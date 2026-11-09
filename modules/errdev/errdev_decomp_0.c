
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



===== ErrDevAcpiNotifyCallback @ 1c0001020 =====

void ErrDevAcpiNotifyCallback(undefined8 param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((ErrDevGenericSciOneTimeInitDone == 1) && (param_2 == 0x80)) {
    LOCK();
    iVar1 = DAT_1c0005428 + 1;
    UNLOCK();
    bVar2 = DAT_1c0005428 == 0;
    DAT_1c0005428 = iVar1;
    if (bVar2) {
      ExQueueWorkItem(&DAT_1c0005408,1);
    }
  }
  return;
}



===== ErrDevDriverUnload @ 1c0001070 =====

void ErrDevDriverUnload(void)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLock,0);
  puVar2 = (undefined8 *)*ErrDevGenericSciErrorSourceListHead;
  if (((undefined8 **)ErrDevGenericSciErrorSourceListHead[1] == &ErrDevGenericSciErrorSourceListHead
      ) && (puVar3 = ErrDevGenericSciErrorSourceListHead,
           (undefined8 *)puVar2[1] == ErrDevGenericSciErrorSourceListHead)) {
    while (ErrDevGenericSciErrorSourceListHead = puVar2,
          puVar2[1] = &ErrDevGenericSciErrorSourceListHead,
          (undefined8 **)puVar3 != &ErrDevGenericSciErrorSourceListHead) {
      if (puVar3[5] != 0) {
        if (puVar3[7] != 0) {
          MmUnmapIoSpace(puVar3[7],*(undefined4 *)(puVar3 + 6));
        }
        MmUnmapIoSpace(puVar3[5],8);
      }
      if (puVar3[3] != 0) {
        ExFreePoolWithTag(puVar3[3],0x76447245);
      }
      ExFreePoolWithTag(puVar3,0x76447245);
      if (((undefined8 **)ErrDevGenericSciErrorSourceListHead[1] !=
           &ErrDevGenericSciErrorSourceListHead) ||
         (puVar2 = (undefined8 *)*ErrDevGenericSciErrorSourceListHead,
         puVar3 = ErrDevGenericSciErrorSourceListHead,
         (undefined8 *)puVar2[1] != ErrDevGenericSciErrorSourceListHead)) goto LAB_1c00012b7;
    }
    ExReleasePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLock,0);
    ExAcquirePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLockV2,0);
    puVar3 = ErrDevGenericSciErrorSourceListHeadV2;
    puVar2 = (undefined8 *)*ErrDevGenericSciErrorSourceListHeadV2;
    if (((undefined8 **)ErrDevGenericSciErrorSourceListHeadV2[1] ==
         &ErrDevGenericSciErrorSourceListHeadV2) &&
       ((undefined8 *)puVar2[1] == ErrDevGenericSciErrorSourceListHeadV2)) {
      ErrDevGenericSciErrorSourceListHeadV2 = puVar2;
      puVar2[1] = &ErrDevGenericSciErrorSourceListHeadV2;
      while( true ) {
        if ((undefined8 **)puVar3 == &ErrDevGenericSciErrorSourceListHeadV2) {
          ExReleasePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLockV2,0);
          KeLeaveCriticalRegion();
          return;
        }
        if (puVar3[5] != 0) {
          if (puVar3[7] != 0) {
            MmUnmapIoSpace(puVar3[7],*(undefined4 *)(puVar3 + 6));
          }
          MmUnmapIoSpace(puVar3[5],8);
        }
        if (puVar3[8] != 0) {
          if (puVar3[0xc] != 0) {
            MmUnmapIoSpace(puVar3[0xc],8);
          }
          MmUnmapIoSpace(puVar3[8],8);
        }
        if (puVar3[3] != 0) {
          ExFreePoolWithTag(puVar3[3],0x76447245);
        }
        ExFreePoolWithTag(puVar3,0x76447245);
        puVar3 = ErrDevGenericSciErrorSourceListHead;
        if (((undefined8 **)ErrDevGenericSciErrorSourceListHead[1] !=
             &ErrDevGenericSciErrorSourceListHead) ||
           (puVar2 = (undefined8 *)*ErrDevGenericSciErrorSourceListHead,
           (undefined8 *)puVar2[1] != ErrDevGenericSciErrorSourceListHead)) break;
        ErrDevGenericSciErrorSourceListHead = puVar2;
        puVar2[1] = &ErrDevGenericSciErrorSourceListHead;
      }
    }
  }
