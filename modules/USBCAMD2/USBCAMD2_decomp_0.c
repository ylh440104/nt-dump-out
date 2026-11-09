
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



===== _guard_check_icall @ 1c0001020 =====

void _guard_check_icall(void)

{
                    /* 0x1020  4  USBCAMD_Debug_LogEntry */
  return;
}



===== USBCAMD_BuildIoRequest @ 1c000102c =====

longlong USBCAMD_BuildIoRequest
                   (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = IoAllocateIrp(*(undefined1 *)(*(longlong *)(param_1 + 0xe8) + 0x4c),0);
  if (lVar2 != 0) {
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(undefined8 *)(lVar1 + -0x40) = param_3;
    *(undefined4 *)(lVar1 + -0x30) = 0x220003;
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(undefined8 *)(lVar1 + -0x10) = param_4;
    *(undefined8 *)(lVar1 + -8) = param_2;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
  }
  return lVar2;
}



===== USBCAMD_CompleteReadRequest @ 1c00010b0 =====

void USBCAMD_CompleteReadRequest(longlong param_1,longlong param_2,undefined1 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 8);
  *(longlong *)(param_2 + 0x48) = param_1;
  *(undefined1 *)(param_2 + 0x41) = param_3;
  *(uint *)(param_2 + 0x20) = (uint)*(byte *)(param_1 + 0x2a4);
  uVar2 = USBCAMD_AcquireIdleLock((int *)(param_1 + 0x28));
  if ((int)uVar2 == 0) {
    ExInterlockedInsertTailList(lVar1 + 0x48,param_2 + 8,lVar1 + 0x58);
    KeReleaseSemaphore(lVar1 + 0x60,0,1);
  }
  else {
    USBCAMD_CompleteRead(param_1,param_2,0,0);
  }
  return;
}



===== USBCAMD_InitializeIsoTransfer @ 1c0001144 =====

undefined8 USBCAMD_InitializeIsoTransfer(longlong param_1,longlong param_2,ulonglong param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  
  lVar7 = (param_3 & 0xffffffff) * 0xd0;
  uVar2 = 0;
  lVar3 = *(longlong *)(param_1 + 0x110);
  puVar6 = (undefined8 *)(param_2 + 0xa0 + lVar7);
  if (*(int *)(param_2 + 0x20) == 0) {
    *(undefined4 *)puVar6 = 0x5452414e;
    puVar6[0x18] = param_1;
    puVar6[0x19] = param_2;
    uVar1 = *(ushort *)(lVar3 + ((longlong)*(int *)(param_2 + 0x2ac) + 1) * 0x18);
    if (uVar1 == 0) {
      uVar2 = 0xc000009c;
    }
    else {
      iVar5 = (uVar1 + 1) * 0x20;
      *(int *)((longlong)puVar6 + 0x24) = iVar5;
      lVar3 = ExAllocatePool2(0x40,iVar5,0x4d414355);
      puVar6[5] = lVar3;
      puVar6[6] = lVar3;
      if (lVar3 == 0) {
        uVar2 = 0xc000009a;
      }
      else {
        puVar6[5] = lVar3 + 0x20;
        lVar3 = ExAllocatePoolWithTag(0x600,0x430,0x63425355);
        puVar6[0xb] = lVar3;
        if (lVar3 == 0) {
          uVar2 = 0xc000009a;
          ExFreePool(puVar6[6]);
          puVar6[6] = 0;
        }
        else {
          puVar6[7] = lVar3;
          puVar6[8] = lVar3 + 0x218;
        }
      }
    }
  }
  else {
    puVar4 = (undefined8 *)(*(longlong *)(param_1 + 8) + 0xa0 + lVar7);
    uVar2 = puVar4[1];
    *puVar6 = *puVar4;
    puVar6[1] = uVar2;
    uVar2 = puVar4[3];
    puVar6[2] = puVar4[2];
    puVar6[3] = uVar2;
    uVar2 = puVar4[5];
    puVar6[4] = puVar4[4];
    puVar6[5] = uVar2;
    uVar2 = puVar4[7];
    puVar6[6] = puVar4[6];
    puVar6[7] = uVar2;
    uVar2 = puVar4[9];
    puVar6[8] = puVar4[8];
    puVar6[9] = uVar2;
    uVar2 = puVar4[0xb];
    puVar6[10] = puVar4[10];
    puVar6[0xb] = uVar2;
    uVar2 = puVar4[0xd];
    puVar6[0xc] = puVar4[0xc];
    puVar6[0xd] = uVar2;
    uVar2 = puVar4[0xf];
    puVar6[0xe] = puVar4[0xe];
    puVar6[0xf] = uVar2;
    uVar2 = puVar4[0x11];
    puVar6[0x10] = puVar4[0x10];
    puVar6[0x11] = uVar2;
    uVar2 = puVar4[0x13];
    puVar6[0x12] = puVar4[0x12];
    puVar6[0x13] = uVar2;
    uVar2 = puVar4[0x15];
    puVar6[0x14] = puVar4[0x14];
    puVar6[0x15] = uVar2;
    uVar2 = puVar4[0x17];
    puVar6[0x16] = puVar4[0x16];
    puVar6[0x17] = uVar2;
    uVar2 = puVar4[0x19];
    puVar6[0x18] = puVar4[0x18];
    puVar6[0x19] = uVar2;
    puVar6[10] = 0;
    puVar6[9] = 0;
    uVar2 = 0;
    puVar6[0x19] = param_2;
  }
  return uVar2;
}



===== USBCAMD_InitializeIsoUrb @ 1c00012e0 =====

undefined8
USBCAMD_InitializeIsoUrb(undefined8 param_1,undefined4 *param_2,ushort *param_3,undefined8 param_4)

{
  ushort uVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  int iVar5;
  
  uVar1 = *param_3;
  memset(param_2 + 1,0,0x214);
  *param_2 = 0xa0218;
  uVar2 = *(undefined8 *)(param_3 + 4);
  *(undefined8 *)(param_2 + 0xe) = 0;
  iVar5 = 0;
  *(undefined8 *)(param_2 + 6) = uVar2;
  param_2[8] = 5;
  param_2[0x21] = 0x20;
  uVar4 = 0;
  do {
    uVar3 = (int)uVar4 + 1;
    param_2[uVar4 * 3 + 0x23] = iVar5;
    iVar5 = iVar5 + (uint)uVar1;
    uVar4 = (ulonglong)uVar3;
  } while (uVar3 < (uint)param_2[0x21]);
  *(undefined8 *)(param_2 + 0xc) = 0;
  *(undefined8 *)(param_2 + 10) = param_4;
  param_2[9] = param_2[0x21] * (uint)uVar1;
  return 0;
}



===== USBCAMD_IsoIrp_Complete @ 1c0001390 =====

undefined8 USBCAMD_IsoIrp_Complete(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  undefined1 uVar6;
  int iVar7;
  
  lVar2 = *(longlong *)(param_3 + 200);
  lVar3 = *(longlong *)(param_3 + 0xc0);
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x240);
  lVar4 = *(longlong *)(param_3 + 0x48);
  plVar1 = (longlong *)(param_3 + 0x50);
  if (param_2 == lVar4) {
    *(undefined8 *)(param_3 + 0x48) = 0;
LAB_1c00013f5:
    if (*plVar1 != 0) goto LAB_1c0001400;
    bVar5 = true;
  }
  else {
    if (param_2 == *plVar1) {
      *plVar1 = 0;
    }
    if (lVar4 == 0) goto LAB_1c00013f5;
LAB_1c0001400:
    bVar5 = false;
  }
  KeReleaseSpinLock(lVar2 + 0x240,CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar6));
  if ((((*(uint *)(lVar2 + 0x10) & 1) != 0) || (*(int *)(lVar2 + 0x14) != 0)) ||
     (*(char *)(param_2 + 0x44) != '\0')) goto LAB_1c0001479;
  if (*(int *)(param_2 + 0x30) == 0) {
    if (!bVar5) goto LAB_1c0001479;
    iVar7 = 0;
    if (*(int *)(*(longlong *)(param_3 + 0x40) + 4) != 0) {
      USBCAMD_ProcessResetRequest(lVar3,lVar2);
      iVar7 = -0x3fffffff;
    }
    if ((*(int *)(lVar2 + 0x2a8) == -1) || (*(int *)(*(longlong *)(param_3 + 0x38) + 4) == 0)) {
      if (iVar7 == 0) {
        USBCAMD_TransferComplete(param_3);
      }
      goto LAB_1c0001479;
    }
  }
  USBCAMD_ProcessResetRequest(lVar3,lVar2);
LAB_1c0001479:
  IoFreeIrp(param_2);
  USBCAMD_ReleaseIdleLock(lVar2 + 0x28);
  return 0xc0000016;
}



===== USBCAMD_ProcessIsoIrps @ 1c00014c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBCAMD_ProcessIsoIrps(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  int *_Src;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  uint uVar9;
  uint local_res10 [2];
  int local_res18;
  undefined8 uVar10;
  undefined4 uVar11;
  
  local_res10[0] = 0;
  KeSetPriorityThread(SystemReserved1[0xf],0x10);
  lVar5 = 0;
  do {
    lVar7 = 0;
    do {
      uVar10 = 0;
      KeWaitForSingleObject(param_1 + 0x60,0,0,0,0);
      uVar11 = (undefined4)((ulonglong)uVar10 >> 0x20);
      if (*(char *)(param_1 + 0x80) != '\0') {
        while( true ) {
          lVar4 = ExInterlockedRemoveHeadList(param_1 + 0x48,param_1 + 0x58);
          uVar11 = (undefined4)((ulonglong)uVar10 >> 0x20);
          if (lVar4 == 0) break;
          lVar6 = *(longlong *)(lVar4 + 0x40);
          USBCAMD_CompleteRead(lVar6,lVar4 + -8,-0x3ffffee0,0);
          USBCAMD_ReleaseIdleLock(lVar6 + 0x28);
        }
        PsTerminateSystemThread(0);
      }
      lVar4 = ExInterlockedRemoveHeadList(param_1 + 0x48);
    } while (lVar4 == 0);
    local_res18 = 0;
    lVar6 = *(longlong *)(lVar4 + 0x10);
    lVar2 = *(longlong *)(lVar4 + 0x40);
    *(undefined4 *)(*(longlong *)(lVar6 + 0x28) + 0x30) = 0;
    _Src = *(int **)(*(longlong *)(lVar6 + 0x28) + 0x28);
    if (*(char *)(lVar4 + 0x38) == '\0') {
      local_res10[0] = *(uint *)(lVar4 + 0x30);
      uVar1 = *(undefined4 *)(*(longlong *)(lVar2 + 0x300) + 0x44);
      if (*(int *)(param_1 + 0x1a0) == 0x200) {
        if (*(char *)(lVar2 + 0x329) == '\0') {
          *_Src = -0x5310113;
          local_res18 = (**(code **)(param_1 + 0x160))
                                  (*(undefined8 *)(param_1 + 0xe8),param_1 + 0x1f8,lVar4 + 0x48,_Src
                                   ,CONCAT44(uVar11,uVar1),*(undefined8 *)(lVar4 + 0x20),
                                   *(undefined4 *)(lVar4 + 0x28),*(undefined4 *)(lVar4 + 0x1c),
                                   local_res10,*(undefined4 *)(lVar4 + 0x30),
                                   *(undefined4 *)(lVar4 + 0x18));
          goto LAB_1c00016b0;
        }
      }
      else {
        *_Src = -0x5310113;
        local_res18 = (**(code **)(param_1 + 0x160))
                                (*(undefined8 *)(param_1 + 0xe8),param_1 + 0x1f8,lVar4 + 0x48,_Src,
                                 CONCAT44(uVar11,uVar1),*(undefined8 *)(lVar4 + 0x20),
                                 *(undefined4 *)(lVar4 + 0x28),*(undefined4 *)(lVar4 + 0x1c),
                                 local_res10);
LAB_1c00016b0:
        if ((-1 < local_res18) && (*_Src == -0x5310113)) {
          local_res10[0] = 0;
        }
      }
      lVar6 = lVar5;
      if (*(char *)(lVar4 + 0x39) != '\0') {
        if (((*(uint *)(param_1 + 0x134) & 8) != 0) && (*(int *)(param_1 + 0x1b0) != 0)) {
          StreamClassDeviceNotification(2,param_1,&USBCAMD_KSEVENTSETID_VIDCAPTOSTI);
        }
        lVar6 = *(longlong *)(param_1 + 0x10);
        if (((lVar6 != 0) && (*(int *)(lVar6 + 0x1c) != 0)) && (*(int *)(lVar6 + 0x18) != 0)) {
          lVar5 = ExInterlockedRemoveHeadList(lVar6 + 0x288,lVar6 + 0x298);
          if (lVar5 != 0) {
            lVar7 = lVar5 + -8;
            lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x28);
            if (*(uint *)(lVar3 + 0x20) < local_res10[0]) {
              ExInterlockedInsertHeadList(lVar6 + 0x288,lVar5,lVar6 + 0x298);
              lVar7 = 0;
            }
            else {
              memcpy(*(void **)(lVar3 + 0x28),_Src,(ulonglong)local_res10[0]);
            }
          }
        }
      }
      iVar8 = local_res18;
      USBCAMD_CompleteRead(lVar2,lVar4 + -8,local_res18,local_res10[0]);
      if (lVar7 != 0) {
        lVar5 = lVar6;
        uVar9 = local_res10[0];
        goto LAB_1c00017a5;
      }
    }
    else {
      *(undefined1 *)(lVar4 + 0x38) = 0;
      iVar8 = 0;
      lVar6 = lVar2;
      lVar7 = lVar4 + -8;
      uVar9 = 0;
LAB_1c00017a5:
      USBCAMD_CompleteRead(lVar6,lVar7,iVar8,uVar9);
      lVar6 = lVar5;
    }
    USBCAMD_ReleaseIdleLock(lVar2 + 0x28);
    lVar5 = lVar6;
  } while( true );
}



===== USBCAMD_SubmitIsoTransfer @ 1c00017dc =====

ulonglong USBCAMD_SubmitIsoTransfer
                    (longlong param_1,longlong param_2,undefined4 param_3,char param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong *plVar9;
  
  lVar8 = *(longlong *)(param_2 + 200);
  if ((*(int *)(param_1 + 0xdc) == 0) ||
     (puVar2 = *(undefined8 **)(param_2 + 0x30), puVar2 == (undefined8 *)0x0)) {
    return 0xc000009c;
  }
  lVar1 = lVar8 + 0x240;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (*(int *)(lVar8 + 0x2a8) == -1) {
LAB_1c0001889:
    lVar5 = USBCAMD_BuildIoRequest
                      (param_1,param_2,*(undefined8 *)(param_2 + 0x40),USBCAMD_IsoIrp_Complete);
    *(longlong *)(param_2 + 0x50) = lVar5;
    if (lVar5 == 0) {
LAB_1c00018b5:
      uVar7 = 0xc000009a;
    }
    else {
      uVar7 = USBCAMD_AcquireIdleLock((int *)(lVar8 + 0x28));
      uVar7 = uVar7 & 0xffffffff;
    }
  }
  else {
    lVar5 = USBCAMD_BuildIoRequest
                      (param_1,param_2,*(undefined8 *)(param_2 + 0x38),USBCAMD_IsoIrp_Complete);
    *(longlong *)(param_2 + 0x48) = lVar5;
    if (lVar5 == 0) goto LAB_1c00018b5;
    uVar6 = USBCAMD_AcquireIdleLock((int *)(lVar8 + 0x28));
    uVar7 = uVar6 & 0xffffffff;
    if ((int)uVar6 == 0) goto LAB_1c0001889;
  }
  plVar9 = (longlong *)(param_2 + 0x48);
  KeReleaseSpinLock(lVar1,uVar3);
  if ((int)uVar7 == 0) {
    if (*plVar9 != 0) {
      lVar5 = (longlong)*(int *)(lVar8 + 0x2a8) + 1;
      USBCAMD_InitializeIsoUrb
                (lVar5 * 3,*(undefined4 **)(param_2 + 0x38),
                 (ushort *)(*(longlong *)(param_1 + 0x110) + lVar5 * 0x18),
                 *(undefined8 *)(param_2 + 0x30));
      lVar5 = *(longlong *)(param_2 + 0x38);
      if (param_4 == '\0') {
        *(uint *)(lVar5 + 0x20) = *(uint *)(lVar5 + 0x20) & 0xfffffffb;
        *(undefined4 *)(*(longlong *)(param_2 + 0x38) + 0x80) = param_3;
      }
      else {
        *(uint *)(lVar5 + 0x20) = *(uint *)(lVar5 + 0x20) | 4;
      }
      uVar4 = IofCallDriver(*(undefined8 *)(param_1 + 0xe8),*plVar9);
      uVar7 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) {
        uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
        IoFreeIrp(*(undefined8 *)(param_2 + 0x50));
        *(undefined8 *)(param_2 + 0x50) = 0;
        USBCAMD_ReleaseIdleLock(lVar8 + 0x28);
        goto LAB_1c0001a56;
      }
    }
    lVar8 = (longlong)*(int *)(lVar8 + 0x2ac) + 1;
    USBCAMD_InitializeIsoUrb
              (lVar8 * 3,*(undefined4 **)(param_2 + 0x40),
               (ushort *)(*(longlong *)(param_1 + 0x110) + lVar8 * 0x18),
               *(undefined8 *)(param_2 + 0x28));
    lVar8 = *(longlong *)(param_2 + 0x40);
    if (param_4 == '\0') {
      *(uint *)(lVar8 + 0x20) = *(uint *)(lVar8 + 0x20) & 0xfffffffb;
      *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x80) = param_3;
    }
    else {
      *(uint *)(lVar8 + 0x20) = *(uint *)(lVar8 + 0x20) | 4;
    }
    uVar4 = IofCallDriver(*(undefined8 *)(param_1 + 0xe8),*(undefined8 *)(param_2 + 0x50));
    uVar7 = 0;
    if (uVar4 != 0x103) {
      uVar7 = (ulonglong)uVar4;
    }
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    if (*plVar9 != 0) {
      IoFreeIrp();
      *plVar9 = 0;
      USBCAMD_ReleaseIdleLock(lVar8 + 0x28);
    }
    if (*(longlong *)(param_2 + 0x50) != 0) {
      IoFreeIrp();
      *(undefined8 *)(param_2 + 0x50) = 0;
      USBCAMD_ReleaseIdleLock(lVar8 + 0x28);
    }
LAB_1c0001a56:
    KeReleaseSpinLock(lVar8 + 0x240,uVar3);
  }
  return uVar7;
}



