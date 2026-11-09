
===== WmiCompleteRequest @ 1c0001010 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WmiCompleteRequest(undefined8 param_1,longlong param_2,int param_3,uint param_4,
                      undefined1 param_5)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint *puVar8;
  uint uVar9;
  
                    /* 0x1010  3  WmiCompleteRequest */
  lVar3 = *(longlong *)(param_2 + 0xb8);
  cVar1 = *(char *)(lVar3 + 1);
  puVar8 = *(uint **)(lVar3 + 0x20);
  if (cVar1 == '\0') {
    uVar9 = puVar8[0xc];
    uVar2 = puVar8[0xd];
    uVar4 = (ulonglong)uVar2;
    uVar5 = uVar9 + param_4;
    uVar6 = (ulonglong)uVar5;
    if (param_3 < 0) {
      if (param_3 != -0x3fffffdd) {
        uVar6 = 0;
        goto LAB_1c00010a5;
      }
    }
    else if (uVar5 <= *(uint *)(lVar3 + 0x18)) {
      *(undefined8 *)(puVar8 + 4) = _DAT_fffff78000000014;
      *puVar8 = uVar5;
      uVar7 = (ulonglong)uVar2;
      if (uVar2 != 0) {
        do {
          uVar5 = (int)uVar7 - 1;
          uVar7 = (ulonglong)uVar5;
          puVar8[uVar7 * 2 + 0x10] = (puVar8 + 0xf)[uVar7];
        } while (uVar5 != 0);
        if (uVar2 != 0) {
          puVar8 = puVar8 + 0xf;
          do {
            *puVar8 = uVar9;
            uVar9 = uVar9 + 7 + puVar8[1] & 0xfffffff8;
            uVar4 = uVar4 - 1;
            puVar8 = puVar8 + 2;
          } while (uVar4 != 0);
        }
      }
      goto LAB_1c00010a5;
    }
    puVar8[0xc] = uVar5;
    param_3 = 0;
    uVar6 = 0x38;
    *puVar8 = 0x38;
    puVar8[0xb] = 0x20;
    goto LAB_1c00010a5;
  }
  if (cVar1 == '\x01') {
    uVar9 = puVar8[0xe] + param_4;
    uVar6 = (ulonglong)uVar9;
    if (-1 < param_3) {
      *puVar8 = uVar9;
      *(undefined8 *)(puVar8 + 4) = _DAT_fffff78000000014;
      goto LAB_1c00010a5;
    }
LAB_1c0001145:
    if (param_3 == -0x3fffffdd) {
      puVar8[0xc] = uVar9;
      param_3 = 0;
      uVar6 = 0x38;
      *puVar8 = 0x38;
      puVar8[0xb] = 0x20;
      goto LAB_1c00010a5;
    }
  }
  else if (cVar1 == '\t') {
    uVar9 = puVar8[0xf] + param_4;
    uVar6 = (ulonglong)uVar9;
    if (-1 < param_3) {
      *puVar8 = uVar9;
      *(undefined8 *)(puVar8 + 4) = _DAT_fffff78000000014;
      puVar8[0x10] = param_4;
      goto LAB_1c00010a5;
    }
    goto LAB_1c0001145;
  }
  uVar6 = 0;
LAB_1c00010a5:
  *(ulonglong *)(param_2 + 0x38) = uVar6;
  *(int *)(param_2 + 0x30) = param_3;
  IofCompleteRequest(param_2,param_5);
  return param_3;
}



