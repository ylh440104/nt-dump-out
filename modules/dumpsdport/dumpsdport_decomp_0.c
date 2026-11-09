
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



===== SdhostAllocateRequest @ 1c0001020 =====

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



===== SdhostBasicCommandSelect @ 1c0001060 =====

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
LAB_1c00010ec:
    bVar2 = 0;
  }
  else {
    if ((local_5c != 2) && (local_5c != 3)) {
      if (local_5c == 4) {
        bVar2 = 0x10;
        goto LAB_1c00010ef;
      }
      if ((((local_5c != 5) && (local_5c != 6)) && (local_5c != 7)) &&
         ((local_5c != 8 && (local_5c != 9)))) goto LAB_1c00010ec;
    }
    bVar2 = 4;
  }
LAB_1c00010ef:
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



===== SdhostBasicCommandSend @ 1c00011b0 =====

void SdhostBasicCommandSend(longlong param_1,longlong param_2,longlong param_3)

{
  if (*(int *)(*(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x20) + 0x44) == 1) {
    SdhostIssueCommand(param_1,(int *)param_2,(undefined8 *)&CmdAppSd,
                       *(int *)(*(longlong *)(param_2 + 0xb8) + 0xb48),0,0,0,param_3,
                       SdhostBasicCommandSendAfterApp,0);
  }
  else {
    SdhostBasicCommandSendAfterApp(param_1,param_2,param_3);
  }
  return;
}



===== SdhostBasicCommandSendAfterApp @ 1c0001220 =====

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



===== SdhostBuildBasicCommand @ 1c00012fc =====

void SdhostBuildBasicCommand(longlong param_1,longlong param_2,longlong param_3)

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
    SdhostIssueCommand(param_1,(int *)param_2,(undefined8 *)&CmdDeselect,0,0,0,0,param_3,
                       SdhostBasicCommandSend,0);
  }
  return;
}



===== SdhostBuildCommand @ 1c00013d8 =====

void SdhostBuildCommand(longlong param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  uVar3 = KeQueryPerformanceCounter(0);
  *(ulonglong *)(param_2 + 0xa8) = uVar3;
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



===== SdhostBuildDataCommand @ 1c0001480 =====

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



===== SdhostBuildDataCommandAfterBlockCount @ 1c0001560 =====

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



===== SdhostBuildDataCommandComplete @ 1c00016f0 =====

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
LAB_1c0001768:
    bVar2 = 0;
  }
  else {
    if ((local_5c != 2) && (local_5c != 3)) {
      if (local_5c == 4) {
        bVar2 = 0x10;
        goto LAB_1c000176a;
      }
      if ((((local_5c != 5) && (local_5c != 6)) && (local_5c != 7)) &&
         ((local_5c != 8 && (local_5c != 9)))) goto LAB_1c0001768;
    }
    bVar2 = 4;
  }
LAB_1c000176a:
  *(byte *)(lVar1 + 0x38) = bVar2;
  memcpy((void *)(lVar1 + 0x28),param_2 + 0x1e,(ulonglong)bVar2);
  param_2[0x26] = 0;
  param_2[0x27] = 0;
  SdhostCompleteRequestPostError(param_2);
  return param_2[0x19];
}



===== SdhostBuildTransfer @ 1c00017b4 =====

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
LAB_1c0001af6:
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
LAB_1c000189f:
      if (uVar2 != 2) goto LAB_1c00018f7;
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
        if (param_2[7] != 2) goto LAB_1c000189f;
        uVar8 = *(uint *)(param_1 + 0xb2c) & 2;
      }
      if (uVar8 == 0) goto LAB_1c000189f;
      *puVar1 = 1;
LAB_1c00018f7:
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
        SdhostCompleteRequest(param_2,uVar9,uVar10,uVar11);
        if (param_2[0x19] < 0) goto LAB_1c0001af6;
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
        if ((char)param_2[0x23] == '\0') goto LAB_1c0001af6;
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



===== SdhostCompleteRequest @ 1c0001b1c =====

void SdhostCompleteRequest(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 local_res8;
  
  local_res8 = 0;
  if (((param_1[0x19] + 0x80000000U & 0x80000000) == 0) && (param_1[0x19] != -0x3fffffea)) {
    lVar1 = *(longlong *)(param_1 + 0x2e);
    LOCK();
    bVar4 = param_1[0x2c] == 0;
    if (bVar4) {
      param_1[0x2c] = 1;
    }
    UNLOCK();
    if (bVar4) {
      uVar3 = *(undefined8 *)(param_1 + 0x28);
      *(int *)(lVar1 + 0x1e10) = *(int *)(lVar1 + 0x1e10) + 1;
      *(undefined8 *)(lVar1 + 0x1e18) = uVar3;
      *(int *)(lVar1 + 0x1e20) = param_1[0x19];
      uVar3 = KeQueryInterruptTimePrecise(&local_res8);
      *(undefined8 *)(lVar1 + 0x1e28) = uVar3;
      lVar2 = *(longlong *)(*(longlong *)(lVar1 + 8) + 8);
      if (*(char *)(lVar1 + 0xb38) == '\0') {
        SdhostQueueWorkItem(lVar2,*(longlong *)(param_1 + 0x58),*(longlong *)(param_1 + 0x58),
                            param_4,(short *)param_1);
        return;
      }
      SdhostErrorRecoveryWorker(lVar2,param_1);
    }
  }
  SdhostCompleteRequestPostError(param_1);
  return;
}



===== SdhostCompleteRequestPostError @ 1c0001be0 =====

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



