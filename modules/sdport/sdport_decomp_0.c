
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



===== RtlStringCbPrintfW @ 1c0001020 =====

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



===== SdhostInitializeMiniportConfigInfo @ 1c000109c =====

void SdhostInitializeMiniportConfigInfo(longlong param_1)

{
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined8 *)(param_1 + 0xe0) = 0;
  *(undefined8 *)(param_1 + 200) = *(undefined8 *)(param_1 + 8);
  if ((*(longlong *)(param_1 + 0x130) != 0x4942001ad7b46895) ||
     (*(longlong *)(param_1 + 0x138) != 0x43a81066d4a71f89)) {
    if ((*(longlong *)(param_1 + 0x130) == 0x11d0b510c8ebdfb0) &&
       (*(longlong *)(param_1 + 0x138) == -0x1cbdda365fff1a80)) {
      *(undefined4 *)(param_1 + 0xd0) = 1;
      *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0x1a0);
      *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0x1a4);
      *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0x1a8);
      *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0x1ac);
      return;
    }
    *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;
  }
  return;
}



===== SdhostInternalDeviceControl @ 1c0001150 =====

ulonglong SdhostInternalDeviceControl(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  if (**(int **)(param_1 + 0x40) == 2) {
    uVar1 = SdhostPdoInternalDeviceControl(param_1,param_2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== SdhostInitializeDbgLog @ 1c0001174 =====

void SdhostInitializeDbgLog(longlong param_1)

{
  memset((void *)(param_1 + 0xde8),0,0x1000);
  *(undefined4 *)(param_1 + 0xdc8) = 0;
  *(undefined8 *)(param_1 + 0xdd8) = 0;
  *(void **)(param_1 + 0xdd0) = (void *)(param_1 + 0xde8);
  *(longlong *)(param_1 + 0xde0) = param_1 + 0x1dc8;
  *(undefined4 *)(param_1 + 0xdcc) = 0x7f;
  return;
}



===== SdhostInitializePoFxDbgLog @ 1c00011d8 =====

void SdhostInitializePoFxDbgLog(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x1b0) != 0) {
    memset((void *)(param_1 + 0x368),0,0x1000);
    *(undefined4 *)(param_1 + 0x348) = 0;
    *(undefined8 *)(param_1 + 0x358) = 0;
    *(longlong *)(param_1 + 0x360) = param_1 + 0x1348;
    *(undefined4 *)(param_1 + 0x34c) = 0x7f;
    *(void **)(param_1 + 0x350) = (void *)(param_1 + 0x368);
  }
  return;
}



===== SdhostPoFxAddDbgLog @ 1c0001248 =====

void SdhostPoFxAddDbgLog(longlong param_1,uint param_2,ulonglong param_3,ulonglong param_4,
                        ulonglong param_5)

{
  int *piVar1;
  int iVar2;
  ulonglong *puVar3;
  
  if (*(longlong *)(param_1 + 0x1b0) != 0) {
    LOCK();
    piVar1 = (int *)(param_1 + 0x348);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    puVar3 = (ulonglong *)
             ((ulonglong)(*(uint *)(param_1 + 0x34c) & iVar2 - 1U) * 0x20 +
             *(longlong *)(param_1 + 0x350));
    *(ulonglong **)(param_1 + 0x358) = puVar3;
    puVar3[1] = param_3;
    puVar3[3] = param_5;
    *puVar3 = (ulonglong)
              ((param_2 & 0xff00 | param_2 << 0x10) << 8 |
              (param_2 & 0xff0000 | param_2 >> 0x10) >> 8);
    puVar3[2] = param_4;
  }
  return;
}



===== SdPortCompleteRequest @ 1c00012d0 =====

void SdPortCompleteRequest(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  
                    /* 0x12d0  2  SdPortCompleteRequest */
  lVar1 = *(longlong *)(param_1 + 0xb8);
  *(undefined4 *)(param_1 + 100) = param_2;
  if (*(char *)(lVar1 + 0xb38) == '\0') {
    KeCancelTimer(param_1 + 0xd8);
  }
  KeInsertQueueDpc(lVar1 + 0xbf0,param_1,0);
  return;
}



===== SdPortGetPciConfigSpace @ 1c0001330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint SdPortGetPciConfigSpace(longlong param_1,undefined1 param_2,undefined8 param_3,int param_4)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  
                    /* 0x1330  3  SdPortGetPciConfigSpace */
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x40);
  uVar4 = 0;
  pcVar2 = *(code **)(lVar1 + 0x198);
  if (pcVar2 != (code *)0x0) {
    iVar3 = (*pcVar2)(*(undefined8 *)(lVar1 + 0x168),0,param_3,param_2,param_4);
    uVar4 = -(uint)(iVar3 != param_4) & 0xc0000001;
  }
  return uVar4;
}



===== SdPortPoFxPowerControl @ 1c0001380 =====

void SdPortPoFxPowerControl
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined8 *puVar1;
  longlong *plVar2;
  
                    /* 0x1380  5  SdPortPoFxPowerControl */
  plVar2 = (longlong *)0x0;
  ExAcquireFastMutex(&TableListMutex);
  for (puVar1 = PrivateExtensionTableList;
      ((undefined8 **)puVar1 != &PrivateExtensionTableList &&
      (plVar2 = puVar1 + -2, puVar1[-1] != param_1)); puVar1 = (undefined8 *)*puVar1) {
  }
  ExReleaseFastMutex(&TableListMutex);
  PoFxPowerControl(*(undefined8 *)(*(longlong *)(*plVar2 + 8) + 0x1b0),param_2,param_3,param_4,
                   param_5,param_6,param_7);
  return;
}



===== SdPortReadRegisterBufferUchar @ 1c0001460 =====

void SdPortReadRegisterBufferUchar(longlong param_1,uint param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  
                    /* 0x1460  6  SdPortReadRegisterBufferUchar */
  if (param_1 != 0) {
    puVar2 = (undefined1 *)((ulonglong)param_2 + param_1);
    for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_3 = *puVar2;
      puVar2 = puVar2 + 1;
      param_3 = param_3 + 1;
    }
  }
  return;
}



===== SdPortReadRegisterBufferUlong @ 1c00014a0 =====

void SdPortReadRegisterBufferUlong(longlong param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  
                    /* 0x14a0  7  SdPortReadRegisterBufferUlong */
  if (param_1 != 0) {
    puVar2 = (undefined4 *)((ulonglong)param_2 + param_1);
    for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_3 = *puVar2;
      puVar2 = puVar2 + 1;
      param_3 = param_3 + 1;
    }
  }
  return;
}



===== SdPortReadRegisterBufferUshort @ 1c00014e0 =====

void SdPortReadRegisterBufferUshort(longlong param_1,uint param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined2 *puVar2;
  
                    /* 0x14e0  8  SdPortReadRegisterBufferUshort */
  if (param_1 != 0) {
    puVar2 = (undefined2 *)((ulonglong)param_2 + param_1);
    for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_3 = *puVar2;
      puVar2 = puVar2 + 1;
      param_3 = param_3 + 1;
    }
  }
  return;
}



===== SdPortReadRegisterUchar @ 1c0001520 =====

undefined1 SdPortReadRegisterUchar(longlong param_1,uint param_2)

{
                    /* 0x1520  9  SdPortReadRegisterUchar */
  if (param_1 == 0) {
    return 0xff;
  }
  return *(undefined1 *)((ulonglong)param_2 + param_1);
}



===== SdPortReadRegisterUlong @ 1c0001540 =====

undefined4 SdPortReadRegisterUlong(longlong param_1,uint param_2)

{
                    /* 0x1540  10  SdPortReadRegisterUlong */
  if (param_1 == 0) {
    return 0xffbadbad;
  }
  return *(undefined4 *)((ulonglong)param_2 + param_1);
}



===== SdPortReadRegisterUshort @ 1c0001560 =====

undefined2 SdPortReadRegisterUshort(longlong param_1,uint param_2)

{
                    /* 0x1560  11  SdPortReadRegisterUshort */
  if (param_1 == 0) {
    return 0xfbad;
  }
  return *(undefined2 *)((ulonglong)param_2 + param_1);
}



===== SdPortSetPciConfigSpace @ 1c0001580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint SdPortSetPciConfigSpace(longlong param_1,undefined1 param_2,undefined8 param_3,uint param_4)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  
                    /* 0x1580  12  SdPortSetPciConfigSpace */
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x40);
  pcVar2 = *(code **)(lVar1 + 400);
  if (pcVar2 == (code *)0x0) {
    uVar3 = 0xc00000bb;
  }
  else {
    uVar3 = (*pcVar2)(*(undefined8 *)(lVar1 + 0x168),0,param_3,param_2,param_4);
    uVar3 = -(uint)(uVar3 < param_4) & 0xc0000001;
  }
  return uVar3;
}



===== SdPortWait @ 1c00015d0 =====

void SdPortWait(uint param_1)

{
                    /* 0x15d0  13  SdPortWait */
  SdhostWait(param_1);
  return;
}



===== SdPortWriteRegisterBufferUchar @ 1c00015f0 =====

void SdPortWriteRegisterBufferUchar(longlong param_1,uint param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  
                    /* 0x15f0  14  SdPortWriteRegisterBufferUchar */
  if (param_1 != 0) {
    puVar2 = (undefined1 *)((ulonglong)param_2 + param_1);
    for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = *param_3;
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 1;
    }
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdPortWriteRegisterBufferUlong @ 1c0001630 =====

void SdPortWriteRegisterBufferUlong(longlong param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  
                    /* 0x1630  15  SdPortWriteRegisterBufferUlong */
  if (param_1 != 0) {
    puVar2 = (undefined4 *)((ulonglong)param_2 + param_1);
    for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = *param_3;
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 1;
    }
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdPortWriteRegisterBufferUshort @ 1c0001670 =====

void SdPortWriteRegisterBufferUshort(longlong param_1,uint param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined2 *puVar2;
  
                    /* 0x1670  16  SdPortWriteRegisterBufferUshort */
  if (param_1 != 0) {
    puVar2 = (undefined2 *)((ulonglong)param_2 + param_1);
    for (uVar1 = (ulonglong)param_4; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = *param_3;
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 1;
    }
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdPortWriteRegisterUchar @ 1c00016b0 =====

void SdPortWriteRegisterUchar(longlong param_1,uint param_2,undefined1 param_3)

{
                    /* 0x16b0  17  SdPortWriteRegisterUchar */
  if (param_1 != 0) {
    *(undefined1 *)((ulonglong)param_2 + param_1) = param_3;
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdPortWriteRegisterUlong @ 1c00016d0 =====

void SdPortWriteRegisterUlong(longlong param_1,uint param_2,undefined4 param_3)

{
                    /* 0x16d0  18  SdPortWriteRegisterUlong */
  if (param_1 != 0) {
    *(undefined4 *)((ulonglong)param_2 + param_1) = param_3;
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdPortWriteRegisterUshort @ 1c00016f0 =====

void SdPortWriteRegisterUshort(longlong param_1,uint param_2,undefined2 param_3)

{
                    /* 0x16f0  19  SdPortWriteRegisterUshort */
  if (param_1 != 0) {
    *(undefined2 *)((ulonglong)param_2 + param_1) = param_3;
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdhostAllocateRequest @ 1c000170c =====

longlong * SdhostAllocateRequest(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)(param_1 + 0xbc8);
  plVar3 = (longlong *)*plVar4;
  if (((longlong *)plVar3[1] == plVar4) && (lVar1 = *plVar3, *(longlong **)(lVar1 + 8) == plVar3)) {
    *plVar4 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar4;
    return plVar3 + -0xd;
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  plVar3 = (longlong *)(*pcVar2)();
  return plVar3;
}



===== SdhostAllocateRequestSynchronous @ 1c0001740 =====

void SdhostAllocateRequestSynchronous(longlong param_1)

{
  SdhostDisableIrpQueue(param_1);
  KeWaitForSingleObject(param_1 + 0xbb0,0,0,0,0);
  SdhostAllocateRequest(param_1);
  return;
}



===== SdhostBasicCommandSelect @ 1c0001790 =====

ulonglong SdhostBasicCommandSelect(longlong param_1,int *param_2,longlong param_3)

{
  longlong lVar1;
  byte bVar2;
  ulonglong uVar3;
  byte local_68 [8];
  int local_60;
  int local_5c;
  
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  memset(local_68,0,0x55);
  lVar1 = *(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x20);
  SdhostConvertSdcmdToCommand((undefined1 *)(lVar1 + 0x40),local_68);
  if (local_5c == 1) {
LAB_1c000181c:
    bVar2 = 0;
  }
  else {
    if ((local_5c != 2) && (local_5c != 3)) {
      if (local_5c == 4) {
        bVar2 = 0x10;
        goto LAB_1c000181f;
      }
      if ((((local_5c != 5) && (local_5c != 6)) && (local_5c != 7)) &&
         ((local_5c != 8 && (local_5c != 9)))) goto LAB_1c000181c;
    }
    bVar2 = 4;
  }
LAB_1c000181f:
  *(byte *)(lVar1 + 0x38) = bVar2;
  memcpy((void *)(lVar1 + 0x28),param_2 + 0x1e,(ulonglong)bVar2);
  if (local_60 == 1) {
    bVar2 = (&SdCmdFlags)[local_68[0]];
  }
  else {
    bVar2 = (&SdAppCmdFlags)[local_68[0]];
  }
  if ((bVar2 & 8) == 0) {
    param_2[0x26] = 0;
    param_2[0x27] = 0;
    SdhostCompleteRequestPostError(param_2);
    uVar3 = (ulonglong)(uint)param_2[0x19];
  }
  else {
    uVar3 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSelect,*(int *)(param_1 + 0xb48),0,
                               0,0,param_3,0,0);
  }
  return uVar3;
}



===== SdhostBasicCommandSend @ 1c00018e0 =====

void SdhostBasicCommandSend(longlong param_1,int *param_2,longlong param_3)

{
  if (*(int *)(*(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x20) + 0x44) == 1) {
    SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSd,
                       *(int *)(*(longlong *)(param_2 + 0x2e) + 0xb48),0,0,0,param_3,
                       SdhostBasicCommandSendAfterApp,0);
  }
  else {
    SdhostBasicCommandSendAfterApp(param_1,param_2,param_3);
  }
  return;
}



===== SdhostBasicCommandSendAfterApp @ 1c0001950 =====

void SdhostBasicCommandSendAfterApp(longlong param_1,int *param_2,longlong param_3)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  byte local_68 [8];
  int local_60;
  
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  memset(local_68,0,0x55);
  lVar1 = *(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x20);
  SdhostConvertSdcmdToCommand((undefined1 *)(lVar1 + 0x40),local_68);
  if (local_60 == 1) {
    bVar2 = (&SdCmdFlags)[local_68[0]];
  }
  else {
    bVar2 = (&SdAppCmdFlags)[local_68[0]];
  }
  iVar3 = *(int *)(lVar1 + 0x54);
  if ((bVar2 & 0x10) != 0) {
    iVar3 = *(int *)(param_1 + 0xb48);
  }
  SdhostIssueCommand(param_1,param_2,(undefined8 *)local_68,iVar3,0,0,0,param_3,
                     SdhostBasicCommandSelect,0);
  return;
}



===== SdhostBuildBasicCommand @ 1c0001a2c =====

void SdhostBuildBasicCommand(longlong param_1,int *param_2,longlong param_3)

{
  byte bVar1;
  byte local_68 [8];
  int local_60;
  
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  memset(local_68,0,0x55);
  SdhostConvertSdcmdToCommand
            ((undefined1 *)(*(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x20) + 0x40),local_68);
  if (local_60 == 1) {
    bVar1 = (&SdCmdFlags)[local_68[0]];
  }
  else {
    bVar1 = (&SdAppCmdFlags)[local_68[0]];
  }
  if ((bVar1 & 8) == 0) {
    SdhostBasicCommandSend(param_1,param_2,param_3);
  }
  else {
    SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdDeselect,0,0,0,0,param_3,
                       SdhostBasicCommandSend,0);
  }
  return;
}



===== SdhostBuildCommand @ 1c0001b08 =====

void SdhostBuildCommand(longlong param_1,int *param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  uVar3 = KeQueryPerformanceCounter(0);
  *(ulonglong *)(param_2 + 0x2a) = uVar3;
  LOCK();
  piVar1 = (int *)(param_1 + 0xdc8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  puVar4 = (undefined8 *)
           ((ulonglong)(*(uint *)(param_1 + 0xdcc) & iVar2 - 1U) * 0x20 +
           *(longlong *)(param_1 + 0xdd0));
  *(undefined8 **)(param_1 + 0xdd8) = puVar4;
  *puVar4 = 0x65526649;
  puVar4[1] = param_3;
  puVar4[2] = param_2;
  puVar4[3] = uVar3 & 0xffffffff;
  if (*(int *)(*(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x20) + 0x4c) == 1) {
    SdhostBuildBasicCommand(param_1,param_2,param_3);
  }
  else {
    SdhostBuildDataCommand(param_1,param_2,param_3);
  }
  return;
}



===== SdhostBuildDataCommand @ 1c0001bb0 =====

void SdhostBuildDataCommand(longlong param_1,int *param_2,longlong param_3)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  
  bVar3 = true;
  lVar1 = *(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x20);
  if (((*(uint *)(param_1 + 0xb24) >> 0x15 & 1) == 0) &&
     ((*(char *)(param_1 + 0x114) == '\0' || ((*(uint *)(param_1 + 0xb24) >> 0x16 & 1) == 0)))) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((*(char *)(lVar1 + 0x40) == '5') || (*(int *)(lVar1 + 0x4c) != 3)) {
    bVar3 = false;
  }
  if ((bVar2) || (!bVar3)) {
    SdhostBuildDataCommandAfterBlockCount(param_1,param_2,param_3);
  }
  else {
    SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSetBlockCount,
                       *(uint *)(lVar1 + 0x60) /
                       (uint)*(ushort *)
                              (param_1 + 0xb7a +
                              (ulonglong)
                              *(byte *)(*(longlong *)
                                         (*(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x28) + 0x40
                                         ) + 0xb0) * 2) & 0xffff,0,0,0,param_3,
                       SdhostBuildDataCommandAfterBlockCount,0);
  }
  return;
}



===== SdhostBuildDataCommandAfterBlockCount @ 1c0001c90 =====

void SdhostBuildDataCommandAfterBlockCount(longlong param_1,int *param_2,longlong param_3)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  byte local_78 [8];
  int local_70;
  
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  memset(local_78,0,0x55);
  lVar3 = *(longlong *)(param_3 + 0xb8);
  lVar4 = *(longlong *)(lVar3 + 0x20);
  SdhostConvertSdcmdToCommand((undefined1 *)(lVar4 + 0x40),local_78);
  if (local_70 == 1) {
    bVar1 = (&SdCmdFlags)[local_78[0]];
  }
  else {
    bVar1 = (&SdAppCmdFlags)[local_78[0]];
  }
  uVar7 = *(uint *)(lVar4 + 0x54);
  if ((bVar1 & 0x10) != 0) {
    uVar7 = *(uint *)(param_1 + 0xb48);
  }
  uVar2 = *(uint *)(lVar4 + 0x60);
  uVar6 = *(ushort *)
           (param_1 + 0xb7a +
           (ulonglong)*(byte *)(*(longlong *)(*(longlong *)(lVar3 + 0x28) + 0x40) + 0xb0) * 2);
  uVar5 = (ushort)((ulonglong)uVar2 / (ulonglong)uVar6);
  uVar8 = (uint)((ulonglong)uVar2 / (ulonglong)uVar6);
  if (local_78[0] == 0x35) {
    if ((uVar7 >> 0x1b & 1) == 0) {
      uVar6 = *(ushort *)(lVar4 + 0x60);
      uVar5 = 1;
      uVar7 = -(uint)(uVar2 < 0x200) & uVar2 & 0x1ff | uVar7 & 0xf7fffe00;
    }
    else {
      if (uVar2 < uVar6) {
        uVar8 = 1;
      }
      uVar5 = (ushort)uVar8 + 1;
      if (uVar2 <= (uVar8 & 0xffff) * (uint)uVar6) {
        uVar5 = (ushort)uVar8;
      }
      uVar7 = uVar7 ^ (uVar5 ^ uVar7) & 0x1ff;
    }
  }
  SdhostIssueCommand(param_1,param_2,(undefined8 *)local_78,uVar7,uVar6,uVar5,
                     *(longlong *)(lVar4 + 0x58),param_3,SdhostBuildDataCommandComplete,0);
  return;
}



===== SdhostBuildDataCommandComplete @ 1c0001e20 =====

int SdhostBuildDataCommandComplete(undefined8 param_1,int *param_2,longlong param_3)

{
  longlong lVar1;
  byte bVar2;
  undefined1 local_68;
  undefined2 local_67;
  undefined1 local_65;
  int local_5c;
  
  local_67 = 0;
  local_65 = 0;
  memset(&local_68,0,0x55);
  lVar1 = *(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x20);
  SdhostConvertSdcmdToCommand((undefined1 *)(lVar1 + 0x40),&local_68);
  if (local_5c == 1) {
LAB_1c0001e98:
    bVar2 = 0;
  }
  else {
    if ((local_5c != 2) && (local_5c != 3)) {
      if (local_5c == 4) {
        bVar2 = 0x10;
        goto LAB_1c0001e9a;
      }
      if ((((local_5c != 5) && (local_5c != 6)) && (local_5c != 7)) &&
         ((local_5c != 8 && (local_5c != 9)))) goto LAB_1c0001e98;
    }
    bVar2 = 4;
  }
LAB_1c0001e9a:
  *(byte *)(lVar1 + 0x38) = bVar2;
  memcpy((void *)(lVar1 + 0x28),param_2 + 0x1e,(ulonglong)bVar2);
  param_2[0x26] = 0;
  param_2[0x27] = 0;
  SdhostCompleteRequestPostError(param_2);
  return param_2[0x19];
}



===== SdhostBuildTransfer @ 1c0001ee4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdhostBuildTransfer(longlong param_1,int *param_2,longlong param_3,longlong param_4,
                       undefined1 param_5)

{
  uint *puVar1;
  uint uVar2;
  undefined1 uVar3;
  byte bVar4;
  int iVar5;
  longlong lVar6;
  char cVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  bool bVar12;
  int local_res18 [4];
  ulonglong in_stack_ffffffffffffff98;
  undefined4 uVar13;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar14;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  local_res18[0] = 0;
  if (param_3 == 0) {
LAB_1c0002226:
    iVar5 = 0x103;
  }
  else {
    *(longlong *)(param_2 + 0x28) = param_4;
    *(longlong *)(param_2 + 0x5c) = param_3;
    param_2[0x5a] = 0;
    param_2[0x5b] = 0;
    *(ulonglong *)(param_2 + 0xe) =
         (ulonglong)*(uint *)(param_3 + 0x2c) + *(longlong *)(param_3 + 0x20);
    param_2[0x10] = 0;
    param_2[0x11] = 0;
    param_2[0x12] = 0;
    param_2[0x13] = 0;
    param_2[0x14] = 0;
    param_2[0x15] = 0;
    param_2[0x16] = 0;
    if ((*(char *)(param_1 + 0x114) == '\0') ||
       (cVar7 = '\x01', (*(uint *)(param_1 + 0xb24) & 0x400000) == 0)) {
      cVar7 = '\0';
    }
    *(char *)((longlong)param_2 + 0x29) = cVar7;
    if (((*(uint *)(param_1 + 0xb24) & 0x200000) == 0) || (uVar3 = 1, cVar7 != '\0')) {
      uVar3 = 0;
    }
    *(undefined1 *)(param_2 + 10) = uVar3;
    if ((char)param_2[2] == '5') {
      uVar8 = *(uint *)(*(longlong *)(*(longlong *)(param_4 + 0xb8) + 0x20) + 0x60);
    }
    else {
      uVar8 = (uint)*(ushort *)(param_2 + 0xb) * (uint)*(ushort *)((longlong)param_2 + 0x2a);
    }
    uVar9 = (ulonglong)uVar8;
    param_2[0xc] = uVar8;
    puVar1 = (uint *)(param_2 + 8);
    uVar2 = *(uint *)(param_1 + 0xb4c);
    uVar10 = (ulonglong)uVar2;
    *puVar1 = uVar2;
    uVar11 = (ulonglong)uVar2;
    if (*(uint *)(param_1 + 0xb20) < uVar8) {
LAB_1c0001fcf:
      if (uVar2 != 2) goto LAB_1c0002027;
      *(undefined8 *)(param_2 + 0x5a) = *(undefined8 *)(param_1 + 0xab0);
      *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(param_1 + 0xad0);
      *(undefined8 *)(param_2 + 0x12) = *(undefined8 *)(param_1 + 0xac8);
      *(undefined8 *)(param_2 + 0x14) = *(undefined8 *)(param_1 + 0xae0);
      param_2[0x16] = *(int *)(param_1 + 0xae8);
    }
    else {
      if (param_2[7] == 1) {
        uVar8 = *(uint *)(param_1 + 0xb2c) & 1;
      }
      else {
        if (param_2[7] != 2) goto LAB_1c0001fcf;
        uVar8 = *(uint *)(param_1 + 0xb2c) & 2;
      }
      if (uVar8 == 0) goto LAB_1c0001fcf;
      *puVar1 = 1;
LAB_1c0002027:
      *puVar1 = 1;
      if ((*(byte *)(param_3 + 10) & 5) == 0) {
        uVar11 = 0;
        uVar9 = 0;
        in_stack_ffffffffffffff98 = in_stack_ffffffffffffff98 & 0xffffffff00000000;
        uVar10 = 1;
        lVar6 = MmMapLockedPagesSpecifyCache(param_3);
      }
      else {
        lVar6 = *(longlong *)(param_3 + 0x18);
      }
      *(longlong *)(param_2 + 0xe) = lVar6;
      if (lVar6 == 0) {
        param_2[0x19] = -0x3fffff66;
        SdhostCompleteRequest((short *)param_2,uVar9,uVar10,uVar11);
        if (param_2[0x19] < 0) goto LAB_1c0002226;
      }
    }
    uVar13 = (undefined4)(in_stack_ffffffffffffff98 >> 0x20);
    *(undefined1 *)(param_2 + 0x23) = param_5;
    if (*puVar1 == 2) {
      if (*(char *)(param_1 + 0xb38) == '\0') {
        bVar4 = KeGetCurrentIrql();
        bVar12 = bVar4 < 2;
        if (bVar12) {
          bVar4 = KfRaiseIrql(2);
        }
        iVar5 = (**(code **)(*(longlong *)(*(longlong *)(param_2 + 0x5a) + 8) + 0x70))
                          (*(longlong *)(param_2 + 0x5a),
                           *(undefined8 *)(*(longlong *)(param_1 + 8) + 0xa8),
                           *(undefined8 *)(param_2 + 0x5c),*(undefined8 *)(param_2 + 0xe),
                           CONCAT44(uVar13,param_2[0xc]),SdhostSendDataCommand,param_2,
                           param_2[7] == 2,*(undefined8 *)(param_2 + 0x14),
                           CONCAT44(uVar14,param_2[0x16]));
        if (bVar12) {
          KeLowerIrql(bVar4);
        }
        if (iVar5 < 0) {
          return iVar5;
        }
        if ((char)param_2[0x23] == '\0') goto LAB_1c0002226;
        KeWaitForSingleObject(param_2 + 0x30,0,0,0,0);
        KeClearEvent(param_2 + 0x30);
      }
      else {
        local_res18[0] = param_2[0xc];
        (**(code **)(*(longlong *)(*(longlong *)(param_2 + 0x5a) + 8) + 0xb8))
                  (*(longlong *)(param_2 + 0x5a),*(undefined8 *)(param_2 + 0x5c),
                   *(undefined8 *)(param_1 + 0xb00),0,in_stack_ffffffffffffff98 & 0xffffffff00000000
                   ,local_res18,param_2[7] == 2,*(undefined8 *)(param_1 + 0xae0),
                   *(undefined4 *)(param_1 + 0xae8),0,0);
      }
    }
    iVar5 = SdhostIssueRequest(*(longlong *)(param_2 + 0x2e),param_2,*(longlong *)(param_2 + 0x28),
                               (char)param_2[0x23]);
  }
  return iVar5;
}



===== SdhostCompleteRequest @ 1c000224c =====

void SdhostCompleteRequest(short *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 local_res8;
  
  local_res8 = 0;
  if (((*(int *)(param_1 + 0x32) + 0x80000000U & 0x80000000) == 0) &&
     (*(int *)(param_1 + 0x32) != -0x3fffffea)) {
    lVar1 = *(longlong *)(param_1 + 0x5c);
    LOCK();
    bVar4 = *(int *)(param_1 + 0x58) == 0;
    if (bVar4) {
      *(int *)(param_1 + 0x58) = 1;
    }
    UNLOCK();
    if (bVar4) {
      uVar3 = *(undefined8 *)(param_1 + 0x50);
      *(int *)(lVar1 + 0x1e10) = *(int *)(lVar1 + 0x1e10) + 1;
      *(undefined8 *)(lVar1 + 0x1e18) = uVar3;
      *(undefined4 *)(lVar1 + 0x1e20) = *(undefined4 *)(param_1 + 0x32);
      uVar3 = KeQueryInterruptTimePrecise(&local_res8);
      *(undefined8 *)(lVar1 + 0x1e28) = uVar3;
      lVar2 = *(longlong *)(*(longlong *)(lVar1 + 8) + 8);
      if (*(char *)(lVar1 + 0xb38) == '\0') {
        SdhostQueueWorkItem(lVar2,*(longlong *)(param_1 + 0xb0),SdhostErrorRecoveryWorker,param_4,
                            param_1,'\0');
        return;
      }
      SdhostErrorRecoveryWorker(lVar2,(longlong)param_1);
    }
  }
  SdhostCompleteRequestPostError((int *)param_1);
  return;
}



===== SdhostCompleteRequestPostError @ 1c0002324 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostCompleteRequestPostError(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined8 local_res8;
  
  local_res8 = 0;
  lVar6 = *(longlong *)(param_1 + 0x2e);
  uVar3 = param_1[0x2a];
  iVar4 = param_1[0x19];
  uVar5 = param_1[0x1e];
  LOCK();
  piVar1 = (int *)(lVar6 + 0xdc8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  puVar10 = (undefined8 *)
            ((ulonglong)(iVar2 - 1U & *(uint *)(lVar6 + 0xdcc)) * 0x20 +
            *(longlong *)(lVar6 + 0xdd0));
  *(undefined8 **)(lVar6 + 0xdd8) = puVar10;
  puVar10[1] = (ulonglong)uVar5;
  *puVar10 = 0x70436552;
  puVar10[2] = (longlong)iVar4;
  puVar10[3] = (ulonglong)uVar3;
  LOCK();
  param_1[0x2c] = 0;
  UNLOCK();
  if (((param_1[0x19] + 0x80000000U & 0x80000000) != 0) || (param_1[0x19] == -0x3fffffea)) {
    if (*param_1 - 1U < 2) {
      (**(code **)(*(longlong *)(*(longlong *)(lVar6 + 8) + 0xc0) + 0x28))
                (*(undefined8 *)(lVar6 + 0xa88),param_1 + 2,param_1 + 0x1e);
    }
    if (param_1[0x19] == -0x3fffffea) {
      SdhostIssueRequest(lVar6,param_1,*(longlong *)(param_1 + 0x28),(char)param_1[0x23]);
      return;
    }
    if ((-1 < param_1[0x19]) && (*(longlong *)(param_1 + 0x26) != 0)) {
      SdhostRemoveOutstandingRequest(lVar6,(undefined8 *)param_1);
      (**(code **)(param_1 + 0x26))(lVar6,param_1,*(undefined8 *)(param_1 + 0x28));
      return;
    }
  }
  SdhostRemoveOutstandingRequest(lVar6,(undefined8 *)param_1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  lVar7 = *(longlong *)(param_1 + 0x28);
  if (lVar7 != 0) {
    lVar8 = KeQueryInterruptTimePrecise(&local_res8);
    *(longlong *)(lVar6 + 0x1e08) = lVar8;
    uVar9 = lVar8 - *(longlong *)(lVar6 + 0x1e00);
    if (4999999 < uVar9) {
      *(int *)(lVar6 + 0x1de8) = *(int *)(lVar6 + 0x1de8) + 1;
      *(longlong *)(lVar6 + 0x1df0) = lVar7;
      *(ulonglong *)(lVar6 + 0x1df8) = uVar9;
    }
    uVar9 = KeQueryPerformanceCounter(0);
    iVar4 = param_1[0x19];
    *(ulonglong *)(param_1 + 0x2a) = uVar9;
    LOCK();
    piVar1 = (int *)(lVar6 + 0xdc8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    puVar10 = (undefined8 *)
              ((ulonglong)(iVar2 - 1U & *(uint *)(lVar6 + 0xdcc)) * 0x20 +
              *(longlong *)(lVar6 + 0xdd0));
    *(undefined8 **)(lVar6 + 0xdd8) = puVar10;
    *puVar10 = 0x6f436649;
    puVar10[1] = lVar7;
    puVar10[2] = (longlong)iVar4;
    puVar10[3] = uVar9 & 0xffffffff;
    *(int *)(lVar7 + 0x30) = param_1[0x19];
    *(ulonglong *)(lVar7 + 0x38) = (ulonglong)(uint)param_1[0xc];
    IofCompleteRequest(lVar7,0);
    lVar7 = *(longlong *)(*(longlong *)(lVar6 + 8) + 0x1b0);
    if (lVar7 != 0) {
      PoFxIdleComponent(lVar7,0,0);
    }
  }
  if (((char)param_1[0x23] != '\0') && (*(char *)(lVar6 + 0xb38) == '\0')) {
    KeSetEvent(param_1 + 0x30,0,0);
  }
  SdhostStartNextIo(lVar6,(longlong)param_1);
  return;
}



===== SdhostDisableIrpQueue @ 1c0002578 =====

void SdhostDisableIrpQueue(longlong param_1)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xb90,&local_28);
  *(undefined1 *)(param_1 + 0xba8) = 0;
  KeReleaseInStackQueuedSpinLock(&local_28);
  return;
}



===== SdhostDrainIrpQueue @ 1c00025d0 =====

void SdhostDrainIrpQueue(longlong param_1)

{
  longlong **pplVar1;
  longlong lVar2;
  code *pcVar3;
  longlong ***ppplVar4;
  longlong ***ppplVar5;
  longlong ***local_38;
  longlong ***local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  SdhostDisableIrpQueue(param_1);
  KeWaitForSingleObject(param_1 + 0xbb0,0,0,0,0);
  local_30 = (longlong ***)&local_38;
  local_38 = (longlong ***)&local_38;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xb90,&local_28);
  ppplVar5 = *(longlong ****)(param_1 + 0xb98);
  while (ppplVar4 = ppplVar5, ppplVar4 != (longlong ***)(param_1 + 0xb98)) {
    ppplVar5 = (longlong ***)*ppplVar4;
    if (((longlong ***)ppplVar5[1] != ppplVar4) ||
       (pplVar1 = ppplVar4[1], (longlong ***)*pplVar1 != ppplVar4)) goto LAB_1c000272b;
    *pplVar1 = (longlong *)ppplVar5;
    ppplVar5[1] = pplVar1;
    if ((longlong ****)*local_30 != &local_38) goto LAB_1c000272b;
    ppplVar4[1] = (longlong **)local_30;
    *ppplVar4 = (longlong **)&local_38;
    *local_30 = (longlong **)ppplVar4;
    local_30 = ppplVar4;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  ppplVar5 = local_38;
  while( true ) {
    if ((longlong ****)ppplVar5 == &local_38) {
      return;
    }
    ppplVar4 = (longlong ***)*ppplVar5;
    if (((longlong ***)ppplVar4[1] != ppplVar5) ||
       (pplVar1 = ppplVar5[1], (longlong ***)*pplVar1 != ppplVar5)) break;
    *pplVar1 = (longlong *)ppplVar4;
    ppplVar4[1] = pplVar1;
    ppplVar5[-0xe] = (longlong **)0x0;
    *(undefined4 *)(ppplVar5 + -0xf) = 0xc000000e;
    IofCompleteRequest(ppplVar5 + -0x15,0);
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x1b0);
    ppplVar5 = ppplVar4;
    if (lVar2 != 0) {
      PoFxIdleComponent(lVar2,0,0);
    }
  }
LAB_1c000272b:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== SdhostDumpProcessBusRequest @ 1c0002738 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdhostDumpProcessBusRequest
              (longlong param_1,int *param_2,undefined8 *param_3,int param_4,undefined2 param_5,
              undefined2 param_6,longlong param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 local_res10 [8];
  undefined1 local_res18 [8];
  uint local_38;
  uint local_34;
  undefined8 local_30;
  
  if (*(int *)(param_3 + 2) == 1) {
    SdhostInitializeRequest(param_2,param_3,1);
    param_2[0x26] = 0;
    param_2[0x27] = 0;
  }
  else {
    SdhostInitializeRequest(param_2,param_3,2);
    *(undefined2 *)(param_2 + 0xb) = param_6;
    *(undefined2 *)((longlong)param_2 + 0x2a) = param_5;
  }
  param_2[9] = param_4;
  if (*(int *)(param_3 + 2) == 1) {
    iVar3 = SdhostIssueRequest(param_1,param_2,0,0);
  }
  else {
    iVar3 = SdhostBuildTransfer(param_1,param_2,param_7,0,0);
  }
  if ((((iVar3 + 0x80000000U & 0x80000000) != 0) || (iVar3 == -0x3fffffea)) && (param_2[0x19] != 0))
  {
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0xc0);
    do {
      uVar6 = *(uint *)(param_1 + 0xc30);
      local_38 = *(uint *)(param_1 + 0xc30);
      local_30 = 0;
      local_34 = *(uint *)(param_1 + 0xc34);
      lVar2 = *(longlong *)(param_1 + 8);
      local_res18[0] = 0;
      local_res10[0] = 0;
      param_8 = 0;
      lVar4 = KeQueryInterruptTimePrecise(&local_30);
      while( true ) {
        (**(code **)(*(longlong *)(lVar2 + 0xc0) + 0x18))
                  (*(undefined8 *)(param_1 + 0xa88),&local_38,&local_34,local_res18,local_res10,
                   &param_8);
        local_38 = (*(uint *)(param_1 + 0xc30) | local_38) & *(uint *)(param_1 + 0xb34);
        local_34 = local_34 | *(uint *)(param_1 + 0xc34);
        *(undefined4 *)(param_1 + 0xc30) = 0;
        *(undefined4 *)(param_1 + 0xc34) = 0;
        if (uVar6 != local_38) break;
        uVar5 = KeQueryInterruptTimePrecise(&local_30);
        if (lVar4 + 50000000U <= uVar5) {
          *(undefined4 *)(param_1 + 0xc30) = 0x8000;
          *(undefined4 *)(param_1 + 0xc34) = 0x11;
          break;
        }
        KeStallExecutionProcessor(1);
        if ((local_38 != *(uint *)(param_1 + 0xc30)) || (local_34 != *(uint *)(param_1 + 0xc34)))
        break;
      }
      uVar6 = uVar6 ^ local_38;
      if (uVar6 != 0) {
        (**(code **)(lVar1 + 0x30))(*(undefined8 *)(param_1 + 0xa88),param_2,local_38,local_34);
        if ((uVar6 >> 0xf & 1) != 0) {
          if ((local_34 & 0x11) == 0) {
            if ((local_34 & 0x22) == 0) {
              if ((local_34 & 0x44) == 0) {
                if ((local_34 & 8) == 0) {
                  iVar3 = (-(uint)((local_34 & 0x80) != 0) & 0xffffff19) + 0xc0000185;
                }
                else {
                  iVar3 = -0x3ffffe7a;
                }
              }
              else {
                iVar3 = -0x3fffff64;
              }
            }
            else {
              iVar3 = -0x3fffffc1;
            }
          }
          else {
            iVar3 = -0x3fffff4b;
          }
          param_2[0x19] = iVar3;
          break;
        }
        if (param_2[0x18] == 0) break;
      }
    } while (((*param_2 == 3) || (param_2[0x19] == -0x3fffffea)) ||
            ((param_2[0x18] != 0 || (uVar6 == 0))));
    iVar3 = param_2[0x19];
  }
  return iVar3;
}



===== SdhostFreeRequest @ 1c00029c0 =====

void SdhostFreeRequest(longlong param_1)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  
  plVar2 = (longlong *)(param_1 + 0x68);
  lVar4 = *(longlong *)(param_1 + 0xb8) + 0xbc8;
  plVar3 = *(longlong **)(*(longlong *)(param_1 + 0xb8) + 0xbd0);
  if (*plVar3 != lVar4) {
    plVar3 = (longlong *)0x3;
    pcVar1 = (code *)swi(0x29);
    plVar2 = (longlong *)(*pcVar1)();
  }
  *plVar2 = lVar4;
  plVar2[1] = (longlong)plVar3;
  *plVar3 = (longlong)plVar2;
  *(longlong **)(lVar4 + 8) = plVar2;
  return;
}



===== SdhostFreeRequestSynchronous @ 1c00029f8 =====

void SdhostFreeRequestSynchronous(longlong param_1)

{
  longlong lVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  SdhostFreeRequest(param_1);
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(lVar1 + 0xb90);
  *(undefined1 *)(lVar1 + 0xba8) = 1;
  KeReleaseInStackQueuedSpinLock(&local_28);
  SdhostStartNextIo(lVar1,0);
  return;
}



===== SdhostInitializeRequest @ 1c0002a60 =====

void SdhostInitializeRequest(undefined4 *param_1,undefined8 *param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  memset(param_1,0,0x68);
  if (param_2 != (undefined8 *)0x0) {
    uVar1 = param_2[1];
    *(undefined8 *)(param_1 + 2) = *param_2;
    *(undefined8 *)(param_1 + 4) = uVar1;
    uVar1 = param_2[3];
    *(undefined8 *)(param_1 + 6) = param_2[2];
    *(undefined8 *)(param_1 + 8) = uVar1;
    uVar1 = param_2[5];
    *(undefined8 *)(param_1 + 10) = param_2[4];
    *(undefined8 *)(param_1 + 0xc) = uVar1;
    uVar1 = param_2[7];
    *(undefined8 *)(param_1 + 0xe) = param_2[6];
    *(undefined8 *)(param_1 + 0x10) = uVar1;
    uVar1 = param_2[9];
    *(undefined8 *)(param_1 + 0x12) = param_2[8];
    *(undefined8 *)(param_1 + 0x14) = uVar1;
    *(undefined8 *)(param_1 + 0x16) = param_2[10];
  }
  *param_1 = param_3;
  *(undefined1 *)(param_1 + 0x23) = 0;
  param_1[0x22] = 0;
  param_1[0x24] = 0;
  *(undefined8 *)(param_1 + 0x26) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x2a) = 0;
  param_1[0x19] = 0xc0000185;
  return;
}



===== SdhostIssueCommand @ 1c0002b04 =====

void SdhostIssueCommand(longlong param_1,int *param_2,undefined8 *param_3,int param_4,
                       undefined2 param_5,undefined2 param_6,longlong param_7,longlong param_8,
                       undefined8 param_9,undefined1 param_10)

{
  undefined1 in_stack_fffffffffffffff0;
  
  if (*(char *)(param_1 + 0xb38) == '\0') {
    if (*(int *)(param_3 + 2) == 1) {
      SdhostInitializeRequest(param_2,param_3,1);
      *(undefined8 *)(param_2 + 0x26) = param_9;
      param_2[9] = param_4;
      SdhostIssueRequest(param_1,param_2,param_8,param_10);
    }
    else {
      SdhostInitializeRequest(param_2,param_3,2);
      *(undefined8 *)(param_2 + 0x26) = param_9;
      *(undefined2 *)(param_2 + 0xb) = param_6;
      *(undefined2 *)((longlong)param_2 + 0x2a) = param_5;
      param_2[9] = param_4;
      SdhostBuildTransfer(param_1,param_2,param_7,param_8,param_10);
    }
  }
  else {
    SdhostDumpProcessBusRequest
              (param_1,param_2,param_3,param_4,param_5,param_6,param_7,in_stack_fffffffffffffff0);
  }
  return;
}



===== SdhostIssueCommandNoTransfer @ 1c0002c08 =====

void SdhostIssueCommandNoTransfer
               (longlong param_1,int *param_2,undefined8 *param_3,int param_4,longlong param_5,
               undefined8 param_6,undefined1 param_7)

{
  SdhostIssueCommand(param_1,param_2,param_3,param_4,0,0,0,param_5,param_6,param_7);
  return;
}



===== SdhostIssueRequest @ 1c0002c54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdhostIssueRequest(longlong param_1,int *param_2,longlong param_3,undefined1 param_4)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  int iVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  longlong lVar10;
  undefined1 *puVar11;
  longlong *plVar12;
  undefined8 uVar13;
  char cVar14;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [40];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  if ((param_3 != 0) &&
     ((*(uint *)(*(longlong *)(*(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x28) + 0x40) + 4) & 1)
      != 0)) {
    *(undefined4 *)(param_3 + 0x30) = 0xc0000184;
    *(ulonglong *)(param_3 + 0x38) = (ulonglong)(uint)param_2[0xc];
    IofCompleteRequest(param_3,0);
    return -0x3ffffe7c;
  }
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 8) + 0xc0);
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 8) + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8);
  puVar11 = auStack_78;
  if ((*param_2 != 3) && (puVar11 = auStack_78, param_2[0x19] == -0x3ffffe7b)) {
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    cVar14 = *(char *)(param_1 + 0xb38) == '\0';
    if ((bool)cVar14) {
      KeAcquireInStackQueuedSpinLock(param_1 + 0xb90,&local_48);
    }
    puVar11 = auStack_78;
    lVar10 = param_1 + 0xbd8;
    plVar12 = *(longlong **)(param_1 + 0xbe0);
    plVar8 = (longlong *)(param_2 + 0x1a);
    if (*plVar12 != lVar10) {
      cVar14 = '\x03';
      pcVar6 = (code *)swi(0x29);
      plVar8 = (longlong *)(*pcVar6)();
      puVar11 = auStack_70;
    }
    *plVar8 = lVar10;
    plVar8[1] = (longlong)plVar12;
    *plVar12 = (longlong)plVar8;
    *(longlong **)(lVar10 + 8) = plVar8;
    *(int *)(param_1 + 0xbe8) = *(int *)(param_1 + 0xbe8) + 1;
    if (cVar14 != '\0') {
      *(undefined8 *)(puVar11 + -8) = 0x1c0002d5e;
      KeReleaseInStackQueuedSpinLock(puVar11 + 0x30);
    }
  }
  iVar7 = param_2[6];
  *(undefined1 *)(param_2 + 0x23) = param_4;
  *(longlong *)(param_2 + 0x28) = param_3;
  if ((iVar7 == 0) || (iVar7 == 1)) {
    if ((((char)param_2[2] == '\x06') && (param_2[9] == 0x3200100)) ||
       ((*(int *)(param_1 + 0xd4) == 3 && ((char)param_2[2] == '&')))) {
      iVar7 = 60000;
    }
    else {
      iVar7 = 1000;
    }
  }
  else {
    if (((iVar7 != 2) && (iVar7 != 3)) && (iVar7 != 4)) goto LAB_1c0002dc4;
    iVar7 = 10000;
  }
  *(undefined8 *)(puVar11 + -8) = 0x1c0002dc4;
  SdhostSetRequestTimeout((longlong)param_2,iVar7);
LAB_1c0002dc4:
  iVar7 = *param_2;
  if (iVar7 == 1) {
    uVar13 = 0x62444d43;
  }
  else if (iVar7 == 2) {
    uVar13 = 0x64444d43;
  }
  else if (iVar7 == 3) {
    uVar13 = 0x4e415254;
  }
  else {
    uVar13 = 0x74525245;
  }
  uVar3 = param_2[9];
  bVar2 = *(byte *)(param_2 + 2);
  LOCK();
  piVar1 = (int *)(param_1 + 0xdc8);
  iVar7 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  puVar9 = (undefined8 *)
           ((ulonglong)(*(uint *)(param_1 + 0xdcc) & iVar7 - 1U) * 0x20 +
           *(longlong *)(param_1 + 0xdd0));
  *(undefined8 **)(param_1 + 0xdd8) = puVar9;
  *puVar9 = uVar13;
  puVar9[1] = (ulonglong)bVar2;
  puVar9[2] = (ulonglong)uVar3;
  puVar9[3] = param_2;
  if (*(char *)(param_1 + 0xb38) == '\0') {
    *(undefined8 *)(puVar11 + -8) = 0x1c0002e62;
    KeAcquireInStackQueuedSpinLock(param_2 + 0x56,puVar11 + 0x48);
    pcVar6 = *(code **)(lVar4 + 0x20);
    *(undefined8 *)(puVar11 + -8) = 0x1c0002e77;
    iVar7 = (*pcVar6)(lVar5 + 0x10,param_2);
    *(undefined8 *)(puVar11 + -8) = 0x1c0002e85;
    KeReleaseInStackQueuedSpinLock(puVar11 + 0x48);
  }
  else {
    pcVar6 = *(code **)(lVar4 + 0x20);
    *(undefined8 *)(puVar11 + -8) = 0x1c0002e4b;
    iVar7 = (*pcVar6)(lVar5 + 0x10,param_2);
  }
  if (((*param_2 != 3) && ((char)param_2[0x23] != '\0')) && (*(char *)(param_1 + 0xb38) == '\0')) {
    *(undefined8 *)(puVar11 + 0x20) = 0;
    *(undefined8 *)(puVar11 + -8) = 0x1c0002ec0;
    KeWaitForSingleObject(param_2 + 0x30,0,0,0);
    *(undefined8 *)(puVar11 + -8) = 0x1c0002ecf;
    KeClearEvent(param_2 + 0x30);
    iVar7 = param_2[0x19];
    *(undefined1 *)(param_2 + 0x23) = 0;
  }
  return iVar7;
}



===== SdhostPdoDeviceCommand @ 1c0002f04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdhostPdoDeviceCommand(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  byte bVar6;
  bool bVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x598);
  iVar5 = *(int *)(param_2 + 0x44);
  bVar3 = true;
  if (iVar5 == 0) {
    bVar6 = (&SdCmdFlags)[*(byte *)(param_2 + 0x40)];
  }
  else {
    if (iVar5 != 1) {
      return -0x3ffffff3;
    }
    bVar6 = (&SdAppCmdFlags)[*(byte *)(param_2 + 0x40)];
  }
  if (*(int *)(param_2 + 0x4c) == 0) {
    return -0x3ffffff3;
  }
  if (*(int *)(param_2 + 0x50) == 0) {
    return -0x3ffffff3;
  }
  if ((*(int *)(param_2 + 0x4c) != 1) && (*(int *)(param_2 + 0x48) == 0)) {
    return -0x3ffffff3;
  }
  if ((bVar6 & 3) == 0) {
    return -0x3fffffde;
  }
  iVar1 = *(int *)(param_1 + 0xb4);
  if ((iVar1 - 2U < 2) && ((bVar6 & 1) == 0)) {
    return -0x3fffffde;
  }
  if (iVar1 == 1) {
    bVar7 = (bVar6 & 2) == 0;
  }
  else {
    if (iVar1 != 3) goto LAB_1c0002fbb;
    bVar7 = iVar5 == 1;
  }
  if (bVar7) {
    return -0x3fffffde;
  }
LAB_1c0002fbb:
  if ((*(char *)(lVar2 + 0xb3b) == '\0') &&
     (cVar4 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0xc0) + 0x70))
                        (*(undefined8 *)(lVar2 + 0xa88)), cVar4 == '\0')) {
    bVar3 = false;
  }
  if (((bVar6 & 4) != 0) && (bVar3)) {
    return -0x3fffff5e;
  }
  if ((*(int *)(param_2 + 0x4c) - 2U < 3) && (*(longlong *)(param_2 + 0x58) == 0)) {
    return -0x3ffffff3;
  }
  iVar5 = SdhostQueueIo(param_1,param_3);
  return iVar5;
}



===== SdhostPdoGetProperty @ 1c0003044 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SdhostPdoGetProperty(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  uint uVar7;
  ulonglong uVar8;
  int *piVar9;
  bool bVar10;
  uint *puVar11;
  ulonglong uVar12;
  ulonglong local_res8;
  
  lVar2 = *(longlong *)(param_1 + 0x598);
  local_res8 = 0;
  uVar5 = 1;
  lVar3 = *(longlong *)(lVar2 + 8);
  lVar4 = *(longlong *)(lVar3 + 0xf0 + (ulonglong)*(byte *)(lVar2 + 4) * 8);
  if (*(longlong *)(lVar3 + 0x1b0) != 0) {
    PoFxActivateComponent(*(longlong *)(lVar3 + 0x1b0),0,1);
  }
  iVar1 = *(int *)(param_2 + 0x40);
  if (iVar1 < 9) {
    if (iVar1 == 8) {
      *(undefined8 *)(param_2 + 0x20) = 1;
      if (*(int *)(param_2 + 0x50) != 0) {
        uVar8 = SdhostValidatePdoPowerState(param_1);
        uVar12 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) goto LAB_1c0003369;
        piVar9 = (int *)SdhostAllocateRequestSynchronous(lVar2);
        uVar8 = SdhostBusInterfaceControl(param_1,piVar9,'\x01',&local_res8);
        uVar12 = uVar8 & 0xffffffff;
        SdhostFreeRequestSynchronous((longlong)piVar9);
        if ((int)uVar8 < 0) goto LAB_1c0003369;
        uVar5 = (undefined1)local_res8;
LAB_1c0003144:
        **(undefined1 **)(param_2 + 0x48) = uVar5;
        goto LAB_1c0003369;
      }
    }
    else if (iVar1 == 0) {
      *(undefined8 *)(param_2 + 0x20) = 4;
      if (3 < *(uint *)(param_2 + 0x50)) {
        uVar7 = *(uint *)(param_1 + 0x5e0);
LAB_1c0003184:
        puVar11 = *(uint **)(param_2 + 0x48);
LAB_1c0003188:
        *puVar11 = uVar7;
        goto LAB_1c0003367;
      }
    }
    else if (iVar1 == 1) {
      puVar11 = *(uint **)(param_2 + 0x48);
      *(undefined8 *)(param_2 + 0x20) = 4;
      if (3 < *(uint *)(param_2 + 0x50)) {
        uVar7 = ~*(uint *)(param_1 + 4) & 1;
        goto LAB_1c0003188;
      }
    }
    else if (iVar1 == 2) {
      *(undefined8 *)(param_2 + 0x20) = 1;
      if (*(int *)(param_2 + 0x50) != 0) {
        uVar5 = (**(code **)(*(longlong *)(lVar3 + 0xc0) + 0x70))(lVar4 + 0x10);
LAB_1c000319f:
        **(undefined1 **)(param_2 + 0x48) = uVar5;
        goto LAB_1c0003367;
      }
    }
    else if (iVar1 == 3) {
      *(undefined8 *)(param_2 + 0x20) = 1;
      if (*(int *)(param_2 + 0x50) != 0) {
        uVar5 = *(undefined1 *)(param_1 + 0xb0);
        goto LAB_1c000319f;
      }
    }
    else if (iVar1 == 4) {
      *(undefined8 *)(param_2 + 0x20) = 4;
      if (3 < *(uint *)(param_2 + 0x50)) {
        uVar7 = *(uint *)(param_1 + 0xb4);
        goto LAB_1c0003184;
      }
    }
    else if (iVar1 == 5) {
      *(undefined8 *)(param_2 + 0x20) = 2;
      if (1 < *(uint *)(param_2 + 0x50)) {
        **(undefined2 **)(param_2 + 0x48) = 0x400;
        goto LAB_1c0003367;
      }
    }
    else if (iVar1 == 6) {
      *(undefined8 *)(param_2 + 0x20) = 1;
      if (*(int *)(param_2 + 0x50) != 0) {
        uVar8 = SdhostValidatePdoPowerState(param_1);
        uVar12 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) goto LAB_1c0003369;
        uVar5 = *(undefined1 *)(lVar2 + 0xb51);
        goto LAB_1c0003144;
      }
    }
    else {
      if (iVar1 != 7) goto LAB_1c0003287;
      *(undefined8 *)(param_2 + 0x20) = 4;
      if (3 < *(uint *)(param_2 + 0x50)) {
        uVar8 = SdhostValidatePdoPowerState(param_1);
        uVar12 = uVar8 & 0xffffffff;
        if (-1 < (int)uVar8) {
          **(undefined4 **)(param_2 + 0x48) = *(undefined4 *)(lVar2 + 0xb54);
        }
        goto LAB_1c0003369;
      }
    }
  }
  else if (iVar1 == 9) {
    *(undefined8 *)(param_2 + 0x20) = 2;
    if (1 < *(uint *)(param_2 + 0x50)) {
      uVar6 = *(undefined2 *)(lVar2 + 0xb0a);
LAB_1c0003360:
      **(undefined2 **)(param_2 + 0x48) = uVar6;
LAB_1c0003367:
      uVar12 = 0;
      goto LAB_1c0003369;
    }
  }
  else if ((iVar1 == 10) || (iVar1 == 0xb)) {
    *(undefined8 *)(param_2 + 0x20) = 2;
    if (1 < *(uint *)(param_2 + 0x50)) {
      uVar6 = *(undefined2 *)(lVar2 + 0xb7a + (ulonglong)*(byte *)(param_1 + 0xb0) * 2);
      goto LAB_1c0003360;
    }
  }
  else if (iVar1 == 0xc) {
    *(undefined8 *)(param_2 + 0x20) = 1;
    if (*(int *)(param_2 + 0x50) != 0) {
      bVar10 = (*(byte *)(lVar2 + 0xb45) & '\x01' << (*(byte *)(param_1 + 0xb0) & 0x1f)) != 0;
LAB_1c00032f1:
      **(byte **)(param_2 + 0x48) = bVar10;
      goto LAB_1c0003367;
    }
  }
  else if (iVar1 == 0xf) {
    *(undefined8 *)(param_2 + 0x20) = 1;
    if (*(int *)(param_2 + 0x50) != 0) {
      bVar10 = (bool)(*(byte *)(param_1 + 0xb8) & 1);
      goto LAB_1c00032f1;
    }
  }
  else if (iVar1 == 0x10) {
    *(undefined8 *)(param_2 + 0x20) = 1;
    if (*(int *)(param_2 + 0x50) != 0) {
      if (((*(uint *)(lVar2 + 0xb24) & 1) == 0) || (*(int *)(lVar2 + 0xb4c) != 3)) {
        uVar5 = 0;
      }
      **(undefined1 **)(param_2 + 0x48) = uVar5;
      goto LAB_1c0003367;
    }
  }
  else {
    if (iVar1 != 0x11) {
LAB_1c0003287:
      uVar12 = 0xc000000d;
      goto LAB_1c0003369;
    }
    *(undefined8 *)(param_2 + 0x20) = 1;
    if (*(int *)(param_2 + 0x50) != 0) {
      **(undefined1 **)(param_2 + 0x48) = 0;
      goto LAB_1c0003367;
    }
  }
  uVar12 = 0xc0000023;
LAB_1c0003369:
  if (*(longlong *)(lVar3 + 0x1b0) != 0) {
    PoFxIdleComponent(*(longlong *)(lVar3 + 0x1b0),0,0);
  }
  return uVar12;
}



===== SdhostPdoInternalDeviceControl @ 1c00033a8 =====

ulonglong SdhostPdoInternalDeviceControl(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  char cVar6;
  int *piVar7;
  longlong lVar8;
  
  lVar5 = *(longlong *)(param_2 + 0xb8);
  lVar8 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar5 + 0x18) != 0x43073) {
    uVar4 = 0xc0000010;
    goto LAB_1c000344b;
  }
  piVar7 = *(int **)(lVar5 + 0x20);
  uVar3 = SdhostValidatePdoPowerState(lVar8);
  uVar4 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    if (*(uint *)(lVar5 + 0x10) < 0x68) {
      uVar4 = 0xc000000d;
      goto LAB_1c000344b;
    }
    iVar1 = *piVar7;
    if (iVar1 == 0) {
      uVar3 = SdhostPdoGetProperty(lVar8,(longlong)piVar7);
      uVar2 = (uint)uVar3;
    }
    else if (iVar1 == 1) {
      uVar3 = SdhostPdoSetProperty(lVar8,(longlong)piVar7);
      uVar2 = (uint)uVar3;
    }
    else {
      if (iVar1 == 2) {
        cVar6 = '\0';
      }
      else {
        if (iVar1 != 3) {
          uVar4 = 0xc0000010;
          goto LAB_1c0003443;
        }
        cVar6 = '\x01';
      }
      uVar2 = SdhostPdoIssueCommand(lVar8,(longlong)piVar7,param_2,cVar6);
    }
    uVar4 = (ulonglong)uVar2;
  }
LAB_1c0003443:
  if ((int)uVar4 == 0x103) {
    return uVar4;
  }
LAB_1c000344b:
  *(int *)(param_2 + 0x30) = (int)uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== SdhostPdoIssueCommand @ 1c0003474 =====

int SdhostPdoIssueCommand(longlong param_1,longlong param_2,longlong param_3,char param_4)

{
  byte *pbVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  undefined8 local_res8;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  lVar2 = *(longlong *)(param_1 + 0x598);
  local_res8 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uVar5 = KeQueryInterruptTimePrecise(&local_res8);
  *(undefined8 *)(lVar2 + 0x1e00) = uVar5;
  lVar2 = *(longlong *)(lVar2 + 8);
  if (*(longlong *)(lVar2 + 0x1b0) != 0) {
    PoFxActivateComponent(*(longlong *)(lVar2 + 0x1b0),0,0);
  }
  KeAcquireInStackQueuedSpinLock(lVar2 + 0x1d0,&local_38);
  puVar9 = auStack_58;
  if (*(char *)(lVar2 + 0x1d8) == '\0') {
    lVar6 = lVar2 + 0x1c0;
    plVar8 = *(longlong **)(lVar2 + 0x1c8);
    plVar7 = (longlong *)(param_3 + 0xa8);
    if (*plVar8 != lVar6) {
      plVar7 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      lVar6 = (*pcVar3)();
      puVar9 = auStack_50;
    }
    *plVar7 = lVar6;
    plVar7[1] = (longlong)plVar8;
    *plVar8 = (longlong)plVar7;
    *(longlong **)(lVar6 + 8) = plVar7;
    pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    *(undefined8 *)(puVar9 + -8) = 0x1c0003548;
    KeReleaseInStackQueuedSpinLock(puVar9 + 0x20);
    return 0x103;
  }
  KeReleaseInStackQueuedSpinLock(&local_38);
  if (param_4 == '\0') {
    iVar4 = SdhostPdoDeviceCommand(param_1,param_2,param_3);
    if (iVar4 == 0x103) {
      return 0x103;
    }
  }
  else {
    iVar4 = 0;
  }
  if (*(longlong *)(lVar2 + 0x1b0) != 0) {
    PoFxIdleComponent(*(longlong *)(lVar2 + 0x1b0),0,0);
  }
  return iVar4;
}



===== SdhostPdoSetProperty @ 1c00035c0 =====

ulonglong SdhostPdoSetProperty(longlong param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  int *piVar8;
  undefined8 uVar9;
  undefined1 uVar10;
  ulonglong uVar11;
  undefined1 uVar12;
  ulonglong local_res8;
  
  lVar4 = *(longlong *)(param_1 + 0x598);
  lVar5 = *(longlong *)(lVar4 + 8);
  if (*(longlong *)(lVar5 + 0x1b0) != 0) {
    PoFxActivateComponent();
  }
  iVar3 = *(int *)(param_2 + 0x40);
  if (iVar3 == 6) {
    *(undefined8 *)(param_2 + 0x20) = 1;
    if (*(int *)(param_2 + 0x50) != 0) {
      bVar1 = **(byte **)(param_2 + 0x48);
      if ((bVar1 == 1) || (bVar1 == 4)) {
        uVar7 = SdhostValidatePdoPowerState(param_1);
        uVar11 = uVar7 & 0xffffffff;
        if ((int)uVar7 < 0) goto LAB_1c00038b5;
        if ((((*(uint *)(lVar4 + 200) & 2) != 0) && (bVar1 == 4)) || (bVar1 == 1)) {
          piVar8 = (int *)SdhostAllocateRequestSynchronous(lVar4);
          iVar3 = *(int *)(param_1 + 0xb4);
          uVar6 = (uint)bVar1;
          if (iVar3 == 1) {
            uVar9 = SdhostSetBusWidthSdio(lVar4,piVar8,uVar6);
            uVar6 = (uint)uVar9;
          }
          else if (iVar3 == 2) {
            uVar7 = SdhostSetBusWidthSd(lVar4,piVar8,uVar6);
            uVar6 = (uint)uVar7;
          }
          else {
            if (iVar3 != 3) {
              uVar11 = 0xc000000d;
              goto LAB_1c00038a9;
            }
            uVar9 = SdhostSetBusWidthMmc(lVar4,piVar8,uVar6);
            uVar6 = (uint)uVar9;
          }
LAB_1c00038a4:
          uVar11 = (ulonglong)uVar6;
          goto LAB_1c00038a9;
        }
      }
LAB_1c00038b0:
      uVar11 = 0xc000000d;
      goto LAB_1c00038b5;
    }
  }
  else if (iVar3 == 7) {
    *(undefined8 *)(param_2 + 0x20) = 4;
    if (3 < *(uint *)(param_2 + 0x50)) {
      uVar7 = SdhostValidatePdoPowerState(param_1);
      uVar11 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar7) {
        uVar6 = SdhostSetClock(lVar4,**(undefined4 **)(param_2 + 0x48));
        uVar11 = (ulonglong)uVar6;
      }
      goto LAB_1c00038b5;
    }
  }
  else if (iVar3 == 8) {
    *(undefined8 *)(param_2 + 0x20) = 1;
    if (*(int *)(param_2 + 0x50) != 0) {
      uVar7 = SdhostValidatePdoPowerState(param_1);
      uVar11 = uVar7 & 0xffffffff;
      if ((int)uVar7 < 0) goto LAB_1c00038b5;
      local_res8 = (ulonglong)**(byte **)(param_2 + 0x48);
      piVar8 = (int *)SdhostAllocateRequestSynchronous(lVar4);
      uVar7 = SdhostBusInterfaceControl(param_1,piVar8,'\0',&local_res8);
      uVar6 = (uint)uVar7;
LAB_1c00037c6:
      uVar11 = (ulonglong)uVar6;
LAB_1c00038a9:
      SdhostFreeRequestSynchronous((longlong)piVar8);
      goto LAB_1c00038b5;
    }
  }
  else if ((iVar3 == 10) || (iVar3 == 0xb)) {
    *(undefined8 *)(param_2 + 0x20) = 2;
    if (1 < *(uint *)(param_2 + 0x50)) {
      uVar7 = SdhostValidatePdoPowerState(param_1);
      uVar11 = uVar7 & 0xffffffff;
      if ((int)uVar7 < 0) goto LAB_1c00038b5;
      uVar2 = **(ushort **)(param_2 + 0x48);
      piVar8 = (int *)SdhostAllocateRequestSynchronous(lVar4);
      uVar7 = SdhostSetFunctionBlockSize(param_1,piVar8,uVar2);
      uVar6 = (uint)uVar7;
      goto LAB_1c00038a4;
    }
  }
  else {
    if (iVar3 != 0xc) {
      if (iVar3 == 0xd) {
        *(undefined8 *)(param_2 + 0x20) = 1;
        if (*(int *)(param_2 + 0x50) == 0) goto LAB_1c000373e;
        uVar7 = SdhostValidatePdoPowerState(param_1);
        uVar11 = uVar7 & 0xffffffff;
        if ((int)uVar7 < 0) goto LAB_1c00038b5;
        if (**(char **)(param_2 + 0x48) != '\0') {
          uVar12 = 0;
          uVar10 = 1;
          goto LAB_1c000369f;
        }
        SdhostDisableEvents(lVar4,0x100);
        SdhostCardAndWakeInterruptEnable(lVar4,0,0);
        if ((*(uint *)(param_1 + 0x608) & 0x20000) == 0) {
          KeWaitForSingleObject(lVar4 + 0xc50,0,0,0,0);
        }
      }
      else {
        if (iVar3 != 0xe) goto LAB_1c00038b0;
        uVar7 = SdhostValidatePdoPowerState(param_1);
        uVar11 = uVar7 & 0xffffffff;
        if ((int)uVar7 < 0) goto LAB_1c00038b5;
        uVar12 = 1;
        uVar10 = 0;
LAB_1c000369f:
        SdhostCardAndWakeInterruptEnable(lVar4,uVar10,uVar12);
      }
      uVar11 = 0;
      goto LAB_1c00038b5;
    }
    *(undefined8 *)(param_2 + 0x20) = 1;
    if (*(int *)(param_2 + 0x50) != 0) {
      uVar7 = SdhostValidatePdoPowerState(param_1);
      uVar11 = uVar7 & 0xffffffff;
      if ((int)uVar7 < 0) goto LAB_1c00038b5;
      piVar8 = (int *)SdhostAllocateRequestSynchronous(lVar4);
      uVar7 = SdhostEnableSdioInterrupt(param_1,piVar8,**(char **)(param_2 + 0x48));
      uVar6 = (uint)uVar7;
      goto LAB_1c00037c6;
    }
  }
LAB_1c000373e:
  uVar11 = 0xc0000023;
LAB_1c00038b5:
  lVar4 = *(longlong *)(lVar5 + 0x1b0);
  if (lVar4 != 0) {
    PoFxIdleComponent(lVar4,0,0);
  }
  return uVar11;
}



===== SdhostQueueIo @ 1c00038f4 =====

int SdhostQueueIo(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar2 = *(longlong *)(param_1 + 0x598);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(lVar2 + 0xb90,&local_28);
  puVar7 = auStack_48;
  if (*(int *)(param_1 + 0x18) - 5U < 2) {
    KeReleaseInStackQueuedSpinLock(&local_28);
    lVar2 = *(longlong *)(*(longlong *)(lVar2 + 8) + 0x1b0);
    if (lVar2 != 0) {
      PoFxIdleComponent(lVar2,0,0);
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    iVar4 = -0x3fffffaa;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000056;
    IofCompleteRequest(param_2,0);
  }
  else {
    if ((*(char *)(lVar2 + 0xba8) == '\0') ||
       (*(longlong **)(lVar2 + 0xbc8) == (longlong *)(lVar2 + 0xbc8))) {
      plVar5 = (longlong *)(param_2 + 0xa8);
      plVar6 = *(longlong **)(lVar2 + 0xba0);
      if (*plVar6 != lVar2 + 0xb98) {
        plVar6 = (longlong *)0x3;
        pcVar3 = (code *)swi(0x29);
        plVar5 = (longlong *)(*pcVar3)();
        puVar7 = auStack_40;
      }
      *plVar5 = lVar2 + 0xb98;
      iVar4 = 0x103;
      plVar5[1] = (longlong)plVar6;
      *plVar6 = (longlong)plVar5;
      *(longlong **)(lVar2 + 0xba0) = plVar5;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
    }
    else {
      plVar5 = SdhostAllocateRequest(lVar2);
      if (plVar5 != (longlong *)0x0) {
        KeClearEvent(lVar2 + 0xbb0);
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        KeReleaseInStackQueuedSpinLock(&local_28);
        iVar4 = SdhostBuildCommand(lVar2,(int *)plVar5,param_2);
        if (iVar4 < 0) {
          *(int *)(param_2 + 0x30) = iVar4;
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(plVar5 + 6);
          KeAcquireInStackQueuedSpinLock(lVar2 + 0xb90,&local_28);
          SdhostFreeRequest((longlong)plVar5);
          KeReleaseInStackQueuedSpinLock(&local_28);
          IofCompleteRequest(param_2,0);
        }
        return iVar4;
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      iVar4 = -0x3fffff66;
      *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
      IofCompleteRequest(param_2,0);
      puVar7 = auStack_48;
    }
    *(undefined8 *)(puVar7 + -8) = 0x1c0003a75;
    KeReleaseInStackQueuedSpinLock(puVar7 + 0x20);
  }
  return iVar4;
}



===== SdhostRemoveOutstandingRequest @ 1c0003aec =====

void SdhostRemoveOutstandingRequest(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  bool bVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  bVar5 = *(char *)(param_1 + 0xb38) == '\0';
  if (bVar5) {
    KeAcquireInStackQueuedSpinLock(param_1 + 0xb90,&local_28);
  }
  puVar4 = *(undefined8 **)(param_1 + 0xbd8);
  do {
    if (puVar4 == (undefined8 *)(param_1 + 0xbd8)) {
LAB_1c0003b40:
      if (bVar5) {
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
      return;
    }
    puVar1 = (undefined8 *)*puVar4;
    if (puVar4 + -0xd == param_2) {
      if (((undefined8 *)puVar1[1] != puVar4) ||
         (puVar2 = (undefined8 *)puVar4[1], (undefined8 *)*puVar2 != puVar4)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      *puVar2 = puVar1;
      puVar1[1] = puVar2;
      *(int *)(param_1 + 0xbe8) = *(int *)(param_1 + 0xbe8) + -1;
      goto LAB_1c0003b40;
    }
    puVar4 = puVar1;
  } while( true );
}



===== SdhostRequestCompleteDpc @ 1c0003bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostRequestCompleteDpc(undefined8 param_1,longlong param_2,int *param_3,ulonglong param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int *piVar4;
  
  lVar3 = 0x80000000;
  piVar4 = param_3;
  if ((((param_3[0x19] + 0x80000000U & 0x80000000) != 0) || (param_3[0x19] == -0x3fffffea)) &&
     (iVar1 = *param_3, iVar1 != 1)) {
    if (iVar1 == 2) {
      *param_3 = 3;
      SdhostIssueRequest(param_2,param_3,*(longlong *)(param_3 + 0x28),(char)param_3[0x23]);
      return;
    }
    if (iVar1 != 3) {
      return;
    }
    lVar3 = *(longlong *)(param_3 + 0x14);
    if (lVar3 != 0) {
      lVar2 = *(longlong *)(param_3 + 0x2e);
      param_4 = (ulonglong)(uint)param_3[7];
      if (*(char *)(lVar2 + 0xb38) == '\0') {
        piVar4 = (int *)CONCAT71((int7)((ulonglong)lVar2 >> 8),param_3[7] == 2);
        (**(code **)(*(longlong *)(*(longlong *)(param_3 + 0x5a) + 8) + 0x60))();
        param_3[0x14] = 0;
        param_3[0x15] = 0;
        param_3[0x16] = 0;
      }
      else {
        piVar4 = *(int **)(lVar2 + 0xb00);
        param_4 = 0;
        lVar3 = *(longlong *)(param_3 + 0x5c);
        (**(code **)(*(longlong *)(*(longlong *)(param_3 + 0x5a) + 8) + 0xd0))();
      }
    }
  }
  SdhostCompleteRequest((short *)param_3,lVar3,piVar4,param_4);
  return;
}



===== SdhostRequestTimeoutDpc @ 1c0003ca0 =====

void SdhostRequestTimeoutDpc
               (undefined8 param_1,short *param_2,undefined8 param_3,undefined8 param_4)

{
  param_2[0x32] = 0xb5;
  param_2[0x33] = -0x4000;
  SdhostCompleteRequest(param_2,param_2,param_3,param_4);
  return;
}



===== SdhostSendDataCommand @ 1c0003cc0 =====

void SdhostSendDataCommand(undefined8 param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  *(undefined8 *)(param_4 + 0x14) = param_3;
  if ((char)param_4[0x23] == '\0') {
    SdhostIssueRequest(*(longlong *)(param_4 + 0x2e),param_4,*(longlong *)(param_4 + 0x28),0);
  }
  else {
    KeSetEvent(param_4 + 0x30,0,0);
  }
  return;
}



===== SdhostSetRequestTimeout @ 1c0003d14 =====

void SdhostSetRequestTimeout(longlong param_1,int param_2)

{
  if ((*(longlong *)(param_1 + 0xb8) == 0) ||
     (*(char *)(*(longlong *)(param_1 + 0xb8) + 0xb38) == '\0')) {
    *(int *)(param_1 + 0x90) = param_2;
    KeSetTimer(param_1 + 0xd8,(longlong)(param_2 * -10000),param_1 + 0x118);
  }
  return;
}



===== SdhostStartNextIo @ 1c0003d68 =====

char SdhostStartNextIo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (*(char *)(param_1 + 0xb38) != '\0') {
    return '\0';
  }
  lVar1 = param_1 + 0xb90;
  KeAcquireInStackQueuedSpinLock(lVar1,&local_38);
  if ((param_2 != 0) && (*(longlong *)(param_2 + 0xa0) != 0)) {
    SdhostFreeRequest(param_2);
  }
  bVar5 = false;
  if (*(char *)(param_1 + 0xba8) != '\0') {
    do {
      if (*(longlong **)(param_1 + 0xbc8) == (longlong *)(param_1 + 0xbc8)) break;
      plVar8 = (longlong *)(param_1 + 0xb98);
      plVar2 = (longlong *)*plVar8;
      if (plVar2 == plVar8) break;
      if (((longlong *)plVar2[1] != plVar8) ||
         (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        cVar6 = (*pcVar4)();
        return cVar6;
      }
      *plVar8 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar8;
      plVar8 = SdhostAllocateRequest(param_1);
      KeReleaseInStackQueuedSpinLock(&local_38);
      iVar7 = SdhostBuildCommand(param_1,(int *)plVar8,(longlong)(plVar2 + -0x15));
      if (iVar7 < 0) {
        *(int *)(plVar2 + -0xf) = iVar7;
        plVar2[-0xe] = (ulonglong)*(uint *)(plVar8 + 6);
        KeAcquireInStackQueuedSpinLock(lVar1,&local_38);
        SdhostFreeRequest((longlong)plVar8);
        KeReleaseInStackQueuedSpinLock(&local_38);
        IofCompleteRequest(plVar2 + -0x15,0);
      }
      else {
        bVar5 = true;
      }
      KeAcquireInStackQueuedSpinLock(lVar1,&local_38);
    } while (*(char *)(param_1 + 0xba8) != '\0');
    if (bVar5) goto LAB_1c0003ef1;
  }
  if (*(longlong **)(param_1 + 0xbd8) == (longlong *)(param_1 + 0xbd8)) {
    KeSetEvent(param_1 + 0xbb0,0,0);
  }
LAB_1c0003ef1:
  KeReleaseInStackQueuedSpinLock(&local_38);
  return bVar5;
}



===== SdhostBuildDriverList @ 1c0003f2c =====

undefined8 *
SdhostBuildDriverList(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  uint uVar4;
  short *psVar5;
  short *psVar6;
  
  puVar1 = (undefined8 *)ExAllocatePool2(0x40,0x58,0x6c446453);
  if (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x58,0x6c446453);
    if (puVar2 == (undefined8 *)0x0) {
      ExFreePoolWithTag(puVar1,0x6c446453);
    }
    else {
      RtlStringCbPrintfW((wchar_t *)(puVar1 + 1),0x1e,L"dumpsdport.sys",param_4);
      RtlStringCbPrintfW((wchar_t *)((longlong)puVar1 + 0x26),0x1e,L"sdport.sys",param_4);
      lVar3 = IoGetDriverObjectExtension
                        (*(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x598) + 8) + 0x10),
                         DriverEntry);
      psVar6 = *(short **)(lVar3 + 0x18);
      if ((psVar6 == (short *)0x0) || (*(ushort *)(lVar3 + 0x10) == 0)) {
        psVar5 = (short *)0x0;
      }
      else {
        uVar4 = (uint)(*(ushort *)(lVar3 + 0x10) >> 1);
        do {
          if (uVar4 == 0) goto LAB_1c0004035;
          uVar4 = uVar4 - 1;
          psVar5 = psVar6 + uVar4;
        } while (*psVar5 != 0x5c);
      }
      if (psVar5 != (short *)0x0) {
        psVar6 = psVar5 + 1;
      }
LAB_1c0004035:
      RtlStringCbPrintfW((wchar_t *)(puVar2 + 1),0x1e,L"%ws.sys",psVar6);
      RtlInitUnicodeString(puVar1 + 9,L"\\SystemRoot\\System32\\Drivers\\dumpsdport.sys");
      IoQueryFullDriverPath
                (*(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x598) + 8) + 0x10),
                 puVar2 + 9);
      *puVar1 = puVar2;
      *puVar2 = 0;
    }
  }
  return puVar1;
}



===== SdhostBuildDumpData @ 1c00040ac =====

undefined4 * SdhostBuildDumpData(void *param_1)

{
  undefined4 *_Dst;
  undefined4 *puVar1;
  longlong *plVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  longlong lVar7;
  void *pvVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  uint uVar12;
  undefined4 uVar13;
  
  puVar6 = (undefined4 *)ExAllocatePool2(0x40,0x3948,0x64446453);
  if (puVar6 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  _Dst = puVar6 + 2;
  *puVar6 = 0x53646453;
  memcpy(_Dst,*(void **)((longlong)param_1 + 0x598),0x1e38);
  KeInitializeSpinLock(puVar6 + 8);
  KeInitializeSpinLock(puVar6 + 0x2e6);
  *(undefined8 *)(puVar6 + 0x10) = 0;
  puVar6[0xe] = 1;
  puVar6[0x12] = 0;
  KeInitializeEvent(puVar6 + 0x14,1,0);
  uVar9 = *(undefined8 *)(*(longlong *)((longlong)param_1 + 0x598) + 0xab0);
  *(undefined1 *)(puVar6 + 0x2d0) = 1;
  *(undefined8 *)(puVar6 + 0x2ae) = uVar9;
  *(undefined8 *)(puVar6 + 0x2c2) = 0;
  *(undefined8 *)(puVar6 + 0x2be) = 0;
  puVar6[0x2b0] = 0;
  *(undefined8 *)(puVar6 + 0x2c0) = 0;
  *(undefined8 *)(puVar6 + 0x2ba) = 0;
  puVar6[700] = 0;
  puVar6[0x1e] = 0x10000;
  lVar7 = ExAllocatePool2(0x40,0x200,0x6d446453);
  *(longlong *)(puVar6 + 0x2c0) = lVar7;
  if (lVar7 != 0) {
    uVar13 = 0;
    lVar7 = IoAllocateMdl(lVar7,0x200,0,0,0);
    *(longlong *)(puVar6 + 0x2be) = lVar7;
    if (lVar7 != 0) {
      MmBuildMdlForNonPagedPool(lVar7);
      if (puVar6[0x2d5] == 2) {
        uVar3 = *(undefined4 *)(*(longlong *)((longlong)param_1 + 0x598) + 0xad8);
        puVar6[0x2b8] = uVar3;
        pvVar8 = (void *)MmAllocateContiguousNodeMemory
                                   (uVar3,0,0xffffffff,0x10000,CONCAT44(uVar13,0x204),0x80000000);
        if (pvVar8 == (void *)0x0) goto LAB_1c00044fd;
        memset(pvVar8,0,(ulonglong)(uint)puVar6[0x2b8]);
        *(void **)(puVar6 + 0x2b6) = pvVar8;
        uVar9 = MmGetPhysicalAddress(pvVar8);
        *(undefined8 *)(puVar6 + 0x2b4) = uVar9;
        uVar13 = *(undefined4 *)(*(longlong *)((longlong)param_1 + 0x598) + 0xae8);
        puVar6[700] = uVar13;
        lVar7 = ExAllocatePool2(0x40,uVar13,0x4c446453);
        if (lVar7 == 0) goto LAB_1c00044fd;
        *(longlong *)(puVar6 + 0x2ba) = lVar7;
      }
      puVar1 = puVar6 + 0x2f4;
      puVar6[0x2fc] = 0;
      *(undefined4 **)(puVar6 + 0x2f6) = puVar1;
      *(undefined4 **)puVar1 = puVar1;
      puVar1 = puVar6 + 0x2f8;
      *(undefined4 **)(puVar6 + 0x2fa) = puVar1;
      *(undefined4 **)puVar1 = puVar1;
      memset(puVar6 + 0x37c,0,0x1000);
      puVar6[0x374] = 0;
      puVar6[0x375] = 0x7f;
      *(undefined4 **)(puVar6 + 0x37a) = puVar6 + 0x774;
      *(undefined4 **)(puVar6 + 0x376) = puVar6 + 0x37c;
      *(undefined8 *)(puVar6 + 0x378) = 0;
      *(undefined8 *)(puVar6 + 0xe48) = 0;
      *(undefined8 *)(puVar6 + 0xe4a) = 0;
      *(undefined8 *)(puVar6 + 0xe4c) = 0;
      *(undefined8 *)(puVar6 + 0xe4e) = 0;
      *(undefined8 *)(puVar6 + 0xe50) = 0;
      pvVar8 = *(void **)(*(longlong *)((longlong)param_1 + 0x598) + 8);
      lVar7 = *(longlong *)((longlong)pvVar8 + 0xb0);
      lVar10 = IoAllocateIrp(*(undefined1 *)(lVar7 + 0x4c),0);
      if (lVar10 != 0) {
        lVar4 = *(longlong *)(lVar10 + 0xb8);
        *(undefined4 *)(lVar10 + 0x30) = 0xc00000bb;
        *(undefined2 *)(lVar4 + -0x48) = 0x81b;
        *(undefined **)(lVar4 + -0x40) = &GUID_QUERY_CRASHDUMP_FUNCTIONS;
        *(undefined4 *)(lVar4 + -0x38) = 0x10028;
        *(undefined4 **)(lVar4 + -0x30) = puVar6 + 0xe48;
        *(undefined8 *)(lVar4 + -0x28) = 0;
        IoSynchronousCallDriver(lVar7,lVar10);
        IoFreeIrp(lVar10);
      }
      puVar1 = puVar6 + 0x790;
      memcpy(puVar1,pvVar8,0x14b8);
      *(undefined4 **)(puVar6 + 4) = puVar1;
      *(undefined1 *)(puVar6 + 0xca9) = 1;
      *(undefined4 **)(puVar6 + 0xcaa) = _Dst;
      *(undefined1 *)(puVar6 + 0x7ca) = 1;
      puVar11 = (undefined8 *)ExAllocatePool2(0x40,0x90,0x64446453);
      plVar2 = (longlong *)(puVar6 + 0x7c0);
      *plVar2 = (longlong)puVar11;
      if (puVar11 != (undefined8 *)0x0) {
        puVar5 = *(undefined8 **)((longlong)pvVar8 + 0xc0);
        uVar9 = puVar5[1];
        *puVar11 = *puVar5;
        puVar11[1] = uVar9;
        uVar9 = puVar5[3];
        puVar11[2] = puVar5[2];
        puVar11[3] = uVar9;
        uVar9 = puVar5[5];
        puVar11[4] = puVar5[4];
        puVar11[5] = uVar9;
        uVar9 = puVar5[7];
        puVar11[6] = puVar5[6];
        puVar11[7] = uVar9;
        uVar9 = puVar5[9];
        puVar11[8] = puVar5[8];
        puVar11[9] = uVar9;
        uVar9 = puVar5[0xb];
        puVar11[10] = puVar5[10];
        puVar11[0xb] = uVar9;
        uVar9 = puVar5[0xd];
        puVar11[0xc] = puVar5[0xc];
        puVar11[0xd] = uVar9;
        uVar9 = puVar5[0xf];
        puVar11[0xe] = puVar5[0xe];
        puVar11[0xf] = uVar9;
        uVar9 = puVar5[0x11];
        puVar11[0x10] = puVar5[0x10];
        puVar11[0x11] = uVar9;
        SdhostInitializePoFxDbgLog((longlong)puVar1);
        uVar12 = *(uint *)(*plVar2 + 0x88) + 0x10;
        if ((*(uint *)(*plVar2 + 0x88) <= uVar12) && (0xf < uVar12)) {
          puVar11 = (undefined8 *)ExAllocatePool2(0x40,uVar12,0x65536453);
          *(undefined8 **)(puVar6 + 0x7cc) = puVar11;
          if (puVar11 != (undefined8 *)0x0) {
            *puVar11 = plVar2;
            *(longlong *)(puVar6 + 0x2a4) = *(longlong *)(puVar6 + 0x7cc) + 0x10;
            memcpy(puVar6 + 0xcbe,param_1,0x610);
            *(undefined4 **)(puVar6 + 0xe24) = _Dst;
            return puVar6;
          }
        }
      }
    }
  }
LAB_1c00044fd:
  if (*(longlong *)(puVar6 + 0x2ba) != 0) {
    ExFreePoolWithTag(*(longlong *)(puVar6 + 0x2ba),0x4c446453);
  }
  if (*(longlong *)(puVar6 + 0x2b6) != 0) {
    MmFreeContiguousMemory();
  }
  if (*(longlong *)(puVar6 + 0x2be) != 0) {
    IoFreeMdl();
  }
  if (*(longlong *)(puVar6 + 0x2c0) != 0) {
    ExFreePoolWithTag(*(longlong *)(puVar6 + 0x2c0),0x6d446453);
  }
  if (*(longlong *)(puVar6 + 0x7c0) != 0) {
    ExFreePoolWithTag(*(longlong *)(puVar6 + 0x7c0),0x64446453);
  }
  ExFreePoolWithTag(puVar6,0x64446453);
  return (undefined4 *)0x0;
}



===== SdhostDumpDevicePowerOn @ 1c00045d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdhostDumpDevicePowerOn(int *param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0x53646453)) {
    uVar1 = 0xc000000d;
  }
  else if ((char)param_1[0xe44] == '\0') {
    uVar1 = 0xc00000bb;
  }
  else {
    if ((*(code **)(param_1 + 0xe50) != (code *)0x0) &&
       (uVar1 = (**(code **)(param_1 + 0xe50))(*(undefined8 *)(param_1 + 0xe4a)), (int)uVar1 < 0)) {
      return uVar1;
    }
    if ((*(longlong *)(*(longlong *)(param_1 + 4) + 0x1b0) != 0) &&
       (uVar1 = PoFxPowerOnCrashdumpDevice(*(longlong *)(*(longlong *)(param_1 + 4) + 0x1b0),0),
       (int)uVar1 < 0)) {
      return uVar1;
    }
    if (*(undefined1 **)(param_1 + 0xe46) != (undefined1 *)0x0) {
      **(undefined1 **)(param_1 + 0xe46) = 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== SdhostFdoDeviceControl @ 1c000465c =====

undefined4 SdhostFdoDeviceControl(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if ((iVar1 == 0x43074) || (iVar1 == 0x43078)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000010;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== SdhostPdoDeviceControl @ 1c00046b0 =====

undefined4 SdhostPdoDeviceControl(longlong param_1,longlong param_2)

{
  int iVar1;
  void *pvVar2;
  longlong lVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  
  pvVar2 = *(void **)(param_1 + 0x40);
  if (pvVar2 == (void *)0x0) {
    uVar6 = 0xc000000e;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0xb8);
    iVar1 = *(int *)(lVar3 + 0x18);
    if (iVar1 == 0x41018) {
      uVar7 = 8;
      if (*(uint *)(lVar3 + 8) < 8) {
        uVar6 = 0xc0000023;
      }
      else {
        puVar5 = *(undefined4 **)(param_2 + 0x18);
        uVar6 = 0;
        *puVar5 = 8;
        *(undefined2 *)(puVar5 + 1) = 0;
        uVar7 = 0;
        *(undefined1 *)((longlong)puVar5 + 7) =
             *(undefined1 *)(*(longlong *)((longlong)pvVar2 + 0x598) + 4);
      }
      *(undefined8 *)(param_2 + 0x38) = uVar7;
    }
    else {
      if (iVar1 == 0x41020) {
        uVar6 = SdhostPdoScsiGetDumpPointers(pvVar2,param_2,param_2,pvVar2);
        return uVar6;
      }
      if (iVar1 == 0x41024) {
        uVar6 = SdhostPdoScsiFreeDumpPointers(0,param_2);
        return uVar6;
      }
      if (iVar1 == 0x43080) {
        return 0xc00000bb;
      }
      if (iVar1 == 0x2d1400) {
        uVar6 = SdhostPdoStorageQueryProperty((longlong)pvVar2,param_2);
        return uVar6;
      }
      if ((iVar1 == 0x2d5644) && (*(char *)(param_2 + 0x40) == '\0')) {
        if (*(uint *)(lVar3 + 0x10) < 0x10) {
          uVar6 = 0xc0000023;
        }
        else {
          piVar4 = *(int **)(param_2 + 0x18);
          if (((piVar4 == (int *)0x0) || (*piVar4 != 1)) || (piVar4[1] != 0x10)) {
            uVar6 = 0xc000000d;
          }
          else {
            uVar6 = 0;
            *(undefined8 *)(*(longlong *)((longlong)pvVar2 + 0x598) + 0xa90) =
                 *(undefined8 *)(piVar4 + 2);
          }
        }
      }
      else {
        uVar6 = 0xc0000010;
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    *(undefined4 *)(param_2 + 0x30) = uVar6;
  }
  IofCompleteRequest(param_2,0);
  return uVar6;
}



===== SdhostPdoScsiFreeDumpPointers @ 1c00047f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 SdhostPdoScsiFreeDumpPointers(undefined8 param_1,longlong param_2)

{
  int *_Dst;
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined4 uVar4;
  
  if (*(char *)(param_2 + 0x40) == '\0') {
    if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x68) {
      uVar4 = 0xc0000023;
    }
    else {
      _Dst = *(int **)(param_2 + 0x18);
      if ((*_Dst == 4) && (_Dst[1] == 0x68)) {
        lVar1 = *(longlong *)(_Dst + 2);
        if (lVar1 != 0) {
          if (*(longlong *)(lVar1 + 0xad8) != 0) {
            MmFreeContiguousMemory();
          }
          if (*(longlong *)(lVar1 + 0xae8) != 0) {
            ExFreePoolWithTag(*(longlong *)(lVar1 + 0xae8),0x4c446453);
          }
          if ((*(short *)(lVar1 + 0x3922) != 0) && (*(code **)(lVar1 + 0x3938) != (code *)0x0)) {
            (**(code **)(lVar1 + 0x3938))(*(undefined8 *)(lVar1 + 0x3928));
          }
          ExFreePoolWithTag(lVar1);
          _Dst[2] = 0;
          _Dst[3] = 0;
        }
        plVar3 = *(longlong **)(_Dst + 10);
        while (plVar3 != (longlong *)0x0) {
          plVar2 = (longlong *)*plVar3;
          if ((plVar2 == (longlong *)0x0) && (plVar3[10] != 0)) {
            ExFreePoolWithTag(plVar3[10],0);
          }
          ExFreePoolWithTag(plVar3);
          plVar3 = plVar2;
        }
        memset(_Dst,0,0x68);
        uVar4 = 0;
      }
      else {
        uVar4 = 0xc0000059;
      }
    }
  }
  else {
    uVar4 = 0xc0000010;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== SdhostPdoScsiGetDumpPointers @ 1c0004960 =====

undefined4
SdhostPdoScsiGetDumpPointers(void *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  
  uVar6 = 0;
  if (*(char *)(param_2 + 0x40) != '\0') {
    uVar7 = 0xc0000010;
    goto LAB_1c0004a94;
  }
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x68) {
    uVar7 = 0xc0000023;
LAB_1c0004a8f:
    uVar6 = 0x68;
  }
  else {
    puVar1 = *(undefined4 **)(param_2 + 0x18);
    lVar5 = param_2;
    puVar3 = SdhostBuildDumpData(param_1);
    if (puVar3 != (undefined4 *)0x0) {
      puVar4 = SdhostBuildDriverList((longlong)param_1,lVar5,param_3,param_4);
      if (puVar4 != (undefined8 *)0x0) {
        memset(puVar1 + 4,0,0x58);
        *puVar1 = 4;
        puVar1[1] = 0x68;
        *(undefined4 **)(puVar1 + 2) = puVar3;
        *(undefined8 *)(puVar1 + 4) = *(undefined8 *)(puVar3 + 0x2b6);
        puVar1[6] = puVar3[700];
        *(code **)(puVar1 + 0x16) = SdhostDumpDevicePowerOn;
        *(undefined1 *)(puVar1 + 7) = 0;
        puVar1[0xc] = 0xc;
        *(undefined8 *)(puVar1 + 8) = 0;
        puVar1[0xf] = 0x10000;
        *(undefined8 **)(puVar1 + 10) = puVar4;
        *(longlong *)(puVar1 + 0x14) = (longlong)param_1 + 0x5e4;
        *(undefined4 **)(puVar1 + 0x18) = puVar3;
        *(bool *)((longlong)param_1 + 0x5e4) = ForceCrashdumpNotReady == 0;
        lVar5 = *(longlong *)(*(longlong *)((longlong)param_1 + 0x598) + 8);
        if (*(longlong *)(lVar5 + 0x1b0) != 0) {
          iVar2 = PoFxRegisterCrashdumpDevice();
          if (-1 < iVar2) {
            *(undefined1 *)(puVar3 + 0xe44) = 1;
          }
        }
        PoFxSetComponentWake(*(undefined8 *)(lVar5 + 0x1b0),0,DisableFStatesCrashdump);
        uVar7 = 0;
        goto LAB_1c0004a8f;
      }
    }
    uVar7 = 0xc000009a;
  }
LAB_1c0004a94:
  *(undefined4 *)(param_2 + 0x30) = uVar7;
  *(undefined8 *)(param_2 + 0x38) = uVar6;
  IofCompleteRequest(param_2,0);
  return uVar7;
}



===== SdhostPdoStorageQueryProperty @ 1c0004ad0 =====

undefined4 SdhostPdoStorageQueryProperty(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  int *_Dst;
  int iVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if (*(uint *)(lVar3 + 0x10) < 0xc) {
    uVar7 = 0xc0000023;
    uVar6 = 0;
    goto LAB_1c0004c82;
  }
  lVar4 = *(longlong *)(param_1 + 0x598);
  _Dst = *(int **)(param_2 + 0x18);
  iVar5 = *_Dst;
  if (iVar5 == 1) {
    iVar5 = _Dst[1];
    if (iVar5 != 0) {
LAB_1c0004bcc:
      uVar6 = 0;
      if (iVar5 == 1) {
        uVar7 = 0;
        goto LAB_1c0004c82;
      }
LAB_1c0004bd1:
      uVar6 = 0;
      uVar7 = 0xc00000bb;
      goto LAB_1c0004c82;
    }
    uVar2 = *(uint *)(lVar3 + 8);
    if (uVar2 < 8) {
LAB_1c0004bea:
      uVar6 = 0;
      uVar7 = 0xc0000023;
      goto LAB_1c0004c82;
    }
    memset(_Dst,0,(ulonglong)uVar2);
    *_Dst = 0x20;
    _Dst[1] = 0x20;
    if (0x1f < uVar2) {
      _Dst[2] = *(int *)(lVar4 + 0x70);
      _Dst[3] = ((*(uint *)(lVar4 + 0x70) & 0xfff) != 0) + 1 + (*(uint *)(lVar4 + 0x70) >> 0xc);
      _Dst[4] = (*(uint *)(lVar4 + 0xb24) & 1) * 2 + 1;
      iVar5 = *(int *)(lVar4 + 0xb4c);
      *(undefined1 *)((longlong)_Dst + 0x17) = 0;
      *(undefined2 *)((longlong)_Dst + 0x15) = 0x100;
      *(bool *)(_Dst + 5) = iVar5 == 1;
      bVar1 = *(byte *)(lVar4 + 0xb08);
      *(undefined2 *)(_Dst + 7) = 0;
      *(ushort *)((longlong)_Dst + 0x1a) = (ushort)bVar1;
      *(undefined1 *)(_Dst + 6) = 0xc;
      uVar7 = 0;
      uVar6 = 0x20;
      goto LAB_1c0004c82;
    }
  }
  else if (iVar5 == 7) {
    iVar5 = _Dst[1];
    uVar6 = 0;
    if (iVar5 != 0) goto LAB_1c0004bcc;
    uVar2 = *(uint *)(lVar3 + 8);
    if (uVar2 < 8) {
      uVar7 = 0xc0000004;
      goto LAB_1c0004c82;
    }
    memset(_Dst,0,(ulonglong)uVar2);
    *_Dst = 0xc;
    _Dst[1] = 0xc;
    if (0xb < uVar2) {
      *(undefined1 *)(_Dst + 2) = 0;
      uVar7 = 0;
      uVar6 = 0xc;
      goto LAB_1c0004c82;
    }
  }
  else {
    if (iVar5 != 0x30) goto LAB_1c0004bd1;
    iVar5 = _Dst[1];
    if (iVar5 != 0) goto LAB_1c0004bcc;
    uVar2 = *(uint *)(lVar3 + 8);
    if (uVar2 < 8) goto LAB_1c0004bea;
    memset(_Dst,0,(ulonglong)uVar2);
    *_Dst = 0x10;
    _Dst[1] = 0x10;
    if (0xf < uVar2) {
      _Dst[2] = 1;
      _Dst[3] = (uint)*(byte *)(lVar4 + 0xb09);
      uVar7 = 0;
      uVar6 = 0x10;
      goto LAB_1c0004c82;
    }
  }
  uVar7 = 0;
  uVar6 = 8;
LAB_1c0004c82:
  *(undefined4 *)(param_2 + 0x30) = uVar7;
  *(undefined8 *)(param_2 + 0x38) = uVar6;
  IofCompleteRequest(param_2,0);
  return uVar7;
}



===== SdhostCardAndWakeInterruptEnable @ 1c0004cc0 =====

undefined8 SdhostCardAndWakeInterruptEnable(longlong param_1,undefined1 param_2,undefined1 param_3)

{
  undefined8 uVar1;
  longlong local_28;
  longlong lStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if ((*(uint *)(*(longlong *)(param_1 + 8) + 4) & 0x40000) == 0) {
    lStack_20 = (ulonglong)CONCAT11(param_3,param_2) << 8;
    local_18 = 0;
    uStack_10 = 0;
    local_28 = param_1;
    KeSynchronizeExecution
              (*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x13b8),SdhostCardInterruptSynchronize,
               &local_28);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc0000184;
  }
  return uVar1;
}



===== SdhostCardDetectDpc @ 1c0004d30 =====

void SdhostCardDetectDpc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = IoAllocateWorkItem(param_2);
  if (lVar1 != 0) {
    IoQueueWorkItemEx(lVar1,SdhostCardDetectWorker,1,param_3);
  }
  return;
}



===== SdhostCardDetectWorker @ 1c0004d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostCardDetectWorker(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  char cVar7;
  undefined4 local_res8 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar2 = *(longlong *)(lVar1 + 0xc0);
  if (*(longlong *)(lVar1 + 0x1b0) != 0) {
    PoFxActivateComponent(*(longlong *)(lVar1 + 0x1b0),0,1);
  }
  uVar6 = 0;
  if (*(char *)(lVar1 + 0x1464) != '\0') {
    do {
      lVar3 = *(longlong *)(lVar1 + 0x1468 + (ulonglong)uVar6 * 8);
      if (*(longlong *)(lVar1 + 0x1450) == 0) {
        cVar7 = (**(code **)(lVar2 + 0x68))(*(undefined8 *)(lVar3 + 0xa88));
LAB_1c0004e6e:
        if (cVar7 != *(char *)(lVar3 + 0xb3a)) {
          *(char *)(lVar3 + 0xb3a) = cVar7;
          if (cVar7 == '\0') {
            memset((void *)(lVar3 + 200),0,0x4e0);
            *(undefined4 *)(lVar3 + 0xb30) = 0;
            SdhostSlotStateChanged(lVar3);
          }
          else {
            ExAcquireFastMutex(lVar3 + 0x30);
            SdhostInitializeSlot(lVar3);
            ExReleaseFastMutex(lVar3 + 0x30);
            if (*(char *)(lVar3 + 0xb3a) != '\0') {
              if (*(longlong *)(lVar1 + 0x1458) == 0) {
                uVar4 = (**(code **)(lVar2 + 0x70))(*(undefined8 *)(lVar3 + 0xa88));
              }
              else {
                local_res8[0] = 0;
                ZwDeviceIoControlFile(*(undefined8 *)(lVar1 + 0x1458));
                uVar4 = (char)local_res8[0];
              }
              *(undefined1 *)(lVar3 + 0xb3b) = uVar4;
            }
          }
        }
      }
      else {
        local_res8[0] = 0;
        iVar5 = ZwDeviceIoControlFile
                          (*(undefined8 *)(lVar1 + 0x1450),0,0,0,&local_38,0x480000,0,0,local_res8,4
                          );
        if (-1 < iVar5) {
          cVar7 = (char)local_res8[0] == '\0';
          goto LAB_1c0004e6e;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(byte *)(lVar1 + 0x1464));
  }
  if (*(longlong *)(lVar1 + 0x1b0) != 0) {
    PoFxIdleComponent(*(longlong *)(lVar1 + 0x1b0),0,0);
  }
  IoFreeWorkItem(param_3);
  return;
}



===== SdhostCardInterruptSynchronize @ 1c0004fc0 =====

undefined8 SdhostCardInterruptSynchronize(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *param_1;
  lVar2 = *(longlong *)(lVar1 + 8);
  *(undefined1 *)(lVar2 + 0x13c9) = *(undefined1 *)((longlong)param_1 + 9);
  *(undefined1 *)(lVar2 + 0x13ca) = *(undefined1 *)((longlong)param_1 + 10);
  return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);
}



===== SdhostDisableEvents @ 1c0004fe4 =====

undefined8 SdhostDisableEvents(longlong param_1,uint param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_28 [3];
  uint local_10;
  undefined4 local_c;
  
  lVar1 = *(longlong *)(param_1 + 8);
  local_c = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  if ((*(uint *)(lVar1 + 4) & 0x40000) == 0) {
    local_28[0] = param_1;
    local_10 = param_2;
    if (*(char *)(param_1 + 0xb38) == '\0') {
      KeSynchronizeExecution
                (*(undefined8 *)(lVar1 + 0x13b8),SdhostInterruptSynchronizeDisable,local_28);
      if (((param_2 & 0xc0) != 0) && (*(longlong *)(lVar1 + 0x1400) != 0)) {
        KeSynchronizeExecution
                  (*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x1400),
                   SdhostInterruptSynchronizeDisable,local_28);
      }
    }
    else {
      SdhostInterruptSynchronizeDisable(local_28);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000184;
  }
  return uVar2;
}



===== SdhostEnableEvents @ 1c00050a4 =====

undefined8 SdhostEnableEvents(longlong param_1,uint param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_28 [3];
  uint local_10;
  undefined4 local_c;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if ((*(uint *)(lVar1 + 4) & 0x40000) == 0) {
    local_c = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[0] = param_1;
    local_10 = param_2;
    if (*(char *)(param_1 + 0xb38) == '\0') {
      KeSynchronizeExecution
                (*(undefined8 *)(lVar1 + 0x13b8),SdhostInterruptSynchronizeEnable,local_28);
      if (((param_2 & 0xc0) != 0) && (*(longlong *)(lVar1 + 0x1400) != 0)) {
        KeSynchronizeExecution
                  (*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x1400),
                   SdhostInterruptSynchronizeEnable,local_28);
      }
    }
    else {
      SdhostInterruptSynchronizeEnable(local_28);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000184;
  }
  return uVar2;
}



===== SdhostGpioInterrupt @ 1c0005170 =====

undefined1 SdhostGpioInterrupt(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x1448) != '\0') {
    KeInsertQueueDpc(param_2 + 0x1408,0,0);
  }
  return 1;
}



===== SdhostInterrupt @ 1c00051b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool SdhostInterrupt(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  undefined8 *puVar6;
  longlong lVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  bool bVar11;
  char local_res10 [8];
  char local_res18 [8];
  char local_res20 [8];
  uint local_38;
  uint local_34 [3];
  
  lVar7 = *(longlong *)(param_2 + 0x1468);
  iVar8 = 0;
  uVar10 = 0;
  if (*(char *)(param_2 + 0x1464) != '\0') {
    do {
      local_38 = 0;
      local_34[0] = 0;
      local_res10[0] = '\0';
      local_res18[0] = '\0';
      local_res20[0] = '\0';
      cVar5 = (**(code **)(*(longlong *)(param_2 + 0xc0) + 0x18))
                        (*(longlong *)(param_2 + 0xf0 + uVar10 * 8) + 0x10,&local_38,local_34,
                         local_res10,local_res18,local_res20);
      *(uint *)(lVar7 + 0xc30) = *(uint *)(lVar7 + 0xc30) | local_38;
      *(uint *)(lVar7 + 0xc34) = *(uint *)(lVar7 + 0xc34) | local_34[0];
      *(uint *)(lVar7 + 0xc30) = *(uint *)(lVar7 + 0xc30) & *(uint *)(lVar7 + 0xb34);
      if ((local_res10[0] != '\0') && ((*(uint *)(lVar7 + 0xb34) & 0xc0) != 0)) {
        LOCK();
        *(uint *)(lVar7 + 0xb8c) = *(uint *)(lVar7 + 0xb8c) | 0xc0;
        UNLOCK();
      }
      if ((local_res18[0] != '\0') && ((*(uint *)(lVar7 + 0xb34) & 0x100) != 0)) {
        LOCK();
        *(uint *)(lVar7 + 0xb8c) = *(uint *)(lVar7 + 0xb8c) | 0x100;
        UNLOCK();
        *(uint *)(lVar7 + 0xb34) = *(uint *)(lVar7 + 0xb34) & 0xfffffeff;
        (**(code **)(*(longlong *)(param_2 + 0xc0) + 0x38))
                  (*(longlong *)(param_2 + 0xf0 + (ulonglong)*(byte *)(lVar7 + 4) * 8) + 0x10,0x100,
                   0);
      }
      if ((local_res20[0] != '\0') && ((*(uint *)(lVar7 + 0xb34) & 0x1000) != 0)) {
        LOCK();
        *(uint *)(lVar7 + 0xb8c) = *(uint *)(lVar7 + 0xb8c) | 0x1000;
        UNLOCK();
      }
      uVar9 = *(uint *)(lVar7 + 0xc34);
      uVar3 = *(uint *)(lVar7 + 0xc30);
      uVar4 = *(uint *)(lVar7 + 0xb8c);
      LOCK();
      piVar1 = (int *)(lVar7 + 0xdc8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      puVar6 = (undefined8 *)
               ((ulonglong)(*(uint *)(lVar7 + 0xdcc) & iVar2 - 1U) * 0x20 +
               *(longlong *)(lVar7 + 0xdd0));
      *(undefined8 **)(lVar7 + 0xdd8) = puVar6;
      *puVar6 = 0x50727349;
      puVar6[1] = (ulonglong)uVar3;
      puVar6[2] = (ulonglong)uVar9;
      puVar6[3] = (ulonglong)uVar4;
      if (cVar5 != '\0') {
        iVar8 = 1 << ((byte)uVar10 & 0x1f);
      }
      uVar9 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar9;
      lVar7 = *(longlong *)(param_2 + 0x1468 + uVar10 * 8);
    } while (uVar9 < *(byte *)(param_2 + 0x1464));
    bVar11 = true;
    if (iVar8 == 0) goto LAB_1c0005382;
    KeInsertQueueDpc(*(longlong *)(param_2 + 8) + 200,0,0);
  }
  bVar11 = iVar8 == 0;
LAB_1c0005382:
  return !bVar11;
}



===== SdhostInterruptDpc @ 1c00053a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostInterruptDpc(undefined8 param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  short *psVar7;
  longlong lVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  longlong local_38;
  undefined8 uStack_30;
  uint uStack_2c;
  ulonglong local_28;
  undefined8 uStack_20;
  
  lVar3 = *(longlong *)(param_2 + 0x40);
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(uint *)(lVar3 + 4) & 0x40000) == 0) {
    lVar8 = *(longlong *)(lVar3 + 0x1468);
    uVar11 = 0;
    if (*(char *)(lVar3 + 0x1464) != '\0') {
      do {
        KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar8 + 0xb90,&local_68);
        uStack_20 = 0;
        uStack_30 = 0;
        local_28 = 0;
        local_38 = lVar8;
        KeSynchronizeExecution
                  (*(undefined8 *)(lVar3 + 0x13b8),SdhostSynchronizeEventProcessing,&local_38);
        for (puVar9 = *(undefined8 **)(lVar8 + 0xbd8); puVar9 != (undefined8 *)(lVar8 + 0xbd8);
            puVar9 = (undefined8 *)*puVar9) {
          KeAcquireInStackQueuedSpinLockAtDpcLevel(puVar9 + 0x1e,&local_50);
          lVar4 = *(longlong *)(lVar3 + 0xc0);
          lVar5 = *(longlong *)(lVar3 + 0xf0 + (ulonglong)*(byte *)(lVar8 + 4) * 8);
          LOCK();
          piVar1 = (int *)(lVar8 + 0xdc8);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          puVar6 = (undefined8 *)
                   ((ulonglong)(iVar2 - 1U & *(uint *)(lVar8 + 0xdcc)) * 0x20 +
                   *(longlong *)(lVar8 + 0xdd0));
          *(undefined8 **)(lVar8 + 0xdd8) = puVar6;
          *puVar6 = 0x4d637044;
          puVar6[1] = (ulonglong)uStack_2c;
          puVar6[2] = local_28 & 0xffffffff;
          puVar6[3] = puVar9 + -0xd;
          param_4 = local_28 & 0xffffffff;
          (**(code **)(lVar4 + 0x30))(lVar5 + 0x10,puVar9 + -0xd,uStack_2c);
          KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_50);
        }
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_68);
        uVar10 = (int)uVar11 + 1;
        uVar11 = (ulonglong)uVar10;
        lVar8 = *(longlong *)(lVar3 + 0x1468 + uVar11 * 8);
      } while (uVar10 < *(byte *)(lVar3 + 0x1464));
    }
    local_68 = 0;
    uStack_60 = 0;
    local_58 = 0;
    uVar11 = 0;
    psVar7 = *(short **)(lVar3 + 0x1468);
    if (*(char *)(lVar3 + 0x1464) != '\0') {
      do {
        KeAcquireInStackQueuedSpinLockAtDpcLevel(psVar7 + 0xc,&local_68);
        LOCK();
        uVar10 = *(uint *)(psVar7 + 0x5c6);
        *(uint *)(psVar7 + 0x5c6) = 0;
        UNLOCK();
        if ((uVar10 & 0xc0) != 0) {
          lVar8 = *(longlong *)(psVar7 + 4);
          SdhostQueueWorkItem(*(longlong *)(lVar8 + 8),*(longlong *)(lVar8 + 0x88),
                              SdhostInitializeSlotWorker,param_4,psVar7,*(int *)(lVar8 + 0x9c) == 0)
          ;
        }
        if ((uVar10 >> 8 & 1) != 0) {
          SdhostProcessSdioInterrupt((longlong)psVar7);
        }
        if ((uVar10 >> 0xc & 1) != 0) {
          lVar8 = *(longlong *)(psVar7 + 4);
          SdhostQueueWorkItem(*(longlong *)(lVar8 + 8),*(longlong *)(lVar8 + 0x88),
                              SdhostTuningWorker,param_4,psVar7,*(int *)(lVar8 + 0x9c) == 0);
        }
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_68);
        uVar10 = (int)uVar11 + 1;
        uVar11 = (ulonglong)uVar10;
        psVar7 = *(short **)(lVar3 + 0x1468 + uVar11 * 8);
      } while (uVar10 < *(byte *)(lVar3 + 0x1464));
    }
  }
  return;
}



===== SdhostInterruptSynchronizeDisable @ 1c0005640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdhostInterruptSynchronizeDisable(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *param_1;
  *(uint *)(lVar1 + 0xb34) = *(uint *)(lVar1 + 0xb34) & ~*(uint *)(param_1 + 3);
  uVar2 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0xc0) + 0x38))
                    (*(longlong *)
                      (*(longlong *)(lVar1 + 8) + 0xf0 + (ulonglong)*(byte *)(lVar1 + 4) * 8) + 0x10
                     ,(int)param_1[3],0);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== SdhostInterruptSynchronizeEnable @ 1c0005690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdhostInterruptSynchronizeEnable(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar1 = *param_1;
  *(uint *)(lVar1 + 0xb34) = *(uint *)(lVar1 + 0xb34) | *(uint *)(param_1 + 3);
  lVar2 = *(longlong *)(lVar1 + 8);
  uVar3 = (**(code **)(*(longlong *)(lVar2 + 0xc0) + 0x38))
                    (*(longlong *)(lVar2 + 0xf0 + (ulonglong)*(byte *)(lVar1 + 4) * 8) + 0x10,
                     (int)param_1[3],CONCAT71((int7)((ulonglong)lVar2 >> 8),1));
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== SdhostPassiveInterrupt @ 1c00056e0 =====

bool SdhostPassiveInterrupt(undefined8 param_1,longlong param_2)

{
  undefined1 uVar1;
  bool bVar2;
  
  if (*(longlong *)(param_2 + 0x1b0) != 0) {
    PoFxActivateComponent(*(longlong *)(param_2 + 0x1b0),0,1);
  }
  uVar1 = KfRaiseIrql(*(undefined1 *)(param_2 + 0x13b0));
  KeAcquireSpinLockAtDpcLevel(param_2 + 0x13a8);
  bVar2 = SdhostInterrupt(param_1,param_2);
  KeReleaseSpinLockFromDpcLevel(param_2 + 0x13a8);
  KeLowerIrql(uVar1);
  if (*(longlong *)(param_2 + 0x1b0) != 0) {
    PoFxIdleComponent(*(longlong *)(param_2 + 0x1b0),0,0);
  }
  return bVar2;
}



===== SdhostProcessSdioInterrupt @ 1c00057ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdhostProcessSdioInterrupt(longlong param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  bool bVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (*(char *)(param_1 + 0xd2) == '\0') {
    uVar5 = 0xc0000010;
  }
  else {
    if ((*(char *)(param_1 + 0xd2) == '\x01') || (*(int *)(param_1 + 0xdbc) == 1)) {
      for (lVar6 = *(longlong *)(param_1 + 0x10); lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0xa8)) {
        lVar6 = *(longlong *)(lVar6 + 0x40);
        local_18 = 0;
        local_28 = 0;
        uStack_20 = 0;
        KeAcquireInStackQueuedSpinLock(param_1 + 0xc98,&local_28);
        if ((*(uint *)(lVar6 + 0x608) & 0x10000) != 0) {
          if ((*(uint *)(lVar6 + 0x60c) & 2) == 0) {
            *(uint *)(param_1 + 0xdc0) =
                 *(uint *)(param_1 + 0xdc0) | 1 << (*(byte *)(lVar6 + 0xb0) & 0x1f);
            bVar8 = (*(uint *)(lVar6 + 0x608) & 0x20000) == 0;
            if (bVar8) {
              *(uint *)(lVar6 + 0x60c) = *(uint *)(lVar6 + 0x60c) | 1;
              KeClearEvent(param_1 + 0xc50);
              KeSetEvent(param_1 + 0xc38,0,0);
            }
            else {
              *(uint *)(lVar6 + 0x60c) = *(uint *)(lVar6 + 0x60c) | 2;
            }
            KeReleaseInStackQueuedSpinLock(&local_28);
            if (!bVar8) {
              uVar3 = *(uint *)(param_1 + 0xdb8);
              uVar4 = *(uint *)(lVar6 + 0x608);
              LOCK();
              piVar1 = (int *)(param_1 + 0xdc8);
              iVar2 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              puVar7 = (undefined8 *)
                       ((ulonglong)(*(uint *)(param_1 + 0xdcc) & iVar2 - 1U) * 0x20 +
                       *(longlong *)(param_1 + 0xdd0));
              *(undefined8 **)(param_1 + 0xdd8) = puVar7;
              puVar7[3] = 0;
              *puVar7 = 0x43496649;
              puVar7[1] = (ulonglong)uVar4;
              puVar7[2] = (ulonglong)uVar3;
              KeClearEvent(param_1 + 0xc50);
              (**(code **)(lVar6 + 0x5f8))(*(undefined8 *)(lVar6 + 0x600),0);
            }
          }
          else {
            KeReleaseInStackQueuedSpinLock(&local_28);
          }
          break;
        }
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
    }
    else {
      KeClearEvent(param_1 + 0xc50);
      KeSetEvent(param_1 + 0xc80,0,0);
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== SdhostQueryCardInterrupts @ 1c00059bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdhostQueryCardInterrupts(longlong param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (*(char *)(param_1 + 0xd2) != '\0') {
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    if ((*(int *)(*(longlong *)(param_1 + 8) + 0x80) == 1) &&
       ((*(uint *)(param_1 + 0x20) & 0x200000) != 0)) {
      piVar5 = (int *)SdhostAllocateRequestSynchronous(param_1);
      iVar4 = SdhostIssueCommandNoTransfer
                        (param_1,piVar5,(undefined8 *)&CmdReadWriteDirectSdio,0xa00,0,0,1);
      if (iVar4 < 0) {
        SdhostFreeRequestSynchronous((longlong)piVar5);
      }
      else {
        SdhostFreeRequestSynchronous((longlong)piVar5);
        uVar8 = (ulonglong)*(byte *)(piVar5 + 0x1e);
        LOCK();
        piVar5 = (int *)(param_1 + 0xdc8);
        iVar1 = *piVar5;
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        puVar7 = (undefined8 *)
                 ((ulonglong)(*(uint *)(param_1 + 0xdcc) & iVar1 - 1U) * 0x20 +
                 *(longlong *)(param_1 + 0xdd0));
        *(undefined8 **)(param_1 + 0xdd8) = puVar7;
        puVar7[2] = 0;
        puVar7[3] = 0;
        *puVar7 = 0x72494351;
        puVar7[1] = uVar8;
        for (lVar6 = *(longlong *)(param_1 + 0x10); lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0xa8))
        {
          lVar6 = *(longlong *)(lVar6 + 0x40);
          if (((uint)uVar8 >> (*(byte *)(lVar6 + 0xb0) & 0x1f) & 1) != 0) {
            KeAcquireInStackQueuedSpinLock(param_1 + 0xc98,&local_28);
            if ((*(uint *)(lVar6 + 0x608) & 0x50000) == 0x50000) {
              if ((*(uint *)(lVar6 + 0x60c) & 2) == 0) {
                *(uint *)(param_1 + 0xdc0) =
                     *(uint *)(param_1 + 0xdc0) | 1 << (*(byte *)(lVar6 + 0xb0) & 0x1f);
                KeReleaseInStackQueuedSpinLock(&local_28);
                uVar2 = *(uint *)(param_1 + 0xdb8);
                uVar3 = *(uint *)(lVar6 + 0x608);
                LOCK();
                piVar5 = (int *)(param_1 + 0xdc8);
                iVar1 = *piVar5;
                *piVar5 = *piVar5 + -1;
                UNLOCK();
                puVar7 = (undefined8 *)
                         ((ulonglong)(*(uint *)(param_1 + 0xdcc) & iVar1 - 1U) * 0x20 +
                         *(longlong *)(param_1 + 0xdd0));
                *(undefined8 **)(param_1 + 0xdd8) = puVar7;
                puVar7[3] = 0;
                puVar7[1] = (ulonglong)uVar3;
                *puVar7 = 0x43496649;
                puVar7[2] = (ulonglong)uVar2;
                (**(code **)(lVar6 + 0x5f8))(*(undefined8 *)(lVar6 + 0x600),0);
                goto LAB_1c0005ba5;
              }
            }
            else {
              uVar8 = (ulonglong)((uint)uVar8 & ~(1 << (*(byte *)(lVar6 + 0xb0) & 0x1f)));
            }
            KeReleaseInStackQueuedSpinLock(&local_28);
          }
LAB_1c0005ba5:
        }
        if ((char)uVar8 == '\0') {
          KeAcquireInStackQueuedSpinLock(param_1 + 0xc98,&local_28);
          if (*(int *)(param_1 + 0xdc0) == 0) {
            KeSetEvent(param_1 + 0xc50,0,0);
            SdhostEnableEvents(param_1,0x100);
          }
          KeReleaseInStackQueuedSpinLock(&local_28);
          iVar4 = 0;
        }
      }
      return iVar4;
    }
    KeAcquireInStackQueuedSpinLock(param_1 + 0xc98,&local_28);
    if (*(int *)(param_1 + 0xdc0) == 0) {
      KeSetEvent(param_1 + 0xc50,0,0);
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  return -0x3fffffff;
}



===== SdhostQueryInterruptsWorker @ 1c0005c90 =====

void SdhostQueryInterruptsWorker(longlong param_1)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 *in_stack_ffffffffffffffc8;
  longlong local_18;
  longlong local_10;
  
  local_10 = param_1 + 0xc80;
  local_18 = param_1 + 0xc68;
  while( true ) {
    KeWaitForMultipleObjects
              (2,&local_18,1,0,(ulonglong)in_stack_ffffffffffffffc8 & 0xffffffffffffff00,0,0,0);
    local_res8 = 0;
    in_stack_ffffffffffffffc8 = &local_res8;
    iVar1 = KeWaitForSingleObject(param_1 + 0xc68,0,0,0,in_stack_ffffffffffffffc8);
    if (iVar1 != 0x102) break;
    SdhostQueryCardInterrupts(param_1);
  }
  PsTerminateSystemThread(0);
  return;
}



===== SdhostSdioInterfaceAcknowledgeInt @ 1c0005d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdhostSdioInterfaceAcknowledgeInt(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  longlong lVar6;
  longlong lVar7;
  bool bVar8;
  undefined1 uVar9;
  undefined8 *puVar10;
  uint uVar11;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((((param_1 == (int *)0x0) || (*param_1 != 0x43494453)) ||
      (piVar5 = *(int **)(param_1 + 4), piVar5 == (int *)0x0)) || (*piVar5 != 2)) {
    return 0xc000000d;
  }
  lVar6 = *(longlong *)(piVar5 + 0x166);
  if (lVar6 != 0) {
    KeAcquireInStackQueuedSpinLock(lVar6 + 0xc98,&local_28);
    if ((piVar5[0x183] & 2U) != 0) {
      uVar11 = *(uint *)(lVar6 + 0xdc0);
      uVar3 = *(uint *)(lVar6 + 0xdb8);
      uVar4 = piVar5[0x182];
      LOCK();
      piVar1 = (int *)(lVar6 + 0xdc8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      puVar10 = (undefined8 *)
                ((ulonglong)(*(uint *)(lVar6 + 0xdcc) & iVar2 - 1U) * 0x20 +
                *(longlong *)(lVar6 + 0xdd0));
      *(undefined8 **)(lVar6 + 0xdd8) = puVar10;
      puVar10[1] = (ulonglong)uVar4;
      *puVar10 = 0x49414649;
      puVar10[2] = (ulonglong)uVar3;
      puVar10[3] = (ulonglong)uVar11;
      *(uint *)(lVar6 + 0xdc0) =
           *(uint *)(lVar6 + 0xdc0) & ~(1 << (*(byte *)(piVar5 + 0x2c) & 0x1f));
      piVar5[0x183] = piVar5[0x183] & 0xfffffffd;
      bVar8 = false;
      if ((*(int *)(lVar6 + 0xdc0) == 0) && ((*(uint *)(lVar6 + 0x20) & 0x200000) != 0)) {
        bVar8 = false;
        if ((*(uint *)(lVar6 + 0xb34) & 0x100) == 0) {
          bVar8 = true;
        }
      }
      if (*(int *)(lVar6 + 0xdc0) == 0) {
        KeSetEvent(lVar6 + 0xc50,0,0);
      }
      KeReleaseInStackQueuedSpinLock(&local_28);
      if (bVar8) {
        lVar7 = *(longlong *)(lVar6 + 8);
        if (*(longlong *)(lVar7 + 0x1b0) != 0) {
          PoFxActivateComponent(*(longlong *)(lVar7 + 0x1b0),0,0);
        }
        KeAcquireInStackQueuedSpinLock(lVar7 + 0x1d0,&local_28);
        if (*(char *)(lVar7 + 0x1d8) == '\0') {
          uVar11 = 1 << (*(byte *)(lVar6 + 4) & 0x1f);
          if ((uVar11 & *(uint *)(lVar7 + 0x13cc)) == 0) {
            uVar11 = *(uint *)(lVar7 + 0x13cc) | uVar11;
            *(uint *)(lVar7 + 0x13cc) = uVar11;
            SdhostPoFxAddDbgLog(lVar7,0x44656649,(ulonglong)uVar11,0,0);
            KeReleaseInStackQueuedSpinLock(&local_28);
            return 0;
          }
          KeReleaseInStackQueuedSpinLock(&local_28);
        }
        else {
          KeReleaseInStackQueuedSpinLock(&local_28);
          uVar9 = KfRaiseIrql(*(undefined1 *)(lVar7 + 0x13b0));
          KeAcquireSpinLockAtDpcLevel(lVar7 + 0x13a8);
          *(uint *)(lVar6 + 0xb34) = *(uint *)(lVar6 + 0xb34) | 0x100;
          if (*(char *)(lVar6 + 0xb39) == '\0') {
            (**(code **)(*(longlong *)(lVar7 + 0xc0) + 0x38))
                      (*(longlong *)(lVar7 + 0xf0 + (ulonglong)*(byte *)(lVar6 + 4) * 8) + 0x10,
                       0x100,1);
          }
          KeReleaseSpinLockFromDpcLevel(lVar7 + 0x13a8);
          KeLowerIrql(uVar9);
        }
        if (*(longlong *)(lVar7 + 0x1b0) != 0) {
          PoFxIdleComponent(*(longlong *)(lVar7 + 0x1b0),0,0);
        }
      }
      return 0;
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  return 0xc0000001;
}



===== SdhostSdioWorker @ 1c0006040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostSdioWorker(longlong param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 local_res8;
  undefined8 *in_stack_ffffffffffffff98;
  longlong local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_28 = 0;
  local_40 = param_1 + 0xc38;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = param_1 + 0xc68;
  while( true ) {
    KeWaitForMultipleObjects
              (2,&local_48,1,0,(ulonglong)in_stack_ffffffffffffff98 & 0xffffffffffffff00,0,0,0);
    local_res8 = 0;
    in_stack_ffffffffffffff98 = &local_res8;
    iVar4 = KeWaitForSingleObject(param_1 + 0xc68,0,0,0,in_stack_ffffffffffffff98);
    if (iVar4 != 0x102) break;
    for (lVar5 = *(longlong *)(param_1 + 0x10); lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0xa8)) {
      lVar5 = *(longlong *)(lVar5 + 0x40);
      KeAcquireInStackQueuedSpinLock(param_1 + 0xc98,&local_38);
      if ((*(uint *)(lVar5 + 0x60c) & 1) == 0) {
        KeReleaseInStackQueuedSpinLock(&local_38);
      }
      else {
        *(uint *)(lVar5 + 0x60c) = *(uint *)(lVar5 + 0x60c) | 2;
        *(uint *)(lVar5 + 0x60c) = *(uint *)(lVar5 + 0x60c) & 0xfffffffe;
        KeReleaseInStackQueuedSpinLock();
        uVar2 = *(uint *)(param_1 + 0xdb8);
        uVar3 = *(uint *)(lVar5 + 0x608);
        LOCK();
        piVar1 = (int *)(param_1 + 0xdc8);
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        puVar6 = (undefined8 *)
                 ((ulonglong)(*(uint *)(param_1 + 0xdcc) & iVar4 - 1U) * 0x20 +
                 *(longlong *)(param_1 + 0xdd0));
        *(undefined8 **)(param_1 + 0xdd8) = puVar6;
        puVar6[3] = 0;
        puVar6[1] = (ulonglong)uVar3;
        *puVar6 = 0x43496649;
        puVar6[2] = (ulonglong)uVar2;
        (**(code **)(lVar5 + 0x5f8))(*(undefined8 *)(lVar5 + 0x600),0);
      }
    }
  }
  PsTerminateSystemThread(0);
  return;
}



===== SdhostSynchronizeEventProcessing @ 1c00061f0 =====

undefined8 SdhostSynchronizeEventProcessing(longlong *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = *param_1;
  *(undefined4 *)((longlong)param_1 + 0xc) = *(undefined4 *)(lVar2 + 0xc30);
  *(undefined4 *)(param_1 + 2) = *(undefined4 *)(lVar2 + 0xc34);
  LOCK();
  uVar1 = *(undefined4 *)(lVar2 + 0xc30);
  *(undefined4 *)(lVar2 + 0xc30) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(lVar2 + 0xc34) = 0;
  UNLOCK();
  return CONCAT71((uint7)(uint3)((uint)uVar1 >> 8),1);
}



===== RESOURCE_HUB_STRING_PRINTF @ 1c0006220 =====

void RESOURCE_HUB_STRING_PRINTF
               (wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined8 in_stack_ffffffffffffffc8;
  
  local_res20 = param_4;
  RtlStringCbVPrintfExW
            (param_1,param_2,(longlong *)0x0,param_4,in_stack_ffffffffffffffc8,param_3,
             (va_list)&local_res20);
  return;
}



===== RESOURCE_HUB_UNICODE_STRING_PRINTF @ 1c0006250 =====

void RESOURCE_HUB_UNICODE_STRING_PRINTF
               (short *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined8 in_stack_ffffffffffffffc8;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res18 = param_3;
  local_res20 = param_4;
  iVar1 = RtlStringCbVPrintfExW
                    (*(wchar_t **)(param_1 + 4),(ulonglong)(ushort)param_1[1],local_18,param_4,
                     in_stack_ffffffffffffffc8,param_2,(va_list)&local_res18);
  if (-1 < iVar1) {
    *param_1 = (short)((longlong)(ulonglong)(uint)((int)local_18[0] - *(int *)(param_1 + 4)) >> 1) *
               2;
  }
  return;
}



===== RtlStringCbPrintfA @ 1c00062b4 =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

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



===== RtlStringCbVPrintfExW @ 1c0006328 =====

int RtlStringCbVPrintfExW
              (wchar_t *param_1,ulonglong param_2,longlong *param_3,undefined8 param_4,
              undefined8 param_5,wchar_t *param_6,va_list param_7)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong _Count;
  int iVar3;
  
  if (0x7ffffffe < (param_2 >> 1) - 1) {
    return -0x3ffffff3;
  }
  _Count = (param_2 >> 1) - 1;
  iVar3 = 0;
  iVar1 = _vsnwprintf(param_1,_Count,param_6,param_7);
  if (iVar1 < 0) {
LAB_1c0006396:
    iVar3 = -0x7ffffffb;
  }
  else {
    uVar2 = (ulonglong)iVar1;
    if (_Count < uVar2) goto LAB_1c0006396;
    if (uVar2 != _Count) {
      _Count = uVar2;
      goto LAB_1c000639d;
    }
  }
  param_1[_Count] = L'\0';
LAB_1c000639d:
  if (((-1 < iVar3) || (iVar3 == -0x7ffffffb)) && (param_3 != (longlong *)0x0)) {
    *param_3 = (longlong)(param_1 + _Count);
  }
  return iVar3;
}



===== SdhostCreatePdo @ 1c00063d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SdhostCreatePdo(longlong param_1,longlong *param_2,ulonglong param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  undefined1 auStack_128 [32];
  uint local_108;
  undefined1 local_100;
  longlong *local_f8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  char local_c8 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_128;
  uVar4 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1468 + (param_3 & 0xff) * 8);
  if ((*(char *)(lVar1 + 0x68) != '\0') && (uVar4 = 0, *(char *)(lVar1 + 0xba) == '\0')) {
    uVar4 = 1;
  }
  cVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0xc0) + 0x70))
                    (*(undefined8 *)(lVar1 + 0xa88));
  local_108 = 0xffff;
  uVar8 = uVar4 | 2;
  if (cVar3 == '\0') {
    uVar8 = uVar4;
  }
  uVar5 = RtlStringCbPrintfA(local_c8,0x80,"%s-%d","\\Device\\SdBus");
  if (-1 < (int)uVar5) {
    RtlInitAnsiString(&local_d8,local_c8);
    local_e8 = 0;
    uStack_e0 = 0;
    uVar5 = RtlAnsiStringToUnicodeString(&local_e8,&local_d8,1);
    if (-1 < (int)uVar5) {
      iVar7 = 0;
      do {
        local_108 = iVar7;
        uVar6 = RtlStringCbPrintfA(local_c8,0x80,"%s-%d","\\Device\\SdBus");
        uVar5 = uVar6 & 0xffffffff;
        if ((int)uVar6 < 0) {
LAB_1c000665a:
          RtlFreeUnicodeString(&local_e8);
          goto LAB_1c000666d;
        }
        iVar7 = iVar7 + 1;
        RtlInitAnsiString(&local_d8,local_c8);
        uVar4 = RtlAnsiStringToUnicodeString(&local_e8,&local_d8,0);
        uVar5 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) goto LAB_1c000665a;
        local_100 = 0;
        local_108 = uVar8;
        local_f8 = param_2;
        uVar4 = IoCreateDevice(*(undefined8 *)(param_1 + 8),0x610,&local_e8,0x22);
        uVar5 = (ulonglong)uVar4;
      } while ((uVar4 == 0x40000000) || (uVar4 == 0xc0000035));
      RtlFreeUnicodeString(&local_e8);
      if (-1 < (int)uVar4) {
        uVar8 = 7;
        uVar4 = *(uint *)(*param_2 + 0x98);
        if ((*(uint *)(lVar1 + 0xb24) & 1) == 0) {
          uVar8 = 3;
        }
        if (uVar8 < uVar4) {
          uVar8 = uVar4;
        }
        *(uint *)(*param_2 + 0x98) = uVar8;
        puVar2 = *(undefined4 **)(*param_2 + 0x40);
        memset(puVar2 + 1,0,0x60c);
        *puVar2 = 2;
        *(longlong *)(puVar2 + 2) = *param_2;
        *(longlong *)(puVar2 + 0x28) = param_1;
        puVar2[0x20] = 1;
        puVar2[0x21] = 4;
        *(undefined8 *)(puVar2 + 0x2a) = *(undefined8 *)(lVar1 + 0x10);
        *(longlong *)(puVar2 + 0x166) = lVar1;
        *(longlong *)(lVar1 + 0x10) = *param_2;
        local_108 = 0x20;
        IoInitializeRemoveLockEx(puVar2 + 0x18,0x6c526453,1,100);
        puVar2[6] = 0;
        puVar2[7] = 0;
        *(uint *)(*param_2 + 0x30) = *(uint *)(*param_2 + 0x30) | 0x2000;
        *(uint *)(*param_2 + 0x30) = *(uint *)(*param_2 + 0x30) & 0xffffff7f;
        uVar4 = *(uint *)(*param_2 + 0x98);
        if (uVar4 <= *(uint *)(lVar1 + 0xb1c)) {
          uVar4 = *(uint *)(lVar1 + 0xb1c);
        }
        *(uint *)(*param_2 + 0x98) = uVar4;
      }
    }
  }
LAB_1c000666d:
  return uVar5;
}



===== SdhostDeviceResetInterfaceDereference @ 1c00066a0 =====

void SdhostDeviceResetInterfaceDereference(int *param_1)

{
  if ((((param_1 != (int *)0x0) && (*param_1 == 0x43455253)) &&
      (*(int **)(param_1 + 2) != (int *)0x0)) &&
     ((**(int **)(param_1 + 2) == 2 && (param_1[-2] == 0)))) {
    param_1[-6] = 0;
    ExFreePoolWithTag(param_1 + -6,0x63496453);
  }
  return;
}



===== SdhostDeviceResetInterfaceReference @ 1c00066f0 =====

void SdhostDeviceResetInterfaceReference(int *param_1)

{
  if ((((param_1 != (int *)0x0) && (*param_1 == 0x43455253)) &&
      (*(int **)(param_1 + 2) != (int *)0x0)) && (**(int **)(param_1 + 2) == 2)) {
    param_1[4] = param_1[4] + 1;
  }
  return;
}



===== SdhostDeviceResetInterfaceReset @ 1c0006720 =====

int SdhostDeviceResetInterfaceReset(int *param_1,int param_2,undefined8 param_3,int *param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  undefined8 uVar6;
  int *piVar7;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0x43455253)) {
    iVar3 = -0x3ffffff3;
  }
  else {
    piVar1 = *(int **)(param_1 + 2);
    if ((piVar1 == (int *)0x0) || (*piVar1 != 2)) {
      iVar3 = -0x3ffffff0;
    }
    else {
      uVar6 = param_3;
      piVar7 = param_4;
      cVar2 = KeGetCurrentIrql();
      if (cVar2 == '\0') {
        iVar3 = SdhostPdoDeviceReset((longlong)piVar1,param_2,uVar6,param_4);
      }
      else {
        lVar4 = IoAllocateWorkItem(*(undefined8 *)(piVar1 + 0x28));
        if ((lVar4 != 0) &&
           (piVar5 = (int *)ExAllocatePool2(0x40,0x18,0x78524453), piVar5 != (int *)0x0)) {
          *piVar5 = param_2;
          piVar5[1] = (int)param_3;
          *(int **)(piVar5 + 2) = piVar1;
          *(int **)(piVar5 + 4) = param_4;
          SdhostQueueWorkItem(*(longlong *)(piVar1 + 0x28),lVar4,SdhostPdoDeviceResetWorker,piVar7,
                              (short *)piVar5,'\0');
          return 0x103;
        }
        iVar3 = -0x3fffff66;
      }
    }
  }
  return iVar3;
}



===== SdhostEnumerateHost @ 1c0006834 =====

undefined8 SdhostEnumerateHost(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  bVar3 = 0;
  if (*(char *)(lVar1 + 0x1464) != '\0') {
    do {
      SdhostEnumerateSlotPdos(param_1,bVar3);
      bVar3 = bVar3 + 1;
    } while (bVar3 < *(byte *)(lVar1 + 0x1464));
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  bVar3 = 0;
  *(undefined4 *)(lVar1 + 0x14a8) = 0;
  *(undefined4 *)(lVar1 + 0x14b0) = 0;
  *(undefined4 *)(lVar1 + 0x14ac) = 0;
  lVar2 = *(longlong *)(lVar1 + 0x1468);
  if (*(char *)(lVar1 + 0x1464) != '\0') {
    do {
      for (lVar2 = *(longlong *)(lVar2 + 0x10); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0xa8)) {
        lVar2 = *(longlong *)(lVar2 + 0x40);
        if ((*(uint *)(lVar2 + 4) & 1) == 0) {
          *(int *)(lVar1 + 0x14a8) = *(int *)(lVar1 + 0x14a8) + 1;
          if (*(int *)(lVar2 + 0x84) == 1) {
            *(int *)(lVar1 + 0x14b0) = *(int *)(lVar1 + 0x14b0) + 1;
          }
          if (*(int *)(lVar2 + 0x18) == 1) {
            *(int *)(lVar1 + 0x14ac) = *(int *)(lVar1 + 0x14ac) + 1;
          }
        }
        else {
          *(uint *)(lVar2 + 4) = *(uint *)(lVar2 + 4) | 2;
        }
      }
      bVar3 = bVar3 + 1;
      lVar2 = *(longlong *)(lVar1 + 0x1468 + (ulonglong)bVar3 * 8);
    } while (bVar3 < *(byte *)(lVar1 + 0x1464));
  }
  if (*(int *)(lVar1 + 0x14ac) < *(int *)(lVar1 + 0x14a8)) {
    if (*(longlong *)(lVar1 + 0x1b0) != 0) {
      PoFxSetDeviceIdleTimeout(*(longlong *)(lVar1 + 0x1b0),DeviceIdleTimeout);
    }
  }
  return 0;
}



===== SdhostEnumerateSlotPdos @ 1c000693c =====

ulonglong SdhostEnumerateSlotPdos(longlong param_1,byte param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  ulonglong uVar10;
  byte bVar11;
  longlong local_res8;
  
  uVar10 = 0;
  local_res8 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1468 + (ulonglong)param_2 * 8);
  if (*(int *)(lVar1 + 0xb30) == 1) {
    uVar10 = 0;
    if (*(int *)(lVar1 + 0xd4) - 2U < 2) {
      uVar6 = SdhostCreatePdo(param_1,&local_res8,(ulonglong)param_2);
      uVar10 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        lVar9 = 9;
        lVar2 = *(longlong *)(local_res8 + 0x40);
        *(undefined1 *)(lVar2 + 0xb0) = 8;
        *(undefined4 *)(lVar2 + 0xb4) = *(undefined4 *)(lVar1 + 0xd4);
        puVar4 = (undefined8 *)(lVar1 + 200);
        puVar5 = (undefined8 *)(lVar2 + 0xb8);
        do {
          puVar8 = puVar5;
          puVar7 = puVar4;
          uVar3 = puVar7[1];
          *puVar8 = *puVar7;
          puVar8[1] = uVar3;
          uVar3 = puVar7[3];
          puVar8[2] = puVar7[2];
          puVar8[3] = uVar3;
          uVar3 = puVar7[5];
          puVar8[4] = puVar7[4];
          puVar8[5] = uVar3;
          uVar3 = puVar7[7];
          puVar8[6] = puVar7[6];
          puVar8[7] = uVar3;
          uVar3 = puVar7[9];
          puVar8[8] = puVar7[8];
          puVar8[9] = uVar3;
          uVar3 = puVar7[0xb];
          puVar8[10] = puVar7[10];
          puVar8[0xb] = uVar3;
          uVar3 = puVar7[0xd];
          puVar8[0xc] = puVar7[0xc];
          puVar8[0xd] = uVar3;
          uVar3 = puVar7[0xf];
          puVar8[0xe] = puVar7[0xe];
          puVar8[0xf] = uVar3;
          lVar9 = lVar9 + -1;
          puVar4 = puVar7 + 0x10;
          puVar5 = puVar8 + 0x10;
        } while (lVar9 != 0);
        uVar3 = puVar7[0x11];
        puVar8[0x10] = puVar7[0x10];
        puVar8[0x11] = uVar3;
        uVar3 = puVar7[0x13];
        puVar8[0x12] = puVar7[0x12];
        puVar8[0x13] = uVar3;
        uVar3 = puVar7[0x15];
        puVar8[0x14] = puVar7[0x14];
        puVar8[0x15] = uVar3;
        uVar3 = puVar7[0x17];
        puVar8[0x16] = puVar7[0x16];
        puVar8[0x17] = uVar3;
        uVar3 = puVar7[0x19];
        puVar8[0x18] = puVar7[0x18];
        puVar8[0x19] = uVar3;
        uVar3 = puVar7[0x1b];
        puVar8[0x1a] = puVar7[0x1a];
        puVar8[0x1b] = uVar3;
      }
    }
    bVar11 = 1;
    if (*(char *)(lVar1 + 0xd2) != '\0') {
      do {
        uVar6 = SdhostCreatePdo(param_1,&local_res8,CONCAT71((int7)(uVar10 >> 8),param_2));
        uVar10 = uVar6 & 0xffffffff;
        if (-1 < (int)uVar6) {
          lVar9 = 9;
          lVar2 = *(longlong *)(local_res8 + 0x40);
          *(int *)(lVar2 + 0x5e0) = *(int *)(lVar2 + 0x5e0) + 1;
          *(byte *)(lVar2 + 0xb0) = bVar11;
          *(undefined4 *)(lVar2 + 0xb4) = 1;
          puVar4 = (undefined8 *)(lVar1 + 200);
          puVar5 = (undefined8 *)(lVar2 + 0xb8);
          do {
            puVar8 = puVar5;
            puVar7 = puVar4;
            uVar3 = puVar7[1];
            *puVar8 = *puVar7;
            puVar8[1] = uVar3;
            uVar3 = puVar7[3];
            puVar8[2] = puVar7[2];
            puVar8[3] = uVar3;
            uVar3 = puVar7[5];
            puVar8[4] = puVar7[4];
            puVar8[5] = uVar3;
            uVar3 = puVar7[7];
            puVar8[6] = puVar7[6];
            puVar8[7] = uVar3;
            uVar3 = puVar7[9];
            puVar8[8] = puVar7[8];
            puVar8[9] = uVar3;
            uVar3 = puVar7[0xb];
            puVar8[10] = puVar7[10];
            puVar8[0xb] = uVar3;
            uVar3 = puVar7[0xd];
            puVar8[0xc] = puVar7[0xc];
            puVar8[0xd] = uVar3;
            uVar3 = puVar7[0xf];
            puVar8[0xe] = puVar7[0xe];
            puVar8[0xf] = uVar3;
            lVar9 = lVar9 + -1;
            puVar4 = puVar7 + 0x10;
            puVar5 = puVar8 + 0x10;
          } while (lVar9 != 0);
          uVar3 = puVar7[0x11];
          puVar8[0x10] = puVar7[0x10];
          puVar8[0x11] = uVar3;
          uVar3 = puVar7[0x13];
          puVar8[0x12] = puVar7[0x12];
          puVar8[0x13] = uVar3;
          uVar3 = puVar7[0x15];
          puVar8[0x14] = puVar7[0x14];
          puVar8[0x15] = uVar3;
          uVar3 = puVar7[0x17];
          puVar8[0x16] = puVar7[0x16];
          puVar8[0x17] = uVar3;
          uVar3 = puVar7[0x19];
          puVar8[0x18] = puVar7[0x18];
          puVar8[0x19] = uVar3;
          uVar3 = puVar7[0x1b];
          puVar8[0x1a] = puVar7[0x1a];
          puVar8[0x1b] = uVar3;
        }
        bVar11 = bVar11 + 1;
      } while (bVar11 <= *(byte *)(lVar1 + 0xd2));
    }
  }
  *(undefined4 *)(lVar1 + 0xb30) = 2;
  return uVar10;
}



===== SdhostFdoFreeDeviceResources @ 1c0006b58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostFdoFreeDeviceResources(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  code *pcVar7;
  undefined8 *puVar8;
  byte bVar9;
  longlong lVar10;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  (**(code **)(*(longlong *)(lVar2 + 0xc0) + 0x80))();
  if (*(longlong *)(lVar2 + 0x13b8) != 0) {
    IoDisconnectInterrupt();
    *(undefined8 *)(lVar2 + 0x13b8) = 0;
  }
  if (*(longlong *)(lVar2 + 0x13c0) != 0) {
    IoDisconnectInterrupt();
    *(undefined8 *)(lVar2 + 0x13c0) = 0;
  }
  *(undefined1 *)(lVar2 + 0x1448) = 0;
  if (*(longlong *)(lVar2 + 0x1400) != 0) {
    IoDisconnectInterrupt();
    *(undefined8 *)(lVar2 + 0x1400) = 0;
  }
  if (*(longlong *)(lVar2 + 0x1450) != 0) {
    ZwClose();
    *(undefined8 *)(lVar2 + 0x1450) = 0;
  }
  if (*(longlong *)(lVar2 + 0x1458) != 0) {
    ZwClose();
    *(undefined8 *)(lVar2 + 0x1458) = 0;
  }
  bVar9 = 0;
  lVar10 = *(longlong *)(lVar2 + 0x1468);
  if (*(char *)(lVar2 + 0x1464) != '\0') {
    do {
      if (lVar10 != 0) {
        if (*(longlong *)(lVar10 + 0xae0) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar10 + 0xae0),0x4c446453);
          *(undefined8 *)(lVar10 + 0xae0) = 0;
        }
        if (*(longlong *)(lVar10 + 0xad0) != 0) {
          (**(code **)(*(longlong *)(*(longlong *)(lVar10 + 0xab0) + 8) + 0x18))
                    (*(longlong *)(lVar10 + 0xab0),*(undefined4 *)(lVar10 + 0xad8),
                     *(undefined8 *)(lVar10 + 0xac8),*(longlong *)(lVar10 + 0xad0),1);
          *(undefined8 *)(lVar10 + 0xad0) = 0;
        }
        if (*(longlong *)(lVar10 + 0xab0) != 0) {
          (**(code **)(*(longlong *)(*(longlong *)(lVar10 + 0xab0) + 8) + 8))();
        }
        if (*(longlong *)(lVar10 + 0xac0) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar10 + 0xac0),0x6d446453);
          *(undefined8 *)(lVar10 + 0xac0) = 0;
        }
        if (*(longlong *)(lVar10 + 0xaa0) != 0) {
          MmUnmapIoSpace(*(longlong *)(lVar10 + 0xaa0),*(undefined4 *)(lVar10 + 0xaa8));
          *(undefined8 *)(lVar10 + 0xaa0) = 0;
          *(undefined4 *)(lVar10 + 0xaa8) = 0;
        }
        plVar1 = (longlong *)(lVar10 + 0xbc8);
        while (plVar3 = (longlong *)*plVar1, plVar3 != plVar1) {
          if (((longlong *)plVar3[1] != plVar1) ||
             (lVar4 = *plVar3, (longlong *)*(longlong *)(lVar4 + 8) != plVar3)) goto LAB_1c0006e48;
          *plVar1 = lVar4;
          *(longlong **)(lVar4 + 8) = plVar1;
          ExFreePoolWithTag(plVar3 + -0xd,0x724d6453);
        }
        for (puVar8 = *(undefined8 **)(lVar10 + 0xbd8); puVar8 != (undefined8 *)(lVar10 + 0xbd8);
            puVar8 = (undefined8 *)*puVar8) {
          *(undefined4 *)((longlong)puVar8 + -4) = 0xc00000c0;
          SdhostCompleteRequestPostError((int *)(puVar8 + -0xd));
          ExFreePoolWithTag(puVar8 + -0xd,0x724d6453);
        }
        ExAcquireFastMutex(&TableListMutex);
        puVar8 = PrivateExtensionTableList;
        if ((undefined8 **)PrivateExtensionTableList != &PrivateExtensionTableList) {
          do {
            puVar5 = (undefined8 *)*puVar8;
            if (puVar8[-2] == lVar10) {
              if (((undefined8 *)puVar5[1] != puVar8) ||
                 (puVar6 = (undefined8 *)puVar8[1], (undefined8 *)*puVar6 != puVar8)) {
LAB_1c0006e48:
                pcVar7 = (code *)swi(0x29);
                (*pcVar7)(3);
                pcVar7 = (code *)swi(3);
                (*pcVar7)();
                return;
              }
              *puVar6 = puVar5;
              puVar5[1] = puVar6;
              ExFreePoolWithTag(puVar8 + -2,0x74586453);
              break;
            }
            puVar8 = puVar5;
          } while ((undefined8 **)puVar5 != &PrivateExtensionTableList);
        }
        ExReleaseFastMutex(&TableListMutex);
      }
      bVar9 = bVar9 + 1;
      lVar10 = *(longlong *)(lVar2 + 0x1468 + (ulonglong)bVar9 * 8);
    } while (bVar9 < *(byte *)(lVar2 + 0x1464));
  }
  return;
}



===== SdhostFdoStartDeviceComplete @ 1c0006e60 =====

undefined8
SdhostFdoStartDeviceComplete(longlong param_1,short *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(param_2 + 0x18) < 0) {
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18);
  }
  else {
    lVar2 = IoAllocateWorkItem();
    if (lVar2 != 0) {
      SdhostQueueWorkItem(*(longlong *)(lVar1 + 8),lVar2,SdhostFdoStartDeviceWorker,param_4,param_2,
                          '\0');
      return 0xc0000016;
    }
    param_2[0x18] = 0x9a;
    param_2[0x19] = -0x4000;
  }
  IoReleaseRemoveLockEx(lVar1 + 0x60,param_2,0x20);
  return 0;
}



===== SdhostFdoStopDevice @ 1c0006ee8 =====

undefined8 SdhostFdoStopDevice(longlong param_1)

{
  SdhostFdoFreeDeviceResources(*(longlong *)(param_1 + 8));
  return 0;
}



===== SdhostInitializePio @ 1c0006f04 =====

undefined8 SdhostInitializePio(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = ExAllocatePool2(0x40,0x200,0x6d446453);
  *(longlong *)(param_1 + 0xaf8) = lVar1;
  if (lVar1 != 0) {
    lVar1 = IoAllocateMdl(lVar1,0x200,0,0,0);
    *(longlong *)(param_1 + 0xaf0) = lVar1;
    if (lVar1 != 0) {
      MmBuildMdlForNonPagedPool(lVar1);
      return 0;
    }
  }
  if (*(longlong *)(param_1 + 0xaf8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xaf8),0x6d446453);
    *(undefined8 *)(param_1 + 0xaf8) = 0;
  }
  if (*(longlong *)(param_1 + 0xaf0) != 0) {
    IoFreeMdl();
  }
  return 0xc000009a;
}



===== SdhostInitializeScatterGatherDma @ 1c0006fd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SdhostInitializeScatterGatherDma(longlong param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined1 auStack_c8 [32];
  undefined4 *local_a8;
  undefined4 *local_a0;
  undefined4 local_88 [4];
  undefined4 local_78;
  undefined2 local_74;
  undefined1 local_70;
  undefined1 local_6f;
  byte local_6d;
  undefined4 local_6c;
  int local_64;
  undefined4 local_58;
  int local_50;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  local_88[0] = 0;
  memset(&local_78,0,0x40);
  lVar3 = *(longlong *)(param_1 + 8);
  local_78 = 3;
  local_74 = 0x101;
  local_6f = 0;
  local_6c = param_2;
  iVar2 = memcmp((void *)(lVar3 + 0x130),&GUID_BUS_TYPE_PCI,0x10);
  piVar1 = (int *)(param_1 + 0xab8);
  local_70 = 1;
  local_58 = *(undefined4 *)(param_1 + 0x70);
  uVar4 = *(uint *)(param_1 + 0xb24) >> 1;
  local_64 = (-(uint)(iVar2 != 0) & 0xc) + 5;
  local_6d = (byte)uVar4 & 1;
  local_50 = (-(uint)((uVar4 & 1) != 0) & 0x20) + 0x20;
  lVar3 = IoGetDmaAdapter(*(undefined8 *)(lVar3 + 0xa8),&local_78,piVar1);
  *(longlong *)(param_1 + 0xab0) = lVar3;
  if (lVar3 != 0) {
    uVar4 = *piVar1 * 0x1000 - 0x1000;
    if (uVar4 < *(uint *)(param_1 + 0x70)) {
      *(uint *)(param_1 + 0x70) = uVar4;
    }
    iVar2 = *piVar1 * *(int *)(param_1 + 0xb18);
    *(int *)(param_1 + 0xad8) = iVar2;
    lVar3 = (**(code **)(*(longlong *)(lVar3 + 8) + 0x10))(lVar3,iVar2,param_1 + 0xac8,0);
    *(longlong *)(param_1 + 0xad0) = lVar3;
    if (lVar3 != 0) {
      local_a0 = local_88;
      local_a8 = (undefined4 *)(param_1 + 0xae8);
      (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xab0) + 8) + 0x68))
                (*(longlong *)(param_1 + 0xab0),0,0,*piVar1 << 0xc);
      lVar3 = ExAllocatePool2(0x40,*(undefined4 *)(param_1 + 0xae8),0x4c446453);
      *(longlong *)(param_1 + 0xae0) = lVar3;
      if (lVar3 != 0) {
        lVar3 = ExAllocatePool2(0x40,0x200,0x6d446453);
        *(longlong *)(param_1 + 0xaf8) = lVar3;
        if (lVar3 != 0) {
          local_a8 = (undefined4 *)0x0;
          lVar3 = IoAllocateMdl(lVar3,0x200,0,0);
          *(longlong *)(param_1 + 0xaf0) = lVar3;
          if (lVar3 != 0) {
            MmBuildMdlForNonPagedPool(lVar3);
            return 0;
          }
        }
      }
    }
  }
  if (*(longlong *)(param_1 + 0xae0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xae0),0x4c446453);
    *(undefined8 *)(param_1 + 0xae0) = 0;
  }
  if (*(longlong *)(param_1 + 0xaf8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xaf8),0x6d446453);
    *(undefined8 *)(param_1 + 0xaf8) = 0;
  }
  if (*(longlong *)(param_1 + 0xaf0) != 0) {
    IoFreeMdl();
  }
  if ((*(longlong *)(param_1 + 0xad0) != 0) && (lVar3 = *(longlong *)(param_1 + 0xab0), lVar3 != 0))
  {
    local_a8 = (undefined4 *)CONCAT71(local_a8._1_7_,1);
    (**(code **)(*(longlong *)(lVar3 + 8) + 0x18))
              (lVar3,*(undefined4 *)(param_1 + 0xad8),*(undefined8 *)(param_1 + 0xac8));
    *(undefined4 *)(param_1 + 0xac8) = 0;
    *(undefined4 *)(param_1 + 0xacc) = 0;
    *(undefined8 *)(param_1 + 0xad0) = 0;
  }
  if (*(longlong *)(param_1 + 0xab0) != 0) {
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0xab0) + 8) + 8))();
    *(undefined8 *)(param_1 + 0xab0) = 0;
  }
  return 0xc000009a;
}



===== SdhostInitializeTransferMethod @ 1c00072b8 =====

void SdhostInitializeTransferMethod(longlong param_1,undefined4 param_2)

{
  if ((*(uint *)(param_1 + 0xb24) & 1) == 0) {
    *(undefined4 *)(param_1 + 0xb4c) = 1;
    SdhostInitializePio(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0xb4c) = 2;
    SdhostInitializeScatterGatherDma(param_1,param_2);
  }
  return;
}



===== SdhostMapSlotRegisterSpace @ 1c00072f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint SdhostMapSlotRegisterSpace(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  longlong lVar8;
  uint uVar9;
  byte bVar10;
  byte local_res8 [8];
  
  lVar3 = *(longlong *)(param_1 + 8);
  local_res8[0] = 0;
  uVar6 = 0;
  if ((*(longlong *)(lVar3 + 0x130) == 0x11d0b510c8ebdfb0) &&
     (*(longlong *)(lVar3 + 0x138) == -0x1cbdda365fff1a80)) {
    bVar10 = 0;
    if (*(code **)(lVar3 + 0x198) != (code *)0x0) {
      iVar5 = (**(code **)(lVar3 + 0x198))(*(undefined8 *)(lVar3 + 0x168),0,local_res8,0x40,1);
      if (iVar5 != 1) {
        return -(uint)(iVar5 != 1) & 0xc0000001;
      }
      bVar10 = local_res8[0];
    }
    local_res8[0] = bVar10 & 7;
    uVar6 = bVar10 & 0xffffff07;
    if (5 < local_res8[0]) {
      return 0xc0000001;
    }
  }
  uVar1 = *(uint *)(param_2 + 0x10);
  uVar9 = 0;
  pcVar7 = (char *)(param_2 + 0x14);
  if (uVar1 != 0) {
    do {
      if ((*pcVar7 == '\x03') && (uVar9 == *(byte *)(param_1 + 4) + uVar6)) break;
      uVar9 = uVar9 + 1;
      pcVar7 = pcVar7 + 0x14;
    } while (uVar9 < uVar1);
  }
  if (uVar1 <= uVar9) {
    return 0xc0000001;
  }
  uVar4 = *(undefined8 *)(pcVar7 + 4);
  *(undefined8 *)(param_1 + 0xa98) = uVar4;
  uVar2 = *(undefined4 *)(pcVar7 + 0xc);
  *(undefined4 *)(param_1 + 0xaa8) = uVar2;
  lVar8 = MmMapIoSpaceEx(uVar4,uVar2,0x204);
  *(longlong *)(param_1 + 0xaa0) = lVar8;
  if (lVar8 == 0) {
    return 0xc0000017;
  }
  uVar6 = (**(code **)(*(longlong *)(lVar3 + 0xc0) + 0x58))
                    (*(longlong *)(lVar3 + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8) + 0x10,
                     *(undefined8 *)(param_1 + 0xa98),lVar8,*(undefined4 *)(param_1 + 0xaa8),
                     *(undefined1 *)(param_1 + 0xb38));
  return uVar6;
}



===== SdhostPdoDeviceReset @ 1c000745c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdhostPdoDeviceReset(longlong param_1,int param_2,undefined8 param_3,int *param_4)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  cVar2 = KeGetCurrentIrql();
  if (cVar2 == '\0') {
    lVar1 = *(longlong *)(param_1 + 0x598);
    ExAcquireFastMutex(lVar1 + 0x30);
    uVar4 = SdhostPdoPowerDown(param_1);
    if ((param_2 == 0) || (param_2 == 1)) {
      iVar3 = SdhostPdoPowerUp(CONCAT44((int)((ulonglong)param_1 >> 0x20),uVar4));
    }
    else {
      iVar3 = -0x3ffffff3;
    }
    ExReleaseFastMutex(lVar1 + 0x30);
  }
  else {
    iVar3 = -0x3ffffff0;
  }
  if (((param_2 == 0) && (param_4 != (int *)0x0)) && (*param_4 == 0x18)) {
    (**(code **)(param_4 + 2))(iVar3,*(undefined8 *)(param_4 + 4));
  }
  return iVar3;
}



===== SdhostPdoDeviceResetWorker @ 1c0007520 =====

void SdhostPdoDeviceResetWorker(undefined8 param_1,int *param_2,undefined8 param_3)

{
  if (param_2 != (int *)0x0) {
    SdhostPdoDeviceReset(*(longlong *)(param_2 + 2),*param_2,param_3,*(int **)(param_2 + 4));
    ExFreePoolWithTag(param_2,0x78524453);
  }
  IoFreeWorkItem(param_3);
  return;
}



===== SdhostPdoQueryRemoveDevice @ 1c000757c =====

undefined8 SdhostPdoQueryRemoveDevice(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 0x9c) == 0) {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x598) + 8);
    iVar1 = *(int *)(param_1 + 0x18);
    if ((iVar1 != 0) && (iVar1 != 3)) {
      *(int *)(param_1 + 0x1c) = iVar1;
      *(undefined4 *)(param_1 + 0x18) = 4;
      LOCK();
      *(int *)(lVar2 + 0x14ac) = *(int *)(lVar2 + 0x14ac) + -1;
      UNLOCK();
      if (*(longlong *)(lVar2 + 0x1b0) != 0) {
        PoFxSetDeviceIdleTimeout(*(longlong *)(lVar2 + 0x1b0),DeviceIdleTimeout);
      }
    }
    SdhostPoFxAddDbgLog(lVar2,0x51526550,(longlong)*(int *)(param_1 + 0x84),
                        (longlong)*(int *)(lVar2 + 0x14b0),(longlong)*(int *)(lVar2 + 0x14ac));
    uVar3 = 0;
  }
  else {
    uVar3 = 0x80000011;
  }
  return uVar3;
}



===== SdhostPdoStartDeviceWorker @ 1c0007620 =====

void SdhostPdoStartDeviceWorker(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  
  if (param_2 != 0) {
    lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x28);
    lVar1 = *(longlong *)(lVar4 + 0x40);
    if (*(int *)(lVar1 + 0x18) == 1) {
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    else {
      lVar2 = *(longlong *)(lVar1 + 0x598);
      if ((*(char *)(lVar2 + 0x68) != '\0') && (*(char *)(lVar2 + 0xba) == '\0')) {
        *(uint *)(lVar4 + 0x34) = *(uint *)(lVar4 + 0x34) | 1;
      }
      *(undefined8 *)(lVar1 + 0x5a8) = 0;
      *(undefined4 *)(lVar1 + 0x5b0) = 0;
      *(undefined4 *)(lVar1 + 0x5a0) = 1;
      KeInitializeEvent(lVar1 + 0x5b8,1,0);
      lVar4 = IoAllocateWorkItem(lVar4);
      *(longlong *)(lVar1 + 0x88) = lVar4;
      if (lVar4 == 0) {
        iVar3 = -0x3fffff66;
      }
      else {
        lVar4 = *(longlong *)(lVar2 + 8);
        if (*(longlong *)(lVar4 + 0x1b0) != 0) {
          PoFxActivateComponent(*(longlong *)(lVar4 + 0x1b0),0,1);
        }
        lVar2 = lVar2 + 0x30;
        ExAcquireFastMutex(lVar2);
        iVar3 = SdhostPdoPowerUp(lVar1);
        if (iVar3 < 0) {
          ExReleaseFastMutex(lVar2);
        }
        else {
          LOCK();
          *(int *)(lVar4 + 0x14b0) = *(int *)(lVar4 + 0x14b0) + 1;
          UNLOCK();
          LOCK();
          *(int *)(lVar4 + 0x14ac) = *(int *)(lVar4 + 0x14ac) + 1;
          UNLOCK();
          *(undefined4 *)(lVar1 + 0x1c) = *(undefined4 *)(lVar1 + 0x18);
          *(undefined4 *)(lVar1 + 0x18) = 1;
          *(undefined4 *)(lVar1 + 0x84) = 1;
          SdhostPoFxAddDbgLog(lVar4,0x53746150,1,(longlong)*(int *)(lVar4 + 0x14b0),0);
          if ((*(int *)(lVar4 + 0x14ac) == *(int *)(lVar4 + 0x14a8)) &&
             (*(longlong *)(lVar4 + 0x1b0) != 0)) {
            PoFxSetDeviceIdleTimeout(*(longlong *)(lVar4 + 0x1b0),0);
          }
          ExReleaseFastMutex(lVar2);
          if (*(longlong *)(lVar4 + 0x1b0) != 0) {
            PoFxIdleComponent(*(longlong *)(lVar4 + 0x1b0),0,0);
          }
        }
      }
      *(int *)(param_2 + 0x30) = iVar3;
    }
    IofCompleteRequest(param_2,0);
    IoFreeWorkItem(param_3);
  }
  return;
}



===== SdhostPdoSurpriseRemoval @ 1c0007814 =====

ulonglong SdhostPdoSurpriseRemoval(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = SdhostPdoStopDevice(param_1);
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x598) + 8);
  if (((*(int *)(param_1 + 0x18) != 0) && (*(int *)(param_1 + 0x18) != 3)) &&
     ((*(uint *)(param_1 + 4) & 1) == 0)) {
    LOCK();
    *(int *)(lVar1 + 0x14ac) = *(int *)(lVar1 + 0x14ac) + -1;
    UNLOCK();
    if (*(longlong *)(lVar1 + 0x1b0) != 0) {
      PoFxSetDeviceIdleTimeout(*(longlong *)(lVar1 + 0x1b0),DeviceIdleTimeout);
    }
  }
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = 5;
  SdhostPoFxAddDbgLog(lVar1,0x53757250,(longlong)*(int *)(lVar1 + 0x14ac),
                      (longlong)*(int *)(lVar1 + 0x14b0),0);
  return uVar2 & 0xffffffff;
}



===== SdhostReenumerationInterfaceDereference @ 1c00078c0 =====

void SdhostReenumerationInterfaceDereference(int *param_1)

{
  if ((((param_1 != (int *)0x0) && (*param_1 == 0x43524453)) &&
      (*(int **)(param_1 + 2) != (int *)0x0)) &&
     ((**(int **)(param_1 + 2) == 2 && (param_1[-2] == 0)))) {
    param_1[-6] = 0;
    ExFreePoolWithTag(param_1 + -6,0x63496453);
  }
  return;
}



===== SdhostReenumerationInterfaceReenumerate @ 1c0007910 =====

void SdhostReenumerationInterfaceReenumerate(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (param_1 != (int *)0x0) {
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    if (((*param_1 == 0x43524453) && (piVar1 = *(int **)(param_1 + 2), piVar1 != (int *)0x0)) &&
       (*piVar1 == 2)) {
      lVar2 = *(longlong *)(piVar1 + 0x166);
      KeAcquireInStackQueuedSpinLock(lVar2 + 0xc98,&local_28);
      SdhostDisableEvents(lVar2,0x100);
      *(uint *)(lVar2 + 0x20) = *(uint *)(lVar2 + 0x20) & 0xffdfffff;
      KeReleaseInStackQueuedSpinLock(&local_28);
      *(undefined4 *)(lVar2 + 0xb30) = 0;
      *(undefined2 *)(lVar2 + 0x69) = 0x100;
      SdhostSlotStateChanged(lVar2);
    }
  }
  return;
}



===== SdhostReenumerationInterfaceReference @ 1c00079b0 =====

void SdhostReenumerationInterfaceReference(int *param_1)

{
  if ((((param_1 != (int *)0x0) && (*param_1 == 0x43524453)) &&
      (*(int **)(param_1 + 2) != (int *)0x0)) && (**(int **)(param_1 + 2) == 2)) {
    param_1[4] = param_1[4] + 1;
  }
  return;
}



===== SdhostSdioInitializeInterface @ 1c00079e0 =====

undefined8 SdhostSdioInitializeInterface(int *param_1,short *param_2)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined8 local_res8;
  undefined8 local_res18 [2];
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  
  local_40 = 0;
  uStack_38 = uStack_38 & 0xffffffff00000000;
  local_84 = 0;
  local_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((param_1 != (int *)0x0) && (*param_1 == 0x43494453)) &&
      (piVar1 = *(int **)(param_1 + 4), piVar1 != (int *)0x0)) && (*piVar1 == 2)) {
    if ((piVar1[0x182] & 0x40000U) != 0) {
      return 0xc0000001;
    }
    if (*param_2 == 0x28) {
      *(undefined8 *)(param_1 + 2) = *(undefined8 *)(param_2 + 4);
      lVar2 = *(longlong *)(piVar1 + 0x166);
      piVar1[0x182] = (uint)(ushort)param_2[1];
      *(undefined1 *)(lVar2 + 0xb39) = 0;
      if (((piVar1[0x182] & 2U) != 0) && (*(char *)(lVar2 + 0xb9) != '\0')) {
        *(undefined1 *)(lVar2 + 0xb39) = 1;
      }
      local_res8 = 0;
      if ((char)param_2[8] != '\0') {
        KeAcquireInStackQueuedSpinLock(lVar2 + 0xc98,&local_78);
        piVar1[0x182] = piVar1[0x182] | 0x10000;
        *(undefined8 *)(piVar1 + 0x17e) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(piVar1 + 0x180) = *(undefined8 *)(param_2 + 0x10);
        *(uint *)(lVar2 + 0xdb8) = *(uint *)(lVar2 + 0xdb8) | 1 << (*(byte *)(piVar1 + 0x2c) & 0x1f)
        ;
        *(int *)(lVar2 + 0xdbc) = *(int *)(lVar2 + 0xdbc) + 1;
        if (*(char *)((longlong)param_2 + 0x11) == '\0') {
          if ((*(uint *)(lVar2 + 0x20) & 0x100000) == 0) {
            *(uint *)(lVar2 + 0x20) = *(uint *)(lVar2 + 0x20) | 0x100000;
            KeReleaseInStackQueuedSpinLock(&local_78);
            KeInitializeEvent(lVar2 + 0xc38,1);
            KeInitializeEvent(lVar2 + 0xc68,0,0);
            local_60 = CONCAT44(local_60._4_4_,0x30);
            uStack_58 = 0;
            uStack_48 = CONCAT44(uStack_48._4_4_,0x200);
            local_50 = 0;
            local_40 = 0;
            uStack_38 = 0;
            iVar3 = PsCreateSystemThread(&local_res8,0,&local_60,0,0,SdhostSdioWorker,lVar2);
            if (-1 < iVar3) {
              local_res18[0] = 0;
              ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,local_res18,0);
              *(undefined8 *)(lVar2 + 0xda8) = local_res18[0];
              ZwClose(local_res8);
            }
            if (1 < *(byte *)(lVar2 + 0xd2)) {
              KeInitializeEvent(lVar2 + 0xc80,0,0);
              local_60 = CONCAT44(local_60._4_4_,0x30);
              uStack_58 = 0;
              uStack_48 = CONCAT44(uStack_48._4_4_,0x200);
              local_50 = 0;
              local_40 = 0;
              uStack_38 = 0;
              iVar3 = PsCreateSystemThread
                                (&local_res8,0,&local_60,0,0,SdhostQueryInterruptsWorker,lVar2);
              if (-1 < iVar3) {
                local_res18[0] = 0;
                ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,local_res18,0);
                *(undefined8 *)(lVar2 + 0xdb0) = local_res18[0];
                ZwClose(local_res8);
              }
            }
            KeAcquireInStackQueuedSpinLock(lVar2 + 0xc98,&local_78);
          }
        }
        else {
          piVar1[0x182] = piVar1[0x182] | 0x20000;
        }
        *(undefined1 *)(*(longlong *)(lVar2 + 8) + 0x13c8) = 1;
        KeReleaseInStackQueuedSpinLock(&local_78);
        local_88 = 1;
        local_80 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x13c0);
        IoReportInterruptActive(&local_88);
      }
      piVar1[0x182] = piVar1[0x182] | 0x40000;
      return 0;
    }
  }
  return 0xc000000d;
}



===== SdhostSdioInterfaceDereference @ 1c0007d60 =====

void SdhostSdioInterfaceDereference(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  longlong lVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (param_1 != (int *)0x0) {
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    if (((*param_1 == 0x43494453) && (piVar3 = *(int **)(param_1 + 4), piVar3 != (int *)0x0)) &&
       (*piVar3 == 2)) {
      piVar1 = piVar3 + 0x17a;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        lVar4 = *(longlong *)(piVar3 + 0x166);
        KeAcquireInStackQueuedSpinLock(lVar4 + 0xc98,&local_28);
        uVar2 = piVar3[0x182];
        piVar3[0x182] = uVar2 & 0xfffbffff;
        if ((uVar2 >> 0x10 & 1) != 0) {
          piVar3[0x182] = uVar2 & 0xfffaffff;
          if (((piVar3[0x183] & 2U) != 0) ||
             ((*(uint *)(lVar4 + 0xdc0) >> (*(byte *)(piVar3 + 0x2c) & 0x1f) & 1) != 0)) {
            *(uint *)(lVar4 + 0xdc0) =
                 *(uint *)(lVar4 + 0xdc0) & ~(1 << (*(byte *)(piVar3 + 0x2c) & 0x1f));
            piVar3[0x183] = piVar3[0x183] & 0xfffffffd;
          }
          *(uint *)(lVar4 + 0xdb8) =
               *(uint *)(lVar4 + 0xdb8) & ~(1 << (*(byte *)(piVar3 + 0x2c) & 0x1f));
          *(int *)(lVar4 + 0xdbc) = *(int *)(lVar4 + 0xdbc) + -1;
          if ((*(int *)(lVar4 + 0xdb8) == 0) && ((*(uint *)(lVar4 + 0x20) >> 0x14 & 1) != 0)) {
            *(uint *)(lVar4 + 0x20) = *(uint *)(lVar4 + 0x20) & 0xffefffff;
            KeSetEvent(lVar4 + 0xc68,0,0);
          }
        }
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
      piVar1 = param_1 + 8;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *param_1 = 0;
        if (*(longlong *)(piVar3 + 0x17c) != 0) {
          ExFreePoolWithTag(*(longlong *)(piVar3 + 0x17c),0x63496453);
        }
        *(int **)(piVar3 + 0x17c) = param_1;
      }
    }
  }
  return;
}



===== SdhostSdioInterfaceReference @ 1c0007f00 =====

void SdhostSdioInterfaceReference(int *param_1)

{
  int *piVar1;
  
  if ((((param_1 != (int *)0x0) && (*param_1 == 0x43494453)) &&
      (piVar1 = *(int **)(param_1 + 4), piVar1 != (int *)0x0)) && (*piVar1 == 2)) {
    piVar1[0x17a] = piVar1[0x17a] + 1;
    param_1[8] = param_1[8] + 1;
  }
  return;
}



===== SdhostUninitializeDevice @ 1c0007f2c =====

undefined8 SdhostUninitializeDevice(longlong param_1)

{
  SdhostDisableIrpQueue(*(longlong *)(param_1 + 0x598));
  return 0;
}



===== SdhostCompletePowerIrp @ 1c0007f4c =====

undefined4 SdhostCompletePowerIrp(longlong param_1,longlong param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x30) = param_3;
  PoStartNextPowerIrp(param_2);
  IofCompleteRequest(param_2,0);
  IoReleaseRemoveLockEx(param_1 + 0x60,param_2,0x20);
  return param_3;
}



===== SdhostFdoDeviceSetPower @ 1c0007fbc =====

undefined4
SdhostFdoDeviceSetPower(longlong param_1,short *param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = *(int *)(*(longlong *)(param_2 + 0x5c) + 0x18);
  if ((*(int *)(param_1 + 0x18) == 0) || (*(int *)(param_1 + 0x84) == iVar2)) {
    uVar3 = SdhostCompletePowerIrp(param_1,(longlong)param_2,0);
  }
  else if (*(char *)(param_1 + 0x1464) == '\0') {
    *(int *)(param_1 + 0x84) = iVar2;
    uVar3 = SdhostForwardPowerIrp(*(longlong *)(param_1 + 8),(longlong)param_2);
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0x5c) + 3);
    *pbVar1 = *pbVar1 | 1;
    SdhostQueueWorkItem(*(longlong *)(param_1 + 8),*(longlong *)(param_1 + 0x88),
                        SdhostFdoDeviceSetPowerWorker,param_4,param_2,*(int *)(param_1 + 0x9c) == 0)
    ;
    uVar4 = 0x44304671;
    if (iVar2 != 1) {
      uVar4 = 0x44784671;
    }
    SdhostPoFxAddDbgLog(param_1,uVar4,(longlong)*(int *)(param_1 + 0x14b0),0,0);
    uVar3 = 0x103;
  }
  return uVar3;
}



===== SdhostFdoDeviceSetPowerWorker @ 1c0008080 =====

void SdhostFdoDeviceSetPowerWorker(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int *piVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  byte bVar9;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uStack_40 = 0;
  local_48 = 0;
  local_44 = 0;
  if (*(int *)(lVar2 + 0x18) == 1) {
    iVar7 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (*(char *)(lVar2 + 0x1464) == '\0') {
      *(int *)(lVar2 + 0x84) = iVar7;
    }
    else if (*(int *)(lVar2 + 0x84) != iVar7) {
      ExAcquireFastMutex(lVar2 + 0x310);
      if (((*(int *)(lVar2 + 0x14a8) == 0) && (iVar7 == 1)) && (*(longlong *)(lVar2 + 0x2a8) != 0))
      {
        SdhostCompletePowerIrp(lVar2,*(longlong *)(lVar2 + 0x2a8),0);
        *(undefined8 *)(lVar2 + 0x2a8) = 0;
      }
      if (iVar7 == 1) {
        SdhostPoFxAddDbgLog(lVar2,0x44304653,(longlong)*(int *)(lVar2 + 0x14b0),0,0);
        uVar5 = SdhostForwardIrpSynchronous(*(undefined8 *)(lVar2 + 0xb0),param_2);
        local_48 = 1;
        uVar8 = uVar5 & 0xffffffff;
        iVar7 = (int)uVar5;
        uStack_40 = (undefined4)*(undefined8 *)(lVar2 + 0x13b8);
        uStack_3c = (undefined4)((ulonglong)*(undefined8 *)(lVar2 + 0x13b8) >> 0x20);
        IoReportInterruptActive(&local_48);
        if (*(char *)(lVar2 + 0x13c8) != '\0') {
          uStack_40 = (undefined4)*(undefined8 *)(lVar2 + 0x13c0);
          uStack_3c = (undefined4)((ulonglong)*(undefined8 *)(lVar2 + 0x13c0) >> 0x20);
          IoReportInterruptActive(&local_48);
        }
        if ((*(longlong *)(lVar2 + 0x1450) == 0) &&
           (lVar6 = *(longlong *)(lVar2 + 0x1400), lVar6 != 0)) {
          uStack_40 = (undefined4)lVar6;
          uStack_3c = (undefined4)((ulonglong)lVar6 >> 0x20);
          IoReportInterruptInactive(&local_48);
        }
        *(uint *)(lVar2 + 4) = *(uint *)(lVar2 + 4) & 0xfffbffff;
        bVar9 = 0;
        lVar6 = *(longlong *)(lVar2 + 0x1468);
        if (*(char *)(lVar2 + 0x1464) != '\0') {
          do {
            if ((*(char *)(lVar6 + 0xb3e) == '\0') && (*(char *)(lVar6 + 0xb3a) != '\0')) {
              uVar5 = SdhostInitializeSlot(lVar6);
              uVar8 = (ulonglong)(int)uVar5;
              if ((int)uVar5 < 0) {
                SdhostPoFxAddDbgLog(lVar2,0x44306572,(longlong)*(int *)(lVar2 + 0x14b0),uVar8,0);
                iVar7 = 0;
                break;
              }
            }
            iVar7 = (int)uVar8;
            bVar9 = bVar9 + 1;
            lVar6 = *(longlong *)(lVar2 + 0x1468 + (ulonglong)bVar9 * 8);
          } while (bVar9 < *(byte *)(lVar2 + 0x1464));
        }
        *(undefined4 *)(lVar2 + 0x84) = 1;
        SdhostCompletePowerIrp(lVar2,param_2,iVar7);
        if ((*(char *)(lVar2 + 0x1e1) != '\0') && (*(longlong *)(lVar2 + 0x1b0) != 0)) {
          *(undefined1 *)(lVar2 + 0x1e1) = 0;
          PoFxReportDevicePoweredOn();
        }
        SdhostPoFxAddDbgLog(lVar2,0x44304645,(longlong)*(int *)(lVar2 + 0x14b0),(longlong)iVar7,0);
      }
      else {
        SdhostPoFxAddDbgLog(lVar2,0x44784653,(longlong)*(int *)(lVar2 + 0x14b0),0,0);
        if ((*(int *)(lVar2 + 0x80) == 5) && (0 < *(int *)(lVar2 + 0x90))) {
          SdhostPoFxAddDbgLog(lVar2,0x44784645,(longlong)*(int *)(lVar2 + 0x14b0),
                              (longlong)*(int *)(lVar2 + 0x80),(longlong)*(int *)(lVar2 + 0x90));
          SdhostForwardPowerIrp(param_1,param_2);
        }
        else {
          *(int *)(lVar2 + 0x84) = iVar7;
          if ((*(int *)(lVar2 + 0x80) == 1) && (*(longlong *)(lVar2 + 0x1b0) != 0)) {
            PoFxCompleteDevicePowerNotRequired();
          }
          bVar9 = 0;
          lVar6 = *(longlong *)(lVar2 + 0x1468);
          if (*(char *)(lVar2 + 0x1464) != '\0') {
            do {
              if (*(longlong *)(lVar6 + 0x10) != 0) {
                piVar4 = (int *)SdhostAllocateRequestSynchronous(lVar6);
                lVar3 = *(longlong *)(lVar6 + 0x10);
                while ((lVar3 != 0 &&
                       (lVar3 = *(longlong *)(lVar3 + 0x40),
                       *(int *)(*(longlong *)(lVar6 + 8) + 0x14a8) != 0))) {
                  ExAcquireFastMutex(lVar6 + 0x30);
                  if (*(int *)(lVar3 + 0x84) == 1) {
                    iVar1 = *(int *)(lVar3 + 0xb4);
                    *(int *)(lVar3 + 0x84) = iVar7;
                    if (iVar1 == 1) {
                      SdhostPowerOffSdio(lVar3,piVar4);
                    }
                    else if (iVar1 == 2) {
                      SdhostPowerOffSd(lVar3,piVar4);
                    }
                    else if (iVar1 == 3) {
                      SdhostPowerOffMmc(lVar3,piVar4);
                    }
                    LOCK();
                    *(int *)(lVar2 + 0x14b0) = *(int *)(lVar2 + 0x14b0) + -1;
                    UNLOCK();
                  }
                  ExReleaseFastMutex(lVar6 + 0x30);
                  lVar3 = *(longlong *)(lVar3 + 0xa8);
                }
                SdhostFreeRequest((longlong)piVar4);
              }
              bVar9 = bVar9 + 1;
              lVar6 = *(longlong *)(lVar2 + 0x1468 + (ulonglong)bVar9 * 8);
            } while (bVar9 < *(byte *)(lVar2 + 0x1464));
          }
          if ((*(longlong *)(lVar2 + 0x1450) == 0) && (*(longlong *)(lVar2 + 0x1400) != 0)) {
            local_48 = 1;
            uStack_40 = (undefined4)*(undefined8 *)(lVar2 + 0x1400);
            uStack_3c = (undefined4)((ulonglong)*(undefined8 *)(lVar2 + 0x1400) >> 0x20);
            IoReportInterruptActive(&local_48);
          }
          if (*(longlong *)(lVar2 + 0x13b8) != 0) {
            local_48 = 1;
            uStack_40 = (undefined4)*(undefined8 *)(lVar2 + 0x13b8);
            uStack_3c = (undefined4)((ulonglong)*(undefined8 *)(lVar2 + 0x13b8) >> 0x20);
            IoReportInterruptInactive(&local_48);
          }
          if (*(longlong *)(lVar2 + 0x13c0) != 0) {
            local_48 = 1;
            uStack_40 = (undefined4)*(undefined8 *)(lVar2 + 0x13c0);
            uStack_3c = (undefined4)((ulonglong)*(undefined8 *)(lVar2 + 0x13c0) >> 0x20);
            IoReportInterruptInactive(&local_48);
          }
          *(undefined4 *)(lVar2 + 4) = 0x40000;
          SdhostPoFxAddDbgLog(lVar2,0x44784645,(longlong)*(int *)(lVar2 + 0x14b0),0,0);
          SdhostForwardPowerIrp(param_1,param_2);
        }
      }
      ExReleaseFastMutex(lVar2 + 0x310);
      return;
    }
    SdhostForwardPowerIrp(param_1,param_2);
  }
  else {
    SdhostCompletePowerIrp(lVar2,param_2,0);
  }
  return;
}



===== SdhostFdoPower @ 1c0008510 =====

undefined4 SdhostFdoPower(longlong param_1,short *param_2)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined8 uVar7;
  
  lVar2 = *(longlong *)(param_2 + 0x5c);
  pcVar6 = "";
  uVar7 = 1;
  iVar3 = IoAcquireRemoveLockEx(param_1 + 0x60);
  if (iVar3 < 0) {
    uVar4 = SdhostCompletePowerIrp(param_1,(longlong)param_2,iVar3);
    return uVar4;
  }
  cVar1 = *(char *)(lVar2 + 1);
  if (cVar1 == '\0') {
    *(short **)(param_1 + 0x298) = param_2;
    iVar5 = 1;
    LOCK();
    iVar3 = *(int *)(param_1 + 0x2a0);
    if (iVar3 == 1) {
      *(int *)(param_1 + 0x2a0) = 3;
    }
    else {
      iVar5 = iVar3;
    }
    UNLOCK();
    if (iVar5 == 2) {
      *(undefined4 *)(param_1 + 0x2a0) = 5;
      param_2[0x18] = 0x120;
      param_2[0x19] = -0x4000;
      IofCompleteRequest(param_2,0);
      return 0xc0000120;
    }
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x80000;
    uVar4 = SdhostForwardIrp(*(undefined8 *)(param_1 + 0xb0),(longlong)param_2,
                             SdhostFdoWaitWakeCompletion,*(undefined8 *)(param_1 + 8));
  }
  else if (cVar1 == '\x02') {
    iVar3 = *(int *)(*(longlong *)(param_2 + 0x5c) + 0x10);
    if (iVar3 == 1) {
      uVar4 = SdhostFdoDeviceSetPower(param_1,param_2,pcVar6,uVar7);
    }
    else {
      if (iVar3 != 0) {
        uVar4 = *(undefined4 *)(param_2 + 0x18);
        SdhostCompletePowerIrp(param_1,(longlong)param_2,uVar4);
        return uVar4;
      }
      if (*(int *)(param_1 + 0x18) == 0) {
        uVar4 = 0;
      }
      else {
        if (*(int *)(*(longlong *)(param_2 + 0x5c) + 0x18) < 7) {
          SdhostForwardIrp(*(undefined8 *)(param_1 + 0xb0),(longlong)param_2,
                           SdhostFdoSystemSetPowerCompletion,0);
          return 0x103;
        }
        uVar4 = 0xc0000001;
      }
      uVar4 = SdhostCompletePowerIrp(param_1,(longlong)param_2,uVar4);
    }
  }
  else {
    if (cVar1 == '\x03') {
      PoStartNextPowerIrp(param_2);
    }
    else {
      PoStartNextPowerIrp();
      *(char *)((longlong)param_2 + 0x43) = *(char *)((longlong)param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0x5c) = *(longlong *)(param_2 + 0x5c) + 0x48;
    }
    uVar4 = PoCallDriver(*(undefined8 *)(param_1 + 0xb0),param_2);
  }
  return uVar4;
}



===== SdhostFdoSystemDevicePowerCompletion @ 1c00086c0 =====

void SdhostFdoSystemDevicePowerCompletion(longlong param_1)

{
  longlong lVar1;
  undefined4 *in_stack_00000028;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(longlong *)(lVar1 + 0x2a8) != 0) {
    SdhostCompletePowerIrp(lVar1,*(longlong *)(lVar1 + 0x2a8),*in_stack_00000028);
    *(undefined8 *)(lVar1 + 0x2a8) = 0;
  }
  return;
}



===== SdhostFdoSystemSetPowerCompletion @ 1c0008700 =====

undefined8 SdhostFdoSystemSetPowerCompletion(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  iVar4 = *(int *)(lVar2 + 0x18);
  *(int *)(lVar3 + 0x80) = iVar4;
  iVar1 = *(int *)(lVar3 + 0x30 + (longlong)iVar4 * 4);
  if (iVar1 == 0) {
    iVar4 = -0x3fffffff;
  }
  else {
    if ((iVar4 == 6) && (0 < *(int *)(lVar3 + 0x9c))) {
      IoReleaseRemoveLockEx(lVar3 + 0x60,param_2,0x20);
      return 0;
    }
    *(longlong *)(lVar3 + 0x2a8) = param_2;
    iVar4 = PoRequestPowerIrp(*(undefined8 *)(lVar3 + 8),
                              CONCAT71((int7)(int3)((uint)iVar4 >> 8),*(undefined1 *)(lVar2 + 1)),
                              iVar1,SdhostFdoSystemDevicePowerCompletion,0,0);
    if (-1 < iVar4) {
      return 0xc0000016;
    }
  }
  SdhostCompletePowerIrp(lVar3,param_2,iVar4);
  return 0xc0000016;
}



===== SdhostFdoWaitWakeCompletion @ 1c00087c0 =====

undefined4 SdhostFdoWaitWakeCompletion(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x40) + 0x2a0);
  iVar2 = *piVar1;
  *piVar1 = 5;
  UNLOCK();
  if (iVar2 == 3) {
    lVar3 = *(longlong *)(param_1 + 0x40);
    if (((*(uint *)(lVar3 + 4) >> 0x13 & 1) != 0) &&
       (*(uint *)(lVar3 + 4) = *(uint *)(lVar3 + 4) & 0xfff7ffff, -1 < *(int *)(param_2 + 0x30))) {
      KeInsertQueueDpc(lVar3 + 0x1408,0,0);
    }
    uVar4 = *(undefined4 *)(param_2 + 0x30);
  }
  else {
    uVar4 = 0xc0000016;
  }
  return uVar4;
}



===== SdhostForwardPowerIrp @ 1c000882c =====

undefined4 SdhostForwardPowerIrp(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 1) {
    uVar3 = *(undefined8 *)(piVar1 + 0x2c);
  }
  else {
    uVar3 = *(undefined8 *)(piVar1 + 0x28);
  }
  uVar2 = PoCallDriver(uVar3,param_2);
  IoReleaseRemoveLockEx(piVar1 + 0x18,param_2,0x20);
  return uVar2;
}



===== SdhostPdoDeviceSetPower @ 1c00088b8 =====

undefined4
SdhostPdoDeviceSetPower(ulonglong param_1,short *param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar4 = SdhostCompletePowerIrp(param_1,(longlong)param_2,0);
  }
  else {
    iVar2 = *(int *)(*(longlong *)(param_2 + 0x5c) + 0x18);
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x598) + 8);
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0x5c) + 3);
    *pbVar1 = *pbVar1 | 1;
    SdhostQueueWorkItem(*(longlong *)(param_1 + 0xa0),*(longlong *)(param_1 + 0x88),
                        SdhostPdoDeviceSetPowerWorker,param_4,param_2,*(int *)(param_1 + 0x9c) == 0)
    ;
    uVar5 = 0x44305071;
    if (iVar2 != 1) {
      uVar5 = 0x44785071;
    }
    SdhostPoFxAddDbgLog(lVar3,uVar5,param_1,(longlong)iVar2,(longlong)*(int *)(lVar3 + 0x84));
    uVar4 = 0x103;
  }
  return uVar4;
}



===== SdhostPdoDeviceSetPowerWorker @ 1c0008970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostPdoDeviceSetPowerWorker(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  int extraout_EAX;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  undefined4 uVar10;
  longlong lVar11;
  int *piVar12;
  
  if (param_2 == 0) {
    return;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar1 = *(int *)(lVar2 + 0x18);
  uVar3 = *(ulonglong *)(*(longlong *)(lVar2 + 0x28) + 0x40);
  lVar11 = *(longlong *)(uVar3 + 0x598);
  lVar4 = *(longlong *)(lVar11 + 8);
  lVar5 = *(longlong *)(lVar4 + 0xc0);
  if (*(longlong *)(lVar4 + 0x1b0) != 0) {
    PoFxActivateComponent(*(longlong *)(lVar4 + 0x1b0),0,1);
  }
  ExAcquireFastMutex(lVar11 + 0x30);
  if (iVar1 == 1) {
    SdhostPoFxAddDbgLog(lVar4,0x44305053,uVar3,1,(ulonglong)*(byte *)(lVar4 + 0x1d8));
    if ((((*(char *)(lVar11 + 0xb3e) != '\0') && (*(int *)(uVar3 + 0x84) == 3)) &&
        (*(int *)(lVar4 + 0x14b0) == 0)) &&
       ((*(longlong *)(lVar11 + 0x10) != 0 &&
        (lVar8 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x40),
        *(int *)(*(longlong *)(lVar11 + 8) + 0x14a8) != 0)))) {
      while( true ) {
        if ((*(int *)(lVar8 + 0x18) == 1) && (*(int *)(lVar8 + 0x84) == 3)) {
          uVar7 = SdhostPdoPowerUpD2(uVar3);
          iVar6 = (int)uVar7;
          if (iVar6 < 0) goto LAB_1c0008b6f;
          (**(code **)(lVar5 + 0x50))(*(undefined8 *)(lVar11 + 0xa88));
          goto LAB_1c0008abe;
        }
        if (*(longlong *)(lVar8 + 0xa8) == 0) break;
        lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0xa8) + 0x40);
      }
    }
    iVar6 = SdhostPdoPowerUp(uVar3);
    if (-1 < iVar6) {
LAB_1c0008abe:
      *(undefined4 *)(uVar3 + 0x84) = 1;
    }
  }
  else {
    SdhostPoFxAddDbgLog(lVar4,0x44785053,uVar3,(longlong)iVar1,(ulonglong)*(byte *)(lVar4 + 0x1d8));
    if (*(int *)(lVar2 + 0x20) == 3) {
      *(int *)(lVar11 + 0x28) = *(int *)(lVar11 + 0x28) + -1;
      iVar6 = 0;
    }
    else if (((*(char *)(lVar11 + 0xb3e) == '\0') || (iVar1 != 3)) ||
            ((*(int *)(lVar4 + 0x14b0) != 1 ||
             ((*(longlong *)(lVar11 + 0x10) == 0 ||
              (lVar8 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x40),
              *(int *)(*(longlong *)(lVar11 + 8) + 0x14a8) == 0)))))) {
LAB_1c0008b54:
      uVar10 = SdhostPdoPowerDown(uVar3);
      lVar11 = CONCAT44((int)((ulonglong)lVar11 >> 0x20),uVar10);
      iVar6 = extraout_EAX;
    }
    else {
      for (; *(int *)(lVar8 + 0x18) != 1; lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0xa8) + 0x40))
      {
        if (*(longlong *)(lVar8 + 0xa8) == 0) goto LAB_1c0008b54;
      }
      (**(code **)(lVar5 + 0x48))(*(undefined8 *)(lVar11 + 0xa88));
      iVar6 = SdhostPdoPowerDownD2(uVar3);
    }
    *(int *)(uVar3 + 0x84) = iVar1;
  }
LAB_1c0008b6f:
  piVar12 = (int *)(lVar4 + 0x14b0);
  if (iVar6 < 0) {
    if (iVar1 != 1) {
      LOCK();
      *(int *)(lVar4 + 0x14b0) = *(int *)(lVar4 + 0x14b0) + -1;
      UNLOCK();
      iVar6 = 0;
      goto LAB_1c0008bbd;
    }
    *(uint *)(lVar11 + 0x20) = *(uint *)(lVar11 + 0x20) | 4;
    SdhostDrainIrpQueue(lVar11);
    IoInvalidateDeviceState(*(undefined8 *)(lVar2 + 0x28));
  }
  else {
    if (iVar1 != 1) {
      LOCK();
      *piVar12 = *piVar12 + -1;
      UNLOCK();
LAB_1c0008bbd:
      uVar9 = 0x44785045;
      goto LAB_1c0008bc2;
    }
    LOCK();
    *piVar12 = *piVar12 + 1;
    UNLOCK();
  }
  uVar9 = 0x44305045;
LAB_1c0008bc2:
  SdhostPoFxAddDbgLog(lVar4,uVar9,uVar3,(longlong)*(int *)(uVar3 + 0x84),
                      (ulonglong)*(byte *)(lVar4 + 0x1d8));
  ExReleaseFastMutex(lVar11 + 0x30);
  SdhostCompletePowerIrp(uVar3,param_2,iVar6);
  if (*(longlong *)(lVar4 + 0x1b0) != 0) {
    PoFxIdleComponent(*(longlong *)(lVar4 + 0x1b0),0,0);
  }
  return;
}



===== SdhostPdoPower @ 1c0008c34 =====

undefined4 SdhostPdoPower(ulonglong param_1,short *param_2)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined8 uVar6;
  
  lVar2 = *(longlong *)(param_2 + 0x5c);
  pcVar5 = "";
  uVar6 = 1;
  iVar3 = IoAcquireRemoveLockEx(param_1 + 0x60);
  uVar4 = 0;
  if (iVar3 < 0) {
    uVar4 = SdhostCompletePowerIrp(param_1,(longlong)param_2,iVar3);
    return uVar4;
  }
  cVar1 = *(char *)(lVar2 + 1);
  if (cVar1 != '\0') {
    if (cVar1 == '\x02') {
      uVar4 = SdhostPdoSetPower(param_1,param_2,pcVar5,uVar6);
    }
    else {
      if (cVar1 == '\x03') {
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        PoStartNextPowerIrp(param_2);
        IofCompleteRequest(param_2,0);
        return *(undefined4 *)(param_2 + 0x18);
      }
      PoStartNextPowerIrp();
      *(char *)((longlong)param_2 + 0x43) = *(char *)((longlong)param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0x5c) = *(longlong *)(param_2 + 0x5c) + 0x48;
      uVar4 = PoCallDriver(*(undefined8 *)(param_1 + 0xa0),param_2);
    }
  }
  return uVar4;
}



===== SdhostPdoPowerDown @ 1c0008d1c =====

undefined4 SdhostPdoPowerDown(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int *piVar4;
  undefined4 unaff_EBX;
  
  if (*(int *)(param_1 + 0x84) == 1) {
    lVar2 = *(longlong *)(param_1 + 0x598);
    lVar3 = *(longlong *)(*(longlong *)(lVar2 + 8) + 0x1b0);
    if (lVar3 != 0) {
      PoFxActivateComponent(lVar3,0,1);
    }
    piVar4 = (int *)SdhostAllocateRequestSynchronous(lVar2);
    if (*(int *)(lVar2 + 0x28) < 2) {
      iVar1 = *(int *)(param_1 + 0xb4);
      if (iVar1 == 1) {
        SdhostPowerOffSdio(param_1,piVar4);
      }
      else if (iVar1 == 2) {
        SdhostPowerOffSd(param_1,piVar4);
      }
      else if (iVar1 == 3) {
        SdhostPowerOffMmc(param_1,piVar4);
      }
    }
    else {
      SdhostStopSdio(param_1,piVar4);
    }
    *(int *)(lVar2 + 0x28) = *(int *)(lVar2 + 0x28) + -1;
    if (*(int *)(lVar2 + 0x28) < 1) {
      SdhostFreeRequest((longlong)piVar4);
    }
    else {
      SdhostFreeRequestSynchronous((longlong)piVar4);
    }
    lVar2 = *(longlong *)(*(longlong *)(lVar2 + 8) + 0x1b0);
    if (lVar2 != 0) {
      PoFxIdleComponent(lVar2,0,0);
    }
  }
  return unaff_EBX;
}



===== SdhostPdoPowerDownD2 @ 1c0008e1c =====

undefined4 SdhostPdoPowerDownD2(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  int *piVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  if (*(int *)(param_1 + 0x84) == 1) {
    lVar1 = *(longlong *)(param_1 + 0x598);
    lVar2 = *(longlong *)(*(longlong *)(lVar1 + 8) + 0x1b0);
    if (lVar2 != 0) {
      PoFxActivateComponent(lVar2,0,1);
    }
    piVar4 = (int *)SdhostAllocateRequestSynchronous(lVar1);
    if (*(int *)(lVar1 + 0x28) < 2) {
      uVar6 = SdhostSetVoltage(*(longlong *)(param_1 + 0x598),4);
      uVar3 = (undefined4)uVar6;
    }
    else {
      uVar5 = SdhostStopSdio(param_1,piVar4);
      uVar3 = (undefined4)uVar5;
    }
    *(int *)(lVar1 + 0x28) = *(int *)(lVar1 + 0x28) + -1;
    if (*(int *)(lVar1 + 0x28) < 1) {
      SdhostFreeRequest((longlong)piVar4);
    }
    else {
      SdhostFreeRequestSynchronous((longlong)piVar4);
    }
    lVar1 = *(longlong *)(*(longlong *)(lVar1 + 8) + 0x1b0);
    if (lVar1 != 0) {
      PoFxIdleComponent(lVar1,0,0);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== SdhostPdoPowerUp @ 1c0008eec =====

int SdhostPdoPowerUp(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int *piVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 8) + 0x1b0);
  if (lVar2 != 0) {
    PoFxActivateComponent(lVar2,0,1);
  }
  piVar4 = (int *)SdhostAllocateRequestSynchronous(lVar1);
  if (*(int *)(lVar1 + 0x28) < 1) {
    iVar3 = *(int *)(param_1 + 0xb4);
    if (iVar3 == 1) {
      iVar3 = SdhostPowerOnSdio(param_1,piVar4);
      goto LAB_1c0008fc0;
    }
    if (iVar3 == 2) {
      iVar3 = SdhostPowerOnSd(param_1,piVar4);
      goto LAB_1c0008fc0;
    }
    if (iVar3 == 3) {
      iVar3 = SdhostPowerOnMmc(param_1,piVar4);
      goto LAB_1c0008fc0;
    }
    iVar3 = -0x3fffff45;
  }
  else {
    iVar3 = SdhostStartSdio(param_1,piVar4);
LAB_1c0008fc0:
    if (-1 < iVar3) {
      *(int *)(lVar1 + 0x28) = *(int *)(lVar1 + 0x28) + 1;
      SdhostFreeRequestSynchronous((longlong)piVar4);
      goto LAB_1c0008f67;
    }
  }
  SdhostFreeRequest((longlong)piVar4);
LAB_1c0008f67:
  lVar1 = *(longlong *)(*(longlong *)(lVar1 + 8) + 0x1b0);
  if (lVar1 != 0) {
    PoFxIdleComponent(lVar1,0,0);
  }
  return iVar3;
}



===== SdhostPdoPowerUpD2 @ 1c0008fdc =====

ulonglong SdhostPdoPowerUpD2(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int *piVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x598);
  lVar3 = *(longlong *)(*(longlong *)(lVar2 + 8) + 0x1b0);
  if (lVar3 != 0) {
    PoFxActivateComponent(lVar3,0,1);
  }
  piVar5 = (int *)SdhostAllocateRequestSynchronous(lVar2);
  if (*(int *)(lVar2 + 0x28) < 1) {
    lVar3 = *(longlong *)(param_1 + 0x598);
    uVar1 = *(undefined4 *)(lVar3 + 0xb48);
    SdhostResetHw(lVar3);
    *(undefined4 *)(lVar3 + 0xb48) = uVar1;
    uVar4 = SdhostResetHost(lVar3,1);
    uVar7 = (ulonglong)uVar4;
    if (-1 < (int)uVar4) {
      uVar6 = SdhostSetVoltage(lVar3,1);
      uVar7 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        uVar4 = SdhostSetClock(lVar3,*(undefined4 *)(lVar3 + 0xe0));
        goto LAB_1c0009038;
      }
    }
  }
  else {
    uVar4 = SdhostStartSdio(param_1,piVar5);
LAB_1c0009038:
    uVar7 = (ulonglong)uVar4;
    if (-1 < (int)uVar4) {
      *(int *)(lVar2 + 0x28) = *(int *)(lVar2 + 0x28) + 1;
      SdhostFreeRequestSynchronous((longlong)piVar5);
      goto LAB_1c000904d;
    }
  }
  SdhostFreeRequest((longlong)piVar5);
LAB_1c000904d:
  lVar2 = *(longlong *)(*(longlong *)(lVar2 + 8) + 0x1b0);
  if (lVar2 != 0) {
    PoFxIdleComponent(lVar2,0,0);
  }
  return uVar7;
}



===== SdhostPdoSetPower @ 1c00090f0 =====

undefined4 SdhostPdoSetPower(ulonglong param_1,short *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x5c);
  if (*(int *)(lVar1 + 0x10) == 1) {
    uVar2 = SdhostPdoDeviceSetPower(param_1,param_2,lVar1,param_4);
  }
  else {
    if (*(int *)(lVar1 + 0x10) != 0) {
      uVar2 = *(undefined4 *)(param_2 + 0x18);
      SdhostCompletePowerIrp(param_1,(longlong)param_2,uVar2);
      return uVar2;
    }
    if (*(int *)(lVar1 + 0x20) - 2U < 2) {
      *(int *)(param_1 + 0x5e0) = *(int *)(param_1 + 0x5e0) + 1;
    }
    *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(lVar1 + 0x18);
    uVar2 = SdhostCompletePowerIrp(param_1,(longlong)param_2,0);
  }
  return uVar2;
}



===== SdhostPoFxActiveCallback @ 1c0009160 =====

void SdhostPoFxActiveCallback(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  char *pcVar5;
  code *pcVar6;
  longlong lVar7;
  undefined1 *puVar8;
  uint uVar9;
  ulonglong uVar10;
  int iVar11;
  longlong *plVar12;
  undefined8 uVar13;
  uint uVar14;
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  plVar1 = param_1 + 0x3a;
  uStack_40 = 0;
  local_48 = 0;
  local_44 = 0;
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeAcquireInStackQueuedSpinLock(plVar1,&local_38);
  uVar13 = 0;
  SdhostPoFxAddDbgLog((longlong)param_1,0x41634362,(ulonglong)*(uint *)((longlong)param_1 + 0x13cc),
                      0,0);
  plVar12 = param_1;
  KeSynchronizeExecution(param_1[0x277],SdhostPoFxSynchronizeActiveState);
  puVar8 = auStackY_78;
  if (*(int *)((longlong)param_1 + 0x13cc) != 0) {
    lVar7 = param_1[0x28d];
    iVar11 = 0;
    uVar10 = 0;
    uVar14 = 1;
    if (*(char *)((longlong)param_1 + 0x1464) != '\0') {
      do {
        if ((*(uint *)((longlong)param_1 + 0x13cc) & uVar14) != 0) {
          SdhostEnableEvents(lVar7,0x100);
          iVar11 = iVar11 + 1;
        }
        uVar9 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
        uVar14 = uVar14 * 2;
        lVar7 = param_1[uVar10 + 0x28d];
      } while (uVar9 < *(byte *)((longlong)param_1 + 0x1464));
    }
    *(undefined4 *)((longlong)param_1 + 0x13cc) = 0;
    KeReleaseInStackQueuedSpinLock(&local_38);
    for (; iVar11 != 0; iVar11 = iVar11 + -1) {
      if (param_1[0x36] != 0) {
        plVar12 = (longlong *)0x0;
        PoFxIdleComponent(param_1[0x36],0);
      }
    }
    KeAcquireInStackQueuedSpinLock(plVar1,&local_38);
  }
  if ((char)param_1[0x279] != '\0') {
    uStack_40 = (undefined4)param_1[0x277];
    uStack_3c = (undefined4)((ulonglong)param_1[0x277] >> 0x20);
    local_48 = 1;
    IoReportInterruptActive(&local_48);
  }
  plVar2 = param_1 + 0x38;
  do {
    plVar4 = (longlong *)*plVar2;
    if (plVar4 == plVar2) {
LAB_1c000939f:
      *(undefined8 *)(puVar8 + -8) = 0x1c00093aa;
      KeReleaseInStackQueuedSpinLock(&local_38);
      return;
    }
    if (((longlong *)plVar4[1] != plVar2) ||
       (lVar7 = *plVar4, (longlong *)*(longlong *)(lVar7 + 8) != plVar4)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar8 = auStackY_70;
      goto LAB_1c000939f;
    }
    *plVar2 = lVar7;
    plVar3 = plVar4 + -0x15;
    *(longlong **)(lVar7 + 8) = plVar2;
    pcVar5 = (char *)plVar4[2];
    uVar10 = *(ulonglong *)(*(longlong *)(pcVar5 + 0x28) + 0x40);
    KeReleaseInStackQueuedSpinLock(&local_38);
    if (*pcVar5 == '\x0f') {
      if (**(int **)(pcVar5 + 0x20) == 2) {
        plVar12 = plVar3;
        iVar11 = SdhostPdoDeviceCommand(uVar10,(longlong)*(int **)(pcVar5 + 0x20),(longlong)plVar3);
        if (iVar11 == 0x103) goto LAB_1c0009380;
      }
      else {
        iVar11 = 0;
      }
      if (param_1[0x36] != 0) {
        plVar12 = (longlong *)0x0;
        PoFxIdleComponent(param_1[0x36],0);
      }
      *(int *)(plVar4 + -0xf) = iVar11;
      IofCompleteRequest(plVar3,0);
    }
    else if (*pcVar5 == '\x16') {
      SdhostPdoSetPower(uVar10,(short *)plVar3,plVar12,uVar13);
    }
LAB_1c0009380:
    KeAcquireInStackQueuedSpinLock(plVar1,&local_38);
  } while( true );
}



===== SdhostPoFxDevicePowerNotRequiredCallback @ 1c00093e0 =====

void SdhostPoFxDevicePowerNotRequiredCallback(longlong param_1)

{
  SdhostPoFxAddDbgLog(param_1,0x44504e52,(longlong)*(int *)(param_1 + 0x14b0),0,0);
  if (*(int *)(param_1 + 0x14b0) == 0) {
    PoRequestPowerIrp(*(undefined8 *)(param_1 + 8),2,4,0,0,0);
    *(undefined1 *)(param_1 + 0x1e0) = 1;
    SdhostPoFxAddDbgLog(param_1,0x44334652,(longlong)*(int *)(param_1 + 0x14b0),0,0);
  }
  else {
    KeSynchronizeExecution(*(undefined8 *)(param_1 + 0x13b8),SdhostPoFxSynchronizeDpnrState,param_1)
    ;
    if (*(longlong *)(param_1 + 0x1b0) != 0) {
      PoFxCompleteDevicePowerNotRequired();
    }
  }
  return;
}



===== SdhostPoFxDevicePowerRequiredCallback @ 1c00094a0 =====

void SdhostPoFxDevicePowerRequiredCallback(longlong param_1)

{
  SdhostPoFxAddDbgLog(param_1,0x44505243,(longlong)*(int *)(param_1 + 0x14b0),0,0);
  KeSynchronizeExecution(*(undefined8 *)(param_1 + 0x13b8),SdhostPoFxSynchronizeDprState,param_1);
  *(undefined1 *)(param_1 + 0x1e1) = 1;
  if (*(char *)(param_1 + 0x1e0) == '\0') {
    if (*(longlong *)(param_1 + 0x1b0) != 0) {
      *(undefined1 *)(param_1 + 0x1e1) = 0;
      PoFxReportDevicePoweredOn();
    }
    *(undefined1 *)(param_1 + 0x1e1) = 0;
    KeSynchronizeExecution(*(undefined8 *)(param_1 + 0x13b8),SdhostPoFxSynchronizeDpnrState,param_1)
    ;
  }
  else {
    PoRequestPowerIrp(*(undefined8 *)(param_1 + 8),2,1,0,0,0);
    *(undefined1 *)(param_1 + 0x1e0) = 0;
    SdhostPoFxAddDbgLog(param_1,0x44304652,(longlong)*(int *)(param_1 + 0x14b0),0,0);
  }
  return;
}



===== SdhostPoFxEnableRuntimePowerManagement @ 1c000958c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdhostPoFxEnableRuntimePowerManagement(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong *plVar2;
  int iVar3;
  undefined1 auStack_108 [32];
  undefined4 local_e8 [4];
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  longlong local_a8;
  undefined4 local_a0;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 *local_78;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_108;
  if (*(int *)(param_1 + 0x84) == 1) {
    local_58 = 0;
    lVar1 = param_1 + 0x1c0;
    local_50 = 0;
    local_48 = 0xffffffff;
    *(longlong *)(param_1 + 0x1c8) = lVar1;
    *(longlong *)lVar1 = lVar1;
    local_40 = 10;
    local_38 = 10;
    local_30 = 1000;
    memset(local_e8,0,0x88);
    local_80 = 0;
    local_e8[0] = 2;
    local_d8 = SdhostPoFxActiveCallback;
    plVar2 = (longlong *)(param_1 + 0x1b0);
    local_7c = 2;
    local_d0 = SdhostPoFxIdleCallback;
    local_a0 = 1;
    local_c8 = SdhostPoFxFStateCallback;
    local_c0 = SdhostPoFxDevicePowerRequiredCallback;
    local_b8 = SdhostPoFxDevicePowerNotRequiredCallback;
    local_b0 = SdhostPoFxPowerControlCallback;
    local_78 = &local_58;
    *(undefined1 *)(param_1 + 0x1d8) = 1;
    local_a8 = param_1;
    iVar3 = PoFxRegisterDevice(*(undefined8 *)(param_1 + 0xa8),local_e8,plVar2);
    if (iVar3 < 0) {
      if (*plVar2 != 0) {
        PoFxUnregisterDevice();
        *plVar2 = 0;
      }
    }
    else {
      PoFxSetComponentLatency(*plVar2,0,10);
      PoFxSetComponentResidency(*plVar2,0,10);
      if (ForceF0State != 0) {
        PoFxSetComponentWake(*plVar2,0,1);
      }
      if ((param_2 != '\0') || (1 < *(int *)(param_1 + 0x308))) {
        if (*(int *)(param_1 + 0x308) == 5) {
          (**(code **)(param_1 + 0x2e0))(*(undefined8 *)(param_1 + 0x2c8),1);
        }
        PoFxStartDevicePowerManagement(*(undefined8 *)(param_1 + 0x1b0));
      }
      SdhostInitializePoFxDbgLog(param_1);
    }
  }
  else {
    iVar3 = -0x3fffffff;
  }
  return iVar3;
}



===== SdhostPoFxFStateCallback @ 1c0009790 =====

void SdhostPoFxFStateCallback(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x1dc) = param_3;
  PoFxCompleteIdleState(*(undefined8 *)(param_1 + 0x1b0));
  return;
}



===== SdhostPoFxIdleCallback @ 1c00097c0 =====

void SdhostPoFxIdleCallback(longlong param_1,undefined4 param_2)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_10 = 0;
  cVar2 = '\0';
  local_18 = 0;
  local_14 = 0;
  SdhostPoFxAddDbgLog(param_1,0x49644362,0,0,0);
  if (*(char *)(param_1 + 0x13c8) != cVar2) {
    uVar1 = *(undefined8 *)(param_1 + 0x13b8);
    uStack_10 = (undefined4)uVar1;
    uStack_c = (undefined4)((ulonglong)uVar1 >> 0x20);
    local_18 = 1;
    IoReportInterruptInactive(&local_18);
  }
  KeSynchronizeExecution(*(undefined8 *)(param_1 + 0x13b8),SdhostPoFxSynchronizeIdleState,param_1);
  PoFxCompleteIdleCondition(*(undefined8 *)(param_1 + 0x1b0),param_2);
  return;
}



===== SdhostPoFxPowerControlCallback @ 1c0009870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostPoFxPowerControlCallback(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0xc0) + 0x78))();
  return;
}



===== SdhostPoFxSynchronizeActiveState @ 1c00098c0 =====

undefined1 SdhostPoFxSynchronizeActiveState(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x1d8) = 1;
  return 1;
}



===== SdhostPoFxSynchronizeDpnrState @ 1c00098e0 =====

undefined1 SdhostPoFxSynchronizeDpnrState(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x1d9) = 0;
  return 0;
}



===== SdhostPoFxSynchronizeDprState @ 1c0009900 =====

undefined1 SdhostPoFxSynchronizeDprState(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x1d9) = 1;
  return 1;
}



===== SdhostPoFxSynchronizeIdleState @ 1c0009920 =====

undefined1 SdhostPoFxSynchronizeIdleState(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x1d8) = 0;
  return 0;
}



===== SdhostPower @ 1c0009940 =====

int SdhostPower(longlong param_1,short *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x40);
  iVar2 = IoAcquireRemoveLockEx(piVar1 + 0x18,param_2,"",1,0x20);
  if (iVar2 < 0) {
    param_2[0x1c] = 0;
    param_2[0x1d] = 0;
    param_2[0x1e] = 0;
    param_2[0x1f] = 0;
    *(int *)(param_2 + 0x18) = iVar2;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  else if (*piVar1 == 1) {
    iVar2 = SdhostFdoPower(*(ulonglong *)(param_1 + 0x40),param_2);
  }
  else {
    iVar2 = SdhostPdoPower(*(ulonglong *)(param_1 + 0x40),param_2);
  }
  return iVar2;
}



===== SdhostValidatePdoPowerState @ 1c00099ec =====

undefined8 SdhostValidatePdoPowerState(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 0xb4) == 1) &&
     ((*(int *)(param_1 + 0x84) != 1 ||
      (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x598) + 8) + 0x84) != 1)))) {
    uVar1 = 0xc0000184;
  }
  return uVar1;
}



===== SdhostBusInterfaceControl @ 1c0009a24 =====

ulonglong SdhostBusInterfaceControl(longlong param_1,int *param_2,char param_3,ulonglong *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  uVar2 = SdhostIssueCommandNoTransfer
                    (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,0xe00,0,0,1);
  if (-1 < (int)uVar2) {
    if (param_3 == '\0') {
      uVar2 = SdhostIssueCommandNoTransfer
                        (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,
                         (byte)((byte)*param_4 ^ *(byte *)(param_2 + 0x1e)) & 3 ^
                         (uint)(byte)*param_4 | 0x80000e00,0,0,1);
    }
    else {
      *param_4 = (ulonglong)*(byte *)(param_2 + 0x1e) & 0xfffffffffffffffc;
      uVar2 = uVar2 & 0xffffffff;
    }
  }
  return uVar2;
}



===== SdhostDeselectDevice @ 1c0009adc =====

void SdhostDeselectDevice(longlong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdDeselect,0,0,0,1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 0xb50) = 0;
  }
  return;
}



===== SdhostEnableSdioInterrupt @ 1c0009b20 =====

ulonglong SdhostEnableSdioInterrupt(longlong param_1,int *param_2,char param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (*(int *)(param_1 + 0xb4) - 2U < 2) {
    uVar2 = 0;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x598);
    uVar2 = SdhostIssueCommandNoTransfer
                      (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,0x800,0,0,1);
    if (-1 < (int)uVar2) {
      uVar4 = (uint)*(byte *)(param_2 + 0x1e) & ~(1 << (*(byte *)(param_1 + 0xb0) & 0x1f));
      if ((param_3 != '\0') && ((*(uint *)(param_1 + 0x608) & 0x10000) != 0)) {
        uVar4 = uVar4 | 1 | 1 << (*(byte *)(param_1 + 0xb0) & 0x1f);
      }
      uVar3 = 0;
      if ((char)uVar4 != '\x01') {
        uVar3 = uVar4 & 0xff;
      }
      uVar2 = SdhostIssueCommandNoTransfer
                        (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,uVar3 | 0x80000800,0,0,
                         1);
      if (-1 < (int)uVar2) {
        *(char *)(lVar1 + 0xb45) = (char)uVar3;
        KeAcquireInStackQueuedSpinLock(lVar1 + 0xc98,&local_28);
        if (param_3 == '\0') {
          *(uint *)(lVar1 + 0x20) = *(uint *)(lVar1 + 0x20) & 0xffdfffff;
          SdhostDisableEvents(lVar1,0x100);
        }
        else if ((*(char *)(lVar1 + 0xb45) != '\0') && ((*(uint *)(lVar1 + 0x20) & 0x200000) == 0))
        {
          *(uint *)(lVar1 + 0x20) = *(uint *)(lVar1 + 0x20) | 0x200000;
          SdhostEnableEvents(lVar1,0x100);
        }
        KeReleaseInStackQueuedSpinLock(&local_28);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
  }
  return uVar2;
}



===== SdhostErrorRecoveryWorker @ 1c0009ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostErrorRecoveryWorker(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined8 local_res10;
  
  uVar3 = *(uint *)(param_2 + 0x24);
  bVar2 = *(byte *)(param_2 + 8);
  local_res10 = 0;
  lVar6 = *(longlong *)(param_2 + 0xb8);
  iVar4 = *(int *)(param_2 + 0x18);
  iVar5 = *(int *)(param_2 + 100);
  LOCK();
  piVar1 = (int *)(lVar6 + 0xdc8);
  iVar7 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  puVar10 = (undefined8 *)
            ((ulonglong)(*(uint *)(lVar6 + 0xdcc) & iVar7 - 1U) * 0x20 +
            *(longlong *)(lVar6 + 0xdd0));
  *(undefined8 **)(lVar6 + 0xdd8) = puVar10;
  *puVar10 = 0x65527245;
  puVar10[1] = (ulonglong)bVar2 << 0x10 | (ulonglong)uVar3;
  puVar10[2] = (longlong)iVar5;
  puVar10[3] = (longlong)iVar4;
  uVar3 = *(uint *)(lVar6 + 0xb34);
  uVar8 = SdhostDisableEvents(lVar6,uVar3);
  if (-1 < (int)uVar8) {
    iVar7 = SdhostResetHost(lVar6,2);
    if (-1 < iVar7) {
      if (*(int *)(param_2 + 0x18) != 1) {
        iVar7 = SdhostResetHost(lVar6,3);
        if (iVar7 < 0) goto LAB_1c0009d7e;
      }
      (**(code **)(*(longlong *)(*(longlong *)(lVar6 + 8) + 0xc0) + 0x40))
                (*(longlong *)
                  (*(longlong *)(lVar6 + 8) + 0xf0 + (ulonglong)*(byte *)(lVar6 + 4) * 8) + 0x10,
                 0xffffffff);
      SdhostEnableEvents(lVar6,uVar3);
    }
  }
LAB_1c0009d7e:
  lVar9 = KeQueryInterruptTimePrecise(&local_res10);
  *(longlong *)(lVar6 + 0x1e30) = lVar9 - *(longlong *)(lVar6 + 0x1e28);
  SdhostCompleteRequestPostError((int *)param_2);
  return;
}



===== SdhostExecuteTuning @ 1c0009dbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostExecuteTuning(longlong param_1)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = 0xd;
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xc0) + 0x60))
            (*(longlong *)
              (*(longlong *)(param_1 + 8) + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8) + 0x10,
             local_res8);
  return;
}



===== SdhostGetBusWidthMmc @ 1c0009e04 =====

ulonglong SdhostGetBusWidthMmc(longlong param_1,int *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  
  uVar2 = 0;
  puVar4 = (undefined4 *)0x0;
  puVar5 = (undefined8 *)0x0;
  if (3 < *(byte *)(param_1 + 0xe8)) {
    *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) | 6;
    *(undefined1 *)(param_1 + 0x114) = 1;
    if ((*(uint *)(param_1 + 0xb24) & 4) == 0) {
      *(undefined4 *)*(undefined8 **)(param_1 + 0xaf8) = 0;
      uVar3 = 4;
      puVar4 = *(undefined4 **)(param_1 + 0xaf8);
      *puVar4 = 0x5a;
    }
    else {
      **(undefined8 **)(param_1 + 0xaf8) = 0;
      uVar3 = 8;
      puVar5 = *(undefined8 **)(param_1 + 0xaf8);
      *puVar5 = 0xaa55;
    }
    uVar2 = SdhostSetBusWidth(param_1,8);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdBusTestWriteMmc,*(int *)(param_1 + 0xb48),
                       uVar3,1,*(longlong *)(param_1 + 0xaf0),0,0,1);
    uVar2 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdBusTestReadMmc,
                               *(int *)(param_1 + 0xb48),uVar3,1,*(longlong *)(param_1 + 0xaf0),0,0,
                               1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if ((puVar5 == (undefined8 *)0x0) || ((short)*(undefined4 *)puVar5 != 0x55aa)) {
      if ((puVar4 == (undefined4 *)0x0) || ((char)*puVar4 != -0x51)) {
        *(undefined1 *)(param_1 + 0xb51) = 1;
        uVar1 = *(uint *)(param_1 + 200) & 0xfffffffd | 4;
      }
      else {
        *(undefined1 *)(param_1 + 0xb51) = 4;
        uVar1 = *(uint *)(param_1 + 200) & 0xfffffffb | 2;
      }
    }
    else {
      uVar1 = *(uint *)(param_1 + 200) | 6;
      *(undefined1 *)(param_1 + 0xb51) = 8;
    }
    *(uint *)(param_1 + 200) = uVar1;
    uVar1 = SdhostSetBusWidth(param_1,1);
    uVar2 = (ulonglong)uVar1;
  }
  return uVar2;
}



===== SdhostGetBusWidthSd @ 1c0009fb0 =====

ulonglong SdhostGetBusWidthSd(longlong param_1,int *param_2)

{
  byte *pbVar1;
  ulonglong uVar2;
  
  uVar2 = SdhostSendAppCmd(param_1,param_2);
  if (-1 < (int)uVar2) {
    pbVar1 = *(byte **)(param_1 + 0xaf8);
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    pbVar1[4] = 0;
    pbVar1[5] = 0;
    pbVar1[6] = 0;
    pbVar1[7] = 0;
    uVar2 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSendScrSd,
                               *(int *)(param_1 + 0xb48),8,1,*(longlong *)(param_1 + 0xaf0),0,0,1);
    if (-1 < (int)uVar2) {
      *(byte *)(param_1 + 0xe8) = *pbVar1 & 0xf;
      *(uint *)(param_1 + 200) = pbVar1[1] >> 1 & 2 | *(uint *)(param_1 + 200) & 0xfffffffd;
      *(byte *)(param_1 + 0x114) = pbVar1[3] >> 1 & 1;
      *(byte *)(param_1 + 0xe9) = pbVar1[2] >> 7;
      uVar2 = uVar2 & 0xffffffff;
    }
  }
  return uVar2;
}



===== SdhostGetDeviceConfigurationSdio @ 1c000a088 =====

uint SdhostGetDeviceConfigurationSdio(longlong param_1,int *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  byte bVar5;
  uint uVar6;
  
  puVar1 = (uint *)(param_1 + 0xca0);
  uVar2 = SdhostIssueCommandNoTransfer
                    (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,0,0,0,1);
  if (-1 < (int)uVar2) {
    *(byte *)(param_1 + 0x120) = *(byte *)(param_2 + 0x1e) >> 4;
    uVar2 = SdhostIssueCommandNoTransfer
                      (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,0x2600,0,0,1);
    if (-1 < (int)uVar2) {
      *(ushort *)(param_1 + 0xcc) =
           (ushort)(*(byte *)(param_2 + 0x1e) & 1) * 2 | *(ushort *)(param_1 + 0xcc) & 0xfffd;
      uVar2 = SdhostIssueCommandNoTransfer
                        (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,0x1000,0,0,1);
      if (-1 < (int)uVar2) {
        bVar5 = 0;
        *(char *)(param_1 + 0x121) = (char)param_2[0x1e];
        uVar3 = 0x1200;
        *puVar1 = 0;
        do {
          uVar2 = SdhostIssueCommandNoTransfer
                            (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,uVar3 & 0x3fffe00
                             ,0,0,1);
          if ((int)uVar2 < 0) goto LAB_1c000a2d1;
          uVar3 = uVar3 + 0x200;
          *puVar1 = *puVar1 | (uint)*(byte *)(param_2 + 0x1e) << (bVar5 & 0x1f);
          bVar5 = bVar5 + 8;
        } while (uVar3 < 0x1800);
        uVar2 = SdhostProcessTupleChain(param_1,param_2,0,puVar1);
        if ((-1 < (int)uVar2) && (uVar4 = 1, *(char *)(param_1 + 0xd2) != '\0')) {
          uVar3 = 0x20000;
          do {
            uVar2 = SdhostIssueCommandNoTransfer
                              (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,
                               uVar3 & 0x3fffe00,0,0,1);
            if ((int)uVar2 < 0) break;
            uVar2 = uVar3 + 0x1200;
            uVar6 = 0;
            *(byte *)(param_1 + 0x124 + uVar4 * 0x90) = *(byte *)(param_2 + 0x1e) & 0xf;
            *puVar1 = 0;
            do {
              SdhostIssueCommandNoTransfer
                        (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,uVar2 & 0x3fffe00,0,0
                         ,1);
              uVar2 = uVar2 + 0x200;
              *puVar1 = *puVar1 | (uint)*(byte *)(param_2 + 0x1e) << ((byte)uVar6 & 0x1f);
              uVar6 = uVar6 + 8;
            } while (uVar6 < 0x18);
            uVar2 = SdhostProcessTupleChain(param_1,param_2,(uint)uVar4,puVar1);
            uVar6 = (uint)uVar4 + 1;
            uVar4 = (ulonglong)uVar6;
            uVar3 = uVar3 + 0x20000;
          } while (uVar6 <= *(byte *)(param_1 + 0xd2));
        }
      }
    }
  }
LAB_1c000a2d1:
  *(undefined2 *)(param_1 + 0xb8a) = 0x200;
  return uVar2;
}



===== SdhostGetMaxClockFrequency @ 1c000a300 =====

ulonglong SdhostGetMaxClockFrequency(longlong param_1,int *param_2)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  
  cVar1 = *(char *)(param_1 + 0xb50);
  if ((cVar1 != '\0') && (uVar5 = SdhostDeselectDevice(param_1,param_2), (int)uVar5 < 0)) {
    return uVar5;
  }
  uVar5 = SdhostSendCsd(param_1,param_2);
  if (-1 < (int)uVar5) {
    if ((cVar1 != '\0') && (uVar5 = SdhostSelectDevice(param_1,param_2), (int)uVar5 < 0)) {
      return uVar5;
    }
    uVar5 = uVar5 & 0xffffffff;
    uVar3 = SdhostClockRateCodeToValue(*(byte *)(param_1 + 0x112));
    *(uint *)(param_1 + 0xe0) = uVar3;
    if (*(int *)(param_1 + 0xb68) == 6) {
      *(uint *)(param_1 + 0xe0) = uVar3 >> 1;
    }
    uVar2 = *(ushort *)(param_1 + 0xcc);
    if (*(int *)(param_1 + 0xd4) == 3) {
      if (((uVar2 & 0x20) == 0) || (uVar4 = 200000, (*(uint *)(param_1 + 0xb24) & 0x100) == 0)) {
        uVar4 = 52000;
      }
      *(undefined4 *)(param_1 + 0xe0) = uVar4;
    }
    else if (((uVar2 & 8) == 0) || (-1 < (char)*(undefined4 *)(param_1 + 0xb24))) {
      if (((uVar2 & 4) != 0) && ((*(uint *)(param_1 + 0xb24) & 0x20) != 0)) {
        *(undefined4 *)(param_1 + 0xe0) = 100000;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xe0) = 0x32c80;
    }
    uVar5 = uVar5 & 0xffffffff;
  }
  return uVar5;
}



===== SdhostGetMaxFrequencySdio @ 1c000a404 =====

undefined8 SdhostGetMaxFrequencySdio(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 25000;
  if (*(byte *)(param_1 + 0x122) == 0) {
    uVar1 = 50000;
  }
  else {
    uVar2 = 25000;
    uVar1 = SdhostClockRateCodeToValue(*(byte *)(param_1 + 0x122));
    if (50000 < uVar1) goto LAB_1c000a43a;
  }
  if (uVar1 <= uVar2) {
    uVar2 = uVar1;
  }
LAB_1c000a43a:
  *(uint *)(param_1 + 0xdc) = uVar2;
  if ((*(byte *)(param_1 + 0x121) & 0x40) != 0) {
    if (400 < uVar1) {
      uVar1 = 400;
    }
    *(uint *)(param_1 + 0xdc) = uVar1;
  }
  if (((*(ushort *)(param_1 + 0xcc) & 8) == 0) || (-1 < (char)*(undefined4 *)(param_1 + 0xb24))) {
    if (((*(ushort *)(param_1 + 0xcc) & 4) == 0) || ((*(uint *)(param_1 + 0xb24) & 0x20) == 0)) {
      *(undefined4 *)(param_1 + 0xe0) = 50000;
    }
    else {
      *(undefined4 *)(param_1 + 0xe0) = 100000;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xe0) = 0x32c80;
  }
  return 0;
}



===== SdhostGetSpeedModesMmc @ 1c000a4bc =====

ulonglong SdhostGetSpeedModesMmc(longlong param_1,int *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  *(undefined2 *)(param_1 + 0xcc) = 0;
  if (*(byte *)(param_1 + 0xe8) < 4) {
    *(undefined4 *)(param_1 + 0xb68) = 1;
    uVar2 = 0;
  }
  else {
    memset(*(void **)(param_1 + 0xaf8),0,0x200);
    uVar1 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSendExtCsdMmc,
                               *(int *)(param_1 + 0xb48),0x200,1,*(longlong *)(param_1 + 0xaf0),0,0,
                               1);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0xaf8) + 0xc4) & 0x30) != 0) {
      *(ushort *)(param_1 + 0xcc) = *(ushort *)(param_1 + 0xcc) | 0x20;
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0xaf8) + 0xc4) & 2) != 0) {
      *(ushort *)(param_1 + 0xcc) = *(ushort *)(param_1 + 0xcc) | 2;
    }
  }
  return uVar2;
}



===== SdhostGetSpeedModesSdio @ 1c000a5a0 =====

ulonglong SdhostGetSpeedModesSdio(longlong param_1,int *param_2)

{
  ulonglong uVar1;
  
  uVar1 = SdhostIssueCommandNoTransfer
                    (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,0x2600,0,0,1);
  if (-1 < (int)uVar1) {
    *(ushort *)(param_1 + 0xcc) =
         (ushort)(*(byte *)(param_2 + 0x1e) & 1) * 2 | *(ushort *)(param_1 + 0xcc) & 0xfffd;
    uVar1 = SdhostIssueCommandNoTransfer
                      (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,0x2800,0,0,1);
    if (-1 < (int)uVar1) {
      *(ushort *)(param_1 + 0xcc) =
           (ushort)(*(byte *)(param_2 + 0x1e) & 1) << 2 | *(ushort *)(param_1 + 0xcc) & 0xffe3;
      uVar1 = uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}



===== SdhostGetSwitchStatusSd @ 1c000a670 =====

int SdhostGetSwitchStatusSd(longlong param_1,int *param_2)

{
  ushort uVar1;
  void *_Dst;
  byte bVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  
  _Dst = *(void **)(param_1 + 0xaf8);
  memset(_Dst,0,0x40);
  iVar3 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSwitchSd,0,0x40,1,
                             *(longlong *)(param_1 + 0xaf0),0,0,1);
  if (((-1 < iVar3) && (*(undefined2 *)(param_1 + 0xcc) = 0, *(char *)(param_1 + 0xd2) == '\0')) &&
     (*(char *)(param_1 + 0xe5) != '\0')) {
    bVar2 = *(byte *)((longlong)_Dst + 0xd) & 1;
    *(ushort *)(param_1 + 0xcc) = (ushort)bVar2;
    bVar2 = *(byte *)((longlong)_Dst + 0xd) & 2 | bVar2;
    *(ushort *)(param_1 + 0xcc) = (ushort)bVar2;
    bVar2 = *(byte *)((longlong)_Dst + 0xd) & 4 | bVar2;
    *(ushort *)(param_1 + 0xcc) = (ushort)bVar2;
    bVar2 = *(byte *)((longlong)_Dst + 0xd) & 8 | bVar2;
    *(ushort *)(param_1 + 0xcc) = (ushort)bVar2;
    *(ushort *)(param_1 + 0xcc) = (ushort)(*(byte *)((longlong)_Dst + 0xd) & 0x10 | bVar2);
    uVar1 = *(ushort *)(param_1 + 0xce);
    uVar4 = (ushort)(*(byte *)((longlong)_Dst + 9) & 1);
    *(ushort *)(param_1 + 0xce) = uVar4 | uVar1 & 0xfffe;
    uVar5 = (ushort)(*(byte *)((longlong)_Dst + 9) & 2);
    *(ushort *)(param_1 + 0xce) = uVar5 | uVar4 | uVar1 & 0xfffc;
    uVar6 = (ushort)(*(byte *)((longlong)_Dst + 9) & 4);
    *(ushort *)(param_1 + 0xce) = uVar6 | uVar5 | uVar4 | uVar1 & 0xfff8;
    *(ushort *)(param_1 + 0xce) =
         (ushort)(*(byte *)((longlong)_Dst + 9) & 8) | uVar6 | uVar5 | uVar4 | uVar1 & 0xfff0;
    uVar1 = *(ushort *)(param_1 + 0xd0);
    uVar4 = (ushort)(*(byte *)((longlong)_Dst + 7) & 1);
    *(ushort *)(param_1 + 0xd0) = uVar4 | uVar1 & 0xfffe;
    uVar5 = (ushort)(*(byte *)((longlong)_Dst + 7) & 2);
    *(ushort *)(param_1 + 0xd0) = uVar5 | uVar4 | uVar1 & 0xfffc;
    uVar6 = (ushort)(*(byte *)((longlong)_Dst + 7) & 4);
    *(ushort *)(param_1 + 0xd0) = uVar6 | uVar5 | uVar4 | uVar1 & 0xfff8;
    *(ushort *)(param_1 + 0xd0) =
         (ushort)(*(byte *)((longlong)_Dst + 7) & 8) | uVar6 | uVar5 | uVar4 | uVar1 & 0xfff0;
  }
  return iVar3;
}



===== SdhostGoIdleState @ 1c000a86c =====

int SdhostGoIdleState(longlong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdGoIdleState,0,0,0,1);
  if (-1 < iVar1) {
    SdhostWait(*(uint *)(param_1 + 0x98));
  }
  return iVar1;
}



===== SdhostInitSdioInterrupt @ 1c000a8c0 =====

void SdhostInitSdioInterrupt(longlong param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  iVar2 = SdhostIssueCommandNoTransfer
                    (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,0x800,0,0,1);
  if (-1 < iVar2) {
    bVar4 = '\x01' << (*(byte *)(param_1 + 0xb0) & 0x1f) & *(byte *)(lVar1 + 0xb45) |
            *(byte *)(param_2 + 0x1e) & ~(byte)(1 << (*(byte *)(param_1 + 0xb0) & 0x1f));
    uVar3 = 0;
    if (bVar4 != 1) {
      uVar3 = (uint)bVar4;
    }
    SdhostIssueCommandNoTransfer
              (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,uVar3 | 0x80000800,0,0,1);
  }
  return;
}



===== SdhostInitializeMmc @ 1c000a970 =====

ulonglong SdhostInitializeMmc(longlong param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  int iVar4;
  
  uVar3 = SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdSendCidAll,0,0,0,1);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar3 = SdhostSendRelativeAddr(param_1,param_2);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  iVar2 = SdhostSendCid(param_1,param_2);
  if (iVar2 < 0) {
    return CONCAT44(extraout_var,iVar2);
  }
  uVar3 = SdhostSendCsd(param_1,param_2);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  *(undefined2 *)(param_1 + 0xb8a) = 0x200;
  uVar3 = SdhostSelectDevice(param_1,param_2);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar3 = SdhostSetWriteGroupDefMmc(param_1,param_2);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar3 = SdhostGetSpeedModesMmc(param_1,param_2);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar3 = SdhostGetBusWidthMmc(param_1,param_2);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar1 = *(ushort *)(param_1 + 0xcc);
  iVar2 = 8;
  if (((uVar1 & 0x20) == 0) || ((*(uint *)(param_1 + 0xb24) & 0x100) == 0)) {
    if (((uVar1 & 0x10) != 0) && ((*(uint *)(param_1 + 0xb24) & 0x40) != 0)) {
      iVar4 = 6;
      goto LAB_1c000aa88;
    }
    if (((uVar1 & 2) != 0) && ((*(uint *)(param_1 + 0xb24) & 8) != 0)) {
      iVar4 = 2;
      goto LAB_1c000aa88;
    }
  }
  else {
    iVar4 = 8;
LAB_1c000aa88:
    uVar3 = SdhostSetSpeedModeMmc(param_1,param_2,iVar4);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  uVar3 = SdhostGetMaxClockFrequency(param_1,param_2);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if (((*(uint *)(param_1 + 200) & 4) == 0) || ((*(uint *)(param_1 + 0xb24) & 4) == 0)) {
    if ((*(uint *)(param_1 + 200) & 2) == 0) goto LAB_1c000aadb;
    iVar2 = 4;
  }
  uVar3 = SdhostSetBusWidthMmc(param_1,param_2,iVar2);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
LAB_1c000aadb:
  return uVar3 & 0xffffffff;
}



===== SdhostInitializeSdMemory @ 1c000aaf4 =====

void SdhostInitializeSdMemory(longlong param_1,int *param_2)

{
  int iVar1;
  ulonglong uVar2;
  
  uVar2 = SdhostSendOpCondSd(param_1,param_2);
  if (-1 < (int)uVar2) {
    uVar2 = SdhostSendVoltageSwitchSd(param_1,param_2);
    if (-1 < (int)uVar2) {
      iVar1 = SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdSendCidAll,0,0,0,1);
      if (-1 < iVar1) {
        iVar1 = SdhostSendRelativeAddr(param_1,param_2);
        if (-1 < iVar1) {
          iVar1 = SdhostSendCid(param_1,param_2);
          if (-1 < iVar1) {
            uVar2 = SdhostSendCsd(param_1,param_2);
            if (-1 < (int)uVar2) {
              *(undefined2 *)(param_1 + 0xb8a) = 0x200;
              iVar1 = SdhostSelectDevice(param_1,param_2);
              if (-1 < iVar1) {
                iVar1 = SdhostGetSwitchStatusSd(param_1,param_2);
                if (-1 < iVar1) {
                  uVar2 = SdhostGetBusWidthSd(param_1,param_2);
                  if (-1 < (int)uVar2) {
                    iVar1 = SdhostSetSpeedModeSd(param_1,param_2);
                    if (-1 < iVar1) {
                      uVar2 = SdhostGetMaxClockFrequency(param_1,param_2);
                      if (-1 < (int)uVar2) {
                        SdhostSetSignalingVoltage(param_1,1);
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
  return;
}



===== SdhostInitializeSlot @ 1c000abf4 =====

ulonglong SdhostInitializeSlot(longlong param_1)

{
  uint *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 extraout_var;
  ulonglong uVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  ulonglong uVar13;
  uint *puVar14;
  longlong lVar15;
  bool bVar16;
  
  SdhostResetHw(param_1);
  iVar8 = SdhostResetHost(param_1,1);
  if (iVar8 < 0) {
    return CONCAT44(extraout_var,iVar8);
  }
  uVar10 = SdhostSetVoltage(param_1,1);
  if ((int)uVar10 < 0) {
    return uVar10;
  }
  uVar10 = SdhostSetClock(param_1,400);
  if ((int)uVar10 < 0) {
    return uVar10;
  }
  lVar15 = 9;
  puVar1 = (uint *)(param_1 + 200);
  puVar6 = (undefined8 *)(param_1 + 0x5a8);
  puVar7 = puVar1;
  do {
    puVar14 = puVar7;
    puVar11 = puVar6;
    uVar2 = *(undefined8 *)(puVar14 + 2);
    uVar3 = *(undefined8 *)(puVar14 + 4);
    uVar4 = *(undefined8 *)(puVar14 + 6);
    *puVar11 = *(undefined8 *)puVar14;
    puVar11[1] = uVar2;
    uVar2 = *(undefined8 *)(puVar14 + 8);
    uVar5 = *(undefined8 *)(puVar14 + 10);
    puVar11[2] = uVar3;
    puVar11[3] = uVar4;
    uVar3 = *(undefined8 *)(puVar14 + 0xc);
    uVar4 = *(undefined8 *)(puVar14 + 0xe);
    puVar11[4] = uVar2;
    puVar11[5] = uVar5;
    uVar2 = *(undefined8 *)(puVar14 + 0x10);
    uVar5 = *(undefined8 *)(puVar14 + 0x12);
    puVar11[6] = uVar3;
    puVar11[7] = uVar4;
    uVar3 = *(undefined8 *)(puVar14 + 0x14);
    uVar4 = *(undefined8 *)(puVar14 + 0x16);
    puVar11[8] = uVar2;
    puVar11[9] = uVar5;
    uVar2 = *(undefined8 *)(puVar14 + 0x18);
    uVar5 = *(undefined8 *)(puVar14 + 0x1a);
    puVar11[10] = uVar3;
    puVar11[0xb] = uVar4;
    uVar3 = *(undefined8 *)(puVar14 + 0x1c);
    uVar4 = *(undefined8 *)(puVar14 + 0x1e);
    puVar11[0xc] = uVar2;
    puVar11[0xd] = uVar5;
    puVar11[0xe] = uVar3;
    puVar11[0xf] = uVar4;
    lVar15 = lVar15 + -1;
    puVar6 = puVar11 + 0x10;
    puVar7 = puVar14 + 0x20;
  } while (lVar15 != 0);
  uVar2 = *(undefined8 *)(puVar14 + 0x22);
  uVar3 = *(undefined8 *)(puVar14 + 0x24);
  uVar4 = *(undefined8 *)(puVar14 + 0x26);
  puVar11[0x10] = *(undefined8 *)(puVar14 + 0x20);
  puVar11[0x11] = uVar2;
  uVar2 = *(undefined8 *)(puVar14 + 0x28);
  uVar5 = *(undefined8 *)(puVar14 + 0x2a);
  puVar11[0x12] = uVar3;
  puVar11[0x13] = uVar4;
  uVar3 = *(undefined8 *)(puVar14 + 0x2c);
  uVar4 = *(undefined8 *)(puVar14 + 0x2e);
  puVar11[0x14] = uVar2;
  puVar11[0x15] = uVar5;
  uVar2 = *(undefined8 *)(puVar14 + 0x30);
  uVar5 = *(undefined8 *)(puVar14 + 0x32);
  puVar11[0x16] = uVar3;
  puVar11[0x17] = uVar4;
  uVar3 = *(undefined8 *)(puVar14 + 0x34);
  uVar4 = *(undefined8 *)(puVar14 + 0x36);
  puVar11[0x18] = uVar2;
  puVar11[0x19] = uVar5;
  puVar11[0x1a] = uVar3;
  puVar11[0x1b] = uVar4;
  plVar12 = SdhostAllocateRequest(param_1);
  if (plVar12 == (longlong *)0x0) {
    return 0xc000009a;
  }
  uVar10 = SdhostQueryDeviceType(param_1,(int *)plVar12);
  uVar13 = uVar10 & 0xffffffff;
  if ((int)uVar10 < 0) goto LAB_1c000aea0;
  if (((((undefined8 *)(param_1 + 0x5a8) == (undefined8 *)0x0) || (puVar1 == (uint *)0x0)) ||
      (*(int *)(param_1 + 0x5b4) != *(int *)(param_1 + 0xd4))) ||
     (*(char *)(param_1 + 0x5b2) != *(char *)(param_1 + 0xd2))) {
LAB_1c000ad8e:
    *(undefined4 *)(param_1 + 0xb30) = 1;
    SdhostSlotStateChanged(param_1);
  }
  else {
    if (*(char *)(param_1 + 0x5b2) != '\0') {
      if (((*(short *)(param_1 + 0x606) == *(short *)(param_1 + 0x126)) &&
          (lVar15 = RtlCompareMemory(param_1 + 0x611,param_1 + 0x131,0x40), lVar15 == 0x40)) &&
         (*(char *)(param_1 + 0x604) == *(char *)(param_1 + 0x124))) {
        bVar16 = *(int *)(param_1 + 0x60c) == *(int *)(param_1 + 300);
        goto LAB_1c000ad8c;
      }
      goto LAB_1c000ad8e;
    }
    if (((*(char *)(param_1 + 0x5ca) != *(char *)(param_1 + 0xea)) ||
        (*(short *)(param_1 + 0x5cc) != *(short *)(param_1 + 0xec))) ||
       (*(char *)(param_1 + 0x5ce) != *(char *)(param_1 + 0xee))) goto LAB_1c000ad8e;
    bVar16 = *(int *)(param_1 + 0x5dc) == *(int *)(param_1 + 0xfc);
LAB_1c000ad8c:
    if (!bVar16) goto LAB_1c000ad8e;
  }
  if (*(char *)(param_1 + 0xe6) != '\0') {
    uVar10 = SdhostSendVoltageSwitchSd(param_1,(int *)plVar12);
    uVar13 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) goto LAB_1c000aea0;
    *(undefined4 *)(param_1 + 0xb48) = 0;
    uVar9 = SdhostSendRelativeAddr(param_1,(int *)plVar12);
    uVar13 = (ulonglong)uVar9;
    if ((int)uVar9 < 0) goto LAB_1c000aea0;
    uVar9 = SdhostSelectDevice(param_1,(int *)plVar12);
    uVar13 = (ulonglong)uVar9;
    if ((int)uVar9 < 0) goto LAB_1c000aea0;
    uVar9 = SdhostGetDeviceConfigurationSdio(param_1,(int *)plVar12);
    uVar13 = (ulonglong)uVar9;
    if ((int)uVar9 < 0) goto LAB_1c000aea0;
    *puVar1 = -(uint)((*(byte *)(param_1 + 0x121) & 0xc0) != 0x40) & 2 | *puVar1 & 0xfffffff9;
    uVar10 = SdhostGetSpeedModesSdio(param_1,(int *)plVar12);
    uVar13 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) goto LAB_1c000aea0;
    uVar10 = SdhostGetMaxFrequencySdio(param_1);
    uVar13 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) goto LAB_1c000aea0;
    uVar10 = SdhostSetVoltage(param_1,4);
    uVar13 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) goto LAB_1c000aea0;
  }
  if (*(char *)(param_1 + 0xe5) != '\0') {
    uVar9 = SdhostInitializeSdMemory(param_1,(int *)plVar12);
    uVar13 = (ulonglong)uVar9;
    if ((int)uVar9 < 0) goto LAB_1c000aea0;
  }
  if (*(char *)(param_1 + 0xe4) != '\0') {
    uVar10 = SdhostInitializeMmc(param_1,(int *)plVar12);
    uVar13 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) goto LAB_1c000aea0;
  }
  uVar13 = SdhostSetVoltage(param_1,4);
  uVar13 = uVar13 & 0xffffffff;
LAB_1c000aea0:
  SdhostFreeRequest((longlong)plVar12);
  return uVar13 & 0xffffffff;
}



===== SdhostInitializeSlotWorker @ 1c000aed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostInitializeSlotWorker(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  undefined1 uVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 8) + 0xc0);
  cVar2 = (**(code **)(lVar1 + 0x68))(*(undefined8 *)(param_2 + 0xa88));
  if (cVar2 != *(char *)(param_2 + 0xb3a)) {
    *(char *)(param_2 + 0xb3a) = cVar2;
    if (cVar2 == '\0') {
      memset((void *)(param_2 + 200),0,0x4e0);
      *(undefined4 *)(param_2 + 0xb30) = 0;
      SdhostSlotStateChanged(param_2);
    }
    else {
      ExAcquireFastMutex(param_2 + 0x30);
      SdhostInitializeSlot(param_2);
      ExReleaseFastMutex(param_2 + 0x30);
      if (*(char *)(param_2 + 0xb3a) != '\0') {
        uVar3 = (**(code **)(lVar1 + 0x70))(*(undefined8 *)(param_2 + 0xa88));
        *(undefined1 *)(param_2 + 0xb3b) = uVar3;
      }
    }
  }
  return;
}



===== SdhostPowerOffMmc @ 1c000af94 =====

void SdhostPowerOffMmc(longlong param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  memset(*(void **)(lVar1 + 0xaf8),0,0x200);
  iVar2 = SdhostIssueCommand(lVar1,param_2,(undefined8 *)&CmdSendExtCsdMmc,*(int *)(lVar1 + 0xb48),
                             0x200,1,*(longlong *)(lVar1 + 0xaf0),0,0,1);
  if (-1 < iVar2) {
    *(byte *)(lVar1 + 0xb3d) = *(byte *)(*(longlong *)(lVar1 + 0xaf8) + 0x21) & 1;
    iVar2 = SdhostDeselectDevice(lVar1,param_2);
    if (-1 < iVar2) {
      iVar2 = SdhostSelectDevice(lVar1,param_2);
      if (-1 < iVar2) {
        SdhostSetVoltage(lVar1,4);
      }
    }
  }
  return;
}



===== SdhostPowerOffSd @ 1c000b06c =====

undefined8 SdhostPowerOffSd(longlong param_1,int *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  SdhostDeselectDevice(lVar1,param_2);
  SdhostSelectDevice(lVar1,param_2);
  SdhostSetSignalingVoltage(lVar1,1);
  SdhostSetVoltage(lVar1,4);
  return 0;
}



===== SdhostPowerOffSdio @ 1c000b0c4 =====

void SdhostPowerOffSdio(longlong param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  uVar3 = SdhostStopSdio(param_1,param_2);
  if (-1 < (int)uVar3) {
    iVar2 = SdhostIssueCommandNoTransfer
                      (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,-0x7ffff3f8,0,0,1);
    if (-1 < iVar2) {
      SdhostSetVoltage(lVar1,4);
    }
  }
  return;
}



===== SdhostPowerOnMmc @ 1c000b130 =====

void SdhostPowerOnMmc(longlong param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  SdhostResetHw(lVar1);
  iVar2 = SdhostResetHost(lVar1,1);
  if (((((-1 < iVar2) && (uVar3 = SdhostSetVoltage(lVar1,1), -1 < (int)uVar3)) &&
       (iVar2 = SdhostSetClock(lVar1,400), -1 < iVar2)) &&
      ((iVar2 = SdhostGoIdleState(lVar1,param_2), -1 < iVar2 &&
       (iVar2 = SdhostSendOpCondMmc(lVar1,param_2), -1 < iVar2)))) &&
     ((iVar2 = SdhostIssueCommandNoTransfer(lVar1,param_2,(undefined8 *)&CmdSendCidAll,0,0,0,1),
      -1 < iVar2 &&
      ((iVar2 = SdhostSendRelativeAddr(lVar1,param_2), -1 < iVar2 &&
       (iVar2 = SdhostSelectDevice(lVar1,param_2), -1 < iVar2)))))) {
    if (*(int *)(lVar1 + 0xb68) - 8U < 2) {
      uVar3 = SdhostSetBusWidthMmc(lVar1,param_2,(uint)*(byte *)(lVar1 + 0xb51));
      if ((int)uVar3 < 0) {
        return;
      }
      uVar3 = SdhostSetSpeedModeMmc(lVar1,param_2,*(int *)(lVar1 + 0xb68));
      iVar2 = (int)uVar3;
    }
    else {
      uVar3 = SdhostSetSpeedModeMmc(lVar1,param_2,*(int *)(lVar1 + 0xb68));
      if ((int)uVar3 < 0) {
        return;
      }
      uVar3 = SdhostSetBusWidthMmc(lVar1,param_2,(uint)*(byte *)(lVar1 + 0xb51));
      iVar2 = (int)uVar3;
    }
    if ((-1 < iVar2) && (iVar2 = SdhostSetClock(lVar1,*(undefined4 *)(lVar1 + 0xe0)), -1 < iVar2)) {
      if ((*(int *)(lVar1 + 0xb68) - 8U < 2) && (iVar2 = SdhostExecuteTuning(lVar1), iVar2 < 0)) {
        return;
      }
      uVar4 = SdhostSetFunctionBlockSize
                        (param_1,param_2,
                         *(ushort *)(lVar1 + 0xb7a + (ulonglong)*(byte *)(param_1 + 0xb0) * 2));
      if (-1 < (int)uVar4) {
        SdhostStartFunction(param_1,param_2);
      }
    }
  }
  return;
}



===== SdhostPowerOnSd @ 1c000b2dc =====

void SdhostPowerOnSd(longlong param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  SdhostResetHw(lVar1);
  iVar2 = SdhostResetHost(lVar1,1);
  if ((((((-1 < iVar2) && (uVar3 = SdhostSetVoltage(lVar1,1), -1 < (int)uVar3)) &&
        (iVar2 = SdhostSetClock(lVar1,400), -1 < iVar2)) &&
       (((iVar2 = SdhostGoIdleState(lVar1,param_2), -1 < iVar2 &&
         (uVar3 = SdhostSendIfCondSd(lVar1,param_2), -1 < (int)uVar3)) &&
        ((uVar4 = SdhostSendOpCondSd(lVar1,param_2), -1 < (int)uVar4 &&
         ((uVar4 = SdhostSendVoltageSwitchSd(lVar1,param_2), -1 < (int)uVar4 &&
          (iVar2 = SdhostIssueCommandNoTransfer(lVar1,param_2,(undefined8 *)&CmdSendCidAll,0,0,0,1),
          -1 < iVar2)))))))) && (iVar2 = SdhostSendRelativeAddr(lVar1,param_2), -1 < iVar2)) &&
     ((((iVar2 = SdhostSelectDevice(lVar1,param_2), -1 < iVar2 &&
        (uVar4 = SdhostSetBusWidthSd(lVar1,param_2,4), -1 < (int)uVar4)) &&
       (iVar2 = SdhostSetSpeedModeSd(lVar1,param_2), -1 < iVar2)) &&
      (iVar2 = SdhostSetClock(lVar1,*(undefined4 *)(lVar1 + 0xe0)), -1 < iVar2)))) {
    if ((*(int *)(lVar1 + 0xb68) == 7) && (iVar2 = SdhostExecuteTuning(lVar1), iVar2 < 0)) {
      return;
    }
    uVar4 = SdhostSetFunctionBlockSize
                      (param_1,param_2,
                       *(ushort *)(lVar1 + 0xb7a + (ulonglong)*(byte *)(param_1 + 0xb0) * 2));
    if (-1 < (int)uVar4) {
      SdhostStartFunction(param_1,param_2);
    }
  }
  return;
}



===== SdhostPowerOnSdio @ 1c000b468 =====

void SdhostPowerOnSdio(longlong param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  SdhostResetHw(lVar1);
  iVar2 = SdhostResetHost(lVar1,1);
  if (((-1 < iVar2) && (uVar3 = SdhostSetVoltage(lVar1,1), -1 < (int)uVar3)) &&
     (iVar2 = SdhostSetClock(lVar1,400), -1 < iVar2)) {
    if ((*(int *)(param_1 + 0x18) != 1) &&
       (SdhostIssueCommandNoTransfer
                  (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,-0x7ffff3f8,0,0,1),
       *(int *)(lVar1 + 0xd4) == 2)) {
      SdhostGoIdleState(lVar1,param_2);
    }
    uVar4 = SdhostSendOpCondSdio(lVar1,param_2);
    if ((-1 < (int)uVar4) && (uVar4 = SdhostSendVoltageSwitchSd(lVar1,param_2), -1 < (int)uVar4)) {
      *(undefined4 *)(lVar1 + 0xb48) = 0;
      iVar2 = SdhostSendRelativeAddr(lVar1,param_2);
      if ((-1 < iVar2) &&
         ((((iVar2 = SdhostSelectDevice(lVar1,param_2), -1 < iVar2 &&
            (iVar2 = SdhostSetSpeedModeSdio(lVar1,param_2), -1 < iVar2)) &&
           (uVar3 = SdhostSetBusWidthSdio(lVar1,param_2,4), -1 < (int)uVar3)) &&
          (iVar2 = SdhostSetClock(lVar1,*(undefined4 *)(lVar1 + 0xe0)), -1 < iVar2)))) {
        if (((*(int *)(lVar1 + 0xb68) == 7) ||
            ((*(int *)(lVar1 + 0xb68) == 5 && ((*(uint *)(lVar1 + 0xb24) & 0x80000) != 0)))) &&
           (iVar2 = SdhostExecuteTuning(lVar1), iVar2 < 0)) {
          return;
        }
        uVar4 = SdhostSetFunctionBlockSize
                          (param_1,param_2,
                           *(ushort *)(lVar1 + 0xb7a + (ulonglong)*(byte *)(param_1 + 0xb0) * 2));
        if ((-1 < (int)uVar4) && (uVar4 = SdhostStartFunction(param_1,param_2), -1 < (int)uVar4)) {
          SdhostInitSdioInterrupt(param_1,param_2);
        }
      }
    }
  }
  return;
}



===== SdhostProcessTupleChain @ 1c000b614 =====

uint SdhostProcessTupleChain(longlong param_1,int *param_2,uint param_3,uint *param_4)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *param_4;
  *param_4 = uVar4 + 1;
  while( true ) {
    if (((uVar4 & 0x1ffff) < 0x1000) || (uVar4 = (uVar4 & 0x1ffff) << 9, 0x2fffe00 < uVar4)) {
      return 0xc0000001;
    }
    SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,uVar4,0,0,1);
    iVar3 = param_2[0x1e];
    *(char *)(param_4 + 1) = (char)iVar3;
    if (0xfd < (byte)((char)iVar3 - 1U)) {
      return 0;
    }
    uVar4 = *param_4 & 0x1ffff;
    *param_4 = *param_4 + 1;
    if (0x16fff < uVar4 - 0x1000) break;
    uVar4 = SdhostIssueCommandNoTransfer
                      (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,uVar4 << 9,0,0,1);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    iVar3 = param_2[0x1e];
    *(char *)((longlong)param_4 + 5) = (char)iVar3;
    *(char *)((longlong)param_4 + 6) = (char)iVar3;
    *(undefined1 *)((longlong)param_4 + 7) = 0;
    memset(param_4 + 2,0,0x100);
    cVar2 = *(char *)((longlong)param_4 + 6);
    while (cVar2 != '\0') {
      uVar4 = ((uint)*(byte *)((longlong)param_4 + 7) + *param_4) * 0x200 & 0x3fffe00;
      if (0x16fff < (uVar4 >> 9) - 0x1000) {
        return 0xc0000001;
      }
      uVar4 = SdhostIssueCommandNoTransfer
                        (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,uVar4,0,0,1);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      *(char *)((ulonglong)*(byte *)((longlong)param_4 + 7) + 8 + (longlong)param_4) =
           (char)param_2[0x1e];
      *(char *)((longlong)param_4 + 7) = *(char *)((longlong)param_4 + 7) + '\x01';
      pcVar1 = (char *)((longlong)param_4 + 6);
      *pcVar1 = *pcVar1 + -1;
      cVar2 = *pcVar1;
    }
    uVar4 = SdhostProcessTuplePacket(param_1 + 200,param_3,(longlong)param_4);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar4 = (uint)*(byte *)((longlong)param_4 + 5) + *param_4;
    *param_4 = uVar4 + 1;
  }
  return 0xc0000001;
}



===== SdhostProcessTuplePacket @ 1c000b7d8 =====

uint SdhostProcessTuplePacket(longlong param_1,uint param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  byte bVar3;
  ulonglong uVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar4 = (ulonglong)param_2;
  cVar6 = *(char *)(param_3 + 4);
  if (cVar6 != '\x15') {
    if (cVar6 == ' ') {
      if (3 < *(byte *)(param_3 + 5)) {
        *(undefined1 *)(param_1 + 0x5d + uVar4 * 0x90) = 1;
        *(undefined2 *)(param_1 + 0x5e + uVar4 * 0x90) = *(undefined2 *)(param_3 + 8);
        *(undefined2 *)(param_1 + 0x60 + uVar4 * 0x90) = *(undefined2 *)(param_3 + 10);
        return 0;
      }
    }
    else if (cVar6 == '!') {
      if (*(char *)(param_3 + 5) == '\x02') {
        return -(uint)(*(char *)(param_3 + 8) != '\f') & 0xc0000001;
      }
    }
    else {
      if (cVar6 != '\"') {
        return 0;
      }
      if (param_2 == 0) {
        if ((*(char *)(param_3 + 8) == '\0') && (3 < *(byte *)(param_3 + 5))) {
          *(undefined2 *)(param_1 + 0x62) = *(undefined2 *)(param_3 + 9);
          *(undefined1 *)(param_1 + 0x5a) = *(undefined1 *)(param_3 + 0xb);
          return 0;
        }
      }
      else if ((*(char *)(param_3 + 8) == '\x01') && (0xd < *(byte *)(param_3 + 5))) {
        *(undefined1 *)(param_1 + 0x68 + uVar4 * 0x90) = *(undefined1 *)(param_3 + 9);
        *(undefined4 *)(param_1 + 100 + uVar4 * 0x90) = *(undefined4 *)(param_3 + 0xb);
        *(undefined2 *)(param_1 + 0x62 + uVar4 * 0x90) = *(undefined2 *)(param_3 + 0x14);
        return 0;
      }
    }
    return 0xc0000001;
  }
  bVar1 = *(byte *)(param_3 + 5);
  uVar7 = 0;
  cVar6 = *(char *)(param_3 + 10);
  bVar5 = 0;
  uVar9 = 3;
  while( true ) {
    if (cVar6 == '\0') break;
    if (((uint)bVar1 < (uint)uVar9) || (0x40 < bVar5)) {
      uVar7 = 0xc0000001;
      break;
    }
    if ((byte)(cVar6 - 0x20U) < 0x5f) {
      uVar2 = (ulonglong)bVar5;
      bVar5 = bVar5 + 1;
      *(char *)(uVar2 + 0x69 + uVar4 * 0x90 + param_1) = cVar6;
    }
    cVar6 = *(char *)(uVar9 + 8 + param_3);
    uVar9 = (ulonglong)((uint)uVar9 + 1);
  }
  bVar3 = 0;
  *(undefined1 *)((ulonglong)bVar5 + uVar4 * 0x90 + 0x69 + param_1) = 0;
  cVar6 = *(char *)(uVar9 + 8 + param_3);
  do {
    uVar8 = (int)uVar9 + 1;
    uVar9 = (ulonglong)uVar8;
    if (cVar6 == '\0') {
LAB_1c000b97c:
      *(undefined1 *)((ulonglong)bVar3 + 0xaa + uVar4 * 0x90 + param_1) = 0;
      return uVar7;
    }
    if ((bVar1 < uVar8) || (0x40 < bVar3)) {
      uVar7 = 0xc0000001;
      goto LAB_1c000b97c;
    }
    if ((byte)(cVar6 - 0x20U) < 0x5f) {
      uVar2 = (ulonglong)bVar3;
      bVar3 = bVar3 + 1;
      *(char *)(uVar2 + uVar4 * 0x90 + 0xaa + param_1) = cVar6;
    }
    cVar6 = *(char *)(uVar9 + 8 + param_3);
  } while( true );
}



===== SdhostQueryDeviceType @ 1c000b9b4 =====

ulonglong SdhostQueryDeviceType(longlong param_1,int *param_2)

{
  int iVar1;
  undefined4 extraout_var;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  
  iVar1 = SdhostGoIdleState(param_1,param_2);
  uVar3 = CONCAT44(extraout_var,iVar1);
  if (-1 < iVar1) {
    uVar2 = SdhostSendIfCondSd(param_1,param_2);
    if (-1 < (int)uVar2) {
      *(char *)(param_1 + 0xe5) = '\x01';
      *(undefined4 *)(param_1 + 0xd4) = 2;
    }
    uVar3 = SdhostSendOpCondSdio(param_1,param_2);
    if (-1 < (int)uVar3) {
      *(undefined1 *)(param_1 + 0xe6) = 1;
    }
    if ((*(char *)(param_1 + 0xe5) == '\0') && (*(char *)(param_1 + 0xe6) == '\0')) {
      iVar1 = SdhostGoIdleState(param_1,param_2);
      if (iVar1 < 0) {
        return CONCAT44(extraout_var_00,iVar1);
      }
      iVar1 = SdhostSendOpCondMmc(param_1,param_2);
      uVar3 = CONCAT44(extraout_var_01,iVar1);
      if (-1 < iVar1) {
        *(undefined1 *)(param_1 + 0xe4) = 1;
        *(undefined4 *)(param_1 + 0xd4) = 3;
      }
    }
    if (((*(char *)(param_1 + 0xe5) != '\0') || (*(char *)(param_1 + 0xe6) != '\0')) ||
       (*(char *)(param_1 + 0xe4) != '\0')) {
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== SdhostResetHost @ 1c000ba94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdhostResetHost(longlong param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = 2;
  local_resc = param_2;
  iVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xc0) + 0x60))
                    (*(longlong *)
                      (*(longlong *)(param_1 + 8) + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8) +
                     0x10,&local_res8);
  if (-1 < iVar1) {
    SdhostEnableEvents(param_1,0x80fb);
  }
  return iVar1;
}



===== SdhostResetHw @ 1c000bb00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdhostResetHw(longlong param_1)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = 1;
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xc0) + 0x60))
            (*(longlong *)
              (*(longlong *)(param_1 + 8) + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8) + 0x10,
             local_res8);
  *(undefined4 *)(param_1 + 0xb48) = 0;
  return 0;
}



===== SdhostSelectDevice @ 1c000bb58 =====

void SdhostSelectDevice(longlong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = SdhostIssueCommandNoTransfer
                    (param_1,param_2,(undefined8 *)&CmdSelect,*(int *)(param_1 + 0xb48),0,0,1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 0xb50) = 1;
  }
  return;
}



===== SdhostSendAppCmd @ 1c000bba0 =====

void SdhostSendAppCmd(longlong param_1,int *param_2)

{
  SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSd,*(int *)(param_1 + 0xb48),0,0,0,0,0,1);
  return;
}



===== SdhostSendCid @ 1c000bbe4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SdhostSendCid(longlong param_1,int *param_2)

{
  undefined8 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  byte bVar7;
  uint uVar8;
  undefined1 auStackY_78 [32];
  byte local_38;
  undefined1 auStack_37 [4];
  undefined1 uStack_33;
  char acStack_32 [2];
  int local_30;
  byte bStack_2b;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar8 = 0;
  iVar5 = SdhostIssueCommandNoTransfer
                    (param_1,param_2,(undefined8 *)&CmdSendCidSd,*(int *)(param_1 + 0xb48),0,0,1);
  if (-1 < iVar5) {
    uVar1 = *(undefined8 *)(param_2 + 0x1e);
    local_38 = (byte)uVar1;
    if (*(int *)(param_1 + 0xd4) == 2) {
      iVar4 = param_2[0x21];
      uVar2 = *(undefined1 *)((longlong)param_2 + 0x86);
      local_30 = param_2[0x20];
      pcVar6 = (char *)(param_1 + 0xf3);
      do {
        if (0x5e < (byte)(acStack_32[(ulonglong)(4 - uVar8) + 1] - 0x21U)) break;
        *pcVar6 = acStack_32[(ulonglong)(4 - uVar8) + 1];
        uVar8 = uVar8 + 1;
        pcVar6 = pcVar6 + 1;
      } while (uVar8 < 5);
      auStack_37[0] = (byte)((ulonglong)uVar1 >> 8);
      acStack_32[0] = (char)((ulonglong)uVar1 >> 0x30);
      *(char *)(param_1 + 0xee) = acStack_32[0];
      stack0xffffffffffffffca = (undefined4)((ulonglong)uVar1 >> 0x10);
      bVar7 = local_38 & 0xf;
      *(undefined4 *)(param_1 + 0xfc) = stack0xffffffffffffffca;
      *(ushort *)(param_1 + 0xf0) = ((auStack_37[0] & 0xf) + 0x7d) * 0x10 + (ushort)(local_38 >> 4);
      *(undefined1 *)(param_1 + 0xea) = uVar2;
      *(short *)(param_1 + 0xec) = (short)iVar4;
    }
    else {
      pcVar6 = (char *)(param_1 + 0xf3);
      uVar2 = *(undefined1 *)((longlong)param_2 + 0x86);
      local_30 = param_2[0x20];
      uVar3 = *(ushort *)(param_2 + 0x21);
      do {
        if (0x5e < (byte)(acStack_32[5 - uVar8] - 0x21U)) break;
        *pcVar6 = acStack_32[5 - uVar8];
        uVar8 = uVar8 + 1;
        pcVar6 = pcVar6 + 1;
      } while (uVar8 < 6);
      *(undefined1 *)(param_1 + 0xea) = uVar2;
      bVar7 = local_38 >> 4;
      *(ushort *)(param_1 + 0xec) = uVar3 & 0xff;
      uStack_33 = (undefined1)((ulonglong)uVar1 >> 0x28);
      *(undefined1 *)(param_1 + 0xee) = uStack_33;
      auStack_37 = SUB84((ulonglong)uVar1 >> 8,0);
      *(undefined1 (*) [4])(param_1 + 0xfc) = auStack_37;
      bStack_2b = (byte)(uVar3 >> 8);
      *(ushort *)(param_1 + 0xf0) = (local_38 & 0xf) + 0x7cd;
      *(byte *)(param_1 + 0x113) = bStack_2b & 3;
    }
    *(byte *)(param_1 + 0xf2) = bVar7;
  }
  return iVar5;
}



===== SdhostSendCsd @ 1c000bda4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SdhostSendCsd(longlong param_1,int *param_2)

{
  ulonglong uVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  ushort uVar5;
  ulonglong uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  byte bStack_31;
  
  uVar8 = 0;
  uVar6 = SdhostIssueCommandNoTransfer
                    (param_1,param_2,(undefined8 *)&CmdSendCsdSd,*(int *)(param_1 + 0xb48),0,0,1);
  if (-1 < (int)uVar6) {
    iVar3 = param_2[0x20];
    uVar1 = *(ulonglong *)(param_2 + 0x1e);
    bStack_31 = (byte)(uVar1 >> 0x38);
    uVar9 = CONCAT31((int3)iVar3,bStack_31);
    uVar7 = (undefined1)((uint)iVar3 >> 0x18);
    bVar4 = (byte)((uint)iVar3 >> 8);
    uVar5 = (ushort)((uint)iVar3 >> 8);
    if (*(int *)(param_1 + 0xd4) == 2) {
      bVar2 = *(byte *)((longlong)param_2 + 0x86);
      *(undefined1 *)(param_1 + 0x112) = uVar7;
      if ((bVar2 & 0xc0) == 0) {
        *(ushort *)(param_1 + 0x100) = uVar5 >> 4;
        lVar11 = 1L << ((byte)((uint)((uVar1 & 0xffffffffffffff) >> 0x18) >> 0xf) & 7) + 2;
        uVar9 = (uVar9 & 0x3ff) << 2 | (uint)((uVar1 & 0xffffffffffffff) >> 0x36);
        uVar10 = 1L << (bVar4 & 0xf);
      }
      else {
        lVar11 = 0x200;
        uVar10 = 0x400;
        *(ushort *)(param_1 + 0x100) = uVar5 >> 4;
        uVar9 = (uint)(ushort)(uVar1 >> 0x28) | (bStack_31 & 0x3f) << 0x10;
      }
      if ((*(char *)(param_1 + 0xb3b) != '\0') || ((uVar1 & 0x20) != 0)) {
        uVar8 = 1;
      }
      *(undefined1 *)(param_1 + 0xb3b) = uVar8;
      *(short *)(param_1 + 0x110) = (short)uVar10;
    }
    else {
      bVar2 = *(byte *)((longlong)param_2 + 0x86);
      *(undefined1 *)(param_1 + 0x112) = uVar7;
      *(byte *)(param_1 + 0xe8) = bVar2 >> 2 & 0xf;
      *(ushort *)(param_1 + 0x100) = uVar5 >> 4;
      uVar9 = (uint)(ushort)(((ushort)uVar9 & 0x3ff) << 2) |
              (uint)((uVar1 & 0xffffffffffffff) >> 0x36);
      lVar11 = 1L << ((byte)((uint)((uVar1 & 0xffffffffffffff) >> 0x18) >> 0xf) & 7) + 2;
      uVar5 = 1 << (bVar4 & 0xf);
      uVar10 = (ulonglong)uVar5;
      *(ushort *)(param_1 + 0x110) = uVar5;
      if ((*(char *)(param_1 + 0xb3b) != '\0') || ((uVar1 & 0x20) != 0)) {
        uVar8 = 1;
      }
      *(undefined1 *)(param_1 + 0xb3b) = uVar8;
    }
    *(ulonglong *)(param_1 + 0x108) = (uVar9 + 1) * uVar10 * lVar11;
    uVar6 = uVar6 & 0xffffffff;
  }
  return uVar6;
}



===== SdhostSendIfCondSd @ 1c000bfa0 =====

undefined8 SdhostSendIfCondSd(longlong param_1,int *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar2 = -(uint)((*(uint *)(param_1 + 0xb58) & 0x80) != 0) & 0x100;
  uVar1 = SdhostIssueCommandNoTransfer
                    (param_1,param_2,(undefined8 *)&CmdSendIfCondSd,uVar2 + 0x1aa,0,0,1);
  if (-1 < (int)uVar1) {
    if (((char)param_2[0x1e] != -0x56) || ((param_2[0x1e] & 0xf00U) != uVar2 + 0x100)) {
      uVar1 = 0xc00000bb;
    }
    *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) | 0x10;
  }
  return uVar1;
}



===== SdhostSendOpCondMmc @ 1c000c02c =====

int SdhostSendOpCondMmc(longlong param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  bVar3 = 0;
  while( true ) {
    iVar2 = SdhostIssueCommandNoTransfer
                      (param_1,param_2,(undefined8 *)&CmdSendOpCondMmc,0x40ff8000,0,0,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    uVar1 = param_2[0x1e];
    if ((int)uVar1 < 0) break;
    SdhostWait(2000);
    bVar3 = bVar3 + 1;
    if (0x31 < bVar3) {
      return iVar2;
    }
  }
  uVar4 = *(uint *)(param_1 + 200) | 1;
  if ((uVar1 & 0x60000000) != 0x40000000) {
    uVar4 = *(uint *)(param_1 + 200) & 0xfffffffe;
  }
  *(uint *)(param_1 + 200) = uVar4;
  if ((uVar1 & 0xff8000) != 0xff8000) {
    iVar2 = -0x3fffff45;
  }
  *(uint *)(param_1 + 0xb5c) = uVar1 & 0xffffff;
  SdhostWait(2000);
  return iVar2;
}



===== SdhostSendOpCondSd @ 1c000c108 =====

ulonglong SdhostSendOpCondSd(longlong param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = SdhostSendAppCmd(param_1,param_2);
  if (-1 < (int)uVar3) {
    iVar1 = SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdAppSendOpCondSd,0,0,0,1);
    if (-1 < iVar1) {
      *(uint *)(param_1 + 0xb5c) = param_2[0x1e] & 0xffffff;
    }
    uVar4 = 0;
    do {
      uVar3 = SdhostSendAppCmd(param_1,param_2);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar2 = SdhostIssueCommandNoTransfer
                        (param_1,param_2,(undefined8 *)&CmdAppSendOpCondSd,
                         (-(uint)((*(uint *)(param_1 + 200) & 0x10) != 0) & 0x50000000) + 0x1000000
                         | *(uint *)(param_1 + 0xb5c),0,0,1);
      uVar3 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_1c000c233;
      uVar2 = param_2[0x1e];
      if ((int)uVar2 < 0) {
        uVar4 = *(uint *)(param_1 + 200);
        if ((uVar4 & 0x10) != 0) {
          uVar5 = uVar4 | 1;
          if ((uVar2 >> 0x1e & 1) == 0) {
            uVar5 = uVar4 & 0xfffffffe;
          }
          *(uint *)(param_1 + 200) = uVar5;
          if (*(int *)(param_1 + 0xb6c) != 2) {
            *(uint *)(param_1 + 200) = (uVar2 >> 0x15 ^ uVar5) & 8 ^ uVar5;
          }
        }
        break;
      }
      SdhostWait(2000);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 500);
    if (-1 < param_2[0x1e]) {
      uVar3 = 0xc00000b5;
    }
  }
LAB_1c000c233:
  return uVar3;
}



===== SdhostSendOpCondSdio @ 1c000c250 =====

ulonglong SdhostSendOpCondSdio(longlong param_1,int *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  byte bVar4;
  
  uVar2 = SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdSendOpCondSdio,0,0,0,1);
  if (-1 < (int)uVar2) {
    uVar1 = param_2[0x1e];
    bVar4 = (byte)(uVar1 >> 0x18);
    uVar3 = uVar1 >> 0x1c & 7;
    *(uint *)(param_1 + 0xb40) = uVar3;
    *(byte *)(param_1 + 0xd2) = bVar4 >> 4 & 7;
    *(byte *)(param_1 + 0xb46) = bVar4 >> 3 & 1;
    if (uVar3 == 0) {
      uVar2 = 0xc00000bb;
    }
    else {
      *(uint *)(param_1 + 0xb5c) = uVar1 & 0xffffff;
      bVar4 = 0;
      do {
        uVar1 = *(uint *)(param_1 + 0xb58) | 0x100;
        if (*(int *)(param_1 + 0xb5c) != 0x80) {
          uVar1 = *(uint *)(param_1 + 0xb58);
        }
        uVar1 = SdhostIssueCommandNoTransfer
                          (param_1,param_2,(undefined8 *)&CmdSendOpCondSdio,uVar1,0,0,1);
        uVar2 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) break;
        if (param_2[0x1e] < 0) {
          *(uint *)(param_1 + 200) =
               ((uint)param_2[0x1e] >> 0x15 ^ *(uint *)(param_1 + 200)) & 8 ^
               *(uint *)(param_1 + 200);
          break;
        }
        SdhostWait(2000);
        bVar4 = bVar4 + 1;
      } while (bVar4 < 10);
    }
  }
  return uVar2;
}



===== SdhostSendRelativeAddr @ 1c000c36c =====

void SdhostSendRelativeAddr(longlong param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = (uint *)(param_1 + 0xb48);
  if (*(int *)(param_1 + 0xd4) == 3) {
    *puVar1 = 0xcccc0000;
  }
  iVar2 = SdhostIssueCommandNoTransfer
                    (param_1,param_2,(undefined8 *)&CmdSendRelativeAddr,*puVar1,0,0,1);
  if ((-1 < iVar2) && (*(int *)(param_1 + 0xd4) != 3)) {
    *puVar1 = param_2[0x1e] & 0xffff0000;
  }
  return;
}



===== SdhostSendVoltageSwitchSd @ 1c000c3e8 =====

ulonglong SdhostSendVoltageSwitchSd(longlong param_1,int *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = 0;
  if ((((*(uint *)(param_1 + 200) & 8) != 0) && ((*(uint *)(param_1 + 0xb24) & 0x10) != 0)) &&
     (*(int *)(param_1 + 0xb6c) != 2)) {
    uVar1 = SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdSwitchVoltageSd,0,0,0,1);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    uVar2 = SdhostSetSignalingVoltage(param_1,2);
    uVar1 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  return uVar1;
}



===== SdhostSetBusSpeed @ 1c000c458 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostSetBusSpeed(longlong param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = 7;
  local_resc = param_2;
  iVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xc0) + 0x60))
                    (*(longlong *)
                      (*(longlong *)(param_1 + 8) + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8) +
                     0x10,&local_res8);
  if (-1 < iVar1) {
    *(undefined4 *)(param_1 + 0xb68) = param_2;
  }
  return;
}



===== SdhostSetBusWidth @ 1c000c4b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostSetBusWidth(longlong param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = 6;
  local_resc = param_2;
  iVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xc0) + 0x60))
                    (*(longlong *)
                      (*(longlong *)(param_1 + 8) + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8) +
                     0x10,&local_res8);
  if (-1 < iVar1) {
    *(char *)(param_1 + 0xb51) = (char)param_2;
  }
  return;
}



===== SdhostSetBusWidthMmc @ 1c000c51c =====

undefined8 SdhostSetBusWidthMmc(longlong param_1,int *param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  ushort uVar3;
  undefined8 uVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  
  uVar4 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSendExtCsdMmc,
                             *(int *)(param_1 + 0xb48),0x200,1,*(longlong *)(param_1 + 0xaf0),0,0,1)
  ;
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  lVar2 = *(longlong *)(param_1 + 0xaf8);
  uVar3 = *(ushort *)(param_1 + 0xce);
  *(ulonglong *)(param_1 + 0x108) = (ulonglong)*(uint *)(lVar2 + 0xd4) << 9;
  *(uint *)(param_1 + 0x118) = (uint)*(byte *)(lVar2 + 0xf7) * 10;
  uVar6 = 0;
  do {
    bVar5 = (byte)uVar6;
    uVar6 = uVar6 + 1;
    uVar3 = (*(byte *)(lVar2 + 0xc5) & (byte)(1 << (bVar5 & 0x1f))) != 0 | uVar3;
    *(ushort *)(param_1 + 0xce) = uVar3;
  } while (uVar6 < 4);
  if (param_3 == 8) {
    if (*(int *)(param_1 + 0xb68) != 8) {
      if (*(int *)(param_1 + 0xb68) == 6) {
LAB_1c000c649:
        uVar6 = (uint)*(byte *)(lVar2 + 0xef);
      }
      else if (*(char *)(lVar2 + 0xc4) == '\x01') {
        uVar6 = (uint)*(byte *)(lVar2 + 0xcb);
      }
      else {
        uVar6 = (uint)*(byte *)(lVar2 + 0xca);
      }
LAB_1c000c651:
      uVar6 = (uVar6 & 0xffffff0) << 4;
      goto LAB_1c000c681;
    }
    uVar6 = (uint)*(byte *)(lVar2 + 0xed);
  }
  else {
    if (param_3 != 4) {
      return 0xc00000bb;
    }
    if (*(int *)(param_1 + 0xb68) == 8) {
      uVar6 = (uint)*(byte *)(lVar2 + 0xed);
      goto LAB_1c000c651;
    }
    if (*(int *)(param_1 + 0xb68) == 6) goto LAB_1c000c649;
    if (*(char *)(lVar2 + 0xc4) == '\x01') {
      bVar5 = *(byte *)(lVar2 + 0xcb);
    }
    else {
      bVar5 = *(byte *)(lVar2 + 0xca);
    }
    uVar6 = bVar5 & 0xf;
  }
  uVar6 = uVar6 << 8;
LAB_1c000c681:
  if (uVar6 != 0) {
    SdhostIssueCommandNoTransfer
              (param_1,param_2,(undefined8 *)&CmdSwitchMmc,uVar6 | 0x3bb0000,0,0,1);
  }
  iVar1 = *(int *)(param_1 + 0xb68);
  if (param_3 == 8) {
    *(undefined1 *)(param_1 + 0xb51) = 8;
    iVar7 = 0x3b70600;
    if (iVar1 != 6) {
      iVar7 = 0x3b70200;
    }
  }
  else {
    iVar7 = 0x3b70100;
    if (iVar1 == 6) {
      iVar7 = 0x3b70500;
    }
  }
  uVar4 = SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdSwitchMmc,iVar7,0,0,1);
  if (((-1 < (int)uVar4) && (uVar4 = SdhostSetBusWidth(param_1,param_3), -1 < (int)uVar4)) &&
     (*(int *)(param_1 + 0xb68) == 6)) {
    uVar4 = SdhostSetBusSpeed(param_1,6);
  }
  return uVar4;
}



===== SdhostSetBusWidthSd @ 1c000c754 =====

ulonglong SdhostSetBusWidthSd(longlong param_1,int *param_2,int param_3)

{
  byte *pbVar1;
  ulonglong uVar2;
  int iVar3;
  
  if ((param_3 == 1) || (param_3 == 4)) {
    iVar3 = 0;
    if (((*(uint *)(param_1 + 200) & 2) != 0) && (iVar3 = 0, param_3 == 4)) {
      iVar3 = 2;
    }
    uVar2 = SdhostSendAppCmd(param_1,param_2);
    if (-1 < (int)uVar2) {
      uVar2 = SdhostIssueCommandNoTransfer
                        (param_1,param_2,(undefined8 *)&CmdAppSetBusWidthSd,iVar3,0,0,1);
      if (-1 < (int)uVar2) {
        uVar2 = SdhostSendAppCmd(param_1,param_2);
        if (-1 < (int)uVar2) {
          uVar2 = SdhostIssueCommandNoTransfer
                            (param_1,param_2,(undefined8 *)&CmdAppSetClrCardDetectSd,0,0,0,1);
          if (-1 < (int)uVar2) {
            if (((*(uint *)(param_1 + 200) & 2) == 0) || (param_3 != 4)) {
              if (param_3 == 1) {
                *(undefined1 *)(param_1 + 0xb51) = 1;
              }
            }
            else {
              *(undefined1 *)(param_1 + 0xb51) = 4;
            }
            uVar2 = SdhostSetBusWidth(param_1,(uint)*(byte *)(param_1 + 0xb51));
            if (-1 < (int)uVar2) {
              uVar2 = SdhostSendAppCmd(param_1,param_2);
              if (-1 < (int)uVar2) {
                pbVar1 = *(byte **)(param_1 + 0xaf8);
                pbVar1[0] = 0;
                pbVar1[1] = 0;
                pbVar1[2] = 0;
                pbVar1[3] = 0;
                pbVar1[4] = 0;
                pbVar1[5] = 0;
                pbVar1[6] = 0;
                pbVar1[7] = 0;
                uVar2 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSendScrSd,
                                           *(int *)(param_1 + 0xb48),8,1,
                                           *(longlong *)(param_1 + 0xaf0),0,0,1);
                if (-1 < (int)uVar2) {
                  *(byte *)(param_1 + 0xe8) = *pbVar1 & 0xf;
                  *(uint *)(param_1 + 200) =
                       pbVar1[1] >> 1 & 2 | *(uint *)(param_1 + 200) & 0xfffffffd;
                  *(byte *)(param_1 + 0x114) = pbVar1[3] >> 1 & 1;
                  *(byte *)(param_1 + 0xe9) = pbVar1[2] >> 7;
                  uVar2 = uVar2 & 0xffffffff;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== SdhostSetBusWidthSdio @ 1c000c928 =====

undefined8 SdhostSetBusWidthSdio(longlong param_1,int *param_2,int param_3)

{
  undefined8 uVar1;
  byte bVar2;
  
  if ((param_3 == 1) || (param_3 == 4)) {
    uVar1 = SdhostIssueCommandNoTransfer
                      (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,0xe00,0,0,1);
    if (-1 < (int)uVar1) {
      bVar2 = *(byte *)(param_2 + 0x1e) & 0xfc;
      if (((*(uint *)(param_1 + 200) & 2) != 0) && (param_3 == 4)) {
        bVar2 = bVar2 | 2;
      }
      uVar1 = SdhostIssueCommandNoTransfer
                        (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,bVar2 | 0x80000e00,0,
                         0,1);
      if (-1 < (int)uVar1) {
        bVar2 = (-((bVar2 & 2) != 0) & 3U) + 1;
        *(byte *)(param_1 + 0xb51) = bVar2;
        uVar1 = SdhostSetBusWidth(param_1,(uint)bVar2);
      }
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== SdhostSetClock @ 1c000ca04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostSetClock(longlong param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = 3;
  local_resc = param_2;
  iVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xc0) + 0x60))
                    (*(longlong *)
                      (*(longlong *)(param_1 + 8) + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8) +
                     0x10,&local_res8);
  if (-1 < iVar1) {
    *(undefined4 *)(param_1 + 0xb54) = param_2;
  }
  return;
}



===== SdhostSetFunctionBlockSize @ 1c000ca64 =====

ulonglong SdhostSetFunctionBlockSize(longlong param_1,int *param_2,ushort param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (param_3 == 0) {
    if (*(int *)(param_1 + 0xb4) == 1) {
      return 0;
    }
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x598);
    if ((param_3 <= *(ushort *)(lVar1 + 0xb0a)) &&
       ((*(byte *)(param_1 + 0xb0) != 8 || (param_3 == 0x200)))) {
      if (*(int *)(param_1 + 0xb4) - 2U < 2) {
        if (*(int *)(lVar1 + 0xb68) == 6) {
          return 0;
        }
        uVar2 = SdhostIssueCommandNoTransfer
                          (lVar1,param_2,(undefined8 *)&CmdSetBlockLength,(uint)param_3,0,0,1);
        *(ushort *)(lVar1 + 0xb7a + (ulonglong)*(byte *)(param_1 + 0xb0) * 2) = param_3;
        return uVar2;
      }
      uVar2 = SdhostIssueCommandNoTransfer
                        (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,
                         (uint)*(byte *)(param_1 + 0xb0) * 0x20000 + 0x2000 | param_3 & 0xff |
                         0x80000000,0,0,1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar2 = SdhostIssueCommandNoTransfer
                        (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,
                         (uint)*(byte *)(param_1 + 0xb0) * 0x20000 + 0x2200 | (uint)(param_3 >> 8) |
                         0x80000000,0,0,1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      *(ushort *)(lVar1 + 0xb7a + (ulonglong)*(byte *)(param_1 + 0xb0) * 2) = param_3;
      return uVar2 & 0xffffffff;
    }
  }
  return 0xc000000d;
}



===== SdhostSetSignalingVoltage @ 1c000cbe4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostSetSignalingVoltage(longlong param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res8 = 8;
  local_resc = param_2;
  iVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xc0) + 0x60))
                    (*(longlong *)
                      (*(longlong *)(param_1 + 8) + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8) +
                     0x10,&local_res8);
  if (-1 < iVar1) {
    *(undefined4 *)(param_1 + 0xb6c) = param_2;
  }
  return;
}



===== SdhostSetSpeedModeMmc @ 1c000cc44 =====

undefined8 SdhostSetSpeedModeMmc(longlong param_1,int *param_2,int param_3)

{
  undefined8 uVar1;
  int iVar2;
  
  if (param_3 == 1) {
    iVar2 = 0;
  }
  else if ((param_3 == 2) || (param_3 == 6)) {
    iVar2 = 0x3b90100;
  }
  else {
    if (param_3 != 8) {
      return 0xc000000d;
    }
    iVar2 = 0x3b90200;
  }
  uVar1 = SdhostIssueCommandNoTransfer(param_1,param_2,(undefined8 *)&CmdSwitchMmc,iVar2,0,0,1);
  if (-1 < (int)uVar1) {
    iVar2 = 2;
    if (param_3 != 6) {
      iVar2 = param_3;
    }
    uVar1 = SdhostSetBusSpeed(param_1,iVar2);
    if (-1 < (int)uVar1) {
      *(int *)(param_1 + 0xb68) = param_3;
    }
  }
  return uVar1;
}



===== SdhostSetSpeedModeSd @ 1c000cce4 =====

void SdhostSetSpeedModeSd(longlong param_1,int *param_2)

{
  byte *pbVar1;
  uint uVar2;
  char *_Dst;
  int iVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(param_1 + 0xb24);
  uVar4 = 0xffffff;
  pbVar1 = (byte *)(param_1 + 0xcc);
  if (((char)uVar2 < '\0') && ((*pbVar1 & 8) != 0)) {
    uVar4 = 0xfffff3;
    *(undefined4 *)(param_1 + 0xb68) = 7;
  }
  else if (((uVar2 & 0x40) == 0) || ((*pbVar1 & 0x10) == 0)) {
    if (((uVar2 & 0x20) == 0) || ((*pbVar1 & 4) == 0)) {
      if (((uVar2 & 8) == 0) || ((*pbVar1 & 2) == 0)) {
        *(undefined4 *)(param_1 + 0xb68) = 1;
      }
      else {
        uVar4 = 0xfffff1;
        *(undefined4 *)(param_1 + 0xb68) = 2;
      }
      goto LAB_1c000ce11;
    }
    uVar4 = 0xfffff2;
    *(undefined4 *)(param_1 + 0xb68) = 5;
  }
  else {
    uVar4 = 0xfffff4;
    *(undefined4 *)(param_1 + 0xb68) = 6;
  }
  if (((uVar2 >> 0x1d & 1) == 0) || ((*(byte *)(param_1 + 0xd0) & 8) == 0)) {
    if (((uVar2 >> 0x1c & 1) == 0) || ((*(byte *)(param_1 + 0xd0) & 4) == 0)) {
      if (((uVar2 >> 0x1b & 1) == 0) || ((*(byte *)(param_1 + 0xd0) & 2) == 0)) {
        if (((uVar2 >> 0x1a & 1) != 0) && ((*(byte *)(param_1 + 0xd0) & 1) != 0)) {
          uVar4 = uVar4 & 0xff0fff;
          *(undefined1 *)(param_1 + 0xb70) = 1;
        }
      }
      else {
        uVar4 = uVar4 & 0xff1fff;
        *(undefined1 *)(param_1 + 0xb70) = 2;
      }
    }
    else {
      uVar4 = uVar4 & 0xff2fff;
      *(undefined1 *)(param_1 + 0xb70) = 3;
    }
  }
  else {
    uVar4 = uVar4 & 0xff3fff;
    *(undefined1 *)(param_1 + 0xb70) = 4;
  }
LAB_1c000ce11:
  _Dst = *(char **)(param_1 + 0xaf8);
  memset(_Dst,0,0x40);
  iVar3 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSwitchSd,uVar4 | 0x80000000,0x40,1,
                             *(longlong *)(param_1 + 0xaf0),0,0,1);
  if (-1 < iVar3) {
    if ((*_Dst == '\0') && (_Dst[1] == '\0')) {
      *(undefined4 *)(param_1 + 0xb68) = 1;
      *(undefined1 *)(param_1 + 0xb70) = 0;
    }
    SdhostSetBusSpeed(param_1,*(undefined4 *)(param_1 + 0xb68));
  }
  return;
}



===== SdhostSetSpeedModeSdio @ 1c000ceb4 =====

void SdhostSetSpeedModeSdio(longlong param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0xb24);
  iVar2 = -0x7fffda00;
  if (((char)uVar1 < '\0') && ((*(byte *)(param_1 + 0xcc) & 8) != 0)) {
    iVar2 = -0x7fffd9fa;
    *(undefined4 *)(param_1 + 0xb68) = 7;
  }
  else if (((uVar1 & 0x40) == 0) || ((*(byte *)(param_1 + 0xcc) & 0x10) == 0)) {
    if (((uVar1 & 0x20) == 0) || ((*(byte *)(param_1 + 0xcc) & 4) == 0)) {
      if (((uVar1 & 8) == 0) || ((*(byte *)(param_1 + 0xcc) & 2) == 0)) {
        *(undefined4 *)(param_1 + 0xb68) = 1;
      }
      else {
        iVar2 = -0x7fffd9fe;
        *(undefined4 *)(param_1 + 0xb68) = 2;
      }
    }
    else {
      iVar2 = -0x7fffd9fc;
      *(undefined4 *)(param_1 + 0xb68) = 5;
    }
  }
  else {
    iVar2 = -0x7fffd9f8;
    *(undefined4 *)(param_1 + 0xb68) = 6;
  }
  iVar2 = SdhostIssueCommandNoTransfer
                    (param_1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,iVar2,0,0,1);
  if (iVar2 < 0) {
    *(undefined4 *)(param_1 + 0xb68) = 1;
  }
  else {
    SdhostSetBusSpeed(param_1,*(undefined4 *)(param_1 + 0xb68));
  }
  return;
}



===== SdhostSetVoltage @ 1c000cfa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdhostSetVoltage(longlong param_1,int param_2)

{
  undefined8 uVar1;
  undefined4 local_res8;
  int local_resc;
  
  local_res8 = 4;
  local_resc = param_2;
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xc0) + 0x60))
                    (*(longlong *)
                      (*(longlong *)(param_1 + 8) + 0xf0 + (ulonglong)*(byte *)(param_1 + 4) * 8) +
                     0x10,&local_res8);
  if (-1 < (int)uVar1) {
    *(int *)(param_1 + 0xb60) = param_2;
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 0xb58) = 0x200000;
    }
    else if (param_2 == 2) {
      *(undefined4 *)(param_1 + 0xb58) = 0x40000;
    }
    else if (param_2 == 3) {
      *(undefined4 *)(param_1 + 0xb58) = 0x80;
    }
    else if (param_2 == 4) {
      *(undefined4 *)(param_1 + 0xb58) = 0;
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== SdhostSetWriteGroupDefMmc @ 1c000d048 =====

ulonglong SdhostSetWriteGroupDefMmc(longlong param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  *(undefined2 *)(param_1 + 0x11c) = 0;
  *(undefined1 *)(param_1 + 0x11e) = 0;
  *(undefined1 *)(param_1 + 0xb3c) = 0;
  if ((*(int *)(param_1 + 0xd4) == 3) && (3 < *(byte *)(param_1 + 0xe8))) {
    memset(*(void **)(param_1 + 0xaf8),0,0x200);
    uVar2 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSendExtCsdMmc,
                               *(int *)(param_1 + 0xb48),0x200,1,*(longlong *)(param_1 + 0xaf0),0,0,
                               1);
    uVar3 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      lVar1 = *(longlong *)(param_1 + 0xaf8);
      *(undefined1 *)(param_1 + 0x11c) = *(undefined1 *)(lVar1 + 0xe0);
      *(undefined1 *)(param_1 + 0x11d) = *(undefined1 *)(lVar1 + 0xdd);
      uVar2 = uVar3;
      if ((*(char *)(lVar1 + 0xe0) != '\0') && (*(char *)(lVar1 + 0xdd) != '\0')) {
        *(undefined1 *)(param_1 + 0x11e) = 1;
        uVar3 = SdhostIssueCommandNoTransfer
                          (param_1,param_2,(undefined8 *)&CmdSwitchMmc,0x3af0100,0,0,1);
        uVar2 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        *(undefined1 *)(param_1 + 0xb3c) = 1;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== SdhostStartFunction @ 1c000d188 =====

ulonglong SdhostStartFunction(longlong param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if ((*(int *)(param_1 + 0xb4) - 2U < 2) || ((*(uint *)(param_1 + 0x608) & 1) != 0)) {
    uVar2 = 0;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x598);
    uVar2 = SdhostIssueCommandNoTransfer
                      (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,
                       (uint)*(byte *)(lVar1 + 0xb44) |
                       1 << (*(byte *)(param_1 + 0xb0) & 0x1f) & 0xffU | 0x80000400,0,0,1);
    if (-1 < (int)uVar2) {
      *(byte *)(lVar1 + 0xb44) =
           *(byte *)(lVar1 + 0xb44) | (byte)(1 << (*(byte *)(param_1 + 0xb0) & 0x1f));
      uVar2 = uVar2 & 0xffffffff;
    }
  }
  return uVar2;
}



===== SdhostStartSdio @ 1c000d228 =====

void SdhostStartSdio(longlong param_1,int *param_2)

{
  ulonglong uVar1;
  
  uVar1 = SdhostSetFunctionBlockSize
                    (param_1,param_2,
                     *(ushort *)
                      (*(longlong *)(param_1 + 0x598) + 0xb7a +
                      (ulonglong)*(byte *)(param_1 + 0xb0) * 2));
  if (-1 < (int)uVar1) {
    uVar1 = SdhostStartFunction(param_1,param_2);
    if (-1 < (int)uVar1) {
      SdhostInitSdioInterrupt(param_1,param_2);
    }
  }
  return;
}



===== SdhostStopSdio @ 1c000d288 =====

ulonglong SdhostStopSdio(longlong param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = SdhostEnableSdioInterrupt(param_1,param_2,'\0');
  if (-1 < (int)uVar2) {
    if ((1 < *(int *)(param_1 + 0xb4) - 2U) && ((*(uint *)(param_1 + 0x608) & 1) == 0)) {
      lVar1 = *(longlong *)(param_1 + 0x598);
      uVar2 = SdhostIssueCommandNoTransfer
                        (lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,
                         (uint)*(byte *)(lVar1 + 0xb44) & ~(1 << (*(byte *)(param_1 + 0xb0) & 0x1f))
                         | 0x80000400,0,0,1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      *(byte *)(lVar1 + 0xb44) =
           *(byte *)(lVar1 + 0xb44) & ~(byte)(1 << (*(byte *)(param_1 + 0xb0) & 0x1f));
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== SdhostTuningWorker @ 1c000d340 =====

void SdhostTuningWorker(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  IoFreeWorkItem(param_3);
  return;
}



===== SdhostGetRegistryCommandFlags @ 1c000d360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SdhostGetRegistryCommandFlags(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  ushort uVar2;
  ulonglong uVar3;
  undefined1 auStack_288 [32];
  undefined4 local_268;
  undefined4 *local_260;
  undefined4 local_258 [2];
  undefined8 local_250;
  undefined8 uStack_248;
  undefined1 local_238 [8];
  uint local_230;
  byte abStack_22c [516];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_288;
  local_250 = 0;
  uStack_248 = 0;
  local_258[0] = 0;
  RtlInitUnicodeString(&local_250);
  local_260 = local_258;
  local_268 = 0x210;
  iVar1 = ZwQueryValueKey(param_1,&local_250,2,local_238);
  if ((-1 < iVar1) && (uVar3 = 0, local_230 >> 1 != 0)) {
    do {
      uVar2 = (short)uVar3 + 1;
      *(byte *)((ulonglong)abStack_22c[uVar3 * 2] + param_3) = abStack_22c[uVar3 * 2 + 1];
      uVar3 = (ulonglong)uVar2;
    } while ((uint)uVar2 < local_230 >> 1);
  }
  return;
}



===== SdhostLoadGlobalRegistryValues @ 1c000d418 =====

undefined8 SdhostLoadGlobalRegistryValues(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined **ppuVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  longlong lVar10;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res10 = 0;
  local_res18[0] = 0;
  local_54 = 0;
  local_68 = 0;
  uStack_60 = 0;
  lVar3 = ExAllocatePool2(0x100,0x540,0x65476453);
  if (lVar3 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    lVar6 = 0x17;
    ppuVar7 = &PTR_PollTimerInterval_1c001c008;
    ppuVar8 = &PTR_PollTimerInterval_1c001c008;
    puVar9 = &DAT_1c001c010;
    lVar10 = 0x17;
    puVar5 = (undefined8 *)(lVar3 + 0x10);
    do {
      *(undefined4 *)(puVar5 + -1) = 0x20;
      *puVar5 = ppuVar8[-1];
      puVar1 = *ppuVar8;
      ppuVar8 = ppuVar8 + 3;
      puVar5[3] = puVar9;
      puVar9 = puVar9 + 6;
      puVar5[1] = puVar1;
      *(undefined4 *)(puVar5 + 2) = 4;
      *(undefined4 *)(puVar5 + 4) = 4;
      lVar10 = lVar10 + -1;
      puVar5 = puVar5 + 7;
    } while (lVar10 != 0);
    iVar2 = RtlQueryRegistryValuesEx(0x80000001,L"Sdhost\\Parameters",lVar3,0,0);
    ExFreePoolWithTag(lVar3,0x65476453);
    if (iVar2 < 0) {
      do {
        puVar9 = (undefined4 *)*ppuVar7;
        ppuVar8 = ppuVar7 + 1;
        ppuVar7 = ppuVar7 + 3;
        *puVar9 = *(undefined4 *)ppuVar8;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
    }
    local_54 = 0;
    local_3c = 0;
    local_50 = 0;
    local_58 = 0x30;
    local_40 = 0x240;
    local_38 = 0;
    uStack_30 = 0;
    local_48 = (undefined8 *)param_1;
    iVar2 = ZwOpenKey(local_res18,0x20019,&local_58);
    if (-1 < iVar2) {
      RtlInitUnicodeString(&local_68,L"Parameters");
      local_54 = 0;
      local_3c = 0;
      local_50 = local_res18[0];
      local_48 = &local_68;
      local_58 = 0x30;
      local_40 = 0x240;
      local_38 = 0;
      uStack_30 = 0;
      iVar2 = ZwOpenKey(&local_res10,0x20019,&local_58);
      if (-1 < iVar2) {
        SdhostGetRegistryCommandFlags(local_res10,L"SdCmdFlags",0x1c0012080);
        SdhostGetRegistryCommandFlags(local_res10,L"SdAppCmdFlags",0x1c0012180);
        ZwClose(local_res10);
      }
      ZwClose(local_res18[0]);
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== SdhostSetDefaultSettings @ 1c000d620 =====

void SdhostSetDefaultSettings(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x68) = 1;
  *(undefined4 *)(param_1 + 0x80) = 10000;
  *(undefined1 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x84) = 10000;
  *(undefined4 *)(param_1 + 0x88) = 10000;
  *(undefined4 *)(param_1 + 0x8c) = 10000;
  *(undefined4 *)(param_1 + 0x98) = 10000;
  *(undefined4 *)(param_1 + 0x9c) = 10000;
  *(undefined8 *)(param_1 + 0xa8) = 10000;
  *(undefined1 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined2 *)(param_1 + 0xb8) = 0;
  *(undefined1 *)(param_1 + 0xba) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 2;
  *(undefined4 *)(param_1 + 0x70) = 0x100000;
  *(undefined4 *)(param_1 + 0x74) = 0x4000;
  *(undefined4 *)(param_1 + 0x78) = 0x2000;
  *(undefined4 *)(param_1 + 0x90) = 250000;
  *(undefined4 *)(param_1 + 0x94) = 50000;
  *(undefined4 *)(param_1 + 0xa0) = 1;
  *(undefined4 *)(param_1 + 0xa4) = 2500000;
  return;
}



===== SdhostClockRateCodeToValue @ 1c000d6c4 =====

int SdhostClockRateCodeToValue(byte param_1)

{
  int iVar1;
  ulonglong uVar2;
  
  iVar1 = 10;
  if ((param_1 & 7) != 0) {
    uVar2 = (ulonglong)(param_1 & 7);
    do {
      iVar1 = iVar1 * 10;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return (uint)(byte)(&DAT_1c0011158)[param_1 >> 3 & 0xf] * iVar1;
}



===== SdhostConvertSdcmdToCommand @ 1c000d700 =====

void SdhostConvertSdcmdToCommand(undefined1 *param_1,undefined1 *param_2)

{
  int iVar1;
  
  memset(param_2,0,0x58);
  *param_2 = *param_1;
  *(uint *)(param_2 + 8) = (*(int *)(param_1 + 4) == 1) + 1;
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 1) {
    *(undefined4 *)(param_2 + 0xc) = 1;
  }
  else if (iVar1 == 2) {
    *(undefined4 *)(param_2 + 0xc) = 2;
  }
  else if (iVar1 == 3) {
    *(undefined4 *)(param_2 + 0xc) = 3;
  }
  else if (iVar1 == 4) {
    *(undefined4 *)(param_2 + 0xc) = 4;
  }
  else if (iVar1 == 5) {
    *(undefined4 *)(param_2 + 0xc) = 5;
  }
  else if (iVar1 == 6) {
    *(undefined4 *)(param_2 + 0xc) = 6;
  }
  else if (iVar1 == 7) {
    *(undefined4 *)(param_2 + 0xc) = 7;
  }
  else if (iVar1 == 8) {
    *(undefined4 *)(param_2 + 0xc) = 8;
  }
  else if (iVar1 == 9) {
    *(undefined4 *)(param_2 + 0xc) = 9;
  }
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
LAB_1c000d7e3:
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  else {
    if (iVar1 == 1) {
      *(undefined4 *)(param_2 + 0x10) = 1;
      goto LAB_1c000d7d3;
    }
    if (iVar1 == 2) {
      *(undefined4 *)(param_2 + 0x10) = 2;
    }
    else if (iVar1 == 3) {
      *(undefined4 *)(param_2 + 0x10) = 3;
    }
    else {
      if (iVar1 != 4) goto LAB_1c000d7e3;
      *(undefined4 *)(param_2 + 0x10) = 4;
    }
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      *(undefined4 *)(param_2 + 0x14) = 1;
      return;
    }
    if (iVar1 == 2) {
      *(undefined4 *)(param_2 + 0x14) = 2;
      return;
    }
  }
LAB_1c000d7d3:
  *(undefined4 *)(param_2 + 0x14) = 0;
  return;
}



===== SdhostEnumerateAcpiChildren @ 1c000d808 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SdhostEnumerateAcpiChildren(undefined8 param_1,int *param_2,undefined4 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 auStack_a8 [32];
  int *local_88;
  undefined4 local_80;
  undefined1 local_78;
  undefined8 *local_70;
  ulonglong *local_68;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  local_30 = 0x48696541;
  local_28 = 0;
  local_48 = 0;
  local_2c = 1;
  local_58 = 0;
  uStack_50 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  KeInitializeEvent(&local_58,1,0);
  local_68 = local_40;
  local_70 = &local_58;
  local_78 = 0;
  local_88 = param_2;
  local_80 = param_3;
  lVar1 = IoBuildDeviceIoControlRequest(0x32c020,param_1,&local_30,0x10);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      local_88 = (int *)0x0;
      uVar2 = KeWaitForSingleObject(&local_58,0,0,0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar2 = local_40[0] & 0xffffffff;
    }
    if ((-1 < (int)uVar2) && (uVar2 = uVar2 & 0xffffffff, *param_2 != 0x47696541)) {
      uVar2 = 0xc014000f;
    }
  }
  return uVar2;
}



===== SdhostEvaluateAcpiMethod @ 1c000d928 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SdhostEvaluateAcpiMethod
                    (undefined8 param_1,ushort *param_2,undefined4 param_3,int *param_4)

{
  ushort uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 auStack_1d8 [32];
  int *local_1b8;
  undefined4 local_1b0;
  undefined1 local_1a8;
  undefined8 *local_1a0;
  ulonglong *local_198;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  ulonglong local_170 [3];
  undefined4 local_158;
  undefined4 local_154;
  undefined1 auStack_14f [263];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1d8;
  uVar1 = *param_2;
  local_178 = 0;
  local_188 = 0;
  uStack_180 = 0;
  if (uVar1 < 0xfb) {
    memset(&local_158,0,0x104);
    memcpy(&local_154,*(void **)(param_2 + 4),(ulonglong)uVar1);
    *(undefined1 *)((longlong)local_170 + (ulonglong)uVar1 + 0x1c) = 0x2e;
    *(undefined4 *)((longlong)local_170 + (ulonglong)(uVar1 + 1) + 0x1c) = param_3;
    *(undefined1 *)((longlong)local_170 + (ulonglong)(uVar1 + 5) + 0x1c) = 0;
    local_158 = 0x41696541;
    local_170[0] = 0;
    local_170[1] = 0;
    KeInitializeEvent(&local_188,1,0);
    local_198 = local_170;
    local_1a0 = &local_188;
    local_1a8 = 0;
    local_1b0 = 0x18;
    local_1b8 = param_4;
    lVar3 = IoBuildDeviceIoControlRequest(0x32c018,param_1,&local_158,0x104);
    if (lVar3 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      uVar2 = IofCallDriver(param_1,lVar3);
      if ((int)uVar2 == 0x103) {
        local_1b8 = (int *)0x0;
        uVar2 = KeWaitForSingleObject(&local_188,0,0,0);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        uVar2 = local_170[0] & 0xffffffff;
      }
      if (-1 < (int)uVar2) {
        uVar2 = uVar2 & 0xffffffff;
        if (*param_4 != 0x426f6541) {
          uVar2 = 0xc014000f;
        }
        if (param_4[2] == 0) {
          uVar2 = 0xc014000f;
        }
      }
    }
  }
  else {
    uVar2 = 0xc00000f0;
  }
  return uVar2;
}



===== SdhostForwardIrp @ 1c000dab8 =====

void SdhostForwardIrp(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  puVar2[-9] = *puVar2;
  puVar2[-8] = puVar2[1];
  puVar2[-7] = puVar2[2];
  puVar2[-6] = puVar2[3];
  *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
  *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
  *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
  *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
  puVar2[-3] = puVar2[6];
  *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(lVar3 + -0x10) = param_3;
  *(undefined8 *)(lVar3 + -8) = param_4;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  PoCallDriver();
  return;
}



===== SdhostForwardIrpSynchronous @ 1c000db20 =====

ulonglong SdhostForwardIrpSynchronous(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  undefined8 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  local_28 = 0;
  uStack_20 = 0;
  puVar2[-9] = *puVar2;
  puVar2[-8] = puVar2[1];
  puVar2[-7] = puVar2[2];
  puVar2[-6] = puVar2[3];
  *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
  *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
  *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
  *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
  puVar2[-3] = puVar2[6];
  *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  KeInitializeEvent(&local_28,0,0);
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar3 + -0x10) = SdhostIrpCompletion;
  *(undefined8 **)(lVar3 + -8) = &local_28;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  uVar4 = PoCallDriver(param_1,param_2);
  if ((int)uVar4 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar4 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  return uVar4;
}



===== SdhostGetInterface @ 1c000dbf8 =====

ulonglong SdhostGetInterface(undefined8 param_1,undefined8 param_2,undefined8 param_3,
                            longlong param_4)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  if ((*(longlong *)(param_4 + 0x130) == 0x11d0b510c8ebdfb0) &&
     (*(longlong *)(param_4 + 0x138) == -0x1cbdda365fff1a80)) {
    KeInitializeEvent(local_38 + 2,0,0);
    lVar2 = IoBuildSynchronousFsdRequest(0x1b,param_1,0,0,0,local_38 + 2,local_38);
    if (lVar2 == 0) {
      uVar3 = 0xc000009a;
    }
    else {
      lVar1 = *(longlong *)(lVar2 + 0xb8);
      *(undefined8 *)(lVar2 + 0x38) = 0;
      *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
      *(undefined **)(lVar1 + -0x40) = &GUID_BUS_INTERFACE_STANDARD;
      *(longlong *)(lVar1 + -0x30) = param_4 + 0x160;
      *(undefined1 *)(lVar1 + -0x47) = 8;
      *(undefined4 *)(lVar1 + -0x38) = 0x10040;
      uVar3 = IofCallDriver(*(undefined8 *)(param_4 + 0xb0),lVar2);
      if ((int)uVar3 == 0x103) {
        KeWaitForSingleObject(local_38 + 2,0,0,0,0);
        uVar3 = local_38[0] & 0xffffffff;
      }
    }
  }
  else {
    uVar3 = 0xc0000010;
  }
  return uVar3;
}



===== SdhostGetPciConfigSpace @ 1c000dd2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint SdhostGetPciConfigSpace(longlong param_1,undefined1 param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(code **)(param_1 + 0x198) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x198))
                      (*(undefined8 *)(param_1 + 0x168),0,param_3,param_2,param_4);
    uVar2 = -(uint)(iVar1 != param_4) & 0xc0000001;
  }
  return uVar2;
}



===== SdhostIrpCompletion @ 1c000dd80 =====

undefined8 SdhostIrpCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== SdhostSlotStateChanged @ 1c000ddac =====

void SdhostSlotStateChanged(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  bool bVar3;
  
  for (lVar2 = *(longlong *)(param_1 + 0x10); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0xa8)) {
    lVar2 = *(longlong *)(lVar2 + 0x40);
    puVar1 = (uint *)(lVar2 + 4);
    *puVar1 = *puVar1 | 1;
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (*(char *)(param_1 + 0x6a) != '\0') {
    memset((void *)(param_1 + 200),0,0x4e0);
  }
  lVar2 = *(longlong *)(param_1 + 8);
  LOCK();
  bVar3 = *(int *)(lVar2 + 0x1460) == 0;
  if (bVar3) {
    *(int *)(lVar2 + 0x1460) = 1;
  }
  UNLOCK();
  if ((bVar3) && (*(longlong *)(lVar2 + 0x1b0) != 0)) {
    PoFxActivateComponent(*(longlong *)(lVar2 + 0x1b0),0,0);
  }
  IoInvalidateDeviceRelations(*(undefined8 *)(lVar2 + 0xa8),0);
  return;
}



===== SdhostStringsToMultiString @ 1c000de48 =====

int SdhostStringsToMultiString(undefined8 *param_1,int param_2,ulonglong *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  int iVar5;
  int iVar6;
  undefined8 local_48;
  undefined2 *puStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  iVar5 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  puStack_40 = (undefined2 *)0x0;
  puVar1 = param_1;
  for (iVar6 = param_2; iVar6 != 0; iVar6 = iVar6 + -1) {
    RtlInitAnsiString(&local_38,*puVar1);
    iVar2 = RtlxAnsiStringToUnicodeSize(&local_38);
    iVar5 = iVar5 + iVar2;
    puVar1 = puVar1 + 1;
  }
  uVar4 = ExAllocatePool2(0x100,(ulonglong)(iVar5 + 2U) + 2,0x64496453);
  param_3[1] = uVar4;
  if (uVar4 == 0) {
    iVar6 = -0x3fffff66;
  }
  else {
    *(short *)param_3 = (short)(iVar5 + 2U);
    *(short *)((longlong)param_3 + 2) = (short)iVar5 + 4;
    local_48 = *param_3;
    puStack_40 = (undefined2 *)param_3[1];
    for (; param_2 != 0; param_2 = param_2 + -1) {
      RtlInitAnsiString(&local_38,*param_1);
      uVar3 = RtlxAnsiStringToUnicodeSize(&local_38);
      if (uVar3 <= local_48._2_2_) {
        iVar6 = RtlAnsiStringToUnicodeString(&local_48,&local_38,0);
        if (iVar6 < 0) {
          ExFreePoolWithTag(param_3[1],0x64496453);
          param_3[1] = 0;
          return iVar6;
        }
        puStack_40 = (undefined2 *)((longlong)puStack_40 + (local_48 & 0xffff) + 2);
        local_48 = (ulonglong)CONCAT42(local_48._4_4_,local_48._2_2_ + (-2 - (short)local_48)) <<
                   0x10;
      }
      param_1 = param_1 + 1;
    }
    *puStack_40 = 0;
    iVar6 = 0;
  }
  return iVar6;
}



===== SdhostWait @ 1c000dfcc =====

void SdhostWait(uint param_1)

{
  byte bVar1;
  longlong local_res10 [3];
  
  bVar1 = KeGetCurrentIrql();
  if ((bVar1 < 2) && (0x32 < param_1)) {
    local_res10[0] = (longlong)(int)(param_1 * -10);
    KeWaitForSingleObject(&SdhostWaitTimerEvent,0,0,0,local_res10);
  }
  else {
    KeStallExecutionProcessor(param_1);
  }
  return;
}



===== SdhostInitializeSystemWorkerThread @ 1c000e038 =====

int SdhostInitializeSystemWorkerThread(longlong param_1)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  iVar1 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uStack_20 = uStack_20 & 0xffffffff00000000;
  local_38 = 0;
  uStack_30 = 0;
  local_res8 = 0;
  if (*(longlong *)(param_1 + 0x20) == 0) {
    KeInitializeQueue(param_1 + 0x28,0);
    local_48 = CONCAT44(local_48._4_4_,0x30);
    uStack_40 = 0;
    uStack_30 = CONCAT44(uStack_30._4_4_,0x200);
    local_38 = 0;
    local_28 = 0;
    uStack_20 = 0;
    iVar1 = PsCreateSystemThread(&local_res8,0,&local_48,0,0,SdhostWorkerStart,param_1);
    if (-1 < iVar1) {
      local_res10 = 0;
      iVar1 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,&local_res10,0);
      *(undefined8 *)(param_1 + 0x20) = local_res10;
      ZwClose(local_res8);
    }
  }
  if (*(longlong *)(param_1 + 0x68) == 0) {
    KeInitializeQueue(param_1 + 0x70,0);
    local_48 = CONCAT44(local_48._4_4_,0x30);
    uStack_40 = 0;
    uStack_30 = CONCAT44(uStack_30._4_4_,0x200);
    local_38 = 0;
    local_28 = 0;
    uStack_20 = 0;
    iVar1 = PsCreateSystemThread(&local_res8,0,&local_48,0,0,SdhostPoFxWorkerStart,param_1);
    if (-1 < iVar1) {
      local_res10 = 0;
      iVar1 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,&local_res10,0);
      *(undefined8 *)(param_1 + 0x68) = local_res10;
      ZwClose(local_res8);
    }
  }
  return iVar1;
}



===== SdhostPoFxWorkerStart @ 1c000e1f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostPoFxWorkerStart(longlong param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  
  do {
    do {
      puVar3 = (undefined8 *)KeRemoveQueue(param_1 + 0x70,0,0);
    } while (puVar3 == (undefined8 *)0x80);
    uVar1 = puVar3[3];
    pcVar2 = (code *)puVar3[2];
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    IoInitializeWorkItem(uVar1,puVar3);
    (*pcVar2)(uVar1);
    ObfDereferenceObject(uVar1);
  } while( true );
}



===== SdhostQueueWorkItem @ 1c000e284 =====

void SdhostQueueWorkItem(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                        short *param_5,char param_6)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (param_6 == '\0') {
    cVar1 = IoTryQueueWorkItem(param_2,param_3,0,param_5);
    lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),DriverEntry);
    lVar4 = *(longlong *)(lVar3 + 0x20);
    lVar5 = lVar3 + 0x28;
    if (((param_5 != (short *)0x0) && (*param_5 == 6)) &&
       (*(longlong *)(*(longlong *)(param_5 + 0x5c) + 0x28) == param_1)) {
      lVar4 = *(longlong *)(lVar3 + 0x68);
      lVar5 = lVar3 + 0x70;
    }
    if (cVar1 != '\0') {
      return;
    }
    if ((lVar4 != 0) && (uVar2 = IoSizeofWorkItem(), 0x27 < uVar2)) {
      KeSetPriorityThread(lVar4,0xd);
      ObfReferenceObject(param_1);
      *(longlong *)(param_2 + 0x18) = param_1;
      *(undefined8 *)(param_2 + 0x10) = param_3;
      *(short **)(param_2 + 0x20) = param_5;
      *(longlong *)(param_2 + 8) = param_2;
      *(longlong *)param_2 = param_2;
      KeInsertQueue(lVar5,param_2);
      return;
    }
  }
  IoQueueWorkItemEx(param_2,param_3,0,param_5);
  return;
}



===== SdhostWorkerStart @ 1c000e3c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostWorkerStart(longlong param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  
  do {
    do {
      puVar3 = (undefined8 *)KeRemoveQueue(param_1 + 0x28,0,0);
    } while (puVar3 == (undefined8 *)0x80);
    uVar1 = puVar3[3];
    pcVar2 = (code *)puVar3[2];
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    IoInitializeWorkItem(uVar1,puVar3);
    (*pcVar2)(uVar1);
    ObfDereferenceObject(uVar1);
  } while( true );
}



===== _guard_check_icall @ 1c000e460 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c000e478 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000e49c =====

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



===== __cpu_features_init @ 1c000e510 =====

/* WARNING: Removing unreachable block (ram,0x0001c000e57a) */
/* WARNING: Removing unreachable block (ram,0x0001c000e529) */
/* WARNING: Removing unreachable block (ram,0x0001c000e51a) */

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



===== __security_check_cookie @ 1c000e5e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c000e620 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c000e650 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000e650. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c000e680 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c000e6e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c000e723;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c000e794;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c000e790:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c000e794;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c000e78c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c000e790;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c000e78c;
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
LAB_1c000e794:
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
LAB_1c000e723:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c000e800 =====

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



===== memset @ 1c000eb00 =====

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



===== __memset_repmovs @ 1c000ec40 =====

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



===== __memset_query @ 1c000ecc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c000ed40 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c000ee80 =====

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



===== __memset_spec_plain @ 1c000ef00 =====

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



===== DllInitialize @ 1c0016010 =====

undefined8 DllInitialize(void)

{
                    /* 0x16010  1  DllInitialize */
  return 0;
}



===== SdhostAddDevice @ 1c0016020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SdhostAddDevice(undefined8 param_1,longlong param_2)

{
  undefined4 *_Dst;
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined1 auStack_268 [32];
  int local_248;
  undefined1 local_240;
  longlong *local_238;
  longlong local_228 [4];
  ushort local_208;
  ushort local_206;
  byte local_200;
  undefined4 local_1dc;
  wchar_t local_108 [104];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_268;
  local_228[0] = 0;
  local_228[1] = 0;
  local_228[2] = 0;
  if (param_2 == 0) {
    uVar2 = 0x8000001a;
  }
  else {
    iVar6 = 0;
    while (local_248 = iVar6, uVar2 = RtlStringCbPrintfW(local_108,200,L"%s%d",L"\\Device\\Sdhost"),
          -1 < (int)uVar2) {
      local_238 = local_228;
      local_240 = 0;
      local_248 = 0;
      local_228[1] = 0;
      local_228[2] = 0;
      uVar2 = IoCreateDevice(param_1,0x14b8,local_228 + 1,4);
      if (-1 < (int)uVar2) {
        lVar3 = IoAttachDeviceToDeviceStack(local_228[0],param_2);
        if (lVar3 == 0) {
          return 0xc000009a;
        }
        lVar4 = IoGetDriverObjectExtension(param_1);
        _Dst = *(undefined4 **)(local_228[0] + 0x40);
        memset(_Dst,0,0x14b8);
        uVar7 = 1;
        *(longlong *)(_Dst + 0x2c) = lVar3;
        *_Dst = 1;
        *(longlong *)(_Dst + 0x2a) = param_2;
        _Dst[0x52] = iVar6;
        *(longlong *)(_Dst + 2) = local_228[0];
        *(undefined8 *)(_Dst + 4) = param_1;
        *(longlong *)(_Dst + 0x2e) = lVar4 + 0x10;
        local_248 = 0x20;
        IoInitializeRemoveLockEx(_Dst + 0x18,0x6c526453,1,100);
        lVar3 = param_2;
        uVar1 = SdhostQueryBusInformation(local_228[0],param_2);
        uVar2 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) goto LAB_1c00162f6;
        if ((*(longlong *)(_Dst + 0x4c) == 0x11d0b510c8ebdfb0) &&
           (*(longlong *)(_Dst + 0x4e) == -0x1cbdda365fff1a80)) {
          uVar5 = SdhostGetInterface(param_2,lVar3,uVar7,(longlong)_Dst);
          uVar2 = uVar5 & 0xffffffff;
          if ((int)uVar5 < 0) goto LAB_1c00162f6;
          memset(&local_208,0,0x100);
          lVar3 = *(longlong *)(local_228[0] + 0x40);
          uVar1 = SdhostGetPciConfigSpace(lVar3,0,&local_208,0x100);
          uVar2 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) goto LAB_1c00162f6;
          *(uint *)(lVar3 + 0x1a0) = (uint)local_208;
          *(uint *)(lVar3 + 0x1a4) = (uint)local_206;
          *(uint *)(lVar3 + 0x1a8) = (uint)local_200;
          *(undefined4 *)(lVar3 + 0x1ac) = local_1dc;
        }
        else {
          iVar6 = memcmp(_Dst + 0x4c,&GUID_BUS_TYPE_ACPI,0x10);
          uVar2 = (ulonglong)(-(uint)(iVar6 != 0) & 0xc00000bb);
        }
        *(longlong *)(_Dst + 0x28) = FdoList;
        FdoList = local_228[0];
        SdhostInitializeSystemWorkerThread(lVar4);
        memset(_Dst + 0x30,0,0x70);
        lVar3 = IoGetDriverObjectExtension(param_1,DriverEntry);
        _Dst[6] = 0;
        _Dst[7] = 0;
        *(longlong *)(_Dst + 0x30) = lVar3 + 200;
        *(uint *)(local_228[0] + 0x30) = *(uint *)(local_228[0] + 0x30) & 0xffffff7f;
        IoRegisterShutdownNotification(local_228[0]);
        if (-1 < (int)uVar2) {
          return uVar2;
        }
LAB_1c00162f6:
        _Dst[7] = _Dst[6];
        _Dst[6] = 6;
        if (*(longlong *)(_Dst + 0x2c) != 0) {
          IoDetachDevice();
        }
        IoDeleteDevice(local_228[0]);
        return uVar2;
      }
      iVar6 = iVar6 + 1;
      if ((int)uVar2 != -0x3fffffcb) {
        return uVar2;
      }
    }
  }
  return uVar2;
}



===== SdhostAllocateMiniportSlotExtensions @ 1c0016360 =====

undefined8 SdhostAllocateMiniportSlotExtensions(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  uint uVar5;
  byte bVar6;
  
  uVar5 = *(uint *)(*param_1 + 0x88) + 0x10;
  if ((uVar5 < *(uint *)(*param_1 + 0x88)) || (uVar5 < 0x10)) {
LAB_1c00163f6:
    uVar2 = 0xc000009a;
  }
  else {
    uVar4 = 0;
    if ((char)param_1[5] != '\0') {
      do {
        puVar1 = (undefined8 *)ExAllocatePool2(0x40,uVar5,0x65536453);
        param_1[uVar4 + 6] = (longlong)puVar1;
        if (puVar1 == (undefined8 *)0x0) {
          if ((char)uVar4 != '\0') {
            plVar3 = param_1 + 6;
            do {
              ExFreePoolWithTag(*plVar3,0x65536453);
              plVar3 = plVar3 + 1;
              uVar4 = uVar4 - 1;
            } while (uVar4 != 0);
          }
          goto LAB_1c00163f6;
        }
        bVar6 = (char)uVar4 + 1;
        uVar4 = (ulonglong)bVar6;
        *puVar1 = param_1;
      } while (bVar6 < *(byte *)(param_1 + 5));
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== SdhostCreateClose @ 1c0016420 =====

undefined8 SdhostCreateClose(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== SdhostDeleteDriver @ 1c001644c =====

void SdhostDeleteDriver(int *param_1)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (*param_1 != 0) {
    *param_1 = 0;
    RtlFreeUnicodeString(param_1 + 4);
    plVar2 = (longlong *)(param_1 + 0x2c);
    if (*plVar2 != 0) {
      lVar4 = *(longlong *)(param_1 + 0x30);
      local_28 = 0;
      uStack_20 = 0;
      local_18 = 0;
      KeAcquireInStackQueuedSpinLock(lVar4 + 0x18,&local_28);
      lVar5 = *plVar2;
      if ((*(longlong **)(lVar5 + 8) != plVar2) ||
         (plVar6 = *(longlong **)(param_1 + 0x2e), (longlong *)*plVar6 != plVar2)) {
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)(3);
        pcVar7 = (code *)swi(3);
        (*pcVar7)();
        return;
      }
      *plVar6 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar6;
      piVar1 = (int *)(lVar4 + 0x20);
      *piVar1 = *piVar1 + -1;
      KeReleaseInStackQueuedSpinLock(&local_28);
      *plVar2 = 0;
    }
    piVar1 = *(int **)(param_1 + 0x30);
    if (piVar1 != (int *)0x0) {
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        SdhostPortData = 0;
        ExFreePoolWithTag(piVar1,0x64506453);
      }
      param_1[0x30] = 0;
      param_1[0x31] = 0;
    }
  }
  return;
}



===== SdhostInitializeDriver @ 1c001653c =====

undefined8 SdhostInitializeDriver(longlong param_1,undefined2 *param_2,longlong param_3)

{
  short sVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(code **)(param_1 + 0x70) = SdhostCreateClose;
  *(code **)(param_1 + 0x80) = SdhostCreateClose;
  *(code **)(param_1 + 0x100) = SdhostCreateClose;
  *(code **)(param_1 + 0xe0) = SdhostDeviceControl;
  *(code **)(param_1 + 0x128) = SdhostSystemControl;
  *(code **)(param_1 + 0x120) = SdhostPower;
  *(code **)(param_1 + 0x148) = SdhostPnp;
  *(code **)(param_1 + 0xe8) = SdhostInternalDeviceControl;
  *(code **)(param_1 + 0x68) = SdhostUnload;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = SdhostAddDevice;
  lVar3 = IoGetDriverObjectExtension(param_1,DriverEntry);
  *(longlong *)(lVar3 + 8) = param_1;
  *(longlong *)(lVar3 + 0xc0) = param_3;
  *(undefined2 *)(lVar3 + 0x10) = *param_2;
  sVar1 = param_2[1];
  *(short *)(lVar3 + 0x12) = sVar1 + 2;
  uVar4 = ExAllocatePool2(0x40,sVar1 + 2,0x65476453);
  *(undefined8 *)(lVar3 + 0x18) = uVar4;
  RtlCopyUnicodeString(lVar3 + 0x10,param_2);
  uVar4 = SdhostLoadGlobalRegistryValues(param_2);
  if (-1 < (int)uVar4) {
    KeInitializeEvent(&SdhostWaitTimerEvent,0,0);
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    KeAcquireInStackQueuedSpinLock(param_3 + 0x18,&local_28);
    puVar8 = auStack_48;
    plVar6 = (longlong *)(param_3 + 8);
    lVar7 = *plVar6;
    plVar5 = (longlong *)(lVar3 + 0xb0);
    if (*(longlong **)(lVar7 + 8) != plVar6) {
      plVar6 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar5 = (longlong *)(*pcVar2)();
      puVar8 = auStack_40;
    }
    plVar5[1] = (longlong)plVar6;
    *plVar5 = lVar7;
    *(longlong **)(lVar7 + 8) = plVar5;
    *plVar6 = (longlong)plVar5;
    *(int *)(param_3 + 0x20) = *(int *)(param_3 + 0x20) + 1;
    *(undefined8 *)(puVar8 + -8) = 0x1c00166c6;
    KeReleaseInStackQueuedSpinLock(puVar8 + 0x20);
    uVar4 = 0;
  }
  return uVar4;
}



===== SdhostQueryBusInformation @ 1c00166ec =====

void SdhostQueryBusInformation(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  *(undefined8 *)(lVar1 + 0x130) = 0;
  *(undefined8 *)(lVar1 + 0x138) = 0;
  *(undefined8 *)(lVar1 + 0x140) = 0;
  iVar2 = IoGetDeviceProperty(param_2,0xc,0x10,(undefined8 *)(lVar1 + 0x130),local_res8);
  if (-1 < iVar2) {
    iVar2 = IoGetDeviceProperty(param_2,0xd,4,lVar1 + 0x140,local_res8);
    if (-1 < iVar2) {
      IoGetDeviceProperty(param_2,0xe,4,lVar1 + 0x144,local_res8);
    }
  }
  return;
}



===== SdhostSystemControl @ 1c00167b0 =====

undefined8 SdhostSystemControl(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 2) {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    uVar2 = 0xc00000bb;
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar2 = IofCallDriver(*(undefined8 *)(piVar1 + 0x2c));
  }
  return uVar2;
}



===== SdhostUnload @ 1c0016810 =====

void SdhostUnload(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  uint uVar6;
  longlong *plVar7;
  longlong lVar8;
  
  lVar4 = FdoList;
  while (lVar4 != 0) {
    lVar1 = *(longlong *)(lVar4 + 0x40);
    *(undefined4 *)(lVar1 + 0x1c) = *(undefined4 *)(lVar1 + 0x18);
    *(undefined4 *)(lVar1 + 0x18) = 6;
    if (*(longlong *)(lVar1 + 0x13b8) != 0) {
      IoDisconnectInterrupt();
    }
    if (*(longlong *)(lVar1 + 0x13c0) != 0) {
      IoDisconnectInterrupt();
    }
    if (*(longlong *)(lVar1 + 0x1400) != 0) {
      IoDisconnectInterrupt();
    }
    uVar6 = 0;
    plVar7 = (longlong *)(lVar1 + 0x1468);
    lVar8 = *plVar7;
    if (*(char *)(lVar1 + 0x1464) != '\0') {
      do {
        lVar2 = *(longlong *)(lVar8 + 0x10);
        while (lVar2 != 0) {
          lVar3 = *(longlong *)(lVar2 + 0x40);
          lVar2 = *(longlong *)(lVar3 + 0xa8);
          *(undefined4 *)(lVar3 + 0x1c) = *(undefined4 *)(lVar3 + 0x18);
          *(undefined4 *)(lVar3 + 0x18) = 6;
          IoDeleteDevice();
        }
        ExFreePoolWithTag(lVar8,0x6c536453);
        *plVar7 = 0;
        uVar6 = uVar6 + 1;
        plVar7 = (longlong *)(lVar1 + ((ulonglong)uVar6 + 0x28d) * 8);
        lVar8 = *plVar7;
      } while (uVar6 < *(byte *)(lVar1 + 0x1464));
    }
    IoDetachDevice(*(undefined8 *)(lVar1 + 0xb0));
    lVar1 = *(longlong *)(lVar1 + 0xa0);
    IoDeleteDevice(lVar4);
    lVar4 = lVar1;
  }
  piVar5 = (int *)IoGetDriverObjectExtension(param_1,DriverEntry);
  SdhostDeleteDriver(piVar5);
  return;
}



===== SdPortInitialize @ 1c00169a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SdPortInitialize(longlong param_1,undefined2 *param_2,undefined8 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  int *piVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int *local_res8;
  
                    /* 0x169a0  4  SdPortInitialize */
  if (((param_1 == 0) || (param_2 == (undefined2 *)0x0)) || (param_3 == (undefined8 *)0x0)) {
    return 0xc000000d;
  }
  local_res8 = (int *)IoGetDriverObjectExtension();
  if (local_res8 == (int *)0x0) {
    uVar6 = IoAllocateDriverObjectExtension(param_1,DriverEntry,0x158,&local_res8);
    uVar9 = (ulonglong)uVar6;
    if ((int)uVar6 < 0) goto LAB_1c0016b8b;
    if (SdhostPortData == (int *)0x0) {
      piVar7 = (int *)ExAllocatePool2(0x40,0x28,0x64506453);
      if (piVar7 != (int *)0x0) {
        piVar1 = piVar7 + 2;
        *(int **)(piVar7 + 4) = piVar1;
        *(int **)piVar1 = piVar1;
        KeInitializeSpinLock(piVar7 + 6);
        piVar7[8] = 0;
        *piVar7 = 1;
        SdhostPortData = piVar7;
        goto LAB_1c0016a81;
      }
    }
    else {
      LOCK();
      *SdhostPortData = *SdhostPortData + 1;
      UNLOCK();
LAB_1c0016a81:
      piVar1 = local_res8;
      piVar7 = SdhostPortData;
      if (SdhostPortData != (int *)0x0) {
        memset(local_res8 + 1,0,0x154);
        *piVar1 = 3;
        uVar8 = SdhostInitializeDriver(param_1,param_2,(longlong)piVar7);
        uVar9 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) goto LAB_1c0016b8b;
        goto LAB_1c0016ad7;
      }
    }
    uVar9 = 0xc000009a;
  }
  else {
    uVar9 = 0xc00000bb;
LAB_1c0016ad7:
    piVar7 = local_res8;
    memset(local_res8 + 0x32,0,0x90);
    uVar5 = param_3[1];
    *(undefined8 *)(piVar7 + 0x32) = *param_3;
    *(undefined8 *)(piVar7 + 0x34) = uVar5;
    uVar5 = param_3[3];
    *(undefined8 *)(piVar7 + 0x36) = param_3[2];
    *(undefined8 *)(piVar7 + 0x38) = uVar5;
    uVar5 = param_3[5];
    *(undefined8 *)(piVar7 + 0x3a) = param_3[4];
    *(undefined8 *)(piVar7 + 0x3c) = uVar5;
    uVar5 = param_3[7];
    *(undefined8 *)(piVar7 + 0x3e) = param_3[6];
    *(undefined8 *)(piVar7 + 0x40) = uVar5;
    uVar5 = param_3[9];
    *(undefined8 *)(piVar7 + 0x42) = param_3[8];
    *(undefined8 *)(piVar7 + 0x44) = uVar5;
    uVar5 = param_3[0xb];
    *(undefined8 *)(piVar7 + 0x46) = param_3[10];
    *(undefined8 *)(piVar7 + 0x48) = uVar5;
    uVar5 = param_3[0xd];
    *(undefined8 *)(piVar7 + 0x4a) = param_3[0xc];
    *(undefined8 *)(piVar7 + 0x4c) = uVar5;
    iVar2 = *(int *)((longlong)param_3 + 0x74);
    iVar3 = *(int *)(param_3 + 0xf);
    iVar4 = *(int *)((longlong)param_3 + 0x7c);
    piVar7[0x4e] = *(int *)(param_3 + 0xe);
    piVar7[0x4f] = iVar2;
    piVar7[0x50] = iVar3;
    piVar7[0x51] = iVar4;
    iVar2 = *(int *)((longlong)param_3 + 0x84);
    iVar3 = *(int *)(param_3 + 0x11);
    iVar4 = *(int *)((longlong)param_3 + 0x8c);
    piVar7[0x52] = *(int *)(param_3 + 0x10);
    piVar7[0x53] = iVar2;
    piVar7[0x54] = iVar3;
    piVar7[0x55] = iVar4;
    _DAT_1c0012348 = 0;
    _DAT_1c0012350 = 0;
    _TableListMutex = 1;
    KeInitializeEvent(&DAT_1c0012358,1,0);
    DAT_1c0012328 = &PrivateExtensionTableList;
    PrivateExtensionTableList = &PrivateExtensionTableList;
    if (-1 < (int)uVar9) {
      return uVar9;
    }
  }
LAB_1c0016b8b:
  if (local_res8 != (int *)0x0) {
    SdhostDeleteDriver(local_res8);
  }
  return uVar9;
}



===== SdhostDeviceControl @ 1c0016bc0 =====

void SdhostDeviceControl(longlong param_1,longlong param_2)

{
  if (**(int **)(param_1 + 0x40) == 1) {
    SdhostFdoDeviceControl(param_1,param_2);
  }
  else {
    SdhostPdoDeviceControl(param_1,param_2);
  }
  return;
}



===== SdhostFdoPnp @ 1c0016be8 =====

ulonglong SdhostFdoPnp(longlong param_1,longlong param_2)

{
  uint *puVar1;
  byte bVar2;
  char cVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 *puVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  bool bVar12;
  
  uVar9 = IoAcquireRemoveLockEx(param_1 + 0x60,param_2,"",1,0x20);
  if ((int)uVar9 < 0) {
    *(uint *)(param_2 + 0x30) = uVar9;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
    return (ulonglong)uVar9;
  }
  puVar4 = *(undefined8 **)(param_2 + 0xb8);
  bVar2 = *(byte *)((longlong)puVar4 + 1);
  if (bVar2 < 6) {
    if (bVar2 != 5) {
      if (bVar2 == 0) {
        *(byte *)((longlong)puVar4 + 3) = *(byte *)((longlong)puVar4 + 3) | 1;
        puVar4 = *(undefined8 **)(param_2 + 0xb8);
        puVar4[-9] = *puVar4;
        puVar4[-8] = puVar4[1];
        puVar4[-7] = puVar4[2];
        puVar4[-6] = puVar4[3];
        *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
        *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
        *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
        puVar4[-3] = puVar4[6];
        *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
        lVar5 = *(longlong *)(param_2 + 0xb8);
        *(undefined8 *)(lVar5 + -8) = 0;
        *(code **)(lVar5 + -0x10) = SdhostFdoStartDeviceComplete;
        *(undefined1 *)(lVar5 + -0x45) = 0xe0;
        IofCallDriver(*(undefined8 *)(param_1 + 0xb0),param_2);
        return 0x103;
      }
      if (bVar2 != 1) {
        if (bVar2 == 2) {
          uVar10 = SdhostFdoRemoveDevice(param_1);
        }
        else {
          if (bVar2 == 3) {
            bVar12 = *(int *)(param_1 + 0x18) == 4;
            goto LAB_1c0016e9c;
          }
          if (bVar2 != 4) goto LAB_1c0016ea4;
          uVar10 = SdhostFdoStopDevice(param_1);
        }
LAB_1c0016e62:
        uVar11 = uVar10 & 0xffffffff;
        iVar7 = (int)uVar10;
        if (((iVar7 + 0x80000000U & 0x80000000) == 0) && (iVar7 != -0x3fffff45)) goto LAB_1c0016e78;
        if (iVar7 == 0x103) {
          return uVar11;
        }
      }
    }
  }
  else {
    if (bVar2 != 6) {
      if (bVar2 == 7) {
        uVar10 = SdhostFdoQueryDeviceRelations(param_1,param_2);
        goto LAB_1c0016e62;
      }
      if (bVar2 == 9) {
        puVar6 = (undefined8 *)puVar4[1];
        puVar4[-9] = *puVar4;
        puVar4[-8] = puVar4[1];
        puVar4[-7] = puVar4[2];
        puVar4[-6] = puVar4[3];
        *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
        *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
        *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
        puVar4[-3] = puVar4[6];
        *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
        uVar9 = IoSynchronousCallDriver(*(undefined8 *)(param_1 + 0xb0));
        uVar11 = (ulonglong)uVar9;
        if ((int)uVar9 < 0) {
          memset((undefined8 *)(param_1 + 0x20),0,0x40);
        }
        else {
          uVar8 = puVar6[1];
          *(undefined8 *)(param_1 + 0x20) = *puVar6;
          *(undefined8 *)(param_1 + 0x28) = uVar8;
          uVar8 = puVar6[3];
          *(undefined8 *)(param_1 + 0x30) = puVar6[2];
          *(undefined8 *)(param_1 + 0x38) = uVar8;
          uVar8 = puVar6[5];
          *(undefined8 *)(param_1 + 0x40) = puVar6[4];
          *(undefined8 *)(param_1 + 0x48) = uVar8;
          uVar8 = puVar6[7];
          *(undefined8 *)(param_1 + 0x50) = puVar6[6];
          *(undefined8 *)(param_1 + 0x58) = uVar8;
        }
      }
      else {
        if (bVar2 != 0x16) {
          if (bVar2 == 0x17) {
            SdhostFdoFreeDeviceResources(*(longlong *)(param_1 + 8));
          }
          goto LAB_1c0016ea4;
        }
        puVar4[-9] = *puVar4;
        puVar4[-8] = puVar4[1];
        puVar4[-7] = puVar4[2];
        puVar4[-6] = puVar4[3];
        *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
        *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
        *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
        puVar4[-3] = puVar4[6];
        *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
        uVar9 = IoSynchronousCallDriver(*(undefined8 *)(param_1 + 0xb0),param_2);
        uVar11 = (ulonglong)uVar9;
        if (((-1 < (int)uVar9) &&
            (cVar3 = *(char *)(*(longlong *)(param_2 + 0xb8) + 8),
            *(uint *)(*(longlong *)(param_1 + 8) + 0x30) =
                 *(uint *)(*(longlong *)(param_1 + 8) + 0x30) & 0xffffdfff, cVar3 == '\0')) &&
           ((*(uint *)(*(longlong *)(param_1 + 0xb0) + 0x30) & 0x2000) != 0)) {
          puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0x30);
          *puVar1 = *puVar1 | 0x2000;
        }
      }
LAB_1c0016e78:
      *(int *)(param_2 + 0x30) = (int)uVar11;
      IofCompleteRequest(param_2,0);
      goto LAB_1c0016ec7;
    }
    bVar12 = *(int *)(param_1 + 0x18) == 2;
LAB_1c0016e9c:
    if (bVar12) {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
    }
  }
LAB_1c0016ea4:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar9 = IofCallDriver(*(undefined8 *)(param_1 + 0xb0),param_2);
  uVar11 = (ulonglong)uVar9;
LAB_1c0016ec7:
  IoReleaseRemoveLockEx(param_1 + 0x60,param_2,0x20);
  return uVar11;
}



===== SdhostFdoQueryDeviceRelations @ 1c0016f04 =====

undefined8 SdhostFdoQueryDeviceRelations(longlong param_1,longlong param_2)

{
  uint *_Src;
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  uint *_Dst;
  ulonglong uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  bool bVar11;
  
  puVar6 = *(uint **)(param_2 + 0x38);
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (iVar2 == 0) {
    LOCK();
    bVar11 = *(int *)(param_1 + 0x1460) == 1;
    if (bVar11) {
      *(int *)(param_1 + 0x1460) = 0;
    }
    UNLOCK();
    if ((bVar11) && (*(longlong *)(param_1 + 0x1b0) != 0)) {
      PoFxIdleComponent(*(longlong *)(param_1 + 0x1b0),0,0);
    }
    _Src = *(uint **)(param_2 + 0x38);
    uVar3 = SdhostEnumerateHost(*(longlong *)(param_1 + 8));
    if ((int)uVar3 < 0) goto LAB_1c00170fa;
    uVar10 = *(uint *)(param_1 + 0x14a8);
    if (uVar10 == 0) {
      if (_Src != (uint *)0x0) {
LAB_1c0017006:
        uVar5 = *_Src;
        if (uVar5 == 0) goto LAB_1c001701e;
        uVar7 = uVar5 * 8 + 8;
        iVar2 = uVar7 + uVar10 * 8;
        uVar10 = uVar5 + uVar10;
        goto LAB_1c001702b;
      }
      _Dst = (uint *)ExAllocatePool2(0x100,0x10,0x72446453);
      puVar6 = _Dst;
      if (_Dst != (uint *)0x0) goto LAB_1c0016f82;
    }
    else {
      if (_Src != (uint *)0x0) goto LAB_1c0017006;
LAB_1c001701e:
      uVar7 = 0;
      iVar2 = uVar10 * 8 + 8;
LAB_1c001702b:
      _Dst = (uint *)ExAllocatePool2(0x100,iVar2,0x72446453);
      if (_Dst != (uint *)0x0) {
        if (_Src == (uint *)0x0) {
          uVar5 = 0;
        }
        else {
          if (*_Src != 0) {
            memcpy(_Dst,_Src,(ulonglong)uVar7);
          }
          uVar5 = *_Src;
          ExFreePoolWithTag(_Src,0x72446453);
        }
        uVar8 = 0;
        if (*(char *)(param_1 + 0x1464) != '\0') {
          do {
            lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x1468 + uVar8 * 8) + 0x10);
            while (lVar9 != 0) {
              lVar1 = *(longlong *)(lVar9 + 0x40);
              if ((uVar5 < uVar10) && ((*(uint *)(lVar1 + 4) & 1) == 0)) {
                uVar4 = (ulonglong)uVar5;
                uVar5 = uVar5 + 1;
                *(longlong *)(_Dst + uVar4 * 2 + 2) = lVar9;
                ObReferenceObjectByPointer(lVar9,0,0,0);
              }
              lVar9 = *(longlong *)(lVar1 + 0xa8);
            }
            uVar7 = (int)uVar8 + 1;
            uVar8 = (ulonglong)uVar7;
          } while (uVar7 < *(byte *)(param_1 + 0x1464));
        }
        *_Dst = uVar5;
        goto LAB_1c00170f8;
      }
    }
    uVar3 = 0xc000009a;
  }
  else {
    if (iVar2 != 3) {
      uVar3 = 0xc00000bb;
      goto LAB_1c00170fa;
    }
    _Dst = puVar6;
    if (puVar6 == (uint *)0x0) {
      _Dst = (uint *)ExAllocatePool2(0x100,0x10,0x72446453);
      if (_Dst == (uint *)0x0) {
        return 0xc000009a;
      }
LAB_1c0016f82:
      *_Dst = 0;
      _Dst[2] = 0;
      _Dst[3] = 0;
    }
LAB_1c00170f8:
    uVar3 = 0;
    puVar6 = _Dst;
  }
LAB_1c00170fa:
  *(uint **)(param_2 + 0x38) = puVar6;
  return uVar3;
}



===== SdhostFdoRemoveDevice @ 1c0017124 =====

undefined8 SdhostFdoRemoveDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  SdhostFdoFreeDeviceResources(*(longlong *)(param_1 + 8));
  KeFlushQueuedDpcs();
  if (*(longlong *)(param_1 + 0x1b0) != 0) {
    PoFxUnregisterDevice();
    *(undefined8 *)(param_1 + 0x1b0) = 0;
  }
  uVar6 = 0;
  if (*(char *)(param_1 + 0x1464) != '\0') {
    do {
      lVar1 = *(longlong *)(param_1 + 0x1468 + uVar6 * 8);
      lVar4 = *(longlong *)(lVar1 + 0x10);
      while (lVar3 = lVar4, lVar3 != 0) {
        lVar2 = *(longlong *)(lVar3 + 0x40);
        if (*(longlong *)(lVar2 + 0x5f0) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar2 + 0x5f0),0x63496453);
          *(undefined8 *)(lVar2 + 0x5f0) = 0;
        }
        lVar4 = *(longlong *)(lVar2 + 0xa8);
        if (*(int *)(lVar2 + 0x18) != 6) {
          *(int *)(lVar2 + 0x1c) = *(int *)(lVar2 + 0x18);
          *(undefined4 *)(lVar2 + 0x18) = 6;
          IoDeleteDevice(lVar3);
        }
      }
      ExFreePoolWithTag(lVar1,0x6c536453);
      *(undefined8 *)(param_1 + 0x1468 + uVar6 * 8) = 0;
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *(byte *)(param_1 + 0x1464));
  }
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
  lVar1 = FdoList;
  *(undefined4 *)(param_1 + 0x18) = 6;
  if (lVar1 != 0) {
    lVar4 = 0;
    do {
      lVar3 = lVar1;
      if (lVar3 == *(longlong *)(param_1 + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(lVar3 + 0x40) + 0xa0);
        if (lVar4 == 0) {
          FdoList = lVar1;
        }
        else {
          *(longlong *)(*(longlong *)(lVar4 + 0x40) + 0xa0) = lVar1;
        }
        break;
      }
      lVar1 = *(longlong *)(*(longlong *)(lVar3 + 0x40) + 0xa0);
      lVar4 = lVar3;
    } while (lVar1 != 0);
  }
  IoDetachDevice(*(undefined8 *)(param_1 + 0xb0));
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  return 0;
}



===== SdhostFdoStartDeviceWorker @ 1c00172d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SdhostFdoStartDeviceWorker(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  uint *puVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  code *pcVar7;
  int *piVar8;
  undefined1 uVar9;
  uint uVar10;
  ulonglong *puVar11;
  undefined8 *puVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  byte bVar16;
  undefined4 uVar17;
  ulonglong uVar18;
  char *pcVar19;
  int *piVar20;
  undefined8 uVar21;
  undefined1 *puVar22;
  byte bVar23;
  char *pcVar24;
  ulonglong uVar25;
  int *piVar26;
  int iVar27;
  uint uVar28;
  ulonglong uVar29;
  char cVar30;
  undefined1 auStack_258 [8];
  undefined1 auStack_250 [76];
  undefined4 local_204;
  longlong local_200;
  ulonglong *local_1f8;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 uStack_1e8;
  undefined4 local_1d8 [2];
  undefined8 local_1d0;
  longlong *local_1c8;
  code *local_1c0;
  ulonglong local_1b8;
  longlong local_1b0;
  undefined1 local_1a8 [2];
  bool bStack_1a6;
  undefined4 local_1a4;
  byte local_1a0;
  uint local_19c;
  undefined8 local_198;
  undefined4 local_188;
  undefined4 uStack_184;
  int *local_180;
  short local_178 [4];
  undefined1 *local_170;
  longlong local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  short *local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  ulonglong uStack_120;
  wchar_t local_118 [24];
  undefined1 local_e8 [160];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_258;
  uStack_1e8 = 0;
  local_1f0 = 0;
  local_1ec = 0;
  local_128 = 0;
  uStack_120 = uStack_120 & 0xffffffff00000000;
  local_170 = local_e8;
  local_204 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_178[0] = 0;
  local_178[1] = 0x98;
  local_178[2] = 0;
  local_178[3] = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = (short *)0x0;
  uStack_130 = 0;
  local_200 = param_1;
  local_168 = param_2;
  local_160 = param_3;
  SdhostWait(0x100);
  puVar22 = auStack_258;
  uVar29 = *(ulonglong *)(param_2 + 0xb8);
  uVar5 = *(ulonglong *)(param_1 + 0x40);
  piVar26 = *(int **)(uVar29 + 8);
  local_180 = piVar26;
  if ((piVar26 != (int *)0x0) && (*piVar26 != 0)) {
    *(undefined8 *)(uVar5 + 0x318) = 0;
    *(undefined4 *)(uVar5 + 0x310) = 1;
    *(undefined4 *)(uVar5 + 800) = 0;
    KeInitializeEvent(uVar5 + 0x328,1,0);
    plVar2 = (longlong *)(uVar5 + 0xc0);
    if (*(longlong *)(uVar5 + 0x1468) == 0) {
      SdhostInitializeMiniportConfigInfo(uVar5);
      (**(code **)(*plVar2 + 8))(plVar2,uVar5 + 0xe8);
      SdhostAllocateMiniportSlotExtensions(plVar2);
      bVar23 = 0;
      *(char *)(uVar5 + 0x1464) = *(char *)(uVar5 + 0xe8);
      if (*(char *)(uVar5 + 0xe8) != '\0') {
        do {
          puVar11 = (ulonglong *)ExAllocatePool2(0x40,0x1e38,0x6c536453);
          puVar22 = auStack_258;
          if (puVar11 == (ulonglong *)0x0) goto LAB_1c0017737;
          *(ulonglong **)(uVar5 + 0x1468 + (ulonglong)bVar23 * 8) = puVar11;
          *(undefined4 *)puVar11 = 4;
          *(byte *)((longlong)puVar11 + 4) = bVar23;
          puVar11[1] = uVar5;
          puVar11[0x151] = *(longlong *)(uVar5 + 0xf0 + (ulonglong)bVar23 * 8) + 0x10;
          puVar12 = (undefined8 *)ExAllocatePool2(0x40,0x20,0x74586453);
          puVar22 = auStack_258;
          if (puVar12 == (undefined8 *)0x0) goto LAB_1c0017737;
          *puVar12 = puVar11;
          puVar12[1] = puVar11[0x151];
          ExAcquireFastMutex(&TableListMutex);
          puVar1 = puVar12 + 2;
          if ((undefined8 *)*DAT_1c0012328 != &PrivateExtensionTableList) goto LAB_1c0017741;
          puVar12[3] = DAT_1c0012328;
          *puVar1 = &PrivateExtensionTableList;
          *DAT_1c0012328 = puVar1;
          DAT_1c0012328 = puVar1;
          ExReleaseFastMutex(&TableListMutex);
          bVar23 = bVar23 + 1;
        } while (bVar23 < *(byte *)(uVar5 + 0x1464));
      }
    }
    local_1f8 = *(ulonglong **)(uVar29 + 0x10);
    uVar29 = 0;
    bVar23 = 0;
    lVar15 = *(longlong *)(uVar5 + 0x1468);
    puVar11 = local_1f8;
    puVar22 = auStack_258;
    if (*(char *)(uVar5 + 0x1464) != '\0') {
      do {
        puVar22 = auStack_258;
        uVar10 = SdhostMapSlotRegisterSpace(lVar15,(longlong)local_1f8);
        if ((int)uVar10 < 0) goto LAB_1c0017ffe;
        SdhostInitializeDbgLog(lVar15);
        KeInitializeSpinLock(lVar15 + 0x18);
        KeInitializeSpinLock(lVar15 + 0xb90);
        KeInitializeSpinLock(lVar15 + 0xc98);
        KeInitializeEvent(lVar15 + 0xc50,0,1);
        SdhostSetDefaultSettings(lVar15);
        *(undefined4 *)(lVar15 + 0x30) = 1;
        *(undefined8 *)(lVar15 + 0x38) = 0;
        *(undefined4 *)(lVar15 + 0x40) = 0;
        KeInitializeEvent(lVar15 + 0x48,1,0);
        (**(code **)(*(longlong *)(uVar5 + 0xc0) + 0x10))
                  (*(undefined8 *)(lVar15 + 0xa88),lVar15 + 0xb08);
        lVar13 = lVar15 + 0xb98;
        *(longlong *)(lVar15 + 0xba0) = lVar13;
        uVar29 = lVar15 + 0xbc8;
        *(longlong *)lVar13 = lVar13;
        lVar13 = lVar15 + 0xbd8;
        *(longlong *)(lVar15 + 0xbe0) = lVar13;
        *(longlong *)lVar13 = lVar13;
        *(ulonglong *)(lVar15 + 0xbd0) = uVar29;
        uVar10 = 0;
        *(ulonglong *)uVar29 = uVar29;
        if (*(char *)(lVar15 + 0xb09) != '\0') {
          do {
            lVar13 = ExAllocatePool2(0x40,0x178,0x724d6453);
            puVar22 = auStack_258;
            if (lVar13 == 0) goto LAB_1c0017737;
            lVar14 = IoAllocateWorkItem(*(undefined8 *)(uVar5 + 8));
            *(longlong *)(lVar13 + 0x160) = lVar14;
            puVar22 = auStack_258;
            if (lVar14 == 0) goto LAB_1c0017737;
            *(longlong *)(lVar13 + 0xb8) = lVar15;
            KeInitializeEvent(lVar13 + 0xc0,0,0);
            KeInitializeTimer(lVar13 + 0xd8);
            KeInitializeDpc(lVar13 + 0x118,SdhostRequestTimeoutDpc,lVar13);
            KeInitializeSpinLock(lVar13 + 0x158);
            puVar6 = *(ulonglong **)(lVar15 + 0xbd0);
            puVar11 = (ulonglong *)(lVar13 + 0x68);
            if (*puVar6 != uVar29) goto LAB_1c0017741;
            *puVar11 = uVar29;
            *(ulonglong **)(lVar13 + 0x70) = puVar6;
            *puVar6 = (ulonglong)puVar11;
            *(ulonglong **)(lVar15 + 0xbd0) = puVar11;
            uVar10 = uVar10 + 1;
          } while (uVar10 < *(byte *)(lVar15 + 0xb09));
        }
        KeInitializeEvent(lVar15 + 0xbb0,0,0);
        KeInitializeDpc(lVar15 + 0xbf0,SdhostRequestCompleteDpc,lVar15);
        bVar23 = bVar23 + 1;
        uVar29 = 0;
        lVar15 = *(longlong *)(uVar5 + 0x1468 + (ulonglong)bVar23 * 8);
        puVar11 = local_1f8;
        puVar22 = auStack_258;
      } while (bVar23 < *(byte *)(uVar5 + 0x1464));
    }
    goto LAB_1c0017748;
  }
  uVar10 = 0xc000000d;
LAB_1c0017ffe:
  *(undefined8 *)(puVar22 + -8) = 0x1c0018008;
  SdhostFdoFreeDeviceResources(*(longlong *)(puVar22 + 0x58));
LAB_1c0018008:
  lVar15 = local_168;
  *(uint *)(local_168 + 0x30) = uVar10;
  *(undefined8 *)(puVar22 + -8) = 0x1c001801b;
  IofCompleteRequest(local_168,0);
  *(undefined8 *)(puVar22 + -8) = 0x1c0018034;
  IoReleaseRemoveLockEx(uVar5 + 0x60,lVar15,0x20);
  *(undefined8 *)(puVar22 + -8) = 0x1c0018044;
  IoFreeWorkItem(local_160);
  *(undefined8 *)(puVar22 + -8) = 0x1c0018058;
  return;
LAB_1c0017741:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  puVar22 = auStack_250;
LAB_1c0017748:
  *(undefined8 *)(puVar22 + -8) = 0x1c0017750;
  SdhostQueryRemovability(uVar5);
  bVar23 = *(byte *)(uVar5 + 0x1464);
  lVar15 = *(longlong *)(uVar5 + 0x1468);
  uVar18 = uVar29 & 0xff;
  puVar22[0x50] = 1;
  if (bVar23 != 0) {
    do {
      if (*(char *)(lVar15 + 0x68) != (char)uVar29) {
        puVar22[0x50] = (char)uVar29;
        break;
      }
      bVar16 = (char)uVar18 + 1;
      uVar18 = (ulonglong)bVar16;
      lVar15 = *(longlong *)(uVar5 + 0x1468 + uVar18 * 8);
    } while (bVar16 < bVar23);
  }
  pcVar24 = (char *)((longlong)puVar11 + 0x14);
  uVar28 = (uint)uVar29;
  uVar25 = uVar29 & 0xffffffff;
  uVar18 = uVar29 & 0xff;
  uVar10 = uVar28;
  if (uVar28 < (uint)puVar11[2]) {
    pcVar19 = pcVar24;
    do {
      uVar10 = (uint)uVar25;
      if (1 < uVar10) break;
      if (*pcVar19 == '\x02') {
        uVar21 = *(undefined8 *)(pcVar19 + 8);
        if (uVar10 == 0) {
          *(undefined8 *)(uVar5 + 0x137c) = *(undefined8 *)pcVar19;
          *(undefined8 *)(uVar5 + 0x1384) = uVar21;
          *(undefined4 *)(uVar5 + 0x138c) = *(undefined4 *)(pcVar19 + 0x10);
        }
        else {
          *(undefined8 *)(uVar5 + 0x13ec) = *(undefined8 *)pcVar19;
          *(undefined8 *)(uVar5 + 0x13f4) = uVar21;
          *(undefined4 *)(uVar5 + 0x13fc) = *(undefined4 *)(pcVar19 + 0x10);
        }
        uVar25 = (ulonglong)(uVar10 + 1);
      }
      uVar10 = (uint)uVar25;
      bVar23 = (char)uVar18 + 1;
      uVar18 = (ulonglong)bVar23;
      pcVar19 = pcVar19 + 0x14;
    } while ((uint)bVar23 < (uint)puVar11[2]);
  }
  uVar18 = uVar29 & 0xffffffff;
  uVar25 = uVar29 & 0xff;
  piVar8 = piVar26;
  if (uVar28 < (uint)piVar26[4]) {
    do {
      piVar20 = piVar8 + 5;
      uVar28 = (uint)uVar18;
      if (1 < uVar28) break;
      if ((char)*piVar20 == '\x02') {
        uVar21 = *(undefined8 *)(piVar8 + 7);
        if (uVar28 == 0) {
          *(undefined8 *)(uVar5 + 0x1368) = *(undefined8 *)piVar20;
          *(undefined8 *)(uVar5 + 0x1370) = uVar21;
          *(int *)(uVar5 + 0x1378) = piVar8[9];
        }
        else {
          *(undefined8 *)(uVar5 + 0x13d8) = *(undefined8 *)piVar20;
          *(undefined8 *)(uVar5 + 0x13e0) = uVar21;
          *(int *)(uVar5 + 0x13e8) = piVar8[9];
        }
        uVar18 = (ulonglong)(uVar28 + 1);
      }
      uVar28 = (uint)uVar18;
      bVar23 = (char)uVar25 + 1;
      uVar25 = (ulonglong)bVar23;
      piVar8 = piVar20;
    } while ((uint)bVar23 < (uint)piVar26[4]);
  }
  if ((uVar10 == 2) && (uVar29 = uVar29 & 0xff, uVar28 == 2)) {
    uVar29 = 1;
  }
  bVar23 = 0;
  iVar27 = 0;
  if ((int)puVar11[2] != 0) {
    do {
      if (((*pcVar24 == -0x7c) && (pcVar24[4] == '\x01')) && (pcVar24[5] == '\x02')) {
        lVar15 = uVar5 + 0x1450;
        if (iVar27 != 0) {
          lVar15 = uVar5 + 0x1458;
        }
        local_188 = *(undefined4 *)(pcVar24 + 8);
        uStack_184 = *(undefined4 *)(pcVar24 + 0xc);
        *(undefined8 *)(puVar22 + 0x20) = *(undefined8 *)(pcVar24 + 8);
        *(undefined8 *)(puVar22 + -8) = 0x1c00178c1;
        uVar10 = RESOURCE_HUB_STRING_PRINTF(local_118,0x22,L"%0*I64x",0x10);
        if ((int)uVar10 < 0) goto LAB_1c0017ffe;
        *(undefined8 *)(puVar22 + -8) = 0x1c00178e8;
        uVar10 = RESOURCE_HUB_UNICODE_STRING_PRINTF
                           (local_178,L"%s%s",L"\\Device\\RESOURCE_HUB\\",local_118);
        if ((int)uVar10 < 0) goto LAB_1c0017ffe;
        uStack_140 = 0;
        local_138 = local_178;
        *(undefined4 *)(puVar22 + 0x28) = 0x60;
        local_148 = CONCAT44(local_148._4_4_,0x30);
        uStack_130 = CONCAT44(uStack_130._4_4_,0x240);
        *(undefined4 *)(puVar22 + 0x20) = 3;
        local_128 = 0;
        uStack_120 = 0;
        *(undefined8 *)(puVar22 + -8) = 0x1c001793d;
        uVar10 = ZwOpenFile(lVar15,0x80100000,&local_148,&local_158);
        if ((int)uVar10 < 0) goto LAB_1c0017ffe;
        iVar27 = iVar27 + 1;
        if (iVar27 == 2) break;
        puVar11 = *(ulonglong **)(puVar22 + 0x60);
      }
      bVar23 = bVar23 + 1;
      pcVar24 = pcVar24 + 0x14;
    } while ((uint)bVar23 < (uint)puVar11[2]);
    piVar26 = local_180;
  }
  *(undefined8 *)(puVar22 + -8) = 0x1c0017992;
  memset((void *)(uVar5 + 0x2c0),0,0x48);
  uVar21 = *(undefined8 *)(uVar5 + 8);
  *(undefined8 *)(puVar22 + -8) = 0x1c001799d;
  lVar15 = IoGetAttachedDeviceReference(uVar21);
  uVar9 = *(undefined1 *)(lVar15 + 0x4c);
  *(undefined8 *)(puVar22 + -8) = 0x1c00179b1;
  lVar13 = IoAllocateIrp(uVar9);
  if (lVar13 == 0) {
LAB_1c0017a83:
    *(undefined8 *)(puVar22 + -8) = 0x1c0017a8d;
    ObfDereferenceObject(lVar15);
  }
  else {
    lVar14 = *(longlong *)(lVar13 + 0xb8);
    *(undefined8 *)(lVar13 + 0x38) = 0;
    *(undefined4 *)(lVar13 + 0x30) = 0xc00000bb;
    *(undefined8 *)(lVar14 + -0x28) = 0;
    *(undefined2 *)(lVar14 + -0x48) = 0x81b;
    *(undefined **)(lVar14 + -0x40) = &GUID_D3COLD_SUPPORT_INTERFACE;
    *(undefined4 *)(lVar14 + -0x38) = 0x10048;
    *(void **)(lVar14 + -0x30) = (void *)(uVar5 + 0x2c0);
    *(undefined8 *)(puVar22 + -8) = 0x1c0017a09;
    iVar27 = IoSynchronousCallDriver(lVar15,lVar13);
    *(undefined8 *)(puVar22 + -8) = 0x1c0017a1a;
    IoFreeIrp(lVar13);
    if (iVar27 < 0) goto LAB_1c0017a83;
    pcVar7 = *(code **)(uVar5 + 0x2e8);
    puVar3 = (uint *)(uVar5 + 0x308);
    uVar21 = *(undefined8 *)(uVar5 + 0x2c8);
    *(undefined8 *)(puVar22 + -8) = 0x1c0017a45;
    iVar27 = (*pcVar7)(uVar21,1,puVar3);
    if (iVar27 < 0) {
      *puVar3 = 0;
      *(undefined4 *)(uVar5 + 0x30c) = 0;
    }
    else {
      local_118[8] = L'\x04';
      local_118[9] = L'\0';
      local_118[10] = L'\x04';
      local_118[0xb] = L'\0';
      local_118[0] = L'\x01';
      local_118[1] = L'\0';
      local_118[2] = L'\x01';
      local_118[3] = L'\0';
      local_118[4] = L'\x02';
      local_118[5] = L'\0';
      local_118[6] = L'\x03';
      local_118[7] = L'\0';
      if (*puVar3 < 6) {
        uVar17 = *(undefined4 *)(local_118 + (longlong)(int)*puVar3 * 2);
      }
      else {
        uVar17 = 0;
      }
      *(undefined4 *)(uVar5 + 0x30c) = uVar17;
    }
  }
  if (((char)uVar29 == '\0') || (*(longlong *)(uVar5 + 0x1450) == 0)) {
    cVar30 = puVar22[0x50];
    puVar4 = (undefined4 *)(uVar5 + 0x13d4);
    if (cVar30 == '\0') {
      if (*(int *)(uVar5 + 0x308) < 2) {
        if ((char)uVar29 == '\0') goto LAB_1c0017aeb;
        *puVar4 = 2;
      }
      else {
        *puVar4 = 1;
      }
    }
    else {
LAB_1c0017aeb:
      *puVar4 = 0;
    }
  }
  else {
    cVar30 = puVar22[0x50];
    *(undefined4 *)(uVar5 + 0x13d4) = 2;
  }
  lVar15 = *(longlong *)(puVar22 + 0x58);
  *(undefined4 *)(uVar5 + 0x80) = 1;
  *(undefined4 *)(uVar5 + 0x84) = 1;
  *(undefined8 *)(puVar22 + -8) = 0x1c0017b17;
  KeInitializeDpc(lVar15 + 200,SdhostInterruptDpc,lVar15);
  if (*(short *)(uVar5 + 0x136c) == 0) {
LAB_1c0017b25:
    uVar10 = 0xc0000001;
  }
  else {
    uVar28 = *(ushort *)(uVar5 + 0x136a) & 1;
    *(undefined1 *)(uVar5 + 0x13c9) = 0;
    *(undefined8 *)(puVar22 + -8) = 0x1c0017b52;
    KeInitializeSpinLock(uVar5 + 0x13a8);
    bVar23 = *(byte *)(uVar5 + 0x1380);
    *(byte *)(uVar5 + 0x13b0) = bVar23;
    *(undefined8 *)(puVar22 + -8) = 0x1c0017b74;
    memset(local_1d8,0,0x50);
    local_1d0 = *(undefined8 *)(uVar5 + 0xa8);
    local_1c8 = (longlong *)(uVar5 + 0x13b8);
    local_1c0 = SdhostInterrupt;
    local_1a4 = *(undefined4 *)(uVar5 + 0x1384);
    local_198 = *(undefined8 *)(uVar5 + 5000);
    local_1d8[0] = 1;
    _local_1a8 = CONCAT21(0x100,bVar23);
    *(undefined8 *)(puVar22 + -8) = 0x1c0017bd6;
    local_1b8 = uVar5;
    local_1b0 = uVar5 + 0x13a8;
    local_1a0 = bVar23;
    local_19c = uVar28;
    uVar10 = IoConnectInterruptEx(local_1d8);
    if (-1 < (int)uVar10) {
      *(undefined8 *)(puVar22 + -8) = 0x1c0017bf4;
      memset(local_1d8,0,0x50);
      local_1d0 = *(undefined8 *)(uVar5 + 0xa8);
      local_1b0 = 0;
      local_1c0 = SdhostPassiveInterrupt;
      local_1a4 = *(undefined4 *)(uVar5 + 0x1384);
      local_198 = *(undefined8 *)(uVar5 + 5000);
      local_1a0 = 0;
      local_1d8[0] = 1;
      _local_1a8 = 0x10000;
      *(undefined8 *)(puVar22 + -8) = 0x1c0017c54;
      local_1c8 = (longlong *)(uVar5 + 0x13c0);
      local_1b8 = uVar5;
      local_19c = uVar28;
      uVar10 = IoConnectInterruptEx(local_1d8);
      if (-1 < (int)uVar10) {
        *(bool *)(uVar5 + 0x13c8) = *(int *)(uVar5 + 0x13d4) == 1;
        *(undefined4 *)(puVar22 + 0x68) = 1;
        *(longlong *)(puVar22 + 0x70) = *(longlong *)(uVar5 + 0x13c0);
        if (*(char *)(uVar5 + 0x13c8) == '\0') {
          *(undefined8 *)(puVar22 + -8) = 0x1c0017c97;
          IoReportInterruptInactive(puVar22 + 0x68);
        }
        uVar21 = *(undefined8 *)(puVar22 + 0x58);
        *(undefined8 *)(puVar22 + -8) = 0x1c0017cb9;
        KeInitializeDpc(uVar5 + 0x1408,SdhostCardDetectDpc,uVar21);
        if (*(int *)(uVar5 + 0x13d4) == 2) {
          if (*(short *)(uVar5 + 0x13dc) == 0) goto LAB_1c0017b25;
          *(undefined8 *)(puVar22 + -8) = 0x1c0017ce5;
          memset(local_1d8,0,0x50);
          local_1a0 = *(byte *)(uVar5 + 0x13f0);
          plVar2 = (longlong *)(uVar5 + 0x1400);
          local_1d0 = *(undefined8 *)(uVar5 + 0xa8);
          local_1c0 = SdhostGpioInterrupt;
          local_1a4 = *(undefined4 *)(uVar5 + 0x13f4);
          local_19c = *(ushort *)(uVar5 + 0x13da) & 1;
          local_198 = *(undefined8 *)(uVar5 + 0x13f8);
          local_1d8[0] = 1;
          local_1b0 = 0;
          _local_1a8 = CONCAT12(*(char *)(uVar5 + 0x13d9) == '\x03',CONCAT11(0,local_1a0));
          *(undefined8 *)(puVar22 + -8) = 0x1c0017d5f;
          local_1c8 = plVar2;
          local_1b8 = uVar5;
          uVar10 = IoConnectInterruptEx(local_1d8);
          if ((int)uVar10 < 0) goto LAB_1c0017ffe;
          if ((*(longlong *)(uVar5 + 0x1450) == 0) && (*plVar2 != 0)) {
            *(undefined4 *)(puVar22 + 0x68) = 1;
            *(longlong *)(puVar22 + 0x70) = *plVar2;
            *(undefined8 *)(puVar22 + -8) = 0x1c0017d95;
            IoReportInterruptInactive(puVar22 + 0x68);
          }
          uVar21 = *(undefined8 *)(puVar22 + 0x58);
        }
        *(uint *)(uVar5 + 4) = *(uint *)(uVar5 + 4) & 0xfffbffff;
        if ((*(longlong *)(uVar5 + 0x1b0) == 0) && (DisableRuntimePower == 0)) {
          *(undefined8 *)(puVar22 + -8) = 0x1c0017dc9;
          SdhostPoFxEnableRuntimePowerManagement(uVar5,cVar30);
        }
        *(undefined8 *)(puVar22 + -8) = 0x1c0017dd3;
        lVar15 = IoAllocateWorkItem(uVar21);
        *(longlong *)(uVar5 + 0x88) = lVar15;
        if (lVar15 == 0) {
LAB_1c0017737:
          uVar10 = 0xc000009a;
        }
        else {
          bVar16 = 0;
          bVar23 = 0;
          if (*(char *)(uVar5 + 0x1464) != '\0') {
            do {
              iVar27 = piVar26[2];
              lVar15 = *(longlong *)(uVar5 + 0x1468 + (ulonglong)bVar16 * 8);
              *(undefined8 *)(puVar22 + -8) = 0x1c0017e0d;
              uVar10 = SdhostInitializeTransferMethod(lVar15,iVar27);
              if ((int)uVar10 < 0) goto LAB_1c0017ffe;
              bVar23 = *(byte *)(uVar5 + 0x1464);
              bVar16 = bVar16 + 1;
            } while (bVar16 < bVar23);
          }
          lVar15 = *(longlong *)(uVar5 + 0x1468);
          bVar16 = 0;
          if (bVar23 != 0) {
            do {
              if (*(longlong *)(uVar5 + 0x1450) == 0) {
                uVar21 = *(undefined8 *)(lVar15 + 0xa88);
                pcVar7 = *(code **)(*(longlong *)(uVar5 + 0xc0) + 0x68);
                *(undefined8 *)(puVar22 + -8) = 0x1c0017ec1;
                cVar30 = (*pcVar7)(uVar21);
              }
              else {
                *(undefined4 *)(puVar22 + 0x48) = 4;
                *(undefined1 **)(puVar22 + 0x40) = puVar22 + 0x54;
                *(undefined4 *)(puVar22 + 0x38) = 0;
                *(undefined8 *)(puVar22 + 0x30) = 0;
                *(undefined4 *)(puVar22 + 0x54) = 0;
                uVar21 = *(undefined8 *)(uVar5 + 0x1450);
                *(undefined4 *)(puVar22 + 0x28) = 0x480000;
                *(undefined8 **)(puVar22 + 0x20) = &local_158;
                *(undefined8 *)(puVar22 + -8) = 0x1c0017e95;
                uVar10 = ZwDeviceIoControlFile(uVar21,0,0,0);
                if ((int)uVar10 < 0) goto LAB_1c0017ffe;
                cVar30 = puVar22[0x54] == '\0';
              }
              *(char *)(lVar15 + 0xb3a) = cVar30;
              if (cVar30 != '\0') {
                if (*(longlong *)(uVar5 + 0x1458) == 0) {
                  uVar21 = *(undefined8 *)(lVar15 + 0xa88);
                  pcVar7 = *(code **)(*(longlong *)(uVar5 + 0xc0) + 0x70);
                  *(undefined8 *)(puVar22 + -8) = 0x1c0017f44;
                  uVar9 = (*pcVar7)(uVar21);
                }
                else {
                  *(undefined4 *)(puVar22 + 0x48) = 4;
                  *(undefined1 **)(puVar22 + 0x40) = puVar22 + 0x54;
                  *(undefined4 *)(puVar22 + 0x38) = 0;
                  *(undefined8 *)(puVar22 + 0x30) = 0;
                  *(undefined4 *)(puVar22 + 0x54) = 0;
                  uVar21 = *(undefined8 *)(uVar5 + 0x1458);
                  *(undefined4 *)(puVar22 + 0x28) = 0x480000;
                  *(undefined8 **)(puVar22 + 0x20) = &local_158;
                  *(undefined8 *)(puVar22 + -8) = 0x1c0017f1c;
                  uVar10 = ZwDeviceIoControlFile(uVar21);
                  if ((int)uVar10 < 0) goto LAB_1c0017ffe;
                  uVar9 = puVar22[0x54];
                }
                *(undefined1 *)(lVar15 + 0xb3b) = uVar9;
              }
              if ((*(char *)(lVar15 + 0x68) != '\0') ||
                 (uVar9 = 1, (*(uint *)(lVar15 + 0xb24) & 0x40000000) == 0)) {
                uVar9 = 0;
              }
              *(undefined1 *)(lVar15 + 0xb3e) = uVar9;
              if (*(char *)(lVar15 + 0x68) == '\0') {
                *(undefined1 *)(lVar15 + 0xb3a) = 1;
              }
              if (*(char *)(lVar15 + 0xb3a) != '\0') {
                *(undefined8 *)(puVar22 + -8) = 0x1c0017f85;
                SdhostInitializeSlot(lVar15);
              }
              bVar16 = bVar16 + 1;
              lVar15 = *(longlong *)(uVar5 + 0x1468 + (ulonglong)bVar16 * 8);
            } while (bVar16 < *(byte *)(uVar5 + 0x1464));
          }
          uVar21 = *(undefined8 *)(uVar5 + 0xa8);
          *(undefined8 *)(puVar22 + -8) = 0x1c0017fc3;
          uVar10 = IoRegisterDeviceInterface(uVar21,&GUID_SD_HOST_CONTROLLER,0,uVar5 + 0x150);
          if (-1 < (int)uVar10) {
            *(undefined8 *)(puVar22 + -8) = 0x1c0017fdb;
            uVar10 = IoSetDeviceInterfaceState(uVar5 + 0x150,1);
            if (-1 < (int)uVar10) {
              *(undefined4 *)(uVar5 + 0x1c) = *(undefined4 *)(uVar5 + 0x18);
              *(undefined4 *)(uVar5 + 0x18) = 1;
              *(undefined1 *)(uVar5 + 0x1448) = 1;
              goto LAB_1c0018008;
            }
          }
        }
      }
    }
  }
  goto LAB_1c0017ffe;
}



===== SdhostPdoDeviceUsageNotification @ 1c001807c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdhostPdoDeviceUsageNotification(longlong param_1,longlong param_2)

{
  uint *puVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  longlong lVar15;
  
  puVar3 = *(undefined8 **)(param_2 + 0xb8);
  bVar8 = false;
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x598) + 8);
  iVar2 = *(int *)(puVar3 + 2);
  uVar13 = (ulonglong)(iVar2 - 1U);
  if (iVar2 - 1U == 0) {
LAB_1c00180ed:
    if (*(char *)(puVar3 + 1) != '\0') {
      if (*(int *)(param_1 + 0x18) != 1) {
        return -0x3fffff5d;
      }
      if ((*(char *)(*(longlong *)(param_1 + 0x598) + 0x68) != '\0') && (iVar2 != 3)) {
        return -0x3ffffff0;
      }
    }
    bVar8 = true;
  }
  else {
    uVar13 = (ulonglong)(iVar2 - 2U);
    if (iVar2 - 2U == 0) {
LAB_1c00180d7:
      if (*(char *)(*(longlong *)(lVar4 + 0xc0) + 0x8c) == '\0') {
        return -0x3fffff45;
      }
      goto LAB_1c00180ed;
    }
    uVar12 = iVar2 - 3;
    uVar13 = (ulonglong)uVar12;
    if (uVar12 == 0) goto LAB_1c00180d7;
    if (uVar12 != 1) {
      return -0x3ffffff3;
    }
  }
  lVar11 = *(longlong *)(*(longlong *)(lVar4 + 8) + 0x18);
  lVar15 = *(longlong *)(lVar4 + 8);
  while (lVar10 = lVar11, lVar10 != 0) {
    lVar15 = lVar10;
    lVar11 = *(longlong *)(lVar10 + 0x18);
  }
  lVar11 = IoAllocateIrp(CONCAT71((int7)(uVar13 >> 8),*(undefined1 *)(lVar15 + 0x4c)));
  if (lVar11 == 0) {
    return -0x3fffff66;
  }
  *(undefined8 *)(lVar11 + 0x98) = *(undefined8 *)(param_2 + 0x98);
  lVar10 = *(longlong *)(lVar11 + 0xb8);
  *(undefined4 *)(lVar11 + 0x30) = 0xc00000bb;
  uVar14 = puVar3[1];
  *(undefined8 *)(lVar10 + -0x48) = *puVar3;
  *(undefined8 *)(lVar10 + -0x40) = uVar14;
  uVar14 = puVar3[3];
  *(undefined8 *)(lVar10 + -0x38) = puVar3[2];
  *(undefined8 *)(lVar10 + -0x30) = uVar14;
  uVar14 = puVar3[5];
  *(undefined8 *)(lVar10 + -0x28) = puVar3[4];
  *(undefined8 *)(lVar10 + -0x20) = uVar14;
  uVar5 = *(undefined4 *)((longlong)puVar3 + 0x34);
  uVar6 = *(undefined4 *)(puVar3 + 7);
  uVar7 = *(undefined4 *)((longlong)puVar3 + 0x3c);
  *(undefined4 *)(lVar10 + -0x18) = *(undefined4 *)(puVar3 + 6);
  *(undefined4 *)(lVar10 + -0x14) = uVar5;
  *(undefined4 *)(lVar10 + -0x10) = uVar6;
  *(undefined4 *)(lVar10 + -0xc) = uVar7;
  *(undefined8 *)(lVar10 + -8) = puVar3[8];
  iVar9 = IoSynchronousCallDriver(lVar15);
  IoFreeIrp(lVar11);
  if (iVar9 < 0) {
    if (iVar9 != -0x3fffff45) {
      return iVar9;
    }
    if (iVar2 != 4) {
      return -0x3fffff45;
    }
    iVar9 = 0;
  }
  if (!bVar8) {
    return iVar9;
  }
  ExAcquireFastMutex(param_1 + 0x5a0);
  iVar2 = *(int *)(puVar3 + 2);
  if (iVar2 == 1) {
    if (*(char *)(puVar3 + 1) == '\0') {
      LOCK();
      *(int *)(lVar4 + 0x94) = *(int *)(lVar4 + 0x94) + -1;
      UNLOCK();
    }
    else {
      LOCK();
      *(int *)(lVar4 + 0x94) = *(int *)(lVar4 + 0x94) + 1;
      UNLOCK();
    }
LAB_1c0018252:
    if (*(char *)(puVar3 + 1) == '\0') {
      LOCK();
      *(int *)(lVar4 + 0x9c) = *(int *)(lVar4 + 0x9c) + -1;
      UNLOCK();
    }
    else {
      LOCK();
      *(int *)(lVar4 + 0x9c) = *(int *)(lVar4 + 0x9c) + 1;
      UNLOCK();
    }
  }
  else {
    if (iVar2 == 2) {
      if (*(char *)(puVar3 + 1) == '\0') {
        LOCK();
        *(int *)(lVar4 + 0x90) = *(int *)(lVar4 + 0x90) + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)(lVar4 + 0x90) = *(int *)(lVar4 + 0x90) + 1;
        UNLOCK();
      }
      goto LAB_1c0018252;
    }
    if (iVar2 == 3) {
      if (*(char *)(puVar3 + 1) == '\0') {
        LOCK();
        *(int *)(lVar4 + 0x98) = *(int *)(lVar4 + 0x98) + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)(lVar4 + 0x98) = *(int *)(lVar4 + 0x98) + 1;
        UNLOCK();
      }
      goto LAB_1c0018252;
    }
  }
  iVar2 = *(int *)(puVar3 + 2);
  if (iVar2 == 1) {
    if (*(char *)(puVar3 + 1) == '\0') {
      LOCK();
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
      UNLOCK();
    }
    else {
      LOCK();
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
      UNLOCK();
    }
  }
  else if (iVar2 == 2) {
    if (*(char *)(puVar3 + 1) == '\0') {
      LOCK();
      *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + -1;
      UNLOCK();
    }
    else {
      LOCK();
      *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
      UNLOCK();
    }
  }
  else {
    if (iVar2 != 3) goto LAB_1c00182d6;
    if (*(char *)(puVar3 + 1) == '\0') {
      LOCK();
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;
      UNLOCK();
    }
    else {
      LOCK();
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
      UNLOCK();
    }
  }
  if (*(char *)(puVar3 + 1) == '\0') {
    LOCK();
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + -1;
    UNLOCK();
  }
  else {
    LOCK();
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + 1;
    UNLOCK();
  }
LAB_1c00182d6:
  if ((_DisableFStatesCrashdump == 0) ||
     (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x598) + 8) + 0x9c) == 0)) {
    uVar14 = 0;
  }
  else {
    uVar14 = 1;
  }
  PoFxSetComponentWake(*(undefined8 *)(lVar4 + 0x1b0),0,uVar14);
  if (*(int *)(param_1 + 0x9c) == 1) {
    puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0x30);
    *puVar1 = *puVar1 & 0xffffdfff;
  }
  else if (*(int *)(param_1 + 0x9c) == 0) {
    puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0x30);
    *puVar1 = *puVar1 | 0x2000;
  }
  ExReleaseFastMutex(param_1 + 0x5a0);
  IoInvalidateDeviceState(*(undefined8 *)(param_1 + 8));
  return iVar9;
}



===== SdhostPdoGenerateDeviceId @ 1c0018384 =====

int SdhostPdoGenerateDeviceId(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  *param_2 = 0;
  pcVar2 = (char *)ExAllocatePool2(0x100,0x80,0x64496453);
  if (pcVar2 == (char *)0x0) {
    return -0x3fffff66;
  }
  if (*(int *)(param_1 + 0xb4) == 1) {
    if (*(char *)(param_1 + 0xc2) == '\0') {
      iVar1 = -0x3fffffff;
      goto LAB_1c00184be;
    }
    if (*(char *)(param_1 + 0xc2) == '\x01') {
      uVar3 = RtlStringCbPrintfA(pcVar2,0x80,"%s\\VID_%04x&PID_%04x","SD");
      iVar1 = (int)uVar3;
    }
    else {
      uVar3 = RtlStringCbPrintfA(pcVar2,0x80,"%s\\VID_%04x&PID_%04x&FN_%d","SD");
      iVar1 = (int)uVar3;
    }
  }
  else {
    uVar3 = RtlStringCbPrintfA(pcVar2,0x80,"%s\\VID_%02x&OID_%04x&PID_%s&REV_%d.%d","SD");
    iVar1 = (int)uVar3;
  }
  if (-1 < iVar1) {
    *param_2 = pcVar2;
    return iVar1;
  }
LAB_1c00184be:
  ExFreePoolWithTag(pcVar2,0x64496453);
  return iVar1;
}



===== SdhostPdoGetCompatibleIds @ 1c00184f8 =====

int SdhostPdoGetCompatibleIds(longlong param_1,ulonglong *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  char *pcVar4;
  char *local_res18 [2];
  
  pcVar2 = (char *)ExAllocatePool2(0x100,0x80,0x64496453);
  if (pcVar2 == (char *)0x0) {
    return -0x3fffff66;
  }
  local_res18[0] = pcVar2;
  if (*(int *)(param_1 + 0xb4) == 2) {
    pcVar4 = "%s\\CLASS_STORAGE";
LAB_1c0018558:
    uVar3 = RtlStringCbPrintfA(pcVar2,0x80,pcVar4,"SD");
    iVar1 = (int)uVar3;
  }
  else {
    if (*(int *)(param_1 + 0xb4) == 3) {
      pcVar4 = "%s\\CLASS_MMC";
      goto LAB_1c0018558;
    }
    if ((7 < *(byte *)(param_1 + 0xb0)) ||
       (*(char *)(param_1 + 0x114 + (ulonglong)*(byte *)(param_1 + 0xb0) * 0x90) == '\0')) {
      iVar1 = -0x3fffffff;
      goto LAB_1c00185db;
    }
    uVar3 = RtlStringCbPrintfA(pcVar2,0x80,"%s\\CLASS_%02x","SD");
    iVar1 = (int)uVar3;
  }
  if (-1 < iVar1) {
    iVar1 = SdhostStringsToMultiString(local_res18,1,param_2);
    pcVar2 = local_res18[0];
  }
LAB_1c00185db:
  ExFreePoolWithTag(pcVar2,0x64496453);
  return iVar1;
}



===== SdhostPdoGetDeviceResetInterface @ 1c001860c =====

undefined8 SdhostPdoGetDeviceResetInterface(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  int *piVar4;
  undefined8 uVar5;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((*(undefined **)(lVar1 + 8) != &GUID_DEVICE_RESET_INTERFACE_STANDARD) &&
     (lVar3 = RtlCompareMemory(*(undefined **)(lVar1 + 8),&GUID_DEVICE_RESET_INTERFACE_STANDARD,0x10
                              ), lVar3 != 0x10)) {
    return 0xc00000bb;
  }
  if (((*(ushort *)(lVar1 + 0x10) < 0x50) || (*(short *)(lVar1 + 0x12) != 1)) ||
     (puVar2 = *(undefined4 **)(lVar1 + 0x18), puVar2 == (undefined4 *)0x0)) {
    uVar5 = 0xc000000d;
  }
  else {
    piVar4 = (int *)ExAllocatePool2(0x40,0x18,0x63496453);
    if (piVar4 == (int *)0x0) {
      ExFreePoolWithTag(0,0x63496453);
      uVar5 = 0xc000009a;
    }
    else {
      *(undefined8 *)(piVar4 + 2) = param_1;
      *piVar4 = 0x43455253;
      *(code **)(puVar2 + 4) = SdhostDeviceResetInterfaceReference;
      *(code **)(puVar2 + 6) = SdhostDeviceResetInterfaceDereference;
      *(code **)(puVar2 + 8) = SdhostDeviceResetInterfaceReset;
      *puVar2 = 0x10050;
      *(int **)(puVar2 + 2) = piVar4;
      SdhostDeviceResetInterfaceReference(piVar4);
      uVar5 = 0;
    }
  }
  return uVar5;
}



===== SdhostPdoGetHardwareIds @ 1c001871c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SdhostPdoGetHardwareIds(longlong param_1,ulonglong *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 auStack_88 [32];
  uint local_68;
  uint local_60;
  longlong local_58;
  char *local_48 [4];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  local_48[0] = (char *)0x0;
  local_48[1] = (char *)0x0;
  local_48[2] = (char *)0x0;
  local_48[3] = (char *)0x0;
  iVar1 = SdhostPdoGenerateDeviceId(param_1,local_48);
  if (iVar1 < 0) {
    return iVar1;
  }
  uVar5 = 1;
  if (*(int *)(param_1 + 0xb4) - 2U < 2) {
    pcVar2 = (char *)ExAllocatePool2(0x100,0x80,0x64496453);
    if (pcVar2 != (char *)0x0) {
      local_58 = param_1 + 0xe3;
      local_60 = (uint)*(ushort *)(param_1 + 0xdc);
      local_68 = (uint)*(byte *)(param_1 + 0xda);
      local_48[1] = pcVar2;
      uVar3 = RtlStringCbPrintfA(pcVar2,0x80,"%s\\VID_%02x&OID_%04x&PID_%s","SD");
      iVar1 = (int)uVar3;
LAB_1c0018800:
      uVar5 = 2;
      if (iVar1 < 0) goto LAB_1c0018817;
      goto LAB_1c0018806;
    }
  }
  else {
    if (*(char *)(param_1 + 0x115 + (ulonglong)*(byte *)(param_1 + 0xb0) * 0x90) == '\0') {
LAB_1c0018806:
      iVar1 = SdhostStringsToMultiString(local_48,(int)uVar5,param_2);
      goto LAB_1c0018817;
    }
    pcVar2 = (char *)ExAllocatePool2(0x100,0x80,0x64496453);
    if (pcVar2 != (char *)0x0) {
      local_60 = (uint)*(ushort *)(param_1 + 0x118 + (ulonglong)*(byte *)(param_1 + 0xb0) * 0x90);
      local_68 = (uint)*(ushort *)(param_1 + 0x116 + (ulonglong)*(byte *)(param_1 + 0xb0) * 0x90);
      local_48[1] = pcVar2;
      uVar3 = RtlStringCbPrintfA(pcVar2,0x80,"%s\\VID_%04x&PID_%04x","SD");
      iVar1 = (int)uVar3;
      goto LAB_1c0018800;
    }
  }
  iVar1 = -0x3fffff66;
LAB_1c0018817:
  do {
    uVar4 = (int)uVar5 - 1;
    uVar5 = (ulonglong)uVar4;
    ExFreePoolWithTag(local_48[uVar5],0x64496453);
  } while (uVar4 != 0);
  return iVar1;
}



===== SdhostPdoGetReenumerationInterface @ 1c00188cc =====

undefined8 SdhostPdoGetReenumerationInterface(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  int *piVar4;
  undefined8 uVar5;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((*(undefined **)(lVar1 + 8) != &GUID_REENUMERATE_SELF_INTERFACE_STANDARD) &&
     (lVar3 = RtlCompareMemory(*(undefined **)(lVar1 + 8),&GUID_REENUMERATE_SELF_INTERFACE_STANDARD,
                               0x10), lVar3 != 0x10)) {
    return 0xc00000bb;
  }
  if (((*(ushort *)(lVar1 + 0x10) < 0x28) || (*(short *)(lVar1 + 0x12) != 1)) ||
     (puVar2 = *(undefined4 **)(lVar1 + 0x18), puVar2 == (undefined4 *)0x0)) {
    uVar5 = 0xc000000d;
  }
  else {
    piVar4 = (int *)ExAllocatePool2(0x40,0x18,0x63496453);
    if (piVar4 == (int *)0x0) {
      ExFreePoolWithTag(0,0x63496453);
      uVar5 = 0xc000009a;
    }
    else {
      *(undefined8 *)(piVar4 + 2) = param_1;
      *piVar4 = 0x43524453;
      *(code **)(puVar2 + 4) = SdhostReenumerationInterfaceReference;
      *(code **)(puVar2 + 6) = SdhostReenumerationInterfaceDereference;
      *(code **)(puVar2 + 8) = SdhostReenumerationInterfaceReenumerate;
      *puVar2 = 0x10028;
      *(int **)(puVar2 + 2) = piVar4;
      SdhostReenumerationInterfaceReference(piVar4);
      uVar5 = 0;
    }
  }
  return uVar5;
}



===== SdhostPdoGetSdioSdbusInterface @ 1c00189dc =====

undefined8 SdhostPdoGetSdioSdbusInterface(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  int *piVar4;
  undefined8 uVar5;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((*(undefined **)(lVar1 + 8) != &GUID_SDBUS_INTERFACE_STANDARD) &&
     (lVar3 = RtlCompareMemory(*(undefined **)(lVar1 + 8),&GUID_SDBUS_INTERFACE_STANDARD,0x10),
     lVar3 != 0x10)) {
    return 0xc00000bb;
  }
  if (((*(ushort *)(lVar1 + 0x10) < 0x30) || (*(short *)(lVar1 + 0x12) != 0x101)) ||
     (puVar2 = *(undefined4 **)(lVar1 + 0x18), puVar2 == (undefined4 *)0x0)) {
    uVar5 = 0xc000000d;
  }
  else {
    piVar4 = (int *)ExAllocatePool2(0x40,0x28,0x63496453);
    if (piVar4 == (int *)0x0) {
      ExFreePoolWithTag(0,0x63496453);
      uVar5 = 0xc000009a;
    }
    else {
      *(undefined8 *)(piVar4 + 4) = param_1;
      *piVar4 = 0x43494453;
      *(code **)(puVar2 + 4) = SdhostSdioInterfaceReference;
      *(code **)(puVar2 + 6) = SdhostSdioInterfaceDereference;
      *(code **)(puVar2 + 10) = SdhostSdioInterfaceAcknowledgeInt;
      *(code **)(puVar2 + 8) = SdhostSdioInitializeInterface;
      *puVar2 = 0x1010030;
      *(int **)(puVar2 + 2) = piVar4;
      SdhostSdioInterfaceReference(piVar4);
      uVar5 = 0;
    }
  }
  return uVar5;
}



===== SdhostPdoPnp @ 1c0018afc =====

undefined4 SdhostPdoPnp(longlong param_1,short *param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  bool bVar9;
  
  bVar2 = *(byte *)(*(longlong *)(param_2 + 0x5c) + 1);
  if (bVar2 < 10) {
    if (bVar2 == 9) {
      uVar5 = SdhostPdoQueryCapabilities(param_1,(longlong)param_2);
      iVar4 = (int)uVar5;
    }
    else {
      iVar4 = 0;
      if (bVar2 == 0) {
        lVar6 = IoAllocateWorkItem(*(undefined8 *)(param_1 + 8));
        if (lVar6 == 0) {
LAB_1c0018bd5:
          iVar4 = -0x3fffff66;
        }
        else {
          *(byte *)(*(longlong *)(param_2 + 0x5c) + 3) =
               *(byte *)(*(longlong *)(param_2 + 0x5c) + 3) | 1;
          SdhostQueueWorkItem(*(longlong *)(param_1 + 0xa0),lVar6,SdhostPdoStartDeviceWorker,param_4
                              ,param_2,'\0');
          iVar4 = 0x103;
        }
        goto LAB_1c0018d13;
      }
      if (bVar2 == 1) {
        uVar5 = SdhostPdoQueryRemoveDevice(param_1);
        iVar4 = (int)uVar5;
      }
      else if (bVar2 == 2) {
        iVar4 = SdhostPdoRemoveDevice(param_1);
      }
      else {
        if (bVar2 == 3) {
          bVar9 = *(int *)(param_1 + 0x18) == 4;
LAB_1c0018b88:
          if (bVar9) {
            *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
          }
          goto LAB_1c0018d13;
        }
        if (bVar2 == 4) {
          uVar5 = SdhostPdoStopDevice(param_1);
          iVar4 = (int)uVar5;
        }
        else {
          if (bVar2 == 5) goto LAB_1c0018d13;
          if (bVar2 == 6) {
            bVar9 = *(int *)(param_1 + 0x18) == 2;
            goto LAB_1c0018b88;
          }
          if (bVar2 == 7) {
            iVar4 = SdhostPdoQueryDeviceRelations(param_1,(longlong)param_2);
          }
          else {
            if (bVar2 != 8) goto LAB_1c0018c64;
            uVar5 = SdhostPdoQueryInterface(param_1,(longlong)param_2);
            iVar4 = (int)uVar5;
          }
        }
      }
    }
LAB_1c0018d03:
    if (iVar4 == -0x3fffff45) goto LAB_1c0018d21;
  }
  else {
    if ((bVar2 != 10) && (bVar2 != 0xb)) {
      if (bVar2 == 0xc) {
        uVar7 = SdhostPdoQueryDeviceText(param_1,(longlong)param_2);
        iVar4 = (int)uVar7;
      }
      else {
        if (bVar2 == 0xd) goto LAB_1c0018d11;
        if (bVar2 == 0x13) {
          iVar4 = SdhostPdoQueryId(param_1,(longlong)param_2);
        }
        else if (bVar2 == 0x14) {
          puVar1 = (uint *)(param_2 + 0x1c);
          iVar4 = 0;
          if (puVar1 == (uint *)0x0) {
            iVar4 = -0x3ffffff3;
          }
          else {
            if (0 < *(int *)(param_1 + 0x9c)) {
              *puVar1 = *puVar1 | 0x20;
            }
            if ((*(uint *)(param_1 + 4) & 4) != 0) {
              *puVar1 = *puVar1 | 4;
            }
          }
        }
        else {
          if (bVar2 == 0x15) {
            puVar8 = (undefined8 *)ExAllocatePool2(0x100,0x18,0x69426453);
            iVar4 = 0;
            *(undefined8 **)(param_2 + 0x1c) = puVar8;
            if (puVar8 == (undefined8 *)0x0) goto LAB_1c0018bd5;
            *puVar8 = 0x4e894036e700cc04;
            puVar8[1] = 0xcd005ff4eb897995;
            *(undefined4 *)(*(longlong *)(param_2 + 0x1c) + 0x10) = 0xf;
            *(undefined4 *)(*(longlong *)(param_2 + 0x1c) + 0x14) = 0;
            goto LAB_1c0018d13;
          }
          if (bVar2 == 0x16) {
            iVar4 = SdhostPdoDeviceUsageNotification(param_1,(longlong)param_2);
          }
          else if (bVar2 == 0x17) {
            uVar7 = SdhostPdoSurpriseRemoval(param_1);
            iVar4 = (int)uVar7;
          }
          else {
LAB_1c0018c64:
            iVar4 = *(int *)(param_2 + 0x18);
          }
        }
      }
      goto LAB_1c0018d03;
    }
LAB_1c0018d11:
    iVar4 = 0;
  }
LAB_1c0018d13:
  *(int *)(param_2 + 0x18) = iVar4;
  if (iVar4 == 0x103) {
    return 0x103;
  }
LAB_1c0018d21:
  uVar3 = *(undefined4 *)(param_2 + 0x18);
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== SdhostPdoQueryCapabilities @ 1c0018d50 =====

undefined8 SdhostPdoQueryCapabilities(longlong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  
  puVar4 = *(undefined8 **)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar8 = *(uint *)((longlong)puVar4 + 4) & 0xfffffdb7;
  *(uint *)((longlong)puVar4 + 4) = uVar8;
  uVar8 = ((uint)*(byte *)(*(longlong *)(param_1 + 0x598) + 0x68) << 4 ^ uVar8) & 0x10 ^ uVar8;
  *(uint *)((longlong)puVar4 + 4) = uVar8;
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x598) + 4);
  bVar2 = *(byte *)(param_1 + 0xb0);
  *(undefined4 *)((longlong)puVar4 + 0x14) = 1;
  *(uint *)(puVar4 + 1) = (uint)bVar1 << 0x10 | (uint)bVar2;
  *(undefined4 *)(puVar4 + 3) = 4;
  *(undefined4 *)((longlong)puVar4 + 0x1c) = 4;
  *(undefined4 *)(puVar4 + 4) = 4;
  *(undefined4 *)((longlong)puVar4 + 0x24) = 4;
  *(undefined4 *)(puVar4 + 5) = 4;
  if ((*(int *)(param_1 + 0xb4) == 2) || (*(int *)(param_1 + 0xb4) == 3)) {
    uVar8 = uVar8 | 0x80;
    *(uint *)((longlong)puVar4 + 4) = uVar8;
  }
  if ((*(int *)(param_1 + 0xb4) == 1) &&
     (((*(uint *)(*(longlong *)(param_1 + 0x598) + 0xb4) >> (*(byte *)(param_1 + 0xb0) & 0x1f) & 1)
       != 0 || ((*(byte *)(param_1 + ((ulonglong)*(byte *)(param_1 + 0xb0) + 2) * 0x90) & 1) != 0)))
     ) {
    *(uint *)((longlong)puVar4 + 4) = uVar8 | 0x1000;
  }
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x598) + 8);
  if (*(int *)(lVar5 + 0x34) == 0) {
    *(undefined8 *)((longlong)puVar4 + 0x2c) = 0;
    uVar7 = 100;
    *(undefined8 *)((longlong)puVar4 + 0x34) = 0;
  }
  else {
    iVar3 = *(int *)(lVar5 + 0x4c);
    *(undefined4 *)(puVar4 + 6) = 0;
    iVar9 = 4;
    if (iVar3 < 4) {
      iVar9 = iVar3;
    }
    *(int *)((longlong)puVar4 + 0x2c) = iVar9;
    *(undefined4 *)((longlong)puVar4 + 0x34) = *(undefined4 *)(lVar5 + 0x54);
    *(undefined4 *)(puVar4 + 7) = *(undefined4 *)(lVar5 + 0x58);
    uVar7 = *(undefined4 *)(lVar5 + 0x5c);
  }
  *(undefined4 *)((longlong)puVar4 + 0x3c) = uVar7;
  uVar6 = puVar4[1];
  *(undefined8 *)(param_1 + 0x20) = *puVar4;
  *(undefined8 *)(param_1 + 0x28) = uVar6;
  uVar6 = puVar4[3];
  *(undefined8 *)(param_1 + 0x30) = puVar4[2];
  *(undefined8 *)(param_1 + 0x38) = uVar6;
  uVar6 = puVar4[5];
  *(undefined8 *)(param_1 + 0x40) = puVar4[4];
  *(undefined8 *)(param_1 + 0x48) = uVar6;
  uVar6 = puVar4[7];
  *(undefined8 *)(param_1 + 0x50) = puVar4[6];
  *(undefined8 *)(param_1 + 0x58) = uVar6;
  return 0;
}



===== SdhostPdoQueryDeviceRelations @ 1c0018e9c =====

int SdhostPdoQueryDeviceRelations(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 4) {
    puVar2 = (undefined4 *)ExAllocatePool2(0x100,0x10,0x72446453);
    if (puVar2 == (undefined4 *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = ObReferenceObjectByPointer(*(undefined8 *)(param_1 + 8),0,0,0);
      if (iVar1 < 0) {
        ExFreePoolWithTag(puVar2,0x72446453);
      }
      else {
        *puVar2 = 1;
        *(undefined8 *)(puVar2 + 2) = *(undefined8 *)(param_1 + 8);
        *(undefined4 **)(param_2 + 0x38) = puVar2;
      }
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 0x30);
  }
  return iVar1;
}



===== SdhostPdoQueryDeviceText @ 1c0018f58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SdhostPdoQueryDeviceText(longlong param_1,longlong param_2)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char *pcVar6;
  longlong lVar7;
  char *pcVar8;
  undefined1 auStack_108 [32];
  char *local_e8;
  ushort local_d8;
  short local_d6;
  undefined4 local_d4;
  longlong local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  char local_a8 [128];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_108;
  local_d4 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) != 0) {
    return 0xc00000bb;
  }
  if (*(int *)(param_1 + 0xb4) != 1) {
    pcVar8 = local_a8;
    lVar4 = 0x80;
    if (*(int *)(param_1 + 0xb4) == 2) {
      do {
        if ((lVar4 == -0x7fffff7e) ||
           (pcVar8[(longlong)"SD Memory Card" - (longlong)local_a8] == '\0')) break;
        *pcVar8 = pcVar8[(longlong)"SD Memory Card" - (longlong)local_a8];
        pcVar8 = pcVar8 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    else {
      do {
        if ((lVar4 == -0x7fffff7e) ||
           (pcVar8[(longlong)"MMC Memory Card" - (longlong)local_a8] == '\0')) break;
        *pcVar8 = pcVar8[(longlong)"MMC Memory Card" - (longlong)local_a8];
        pcVar8 = pcVar8 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    pcVar6 = pcVar8 + -1;
    if (lVar4 != 0) {
      pcVar6 = pcVar8;
    }
    *pcVar6 = '\0';
    if (lVar4 == 0) {
      return 0x80000005;
    }
    goto LAB_1c0019026;
  }
  pcVar6 = (char *)0x0;
  lVar4 = (ulonglong)*(byte *)(param_1 + 0xb0) * 0x90 + param_1 + 0xb8;
  pcVar8 = (char *)(lVar4 + 0x69);
  if (*pcVar8 == '\0') {
    pcVar8 = (char *)(param_1 + 0x121);
    if (*pcVar8 != '\0') {
      lVar4 = param_1 + 0xb8;
      goto LAB_1c0018fe3;
    }
LAB_1c0018fef:
    pcVar8 = "Generic";
  }
  else {
LAB_1c0018fe3:
    pcVar6 = (char *)(lVar4 + 0xaa);
    if (pcVar8 == (char *)0x0) goto LAB_1c0018fef;
  }
  local_e8 = "SDIO Device";
  if (pcVar6 != (char *)0x0) {
    local_e8 = pcVar6;
  }
  uVar5 = RtlStringCbPrintfA(local_a8,0x80,"%s %s",pcVar8);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
LAB_1c0019026:
  RtlInitAnsiString(&local_c8,local_a8);
  lVar4 = -1;
  do {
    lVar7 = lVar4 + 1;
    lVar2 = lVar4 + 1;
    lVar4 = lVar7;
  } while (local_a8[lVar2] != '\0');
  sVar1 = ((short)lVar7 + 1) * 2;
  local_d0 = ExAllocatePool2(0x100,sVar1,0x64496453);
  if (local_d0 == 0) {
    return 0xc000009a;
  }
  local_d8 = 0;
  local_d6 = sVar1;
  uVar3 = RtlAnsiStringToUnicodeString(&local_d8,&local_c8,0);
  if ((int)uVar3 < 0) {
    ExFreePoolWithTag(local_d0,0x64496453);
    return (ulonglong)uVar3;
  }
  *(undefined2 *)(local_d0 + (ulonglong)(local_d8 >> 1) * 2) = 0;
  *(longlong *)(param_2 + 0x38) = local_d0;
  return 0;
}



===== SdhostPdoQueryId @ 1c001919c =====

int SdhostPdoQueryId(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 local_res10;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_res10 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_38,0);
  iVar2 = *(int *)(lVar1 + 8);
  if (iVar2 == 0) {
    iVar2 = SdhostPdoGenerateDeviceId(param_1,&local_res10);
    if (iVar2 < 0) {
      return iVar2;
    }
    RtlInitAnsiString(&local_18,local_res10);
    iVar2 = RtlAnsiStringToUnicodeString(&local_38,&local_18,1);
    ExFreePoolWithTag(local_res10,0x64496453);
  }
  else if (iVar2 == 1) {
    iVar2 = SdhostPdoGetHardwareIds(param_1,&local_38);
  }
  else if (iVar2 == 2) {
    iVar2 = SdhostPdoGetCompatibleIds(param_1,&local_38);
  }
  else if (iVar2 == 3) {
    local_28 = 0;
    uStack_20 = 0;
    RtlInitAnsiString(&local_28,"123456");
    iVar2 = RtlAnsiStringToUnicodeString(&local_38,&local_28,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = RtlIntegerToUnicodeString
                      (*(undefined1 *)(*(longlong *)(param_1 + 0x598) + 4),10,&local_38);
    if (iVar2 < 0) {
      RtlFreeUnicodeString(&local_38);
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x30);
  }
  if (-1 < iVar2) {
    *(undefined8 *)(param_2 + 0x38) = uStack_30;
  }
  return iVar2;
}



===== SdhostPdoQueryInterface @ 1c0019324 =====

undefined8 SdhostPdoQueryInterface(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if ((*(undefined **)(lVar2 + 8) == &GUID_SDBUS_INTERFACE_STANDARD) ||
     (lVar1 = RtlCompareMemory(*(undefined **)(lVar2 + 8),&GUID_SDBUS_INTERFACE_STANDARD,0x10),
     lVar1 == 0x10)) {
    uVar3 = SdhostPdoGetSdioSdbusInterface(param_1,param_2);
    return uVar3;
  }
  if ((*(undefined **)(lVar2 + 8) == &GUID_REENUMERATE_SELF_INTERFACE_STANDARD) ||
     (lVar1 = RtlCompareMemory(*(undefined **)(lVar2 + 8),&GUID_REENUMERATE_SELF_INTERFACE_STANDARD,
                               0x10), lVar1 == 0x10)) {
    uVar3 = SdhostPdoGetReenumerationInterface(param_1,param_2);
    return uVar3;
  }
  if ((*(undefined **)(lVar2 + 8) == &GUID_DEVICE_RESET_INTERFACE_STANDARD) ||
     (lVar2 = RtlCompareMemory(*(undefined **)(lVar2 + 8),&GUID_DEVICE_RESET_INTERFACE_STANDARD,0x10
                              ), lVar2 == 0x10)) {
    uVar3 = SdhostPdoGetDeviceResetInterface(param_1,param_2);
    return uVar3;
  }
  return 0xc00000bb;
}



===== SdhostPdoRemoveDevice @ 1c0019404 =====

undefined4 SdhostPdoRemoveDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 extraout_EAX;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  uVar5 = 0;
  lVar2 = *(longlong *)(lVar1 + 8);
  if ((*(uint *)(param_1 + 4) & 2) == 0) {
    if (*(longlong *)(lVar2 + 0x1b0) != 0) {
      PoFxActivateComponent(*(longlong *)(lVar2 + 0x1b0),0,1);
    }
    ExAcquireFastMutex(lVar1 + 0x30);
    uVar5 = SdhostPdoPowerDown(param_1);
    lVar4 = CONCAT44((int)((ulonglong)param_1 >> 0x20),uVar5);
    if (*(int *)(lVar4 + 0x84) == 1) {
      LOCK();
      *(int *)(lVar2 + 0x14b0) = *(int *)(lVar2 + 0x14b0) + -1;
      UNLOCK();
    }
    if (*(int *)(lVar4 + 0x18) == 1) {
      LOCK();
      *(int *)(lVar2 + 0x14ac) = *(int *)(lVar2 + 0x14ac) + -1;
      UNLOCK();
    }
    uVar5 = *(undefined4 *)(lVar4 + 0x18);
    *(undefined4 *)(lVar4 + 0x18) = 0;
    *(undefined4 *)(lVar4 + 0x84) = 4;
    *(undefined4 *)(lVar4 + 0x1c) = uVar5;
    SdhostPoFxAddDbgLog(lVar2,0x52656d50,4,(longlong)*(int *)(lVar2 + 0x14b0),
                        (longlong)*(int *)(lVar2 + 0x14ac));
    ExReleaseFastMutex(lVar1 + 0x30);
    if (*(longlong *)(lVar2 + 0x1b0) != 0) {
      PoFxIdleComponent(*(longlong *)(lVar2 + 0x1b0),0,0);
    }
    SdhostUninitializeDevice(lVar4);
    uVar5 = extraout_EAX;
  }
  else {
    if (*(longlong *)(lVar1 + 0x10) != 0) {
      lVar2 = *(longlong *)(lVar1 + 0x10);
      lVar4 = 0;
      do {
        lVar3 = lVar2;
        if (lVar3 == *(longlong *)(param_1 + 8)) {
          if (lVar4 == 0) {
            *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(param_1 + 0xa8);
          }
          else {
            *(undefined8 *)(*(longlong *)(lVar4 + 0x40) + 0xa8) = *(undefined8 *)(param_1 + 0xa8);
          }
          break;
        }
        lVar2 = *(longlong *)(*(longlong *)(lVar3 + 0x40) + 0xa8);
        lVar4 = lVar3;
      } while (lVar2 != 0);
    }
    if (*(longlong *)(lVar1 + 0x10) == 0) {
      SdhostDrainIrpQueue(lVar1);
    }
    if (*(longlong *)(param_1 + 0x5f0) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x5f0),0x63496453);
      *(undefined8 *)(param_1 + 0x5f0) = 0;
    }
    if (*(int *)(param_1 + 0x18) != 6) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x18) = 6;
      IoDeleteDevice(*(undefined8 *)(param_1 + 8));
    }
  }
  if (*(char *)(lVar1 + 0x6a) != '\0') {
    ExAcquireFastMutex(lVar1 + 0x30);
    SdhostInitializeSlot(lVar1);
    ExReleaseFastMutex(lVar1 + 0x30);
  }
  return uVar5;
}



===== SdhostPdoStopDevice @ 1c00195f4 =====

undefined8 SdhostPdoStopDevice(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x598);
  lVar4 = *(longlong *)(lVar1 + 8);
  if (*(int *)(lVar4 + 0x18) == 1) {
    if (*(longlong *)(lVar4 + 0x1b0) != 0) {
      PoFxActivateComponent(*(longlong *)(lVar4 + 0x1b0),0,1);
    }
    ExAcquireFastMutex(lVar1 + 0x30);
    uVar3 = SdhostPdoPowerDown(param_1);
    lVar4 = CONCAT44((int)((ulonglong)lVar4 >> 0x20),uVar3);
    if ((*(uint *)(param_1 + 4) & 1) == 0) {
      if (*(int *)(param_1 + 0x84) == 1) {
        LOCK();
        *(int *)(lVar4 + 0x14b0) = *(int *)(lVar4 + 0x14b0) + -1;
        UNLOCK();
      }
      if (*(int *)(param_1 + 0x18) == 1) {
        LOCK();
        *(int *)(lVar4 + 0x14ac) = *(int *)(lVar4 + 0x14ac) + -1;
        UNLOCK();
      }
    }
    *(undefined4 *)(param_1 + 0x84) = 4;
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = 3;
    SdhostPoFxAddDbgLog(lVar4,0x53746f50,4,(longlong)*(int *)(lVar4 + 0x14b0),
                        (longlong)*(int *)(lVar4 + 0x14ac));
    ExReleaseFastMutex(lVar1 + 0x30);
    if (*(longlong *)(lVar4 + 0x1b0) != 0) {
      PoFxIdleComponent(*(longlong *)(lVar4 + 0x1b0),0,0);
    }
    uVar2 = SdhostUninitializeDevice(param_1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== SdhostPnp @ 1c0019700 =====

void SdhostPnp(longlong param_1,short *param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 1) {
    SdhostFdoPnp((longlong)piVar1,(longlong)param_2);
  }
  else {
    SdhostPdoPnp((longlong)piVar1,param_2,param_3,param_4);
  }
  return;
}



===== SdhostQueryRemovability @ 1c0019728 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SdhostQueryRemovability(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  int *_Dst;
  ulonglong uVar4;
  longlong lVar5;
  byte bVar6;
  byte *pbVar7;
  byte bVar8;
  ulonglong uVar9;
  undefined1 auStack_a8 [48];
  undefined1 local_78;
  ushort local_70 [8];
  int local_60 [3];
  short sStack_54;
  ulonglong local_50;
  int local_48 [6];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar9 = 0;
  local_50 = 0;
  iVar1 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  local_70[4] = 0;
  local_70[5] = 0;
  local_70[6] = 0;
  local_70[7] = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  stack0xffffffffffffffa8 = 0;
  if (((*(longlong *)(param_1 + 0x130) == 0x4942001ad7b46895) &&
      (*(longlong *)(param_1 + 0x138) == 0x43a81066d4a71f89)) ||
     ((*(longlong *)(param_1 + 0x130) == 0x11d0b510c8ebdfb0 &&
      (*(longlong *)(param_1 + 0x138) == -0x1cbdda365fff1a80)))) {
    bVar8 = *(byte *)(param_1 + 0x1464);
    bVar6 = 0;
    lVar5 = *(longlong *)(param_1 + 0x1468);
    lVar2 = lVar5;
    if (bVar8 != 0) {
      do {
        if (((*(longlong *)(param_1 + 0x130) == 0x4942001ad7b46895) &&
            (*(longlong *)(param_1 + 0x138) == 0x43a81066d4a71f89)) &&
           ((*(uint *)(lVar2 + 0x24) & 0x800000) != 0)) {
          return 0;
        }
        bVar6 = bVar6 + 1;
        lVar2 = *(longlong *)(param_1 + 0x1468 + (ulonglong)bVar6 * 8);
      } while (bVar6 < bVar8);
    }
    lVar2 = *(longlong *)(param_1 + 0x130) + -0x4942001ad7b46895;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0x138) + -0x43a81066d4a71f89;
    }
    bVar6 = 0;
    if (bVar8 != 0) {
      do {
        bVar6 = bVar6 + 1;
        *(undefined1 *)(lVar5 + 0x68) = 1;
        lVar5 = *(longlong *)(param_1 + 0x1468 + (ulonglong)bVar6 * 8);
      } while (bVar6 < *(byte *)(param_1 + 0x1464));
    }
    local_48[0] = 0;
    local_48[1] = 0;
    local_48[2] = 0;
    local_48[3] = 0;
    local_48[4] = 0;
    local_78 = lVar2 != 0;
    uVar3 = SdhostEnumerateAcpiChildren(*(undefined8 *)(param_1 + 0xb0),local_48,0x14);
    if ((int)uVar3 == -0x7ffffffb) {
      iVar1 = local_48[1];
      uVar3 = (ulonglong)(uint)local_48[1];
      if ((uint)local_48[1] < 0x14) {
        iVar1 = -0x3febfff1;
      }
      else {
        _Dst = (int *)ExAllocatePool2(0x40,uVar3,0x69416453);
        if (_Dst == (int *)0x0) {
          iVar1 = -0x3fffff66;
        }
        else {
          memset(_Dst,0,uVar3);
          uVar3 = SdhostEnumerateAcpiChildren(*(undefined8 *)(param_1 + 0xb0),_Dst,iVar1);
          iVar1 = (int)uVar3;
          if (_Dst[1] == 0) {
LAB_1c00199b4:
            iVar1 = -0x3febfff1;
          }
          else {
            pbVar7 = (byte *)(_Dst + 2);
            bVar8 = 1;
            if (1 < (uint)_Dst[1]) {
              do {
                pbVar7 = pbVar7 + (ulonglong)*(uint *)(pbVar7 + 4) + 8;
                if ((*pbVar7 & 1) != 0) {
                  RtlInitAnsiString(local_70,pbVar7 + 8);
                  SdhostEvaluateAcpiMethod
                            (*(undefined8 *)(param_1 + 0xb0),local_70,0x5244415f,local_60);
                  if (sStack_54 != 0) goto LAB_1c00199b4;
                  uVar3 = local_50 >> 0x10;
                  RtlInitAnsiString(local_70,pbVar7 + 8);
                  uVar4 = SdhostEvaluateAcpiMethod
                                    (*(undefined8 *)(param_1 + 0xb0),local_70,0x564d525f,local_60);
                  lVar5 = *(longlong *)(param_1 + 0x1468 + (uVar3 & 0xffff) * 8);
                  iVar1 = (int)uVar4;
                  if ((iVar1 < 0) || (sStack_54 != 0)) {
                    *(undefined1 *)(lVar5 + 0x68) = local_78;
                  }
                  else if ((int)local_50 == 0) {
                    *(undefined1 *)(lVar5 + 0x68) = 0;
                  }
                }
                bVar8 = bVar8 + 1;
              } while ((uint)bVar8 < (uint)_Dst[1]);
            }
          }
          ExFreePoolWithTag(_Dst,0x69416453);
          if (-1 < iVar1) {
            return iVar1;
          }
        }
      }
    }
    else {
      iVar1 = -0x3febfff1;
      local_78 = lVar2 != 0;
    }
    lVar5 = *(longlong *)(param_1 + 0x1468);
    if (*(char *)(param_1 + 0x1464) != '\0') {
      do {
        *(undefined1 *)(lVar5 + 0x68) = local_78;
        bVar8 = (char)uVar9 + 1;
        uVar9 = (ulonglong)bVar8;
        lVar5 = *(longlong *)(param_1 + 0x1468 + uVar9 * 8);
      } while (bVar8 < *(byte *)(param_1 + 0x1464));
    }
  }
  return iVar1;
}



===== entry @ 1c001b010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c001b044 =====

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



===== DriverEntry @ 1c001b080 =====

undefined8 DriverEntry(void)

{
  return 0;
}


