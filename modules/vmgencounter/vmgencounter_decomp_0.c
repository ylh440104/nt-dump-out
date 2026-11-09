
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



===== __C_specific_handler @ 1c000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== GenCounterAcpiNotification @ 1c0001030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GenCounterAcpiNotification(longlong param_1,int param_2)

{
  if (param_2 == 0x80) {
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  }
  return;
}



===== GenCounterFastDeviceControl @ 1c0001070 =====

ulonglong GenCounterFastDeviceControl(void)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  char cVar4;
  ulonglong in_RAX;
  ulonglong uVar5;
  int in_R9D;
  longlong *in_stack_00000028;
  uint in_stack_00000030;
  int in_stack_00000038;
  undefined4 *in_stack_00000040;
  longlong in_stack_00000048;
  
  if (((in_stack_00000038 == 0x32c004) && (in_R9D == 0)) && (0xf < in_stack_00000030)) {
    plVar1 = *(longlong **)(in_stack_00000048 + 0x40);
    cVar4 = ExGetPreviousMode();
    if (cVar4 == '\0') {
      plVar1 = (longlong *)*plVar1;
      do {
        do {
          lVar3 = plVar1[1];
        } while (*plVar1 != *plVar1);
      } while (lVar3 != plVar1[1]);
      *in_stack_00000028 = *plVar1;
      in_stack_00000028[1] = lVar3;
    }
    else {
      ProbeForWrite(in_stack_00000028,0x10,1);
      puVar2 = (undefined8 *)*plVar1;
      do {
        do {
          lVar3 = puVar2[1];
          plVar1 = (longlong *)*puVar2;
        } while ((longlong *)*puVar2 != plVar1);
      } while (lVar3 != puVar2[1]);
      *in_stack_00000028 = (longlong)*puVar2;
      in_stack_00000028[1] = lVar3;
      in_stack_00000028 = plVar1;
    }
    *(undefined8 *)(in_stack_00000040 + 2) = 0x10;
    *in_stack_00000040 = 0;
    uVar5 = CONCAT71((int7)((ulonglong)in_stack_00000028 >> 8),1);
  }
  else {
    uVar5 = in_RAX & 0xffffffffffffff00;
  }
  return uVar5;
}



===== GenCounterReadCounter @ 1c0001164 =====

void GenCounterReadCounter(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = (longlong *)*param_1;
  do {
    do {
      lVar2 = plVar1[1];
    } while (*plVar1 != *plVar1);
  } while (lVar2 != plVar1[1]);
  *param_2 = *plVar1;
  param_2[1] = lVar2;
  return;
}



===== FxStubDriverUnloadCommon @ 1c0001190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0004258 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0004258 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c00011e9:
      if (ppvVar1 == (void **)0x0) goto LAB_1c000123f;
      if (ppvVar2 <= ppvVar1) goto LAB_1c0001257;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c00011e9;
