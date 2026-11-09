
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



===== CompletePowerWait @ 1c0001020 =====

void CompletePowerWait(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  char cVar3;
  undefined7 extraout_var;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x10);
  LOCK();
  lVar4 = *(longlong *)(lVar1 + 0x228);
  *(longlong *)(lVar1 + 0x228) = 0;
  UNLOCK();
  if (lVar4 != 0) {
    cVar3 = HasIrpBeenCanceled(lVar4);
    if ((int)CONCAT71(extraout_var,cVar3) != 0) {
      lVar4 = 0;
    }
  }
  KeReleaseSpinLock(lVar1 + 0x10,uVar2);
  if (lVar4 != 0) {
    *(undefined8 *)(lVar4 + 0x38) = 0;
    RemoveReferenceAndCompleteRequest(param_1,lVar4,param_2);
  }
  return;
}



===== PowerIrpCompletion @ 1c00010d0 =====

undefined8 PowerIrpCompletion(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (-1 < *(int *)(param_2 + 0x30)) {
    lVar3 = *(longlong *)(param_2 + 0xb8);
    if ((*(int *)(lVar3 + 0x18) == 1) && (*(int *)(lVar2 + 0x260) != 1)) {
      CompletePowerWait(param_1,0);
    }
    *(undefined4 *)(lVar2 + 0x260) = *(undefined4 *)(lVar3 + 0x18);
  }
  RemoveReference(param_1);
  if ((*(char *)(param_2 + 0x41) != '\0') &&
     (*(char *)(param_2 + 0x43) <= *(char *)(param_2 + 0x42))) {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  return 0;
}



===== ForwardIrp @ 1c0001168 =====

void ForwardIrp(undefined8 param_1,longlong param_2)

{
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver();
  return;
}



===== HasIrpBeenCanceled @ 1c0001190 =====

char HasIrpBeenCanceled(longlong param_1)

{
  char cVar1;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  IoAcquireCancelSpinLock(local_res8);
  cVar1 = *(char *)(param_1 + 0x44);
  if (cVar1 != '\0') {
    *(undefined4 *)(param_1 + 0x30) = 0xc0000120;
  }
  LOCK();
  *(undefined8 *)(param_1 + 0x68) = 0;
  UNLOCK();
  IoReleaseCancelSpinLock(local_res8[0]);
  return cVar1;
}



===== IoCompletionSetEvent @ 1c0001200 =====

undefined8 IoCompletionSetEvent(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== UniLogError @ 1c000122c =====

void UniLogError(longlong param_1,longlong param_2)

{
  undefined2 *puVar1;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000038;
  undefined4 in_stack_00000040;
  
  if (param_2 == 0) {
    param_2 = param_1;
  }
  puVar1 = (undefined2 *)IoAllocateErrorLogEntry(param_2,0x30);
  if (puVar1 != (undefined2 *)0x0) {
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 6) = in_stack_00000040;
    *(undefined4 *)(puVar1 + 8) = in_stack_00000030;
    *(undefined4 *)(puVar1 + 10) = in_stack_00000038;
    IoWriteErrorLogEntry();
  }
  return;
}



===== GetDleCancelRoutine @ 1c0001290 =====

void GetDleCancelRoutine(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x10);
  if (*(longlong *)(lVar1 + 0x2b0) == param_2) {
    *(undefined8 *)(lVar1 + 0x2b0) = 0;
  }
  KeReleaseSpinLock(lVar1 + 0x10,uVar2);
  *(undefined8 *)(param_2 + 0x38) = 0;
  RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000120);
  return;
}



===== UniStopReceiveComplete @ 1c0001330 =====

undefined8 UniStopReceiveComplete(longlong param_1)

{
  KeInsertQueueDpc(*(longlong *)(param_1 + 0x40) + 0x2b8);
  return 0xc0000016;
}



===== SetPowerCompletion @ 1c0001360 =====

void SetPowerCompletion(void)

{
  undefined4 *in_R9;
  undefined4 *in_stack_00000028;
  
  *in_R9 = *in_stack_00000028;
  KeSetEvent(in_R9 + 2,0,0);
  return;
}



===== InitIrpQueue @ 1c0001390 =====

void InitIrpQueue(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  *(undefined8 *)(param_1 + 0x18) = 0;
  lVar1 = param_1 + 8;
  *(longlong *)(param_1 + 0x10) = lVar1;
  *(longlong *)lVar1 = lVar1;
  KeInitializeSpinLock();
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x20) = param_2;
  *(undefined8 *)(param_1 + 0x30) = param_3;
  return;
}



===== MarkQueueToEmpty @ 1c00013e8 =====

void MarkQueueToEmpty(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  if ((*(longlong *)(param_1 + 0x18) != 0) ||
     (*(longlong **)(param_1 + 8) != (longlong *)(param_1 + 8))) {
    *(undefined4 *)(param_1 + 0x38) = 1;
  }
  KeReleaseSpinLock(param_1,uVar1);
  return;
}



===== CheckStateAndAddReference @ 1c0001434 =====

undefined8 CheckStateAndAddReference(longlong param_1,longlong param_2)

{
  int *piVar1;
  char *pcVar2;
  
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 0x204f4446) {
    if (piVar1[0x10] != 0) {
      if (*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) != 0) {
        LOCK();
        piVar1[0xf] = piVar1[0xf] + 1;
        UNLOCK();
        if (*(char *)((longlong)piVar1 + 0x3a) == '\0') {
          LOCK();
          piVar1[0xf] = piVar1[0xf] + 1;
          UNLOCK();
          return 0;
        }
        RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000001);
        return 0xc0000001;
      }
      goto LAB_1c00014a7;
    }
    pcVar2 = "MODEM: CheckStateAndAddReference: Got IRP when not open!\n";
  }
  else {
    if (*piVar1 == 0x204f4450) goto LAB_1c00014a7;
    pcVar2 = "MODEM: CheckStateAndAddReference: Bad DevObj\n";
  }
  DbgPrint(pcVar2);
LAB_1c00014a7:
  *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
  IofCompleteRequest(param_2,0);
  return 0xc0000001;
}



===== CheckStateAndAddReferencePower @ 1c00014d4 =====

undefined8 CheckStateAndAddReferencePower(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  LOCK();
  *(int *)(lVar1 + 0x3c) = *(int *)(lVar1 + 0x3c) + 1;
  UNLOCK();
  if (*(char *)(lVar1 + 0x3a) == '\0') {
    LOCK();
    *(int *)(lVar1 + 0x3c) = *(int *)(lVar1 + 0x3c) + 1;
    UNLOCK();
    uVar2 = 0;
  }
  else {
    PoStartNextPowerIrp(param_2);
    RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000001);
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== CheckStateAndAddReferenceWMI @ 1c0001534 =====

undefined8 CheckStateAndAddReferenceWMI(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  LOCK();
  *(int *)(lVar1 + 0x3c) = *(int *)(lVar1 + 0x3c) + 1;
  UNLOCK();
  if (*(char *)(lVar1 + 0x3a) == '\0') {
    LOCK();
    *(int *)(lVar1 + 0x3c) = *(int *)(lVar1 + 0x3c) + 1;
    UNLOCK();
    uVar2 = 0;
  }
  else {
    RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000001);
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== RemoveReference @ 1c000156c =====

void RemoveReference(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x3c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(lVar3 + 0x208,0,0);
  }
  return;
}



===== RemoveReferenceAndCompleteRequest @ 1c00015a8 =====

void RemoveReferenceAndCompleteRequest(longlong param_1,longlong param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x3c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(lVar3 + 0x208,0,0);
  }
  *(undefined4 *)(param_2 + 0x30) = param_3;
  IofCompleteRequest(param_2,2);
  return;
}



===== _guard_check_icall @ 1c0001620 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0001638 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000165c =====

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



===== __cpu_features_init @ 1c00016d0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000173a) */
/* WARNING: Removing unreachable block (ram,0x0001c00016e9) */
/* WARNING: Removing unreachable block (ram,0x0001c00016da) */

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



===== __security_check_cookie @ 1c00017a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00017e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001810 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001840 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00018c0 =====

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



===== memset @ 1c0001bc0 =====

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



===== __memset_repmovs @ 1c0001d00 =====

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



===== __memset_query @ 1c0001d80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0001e00 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0001f40 =====

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



===== __memset_spec_plain @ 1c0001fc0 =====

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



===== CreateChildPdo @ 1c0008008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CreateChildPdo(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  int iVar3;
  code *pcVar4;
  undefined1 auStack_1b8 [32];
  undefined8 local_198;
  undefined1 local_190;
  longlong *local_188;
  undefined4 local_178 [2];
  longlong local_170 [3];
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined1 local_138 [8];
  undefined4 local_130;
  wchar_t *local_128;
  undefined8 *local_120;
  undefined4 local_118;
  undefined4 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  wchar_t *local_f0;
  undefined8 local_c8;
  undefined4 local_c0;
  wchar_t *local_b8;
  undefined1 *local_b0;
  undefined4 local_a8;
  undefined8 local_90;
  undefined4 local_88;
  wchar_t *local_80;
  undefined4 *local_78;
  undefined4 local_70;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_170[2] = 0;
  if ((*(longlong *)(param_1 + 8) == 0) && (*(char *)(param_1 + 0x3a) == '\0')) {
    iVar3 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x20),2,0x1f01ff,local_170 + 2);
    if (-1 < iVar3) {
      local_178[0] = 0;
      local_158 = 0;
      uStack_150 = 0;
      local_148 = 0;
      uStack_140 = 0;
      RtlInitUnicodeString(&local_158);
      local_158._0_4_ = CONCAT22(0x200,(undefined2)local_158);
      memset(local_138,0,0x118);
      lVar2 = local_170[2];
      local_128 = L"PermanentGuid";
      local_120 = &local_148;
      local_130 = 0x124;
      local_118 = 0x3000000;
      local_f0 = L"WaveDriver";
      local_108 = 0;
      local_b8 = L"WaveHardwareID";
      local_b0 = (undefined1 *)&local_158;
      local_80 = L"DuplexSupport";
      local_78 = local_178;
      local_148 = CONCAT44(local_148._4_4_,0xfffffff0);
      local_100 = 0;
      local_f8 = 1;
      local_c8 = 0;
      local_c0 = 0x134;
      local_a8 = 0x1000000;
      local_90 = 0;
      local_88 = 0x130;
      local_70 = 0x4000004;
      local_170[0] = 0;
      local_170[1] = 0;
      RtlInitUnicodeString(local_170,L"RtlQueryRegistryValuesEx");
      pcVar4 = (code *)MmGetSystemRoutineAddress(local_170);
      local_198 = 0;
      if (pcVar4 == (code *)0x0) {
        pcVar4 = RtlQueryRegistryValues_exref;
      }
      iVar3 = (*pcVar4)(0x40000000,lVar2,local_138,0);
      if (-1 < iVar3) {
        local_188 = local_170;
        local_170[0] = 0;
        local_190 = 0;
        local_198 = CONCAT44(local_198._4_4_,0x80);
        iVar3 = IoCreateDevice(*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8),0x40,0,0x2a);
        if (-1 < iVar3) {
          puVar1 = *(undefined4 **)(local_170[0] + 0x40);
          *puVar1 = 0x204f4450;
          *(undefined8 *)(puVar1 + 4) = *(undefined8 *)(param_1 + 0x18);
          *(undefined8 *)(puVar1 + 2) = *(undefined8 *)(param_1 + 0x20);
          *(undefined1 *)(puVar1 + 0xf) = 0;
          *(undefined8 *)(puVar1 + 6) = local_158;
          *(undefined8 *)(puVar1 + 8) = uStack_150;
          puVar1[10] = local_178[0];
          *(undefined8 *)(puVar1 + 0xb) = local_148;
          *(undefined8 *)(puVar1 + 0xd) = uStack_140;
          *(longlong *)(param_1 + 8) = local_170[0];
          *(uint *)(local_170[0] + 0x30) = *(uint *)(local_170[0] + 0x30) | 0x2000;
          *(uint *)(local_170[0] + 0x30) = *(uint *)(local_170[0] + 0x30) & 0xffffff7f;
          ModemCreateWaveDriverRegValue(*(undefined8 *)(param_1 + 0x20),0);
        }
      }
      ZwClose(local_170[2]);
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



===== ModemCreateWaveDriverRegValue @ 1c000829c =====

int ModemCreateWaveDriverRegValue(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_res10 [2];
  undefined8 local_res18 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  local_res10[0] = param_2;
  iVar1 = ModemGetVolatileWaveKey(param_1,local_res18);
  if (-1 < iVar1) {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"Started");
    iVar1 = ZwSetValueKey(local_res18[0],&local_18,0,4,local_res10,4);
    ZwClose(local_res18[0]);
  }
  return iVar1;
}



===== ModemGetVolatileWaveKey @ 1c000832c =====

int ModemGetVolatileWaveKey(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined4 local_res10 [2];
  undefined8 local_res18;
  undefined8 local_res20;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  
  *param_2 = 0;
  local_res20 = 0;
  iVar1 = IoOpenDeviceRegistryKey(param_1,2,0x1f01ff,&local_res20);
  if (-1 < iVar1) {
    local_34 = 0;
    local_res18 = 0;
    local_4c = 0;
    local_60 = 0;
    uStack_58 = 0;
    RtlInitUnicodeString(&local_60,L"WaveDriver");
    local_48 = local_res20;
    local_40 = &local_60;
    local_50 = 0x30;
    local_38 = 0x240;
    local_30 = 0;
    uStack_28 = 0;
    iVar1 = ZwOpenKey(&local_res18,0x1f01ff,&local_50);
    if (-1 < iVar1) {
      local_res10[0] = 0;
      local_68 = 0;
      RtlInitUnicodeString(&local_60,L"Enumerated");
      local_48 = local_res18;
      local_40 = &local_60;
      local_50 = 0x30;
      local_38 = 0x240;
      local_30 = 0;
      uStack_28 = 0;
      iVar1 = ZwCreateKey(&local_68,2,&local_50,0,0,1,local_res10);
      if (-1 < iVar1) {
        *param_2 = local_68;
      }
      ZwClose(local_res18);
    }
    ZwClose(local_res20);
  }
  return iVar1;
}



===== ModemPdoPnp @ 1c000849c =====

uint ModemPdoPnp(longlong param_1,longlong param_2)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  uint uVar6;
  wchar_t *pwVar7;
  undefined4 *puVar8;
  longlong lVar9;
  uint local_res8 [2];
  ulonglong local_38;
  void *pvStack_30;
  
  lVar9 = *(longlong *)(param_2 + 0xb8);
  puVar8 = *(undefined4 **)(param_1 + 0x40);
  uVar6 = *(uint *)(param_2 + 0x30);
  bVar1 = *(byte *)(lVar9 + 1);
  if (0x13 < bVar1) {
    if (bVar1 == 0x17) {
      uVar6 = 0;
    }
    goto LAB_1c00089ab;
  }
  if (bVar1 == 0x13) {
    iVar2 = *(int *)(lVar9 + 8);
    if (iVar2 != 0) {
      if (iVar2 == 1) {
        pwVar7 = (wchar_t *)
                 ExAllocatePool2(0x100,(ulonglong)*(ushort *)(puVar8 + 6) + 0x1a,0x4d444d55);
        if (pwVar7 == (wchar_t *)0x0) {
          uVar6 = 0xc000009a;
        }
        else {
          uVar6 = 0;
          builtin_wcsncpy(pwVar7,L"MODEMWAVE\\",10);
          memcpy(pwVar7 + 10,*(void **)(puVar8 + 8),(ulonglong)*(ushort *)(puVar8 + 6));
        }
      }
      else {
        if (iVar2 == 2) {
          lVar9 = ExAllocatePool2(0x100,4,0x4d444d55);
          *(longlong *)(param_2 + 0x38) = lVar9;
          uVar6 = ~-(uint)(lVar9 != 0) & 0xc000009a;
          goto LAB_1c00089ab;
        }
        if (iVar2 != 3) goto LAB_1c00089ab;
        pwVar7 = (wchar_t *)0x0;
        local_38 = 0;
        pvStack_30 = (void *)0x0;
        uVar6 = RtlStringFromGUID(puVar8 + 0xb,&local_38);
        if (-1 < (int)uVar6) {
          pwVar7 = (wchar_t *)ExAllocatePool2(0x100,(local_38 & 0xffff) + 2,0x4d444d55);
          if (pwVar7 == (wchar_t *)0x0) {
            uVar6 = 0xc0000017;
          }
          else {
            memcpy(pwVar7,pvStack_30,local_38 & 0xffff);
          }
          RtlFreeUnicodeString(&local_38);
        }
      }
      *(wchar_t **)(param_2 + 0x38) = pwVar7;
      goto LAB_1c00089ab;
    }
    pwVar7 = (wchar_t *)ExAllocatePool2(0x100,0x18,0x4d444d55);
    if (pwVar7 == (wchar_t *)0x0) {
      uVar6 = 0xc000009a;
    }
    else {
      builtin_wcsncpy(pwVar7,L"MODEMWAVE\\0",0xc);
LAB_1c0008797:
      uVar6 = 0;
    }
    *(wchar_t **)(param_2 + 0x38) = pwVar7;
    goto LAB_1c00089ab;
  }
  if (bVar1 < 6) {
    if (bVar1 != 5) {
      if (bVar1 == 0) {
        ModemCreateWaveDriverRegValue
                  (*(undefined8 *)(*(longlong *)(*(longlong *)(puVar8 + 4) + 0x40) + 0x20),1);
      }
      else if (bVar1 != 1) {
        if (bVar1 == 2) {
          lVar3 = *(longlong *)(*(longlong *)(puVar8 + 4) + 0x40);
          KeEnterCriticalRegion();
          lVar9 = lVar3 + 0x1a0;
          ExAcquireResourceExclusiveLite(lVar9);
          if ((*(char *)((longlong)puVar8 + 0x3d) == '\0') &&
             (ModemCreateWaveDriverRegValue(*(undefined8 *)(lVar3 + 0x20),0),
             *(char *)(puVar8 + 0xf) != '\0')) {
            *puVar8 = 0x4f445078;
            RtlFreeUnicodeString(puVar8 + 6);
            *(undefined1 *)((longlong)puVar8 + 0x3d) = 1;
            IoDeleteDevice(param_1);
          }
          uVar6 = 0;
          ExReleaseResourceLite(lVar9);
          KeLeaveCriticalRegion();
          goto LAB_1c00089ab;
        }
        if ((bVar1 != 3) && (bVar1 != 4)) goto LAB_1c00089ab;
      }
    }
  }
  else if (bVar1 != 6) {
    if (bVar1 == 7) {
      if (*(int *)(lVar9 + 8) != 4) goto LAB_1c00089ab;
      puVar8 = (undefined4 *)ExAllocatePool2(0x100,0x10,0x4d444d55);
      if (puVar8 == (undefined4 *)0x0) goto LAB_1c00087a2;
      ObfReferenceObject(param_1);
      *(longlong *)(puVar8 + 2) = param_1;
      *puVar8 = 1;
      *(undefined4 **)(param_2 + 0x38) = puVar8;
    }
    else if (bVar1 == 9) {
      puVar8 = *(undefined4 **)(lVar9 + 8);
      *puVar8 = 0x10040;
      *(undefined8 *)(puVar8 + 0xb) = 0;
      puVar8[1] = puVar8[1] & 0xffffffd3 | 0x240;
      *(undefined8 *)(puVar8 + 0xd) = 0;
      puVar8[0xf] = 0;
    }
    else {
      if (bVar1 == 0xc) {
        if (*(int *)(lVar9 + 8) != 0) goto LAB_1c00089ab;
        pwVar7 = (wchar_t *)ExAllocatePool2(0x100,0x26,0x4d444d55);
        if (pwVar7 != (wchar_t *)0x0) {
          builtin_wcsncpy(pwVar7,L"Modem Audio Device",0x13);
          goto LAB_1c0008797;
        }
LAB_1c00087a2:
        uVar6 = 0xc000009a;
        goto LAB_1c00089ab;
      }
      if (bVar1 != 0xf) goto LAB_1c00089ab;
      iVar2 = *(int *)(lVar9 + 8);
      if (iVar2 == 0) {
        if (0xf < *(uint *)(lVar9 + 0x20)) {
          puVar4 = *(undefined8 **)(lVar9 + 0x10);
          uVar6 = 0;
          uVar5 = *(undefined8 *)(puVar8 + 0xd);
          *puVar4 = *(undefined8 *)(puVar8 + 0xb);
          puVar4[1] = uVar5;
          *(undefined8 *)(param_2 + 0x38) = 0x10;
          goto LAB_1c00089ab;
        }
LAB_1c000873a:
        uVar6 = 0xc0000023;
        goto LAB_1c00089ab;
      }
      if (iVar2 == 1) {
        local_res8[0] = 0;
        if (*(uint *)(lVar9 + 0x20) < 4) goto LAB_1c000873a;
        uVar6 = IoGetDeviceProperty(*(undefined8 *)(puVar8 + 2),0xb,0,0,local_res8);
        if (uVar6 != 0xc0000023) goto LAB_1c00089ab;
        **(int **)(lVar9 + 0x10) = local_res8[0] + 0xc;
        *(undefined8 *)(param_2 + 0x38) = 4;
      }
      else {
        if (iVar2 == 2) {
          local_res8[0] = 0;
          if ((0xc < *(uint *)(lVar9 + 0x20)) &&
             (uVar6 = IoGetDeviceProperty(*(undefined8 *)(puVar8 + 2),0xb,
                                          *(uint *)(lVar9 + 0x20) - 0xc,
                                          *(undefined8 *)(lVar9 + 0x10),local_res8), uVar6 == 0)) {
            lVar9 = *(longlong *)(lVar9 + 0x10);
            *(undefined8 *)(((ulonglong)local_res8[0] - 2) + lVar9) = 0x7600610057005c;
            *(undefined4 *)((ulonglong)local_res8[0] + 6 + lVar9) = 0x65;
            *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res8[0] + 10;
          }
          goto LAB_1c00089ab;
        }
        if (iVar2 != 3) goto LAB_1c00089ab;
        if (*(uint *)(lVar9 + 0x20) < 4) goto LAB_1c000873a;
        **(undefined4 **)(lVar9 + 0x10) = puVar8[10];
        *(undefined8 *)(param_2 + 0x38) = 4;
      }
    }
  }
  uVar6 = 0;
