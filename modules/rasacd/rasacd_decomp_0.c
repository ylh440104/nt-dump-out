
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== AcdBind @ 140001020 =====

undefined8 AcdBind(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*(uint *)(param_2 + 0x10) < 8) {
    uVar5 = 0xc0000023;
  }
  else {
    puVar1 = (undefined8 *)**(undefined8 **)(param_1 + 0x18);
    puVar1[4] = AcdNewConnection;
    puVar1[5] = AcdStartConnection;
    puVar1[6] = AcdCancelConnection;
    uVar3 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    uVar4 = KeAcquireSpinLockRaiseToDpc(puVar1 + 2);
    *(undefined1 *)((longlong)puVar1 + 0x1c) = fAcdEnabledG;
    KeReleaseSpinLock(puVar1 + 2,uVar4);
    puVar8 = auStack_28;
    puVar6 = &AcdDriverListG;
    puVar7 = DAT_140006108;
    if ((undefined8 *)*DAT_140006108 != &AcdDriverListG) {
      puVar7 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      puVar6 = (undefined8 *)(*pcVar2)();
      puVar8 = auStack_20;
    }
    puVar1[1] = puVar7;
    *puVar1 = puVar6;
    *puVar7 = puVar1;
    *(undefined8 *)(puVar8 + -8) = 0x1400010ec;
    DAT_140006108 = puVar1;
    KeReleaseSpinLock(&AcdSpinLockG,uVar3);
    *(undefined8 *)(param_1 + 0x38) = 0;
    uVar5 = 0;
  }
  return uVar5;
}



===== AcdCancelConnection @ 140001120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 AcdCancelConnection(int param_1,int *param_2,undefined *param_3,undefined8 param_4)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
  puVar3 = FindConnection(param_2);
  if (puVar3 != (undefined8 *)0x0) {
    for (puVar4 = (undefined8 *)puVar3[4]; puVar4 != puVar3 + 4; puVar4 = (undefined8 *)*puVar4) {
      if ((((*(int *)(puVar4 + 2) == param_1) && (*(char *)((longlong)puVar4 + 0x14) == '\0')) &&
          (*(char *)((longlong)puVar4 + 0x15) == '\0')) &&
         (cVar2 = (*(code *)param_3)(param_4,*(undefined4 *)((longlong)puVar4 + 0x41c),puVar4[0xc6],
                                     *(undefined2 *)(puVar4 + 199),puVar4 + 200), cVar2 != '\0')) {
        *(undefined1 *)((longlong)puVar4 + 0x14) = 1;
        uVar5 = 1;
        *(int *)(&DAT_140006124 + (longlong)*param_2 * 8) =
             *(int *)(&DAT_140006124 + (longlong)*param_2 * 8) + 1;
        break;
      }
    }
  }
  KeReleaseSpinLock(&AcdSpinLockG,uVar1);
  return uVar5;
}



===== AcdConnectAddress @ 140001214 =====

undefined8 AcdConnectAddress(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint *puVar3;
  char cVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong local_28;
  longlong local_20;
  
  uVar6 = 0xc0000001;
  cVar4 = IoIs32bitProcess();
  if (cVar4 == '\0') {
    if (*(uint *)(param_2 + 0x10) < 0x618) {
      return 0xc0000023;
    }
  }
  else if (*(uint *)(param_2 + 0x10) < 0x610) {
    return 0xc0000023;
  }
  IoIs32bitProcess(param_1);
  puVar3 = *(uint **)(param_1 + 0x18);
  uVar2 = puVar3[0x101];
  cVar4 = FDisabledAddress((longlong)puVar3);
  if (cVar4 == '\0') {
    local_28 = param_1;
    local_20 = param_2;
    if ((uVar2 & 1) == 0) {
      IoAcquireCancelSpinLock();
      uVar5 = AcdStartConnection(0,puVar3,uVar2,ConnectAddressComplete,2,&local_28);
      if ((char)uVar5 != '\0') {
        uVar6 = 0x103;
        LOCK();
        *(code **)(param_1 + 0x68) = CancelConnectAddress;
        UNLOCK();
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
      }
      IoReleaseCancelSpinLock(0);
    }
    else {
      AcdNewConnection((undefined8 *)puVar3,(undefined8 *)(puVar3 + 0x102));
      uVar6 = 0;
    }
  }
  return uVar6;
}



===== AcdConnectionInProgress @ 140001334 =====

uint AcdConnectionInProgress(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined8 *puVar4;
  
  if (*(uint *)(param_2 + 0x10) < 0x408) {
    uVar3 = 0xc0000023;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x18);
    uVar2 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    puVar4 = FindConnection((int *)(lVar1 + 4));
    if (puVar4 != (undefined8 *)0x0) {
      *(undefined1 *)((longlong)puVar4 + 0x11) = 1;
    }
    KeReleaseSpinLock(&AcdSpinLockG,uVar2);
    uVar3 = ~-(uint)(puVar4 != (undefined8 *)0x0) & 0xc0000001;
  }
  return uVar3;
}



===== AcdEnable @ 1400013b4 =====

undefined8 AcdEnable(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  
  if (*(int *)(param_2 + 0x10) == 0) {
    uVar6 = 0xc0000023;
  }
  else {
    uVar5 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    cVar1 = **(char **)(param_1 + 0x18);
    SetDriverMode(cVar1);
    if (cVar1 == '\0') {
      ClearRequests();
      plVar7 = pDisabledAddressesG;
      while (1 < *(uint *)(plVar7 + 2)) {
        plVar7 = (longlong *)*plVar7;
        lVar2 = *plVar7;
        if ((*(longlong **)(lVar2 + 8) != plVar7) ||
           (plVar3 = (longlong *)plVar7[1], (longlong *)*plVar3 != plVar7)) {
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          uVar6 = (*pcVar4)();
          return uVar6;
        }
        *plVar3 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar3;
        ExFreePoolWithTag(plVar7,0);
        plVar7 = pDisabledAddressesG;
        *(int *)(pDisabledAddressesG + 2) = (int)pDisabledAddressesG[2] + -1;
      }
    }
    KeReleaseSpinLock(&AcdSpinLockG,uVar5);
    AcdTcpCallbackEnable(cVar1);
    uVar6 = 0;
  }
  return uVar6;
}



===== AcdEnableAddress @ 14000147c =====

undefined8 AcdEnableAddress(longlong param_1,longlong param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  
  if (*(uint *)(param_2 + 0x10) < 0x408) {
    uVar2 = 0xc0000023;
  }
  else if (fAcdEnabledG == '\0') {
    uVar2 = 0xc0000001;
  }
  else {
    pcVar1 = *(char **)(param_1 + 0x18);
    if (*pcVar1 == '\0') {
      uVar2 = AcdpEnableAddress((longlong)pcVar1);
    }
    else {
      uVar2 = AcdpDisableAddress((undefined8 *)pcVar1);
    }
  }
  return uVar2;
}



===== AcdNewConnection @ 1400014d0 =====

void AcdNewConnection(undefined8 *param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  
  if (fAcdEnabledG != '\0') {
    uVar1 = KeAcquireSpinLockRaiseToDpc();
    AddCompletionBlock(0,param_1,1,param_2,0,0,(undefined8 *)0x0);
    KeReleaseSpinLock(&AcdSpinLockG,uVar1);
  }
  return;
}



===== AcdQueryState @ 14000155c =====

