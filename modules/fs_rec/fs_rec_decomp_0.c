
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



===== __GSHandlerCheck @ 1c0001020 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0001044 =====

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



===== __cpu_features_init @ 1c00010c0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000112a) */
/* WARNING: Removing unreachable block (ram,0x0001c00010d9) */
/* WARNING: Removing unreachable block (ram,0x0001c00010ca) */

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



===== _guard_check_icall @ 1c0001190 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 1c00011b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00011f0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00011f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001220 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c0001260 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c00012a3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c0001314;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c0001310:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0001314;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c000130c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0001310;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c000130c;
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
LAB_1c0001314:
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
LAB_1c00012a3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c0001380 =====

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



===== memset @ 1c0001680 =====

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



===== __memset_repmovs @ 1c00017c0 =====

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



===== __memset_query @ 1c0001840 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00018c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0001a00 =====

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



===== __memset_spec_plain @ 1c0001a80 =====

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



===== FsRecLoadFileSystem @ 1c0008010 =====

int FsRecLoadFileSystem(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong *plVar6;
  int iVar7;
  undefined8 local_38;
  longlong lStack_30;
  
  plVar6 = *(longlong **)(param_1 + 0x40);
  local_38 = 0;
  lStack_30 = 0;
  iVar2 = -0x3ffffef2;
  if (*(int *)((longlong)plVar6 + 0xc) != 1) {
    KeEnterCriticalRegion();
    iVar7 = 0;
    KeWaitForSingleObject(FsRecLoadSync,0,0,0,0);
    iVar2 = -0x3ffffef2;
    if (*(int *)((longlong)plVar6 + 0xc) == 0) {
      RtlInitUnicodeString(&local_38,param_2);
      iVar2 = ZwLoadDriver(&local_38);
      if (iVar2 < 0) {
        uVar4 = LoadDriverStatusLog & 7;
        uVar3 = (uint)(ushort)local_38;
        if (0x10 < uVar3) {
          iVar7 = (ushort)local_38 - 0x10;
        }
        uVar5 = 0x10;
        if (uVar3 < 0x11) {
          uVar5 = uVar3;
        }
        lVar1 = (ulonglong)uVar4 * 0x14;
        LoadDriverStatusLog = LoadDriverStatusLog + 1;
        *(int *)(&DAT_1c0005164 + lVar1) = iVar2;
        memcpy(&DAT_1c0005168 + lVar1,(void *)(lStack_30 + (longlong)(iVar7 / 2) * 2),
               (ulonglong)uVar5);
        memset((void *)((longlong)&LoadDriverStatusLog +
                       ((ulonglong)(uVar5 >> 1) + (ulonglong)uVar4 * 10 + 4) * 2),0,
               0x10 - (ulonglong)uVar5);
      }
      if (((int)plVar6[1] != 7) || (iVar2 != -0x3fffffc6)) {
        iVar7 = *(int *)((longlong)plVar6 + 0xc);
        while (iVar7 != 2) {
          param_1 = *plVar6;
          *(undefined4 *)((longlong)plVar6 + 0xc) = 2;
          plVar6 = *(longlong **)(param_1 + 0x40);
          iVar7 = *(int *)((longlong)plVar6 + 0xc);
        }
      }
    }
    if (((int)plVar6[1] != 7) || (iVar2 != -0x3fffffc6)) {
      iVar7 = *(int *)((longlong)plVar6 + 0xc);
      while (iVar7 != 1) {
        IoUnregisterFileSystem(param_1);
        param_1 = *plVar6;
        *(undefined4 *)((longlong)plVar6 + 0xc) = 1;
        plVar6 = *(longlong **)(param_1 + 0x40);
        iVar7 = *(int *)((longlong)plVar6 + 0xc);
      }
    }
    KeSetEvent(FsRecLoadSync,0,0);
    KeLeaveCriticalRegion();
  }
  return iVar2;
}



===== FsRecCleanupClose @ 1c0008210 =====

undefined8 FsRecCleanupClose(undefined8 param_1,undefined8 param_2)

{
  IofCompleteRequest(param_2,0);
  return 0;
}



===== FsRecCreate @ 1c0008240 =====

uint FsRecCreate(undefined8 param_1,longlong param_2)

