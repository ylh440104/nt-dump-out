
===== DiskShutdownFlush @ 140001010 =====

undefined8 DiskShutdownFlush(longlong param_1,longlong *param_2,undefined8 param_3)

{
  byte bVar1;
  longlong lVar2;
  char *pcVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined2 uVar9;
  uint uVar10;
  undefined4 uVar11;
  longlong lVar12;
  undefined2 *puVar13;
  longlong lVar14;
  longlong lVar15;
  undefined1 *puVar16;
  longlong *plVar17;
  undefined8 uVar18;
  undefined2 *puVar19;
  bool bVar20;
  undefined2 *local_res10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  pcVar3 = (char *)param_2[0x17];
  bVar20 = false;
  puVar19 = (undefined2 *)0x0;
  lVar14 = *(longlong *)(lVar2 + 0x18);
  lVar15 = *(longlong *)(lVar2 + 0x60);
  if (*pcVar3 == '\t') {
    if ((*(ushort *)(lVar14 + 0x280) & 0x10) != 0) {
      *(undefined4 *)(param_2 + 6) = 0;
      ClassReleaseRemoveLock(param_1);
      ClassCompleteRequest(param_1,param_2,0);
      return 0;
    }
    lVar2 = lVar15 + 0x1d8;
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,param_3,param_2,pcVar3[2]);
    }
    puVar16 = auStack_68;
    *(byte *)(param_2[0x17] + 3) = *(byte *)(param_2[0x17] + 3) | 1;
    lVar14 = lVar15;
    if (*(longlong *)(lVar15 + 0x80) == 0) {
      *(longlong **)(lVar15 + 0x80) = param_2;
      if ((*(longlong *)(lVar15 + 0x1f8) == 0) && ((pcVar3[2] & 1U) != 0)) {
        lVar12 = IoAllocateIrp(*(char *)(param_1 + 0x4c) + '\x03',0);
        *(longlong *)(lVar15 + 0x1f8) = lVar12;
        if (lVar12 == 0) {
          *(undefined8 *)(lVar15 + 0x80) = 0;
        }
      }
      KeReleaseSpinLock(lVar2,uVar8);
      plVar17 = param_2;
      if ((pcVar3[2] & 1U) == 0) {
        DiskFlushDispatch(param_1,lVar15 + 0x70);
        return 0x103;
      }
    }
    else {
      if (*(longlong *)(lVar15 + 0x98) == 0) {
        *(longlong **)(lVar15 + 0x98) = param_2;
        bVar1 = pcVar3[2];
        *(byte *)(lVar15 + 0x200) = ~bVar1 & 1;
        KeReleaseSpinLock(lVar2,uVar8);
        if ((~bVar1 & 1) == 0) {
          return 0x103;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                  &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
        }
        KeWaitForSingleObject(lVar15 + 0x1e0,0,0,0);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                  &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
        }
        uVar8 = KeAcquireSpinLockRaiseToDpc(lVar2);
        plVar17 = (longlong *)(lVar15 + 0x70);
        plVar4 = (longlong *)(lVar15 + 0x88);
        while( true ) {
          plVar5 = (longlong *)*plVar4;
          if (plVar5 == plVar4) {
            *(undefined8 *)(lVar15 + 0x80) = *(undefined8 *)(lVar15 + 0x98);
            *(undefined8 *)(lVar15 + 0x98) = 0;
            *(undefined1 *)(lVar15 + 0x200) = 0;
            KeReleaseSpinLock(lVar2,uVar8);
            DiskFlushDispatch(param_1,(longlong)plVar17);
            return 0x103;
          }
          if (((longlong *)plVar5[1] != plVar4) ||
             (lVar12 = *plVar5, *(longlong **)(lVar12 + 8) != plVar5)) break;
          *plVar4 = lVar12;
          *(longlong **)(lVar12 + 8) = plVar4;
          plVar6 = *(longlong **)(lVar15 + 0x78);
          if ((longlong *)*plVar6 != plVar17) break;
          *plVar5 = (longlong)plVar17;
          plVar5[1] = (longlong)plVar6;
          *plVar6 = (longlong)plVar5;
          *(longlong **)(lVar15 + 0x78) = plVar5;
        }
      }
      else {
        lVar14 = lVar15 + 0x88;
        plVar17 = param_2 + 0x15;
        plVar4 = *(longlong **)(lVar15 + 0x90);
        if (*plVar4 == lVar14) {
          *plVar17 = lVar14;
          param_2[0x16] = (longlong)plVar4;
          *plVar4 = (longlong)plVar17;
          *(longlong **)(lVar15 + 0x90) = plVar17;
          KeReleaseSpinLock(lVar2,uVar8);
          return 0x103;
        }
      }
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)(3);
      puVar16 = auStack_60;
    }
    param_2 = plVar17;
    if (*(longlong *)(lVar14 + 0x1f8) != 0) {
      *(undefined8 *)(puVar16 + -8) = 0x1400012de;
      DiskFlushDispatchAsync(param_1,lVar14 + 0x70);
      return 0x103;
    }
  }
  else {
    if (*(char *)(*(longlong *)(lVar14 + 0x210) + 0x1e) == '\x01') {
      bVar20 = *(char *)(*(longlong *)(lVar14 + 0x210) + 0x1f) == '\x01';
      uVar11 = 0x134;
      if (!bVar20) {
        uVar11 = 0xb8;
      }
    }
    else {
      uVar11 = 0x58;
    }
    puVar13 = (undefined2 *)ExAllocatePool2(0x40,uVar11);
    puVar16 = auStack_68;
    if (puVar13 != (undefined2 *)0x0) {
      if (*(char *)(*(longlong *)(lVar14 + 0x210) + 0x1e) == '\x01') {
        *puVar13 = 8;
        *(undefined1 *)(puVar13 + 1) = 0x28;
        *(undefined4 *)(puVar13 + 4) = 0x53524258;
        *(undefined4 *)(puVar13 + 6) = 1;
        *(undefined4 *)(puVar13 + 8) = uVar11;
        *(undefined4 *)(puVar13 + 10) = 0;
        uVar9 = IoGetIoPriorityHint(param_2);
        *(undefined4 *)(puVar13 + 0x1a) = 0x80;
        puVar13[0x12] = uVar9;
        *(undefined4 *)(puVar13 + 0x1c) = 1;
        *(int *)(puVar13 + 0x14) = *(int *)(lVar14 + 0x248) << 2;
        *(undefined4 *)(puVar13 + 0x10) = 0xff;
        puVar13[0x13] = 0x20;
        *(undefined4 *)(puVar13 + 0xc) = *(undefined4 *)(lVar14 + 0x250);
        puVar13[0x40] = 1;
        *(undefined4 *)(puVar13 + 0x42) = 4;
        uVar10 = (uint)bVar20 * 4 + 0x90;
        *(uint *)(puVar13 + 0x3c) = uVar10;
        if (*(uint *)(puVar13 + 8) < (uint)bVar20 * 4 + 0xb8) {
LAB_14000151e:
          *(undefined4 *)(param_2 + 6) = 0xc00000e5;
          ClassReleaseRemoveLock(param_1,param_2);
          ClassCompleteRequest(param_1,param_2,0);
          return 0xc00000e5;
        }
        *(undefined4 *)((ulonglong)uVar10 + (longlong)puVar13) = 0x40;
        lVar15 = (ulonglong)uVar10 + (longlong)puVar13;
        *(undefined4 *)(lVar15 + 4) = 0x20;
        local_res10 = (undefined2 *)(lVar15 + 0x18);
        puVar19 = puVar13;
        if (bVar20 != false) {
          uVar10 = *(int *)(puVar13 + 0x3c) + 0x28;
          *(uint *)(puVar13 + 0x3e) = uVar10;
          if ((ulonglong)*(uint *)(puVar13 + 8) < (ulonglong)uVar10 + 0x70) goto LAB_14000151e;
          *(undefined4 *)((ulonglong)uVar10 + (longlong)puVar13) = 0x43;
          *(undefined4 *)((ulonglong)uVar10 + 4 + (longlong)puVar13) = 100;
        }
      }
      else {
        *puVar13 = 0x58;
        local_res10 = puVar13 + 0x24;
        lVar15 = 0;
        *(int *)(puVar13 + 10) = *(int *)(lVar14 + 0x248) << 2;
        puVar13[4] = 0x20ff;
        *(undefined4 *)(puVar13 + 6) = *(undefined4 *)(lVar14 + 0x250);
        *(undefined1 *)(puVar13 + 1) = 0;
      }
      if ((*(ushort *)(lVar14 + 0x280) & 1) != 0) {
        if (*(char *)(*(longlong *)(lVar14 + 0x210) + 0x1e) == '\x01') {
          *(undefined1 *)(lVar15 + 10) = 10;
        }
        else {
          *(undefined1 *)(puVar13 + 5) = 10;
        }
        *(undefined1 *)local_res10 = 0x35;
        uVar18 = 0;
        uVar11 = ClassSendSrbSynchronous(param_1,puVar13,0,0);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,uVar18,uVar11);
        }
      }
      if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
        if (*(char *)(*(longlong *)(lVar14 + 0x210) + 0x1e) == '\x01') {
          *(undefined1 *)((longlong)puVar19 + 3) = 0;
          *(undefined1 *)(lVar15 + 8) = 0;
          *(undefined1 *)(lVar15 + 10) = 6;
          *(undefined4 *)(puVar19 + 0x14) = *(undefined4 *)(lVar14 + 0x248);
        }
        else {
          *(undefined2 *)((longlong)puVar13 + 3) = 0;
          *(undefined1 *)(puVar13 + 5) = 6;
          *(undefined4 *)(puVar13 + 10) = *(undefined4 *)(lVar14 + 0x248);
        }
        *(byte *)(local_res10 + 2) = *(byte *)(local_res10 + 2) & 0xfe;
        *(undefined1 *)local_res10 = 0x1e;
        uVar18 = 0;
        uVar11 = ClassSendSrbSynchronous(param_1,puVar13,0,0);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,uVar18,uVar11);
        }
      }
      if (*(char *)(*(longlong *)(lVar14 + 0x210) + 0x1e) == '\x01') {
        *(undefined4 *)(puVar19 + 0x1c) = 0;
        *(undefined4 *)(puVar19 + 0x3c) = 0;
        *(undefined4 *)(puVar19 + 10) = 7;
        *(longlong **)(puVar19 + 0x28) = param_2;
        *(undefined4 *)(puVar19 + 8) = 0x90;
        *(undefined1 *)((longlong)puVar19 + 3) = 0;
      }
      else {
        *(undefined1 *)(puVar13 + 5) = 0;
        puVar13[1] = 7;
        *(longlong **)(puVar13 + 0x18) = param_2;
      }
      pcVar7 = ClassIoComplete_exref;
      pcVar3[0x20] = '\0';
      pcVar3[0x21] = '\0';
      pcVar3[0x22] = '\0';
      pcVar3[0x23] = '\0';
      pcVar3[0x24] = '\0';
      pcVar3[0x25] = '\0';
      pcVar3[0x26] = '\0';
      pcVar3[0x27] = '\0';
      lVar14 = param_2[0x17];
      *(code **)(lVar14 + -0x10) = pcVar7;
      *(undefined2 **)(lVar14 + -8) = puVar13;
      *(undefined1 *)(lVar14 + -0x45) = 0xe0;
      lVar14 = param_2[0x17];
      *(undefined1 *)(lVar14 + -0x48) = 0xf;
      *(undefined2 **)(lVar14 + -0x40) = puVar13;
      *(byte *)(param_2[0x17] + 3) = *(byte *)(param_2[0x17] + 3) | 1;
      IofCallDriver(*(undefined8 *)(lVar2 + 0x10),param_2);
      return 0x103;
    }
  }
  *(undefined4 *)(param_2 + 6) = 0xc000009a;
  *(undefined8 *)(puVar16 + -8) = 0x140001155;
  ClassReleaseRemoveLock(param_1,param_2);
  *(undefined8 *)(puVar16 + -8) = 0x14000116a;
  ClassCompleteRequest(param_1,param_2,0);
  return 0xc000009a;
}



===== DiskFlushDispatch @ 140001750 =====

void DiskFlushDispatch(longlong param_1,longlong param_2)

{
  undefined2 *puVar1;
  longlong *plVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  ulonglong uVar10;
  bool bVar11;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  puVar1 = (undefined2 *)(param_2 + 0x30);
  bVar11 = false;
  iVar7 = 0;
  if (*(char *)(*(longlong *)(lVar4 + 0x210) + 0x1e) == '\x01') {
    memset((void *)(param_2 + 0x32),0,0x132);
    *puVar1 = 8;
    *(undefined1 *)(param_2 + 0x32) = 0x28;
    *(undefined4 *)(param_2 + 0x38) = 0x53524258;
    *(undefined4 *)(param_2 + 0x3c) = 1;
    cVar3 = *(char *)(*(longlong *)(lVar4 + 0x210) + 0x1f);
    uVar8 = 0x134;
    if (cVar3 != '\x01') {
      uVar8 = 0xb8;
    }
    *(undefined4 *)(param_2 + 0x40) = uVar8;
    uVar6 = IoGetIoPriorityHint(*(undefined8 *)(param_2 + 0x10));
    *(undefined4 *)(param_2 + 100) = 0x80;
    *(undefined2 *)(param_2 + 0x54) = uVar6;
    *(int *)(param_2 + 0x58) = *(int *)(lVar4 + 0x248) << 2;
    bVar11 = cVar3 == '\x01';
    *(undefined4 *)(param_2 + 0x50) = 0xff;
    *(undefined2 *)(param_2 + 0x56) = 0x20;
    *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(lVar4 + 0x250);
    *(undefined2 *)(param_2 + 0xb0) = 1;
    *(undefined4 *)(param_2 + 0xb4) = 4;
  }
  else {
    memset((void *)(param_2 + 0x32),0,0x56);
    *puVar1 = 0x58;
    *(int *)(param_2 + 0x44) = *(int *)(lVar4 + 0x248) << 2;
    *(undefined2 *)(param_2 + 0x38) = 0x20ff;
    *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(lVar4 + 0x250);
  }
  if ((*(ushort *)(lVar4 + 0x280) & 1) != 0) {
    if (*(char *)(*(longlong *)(lVar4 + 0x210) + 0x1e) == '\x01') {
      *(undefined4 *)(param_2 + 0x44) = 0;
      if (bVar11) {
        *(undefined4 *)(param_2 + 0x68) = 2;
        uVar9 = 0x94;
        *(undefined4 *)(param_2 + 0xac) = 0xbc;
      }
      else {
        *(undefined4 *)(param_2 + 0x68) = 1;
        uVar9 = 0x90;
      }
      uVar10 = (ulonglong)uVar9;
      *(uint *)(param_2 + 0xa8) = uVar9;
      if ((ulonglong)*(uint *)(param_2 + 0x40) < uVar10 + 0x28) {
        return;
      }
      *(undefined4 *)(uVar10 + (longlong)puVar1) = 0x40;
      *(undefined4 *)(uVar10 + 4 + (longlong)puVar1) = 0x20;
      *(undefined1 *)(uVar10 + 10 + (longlong)puVar1) = 10;
      *(undefined1 *)(uVar10 + 0x18 + (longlong)puVar1) = 0x35;
      if (bVar11) {
        uVar10 = (ulonglong)*(uint *)(param_2 + 0xac);
        if ((ulonglong)*(uint *)(param_2 + 0x40) < uVar10 + 0x70) {
          return;
        }
        *(undefined4 *)(uVar10 + (longlong)puVar1) = 0x43;
        *(undefined4 *)(uVar10 + 4 + (longlong)puVar1) = 100;
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x32) = 0;
      *(undefined1 *)(param_2 + 0x3a) = 10;
      *(undefined1 *)(param_2 + 0x78) = 0x35;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    iVar7 = ClassSendSrbSynchronous(param_1,puVar1,0,0,1);
  }
  plVar2 = (longlong *)(param_2 + 0x10);
  if (*(char *)(*(longlong *)(lVar4 + 0x210) + 0x1e) == '\x01') {
    *(undefined4 *)(param_2 + 0x44) = 8;
    *(undefined4 *)(param_2 + 0x68) = 0;
    *(undefined4 *)(param_2 + 0xa8) = 0;
    *(uint *)(param_2 + 0x48) = *(uint *)(param_2 + 0x48) | 0x20000000;
    *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_2 + 0x10);
  }
  else {
    *(undefined1 *)(param_2 + 0x32) = 8;
    *(undefined1 *)(param_2 + 0x3a) = 0;
    *(uint *)(param_2 + 0x3c) = *(uint *)(param_2 + 0x3c) | 0x20000000;
    *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_2 + 0x10);
    *(undefined1 *)(param_2 + 0x34) = 0;
  }
  *(undefined1 *)(param_2 + 0x33) = 0;
  *(undefined8 *)(*(longlong *)(*plVar2 + 0xb8) + 0x20) = 0;
  lVar5 = *(longlong *)(*plVar2 + 0xb8);
  *(undefined1 *)(lVar5 + -0x48) = 0xf;
  *(undefined2 **)(lVar5 + -0x40) = puVar1;
  lVar5 = *(longlong *)(*plVar2 + 0xb8);
  *(code **)(lVar5 + -0x10) = DiskFlushComplete;
  *(longlong *)(lVar5 + -8) = (longlong)iVar7;
  *(undefined1 *)(lVar5 + -0x45) = 0xe0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,*plVar2);
  }
  IofCallDriver(*(undefined8 *)(lVar4 + 0x10),*plVar2);
  return;
}



===== DiskFlushDispatchAsync @ 140001aa0 =====

void DiskFlushDispatchAsync(longlong param_1,longlong param_2)

{
  undefined2 *puVar1;
  char *pcVar2;
  longlong *plVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined2 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  bool bVar15;
  
  lVar5 = *(longlong *)(param_1 + 0x40);
  puVar1 = (undefined2 *)(param_2 + 0x30);
  bVar15 = false;
  if (*(char *)(*(longlong *)(lVar5 + 0x210) + 0x1e) == '\x01') {
    memset((void *)(param_2 + 0x32),0,0x132);
    *puVar1 = 8;
    *(undefined1 *)(param_2 + 0x32) = 0x28;
    *(undefined4 *)(param_2 + 0x38) = 0x53524258;
    *(undefined4 *)(param_2 + 0x3c) = 1;
    cVar4 = *(char *)(*(longlong *)(lVar5 + 0x210) + 0x1f);
    uVar10 = 0x134;
    if (cVar4 != '\x01') {
      uVar10 = 0xb8;
    }
    *(undefined4 *)(param_2 + 0x40) = uVar10;
    uVar9 = IoGetIoPriorityHint(*(undefined8 *)(param_2 + 0x10));
    *(undefined4 *)(param_2 + 100) = 0x80;
    *(undefined2 *)(param_2 + 0x54) = uVar9;
    iVar12 = *(int *)(lVar5 + 0x248);
    *(undefined4 *)(param_2 + 0x50) = 0xff;
    *(undefined2 *)(param_2 + 0x56) = 0x20;
    *(int *)(param_2 + 0x58) = iVar12 << 2;
    uVar11 = *(uint *)(lVar5 + 0x250);
    *(uint *)(param_2 + 0x48) = uVar11;
    bVar15 = cVar4 == '\x01';
    *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_2 + 0x10);
    *(uint *)(param_2 + 0x48) = uVar11 | 0x20000000;
    *(undefined2 *)(param_2 + 0xb0) = 1;
    *(undefined4 *)(param_2 + 0xb4) = 4;
  }
  else {
    memset((void *)(param_2 + 0x32),0,0x56);
    *puVar1 = 0x58;
    *(int *)(param_2 + 0x44) = *(int *)(lVar5 + 0x248) << 2;
    *(undefined2 *)(param_2 + 0x38) = 0x20ff;
    uVar11 = *(uint *)(lVar5 + 0x250);
    *(uint *)(param_2 + 0x3c) = uVar11;
    *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_2 + 0x10);
    *(uint *)(param_2 + 0x3c) = uVar11 | 0x20000000;
  }
  if ((*(ushort *)(lVar5 + 0x280) & 1) == 0) {
    if (*(char *)(*(longlong *)(lVar5 + 0x210) + 0x1e) == '\x01') {
      *(undefined4 *)(param_2 + 0x44) = 8;
      *(undefined4 *)(param_2 + 0x68) = 0;
      *(undefined4 *)(param_2 + 0xa8) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x32) = 8;
      *(undefined1 *)(param_2 + 0x3a) = 0;
      *(undefined1 *)(param_2 + 0x34) = 0;
    }
    *(undefined1 *)(param_2 + 0x33) = 0;
    *(undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0xb8) + 0x20) = 0;
    lVar6 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 0xb8);
    *(code **)(lVar6 + -0x10) = DiskFlushComplete;
    *(undefined8 *)(lVar6 + -8) = 0;
    *(undefined1 *)(lVar6 + -0x45) = 0xe0;
    lVar6 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 0xb8);
    *(undefined1 *)(lVar6 + -0x48) = 0xf;
    *(undefined2 **)(lVar6 + -0x40) = puVar1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,*(undefined8 *)(param_2 + 0x10));
    }
    IofCallDriver(*(undefined8 *)(lVar5 + 0x10),*(undefined8 *)(param_2 + 0x10));
  }
  else {
    if (*(char *)(*(longlong *)(lVar5 + 0x210) + 0x1e) == '\x01') {
      *(undefined4 *)(param_2 + 0x44) = 0;
      if (bVar15) {
        *(undefined4 *)(param_2 + 0x68) = 2;
        uVar11 = 0x94;
        *(undefined4 *)(param_2 + 0xac) = 0xbc;
      }
      else {
        *(undefined4 *)(param_2 + 0x68) = 1;
        uVar11 = 0x90;
      }
      uVar13 = (ulonglong)uVar11;
      *(uint *)(param_2 + 0xa8) = uVar11;
      if ((ulonglong)*(uint *)(param_2 + 0x40) < uVar13 + 0x28) {
        return;
      }
      *(undefined4 *)(uVar13 + (longlong)puVar1) = 0x40;
      *(undefined4 *)(uVar13 + 4 + (longlong)puVar1) = 0x20;
      *(undefined1 *)(uVar13 + 10 + (longlong)puVar1) = 10;
      *(undefined1 *)(uVar13 + 0x18 + (longlong)puVar1) = 0x35;
      if (bVar15) {
        uVar13 = (ulonglong)*(uint *)(param_2 + 0xac);
        if ((ulonglong)*(uint *)(param_2 + 0x40) < uVar13 + 0x70) {
          return;
        }
        *(undefined4 *)(uVar13 + (longlong)puVar1) = 0x43;
        *(undefined4 *)(uVar13 + 4 + (longlong)puVar1) = 100;
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x32) = 0;
      *(undefined1 *)(param_2 + 0x3a) = 10;
      *(undefined1 *)(param_2 + 0x78) = 0x35;
    }
    IoReuseIrp(*(undefined8 *)(param_2 + 0x188),0xc00000bb);
    ClassAcquireRemoveLockEx
              (param_1,*(undefined8 *)(param_2 + 0x188),"minkernel\\storage\\disk\\disk.c",0x7e9);
    *(undefined8 *)(*(longlong *)(param_2 + 0x188) + 0x98) =
         *(undefined8 *)(*(longlong *)(param_2 + 0x10) + 0x98);
    lVar5 = *(longlong *)(param_2 + 0x188);
    pcVar2 = (char *)(lVar5 + 0x43);
    *pcVar2 = *pcVar2 + -1;
    plVar3 = (longlong *)(lVar5 + 0xb8);
    *plVar3 = *plVar3 + -0x48;
    lVar5 = *(longlong *)(*(longlong *)(param_2 + 0x188) + 0xb8);
    *(undefined8 *)(lVar5 + 8) = *(undefined8 *)(param_2 + 0x10);
    *(longlong *)(lVar5 + 0x28) = param_1;
    lVar5 = *(longlong *)(*(longlong *)(param_2 + 0x188) + 0xb8);
    *(code **)(lVar5 + -0x10) = DiskFlushAsyncComplete;
    *(undefined8 *)(lVar5 + -8) = 0;
    *(undefined1 *)(lVar5 + -0x45) = 0xe0;
    lVar5 = *(longlong *)(param_2 + 0x188);
    pcVar2 = (char *)(lVar5 + 0x43);
    *pcVar2 = *pcVar2 + -1;
    plVar3 = (longlong *)(lVar5 + 0xb8);
    *plVar3 = *plVar3 + -0x48;
    puVar7 = *(undefined1 **)(*(longlong *)(param_2 + 0x188) + 0xb8);
    *(longlong *)(puVar7 + 0x28) = param_1;
    puVar8 = *(undefined1 **)(*(longlong *)(param_2 + 0x10) + 0xb8);
    *puVar7 = *puVar8;
    puVar7[1] = puVar8[1];
    puVar7[2] = puVar8[2];
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    uVar14 = *(undefined8 *)(param_2 + 0x188);
    iVar12 = ClassSendSrbAsynchronous(param_1,puVar1,uVar14,0,0,1);
    if (((iVar12 != 0x103) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0 &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,uVar14,iVar12);
    }
  }
  return;
}



===== DiskFlushComplete @ 140001f20 =====

int DiskFlushComplete(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  int iVar11;
  int iVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  undefined *puVar16;
  undefined8 unaff_R13;
  longlong local_res8 [2];
  undefined8 uStack_80;
  undefined1 auStack_78 [32];
  longlong local_48 [4];
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  plVar14 = (longlong *)(lVar1 + 0x70);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_2);
  }
  puVar16 = (undefined *)(lVar1 + 0xa0);
  iVar11 = ClassIoComplete(param_1,param_2);
  puVar15 = auStack_78;
  if ((-1 < iVar11) && (puVar15 = auStack_78, param_3 < 0)) {
    *(int *)(param_2 + 0x30) = param_3;
    puVar15 = auStack_78;
    iVar11 = param_3;
  }
  do {
    plVar13 = (longlong *)*plVar14;
    if (plVar13 != plVar14) goto LAB_14000208c;
    *(undefined8 *)(puVar15 + -8) = 0x140001fc2;
    uVar10 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x1d8);
    if (*(char *)(lVar1 + 0x200) != '\0') {
      *(undefined8 *)(puVar15 + -8) = 0x1400020f7;
      KeReleaseSpinLock(lVar1 + 0x1d8,uVar10);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar15 + -8) = 0x140002149;
        WPP_SF_(uVar5,0x20,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      puVar16 = (undefined *)0x0;
      *(undefined8 *)(puVar15 + -8) = 0x14000211b;
      KeSetEvent(lVar1 + 0x1e0,0);
LAB_14000202a:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(int *)(puVar15 + 0x20) = iVar11;
        *(undefined8 *)(puVar15 + -8) = 0x1400022d8;
        WPP_SF_qD(uVar5,0x23,puVar16,param_2,puVar15[0x20]);
      }
      return iVar11;
    }
    plVar13 = (longlong *)(lVar1 + 0x88);
    while( true ) {
      plVar2 = (longlong *)*plVar13;
      if (plVar2 == plVar13) {
        lVar3 = *(longlong *)(lVar1 + 0x98);
        *(undefined8 *)(puVar15 + 0x88) = unaff_R13;
        *(longlong *)(lVar1 + 0x80) = lVar3;
        *(undefined8 *)(lVar1 + 0x98) = 0;
        *(undefined1 *)(lVar1 + 0x200) = 0;
        if (lVar3 == 0) {
          *(undefined8 *)(puVar15 + -8) = 0x14000201d;
          KeReleaseSpinLock(lVar1 + 0x1d8,uVar10);
          goto LAB_14000202a;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          puVar16 = &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids;
          *(undefined8 *)(puVar15 + -8) = 0x1400021ec;
          WPP_SF_q(uVar5,0x21,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,lVar3);
        }
        *(undefined8 *)(puVar15 + -8) = 0x1400021fe;
        KeReleaseSpinLock(lVar1 + 0x1d8,uVar10);
        *(undefined8 *)(puVar15 + 0x30) = 0;
        *(undefined8 *)(puVar15 + 0x80) = 0;
        *(undefined8 *)(puVar15 + -8) = 0x140002224;
        IoGetStackLimits(puVar15 + 0x80,puVar15 + 0x30);
        if (puVar15 + (0x30 - *(longlong *)(puVar15 + 0x80)) < (undefined1 *)0x3000) {
          *(longlong *)(puVar15 + 0x38) = param_1;
          puVar16 = (undefined *)0x3000;
          *(longlong **)(puVar15 + 0x40) = plVar14;
          *(undefined8 *)(puVar15 + 0x20) = 0;
          *(undefined8 *)(puVar15 + -8) = 0x140002269;
          iVar12 = KeExpandKernelStackAndCalloutEx
                             (DiskFlushDispatchAsyncCallout,puVar15 + 0x38,0x3000,0);
          if (-1 < iVar12) goto LAB_14000202a;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
            puVar16 = &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids;
            *(undefined8 *)(puVar15 + -8) = 0x1400022a9;
            WPP_SF_D(uVar5,0x22,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,iVar12);
          }
        }
        *(undefined8 *)(puVar15 + -8) = 0x1400022b4;
        DiskFlushDispatchAsync(param_1,(longlong)plVar14);
        goto LAB_14000202a;
      }
      if (((longlong *)plVar2[1] != plVar13) ||
         (lVar3 = *plVar2, *(longlong **)(lVar3 + 8) != plVar2)) break;
      *plVar13 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar13;
      puVar4 = *(undefined8 **)(lVar1 + 0x78);
      if ((longlong *)*puVar4 != plVar14) break;
      *plVar2 = (longlong)plVar14;
      plVar2[1] = (longlong)puVar4;
      *puVar4 = plVar2;
      *(longlong **)(lVar1 + 0x78) = plVar2;
    }
    do {
      pcVar6 = (code *)swi(0x29);
      plVar13 = (longlong *)(*pcVar6)(3);
      puVar15 = puVar15 + 8;
LAB_14000208c:
    } while (((longlong *)plVar13[1] != plVar14) ||
            (lVar3 = *plVar13, *(longlong **)(lVar3 + 8) != plVar13));
    *plVar14 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar14;
    plVar13[1] = (longlong)plVar13;
    *plVar13 = (longlong)plVar13;
    uVar7 = *(undefined4 *)(param_2 + 0x34);
    uVar8 = *(undefined4 *)(param_2 + 0x38);
    uVar9 = *(undefined4 *)(param_2 + 0x3c);
    *(undefined4 *)(plVar13 + -0xf) = *(undefined4 *)(param_2 + 0x30);
    *(undefined4 *)((longlong)plVar13 + -0x74) = uVar7;
    *(undefined4 *)(plVar13 + -0xe) = uVar8;
    *(undefined4 *)((longlong)plVar13 + -0x6c) = uVar9;
    *(undefined8 *)(puVar15 + -8) = 0x1400020c6;
    ClassReleaseRemoveLock(param_1,plVar13 + -0x15);
    puVar16 = (undefined *)0x0;
    *(undefined8 *)(puVar15 + -8) = 0x1400020db;
    ClassCompleteRequest(param_1,plVar13 + -0x15);
  } while( true );
}