undefined8 AcdQueryState(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_2 + 8) == 0) {
    uVar2 = 0xc0000023;
  }
  else {
    uVar1 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    **(byte **)(param_1 + 0x18) = -(fAcdEnableRedirNotifs != '\0') & fAcdEnabledG;
    *(undefined8 *)(param_1 + 0x38) = 1;
    KeReleaseSpinLock(&AcdSpinLockG,uVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== AcdReset @ 1400015cc =====

void AcdReset(void)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  SetDriverMode(0);
  ClearRequests();
  KeReleaseSpinLock(&AcdSpinLockG,uVar1);
  return;
}



===== AcdSignalCompletion @ 140001618 =====

undefined8 AcdSignalCompletion(longlong param_1,longlong param_2)

{
  undefined1 *puVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  
  bVar2 = false;
  if (*(uint *)(param_2 + 0x10) < 0x408) {
    uVar4 = 0xc0000023;
  }
  else {
    puVar1 = *(undefined1 **)(param_1 + 0x18);
    uVar3 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    plVar5 = FindConnection((int *)(puVar1 + 4));
    if ((plVar5 != (longlong *)0x0) && (*(char *)((longlong)plVar5 + 0x12) == '\0')) {
      bVar2 = true;
      *(undefined1 *)((longlong)plVar5 + 0x12) = 1;
    }
    KeReleaseSpinLock(&AcdSpinLockG,uVar3);
    if (bVar2) {
      AcdSignalCompletionCommon(plVar5,*puVar1);
      uVar4 = 0;
    }
    else {
      uVar4 = 0xc0000001;
    }
  }
  return uVar4;
}



===== AcdSignalCompletionCommon @ 1400016c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AcdSignalCompletionCommon(longlong *param_1,undefined1 param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  plVar1 = param_1 + 4;
  plVar7 = (longlong *)0x0;
  while( true ) {
    bVar5 = false;
    uVar6 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    plVar3 = (longlong *)*plVar1;
    plVar8 = plVar7;
    while (plVar7 = plVar3, plVar7 != plVar1) {
      if ((*(char *)((longlong)plVar7 + 0x14) == '\0') &&
         (*(char *)((longlong)plVar7 + 0x15) == '\0')) {
        *(undefined1 *)((longlong)plVar7 + 0x15) = 1;
        bVar5 = true;
        goto LAB_1400017b2;
      }
      plVar8 = plVar7;
      plVar3 = (longlong *)*plVar7;
    }
    lVar2 = *param_1;
    if ((*(longlong **)(lVar2 + 8) != param_1) ||
       (plVar7 = (longlong *)param_1[1], (longlong *)*plVar7 != param_1)) break;
    *plVar7 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar7;
    plVar7 = plVar8;
    while (plVar3 = (longlong *)*plVar1, plVar3 != plVar1) {
      if (((longlong *)plVar3[1] != plVar1) ||
         (lVar2 = *plVar3, *(longlong **)(lVar2 + 8) != plVar3)) goto LAB_1400017e8;
      *plVar1 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar1;
      ExFreePoolWithTag(plVar3);
      lOutstandingRequestsG = lOutstandingRequestsG + -1;
      plVar7 = plVar3;
    }
    ExFreePoolWithTag(param_1,0);
    KeSetEvent(&AcdRequestThreadEventG,0,0);
LAB_1400017b2:
    KeReleaseSpinLock(&AcdSpinLockG,uVar6);
    if (!bVar5) {
      return;
    }
    (*(code *)plVar7[0xc6])(param_2);
  }
LAB_1400017e8:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return;
}



===== AcdStartConnection @ 140001810 =====

ulonglong AcdStartConnection(undefined4 param_1,uint *param_2,uint param_3,undefined8 param_4,
                            ushort param_5,undefined8 *param_6)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if ((fAcdEnabledG != '\0') && (*param_2 < 4)) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    *(int *)(&AcdStatsG + (longlong)(int)*param_2 * 8) =
         *(int *)(&AcdStatsG + (longlong)(int)*param_2 * 8) + 1;
    uVar2 = AddCompletionBlock(param_1,(undefined8 *)param_2,param_3,(undefined8 *)0x0,param_4,
                               param_5,param_6);
    uVar3 = KeReleaseSpinLock(&AcdSpinLockG,uVar1);
    register0x00000020 = (BADSPACEBASE *)CONCAT71((int7)((ulonglong)uVar3 >> 8),(char)uVar2);
  }
  return (ulonglong)register0x00000020;
}



===== AcdTcpCallbackEnable @ 1400018d4 =====

void AcdTcpCallbackEnable(char param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  char cVar3;
  bool bVar4;
  
  cVar3 = '\0';
  uVar1 = KeAcquireSpinLockRaiseToDpc(&TcpCcbLock);
  lVar2 = TcpCcbRegistrationHandle;
  if ((TcpCcbRegistrationHandle != 0) && (cVar3 = '\x01', param_1 == '\0')) {
    TcpCcbRegistrationHandle = 0;
  }
  KeReleaseSpinLock(&TcpCcbLock,uVar1);
  if (param_1 == cVar3) {
    return;
  }
  if (param_1 != '\0') {
    lVar2 = ExRegisterCallback(TcpCcbObject,AcdTcpCallbackHandler,0);
    if (lVar2 == 0) {
      return;
    }
    uVar1 = KeAcquireSpinLockRaiseToDpc(&TcpCcbLock);
    bVar4 = TcpCcbRegistrationHandle == 0;
    if (bVar4) {
      TcpCcbRegistrationHandle = lVar2;
    }
    KeReleaseSpinLock(&TcpCcbLock,uVar1);
    if (bVar4) {
      return;
    }
  }
  ExUnregisterCallback(lVar2);
  return;
}



===== AcdTcpCallbackHandler @ 1400019d0 =====

void AcdTcpCallbackHandler(undefined8 param_1,int param_2,short *param_3)

{
  undefined4 local_628;
  int local_624;
  undefined1 local_620 [520];
  undefined4 local_418;
  int local_414;
  undefined1 local_410 [1032];
  
  memset(local_410,0,0x3fc);
  memset(local_620,0,0x1fc);
  if (((param_2 == 1) && (*param_3 == 2)) && (*(int *)(param_3 + 4) == 5)) {
    local_414 = **(int **)(param_3 + 0xc);
    local_624 = **(int **)(param_3 + 8);
    if (((local_624 != 0) && (local_414 != 0)) && ((char)local_414 != '\x7f')) {
      local_418 = 0;
      local_628 = 0;
      AcdNewConnection((undefined8 *)&local_418,(undefined8 *)&local_628);
    }
  }
  return;
}



===== AcdUnbind @ 140001a78 =====

undefined8 AcdUnbind(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  
  if (*(uint *)(param_2 + 0x10) < 8) {
    uVar7 = 0xc0000023;
  }
  else {
    plVar1 = (longlong *)**(longlong **)(param_1 + 0x18);
    uVar5 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    for (puVar9 = AcdConnectionQueueG; (undefined8 **)puVar9 != &AcdConnectionQueueG;
        puVar9 = (undefined8 *)*puVar9) {
      for (puVar8 = (undefined8 *)puVar9[4]; puVar8 != puVar9 + 4; puVar8 = (undefined8 *)*puVar8) {
        if (*(int *)(puVar8 + 2) == (int)plVar1[3]) {
          *(undefined1 *)((longlong)puVar8 + 0x14) = 1;
        }
      }
    }
    uVar6 = KeAcquireSpinLockRaiseToDpc(plVar1 + 2);
    *(undefined1 *)((longlong)plVar1 + 0x1c) = 0;
    KeReleaseSpinLock(plVar1 + 2,uVar6);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) != plVar1) ||
       (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar7 = (*pcVar4)();
      return uVar7;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseSpinLock(&AcdSpinLockG,CONCAT71((int7)((ulonglong)lVar2 >> 8),uVar5));
    *(undefined8 *)(param_1 + 0x38) = 0;
    uVar7 = 0;
  }
  return uVar7;
}