===== USBCAMD_TransferComplete @ 1c0001a90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 USBCAMD_TransferComplete(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  void *_Dst;
  longlong lVar8;
  ulonglong _Size;
  longlong lVar9;
  undefined1 *puVar10;
  longlong lVar11;
  longlong lVar12;
  undefined4 *puVar13;
  undefined1 local_res8 [8];
  ulonglong local_res10;
  
  lVar4 = *(longlong *)(param_1 + 0xc0);
  local_res8[0] = 0;
  uVar5 = *(uint *)(*(longlong *)(param_1 + 0x40) + 0x84);
  KeAcquireSpinLockAtDpcLevel(*(longlong *)(param_1 + 200) + 0x98);
  if (uVar5 != 0) {
    lVar12 = 0;
    lVar11 = 0;
    puVar1 = (uint *)(param_1 + 0x18);
    local_res10 = (ulonglong)uVar5;
    do {
      puVar10 = (undefined1 *)(param_1 + 0x20);
      puVar13 = (undefined4 *)(param_1 + 0x1c);
      *puVar13 = 0;
      *puVar1 = 0;
      *puVar10 = 0;
      if ((*(longlong *)(lVar4 + 0x10) == 0) ||
         (lVar7 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x90), lVar7 == 0)) {
        lVar7 = *(longlong *)(*(longlong *)(param_1 + 200) + 0x90);
        lVar9 = 0;
        if (lVar7 != 0) goto LAB_1c0001b3d;
      }
      else {
LAB_1c0001b3d:
        lVar9 = lVar7 + 0x50;
      }
      lVar7 = *(longlong *)(param_1 + 0x38) + lVar11 * 0xc;
      lVar6 = *(longlong *)(param_1 + 0x28) +
              (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x40) + 0x8c + lVar12);
      lVar2 = *(longlong *)(param_1 + 0x40) + 0x8c + lVar11 * 0xc;
      lVar8 = *(longlong *)(param_1 + 0x30) + lVar11;
      if (*(int *)(lVar4 + 0x1a0) == 0x200) {
        uVar5 = (**(code **)(lVar4 + 0x150))
                          (*(undefined8 *)(lVar4 + 0xe8),lVar4 + 0x1f8,lVar9,lVar7 + 0x8c,lVar8,
                           lVar2,lVar6,puVar10,puVar1,puVar13);
      }
      else {
        uVar5 = (**(code **)(lVar4 + 0x150))
                          (*(undefined8 *)(lVar4 + 0xe8),lVar4 + 0x1f8,lVar9,lVar7 + 0x8c,lVar8,
                           lVar2,lVar6,puVar10,local_res8);
        *puVar13 = 0;
      }
      _Size = (ulonglong)uVar5;
      if ((*puVar1 & 8) != 0) {
        *(undefined4 *)(*(longlong *)(param_1 + 200) + 0x24) = 1;
      }
      if (((*puVar1 & 2) != 0) &&
         (((*(longlong *)(lVar4 + 0x10) != 0 &&
           (lVar7 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x90), lVar7 != 0)) ||
          ((*(longlong *)(lVar4 + 8) != 0 &&
           (lVar7 = *(longlong *)(*(longlong *)(lVar4 + 8) + 0x90), lVar7 != 0)))))) {
        *(undefined1 *)(lVar7 + 0x40) = 1;
      }
      lVar7 = *(longlong *)(lVar4 + 0x10);
      if (*(char *)(param_1 + 0x20) == '\0') {
        if (((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x90), lVar7 == 0)) &&
           ((*(longlong *)(lVar4 + 8) == 0 ||
            (lVar7 = *(longlong *)(*(longlong *)(lVar4 + 8) + 0x90), lVar7 == 0)))) {
          lVar7 = 0;
        }
        if ((((uVar5 != 0) && (lVar7 != 0)) && (lVar9 = *(longlong *)(lVar7 + 0x28), lVar9 != 0)) &&
           (_Dst = (void *)((ulonglong)*(uint *)(lVar7 + 0x3c) + lVar9),
           (longlong)_Dst + _Size <= (ulonglong)*(uint *)(lVar7 + 0x30) + lVar9)) {
          *(int *)(lVar7 + 0x24) = *(int *)(lVar7 + 0x24) + 1;
          *(int *)(lVar7 + 0x38) = *(int *)(lVar7 + 0x38) + uVar5;
LAB_1c0001dc9:
          memcpy(_Dst,(void *)((ulonglong)*(uint *)(*(longlong *)(param_1 + 0x40) + 0x8c + lVar12) +
                               (ulonglong)*(uint *)(param_1 + 0x1c) + *(longlong *)(param_1 + 0x28))
                 ,_Size);
          *(int *)(lVar7 + 0x3c) = *(int *)(lVar7 + 0x3c) + uVar5;
        }
      }
      else {
        if (((lVar7 != 0) && (lVar7 = *(longlong *)(lVar7 + 0x90), lVar7 != 0)) ||
           ((*(longlong *)(lVar4 + 8) != 0 &&
            (lVar7 = *(longlong *)(*(longlong *)(lVar4 + 8) + 0x90), lVar7 != 0)))) {
          uVar3 = *(uint *)(*(longlong *)(*(longlong *)(lVar7 + 0x18) + 0x10) + 4);
          *(undefined8 *)(*(longlong *)(lVar4 + 8 + (ulonglong)uVar3 * 8) + 0x90) = 0;
          if (*(int *)(*(longlong *)(param_1 + 200) + 0x24) == 0) {
            if (*(char *)(lVar7 + 0x40) == '\0') {
              if (uVar3 == 0) {
                lVar9 = *(longlong *)(lVar4 + 8);
              }
              else {
                lVar9 = *(longlong *)(lVar4 + 0x10);
              }
              USBCAMD_CompleteReadRequest(lVar9,lVar7,0);
            }
            else {
              *(undefined1 *)(lVar7 + 0x40) = 0;
              ExInterlockedInsertHeadList
                        (*(longlong *)(lVar4 + 8 + (ulonglong)uVar3 * 8) + 0x288,lVar7 + 8);
            }
          }
          else {
            USBCAMD_CompleteReadRequest(*(longlong *)(param_1 + 200),lVar7,1);
            *(undefined4 *)(*(longlong *)(param_1 + 200) + 0x24) = 0;
          }
        }
        if ((*puVar1 & 4) == 0) {
          lVar7 = *(longlong *)(lVar4 + 8);
        }
        else {
          lVar7 = *(longlong *)(lVar4 + 0x10);
        }
        lVar9 = ExInterlockedRemoveHeadList(lVar7 + 0x288,lVar7 + 0x298);
        if (lVar9 != 0) {
          lVar7 = lVar9 + -8;
          *(longlong *)
           (*(longlong *)
             (lVar4 + 8 +
             (ulonglong)*(uint *)(*(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x10) + 4) * 8) + 0x90
           ) = lVar7;
          *(undefined4 *)(lVar9 + 0x34) = 0;
          *(undefined4 *)(lVar9 + 0x1c) = 0;
          *(undefined4 *)(lVar9 + 0x30) = 0;
          *(undefined1 *)(lVar9 + 0x38) = 0;
          if (*(int *)(lVar4 + 0x1a0) == 0x200) {
            *(undefined4 *)(lVar9 + 0x2c) = *(undefined4 *)(lVar9 + 0x28);
            (**(code **)(lVar4 + 0x158))();
          }
          else {
            (**(code **)(lVar4 + 0x158))(lVar4 + 0x1f8,lVar9 + 0x48);
          }
          if ((uVar5 != 0) && (lVar2 = *(longlong *)(lVar9 + 0x20), lVar2 != 0)) {
            _Dst = (void *)((ulonglong)*(uint *)(lVar9 + 0x34) + lVar2);
            *(undefined4 *)(lVar9 + 0x1c) = 1;
            *(uint *)(lVar9 + 0x30) = uVar5;
            if ((longlong)_Dst + _Size <= (ulonglong)*(uint *)(lVar9 + 0x28) + lVar2)
            goto LAB_1c0001dc9;
          }
        }
      }
      lVar11 = lVar11 + 1;
      lVar12 = lVar12 + 0xc;
      local_res10 = local_res10 - 1;
    } while (local_res10 != 0);
  }
  KeReleaseSpinLockFromDpcLevel(*(longlong *)(param_1 + 200) + 0x98);
  USBCAMD_SubmitIsoTransfer(lVar4,param_1,0,'\x01');
  return 0;
}



===== USBCAMD_CancelQueuedSRBs @ 1c0001ec8 =====

void USBCAMD_CancelQueuedSRBs(longlong param_1)

{
  longlong *******ppppppplVar1;
  longlong lVar2;
  longlong lVar3;
  longlong ******pppppplVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong ******pppppplVar7;
  longlong *******ppppppplVar8;
  longlong *******local_28;
  longlong *******local_20;
  
  lVar2 = *(longlong *)(param_1 + 8);
  local_20 = (longlong *******)&local_28;
  local_28 = (longlong *******)&local_28;
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x98);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x298);
  lVar3 = *(longlong *)(param_1 + 0x90);
  ppppppplVar1 = (longlong *******)(param_1 + 0x288);
  if (lVar3 != 0) {
    *(undefined8 *)(param_1 + 0x90) = 0;
    pppppplVar7 = (longlong ******)(lVar3 + 8);
    pppppplVar4 = *ppppppplVar1;
    if ((longlong *******)pppppplVar4[1] != ppppppplVar1) goto LAB_1c0002034;
    *pppppplVar7 = (longlong *****)pppppplVar4;
    *(longlong ********)(lVar3 + 0x10) = ppppppplVar1;
    pppppplVar4[1] = (longlong *****)pppppplVar7;
    *ppppppplVar1 = pppppplVar7;
  }
  if ((*(char *)(param_1 + 0x32a) == '\0') || (*(char *)(lVar2 + 0x12e) != '\0')) {
    while (ppppppplVar8 = (longlong *******)*ppppppplVar1, ppppppplVar8 != ppppppplVar1) {
      if (((longlong *******)ppppppplVar8[1] != ppppppplVar1) ||
         (pppppplVar4 = *ppppppplVar8, (longlong *******)pppppplVar4[1] != ppppppplVar8))
      goto LAB_1c0002034;
      *ppppppplVar1 = pppppplVar4;
      pppppplVar4[1] = (longlong *****)ppppppplVar1;
      if ((longlong ********)*local_20 != &local_28) goto LAB_1c0002034;
      ppppppplVar8[1] = (longlong ******)local_20;
      *ppppppplVar8 = (longlong ******)&local_28;
      *local_20 = (longlong ******)ppppppplVar8;
      local_20 = ppppppplVar8;
    }
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x298);
  KeReleaseSpinLock(param_1 + 0x98,uVar6);
  while( true ) {
    if ((longlong ********)local_28 == &local_28) {
      return;
    }
    if (((longlong ********)local_28[1] != &local_28) ||
       (ppppppplVar1 = (longlong *******)*local_28, (longlong *******)ppppppplVar1[1] != local_28))
    break;
    ppppppplVar1[1] = (longlong ******)&local_28;
    ppppppplVar8 = local_28 + -1;
    local_28 = ppppppplVar1;
    USBCAMD_CompleteRead(param_1,(longlong)ppppppplVar8,-0x3ffffee0,0);
  }
LAB_1c0002034:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  return;
}



===== USBCAMD_GetPortStatus @ 1c000205c =====

int USBCAMD_GetPortStatus(longlong param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  
  KeWaitForSingleObject(param_1 + 0x98,0,0,0,0);
  *param_3 = 0;
  iVar1 = USBCAMD_CallUSBD(param_1,0,0x220013,(longlong)param_3);
  KeReleaseSemaphore(param_1 + 0x98,0x10,1);
  return iVar1;
}



===== USBCAMD_ProcessResetRequest @ 1c00020e0 =====

undefined8 USBCAMD_ProcessResetRequest(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x90 + (ulonglong)*(byte *)(param_2 + 0x2a4) * 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (*piVar1 == 0 || SCARRY4(iVar2,1) != *piVar1 < 0) {
    puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x30,0x4d414355);
    if (puVar3 == (undefined8 *)0x0) {
      LOCK();
      piVar1 = (int *)(param_1 + 0x90 + (ulonglong)*(byte *)(param_2 + 0x2a4) * 4);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      uVar4 = 0;
    }
    else {
      *puVar3 = 0;
      puVar3[2] = USBCAMD_ResetWorkItem;
      puVar3[3] = puVar3;
      puVar3[4] = param_2;
      *(undefined4 *)(param_2 + 0x14) = 1;
      uVar4 = ExQueueWorkItem(puVar3,0);
    }
    uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  }
  else {
    LOCK();
    piVar1 = (int *)(param_1 + 0x90 + (ulonglong)*(byte *)(param_2 + 0x2a4) * 4);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    uVar4 = 0;
  }
  return uVar4;
}



===== USBCAMD_ResetChannel @ 1c0002188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBCAMD_ResetChannel(longlong param_1,longlong param_2,uint param_3,int param_4)

{
  int *piVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong lVar8;
  
  iVar4 = 0;
  KeWaitForSingleObject(param_1 + 0x98,0,0,0,0);
  bVar2 = *(byte *)(param_2 + 0x2a4);
  if (*(int *)(param_2 + 0x1c) == 0) goto LAB_1c0002405;
  if ((-1 < param_4) && ((param_3 & 1) == 0)) {
    iVar4 = USBCAMD_CallUSBD(param_1,0,0x220017,0);
    if (iVar4 == -0x3fffff45) {
      iVar4 = USBCAMD_CallUSBD(param_1,0,0x220007,0);
    }
    if (iVar4 < 0) goto LAB_1c0002405;
  }
  iVar4 = USBCAMD_ResetPipes(param_1,param_2,*(longlong *)(param_1 + 0x110),'\x01');
  if (iVar4 < 0) goto LAB_1c0002405;
  piVar1 = (int *)(param_2 + 0x28);
  iVar4 = USBCAMD_WaitForIdle(piVar1,2);
  if (iVar4 == 0x102) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x240);
    plVar6 = (longlong *)(param_2 + 0xf0);
    lVar8 = 2;
    do {
      lVar7 = lVar8;
      if (plVar6[-1] != 0) {
        IoCancelIrp();
      }
      if (*plVar6 != 0) {
        IoCancelIrp();
      }
      plVar6 = plVar6 + 0x1a;
      lVar8 = lVar7 + -1;
    } while (lVar8 != 0);
    KeReleaseSpinLock(param_2 + 0x240,uVar3);
    iVar4 = USBCAMD_WaitForIdle(piVar1,(int)lVar7 + 1);
  }
  if ((iVar4 != 0) ||
     (iVar4 = USBCAMD_ResetPipes(param_1,param_2,*(longlong *)(param_1 + 0x110),'\0'), iVar4 < 0))
  goto LAB_1c0002405;
  uVar5 = USBCAMD_AcquireIdleLock(piVar1);
  iVar4 = (int)uVar5;
  if (iVar4 < 0) goto LAB_1c0002405;
  if (*(int *)(param_2 + 0x18) != 0) {
    lVar8 = param_1 + 0x1f8;
    if (*(int *)(param_1 + 0x1a0) == 0x200) {
      iVar4 = (**(code **)(param_1 + 0x170))(*(undefined8 *)(param_1 + 0xe8),lVar8,bVar2);
      if (-1 < iVar4) {
        iVar4 = (**(code **)(param_1 + 0x168))(*(undefined8 *)(param_1 + 0xe8),lVar8,bVar2);
        goto LAB_1c000238e;
      }
    }
    else {
      iVar4 = (**(code **)(param_1 + 0x170))(*(undefined8 *)(param_1 + 0xe8),lVar8);
      if (-1 < iVar4) {
        iVar4 = (**(code **)(param_1 + 0x168))(*(undefined8 *)(param_1 + 0xe8),lVar8);
LAB_1c000238e:
        if (-1 < iVar4) {
          *(undefined4 *)(param_2 + 0x2a8) = *(undefined4 *)(param_1 + 0x11c);
          if ((uint)bVar2 == (int)*(char *)(param_1 + 0x124)) {
            *(undefined4 *)(param_2 + 0x2ac) = *(undefined4 *)(param_1 + 0x120);
            *(undefined1 *)(param_2 + 0x2a5) = 1;
            USBCAMD_StartIsoStream(param_1,param_2);
          }
          else if ((uint)bVar2 == (int)*(char *)(param_1 + 300)) {
            *(undefined4 *)(param_2 + 0x2ac) = *(undefined4 *)(param_1 + 0x128);
            *(undefined1 *)(param_2 + 0x2a5) = 2;
            USBCAMD_StartBulkStream(param_1,param_2);
          }
        }
      }
    }
  }
  USBCAMD_ReleaseIdleLock((longlong)piVar1);
LAB_1c0002405:
  KeReleaseSemaphore(param_1 + 0x98,0x10,1);
  return iVar4;
}



===== USBCAMD_ResetPipes @ 1c0002440 =====

int USBCAMD_ResetPipes(longlong param_1,longlong param_2,longlong param_3,char param_4)

{
  int iVar1;
  undefined2 *puVar2;
  short sVar3;
  
  puVar2 = (undefined2 *)ExAllocatePool2(0x40,0x28);
  if (puVar2 == (undefined2 *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *puVar2 = 0x28;
    sVar3 = (-(ushort)(param_4 != '\0') & 0xffe4) + 0x1e;
    puVar2[1] = sVar3;
    *(undefined8 *)(puVar2 + 0xc) =
         *(undefined8 *)(param_3 + 0x20 + (longlong)*(int *)(param_2 + 0x2ac) * 0x18);
    iVar1 = USBCAMD_CallUSBD(param_1,(longlong)puVar2,0,0);
    if ((-1 < iVar1) && (*(int *)(param_2 + 0x2a8) != -1)) {
      *puVar2 = 0x28;
      puVar2[1] = sVar3;
      *(undefined8 *)(puVar2 + 0xc) =
           *(undefined8 *)(param_3 + 0x20 + (longlong)*(int *)(param_2 + 0x2a8) * 0x18);
      iVar1 = USBCAMD_CallUSBD(param_1,(longlong)puVar2,0,0);
    }
    ExFreePool(puVar2);
  }
  return iVar1;
}



===== USBCAMD_ResetWorkItem @ 1c0002550 =====

void USBCAMD_ResetWorkItem(longlong param_1,undefined8 param_2)

{
  int *piVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  uint local_res8 [2];
  
  lVar3 = *(longlong *)(param_1 + 0x20);
  lVar4 = *(longlong *)(lVar3 + 8);
  bVar2 = *(byte *)(lVar3 + 0x2a4);
  if (*(int *)(lVar3 + 0x20) == 0) {
    local_res8[0] = 0;
    iVar5 = USBCAMD_GetPortStatus(lVar4,param_2,local_res8);
    if (iVar5 < 0) {
      if (*(int *)(lVar3 + 0x18) != 0) {
        USBCAMD_StopChannel(lVar4,lVar3);
      }
      if (*(int *)(lVar3 + 0x1c) != 0) {
        USBCAMD_UnPrepareChannel(lVar4,lVar3);
      }
    }
    else {
      USBCAMD_ResetChannel(lVar4,lVar3,local_res8[0],iVar5);
      *(undefined4 *)(lVar3 + 0x14) = 0;
    }
  }
  LOCK();
  piVar1 = (int *)(lVar4 + 0x90 + (ulonglong)bVar2 * 4);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  ExFreePool(param_1);
  return;
}



===== AdapterCancelPacket @ 1c0002600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AdapterCancelPacket(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  code *pcVar5;
  bool bVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  
  if ((*(uint *)(param_1 + 0x50) & 3) != 0) {
    bVar6 = false;
    lVar1 = *(longlong *)(param_1 + 0x18);
    puVar8 = (undefined8 *)0x0;
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
    if (*(char *)(lVar2 + 0x2a5) == '\x01') {
      KeAcquireSpinLockAtDpcLevel(lVar2 + 0x98);
      puVar8 = *(undefined8 **)(lVar2 + 0x90);
      if ((puVar8 == (undefined8 *)0x0) || (puVar8[3] != param_1)) {
        KeAcquireSpinLockAtDpcLevel(lVar2 + 0x298);
        puVar3 = *(undefined8 **)(lVar2 + 0x288);
        do {
          puVar7 = puVar3;
          bVar6 = false;
          if (puVar7 == (undefined8 *)(lVar2 + 0x288)) goto LAB_1c00026d8;
          puVar3 = (undefined8 *)*puVar7;
          puVar8 = puVar7 + -1;
        } while (puVar7[2] != param_1);
        if (((undefined8 *)puVar3[1] != puVar7) ||
           (puVar4 = (undefined8 *)puVar7[1], (undefined8 *)*puVar4 != puVar7)) goto LAB_1c000280a;
        *puVar4 = puVar3;
        bVar6 = true;
        puVar3[1] = puVar4;
LAB_1c00026d8:
        KeReleaseSpinLockFromDpcLevel(lVar2 + 0x298);
      }
      else {
        *(undefined8 *)(lVar2 + 0x90) = 0;
        bVar6 = true;
      }
      KeReleaseSpinLockFromDpcLevel(lVar2 + 0x98);
    }
    else {
      USBCAMD_CancelOutstandingIrp(lVar1,(ulonglong)*(uint *)(lVar2 + 0x2ac),'\0');
      KeAcquireSpinLockAtDpcLevel(lVar2 + 0x298);
      puVar3 = *(undefined8 **)(lVar2 + 0x288);
      do {
        puVar7 = puVar3;
        if (puVar7 == (undefined8 *)(lVar2 + 0x288)) goto LAB_1c000274a;
        puVar3 = (undefined8 *)*puVar7;
        puVar8 = puVar7 + -1;
      } while (puVar7[2] != param_1);
      if (((undefined8 *)puVar3[1] != puVar7) ||
         (puVar4 = (undefined8 *)puVar7[1], (undefined8 *)*puVar4 != puVar7)) {
LAB_1c000280a:
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      *puVar4 = puVar3;
      bVar6 = true;
      puVar3[1] = puVar4;
LAB_1c000274a:
      KeReleaseSpinLockFromDpcLevel(lVar2 + 0x298);
      if (*(char *)(lVar2 + 0x329) == '\0') {
        (**(code **)(lVar1 + 0x160))
                  (*(undefined8 *)(lVar1 + 0xe8),lVar1 + 0x1f8,*(longlong *)(lVar2 + 0x90) + 0x50,0,
                   0,0,0,0,0,0,*(undefined4 *)(*(longlong *)(param_1 + 0x10) + 4));
      }
    }
    if (bVar6) {
      USBCAMD_CompleteRead(lVar2,(longlong)puVar8,-0x3ffffee0,0);
    }
  }
  return;
}



===== AdapterOpenStream @ 1c0002818 =====

void AdapterOpenStream(longlong param_1)

{
  int *piVar1;
  uint uVar2;
  longlong lVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  longlong lVar10;
  uint uVar11;
  ulonglong uVar12;
  uint local_res8 [2];
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  local_res8[0] = 0;
  puVar4 = *(uint **)(param_1 + 0x28);
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0x10) + 4);
  uVar12 = (ulonglong)uVar2;
  puVar5 = *(undefined4 **)(*(longlong *)(param_1 + 0x10) + 8);
  if ((uVar2 < *(uint *)(lVar3 + 0xd8)) && (*(int *)(lVar3 + 0xe0 + uVar12 * 4) == 0)) {
    if (*puVar4 < 0x98) {
      iVar7 = -0x3ffffdfa;
      goto LAB_1c0002a3e;
    }
    uVar11 = puVar4[0x1c] + 0x30;
    uVar6 = puVar4[0x1c] + 0x70;
    if ((((0x2f < uVar11) && (0x3f < uVar6)) && (uVar6 <= *puVar4)) &&
       ((uVar6 = CalculateImageSize((longlong)(puVar4 + 0x10),local_res8), -1 < (int)uVar6 &&
        (local_res8[0] <= puVar4[2])))) {
      if ((uVar2 == 1) && (*(char *)(lVar3 + 0x12d) != '\0')) {
        puVar5[8] = 1;
        if ((*(longlong *)(lVar3 + 8) == 0) ||
           (((*(uint *)(lVar3 + 0x134) & 4) != 0 &&
            (uVar6 = puVar4[0x1c],
            uVar8 = RtlCompareMemory(puVar4 + 0x1c,
                                     *(longlong *)(*(longlong *)(lVar3 + 8) + 0x300) + 0x30,uVar6),
            uVar8 != uVar6)))) goto LAB_1c0002a39;
      }
      else {
        puVar5[8] = 0;
      }
      *(byte *)(puVar5 + 0xa9) = (byte)uVar2;
      *(undefined4 **)(lVar3 + 8 + uVar12 * 8) = puVar5;
      *(byte *)((longlong)puVar5 + 0x329) =
           (byte)(*(uint *)(lVar3 + 0x134) >> ((byte)uVar2 & 0x1f)) & 1;
      uVar9 = USBCAMD_OpenChannel(lVar3,puVar5,*(undefined8 *)(param_1 + 0x28));
      iVar7 = (int)uVar9;
      if (-1 < iVar7) {
        uVar8 = USBCAMD_PrepareChannel(lVar3,(longlong)puVar5);
        iVar7 = (int)uVar8;
      }
      if (*(longlong *)(puVar4 + 0x1a) != 0) {
        if (-1 < iVar7) {
          *(undefined8 *)(puVar5 + 0xc6) = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10);
          *(undefined8 *)(puVar5 + 0xc4) = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x18);
          *(code **)(*(longlong *)(param_1 + 0x10) + 0x10) = USBCAMD_ReceiveDataPacket;
          *(code **)(*(longlong *)(param_1 + 0x10) + 0x18) = USBCAMD_ReceiveCtrlPacket;
          puVar5[0xc2] = 0;
          *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x20) = 0;
          *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x28) = 0;
          lVar10 = ExAllocatePool2(0x42,uVar11,0x4d414355);
          *(longlong *)(puVar5 + 0xc0) = lVar10;
          if (lVar10 == 0) {
            iVar7 = -0x3fffff66;
          }
          else {
            piVar1 = (int *)(lVar3 + 0xe0 + uVar12 * 4);
            *piVar1 = *piVar1 + 1;
            memcpy(*(void **)(puVar5 + 0xc0),puVar4 + 0x10,(ulonglong)uVar11);
            *(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x38) = 0;
            *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x48) = 0x48;
            *(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x39) = 1;
          }
          goto LAB_1c0002a3e;
        }
        *(undefined8 *)(lVar3 + 8 + uVar12 * 8) = 0;
      }
    }
  }