===== SdhostDumpProcessBusRequest @ 1c0001e34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdhostDumpProcessBusRequest
              (longlong param_1,int *param_2,undefined8 *param_3,int param_4,undefined2 param_5,
              undefined2 param_6,longlong param_7,char param_8)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined1 local_res10 [8];
  undefined1 local_res18 [8];
  undefined1 local_48 [4];
  uint local_44;
  uint local_40 [2];
  undefined8 local_38;
  longlong local_30;
  
  if ((param_2[0x19] != -0x3fffffea) || (param_8 == '\0')) {
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
  }
  if (*(int *)(param_3 + 2) == 1) {
    iVar2 = SdhostIssueRequest(param_1,param_2,0,0);
  }
  else {
    iVar2 = SdhostBuildTransfer(param_1,param_2,param_7,0,0);
  }
  if ((((iVar2 + 0x80000000U & 0x80000000) != 0) || (iVar2 == -0x3fffffea)) && (param_2[0x19] != 0))
  {
    local_30 = *(longlong *)(*(longlong *)(param_1 + 8) + 0xc0);
    do {
      uVar5 = *(uint *)(param_1 + 0xc30);
      local_44 = *(uint *)(param_1 + 0xc30);
      local_40[0] = *(uint *)(param_1 + 0xc34);
      lVar1 = *(longlong *)(param_1 + 8);
      local_48[0] = 0;
      local_38 = 0;
      local_res18[0] = 0;
      local_res10[0] = 0;
      lVar3 = KeQueryInterruptTimePrecise(&local_38);
      while( true ) {
        (**(code **)(*(longlong *)(lVar1 + 0xc0) + 0x18))
                  (*(undefined8 *)(param_1 + 0xa88),&local_44,local_40,local_48,local_res18,
                   local_res10);
        local_44 = (*(uint *)(param_1 + 0xc30) | local_44) & *(uint *)(param_1 + 0xb34);
        local_40[0] = local_40[0] | *(uint *)(param_1 + 0xc34);
        *(undefined4 *)(param_1 + 0xc30) = 0;
        *(undefined4 *)(param_1 + 0xc34) = 0;
        if (uVar5 != local_44) break;
        uVar4 = KeQueryInterruptTimePrecise(&local_38);
        if (lVar3 + 50000000U <= uVar4) {
          *(undefined4 *)(param_1 + 0xc30) = 0x8000;
          *(undefined4 *)(param_1 + 0xc34) = 0x11;
          break;
        }
        KeStallExecutionProcessor(1);
        if ((local_44 != *(uint *)(param_1 + 0xc30)) || (local_40[0] != *(uint *)(param_1 + 0xc34)))
        break;
      }
      uVar5 = uVar5 ^ local_44;
      if (uVar5 == 0) {
        if ((param_8 != '\0') && (iVar2 == 0x103)) {
          param_2[0x19] = -0x3fffffea;
          goto LAB_1c000204d;
        }
      }
      else {
        (**(code **)(local_30 + 0x30))
                  (*(undefined8 *)(param_1 + 0xa88),param_2,local_44,local_40[0]);
        if ((uVar5 >> 0xf & 1) != 0) {
          if ((local_40[0] & 0x11) == 0) {
            if ((local_40[0] & 0x22) == 0) {
              if ((local_40[0] & 0x44) == 0) {
                if ((local_40[0] & 8) == 0) {
                  iVar2 = (-(uint)((local_40[0] & 0x80) != 0) & 0xffffff19) + 0xc0000185;
                }
                else {
                  iVar2 = -0x3ffffe7a;
                }
              }
              else {
                iVar2 = -0x3fffff64;
              }
            }
            else {
              iVar2 = -0x3fffffc1;
            }
          }
          else {
            iVar2 = -0x3fffff4b;
          }
          param_2[0x19] = iVar2;
          break;
        }
        if (param_2[0x18] == 0) break;
      }
    } while ((((*param_2 == 3) || (param_2[0x19] == -0x3fffffea)) || (param_2[0x18] != 0)) ||
            (uVar5 == 0));
    iVar2 = param_2[0x19];
  }
LAB_1c000204d:
  return iVar2;
}



===== SdhostFreeRequest @ 1c00020fc =====

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



===== SdhostInitializeRequest @ 1c0002134 =====

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



===== SdhostIssueCommand @ 1c00021d8 =====

void SdhostIssueCommand(longlong param_1,int *param_2,undefined8 *param_3,int param_4,
                       undefined2 param_5,undefined2 param_6,longlong param_7,longlong param_8,
                       undefined8 param_9,undefined1 param_10)

{
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
    SdhostDumpProcessBusRequest(param_1,param_2,param_3,param_4,param_5,param_6,param_7,'\0');
  }
  return;
}



===== SdhostIssueRequest @ 1c00022e0 =====

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
      *(undefined8 *)(puVar11 + -8) = 0x1c00023ea;
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
    if (((iVar7 != 2) && (iVar7 != 3)) && (iVar7 != 4)) goto LAB_1c0002450;
    iVar7 = 10000;
  }
  *(undefined8 *)(puVar11 + -8) = 0x1c0002450;
  SdhostSetRequestTimeout((longlong)param_2,iVar7);
LAB_1c0002450:
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
    *(undefined8 *)(puVar11 + -8) = 0x1c00024ee;
    KeAcquireInStackQueuedSpinLock(param_2 + 0x56,puVar11 + 0x48);
    pcVar6 = *(code **)(lVar4 + 0x20);
    *(undefined8 *)(puVar11 + -8) = 0x1c0002503;
    iVar7 = (*pcVar6)(lVar5 + 0x10,param_2);
    *(undefined8 *)(puVar11 + -8) = 0x1c0002511;
    KeReleaseInStackQueuedSpinLock(puVar11 + 0x48);
  }
  else {
    pcVar6 = *(code **)(lVar4 + 0x20);
    *(undefined8 *)(puVar11 + -8) = 0x1c00024d7;
    iVar7 = (*pcVar6)(lVar5 + 0x10,param_2);
  }
  if (((*param_2 != 3) && ((char)param_2[0x23] != '\0')) && (*(char *)(param_1 + 0xb38) == '\0')) {
    *(undefined8 *)(puVar11 + 0x20) = 0;
    *(undefined8 *)(puVar11 + -8) = 0x1c000254c;
    KeWaitForSingleObject(param_2 + 0x30,0,0,0);
    *(undefined8 *)(puVar11 + -8) = 0x1c000255b;
    KeClearEvent(param_2 + 0x30);
    iVar7 = param_2[0x19];
    *(undefined1 *)(param_2 + 0x23) = 0;
  }
  return iVar7;
}



===== SdhostRemoveOutstandingRequest @ 1c0002590 =====

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
LAB_1c00025e4:
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
      goto LAB_1c00025e4;
    }
    puVar4 = puVar1;
  } while( true );
}



===== SdhostSendDataCommand @ 1c0002650 =====

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



===== SdhostSetRequestTimeout @ 1c00026a4 =====

void SdhostSetRequestTimeout(longlong param_1,int param_2)

{
  if ((*(longlong *)(param_1 + 0xb8) == 0) ||
     (*(char *)(*(longlong *)(param_1 + 0xb8) + 0xb38) == '\0')) {
    *(int *)(param_1 + 0x90) = param_2;
    KeSetTimer(param_1 + 0xd8,(longlong)(param_2 * -10000),param_1 + 0x118);
  }
  return;
}



===== SdhostStartNextIo @ 1c00026f8 =====

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
      iVar7 = SdhostBuildCommand(param_1,(longlong)plVar8,(longlong)(plVar2 + -0x15));
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
    if (bVar5) goto LAB_1c0002881;
  }
  if (*(longlong **)(param_1 + 0xbd8) == (longlong *)(param_1 + 0xbd8)) {
    KeSetEvent(param_1 + 0xbb0,0,0);
  }