LAB_1c00012b7:
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ErrDevErrSrcCorrectV2 @ 1c00012d0 =====

undefined8 ErrDevErrSrcCorrectV2(longlong param_1,int *param_2)

{
  *param_2 = *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x10) + 0x50;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return 0;
}



===== ErrDevErrSrcInitialize @ 1c00012f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong ErrDevErrSrcInitialize(int param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  longlong local_res10 [3];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res10[0] = 0;
  if (*(char *)(param_2 + 8) == '\x03') {
    if (param_1 == 0) {
      uVar3 = 0;
    }
    else {
      uVar4 = ErrDevInitGenericErrorSourceEntry(param_2,local_res10);
      uVar3 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLock,0);
        puVar6 = auStack_28;
        puVar5 = &ErrDevGenericSciErrorSourceListHead;
        if ((undefined8 *)*DAT_1c0005458 != &ErrDevGenericSciErrorSourceListHead) {
          puVar5 = (undefined8 *)0x3;
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)();
          puVar6 = auStack_20;
        }
        puVar1 = *(undefined8 **)(puVar6 + 0x38);
        *puVar1 = puVar5;
        puVar1[1] = DAT_1c0005458;
        *DAT_1c0005458 = puVar1;
        *(undefined8 *)(puVar6 + -8) = 0x1c000138e;
        DAT_1c0005458 = puVar1;
        ExReleasePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLock,0);
        *(undefined8 *)(puVar6 + -8) = 0x1c000139a;
        KeLeaveCriticalRegion();
      }
      if (ErrDevGenericSciOneTimeInitDone == 0) {
        DAT_1c0005428 = 0;
        _DAT_1c0005408 = 0;
        _DAT_1c0005418 = ErrDevErrorDeviceNotifyWorker;
        _DAT_1c0005420 = &ErrDevGenericSciContext;
        ErrDevGenericSciOneTimeInitDone = 1;
      }
    }
  }
  else {
    uVar3 = 0xc00000bb;
  }
  return uVar3;
}



===== ErrDevErrSrcInitializeV2 @ 1c00013f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong ErrDevErrSrcInitializeV2(int param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  longlong local_res10 [3];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res10[0] = 0;
  if (*(char *)(param_2 + 8) == '\x03') {
    if (param_1 == 0) {
      uVar3 = 0;
    }
    else {
      uVar4 = ErrDevInitGenericErrorSourceEntryV2(param_2,local_res10);
      uVar3 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLockV2,0);
        puVar6 = auStack_28;
        puVar5 = &ErrDevGenericSciErrorSourceListHeadV2;
        if ((undefined8 *)*DAT_1c0005448 != &ErrDevGenericSciErrorSourceListHeadV2) {
          puVar5 = (undefined8 *)0x3;
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)();
          puVar6 = auStack_20;
        }
        puVar1 = *(undefined8 **)(puVar6 + 0x38);
        *puVar1 = puVar5;
        puVar1[1] = DAT_1c0005448;
        *DAT_1c0005448 = puVar1;
        *(undefined8 *)(puVar6 + -8) = 0x1c000148e;
        DAT_1c0005448 = puVar1;
        ExReleasePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLockV2,0);
        *(undefined8 *)(puVar6 + -8) = 0x1c000149a;
        KeLeaveCriticalRegion();
      }
      if (ErrDevGenericSciOneTimeInitDone == 0) {
        DAT_1c0005428 = 0;
        _DAT_1c0005408 = 0;
        _DAT_1c0005418 = ErrDevErrorDeviceNotifyWorker;
        _DAT_1c0005420 = &ErrDevGenericSciContext;
        ErrDevGenericSciOneTimeInitDone = 1;
      }
    }
  }
  else {
    uVar3 = 0xc00000bb;
  }
  return uVar3;
}