LAB_1c0002a39:
  iVar7 = -0x3ffffff3;
LAB_1c0002a3e:
  *(int *)(param_1 + 8) = iVar7;
  return;
}



===== AdapterStreamInfo @ 1c0002a68 =====

void AdapterStreamInfo(longlong param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  uint uVar4;
  ulonglong uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  puVar2 = *(undefined4 **)(param_1 + 0x28);
  puVar2[1] = 0x88;
  *puVar2 = *(undefined4 *)(lVar1 + 0xd8);
  *(undefined **)(puVar2 + 10) = &DAT_1c000b020;
  if ((*(uint *)(lVar1 + 0x134) & 8) != 0) {
    puVar2[6] = 1;
    *(undefined ***)(puVar2 + 8) = &VIDCAPTOSTIEventSet;
    *(code **)(puVar2 + 0xc) = USBCAMD_DeviceEventProc;
  }
  uVar5 = 0;
  if (*(int *)(lVar1 + 0xd8) != 0) {
    do {
      puVar3 = &PINNAME_VIDEO_CAPTURE;
      if ((int)uVar5 != 0) {
        puVar3 = &PINNAME_VIDEO_STILL;
      }
      uVar4 = (int)uVar5 + 1;
      *(undefined **)(puVar2 + uVar5 * 0x22 + 0x2a) = puVar3;
      *(undefined **)(puVar2 + uVar5 * 0x22 + 0x28) = puVar3;
      *(undefined ***)(puVar2 + uVar5 * 0x22 + 0x22) = &VideoStreamProperties;
      puVar2[uVar5 * 0x22 + 0x12] = 1;
      puVar2[uVar5 * 0x22 + 0x13] = 2;
      *(undefined1 *)(puVar2 + uVar5 * 0x22 + 0x14) = 1;
      puVar2[uVar5 * 0x22 + 0x20] = 2;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(lVar1 + 0xd8));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



===== AdapterTimeoutPacket @ 1c0002b40 =====

void AdapterTimeoutPacket(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x38);
  return;
}



===== CalculateImageSize @ 1c0002b50 =====

uint CalculateImageSize(longlong param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x34);
  uVar1 = *(ushort *)(param_1 + 0x3e);
  uVar2 = uVar4 * uVar1;
  *param_2 = uVar2;
  if ((uVar4 == 0) || (uVar2 / uVar4 == (uint)uVar1)) {
    uVar4 = -*(int *)(param_1 + 0x38);
    if (-*(int *)(param_1 + 0x38) < 0) {
      uVar4 = *(uint *)(param_1 + 0x38);
    }
    uVar2 = (uVar2 >> 3) + 3 & 0xfffffffc;
    uVar3 = uVar2 * uVar4;
    *param_2 = uVar3;
    if ((uVar2 == 0) || (uVar3 / uVar2 == uVar4)) {
      return -(uint)(*(uint *)(param_1 + 0x44) != uVar3) & 0xc000000d;
    }
  }
  return 0xc000000d;
}



===== DllUnload @ 1c0002bd0 =====

undefined8 DllUnload(void)

{
                    /* 0x2bd0  1  DllUnload */
  return 0;
}



===== HwInitialize @ 1c0002bdc =====