===== AcdWaitForNotification @ 140001b70 =====

undefined8 AcdWaitForNotification(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  undefined1 local_res10 [24];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res10[0] = 0;
  if (*(uint *)(param_2 + 8) < 0x618) {
    uVar4 = 0xc0000023;
  }
  else {
    IoAcquireCancelSpinLock(local_res10);
    uVar3 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    puVar8 = auStack_28;
    *(undefined4 *)(param_1 + 0x30) = 0x103;
    puVar5 = &AcdNotificationQueueG;
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    LOCK();
    *(code **)(param_1 + 0x68) = CancelNotification;
    UNLOCK();
    puVar7 = (undefined8 *)(param_1 + 0xa8);
    puVar6 = DAT_140006168;
    if ((undefined8 *)*DAT_140006168 != &AcdNotificationQueueG) {
      puVar6 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      puVar5 = (undefined8 *)(*pcVar2)();
      puVar8 = auStack_20;
    }
    *(undefined8 **)(param_1 + 0xb0) = puVar6;
    *puVar7 = puVar5;
    *puVar6 = puVar7;
    *(undefined8 *)(puVar8 + -8) = 0x140001c1e;
    DAT_140006168 = puVar7;
    KeSetEvent(&AcdRequestThreadEventG,0,0);
    *(undefined8 *)(puVar8 + -8) = 0x140001c34;
    KeReleaseSpinLock(&AcdSpinLockG,uVar3);
    *(undefined8 *)(puVar8 + -8) = 0x140001c44;
    IoReleaseCancelSpinLock(puVar8[0x38]);
    uVar4 = 0x103;
  }
  return uVar4;
}



===== AcdpDisableAddress @ 140001c60 =====

undefined8 AcdpDisableAddress(undefined8 *param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  char *pcVar12;
  char *pcVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  longlong lVar16;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar7 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
  puVar14 = auStack_28;
  pcVar12 = (char *)(*pDisabledAddressesG + 0x10);
  if (*pcVar12 == '\0') {
    lVar16 = 8;
    do {
      uVar6 = param_1[1];
      *(undefined8 *)pcVar12 = *param_1;
      *(undefined8 *)(pcVar12 + 8) = uVar6;
      uVar6 = param_1[3];
      *(undefined8 *)(pcVar12 + 0x10) = param_1[2];
      *(undefined8 *)(pcVar12 + 0x18) = uVar6;
      uVar6 = param_1[5];
      *(undefined8 *)(pcVar12 + 0x20) = param_1[4];
      *(undefined8 *)(pcVar12 + 0x28) = uVar6;
      uVar6 = param_1[7];
      *(undefined8 *)(pcVar12 + 0x30) = param_1[6];
      *(undefined8 *)(pcVar12 + 0x38) = uVar6;
      uVar6 = param_1[9];
      *(undefined8 *)(pcVar12 + 0x40) = param_1[8];
      *(undefined8 *)(pcVar12 + 0x48) = uVar6;
      uVar6 = param_1[0xb];
      *(undefined8 *)(pcVar12 + 0x50) = param_1[10];
      *(undefined8 *)(pcVar12 + 0x58) = uVar6;
      uVar3 = *(undefined4 *)((longlong)param_1 + 100);
      uVar4 = *(undefined4 *)(param_1 + 0xd);
      uVar5 = *(undefined4 *)((longlong)param_1 + 0x6c);
      *(undefined4 *)(pcVar12 + 0x60) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(pcVar12 + 100) = uVar3;
      *(undefined4 *)(pcVar12 + 0x68) = uVar4;
      *(undefined4 *)(pcVar12 + 0x6c) = uVar5;
      pcVar13 = pcVar12 + 0x80;
      puVar8 = param_1 + 0xe;
      uVar6 = param_1[0xf];
      param_1 = param_1 + 0x10;
      *(undefined8 *)(pcVar12 + 0x70) = *puVar8;
      *(undefined8 *)(pcVar12 + 0x78) = uVar6;
      lVar16 = lVar16 + -1;
      pcVar12 = pcVar13;
    } while (lVar16 != 0);
    *(undefined8 *)pcVar13 = *param_1;
    puVar14 = auStack_28;
  }
  else if (*(uint *)(pDisabledAddressesG + 2) < *(uint *)((longlong)pDisabledAddressesG + 0x14)) {
    KeReleaseSpinLock(&AcdSpinLockG,CONCAT71((int7)((ulonglong)pcVar12 >> 8),uVar7));
    puVar8 = (undefined8 *)ExAllocatePool2(0x40,0x418,0x4e646341);
    if (puVar8 == (undefined8 *)0x0) {
      return 0xc000009a;
    }
    lVar16 = 8;
    puVar11 = puVar8 + 2;
    do {
      uVar6 = param_1[1];
      *puVar11 = *param_1;
      puVar11[1] = uVar6;
      uVar6 = param_1[3];
      puVar11[2] = param_1[2];
      puVar11[3] = uVar6;
      uVar6 = param_1[5];
      puVar11[4] = param_1[4];
      puVar11[5] = uVar6;
      uVar6 = param_1[7];
      puVar11[6] = param_1[6];
      puVar11[7] = uVar6;
      uVar6 = param_1[9];
      puVar11[8] = param_1[8];
      puVar11[9] = uVar6;
      uVar6 = param_1[0xb];
      puVar11[10] = param_1[10];
      puVar11[0xb] = uVar6;
      uVar3 = *(undefined4 *)((longlong)param_1 + 100);
      uVar4 = *(undefined4 *)(param_1 + 0xd);
      uVar5 = *(undefined4 *)((longlong)param_1 + 0x6c);
      *(undefined4 *)(puVar11 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)((longlong)puVar11 + 100) = uVar3;
      *(undefined4 *)(puVar11 + 0xd) = uVar4;
      *(undefined4 *)((longlong)puVar11 + 0x6c) = uVar5;
      puVar10 = puVar11 + 0x10;
      puVar1 = param_1 + 0xe;
      uVar3 = *(undefined4 *)((longlong)param_1 + 0x74);
      uVar4 = *(undefined4 *)(param_1 + 0xf);
      uVar5 = *(undefined4 *)((longlong)param_1 + 0x7c);
      param_1 = param_1 + 0x10;
      *(undefined4 *)(puVar11 + 0xe) = *(undefined4 *)puVar1;
      *(undefined4 *)((longlong)puVar11 + 0x74) = uVar3;
      *(undefined4 *)(puVar11 + 0xf) = uVar4;
      *(undefined4 *)((longlong)puVar11 + 0x7c) = uVar5;
      lVar16 = lVar16 + -1;
      puVar11 = puVar10;
    } while (lVar16 != 0);
    *puVar10 = *param_1;
    uVar7 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    puVar15 = auStack_28;
    puVar11 = (undefined8 *)pDisabledAddressesG[1];
    plVar9 = pDisabledAddressesG;
    if ((longlong *)*puVar11 != pDisabledAddressesG) {
      puVar11 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar9 = (longlong *)(*pcVar2)(3,uVar7);
      puVar15 = auStack_20;
    }
    *puVar8 = plVar9;
    puVar8[1] = puVar11;
    *puVar11 = puVar8;
    plVar9[1] = (longlong)puVar8;
    *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
    puVar14 = puVar15;
  }
  *(undefined8 *)(puVar14 + -8) = 0x140001d0f;
  KeReleaseSpinLock(&AcdSpinLockG);
  return 0;
}



