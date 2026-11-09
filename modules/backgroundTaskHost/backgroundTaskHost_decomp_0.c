
===== pre_c_init @ 140001010 =====

/* WARNING: Removing unreachable block (ram,0x000140001068) */
/* WARNING: Removing unreachable block (ram,0x000140001022) */
/* WARNING: Removing unreachable block (ram,0x000140001070) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 pre_c_init(void)

{
  int iVar1;
  
  DAT_1400050c0 = 0;
  iVar1 = _get_image_app_type(1);
  __set_app_type(iVar1);
  ___onexitend = 0xffffffffffffffff;
  ___onexitbegin = 0xffffffffffffffff;
  *(undefined4 *)_fmode_exref = _fmode;
  *(undefined4 *)_commode_exref = _commode;
  _setargv();
  if (__defaultmatherr == 0) {
    __setusermatherr(_setargv);
  }
  return 0;
}



===== pre_cpp_init @ 1400010f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pre_cpp_init(void)

{
  _DAT_1400050c4 = _newmode;
  _DAT_1400050ac =
       __getmainargs(&DAT_1400050a8,&DAT_1400050b0,&DAT_1400050b8,_dowildcard,&DAT_1400050c4);
  return;
}



===== __mainCRTStartup @ 140001140 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __mainCRTStartup(void)

{
  void *pvVar1;
  bool bVar2;
  int iVar3;
  BOOL BVar4;
  void *pvVar5;
  longlong *plVar6;
  bool bVar7;
  
  pvVar1 = StackBase;
  bVar2 = false;
  while( true ) {
    pvVar5 = (void *)0x0;
    LOCK();
    bVar7 = __native_startup_lock == (void *)0x0;
    if (bVar7) {
      __native_startup_lock = pvVar1;
    }
    else {
      pvVar5 = __native_startup_lock;
    }
    UNLOCK();
    if (bVar7) goto LAB_140001191;
    if (pvVar5 == pvVar1) break;
    Sleep(1000);
  }
  bVar2 = true;
LAB_140001191:
  if (__native_startup_state == 1) {
    _amsg_exit(0x1f);
  }
  else if (__native_startup_state == 0) {
    __native_startup_state = 1;
    iVar3 = 0;
    for (plVar6 = &__xi_a; plVar6 < &__xi_z; plVar6 = plVar6 + 1) {
      if (iVar3 != 0) {
        return 0xff;
      }
      if (*plVar6 != 0) {
        iVar3 = (*(code *)*plVar6)();
      }
    }
    if (iVar3 != 0) {
      return 0xff;
    }
  }
  else {
    DAT_1400050a4 = 1;
  }
  if (__native_startup_state == 1) {
    _initterm(&__xc_a,&__xc_z);
    __native_startup_state = 2;
  }
  if (!bVar2) {
    LOCK();
    __native_startup_lock = (void *)0x0;
    UNLOCK();
  }
  if ((__dyn_tls_init_callback != (code *)0x0) &&
     (BVar4 = _IsNonwritableInCurrentImage((PBYTE)&__dyn_tls_init_callback), BVar4 != 0)) {
    (*__dyn_tls_init_callback)(0,2);
  }
  DAT_1400050a0 = main(DAT_1400050a8,DAT_1400050b0,DAT_1400050b8);
  if (DAT_1400050c0 == 0) {
                    /* WARNING: Subroutine does not return */
    exit(DAT_1400050a0);
  }
  if (DAT_1400050a4 == 0) {
    _cexit();
  }
  return DAT_1400050a0;
}



===== entry @ 140001300 =====

void entry(void)

{
  __security_init_cookie();
  __mainCRTStartup();
  return;
}



===== __CxxUnhandledExceptionFilter @ 140001330 =====

/* long __cdecl __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS * __ptr64) */

long __cdecl __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *param_1)

{
  int iVar1;
  PEXCEPTION_RECORD pEVar2;
  
  pEVar2 = param_1->ExceptionRecord;
  if (((pEVar2->ExceptionCode == 0xe06d7363) && (pEVar2->NumberParameters == 4)) &&
     ((iVar1 = (int)pEVar2->ExceptionInformation[0], iVar1 + 0xe66cfae0U < 3 || (iVar1 == 0x1994000)
      ))) {
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  return 0;
}



===== __CxxSetUnhandledExceptionFilter @ 140001370 =====

undefined8 __CxxSetUnhandledExceptionFilter(void)

{
  SetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return 0;
}



===== _XcptFilter @ 14000138e =====

int __cdecl _XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000138e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _XcptFilter(_ExceptionNum,_ExceptionPtr);
  return iVar1;
}