===== ErrDevExtractCorrectedGenericErrorDataV2 @ 1c00014ec =====

undefined8 ErrDevExtractCorrectedGenericErrorDataV2(longlong param_1)

{
  void *_Src;
  uint uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  uint uVar4;
  
  _Src = *(void **)(param_1 + 0x38);
  lVar3 = *(longlong *)(param_1 + 0x18);
  if (lVar3 == 0) {
    puVar2 = (undefined4 *)ExAllocatePool2(0x40,*(undefined4 *)(param_1 + 0x20),0x76447245);
    *(undefined4 **)(param_1 + 0x18) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      return 0xc0000225;
    }
    *puVar2 = 0x41454857;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 4) = 3;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 8) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x10) = 6;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x18) = *(undefined4 *)(param_1 + 0x94);
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x1c) = 0xd;
    lVar3 = *(longlong *)(param_1 + 0x18);
    *(undefined8 *)(lVar3 + 0x20) = 0x409aab403e62a467;
    *(undefined8 *)(lVar3 + 0x28) = 0x8fb364d462f398a6;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x38) = 7;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x40) = 0x50;
    lVar3 = *(longlong *)(param_1 + 0x18);
  }
  *(undefined4 *)(lVar3 + 0x44) = *(undefined4 *)(param_1 + 0x30);
  lVar3 = *(longlong *)(param_1 + 0x18);
  uVar4 = *(int *)((longlong)_Src + 8) + *(int *)((longlong)_Src + 0xc) + 0x14;
  uVar1 = *(uint *)(lVar3 + 0x44);
  if (uVar4 <= *(uint *)(lVar3 + 0x44)) {
    uVar1 = uVar4;
  }
  *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)((longlong)_Src + 0x10);
  *(uint *)(lVar3 + 0x44) = uVar1;
  memcpy((void *)((ulonglong)*(uint *)(lVar3 + 0x40) + lVar3),_Src,(ulonglong)uVar1);
  return 0;
}



===== ErrDevInitGenericErrorSourceEntry @ 1c00015f4 =====