LAB_1c000123f:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0001257:
  WdfVersionUnbind(&DAT_1c00044a0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0001290 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c00012c4 =====

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
    _DAT_1c00044a0 = 0x2080000;
    _DAT_1c00044a8 = &DAT_1c0004290;
    RtlCopyUnicodeString(&DAT_1c00044a0);
    p_Var4 = param_1;
    uVar3 = WdfVersionBind(param_1,&DAT_1c00044a0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < (int)uVar3) {
      uVar1 = FxStubBindClasses(p_Var4);
      if ((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) {
        uVar1 = DriverEntry((longlong)param_1,param_2);
        if (-1 < (int)uVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c0004498 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",uVar1,&DAT_1c00044a0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0004258 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0001450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c0004498 != (code *)0x0) && (DAT_1c0004498 != FxStubDriverUnload)) {
    (*DAT_1c0004498)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0001484 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00014a9) */
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
    if ((void **)0x1c000424f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0004258 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c000160c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001629) */
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
    if ((void **)0x1c000426f < ppvVar2) break;
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



===== _guard_check_icall @ 1c00016e0 =====

void _guard_check_icall(void)

{
  return;
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



===== __cpu_features_init @ 1c0001790 =====

/* WARNING: Removing unreachable block (ram,0x0001c00017fa) */
/* WARNING: Removing unreachable block (ram,0x0001c00017a9) */
/* WARNING: Removing unreachable block (ram,0x0001c000179a) */

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



===== __security_check_cookie @ 1c0001860 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00018a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00018d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00018d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001900 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 1c0001980 =====

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



===== __memset_repmovs @ 1c0001ac0 =====

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



===== __memset_query @ 1c0001b40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0001bc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0001d00 =====

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



===== __memset_spec_plain @ 1c0001d80 =====

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



===== GenCounterCleanup @ 1c0007010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GenCounterCleanup(undefined8 param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_GENCOUNTER_EXTENSION_TYPE_INFO_1c00040f8);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x520))(WdfDriverGlobals,uVar2);
  (**(code **)(WdfFunctions_01015 + 0x520))(WdfDriverGlobals,plVar1[3]);
  if ((char)plVar1[0x10] != '\0') {
    (*(code *)plVar1[0xf])(plVar1[6]);
    *(undefined1 *)(plVar1 + 0x10) = 0;
  }
  if ((code *)plVar1[8] != (code *)0x0) {
    (*(code *)plVar1[8])(plVar1[6]);
    plVar1[8] = 0;
  }
  if (*plVar1 != 0) {
    MmUnmapIoSpace(*plVar1,0x10);
    *plVar1 = 0;
  }
  return;
}



===== GenCounterDeviceAdd @ 1c0007110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GenCounterDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined1 auStack_288 [32];
  undefined8 *local_268;
  undefined8 local_258;
  undefined8 local_250;
  undefined4 local_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 local_238;
  undefined4 uStack_234;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined *local_218;
  undefined8 local_210;
  undefined8 local_208;
  wchar_t *local_200;
  undefined8 local_1f8;
  wchar_t *local_1f0;
  ulonglong local_1e8;
  code *pcStack_1e0;
  undefined8 local_1d8;
  ulonglong local_1d0 [6];
  undefined *local_1a0;
  undefined4 local_198;
  undefined8 local_194;
  undefined1 local_18c;
  undefined1 local_18b;
  code *local_170;
  undefined4 local_148;
  undefined4 local_138;
  undefined4 local_134;
  code *local_100;
  code *local_f0;
  wchar_t local_a8 [32];
  wchar_t local_68 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_288;
  uStack_244 = 0;
  builtin_wcsncpy(local_a8,L"\\Device\\VmGenerationCounter",0x1c);
  local_134 = 0;
  local_1d0[0] = (ulonglong)(uint)local_1d0[0];
  local_1e8 = (ulonglong)(uint)local_1e8;
  local_200 = local_a8;
  local_1f0 = local_68;
  builtin_wcsncpy(local_68,L"\\DosDevices\\VmGenerationCounter",0x20);
  local_258 = 0;
  local_210 = 0;
  local_208 = 0x380036;
  local_1f8 = 0x40003e;
  local_250 = param_2;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,0x6f0043,&local_208);
  if (-1 < (int)uVar4) {
    memset(&local_138,0,0x90);
    local_f0 = GenCounterInit;
    local_100 = GenCounterCleanup;
    local_138 = 0x90;
    (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_250,&local_138);
    local_238 = 0;
    uStack_234 = 0;
    local_218 = PTR__WDF_GENCOUNTER_REQUEST_CONTEXT_TYPE_INFO_1c0004120;
    uStack_244 = 0;
    uStack_240 = 0;
    uStack_23c = 0;
    local_248 = 0x38;
    local_228 = 0;
    uStack_220 = 0;
    uStack_230 = 0x100000001;
    (**(code **)(WdfFunctions_01015 + 0x240))(WdfDriverGlobals,local_250,&local_248);
    local_1a0 = PTR__WDF_GENCOUNTER_EXTENSION_TYPE_INFO_1c00040f8;
    local_1d0[2] = 0;
    local_1d0[1] = 0;
    local_1d0[0] = 0x38;
    local_1d0[4] = 0;
    local_1d0[5] = 0;
    local_1d0[3] = 0x100000001;
    uVar4 = (**(code **)(WdfFunctions_01015 + 600))
                      (WdfDriverGlobals,&local_250,local_1d0,&local_258);
    if (-1 < (int)uVar4) {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_258,
                         PTR__WDF_GENCOUNTER_EXTENSION_TYPE_INFO_1c00040f8);
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x268))
                        (WdfDriverGlobals,local_258,&GUID_DEVINTERFACE_VM_GENCOUNTER,0);
      if (-1 < (int)uVar4) {
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x280))(WdfDriverGlobals,local_258,&local_1f8);
        if (-1 < (int)uVar4) {
          memset(&local_198,0,0x60);
          local_148 = 0xffffffff;
          local_268 = &local_210;
          local_170 = GenCounterDeviceControl;
          local_198 = 0x60;
          local_18b = 1;
          local_194 = 2;
          uVar4 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_258,&local_198,0)
          ;
          if (-1 < (int)uVar4) {
            (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,local_210,0,0);
            memset(&local_18c,0,0x54);
            local_268 = (undefined8 *)(lVar2 + 0x18);
            local_198 = 0x60;
            local_194 = 3;
            uVar4 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                              (WdfDriverGlobals,local_258,&local_198,0);
            if (-1 < (int)uVar4) {
              uStack_234 = 0;
              local_1d8 = 1;
              local_1e8 = 0x18;
              pcStack_1e0 = GenCounterNotificationWorkerRoutine;
              local_218 = PTR__WDF_GENCOUNTER_WORKITEM_CONTEXT_TYPE_INFO_1c0004148;
              local_228 = local_258;
              uStack_244 = 0;
              uStack_240 = 0;
              uStack_23c = 0;
              local_238 = 0;
              uStack_220 = 0;
              local_248 = 0x38;
              uStack_230 = 0x100000001;
              uVar4 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                                (WdfDriverGlobals,&local_1e8,&local_248,lVar2 + 0x20);
              if (-1 < (int)uVar4) {
                plVar3 = (longlong *)
                         (**(code **)(WdfFunctions_01015 + 0x650))
                                   (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x20),
                                    PTR__WDF_GENCOUNTER_WORKITEM_CONTEXT_TYPE_INFO_1c0004148);
                *plVar3 = lVar2;
                local_218 = (undefined *)0x0;
                local_238 = 0;
                uStack_234 = 0;
                uStack_220 = 0;
                local_228 = local_258;
                uStack_244 = 0;
                uStack_240 = 0;
                uStack_23c = 0;
                local_248 = 0x38;
                uStack_230 = 0x100000001;
                uVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                                  (WdfDriverGlobals,&local_248,lVar2 + 0x88);
                uVar4 = (ulonglong)uVar1;
                if (-1 < (int)uVar1) {
                  uVar4 = 0;
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar4;
}



===== GenCounterDeviceControl @ 1c00075d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GenCounterDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *local_18;
  longlong *local_10;
  
  local_10 = (longlong *)0x0;
  local_18 = (longlong *)0x0;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar4,PTR__WDF_GENCOUNTER_EXTENSION_TYPE_INFO_1c00040f8);
  if (param_5 == 0x32c004) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x10,&local_18,0);
    if (-1 < iVar3) {
      if (param_4 == 0) {
        GenCounterReadCounter(plVar5,local_18);
        (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x10);
        iVar3 = 0;
        goto LAB_1c0007818;
      }
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x10,&local_10,0);
      if (-1 < iVar3) {
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar5[0x11],0);
        if ((plVar5[1] == *local_10) && (plVar5[2] == local_10[1])) {
          lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_2,
                             PTR__WDF_GENCOUNTER_REQUEST_CONTEXT_TYPE_INFO_1c0004120);
          *(undefined8 *)(lVar6 + 0x10) = param_2;
          *(longlong **)(lVar6 + 0x18) = local_18;
          iVar3 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2,plVar5[3]);
          if (iVar3 < 0) {
            (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,plVar5[0x11]);
            goto LAB_1c0007818;
          }
          iVar3 = 0x103;
        }
        else {
          uVar1 = *(undefined4 *)((longlong)plVar5 + 0xc);
          lVar6 = plVar5[2];
          uVar2 = *(undefined4 *)((longlong)plVar5 + 0x14);
          *(int *)local_18 = (int)plVar5[1];
          *(undefined4 *)((longlong)local_18 + 4) = uVar1;
          *(int *)(local_18 + 1) = (int)lVar6;
          *(undefined4 *)((longlong)local_18 + 0xc) = uVar2;
          (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x10);
          iVar3 = 0;
        }
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,plVar5[0x11]);
      }
    }
    if (iVar3 == 0x103) {
      return;
    }
  }
  else {
    iVar3 = -0x3fffff45;
  }