===== AcdpEnableAddress @ 140001e1c =====

undefined8 AcdpEnableAddress(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined1 uVar5;
  int iVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  plVar7 = (longlong *)0x0;
  plVar9 = (longlong *)0x0;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
  plVar4 = pDisabledAddressesG;
  if (*(uint *)(pDisabledAddressesG + 2) == 1) {
    plVar9 = (longlong *)*pDisabledAddressesG;
    memset(plVar9 + 2,0,0x408);
    puVar8 = auStack_28;
  }
  else {
    puVar8 = auStack_28;
    if (1 < *(uint *)(pDisabledAddressesG + 2)) {
      plVar7 = (longlong *)*pDisabledAddressesG;
      puVar8 = auStack_28;
      if ((longlong *)*pDisabledAddressesG != pDisabledAddressesG) {
        do {
          plVar9 = plVar7;
          iVar6 = memcmp(plVar9 + 3,(void *)(param_1 + 8),0x400);
          plVar7 = plVar9;
          if (iVar6 == 0) break;
          plVar7 = (longlong *)*plVar9;
        } while (plVar7 != plVar4);
        puVar8 = auStack_28;
        if (plVar7 != plVar4) {
          lVar1 = *plVar7;
          if ((*(longlong **)(lVar1 + 8) == plVar7) &&
             (plVar2 = (longlong *)plVar7[1], (longlong *)*plVar2 == plVar7)) {
            *plVar2 = lVar1;
            *(longlong **)(lVar1 + 8) = plVar2;
            *(int *)(plVar4 + 2) = (int)plVar4[2] + -1;
            puVar8 = auStack_28;
            goto LAB_140001ecd;
          }
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          puVar8 = auStack_20;
        }
      }
      plVar7 = (longlong *)0x0;
    }
  }
LAB_140001ecd:
  *(undefined8 *)(puVar8 + -8) = 0x140001ede;
  KeReleaseSpinLock(&AcdSpinLockG,uVar5);
  if (plVar7 != (longlong *)0x0) {
    *(undefined8 *)(puVar8 + -8) = 0x140001ef4;
    ExFreePoolWithTag(plVar9,0);
  }
  return 0;
}



===== AddCompletionBlock @ 140001f20 =====

ulonglong AddCompletionBlock(undefined4 param_1,undefined8 *param_2,uint param_3,undefined8 *param_4
                            ,undefined8 param_5,ushort param_6,undefined8 *param_7)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined1 *puVar13;
  ulonglong uVar14;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  uVar14 = (ulonglong)param_6;
  puVar9 = (undefined1 *)register0x00000020;
  if (lOutstandingRequestsG < 100) {
    puVar12 = (undefined8 *)(uVar14 * 8 + 0x640);
    puVar6 = (undefined8 *)ExAllocatePool2(0x40,puVar12,0x4e646341);
    puVar9 = (undefined1 *)0x0;
    if (puVar6 != (undefined8 *)0x0) {
      *(undefined4 *)(puVar6 + 2) = param_1;
      *(undefined2 *)((longlong)puVar6 + 0x14) = 0;
      lVar7 = 8;
      puVar11 = puVar6 + 3;
      do {
        uVar8 = param_2[1];
        *puVar11 = *param_2;
        puVar11[1] = uVar8;
        uVar8 = param_2[3];
        puVar11[2] = param_2[2];
        puVar11[3] = uVar8;
        uVar8 = param_2[5];
        puVar11[4] = param_2[4];
        puVar11[5] = uVar8;
        uVar8 = param_2[7];
        puVar11[6] = param_2[6];
        puVar11[7] = uVar8;
        uVar8 = param_2[9];
        puVar11[8] = param_2[8];
        puVar11[9] = uVar8;
        uVar8 = param_2[0xb];
        puVar11[10] = param_2[10];
        puVar11[0xb] = uVar8;
        uVar3 = *(undefined4 *)((longlong)param_2 + 100);
        uVar4 = *(undefined4 *)(param_2 + 0xd);
        uVar5 = *(undefined4 *)((longlong)param_2 + 0x6c);
        *(undefined4 *)(puVar11 + 0xc) = *(undefined4 *)(param_2 + 0xc);
        *(undefined4 *)((longlong)puVar11 + 100) = uVar3;
        *(undefined4 *)(puVar11 + 0xd) = uVar4;
        *(undefined4 *)((longlong)puVar11 + 0x6c) = uVar5;
        puVar10 = puVar11 + 0x10;
        puVar1 = param_2 + 0xe;
        uVar3 = *(undefined4 *)((longlong)param_2 + 0x74);
        uVar4 = *(undefined4 *)(param_2 + 0xf);
        uVar5 = *(undefined4 *)((longlong)param_2 + 0x7c);
        param_2 = param_2 + 0x10;
        *(undefined4 *)(puVar11 + 0xe) = *(undefined4 *)puVar1;
        *(undefined4 *)((longlong)puVar11 + 0x74) = uVar3;
        *(undefined4 *)(puVar11 + 0xf) = uVar4;
        *(undefined4 *)((longlong)puVar11 + 0x7c) = uVar5;
        lVar7 = lVar7 + -1;
        puVar11 = puVar10;
      } while (lVar7 != 0);
      *(undefined4 *)puVar10 = *(undefined4 *)param_2;
      uVar8 = PsGetCurrentProcessId();
      *(uint *)((longlong)puVar6 + 0x41c) = param_3;
      puVar6[0xc5] = uVar8;
      if (param_4 == (undefined8 *)0x0) {
        puVar12 = (undefined8 *)0x0;
        memset(puVar6 + 0x84,0,0x204);
      }
      else {
        lVar7 = 4;
        puVar11 = puVar6 + 0x84;
        do {
          uVar8 = param_4[1];
          *puVar11 = *param_4;
          puVar11[1] = uVar8;
          uVar8 = param_4[3];
          puVar11[2] = param_4[2];
          puVar11[3] = uVar8;
          uVar8 = param_4[5];
          puVar11[4] = param_4[4];
          puVar11[5] = uVar8;
          uVar8 = param_4[7];
          puVar11[6] = param_4[6];
          puVar11[7] = uVar8;
          uVar8 = param_4[9];
          puVar11[8] = param_4[8];
          puVar11[9] = uVar8;
          uVar8 = param_4[0xb];
          puVar11[10] = param_4[10];
          puVar11[0xb] = uVar8;
          uVar3 = *(undefined4 *)((longlong)param_4 + 100);
          uVar4 = *(undefined4 *)(param_4 + 0xd);
          uVar5 = *(undefined4 *)((longlong)param_4 + 0x6c);
          *(undefined4 *)(puVar11 + 0xc) = *(undefined4 *)(param_4 + 0xc);
          *(undefined4 *)((longlong)puVar11 + 100) = uVar3;
          *(undefined4 *)(puVar11 + 0xd) = uVar4;
          *(undefined4 *)((longlong)puVar11 + 0x6c) = uVar5;
          puVar10 = puVar11 + 0x10;
          puVar1 = param_4 + 0xe;
          uVar8 = param_4[0xf];
          param_4 = param_4 + 0x10;
          puVar11[0xe] = *puVar1;
          puVar11[0xf] = uVar8;
          lVar7 = lVar7 + -1;
          puVar11 = puVar10;
        } while (lVar7 != 0);
        *(undefined4 *)puVar10 = *(undefined4 *)param_4;
      }
      puVar13 = auStack_38;
      puVar6[0xc6] = param_5;
      *(ushort *)(puVar6 + 199) = param_6;
      if (param_6 != 0) {
        puVar12 = (undefined8 *)((longlong)puVar6 - (longlong)param_7);
        do {
          *(undefined8 *)((longlong)(puVar12 + 200) + (longlong)param_7) = *param_7;
          param_7 = param_7 + 1;
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
      }
      if ((param_3 & 1) == 0) {
        uVar8 = AddCompletionToConnection(puVar6,puVar12);
        puVar13 = auStack_38;
        if ((char)uVar8 == '\0') {
          puVar9 = (undefined1 *)ExFreePoolWithTag(puVar6,0);
          goto LAB_140002121;
        }
      }
      else {
        puVar12 = &AcdCompletionQueueG;
        if ((undefined8 *)*DAT_140006178 != &AcdCompletionQueueG) {
          puVar12 = (undefined8 *)0x3;
          pcVar2 = (code *)swi(0x29);
          DAT_140006178 = (undefined8 *)(*pcVar2)();
          puVar13 = auStack_30;
        }
        *puVar6 = puVar12;
        puVar6[1] = DAT_140006178;
        *DAT_140006178 = puVar6;
        DAT_140006178 = puVar6;
      }
      lOutstandingRequestsG = lOutstandingRequestsG + 1;
      *(undefined8 *)(puVar13 + -8) = 0x1400020fb;
      uVar8 = KeSetEvent(&AcdRequestThreadEventG,0,0);
      return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
    }
  }
LAB_140002121:
  return (ulonglong)puVar9 & 0xffffffffffffff00;
}