LAB_1c0002881:
  KeReleaseInStackQueuedSpinLock(&local_38);
  return bVar5;
}



===== SdhostDisableEvents @ 1c00028bc =====

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



===== SdhostEnableEvents @ 1c000297c =====

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



===== SdhostInterruptSynchronizeDisable @ 1c0002a40 =====

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



===== SdhostInterruptSynchronizeEnable @ 1c0002a90 =====

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



===== SdhostDeselectDevice @ 1c0002ae0 =====

void SdhostDeselectDevice(longlong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdDeselect,0,0,0,0,0,0,1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 0xb50) = 0;
  }
  return;
}



===== SdhostErrorRecoveryWorker @ 1c0002b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhostErrorRecoveryWorker(undefined8 param_1,int *param_2)

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
  
  uVar3 = param_2[9];
  bVar2 = *(byte *)(param_2 + 2);
  local_res10 = 0;
  lVar6 = *(longlong *)(param_2 + 0x2e);
  iVar4 = param_2[6];
  iVar5 = param_2[0x19];
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
      if (param_2[6] != 1) {
        iVar7 = SdhostResetHost(lVar6,3);
        if (iVar7 < 0) goto LAB_1c0002c1e;
      }
      (**(code **)(*(longlong *)(*(longlong *)(lVar6 + 8) + 0xc0) + 0x40))
                (*(longlong *)
                  (*(longlong *)(lVar6 + 8) + 0xf0 + (ulonglong)*(byte *)(lVar6 + 4) * 8) + 0x10,
                 0xffffffff);
      SdhostEnableEvents(lVar6,uVar3);
    }
  }
LAB_1c0002c1e:
  lVar9 = KeQueryInterruptTimePrecise(&local_res10);
  *(longlong *)(lVar6 + 0x1e30) = lVar9 - *(longlong *)(lVar6 + 0x1e28);
  SdhostCompleteRequestPostError(param_2);
  return;
}



===== SdhostExecuteTuning @ 1c0002c5c =====

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



===== SdhostGoIdleState @ 1c0002ca4 =====

int SdhostGoIdleState(longlong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdGoIdleState,0,0,0,0,0,0,1);
  if (-1 < iVar1) {
    SdhostWait(*(uint *)(param_1 + 0x98));
  }
  return iVar1;
}



===== SdhostPowerOffMmc @ 1c0002d0c =====

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



===== SdhostPowerOffSd @ 1c0002de4 =====

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



===== SdhostPowerOnMmc @ 1c0002e3c =====

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
     ((iVar2 = SdhostSendCidAll(lVar1,param_2), -1 < iVar2 &&
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



===== SdhostPowerOnSd @ 1c0002fd0 =====

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
          (iVar2 = SdhostSendCidAll(lVar1,param_2), -1 < iVar2)))))))) &&
      (iVar2 = SdhostSendRelativeAddr(lVar1,param_2), -1 < iVar2)) &&
     ((((iVar2 = SdhostSelectDevice(lVar1,param_2), -1 < iVar2 &&
        (uVar4 = SdhostSetBusWidthSd(lVar1,param_2), -1 < (int)uVar4)) &&
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



===== SdhostResetHost @ 1c0003138 =====

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



===== SdhostResetHw @ 1c00031a4 =====

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



===== SdhostSelectDevice @ 1c00031fc =====

void SdhostSelectDevice(longlong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSelect,*(int *)(param_1 + 0xb48),0,0,
                             0,0,0,1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 0xb50) = 1;
  }
  return;
}



===== SdhostSendAppCmd @ 1c0003258 =====

void SdhostSendAppCmd(longlong param_1,int *param_2)

{
  SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSd,*(int *)(param_1 + 0xb48),0,0,0,0,0,1);
  return;
}



===== SdhostSendCidAll @ 1c000329c =====

void SdhostSendCidAll(longlong param_1,int *param_2)

{
  SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSendCidAll,0,0,0,0,0,0,1);
  return;
}



===== SdhostSendIfCondSd @ 1c00032dc =====

undefined8 SdhostSendIfCondSd(longlong param_1,int *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar2 = -(uint)((*(uint *)(param_1 + 0xb58) & 0x80) != 0) & 0x100;
  uVar1 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSendIfCondSd,uVar2 + 0x1aa,0,0,0,0,0,
                             1);
  if (-1 < (int)uVar1) {
    if (((char)param_2[0x1e] != -0x56) || ((param_2[0x1e] & 0xf00U) != uVar2 + 0x100)) {
      uVar1 = 0xc00000bb;
    }
    *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) | 0x10;
  }
  return uVar1;
}



===== SdhostSendOpCondMmc @ 1c0003380 =====

int SdhostSendOpCondMmc(longlong param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  bVar3 = 0;
  while( true ) {
    iVar2 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSendOpCondMmc,0x40ff8000,0,0,0,0,0,
                               1);
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



===== SdhostSendOpCondSd @ 1c0003478 =====

ulonglong SdhostSendOpCondSd(longlong param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = SdhostSendAppCmd(param_1,param_2);
  if (-1 < (int)uVar3) {
    iVar1 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSendOpCondSd,0,0,0,0,0,0,1);
    if (-1 < iVar1) {
      *(uint *)(param_1 + 0xb5c) = param_2[0x1e] & 0xffffff;
    }
    uVar4 = 0;
    do {
      uVar3 = SdhostSendAppCmd(param_1,param_2);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar2 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSendOpCondSd,
                                 (-(uint)((*(uint *)(param_1 + 200) & 0x10) != 0) & 0x50000000) +
                                 0x1000000 | *(uint *)(param_1 + 0xb5c),0,0,0,0,0,1);
      uVar3 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_1c00035ce;
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
LAB_1c00035ce:
  return uVar3;
}



===== SdhostSendRelativeAddr @ 1c00035f0 =====

void SdhostSendRelativeAddr(longlong param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = (uint *)(param_1 + 0xb48);
  if (*(int *)(param_1 + 0xd4) == 3) {
    *puVar1 = 0xcccc0000;
  }
  iVar2 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSendRelativeAddr,*puVar1,0,0,0,0,0,1)
  ;
  if ((-1 < iVar2) && (*(int *)(param_1 + 0xd4) != 3)) {
    *puVar1 = param_2[0x1e] & 0xffff0000;
  }
  return;
}



===== SdhostSendVoltageSwitchSd @ 1c0003684 =====