===== RtlpImageNtHeader @ 14000139c =====

int * RtlpImageNtHeader(short *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if (((((longlong)param_1 - 1U < 0xfffffffffffffffe) && (*param_1 == 0x5a4d)) &&
      (-1 < *(int *)(param_1 + 0x1e))) &&
     ((*(uint *)(param_1 + 0x1e) < 0x10000000 &&
      (piVar1 = (int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1), *piVar1 != 0x4550))
     )) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



===== _get_image_app_type @ 1400013f8 =====

undefined4 _get_image_app_type(undefined4 param_1)

{
  HMODULE pHVar1;
  int *piVar2;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((pHVar1 != (HMODULE)0x0) &&
     (piVar2 = RtlpImageNtHeader((short *)pHVar1), piVar2 != (int *)0x0)) {
    if ((short)piVar2[0x17] == 2) {
      return 2;
    }
    if ((short)piVar2[0x17] == 3) {
      param_1 = 1;
    }
  }
  return param_1;
}



===== _amsg_exit @ 140001444 =====

void __cdecl _amsg_exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140001444. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _amsg_exit(param_1);
  return;
}



===== _setargv @ 140001450 =====

int __cdecl _setargv(void)

{
  return 0;
}



===== _FindPESection @ 140001460 =====

PIMAGE_SECTION_HEADER __cdecl _FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  int iVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  uint uVar3;
  
  iVar1 = *(int *)(pImageBase + 0x3c);
  uVar3 = 0;
  p_Var2 = (PIMAGE_SECTION_HEADER)
           (pImageBase +
           (ulonglong)*(ushort *)(pImageBase + (longlong)iVar1 + 0x14) + 0x18 + (longlong)iVar1);
  if (*(ushort *)(pImageBase + (longlong)iVar1 + 6) != 0) {
    do {
      if ((p_Var2->VirtualAddress <= rva) &&
         (rva < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) {
        return p_Var2;
      }
      uVar3 = uVar3 + 1;
      p_Var2 = p_Var2 + 1;
    } while (uVar3 < *(ushort *)(pImageBase + (longlong)iVar1 + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}



===== _IsNonwritableInCurrentImage @ 1400014b0 =====

BOOL __cdecl _IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  uint uVar2;
  PIMAGE_SECTION_HEADER p_Var3;
  
  BVar1 = _ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_140000000);
  uVar2 = 0;
  if (BVar1 != 0) {
    p_Var3 = _FindPESection((PBYTE)&IMAGE_DOS_HEADER_140000000,(DWORD_PTR)(pTarget + -0x140000000));
    uVar2 = 0;
    if (p_Var3 != (PIMAGE_SECTION_HEADER)0x0) {
      uVar2 = ~(p_Var3->Characteristics >> 0x1f) & 1;
    }
  }
  return uVar2;
}



===== _ValidateImageBase @ 140001510 =====

BOOL __cdecl _ValidateImageBase(PBYTE pImageBase)

{
  if ((*(short *)pImageBase == 0x5a4d) &&
     (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550)) {
    return (BOOL)((short)*(int *)((longlong)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) ==
                 0x20b);
  }
  return 0;
}



===== __security_init_cookie @ 140001544 =====

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_res18;
  
  local_res18.dwLowDateTime = 0;
  local_res18.dwHighDateTime = 0;
  local_res10.QuadPart = 0;
  if (__security_cookie == 0x2b992ddfa232) {
    GetSystemTimeAsFileTime(&local_res18);
    local_res8 = local_res18;
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1 << 0x18);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)DVar1 ^ (ulonglong)local_res8 ^ (ulonglong)&local_res8);
    QueryPerformanceCounter(&local_res10);
    __security_cookie =
         (local_res10.QuadPart << 0x20 ^ local_res10.QuadPart ^ (ulonglong)local_res8) &
         0xffffffffffff;
    if (__security_cookie == 0x2b992ddfa232) {
      __security_cookie = 0x2b992ddfa233;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== _initterm @ 140001623 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001623. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== __C_specific_handler @ 14000162f =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000162f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __raise_securityfailure @ 140001648 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000140001675. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



===== __report_gsfailure @ 140001690 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  ulonglong local_38 [2];
  PVOID local_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  local_38[1] = 0;
  local_28 = (PVOID)0x0;
  local_38[0] = 0;
  RtlCaptureContext(&DAT_140005180);
  ControlPc = DAT_140005278;
  FunctionEntry = RtlLookupFunctionEntry(DAT_140005278,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    DAT_140005278 = *DAT_140005218;
    DAT_140005218 = DAT_140005218 + 1;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_140005180,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_1400050f0 = DAT_140005278;
  _DAT_1400050e0 = 0xc0000409;
  _DAT_1400050e4 = 1;
  _DAT_1400050f8 = 3;
  DAT_140005100 = 2;
  DAT_140005108 = __security_cookie;
  DAT_140005110 = __security_cookie_complement;
  uStack_20 = __security_cookie;
  uStack_18 = __security_cookie_complement;
  _DAT_140005200 = _StackCookie;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_140003000);
  return;
}



