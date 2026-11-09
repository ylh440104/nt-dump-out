
===== ReferenceCompletionContext @ 140001008 =====

longlong * ReferenceCompletionContext(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  *param_1 = 0;
  param_1[1] = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_2 + 0xb8);
  plVar1 = *(longlong **)(param_2 + 0xb0);
  if (plVar1 != (longlong *)0x0) {
    lVar2 = *plVar1;
    param_1[1] = plVar1[1];
    *param_1 = lVar2;
    if (lVar2 != 0) {
      ObfReferenceObject();
    }
  }
  KeReleaseSpinLock(param_2 + 0xb8,uVar3);
  return param_1;
}



===== __report_gsfailure @ 1400010b0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400010bd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== WdmlibRtlInitUnicodeStringEx @ 1400010d0 =====

undefined8 WdmlibRtlInitUnicodeStringEx(short *param_1,longlong param_2)

{
  short sVar1;
  ulonglong uVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    sVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (0x7ffe < uVar2) {
      return 0xc0000106;
    }
    sVar1 = (short)uVar2 * 2;
    sVar3 = sVar1 + 2;
  }
  *param_1 = sVar1;
  param_1[1] = sVar3;
  *(longlong *)(param_1 + 4) = param_2;
  return 0;
}



===== _guard_check_icall @ 140001130 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140001148 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000116c =====

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



===== __GSHandlerCheck_SEH @ 1400011d4 =====

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}



===== __cpu_features_init @ 140001270 =====

/* WARNING: Removing unreachable block (ram,0x0001400012da) */
/* WARNING: Removing unreachable block (ram,0x000140001289) */
/* WARNING: Removing unreachable block (ram,0x00014000127a) */

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



===== __security_check_cookie @ 140001340 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140001380 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400013b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400013b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400013e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140001440 =====

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



===== memset @ 140001740 =====

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



===== __memset_repmovs @ 140001880 =====

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



===== __memset_query @ 140001900 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140001980 =====

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



===== __memset_spec_ermsb_repmovsb @ 140001ac0 =====

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



===== __memset_spec_plain @ 140001b40 =====

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



===== operator() @ 140008008 =====

/* public: void __cdecl ReleaseDeleter<class PCW_COUNTERSET>::operator()(class PCW_COUNTERSET *
   __ptr64)const __ptr64 */

void __thiscall
ReleaseDeleter<PCW_COUNTERSET>::operator()
          (ReleaseDeleter<PCW_COUNTERSET> *this,PCW_COUNTERSET *param_1)