undefined8 ErrDevInitGenericErrorSourceEntry(undefined8 *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  
  uVar10 = 0;
  lVar4 = ExAllocatePool2(0x100,0x410,0x76447245);
  if (lVar4 == 0) {
    uVar10 = 0xc000009a;
  }
  else {
    *(undefined4 *)(lVar4 + 0x30) = *(undefined4 *)((longlong)param_1 + 0x2c);
    lVar5 = MmMapIoSpaceEx(param_1[7],8,0x204);
    *(longlong *)(lVar4 + 0x28) = lVar5;
    if (lVar5 == 0) {
      uVar10 = 0xc000009a;
      if (*(longlong *)(lVar4 + 0x18) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar4 + 0x18),0x76447245);
      }
      ExFreePoolWithTag(lVar4,0x76447245);
      lVar4 = 0;
    }
    else {
      iVar7 = *(int *)(lVar4 + 0x30) + *(int *)(param_1 + 2) + 0x50;
      *(int *)(lVar4 + 0x20) = iVar7;
      puVar6 = (undefined4 *)ExAllocatePool2(0x40,iVar7,0x76447245);
      *(undefined4 **)(lVar4 + 0x18) = puVar6;
      lVar5 = 7;
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = 0x41454857;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x18) + 4) = 3;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x18) + 8) = *(undefined4 *)(lVar4 + 0x20);
        *(undefined4 *)(*(longlong *)(lVar4 + 0x18) + 0x10) = 6;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x18) + 0x18) =
             *(undefined4 *)((longlong)param_1 + 0x1c);
        *(undefined4 *)(*(longlong *)(lVar4 + 0x18) + 0x1c) = 8;
        lVar1 = *(longlong *)(lVar4 + 0x18);
        *(undefined8 *)(lVar1 + 0x20) = 0x409aab403e62a467;
        *(undefined8 *)(lVar1 + 0x28) = 0x8fb364d462f398a6;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x18) + 0x38) = 7;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x18) + 0x40) = 0x50;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x18) + 0x44) = *(undefined4 *)(lVar4 + 0x30);
      }
      puVar3 = (undefined8 *)(lVar4 + 0x40);
      do {
        puVar9 = param_1;
        puVar8 = puVar3;
        uVar2 = puVar9[1];
        *puVar8 = *puVar9;
        puVar8[1] = uVar2;
        uVar2 = puVar9[3];
        puVar8[2] = puVar9[2];
        puVar8[3] = uVar2;
        uVar2 = puVar9[5];
        puVar8[4] = puVar9[4];
        puVar8[5] = uVar2;
        uVar2 = puVar9[7];
        puVar8[6] = puVar9[6];
        puVar8[7] = uVar2;
        uVar2 = puVar9[9];
        puVar8[8] = puVar9[8];
        puVar8[9] = uVar2;
        uVar2 = puVar9[0xb];
        puVar8[10] = puVar9[10];
        puVar8[0xb] = uVar2;
        uVar2 = puVar9[0xd];
        puVar8[0xc] = puVar9[0xc];
        puVar8[0xd] = uVar2;
        uVar2 = puVar9[0xf];
        puVar8[0xe] = puVar9[0xe];
        puVar8[0xf] = uVar2;
        lVar5 = lVar5 + -1;
        puVar3 = puVar8 + 0x10;
        param_1 = puVar9 + 0x10;
      } while (lVar5 != 0);
      uVar2 = puVar9[0x11];
      puVar8[0x10] = puVar9[0x10];
      puVar8[0x11] = uVar2;
      uVar2 = puVar9[0x13];
      puVar8[0x12] = puVar9[0x12];
      puVar8[0x13] = uVar2;
      uVar2 = puVar9[0x15];
      puVar8[0x14] = puVar9[0x14];
      puVar8[0x15] = uVar2;
      uVar2 = puVar9[0x17];
      puVar8[0x16] = puVar9[0x16];
      puVar8[0x17] = uVar2;
      puVar8[0x18] = puVar9[0x18];
      *(undefined4 *)(puVar8 + 0x19) = *(undefined4 *)(puVar9 + 0x19);
    }
  }
  *param_2 = lVar4;
  return uVar10;
}



===== ErrDevInitGenericErrorSourceEntryV2 @ 1c00017e0 =====

