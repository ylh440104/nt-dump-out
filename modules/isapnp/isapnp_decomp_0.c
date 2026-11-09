
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



===== PipCompleteRequest @ 1c0001020 =====

void PipCompleteRequest(longlong param_1,undefined4 param_2)

{
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = param_2;
  IofCompleteRequest(param_1,0);
  return;
}



===== PiPnPFdoCompletion @ 1c0001050 =====

undefined8 PiPnPFdoCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,1);
  return 0xc0000016;
}



===== FdoContingentPowerCompletionRoutine @ 1c0001080 =====

void FdoContingentPowerCompletionRoutine
               (longlong param_1,char param_2,undefined4 param_3,longlong param_4,int *param_5)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_4 + 0xb8);
  *(int *)(param_4 + 0x30) = *param_5;
  if (*param_5 < 0) {
    PoStartNextPowerIrp(param_4);
    IofCompleteRequest(param_4,0);
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0x40);
    PoStartNextPowerIrp(param_4);
    if (param_2 == '\x02') {
      *(undefined4 *)(lVar2 + 100) = *(undefined4 *)(lVar1 + 0x18);
      *(undefined4 *)(lVar2 + 0x68) = param_3;
      PoSetPowerState(param_1,1,param_3);
    }
    *(char *)(param_4 + 0x43) = *(char *)(param_4 + 0x43) + '\x01';
    *(longlong *)(param_4 + 0xb8) = *(longlong *)(param_4 + 0xb8) + 0x48;
    PoCallDriver(*(undefined8 *)(lVar2 + 0x58),param_4);
  }
  return;
}



===== PiDispatchPower @ 1c0001160 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PiDispatchPower(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58) == 0) {
    PoStartNextPowerIrp(param_2);
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar2 = 0xc000000e;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    IofCompleteRequest(param_2,0);
  }
  else {
    bVar1 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
    if (bVar1 < 4) {
      uVar2 = (*(code *)(&PiPowerDispatchTableFdo)[bVar1])(param_1,param_2);
    }
    else {
      uVar2 = PipPassPowerIrpFdo(param_1,param_2);
    }
  }
  return uVar2;
}



===== PipPassPowerIrpFdo @ 1c00011f0 =====

void PipPassPowerIrpFdo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  PoStartNextPowerIrp(param_2);
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  PoCallDriver(*(undefined8 *)(lVar1 + 0x58),param_2);
  return;
}



===== PipSetQueryPowerStateFdo @ 1c0001250 =====

undefined8 PipSetQueryPowerStateFdo(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar3 + 0x10) == 0) {
    iVar1 = *(int *)(lVar3 + 0x18);
    if ((iVar1 == 1) ||
       ((((iVar1 != 2 && (iVar1 != 3)) && (iVar1 != 4)) && ((iVar1 != 5 && (iVar1 != 6)))))) {
      uVar4 = 1;
    }
    else {
      uVar4 = 4;
    }
    *(byte *)(lVar3 + 3) = *(byte *)(lVar3 + 3) | 1;
    PoRequestPowerIrp(*(undefined8 *)(lVar2 + 0x50),
                      CONCAT71((int7)((ulonglong)lVar3 >> 8),*(undefined1 *)(lVar3 + 1)),uVar4,
                      FdoContingentPowerCompletionRoutine,param_2,0);
    uVar4 = 0x103;
  }
  else {
    uVar4 = PipPassPowerIrpFdo(param_1,param_2);
  }
  return uVar4;
}



===== _guard_check_icall @ 1c00012e0 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 1c0001300 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001340 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001370 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00013a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0001400 =====

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