{
  PCW_COUNTERSET *pPVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = *(uint *)(param_1 + 0x98);
  do {
    if ((int)uVar5 < 2) {
      uVar4 = *(undefined8 *)(param_1 + 0x90);
      KeEnterCriticalRegion(this);
      ExAcquirePushLockExclusiveEx(uVar4,0);
      LOCK();
      pPVar1 = param_1 + 0x98;
      iVar3 = *(int *)pPVar1;
      *(int *)pPVar1 = *(int *)pPVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        RtlRbRemoveNode(*(longlong *)(param_1 + 0x90) + 8,param_1);
        ExReleasePushLockExclusiveEx(*(undefined8 *)(param_1 + 0x90),0);
        KeLeaveCriticalRegion();
        PCW_COUNTERSET::~PCW_COUNTERSET(param_1);
        ExFreePoolWithTag(param_1,0);
        return;
      }
      ExReleasePushLockExclusiveEx(*(longlong *)(param_1 + 0x90),0);
      KeLeaveCriticalRegion();
      return;
    }
    this = (ReleaseDeleter<PCW_COUNTERSET> *)(ulonglong)(uVar5 - 1);
    LOCK();
    uVar2 = *(uint *)(param_1 + 0x98);
    bVar6 = uVar5 == uVar2;
    if (bVar6) {
      *(uint *)(param_1 + 0x98) = uVar5 - 1;
    }
    else {
      uVar5 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return;
}



===== AddCounter @ 1400080ec =====

/* private: long __cdecl _PCW_BUFFER::AddCounter(void const * __ptr64,struct _PCW_COUNTER_DESCRIPTOR
   const * __ptr64) __ptr64 */

long __thiscall
_PCW_BUFFER::AddCounter(_PCW_BUFFER *this,void *param_1,_PCW_COUNTER_DESCRIPTOR *param_2)

{
  void *pvVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  void *local_res18;
  ulonglong local_18;
  undefined4 local_10;
  
  local_res18 = (void *)0x0;
  local_10 = 0;
  uVar4 = *(ushort *)(param_2 + 6) + 0xf;
  local_18 = CONCAT44(CONCAT22(*(ushort *)(param_2 + 6),*(undefined2 *)param_2),uVar4) &
             0xfffffffffffffff8;
  lVar2 = ReserveSpaceVoid(this,&local_res18,uVar4 & 0xfffffff8);
  pvVar1 = local_res18;
  if (-1 < lVar2) {
    if (local_res18 == (void *)0x0) {
      lVar2 = 0;
    }
    else {
      *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
      lVar2 = PcwpWriteToUserBuffer(local_res18,&local_18,8);
      if (-1 < lVar2) {
        lVar3 = PcwpWriteToUserBuffer
                          ((void *)((longlong)pvVar1 + 8),
                           (void *)((ulonglong)*(ushort *)(param_2 + 4) + (longlong)param_1),
                           (uint)*(ushort *)(param_2 + 6));
        lVar2 = 0;
        if (lVar3 < 0) {
          lVar2 = lVar3;
        }
      }
    }
  }
  return lVar2;
}



===== AddInstanceName @ 1400081a8 =====

/* public: long __cdecl _PCW_BUFFER::AddInstanceName(struct _UNICODE_STRING const * __ptr64,unsigned
   long) __ptr64 */

long __thiscall
_PCW_BUFFER::AddInstanceName(_PCW_BUFFER *this,_UNICODE_STRING *param_1,ulong param_2)

{
  void *pvVar1;
  bool bVar2;
  long lVar3;
  void *local_res8;
  undefined8 local_28;
  undefined4 local_20;
  
  local_28 = 0;
  local_20 = 0;
  local_res8 = (void *)0x0;
  bVar2 = PcwpWildcardMatch(*(_UNICODE_STRING **)(this + 0x28),param_1);
  if (bVar2) {
    local_28 = CONCAT44(local_28._4_4_,*(ushort *)param_1 + 0x13) & 0xfffffffffffffff8;
    lVar3 = ReserveSpaceVoid(this,&local_res8,*(ushort *)param_1 + 0x13 & 0xfffffff8);
    pvVar1 = local_res8;
    if (lVar3 < 0) {
      return lVar3;
    }
    if (local_res8 != (void *)0x0) {
      local_res8 = (void *)((ulonglong)local_res8 & 0xffffffffffff0000);
      local_28 = CONCAT44(param_2,(undefined4)local_28);
      lVar3 = PcwpWriteToUserBuffer(pvVar1,&local_28,8);
      if (lVar3 < 0) {
        return lVar3;
      }
      lVar3 = PcwpWriteToUserBuffer
                        ((void *)((longlong)pvVar1 + 8),*(void **)(param_1 + 8),
                         (uint)*(ushort *)param_1);
      if (lVar3 < 0) {
        return lVar3;
      }
      lVar3 = PcwpWriteToUserBuffer
                        ((void *)((longlong)pvVar1 + ((ulonglong)(*(ushort *)param_1 >> 1) + 4) * 2)
                         ,&local_res8,2);
      if (lVar3 < 0) {
        return lVar3;
      }
      *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
    }
  }
  return 0;
}



===== Collect @ 140008288 =====

/* public: long __cdecl PCW_QUERY::Collect(void * __ptr64,unsigned long,unsigned long * __ptr64)
   __ptr64 */

long __thiscall PCW_QUERY::Collect(PCW_QUERY *this,void *param_1,ulong param_2,ulong *param_3)

{
  PCW_QUERY *pPVar1;
  PCW_QUERY *pPVar2;
  PCW_COUNTERSET_BASE *pPVar3;
  longlong lVar4;
  bool bVar5;
  long lVar6;
  uint uVar7;
  PCW_QUERY *this_00;
  ulong uVar8;
  _KEVENT *local_res10;
  ulong local_res18;
  ulong *local_res20;
  undefined8 local_f8;
  ulonglong uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  ulong uStack_d0;
  uint uStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  ulonglong uStack_c0;
  undefined8 local_b8;
  PCW_QUERY_ITEM *pPStack_b0;
  ulonglong local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  ulonglong uStack_90;
  void *local_88;
  void *local_80;
  undefined4 local_78;
  undefined4 uStack_74;
  ulong uStack_70;
  uint uStack_6c;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  PCW_QUERY_ITEM *pPStack_50;
  ulonglong local_48;
  undefined8 uStack_40;
  
  local_res20 = param_3;
  memset(&local_d8,0,0x40);
  uVar7 = 0;
  local_80 = (void *)0x0;
  uStack_90 = 0;
  uStack_cc = 0;
  uStack_c8 = 0;
  local_98 = (ulonglong)param_2;
  local_d8 = param_1;
  uStack_d0 = param_2;
  lVar6 = _PCW_BUFFER::ReserveSpaceVoid((_PCW_BUFFER *)&local_d8,&local_80,0x10);
  if (-1 < lVar6) {
    uStack_c4 = uVar7;
    KeEnterCriticalRegion();
    pPVar1 = this + 8;
    ExAcquirePushLockSharedEx(pPVar1,0);
    pPVar2 = this + 0x10;
    this_00 = *(PCW_QUERY **)pPVar2;
    if (this_00 != pPVar2) {
      do {
        bVar5 = PcwpIsRequestCancelled(*(_KEVENT **)(this + 0x28));
        if (bVar5) {
          lVar6 = -0x3ffffee0;
          goto LAB_140008614;
        }
        local_68 = CONCAT44(uStack_c4,uStack_c8);
        local_res10 = *(_KEVENT **)(this + 0x28);
        local_88 = (void *)0x0;
        pPVar3 = *(PCW_COUNTERSET_BASE **)(this_00 + 0x50);
        uStack_60 = uStack_c0;
        local_58 = local_b8;
        pPStack_50 = pPStack_b0;
        local_48 = local_a8;
        uStack_40 = uStack_a0;
        local_78 = (undefined4)local_d8;
        uStack_74 = local_d8._4_4_;
        uStack_70 = uStack_d0;
        uStack_6c = uStack_cc;
        local_f8 = 0;
        uStack_f0 = 0;
        local_e8 = 0;
        uStack_e0 = 0;
        local_res18 = uStack_d0;
        uVar7 = _PCW_BUFFER::ReserveSpaceVoid((_PCW_BUFFER *)&local_d8,&local_88,0x20);
        if ((int)uVar7 < 0) {
LAB_1400084e9:
          local_d8 = (void *)CONCAT44(uStack_74,local_78);
          local_res10 = (_KEVENT *)0x0;
          uVar8 = 0x20;
          uStack_d0 = uStack_70;
          uStack_cc = uStack_6c;
          uStack_c8 = (undefined4)local_68;
          uStack_c4 = (uint)((ulonglong)local_68 >> 0x20);
          uStack_c0 = uStack_60;
          local_b8 = local_58;
          pPStack_b0 = pPStack_50;
          local_f8 = 0;
          uStack_f0 = 0;
          local_e8 = 0;
          uStack_e0 = 0;
          local_a8 = local_48;
          uStack_a0 = uStack_40;
          lVar6 = _PCW_BUFFER::ReserveSpaceVoid((_PCW_BUFFER *)&local_d8,&local_res10,0x20);
          if (lVar6 < 0) {
LAB_140008614:
            ExReleasePushLockSharedEx(pPVar1,0);
            KeLeaveCriticalRegion();
            return lVar6;
          }
          if (local_res10 != (_KEVENT *)0x0) {
            uStack_e0 = *(undefined8 *)(this_00 + 0x48);
            local_e8 = 0;
            local_f8 = CONCAT44(uVar8,uVar8);
            uStack_f0 = (ulonglong)uVar7 << 0x20;
            lVar6 = PcwpWriteToUserBuffer(local_res10,&local_f8,uVar8);
            if (lVar6 < 0) goto LAB_140008614;
          }
        }
        else {
          uStack_c0 = uStack_c0 & 0xffffffff00000000;
          pPStack_b0 = (PCW_QUERY_ITEM *)(this_00 + 0x58);
          local_a8 = (ulonglong)*(uint5 *)(this_00 + 0x3c);
          uStack_a0 = *(undefined8 *)(this_00 + 0x30);
          lVar4 = *(longlong *)(pPVar3 + 0x50);
          KeEnterCriticalRegion();
          ExAcquirePushLockSharedEx(lVar4 + 0x50,0);
          uVar7 = PCW_QUERY_ITEM::SendCollectNotification
                            ((PCW_QUERY_ITEM *)this_00,*(PCW_COUNTERSET_BASE **)(pPVar3 + 0x50),
                             (_PCW_BUFFER *)&local_d8,local_res10);
          if (-1 < (int)uVar7) {
            uVar7 = PCW_QUERY_ITEM::SendCollectNotification
                              ((PCW_QUERY_ITEM *)this_00,pPVar3,(_PCW_BUFFER *)&local_d8,local_res10
                              );
          }
          ExReleasePushLockSharedEx(*(longlong *)(pPVar3 + 0x50) + 0x50,0);
          KeLeaveCriticalRegion();
          if ((int)uVar7 < 0) goto LAB_1400084e9;
          if ((*(PCW_QUERY_ITEM *)(this_00 + 0x40) != (PCW_QUERY_ITEM)0x0) || ((uint)uStack_c0 == 0)
             ) {
            uVar7 = PCW_QUERY_ITEM::CollectInstances
                              ((PCW_QUERY_ITEM *)this_00,*(PCW_COUNTERSET_BASE **)(pPVar3 + 0x50),
                               (_PCW_BUFFER *)&local_d8,local_res10);
            if ((int)uVar7 < 0) goto LAB_1400084e9;
            if ((*(PCW_QUERY_ITEM *)(this_00 + 0x40) != (PCW_QUERY_ITEM)0x0) ||
               ((uint)uStack_c0 == 0)) {
              uVar7 = PCW_QUERY_ITEM::CollectInstances
                                ((PCW_QUERY_ITEM *)this_00,pPVar3,(_PCW_BUFFER *)&local_d8,
                                 local_res10);
              if ((int)uVar7 < 0) goto LAB_1400084e9;
            }
          }
          if (local_88 != (void *)0x0) {
            uStack_f0 = (ulonglong)(uint)uStack_c0;
            local_e8 = uStack_a0;
            uStack_e0 = *(undefined8 *)(this_00 + 0x48);
            local_f8 = CONCAT44(0x20,local_res18 - uStack_d0);
            uVar7 = PcwpWriteToUserBuffer(local_88,&local_f8,0x20);
            if ((int)uVar7 < 0) goto LAB_1400084e9;
            uStack_c4 = uStack_c4 + 1;
          }
        }
        this_00 = *(PCW_QUERY **)this_00;
        lVar6 = 0;
      } while (this_00 != pPVar2);
      param_3 = local_res20;
    }
    ExReleasePushLockSharedEx(pPVar1,0);
    KeLeaveCriticalRegion();
    if (local_80 != (void *)0x0) {
      uStack_90 = (ulonglong)uStack_c4;
      local_98 = CONCAT44(0x10,param_2 - uStack_d0);
      lVar6 = PcwpWriteToUserBuffer(local_80,&local_98,0x10);
      if (lVar6 < 0) {
        return lVar6;
      }
    }
    *param_3 = uStack_cc;
    if (param_2 < uStack_cc) {
      lVar6 = -0x7ffffffb;
    }
  }
  return lVar6;
}



===== CollectInstance @ 14000863c =====

/* public: long __cdecl _PCW_BUFFER::CollectInstance(struct _PCW_REGISTRATION const * __ptr64,struct
   _UNICODE_STRING const * __ptr64,unsigned long,unsigned long,void const * __ptr64 const *
   __ptr64,struct _PCW_DATA const * __ptr64) __ptr64 */

long __thiscall
_PCW_BUFFER::CollectInstance
          (_PCW_BUFFER *this,_PCW_REGISTRATION *param_1,_UNICODE_STRING *param_2,ulong param_3,
          ulong param_4,void **param_5,_PCW_DATA *param_6)

{
  _PCW_COUNTER_DESCRIPTOR *p_Var1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  void *pvVar6;
  uint uVar7;
  ulong uVar8;
  void *local_res8;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  
  iVar3 = *(int *)(this + 8);
  local_48 = 0;
  uVar7 = *(ushort *)param_2 + 0x1b & 0xfffffff8;
  local_58 = 0;
  uStack_50 = (ulonglong)uVar7;
  local_res8 = (void *)0x0;
  uVar8 = param_3;
  lVar4 = ReserveSpaceVoid(this,&local_res8,uVar7);
  if (-1 < lVar4) {
    uVar7 = 0;
    *(ulonglong *)(this + 0x38) = *(ulonglong *)(this + 0x38) & *(ulonglong *)(param_1 + 0x10);
    *(undefined4 *)(this + 0x1c) = 0;
    if (*(int *)(param_1 + 0x18) != 0) {
      do {
        p_Var1 = (_PCW_COUNTER_DESCRIPTOR *)(*(longlong *)(param_1 + 0x40) + (ulonglong)uVar7 * 8);
        if ((*(ulonglong *)(this + 0x38) >> ((ulonglong)(byte)*p_Var1 & 0x3f) & 1) != 0) {
          uVar2 = *(ushort *)(p_Var1 + 2);
          uVar5 = (uint)uVar2;
          if (param_4 <= uVar5) {
            return -0x3ffffdfa;
          }
          if (param_5 == (void **)0x0) {
            if (*(uint *)(param_6 + (ulonglong)uVar5 * 0x10 + 8) <
                (uint)*(ushort *)(p_Var1 + 4) + (uint)*(ushort *)(p_Var1 + 6)) {
              return -0x3ffffdfa;
            }
            pvVar6 = *(void **)(param_6 + (ulonglong)uVar5 * 0x10);
          }
          else {
            pvVar6 = param_5[uVar2];
          }
          lVar4 = AddCounter(this,pvVar6,p_Var1);
          if (lVar4 < 0) {
            return lVar4;
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(param_1 + 0x18));
      uVar8 = param_3;
    }
    pvVar6 = local_res8;
    if (local_res8 != (void *)0x0) {
      local_res8 = (void *)((ulonglong)local_res8 & 0xffffffffffff0000);
      uStack_50 = CONCAT44(*(undefined4 *)(this + 0x1c),(undefined4)uStack_50);
      local_58 = CONCAT44(uVar8,iVar3 - *(int *)(this + 8));
      lVar4 = PcwpWriteToUserBuffer(pvVar6,&local_58,0x10);
      if (lVar4 < 0) {
        return lVar4;
      }
      lVar4 = PcwpWriteToUserBuffer
                        ((void *)((longlong)pvVar6 + 0x10),*(void **)(param_2 + 8),
                         (uint)*(ushort *)param_2);
      if (lVar4 < 0) {
        return lVar4;
      }
      lVar4 = PcwpWriteToUserBuffer
                        ((void *)((longlong)pvVar6 + ((ulonglong)(*(ushort *)param_2 >> 1) + 8) * 2)
                         ,&local_res8,2);
      if (lVar4 < 0) {
        return lVar4;
      }
      *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
    }
    lVar4 = 0;
  }
  return lVar4;
}



===== CollectInstances @ 1400087c4 =====

/* private: long __cdecl PCW_QUERY_ITEM::CollectInstances(class PCW_COUNTERSET_BASE * __ptr64,struct
   _PCW_BUFFER * __ptr64,struct _KEVENT * __ptr64)const __ptr64 */

long __thiscall
PCW_QUERY_ITEM::CollectInstances
          (PCW_QUERY_ITEM *this,PCW_COUNTERSET_BASE *param_1,_PCW_BUFFER *param_2,_KEVENT *param_3)

{
  _PCW_INSTANCE *p_Var1;
  _PCW_REGISTRATION *p_Var2;
  bool bVar3;
  long lVar4;
  undefined8 *puVar5;
  _PCW_INSTANCE *this_00;
  _PCW_INSTANCE *local_28;
  _PCW_INSTANCE *local_20;
  
  local_28 = (_PCW_INSTANCE *)0x0;
  PCW_COUNTERSET_BASE::NextInstance(param_1,&local_20,&local_28);
  this_00 = local_20;
  while( true ) {
    if (this_00 == (_PCW_INSTANCE *)0x0) {
      return 0;
    }
    bVar3 = PcwpIsRequestCancelled(param_3);
    if (bVar3) break;
    if (((*(int *)(this + 0x3c) == -1) || (*(int *)(this_00 + 0x48) == *(int *)(this + 0x3c))) &&
       (bVar3 = PcwpWildcardMatch((_UNICODE_STRING *)(this + 0x58),
                                  (_UNICODE_STRING *)(this_00 + 0x10)), bVar3)) {
      p_Var1 = this_00 + 0x30;
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(p_Var1,0);
      p_Var2 = *(_PCW_REGISTRATION **)(this_00 + 0x38);
      if ((p_Var2 != (_PCW_REGISTRATION *)0x0) &&
         (lVar4 = _PCW_BUFFER::CollectInstance
                            (param_2,p_Var2,(_UNICODE_STRING *)(this_00 + 0x10),
                             *(ulong *)(this_00 + 0x48),*(ulong *)(p_Var2 + 0x1c),
                             *(void ***)(this_00 + 0x40),(_PCW_DATA *)0x0), lVar4 < 0)) {
        ExReleasePushLockSharedEx(p_Var1,0);
        KeLeaveCriticalRegion();
        goto LAB_140008922;
      }
      ExReleasePushLockSharedEx(p_Var1,0);
      KeLeaveCriticalRegion();
      if ((this[0x40] == (PCW_QUERY_ITEM)0x0) && (*(int *)(param_2 + 0x18) != 0)) {
        if (this_00 == (_PCW_INSTANCE *)0x0) {
          return 0;
        }
        _PCW_INSTANCE::Release(this_00);
        return 0;
      }
    }
    local_20 = this_00;
    puVar5 = (undefined8 *)PCW_COUNTERSET_BASE::NextInstance(param_1,&local_28,&local_20);
    this_00 = (_PCW_INSTANCE *)*puVar5;
    *puVar5 = 0;
    if (local_28 != (_PCW_INSTANCE *)0x0) {
      _PCW_INSTANCE::Release(local_28);
    }
  }
  lVar4 = -0x3ffffee0;
LAB_140008922:
  _PCW_INSTANCE::Release(this_00);
  return lVar4;
}



===== EnumerateCounterSetInstances @ 140008964 =====

long EnumerateCounterSetInstances
               (PCW_COUNTERSET_BASE *param_1,_KEVENT *param_2,_PCW_BUFFER *param_3)

{
  bool bVar1;
  long lVar2;
  undefined8 *puVar3;
  _PCW_INSTANCE *this;
  _PCW_INSTANCE *local_res20;
  _PCW_INSTANCE *local_28 [2];
  
  local_res20 = (_PCW_INSTANCE *)0x0;
  PCW_COUNTERSET_BASE::NextInstance(param_1,local_28,&local_res20);
  this = local_28[0];
  while( true ) {
    if (this == (_PCW_INSTANCE *)0x0) {
      return 0;
    }
    bVar1 = PcwpIsRequestCancelled(param_2);
    if (bVar1) break;
    if ((*(longlong *)(this + 0x38) != 0) &&
       (lVar2 = _PCW_BUFFER::AddInstanceName
                          (param_3,(_UNICODE_STRING *)(this + 0x10),*(ulong *)(this + 0x48)),
       lVar2 < 0)) goto LAB_1400089f9;
    local_res20 = this;
    puVar3 = (undefined8 *)PCW_COUNTERSET_BASE::NextInstance(param_1,local_28,&local_res20);
    this = (_PCW_INSTANCE *)*puVar3;
    *puVar3 = 0;
    if (local_28[0] != (_PCW_INSTANCE *)0x0) {
      _PCW_INSTANCE::Release(local_28[0]);
    }
  }
  lVar2 = -0x3ffffee0;
LAB_1400089f9:
  _PCW_INSTANCE::Release(this);
  return lVar2;
}



===== PcwpEnumerateInstances @ 140008a24 =====

/* long __cdecl PcwpEnumerateInstances(struct _KEVENT * __ptr64,struct _UNICODE_STRING const *
   __ptr64,struct _UNICODE_STRING const * __ptr64,void * __ptr64,unsigned long,unsigned long *
   __ptr64) */

long __cdecl
PcwpEnumerateInstances
          (_KEVENT *param_1,_UNICODE_STRING *param_2,_UNICODE_STRING *param_3,void *param_4,
          ulong param_5,ulong *param_6)

{
  longlong lVar1;
  PCW_COUNTERSET *pPVar2;
  long lVar3;
  unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *this;
  PCW_COUNTERSET_BASE *this_00;
  undefined8 local_res20;
  ReleaseDeleter<PCW_COUNTERSET> *local_68 [2];
  void *local_58;
  ulong local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_40;
  _UNICODE_STRING *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_res20 = (PCW_COUNTERSET *)0x0;
  local_68[0] = (ReleaseDeleter<PCW_COUNTERSET> *)0x0;
  memset(&local_58,0,0x40);
  local_4c = 0;
  local_50 = param_5;
  local_48 = 1;
  local_58 = param_4;
  lVar3 = _PCW_BUFFER::ReserveSpaceVoid((_PCW_BUFFER *)&local_58,local_68,8);
  if (lVar3 < 0) {
    return lVar3;
  }
  this = (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)&local_res20;
  lVar3 = PCW_COUNTERSET::FindOrCreate(this,param_2,1);
  pPVar2 = local_res20;
  if (lVar3 < 0) {
    if (local_res20 != (PCW_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_COUNTERSET>::operator()((ReleaseDeleter<PCW_COUNTERSET> *)this,local_res20)
      ;
    }
    return lVar3;
  }
  local_28 = 0xffffffff;
  local_40 = 0;
  local_24 = 1;
  lVar1 = *(longlong *)(local_res20 + 0x50);
  local_30 = param_3;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(lVar1 + 0x50,0);
  lVar3 = PcwpEnumerateInstancesNotification
                    (*(PCW_COUNTERSET_BASE **)(pPVar2 + 0x50),(_PCW_BUFFER *)&local_58,param_3,
                     param_1);
  if (-1 < lVar3) {
    lVar3 = PcwpEnumerateInstancesNotification
                      ((PCW_COUNTERSET_BASE *)pPVar2,(_PCW_BUFFER *)&local_58,param_3,param_1);
  }
  this_00 = (PCW_COUNTERSET_BASE *)(*(longlong *)(pPVar2 + 0x50) + 0x50);
  ExReleasePushLockSharedEx(this_00,0);
  KeLeaveCriticalRegion();
  if (-1 < lVar3) {
    this_00 = *(PCW_COUNTERSET_BASE **)(pPVar2 + 0x50);
    lVar3 = EnumerateCounterSetInstances(this_00,param_1,(_PCW_BUFFER *)&local_58);
    if ((-1 < lVar3) &&
       (this_00 = (PCW_COUNTERSET_BASE *)pPVar2,
       lVar3 = EnumerateCounterSetInstances
                         ((PCW_COUNTERSET_BASE *)pPVar2,param_1,(_PCW_BUFFER *)&local_58),
       -1 < lVar3)) {
      if (local_68[0] != (ReleaseDeleter<PCW_COUNTERSET> *)0x0) {
        local_res20 = (PCW_COUNTERSET *)CONCAT44(8,local_40);
        this_00 = (PCW_COUNTERSET_BASE *)local_68[0];
        lVar3 = PcwpWriteToUserBuffer(local_68[0],&local_res20,8);
        if (lVar3 < 0) goto LAB_140008bb6;
      }
      this_00 = (PCW_COUNTERSET_BASE *)(ulonglong)local_4c;
      *param_6 = local_4c;
      if (param_5 < local_4c) {
        lVar3 = -0x7ffffffb;
      }
    }
  }
LAB_140008bb6:
  ReleaseDeleter<PCW_COUNTERSET>::operator()((ReleaseDeleter<PCW_COUNTERSET> *)this_00,pPVar2);
  return lVar3;
}



===== PcwpEnumerateInstancesNotification @ 140008be4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PcwpEnumerateInstancesNotification(class PCW_COUNTERSET_BASE * __ptr64,struct
   _PCW_BUFFER * __ptr64,struct _UNICODE_STRING const * __ptr64,struct _KEVENT * __ptr64) */

long __cdecl
PcwpEnumerateInstancesNotification
          (PCW_COUNTERSET_BASE *param_1,_PCW_BUFFER *param_2,_UNICODE_STRING *param_3,
          _KEVENT *param_4)

{
  bool bVar1;
  int iVar2;
  PCW_COUNTERSET_BASE *pPVar3;
  undefined8 local_38;
  _UNICODE_STRING *local_30;
  undefined4 local_28;
  undefined1 local_24;
  undefined2 local_23;
  undefined1 local_21;
  _PCW_BUFFER *local_20;
  _KEVENT *local_18;
  
  local_28 = 0xffffffff;
  pPVar3 = *(PCW_COUNTERSET_BASE **)(param_1 + 0x28);
  iVar2 = 0;
  local_23 = 0;
  local_21 = 0;
  local_38 = 0;
  local_24 = 1;
  local_30 = param_3;
  local_20 = param_2;
  local_18 = param_4;
  while( true ) {
    if (pPVar3 == param_1 + 0x28) {
      return iVar2;
    }
    bVar1 = PcwpIsRequestCancelled(param_4);
    if (bVar1) break;
    if ((*(code **)(pPVar3 + 0x30) != (code *)0x0) &&
       (iVar2 = (**(code **)(pPVar3 + 0x30))(2,&local_38,*(undefined8 *)(pPVar3 + 0x38)), iVar2 < 0)
       ) {
      return iVar2;
    }
    pPVar3 = *(PCW_COUNTERSET_BASE **)pPVar3;
  }
  return -0x3ffffee0;
}



===== PcwpIsRequestCancelled @ 140008c94 =====

/* bool __cdecl PcwpIsRequestCancelled(struct _KEVENT * __ptr64) */

bool __cdecl PcwpIsRequestCancelled(_KEVENT *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = PsIsThreadTerminating(SystemReserved1[0xf]);
  if (cVar1 == '\0') {
    if (param_1 == (_KEVENT *)0x0) {
      return false;
    }
    iVar2 = KeReadStateEvent(param_1);
    if (iVar2 == 0) {
      return false;
    }
  }
  return true;
}



===== PcwpWildcardMatch @ 140008cec =====

/* bool __cdecl PcwpWildcardMatch(struct _UNICODE_STRING const * __ptr64,struct _UNICODE_STRING
   const * __ptr64) */

bool __cdecl PcwpWildcardMatch(_UNICODE_STRING *param_1,_UNICODE_STRING *param_2)

{
  short *psVar1;
  ulonglong uVar2;
  int iVar3;
  short *psVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  short *psVar8;
  
  psVar8 = (short *)0x0;
  psVar1 = *(short **)(param_1 + 8) + (*(ushort *)param_1 >> 1);
  uVar2 = *(ulonglong *)(param_2 + 8) + (ulonglong)(*(ushort *)param_2 >> 1) * 2;
  psVar4 = *(short **)(param_1 + 8);
  uVar6 = 0;
  uVar7 = *(ulonglong *)(param_2 + 8);
  while( true ) {
    while( true ) {
      if ((uVar2 <= uVar7) && (psVar1 <= psVar4)) {
        return true;
      }
      uVar5 = uVar6;
      if ((psVar4 < psVar1) && (*psVar4 == 0x2a)) {
        do {
          psVar4 = psVar4 + 1;
          if (psVar1 <= psVar4) {
            return true;
          }
        } while (*psVar4 == 0x2a);
        uVar5 = uVar7 + 2;
        psVar8 = psVar4;
      }
      if (((uVar2 <= uVar7) || (psVar1 <= psVar4)) ||
         ((*psVar4 != 0x3f && (iVar3 = RtlCompareUnicodeStrings(psVar4,1,uVar7,1,1), iVar3 != 0))))
      break;
      psVar4 = psVar4 + 1;
      uVar6 = uVar5;
      uVar7 = uVar7 + 2;
    }
    if ((psVar8 == (short *)0x0) || (uVar2 <= uVar5)) break;
    uVar6 = uVar5 + 2;
    psVar4 = psVar8;
    uVar7 = uVar5;
  }
  return false;
}



===== PcwpWriteToUserBuffer @ 140008dcc =====

/* long __cdecl PcwpWriteToUserBuffer(void * __ptr64,void const * __ptr64,unsigned long) */

long __cdecl PcwpWriteToUserBuffer(void *param_1,void *param_2,ulong param_3)

{
  memmove(param_1,param_2,(ulonglong)param_3);
  return 0;
}



===== ReserveSpaceVoid @ 140008dec =====

/* private: long __cdecl _PCW_BUFFER::ReserveSpaceVoid(void * __ptr64 * __ptr64,unsigned long)
   __ptr64 */

long __thiscall _PCW_BUFFER::ReserveSpaceVoid(_PCW_BUFFER *this,void **param_1,ulong param_2)

{
  uint uVar1;
  void *pvVar2;
  
  *(ulong *)(this + 0xc) = *(int *)(this + 0xc) + param_2;
  if (*(uint *)(this + 0xc) < param_2) {
    return -0x3fffff6b;
  }
  uVar1 = *(uint *)(this + 8);
  if (uVar1 < param_2) {
    *param_1 = (void *)0x0;
  }
  else {
    pvVar2 = *(void **)this;
    *param_1 = pvVar2;
    *(ulonglong *)this = (ulonglong)param_2 + (longlong)pvVar2;
    *(uint *)(this + 8) = uVar1 - param_2;
  }
  return 0;
}



===== SendCollectNotification @ 140008e34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl PCW_QUERY_ITEM::SendCollectNotification(class PCW_COUNTERSET_BASE *
   __ptr64,struct _PCW_BUFFER * __ptr64,struct _KEVENT * __ptr64)const __ptr64 */

long __thiscall
PCW_QUERY_ITEM::SendCollectNotification
          (PCW_QUERY_ITEM *this,PCW_COUNTERSET_BASE *param_1,_PCW_BUFFER *param_2,_KEVENT *param_3)

{
  bool bVar1;
  int iVar2;
  PCW_COUNTERSET_BASE *pPVar3;
  undefined8 local_48;
  PCW_QUERY_ITEM *local_40;
  undefined4 local_38;
  PCW_QUERY_ITEM local_34;
  undefined2 local_33;
  undefined1 local_31;
  _PCW_BUFFER *local_30;
  _KEVENT *local_28;
  
  local_34 = this[0x40];
  pPVar3 = *(PCW_COUNTERSET_BASE **)(param_1 + 0x28);
  local_33 = 0;
  local_31 = 0;
  iVar2 = 0;
  local_48 = *(undefined8 *)(this + 0x30);
  local_40 = this + 0x58;
  local_38 = *(undefined4 *)(this + 0x3c);
  local_30 = param_2;
  local_28 = param_3;
  do {
    if (pPVar3 == param_1 + 0x28) {
      return iVar2;
    }
    bVar1 = PcwpIsRequestCancelled(param_3);
    if (bVar1) {
      return -0x3ffffee0;
    }
    if (*(longlong *)(pPVar3 + 0x30) != 0) {
      *(PCW_COUNTERSET_BASE **)(local_30 + 0x20) = pPVar3;
      iVar2 = (**(code **)(pPVar3 + 0x30))(3,&local_48,*(undefined8 *)(pPVar3 + 0x38));
      if (iVar2 < 0) {
        return iVar2;
      }
      if ((this[0x40] == (PCW_QUERY_ITEM)0x0) && (*(int *)(param_2 + 0x18) != 0)) {
        return iVar2;
      }
    }
    pPVar3 = *(PCW_COUNTERSET_BASE **)pPVar3;
  } while( true );
}



===== PCW_QUERY_ITEM @ 140008f14 =====

/* public: __cdecl PCW_QUERY_ITEM::PCW_QUERY_ITEM(class utl::unique_ptr<class PCW_COUNTERSET,struct
   ReleaseDeleter<class PCW_COUNTERSET> > && __ptr64,class AllocatedUnicodeString &&
   __ptr64,bool,unsigned long,unsigned __int64 const & __ptr64,void * __ptr64) __ptr64 */

PCW_QUERY_ITEM * __thiscall
PCW_QUERY_ITEM::PCW_QUERY_ITEM
          (PCW_QUERY_ITEM *this,unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *param_1,
          AllocatedUnicodeString *param_2,bool param_3,ulong param_4,__uint64 *param_5,void *param_6
          )

{
  PCW_QUERY_ITEM *pPVar1;
  __uint64 _Var2;
  undefined8 uVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  PCW_QUERY_ITEM *pPVar7;
  undefined8 local_38;
  PCW_QUERY_ITEM *local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  pPVar7 = this + 0x10;
  pPVar1 = this + 0x20;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)pPVar7 = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(longlong *)pPVar1 = 0;
  *(undefined8 *)(this + 0x28) = 0;
  _Var2 = *param_5;
  *(ulong *)(this + 0x3c) = param_4;
  *(__uint64 *)(this + 0x30) = _Var2;
  local_30 = this + 0x58;
  *(void **)(this + 0x48) = param_6;
  *(undefined4 *)(this + 0x38) = 0;
  this[0x40] = (PCW_QUERY_ITEM)param_3;
  uVar3 = *(undefined8 *)param_1;
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(this + 0x50) = uVar3;
  uVar3 = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)local_30 = *(undefined8 *)param_2;
  *(undefined8 *)(this + 0x60) = uVar3;
  *(undefined8 *)param_2 = 0;
  *(undefined8 *)(param_2 + 8) = 0;
  local_38 = *(undefined8 *)(this + 0x30);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar4 = *(longlong *)(*(longlong *)(this + 0x50) + 0x50);
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(lVar4 + 0x50);
  PCW_COUNTERSET_BASE::Notify
            (*(PCW_COUNTERSET_BASE **)(*(longlong *)(this + 0x50) + 0x50),0,
             (_PCW_CALLBACK_INFORMATION *)&local_38);
  PCW_COUNTERSET_BASE::Notify
            (*(PCW_COUNTERSET_BASE **)(this + 0x50),0,(_PCW_CALLBACK_INFORMATION *)&local_38);
  lVar4 = *(longlong *)(*(longlong *)(this + 0x50) + 0x50);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar4 + 0x68,0);
  lVar4 = *(longlong *)(*(longlong *)(this + 0x50) + 0x50);
  plVar5 = *(longlong **)(lVar4 + 0x78);
  if (*plVar5 == lVar4 + 0x70) {
    *(longlong **)(this + 0x18) = plVar5;
    *(longlong *)pPVar7 = lVar4 + 0x70;
    *plVar5 = (longlong)pPVar7;
    *(PCW_QUERY_ITEM **)(lVar4 + 0x78) = pPVar7;
    lVar4 = *(longlong *)(this + 0x50);
    plVar5 = *(longlong **)(lVar4 + 0x60);
    if (*plVar5 == lVar4 + 0x58) {
      *(longlong **)(this + 0x28) = plVar5;
      *(longlong *)pPVar1 = lVar4 + 0x58;
      *plVar5 = (longlong)pPVar1;
      *(PCW_QUERY_ITEM **)(lVar4 + 0x60) = pPVar1;
      ExReleasePushLockExclusiveEx(*(longlong *)(*(longlong *)(this + 0x50) + 0x50) + 0x68,0);
      KeLeaveCriticalRegion();
      ExReleasePushLockSharedEx(*(longlong *)(*(longlong *)(this + 0x50) + 0x50) + 0x50,0);
      KeLeaveCriticalRegion();
      return this;
    }
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  pPVar7 = (PCW_QUERY_ITEM *)(*pcVar6)();
  return pPVar7;
}



===== ~PCW_QUERY @ 1400090d4 =====

/* private: __cdecl PCW_QUERY::~PCW_QUERY(void) __ptr64 */

void __thiscall PCW_QUERY::~PCW_QUERY(PCW_QUERY *this)

{
  PCW_QUERY_ITEM *pPVar1;
  PCW_QUERY_ITEM *this_00;
  longlong lVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar4 = auStack_28;
  pPVar1 = (PCW_QUERY_ITEM *)(this + 0x10);
  do {
    this_00 = *(PCW_QUERY_ITEM **)pPVar1;
    if (this_00 == pPVar1) {
LAB_14000912a:
      if (*(longlong *)(this + 0x28) != 0) {
        *(undefined8 *)(puVar4 + -8) = 0x14000913a;
        ObfDereferenceObject();
      }
      return;
    }
    if ((*(PCW_QUERY_ITEM **)(this_00 + 8) != pPVar1) ||
       (lVar2 = *(longlong *)this_00, *(PCW_QUERY_ITEM **)(lVar2 + 8) != this_00)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar4 = auStack_20;
      goto LAB_14000912a;
    }
    *(longlong *)pPVar1 = lVar2;
    *(PCW_QUERY_ITEM **)(lVar2 + 8) = pPVar1;
    PCW_QUERY_ITEM::~PCW_QUERY_ITEM(this_00);
    ExFreePoolWithTag(this_00,0);
  } while( true );
}



===== ~PCW_QUERY_ITEM @ 140009158 =====

/* public: __cdecl PCW_QUERY_ITEM::~PCW_QUERY_ITEM(void) __ptr64 */

void __thiscall PCW_QUERY_ITEM::~PCW_QUERY_ITEM(PCW_QUERY_ITEM *this)

{
  PCW_QUERY_ITEM *pPVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  AllocatedUnicodeString *this_00;
  undefined8 local_38;
  AllocatedUnicodeString *local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = *(undefined8 *)(this + 0x30);
  this_00 = (AllocatedUnicodeString *)(this + 0x58);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar2 = *(longlong *)(*(longlong *)(this + 0x50) + 0x50);
  local_30 = this_00;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(lVar2 + 0x50,0);
  PCW_COUNTERSET_BASE::Notify
            (*(PCW_COUNTERSET_BASE **)(*(longlong *)(this + 0x50) + 0x50),1,
             (_PCW_CALLBACK_INFORMATION *)&local_38);
  PCW_COUNTERSET_BASE::Notify
            (*(PCW_COUNTERSET_BASE **)(this + 0x50),1,(_PCW_CALLBACK_INFORMATION *)&local_38);
  lVar2 = *(longlong *)(*(longlong *)(this + 0x50) + 0x50);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar2 + 0x68,0);
  pPVar1 = this + 0x10;
  lVar2 = *(longlong *)pPVar1;
  if ((*(PCW_QUERY_ITEM **)(lVar2 + 8) == pPVar1) &&
     (plVar3 = *(longlong **)(this + 0x18), (PCW_QUERY_ITEM *)*plVar3 == pPVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    pPVar1 = this + 0x20;
    lVar2 = *(longlong *)pPVar1;
    if ((*(PCW_QUERY_ITEM **)(lVar2 + 8) == pPVar1) &&
       (plVar3 = *(longlong **)(this + 0x28), (PCW_QUERY_ITEM *)*plVar3 == pPVar1)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      ExReleasePushLockExclusiveEx(*(longlong *)(*(longlong *)(this + 0x50) + 0x50) + 0x68,0);
      KeLeaveCriticalRegion();
      ExReleasePushLockSharedEx(*(longlong *)(*(longlong *)(this + 0x50) + 0x50) + 0x50,0);
      KeLeaveCriticalRegion();
      AllocatedUnicodeString::~AllocatedUnicodeString(this_00);
      if (*(PCW_COUNTERSET **)(this + 0x50) != (PCW_COUNTERSET *)0x0) {
        ReleaseDeleter<PCW_COUNTERSET>::operator()
                  ((ReleaseDeleter<PCW_COUNTERSET> *)this_00,*(PCW_COUNTERSET **)(this + 0x50));
      }
      return;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== CloseQueryItem @ 1400092c4 =====

/* public: long __cdecl PCW_QUERY::CloseQueryItem(unsigned long) __ptr64 */

long __thiscall PCW_QUERY::CloseQueryItem(PCW_QUERY *this,ulong param_1)

{
  PCW_QUERY *pPVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  long lVar5;
  PCW_QUERY_ITEM *this_00;
  
  KeEnterCriticalRegion();
  pPVar1 = this + 8;
  ExAcquirePushLockExclusiveEx(pPVar1,0);
  this_00 = *(PCW_QUERY_ITEM **)(this + 0x10);
  do {
    if (this_00 == (PCW_QUERY_ITEM *)(this + 0x10)) {
LAB_140009314:
      ExReleasePushLockExclusiveEx(pPVar1,0);
      KeLeaveCriticalRegion();
      return -0x3ffffddb;
    }
    if (param_1 == *(ulong *)(this_00 + 0x38)) {
      if (this_00 != (PCW_QUERY_ITEM *)0x0) {
        lVar2 = *(longlong *)this_00;
        if ((*(PCW_QUERY_ITEM **)(lVar2 + 8) == this_00) &&
           (plVar3 = *(longlong **)(this_00 + 8), (PCW_QUERY_ITEM *)*plVar3 == this_00)) {
          *plVar3 = lVar2;
          *(longlong **)(lVar2 + 8) = plVar3;
          ExReleasePushLockExclusiveEx(pPVar1,0);
          KeLeaveCriticalRegion();
          LOCK();
          *(int *)(this + 0x30) = *(int *)(this + 0x30) + -1;
          UNLOCK();
          PCW_QUERY_ITEM::~PCW_QUERY_ITEM(this_00);
          ExFreePoolWithTag(this_00,0);
          return 0;
        }
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        lVar5 = (*pcVar4)();
        return lVar5;
      }
      goto LAB_140009314;
    }
    this_00 = *(PCW_QUERY_ITEM **)this_00;
  } while( true );
}



===== Create @ 1400093b8 =====

/* public: static long __cdecl PCW_QUERY::Create(void * __ptr64 * __ptr64,unsigned long,class
   utl::unique_ptr<struct _KEVENT,struct GenericDeleter<struct _KEVENT,__int64 __cdecl(void *
   __ptr64),&__int64 __cdecl ObfDereferenceObject(void * __ptr64)> >) */

long __cdecl PCW_QUERY::Create(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined4 *puVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 *local_res20;
  
  local_res20 = (undefined4 *)0x0;
  lVar4 = PcwpCreateObject(&local_res20,0x38);
  puVar3 = local_res20;
  if (-1 < lVar4) {
    *local_res20 = 0;
    puVar1 = (undefined8 *)(local_res20 + 4);
    *(undefined8 *)(local_res20 + 2) = 0;
    *puVar1 = 0;
    *(undefined8 *)(local_res20 + 6) = 0;
    uVar5 = PsGetCurrentProcess();
    *(undefined8 *)(puVar3 + 8) = uVar5;
    lVar2 = *param_3;
    *param_3 = 0;
    puVar3[0xc] = 0;
    *(longlong *)(puVar3 + 10) = lVar2;
    *(undefined8 **)(puVar3 + 6) = puVar1;
    *puVar1 = puVar1;
    lVar4 = ObInsertObject(puVar3,0,0xf0003,0,0,param_1);
  }
  if (*param_3 != 0) {
    ObfDereferenceObject();
  }
  return lVar4;
}



===== CreateQueryItem @ 140009484 =====

/* public: long __cdecl PCW_QUERY::CreateQueryItem(unsigned long * __ptr64,bool,struct
   _UNICODE_STRING const * __ptr64,class AllocatedUnicodeString && __ptr64,unsigned long,unsigned
   __int64,void * __ptr64) __ptr64 */

long __thiscall
PCW_QUERY::CreateQueryItem
          (PCW_QUERY *this,ulong *param_1,bool param_2,_UNICODE_STRING *param_3,
          AllocatedUnicodeString *param_4,ulong param_5,__uint64 param_6,void *param_7)

{
  PCW_QUERY *pPVar1;
  int iVar2;
  long lVar3;
  PCW_QUERY_ITEM *this_00;
  unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *this_01;
  ReleaseDeleter<PCW_COUNTERSET> *this_02;
  PCW_COUNTERSET *local_res8;
  longlong local_18 [2];
  
  LOCK();
  pPVar1 = this + 0x30;
  iVar2 = *(int *)pPVar1;
  *(int *)pPVar1 = *(int *)pPVar1 + 1;
  UNLOCK();
  if (iVar2 + 1 < 0x10000) {
    local_res8 = (PCW_COUNTERSET *)0x0;
    this_01 = (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)&local_res8;
    lVar3 = PCW_COUNTERSET::FindOrCreate(this_01,param_3,1);
    if (lVar3 < 0) {
      LOCK();
      *(int *)(this + 0x30) = *(int *)(this + 0x30) + -1;
      UNLOCK();
      if (local_res8 != (PCW_COUNTERSET *)0x0) {
        ReleaseDeleter<PCW_COUNTERSET>::operator()
                  ((ReleaseDeleter<PCW_COUNTERSET> *)this_01,local_res8);
      }
    }
    else {
      this_02 = (ReleaseDeleter<PCW_COUNTERSET> *)0x101;
      this_00 = (PCW_QUERY_ITEM *)ExAllocatePool2(0x101,0x68,0x51776350);
      if (this_00 != (PCW_QUERY_ITEM *)0x0) {
        local_18[0] = PCW_QUERY_ITEM::PCW_QUERY_ITEM
                                (this_00,(unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_>
                                          *)&local_res8,param_4,param_2,param_5,&param_6,param_7);
        this_02 = (ReleaseDeleter<PCW_COUNTERSET> *)this_00;
        if (local_18[0] != 0) {
          InsertQueryItem(this,local_18,param_1);
          if (local_res8 != (PCW_COUNTERSET *)0x0) {
            ReleaseDeleter<PCW_COUNTERSET>::operator()
                      ((ReleaseDeleter<PCW_COUNTERSET> *)this,local_res8);
          }
          return 0;
        }
      }
      LOCK();
      *(int *)(this + 0x30) = *(int *)(this + 0x30) + -1;
      UNLOCK();
      if (local_res8 != (PCW_COUNTERSET *)0x0) {
        ReleaseDeleter<PCW_COUNTERSET>::operator()(this_02,local_res8);
      }
      lVar3 = -0x3fffffe9;
    }
  }
  else {
    LOCK();
    *(int *)(this + 0x30) = *(int *)(this + 0x30) + -1;
    UNLOCK();
    lVar3 = -0x3fffff66;
  }
  return lVar3;
}



===== InsertQueryItem @ 1400095bc =====

/* private: void __cdecl PCW_QUERY::InsertQueryItem(class utl::unique_ptr<class
   PCW_QUERY_ITEM,struct utl::default_delete<class PCW_QUERY_ITEM> >,unsigned long * __ptr64)
   __ptr64 */

void __thiscall PCW_QUERY::InsertQueryItem(PCW_QUERY *this,longlong *param_2,int *param_3)

{
  PCW_QUERY_ITEM *this_00;
  code *pcVar1;
  undefined8 *puVar2;
  PCW_QUERY *pPVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(this + 8,0);
  puVar5 = auStack_28;
  pPVar3 = *(PCW_QUERY **)(this + 0x10);
  for (iVar6 = 1; (pPVar3 != this + 0x10 && (iVar6 == *(int *)(pPVar3 + 0x38))); iVar6 = iVar6 + 1)
  {
    pPVar3 = *(PCW_QUERY **)pPVar3;
  }
  *param_3 = iVar6;
  *(int *)(*param_2 + 0x38) = iVar6;
  puVar4 = *(undefined8 **)(pPVar3 + 8);
  puVar2 = (undefined8 *)*param_2;
  if ((PCW_QUERY *)*puVar4 != pPVar3) {
    pPVar3 = (PCW_QUERY *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar2 = (undefined8 *)(*pcVar1)();
    puVar5 = auStack_20;
  }
  *puVar2 = pPVar3;
  puVar2[1] = puVar4;
  *puVar4 = puVar2;
  *(undefined8 **)(pPVar3 + 8) = puVar2;
  *param_2 = 0;
  *(undefined8 *)(puVar5 + -8) = 0x140009656;
  ExReleasePushLockExclusiveEx(this + 8,0);
  *(undefined8 *)(puVar5 + -8) = 0x140009662;
  KeLeaveCriticalRegion();
  this_00 = (PCW_QUERY_ITEM *)*param_2;
  if (this_00 != (PCW_QUERY_ITEM *)0x0) {
    *(undefined8 *)(puVar5 + -8) = 0x140009677;
    PCW_QUERY_ITEM::~PCW_QUERY_ITEM(this_00);
    *(undefined8 *)(puVar5 + -8) = 0x140009683;
    ExFreePoolWithTag(this_00,0);
  }
  return;
}



===== PcwpReferenceObjectByHandle<PCW_QUERY> @ 1400096a8 =====

ulonglong PcwpReferenceObjectByHandle<PCW_QUERY>
                    (longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  longlong lVar1;
  _OBJECT_TYPE *p_Var2;
  ulonglong uVar3;
  int *local_res8;
  
  p_Var2 = PcwObjectType;
  lVar1 = *param_1;
  *param_1 = 0;
  if (lVar1 != 0) {
    ObfDereferenceObject();
  }
  local_res8 = (int *)0x0;
  uVar3 = ObReferenceObjectByHandle(param_2,param_3,p_Var2,1,&local_res8,0);
  *param_1 = (longlong)local_res8;
  if ((-1 < (int)uVar3) && (uVar3 = uVar3 & 0xffffffff, *local_res8 != 0)) {
    uVar3 = 0xc0000024;
  }
  return uVar3;
}



===== PcwpReferenceObjectByHandle<PCW_USER_REGISTRATION> @ 140009744 =====

ulonglong PcwpReferenceObjectByHandle<PCW_USER_REGISTRATION>(longlong *param_1,undefined8 param_2)

{
  longlong lVar1;
  _OBJECT_TYPE *p_Var2;
  ulonglong uVar3;
  int *local_res8;
  
  p_Var2 = PcwObjectType;
  lVar1 = *param_1;
  *param_1 = 0;
  if (lVar1 != 0) {
    ObfDereferenceObject();
  }
  local_res8 = (int *)0x0;
  uVar3 = ObReferenceObjectByHandle(param_2,1,p_Var2,1,&local_res8,0);
  *param_1 = (longlong)local_res8;
  if ((-1 < (int)uVar3) && (uVar3 = uVar3 & 0xffffffff, *local_res8 != 1)) {
    uVar3 = 0xc0000024;
  }
  return uVar3;
}



===== ReferenceObjectByHandle<_KEVENT> @ 1400097d8 =====

void ReferenceObjectByHandle<_KEVENT>
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               longlong *param_5)

{
  longlong lVar1;
  longlong *plVar2;
  
  plVar2 = param_5;
  lVar1 = *param_5;
  *param_5 = 0;
  if (lVar1 != 0) {
    ObfDereferenceObject();
  }
  param_5 = (longlong *)0x0;
  ObReferenceObjectByHandle(param_1,0x100000,param_3,1,&param_5,0);
  *plVar2 = (longlong)param_5;
  return;
}



===== ~AllocatedUnicodeString @ 14000985c =====

/* public: __cdecl AllocatedUnicodeString::~AllocatedUnicodeString(void) __ptr64 */

void __thiscall AllocatedUnicodeString::~AllocatedUnicodeString(AllocatedUnicodeString *this)

{
  if (*(longlong *)(this + 8) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 8),0);
  }
  return;
}



===== Capture @ 140009884 =====

/* public: long __cdecl AllocatedUnicodeString::Capture(unsigned short const * __ptr64,unsigned
   short,enum _MODE) __ptr64 */

long __thiscall
AllocatedUnicodeString::Capture
          (AllocatedUnicodeString *this,ushort *param_1,ushort param_2,_MODE param_3)

{
  undefined1 auVar1 [16];
  long lVar2;
  undefined8 uVar3;
  void *_Dst;
  ushort uVar4;
  
  uVar4 = param_2 & 0xfffe;
  if (uVar4 == 0) {
    lVar2 = -0x3ffffdfa;
  }
  else {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = (ulonglong)(param_2 >> 1) + 1;
    uVar3 = SUB168(ZEXT816(2) * auVar1,0);
    if (SUB168(ZEXT816(2) * auVar1,8) != 0) {
      uVar3 = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePool2(0x101,uVar3,0x54776350);
    if (_Dst == (void *)0x0) {
      lVar2 = -0x3fffff66;
    }
    else {
      if (param_3 == 0) {
        memmove(_Dst,param_1,(ulonglong)uVar4);
      }
      else {
        memmove(_Dst,param_1,(ulonglong)uVar4);
      }
      *(undefined2 *)((longlong)_Dst + (ulonglong)(param_2 >> 1) * 2) = 0;
      if (*(longlong *)(this + 8) != 0) {
        ExFreePoolWithTag(*(longlong *)(this + 8),0);
      }
      *(void **)(this + 8) = _Dst;
      *(ushort *)this = uVar4;
      *(ushort *)(this + 2) = uVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



===== PcwpDispatchCreate @ 1400099c0 =====

/* long __cdecl PcwpDispatchCreate(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl PcwpDispatchCreate(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== PcwpFastIoDeviceControl @ 1400099f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl PcwpFastIoDeviceControl(struct _FILE_OBJECT * __ptr64,unsigned char,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long,unsigned long,struct _IO_STATUS_BLOCK *
   __ptr64,struct _DEVICE_OBJECT * __ptr64) */

uchar __cdecl
PcwpFastIoDeviceControl
          (_FILE_OBJECT *param_1,uchar param_2,void *param_3,ulong param_4,void *param_5,
          ulong param_6,ulong param_7,_IO_STATUS_BLOCK *param_8,_DEVICE_OBJECT *param_9)

{
  _IO_STATUS_BLOCK *p_Var1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  p_Var1 = param_8;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  *(undefined8 *)(param_8 + 8) = 0;
  if ((param_7 | 0x3ffc) == 0x227fff) {
    uVar3 = param_7 >> 2 & 0xfff;
    param_7 = uVar3;
    if (uVar3 < 0x10) {
      uVar4 = (ulonglong)uVar3;
      if ((*(ulong *)(&DAT_140003000 + uVar4 * 0x10) == param_4) &&
         ((*(ulong *)(&DAT_140003004 + uVar4 * 0x10) == param_6 ||
          (*(ulong *)(&DAT_140003004 + uVar4 * 0x10) == 0xffffffff)))) {
        if (param_5 != (void *)0x0) {
          ProbeForWrite(param_5,param_6,1);
        }
        memmove(&local_58,param_3,(ulonglong)param_4);
        param_1 = (_FILE_OBJECT *)&local_58;
        uVar2 = (*(code *)(&PTR_PcwpIoctlCreateQuery_140003008)[uVar4 * 2])
                          (param_1,param_5,&param_6);
        uVar4 = (ulonglong)uVar2;
        *(uint *)p_Var1 = uVar2;
        *(ulonglong *)(p_Var1 + 8) = (ulonglong)param_6;
        if (-1 < (int)uVar2) {
          return '\x01';
        }
        if ((Microsoft_Windows_Diagnosis_PCWEnableBits & 0x10) == 0) {
          return '\x01';
        }
      }
      else {
        *(undefined4 *)param_8 = 0xc0000206;
        if ((Microsoft_Windows_Diagnosis_PCWEnableBits & 0x10) == 0) {
          return '\x01';
        }
        uVar4 = 0xc0000206;
      }
    }
    else {
      *(undefined4 *)param_8 = 0xc0000010;
      if ((Microsoft_Windows_Diagnosis_PCWEnableBits & 0x10) == 0) {
        return '\x01';
      }
      uVar4 = 0xc0000010;
    }
  }
  else {
    *(undefined4 *)param_8 = 0xc0000010;
    if ((Microsoft_Windows_Diagnosis_PCWEnableBits & 0x10) == 0) {
      return '\x01';
    }
    uVar3 = 0xffffffff;
    uVar4 = 0xc0000010;
  }
  McTemplateU0qq_EtwWriteTransfer(param_1,&PcwIoctlFail,uVar4,uVar3);
  return '\x01';
}



===== PcwpIoctlAddQueryItem @ 140009bf0 =====

/* long __cdecl PcwpIoctlAddQueryItem(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long *
   __ptr64) */

long __cdecl PcwpIoctlAddQueryItem(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  PCW_QUERY *pPVar1;
  long lVar2;
  ulonglong uVar3;
  ulong local_res8 [2];
  PCW_QUERY *local_res20;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_res8[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_res20 = (PCW_QUERY *)0x0;
  lVar2 = AllocatedUnicodeString::Capture
                    ((AllocatedUnicodeString *)&local_18,*(ushort **)(param_1 + 0x18),
                     *(ushort *)(param_1 + 2),1);
  if ((-1 < lVar2) &&
     (lVar2 = AllocatedUnicodeString::Capture
                        ((AllocatedUnicodeString *)&local_28,*(ushort **)(param_1 + 0x20),
                         *(ushort *)(param_1 + 4),1), -1 < lVar2)) {
    uVar3 = PcwpReferenceObjectByHandle<PCW_QUERY>
                      ((longlong *)&local_res20,*(undefined8 *)(param_1 + 0x10),2);
    pPVar1 = local_res20;
    lVar2 = (long)uVar3;
    if ((-1 < lVar2) &&
       (lVar2 = PCW_QUERY::CreateQueryItem
                          (local_res20,local_res8,*param_1 != (PCW_IOCTL_INPUT)0x0,
                           (_UNICODE_STRING *)&local_18,(AllocatedUnicodeString *)&local_28,
                           *(ulong *)(param_1 + 8),*(__uint64 *)(param_1 + 0x30),
                           *(void **)(param_1 + 0x28)), -1 < lVar2)) {
      *(ulong *)param_2 = local_res8[0];
      if (pPVar1 != (PCW_QUERY *)0x0) {
        ObfDereferenceObject(pPVar1);
      }
      AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_28);
      AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_18);
      return 0;
    }
    if (pPVar1 != (PCW_QUERY *)0x0) {
      ObfDereferenceObject(pPVar1);
    }
  }
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_28);
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_18);
  return lVar2;
}



===== PcwpIoctlCheckNotifier @ 140009d80 =====

/* long __cdecl PcwpIoctlCheckNotifier(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long
   * __ptr64) */

long __cdecl PcwpIoctlCheckNotifier(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  bool bVar4;
  longlong lVar5;
  int iVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined1 uVar9;
  longlong local_res8;
  
  local_res8 = 0;
  uVar7 = PcwpReferenceObjectByHandle<PCW_USER_REGISTRATION>
                    (&local_res8,*(undefined8 *)(param_1 + 8));
  lVar5 = local_res8;
  iVar6 = (int)uVar7;
  if (iVar6 < 0) {
    if (local_res8 != 0) {
      ObfDereferenceObject();
    }
  }
  else {
    lVar3 = *(longlong *)(local_res8 + 0x18);
    KeEnterCriticalRegion();
    lVar1 = lVar3 + 0x68;
    ExAcquirePushLockSharedEx(lVar1,0);
    plVar2 = (longlong *)(lVar3 + 0x70);
    plVar8 = (longlong *)*plVar2;
    if (plVar8 != plVar2) {
      uVar9 = 1;
      do {
        if (((int)plVar8[2] == *(int *)param_1) &&
           (*(int *)((longlong)plVar8 + 0x14) == *(int *)(param_1 + 4))) {
          bVar4 = true;
        }
        else {
          bVar4 = false;
        }
        if (bVar4) {
          ExReleasePushLockSharedEx(lVar1,0);
          KeLeaveCriticalRegion();
          goto LAB_140009e4e;
        }
        plVar8 = (longlong *)*plVar8;
      } while (plVar8 != plVar2);
    }
    ExReleasePushLockSharedEx(lVar1,0);
    KeLeaveCriticalRegion();
    uVar9 = 0;
LAB_140009e4e:
    *(undefined1 *)param_2 = uVar9;
    ObfDereferenceObject(lVar5);
    iVar6 = 0;
  }
  return iVar6;
}



===== PcwpIoctlCollect @ 140009ec0 =====

/* long __cdecl PcwpIoctlCollect(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long *
   __ptr64) */

long __cdecl PcwpIoctlCollect(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  PCW_QUERY *pPVar1;
  int iVar2;
  ulonglong uVar3;
  PCW_QUERY *local_res8;
  
  local_res8 = (PCW_QUERY *)0x0;
  uVar3 = PcwpReferenceObjectByHandle<PCW_QUERY>((longlong *)&local_res8,*(undefined8 *)param_1,1);
  pPVar1 = local_res8;
  iVar2 = (int)uVar3;
  if (iVar2 < 0) {
    if (local_res8 != (PCW_QUERY *)0x0) {
      ObfDereferenceObject();
    }
  }
  else {
    iVar2 = PCW_QUERY::Collect(local_res8,param_2,*param_3,param_3);
    if (pPVar1 != (PCW_QUERY *)0x0) {
      ObfDereferenceObject(pPVar1);
    }
  }
  return iVar2;
}



===== PcwpIoctlCompleteNotification @ 140009f60 =====

/* long __cdecl PcwpIoctlCompleteNotification(union PCW_IOCTL_INPUT * __ptr64,void *
   __ptr64,unsigned long * __ptr64) */

long __cdecl PcwpIoctlCompleteNotification(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  PCW_USER_REGISTRATION *pPVar1;
  int iVar2;
  ulonglong uVar3;
  bool local_res8 [8];
  PCW_USER_REGISTRATION *local_res20;
  
  local_res8[0] = false;
  local_res20 = (PCW_USER_REGISTRATION *)0x0;
  uVar3 = PcwpReferenceObjectByHandle<PCW_USER_REGISTRATION>
                    ((longlong *)&local_res20,*(undefined8 *)param_1);
  pPVar1 = local_res20;
  iVar2 = (int)uVar3;
  if ((iVar2 < 0) ||
     (iVar2 = PCW_USER_REGISTRATION::CompleteInFlightNotification
                        (local_res20,local_res8,*(ulong *)(param_1 + 0x14),*(void **)(param_1 + 8),
                         *(ulong *)(param_1 + 0x10)), iVar2 < 0)) {
    if (pPVar1 != (PCW_USER_REGISTRATION *)0x0) {
      ObfDereferenceObject(pPVar1);
    }
  }
  else {
    *(bool *)param_2 = local_res8[0];
    if (pPVar1 != (PCW_USER_REGISTRATION *)0x0) {
      ObfDereferenceObject(pPVar1);
    }
    iVar2 = 0;
  }
  return iVar2;
}



===== PcwpIoctlCreateNotifier @ 14000a060 =====

/* long __cdecl PcwpIoctlCreateNotifier(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long
   * __ptr64) */

long __cdecl PcwpIoctlCreateNotifier(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  long lVar1;
  void *local_res8;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_res8 = (void *)0x0;
  lVar1 = AllocatedUnicodeString::Capture
                    ((AllocatedUnicodeString *)&local_18,*(ushort **)(param_1 + 8),
                     *(ushort *)param_1,1);
  if ((lVar1 < 0) ||
     (lVar1 = PCW_NOTIFIER::Create(&local_res8,(_UNICODE_STRING *)&local_18), lVar1 < 0)) {
    AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_18);
    return lVar1;
  }
  *(void **)param_2 = local_res8;
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_18);
  return 0;
}



===== PcwpIoctlCreateQuery @ 14000a100 =====

/* long __cdecl PcwpIoctlCreateQuery(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long *
   __ptr64) */

long __cdecl PcwpIoctlCreateQuery(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 in_R9;
  longlong local_res8;
  undefined8 local_res20;
  
  local_res8 = 0;
  local_res20 = 0;
  if ((*(longlong *)param_1 == 0) ||
     (iVar1 = ReferenceObjectByHandle<_KEVENT>
                        (*(longlong *)param_1,param_2,*(undefined8 *)ExEventObjectType_exref,in_R9,
                         &local_res8), -1 < iVar1)) {
    lVar2 = PCW_QUERY::Create(&local_res20);
    if (-1 < lVar2) {
      *(undefined8 *)param_2 = local_res20;
      lVar2 = 0;
    }
    return lVar2;
  }
  if (local_res8 != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== PcwpIoctlDisconnect @ 14000a1a0 =====

/* long __cdecl PcwpIoctlDisconnect(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long *
   __ptr64) */

long __cdecl PcwpIoctlDisconnect(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  PCW_USER_REGISTRATION *pPVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  PCW_USER_REGISTRATION *local_res8;
  
  local_res8 = (PCW_USER_REGISTRATION *)0x0;
  uVar4 = PcwpReferenceObjectByHandle<PCW_USER_REGISTRATION>
                    ((longlong *)&local_res8,*(undefined8 *)param_1);
  pPVar1 = local_res8;
  iVar3 = (int)uVar4;
  if (iVar3 < 0) {
    if (local_res8 != (PCW_USER_REGISTRATION *)0x0) {
      ObfDereferenceObject();
    }
  }
  else {
    bVar2 = PCW_USER_REGISTRATION::Disconnect(local_res8);
    *(bool *)param_2 = bVar2;
    if (pPVar1 != (PCW_USER_REGISTRATION *)0x0) {
      ObfDereferenceObject(pPVar1);
    }
    iVar3 = 0;
  }
  return iVar3;
}



===== PcwpIoctlEnumerateInstances @ 14000a240 =====

/* long __cdecl PcwpIoctlEnumerateInstances(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned
   long * __ptr64) */

long __cdecl PcwpIoctlEnumerateInstances(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  long lVar1;
  int iVar2;
  ushort *puVar3;
  _KEVENT *p_Var4;
  undefined8 uVar5;
  _KEVENT *local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8 = (_KEVENT *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar1 = AllocatedUnicodeString::Capture
                    ((AllocatedUnicodeString *)&local_28,*(ushort **)(param_1 + 8),
                     *(ushort *)param_1,1);
  if (-1 < lVar1) {
    uVar5 = 1;
    puVar3 = *(ushort **)(param_1 + 0x10);
    lVar1 = AllocatedUnicodeString::Capture
                      ((AllocatedUnicodeString *)&local_38,puVar3,*(ushort *)(param_1 + 2),1);
    if (-1 < lVar1) {
      p_Var4 = (_KEVENT *)0x0;
      if (*(longlong *)(param_1 + 0x18) != 0) {
        iVar2 = ReferenceObjectByHandle<_KEVENT>
                          (*(longlong *)(param_1 + 0x18),puVar3,
                           *(undefined8 *)ExEventObjectType_exref,uVar5,(longlong *)&local_res8);
        if (iVar2 < 0) {
          AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_38);
          AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_28);
          if (local_res8 != (_KEVENT *)0x0) {
            ObfDereferenceObject();
          }
          return iVar2;
        }
        p_Var4 = local_res8;
      }
      lVar1 = PcwpEnumerateInstances
                        (p_Var4,(_UNICODE_STRING *)&local_28,(_UNICODE_STRING *)&local_38,param_2,
                         *param_3,param_3);
      AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_38);
      AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_28);
      if (p_Var4 != (_KEVENT *)0x0) {
        ObfDereferenceObject(p_Var4);
      }
      return lVar1;
    }
  }
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_38);
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_28);
  return lVar1;
}