LAB_1c00089ab:
  *(uint *)(param_2 + 0x30) = uVar6;
  IofCompleteRequest(param_2,0);
  return uVar6;
}



===== ModemPower @ 1c00089f0 =====

ulonglong ModemPower(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  int *local_res8;
  
  local_res8 = *(int **)(param_1 + 0x40);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*local_res8 == 0x204f4450) {
    PoStartNextPowerIrp(param_2);
    if ((byte)(*(char *)(lVar1 + 1) - 2U) < 2) {
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    uVar3 = *(uint *)(param_2 + 0x30);
    IofCompleteRequest(param_2,0);
    goto LAB_1c0008b32;
  }
  uVar4 = CheckStateAndAddReferencePower(param_1,param_2);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  if (*(char *)(lVar1 + 1) == '\x02') {
    if (*(int *)(lVar1 + 0x10) == 0) goto LAB_1c0008a78;
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
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar1 + -0x10) = PowerIrpCompletion;
    *(int ***)(lVar1 + -8) = &local_res8;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    PoStartNextPowerIrp(param_2);
    uVar3 = PoCallDriver(*(undefined8 *)(local_res8 + 10),param_2);
  }
  else {
    if (*(char *)(lVar1 + 1) == '\x03') {
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
LAB_1c0008a78:
    PoStartNextPowerIrp(param_2);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = PoCallDriver(*(undefined8 *)(local_res8 + 10),param_2);
    RemoveReference(param_1);
  }
  RemoveReference(param_1);
LAB_1c0008b32:
  return (ulonglong)uVar3;
}



===== ModemAddDevice @ 1c0008b50 =====

int ModemAddDevice(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  uint local_res18 [2];
  longlong local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  uVar8 = 0;
  iVar3 = IoCreateDevice();
  if (iVar3 < 0) {
    UniLogError(param_1,0);
  }
  else {
    *(undefined4 *)(param_2 + 0x48) = 0x2b;
    lVar6 = param_2;
    lVar4 = IoAttachDeviceToDeviceStack(local_res20);
    uVar7 = (undefined4)lVar6;
    if (lVar4 == 0) {
      UniLogError(param_1,0);
      iVar3 = -0x3fffff66;
    }
    else {
      *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 0x2004;
      puVar2 = *(undefined4 **)(local_res20 + 0x40);
      *puVar2 = 0x204f4446;
      *(longlong *)(puVar2 + 6) = local_res20;
      *(longlong *)(puVar2 + 8) = param_2;
      *(longlong *)(puVar2 + 10) = lVar4;
      iVar3 = ExInitializeResourceLite(puVar2 + 0x68);
      if (iVar3 == 0) {
        *(undefined1 *)(puVar2 + 0xe) = 0;
        puVar2[0xf] = 1;
        *(undefined1 *)((longlong)puVar2 + 0x3a) = 0;
        *(undefined1 *)(puVar2 + 0x104) = 0;
        *(undefined1 *)((longlong)puVar2 + 0x2ae) = 0;
        iVar3 = ModemGetRegistryKeyValue(param_2,uVar7,uVar8,local_res18);
        if (iVar3 < 0) {
          local_res18[0] = (uint)(*(char *)((longlong)puVar2 + 0x2ae) != '\0');
          ModemSetRegistryKeyValue();
        }
        else if (local_res18[0] != 0) {
          *(undefined1 *)((longlong)puVar2 + 0x2ae) = 1;
        }
        KeInitializeEvent(puVar2 + 0x82,0,0);
        KeInitializeSpinLock(puVar2 + 4);
        puVar1 = puVar2 + 0x16;
        *(undefined4 **)(puVar2 + 0x18) = puVar1;
        *(undefined4 **)puVar1 = puVar1;
        puVar1 = puVar2 + 0x22;
        *(undefined4 **)(puVar2 + 0x24) = puVar1;
        *(undefined4 **)puVar1 = puVar1;
        puVar1 = puVar2 + 0xc2;
        *(undefined4 **)(puVar2 + 0xc4) = puVar1;
        *(undefined4 **)puVar1 = puVar1;
        puVar1 = puVar2 + 0xc6;
        *(undefined4 **)(puVar2 + 200) = puVar1;
        *(undefined4 **)puVar1 = puVar1;
        puVar1 = puVar2 + 0xcc;
        *(undefined4 **)(puVar2 + 0xce) = puVar1;
        *(undefined4 **)puVar1 = puVar1;
        puVar1 = puVar2 + 0xd0;
        *(undefined4 **)(puVar2 + 0xd2) = puVar1;
        *(undefined4 **)puVar1 = puVar1;
        InitIrpQueue((longlong)(puVar2 + 0xd4),local_res20,WriteIrpStarter);
        InitIrpQueue((longlong)(puVar2 + 0xec),local_res20,ReadIrpStarter);
        KeInitializeDpc(puVar2 + 0xae,WaveStopDpcHandler,puVar2);
        lVar6 = 2;
        puVar5 = (undefined8 *)(puVar2 + 0x2a);
        do {
          *puVar5 = puVar2;
          puVar5 = puVar5 + 7;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
        *(undefined4 **)(puVar2 + 0x3a) = puVar2 + 0x2a;
        *(undefined4 **)(puVar2 + 0x2c) = puVar2 + 0x38;
        iVar3 = ModemHandleSymbolicLink(param_2,(longlong)(puVar2 + 0x12),1);
        if (iVar3 < 0) {
          UniLogError(param_1,local_res20);
          IoDetachDevice(lVar4);
          ExDeleteResourceLite(puVar2 + 0x68);
          IoDeleteDevice(local_res20);
        }
        else {
          *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) & 0xffffff7f;
          IoWMIRegistrationControl(local_res20,1);
        }
        goto LAB_1c0008e5c;
      }
      IoDetachDevice(lVar4);
    }
    IoDeleteDevice(local_res20);
  }
LAB_1c0008e5c:
  return iVar3;
}



===== ModemGetRegistryKeyValue @ 1c0008e7c =====

int ModemGetRegistryKeyValue(undefined8 param_1,undefined4 param_2,undefined8 param_3,void *param_4)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_res10 [2];
  undefined8 local_res18;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_res10[0] = param_2;
  iVar1 = IoOpenDeviceRegistryKey(0,1,0x20000,&local_res18);
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_18,L"WakeOnRing");
    local_res10[0] = 0x1c;
    lVar2 = ExAllocatePool2(0x100,0x1c,0x4d444d55);
    if (lVar2 != 0) {
      iVar1 = ZwQueryValueKey(local_res18,&local_18,2,lVar2,local_res10[0],local_res10);
      if ((-1 < iVar1) && (*(uint *)(lVar2 + 8) < 5)) {
        memcpy(param_4,(void *)(lVar2 + 0xc),(ulonglong)*(uint *)(lVar2 + 8));
      }
      ExFreePoolWithTag(lVar2,0);
    }
    ZwClose(local_res18);
  }
  return iVar1;
}



===== ModemHandleSymbolicLink @ 1c0008f90 =====

int ModemHandleSymbolicLink(undefined8 param_1,longlong param_2,int param_3)

{
  int iVar1;
  undefined4 local_res20 [2];
  undefined8 local_38;
  longlong local_30;
  undefined8 local_28;
  longlong lStack_20;
  
  local_38 = 0x2000000;
  local_res20[0] = 0;
  local_30 = ExAllocatePool2(0x100,0x202,0x4d444d55);
  if (local_30 == 0) {
    return -0x3fffff66;
  }
  RtlAppendUnicodeToString(&local_38,L"\\DosDevices\\");
  iVar1 = IoGetDeviceProperty(param_1,9,(uint)local_38._2_2_ - (uint)(ushort)local_38,
                              local_30 + (ulonglong)((ushort)local_38 >> 1) * 2,local_res20);
  if (-1 < iVar1) {
    local_38 = CONCAT62(local_38._2_6_,(ushort)local_38 + (short)local_res20[0] + -2);
    if (param_3 == 0) {
      if (*(longlong *)(param_2 + 8) != 0) {
        IoSetDeviceInterfaceState(param_2,0);
        RtlFreeUnicodeString(param_2);
      }
      iVar1 = IoDeleteSymbolicLink(&local_38);
    }
    else {
      lStack_20 = 0;
      local_28 = 0x2000000;
      lStack_20 = ExAllocatePool2(0x100,0x202,0x4d444d55);
      if (lStack_20 == 0) {
        iVar1 = -0x3fffff66;
      }
      else {
        iVar1 = IoGetDeviceProperty(param_1,0xb,local_28._2_2_,lStack_20,local_res20);
        if (-1 < iVar1) {
          local_28 = CONCAT62(local_28._2_6_,(short)local_28 + (short)local_res20[0] + -2);
          IoCreateSymbolicLink(&local_38,&local_28);
          ExFreePoolWithTag(lStack_20,0);
          lStack_20 = 0;
          iVar1 = IoRegisterDeviceInterface(param_1,&GUID_DEVINTERFACE_MODEM,0,param_2);
          if (-1 < iVar1) {
            IoSetDeviceInterfaceState(param_2,1);
          }
        }
      }
    }
  }
  ExFreePoolWithTag(local_30,0);
  return iVar1;
}



===== ModemPnP @ 1c00091b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint ModemPnP(longlong param_1,longlong param_2)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  int *piVar4;
  undefined8 *puVar5;
  uint *_Src;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint *_Dst;
  undefined8 uVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  uint uVar13;
  ulonglong uVar14;
  uint uVar15;
  bool bVar16;
  undefined1 auStack_288 [32];
  ulonglong *local_268;
  ulonglong local_258 [2];
  ushort local_248;
  ushort local_246;
  ushort local_244;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_288;
  piVar4 = *(int **)(param_1 + 0x40);
  iVar6 = *piVar4;
  if ((iVar6 == 0x204f4450) || (iVar6 == 0x4f445078)) {
    uVar7 = ModemPdoPnp(param_1,param_2);
    return uVar7;
  }
  if (iVar6 != 0x204f4446) {
    DbgPrint("MODEM: ModemPnp: Bad DevObj\n");
    uVar7 = 0;
LAB_1c00094cc:
    *(uint *)(param_2 + 0x30) = uVar7;
LAB_1c00094cf:
    IofCompleteRequest(param_2,0);
    return uVar7;
  }
  bVar3 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
  lVar12 = 5;
  if (bVar3 < 6) {
    if (bVar3 == 5) {
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(piVar4 + 0x68,1);
      if (piVar4[0x10] != 0) {
        ExReleaseResourceLite();
        KeLeaveCriticalRegion();
        uVar7 = 0xc0000001;
        goto LAB_1c00094cc;
      }
      *(char *)((longlong)piVar4 + 0x39) = (char)piVar4[0xe];
      *(undefined1 *)(piVar4 + 0xe) = 0;
      ExReleaseResourceLite(piVar4 + 0x68);
      KeLeaveCriticalRegion();
    }
    else {
      if (bVar3 == 0) {
        uVar7 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(piVar4 + 10),param_2,'\x01');
        if (-1 < (int)uVar7) {
          *(undefined1 *)(piVar4 + 0xe) = 1;
          KeEnterCriticalRegion();
          ExAcquireResourceExclusiveLite(piVar4 + 0x68,1);
          CreateChildPdo((longlong)piVar4);
          ExReleaseResourceLite(piVar4 + 0x68);
          KeLeaveCriticalRegion();
        }
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(uint *)(param_2 + 0x30) = uVar7;
        goto LAB_1c00094cf;
      }
      if (bVar3 != 1) {
        if (bVar3 == 2) {
          *(undefined2 *)((longlong)piVar4 + 0x3a) = 0x101;
          if ((char)piVar4[0x104] == '\0') {
            ModemHandleSymbolicLink(*(undefined8 *)(piVar4 + 8),(longlong)(piVar4 + 0x12),0);
          }
          local_258[0] = 0;
          iVar6 = ModemGetVolatileWaveKey(*(undefined8 *)(piVar4 + 8),local_258);
          if (-1 < iVar6) {
            ZwDeleteKey(local_258[0]);
          }
          MmLockPagableSectionByHandle(PagedCodeSectionHandle);
          KeEnterCriticalRegion();
          piVar2 = piVar4 + 0x68;
          ExAcquireResourceExclusiveLite(piVar2,1);
          CleanUpOnRemove(param_1,param_2);
          if (*(longlong *)(piVar4 + 2) != 0) {
            lVar12 = *(longlong *)(*(longlong *)(piVar4 + 2) + 0x40);
            *(undefined1 *)(lVar12 + 0x3c) = 1;
            if (*(char *)(lVar12 + 0x3d) == '\0') {
              *(undefined1 *)(lVar12 + 0x3d) = 1;
              IoDeleteDevice(*(undefined8 *)(piVar4 + 2));
              piVar4[2] = 0;
              piVar4[3] = 0;
            }
          }
          ExReleaseResourceLite(piVar2);
          KeLeaveCriticalRegion();
          MmUnlockPagableImageSection(PagedCodeSectionHandle);
          if ((char)piVar4[0x104] == '\0') {
            IoWMIRegistrationControl(param_1,2);
          }
          LOCK();
          piVar1 = piVar4 + 0xf;
          iVar6 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar6 != 1) {
            local_268 = (ulonglong *)0x0;
            KeWaitForSingleObject(piVar4 + 0x82,0,0,0);
          }
          puVar5 = *(undefined8 **)(param_2 + 0xb8);
          puVar5[-9] = *puVar5;
          puVar5[-8] = puVar5[1];
          puVar5[-7] = puVar5[2];
          puVar5[-6] = puVar5[3];
          puVar5[-5] = puVar5[4];
          puVar5[-4] = puVar5[5];
          puVar5[-3] = puVar5[6];
          *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
          uVar7 = IofCallDriver(*(undefined8 *)(piVar4 + 10),param_2);
          IoDetachDevice(*(undefined8 *)(piVar4 + 10));
          *piVar4 = 0x4f444678;
          ExDeleteResourceLite(piVar2);
          IoDeleteDevice(param_1);
          return uVar7;
        }
        if (bVar3 != 3) {
          if (bVar3 != 4) goto LAB_1c000950c;
          *(undefined1 *)(piVar4 + 0xe) = 0;
        }
      }
    }
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  else {
    if (bVar3 == 6) {
      uVar7 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(piVar4 + 10),param_2,'\x01');
      *(undefined1 *)(piVar4 + 0xe) = *(undefined1 *)((longlong)piVar4 + 0x39);
      *(uint *)(param_2 + 0x30) = uVar7;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      return uVar7;
    }
    if (bVar3 == 7) {
      uVar9 = *(undefined8 *)(piVar4 + 10);
      if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) {
        uVar7 = WaitForLowerDriverToCompleteIrp(uVar9,param_2,'\x01');
        if (((int)uVar7 < 0) || (_Src = *(uint **)(param_2 + 0x38), _Src == (uint *)0x0)) {
          _Dst = (uint *)ExAllocatePool2(0x100,0x10,0x4d444d55);
          if (_Dst == (uint *)0x0) {
            uVar7 = 0xc000009a;
            *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
            goto LAB_1c0009881;
          }
        }
        else {
          uVar14 = (ulonglong)*_Src * 8 + 0x10;
          if ((0xffffffff < uVar14) ||
             (_Dst = (uint *)ExAllocatePool2(0x100,uVar14,0x4d444d55), _Dst == (uint *)0x0))
          goto LAB_1c0009881;
          memcpy(_Dst,_Src,(ulonglong)*_Src * 8 + 8);
          ExFreePoolWithTag(_Src,0);
        }
        *(uint **)(param_2 + 0x38) = _Dst;
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(piVar4 + 0x68,1);
        if ((*(longlong *)(piVar4 + 2) != 0) &&
           (**(int **)(*(longlong *)(piVar4 + 2) + 0x40) == 0x204f4450)) {
          ObfReferenceObject();
          *(undefined8 *)(_Dst + (ulonglong)*_Dst * 2 + 2) = *(undefined8 *)(piVar4 + 2);
          *_Dst = *_Dst + 1;
        }
        ExReleaseResourceLite(piVar4 + 0x68);
        KeLeaveCriticalRegion();
        *(undefined4 *)(param_2 + 0x30) = 0;
        uVar7 = 0;
LAB_1c0009881:
        IofCompleteRequest(param_2,0);
        return uVar7;
      }
      goto LAB_1c0009513;
    }
    if (bVar3 == 9) {
      uVar7 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(piVar4 + 10),param_2,'\x01');
      *(undefined1 *)(piVar4 + 0x8e) = 1;
      lVar11 = 0x14;
      lVar10 = *(longlong *)(param_2 + 0xb8);
      piVar4[0x8f] = 4;
      piVar4[0x90] = 4;
      piVar4[0x91] = 4;
      piVar4[0x92] = 4;
      piVar4[0x93] = 4;
      piVar4[0x94] = 4;
      piVar4[0x95] = 4;
      do {
        *(undefined4 *)((longlong)piVar4 + lVar11 + 0x22c) =
             *(undefined4 *)(lVar11 + *(longlong *)(lVar10 + 8));
        lVar11 = lVar11 + 4;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      piVar4[0x90] = 1;
      piVar4[0x96] = *(int *)(*(longlong *)(lVar10 + 8) + 0x2c);
      piVar4[0x97] = *(int *)(*(longlong *)(lVar10 + 8) + 0x30);
      goto LAB_1c00094cf;
    }
    if (bVar3 == 0xd) {
      local_268 = local_258;
      local_258[0] = local_258[0] & 0xffffffff00000000;
      bVar16 = false;
      iVar6 = IoGetDeviceProperty(*(undefined8 *)(piVar4 + 8),0xf,0x208,&local_248);
      if (-1 < iVar6) {
        uVar7 = local_248 - 0x4d;
        if ((uVar7 == 0) && (uVar7 = local_246 - 0x46, uVar7 == 0)) {
          uVar7 = (uint)local_244;
        }
        bVar16 = uVar7 == 0;
      }
      uVar7 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(piVar4 + 10),param_2,'\x01');
      if (((-1 < (int)uVar7) && (!bVar16)) && (lVar12 = *(longlong *)(param_2 + 0x38), lVar12 != 0))
      {
        lVar11 = lVar12 + 0x20;
        uVar15 = 0;
        if (*(int *)(lVar12 + 0x1c) != 0) {
          do {
            uVar14 = 0;
            uVar8 = 0;
            if (*(int *)(lVar11 + 4) != 0) {
              do {
                lVar10 = uVar14 * 0x20;
                if (((*(char *)(lVar10 + 9 + lVar11) == '\x02') &&
                    (*(char *)(lVar10 + 10 + lVar11) == '\x03')) &&
                   ((*(byte *)(lVar10 + 0xc + lVar11) & 1) != 0)) {
                  *(undefined1 *)(lVar10 + 10 + lVar11) = 1;
                }
                uVar8 = *(uint *)(lVar11 + 4);
                uVar13 = (int)uVar14 + 1;
                uVar14 = (ulonglong)uVar13;
              } while (uVar13 < uVar8);
            }
            uVar15 = uVar15 + 1;
            lVar11 = lVar11 + 0x28 + (ulonglong)(uVar8 - 1) * 0x20;
          } while (uVar15 < *(uint *)(lVar12 + 0x1c));
        }
      }
      IofCompleteRequest(param_2,0);
      return uVar7;
    }
    if (bVar3 == 0x17) {
      *(undefined4 *)(param_2 + 0x30) = 0;
      *(undefined1 *)((longlong)piVar4 + 0x3a) = 1;
      *(undefined1 *)(piVar4 + 0x104) = 1;
      ModemHandleSymbolicLink(*(undefined8 *)(piVar4 + 8),(longlong)(piVar4 + 0x12),0);
      IoWMIRegistrationControl(param_1,2);
      if (*(longlong *)(piVar4 + 0x14) != 0) {
        IoSetDeviceInterfaceState(piVar4 + 0x12,0);
      }
      MmLockPagableSectionByHandle(PagedCodeSectionHandle);
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(piVar4 + 0x68,1);
      CleanUpOnRemove(param_1,param_2);
      ExReleaseResourceLite(piVar4 + 0x68);
      KeLeaveCriticalRegion();
      MmUnlockPagableImageSection(PagedCodeSectionHandle);
    }
  }
LAB_1c000950c:
  uVar9 = *(undefined8 *)(piVar4 + 10);
LAB_1c0009513:
  uVar7 = ForwardIrp(uVar9,param_2);
  return uVar7;
}



===== ModemSetRegistryKeyValue @ 1c0009938 =====

int ModemSetRegistryKeyValue(void)