ulonglong SdhostSendVoltageSwitchSd(longlong param_1,int *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = 0;
  if ((((*(uint *)(param_1 + 200) & 8) != 0) && ((*(uint *)(param_1 + 0xb24) & 0x10) != 0)) &&
     (*(int *)(param_1 + 0xb6c) != 2)) {
    uVar1 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSwitchVoltageSd,0,0,0,0,0,0,1);
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



===== SdhostSetBusSpeed @ 1c000370c =====

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



===== SdhostSetBusWidth @ 1c000376c =====

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



===== SdhostSetBusWidthMmc @ 1c00037d0 =====

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
LAB_1c00038fc:
        uVar6 = (uint)*(byte *)(lVar2 + 0xef);
      }
      else if (*(char *)(lVar2 + 0xc4) == '\x01') {
        uVar6 = (uint)*(byte *)(lVar2 + 0xcb);
      }
      else {
        uVar6 = (uint)*(byte *)(lVar2 + 0xca);
      }
LAB_1c0003904:
      uVar6 = (uVar6 & 0xffffff0) << 4;
      goto LAB_1c0003934;
    }
    uVar6 = (uint)*(byte *)(lVar2 + 0xed);
  }
  else {
    if (param_3 != 4) {
      return 0xc00000bb;
    }
    if (*(int *)(param_1 + 0xb68) == 8) {
      uVar6 = (uint)*(byte *)(lVar2 + 0xed);
      goto LAB_1c0003904;
    }
    if (*(int *)(param_1 + 0xb68) == 6) goto LAB_1c00038fc;
    if (*(char *)(lVar2 + 0xc4) == '\x01') {
      bVar5 = *(byte *)(lVar2 + 0xcb);
    }
    else {
      bVar5 = *(byte *)(lVar2 + 0xca);
    }
    uVar6 = bVar5 & 0xf;
  }
  uVar6 = uVar6 << 8;
LAB_1c0003934:
  if (uVar6 != 0) {
    SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSwitchMmc,uVar6 | 0x3bb0000,0,0,0,0,0,1);
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
  uVar4 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSwitchMmc,iVar7,0,0,0,0,0,1);
  if (((-1 < (int)uVar4) && (uVar4 = SdhostSetBusWidth(param_1,param_3), -1 < (int)uVar4)) &&
     (*(int *)(param_1 + 0xb68) == 6)) {
    uVar4 = SdhostSetBusSpeed(param_1,6);
  }
  return uVar4;
}



===== SdhostSetBusWidthSd @ 1c0003a24 =====

ulonglong SdhostSetBusWidthSd(longlong param_1,int *param_2)

{
  uint uVar1;
  byte *pbVar2;
  ulonglong uVar3;
  
  uVar1 = *(uint *)(param_1 + 200);
  uVar3 = SdhostSendAppCmd(param_1,param_2);
  if (-1 < (int)uVar3) {
    uVar3 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSetBusWidthSd,uVar1 & 2,0,0,0,0,
                               0,1);
    if (-1 < (int)uVar3) {
      uVar3 = SdhostSendAppCmd(param_1,param_2);
      if (-1 < (int)uVar3) {
        uVar3 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSetClrCardDetectSd,0,0,0,0,0
                                   ,0,1);
        if (-1 < (int)uVar3) {
          if ((*(uint *)(param_1 + 200) & 2) != 0) {
            *(undefined1 *)(param_1 + 0xb51) = 4;
          }
          uVar3 = SdhostSetBusWidth(param_1,(uint)*(byte *)(param_1 + 0xb51));
          if (-1 < (int)uVar3) {
            uVar3 = SdhostSendAppCmd(param_1,param_2);
            if (-1 < (int)uVar3) {
              pbVar2 = *(byte **)(param_1 + 0xaf8);
              pbVar2[0] = 0;
              pbVar2[1] = 0;
              pbVar2[2] = 0;
              pbVar2[3] = 0;
              pbVar2[4] = 0;
              pbVar2[5] = 0;
              pbVar2[6] = 0;
              pbVar2[7] = 0;
              uVar3 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdAppSendScrSd,
                                         *(int *)(param_1 + 0xb48),8,1,
                                         *(longlong *)(param_1 + 0xaf0),0,0,1);
              if (-1 < (int)uVar3) {
                *(byte *)(param_1 + 0xe8) = *pbVar2 & 0xf;
                *(uint *)(param_1 + 200) =
                     pbVar2[1] >> 1 & 2 | *(uint *)(param_1 + 200) & 0xfffffffd;
                *(byte *)(param_1 + 0x114) = pbVar2[3] >> 1 & 1;
                *(byte *)(param_1 + 0xe9) = pbVar2[2] >> 7;
                uVar3 = uVar3 & 0xffffffff;
              }
            }
          }
        }
      }
    }
  }
  return uVar3;
}



===== SdhostSetClock @ 1c0003bd8 =====

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



===== SdhostSetFunctionBlockSize @ 1c0003c38 =====

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
        uVar2 = SdhostIssueCommand(lVar1,param_2,(undefined8 *)&CmdSetBlockLength,(uint)param_3,0,0,
                                   0,0,0,1);
        *(ushort *)(lVar1 + 0xb7a + (ulonglong)*(byte *)(param_1 + 0xb0) * 2) = param_3;
        return uVar2;
      }
      uVar2 = SdhostIssueCommand(lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,
                                 (uint)*(byte *)(param_1 + 0xb0) * 0x20000 + 0x2000 | param_3 & 0xff
                                 | 0x80000000,0,0,0,0,0,1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar2 = SdhostIssueCommand(lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,
                                 (uint)*(byte *)(param_1 + 0xb0) * 0x20000 + 0x2200 |
                                 (uint)(param_3 >> 8) | 0x80000000,0,0,0,0,0,1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      *(ushort *)(lVar1 + 0xb7a + (ulonglong)*(byte *)(param_1 + 0xb0) * 2) = param_3;
      return uVar2 & 0xffffffff;
    }
  }
  return 0xc000000d;
}



===== SdhostSetSignalingVoltage @ 1c0003de8 =====

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



===== SdhostSetSpeedModeMmc @ 1c0003e48 =====

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
  uVar1 = SdhostIssueCommand(param_1,param_2,(undefined8 *)&CmdSwitchMmc,iVar2,0,0,0,0,0,1);
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



===== SdhostSetSpeedModeSd @ 1c0003f00 =====

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
      goto LAB_1c000402d;
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
LAB_1c000402d:
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



===== SdhostSetVoltage @ 1c00040d0 =====

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



===== SdhostStartFunction @ 1c0004178 =====