===== PcwpIoctlGetSecurity @ 14000a390 =====

/* long __cdecl PcwpIoctlGetSecurity(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long *
   __ptr64) */

long __cdecl PcwpIoctlGetSecurity(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  long lVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  lVar1 = AllocatedUnicodeString::Capture
                    ((AllocatedUnicodeString *)&local_18,*(ushort **)(param_1 + 8),
                     *(ushort *)(param_1 + 4),1);
  if (-1 < lVar1) {
    lVar1 = PcwpGetCounterSetSecurityDescriptor
                      ((_UNICODE_STRING *)&local_18,*(ulong *)param_1,param_2,param_3);
    if (lVar1 == -0x3fffffdd) {
      lVar1 = -0x7ffffffb;
    }
  }
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_18);
  return lVar1;
}



===== PcwpIoctlModifyQueryItem @ 14000a420 =====

/* long __cdecl PcwpIoctlModifyQueryItem(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned
   long * __ptr64) */

long __cdecl PcwpIoctlModifyQueryItem(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong local_res8;
  
  local_res8 = 0;
  uVar4 = PcwpReferenceObjectByHandle<PCW_QUERY>(&local_res8,*(undefined8 *)(param_1 + 8),2);
  iVar3 = (int)uVar4;
  if (iVar3 < 0) {
    if (local_res8 != 0) {
      ObfDereferenceObject();
    }
  }
  else {
    uVar1 = *(undefined8 *)(param_1 + 0x10);
    iVar3 = *(int *)param_1;
    KeEnterCriticalRegion();
    lVar2 = local_res8;
    ExAcquirePushLockExclusiveEx(local_res8 + 8,0);
    for (puVar5 = *(undefined8 **)(lVar2 + 0x10); puVar5 != (undefined8 *)(lVar2 + 0x10);
        puVar5 = (undefined8 *)*puVar5) {
      if (iVar3 == *(int *)(puVar5 + 7)) {
        if (puVar5 != (undefined8 *)0x0) {
          iVar3 = 0;
          puVar5[9] = uVar1;
          goto LAB_14000a4b3;
        }
        break;
      }
    }
    iVar3 = -0x3ffffddb;
LAB_14000a4b3:
    ExReleasePushLockExclusiveEx(lVar2 + 8,0);
    KeLeaveCriticalRegion();
    if (lVar2 != 0) {
      ObfDereferenceObject(lVar2);
    }
  }
  return iVar3;
}



===== PcwpIoctlNotify @ 14000a510 =====

/* long __cdecl PcwpIoctlNotify(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long *
   __ptr64) */

long __cdecl PcwpIoctlNotify(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  PCW_NOTIFIER *pPVar1;
  long lVar2;
  PCW_NOTIFIER *local_res8;
  
  local_res8 = (PCW_NOTIFIER *)0x0;
  lVar2 = ObReferenceObjectByHandle(*(undefined8 *)(param_1 + 8),2,PcwObjectType,1,&local_res8,0);
  pPVar1 = local_res8;
  if ((-1 < lVar2) && (*(int *)local_res8 != 2)) {
    lVar2 = -0x3fffffdc;
  }
  if (-1 < lVar2) {
    lVar2 = PCW_NOTIFIER::SendNotification
                      (local_res8,*(ulong *)(param_1 + 0x1c),
                       (_LARGE_INTEGER *)
                       (-(ulonglong)(param_1[0x20] != (PCW_IOCTL_INPUT)0x0) & (ulonglong)param_1),
                       *(void **)(param_1 + 0x10),*(ulong *)(param_1 + 0x18),param_2,*param_3,
                       param_3);
  }
  if (pPVar1 != (PCW_NOTIFIER *)0x0) {
    ObfDereferenceObject(pPVar1);
  }
  return lVar2;
}



===== PcwpIoctlReadNotificationData @ 14000a610 =====

/* long __cdecl PcwpIoctlReadNotificationData(union PCW_IOCTL_INPUT * __ptr64,void *
   __ptr64,unsigned long * __ptr64) */

long __cdecl PcwpIoctlReadNotificationData(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  PCW_USER_REGISTRATION *pPVar1;
  int iVar2;
  ulonglong uVar3;
  PCW_USER_REGISTRATION *local_res8;
  
  local_res8 = (PCW_USER_REGISTRATION *)0x0;
  uVar3 = PcwpReferenceObjectByHandle<PCW_USER_REGISTRATION>
                    ((longlong *)&local_res8,*(undefined8 *)param_1);
  pPVar1 = local_res8;
  iVar2 = (int)uVar3;
  if (iVar2 < 0) {
    if (local_res8 != (PCW_USER_REGISTRATION *)0x0) {
      ObfDereferenceObject();
    }
  }
  else {
    iVar2 = PCW_USER_REGISTRATION::ReadInFlightNotificationBuffer
                      (local_res8,param_2,*param_3,param_3);
    if (pPVar1 != (PCW_USER_REGISTRATION *)0x0) {
      ObfDereferenceObject(pPVar1);
    }
  }
  return iVar2;
}



===== PcwpIoctlRegister @ 14000a6a0 =====

/* long __cdecl PcwpIoctlRegister(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long *
   __ptr64) */

long __cdecl PcwpIoctlRegister(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  longlong local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  longlong local_28;
  longlong lStack_20;
  longlong local_18 [2];
  
  local_res8 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar3 = ObReferenceObjectByHandle
                    (*(undefined8 *)(param_1 + 0x10),0,*(undefined8 *)IoFileObjectType_exref,1,
                     &local_res8,0);
  lVar2 = local_res8;
  if (iVar3 < 0) {
    if (local_res8 != 0) {
      ObfDereferenceObject();
    }
  }
  else {
    plVar4 = ReferenceCompletionContext(local_18,local_res8);
    lVar1 = *plVar4;
    lStack_20 = plVar4[1];
    local_28 = lVar1;
    if (lVar1 == 0) {
      if (lVar2 != 0) {
        ObfDereferenceObject(lVar2);
      }
      iVar3 = -0x3ffffff8;
    }
    else {
      iVar3 = AllocatedUnicodeString::Capture
                        ((AllocatedUnicodeString *)&local_38,*(ushort **)(param_1 + 8),
                         *(ushort *)param_1,1);
      if (iVar3 < 0) {
        ObfDereferenceObject(lVar1);
        if (lVar2 != 0) {
          ObfDereferenceObject(lVar2);
        }
      }
      else {
        local_res8 = lVar1;
        iVar3 = PCW_USER_REGISTRATION::Create(param_2,&local_38,&local_res8,lStack_20);
        if (lVar2 != 0) {
          ObfDereferenceObject(lVar2);
        }
      }
    }
  }
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_38);
  return iVar3;
}



===== PcwpIoctlRemoveQueryItem @ 14000a800 =====

/* long __cdecl PcwpIoctlRemoveQueryItem(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned
   long * __ptr64) */

long __cdecl PcwpIoctlRemoveQueryItem(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  PCW_QUERY *pPVar1;
  int iVar2;
  ulonglong uVar3;
  PCW_QUERY *local_res8;
  
  local_res8 = (PCW_QUERY *)0x0;
  uVar3 = PcwpReferenceObjectByHandle<PCW_QUERY>
                    ((longlong *)&local_res8,*(undefined8 *)(param_1 + 8),2);
  pPVar1 = local_res8;
  iVar2 = (int)uVar3;
  if (iVar2 < 0) {
    if (local_res8 != (PCW_QUERY *)0x0) {
      ObfDereferenceObject();
    }
  }
  else {
    iVar2 = PCW_QUERY::CloseQueryItem(local_res8,*(ulong *)param_1);
    if (pPVar1 != (PCW_QUERY *)0x0) {
      ObfDereferenceObject(pPVar1);
    }
  }
  return iVar2;
}



===== PcwpIoctlSetSecurity @ 14000a880 =====

/* long __cdecl PcwpIoctlSetSecurity(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned long *
   __ptr64) */

long __cdecl PcwpIoctlSetSecurity(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  long lVar1;
  void *local_res8;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = (void *)0x0;
  local_18 = 0;
  uStack_10 = 0;
  lVar1 = AllocatedUnicodeString::Capture
                    ((AllocatedUnicodeString *)&local_18,*(ushort **)(param_1 + 0x10),
                     *(ushort *)param_1,1);
  if (-1 < lVar1) {
    if (param_1[2] == (PCW_IOCTL_INPUT)0x0) {
      lVar1 = SeCaptureSecurityDescriptor(*(undefined8 *)(param_1 + 8),1,1,1,&local_res8);
      if (-1 < lVar1) {
        lVar1 = PcwpSetCounterSetSecurityDescriptor
                          ((_UNICODE_STRING *)&local_18,*(ulong *)(param_1 + 4),local_res8);
        SeReleaseSecurityDescriptor(local_res8,1);
      }
    }
    else {
      lVar1 = PcwpClearCounterSetSecurityDescriptor((_UNICODE_STRING *)&local_18);
    }
  }
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_18);
  return lVar1;
}



===== PcwpIoctlStatelessNotify @ 14000a940 =====

/* long __cdecl PcwpIoctlStatelessNotify(union PCW_IOCTL_INPUT * __ptr64,void * __ptr64,unsigned
   long * __ptr64) */

long __cdecl PcwpIoctlStatelessNotify(PCW_IOCTL_INPUT *param_1,void *param_2,ulong *param_3)

{
  long lVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  lVar1 = AllocatedUnicodeString::Capture
                    ((AllocatedUnicodeString *)&local_18,*(ushort **)(param_1 + 0x20),
                     *(ushort *)(param_1 + 0x1a),1);
  if (lVar1 < 0) {
    AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_18);
  }
  else {
    lVar1 = PcwpSendStatelessNotification
                      ((_UNICODE_STRING *)&local_18,*(ulong *)(param_1 + 0x14),
                       (_LARGE_INTEGER *)
                       (-(ulonglong)(param_1[0x18] != (PCW_IOCTL_INPUT)0x0) & (ulonglong)param_1),
                       *(void **)(param_1 + 8),*(ulong *)(param_1 + 0x10),param_2,*param_3,param_3);
    AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_18);
  }
  return lVar1;
}



===== McGenControlCallbackV2 @ 14000aa30 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 14000ab40 =====

void McGenEventRegister_EtwRegister(void)

