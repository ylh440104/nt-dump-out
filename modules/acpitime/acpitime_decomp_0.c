
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



===== memcpy_s @ 1c0001020 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_1c000103d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_1c000107f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memcpy(_Dst,_Src,_MaxCount);
        goto LAB_1c000103d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_1c000107f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== _guard_check_icall @ 1c00010c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 1c00010e0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000114a) */
/* WARNING: Removing unreachable block (ram,0x0001c00010f9) */
/* WARNING: Removing unreachable block (ram,0x0001c00010ea) */

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



===== FxStubDriverUnloadCommon @ 1c00011a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005118 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0005118 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c0001201:
      if (ppvVar1 == (void **)0x0) goto LAB_1c0001257;
      if (ppvVar2 <= ppvVar1) goto LAB_1c000126f;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c0001201;
LAB_1c0001257:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c000126f:
  WdfVersionUnbind(&DAT_1c0005360,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c00012b0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c00012e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  _WDF_BIND_INFO *p_Var4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    uVar3 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1c0005360 = 0x2080000;
    _DAT_1c0005368 = &DAT_1c0005150;
    RtlCopyUnicodeString(&DAT_1c0005360);
    p_Var4 = param_1;
    uVar3 = WdfVersionBind(param_1,&DAT_1c0005360,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < (int)uVar3) {
      uVar1 = FxStubBindClasses(p_Var4);
      if ((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) {
        uVar1 = DriverEntry(param_1,param_2);
        if (-1 < (int)uVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c0005358 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",uVar1,&DAT_1c0005360);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005118 != &__KMDF_CLASS_BIND_START) {
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
      uVar3 = (ulonglong)uVar1;
    }
  }
  return uVar3;
}



===== FxStubDriverUnload @ 1c0001470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c0005358 != (code *)0x0) && (DAT_1c0005358 != FxStubDriverUnload)) {
    (*DAT_1c0005358)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c00014a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00014c9) */
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
    if ((void **)0x1c000510f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0005118 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c000162c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001649) */
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
    if ((void **)0x1c000512f < ppvVar2) break;
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



===== __GSHandlerCheck @ 1c00016f8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000171c =====

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



===== __security_check_cookie @ 1c0001790 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00017d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001800 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001830 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0001880 =====

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



===== memset @ 1c0001b80 =====

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



===== __memset_repmovs @ 1c0001cc0 =====

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



===== __memset_query @ 1c0001d40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0001dc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0001f00 =====

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



===== __memset_spec_plain @ 1c0001f80 =====

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



===== WaAcpiEvtDeviceWdmIrpQueryCapabilitiesCompletion @ 1c0008010 =====

undefined8 WaAcpiEvtDeviceWdmIrpQueryCapabilitiesCompletion(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  g_DeepestWakeSystemState =
       *(undefined4 *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) + 0x2c);
  return 0;
}



===== WaAcpiNotifyCallback @ 1c0008040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WaAcpiNotifyCallback(undefined8 param_1,int param_2)

{
  bool bVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  uint local_res10 [2];
  int local_res18 [2];
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  DbgPrint("WaAcpiNotifyCallback(%p, %#08lx)\n",param_1,param_2);
  if (param_2 != 2) {
    return;
  }
  bVar1 = false;
  uVar2 = WaGetWakeStatus(param_1,0,local_res10);
  uVar4 = 0;
  if ((-1 < (int)uVar2) && (bVar1 = true, (local_res10[0] & 2) != 0)) {
    uVar4 = 8;
  }
  uVar2 = WaGetWakeStatus(param_1,1,local_res10);
  if ((int)uVar2 < 0) {
    if (!bVar1) {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_WA_EXTENSION_TYPE_INFO_1c0005018);
      if (((*(uint *)(lVar3 + 0x58) & 8) != 0) &&
         ((uVar2 = WaIsAlarmExpired(param_1,0,local_res18), (int)uVar2 < 0 || (local_res18[0] != 0))
         )) {
        uVar4 = 8;
      }
      if (((*(uint *)(lVar3 + 0x58) & 0x10) != 0) &&
         ((uVar2 = WaIsAlarmExpired(param_1,1,local_res18), (int)uVar2 < 0 || (local_res18[0] != 0))
         )) {
        uVar4 = uVar4 | 0x10;
      }
      goto LAB_1c000815b;
    }
  }
  else if ((local_res10[0] & 2) != 0) {
    uVar4 = uVar4 | 0x10;
  }
  WaClearWakeStatus(param_1,0);
  WaClearWakeStatus(param_1,1);