int HwInitialize(longlong param_1,undefined8 *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  longlong lVar7;
  
  lVar7 = *(longlong *)(param_1 + 0x28);
  puVar2 = *(undefined4 **)(lVar7 + 8);
  uVar3 = *(undefined8 *)(lVar7 + 0x18);
  if (*(int *)(lVar7 + 0x38) == 0) {
    puVar1 = (uint *)(*(longlong *)(lVar7 + 0x10) + 0x30);
    *puVar1 = *puVar1 | 0x10;
    puVar1 = (uint *)(*(longlong *)(lVar7 + 0x10) + 0x30);
    *puVar1 = *puVar1 & 0xffffff7f;
    *(undefined8 *)(puVar2 + 0x3a) = uVar3;
    *(undefined8 *)(puVar2 + 0x3c) = *(undefined8 *)(lVar7 + 0x10);
    *(undefined8 *)(puVar2 + 0x3e) = *(undefined8 *)(lVar7 + 0x68);
    puVar6 = puVar2 + 0x12;
    *(undefined4 **)(puVar2 + 0x14) = puVar6;
    *(undefined4 **)puVar6 = puVar6;
    KeInitializeSemaphore(puVar2 + 0x18,0,0x7fffffff);
    if (*(longlong *)(puVar2 + 0x3e) == 0) {
      *(undefined8 *)(puVar2 + 0x3e) = *(undefined8 *)(puVar2 + 0x3a);
    }
    *(undefined8 *)(puVar2 + 0x22) = 0;
    *puVar2 = 0x45564544;
    if (puVar2[0x68] != 0x200) {
      uVar3 = param_2[1];
      *(undefined8 *)(puVar2 + 0x4e) = *param_2;
      *(undefined8 *)(puVar2 + 0x50) = uVar3;
      uVar3 = param_2[3];
      *(undefined8 *)(puVar2 + 0x52) = param_2[2];
      *(undefined8 *)(puVar2 + 0x54) = uVar3;
      uVar3 = param_2[5];
      *(undefined8 *)(puVar2 + 0x56) = param_2[4];
      *(undefined8 *)(puVar2 + 0x58) = uVar3;
      uVar3 = param_2[7];
      *(undefined8 *)(puVar2 + 0x5a) = param_2[6];
      *(undefined8 *)(puVar2 + 0x5c) = uVar3;
      uVar3 = param_2[9];
      *(undefined8 *)(puVar2 + 0x5e) = param_2[8];
      *(undefined8 *)(puVar2 + 0x60) = uVar3;
      uVar3 = param_2[0xb];
      *(undefined8 *)(puVar2 + 0x62) = param_2[10];
      *(undefined8 *)(puVar2 + 100) = uVar3;
      *(undefined8 *)(puVar2 + 0x66) = param_2[0xc];
    }
    puVar2[0x36] = 1;
    *(undefined8 *)(puVar2 + 2) = 0;
    *(undefined8 *)(puVar2 + 4) = 0;
    puVar2[0x4c] = 1;
    puVar2[0x37] = 1;
    iVar4 = USBCAMD_StartDevice((longlong)puVar2);
    if (-1 < iVar4) {
      puVar6 = puVar2 + 0xe;
      *(int *)(lVar7 + 0x48) = puVar2[0x36] * 0x88 + 0x48;
      lVar7 = 2;
      puVar5 = puVar2 + 6;
      do {
        *(undefined4 **)(puVar5 + 2) = puVar5;
        *(undefined4 **)puVar5 = puVar5;
        puVar5 = puVar5 + 4;
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      KeInitializeSpinLock(puVar2 + 0x10);
      KeInitializeSpinLock(puVar2 + 0x16);
      puVar2[0x6c] = 0;
      *(undefined1 *)((longlong)puVar2 + 0x12e) = 0;
      puVar2[0x37] = 2;
    }
  }
  else {
    iVar4 = -0x3ffffff2;
  }
  return iVar4;
}



===== HwUnInitialize @ 1c0002d94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 HwUnInitialize(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  uVar4 = 0;
  if (*(int *)(lVar1 + 0xd8) != 0) {
    do {
      lVar2 = *(longlong *)(lVar1 + 8 + uVar4 * 8);
      if (lVar2 != 0) {
        USBCAMD_CleanupChannel(lVar1,lVar2,uVar4);
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(lVar1 + 0xd8));
  }
  *(undefined4 *)(lVar1 + 0xdc) = 0;
  if (*(longlong *)(lVar1 + 0x108) != 0) {
    (**(code **)(lVar1 + 0x148))(*(undefined8 *)(lVar1 + 0xe8));
    if (*(int *)(lVar1 + 0x1a0) == 0x200) {
      USBCAMD_CancelOutstandingBulkIntIrps(lVar1,'\0');
      if (*(longlong *)(lVar1 + 0x1a8) != 0) {
        ExFreePool();
        *(undefined8 *)(lVar1 + 0x1a8) = 0;
      }
    }
    if (*(longlong *)(lVar1 + 0x110) != 0) {
      ExFreePool();
      *(undefined8 *)(lVar1 + 0x110) = 0;
    }
    ExFreePool(*(undefined8 *)(lVar1 + 0x108));
    *(undefined8 *)(lVar1 + 0x108) = 0;
  }
  return 0;
}



===== USBCAMD_AdapterReceivePacket @ 1c0002e80 =====

longlong *
USBCAMD_AdapterReceivePacket(longlong param_1,undefined8 *param_2,longlong *param_3,char param_4)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong *plVar9;
  
                    /* 0x2e80  2  USBCAMD_AdapterReceivePacket */
  plVar2 = *(longlong **)(param_1 + 0x18);
  if (param_3 != (longlong *)0x0) {
    *param_3 = plVar2[0x1d];
  }
  if (param_4 == '\0') goto LAB_1c0003090;
  iVar6 = *(int *)(param_1 + 4);
  if (iVar6 < 0x10a) {
    if (iVar6 == 0x109) {
      uVar7 = HwUnInitialize(param_1);
      iVar6 = (int)uVar7;
LAB_1c0002f03:
      *(int *)(param_1 + 8) = iVar6;
    }
    else if (iVar6 == 0x100) {
      AdapterStreamInfo(param_1);
    }
    else if (iVar6 == 0x101) {
      AdapterOpenStream(param_1);
    }
    else {
      if (iVar6 != 0x102) {
        if (iVar6 == 0x107) {
          iVar6 = HwInitialize(param_1,param_2);
        }
        else {
          if (iVar6 != 0x108) goto LAB_1c0003071;
          uVar7 = USBCAMD_SetDevicePowerState((longlong)plVar2,param_1);
          iVar6 = (int)uVar7;
        }
        goto LAB_1c0002f03;
      }
      uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + 4);
      lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
      *(undefined4 *)(param_1 + 8) = 0;
      if (uVar1 < *(uint *)(*(longlong *)(param_1 + 0x18) + 0xd8)) {
        USBCAMD_CleanupChannel(*(longlong *)(param_1 + 0x18),lVar8,(ulonglong)uVar1);
      }
    }
  }
  else {
    if (iVar6 == 0x10a) {
      lVar8 = *(longlong *)(param_1 + 0x48);
      pcVar4 = *(char **)(lVar8 + 0xb8);
      if ((*pcVar4 != '\x1b') || (pcVar4[1] != '\b')) {
LAB_1c0003071:
        *(undefined4 *)(param_1 + 8) = 0xc0000002;
        goto LAB_1c0003078;
      }
      if ((**(longlong **)(pcVar4 + 8) != 0x11d1b27f2bcb75c0) ||
         ((((*(longlong **)(pcVar4 + 8))[1] != 0x52b0dc9a00041ba ||
           (*(short *)(pcVar4 + 0x10) != 0x48)) || (*(short *)(pcVar4 + 0x12) != 0x200)))) {
        *(undefined4 *)(param_1 + 8) = 0xc00000bb;
        goto LAB_1c0003078;
      }
      puVar5 = *(undefined4 **)(pcVar4 + 0x18);
      *(code **)(puVar5 + 0xc) = USBCAMD_SetVideoFormat;
      *(code **)(puVar5 + 8) = USBCAMD_WaitOnDeviceEvent;
      *(code **)(puVar5 + 10) = USBCAMD_BulkReadWrite;
      *(code **)(puVar5 + 0x10) = USBCAMD_CancelBulkReadWrite;
      *(code **)(puVar5 + 0xe) = USBCAMD_SetIsoPipeState;
      *puVar5 = 0x2000048;
      *(undefined4 *)(lVar8 + 0x30) = 0;
    }
    else if (iVar6 != 0x10b) {
      lVar8 = 2;
      if (iVar6 == 0x10d) {
        USBCAMD_QueryCapabilities((longlong)plVar2);
      }
      else {
        if (iVar6 != 0x10e) goto LAB_1c0003071;
        *(undefined1 *)((longlong)plVar2 + 0x12e) = 1;
        plVar9 = plVar2;
        do {
          plVar9 = plVar9 + 1;
          lVar3 = *plVar9;
          if (lVar3 != 0) {
            if (*(int *)(lVar3 + 0x18) != 0) {
              USBCAMD_StopChannel((longlong)plVar2,lVar3);
            }
            if (*(int *)(lVar3 + 0x1c) != 0) {
              USBCAMD_UnPrepareChannel((longlong)plVar2,lVar3);
            }
          }
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
      }
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
LAB_1c0003078:
  StreamClassDeviceNotification(1,*(undefined8 *)(param_1 + 0x18),param_1);
LAB_1c0003090:
  return plVar2 + 0x3f;
}



===== USBCAMD_BulkOutComplete @ 1c00030c0 =====

undefined4 USBCAMD_BulkOutComplete(undefined8 param_1,longlong param_2,undefined4 param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  *(undefined4 *)(lVar1 + 8) = param_3;
  if ((*(int *)(lVar1 + 4) == 0) && (*(int *)(*(longlong *)(lVar1 + 0x28) + 0x24) == 0)) {
    *(undefined4 *)(lVar1 + 8) = 0xc0000120;
  }
  StreamClassStreamNotification(3,*(undefined8 *)(lVar1 + 0x10),lVar1);
  return param_3;
}



===== USBCAMD_CleanupChannel @ 1c0003110 =====

undefined8 USBCAMD_CleanupChannel(longlong param_1,longlong param_2,ulonglong param_3)

{
  int *piVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined8 local_res8;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar3 = 0xc000000d;
  }
  else {
    if (*(longlong *)(param_1 + 8 + (param_3 & 0xffffffff) * 8) != 0) {
      if (*(int *)(param_2 + 0x18) != 0) {
        USBCAMD_StopChannel(param_1,param_2);
      }
      if (*(int *)(param_2 + 0x1c) != 0) {
        USBCAMD_UnPrepareChannel(param_1,param_2);
      }
      KeWaitForSingleObject(param_1 + 0x98,0,0,0,0);
      bVar2 = *(byte *)(param_2 + 0x2a4);
      piVar1 = (int *)(param_1 + 0xe0 + (ulonglong)bVar2 * 4);
      *piVar1 = *piVar1 + -1;
      KeReleaseSemaphore(param_1 + 0x98,0x10,1);
      while (-1 < *(int *)(param_1 + 0x90 + (ulonglong)bVar2 * 4)) {
        local_res8 = 0xffffffffffffb1e0;
        KeDelayExecutionThread(0,0,&local_res8);
      }
      if (*(longlong *)(param_2 + 0x300) != 0) {
        ExFreePool();
        *(undefined8 *)(param_2 + 0x300) = 0;
      }
      *(undefined8 *)(param_1 + 8 + (param_3 & 0xffffffff) * 8) = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== USBCAMD_CompleteRead @ 1c0003228 =====

void USBCAMD_CompleteRead(longlong param_1,longlong param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  longlong local_30;
  undefined8 local_28;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  puVar9 = (undefined8 *)0x0;
  lVar3 = *(longlong *)(lVar2 + 0x28);
  iVar1 = *(int *)(*(longlong *)(lVar2 + 0x10) + 4);
  *(int *)(lVar2 + 8) = param_3;
  *(undefined4 *)(lVar3 + 0x24) = param_4;
  if (iVar1 == 0) {
    puVar9 = (undefined8 *)(lVar3 + 0x38);
    *(undefined4 *)(param_1 + 0x2b8) = *(undefined4 *)puVar9;
  }
  if (((*(longlong *)(param_1 + 0x2b0) != 0) && (iVar1 == 0)) && (param_3 != -0x3ffffee0)) {
    local_48 = *(undefined8 *)(param_1 + 8);
    local_34 = 0;
    local_38 = 0;
    local_28 = 0;
    local_30 = 0;
    local_40 = *(undefined8 *)(lVar2 + 0x10);
    StreamClassQueryMasterClockSync(*(longlong *)(param_1 + 0x2b0),&local_48);
    *(longlong *)(lVar3 + 8) = local_30;
    if (*(char *)(param_1 + 0x328) == '\0') {
      lVar8 = (*(longlong *)(lVar3 + 0x18) / 2 + local_30) / *(longlong *)(lVar3 + 0x18);
      lVar4 = *(longlong *)(param_1 + 0x2c0);
      if (lVar4 < lVar8) {
        uVar7 = (int)lVar8 - (int)lVar4;
        *(ulonglong *)(param_1 + 0x2c0) = (ulonglong)uVar7 + lVar4;
        *(longlong *)(param_1 + 0x2c8) = *(longlong *)(param_1 + 0x2c8) + (ulonglong)(uVar7 - 1);
      }
      else {
        if (local_30 < *(longlong *)(param_1 + 0x330)) {
          *(longlong *)(lVar3 + 8) = *(longlong *)(param_1 + 0x330);
        }
        *(longlong *)(param_1 + 0x2c0) = *(longlong *)(param_1 + 0x2c0) + 1;
      }
    }
    else {
      *(undefined8 *)(param_1 + 0x2c8) = 0;
      *(undefined1 *)(param_1 + 0x328) = 0;
      *(undefined8 *)(param_1 + 0x2c0) = 1;
    }
    *(undefined8 *)(param_1 + 0x330) = *(undefined8 *)(lVar3 + 8);
  }
  uVar7 = *(uint *)(lVar3 + 0x30);
  if (uVar7 == 0) {
    *(undefined4 *)(lVar3 + 0x30) = 1;
    uVar7 = 1;
  }
  uVar5 = uVar7 | 0x110;
  if (*(longlong *)(param_1 + 0x2b0) == 0) {
    uVar5 = uVar7 & 0xfffffeef;
  }
  *(uint *)(lVar3 + 0x30) = uVar5;
  if (iVar1 == 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x2c0);
    *puVar9 = *(undefined8 *)(param_1 + 0x2b8);
    puVar9[1] = uVar6;
    uVar6 = *(undefined8 *)(param_1 + 0x2d0);
    puVar9[2] = *(undefined8 *)(param_1 + 0x2c8);
    puVar9[3] = uVar6;
    uVar6 = *(undefined8 *)(param_1 + 0x2e0);
    puVar9[4] = *(undefined8 *)(param_1 + 0x2d8);
    puVar9[5] = uVar6;
    uVar6 = *(undefined8 *)(param_1 + 0x2f0);
    puVar9[6] = *(undefined8 *)(param_1 + 0x2e8);
    puVar9[7] = uVar6;
    puVar9[8] = *(undefined8 *)(param_1 + 0x2f8);
  }
  if ((*(char *)(param_1 + 0x329) == '\0') && (*(longlong *)(param_2 + 0x28) != 0)) {
    ExFreePool();
  }
  *(undefined8 *)(param_2 + 0x28) = 0;
  if ((*(int *)(lVar2 + 4) == 0) && (*(int *)(*(longlong *)(lVar2 + 0x28) + 0x24) == 0)) {
    *(undefined4 *)(lVar2 + 8) = 0xc0000120;
  }
  StreamClassStreamNotification(3,*(undefined8 *)(lVar2 + 0x10),lVar2);
  return;
}



===== USBCAMD_DeviceEventProc @ 1c0003450 =====

undefined8 USBCAMD_DeviceEventProc(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x1b0);
  iVar2 = iVar1 + 1;
  if (*param_1 == '\0') {
    iVar2 = iVar1 + -1;
  }
  *(int *)(*(longlong *)(param_1 + 0x18) + 0x1b0) = iVar2;
  return 0;
}



===== USBCAMD_DriverEntry @ 1c0003480 =====

void USBCAMD_DriverEntry(undefined8 param_1,undefined8 param_2,int param_3,int param_4,
                        undefined8 param_5)

{
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 local_58;
  code *local_50;
  code *local_48;
  int local_40;
  int local_3c;
  undefined8 local_38;
  undefined2 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined4 local_24;
  
                    /* 0x3480  5  USBCAMD_DriverEntry */
  local_64 = 0;
  memset(&local_68,0,0x54);
  local_58 = param_5;
  local_60 = 0;
  local_50 = AdapterCancelPacket;
  local_30 = 0;
  local_48 = AdapterTimeoutPacket;
  local_40 = param_3 + 0x1f8;
  local_3c = param_4 + 0x50;
  local_24 = 0;
  local_68 = 0x58;
  local_38 = 0x340;
  local_2c = 3;
  local_28 = 1;
  StreamClassRegisterAdapter(param_1,param_2,&local_68);
  return;
}



===== USBCAMD_InitializeNewInterface @ 1c0003550 =====

void USBCAMD_InitializeNewInterface
               (longlong param_1,undefined8 *param_2,int param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
                    /* 0x3550  7  USBCAMD_InitializeNewInterface */
  if (param_3 == 0x200) {
    uVar1 = param_2[1];
    *(undefined8 *)(param_1 + -0xc0) = *param_2;
    *(undefined8 *)(param_1 + -0xb8) = uVar1;
    uVar1 = param_2[3];
    *(undefined8 *)(param_1 + -0xb0) = param_2[2];
    *(undefined8 *)(param_1 + -0xa8) = uVar1;
    uVar1 = param_2[5];
    *(undefined8 *)(param_1 + -0xa0) = param_2[4];
    *(undefined8 *)(param_1 + -0x98) = uVar1;
    uVar1 = param_2[7];
    *(undefined8 *)(param_1 + -0x90) = param_2[6];
    *(undefined8 *)(param_1 + -0x88) = uVar1;
    uVar1 = param_2[9];
    *(undefined8 *)(param_1 + -0x80) = param_2[8];
    *(undefined8 *)(param_1 + -0x78) = uVar1;
    uVar1 = param_2[0xb];
    *(undefined8 *)(param_1 + -0x70) = param_2[10];
    *(undefined8 *)(param_1 + -0x68) = uVar1;
    *(undefined8 *)(param_1 + -0x60) = param_2[0xc];
    *(undefined4 *)(param_1 + -0x58) = 0x200;
    *(undefined4 *)(param_1 + -0xc4) = param_4;
  }
  return;
}



===== USBCAMD_ProcessSetIsoPipeState @ 1c00035b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBCAMD_ProcessSetIsoPipeState(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  int iVar2;
  uint local_res18 [4];
  
  local_res18[0] = 0;
  if (param_3 == 1) {
    *(undefined1 *)(param_2 + 0x32a) = 1;
    *(uint *)(param_1 + 0x118) =
         (uint)*(ushort *)
                (*(longlong *)(param_1 + 0x110) + ((longlong)*(int *)(param_2 + 0x2ac) + 1) * 0x18);
    USBCAMD_StopChannel(param_1,param_2);
  }
  else {
    LOCK();
    *(undefined4 *)(param_2 + 0x28) = 0;
    UNLOCK();
    *(undefined1 *)(param_2 + 0x32a) = 0;
    iVar2 = USBCAMD_GetPortStatus(param_1,param_2,local_res18);
    if ((-1 < iVar2) && ((local_res18[0] & 1) == 0)) {
      iVar2 = USBCAMD_CallUSBD(param_1,0,0x220017,0);
      if (iVar2 == -0x3fffff45) {
        iVar2 = USBCAMD_CallUSBD(param_1,0,0x220007,0);
      }
      if (iVar2 < 0) {
        return;
      }
    }
    iVar2 = USBCAMD_ResetPipes(param_1,param_2,*(longlong *)(param_1 + 0x110),'\0');
    lVar1 = param_1 + 0x1f8;
    if (*(int *)(param_1 + 0x1a0) == 0x200) {
      if ((-1 < iVar2) &&
         (iVar2 = (**(code **)(param_1 + 0x170))(*(undefined8 *)(param_1 + 0xe8),lVar1,0),
         -1 < iVar2)) {
        (**(code **)(param_1 + 0x168))(*(undefined8 *)(param_1 + 0xe8),lVar1,0);
      }
    }
    else if ((-1 < iVar2) &&
            (iVar2 = (**(code **)(param_1 + 0x170))(*(undefined8 *)(param_1 + 0xe8),lVar1),
            -1 < iVar2)) {
      (**(code **)(param_1 + 0x168))(*(undefined8 *)(param_1 + 0xe8),lVar1);
    }
    *(undefined4 *)(param_2 + 0x2a8) = *(undefined4 *)(param_1 + 0x11c);
    *(undefined4 *)(param_2 + 0x2ac) = *(undefined4 *)(param_1 + 0x120);
    *(undefined1 *)(param_2 + 0x2a5) = 1;
    USBCAMD_StartIsoStream(param_1,param_2);
  }
  return;
}



===== USBCAMD_ReceiveCtrlPacket @ 1c0003740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBCAMD_ReceiveCtrlPacket(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  code *pcVar10;
  undefined1 uVar11;
  int iVar12;
  longlong lVar13;
  undefined8 uVar14;
  undefined1 *puVar15;
  longlong *plVar16;
  char local_res8 [16];
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  
  lVar6 = *(longlong *)(param_1 + 0x18);
  lVar7 = *(longlong *)(param_1 + 0x20);
  local_res8[0] = '\0';
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  iVar3 = *(int *)(*(longlong *)(param_1 + 0x10) + 4);
  lVar13 = (longlong)iVar3;
  lVar1 = lVar6 + 0x40;
  iVar4 = *(int *)(lVar8 + 0x308);
  plVar16 = (longlong *)(lVar6 + 0x18 + lVar13 * 0x10);
  uVar11 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar15 = auStack_58;
  if (*(int *)(lVar6 + 0x38 + lVar13 * 4) == 1) {
    *(longlong *)(lVar7 + 0x18) = param_1;
    puVar2 = (undefined8 *)(lVar7 + 8);
    plVar9 = (longlong *)plVar16[1];
    if ((longlong *)*plVar9 == plVar16) {
      *puVar2 = plVar16;
      *(longlong **)(lVar7 + 0x10) = plVar9;
      *plVar9 = (longlong)puVar2;
      plVar16[1] = (longlong)puVar2;
    }
    else {
LAB_1c00039f0:
      pcVar10 = (code *)swi(0x29);
      uVar11 = (*pcVar10)(3);
      puVar15 = auStack_50;
LAB_1c00039f7:
      *(undefined4 *)(lVar6 + 0x38 + lVar13 * 4) = 0;
    }
    *(undefined8 *)(puVar15 + -8) = 0x1c0003a09;
    KeReleaseSpinLock(lVar1,uVar11);
    return;
  }
  *(undefined4 *)(lVar6 + 0x38 + lVar13 * 4) = 1;
  KeReleaseSpinLock(lVar1);
  do {
    puVar15 = auStack_58;
    if (*(code **)(lVar8 + 0x310) != (code *)0x0) {
      (**(code **)(lVar8 + 0x310))(param_1,lVar6 + 0x1f8,local_res8);
    }
    if (local_res8[0] != '\x01') {
      iVar12 = *(int *)(param_1 + 4);
      if (iVar12 == 2) {
        uVar5 = *(undefined4 *)(lVar8 + 0x308);
        *(undefined4 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x28) = uVar5;
        *(undefined4 *)(param_1 + 0x60) = 4;
        if (*(int *)(lVar8 + 0x308) == 2) {
          *(undefined4 *)(param_1 + 8) = 0x80000022;
        }
      }
      else if (iVar12 == 3) {
        if ((((iVar3 == 1) && (*(longlong *)(lVar6 + 8) == 0)) && (*(int *)(lVar8 + 0x20) != 0)) ||
           (*(int *)(lVar6 + 0x130) != 1)) {
          *(undefined4 *)(param_1 + 8) = 0xc000000d;
        }
        else {
          iVar12 = *(int *)(param_1 + 0x28);
          if (iVar12 == 0) {
            if (*(int *)(lVar8 + 0x18) != 0) {
              iVar12 = USBCAMD_StopChannel(lVar6,lVar8);
              goto LAB_1c0003923;
            }
LAB_1c0003921:
            iVar12 = 0;
          }
          else {
            if (iVar12 == 1) goto LAB_1c0003921;
            if (iVar12 == 2) {
              if ((iVar4 == 1) || (iVar4 == 0)) {
                *(undefined8 *)(lVar8 + 0x2c0) = 0;
                *(undefined8 *)(lVar8 + 0x2c8) = 0;
                *(undefined4 *)(lVar8 + 700) = 0;
                *(undefined1 *)(lVar8 + 0x328) = 1;
              }
              goto LAB_1c0003921;
            }
            if (iVar12 == 3) {
              if ((*(int *)(lVar8 + 0x18) != 0) || (*(char *)(lVar6 + 0x12f) != '\0'))
              goto LAB_1c0003921;
              iVar12 = USBCAMD_StartChannel(lVar6,lVar8);
            }
            else {
              iVar12 = -0x3ffffffe;
            }
          }
LAB_1c0003923:
          *(int *)(param_1 + 8) = iVar12;
          *(undefined4 *)(lVar8 + 0x308) = *(undefined4 *)(param_1 + 0x28);
        }
      }
      else if (iVar12 == 5) {
        if (*(char *)(lVar6 + 0x12e) == '\0') {
          VideoGetProperty(param_1);
        }
        else {
          *(undefined4 *)(param_1 + 8) = 0xc000000e;
        }
      }
      else if (iVar12 == 7) {
        lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
        if (*(char *)(lVar7 + 0x2a4) == '\0') {
          uVar14 = *(undefined8 *)(param_1 + 0x28);
        }
        else {
          uVar14 = 0;
        }
        *(undefined8 *)(lVar7 + 0x2b0) = uVar14;
        *(undefined4 *)(param_1 + 8) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 8) = 0xc0000002;
      }
      if ((*(int *)(param_1 + 4) == 0) && (*(int *)(*(longlong *)(param_1 + 0x28) + 0x24) == 0)) {
        *(undefined4 *)(param_1 + 8) = 0xc0000120;
      }
      StreamClassStreamNotification(3,*(undefined8 *)(param_1 + 0x10),param_1);
    }
    uVar11 = KeAcquireSpinLockRaiseToDpc(lVar1);
    plVar9 = (longlong *)*plVar16;
    if (plVar9 == plVar16) goto LAB_1c00039f7;
    if (((longlong *)plVar9[1] != plVar16) ||
       (lVar7 = *plVar9, (longlong *)*(longlong *)(lVar7 + 8) != plVar9)) goto LAB_1c00039f0;
    *plVar16 = lVar7;
    *(longlong **)(lVar7 + 8) = plVar16;
    *(undefined4 *)(lVar6 + 0x38 + lVar13 * 4) = 1;
    KeReleaseSpinLock(lVar1);
    param_1 = plVar9[2];
  } while( true );
}



===== USBCAMD_ReceiveDataPacket @ 1c0003a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBCAMD_ReceiveDataPacket(longlong param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong lVar8;
  uint uVar9;
  char local_res8 [8];
  
  lVar8 = *(longlong *)(param_1 + 0x18);
  puVar3 = *(undefined4 **)(param_1 + 0x20);
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  local_res8[0] = '\0';
  cVar1 = *(char *)(lVar4 + 0x2a4);
  if ((*(code **)(lVar4 + 0x318) != (code *)0x0) &&
     ((**(code **)(lVar4 + 0x318))(param_1,lVar8 + 0x1f8,local_res8), local_res8[0] == '\x01')) {
    return;
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    if (iVar5 == 1) {
      uVar9 = 0;
      uVar2 = *(uint *)(*(longlong *)(lVar8 + 0x110) + 0x10);
      if (uVar2 != 0) {
        do {
          if ((*(char *)(*(longlong *)(lVar8 + 0x1a8) + 1 + (ulonglong)uVar9 * 0x30) == '\0') &&
             (*(char *)(*(longlong *)(lVar8 + 0x1a8) + (ulonglong)uVar9 * 0x30) == '\x02')) {
            if (cVar1 == '\x01') {
              *(longlong *)(puVar3 + 6) = param_1;
              *puVar3 = 0x45425253;
              lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x28);
              uVar2 = *(uint *)(*(longlong *)(param_1 + 0x28) + 0x24);
              puVar3[0xd] = uVar2;
              if ((lVar4 != 0) && (uVar2 != 0)) {
                (**(code **)(lVar8 + 0x158))(lVar8 + 0x1f8,puVar3 + 0x14,1);
                uVar6 = USBCAMD_IntOrBulkTransfer
                                  (lVar8,0,lVar4,uVar2,uVar9,USBCAMD_BulkOutComplete,puVar3,0,0);
                *(int *)(param_1 + 8) = (int)uVar6;
                return;
              }
              *(undefined4 *)(param_1 + 8) = 0xc000000d;
              if ((*(int *)(param_1 + 4) == 0) &&
                 (*(int *)(*(longlong *)(param_1 + 0x28) + 0x24) == 0)) {
                *(undefined4 *)(param_1 + 8) = 0xc0000120;
              }
              goto LAB_1c0003bbf;
            }
            break;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar2);
      }
      *(undefined4 *)(param_1 + 8) = 0xc0000002;
LAB_1c0003bbf:
      lVar8 = *(longlong *)(param_1 + 0x10);
    }
    else {
      *(undefined4 *)(param_1 + 8) = 0xc0000002;
      if ((iVar5 == 0) && (*(int *)(*(longlong *)(param_1 + 0x28) + 0x24) == 0)) {
        *(undefined4 *)(param_1 + 8) = 0xc0000120;
      }
      lVar8 = *(longlong *)(param_1 + 0x10);
    }
    goto LAB_1c0003cd4;
  }
  if (*(char *)(lVar8 + 0x12e) == '\0') {
    lVar8 = *(longlong *)(param_1 + 0x28);
    *(undefined4 *)(lVar8 + 0x10) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 1;
    *(undefined8 *)(lVar8 + 8) = 0;
    *(undefined8 *)(lVar8 + 0x18) = *(undefined8 *)(*(longlong *)(lVar4 + 0x300) + 0x28);
    *(undefined4 *)(lVar8 + 0x24) = 0;
    uVar7 = USBCAMD_AcquireIdleLock((int *)(lVar4 + 0x28));
    if (-1 < (int)uVar7) {
      if (*(int *)(lVar4 + 0x308) == 0) {
        *(undefined4 *)(param_1 + 8) = 0;
        if ((*(int *)(param_1 + 4) == 0) && (*(int *)(*(longlong *)(param_1 + 0x28) + 0x24) == 0)) {
          *(undefined4 *)(param_1 + 8) = 0xc0000120;
        }
        uVar7 = *(undefined8 *)(param_1 + 0x10);
      }
      else {
        *(longlong *)(puVar3 + 6) = param_1;
        *puVar3 = 0x45425253;
        uVar2 = *(uint *)(*(longlong *)(lVar4 + 0x300) + 0x44);
        if ((uVar2 <= *(uint *)(*(longlong *)(param_1 + 0x28) + 0x20)) || (cVar1 != '\0')) {
          iVar5 = (-(uint)(cVar1 != '\0') & 0xffb) + 9;
          *(int *)(param_1 + 0x38) = iVar5;
          *(int *)(param_1 + 0x34) = iVar5;
          USBCAMD_ReadChannel((ulonglong)uVar2,lVar4,(longlong)puVar3);
          goto LAB_1c0003cab;
        }
        *(undefined4 *)(param_1 + 8) = 0xc000009a;
        if ((*(int *)(param_1 + 4) == 0) && (*(int *)(*(longlong *)(param_1 + 0x28) + 0x24) == 0)) {
          *(undefined4 *)(param_1 + 8) = 0xc0000120;
        }
        uVar7 = *(undefined8 *)(param_1 + 0x10);
      }
      StreamClassStreamNotification(3,uVar7,param_1);
LAB_1c0003cab:
      USBCAMD_ReleaseIdleLock(lVar4 + 0x28);
      return;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    if ((*(int *)(param_1 + 4) == 0) && (*(int *)(*(longlong *)(param_1 + 0x28) + 0x24) == 0))
    goto LAB_1c0003cca;
  }
  else {
LAB_1c0003cca:
    *(undefined4 *)(param_1 + 8) = 0xc0000120;
  }
  lVar8 = *(longlong *)(param_1 + 0x10);
LAB_1c0003cd4:
  StreamClassStreamNotification(3,lVar8,param_1);
  return;
}



===== USBCAMD_SetIsoPipeState @ 1c0003d10 =====

undefined8 USBCAMD_SetIsoPipeState(longlong param_1,uint param_2)

{
  longlong lVar1;
  byte bVar2;
  undefined8 uVar3;
  longlong *plVar4;
  
  uVar3 = 0;
  lVar1 = *(longlong *)(param_1 + -0x1f0);
  if (lVar1 == 0) {
    uVar3 = 0;
  }
  else if (*(byte *)(lVar1 + 0x32a) == param_2) {
    uVar3 = 0xc000000d;
  }
  else {
    bVar2 = KeGetCurrentIrql();
    if (bVar2 < 2) {
      USBCAMD_ProcessSetIsoPipeState(param_1 + -0x1f8,lVar1,param_2);
    }
    else {
      uVar3 = 0x103;
      plVar4 = (longlong *)ExAllocatePool2(0x40,0x58,0x4d414355);
      if (plVar4 == (longlong *)0x0) {
        uVar3 = 0xc000009a;
      }
      else {
        *plVar4 = param_1 + -0x1f8;
        plVar4[1] = 0;
        plVar4[3] = (longlong)USBCAMD_SetIsoPipeWorkItem;
        plVar4[4] = (longlong)plVar4;
        plVar4[5] = lVar1;
        *(uint *)(plVar4 + 10) = param_2;
        ExQueueWorkItem(plVar4 + 1,1);
      }
    }
  }
  return uVar3;
}



===== USBCAMD_SetIsoPipeWorkItem @ 1c0003df0 =====

void USBCAMD_SetIsoPipeWorkItem(longlong *param_1)

{
  USBCAMD_ProcessSetIsoPipeState(*param_1,param_1[5],(int)param_1[10]);
  ExFreePool(param_1);
  return;
}



===== USBCAMD_SetVideoFormat @ 1c0003e30 =====

undefined8 USBCAMD_SetVideoFormat(ulonglong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  void *_Dst;
  uint uVar4;
  ulonglong local_res8;
  
  puVar1 = *(uint **)(param_2 + 0x28);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 8);
  if (((*(longlong *)(puVar1 + 0xc) == 0x11cec35605589f80) &&
      (*(longlong *)(puVar1 + 0xe) == 0x5a595500aa0001bf)) && (0x97 < *puVar1)) {
    local_res8 = param_1 & 0xffffffff00000000;
    uVar3 = puVar1[0x1c];
    uVar4 = uVar3 + 0x30;
    if ((uVar4 < uVar3) || (uVar3 + 0x70 < uVar4)) {
      *(undefined4 *)(param_2 + 8) = 0xc0000095;
      return 0;
    }
    if (((uVar3 + 0x70 <= *puVar1) &&
        (uVar3 = CalculateImageSize((longlong)(puVar1 + 0x10),(uint *)&local_res8), -1 < (int)uVar3)
        ) && ((uint)local_res8 <= puVar1[2])) {
      if (*(longlong *)(lVar2 + 0x300) != 0) {
        ExFreePool();
        *(undefined8 *)(lVar2 + 0x300) = 0;
      }
      _Dst = (void *)ExAllocatePool2(0x42,uVar4,0x4d414355);
      *(void **)(lVar2 + 0x300) = _Dst;
      if (_Dst == (void *)0x0) {
        *(undefined4 *)(param_2 + 8) = 0xc000009a;
        return 0;
      }
      memcpy(_Dst,puVar1 + 0x10,(ulonglong)uVar4);
      return 1;
    }
  }
  *(undefined4 *)(param_2 + 8) = 0xc000000d;
  return 0;
}



===== VideoGetProperty @ 1c0003f5c =====

void VideoGetProperty(longlong param_1)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined4 *puVar5;
  longlong lVar6;
  
  plVar2 = *(longlong **)(param_1 + 0x28);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8);
  plVar4 = (longlong *)*plVar2;
  cVar1 = *(char *)(lVar3 + 0x2a4);
  if ((*plVar4 == 0x11cfac9b1d58c920) && (plVar4[1] == 0xc104db28d6a5)) {
    if ((int)plVar4[2] == 3) {
      if (*(longlong *)(lVar3 + 0x300) == 0) {
        *(undefined4 *)(param_1 + 8) = 0xc000000d;
        return;
      }
      puVar5 = (undefined4 *)plVar2[2];
      *puVar5 = 0x80000003;
      puVar5[2] = (-(uint)(cVar1 != '\0') & 0xfffffffd) + 5;
      puVar5[1] = 1;
      puVar5[3] = *(undefined4 *)(*(longlong *)(lVar3 + 0x300) + 0x44);
      *(undefined8 *)(puVar5 + 4) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0x18;
LAB_1c0003fdc:
      *(undefined4 *)(param_1 + 8) = 0;
      return;
    }
  }
  else if ((*plVar4 == 0x11d030acc6e13344) && ((plVar4[1] == 0x568911c9a0008ca1 && (cVar1 == '\0')))
          ) {
    if ((int)plVar4[2] == 0) {
      lVar6 = plVar4[1];
      plVar2 = (longlong *)plVar2[2];
      *plVar2 = *plVar4;
      plVar2[1] = lVar6;
      plVar2[2] = plVar4[2];
      plVar2[3] = *(longlong *)(lVar3 + 0x2c0);
      plVar2[4] = *(longlong *)(lVar3 + 0x2c8);
      *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(*(longlong *)(lVar3 + 0x300) + 0x44);
      *(undefined4 *)(param_1 + 0x60) = 0x30;
      goto LAB_1c0003fdc;
    }
  }
  else {
    *(undefined4 *)(param_1 + 8) = 0xc0000002;
  }
  return;
}