undefined8 ErrDevInitGenericErrorSourceEntryV2(undefined8 *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  int iVar10;
  
  uVar9 = 0;
  lVar3 = ExAllocatePool2(0x100,0x448,0x76447245);
  if (lVar3 == 0) {
    uVar9 = 0xc000009a;
  }
  else {
    *(undefined4 *)(lVar3 + 0x30) = *(undefined4 *)((longlong)param_1 + 0x2c);
    lVar4 = MmMapIoSpaceEx(param_1[7],8,0x204);
    *(longlong *)(lVar3 + 0x28) = lVar4;
    if (lVar4 != 0) {
      if ((*(char *)((longlong)param_1 + 0x5f) == '\x03') &&
         (*(char *)((longlong)param_1 + 0x5d) == ' ')) {
        *(undefined4 *)(lVar3 + 0x58) = 4;
      }
      else if ((*(char *)((longlong)param_1 + 0x5f) == '\x04') &&
              (*(char *)((longlong)param_1 + 0x5d) == '@')) {
        *(undefined4 *)(lVar3 + 0x58) = 8;
      }
      *(undefined8 *)(lVar3 + 0x48) = param_1[0xd];
      *(undefined8 *)(lVar3 + 0x50) = param_1[0xe];
      puVar5 = (undefined8 *)ExAllocatePool2(0x42,8,0x76447245);
      *(undefined8 **)(lVar3 + 0x40) = puVar5;
      if (puVar5 != (undefined8 *)0x0) {
        *puVar5 = param_1[0xc];
        iVar10 = *(int *)(param_1 + 2) + 0x50 + *(int *)(lVar3 + 0x30);
        *(int *)(lVar3 + 0x20) = iVar10;
        puVar6 = (undefined4 *)ExAllocatePool2(0x40,iVar10,0x76447245);
        *(undefined4 **)(lVar3 + 0x18) = puVar6;
        lVar4 = 7;
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = 0x41454857;
          *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 4) = 3;
          *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 8) = *(undefined4 *)(lVar3 + 0x20);
          *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x10) = 6;
          *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x18) =
               *(undefined4 *)((longlong)param_1 + 0x1c);
          *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x1c) = 0xd;
          lVar1 = *(longlong *)(lVar3 + 0x18);
          *(undefined8 *)(lVar1 + 0x20) = 0x409aab403e62a467;
          *(undefined8 *)(lVar1 + 0x28) = 0x8fb364d462f398a6;
          *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x38) = 7;
          *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x40) = 0x50;
          *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x44) = *(undefined4 *)(lVar3 + 0x30);
        }
        puVar5 = (undefined8 *)(lVar3 + 0x78);
        do {
          puVar8 = param_1;
          puVar7 = puVar5;
          uVar2 = puVar8[1];
          *puVar7 = *puVar8;
          puVar7[1] = uVar2;
          uVar2 = puVar8[3];
          puVar7[2] = puVar8[2];
          puVar7[3] = uVar2;
          uVar2 = puVar8[5];
          puVar7[4] = puVar8[4];
          puVar7[5] = uVar2;
          uVar2 = puVar8[7];
          puVar7[6] = puVar8[6];
          puVar7[7] = uVar2;
          uVar2 = puVar8[9];
          puVar7[8] = puVar8[8];
          puVar7[9] = uVar2;
          uVar2 = puVar8[0xb];
          puVar7[10] = puVar8[10];
          puVar7[0xb] = uVar2;
          uVar2 = puVar8[0xd];
          puVar7[0xc] = puVar8[0xc];
          puVar7[0xd] = uVar2;
          uVar2 = puVar8[0xf];
          puVar7[0xe] = puVar8[0xe];
          puVar7[0xf] = uVar2;
          lVar4 = lVar4 + -1;
          puVar5 = puVar7 + 0x10;
          param_1 = puVar8 + 0x10;
        } while (lVar4 != 0);
        uVar2 = puVar8[0x11];
        puVar7[0x10] = puVar8[0x10];
        puVar7[0x11] = uVar2;
        uVar2 = puVar8[0x13];
        puVar7[0x12] = puVar8[0x12];
        puVar7[0x13] = uVar2;
        uVar2 = puVar8[0x15];
        puVar7[0x14] = puVar8[0x14];
        puVar7[0x15] = uVar2;
        uVar2 = puVar8[0x17];
        puVar7[0x16] = puVar8[0x16];
        puVar7[0x17] = uVar2;
        puVar7[0x18] = puVar8[0x18];
        *(undefined4 *)(puVar7 + 0x19) = *(undefined4 *)(puVar8 + 0x19);
        goto LAB_1c0001a40;
      }
    }
    uVar9 = 0xc000009a;
    if (*(longlong *)(lVar3 + 0x40) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar3 + 0x40),0x76447245);
    }
    if (*(longlong *)(lVar3 + 0x28) != 0) {
      MmUnmapIoSpace(*(longlong *)(lVar3 + 0x28),8);
    }
    if (*(longlong *)(lVar3 + 0x18) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar3 + 0x18),0x76447245);
    }
    ExFreePoolWithTag(lVar3,0x76447245);
    lVar3 = 0;
  }
LAB_1c0001a40:
  *param_2 = lVar3;
  return uVar9;
}



===== ErrDevSignalRAS @ 1c0001a68 =====

undefined8 ErrDevSignalRAS(longlong param_1)