{
  int iVar1;
  undefined8 local_res18 [2];
  undefined8 in_stack_00000028;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = IoOpenDeviceRegistryKey(0,1,0xf003f,local_res18);
  if (iVar1 < 0) {
    ZwClose(local_res18[0]);
  }
  else {
    RtlInitUnicodeString(&local_18,L"WakeOnRing");
    iVar1 = ZwSetValueKey(local_res18[0],&local_18,0,4,in_stack_00000028,4);
  }
  return iVar1;
}



===== QueryDeviceCaps @ 1c00099dc =====

undefined4 QueryDeviceCaps(longlong param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  while (lVar2 = lVar3, lVar2 != 0) {
    param_1 = lVar2;
    lVar3 = *(longlong *)(lVar2 + 0x18);
  }
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c));
  if (lVar3 == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    *(undefined8 *)(lVar3 + 0x38) = 0;
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    memset(param_2,0,0x40);
    *param_2 = 0x10040;
    param_2[2] = 0xffffffff;
    param_2[3] = 0xffffffff;
    lVar2 = *(longlong *)(lVar3 + 0xb8);
    *(undefined2 *)(lVar2 + -0x48) = 0x91b;
    *(undefined4 **)(lVar2 + -0x40) = param_2;
    uVar1 = WaitForLowerDriverToCompleteIrp(param_1,lVar3,'\0');
    IoFreeIrp(lVar3);
  }
  return uVar1;
}



===== UniUnload @ 1c0009aa0 =====

void UniUnload(void)

{
  ExFreePoolWithTag(DAT_1c0005118,0);
  DAT_1c0005118 = 0;
  return;
}



===== WaitForLowerDriverToCompleteIrp @ 1c0009ad0 =====

undefined4 WaitForLowerDriverToCompleteIrp(undefined8 param_1,longlong param_2,char param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,0,0);
  if (param_3 != '\0') {
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
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar2 + -0x10) = IoCompletionSetEvent;
  *(undefined8 **)(lVar2 + -8) = &local_28;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  iVar3 = IofCallDriver(param_1,param_2);
  if (iVar3 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  return *(undefined4 *)(param_2 + 0x30);
}



===== GetPropertiesHandler @ 1c0009bac =====

undefined4 GetPropertiesHandler(longlong param_1,longlong param_2)

{
  uint uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  longlong lVar4;
  ushort *puVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  longlong lVar13;
  uint uVar14;
  uint uVar15;
  void *_Dst;
  undefined4 local_res20 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  puVar5 = *(ushort **)(param_2 + 0x18);
  lVar6 = *(longlong *)(param_2 + 0xb8);
  puVar2 = puVar5 + 0x1e;
  iVar10 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(lVar4 + 0x28),param_2,'\x01');
  if (-1 < iVar10) {
    uVar9 = *(undefined8 *)(lVar4 + 0x120);
    *(undefined8 *)puVar2 = *(undefined8 *)(lVar4 + 0x118);
    *(undefined8 *)(puVar5 + 0x22) = uVar9;
    uVar9 = *(undefined8 *)(lVar4 + 0x130);
    *(undefined8 *)(puVar5 + 0x26) = *(undefined8 *)(lVar4 + 0x128);
    *(undefined8 *)(puVar5 + 0x2a) = uVar9;
    uVar9 = *(undefined8 *)(lVar4 + 0x140);
    *(undefined8 *)(puVar5 + 0x2e) = *(undefined8 *)(lVar4 + 0x138);
    *(undefined8 *)(puVar5 + 0x32) = uVar9;
    uVar3 = *(undefined4 *)(lVar4 + 0x14c);
    uVar7 = *(undefined4 *)(lVar4 + 0x150);
    uVar8 = *(undefined4 *)(lVar4 + 0x154);
    *(undefined4 *)(puVar5 + 0x36) = *(undefined4 *)(lVar4 + 0x148);
    *(undefined4 *)(puVar5 + 0x38) = uVar3;
    *(undefined4 *)(puVar5 + 0x3a) = uVar7;
    *(undefined4 *)(puVar5 + 0x3c) = uVar8;
    uVar3 = *(undefined4 *)(lVar4 + 0x15c);
    uVar7 = *(undefined4 *)(lVar4 + 0x160);
    uVar8 = *(undefined4 *)(lVar4 + 0x164);
    *(undefined4 *)(puVar5 + 0x3e) = *(undefined4 *)(lVar4 + 0x158);
    *(undefined4 *)(puVar5 + 0x40) = uVar3;
    *(undefined4 *)(puVar5 + 0x42) = uVar7;
    *(undefined4 *)(puVar5 + 0x44) = uVar8;
    puVar5[0x2a] = 0;
    puVar5[0x2b] = 0;
    puVar5[0x2e] = 0;
    puVar5[0x2f] = 0;
    puVar5[0x32] = 0;
    puVar5[0x33] = 0;
    uVar15 = *(uint *)(lVar4 + 0x138);
    if (*(uint *)(lVar4 + 0x138) <= *(uint *)(lVar4 + 0x130)) {
      uVar15 = *(uint *)(lVar4 + 0x130);
    }
    uVar14 = *(uint *)(lVar4 + 0x140);
    if (*(uint *)(lVar4 + 0x140) <= uVar15) {
      uVar14 = uVar15;
    }
    lVar13 = ExAllocatePool2(0x100,(ulonglong)(uVar14 + 2) + 0x10,0x4d444d55);
    if (lVar13 != 0) {
      uVar15 = *(uint *)(lVar6 + 8);
      iVar10 = 0x88;
      local_60 = 0;
      _Dst = (void *)(*(longlong *)(param_2 + 0x18) + 0x88);
      iVar11 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar4 + 0x20),2,0x1f01ff,&local_60);
      if (-1 < iVar11) {
        local_res20[0] = 0;
        local_58 = 0;
        uStack_50 = 0;
        iVar11 = (int)puVar2;
        if ((*(int *)(lVar4 + 0x130) != 0) && (*(int *)(lVar4 + 0x130) + 0x88U <= uVar15)) {
          RtlInitUnicodeString(&local_58,L"Manufacturer");
          iVar12 = ZwQueryValueKey(local_60,&local_58,2,lVar13,*(int *)(lVar4 + 0x130) + 0x11,
                                   local_res20);
          iVar10 = 0x88;
          if ((iVar12 == 0) && (uVar14 = *(uint *)(lVar13 + 8), 1 < uVar14)) {
            uVar1 = uVar14 - 2;
            memcpy(_Dst,(void *)(lVar13 + 0xc),(ulonglong)uVar1);
            *(uint *)puVar2 = *(int *)puVar2 + uVar1;
            *(uint *)(puVar5 + 0x2a) = uVar1;
            iVar10 = uVar14 + 0x86;
            *(int *)(puVar5 + 0x28) = (int)_Dst - iVar11;
            _Dst = (void *)((longlong)_Dst + (ulonglong)uVar1);
          }
        }
        if ((*(int *)(lVar4 + 0x138) != 0) && ((uint)(*(int *)(lVar4 + 0x138) + iVar10) <= uVar15))
        {
          RtlInitUnicodeString(&local_58,L"Model");
          iVar12 = ZwQueryValueKey(local_60,&local_58,2,lVar13,*(int *)(lVar4 + 0x138) + 0x11,
                                   local_res20);
          if ((iVar12 == 0) && (1 < *(uint *)(lVar13 + 8))) {
            uVar14 = *(uint *)(lVar13 + 8) - 2;
            memcpy(_Dst,(void *)(lVar13 + 0xc),(ulonglong)uVar14);
            *(uint *)puVar2 = *(int *)puVar2 + uVar14;
            *(uint *)(puVar5 + 0x2e) = uVar14;
            *(int *)(puVar5 + 0x2c) = (int)_Dst - iVar11;
            iVar10 = iVar10 + uVar14;
            _Dst = (void *)((longlong)_Dst + (ulonglong)uVar14);
          }
        }
        if ((*(int *)(lVar4 + 0x140) != 0) && ((uint)(iVar10 + *(int *)(lVar4 + 0x140)) <= uVar15))
        {
          RtlInitUnicodeString(&local_58,L"Version");
          iVar10 = ZwQueryValueKey(local_60,&local_58,2,lVar13,*(int *)(lVar4 + 0x140) + 0x11,
                                   local_res20);
          if ((iVar10 == 0) && (1 < *(uint *)(lVar13 + 8))) {
            uVar15 = *(uint *)(lVar13 + 8) - 2;
            memcpy(_Dst,(void *)(lVar13 + 0xc),(ulonglong)uVar15);
            *(uint *)(puVar5 + 0x32) = uVar15;
            *(uint *)puVar2 = *(int *)puVar2 + uVar15;
            *(int *)(puVar5 + 0x30) = (int)_Dst - iVar11;
          }
        }
        ZwClose(local_60);
      }
      ExFreePoolWithTag(lVar13,0);
    }
    puVar5[0xc] = 6;
    puVar5[0xd] = 0;
    *puVar5 = *puVar2 + 0x3c;
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)(ushort)(*puVar2 + 0x3c);
  }
  uVar3 = *(undefined4 *)(param_2 + 0x30);
  RemoveReferenceAndCompleteRequest(param_1,param_2,uVar3);
  return uVar3;
}



===== BinaryQueryRegRoutine @ 1c0009f40 =====

undefined8
BinaryQueryRegRoutine
          (undefined8 param_1,int param_2,void *param_3,uint param_4,undefined8 param_5,int *param_6
          )

{
  undefined8 uVar1;
  
  if (param_2 - 3U < 2) {
    if ((uint)-*param_6 < param_4) {
      uVar1 = 0xc0000023;
    }
    else {
      memcpy(param_6,param_3,(longlong)-*param_6);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== EnableDisableSerialWaitWake @ 1c0009f88 =====

ulonglong EnableDisableSerialWaitWake(longlong param_1,char param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    ((-(uint)(param_2 != '\0') & 0xfffffffc) + 0x1b0008,
                     *(undefined8 *)(param_1 + 0x30),0,0,0,0,1,local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x30),lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== SetDtr @ 1c000a06c =====

ulonglong SetDtr(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (0x1b0024,*(undefined8 *)(param_1 + 0x30),0,0,0,0,0,local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x30),lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== StartDevicePower @ 1c000a13c =====

int StartDevicePower(longlong param_1)

{
  int iVar1;
  longlong local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined4 local_10;
  
  iVar1 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_10 = 0;
  if ((*(int *)(param_1 + 0x274) != 0) && (*(int *)(param_1 + 0x260) != 1)) {
    KeInitializeEvent(&uStack_20,0,0);
    iVar1 = PoRequestPowerIrp(*(undefined8 *)(param_1 + 0x20),2,1,SetPowerCompletion,&local_28,0);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&uStack_20,0,0,0,0);
      iVar1 = (int)local_28;
    }
    if ((-1 < iVar1) &&
       (local_res8 = (longlong)*(int *)(param_1 + 0x274) * -10000, 0 < *(int *)(param_1 + 0x274))) {
      KeDelayExecutionThread(0,0,&local_res8);
    }
  }
  return iVar1;
}



===== UniClose @ 1c000a230 =====

undefined4 UniClose(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  LOCK();
  *(int *)(lVar1 + 0x3c) = *(int *)(lVar1 + 0x3c) + 1;
  UNLOCK();
  if (*(char *)(lVar1 + 0x3b) == '\0') {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar1 + 0x1a0,1);
    uVar2 = UniCloseStarter(lVar1,param_2);
    ExReleaseResourceLite(lVar1 + 0x1a0);
    KeLeaveCriticalRegion();
    RemoveReferenceAndCompleteRequest(param_1,param_2,uVar2);
  }
  else {
    RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000001);
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== UniCloseStarter @ 1c000a2e4 =====

undefined4 UniCloseStarter(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -1;
  uVar2 = 0;
  if (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) != 0) {
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
  }
  if (*(int *)(param_1 + 0x40) == 0) {
    LOCK();
    lVar1 = *(longlong *)(param_1 + 0xa0);
    *(longlong *)(param_1 + 0xa0) = 0;
    UNLOCK();
    if (lVar1 != 0) {
      IoFreeIrp();
    }
    uVar2 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(param_1 + 0x28),param_2,'\x01');
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x220) = 5;
    if (*(longlong *)(param_1 + 0x268) != 0) {
      PoUnregisterSystemState();
      *(undefined8 *)(param_1 + 0x268) = 0;
    }
    MmUnlockPagableImageSection(PagedCodeSectionHandle);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  return uVar2;
}



===== UniOpen @ 1c000a3c0 =====

ulonglong UniOpen(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  LOCK();
  *(int *)(lVar1 + 0x40) = *(int *)(lVar1 + 0x40) + 1;
  UNLOCK();
  uVar3 = CheckStateAndAddReference(param_1,param_2);
  LOCK();
  *(int *)(lVar1 + 0x40) = *(int *)(lVar1 + 0x40) + -1;
  UNLOCK();
  if ((int)uVar3 == 0) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar1 + 0x1a0,1);
    if (*(char *)(lVar1 + 0x38) == '\0') {
      uVar2 = 0xc0000037;
    }
    else {
      uVar2 = UniOpenStarter(lVar1,param_2);
    }
    ExReleaseResourceLite(lVar1 + 0x1a0);
    KeLeaveCriticalRegion();
    RemoveReferenceAndCompleteRequest(param_1,param_2,uVar2);
    RemoveReference(param_1);
    uVar3 = (ulonglong)uVar2;
  }
  return uVar3;
}



===== UniOpenStarter @ 1c000a47c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UniOpenStarter(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined1 auStack_258 [32];
  undefined8 local_238;
  undefined4 *local_230;
  undefined4 local_228 [2];
  undefined8 local_220;
  undefined4 local_218 [2];
  longlong local_210 [2];
  undefined4 local_200 [2];
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined4 local_1d8;
  undefined8 local_1d4;
  undefined8 uStack_1cc;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  code *local_198;
  undefined4 local_190;
  wchar_t *local_188;
  undefined8 *local_180;
  code *local_160;
  undefined4 local_158;
  wchar_t *local_150;
  undefined4 *local_148;
  code *local_128;
  undefined4 local_120;
  wchar_t *local_118;
  undefined4 *local_110;
  undefined4 local_108;
  undefined4 *local_100;
  undefined4 local_f8;
  undefined4 local_e8;
  wchar_t *local_e0;
  longlong local_d8;
  undefined4 local_d0;
  undefined4 *local_c8;
  undefined4 local_c0;
  undefined4 local_b0;
  wchar_t *local_a8;
  int *local_a0;
  undefined4 local_98;
  undefined4 *local_90;
  undefined4 local_88;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_258;
  lVar6 = *(longlong *)(param_2 + 0xb8);
  local_220 = 0;
  local_228[0] = 0;
  local_1c0 = 0;
  uStack_1b8 = 0;
  local_200[0] = 10;
  local_1b0 = 0;
  uStack_1a8 = 0;
  local_218[0] = 0;
  local_1d4 = 0;
  uStack_1cc = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  local_1f8 = 0;
  uStack_1f0 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  local_1e8 = 0;
  uStack_1e0 = 0;
  if ((*(uint *)(lVar6 + 0x10) & 1) != 0) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000103;
    return -0x3ffffefd;
  }
  if (*(short *)(*(longlong *)(lVar6 + 0x30) + 0x58) == 0) {
    if (*(int *)(param_1 + 0x40) != 0) {
      *(undefined4 *)(param_2 + 0x30) = 0xc0000043;
      return -0x3fffffbd;
    }
LAB_1c000a587:
    lVar8 = 2;
    iVar3 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x20),2,1,&local_220);
    if (-1 < iVar3) {
      memset(&local_198,0,0x150);
      uVar5 = local_220;
      local_120 = 0;
      local_198 = BinaryQueryRegRoutine;
      local_188 = L"Properties";
      local_160 = BinaryQueryRegRoutine;
      local_180 = &local_1c0;
      local_128 = BinaryQueryRegRoutine;
      local_150 = L"Default";
      local_100 = local_200;
      local_148 = &local_1d8;
      local_e8 = 0x120;
      local_118 = L"InactivityScale";
      local_110 = (undefined4 *)(param_1 + 0x198);
      local_d0 = 0x4000004;
      *local_110 = 0xfffffffc;
      local_e0 = L"PowerDelay";
      local_d8 = param_1 + 0x274;
      local_c8 = local_218;
      local_a8 = L"ConfigDelay";
      local_90 = local_218;
      local_b0 = 0x120;
      local_98 = 0x4000004;
      local_190 = 4;
      local_1c0._0_4_ = 0xffffffe0;
      local_158 = 4;
      local_1d8 = 0xffffffec;
      local_108 = 3;
      local_f8 = 4;
      local_c0 = 4;
      local_88 = 4;
      local_210[0] = 0;
      local_210[1] = 0;
      local_a0 = (int *)(param_1 + 0x278);
      RtlInitUnicodeString(local_210,L"RtlQueryRegistryValuesEx");
      pcVar4 = (code *)MmGetSystemRoutineAddress(local_210);
      if (pcVar4 == (code *)0x0) {
        pcVar4 = RtlQueryRegistryValues_exref;
      }
      local_238 = 0;
      iVar3 = (*pcVar4)(0x40000000,uVar5,&local_198,param_1);
      if (iVar3 < 0) {
        *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
        ZwClose(local_220);
        return -0x3ffffff3;
      }
      memset((undefined4 *)(param_1 + 0x118),0,0x50);
      *(undefined8 *)(param_1 + 0x168) = 0;
      *(undefined8 *)(param_1 + 0x170) = 0;
      *(undefined8 *)(param_1 + 0x178) = 0;
      *(undefined8 *)(param_1 + 0x180) = 0;
      *(undefined8 *)(param_1 + 0x188) = 0;
      *(undefined8 *)(param_1 + 400) = 0;
      RtlInitUnicodeString(&local_1f8,L"Manufacturer");
      local_230 = local_228;
      local_238._0_4_ = 0x10;
      uStack_1e0._0_4_ = 1;
      iVar3 = ZwQueryValueKey(local_220,&local_1f8,2,&local_1e8);
      if ((iVar3 == 0) || (iVar3 == -0x7ffffffb)) {
        iVar3 = (int)uStack_1e0 + -2;
      }
      else {
        iVar3 = 0;
      }
      *(int *)(param_1 + 0x130) = iVar3;
      RtlInitUnicodeString(&local_1f8,L"Model");
      local_230 = local_228;
      local_238._0_4_ = 0x10;
      uStack_1e0._0_4_ = 1;
      iVar3 = ZwQueryValueKey(local_220,&local_1f8,2,&local_1e8);
      if ((iVar3 == 0) || (iVar3 == -0x7ffffffb)) {
        iVar3 = (int)uStack_1e0 + -2;
      }
      else {
        iVar3 = 0;
      }
      *(int *)(param_1 + 0x138) = iVar3;
      RtlInitUnicodeString(&local_1f8,L"Version");
      local_230 = local_228;
      local_238 = CONCAT44(local_238._4_4_,0x10);
      uStack_1e0 = CONCAT44(uStack_1e0._4_4_,1);
      iVar3 = ZwQueryValueKey(local_220,&local_1f8,2,&local_1e8);
      if ((iVar3 == 0) || (iVar3 == -0x7ffffffb)) {
        iVar3 = (int)uStack_1e0 + -2;
      }
      else {
        iVar3 = 0;
      }
      *(int *)(param_1 + 0x140) = iVar3;
      ZwClose(local_220);
      *(undefined4 *)(param_1 + 0x170) = 0;
      *(undefined4 *)(param_1 + 0x174) = 0;
      *(undefined4 *)(param_1 + 0x144) = (undefined4)local_1c0;
      *(undefined4 *)(param_1 + 0x148) = local_1c0._4_4_;
      *(undefined4 *)(param_1 + 0x14c) = (undefined4)uStack_1b8;
      *(undefined4 *)(param_1 + 0x150) = uStack_1b8._4_4_;
      *(undefined4 *)(param_1 + 0x154) = (undefined4)local_1b0;
      *(undefined4 *)(param_1 + 0x158) = local_1b0._4_4_;
      *(undefined4 *)(param_1 + 0x15c) = (undefined4)uStack_1a8;
      *(undefined4 *)(param_1 + 0x160) = uStack_1a8._4_4_;
      *(undefined4 *)(param_1 + 0x118) = 0x4c;
      *(undefined4 *)(param_1 + 0x178) = local_1d8;
      *(int *)(param_1 + 0x11c) =
           *(int *)(param_1 + 0x138) + *(int *)(param_1 + 0x130) + *(int *)(param_1 + 0x140) + 0x4c;
      *(int *)(param_1 + 0x17c) = (int)local_1d4 * *(int *)(param_1 + 0x198);
      *(undefined4 *)(param_1 + 0x180) = local_1d4._4_4_;
      *(undefined4 *)(param_1 + 0x184) = (undefined4)uStack_1cc;
      *(undefined4 *)(param_1 + 0x188) = uStack_1cc._4_4_;
      *(undefined4 *)(param_1 + 0x168) = 0x30;
      *(undefined4 *)(param_1 + 0x16c) = 0x30;
      StartDevicePower(param_1);
      iVar3 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(param_1 + 0x28),param_2,'\x01');
      if (iVar3 < 0) {
        *(int *)(param_2 + 0x30) = iVar3;
        return iVar3;
      }
      *(longlong *)(param_1 + 0x30) = *(longlong *)(param_1 + 0x28);
      *(char *)(*(longlong *)(param_1 + 0x18) + 0x4c) =
           *(char *)(*(longlong *)(param_1 + 0x28) + 0x4c) + '\x01';
      SetDtr(param_1);
      EnableDisableSerialWaitWake(param_1,*(char *)(param_1 + 0x2ae));
      iVar3 = *(int *)(param_1 + 0x278);
      local_210[0] = (longlong)iVar3 * -10000;
      if (0 < iVar3) {
        KeDelayExecutionThread(0,0,local_210);
      }
      *(undefined8 *)(param_1 + 0x398) = *(undefined8 *)(param_1 + 0x30);
      *(undefined8 *)(param_1 + 0x3f0) = *(undefined8 *)(param_1 + 0x30);
      *(undefined8 *)(*(longlong *)(lVar6 + 0x30) + 0x18) = 1;
      *(undefined4 *)(param_1 + 0x7c) = 1;
      *(undefined4 *)(param_1 + 0x40) = 1;
      uVar5 = IoGetCurrentProcess();
      *(undefined8 *)(param_1 + 0x70) = uVar5;
      lVar6 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x18) >> 8),
                                     *(undefined1 *)(*(longlong *)(param_1 + 0x18) + 0x4c)),0);
      if (lVar6 == 0) {
        UniCloseStarter(param_1,param_2);
        *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
        return -0x3fffff66;
      }
      lVar1 = *(longlong *)(lVar6 + 0xb8);
      *(char *)(lVar6 + 0x43) = *(char *)(lVar6 + 0x43) + -1;
      *(undefined4 *)(lVar6 + 0x10) = 0x30;
      *(longlong *)(lVar6 + 0xb8) = lVar1 + -0x48;
      *(undefined8 *)(lVar6 + 0x70) = 0;
      *(undefined8 *)(lVar6 + 0x18) = 0;
      *(undefined8 *)(lVar6 + 0x50) = 0;
      *(undefined8 *)(lVar6 + 0x48) = 0;
      *(undefined8 *)(lVar1 + -0x20) = *(undefined8 *)(param_1 + 0x18);
      puVar7 = (undefined8 *)(param_1 + 200);
      *(longlong *)(param_1 + 0xa0) = lVar6;
      lVar6 = 2;
      *(undefined2 *)(param_1 + 0x2ac) = 0;
      *(undefined4 *)(param_1 + 0x220) = 5;
      *(undefined4 *)(param_1 + 0x78) = 0;
      *(undefined8 *)(param_1 + 0xb8) = 0;
      *(undefined8 *)(param_1 + 0xf0) = 0;
      *(undefined8 *)(param_1 + 0xc0) = 0;
      *(undefined8 *)(param_1 + 0xf8) = 0;
      do {
        *puVar7 = 0;
        puVar7 = puVar7 + 7;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      puVar7 = (undefined8 *)(param_1 + 0xd0);
      do {
        *puVar7 = 0;
        puVar7 = puVar7 + 7;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      MmLockPagableSectionByHandle(PagedCodeSectionHandle);
      return 0;
    }
  }
  else {
    local_210[0] = 0;
    local_210[1] = 0;
    RtlInitUnicodeString(local_210,L"\\Tsp");
    cVar2 = RtlEqualUnicodeString(*(longlong *)(lVar6 + 0x30) + 0x58,local_210,1);
    if (cVar2 != '\0') {
      if (*(int *)(param_1 + 0x40) != 0) {
        iVar3 = -0x3fffffbd;
        goto LAB_1c000ab63;
      }
      goto LAB_1c000a587;
    }
    RtlInitUnicodeString(local_210,L"\\Client");
    cVar2 = RtlEqualUnicodeString(*(longlong *)(lVar6 + 0x30) + 0x58,local_210,1);
    if (cVar2 == '\0') {
      RtlInitUnicodeString(local_210,&u__Wave);
      cVar2 = RtlEqualUnicodeString(*(longlong *)(lVar6 + 0x30) + 0x58,local_210,1);
      if ((((cVar2 != '\0') && (*(int *)(param_1 + 0x40) == 1)) &&
          (*(longlong *)(param_1 + 0x70) != 0)) &&
         ((*(longlong **)(param_1 + 0x330) != (longlong *)(param_1 + 0x330) ||
          (*(char *)(param_1 + 0x2ac) != '\0')))) goto LAB_1c000abf5;
    }
    else if ((*(int *)(param_1 + 0x40) != 0) && (*(longlong *)(param_1 + 0x70) != 0)) {
LAB_1c000abf5:
      *(undefined8 *)(*(longlong *)(lVar6 + 0x30) + 0x18) = 0;
      *(longlong *)(*(longlong *)(lVar6 + 0x30) + 0x20) = (longlong)*(int *)(param_1 + 0x80);
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      *(int *)(param_1 + 0x300) = *(int *)(param_1 + 0x300) + 1;
      return 0;
    }
  }
  iVar3 = -0x3ffffff3;