===== USBCAMD_AbortPipe @ 1c0004064 =====

int USBCAMD_AbortPipe(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)ExAllocatePool2(0x40);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    puVar2[1] = 0;
    *puVar2 = 0x20028;
    *(undefined8 *)(puVar2 + 6) = param_2;
    iVar1 = USBCAMD_CallUSBD(param_1,(longlong)puVar2,0,0);
    ExFreePool(puVar2);
  }
  return iVar1;
}



===== USBCAMD_AcquireIdleLock @ 1c00040f8 =====

undefined8 USBCAMD_AcquireIdleLock(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  LOCK();
  param_1[2] = param_1[2] + 1;
  UNLOCK();
  if (*param_1 != 0) {
    LOCK();
    piVar1 = param_1 + 2;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      LOCK();
      param_1[1] = param_1[1] + 1;
      UNLOCK();
      LOCK();
      piVar1 = param_1 + 1;
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 != 1) {
        KeSetEvent(param_1 + 4,0,0);
      }
    }
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== USBCAMD_CallUSBD @ 1c000414c =====

int USBCAMD_CallUSBD(longlong param_1,longlong param_2,int param_3,longlong param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  KeWaitForSingleObject(param_1 + 0xb8,0,0,0,0);
  KeInitializeEvent(&local_38,1);
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0xe8) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0xe8) + 0x4c)),0);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    if (param_3 == 0) {
      param_3 = 0x220003;
    }
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    if (param_4 == 0) {
      param_4 = param_2;
    }
    *(longlong *)(lVar1 + -0x40) = param_4;
    *(int *)(lVar1 + -0x30) = param_3;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = USBCAMD_CallUsbdCompletion;
    *(undefined8 **)(lVar1 + -8) = &local_38;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    if (*(int *)(param_1 + 0xdc) == 0) {
      iVar2 = -0x3fffff63;
    }
    else {
      *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
      iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0xe8),lVar3);
      if (iVar2 == 0x103) {
        local_res8 = 0xfffffffffd050f80;
        iVar2 = KeWaitForSingleObject(&local_38,0,0,0,&local_res8);
        if (iVar2 == 0x102) {
          iVar2 = -0x3fffff4b;
          IoCancelIrp(lVar3);
          KeWaitForSingleObject(&local_38,0,0,0,0);
        }
        else {
          iVar2 = *(int *)(lVar3 + 0x30);
        }
      }
    }
    IoFreeIrp(lVar3);
  }
  KeReleaseSemaphore(param_1 + 0xb8,0x10,1);
  return iVar2;
}



===== USBCAMD_CallUsbdCompletion @ 1c0004320 =====

undefined8 USBCAMD_CallUsbdCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== USBCAMD_CommandWorkItem @ 1c0004350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBCAMD_CommandWorkItem(longlong *param_1)

{
  int iVar1;
  
  iVar1 = USBCAMD_ControlVendorCommandWorker
                    (*param_1,(char)param_1[5],*(undefined2 *)((longlong)param_1 + 0x2a),
                     *(undefined2 *)((longlong)param_1 + 0x2c),(void *)param_1[6],(uint *)param_1[7]
                     ,(char)param_1[8]);
  if ((code *)param_1[9] != (code *)0x0) {
    (*(code *)param_1[9])(*param_1,param_1[10],iVar1);
  }
  ExFreePool(param_1);
  return;
}



===== USBCAMD_ConfigureDevice @ 1c00043bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBCAMD_ConfigureDevice(longlong param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x88,0x4d414355);
  iVar1 = -0x3fffff66;
  if (puVar2 != (undefined4 *)0x0) {
    uVar5 = 0x40;
    while( true ) {
      lVar3 = ExAllocatePool2(0x40,uVar5);
      if (lVar3 == 0) {
        iVar1 = -0x3fffff66;
      }
      else {
        *puVar2 = 0xb0088;
        puVar2[9] = uVar5;
        *(undefined8 *)(puVar2 + 0xc) = 0;
        *(longlong *)(puVar2 + 10) = lVar3;
        *(undefined4 *)((longlong)puVar2 + 0x82) = 0x200;
        *(undefined8 *)(puVar2 + 0xe) = 0;
        iVar1 = USBCAMD_CallUSBD(param_1,(longlong)puVar2,0,0);
      }
      if (((puVar2[9] == 0) || (lVar3 == 0)) || (*(ushort *)(lVar3 + 2) <= uVar5)) break;
      uVar5 = (uint)*(ushort *)(lVar3 + 2);
      ExFreePool(lVar3);
    }
    ExFreePool(puVar2);
    if (lVar3 != 0) {
      if (-1 < iVar1) {
        uVar4 = USBCAMD_SelectConfiguration(param_1,lVar3);
        iVar1 = (int)uVar4;
        if (-1 < iVar1) {
          iVar1 = (**(code **)(param_1 + 0x140))(*(undefined8 *)(param_1 + 0xe8),param_1 + 0x1f8);
        }
      }
      ExFreePool(lVar3);
    }
  }
  return iVar1;
}



===== USBCAMD_ControlVendorCommand @ 1c0004520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBCAMD_ControlVendorCommand
              (longlong param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4,
              void *param_5,uint *param_6,char param_7,undefined *param_8,longlong param_9)

{
  byte bVar1;
  int iVar2;
  longlong *plVar3;
  
                    /* 0x4520  3  USBCAMD_ControlVendorCommand */
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 2) {
    iVar2 = USBCAMD_ControlVendorCommandWorker
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    if (param_8 != (undefined *)0x0) {
      (*(code *)param_8)(param_1,param_9,iVar2);
    }
  }
  else {
    iVar2 = 0x103;
    plVar3 = (longlong *)ExAllocatePool2(0x42,0x58,0x4d414355);
    if (plVar3 == (longlong *)0x0) {
      iVar2 = -0x3fffff66;
    }
    else {
      *plVar3 = param_1;
      plVar3[1] = 0;
      plVar3[3] = (longlong)USBCAMD_CommandWorkItem;
      plVar3[6] = (longlong)param_5;
      plVar3[7] = (longlong)param_6;
      *(char *)(plVar3 + 8) = param_7;
      plVar3[9] = (longlong)param_8;
      plVar3[10] = param_9;
      plVar3[4] = (longlong)plVar3;
      *(undefined1 *)(plVar3 + 5) = param_2;
      *(undefined2 *)((longlong)plVar3 + 0x2a) = param_3;
      *(undefined2 *)((longlong)plVar3 + 0x2c) = param_4;
      ExQueueWorkItem(plVar3 + 1,1);
    }
  }
  return iVar2;
}



===== USBCAMD_ControlVendorCommandWorker @ 1c0004674 =====

int USBCAMD_ControlVendorCommandWorker
              (longlong param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4,
              void *param_5,uint *param_6,char param_7)

{
  int iVar1;
  void *_Dst;
  undefined4 *puVar2;
  void *_Src;
  uint uVar3;
  
  if (param_6 == (uint *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *param_6;
  }
  _Dst = (void *)ExAllocatePool2(0x40,uVar3 + 0x8f & 0xfffffff8);
  if (_Dst == (void *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    puVar2 = (undefined4 *)(((ulonglong)(uVar3 + 7) & 0xfffffff8) + (longlong)_Dst);
    if ((param_6 == (uint *)0x0) || (*param_6 == 0)) {
      _Src = (void *)0x0;
    }
    else {
      _Src = _Dst;
      if (param_7 == '\0') {
        memcpy(_Dst,param_5,(ulonglong)*param_6);
      }
    }
    *(undefined8 *)(puVar2 + 0xc) = 0;
    *(undefined1 *)((longlong)puVar2 + 0x81) = param_2;
    *puVar2 = 0x170088;
    puVar2[9] = uVar3;
    *(undefined8 *)(puVar2 + 0xe) = 0;
    puVar2[8] = (uint)(param_7 != '\0');
    *(void **)(puVar2 + 10) = _Src;
    *(undefined1 *)(puVar2 + 0x20) = 0;
    *(undefined2 *)((longlong)puVar2 + 0x82) = param_3;
    *(undefined2 *)(puVar2 + 0x21) = param_4;
    iVar1 = USBCAMD_CallUSBD(param_1 + -0x1f8,(longlong)puVar2,0,0);
    if ((-1 < iVar1) && (param_6 != (uint *)0x0)) {
      uVar3 = puVar2[9];
      *param_6 = uVar3;
      if ((_Src != (void *)0x0) && (param_7 != '\0')) {
        memcpy(param_5,_Src,(ulonglong)uVar3);
      }
    }
    ExFreePool(_Dst);
  }
  return iVar1;
}



===== USBCAMD_GetRegistryKeyValue @ 1c00047e0 =====

int USBCAMD_GetRegistryKeyValue
              (undefined8 param_1,undefined8 param_2,int param_3,void *param_4,uint param_5)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint local_res18 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  
                    /* 0x47e0  6  USBCAMD_GetRegistryKeyValue */
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = -0x3fffffe9;
  RtlInitUnicodeString(&local_28);
  uVar3 = param_3 + 0x18;
  if ((uVar3 < 0x18) || (local_res18[0] = uVar3 + param_5, local_res18[0] < uVar3)) {
    return -0x3fffff6b;
  }
  lVar2 = ExAllocatePool2(0x100,local_res18[0],0x4d414355);
  if (lVar2 != 0) {
    iVar1 = ZwQueryValueKey(param_1,&local_28,1,lVar2,local_res18[0],local_res18);
    if (-1 < iVar1) {
      memcpy(param_4,(void *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2),(ulonglong)param_5);
    }
    ExFreePool(lVar2);
  }
  return iVar1;
}



===== USBCAMD_OpenChannel @ 1c00048d0 =====

undefined8 USBCAMD_OpenChannel(longlong param_1,undefined4 *param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  KeWaitForSingleObject(param_1 + 0x98,0,0,0,0);
  *param_2 = 0x4348414e;
  *(longlong *)(param_2 + 2) = param_1;
  *(undefined8 *)(param_2 + 200) = param_3;
  param_2[0xa8] = 0;
  param_2[9] = 0;
  *(undefined1 *)((longlong)param_2 + 0x32a) = 0;
  if (*(int *)(param_1 + 0xe0 + (ulonglong)*(byte *)(param_2 + 0xa9) * 4) == 0) {
    puVar1 = param_2 + 0xa2;
    *(undefined8 *)(param_2 + 0x24) = 0;
    *(undefined4 **)(param_2 + 0xa4) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    *(undefined8 *)(param_2 + 6) = 0;
    *(undefined8 *)(param_2 + 4) = 0;
    KeInitializeSpinLock(param_2 + 0xa6);
    KeInitializeSpinLock(param_2 + 0x26);
    KeInitializeSpinLock(param_2 + 0x90);
    *(undefined8 *)(param_2 + 10) = 0;
    param_2[0xc] = 0;
    KeInitializeEvent(param_2 + 0xe,1);
    puVar2 = (undefined8 *)(param_2 + 0x3c);
    lVar3 = 2;
    do {
      puVar2[0xf] = 0;
      *puVar2 = 0;
      puVar2[-2] = 0;
      puVar2[-1] = 0;
      puVar2[-3] = 0;
      puVar2[1] = 0;
      puVar2 = puVar2 + 0x1a;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  else {
    uVar4 = 0xc000009c;
  }
  KeReleaseSemaphore(param_1 + 0x98,0x10,1);
  return uVar4;
}



===== USBCAMD_Parse_PipeConfig @ 1c0004a38 =====

undefined8 USBCAMD_Parse_PipeConfig(longlong param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  
  *(undefined4 *)(param_1 + 0x120) = 0xffffffff;
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x128) = 0xffffffff;
  uVar4 = 0;
  iVar5 = 0;
  *(undefined2 *)(param_1 + 300) = 0xff;
  *(undefined1 *)(param_1 + 0x124) = 0xff;
  if (0 < param_2) {
    pbVar2 = (byte *)(*(longlong *)(param_1 + 0x1a8) + 4);
    do {
      bVar1 = pbVar2[1];
      if ((bVar1 & 8) == 0) {
        if (bVar1 == 1) {
          if ((*pbVar2 != 3) && ((pbVar2[-3] & 1) != 0)) {
            if ((pbVar2[-4] & 1) == 0) {
              if ((pbVar2[-4] & 2) != 0) {
                *(int *)(param_1 + 0x128) = iVar5;
                *(byte *)(param_1 + 300) = ~*pbVar2 & 1;
              }
            }
            else {
              *(int *)(param_1 + 0x120) = iVar5;
              *(byte *)(param_1 + 0x124) = ~*pbVar2 & 1;
            }
            uVar4 = uVar4 + 1;
          }
        }
        else if (bVar1 == 2) {
          if (((*pbVar2 & 3) != 0) && ((pbVar2[-3] & 1) != 0)) {
            if ((pbVar2[-4] & 1) == 0) {
              if ((pbVar2[-4] & 2) != 0) {
                *(int *)(param_1 + 0x128) = iVar5;
                *(undefined1 *)(param_1 + 300) = 0;
              }
            }
            else {
              *(int *)(param_1 + 0x120) = iVar5;
              *(undefined1 *)(param_1 + 0x124) = 0;
            }
            *(undefined1 *)(param_1 + 0x12d) = 1;
            uVar4 = uVar4 + 2;
          }
        }
        else if (((bVar1 == 4) && ((pbVar2[-4] & 1) != 0)) && ((pbVar2[-3] & 1) != 0)) {
          *(int *)(param_1 + 0x11c) = iVar5;
        }
      }
      iVar5 = iVar5 + 1;
      pbVar2 = pbVar2 + 0x30;
    } while (iVar5 < param_2);
    if (uVar4 != 0) {
      *(uint *)(param_1 + 0xd8) = uVar4;
    }
  }
  if (((*(int *)(param_1 + 0x120) == -1) && (*(int *)(param_1 + 0x128) == -1)) || (2 < uVar4)) {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== USBCAMD_PowerUpWorkItem @ 1c0004ba0 =====

void USBCAMD_PowerUpWorkItem(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *param_1;
  lVar2 = *(longlong *)(lVar1 + 8);
  *(undefined1 *)(lVar1 + 0x12f) = 0;
  if (((lVar2 != 0) && (*(char *)(lVar2 + 0x2a5) == '\x01')) && (*(int *)(lVar2 + 0x308) - 2U < 2))
  {
    USBCAMD_ProcessSetIsoPipeState(lVar1,lVar2,0);
  }
  ExFreePool(param_1);
  return;
}



===== USBCAMD_PrepareChannel @ 1c0004bf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong USBCAMD_PrepareChannel(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 uVar8;
  int *piVar9;
  undefined4 uVar10;
  
  uVar10 = 0;
  KeWaitForSingleObject(param_1 + 0x98,0,0,0,0);
  bVar2 = *(byte *)(param_2 + 0x2a4);
  if ((*(int *)(param_2 + 0x1c) != 0) || (*(int *)(param_2 + 0x18) != 0)) {
    uVar6 = 0xc0000001;
    goto LAB_1c0004e2b;
  }
  piVar1 = (int *)(param_2 + 0x2a0);
  lVar5 = param_1 + 0x1f8;
  if (*(int *)(param_1 + 0x1a0) == 0x200) {
    uVar7 = (**(code **)(param_1 + 400))
                      (*(undefined8 *)(param_1 + 0xe8),lVar5,piVar1,*(undefined8 *)(param_2 + 800),
                       CONCAT44(uVar10,(uint)bVar2));
    uVar6 = (ulonglong)uVar7;
    if (-1 < (int)uVar7) {
      uVar7 = (**(code **)(param_1 + 0x168))(*(undefined8 *)(param_1 + 0xe8),lVar5,(uint)bVar2);
LAB_1c0004cd9:
      uVar6 = (ulonglong)uVar7;
    }
  }
  else {
    uVar7 = (**(code **)(param_1 + 400))
                      (*(undefined8 *)(param_1 + 0xe8),lVar5,piVar1,*(undefined8 *)(param_2 + 800));
    uVar6 = (ulonglong)uVar7;
    if (-1 < (int)uVar7) {
      uVar7 = (**(code **)(param_1 + 0x168))(*(undefined8 *)(param_1 + 0xe8),lVar5);
      goto LAB_1c0004cd9;
    }
  }
  if (*piVar1 == 0) {
    uVar6 = 0xc000009c;
  }
  else if (-1 < (int)uVar6) {
    if ((uint)bVar2 == (int)*(char *)(param_1 + 0x124)) {
      *(undefined4 *)(param_2 + 0x2ac) = *(undefined4 *)(param_1 + 0x120);
      *(undefined1 *)(param_2 + 0x2a5) = 1;
      uVar4 = USBCAMD_StartIsoThread(param_1);
      uVar6 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) goto LAB_1c0004e2b;
    }
    else if ((uint)bVar2 == (int)*(char *)(param_1 + 300)) {
      piVar9 = (int *)(param_2 + 0xc4);
      *(undefined4 *)(param_2 + 0x2ac) = *(undefined4 *)(param_1 + 0x128);
      uVar6 = 0;
      *(undefined1 *)(param_2 + 0x2a5) = 2;
      do {
        uVar8 = 0x4d414355;
        lVar5 = ExAllocatePool2(0x200,*piVar1);
        *(longlong *)(piVar9 + 1) = lVar5;
        if (lVar5 == 0) {
LAB_1c0004dba:
          uVar6 = 0xc000009a;
          goto LAB_1c0004e2b;
        }
        *piVar9 = *piVar1;
        iVar3 = USBCAMD_InitializeBulkTransfer
                          (param_1,param_2,uVar8,(undefined4 *)(uVar6 * 0xd0 + 0xa0 + param_2),
                           *(undefined4 *)(param_2 + 0x2ac));
        if (iVar3 != 0) goto LAB_1c0004dba;
        uVar7 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar7;
        piVar9 = piVar9 + 0x34;
      } while (uVar7 < 2);
      uVar6 = 0;
    }
    else if (*(int *)(param_2 + 0x20) != 0) {
      *(undefined4 *)(param_2 + 0x2ac) = *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x2ac);
      *(undefined1 *)(param_2 + 0x2a5) = *(undefined1 *)(*(longlong *)(param_1 + 8) + 0x2a5);
    }
    *(undefined4 *)(param_2 + 0x2a8) = *(undefined4 *)(param_1 + 0x11c);
    if (*(char *)(param_2 + 0x2a5) == '\x01') {
      uVar7 = 0;
      do {
        uVar4 = USBCAMD_InitializeIsoTransfer(param_1,param_2,(ulonglong)uVar7);
        uVar6 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) goto LAB_1c0004e2b;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 2);
    }
    if (-1 < (int)uVar6) {
      *(undefined4 *)(param_2 + 0x1c) = 1;
    }
  }
LAB_1c0004e2b:
  KeReleaseSemaphore(param_1 + 0x98,0x10,1);
  return uVar6;
}



===== USBCAMD_QueryCapabilities @ 1c0004e70 =====

int USBCAMD_QueryCapabilities(longlong param_1)

{
  undefined4 *_Dst;
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  _Dst = (undefined4 *)(param_1 + 0x1b4);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0xe8) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0xe8) + 0x4c)));
  if (lVar4 == 0) {
    iVar3 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined2 *)(lVar1 + -0x48) = 0x91b;
    KeInitializeEvent(&local_28,0,0);
    lVar2 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar2 + -0x10) = USBCAMD_CallUsbdCompletion;
    *(undefined8 **)(lVar2 + -8) = &local_28;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    memset(_Dst,0,0x40);
    *_Dst = 0x10040;
    *(undefined4 *)(param_1 + 0x1bc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c0) = 0xffffffff;
    *(undefined4 **)(lVar1 + -0x40) = _Dst;
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    iVar3 = IofCallDriver(*(undefined8 *)(param_1 + 0xe8),lVar4);
    if (iVar3 == 0x103) {
      KeWaitForSingleObject(&local_28,5,0,0,0);
      iVar3 = *(int *)(lVar4 + 0x30);
    }
    IoFreeIrp(lVar4);
  }
  return iVar3;
}



===== USBCAMD_ReadChannel @ 1c0004fb0 =====