===== DiskDeviceControl @ 1400022f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskDeviceControl(undefined *param_1,undefined *param_2,undefined8 *param_3)

{
  uint uVar1;
  byte *pbVar2;
  longlong lVar3;
  bool bVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined1 uVar9;
  undefined8 *puVar10;
  undefined *puVar11;
  int iVar12;
  undefined1 auStackY_88 [32];
  undefined1 uVar13;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  pbVar2 = *(byte **)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  local_48 = 0;
  uStack_40 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar1 = *(uint *)(pbVar2 + 0x18);
  uVar9 = SUB81(param_2,0);
  uVar13 = SUB81(param_1,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,param_3,uVar1,uVar13,uVar9);
  }
  if (DiskETWEnabled != '\0') {
    puVar10 = &local_48;
    IoGetActivityIdIrp(param_2);
    if ((DAT_14000c2c1 & 4) != 0) {
      param_3 = &local_48;
      McTemplateK0qpddd_EtwWriteTransfer
                ((ulonglong)*pbVar2,puVar10,param_3,*(undefined4 *)(lVar3 + 0x24c),uVar9,*pbVar2,
                 pbVar2[1],(char)uVar1);
    }
  }
  if ((lVar3 == 0) || (*(longlong *)(lVar3 + 0x208) == 0)) {
LAB_140002381:
    puVar8 = param_1;
    puVar11 = param_2;
    if (uVar1 < 0x7c01d) {
      if (uVar1 == 0x7c01c) {
        uVar5 = DiskIoctlReassignBlocks((longlong)param_1,(longlong)param_2);
      }
      else if (uVar1 < 0x70404) {
        if (uVar1 == 0x70403) {
          uVar7 = DiskIoctlSetVerify((longlong)param_1,(longlong)param_2);
          uVar5 = (uint)uVar7;
        }
        else if (uVar1 == 0x70000) {
          uVar7 = DiskIoctlGetDriveGeometry((longlong)param_1,(longlong)param_2);
          uVar5 = (uint)uVar7;
        }
        else if (uVar1 == 0x70014) {
          uVar7 = DiskIoctlVerify((longlong)param_1,(longlong)param_2);
          uVar5 = (uint)uVar7;
        }
        else if (uVar1 == 0x70024) {
          uVar5 = DiskIoctlIsWritable(param_1,uVar9);
        }
        else {
          if (uVar1 == 0x7008c) goto LAB_140002536;
          if (uVar1 != 0x700a0) goto LAB_1400023d2;
          uVar7 = DiskIoctlGetDriveGeometryEx((longlong)param_1,(longlong)param_2);
          uVar5 = (uint)uVar7;
        }
      }
      else if (uVar1 == 0x70407) {
        uVar7 = DiskIoctlClearVerify((longlong)param_1,(longlong)param_2);
        uVar5 = (uint)uVar7;
      }
      else if (uVar1 == 0x7405c) {
        uVar5 = DiskIoctlGetLengthInfo((longlong)param_1,(longlong)param_2);
      }
      else if (uVar1 == 0x74080) {
        uVar6 = DiskIoctlSmartGetVersion((longlong)param_1,(longlong)param_2);
        uVar5 = (uint)uVar6;
      }
      else if (uVar1 == 0x740d4) {
        uVar6 = DiskIoctlGetCacheInformation((longlong)param_1,(longlong)param_2);
        uVar5 = (uint)uVar6;
      }
      else {
        if (uVar1 != 0x740e0) goto LAB_1400023d2;
        uVar7 = DiskIoctlGetCacheSetting((longlong)param_1,(longlong)param_2);
        uVar5 = (uint)uVar7;
      }
    }
    else if (uVar1 < 0x7c0e5) {
      if (uVar1 == 0x7c0e4) {
        uVar7 = DiskIoctlSetCacheSetting((longlong)param_1,(longlong)param_2);
        uVar5 = (uint)uVar7;
      }
      else if (uVar1 == 0x7c084) {
        uVar5 = DiskIoctlSmartSendDriveCommand((longlong)param_1,(longlong)param_2);
      }
      else if (uVar1 == 0x7c088) {
LAB_140002536:
        uVar5 = DiskIoctlSmartReceiveDriveData((longlong)param_1,(longlong)param_2);
      }
      else if (uVar1 == 0x7c0a4) {
        uVar5 = DiskIoctlReassignBlocksEx((longlong)param_1,(longlong)param_2);
      }
      else if (uVar1 == 0x7c0c8) {
        uVar5 = DiskIoctlUpdateDriveSize((longlong)param_1,(longlong)param_2);
      }
      else {
        if (uVar1 != 0x7c0d8) goto LAB_1400023d2;
        uVar5 = DiskIoctlSetCacheInformation((longlong)param_1,(longlong)param_2);
      }
    }
    else if (uVar1 == 0x2d0c04) {
      uVar6 = DiskIoctlGetMediaTypesEx((longlong)param_1,(ulonglong)param_2);
      uVar5 = (uint)uVar6;
    }
    else if (uVar1 == 0x2d1100) {
      uVar6 = DiskIoctlPredictFailure((longlong)param_1,(longlong)param_2);
      uVar5 = (uint)uVar6;
    }
    else if (uVar1 == 0x2d1104) {
      uVar5 = DiskIoctlEnableFailurePrediction((longlong)param_1,(longlong)param_2);
    }
    else {
      if ((uVar1 != 0x560000) && (uVar1 != 0x564000)) {
LAB_1400023d2:
        uVar6 = ClassDeviceControl(param_1,param_2);
        return uVar6;
      }
      uVar5 = DiskIoctlGetVolumeDiskExtents((longlong)param_1,(longlong)param_2);
    }
    uVar6 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_14000259a;
  }
  else {
    puVar11 = (undefined *)(ulonglong)uVar1;
    bVar4 = DiskIoctlFastFailAtaCommandForNonAtaDevice
                      (*(int *)(*(longlong *)(lVar3 + 0x208) + 0x1c),uVar1);
    if (!bVar4) goto LAB_140002381;
    uVar6 = 0xc00000bb;
    puVar8 = WPP_GLOBAL_Control;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140002482;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      puVar11 = (undefined *)0x12;
      WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,param_3,uVar1,uVar13,uVar9);
    }
LAB_14000259a:
    iVar12 = (int)uVar6;
    puVar8 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar8 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_DqD(puVar8,puVar11,param_3,uVar1,uVar13,(char)uVar6);
    }
    if ((((iVar12 + 0x3fffff5eU < 2) || (iVar12 + 0x3fffffeeU < 3)) ||
        ((iVar12 == -0x7fffffea || (iVar12 == -0x3fffff4b)))) &&
       (*(longlong *)(param_2 + 0x98) != 0)) {
      puVar8 = param_2;
      puVar11 = param_1;
      IoSetHardErrorOrVerifyDevice();
    }
  }
  if ((int)uVar6 == 0x103) {
    return uVar6;
  }
LAB_140002482:
  if ((DiskETWEnabled != '\0') && ((DAT_14000c2c1 & 0x10) != 0)) {
    McTemplateK0qpd_EtwWriteTransfer
              (puVar8,puVar11,&local_48,*(undefined4 *)(lVar3 + 0x24c),uVar9,(char)uVar6);
  }
  *(int *)(param_2 + 0x30) = (int)uVar6;
  ClassReleaseRemoveLock(param_1,param_2);
  ClassCompleteRequest(param_1,param_2,0);
  return uVar6;
}



===== DiskIoctlFastFailAtaCommandForNonAtaDevice @ 1400027c0 =====

bool DiskIoctlFastFailAtaCommandForNonAtaDevice(int param_1,int param_2)

{
  if ((param_1 != 0x11) && (param_1 != 0x14)) {
    return false;
  }
  if (((param_2 == 0x74080) ||
      (((param_2 == 0x7c088 || (param_2 == 0x7008c)) || (param_2 == 0x7c084)))) ||
     (param_2 == 0x4d02c)) {
    return true;
  }
  return param_2 == 0x4d030;
}



===== DiskPostReregisterRequest @ 140002810 =====

undefined8 DiskPostReregisterRequest(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = IoAllocateWorkItem();
  if (lVar1 != 0) {
    lVar2 = ExAllocatePool2(0x40,0x18,0x61446353);
    if (lVar2 != 0) {
      *(undefined8 *)(lVar2 + 8) = param_1;
      *(undefined8 *)(lVar2 + 0x10) = param_2;
      ExInterlockedPushEntryList(&DiskReregHead,lVar2,&DiskReregSpinlock);
      LOCK();
      UNLOCK();
      if (DiskReregWorkItems == 0) {
        DiskReregWorkItems = DiskReregWorkItems + 1;
        IoQueueWorkItem(lVar1,DiskReregWorker,1,lVar1);
      }
      else {
        DiskReregWorkItems = DiskReregWorkItems + 1;
        IoFreeWorkItem();
      }
      return 0;
    }
    IoFreeWorkItem(lVar1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_1);
    }
  }
  return 0xc000009a;
}



===== DiskFdoProcessError @ 140002930 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DiskFdoProcessError(longlong param_1,longlong param_2,int *param_3,undefined1 *param_4)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  longlong lVar7;
  byte *pbVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  char cVar12;
  byte bVar13;
  undefined1 auStackY_88 [32];
  char local_58;
  byte local_57 [7];
  byte *local_50;
  char local_48 [16];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_58 = '\0';
  local_57[0] = 0;
  local_50 = (byte *)0x0;
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
  if (*(char *)(param_2 + 2) == '(') {
    if (((*(int *)(param_2 + 0x14) != 0) || (*(int *)(param_2 + 0x38) == 0)) ||
       (pcVar5 = (char *)GetSrbScsiData(param_2,(undefined1 *)0x0,(undefined4 *)0x0,&local_58,
                                        &local_50,local_57), pbVar8 = local_50, cVar12 = local_58,
       bVar11 = local_57[0], pcVar5 == (char *)0x0)) {
      pcVar5 = local_48;
      pbVar8 = local_50;
      cVar12 = local_58;
      bVar11 = local_57[0];
    }
  }
  else {
    pcVar5 = (char *)(param_2 + 0x48);
    pbVar8 = *(byte **)(param_2 + 0x20);
    cVar12 = *(char *)(param_2 + 4);
    bVar11 = *(byte *)(param_2 + 0xb);
  }
  if (((*param_3 == -0x3fffffc4) && (pcVar5 != (char *)0x0)) && ((*pcVar5 - 8U & 0x5d) == 0)) {
    *param_4 = 1;
    *(int *)(lVar1 + 0x254) = *(int *)(lVar1 + 0x254) + 1;
    return;
  }
  bVar10 = *(byte *)(param_2 + 3) & 0x3f;
  if ((bVar10 == 4) && (cVar12 == '\b')) {
    ResetBus(param_1);
    *(int *)(lVar1 + 0x254) = *(int *)(lVar1 + 0x254) + 1;
    return;
  }
  if (((-1 < (char)*(byte *)(param_2 + 3)) || (pbVar8 == (byte *)0x0)) || (pcVar5 == (char *)0x0)) {
    if (bVar10 != 4) {
      switch(bVar10) {
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xf:
      case 0x11:
      case 0x13:
      case 0x16:
      case 0x20:
      case 0x21:
        goto switchD_140002d0f_caseD_7;
      default:
        return;
      }
    }
    if (cVar12 != '\x18') {
      return;
    }
    goto switchD_140002d0f_caseD_7;
  }
  bVar13 = 0;
  bVar10 = 0;
  bVar9 = 0;
  if (bVar11 == 0) {
    return;
  }
  bVar2 = false;
  if ((byte)((*pbVar8 & 0x7f) + 0x8e) < 2) {
    if (pbVar8 + 8 <= pbVar8 + bVar11) {
      bVar10 = pbVar8[2];
      bVar13 = pbVar8[1] & 0xf;
      bVar9 = pbVar8[3];
      goto LAB_140002a40;
    }
  }
  else if (pbVar8 + 8 <= pbVar8 + bVar11) {
    bVar13 = pbVar8[2] & 0xf;
    uVar4 = (uint)bVar11;
    if (pbVar8[7] + 8 <= (uint)bVar11) {
      uVar4 = pbVar8[7] + 8;
    }
    if (pbVar8 + 0xd <= pbVar8 + uVar4) {
      bVar10 = pbVar8[0xc];
    }
    if (pbVar8 + uVar4 < pbVar8 + 0xe) {
      bVar9 = 0;
    }
    else {
      bVar9 = pbVar8[0xd];
    }
LAB_140002a40:
    bVar2 = true;
  }
  if (!bVar2) {
    return;
  }
  if (bVar13 == 2) {
    if (bVar10 == 4) {
      if (((bVar9 != 0) && (bVar9 != 1)) && (bVar9 != 3)) {
        return;
      }
    }
    else if (bVar10 != 0x3a) {
      return;
    }
  }
  else if (((bVar13 != 1) && (bVar13 != 3)) && (bVar13 != 4)) {
    if (bVar13 == 5) {
      if (bVar10 != 0x24) {
        return;
      }
      cVar12 = *pcVar5;
      if (((cVar12 == '*') || (cVar12 == -0x76)) && ((pcVar5[1] & 8U) != 0)) {
        lVar7 = *(longlong *)(lVar1 + 0x60);
        if (*(int *)(lVar7 + 0x208) == 1) {
          puVar6 = (undefined4 *)IoAllocateErrorLogEntry(*(undefined8 *)(lVar1 + 8),0x40);
          if (puVar6 != (undefined4 *)0x0) {
            puVar6[5] = *param_3;
            puVar6[3] = 0x80040084;
            *(undefined8 *)(puVar6 + 6) = 0;
            *puVar6 = 0x10000f;
            puVar6[4] = 0;
            puVar6[10] = (uint)*(byte *)(lVar7 + 0xc);
            puVar6[0xb] = (uint)*(byte *)(lVar7 + 0xd);
            puVar6[0xc] = (uint)*(byte *)(lVar7 + 0xe);
            puVar6[0xd] = (uint)*(byte *)(lVar7 + 0xf);
            IoWriteErrorLogEntry(puVar6);
          }
        }
        else {
          lVar7 = IoAllocateWorkItem(param_1);
          if (lVar7 != 0) {
            IoQueueWorkItem(lVar7,DisableWriteCache,0,lVar7);
          }
        }
        *(uint *)(lVar1 + 0x36c) = *(uint *)(lVar1 + 0x36c) | 0x80;
        if (((*(ushort *)(lVar1 + 0x280) & 1) == 0) ||
           ((*(ushort *)(lVar1 + 0x280) >> 4 & 1) != 0 || (*(byte *)(lVar1 + 0x36c) & 0x80) != 0)) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
        *(undefined1 *)(lVar1 + 0x283) = uVar3;
        pcVar5[1] = pcVar5[1] & 0xf7;
        *param_4 = 1;
        return;
      }
      if (cVar12 != '\x1a') {
        return;
      }
      if ((pcVar5[2] & 0x3fU) == 0x3f) {
        pcVar5[2] = pcVar5[2] & 200U | 8;
        *param_4 = 1;
        return;
      }
      return;
    }
    if (bVar13 != 6) {
      return;
    }
  }
switchD_140002d0f_caseD_7:
  if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
  }
  return;
}



===== ResetBus @ 140002d20 =====

void ResetBus(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined2 uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  plVar7 = (longlong *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
  }
  plVar5 = (longlong *)ExAllocatePool2(0x40,0xc0,0x63446353);
  if (plVar5 != (longlong *)0x0) {
    *plVar5 = param_1;
    plVar1 = plVar5 + 1;
    if (*(char *)(*(longlong *)(lVar2 + 0x210) + 0x1e) == '\x01') {
      memset((void *)((longlong)plVar5 + 10),0,0xb6);
      *(undefined2 *)plVar1 = 8;
      *(undefined4 *)((longlong)plVar5 + 0x14) = 1;
      *(undefined1 *)((longlong)plVar5 + 10) = 0x28;
      *(undefined4 *)(plVar5 + 2) = 0x53524258;
      *(undefined4 *)(plVar5 + 3) = 0xb8;
      *(undefined4 *)((longlong)plVar5 + 0x1c) = 0x12;
      *(undefined4 *)((longlong)plVar5 + 0x3c) = 0x80;
      *(undefined2 *)(plVar5 + 0x11) = 1;
      *(undefined4 *)((longlong)plVar5 + 0x8c) = 4;
      plVar7 = plVar1;
    }
    else {
      memset((void *)((longlong)plVar5 + 10),0,0x56);
      *(undefined2 *)plVar1 = 0x58;
      *(undefined1 *)((longlong)plVar5 + 10) = 0x12;
    }
    lVar6 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
    if (lVar6 == 0) {
      ExFreePoolWithTag(plVar5,0);
    }
    else {
      ClassAcquireRemoveLockEx(param_1,lVar6,"minkernel\\storage\\disk\\disk.c",0xd9f);
      lVar3 = *(longlong *)(lVar6 + 0xb8);
      *(code **)(lVar3 + -0x10) = ClassAsynchronousCompletion_exref;
      *(longlong **)(lVar3 + -8) = plVar5;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      lVar3 = *(longlong *)(lVar6 + 0xb8);
      *(undefined1 *)(lVar3 + -0x48) = 0xf;
      if (*(char *)(*(longlong *)(lVar2 + 0x210) + 0x1e) == '\x01') {
        uVar4 = IoGetIoPriorityHint(lVar6);
        *(undefined2 *)((longlong)plVar7 + 0x24) = uVar4;
        plVar7[10] = lVar6;
      }
      else {
        plVar5[7] = lVar6;
      }
      *(longlong **)(lVar3 + -0x40) = plVar1;
      IofCallDriver(*(undefined8 *)(lVar2 + 0x10),lVar6);
    }
  }
  return;
}



===== DiskFlushAsyncComplete @ 140002f00 =====

undefined8 DiskFlushAsyncComplete(longlong param_1,longlong param_2,undefined *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(lVar2 + 0x60);
  lVar4 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids;
    lVar4 = 0x24;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  iVar1 = *(int *)(param_2 + 0x30);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20000) != 0)) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar4,param_3,(uint)*(byte *)(lVar3 + 0xa3))
    ;
  }
  if (*(char *)(*(longlong *)(lVar2 + 0x210) + 0x1e) == '\x01') {
    *(undefined4 *)(lVar3 + 0xb4) = 8;
    *(undefined4 *)(lVar3 + 0xd8) = 0;
    *(undefined4 *)(lVar3 + 0x118) = 0;
    *(uint *)(lVar3 + 0xb8) = *(uint *)(lVar3 + 0xb8) | 0x20000000;
    *(undefined8 *)(lVar3 + 0xf0) = *(undefined8 *)(lVar3 + 0x80);
    *(undefined1 *)(lVar3 + 0xa3) = 0;
  }
  else {
    *(undefined1 *)(lVar3 + 0xa2) = 8;
    *(undefined1 *)(lVar3 + 0xaa) = 0;
    *(uint *)(lVar3 + 0xac) = *(uint *)(lVar3 + 0xac) | 0x20000000;
    *(undefined8 *)(lVar3 + 0xd0) = *(undefined8 *)(lVar3 + 0x80);
    *(undefined2 *)(lVar3 + 0xa3) = 0;
    *(undefined8 *)(lVar3 + 0xc0) = 0;
    *(undefined1 *)(lVar3 + 0xab) = 0;
  }
  *(undefined8 *)(*(longlong *)(*(longlong *)(lVar3 + 0x80) + 0xb8) + 0x20) = 0;
  lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x80) + 0xb8);
  *(undefined1 *)(lVar4 + -0x48) = 0xf;
  *(longlong *)(lVar4 + -0x40) = lVar3 + 0xa0;
  lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x80) + 0xb8);
  *(code **)(lVar4 + -0x10) = DiskFlushComplete;
  *(longlong *)(lVar4 + -8) = (longlong)iVar1;
  *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  IofCallDriver(*(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar3 + 0x80));
  return 0xc0000016;
}



===== DiskReadWriteVerification @ 1400030b0 =====

int DiskReadWriteVerification(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar4 = 0;
  uVar5 = *(int *)(*(longlong *)(lVar2 + 0x18) + 0x23c) - 1U & *(uint *)(lVar1 + 8);
  uVar3 = *(int *)(*(longlong *)(lVar2 + 0x18) + 0x23c) - 1U & *(uint *)(lVar1 + 0x18);
  if ((((*(longlong *)(lVar2 + 0x90) < *(longlong *)(lVar1 + 0x18)) ||
       (*(longlong *)(lVar1 + 0x18) < 0)) || (uVar5 != 0)) ||
     ((uVar3 != 0 ||
      ((ulonglong)(*(longlong *)(lVar2 + 0x90) - *(longlong *)(lVar1 + 0x18)) <
       (ulonglong)*(uint *)(lVar1 + 8))))) {
    iVar4 = *(int *)(*(longlong *)(lVar2 + 0x60) + 4);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,(ulonglong)uVar5,iVar4);
      }
      if ((((iVar4 + 0x3fffff5eU < 2) || (iVar4 == -0x3fffff4b)) ||
          ((iVar4 + 0x3fffffeeU < 3 || (iVar4 == -0x7fffffea)))) &&
         (*(longlong *)(param_2 + 0x98) != 0)) {
        IoSetHardErrorOrVerifyDevice(param_2,param_1);
      }
    }
    else if ((uVar5 == 0) && (uVar3 == 0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = -0x3ffffff3;
    }
  }
  *(int *)(param_2 + 0x30) = iVar4;
  return iVar4;
}



===== DiskEnableSmart @ 1400031e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DiskEnableSmart(longlong param_1)

{
  undefined1 auStackY_98 [32];
  uint local_58 [2];
  int local_50 [15];
  undefined1 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58[0] = 0x3d;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_50[8] = 0;
  local_50[9] = 0;
  local_50[10] = 0;
  local_50[0xb] = 0;
  local_50[0xc] = 0;
  local_50[0xd] = 0;
  local_50[0xe] = 0;
  local_14 = 0;
  DiskPerformSmartCommand(param_1,0x1b0504,0xb0,0xd8,0,0,local_50,local_58);
  return;
}



===== WPP_SF_q @ 140003270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== SetSrbScsiData @ 1400032c0 =====

void SetSrbScsiData(longlong param_1,undefined1 param_2,int param_3,undefined8 param_4,
                   undefined8 param_5,undefined1 param_6)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if ((*(char *)(param_1 + 2) == '(') && (*(int *)(param_1 + 0x14) == 0)) {
    uVar6 = 0;
    if (*(uint *)(param_1 + 0x38) != 0) {
      do {
        uVar5 = *(uint *)(param_1 + 0x78 + uVar6 * 4);
        if ((0x7f < uVar5) && (uVar2 = *(uint *)(param_1 + 0x10), uVar5 <= uVar2)) {
          piVar1 = (int *)((ulonglong)uVar5 + param_1);
          uVar4 = (ulonglong)uVar5;
          iVar3 = *piVar1;
          if (iVar3 == 0x40) {
            uVar4 = uVar4 + 0x28;
          }
          else {
            if (iVar3 != 0x41) {
              if ((iVar3 == 0x42) && (uVar4 + 0x28 <= (ulonglong)uVar2)) {
                *(undefined8 *)(piVar1 + 6) = param_5;
                piVar1[3] = param_3;
                goto LAB_14000334d;
              }
              goto LAB_140003371;
            }
            uVar4 = uVar4 + 0x38;
          }
          if (uVar4 <= uVar2) {
            *(undefined8 *)(piVar1 + 4) = param_5;
            *(undefined1 *)((longlong)piVar1 + 10) = param_2;
LAB_14000334d:
            *(undefined1 *)((longlong)piVar1 + 9) = param_6;
            *(undefined1 *)(piVar1 + 2) = 0;
            return;
          }
        }
LAB_140003371:
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < *(uint *)(param_1 + 0x38));
    }
  }
  return;
}



===== WPP_SF_qqddDDq @ 140003390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqddDDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,0x30,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,8,0);
  return;
}



===== WPP_SF_DqL @ 140003450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DqL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_2,local_res20,4,
             &param_5,8,&param_6,4,0);
  return;
}



===== __report_gsfailure @ 1400034d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== DiskFlushDispatchAsyncCallout @ 1400034e0 =====

void DiskFlushDispatchAsyncCallout(longlong *param_1)

{
  DiskFlushDispatchAsync(*param_1,param_1[1]);
  return;
}



===== DiskIoctlClearVerify @ 1400034fc =====

undefined8 DiskIoctlClearVerify(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0xc00000bb;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  if (*(char *)(param_2 + 0x40) == '\0') {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffd;
    uVar1 = 0;
  }
  return uVar1;
}



===== DiskIoctlSetVerify @ 140003578 =====

undefined8 DiskIoctlSetVerify(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0xc00000bb;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  if (*(char *)(param_2 + 0x40) == '\0') {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
    uVar1 = 0;
  }
  return uVar1;
}



===== DiskIoctlVerify @ 1400035f4 =====

undefined8 DiskIoctlVerify(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined2 uVar5;
  undefined8 uVar6;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  plVar3 = *(longlong **)(param_2 + 0x18);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  if (*(uint *)(lVar2 + 0x10) < 0x10) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    return 0xc0000004;
  }
  uVar6 = 0xb8;
  if (*(char *)(*(longlong *)(lVar4 + 0x210) + 0x1e) != '\x01') {
    uVar6 = 0x58;
  }
  lVar2 = ExAllocatePool2(0x40,uVar6,0x53446353);
  if (lVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
LAB_1400036fc:
    uVar6 = 0xc000009a;
  }
  else {
    if ((*(longlong *)(lVar4 + 0x90) < *plVar3) || (*plVar3 < 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
        uVar5 = 0x51;
LAB_14000381b:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
    }
    else {
      if ((ulonglong)*(uint *)(plVar3 + 1) <= (ulonglong)(*(longlong *)(lVar4 + 0x90) - *plVar3)) {
        plVar3 = (longlong *)ExAllocatePool2(0x40,0x18,0x57446353);
        if (plVar3 != (longlong *)0x0) {
          *plVar3 = param_2;
          plVar3[1] = lVar2;
          lVar4 = IoAllocateWorkItem(param_1);
          plVar3[2] = lVar4;
          if (lVar4 != 0) {
            pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
            *pbVar1 = *pbVar1 | 1;
            IoQueueWorkItem(plVar3[2],DiskIoctlVerifyThread,1,plVar3);
            return 0x103;
          }
          ExFreePoolWithTag(plVar3,0);
        }
        ExFreePoolWithTag(lVar2,0);
        goto LAB_1400036fc;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x52;
        goto LAB_14000381b;
      }
    }
    ExFreePoolWithTag(lVar2,0);
    uVar6 = 0xc0000015;
  }
  return uVar6;
}



===== DiskIsManagedZonedDevice @ 140003864 =====

undefined1 DiskIsManagedZonedDevice(longlong param_1)

{
  longlong lVar1;
  
  if (((((*(byte *)(*(longlong *)(param_1 + 0x40) + 0x68) & 1) == 0) ||
       (*(int *)(param_1 + 0x48) != 7)) || ((*(uint *)(param_1 + 0x34) & 4) != 0)) ||
     ((lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x480), lVar1 == 0 ||
      ((*(uint *)(lVar1 + 0x10) & 0xf8000000) != 0xa0000000)))) {
    return 0;
  }
  return 1;
}



===== Feature_2022601018__private_IsEnabledDeviceUsageNoInline @ 1400038a8 =====

ulonglong Feature_2022601018__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2022601018__private_featureState;
  if ((Feature_2022601018__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2022601018__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2022601018__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2022601018__private_IsEnabledFallback @ 1400038e0 =====

void Feature_2022601018__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2022601018__private_descriptor);
  return;
}



===== Feature_Disk_KcsanFix__private_IsEnabledDeviceUsageNoInline @ 1400038fc =====

ulonglong Feature_Disk_KcsanFix__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Disk_KcsanFix__private_featureState;
  if ((Feature_Disk_KcsanFix__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Disk_KcsanFix__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Disk_KcsanFix__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Disk_KcsanFix__private_IsEnabledFallback @ 140003934 =====

void Feature_Disk_KcsanFix__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_Disk_KcsanFix__private_descriptor);
  return;
}



===== GetSrbScsiData @ 140003950 =====

longlong GetSrbScsiData(longlong param_1,undefined1 *param_2,undefined4 *param_3,undefined1 *param_4
                       ,undefined8 *param_5,undefined1 *param_6)