ulonglong SdhostStartFunction(longlong param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if ((*(int *)(param_1 + 0xb4) - 2U < 2) || ((*(uint *)(param_1 + 0x608) & 1) != 0)) {
    uVar2 = 0;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x598);
    uVar2 = SdhostIssueCommand(lVar1,param_2,(undefined8 *)&CmdReadWriteDirectSdio,
                               (uint)*(byte *)(lVar1 + 0xb44) |
                               1 << (*(byte *)(param_1 + 0xb0) & 0x1f) & 0xffU | 0x80000400,0,0,0,0,
                               0,1);
    if (-1 < (int)uVar2) {
      *(byte *)(lVar1 + 0xb44) =
           *(byte *)(lVar1 + 0xb44) | (byte)(1 << (*(byte *)(param_1 + 0xb0) & 0x1f));
      uVar2 = uVar2 & 0xffffffff;
    }
  }
  return uVar2;
}



===== SdhostConvertSdcmdToCommand @ 1c000422c =====

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
LAB_1c000430f:
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  else {
    if (iVar1 == 1) {
      *(undefined4 *)(param_2 + 0x10) = 1;
      goto LAB_1c00042ff;
    }
    if (iVar1 == 2) {
      *(undefined4 *)(param_2 + 0x10) = 2;
    }
    else if (iVar1 == 3) {
      *(undefined4 *)(param_2 + 0x10) = 3;
    }
    else {
      if (iVar1 != 4) goto LAB_1c000430f;
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
LAB_1c00042ff:
  *(undefined4 *)(param_2 + 0x14) = 0;
  return;
}



===== SdhostWait @ 1c0004334 =====

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



===== SdhostQueueWorkItem @ 1c00043a0 =====

void SdhostQueueWorkItem(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                        short *param_5)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  cVar1 = IoTryQueueWorkItem(param_2,SdhostErrorRecoveryWorker,0,param_5);
  lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),DriverEntry);
  lVar4 = *(longlong *)(lVar3 + 0x20);
  lVar5 = lVar3 + 0x28;
  if (((param_5 != (short *)0x0) && (*param_5 == 6)) &&
     (*(longlong *)(*(longlong *)(param_5 + 0x5c) + 0x28) == param_1)) {
    lVar4 = *(longlong *)(lVar3 + 0x68);
    lVar5 = lVar3 + 0x70;
  }
  if (cVar1 == '\0') {
    if ((lVar4 != 0) && (uVar2 = IoSizeofWorkItem(), 0x27 < uVar2)) {
      KeSetPriorityThread(lVar4,0xd);
      ObfReferenceObject(param_1);
      *(longlong *)(param_2 + 0x18) = param_1;
      *(code **)(param_2 + 0x10) = SdhostErrorRecoveryWorker;
      *(short **)(param_2 + 0x20) = param_5;
      *(longlong *)(param_2 + 8) = param_2;
      *(longlong *)param_2 = param_2;
      KeInsertQueue(lVar5,param_2);
      return;
    }
    IoQueueWorkItemEx(param_2,SdhostErrorRecoveryWorker,0,param_5);
  }
  return;
}



===== DriverEntry @ 1c00044d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(undefined8 param_1,uint *param_2)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  int iVar4;
  undefined4 local_res10 [2];
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  local_res10[0] = 0;
  PoSetHiberRange(0,0x10000,lVar1,0x3948,0x74446453);
  if (*(longlong *)(lVar1 + 0xae8) != 0) {
    PoSetHiberRange(0,0x10000,*(longlong *)(lVar1 + 0xae8),*(undefined4 *)(lVar1 + 0xaf0),0x74446453
                   );
  }
  *(code **)(param_2 + 0xe) = SdhostDumpOpen;
  *(code **)(param_2 + 0x10) = SdhostDumpWrite;
  *(code **)(param_2 + 0x20) = SdhostDumpWritePending;
  *(code **)(param_2 + 0x28) = SdhostDumpRead;
  *(code **)(param_2 + 0x12) = SdhostDumpFinish;
  if (0xff < *param_2) {
    *(code **)(param_2 + 0x3e) = SdhostDumpGetTransferSizes;
  }
  if (0x107 < *param_2) {
    *(code **)(param_2 + 0x40) = SdhostDumpNotify;
  }
  param_2[0x1b] = *(uint *)(lVar1 + 0x78);
  memset(&DAT_1c0009290,0,0x1f8);
  uVar3 = 0;
  _DAT_1c0009290 = *(undefined8 *)(param_2 + 0xc);
  _DAT_1c0009298 = *(undefined8 *)(param_2 + 4);
  _DAT_1c00092a0 = *(undefined8 *)(param_2 + 6);
  _DAT_1c00092a8 = *(undefined8 *)(param_2 + 8);
  _DAT_1c00092b0 = *(undefined8 *)(param_2 + 10);
  _DAT_1c00092b8 = param_2[0x1c];
  DAT_1c0009448 = (undefined1)param_2[0x1a];
  DAT_1c0009449 = *(undefined1 *)((longlong)param_2 + 0x69);
  DumpExtension = lVar1;
  DAT_1c0009288 = lVar1 + 8;
  *(undefined1 *)(lVar1 + 0xb8) = 0;
  *(undefined1 *)(lVar1 + 0xb46) = 0;
  if (*(int *)(lVar1 + 0xb54) == 2) {
    if (DAT_1c000944a == '\0') {
      iVar4 = (uint)((*(uint *)(lVar1 + 0x78) & 0xfff) != 0) + (*(uint *)(lVar1 + 0x78) >> 0xc);
      iVar2 = HalDmaAllocateCrashDumpRegistersEx
                        (*(undefined8 *)(lVar1 + 0xab8),iVar4,0,lVar1 + 0xb08,local_res10);
      uVar3 = (ulonglong)iVar2;
      if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x2c,0x80000002,uVar3,iVar4,local_res10[0]);
      }
      *(undefined4 *)(lVar1 + 0xac0) = local_res10[0];
      DAT_1c000944a = '\x01';
    }
  }
  else {
    DAT_1c000944a = '\0';
  }
  return uVar3 & 0xffffffff;
}