===== AddCompletionToConnection @ 14000214c =====

undefined8 AddCompletionToConnection(undefined8 *param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  puVar2 = FindConnection((int *)(param_1 + 3));
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x30,0x4e646341);
    if (puVar2 == (undefined8 *)0x0) {
      return 0;
    }
    *(undefined2 *)(puVar2 + 2) = 0;
    param_2 = &AcdConnectionQueueG;
    *(undefined4 *)((longlong)puVar2 + 0x14) = 0;
    *(undefined4 *)(puVar2 + 3) = 0;
    *(undefined1 *)((longlong)puVar2 + 0x12) = 0;
    puVar3 = puVar2 + 4;
    *param_1 = puVar3;
    param_1[1] = puVar3;
    puVar2[5] = param_1;
    *puVar3 = param_1;
    if ((undefined8 *)*DAT_140006158 != &AcdConnectionQueueG) goto LAB_1400021d8;
  }
  else {
    puVar3 = (undefined8 *)puVar2[5];
    puVar4 = puVar2 + 4;
    if ((undefined8 *)*puVar3 == puVar4) {
      *param_1 = puVar4;
      param_1[1] = puVar3;
      *puVar3 = param_1;
      puVar2[5] = param_1;
      goto LAB_1400021f0;
    }
LAB_1400021d8:
    puVar2 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    DAT_140006158 = (undefined8 *)(*pcVar1)();
  }
  *puVar2 = param_2;
  puVar2[1] = DAT_140006158;
  *DAT_140006158 = puVar2;
  puVar4 = DAT_140006158;
  DAT_140006158 = puVar2;
LAB_1400021f0:
  return CONCAT71((int7)((ulonglong)puVar4 >> 8),1);
}



===== CancelConnectAddress @ 140002200 =====

void CancelConnectAddress(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  char cVar2;
  
  cVar2 = AcdCancelConnection(0,*(int **)(param_2 + 0x18),CancelConnectAddressCallback,param_2);
  if (cVar2 == '\0') {
    IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    LOCK();
    uVar1 = *(undefined8 *)(param_2 + 0x68);
    *(undefined8 *)(param_2 + 0x68) = 0;
    UNLOCK();
    IoReleaseCancelSpinLock(CONCAT71((int7)((ulonglong)uVar1 >> 8),*(undefined1 *)(param_2 + 0x45)))
    ;
    IofCompleteRequest(param_2,0);
  }
  return;
}



===== CancelConnectAddressCallback @ 140002280 =====

undefined8
CancelConnectAddressCallback
          (longlong param_1,undefined8 param_2,undefined8 param_3,short param_4,longlong *param_5)

{
  longlong *in_RAX;
  
  if ((param_4 == 2) && (in_RAX = param_5, *param_5 == param_1)) {
    return CONCAT71((int7)((ulonglong)param_5 >> 8),1);
  }
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== CancelNotification @ 1400022a0 =====

void CancelNotification(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseSpinLock(&AcdSpinLockG,CONCAT71((int7)((ulonglong)plVar3 >> 8),uVar5));
    IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
    IofCompleteRequest(param_2,0);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== ClearRequests @ 140002334 =====

void ClearRequests(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  
  do {
    plVar4 = AcdConnectionQueueG;
    while( true ) {
      if ((longlong **)plVar4 == &AcdConnectionQueueG) {
        while( true ) {
          puVar3 = AcdCompletionQueueG;
          if ((undefined8 **)AcdCompletionQueueG == &AcdCompletionQueueG) {
            return;
          }
          if (((undefined8 **)AcdCompletionQueueG[1] != &AcdCompletionQueueG) ||
             (puVar1 = (undefined8 *)*AcdCompletionQueueG,
             (undefined8 *)puVar1[1] != AcdCompletionQueueG)) break;
          AcdCompletionQueueG = puVar1;
          puVar1[1] = &AcdCompletionQueueG;
          ExFreePoolWithTag(puVar3,0);
          lOutstandingRequestsG = lOutstandingRequestsG + -1;
        }
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        return;
      }
      if (*(char *)((longlong)plVar4 + 0x12) == '\0') break;
      plVar4 = (longlong *)*plVar4;
    }
    *(undefined1 *)((longlong)plVar4 + 0x12) = 1;
    KeReleaseSpinLock(&AcdSpinLockG);
    AcdSignalCompletionCommon(plVar4,0);
    KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
  } while( true );
}



===== ConnectAddressComplete @ 1400023f0 =====

void ConnectAddressComplete(char param_1,longlong *param_2)

{
  longlong lVar1;
  undefined1 local_res8 [8];
  
  lVar1 = *param_2;
  local_res8[0] = 0;
  *(undefined8 *)(lVar1 + 0x38) = 0;
  *(uint *)(lVar1 + 0x30) = ~-(uint)(param_1 != '\0') & 0xc0000001;
  IoAcquireCancelSpinLock(local_res8);
  LOCK();
  *(undefined8 *)(lVar1 + 0x68) = 0;
  UNLOCK();
  IoReleaseCancelSpinLock(local_res8[0]);
  IofCompleteRequest(lVar1,0);
  return;
}



===== FDisabledAddress @ 140002460 =====

undefined1 FDisabledAddress(longlong param_1)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  
  uVar5 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
  puVar1 = pDisabledAddressesG;
  uVar6 = 0;
  if (fAcdEnabledG != '\0') {
    for (puVar4 = (undefined8 *)*pDisabledAddressesG; puVar4 != puVar1;
        puVar4 = (undefined8 *)*puVar4) {
      if (*(char *)(puVar4 + 2) != '\0') {
        iVar3 = memcmp(puVar4 + 3,(void *)(param_1 + 4),0x400);
        if (iVar3 == 0) {
          uVar5 = 1;
        }
      }
    }
    uVar6 = uVar5;
  }
  KeReleaseSpinLock(&AcdSpinLockG,uVar2);
  return uVar6;
}



===== FindConnection @ 140002518 =====

undefined8 * FindConnection(int *param_1)

{
  int *_Buf1;
  char cVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined8 *puVar7;
  bool bVar8;
  
  if ((undefined8 **)AcdConnectionQueueG != &AcdConnectionQueueG) {
    iVar2 = *param_1;
    _Buf1 = param_1 + 1;
    puVar7 = AcdConnectionQueueG;
    do {
      lVar3 = puVar7[4];
      if (iVar2 != *(int *)(lVar3 + 0x18)) goto LAB_1400025d0;
      if (iVar2 == 0) {
        bVar8 = *_Buf1 == *(int *)(lVar3 + 0x1c);
LAB_1400025ce:
        if (bVar8) {
          return puVar7;
        }
      }
      else if (iVar2 == 1) {
        if (*_Buf1 == *(int *)(lVar3 + 0x1c)) {
          bVar8 = (short)param_1[2] == *(short *)(lVar3 + 0x20);
          goto LAB_1400025ce;
        }
      }
      else {
        if (iVar2 == 2) {
          iVar4 = memcmp(_Buf1,(void *)(lVar3 + 0x1c),0xf);
          bVar8 = iVar4 == 0;
          goto LAB_1400025ce;
        }
        if (iVar2 == 3) {
          uVar6 = 0;
          piVar5 = _Buf1;
          while( true ) {
            cVar1 = *(char *)(((lVar3 + 0x18) - (longlong)param_1) + (longlong)piVar5);
            if ((char)*piVar5 != cVar1) break;
            if ((char)*piVar5 == '\0') {
              return puVar7;
            }
            if (cVar1 == '\0') {
              return puVar7;
            }
            uVar6 = uVar6 + 1;
            piVar5 = (int *)((longlong)piVar5 + 1);
            if (0x3ff < uVar6) {
              return puVar7;
            }
          }
        }
      }
LAB_1400025d0:
      puVar7 = (undefined8 *)*puVar7;
    } while ((undefined8 **)puVar7 != &AcdConnectionQueueG);
  }
  return (undefined8 *)0x0;
}



===== SetDriverMode @ 140002600 =====

void SetDriverMode(undefined1 param_1)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  
  fAcdEnabledG = param_1;
  for (puVar2 = AcdDriverListG; (undefined8 **)puVar2 != &AcdDriverListG;
      puVar2 = (undefined8 *)*puVar2) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(puVar2 + 2);
    *(undefined1 *)((longlong)puVar2 + 0x1c) = param_1;
    KeReleaseSpinLock(puVar2 + 2,uVar1);
  }
  return;
}