void USBCAMD_ReadChannel(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  
  uVar1 = *(uint *)(param_2 + 0x2a0);
  lVar2 = *(longlong *)(param_3 + 0x18);
  if (uVar1 == 0) goto LAB_1c0004fd3;
  if (*(char *)(param_2 + 0x2a5) == '\x02') {
    *(undefined8 *)(param_3 + 0x28) = 0;
    *(uint *)(param_3 + 0x34) = uVar1;
    *(uint *)(param_3 + 0x30) = uVar1;
LAB_1c000507f:
    ExInterlockedInsertTailList(param_2 + 0x288,param_3 + 8,param_2 + 0x298);
  }
  else {
    if (*(char *)(param_2 + 0x329) == '\0') {
      *(uint *)(param_3 + 0x30) = uVar1;
      lVar3 = ExAllocatePool2(0x200,uVar1,0x4d414355);
      *(longlong *)(param_3 + 0x28) = lVar3;
      if (lVar3 != 0) goto LAB_1c000507f;
    }
    else if (uVar1 <= *(uint *)(*(longlong *)(param_2 + 0x300) + 0x44)) {
      *(undefined8 *)(param_3 + 0x28) = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x28);
      *(undefined4 *)(param_3 + 0x30) = *(undefined4 *)(*(longlong *)(lVar2 + 0x28) + 0x20);
      goto LAB_1c000507f;
    }
LAB_1c0004fd3:
    *(undefined4 *)(lVar2 + 8) = 0xc000009a;
    if ((*(int *)(lVar2 + 4) == 0) && (*(int *)(*(longlong *)(lVar2 + 0x28) + 0x24) == 0)) {
      *(undefined4 *)(lVar2 + 8) = 0xc0000120;
    }
    StreamClassStreamNotification(3,*(undefined8 *)(lVar2 + 0x10),lVar2);
  }
  return;
}



===== USBCAMD_ReleaseIdleLock @ 1c00050b4 =====

void USBCAMD_ReleaseIdleLock(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    LOCK();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    UNLOCK();
    LOCK();
    piVar1 = (int *)(param_1 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 != 1) {
      KeSetEvent(param_1 + 0x10,0,0);
    }
  }
  return;
}



===== USBCAMD_SelectAlternateInterface @ 1c0005100 =====

int USBCAMD_SelectAlternateInterface(longlong param_1,ushort *param_2)

{
  ushort *_Dst;
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  
                    /* 0x5100  8  USBCAMD_SelectAlternateInterface */
  lVar1 = param_1 + -0x1f8;
  if ((*(int *)(param_1 + -0x58) == 0x200) &&
     (iVar3 = USBCAMD_CancelOutstandingBulkIntIrps(lVar1,'\x01'), iVar3 < 0)) {
    return -0x3fffff64;
  }
  uVar2 = *(uint *)(*(longlong *)(param_1 + -0xe8) + 0x10);
  if (uVar2 < 0x186a1) {
    iVar3 = uVar2 * 0x18 + 0x38;
    puVar4 = (undefined2 *)ExAllocatePool2(0x42,iVar3,0x4d414355);
    if (puVar4 == (undefined2 *)0x0) {
      iVar3 = -0x3fffff66;
    }
    else {
      _Dst = puVar4 + 0x10;
      memcpy(_Dst,param_2,(ulonglong)*param_2);
      puVar4[1] = 1;
      *puVar4 = (short)iVar3;
      *(undefined8 *)(puVar4 + 0xc) = *(undefined8 *)(param_1 + -0xf8);
      iVar3 = USBCAMD_CallUSBD(lVar1,(longlong)puVar4,0,0);
      if ((-1 < iVar3) && (-1 < *(int *)(puVar4 + 2))) {
        memcpy(*(void **)(param_1 + -0xe8),_Dst,(ulonglong)*_Dst);
        memcpy(param_2,_Dst,(ulonglong)*_Dst);
      }
      ExFreePool(puVar4);
    }
    if (*(int *)(param_1 + -0x58) == 0x200) {
      USBCAMD_RestoreOutstandingBulkIntIrps(lVar1);
    }
  }
  else {
    iVar3 = -0x3ffffff3;
  }
  return iVar3;
}



===== USBCAMD_SelectConfiguration @ 1c0005248 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong USBCAMD_SelectConfiguration(longlong param_1,longlong param_2)

{
  ushort *_Src;
  byte bVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined2 *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  void *_Dst;
  longlong lVar8;
  uint uVar9;
  byte *pbVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  undefined2 *puVar13;
  int iVar14;
  longlong lVar15;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar16;
  
  bVar1 = *(byte *)(param_2 + 4);
  uVar12 = 0;
  puVar5 = (undefined2 *)0x0;
  puVar2 = (undefined8 *)ExAllocatePool2(0x100,(ulonglong)(bVar1 + 1) << 4);
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  if (puVar2 == (undefined8 *)0x0) {
    uVar7 = 0xc000009a;
    goto LAB_1c00055fa;
  }
  uVar9 = 0;
  puVar11 = puVar2;
  if (bVar1 != 0) {
    do {
      in_stack_ffffffffffffff88 =
           CONCAT44((int)((ulonglong)in_stack_ffffffffffffff88 >> 0x20),0xffffffff);
      uVar3 = USBD_ParseConfigurationDescriptorEx
                        (param_2,param_2,uVar9,0xffffffff,in_stack_ffffffffffffff88,0xffffffff,
                         0xffffffff);
      uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
      *puVar11 = uVar3;
      uVar9 = uVar9 + 1;
      puVar11 = puVar11 + 2;
    } while (uVar9 < bVar1);
  }
  *puVar11 = 0;
  lVar4 = USBD_CreateConfigurationRequestEx(param_2,puVar2);
  if (lVar4 == 0) {
LAB_1c00053d3:
    uVar7 = 0xc000009a;
  }
  else {
    if (*(int *)(param_1 + 0x1a0) == 0x200) {
      uVar9 = *(uint *)(puVar2[1] + 0x10);
      uVar12 = (ulonglong)uVar9;
      puVar5 = (undefined2 *)ExAllocatePool2(0x100,uVar12 * 2);
      if (puVar5 == (undefined2 *)0x0) goto LAB_1c00053d3;
      uVar9 = (**(code **)(param_1 + 0x178))
                        (*(undefined8 *)(param_1 + 0xe8),param_1 + 0x1f8,puVar2[1],param_2,
                         CONCAT44(uVar16,uVar9),puVar5,*(undefined8 *)(param_1 + 0x108));
    }
    else {
      uVar9 = (**(code **)(param_1 + 0x178))
                        (*(undefined8 *)(param_1 + 0xe8),param_1 + 0x1f8,puVar2[1],param_2,
                         param_1 + 0x120,param_1 + 0x11c);
      *(undefined4 *)(param_1 + 0x128) = 0xffffffff;
      *(undefined1 *)(param_1 + 0x124) = 0;
      *(undefined2 *)(param_1 + 300) = 0xff;
    }
    uVar7 = (ulonglong)uVar9;
  }
  ExFreePool(puVar2);
  if (-1 < (int)uVar7) {
    _Src = (ushort *)(lVar4 + 0x28);
    uVar9 = USBCAMD_CallUSBD(param_1,lVar4,0,0);
    uVar7 = (ulonglong)uVar9;
    if ((-1 < (int)uVar9) && (-1 < *(int *)(lVar4 + 4))) {
      if (*(int *)(param_1 + 0x1a0) == 0x200) {
        iVar14 = (int)uVar12;
        lVar6 = ExAllocatePool2(0x40,uVar12 * 0x30,0x4d414355);
        *(longlong *)(param_1 + 0x1a8) = lVar6;
        if (lVar6 == 0) {
          uVar7 = 0xc000009a;
        }
        else {
          if (iVar14 != 0) {
            pbVar10 = (byte *)(lVar4 + 0x42);
            lVar6 = 0;
            lVar15 = 0;
            puVar13 = puVar5;
            do {
              *(byte *)(*(longlong *)(param_1 + 0x1a8) + lVar15) = pbVar10[2] & 3;
              *(byte *)(*(longlong *)(param_1 + 0x1a8) + 1 + lVar15) = *pbVar10 >> 7;
              *(undefined2 *)(*(longlong *)(param_1 + 0x1a8) + 2 + lVar15) =
                   *(undefined2 *)(pbVar10 + -2);
              *(undefined2 *)(*(longlong *)(param_1 + 0x1a8) + 4 + lVar15) = *puVar13;
              lVar8 = *(longlong *)(param_1 + 0x1a8) + 0x10 + lVar15;
              *(longlong *)(lVar8 + 8) = lVar8;
              *(longlong *)lVar8 = lVar8;
              lVar8 = *(longlong *)(param_1 + 0x1a8) + 0x20 + lVar15;
              *(longlong *)(lVar8 + 8) = lVar8;
              *(longlong *)lVar8 = lVar8;
              KeInitializeSpinLock(*(longlong *)(param_1 + 0x1a8) + 8 + lVar6);
              lVar6 = lVar6 + 0x30;
              pbVar10 = pbVar10 + 0x18;
              lVar15 = lVar15 + 0x30;
              puVar13 = puVar13 + 1;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          uVar7 = USBCAMD_Parse_PipeConfig(param_1,iVar14);
          uVar7 = uVar7 & 0xffffffff;
        }
      }
      *(undefined8 *)(param_1 + 0x100) = *(undefined8 *)(lVar4 + 0x20);
      _Dst = (void *)ExAllocatePool2(0x42,*_Src,0x4d414355);
      *(void **)(param_1 + 0x110) = _Dst;
      if (_Dst == (void *)0x0) {
        uVar7 = 0xc000009a;
      }
      else {
        memcpy(_Dst,_Src,(ulonglong)*_Src);
      }
    }
  }
  if (lVar4 != 0) {
    ExFreePool(lVar4);
  }
LAB_1c00055fa:
  if ((*(int *)(param_1 + 0x1a0) == 0x200) && (puVar5 != (undefined2 *)0x0)) {
    ExFreePool(puVar5);
  }
  return uVar7;
}



===== USBCAMD_SetDevicePowerState @ 1c0005634 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 USBCAMD_SetDevicePowerState(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined4 local_res8;
  undefined4 local_resc;
  
  iVar1 = *(int *)(param_2 + 0x28);
  uVar5 = 0;
  if (*(int *)(param_1 + 0x130) == iVar1) {
    uVar5 = 0;
  }
  else {
    if (iVar1 == 1) {
      if (((*(longlong *)(param_1 + 8) != 0) &&
          (*(char *)(*(longlong *)(param_1 + 8) + 0x2a5) == '\x01')) &&
         (plVar4 = (longlong *)ExAllocatePool2(0x40,0x28,0x4d414355), plVar4 != (longlong *)0x0)) {
        *plVar4 = param_1;
        plVar4[4] = (longlong)plVar4;
        plVar4[3] = (longlong)USBCAMD_PowerUpWorkItem;
        plVar4[1] = 0;
        *(undefined1 *)(param_1 + 0x12f) = 1;
        ExQueueWorkItem(plVar4 + 1,1);
      }
    }
    else if ((iVar1 != 2) && (iVar1 != 3)) {
      if (iVar1 == 4) {
        if (((*(int *)(param_1 + 0x130) == 1) && (lVar2 = *(longlong *)(param_1 + 8), lVar2 != 0))
           && ((*(char *)(lVar2 + 0x2a5) == '\x01' && (*(int *)(lVar2 + 0x308) - 2U < 2)))) {
          USBCAMD_ProcessSetIsoPipeState(param_1,lVar2,1);
          if (*(int *)(param_1 + 0x1a0) == 0x200) {
            (**(code **)(param_1 + 0x170))(*(undefined8 *)(param_1 + 0xe8),param_1 + 0x1f8,0);
          }
          else {
            (**(code **)(param_1 + 0x170))(*(undefined8 *)(param_1 + 0xe8),param_1 + 0x1f8);
          }
          do {
            local_resc = 0xffffffff;
            local_res8 = 0xfb3b4c00;
            KeDelayExecutionThread(0,0,&local_res8);
            iVar3 = KeReadStateSemaphore();
          } while (iVar3 == 0);
        }
      }
      else {
        uVar5 = 0xc00000bb;
      }
    }
    *(int *)(param_1 + 0x130) = iVar1;
  }
  return uVar5;
}



===== USBCAMD_StartBulkStream @ 1c00057c4 =====

void USBCAMD_StartBulkStream(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  *(undefined4 *)(param_2 + 0x33c) = 0;
  *(undefined4 *)(param_2 + 0x18) = 1;
  uVar1 = USBCAMD_IntOrBulkTransfer
                    (param_1,param_2,*(undefined8 *)(param_2 + 200),*(uint *)(param_2 + 0xc4),
                     *(uint *)(param_2 + 0x2ac),0,0,0,0);
  if ((int)uVar1 < 0) {
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  return;
}



===== USBCAMD_StartChannel @ 1c0005824 =====

int USBCAMD_StartChannel(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = 0;
  KeWaitForSingleObject(param_1 + 0x98,0,0,0,0);
  if (*(int *)(param_2 + 0x18) == 0) {
    LOCK();
    *(undefined4 *)(param_2 + 0x28) = 0;
    UNLOCK();
    if (*(int *)(param_2 + 0x20) != 1) {
      if (*(char *)(param_2 + 0x2a5) == '\x01') {
        iVar1 = USBCAMD_ResetPipes(param_1,param_2,*(longlong *)(param_1 + 0x110),'\0');
        if (iVar1 < 0) goto LAB_1c00058d7;
        if (*(char *)(param_2 + 0x2a5) == '\x01') {
          iVar1 = USBCAMD_StartIsoStream(param_1,param_2);
          goto LAB_1c00058d7;
        }
      }
      iVar1 = USBCAMD_StartBulkStream(param_1,param_2);
      goto LAB_1c00058d7;
    }
    if ((*(longlong *)(param_1 + 8) != 0) && (*(int *)(*(longlong *)(param_1 + 8) + 0x18) != 0)) {
      *(undefined4 *)(param_2 + 0x18) = 1;
      goto LAB_1c00058d7;
    }
  }
  iVar1 = -0x3fffffff;
LAB_1c00058d7:
  KeReleaseSemaphore(param_1 + 0x98,0x10,1);
  return iVar1;
}



===== USBCAMD_StartDevice @ 1c0005910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBCAMD_StartDevice(longlong param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined8 in_stack_ffffffffffffffc8;
  uint uVar4;
  
  uVar4 = (uint)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);
  KeInitializeSemaphore(param_1 + 0x98,1,1);
  KeInitializeSemaphore(param_1 + 0xb8,1,1);
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x88,0x4d414355);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    lVar3 = ExAllocatePool2(0x40,0x12);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      *puVar2 = 0xb0088;
      puVar2[9] = 0x12;
      *(undefined8 *)(puVar2 + 0xc) = 0;
      *(longlong *)(puVar2 + 10) = lVar3;
      *(undefined4 *)((longlong)puVar2 + 0x82) = 0x100;
      *(undefined8 *)(puVar2 + 0xe) = 0;
      iVar1 = USBCAMD_CallUSBD(param_1,(longlong)puVar2,0,0);
      if (iVar1 < 0) {
        ExFreePool(lVar3);
      }
      else {
        *(longlong *)(param_1 + 0x108) = lVar3;
      }
    }
    ExFreePool(puVar2);
    if ((-1 < iVar1) && (iVar1 = USBCAMD_ConfigureDevice(param_1), -1 < iVar1)) {
      *(undefined8 *)(param_1 + 0xe0) = 0;
      *(undefined8 *)(param_1 + 0x90) = 0xffffffffffffffff;
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  if (*(longlong *)(param_1 + 0x108) != 0) {
    ExFreePool();
    *(undefined8 *)(param_1 + 0x108) = 0;
  }
  if (*(longlong *)(param_1 + 0x110) != 0) {
    ExFreePool();
    *(undefined8 *)(param_1 + 0x110) = 0;
  }
  if ((*(int *)(param_1 + 0x1a0) == 0x200) && (*(longlong *)(param_1 + 0x1a8) != 0)) {
    ExFreePool();
    *(undefined8 *)(param_1 + 0x1a8) = 0;
  }
  if (*(int *)(param_1 + 0x1a0) == 0x200) {
    (**(code **)(param_1 + 0x178))
              (*(undefined8 *)(param_1 + 0xe8),param_1 + 0x1f8,0,0,(ulonglong)uVar4 << 0x20,0,0);
  }
  else {
    (**(code **)(param_1 + 0x178))(*(undefined8 *)(param_1 + 0xe8),param_1 + 0x1f8,0,0,0,0);
  }
  return iVar1;
}



===== USBCAMD_StartIsoStream @ 1c0005b14 =====

void USBCAMD_StartIsoStream(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  
  iVar6 = 0;
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x20);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0x70020;
    iVar1 = USBCAMD_CallUSBD(param_1,(longlong)puVar2,0,0);
    if ((-1 < iVar1) && (-1 < (int)puVar2[1])) {
      iVar6 = puVar2[6];
    }
    ExFreePool(puVar2);
  }
  iVar6 = iVar6 + 10;
  *(undefined4 *)(param_2 + 0x18) = 1;
  lVar4 = param_2 + 0xa0;
  lVar5 = 2;
  do {
    uVar3 = USBCAMD_SubmitIsoTransfer(param_1,lVar4,iVar6,'\0');
    iVar6 = iVar6 + 0x20;
    lVar4 = lVar4 + 0xd0;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  if ((int)uVar3 < 0) {
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  return;
}



===== USBCAMD_StartIsoThread @ 1c0005be8 =====

ulonglong USBCAMD_StartIsoThread(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res8;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  local_1c = 0;
  local_30 = 0;
  local_28 = 0;
  *(undefined1 *)(param_1 + 0x80) = 0;
  local_38 = 0x30;
  local_20 = 0x200;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = PsCreateSystemThread(&local_res8,0,&local_38,0,0,USBCAMD_ProcessIsoIrps,param_1);
  if (-1 < (int)uVar2) {
    uVar1 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,param_1 + 0x88,0);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      *(undefined1 *)(param_1 + 0x80) = 1;
      KeReleaseSemaphore(param_1 + 0x60,0,1);
    }
    ZwClose(local_res8);
  }
  return uVar2;
}



===== USBCAMD_StopChannel @ 1c0005ce4 =====

int USBCAMD_StopChannel(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 local_res10;
  undefined4 local_res14;
  
  KeWaitForSingleObject(param_1 + 0x98,0,0,0,0);
  if (*(int *)(param_2 + 0x18) == 0) {
    iVar4 = 0;
    goto LAB_1c0005f2d;
  }
  lVar6 = 2;
  if (*(char *)(param_2 + 0x2a5) == '\x02') {
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    iVar4 = USBCAMD_CancelOutstandingIrp(param_1,(ulonglong)*(uint *)(param_2 + 0x2ac),'\0');
    goto LAB_1c0005f2d;
  }
  *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 1;
  if ((*(int *)(param_2 + 0x20) == 0) && (*(char *)(param_2 + 0x2a5) == '\x01')) {
    USBCAMD_AbortPipe(param_1,*(undefined8 *)
                               (*(longlong *)(param_1 + 0x110) + 0x20 +
                               (longlong)*(int *)(param_2 + 0x2ac) * 0x18));
    if (*(int *)(param_2 + 0x2a8) != -1) {
      USBCAMD_AbortPipe(param_1,*(undefined8 *)
                                 (*(longlong *)(param_1 + 0x110) + 0x20 +
                                 (longlong)*(int *)(param_2 + 0x2a8) * 0x18));
    }
  }
  iVar4 = 0;
  LOCK();
  *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) + 1;
  UNLOCK();
  LOCK();
  *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + 1;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_2 + 0x28) = 1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)(param_2 + 0x30);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
LAB_1c0005e07:
    LOCK();
    piVar1 = (int *)(param_2 + 0x2c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 != 1) {
      KeSetEvent(param_2 + 0x38,0,0);
    }
  }
  else {
    local_res8 = 0xfd9da600;
    local_resc = 0xffffffff;
    iVar4 = KeWaitForSingleObject(param_2 + 0x38,0,0,0,&local_res8);
    if (iVar4 == 0) goto LAB_1c0005e07;
    LOCK();
    *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) + -1;
    UNLOCK();
  }
  if (iVar4 == 0x102) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x240);
    plVar5 = (longlong *)(param_2 + 0xf0);
    do {
      if (plVar5[-1] != 0) {
        IoCancelIrp();
      }
      if (*plVar5 != 0) {
        IoCancelIrp();
      }
      plVar5 = plVar5 + 0x1a;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    KeReleaseSpinLock(param_2 + 0x240,uVar3);
    iVar4 = 0;
    LOCK();
    *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) + 1;
    UNLOCK();
    LOCK();
    *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + 1;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_2 + 0x28) = 1;
    UNLOCK();
    LOCK();
    piVar1 = (int *)(param_2 + 0x30);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 != 1) {
      local_res10 = 0xfd9da600;
      local_res14 = 0xffffffff;
      iVar4 = KeWaitForSingleObject(param_2 + 0x38,0,0,0,&local_res10);
      if (iVar4 != 0) {
        LOCK();
        *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) + -1;
        UNLOCK();
        goto LAB_1c0005f19;
      }
    }
    LOCK();
    piVar1 = (int *)(param_2 + 0x2c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 != 1) {
      KeSetEvent(param_2 + 0x38,0,0);
    }
  }
LAB_1c0005f19:
  USBCAMD_CancelQueuedSRBs(param_2);
  *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xfffffffe;
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
LAB_1c0005f2d:
  KeReleaseSemaphore(param_1 + 0x98,0x10,1);
  return iVar4;
}