{
  undefined8 uVar1;
  ulonglong *puVar2;
  
  if (**(longlong **)(param_1 + 0x40) == -1) {
    uVar1 = 0xc0000225;
  }
  else {
    puVar2 = *(ulonglong **)(param_1 + 0x60);
    if (puVar2 == (ulonglong *)0x0) {
      puVar2 = (ulonglong *)
               MmMapIoSpaceEx(**(longlong **)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x58),0x204)
      ;
      *(ulonglong **)(param_1 + 0x60) = puVar2;
      if (puVar2 == (ulonglong *)0x0) {
        return 0xc00000e5;
      }
    }
    if (*(int *)(param_1 + 0x58) == 4) {
      *(uint *)puVar2 =
           (uint)*puVar2 & (uint)*(ulonglong *)(param_1 + 0xe0) |
           (uint)*(ulonglong *)(param_1 + 0xe8);
    }
    else {
      *puVar2 = *puVar2 & *(ulonglong *)(param_1 + 0xe0) | *(ulonglong *)(param_1 + 0xe8);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== FxStubDriverUnloadCommon @ 1c0001afc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005198 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0005198 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c0001b55:
      if (ppvVar1 == (void **)0x0) goto LAB_1c0001bab;
      if (ppvVar2 <= ppvVar1) goto LAB_1c0001bc3;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c0001b55;
LAB_1c0001bab:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0001bc3:
  WdfVersionUnbind(&DAT_1c00053e0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0001c00 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0001c34 =====

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
    _DAT_1c00053e0 = 0x2080000;
    _DAT_1c00053e8 = &DAT_1c00051d0;
    RtlCopyUnicodeString(&DAT_1c00053e0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c00053e0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00053d8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c00053e0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005198 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0001dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00053d8 != (code *)0x0) && (DAT_1c00053d8 != FxStubDriverUnload)) {
    (*DAT_1c00053d8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0001df4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001e19) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x1c000518f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0005198 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 1c0001f7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001f99) */
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
    if ((void **)0x1c00051af < ppvVar2) break;
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



===== _guard_check_icall @ 1c0002050 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 1c0002070 =====

/* WARNING: Removing unreachable block (ram,0x0001c00020da) */
/* WARNING: Removing unreachable block (ram,0x0001c0002089) */
/* WARNING: Removing unreachable block (ram,0x0001c000207a) */

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



===== __security_check_cookie @ 1c0002140 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0002180 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00021b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00021b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00021e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0002240 =====

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



===== memset @ 1c0002540 =====

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



===== __memset_repmovs @ 1c0002680 =====

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



===== __memset_query @ 1c0002700 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0002780 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00028c0 =====

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



===== __memset_spec_plain @ 1c0002940 =====

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



===== ErrDevDeviceAdd @ 1c0008010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ErrDevDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined4 local_c8;
  undefined4 local_c4;
  code *local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined *local_98;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7b;
  code *local_60;
  undefined4 local_38;
  
  local_res18 = 0;
  local_res20 = 0;
  local_c4 = 0;
  local_b8 = 0;
  local_98 = PTR__WDF_FDO_DATA_TYPE_INFO_1c0005088;
  local_c0 = ErrDevDeviceCleanup;
  local_a8 = 0;
  uStack_a0 = 0;
  local_c8 = 0x38;
  local_b0 = 1;
  local_ac = 1;
  local_res10 = param_2;
  uVar3 = (**(code **)(WdfFunctions_01015 + 600))
                    (WdfDriverGlobals,&local_res10,&local_c8,&local_res18);
  if (-1 < (int)uVar3) {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_res18,PTR__WDF_FDO_DATA_TYPE_INFO_1c0005088);
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x268))
                      (WdfDriverGlobals,local_res18,&GUID_DEVINTERFACE_ERRDEV,0);
    if (-1 < (int)uVar3) {
      memset(&local_88,0,0x60);
      local_38 = 0xffffffff;
      local_80 = 2;
      local_84 = 2;
      local_88 = 0x60;
      local_60 = ErrDevIoDeviceControl;
      local_7b = 1;
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                        (WdfDriverGlobals,local_res18,&local_88,0,&local_res20);
      uVar3 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar5 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,local_res18);
        *(undefined8 *)(lVar4 + 0x68) = uVar5;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x418))
                          (WdfDriverGlobals,local_res18,&GUID_ACPI_INTERFACE_STANDARD,lVar4 + 0x10,
                           0x58,1,0);
        if (-1 < iVar2) {
          if (*(code **)(lVar4 + 0x20) != (code *)0x0) {
            (**(code **)(lVar4 + 0x20))(*(undefined8 *)(lVar4 + 0x18));
          }
          iVar2 = (**(code **)(lVar4 + 0x58))
                            (*(undefined8 *)(lVar4 + 0x68),ErrDevAcpiNotifyCallback,local_res18);
          if (iVar2 < 0) {
            if (*(code **)(lVar4 + 0x28) != (code *)0x0) {
              (**(code **)(lVar4 + 0x28))(*(undefined8 *)(lVar4 + 0x18));
            }
            *(undefined8 *)(lVar4 + 0x60) = 0;
            *(undefined8 *)(lVar4 + 0x28) = 0;
          }
        }
      }
    }
  }
  return uVar3;
}