===== AcdDispatch @ 140002680 =====

uint AcdDispatch(undefined8 param_1,longlong param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  
  pcVar2 = *(char **)(param_2 + 0xb8);
  cVar1 = *pcVar2;
  if (cVar1 == '\0') {
    uVar4 = AcdCreate();
    uVar3 = (uint)uVar4;
  }
  else if (cVar1 == '\x02') {
    uVar4 = AcdClose();
    uVar3 = (uint)uVar4;
  }
  else {
    if (cVar1 == '\x0e') {
      uVar3 = AcdDispatchDeviceControl(param_2,(longlong)pcVar2);
      return uVar3;
    }
    if (cVar1 == '\x0f') {
      uVar3 = AcdDispatchInternalDeviceControl(param_2,(longlong)pcVar2);
      return uVar3;
    }
    if (cVar1 != '\x12') {
      uVar3 = 0xc0000002;
      goto LAB_1400026e6;
    }
    uVar4 = AcdCleanup();
    uVar3 = (uint)uVar4;
  }
  if (uVar3 == 0x103) {
    return 0x103;
  }
LAB_1400026e6:
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(uint *)(param_2 + 0x30) = uVar3;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== AcdNotificationRequestThread @ 140002720 =====

void AcdNotificationRequestThread(void)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 local_res10 [8];
  
  local_res10[0] = 0;
  IoStartTimer(pAcdDeviceObjectG);
  do {
    IoAcquireCancelSpinLock(local_res10);
    uVar3 = KeAcquireSpinLockRaiseToDpc(&AcdSpinLockG);
    puVar2 = AcdCompletionQueueG;
    if ((undefined8 **)AcdNotificationQueueG == &AcdNotificationQueueG) {
LAB_14000278d:
      KeReleaseSpinLock(&AcdSpinLockG,uVar3);
      IoReleaseCancelSpinLock(local_res10[0]);
    }
    else {
      for (puVar4 = AcdConnectionQueueG;
          ((undefined8 **)puVar4 != &AcdConnectionQueueG && (*(char *)(puVar4 + 2) == '\0'));
          puVar4 = (undefined8 *)*puVar4) {
        if (*(char *)((longlong)puVar4 + 0x12) == '\0') {
          for (puVar5 = (undefined8 *)puVar4[4]; puVar5 != puVar4 + 4;
              puVar5 = (undefined8 *)*puVar5) {
            if (*(char *)((longlong)puVar5 + 0x14) == '\0') {
              *(undefined1 *)(puVar4 + 2) = 1;
              ProcessCompletion((longlong)puVar5,local_res10[0],uVar3);
              goto LAB_14000283b;
            }
          }
        }
      }
      if ((undefined8 **)AcdCompletionQueueG == &AcdCompletionQueueG) goto LAB_14000278d;
      if (((undefined8 **)AcdCompletionQueueG[1] != &AcdCompletionQueueG) ||
         (puVar4 = (undefined8 *)*AcdCompletionQueueG,
         (undefined8 *)puVar4[1] != AcdCompletionQueueG)) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(3);
        return;
      }
      lOutstandingRequestsG = lOutstandingRequestsG + -1;
      AcdCompletionQueueG = puVar4;
      puVar4[1] = &AcdCompletionQueueG;
      ProcessCompletion((longlong)puVar2,local_res10[0],uVar3);
      ExFreePool(puVar2);
    }
LAB_14000283b:
    if (AcdStopThread == '\x01') {
      return;
    }
    KeWaitForSingleObject(&AcdRequestThreadEventG,0,0,0,0);
    KeClearEvent(&AcdRequestThreadEventG);
  } while( true );
}



===== ProcessCompletion @ 1400028ac =====