===== WmiFireEvent @ 1c0001180 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WmiFireEvent(undefined8 param_1,int *param_2,int param_3,uint param_4,void *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
                    /* 0x1180  4  WmiFireEvent */
  uVar5 = 0;
  if (param_5 != (void *)0x0) {
    uVar5 = param_4;
  }
  piVar4 = (int *)ExAllocatePool2(0x40,uVar5 + 0x40,0x4c696d57);
  if (piVar4 == (int *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    iVar3 = param_2[1];
    iVar1 = param_2[2];
    iVar2 = param_2[3];
    piVar4[6] = *param_2;
    piVar4[7] = iVar3;
    piVar4[8] = iVar1;
    piVar4[9] = iVar2;
    iVar3 = IoWMIDeviceObjectToProviderId(param_1);
    *piVar4 = uVar5 + 0x40;
    piVar4[1] = iVar3;
    piVar4[0xb] = 0x8a;
    *(undefined8 *)(piVar4 + 4) = _DAT_fffff78000000014;
    piVar4[0xd] = param_3;
    piVar4[0xf] = uVar5;
    piVar4[0xe] = 0x40;
    if (param_5 != (void *)0x0) {
      memcpy(piVar4 + 0x10,param_5,(ulonglong)uVar5);
    }
    iVar3 = IoWMIWriteEvent(piVar4);
    if (iVar3 < 0) {
      ExFreePoolWithTag(piVar4,0x4c696d57);
    }
    else {
      iVar3 = 0;
    }
  }
  if (param_5 != (void *)0x0) {
    ExFreePool(param_5);
  }
  return iVar3;
}



===== __report_gsfailure @ 1c00012b0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _guard_check_icall @ 1c00012d0 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 1c00012f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001330 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001360 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001390 =====

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



===== DllUnload @ 1c0007010 =====

undefined8 DllUnload(void)

{
                    /* 0x7010  2  DllUnload */
  return 0;
}



===== WmiSystemControl @ 1c0007020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WmiSystemControl(uint *param_1,longlong param_2,longlong param_3,undefined4 *param_4)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  longlong *plVar4;
  uint *puVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  code *pcVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong *puVar12;
  longlong *plVar13;
  longlong lVar14;
  ulonglong uVar15;
  int iVar16;
  uint *puVar17;
  bool bVar18;
  undefined8 in_stack_ffffffffffffff28;
  uint7 uVar20;
  undefined8 uVar19;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  ushort *local_90;
  ulonglong local_88;
  void *local_80;
  longlong local_78;
  ulonglong local_70;
  void *local_68;
  uint local_60;
  ulonglong local_58;
  ulonglong local_50;
  ulonglong local_48;
  ushort local_40 [12];
  
                    /* 0x7020  5  WmiSystemControl */
  lVar14 = *(longlong *)(param_3 + 0xb8);
  bVar1 = *(byte *)(lVar14 + 1);
  if ((9 < bVar1) && (bVar1 != 0xb)) {
    *param_4 = 2;
    return 0;
  }
  if ((*(longlong *)(lVar14 + 8) != param_2) || (param_1 == (uint *)0x0)) {
    *param_4 = 3;
    return (ulonglong)*(uint *)(param_3 + 0x30);
  }
  puVar17 = (uint *)0x0;
  *param_4 = 0;
  uVar7 = 0;
  uVar2 = *(uint *)(lVar14 + 0x18);
  uVar8 = 0;
  uVar10 = 0;
  puVar3 = *(uint **)(lVar14 + 0x20);
  if ((bVar1 != 8) && (bVar1 != 0xb)) {
    local_78 = *(longlong *)(param_1 + 2);
    do {
      if (*param_1 <= (uint)uVar8) {
        uVar8 = 0xc0000295;
LAB_1c0007211:
        *(int *)(param_3 + 0x30) = (int)uVar8;
        *param_4 = 1;
        return uVar8;
      }
      plVar13 = (longlong *)(uVar8 * 0x10 + local_78);
      plVar4 = (longlong *)*plVar13;
      lVar11 = **(longlong **)(lVar14 + 0x10) - *plVar4;
      if (lVar11 == 0) {
        lVar11 = (*(longlong **)(lVar14 + 0x10))[1] - plVar4[1];
      }
      if (lVar11 == 0) {
        uVar10 = *(uint *)(plVar13 + 1);
        if ((bVar1 != 9) && (2 < (byte)(bVar1 - 1))) {
          uVar7 = 0;
          break;
        }
        uVar7 = puVar3[0xd];
        if (((char)puVar3[0xb] < '\0') && (uVar7 < uVar10)) break;
        uVar8 = 0xc0000296;
        goto LAB_1c0007211;
      }
      uVar8 = (ulonglong)((uint)uVar8 + 1);
    } while( true );
  }
  if (bVar1 == 0) {
    if (uVar2 < 0x48) {
      *(undefined4 *)(param_3 + 0x30) = 0xc0000001;
      *(undefined8 *)(param_3 + 0x38) = 0;
      *param_4 = 1;
      return 0;
    }
    puVar3[0xb] = puVar3[0xb] & 0xffffffef;
    uVar7 = uVar10 * 8 + 0x40;
    puVar3[0xd] = uVar10;
    puVar3[0xc] = uVar7;
    if (uVar2 < uVar7) {
      lVar14 = 0;
      iVar16 = 0;
    }
    else {
      puVar17 = puVar3 + 0xf;
      lVar14 = (ulonglong)uVar7 + (longlong)puVar3;
      iVar16 = uVar2 - uVar7;
    }
    uVar7 = 0;
LAB_1c0007161:
    pcVar9 = *(code **)(param_1 + 6);
LAB_1c0007165:
    uVar8 = (*pcVar9)(param_2,param_3,uVar8,uVar7,uVar10,puVar17,iVar16,lVar14);
    return uVar8;
  }
  uVar20 = (uint7)((ulonglong)in_stack_ffffffffffffff28 >> 8);
  switch(bVar1) {
  case 1:
    puVar17 = puVar3 + 0xf;
    iVar16 = uVar2 - puVar3[0xe];
    lVar14 = (longlong)puVar3 + (ulonglong)puVar3[0xe];
    uVar10 = 1;
    goto LAB_1c0007161;
  case 2:
    if (*(code **)(param_1 + 8) != (code *)0x0) {
      uVar8 = (**(code **)(param_1 + 8))
                        (param_2,param_3,uVar8,uVar7,puVar3[0xf],
                         (ulonglong)puVar3[0xe] + (longlong)puVar3);
      return uVar8;
    }
  default:
switchD_1c00071ba_caseD_a:
    *(undefined8 *)(param_3 + 0x38) = 0;
    *(undefined4 *)(param_3 + 0x30) = 0xc0000010;
    *param_4 = 1;
    return 0xc0000010;
  case 3:
    if (*(code **)(param_1 + 10) != (code *)0x0) {
      uVar8 = (**(code **)(param_1 + 10))
                        (param_2,param_3,uVar8,uVar7,puVar3[0xe],puVar3[0x10],
                         (ulonglong)puVar3[0xf] + (longlong)puVar3);
      return uVar8;
    }
    goto switchD_1c00071ba_caseD_a;
  case 4:
    if (*(code **)(param_1 + 0xe) != (code *)0x0) {
      uVar8 = (**(code **)(param_1 + 0xe))(param_2,param_3,uVar8,0,CONCAT71(uVar20,1));
      return uVar8;
    }
    break;
  case 5:
    if (*(code **)(param_1 + 0xe) != (code *)0x0) {
      uVar8 = (**(code **)(param_1 + 0xe))(param_2,param_3,uVar8,0,(ulonglong)uVar20 << 8);
      return uVar8;
    }
    break;
  case 6:
    pcVar9 = *(code **)(param_1 + 0xe);
    if (pcVar9 != (code *)0x0) {
      uVar19 = CONCAT71(uVar20,1);
LAB_1c00073f8:
      uVar8 = (*pcVar9)(param_2,param_3,uVar8,1,uVar19);
      return uVar8;
    }
    break;
  case 7:
    pcVar9 = *(code **)(param_1 + 0xe);
    if (pcVar9 != (code *)0x0) {
      uVar19 = 0;
      goto LAB_1c00073f8;
    }
    break;
  case 8:
  case 0xb:
    local_58 = 0;
    local_90 = (ushort *)0x0;
    local_70 = 0;
    local_88 = 0;
    local_40[0] = 0;
    local_40[1] = 0;
    local_40[2] = 0;
    local_40[3] = 0;
    local_40[4] = 0;
    local_40[5] = 0;
    local_40[6] = 0;
    local_40[7] = 0;
    local_80 = (void *)0x0;
    local_68 = (void *)0x0;
    local_a4 = 0;
    local_9c = (**(code **)(param_1 + 4))(param_2,&local_a4,&local_88,&local_90,&local_70,&local_58)
    ;
    uVar8 = (ulonglong)local_9c;
    if (-1 < (int)local_9c) {
      if (((local_a4 & 0x20) != 0) || (local_80 != (void *)0x0)) {
        local_78 = *(longlong *)(param_1 + 2);
        uVar10 = *param_1;
        uVar15 = (ulonglong)uVar10;
        local_60 = uVar10 * 0x20 + 0x18;
        bVar18 = false;
        local_48 = local_58;
        if ((local_a4 & 0x20) == 0) {
          if ((local_a4 & 8) == 0) {
            local_a4 = local_a4 | 4;
          }
          iVar16 = (ushort)local_88 + 2;
          local_50 = (ulonglong)local_60;
        }
        else {
          bVar18 = bVar1 == 0xb;
          local_50 = local_58;
          iVar16 = 0;
        }
        uVar6 = local_50;
        if (local_90 == (ushort *)0x0) {
          local_90 = local_40;
        }
        local_a0 = local_60 + iVar16;
        local_98 = (ushort)local_70 + 2 + local_a0;
        local_94 = local_98 + 2 + (uint)*local_90;
        *puVar3 = local_94;
        if (uVar2 < local_94) {
          uVar10 = 4;
        }
        else {
          puVar3[1] = 0;
          puVar3[2] = local_98;
          puVar3[3] = local_a0;
          puVar3[4] = uVar10;
          if (uVar10 != 0) {
            if (!bVar18) {
              puVar12 = (ulonglong *)(puVar3 + 0xc);
              puVar17 = (uint *)(local_78 + 8);
              do {
                uVar8 = (*(ulonglong **)(puVar17 + -2))[1];
                puVar12[-3] = **(ulonglong **)(puVar17 + -2);
                puVar12[-2] = uVar8;
                *(uint *)(puVar12 + -1) = local_a4 | puVar17[1];
                *puVar12 = local_50;
                *(uint *)((longlong)puVar12 + -4) = *puVar17;
                uVar15 = uVar15 - 1;
                puVar12 = puVar12 + 4;
                puVar17 = puVar17 + 4;
              } while (uVar15 != 0);
            }
            else {
              puVar12 = (ulonglong *)(puVar3 + 0xc);
              puVar17 = (uint *)(local_78 + 8);
              do {
                puVar5 = *(uint **)(puVar17 + -2);
                uVar2 = puVar5[1];
                uVar10 = puVar5[2];
                uVar7 = puVar5[3];
                *(uint *)(puVar12 + -3) = *puVar5;
                *(uint *)((longlong)puVar12 + -0x14) = uVar2;
                *(uint *)(puVar12 + -2) = uVar10;
                *(uint *)((longlong)puVar12 + -0xc) = uVar7;
                *(uint *)(puVar12 + -1) = local_a4 | puVar17[1];
                *puVar12 = uVar6;
                *(uint *)((longlong)puVar12 + -4) = *puVar17;
                ObfReferenceObject(local_58);
                puVar12 = puVar12 + 4;
                puVar17 = puVar17 + 4;
                uVar15 = uVar15 - 1;
              } while (uVar15 != 0);
            }
          }
          uVar10 = local_94;
          uVar2 = local_98;
          if ((local_a4 & 0xc) != 0) {
            *(ushort *)((ulonglong)local_60 + (longlong)puVar3) = (ushort)local_88;
            memcpy((ushort *)((ulonglong)local_60 + (longlong)puVar3) + 1,local_80,local_88 & 0xffff
                  );
          }
          *(undefined2 *)((ulonglong)local_a0 + (longlong)puVar3) = (ushort)local_70;
          memcpy((undefined2 *)((ulonglong)local_a0 + (longlong)puVar3) + 1,local_68,
                 local_70 & 0xffff);
          *(ushort *)((ulonglong)uVar2 + (longlong)puVar3) = *local_90;
          memcpy((void *)((longlong)puVar3 + (ulonglong)uVar2 + 2),*(void **)(local_90 + 4),
                 (ulonglong)*local_90);
          uVar8 = (ulonglong)local_9c;
        }
        goto LAB_1c00072d3;
      }
      uVar8 = 0xc0000010;
      local_9c = 0xc0000010;
    }
    uVar10 = 0;
LAB_1c00072d3:
    if (local_80 != (void *)0x0) {
      ExFreePool(local_80);
      uVar8 = (ulonglong)local_9c;
    }
    *(ulonglong *)(param_3 + 0x38) = (ulonglong)uVar10;
    *(int *)(param_3 + 0x30) = (int)uVar8;
    *param_4 = 1;
    return uVar8;
  case 9:
    pcVar9 = *(code **)(param_1 + 0xc);
    if (pcVar9 == (code *)0x0) goto switchD_1c00071ba_caseD_a;
    iVar16 = uVar2 - puVar3[0xf];
    lVar14 = (longlong)puVar3 + (ulonglong)puVar3[0xf];
    puVar17 = (uint *)(ulonglong)puVar3[0x10];
    uVar10 = puVar3[0xe];
    goto LAB_1c0007165;
  }
  *(undefined4 *)(param_3 + 0x30) = 0;
  *(undefined8 *)(param_3 + 0x38) = 0;
  *param_4 = 1;
  return 0;
}



===== entry @ 1c0009010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c0009044 =====

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



===== DllInitialize @ 1c0009080 =====

undefined8 DllInitialize(void)

{
                    /* 0x9080  1  DllInitialize */
  __security_init_cookie();
  return 0;
}



===== DriverEntry @ 1c0009098 =====

undefined8 DriverEntry(void)

{
  return 0;
}