LAB_1c0007818:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar3);
  return;
}



===== GenCounterInit @ 1c0007860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GenCounterInit(undefined8 param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 auStack_e8 [32];
  undefined8 *local_c8;
  undefined8 *local_c0;
  undefined8 local_b8;
  undefined8 *local_b0;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined4 *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_e8;
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_GENCOUNTER_EXTENSION_TYPE_INFO_1c00040f8);
  local_88 = 0;
  *plVar1 = 0;
  local_60 = &local_90;
  local_30 = 0;
  local_78 = &local_50;
  local_90 = 0x42696541;
  local_8c = 0x52444441;
  local_68 = 1;
  local_58 = 8;
  local_50 = 0;
  uStack_48 = 0;
  local_80 = 1;
  local_40 = 0;
  uStack_38 = 0;
  local_70 = 0x24;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  local_b0 = &local_88;
  local_c0 = &local_80;
  local_b8 = 0;
  local_c8 = &local_68;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x32c004);
  if (-1 < (int)uVar2) {
    if ((int)local_50 == 0x426f6541) {
      if (((int)uStack_48 == 2) && (uStack_48._4_2_ == 0)) {
        local_98 = (undefined4)local_40;
        uStack_94 = *(undefined4 *)((longlong)&local_40 + (uStack_48 >> 0x30) + 4);
        ZwSetSystemInformation(0xa1,&local_98,8);
        lVar3 = MmMapIoSpaceEx(CONCAT44(uStack_94,local_98),0x10,2);
        *plVar1 = lVar3;
        if (lVar3 == 0) {
          uVar2 = 0xc000009a;
        }
        else {
          local_b8 = 0;
          local_c0 = (undefined8 *)CONCAT62(local_c0._2_6_,1);
          local_c8 = (undefined8 *)CONCAT62(local_c8._2_6_,0x58);
          uVar2 = (**(code **)(WdfFunctions_01015 + 0x418))
                            (WdfDriverGlobals,param_1,&GUID_ACPI_INTERFACE_STANDARD2,plVar1 + 5);
          if (-1 < (int)uVar2) {
            uVar2 = (*(code *)plVar1[0xe])(plVar1[6],GenCounterAcpiNotification,plVar1);
            if (-1 < (int)uVar2) {
              *(undefined1 *)(plVar1 + 0x10) = 1;
              (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar1[0x11],0);
              GenCounterReadCounter(plVar1,plVar1 + 1);
              (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,plVar1[0x11]);
              uVar2 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,param_1);
              (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,uVar2);
              uVar2 = 0;
            }
          }
        }
      }
      else {
        uVar2 = 0xc000000d;
      }
    }
    else {
      uVar2 = 0xc0000225;
    }
  }
  return uVar2;
}