void ProcessCompletion(longlong param_1,undefined1 param_2,undefined1 param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined8 *_Dst;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  longlong *plVar8;
  char cVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  
  plVar8 = AcdNotificationQueueG;
  lVar10 = *AcdNotificationQueueG;
  if (((longlong **)AcdNotificationQueueG[1] != &AcdNotificationQueueG) ||
     (*(longlong **)(lVar10 + 8) != AcdNotificationQueueG)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  plVar2 = AcdNotificationQueueG + -0x15;
  AcdNotificationQueueG = (longlong *)lVar10;
  *(longlong ***)(lVar10 + 8) = &AcdNotificationQueueG;
  LOCK();
  plVar8[-8] = 0;
  UNLOCK();
  cVar9 = IoIs32bitProcess(plVar2);
  _Dst = (undefined8 *)plVar8[-0x12];
  puVar11 = (undefined8 *)(param_1 + 0x18);
  if (cVar9 == '\0') {
    memmove(_Dst,puVar11,0x618);
  }
  else {
    lVar10 = 8;
    puVar13 = _Dst;
    do {
      uVar7 = puVar11[1];
      *puVar13 = *puVar11;
      puVar13[1] = uVar7;
      uVar7 = puVar11[3];
      puVar13[2] = puVar11[2];
      puVar13[3] = uVar7;
      uVar7 = puVar11[5];
      puVar13[4] = puVar11[4];
      puVar13[5] = uVar7;
      uVar7 = puVar11[7];
      puVar13[6] = puVar11[6];
      puVar13[7] = uVar7;
      uVar7 = puVar11[9];
      puVar13[8] = puVar11[8];
      puVar13[9] = uVar7;
      uVar7 = puVar11[0xb];
      puVar13[10] = puVar11[10];
      puVar13[0xb] = uVar7;
      uVar7 = puVar11[0xd];
      puVar13[0xc] = puVar11[0xc];
      puVar13[0xd] = uVar7;
      puVar12 = puVar13 + 0x10;
      puVar1 = puVar11 + 0xe;
      uVar7 = puVar11[0xf];
      puVar11 = puVar11 + 0x10;
      puVar13[0xe] = *puVar1;
      puVar13[0xf] = uVar7;
      lVar10 = lVar10 + -1;
      puVar13 = puVar12;
    } while (lVar10 != 0);
    lVar10 = 4;
    *(undefined4 *)puVar12 = *(undefined4 *)puVar11;
    puVar11 = (undefined8 *)(param_1 + 0x420);
    puVar13 = _Dst + 0x81;
    do {
      uVar7 = puVar11[1];
      *puVar13 = *puVar11;
      puVar13[1] = uVar7;
      uVar7 = puVar11[3];
      puVar13[2] = puVar11[2];
      puVar13[3] = uVar7;
      uVar7 = puVar11[5];
      puVar13[4] = puVar11[4];
      puVar13[5] = uVar7;
      uVar7 = puVar11[7];
      puVar13[6] = puVar11[6];
      puVar13[7] = uVar7;
      uVar7 = puVar11[9];
      puVar13[8] = puVar11[8];
      puVar13[9] = uVar7;
      uVar7 = puVar11[0xb];
      puVar13[10] = puVar11[10];
      puVar13[0xb] = uVar7;
      uVar4 = *(undefined4 *)((longlong)puVar11 + 100);
      uVar5 = *(undefined4 *)(puVar11 + 0xd);
      uVar6 = *(undefined4 *)((longlong)puVar11 + 0x6c);
      *(undefined4 *)(puVar13 + 0xc) = *(undefined4 *)(puVar11 + 0xc);
      *(undefined4 *)((longlong)puVar13 + 100) = uVar4;
      *(undefined4 *)(puVar13 + 0xd) = uVar5;
      *(undefined4 *)((longlong)puVar13 + 0x6c) = uVar6;
      puVar12 = puVar13 + 0x10;
      puVar1 = puVar11 + 0xe;
      uVar7 = puVar11[0xf];
      puVar11 = puVar11 + 0x10;
      puVar13[0xe] = *puVar1;
      puVar13[0xf] = uVar7;
      lVar10 = lVar10 + -1;
      puVar13 = puVar12;
    } while (lVar10 != 0);
    *(undefined4 *)puVar12 = *(undefined4 *)puVar11;
    *(undefined4 *)((longlong)_Dst + 0x404) = *(undefined4 *)(param_1 + 0x41c);
    *(undefined4 *)((longlong)_Dst + 0x60c) = *(undefined4 *)(param_1 + 0x628);
  }
  KeReleaseSpinLock(&AcdSpinLockG,param_3);
  IoReleaseCancelSpinLock(param_2);
  *(undefined4 *)(plVar8 + -0xf) = 0;
  plVar8[-0xe] = 0x618;
  IofCompleteRequest(plVar2,0);
  return;
}



===== AcdConnectionTimerWrapper @ 140002a70 =====

void AcdConnectionTimerWrapper(void)

{
  bool bVar1;
  uint uVar2;
  longlong *plVar3;
  uint uVar4;
  longlong *plVar5;
  
  bVar1 = false;
  KeAcquireSpinLockAtDpcLevel(&AcdSpinLockG);
  plVar3 = AcdConnectionQueueG;
  plVar5 = (longlong *)0x0;
  do {
    if ((longlong **)plVar3 == &AcdConnectionQueueG) {
LAB_140002ae7:
      KeReleaseSpinLockFromDpcLevel(&AcdSpinLockG);
      if (bVar1) {
        AcdSignalCompletionCommon(plVar5,0);
      }
      return;
    }
    plVar5 = plVar3;
    if (((char)plVar3[2] != '\0') && (*(char *)((longlong)plVar3 + 0x12) == '\0')) {
      uVar4 = *(int *)((longlong)plVar3 + 0x14) + 1;
      *(uint *)((longlong)plVar3 + 0x14) = uVar4;
      if (*(char *)((longlong)plVar3 + 0x11) == '\0') {
        uVar2 = (int)plVar3[3] + 1;
        *(uint *)(plVar3 + 3) = uVar2;
      }
      else {
        *(undefined4 *)(plVar3 + 3) = 0;
        uVar2 = 0;
      }
      if ((0xb3 < uVar4) || (0x27 < uVar2)) {
        bVar1 = true;
        *(undefined1 *)((longlong)plVar3 + 0x12) = 1;
        goto LAB_140002ae7;
      }
    }
    plVar3 = (longlong *)*plVar3;
  } while( true );
}



===== _guard_check_icall @ 140002b30 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 140002b50 =====

/* WARNING: Removing unreachable block (ram,0x000140002bba) */
/* WARNING: Removing unreachable block (ram,0x000140002b69) */
/* WARNING: Removing unreachable block (ram,0x000140002b5a) */

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



===== __security_check_cookie @ 140002c20 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002c60 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002c90 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002cc0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140002d20 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140002d63;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140002dd4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140002dd0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140002dd4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140002dcc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140002dd0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140002dcc;
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
LAB_140002dd4:
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
LAB_140002d63:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140002e40 =====

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



===== memset @ 140003140 =====

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



===== __memset_repmovs @ 140003280 =====

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



===== __memset_query @ 140003300 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003380 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400034c0 =====

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



===== __memset_spec_plain @ 140003540 =====

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



===== AcdCleanup @ 140009008 =====

undefined8 AcdCleanup(void)

{
  return 0;
}



===== AcdClose @ 140009014 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 AcdClose(void)

{
  _ulAcdOpenCountG = _ulAcdOpenCountG + -1;
  if (_ulAcdOpenCountG == 0) {
    AcdReset();
  }
  return 0;
}



===== AcdCreate @ 140009034 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 AcdCreate(void)

{
  _ulAcdOpenCountG = _ulAcdOpenCountG + 1;
  return 0;
}



===== AcdDispatchDeviceControl @ 140009044 =====

uint AcdDispatchDeviceControl(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar1 == 0xf14008) {
    uVar3 = AcdWaitForNotification(param_1,param_2);
    uVar2 = (uint)uVar3;
  }
  else if (iVar1 == 0xf1400c) {
    uVar2 = AcdConnectionInProgress(param_1,param_2);
  }
  else if (iVar1 == 0xf14014) {
    uVar3 = AcdConnectAddress(param_1,param_2);
    uVar2 = (uint)uVar3;
  }
  else {
    if (iVar1 == 0xf18000) {
      AcdReset();
      goto LAB_1400090ca;
    }
    if (iVar1 == 0xf18004) {
      uVar3 = AcdEnable(param_1,param_2);
      uVar2 = (uint)uVar3;
    }
    else if (iVar1 == 0xf18010) {
      uVar3 = AcdSignalCompletion(param_1,param_2);
      uVar2 = (uint)uVar3;
    }
    else {
      if (iVar1 != 0xf18018) {
        uVar2 = 0xc0000002;
        goto LAB_1400090ca;
      }
      uVar3 = AcdEnableAddress(param_1,param_2);
      uVar2 = (uint)uVar3;
    }
  }
  if (uVar2 == 0x103) {
    return 0x103;
  }
LAB_1400090ca:
  *(uint *)(param_1 + 0x30) = uVar2;
  IofCompleteRequest(param_1,0);
  return uVar2;
}



