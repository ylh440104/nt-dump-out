
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

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
  *param_6 = PTR_DAT_140008008;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140008008;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140008020,&local_18,0,0,param_5,param_6);
  return;
}



===== MPSendNetBufferLists @ 1400010c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MPSendNetBufferLists(longlong param_1,undefined8 *param_2,ulonglong param_3,undefined8 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined8 *puVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint uVar11;
  int iVar12;
  undefined8 *puVar13;
  undefined1 auStackY_e8 [32];
  int local_b8 [2];
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined2 local_9c;
  undefined8 local_98 [4];
  int *local_78;
  undefined8 local_70;
  undefined8 local_68 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  piVar1 = (int *)(param_1 + 0xc0);
  uVar11 = (uint)param_4 & 1;
  LOCK();
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (*(char *)(*(longlong *)(param_1 + 0x30) + 0x56) == '\0')) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 2;
  }
  else {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffd;
  }
  while (param_2 != (undefined8 *)0x0) {
    puVar13 = (undefined8 *)*param_2;
    uVar5 = *(uint *)(param_1 + 0x40);
    if ((uVar5 & 0x37) == 0) {
      *param_2 = 0;
      *(undefined4 *)(param_2 + 0xd) = 0;
      *(undefined4 *)((longlong)param_2 + 0x8c) = 0;
      LOCK();
      *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + 1;
      UNLOCK();
      LOCK();
      *(int *)(param_2 + 0xd) = *(int *)(param_2 + 0xd) + 1;
      UNLOCK();
      for (puVar3 = (undefined8 *)param_2[1]; local_b0 = puVar13, puVar3 != (undefined8 *)0x0;
          puVar3 = (undefined8 *)*puVar3) {
        puVar3[0x12] = param_2;
        puVar13 = (undefined8 *)puVar3[1];
        uVar10 = 0;
        local_a8 = 0;
        local_a0 = 0;
        local_9c = 0;
        do {
          if (puVar13 == (undefined8 *)0x0) {
            *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc0010015;
            _KdNicTxBadDestinationAddress = _KdNicTxBadDestinationAddress + 1;
            goto LAB_14000131f;
          }
          uVar5 = 0xe - (int)uVar10;
          if (*(uint *)(puVar13 + 5) < uVar5) {
            uVar5 = *(uint *)(puVar13 + 5);
          }
          param_3 = (ulonglong)uVar5;
          memmove((void *)((longlong)local_98 + (uVar10 - 0x10)),
                  (void *)((ulonglong)*(uint *)((longlong)puVar13 + 0x2c) + puVar13[4]),param_3);
          puVar13 = (undefined8 *)*puVar13;
          uVar5 = (int)uVar10 + uVar5;
          uVar10 = (ulonglong)uVar5;
        } while (uVar5 < 0xe);
        if (((((char)local_a8 == -1) && (local_a8._1_1_ == -1)) && (local_a8._2_1_ == -1)) &&
           (((local_a8._3_1_ == -1 && (local_a8._4_1_ == -1)) && (local_a8._5_1_ == -1)))) {
          iVar6 = 8;
        }
        else {
          iVar6 = ((local_a8 & 1) != 0) + 1;
        }
        *(int *)(puVar3 + 0x13) = iVar6;
        LOCK();
        *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + 1;
        UNLOCK();
        LOCK();
        *(int *)(param_2 + 0xd) = *(int *)(param_2 + 0xd) + 1;
        UNLOCK();
        param_3 = param_1 + 0x88;
        ExInterlockedInsertTailList(param_1 + 0x78,puVar3 + 0x10);
LAB_14000131f:
        puVar13 = local_b0;
      }
      LOCK();
      piVar2 = (int *)(param_2 + 0xd);
      iVar6 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar6 == 1) {
        *param_2 = 0;
        param_3 = (ulonglong)uVar11;
        NdisMSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),param_2);
      }
      LOCK();
      *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + -1;
      UNLOCK();
      param_2 = puVar13;
    }
    else {
      if ((uVar5 & 1) == 0) {
        uVar7 = 0xc0000001;
        if ((uVar5 & 0x30) != 0) {
          uVar7 = 0xc023002a;
        }
        *(undefined4 *)((longlong)param_2 + 0x8c) = uVar7;
      }
      else {
        *(undefined4 *)((longlong)param_2 + 0x8c) = 0xc001000d;
      }
      *param_2 = 0;
      param_3 = (ulonglong)uVar11;
      local_b0 = puVar13;
      NdisMSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),param_2);
      param_2 = puVar13;
    }
  }
  iVar12 = 0;
  LOCK();
  piVar2 = (int *)(param_1 + 0xbc);
  iVar6 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  if (iVar6 + 1 < 2) {
LAB_14000114a:
    do {
      lVar9 = param_1 + 0x58;
      lVar8 = ExInterlockedRemoveHeadList(lVar9,param_1 + 0x68);
      if (lVar8 == 0) {
        _KdNicTxTransmitQueuedSendsNoTCBs = _KdNicTxTransmitQueuedSendsNoTCBs + 1;
      }
      else {
        lVar9 = ExInterlockedRemoveHeadList(param_1 + 0x78,param_1 + 0x88);
        if (lVar9 != 0) {
          *(undefined4 *)(lVar8 + 0x1c) = 0;
          *(longlong *)(lVar8 + 0x10) = lVar9 + -0x80;
          iVar12 = iVar12 + 1;
          *(undefined4 *)(lVar8 + 0x18) = *(undefined4 *)(lVar9 + 0x18);
          ExpInterlockedPushEntrySList(*(longlong *)(param_1 + 0x30) + 0x10,lVar8 + -0x10);
          goto LAB_14000114a;
        }
        param_3 = param_1 + 0x68;
        lVar9 = param_1 + 0x58;
        ExInterlockedInsertTailList(lVar9,lVar8);
      }
      LOCK();
      piVar2 = (int *)(param_1 + 0xbc);
      iVar6 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    } while (1 < iVar6);
    if (5 < DAT_140008000) {
      _tlgWriteTransfer_EtwWriteTransfer(lVar9,&DAT_1400067f4,param_3,param_4,2,local_68);
    }
    cVar4 = KdPollBreakIn();
    if (cVar4 != '\0') {
      lVar9 = 1;
      DbgBreakPointWithStatus();
    }
    if (5 < DAT_140008000) {
      local_78 = local_b8;
      local_70 = 4;
      local_b8[0] = iVar12;
      _tlgWriteTransfer_EtwWriteTransfer(lVar9,&DAT_140006812,param_3,param_4,3,local_98);
    }
  }
  LOCK();
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  return;
}



===== HandleSend @ 1400014f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HandleSend(longlong param_1,uint *param_2,ulonglong param_3,undefined8 param_4)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  bool bVar7;
  uint *puVar8;
  uint *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  uint *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [136];
  ulonglong local_38;
  
  puVar13 = auStack_c8;
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar14 = 0;
  puVar15 = (undefined8 *)0x0;
  puVar16 = (undefined8 *)0x0;
  bVar7 = true;
  puVar12 = param_2;
  if (*(longlong *)(param_1 + 0x30) == 0) goto LAB_140001677;
  plVar1 = (longlong *)(param_1 + 0x158);
  if ((longlong *)*plVar1 == plVar1) {
    *(undefined4 *)(param_1 + 0x168) = 0;
    bVar7 = false;
    puVar8 = (uint *)ExpInterlockedFlushSList(*(longlong *)(param_1 + 0x30) + 0x20);
    puVar13 = auStack_c8;
    if (puVar8 == (uint *)0x0) goto LAB_140001677;
    do {
      puVar12 = *(uint **)puVar8;
      puVar8[0] = 0;
      puVar8[1] = 0;
      puVar9 = puVar8 + 4;
      lVar4 = *plVar1;
      if (*(longlong **)(lVar4 + 8) != plVar1) goto LAB_140001664;
      *(longlong *)puVar9 = lVar4;
      *(longlong **)(puVar8 + 6) = plVar1;
      *(uint **)(lVar4 + 8) = puVar9;
      *plVar1 = (longlong)puVar9;
      *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
      puVar8 = puVar12;
    } while (puVar12 != (uint *)0x0);
  }
  while( true ) {
    plVar5 = (longlong *)*plVar1;
    puVar13 = auStack_c8;
    if ((plVar5 == plVar1) || (puVar13 = auStack_c8, *param_2 <= uVar14)) break;
    if (((longlong *)plVar5[1] != plVar1) || (lVar4 = *plVar5, *(longlong **)(lVar4 + 8) != plVar5))
    goto LAB_140001664;
    *plVar1 = lVar4;
    puVar12 = (uint *)(plVar5 + -2);
    *(longlong **)(lVar4 + 8) = plVar1;
    param_3 = (ulonglong)*(uint *)((longlong)plVar5 + 0x1c);
    if (*(uint *)((longlong)plVar5 + 0x1c) == 0) {
      *(int *)(param_1 + 0x2e8) = *(int *)(param_1 + 0x2e8) + 1;
      *(undefined4 *)(*(longlong *)(plVar5[2] + 0x90) + 0x8c) = 0xc000009a;
    }
    else {
      iVar2 = (int)plVar5[3];
      if (iVar2 == 1) {
LAB_14000162c:
        *(longlong *)(param_1 + 0x280) = *(longlong *)(param_1 + 0x280) + 1;
        *(longlong *)(param_1 + 0x2b0) = *(longlong *)(param_1 + 0x2b0) + param_3;
      }
      else if (iVar2 == 2) {
        *(longlong *)(param_1 + 0x288) = *(longlong *)(param_1 + 0x288) + 1;
        *(longlong *)(param_1 + 0x2b8) = *(longlong *)(param_1 + 0x2b8) + param_3;
      }
      else {
        if (iVar2 != 8) goto LAB_14000162c;
        *(longlong *)(param_1 + 0x290) = *(longlong *)(param_1 + 0x290) + 1;
        *(longlong *)(param_1 + 0x2c0) = *(longlong *)(param_1 + 0x2c0) + param_3;
      }
    }
    puVar10 = TCBFree(param_1,(longlong)puVar12);
    if (puVar10 != (undefined8 *)0x0) {
      if (puVar15 == (undefined8 *)0x0) {
        puVar15 = puVar10;
      }
      else {
        *puVar16 = puVar10;
      }
      puVar16 = puVar10;
    }
    uVar14 = uVar14 + 1;
    *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + -1;
  }
  goto LAB_14000166b;