LAB_1c000815b:
  PoSetFixedWakeSource(uVar4);
  return;
}



===== WaAcpiTimeWdmPreprocessQueryCapabilitiesIrp @ 1c0008190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WaAcpiTimeWdmPreprocessQueryCapabilitiesIrp(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  
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
  *(code **)(lVar2 + -0x10) = WaAcpiEvtDeviceWdmIrpQueryCapabilitiesCompletion;
  *(undefined8 *)(lVar2 + -8) = param_1;
  *(undefined1 *)(lVar2 + -0x45) = 0x40;
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== WaClearWakeStatus @ 1c0008208 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WaClearWakeStatus(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined1 auStack_c8 [32];
  undefined8 *local_a8;
  longlong *local_a0;
  undefined8 local_98;
  longlong *local_90;
  longlong local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 *local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  int local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_20 = 0;
  local_50 = &local_40;
  local_40 = 0x49696541;
  local_68 = &local_30;
  local_78[0] = 0;
  local_3c = 0x5357435f;
  local_30 = 0;
  uStack_28 = 0;
  local_58 = 1;
  local_48 = 0xc;
  local_78[1] = 1;
  local_60 = 0x14;
  local_38 = param_2;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  local_90 = local_78;
  local_a0 = local_78 + 1;
  local_98 = 0;
  local_a8 = &local_58;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar1,0,0x32c004);
  if (-1 < (int)uVar2) {
    if (((local_78[0] == 0x14) && ((int)uStack_28 == 1)) && (uStack_28._4_2_ == 0)) {
      uVar2 = (ulonglong)(-(uint)(local_20 != 0) & 0xc0000001);
    }
    else {
      uVar2 = 0xc0000001;
    }
  }
  return uVar2;
}



===== WaDeviceAdd @ 1c0008330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WaDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_1b8 [32];
  undefined8 *local_198;
  undefined4 local_190;
  undefined1 local_178 [8];
  undefined8 local_170;
  undefined8 local_168;
  undefined4 local_160;
  undefined4 local_15c;
  undefined8 local_158;
  ulonglong local_150 [6];
  undefined *local_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined1 local_10b;
  code *local_f0;
  undefined4 local_c8;
  undefined4 local_b8 [10];
  code *local_90;
  code *local_88;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_18 = 0;
  local_170 = 0;
  local_158 = 0;
  local_150[0] = (ulonglong)(uint)local_150[0];
  local_168 = param_2;
  memset(local_b8,0,0x90);
  local_90 = WaEvtDevicePrepareHardware;
  local_b8[0] = 0x90;
  local_88 = WaEvtDeviceReleaseHardware;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,param_2,local_b8);
  local_198 = (undefined8 *)local_178;
  local_178[0] = 9;
  local_190 = 1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,local_168,WaAcpiTimeWdmPreprocessQueryCapabilitiesIrp,0x1b);
  if (-1 < iVar1) {
    local_160 = 8;
    local_15c = 1;
    (**(code **)(WdfFunctions_01015 + 0xc98))(WdfDriverGlobals,local_168,&local_160);
    local_120 = PTR__WDF_WA_EXTENSION_TYPE_INFO_1c0005018;
    local_150[2] = 0;
    local_150[1] = 0;
    local_150[0] = 0x38;
    local_150[4] = 0;
    local_150[5] = 0;
    local_150[3] = 0x100000001;
    iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                      (WdfDriverGlobals,&local_168,local_150,&local_170);
    if (-1 < iVar1) {
      local_18 = 0;
      local_28 = 0x14;
      local_24 = 5;
      local_1c = 1;
      local_20 = 1;
      (**(code **)(WdfFunctions_01015 + 0x178))(WdfDriverGlobals,local_170,&local_28);
      memset(&local_118,0,0x60);
      local_c8 = 0xffffffff;
      local_110 = 0;
      local_198 = &local_158;
      local_f0 = WaIoDeviceControl;
      local_118 = 0x60;
      local_10b = 1;
      local_114 = 2;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_170,&local_118,0);
      if (-1 < iVar1) {
        (**(code **)(WdfFunctions_01015 + 0x268))
                  (WdfDriverGlobals,local_170,&GUID_DEVICE_ACPI_TIME,0);
      }
    }
  }
  return;
}