{
  if (PCW_EVENT_PROVIDER_Context == 0) {
    EtwRegister(&PCW_EVENT_PROVIDER,McGenControlCallbackV2,&PCW_EVENT_PROVIDER_Context,
                &PCW_EVENT_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 14000ab80 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (PCW_EVENT_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    PCW_EVENT_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 14000abb4 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140011118;
  uVar2 = 0;
  if (DAT_140011118 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140011118;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(PCW_EVENT_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateU0qq_EtwWriteTransfer @ 14000ac18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res18;
  local_28 = local_res20;
  local_2c = 0;
  local_30 = 4;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(4,param_2,param_3,3,local_48);
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000ac88 =====

/* WARNING: Removing unreachable block (ram,0x00014000acb0) */
/* WARNING: Removing unreachable block (ram,0x00014000acc0) */
/* WARNING: Removing unreachable block (ram,0x00014000acc5) */
/* WARNING: Removing unreachable block (ram,0x00014000acca) */
/* WARNING: Removing unreachable block (ram,0x00014000acd5) */
/* WARNING: Removing unreachable block (ram,0x00014000acea) */
/* WARNING: Removing unreachable block (ram,0x00014000ace0) */
/* WARNING: Removing unreachable block (ram,0x00014000acfa) */
/* WARNING: Removing unreachable block (ram,0x00014000ad17) */
/* WARNING: Removing unreachable block (ram,0x00014000ad26) */
/* WARNING: Removing unreachable block (ram,0x00014000ad2b) */
/* WARNING: Removing unreachable block (ram,0x00014000ad1d) */
/* WARNING: Removing unreachable block (ram,0x00014000ad2d) */
/* WARNING: Removing unreachable block (ram,0x00014000ad32) */
/* WARNING: Removing unreachable block (ram,0x00014000ad22) */
/* WARNING: Removing unreachable block (ram,0x00014000acb5) */
/* WARNING: Removing unreachable block (ram,0x00014000acbe) */
/* WARNING: Removing unreachable block (ram,0x00014000ad3d) */
/* WARNING: Removing unreachable block (ram,0x00014000ad42) */
/* WARNING: Removing unreachable block (ram,0x00014000ad34) */
/* WARNING: Removing unreachable block (ram,0x00014000ad65) */
/* WARNING: Removing unreachable block (ram,0x00014000ad44) */
/* WARNING: Removing unreachable block (ram,0x00014000ad5e) */
/* WARNING: Removing unreachable block (ram,0x00014000ad63) */
/* WARNING: Removing unreachable block (ram,0x00014000ad55) */
/* WARNING: Removing unreachable block (ram,0x00014000ad5a) */
/* WARNING: Removing unreachable block (ram,0x00014000ad39) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000ad78 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = *param_1;
  if ((uVar6 >> 9 & 1) == 0) {
    uVar3 = uVar6;
  }
  else {
    uVar4 = uVar6 >> 6 & 1;
    if ((uVar4 != 0) && (plVar5 = *(longlong **)(param_2 + 0x20), plVar5 != (longlong *)0x0)) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)*plVar5;
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000ae14;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000ae14;
          }
          uVar4 = 1;
          plVar5 = plVar5 + 1;
        }
        uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                          ((uint *)*puVar1,(longlong)puVar1);
        if ((uVar4 == 0) || ((uVar2 & 1) == 0)) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        plVar5 = plVar5 + 1;
      } while (uVar4 != 0);
    }
LAB_14000ae14:
    do {
      uVar2 = uVar6 & 0xffffffce;
      if ((uVar6 & 1) == uVar4) {
        uVar2 = uVar6 & 0xfffffffe;
      }
      uVar3 = uVar2 & 0xfffffdff | uVar4;
      LOCK();
      uVar2 = *param_1;
      bVar7 = uVar6 == uVar2;
      if (bVar7) {
        *param_1 = uVar3;
      }
      else {
        uVar6 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000ae80 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (plVar2 = &wil_details_featureDescriptors_a; plVar2 < &wil_details_featureDescriptors_a;
          plVar2 = plVar2 + 1) {
        if (*plVar2 != 0) {
          do {
            if (plVar2 == (longlong *)0x0) {
              return;
            }
            if ((*(uint *)plVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
            }
            plVar2 = plVar2 + 7;
            while( true ) {
              if (&UNK_1400046f7 < plVar2) {
                return;
              }
              if (*plVar2 != 0) break;
              plVar2 = plVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_RecordCachedUsage @ 14000af00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
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
    bVar6 = uVar2 == uVar4;
    if (bVar6) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar6);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
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
  if (0 < (longlong)puVar5 - (longlong)&local_48 >> 3) {
    wil_details_RecordFeatureUsageCallback();
  }
  return;
}



===== wil_details_RecordFeatureUsageCallback @ 14000b04c =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 14000b070 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000b100 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
      plVar3 = plVar3 + 1) {
    if (*plVar3 != 0) goto LAB_14000b1fd;
  }
LAB_14000b206:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000b1fd:
  if (plVar3 == (longlong *)0x0) goto LAB_14000b206;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000b1ce:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000b1ce;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*plVar3 = *(uint *)*plVar3 ^ (*(uint *)*plVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_1400046f7 < plVar3) goto LAB_14000b206;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_14000b1fd;
}



===== PCW_NOTIFICATION @ 14000b22c =====

/* public: __cdecl PCW_NOTIFICATION::PCW_NOTIFICATION(struct _LUID const & __ptr64,unsigned
   long,struct _KEVENT * __ptr64,void const * __ptr64,unsigned long,void * __ptr64,unsigned long)
   __ptr64 */

PCW_NOTIFICATION * __thiscall
PCW_NOTIFICATION::PCW_NOTIFICATION
          (PCW_NOTIFICATION *this,_LUID *param_1,ulong param_2,_KEVENT *param_3,void *param_4,
          ulong param_5,void *param_6,ulong param_7)

{
  undefined8 uVar1;
  
  *(undefined8 *)this = 0;
  *(_KEVENT **)(this + 8) = param_3;
  uVar1 = *(undefined8 *)param_1;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined8 *)(this + 0x10) = uVar1;
  *(ulong *)(this + 0x18) = param_2;
  uVar1 = PsGetCurrentProcess();
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x20) = uVar1;
  *(void **)(this + 0x28) = param_4;
  *(void **)(this + 0x30) = param_6;
  *(ulong *)(this + 0x38) = param_5;
  *(ulong *)(this + 0x3c) = param_7;
  this[0x44] = (PCW_NOTIFICATION)0x0;
  *(undefined4 *)(this + 0x4c) = 1;
  return this;
}



===== PCW_NOTIFIER @ 14000b2a0 =====

/* private: __cdecl PCW_NOTIFIER::PCW_NOTIFIER(class utl::unique_ptr<class PCW_COUNTERSET,struct
   ReleaseDeleter<class PCW_COUNTERSET> > && __ptr64,struct _LUID const & __ptr64) __ptr64 */

PCW_NOTIFIER * __thiscall
PCW_NOTIFIER::PCW_NOTIFIER
          (PCW_NOTIFIER *this,unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *param_1,
          _LUID *param_2)

{
  PCW_NOTIFIER *pPVar1;
  code *pcVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  *(undefined4 *)this = 2;
  pPVar1 = this + 8;
  *(longlong *)pPVar1 = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = *(undefined8 *)param_2;
  lVar3 = *(longlong *)param_1;
  *(undefined8 *)param_1 = 0;
  *(longlong *)(this + 0x20) = lVar3;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar3 + 0x68,0);
  puVar5 = auStack_28;
  lVar3 = *(longlong *)(this + 0x20) + 0x70;
  plVar4 = *(longlong **)(*(longlong *)(this + 0x20) + 0x78);
  if (*plVar4 != lVar3) {
    plVar4 = (longlong *)0x3;
    pcVar2 = (code *)swi(0x29);
    lVar3 = (*pcVar2)();
    puVar5 = auStack_20;
  }
  *(longlong **)(this + 0x10) = plVar4;
  *(longlong *)pPVar1 = lVar3;
  *plVar4 = (longlong)pPVar1;
  *(PCW_NOTIFIER **)(lVar3 + 8) = pPVar1;
  lVar3 = *(longlong *)(this + 0x20);
  *(undefined8 *)(puVar5 + -8) = 0x14000b329;
  ExReleasePushLockExclusiveEx(lVar3 + 0x68,0);
  *(undefined8 *)(puVar5 + -8) = 0x14000b335;
  KeLeaveCriticalRegion();
  return this;
}



===== PCW_USER_REGISTRATION @ 14000b354 =====

/* private: __cdecl PCW_USER_REGISTRATION::PCW_USER_REGISTRATION(class utl::unique_ptr<class
   PCW_COUNTERSET,struct ReleaseDeleter<class PCW_COUNTERSET> > && __ptr64,class
   utl::unique_ptr<void,struct GenericDeleter<void,__int64 __cdecl(void * __ptr64),&__int64 __cdecl
   ObfDereferenceObject(void * __ptr64)> >,void * __ptr64 const,class utl::unique_ptr<struct
   _IO_MINI_COMPLETION_PACKET_USER,struct GenericDeleter<struct _IO_MINI_COMPLETION_PACKET_USER,void
   __cdecl(struct _IO_MINI_COMPLETION_PACKET_USER * __ptr64),&void __cdecl
   IoFreeMiniCompletionPacket(struct _IO_MINI_COMPLETION_PACKET_USER * __ptr64)> > && __ptr64)
   __ptr64 */

PCW_USER_REGISTRATION * __thiscall
PCW_USER_REGISTRATION::PCW_USER_REGISTRATION
          (PCW_USER_REGISTRATION *this,undefined8 *param_1,longlong *param_3,undefined8 param_4,
          undefined8 *param_5)

{
  PCW_USER_REGISTRATION *pPVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 uVar4;
  
  *(undefined4 *)this = 1;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  uVar2 = *param_1;
  *param_1 = 0;
  pPVar1 = this + 0x40;
  *(undefined8 *)(this + 0x18) = uVar2;
  *(undefined8 *)(this + 0x20) = 0;
  lVar3 = *param_3;
  *param_3 = 0;
  *(longlong *)(this + 0x28) = lVar3;
  *(undefined8 *)(this + 0x30) = param_4;
  uVar2 = *param_5;
  *param_5 = 0;
  *(undefined8 *)(this + 0x38) = uVar2;
  *(undefined8 *)pPVar1 = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  uVar4 = PsGetCurrentProcessId();
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x58) = uVar4;
  *(PCW_USER_REGISTRATION **)(this + 0x48) = pPVar1;
  *(PCW_USER_REGISTRATION **)pPVar1 = pPVar1;
  *(PCW_USER_REGISTRATION **)(*(longlong *)(this + 0x38) + 0x40) = this;
  ObfReferenceObject(this);
  if (*param_3 != 0) {
    ObfDereferenceObject();
  }
  return this;
}



===== ~PCW_NOTIFIER @ 14000b414 =====

/* public: __cdecl PCW_NOTIFIER::~PCW_NOTIFIER(void) __ptr64 */

void __thiscall PCW_NOTIFIER::~PCW_NOTIFIER(PCW_NOTIFIER *this)

{
  PCW_NOTIFIER *pPVar1;
  PCW_NOTIFIER *pPVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  pPVar1 = this + 8;
  pPVar2 = this + 0x20;
  if (*(longlong *)pPVar1 != 0) {
    lVar3 = *(longlong *)pPVar2;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar3 + 0x68,0);
    lVar3 = *(longlong *)pPVar1;
    if ((*(PCW_NOTIFIER **)(lVar3 + 8) != pPVar1) ||
       (plVar4 = *(longlong **)(this + 0x10), (PCW_NOTIFIER *)*plVar4 != pPVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    ExReleasePushLockExclusiveEx(*(longlong *)pPVar2 + 0x68,0);
    KeLeaveCriticalRegion();
    SendDisconnectNotification(this);
  }
  if (*(PCW_COUNTERSET **)pPVar2 != (PCW_COUNTERSET *)0x0) {
    ReleaseDeleter<PCW_COUNTERSET>::operator()
              ((ReleaseDeleter<PCW_COUNTERSET> *)this,*(PCW_COUNTERSET **)pPVar2);
  }
  return;
}



===== ~PCW_USER_REGISTRATION @ 14000b4cc =====

/* private: __cdecl PCW_USER_REGISTRATION::~PCW_USER_REGISTRATION(void) __ptr64 */

void __thiscall PCW_USER_REGISTRATION::~PCW_USER_REGISTRATION(PCW_USER_REGISTRATION *this)

{
  PCW_USER_REGISTRATION *pPVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  ReleaseDeleter<PCW_COUNTERSET> *this_00;
  
  pPVar1 = this + 8;
  if (*(longlong *)pPVar1 != 0) {
    lVar4 = *(longlong *)(*(longlong *)(this + 0x18) + 0x50);
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar4 + 0x50);
    lVar4 = *(longlong *)pPVar1;
    if ((*(PCW_USER_REGISTRATION **)(lVar4 + 8) != pPVar1) ||
       (plVar5 = *(longlong **)(this + 0x10), (PCW_USER_REGISTRATION *)*plVar5 != pPVar1)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    ExReleasePushLockExclusiveEx(*(longlong *)(*(longlong *)(this + 0x18) + 0x50) + 0x50);
    KeLeaveCriticalRegion();
  }
  if (*(PCW_NOTIFICATION **)(this + 0x50) != (PCW_NOTIFICATION *)0x0) {
    PCW_NOTIFICATION::Complete
              (*(PCW_NOTIFICATION **)(this + 0x50),(PCW_REPLYITEM_BUFFER *)0x0,(void *)0x0);
  }
  lVar4 = *(longlong *)(this + 0x50);
  if (lVar4 != 0) {
    LOCK();
    piVar2 = (int *)(lVar4 + 0x4c);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      ExFreePoolWithTag(lVar4,0);
    }
  }
  if (*(longlong *)(this + 0x38) != 0) {
    IoFreeMiniCompletionPacket();
  }
  this_00 = *(ReleaseDeleter<PCW_COUNTERSET> **)(this + 0x28);
  if (this_00 != (ReleaseDeleter<PCW_COUNTERSET> *)0x0) {
    ObfDereferenceObject();
  }
  if (*(PCW_COUNTERSET **)(this + 0x18) != (PCW_COUNTERSET *)0x0) {
    ReleaseDeleter<PCW_COUNTERSET>::operator()(this_00,*(PCW_COUNTERSET **)(this + 0x18));
  }
  return;
}



===== Complete @ 14000b5e4 =====

/* public: long __cdecl PCW_NOTIFICATION::Complete(struct PCW_REPLYITEM_BUFFER * __ptr64,void const
   * __ptr64) __ptr64 */

long __thiscall
PCW_NOTIFICATION::Complete(PCW_NOTIFICATION *this,PCW_REPLYITEM_BUFFER *param_1,void *param_2)

{
  PCW_NOTIFICATION *pPVar1;
  int iVar2;
  long lVar3;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(this,0);
  if (this[0x44] == (PCW_NOTIFICATION)0x0) {
    lVar3 = 0;
    if (param_1 != (PCW_REPLYITEM_BUFFER *)0x0) {
      lVar3 = CopyToNotificationBuffer(this,param_1,param_2);
      if (-1 < lVar3) {
        *(int *)(this + 0x48) = *(int *)(this + 0x48) + 1;
      }
    }
    LOCK();
    pPVar1 = this + 0x1c;
    iVar2 = *(int *)pPVar1;
    *(int *)pPVar1 = *(int *)pPVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      KeSetEvent(*(undefined8 *)(this + 8),0,0);
    }
  }
  else {
    lVar3 = 0;
  }
  ExReleasePushLockExclusiveEx(this,0);
  KeLeaveCriticalRegion();
  return lVar3;
}



===== CompleteInFlightNotification @ 14000b698 =====

/* public: long __cdecl PCW_USER_REGISTRATION::CompleteInFlightNotification(bool * __ptr64,unsigned
   long,void const * __ptr64,unsigned long) __ptr64 */

long __thiscall
PCW_USER_REGISTRATION::CompleteInFlightNotification
          (PCW_USER_REGISTRATION *this,bool *param_1,ulong param_2,void *param_3,ulong param_4)

{
  PCW_USER_REGISTRATION *pPVar1;
  PCW_USER_REGISTRATION *pPVar2;
  int *piVar3;
  int iVar4;
  PCW_USER_REGISTRATION *pPVar5;
  longlong lVar6;
  code *pcVar7;
  undefined1 *puVar8;
  long lVar9;
  longlong local_res8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  ulong local_24;
  undefined4 local_20;
  ulong local_1c;
  
  KeEnterCriticalRegion();
  pPVar1 = this + 0x20;
  ExAcquirePushLockExclusiveEx(pPVar1,0);
  puVar8 = auStack_48;
  if ((this[0x5f] == (PCW_USER_REGISTRATION)0x0) ||
     (puVar8 = auStack_48, this[0x5c] != (PCW_USER_REGISTRATION)0x0)) {
LAB_14000b819:
    *(undefined8 *)(puVar8 + -8) = 0x14000b825;
    ExReleasePushLockExclusiveEx(pPVar1,0);
    *(undefined8 *)(puVar8 + -8) = 0x14000b831;
    KeLeaveCriticalRegion();
    lVar9 = -0x3ffffe7c;
  }
  else {
    if (*(longlong *)(this + 0x50) == 0) {
      lVar9 = 0;
    }
    else {
      local_28 = 0;
      local_24 = param_4;
      local_20 = PsGetCurrentProcessId();
      local_1c = param_2;
      lVar9 = PCW_NOTIFICATION::Complete
                        (*(PCW_NOTIFICATION **)(this + 0x50),(PCW_REPLYITEM_BUFFER *)&local_28,
                         param_3);
      lVar6 = *(longlong *)(this + 0x50);
      *(undefined8 *)(this + 0x50) = 0;
      if (lVar6 != 0) {
        LOCK();
        piVar3 = (int *)(lVar6 + 0x4c);
        iVar4 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar4 == 1) {
          ExFreePoolWithTag(lVar6,0);
        }
      }
    }
    this[0x5f] = (PCW_USER_REGISTRATION)0x0;
    *param_1 = (bool)this[0x5d];
    if (this[0x5d] == (PCW_USER_REGISTRATION)0x0) {
      if (this[0x5e] == (PCW_USER_REGISTRATION)0x0) {
        pPVar2 = this + 0x40;
        while( true ) {
          pPVar5 = *(PCW_USER_REGISTRATION **)pPVar2;
          if (pPVar5 == pPVar2) break;
          if ((*(PCW_USER_REGISTRATION **)(pPVar5 + 8) != pPVar2) ||
             (lVar6 = *(longlong *)pPVar5, *(PCW_USER_REGISTRATION **)(lVar6 + 8) != pPVar5)) {
            pcVar7 = (code *)swi(0x29);
            (*pcVar7)(3);
            puVar8 = auStack_40;
            goto LAB_14000b819;
          }
          *(longlong *)pPVar2 = lVar6;
          *(PCW_USER_REGISTRATION **)(lVar6 + 8) = pPVar2;
          lVar6 = *(longlong *)(pPVar5 + 0x10);
          *(undefined8 *)(pPVar5 + 0x10) = 0;
          ExFreePoolWithTag();
          if (*(char *)(lVar6 + 0x44) == '\0') {
            local_res8 = lVar6;
            DeliverNotification(this,&local_res8);
            break;
          }
          LOCK();
          piVar3 = (int *)(lVar6 + 0x4c);
          iVar4 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar4 == 1) {
            ExFreePoolWithTag(lVar6);
          }
        }
      }
      else {
        this[0x5e] = (PCW_USER_REGISTRATION)0x0;
        DeliverGenericDisconnectNotification(this);
      }
    }
    ExReleasePushLockExclusiveEx(pPVar1,0);
    KeLeaveCriticalRegion();
  }
  return lVar9;
}



===== CopyToNotificationBuffer @ 14000b858 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000b96c) */
/* private: long __cdecl PCW_NOTIFICATION::CopyToNotificationBuffer(struct PCW_REPLYITEM_BUFFER *
   __ptr64,void const * __ptr64) __ptr64 */

long __thiscall
PCW_NOTIFICATION::CopyToNotificationBuffer
          (PCW_NOTIFICATION *this,PCW_REPLYITEM_BUFFER *param_1,void *param_2)

{
  PCW_REPLYITEM_BUFFER *pPVar1;
  PCW_NOTIFICATION *pPVar2;
  PCW_NOTIFICATION *pPVar3;
  undefined4 *puVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined8 uVar12;
  uint uVar13;
  undefined1 auStack_e8 [32];
  ulonglong local_c8;
  undefined1 local_c0;
  undefined8 *local_b8;
  undefined4 local_a8;
  uint local_a4;
  PCW_NOTIFICATION *local_a0;
  void *local_98;
  PCW_REPLYITEM_BUFFER *local_90;
  PCW_NOTIFICATION *local_88;
  PCW_NOTIFICATION *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_e8;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_78 = 0;
  pPVar1 = param_1 + 4;
  if ((*(uint *)pPVar1 < 0xfffffff9) &&
     (uVar13 = (*(uint *)pPVar1 + 7 & 0xfffffff8) + 0x10, 0xf < uVar13)) {
    *(uint *)param_1 = uVar13;
    pPVar2 = this + 0x40;
    uVar13 = uVar13 + *(uint *)pPVar2;
    if (*(uint *)pPVar2 <= uVar13) {
      if (uVar13 <= *(uint *)(this + 0x3c)) {
        pPVar3 = this + 0x20;
        local_a4 = uVar13;
        local_a0 = this;
        local_98 = param_2;
        local_90 = pPVar1;
        local_88 = pPVar2;
        local_80 = pPVar3;
        KeStackAttachProcess(*(undefined8 *)pPVar3,&local_70);
        uVar8 = *(undefined4 *)(param_1 + 4);
        uVar9 = *(undefined4 *)(param_1 + 8);
        uVar10 = *(undefined4 *)(param_1 + 0xc);
        puVar4 = (undefined4 *)(*(longlong *)(this + 0x30) + (ulonglong)*(uint *)pPVar2);
        *puVar4 = *(undefined4 *)param_1;
        puVar4[1] = uVar8;
        puVar4[2] = uVar9;
        puVar4[3] = uVar10;
        local_a8 = 0;
        KeUnstackDetachProcess(&local_70);
        local_c8 = (ulonglong)*(uint *)pPVar1;
        if (*(uint *)pPVar1 != 0) {
          uVar5 = *(uint *)pPVar2;
          lVar6 = *(longlong *)(this + 0x30);
          uVar7 = *(undefined8 *)pPVar3;
          uVar12 = PsGetCurrentProcess();
          local_b8 = &local_78;
          local_c0 = 0;
          iVar11 = MmCopyVirtualMemory(uVar12,param_2,uVar7,lVar6 + (ulonglong)uVar5 + 0x10);
          if (iVar11 < 0) {
            return iVar11;
          }
        }
      }
      *(uint *)pPVar2 = uVar13;
      return 0;
    }
  }
  return -0x3fffff6b;
}



===== Create @ 14000b9fc =====

/* public: static long __cdecl PCW_NOTIFIER::Create(void * __ptr64 * __ptr64,struct _UNICODE_STRING
   const * __ptr64) */

long __cdecl PCW_NOTIFIER::Create(void **param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *this;
  PCW_COUNTERSET *local_res18;
  undefined8 local_res20;
  PCW_NOTIFIER *local_18 [2];
  
  local_res18 = (PCW_COUNTERSET *)0x0;
  local_res20 = 0;
  iVar1 = ZwAllocateLocallyUniqueId(&local_res20);
  if (-1 < iVar1) {
    this = (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)&local_res18;
    iVar1 = PCW_COUNTERSET::FindOrCreate(this,param_2,1);
    if (-1 < iVar1) {
      local_18[0] = (PCW_NOTIFIER *)0x0;
      this = (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)local_18;
      iVar1 = PcwpCreateObject((void **)this,0x28);
      if (-1 < iVar1) {
        this = (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)
               PCW_NOTIFIER(local_18[0],
                            (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)
                            &local_res18,(_LUID *)&local_res20);
        iVar1 = ObInsertObject(this,0,2,0,0,param_1);
      }
    }
    if (local_res18 != (PCW_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_COUNTERSET>::operator()((ReleaseDeleter<PCW_COUNTERSET> *)this,local_res18)
      ;
    }
  }
  return iVar1;
}



===== Create @ 14000bac0 =====

/* public: static long __cdecl PCW_USER_REGISTRATION::Create(void * __ptr64 * __ptr64,struct
   _UNICODE_STRING const * __ptr64,class utl::unique_ptr<void,struct GenericDeleter<void,__int64
   __cdecl(void * __ptr64),&__int64 __cdecl ObfDereferenceObject(void * __ptr64)> >,void * __ptr64
   const) */

long __cdecl
PCW_USER_REGISTRATION::Create
          (undefined8 *param_1,_UNICODE_STRING *param_2,longlong *param_3,undefined8 param_4)

{
  PCW_USER_REGISTRATION *pPVar1;
  long lVar2;
  ReleaseDeleter<PCW_COUNTERSET> *pRVar3;
  PCW_USER_REGISTRATION *this;
  longlong lVar4;
  unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *this_00;
  code *pcVar5;
  PCW_USER_REGISTRATION *pPVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  ReleaseDeleter<PCW_COUNTERSET> **local_58;
  undefined8 *local_50;
  PCW_COUNTERSET *local_48;
  PCW_USER_REGISTRATION *local_40;
  ReleaseDeleter<PCW_COUNTERSET> *local_38;
  undefined8 local_30;
  PCW_USER_REGISTRATION *local_28 [2];
  
  local_30 = 0;
  local_48 = (PCW_COUNTERSET *)0x0;
  this_00 = (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)&local_48;
  lVar2 = PCW_COUNTERSET::FindOrCreate(this_00,param_2,2);
  if (lVar2 < 0) {
    if (local_48 != (PCW_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_COUNTERSET>::operator()((ReleaseDeleter<PCW_COUNTERSET> *)this_00,local_48)
      ;
    }
    if (*param_3 != 0) {
      ObfDereferenceObject();
    }
  }
  else {
    pcVar5 = PacketCompletedCallback;
    pRVar3 = (ReleaseDeleter<PCW_COUNTERSET> *)
             IoAllocateMiniCompletionPacket(PacketCompletedCallback,0);
    local_38 = pRVar3;
    if (pRVar3 == (ReleaseDeleter<PCW_COUNTERSET> *)0x0) {
      if (local_48 != (PCW_COUNTERSET *)0x0) {
        ReleaseDeleter<PCW_COUNTERSET>::operator()
                  ((ReleaseDeleter<PCW_COUNTERSET> *)pcVar5,local_48);
      }
      if (*param_3 != 0) {
        ObfDereferenceObject();
      }
      lVar2 = -0x3fffffe9;
    }
    else {
      local_40 = (PCW_USER_REGISTRATION *)0x0;
      lVar2 = PcwpCreateObject(&local_40,0x60);
      if (lVar2 < 0) {
        IoFreeMiniCompletionPacket();
        if (local_48 != (PCW_COUNTERSET *)0x0) {
          ReleaseDeleter<PCW_COUNTERSET>::operator()(pRVar3,local_48);
        }
        if (*param_3 != 0) {
          ObfDereferenceObject();
        }
      }
      else {
        local_28[0] = (PCW_USER_REGISTRATION *)*param_3;
        *param_3 = 0;
        local_58 = &local_38;
        this = (PCW_USER_REGISTRATION *)PCW_USER_REGISTRATION(local_40,&local_48,local_28,param_4);
        pRVar3 = local_38;
        local_28[0] = this;
        if (local_38 != (ReleaseDeleter<PCW_COUNTERSET> *)0x0) {
          IoFreeMiniCompletionPacket();
        }
        if (local_48 != (PCW_COUNTERSET *)0x0) {
          ReleaseDeleter<PCW_COUNTERSET>::operator()(pRVar3,local_48);
        }
        puVar8 = auStack_78;
        KeEnterCriticalRegion();
        pPVar1 = this + 0x20;
        local_38 = (ReleaseDeleter<PCW_COUNTERSET> *)pPVar1;
        ExAcquirePushLockExclusiveEx(pPVar1,0);
        local_50 = &local_30;
        local_58 = (ReleaseDeleter<PCW_COUNTERSET> **)0x0;
        lVar2 = ObInsertObject(this,0,3);
        if (lVar2 < 0) {
          ExReleasePushLockExclusiveEx(pPVar1,0);
          KeLeaveCriticalRegion();
          Disconnect(this);
        }
        else {
          *param_1 = local_30;
          lVar4 = *(longlong *)(*(longlong *)(this + 0x18) + 0x50);
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(lVar4 + 0x50,0);
          pPVar6 = this + 8;
          lVar4 = *(longlong *)(this + 0x18) + 0x80;
          plVar7 = *(longlong **)(*(longlong *)(this + 0x18) + 0x88);
          puVar8 = auStack_78;
          if (*plVar7 != lVar4) {
            pPVar6 = (PCW_USER_REGISTRATION *)0x3;
            pcVar5 = (code *)swi(0x29);
            lVar4 = (*pcVar5)();
            puVar8 = auStack_70;
          }
          *(longlong *)pPVar6 = lVar4;
          *(longlong **)(pPVar6 + 8) = plVar7;
          *plVar7 = (longlong)pPVar6;
          *(PCW_USER_REGISTRATION **)(lVar4 + 8) = pPVar6;
          lVar4 = *(longlong *)(*(longlong *)(this + 0x18) + 0x50);
          *(undefined8 *)(puVar8 + -8) = 0x14000bd32;
          ExReleasePushLockExclusiveEx(lVar4 + 0x50,0);
          *(undefined8 *)(puVar8 + -8) = 0x14000bd3e;
          KeLeaveCriticalRegion();
          *(undefined8 *)(puVar8 + -8) = 0x14000bd4f;
          ExReleasePushLockExclusiveEx(pPVar1,0);
          *(undefined8 *)(puVar8 + -8) = 0x14000bd5b;
          KeLeaveCriticalRegion();
        }
        if (*param_3 != 0) {
          *(undefined8 *)(puVar8 + -8) = 0x14000bd6f;
          ObfDereferenceObject();
        }
      }
    }
  }
  return lVar2;
}



===== DeliverGenericDisconnectNotification @ 14000bd9c =====

/* private: void __cdecl PCW_USER_REGISTRATION::DeliverGenericDisconnectNotification(void) __ptr64
    */

void __thiscall
PCW_USER_REGISTRATION::DeliverGenericDisconnectNotification(PCW_USER_REGISTRATION *this)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  this[0x5c] = (PCW_USER_REGISTRATION)0x1;
  this[0x5f] = (PCW_USER_REGISTRATION)0x1;
  lVar3 = *(longlong *)(this + 0x50);
  *(undefined8 *)(this + 0x50) = 0;
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0x4c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      ExFreePoolWithTag(lVar3,0);
    }
  }
  IoSetIoCompletionEx(*(undefined8 *)(this + 0x28),*(undefined8 *)(this + 0x30),0,0,0xffffffff,0,
                      *(undefined8 *)(this + 0x38));
  return;
}



===== DeliverNotification @ 14000be18 =====

/* private: void __cdecl PCW_USER_REGISTRATION::DeliverNotification(class utl::unique_ptr<class
   PCW_NOTIFICATION,struct ReleaseDeleter<class PCW_NOTIFICATION> >) __ptr64 */

void __thiscall
PCW_USER_REGISTRATION::DeliverNotification(PCW_USER_REGISTRATION *this,longlong *param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  this[0x5c] = (PCW_USER_REGISTRATION)0x1;
  this[0x5f] = (PCW_USER_REGISTRATION)0x1;
  lVar3 = *param_2;
  *param_2 = 0;
  lVar4 = *(longlong *)(this + 0x50);
  *(longlong *)(this + 0x50) = lVar3;
  if (lVar4 != 0) {
    LOCK();
    piVar1 = (int *)(lVar4 + 0x4c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      ExFreePoolWithTag(lVar4,0);
    }
  }
  lVar3 = *(longlong *)(this + 0x50);
  IoSetIoCompletionEx(*(undefined8 *)(this + 0x28),*(undefined8 *)(this + 0x30),
                      (longlong)*(int *)(lVar3 + 0x14),*(undefined4 *)(lVar3 + 0x10),
                      *(undefined4 *)(lVar3 + 0x18),0,*(undefined8 *)(this + 0x38));
  lVar3 = *param_2;
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0x4c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      ExFreePoolWithTag(lVar3,0);
    }
  }
  return;
}



===== Disconnect @ 14000becc =====

/* public: bool __cdecl PCW_USER_REGISTRATION::Disconnect(void) __ptr64 */

bool __thiscall PCW_USER_REGISTRATION::Disconnect(PCW_USER_REGISTRATION *this)

{
  PCW_USER_REGISTRATION *pPVar1;
  PCW_NOTIFICATION *pPVar2;
  int iVar3;
  PCW_USER_REGISTRATION PVar4;
  PCW_USER_REGISTRATION PVar5;
  PCW_USER_REGISTRATION PVar6;
  PCW_USER_REGISTRATION *pPVar7;
  longlong lVar8;
  PCW_NOTIFICATION *this_00;
  code *pcVar9;
  undefined1 *puVar10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(this + 0x20);
  puVar10 = auStack_38;
  PVar4 = this[0x5d];
  pPVar1 = this + 0x40;
  *(undefined2 *)(this + 0x5d) = 1;
  do {
    pPVar7 = *(PCW_USER_REGISTRATION **)pPVar1;
    if (pPVar7 == pPVar1) {
LAB_14000bf81:
      lVar8 = *(longlong *)(this + 0x28);
      *(undefined8 *)(this + 0x28) = 0;
      PVar5 = this[0x5f];
      PVar6 = this[0x5c];
      *(undefined8 *)(puVar10 + -8) = 0x14000bf9e;
      ExReleasePushLockExclusiveEx(this + 0x20,0);
      *(undefined8 *)(puVar10 + -8) = 0x14000bfaa;
      KeLeaveCriticalRegion();
      if ((PVar6 == (PCW_USER_REGISTRATION)0x0) && (PVar4 == (PCW_USER_REGISTRATION)0x0)) {
        *(undefined8 *)(puVar10 + -8) = 0x14000bfc2;
        ObfDereferenceObject(this);
      }
      if (lVar8 != 0) {
        *(undefined8 *)(puVar10 + -8) = 0x14000bfd6;
        ObfDereferenceObject(lVar8);
      }
      return (bool)PVar5;
    }
    if ((*(PCW_USER_REGISTRATION **)(pPVar7 + 8) != pPVar1) ||
       (lVar8 = *(longlong *)pPVar7, *(PCW_USER_REGISTRATION **)(lVar8 + 8) != pPVar7)) {
      pcVar9 = (code *)swi(0x29);
      (*pcVar9)(3);
      puVar10 = auStack_30;
      goto LAB_14000bf81;
    }
    *(longlong *)pPVar1 = lVar8;
    *(PCW_USER_REGISTRATION **)(lVar8 + 8) = pPVar1;
    this_00 = *(PCW_NOTIFICATION **)(pPVar7 + 0x10);
    *(undefined8 *)(pPVar7 + 0x10) = 0;
    ExFreePoolWithTag();
    PCW_NOTIFICATION::Complete(this_00,(PCW_REPLYITEM_BUFFER *)0x0,(void *)0x0);
    if (this_00 != (PCW_NOTIFICATION *)0x0) {
      LOCK();
      pPVar2 = this_00 + 0x4c;
      iVar3 = *(int *)pPVar2;
      *(int *)pPVar2 = *(int *)pPVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        ExFreePoolWithTag(this_00);
      }
    }
  } while( true );
}



===== PacketCompletedCallback @ 14000c000 =====

/* private: static void __cdecl PCW_USER_REGISTRATION::PacketCompletedCallback(struct
   _IO_MINI_COMPLETION_PACKET_USER * __ptr64,void * __ptr64) */

void __cdecl
PCW_USER_REGISTRATION::PacketCompletedCallback
          (_IO_MINI_COMPLETION_PACKET_USER *param_1,void *param_2)

{
  char cVar1;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx((longlong)param_2 + 0x20,0);
  cVar1 = *(char *)((longlong)param_2 + 0x5d);
  *(undefined1 *)((longlong)param_2 + 0x5c) = 0;
  ExReleasePushLockExclusiveEx((longlong)param_2 + 0x20,0);
  KeLeaveCriticalRegion();
  if (cVar1 != '\0') {
    ObfDereferenceObject(param_2);
  }
  return;
}



===== PcwpSendStatelessNotification @ 14000c080 =====