LAB_1c000ab63:
  *(int *)(param_2 + 0x30) = iVar3;
  return iVar3;
}



===== ModemQueryWmiRegInfo @ 1c000ac20 =====

undefined8
ModemQueryWmiRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0x20;
  *param_4 = &DriverEntryRegPath;
  RtlInitUnicodeString(param_5,L"MODEMWMI");
  *param_6 = *(undefined8 *)(lVar1 + 0x20);
  return 0;
}



===== ModemWmi @ 1c000ac70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ModemWmi(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 auStack_98 [32];
  int local_78 [4];
  undefined4 local_68 [16];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_78[0] = 0;
  piVar1 = *(int **)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if ((*piVar1 == 0x204f4450) || (*piVar1 == 0x4f445078)) {
    uVar3 = *(uint *)(param_2 + 0x30);
    IofCompleteRequest(param_2,0);
LAB_1c000adc0:
    return (ulonglong)uVar3;
  }
  uVar4 = CheckStateAndAddReferenceWMI(param_1,param_2);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  if ((char)piVar1[0x8e] == (char)uVar4) {
    memset(local_68,0,0x40);
    QueryDeviceCaps(*(longlong *)(piVar1 + 8),local_68);
  }
  if ((piVar1[0x96] < 2) || (piVar1[0x97] < 2)) {
    if (*(longlong *)(lVar2 + 8) == param_1) {
      RemoveReference(param_1);
      uVar3 = *(uint *)(param_2 + 0x30);
      RemoveReferenceAndCompleteRequest(param_1,param_2,uVar3);
    }
    else {
      uVar3 = ForwardIrp(*(undefined8 *)(piVar1 + 10),param_2);
      RemoveReference(param_1);
      RemoveReference(param_1);
    }
    goto LAB_1c000adc0;
  }
  uVar3 = WmiSystemControl(&WmiContext,param_1,param_2,local_78);
  uVar4 = (ulonglong)uVar3;
  if (local_78[0] != 0) {
    if (local_78[0] == 1) {
      RemoveReferenceAndCompleteRequest(param_1,param_2,*(undefined4 *)(param_2 + 0x30));
      goto LAB_1c000ad4e;
    }
    if ((local_78[0] != 2) && (local_78[0] != 3)) goto LAB_1c000ad4e;
    uVar3 = ForwardIrp(*(undefined8 *)(piVar1 + 10),param_2);
    uVar4 = (ulonglong)uVar3;
  }
  RemoveReference(param_1);
LAB_1c000ad4e:
  RemoveReference(param_1);
  return uVar4;
}



===== ModemWmiQueryDataBlock @ 1c000adf0 =====

void ModemWmiQueryDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,int param_7,undefined1 *param_8)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_3 == 0) {
    uVar2 = 1;
    if (param_7 == 0) {
      uVar1 = 0xc0000023;
    }
    else {
      uVar1 = 0;
      *param_8 = *(undefined1 *)(*(longlong *)(param_1 + 0x40) + 0x2ae);
      *param_6 = 1;
    }
  }
  else {
    uVar1 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar1,uVar2,0);
  return;
}



===== ModemWmiSetDataBlock @ 1c000ae60 =====

void ModemWmiSetDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,int param_5,
               char *param_6)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = 0;
  if (param_3 == 0) {
    uVar1 = 1;
    if (param_5 == 0) {
      uVar2 = 0xc0000023;
    }
    else {
      SetWakeEnabledState(param_1,*param_6);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar2,uVar1,0);
  return;
}



===== ModemWmiSetDataItem @ 1c000aee0 =====

void ModemWmiSetDataItem(longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
                        undefined8 param_5,int param_6,char *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = 0;
  if (param_3 == 0) {
    uVar1 = 1;
    if (param_6 == 0) {
      uVar2 = 0xc0000023;
    }
    else {
      SetWakeEnabledState(param_1,*param_7);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar2,uVar1,0);
  return;
}



===== SetWakeEnabledState @ 1c000af58 =====

undefined8 SetWakeEnabledState(longlong param_1,char param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar1 + 0x1a0,1);
  if (*(int *)(lVar1 + 0x40) == 0) {
    *(char *)(lVar1 + 0x2ae) = param_2;
  }
  else {
    if (*(char *)(lVar1 + 0x2ae) == '\0') {
      if (param_2 == '\0') goto LAB_1c000afc8;
    }
    else if (param_2 != '\0') goto LAB_1c000afc8;
    *(char *)(lVar1 + 0x2ae) = param_2;
    EnableDisableSerialWaitWake(lVar1,param_2);
  }
LAB_1c000afc8:
  ExReleaseResourceLite(lVar1 + 0x1a0);
  KeLeaveCriticalRegion();
  ModemSetRegistryKeyValue();
  return 0;
}



===== CleanUpOnRemove @ 1c000c008 =====

void CleanUpOnRemove(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  char cVar7;
  undefined7 extraout_var;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  undefined4 local_res8 [2];
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar9 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar3 + 0x40) != 0) {
    local_res8[0] = 0;
    lVar1 = lVar3 + 0x10;
    lVar11 = 2;
    plVar8 = (longlong *)(lVar3 + 0xd8);
    lVar10 = 2;
    do {
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
      if (plVar8[-1] != 0) {
        *(undefined1 *)(*plVar8 + 0x21) = 1;
        plVar8[-1] = 0;
        *plVar8 = 0;
      }
      plVar2 = plVar8 + -2;
      lVar4 = *plVar2;
      if (lVar4 == 0) {
        KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar6));
      }
      else {
        *plVar2 = 0;
        UniRundownShuttledWait(lVar3,plVar2,1,lVar4,uVar6,0,0);
      }
      plVar8 = plVar8 + 7;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    *(undefined2 *)(lVar9 + -0x48) = 0xe;
    *(undefined1 *)(lVar9 + -0x46) = *(undefined1 *)(lVar9 + 2);
    *(undefined4 *)(lVar9 + -0x40) = 0;
    *(undefined4 *)(lVar9 + -0x30) = 0x1b0044;
    *(undefined4 *)(lVar9 + -0x38) = 4;
    *(undefined8 *)(lVar9 + -0x28) = 0;
    uVar5 = *(undefined8 *)(param_2 + 0x18);
    *(undefined4 **)(param_2 + 0x18) = local_res8;
    WaitForLowerDriverToCompleteIrp(*(undefined8 *)(lVar3 + 0x30),param_2,'\0');
    *(undefined4 *)(lVar9 + -0x38) = 4;
    *(undefined1 *)(lVar9 + -0x46) = 0;
    *(undefined4 *)(lVar9 + -0x40) = 0;
    *(undefined8 *)(lVar9 + -0x28) = 0;
    *(undefined2 *)(lVar9 + -0x48) = 0xe;
    *(undefined4 *)(lVar9 + -0x30) = 0x1b004c;
    **(undefined4 **)(param_2 + 0x18) = 3;
    WaitForLowerDriverToCompleteIrp(*(undefined8 *)(lVar3 + 0x30),param_2,'\0');
    *(undefined8 *)(param_2 + 0x18) = uVar5;
    plVar8 = (longlong *)(lVar3 + 0x318);
    do {
      EmptyIpcQueue(lVar3,plVar8 + -2);
      EmptyIpcQueue(lVar3,plVar8);
      plVar8 = plVar8 + 5;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
    CompletePowerWait(param_1,0xc0000120);
    lVar9 = 0;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    if (*(longlong *)(lVar3 + 0x2b0) != 0) {
      cVar7 = HasIrpBeenCanceled(*(longlong *)(lVar3 + 0x2b0));
      if ((int)CONCAT71(extraout_var,cVar7) == 0) {
        lVar9 = *(longlong *)(lVar3 + 0x2b0);
        *(undefined8 *)(lVar3 + 0x2b0) = 0;
      }
    }
    KeReleaseSpinLock(lVar1,uVar6);
    if (lVar9 != 0) {
      *(undefined8 *)(lVar9 + 0x38) = 0;
      RemoveReferenceAndCompleteRequest(param_1,lVar9,0);
    }
  }
  return;
}



===== UniDispatch @ 1c000c210 =====

ulonglong UniDispatch(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar4 = CheckStateAndAddReference(param_1,param_2);
  if ((int)uVar4 == 0) {
    if ((*(int *)(lVar1 + 0x7c) == 0) && (*(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x18) == 0)) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar4 = 0xc0000037;
      RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000037);
    }
    else {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x30),param_2);
      uVar4 = (ulonglong)uVar3;
      RemoveReference(param_1);
    }
    RemoveReference(param_1);
  }
  return uVar4;
}



===== PowerWaitCancelRoutine @ 1c000c2c0 =====

void PowerWaitCancelRoutine(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x10);
  if (*(int *)(param_2 + 0x30) == 0x103) {
    *(undefined8 *)(lVar1 + 0x228) = 0;
  }
  KeReleaseSpinLock(lVar1 + 0x10,uVar2);
  *(undefined8 *)(param_2 + 0x38) = 0;
  RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000120);
  return;
}



===== UniIoControl @ 1c000c360 =====

ulonglong UniIoControl(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  uint *puVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined8 uVar11;
  longlong lVar12;
  longlong lVar13;
  undefined4 uVar14;
  longlong lVar15;
  undefined1 local_res8 [8];
  undefined1 local_res10 [8];
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar12 = *(longlong *)(param_2 + 0xb8);
  lVar13 = param_2;
  uVar10 = CheckStateAndAddReference(param_1,param_2);
  if ((int)uVar10 != 0) {
    return uVar10;
  }
  uVar9 = *(uint *)(*(longlong *)(lVar12 + 0x30) + 0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar2 = *(uint *)(lVar12 + 0x18);
  if (uVar2 < 0x1b0065) {
    if (uVar2 != 0x1b0064) {
      if (uVar2 < 0x1b0035) {
        if (uVar2 != 0x1b0034) {
          if (uVar2 < 0x1b001d) {
            if ((uVar2 == 0x1b001c) || (uVar2 == 0x1b0004)) goto LAB_1c000cabb;
            iVar8 = uVar2 - 0x1b0008;
          }
          else {
            iVar8 = uVar2 - 0x1b0020;
          }
          if (iVar8 == 0) goto LAB_1c000c506;
        }
      }
      else {
        if (0x1b004c < uVar2) {
          if (((uVar2 != 0x1b0050) && (uVar2 != 0x1b0054)) && (uVar2 != 0x1b0058)) {
            iVar8 = uVar2 - 0x1b005c;
            if (iVar8 != 0) {
LAB_1c000c4fd:
              if (iVar8 == 4) goto LAB_1c000c506;
            }
            goto LAB_1c000cabb;
          }
LAB_1c000c506:
          lVar3 = *(longlong *)(param_1 + 0x40);
          *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
          *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
          uVar9 = IofCallDriver(*(undefined8 *)(lVar3 + 0x30),param_2);
          uVar10 = (ulonglong)uVar9;
          RemoveReference(param_1);
          goto LAB_1c000cc9f;
        }
        if (uVar2 == 0x1b004c) {
          if (*(uint *)(lVar12 + 0x10) < 4) goto LAB_1c000c433;
          uVar9 = **(uint **)(param_2 + 0x18);
          if ((uVar9 & 5) != 0) {
            MarkQueueToEmpty(lVar3 + 0x350);
          }
          if ((uVar9 & 10) != 0) {
            MarkQueueToEmpty(lVar3 + 0x3b0);
          }
        }
        else if (((uVar2 != 0x1b0038) && (uVar2 != 0x1b003c)) && (uVar2 == 0x1b0040)) {
          if (3 < *(uint *)(lVar12 + 8)) {
            **(undefined4 **)(param_2 + 0x18) =
                 *(undefined4 *)
                  ((ulonglong)
                   (-(uint)(*(longlong *)(*(longlong *)(lVar12 + 0x30) + 0x18) != 0) & 0x38) + 0xc0
                  + lVar3);
LAB_1c000c45b:
            *(undefined8 *)(param_2 + 0x38) = 4;
            goto LAB_1c000cc8e;
          }
          goto LAB_1c000c433;
        }
      }
    }
LAB_1c000cabb:
    if (*(longlong *)(*(longlong *)(lVar12 + 0x30) + 0x18) == 0) {
      uVar10 = UniCheckPassThrough(param_1,param_2);
      uVar9 = (uint)uVar10;
    }
    else {
      uVar10 = UniSniffOwnerSettings(param_1,param_2);
      uVar9 = (uint)uVar10;
    }
LAB_1c000c572:
    uVar10 = (ulonglong)uVar9;
    goto LAB_1c000cc9f;
  }
  if (uVar2 < 0x2b0011) {
    if (uVar2 != 0x2b0010) {
      if (uVar2 < 0x1b0081) {
        if (uVar2 != 0x1b0080) {
          if ((uVar2 == 0x1b0068) || (uVar2 == 0x1b006c)) goto LAB_1c000c506;
          if (uVar2 == 0x1b0070) goto LAB_1c000cabb;
          iVar8 = uVar2 - 0x1b0074;
          if (iVar8 != 0) goto LAB_1c000c4fd;
          if (*(uint *)(lVar12 + 8) < 0x8c) {
            if (*(uint *)(lVar12 + 8) != 0x40) goto LAB_1c000c433;
            goto LAB_1c000c506;
          }
          bVar5 = KeGetCurrentIrql();
          if (1 < bVar5) {
            uVar10 = 0xc0000010;
            goto LAB_1c000cc91;
          }
          uVar9 = GetPropertiesHandler(param_1,param_2);
          goto LAB_1c000c572;
        }
        if (3 < *(uint *)(lVar12 + 8)) {
          if ((ulonglong)*(uint *)(lVar3 + 0x16c) + 0x30 < 0x100000000) {
            **(int **)(param_2 + 0x18) = *(uint *)(lVar3 + 0x16c) + 0x30;
            goto LAB_1c000c45b;
          }
          uVar10 = 0xc000009a;
          goto LAB_1c000cc91;
        }
      }
      else {
        if (uVar2 != 0x1b0084) {
          if (uVar2 != 0x1b0088) {
            if ((uVar2 == 0x1b008c) || (uVar2 == 0x1b0090)) goto LAB_1c000c506;
            if (uVar2 == 0x2b000c) {
              if (3 < *(uint *)(lVar12 + 0x10)) {
                if (**(int **)(param_2 + 0x18) == 1) {
                  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x10);
                  *(undefined1 *)(lVar3 + 0x2ac) = 1;
                  *(undefined8 *)(lVar3 + 0x2a4) = 0;
                  goto LAB_1c000c621;
                }
                if (**(int **)(param_2 + 0x18) != 0) goto LAB_1c000c76e;
                lVar12 = 0;
                uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x10);
                if ((*(longlong *)(lVar3 + 0x2b0) != 0) &&
                   (cVar7 = HasIrpBeenCanceled(*(longlong *)(lVar3 + 0x2b0)),
                   (int)CONCAT71(extraout_var,cVar7) == 0)) {
                  lVar12 = *(longlong *)(lVar3 + 0x2b0);
                  *(undefined8 *)(lVar3 + 0x2b0) = 0;
                }
                *(undefined1 *)(lVar3 + 0x2ac) = 0;
                *(undefined8 *)(lVar3 + 0x2a4) = 0;
                KeReleaseSpinLock(lVar3 + 0x10,uVar6);
                if (lVar12 != 0) {
                  *(undefined8 *)(lVar12 + 0x38) = 0;
                  RemoveReferenceAndCompleteRequest(param_1,lVar12,0);
                }
                goto LAB_1c000cc8e;
              }
              goto LAB_1c000c433;
            }
          }
          goto LAB_1c000cabb;
        }
        puVar4 = *(uint **)(param_2 + 0x18);
        uVar9 = *(int *)(lVar3 + 0x16c) + 0x30;
        if (uVar9 <= *(uint *)(lVar12 + 8)) {
          *puVar4 = uVar9;
          puVar4[1] = 1;
          puVar4[9] = 6;
          puVar4[10] = 0x30;
          puVar4[0xb] = *(uint *)(lVar3 + 0x16c);
          uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x10);
          memcpy(puVar4 + 0xc,(void *)(lVar3 + 0x168),(ulonglong)*(uint *)(lVar3 + 0x16c));
          KeReleaseSpinLock(lVar3 + 0x10,uVar6);
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)*puVar4;
          goto LAB_1c000cc8e;
        }
      }