===== PiAddDevice @ 1c0007010 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PiAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  bool bVar10;
  longlong local_res18;
  undefined8 local_res20;
  longlong local_48 [4];
  
  local_res18 = 0;
  uVar6 = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  KeWaitForSingleObject(&IsaBusNumberLock,0,0,0,0);
  ActiveIsaCount = ActiveIsaCount + 1;
  RtlInitUnicodeString(local_48 + 1,0);
  iVar4 = IoCreateDevice(param_1,0x70,0,0x2a,CONCAT44(uVar6,0x100),0,&local_res18);
  if (iVar4 < 0) goto LAB_1c00071d3;
  puVar1 = *(undefined4 **)(local_res18 + 0x40);
  *puVar1 = 0x80000000;
  *(longlong *)(puVar1 + 0x14) = local_res18;
  uVar7 = IoAttachDeviceToDeviceStack(local_res18,param_2);
  local_res20 = 0;
  local_48[0] = 0;
  uVar8 = 1;
  *(undefined8 *)(puVar1 + 0x16) = uVar7;
  *(undefined8 *)(puVar1 + 0x12) = param_2;
  bVar10 = false;
  iVar5 = IoOpenDeviceRegistryKey(param_2,1,0x20019,&local_res20);
  if (iVar5 < 0) {
LAB_1c0007164:
    uVar7 = 0;
  }
  else {
    uVar8 = PipGetRegistryValue(local_res20,uVar8,local_48);
    if (-1 < (int)uVar8) {
      if ((*(int *)(local_48[0] + 4) == 4) && (3 < *(uint *)(local_48[0] + 0xc))) {
        bVar10 = *(int *)((ulonglong)*(uint *)(local_48[0] + 8) + local_48[0]) != 0;
      }
      ExFreePoolWithTag(local_48[0],0);
    }
    ZwClose(local_res20);
    if (!bVar10) goto LAB_1c0007164;
    uVar7 = 1;
  }
  uVar6 = RtlFindClearBitsAndSet(BusNumBM,1,uVar7);
  *(undefined8 *)(puVar1 + 2) = 0;
  if (ActiveIsaCount == 1) {
    puVar9 = (undefined8 *)ExAllocatePool2(0x40,0x10,0x706e70);
    if (puVar9 == (undefined8 *)0x0) {
      PipBusExtension = puVar9;
      return -0x3fffff66;
    }
    _PipFirstInit = 1;
    PipBusExtension = puVar9;
  }
  else {
    puVar9 = (undefined8 *)*PipBusExtension;
    puVar3 = PipBusExtension;
    while (puVar2 = puVar9, puVar2 != (undefined8 *)0x0) {
      puVar3 = puVar2;
      puVar9 = (undefined8 *)*puVar2;
    }
    puVar9 = (undefined8 *)ExAllocatePool2(0x40,0x10,0x706e70);
    *puVar3 = puVar9;
    if (puVar9 == (undefined8 *)0x0) {
      return -0x3fffff66;
    }
  }
  *puVar9 = 0;
  puVar9[1] = puVar1;
  puVar1[0x18] = uVar6;
  *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) & 0xffffff7f;
LAB_1c00071d3:
  KeSetEvent(&IsaBusNumberLock,0,0);
  return iVar4;
}



===== PiDispatchDevCtl @ 1c0007260 =====

ulonglong PiDispatchDevCtl(longlong param_1,longlong param_2)

{
  uint uVar1;
  int *piVar2;
  ulonglong uVar3;
  
  piVar2 = *(int **)(param_1 + 0x40);
  if (*piVar2 < 0) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(*(undefined8 *)(piVar2 + 0x16));
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x30);
    IofCompleteRequest(param_2,0);
    uVar3 = (ulonglong)uVar1;
  }
  return uVar3;
}



===== PiDispatchPnp @ 1c00072c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PiDispatchPnp(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = **(uint **)(param_1 + 0x40);
  if ((int)uVar2 < 0) {
    if (*(longlong *)(*(uint **)(param_1 + 0x40) + 0x16) != 0) {
      bVar1 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
      if (bVar1 < 0x19) {
        uVar2 = (*(code *)(&PiPnpDispatchTableFdo)[bVar1])(param_1,param_2);
      }
      else {
        uVar2 = PipPassIrp(param_1,param_2);
      }
      return uVar2;
    }
    uVar2 = 0xc000000e;
  }
  else {
    if ((uVar2 & 1) == 0) {
      return 0;
    }
    uVar2 = -(uint)(*(char *)(*(longlong *)(param_2 + 0xb8) + 1) != '\x02') & 0xc000000e;
  }
  PipCompleteRequest(param_2,uVar2);
  return uVar2;
}



===== PiUnload @ 1c0007350 =====

void PiUnload(void)

{
  if (DAT_1c0004088 != 0) {
    ExFreePoolWithTag(DAT_1c0004088,0);
  }
  return;
}



===== PipPassIrp @ 1c0007380 =====

void PipPassIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*(undefined8 *)(lVar1 + 0x58));
  return;
}



===== PipGetRegistryValue @ 1c00073b0 =====