{
  int iVar1;
  bool bVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  
  lVar7 = 0;
  bVar2 = false;
  if ((*(char *)(param_1 + 2) == '(') && (*(int *)(param_1 + 0x14) == 0)) {
    uVar9 = 0;
    if (*(int *)(param_1 + 0x38) != 0) {
      do {
        uVar8 = *(uint *)(param_1 + 0x78 + uVar9 * 4);
        if ((0x7f < uVar8) &&
           (uVar6 = (ulonglong)*(uint *)(param_1 + 0x10), uVar8 <= *(uint *)(param_1 + 0x10))) {
          uVar5 = (ulonglong)uVar8;
          iVar1 = *(int *)((ulonglong)uVar8 + param_1);
          if (iVar1 == 0x40) {
            if (uVar5 + 0x28 <= uVar6) {
              if (param_2 != (undefined1 *)0x0) {
                *param_2 = *(undefined1 *)(uVar5 + 10 + param_1);
              }
              lVar4 = param_1 + 0x18 + uVar5;
              if (*(char *)(uVar5 + 10 + param_1) == '\0') {
                lVar4 = lVar7;
              }
              if (param_4 != (undefined1 *)0x0) {
                *param_4 = *(undefined1 *)(uVar5 + 8 + param_1);
              }
              if (param_5 == (undefined8 *)0x0) goto LAB_140003a24;
              uVar3 = *(undefined8 *)(uVar5 + 0x10 + param_1);
LAB_140003a21:
              *param_5 = uVar3;
LAB_140003a24:
              if (param_6 == (undefined1 *)0x0) {
                return lVar4;
              }
              *param_6 = *(undefined1 *)(uVar5 + 9 + param_1);
              return lVar4;
            }
          }
          else if (iVar1 == 0x41) {
            if (uVar5 + 0x38 <= uVar6) {
              bVar2 = true;
              if (param_2 != (undefined1 *)0x0) {
                *param_2 = *(undefined1 *)(uVar5 + 10 + param_1);
              }
              lVar4 = param_1 + 0x18 + uVar5;
              if (*(char *)(uVar5 + 10 + param_1) == '\0') {
                lVar4 = lVar7;
              }
              if (param_4 != (undefined1 *)0x0) {
                *param_4 = *(undefined1 *)(uVar5 + 8 + param_1);
              }
              if (param_5 != (undefined8 *)0x0) {
                *param_5 = *(undefined8 *)(uVar5 + 0x10 + param_1);
              }
              if (param_6 == (undefined1 *)0x0) {
                return lVar4;
              }
              *param_6 = *(undefined1 *)(uVar5 + 9 + param_1);
              lVar7 = lVar4;
            }
          }
          else if ((iVar1 == 0x42) && (uVar5 + 0x28 <= uVar6)) {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = *(undefined4 *)(uVar5 + 0xc + param_1);
            }
            lVar4 = param_1 + 0x20 + uVar5;
            if (*(int *)(uVar5 + 0xc + param_1) == 0) {
              lVar4 = lVar7;
            }
            if (param_4 != (undefined1 *)0x0) {
              *param_4 = *(undefined1 *)(uVar5 + 8 + param_1);
            }
            if (param_5 == (undefined8 *)0x0) goto LAB_140003a24;
            uVar3 = *(undefined8 *)(uVar5 + 0x18 + param_1);
            goto LAB_140003a21;
          }
          if (bVar2) {
            return lVar7;
          }
        }
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
      } while (uVar8 < *(uint *)(param_1 + 0x38));
    }
  }
  else {
    if (param_2 != (undefined1 *)0x0) {
      *param_2 = 0;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
    if (param_4 != (undefined1 *)0x0) {
      *param_4 = 0;
    }
    if (param_5 != (undefined8 *)0x0) {
      *param_5 = 0;
    }
    if (param_6 != (undefined1 *)0x0) {
      *param_6 = 0;
    }
  }
  return lVar7;
}



===== McGenControlCallbackV2 @ 140003b50 =====

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
  
  if (param_7 == 0) {
    return;
  }
  if (param_2 == 0) {
    *(undefined4 *)(param_7 + 0x24) = 0;
    *(undefined1 *)(param_7 + 0x28) = 0;
    *(undefined8 *)(param_7 + 0x10) = 0;
    *(undefined8 *)(param_7 + 0x18) = 0;
    if (*(ushort *)(param_7 + 0x2a) != 0) {
      memset(*(void **)(param_7 + 0x30),0,
             (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
    }
LAB_140003c62:
    DiskETWEnabled = 0;
  }
  else {
    if (param_2 == 1) {
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
    else if (param_2 == 0) goto LAB_140003c62;
    DiskETWEnabled = 1;
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 140003c78 =====

void McGenEventRegister_EtwRegister(void)

{
  if (DiskEventProvider_Context == 0) {
    EtwRegister(&DiskEventProvider,McGenControlCallbackV2,&DiskEventProvider_Context,
                &DiskEventProvider_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140003cb8 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (DiskEventProvider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    DiskEventProvider_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140003cec =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000c008;
  uVar2 = 0;
  if (DAT_14000c008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000c008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(DiskEventProvider_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0qpd_EtwWriteTransfer @ 140003d50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qpd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_30 = 8;
  local_48 = local_res20;
  local_40 = 4;
  local_38 = &param_5;
  local_20 = 4;
  local_28 = &param_6;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EventNonReadWriteRequestComplete,param_3,4,local_58);
  return;
}



===== McTemplateK0qpddd_EtwWriteTransfer @ 140003dd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qpddd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = local_res20;
  local_60 = 4;
  local_58 = &param_5;
  local_50 = 8;
  local_48 = &param_6;
  local_40 = 4;
  local_38 = &param_7;
  local_28 = &param_8;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EventIOCTL,param_3,6,local_78);
  return;
}



===== McTemplateK0qpduuuuu_EtwWriteTransfer @ 140003e78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qpduuuuu_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_108 [32];
  undefined1 local_d8 [8];
  undefined1 local_d0 [8];
  undefined1 local_c8 [8];
  undefined1 local_c0 [8];
  undefined1 local_b8 [16];
  undefined8 local_a8 [2];
  undefined4 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  local_90 = 4;
  local_98 = local_res20;
  local_b8[0] = 0;
  local_88 = &param_5;
  local_78 = &param_6;
  local_68 = local_d8;
  local_c0[0] = 0;
  local_58 = local_d0;
  local_48 = local_c8;
  local_38 = local_c0;
  local_28 = local_b8;
  local_c8[0] = 0;
  local_d0[0] = 0;
  local_d8[0] = 0;
  local_80 = 8;
  local_70 = 4;
  local_60 = 1;
  local_50 = 1;
  local_40 = 1;
  local_30 = 1;
  local_20 = 1;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EventIORequestComplete,param_3,9,local_a8);
  return;
}



===== McTemplateK0qpuxi_EtwWriteTransfer @ 140003f6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qpuxi_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_b8 [32];
  undefined1 local_88 [16];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68 = local_res20;
  local_88[0] = 0x28;
  local_58 = &param_5;
  local_60 = 4;
  local_48 = local_88;
  local_50 = 8;
  local_38 = &param_7;
  local_28 = &param_8;
  local_40 = 1;
  local_30 = 8;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EventReadRequest,param_3,6,local_78);
  return;
}



===== McTemplateK0uuuuuhhhhq_EtwWriteTransfer @ 140004018 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0uuuuuhhhhq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13)

{
  undefined1 local_res20 [8];
  undefined1 auStackY_f8 [32];
  undefined8 local_c8 [2];
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_b8 = local_res20;
  local_b0 = 1;
  local_a8 = &param_5;
  local_a0 = 1;
  local_98 = &param_6;
  local_90 = 1;
  local_88 = &param_7;
  local_80 = 1;
  local_78 = &param_8;
  local_68 = &param_9;
  local_58 = &param_10;
  local_48 = &param_11;
  local_38 = &param_12;
  local_28 = &param_13;
  local_70 = 1;
  local_60 = 2;
  local_50 = 2;
  local_40 = 2;
  local_30 = 2;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&DiskCacheInfo,0,0xb,local_c8);
  return;
}



===== RtlStringCchPrintfW @ 140004118 =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== WPP_SF_ @ 140004194 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 1400041c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DqD @ 140004204 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,0x13,local_res20,4,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_Dqq @ 14000426c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_2,local_res20,4,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_L @ 1400042d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_d @ 14000431c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,0x25,local_res20,4,0);
  return;
}



===== WPP_SF_dqL @ 140004368 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dqL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,0x28,local_res20,4,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qD @ 1400043d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qq @ 140004428 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_s @ 140004478 =====

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
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar2,0);
  return;
}



===== WPP_SF_sq @ 1400044dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sq(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
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
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar2,&param_5,8,0);
  return;
}



===== WPP_SF_ss @ 140004554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ss(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_5[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,0xf,param_4,lVar1,param_5
             ,lVar3,0);
  return;
}



===== WPP_SF_sss @ 1400045f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sss(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,char *param_5
               ,char *param_6)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  if (param_6 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_6[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_5[lVar1] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  lVar1 = -1;
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
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
            (param_1,0x2b,&WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,0x10,param_4,lVar2,
             param_5,lVar3,param_6,lVar4,0);
  return;
}



===== WppClassicProviderCallback @ 1400046e0 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140004714 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000b2c7 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14000473c =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140004814 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400048f8 =====

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
LAB_140004a50:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140004a43:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140004a50;
      if (uVar5 == 5) goto LAB_140004a43;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140004a78 =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140004afc =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140004bec =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140004cfc =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140004d60 =====

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



===== wil_details_IsEnabledFallback @ 140004ec0 =====

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



===== wil_details_MapReportingKind @ 140004f54 =====

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



===== wil_details_RecordCachedUsage @ 140004ff4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005150 =====

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



===== DiskExecuteSmartDiagnostics @ 1400051d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DiskExecuteSmartDiagnostics(longlong param_1,undefined1 param_2)

{
  undefined1 auStackY_98 [32];
  uint local_58 [2];
  int local_50 [15];
  undefined1 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58[0] = 0x3d;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_50[8] = 0;
  local_50[9] = 0;
  local_50[10] = 0;
  local_50[0xb] = 0;
  local_50[0xc] = 0;
  local_50[0xd] = 0;
  local_50[0xe] = 0;
  local_14 = 0;
  DiskPerformSmartCommand(param_1,0x1b0509,0xb0,0xd4,0,param_2,local_50,local_58);
  return;
}



===== DiskFdoQueryWmiRegInfoEx @ 140005260 =====

void DiskFdoQueryWmiRegInfoEx(longlong param_1,undefined4 *param_2)

{
  DiskFdoQueryWmiRegInfo(param_1,param_2);
  return;
}



===== DiskInfoExceptionCheck @ 140005278 =====

undefined8 DiskInfoExceptionCheck(longlong param_1)

{
  char cVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  longlong lVar5;
  undefined2 *puVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined4 uVar10;
  undefined2 *puVar11;
  byte *pbVar12;
  
  lVar5 = ExAllocatePool2(0x48,0xc0,0x41446353);
  if (lVar5 == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000009a;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0) {
      return 0xc000009a;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return 0xc000009a;
    }
    uVar3 = 0x1c;
  }
  else {
    uVar10 = 0xb8;
    if (*(char *)(*(longlong *)(param_1 + 0x210) + 0x1e) != '\x01') {
      uVar10 = 0x58;
    }
    puVar6 = (undefined2 *)ExAllocatePool2(0x40,uVar10,0x53446353);
    if (puVar6 == (undefined2 *)0x0) {
      ExFreePoolWithTag(lVar5,0);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0) {
        return 0xc000009a;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
        return 0xc000009a;
      }
      uVar3 = 0x1d;
    }
    else {
      lVar7 = ExAllocatePool2(0x48,0x12,0x37436353);
      if (lVar7 == 0) {
        ExFreePoolWithTag(puVar6);
        ExFreePoolWithTag(lVar5,0);
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000009a;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0) {
          return 0xc000009a;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
          return 0xc000009a;
        }
        uVar3 = 0x1e;
      }
      else {
        lVar8 = IoAllocateIrp(*(char *)(*(longlong *)(param_1 + 0x10) + 0x4c) + '\x01',0);
        if (lVar8 == 0) {
          ExFreePoolWithTag(lVar7,0);
          ExFreePoolWithTag(puVar6,0);
          ExFreePoolWithTag(lVar5,0);
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0xc000009a;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0) {
            return 0xc000009a;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
            return 0xc000009a;
          }
          uVar3 = 0x1f;
        }
        else {
          iVar4 = ClassAcquireRemoveLockEx
                            (*(undefined8 *)(param_1 + 8),lVar8,
                             "minkernel\\storage\\disk\\diskwmi.c",0x826);
          if (iVar4 != 0) {
            ClassReleaseRemoveLock(*(undefined8 *)(param_1 + 8),lVar8);
            IoFreeIrp(lVar8);
            ExFreePoolWithTag(lVar7,0);
            ExFreePoolWithTag(puVar6,0);
            ExFreePoolWithTag(lVar5,0);
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                      &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids);
            }
            return 0xc00000c0;
          }
          lVar9 = *(longlong *)(lVar8 + 0xb8);
          *(char *)(lVar8 + 0x43) = *(char *)(lVar8 + 0x43) + -1;
          *(longlong *)(lVar8 + 0xb8) = lVar9 + -0x48;
          *(undefined8 *)(lVar9 + -0x20) = *(undefined8 *)(param_1 + 8);
          *(undefined8 *)(lVar9 + -0x28) = 4;
          *(longlong *)(lVar9 + -0x30) = lVar7;
          lVar9 = *(longlong *)(lVar8 + 0xb8);
          *(undefined1 *)(lVar9 + -0x48) = 0xf;
          *(undefined2 **)(lVar9 + -0x40) = puVar6;
          lVar9 = *(longlong *)(lVar8 + 0xb8);
          *(code **)(lVar9 + -0x10) = DiskInfoExceptionComplete;
          *(undefined2 **)(lVar9 + -8) = puVar6;
          *(undefined1 *)(lVar9 + -0x45) = 0xe0;
          lVar9 = IoAllocateMdl(lVar5,0xc0,0,0,lVar8);
          *(longlong *)(lVar8 + 8) = lVar9;
          if (lVar9 != 0) {
            MmBuildMdlForNonPagedPool(lVar9);
            if (*(char *)(*(longlong *)(param_1 + 0x210) + 0x1e) == '\x01') {
              *(undefined4 *)(puVar6 + 10) = 0;
              *puVar6 = 8;
              *(undefined1 *)(puVar6 + 1) = 0x28;
              *(undefined4 *)(puVar6 + 4) = 0x53524258;
              *(undefined4 *)(puVar6 + 6) = 1;
              *(undefined4 *)(puVar6 + 8) = uVar10;
              uVar3 = IoGetIoPriorityHint(lVar8);
              puVar6[0x12] = uVar3;
              *(undefined4 *)(puVar6 + 0x1a) = 0x80;
              *(undefined4 *)(puVar6 + 0x1c) = 1;
              *(undefined4 *)(puVar6 + 0x14) = *(undefined4 *)(param_1 + 0x248);
              *(undefined4 *)(puVar6 + 0x1e) = 0xc0;
              *(longlong *)(puVar6 + 0x20) = lVar5;
              uVar2 = *(uint *)(param_1 + 0x250);
              *(undefined4 *)(puVar6 + 0x10) = 0xff;
              *(uint *)(puVar6 + 0xc) = uVar2 | 0x148;
              puVar6[0x13] = 0x20;
              *(longlong *)(puVar6 + 0x28) = lVar8;
              puVar6[0x40] = 1;
              *(undefined4 *)(puVar6 + 0x42) = 4;
              *(undefined4 *)(puVar6 + 0x3c) = 0x90;
              if (*(uint *)(puVar6 + 8) < 0xb8) {
                ClassReleaseRemoveLock(*(undefined8 *)(param_1 + 8),lVar8);
                ExFreePoolWithTag(puVar6,0);
                ExFreePoolWithTag(lVar5,0);
                ExFreePoolWithTag(lVar7,0);
                IoFreeIrp(lVar8);
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
                   (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                          &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids);
                }
                return 0xc00000e5;
              }
              *(undefined4 *)(puVar6 + 0x48) = 0x40;
              puVar11 = puVar6 + 0x54;
              *(undefined4 *)(puVar6 + 0x4a) = 0x20;
              pbVar12 = (byte *)(puVar6 + 0x55);
              *(undefined2 *)((longlong)puVar6 + 0x99) = 0x612;
              *(longlong *)(puVar6 + 0x50) = lVar7;
            }
            else {
              *puVar6 = 0x58;
              puVar11 = puVar6 + 0x24;
              *(undefined1 *)(puVar6 + 1) = 0;
              pbVar12 = (byte *)(puVar6 + 0x25);
              *(undefined1 *)((longlong)puVar6 + 0xb) = 0x12;
              *(longlong *)(puVar6 + 0x10) = lVar7;
              *(undefined4 *)(puVar6 + 10) = *(undefined4 *)(param_1 + 0x248);
              *(undefined4 *)(puVar6 + 8) = 0xc0;
              *(longlong *)(puVar6 + 0xc) = lVar5;
              uVar2 = *(uint *)(param_1 + 0x250);
              puVar6[4] = 0x20ff;
              *(uint *)(puVar6 + 6) = uVar2 | 0x148;
              *(longlong *)(puVar6 + 0x18) = lVar8;
              *(undefined1 *)(puVar6 + 5) = 6;
            }
            cVar1 = *(char *)(*(longlong *)(param_1 + 0x480) + 0x26);
            *pbVar12 = *pbVar12 & 0xdc | 0x1c;
            if (cVar1 == '\0') {
              *(undefined1 *)puVar11 = 0x1a;
              *(undefined1 *)(puVar11 + 2) = 0xc0;
            }
            else {
              *(undefined1 *)puVar11 = 0x5a;
              *(undefined1 *)(puVar11 + 4) = 0xc0;
              *(undefined1 *)(puVar6 + 5) = 10;
            }
            pbVar12 = (byte *)(*(longlong *)(lVar8 + 0xb8) + 3);
            *pbVar12 = *pbVar12 | 1;
            IofCallDriver(*(undefined8 *)(param_1 + 0x10),lVar8);
            return 0x103;
          }
          ClassReleaseRemoveLock(*(undefined8 *)(param_1 + 8),lVar8);
          ExFreePoolWithTag(puVar6,0);
          ExFreePoolWithTag(lVar5,0);
          ExFreePoolWithTag(lVar7,0);
          IoFreeIrp(lVar8);
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0xc000009a;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0) {
            return 0xc000009a;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
            return 0xc000009a;
          }
          uVar3 = 0x21;
        }
      }
    }
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
          &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids);
  return 0xc000009a;
}



===== DiskInfoExceptionComplete @ 140005880 =====

undefined8 DiskInfoExceptionComplete(longlong param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  bool bVar4;
  byte bVar5;
  char cVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined2 uVar9;
  byte bVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 local_res8 [8];
  undefined1 local_res10 [8];
  int local_res18 [2];
  undefined4 local_res20 [2];
  byte local_88;
  int local_84 [3];
  longlong local_78;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  
  local_60 = *(longlong *)(param_1 + 0x40);
  puVar3 = *(undefined1 **)(param_2 + 0xb8);
  bVar10 = *(byte *)(param_3 + 3) & 0x3f;
  lVar11 = *(longlong *)(local_60 + 0x60);
  lVar12 = 0;
  local_res18[0] = 0;
  local_84[1] = 0;
  local_58 = *(longlong *)(puVar3 + 0x18);
  local_88 = 1;
  bVar5 = local_88;
  local_88 = 1;
  local_70 = 0;
  local_68 = 0;
  local_res10[0] = 0;
  local_84[0] = 0;
  local_res8[0] = 0;
  if (*(char *)(param_3 + 2) == '(') {
    local_78 = *(longlong *)(param_3 + 0x40);
    local_res20[0] = *(undefined4 *)(param_3 + 0x3c);
    lVar12 = param_3;
    if ((*(int *)(param_3 + 0x14) == 0) && (*(int *)(param_3 + 0x38) != 0)) {
      GetSrbScsiData(param_3,local_res10,local_84,(undefined1 *)0x0,&local_68,local_res8);
      local_70 = local_68;
    }
  }
  else {
    local_res20[0] = *(undefined4 *)(param_3 + 0x10);
    local_78 = *(longlong *)(param_3 + 0x18);
    local_70 = *(longlong *)(param_3 + 0x20);
  }
  if ((bVar10 == 1) || (bVar10 == 0x12)) {
    local_res18[0] = ClassModeSenseTranslate(param_1,local_78,local_res20);
    lVar12 = local_78;
    if (local_res18[0] < 0) goto LAB_140005d3d;
    lVar7 = ClassFindModePage(local_78,local_res20[0],0x1c,1);
    uVar8 = Feature_2022601018__private_IsEnabledDeviceUsageNoInline();
    local_88 = bVar5;
    if ((int)uVar8 == 0) {
      if (lVar7 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x1b;
          goto LAB_140005d18;
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                   &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_1);
        }
        *(undefined1 *)(lVar11 + 0x15) = 1;
        if (((*(byte *)(lVar7 + 2) & 8) == 0) && ((byte)((*(byte *)(lVar7 + 3) & 0xf) - 2) < 5)) {
          *(undefined4 *)(lVar11 + 0x10) = 3;
          *(undefined1 *)(lVar11 + 0x16) = 1;
          uVar8 = DiskPostReregisterRequest(param_1,param_2);
          local_88 = (byte)(uVar8 >> 0x1f) & 1;
        }
        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
                (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x1a;
          goto LAB_140005d18;
        }
      }
    }
    else if ((lVar7 == 0) || ((ulonglong)*(byte *)(lVar7 + 1) + 2 < 4)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0 &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])))) {
        uVar9 = 0x18;
LAB_140005d18:
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                 &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_1);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_1);
      }
      *(undefined1 *)(lVar11 + 0x15) = 1;
      if (((*(byte *)(lVar7 + 2) & 8) == 0) && ((byte)((*(byte *)(lVar7 + 3) & 0xf) - 2) < 5)) {
        *(undefined4 *)(lVar11 + 0x10) = 3;
        *(undefined1 *)(lVar11 + 0x16) = 1;
        uVar8 = DiskPostReregisterRequest(param_1,param_2);
        local_88 = (byte)(uVar8 >> 0x1f) & 1;
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar9 = 0x17;
        goto LAB_140005d18;
      }
    }
    local_res18[0] = 0;
    goto LAB_140005d3d;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_2,(char)param_3);
  }
  if ((*(byte *)(param_3 + 3) & 0x40) != 0) {
    ClassReleaseQueue(param_1);
  }
  lVar11 = 0;
  cVar6 = ClassInterpretSenseInfo
                    (param_1,param_3,*puVar3,0,4 - *(int *)(puVar3 + 0x20),local_res18,local_84 + 1)
  ;
  if (((puVar3[2] & 2) == 0) || (local_res18[0] != -0x7fffffea)) {
    if (cVar6 != '\0') goto LAB_140005a15;
LAB_140005a1e:
    bVar4 = false;
  }
  else {
    local_res18[0] = -0x3ffffe7b;
LAB_140005a15:
    bVar4 = true;
    if (*(longlong *)(puVar3 + 0x20) == 0) goto LAB_140005a1e;
  }
  *(longlong *)(puVar3 + 0x20) = *(longlong *)(puVar3 + 0x20) + -1;
  if (bVar4) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      lVar11 = param_2;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_2);
    }
    uVar2 = *(undefined4 *)(*(longlong *)(param_2 + 8) + 0x28);
    if (*(char *)(param_3 + 2) == '(') {
      *(undefined4 *)(lVar12 + 0x3c) = uVar2;
      *(undefined1 *)(lVar12 + 3) = 0;
      if ((*(int *)(lVar12 + 0x14) == 0) && (*(int *)(lVar12 + 0x38) != 0)) {
        SetSrbScsiData(lVar12,local_res10[0],local_84[0],lVar11,local_70,local_res8[0]);
      }
      *(undefined2 *)(lVar12 + 0x26) = 0x20;
      *(undefined4 *)(lVar12 + 0x20) = 0xff;
      *(uint *)(lVar12 + 0x18) = *(uint *)(lVar12 + 0x18) & 0xfffffffd | 0xc;
    }
    else {
      *(undefined2 *)(param_3 + 3) = 0;
      *(undefined4 *)(param_3 + 0x10) = uVar2;
      *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xfffffffd | 0xc;
      *(undefined2 *)(param_3 + 8) = 0x20ff;
    }
    puVar3[-0x48] = 0xf;
    *(longlong *)(puVar3 + -0x40) = param_3;
    lVar11 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar11 + -0x10) = DiskInfoExceptionComplete;
    *(longlong *)(lVar11 + -8) = param_3;
    *(undefined1 *)(lVar11 + -0x45) = 0xe0;
    IofCallDriver(*(undefined8 *)(local_60 + 0x10),param_2);
    return 0xc0000016;
  }
  lVar12 = local_78;
LAB_140005d3d:
  lVar11 = local_70;
  if ((local_70 != local_58) && (local_58 != 0)) {
    ExFreePoolWithTag(local_58,0);
  }
  if (lVar11 != 0) {
    ExFreePoolWithTag(lVar11,0);
  }
  if (lVar12 != 0) {
    ExFreePoolWithTag(lVar12,0);
  }
  ExFreePoolWithTag(param_3,0);
  if (local_88 != 0) {
    *(int *)(param_2 + 0x30) = local_res18[0];
    if (*(char *)(param_2 + 0x41) != '\0') {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
    }
    ClassReleaseRemoveLock(param_1,param_2);
    IoFreeMdl(*(undefined8 *)(param_2 + 8));
    IoFreeIrp(param_2);
  }
  return 0xc0000016;
}



===== WPP_SF_DDqL @ 140005e0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDqL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,0x33,local_res20,4,
             &param_5,4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_dd @ 140005e80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1)

{
  undefined1 uStack0000000000000028;
  undefined4 local_18 [6];
  
  local_18[0] = 0x1c;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,0xb,local_18,4,
             &uStack0000000000000028,4,0);
  return;
}



===== WPP_SF_qL @ 140005edc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,0x35,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qqL @ 140005f38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qqdDq @ 140005fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,0x2c,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_SF_qqdLq @ 140006028 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdLq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,0x2a,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_SF_qqddDq @ 1400060b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqddDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,0x2e,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,&param_8,4,&param_9,8,0);
  return;
}



===== WPP_SF_qqds @ 140006144 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqds(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,char *param_7)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 local_res20;
  
  if (param_7 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_7[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_7;
  if (param_7 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,pcVar3,lVar2,0);
  return;
}



===== WPP_SF_qqsL @ 1400061fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqsL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 local_res20;
  
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_6[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,0x28,&local_res20,8,
             &param_5,8,pcVar3,lVar2,&param_7,4,0);
  return;
}



===== WPP_SF_qs @ 1400062b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qs(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_res20;
  
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,param_2,&local_res20,8,
             param_5,lVar2,0);
  return;
}



===== WPP_SF_sqL @ 14000633c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqL(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

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
            (param_1,0x2b,&WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,10,param_4,lVar2,&param_5
             ,8,&param_6,4,0);
  return;
}



===== DiskStopDevice @ 1400063e0 =====

undefined8 DiskStopDevice(void)

{
  return 0;
}



===== RtlStringCbPrintfW @ 1400063ec =====

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



===== RtlStringCchPrintfA @ 140006468 =====

undefined8 RtlStringCchPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

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



===== WPP_SF_Lq @ 1400064dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Lq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,10,local_res20,4,&param_5
             ,8,0);
  return;
}



===== WPP_SF_Lqq @ 140006538 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Lqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,param_2,local_res20,4,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_ZD @ 1400065a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZD(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

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
      goto LAB_1400065c9;
    }
  }
  pwVar2 = L"NULL";
LAB_1400065c9:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,param_2,param_4,2,pwVar2,
             wVar1,&param_5,4,0);
  return;
}



===== WPP_SF_ZZ @ 140006634 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  wchar_t wVar4;
  
  pwVar2 = L"NULL";
  wVar4 = L'\b';
  if (param_5 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_14000667d;
    }
  }
  pwVar1 = L"NULL";
LAB_14000667d:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  if ((param_4 != (wchar_t *)0x0) && (wVar4 = *param_4, *param_4 != L'\0')) {
    pwVar2 = *(wchar_t **)(param_4 + 4);
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,param_2,param_4,2,pwVar2,
             wVar4,param_5,2,pwVar1,wVar3,0);
  return;
}



===== _guard_check_icall @ 140006720 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140006738 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000675c =====

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



===== __cpu_features_init @ 1400067d0 =====

/* WARNING: Removing unreachable block (ram,0x00014000683a) */
/* WARNING: Removing unreachable block (ram,0x0001400067e9) */
/* WARNING: Removing unreachable block (ram,0x0001400067da) */

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



===== __security_check_cookie @ 1400068a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400068e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140006910 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140006910. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140006940 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1400069c0 =====

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



===== memset @ 140006cc0 =====

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



===== __memset_repmovs @ 140006e00 =====

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



===== __memset_query @ 140006e80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140006f00 =====

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



===== __memset_spec_ermsb_repmovsb @ 140007040 =====

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



===== __memset_spec_plain @ 1400070c0 =====

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



===== DiskSetInfoExceptionInformation @ 140010010 =====

int DiskSetInfoExceptionInformation(longlong param_1,void *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  
  lVar3 = 2;
  do {
    lVar2 = lVar3;
    iVar1 = DiskModeSelect(*(longlong *)(param_1 + 8),param_2,0xc,1);
    lVar3 = lVar2 + -1;
  } while (lVar3 != 0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    pcVar4 = "succeeded";
    if (iVar1 < 0) {
      pcVar4 = "failed";
    }
    WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)lVar2 + 0x31,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,pcVar4,
              (char)*(undefined8 *)(param_1 + 8));
  }
  return iVar1;
}



===== DisableWriteCache @ 1400100c0 =====

void DisableWriteCache(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 local_28 [8];
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_28 = (undefined1  [8])0x0;
  uStack_20 = 0;
  local_18 = 0;
  uVar2 = DiskGetCacheInformation(lVar1,local_28);
  if ((-1 < (int)uVar2) && (local_28[2] == '\x01')) {
    local_28[2] = 0;
    DiskSetCacheInformation(lVar1,local_28);
  }
  IoFreeWorkItem(param_2);
  return;
}