LAB_1c000c433:
      uVar10 = 0xc0000023;
      goto LAB_1c000cc91;
    }
    lVar13 = lVar3 + 0x10;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar13);
    uVar10 = 0;
    if (*(char *)(lVar3 + 0x2ac) == '\0') {
      KeReleaseSpinLock(lVar13,uVar6);
      goto LAB_1c000c76e;
    }
    LOCK();
    lVar15 = *(longlong *)(lVar3 + 0x2b0);
    *(longlong *)(lVar3 + 0x2b0) = 0;
    UNLOCK();
    if ((lVar15 != 0) &&
       (cVar7 = HasIrpBeenCanceled(lVar15), (int)CONCAT71(extraout_var_00,cVar7) != 0)) {
      lVar15 = 0;
    }
    uVar9 = *(uint *)(lVar3 + 0x2a4);
    if (uVar9 != 0) {
      if (*(uint *)(lVar12 + 8) <= uVar9) {
        uVar9 = *(uint *)(lVar12 + 8);
      }
      memcpy(*(void **)(param_2 + 0x18),(void *)(lVar3 + 0x27c),(ulonglong)uVar9);
      *(int *)(lVar3 + 0x2a4) = *(int *)(lVar3 + 0x2a4) - uVar9;
      KeReleaseSpinLock(lVar13,uVar6);
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar9;
      if (lVar15 != 0) {
        *(undefined8 *)(lVar15 + 0x38) = 0;
        RemoveReferenceAndCompleteRequest(param_1,lVar15,0xc0000120);
      }
      goto LAB_1c000cc91;
    }
    local_res8[0] = 0;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    uVar10 = 0x103;
    *(undefined4 *)(param_2 + 0x30) = 0x103;
    IoAcquireCancelSpinLock(local_res8);
    LOCK();
    *(code **)(param_2 + 0x68) = GetDleCancelRoutine;
    UNLOCK();
    *(longlong *)(lVar3 + 0x2b0) = param_2;
    IoReleaseCancelSpinLock(local_res8[0]);
    KeReleaseSpinLock(lVar13,uVar6);
    if (lVar15 == 0) goto LAB_1c000cc9f;
    *(undefined8 *)(lVar15 + 0x38) = 0;
    uVar14 = 0xc0000120;
  }
  else {
    if (uVar2 < 0x2b0029) {
      if (uVar2 == 0x2b0028) {
        lVar13 = *(longlong *)(param_2 + 0x18);
        if (uVar9 != 1) goto LAB_1c000c76e;
        if (0x17 < *(uint *)(lVar12 + 0x10)) {
          *(undefined4 *)(lVar3 + 0x78) = 0;
          *(undefined8 *)(lVar13 + 8) = 0xffffffffffffffff;
          uVar10 = 0x103;
          QueueLoopbackMessageIrp(lVar3,param_2);
          EmptyIpcQueue(lVar3,(longlong *)(lVar3 + 0x308));
          EmptyIpcQueue(lVar3,(longlong *)(lVar3 + 0x318));
          goto LAB_1c000cc9f;
        }
      }
      else if (uVar2 == 0x2b0014) {
        if (3 < *(uint *)(lVar12 + 0x10)) {
          if (**(int **)(param_2 + 0x18) == 1) {
            uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x10);
            *(undefined1 *)(lVar3 + 0x2ad) = 1;
LAB_1c000c621:
            KeReleaseSpinLock(lVar3 + 0x10,uVar6);
          }
          else {
            if (**(int **)(param_2 + 0x18) != 0) goto LAB_1c000c76e;
            uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x10);
            *(undefined1 *)(lVar3 + 0x2ad) = 0;
            uVar11 = CONCAT71((int7)((ulonglong)lVar13 >> 8),uVar6);
            KeReleaseSpinLock(lVar3 + 0x10);
            CleanUpQueuedIrps(lVar3 + 0x350,uVar11);
          }
          goto LAB_1c000cc8e;
        }
      }
      else {
        if (uVar2 != 0x2b0018) {
          if (uVar2 == 0x2b001c) {
            if ((uVar9 != 1) || (*(uint *)(lVar3 + 0x40) < 2)) {
LAB_1c000c76e:
              uVar10 = 0xc000000d;
              goto LAB_1c000cc91;
            }
            if (*(uint *)(lVar12 + 0x10) < 0x18) goto LAB_1c000c433;
            if ((*(int *)(*(longlong *)(param_2 + 0x18) + 8) != *(int *)(lVar3 + 0x300)) ||
               (*(int *)(*(longlong *)(param_2 + 0x18) + 0xc) != *(int *)(lVar3 + 0x304))) {
              uVar10 = 0xc0000001;
              goto LAB_1c000cc91;
            }
          }
          else if (uVar2 != 0x2b0020) {
            if (uVar2 != 0x2b0024) goto LAB_1c000cabb;
            lVar13 = *(longlong *)(param_2 + 0x18);
            if (((*(uint *)(lVar3 + 0x40) < 2) || (uVar9 != 0)) || (*(int *)(lVar3 + 0x78) == 0))
            goto LAB_1c000c76e;
            if (*(uint *)(lVar12 + 0x10) < 0x18) goto LAB_1c000c433;
            *(int *)(lVar3 + 0x304) = *(int *)(lVar3 + 0x304) + 1;
            *(undefined4 *)(lVar13 + 8) = *(undefined4 *)(lVar3 + 0x300);
            *(undefined4 *)(lVar13 + 0xc) = *(undefined4 *)(lVar3 + 0x304);
          }
          uVar10 = 0x103;
          QueueMessageIrp(lVar3,param_2);
          goto LAB_1c000cc9f;
        }
        lVar13 = *(longlong *)(param_2 + 0xb8);
        if (*(int *)(lVar12 + 0x10) != 0) {
          *(undefined4 *)(lVar3 + 0x2f8) = 0;
          *(undefined2 *)(lVar13 + -0x48) = 4;
          *(undefined4 *)(lVar13 + -0x40) = *(undefined4 *)(lVar12 + 0x10);
          lVar12 = *(longlong *)(param_2 + 0xb8);
          *(code **)(lVar12 + -0x10) = UniStopReceiveComplete;
          *(longlong *)(lVar12 + -8) = lVar3;
          *(undefined1 *)(lVar12 + -0x45) = 0xe0;
          pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
          uVar10 = 0x103;
          *(undefined4 *)(param_2 + 0x30) = 0x103;
          IofCallDriver(*(undefined8 *)(lVar3 + 0x30),param_2);
          goto LAB_1c000cc9f;
        }
      }
      goto LAB_1c000c433;
    }
    if (uVar2 != 0x2b002c) {
      if (uVar2 == 0x2b0030) {
        if (3 < *(uint *)(lVar12 + 0x10)) {
          iVar8 = **(int **)(param_2 + 0x18);
          *(uint *)(lVar3 + 0x220) = (-(uint)(iVar8 != 0) & 4) + 1;
          if (iVar8 == 0) {
            uVar11 = PoRegisterSystemState(*(longlong *)(lVar3 + 0x268),0x80000001);
            *(undefined8 *)(lVar3 + 0x268) = uVar11;
          }
          else if (*(longlong *)(lVar3 + 0x268) != 0) {
            PoUnregisterSystemState();
            *(undefined8 *)(lVar3 + 0x268) = 0;
          }
          goto LAB_1c000cc8e;
        }
      }
      else {
        if (uVar2 != 0x2b0034) {
          if (uVar2 == 0x2b0038) {
            EmptyIpcQueue(lVar3,(longlong *)(lVar3 + 0x308 + (ulonglong)uVar9 * 0x28));
            EmptyIpcQueue(lVar3,(longlong *)(lVar3 + 0x318 + (ulonglong)uVar9 * 0x28));
            if (uVar9 == 1) {
              EmptyIpcQueue(lVar3,(longlong *)(lVar3 + 0x308));
              EmptyIpcQueue(lVar3,(longlong *)(lVar3 + 0x318));
            }
          }
          else {
            if (uVar2 != 0x2b003c) goto LAB_1c000cabb;
            if (uVar9 != 1) goto LAB_1c000c76e;
            if (*(uint *)(lVar12 + 0x10) < 4) goto LAB_1c000c433;
            *(undefined4 *)(lVar3 + 0x78) = **(undefined4 **)(param_2 + 0x18);
          }
          goto LAB_1c000cc8e;
        }
        local_res10[0] = 0;
        if (3 < *(uint *)(lVar12 + 0x10)) {
          iVar8 = **(int **)(param_2 + 0x18);
          uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x10);
          if (iVar8 == 0) {
            uVar10 = 0;
            lVar12 = 0;
          }
          else {
            pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
            *pbVar1 = *pbVar1 | 1;
            uVar10 = 0x103;
            *(undefined4 *)(param_2 + 0x30) = 0x103;
            IoAcquireCancelSpinLock(local_res10);
            LOCK();
            *(code **)(param_2 + 0x68) = PowerWaitCancelRoutine;
            UNLOCK();
            IoReleaseCancelSpinLock(local_res10[0]);
            lVar12 = param_2;
          }
          LOCK();
          lVar13 = *(longlong *)(lVar3 + 0x228);
          *(longlong *)(lVar3 + 0x228) = lVar12;
          UNLOCK();
          if ((lVar13 != 0) &&
             (cVar7 = HasIrpBeenCanceled(lVar13), (int)CONCAT71(extraout_var_01,cVar7) != 0)) {
            lVar13 = 0;
          }
          KeReleaseSpinLock(lVar3 + 0x10,uVar6);
          if (lVar13 != 0) {
            *(undefined8 *)(lVar13 + 0x38) = 0;
            RemoveReferenceAndCompleteRequest(param_1,lVar13,0xc0000120);
          }
          if ((int)uVar10 == 0x103) goto LAB_1c000cc9f;
          goto LAB_1c000cc91;
        }
      }
      goto LAB_1c000c433;
    }
LAB_1c000cc8e:
    uVar10 = 0;
LAB_1c000cc91:
    uVar14 = (undefined4)uVar10;
    lVar15 = param_2;
  }
  RemoveReferenceAndCompleteRequest(param_1,lVar15,uVar14);
LAB_1c000cc9f:
  RemoveReference(param_1);
  return uVar10;
}



===== WaveStopDpcHandler @ 1c000ccd0 =====

void WaveStopDpcHandler(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  
  lVar3 = *(longlong *)(param_3 + 0xb8);
  iVar5 = *(int *)(param_3 + 0x30);
  if (iVar5 < 0) {
LAB_1c000cde7:
    lVar3 = *(longlong *)(param_4 + 0x18);
LAB_1c000cdeb:
    RemoveReferenceAndCompleteRequest(lVar3,param_3,iVar5);
  }
  else {
    if (*(int *)(param_4 + 0x2f8) == 0) {
      *(undefined4 *)(param_4 + 0x2f8) = 1;
      *(undefined2 *)(lVar3 + -0x48) = 3;
      *(undefined4 *)(lVar3 + -0x40) = 1;
      lVar3 = *(longlong *)(param_3 + 0xb8);
      *(code **)(lVar3 + -0x10) = UniStopReceiveComplete;
      *(longlong *)(lVar3 + -8) = param_4;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      uVar4 = *(undefined8 *)(param_4 + 0x30);
    }
    else {
      if (*(int *)(param_4 + 0x2f8) != 1) goto LAB_1c000cdf3;
      pcVar2 = *(char **)(param_3 + 0x18);
      if (*(longlong *)(param_3 + 0x38) != 1) {
        *(undefined8 *)(param_3 + 0x38) = 0;
        iVar5 = -0x3fffffff;
        goto LAB_1c000cde7;
      }
      lVar1 = param_4 + 0x10;
      KeAcquireSpinLockAtDpcLevel(lVar1);
      if (*(int *)(param_4 + 0x2a8) == 0) {
        if (*pcVar2 == '\x10') {
          *(undefined4 *)(param_4 + 0x2a8) = 1;
        }
      }
      else {
        *(undefined4 *)(param_4 + 0x2a8) = 0;
        if (*(uint *)(param_4 + 0x2a4) < 0x28) {
          *(char *)((ulonglong)*(uint *)(param_4 + 0x2a4) + 0x27c + param_4) = *pcVar2;
          *(int *)(param_4 + 0x2a4) = *(int *)(param_4 + 0x2a4) + 1;
        }
        if (*pcVar2 == '\x03') {
          KeReleaseSpinLockFromDpcLevel(lVar1);
          *(undefined8 *)(param_3 + 0x38) = 0;
          lVar3 = *(longlong *)(param_4 + 0x18);
          iVar5 = 0;
          goto LAB_1c000cdeb;
        }
      }
      KeReleaseSpinLockFromDpcLevel(lVar1);
      *(undefined2 *)(lVar3 + -0x48) = 3;
      *(undefined4 *)(lVar3 + -0x40) = 1;
      lVar3 = *(longlong *)(param_3 + 0xb8);
      *(code **)(lVar3 + -0x10) = UniStopReceiveComplete;
      *(longlong *)(lVar3 + -8) = param_4;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      uVar4 = *(undefined8 *)(param_4 + 0x30);
    }
    IofCallDriver(uVar4,param_3);
  }
LAB_1c000cdf3:
  HandleDleIrp(param_4);
  return;
}



===== UniCancelShuttledWait @ 1c000ce70 =====

void UniCancelShuttledWait(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  undefined1 uVar2;
  
  plVar1 = *(longlong **)(*(longlong *)(param_2 + 0xb8) + 0x18);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar2 = KeAcquireSpinLockRaiseToDpc(*plVar1 + 0x10);
  *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x18) = 0x1b0048;
  UniRundownShuttledWait(*plVar1,plVar1 + 4,2,param_2,uVar2,0xc0000120,0);
  return;
}



===== UniChangeShuttledToPassDown @ 1c000cef4 =====

void UniChangeShuttledToPassDown(longlong *param_1,undefined1 param_2)

{
  longlong *plVar1;
  byte *pbVar2;
  longlong lVar3;
  undefined1 *puVar4;
  longlong lVar5;
  undefined1 local_res8 [8];
  
  plVar1 = param_1 + 4;
  local_res8[0] = 0;
  if (*plVar1 == 0) {
    KeReleaseSpinLock(*param_1 + 0x10);
  }
  else {
    IoAcquireCancelSpinLock(local_res8);
    lVar3 = *plVar1;
    if (*(longlong *)(lVar3 + 0x68) == 0) {
      IoReleaseCancelSpinLock(local_res8[0]);
      *plVar1 = 0;
      if (((longlong *)param_1[1])[4] != 0) {
        UniChangeShuttledToPassDown((longlong *)param_1[1],param_2);
        param_2 = KeAcquireSpinLockRaiseToDpc(*param_1 + 0x10);
      }
      UniRundownShuttledWait(*param_1,plVar1,1,lVar3,param_2,0xc0000120,0);
    }
    else {
      *(undefined8 *)(lVar3 + 0x68) = 0;
      lVar3 = *(longlong *)(*plVar1 + 0xb8);
      pbVar2 = (byte *)(lVar3 + 0x20);
      *pbVar2 = *pbVar2 & 0xfd;
      IoReleaseCancelSpinLock(CONCAT71((int7)((ulonglong)lVar3 >> 8),local_res8[0]));
      if (*(int *)(*param_1 + 0x7c) == 2) {
        UniMakeIrpShuttledWait(param_1,*plVar1,param_2,'\0');
      }
      else {
        puVar4 = *(undefined1 **)(*plVar1 + 0xb8);
        puVar4[0x20] = puVar4[0x20] & 0xfe;
        *(undefined4 *)(*(longlong *)(*plVar1 + 0xb8) + 0x18) = 0x1b0048;
        lVar3 = *plVar1;
        lVar5 = *(longlong *)(lVar3 + 0xb8);
        *(undefined1 *)(lVar5 + 0x21) = 0;
        *plVar1 = 0;
        param_1[5] = lVar3;
        param_1[6] = lVar5;
        puVar4[-0x48] = *puVar4;
        puVar4[-0x47] = puVar4[1];
        puVar4[-0x46] = puVar4[2];
        *(undefined4 *)(puVar4 + -0x30) = 0x1b0048;
        *(undefined4 *)(puVar4 + -0x40) = *(undefined4 *)(puVar4 + 8);
        *(undefined8 *)(puVar4 + -0x28) = *(undefined8 *)(puVar4 + 0x20);
        lVar3 = *(longlong *)(param_1[5] + 0xb8);
        *(code **)(lVar3 + -0x10) = UniGeneralWaitComplete;
        *(longlong **)(lVar3 + -8) = param_1;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        *(undefined4 *)(param_1[5] + 0x30) = 0;
        KeReleaseSpinLock(*param_1 + 0x10,CONCAT71((int7)((ulonglong)puVar4 >> 8),param_2));
        IofCallDriver(*(undefined8 *)(*param_1 + 0x30),param_1[5]);
      }
    }
  }
  return;
}



===== UniGeneralMaskComplete @ 1c000d0d0 =====

undefined8 UniGeneralMaskComplete(longlong param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(*param_3 + 0x10);
  *(int *)(param_3 + 2) = (int)param_3[2] + -1;
  *(int *)((longlong)param_3 + 0x14) = *(int *)((longlong)param_3 + 0x14) + -1;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(undefined4 **)(param_2 + 0x18);
  *puVar3 = *(undefined4 *)(lVar2 + 8);
  *(undefined4 *)(lVar2 + 8) = 0;
  if (-1 < *(int *)(param_2 + 0x30)) {
    uVar1 = **(uint **)(param_2 + 0x18);
    *(uint *)((longlong)param_3 + 0x1c) = *(uint *)((longlong)param_3 + 0x1c) & uVar1;
    *(uint *)(param_3 + 3) = uVar1;
  }
  KeReleaseSpinLock(*param_3 + 0x10,CONCAT71((int7)((ulonglong)puVar3 >> 8),uVar4));
  RemoveReference(param_1);
  return 0;
}



===== UniGeneralWaitComplete @ 1c000d170 =====

undefined8 UniGeneralWaitComplete(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  
  plVar4 = (longlong *)param_3[1];
  uVar2 = **(uint **)(param_2 + 0x18);
  uVar7 = KeAcquireSpinLockRaiseToDpc(*plVar4 + 0x10);
  if (*(char *)(*(longlong *)(param_2 + 0xb8) + 0x21) == '\0') {
    param_3[5] = 0;
    iVar3 = *(int *)(param_2 + 0x30);
    if (iVar3 == -0x3ffffff3) {
LAB_1c000d34a:
      *(undefined4 *)(param_2 + 0x30) = 0;
      *(undefined8 *)(param_2 + 0x38) = 0;
      UniMakeIrpShuttledWait(param_3,param_2,uVar7,'\0');
      return 0xc0000016;
    }
    if (iVar3 < 0) {
      if (iVar3 != -0x3ffffee0) {
        KeReleaseSpinLock(*plVar4 + 0x10);
        goto LAB_1c000d1ea;
      }
    }
    else {
      if (uVar2 == 0) goto LAB_1c000d34a;
      if ((uVar2 & *(uint *)(plVar4 + 3)) != 0) {
        plVar1 = plVar4 + 4;
        lVar5 = *plVar1;
        if (lVar5 == 0) {
          *(uint *)((longlong)plVar4 + 0x1c) =
               *(uint *)((longlong)plVar4 + 0x1c) | uVar2 & *(uint *)(plVar4 + 3);
        }
        else {
          *plVar1 = 0;
          param_3[5] = param_2;
          UniRundownShuttledWait(*plVar4,plVar1,1,lVar5,uVar7,0,*(uint *)(plVar4 + 3) & uVar2);
          uVar7 = KeAcquireSpinLockRaiseToDpc(*param_3 + 0x10);
          param_3[5] = 0;
        }
      }
      if ((*(uint *)(param_3 + 3) & uVar2) == 0) {
        if (*(uint *)(param_3 + 2) <= *(uint *)((longlong)param_3 + 0x14)) {
          lVar5 = *(longlong *)(param_2 + 0xb8);
          *(undefined1 *)(lVar5 + 0x21) = 0;
          param_3[5] = param_2;
          param_3[6] = lVar5;
          KeReleaseSpinLock(*param_3 + 0x10,uVar7);
          puVar6 = *(undefined8 **)(param_2 + 0xb8);
          puVar6[-9] = *puVar6;
          puVar6[-8] = puVar6[1];
          puVar6[-7] = puVar6[2];
          puVar6[-6] = puVar6[3];
          *(undefined4 *)(puVar6 + -5) = *(undefined4 *)(puVar6 + 4);
          *(undefined4 *)((longlong)puVar6 + -0x24) = *(undefined4 *)((longlong)puVar6 + 0x24);
          *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(puVar6 + 5);
          *(undefined4 *)((longlong)puVar6 + -0x1c) = *(undefined4 *)((longlong)puVar6 + 0x2c);
          puVar6[-3] = puVar6[6];
          *(undefined1 *)((longlong)puVar6 + -0x45) = 0;
          lVar5 = *(longlong *)(param_2 + 0xb8);
          *(code **)(lVar5 + -0x10) = UniGeneralWaitComplete;
          *(longlong **)(lVar5 + -8) = param_3;
          *(undefined1 *)(lVar5 + -0x45) = 0xe0;
          IofCallDriver(*(undefined8 *)(*param_3 + 0x30),param_2);
          return 0xc0000016;
        }
        **(undefined4 **)(param_2 + 0x18) = 0;
      }
    }
    UniChangeShuttledToPassDown(plVar4,uVar7);
  }
  else {
    KeReleaseSpinLock(*plVar4 + 0x10,uVar7);
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 4;
    **(undefined4 **)(param_2 + 0x18) = 0;
  }
LAB_1c000d1ea:
  RemoveReference(param_1);
  return 0;
}



===== UniMakeIrpShuttledWait @ 1c000d390 =====