===== WaEvtDevicePrepareHardware @ 1c00085b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WaEvtDevicePrepareHardware(undefined8 param_1)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint local_res20 [2];
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_WA_EXTENSION_TYPE_INFO_1c0005018);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x418))
                    (WdfDriverGlobals,param_1,&GUID_ACPI_INTERFACE_STANDARD,lVar3,0x58,1,0);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
  iVar2 = (**(code **)(lVar3 + 0x48))(uVar5,WaAcpiNotifyCallback,param_1);
  if ((iVar2 < 0) && (*(code **)(lVar3 + 0x18) != (code *)0x0)) {
    (**(code **)(lVar3 + 0x18))(*(undefined8 *)(lVar3 + 8));
  }
  uVar4 = WaGetCapabilities(param_1,(uint *)(lVar3 + 0x5c));
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  uVar6 = 0;
  local_res20[0] = 0;
  bVar1 = false;
  if ((*(uint *)(lVar3 + 0x5c) & 0x10) == 0) {
    return uVar4 & 0xffffffff;
  }
  if (g_DeepestWakeSystemState != 6) {
    return uVar4 & 0xffffffff;
  }
  uVar5 = WaGetWakeStatus(param_1,0,local_res20);
  if (-1 < (int)uVar5) {
    bVar1 = true;
    uVar6 = 0;
    if ((local_res20[0] & 2) != 0) {
      uVar6 = 8;
    }
  }
  uVar4 = WaGetWakeStatus(param_1,1,local_res20);
  if ((int)uVar4 < 0) {
    if (!bVar1) goto LAB_1c0008710;
  }
  else if ((local_res20[0] & 2) != 0) {
    uVar6 = uVar6 | 0x10;
  }
  WaClearWakeStatus(param_1,0);
  WaClearWakeStatus(param_1,1);
LAB_1c0008710:
  PoSetFixedWakeSource(uVar6);
  return uVar4 & 0xffffffff;
}



===== WaEvtDeviceReleaseHardware @ 1c0008740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WaEvtDeviceReleaseHardware(undefined8 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_WA_EXTENSION_TYPE_INFO_1c0005018);
  if (*(longlong *)(lVar1 + 0x50) != 0) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
    (**(code **)(lVar1 + 0x50))(uVar2,WaAcpiNotifyCallback);
  }
  if (*(code **)(lVar1 + 0x18) != (code *)0x0) {
    (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 8));
  }
  return 0;
}



===== WaGetCapabilities @ 1c00087d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WaGetCapabilities(undefined8 param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined1 auStack_b8 [32];
  undefined8 *local_98;
  longlong *local_90;
  undefined8 local_88;
  longlong *local_80;
  undefined4 local_68;
  undefined4 local_64;
  longlong local_60 [2];
  undefined8 *local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_b8;
  local_68 = 0x42696541;
  local_18 = 0;
  local_38 = &local_68;
  local_64 = 0x5043475f;
  local_50 = &local_28;
  local_40 = 1;
  local_60[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = 8;
  local_60[1] = 1;
  local_48 = 0x14;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  local_80 = local_60;
  local_90 = local_60 + 1;
  local_88 = 0;
  local_98 = &local_40;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar1,0,0x32c004);
  if ((int)uVar1 < 0) {
    if ((int)uVar1 != -0x3fffffcc) {
      return uVar1;
    }
    *param_2 = 0xff;
  }
  else {
    if (((local_60[0] != 0x14) || ((int)uStack_20 != 1)) || (uStack_20._4_2_ != 0)) {
      return 0xc0000001;
    }
    *param_2 = local_18;
  }
  return 0;
}