===== DiskCreateFdo @ 14001012c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskCreateFdo(undefined8 param_1,undefined8 param_2,uint *param_3,char param_4)

{
  ushort *puVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  char *pcVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  undefined1 auStack_158 [32];
  longlong *local_138;
  longlong local_128;
  undefined8 local_120;
  char *local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 *local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  ulonglong uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  wchar_t local_c8 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_158;
  local_118 = (char *)0x0;
  uVar5 = 0;
  local_120 = 0;
  local_128 = 0;
  *param_3 = 0;
  while( true ) {
    memset(local_c8,0,0x80);
    local_f0 = 0;
    uStack_e8 = uStack_e8 & 0xffffffff00000000;
    local_e0 = 0;
    uStack_d8 = 0;
    local_110 = 0;
    uStack_108 = 0;
    local_100 = (undefined8 *)0x0;
    uStack_f8 = 0;
    uVar6 = RtlStringCchPrintfW(local_c8,0x3f,L"\\Device\\Harddisk%d",(ulonglong)uVar5);
    uVar10 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) break;
    RtlInitUnicodeString(&local_e0,local_c8);
    local_100 = &local_e0;
    local_110 = CONCAT44(local_110._4_4_,0x30);
    puVar11 = &local_110;
    uStack_108 = 0;
    uStack_f8 = CONCAT44(uStack_f8._4_4_,0x250);
    local_f0 = 0;
    uStack_e8 = 0;
    uVar4 = ZwCreateDirectoryObject(&local_120);
    uVar6 = (ulonglong)uVar4;
    uVar2 = *param_3;
    uVar5 = uVar2 + 1;
    *param_3 = uVar5;
    if ((uVar4 != 0xc0000035) && (uVar4 != 0x40000000)) {
      if ((int)uVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,puVar11,uVar4);
        }
      }
      else {
        *param_3 = uVar2;
        lVar7 = IoGetAttachedDeviceReference(param_2);
        uVar5 = ClassClaimDevice(lVar7,0);
        uVar6 = (ulonglong)uVar5;
        if (-1 < (int)uVar5) {
          uVar6 = DiskGenerateDeviceName(*param_3,(longlong *)&local_118);
          pcVar9 = local_118;
          uVar10 = uVar6 & 0xffffffff;
          if ((int)uVar6 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,WPP_GLOBAL_Control,(int)uVar6)
              ;
            }
            pcVar9 = local_118;
          }
          else {
            local_138 = &local_128;
            uVar5 = ClassCreateDeviceObject(param_1,local_118,param_2,1);
            uVar10 = (ulonglong)uVar5;
            if ((int)uVar5 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                         &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,pcVar9);
              }
            }
            else {
              if (pcVar9 != (char *)0x0) {
                ExFreePoolWithTag(pcVar9,0);
                pcVar9 = (char *)0x0;
              }
              *(uint *)(local_128 + 0x30) = *(uint *)(local_128 + 0x30) | 0x10;
              lVar3 = *(longlong *)(local_128 + 0x40);
              if (param_4 != '\0') {
                puVar1 = (ushort *)(*(longlong *)(local_128 + 0x38) + 4);
                *puVar1 = *puVar1 | 0x10;
              }
              *(undefined4 *)(lVar3 + 600) = 0;
              *(uint *)(lVar3 + 0x24c) = *param_3;
              if (*(uint *)(local_128 + 0x98) < *(uint *)(lVar7 + 0x98)) {
                *(uint *)(local_128 + 0x98) = *(uint *)(lVar7 + 0x98);
              }
              *(undefined8 *)(lVar3 + 0x200) = param_2;
              lVar8 = IoAttachDeviceToDeviceStack(local_128,param_2);
              *(longlong *)(lVar3 + 0x10) = lVar8;
              if (lVar8 != 0) {
                *(uint *)(local_128 + 0x30) = *(uint *)(local_128 + 0x30) & 0xffffff7f;
                *(undefined8 *)(lVar3 + 0x2c0) = local_120;
                ObfDereferenceObject(lVar7);
                return 0;
              }
              uVar10 = 0xc0000001;
            }
          }
          if (local_128 != 0) {
            IoDeleteDevice();
          }
          if (pcVar9 != (char *)0x0) {
            ExFreePoolWithTag(pcVar9,0);
          }
          ObfDereferenceObject(lVar7);
          ZwMakeTemporaryObject(local_120);
          ZwClose(local_120);
          return uVar10;
        }
        ZwMakeTemporaryObject(local_120);
        ZwClose(local_120);
        ObfDereferenceObject(lVar7);
      }
      return uVar6;
    }
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return uVar10;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
    return uVar10;
  }
  if (WPP_GLOBAL_Control[0x29] == '\0') {
    return uVar10;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
           &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,(int)uVar6);
  return uVar10;
}



===== DiskDriverReinitialization @ 140010530 =====

void DiskDriverReinitialization(void)

{
  return;
}



===== DiskGetInfoExceptionInformation @ 14001053c =====

int DiskGetInfoExceptionInformation(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  byte *pbVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  
  pbVar2 = (byte *)ExAllocatePool2(0x48,0xc0,0x41446353);
  if (pbVar2 == (byte *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    return -0x3fffff66;
  }
  uVar1 = ClassModeSense(*(undefined8 *)(param_1 + 8),pbVar2,0xc0,0x1c);
  if (uVar1 < 4) {
    uVar1 = ClassModeSense(*(undefined8 *)(param_1 + 8),pbVar2,0xc0,0x1c);
    if (uVar1 < 4) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      iVar6 = -0x3ffffe7b;
      goto LAB_140010751;
    }
  }
  uVar8 = *pbVar2 + 1;
  if (uVar1 <= *pbVar2 + 1) {
    uVar8 = uVar1;
  }
  puVar3 = (undefined8 *)ClassFindModePage(pbVar2,uVar8,0x1c,1);
  if (puVar3 == (undefined8 *)0x0) {
    iVar6 = -0x3fffff45;
  }
  else {
    uVar4 = Feature_2022601018__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      if ((byte *)((longlong)puVar3 + 0xcU) <= pbVar2 + uVar8) goto LAB_1400106ee;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x30;
        goto LAB_1400106a8;
      }
    }
    else {
      if (0xb < (ulonglong)*(byte *)((longlong)puVar3 + 1) + 2) {
LAB_1400106ee:
        *param_2 = *puVar3;
        iVar6 = 0;
        *(undefined4 *)(param_2 + 1) = *(undefined4 *)(puVar3 + 1);
        goto LAB_140010706;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = 0x2f;
LAB_1400106a8:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
    }
    iVar6 = -0x3fffffff;
  }
LAB_140010706:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    pcVar7 = "does";
    if (iVar6 < 0) {
      pcVar7 = "does not";
    }
    WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,pcVar7,
              (char)*(undefined8 *)(param_1 + 8));
  }
LAB_140010751:
  ExFreePoolWithTag(pbVar2,0);
  return iVar6;
}



===== DiskInitializeFailurePrediction @ 140010790 =====

void DiskInitializeFailurePrediction(longlong param_1,undefined8 param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(lVar2 + 0x60);
  iVar5 = ClassAcquireRemoveLockEx(param_1,param_2,"minkernel\\storage\\disk\\disk.c",0xa46);
  if (iVar5 == 0) {
    piVar1 = (int *)(lVar3 + 0x10);
    DiskDetectFailurePrediction(lVar2,piVar1,*(int *)(lVar3 + 8) != 0);
    if (*piVar1 != 0) {
      IoWMIRegistrationControl(param_1,4);
      uVar6 = 0xe10;
      *(undefined1 *)(lVar3 + 0x14) = 1;
      uVar4 = DiskEnableDisableFailurePredictPolling(lVar2,'\x01',0xe10);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,uVar6,*piVar1,
                   (char)param_1,uVar4);
      }
    }
    ClassReleaseRemoveLock(param_1,param_2);
  }
  IoFreeWorkItem(param_2);
  return;
}



===== DiskIoctlEnableFailurePrediction @ 140010898 =====

int DiskIoctlEnableFailurePrediction(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  byte bVar6;
  int iVar7;
  ulonglong uVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar4 = *(longlong *)(lVar2 + 0x60);
  bVar6 = KeGetCurrentIrql();
  if (1 < bVar6) {
    return -0x3ffffeb8;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  if ((*(uint *)(lVar3 + 0x10) < 0xc) || (*(uint *)(lVar3 + 8) < 0xc)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    return -0x3fffffdd;
  }
  piVar5 = *(int **)(param_2 + 0x18);
  if ((((*piVar5 != 1) || ((uint)piVar5[1] < 0xc)) &&
      ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
            &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
  }
  if (((*(short *)((longlong)piVar5 + 10) != 0) &&
      ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
            &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
  }
  iVar7 = 0;
  if (((char)piVar5[2] != '\0') &&
     (cVar1 = *(char *)((longlong)piVar5 + 9), cVar1 != *(char *)(lVar4 + 0x16))) {
    if (*(int *)(lVar4 + 0x10) - 1U < 2) {
      uVar8 = DiskEnableDisableFailurePrediction(lVar2,cVar1);
      iVar7 = (int)uVar8;
    }
    else if (*(char *)(lVar4 + 0x15) != '\0') {
      iVar7 = DiskEnableInfoExceptions(lVar2,cVar1);
    }
  }
  *(undefined1 *)((longlong)piVar5 + 9) = *(undefined1 *)(lVar4 + 0x16);
  if (-1 < iVar7) {
    *(undefined8 *)(param_2 + 0x38) = 0xc;
  }
  return iVar7;
}



===== DiskIoctlGetDriveGeometryEx @ 140010a54 =====

undefined8 DiskIoctlGetDriveGeometryEx(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  char cVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  
  bVar4 = KeGetCurrentIrql();
  if (bVar4 < 2) {
    lVar2 = *(longlong *)(param_1 + 0x40);
    uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    lVar3 = *(longlong *)(lVar2 + 0x60);
    if ((int)uVar1 < 0x20) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      uVar6 = 0xc0000023;
    }
    else {
      memset(*(void **)(param_2 + 0x18),0,(ulonglong)uVar1);
      if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
        uVar6 = ClassReadDriveCapacity(*(undefined8 *)(*(longlong *)(lVar2 + 0x18) + 8));
        *(int *)(lVar3 + 4) = (int)uVar6;
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      }
      puVar8 = *(undefined8 **)(param_2 + 0x18);
      uVar6 = *(undefined8 *)(lVar2 + 0x230);
      *puVar8 = *(undefined8 *)(lVar2 + 0x228);
      puVar8[1] = uVar6;
      puVar8[2] = *(undefined8 *)(lVar2 + 0x238);
      if ((*(int *)((longlong)puVar8 + 0x14) == 0) &&
         (cVar5 = DiskIsManagedZonedDevice(param_1), cVar5 == '\0')) {
        *(undefined4 *)((longlong)puVar8 + 0x14) = 0x200;
      }
      puVar8[3] = *(undefined8 *)(lVar2 + 0x90);
      uVar7 = 0x28;
      if (uVar1 < 0x28) {
        uVar7 = (ulonglong)uVar1;
      }
      *(ulonglong *)(param_2 + 0x38) = uVar7;
      uVar6 = 0;
    }
  }
  else {
    uVar6 = 0xc0000148;
  }
  return uVar6;
}



===== DiskIoctlReassignBlocks @ 140010b88 =====

undefined4 DiskIoctlReassignBlocks(longlong param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined2 *puVar6;
  byte bVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  ulonglong uVar12;
  uint uVar13;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  puVar6 = *(undefined2 **)(param_2 + 0x18);
  bVar7 = KeGetCurrentIrql();
  if (1 < bVar7) {
    return 0xc0000148;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  uVar2 = *(uint *)(lVar5 + 0x10);
  if (uVar2 < 8) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000004;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return 0xc0000004;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000004;
    }
    uVar8 = 0x54;
  }
  else {
    if (puVar6[1] == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      return 0xc000000d;
    }
    uVar13 = (uint)(ushort)puVar6[1] * 4 + 4;
    if (uVar13 <= uVar2) {
      uVar9 = 0xb8;
      if (*(char *)(*(longlong *)(lVar4 + 0x210) + 0x1e) != '\x01') {
        uVar9 = 0x58;
      }
      puVar10 = (undefined2 *)ExAllocatePool2(0x40,uVar9,0x53446353);
      if (puVar10 == (undefined2 *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                  &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
        }
        return 0xc000009a;
      }
      uVar1 = puVar6[1];
      uVar12 = (ulonglong)uVar1;
      *puVar6 = 0;
      puVar6[1] = (uVar1 & 0x3fff) >> 6 | uVar1 << 10;
      while ((int)uVar12 != 0) {
        uVar12 = (ulonglong)((int)uVar12 - 1);
        uVar3 = *(undefined4 *)(puVar6 + uVar12 * 2 + 2);
        *(char *)(puVar6 + uVar12 * 2 + 3) = (char)((uint)uVar3 >> 8);
        *(char *)((longlong)puVar6 + uVar12 * 4 + 7) = (char)uVar3;
        *(char *)(puVar6 + uVar12 * 2 + 2) = (char)((uint)uVar3 >> 0x18);
        *(char *)((longlong)puVar6 + uVar12 * 4 + 5) = (char)((uint)uVar3 >> 0x10);
      }
      if (*(char *)(*(longlong *)(lVar4 + 0x210) + 0x1e) == '\x01') {
        *(undefined4 *)(puVar10 + 6) = 1;
        *puVar10 = 8;
        *(undefined1 *)(puVar10 + 1) = 0x28;
        *(undefined4 *)(puVar10 + 4) = 0x53524258;
        *(undefined4 *)(puVar10 + 8) = uVar9;
        *(undefined4 *)(puVar10 + 10) = 0;
        uVar8 = IoGetIoPriorityHint(param_2);
        *(undefined4 *)(puVar10 + 0x1a) = 0x80;
        *(undefined4 *)(puVar10 + 0x1c) = 1;
        puVar10[0x12] = uVar8;
        *(undefined4 *)(puVar10 + 0x14) = *(undefined4 *)(lVar4 + 0x248);
        puVar10[0x40] = 1;
        *(undefined4 *)(puVar10 + 0x42) = 4;
        *(undefined4 *)(puVar10 + 0x3c) = 0x90;
        if (*(uint *)(puVar10 + 8) < 0xb8) {
          ExFreePoolWithTag(puVar10,0);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                    &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
          }
          return 0xc00000e5;
        }
        *(undefined4 *)(puVar10 + 0x48) = 0x40;
        puVar11 = puVar10 + 0x54;
        *(undefined4 *)(puVar10 + 0x4a) = 0x20;
        *(undefined1 *)(puVar10 + 0x4d) = 6;
      }
      else {
        *puVar10 = 0x58;
        *(undefined1 *)(puVar10 + 1) = 0;
        *(undefined1 *)(puVar10 + 5) = 6;
        *(undefined4 *)(puVar10 + 10) = *(undefined4 *)(lVar4 + 0x248);
        puVar11 = puVar10 + 0x24;
      }
      *(undefined1 *)puVar11 = 7;
      uVar9 = ClassSendSrbSynchronous(param_1,puVar10,puVar6,uVar13,1);
      ExFreePoolWithTag(puVar10,0);
      return uVar9;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000004;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return 0xc0000004;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000004;
    }
    uVar8 = 0x56;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
          &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
  return 0xc0000004;
}



===== DiskIoctlReassignBlocksEx @ 140010efc =====

undefined4 DiskIoctlReassignBlocksEx(longlong param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined2 *puVar5;
  undefined8 uVar6;
  byte bVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  ulonglong uVar12;
  uint uVar13;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  puVar5 = *(undefined2 **)(param_2 + 0x18);
  bVar7 = KeGetCurrentIrql();
  if (1 < bVar7) {
    return 0xc0000148;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  uVar2 = *(uint *)(lVar4 + 0x10);
  if (uVar2 < 0xc) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000004;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return 0xc0000004;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000004;
    }
    uVar8 = 0x5a;
  }
  else {
    if (puVar5[1] == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      return 0xc000000d;
    }
    uVar13 = (uint)(ushort)puVar5[1] * 8 + 4;
    if (uVar13 <= uVar2) {
      uVar9 = 0xb8;
      if (*(char *)(*(longlong *)(lVar3 + 0x210) + 0x1e) != '\x01') {
        uVar9 = 0x58;
      }
      puVar10 = (undefined2 *)ExAllocatePool2(0x40,uVar9,0x53446353);
      if (puVar10 == (undefined2 *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
                  &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
        }
        return 0xc000009a;
      }
      uVar1 = puVar5[1];
      uVar12 = (ulonglong)uVar1;
      *puVar5 = 0;
      puVar5[1] = (uVar1 & 0x1fff) >> 5 | uVar1 << 0xb;
      while ((int)uVar12 != 0) {
        uVar12 = (ulonglong)((int)uVar12 - 1);
        uVar6 = *(undefined8 *)(puVar5 + uVar12 * 4 + 2);
        *(char *)((longlong)puVar5 + uVar12 * 8 + 0xb) = (char)uVar6;
        *(char *)(puVar5 + uVar12 * 4 + 5) = (char)((ulonglong)uVar6 >> 8);
        *(char *)((longlong)puVar5 + uVar12 * 8 + 9) = (char)((ulonglong)uVar6 >> 0x10);
        *(char *)(puVar5 + uVar12 * 4 + 4) = (char)((ulonglong)uVar6 >> 0x18);
        *(char *)((longlong)puVar5 + uVar12 * 8 + 7) = (char)((ulonglong)uVar6 >> 0x20);
        *(char *)(puVar5 + uVar12 * 4 + 3) = (char)((ulonglong)uVar6 >> 0x28);
        *(char *)(puVar5 + uVar12 * 4 + 2) = (char)((ulonglong)uVar6 >> 0x38);
        *(char *)((longlong)puVar5 + uVar12 * 8 + 5) = (char)((ulonglong)uVar6 >> 0x30);
      }
      if (*(char *)(*(longlong *)(lVar3 + 0x210) + 0x1e) == '\x01') {
        *puVar10 = 8;
        *(undefined1 *)(puVar10 + 1) = 0x28;
        *(undefined4 *)(puVar10 + 4) = 0x53524258;
        *(undefined4 *)(puVar10 + 6) = 1;
        *(undefined4 *)(puVar10 + 8) = uVar9;
        *(undefined4 *)(puVar10 + 10) = 0;
        uVar8 = IoGetIoPriorityHint(param_2);
        *(undefined4 *)(puVar10 + 0x1a) = 0x80;
        *(undefined4 *)(puVar10 + 0x1c) = 1;
        puVar10[0x12] = uVar8;
        *(undefined4 *)(puVar10 + 0x14) = *(undefined4 *)(lVar3 + 0x248);
        puVar10[0x40] = 1;
        *(undefined4 *)(puVar10 + 0x42) = 4;
        *(undefined4 *)(puVar10 + 0x3c) = 0x90;
        if (*(uint *)(puVar10 + 8) < 0xb8) {
          ExFreePoolWithTag(puVar10,0);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
                    &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
          }
          return 0xc00000e5;
        }
        *(undefined4 *)(puVar10 + 0x48) = 0x40;
        puVar11 = puVar10 + 0x54;
        *(undefined4 *)(puVar10 + 0x4a) = 0x20;
        *(undefined1 *)(puVar10 + 0x4d) = 6;
      }
      else {
        *puVar10 = 0x58;
        puVar11 = puVar10 + 0x24;
        *(undefined1 *)(puVar10 + 1) = 0;
        *(undefined1 *)(puVar10 + 5) = 6;
        *(undefined4 *)(puVar10 + 10) = *(undefined4 *)(lVar3 + 0x248);
      }
      *(undefined1 *)puVar11 = 7;
      *(byte *)((longlong)puVar11 + 1) = *(byte *)((longlong)puVar11 + 1) & 0xe3 | 2;
      uVar9 = ClassSendSrbSynchronous(param_1,puVar10,puVar5,uVar13,1);
      ExFreePoolWithTag(puVar10,0);
      return uVar9;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000004;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return 0xc0000004;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000004;
    }
    uVar8 = 0x5c;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
          &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
  return 0xc0000004;
}



===== DiskIoctlSetCacheInformation @ 1400112a8 =====

int DiskIoctlSetCacheInformation(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  byte *pbVar3;
  longlong lVar4;
  byte bVar5;
  int iVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  pbVar3 = *(byte **)(param_2 + 0x18);
  lVar4 = *(longlong *)(lVar1 + 0x60);
  bVar5 = KeGetCurrentIrql();
  if (bVar5 < 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
    }
    if (*(uint *)(lVar2 + 0x10) < 0x18) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      iVar6 = -0x3ffffffc;
    }
    else {
      iVar6 = DiskSetCacheInformation(lVar1,pbVar3);
      *(uint *)(lVar4 + 0x208) = (uint)(pbVar3[2] != 0);
      ClassSetDeviceParameter(lVar1,L"Disk",L"UserWriteCacheSetting");
      DiskLogCacheInformation(lVar1,(longlong)pbVar3,iVar6);
    }
  }
  else {
    iVar6 = -0x3ffffeb8;
  }
  return iVar6;
}



===== DiskIoctlSetCacheSetting @ 1400113e4 =====

undefined8 DiskIoctlSetCacheSetting(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  ushort uVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  bool bVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar5 = 0;
  bVar3 = KeGetCurrentIrql();
  if (bVar3 < 2) {
    if (*(uint *)(lVar2 + 0x10) < 0xc) {
      uVar5 = 0xc0000004;
    }
    else if (**(int **)(param_2 + 0x18) == 0xc) {
      bVar7 = (char)(*(int **)(param_2 + 0x18))[2] == '\0';
      uVar6 = 1;
      if (bVar7) {
        uVar4 = *(ushort *)(lVar1 + 0x280) & 0xffef;
      }
      else {
        uVar4 = *(ushort *)(lVar1 + 0x280) | 0x10;
      }
      *(ushort *)(lVar1 + 0x280) = uVar4;
      if ((((*(ushort *)(lVar1 + 0x280) & 1) == 0) || ((*(ushort *)(lVar1 + 0x280) & 0x10) != 0)) ||
         ((char)*(undefined4 *)(lVar1 + 0x36c) < '\0')) {
        uVar6 = 0;
      }
      *(undefined1 *)(lVar1 + 0x283) = uVar6;
      ClassSetDeviceParameter(lVar1,L"Disk",L"CacheIsPowerProtected",!bVar7);
    }
    else {
      uVar5 = 0xc000000d;
    }
  }
  else {
    uVar5 = 0xc0000148;
  }
  return uVar5;
}



===== DiskIoctlUpdateDriveSize @ 1400114d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DiskIoctlUpdateDriveSize(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  int iVar5;
  undefined1 auStack_88 [32];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(lVar1 + 0x60);
  local_44 = 0;
  local_34 = 0;
  bVar4 = KeGetCurrentIrql();
  if (bVar4 < 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
    }
    if (*(uint *)(lVar2 + 8) < 0x18) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      iVar5 = -0x3fffffdd;
    }
    else {
      iVar5 = ClassReadDriveCapacity(param_1);
      *(int *)(lVar3 + 4) = iVar5;
      if (-1 < iVar5) {
        memmove(*(void **)(param_2 + 0x18),(void *)(lVar1 + 0x228),0x18);
        if (*(int *)(*(longlong *)(param_2 + 0x18) + 0x14) == 0) {
          *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x14) = 0x200;
        }
        local_38 = 0xffffffff;
        iVar5 = 0;
        *(undefined8 *)(param_2 + 0x38) = 0x18;
        local_40 = 0;
        local_54 = 0x11dff54c;
        uStack_50 = 0x41f98469;
        uStack_4c = 0x83efdeb3;
        uStack_48 = 0x4ac58764;
        local_58 = 0x240001;
        IoReportTargetDeviceChangeAsynchronous(*(undefined8 *)(lVar1 + 0x200),&local_58,0,0);
      }
    }
  }
  else {
    iVar5 = -0x3ffffeb8;
  }
  return iVar5;
}



===== DiskIoctlVerifyThread @ 140011660 =====

void DiskIoctlVerifyThread(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  char cVar7;
  char cVar6;
  char cVar5;
  char cVar4;
  undefined2 uVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  ushort uVar12;
  longlong lVar13;
  uint uVar14;
  char *pcVar15;
  undefined2 *_Dst;
  undefined4 *local_res20;
  ulonglong uVar16;
  undefined2 *local_68;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar10 = 0;
  lVar2 = *param_2;
  local_68 = (undefined2 *)0x0;
  lVar11 = *(longlong *)(lVar1 + 0x60);
  _Dst = (undefined2 *)param_2[1];
  plVar3 = *(longlong **)(lVar2 + 0x18);
  local_res20 = (undefined4 *)0x0;
  IoFreeWorkItem(param_2[2]);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
  }
  uVar16 = 0;
  lVar13 = *(longlong *)(lVar1 + 0x98) + *plVar3 >> (*(byte *)(lVar1 + 0x282) & 0x3f);
  uVar9 = *(uint *)(plVar3 + 1) >> (*(byte *)(lVar1 + 0x282) & 0x1f);
  lVar11 = lVar11 + 0x38;
  KeWaitForSingleObject(lVar11,0,0,0,0);
  if (*(char *)(*(longlong *)(lVar1 + 0x210) + 0x1e) == '\x01') {
    memset(_Dst,0,0xb8);
    *_Dst = 8;
    *(undefined1 *)(_Dst + 1) = 0x28;
    *(undefined4 *)(_Dst + 4) = 0x53524258;
    *(undefined4 *)(_Dst + 6) = 1;
    *(undefined4 *)(_Dst + 8) = 0xb8;
    uVar8 = IoGetIoPriorityHint();
    *(undefined4 *)(_Dst + 0x1a) = 0x80;
    *(undefined4 *)(_Dst + 0x1c) = 1;
    _Dst[0x12] = uVar8;
    _Dst[0x40] = 1;
    *(undefined4 *)(_Dst + 0x42) = 4;
    *(undefined4 *)(_Dst + 0x3c) = 0x90;
    if (*(uint *)(_Dst + 8) < 0xb8) {
      ExFreePoolWithTag(_Dst,0);
      _Dst = (undefined2 *)0x0;
      ExFreePoolWithTag(param_2,0);
      param_2 = (longlong *)0x0;
      iVar10 = -0x3fffff1b;
      goto LAB_1400119e7;
    }
    local_res20 = (undefined4 *)(_Dst + 0x48);
    *local_res20 = 0x40;
    *(undefined4 *)(_Dst + 0x4a) = 0x20;
    pcVar15 = (char *)(_Dst + 0x54);
    uVar12 = *(ushort *)(lVar1 + 0x280) & 0x20;
    *(byte *)(_Dst + 0x4d) = (-(uVar12 != 0) & 6U) + 10;
    *pcVar15 = (-(uVar12 != 0) & 0x60U) + 0x2f;
    local_68 = _Dst;
  }
  else {
    memset((void *)((longlong)_Dst + 3),0,0x55);
    *_Dst = 0x58;
    *(undefined1 *)(_Dst + 1) = 0;
    pcVar15 = (char *)(_Dst + 0x24);
    if ((*(ushort *)(lVar1 + 0x280) & 0x20) == 0) {
      *(undefined1 *)(_Dst + 5) = 10;
      *pcVar15 = '/';
    }
    else {
      *(undefined1 *)(_Dst + 5) = 0x10;
      *pcVar15 = -0x71;
    }
  }
  do {
    if (uVar9 == 0) break;
    if (uVar9 < 0x100) {
      uVar14 = uVar9 & 0xffff;
    }
    else {
      uVar14 = 0x100;
    }
    if (*(char *)(*(longlong *)(lVar1 + 0x210) + 0x1e) == '\x01') {
      *(undefined1 *)((longlong)local_68 + 3) = 0;
      *(undefined1 *)(local_res20 + 2) = 0;
      *(uint *)(local_68 + 0x14) = (uVar14 + 0x7f >> 7) * *(int *)(lVar1 + 0x248);
    }
    else {
      *(undefined2 *)((longlong)_Dst + 3) = 0;
      *(uint *)(_Dst + 10) = (uVar14 + 0x7f >> 7) * *(int *)(lVar1 + 0x248);
    }
    cVar4 = (char)((ulonglong)lVar13 >> 8);
    cVar5 = (char)((ulonglong)lVar13 >> 0x10);
    cVar6 = (char)((ulonglong)lVar13 >> 0x18);
    cVar7 = (char)(uVar14 >> 8);
    if ((*(ushort *)(lVar1 + 0x280) & 0x20) == 0) {
      pcVar15[2] = cVar6;
      pcVar15[3] = cVar5;
      pcVar15[4] = cVar4;
      pcVar15[7] = cVar7;
      pcVar15[5] = (char)lVar13;
      pcVar15[8] = (char)uVar14;
    }
    else {
      pcVar15[8] = cVar4;
      pcVar15[7] = cVar5;
      pcVar15[6] = cVar6;
      pcVar15[5] = (char)((ulonglong)lVar13 >> 0x20);
      pcVar15[4] = (char)((ulonglong)lVar13 >> 0x28);
      pcVar15[3] = (char)((ulonglong)lVar13 >> 0x30);
      pcVar15[2] = (char)((ulonglong)lVar13 >> 0x38);
      pcVar15[0xc] = cVar7;
      pcVar15[9] = (char)lVar13;
      pcVar15[0xd] = (char)uVar14;
    }
    uVar16 = uVar16 & 0xffffffffffffff00;
    iVar10 = ClassSendSrbSynchronous(param_1,_Dst,0,0,uVar16);
    lVar13 = lVar13 + (ulonglong)uVar14;
    uVar9 = uVar9 - uVar14;
  } while (-1 < iVar10);