===== USBCAMD_UnPrepareChannel @ 1c0005f68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBCAMD_UnPrepareChannel(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  KeWaitForSingleObject(param_1 + 0x98,0,0,0,0);
  uVar1 = *(undefined1 *)(param_2 + 0x2a4);
  if ((*(int *)(param_2 + 0x1c) == 0) || (*(int *)(param_2 + 0x18) != 0)) {
    iVar5 = -0x3fffffff;
  }
  else if (*(int *)(param_2 + 0x20) == 1) {
    iVar5 = 0;
  }
  else {
    lVar4 = param_1 + 0x1f8;
    if (*(int *)(param_1 + 0x1a0) == 0x200) {
      (**(code **)(param_1 + 0x170))(*(undefined8 *)(param_1 + 0xe8),lVar4,uVar1);
    }
    else {
      (**(code **)(param_1 + 0x170))(*(undefined8 *)(param_1 + 0xe8),lVar4);
    }
    if (*(int *)(param_1 + 0x1a0) == 0x200) {
      iVar2 = (**(code **)(param_1 + 0x198))(*(undefined8 *)(param_1 + 0xe8),lVar4,uVar1);
    }
    else {
      iVar2 = (**(code **)(param_1 + 0x198))(*(undefined8 *)(param_1 + 0xe8));
    }
    uVar6 = 2;
    iVar5 = 0;
    if (-1 < iVar2) {
      iVar5 = iVar2;
    }
    if (*(char *)(param_2 + 0x2a5) == '\x01') {
      plVar3 = (longlong *)(param_2 + 0xf8);
      do {
        uVar7 = uVar6;
        if (plVar3[-5] != 0) {
          ExFreePool();
          plVar3[-5] = 0;
        }
        if (*plVar3 != 0) {
          ExFreePool();
          *plVar3 = 0;
        }
        plVar3 = plVar3 + 0x1a;
        uVar6 = uVar7 - 1;
      } while (uVar6 != 0);
      if (*(longlong *)(param_1 + 0x88) != 0) {
        *(undefined1 *)(param_1 + 0x80) = 1;
        if (Win98 == '\0') {
          KeReleaseSemaphore();
          KeWaitForSingleObject(*(undefined8 *)(param_1 + 0x88),0,0,0,0);
        }
        else {
          KeReleaseSemaphore(param_1 + 0x60,0,uVar7 & 0xffffffff,0);
        }
        ObfDereferenceObject(*(undefined8 *)(param_1 + 0x88));
        *(undefined8 *)(param_1 + 0x88) = 0;
      }
    }
    else {
      plVar3 = (longlong *)(param_2 + 200);
      lVar4 = param_2 + 0xa0;
      do {
        if (*plVar3 != 0) {
          ExFreePool();
          *plVar3 = 0;
        }
        USBCAMD_FreeBulkTransfer(lVar4);
        lVar4 = lVar4 + 0xd0;
        plVar3 = plVar3 + 0x1a;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  *(undefined4 *)(param_2 + 0x1c) = 0;
  KeReleaseSemaphore(param_1 + 0x98,0x10,1);
  return iVar5;
}



===== USBCAMD_WaitForIdle @ 1c000619c =====

int USBCAMD_WaitForIdle(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_res8;
  undefined4 local_resc;
  
  LOCK();
  param_1[1] = param_1[1] + 1;
  UNLOCK();
  LOCK();
  param_1[2] = param_1[2] + 1;
  UNLOCK();
  if (param_2 == 1) {
    LOCK();
    *param_1 = 1;
    UNLOCK();
  }
  else if (param_2 == 2) {
    LOCK();
    if (*param_1 == 0) {
      *param_1 = 2;
    }
    UNLOCK();
  }
  LOCK();
  piVar1 = param_1 + 2;
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 != 1) {
    local_resc = 0xffffffff;
    local_res8 = 0xfd9da600;
    iVar2 = KeWaitForSingleObject(param_1 + 4,0,0,0,&local_res8);
    if (iVar2 != 0) {
      LOCK();
      param_1[1] = param_1[1] + -1;
      UNLOCK();
      return iVar2;
    }
  }
  if (param_2 == 2) {
    LOCK();
    if (*param_1 == 2) {
      *param_1 = 0;
    }
    UNLOCK();
  }
  LOCK();
  piVar1 = param_1 + 1;
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 != 1) {
    KeSetEvent(param_1 + 4,0,0);
  }
  return 0;
}



===== USBCAMD_BulkReadWrite @ 1c0006290 =====

ulonglong USBCAMD_BulkReadWrite
                    (longlong param_1,ushort param_2,longlong param_3,uint param_4,longlong param_5,
                    longlong param_6)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  ulonglong uVar5;
  longlong *plVar6;
  uint uVar7;
  
  lVar1 = param_1 + -0x1f8;
  if (*(char *)(param_1 + -0xca) == '\0') {
    uVar2 = *(uint *)(*(longlong *)(param_1 + -0xe8) + 0x10);
    uVar7 = (uint)param_2;
    if ((((param_2 < uVar2 || uVar7 == uVar2) &&
         (bVar3 = USBCAMD_OutstandingIrp(lVar1,uVar7), !bVar3)) &&
        (*(int *)(*(longlong *)(param_1 + -0xe8) + 0x1c + (ulonglong)param_2 * 0x18) == 2)) &&
       (param_3 != 0)) {
      bVar4 = KeGetCurrentIrql();
      if (bVar4 < 2) {
        uVar5 = USBCAMD_IntOrBulkTransfer(lVar1,0,param_3,param_4,uVar7,param_5,param_6,0,0);
        uVar5 = uVar5 & 0xffffffff;
      }
      else {
        uVar5 = 0x103;
        plVar6 = (longlong *)ExAllocatePool2(0x40,0x58,0x4d414355);
        if (plVar6 == (longlong *)0x0) {
          uVar5 = 0xc000009a;
        }
        else {
          plVar6[5] = 0;
          *(undefined2 *)((longlong)plVar6 + 0x54) = 0;
          plVar6[1] = 0;
          plVar6[3] = (longlong)USBCAMD_EventWaitWorkItem;
          plVar6[8] = param_5;
          plVar6[9] = param_6;
          plVar6[4] = (longlong)plVar6;
          *plVar6 = lVar1;
          *(uint *)(plVar6 + 7) = uVar7;
          plVar6[6] = param_3;
          *(uint *)((longlong)plVar6 + 0x3c) = param_4;
          ExQueueWorkItem(plVar6 + 1,1);
        }
      }
      return uVar5;
    }
    uVar5 = 0xc000000d;
  }
  else {
    uVar5 = 0xc0000128;
  }
  return uVar5;
}



===== USBCAMD_BulkTransferComplete @ 1c0006410 =====

undefined8 USBCAMD_BulkTransferComplete(undefined8 param_1,longlong param_2,longlong param_3)

{
  ulonglong *puVar1;
  longlong *plVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  longlong lVar9;
  longlong lVar10;
  ulonglong *puVar11;
  undefined4 *puVar12;
  longlong *plVar13;
  code *pcVar14;
  undefined1 uVar15;
  uint uVar16;
  longlong lVar17;
  undefined8 *puVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  longlong lVar21;
  longlong lVar22;
  int local_res20;
  
  uVar5 = *(uint *)(param_3 + 0x80);
  lVar9 = *(longlong *)(param_3 + 0xc0);
  local_res20 = 0;
  lVar10 = *(longlong *)(param_3 + 200);
  lVar22 = (ulonglong)uVar5 * 0x30 + *(longlong *)(lVar9 + 0x1a8);
  lVar21 = lVar22 + 8;
  uVar15 = KeAcquireSpinLockRaiseToDpc(lVar21);
  lVar17 = *(longlong *)(param_3 + 0x50);
  *(undefined8 *)(param_3 + 0x50) = 0;
  if (lVar17 == 0) {
    KeReleaseSpinLock(lVar21,uVar15);
    LOCK();
    iVar3 = *(int *)(param_3 + 0xa0);
    *(int *)(param_3 + 0xa0) = 1;
    UNLOCK();
    if (iVar3 != 0) {
      IoFreeIrp(param_2);
    }
    KeSetEvent(param_3 + 0x88,1,0);
    if (lVar10 == 0) {
      return 0xc0000016;
    }
LAB_1c0006531:
    USBCAMD_ReleaseIdleLock(lVar10 + 0x28);
    return 0xc0000016;
  }
  puVar1 = (ulonglong *)(param_3 + 8);
  uVar20 = *puVar1;
  if ((*(ulonglong **)(uVar20 + 8) != puVar1) ||
     (puVar11 = *(ulonglong **)(param_3 + 0x10), (ulonglong *)*puVar11 != puVar1)) {
LAB_1c00068b8:
    pcVar14 = (code *)swi(0x29);
    (*pcVar14)(3);
    pcVar14 = (code *)swi(3);
    uVar19 = (*pcVar14)();
    return uVar19;
  }
  *puVar11 = uVar20;
  *(ulonglong **)(uVar20 + 8) = puVar11;
  *(ulonglong **)(param_3 + 0x10) = puVar1;
  *puVar1 = (ulonglong)puVar1;
  if ((lVar10 != 0) && ((*(uint *)(lVar10 + 0x10) & 1) != 0)) {
    KeReleaseSpinLock(lVar21,CONCAT71((int7)(uVar20 >> 8),uVar15));
    IoFreeIrp(param_2);
    goto LAB_1c0006531;
  }
  if (-1 < *(int *)(param_2 + 0x30)) {
    puVar12 = *(undefined4 **)(param_3 + 0x40);
    uVar6 = puVar12[9];
    uVar20 = (ulonglong)uVar6;
    if (puVar12[1] == 0) {
      uVar7 = *(uint *)(param_3 + 100);
      uVar4 = *(ushort *)(*(longlong *)(lVar9 + 0x110) + 0x18 + (ulonglong)uVar5 * 0x18);
      if (*(char *)(param_3 + 0x84) != '\0') {
        memcpy(*(void **)(param_3 + 0x78),*(void **)(param_3 + 0x58),(ulonglong)uVar6);
        *(undefined8 *)(param_3 + 0x70) = *(undefined8 *)(param_3 + 0x78);
      }
      *(int *)(param_3 + 0x68) = *(int *)(param_3 + 0x68) + uVar6;
      lVar21 = (ulonglong)uVar6 + *(longlong *)(param_3 + 0x70);
      uVar16 = *(int *)(param_3 + 0x60) - uVar6;
      *(longlong *)(param_3 + 0x70) = lVar21;
      *(uint *)(param_3 + 0x60) = uVar16;
      if ((uVar16 == 0) || (uVar6 < uVar7)) {
        KeReleaseSpinLock(lVar22 + 8,CONCAT31((int3)(uVar6 >> 8),uVar15));
        IoFreeIrp(param_2);
        if (lVar10 == 0) {
          puVar18 = (undefined8 *)ExAllocatePool2(0x40,0x38);
          if (puVar18 == (undefined8 *)0x0) {
            return 0xc0000016;
          }
          *puVar18 = 0;
          puVar18[2] = USBCAMD_ProcessInterruptTransferWorkItem;
          *(uint *)(puVar18 + 6) = uVar5;
          puVar18[3] = puVar18;
          puVar18[4] = lVar9;
          puVar18[5] = param_3;
          ExQueueWorkItem(puVar18,1);
          return 0xc0000016;
        }
        puVar18 = (undefined8 *)ExAllocatePool2(0x40,0x30,0x4d414355);
        if (puVar18 != (undefined8 *)0x0) {
          *puVar18 = 0;
          *(undefined4 *)(puVar18 + 5) = 0;
          puVar18[2] = USBCAMD_ProcessStillReadWorkItem;
          puVar18[3] = puVar18;
          puVar18[4] = lVar10;
          ExQueueWorkItem(puVar18,1);
        }
        goto LAB_1c0006531;
      }
      uVar6 = *(uint *)(param_3 + 100);
      if (uVar16 < *(uint *)(param_3 + 100)) {
        *(uint *)(param_3 + 100) = uVar16;
        uVar6 = uVar16;
      }
      if (*(char *)(*(longlong *)(lVar9 + 0x1a8) + 1 + (ulonglong)uVar5 * 0x30) == '\x01') {
        if (uVar6 < uVar4) {
          lVar17 = *(longlong *)(param_3 + 0x58);
          *(undefined1 *)(param_3 + 0x84) = 1;
          *(longlong *)(param_3 + 0x78) = lVar21;
          if (lVar17 == 0) {
            lVar17 = ExAllocatePool2(0x40,(ulonglong)uVar4,0x4d414355);
            *(longlong *)(param_3 + 0x58) = lVar17;
            if (lVar17 == 0) {
              local_res20 = -0x3fffff66;
            }
          }
          *(longlong *)(param_3 + 0x70) = lVar17;
          uVar6 = (uint)uVar4;
        }
        uVar20 = (ulonglong)uVar6 % (ulonglong)uVar4;
        *(uint *)(param_3 + 100) = uVar6 - (int)uVar20;
        if (local_res20 != 0) {
          KeReleaseSpinLock(lVar22 + 8,CONCAT71((int7)(uVar20 >> 8),uVar15));
          IoFreeIrp(param_2);
          if (lVar10 != 0) goto LAB_1c0006531;
          goto LAB_1c00066f1;
        }
      }
      *(undefined4 *)(param_3 + 0xa0) = 0;
      *(longlong *)(param_3 + 0x50) = param_2;
      plVar2 = (longlong *)(param_3 + 8);
      plVar13 = *(longlong **)(lVar22 + 0x18);
      if (*plVar13 == lVar22 + 0x10) {
        *(longlong **)(param_3 + 0x10) = plVar13;
        *plVar2 = lVar22 + 0x10;
        *plVar13 = (longlong)plVar2;
        *(longlong **)(lVar22 + 0x18) = plVar2;
        KeReleaseSpinLock(lVar22 + 8,CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar15));
        *puVar12 = 0x90080;
        *(undefined8 *)(puVar12 + 6) =
             *(undefined8 *)(*(longlong *)(lVar9 + 0x110) + 0x20 + (ulonglong)uVar5 * 0x18);
        uVar8 = *(undefined4 *)(param_3 + 100);
        *(undefined8 *)(puVar12 + 0xc) = 0;
        puVar12[9] = uVar8;
        uVar19 = *(undefined8 *)(param_3 + 0x70);
        *(undefined8 *)(puVar12 + 0xe) = 0;
        *(undefined8 *)(puVar12 + 10) = uVar19;
        puVar12[8] = 2;
        lVar21 = *(longlong *)(param_3 + 0x50);
        lVar10 = *(longlong *)(lVar21 + 0xb8);
        *(undefined8 *)(lVar10 + -0x40) = *(undefined8 *)(param_3 + 0x40);
        *(undefined4 *)(lVar10 + -0x30) = 0x220003;
        *(undefined1 *)(lVar10 + -0x48) = 0xf;
        lVar21 = *(longlong *)(lVar21 + 0xb8);
        *(code **)(lVar21 + -0x10) = USBCAMD_BulkTransferComplete;
        *(longlong *)(lVar21 + -8) = param_3;
        *(undefined1 *)(lVar21 + -0x45) = 0xe0;
        IofCallDriver(*(undefined8 *)(lVar9 + 0xe8),*(undefined8 *)(param_3 + 0x50));
        return 0xc0000016;
      }
      goto LAB_1c00068b8;
    }
  }
  KeReleaseSpinLock(lVar21,CONCAT71((int7)(uVar20 >> 8),uVar15));
  IoFreeIrp(param_2);
  if (lVar10 != 0) {
    USBCAMD_ReleaseIdleLock(lVar10 + 0x28);
    USBCAMD_ProcessResetRequest(lVar9,lVar10);
    return 0xc0000016;
  }
LAB_1c00066f1:
  USBCAMD_FreeBulkTransfer(param_3);
  ExFreePool(param_3);
  return 0xc0000016;
}



===== USBCAMD_CancelBulkReadWrite @ 1c00068d0 =====

undefined4 USBCAMD_CancelBulkReadWrite(longlong param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (param_2 <= *(uint *)(*(longlong *)(param_1 + -0xe8) + 0x10)) {
    bVar1 = USBCAMD_OutstandingIrp(param_1 + -0x1f8,param_2);
    if (!bVar1) {
      return 0;
    }
    if ((1 < *(int *)(*(longlong *)(param_1 + -0xe8) + 0x1c + (ulonglong)param_2 * 0x18)) &&
       (bVar2 = KeGetCurrentIrql(), bVar2 < 2)) {
      uVar3 = USBCAMD_CancelOutstandingIrp(param_1 + -0x1f8,(ulonglong)param_2,'\0');
      return uVar3;
    }
  }
  return 0xc000000d;
}



===== USBCAMD_CancelOutstandingBulkIntIrps @ 1c000694c =====

undefined4 USBCAMD_CancelOutstandingBulkIntIrps(longlong param_1,char param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x110) + 0x10) != 0) {
    do {
      bVar1 = USBCAMD_OutstandingIrp(param_1,uVar3);
      if (bVar1) {
        uVar2 = USBCAMD_CancelOutstandingIrp(param_1,(ulonglong)uVar3,param_2);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(*(longlong *)(param_1 + 0x110) + 0x10));
  }
  return uVar2;
}



===== USBCAMD_CancelOutstandingIrp @ 1c00069c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 USBCAMD_CancelOutstandingIrp(longlong param_1,ulonglong param_2,char param_3)

{
  longlong *******ppppppplVar1;
  longlong lVar2;
  longlong *******ppppppplVar3;
  int iVar4;
  longlong *******ppppppplVar5;
  longlong ******pppppplVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  longlong lVar10;
  longlong *******local_38;
  longlong *******local_30;
  
  uVar9 = 0;
  local_30 = (longlong *******)&local_38;
  lVar10 = (param_2 & 0xffffffff) * 0x30 + *(longlong *)(param_1 + 0x1a8);
  local_38 = (longlong *******)&local_38;
  lVar2 = lVar10 + 8;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar2);
  ppppppplVar3 = (longlong *******)(lVar10 + 0x10);
  while (ppppppplVar5 = (longlong *******)*ppppppplVar3, ppppppplVar5 != ppppppplVar3) {
    if (((longlong *******)ppppppplVar5[1] != ppppppplVar3) ||
       (pppppplVar6 = *ppppppplVar5, (longlong *******)pppppplVar6[1] != ppppppplVar5))
    goto LAB_1c0006bda;
    *ppppppplVar3 = pppppplVar6;
    pppppplVar6[1] = (longlong *****)ppppppplVar3;
    pppppplVar6 = ppppppplVar5[9];
    ppppppplVar5[9] = (longlong ******)0x0;
    ppppppplVar5[1] = (longlong ******)ppppppplVar5;
    *ppppppplVar5 = (longlong ******)ppppppplVar5;
    if (pppppplVar6 != (longlong ******)0x0) {
      KeReleaseSpinLock(lVar2);
      IoCancelIrp(pppppplVar6);
      LOCK();
      iVar4 = *(int *)(ppppppplVar5 + 0x13);
      *(undefined4 *)(ppppppplVar5 + 0x13) = 1;
      UNLOCK();
      if (iVar4 != 0) {
        IoFreeIrp(pppppplVar6);
      }
      if ((longlong ********)*local_30 != &local_38) goto LAB_1c0006bda;
      ppppppplVar5[1] = (longlong ******)local_30;
      *ppppppplVar5 = (longlong ******)&local_38;
      *local_30 = (longlong ******)ppppppplVar5;
      local_30 = ppppppplVar5;
      uVar8 = KeAcquireSpinLockRaiseToDpc(lVar2);
    }
  }
  KeReleaseSpinLock(lVar2,uVar8);
  uVar9 = 0;
  while( true ) {
    ppppppplVar3 = local_38;
    if ((longlong ********)local_38 == &local_38) {
      return uVar9;
    }
    if (((longlong ********)local_38[1] != &local_38) ||
       (ppppppplVar5 = (longlong *******)*local_38, (longlong *******)ppppppplVar5[1] != local_38))
    break;
    ppppppplVar5[1] = (longlong ******)&local_38;
    ppppppplVar1 = local_38 + 0x18;
    local_38 = ppppppplVar5;
    if (*ppppppplVar1 != (longlong ******)0x0) {
      USBCAMD_ResetPipes(param_1,(longlong)*ppppppplVar1,*(longlong *)(param_1 + 0x110),'\x01');
    }
    uVar9 = KeWaitForSingleObject(ppppppplVar3 + 0x10,0,0,0,0);
    if (param_3 == '\0') {
      if (ppppppplVar3[0x14] != (longlong ******)0x0) {
        (*(code *)ppppppplVar3[0x14])(param_1 + 0x1f8,ppppppplVar3[0x15]);
      }
      if (ppppppplVar3[0x18] == (longlong ******)0x0) {
        USBCAMD_FreeBulkTransfer((longlong)(ppppppplVar3 + -1));
        ExFreePool(ppppppplVar3 + -1);
      }
    }
    else {
      pppppplVar6 = *(longlong *******)(lVar10 + 0x28);
      if ((longlong ******)*pppppplVar6 != (longlong ******)(lVar10 + 0x20)) break;
      *ppppppplVar3 = (longlong ******)(lVar10 + 0x20);
      ppppppplVar3[1] = pppppplVar6;
      *pppppplVar6 = (longlong *****)ppppppplVar3;
      *(longlong ********)(lVar10 + 0x28) = ppppppplVar3;
    }
  }
LAB_1c0006bda:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  return uVar9;
}



===== USBCAMD_EventWaitWorkItem @ 1c0006c10 =====

void USBCAMD_EventWaitWorkItem(longlong *param_1)

{
  USBCAMD_IntOrBulkTransfer
            (*param_1,param_1[5],param_1[6],*(uint *)((longlong)param_1 + 0x3c),
             *(uint *)(param_1 + 7),param_1[8],param_1[9],*(undefined1 *)((longlong)param_1 + 0x54),
             *(undefined1 *)((longlong)param_1 + 0x55));
  ExFreePool(param_1);
  return;
}