undefined8
UniMakeIrpShuttledWait(longlong *param_1,longlong param_2,undefined1 param_3,char param_4)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 local_res10 [8];
  
  local_res10[0] = 0;
  IoAcquireCancelSpinLock(local_res10);
  if (*(char *)(param_2 + 0x44) == '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    param_1[4] = param_2;
    *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x20) = 0;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 0x20);
    *pbVar1 = *pbVar1 | 2;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 0x20);
    *pbVar1 = *pbVar1 | 1;
    *(longlong **)(*(longlong *)(param_2 + 0xb8) + 0x18) = param_1;
    LOCK();
    *(code **)(param_2 + 0x68) = UniCancelShuttledWait;
    UNLOCK();
    IoReleaseCancelSpinLock(local_res10[0]);
    KeReleaseSpinLock(*param_1 + 0x10,param_3);
    if (param_4 != '\0') {
      lVar2 = *param_1;
      UniGetNextIrp(*(longlong *)(lVar2 + 0x18),lVar2 + 0x10,(longlong *)(lVar2 + 0x98),
                    (longlong *)(lVar2 + 0x88));
    }
    uVar3 = 0x103;
  }
  else {
    IoReleaseCancelSpinLock(local_res10[0]);
    KeReleaseSpinLock(*param_1 + 0x10,param_3);
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    if (param_4 != '\0') {
      lVar2 = *param_1;
      UniGetNextIrp(*(longlong *)(lVar2 + 0x18),lVar2 + 0x10,(longlong *)(lVar2 + 0x98),
                    (longlong *)(lVar2 + 0x88));
    }
    uVar3 = 0xc0000120;
  }
  return uVar3;
}



===== UniMaskStarter @ 1c000d500 =====

undefined8 UniMaskStarter(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  uint *puVar6;
  longlong lVar7;
  undefined4 *puVar8;
  undefined1 uVar9;
  uint uVar10;
  longlong *plVar11;
  
  lVar1 = param_1 + 0x10;
  plVar3 = (longlong *)(param_1 + 0x98);
  lVar4 = *plVar3;
  puVar5 = *(undefined8 **)(lVar4 + 0xb8);
  puVar6 = *(uint **)(lVar4 + 0x18);
  plVar11 = (longlong *)
            ((ulonglong)(-(uint)(*(longlong *)(puVar5[6] + 0x18) != 0) & 0x38) + 0xa8 + param_1);
  lVar7 = plVar11[1];
  if (*(int *)(puVar5 + 3) == 0x1b0044) {
    if (3 < *(uint *)(puVar5 + 2)) {
      puVar5[-9] = *puVar5;
      puVar5[-8] = puVar5[1];
      puVar5[-7] = puVar5[2];
      puVar5[-6] = puVar5[3];
      *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
      *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
      *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
      *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
      puVar5[-3] = puVar5[6];
      *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
      lVar4 = *(longlong *)(*plVar3 + 0xb8);
      *(code **)(lVar4 + -0x10) = UniGeneralMaskComplete;
      *(longlong **)(lVar4 + -8) = plVar11;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      *(undefined4 *)(*(longlong *)(*plVar3 + 0xb8) + 8) = **(undefined4 **)(*plVar3 + 0x18);
      uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
      plVar2 = plVar11 + 4;
      uVar10 = 0x30;
      if (*(int *)(param_1 + 0x7c) != 2) {
        uVar10 = 0;
      }
      *puVar6 = *puVar6 | uVar10 | *(uint *)(lVar7 + 0x18);
      *(int *)((longlong)plVar11 + 0x14) = *(int *)((longlong)plVar11 + 0x14) + 1;
      lVar4 = *plVar2;
      if (lVar4 == 0) {
        if (plVar11[5] != 0) {
          *(undefined1 *)(plVar11[6] + 0x21) = 1;
          plVar11[5] = 0;
          plVar11[6] = 0;
        }
        KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar9));
      }
      else {
        *plVar2 = 0;
        UniRundownShuttledWait(param_1,plVar2,1,lVar4,uVar9,0,0);
      }
LAB_1c000d64e:
      IofCallDriver(*(undefined8 *)(param_1 + 0x30),*plVar3);
      goto LAB_1c000d7de;
    }
LAB_1c000d56f:
    *(undefined4 *)(lVar4 + 0x30) = 0xc0000023;
  }
  else {
    if (*(uint *)(puVar5 + 1) < 4) goto LAB_1c000d56f;
    if (((int)plVar11[3] == 0) &&
       ((*(longlong *)(puVar5[6] + 0x18) == 0 || (*(int *)(param_1 + 0x7c) != 2)))) {
      *(undefined4 *)(lVar4 + 0x30) = 0xc000000d;
    }
    else {
      uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1);
      if ((plVar11[4] == 0) && (plVar11[5] == 0)) {
        if (*(int *)((longlong)plVar11 + 0x1c) == 0) {
          if (*(uint *)(plVar11 + 2) <= *(uint *)((longlong)plVar11 + 0x14)) {
            if ((*(longlong *)(lVar7 + 0x28) != 0) || (*(int *)(param_1 + 0x7c) == 2)) {
              UniMakeIrpShuttledWait(plVar11,*plVar3,uVar9,'\x01');
              return 0x103;
            }
            lVar4 = *plVar3;
            lVar7 = *(longlong *)(lVar4 + 0xb8);
            *(undefined1 *)(lVar7 + 0x21) = 0;
            plVar11[6] = lVar7;
            plVar11[5] = lVar4;
            KeReleaseSpinLock(lVar1,uVar9);
            puVar5 = *(undefined8 **)(*plVar3 + 0xb8);
            puVar5[-9] = *puVar5;
            puVar5[-8] = puVar5[1];
            puVar5[-7] = puVar5[2];
            puVar5[-6] = puVar5[3];
            *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
            *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
            *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
            *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
            puVar5[-3] = puVar5[6];
            *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
            lVar4 = *(longlong *)(*plVar3 + 0xb8);
            *(code **)(lVar4 + -0x10) = UniGeneralWaitComplete;
            *(longlong **)(lVar4 + -8) = plVar11;
            *(undefined1 *)(lVar4 + -0x45) = 0xe0;
            goto LAB_1c000d64e;
          }
          puVar8 = *(undefined4 **)(*plVar3 + 0x18);
          *(undefined4 *)(*plVar3 + 0x30) = 0;
          *(undefined8 *)(*plVar3 + 0x38) = 4;
          *puVar8 = 0;
        }
        else {
          puVar8 = *(undefined4 **)(*plVar3 + 0x18);
          *(undefined4 *)(*plVar3 + 0x30) = 0;
          *(undefined8 *)(*plVar3 + 0x38) = 4;
          *puVar8 = *(undefined4 *)((longlong)plVar11 + 0x1c);
          *(undefined4 *)((longlong)plVar11 + 0x1c) = 0;
        }
        KeReleaseSpinLock(lVar1,uVar9);
        goto LAB_1c000d7de;
      }
      KeReleaseSpinLock(lVar1,uVar9);
      *(undefined4 *)(*plVar3 + 0x30) = 0xc000000d;
    }
  }
  *(undefined8 *)(*plVar3 + 0x38) = 0;
LAB_1c000d7de:
  UniGetNextIrp(*(longlong *)(param_1 + 0x18),lVar1,plVar3,(longlong *)(param_1 + 0x88));
  return 0x103;
}



===== UniRundownShuttledWait @ 1c000d830 =====

void UniRundownShuttledWait
               (longlong param_1,longlong *param_2,byte param_3,longlong param_4,undefined1 param_5,
               undefined4 param_6,undefined4 param_7)

{
  byte *pbVar1;
  char cVar2;
  undefined1 local_res18 [8];
  
  local_res18[0] = 0;
  if (**(char **)(param_4 + 0xb8) != '\x0e') {
    DbgPrint("MODEM: shuttled irp has bad major function\n");
  }
  pbVar1 = (byte *)(*(longlong *)(param_4 + 0xb8) + 0x20);
  *pbVar1 = *pbVar1 & ~param_3;
  IoAcquireCancelSpinLock(local_res18);
  if (*(longlong *)(param_4 + 0x68) != 0) {
    *(undefined8 *)(param_4 + 0x68) = 0;
    pbVar1 = (byte *)(*(longlong *)(param_4 + 0xb8) + 0x20);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  IoReleaseCancelSpinLock(local_res18[0]);
  if (*param_2 != 0) {
    *param_2 = 0;
    pbVar1 = (byte *)(*(longlong *)(param_4 + 0xb8) + 0x20);
    *pbVar1 = *pbVar1 & 0xfe;
  }
  cVar2 = *(char *)(*(longlong *)(param_4 + 0xb8) + 0x20);
  KeReleaseSpinLock(param_1 + 0x10,param_5);
  if (cVar2 == '\0') {
    *(undefined8 *)(param_4 + 0x38) = 4;
    **(undefined4 **)(param_4 + 0x18) = param_7;
    RemoveReferenceAndCompleteRequest(*(longlong *)(param_1 + 0x18),param_4,param_6);
  }
  return;
}



===== UniCleanup @ 1c000d930 =====

undefined8 UniCleanup(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong lVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if (*(int *)(lVar1 + 0x40) != 0) {
    uVar3 = KeAcquireSpinLockRaiseToDpc();
    plVar5 = (longlong *)(lVar1 + 200 + (ulonglong)(-(uint)(lVar2 != 0) & 0x38));
    lVar2 = *plVar5;
    if (lVar2 == 0) {
      KeReleaseSpinLock(lVar1 + 0x10,CONCAT71((int7)((ulonglong)plVar5 >> 8),uVar3));
    }
    else {
      *plVar5 = 0;
      UniRundownShuttledWait(lVar1,plVar5,1,lVar2,uVar3,0,0);
    }
    lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
    EmptyIpcQueue(lVar1,(longlong *)(lVar1 + 0x308 + lVar2 * 0x28));
    EmptyIpcQueue(lVar1,(longlong *)(lVar1 + 0x318 + lVar2 * 0x28));
    if (lVar2 == 1) {
      EmptyIpcQueue(lVar1,(longlong *)(lVar1 + 0x308));
    }
    lVar6 = 0x318;
    if (lVar2 != 1) {
      lVar6 = 0x340;
    }
    EmptyIpcQueue(lVar1,(longlong *)(lVar6 + lVar1));
    if (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) != 0) {
      CompletePowerWait(param_1,0xc0000120);
      uVar4 = ForwardIrp(*(undefined8 *)(lVar1 + 0x30),param_2);
      return uVar4;
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CleanUpQueuedIrps @ 1c000daa0 =====

void CleanUpQueuedIrps(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  int local_res10 [2];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res10[0]._1_3_ = (uint3)((ulonglong)param_2 >> 8);
  local_res10[0] = (uint)local_res10[0]._1_3_ << 8;
  uVar5 = KeAcquireSpinLockRaiseToDpc();
  puVar6 = auStack_28;
  plVar1 = (longlong *)(param_1 + 8);
  do {
    if ((longlong *)*plVar1 == plVar1) {
LAB_1c000db89:
      *(undefined8 *)(puVar6 + -8) = 0x1c000db96;
      KeReleaseSpinLock(param_1,uVar5);
      return;
    }
    puVar2 = *(undefined8 **)(param_1 + 0x10);
    if (((longlong *)*puVar2 != plVar1) ||
       (plVar3 = (longlong *)puVar2[1], (undefined8 *)*plVar3 != puVar2)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar6 = auStack_20;
      goto LAB_1c000db89;
    }
    *(longlong **)(param_1 + 0x10) = plVar3;
    *plVar3 = (longlong)plVar1;
    IoAcquireCancelSpinLock(local_res10);
    if (*(char *)((longlong)puVar2 + -100) == '\0') {
      LOCK();
      puVar2[-8] = 0;
      UNLOCK();
      IoReleaseCancelSpinLock((undefined1)local_res10[0]);
      KeReleaseSpinLock(param_1,uVar5);
      puVar2[-0xe] = 0;
      RemoveReferenceAndCompleteRequest(*(longlong *)(param_1 + 0x20),(longlong)(puVar2 + -0x15),0);
      uVar5 = KeAcquireSpinLockRaiseToDpc(param_1);
    }
    else {
      *(undefined4 *)(puVar2 + -0xf) = 0xc0000120;
      IoReleaseCancelSpinLock((undefined1)local_res10[0]);
    }
  } while( true );
}



===== HandleDleIrp @ 1c000dbb8 =====

void HandleDleIrp(longlong param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined7 extraout_var;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  
  lVar4 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x10);
  if ((*(int *)(param_1 + 0x2a4) != 0) && (*(longlong *)(param_1 + 0x2b0) != 0)) {
    cVar2 = HasIrpBeenCanceled(*(longlong *)(param_1 + 0x2b0));
    if ((int)CONCAT71(extraout_var,cVar2) == 0) {
      lVar4 = *(longlong *)(param_1 + 0x2b0);
      *(undefined8 *)(param_1 + 0x2b0) = 0;
      uVar5 = *(uint *)(*(longlong *)(lVar4 + 0xb8) + 8);
      uVar3 = *(uint *)(param_1 + 0x2a4);
      if (uVar5 <= *(uint *)(param_1 + 0x2a4)) {
        uVar3 = uVar5;
      }
      memcpy(*(void **)(lVar4 + 0x18),(void *)(param_1 + 0x27c),(ulonglong)uVar3);
      uVar5 = *(int *)(param_1 + 0x2a4) - uVar3;
      *(uint *)(param_1 + 0x2a4) = uVar5;
      memcpy((void *)(param_1 + 0x27c),(void *)(param_1 + 0x27c + (ulonglong)uVar3),(ulonglong)uVar5
            );
      *(ulonglong *)(lVar4 + 0x38) = (ulonglong)uVar3;
    }
  }
  KeReleaseSpinLock(param_1 + 0x10,uVar1);
  if (lVar4 != 0) {
    RemoveReferenceAndCompleteRequest(*(longlong *)(param_1 + 0x18),lVar4,0);
  }
  return;
}



===== IrpCancelRoutine @ 1c000dcb0 =====

void IrpCancelRoutine(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  uVar2 = *(undefined8 *)(param_2 + 0x38);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar6 = KeAcquireSpinLockRaiseToDpc(uVar2);
  if (*(int *)(param_2 + 0x30) == 0x103) {
    plVar1 = (longlong *)(param_2 + 0xa8);
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) != plVar1) ||
       (plVar4 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar4 != plVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
  }
  KeReleaseSpinLock(uVar2,uVar6);
  *(undefined8 *)(param_2 + 0x38) = 0;
  RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000120);
  return;
}



===== QueueIrp @ 1c000dd58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 QueueIrp(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar3 = KeAcquireSpinLockRaiseToDpc();
  puVar7 = auStack_28;
  plVar8 = (longlong *)(param_1 + 8);
  if ((*(longlong *)(param_1 + 0x18) == 0) && ((longlong *)*plVar8 == plVar8)) {
    *(longlong *)(param_1 + 0x18) = param_2;
    KeReleaseSpinLock(param_1,uVar3);
    uVar5 = (**(code **)(param_1 + 0x30))(param_1,*(undefined8 *)(param_1 + 0x20),param_2);
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    puVar4 = (undefined8 *)(param_2 + 0xa8);
    *(undefined4 *)(param_2 + 0x30) = 0x103;
    puVar6 = *(undefined8 **)(param_1 + 0x10);
    if ((longlong *)*puVar6 != plVar8) {
      puVar6 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      puVar4 = (undefined8 *)(*pcVar2)();
      puVar7 = auStack_20;
    }
    puVar4[1] = puVar6;
    *puVar4 = plVar8;
    *puVar6 = puVar4;
    plVar8[1] = (longlong)puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x1c000ddfe;
    IoAcquireCancelSpinLock(puVar7 + 0x30);
    *(longlong *)(param_2 + 0x38) = param_1;
    LOCK();
    uVar5 = *(undefined8 *)(param_2 + 0x68);
    *(undefined8 *)(param_2 + 0x68) = IrpCancelRoutine;
    UNLOCK();
    *(undefined8 *)(puVar7 + -8) = 0x1c000de1d;
    IoReleaseCancelSpinLock(CONCAT71((int7)((ulonglong)uVar5 >> 8),puVar7[0x30]));
    *(undefined8 *)(puVar7 + -8) = 0x1c000de2f;
    KeReleaseSpinLock(param_1,uVar3);
    uVar5 = 0x103;
  }
  return uVar5;
}



===== ReadIrpStarter @ 1c000de50 =====

undefined8 ReadIrpStarter(longlong param_1,undefined8 param_2,longlong param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  
  lVar3 = *(longlong *)(param_3 + 0xb8);
  *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)(param_3 + 0x18);
  uVar2 = *(undefined4 *)(lVar3 + 8);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = uVar2;
  puVar4 = *(undefined8 **)(param_3 + 0xb8);
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
  lVar3 = *(longlong *)(param_3 + 0xb8);
  *(code **)(lVar3 + -0x10) = UniReadComplete;
  *(longlong *)(lVar3 + -8) = param_1;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  IofCallDriver(*(undefined8 *)(param_1 + 0x40),param_3);
  return 0x103;
}



===== StartNextReadWriteIrp @ 1c000dee4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void StartNextReadWriteIrp(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong lVar5;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  uVar4 = KeAcquireSpinLockRaiseToDpc();
  *(undefined8 *)(param_1 + 0x18) = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 1;
    plVar1 = (longlong *)(param_1 + 8);
LAB_1c000df28:
    do {
      plVar2 = (longlong *)*plVar1;
      if (plVar2 == plVar1) {
LAB_1c000e017:
        *(undefined8 *)(param_1 + 0x18) = 0;
      }
      else {
        if (((longlong *)plVar2[1] != plVar1) ||
           (lVar5 = *plVar2, (longlong *)*(longlong *)(lVar5 + 8) != plVar2)) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        *plVar1 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar1;
        lVar5 = (longlong)(plVar2 + -0x15);
        IoAcquireCancelSpinLock(local_res8);
        if (*(char *)((longlong)plVar2 + -100) != '\0') {
          *(undefined4 *)(plVar2 + -0xf) = 0xc0000120;
          IoReleaseCancelSpinLock(local_res8[0]);
          goto LAB_1c000df28;
        }
        LOCK();
        plVar2[-8] = 0;
        UNLOCK();
        IoReleaseCancelSpinLock(local_res8[0]);
        *(longlong *)(param_1 + 0x18) = lVar5;
        if (lVar5 != 0) {
          if (*(int *)(param_1 + 0x38) != 0) {
            KeReleaseSpinLock(param_1,uVar4);
            RemoveReferenceAndCompleteRequest(*(longlong *)(param_1 + 0x20),lVar5,0xc0000120);
            uVar4 = KeAcquireSpinLockRaiseToDpc(param_1);
            goto LAB_1c000e017;
          }
          KeReleaseSpinLock();
          (**(code **)(param_1 + 0x30))(param_1,*(undefined8 *)(param_1 + 0x20),lVar5);
          uVar4 = KeAcquireSpinLockRaiseToDpc(param_1);
        }
      }
      if ((*(longlong *)(param_1 + 0x18) != 0) || ((longlong *)*plVar1 == plVar1))
      goto LAB_1c000e02c;
    } while( true );
  }
LAB_1c000e034:
  KeReleaseSpinLock(param_1,uVar4);
  return;
LAB_1c000e02c:
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  goto LAB_1c000e034;
}



===== UniRead @ 1c000e070 =====

ulonglong UniRead(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar4 = CheckStateAndAddReference(param_1,param_2);
  if ((int)uVar4 == 0) {
    lVar2 = *(longlong *)(lVar2 + 0x30);
    if ((*(longlong *)(lVar2 + 0x18) == 0) &&
       ((*(int *)(lVar1 + 0x7c) == 0 ||
        (*(longlong *)(lVar2 + 0x20) != (longlong)*(int *)(lVar1 + 0x80))))) {
      uVar4 = 0xc0000037;
      RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000037);
    }
    else if (*(char *)(lVar1 + 0x2ac) == '\0') {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x30));
      uVar4 = (ulonglong)uVar3;
      RemoveReference(param_1);
    }
    else {
      uVar4 = QueueIrp(lVar1 + 0x3b0,param_2);
      uVar4 = uVar4 & 0xffffffff;
    }
    RemoveReference(param_1);
  }
  return uVar4;
}



===== UniReadComplete @ 1c000e140 =====