LAB_1400119e7:
  KeReleaseMutex(lVar11,0);
  *(undefined8 *)(lVar2 + 0x38) = 0;
  *(int *)(lVar2 + 0x30) = iVar10;
  ClassReleaseRemoveLock(param_1,lVar2);
  ClassCompleteRequest(param_1,lVar2,0);
  if (_Dst != (undefined2 *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  if (param_2 != (longlong *)0x0) {
    ExFreePoolWithTag(param_2,0);
  }
  return;
}



===== DiskLogCacheInformation @ 140011a70 =====

void DiskLogCacheInformation(longlong param_1,longlong param_2,undefined4 param_3)

{
  ushort uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)IoAllocateErrorLogEntry(*(undefined8 *)(param_1 + 8));
  if (puVar3 != (undefined4 *)0x0) {
    uVar1 = *(ushort *)(param_1 + 0x280);
    lVar2 = *(longlong *)(param_1 + 0x60);
    puVar3[5] = param_3;
    *(undefined8 *)(puVar3 + 6) = 0;
    *puVar3 = 0x10000f;
    puVar3[4] = 1;
    puVar3[3] = (uVar1 & 1 ^ 1) * 2 + -0x7ffbffe0;
    puVar3[10] = (uint)*(byte *)(lVar2 + 0xd);
    puVar3[0xb] = (uint)*(byte *)(lVar2 + 0xe);
    puVar3[0xc] = (uint)*(byte *)(lVar2 + 0xf);
    puVar3[0xd] = (uint)*(byte *)(param_2 + 2);
    IoWriteErrorLogEntry(puVar3);
  }
  return;
}



===== DiskSetCacheInformation @ 140011b24 =====

int DiskSetCacheInformation(longlong param_1,byte *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  ulonglong uVar6;
  byte bVar7;
  byte bVar8;
  longlong lVar9;
  undefined2 uVar10;
  byte *pbVar11;
  undefined1 uVar12;
  uint uVar13;
  
  pbVar4 = (byte *)ExAllocatePool2(0x48,0xc0,0x43446353);
  uVar12 = 0;
  if (pbVar4 == (byte *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    return -0x3fffff66;
  }
  uVar2 = ClassModeSense(*(undefined8 *)(param_1 + 8),pbVar4,0xc0,8);
  if (uVar2 < 4) {
    uVar2 = ClassModeSense(*(undefined8 *)(param_1 + 8),pbVar4,0xc0,8);
    if (uVar2 < 4) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      iVar3 = -0x3ffffe7b;
      goto LAB_140011e8e;
    }
  }
  uVar13 = *pbVar4 + 1;
  if (uVar2 <= *pbVar4 + 1) {
    uVar13 = uVar2;
  }
  pbVar5 = (byte *)ClassFindModePage(pbVar4,uVar13,8,1);
  if (pbVar5 == (byte *)0x0) {
    iVar3 = -0x3fffff45;
    goto LAB_140011e8e;
  }
  uVar6 = Feature_2022601018__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    if (pbVar5 + 0xc <= pbVar4 + uVar13) {
LAB_140011cf5:
      *pbVar5 = *pbVar5 & 0x7f;
      bVar7 = param_2[1] == 0 | pbVar5[2] & 0xfe;
      pbVar5[2] = bVar7;
      bVar7 = (param_2[0xe] * '\x02' ^ bVar7) & 2 ^ bVar7;
      pbVar5[2] = bVar7;
      bVar7 = (param_2[2] << 2 ^ bVar7) & 4 ^ bVar7;
      pbVar5[2] = bVar7;
      iVar3 = *(int *)(param_2 + 8);
      if (iVar3 == 0xf) {
        iVar3 = 2;
      }
      else if (iVar3 == 2) {
        iVar3 = 0xf;
      }
      bVar8 = (pbVar5[3] ^ (byte)iVar3) & 0xf ^ pbVar5[3];
      pbVar5[3] = bVar8;
      iVar3 = *(int *)(param_2 + 4);
      if (iVar3 == 0xf) {
        iVar3 = 2;
      }
      else if (iVar3 == 2) {
        iVar3 = 0xf;
      }
      pbVar5[3] = (char)iVar3 << 4 | bVar8 & 0xf;
      pbVar5[4] = param_2[0xd];
      pbVar5[5] = param_2[0xc];
      pbVar5[6] = param_2[0x11];
      pbVar5[7] = param_2[0x10];
      pbVar5[8] = param_2[0x13];
      pbVar5[9] = param_2[0x12];
      if ((bVar7 & 2) != 0) {
        pbVar5[10] = param_2[0x15];
        pbVar5[0xb] = param_2[0x14];
      }
      uVar2 = 0;
      do {
        uVar6 = (ulonglong)(pbVar5[1] + 2);
        lVar9 = *(longlong *)(param_1 + 8);
        pbVar11 = pbVar5;
        iVar3 = DiskModeSelect(lVar9,pbVar5,pbVar5[1] + 2,*param_2);
        if (-1 < iVar3) {
          if (param_2[2] == 0) {
            lVar9 = 0xfffe;
            uVar1 = *(ushort *)(param_1 + 0x280) & 0xfffe;
          }
          else {
            uVar1 = *(ushort *)(param_1 + 0x280) | 1;
          }
          *(ushort *)(param_1 + 0x280) = uVar1;
          if ((((*(ushort *)(param_1 + 0x280) & 1) != 0) &&
              ((*(ushort *)(param_1 + 0x280) & 0x10) == 0)) &&
             (-1 < (char)*(undefined4 *)(param_1 + 0x36c))) {
            uVar12 = 1;
          }
          *(undefined1 *)(param_1 + 0x283) = uVar12;
          if ((Microsoft_Windows_DiskEnableBits & 1) != 0) {
            McTemplateK0uuuuuhhhhq_EtwWriteTransfer
                      (lVar9,pbVar11,uVar6,param_2[1],param_2[2],param_2[4],param_2[8],param_2[0xe],
                       (char)*(undefined2 *)(param_2 + 0xc),(char)*(undefined2 *)(param_2 + 0x10),
                       (char)*(undefined2 *)(param_2 + 0x12),(char)*(undefined2 *)(param_2 + 0x14),
                       (char)*(undefined4 *)(param_1 + 0x24c));
          }
          goto LAB_140011e8e;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < 2);
      *(uint *)(param_1 + 0x36c) = *(uint *)(param_1 + 0x36c) | 0x40;
      goto LAB_140011e8e;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar10 = 0x3b;
LAB_140011cda:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
  }
  else {
    if (0xb < (ulonglong)pbVar5[1] + 2) goto LAB_140011cf5;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar10 = 0x3a;
      goto LAB_140011cda;
    }
  }
  iVar3 = -0x3fffffff;
LAB_140011e8e:
  ExFreePoolWithTag(pbVar4,0);
  return iVar3;
}



===== DiskSetSpecialHacks @ 140011ed0 =====

void DiskSetSpecialHacks(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
             &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_2);
  }
  if ((param_2 & 1) != 0) {
    *(uint *)(param_1 + 0x250) = *(uint *)(param_1 + 0x250) & 0xfffffffd;
  }
  if ((param_2 & 2) != 0) {
    *(uint *)(param_1 + 0x250) = *(uint *)(param_1 + 0x250) | 8;
  }
  if ((param_2 & 4) != 0) {
    *(uint *)(param_1 + 0x36c) = *(uint *)(param_1 + 0x36c) | 1;
  }
  if ((param_2 & 8) != 0) {
    *(uint *)(param_1 + 0x36c) = *(uint *)(param_1 + 0x36c) | 0x10;
  }
  if ((param_2 & 0x10) != 0) {
    *(uint *)(param_1 + 0x36c) = *(uint *)(param_1 + 0x36c) | 0x20;
  }
  if ((param_2 & 0x20) != 0 && (*(byte *)(lVar1 + 0x34) & 1) != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,lVar1);
    }
    *(ushort *)(param_1 + 0x280) = *(ushort *)(param_1 + 0x280) | 4;
  }
  return;
}



===== DiskUnload @ 140011fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DiskUnload(void)

{
  undefined *puVar1;
  
  McGenEventUnregister_EtwUnregister();
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
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



===== WppInitKm @ 1400120ac =====

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



===== WppLoadTracingSupport @ 14001213c =====

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



===== WppTraceCallback @ 140012280 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 140012508 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400125d4 =====

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
      goto LAB_140012631;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140012631;
    }
  }
  uVar1 = 0x206;
LAB_140012631:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14001263c =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400126f4 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14001272c =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1400127ae;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1400127ae;
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
LAB_1400127ae:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140012800 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140012860 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001287c =====

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



===== DiskEnableDisableFailurePredictPolling @ 140012930 =====

void DiskEnableDisableFailurePredictPolling(longlong param_1,char param_2,undefined4 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x60);
  uVar3 = 0;
  if (param_2 != '\0') {
    uVar2 = DiskEnableDisableFailurePrediction(param_1,param_2);
    if ((int)uVar2 < 0) {
      return;
    }
    uVar3 = *(undefined4 *)(lVar1 + 0x10);
  }
  ClassSetFailurePredictionPoll(param_1,uVar3,param_3);
  return;
}



===== DiskEnableDisableFailurePrediction @ 140012990 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskEnableDisableFailurePrediction(longlong param_1,char param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStackY_98 [32];
  uint local_58 [2];
  int local_50 [15];
  undefined1 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar2 = *(longlong *)(param_1 + 0x60);
  iVar1 = *(int *)(lVar2 + 0x10);
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      if (param_2 == '\0') {
        local_58[0] = 0x3d;
        local_50[0xc] = 0;
        local_50[0xd] = 0;
        local_50[0xe] = 0;
        local_14 = 0;
        local_50[0] = 0;
        local_50[1] = 0;
        local_50[2] = 0;
        local_50[3] = 0;
        local_50[4] = 0;
        local_50[5] = 0;
        local_50[6] = 0;
        local_50[7] = 0;
        local_50[8] = 0;
        local_50[9] = 0;
        local_50[10] = 0;
        local_50[0xb] = 0;
        uVar3 = DiskPerformSmartCommand(param_1,0x1b0505,0xb0,0xd9,0,0,local_50,local_58);
      }
      else {
        uVar3 = DiskEnableSmart(param_1);
      }
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      *(char *)(lVar2 + 0x16) = param_2;
      return uVar3;
    }
    if (iVar1 != 3) {
      return 0xc0000010;
    }
  }
  return 0;
}



===== DiskEnableInfoExceptions @ 140012a78 =====

int DiskEnableInfoExceptions(longlong param_1,char param_2)

{
  longlong lVar1;
  ulonglong *puVar2;
  int iVar3;
  byte *pbVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  undefined8 uVar8;
  uint local_res8 [2];
  ulonglong *local_res18;
  ulonglong local_38;
  
  lVar1 = *(longlong *)(param_1 + 0x60);
  local_res18 = (ulonglong *)0x0;
  uVar8 = 0xc0;
  local_res8[0] = 0xc0;
  pbVar4 = (byte *)ExAllocatePool2(0x48,0xc0,0x41446353);
  if (pbVar4 == (byte *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids);
    }
    return -0x3fffff66;
  }
  uVar5 = DiskGetModePage(*(undefined8 *)(param_1 + 8),uVar8,1,pbVar4,local_res8,
                          (longlong *)&local_res18);
  uVar6 = Feature_2022601018__private_IsEnabledDeviceUsageNoInline();
  puVar2 = local_res18;
  if ((int)uVar6 == 0) {
    if ((-1 < (int)uVar5) && (local_res18 != (ulonglong *)0x0)) goto LAB_140012b95;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 4))
       )) goto LAB_140012d9c;
    uVar7 = 0xe;
  }
  else if ((((int)uVar5 < 0) || (local_res18 == (ulonglong *)0x0)) ||
          ((ulonglong)*(byte *)((longlong)local_res18 + 1) + 2 < 4)) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140012d9c;
    uVar7 = 0xd;
  }
  else {
LAB_140012b95:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar8 = 0xf;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,*(undefined8 *)(param_1 + 8));
    }
    if ((*puVar2 & 0x80000) == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140012d9c;
      uVar7 = 0x10;
    }
    else {
      uVar6 = Feature_2022601018__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar6 == 0) {
        local_38 = *puVar2;
      }
      else {
        local_38 = (ulonglong)(uint)*puVar2;
      }
      uVar8 = DiskGetModePage(*(undefined8 *)(param_1 + 8),uVar8,0,pbVar4,local_res8,
                              (longlong *)&local_res18);
      uVar6 = Feature_2022601018__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar6 == 0) {
        if (((int)uVar8 < 0) || (local_res18 == (ulonglong *)0x0)) goto LAB_140012d9c;
      }
      else if (((int)uVar8 < 0) ||
              ((local_res18 == (ulonglong *)0x0 ||
               ((ulonglong)*(byte *)((longlong)local_res18 + 1) + 2 < 4)))) goto LAB_140012d9c;
      if (((*local_res18 & 0xf000000) != 0) || ((local_38 & 0xf000000) != 0)) {
        if ((local_38 & 0x800000) != 0) {
          *(byte *)((longlong)local_res18 + 2) =
               ~-(*(char *)(lVar1 + 0x14) != '\0') & 0x80U |
               *(byte *)((longlong)local_res18 + 2) & 0x7f;
        }
        if ((local_38 & 0xf000000) != 0) {
          *(byte *)((longlong)local_res18 + 3) = *(byte *)((longlong)local_res18 + 3) & 0xf4 | 4;
        }
        *(byte *)((longlong)local_res18 + 2) =
             ~-(param_2 != '\0') & 8U | *(byte *)((longlong)local_res18 + 2) & 0xf7;
        iVar3 = ClassModeSelect(*(undefined8 *)(param_1 + 8),pbVar4,local_res8[0],
                                (byte)*local_res18 >> 7);
        if (-1 < iVar3) {
          if (param_2 == '\0') {
            *(undefined4 *)(lVar1 + 0x10) = 0;
            *(undefined1 *)(lVar1 + 0x16) = 0;
          }
          else {
            *(undefined4 *)(lVar1 + 0x10) = 3;
            *(undefined1 *)(lVar1 + 0x16) = 1;
          }
        }
        ExFreePoolWithTag(pbVar4,0);
        return iVar3;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140012d9c;
      uVar7 = 0x11;
    }
  }
  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
           &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,*(undefined8 *)(param_1 + 8));
LAB_140012d9c:
  ExFreePoolWithTag(pbVar4,0);
  return -0x3fffff45;
}



===== DiskFdoExecuteWmiMethod @ 140012de0 =====

void DiskFdoExecuteWmiMethod
               (longlong param_1,ulonglong param_2,int param_3,int param_4,uint param_5,uint param_6
               ,uint *param_7)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  undefined7 uVar13;
  ulonglong uVar12;
  bool bVar14;
  ulonglong in_stack_ffffffffffffff88;
  undefined8 local_48;
  undefined4 local_40;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(lVar2 + 0x60);
  lVar8 = param_1;
  uVar12 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    in_stack_ffffffffffffff88 = param_2;
    WPP_SF_qqddDDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1,param_2,param_1,(char)param_2,
                   (char)param_3,(char)param_4,(char)param_5,(char)param_6,(char)param_7);
  }
  if (((param_3 == 0) || (param_3 == 1)) || (param_3 == 2)) {
LAB_140013306:
    uVar11 = 0;
    iVar5 = -0x3ffffff0;
LAB_140012ecb:
  }
  else {
    if (param_3 != 3) {
      if (((param_3 != 4) && (param_3 != 5)) && (param_3 != 6)) {
        uVar11 = 0;
        iVar5 = -0x3ffffd6b;
        goto LAB_140012ecb;
      }
      goto LAB_140013306;
    }
    if (param_4 != 1) {
      if (param_4 == 2) {
        uVar11 = 0;
        if (param_5 == 0) goto LAB_140012fdb;
        bVar1 = (byte)*param_7;
        if (bVar1 == 0) {
          uVar12 = 0;
          DiskEnableDisableFailurePredictPolling(lVar2,'\0',0);
        }
        uVar7 = DiskEnableDisableFailurePrediction(lVar2,bVar1);
        iVar5 = (int)uVar7;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140013323;
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          in_stack_ffffffffffffff88 = *(ulonglong *)(lVar2 + 8);
          WPP_SF_DqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,uVar12,(uint)bVar1,
                     (char)in_stack_ffffffffffffff88,(char)uVar7);
        }
      }
      else if (param_4 == 3) {
        uVar11 = 0;
        if (param_5 < 5) goto LAB_140012fdb;
        uVar10 = *param_7;
        bVar1 = (byte)param_7[1];
        uVar12 = (ulonglong)uVar10;
        uVar9 = CONCAT71((int7)((ulonglong)lVar8 >> 8),bVar1);
        iVar5 = DiskEnableDisableFailurePredictPolling(lVar2,bVar1,uVar10);
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140013323;
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          in_stack_ffffffffffffff88 = CONCAT44((int)(in_stack_ffffffffffffff88 >> 0x20),uVar10);
          WPP_SF_DDqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,uVar12,(uint)bVar1,
                      (char)uVar10,(char)*(undefined8 *)(lVar2 + 8),(char)iVar5);
        }
      }
      else if (param_4 == 4) {
        uVar11 = 4;
        if (param_6 < 4) {
LAB_140012fd1:
          iVar5 = -0x3fffffdd;
        }
        else {
          uVar10 = *(uint *)(lVar3 + 0x10);
          iVar5 = 0;
          *param_7 = uVar10;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140013323;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            in_stack_ffffffffffffff88 = *(ulonglong *)(lVar2 + 8);
            WPP_SF_DqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,uVar12,uVar10,
                       (char)in_stack_ffffffffffffff88,0);
          }
        }
      }
      else {
        if (param_4 != 5) {
          uVar13 = (undefined7)(uVar12 >> 8);
          if (param_4 == 6) {
            if (*(int *)(lVar3 + 0x10) != 2) goto LAB_140013306;
            if (1 < param_5) {
              uVar10 = (uint)*(byte *)((longlong)param_7 + 1) * 0x200;
              uVar11 = uVar10 + 4;
              if (uVar11 <= param_6) {
                uVar12 = CONCAT71(uVar13,(char)*param_7);
                uVar7 = DiskReadSmartLog(lVar2,*(byte *)((longlong)param_7 + 1),(char)*param_7,
                                         param_7 + 1);
                iVar6 = (int)uVar7;
                bVar14 = iVar6 < 0;
                if (bVar14) {
                  uVar10 = 0;
                }
                *param_7 = uVar10;
LAB_140013071:
                iVar5 = 0;
                if (!bVar14) {
                  iVar5 = iVar6;
                }
                goto LAB_140012ece;
              }
              goto LAB_140012fd1;
            }
          }
          else {
            if (param_4 != 7) {
              if (param_4 == 8) {
                if (*(int *)(lVar3 + 0x10) != 2) goto LAB_140013306;
                if (param_5 == 0) goto LAB_140012fdb;
                uVar11 = 4;
                if (param_6 < 4) goto LAB_140012fd1;
                if ((byte)*param_7 < 3) {
                  iVar5 = DiskExecuteSmartDiagnostics(lVar2,(byte)*param_7);
                  if (iVar5 < 0) {
                    *param_7 = 2;
                    iVar5 = 0;
                  }
                  else {
                    *param_7 = 0;
                  }
                  goto LAB_140012ece;
                }
                *param_7 = 1;
                iVar5 = 0;
              }
              else {
                uVar11 = 0;
                iVar5 = -0x3ffffd69;
              }
              goto LAB_140012ecb;
            }
            if (*(int *)(lVar3 + 0x10) != 2) goto LAB_140013306;
            if ((7 < (int)param_5) &&
               ((uint)*(byte *)((longlong)param_7 + 1) * 0x200 + 8 <= param_5)) {
              uVar11 = 1;
              if (param_6 != 0) {
                uVar12 = CONCAT71(uVar13,(char)*param_7);
                uVar7 = DiskWriteSmartLog(lVar2,*(byte *)((longlong)param_7 + 1),(char)*param_7,
                                          param_7 + 2);
                iVar6 = (int)uVar7;
                *(byte *)param_7 = (byte)(uVar7 >> 0x1f) & 1 ^ 1;
                bVar14 = iVar6 < 0;
                goto LAB_140013071;
              }
              goto LAB_140012fd1;
            }
          }
          goto LAB_140012fdb;
        }
        uVar11 = 1;
        if (param_6 == 0) goto LAB_140012fd1;
        if (*(int *)(lVar3 + 0x10) == 2) {
          lVar8 = 0;
          iVar5 = DiskExecuteSmartDiagnostics(lVar2,0);
        }
        else {
          iVar5 = -0x3ffffff0;
        }
        *(byte *)param_7 = (byte)((uint)iVar5 >> 0x1f) ^ 1;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140013323;
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          in_stack_ffffffffffffff88 = CONCAT44((int)(in_stack_ffffffffffffff88 >> 0x20),iVar5);
          WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar8,uVar12,
                    *(undefined8 *)(lVar2 + 8),(char)iVar5);
        }
      }
      goto LAB_140012ecb;
    }
    uVar11 = 0;
    if (param_5 == 0) {
LAB_140012fdb:
      uVar11 = 0;
      iVar5 = -0x3ffffff3;
      goto LAB_140012ecb;
    }
    bVar1 = (byte)*param_7;
    iVar5 = 0;
    if (*(byte *)(lVar3 + 0x14) != bVar1) {
      *(byte *)(lVar3 + 0x14) = bVar1;
      if (*(int *)(lVar3 + 0x10) == 3) {
        local_48 = 0;
        local_40 = 0;
        iVar5 = DiskGetInfoExceptionInformation(lVar2,&local_48);
        if (-1 < iVar5) {
          bVar4 = local_48._2_1_ & 0x7f;
          local_48._0_3_ = CONCAT12(~-(bVar1 != 0) & 0x80U | bVar4,(undefined2)local_48);
          iVar5 = DiskSetInfoExceptionInformation(lVar2,&local_48);
        }
      }
      else {
        iVar5 = -0x3ffffff0;
      }
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140013323;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      in_stack_ffffffffffffff88 = *(ulonglong *)(lVar2 + 8);
      WPP_SF_DqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,uVar12,(uint)bVar1,
                 (char)in_stack_ffffffffffffff88,(char)iVar5);
    }
  }
LAB_140012ece:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    in_stack_ffffffffffffff88 = param_2;
    WPP_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,uVar12,param_1,(char)param_2,
               (char)iVar5);
  }
LAB_140013323:
  ClassWmiCompleteRequest
            (param_1,param_2,iVar5,uVar11,in_stack_ffffffffffffff88 & 0xffffffffffffff00);
  return;
}



===== DiskFdoQueryWmiRegInfo @ 140013360 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DiskFdoQueryWmiRegInfo(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = DAT_14000c11c | 0x10000;
  iVar1 = *(int *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) + 0x10);
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      DAT_14000c11c = uVar2;
      if (iVar1 == 3) {
        _DAT_14000c0bc = _DAT_14000c0bc & 0xfffeffff;
        _DAT_14000c104 = _DAT_14000c104 & 0xfffeffff;
        _DAT_14000c0ec = _DAT_14000c0ec & 0xfffeffff;
        _DAT_14000c0d4 = _DAT_14000c0d4 | 0x10000;
        DAT_14000c134 = DAT_14000c134 & 0xfffeffff;
      }
      else {
        _DAT_14000c0bc = _DAT_14000c0bc | 0x10000;
        _DAT_14000c0d4 = _DAT_14000c0d4 | 0x10000;
        _DAT_14000c104 = _DAT_14000c104 | 0x10000;
        _DAT_14000c0ec = _DAT_14000c0ec | 0x10000;
        DAT_14000c134 = DAT_14000c134 | 0x10000;
      }
      goto LAB_14001340f;
    }
    uVar2 = DAT_14000c11c & 0xfffeffff;
  }
  DAT_14000c11c = uVar2;
  _DAT_14000c0bc = _DAT_14000c0bc & 0xfffeffff;
  _DAT_14000c0d4 = _DAT_14000c0d4 & 0xfffeffff;
  _DAT_14000c104 = _DAT_14000c104 & 0xfffeffff;
  _DAT_14000c0ec = _DAT_14000c0ec & 0xfffeffff;
  DAT_14000c134 = DAT_14000c134 | 0x10000;
LAB_14001340f:
  *param_2 = 0x20;
  return 0;
}



===== DiskFdoSetWmiDataBlock @ 140013420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DiskFdoSetWmiDataBlock
               (longlong param_1,undefined8 param_2,undefined8 param_3,uint param_4,longlong param_5
               )

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStackY_98 [32];
  undefined2 local_58;
  byte local_56;
  byte local_55;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar4 = (uint)param_3;
  lVar2 = *(longlong *)(lVar1 + 0x60);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqdDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,(char)param_2,
                 (char)param_3,(char)param_4,(char)param_5);
  }
  if (uVar4 == 6) {
    if (param_4 < 0xc) {
      iVar3 = -0x3ffffff3;
    }
    else {
      local_56 = *(byte *)(param_5 + 1);
      local_55 = *(byte *)(param_5 + 2) & 0xf;
      local_58 = 0xa1c;
      local_51 = *(undefined1 *)(param_5 + 4);
      local_52 = *(undefined1 *)(param_5 + 5);
      local_53 = *(undefined1 *)(param_5 + 6);
      local_54 = *(undefined1 *)(param_5 + 7);
      local_4d = *(undefined1 *)(param_5 + 8);
      local_4e = *(undefined1 *)(param_5 + 9);
      local_4f = *(undefined1 *)(param_5 + 10);
      local_50 = *(undefined1 *)(param_5 + 0xb);
      *(byte *)(lVar2 + 0x14) = (byte)~local_56 >> 7;
      iVar3 = DiskSetInfoExceptionInformation(lVar1,&local_58);
    }
  }
  else {
    iVar3 = -0x3ffffd6b;
    if (uVar4 < 6) {
      iVar3 = -0x3ffffd3a;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,param_3,param_1,(char)param_2,
               (char)iVar3);
  }
  ClassWmiCompleteRequest(param_1,param_2,iVar3,0);
  return;
}



===== DiskFdoSetWmiDataItem @ 1400135b0 =====

void DiskFdoSetWmiDataItem
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined1 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 uVar1;
  uint uVar2;
  ulonglong in_stack_ffffffffffffffc8;
  
  uVar2 = (uint)param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    in_stack_ffffffffffffffc8 = param_2;
    WPP_SF_qqddDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,(char)param_2,
                  (char)param_3,param_4,param_5,param_6);
  }
  uVar1 = 0xc00002c6;
  if (5 < uVar2) {
    uVar1 = 0xc0000295;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    in_stack_ffffffffffffffc8 = param_2;
    WPP_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,param_3,param_1,(char)param_2,
               (char)uVar1);
  }
  ClassWmiCompleteRequest(param_1,param_2,uVar1,0,in_stack_ffffffffffffffc8 & 0xffffffffffffff00);
  return;
}



===== DiskGetModePage @ 1400136a4 =====

undefined8
DiskGetModePage(undefined8 param_1,undefined8 param_2,undefined1 param_3,byte *param_4,uint *param_5
               ,longlong *param_6)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if ((((param_4 == (byte *)0x0) || (param_5 == (uint *)0x0)) || (uVar2 = *param_5, uVar2 < 4)) ||
     (param_6 == (longlong *)0x0)) {
    uVar4 = 0xc000000d;
  }
  else {
    memset(param_4,0,(ulonglong)uVar2);
    uVar2 = ClassModeSenseEx(param_1,param_4,uVar2,0x1c,param_3);
    if (uVar2 < 4) {
      uVar2 = ClassModeSenseEx(param_1,param_4,*param_5,0x1c,param_3);
      if (uVar2 < 4) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
        }
        *param_5 = 0;
        return 0xc0000185;
      }
    }
    uVar1 = *param_4 + 1;
    if (uVar2 <= *param_4 + 1) {
      uVar1 = uVar2;
    }
    *param_5 = uVar1;
    lVar3 = ClassFindModePage(param_4,uVar1,0x1c,1);
    if (lVar3 == 0) {
      *param_6 = 0;
      uVar4 = 0xc00000bb;
    }
    else {
      *param_6 = lVar3;
      uVar4 = 0;
    }
  }
  return uVar4;
}



===== DiskInitializeReregistration @ 1400137e4 =====

undefined8 DiskInitializeReregistration(void)

{
  KeInitializeSpinLock(&DiskReregSpinlock);
  return 0;
}



===== DiskReadFailurePredictThresholds @ 14001380c =====

ulonglong DiskReadFailurePredictThresholds(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  int *piVar4;
  ulonglong uVar5;
  int *piVar6;
  longlong lVar7;
  uint local_res8 [2];
  
  iVar2 = *(int *)(*(longlong *)(param_1 + 0x60) + 0x10);
  if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 != 2)) {
    return 0xc0000010;
  }
  local_res8[0] = 0x22c;
  piVar4 = (int *)ExAllocatePool2(0x40,0x22c,0x61446353);
  if (piVar4 == (int *)0x0) {
    return 0xc000009a;
  }
  uVar5 = DiskPerformSmartCommand(param_1,0x1b0503,0xb0,0xd1,0,0,piVar4,local_res8);
  if (-1 < (int)uVar5) {
    lVar7 = 4;
    piVar6 = piVar4 + 0xb;
    do {
      uVar3 = *(undefined8 *)(piVar6 + 2);
      *param_2 = *(undefined8 *)piVar6;
      param_2[1] = uVar3;
      uVar3 = *(undefined8 *)(piVar6 + 6);
      param_2[2] = *(undefined8 *)(piVar6 + 4);
      param_2[3] = uVar3;
      uVar3 = *(undefined8 *)(piVar6 + 10);
      param_2[4] = *(undefined8 *)(piVar6 + 8);
      param_2[5] = uVar3;
      uVar3 = *(undefined8 *)(piVar6 + 0xe);
      param_2[6] = *(undefined8 *)(piVar6 + 0xc);
      param_2[7] = uVar3;
      uVar3 = *(undefined8 *)(piVar6 + 0x12);
      param_2[8] = *(undefined8 *)(piVar6 + 0x10);
      param_2[9] = uVar3;
      uVar3 = *(undefined8 *)(piVar6 + 0x16);
      param_2[10] = *(undefined8 *)(piVar6 + 0x14);
      param_2[0xb] = uVar3;
      uVar3 = *(undefined8 *)(piVar6 + 0x1a);
      param_2[0xc] = *(undefined8 *)(piVar6 + 0x18);
      param_2[0xd] = uVar3;
      piVar1 = piVar6 + 0x1c;
      uVar3 = *(undefined8 *)(piVar6 + 0x1e);
      piVar6 = piVar6 + 0x20;
      param_2[0xe] = *(undefined8 *)piVar1;
      param_2[0xf] = uVar3;
      lVar7 = lVar7 + -1;
      param_2 = param_2 + 0x10;
    } while (lVar7 != 0);
  }
  ExFreePoolWithTag(piVar4,0);
  return uVar5 & 0xffffffff;
}