/* long __cdecl PcwpSendStatelessNotification(struct _UNICODE_STRING const * __ptr64,unsigned
   long,union _LARGE_INTEGER * __ptr64,void * __ptr64,unsigned long,void * __ptr64,unsigned
   long,unsigned long * __ptr64) */

long __cdecl
PcwpSendStatelessNotification
          (_UNICODE_STRING *param_1,ulong param_2,_LARGE_INTEGER *param_3,void *param_4,
          ulong param_5,void *param_6,ulong param_7,ulong *param_8)

{
  long lVar1;
  unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *this;
  PCW_COUNTERSET *local_38;
  undefined4 local_30 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  PCW_COUNTERSET *local_10;
  
  local_38 = (PCW_COUNTERSET *)0x0;
  this = (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)&local_38;
  lVar1 = PCW_COUNTERSET::FindOrCreate(this,param_1,1);
  if (lVar1 < 0) {
    if (local_38 != (PCW_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_COUNTERSET>::operator()((ReleaseDeleter<PCW_COUNTERSET> *)this,local_38);
    }
  }
  else {
    local_30[0] = 2;
    local_18 = 0;
    local_10 = local_38;
    local_28 = 0;
    uStack_20 = 0;
    lVar1 = PCW_NOTIFIER::SendNotification
                      ((PCW_NOTIFIER *)local_30,param_2,param_3,param_4,param_5,param_6,param_7,
                       param_8);
    PCW_NOTIFIER::~PCW_NOTIFIER((PCW_NOTIFIER *)local_30);
  }
  return lVar1;
}



===== ReadInFlightNotificationBuffer @ 14000c158 =====

/* public: long __cdecl PCW_USER_REGISTRATION::ReadInFlightNotificationBuffer(void *
   __ptr64,unsigned long,unsigned long * __ptr64) __ptr64 */

long __thiscall
PCW_USER_REGISTRATION::ReadInFlightNotificationBuffer
          (PCW_USER_REGISTRATION *this,void *param_1,ulong param_2,ulong *param_3)

{
  PCW_USER_REGISTRATION *pPVar1;
  uint uVar2;
  undefined4 uVar3;
  longlong lVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 local_res8;
  
  lVar5 = 0;
  local_res8 = 0;
  KeEnterCriticalRegion();
  pPVar1 = this + 0x20;
  ExAcquirePushLockExclusiveEx(pPVar1,0);
  lVar4 = *(longlong *)(this + 0x50);
  if ((lVar4 == 0) || (this[0x5c] != (PCW_USER_REGISTRATION)0x0)) {
    ExReleasePushLockExclusiveEx(pPVar1,0);
    KeLeaveCriticalRegion();
    lVar5 = -0x3ffffe7c;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar4,0);
    if (*(char *)(lVar4 + 0x44) == '\0') {
      uVar2 = *(uint *)(lVar4 + 0x38);
      if (param_2 < uVar2) {
        *param_3 = uVar2;
        lVar5 = -0x7ffffffb;
      }
      else if (uVar2 == 0) {
        *param_3 = 0;
      }
      else {
        *param_3 = uVar2;
        uVar3 = *(undefined4 *)(lVar4 + 0x38);
        uVar6 = PsGetCurrentProcess();
        lVar5 = MmCopyVirtualMemory(*(undefined8 *)(lVar4 + 0x20),*(undefined8 *)(lVar4 + 0x28),
                                    uVar6,param_1,uVar3,0,&local_res8);
      }
    }
    else {
      lVar5 = -0x3ffffee0;
    }
    ExReleasePushLockExclusiveEx(lVar4,0);
    KeLeaveCriticalRegion();
    ExReleasePushLockExclusiveEx(pPVar1,0);
    KeLeaveCriticalRegion();
  }
  return lVar5;
}



===== SendDisconnectNotification @ 14000c2c0 =====

/* private: void __cdecl PCW_NOTIFIER::SendDisconnectNotification(void) __ptr64 */

void __thiscall PCW_NOTIFIER::SendDisconnectNotification(PCW_NOTIFIER *this)

{
  PCW_NOTIFICATION *pPVar1;
  int iVar2;
  long lVar3;
  PCW_NOTIFICATION *pPVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  
  pPVar4 = (PCW_NOTIFICATION *)ExAllocatePool2(0x101,0x50);
  if (pPVar4 == (PCW_NOTIFICATION *)0x0) {
    pPVar4 = (PCW_NOTIFICATION *)0x0;
  }
  else {
    pPVar4 = (PCW_NOTIFICATION *)
             PCW_NOTIFICATION::PCW_NOTIFICATION
                       (pPVar4,(_LUID *)(this + 0x18),0xffffffff,(_KEVENT *)0x0,(void *)0x0,0,
                        (void *)0x0,0);
  }
  lVar6 = *(longlong *)(*(longlong *)(this + 0x20) + 0x50);
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(lVar6 + 0x50,0);
  lVar6 = *(longlong *)(this + 0x20);
  puVar5 = (undefined8 *)(lVar6 + 0x80);
  puVar7 = (undefined8 *)*puVar5;
  do {
    if (puVar7 == puVar5) {
      ExReleasePushLockSharedEx(*(longlong *)(lVar6 + 0x50) + 0x50,0);
      KeLeaveCriticalRegion();
      if (pPVar4 != (PCW_NOTIFICATION *)0x0) {
        LOCK();
        pPVar1 = pPVar4 + 0x4c;
        iVar2 = *(int *)pPVar1;
        *(int *)pPVar1 = *(int *)pPVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          ExFreePoolWithTag(pPVar4,0);
        }
      }
      return;
    }
    if (pPVar4 == (PCW_NOTIFICATION *)0x0) {
LAB_14000c37b:
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(puVar7 + 3,0);
      if (*(char *)((longlong)puVar7 + 0x55) == '\0') {
        if (*(char *)((longlong)puVar7 + 0x57) == '\0') {
          PCW_USER_REGISTRATION::DeliverGenericDisconnectNotification
                    ((PCW_USER_REGISTRATION *)(puVar7 + -1));
        }
        else {
          *(undefined1 *)((longlong)puVar7 + 0x56) = 1;
        }
      }
      ExReleasePushLockExclusiveEx(puVar7 + 3);
      KeLeaveCriticalRegion();
    }
    else {
      lVar3 = PCW_USER_REGISTRATION::SendNotificationToRegistration
                        ((PCW_USER_REGISTRATION *)(puVar7 + -1),pPVar4);
      if (lVar3 == -0x3fffff66) goto LAB_14000c37b;
    }
    lVar6 = *(longlong *)(this + 0x20);
    puVar7 = (undefined8 *)*puVar7;
    puVar5 = (undefined8 *)(lVar6 + 0x80);
  } while( true );
}



===== SendNotification @ 14000c450 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl PCW_NOTIFIER::SendNotification(unsigned long,union _LARGE_INTEGER *
   __ptr64,void const * __ptr64,unsigned long,void * __ptr64,unsigned long,unsigned long * __ptr64)
   __ptr64 */

long __thiscall
PCW_NOTIFIER::SendNotification
          (PCW_NOTIFIER *this,ulong param_1,_LARGE_INTEGER *param_2,void *param_3,ulong param_4,
          void *param_5,ulong param_6,ulong *param_7)

{
  PCW_NOTIFICATION *pPVar1;
  int iVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  char cVar6;
  long lVar7;
  int iVar8;
  PCW_NOTIFICATION *pPVar9;
  undefined8 *puVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 *puVar13;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  KeInitializeEvent(&local_38,0,0);
  pPVar9 = (PCW_NOTIFICATION *)ExAllocatePool2(0x101,0x50,0x4e776350);
  if (pPVar9 == (PCW_NOTIFICATION *)0x0) {
    pPVar9 = (PCW_NOTIFICATION *)0x0;
  }
  else {
    pPVar9 = (PCW_NOTIFICATION *)
             PCW_NOTIFICATION::PCW_NOTIFICATION
                       (pPVar9,(_LUID *)(this + 0x18),param_1,(_KEVENT *)&local_38,param_3,param_4,
                        param_5,param_6);
  }
  if (pPVar9 == (PCW_NOTIFICATION *)0x0) {
    lVar7 = -0x3fffffe9;
  }
  else {
    *(undefined4 *)(pPVar9 + 0x40) = 8;
    iVar8 = 0;
    lVar11 = *(longlong *)(*(longlong *)(this + 0x20) + 0x50);
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(lVar11 + 0x50,0);
    lVar11 = *(longlong *)(this + 0x20);
    puVar10 = (undefined8 *)(lVar11 + 0x80);
    for (puVar13 = (undefined8 *)*puVar10; puVar13 != puVar10; puVar13 = (undefined8 *)*puVar13) {
      lVar7 = PCW_USER_REGISTRATION::SendNotificationToRegistration
                        ((PCW_USER_REGISTRATION *)(puVar13 + -1),pPVar9);
      iVar2 = iVar8 + 1;
      if (lVar7 < 0) {
        iVar2 = iVar8;
      }
      iVar8 = iVar2;
      lVar11 = *(longlong *)(this + 0x20);
      puVar10 = (undefined8 *)(lVar11 + 0x80);
    }
    ExReleasePushLockSharedEx(*(longlong *)(lVar11 + 0x50) + 0x50,0);
    KeLeaveCriticalRegion();
    LOCK();
    pPVar1 = pPVar9 + 0x1c;
    iVar2 = *(int *)pPVar1;
    *(int *)pPVar1 = *(int *)pPVar1 + iVar8;
    UNLOCK();
    if (iVar2 == -iVar8) {
LAB_14000c6d2:
      uVar3 = *(uint *)(pPVar9 + 0x40);
      local_48 = CONCAT44(uVar3,*(undefined4 *)(pPVar9 + 0x48));
      *param_7 = uVar3;
      if (param_6 < uVar3) {
        LOCK();
        pPVar1 = pPVar9 + 0x4c;
        iVar8 = *(int *)pPVar1;
        *(int *)pPVar1 = *(int *)pPVar1 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          ExFreePoolWithTag(pPVar9,0);
        }
        lVar7 = -0x7ffffffb;
      }
      else {
        *(undefined8 *)param_5 = local_48;
        LOCK();
        pPVar1 = pPVar9 + 0x4c;
        iVar8 = *(int *)pPVar1;
        *(int *)pPVar1 = *(int *)pPVar1 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          ExFreePoolWithTag(pPVar9,0);
        }
        lVar7 = 0;
      }
    }
    else {
      auVar4._8_8_ = 0;
      auVar4._0_8_ = _DAT_fffff78000000320 << 8;
      lVar11 = SUB168(auVar4 * (ZEXT416(_DAT_fffff78000000004) << 0x20),8);
      do {
        do {
          iVar8 = KeWaitForSingleObject(&local_38,6,0,1,param_2);
          if (iVar8 == 0) goto LAB_14000c6d2;
          if (iVar8 == 0x101) {
            cVar6 = PsIsThreadTerminating(SystemReserved1[0xf]);
            if (cVar6 != '\0') {
              lVar7 = -0x3ffffdc0;
              goto LAB_14000c664;
            }
          }
          else if (iVar8 == 0x102) goto LAB_14000c658;
        } while ((param_2 == (_LARGE_INTEGER *)0x0) || (-1 < *(longlong *)param_2));
        auVar5._8_8_ = 0;
        auVar5._0_8_ = _DAT_fffff78000000320 << 8;
        lVar12 = SUB168(auVar5 * (ZEXT416(_DAT_fffff78000000004) << 0x20),8);
        *(longlong *)param_2 = *(longlong *)param_2 + (lVar12 - lVar11) * 10000;
        lVar11 = lVar12;
      } while (*(longlong *)param_2 < 0);
LAB_14000c658:
      lVar7 = 0x102;
LAB_14000c664:
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(pPVar9,0);
      pPVar9[0x44] = (PCW_NOTIFICATION)0x1;
      ExReleasePushLockExclusiveEx(pPVar9,0);
      KeLeaveCriticalRegion();
      *param_7 = 0;
      LOCK();
      pPVar1 = pPVar9 + 0x4c;
      iVar8 = *(int *)pPVar1;
      *(int *)pPVar1 = *(int *)pPVar1 + -1;
      UNLOCK();
      if (iVar8 == 1) {
        ExFreePoolWithTag(pPVar9,0);
      }
    }
  }
  return lVar7;
}



===== SendNotificationToRegistration @ 14000c790 =====

/* public: long __cdecl PCW_USER_REGISTRATION::SendNotificationToRegistration(class PCW_NOTIFICATION
   * __ptr64) __ptr64 */

long __thiscall
PCW_USER_REGISTRATION::SendNotificationToRegistration
          (PCW_USER_REGISTRATION *this,PCW_NOTIFICATION *param_1)

{
  PCW_NOTIFICATION *pPVar1;
  int iVar2;
  code *pcVar3;
  longlong *plVar4;
  PCW_USER_REGISTRATION *pPVar5;
  PCW_NOTIFICATION *pPVar6;
  longlong *plVar7;
  long lVar8;
  undefined1 *puVar9;
  bool bVar10;
  PCW_NOTIFICATION *local_res8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  lVar8 = 0;
  bVar10 = false;
  local_res8 = (PCW_NOTIFICATION *)((ulonglong)local_res8 & 0xffffffff00000000);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(this + 0x20,0);
  if (this[0x5d] == (PCW_USER_REGISTRATION)0x0) {
    if (this[0x5f] == (PCW_USER_REGISTRATION)0x0) {
      if (param_1 != (PCW_NOTIFICATION *)0x0) {
        LOCK();
        *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
        UNLOCK();
      }
      local_res8 = param_1;
      DeliverNotification(this,&local_res8);
      puVar9 = auStack_38;
    }
    else {
      plVar4 = (longlong *)ExAllocatePool2(0x100,0x18,0x4e776350);
      if (plVar4 == (longlong *)0x0) {
        plVar4 = (longlong *)0x0;
        pPVar6 = local_res8;
      }
      else {
        if (param_1 != (PCW_NOTIFICATION *)0x0) {
          LOCK();
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          UNLOCK();
        }
        *plVar4 = 0;
        plVar4[1] = 0;
        plVar4[2] = (longlong)param_1;
        bVar10 = true;
        pPVar6 = (PCW_NOTIFICATION *)0x0;
      }
      if ((bVar10) && (pPVar6 != (PCW_NOTIFICATION *)0x0)) {
        LOCK();
        pPVar1 = pPVar6 + 0x4c;
        iVar2 = *(int *)pPVar1;
        *(int *)pPVar1 = *(int *)pPVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          ExFreePoolWithTag(pPVar6,0);
        }
      }
      puVar9 = auStack_38;
      if (plVar4 == (longlong *)0x0) {
        lVar8 = -0x3fffff66;
        puVar9 = auStack_38;
      }
      else {
        pPVar5 = this + 0x40;
        plVar7 = *(longlong **)(this + 0x48);
        if ((PCW_USER_REGISTRATION *)*plVar7 != pPVar5) {
          plVar7 = (longlong *)0x3;
          pcVar3 = (code *)swi(0x29);
          pPVar5 = (PCW_USER_REGISTRATION *)(*pcVar3)();
          puVar9 = auStack_30;
        }
        *plVar4 = (longlong)pPVar5;
        plVar4[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar4;
        *(longlong **)(pPVar5 + 8) = plVar4;
      }
    }
  }
  else {
    lVar8 = -0x3ffffe7c;
    puVar9 = auStack_38;
  }
  *(undefined8 *)(puVar9 + -8) = 0x14000c8b4;
  ExReleasePushLockExclusiveEx(this + 0x20,0);
  *(undefined8 *)(puVar9 + -8) = 0x14000c8c0;
  KeLeaveCriticalRegion();
  return lVar8;
}



===== PcwpCloseObjectHandle @ 14000c8f0 =====

/* void __cdecl PcwpCloseObjectHandle(struct _EPROCESS * __ptr64,void * __ptr64,unsigned
   __int64,unsigned __int64) */

void __cdecl
PcwpCloseObjectHandle(_EPROCESS *param_1,void *param_2,__uint64 param_3,__uint64 param_4)

{
  if ((param_4 == 1) && (*(int *)param_2 == 1)) {
    PCW_USER_REGISTRATION::Disconnect(param_2);
  }
  return;
}



===== PcwpCreateObject @ 14000c914 =====

/* long __cdecl PcwpCreateObject(void * __ptr64 * __ptr64,unsigned long) */

long __cdecl PcwpCreateObject(void **param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = ObCreateObject(0,PcwObjectType,0,1,0,param_2,param_2,0,param_1);
  return lVar1;
}



===== PcwpDeleteObject @ 14000c960 =====

/* void __cdecl PcwpDeleteObject(void * __ptr64) */

void __cdecl PcwpDeleteObject(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)param_1;
  if (iVar1 == 0) {
    PCW_QUERY::~PCW_QUERY(param_1);
  }
  else if (iVar1 == 1) {
    PCW_USER_REGISTRATION::~PCW_USER_REGISTRATION(param_1);
  }
  else if (iVar1 == 2) {
    PCW_NOTIFIER::~PCW_NOTIFIER(param_1);
  }
  return;
}



===== PcwpOpenObject @ 14000c9a0 =====

/* long __cdecl PcwpOpenObject(enum _OB_OPEN_REASON,char,struct _EPROCESS * __ptr64,void *
   __ptr64,unsigned long * __ptr64,unsigned long) */

long __cdecl
PcwpOpenObject(_OB_OPEN_REASON param_1,char param_2,_EPROCESS *param_3,void *param_4,ulong *param_5,
              ulong param_6)

{
  return -(uint)(param_1 != 0) & 0xc00000bb;
}



===== PCW_COUNTERSET @ 14000c9b4 =====

/* private: __cdecl PCW_COUNTERSET::PCW_COUNTERSET(class utl::unique_ptr<class
   PCW_SILO_NEUTRAL_COUNTERSET,struct ReleaseDeleter<class PCW_SILO_NEUTRAL_COUNTERSET> > &&
   __ptr64,class PCW_SILO_CONTEXT * __ptr64) __ptr64 */

PCW_COUNTERSET * __thiscall
PCW_COUNTERSET::PCW_COUNTERSET
          (PCW_COUNTERSET *this,
          unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
          *param_1,PCW_SILO_CONTEXT *param_2)

{
  PCW_COUNTERSET *pPVar1;
  PCW_COUNTERSET *pPVar2;
  PCW_COUNTERSET *pPVar3;
  PCW_COUNTERSET *pPVar4;
  undefined2 uVar5;
  undefined8 uVar6;
  
  uVar5 = *(undefined2 *)(*(longlong *)param_1 + 0x18);
  pPVar1 = this + 0x58;
  uVar6 = *(undefined8 *)(*(longlong *)param_1 + 0x20);
  pPVar2 = this + 0x70;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  pPVar4 = this + 0x80;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x18) = uVar5;
  *(undefined2 *)(this + 0x1a) = uVar5;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined8 *)(this + 0x20) = uVar6;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  pPVar3 = this + 0x28;
  *(undefined8 *)(this + 0x48) = 0;
  *(PCW_COUNTERSET **)(this + 0x30) = pPVar3;
  *(PCW_COUNTERSET **)pPVar3 = pPVar3;
  pPVar3 = this + 0x40;
  *(PCW_COUNTERSET **)(this + 0x48) = pPVar3;
  *(PCW_COUNTERSET **)pPVar3 = pPVar3;
  uVar6 = *(undefined8 *)param_1;
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(this + 0x50) = uVar6;
  *(undefined8 *)pPVar1 = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)pPVar2 = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)pPVar4 = 0;
  *(undefined8 *)(this + 0x88) = 0;
  if (param_2 != (PCW_SILO_CONTEXT *)0x0) {
    PsReferenceSiloContext(param_2);
  }
  *(PCW_SILO_CONTEXT **)(this + 0x90) = param_2;
  *(undefined4 *)(this + 0x98) = 1;
  *(PCW_COUNTERSET **)(this + 0x60) = pPVar1;
  *(PCW_COUNTERSET **)pPVar1 = pPVar1;
  *(PCW_COUNTERSET **)(this + 0x78) = pPVar2;
  *(PCW_COUNTERSET **)pPVar2 = pPVar2;
  *(PCW_COUNTERSET **)(this + 0x88) = pPVar4;
  *(PCW_COUNTERSET **)pPVar4 = pPVar4;
  return this;
}



===== _PCW_REGISTRATION @ 14000caa8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: __cdecl _PCW_REGISTRATION::_PCW_REGISTRATION(class utl::unique_ptr<class
   PCW_COUNTERSET,struct ReleaseDeleter<class PCW_COUNTERSET> > && __ptr64,class
   utl::unique_ptr<class PCW_SILO_NEUTRAL_COUNTERSET,struct ReleaseDeleter<class
   PCW_SILO_NEUTRAL_COUNTERSET> > && __ptr64,unsigned long,struct _PCW_COUNTER_DESCRIPTOR const *
   __ptr64,unsigned __int64,unsigned long,long (__cdecl*)(enum _PCW_CALLBACK_TYPE,union
   _PCW_CALLBACK_INFORMATION * __ptr64,void * __ptr64),void * __ptr64) __ptr64 */

_PCW_REGISTRATION * __thiscall
_PCW_REGISTRATION::_PCW_REGISTRATION
          (_PCW_REGISTRATION *this,
          unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *param_1,
          unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
          *param_2,ulong param_3,_PCW_COUNTER_DESCRIPTOR *param_4,__uint64 param_5,ulong param_6,
          _func_long__PCW_CALLBACK_TYPE__PCW_CALLBACK_INFORMATION_ptr_void_ptr *param_7,
          void *param_8)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [72];
  
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(__uint64 *)(this + 0x10) = param_5;
  *(ulong *)(this + 0x1c) = param_6;
  *(ulong *)(this + 0x18) = param_3;
  uVar1 = *(undefined8 *)param_1;
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(this + 0x20) = uVar1;
  lVar2 = *(longlong *)param_2;
  *(undefined8 *)param_2 = 0;
  *(longlong *)(this + 0x28) = lVar2;
  lVar9 = *(longlong *)(this + 0x20);
  *(_func_long__PCW_CALLBACK_TYPE__PCW_CALLBACK_INFORMATION_ptr_void_ptr **)(this + 0x30) = param_7;
  *(void **)(this + 0x38) = param_8;
  *(_PCW_COUNTER_DESCRIPTOR **)(this + 0x40) = param_4;
  if (lVar9 == 0) {
    lVar8 = lVar2;
  }
  else {
    lVar8 = *(longlong *)(lVar9 + 0x50);
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar8 + 0x50,0);
  puVar7 = auStack_58;
  if (lVar9 == 0) {
    lVar9 = lVar2;
  }
  plVar5 = *(longlong **)(lVar9 + 0x30);
  if (*plVar5 != lVar9 + 0x28) {
    pcVar4 = (code *)swi(0x29);
    plVar5 = (longlong *)(*pcVar4)(3);
    puVar7 = auStack_50;
  }
  *(longlong *)this = lVar9 + 0x28;
  *(longlong **)(this + 8) = plVar5;
  *plVar5 = (longlong)this;
  *(_PCW_REGISTRATION **)(lVar9 + 0x30) = this;
  if (*(longlong *)(this + 0x30) != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x14000cb8c;
    KeEnterCriticalRegion();
    *(undefined8 *)(puVar7 + -8) = 0x14000cba1;
    ExAcquirePushLockSharedEx(lVar8 + 0x68,0);
    if (*(longlong *)(this + 0x20) == 0) {
      for (puVar10 = *(undefined8 **)(lVar8 + 0x70); puVar10 != (undefined8 *)(lVar8 + 0x70);
          puVar10 = (undefined8 *)*puVar10) {
        uVar1 = puVar10[4];
        *(undefined8 *)(puVar7 + 0x40) = 0;
        uVar3 = *(undefined8 *)(this + 0x38);
        *(undefined8 *)(puVar7 + 0x20) = uVar1;
        *(undefined8 **)(puVar7 + 0x28) = puVar10 + 9;
        pcVar4 = *(code **)(this + 0x30);
        *(undefined8 *)(puVar7 + 0x30) = 0;
        *(undefined8 *)(puVar7 + 0x38) = 0;
        *(undefined8 *)(puVar7 + -8) = 0x14000cc3d;
        (*pcVar4)(0,puVar7 + 0x20,uVar3);
      }
    }
    else {
      puVar6 = (undefined8 *)(*(longlong *)(this + 0x20) + 0x58);
      for (puVar10 = (undefined8 *)*puVar6; puVar10 != puVar6; puVar10 = (undefined8 *)*puVar10) {
        uVar1 = puVar10[2];
        uVar3 = *(undefined8 *)(this + 0x38);
        *(undefined8 *)(puVar7 + 0x40) = 0;
        *(undefined8 *)(puVar7 + 0x20) = uVar1;
        *(undefined8 **)(puVar7 + 0x28) = puVar10 + 7;
        pcVar4 = *(code **)(this + 0x30);
        *(undefined8 *)(puVar7 + 0x30) = 0;
        *(undefined8 *)(puVar7 + 0x38) = 0;
        *(undefined8 *)(puVar7 + -8) = 0x14000cbed;
        (*pcVar4)(0,puVar7 + 0x20,uVar3);
        puVar6 = (undefined8 *)(*(longlong *)(this + 0x20) + 0x58);
      }
    }
    *(undefined8 *)(puVar7 + -8) = 0x14000cc51;
    ExReleasePushLockSharedEx(lVar8 + 0x68,0);
    *(undefined8 *)(puVar7 + -8) = 0x14000cc5d;
    KeLeaveCriticalRegion();
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000cc6e;
  ExReleasePushLockExclusiveEx(lVar8 + 0x50,0);
  *(undefined8 *)(puVar7 + -8) = 0x14000cc7a;
  KeLeaveCriticalRegion();
  return this;
}



===== ~PCW_COUNTERSET @ 14000cca4 =====

/* private: __cdecl PCW_COUNTERSET::~PCW_COUNTERSET(void) __ptr64 */

void __thiscall PCW_COUNTERSET::~PCW_COUNTERSET(PCW_COUNTERSET *this)

{
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *this_00;
  
  this_00 = *(ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> **)(this + 0x90);
  if (this_00 != (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)0x0) {
    PsDereferenceSiloContext();
  }
  if (*(PCW_SILO_NEUTRAL_COUNTERSET **)(this + 0x50) != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
    ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
              (this_00,*(PCW_SILO_NEUTRAL_COUNTERSET **)(this + 0x50));
  }
  return;
}



===== ~_PCW_INSTANCE @ 14000cce0 =====

/* private: __cdecl _PCW_INSTANCE::~_PCW_INSTANCE(void) __ptr64 */

void __thiscall _PCW_INSTANCE::~_PCW_INSTANCE(_PCW_INSTANCE *this)

{
  _PCW_INSTANCE *this_00;
  
  this_00 = this;
  if (*(PCW_SILO_NEUTRAL_COUNTERSET **)(this + 0x28) != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
    ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
              ((ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)this,
               *(PCW_SILO_NEUTRAL_COUNTERSET **)(this + 0x28));
  }
  if (*(PCW_COUNTERSET **)(this + 0x20) != (PCW_COUNTERSET *)0x0) {
    ReleaseDeleter<PCW_COUNTERSET>::operator()
              ((ReleaseDeleter<PCW_COUNTERSET> *)this_00,*(PCW_COUNTERSET **)(this + 0x20));
  }
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)(this + 0x10));
  return;
}



===== ~_PCW_REGISTRATION @ 14000cd1c =====

/* public: __cdecl _PCW_REGISTRATION::~_PCW_REGISTRATION(void) __ptr64 */

void __thiscall _PCW_REGISTRATION::~_PCW_REGISTRATION(_PCW_REGISTRATION *this)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 *puVar4;
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *this_00;
  _PCW_INSTANCE *this_01;
  PCW_COUNTERSET_BASE *pPVar5;
  PCW_COUNTERSET_BASE *pPVar6;
  _PCW_INSTANCE *local_res8;
  _PCW_INSTANCE *local_res10;
  
  pPVar6 = *(PCW_COUNTERSET_BASE **)(this + 0x20);
  if (pPVar6 == (PCW_COUNTERSET_BASE *)0x0) {
    pPVar5 = *(PCW_COUNTERSET_BASE **)(this + 0x28);
    pPVar6 = pPVar5;
  }
  else {
    pPVar5 = *(PCW_COUNTERSET_BASE **)(pPVar6 + 0x50);
  }
  local_res8 = (_PCW_INSTANCE *)0x0;
  PCW_COUNTERSET_BASE::NextInstance(pPVar6,&local_res10,&local_res8);
  this_01 = local_res10;
  while (this_01 != (_PCW_INSTANCE *)0x0) {
    if (this == *(_PCW_REGISTRATION **)(this_01 + 0x38)) {
      _PCW_INSTANCE::Close(this_01);
    }
    local_res8 = this_01;
    puVar4 = (undefined8 *)PCW_COUNTERSET_BASE::NextInstance(pPVar6,&local_res10,&local_res8);
    this_01 = (_PCW_INSTANCE *)*puVar4;
    *puVar4 = 0;
    if (local_res10 != (_PCW_INSTANCE *)0x0) {
      _PCW_INSTANCE::Release(local_res10);
    }
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pPVar5 + 0x50,0);
  lVar1 = *(longlong *)this;
  if ((*(_PCW_REGISTRATION **)(lVar1 + 8) != this) ||
     (plVar2 = *(longlong **)(this + 8), (_PCW_REGISTRATION *)*plVar2 != this)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar2 = lVar1;
  this_00 = (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)(pPVar5 + 0x50);
  *(longlong **)(lVar1 + 8) = plVar2;
  ExReleasePushLockExclusiveEx(this_00,0);
  KeLeaveCriticalRegion();
  if (*(PCW_SILO_NEUTRAL_COUNTERSET **)(this + 0x28) != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
    ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
              (this_00,*(PCW_SILO_NEUTRAL_COUNTERSET **)(this + 0x28));
  }
  if (*(PCW_COUNTERSET **)(this + 0x20) != (PCW_COUNTERSET *)0x0) {
    ReleaseDeleter<PCW_COUNTERSET>::operator()
              ((ReleaseDeleter<PCW_COUNTERSET> *)this_00,*(PCW_COUNTERSET **)(this + 0x20));
  }
  return;
}