===== ErrDevDeviceCleanup @ 1c0008220 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ErrDevDeviceCleanup(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_1c0005088);
  if (*(code **)(lVar1 + 0x60) != (code *)0x0) {
    (**(code **)(lVar1 + 0x60))(*(undefined8 *)(lVar1 + 0x68),ErrDevAcpiNotifyCallback);
  }
  if (*(code **)(lVar1 + 0x28) != (code *)0x0) {
    (**(code **)(lVar1 + 0x28))(*(undefined8 *)(lVar1 + 0x18));
  }
  return;
}



===== ErrDevErrorDeviceNotifyWorker @ 1c0008290 =====

void ErrDevErrorDeviceNotifyWorker(longlong param_1)

{
  int *piVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  int iVar8;
  
  iVar8 = 0;
  do {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLock,0);
    bVar3 = false;
    for (puVar7 = ErrDevGenericSciErrorSourceListHead;
        (undefined8 **)puVar7 != &ErrDevGenericSciErrorSourceListHead;
        puVar7 = (undefined8 *)*puVar7) {
      if (*(longlong *)puVar7[5] != -1) {
        puVar5 = (uint *)puVar7[7];
        if (puVar5 == (uint *)0x0) {
          puVar5 = (uint *)MmMapIoSpaceEx(*(longlong *)puVar7[5],*(undefined4 *)(puVar7 + 6),0x204);
          puVar7[7] = puVar5;
          if (puVar5 == (uint *)0x0) goto LAB_1c0008378;
        }
        uVar2 = *puVar5;
        if ((uVar2 & 2) == 0) {
          if ((uVar2 & 1) != 0) {
            *puVar5 = uVar2 & 0xfffffffe;
          }
        }
        else {
          uVar6 = ErrDevExtractCorrectedGenericErrorData((longlong)puVar7);
          *puVar5 = *puVar5 & 0xfffffffd;
          if (-1 < (int)uVar6) {
            PshedRetrieveErrorInfo(puVar7[3]);
            WheaReportHwError(puVar7[3]);
            bVar3 = true;
            LOCK();
            piVar1 = (int *)(param_1 + 0x28);
            iVar8 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            iVar8 = iVar8 + -1;
            if (iVar8 == 0) break;
          }
        }
      }
LAB_1c0008378:
    }
    ExReleasePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLock);
    ExAcquirePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLockV2);
    for (puVar7 = ErrDevGenericSciErrorSourceListHeadV2;
        (undefined8 **)puVar7 != &ErrDevGenericSciErrorSourceListHeadV2;
        puVar7 = (undefined8 *)*puVar7) {
      bVar4 = bVar3;
      if (*(longlong *)puVar7[5] != -1) {
        puVar5 = (uint *)puVar7[7];
        if (puVar5 == (uint *)0x0) {
          puVar5 = (uint *)MmMapIoSpaceEx(*(longlong *)puVar7[5],*(undefined4 *)(puVar7 + 6),0x204);
          puVar7[7] = puVar5;
          if (puVar5 == (uint *)0x0) goto LAB_1c0008463;
        }
        if (((*puVar5 & 2) != 0) || ((*puVar5 & 1) != 0)) {
          uVar6 = ErrDevExtractCorrectedGenericErrorDataV2((longlong)puVar7);
          *puVar5 = 0;
          ErrDevSignalRAS((longlong)puVar7);
          if (-1 < (int)uVar6) {
            PshedRetrieveErrorInfo(puVar7[3]);
            WheaReportHwError(puVar7[3]);
            bVar3 = true;
            LOCK();
            piVar1 = (int *)(param_1 + 0x28);
            iVar8 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            iVar8 = iVar8 + -1;
            bVar4 = true;
            if (iVar8 == 0) break;
          }
        }
      }
LAB_1c0008463:
      bVar3 = bVar4;
    }
    ExReleasePushLockExclusiveEx(&ErrDevGenericSciErrorSourceListLockV2);
    KeLeaveCriticalRegion();
    if (!bVar3) {
      LOCK();
      piVar1 = (int *)(param_1 + 0x28);
      iVar8 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      iVar8 = iVar8 + -1;
    }
    if (iVar8 < 1) {
      return;
    }
  } while( true );
}