LAB_140001664:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  puVar13 = auStack_c0;
LAB_14000166b:
  if (puVar16 != (undefined8 *)0x0) {
    *puVar16 = 0;
  }
LAB_140001677:
  *(undefined8 **)(param_2 + 4) = puVar15;
  param_2[6] = uVar14;
  uVar3 = *(uint *)(param_1 + 0x168);
  uVar11 = (ulonglong)uVar3;
  param_2[7] = uVar3;
  if ((uVar3 == 0) && (bVar7)) {
    param_2[7] = 0xffffffff;
    uVar11 = 0xffffffff;
  }
  if (5 < DAT_140008000) {
    puVar12 = (uint *)&DAT_140006739;
    *(uint *)(puVar13 + 0x30) = *param_2;
    *(undefined1 **)(puVar13 + 0x60) = puVar13 + 0x30;
    *(undefined1 **)(puVar13 + 0x70) = puVar13 + 0x34;
    *(undefined1 **)(puVar13 + 0x80) = puVar13 + 0x38;
    *(undefined1 **)(puVar13 + 0x28) = puVar13 + 0x40;
    *(undefined4 *)(puVar13 + 0x20) = 5;
    *(undefined8 *)(puVar13 + 0x68) = 4;
    *(uint *)(puVar13 + 0x34) = uVar14;
    *(undefined8 *)(puVar13 + 0x78) = 4;
    *(int *)(puVar13 + 0x38) = (int)uVar11;
    *(undefined8 *)(puVar13 + 0x88) = 4;
    *(undefined8 *)(puVar13 + -8) = 0x140001710;
    _tlgWriteTransfer_EtwWriteTransfer
              (uVar11,&DAT_140006739,param_3,param_4,*(undefined4 *)(puVar13 + 0x20),
               *(undefined8 **)(puVar13 + 0x28));
  }
  *(undefined8 *)(puVar13 + -8) = 0x140001718;
  TXTransmitQueuedSends(param_1,puVar12,param_3,param_4);
  *(undefined8 *)(puVar13 + -8) = 0x140001728;
  return;
}



===== TXTransmitQueuedSends @ 140001750 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TXTransmitQueuedSends(longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  undefined1 auStackY_88 [32];
  int local_58 [2];
  undefined8 local_50 [4];
  int *local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  iVar6 = 0;
  LOCK();
  piVar1 = (int *)(param_1 + 0xbc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 + 1 < 2) {
LAB_140001797:
    do {
      lVar5 = param_1 + 0x58;
      lVar4 = ExInterlockedRemoveHeadList(lVar5,param_1 + 0x68);
      if (lVar4 == 0) {
        _KdNicTxTransmitQueuedSendsNoTCBs = _KdNicTxTransmitQueuedSendsNoTCBs + 1;
      }
      else {
        lVar5 = ExInterlockedRemoveHeadList(param_1 + 0x78,param_1 + 0x88);
        if (lVar5 != 0) {
          *(undefined4 *)(lVar4 + 0x1c) = 0;
          *(longlong *)(lVar4 + 0x10) = lVar5 + -0x80;
          iVar6 = iVar6 + 1;
          *(undefined4 *)(lVar4 + 0x18) = *(undefined4 *)(lVar5 + 0x18);
          ExpInterlockedPushEntrySList(*(longlong *)(param_1 + 0x30) + 0x10,lVar4 + -0x10);
          goto LAB_140001797;
        }
        param_3 = param_1 + 0x68;
        lVar5 = param_1 + 0x58;
        ExInterlockedInsertTailList(lVar5,lVar4);
      }
      LOCK();
      piVar1 = (int *)(param_1 + 0xbc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    } while (1 < iVar2);
    if (5 < DAT_140008000) {
      _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_1400067f4,param_3,param_4,2,local_50);
    }
    cVar3 = KdPollBreakIn();
    if (cVar3 != '\0') {
      lVar5 = 1;
      DbgBreakPointWithStatus();
    }
    if (5 < DAT_140008000) {
      local_30 = local_58;
      local_28 = 4;
      local_58[0] = iVar6;
      _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_140006812,param_3,param_4,3,local_50);
    }
  }
  return;
}



===== HandleReceive @ 140001920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HandleReceive(longlong param_1,uint *param_2,undefined8 *param_3,undefined8 *param_4)

{
  longlong *plVar1;
  undefined2 uVar2;
  uint uVar3;
  longlong *plVar4;
  longlong *plVar5;
  code *pcVar6;
  bool bVar7;
  char cVar8;
  longlong lVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  uint uVar13;
  undefined8 *puVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong *plVar17;
  undefined1 auStackY_108 [8];
  undefined1 auStackY_100 [24];
  undefined4 uStack_d4;
  undefined2 local_d0;
  uint local_cc;
  uint local_c8 [4];
  undefined1 local_b8 [32];
  uint *local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined8 local_68 [4];
  ulonglong local_48;
  
  puVar12 = auStackY_108;
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  lVar15 = *(longlong *)(param_1 + 0x30);
  bVar7 = true;
  uVar13 = 0;
  plVar16 = (longlong *)0x0;
  plVar17 = (longlong *)0x0;
  if (lVar15 == 0) goto LAB_140001b4a;
  lVar10 = param_1;
  lVar9 = RCBAllocate(param_1);
  puVar12 = auStackY_108;
  puVar14 = param_3;
  while (lVar9 != 0) {
    ExpInterlockedPushEntrySList(lVar15 + 0x30,lVar9);
    lVar10 = param_1;
    lVar9 = RCBAllocate(param_1);
  }
  plVar1 = (longlong *)(param_1 + 0x140);
  if ((longlong *)*plVar1 == plVar1) {
    *(undefined4 *)(param_1 + 0x150) = 0;
    bVar7 = false;
    if (5 < DAT_140008000) {
      _tlgWriteTransfer_EtwWriteTransfer(lVar10,&DAT_1400067b7,puVar14,param_4,2,local_68);
    }
    cVar8 = KdPollBreakIn();
    if (cVar8 != '\0') {
      DbgBreakPointWithStatus(1);
    }
    param_3 = (undefined8 *)ExpInterlockedFlushSList(lVar15 + 0x40);
    if (param_3 == (undefined8 *)0x0) {
      bVar7 = false;
      goto LAB_140001b4a;
    }
    do {
      lVar15 = param_3[5];
      puVar14 = (undefined8 *)*param_3;
      *param_3 = 0;
      *(undefined4 *)(*(longlong *)(param_3[4] + 8) + 0x18) = *(undefined4 *)(lVar15 + 0x10);
      uVar3 = *(uint *)(lVar15 + 0x14);
      uVar2 = *(undefined2 *)(lVar15 + 0x18);
      if ((((((char)uVar3 == -1) && (uStack_d4._1_1_ = (char)(uVar3 >> 8), uStack_d4._1_1_ == -1))
           && (uStack_d4._2_1_ = (char)(uVar3 >> 0x10), uStack_d4._2_1_ == -1)) &&
          ((uStack_d4._3_1_ = (char)(uVar3 >> 0x18), uStack_d4._3_1_ == -1 && ((char)uVar2 == -1))))
         && (local_d0._1_1_ = (char)((ushort)uVar2 >> 8), local_d0._1_1_ == -1)) {
        *(longlong *)(param_1 + 0x278) = *(longlong *)(param_1 + 0x278) + 1;
        *(longlong *)(param_1 + 0x2a8) =
             *(longlong *)(param_1 + 0x2a8) + (ulonglong)*(uint *)(lVar15 + 0x10);
      }
      else if ((uVar3 & 1) == 0) {
        *(longlong *)(param_1 + 0x268) = *(longlong *)(param_1 + 0x268) + 1;
        *(longlong *)(param_1 + 0x298) =
             *(longlong *)(param_1 + 0x298) + (ulonglong)*(uint *)(lVar15 + 0x10);
      }
      else {
        *(longlong *)(param_1 + 0x270) = *(longlong *)(param_1 + 0x270) + 1;
        *(longlong *)(param_1 + 0x2a0) =
             *(longlong *)(param_1 + 0x2a0) + (ulonglong)*(uint *)(lVar15 + 0x10);
      }
      lVar15 = *plVar1;
      plVar4 = param_3 + 2;
      param_4 = puVar14;
      uStack_d4 = uVar3;
      local_d0 = uVar2;
      if (*(longlong **)(lVar15 + 8) != plVar1) goto LAB_140001b30;
      *plVar4 = lVar15;
      param_3[3] = plVar1;
      *(longlong **)(lVar15 + 8) = plVar4;
      *plVar1 = (longlong)plVar4;
      *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + 1;
      param_3 = puVar14;
    } while (puVar14 != (undefined8 *)0x0);
  }
  else {
    bVar7 = true;
  }
  while( true ) {
    lVar15 = 0;
    plVar4 = (longlong *)*plVar1;
    puVar12 = auStackY_108;
    param_3 = puVar14;
    if ((plVar4 == plVar1) || (puVar12 = auStackY_108, *param_2 <= uVar13)) break;
    if (((longlong *)plVar4[1] != plVar1) ||
       (lVar15 = *plVar4, *(longlong **)(lVar15 + 8) != plVar4)) goto LAB_140001b30;
    *plVar1 = lVar15;
    *(longlong **)(lVar15 + 8) = plVar1;
    *(undefined4 *)(plVar4[2] + 0x8c) = 0;
    plVar5 = (longlong *)plVar4[2];
    if (plVar16 == (longlong *)0x0) {
      uVar13 = uVar13 + 1;
      *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + -1;
      plVar16 = plVar5;
      plVar17 = plVar5;
    }
    else {
      *plVar17 = (longlong)plVar5;
      uVar13 = uVar13 + 1;
      plVar17 = (longlong *)plVar4[2];
      *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + -1;
    }
  }
  goto LAB_140001b37;
LAB_140001b30:
  lVar15 = 0;
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  puVar12 = auStackY_100;
LAB_140001b37:
  if (plVar17 != (longlong *)0x0) {
    *plVar17 = lVar15;
  }
LAB_140001b4a:
  param_2[6] = uVar13;
  *(longlong **)(param_2 + 4) = plVar16;
  param_2[8] = 0x400;
  uVar3 = *(uint *)(param_1 + 0x150);
  uVar11 = (ulonglong)uVar3;
  param_2[7] = uVar3;
  if ((uVar3 == 0) && (bVar7)) {
    param_2[7] = 0xffffffff;
    uVar11 = 0xffffffff;
  }
  if (5 < DAT_140008000) {
    local_cc = *param_2;
    local_98 = &local_cc;
    local_88 = local_c8;
    local_78 = &uStack_d4;
    *(undefined1 **)(puVar12 + 0x28) = local_b8;
    *(undefined4 *)(puVar12 + 0x20) = 5;
    local_90 = 4;
    local_80 = 4;
    uStack_d4 = (int)uVar11;
    local_70 = 4;
    *(undefined8 *)(puVar12 + -8) = 0x140001bdb;
    local_c8[0] = uVar13;
    _tlgWriteTransfer_EtwWriteTransfer
              (uVar11,&DAT_14000683f,param_3,param_4,*(undefined4 *)(puVar12 + 0x20),
               *(undefined8 **)(puVar12 + 0x28));
  }
  *(undefined8 *)(puVar12 + -8) = 0x140001be7;
  return;
}