===== SdPortCompleteRequest @ 1c00046f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdPortCompleteRequest(int *param_1,longlong param_2,ulonglong param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  
                    /* 0x46f0  1  SdPortCompleteRequest */
  lVar1 = *(longlong *)(param_1 + 0x2e);
  iVar2 = (int)param_2;
  param_1[0x19] = iVar2;
  if ((((iVar2 + 0x80000000U & 0x80000000) != 0) || (iVar2 == -0x3fffffea)) &&
     (iVar2 = *param_1, iVar2 != 1)) {
    if (iVar2 == 2) {
      *param_1 = 3;
      SdhostIssueRequest(lVar1,param_1,*(longlong *)(param_1 + 0x28),(char)param_1[0x23]);
      return;
    }
    if (iVar2 != 3) {
      return;
    }
    param_2 = *(longlong *)(param_1 + 0x14);
    if (param_2 != 0) {
      if (*(char *)(lVar1 + 0xb38) == '\0') {
        param_3 = (ulonglong)CONCAT31((int3)((uint)param_1[7] >> 8),param_1[7] == 2);
        (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x5a) + 8) + 0x60))();
        param_1[0x14] = 0;
        param_1[0x15] = 0;
        param_1[0x16] = 0;
      }
      else {
        param_3 = *(ulonglong *)(lVar1 + 0xb00);
        param_4 = 0;
        param_2 = *(longlong *)(param_1 + 0x5c);
        (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x5a) + 8) + 0xd0))();
      }
    }
  }
  SdhostCompleteRequest(param_1,param_2,param_3,param_4);
  return;
}



===== SdPortGetPciConfigSpace @ 1c00047d0 =====

undefined8 SdPortGetPciConfigSpace(void)

{
                    /* 0x47d0  2  SdPortGetPciConfigSpace
                       0x47d0  4  SdPortPoFxPowerControl
                       0x47d0  11  SdPortSetPciConfigSpace */
  return 0xc0000002;
}



===== SdPortInitialize @ 1c00047e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdPortInitialize(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *_Dst;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
                    /* 0x47e0  3  SdPortInitialize */
  if (param_3 == (undefined8 *)0x0) {
    uVar4 = 0xc000000d;
  }
  else {
    _Dst = *(undefined8 **)(DumpExtension + 0x1f00);
    memset(_Dst,0,0x90);
    uVar4 = param_3[1];
    *_Dst = *param_3;
    _Dst[1] = uVar4;
    uVar4 = param_3[3];
    _Dst[2] = param_3[2];
    _Dst[3] = uVar4;
    uVar4 = param_3[5];
    _Dst[4] = param_3[4];
    _Dst[5] = uVar4;
    uVar4 = param_3[7];
    _Dst[6] = param_3[6];
    _Dst[7] = uVar4;
    uVar4 = param_3[9];
    _Dst[8] = param_3[8];
    _Dst[9] = uVar4;
    uVar4 = param_3[0xb];
    _Dst[10] = param_3[10];
    _Dst[0xb] = uVar4;
    uVar4 = param_3[0xd];
    _Dst[0xc] = param_3[0xc];
    _Dst[0xd] = uVar4;
    uVar1 = *(undefined4 *)((longlong)param_3 + 0x74);
    uVar2 = *(undefined4 *)(param_3 + 0xf);
    uVar3 = *(undefined4 *)((longlong)param_3 + 0x7c);
    *(undefined4 *)(_Dst + 0xe) = *(undefined4 *)(param_3 + 0xe);
    *(undefined4 *)((longlong)_Dst + 0x74) = uVar1;
    *(undefined4 *)(_Dst + 0xf) = uVar2;
    *(undefined4 *)((longlong)_Dst + 0x7c) = uVar3;
    uVar1 = *(undefined4 *)((longlong)param_3 + 0x84);
    uVar2 = *(undefined4 *)(param_3 + 0x11);
    uVar3 = *(undefined4 *)((longlong)param_3 + 0x8c);
    *(undefined4 *)(_Dst + 0x10) = *(undefined4 *)(param_3 + 0x10);
    *(undefined4 *)((longlong)_Dst + 0x84) = uVar1;
    *(undefined4 *)(_Dst + 0x11) = uVar2;
    *(undefined4 *)((longlong)_Dst + 0x8c) = uVar3;
    uVar4 = (*(code *)_Dst[0xb])
                      (*(undefined8 *)(DAT_1c0009288 + 0xa88),*(undefined8 *)(DAT_1c0009288 + 0xa98)
                       ,*(undefined8 *)(DAT_1c0009288 + 0xaa0),
                       *(undefined4 *)(DAT_1c0009288 + 0xaa8),*(undefined1 *)(DAT_1c0009288 + 0xb38)
                      );
  }
  return uVar4;
}



===== SdPortReadRegisterBufferUchar @ 1c00048b0 =====