===== DiskReadSmartLog @ 140013934 =====

ulonglong DiskReadSmartLog(longlong param_1,byte param_2,undefined1 param_3,void *param_4)

{
  int iVar1;
  ulonglong uVar2;
  int *piVar3;
  ulonglong uVar4;
  uint local_res10 [2];
  
  uVar2 = (ulonglong)param_2 * 0x200 + 0x10;
  iVar1 = (int)uVar2;
  if (uVar2 < 0x21) {
    iVar1 = 0x21;
  }
  local_res10[0] = iVar1 + 0x1c;
  piVar3 = (int *)ExAllocatePool2(0x40,local_res10[0],0x61446353);
  if (piVar3 == (int *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar4 = DiskPerformSmartCommand(param_1,0x1b050b,0xb0,0xd5,param_2,param_3,piVar3,local_res10);
    uVar2 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      memmove(param_4,piVar3 + 0xb,(ulonglong)param_2 * 0x200);
    }
    ExFreePoolWithTag(piVar3,0);
  }
  return uVar2;
}



===== DiskReregWorker @ 140013a20 =====

void DiskReregWorker(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  bool bVar5;
  
  do {
    lVar4 = ExInterlockedPopEntryList(&DiskReregHead,&DiskReregSpinlock);
    if (lVar4 == 0) {
      iVar3 = -0x3fffff1b;
LAB_140013ac9:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_21b162e7ce8735922baafeb59b96363c_Traceguids,iVar3);
      }
    }
    else {
      uVar1 = *(undefined8 *)(lVar4 + 8);
      lVar2 = *(longlong *)(lVar4 + 0x10);
      iVar3 = IoWMIRegistrationControl(uVar1,4);
      ClassReleaseRemoveLock(uVar1,lVar2);
      IoFreeMdl(*(undefined8 *)(lVar2 + 8));
      IoFreeIrp(lVar2);
      ExFreePoolWithTag(lVar4,0);
      if (iVar3 < 0) goto LAB_140013ac9;
    }
    LOCK();
    iVar3 = DiskReregWorkItems + -1;
    UNLOCK();
    bVar5 = DiskReregWorkItems == 1;
    DiskReregWorkItems = iVar3;
    if (bVar5) {
      IoFreeWorkItem(param_2);
      return;
    }
  } while( true );
}



===== DiskWmiFunctionControl @ 140013b50 =====

void DiskWmiFunctionControl
               (longlong param_1,ulonglong param_2,undefined8 param_3,int param_4,char param_5)

{
  longlong lVar1;
  byte bVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  char *pcVar5;
  undefined8 uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  ulonglong in_stack_ffffffffffffffc8;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar3 = 0;
  iVar7 = (int)param_3;
  bVar2 = (byte)param_3;
  uVar9 = (undefined1)param_2;
  if (param_4 == 1) {
    if (param_5 != '\0') {
      if ((iVar7 - 1U < 3) || (iVar7 == 5)) {
        uVar4 = DiskEnableDisableFailurePrediction(lVar1,'\x01');
        uVar3 = (undefined4)uVar4;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0 &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
          in_stack_ffffffffffffffc8 = param_2;
          WPP_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,param_3,param_1,uVar9,
                     (char)uVar4);
        }
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        in_stack_ffffffffffffffc8 = param_2;
        WPP_SF_qqds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,param_3,param_1,uVar9,bVar2,
                    "Enabled");
      }
    }
  }
  else if (param_4 == 0) {
    uVar4 = param_2;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      pcVar5 = "Enabled";
      if (param_5 == '\0') {
        pcVar5 = "Disabled";
      }
      uVar4 = 0;
      in_stack_ffffffffffffffc8 = param_2;
      WPP_SF_qqds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,param_3,param_1,uVar9,bVar2,pcVar5
                 );
    }
    if ((iVar7 == 4) && (param_5 != '\0')) {
      uVar6 = CONCAT71((int7)(uVar4 >> 8),param_5);
      uVar8 = 0;
      uVar3 = DiskEnableDisableFailurePredictPolling(lVar1,param_5,0);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0 &&
          (bVar2 <= (byte)WPP_GLOBAL_Control[0x29])))) {
        in_stack_ffffffffffffffc8 = param_2;
        WPP_SF_qqsL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,uVar8,param_1,uVar9,
                    "DiskEnableSmartPolling",(char)uVar3);
      }
    }
  }
  ClassWmiCompleteRequest(param_1,param_2,uVar3,0,in_stack_ffffffffffffffc8 & 0xffffffffffffff00);
  return;
}



===== DiskWriteSmartLog @ 140013d48 =====

ulonglong DiskWriteSmartLog(longlong param_1,byte param_2,undefined1 param_3,void *param_4)

{
  int *piVar1;
  ulonglong uVar2;
  uint local_res10 [2];
  
  local_res10[0] = (int)((ulonglong)param_2 * 0x200) + 0x3c;
  piVar1 = (int *)ExAllocatePool2(0x40,local_res10[0],0x61446353);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    memmove(piVar1 + 0xf,param_4,(ulonglong)param_2 * 0x200);
    uVar2 = DiskPerformSmartCommand(param_1,0x1b050c,0xb0,0xd6,param_2,param_3,piVar1,local_res10);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(piVar1,0);
  }
  return uVar2;
}



===== DiskAddDevice @ 140013e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DiskAddDevice(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  code *pcVar2;
  ulonglong uVar3;
  int *piVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  int local_res18 [2];
  ulonglong local_res20;
  undefined1 uVar9;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  ulonglong local_b8;
  undefined8 *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined1 local_88 [8];
  undefined4 local_80;
  wchar_t *local_78;
  int *local_70;
  undefined4 local_68;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_bc = 0;
  local_a4 = 0;
  local_e8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  memset(local_88,0,0x70);
  uVar5 = 0x20019;
  iVar1 = IoOpenDeviceRegistryKey(param_2,1,0x20019,&local_res20);
  uVar9 = (undefined1)param_2;
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),uVar5,iVar1,uVar9);
    }
  }
  else {
    RtlInitUnicodeString(&local_e0,L"Disk");
    puVar6 = &local_c0;
    local_b8 = local_res20;
    local_b0 = &local_e0;
    local_c0 = 0x30;
    local_a8 = 0x240;
    local_a0 = 0;
    uStack_98 = 0;
    iVar1 = ZwOpenKey(&local_e8,0x20019);
    ZwClose(local_res20);
    uVar5 = local_e8;
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_Lqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,puVar6,iVar1,uVar9,
                   (char)local_res20);
      }
    }
    else {
      local_78 = L"RootPartitionMountable";
      local_70 = local_res18;
      local_80 = 0x120;
      local_68 = 0x4000000;
      local_d0 = 0;
      uStack_c8 = 0;
      RtlInitUnicodeString(&local_d0,L"RtlQueryRegistryValuesEx");
      pcVar2 = (code *)MmGetSystemRoutineAddress(&local_d0);
      puVar7 = local_88;
      if (pcVar2 == (code *)0x0) {
        pcVar2 = RtlQueryRegistryValues_exref;
      }
      iVar1 = (*pcVar2)(0x40000000,uVar5,puVar7,0,0);
      if ((((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_Lqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,puVar7,iVar1,(char)local_e8,uVar9)
        ;
      }
      ZwClose(local_e8);
      if (-1 < iVar1) goto LAB_1400140a0;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar8 = "";
    if (local_res18[0] == 0) {
      pcVar8 = "not ";
    }
    WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,pcVar8,uVar9);
  }
LAB_1400140a0:
  local_res20 = local_res20 & 0xffffffff00000000;
  uVar3 = DiskCreateFdo(param_1,param_2,(uint *)&local_res20,local_res18[0] == 0);
  piVar4 = (int *)IoGetConfigurationInformation();
  if (-1 < (int)uVar3) {
    *piVar4 = *piVar4 + 1;
  }
  return uVar3 & 0xffffffff;
}



===== DiskCreateGuidSymbolicLink @ 1400140f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskCreateGuidSymbolicLink(longlong param_1)

{
  wchar_t *pwVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint *puVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined *puVar11;
  undefined1 auStack_78 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar9 = 0;
  lVar3 = *(longlong *)(lVar2 + 0x60);
  if (*(char *)(lVar3 + 0x20c) == '\0') {
    lVar4 = *(longlong *)(lVar2 + 0x490);
    puVar11 = (undefined *)0x10;
    puVar10 = (undefined8 *)(lVar4 + 4);
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    lVar7 = RtlCompareMemory(puVar10,&local_38);
    if (lVar7 == 0x10) {
      return 0xc0000001;
    }
    pwVar1 = (wchar_t *)(lVar2 + 0x70);
    while( true ) {
      uVar8 = DiskGetGuidSymbolicLinkName(puVar10,&local_48);
      uVar9 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) break;
      uVar6 = IoCreateSymbolicLink(&local_48,pwVar1);
      uVar9 = (ulonglong)uVar6;
      if (-1 < (int)uVar6) {
        *(undefined1 *)(lVar3 + 0x20c) = 1;
        goto LAB_140014264;
      }
      if (uVar6 != 0xc0000035) {
LAB_14001422c:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,puVar11,pwVar1,(char)uVar9);
        }
LAB_140014264:
        RtlFreeUnicodeString(&local_48);
        return uVar9;
      }
      DiskLogDuplicateGuidEvent(lVar2);
      uVar6 = ExUuidCreate(puVar10);
      uVar9 = (ulonglong)uVar6;
      puVar5 = *(uint **)(lVar2 + 0x490);
      if ((int)uVar6 < 0) {
        *puVar5 = 0;
        *puVar10 = 0;
        *(undefined8 *)(lVar4 + 0xc) = 0;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar11 = &WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,uVar6);
        }
        goto LAB_14001422c;
      }
      *puVar5 = *puVar5 | 1;
      RtlFreeUnicodeString(&local_48);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,puVar11,pwVar1,(char)uVar8);
    }
    **(undefined4 **)(lVar2 + 0x490) = 0;
    *puVar10 = 0;
    *(undefined8 *)(lVar4 + 0xc) = 0;
  }
  return uVar9;
}



===== DiskCreateSymbolicLinks @ 1400142f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DiskCreateSymbolicLinks(longlong param_1)

{
  longlong lVar1;
  uint *puVar2;
  int iVar3;
  undefined8 uVar4;
  wchar_t *pwVar5;
  undefined1 auStackY_e8 [32];
  wchar_t local_b8 [72];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_e8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar2 = *(uint **)(lVar1 + 0x60);
  memset(local_b8 + 8,0,0x80);
  local_b8[0] = L'\0';
  local_b8[1] = L'\0';
  local_b8[2] = L'\0';
  local_b8[3] = L'\0';
  local_b8[4] = L'\0';
  local_b8[5] = L'\0';
  local_b8[6] = L'\0';
  local_b8[7] = L'\0';
  if ((*puVar2 & 1) == 0) {
    pwVar5 = L"\\Device\\Harddisk%d\\Partition0";
    uVar4 = RtlStringCchPrintfW(local_b8 + 8,0x3f,L"\\Device\\Harddisk%d\\Partition0",
                                (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x18) + 0x24c));
    if (-1 < (int)uVar4) {
      RtlInitUnicodeString(local_b8,local_b8 + 8);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_ZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,pwVar5,local_b8,
                  (wchar_t *)(lVar1 + 0x70));
      }
      iVar3 = IoCreateSymbolicLink(local_b8,lVar1 + 0x70);
      if (-1 < iVar3) {
        *puVar2 = *puVar2 | 1;
      }
    }
  }
  if ((*puVar2 & 2) == 0) {
    pwVar5 = L"\\DosDevices\\PhysicalDrive%d";
    uVar4 = RtlStringCchPrintfW(local_b8 + 8,0x3f,L"\\DosDevices\\PhysicalDrive%d",
                                (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x18) + 0x24c));
    if (-1 < (int)uVar4) {
      RtlInitUnicodeString(local_b8,local_b8 + 8);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_ZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,pwVar5,local_b8,
                  (wchar_t *)(lVar1 + 0x70));
      }
      iVar3 = IoCreateSymbolicLink(local_b8,lVar1 + 0x70);
      if (-1 < iVar3) {
        *puVar2 = *puVar2 | 2;
      }
    }
  }
  DiskCreateGuidSymbolicLink(param_1);
  return;
}



===== DiskDeleteSymbolicLinks @ 140014498 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DiskDeleteSymbolicLinks(longlong param_1)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar2 = *(uint **)(lVar1 + 0x60);
  memset(local_98,0,0x80);
  local_b8 = 0;
  uStack_b0 = 0;
  uVar3 = *puVar2;
  if ((uVar3 & 1) != 0) {
    uVar4 = RtlStringCchPrintfW(local_98,0x3f,L"\\Device\\Harddisk%d\\Partition0",
                                (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x18) + 0x24c));
    if (-1 < (int)uVar4) {
      RtlInitUnicodeString(&local_b8,local_98);
      IoDeleteSymbolicLink(&local_b8);
    }
    *puVar2 = *puVar2 & 0xfffffffe;
    uVar3 = *puVar2;
  }
  if ((uVar3 & 2) != 0) {
    uVar4 = RtlStringCchPrintfW(local_98,0x3f,L"\\DosDevices\\PhysicalDrive%d",
                                (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x18) + 0x24c));
    if (-1 < (int)uVar4) {
      RtlInitUnicodeString(&local_b8,local_98);
      IoDeleteSymbolicLink(&local_b8);
    }
    *puVar2 = *puVar2 & 0xfffffffd;
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  if (*(char *)(lVar1 + 0x20c) != '\0') {
    local_a8 = 0;
    uStack_a0 = 0;
    uVar5 = DiskGetGuidSymbolicLinkName
                      (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x490) + 4,&local_a8);
    if (-1 < (int)uVar5) {
      IoDeleteSymbolicLink(&local_a8);
      *(undefined1 *)(lVar1 + 0x20c) = 0;
    }
    RtlFreeUnicodeString(&local_a8);
  }
  return;
}



===== DiskGenerateDeviceName @ 14001460c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskGenerateDeviceName(uint param_1,longlong *param_2)

{
  ulonglong uVar1;
  char *pcVar2;
  ulonglong uVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  undefined1 auStack_88 [32];
  int local_68;
  char local_58 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  memset(local_58,0,0x40);
  local_68 = diskDeviceSequenceNumber;
  diskDeviceSequenceNumber = diskDeviceSequenceNumber + 1;
  uVar1 = RtlStringCchPrintfA(local_58,0x3f,"\\Device\\Harddisk%d\\DR%d",(ulonglong)param_1);
  uVar3 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,(int)uVar1);
    }
  }
  else {
    lVar7 = -1;
    do {
      lVar5 = lVar7;
      lVar7 = lVar5 + 1;
    } while (local_58[lVar5 + 1] != '\0');
    pcVar2 = (char *)ExAllocatePool2(0x100,lVar5 + 2,0x4e446353);
    *param_2 = (longlong)pcVar2;
    lVar7 = -1;
    if (pcVar2 == (char *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      do {
        lVar5 = lVar7;
        lVar7 = lVar5 + 1;
      } while (local_58[lVar5 + 1] != '\0');
      lVar7 = lVar5 + 2;
      if (lVar5 + 1U < 0x7fffffff) {
        lVar6 = 0x7ffffffe - lVar7;
        lVar5 = -(longlong)pcVar2;
        do {
          if ((lVar6 + lVar7 == 0) || (pcVar2[(longlong)(local_58 + lVar5)] == '\0')) break;
          *pcVar2 = pcVar2[(longlong)(local_58 + lVar5)];
          pcVar2 = pcVar2 + 1;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        pcVar4 = pcVar2 + -1;
        if (lVar7 != 0) {
          pcVar4 = pcVar2;
        }
        *pcVar4 = '\0';
        uVar8 = ~-(uint)(lVar7 != 0) & 0x80000005;
        if (lVar7 != 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                     &WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,local_58);
          }
          return 0;
        }
      }
      else {
        uVar8 = 0xc000000d;
        if (lVar7 != 0) {
          *pcVar2 = '\0';
        }
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,uVar8);
      }
      if (*param_2 != 0) {
        ExFreePoolWithTag(*param_2,0);
        *param_2 = 0;
      }
      uVar3 = (ulonglong)uVar8;
    }
  }
  return uVar3;
}



===== DiskInitFdo @ 140014840 =====

undefined8 DiskInitFdo(longlong param_1)

{
  void *_Dst;
  ushort uVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  uint uVar10;
  ulonglong in_stack_ffffffffffffff88;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(lVar3 + 0x60);
  ClassInitializeSrbLookasideList(lVar3,4);
  if (*(char *)(*(longlong *)(lVar3 + 0x208) + 10) != '\0') {
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 1;
  }
  uVar10 = *(uint *)(lVar3 + 0x250);
  *(uint *)(lVar3 + 0x250) = uVar10 | 0x200000;
  if ((*(char *)(*(longlong *)(lVar3 + 0x208) + 0xb) != '\0') &&
     (*(char *)(*(longlong *)(lVar3 + 0x210) + 0x16) != '\0')) {
    *(uint *)(lVar3 + 0x250) = uVar10 | 0x200002;
  }
  ClassScanForSpecial(lVar3,&DiskBadControllers,DiskSetSpecialHacks);
  *(undefined8 *)(lVar3 + 0x228) = 0;
  *(undefined8 *)(lVar3 + 0x230) = 0;
  *(undefined8 *)(lVar3 + 0x238) = 0;
  lVar8 = ExAllocatePool2(0x48,0x12,0x73446353);
  *(longlong *)(lVar3 + 0x240) = lVar8;
  if (lVar8 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids);
    }
    return 0xc000009a;
  }
  *(undefined1 *)(lVar3 + 0x225) = 0x12;
  *(undefined8 *)(lVar3 + 0x98) = 0;
  if ((*(longlong *)(lVar3 + 0x488) == 0) ||
     (uVar1 = *(ushort *)(*(longlong *)(lVar3 + 0x488) + 0xe), uVar10 = (uint)uVar1, uVar1 == 0)) {
    uVar6 = ClassQueryTimeOutRegistryValue(param_1);
    uVar10 = 10;
    if (uVar6 != 0) {
      uVar10 = uVar6;
    }
  }
  *(uint *)(lVar3 + 0x248) = uVar10;
  if ((*(uint *)(param_1 + 0x34) & 1) == 0) {
    *(ushort *)(lVar3 + 0x280) = *(ushort *)(lVar3 + 0x280) | 4;
  }
  else {
    ClassUpdateInformationInRegistry
              (param_1,"PhysicalDrive",*(undefined4 *)(lVar3 + 0x24c),0,
               in_stack_ffffffffffffff88 & 0xffffffff00000000);
    ClassInitializeMediaChangeDetection(lVar3,"Disk");
    if ((*(int *)(*(longlong *)(lVar3 + 0x208) + 0x1c) != 7) ||
       ((*(byte *)(*(longlong *)(lVar3 + 0x208) + 9) & 0xf0) != 0x10)) goto LAB_140014a11;
  }
  *(uint *)(lVar3 + 0x250) = *(uint *)(lVar3 + 0x250) | 0x100;
LAB_140014a11:
  uVar2 = *(undefined4 *)(lVar3 + 0x250);
  ClassReadDriveCapacity(param_1);
  if (*(int *)(lVar3 + 0x23c) == 0) {
    *(undefined4 *)(lVar3 + 0x23c) = 0x200;
    *(undefined1 *)(lVar3 + 0x282) = 9;
  }
  DiskCreateSymbolicLinks(param_1);
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeInitializeEvent(&local_38,1,0);
  lVar8 = IoBuildDeviceIoControlRequest
                    (0x41018,*(undefined8 *)(lVar3 + 0x10),0,0,lVar4 + 8,8,0,&local_38,&local_48);
  if ((lVar8 != 0) && (iVar7 = IofCallDriver(*(undefined8 *)(lVar3 + 0x10),lVar8), iVar7 == 0x103))
  {
    KeWaitForSingleObject(&local_38,0,0,0,0);
  }
  pcVar5 = InitSafeBootMode_exref;
  *(undefined4 *)(lVar4 + 0x10) = 0;
  if (((*(int *)pcVar5 == 0) && (*(int *)(*(longlong *)(lVar3 + 0x208) + 0x1c) != 0x14)) &&
     (lVar8 = IoAllocateWorkItem(param_1), lVar8 != 0)) {
    IoQueueWorkItem(lVar8,DiskInitializeFailurePrediction,1,lVar8);
  }
  KeInitializeMutex(lVar4 + 0x38);
  _Dst = (void *)(lVar4 + 0x70);
  memset(_Dst,0,0x198);
  lVar8 = lVar4 + 0x88;
  *(void **)(lVar4 + 0x78) = _Dst;
  *(void **)_Dst = _Dst;
  *(longlong *)(lVar4 + 0x90) = lVar8;
  *(longlong *)lVar8 = lVar8;
  KeInitializeSpinLock(lVar4 + 0x1d8);
  KeInitializeEvent(lVar4 + 0x1e0,1);
  uVar9 = IoAllocateIrp(*(char *)(param_1 + 0x4c) + '\x03',0);
  *(undefined8 *)(lVar4 + 0x1f8) = uVar9;
  *(undefined1 *)(lVar4 + 0x200) = 0;
  *(undefined4 *)(lVar3 + 0x250) = uVar2;
  return 0;
}



===== DiskLogDuplicateGuidEvent @ 140014c00 =====

void DiskLogDuplicateGuidEvent(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)IoAllocateErrorLogEntry(*(undefined8 *)(param_1 + 8),0x46);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)((longlong)puVar1 + 0xc) = 0x8004009e;
    *puVar1 = 0x1b;
    uVar2 = RtlStringCbPrintfW((wchar_t *)(puVar1 + 6),0x16,L"%d",
                               (ulonglong)*(uint *)(param_1 + 0x24c));
    if (-1 < (int)uVar2) {
      *(short *)((longlong)puVar1 + 4) = *(short *)((longlong)puVar1 + 4) + 1;
      *(undefined2 *)((longlong)puVar1 + 6) = 0x30;
    }
    IoWriteErrorLogEntry(puVar1);
  }
  return;
}



===== DiskRemoveDevice @ 140014c90 =====

undefined8 DiskRemoveDevice(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  int *piVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(lVar1 + 0x60);
  if ((param_2 - 1U & 0xfd) != 0) {
    if (*(longlong *)(lVar1 + 0x2c0) != 0) {
      ZwMakeTemporaryObject();
      ZwClose(*(undefined8 *)(lVar1 + 0x2c0));
      *(undefined8 *)(lVar1 + 0x2c0) = 0;
    }
    if (param_2 == '\x02') {
      if (*(longlong *)(lVar1 + 0x240) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar1 + 0x240),0);
        *(undefined8 *)(lVar1 + 0x240) = 0;
      }
      piVar3 = (int *)IoGetConfigurationInformation();
      *piVar3 = *piVar3 + -1;
      if (*(longlong *)(lVar2 + 0x1f8) != 0) {
        IoFreeIrp();
        *(undefined8 *)(lVar2 + 0x1f8) = 0;
      }
    }
    DiskDeleteSymbolicLinks(param_1);
    if (param_2 == '\x02') {
      ClassDeleteSrbLookasideList(lVar1);
    }
  }
  return 0;
}



===== DiskStartFdo @ 140014d90 =====

undefined8 DiskStartFdo(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  int local_res8 [2];
  undefined8 local_res10;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined1 local_58 [8];
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_48 = 0;
  local_30 = 0;
  lVar3 = *(longlong *)(lVar2 + 0x60);
  uVar9 = 1;
  local_res10 = 0;
  local_res8[0] = 0;
  local_58 = (undefined1  [8])0x0;
  uStack_50 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_68 = 0;
  uStack_60 = 0;
  KeInitializeEvent(&local_40,1,0);
  lVar6 = IoBuildDeviceIoControlRequest(0x2d0c14,param_1,0,0,&local_res10,8,0,&local_40,&local_68);
  if (lVar6 != 0) {
    iVar5 = IofCallDriver(param_1,lVar6);
    if (iVar5 == 0x103) {
      KeWaitForSingleObject(&local_40,0,0,0,0);
    }
  }
  *(ushort *)(lVar2 + 0x280) = *(ushort *)(lVar2 + 0x280) & 0xfffe;
  if ((((*(ushort *)(lVar2 + 0x280) & 1) == 0) || ((*(ushort *)(lVar2 + 0x280) & 0x10) != 0)) ||
     ((char)*(undefined4 *)(lVar2 + 0x36c) < '\0')) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  piVar1 = (int *)(lVar3 + 0x208);
  *(undefined1 *)(lVar2 + 0x283) = uVar4;
  *piVar1 = -1;
  ClassGetDeviceParameter(lVar2,L"Disk",L"UserWriteCacheSetting",piVar1);
  if (*piVar1 == -1) {
    if ((*(uint *)(lVar2 + 0x36c) & 0x10) == 0) {
      if ((local_res10._6_1_ == '\0') || (local_res10._7_1_ != '\0')) {
        if (local_res10._5_1_ == '\0') goto LAB_140014f8a;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar8 = 0x19;
          goto LAB_140014f74;
        }
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x18;
        goto LAB_140014f74;
      }
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar8 = 0x17;
LAB_140014f74:
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
               &WPP_05abe5c235553bdb89a3b8ecfd575366_Traceguids,param_1);
    }
    *piVar1 = 0;
  }
LAB_140014f8a:
  uVar7 = DiskGetCacheInformation(lVar2,local_58);
  if (-1 < (int)uVar7) {
    if (local_58[2] == '\x01') {
      *(ushort *)(lVar2 + 0x280) = *(ushort *)(lVar2 + 0x280) | 1;
      if ((((*(ushort *)(lVar2 + 0x280) & 1) == 0) || ((*(ushort *)(lVar2 + 0x280) & 0x10) != 0)) ||
         ((char)*(undefined4 *)(lVar2 + 0x36c) < '\0')) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
      *(undefined1 *)(lVar2 + 0x283) = uVar4;
      if (*piVar1 != 0) goto LAB_140015003;
      local_58[2] = 0;
    }
    else {
      if (*(int *)(lVar3 + 0x208) != 1) goto LAB_140015003;
      local_58[2] = 1;
    }
    DiskSetCacheInformation(lVar2,local_58);
  }
LAB_140015003:
  *(ushort *)(lVar2 + 0x280) = *(ushort *)(lVar2 + 0x280) & 0xffef;
  ClassGetDeviceParameter(lVar2,L"Disk",L"CacheIsPowerProtected",local_res8);
  if (local_res8[0] == 1) {
    *(ushort *)(lVar2 + 0x280) = *(ushort *)(lVar2 + 0x280) | 0x10;
  }
  if ((((*(ushort *)(lVar2 + 0x280) & 1) == 0) || ((*(ushort *)(lVar2 + 0x280) & 0x10) != 0)) ||
     ((char)*(undefined4 *)(lVar2 + 0x36c) < '\0')) {
    uVar9 = 0;
  }
  *(undefined1 *)(lVar2 + 0x283) = uVar9;
  return 0;
}



===== DiskDetectFailurePrediction @ 1400150a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskDetectFailurePrediction(longlong param_1,undefined4 *param_2,char param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  char *pcVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined1 auStackY_288 [32];
  char local_248 [8];
  undefined8 local_240;
  int local_238 [132];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_288;
  lVar1 = *(longlong *)(param_1 + 0x60);
  local_248[0] = '\0';
  uVar6 = 0x204;
  memset(local_238,0,0x204);
  local_240 = 0;
  *param_2 = 0;
  if ((param_3 == '\0') || (DiskGetIdentifyInfo(param_1,local_248), local_248[0] == '\0')) {
    uVar2 = DiskSendFailurePredictIoctl(param_1,local_238);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      pcVar4 = "does";
      if ((int)uVar2 < 0) {
        pcVar4 = "does not";
      }
      WPP_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,WPP_GLOBAL_Control,
                *(undefined8 *)(param_1 + 8),pcVar4);
    }
    if ((int)uVar2 < 0) {
      *param_2 = 0;
      DiskInfoExceptionCheck(param_1);
      uVar5 = 0;
    }
    else {
      *param_2 = 1;
      *(undefined1 *)(lVar1 + 0x16) = 1;
      if (local_238[0] != 0) {
        local_238[0] = 0x200;
        ClassNotifyFailurePredicted(param_1,local_238,0x204,*(char *)(param_1 + 0x333) == '\0');
        *(undefined1 *)(param_1 + 0x333) = 1;
      }
      uVar5 = (ulonglong)uVar2;
    }
    return uVar5;
  }
  uVar2 = DiskEnableSmart(param_1);
  uVar5 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    *param_2 = 2;
    *(undefined1 *)(lVar1 + 0x16) = 1;
    uVar3 = DiskReadFailurePredictStatus(param_1,(undefined4 *)&local_240);
    uVar5 = uVar3 & 0xffffffff;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      pcVar4 = "does";
      if ((int)uVar3 < 0) {
        pcVar4 = "does not";
      }
      WPP_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,uVar6,*(undefined8 *)(param_1 + 8),
                pcVar4);
    }
    if ((int)uVar3 < 0) {
      *param_2 = 0;
      *(undefined1 *)(lVar1 + 0x16) = 0;
    }
  }
  return uVar5;
}