===== RCBAllocate @ 140001c10 =====

longlong RCBAllocate(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  int *piVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar6 = 0;
  piVar4 = (int *)ExAllocateFromNPagedLookasideList(&DAT_140008200);
  if (piVar4 != (int *)0x0) {
    *piVar4 = 1;
    piVar4[4] = 0x5ea;
    lVar5 = ExInterlockedRemoveHeadList(param_1 + 0xd0,param_1 + 0xe0);
    if (lVar5 != 0) {
      LOCK();
      *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + 1;
      UNLOCK();
      lVar6 = lVar5 + -0x10;
      LOCK();
      *piVar4 = *piVar4 + 1;
      UNLOCK();
      *(int **)(lVar5 + 0x18) = piVar4;
      lVar2 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 8);
      uVar3 = *(undefined8 *)(piVar4 + 2);
      *(undefined8 *)(lVar2 + 0x20) = uVar3;
      *(undefined4 *)(lVar2 + 0x18) = 0;
      *(undefined4 *)(lVar2 + 0x28) = 0;
      *(undefined8 *)(lVar2 + 8) = uVar3;
      *(undefined4 *)(lVar2 + 0x10) = 0;
      *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x60) = lVar6;
    }
    LOCK();
    iVar1 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      ExFreeToNPagedLookasideList(&DAT_140008200,piVar4);
    }
  }
  return lVar6;
}



===== TCBFree @ 140001cf0 =====

undefined8 * TCBFree(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  puVar3 = *(undefined8 **)(*(longlong *)(param_2 + 0x20) + 0x90);
  LOCK();
  piVar1 = (int *)(puVar3 + 0xd);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *puVar3 = 0;
  }
  LOCK();
  *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + -1;
  UNLOCK();
  *(undefined8 *)(param_2 + 0x20) = 0;
  puVar4 = (undefined8 *)0x0;
  if (iVar2 == 1) {
    puVar4 = puVar3;
  }
  ExInterlockedInsertTailList(param_1 + 0x58,param_2 + 0x10,param_1 + 0x68);
  return puVar4;
}



===== RCBFree @ 140001d60 =====

void RCBFree(longlong param_1,longlong param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_2 + 0x28);
  ExInterlockedInsertTailList(param_1 + 0xd0,param_2 + 0x10,param_1 + 0xe0);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    ExFreeToNPagedLookasideList(&DAT_140008200,piVar2);
  }
  LOCK();
  *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + -1;
  UNLOCK();
  return;
}



===== MPReturnNetBufferLists @ 140001dd0 =====

void MPReturnNetBufferLists(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  int *piVar3;
  
  while (param_2 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*param_2;
    *param_2 = 0;
    *(undefined4 *)((longlong)param_2 + 0x8c) = 0;
    piVar3 = *(int **)(param_2[0xc] + 0x28);
    ExInterlockedInsertTailList(param_1 + 0xd0,param_2[0xc] + 0x10,param_1 + 0xe0);
    LOCK();
    iVar1 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      ExFreeToNPagedLookasideList(&DAT_140008200,piVar3);
    }
    LOCK();
    *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + -1;
    UNLOCK();
    param_2 = puVar2;
  }
  return;
}



===== SchedulePollRequest @ 140001e90 =====

void SchedulePollRequest(longlong param_1)

{
  NdisSetTimerObject(*(undefined8 *)(param_1 + 0x130),0xffffffffffffe2b4,0,0);
  return;
}



===== KdNicDispatchPower @ 140001ec0 =====

void KdNicDispatchPower(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  PoStartNextPowerIrp(param_2);
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*puVar1,param_2);
  return;
}



===== NdisSetPollNotification @ 140001f20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NdisSetPollNotification
               (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_78 [32];
  char local_48 [8];
  undefined8 local_40 [4];
  char *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (5 < DAT_140008000) {
    local_48[0] = *(char *)(param_2 + 4);
    local_20 = local_48;
    local_18 = 1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000676c,param_3,param_4,3,local_40);
  }
  if ((*(char *)(param_2 + 4) != '\0') && (*(int *)(param_1 + 0x138) != 0)) {
    SchedulePollRequest(param_1);
  }
  return;
}



===== RequestPollDpc @ 140001fc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RequestPollDpc(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (5 < DAT_140008000) {
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1400067d5,param_3,param_4,2,local_38);
  }
  if (*(int *)(param_2 + 0x138) != 0) {
    NdisRequestPoll(*(undefined8 *)(param_2 + 0x120),0);
  }
  return;
}



===== NdisPoll @ 140002040 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 NdisPoll(longlong param_1,longlong param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  bool bVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (5 < DAT_140008000) {
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000679e,param_3,param_4,2,local_38);
  }
  LOCK();
  bVar2 = *(int *)(param_1 + 0x128) == 0;
  if (bVar2) {
    *(int *)(param_1 + 0x128) = 1;
  }
  UNLOCK();
  if (bVar2) {
    HandleSend(param_1,(uint *)(param_2 + 8),(ulonglong)param_3,param_4);
    HandleReceive(param_1,(uint *)(param_2 + 0x50),param_3,param_4);
    LOCK();
    uVar1 = *(undefined4 *)(param_1 + 0x128);
    *(undefined4 *)(param_1 + 0x128) = 0;
    UNLOCK();
  }
  else {
    uVar1 = 0;
    *(undefined8 *)(param_2 + 0x68) = 0;
    *(undefined8 *)(param_2 + 0x60) = 0;
    *(undefined8 *)(param_2 + 0x20) = 0;
    *(undefined8 *)(param_2 + 0x18) = 0;
  }
  return uVar1;
}



===== KdNicDispatchForwardIrp @ 1400020f0 =====

void KdNicDispatchForwardIrp(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*puVar1);
  return;
}