===== operator() @ 14000ce2c =====

/* public: void __cdecl ReleaseDeleter<class PCW_SILO_NEUTRAL_COUNTERSET>::operator()(class
   PCW_SILO_NEUTRAL_COUNTERSET * __ptr64)const __ptr64 */

void __thiscall
ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
          (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *this,PCW_SILO_NEUTRAL_COUNTERSET *param_1)

{
  PCW_SILO_NEUTRAL_COUNTERSET *pPVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = *(uint *)(param_1 + 0x84);
  while (1 < (int)uVar4) {
    this = (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)(ulonglong)(uVar4 - 1);
    LOCK();
    uVar2 = *(uint *)(param_1 + 0x84);
    bVar5 = uVar4 == uVar2;
    if (bVar5) {
      *(uint *)(param_1 + 0x84) = uVar4 - 1;
    }
    else {
      uVar4 = uVar2;
    }
    UNLOCK();
    if (bVar5) {
      return;
    }
  }
  KeEnterCriticalRegion(this);
  ExAcquirePushLockExclusiveEx(&DAT_140011468,0);
  LOCK();
  pPVar1 = param_1 + 0x84;
  iVar3 = *(int *)pPVar1;
  *(int *)pPVar1 = *(int *)pPVar1 + -1;
  UNLOCK();
  if (iVar3 != 1) {
    ExReleasePushLockExclusiveEx(&DAT_140011468,0);
    KeLeaveCriticalRegion();
    return;
  }
  RtlRbRemoveNode(&DAT_140011470,param_1);
  ExReleasePushLockExclusiveEx(&DAT_140011468,0);
  KeLeaveCriticalRegion();
  if (param_1 == (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
    return;
  }
  PCW_SILO_NEUTRAL_COUNTERSET::~PCW_SILO_NEUTRAL_COUNTERSET(param_1);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== Close @ 14000cf0c =====

/* public: void __cdecl _PCW_INSTANCE::Close(void) __ptr64 */

void __thiscall _PCW_INSTANCE::Close(_PCW_INSTANCE *this)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(this + 0x30,0);
  *(undefined8 *)(this + 0x38) = 0;
  ExReleasePushLockExclusiveEx(this + 0x30,0);
  KeLeaveCriticalRegion();
  Release(this);
  return;
}



===== Create @ 14000cf74 =====

/* public: static long __cdecl _PCW_INSTANCE::Create(struct _PCW_INSTANCE * __ptr64 * __ptr64,struct
   _PCW_REGISTRATION const * __ptr64,struct _UNICODE_STRING const * __ptr64,unsigned long,struct
   _PCW_DATA const * __ptr64) */

long __cdecl
_PCW_INSTANCE::Create
          (_PCW_INSTANCE **param_1,_PCW_REGISTRATION *param_2,_UNICODE_STRING *param_3,ulong param_4
          ,_PCW_DATA *param_5)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  code *pcVar5;
  long lVar6;
  _PCW_INSTANCE *p_Var7;
  longlong *plVar8;
  _PCW_INSTANCE *p_Var9;
  longlong lVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  uint uVar13;
  ulonglong uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar11 = (ulonglong)param_4;
  if (*(ulong *)(param_2 + 0x1c) != param_4) {
    return -0x3fffff0e;
  }
  uVar14 = 0;
  if (*(uint *)(param_2 + 0x18) != 0) {
    lVar10 = *(longlong *)(param_2 + 0x40);
    do {
      if (*(uint *)(param_5 + (ulonglong)*(ushort *)(lVar10 + 2 + uVar14 * 8) * 0x10 + 8) <
          (uint)*(ushort *)(lVar10 + 6 + uVar14 * 8) + (uint)*(ushort *)(lVar10 + 4 + uVar14 * 8)) {
        return -0x3ffffdfa;
      }
      uVar13 = (int)uVar14 + 1;
      uVar14 = (ulonglong)uVar13;
    } while (uVar13 < *(uint *)(param_2 + 0x18));
  }
  if (0x1ffffff5 < param_4) {
    return -0x3fffff6b;
  }
  local_48 = 0;
  uStack_40 = 0;
  uVar15 = 0;
  uVar16 = 0;
  uVar17 = 0;
  uVar18 = 0;
  if ((param_3 != (_UNICODE_STRING *)0x0) && (*(ushort *)param_3 != 0)) {
    lVar6 = AllocatedUnicodeString::Capture
                      ((AllocatedUnicodeString *)&local_48,*(ushort **)(param_3 + 8),
                       *(ushort *)param_3,0);
    if (lVar6 < 0) goto LAB_14000d069;
    uVar15 = (undefined4)local_48;
    uVar16 = local_48._4_4_;
    uVar17 = (undefined4)uStack_40;
    uVar18 = uStack_40._4_4_;
  }
  p_Var7 = (_PCW_INSTANCE *)ExAllocatePool2(0x100,param_4 * 8 + 0x50,0x49776350);
  if (p_Var7 != (_PCW_INSTANCE *)0x0) {
    if (param_4 != 0) {
      p_Var9 = p_Var7 + 0x50;
      do {
        uVar3 = *(undefined8 *)param_5;
        param_5 = param_5 + 0x10;
        *(undefined8 *)p_Var9 = uVar3;
        p_Var9 = p_Var9 + 8;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
    lVar10 = *(longlong *)(param_2 + 0x20);
    local_38 = 0;
    uStack_30 = 0;
    local_48 = 0;
    uStack_40 = 0;
    *(undefined8 *)p_Var7 = 0;
    *(undefined8 *)(p_Var7 + 8) = 0;
    *(undefined4 *)(p_Var7 + 0x10) = uVar15;
    *(undefined4 *)(p_Var7 + 0x14) = uVar16;
    *(undefined4 *)(p_Var7 + 0x18) = uVar17;
    *(undefined4 *)(p_Var7 + 0x1c) = uVar18;
    if (lVar10 != 0) {
      LOCK();
      *(int *)(lVar10 + 0x98) = *(int *)(lVar10 + 0x98) + 1;
      UNLOCK();
    }
    *(longlong *)(p_Var7 + 0x20) = lVar10;
    lVar10 = *(longlong *)(param_2 + 0x28);
    if (lVar10 != 0) {
      LOCK();
      *(int *)(lVar10 + 0x84) = *(int *)(lVar10 + 0x84) + 1;
      UNLOCK();
    }
    lVar4 = *(longlong *)(param_2 + 0x20);
    *(longlong *)(p_Var7 + 0x28) = lVar10;
    *(undefined8 *)(p_Var7 + 0x30) = 0;
    *(_PCW_REGISTRATION **)(p_Var7 + 0x38) = param_2;
    *(_PCW_INSTANCE **)(p_Var7 + 0x40) = p_Var7 + 0x50;
    if (lVar4 == 0) {
      lVar10 = *(longlong *)(param_2 + 0x28);
    }
    else {
      lVar10 = *(longlong *)(lVar4 + 0x50);
    }
    LOCK();
    piVar1 = (int *)(lVar10 + 0x80);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    lVar10 = *(longlong *)(p_Var7 + 0x20);
    *(int *)(p_Var7 + 0x48) = iVar2 + 1;
    *(undefined4 *)(p_Var7 + 0x4c) = 1;
    if (lVar10 == 0) {
      lVar10 = *(longlong *)(p_Var7 + 0x28);
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar10 + 0x38,0);
    puVar12 = auStack_68;
    plVar8 = *(longlong **)(lVar10 + 0x48);
    if (*plVar8 != lVar10 + 0x40) {
      pcVar5 = (code *)swi(0x29);
      plVar8 = (longlong *)(*pcVar5)(3);
      puVar12 = auStack_60;
    }
    *(longlong *)p_Var7 = lVar10 + 0x40;
    *(longlong **)(p_Var7 + 8) = plVar8;
    *plVar8 = (longlong)p_Var7;
    *(_PCW_INSTANCE **)(lVar10 + 0x48) = p_Var7;
    *(undefined8 *)(puVar12 + -8) = 0x14000d170;
    ExReleasePushLockExclusiveEx(lVar10 + 0x38,0);
    *(undefined8 *)(puVar12 + -8) = 0x14000d17c;
    KeLeaveCriticalRegion();
    *param_1 = p_Var7;
    *(undefined8 *)(puVar12 + -8) = 0x14000d18e;
    AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)(puVar12 + 0x20));
    return 0;
  }
  lVar6 = -0x3fffffe9;
LAB_14000d069:
  AllocatedUnicodeString::~AllocatedUnicodeString((AllocatedUnicodeString *)&local_48);
  return lVar6;
}



===== Create @ 14000d1b8 =====

/* public: static long __cdecl _PCW_REGISTRATION::Create(struct _PCW_REGISTRATION * __ptr64 *
   __ptr64,struct _UNICODE_STRING const * __ptr64,unsigned long,struct _PCW_COUNTER_DESCRIPTOR *
   __ptr64,long (__cdecl*)(enum _PCW_CALLBACK_TYPE,union _PCW_CALLBACK_INFORMATION * __ptr64,void *
   __ptr64),void * __ptr64,enum PCW_REGISTRATION_FLAGS) */

long __cdecl
_PCW_REGISTRATION::Create
          (_PCW_REGISTRATION **param_1,_UNICODE_STRING *param_2,ulong param_3,
          _PCW_COUNTER_DESCRIPTOR *param_4,
          _func_long__PCW_CALLBACK_TYPE__PCW_CALLBACK_INFORMATION_ptr_void_ptr *param_5,
          void *param_6,PCW_REGISTRATION_FLAGS param_7)

{
  _PCW_COUNTER_DESCRIPTOR *p_Var1;
  uint uVar2;
  int iVar3;
  _PCW_REGISTRATION *this;
  _PCW_REGISTRATION *p_Var4;
  unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_> *this_00;
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *this_01;
  ulong uVar5;
  PCW_SILO_NEUTRAL_COUNTERSET *pPVar6;
  PCW_COUNTERSET *pPVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  PCW_COUNTERSET *local_38;
  PCW_SILO_NEUTRAL_COUNTERSET *local_30;
  
  uVar9 = (ulonglong)param_3;
  if (param_3 < 0x1ffffff7) {
    pPVar6 = (PCW_SILO_NEUTRAL_COUNTERSET *)0x0;
    local_30 = (PCW_SILO_NEUTRAL_COUNTERSET *)0x0;
    local_38 = (PCW_COUNTERSET *)0x0;
    if ((param_7 & 1) == 0) {
      this_00 = (unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
                 *)&local_38;
      iVar3 = PCW_COUNTERSET::FindOrCreate
                        ((unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)this_00,
                         param_2);
      pPVar7 = local_38;
    }
    else {
      this_00 = (unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
                 *)&local_30;
      iVar3 = PCW_SILO_NEUTRAL_COUNTERSET::FindOrCreate(this_00,param_2);
      pPVar6 = local_30;
      pPVar7 = (PCW_COUNTERSET *)0x0;
    }
    if (iVar3 < 0) {
      if (pPVar7 != (PCW_COUNTERSET *)0x0) {
        ReleaseDeleter<PCW_COUNTERSET>::operator()((ReleaseDeleter<PCW_COUNTERSET> *)this_00,pPVar7)
        ;
      }
      if (pPVar6 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
        ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
                  ((ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)this_00,pPVar6);
      }
    }
    else {
      this_01 = (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)0x100;
      this = (_PCW_REGISTRATION *)ExAllocatePool2(0x100,param_3 * 8 + 0x48,0x52776350);
      if (this == (_PCW_REGISTRATION *)0x0) {
        if (pPVar7 != (PCW_COUNTERSET *)0x0) {
          ReleaseDeleter<PCW_COUNTERSET>::operator()
                    ((ReleaseDeleter<PCW_COUNTERSET> *)this_01,pPVar7);
        }
        if (pPVar6 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
          ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()(this_01,pPVar6);
        }
        iVar3 = -0x3fffffe9;
      }
      else {
        uVar8 = 0;
        uVar5 = 0;
        if (param_3 != 0) {
          memmove((_PCW_COUNTER_DESCRIPTOR *)(this + 0x48),param_4,uVar9 << 3);
          do {
            uVar8 = uVar8 | 1L << ((ulonglong)*(ushort *)param_4 & 0x3f);
            p_Var1 = param_4 + 2;
            param_4 = param_4 + 8;
            uVar2 = *(ushort *)p_Var1 + 1;
            if (*(ushort *)p_Var1 < uVar5) {
              uVar2 = uVar5;
            }
            uVar5 = uVar2;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        p_Var4 = (_PCW_REGISTRATION *)
                 _PCW_REGISTRATION(this,(unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_>
                                         *)&local_38,
                                   (unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
                                    *)&local_30,param_3,(_PCW_COUNTER_DESCRIPTOR *)(this + 0x48),
                                   uVar8,uVar5,param_5,param_6);
        *param_1 = p_Var4;
        if (local_38 != (PCW_COUNTERSET *)0x0) {
          ReleaseDeleter<PCW_COUNTERSET>::operator()
                    ((ReleaseDeleter<PCW_COUNTERSET> *)this,local_38);
        }
        if (local_30 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
          ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
                    ((ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)this,local_30);
        }
        iVar3 = 0;
      }
    }
  }
  else {
    iVar3 = -0x3fffff6b;
  }
  return iVar3;
}



===== FindOrCreate @ 14000d364 =====

/* public: static long __cdecl PCW_COUNTERSET::FindOrCreate(class utl::unique_ptr<class
   PCW_COUNTERSET,struct ReleaseDeleter<class PCW_COUNTERSET> > * __ptr64,struct _UNICODE_STRING
   const * __ptr64) */

long __cdecl
PCW_COUNTERSET::FindOrCreate
          (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *param_1,
          _UNICODE_STRING *param_2)

{
  _RTL_RB_TREE *p_Var1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  PCW_COUNTERSET_BASE *pPVar5;
  PCW_COUNTERSET *pPVar6;
  PCW_COUNTERSET_BASE *pPVar7;
  PCW_SILO_CONTEXT *this;
  unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_> *this_00;
  PCW_SILO_CONTEXT *pPVar8;
  PCW_COUNTERSET_BASE *this_01;
  PCW_SILO_NEUTRAL_COUNTERSET *local_res18;
  PCW_SILO_CONTEXT *local_res20;
  
  local_res20 = (PCW_SILO_CONTEXT *)0x0;
  uVar2 = PsGetSiloMonitorContextSlot(DAT_140011460);
  uVar4 = PsGetCurrentServerSilo();
  PsGetPermanentSiloContext(uVar4,uVar2,&local_res20);
  pPVar8 = local_res20;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(pPVar8,0);
  p_Var1 = (_RTL_RB_TREE *)(pPVar8 + 8);
  pPVar5 = PCW_COUNTERSET_BASE::FindNode(p_Var1,param_2);
  if (pPVar5 != (PCW_COUNTERSET_BASE *)0x0) {
    LOCK();
    *(int *)(pPVar5 + 0x98) = *(int *)(pPVar5 + 0x98) + 1;
    UNLOCK();
  }
  this = pPVar8;
  ExReleasePushLockSharedEx(pPVar8,0);
  KeLeaveCriticalRegion();
  if (pPVar5 == (PCW_COUNTERSET_BASE *)0x0) {
    local_res18 = (PCW_SILO_NEUTRAL_COUNTERSET *)0x0;
    this_00 = (unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
               *)&local_res18;
    lVar3 = PCW_SILO_NEUTRAL_COUNTERSET::FindOrCreate(this_00,param_2);
    if (-1 < lVar3) {
      this_00 = (unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
                 *)0x100;
      pPVar6 = (PCW_COUNTERSET *)ExAllocatePool2(0x100,0xa0,0x43776350);
      if (pPVar6 != (PCW_COUNTERSET *)0x0) {
        pPVar5 = (PCW_COUNTERSET_BASE *)
                 PCW_COUNTERSET(pPVar6,(unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
                                        *)&local_res18,pPVar8);
        this_00 = (unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
                   *)pPVar6;
        if (pPVar5 != (PCW_COUNTERSET_BASE *)0x0) {
          if (local_res18 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
            ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
                      ((ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)pPVar6,local_res18);
          }
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(pPVar8,0);
          pPVar7 = PCW_COUNTERSET_BASE::FindNode(p_Var1,param_2);
          if (pPVar7 == (PCW_COUNTERSET_BASE *)0x0) {
            PCW_COUNTERSET_BASE::InsertNode(p_Var1,(_UNICODE_STRING *)(pPVar5 + 0x18),pPVar5);
            this_01 = (PCW_COUNTERSET_BASE *)0x0;
          }
          else {
            LOCK();
            *(int *)(pPVar7 + 0x98) = *(int *)(pPVar7 + 0x98) + 1;
            UNLOCK();
            this_01 = pPVar5;
            pPVar5 = pPVar7;
          }
          ExReleasePushLockExclusiveEx(pPVar8,0);
          KeLeaveCriticalRegion();
          this = pPVar8;
          if (this_01 != (PCW_COUNTERSET_BASE *)0x0) {
            ~PCW_COUNTERSET((PCW_COUNTERSET *)this_01);
            ExFreePoolWithTag(this_01,0);
            this = (PCW_SILO_CONTEXT *)this_01;
          }
          pPVar6 = *(PCW_COUNTERSET **)param_1;
          *(PCW_COUNTERSET_BASE **)param_1 = pPVar5;
          goto LAB_14000d421;
        }
      }
      lVar3 = -0x3fffffe9;
    }
    if (local_res18 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
                ((ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)this_00,local_res18);
    }
  }
  else {
    pPVar6 = *(PCW_COUNTERSET **)param_1;
    *(PCW_COUNTERSET_BASE **)param_1 = pPVar5;
LAB_14000d421:
    if (pPVar6 != (PCW_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_COUNTERSET>::operator()((ReleaseDeleter<PCW_COUNTERSET> *)this,pPVar6);
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== FindOrCreate @ 14000d560 =====

/* public: static long __cdecl PCW_COUNTERSET::FindOrCreate(class utl::unique_ptr<class
   PCW_COUNTERSET,struct ReleaseDeleter<class PCW_COUNTERSET> > * __ptr64,struct _UNICODE_STRING
   const * __ptr64,unsigned long) */

long __cdecl
PCW_COUNTERSET::FindOrCreate
          (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *param_1,
          _UNICODE_STRING *param_2,ulong param_3)

{
  longlong lVar1;
  PCW_COUNTERSET *pPVar2;
  PCW_COUNTERSET *pPVar3;
  long lVar4;
  unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *this;
  ReleaseDeleter<PCW_COUNTERSET> *this_00;
  PCW_COUNTERSET *local_res20;
  
  local_res20 = (PCW_COUNTERSET *)0x0;
  this = (unique_ptr<PCW_COUNTERSET,ReleaseDeleter<PCW_COUNTERSET>_> *)&local_res20;
  lVar4 = FindOrCreate(this,param_2);
  pPVar3 = local_res20;
  if (lVar4 < 0) {
    if (local_res20 != (PCW_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_COUNTERSET>::operator()((ReleaseDeleter<PCW_COUNTERSET> *)this,local_res20)
      ;
    }
  }
  else {
    lVar1 = *(longlong *)(local_res20 + 0x50);
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(lVar1 + 0x58,0);
    lVar4 = PcwpAccessCheck(*(PCW_SILO_NEUTRAL_COUNTERSET **)(pPVar3 + 0x50),param_3);
    this_00 = (ReleaseDeleter<PCW_COUNTERSET> *)(lVar1 + 0x58);
    ExReleasePushLockSharedEx(this_00,0);
    KeLeaveCriticalRegion();
    if (lVar4 < 0) {
      ReleaseDeleter<PCW_COUNTERSET>::operator()(this_00,pPVar3);
    }
    else {
      pPVar2 = *(PCW_COUNTERSET **)param_1;
      *(PCW_COUNTERSET **)param_1 = pPVar3;
      if (pPVar2 != (PCW_COUNTERSET *)0x0) {
        ReleaseDeleter<PCW_COUNTERSET>::operator()(this_00,pPVar2);
      }
      lVar4 = 0;
    }
  }
  return lVar4;
}



===== NextInstance @ 14000d634 =====

/* public: class utl::unique_ptr<struct _PCW_INSTANCE,struct ReleaseDeleter<struct _PCW_INSTANCE> >
   __cdecl PCW_COUNTERSET_BASE::NextInstance(class utl::unique_ptr<struct _PCW_INSTANCE,struct
   ReleaseDeleter<struct _PCW_INSTANCE> >) __ptr64 */

longlong * __thiscall
PCW_COUNTERSET_BASE::NextInstance(PCW_COUNTERSET_BASE *this,longlong *param_2,longlong *param_3)

{
  _PCW_INSTANCE *this_00;
  PCW_COUNTERSET_BASE *pPVar1;
  
  *param_2 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(this + 0x38,0);
  pPVar1 = (PCW_COUNTERSET_BASE *)*param_3;
  if ((PCW_COUNTERSET_BASE *)*param_3 == (PCW_COUNTERSET_BASE *)0x0) {
    pPVar1 = this + 0x40;
  }
  pPVar1 = *(PCW_COUNTERSET_BASE **)pPVar1;
  if (pPVar1 != this + 0x40) {
    if (pPVar1 != (PCW_COUNTERSET_BASE *)0x0) {
      LOCK();
      *(int *)(pPVar1 + 0x4c) = *(int *)(pPVar1 + 0x4c) + 1;
      UNLOCK();
    }
    this_00 = (_PCW_INSTANCE *)*param_2;
    *param_2 = (longlong)pPVar1;
    if (this_00 != (_PCW_INSTANCE *)0x0) {
      _PCW_INSTANCE::Release(this_00);
    }
  }
  ExReleasePushLockSharedEx(this + 0x38,0);
  KeLeaveCriticalRegion();
  if ((_PCW_INSTANCE *)*param_3 != (_PCW_INSTANCE *)0x0) {
    _PCW_INSTANCE::Release((_PCW_INSTANCE *)*param_3);
  }
  return param_2;
}



===== Notify @ 14000d6ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl PCW_COUNTERSET_BASE::Notify(enum _PCW_CALLBACK_TYPE,union
   _PCW_CALLBACK_INFORMATION * __ptr64)const __ptr64 */

void __thiscall
PCW_COUNTERSET_BASE::Notify
          (PCW_COUNTERSET_BASE *this,_PCW_CALLBACK_TYPE param_1,_PCW_CALLBACK_INFORMATION *param_2)

{
  PCW_COUNTERSET_BASE *pPVar1;
  
  for (pPVar1 = *(PCW_COUNTERSET_BASE **)(this + 0x28); pPVar1 != this + 0x28;
      pPVar1 = *(PCW_COUNTERSET_BASE **)pPVar1) {
    if (*(code **)(pPVar1 + 0x30) != (code *)0x0) {
      (**(code **)(pPVar1 + 0x30))(param_1,param_2,*(undefined8 *)(pPVar1 + 0x38));
    }
  }
  return;
}



===== Release @ 14000d74c =====

/* public: void __cdecl _PCW_INSTANCE::Release(void) __ptr64 */

void __thiscall _PCW_INSTANCE::Release(_PCW_INSTANCE *this)

{
  _PCW_INSTANCE *p_Var1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  int iVar6;
  longlong lVar7;
  bool bVar8;
  
  iVar6 = *(int *)(this + 0x4c);
  do {
    if (iVar6 < 2) {
      lVar7 = *(longlong *)(this + 0x20);
      if (lVar7 == 0) {
        lVar7 = *(longlong *)(this + 0x28);
      }
      KeEnterCriticalRegion();
      lVar7 = lVar7 + 0x38;
      ExAcquirePushLockExclusiveEx(lVar7,0);
      LOCK();
      p_Var1 = this + 0x4c;
      iVar6 = *(int *)p_Var1;
      *(int *)p_Var1 = *(int *)p_Var1 + -1;
      UNLOCK();
      if (iVar6 != 1) {
        ExReleasePushLockExclusiveEx(lVar7,0);
        KeLeaveCriticalRegion();
        return;
      }
      lVar3 = *(longlong *)this;
      if ((*(_PCW_INSTANCE **)(lVar3 + 8) == this) &&
         (plVar4 = *(longlong **)(this + 8), (_PCW_INSTANCE *)*plVar4 == this)) {
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        ExReleasePushLockExclusiveEx(lVar7,0);
        KeLeaveCriticalRegion();
        ~_PCW_INSTANCE(this);
        ExFreePoolWithTag(this,0);
        return;
      }
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    LOCK();
    iVar2 = *(int *)(this + 0x4c);
    bVar8 = iVar6 == iVar2;
    if (bVar8) {
      *(int *)(this + 0x4c) = iVar6 + -1;
    }
    else {
      iVar6 = iVar2;
    }
    UNLOCK();
  } while (!bVar8);
  return;
}



===== McTemplateU0qhzr1_EtwWriteTransfer @ 14000d830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qhzr1_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort param_4,
               undefined8 param_5)

{
  undefined4 local_res18 [2];
  ushort local_res20 [4];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_30 = 2;
  local_48 = local_res18;
  local_40 = 4;
  local_38 = local_res20;
  local_1c = 0;
  local_28 = param_5;
  local_20 = (uint)param_4 * 2;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(0,&PcwRegisterFail,param_3,4,local_58);
  return;
}



===== McTemplateU0qhzr1hzr3_EtwWriteTransfer @ 14000d8c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qhzr1hzr3_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,ushort param_4,
               undefined8 param_5,ushort param_6,undefined8 param_7)

{
  undefined4 local_res18 [2];
  ushort local_res20 [4];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  ushort *local_58;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_60 = 4;
  local_68 = local_res18;
  local_50 = 2;
  local_58 = local_res20;
  local_48 = param_5;
  local_40 = (uint)param_4 * 2;
  local_3c = 0;
  local_38 = &param_6;
  local_28 = param_7;
  local_20 = (uint)param_6 * 2;
  local_30 = 2;
  local_1c = 0;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,6,local_78);
  return;
}



===== PcwAddInstance @ 14000d980 =====

int PcwAddInstance(_PCW_BUFFER *param_1,_UNICODE_STRING *param_2,ulong param_3,ulong param_4,
                  _PCW_DATA *param_5)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  
  bVar1 = PcwpWildcardMatch(*(_UNICODE_STRING **)(param_1 + 0x28),param_2);
  if (!bVar1) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    if ((*(ulong *)(param_1 + 0x30) != 0xffffffff) && (*(ulong *)(param_1 + 0x30) != param_3)) {
      return 0;
    }
    bVar1 = PcwpWildcardMatch(*(_UNICODE_STRING **)(param_1 + 0x28),param_2);
    if (!bVar1) {
      return 0;
    }
    if ((*(int *)(param_1 + 0x34) == 0) && (*(int *)(param_1 + 0x18) != 0)) {
      return 0;
    }
    iVar2 = _PCW_BUFFER::CollectInstance
                      (param_1,*(_PCW_REGISTRATION **)(param_1 + 0x20),param_2,param_3,param_4,
                       (void **)0x0,param_5);
  }
  else {
    if (*(int *)(param_1 + 0x10) != 1) {
      iVar2 = -0x3fffffff;
      goto LAB_14000da2b;
    }
    iVar2 = _PCW_BUFFER::AddInstanceName(param_1,param_2,param_3);
  }
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_14000da2b:
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x20);
  if (lVar3 == 0) {
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x28);
  }
  if (((byte)Microsoft_Windows_Diagnosis_PCWEnableBits & 1) == 0) {
    return iVar2;
  }
  McTemplateU0qhzr1hzr3_EtwWriteTransfer
            ((ulonglong)(*(ushort *)param_2 >> 1),&PcwAddFail,iVar2,*(ushort *)(lVar3 + 0x18) >> 1,
             *(undefined8 *)(lVar3 + 0x20),*(ushort *)param_2 >> 1,*(undefined8 *)(param_2 + 8));
  return iVar2;
}



===== PcwCloseInstance @ 14000daa0 =====

void PcwCloseInstance(_PCW_INSTANCE *param_1)

{
  _PCW_INSTANCE::Close(param_1);
  return;
}



===== PcwCreateInstance @ 14000dac0 =====

long PcwCreateInstance(_PCW_INSTANCE **param_1,_PCW_REGISTRATION *param_2,_UNICODE_STRING *param_3,
                      ulong param_4,_PCW_DATA *param_5)

{
  long lVar1;
  longlong lVar2;
  
  lVar1 = _PCW_INSTANCE::Create(param_1,param_2,param_3,param_4,param_5);
  if (lVar1 < 0) {
    lVar2 = *(longlong *)(param_2 + 0x20);
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_2 + 0x28);
    }
    if (((byte)Microsoft_Windows_Diagnosis_PCWEnableBits & 1) != 0) {
      McTemplateU0qhzr1hzr3_EtwWriteTransfer
                ((ulonglong)(*(ushort *)param_3 >> 1),&PcwCreateFail,lVar1,
                 *(ushort *)(lVar2 + 0x18) >> 1,*(undefined8 *)(lVar2 + 0x20),
                 *(ushort *)param_3 >> 1,*(undefined8 *)(param_3 + 8));
    }
  }
  return lVar1;
}