ulonglong PipGetRegistryValue(undefined8 param_1,ulonglong param_2,longlong *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10 = param_2 & 0xffffffff00000000;
  *param_3 = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"DeferBridge");
  uVar2 = ZwQueryValueKey(param_1,&local_18,1,0,0,&local_res10);
  if (((int)uVar2 == -0x7ffffffb) || ((int)uVar2 == -0x3fffffdd)) {
    lVar3 = ExAllocatePool2(0x40,local_res10 & 0xffffffff,0x706e70);
    if (lVar3 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      uVar1 = ZwQueryValueKey(param_1,&local_18,1,lVar3,(undefined4)local_res10,&local_res10);
      uVar2 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        ExFreePoolWithTag(lVar3,0);
      }
      else {
        *param_3 = lVar3;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



===== FindInterruptTranslator @ 1c00074b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FindInterruptTranslator(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_res10[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  uVar2 = 0xc00000bb;
  if (*(longlong *)(lVar1 + 0x20) == 2) {
    IoGetDeviceProperty(*(undefined8 *)(param_1 + 0x48),0xd,4,local_res20,local_res18);
    IoGetDeviceProperty(*(undefined8 *)(param_1 + 0x48),0xe,4,local_res10,local_res18);
    uVar2 = (**(code **)(HalDispatchTable_exref + 0x78))
                      (local_res20[0],local_res10[0],1,*(undefined2 *)(lVar1 + 0x10),
                       *(undefined2 *)(lVar1 + 0x12),*(undefined8 *)(lVar1 + 0x18),local_res10);
  }
  return uVar2;
}



===== PiCancelRemoveStopFdo @ 1c0007590 =====

undefined8 PiCancelRemoveStopFdo(longlong param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 0x40);
  PiDeferProcessingFdo((longlong)puVar1,param_2);
  KeWaitForSingleObject(&IsaBusNumberLock,0,0,0,0);
  if ((*puVar1 & 0x20) != 0) {
    ActiveIsaCount = ActiveIsaCount + 1;
  }
  *puVar1 = *puVar1 & 0xffffffdf;
  KeSetEvent(&IsaBusNumberLock,0,0);
  PipCompleteRequest(param_2,0);
  return 0;
}



===== PiDeferProcessingFdo @ 1c0007614 =====

ulonglong PiDeferProcessingFdo(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,0,0);
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
  *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
  *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar2 + -0x10) = PiPnPFdoCompletion;
  *(undefined8 **)(lVar2 + -8) = &local_28;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  uVar3 = IofCallDriver(*(undefined8 *)(param_1 + 0x58),param_2);
  if ((int)uVar3 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  return uVar3;
}



===== PiQueryDeviceRelationsFdo @ 1c00076f0 =====

undefined8 PiQueryDeviceRelationsFdo(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  if ((*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) &&
     (*(int *)(*(longlong *)(param_1 + 0x40) + 0x60) == 0)) {
    puVar1 = (undefined4 *)ExAllocatePool2(0x100,0x10,0x706e70);
    if (puVar1 == (undefined4 *)0x0) {
      PipCompleteRequest(param_2,0xc000009a);
      return 0xc000009a;
    }
    *puVar1 = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined4 **)(param_2 + 0x38) = puVar1;
  }
  uVar2 = PipPassIrp(param_1,param_2);
  return uVar2;
}



===== PiQueryInterfaceFdo @ 1c0007780 =====

ulonglong PiQueryInterfaceFdo(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  
  plVar1 = *(longlong **)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((*plVar1 == 0x11d0aacf6c154a92) && (plVar1[1] == 0x44b206c9a0002a8d)) {
    uVar3 = FindInterruptTranslator(*(longlong *)(param_1 + 0x40),param_2);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) {
      if (iVar2 != -0x3fffff45) {
        PipCompleteRequest(param_2,iVar2);
        return uVar3 & 0xffffffff;
      }
    }
    else {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(int *)(param_2 + 0x30) = iVar2;
    }
  }
  uVar3 = PipPassIrp(param_1,param_2);
  return uVar3;
}



===== PiQueryLegacyBusInformationFdo @ 1c0007810 =====

undefined8 PiQueryLegacyBusInformationFdo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar2 = (undefined8 *)ExAllocatePool2(0x100,0x18,0x706e70);
  if (puVar2 == (undefined8 *)0x0) {
    PipCompleteRequest(param_2,0xc000009a);
    uVar3 = 0xc000009a;
  }
  else {
    *(undefined4 *)(puVar2 + 2) = 1;
    *puVar2 = 0x11d0d87de676f854;
    puVar2[1] = 0xc55f05c9a000b292;
    *(undefined4 *)((longlong)puVar2 + 0x14) = *(undefined4 *)(lVar1 + 0x60);
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 **)(param_2 + 0x38) = puVar2;
    uVar3 = PipPassIrp(param_1,param_2);
  }
  return uVar3;
}



===== PiQueryPnpDeviceState @ 1c00078a0 =====

void PiQueryPnpDeviceState(longlong param_1,longlong param_2)

{
  *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 0x20;
  *(undefined4 *)(param_2 + 0x30) = 0;
  PipPassIrp(param_1,param_2);
  return;
}



===== PiQueryRemoveStopFdo @ 1c00078c0 =====