===== DiskGetIdentifyInfo @ 1400152a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskGetIdentifyInfo(longlong param_1,char *param_2)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined1 auStackY_298 [32];
  uint local_258 [4];
  int local_248 [52];
  ushort local_178;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_298;
  uVar3 = 0x22c;
  memset(local_248,0,0x22c);
  local_258[0] = 0x22c;
  uVar3 = CONCAT71((int7)((ulonglong)uVar3 >> 8),0xec);
  uVar2 = DiskPerformSmartCommand(param_1,0x1b0501,0xec,0,0,0,local_248,local_258);
  if ((((int)uVar2 < 0) || (0xfffd < (ushort)(local_178 - 1))) || ((local_178 & 1) == 0)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  *param_2 = cVar1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    pcVar4 = "is";
    if (cVar1 == '\0') {
      pcVar4 = "is not";
    }
    WPP_SF_sqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,uVar3,pcVar4,
               (char)*(undefined8 *)(param_1 + 8),(char)uVar2);
  }
  return uVar2 & 0xffffffff;
}



===== DiskIoctlPredictFailure @ 1400153c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskIoctlPredictFailure(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined8 *puVar14;
  undefined1 auStackY_f8 [32];
  undefined1 uVar15;
  undefined8 local_90;
  longlong local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar11 = *(longlong *)(param_2 + 0xb8);
  local_90 = 0;
  lVar3 = *(longlong *)(lVar2 + 0x60);
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  bVar5 = KeGetCurrentIrql();
  if (bVar5 < 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
    }
    if (*(uint *)(lVar11 + 8) < 0x204) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      uVar9 = 0xc0000023;
    }
    else {
      puVar4 = *(uint **)(param_2 + 0x18);
      if (*(int *)(lVar3 + 0x10) == 3) {
        *puVar4 = 0;
        KeInitializeEvent(&local_80,1);
        puVar10 = (undefined8 *)IoGetAttachedDeviceReference(param_1);
        uVar1 = *(undefined4 *)(lVar2 + 0x23c);
        local_88 = ExAllocatePool2(0x40,uVar1,0x61446353);
        if (local_88 == 0) {
          ObfDereferenceObject(puVar10);
          return 0xc000009a;
        }
        puVar12 = &local_80;
        lVar11 = IoBuildSynchronousFsdRequest(3,puVar10,local_88,uVar1);
        if (lVar11 == 0) {
          uVar9 = 0xc000009a;
        }
        else {
          uVar15 = (undefined1)lVar11;
          if (DiskETWEnabled != '\0') {
            puVar14 = &local_58;
            lVar13 = param_2;
            iVar7 = IoGetActivityIdIrp();
            if (-1 < iVar7) {
              puVar14 = &local_58;
              lVar13 = lVar11;
              IoSetActivityIdIrp();
            }
            if ((Microsoft_Windows_DiskEnableBits & 4) != 0) {
              McTemplateK0qpuxi_EtwWriteTransfer
                        (lVar13,puVar14,&local_58,*(undefined4 *)(lVar2 + 0x24c),uVar15,puVar12,
                         (char)uVar1,0);
            }
          }
          puVar12 = puVar10;
          uVar6 = IofCallDriver();
          if (uVar6 == 0x103) {
            puVar12 = &local_80;
            lVar11 = 0;
            KeWaitForSingleObject(puVar12,0,0,0);
            uVar6 = (uint)local_68;
          }
          uVar9 = (ulonglong)uVar6;
          if ((DiskETWEnabled != '\0') && ((DAT_14000c2c1 & 1) != 0)) {
            McTemplateK0qpduuuuu_EtwWriteTransfer
                      (puVar12,lVar11,&local_58,*(undefined4 *)(lVar2 + 0x24c),uVar15,(char)uVar6);
          }
        }
        ExFreePoolWithTag(local_88,0);
        ObfDereferenceObject(puVar10);
        if ((int)uVar9 == -0x3fffff66) {
          return uVar9;
        }
      }
      if (*(int *)(lVar3 + 0x10) - 2U < 2) {
        uVar8 = DiskReadFailurePredictStatus(lVar2,(undefined4 *)&local_90);
        uVar9 = uVar8 & 0xffffffff;
        if (-1 < (int)uVar8) {
          uVar9 = DiskReadFailurePredictData(lVar2,*(undefined4 **)(param_2 + 0x18));
          uVar9 = uVar9 & 0xffffffff;
          *puVar4 = (uint)(local_90._4_1_ != '\0');
          *(undefined8 *)(param_2 + 0x38) = 0x204;
        }
      }
      else {
        uVar9 = 0xc0000010;
      }
    }
  }
  else {
    uVar9 = 0xc0000148;
  }
  return uVar9;
}



===== DiskReadFailurePredictStatus @ 140015770 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskReadFailurePredictStatus(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  undefined1 auStackY_98 [32];
  uint local_58 [2];
  int local_50 [11];
  char cStack_21;
  undefined8 local_20;
  undefined4 local_18;
  undefined1 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar2 = *(longlong *)(param_1 + 0x60);
  *(undefined1 *)(param_2 + 1) = 0;
  iVar1 = *(int *)(lVar2 + 0x10);
  if (iVar1 == 2) {
    local_58[0] = 0x3d;
    local_50[0] = 0;
    local_50[1] = 0;
    local_50[2] = 0;
    local_50[3] = 0;
    local_50[4] = 0;
    local_50[5] = 0;
    local_50[6] = 0;
    local_50[7] = 0;
    local_50[8] = 0;
    local_50[9] = 0;
    stack0xffffffffffffffd8 = 0;
    local_20 = 0;
    local_18 = 0;
    local_14 = 0;
    uVar3 = DiskPerformSmartCommand(param_1,0x1b0506,0xb0,0xda,0,0,local_50,local_58);
    if (-1 < (int)uVar3) {
      *param_2 = 0;
      if ((cStack_21 == -0xc) && ((char)local_20 == ',')) {
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
      *(undefined1 *)(param_2 + 1) = uVar4;
      uVar3 = uVar3 & 0xffffffff;
    }
  }
  else if (((iVar1 == 0) || (iVar1 == 1)) || (iVar1 != 3)) {
    uVar3 = 0xc0000010;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x334);
    *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_1 + 0x333);
    uVar3 = 0;
  }
  return uVar3;
}



===== DiskReadFailurePredictData @ 140015870 =====

ulonglong DiskReadFailurePredictData(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  int *piVar7;
  undefined8 *puVar8;
  uint local_res8 [2];
  
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x60) + 0x10);
  if (iVar1 == 2) {
    local_res8[0] = 0x22c;
    piVar3 = (int *)ExAllocatePool2(0x40,0x22c,0x61446353);
    if (piVar3 == (int *)0x0) {
      uVar6 = 0xc000009a;
    }
    else {
      uVar4 = DiskPerformSmartCommand(param_1,0x1b0502,0xb0,0xd0,0,0,piVar3,local_res8);
      uVar6 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        *param_2 = 0x200;
        lVar5 = 4;
        piVar7 = piVar3 + 0xb;
        puVar8 = (undefined8 *)(param_2 + 1);
        do {
          uVar2 = *(undefined8 *)(piVar7 + 2);
          *puVar8 = *(undefined8 *)piVar7;
          puVar8[1] = uVar2;
          uVar2 = *(undefined8 *)(piVar7 + 6);
          puVar8[2] = *(undefined8 *)(piVar7 + 4);
          puVar8[3] = uVar2;
          uVar2 = *(undefined8 *)(piVar7 + 10);
          puVar8[4] = *(undefined8 *)(piVar7 + 8);
          puVar8[5] = uVar2;
          uVar2 = *(undefined8 *)(piVar7 + 0xe);
          puVar8[6] = *(undefined8 *)(piVar7 + 0xc);
          puVar8[7] = uVar2;
          uVar2 = *(undefined8 *)(piVar7 + 0x12);
          puVar8[8] = *(undefined8 *)(piVar7 + 0x10);
          puVar8[9] = uVar2;
          uVar2 = *(undefined8 *)(piVar7 + 0x16);
          puVar8[10] = *(undefined8 *)(piVar7 + 0x14);
          puVar8[0xb] = uVar2;
          uVar2 = *(undefined8 *)(piVar7 + 0x1a);
          puVar8[0xc] = *(undefined8 *)(piVar7 + 0x18);
          puVar8[0xd] = uVar2;
          uVar2 = *(undefined8 *)(piVar7 + 0x1e);
          puVar8[0xe] = *(undefined8 *)(piVar7 + 0x1c);
          puVar8[0xf] = uVar2;
          lVar5 = lVar5 + -1;
          piVar7 = piVar7 + 0x20;
          puVar8 = puVar8 + 0x10;
        } while (lVar5 != 0);
      }
      ExFreePoolWithTag(piVar3,0);
    }
  }
  else {
    if (((iVar1 != 0) && (iVar1 != 1)) && (iVar1 == 3)) {
      *param_2 = 4;
      param_2[1] = *(undefined4 *)(param_1 + 0x334);
      return 0;
    }
    uVar6 = 0xc0000010;
  }
  return uVar6;
}



===== DiskPerformSmartCommand @ 1400159c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DiskPerformSmartCommand
                    (longlong param_1,int param_2,undefined1 param_3,undefined1 param_4,
                    undefined1 param_5,undefined1 param_6,int *param_7,uint *param_8)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  undefined1 auStack_198 [32];
  undefined8 *local_178;
  undefined8 *local_170;
  ulonglong *local_168;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  ulonglong local_138 [2];
  undefined2 local_128;
  undefined1 local_126;
  undefined1 local_123;
  undefined1 local_122;
  undefined1 local_121;
  undefined2 local_120;
  uint local_11c;
  int local_118;
  int local_114;
  int *local_110;
  longlong local_f8;
  undefined2 local_c8;
  undefined1 local_c6;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_a8;
  undefined2 local_a4;
  undefined2 local_a2;
  int local_a0;
  undefined4 local_94;
  int local_8c;
  int *local_88;
  longlong local_78;
  undefined2 local_48;
  undefined4 local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_198;
  lVar2 = *(longlong *)(param_1 + 0x60);
  local_140 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_138[0] = 0;
  local_138[1] = 0;
  memset(&local_128,0,0x58);
  memset(&local_c8,0,0x90);
  uVar1 = *param_8;
  if (uVar1 < 0x1c) {
    uVar5 = 0xc0000023;
  }
  else {
    *param_7 = 0x1c;
    param_7[1] = 0x49534353;
    param_7[2] = 0x4b534944;
    param_7[3] = *(int *)(param_1 + 0x248);
    param_7[6] = uVar1 - 0x1c;
    param_7[4] = param_2;
    param_7[7] = 0x21;
    *(undefined1 *)(param_7 + 10) = *(undefined1 *)(lVar2 + 0xe);
    *(undefined1 *)((longlong)param_7 + 0x21) = param_5;
    *(undefined1 *)((longlong)param_7 + 0x22) = param_6;
    *(undefined1 *)(param_7 + 8) = param_4;
    *(undefined2 *)((longlong)param_7 + 0x23) = 0xc24f;
    *(undefined1 *)((longlong)param_7 + 0x26) = param_3;
    KeInitializeEvent(&local_150,0,0);
    local_168 = local_138;
    iVar6 = *param_7 + param_7[6];
    local_170 = &local_150;
    local_158 = 1;
    local_178 = &local_158;
    lVar4 = IoBuildSynchronousFsdRequest(0xf,*(undefined8 *)(param_1 + 0x10),param_7,iVar6);
    if (lVar4 == 0) {
      uVar5 = 0xc000009a;
    }
    else {
      lVar3 = *(longlong *)(lVar4 + 0xb8);
      *(undefined2 *)(lVar3 + -0x48) = 0x10f;
      if (*(char *)(*(longlong *)(param_1 + 0x210) + 0x1e) == '\x01') {
        *(undefined2 **)(lVar3 + -0x40) = &local_c8;
        local_c8 = 8;
        local_c6 = 0x28;
        local_c0 = 0x53524258;
        local_bc = 1;
        local_b8 = 0x90;
        local_b4 = 2;
        local_a4 = IoGetIoPriorityHint(lVar4);
        local_b0 = *(uint *)(param_1 + 0x250) | 0x100140;
        local_94 = 0x80;
        local_a2 = 0x20;
        local_a0 = param_7[3];
        local_a8 = 0xff;
        local_88 = param_7;
        local_48 = 1;
        local_44 = 4;
        local_40 = *(undefined1 *)(lVar2 + 0xd);
        local_3f = *(undefined1 *)(lVar2 + 0xe);
        local_121 = *(undefined1 *)(lVar2 + 0xf);
        local_8c = iVar6;
        local_78 = lVar4;
        local_3e = local_121;
      }
      else {
        *(undefined2 **)(lVar3 + -0x40) = &local_128;
        local_123 = *(undefined1 *)(lVar2 + 0xd);
        local_122 = *(undefined1 *)(lVar2 + 0xe);
        local_121 = *(undefined1 *)(lVar2 + 0xf);
        local_11c = *(uint *)(param_1 + 0x250) | 0x100140;
        local_126 = 2;
        local_114 = param_7[3];
        local_128 = 0x58;
        local_120 = 0x20ff;
        local_110 = param_7;
        local_118 = iVar6;
        local_f8 = lVar4;
      }
      KeFlushIoBuffers(*(undefined8 *)(lVar4 + 8),0,1);
      uVar5 = IofCallDriver(*(undefined8 *)(param_1 + 0x10),lVar4);
      if ((int)uVar5 == 0x103) {
        local_178 = (undefined8 *)0x0;
        KeWaitForSingleObject(&local_150,0,0,0);
        uVar5 = local_138[0] & 0xffffffff;
      }
    }
  }
  return uVar5;
}



===== DiskIoctlIsWritable @ 140015cd0 =====

uint DiskIoctlIsWritable(undefined8 param_1,undefined1 param_2)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    return 0xc0000148;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,param_2);
  }
  lVar3 = ExAllocatePool2(0x48,0xc0,0x4d446353);
  if (lVar3 != 0) {
    iVar2 = ClassModeSense(param_1,lVar3,0xc0,0x3f);
    if (iVar2 == 0) {
      uVar4 = 0xc0000001;
    }
    else {
      uVar4 = (int)*(char *)(lVar3 + 2) >> 7 & 0xc00000a2;
    }
    ExFreePoolWithTag(lVar3,0);
    return uVar4;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
            &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
  }
  return 0xc000009a;
}



===== DiskIoctlSmartReceiveDriveData @ 140015e20 =====

int DiskIoctlSmartReceiveDriveData(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  int iVar6;
  uint *puVar7;
  longlong lVar8;
  undefined2 uVar9;
  uint uVar10;
  ulonglong uVar11;
  size_t _Size;
  uint uVar12;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar8 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_2 + 0x18);
  lVar4 = *(longlong *)(lVar2 + 0x60);
  local_58 = 0;
  uStack_50 = 0;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  bVar5 = KeGetCurrentIrql();
  if (1 < bVar5) {
    return -0x3ffffeb8;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  if (*(uint *)(lVar8 + 0x10) < 0x20) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    uVar9 = 0x6b;
    goto LAB_14001626f;
  }
  if (*(uint *)(lVar8 + 8) < 0x210) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffdd;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return -0x3fffffdd;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3fffffdd;
    }
    uVar9 = 0x6c;
LAB_14001618f:
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
            &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    return -0x3fffffdd;
  }
  KeInitializeEvent(&local_48,0,0);
  if (*(char *)(lVar3 + 10) == -0x14) {
    uVar12 = 0x1b0501;
  }
  else {
    if (*(char *)(lVar3 + 10) != -0x50) {
LAB_140016251:
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffff3;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        return -0x3ffffff3;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return -0x3ffffff3;
      }
      uVar9 = 0x6f;
LAB_14001626f:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      return -0x3ffffff3;
    }
    cVar1 = *(char *)(lVar3 + 4);
    if (cVar1 == -0x30) {
      uVar12 = 0x1b0502;
    }
    else {
      if (cVar1 != -0x2f) {
        if (cVar1 == -0x2b) {
          if (*(int *)(lVar4 + 0x10) != 2) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                      &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
            }
            return -0x3ffffff0;
          }
          iVar6 = (uint)*(byte *)(lVar3 + 5) * 0x200;
          if (*(byte *)(lVar3 + 5) == 0) {
            return -0x3ffffff3;
          }
          uVar10 = iVar6 + 0x21;
          if (*(uint *)(lVar8 + 8) < iVar6 + 0x20U) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return -0x3fffffdd;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
              return -0x3fffffdd;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
              return -0x3fffffdd;
            }
            uVar9 = 0x6e;
            goto LAB_14001618f;
          }
          uVar12 = 0x1b050b;
          goto LAB_140015ee3;
        }
        goto LAB_140016251;
      }
      uVar12 = 0x1b0503;
    }
  }
  uVar10 = 0x211;
LAB_140015ee3:
  puVar7 = (uint *)ExAllocatePool2(0x40,uVar10 + 0x1c,0x61446353);
  if (puVar7 == (uint *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    iVar6 = -0x3fffff66;
  }
  else {
    *puVar7 = 0x1c;
    puVar7[1] = 0x49534353;
    puVar7[2] = 0x4b534944;
    puVar7[3] = *(uint *)(lVar2 + 0x248);
    puVar7[6] = uVar10;
    puVar7[4] = uVar12;
    *(undefined1 *)(lVar3 + 0xc) = *(undefined1 *)(lVar4 + 0xe);
    memmove(puVar7 + 7,*(void **)(param_2 + 0x18),0x20);
    lVar8 = IoBuildDeviceIoControlRequest
                      (0x4d008,*(undefined8 *)(lVar2 + 0x10),puVar7,0x3c,puVar7,uVar10 + 0x1c,0,
                       &local_48,&local_58);
    if (lVar8 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      ExFreePoolWithTag(puVar7,0);
      iVar6 = -0x3fffff66;
    }
    else {
      iVar6 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10),lVar8);
      if (iVar6 == 0x103) {
        KeWaitForSingleObject(&local_48,0,0,0,0);
        iVar6 = (int)local_58;
      }
      if (iVar6 < 0) {
        uVar11 = 0x10;
        _Size = 0x10;
      }
      else {
        uVar11 = (ulonglong)(uVar10 - 1);
        _Size = (size_t)(uVar10 - 1);
      }
      memmove(*(void **)(param_2 + 0x18),(void *)((ulonglong)*puVar7 + (longlong)puVar7),_Size);
      *(ulonglong *)(param_2 + 0x38) = uVar11;
      ExFreePoolWithTag(puVar7,0);
    }
  }
  return iVar6;
}



===== DiskIoctlGetMediaTypesEx @ 140016290 =====

ulonglong DiskIoctlGetMediaTypesEx(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 *puVar5;
  byte extraout_var;
  longlong lVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  ulonglong uVar9;
  char cVar10;
  ulonglong in_stack_ffffffffffffffc8;
  
  lVar6 = *(longlong *)(param_1 + 0x40);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  cVar10 = '\0';
  bVar2 = KeGetCurrentIrql();
  if (bVar2 < 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      in_stack_ffffffffffffffc8 = param_2;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
    }
    if (*(uint *)(lVar1 + 8) < 0x28) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      uVar9 = 0xc0000023;
    }
    else {
      uVar7 = 0xb8;
      if (*(char *)(*(longlong *)(lVar6 + 0x210) + 0x1e) != '\x01') {
        uVar7 = 0x58;
      }
      puVar5 = (undefined2 *)ExAllocatePool2(0x40,uVar7,0x53446353);
      if (puVar5 == (undefined2 *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                  &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
        }
        uVar9 = 0xc000009a;
      }
      else {
        if (*(char *)(*(longlong *)(lVar6 + 0x210) + 0x1e) == '\x01') {
          *puVar5 = 8;
          *(undefined4 *)(puVar5 + 6) = 1;
          *(undefined1 *)(puVar5 + 1) = 0x28;
          *(undefined4 *)(puVar5 + 4) = 0x53524258;
          *(undefined4 *)(puVar5 + 8) = uVar7;
          *(undefined4 *)(puVar5 + 10) = 0;
          uVar3 = IoGetIoPriorityHint(param_2);
          puVar5[0x12] = uVar3;
          *(undefined4 *)(puVar5 + 0x1a) = 0x80;
          *(undefined4 *)(puVar5 + 0x1c) = 1;
          *(undefined4 *)(puVar5 + 0x14) = *(undefined4 *)(lVar6 + 0x248);
          puVar5[0x40] = 1;
          *(undefined4 *)(puVar5 + 0x42) = 4;
          *(undefined4 *)(puVar5 + 0x3c) = 0x90;
          if (*(uint *)(puVar5 + 8) < 0xb8) {
            ExFreePoolWithTag(puVar5,0);
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                      &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
            }
            return 0xc00000e5;
          }
          *(undefined4 *)(puVar5 + 0x48) = 0x40;
          puVar8 = puVar5 + 0x54;
          *(undefined4 *)(puVar5 + 0x4a) = 0x20;
          *(undefined1 *)(puVar5 + 0x4d) = 6;
        }
        else {
          *puVar5 = 0x58;
          puVar8 = puVar5 + 0x24;
          *(undefined1 *)(puVar5 + 1) = 0;
          *(undefined1 *)(puVar5 + 5) = 6;
          *(undefined4 *)(puVar5 + 10) = *(undefined4 *)(lVar6 + 0x248);
        }
        *(undefined1 *)puVar8 = 0;
        ClassSendSrbSynchronous(param_1,puVar5,0,0,in_stack_ffffffffffffffc8 & 0xffffffffffffff00);
        lVar6 = ExAllocatePool2(0x48,0xc0,0x4d446353);
        if (lVar6 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                    &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
          }
          ExFreePoolWithTag(puVar5,0);
          uVar9 = 0xc000009a;
        }
        else {
          iVar4 = ClassModeSense(param_1,lVar6,0xc0,0x3f);
          if (iVar4 == 0) {
            uVar9 = 0xc0000001;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                      &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
            }
          }
          else {
            if (*(char *)(lVar6 + 3) != '\0') {
              cVar10 = *(char *)(lVar6 + 4);
            }
            uVar9 = DiskDetermineMediaTypes
                              (param_1,param_2,*(char *)(lVar6 + 1),cVar10,extraout_var >> 7 ^ 1,
                               (byte)~*(byte *)(lVar6 + 2) >> 7);
            uVar9 = uVar9 & 0xffffffff;
          }
          ExFreePoolWithTag(puVar5,0);
          ExFreePoolWithTag(lVar6,0);
        }
      }
    }
  }
  else {
    uVar9 = 0xc0000148;
  }
  return uVar9;
}



===== DiskDetermineMediaTypes @ 140016690 =====

undefined8
DiskDetermineMediaTypes
          (longlong param_1,longlong param_2,char param_3,char param_4,char param_5,char param_6)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char *_Str2;
  ulonglong uVar11;
  undefined8 *puVar12;
  char *_Str2_00;
  char *_MaxCount;
  char *_Str2_01;
  uint uVar13;
  ulonglong uVar14;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  bVar6 = false;
  puVar2 = *(undefined4 **)(param_2 + 0x18);
  lVar3 = *(longlong *)(param_1 + 0x40);
  puVar12 = (undefined8 *)(puVar2 + 2);
  if ((*(uint *)(param_1 + 0x34) & 1) == 0) {
    *puVar2 = 7;
    puVar2[1] = 1;
    *puVar12 = *(undefined8 *)(lVar3 + 0x228);
    puVar2[4] = 0xc;
    puVar2[5] = *(undefined4 *)(lVar3 + 0x234);
    puVar2[6] = *(undefined4 *)(lVar3 + 0x238);
    puVar2[7] = *(undefined4 *)(lVar3 + 0x23c);
    puVar2[8] = 1;
    puVar2[9] = 0x80000008;
    if (param_6 == '\0') {
      puVar2[9] = 0x80000108;
    }
  }
  else {
    lVar4 = *(longlong *)(lVar3 + 0x208);
    _Str2 = (char *)((ulonglong)*(uint *)(lVar4 + 0xc) + lVar4);
    _Str2_00 = (char *)((ulonglong)*(uint *)(lVar4 + 0x10) + lVar4);
    _Str2_01 = (char *)((ulonglong)*(uint *)(lVar4 + 0x14) + lVar4);
    _MaxCount = _Str2_00;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_ss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),_Str2,_Str2_00,_Str2,_Str2_00);
    }
    uVar14 = 0;
    while( true ) {
      uVar13 = 8;
      pcVar5 = (&DiskMediaTypesExclude)[uVar14 * 6];
      if (pcVar5 == (char *)0x0) break;
      _MaxCount = (char *)0xffffffffffffffff;
      do {
        _MaxCount = _MaxCount + 1;
      } while (pcVar5[(longlong)_MaxCount] != '\0');
      iVar7 = strncmp(pcVar5,_Str2,(size_t)_MaxCount);
      if (iVar7 == 0) {
        pcVar5 = (&PTR_s_RDX_140009218)[uVar14 * 6];
        if (pcVar5 == (char *)0x0) goto LAB_140016a2d;
        _MaxCount = (char *)0xffffffffffffffff;
        do {
          _MaxCount = _MaxCount + 1;
        } while (pcVar5[(longlong)_MaxCount] != '\0');
        iVar7 = strncmp(pcVar5,_Str2_00,(size_t)_MaxCount);
        if (iVar7 == 0) goto LAB_140016a2d;
      }
      uVar14 = (ulonglong)((int)uVar14 + 1);
    }
    for (uVar14 = 0; pcVar5 = (&DiskMediaTypes)[uVar14 * 6], pcVar5 != (char *)0x0;
        uVar14 = (ulonglong)((int)uVar14 + 1)) {
      _MaxCount = (char *)0xffffffffffffffff;
      do {
        _MaxCount = _MaxCount + 1;
      } while (pcVar5[(longlong)_MaxCount] != '\0');
      iVar7 = strncmp(pcVar5,_Str2,(size_t)_MaxCount);
      if (iVar7 == 0) {
        pcVar5 = (&PTR_s_PD_1_LF_1094_140009008)[uVar14 * 6];
        if (pcVar5 != (char *)0x0) {
          _MaxCount = (char *)0xffffffffffffffff;
          do {
            _MaxCount = _MaxCount + 1;
          } while (pcVar5[(longlong)_MaxCount] != '\0');
          iVar7 = strncmp(pcVar5,_Str2_00,(size_t)_MaxCount);
          if (iVar7 != 0) goto LAB_1400169e0;
        }
        pcVar5 = (char *)(&DAT_140009010)[uVar14 * 6];
        if (pcVar5 != (char *)0x0) {
          _MaxCount = (char *)0xffffffffffffffff;
          do {
            _MaxCount = _MaxCount + 1;
          } while (pcVar5[(longlong)_MaxCount] != '\0');
          iVar7 = strncmp(pcVar5,_Str2_01,(size_t)_MaxCount);
          if (iVar7 != 0) goto LAB_1400169e0;
        }
        bVar6 = true;
        *puVar2 = 7;
        puVar2[1] = (&DAT_140009018)[uVar14 * 0xc];
        if (*(uint *)(lVar1 + 8) < (&DAT_140009018)[uVar14 * 0xc] * 0x20 + 8U) {
          *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
          return 0xc0000023;
        }
        uVar11 = 0;
        if ((&DAT_140009018)[uVar14 * 0xc] != 0) {
          do {
            *puVar12 = *(undefined8 *)(lVar3 + 0x228);
            *(undefined4 *)((longlong)puVar12 + 0xc) = *(undefined4 *)(lVar3 + 0x234);
            *(undefined4 *)(puVar12 + 2) = *(undefined4 *)(lVar3 + 0x238);
            *(undefined4 *)((longlong)puVar12 + 0x14) = *(undefined4 *)(lVar3 + 0x23c);
            *(undefined4 *)(puVar12 + 3) = (&DAT_14000901c)[uVar14 * 0xc];
            uVar10 = (&DAT_140009020)[uVar14 * 0xc + uVar11];
            _MaxCount = (char *)(ulonglong)uVar10;
            *(uint *)(puVar12 + 1) = uVar10;
            uVar8 = 2;
            if (uVar10 != 0x3a) {
              uVar8 = 8;
            }
            *(uint *)((longlong)puVar12 + 0x1c) = uVar8;
            if (param_5 != '\0') {
              if (param_3 == '\x02') {
                uVar9 = 0x3a;
              }
              else {
                if (param_3 != '\x03') {
                  uVar8 = uVar8 | 0x80000000;
                  *(uint *)((longlong)puVar12 + 0x1c) = uVar8;
                  goto LAB_1400169bf;
                }
                uVar9 = 0x41;
                if (param_4 != -0x79) {
                  uVar9 = 0x3b;
                }
              }
              if (uVar10 == uVar9) {
                uVar8 = uVar8 | 0x80000000;
                *(uint *)((longlong)puVar12 + 0x1c) = uVar8;
              }
            }
LAB_1400169bf:
            if (param_6 == '\0') {
              *(uint *)((longlong)puVar12 + 0x1c) = uVar8 | 0x100;
            }
            puVar12 = puVar12 + 4;
            uVar10 = (int)uVar11 + 1;
            uVar11 = (ulonglong)uVar10;
          } while (uVar10 < (uint)(&DAT_140009018)[uVar14 * 0xc]);
        }
      }
LAB_1400169e0:
    }
    if (!bVar6) {
LAB_140016a2d:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_sss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),_Str2,_MaxCount,_Str2,_Str2_00,
                   _Str2_01);
      }
      *puVar2 = 7;
      puVar2[1] = 1;
      *puVar12 = *(undefined8 *)(lVar3 + 0x228);
      *(undefined4 *)(puVar12 + 1) = 0xb;
      *(undefined4 *)((longlong)puVar12 + 0xc) = *(undefined4 *)(lVar3 + 0x234);
      *(undefined4 *)(puVar12 + 2) = *(undefined4 *)(lVar3 + 0x238);
      *(undefined4 *)((longlong)puVar12 + 0x14) = *(undefined4 *)(lVar3 + 0x23c);
      *(undefined4 *)(puVar12 + 3) = 1;
      *(undefined4 *)((longlong)puVar12 + 0x1c) = 8;
      if (param_5 != '\0') {
        uVar13 = 0x80000008;
        *(undefined4 *)((longlong)puVar12 + 0x1c) = 0x80000008;
      }
      if (param_6 == '\0') {
        *(uint *)((longlong)puVar12 + 0x1c) = uVar13 | 0x100;
      }
    }
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)(uint)puVar2[1] * 0x20 + 8;
  return 0;
}