===== MPQueryInformation @ 140002120 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MPQueryInformation(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong *_Src;
  uint uVar5;
  undefined1 auStack_78 [32];
  int local_58;
  undefined2 local_54 [2];
  longlong local_50;
  undefined4 local_48;
  undefined4 local_44;
  longlong local_40;
  undefined2 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0x74;
  _Src = (longlong *)&local_58;
  local_48 = 0;
  local_40._0_1_ = 'M';
  local_40._1_1_ = 'i';
  local_40._2_1_ = 'c';
  local_40._3_1_ = 'r';
  local_40._4_1_ = 'o';
  local_40._5_1_ = 's';
  local_40._6_1_ = 'o';
  local_40._7_1_ = 'f';
  uVar5 = 4;
  uVar1 = *(uint *)(param_2 + 0x20);
  local_44 = 0;
  local_58 = 0;
  local_54[0] = 0;
  local_50 = 0;
  if (uVar1 == 0x20106) {
    if (*(uint *)(param_2 + 0x30) < 0x98) {
      *(undefined4 *)(param_2 + 0x38) = 0x98;
      return 0xc0010016;
    }
    puVar2 = *(undefined4 **)(param_2 + 0x28);
    memset(puVar2 + 2,0,0x90);
    *puVar2 = 0x980180;
    puVar2[1] = 0x839ffec;
    *(longlong *)(puVar2 + 6) =
         *(longlong *)(param_1 + 0x2a0) + *(longlong *)(param_1 + 0x2a8) +
         *(longlong *)(param_1 + 0x298);
    *(undefined8 *)(puVar2 + 0x1a) = *(undefined8 *)(param_1 + 0x298);
    *(undefined8 *)(puVar2 + 0x1c) = *(undefined8 *)(param_1 + 0x2a0);
    *(undefined8 *)(puVar2 + 0x1e) = *(undefined8 *)(param_1 + 0x2a8);
    *(undefined8 *)(puVar2 + 8) = *(undefined8 *)(param_1 + 0x268);
    *(undefined8 *)(puVar2 + 10) = *(undefined8 *)(param_1 + 0x270);
    *(undefined8 *)(puVar2 + 0xc) = *(undefined8 *)(param_1 + 0x278);
    uVar4 = (ulonglong)
            (uint)(*(int *)(param_1 + 0x300) + *(int *)(param_1 + 0x2f8) + *(int *)(param_1 + 0x2f0)
                   + *(int *)(param_1 + 0x2ec) + *(int *)(param_1 + 0x2f4));
    *(ulonglong *)(puVar2 + 4) = uVar4;
    *(ulonglong *)(puVar2 + 2) = *(uint *)(param_1 + 0x2f4) + uVar4;
    *(longlong *)(puVar2 + 0xe) =
         *(longlong *)(param_1 + 0x2c0) + *(longlong *)(param_1 + 0x2b0) +
         *(longlong *)(param_1 + 0x2b8);
    *(undefined8 *)(puVar2 + 0x20) = *(undefined8 *)(param_1 + 0x2b0);
    *(undefined8 *)(puVar2 + 0x22) = *(undefined8 *)(param_1 + 0x2b8);
    *(undefined8 *)(puVar2 + 0x24) = *(undefined8 *)(param_1 + 0x2c0);
    *(undefined8 *)(puVar2 + 0x10) = *(undefined8 *)(param_1 + 0x280);
    *(undefined8 *)(puVar2 + 0x12) = *(undefined8 *)(param_1 + 0x288);
    *(undefined8 *)(puVar2 + 0x14) = *(undefined8 *)(param_1 + 0x290);
    *(ulonglong *)(puVar2 + 0x16) =
         (ulonglong)
         (uint)(*(int *)(param_1 + 0x2e8) + *(int *)(param_1 + 0x2d4) + *(int *)(param_1 + 0x2d0) +
                *(int *)(param_1 + 0x2cc) + *(int *)(param_1 + 0x2c8));
    *(undefined8 *)(puVar2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x34) = 0x98;
    return 0;
  }
  if (uVar1 < 0x20102) {
    if (uVar1 == 0x20101) {
      _Src = &local_50;
      uVar5 = 8;
      local_50 = *(longlong *)(param_1 + 0x290) + *(longlong *)(param_1 + 0x288) +
                 *(longlong *)(param_1 + 0x280);
    }
    else {
      switch(uVar1) {
      case 0x10102:
        _Src = (longlong *)&local_48;
        break;
      case 0x10103:
      case 0x10104:
        _Src = (longlong *)&local_44;
        break;
      default:
        return 0xc00000bb;
      case 0x10108:
        local_58 = *(int *)(param_1 + 0x198) * 0x5ea;
        break;
      case 0x10109:
        local_58 = *(int *)(param_1 + 0x19c) * 0x5ea;
        break;
      case 0x1010a:
      case 0x1010b:
      case 0x10111:
        local_58 = 0x5ea;
        break;
      case 0x1010c:
        local_58 = 0xffffff;
        break;
      case 0x1010d:
        _Src = &local_40;
        uVar5 = 10;
        break;
      case 0x10110:
        _Src = (longlong *)local_54;
        local_54[0] = 0x656;
        uVar5 = 2;
        break;
      case 0x10115:
        local_58 = *(int *)(param_1 + 0x38);
        break;
      case 0x10116:
        local_58 = 0x50000;
      }
    }
  }
  else if (uVar1 < 0x1020102) {
    if (uVar1 == 0x1020101) {
      local_58 = *(int *)(param_1 + 0x2f0);
    }
    else if (uVar1 < 0x2020f) {
      if (uVar1 == 0x2020e) {
        local_58 = *(int *)(param_1 + 0xb8);
      }
      else if (uVar1 == 0x20102) {
        _Src = &local_50;
        uVar5 = 8;
        local_50 = *(longlong *)(param_1 + 0x278) + *(longlong *)(param_1 + 0x270) +
                   *(longlong *)(param_1 + 0x268);
      }
      else if (uVar1 == 0x20103) {
        local_58 = *(int *)(param_1 + 0x2e8) + *(int *)(param_1 + 0x2d4) + *(int *)(param_1 + 0x2d0)
                   + *(int *)(param_1 + 0x2cc) + *(int *)(param_1 + 0x2c8);
      }
      else if (uVar1 == 0x20104) {
        local_58 = *(int *)(param_1 + 0x300) + *(int *)(param_1 + 0x2f8) + *(int *)(param_1 + 0x2f4)
                   + *(int *)(param_1 + 0x2f0) + *(int *)(param_1 + 0x2ec);
      }
      else {
        if (uVar1 != 0x20105) {
          return 0xc00000bb;
        }
        local_58 = *(int *)(param_1 + 0x2f4);
      }
    }
    else if (uVar1 == 0x1010101) {
      _Src = (longlong *)(param_1 + 0x44);
      uVar5 = 6;
    }
    else if (uVar1 == 0x1010102) {
      _Src = (longlong *)(param_1 + 0x4a);
      uVar5 = 6;
    }
    else {
      if (uVar1 != 0x1010104) {
        return 0xc00000bb;
      }
      local_58 = 0x20;
    }
  }
  else if (uVar1 < 0x1020205) {
    if (uVar1 == 0x1020204) {
      local_58 = *(int *)(param_1 + 0x2d0);
    }
    else if (uVar1 == 0x1020102) {
      local_58 = *(int *)(param_1 + 0x2dc);
    }
    else if (uVar1 == 0x1020103) {
      local_58 = *(int *)(param_1 + 0x2e0);
    }
    else if (uVar1 == 0x1020201) {
      local_58 = *(int *)(param_1 + 0x2d8);
    }
    else if (uVar1 == 0x1020202) {
      local_58 = *(int *)(param_1 + 0x2c8);
    }
    else {
      if (uVar1 != 0x1020203) {
        return 0xc00000bb;
      }
      local_58 = *(int *)(param_1 + 0x2f8);
    }
  }
  else if (uVar1 == 0x1020205) {
    local_58 = *(int *)(param_1 + 0x2d4);
  }
  else if (uVar1 == 0x1020206) {
    local_58 = *(int *)(param_1 + 0x2d4);
  }
  else {
    if (uVar1 != 0x1020207) {
      return 0xc00000bb;
    }
    local_58 = *(int *)(param_1 + 0x2cc);
  }
  if (*(uint *)(param_2 + 0x30) < uVar5) {
    *(uint *)(param_2 + 0x38) = uVar5;
    uVar3 = 0xc0010016;
  }
  else {
    memmove(*(void **)(param_2 + 0x28),_Src,(ulonglong)uVar5);
    uVar3 = 0;
    *(uint *)(param_2 + 0x34) = uVar5;
  }
  return uVar3;
}



===== HWFrameAllocate @ 1400025e0 =====

longlong HWFrameAllocate(undefined8 param_1,ulonglong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = NdisAllocateMemoryWithTagPriority(NdisDriverHandle,param_2,param_3,0x10);
  if (lVar1 != 0) {
    lVar2 = NdisAllocateMdl(NdisDriverHandle,lVar1 + 0x14,0x5ea);
    *(longlong *)(lVar1 + 8) = lVar2;
    if (lVar2 != 0) {
      return lVar1;
    }
    NdisFreeMemory(lVar1,param_2 & 0xffffffff,0);
  }
  return 0;
}



===== GetKdNetNetworkInterface @ 140002670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GetKdNetNetworkInterface(void)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined8 local_res8 [4];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  wchar_t *local_68;
  undefined8 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  
  local_78 = 0;
  local_70 = 0x134;
  local_68 = L"KdNic";
  local_60 = local_res8;
  local_58 = 0xb000000;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  KdNetNicInterface = 0;
  local_res8[0] = 0xfffffff8;
  local_88 = 0;
  uStack_80 = 0;
  RtlInitUnicodeString(&local_88,L"RtlQueryRegistryValuesEx");
  pcVar1 = (code *)MmGetSystemRoutineAddress(&local_88);
  if (pcVar1 == (code *)0x0) {
    pcVar1 = RtlQueryRegistryValues_exref;
  }
  uVar2 = (*pcVar1)(1,L"KDNET\\KDNIC",&local_78,0,0);
  if (-1 < (int)uVar2) {
    KdNetNicInterface = MmGetVirtualForPhysical(local_res8[0]);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== MPOidRequest @ 140002760 =====

undefined8 MPOidRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 0xc) {
LAB_14000278d:
    uVar2 = 0xc00000bb;
  }
  else {
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        uVar2 = MPSetInformation(param_1,param_2);
        return uVar2;
      }
      if (iVar1 != 2) goto LAB_14000278d;
    }
    uVar2 = MPQueryInformation(param_1,param_2);
  }
  return uVar2;
}



===== MPCheckForHangEx @ 1400027a0 =====

undefined1 MPCheckForHangEx(void)

{
  return 0;
}



===== TXNblReleaseAndComplete @ 1400027b0 =====

void TXNblReleaseAndComplete(longlong param_1,undefined8 *param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_2 + 0xd);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *param_2 = 0;
    NdisMSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x28),param_2,param_3 != '\0');
    LOCK();
    *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + -1;
    UNLOCK();
  }
  else {
    LOCK();
    *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + -1;
    UNLOCK();
  }
  return;
}



===== __report_gsfailure @ 140002810 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== FreeAdapterListLock @ 140002820 =====

void FreeAdapterListLock(void)

{
  NdisFreeRWLock(DAT_1400081d0);
  DAT_1400081d0 = 0;
  return;
}