int PiQueryRemoveStopFdo(longlong param_1,longlong param_2)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = *(uint **)(param_1 + 0x40);
  KeWaitForSingleObject(&IsaBusNumberLock,0,0,0,0);
  if (puVar1[0x18] == 0) {
    iVar2 = -0x3fffffff;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
    IofCompleteRequest(param_2,0);
  }
  else {
    ActiveIsaCount = ActiveIsaCount + -1;
    iVar2 = 0;
    *puVar1 = *puVar1 | 0x20;
  }
  KeSetEvent(&IsaBusNumberLock,0,0);
  if (-1 < iVar2) {
    *(undefined4 *)(param_2 + 0x30) = 0;
    iVar2 = PipPassIrp(param_1,param_2);
  }
  return iVar2;
}



===== PiRemoveFdo @ 1c0007980 =====

undefined4 PiRemoveFdo(longlong param_1,longlong param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  puVar1 = *(uint **)(param_1 + 0x40);
  KeWaitForSingleObject(&IsaBusNumberLock,0,0,0,0);
  if ((*puVar1 & 0x40) == 0) {
    RtlClearBits(BusNumBM,puVar1[0x18],1);
  }
  puVar3 = PipBusExtension;
  for (puVar4 = PipBusExtension; (uint *)puVar4[1] != puVar1; puVar4 = (undefined8 *)*puVar4) {
    puVar3 = puVar4;
  }
  if (puVar3 == puVar4) {
    PipBusExtension = (undefined8 *)*puVar4;
  }
  else {
    *puVar3 = (undefined8 *)*puVar4;
  }
  ExFreePoolWithTag(puVar4,0);
  KeSetEvent(&IsaBusNumberLock,0,0);
  IoDetachDevice(*(undefined8 *)(puVar1 + 0x16));
  *(undefined4 *)(param_2 + 0x30) = 0;
  uVar2 = PipPassIrp(param_1,param_2);
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  *puVar1 = *puVar1 | 1;
  puVar1[0x1a] = 4;
  IoDeleteDevice(*(undefined8 *)(puVar1 + 0x14));
  return uVar2;
}



===== PiStartFdo @ 1c0007a90 =====

ulonglong PiStartFdo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = PiDeferProcessingFdo(lVar1,param_2);
  if (-1 < (int)uVar2) {
    *(undefined4 *)(lVar1 + 100) = 1;
    *(undefined4 *)(lVar1 + 0x68) = 1;
  }
  IofCompleteRequest(param_2,0);
  return uVar2 & 0xffffffff;
}



===== PiStopFdo @ 1c0007af0 =====

void PiStopFdo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  KeWaitForSingleObject(&IsaBusNumberLock,0,0,0,0);
  RtlClearBits(BusNumBM,*(undefined4 *)(lVar1 + 0x60),1);
  KeSetEvent(&IsaBusNumberLock,0,0);
  *(undefined4 *)(lVar1 + 0x68) = 4;
  *(undefined4 *)(param_2 + 0x30) = 0;
  PipPassIrp(param_1,param_2);
  return;
}



===== PiSurpriseRemoveFdo @ 1c0007b90 =====

void PiSurpriseRemoveFdo(longlong param_1,longlong param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 0x40);
  KeWaitForSingleObject(&IsaBusNumberLock,0,0,0,0);
  RtlClearBits(BusNumBM,puVar1[0x18],1);
  KeSetEvent(&IsaBusNumberLock,0,0);
  *(undefined4 *)(param_2 + 0x30) = 0;
  PipPassIrp(param_1,param_2);
  *puVar1 = *puVar1 | 0x40;
  puVar1[0x1a] = 4;
  return;
}



===== entry @ 1c0008010 =====

void entry(longlong param_1,undefined2 *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0008044 =====

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



===== DriverEntry @ 1c0008078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1,undefined2 *param_2)

{
  undefined8 uVar1;
  
  *(code **)(param_1 + 0x68) = PiUnload;
  *(code **)(param_1 + 0x148) = PiDispatchPnp;
  *(code **)(param_1 + 0x120) = PiDispatchPower;
  *(code **)(param_1 + 0xe0) = PiDispatchDevCtl;
  *(code **)(param_1 + 0x128) = PiDispatchDevCtl;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = PiAddDevice;
  _PipRegistryPath = *param_2;
  _DAT_1c0004082 = param_2[1];
  DAT_1c0004088 = (void *)ExAllocatePool2(0x100,_DAT_1c0004082,0x706e70);
  if (DAT_1c0004088 == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memcpy(DAT_1c0004088,*(void **)(param_2 + 4),(ulonglong)(ushort)param_2[1]);
    KeInitializeEvent(&PipDeviceTreeLock,1,1);
    KeInitializeEvent(&IsaBusNumberLock,1,1);
    BusNumBM = &BusNumBMHeader;
    RtlInitializeBitMap(&BusNumBMHeader,&BusNumberBuffer,0x40);
    RtlClearAllBits(BusNumBM);
    uVar1 = 0;
  }
  return uVar1;
}