undefined8 UniReadComplete(longlong param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  bool bVar6;
  undefined1 uVar7;
  uint uVar8;
  ulonglong uVar9;
  char *_Dst;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  if ((-1 < *(int *)(param_2 + 0x30)) && (*(char *)(lVar3 + 0x3a) == '\0')) {
    if ((*(ulonglong *)(param_2 + 0x38) == (ulonglong)*(uint *)(param_3 + 0x58)) &&
       (0x28 < *(uint *)(lVar4 + 8))) {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
    uVar1 = *(uint *)(param_2 + 0x38);
    _Dst = *(char **)(param_2 + 0x18);
    for (uVar8 = uVar1; uVar8 != 0; uVar8 = uVar8 - 1) {
      if (*(int *)(lVar3 + 0x2a8) == 0) {
        if (*_Dst == '\x10') {
          *(undefined4 *)(lVar3 + 0x2a8) = 1;
          memcpy(_Dst,_Dst + 1,(ulonglong)(uVar8 - 1));
          *(longlong *)(param_2 + 0x38) = *(longlong *)(param_2 + 0x38) + -1;
        }
        else {
          _Dst = _Dst + 1;
        }
      }
      else {
        if (*_Dst == '\x10') {
          _Dst = _Dst + 1;
        }
        else {
          uVar7 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x10);
          uVar2 = *(uint *)(lVar3 + 0x2a4);
          if (uVar2 < 0x28) {
            uVar9 = (ulonglong)uVar2;
            uVar2 = CONCAT31((int3)(uVar2 >> 8),*_Dst);
            *(char *)(uVar9 + 0x27c + lVar3) = *_Dst;
            *(int *)(lVar3 + 0x2a4) = *(int *)(lVar3 + 0x2a4) + 1;
          }
          KeReleaseSpinLock(lVar3 + 0x10,CONCAT31((int3)(uVar2 >> 8),uVar7));
          memcpy(_Dst,_Dst + 1,(ulonglong)(uVar8 - 1));
          *(longlong *)(param_2 + 0x38) = *(longlong *)(param_2 + 0x38) + -1;
        }
        *(undefined4 *)(lVar3 + 0x2a8) = 0;
      }
    }
    HandleDleIrp(lVar3);
    *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + *(int *)(param_2 + 0x38);
    if (((bVar6) && (*(ulonglong *)(param_2 + 0x38) != (ulonglong)uVar1)) ||
       ((*(longlong *)(param_2 + 0x38) == 0 && (uVar1 != 0)))) {
      puVar5 = *(undefined8 **)(param_2 + 0xb8);
      puVar5[-9] = *puVar5;
      puVar5[-8] = puVar5[1];
      puVar5[-7] = puVar5[2];
      puVar5[-6] = puVar5[3];
      *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
      *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
      *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
      *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
      puVar5[-3] = puVar5[6];
      *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
      *(longlong *)(param_2 + 0x18) = *(longlong *)(param_2 + 0x18) + *(longlong *)(param_2 + 0x38);
      *(int *)(lVar4 + -0x40) = *(int *)(lVar4 + 8) - *(int *)(param_3 + 0x5c);
      lVar3 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar3 + -0x10) = UniReadComplete;
      *(longlong *)(lVar3 + -8) = param_3;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      IofCallDriver(*(undefined8 *)(param_3 + 0x40),param_2);
      return 0xc0000016;
    }
  }
  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_3 + 0x50);
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(param_3 + 0x5c);
  StartNextReadWriteIrp(param_3);
  RemoveReference(param_1);
  return 0;
}



===== UniWrite @ 1c000e340 =====

ulonglong UniWrite(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar4 = CheckStateAndAddReference(param_1,param_2);
  if ((int)uVar4 == 0) {
    lVar2 = *(longlong *)(lVar2 + 0x30);
    if ((*(longlong *)(lVar2 + 0x18) == 0) &&
       ((*(int *)(lVar1 + 0x7c) == 0 ||
        (*(longlong *)(lVar2 + 0x20) != (longlong)*(int *)(lVar1 + 0x80))))) {
      uVar4 = 0xc0000037;
      RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000037);
    }
    else if (*(char *)(lVar1 + 0x2ad) == '\0') {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x30));
      uVar4 = (ulonglong)uVar3;
      RemoveReference(param_1);
    }
    else {
      uVar4 = QueueIrp(lVar1 + 0x350,param_2);
      uVar4 = uVar4 & 0xffffffff;
    }
    RemoveReference(param_1);
  }
  return uVar4;
}



===== UniWriteComplete @ 1c000e410 =====

undefined8 UniWriteComplete(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(uint *)(lVar2 + 0x1c) != 0) {
    if (*(int *)(param_2 + 0x30) < 0) goto LAB_1c000e4d6;
    if ((*(ulonglong *)(param_2 + 0x38) == (ulonglong)*(uint *)(lVar2 + 0x1c)) &&
       (*(char *)(*(longlong *)(param_1 + 0x40) + 0x3a) == '\0')) {
      pcVar3 = (char *)(*(ulonglong *)(param_2 + 0x38) + *(longlong *)(param_2 + 0x18));
      *(char **)(param_2 + 0x18) = pcVar3 + -1;
      pcVar4 = (char *)((ulonglong)*(uint *)(lVar2 + 8) + *(longlong *)(param_3 + 0x50));
      *(int *)(lVar2 + -0x40) = (int)pcVar4 - *(int *)(param_2 + 0x18);
      *(undefined4 *)(lVar2 + 0x1c) = 0;
      for (; pcVar3 < pcVar4; pcVar3 = pcVar3 + 1) {
        if (*pcVar3 == '\x10') {
          iVar1 = ((int)pcVar3 - *(int *)(param_2 + 0x18)) + 1;
          *(int *)(lVar2 + -0x40) = iVar1;
          *(int *)(lVar2 + 0x1c) = iVar1;
          break;
        }
      }
      if (*(int *)(lVar2 + -0x40) != 0) {
        lVar2 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar2 + -0x10) = UniWriteComplete;
        *(longlong *)(lVar2 + -8) = param_3;
        *(undefined1 *)(lVar2 + -0x45) = 0xe0;
        IofCallDriver(*(undefined8 *)(param_3 + 0x48));
        return 0xc0000016;
      }
    }
  }
  if (-1 < *(int *)(param_2 + 0x30)) {
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(lVar2 + 8);
  }
LAB_1c000e4d6:
  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_3 + 0x50);
  StartNextReadWriteIrp(param_3);
  RemoveReference(param_1);
  return 0;
}



===== WriteIrpStarter @ 1c000e500 =====

undefined8 WriteIrpStarter(longlong param_1,undefined8 param_2,longlong param_3)

{
  byte *pbVar1;
  undefined1 *puVar2;
  longlong lVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
  puVar2 = *(undefined1 **)(param_3 + 0xb8);
  puVar2[-0x48] = *puVar2;
  puVar2[-0x47] = puVar2[1];
  puVar2[-0x46] = puVar2[2];
  *(undefined4 *)(puVar2 + -0x40) = *(undefined4 *)(puVar2 + 8);
  *(undefined4 *)(puVar2 + -0x3c) = *(undefined4 *)(puVar2 + 0xc);
  *(undefined4 *)(puVar2 + -0x38) = *(undefined4 *)(puVar2 + 0x10);
  *(undefined4 *)(puVar2 + -0x34) = *(undefined4 *)(puVar2 + 0x14);
  *(undefined4 *)(puVar2 + -0x30) = *(undefined4 *)(puVar2 + 0x18);
  *(undefined4 *)(puVar2 + -0x2c) = *(undefined4 *)(puVar2 + 0x1c);
  *(undefined4 *)(puVar2 + -0x28) = *(undefined4 *)(puVar2 + 0x20);
  *(undefined4 *)(puVar2 + -0x24) = *(undefined4 *)(puVar2 + 0x24);
  *(undefined4 *)(puVar2 + 0x1c) = 0;
  *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)(param_3 + 0x18);
  pcVar5 = *(char **)(param_3 + 0x18);
  pcVar6 = pcVar5 + *(uint *)(puVar2 + 8);
  do {
    if (pcVar6 <= pcVar5) {
LAB_1c000e562:
      pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      lVar3 = *(longlong *)(param_3 + 0xb8);
      *(undefined4 *)(param_3 + 0x30) = 0x103;
      *(code **)(lVar3 + -0x10) = UniWriteComplete;
      *(longlong *)(lVar3 + -8) = param_1;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      IofCallDriver(*(undefined8 *)(param_1 + 0x48),param_3);
      return 0x103;
    }
    if (*pcVar5 == '\x10') {
      iVar4 = ((int)pcVar5 - *(int *)(param_3 + 0x18)) + 1;
      *(int *)(puVar2 + -0x40) = iVar4;
      *(int *)(puVar2 + 0x1c) = iVar4;
      goto LAB_1c000e562;
    }
    pcVar5 = pcVar5 + 1;
  } while( true );
}



===== UniCheckPassThrough @ 1c000e5b4 =====

ulonglong UniCheckPassThrough(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar2 + 0x7c) == 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar4 = 0xc0000037;
    RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000037);
  }
  else {
    iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if ((iVar1 - 0x1b0044U & 0xfffffffb) == 0) {
      uVar4 = UniStartOrQueue(lVar2,lVar2 + 0x10,param_2,(longlong *)(lVar2 + 0x88),
                              (longlong *)(lVar2 + 0x98),UniMaskStarter);
      return uVar4;
    }
    if (iVar1 == 0x1b0088) {
      uVar4 = UniValidateNewCommConfig(lVar2,param_2,'\0');
      return uVar4;
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(*(undefined8 *)(lVar2 + 0x30));
    uVar4 = (ulonglong)uVar3;
    RemoveReference(param_1);
  }
  return uVar4;
}



===== UniGetNextIrp @ 1c000e67c =====

void UniGetNextIrp(longlong param_1,undefined8 param_2,longlong *param_3,longlong *param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_2);
  puVar7 = auStack_28;
  plVar8 = (longlong *)*param_4;
  lVar2 = *param_3;
  if (plVar8 != param_4) {
    if (((longlong *)plVar8[1] == param_4) && (lVar3 = *plVar8, *(longlong **)(lVar3 + 8) == plVar8)
       ) {
      *param_4 = lVar3;
      plVar8 = plVar8 + -0x15;
      *(longlong **)(lVar3 + 8) = param_4;
      puVar7 = auStack_28;
      goto LAB_1c000e6e6;
    }
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3,uVar6);
    puVar7 = auStack_20;
  }
  plVar8 = (longlong *)0x0;
LAB_1c000e6e6:
  puVar4 = *(undefined8 **)(puVar7 + 0x50);
  *param_3 = (longlong)plVar8;
  *puVar4 = plVar8;
  *(undefined8 *)(puVar7 + -8) = 0x1c000e6fb;
  KeReleaseSpinLock(param_2);
  if ((puVar7[0x58] != '\0') && (lVar2 != 0)) {
    uVar1 = *(undefined4 *)(lVar2 + 0x30);
    *(undefined8 *)(puVar7 + -8) = 0x1c000e71b;
    RemoveReferenceAndCompleteRequest(param_1,lVar2,uVar1);
  }
  return;
}



===== UniPassThroughStarter @ 1c000e740 =====

undefined8 UniPassThroughStarter(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x68);
  uVar1 = **(uint **)(lVar2 + 0x18);
  if (uVar1 == 3) {
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
    **(undefined4 **)(lVar2 + 0x18) = 0;
LAB_1c000e775:
    if (*(int *)(param_1 + 0x7c) != 0) {
      UniSetupNoPassPart1((ulonglong)uVar1,lVar2,param_1);
      return 0x103;
    }
  }
  else {
    if (uVar1 == 0) goto LAB_1c000e775;
    if (uVar1 == 1) {
      if (*(int *)(param_1 + 0x7c) != 1) {
        UniSetupPass(1,lVar2,param_1);
        return 0x103;
      }
    }
    else {
      if (uVar1 != 2) {
        uVar5 = 0xc000000d;
        goto LAB_1c000e7bc;
      }
      if (*(int *)(param_1 + 0x7c) != 2) {
        lVar3 = *(longlong *)(lVar2 + 0xb8);
        *(undefined4 *)(param_1 + 0x7c) = 2;
        lVar4 = *(longlong *)(lVar2 + 0xb8);
        *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(lVar2 + 0x18);
        *(longlong *)(lVar2 + 0x18) = lVar4 + 0x20;
        *(undefined2 *)(lVar3 + -0x48) = 0xe;
        *(undefined4 *)(lVar3 + -0x40) = 0;
        *(undefined8 *)(lVar3 + -0x28) = 0;
        *(undefined1 *)(lVar3 + -0x46) = *(undefined1 *)(lVar3 + 2);
        *(undefined4 *)(lVar3 + -0x38) = 4;
        *(undefined4 *)(lVar3 + -0x30) = 0x1b0044;
        **(undefined4 **)(lVar2 + 0x18) = 0;
        lVar3 = *(longlong *)(lVar2 + 0xb8);
        *(code **)(lVar3 + -0x10) = UniSetupSniffPart1;
        *(longlong *)(lVar3 + -8) = param_1;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        IofCallDriver(*(undefined8 *)(param_1 + 0x30),lVar2);
        return 0x103;
      }
    }
  }
  uVar5 = 0;
LAB_1c000e7bc:
  *(undefined4 *)(lVar2 + 0x30) = uVar5;
  *(undefined8 *)(lVar2 + 0x38) = 0;
  UniGetNextIrp(*(longlong *)(param_1 + 0x18),param_1 + 0x10,(longlong *)(param_1 + 0x68),
                (longlong *)(param_1 + 0x58));
  return 0x103;
}



===== UniSendOurWaitDown @ 1c000e88c =====

void UniSendOurWaitDown(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  LOCK();
  lVar1 = *(longlong *)(param_1 + 0xa0);
  *(longlong *)(param_1 + 0xa0) = 0;
  UNLOCK();
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(undefined8 *)(lVar2 + 0x18) = 0;
  *(longlong *)(lVar1 + 0x18) = lVar2 + 0x20;
  *(undefined2 *)(lVar2 + -0x48) = 0xe;
  *(undefined4 *)(lVar2 + -0x40) = 4;
  *(undefined4 *)(lVar2 + -0x38) = 0;
  *(undefined4 *)(lVar2 + -0x30) = 0x1b0048;
  *(undefined8 *)(lVar2 + -0x28) = 0;
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(undefined2 *)(lVar1 + 0x44) = 0;
  *(undefined8 *)(lVar1 + 0x68) = 0;
  *(code **)(lVar2 + -0x10) = UniSniffWaitComplete;
  *(longlong *)(lVar2 + -8) = param_1;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  LOCK();
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  UNLOCK();
  IofCallDriver(*(undefined8 *)(param_1 + 0x30));
  return;
}



===== UniSetupNoPassPart1 @ 1c000e914 =====

undefined8 UniSetupNoPassPart1(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  uint uVar6;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar1 = param_3 + 0x10;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  iVar2 = *(int *)(param_3 + 0x7c);
  *(undefined4 *)(param_3 + 0x7c) = 0;
  if (iVar2 == 2) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(param_2 + 0x18);
    *(longlong *)(param_2 + 0x18) = lVar4 + 0x20;
    *(undefined2 *)(lVar3 + -0x48) = 0xe;
    *(undefined1 *)(lVar3 + -0x46) = *(undefined1 *)(lVar3 + 2);
    *(undefined4 *)(lVar3 + -0x40) = 0;
    *(undefined4 *)(lVar3 + -0x38) = 4;
    *(undefined4 *)(lVar3 + -0x30) = 0x1b0044;
    *(undefined8 *)(lVar3 + -0x28) = 0;
    uVar6 = *(uint *)(param_3 + 0xf8) | *(uint *)(param_3 + 0xc0);
    **(uint **)(param_2 + 0x18) = uVar6;
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar3 + -0x10) = UniSetupNoPassPart2;
    *(longlong *)(lVar3 + -8) = param_3;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    KeReleaseSpinLock(lVar1,CONCAT31((int3)(uVar6 >> 8),uVar5));
    IofCallDriver(*(undefined8 *)(param_3 + 0x30),param_2);
  }
  else {
    KeReleaseSpinLock(lVar1,uVar5);
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(param_2 + 0x18);
    *(longlong *)(param_2 + 0x18) = lVar1 + 0x20;
    UniSetupNoPassPart2(*(undefined8 *)(param_3 + 0x30),param_2,param_3);
  }
  return 0xc0000016;
}



===== UniSetupNoPassPart2 @ 1c000ea50 =====

undefined8 UniSetupNoPassPart2(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(undefined1 *)(lVar1 + -0x46) = 0;
  *(undefined4 *)(lVar1 + -0x40) = 0;
  *(undefined8 *)(lVar1 + -0x28) = 0;
  *(undefined2 *)(lVar1 + -0x48) = 0xe;
  *(undefined4 *)(lVar1 + -0x38) = 4;
  *(undefined4 *)(lVar1 + -0x30) = 0x1b004c;
  **(undefined4 **)(param_2 + 0x18) = 3;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar1 + -0x10) = UniSetupNoPassPart3;
  *(longlong *)(lVar1 + -8) = param_3;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  IofCallDriver(*(undefined8 *)(param_3 + 0x30));
  return 0xc0000016;
}



===== UniSetupNoPassPart3 @ 1c000eac0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000eb1c) */

undefined8 UniSetupNoPassPart3(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong *plVar4;
  
  lVar1 = param_3 + 0x10;
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (lVar2 != 0) {
    *(longlong *)(param_2 + 0x18) = lVar2;
    *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x18) = 0x2b0008;
    UniGetNextIrp(*(longlong *)(param_3 + 0x18),lVar1,(longlong *)(param_3 + 0x68),
                  (longlong *)(param_3 + 0x58));
    return 0xc0000016;
  }
  *(longlong *)(param_3 + 0xa0) = param_2;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (((*(int *)(param_3 + 0x7c) == 2) || (*(longlong *)(param_3 + 0xd0) != 0)) ||
     (*(longlong *)(param_3 + 0x108) != 0)) {
LAB_1c000eb85:
    KeReleaseSpinLock(lVar1,uVar3);
  }
  else {
    if (*(longlong *)(param_3 + 200) == 0) {
      if (*(longlong *)(param_3 + 0x100) == 0) goto LAB_1c000eb85;
      plVar4 = (longlong *)(param_3 + 0xe0);
    }
    else {
      plVar4 = (longlong *)(param_3 + 0xa8);
    }
    UniChangeShuttledToPassDown(plVar4,uVar3);
  }
  return 0xc0000016;
}



===== UniSetupPass @ 1c000ebac =====

undefined8 UniSetupPass(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  uint uVar6;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar1 = param_3 + 0x10;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  iVar2 = *(int *)(param_3 + 0x7c);
  *(undefined4 *)(param_3 + 0x7c) = 1;
  if (iVar2 == 2) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(param_2 + 0x18);
    *(longlong *)(param_2 + 0x18) = lVar4 + 0x20;
    *(undefined2 *)(lVar3 + -0x48) = 0xe;
    *(undefined4 *)(lVar3 + -0x40) = 0;
    *(undefined8 *)(lVar3 + -0x28) = 0;
    *(undefined1 *)(lVar3 + -0x46) = *(undefined1 *)(lVar3 + 2);
    *(undefined4 *)(lVar3 + -0x38) = 4;
    *(undefined4 *)(lVar3 + -0x30) = 0x1b0044;
    uVar6 = *(uint *)(param_3 + 0xf8) | *(uint *)(param_3 + 0xc0);
    **(uint **)(param_2 + 0x18) = uVar6;
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar3 + -0x10) = UniSetupNoPassPart3;
    *(longlong *)(lVar3 + -8) = param_3;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    KeReleaseSpinLock(lVar1,CONCAT31((int3)(uVar6 >> 8),uVar5));
    IofCallDriver(*(undefined8 *)(param_3 + 0x30),param_2);
  }
  else {
    KeReleaseSpinLock(lVar1);
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(param_2 + 0x18);
    *(longlong *)(param_2 + 0x18) = lVar1 + 0x20;
    UniSetupNoPassPart3(*(undefined8 *)(param_3 + 0x30),param_2,param_3);
  }
  return 0xc0000016;
}



===== UniSetupSniffPart1 @ 1c000ecf0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000ed60) */

undefined8 UniSetupSniffPart1(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((*(uint *)(param_2 + 0x30) & 0xc0000000) == 0xc0000000) {
    *(undefined4 *)(param_3 + 0x7c) = 1;
    *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x18) = 0x2b0008;
    UniGetNextIrp(*(longlong *)(param_3 + 0x18),param_3 + 0x10,(longlong *)(param_3 + 0x68),
                  (longlong *)(param_3 + 0x58));
  }
  else {
    *(undefined2 *)(lVar1 + -0x48) = 0xe;
    *(undefined4 *)(lVar1 + -0x40) = 0;
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined1 *)(lVar1 + -0x46) = *(undefined1 *)(lVar1 + 2);
    *(undefined4 *)(lVar1 + -0x38) = 4;
    *(undefined4 *)(lVar1 + -0x30) = 0x1b0044;
    **(uint **)(param_2 + 0x18) = *(uint *)(param_3 + 0xf8) | *(uint *)(param_3 + 0xc0) | 0x30;
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar1 + -0x10) = UniSetupSniffPart2;
    *(longlong *)(lVar1 + -8) = param_3;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    IofCallDriver(*(undefined8 *)(param_3 + 0x30));
  }
  return 0xc0000016;
}



===== UniSetupSniffPart2 @ 1c000ede0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000ee58) */

undefined8 UniSetupSniffPart2(undefined8 param_1,longlong param_2,longlong param_3)

{
  if ((*(uint *)(param_2 + 0x30) & 0xc0000000) == 0xc0000000) {
    *(undefined4 *)(param_3 + 0x7c) = 1;
  }
  else {
    UniSendOurWaitDown(param_3);
  }
  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x18) = 0x2b0008;
  UniGetNextIrp(*(longlong *)(param_3 + 0x18),param_3 + 0x10,(longlong *)(param_3 + 0x68),
                (longlong *)(param_3 + 0x58));
  return 0xc0000016;
}



===== UniSniffOwnerSettings @ 1c000ee78 =====