===== PcwRegister @ 14000db50 =====

uint PcwRegister(_PCW_REGISTRATION **param_1,int *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  PCW_REGISTRATION_FLAGS PVar3;
  _UNICODE_STRING *p_Var4;
  
  p_Var4 = *(_UNICODE_STRING **)(param_2 + 2);
  if ((*(ushort *)p_Var4 == 0) || ((*(ushort *)p_Var4 & 1) != 0)) {
LAB_14000dbc5:
    uVar2 = 0xc00000f0;
  }
  else {
    if (*param_2 == 0x100) {
      PVar3 = 0;
    }
    else if ((*param_2 != 0x200) || (PVar3 = param_2[0xc], PVar3 != (PVar3 & 1)))
    goto LAB_14000dbc5;
    uVar2 = _PCW_REGISTRATION::Create
                      (param_1,p_Var4,param_2[4],*(_PCW_COUNTER_DESCRIPTOR **)(param_2 + 6),
                       *(_func_long__PCW_CALLBACK_TYPE__PCW_CALLBACK_INFORMATION_ptr_void_ptr **)
                        (param_2 + 8),*(void **)(param_2 + 10),PVar3);
    if (-1 < (int)uVar2) {
      return uVar2;
    }
  }
  if (((byte)Microsoft_Windows_Diagnosis_PCWEnableBits & 1) != 0) {
    uVar1 = *(undefined8 *)(*(ushort **)(param_2 + 2) + 4);
    McTemplateU0qhzr1_EtwWriteTransfer
              (uVar1,p_Var4,(ulonglong)uVar2,**(ushort **)(param_2 + 2) >> 1,uVar1);
  }
  return uVar2;
}



===== PcwUnregister @ 14000dc10 =====

void PcwUnregister(_PCW_REGISTRATION *param_1)

{
  if (param_1 != (_PCW_REGISTRATION *)0x0) {
    _PCW_REGISTRATION::~_PCW_REGISTRATION(param_1);
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== PcwpAccessCheck @ 14000dc40 =====

/* long __cdecl PcwpAccessCheck(class PCW_SILO_NEUTRAL_COUNTERSET const * __ptr64,unsigned long) */

long __cdecl PcwpAccessCheck(PCW_SILO_NEUTRAL_COUNTERSET *param_1,ulong param_2)

{
  char cVar1;
  long local_res8 [2];
  undefined4 local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  local_res8[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  SeCaptureSubjectContext(&local_28);
  cVar1 = SeAccessCheck(*(undefined8 *)(param_1 + 0x60),&local_28,0,param_2,0,0,
                        &PcwCounterSetGenericMap,1,local_res18,local_res8);
  SeReleaseSubjectContext(&local_28);
  if (cVar1 != '\0') {
    local_res8[0] = 0;
  }
  return local_res8[0];
}



===== PcwpClearCounterSetSecurityDescriptor @ 14000dd00 =====

/* long __cdecl PcwpClearCounterSetSecurityDescriptor(struct _UNICODE_STRING const * __ptr64) */

long __cdecl PcwpClearCounterSetSecurityDescriptor(_UNICODE_STRING *param_1)

{
  longlong lVar1;
  PCW_SILO_NEUTRAL_COUNTERSET *pPVar2;
  long lVar3;
  unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_> *this;
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *this_00;
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *pRVar4;
  PCW_SILO_NEUTRAL_COUNTERSET *local_res10;
  
  local_res10 = (PCW_SILO_NEUTRAL_COUNTERSET *)0x0;
  lVar3 = PcwpOpenSecurityKey();
  if (lVar3 < 0) {
    return lVar3;
  }
  lVar3 = PcwpInitDefaultSecurityDescriptor();
  if (lVar3 < 0) {
    return lVar3;
  }
  this = (unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_> *)
         &local_res10;
  lVar3 = PCW_SILO_NEUTRAL_COUNTERSET::FindOrCreate(this,param_1);
  if (lVar3 < 0) {
    if (local_res10 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
                ((ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)this,local_res10);
    }
    return lVar3;
  }
  KeEnterCriticalRegion();
  pPVar2 = local_res10;
  pRVar4 = (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)(local_res10 + 0x58);
  ExAcquirePushLockSharedEx(pRVar4,0);
  lVar3 = PcwpAccessCheck(pPVar2,0x10c0000);
  this_00 = pRVar4;
  ExReleasePushLockSharedEx(pRVar4,0);
  KeLeaveCriticalRegion();
  if (lVar3 < 0) {
    if (pPVar2 == (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
      return lVar3;
    }
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(pRVar4,0);
    if ((PcwDefaultSecurityDescriptor != *(void **)(pPVar2 + 0x60)) &&
       (lVar3 = ZwDeleteValueKey(PcwSecurityKey,pPVar2 + 0x18), -1 < lVar3)) {
      ObReferenceSecurityDescriptor(PcwDefaultSecurityDescriptor,1);
      lVar1 = *(longlong *)(pPVar2 + 0x60);
      *(void **)(pPVar2 + 0x60) = PcwDefaultSecurityDescriptor;
      if (lVar1 != 0) {
        ObDereferenceSecurityDescriptor(lVar1,1);
      }
    }
    ExReleasePushLockExclusiveEx(pRVar4,0);
    KeLeaveCriticalRegion();
    this_00 = pRVar4;
  }
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()(this_00,pPVar2);
  return lVar3;
}



===== PcwpCreateAllowedDacl @ 14000de84 =====

/* long __cdecl PcwpCreateAllowedDacl(class utl::unique_ptr<struct _ACL,struct
   utl::default_delete<struct _ACL> > * __ptr64,unsigned long,...) */

long __cdecl
PcwpCreateAllowedDacl(unique_ptr<_ACL,utl::default_delete<_ACL>_> *param_1,ulong param_2,...)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = in_R8;
  local_res20 = in_R9;
  uVar7 = 0;
  puVar6 = &local_res18;
  uVar5 = 8;
  if (param_2 != 0) {
    do {
      uVar4 = *puVar6;
      puVar6 = puVar6 + 2;
      uVar2 = RtlLengthSid(uVar4);
      if ((uVar5 + uVar2 < uVar2) || (uVar5 = uVar5 + uVar2 + 0xc, uVar5 < 0xc)) {
        return -0x3fffff6b;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_2);
  }
  uVar4 = ExAllocatePool2(0x100,uVar5,0x54776350);
  lVar1 = *(longlong *)param_1;
  *(undefined8 *)param_1 = uVar4;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  iVar3 = RtlCreateAcl(*(undefined8 *)param_1,uVar5,2);
  if (-1 < iVar3) {
    uVar5 = 0;
    puVar6 = &local_res18;
    if (param_2 != 0) {
      do {
        iVar3 = RtlAddAccessAllowedAce(*(undefined8 *)param_1,2,*(undefined4 *)(puVar6 + 1),*puVar6)
        ;
        if (iVar3 < 0) {
          return iVar3;
        }
        uVar5 = uVar5 + 1;
        puVar6 = puVar6 + 2;
      } while (uVar5 < param_2);
    }
    iVar3 = 0;
  }
  return iVar3;
}



===== PcwpCreateDefaultSecurityDescriptor @ 14000df7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl PcwpCreateDefaultSecurityDescriptor(class utl::unique_ptr<void,struct
   ObDereferenceSecurityDescriptorDeleter> * __ptr64) */

long __cdecl
PcwpCreateDefaultSecurityDescriptor
          (unique_ptr<void,ObDereferenceSecurityDescriptorDeleter> *param_1)

{
  longlong lVar1;
  longlong lVar2;
  long lVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_238 [32];
  undefined8 local_218;
  undefined4 local_210;
  undefined1 *local_208;
  undefined4 local_200;
  undefined1 *local_1f8;
  undefined4 local_1f0;
  undefined1 *local_1e8;
  undefined4 local_1e0;
  undefined8 local_1d8;
  undefined4 local_1d0;
  undefined8 local_1c8;
  undefined4 local_1c0;
  undefined8 local_1b8;
  undefined4 local_1b0;
  undefined8 local_1a8;
  undefined4 local_1a0;
  int local_198 [2];
  longlong local_190 [2];
  wchar_t *local_180;
  longlong local_178 [5];
  undefined4 local_150;
  undefined2 local_14c;
  undefined1 local_148 [72];
  undefined1 local_100 [72];
  undefined1 local_b8 [72];
  undefined1 local_70 [72];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_238;
  local_150 = 0;
  local_190[0] = 0;
  local_180 = L"windowsPerformanceCounters";
  local_210 = 0x22f;
  local_190[1] = 0x360034;
  local_14c = 0x500;
  local_178[0] = 0;
  local_178[1] = 0;
  local_178[4] = 0;
  local_178[2] = 0;
  local_178[3] = 0;
  local_218._0_4_ = 0x20;
  lVar3 = PcwpInitSid(local_b8,0x44,(_SID_IDENTIFIER_AUTHORITY *)&local_150,'\x02');
  if (-1 < lVar3) {
    local_210 = 0x22e;
    local_218 = CONCAT44(local_218._4_4_,0x20);
    lVar3 = PcwpInitSid(local_100,0x44,(_SID_IDENTIFIER_AUTHORITY *)&local_150,'\x02');
    if ((((-1 < lVar3) &&
         (lVar3 = RtlDeriveCapabilitySidsFromName(local_190 + 1,local_70,local_148), -1 < lVar3)) &&
        (lVar3 = RtlCreateSecurityDescriptor(local_190 + 3,1), -1 < lVar3)) &&
       (lVar3 = RtlSetOwnerSecurityDescriptor
                          (local_190 + 3,*(undefined8 *)(*(longlong *)SeExports_exref + 0x110),0),
       -1 < lVar3)) {
      iVar4 = RtlSetGroupSecurityDescriptor
                        (local_190 + 3,*(undefined8 *)(*(longlong *)SeExports_exref + 0x110),0);
      if (iVar4 < 0) {
        lVar3 = 1;
      }
      else {
        local_1a0 = 2;
        lVar1 = *(longlong *)SeExports_exref;
        local_1a8 = *(undefined8 *)(lVar1 + 0xc0);
        local_1b8 = *(undefined8 *)(lVar1 + 0x188);
        local_1b0 = 3;
        local_1c8 = *(undefined8 *)(lVar1 + 0x180);
        local_1c0 = 3;
        local_1d8 = *(undefined8 *)(lVar1 + 0x100);
        local_1d0 = _PcwCounterSetGenericMap;
        local_1e8 = local_148;
        local_1e0 = 3;
        local_1f8 = local_100;
        local_1f0 = _PcwCounterSetGenericMap;
        local_208 = local_b8;
        local_200 = _PcwCounterSetGenericMap;
        local_218 = *(undefined8 *)(lVar1 + 0x110);
        local_210 = DAT_14001121c;
        lVar3 = PcwpCreateAllowedDacl
                          ((unique_ptr<_ACL,utl::default_delete<_ACL>_> *)local_190,9,
                           *(undefined8 *)(lVar1 + 0x108));
        lVar1 = local_190[0];
        if (lVar3 < 0) {
          if (local_190[0] != 0) {
            ExFreePoolWithTag(local_190[0],0);
          }
        }
        else {
          lVar3 = RtlSetDaclSecurityDescriptor(local_190 + 3,1,local_190[0],0);
          if (lVar3 < 0) {
            if (lVar1 != 0) {
              ExFreePoolWithTag(lVar1,0);
            }
          }
          else {
            local_198[0] = RtlLengthSecurityDescriptor(local_190 + 3);
            local_198[0] = local_198[0] + 0x14;
            lVar5 = ExAllocatePool2(0x100,local_198[0],0x54776350);
            if (lVar5 == 0) {
              if (lVar1 != 0) {
                ExFreePoolWithTag(lVar1,0);
              }
              lVar3 = -0x3fffffe9;
            }
            else {
              lVar3 = RtlAbsoluteToSelfRelativeSD(local_190 + 3,lVar5,local_198);
              if (-1 < lVar3) {
                lVar2 = *(longlong *)param_1;
                *(undefined8 *)param_1 = 0;
                if (lVar2 != 0) {
                  ObDereferenceSecurityDescriptor(lVar2,1);
                }
                lVar3 = ObLogSecurityDescriptor(lVar5,param_1,1);
              }
              ExFreePoolWithTag(lVar5,0);
              if (lVar1 != 0) {
                ExFreePoolWithTag(lVar1,0);
              }
            }
          }
        }
      }
    }
  }
  return lVar3;
}



===== PcwpGetCounterSetSecurityDescriptor @ 14000e2e8 =====

/* long __cdecl PcwpGetCounterSetSecurityDescriptor(struct _UNICODE_STRING const * __ptr64,unsigned
   long,void * __ptr64,unsigned long * __ptr64) */

long __cdecl
PcwpGetCounterSetSecurityDescriptor
          (_UNICODE_STRING *param_1,ulong param_2,void *param_3,ulong *param_4)

{
  PCW_SILO_NEUTRAL_COUNTERSET *pPVar1;
  long lVar2;
  unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_> *this;
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *this_00;
  uint uVar3;
  uint uVar4;
  ulong local_res10 [2];
  PCW_SILO_NEUTRAL_COUNTERSET *local_28 [2];
  
  local_28[0] = (PCW_SILO_NEUTRAL_COUNTERSET *)0x0;
  uVar4 = -(uint)((param_2 & 0x17) != 0) & 0x20000;
  this = (unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_> *)
         local_28;
  uVar3 = uVar4 | 0x1000000;
  if ((param_2 & 8) == 0) {
    uVar3 = uVar4;
  }
  local_res10[0] = param_2;
  lVar2 = PCW_SILO_NEUTRAL_COUNTERSET::FindOrCreate(this,param_1);
  if (lVar2 < 0) {
    if (local_28[0] != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()
                ((ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)this,local_28[0]);
    }
  }
  else {
    KeEnterCriticalRegion();
    pPVar1 = local_28[0];
    ExAcquirePushLockSharedEx(local_28[0] + 0x58,0);
    lVar2 = PcwpAccessCheck(pPVar1,uVar3);
    if (-1 < lVar2) {
      lVar2 = SeQuerySecurityDescriptorInfo(local_res10,param_3,param_4,pPVar1 + 0x60);
    }
    this_00 = (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)(pPVar1 + 0x58);
    ExReleasePushLockSharedEx(this_00,0);
    KeLeaveCriticalRegion();
    if (pPVar1 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()(this_00,pPVar1);
    }
  }
  return lVar2;
}



===== PcwpInitDefaultSecurityDescriptor @ 14000e3e4 =====

/* long __cdecl PcwpInitDefaultSecurityDescriptor(void) */

long __cdecl PcwpInitDefaultSecurityDescriptor(void)

{
  long lVar1;
  bool bVar2;
  void *local_res8;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_18 = 0x20000;
  local_10 = L"";
  local_res8 = (void *)0x0;
  if (PcwDefaultSecurityDescriptor == (void *)0x0) {
    lVar1 = PcwpReadSecurityDescriptor
                      ((unique_ptr<void,ObDereferenceSecurityDescriptorDeleter> *)&local_res8,
                       (_UNICODE_STRING *)&local_18);
    if ((lVar1 < 0) &&
       ((lVar1 != -0x3fffffcc ||
        (lVar1 = PcwpCreateDefaultSecurityDescriptor
                           ((unique_ptr<void,ObDereferenceSecurityDescriptorDeleter> *)&local_res8),
        lVar1 < 0)))) {
      if (local_res8 != (void *)0x0) {
        ObDereferenceSecurityDescriptor(local_res8,1);
      }
      return lVar1;
    }
    LOCK();
    bVar2 = PcwDefaultSecurityDescriptor == (void *)0x0;
    if (bVar2) {
      PcwDefaultSecurityDescriptor = local_res8;
    }
    UNLOCK();
    if (bVar2) {
      local_res8 = (void *)0x0;
    }
    if (local_res8 != (void *)0x0) {
      ObDereferenceSecurityDescriptor(local_res8,1);
    }
  }
  return 0;
}



===== PcwpInitSid @ 14000e4b0 =====

/* long __cdecl PcwpInitSid(void * __ptr64,unsigned long,struct _SID_IDENTIFIER_AUTHORITY *
   __ptr64,unsigned char,...) */

long __cdecl
PcwpInitSid(void *param_1,ulong param_2,_SID_IDENTIFIER_AUTHORITY *param_3,uchar param_4,...)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  uint uVar6;
  byte local_res20 [8];
  
  uVar6 = 0;
  local_res20[0] = param_4;
  uVar2 = RtlLengthRequiredSid(param_4);
  if (param_2 < uVar2) {
    iVar3 = -0x3fffffdd;
  }
  else {
    iVar3 = RtlInitializeSid(param_1,param_3,local_res20[0]);
    if (-1 < iVar3) {
      if (local_res20[0] != 0) {
        pbVar5 = local_res20;
        do {
          pbVar5 = pbVar5 + 8;
          uVar1 = *(undefined4 *)pbVar5;
          puVar4 = (undefined4 *)RtlSubAuthoritySid(param_1,uVar6);
          uVar6 = uVar6 + 1;
          *puVar4 = uVar1;
        } while (uVar6 < local_res20[0]);
      }
      iVar3 = 0;
    }
  }
  return iVar3;
}



===== PcwpOpenSecurityKey @ 14000e548 =====

/* long __cdecl PcwpOpenSecurityKey(void) */

long __cdecl PcwpOpenSecurityKey(void)

{
  int iVar1;
  bool bVar2;
  void *local_res8 [4];
  undefined8 local_48;
  wchar_t *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = (void *)0x0;
  local_34 = 0;
  local_1c = 0;
  local_40 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\PCW\\Security";
  local_48 = 0x80007e;
  if (PcwSecurityKey == (void *)0x0) {
    local_30 = 0;
    local_28 = &local_48;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwOpenKey(local_res8,0x2001f,&local_38);
    if (iVar1 < 0) {
      return iVar1;
    }
    LOCK();
    bVar2 = PcwSecurityKey == (void *)0x0;
    if (bVar2) {
      PcwSecurityKey = local_res8[0];
    }
    UNLOCK();
    if (!bVar2) {
      ZwClose(local_res8[0]);
    }
  }
  return 0;
}



===== PcwpReadSecurityDescriptor @ 14000e5ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PcwpReadSecurityDescriptor(class utl::unique_ptr<void,struct
   ObDereferenceSecurityDescriptorDeleter> * __ptr64,struct _UNICODE_STRING const * __ptr64) */

long __cdecl
PcwpReadSecurityDescriptor
          (unique_ptr<void,ObDereferenceSecurityDescriptorDeleter> *param_1,_UNICODE_STRING *param_2
          )

{
  longlong lVar1;
  char cVar2;
  long lVar3;
  undefined1 *puVar4;
  void *_Dst;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 auStack_478 [32];
  uint local_458;
  uint *local_450;
  uint local_448 [4];
  undefined1 local_438 [1024];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_478;
  uVar7 = 0x400;
  memset(local_438,0,0x400);
  puVar6 = local_438;
  lVar3 = PcwpOpenSecurityKey();
  if (-1 < lVar3) {
    local_448[0] = 0x400;
    puVar5 = (undefined1 *)0x0;
    do {
      puVar4 = puVar5;
      if (uVar7 < local_448[0]) {
        puVar4 = (undefined1 *)ExAllocatePool2(0x100,local_448[0],0x54776350);
        if (puVar5 != (undefined1 *)0x0) {
          ExFreePoolWithTag(puVar5,0);
        }
        if (puVar4 == (undefined1 *)0x0) {
          return -0x3fffffe9;
        }
        puVar6 = puVar4;
        uVar7 = local_448[0];
      }
      local_450 = local_448;
      local_458 = uVar7;
      lVar3 = ZwQueryValueKey(PcwSecurityKey,param_2,2,puVar6);
      puVar5 = puVar4;
    } while (lVar3 == -0x7ffffffb);
    if (-1 < lVar3) {
      _Dst = (void *)ExAllocatePool2(0x100,*(undefined4 *)(puVar6 + 8),0x54776350);
      if (_Dst == (void *)0x0) {
        lVar3 = -0x3fffffe9;
      }
      else {
        memmove(_Dst,puVar6 + 0xc,(ulonglong)*(uint *)(puVar6 + 8));
        cVar2 = RtlValidRelativeSecurityDescriptor(_Dst,*(undefined4 *)(puVar6 + 8),3);
        if (cVar2 == '\0') {
          lVar3 = -0x3fffff87;
        }
        else {
          lVar1 = *(longlong *)param_1;
          *(undefined8 *)param_1 = 0;
          if (lVar1 != 0) {
            ObDereferenceSecurityDescriptor(lVar1,1);
          }
          lVar3 = ObLogSecurityDescriptor(_Dst,param_1,1);
        }
        ExFreePoolWithTag(_Dst,0);
      }
    }
    if (puVar4 != (undefined1 *)0x0) {
      ExFreePoolWithTag(puVar4,0);
    }
  }
  return lVar3;
}



===== PcwpSetCounterSetSecurityDescriptor @ 14000e7c8 =====

/* long __cdecl PcwpSetCounterSetSecurityDescriptor(struct _UNICODE_STRING const * __ptr64,unsigned
   long,void * __ptr64) */

long __cdecl
PcwpSetCounterSetSecurityDescriptor(_UNICODE_STRING *param_1,ulong param_2,void *param_3)

{
  PCW_SILO_NEUTRAL_COUNTERSET *pPVar1;
  PCW_SILO_NEUTRAL_COUNTERSET *pPVar2;
  long lVar3;
  undefined4 uVar4;
  uint uVar5;
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *pRVar6;
  uint uVar7;
  uint local_res10 [4];
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *local_res20;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar8;
  PCW_SILO_NEUTRAL_COUNTERSET *local_38;
  longlong local_30;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  local_38 = (PCW_SILO_NEUTRAL_COUNTERSET *)0x0;
  local_res20 = (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)0x0;
  local_res10[0] = param_2;
  lVar3 = PcwpOpenSecurityKey();
  if (lVar3 < 0) {
    if (local_res20 != (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)0x0) {
      ObDereferenceSecurityDescriptor(local_res20,1);
    }
  }
  else {
    uVar5 = -(uint)((local_res10[0] & 3) != 0) & 0x80000;
    uVar7 = uVar5 | 0x40000;
    if ((local_res10[0] & 4) == 0) {
      uVar7 = uVar5;
    }
    uVar5 = uVar7 | 0x1000000;
    if ((local_res10[0] & 8) == 0) {
      uVar5 = uVar7;
    }
    lVar3 = PCW_SILO_NEUTRAL_COUNTERSET::FindOrCreate
                      ((unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
                        *)&local_38,param_1);
    if (-1 < lVar3) {
      KeEnterCriticalRegion();
      pPVar2 = local_38;
      pPVar1 = local_38 + 0x58;
      ExAcquirePushLockSharedEx(pPVar1,0);
      local_30 = *(longlong *)(pPVar2 + 0x60);
      lVar3 = PcwpAccessCheck(pPVar2,uVar5);
      if (-1 < lVar3) {
        uVar8 = 1;
        lVar3 = SeSetSecurityDescriptorInfo
                          (0,local_res10,param_3,&local_30,1,&PcwCounterSetGenericMap);
      }
      ExReleasePushLockSharedEx(pPVar1,0);
      KeLeaveCriticalRegion();
      if (-1 < lVar3) {
        if (local_res20 != (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)0x0) {
          ObDereferenceSecurityDescriptor(local_res20,1);
        }
        lVar3 = ObLogSecurityDescriptor(local_30,&local_res20,1);
        if (local_30 != 0) {
          ExFreePoolWithTag(local_30,0);
        }
        if (-1 < lVar3) {
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(pPVar1,0);
          uVar4 = RtlLengthSecurityDescriptor(local_res20);
          lVar3 = ZwSetValueKey(PcwSecurityKey,pPVar2 + 0x18,0,3,local_res20,CONCAT44(uVar8,uVar4));
          if (-1 < lVar3) {
            pRVar6 = *(ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> **)(pPVar2 + 0x60);
            *(ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> **)(pPVar2 + 0x60) = local_res20;
            local_res20 = pRVar6;
          }
          ExReleasePushLockExclusiveEx(pPVar1,0);
          KeLeaveCriticalRegion();
        }
      }
      pRVar6 = local_res20;
      if (local_res20 != (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)0x0) {
        ObDereferenceSecurityDescriptor(local_res20,1);
      }
      ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()(pRVar6,pPVar2);
      return lVar3;
    }
    pRVar6 = local_res20;
    if (local_res20 != (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)0x0) {
      ObDereferenceSecurityDescriptor(local_res20,1);
    }
    if (local_38 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()(pRVar6,local_38);
    }
  }
  return lVar3;
}



===== RegisterForSiloNotifications @ 14000ea2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl PCW_SILO_CONTEXT::RegisterForSiloNotifications(struct _UNICODE_STRING
   * __ptr64) */

long __cdecl PCW_SILO_CONTEXT::RegisterForSiloNotifications(_UNICODE_STRING *param_1)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined2 local_38;
  undefined1 local_36;
  undefined4 local_35;
  undefined1 local_31;
  _UNICODE_STRING *local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_35 = 0;
  local_31 = 0;
  local_38 = 0x101;
  local_36 = 1;
  local_20 = 0;
  local_28 = SiloCreateCallback;
  local_30 = param_1;
  iVar1 = PsRegisterSiloMonitor(&local_38,&DAT_140011460);
  if (-1 < iVar1) {
    iVar1 = PsStartSiloMonitor(DAT_140011460);
    if (iVar1 < 0) {
      PsUnregisterSiloMonitor(DAT_140011460);
    }
  }
  return iVar1;
}



===== SiloContextCleanupCallback @ 14000eae0 =====

/* private: static void __cdecl PCW_SILO_CONTEXT::SiloContextCleanupCallback(void * __ptr64) */

void __cdecl PCW_SILO_CONTEXT::SiloContextCleanupCallback(void *param_1)

{
  return;
}



===== SiloCreateCallback @ 14000eaf0 =====

/* private: static long __cdecl PCW_SILO_CONTEXT::SiloCreateCallback(struct _EJOB * __ptr64) */

long __cdecl PCW_SILO_CONTEXT::SiloCreateCallback(_EJOB *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 *local_res10;
  
  local_res10 = (undefined8 *)0x0;
  iVar2 = PsCreateSiloContext(param_1,0x18,1,SiloContextCleanupCallback,&local_res10);
  puVar1 = local_res10;
  if (-1 < iVar2) {
    *local_res10 = 0;
    local_res10[1] = 0;
    local_res10[2] = 0;
    uVar3 = PsGetSiloMonitorContextSlot(DAT_140011460);
    iVar2 = PsInsertPermanentSiloContext(param_1,uVar3,puVar1);
    if (puVar1 != (undefined8 *)0x0) {
      PsDereferenceSiloContext(puVar1);
    }
  }
  return iVar2;
}



===== UnregisterForSiloNotifications @ 14000eb9c =====

/* public: static void __cdecl PCW_SILO_CONTEXT::UnregisterForSiloNotifications(void) */

void __cdecl PCW_SILO_CONTEXT::UnregisterForSiloNotifications(void)

{
  PsUnregisterSiloMonitor(DAT_140011460);
  return;
}



===== PCW_SILO_NEUTRAL_COUNTERSET @ 14000ebc0 =====

/* private: __cdecl PCW_SILO_NEUTRAL_COUNTERSET::PCW_SILO_NEUTRAL_COUNTERSET(class
   utl::unique_ptr<unsigned short [0],struct utl::default_delete<unsigned short [0]> >,unsigned
   short,class utl::unique_ptr<void,struct ObDereferenceSecurityDescriptorDeleter> && __ptr64)
   __ptr64 */

PCW_SILO_NEUTRAL_COUNTERSET * __thiscall
PCW_SILO_NEUTRAL_COUNTERSET::PCW_SILO_NEUTRAL_COUNTERSET
          (PCW_SILO_NEUTRAL_COUNTERSET *this,longlong *param_2,undefined2 param_3,
          undefined8 *param_4)

{
  PCW_SILO_NEUTRAL_COUNTERSET *pPVar1;
  PCW_SILO_NEUTRAL_COUNTERSET *pPVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = *param_2;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x18) = param_3;
  *(undefined2 *)(this + 0x1a) = param_3;
  *(undefined4 *)(this + 0x1c) = 0;
  pPVar1 = this + 0x70;
  *(longlong *)(this + 0x20) = lVar3;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  pPVar2 = this + 0x28;
  *(undefined8 *)(this + 0x48) = 0;
  *(PCW_SILO_NEUTRAL_COUNTERSET **)(this + 0x30) = pPVar2;
  *(PCW_SILO_NEUTRAL_COUNTERSET **)pPVar2 = pPVar2;
  pPVar2 = this + 0x40;
  *(PCW_SILO_NEUTRAL_COUNTERSET **)(this + 0x48) = pPVar2;
  *(PCW_SILO_NEUTRAL_COUNTERSET **)pPVar2 = pPVar2;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  uVar4 = *param_4;
  *param_4 = 0;
  *(undefined8 *)(this + 0x60) = uVar4;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)pPVar1 = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 1;
  lVar3 = *param_2;
  *param_2 = 0;
  *(longlong *)(this + 0x88) = lVar3;
  *(PCW_SILO_NEUTRAL_COUNTERSET **)(this + 0x78) = pPVar1;
  *(PCW_SILO_NEUTRAL_COUNTERSET **)pPVar1 = pPVar1;
  if (*param_2 != 0) {
    ExFreePoolWithTag(*param_2,0);
  }
  return this;
}