===== GetSystemTimerResolution @ 14000284c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GetSystemTimerResolution(uint *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  uint local_res8 [2];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  wchar_t *local_68;
  uint *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  
  if (param_1 == (uint *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    local_78 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    local_38 = 0;
    local_30 = 0;
    local_68 = L"TimerResolution";
    local_60 = local_res8;
    local_res8[0] = 0xfffffffc;
    local_70 = 0x134;
    local_58 = 0x4000000;
    local_88 = 0;
    uStack_80 = 0;
    RtlInitUnicodeString(&local_88,L"RtlQueryRegistryValuesEx");
    pcVar2 = (code *)MmGetSystemRoutineAddress(&local_88);
    if (pcVar2 == (code *)0x0) {
      pcVar2 = RtlQueryRegistryValues_exref;
    }
    uVar1 = (*pcVar2)(1,L"kdnic",&local_78,0,0);
    if (-1 < (int)uVar1) {
      if (local_res8[0] < 5000) {
        local_res8[0] = 5000;
      }
      if (40000 < local_res8[0]) {
        local_res8[0] = 40000;
      }
      *param_1 = local_res8[0];
    }
  }
  return uVar1;
}



===== MPAttachAdapter @ 140002944 =====

void MPAttachAdapter(undefined8 *param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res8 = 0;
  local_resa = 0;
  if (param_1[6] != 0) {
    piVar1 = (int *)(param_1[6] + 4);
    LOCK();
    if (*piVar1 == 0) {
      *piVar1 = 1;
    }
    UNLOCK();
  }
  NdisAcquireRWLockWrite(DAT_1400081d0,&local_res8,0);
  puVar4 = auStack_28;
  puVar3 = &GlobalData;
  if ((undefined *)*DAT_1400081c8 != &GlobalData) {
    puVar3 = (undefined *)0x3;
    pcVar2 = (code *)swi(0x29);
    DAT_1400081c8 = (undefined8 *)(*pcVar2)();
    puVar4 = auStack_20;
  }
  *param_1 = puVar3;
  param_1[1] = DAT_1400081c8;
  *DAT_1400081c8 = param_1;
  *(undefined8 *)(puVar4 + -8) = 0x1400029c2;
  DAT_1400081c8 = param_1;
  NdisReleaseRWLock(DAT_1400081d0,puVar4 + 0x30);
  return;
}



===== MPDetachAdapter @ 1400029d4 =====

void MPDetachAdapter(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if (param_1[6] != 0) {
    piVar1 = (int *)(param_1[6] + 4);
    LOCK();
    if (*piVar1 == 1) {
      *piVar1 = 0;
    }
    UNLOCK();
  }
  NdisAcquireRWLockWrite(DAT_1400081d0,&local_res8,0);
  lVar2 = *param_1;
  if ((*(longlong **)(lVar2 + 8) == param_1) &&
     (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 == param_1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
    NdisReleaseRWLock(DAT_1400081d0,&local_res8);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== MPSetOptions @ 140002a70 =====

undefined8 MPSetOptions(void)

{
  return 0;
}



===== _tlgDefineProvider_annotation__Tlgg_hKdnicProviderProv @ 140002a7c =====

void _tlgDefineProvider_annotation__Tlgg_hKdnicProviderProv(void)

{
  return;
}



===== MPResetEx @ 140002a90 =====

undefined8 MPResetEx(longlong *param_1,undefined1 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1[6] != 0) {
    iVar2 = *(int *)(param_1[6] + 4);
  }
  if ((*(uint *)(param_1 + 8) & 1) == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 1;
    NICStopTheDatapath(param_1,0xc001000d);
    if (iVar2 != 0) {
      NICStartTheDatapath(param_1);
    }
    *param_2 = 0;
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc001000d;
  }
  return uVar1;
}



===== _guard_check_icall @ 140002b00 =====

void _guard_check_icall(void)

{
  return;
}



===== NICAsyncResetOrPauseDpc @ 140002b10 =====

void NICAsyncResetOrPauseDpc(undefined8 param_1,longlong param_2)

{
  bool bVar1;
  
  if ((*(uint *)(param_2 + 0x40) & 0x11) == 0) {
    return;
  }
  bVar1 = *(int *)(param_2 + 0xb8) != 0;
  if (*(int *)(param_2 + 0x110) == 0) {
    if (*(int *)(param_2 + 0xb8) == 0) goto LAB_140002b60;
  }
  else {
    bVar1 = true;
  }
  *(int *)(param_2 + 0x178) = *(int *)(param_2 + 0x178) + 1;
  if (*(int *)(param_2 + 0x178) < 0x33) {
    NICScheduleTheResetOrPauseDpc(param_2,'\x01');
    return;
  }
LAB_140002b60:
  if ((*(uint *)(param_2 + 0x40) & 0x10) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xffffffef | 0x20;
    NdisMPauseComplete(*(undefined8 *)(param_2 + 0x28));
  }
  if ((*(uint *)(param_2 + 0x40) & 1) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffffe;
    NdisMResetComplete(*(undefined8 *)(param_2 + 0x28),-(uint)bVar1 & 0xc0000001,0);
  }
  return;
}



===== NICIsBusy @ 140002bc0 =====

undefined4 NICIsBusy(longlong param_1)

{
  undefined4 uVar1;
  
  uVar1 = CONCAT31((int3)((uint)*(int *)(param_1 + 0xb8) >> 8),*(int *)(param_1 + 0xb8) != 0);
  if (*(int *)(param_1 + 0x110) != 0) {
    uVar1 = 1;
  }
  return uVar1;
}



===== NICScheduleTheResetOrPauseDpc @ 140002be4 =====

void NICScheduleTheResetOrPauseDpc(longlong param_1,char param_2)

{
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0x178) = 0;
  }
  NdisSetTimerObject(*(undefined8 *)(param_1 + 0x170),0xfffffffffff0bdc0,0,0);
  return;
}



===== MPSetInformation @ 140002c20 =====

undefined8 MPSetInformation(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_2 + 0x20);
  if (iVar1 == 0x1010e) {
    if (*(int *)(param_2 + 0x30) != 4) {
LAB_140002c63:
      *(undefined4 *)(param_2 + 0x38) = 4;
      return 0xc0010014;
    }
    *(undefined4 *)(param_2 + 0x34) = 4;
    uVar2 = **(uint **)(param_2 + 0x28);
    if ((uVar2 & 0xffffffd0) != 0) {
      return 0xc00000bb;
    }
    if (uVar2 != *(uint *)(param_1 + 0x17c)) {
      *(uint *)(param_1 + 0x17c) = uVar2;
    }
  }
  else {
    if (iVar1 != 0x1010f) {
      if (iVar1 != 0x1010103) {
        return 0xc00000bb;
      }
      uVar3 = NICSetMulticastList(param_1,param_2);
      if ((int)uVar3 != 0) {
        return uVar3;
      }
      goto LAB_140002cac;
    }
    if (*(int *)(param_2 + 0x30) != 4) goto LAB_140002c63;
    *(undefined4 *)(param_1 + 0x180) = **(undefined4 **)(param_2 + 0x28);
    *(undefined4 *)(param_2 + 0x34) = 4;
  }
  uVar3 = 0;
LAB_140002cac:
  *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_2 + 0x30);
  return uVar3;
}



===== NICSetMulticastList @ 140002cc0 =====

undefined8 NICSetMulticastList(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(uint *)(param_2 + 0x30);
  *(uint *)(param_2 + 0x34) = uVar1;
  *(undefined4 *)(param_2 + 0x38) = 6;
  uVar2 = 0;
  if (uVar1 == (uVar1 / 6) * 6) {
    if (uVar1 < 0xc1) {
      memset((void *)(param_1 + 0x1a4),0,0xc0);
      memmove((void *)(param_1 + 0x1a4),*(void **)(param_2 + 0x28),
              (ulonglong)*(uint *)(param_2 + 0x30));
      *(uint *)(param_1 + 0x1a0) = *(uint *)(param_2 + 0x30) / 6;
    }
    else {
      uVar2 = 0xc0010009;
      *(undefined4 *)(param_2 + 0x38) = 0xc0;
    }
  }
  else {
    uVar2 = 0xc0010014;
  }
  return uVar2;
}



===== RxFlushReceiveQueue @ 140002d70 =====

void RxFlushReceiveQueue(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x30);
  if (lVar2 != 0) {
    while (lVar5 = ExpInterlockedPopEntrySList(lVar2 + 0x30), lVar5 != 0) {
      RCBFree(param_1,lVar5);
    }
    while (lVar5 = ExpInterlockedPopEntrySList(lVar2 + 0x40), lVar5 != 0) {
      RCBFree(param_1,lVar5);
    }
    plVar1 = (longlong *)(param_1 + 0x140);
    while (plVar3 = (longlong *)*plVar1, plVar3 != plVar1) {
      if (((longlong *)plVar3[1] != plVar1) ||
         (lVar2 = *plVar3, (longlong *)*(longlong *)(lVar2 + 8) != plVar3)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar1 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar1;
      RCBFree(param_1,(longlong)(plVar3 + -2));
      *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + -1;
    }
  }
  return;
}



===== TXFlushSendQueue @ 140002e24 =====

longlong TXFlushSendQueue(longlong param_1,undefined4 param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  bool bVar8;
  
  do {
    LOCK();
    bVar8 = *(int *)(param_1 + 0xc0) == 0;
    if (bVar8) {
      *(int *)(param_1 + 0xc0) = 0;
    }
    UNLOCK();
  } while (!bVar8);
  while (lVar5 = ExInterlockedRemoveHeadList(param_1 + 0x78,param_1 + 0x88), lVar5 != 0) {
    puVar2 = *(undefined8 **)(lVar5 + 0x10);
    *(undefined4 *)((longlong)puVar2 + 0x8c) = param_2;
    TXNblReleaseAndComplete(param_1,puVar2,'\0');
  }
  while( true ) {
    lVar5 = ExInterlockedRemoveHeadList(param_1 + 0x98);
    lVar6 = -lVar5;
    uVar7 = -(ulonglong)(lVar5 != 0) & lVar5 - 0x10U;
    if (uVar7 == 0) break;
    *(undefined4 *)(*(longlong *)(*(longlong *)(uVar7 + 0x20) + 0x90) + 0x8c) = param_2;
    TCBFreeAndComplete(param_1,uVar7);
  }
  plVar1 = (longlong *)(param_1 + 0x158);
  while( true ) {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
      return lVar6;
    }
    if (((longlong *)plVar3[1] != plVar1) ||
       (lVar5 = *plVar3, (longlong *)*(longlong *)(lVar5 + 8) != plVar3)) break;
    *plVar1 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar1;
    *(undefined4 *)(*(longlong *)(plVar3[2] + 0x90) + 0x8c) = param_2;
    lVar6 = TCBFreeAndComplete(param_1,(longlong)(plVar3 + -2));
    *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + -1;
  }
  pcVar4 = (code *)swi(0x29);
  lVar5 = (*pcVar4)(3);
  return lVar5;
}



===== TCBFreeAndComplete @ 140002f44 =====

void TCBFreeAndComplete(longlong param_1,longlong param_2)

{
  TXNblReleaseAndComplete(param_1,*(undefined8 **)(*(longlong *)(param_2 + 0x20) + 0x90),'\0');
  *(undefined8 *)(param_2 + 0x20) = 0;
  ExInterlockedInsertTailList(param_1 + 0x58,param_2 + 0x10,param_1 + 0x68);
  return;
}



===== HWFrameFree @ 140002fa0 =====

void HWFrameFree(longlong param_1)

{
  NdisFreeMdl(*(undefined8 *)(param_1 + 8));
  NdisFreeMemory(param_1,0x600,0);
  return;
}



===== HWGetMediaConnectStatus @ 140002fe0 =====

char HWGetMediaConnectStatus(longlong param_1)

{
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (*(char *)(*(longlong *)(param_1 + 0x30) + 0x56) == '\0')) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 2;
  }
  else {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffd;
  }
  return ((*(uint *)(param_1 + 0x40) & 2) != 0) + '\x01';
}



===== GetKdNicLegacyFallbackConfig @ 140003010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GetKdNicLegacyFallbackConfig(longlong param_1,undefined1 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStack_78 [32];
  undefined8 *local_58;
  undefined4 *local_50;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [4];
  int local_24;
  int local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = 0;
  local_48[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  if ((param_2 == (undefined1 *)0x0) || (param_1 == 0)) {
    uVar2 = 0xc000000d;
  }
  else {
    *param_2 = 0;
    local_58 = &local_40;
    uVar2 = IoOpenDriverRegistryKey(0,2,0x20019);
    if (-1 < (int)uVar2) {
      RtlInitUnicodeString(&local_38,L"UseLegacyKdnic");
      local_50 = local_48;
      local_58 = (undefined8 *)CONCAT44(local_58._4_4_,0x14);
      uVar1 = ZwQueryValueKey(local_40,&local_38,2,local_28);
      uVar2 = (ulonglong)uVar1;
      if ((-1 < (int)uVar1) && (local_24 == 4)) {
        *param_2 = local_1c != 0;
      }
      ZwClose(local_40);
    }
  }
  return uVar2;
}



===== FxStubDriverUnloadCommon @ 140003118 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_1400082c0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140003150 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140003184 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1400082c0 = 0x2080000;
    _DAT_1400082c8 = &DAT_1400082e0;
    RtlCopyUnicodeString(&DAT_1400082c0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1400082c0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry((longlong)param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1400084e8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1400082c0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140008198 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 140003310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1400084e8 != (code *)0x0) && (DAT_1400084e8 != FxStubDriverUnload)) {
    (*DAT_1400084e8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140003344 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140003369) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  void **ppvVar3;
  
  iVar1 = 0;
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)&__KMDF_CLASS_BIND_END);
    if (puVar2 == (uint *)0x0) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    if ((uint *)0x14000818f < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_140008198 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,*(undefined8 *)(puVar2 + 0xe),puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
  }
  return iVar1;
}