===== WaGetWakeStatus @ 1c0008910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WaGetWakeStatus(undefined8 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  undefined1 auStack_c8 [32];
  undefined8 *local_a8;
  longlong *local_a0;
  undefined8 local_98;
  longlong *local_90;
  longlong local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 *local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_20 = 0;
  local_50 = &local_40;
  local_40 = 0x49696541;
  local_68 = &local_30;
  local_78[0] = 0;
  local_3c = 0x5357475f;
  local_30 = 0;
  uStack_28 = 0;
  local_58 = 1;
  local_48 = 0xc;
  local_78[1] = 1;
  local_60 = 0x14;
  local_38 = param_2;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  local_90 = local_78;
  local_a0 = local_78 + 1;
  local_98 = 0;
  local_a8 = &local_58;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar1,0,0x32c004);
  if (-1 < (int)uVar1) {
    if (((local_78[0] == 0x14) && ((int)uStack_28 == 1)) && (uStack_28._4_2_ == 0)) {
      *param_3 = local_20;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc0000001;
    }
  }
  return uVar1;
}



===== WaHandleAcpiGetDeviceCapabilities @ 1c0008a40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WaHandleAcpiGetDeviceCapabilities(undefined8 param_1,byte *param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_WA_EXTENSION_TYPE_INFO_1c0005018);
  uVar2 = *(uint *)(lVar1 + 0x5c);
  *(undefined4 *)(param_2 + 8) = g_DeepestWakeSystemState;
  *param_2 = (byte)uVar2 & 1;
  param_2[1] = (byte)(uVar2 >> 1) & 1;
  param_2[2] = (byte)(uVar2 >> 5) & 1;
  param_2[3] = (byte)(uVar2 >> 7) & 1;
  param_2[4] = (byte)(uVar2 >> 6) & 1;
  param_2[5] = (byte)(uVar2 >> 8) & 1;
  param_2[6] = (byte)(uVar2 >> 4) & 1;
  bVar3 = (uVar2 & 4) == 0;
  if (bVar3) {
    uVar2 = 2;
  }
  else {
    uVar2 = ~(uVar2 >> 3) & 1;
  }
  param_2[0xc] = !bVar3;
  *(uint *)(param_2 + 0x10) = uVar2;
  *param_3 = 0x14;
  return 0;
}