===== USBCAMD_FreeBulkTransfer @ 1c0006c70 =====

undefined8 USBCAMD_FreeBulkTransfer(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x58) != 0) {
    ExFreePool();
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  if (*(longlong *)(param_1 + 0x40) != 0) {
    ExFreePool();
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  return 0;
}



===== USBCAMD_InitializeBulkTransfer @ 1c0006cbc =====

undefined4
USBCAMD_InitializeBulkTransfer
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
          undefined4 param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  
  *(undefined8 *)(param_4 + 0x30) = param_1;
  *(undefined8 *)(param_4 + 0x32) = param_2;
  *param_4 = 0x5452414e;
  param_4[0x20] = param_5;
  KeInitializeEvent(param_4 + 0x22,1);
  lVar1 = ExAllocatePool2(0x40,0x80,0x4d414355);
  *(longlong *)(param_4 + 0x10) = lVar1;
  uVar2 = 0;
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



===== USBCAMD_IntOrBulkTransfer @ 1c0006d3c =====

ulonglong USBCAMD_IntOrBulkTransfer
                    (longlong param_1,longlong param_2,undefined8 param_3,uint param_4,uint param_5,
                    undefined8 param_6,undefined8 param_7,undefined1 param_8,undefined1 param_9)

{
  ushort uVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 *_Dst;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  
  uVar6 = (ulonglong)param_5;
  lVar14 = uVar6 * 0x30 + *(longlong *)(param_1 + 0x1a8);
  uVar5 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x28 + uVar6 * 0x18);
  uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x110) + 0x18 + uVar6 * 0x18);
  if (param_2 == 0) {
    _Dst = (undefined4 *)ExAllocatePool2(0x40,0xd0,0x4d414355);
    if (_Dst != (undefined4 *)0x0) {
      uVar13 = 0xd0;
      memset(_Dst,0,0xd0);
      iVar4 = USBCAMD_InitializeBulkTransfer(param_1,0,uVar13,_Dst,param_5);
      if (iVar4 == 0) goto LAB_1c0006e26;
LAB_1c0006dec:
      ExFreePool(_Dst);
    }
LAB_1c0006dfb:
    uVar7 = 0xc000009a;
  }
  else {
    _Dst = (undefined4 *)((ulonglong)*(uint *)(param_2 + 0x33c) * 0xd0 + 0xa0 + param_2);
LAB_1c0006e26:
    uVar7 = 0;
    _Dst[0x20] = param_5;
    *(undefined8 *)(_Dst + 0x2a) = param_6;
    *(undefined8 *)(_Dst + 0x2c) = param_7;
    *(undefined1 *)(_Dst + 0x2e) = param_8;
    *(undefined1 *)((longlong)_Dst + 0xb9) = param_9;
    *(undefined1 *)(_Dst + 0x21) = 0;
    _Dst[0x18] = param_4;
    _Dst[0x19] = param_4;
    *(undefined8 *)(_Dst + 0x1c) = param_3;
    *(undefined8 *)(_Dst + 0x1e) = param_3;
    _Dst[0x1a] = 0;
    if (uVar5 < param_4) {
      _Dst[0x19] = uVar5;
      param_4 = uVar5;
    }
    if (*(char *)(lVar14 + 1) == '\x01') {
      if (param_4 < uVar1) {
        *(undefined1 *)(_Dst + 0x21) = 1;
        lVar8 = ExAllocatePool2(0x40,uVar1,0x4d414355);
        *(longlong *)(_Dst + 0x16) = lVar8;
        *(longlong *)(_Dst + 0x1c) = lVar8;
        if (lVar8 == 0) {
          if (param_2 == 0) {
            USBCAMD_FreeBulkTransfer((longlong)_Dst);
            goto LAB_1c0006dec;
          }
          goto LAB_1c0006dfb;
        }
        _Dst[0x19] = (uint)uVar1;
      }
      else {
        _Dst[0x19] = param_4 - param_4 % (uint)uVar1;
      }
    }
    lVar8 = lVar14 + 8;
    *(undefined2 *)(*(longlong *)(_Dst + 0x10) + 2) = 9;
    **(undefined2 **)(_Dst + 0x10) = 0x80;
    *(undefined8 *)(*(longlong *)(_Dst + 0x10) + 0x18) =
         *(undefined8 *)(*(longlong *)(param_1 + 0x110) + 0x20 + uVar6 * 0x18);
    *(undefined4 *)(*(longlong *)(_Dst + 0x10) + 0x24) = _Dst[0x19];
    *(undefined8 *)(*(longlong *)(_Dst + 0x10) + 0x30) = 0;
    *(undefined8 *)(*(longlong *)(_Dst + 0x10) + 0x28) = *(undefined8 *)(_Dst + 0x1c);
    *(undefined4 *)(*(longlong *)(_Dst + 0x10) + 0x20) = 2;
    *(undefined8 *)(*(longlong *)(_Dst + 0x10) + 0x38) = 0;
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar8);
    if (param_2 != 0) {
      if (*(int *)(param_2 + 0x18) == 0) {
        KeReleaseSpinLock(lVar8,uVar3);
        return 0;
      }
      uVar7 = USBCAMD_AcquireIdleLock((int *)(param_2 + 0x28));
      uVar7 = uVar7 & 0xffffffff;
    }
    puVar12 = auStackY_68;
    if ((int)uVar7 == 0) {
      lVar9 = USBCAMD_BuildIoRequest
                        (param_1,_Dst,*(undefined8 *)(_Dst + 0x10),USBCAMD_BulkTransferComplete);
      puVar12 = auStackY_68;
      *(longlong *)(_Dst + 0x14) = lVar9;
      _Dst[0x28] = 0;
      if (lVar9 == 0) {
        if (param_2 == 0) {
          USBCAMD_FreeBulkTransfer((longlong)_Dst);
          ExFreePool(_Dst);
        }
        else {
          USBCAMD_ReleaseIdleLock(param_2 + 0x28);
        }
        puVar12 = auStackY_68;
        uVar7 = 0xc000009a;
      }
      else {
        lVar9 = lVar14 + 0x10;
        plVar11 = *(longlong **)(lVar14 + 0x18);
        plVar10 = (longlong *)(_Dst + 2);
        if (*plVar11 != lVar9) {
          lVar9 = 3;
          pcVar2 = (code *)swi(0x29);
          plVar10 = (longlong *)(*pcVar2)();
          puVar12 = auStackY_60;
        }
        *plVar10 = lVar9;
        plVar10[1] = (longlong)plVar11;
        *plVar11 = (longlong)plVar10;
        *(longlong **)(lVar9 + 8) = plVar10;
      }
    }
    *(undefined8 *)(puVar12 + -8) = 0x1c000702c;
    KeReleaseSpinLock(lVar8,uVar3);
    if (*(longlong *)(_Dst + 0x14) != 0) {
      uVar13 = *(undefined8 *)(param_1 + 0xe8);
      *(undefined8 *)(puVar12 + -8) = 0x1c000704a;
      uVar5 = IofCallDriver(uVar13);
      uVar7 = (ulonglong)uVar5;
      if (uVar5 == 0x103) {
        uVar7 = 0;
      }
    }
  }
  return uVar7;
}



===== USBCAMD_OutstandingIrp @ 1c0007078 =====

bool USBCAMD_OutstandingIrp(longlong param_1,uint param_2)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong *plVar4;
  
  lVar3 = (ulonglong)param_2 * 0x30;
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x1a8) + 8 + lVar3);
  plVar4 = (longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x10 + lVar3);
  plVar1 = (longlong *)*plVar4;
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x1a8) + 8 + lVar3,uVar2);
  return plVar1 != plVar4;
}



===== USBCAMD_ProcessInterruptTransferWorkItem @ 1c0007100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBCAMD_ProcessInterruptTransferWorkItem(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  lVar2 = *(longlong *)(param_1 + 0x20);
  if (*(code **)(lVar1 + 0xa8) != (code *)0x0) {
    (**(code **)(lVar1 + 0xa8))(lVar2 + 0x1f8,*(undefined8 *)(lVar1 + 0xb0),0);
  }
  if (((*(char *)(lVar1 + 0xb9) == '\x01') && ((*(uint *)(lVar2 + 0x134) & 8) != 0)) &&
     (*(int *)(lVar2 + 0x1b0) != 0)) {
    StreamClassDeviceNotification(2,lVar2,&USBCAMD_KSEVENTSETID_VIDCAPTOSTI);
  }
  if (*(char *)(lVar1 + 0xb8) != '\0') {
    USBCAMD_RestoreOutstandingIrp(lVar2,*(uint *)(param_1 + 0x30),lVar1);
  }
  ExFreePool(param_1);
  return;
}



===== USBCAMD_ProcessStillReadWorkItem @ 1c00071c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBCAMD_ProcessStillReadWorkItem(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  undefined4 local_res8 [2];
  undefined4 local_res10;
  undefined4 local_res14;
  ulonglong in_stack_ffffffffffffff98;
  undefined4 uVar8;
  
  local_res14 = 0xffffffff;
  lVar1 = *(longlong *)(param_1 + 0x20);
  iVar4 = *(int *)(param_1 + 0x28);
  local_res10 = 0xffff3cb0;
  lVar7 = (ulonglong)*(uint *)(lVar1 + 0x33c) * 0xd0;
  uVar6 = 0;
  local_res8[0] = *(undefined4 *)(lVar1 + 0x108 + lVar7);
  lVar2 = *(longlong *)(lVar1 + 8);
  do {
    lVar5 = ExInterlockedRemoveHeadList(lVar1 + 0x288,lVar1 + 0x298);
    uVar8 = (undefined4)(in_stack_ffffffffffffff98 >> 0x20);
    if (lVar5 != 0) {
      (**(code **)(lVar2 + 0x158))
                (lVar2 + 0x1f8,lVar5 + 0x48,*(undefined1 *)(lVar1 + 0x2a4),lVar5 + 0x2c);
      lVar3 = *(longlong *)(lVar5 + 0x10);
      *(undefined4 *)(*(longlong *)(lVar3 + 0x28) + 0x30) = 0;
      if ((iVar4 == 0) && (*(char *)(lVar1 + 0x329) == '\0')) {
        iVar4 = (**(code **)(lVar2 + 0x160))
                          (*(undefined8 *)(lVar2 + 0xe8),lVar2 + 0x1f8,lVar5 + 0x48,
                           *(undefined8 *)(*(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x28) + 0x28)
                           ,*(undefined4 *)(*(longlong *)(lVar1 + 0x300) + 0x44),
                           *(undefined8 *)(lVar1 + 200 + lVar7),
                           CONCAT44(uVar8,*(undefined4 *)(lVar5 + 0x28)),0,local_res8,
                           *(undefined4 *)(lVar1 + 0x108 + lVar7),
                           *(undefined4 *)(*(longlong *)(lVar3 + 0x10) + 4));
      }
      USBCAMD_CompleteRead(lVar1,lVar5 + -8,iVar4,local_res8[0]);
      goto LAB_1c0007370;
    }
    KeDelayExecutionThread(0,0,&local_res10);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 2);
  if (*(char *)(lVar1 + 0x329) == '\0') {
    (**(code **)(lVar2 + 0x160))
              (*(undefined8 *)(lVar2 + 0xe8),lVar2 + 0x1f8,0,0,0,0,
               in_stack_ffffffffffffff98 & 0xffffffff00000000,0,0,0,0);
  }
LAB_1c0007370:
  *(uint *)(lVar1 + 0x33c) = *(uint *)(lVar1 + 0x33c) ^ 1;
  lVar7 = (ulonglong)*(uint *)(lVar1 + 0x33c) * 0xd0;
  USBCAMD_IntOrBulkTransfer
            (lVar2,lVar1,*(undefined8 *)(lVar7 + 200 + lVar1),*(uint *)(lVar7 + 0xc4 + lVar1),
             *(uint *)(lVar1 + 0x2ac),0,0,0,0);
  ExFreePool(param_1);
  return;
}



===== USBCAMD_RestoreOutstandingBulkIntIrps @ 1c00073ec =====

ulonglong USBCAMD_RestoreOutstandingBulkIntIrps(longlong param_1)

{
  longlong *plVar1;
  code *pcVar2;
  undefined1 uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  
  uVar6 = 0;
  uVar5 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x110) + 0x10) != 0) {
    do {
      while( true ) {
        lVar9 = uVar5 * 0x30;
        plVar7 = (longlong *)(*(longlong *)(param_1 + 0x1a8) + 0x20 + lVar9);
        uVar3 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x1a8) + 8 + lVar9);
        plVar1 = (longlong *)*plVar7;
        if (plVar1 == plVar7) {
          lVar8 = 0;
        }
        else {
          if (((longlong *)plVar1[1] != plVar7) ||
             (lVar8 = *plVar1, (longlong *)*(longlong *)(lVar8 + 8) != plVar1)) {
            pcVar2 = (code *)swi(0x29);
            (*pcVar2)(3,uVar3);
            pcVar2 = (code *)swi(3);
            uVar5 = (*pcVar2)();
            return uVar5;
          }
          *plVar7 = lVar8;
          *(longlong **)(lVar8 + 8) = plVar7;
          lVar8 = (longlong)(plVar1 + -1);
        }
        KeReleaseSpinLock(*(longlong *)(param_1 + 0x1a8) + 8 + lVar9);
        if (lVar8 == 0) break;
        uVar4 = USBCAMD_RestoreOutstandingIrp(param_1,(uint)uVar5,lVar8);
        uVar6 = (ulonglong)uVar4;
      }
      uVar4 = (uint)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(*(longlong *)(param_1 + 0x110) + 0x10));
  }
  return uVar6;
}



===== USBCAMD_RestoreOutstandingIrp @ 1c00074e0 =====

void USBCAMD_RestoreOutstandingIrp(longlong param_1,uint param_2,longlong param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  lVar4 = *(longlong *)(param_3 + 200);
  uVar1 = *(undefined1 *)(param_3 + 0xb9);
  uVar2 = *(undefined1 *)(param_3 + 0xb8);
  uVar5 = *(undefined8 *)(param_3 + 0x78);
  uVar3 = *(uint *)(param_3 + 100);
  uVar6 = *(undefined8 *)(param_3 + 0xa8);
  uVar7 = *(undefined8 *)(param_3 + 0xb0);
  if (lVar4 == 0) {
    USBCAMD_FreeBulkTransfer(param_3);
    ExFreePool(param_3);
  }
  USBCAMD_IntOrBulkTransfer(param_1,lVar4,uVar5,uVar3,param_2,uVar6,uVar7,uVar2,uVar1);
  return;
}



===== USBCAMD_WaitOnDeviceEvent @ 1c00075b0 =====

ulonglong USBCAMD_WaitOnDeviceEvent
                    (longlong param_1,uint param_2,longlong param_3,uint param_4,longlong param_5,
                    longlong param_6,undefined1 param_7)

{
  longlong lVar1;
  bool bVar2;
  byte bVar3;
  ulonglong uVar4;
  longlong *plVar5;
  
  lVar1 = param_1 + -0x1f8;
  if (*(char *)(param_1 + -0xca) == '\0') {
    if ((param_2 <= *(uint *)(*(longlong *)(param_1 + -0xe8) + 0x10)) &&
       (bVar2 = USBCAMD_OutstandingIrp(lVar1,param_2), !bVar2)) {
      if ((*(int *)(*(longlong *)(param_1 + -0xe8) + 4 + ((ulonglong)param_2 + 1) * 0x18) == 3) &&
         ((param_3 != 0 &&
          (*(ushort *)(*(longlong *)(param_1 + -0xe8) + ((ulonglong)param_2 + 1) * 0x18) <= param_4)
          ))) {
        bVar3 = KeGetCurrentIrql();
        if (bVar3 < 2) {
          uVar4 = USBCAMD_IntOrBulkTransfer
                            (lVar1,0,param_3,param_4,param_2,param_5,param_6,param_7,1);
          uVar4 = uVar4 & 0xffffffff;
        }
        else {
          uVar4 = 0x103;
          plVar5 = (longlong *)ExAllocatePool2(0x40,0x58,0x4d414355);
          if (plVar5 == (longlong *)0x0) {
            uVar4 = 0xc000009a;
          }
          else {
            plVar5[5] = 0;
            plVar5[1] = 0;
            plVar5[3] = (longlong)USBCAMD_EventWaitWorkItem;
            plVar5[8] = param_5;
            plVar5[9] = param_6;
            *(undefined1 *)((longlong)plVar5 + 0x54) = param_7;
            plVar5[4] = (longlong)plVar5;
            *plVar5 = lVar1;
            *(uint *)(plVar5 + 7) = param_2;
            plVar5[6] = param_3;
            *(uint *)((longlong)plVar5 + 0x3c) = param_4;
            *(undefined1 *)((longlong)plVar5 + 0x55) = 1;
            ExQueueWorkItem(plVar5 + 1,1);
          }
        }
        return uVar4;
      }
    }
    uVar4 = 0xc000000d;
  }
  else {
    uVar4 = 0xc0000128;
  }
  return uVar4;
}



===== __cpu_features_init @ 1c0007760 =====

/* WARNING: Removing unreachable block (ram,0x0001c00077ca) */
/* WARNING: Removing unreachable block (ram,0x0001c0007779) */
/* WARNING: Removing unreachable block (ram,0x0001c000776a) */

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



===== __security_check_cookie @ 1c0007830 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0007870 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00078a0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00078a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00078d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0007940 =====

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



===== memset @ 1c0007c40 =====

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



===== __memset_repmovs @ 1c0007d80 =====

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



===== __memset_query @ 1c0007e00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0007e80 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0007fc0 =====

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



===== __memset_spec_plain @ 1c0008040 =====

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



===== entry @ 1c0010010 =====

void entry(void)

{
  __security_init_cookie();
  DllUnload();
  return;
}



===== __security_init_cookie @ 1c0010044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  byte bVar8;
  byte *pbVar6;
  char *pcVar7;
  char *pcVar9;
  char in_DL;
  char in_DH;
  undefined6 in_register_00000012;
  char unaff_BH;
  undefined1 *unaff_RSI;
  char in_R8B;
  undefined7 in_register_00000081;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar9 = (char *)0x6;
    pcVar2 = (code *)swi(0x29);
    pbVar6 = (byte *)(*pcVar2)();
    bVar4 = (byte)pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    bVar1 = *pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + in_DL + CARRY1(bVar1,bVar4);
    *pbVar6 = *pbVar6 + bVar4;
    bVar1 = *pbVar6;
    bVar8 = (byte)((ulonglong)pbVar6 >> 8);
    *pbVar6 = *pbVar6 + bVar8;
    *pbVar6 = *pbVar6 + bVar4 + CARRY1(bVar1,bVar8);
    bVar1 = *pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    uVar5 = (int)pbVar6 + *(int *)pbVar6 + (uint)CARRY1(bVar1,bVar4);
    pcVar7 = (char *)(ulonglong)uVar5;
    cVar3 = (char)uVar5;
    *pcVar7 = *pcVar7 + cVar3;
    *(undefined1 *)((longlong)pcVar7 * 2) = *(undefined1 *)((longlong)pcVar7 * 2);
    pcVar7[0x25] = pcVar7[0x25] + in_DL;
    *pcVar7 = *pcVar7 + cVar3;
    *pcVar7 = *pcVar7 + cVar3;
    *pcVar7 = *pcVar7 + cVar3;
    pcVar7[0x2b] = pcVar7[0x2b] + cVar3;
    *pcVar7 = *pcVar7 + cVar3;
    uVar5 = CONCAT31((int3)(uVar5 >> 8),cVar3 + in_DL);
    uVar5 = uVar5 - *(int *)(ulonglong)uVar5;
    pcVar7 = (char *)(ulonglong)uVar5;
    cVar3 = (char)uVar5;
    *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
         *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) + cVar3;
    *unaff_RSI = *unaff_RSI;
    *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
         *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) + cVar3;
    *pcVar7 = *pcVar7;
    *pcVar7 = *pcVar7 + cVar3;
    pcVar7 = (char *)(ulonglong)uVar5;
    *pcVar7 = *pcVar7 + cVar3;
    *(undefined1 *)((longlong)pcVar7 * 2) = *(undefined1 *)((longlong)pcVar7 * 2);
    in_DL = in_DL + pcVar7[0x35];
    *pcVar7 = *pcVar7 + cVar3;
    bVar4 = cVar3 + pcVar7[0x37];
    pbVar6 = (byte *)(ulonglong)CONCAT31((int3)(uVar5 >> 8),bVar4);
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + in_DH;
    bVar1 = *pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    cRam00000001b0011051 = cRam00000001b0011051 + unaff_BH + CARRY1(bVar1,bVar4);
    *pbVar6 = *pbVar6 + bVar4;
    cVar3 = (char)(uVar5 >> 8);
    *pbVar6 = *pbVar6 + cVar3;
    *(byte *)CONCAT71(in_register_00000081,in_R8B) =
         *(char *)CONCAT71(in_register_00000081,in_R8B) + bVar4;
    pbVar6[0x43] = pbVar6[0x43] + in_DL;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + cVar3;
    *(char *)CONCAT71(in_register_00000081,in_R8B) =
         *(char *)CONCAT71(in_register_00000081,in_R8B) + in_R8B;
    *(char *)CONCAT71(in_register_00000081,in_R8B) =
         *(char *)CONCAT71(in_register_00000081,in_R8B) + in_R8B;
    *pcVar9 = *pcVar9 + in_DL;
    *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
         *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) + bVar4;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