===== DiskFdoQueryWmiDataBlock @ 140016b00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DiskFdoQueryWmiDataBlock
               (longlong param_1,undefined8 param_2,undefined8 param_3,uint param_4,byte *param_5)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 auStackY_2a8 [32];
  undefined8 local_268;
  undefined4 local_260;
  int local_258;
  undefined4 local_254;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2a8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar3 = (int)param_3;
  lVar2 = *(longlong *)(lVar1 + 0x60);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqdLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,(char)param_2,
                 (char)param_3,(char)param_4,(char)param_5);
  }
  if (iVar3 == 3) {
    uVar6 = 0;
LAB_140016b65:
    uVar7 = 0;
  }
  else {
    if (iVar3 == 0) {
      uVar7 = 0x18;
      if (0x17 < param_4) {
        if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
          uVar4 = ClassReadDriveCapacity(*(undefined8 *)(*(longlong *)(lVar1 + 0x18) + 8));
          *(uint *)(lVar2 + 4) = uVar4;
          uVar6 = (ulonglong)uVar4;
          if ((int)uVar4 < 0) goto LAB_140016b67;
        }
        param_3 = 0x18;
        memmove(param_5,(void *)(lVar1 + 0x228),0x18);
        uVar6 = 0;
        goto LAB_140016b67;
      }
    }
    else if (iVar3 == 1) {
      uVar7 = 8;
      if (7 < param_4) {
        param_3 = 0x204;
        memset(&local_258,0,0x204);
        uVar4 = DiskSendFailurePredictIoctl(lVar1,&local_258);
        uVar6 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) {
          uVar5 = 0;
          if (*(int *)(lVar2 + 0x10) == 3) {
            uVar5 = local_254;
          }
          *(undefined4 *)param_5 = uVar5;
          param_5[4] = local_258 != 0;
        }
        goto LAB_140016b67;
      }
    }
    else if (iVar3 == 2) {
      uVar7 = 0x204;
      if (0x203 < param_4) {
        uVar4 = DiskSendFailurePredictIoctl(lVar1,param_5);
        uVar6 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) {
          param_5[0] = 0;
          param_5[1] = 2;
          param_5[2] = 0;
          param_5[3] = 0;
        }
        goto LAB_140016b67;
      }
    }
    else if (iVar3 == 5) {
      uVar7 = 0x200;
      if (0x1ff < param_4) {
        uVar6 = DiskReadFailurePredictThresholds(lVar1,(undefined8 *)param_5);
        uVar6 = uVar6 & 0xffffffff;
        goto LAB_140016b67;
      }
    }
    else {
      if (iVar3 != 6) {
        uVar6 = 0xc0000295;
        goto LAB_140016b65;
      }
      uVar7 = 0xc;
      local_268 = 0;
      local_260 = 0;
      if (0xb < param_4) {
        uVar4 = DiskGetInfoExceptionInformation(lVar1,&local_268);
        uVar6 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) {
          param_5[6] = local_268._5_1_;
          param_5[5] = local_268._6_1_;
          param_5[4] = local_268._7_1_;
          *param_5 = (byte)local_268 >> 7;
          param_5[0xb] = (byte)local_260;
          param_5[1] = local_268._2_1_;
          param_5[10] = local_260._1_1_;
          param_5[9] = local_260._2_1_;
          param_5[2] = local_268._3_1_ & 0xf;
          param_5[8] = local_260._3_1_;
          param_5[3] = 0;
          param_5[7] = local_268._4_1_;
        }
        goto LAB_140016b67;
      }
    }
    uVar6 = 0xc0000023;
  }
LAB_140016b67:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_3,param_1,(char)param_2,
               (char)uVar6);
  }
  ClassWmiCompleteRequest(param_1,param_2,uVar6,uVar7);
  return;
}



===== DiskSendFailurePredictIoctl @ 140016e20 =====

int DiskSendFailurePredictIoctl(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,1,0);
  uVar2 = IoGetAttachedDeviceReference(*(undefined8 *)(param_1 + 8));
  lVar3 = IoBuildDeviceIoControlRequest(0x2d1100,uVar2,0,0,param_2,0x204,0,&local_28,&local_38);
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(uVar2,lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar1 = (int)local_38;
    }
  }
  ObfDereferenceObject(uVar2);
  return iVar1;
}



===== DiskIoctlSmartGetVersion @ 140016f30 =====

ulonglong DiskIoctlSmartGetVersion(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  uint *puVar5;
  ulonglong uVar6;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar8;
  longlong lVar7;
  ulonglong local_28 [2];
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(lVar1 + 0x60);
  local_28[0] = 0;
  local_28[1] = 0;
  bVar4 = KeGetCurrentIrql();
  if (bVar4 < 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      lVar7 = param_2;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
      uVar8 = (undefined4)((ulonglong)lVar7 >> 0x20);
    }
    if (*(uint *)(lVar2 + 8) < 0x18) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      uVar6 = 0xc0000023;
    }
    else {
      puVar5 = (uint *)ExAllocatePool2(0x40,0x34,0x61446353);
      if (puVar5 == (uint *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                  &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
        }
        uVar6 = 0xc000009a;
      }
      else {
        *puVar5 = 0x1c;
        puVar5[1] = 0x49534353;
        puVar5[2] = 0x4b534944;
        puVar5[3] = *(uint *)(lVar1 + 0x248);
        puVar5[6] = 0x18;
        puVar5[4] = 0x1b0500;
        *(undefined1 *)((longlong)puVar5 + 0x1f) = *(undefined1 *)(lVar3 + 0xe);
        ClassSendDeviceIoControlSynchronous
                  (0x4d008,*(undefined8 *)(lVar1 + 0x10),puVar5,0x34,CONCAT44(uVar8,0x34),0,local_28
                  );
        uVar6 = local_28[0];
        if (-1 < (int)local_28[0]) {
          memmove(*(void **)(param_2 + 0x18),(void *)((ulonglong)*puVar5 + (longlong)puVar5),0x18);
          *(undefined8 *)(param_2 + 0x38) = 0x18;
        }
        ExFreePoolWithTag(puVar5,0);
        uVar6 = uVar6 & 0xffffffff;
      }
    }
  }
  else {
    uVar6 = 0xc0000148;
  }
  return uVar6;
}



===== DiskIoctlGetCacheInformation @ 140017140 =====

ulonglong DiskIoctlGetCacheInformation(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  byte *pbVar3;
  byte bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  pbVar3 = *(byte **)(param_2 + 0x18);
  bVar4 = KeGetCurrentIrql();
  if (bVar4 < 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
    }
    if (*(uint *)(lVar2 + 8) < 0x18) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      uVar6 = 0xc0000023;
    }
    else {
      uVar5 = DiskGetCacheInformation(lVar1,pbVar3);
      uVar6 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        *(undefined8 *)(param_2 + 0x38) = 0x18;
        if (pbVar3[2] == 0) {
          *(ushort *)(lVar1 + 0x280) = *(ushort *)(lVar1 + 0x280) & 0xfffe;
        }
        else {
          *(ushort *)(lVar1 + 0x280) = *(ushort *)(lVar1 + 0x280) | 1;
        }
        if ((((*(ushort *)(lVar1 + 0x280) & 1) == 0) || ((*(ushort *)(lVar1 + 0x280) & 0x10) != 0))
           || ((char)*(undefined4 *)(lVar1 + 0x36c) < '\0')) {
          *(undefined1 *)(lVar1 + 0x283) = 0;
        }
        else {
          *(undefined1 *)(lVar1 + 0x283) = 1;
        }
      }
    }
  }
  else {
    uVar6 = 0xc0000148;
  }
  return uVar6;
}



===== DiskGetCacheInformation @ 1400172b0 =====

undefined8 DiskGetCacheInformation(longlong param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  ulonglong uVar9;
  undefined2 uVar10;
  ushort uVar11;
  uint uVar12;
  byte bVar13;
  
  pbVar7 = (byte *)ExAllocatePool2(0x48,0xc0,0x43446353);
  if (pbVar7 == (byte *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    return 0xc000009a;
  }
  uVar6 = ClassModeSense(*(undefined8 *)(param_1 + 8),pbVar7,0xc0,8);
  if (uVar6 < 4) {
    uVar6 = ClassModeSense(*(undefined8 *)(param_1 + 8),pbVar7,0xc0,8);
    if (uVar6 < 4) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      ExFreePoolWithTag(pbVar7,0);
      return 0xc0000185;
    }
  }
  uVar12 = *pbVar7 + 1;
  if (uVar6 <= *pbVar7 + 1) {
    uVar12 = uVar6;
  }
  pbVar8 = (byte *)ClassFindModePage(pbVar7,uVar12,8,1);
  if (pbVar8 == (byte *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    ExFreePoolWithTag(pbVar7,0);
    return 0xc00000bb;
  }
  uVar9 = Feature_2022601018__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
    if (pbVar8 + 0xc <= pbVar7 + uVar12) goto LAB_1400174ee;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400174d3;
    uVar10 = 0x37;
  }
  else {
    if (0xb < (ulonglong)pbVar8[1] + 2) {
LAB_1400174ee:
      param_2[0] = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
      param_2[8] = 0;
      param_2[9] = 0;
      param_2[10] = 0;
      param_2[0xb] = 0;
      param_2[0xc] = 0;
      param_2[0xd] = 0;
      param_2[0xe] = 0;
      param_2[0xf] = 0;
      param_2[0x10] = 0;
      param_2[0x11] = 0;
      param_2[0x12] = 0;
      param_2[0x13] = 0;
      param_2[0x14] = 0;
      param_2[0x15] = 0;
      param_2[0x16] = 0;
      param_2[0x17] = 0;
      uVar9 = 2;
      *param_2 = *pbVar8 >> 7;
      bVar1 = pbVar8[2];
      param_2[1] = ~bVar1 & 1;
      bVar13 = pbVar8[2] >> 2 & 1;
      param_2[2] = bVar13;
      bVar5 = pbVar8[3] >> 4;
      if (bVar5 == 0xf) {
        uVar6 = 2;
      }
      else if (bVar5 == 2) {
        uVar6 = 0xf;
      }
      else {
        uVar6 = (uint)(pbVar8[3] >> 4);
      }
      *(uint *)(param_2 + 4) = uVar6;
      bVar5 = pbVar8[3];
      if ((bVar5 & 0xf) != 0xf) {
        if ((bVar5 & 0xf) == 2) {
          uVar9 = 0xf;
        }
        else {
          uVar9 = (ulonglong)(bVar5 & 0xf);
        }
      }
      *(int *)(param_2 + 8) = (int)uVar9;
      bVar2 = pbVar8[5];
      *(ushort *)(param_2 + 0xc) = CONCAT11(pbVar8[4],bVar2);
      bVar3 = pbVar8[7];
      *(ushort *)(param_2 + 0x10) = CONCAT11(pbVar8[6],bVar3);
      bVar4 = pbVar8[9];
      uVar11 = CONCAT11(pbVar8[8],bVar4);
      *(ushort *)(param_2 + 0x12) = uVar11;
      if ((pbVar8[2] & 2) != 0) {
        param_2[0xe] = 1;
        uVar11 = CONCAT11(pbVar8[10],pbVar8[0xb]);
        *(ushort *)(param_2 + 0x14) = uVar11;
      }
      if ((Microsoft_Windows_DiskEnableBits & 1) != 0) {
        McTemplateK0uuuuuhhhhq_EtwWriteTransfer
                  ((ulonglong)bVar5,(ulonglong)uVar11,uVar9,~bVar1 & 1,bVar13,(char)uVar6,
                   (char)uVar9,param_2[0xe],bVar2,bVar3,bVar4,(char)*(undefined2 *)(param_2 + 0x14),
                   (char)*(undefined4 *)(param_1 + 0x24c));
      }
      ExFreePoolWithTag(pbVar7,0);
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400174d3;
    uVar10 = 0x36;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
          &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
LAB_1400174d3:
  ExFreePoolWithTag(pbVar7,0);
  return 0xc0000001;
}



===== DiskIoctlSmartSendDriveCommand @ 140017690 =====

int DiskIoctlSmartSendDriveCommand(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  int iVar6;
  uint *puVar7;
  longlong lVar8;
  undefined2 uVar9;
  uint uVar10;
  size_t sVar11;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar8 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_2 + 0x18);
  lVar4 = *(longlong *)(lVar2 + 0x60);
  iVar6 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  bVar5 = KeGetCurrentIrql();
  if (1 < bVar5) {
    return -0x3ffffeb8;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  if (*(uint *)(lVar8 + 0x10) < 0x20) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar9 = 0x73;
LAB_140017acc:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
LAB_140017adc:
    iVar6 = -0x3ffffff3;
  }
  else {
    if (*(uint *)(lVar8 + 8) < 0x10) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffdd;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        return -0x3fffffdd;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return -0x3fffffdd;
      }
      uVar9 = 0x74;
LAB_140017884:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      return -0x3fffffdd;
    }
    KeInitializeEvent(&local_48,0,0);
    if (*(char *)(lVar3 + 10) != -0x50) goto switchD_140017800_caseD_d5;
    cVar1 = *(char *)(lVar3 + 4);
    if (cVar1 == -0x28) {
      uVar10 = 0x1b0504;
    }
    else if (cVar1 == -0x26) {
      if (*(uint *)(lVar8 + 8) < 0x18) {
        return -0x3fffffdd;
      }
      uVar10 = 0x1b0506;
      iVar6 = 8;
    }
    else {
      switch(cVar1) {
      case -0x2e:
        uVar10 = 0x1b0507;
        break;
      case -0x2d:
        uVar10 = 0x1b0508;
        break;
      case -0x2c:
        if (2 < *(byte *)(lVar3 + 6)) goto switchD_140017800_caseD_d5;
        uVar10 = 0x1b0509;
        break;
      default:
switchD_140017800_caseD_d5:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x77;
          goto LAB_140017acc;
        }
        goto LAB_140017adc;
      case -0x2a:
        if (*(int *)(lVar4 + 0x10) != 2) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
                    &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
          }
          return -0x3ffffff0;
        }
        iVar6 = (uint)*(byte *)(lVar3 + 5) * 0x200;
        if (*(byte *)(lVar3 + 5) == 0) goto LAB_140017adc;
        if (*(uint *)(lVar8 + 0x10) < iVar6 + 0x20U) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return -0x3fffffdd;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
            return -0x3fffffdd;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return -0x3fffffdd;
          }
          uVar9 = 0x76;
          goto LAB_140017884;
        }
        uVar10 = 0x1b050c;
        break;
      case -0x27:
        uVar10 = 0x1b0505;
        break;
      case -0x25:
        uVar10 = 0x1b050a;
      }
    }
    puVar7 = (uint *)ExAllocatePool2(0x40,iVar6 + 0x3d,0x61446353);
    if (puVar7 == (uint *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      iVar6 = -0x3fffff66;
    }
    else {
      *puVar7 = 0x1c;
      puVar7[1] = 0x49534353;
      puVar7[2] = 0x4b534944;
      puVar7[3] = *(uint *)(lVar2 + 0x248);
      puVar7[6] = iVar6 + 0x21;
      puVar7[4] = uVar10;
      *(undefined1 *)(lVar3 + 0xc) = *(undefined1 *)(lVar4 + 0xe);
      if (*(char *)(lVar3 + 4) == -0x2a) {
        sVar11 = (ulonglong)*(byte *)(lVar3 + 5) * 0x200 + 0x20;
      }
      else {
        sVar11 = 0x20;
      }
      memmove(puVar7 + 7,*(void **)(param_2 + 0x18),sVar11);
      lVar8 = IoBuildDeviceIoControlRequest
                        (0x4d008,*(undefined8 *)(lVar2 + 0x10),puVar7,iVar6 + 0x3d,puVar7,
                         iVar6 + 0x3d,0,&local_48,&local_58);
      if (lVar8 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
                  &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
        }
        ExFreePoolWithTag(puVar7,0);
        iVar6 = -0x3fffff66;
      }
      else {
        iVar6 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10),lVar8);
        if (iVar6 == 0x103) {
          KeWaitForSingleObject(&local_48,0,0,0,0);
          iVar6 = (int)local_58;
        }
        sVar11 = 0x18;
        if (*(char *)(lVar3 + 4) != -0x26) {
          sVar11 = 0x10;
        }
        memmove(*(void **)(param_2 + 0x18),(void *)((ulonglong)*puVar7 + (longlong)puVar7),sVar11);
        *(size_t *)(param_2 + 0x38) = sVar11;
        ExFreePoolWithTag(puVar7,0);
      }
    }
  }
  return iVar6;
}



===== DiskIoctlGetCacheSetting @ 140017b10 =====

undefined8 DiskIoctlGetCacheSetting(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0xc) {
    return 0xc0000023;
  }
  puVar2 = *(undefined8 **)(param_2 + 0x18);
  *puVar2 = 0xc;
  if ((char)*(undefined4 *)(lVar1 + 0x36c) < '\0') {
    *(undefined4 *)((longlong)puVar2 + 4) = 1;
  }
  if ((*(uint *)(lVar1 + 0x36c) & 0x40) != 0) {
    *(undefined4 *)((longlong)puVar2 + 4) = 2;
  }
  *(byte *)(puVar2 + 1) = (byte)*(undefined2 *)(lVar1 + 0x280) >> 4 & 1;
  *(undefined8 *)(param_2 + 0x38) = 0xc;
  return 0;
}



===== DiskModeSelect @ 140017b80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DiskModeSelect(longlong param_1,void *param_2,uint param_3,byte param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  bool bVar8;
  undefined1 auStack_1a8 [32];
  undefined1 local_188;
  byte local_178;
  undefined2 local_168;
  byte abStack_165 [17];
  int local_154;
  byte local_120 [24];
  undefined2 local_108;
  undefined1 local_106;
  undefined4 local_100;
  undefined4 local_fc;
  undefined8 local_f8;
  undefined2 local_e4;
  int local_e0;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_90;
  undefined2 local_88;
  undefined4 local_84;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 local_6e;
  byte local_60 [24];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1a8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_178 = param_4;
  memset(&local_168,0,0x58);
  memset(&local_108,0,0xb8);
  if (*(int *)(lVar1 + 0x23c) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
    }
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar5 = param_3 + 0xc;
    lVar3 = ExAllocatePool2(0x48,iVar5,0x4d446353);
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      *(undefined1 *)(lVar3 + 3) = 8;
      *(undefined1 *)(lVar3 + 0xb) = *(undefined1 *)(lVar1 + 0x23e);
      *(char *)(lVar3 + 10) = (char)((uint)*(undefined4 *)(lVar1 + 0x23c) >> 8);
      *(undefined1 *)(lVar3 + 9) = *(undefined1 *)(lVar1 + 0x23c);
      memmove((void *)(lVar3 + 0xc),param_2,(ulonglong)param_3);
      if (*(char *)(*(longlong *)(lVar1 + 0x210) + 0x1e) == '\x01') {
        local_106 = 0x28;
        local_108 = 8;
        pbVar4 = local_60;
        local_100 = 0x53524258;
        local_e4 = 2;
        local_fc = 1;
        local_f8 = 0xb8;
        local_d4 = 0x80;
        local_d0 = 1;
        puVar7 = &local_108;
        local_88 = 1;
        local_e0 = *(int *)(lVar1 + 0x248) * 2;
        local_84 = 4;
        local_90 = 0x90;
        local_78 = 0x40;
        local_74 = 0x20;
        local_6e = 6;
      }
      else {
        abStack_165[7] = 6;
        pbVar4 = local_120;
        puVar7 = &local_168;
        local_154 = *(int *)(lVar1 + 0x248) * 2;
      }
      *pbVar4 = 0x15;
      pbVar4[4] = (byte)iVar5;
      pbVar4[1] = (pbVar4[1] ^ local_178) & 1 ^ pbVar4[1] | 0x10;
      iVar6 = 1;
      do {
        local_188 = 1;
        iVar2 = ClassSendSrbSynchronous(param_1,puVar7,lVar3,iVar5);
        if (iVar2 != -0x7fffffea) {
          if ((*(byte *)((longlong)puVar7 + 3) & 0x3f) == 0x12) {
            iVar2 = 0;
          }
          break;
        }
        bVar8 = iVar6 != 0;
        iVar6 = iVar6 + -1;
      } while (bVar8);
      ExFreePoolWithTag(lVar3,0);
    }
  }
  return iVar2;
}



===== DiskGetGuidSymbolicLinkName @ 140017de0 =====

ulonglong DiskGetGuidSymbolicLinkName(undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  wchar_t *pwVar2;
  ulonglong uVar3;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  uVar1 = RtlStringFromGUID(0,&local_18);
  if (-1 < (int)uVar1) {
    pwVar2 = (wchar_t *)ExAllocatePool2(0x40,0x6a,0x20446353);
    if (pwVar2 == (wchar_t *)0x0) {
      uVar1 = 0xc000009a;
    }
    else {
      uVar3 = RtlStringCbPrintfW(pwVar2,0x6a,L"\\Global??\\Disk%s",uStack_10);
      uVar1 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        ExFreePoolWithTag(pwVar2,0);
      }
      else {
        RtlInitUnicodeString(param_2,pwVar2);
      }
    }
    RtlFreeUnicodeString(&local_18);
  }
  return uVar1;
}



===== DiskIoctlGetDriveGeometry @ 140017eb0 =====

undefined8 DiskIoctlGetDriveGeometry(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  byte bVar5;
  char cVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  
  lVar9 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(undefined8 **)(param_2 + 0x18);
  lVar4 = *(longlong *)(lVar9 + 0x60);
  bVar5 = KeGetCurrentIrql();
  if (bVar5 < 2) {
    if (*(uint *)(lVar2 + 8) < 0x18) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      uVar7 = 0xc0000023;
    }
    else {
      if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
        uVar7 = ClassReadDriveCapacity(*(undefined8 *)(*(longlong *)(lVar9 + 0x18) + 8));
        *(int *)(lVar4 + 4) = (int)uVar7;
        if ((int)uVar7 < 0) {
          return uVar7;
        }
      }
      uVar8 = Feature_Disk_KcsanFix__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar8 == 0) {
        memmove(*(void **)(param_2 + 0x18),(undefined8 *)(lVar9 + 0x228),0x18);
        lVar9 = *(longlong *)(param_2 + 0x18);
        if ((*(int *)(lVar9 + 0x14) == 0) &&
           (cVar6 = DiskIsManagedZonedDevice(param_1), cVar6 == '\0')) {
          *(undefined4 *)(lVar9 + 0x14) = 0x200;
        }
      }
      else {
        *puVar3 = *(undefined8 *)(lVar9 + 0x228);
        *(undefined4 *)(puVar3 + 1) = *(undefined4 *)(lVar9 + 0x230);
        *(undefined4 *)((longlong)puVar3 + 0xc) = *(undefined4 *)(lVar9 + 0x234);
        *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(lVar9 + 0x238);
        iVar1 = *(int *)(lVar9 + 0x23c);
        *(int *)((longlong)puVar3 + 0x14) = iVar1;
        if ((iVar1 == 0) && (cVar6 = DiskIsManagedZonedDevice(param_1), cVar6 == '\0')) {
          *(undefined4 *)((longlong)puVar3 + 0x14) = 0x200;
        }
      }
      *(undefined8 *)(param_2 + 0x38) = 0x18;
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0xc0000148;
  }
  return uVar7;
}



===== DiskIoctlGetLengthInfo @ 140018020 =====

int DiskIoctlGetLengthInfo(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  int iVar7;
  ulonglong uVar8;
  
  bVar6 = KeGetCurrentIrql();
  if (1 < bVar6) {
    return -0x3ffffeb8;
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(lVar3 + 0x18);
  lVar5 = *(longlong *)(lVar4 + 0x60);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 8) {
    return -0x3fffffdd;
  }
  iVar7 = ClassReadDriveCapacity(*(undefined8 *)(lVar4 + 8));
  LOCK();
  iVar1 = *(int *)(lVar5 + 4);
  *(int *)(lVar5 + 4) = iVar7;
  UNLOCK();
  uVar8 = Feature_Disk_KcsanFix__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar8 == 0) {
    iVar2 = *(int *)(lVar5 + 4);
  }
  else {
    iVar2 = *(int *)(lVar5 + 4);
  }
  if (iVar2 != iVar1) {
    IoInvalidateDeviceRelations(*(undefined8 *)(lVar4 + 0x200),0);
  }
  if (iVar7 < 0) {
    uVar8 = Feature_Disk_KcsanFix__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar8 != 0) {
      *(int *)(param_2 + 0x30) = iVar7;
    }
  }
  else {
    **(undefined8 **)(param_2 + 0x18) = *(undefined8 *)(lVar3 + 0x90);
    uVar8 = Feature_Disk_KcsanFix__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar8 != 0) {
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    *(undefined8 *)(param_2 + 0x38) = 8;
    iVar7 = 0;
  }
  return iVar7;
}



===== DiskIoctlGetVolumeDiskExtents @ 140018140 =====

int DiskIoctlGetVolumeDiskExtents(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  byte bVar5;
  int iVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar6 = -0x3ffffff0;
  lVar3 = *(longlong *)(lVar1 + 0x60);
  bVar5 = KeGetCurrentIrql();
  if (1 < bVar5) {
    return -0x3ffffeb8;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
              &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids,param_1,(char)param_2);
  }
  if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
    if (*(uint *)(lVar2 + 8) < 0x20) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                &WPP_0b53ab2e7a6032127f9b7c9bb3ebc131_Traceguids);
      }
      return -0x3fffffdd;
    }
    iVar6 = ClassReadDriveCapacity(*(undefined8 *)(*(longlong *)(lVar1 + 0x18) + 8));
    *(int *)(lVar3 + 4) = iVar6;
    if (-1 < iVar6) {
      puVar4 = *(undefined4 **)(param_2 + 0x18);
      *puVar4 = 1;
      puVar4[2] = *(undefined4 *)(*(longlong *)(lVar1 + 0x18) + 0x24c);
      *(undefined8 *)(puVar4 + 4) = *(undefined8 *)(lVar1 + 0x98);
      *(undefined8 *)(puVar4 + 6) = *(undefined8 *)(lVar1 + 0x90);
      *(undefined8 *)(param_2 + 0x38) = 0x20;
    }
  }
  return iVar6;
}



===== entry @ 14001a010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001a044 =====

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



===== DriverEntry @ 14001a078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_218 [32];
  undefined4 local_1f8 [2];
  undefined4 local_1f0;
  undefined4 local_1ec;
  code *local_1e8;
  undefined8 local_1e0;
  undefined4 local_1d8 [2];
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c4;
  code *local_1c0;
  code *local_1b8;
  code *local_1b0;
  code *local_1a8;
  undefined8 local_1a0;
  code *local_198;
  code *local_190;
  code *local_188;
  code *local_180;
  code *local_178;
  undefined4 local_168;
  undefined *local_160;
  code *local_158;
  code *local_150;
  code *local_148;
  code *local_140;
  code *local_138;
  code *local_130;
  code *local_80;
  code *local_60;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_218;
  memset(local_1d8,0,0x188);
  local_48 = 0xe34b11;
  local_1ec = 0;
  DAT_14000c288 = &WPP_ThisDir_CTLGUID_wppCtlGuid;
  local_1e0 = 0;
  local_44 = 0x47452444;
  local_40 = 0x1623da5;
  local_3c = 0xf782cd00;
  local_38 = 0xa483941;
  local_34 = 0x4f7bbdfd;
  local_30 = 0xe2ce95be;
  local_2c = 0xc0916a2;
  _WPP_MAIN_CB = 0;
  DAT_14000c290 = 0;
  _DAT_14000c2a0 = 0;
  _DAT_14000c2a8 = 1;
  WppLoadTracingSupport();
  _DAT_14000c2a0 = 0;
  WppInitKm();
  local_1d8[0] = 0x188;
  local_198 = DiskInitFdo;
  local_1d0 = 0x6d0;
  local_190 = DiskStartFdo;
  local_180 = DiskStopDevice;
  local_178 = DiskRemoveDevice;
  local_188 = ClassSpinDownPowerHandler_exref;
  local_1c0 = DiskFdoProcessError;
  local_1b8 = DiskReadWriteVerification;
  local_1b0 = DiskDeviceControl;
  local_1a8 = DiskShutdownFlush;
  local_160 = &DiskWmiFdoGuidList;
  local_158 = DiskFdoQueryWmiRegInfo;
  local_150 = DiskFdoQueryWmiDataBlock;
  local_148 = DiskFdoSetWmiDataBlock;
  local_140 = DiskFdoSetWmiDataItem;
  local_138 = DiskFdoExecuteWmiMethod;
  local_130 = DiskWmiFunctionControl;
  local_80 = DiskAddDevice;
  local_60 = DiskUnload;
  local_1cc = 7;
  local_1c4 = 0x100;
  local_1a0 = 0;
  local_168 = 7;
  DiskInitializeReregistration();
  iVar1 = ClassInitialize(param_1,param_2,local_1d8);
  local_1f0 = 0x18;
  local_1e8 = DiskFdoQueryWmiRegInfoEx;
  ClassInitializeEx(param_1,&local_48,&local_1f0);
  local_1f8[0] = 3;
  ClassInitializeEx(param_1,&local_38,local_1f8);
  McGenEventRegister_EtwRegister();
  wil_InitializeFeatureStaging();
  if (-1 < iVar1) {
    IoRegisterDriverReinitialization(param_1,DiskDriverReinitialization,0);
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14001a310 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001a400 =====

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