===== WaHandleAcpiGetRealTime @ 1c0008afc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WaHandleAcpiGetRealTime(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 auStack_e8 [32];
  undefined4 *local_c8;
  undefined4 *local_c0;
  undefined8 local_b8;
  ulonglong *local_b0;
  undefined4 local_98;
  undefined4 local_94;
  ulonglong local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_e8;
  local_90 = 0;
  local_6c = 0;
  local_84 = 0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_WA_EXTENSION_TYPE_INFO_1c0005018);
  if ((*(uint *)(lVar1 + 0x5c) & 4) == 0) {
    uVar2 = 0xc00000bb;
  }
  else {
    local_6c = 0;
    local_68 = &local_98;
    local_5c = 0;
    local_84 = 0;
    local_74 = 0;
    local_38 = 0;
    local_80 = &local_58;
    local_98 = 0x42696541;
    local_94 = 0x5452475f;
    local_70 = 1;
    local_60 = 8;
    local_58 = 0;
    uStack_50 = 0;
    local_88 = 1;
    local_48 = 0;
    uStack_40 = 0;
    local_78 = 0x24;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
    local_b0 = &local_90;
    local_b8 = 0;
    local_c0 = &local_88;
    local_c8 = &local_70;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x32c004);
    if (-1 < (int)uVar2) {
      if ((((local_90 < 0x14) || ((int)local_58 != 0x426f6541)) || ((int)uStack_50 != 1)) ||
         (((uStack_50._4_2_ != 2 || (uStack_50._6_2_ != 0x10)) || (local_48._7_1_ == '\0')))) {
        uVar2 = 0xc0000001;
      }
      else {
        *param_2 = local_48;
        param_2[1] = uStack_40;
        if ((*(uint *)(lVar1 + 0x5c) & 8) == 0) {
          *(undefined2 *)(param_2 + 1) = 500;
        }
        *param_3 = 0x10;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



===== WaHandleAcpiSetRealTime @ 1c0008ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WaHandleAcpiSetRealTime(undefined8 param_1,void *param_2,undefined4 *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined1 auStack_f8 [32];
  ulonglong *local_d8;
  ulonglong *local_d0;
  undefined8 local_c8;
  ulonglong *local_c0;
  ulonglong local_a8;
  ulonglong local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  ulonglong local_88;
  undefined4 *local_80;
  int local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  int local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined1 local_44 [20];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_f8;
  local_a8 = 0;
  local_88 = (ulonglong)(uint)local_88;
  local_a0 = (ulonglong)(uint)local_a0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_WA_EXTENSION_TYPE_INFO_1c0005018);
  uVar3 = 4;
  if ((*(uint *)(lVar1 + 0x5c) & 4) == 0) {
    uVar2 = 0xc00000bb;
  }
  else {
    local_58 = 0x43696541;
    local_50 = 0x10;
    local_54 = 0x5452535f;
    local_48 = 0x100002;
    memcpy_s(local_44,0x10,param_2,0x10);
    if (3 < local_48._2_2_) {
      uVar3 = (uint)local_48._2_2_;
    }
    local_60 = 0;
    local_78 = (int)local_50 + 4 + uVar3;
    local_74 = 0;
    local_50 = CONCAT44(local_50._4_4_ + 1,local_78);
    local_80 = &local_58;
    local_98 = &local_70;
    local_70 = 0;
    uStack_68 = 0;
    local_88 = 1;
    local_a0 = 1;
    local_90 = 0x14;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
    local_c0 = &local_a8;
    local_d0 = &local_a0;
    local_c8 = 0;
    local_d8 = &local_88;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x32c004);
    if (-1 < (int)uVar2) {
      if ((((local_a8 < 0x14) || ((int)local_70 != 0x426f6541)) || ((int)uStack_68 != 1)) ||
         ((uStack_68._4_2_ != 0 || (local_60 != 0)))) {
        uVar2 = 0xc0000001;
      }
      else {
        *param_3 = 0;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



===== WaHandleWakeAlarmControl @ 1c0008e58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
WaHandleWakeAlarmControl
          (undefined8 param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined1 auStack_108 [32];
  undefined8 *local_e8;
  longlong *local_e0;
  undefined8 local_d8;
  longlong *local_d0;
  longlong local_b8 [2];
  undefined8 *puStack_a8;
  ulonglong local_a0;
  undefined8 local_98;
  undefined4 *puStack_90;
  int local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  int local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined4 local_58;
  int local_54 [3];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  local_70 = 0;
  local_88 = 0;
  local_a0 = local_a0 & 0xffffffff00000000;
  local_b8[0] = 0;
  local_68 = 0x43696541;
  local_80 = 0;
  uStack_78 = 0;
  local_98 = 0;
  puStack_90 = (undefined4 *)0x0;
  local_b8[1] = 0;
  puStack_a8 = (undefined8 *)0x0;
  if (param_2 == 0x298200) {
    local_64 = 0x5654535f;
  }
  else if (param_2 == 0x298204) {
    local_64 = 0x5054535f;
  }
  else if (param_2 == 0x29c208) {
    local_64 = 0x5649545f;
  }
  else {
    local_64 = 0x5049545f;
  }
  local_54[0] = *param_3;
  local_58 = 0x40000;
  local_60 = 0x100000018;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_WA_EXTENSION_TYPE_INFO_1c0005018);
  if ((*param_3 != 0) && (*param_3 != 1)) {
    return 0xc000000d;
  }
  if ((*(uint *)(lVar1 + 0x5c) & 499) == 0) {
LAB_1c00090a6:
    uVar2 = 0xc00000bb;
  }
  else {
    if ((param_2 - 0x298200U & 0xfffffffb) == 0) {
      uVar3 = 4;
      if (3 < local_58._2_2_) {
        uVar3 = (ulonglong)local_58._2_2_;
      }
      *(undefined4 *)((longlong)local_54 + uVar3) = 0x40000;
      *(int *)((longlong)local_54 + uVar3 + 4) = param_3[1];
      local_88 = (int)local_60 + 8;
      local_60 = CONCAT44(local_60._4_4_ + 1,local_88);
    }
    else {
      local_88 = (int)local_60;
    }
    puStack_90 = &local_68;
    local_84 = 0;
    puStack_a8 = &local_80;
    local_98 = 1;
    local_b8[1] = 1;
    local_a0 = 0x14;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
    local_d0 = local_b8;
    local_e0 = local_b8 + 1;
    local_d8 = 0;
    local_e8 = &local_98;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x32c004);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (((local_b8[0] != 0x14) || ((int)uStack_78 != 1)) || (uStack_78._4_2_ != 0)) {
      return 0xc0000001;
    }
    if ((param_2 - 0x29c208U & 0xfffffffb) == 0) {
      *param_4 = *param_3;
      param_4[1] = local_70;
      *param_5 = 8;
    }
    else {
      if (local_70 != 0) goto LAB_1c00090a6;
      *param_5 = 0;
      if (param_2 == 0x298200) {
        uVar4 = 8;
        if (*param_3 != 0) {
          uVar4 = 0x10;
        }
        if (param_3[1] == -1) {
          uVar4 = ~uVar4 & *(uint *)(lVar1 + 0x58);
        }
        else {
          uVar4 = uVar4 | *(uint *)(lVar1 + 0x58);
        }
        *(uint *)(lVar1 + 0x58) = uVar4;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== WaIoDeviceControl @ 1c00090e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WaIoDeviceControl(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,
                      int param_5)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_38 [2];
  ulonglong local_30;
  byte *local_28;
  ulonglong local_20;
  int *local_18 [2];
  
  local_18[0] = (int *)0x0;
  local_20 = 0;
  local_28 = (byte *)0x0;
  local_30 = 0;
  local_38[0] = 0;
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals);
  if (cVar1 != '\0') {
LAB_1c000913d:
    iVar2 = -0x3ffffff0;
    goto LAB_1c000932b;
  }
  if (((param_4 != 0) &&
      (iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))
                         (WdfDriverGlobals,param_2,param_4,local_18,&local_20), iVar2 < 0)) ||
     ((param_3 != 0 &&
      (iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                         (WdfDriverGlobals,param_2,param_3,&local_28,&local_30), iVar2 < 0))))
  goto LAB_1c000932b;
  if (param_5 == 0x294210) {
    if (0xf < local_30) {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      uVar3 = WaHandleAcpiGetRealTime(uVar3,(undefined8 *)local_28,local_38);
      iVar2 = (int)uVar3;
      goto LAB_1c000932b;
    }
  }
  else if (param_5 == 0x294218) {
    if (3 < local_30) {
      iVar2 = 0;
      local_38[0] = 4;
      *(int *)local_28 = g_DeepestWakeSystemState;
      goto LAB_1c000932b;
    }
  }
  else if (param_5 == 0x29421c) {
    if (local_30 == 0x14) {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      uVar3 = WaHandleAcpiGetDeviceCapabilities(uVar3,local_28,local_38);
      iVar2 = (int)uVar3;
      goto LAB_1c000932b;
    }
  }
  else if ((param_5 == 0x298200) || (param_5 == 0x298204)) {
LAB_1c000924e:
    if (local_20 == 8) {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      uVar3 = WaHandleWakeAlarmControl(uVar3,param_5,local_18[0],(int *)local_28,local_38);
      iVar2 = (int)uVar3;
      goto LAB_1c000932b;
    }
  }
  else if (param_5 == 0x298214) {
    if (0xf < local_20) {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
      uVar3 = WaHandleAcpiSetRealTime(uVar3,local_18[0],local_38);
      iVar2 = (int)uVar3;
      goto LAB_1c000932b;
    }
  }
  else {
    if ((param_5 != 0x29c208) && (param_5 != 0x29c20c)) goto LAB_1c000913d;
    if (local_30 == 8) goto LAB_1c000924e;
  }
  iVar2 = -0x3ffffffc;
LAB_1c000932b:
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar2,local_38[0]);
  return;
}



===== WaIsAlarmExpired @ 1c0009370 =====

undefined8 WaIsAlarmExpired(undefined8 param_1,uint param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  undefined4 local_res10 [4];
  undefined8 local_res20;
  
  local_res10[0] = 0;
  local_res20 = (ulonglong)param_2;
  uVar1 = WaHandleWakeAlarmControl
                    (param_1,0x29c208,(int *)&local_res20,(int *)&local_res20,local_res10);
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  if (local_res20._4_4_ == -1) {
    local_res20._0_4_ = param_2;
    uVar1 = WaHandleWakeAlarmControl
                      (param_1,0x29c20c,(int *)&local_res20,(int *)&local_res20,local_res10);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (local_res20._4_4_ == -1) {
      *param_3 = 1;
      return 0;
    }
  }
  *param_3 = 0;
  return 0;
}



===== __security_init_cookie @ 1c000a008 =====

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



===== DriverEntry @ 1c000a03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_28;
  code *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0x20;
  g_DeepestWakeSystemState = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = WaDeviceAdd;
  (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_28,0);
  return;
}