===== AcdDispatchInternalDeviceControl @ 1400090f4 =====

int AcdDispatchInternalDeviceControl(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  *(undefined8 *)(param_1 + 0x38) = 0;
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar1 == 0xf148d0) {
    uVar2 = AcdBind(param_1,param_2);
    iVar1 = (int)uVar2;
  }
  else if (iVar1 == 0xf148d4) {
    uVar2 = AcdUnbind(param_1,param_2);
    iVar1 = (int)uVar2;
  }
  else {
    if (iVar1 != 0xf148d8) {
      iVar1 = -0x3ffffffe;
      goto LAB_140009142;
    }
    uVar2 = AcdQueryState(param_1,param_2);
    iVar1 = (int)uVar2;
  }
  if (iVar1 == 0x103) {
    return 0x103;
  }
LAB_140009142:
  *(int *)(param_1 + 0x30) = iVar1;
  IofCompleteRequest(param_1,0);
  return iVar1;
}



===== AcdUnload @ 140009170 =====

void AcdUnload(void)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  AcdStopThread = 1;
  KeSetEvent(&AcdRequestThreadEventG,0,0);
  local_18 = 0;
  KeWaitForSingleObject(NotificationThread,0,0,0);
  ObfDereferenceObject(NotificationThread);
  ZwClose(hSignalNotificationThreadG);
  IoDeleteDevice(pAcdDeviceObjectG);
  if (TcpCcbRegistrationHandle != 0) {
    ExUnregisterCallback();
  }
  ObfDereferenceObject(TcpCcbObject);
  puVar5 = auStack_38;
  if (pDisabledAddressesG != (longlong *)0x0) {
    while( true ) {
      plVar4 = pDisabledAddressesG;
      plVar1 = (longlong *)*pDisabledAddressesG;
      if (plVar1 == pDisabledAddressesG) break;
      if (((longlong *)plVar1[1] != pDisabledAddressesG) ||
         (lVar2 = *plVar1, (longlong *)*(longlong *)(lVar2 + 8) != plVar1)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        puVar5 = auStack_30;
        break;
      }
      *pDisabledAddressesG = lVar2;
      *(longlong **)(lVar2 + 8) = plVar4;
      ExFreePoolWithTag(plVar1);
    }
    *(undefined8 *)(puVar5 + -8) = 0x14000926a;
    ExFreePoolWithTag();
    pDisabledAddressesG = (longlong *)0x0;
  }
  return;
}



===== entry @ 14000a010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000a044 =====

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



===== DriverEntry @ 14000a078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DriverEntry(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  code *pcVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int local_res18 [4];
  undefined8 in_stack_ffffffffffffff08;
  uint uVar6;
  ulonglong in_stack_ffffffffffffff10;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  ulonglong uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  int *local_60;
  undefined4 local_58;
  
  uVar6 = (uint)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);
  local_b8 = 0;
  uStack_b0 = uStack_b0 & 0xffffffff00000000;
  local_a8 = 0;
  uStack_a0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = (undefined8 *)0x0;
  uStack_c0 = 0;
  local_88 = 0;
  uStack_80 = 0;
  KeInitializeSpinLock(&AcdSpinLockG);
  lOutstandingRequestsG = 0;
  DAT_140006168 = &AcdNotificationQueueG;
  AcdNotificationQueueG = &AcdNotificationQueueG;
  DAT_140006178 = &AcdCompletionQueueG;
  AcdCompletionQueueG = &AcdCompletionQueueG;
  DAT_140006158 = &AcdConnectionQueueG;
  AcdConnectionQueueG = &AcdConnectionQueueG;
  DAT_140006108 = &AcdDriverListG;
  AcdDriverListG = &AcdDriverListG;
  RtlInitUnicodeString(&local_a8,L"\\Device\\RasAcd");
  iVar2 = IoCreateDevice(param_1,0,&local_a8,0xf1,(ulonglong)uVar6 << 0x20,
                         in_stack_ffffffffffffff10 & 0xffffffffffffff00,&pAcdDeviceObjectG);
  if (iVar2 < 0) {
    DbgPrint("AcdDriverEntry: IoCreateDevice failed (status=0x%x)\n",iVar2);
  }
  else {
    *(code **)(param_1 + 0x68) = AcdUnload;
    puVar4 = (undefined8 *)(param_1 + 0x70);
    for (lVar5 = 0x1b; lVar5 != 0; lVar5 = lVar5 + -1) {
      *puVar4 = AcdDispatch;
      puVar4 = puVar4 + 1;
    }
    *(undefined8 *)(param_1 + 0x50) = 0;
    IoInitializeTimer(pAcdDeviceObjectG,AcdConnectionTimerWrapper,0);
    local_res18[0] = 0;
    memset(local_78,0,0x70);
    local_70 = 0x120;
    local_68 = L"EnableRedirNotifications";
    local_60 = local_res18;
    local_58 = 0x4000000;
    local_98 = 0;
    uStack_90 = 0;
    RtlInitUnicodeString(&local_98,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(&local_98);
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    iVar2 = (*pcVar3)(1,L"RasAcd\\Parameters",local_78,0,0);
    if ((iVar2 == 0) && (local_res18[0] != 0)) {
      fAcdEnableRedirNotifs = 1;
    }
    KeInitializeEvent(&AcdRequestThreadEventG,0,0);
    iVar2 = PsCreateSystemThread
                      (&hSignalNotificationThreadG,0x1fffff,0,0,0,AcdNotificationRequestThread,0);
    if (iVar2 < 0) {
      DbgPrint("AcdDriverEntry: PsCreateSystemThread failed (status=0x%x)\n",iVar2);
    }
    else {
      pDisabledAddressesG = (undefined8 *)ExAllocatePool2(0x40,0x18,0x4e646341);
      if (pDisabledAddressesG != (undefined8 *)0x0) {
        puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x418,0x4e646341);
        if (puVar4 == (undefined8 *)0x0) {
          IoDeleteDevice(pAcdDeviceObjectG);
          ExFreePoolWithTag(pDisabledAddressesG,0);
          return -0x3fffff66;
        }
        RtlInitUnicodeString(&local_88,L"\\Callback\\TcpConnectionCallbackTemp");
        uStack_d0 = 0;
        local_c8 = &local_88;
        local_d8 = CONCAT44(local_d8._4_4_,0x30);
        uStack_c0 = CONCAT44(uStack_c0._4_4_,0x50);
        local_b8 = 0;
        uStack_b0 = 0;
        iVar2 = ExCreateCallback(&TcpCcbObject,&local_d8,1);
        if (iVar2 < 0) {
          IoDeleteDevice(pAcdDeviceObjectG);
          ExFreePoolWithTag(pDisabledAddressesG,0);
          ExFreePoolWithTag(puVar4,0);
          return iVar2;
        }
        KeInitializeSpinLock(&TcpCcbLock);
        puVar1 = pDisabledAddressesG;
        *pDisabledAddressesG = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        memset(puVar4 + 2,0,0x408);
        *puVar4 = puVar1;
        puVar4[1] = puVar1;
        *puVar1 = puVar4;
        puVar1[1] = puVar4;
        *(undefined4 *)(puVar1 + 2) = 1;
        *(undefined4 *)((longlong)puVar1 + 0x14) = 10;
        ObReferenceObjectByHandle(hSignalNotificationThreadG,0,0,0,&NotificationThread,0);
        return 0;
      }
      iVar2 = -0x3fffff66;
      pDisabledAddressesG = (undefined8 *)0x0;
    }
    IoDeleteDevice(pAcdDeviceObjectG);
  }
  return iVar2;
}