===== FxStubUnbindClasses @ 1400034a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140008198 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_140008198 + 0x50);
    while (puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)puVar1),
          puVar2 != (uint *)0x0) {
      if (puVar1 <= puVar2) {
        return;
      }
      if (*(code **)(puVar2 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      else {
        (**(code **)(puVar2 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
    }
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
  return;
}



===== FxGetNextClassBindInfo @ 140003560 =====

longlong * FxGetNextClassBindInfo(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = param_1 + 1;
  for (; (plVar1 <= param_2 && (*param_1 == 0)); param_1 = param_1 + 1) {
    plVar1 = param_1 + 2;
  }
  if (param_2 <= param_1) {
    return param_2;
  }
  if (param_2 < param_1 + 10) {
    return (longlong *)0x0;
  }
  plVar1 = (longlong *)0x0;
  if ((int)*param_1 == 0x50) {
    plVar1 = param_1;
  }
  return plVar1;
}



===== FxStubInitTypes @ 1400035a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400035c5) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  void *pvVar1;
  void **ppvVar2;
  
  ppvVar2 = &__KMDF_TYPE_INIT_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_TYPE_INIT_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x1400081af < ppvVar2) break;
    if (((&__KMDF_TYPE_INIT_END < ppvVar2 + 5) || (*(uint *)ppvVar2 != 0x28)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextObjectContextTypeInfo failed\n");
      return -0x3fffff85;
    }
    if (ppvVar2[4] != (code *)0x0) {
      pvVar1 = (void *)(*ppvVar2[4])();
      ppvVar2[3] = pvVar1;
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return 0;
}



===== __GSHandlerCheck @ 140003678 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000369c =====

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



===== __cpu_features_init @ 140003710 =====

/* WARNING: Removing unreachable block (ram,0x00014000377a) */
/* WARNING: Removing unreachable block (ram,0x000140003729) */
/* WARNING: Removing unreachable block (ram,0x00014000371a) */

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



===== __security_check_cookie @ 1400037e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140003820 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140003850 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140003850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140003880 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140003900 =====

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



===== memset @ 140003c00 =====

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



===== __memset_repmovs @ 140003d40 =====

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



===== __memset_query @ 140003dc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003e40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140003f80 =====

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



===== __memset_spec_plain @ 140004000 =====

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



===== DriverUnload @ 14000b010 =====

void DriverUnload(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_140008020;
  if ((DAT_140008280 & 0x20) != 0) {
    DAT_140008280 = DAT_140008280 & 0xffffffdf;
    DAT_140008020 = 0;
    DAT_140008000 = 0;
    EtwUnregister(uVar1);
  }
  if ((DAT_140008280 & 1) != 0) {
    DAT_140008280 = DAT_140008280 & 0xfffffffe;
    FreeAdapterListLock();
  }
  if ((DAT_140008280 & 4) != 0) {
    DAT_140008280 = DAT_140008280 & 0xfffffffb;
    NdisMDeregisterMiniportDriver(NdisDriverHandle);
  }
  if ((DAT_140008280 & 2) != 0) {
    DAT_140008280 = DAT_140008280 & 0xfffffffd;
    ExDeleteNPagedLookasideList(&DAT_140008200);
  }
  if ((DAT_140008280 & 8) != 0) {
    DAT_140008280 = DAT_140008280 & 0xfffffff7;
    ExSetTimerResolution(22000,0);
  }
  return;
}



===== KdNicAddDevice @ 14000b0e0 =====

int KdNicAddDevice(undefined8 param_1,undefined8 param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  iVar2 = IoCreateDevice(param_1,8,0,0x12,0,0,local_res18);
  if (-1 < iVar2) {
    plVar1 = *(longlong **)(local_res18[0] + 0x40);
    lVar3 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
    if (lVar3 == 0) {
      iVar2 = -0x3ffffff2;
    }
    else {
      *plVar1 = lVar3;
      *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
      local_res18[0] = 0;
    }
  }
  if (local_res18[0] != 0) {
    IoDeleteDevice();
  }
  return iVar2;
}



===== KdNicDispatchWmi @ 14000b190 =====

void KdNicDispatchWmi(longlong param_1,longlong param_2)

{
  KdNicDispatchForwardIrp(param_1,param_2);
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14000b1a8 =====

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
  local_28 = *(undefined4 *)(PTR_DAT_140008008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_140008008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_140008008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_140008008 + -4);
  if (DAT_140008020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_140008028 = 0;
  uRam0000000140008030 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14000b20b;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_140008000,&DAT_140008020);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_140008008;
    *(undefined8 *)(puVar4 + -8) = 0x14000b232;
    EtwSetInformation(DAT_140008020,2,PTR_DAT_140008008,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x14000b246;
  return iVar3;
}



===== _tlgEnableCallback @ 14000b260 =====

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



===== MPDevicePnpEventNotify @ 14000b2e0 =====

void MPDevicePnpEventNotify(longlong param_1,longlong param_2)

{
  if (*(int *)(param_2 + 8) == 2) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100;
  }
  return;
}



===== MPHaltEx @ 14000b300 =====

void MPHaltEx(longlong *param_1)

{
  undefined4 uVar1;
  
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  NICStopTheDatapath(param_1,0xc0000001);
  while( true ) {
    uVar1 = NICIsBusy((longlong)param_1);
    if ((char)uVar1 == '\0') break;
    NdisMSleep(1000);
  }
  NICFreeAdapter((longlong)param_1);
  return;
}



===== MPInitializeEx @ 14000b350 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong MPInitializeEx(undefined8 param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined7 extraout_var;
  longlong lVar7;
  ulonglong uVar8;
  undefined1 auStack_1b8 [32];
  undefined8 local_198;
  undefined8 local_190;
  longlong local_188;
  ulonglong local_180;
  longlong local_178;
  undefined4 local_170;
  undefined4 local_16c;
  undefined8 local_168;
  undefined8 local_160;
  code *local_158;
  code *local_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined4 local_110;
  undefined4 local_108 [2];
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  short local_ac;
  undefined4 local_aa;
  undefined2 local_a6;
  undefined4 local_8a;
  undefined2 local_86;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  short local_54;
  undefined1 local_52;
  undefined8 local_50;
  undefined8 local_48;
  undefined *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_188 = 0;
  local_180 = (ulonglong)(uint)local_180;
  uVar6 = NICAllocAdapter(&local_188);
  lVar2 = local_188;
  uVar8 = uVar6 & 0xffffffff;
  lVar7 = lVar2;
  if ((int)uVar6 == 0) {
    *(undefined8 *)(local_188 + 0x28) = param_1;
    local_180 = 0x1c1c9e;
    local_168 = 0;
    local_178 = local_188;
    local_170 = 0x24;
    local_16c = 4;
    uVar4 = NdisMSetMiniportAttributes(param_1);
    uVar8 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      uVar6 = NICReadRegParameters(lVar2);
      uVar8 = uVar6 & 0xffffffff;
      if ((int)uVar6 == 0) {
        memset(local_108,0,0xe0);
        local_108[0] = 0xe0029f;
        local_100 = 0;
        local_fc = 0xe;
        local_f8 = 0x5dc;
        local_f0 = *(undefined8 *)(lVar2 + 0x188);
        local_e8 = *(undefined8 *)(lVar2 + 0x188);
        local_e0 = *(undefined8 *)(lVar2 + 400);
        local_d8 = *(undefined8 *)(lVar2 + 400);
        cVar3 = HWGetMediaConnectStatus(lVar2);
        local_d0 = (undefined4)CONCAT71(extraout_var,cVar3);
        local_ac = (short)uVar6 + 6;
        local_cc = 2;
        local_c8 = *(undefined4 *)(lVar2 + 0x180);
        local_b8 = 0xd;
        local_b4 = 0x2f;
        local_b0 = 0x20;
        local_aa = *(undefined4 *)(lVar2 + 0x44);
        local_a6 = *(undefined2 *)(lVar2 + 0x48);
        local_8a = *(undefined4 *)(lVar2 + 0x4a);
        local_86 = *(undefined2 *)(lVar2 + 0x4e);
        local_40 = &NICSupportedOids;
        uStack_140 = 0;
        local_118 = 0;
        local_128 = 0;
        local_68 = 0;
        local_60 = 2;
        local_58 = 1;
        local_52 = 1;
        local_50 = 0x839ffec;
        local_48 = 0;
        local_38 = 0xb0;
        local_34 = 4;
        local_138 = 0;
        uStack_130 = 0;
        local_110 = 0;
        local_148 = 0x3c0280;
        uStack_120 = 0;
        local_30 = 0;
        local_54 = local_ac;
        uVar4 = NdisMSetMiniportAttributes(param_1,local_108);
        uVar8 = (ulonglong)uVar4;
        if (uVar4 == 0) {
          local_190 = 0;
          local_198 = 0;
          NdisMGetDeviceProperty(param_1,lVar2 + 0x10,lVar2 + 0x18,lVar2 + 0x20);
          lVar7 = local_188;
          *(undefined4 *)(lVar2 + 0x138) = 0;
          LOCK();
          *(undefined4 *)(lVar2 + 0x128) = 2;
          UNLOCK();
          local_158 = NdisSetPollNotification;
          local_160 = 0x180180;
          local_150 = NdisPoll;
          puVar1 = (undefined8 *)(local_188 + 0x120);
          iVar5 = NdisRegisterPoll(param_1,local_188,&local_160,puVar1);
          if (iVar5 == 0) {
            NICSetVisible(lVar7);
            return 0;
          }
          *puVar1 = 0;
          uVar8 = 0xc0000001;
        }
      }
    }
  }
  if (lVar7 != 0) {
    NICFreeAdapter(lVar7);
  }
  return uVar8;
}



===== MPPause @ 14000b610 =====

undefined8 MPPause(longlong *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x10;
  NICStopTheDatapath(param_1,0xc023002a);
  uVar1 = NICIsBusy((longlong)param_1);
  uVar2 = 0;
  if ((char)uVar1 == '\0') {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffffef | 0x20;
  }
  else {
    NICScheduleTheResetOrPauseDpc((longlong)param_1,'\0');
    uVar2 = 0x103;
  }
  return uVar2;
}



===== MPRestart @ 14000b660 =====

undefined8 MPRestart(undefined8 *param_1)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffffcf;
  NICStartTheDatapath(param_1);
  return 0;
}



===== NICAllocAdapter @ 14000b67c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NICAllocAdapter(undefined8 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  void *_Dst;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  code *pcStack_50;
  void *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  uVar6 = 0;
  *param_1 = 0;
  local_48 = (void *)0x0;
  local_58 = 0;
  pcStack_50 = (code *)0x0;
  _Dst = (void *)NdisAllocateMemoryWithTagPriority(NdisDriverHandle,0x308,0x5f4e444b,0x10);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x308);
    *(longlong *)((longlong)_Dst + 0x30) = KdNetNicInterface;
    lVar1 = KdNetNicInterface;
    *(undefined4 *)((longlong)_Dst + 0x38) = 0x200;
    *(undefined4 *)((longlong)_Dst + 0x3c) = 0x600;
    if (lVar1 == 0) {
      *(uint *)((longlong)_Dst + 0x40) = *(uint *)((longlong)_Dst + 0x40) | 2;
    }
    else {
      if (*(char *)(lVar1 + 0x56) == '\0') {
        *(uint *)((longlong)_Dst + 0x40) = *(uint *)((longlong)_Dst + 0x40) | 2;
      }
      if (1000 < *(uint *)(lVar1 + 0x58)) {
        uVar7 = *(uint *)(lVar1 + 0x58) / 1000;
        if (0x10 < uVar7) {
          uVar7 = 0x10;
        }
        *(uint *)((longlong)_Dst + 0x38) = uVar7 << 9;
        *(uint *)((longlong)_Dst + 0x3c) = uVar7 * 0x600;
      }
    }
    *(void **)((longlong)_Dst + 8) = _Dst;
    lVar1 = (longlong)_Dst + 0x58;
    *(void **)_Dst = _Dst;
    *(longlong *)((longlong)_Dst + 0x60) = lVar1;
    *(longlong *)lVar1 = lVar1;
    KeInitializeSpinLock((longlong)_Dst + 0x68);
    lVar2 = (longlong)_Dst + 0x78;
    *(longlong *)((longlong)_Dst + 0x80) = lVar2;
    *(longlong *)lVar2 = lVar2;
    KeInitializeSpinLock((longlong)_Dst + 0x88);
    lVar2 = (longlong)_Dst + 0x98;
    *(longlong *)((longlong)_Dst + 0xa0) = lVar2;
    *(longlong *)lVar2 = lVar2;
    KeInitializeSpinLock((longlong)_Dst + 0xa8);
    lVar2 = (longlong)_Dst + 0xd0;
    *(longlong *)((longlong)_Dst + 0xd8) = lVar2;
    *(longlong *)lVar2 = lVar2;
    KeInitializeSpinLock((longlong)_Dst + 0xe0);
    lVar4 = (longlong)_Dst + 0xf0;
    *(longlong *)((longlong)_Dst + 0xf8) = lVar4;
    *(longlong *)lVar4 = lVar4;
    KeInitializeSpinLock((longlong)_Dst + 0x100);
    lVar4 = (longlong)_Dst + 0x140;
    *(longlong *)((longlong)_Dst + 0x148) = lVar4;
    *(longlong *)lVar4 = lVar4;
    lVar4 = (longlong)_Dst + 0x158;
    *(longlong *)((longlong)_Dst + 0x160) = lVar4;
    *(longlong *)lVar4 = lVar4;
    *(undefined4 *)((longlong)_Dst + 0x180) = 0x5dc;
    local_40 = 0x100180;
    local_3c = 0x100;
    local_38 = 0x724e444b;
    lVar4 = NdisAllocateNetBufferListPool(NdisDriverHandle,&local_40);
    *(longlong *)((longlong)_Dst + 0x118) = lVar4;
    if (lVar4 != 0) {
      uVar5 = NdisAllocateMemoryWithTagPriority
                        (*(undefined8 *)((longlong)_Dst + 0x28),
                         *(int *)((longlong)_Dst + 0x38) * 0x30,0x544e444b,0x10);
      *(undefined8 *)((longlong)_Dst + 0x50) = uVar5;
      lVar4 = NdisAllocateMemoryWithTagPriority
                        (*(undefined8 *)((longlong)_Dst + 0x28),
                         *(int *)((longlong)_Dst + 0x3c) * 0x30,0x524e444b,0x10);
      *(longlong *)((longlong)_Dst + 200) = lVar4;
      if ((*(longlong *)((longlong)_Dst + 0x50) != 0) && (lVar4 != 0)) {
        if (*(int *)((longlong)_Dst + 0x38) != 0) {
          do {
            ExInterlockedInsertTailList
                      (lVar1,*(longlong *)((longlong)_Dst + 0x50) + 0x10 + uVar6 * 0x30,
                       (longlong)_Dst + 0x68);
            uVar7 = (int)uVar6 + 1;
            uVar6 = (ulonglong)uVar7;
          } while (uVar7 < *(uint *)((longlong)_Dst + 0x38));
        }
        for (uVar6 = 0; (uint)uVar6 < *(uint *)((longlong)_Dst + 0x3c);
            uVar6 = (ulonglong)((uint)uVar6 + 1)) {
          local_60 = 0;
          lVar1 = *(longlong *)((longlong)_Dst + 200);
          local_68 = 0;
          lVar4 = NdisAllocateNetBufferAndNetBufferList
                            (*(undefined8 *)((longlong)_Dst + 0x118),0,0,0);
          *(longlong *)(uVar6 * 0x30 + lVar1 + 0x20) = lVar4;
          if (lVar4 == 0) goto LAB_14000b9da;
          ExInterlockedInsertTailList(lVar2);
        }
        pcStack_50 = RequestPollDpc;
        local_58 = 0x5f4e444b00180197;
        local_48 = _Dst;
        iVar3 = NdisAllocateTimerObject(NdisDriverHandle,&local_58,(longlong)_Dst + 0x130);
        if (iVar3 == 0) {
          pcStack_50 = NICAsyncResetOrPauseDpc;
          uVar5 = NdisAllocateTimerObject(NdisDriverHandle,&local_58,(longlong)_Dst + 0x170);
          if ((int)uVar5 == 0) goto LAB_14000b9df;
        }
        uVar5 = 0xc0000001;
        goto LAB_14000b9df;
      }
    }
  }