===== ~PCW_SILO_NEUTRAL_COUNTERSET @ 14000ec7c =====

/* private: __cdecl PCW_SILO_NEUTRAL_COUNTERSET::~PCW_SILO_NEUTRAL_COUNTERSET(void) __ptr64 */

void __thiscall
PCW_SILO_NEUTRAL_COUNTERSET::~PCW_SILO_NEUTRAL_COUNTERSET(PCW_SILO_NEUTRAL_COUNTERSET *this)

{
  if (*(longlong *)(this + 0x88) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x88),0);
  }
  if (*(longlong *)(this + 0x60) != 0) {
    ObDereferenceSecurityDescriptor(*(longlong *)(this + 0x60),1);
  }
  return;
}



===== FindNode @ 14000ecc8 =====

/* protected: static class PCW_COUNTERSET_BASE * __ptr64 __cdecl
   PCW_COUNTERSET_BASE::FindNode(struct _RTL_RB_TREE * __ptr64,struct _UNICODE_STRING const *
   __ptr64) */

PCW_COUNTERSET_BASE * __cdecl
PCW_COUNTERSET_BASE::FindNode(_RTL_RB_TREE *param_1,_UNICODE_STRING *param_2)

{
  _RTL_RB_TREE _Var1;
  int iVar2;
  PCW_COUNTERSET_BASE *pPVar3;
  PCW_COUNTERSET_BASE *pPVar4;
  
  _Var1 = param_1[8];
  pPVar4 = *(PCW_COUNTERSET_BASE **)param_1;
  if (((byte)param_1[8] & 1) != 0) {
    if (pPVar4 == (PCW_COUNTERSET_BASE *)0x0) {
      return (PCW_COUNTERSET_BASE *)0x0;
    }
    pPVar4 = (PCW_COUNTERSET_BASE *)((ulonglong)pPVar4 ^ (ulonglong)param_1);
  }
  do {
    if (pPVar4 == (PCW_COUNTERSET_BASE *)0x0) {
      return (PCW_COUNTERSET_BASE *)0x0;
    }
    iVar2 = PcwpRbNameCompareNoCase(param_2,(longlong)pPVar4);
    if (iVar2 < 0) {
      pPVar3 = *(PCW_COUNTERSET_BASE **)pPVar4;
    }
    else {
      if (iVar2 < 1) {
        return pPVar4;
      }
      pPVar3 = *(PCW_COUNTERSET_BASE **)(pPVar4 + 8);
    }
    if ((((byte)_Var1 & 1) == 0) || (pPVar3 == (PCW_COUNTERSET_BASE *)0x0)) {
      pPVar4 = pPVar3;
    }
    else {
      pPVar4 = (PCW_COUNTERSET_BASE *)((ulonglong)pPVar4 ^ (ulonglong)pPVar3);
    }
  } while( true );
}



===== FindOrCreate @ 14000ed40 =====

/* public: static long __cdecl PCW_SILO_NEUTRAL_COUNTERSET::FindOrCreate(class utl::unique_ptr<class
   PCW_SILO_NEUTRAL_COUNTERSET,struct ReleaseDeleter<class PCW_SILO_NEUTRAL_COUNTERSET> > *
   __ptr64,struct _UNICODE_STRING const * __ptr64) */

long __cdecl
PCW_SILO_NEUTRAL_COUNTERSET::FindOrCreate
          (unique_ptr<PCW_SILO_NEUTRAL_COUNTERSET,ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>_>
           *param_1,_UNICODE_STRING *param_2)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  void *pvVar3;
  long lVar4;
  PCW_COUNTERSET_BASE *pPVar5;
  undefined8 uVar6;
  void *_Dst;
  PCW_SILO_NEUTRAL_COUNTERSET *pPVar7;
  PCW_COUNTERSET_BASE *pPVar8;
  ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *this;
  PCW_COUNTERSET_BASE *this_00;
  ulonglong uVar9;
  void *local_res18;
  void *local_res20;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&DAT_140011468,0);
  pPVar5 = PCW_COUNTERSET_BASE::FindNode((_RTL_RB_TREE *)&DAT_140011470,param_2);
  if (pPVar5 != (PCW_COUNTERSET_BASE *)0x0) {
    LOCK();
    *(int *)(pPVar5 + 0x84) = *(int *)(pPVar5 + 0x84) + 1;
    UNLOCK();
  }
  this = (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)&DAT_140011468;
  ExReleasePushLockSharedEx(&DAT_140011468,0);
  KeLeaveCriticalRegion();
  if (pPVar5 == (PCW_COUNTERSET_BASE *)0x0) {
    uVar1 = *(ushort *)param_2;
    uVar9 = CONCAT62(0,uVar1 >> 1);
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar9;
    uVar6 = SUB168(ZEXT816(2) * auVar2,0);
    if (SUB168(ZEXT816(2) * auVar2,8) != 0) {
      uVar6 = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePool2(0x100,uVar6,0x43776350);
    if (_Dst == (void *)0x0) {
      return -0x3fffffe9;
    }
    memmove(_Dst,*(void **)(param_2 + 8),uVar9 * 2);
    local_res18 = (void *)0x0;
    lVar4 = PcwpReadSecurityDescriptor
                      ((unique_ptr<void,ObDereferenceSecurityDescriptorDeleter> *)&local_res18,
                       param_2);
    if (lVar4 < 0) {
      if ((lVar4 == -0x3fffffcc) && (lVar4 = PcwpInitDefaultSecurityDescriptor(), -1 < lVar4)) {
        ObReferenceSecurityDescriptor(PcwDefaultSecurityDescriptor,1);
        pvVar3 = local_res18;
        local_res18 = PcwDefaultSecurityDescriptor;
        if (pvVar3 != (void *)0x0) {
          ObDereferenceSecurityDescriptor(pvVar3,1);
        }
        goto LAB_14000eeba;
      }
      if (local_res18 != (void *)0x0) {
        ObDereferenceSecurityDescriptor(local_res18,1);
      }
    }
    else {
LAB_14000eeba:
      pPVar7 = (PCW_SILO_NEUTRAL_COUNTERSET *)ExAllocatePool2(0x100,0x90,0x43776350);
      if (pPVar7 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
        local_res20 = _Dst;
        pPVar5 = (PCW_COUNTERSET_BASE *)
                 PCW_SILO_NEUTRAL_COUNTERSET(pPVar7,&local_res20,(uVar1 >> 1) * 2,&local_res18);
        _Dst = (void *)0x0;
        if (pPVar5 != (PCW_COUNTERSET_BASE *)0x0) {
          if (local_res18 != (void *)0x0) {
            ObDereferenceSecurityDescriptor(local_res18,1);
          }
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(&DAT_140011468,0);
          pPVar8 = PCW_COUNTERSET_BASE::FindNode
                             ((_RTL_RB_TREE *)&DAT_140011470,(_UNICODE_STRING *)(pPVar5 + 0x18));
          if (pPVar8 == (PCW_COUNTERSET_BASE *)0x0) {
            PCW_COUNTERSET_BASE::InsertNode
                      ((_RTL_RB_TREE *)&DAT_140011470,(_UNICODE_STRING *)(pPVar5 + 0x18),pPVar5);
            this_00 = (PCW_COUNTERSET_BASE *)0x0;
          }
          else {
            LOCK();
            *(int *)(pPVar8 + 0x84) = *(int *)(pPVar8 + 0x84) + 1;
            UNLOCK();
            this_00 = pPVar5;
            pPVar5 = pPVar8;
          }
          this = (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)&DAT_140011468;
          ExReleasePushLockExclusiveEx(&DAT_140011468,0);
          KeLeaveCriticalRegion();
          if (this_00 != (PCW_COUNTERSET_BASE *)0x0) {
            ~PCW_SILO_NEUTRAL_COUNTERSET((PCW_SILO_NEUTRAL_COUNTERSET *)this_00);
            ExFreePoolWithTag(this_00,0);
            this = (ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET> *)this_00;
          }
          pPVar7 = *(PCW_SILO_NEUTRAL_COUNTERSET **)param_1;
          *(PCW_COUNTERSET_BASE **)param_1 = pPVar5;
          goto LAB_14000edc8;
        }
      }
      lVar4 = -0x3fffffe9;
      if (local_res18 != (void *)0x0) {
        ObDereferenceSecurityDescriptor(local_res18,1);
      }
      if (_Dst == (void *)0x0) {
        return -0x3fffffe9;
      }
    }
    ExFreePoolWithTag(_Dst,0);
  }
  else {
    pPVar7 = *(PCW_SILO_NEUTRAL_COUNTERSET **)param_1;
    *(PCW_COUNTERSET_BASE **)param_1 = pPVar5;
LAB_14000edc8:
    if (pPVar7 != (PCW_SILO_NEUTRAL_COUNTERSET *)0x0) {
      ReleaseDeleter<PCW_SILO_NEUTRAL_COUNTERSET>::operator()(this,pPVar7);
    }
    lVar4 = 0;
  }
  return lVar4;
}



===== InsertNode @ 14000f018 =====

/* protected: static void __cdecl PCW_COUNTERSET_BASE::InsertNode(struct _RTL_RB_TREE *
   __ptr64,struct _UNICODE_STRING const * __ptr64,class PCW_COUNTERSET_BASE * __ptr64) */

void __cdecl
PCW_COUNTERSET_BASE::InsertNode
          (_RTL_RB_TREE *param_1,_UNICODE_STRING *param_2,PCW_COUNTERSET_BASE *param_3)

{
  _RTL_RB_TREE _Var1;
  int iVar2;
  ulonglong *puVar3;
  undefined1 uVar4;
  ulonglong *puVar5;
  
  _Var1 = param_1[8];
  uVar4 = 0;
  puVar5 = *(ulonglong **)param_1;
  if (((byte)param_1[8] & 1) != 0) {
    if (puVar5 == (ulonglong *)0x0) goto LAB_14000f07e;
    puVar5 = (ulonglong *)((ulonglong)puVar5 ^ (ulonglong)param_1);
  }
  if (puVar5 != (ulonglong *)0x0) {
    do {
      iVar2 = PcwpRbNameCompareNoCase(param_2,(longlong)puVar5);
      if (iVar2 < 0) {
        puVar3 = (ulonglong *)*puVar5;
        if (((byte)_Var1 & 1) != 0) {
          if (puVar3 == (ulonglong *)0x0) break;
          puVar3 = (ulonglong *)((ulonglong)puVar3 ^ (ulonglong)puVar5);
        }
        if (puVar3 == (ulonglong *)0x0) break;
      }
      else {
        puVar3 = (ulonglong *)puVar5[1];
        if (((byte)_Var1 & 1) != 0) {
          if (puVar3 == (ulonglong *)0x0) goto LAB_14000f07c;
          puVar3 = (ulonglong *)((ulonglong)puVar3 ^ (ulonglong)puVar5);
        }
        if (puVar3 == (ulonglong *)0x0) goto LAB_14000f07c;
      }
      puVar5 = puVar3;
    } while( true );
  }
  goto LAB_14000f07e;
LAB_14000f07c:
  uVar4 = 1;
LAB_14000f07e:
  RtlRbInsertNodeEx(param_1,puVar5,uVar4,param_3);
  return;
}



===== PcwpRbNameCompareNoCase @ 14000f0d0 =====

void PcwpRbNameCompareNoCase(undefined8 param_1,longlong param_2)

{
  RtlCompareUnicodeString(param_1,param_2 + 0x18,1);
  return;
}



===== WdmlibIoCreateDeviceSecure @ 14000f0f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000048;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (WdmlibInitialized == '\0') {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
    PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
    if (PfnIoCreateDeviceSecure == (code *)0x0) {
      PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
    }
    RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
    MmGetSystemRoutineAddress(&local_18);
    WdmlibInitialized = '\x01';
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,0,param_3,0x22,0x100,0,&SDDL_DEVOBJ_SYS_ALL_ADM_RWX_WORLD_R_PCW_RW,0,
             in_stack_00000048);
  return;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 14000f1e0 =====

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          uVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return uVar1;
}



===== IoDevObjCreateDeviceSecure @ 14000f2e0 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,undefined4 *param_8,
                    undefined8 *param_9)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res18;
  undefined4 local_res20;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar2 = param_9;
  local_res18 = 0;
  local_58 = 0;
  *param_9 = 0;
  param_9 = (undefined8 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  uVar5 = param_2;
  local_res20 = param_4;
  if ((param_8 != (undefined4 *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_14000f440;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_14000f440;
    }
  }
  uVar1 = local_res20;
  if ((uVar6 & 1) != 0) {
    uVar1 = local_68._4_4_;
  }
  if ((uVar6 & 4) != 0) {
    param_5 = (undefined4)local_58;
  }
  if ((uVar6 & 8) != 0) {
    param_6 = local_58._4_1_;
  }
  uVar3 = IoCreateDevice(param_1,param_2 & 0xffffffff,param_3,uVar1,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar5 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_68);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar2 = param_9;
    }
  }
LAB_14000f440:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 14000f474 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      uVar3 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar1 = uVar3 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar1 = uVar3;
      }
      uVar3 = uVar1 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar3 = uVar1;
      }
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,uVar3,*(undefined8 *)IoDeviceObjectType_exref,0,
                         &local_res20);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_res20,local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_res20);
      }
    }
  }
  return uVar2;
}



===== SeSddlSecurityDescriptorFromSDDL @ 14000f564 =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  short *_Dst;
  void *_Src;
  
  uVar2 = (ulonglong)*param_1 + 2;
  if (param_1[1] == uVar2) {
    uVar1 = *param_1 >> 1;
    if ((*(short **)(param_1 + 4))[uVar1] == 0) {
      uVar2 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),(uint)uVar1,param_3);
      return uVar2;
    }
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar2,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    _Src = *(void **)(param_1 + 4);
    memmove(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 14000f644 =====

undefined8
SepSddlAddAceToAcl(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  pvVar2 = (void *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = pvVar2;
  if (*(ushort *)((longlong)pvVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)uVar5);
    memmove(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 14000f744 =====

int SepSddlDaclFromSDDLString
              (short *param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  undefined4 uVar4;
  longlong local_res8;
  short *local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = (short *)0x0;
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != 0x50) {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != 0x50) {
    lVar2 = 2;
  }
  iVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18[0]; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
    }
    if (*psVar3 == 0) {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



===== SepSddlGetAclForString @ 14000f830 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  bool bVar1;
  bool bVar2;
  wchar_t wVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  uint uVar16;
  undefined **ppuVar17;
  short *local_res8;
  uint local_res10;
  uint local_res18;
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_50[0] = 0;
  iVar5 = 0;
  uVar16 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_1[lVar7] != L'\0');
    pwVar6 = param_1 + lVar7;
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = pwVar6;
  bVar2 = false;
  bVar1 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar16 = uVar16 + 1;
    }
    else {
      bVar1 = bVar2;
      if (*pwVar10 != L' ') {
        bVar2 = true;
        bVar1 = true;
      }
    }
  }
  local_res18 = uVar16 / 5;
  if ((uVar16 != local_res18 * 5) || ((uVar16 == 0 && (bVar1)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (local_res18 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar16 = local_res18 * 0x30 + 8;
      if (0xffff < uVar16) {
        uVar16 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar16,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar16);
        *_Dst = 2;
        _Dst[1] = (short)uVar16;
        *(undefined4 *)(_Dst + 2) = 0;
        local_res10 = 0;
        uVar16 = local_res18;
        uVar15 = 8;
        if (local_res18 != 0) {
          do {
            uVar15 = 0;
            local_res8 = (short *)((ulonglong)local_res8 & 0xffffffff00000000);
            for (; *param_1 == L' '; param_1 = param_1 + 1) {
            }
            if (*param_1 == L'(') {
              do {
                param_1 = param_1 + 1;
              } while (*param_1 == L' ');
            }
            iVar4 = _wcsnicmp(param_1,L"A",1);
            if (iVar4 != 0) {
LAB_14000fbcb:
              iVar5 = -0x3ffffff3;
LAB_14000fbcd:
              lVar7 = *param_2;
              goto LAB_14000fbb3;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_14000fbcb;
            do {
              pwVar6 = pwVar6 + 1;
              wVar3 = *pwVar6;
            } while (wVar3 == L' ');
            if (wVar3 != L';') {
              do {
                uVar11 = 0;
                while (wVar3 == L' ') {
                  pwVar6 = pwVar6 + 1;
                  wVar3 = *pwVar6;
                }
                ppuVar17 = &PTR_u_RC_140011160;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 | *(uint *)(&DAT_14001116c + uVar11 * 0x10);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + (uint)(&DAT_140011168)[uVar11 * 4];
                    goto LAB_14000fabd;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_14000fbcb;
                uVar15 = (uint)local_res8;
LAB_14000fabd:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_14000fbcd;
            lVar7 = 2;
            do {
              for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
              }
              if (*pwVar6 != L';') {
                iVar5 = -0x3ffffff3;
              }
              pwVar6 = pwVar6 + 1;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            if (iVar5 != 0) goto LAB_14000fbcd;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_14000fb3b:
              iVar5 = -0x3fffff89;
              goto LAB_14000fbcd;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_14000fb3b;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_14000fbcd;
            }
            if (*param_1 == L'(') {
              param_1 = psVar12 + 2;
            }
            local_res10 = local_res10 + 1;
          } while (local_res10 < uVar16);
          uVar15 = local_res20[0];
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(short *)(lVar7 + 2) = (short)uVar15;
          return 0;
        }
LAB_14000fbb3:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 14000fbf8 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  puVar5 = &DAT_140011234;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_14001122c + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_140011228 + uVar7 * 0x18);
      uVar6 = (&DAT_140011234)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_14000fc8f;
      }
      else {
LAB_14000fc8f:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_140011220 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_14000fca4;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_14000fca4:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 14000fccc =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  uVar1 = *param_1;
  uVar6 = (uint)uVar1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_14000fd4f:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_14000fd2d;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_14000fd4f;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_14000fd2d:
  do {
    sVar5 = (short)uVar6;
    if ((ushort)(sVar5 - 0x30U) < 10) {
      iVar2 = uVar6 - 0x30;
    }
    else {
      if (iVar7 != 0x10) break;
      if ((ushort)(sVar5 - 0x41U) < 6) {
        iVar2 = uVar6 - 0x37;
      }
      else {
        if (5 < (ushort)(sVar5 - 0x61U)) break;
        iVar2 = uVar6 - 0x57;
      }
    }
    uVar3 = iVar7 * uVar4 + iVar2;
    if (uVar3 < uVar4) {
      return 0;
    }
    param_1 = param_1 + 1;
    uVar6 = (uint)*param_1;
    uVar4 = uVar3;
  } while (*param_1 != 0);
  if (param_1 == puVar8) {
    return 0;
  }
  *param_2 = param_1;
  *param_3 = uVar4;
  return 1;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 14000fdd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,uint param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t *pwVar5;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  longlong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  pwVar5 = L"SeConvertStringSecurityDescriptorToSecurityDescriptor";
  local_58[1] = 0;
  local_58[2] = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_58 + 1);
  pcVar3 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
  if (pcVar3 != (code *)0x0) {
    uVar4 = (*pcVar3)(param_1,1,param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar4;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  _Dst = (void *)0x0;
  *param_3 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = SepSddlDaclFromSDDLString(param_1,pwVar5,local_res20,local_58);
  if (-1 < (int)uVar2) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58[0],0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res10[0]);
      uVar2 = RtlAbsoluteToSelfRelativeSD(&local_40,_Dst,local_res10);
      if (-1 < (int)uVar2) {
        ExFreePoolWithTag(local_58[0],0);
        *param_3 = (longlong)_Dst;
        goto LAB_14000ff1d;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_14000ff1d:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 14000ff7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (undefined4 *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x140003780,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar5 = *param_1;
    pwVar4 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar5 = 2;
    }
    else {
      uVar3 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar4,uVar5,0,&local_b8,local_a8);
      uVar2 = (uint)uVar3;
      uVar5 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar5;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 140010118 =====

ulonglong PiRegStateReadStackCreationSettingsFromKey
                    (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58;
  ushort local_50 [12];
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x140003700);
  uVar1 = (uint)uVar2;
  lVar4 = 0;
  if (((int)uVar1 < 0) ||
     (uVar1 = CmRegUtilUcValueGetFullBuffer(param_1,local_50,param_3,param_4,&local_58),
     lVar4 = local_58, (int)uVar1 < 0)) {
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000034) {
      uVar5 = 0;
    }
  }
  else {
    param_3 = (uint *)0x1;
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_58 + 8) + local_58,0,1,1,&local_res20);
    uVar5 = (ulonglong)uVar1;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (-1 < (int)uVar5) {
    if (local_res20 != 0) {
      param_3 = local_res18;
      uVar3 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_140010297;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140003718,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_140010297;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140003730,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_140010297;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140003760,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_140010297:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar5;
}



===== PpRegStateReadCreateClassCreationSettings @ 1400102dc =====

ulonglong PpRegStateReadCreateClassCreationSettings
                    (undefined4 *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,param_2,1,local_res18,&local_res20);
  uVar4 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    puVar6 = &local_18;
    puVar5 = (uint *)0x20019;
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1400036a0,0x20019,puVar6);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18,param_3,puVar5,puVar6);
    uVar2 = uVar2 & 0xffffffff;
    uVar4 = local_18;
  }
  else {
    puVar7 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar7 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1400036b8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400036c8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400036e8,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 140010440 =====

ulonglong PpRegStateUpdateStackCreationSettings(undefined4 *param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  short local_30 [12];
  
  uVar8 = 0;
  local_res18 = (undefined *)0x0;
  uVar7 = 0;
  local_38 = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,param_2,0,(undefined4 *)0x0,&local_res20);
  uVar2 = (undefined4)uVar8;
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar2 = (undefined4)uVar8;
      uVar7 = 1;
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar8,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar6 = (undefined *)0x0;
    }
    local_res18 = puVar6;
    uVar5 = CmRegUtilCreateWstrKey
                      (local_res20,0x1400036a0,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = uVar5 & 0xffffffff;
    ZwClose(local_res20);
    if (-1 < (int)uVar5) {
      uVar2 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x140003700);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar3 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar2);
        uVar4 = (ulonglong)uVar3;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== CmRegUtilCreateWstrKey @ 1400105a8 =====

ulonglong CmRegUtilCreateWstrKey
                    (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res20 [2];
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_res20[0] = param_4;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_res20[0] = 0;
    local_58 = 0;
    local_18 = 0;
    local_20 = param_5;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    uVar1 = ZwCreateKey(&local_58,0xf003f,&local_40,0,0,0,local_res20);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      local_58 = 0;
      local_res20[0] = 0;
    }
    *param_7 = local_58;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_res20[0];
    }
  }
  return uVar2;
}



===== CmRegUtilOpenExistingWstrKey @ 140010678 =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar3 = (ulonglong)param_3;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_58 = 0;
    *param_4 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    iVar1 = ZwOpenKey(&local_58,uVar3 & 0xffffffff,&local_40);
    if (-1 < iVar1) {
      *param_4 = local_58;
    }
  }
  return;
}



===== CmRegUtilUcValueGetFullBuffer @ 14001070c =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = *param_2 + 0x1f & 0xfffffff8;
  *param_5 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar2);
  iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar2,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_140010844;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_140010844:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 140010888 =====

undefined4 CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  size_t _Size;
  ushort uVar1;
  undefined4 uVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar1 = *param_3;
  local_24 = 0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    _Size = (ulonglong)uVar1 + 2;
    local_26 = uVar1 + 2;
    local_20 = (void *)ExAllocatePoolWithTag(1,_Size,0x63557050);
    if (local_20 == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(local_20,0,_Size);
      local_28 = *param_3;
      memmove(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
      *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



===== CmRegUtilWstrValueGetDword @ 1400109d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilWstrValueGetDword
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  short local_30 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_30,param_2);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    uVar1 = ZwQueryValueKey(param_1,local_30,2,local_20);
    if (-1 < (int)uVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        uVar1 = 0xc0000024;
      }
    }
    *param_4 = uVar2;
  }
  return uVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 140010a78 =====

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,param_2);
    if (-1 < (int)uVar1) {
      CmRegUtilUcValueSetUcString(param_1,&local_18,local_28);
    }
  }
  return;
}



===== entry @ 140012010 =====

void entry(_DRIVER_OBJECT *param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140012044 =====

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



===== PcwInitialize @ 140012078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl PcwInitialize(struct _DRIVER_OBJECT * __ptr64) */

long __cdecl PcwInitialize(_DRIVER_OBJECT *param_1)

{
  uint uVar1;
  undefined8 ******ppppppuVar2;
  undefined4 uVar3;
  undefined1 auStack_108 [32];
  undefined8 ******local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined **local_d8;
  undefined8 local_d0;
  _DRIVER_OBJECT *local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined2 local_a8;
  byte local_a6;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 local_84;
  undefined4 local_80;
  code *local_70;
  code *local_68;
  code *local_60;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_108;
  local_e8 = (undefined8 ******)0x0;
  local_c0 = 0;
  uStack_b8 = 0;
  memset(&local_a8,0,0x78);
  local_e0 = 0x10001;
  local_d8 = &PcwpCallbackTable;
  local_dc = 0x50000;
  ppppppuVar2 = &local_e8;
  local_d0 = 0;
  local_c8 = param_1;
  uVar1 = ExRegisterExtension(ppppppuVar2,0x10001,&local_e0);
  if ((int)uVar1 < 0) {
    if (((byte)Microsoft_Windows_Diagnosis_PCWEnableBits & 1) == 0) {
      return uVar1;
    }
    uVar3 = 3;
  }
  else {
    local_a6 = local_a6 | 6;
    local_70 = PcwpOpenObject;
    local_a8 = 0x78;
    local_60 = PcwpDeleteObject;
    local_a0 = 0x132;
    local_68 = PcwpCloseObjectHandle;
    local_9c = 1;
    uStack_98 = 2;
    uStack_94 = 0;
    uStack_90 = 0xf0003;
    local_8c = 0xf0003;
    local_84 = 1;
    local_80 = 0x38;
    RtlInitUnicodeString(&local_c0,L"PcwObject");
    uVar1 = ObCreateObjectType(&local_c0,&local_a8,0,&PcwObjectType);
    if (-1 < (int)uVar1) {
      return 0;
    }
    ppppppuVar2 = local_e8;
    ExUnregisterExtension();
    if (((byte)Microsoft_Windows_Diagnosis_PCWEnableBits & 1) == 0) {
      return uVar1;
    }
    uVar3 = 4;
  }
  McTemplateU0qq_EtwWriteTransfer(ppppppuVar2,&DriverLoadFail,(ulonglong)uVar1,uVar3);
  return uVar1;
}



===== DriverEntry @ 14001220c =====

uint DriverEntry(_DRIVER_OBJECT *param_1,undefined8 param_2)

{
  uint uVar1;
  _UNICODE_STRING *p_Var2;
  _DRIVER_OBJECT *p_Var3;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_10 = L"\\Device\\PcwDrv";
  local_18 = 0x1e001c;
  McGenEventRegister_EtwRegister();
  wil_InitializeFeatureStaging();
  *(_FAST_IO_DISPATCH **)(param_1 + 0x50) = &PcwpFastIoDispatchTable;
  p_Var2 = (_UNICODE_STRING *)&local_18;
  *(code **)(param_1 + 0x70) = PcwpDispatchCreate;
  uVar1 = PCW_SILO_CONTEXT::RegisterForSiloNotifications(p_Var2);
  if ((int)uVar1 < 0) {
    if (((byte)Microsoft_Windows_Diagnosis_PCWEnableBits & 1) != 0) {
      McTemplateU0qq_EtwWriteTransfer(p_Var2,&DriverLoadFail,(ulonglong)uVar1,0);
    }
  }
  else {
    p_Var3 = param_1;
    uVar1 = WdmlibIoCreateDeviceSecure(param_1,param_2,&local_18);
    if ((int)uVar1 < 0) {
      if (((byte)Microsoft_Windows_Diagnosis_PCWEnableBits & 1) != 0) {
        McTemplateU0qq_EtwWriteTransfer(p_Var3,&DriverLoadFail,(ulonglong)uVar1,1);
      }
    }
    else {
      uVar1 = PcwInitialize(param_1);
      if (-1 < (int)uVar1) {
        uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f;
        return 0;
      }
      IoDeleteDevice(0);
    }
    PCW_SILO_CONTEXT::UnregisterForSiloNotifications();
  }
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
  return uVar1;
}



===== wil_InitializeFeatureStaging @ 140012354 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
        plVar3 = plVar3 + 1) {
      if (*plVar3 != 0) goto LAB_1400123db;
    }
LAB_140012415:
    _g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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
LAB_1400123db:
  if (plVar3 == (longlong *)0x0) goto LAB_140012415;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_140012415;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_1400046f7 < plVar3) goto LAB_140012415;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1400123db;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140012468 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  plVar4 = &wil_details_featureDescriptors_a;
  while( true ) {
    if (&wil_details_featureDescriptors_a <= plVar4) {
      return;
    }
    if (*plVar4 != 0) break;
    plVar4 = plVar4 + 1;
  }
  do {
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)plVar4 + 0x1d) == '\0') && (*(char *)((longlong)plVar4 + 0x1e) == '\0')
       ) {
      iVar3 = RtlQueryFeatureConfiguration
                        ((int)plVar4[3],1 < (byte)(*(char *)((longlong)plVar4 + 0x1c) - 2U),
                         &local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*plVar4;
          plVar4 = plVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_1400046f7 < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140012552;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140012552;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140012552:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400046f7 < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}