===== ErrDevExtractCorrectedGenericErrorData @ 1c00084d0 =====

undefined8 ErrDevExtractCorrectedGenericErrorData(longlong param_1)

{
  void *_Src;
  uint uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  uint uVar4;
  
  _Src = *(void **)(param_1 + 0x38);
  lVar3 = *(longlong *)(param_1 + 0x18);
  if (lVar3 == 0) {
    puVar2 = (undefined4 *)ExAllocatePool2(0x40,*(undefined4 *)(param_1 + 0x20),0x76447245);
    *(undefined4 **)(param_1 + 0x18) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      return 0xc0000225;
    }
    *puVar2 = 0x41454857;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 4) = 3;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 8) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x10) = 6;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x18) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x1c) = 8;
    lVar3 = *(longlong *)(param_1 + 0x18);
    *(undefined8 *)(lVar3 + 0x20) = 0x409aab403e62a467;
    *(undefined8 *)(lVar3 + 0x28) = 0x8fb364d462f398a6;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x38) = 7;
    *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x40) = 0x50;
    lVar3 = *(longlong *)(param_1 + 0x18);
  }
  *(undefined4 *)(lVar3 + 0x44) = *(undefined4 *)(param_1 + 0x30);
  lVar3 = *(longlong *)(param_1 + 0x18);
  uVar4 = *(int *)((longlong)_Src + 8) + *(int *)((longlong)_Src + 0xc) + 0x14;
  uVar1 = *(uint *)(lVar3 + 0x44);
  if (uVar4 <= *(uint *)(lVar3 + 0x44)) {
    uVar1 = uVar4;
  }
  *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)((longlong)_Src + 0x10);
  *(uint *)(lVar3 + 0x44) = uVar1;
  memcpy((void *)((ulonglong)*(uint *)(lVar3 + 0x40) + lVar3),_Src,(ulonglong)uVar1);
  return 0;
}



===== ErrDevIoDeviceControl @ 1c00085e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ErrDevIoDeviceControl(undefined8 param_1,undefined8 param_2)

{
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0xc0000010,0);
  return;
}



===== __security_init_cookie @ 1c0009008 =====

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



===== DriverEntry @ 1c000903c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  code *local_18;
  undefined8 local_10;
  
  local_24 = 0;
  local_10 = 0;
  local_28 = 0x20;
  local_20 = ErrDevDeviceAdd;
  local_18 = ErrDevDriverUnload;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_28,0);
  ErrDevGenericSciOneTimeInitDone = 0;
  _ErrDevGenericSciErrorSourceListLock = 0;
  _ErrDevGenericSciErrorSourceListLockV2 = 0;
  DAT_1c0005458 = &ErrDevGenericSciErrorSourceListHead;
  ErrDevGenericSciErrorSourceListHead = &ErrDevGenericSciErrorSourceListHead;
  DAT_1c0005448 = &ErrDevGenericSciErrorSourceListHeadV2;
  ErrDevGenericSciErrorSourceListHeadV2 = &ErrDevGenericSciErrorSourceListHeadV2;
  WheaConfigureErrorSource(8,&ErrDevErrSrcConfiguration);
  WheaConfigureErrorSource(0xd,&ErrDevErrSrcConfigurationV2);
  return uVar1;
}