===== GenCounterNotificationWorkerRoutine @ 1c0007b20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GenCounterNotificationWorkerRoutine(undefined8 param_1)

{
  longlong ***ppplVar1;
  longlong *plVar2;
  longlong **pplVar3;
  code *pcVar4;
  longlong *plVar5;
  longlong *plVar6;
  char cVar7;
  int iVar8;
  undefined8 *puVar9;
  longlong ***ppplVar10;
  char *pcVar11;
  undefined8 local_res10 [3];
  longlong ***local_38;
  longlong ***local_30;
  longlong *local_28;
  longlong *plStack_20;
  
  local_res10[0] = 0;
  local_28 = (longlong *)0x0;
  plStack_20 = (longlong *)0x0;
  puVar9 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_GENCOUNTER_WORKITEM_CONTEXT_TYPE_INFO_1c0004148);
  plVar2 = (longlong *)*puVar9;
  local_30 = (longlong ***)&local_38;
  local_38 = (longlong ***)&local_38;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar2[0x11],0);
  GenCounterReadCounter(plVar2,(longlong *)&local_28);
  plVar6 = plStack_20;
  plVar5 = local_28;
  if ((local_28 == (longlong *)plVar2[1]) && (plStack_20 == (longlong *)plVar2[2])) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,plVar2[0x11]);
  }
  else {
    plVar2[1] = (longlong)local_28;
    plVar2[2] = (longlong)plStack_20;
    while( true ) {
      iVar8 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals,plVar2[3],local_res10);
      if (iVar8 != 0) break;
      ppplVar10 = (longlong ***)
                  (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,local_res10[0],
                             PTR__WDF_GENCOUNTER_REQUEST_CONTEXT_TYPE_INFO_1c0004120);
      pplVar3 = ppplVar10[3];
      *pplVar3 = plVar5;
      pplVar3[1] = plVar6;
      if ((longlong ****)*local_30 != &local_38) goto LAB_1c0007cd8;
      ppplVar10[1] = (longlong **)local_30;
      *ppplVar10 = (longlong **)&local_38;
      *local_30 = (longlong **)ppplVar10;
      local_30 = ppplVar10;
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,plVar2[0x11]);
    while ((longlong ****)local_38 != &local_38) {
      if (((longlong ****)local_38[1] != &local_38) ||
         (ppplVar10 = (longlong ***)*local_38, (longlong ***)ppplVar10[1] != local_38)) {
LAB_1c0007cd8:
        pcVar4 = (code *)swi(0x29);
        pcVar11 = (char *)(*pcVar4)(3);
        cVar7 = (char)pcVar11;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        *pcVar11 = *pcVar11 + cVar7;
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      ppplVar10[1] = (longlong **)&local_38;
      ppplVar1 = local_38 + 2;
      local_38 = ppplVar10;
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,*ppplVar1,0,0x10);
    }
  }
  return;
}



===== __security_init_cookie @ 1c0008008 =====

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



===== DriverEntry @ 1c000803c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_24 = 0;
  local_28 = 0x20;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = GenCounterDeviceAdd;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_28,0);
  if (-1 < iVar1) {
    *(undefined **)(param_1 + 0x50) = &GenCounterFastIoDispatch;
  }
  return;
}