ulonglong UniSniffOwnerSettings(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  code *pcVar6;
  longlong *plVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar3 = *(uint *)(lVar2 + 0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if ((uVar3 & 0xffff0000) != 0x2b0000) {
    if ((*(int *)(lVar2 + 0x18) - 0x1b0044U & 0xfffffffb) == 0) {
      plVar4 = (longlong *)(lVar1 + 0x98);
      plVar7 = (longlong *)(lVar1 + 0x88);
      pcVar6 = UniMaskStarter;
LAB_1c000ef8f:
      uVar5 = UniStartOrQueue(lVar1,lVar1 + 0x10,param_2,plVar7,plVar4,pcVar6);
      return uVar5;
    }
    if (*(int *)(lVar2 + 0x18) == 0x1b0088) {
      uVar5 = UniValidateNewCommConfig(lVar1,param_2,'\x01');
      return uVar5;
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = lVar2 + 0x48;
    uVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x30),param_2);
    RemoveReference(param_1);
    goto LAB_1c000eeec;
  }
  if (uVar3 == 0x2b0008) {
    if (3 < *(uint *)(lVar2 + 0x10)) {
      plVar4 = (longlong *)(lVar1 + 0x68);
      plVar7 = (longlong *)(lVar1 + 0x58);
      pcVar6 = UniPassThroughStarter;
      goto LAB_1c000ef8f;
    }
LAB_1c000eed9:
    uVar3 = 0xc0000023;
  }
  else {
    if (uVar3 == 0x2b0004) {
      if (3 < *(uint *)(lVar2 + 8)) {
        **(undefined4 **)(param_2 + 0x18) = *(undefined4 *)(lVar1 + 0x7c);
        *(undefined8 *)(param_2 + 0x38) = 4;
        RemoveReferenceAndCompleteRequest(param_1,param_2,0);
        return 0;
      }
      goto LAB_1c000eed9;
    }
    uVar3 = 0xc000000d;
  }
  RemoveReferenceAndCompleteRequest(param_1,param_2,uVar3);
LAB_1c000eeec:
  return (ulonglong)uVar3;
}



===== UniSniffWaitComplete @ 1c000efc0 =====

undefined8 UniSniffWaitComplete(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  longlong *plVar9;
  longlong lVar10;
  undefined7 uVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined8 local_98 [4];
  longlong local_78 [10];
  
  lVar1 = param_3 + 0x10;
  *(longlong *)(param_3 + 0xa0) = param_2;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (*(int *)(param_2 + 0x30) < 0) {
    uVar16 = 0xffffffff;
  }
  else {
    uVar16 = **(uint **)(param_2 + 0x18);
    if (uVar16 == 0) {
      uVar11 = (undefined7)((ulonglong)*(uint **)(param_2 + 0x18) >> 8);
      if (*(int *)(param_3 + 0x7c) == 2) {
        KeReleaseSpinLock(lVar1,CONCAT71(uVar11,uVar8));
        UniSendOurWaitDown(param_3);
        goto LAB_1c000f19f;
      }
      if ((*(longlong *)(param_3 + 0xd0) == 0) && (*(longlong *)(param_3 + 0x108) == 0)) {
        if (*(longlong *)(param_3 + 200) == 0) {
          if (*(longlong *)(param_3 + 0x100) == 0) goto LAB_1c000f08a;
          plVar9 = (longlong *)(param_3 + 0xe0);
        }
        else {
          plVar9 = (longlong *)(param_3 + 0xa8);
        }
        UniChangeShuttledToPassDown(plVar9,uVar8);
      }
      else {
LAB_1c000f08a:
        KeReleaseSpinLock(lVar1,CONCAT71(uVar11,uVar8));
      }
      goto LAB_1c000f19f;
    }
  }
  iVar15 = 2;
  puVar13 = local_98;
  puVar12 = (undefined8 *)(param_3 + 0xa8);
  iVar14 = 2;
  memset(local_98,0,0x70);
  do {
    if ((*(uint *)(puVar12 + 3) & uVar16) != 0) {
      if (puVar12[4] == 0) {
        *(uint *)((longlong)puVar12 + 0x1c) =
             *(uint *)((longlong)puVar12 + 0x1c) | *(uint *)(puVar12 + 3) & uVar16;
      }
      else {
        uVar2 = puVar12[1];
        uVar4 = puVar12[2];
        uVar5 = puVar12[3];
        *puVar13 = *puVar12;
        puVar13[1] = uVar2;
        uVar6 = puVar12[4];
        uVar7 = puVar12[5];
        puVar13[2] = uVar4;
        puVar13[3] = uVar5;
        uVar2 = puVar12[6];
        puVar12[4] = 0;
        puVar13[4] = uVar6;
        puVar13[5] = uVar7;
        puVar13[6] = uVar2;
        puVar13 = puVar13 + 7;
      }
    }
    puVar12 = puVar12 + 7;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  lVar10 = lVar1;
  KeReleaseSpinLock();
  if ((uVar16 & 0x30) == 0) {
    UniSendOurWaitDown(param_3);
  }
  else {
    LOCK();
    lVar3 = *(longlong *)(param_3 + 0xa0);
    *(longlong *)(param_3 + 0xa0) = 0;
    UNLOCK();
    *(undefined8 *)(lVar3 + 0x18) = 0;
    UniSetupNoPassPart1(lVar10,lVar3,param_3);
  }
  plVar9 = local_78;
  do {
    lVar10 = *plVar9;
    if (lVar10 != 0) {
      *plVar9 = 0;
      uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
      UniRundownShuttledWait(param_3,plVar9,1,lVar10,uVar8,0,*(uint *)(plVar9 + -1) & uVar16);
    }
    plVar9 = plVar9 + 7;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
LAB_1c000f19f:
  RemoveReference(*(longlong *)(param_3 + 0x18));
  return 0xc0000016;
}



===== UniStartOrQueue @ 1c000f1d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UniStartOrQueue(longlong param_1,undefined8 param_2,longlong param_3,longlong *param_4,
               longlong *param_5,undefined *param_6)

{
  byte *pbVar1;
  int *piVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar3 = *(longlong *)(param_3 + 0xb8);
  uVar5 = KeAcquireSpinLockRaiseToDpc();
  puVar8 = auStack_28;
  if (*(int *)(lVar3 + 0x18) == 0x1b0044) {
    piVar2 = (int *)((ulonglong)
                     (-(uint)(*(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18) != 0) & 0x38) + 0xb8
                    + param_1);
    *piVar2 = *piVar2 + 1;
  }
  if (((longlong *)*param_4 == param_4) && (*param_5 == 0)) {
    *param_5 = param_3;
    KeReleaseSpinLock(param_2);
    pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    (*(code *)param_6)(param_1);
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    puVar6 = (undefined8 *)(param_3 + 0xa8);
    plVar7 = (longlong *)param_4[1];
    if ((longlong *)*plVar7 != param_4) {
      plVar7 = (longlong *)0x3;
      pcVar4 = (code *)swi(0x29);
      puVar6 = (undefined8 *)(*pcVar4)(3,uVar5);
      puVar8 = auStack_20;
    }
    puVar6[1] = plVar7;
    *puVar6 = param_4;
    *plVar7 = (longlong)puVar6;
    param_4[1] = (longlong)puVar6;
    *(undefined8 *)(puVar8 + -8) = 0x1c000f2ad;
    KeReleaseSpinLock(param_2);
  }
  return 0x103;
}



===== UniValidateNewCommConfig @ 1c000f2dc =====

undefined8 UniValidateNewCommConfig(longlong param_1,longlong param_2,char param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x60) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    RemoveReferenceAndCompleteRequest(*(longlong *)(param_1 + 0x18),param_2,0xc0000023);
    uVar4 = 0xc0000023;
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x10);
    uVar1 = *(uint *)(lVar2 + 0x40);
    uVar5 = *(uint *)(param_1 + 0x148);
    if ((uVar1 <= *(uint *)(param_1 + 0x148)) && (uVar5 = uVar1, uVar1 == 0)) {
      uVar5 = 1;
    }
    *(uint *)(param_1 + 0x178) = uVar5;
    uVar1 = *(uint *)(lVar2 + 0x44);
    uVar5 = *(uint *)(param_1 + 0x14c);
    if ((uVar1 <= *(uint *)(param_1 + 0x14c)) && (uVar5 = uVar1, uVar1 == 0xffffffff)) {
      uVar5 = 0;
    }
    *(uint *)(param_1 + 0x17c) = uVar5;
    if ((*(uint *)(param_1 + 0x150) >> (*(uint *)(lVar2 + 0x48) & 0x1f) & 1) != 0) {
      *(uint *)(param_1 + 0x180) = *(uint *)(lVar2 + 0x48);
    }
    if ((*(uint *)(param_1 + 0x154) >> (*(uint *)(lVar2 + 0x4c) & 0x1f) & 1) != 0) {
      *(uint *)(param_1 + 0x184) = *(uint *)(lVar2 + 0x4c);
    }
    *(uint *)(param_1 + 0x188) = *(uint *)(lVar2 + 0x50) & *(uint *)(param_1 + 0x158);
    if (param_3 != '\0') {
      *(undefined4 *)(param_1 + 0x18c) = *(undefined4 *)(lVar2 + 0x54);
      *(undefined4 *)(param_1 + 400) = *(undefined4 *)(lVar2 + 0x58);
    }
    KeReleaseSpinLock(param_1 + 0x10,CONCAT31((int3)(uVar1 >> 8),uVar3));
    *(undefined8 *)(param_2 + 0x38) = 0;
    RemoveReferenceAndCompleteRequest(*(longlong *)(param_1 + 0x18),param_2,0);
    uVar4 = 0;
  }
  return uVar4;
}



===== EmptyIpcQueue @ 1c000f418 =====

void EmptyIpcQueue(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  lVar1 = param_1 + 0x10;
  while( true ) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    IoAcquireCancelSpinLock(local_res8);
    puVar4 = GetUsableIrp(param_2);
    if (puVar4 == (undefined8 *)0x0) break;
    LOCK();
    uVar2 = puVar4[0xd];
    puVar4[0xd] = 0;
    UNLOCK();
    IoReleaseCancelSpinLock(CONCAT71((int7)((ulonglong)uVar2 >> 8),local_res8[0]));
    KeReleaseSpinLock(lVar1,uVar3);
    puVar4[7] = 0;
    RemoveReferenceAndCompleteRequest(*(longlong *)(param_1 + 0x18),(longlong)puVar4,0xc0000120);
  }
  IoReleaseCancelSpinLock(local_res8[0]);
  KeReleaseSpinLock(lVar1,uVar3);
  return;
}



===== GetPutCancelRoutine @ 1c000f4f0 =====

void GetPutCancelRoutine(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x10);
  if (*(int *)(param_2 + 0x30) == 0x103) {
    plVar1 = (longlong *)(param_2 + 0xa8);
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) != plVar1) ||
       (plVar4 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar4 != plVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
  }
  KeReleaseSpinLock(lVar2 + 0x10,uVar6);
  *(undefined8 *)(param_2 + 0x38) = 0;
  RemoveReferenceAndCompleteRequest(param_1,param_2,0xc0000120);
  return;
}



===== GetUsableIrp @ 1c000f598 =====

undefined8 * GetUsableIrp(longlong *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  code *pcVar3;
  
  while( true ) {
    if ((longlong *)*param_1 == param_1) {
      return (undefined8 *)0x0;
    }
    plVar1 = (longlong *)param_1[1];
    if (((longlong *)*plVar1 != param_1) ||
       (puVar2 = (undefined8 *)plVar1[1], (longlong *)*puVar2 != plVar1)) break;
    param_1[1] = (longlong)puVar2;
    *puVar2 = param_1;
    if (*(char *)((longlong)plVar1 + -100) == '\0') {
      return plVar1 + -0x15;
    }
    *(undefined4 *)(plVar1 + -0xf) = 0xc0000120;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return (undefined8 *)0x0;
}



===== HandleIpc @ 1c000f5e0 =====

void HandleIpc(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  longlong *plVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined1 local_res8 [8];
  
  lVar1 = param_1 + 0x10;
  local_res8[0] = 0;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar13 = 0;
  lVar9 = param_1 + 0x308;
  uVar11 = 1;
  do {
    IoAcquireCancelSpinLock(local_res8);
    plVar10 = (longlong *)(param_1 + (uVar11 * 5 + 0x61) * 8);
    puVar7 = GetUsableIrp(plVar10);
    if (puVar7 == (undefined8 *)0x0) {
LAB_1c000f7c2:
      IoReleaseCancelSpinLock(local_res8[0]);
    }
    else {
      puVar8 = GetUsableIrp((longlong *)(param_1 + (uVar13 * 5 + 99) * 8));
      if (puVar8 == (undefined8 *)0x0) {
        lVar4 = *plVar10;
        plVar3 = puVar7 + 0x15;
        if (*(longlong **)(lVar4 + 8) != plVar10) {
LAB_1c000f815:
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
        *plVar3 = lVar4;
        puVar7[0x16] = plVar10;
        *(longlong **)(lVar4 + 8) = plVar3;
        *plVar10 = (longlong)plVar3;
        goto LAB_1c000f7c2;
      }
      LOCK();
      puVar7[0xd] = 0;
      UNLOCK();
      LOCK();
      uVar2 = puVar8[0xd];
      puVar8[0xd] = 0;
      UNLOCK();
      IoReleaseCancelSpinLock(CONCAT71((int7)((ulonglong)uVar2 >> 8),local_res8[0]));
      KeReleaseSpinLock(lVar1,uVar6);
      uVar12 = *(uint *)(puVar8[0x17] + 0x10);
      if (*(uint *)(puVar7[0x17] + 8) <= *(uint *)(puVar8[0x17] + 0x10)) {
        uVar12 = *(uint *)(puVar7[0x17] + 8);
      }
      memcpy((void *)puVar7[3],(void *)puVar8[3],(ulonglong)uVar12);
      puVar7[7] = (ulonglong)uVar12;
      RemoveReferenceAndCompleteRequest(*(longlong *)(param_1 + 0x18),(longlong)puVar7,0);
      if (*(int *)(puVar8[0x17] + 0x18) == 0x2b0024) {
        uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
        *(undefined4 *)(puVar8 + 6) = 0x103;
        plVar10 = puVar8 + 0x15;
        plVar3 = *(longlong **)(lVar9 + 8);
        if (*plVar3 != lVar9) goto LAB_1c000f815;
        *plVar10 = lVar9;
        puVar8[0x16] = plVar3;
        *plVar3 = (longlong)plVar10;
        *(longlong **)(lVar9 + 8) = plVar10;
        IoAcquireCancelSpinLock(local_res8);
        LOCK();
        puVar8[0xd] = GetPutCancelRoutine;
        UNLOCK();
        IoReleaseCancelSpinLock(local_res8[0]);
        KeReleaseSpinLock(lVar1,uVar6);
        HandleIpc(param_1);
      }
      else {
        puVar8[7] = 0;
        RemoveReferenceAndCompleteRequest(*(longlong *)(param_1 + 0x18),(longlong)puVar8,0);
      }
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    }
    uVar12 = (int)uVar13 + 1;
    uVar13 = (ulonglong)uVar12;
    lVar9 = lVar9 + 0x28;
    uVar11 = (ulonglong)((int)uVar11 - 1);
    if (1 < uVar12) {
      KeReleaseSpinLock(lVar1,uVar6);
      return;
    }
  } while( true );
}



===== QueueLoopbackMessageIrp @ 1c000f824 =====

void QueueLoopbackMessageIrp(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar1 = *(int *)(*(longlong *)(lVar2 + 0x30) + 0x18);
  *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 1;
  *(undefined4 *)(param_2 + 0x30) = 0x103;
  lVar7 = (-(ulonglong)(iVar1 != 0) & 0xffffffffffffffd8) + 0x340 + param_1;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x10,param_2,lVar2,-iVar1);
  puVar8 = auStack_38;
  plVar6 = *(longlong **)(lVar7 + 8);
  plVar5 = (longlong *)(param_2 + 0xa8);
  if (*plVar6 != lVar7) {
    plVar5 = (longlong *)0x3;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)();
    puVar8 = auStack_30;
  }
  *plVar5 = lVar7;
  plVar5[1] = (longlong)plVar6;
  *plVar6 = (longlong)plVar5;
  *(longlong **)(lVar7 + 8) = plVar5;
  *(undefined8 *)(puVar8 + -8) = 0x1c000f8b4;
  IoAcquireCancelSpinLock(puVar8 + 0x40);
  LOCK();
  *(code **)(param_2 + 0x68) = GetPutCancelRoutine;
  UNLOCK();
  *(undefined8 *)(puVar8 + -8) = 0x1c000f8cf;
  IoReleaseCancelSpinLock(puVar8[0x40]);
  *(undefined8 *)(puVar8 + -8) = 0x1c000f8e2;
  KeReleaseSpinLock(param_1 + 0x10,uVar4);
  *(undefined8 *)(puVar8 + -8) = 0x1c000f8ef;
  HandleIpc(param_1);
  return;
}



===== QueueMessageIrp @ 1c000f90c =====

void QueueMessageIrp(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  longlong lVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar1 = *(uint *)(*(longlong *)(lVar2 + 0x30) + 0x18);
  *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 1;
  *(undefined4 *)(param_2 + 0x30) = 0x103;
  lVar8 = 0x308;
  if (*(int *)(lVar2 + 0x18) != 0x2b0020) {
    lVar8 = 0x318;
  }
  lVar2 = param_1 + lVar8 + (ulonglong)uVar1 * 0x28;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x10);
  puVar7 = auStack_38;
  plVar6 = *(longlong **)(lVar2 + 8);
  plVar5 = (longlong *)(param_2 + 0xa8);
  if (*plVar6 != lVar2) {
    plVar5 = (longlong *)0x3;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)();
    puVar7 = auStack_30;
  }
  *plVar5 = lVar2;
  plVar5[1] = (longlong)plVar6;
  *plVar6 = (longlong)plVar5;
  *(longlong **)(lVar2 + 8) = plVar5;
  *(undefined8 *)(puVar7 + -8) = 0x1c000f9a9;
  IoAcquireCancelSpinLock(puVar7 + 0x40);
  LOCK();
  *(code **)(param_2 + 0x68) = GetPutCancelRoutine;
  UNLOCK();
  *(undefined8 *)(puVar7 + -8) = 0x1c000f9c4;
  IoReleaseCancelSpinLock(puVar7[0x40]);
  *(undefined8 *)(puVar7 + -8) = 0x1c000f9d7;
  KeReleaseSpinLock(param_1 + 0x10,uVar4);
  *(undefined8 *)(puVar7 + -8) = 0x1c000f9e4;
  HandleIpc(param_1);
  return;
}



===== entry @ 1c0010010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0010044 =====

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



===== DriverEntry @ 1c0010078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1,ushort *param_2)

{
  void *pvVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 auStack_158 [32];
  undefined8 local_138;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined1 local_108 [8];
  undefined4 local_100;
  wchar_t *local_f8;
  undefined4 *local_f0;
  undefined4 local_e8;
  undefined4 *local_e0;
  undefined4 local_d8;
  undefined4 local_c8;
  wchar_t *local_c0;
  undefined4 *local_b8;
  undefined4 local_b0;
  undefined4 *local_a8;
  undefined4 local_a0;
  undefined4 local_90;
  wchar_t *local_88;
  undefined4 *local_80;
  undefined4 local_78;
  undefined4 *local_70;
  undefined4 local_68;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_158;
  _DriverEntryRegPath = *param_2;
  _DAT_1c0005112 = _DriverEntryRegPath + 2;
  local_128 = 0;
  local_120 = 0;
  local_11c = 0;
  local_124 = 0;
  DAT_1c0005118 = (void *)ExAllocatePool2(0x100,_DAT_1c0005112,0x4d444d55);
  if (DAT_1c0005118 == (void *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    memcpy(DAT_1c0005118,*(void **)(param_2 + 4),(ulonglong)*param_2);
    *(undefined2 *)((longlong)DAT_1c0005118 + (ulonglong)(*param_2 >> 1) * 2) = 0;
    memset(local_108,0,0xe0);
    pvVar1 = DAT_1c0005118;
    local_f8 = L"BreakOnEntry";
    local_e8 = 0x4000004;
    local_d8 = 4;
    local_f0 = &local_124;
    local_b0 = 0x4000004;
    local_e0 = &local_128;
    local_a0 = 4;
    local_c0 = L"DebugLevel";
    local_b8 = &local_120;
    local_a8 = &local_128;
    local_88 = L"DebugFlags";
    local_80 = &local_11c;
    local_70 = &local_128;
    local_78 = 0x4000004;
    local_68 = 4;
    local_100 = 0x120;
    local_c8 = 0x120;
    local_90 = 0x120;
    local_118 = 0;
    uStack_110 = 0;
    RtlInitUnicodeString(&local_118,L"RtlQueryRegistryValuesEx");
    pcVar4 = (code *)MmGetSystemRoutineAddress(&local_118);
    local_138 = 0;
    if (pcVar4 == (code *)0x0) {
      pcVar4 = RtlQueryRegistryValues_exref;
    }
    iVar2 = (*pcVar4)(0x80000000,pvVar1,local_108,0);
    if (iVar2 < 0) {
      local_124 = 0;
      local_120 = 0;
    }
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = ModemAddDevice;
    *(code **)(param_1 + 0xb8) = UniDispatch;
    *(code **)(param_1 + 0x68) = UniUnload;
    *(code **)(param_1 + 0x70) = UniOpen;
    *(code **)(param_1 + 0x80) = UniClose;
    *(code **)(param_1 + 0xe0) = UniIoControl;
    *(code **)(param_1 + 0x90) = UniWrite;
    *(code **)(param_1 + 0x88) = UniRead;
    *(code **)(param_1 + 0x100) = UniCleanup;
    *(code **)(param_1 + 0x98) = UniDispatch;
    *(code **)(param_1 + 0xa0) = UniDispatch;
    *(code **)(param_1 + 0x148) = ModemPnP;
    *(code **)(param_1 + 0x120) = ModemPower;
    *(code **)(param_1 + 0x128) = ModemWmi;
    PagedCodeSectionHandle = MmLockPagableDataSection();
    MmUnlockPagableImageSection(PagedCodeSectionHandle);
    uVar3 = 0;
  }
  return uVar3;
}