===== _guard_check_icall @ 140001840 =====

void _guard_check_icall(void)

{
  return;
}



===== __tailMerge_api_ms_win_core_winrt_l1_1_0_dll @ 140001850 =====

void __tailMerge_api_ms_win_core_winrt_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_R8;
  undefined8 in_XMM0_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140003900,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001400018c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_XMM0_Qa,in_RDX,in_R8,param_4);
  return;
}



===== DelayLoad_RoInitialize @ 1400018cf =====

void DelayLoad_RoInitialize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RoUninitialize @ 1400018e1 =====

void DelayLoad_RoUninitialize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_core_winrt_string_l1_1_0_dll @ 1400018ed =====

void __tailMerge_api_ms_win_core_winrt_string_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_R9;
  undefined8 in_XMM0_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140003920,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140001964. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_XMM0_Qa,in_RDX,param_3,in_R9);
  return;
}



===== DelayLoad_WindowsCreateStringReference @ 14000196c =====

void DelayLoad_WindowsCreateStringReference
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_string_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RoGetActivationFactory @ 14000197e =====

void DelayLoad_RoGetActivationFactory
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_winrt_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== main @ 140001990 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl main(int _Argc,char **_Argv,char **_Env)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_58 [32];
  longlong *local_38;
  undefined8 local_30;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  uVar2 = RoInitialize(1);
  if (-1 < (int)uVar2) {
    local_38 = (longlong *)0x0;
    iVar3 = WindowsCreateStringReference
                      (L"Windows.ApplicationModel.Core.CoreApplication",0x2d,local_28,&local_30);
    if (iVar3 < 0) {
      RaiseException(0xc000000d,1,0,(ULONG_PTR *)0x0);
    }
    if (local_38 != (longlong *)0x0) {
      (**(code **)(*local_38 + 0x10))();
    }
    uVar2 = RoGetActivationFactory(local_30,&_GUID_0aacf7a4_5e1d_49df_8034_fb6a68bc5ed1,&local_38);
    if (-1 < (int)uVar2) {
      uVar2 = (**(code **)(*local_38 + 0x68))(local_38,0);
    }
    plVar1 = local_38;
    if (local_38 != (longlong *)0x0) {
      local_38 = (longlong *)0x0;
      (**(code **)(*plVar1 + 0x10))();
    }
    RoUninitialize();
  }
  return uVar2 >> 0x1f;
}



===== __delayLoadHelper2 @ 140001aa0 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(&IMAGE_DOS_HEADER_140000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== __GSHandlerCheck @ 140001ae4 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001b08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)(*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0);
  }
  return uVar1;
}



===== __security_check_cookie @ 140001b90 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140001bd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140001c00 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001c00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140001c30 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== __mainCRTStartup$filt$0 @ 140001c40 =====

void __mainCRTStartup_filt_0(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



===== _IsNonwritableInCurrentImage$filt$0 @ 140001c70 =====

bool _IsNonwritableInCurrentImage_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 140002010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