void SdPortReadRegisterBufferUchar(longlong param_1,uint param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  
                    /* 0x48b0  5  SdPortReadRegisterBufferUchar */
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



===== SdPortReadRegisterBufferUlong @ 1c00048f0 =====

void SdPortReadRegisterBufferUlong(longlong param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  
                    /* 0x48f0  6  SdPortReadRegisterBufferUlong */
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



===== SdPortReadRegisterBufferUshort @ 1c0004930 =====

void SdPortReadRegisterBufferUshort(longlong param_1,uint param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined2 *puVar2;
  
                    /* 0x4930  7  SdPortReadRegisterBufferUshort */
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



===== SdPortReadRegisterUchar @ 1c0004970 =====

undefined1 SdPortReadRegisterUchar(longlong param_1,uint param_2)

{
                    /* 0x4970  8  SdPortReadRegisterUchar */
  if (param_1 == 0) {
    return 0xff;
  }
  return *(undefined1 *)((ulonglong)param_2 + param_1);
}



===== SdPortReadRegisterUlong @ 1c0004990 =====

undefined4 SdPortReadRegisterUlong(longlong param_1,uint param_2)

{
                    /* 0x4990  9  SdPortReadRegisterUlong */
  if (param_1 == 0) {
    return 0xffbadbad;
  }
  return *(undefined4 *)((ulonglong)param_2 + param_1);
}



===== SdPortReadRegisterUshort @ 1c00049b0 =====

undefined2 SdPortReadRegisterUshort(longlong param_1,uint param_2)

{
                    /* 0x49b0  10  SdPortReadRegisterUshort */
  if (param_1 == 0) {
    return 0xfbad;
  }
  return *(undefined2 *)((ulonglong)param_2 + param_1);
}



===== SdPortWait @ 1c00049d0 =====

void SdPortWait(void)

{
                    /* 0x49d0  12  SdPortWait */
  KeStallExecutionProcessor();
  return;
}



===== SdPortWriteRegisterBufferUchar @ 1c00049f0 =====

void SdPortWriteRegisterBufferUchar(longlong param_1,uint param_2,undefined1 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  
                    /* 0x49f0  13  SdPortWriteRegisterBufferUchar */
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



===== SdPortWriteRegisterBufferUlong @ 1c0004a30 =====

void SdPortWriteRegisterBufferUlong(longlong param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  
                    /* 0x4a30  14  SdPortWriteRegisterBufferUlong */
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



===== SdPortWriteRegisterBufferUshort @ 1c0004a70 =====

void SdPortWriteRegisterBufferUshort(longlong param_1,uint param_2,undefined2 *param_3,uint param_4)

{
  ulonglong uVar1;
  undefined2 *puVar2;
  
                    /* 0x4a70  15  SdPortWriteRegisterBufferUshort */
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



===== SdPortWriteRegisterUchar @ 1c0004ab0 =====

void SdPortWriteRegisterUchar(longlong param_1,uint param_2,undefined1 param_3)

{
                    /* 0x4ab0  16  SdPortWriteRegisterUchar */
  if (param_1 != 0) {
    *(undefined1 *)((ulonglong)param_2 + param_1) = param_3;
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdPortWriteRegisterUlong @ 1c0004ad0 =====

void SdPortWriteRegisterUlong(longlong param_1,uint param_2,undefined4 param_3)

{
                    /* 0x4ad0  17  SdPortWriteRegisterUlong */
  if (param_1 != 0) {
    *(undefined4 *)((ulonglong)param_2 + param_1) = param_3;
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdPortWriteRegisterUshort @ 1c0004af0 =====

void SdPortWriteRegisterUshort(longlong param_1,uint param_2,undefined2 param_3)

{
                    /* 0x4af0  18  SdPortWriteRegisterUshort */
  if (param_1 != 0) {
    *(undefined2 *)((ulonglong)param_2 + param_1) = param_3;
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdhostDumpFinish @ 1c0004b10 =====

void SdhostDumpFinish(void)

{
  longlong lVar1;
  
  lVar1 = DumpExtension;
  if (*(int *)(DumpExtension + 0x33ac) == 2) {
    SdhostPowerOffSd(DumpExtension + 0x32f8,(int *)&DAT_1c00092c8);
  }
  else if (*(int *)(DumpExtension + 0x33ac) == 3) {
    SdhostPowerOffMmc(DumpExtension + 0x32f8,(int *)&DAT_1c00092c8);
  }
  if ((((DAT_1c0009448 != '\0') && (DAT_1c000944a != '\0')) && (lVar1 != 0)) &&
     (*(int *)(lVar1 + 0xb54) == 2)) {
    HalDmaFreeCrashDumpRegistersEx(*(undefined8 *)(lVar1 + 0xab8),0);
    DAT_1c000944a = '\0';
  }
  return;
}



===== SdhostDumpGetTransferSizes @ 1c0004ba0 =====

void SdhostDumpGetTransferSizes(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0x200;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(DumpExtension + 0x78);
  }
  return;
}



===== SdhostDumpIoRequest @ 1c0004bc4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SdhostDumpIoRequest(ulonglong *param_1,longlong param_2,char param_3,char param_4)

{
  longlong lVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  lVar1 = DAT_1c0009288;
  _DAT_1c0009440 = *param_1;
  if ((*(uint *)(DAT_1c0009288 + 200) & 1) != 0) {
    _DAT_1c0009440 = _DAT_1c0009440 >> 9;
  }
  uVar4 = *(uint *)(param_2 + 0x28) >> 9;
  uVar3 = (ushort)uVar4;
  if ((((*(uint *)(DAT_1c0009288 + 0xb24) >> 0x15 & 1) == 0) &&
      (((*(char *)(DAT_1c0009288 + 0x114) == '\0' ||
        ((*(uint *)(DAT_1c0009288 + 0xb24) >> 0x16 & 1) == 0)) && (1 < uVar3)))) &&
     (iVar2 = SdhostDumpProcessBusRequest
                        (DAT_1c0009288,(int *)&DAT_1c00092c8,(undefined8 *)&CmdSetBlockCount,
                         uVar4 & 0xffff,0,0,0,param_4), iVar2 < 0)) {
    return;
  }
  if (param_3 == '\0') {
    _DAT_1c0009458 = _DAT_1c0009458 + 1;
    if (uVar3 == 1) {
      local_88 = 0x11;
      local_78 = 0x100000002;
    }
    else {
      local_88 = 0x12;
      local_78 = 0x100000003;
    }
  }
  else {
    _DAT_1c0009460 = _DAT_1c0009460 + 1;
    if (uVar3 == 1) {
      local_88 = 0x18;
      local_78 = 0x200000002;
    }
    else {
      local_88 = 0x19;
      local_78 = 0x200000003;
    }
  }
  uStack_40 = 0;
  local_48 = 0;
  uStack_60 = 0;
  local_68 = 0;
  uStack_70 = 0;
  uStack_80 = 0x200000001;
  local_38 = 0;
  local_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  SdhostDumpProcessBusRequest
            (lVar1,(int *)&DAT_1c00092c8,&local_88,DAT_1c0009440,0x200,uVar3,param_2,param_4);
  return;
}



===== SdhostDumpNotify @ 1c0004e00 =====

void SdhostDumpNotify(int param_1)

{
  if (((param_1 == 2) &&
      (((DAT_1c0009448 == '\0' || (DAT_1c0009449 != '\0')) && (DAT_1c000944a != '\0')))) &&
     ((DumpExtension != 0 && (*(int *)(DumpExtension + 0xb54) == 2)))) {
    HalDmaFreeCrashDumpRegistersEx(*(undefined8 *)(DumpExtension + 0xab8),0);
    DAT_1c000944a = '\0';
  }
  return;
}



===== SdhostDumpOpen @ 1c0004e70 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte SdhostDumpOpen(undefined8 param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  
  lVar2 = DAT_1c0009288;
  uVar1 = *(uint *)(DAT_1c0009288 + 0xb24);
  uVar3 = uVar1 & 0xfffffc7f;
  _DAT_1c00092c0 = param_1;
  *(uint *)(DAT_1c0009288 + 0xb24) = uVar3;
  if ((uVar1 >> 0x13 & 1) != 0) {
    uVar3 = uVar1 & 0xfffffc5f;
    *(uint *)(lVar2 + 0xb24) = uVar3;
  }
  if (*(int *)(lVar2 + 0xd4) == 2) {
    *(uint *)(lVar2 + 0xb24) = uVar3 & 0xffffffef;
  }
  memset(&DAT_1c00092c8,0,0x178);
  _DAT_1c0009380 = lVar2;
  SdhostDisableEvents(lVar2,0xffffffff);
  iVar4 = SdhostDumpResetHostAndDevice();
  return (byte)((uint)iVar4 >> 0x1f) ^ 1;
}



===== SdhostDumpRead @ 1c0004f00 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdhostDumpRead(int param_1,longlong *param_2,longlong param_3)

{
  int iVar1;
  ulonglong local_res10 [3];
  
  local_res10[0] = *param_2 + _DAT_1c00092c0;
  if (param_1 == 0) {
    iVar1 = SdhostDumpReadWriteSynchronous(local_res10,param_3,'\0');
  }
  else {
    if (((param_1 != 1) && (param_1 != 2)) && (param_1 != 3)) {
      return 0;
    }
    iVar1 = SdhostDumpReadWriteAsynchronous(param_1,local_res10,param_3,'\0');
  }
  return iVar1;
}



===== SdhostDumpReadWriteAsynchronous @ 1c0004f5c =====

int SdhostDumpReadWriteAsynchronous(int param_1,ulonglong *param_2,longlong param_3,char param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 == 1) {
    DAT_1c000944c = 0;
    do {
      iVar1 = SdhostDumpIoRequest(param_2,param_3,param_4,'\x01');
      if (iVar1 == 0x103) {
        return 0x103;
      }
      if (-1 < DAT_1c000932c) {
        return DAT_1c000932c;
      }
      iVar1 = SdhostDumpResetHostAndDevice();
      if (iVar1 < 0) {
        return iVar1;
      }
      DAT_1c000944c = DAT_1c000944c + 1;
    } while (DAT_1c000944c < 3);
  }
  else if ((param_1 == 2) || (param_1 == 3)) {
    for (; DAT_1c000944c < 3; DAT_1c000944c = DAT_1c000944c + 1) {
      if (DAT_1c000932c == -0x3fffffea) {
        iVar1 = SdhostDumpProcessBusRequest
                          (DAT_1c0009288,(int *)&DAT_1c00092c8,(undefined8 *)&DAT_1c00092d0,
                           DAT_1c00092ec,DAT_1c00092f2,DAT_1c00092f4,param_3,param_1 != 3);
      }
      else {
        iVar1 = SdhostDumpIoRequest(param_2,param_3,param_4,param_1 != 3);
      }
      if (iVar1 == 0x103) {
        return 0x103;
      }
      if (-1 < DAT_1c000932c) {
        return DAT_1c000932c;
      }
      iVar1 = SdhostDumpResetHostAndDevice();
      if (iVar1 < 0) {
        return iVar1;
      }
      DAT_1c000932c = -0x3ffffe7b;
    }
  }
  else {
    iVar1 = -0x3fffff45;
  }
  return iVar1;
}



===== SdhostDumpReadWriteSynchronous @ 1c00050c8 =====

int SdhostDumpReadWriteSynchronous(ulonglong *param_1,longlong param_2,char param_3)

{
  int iVar1;
  
  DAT_1c000944c = 0;
  while( true ) {
    iVar1 = SdhostDumpIoRequest(param_1,param_2,param_3,'\0');
    if (-1 < iVar1) {
      return iVar1;
    }
    iVar1 = SdhostDumpResetHostAndDevice();
    if (iVar1 < 0) break;
    DAT_1c000944c = DAT_1c000944c + 1;
    if (2 < DAT_1c000944c) {
      return iVar1;
    }
  }
  return iVar1;
}



===== SdhostDumpResetHostAndDevice @ 1c0005138 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdhostDumpResetHostAndDevice(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    _DAT_1c0009450 = _DAT_1c0009450 + 1;
    if (*(int *)(DumpExtension + 0x33ac) == 2) {
      iVar1 = SdhostPowerOnSd(DumpExtension + 0x32f8,(int *)&DAT_1c00092c8);
    }
    else {
      if (*(int *)(DumpExtension + 0x33ac) != 3) {
        return -0x3ffffff0;
      }
      iVar1 = SdhostPowerOnMmc(DumpExtension + 0x32f8,(int *)&DAT_1c00092c8);
    }
    if ((iVar1 + 0x80000000U & 0x80000000) != 0) {
      return iVar1;
    }
    if (iVar1 == -0x3ffffff0) {
      return -0x3ffffff0;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 5);
  return iVar1;
}



===== SdhostDumpWrite @ 1c00051c0 =====

void SdhostDumpWrite(longlong *param_1,longlong param_2)

{
  SdhostDumpWritePending(0,param_1,param_2);
  return;
}



===== SdhostDumpWritePending @ 1c00051e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdhostDumpWritePending(int param_1,longlong *param_2,longlong param_3)

{
  int iVar1;
  ulonglong local_res10 [3];
  
  local_res10[0] = *param_2 + _DAT_1c00092c0;
  if (param_1 == 0) {
    iVar1 = SdhostDumpReadWriteSynchronous(local_res10,param_3,'\x01');
  }
  else {
    if (((param_1 != 1) && (param_1 != 2)) && (param_1 != 3)) {
      return 0;
    }
    iVar1 = SdhostDumpReadWriteAsynchronous(param_1,local_res10,param_3,'\x01');
  }
  return iVar1;
}



===== _guard_check_icall @ 1c0005250 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 1c0005270 =====

/* WARNING: Removing unreachable block (ram,0x0001c00052da) */
/* WARNING: Removing unreachable block (ram,0x0001c0005289) */
/* WARNING: Removing unreachable block (ram,0x0001c000527a) */

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



===== __security_check_cookie @ 1c0005340 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0005380 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00053b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00053b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00053e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0005440 =====

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



===== memset @ 1c0005740 =====

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



===== __memset_repmovs @ 1c0005880 =====

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



===== __memset_query @ 1c0005900 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005980 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0005ac0 =====

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



===== __memset_spec_plain @ 1c0005b40 =====

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



===== entry @ 1c000d010 =====

void entry(undefined8 param_1,uint *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000d044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  undefined7 uVar6;
  byte *pbVar5;
  undefined1 *puVar7;
  char *in_RDX;
  char unaff_BH;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    puVar7 = (undefined1 *)0x6;
    pcVar1 = (code *)swi(0x29);
    pcVar4 = (char *)(*pcVar1)();
    cVar2 = (char)pcVar4;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *pcVar4 = *pcVar4 + cVar2;
    *puVar7 = *puVar7;
    *pcVar4 = *pcVar4 + cVar2;
    uVar6 = (undefined7)((ulonglong)pcVar4 >> 8);
    bVar3 = (cVar2 + -0x6b) * '\x02';
    pbVar5 = (byte *)CONCAT71(uVar6,bVar3);
    *(int *)pbVar5 = *(int *)pbVar5 + (int)pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    bVar3 = bVar3 ^ *pbVar5;
    pcVar4 = (char *)CONCAT71(uVar6,bVar3);
    *pcVar4 = *pcVar4 + bVar3;
    *pcVar4 = *pcVar4 + bVar3;
    *pcVar4 = *pcVar4 + bVar3;
    *in_RDX = *in_RDX + unaff_BH;
    *puVar7 = *puVar7;
    *pcVar4 = *pcVar4 + bVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