{
  short sVar1;
  uint uVar2;
  
  sVar1 = *(short *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x58);
  *(undefined8 *)(param_2 + 0x38) = 1;
  uVar2 = -(uint)(sVar1 != 0) & 0xc000003a;
  *(uint *)(param_2 + 0x30) = uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== FsRecUnload @ 1c0008290 =====

void FsRecUnload(void)

{
  ExFreePoolWithTag(FsRecLoadSync,0);
  return;
}



===== UdfsReadTrackInfo @ 1c00082b8 =====

void UdfsReadTrackInfo(undefined8 param_1,undefined1 param_2,void *param_3)

{
  uint local_res20 [2];
  byte local_18 [6];
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  undefined7 uStack_f;
  
  local_res20[0] = 0x100;
  uStack_12 = 0;
  uStack_f = 0;
  local_18[0] = 0x52;
  uStack_11 = 1;
  uStack_10 = 0;
  local_18[1] = 1;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = param_2;
  UdfsRecSendSptCdb(param_1,local_18,param_3,local_res20);
  return;
}



===== IsFatVolume @ 1c0008308 =====

undefined8 IsFatVolume(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  byte bVar6;
  int iVar7;
  undefined1 uStack0000000000000000;
  
  cVar1 = *param_1;
  uVar5 = CONCAT71((int7)((ulonglong)&uStack0000000000000000 >> 8),cVar1);
  sVar2 = *(short *)(param_1 + 0xb);
  iVar7 = 0;
  if (*(short *)(param_1 + 0x13) == 0) {
    iVar7 = *(int *)(param_1 + 0x20);
  }
  bVar6 = 1;
  if ((((cVar1 == 'I') || (cVar1 == -0x17)) || (cVar1 == -0x15)) &&
     ((((sVar2 == 0x80 || (uVar5 = 0x100, sVar2 == 0x100)) ||
       ((uVar5 = 0x200, sVar2 == 0x200 ||
        ((uVar5 = 0x400, sVar2 == 0x400 || (uVar5 = 0x800, sVar2 == 0x800)))))) ||
      (uVar5 = 0x1000, sVar2 == 0x1000)))) {
    bVar3 = param_1[0xd] - 1;
    uVar5 = CONCAT71((int7)(uVar5 >> 8),bVar3);
    if (((((bVar3 < 0x40) && ((0x800000008000808bU >> ((ulonglong)bVar3 & 0x3f) & 1) != 0)) ||
         (param_1[0xd] == -0x80)) && ((*(short *)(param_1 + 0xe) != 0 && (param_1[0x10] != '\0'))))
       && ((*(short *)(param_1 + 0x13) != 0 || (iVar7 != 0)))) {
      uVar4 = (int)CONCAT71((int7)((ulonglong)param_4 >> 8),param_1[0x15]) - 2;
      uVar5 = (ulonglong)uVar4;
      if ((0xed < (byte)uVar4) && (6 < (byte)(param_1[0x15] + 0xfU))) {
        if (*(short *)(param_1 + 0x16) != 0) {
          uVar5 = (ulonglong)CONCAT31((int3)(uVar4 >> 8),-(*(short *)(param_1 + 0x11) != 0));
          bVar6 = -(*(short *)(param_1 + 0x11) != 0) & 1;
        }
        goto LAB_1c00083fe;
      }
    }
  }
  bVar6 = 0;
LAB_1c00083fe:
  return CONCAT71((int7)(uVar5 >> 8),bVar6);
}



===== IsNtfsVolume @ 1c0008424 =====

ulonglong IsNtfsVolume(longlong param_1,uint param_2,longlong *param_3)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  ulonglong in_RAX;
  undefined7 uVar4;
  longlong lVar5;
  
  if ((((((*(char *)(param_1 + 3) == 'N') && (*(char *)(param_1 + 4) == 'T')) &&
        (*(char *)(param_1 + 5) == 'F')) &&
       ((*(char *)(param_1 + 6) == 'S' &&
        (in_RAX = CONCAT71((int7)(in_RAX >> 8),0x20), *(char *)(param_1 + 7) == ' ')))) &&
      (*(char *)(param_1 + 8) == ' ')) &&
     (((*(char *)(param_1 + 9) == ' ' && (*(char *)(param_1 + 10) == ' ')) &&
      (*(char *)(param_1 + 0xb) == '\0')))) {
    in_RAX = (ulonglong)*(byte *)(param_1 + 0xc) << 8;
    if (((uint)in_RAX == param_2) && ((uint)in_RAX < 0x1001)) {
      bVar2 = *(byte *)(param_1 + 0xd);
      in_RAX = (ulonglong)(bVar2 - 1);
      if (((((((byte)(bVar2 - 1) < 0x40) && ((0x800000008000808bU >> (in_RAX & 0x3f) & 1) != 0)) ||
            (bVar2 == 0x80)) &&
           (((((*(char *)(param_1 + 0xe) == '\0' && (*(char *)(param_1 + 0xf) == '\0')) &&
              (*(char *)(param_1 + 0x10) == '\0')) &&
             ((*(char *)(param_1 + 0x11) == '\0' && (*(char *)(param_1 + 0x12) == '\0')))) &&
            ((*(char *)(param_1 + 0x13) == '\0' &&
             ((*(char *)(param_1 + 0x14) == '\0' && (*(char *)(param_1 + 0x16) == '\0')))))))) &&
          ((*(char *)(param_1 + 0x17) == '\0' &&
           (((*(char *)(param_1 + 0x20) == '\0' && (*(char *)(param_1 + 0x21) == '\0')) &&
            (*(char *)(param_1 + 0x22) == '\0')))))) &&
         (((*(char *)(param_1 + 0x23) == '\0' &&
           (lVar1 = *param_3, *(longlong *)(param_1 + 0x28) <= lVar1)) &&
          ((in_RAX = (ulonglong)bVar2 * *(longlong *)(param_1 + 0x30), (longlong)in_RAX <= lVar1 &&
           (lVar5 = (ulonglong)bVar2 * *(longlong *)(param_1 + 0x38), lVar5 <= lVar1)))))) {
        uVar3 = (int)CONCAT71((int7)((ulonglong)lVar5 >> 8),*(char *)(param_1 + 0x40)) + 0x1f;
        in_RAX = (ulonglong)uVar3;
        bVar2 = (byte)uVar3;
        if (((bVar2 < 0x40) &&
            (in_RAX = (ulonglong)(char)bVar2, (0x8000808b007fffffU >> (in_RAX & 0x3f) & 1) != 0)) ||
           (*(char *)(param_1 + 0x40) == '@')) {
          bVar2 = *(char *)(param_1 + 0x44) + 0x1f;
          uVar4 = (undefined7)(in_RAX >> 8);
          if ((bVar2 < 0x40) && ((0x8000808b007fffffU >> ((longlong)(char)bVar2 & 0x3fU) & 1) != 0))
          {
            return CONCAT71(uVar4,1);
          }
          return CONCAT71(uVar4,*(char *)(param_1 + 0x44) == '@');
        }
      }
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== NtfsRecFsControl @ 1c00085a0 =====

int NtfsRecFsControl(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint local_res8 [2];
  longlong local_res10;
  ulonglong local_res18;
  longlong local_res20;
  longlong local_48 [3];
  
  local_48[1] = 0;
  local_res20 = 0;
  local_48[0] = 0;
  local_res8[0] = 0;
  local_res18 = 0;
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar1 == '\x01') {
    lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    iVar4 = FsRecGetDeviceSectorSize(lVar2,local_res8,&local_res18);
    uVar3 = local_res8[0];
    if (-1 < iVar4) {
      local_res10 = 0;
      iVar4 = -0x3ffffeb1;
      local_res20 = ((longlong)local_res18 >> 1) * (longlong)(int)local_res8[0];
      local_48[0] = (local_res18 - 1) * (longlong)(int)local_res8[0];
      uVar5 = FsRecReadBlock(lVar2,local_48 + 1,0x200,local_res8[0],&local_res10,(undefined1 *)0x0);
      lVar7 = local_res10;
      if ((char)uVar5 == '\0') {
        uVar5 = FsRecReadBlock(lVar2,&local_res20,0x200,uVar3,&local_res10,(undefined1 *)0x0);
        lVar7 = local_res10;
        if (((char)uVar5 == '\0') ||
           (uVar6 = IsNtfsVolume(local_res10,uVar3,(longlong *)&local_res18), (char)uVar6 == '\0'))
        {
          uVar5 = FsRecReadBlock(lVar2,local_48,0x200,uVar3,&local_res10,(undefined1 *)0x0);
          lVar7 = local_res10;
          if ((char)uVar5 != '\0') {
            uVar6 = IsNtfsVolume(local_res10,uVar3,(longlong *)&local_res18);
            iVar4 = -0x3ffffeb1;
            if ((char)uVar6 != '\0') {
              iVar4 = -0x3ffffe64;
            }
          }
        }
        else {
          iVar4 = -0x3ffffe64;
        }
      }
      else {
        uVar6 = IsNtfsVolume(local_res10,uVar3,(longlong *)&local_res18);
        iVar4 = (-(uint)((char)uVar6 != '\0') & 0x4d) + 0xc000014f;
      }
      if (lVar7 != 0) {
        ExFreePoolWithTag(lVar7,0);
      }
    }
  }
  else if (cVar1 == '\x03') {
    iVar4 = FsRecLoadFileSystem(param_1,
                                L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Ntfs");
  }
  else {
    iVar4 = -0x3ffffff0;
  }
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== FsRecFsControl @ 1c0008760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FsRecFsControl(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  short *psVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  char *pcVar9;
  longlong lVar10;
  undefined8 uVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  undefined1 auStack_118 [32];
  undefined8 *local_f8;
  undefined8 *local_f0;
  undefined8 *local_e8;
  undefined8 *local_e0;
  undefined8 *local_d8;
  uint local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_118;
  iVar5 = *(int *)(*(longlong *)(param_1 + 0x40) + 0xc);
  if ((iVar5 != 0) && (*(char *)(*(longlong *)(param_2 + 0xb8) + 1) == '\x01')) {
    iVar12 = -0x3ffffeb1;
    if (iVar5 != 1) {
      iVar12 = -0x3ffffe64;
    }
    *(int *)(param_2 + 0x30) = iVar12;
    IofCompleteRequest(param_2,0);
    return iVar12;
  }
  iVar5 = *(int *)(*(longlong *)(param_1 + 0x40) + 8);
  if (iVar5 == 5) {
    cVar2 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
    if (cVar2 == '\x01') {
      psVar3 = *(short **)(*(longlong *)(param_2 + 0xb8) + 0x10);
      local_50 = 0;
      local_60 = 0;
      uStack_58 = 0;
      local_c0 = 0;
      local_90 = 0;
      uStack_88 = 0;
      local_80 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      KeInitializeEvent(&local_90,1,0);
      local_d8 = &local_a8;
      local_e0 = &local_90;
      local_e8 = (undefined8 *)((ulonglong)local_e8 & 0xffffffffffffff00);
      local_f8 = &local_c0;
      local_f0 = (undefined8 *)CONCAT44(local_f0._4_4_,8);
      lVar7 = IoBuildDeviceIoControlRequest(0x7405c,psVar3,0,0);
      if (lVar7 != 0) {
        pbVar1 = (byte *)(*(longlong *)(lVar7 + 0xb8) + -0x46);
        *pbVar1 = *pbVar1 | 2;
        iVar5 = IofCallDriver(psVar3,lVar7);
        if (iVar5 == 0x103) {
          local_f8 = (undefined8 *)0x0;
          KeWaitForSingleObject(&local_90,0,0,0);
        }
      }
      if (*(int *)(psVar3 + 0x24) == 2) {
        uVar11 = 0x2404c;
      }
      else {
        if (*(int *)(psVar3 + 0x24) != 7) goto LAB_1c0008c3e;
        uVar11 = 0x70000;
      }
      local_68 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_b8 = 0;
      uStack_b0 = 0;
      KeInitializeEvent(&local_78,1,0);
      local_d8 = &local_b8;
      local_e0 = &local_78;
      local_e8 = (undefined8 *)((ulonglong)local_e8 & 0xffffffffffffff00);
      local_f8 = &local_60;
      local_f0 = (undefined8 *)CONCAT44(local_f0._4_4_,0x18);
      lVar7 = IoBuildDeviceIoControlRequest(uVar11,psVar3,0,0);
      if (lVar7 == 0) {
        iVar5 = -0x3fffff66;
      }
      else {
        pbVar1 = (byte *)(*(longlong *)(lVar7 + 0xb8) + -0x46);
        *pbVar1 = *pbVar1 | 2;
        iVar5 = IofCallDriver(psVar3);
        if (iVar5 == 0x103) {
          local_f8 = (undefined8 *)0x0;
          KeWaitForSingleObject(&local_78,0,0,0);
          iVar5 = (int)local_b8;
        }
        if (-1 < iVar5) {
          if (local_50._4_4_ == 0) {
            iVar5 = -0x3ffffff3;
          }
          else {
            uVar8 = IsUdfsVolume(psVar3,local_50._4_4_);
            iVar5 = -0x3ffffeb1;
            if ((char)uVar8 != '\0') {
              iVar5 = -0x3ffffe64;
            }
          }
        }
      }
      goto LAB_1c0008990;
    }
    if (cVar2 == '\x03') {
      iVar5 = FsRecLoadFileSystem(param_1,
                                  L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Udfs")
      ;
      goto LAB_1c0008990;
    }
  }
  else {
    if (iVar5 != 2) {
      if (iVar5 == 1) {
        iVar5 = CdfsRecFsControl(param_1,param_2);
        return iVar5;
      }
      if (iVar5 == 4) {
        iVar5 = NtfsRecFsControl(param_1,param_2);
        return iVar5;
      }
      if (iVar5 == 6) {
        iVar5 = ExFatRecFsControl(param_1,param_2);
        return iVar5;
      }
      if (iVar5 == 7) {
        iVar5 = ReFSRecFsControl(param_1,param_2,'\0');
        return iVar5;
      }
      if (iVar5 == 8) {
        iVar5 = ReFSRecFsControl(param_1,param_2,'\x01');
        return iVar5;
      }
      return -0x3ffffff0;
    }
    local_c0 = 0;
    local_c8[0] = 0;
    cVar2 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
    if (cVar2 == '\x01') {
      lVar7 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x10);
      iVar5 = FsRecGetDeviceSectorSize(lVar7,local_c8,(ulonglong *)0x0);
      if (-1 < iVar5) {
        local_98 = 0;
        iVar12 = -0x3ffffeb1;
        iVar5 = -0x3ffffeb1;
        local_b8 = 0;
        uStack_b0 = 0;
        bVar4 = false;
        local_a8 = 0;
        uStack_a0 = 0;
        KeInitializeEvent(&local_a8,1,0);
        uVar14 = local_c8[0];
        if (local_c8[0] < 0x201) {
          uVar14 = (local_c8[0] + 0x1ff) - (local_c8[0] + 0x1ff) % local_c8[0];
        }
        pcVar9 = (char *)ExAllocatePoolWithTag(0x600,uVar14 + 0xfff & 0xfffff000,0x63727346);
        if (pcVar9 != (char *)0x0) {
          local_e8 = &local_b8;
          uVar8 = (ulonglong)uVar14;
          local_f0 = &local_a8;
          local_f8 = &local_c0;
          pcVar13 = pcVar9;
          lVar10 = IoBuildSynchronousFsdRequest(3,lVar7);
          if (lVar10 != 0) {
            pbVar1 = (byte *)(*(longlong *)(lVar10 + 0xb8) + -0x46);
            *pbVar1 = *pbVar1 | 2;
            iVar6 = IofCallDriver(lVar7);
            if (iVar6 == 0x103) {
              uVar8 = 0;
              local_f8 = (undefined8 *)0x0;
              pcVar13 = (char *)0x0;
              lVar10 = 0;
              KeWaitForSingleObject(&local_a8);
              iVar6 = (int)local_b8;
            }
            if (iVar6 < 0) {
              bVar4 = true;
            }
            else {
              uVar11 = IsFatVolume(pcVar9,lVar10,pcVar13,uVar8);
              iVar12 = -0x3ffffeb1;
              iVar5 = -0x3ffffeb1;
              if ((char)uVar11 != '\0') {
                iVar12 = -0x3ffffe64;
                iVar5 = -0x3ffffe64;
              }
            }
          }
          ExFreePoolWithTag(pcVar9,0);
          if ((bVar4) && (iVar5 = iVar12, (*(byte *)(lVar7 + 0x34) & 4) != 0)) {
            iVar5 = -0x3ffffe64;
          }
        }
      }
      goto LAB_1c0008990;
    }
    if (cVar2 == '\x03') {
      iVar5 = FsRecLoadFileSystem(param_1,
                                  L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Fastfat"
                                 );
      goto LAB_1c0008990;
    }
  }
LAB_1c0008c3e:
  iVar5 = -0x3ffffff0;
LAB_1c0008990:
  *(int *)(param_2 + 0x30) = iVar5;
  IofCompleteRequest(param_2,0);
  return iVar5;
}



===== IsUdfsVolume @ 1c0008cb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong IsUdfsVolume(short *param_1,uint param_2)

{
  undefined **ppuVar1;
  byte *pbVar2;
  uint uVar3;
  bool bVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  short *psVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  short *psVar13;
  uint uVar14;
  short *psVar15;
  char cVar16;
  uint uVar17;
  undefined **ppuVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  short *psVar21;
  undefined1 auStackY_1f8 [32];
  char local_1b8 [4];
  int local_1b4;
  undefined8 local_1b0;
  uint local_1a8 [2];
  ulonglong local_1a0;
  short *local_198;
  short *local_190;
  undefined1 local_188 [16];
  undefined8 local_178;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined2 local_168;
  byte local_160;
  undefined1 uStack_15f;
  char cStack_15e;
  undefined4 uStack_15d;
  undefined1 uStack_159;
  undefined1 uStack_158;
  undefined1 uStack_157;
  undefined1 uStack_156;
  undefined1 uStack_155;
  undefined4 uStack_154;
  uint5 local_148;
  byte bStack_143;
  byte bStack_142;
  byte bStack_141;
  undefined1 uStack_140;
  undefined1 uStack_13f;
  undefined1 uStack_13e;
  undefined1 uStack_13d;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined2 local_128;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_198 = (short *)0x0;
  local_1a0 = 0;
  local_1a8[0] = 0;
  uVar12 = 0;
  local_1b4 = 0;
  psVar15 = (short *)0x0;
  local_1b8[0] = '\0';
  local_1b0 = local_1b0 & 0xffffffff00000000;
  uVar20 = 0x800;
  psVar21 = (short *)0x0;
  local_160 = 0;
  uStack_15f = 0;
  cStack_15e = '\0';
  uStack_15d = 0;
  uStack_159 = 0;
  uStack_158 = 0;
  uStack_157 = 0;
  uStack_156 = 0;
  uStack_155 = 0;
  local_190 = param_1;
  if (*(int *)(param_1 + 0x24) == 2) {
    uVar10 = FsRecDeviceIoControl(param_1,0x24038,0,0,&local_160,0xc);
    uVar19 = local_1b0;
    iVar7 = (int)uVar10;
    if (iVar7 < 0) {
      if (((iVar7 == -0x3fffff5d) || (iVar7 == -0x3ffffe88)) || (iVar7 == -0x3fffffed)) {
        return uVar10 & 0xffffffffffffff00;
      }
      UdfsRecGetOpenSessionStart
                ((longlong)param_1,(undefined1 *)&local_1b0,(int *)local_1a8,local_1b8);
      psVar13 = local_190;
      uVar17 = local_1a8[0];
      if (local_1b8[0] == '\0') {
        return 0;
      }
      if (*(int *)(param_1 + 0x24) != 2) {
        return 0;
      }
      iVar7 = (int)local_1b0;
      while (uVar14 = (uint)psVar15, uVar14 < 4) {
        if (uVar14 == 0) {
          uVar3 = iVar7 + 0x100;
LAB_1c0009116:
          local_1a0 = (ulonglong)(param_2 * uVar3);
        }
        else {
          if (uVar14 == 1) {
            uVar3 = iVar7 + 0x200;
            goto LAB_1c0009116;
          }
          if (uVar14 == 2) {
            uVar3 = uVar17 - 0x100;
            goto LAB_1c0009116;
          }
          uVar3 = uVar17;
          if (uVar14 == 3) goto LAB_1c0009116;
        }
        uVar11 = FsRecReadBlock(psVar13,&local_1a0,0x200,param_2,(longlong *)&local_198,
                                (undefined1 *)0x0);
        psVar21 = local_198;
        if ((((char)uVar11 != '\0') && (*local_198 == 2)) && (local_198[5] == 0x1f0))
        goto LAB_1c00092d5;
        psVar15 = (short *)(ulonglong)(uVar14 + 1);
      }
      goto LAB_1c0008dfe;
    }
    if (cStack_15e != (char)uStack_15d) {
      local_1b0._0_2_ = CONCAT11(uStack_156,uStack_155);
      local_1b0._0_3_ = CONCAT12(uStack_157,(undefined2)local_1b0);
      local_1b0._4_4_ = SUB84(uVar19,4);
      local_1b0._0_4_ = CONCAT13(uStack_158,(undefined3)local_1b0);
      local_1b4 = (int)local_1b0;
    }
  }
  if (*(int *)(param_1 + 0x24) == 2) {
    local_1a8[0] = 0x100;
    uStack_15f = 0;
    cStack_15e = '\0';
    uStack_15d = 0;
    uStack_157 = 0;
    uStack_156 = 0;
    uStack_155 = 0;
    uStack_154 = 0;
    local_160 = 0x51;
    uStack_159 = 1;
    uStack_158 = 0;
    uVar12 = UdfsRecSendSptCdb(param_1,&local_160,&local_148,local_1a8);
    if (-1 < (int)uVar12) {
      local_188[5] = bStack_143;
      local_188._0_5_ = local_148;
      local_188[6] = bStack_142;
      local_188[7] = bStack_141;
      local_188[8] = uStack_140;
      local_188[9] = uStack_13f;
      local_188[10] = uStack_13e;
      local_188[0xb] = uStack_13d;
      local_188._12_4_ = uStack_13c;
      local_168 = local_128;
      local_178 = CONCAT44(uStack_134,local_138);
      uStack_170 = uStack_130;
      uStack_16c = uStack_12c;
      if (((local_148 & 0xc0000) != 0 && ((byte)(local_148 >> 0x10) & 0xc) != 0xc) &&
         ((local_148 & 0x30000) != 0)) {
        iVar7 = UdfsReadTrackInfo(param_1,bStack_142,&local_148);
        psVar13 = local_190;
        if (-1 < iVar7) {
          cVar6 = local_188[5];
          cVar16 = local_188[6];
          if ((bStack_142 & 0x40) != 0) {
            if (local_188[5] == local_188[6]) goto LAB_1c0008d34;
            cVar16 = local_188[6] + -1;
            iVar7 = UdfsReadTrackInfo(local_190,cVar16,&local_148);
            if (iVar7 < 0) goto LAB_1c0008d34;
          }
          if ((((bStack_143 & 0x20) == 0) && ((bStack_141 & 3) != 0)) &&
             ((cVar16 == cVar6 || (iVar7 = UdfsReadTrackInfo(psVar13,cVar6,&local_148), -1 < iVar7))
             )) {
            local_1b0._0_2_ = CONCAT11(uStack_13e,uStack_13d);
            local_1b0._0_3_ = CONCAT12(uStack_13f,(undefined2)local_1b0);
            local_1b0._0_4_ = CONCAT13(uStack_140,(undefined3)local_1b0);
            local_1b4 = (int)local_1b0;
          }
        }
      }
    }
  }
LAB_1c0008d34:
  local_198 = (short *)(ulonglong)(param_2 - 1);
  local_1a8[0] = param_2 + 0x7fff & ~(param_2 - 1);
  do {
    cVar16 = '\0';
    bVar4 = false;
    local_1b8[0] = '\0';
    uVar19 = (ulonglong)(param_2 * local_1b4 + local_1a8[0]);
    uVar12 = 0;
    local_1b0 = uVar19;
    local_1a0 = uVar19;
    do {
      psVar13 = local_198;
      psVar8 = psVar15;
      if (((ulonglong)local_198 & local_1a0) == 0) {
        local_178 = 0;
        local_160 = 0;
        uStack_15f = 0;
        cStack_15e = '\0';
        uStack_15d = 0;
        uStack_159 = 0;
        uStack_158 = 0;
        uStack_157 = 0;
        uStack_156 = 0;
        uStack_155 = 0;
        uStack_154 = 0;
        local_188 = ZEXT816(0);
        KeInitializeEvent(local_188,1,0);
        if (param_2 < 0x801) {
          uVar17 = (param_2 + 0x7ff) - (param_2 + 0x7ff) % param_2;
        }
        else {
          uVar17 = param_2;
        }
        psVar8 = psVar21;
        if (psVar21 == (short *)0x0) {
          psVar8 = (short *)ExAllocatePoolWithTag(0x600,uVar17 + 0xfff & 0xfffff000,0x63727346);
          psVar21 = psVar8;
          if (psVar8 == (short *)0x0) break;
        }
        psVar13 = local_190;
        lVar9 = IoBuildSynchronousFsdRequest(3,local_190,psVar8,uVar17);
        psVar21 = psVar8;
        if (lVar9 == 0) break;
        pbVar2 = (byte *)(*(longlong *)(lVar9 + 0xb8) + -0x46);
        *pbVar2 = *pbVar2 | 2;
        iVar7 = IofCallDriver();
        if (iVar7 == 0x103) {
          psVar13 = (short *)local_188;
          KeWaitForSingleObject(psVar13,0,0,0);
          iVar7 = CONCAT13((char)uStack_15d,CONCAT12(cStack_15e,CONCAT11(uStack_15f,local_160)));
        }
        if (iVar7 < 0) break;
        uVar19 = local_1b0;
        cVar16 = local_1b8[0];
      }
      ppuVar18 = &VsdIdentParseTable;
      piVar5 = (int *)VsdIdentParseTable;
      if ((char)*psVar8 == '\0') {
        while (piVar5 != (int *)0x0) {
          iVar7 = *piVar5 - *(int *)((longlong)psVar8 + 1);
          if (iVar7 == 0) {
            iVar7 = (uint)*(byte *)(piVar5 + 1) - (uint)*(byte *)((longlong)psVar8 + 5);
          }
          if (iVar7 == 0) break;
          ppuVar1 = ppuVar18 + 2;
          ppuVar18 = ppuVar18 + 2;
          piVar5 = (int *)*ppuVar1;
        }
        if (*(int *)(ppuVar18 + 1) == 2) {
          bVar4 = true;
        }
        else {
          switch(*(int *)(ppuVar18 + 1)) {
          case 1:
            if ((cVar16 != '\0') || ((char)psVar8[3] != '\x01')) goto LAB_1c0008e5e;
            cVar16 = '\x01';
            local_1b8[0] = '\x01';
            break;
          default:
            if ((local_1a0 == uVar19 + 0x800) && (0x800 < param_2)) goto LAB_1c0008fff;
LAB_1c0008e5e:
            local_1a0 = local_1a0 + uVar20;
            psVar15 = psVar8 + 0x400;
            goto LAB_1c0008df3;
          case 4:
          case 5:
          case 6:
          case 7:
          case 9:
            break;
          case 8:
          case 10:
            if ((cVar16 != '\0') && ((char)psVar8[3] == '\x01')) {
              local_1a0 = local_1a0 + uVar20;
              goto LAB_1c00092d5;
            }
          }
        }
      }
      else {
        psVar15 = psVar8;
        if ((cVar16 != '\0') || ((byte)((char)*psVar8 - 3U) < 0xfc)) break;
        iVar7 = UdfsFindInParseTable(psVar13,(int *)((longlong)psVar8 + 1));
        if ((iVar7 != 3) && (iVar7 != 4)) {
          if ((local_1a0 != uVar19 + 0x800) || (param_2 < 0x801)) goto LAB_1c0008e5e;
LAB_1c0008fff:
          local_1a0 = local_1a0 - uVar20;
          uVar20 = (ulonglong)param_2;
        }
      }
      psVar15 = psVar8 + 0x400;
      local_1a0 = local_1a0 + uVar20;
    } while (!bVar4);
LAB_1c0008df3:
    if (local_1b4 == 0) goto LAB_1c0008dfe;
    local_1b4 = 0;
  } while( true );
LAB_1c00092d5:
  uVar12 = 1;
LAB_1c0008dfe:
  if (psVar21 != (short *)0x0) {
    ExFreePoolWithTag(psVar21,0);
  }
  return uVar12;
}



===== FsRecGetDeviceSectorSize @ 1c0009300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FsRecGetDeviceSectorSize(longlong param_1,uint *param_2,ulonglong *param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 auStack_d8 [32];
  ulonglong *local_b8;
  undefined4 local_b0;
  undefined1 local_a8;
  undefined8 *local_a0;
  undefined8 *local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulonglong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_d8;
  local_48 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  KeInitializeEvent(&local_88,1,0);
  local_98 = &local_68;
  local_a0 = &local_88;
  local_a8 = 0;
  local_b8 = &local_70;
  local_b0 = 8;
  lVar4 = IoBuildDeviceIoControlRequest(0x7405c,param_1,0,0);
  iVar3 = -0x3fffff66;
  if (lVar4 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar4 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 2;
    iVar2 = IofCallDriver(param_1,lVar4);
    if (iVar2 == 0x103) {
      local_b8 = (ulonglong *)0x0;
      KeWaitForSingleObject(&local_88,0,0,0);
      iVar2 = (int)local_68;
    }
  }
  if (*(int *)(param_1 + 0x48) == 7) {
    uVar5 = 0x70000;
  }
  else {
    if (*(int *)(param_1 + 0x48) != 2) {
      return -0x3ffffff0;
    }
    uVar5 = 0x2404c;
  }
  local_78 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_68 = 0;
  uStack_60 = 0;
  KeInitializeEvent(&local_88,1,0);
  local_98 = &local_68;
  local_a0 = &local_88;
  local_a8 = 0;
  local_b8 = &local_58;
  local_b0 = 0x18;
  lVar4 = IoBuildDeviceIoControlRequest(uVar5,param_1,0,0);
  if (lVar4 != 0) {
    pbVar1 = (byte *)(*(longlong *)(lVar4 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 2;
    iVar3 = IofCallDriver(param_1);
    if (iVar3 == 0x103) {
      local_b8 = (ulonglong *)0x0;
      KeWaitForSingleObject(&local_88,0,0,0);
      iVar3 = (int)local_68;
    }
    if (-1 < iVar3) {
      if (local_48._4_4_ == 0) {
        return -0x3ffffff3;
      }
      *param_2 = local_48._4_4_;
      if (param_3 != (ulonglong *)0x0) {
        if (iVar2 < 0) {
          return iVar2;
        }
        *param_3 = local_70 / local_48._4_4_;
      }
      return 0;
    }
  }
  return iVar3;
}



===== ReFSRecFsControl @ 1c0009580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ReFSRecFsControl(longlong param_1,longlong param_2,char param_3)

{
  byte *pbVar1;
  char cVar2;
  longlong lVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  uint uVar12;
  ushort uVar13;
  ulonglong uVar14;
  ushort uVar15;
  ushort uVar16;
  undefined8 uVar17;
  undefined1 auStackY_1c8 [32];
  longlong local_168;
  ulonglong local_160;
  undefined8 local_158;
  longlong local_150;
  longlong local_148;
  ulonglong local_140 [13];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1c8;
  uVar16 = 0;
  local_158 = 0;
  local_150 = 0;
  local_148 = 0;
  cVar2 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  local_80 = 0;
  uStack_78 = 0;
  if (cVar2 != '\x01') {
    if (cVar2 == '\x03') {
      if (param_3 == '\0') {
        iVar7 = FsRecLoadFileSystem(param_1,
                                    L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\ReFS"
                                   );
        if (iVar7 == -0x3fffffc6) {
          LastFSLoadFailedDueToBitLocker = '\x01';
        }
      }
      else {
        iVar7 = FsRecLoadFileSystem(param_1,
                                    L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\ReFSv1"
                                   );
      }
    }
    else {
      iVar7 = -0x3ffffff0;
    }
    goto LAB_1c0009940;
  }
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  local_50 = 0;
  local_88 = 0;
  local_140[3] = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_160 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_140[1] = 0;
  local_140[2] = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  KeInitializeEvent(local_140 + 1,1,0);
  lVar9 = IoBuildDeviceIoControlRequest(0x7405c,lVar3,0,0);
  iVar7 = -0x3fffff66;
  if (lVar9 == 0) {
    iVar6 = -0x3fffff66;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar9 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 2;
    iVar6 = IofCallDriver(lVar3);
    if (iVar6 == 0x103) {
      KeWaitForSingleObject(local_140 + 1,0,0,0);
      iVar6 = (int)local_d8;
    }
  }
  if (*(int *)(lVar3 + 0x48) == 7) {
    uVar17 = 0x70000;
  }
  else {
    if (*(int *)(lVar3 + 0x48) != 2) {
      iVar7 = -0x3ffffff0;
      goto LAB_1c0009940;
    }
    uVar17 = 0x2404c;
  }
  local_140[6] = 0;
  local_140[4] = 0;
  local_140[5] = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  KeInitializeEvent(local_140 + 4,1,0);
  lVar9 = IoBuildDeviceIoControlRequest(uVar17,lVar3,0,0);
  if (lVar9 == 0) goto LAB_1c0009940;
  pbVar1 = (byte *)(*(longlong *)(lVar9 + 0xb8) + -0x46);
  *pbVar1 = *pbVar1 | 2;
  iVar7 = IofCallDriver(lVar3);
  if (iVar7 == 0x103) {
    KeWaitForSingleObject(local_140 + 4,0,0,0);
    iVar7 = (int)local_c8;
  }
  if (iVar7 < 0) goto LAB_1c0009940;
  uVar5 = local_50._4_4_;
  if (local_50._4_4_ == 0) {
    iVar7 = -0x3ffffff3;
    goto LAB_1c0009940;
  }
  if (iVar6 < 0) {
    iVar7 = iVar6;
    goto LAB_1c0009940;
  }
  uVar10 = local_160 / local_50._4_4_;
  local_158 = 0;
  local_150 = ((longlong)uVar10 >> 1) * (longlong)(int)local_50._4_4_;
  local_b8 = 0;
  uStack_b0 = 0;
  local_140[7] = 0;
  local_140[8] = 0;
  iVar7 = -0x3ffffeb1;
  local_148 = (uVar10 - 1) * (longlong)(int)local_50._4_4_;
  local_140[9] = 0;
  local_140[0] = uVar10;
  KeInitializeEvent(local_140 + 7,1,0);
  uVar12 = uVar5 + 0x1ff;
  if (uVar5 < 0x201) {
    uVar8 = uVar12 - uVar12 % uVar5;
  }
  else {
    uVar8 = uVar5;
  }
  lVar9 = ExAllocatePoolWithTag(0x600,uVar8 + 0xfff & 0xfffff000,0x63727346);
  local_168 = lVar9;
  if ((lVar9 == 0) || (lVar11 = IoBuildSynchronousFsdRequest(3,lVar3,lVar9,uVar8), lVar11 == 0)) {
LAB_1c00099a1:
    local_140[0xc] = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    local_140[10] = 0;
    local_140[0xb] = 0;
    KeInitializeEvent(local_140 + 10,1,0);
    if (uVar5 < 0x201) {
      uVar12 = uVar12 - uVar12 % uVar5;
    }
    else {
      uVar12 = uVar5;
    }
    if (lVar9 == 0) {
      lVar9 = ExAllocatePoolWithTag(0x600,uVar12 + 0xfff & 0xfffff000,0x63727346);
      local_168 = lVar9;
      if (lVar9 != 0) goto LAB_1c0009a28;
    }
    else {
LAB_1c0009a28:
      lVar11 = IoBuildSynchronousFsdRequest(3,lVar3,lVar9,uVar12);
      if (lVar11 != 0) {
        pbVar1 = (byte *)(*(longlong *)(lVar11 + 0xb8) + -0x46);
        *pbVar1 = *pbVar1 | 2;
        iVar6 = IofCallDriver(lVar3,lVar11);
        if (iVar6 == 0x103) {
          KeWaitForSingleObject(local_140 + 10,0,0,0);
          iVar6 = (int)local_a8;
        }
        if (((((-1 < iVar6) && (*(char *)(lVar9 + 3) == 'R')) && (*(char *)(lVar9 + 4) == 'e')) &&
            (((*(char *)(lVar9 + 5) == 'F' && (*(char *)(lVar9 + 6) == 'S')) &&
             ((*(char *)(lVar9 + 7) == '\0' &&
              ((*(char *)(lVar9 + 8) == '\0' && (*(char *)(lVar9 + 9) == '\0')))))))) &&
           (*(char *)(lVar9 + 10) == '\0')) {
          if (param_3 == '\0') {
            if (1 < *(byte *)(lVar9 + 0x28)) goto LAB_1c0009d63;
          }
          else if (*(char *)(lVar9 + 0x28) == '\x01') {
LAB_1c0009d63:
            uVar16 = *(ushort *)(lVar9 + 0x14);
            if ((0x57 < uVar16) && (uVar16 < uVar5 || uVar16 == uVar5)) {
              uVar12 = 0;
              uVar14 = 3;
              do {
                if (1 < (ushort)((short)uVar14 - 0x16U)) {
                  uVar12 = (uVar12 >> 1 & 0x7fff) +
                           (uint)(ushort)((ushort)*(byte *)(uVar14 + lVar9) +
                                         (short)uVar12 * -0x8000);
                }
                uVar15 = (short)uVar14 + 1;
                uVar14 = (ulonglong)uVar15;
              } while (uVar15 < uVar16);
              if ((((*(short *)(lVar9 + 0x16) == (short)uVar12) &&
                   (*(int *)(lVar9 + 0x20) - 0x200U < 0xe01)) &&
                  ((((param_3 == '\0' && (*(int *)(lVar9 + 0x24) == 1)) ||
                    (((iVar6 = *(int *)(lVar9 + 0x24), iVar6 == 0x100 || (iVar6 == 0x80)) ||
                     ((iVar6 - 4U < 0x3d &&
                      ((0x1000000010001011U >> ((ulonglong)(iVar6 - 4U) & 0x3f) & 1) != 0)))))) ||
                   (iVar6 == 0x200)))) &&
                 ((*(ulonglong *)(lVar9 + 0x18) != 0 && (*(ulonglong *)(lVar9 + 0x18) <= uVar10))))
              {
                iVar7 = -0x3ffffe64;
                goto LAB_1c00098f4;
              }
            }
          }
        }
      }
    }
    uVar17 = FsRecReadBlock(lVar3,&local_148,0x200,uVar5,&local_168,(undefined1 *)0x0);
    lVar9 = local_168;
    if (((char)uVar17 != '\0') &&
       (uVar10 = IsReFSVolume(local_168,uVar5,local_140,param_3), (char)uVar10 != '\0')) {
      iVar7 = -0x3ffffe64;
    }
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar11 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 2;
    iVar6 = IofCallDriver(lVar3,lVar11);
    if (iVar6 == 0x103) {
      KeWaitForSingleObject(local_140 + 7,0,0,0);
      iVar6 = (int)local_b8;
    }
    if (iVar6 < 0) goto LAB_1c00099a1;
    if (((((*(char *)(lVar9 + 3) == 'R') && (*(char *)(lVar9 + 4) == 'e')) &&
         (*(char *)(lVar9 + 5) == 'F')) &&
        ((*(char *)(lVar9 + 6) == 'S' && (*(char *)(lVar9 + 7) == '\0')))) &&
       ((*(char *)(lVar9 + 8) == '\0' &&
        ((*(char *)(lVar9 + 9) == '\0' && (*(char *)(lVar9 + 10) == '\0')))))) {
      if (param_3 == '\0') {
        if (1 < *(byte *)(lVar9 + 0x28)) goto LAB_1c0009c27;
        goto LAB_1c00098e3;
      }
      if (*(char *)(lVar9 + 0x28) != '\x01') goto LAB_1c00098e3;
LAB_1c0009c27:
      uVar15 = *(ushort *)(lVar9 + 0x14);
      if ((uVar15 < 0x58) || (uVar5 <= uVar15 && uVar15 != uVar5)) goto LAB_1c00098e3;
      uVar14 = 3;
      do {
        if (1 < (ushort)((short)uVar14 - 0x16U)) {
          uVar16 = (uVar16 >> 1) + (ushort)*(byte *)(uVar14 + lVar9) + uVar16 * -0x8000;
        }
        uVar13 = (short)uVar14 + 1;
        uVar14 = (ulonglong)uVar13;
      } while (uVar13 < uVar15);
      if (((*(ushort *)(lVar9 + 0x16) != uVar16) || (0xe00 < *(int *)(lVar9 + 0x20) - 0x200U)) ||
         ((((((param_3 != '\0' || (*(int *)(lVar9 + 0x24) != 1)) &&
             ((iVar7 = *(int *)(lVar9 + 0x24), iVar7 != 0x100 && (iVar7 != 0x80)))) &&
            ((0x3c < iVar7 - 4U ||
             ((0x1000000010001011U >> ((ulonglong)(iVar7 - 4U) & 0x3f) & 1) == 0)))) &&
           (iVar7 != 0x200)) ||
          ((*(ulonglong *)(lVar9 + 0x18) == 0 || (uVar10 < *(ulonglong *)(lVar9 + 0x18)))))))
      goto LAB_1c00098e3;
      bVar4 = true;
    }
    else {
LAB_1c00098e3:
      bVar4 = false;
    }
    iVar7 = -0x3ffffe64;
    if (!bVar4) {
      iVar7 = -0x3ffffeb1;
    }
  }
LAB_1c00098f4:
  if (lVar9 != 0) {
    ExFreePoolWithTag(lVar9,0);
  }
  if (((LastFSLoadFailedDueToBitLocker == '\0') || (iVar7 != -0x3ffffe64)) || (param_3 != '\0')) {
    if (((LastFSLoadFailedDueToBitLocker == '\0') || (iVar7 == -0x3ffffeb1)) || (param_3 != '\0'))
    goto LAB_1c0009940;
  }
  else {
    iVar7 = -0x3fffffff;
  }
  LastFSLoadFailedDueToBitLocker = '\0';
LAB_1c0009940:
  *(int *)(param_2 + 0x30) = iVar7;
  IofCompleteRequest(param_2,0);
  return iVar7;
}



===== ExFatRecFsControl @ 1c0009ea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ExFatRecFsControl(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  char *pcVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined1 auStack_d8 [32];
  undefined8 *local_b8;
  undefined8 *local_b0;
  undefined8 *local_a8;
  undefined8 *local_a0;
  undefined8 *local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  local_58 = 0;
  cVar2 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar2 == '\x01') {
    lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    local_60 = 0;
    local_40 = 0;
    local_50 = 0;
    uStack_48 = 0;
    local_78 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_70 = 0;
    uStack_68 = 0;
    KeInitializeEvent(&local_88,1,0);
    local_98 = &local_70;
    local_a0 = &local_88;
    local_a8 = (undefined8 *)((ulonglong)local_a8 & 0xffffffffffffff00);
    local_b8 = &local_60;
    local_b0 = (undefined8 *)CONCAT44(local_b0._4_4_,8);
    lVar7 = IoBuildDeviceIoControlRequest(0x7405c,lVar3,0,0);
    if (lVar7 != 0) {
      pbVar1 = (byte *)(*(longlong *)(lVar7 + 0xb8) + -0x46);
      *pbVar1 = *pbVar1 | 2;
      iVar5 = IofCallDriver(lVar3,lVar7);
      if (iVar5 == 0x103) {
        local_b8 = (undefined8 *)0x0;
        KeWaitForSingleObject(&local_88,0,0,0);
      }
    }
    if (*(int *)(lVar3 + 0x48) == 2) {
      uVar9 = 0x2404c;
    }
    else {
      if (*(int *)(lVar3 + 0x48) != 7) goto LAB_1c000a1dc;
      uVar9 = 0x70000;
    }
    local_78 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_70 = 0;
    uStack_68 = 0;
    KeInitializeEvent(&local_88,1,0);
    local_98 = &local_70;
    local_a0 = &local_88;
    local_a8 = (undefined8 *)((ulonglong)local_a8 & 0xffffffffffffff00);
    local_b8 = &local_50;
    local_b0 = (undefined8 *)CONCAT44(local_b0._4_4_,0x18);
    lVar7 = IoBuildDeviceIoControlRequest(uVar9,lVar3,0,0);
    if (lVar7 == 0) {
      iVar5 = -0x3fffff66;
    }
    else {
      pbVar1 = (byte *)(*(longlong *)(lVar7 + 0xb8) + -0x46);
      *pbVar1 = *pbVar1 | 2;
      iVar5 = IofCallDriver(lVar3);
      if (iVar5 == 0x103) {
        local_b8 = (undefined8 *)0x0;
        KeWaitForSingleObject(&local_88,0,0,0);
        iVar5 = (int)local_70;
      }
      if (-1 < iVar5) {
        uVar10 = local_40._4_4_;
        if (local_40._4_4_ == 0) {
          iVar5 = -0x3ffffff3;
        }
        else {
          local_78 = 0;
          iVar5 = -0x3ffffeb1;
          local_70 = 0;
          uStack_68 = 0;
          local_88 = 0;
          uStack_80 = 0;
          KeInitializeEvent(&local_88,1,0);
          if (uVar10 < 0x201) {
            uVar10 = (uVar10 + 0x1ff) - (uVar10 + 0x1ff) % uVar10;
          }
          pcVar8 = (char *)ExAllocatePoolWithTag(0x600,uVar10 + 0xfff & 0xfffff000,0x63727346);
          if (pcVar8 != (char *)0x0) {
            local_a8 = &local_70;
            local_b0 = &local_88;
            local_b8 = &local_58;
            lVar7 = IoBuildSynchronousFsdRequest(3,lVar3,pcVar8,uVar10);
            if (lVar7 != 0) {
              pbVar1 = (byte *)(*(longlong *)(lVar7 + 0xb8) + -0x46);
              *pbVar1 = *pbVar1 | 2;
              iVar6 = IofCallDriver(lVar3,lVar7);
              if (iVar6 == 0x103) {
                local_b8 = (undefined8 *)0x0;
                KeWaitForSingleObject(&local_88,0,0,0);
                iVar6 = (int)local_70;
              }
              if (-1 < iVar6) {
                bVar4 = IsExFatVolume(pcVar8);
                iVar5 = -0x3ffffeb1;
                if (bVar4) {
                  iVar5 = -0x3ffffe64;
                }
              }
            }
            ExFreePoolWithTag(pcVar8,0);
          }
        }
      }
    }
  }
  else {
    if (cVar2 == '\x03') {
      iVar5 = FsRecLoadFileSystem(param_1,
                                  L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\ExFat"
                                 );
      goto LAB_1c000a195;
    }
LAB_1c000a1dc:
    iVar5 = -0x3ffffff0;
  }
LAB_1c000a195:
  *(int *)(param_2 + 0x30) = iVar5;
  IofCompleteRequest(param_2,0);
  return iVar5;
}



===== IsExFatVolume @ 1c000a250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool IsExFatVolume(char *param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined1 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  bVar3 = false;
  local_18 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_14 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((((*param_1 == -0x15) && (param_1[1] == 'v')) && (param_1[2] == -0x70)) &&
     ((((*(longlong *)(param_1 + 3) == 0x2020205441465845 &&
        (iVar2 = memcmp(param_1 + 0xb,&local_48,0x35), iVar2 == 0)) &&
       (((byte)(param_1[0x6c] - 7U) < 6 &&
        (((byte)param_1[0x6d] < 0x11 && (0x17 < *(uint *)(param_1 + 0x50))))))) &&
      ((byte)(param_1[0x6e] - 1U) < 2)))) {
    if ((ulonglong)((uint)(byte)param_1[0x6e] * *(uint *)(param_1 + 0x54)) +
        (ulonglong)*(uint *)(param_1 + 0x50) <= (ulonglong)*(uint *)(param_1 + 0x58)) {
      uVar1 = *(uint *)(param_1 + 0x5c);
      if ((((uVar1 != 0) &&
           ((ulonglong)uVar1 <=
            (((ulonglong)*(uint *)(param_1 + 0x54) << (param_1[0x6c] & 0x3fU)) >> 2) - 2)) &&
          (((ulonglong)uVar1 << (param_1[0x6d] & 0x3fU)) + (ulonglong)*(uint *)(param_1 + 0x58) <=
           *(ulonglong *)(param_1 + 0x48))) &&
         ((1 < *(uint *)(param_1 + 0x60) && (*(uint *)(param_1 + 0x60) - 2 < uVar1)))) {
        bVar3 = *(short *)(param_1 + 0x1fe) == -0x55ab;
      }
    }
  }
  return bVar3;
}



===== UdfsFindInParseTable @ 1c000a3a0 =====

undefined4 UdfsFindInParseTable(undefined8 param_1,int *param_2)

{
  undefined **ppuVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  
  ppuVar4 = &VsdIdentParseTable;
  piVar2 = (int *)VsdIdentParseTable;
  while (piVar2 != (int *)0x0) {
    iVar3 = *piVar2 - *param_2;
    if (iVar3 == 0) {
      iVar3 = (uint)*(byte *)(piVar2 + 1) - (uint)*(byte *)(param_2 + 1);
    }
    if (iVar3 == 0) break;
    ppuVar1 = ppuVar4 + 2;
    ppuVar4 = ppuVar4 + 2;
    piVar2 = (int *)*ppuVar1;
  }
  return *(undefined4 *)(ppuVar4 + 1);
}



===== UdfsRecSendSptCdb @ 1c000a3f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UdfsRecSendSptCdb(undefined8 param_1,byte *param_2,void *param_3,uint *param_4)

{
  byte bVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  undefined1 auStackY_278 [32];
  undefined2 local_248;
  char local_246;
  byte local_242;
  undefined1 local_241;
  undefined1 local_240;
  uint local_23c;
  undefined4 local_238;
  undefined8 local_230;
  undefined4 local_228;
  undefined1 local_224 [22];
  byte local_20e;
  undefined1 local_1fc [436];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_278;
  bVar5 = 0;
  bVar1 = *param_2 >> 5;
  if (bVar1 == 0) {
    bVar5 = 6;
  }
  else if ((bVar1 == 1) || (bVar1 == 2)) {
    bVar5 = 10;
  }
  else if (bVar1 == 5) {
    bVar5 = 0xc;
  }
  if (*param_4 != 0) {
    memset(param_3,0,(ulonglong)*param_4);
  }
  uVar4 = *param_4;
  uVar3 = uVar4 + 0x4c;
  if (uVar3 < 0x201) {
    memset(&local_248,0,(ulonglong)uVar3);
    memcpy(local_224,param_2,(ulonglong)bVar5);
    local_248 = 0x38;
    local_241 = 0x12;
    if (uVar4 == 0) {
      local_240 = 2;
    }
    else {
      local_240 = 1;
    }
    local_228 = 0x38;
    local_238 = 0x2d;
    local_230 = 0x4c;
    local_242 = bVar5;
    local_23c = uVar4;
    uVar2 = FsRecDeviceIoControl(param_1,0x4d004,&local_248,uVar3,&local_248,uVar3);
    if (-1 < (int)uVar2) {
      if ((local_20e & 0xf) == 0) {
        if (local_246 == '\0') {
          uVar3 = *param_4;
          uVar4 = 0;
          if (uVar3 < local_23c) {
            uVar4 = 0x80000005;
          }
          if (local_23c < uVar3) {
            *param_4 = local_23c;
            uVar3 = local_23c;
          }
          if (uVar4 != 0x80000005) {
            memcpy(param_3,local_1fc,(ulonglong)uVar3);
          }
        }
        else {
          uVar4 = 0xc000000d;
        }
      }
      else {
        uVar4 = 0xc0000185;
      }
      uVar2 = (ulonglong)uVar4;
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== FsRecDeviceIoControl @ 1c000a570 =====

ulonglong FsRecDeviceIoControl
                    (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 param_6)

{
  byte *pbVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,1,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_2,param_1,param_3,param_4,param_5,param_6,0,local_38 + 2,local_38);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(lVar2 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 2;
    uVar3 = IofCallDriver(param_1,lVar2);
    if ((int)uVar3 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar3 = local_38[0] & 0xffffffff;
    }
  }
  return uVar3;
}



===== FsRecReadBlock @ 1c000a680 =====

ulonglong FsRecReadBlock(undefined8 param_1,undefined8 param_2,uint param_3,uint param_4,
                        longlong *param_5,undefined1 *param_6)

{
  byte *pbVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  if (param_6 != (undefined1 *)0x0) {
    *param_6 = 0;
  }
  KeInitializeEvent(local_38 + 2,1);
  if (param_4 <= param_3) {
    param_4 = (param_3 + param_4 + -1) - ((param_3 + param_4) - 1) % param_4;
  }
  lVar2 = *param_5;
  if (lVar2 == 0) {
    lVar2 = ExAllocatePoolWithTag(0x600,param_4 + 0xfff & 0xfffff000,0x63727346);
    *param_5 = lVar2;
    uVar3 = 0;
    if (lVar2 == 0) goto LAB_1c000a7ef;
  }
  lVar2 = IoBuildSynchronousFsdRequest(3,param_1,lVar2,param_4,param_2,local_38 + 2,local_38);
  uVar3 = 0;
  if (lVar2 != 0) {
    pbVar1 = (byte *)(*(longlong *)(lVar2 + 0xb8) + -0x46);
    *pbVar1 = *pbVar1 | 2;
    uVar3 = IofCallDriver(param_1,lVar2);
    if ((int)uVar3 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar3 = local_38[0] & 0xffffffff;
    }
    if (-1 < (int)uVar3) {
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
    if (param_6 != (undefined1 *)0x0) {
      *param_6 = 1;
    }
  }
LAB_1c000a7ef:
  return uVar3 & 0xffffffffffffff00;
}



===== UdfsRecGetOpenSessionStart @ 1c000a800 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UdfsRecGetOpenSessionStart
               (longlong param_1,undefined1 *param_2,int *param_3,undefined1 *param_4)

{
  int iVar1;
  ulonglong uVar2;
  char cVar3;
  undefined1 auStack_1b8 [48];
  uint local_188 [2];
  byte local_180 [16];
  undefined1 local_170 [16];
  uint5 local_148;
  byte bStack_143;
  byte bStack_142;
  byte bStack_141;
  undefined1 uStack_140;
  undefined1 uStack_13f;
  undefined1 uStack_13e;
  undefined1 uStack_13d;
  undefined1 uStack_13c;
  undefined1 uStack_13b;
  undefined1 uStack_13a;
  undefined1 uStack_139;
  undefined1 local_12c;
  undefined1 local_12b;
  undefined1 local_12a;
  undefined1 local_129;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1b8;
  if (*(int *)(param_1 + 0x48) == 2) {
    local_188[0] = 0x100;
    local_180[1] = 0;
    local_180[2] = 0;
    local_180[3] = 0;
    local_180[4] = 0;
    local_180[5] = 0;
    local_180[6] = 0;
    local_180[9] = 0;
    local_180[10] = 0;
    local_180[0xb] = 0;
    local_180[0xc] = 0;
    local_180[0xd] = 0;
    local_180[0xe] = 0;
    local_180[0xf] = 0;
    local_180[0] = 0x51;
    local_180[7] = 1;
    local_180[8] = 0;
    uVar2 = UdfsRecSendSptCdb(param_1,local_180,&local_148,local_188);
    if ((((-1 < (int)uVar2) &&
         (local_170[5] = bStack_143, local_170._0_5_ = local_148, local_170[6] = bStack_142,
         local_170[7] = bStack_141, local_170[8] = uStack_140, local_170[9] = uStack_13f,
         local_170[10] = uStack_13e, local_170[0xb] = uStack_13d, local_170[0xc] = uStack_13c,
         local_170[0xd] = uStack_13b, local_170[0xe] = uStack_13a, local_170[0xf] = uStack_139,
         (local_148 & 0xc0000) != 0 && ((byte)(local_148 >> 0x10) & 0xc) != 0xc)) &&
        ((local_148 & 0x30000) != 0)) &&
       (iVar1 = UdfsReadTrackInfo(param_1,bStack_142,&local_148), -1 < iVar1)) {
      cVar3 = local_170[6];
      if ((bStack_142 & 0x40) != 0) {
        if (local_170[5] == local_170[6]) {
          return;
        }
        cVar3 = local_170[6] + -1;
        iVar1 = UdfsReadTrackInfo(param_1,cVar3,&local_148);
        if (iVar1 < 0) {
          return;
        }
      }
      if (((bStack_143 & 0x20) == 0) && ((bStack_141 & 3) != 0)) {
        if (param_4 != (undefined1 *)0x0) {
          *param_4 = 1;
        }
        if ((bStack_141 & 2) == 0) {
          *(undefined1 *)param_3 = uStack_139;
          *(undefined1 *)((longlong)param_3 + 1) = uStack_13a;
          *(undefined1 *)((longlong)param_3 + 2) = uStack_13b;
          *(undefined1 *)((longlong)param_3 + 3) = uStack_13c;
          *param_3 = *param_3 + -1;
        }
        else {
          *(undefined1 *)param_3 = local_129;
          *(undefined1 *)((longlong)param_3 + 1) = local_12a;
          *(undefined1 *)((longlong)param_3 + 2) = local_12b;
          *(undefined1 *)((longlong)param_3 + 3) = local_12c;
        }
        if ((cVar3 == local_170[5]) ||
           (iVar1 = UdfsReadTrackInfo(param_1,local_170[5],&local_148), -1 < iVar1)) {
          *param_2 = uStack_13d;
          param_2[1] = uStack_13e;
          param_2[2] = uStack_13f;
          param_2[3] = uStack_140;
        }
      }
    }
  }
  return;
}



===== IsReFSVolume @ 1c000a9d0 =====

ulonglong IsReFSVolume(longlong param_1,uint param_2,ulonglong *param_3,char param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ulonglong in_RAX;
  ushort uVar4;
  ushort uVar5;
  ulonglong uVar6;
  
  if (((((*(char *)(param_1 + 3) == 'R') && (*(char *)(param_1 + 4) == 'e')) &&
       (*(char *)(param_1 + 5) == 'F')) &&
      ((*(char *)(param_1 + 6) == 'S' && (*(char *)(param_1 + 7) == '\0')))) &&
     ((*(char *)(param_1 + 8) == '\0' &&
      ((*(char *)(param_1 + 9) == '\0' && (*(char *)(param_1 + 10) == '\0')))))) {
    in_RAX = 0;
    if (param_4 == '\0') {
      if (*(byte *)(param_1 + 0x28) < 2) goto LAB_1c000a9db;
    }
    else if (*(byte *)(param_1 + 0x28) != 1) goto LAB_1c000a9db;
    uVar1 = *(ushort *)(param_1 + 0x14);
    if ((0x57 < uVar1) && (uVar1 < param_2 || uVar1 == param_2)) {
      uVar6 = 3;
      uVar4 = 0;
      do {
        uVar3 = (int)uVar6 - 0x16;
        in_RAX = (ulonglong)uVar3;
        if (1 < (ushort)uVar3) {
          uVar4 = (uVar4 >> 1) + (ushort)*(byte *)(uVar6 + param_1) + uVar4 * -0x8000;
          in_RAX = uVar6;
        }
        uVar5 = (short)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < uVar1);
      if (((*(ushort *)(param_1 + 0x16) == uVar4) &&
          (uVar3 = *(int *)(param_1 + 0x20) - 0x200, in_RAX = (ulonglong)uVar3, uVar3 < 0xe01)) &&
         (((param_4 == '\0' && (*(int *)(param_1 + 0x24) == 1)) ||
          ((((iVar2 = *(int *)(param_1 + 0x24), iVar2 == 0x100 || (iVar2 == 0x80)) ||
            ((in_RAX = (ulonglong)(iVar2 - 4U), iVar2 - 4U < 0x3d &&
             ((0x1000000010001011U >> (in_RAX & 0x3f) & 1) != 0)))) || (iVar2 == 0x200)))))) {
        uVar6 = *(ulonglong *)(param_1 + 0x18);
        in_RAX = 0;
        if (uVar6 != 0) {
          return CONCAT71((int7)(uVar6 >> 8),uVar6 <= *param_3);
        }
      }
    }
  }
LAB_1c000a9db:
  return in_RAX & 0xffffffffffffff00;
}



===== CdfsRecFsControl @ 1c000ab00 =====

int CdfsRecFsControl(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar1 == '\x01') {
    iVar2 = FsRecGetDeviceSectorSize
                      (*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x10),local_res8,
                       (ulonglong *)0x0);
    if (-1 < iVar2) {
      iVar2 = -0x3ffffe64;
    }
  }
  else if (cVar1 == '\x03') {
    iVar2 = FsRecLoadFileSystem(param_1,
                                L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Cdfs");
  }
  else {
    iVar2 = -0x3ffffff0;
  }
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== entry @ 1c000b010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c000b044 =====

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



===== DriverEntry @ 1c000b080 =====

uint DriverEntry(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  longlong local_res8;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  local_res8 = 0;
  MmPageEntireDriver(DriverEntry);
  *(code **)(param_1 + 0xd8) = FsRecFsControl;
  *(code **)(param_1 + 0x70) = FsRecCreate;
  *(code **)(param_1 + 0x100) = FsRecCleanupClose;
  *(code **)(param_1 + 0x80) = FsRecCleanupClose;
  *(code **)(param_1 + 0x68) = FsRecUnload;
  FsRecLoadSync = ExAllocatePoolWithTag(0x600,0x18,0x63727346);
  if (FsRecLoadSync == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    KeInitializeEvent(FsRecLoadSync,1,1);
    memset(&LoadDriverStatusLog,0,0xa4);
    uVar2 = FsRecCreateAndRegisterDO
                      (param_1,0,(longlong *)0x0,L"\\Ntfs",L"\\FileSystem\\NtfsRecognizer",4,8,'\0')
    ;
    iVar4 = -((int)~(uint)uVar2 >> 0x1f);
    uVar2 = FsRecCreateAndRegisterDO
                      (param_1,0,&local_res8,L"\\Fat",L"\\FileSystem\\FatDiskRecognizer",2,8,'\x01')
    ;
    iVar3 = iVar4 + 1;
    if ((int)uVar2 < 0) {
      iVar3 = iVar4;
    }
    uVar2 = FsRecCreateAndRegisterDO
                      (param_1,0,(longlong *)0x0,L"\\ExFat",L"\\FileSystem\\ExFatRecognizer",6,8,
                       '\x01');
    iVar4 = iVar3 + 1;
    if ((int)uVar2 < 0) {
      iVar4 = iVar3;
    }
    uVar2 = FsRecCreateAndRegisterDO
                      (param_1,0,(longlong *)0x0,L"\\ReFS",L"\\FileSystem\\ReFSRecognizer",7,8,
                       '\x01');
    iVar3 = iVar4 + 1;
    if ((int)uVar2 < 0) {
      iVar3 = iVar4;
    }
    uVar2 = FsRecCreateAndRegisterDO
                      (param_1,0,(longlong *)0x0,L"\\ReFSv1",L"\\FileSystem\\ReFSv1Recognizer",8,8,
                       '\x01');
    iVar4 = iVar3 + 1;
    if ((int)uVar2 < 0) {
      iVar4 = iVar3;
    }
    uVar2 = FsRecCreateAndRegisterDO
                      (param_1,0,local_res18,L"\\UdfsDisk",L"\\FileSystem\\UdfsDiskRecognizer",5,8,
                       '\x01');
    iVar3 = iVar4 + 1;
    if ((int)uVar2 < 0) {
      iVar3 = iVar4;
    }
    uVar2 = FsRecCreateAndRegisterDO
                      (param_1,local_res8,(longlong *)0x0,L"\\FatCdrom",
                       L"\\FileSystem\\FatCdRomRecognizer",2,3,'\0');
    iVar4 = iVar3 + 1;
    if ((int)uVar2 < 0) {
      iVar4 = iVar3;
    }
    uVar2 = FsRecCreateAndRegisterDO
                      (param_1,local_res18[0],(longlong *)0x0,L"\\UdfsCdRom",
                       L"\\FileSystem\\UdfsCdRomRecognizer",5,3,'\0');
    iVar3 = iVar4 + 1;
    if ((int)uVar2 < 0) {
      iVar3 = iVar4;
    }
    uVar2 = FsRecCreateAndRegisterDO
                      (param_1,0,(longlong *)0x0,L"\\Cdfs",L"\\FileSystem\\CdfsRecognizer",1,3,
                       '\x01');
    iVar4 = iVar3 + 1;
    if ((int)uVar2 < 0) {
      iVar4 = iVar3;
    }
    uVar1 = ~-(uint)(iVar4 != 0) & 0xc000010e;
  }
  return uVar1;
}



===== FsRecCreateAndRegisterDO @ 1c000b37c =====

undefined8
FsRecCreateAndRegisterDO
          (undefined8 param_1,longlong param_2,longlong *param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6,undefined4 param_7,char param_8)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  longlong local_res18 [2];
  ulonglong uVar4;
  uint uVar5;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar6;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
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
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  local_res18[0] = 0;
  local_4c = 0;
  local_34 = 0;
  local_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (param_3 != (longlong *)0x0) {
    *param_3 = 0;
  }
  RtlInitUnicodeString(&local_70,param_4);
  local_40 = &local_70;
  uVar5 = 0;
  uVar4 = 0;
  local_50 = 0x30;
  local_48 = 0;
  local_38 = 0x40;
  local_30 = 0;
  uStack_28 = 0;
  iVar2 = ZwCreateFile(&local_78,0x100000,&local_50,&local_60,0,0,CONCAT44(uVar6,3),1,0,0,0);
  if (iVar2 < 0) {
    if (iVar2 == -0x3fffffcc) {
      RtlInitUnicodeString(&local_70,param_5);
      uVar3 = IoCreateDevice(param_1,0x10,&local_70,param_7,uVar4 & 0xffffffff00000000,
                             uVar5 & 0xffffff00,local_res18);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      plVar1 = *(longlong **)(local_res18[0] + 0x40);
      *(undefined4 *)(plVar1 + 1) = param_6;
      *(undefined4 *)((longlong)plVar1 + 0xc) = 0;
      if (param_2 == 0) {
        *plVar1 = local_res18[0];
      }
      else {
        *plVar1 = **(longlong **)(param_2 + 0x40);
        **(longlong **)(param_2 + 0x40) = local_res18[0];
      }
      if (param_3 != (longlong *)0x0) {
        *param_3 = local_res18[0];
      }
      if (param_8 != '\0') {
        *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x10000;
      }
      IoRegisterFileSystem(local_res18[0]);
      return 0;
    }
  }
  else {
    ZwClose(local_78);
  }
  return 0xc000010e;
}