LAB_14000b9da:
  uVar5 = 0xc000009a;
LAB_14000b9df:
  *param_1 = _Dst;
  return uVar5;
}



===== NICFreeAdapter @ 14000ba14 =====

void NICFreeAdapter(longlong param_1)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 0x120) != 0) {
    NdisDeregisterPoll();
    *(undefined8 *)(param_1 + 0x120) = 0;
  }
  if (*(longlong *)(param_1 + 0x170) != 0) {
    NdisFreeTimerObject();
    *(undefined8 *)(param_1 + 0x170) = 0;
  }
  if (*(longlong *)(param_1 + 0x130) != 0) {
    NdisFreeTimerObject();
    *(undefined8 *)(param_1 + 0x130) = 0;
  }
  while( true ) {
    lVar1 = ExInterlockedRemoveHeadList(param_1 + 0xd0,param_1 + 0xe0);
    if (lVar1 == 0) break;
    NdisFreeNetBufferList(*(undefined8 *)(lVar1 + 0x10));
  }
  if (*(longlong *)(param_1 + 0x118) != 0) {
    NdisFreeNetBufferListPool();
    *(undefined8 *)(param_1 + 0x118) = 0;
  }
  if (*(longlong *)(param_1 + 200) != 0) {
    NdisFreeMemory(*(longlong *)(param_1 + 200),*(int *)(param_1 + 0x3c) * 0x30,0);
    *(undefined8 *)(param_1 + 200) = 0;
  }
  if (*(longlong *)(param_1 + 0x50) != 0) {
    NdisFreeMemory(*(longlong *)(param_1 + 0x50),*(int *)(param_1 + 0x38) * 0x30,0);
    *(undefined8 *)(param_1 + 0x50) = 0;
  }
  NdisFreeMemory(param_1,0x308,0);
  return;
}



===== NICReadRegParameters @ 14000bb60 =====

undefined8 NICReadRegParameters(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 local_res8 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_24 = 0;
  local_14 = 0;
  local_res8[0] = 0;
  local_28 = 0x1401a9;
  local_20 = *(undefined8 *)(param_1 + 0x28);
  local_18 = 0;
  iVar2 = NdisOpenConfigurationEx(&local_28,local_res8);
  if (iVar2 == 0) {
    lVar4 = *(longlong *)(param_1 + 0x30);
    if (lVar4 != 0) {
      *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(lVar4 + 0x50);
      *(undefined2 *)(param_1 + 0x48) = *(undefined2 *)(lVar4 + 0x54);
    }
    *(undefined4 *)(param_1 + 0x4a) = *(undefined4 *)(param_1 + 0x44);
    *(undefined2 *)(param_1 + 0x4e) = *(undefined2 *)(param_1 + 0x48);
    if (lVar4 == 0) {
      lVar4 = 1000000000;
      *(undefined8 *)(param_1 + 0x188) = 1000000000;
    }
    else {
      *(ulonglong *)(param_1 + 0x188) = (ulonglong)*(uint *)(lVar4 + 0xc) * 1000000;
      uVar1 = *(uint *)(lVar4 + 0xc);
      *(ulonglong *)(param_1 + 400) = (ulonglong)uVar1;
      lVar4 = (ulonglong)uVar1 * 1000000;
    }
    *(longlong *)(param_1 + 400) = lVar4;
    NdisCloseConfiguration(local_res8[0]);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== NICSetVisible @ 14000bc34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NICSetVisible(longlong param_1)

{
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined1 local_c8 [4];
  int local_c4;
  undefined8 local_c0;
  longlong local_b8 [2];
  wchar_t *local_a8;
  longlong local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_74;
  undefined1 *local_58;
  undefined4 local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  local_b8[1] = 0x20001e;
  local_c0 = 0;
  local_a8 = L"Characteristics";
  local_b8[0] = 0;
  local_c8[0] = 0;
  local_84 = 0;
  memset(&local_88,0,0x6c);
  local_98 = *(undefined8 *)(param_1 + 0x28);
  local_a0 = 0x1401a9;
  local_90 = 0;
  local_c4 = NdisOpenConfigurationEx(local_b8 + 3,&local_c0);
  if (local_c4 == 0) {
    local_d8 = 0;
    NdisReadConfiguration(&local_c4,local_b8,local_c0,local_b8 + 1);
    if (-1 < local_c4) {
      *(uint *)(local_b8[0] + 8) = *(uint *)(local_b8[0] + 8) & 0xfffffff7;
      NdisWriteConfiguration(&local_c4,local_c0,local_b8 + 1,local_b8[0]);
      memset(&local_88,0,0x70);
      local_58 = local_c8;
      local_88 = 0x700198;
      local_74 = 0x40020063;
      local_50 = 1;
      NdisMIndicateStatusEx(*(undefined8 *)(param_1 + 0x28),&local_88);
    }
    NdisCloseConfiguration(local_c0);
  }
  else {
    local_c4 = -0x3fffffff;
  }
  return local_c4;
}



===== NICStartTheDatapath @ 14000bd90 =====

void NICStartTheDatapath(undefined8 *param_1)

{
  MPAttachAdapter(param_1);
  if (param_1[6] != 0) {
    LOCK();
    *(undefined4 *)(param_1 + 0x25) = 0;
    UNLOCK();
    *(undefined4 *)(param_1 + 0x27) = 1;
    SchedulePollRequest((longlong)param_1);
  }
  return;
}



===== NICStopTheDatapath @ 14000bdcc =====

void NICStopTheDatapath(longlong *param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined8 local_res8;
  
  NdisCancelTimerObject(param_1[0x2e]);
  *(undefined4 *)(param_1 + 0x27) = 0;
  NdisCancelTimerObject(param_1[0x26]);
  local_res8 = 0xffffffffffffb1e0;
  while( true ) {
    iVar3 = 0;
    LOCK();
    iVar1 = (int)param_1[0x25];
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x25) = 2;
    }
    else {
      iVar3 = iVar1;
    }
    UNLOCK();
    if ((iVar3 == 2) || (iVar3 == 0)) break;
    KeDelayExecutionThread(0,0,&local_res8);
  }
  KeFlushQueuedDpcs();
  MPDetachAdapter(param_1);
  TXFlushSendQueue((longlong)param_1,param_2);
  RxFlushReceiveQueue((longlong)param_1);
  cVar2 = KdPollBreakIn();
  if (cVar2 != '\0') {
    DbgBreakPointWithStatus(1);
  }
  TXFlushSendQueue((longlong)param_1,param_2);
  RxFlushReceiveQueue((longlong)param_1);
  return;
}



===== KdNicFallbackCreatePdo @ 14000beb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KdNicFallbackCreatePdo(undefined8 param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 auStack_168 [32];
  undefined4 local_148;
  longlong local_138;
  longlong local_130 [2];
  wchar_t *local_120;
  undefined8 local_118;
  wchar_t *local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  wchar_t local_68 [24];
  wchar_t local_38 [20];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_168;
  local_130[0] = 0;
  local_e8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  local_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  memset(&local_b8,0,0x50);
  builtin_wcsncpy(local_68,L"KdNicLegacyEnume",0x10);
  builtin_wcsncpy(local_68 + 0x10,L"rator",6);
  local_110 = local_38;
  builtin_wcsncpy(local_38,L"KdNic legacy dev",0x10);
  local_130[1] = 0x2c002a;
  builtin_wcsncpy(local_38 + 0x10,L"ice",4);
  local_118 = 0x280026;
  local_108 = 0;
  uStack_100 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_120 = local_68;
  local_138 = (**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals,param_1);
  if (local_138 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_138,0x12);
    RtlInitUnicodeString(&local_108,L"KDNIC\\Legacy");
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_138,&local_108);
    uVar3 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_138,&local_108);
      uVar3 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        RtlInitUnicodeString(&local_f8,L"0000");
        uVar1 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_138,&local_f8);
        uVar3 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_148 = 0x409;
          uVar1 = (**(code **)(WdfFunctions_01015 + 0x6c0))
                            (WdfDriverGlobals,local_138,&local_118,local_130 + 1);
          uVar3 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            (**(code **)(WdfFunctions_01015 + 0x6c8))(WdfDriverGlobals,local_138,0x409);
            uVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_138,0,local_130)
            ;
            uVar3 = (ulonglong)uVar1;
            if (-1 < (int)uVar1) {
              local_e8 = 0x30;
              uStack_e4 = 2;
              uStack_e0 = 2;
              uStack_dc = 2;
              local_d8 = 2;
              uStack_d4 = 1;
              uStack_d0 = 0x100000002;
              local_c8 = 0x200000002;
              uStack_c0 = 0xffffffffffffffff;
              (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_130[0],&local_e8);
              local_80 = 5;
              local_6c = 5;
              local_9c = 5;
              uStack_88 = 4;
              local_84 = 4;
              local_b8 = 0x50;
              local_b4 = 2;
              local_b0 = 2;
              local_ac = 2;
              local_a8 = 2;
              local_a4 = 2;
              local_a0 = 2;
              local_7c = 7;
              local_78 = 0xffffffff;
              local_74 = 0xffffffff;
              local_70 = 0xffffffff;
              uStack_98 = 1;
              uStack_94 = 4;
              uStack_90 = 4;
              local_8c = 4;
              (**(code **)(WdfFunctions_01015 + 0x2a0))(WdfDriverGlobals,local_130[0],&local_b8);
              uVar2 = (**(code **)(WdfFunctions_01015 + 0x428))
                                (WdfDriverGlobals,param_1,local_130[0]);
              uVar3 = uVar2 & 0xffffffff;
              if (-1 < (int)uVar2) {
                return uVar2;
              }
            }
          }
        }
      }
    }
  }
  if (local_138 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
  }
  if (local_130[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return uVar3;
}



===== KdNicFallbackDriverEntry @ 14000c298 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KdNicFallbackDriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_24 = 0;
  local_28 = 0x20;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = KdNicFallbackEvtDeviceAdd;
  (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_28,0);
  return;
}



===== KdNicFallbackEvtDeviceAdd @ 14000c300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 KdNicFallbackEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 auStack_88 [48];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined8 local_24;
  undefined8 uStack_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  local_58 = 0;
  local_40 = 0;
  local_50 = param_2;
  uVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_50,0,&local_58);
  if (-1 < (int)uVar1) {
    local_30 = 0x1c;
    local_2c = 2;
    local_24 = 0x200000002;
    uStack_1c = 0x200000002;
    local_28 = 1;
    (**(code **)(WdfFunctions_01015 + 0xe8))(WdfDriverGlobals,local_58,&local_30);
    local_48 = 0;
    local_40 = 0;
    local_34 = 0;
    local_38 = 0xf;
    (**(code **)(WdfFunctions_01015 + 0x2a8))(WdfDriverGlobals,local_58,&local_48);
    KdNicFallbackCreatePdo(local_58);
    uVar1 = 0;
  }
  return uVar1;
}



===== KdNicDispatchPnp @ 14000c400 =====

ulonglong KdNicDispatchPnp(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar1 != '\x03') {
    switch(cVar1) {
    case '\0':
    case '\x01':
    case '\x04':
    case '\x05':
    case '\x06':
      break;
    case '\x02':
      uVar3 = KdNicDispatchForwardIrp(param_1,param_2);
      IoDetachDevice(*puVar2);
      IoDeleteDevice(param_1);
      return (ulonglong)uVar3;
    default:
      goto switchD_14000c444_caseD_3;
    case '\x14':
      *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 2;
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
switchD_14000c444_caseD_3:
  uVar4 = KdNicDispatchForwardIrp(param_1,param_2);
  return uVar4;
}



===== __security_init_cookie @ 14000d008 =====

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



===== DriverEntry @ 14000d03c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  uint local_res8 [2];
  undefined4 local_b8;
  undefined8 local_b4;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  
  memset(&local_b8,0,0xa0);
  local_res8[0] = local_res8[0] & 0xffffff00;
  memset(&DAT_1400081d0,0,0xf0);
  DAT_1400081c8 = &GlobalData;
  _GlobalData = &GlobalData;
  GetKdNetNetworkInterface();
  if (((KdNetNicInterface == (short *)0x0) || (*KdNetNicInterface != 3)) ||
     (KdNetNicInterface[1] != 0x60)) {
    *(code **)(param_1 + 0x68) = DriverUnload;
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = KdNicAddDevice;
    *(code **)(param_1 + 0x148) = KdNicDispatchPnp;
    *(code **)(param_1 + 0x120) = KdNicDispatchPower;
    *(code **)(param_1 + 0x128) = KdNicDispatchWmi;
    return 0;
  }
  GetKdNicLegacyFallbackConfig(param_1,(undefined1 *)local_res8);
  if ((char)local_res8[0] == '\0') {
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
    DAT_140008280 = DAT_140008280 | 0x20;
    local_res8[0] = 20000;
    GetSystemTimerResolution(local_res8);
    ExSetTimerResolution(local_res8[0],1);
    DAT_140008280 = DAT_140008280 | 8;
    uVar2 = NdisGetVersion();
    ExInitializeNPagedLookasideList
              (&DAT_140008200,HWFrameAllocate,HWFrameFree,~-(uint)(uVar2 < 0x6001e) & 0x200,0x600,
               0x464e444b,0);
    DAT_140008280 = DAT_140008280 | 2;
    local_a8 = MPSetOptions;
    local_b8 = 0xa0038a;
    local_a0 = MPInitializeEx;
    local_b4 = 0x55606;
    local_98 = MPHaltEx;
    local_90 = DriverUnload;
    local_88 = MPPause;
    local_80 = MPRestart;
    local_78 = MPOidRequest;
    local_70 = MPSendNetBufferLists;
    local_68 = MPReturnNetBufferLists;
    local_60 = _guard_check_icall;
    local_58 = MPCheckForHangEx;
    local_50 = MPResetEx;
    local_48 = MPDevicePnpEventNotify;
    local_40 = _guard_check_icall;
    local_38 = _guard_check_icall;
    iVar1 = NdisMRegisterMiniportDriver(param_1,param_2,&GlobalData,&local_b8,&NdisDriverHandle);
    if (iVar1 == 0) {
      DAT_140008280 = DAT_140008280 | 4;
      DAT_1400081d0 = NdisAllocateRWLock(NdisDriverHandle);
      if (DAT_1400081d0 != 0) {
        DAT_140008280 = DAT_140008280 | 1;
        return 0;
      }
      iVar1 = -0x3fffff66;
      DAT_1400081d0 = 0;
      goto LAB_14000d0f2;
    }
  }
  else {
    iVar1 = KdNicFallbackDriverEntry(param_1,param_2);
  }
  if (-1 < iVar1) {
    return iVar1;
  }
LAB_14000d0f2:
  DriverUnload();
  return iVar1;
}


