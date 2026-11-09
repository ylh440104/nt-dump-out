
===== initialize_legacy_wide_specifiers @ 180001010 =====

undefined8 initialize_legacy_wide_specifiers(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 4;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return 0;
}



===== __local_stdio_printf_options @ 180001034 =====

__uint64 * __local_stdio_printf_options(void)

{
  return &`__local_stdio_printf_options'::__l2::_OptionsStorage;
}



===== __local_stdio_scanf_options @ 180001044 =====

__uint64 * __local_stdio_scanf_options(void)

{
  return &`__local_stdio_scanf_options'::__l2::_OptionsStorage;
}



===== initialize_msvcrt_compatibility @ 180001060 =====

undefined8 initialize_msvcrt_compatibility(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x18;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 4;
  return 0;
}



===== dllmain_crt_dispatch @ 180001090 =====

ulonglong dllmain_crt_dispatch(undefined8 param_1,int param_2,longlong param_3)

{
  byte bVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  undefined7 extraout_var;
  
  if (param_2 == 0) {
    uVar2 = dllmain_crt_process_detach(CONCAT71((int7)((ulonglong)param_1 >> 8),param_3 != 0));
    return CONCAT71(extraout_var,uVar2);
  }
  if (param_2 == 1) {
    uVar3 = dllmain_crt_process_attach(param_1,param_3);
    return uVar3;
  }
  if (param_2 == 2) {
    bVar1 = __scrt_dllmain_crt_thread_attach();
  }
  else {
    if (param_2 != 3) {
      return 1;
    }
    bVar1 = __scrt_dllmain_crt_thread_detach();
  }
  return (ulonglong)bVar1;
}



===== dllmain_crt_process_attach @ 1800010e8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 dllmain_crt_process_attach(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  
  lVar4 = __scrt_initialize_crt(0);
  if ((char)lVar4 != '\0') {
    uVar5 = __scrt_acquire_startup_lock();
    bVar1 = true;
    if (__scrt_current_native_startup_state != 0) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(7);
    }
    __scrt_current_native_startup_state = 1;
    bVar2 = __scrt_dllmain_before_initialize_c();
    if (bVar2) {
      _RTC_Initialize();
      __scrt_initialize_type_info();
      __scrt_initialize_default_local_stdio_options();
      iVar3 = _initterm_e(&__xi_a,&__xi_z);
      if ((iVar3 == 0) && (uVar6 = __scrt_dllmain_after_initialize_c(), (char)uVar6 != '\0')) {
        _initterm(&__xc_a,&__xc_z);
        __scrt_current_native_startup_state = 2;
        bVar1 = false;
      }
    }
    __scrt_release_startup_lock((char)uVar5);
    if (!bVar1) {
      plVar7 = (longlong *)__scrt_get_dyn_tls_init_callback();
      if ((*plVar7 != 0) &&
         (uVar8 = __scrt_is_nonwritable_in_current_image((longlong)plVar7), (char)uVar8 != '\0')) {
        (*(code *)*plVar7)(param_1,2,param_2);
      }
      DAT_180009090 = DAT_180009090 + 1;
      return 1;
    }
  }
  return 0;
}



===== dllmain_crt_process_detach @ 180001200 =====

undefined1 dllmain_crt_process_detach(undefined8 param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined7 uVar3;
  
  uVar1 = (undefined1)param_1;
  if (DAT_180009090 < 1) {
    uVar1 = 0;
  }
  else {
    DAT_180009090 = DAT_180009090 + -1;
    uVar2 = __scrt_acquire_startup_lock();
    if (__scrt_current_native_startup_state != 2) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(7);
    }
    __scrt_dllmain_uninitialize_c();
    __scrt_uninitialize_type_info();
    _RTC_Terminate();
    __scrt_current_native_startup_state = 0;
    uVar3 = (undefined7)((ulonglong)param_1 >> 8);
    __scrt_release_startup_lock((char)uVar2);
    uVar1 = __scrt_uninitialize_crt(CONCAT71(uVar3,uVar1),'\0');
    __scrt_dllmain_uninitialize_critical();
  }
  return uVar1;
}



===== dllmain_dispatch @ 180001288 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00018000134b) */
/* WARNING: Removing unreachable block (ram,0x0001800012db) */
/* WARNING: Removing unreachable block (ram,0x00018000138d) */

ulonglong dllmain_dispatch(HMODULE param_1,int param_2,longlong param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if ((param_2 == 0) && (DAT_180009090 < 1)) {
    return 0;
  }
  if (param_2 - 1U < 2) {
    uVar1 = dllmain_crt_dispatch(param_1,param_2,param_3);
    if ((int)uVar1 == 0) {
      return uVar1 & 0xffffffff;
    }
  }
  uVar1 = DllMain(param_1,param_2);
  uVar2 = uVar1 & 0xffffffff;
  if ((param_2 == 1) && ((int)uVar1 == 0)) {
    DllMain(param_1,0);
    dllmain_crt_dispatch(param_1,0,param_3);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    uVar1 = dllmain_crt_dispatch(param_1,param_2,param_3);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== entry @ 1800013c0 =====

void entry(HMODULE param_1,int param_2,longlong param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}



===== __security_check_cookie @ 180001410 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __security_init_cookie @ 180001434 =====

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  LARGE_INTEGER local_res8;
  _FILETIME local_res10;
  _FILETIME local_18 [2];
  
  if (__security_cookie == 0x2b992ddfa232) {
    local_res10.dwLowDateTime = 0;
    local_res10.dwHighDateTime = 0;
    local_res8.QuadPart = 0;
    GetSystemTimeAsFileTime(&local_res10);
    local_18[0] = local_res10;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res8);
    __security_cookie =
         (local_res8.QuadPart << 0x20 ^ local_res8.QuadPart ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (__security_cookie == 0x2b992ddfa232) {
      __security_cookie = 0x2b992ddfa233;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== DllMain @ 1800014ec =====

undefined8 DllMain(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



===== __scrt_initialize_type_info @ 180001518 =====

/* void __cdecl __scrt_initialize_type_info(void) */

void __cdecl __scrt_initialize_type_info(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000151f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&__type_info_root_node);
  return;
}



===== __scrt_uninitialize_type_info @ 18000152c =====

/* void __cdecl __scrt_uninitialize_type_info(void) */

void __cdecl __scrt_uninitialize_type_info(void)

{
  _o___std_type_info_destroy_list(&__type_info_root_node);
  return;
}



===== __scrt_initialize_default_local_stdio_options @ 180001540 =====

void __scrt_initialize_default_local_stdio_options(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x24;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return;
}



===== __scrt_acquire_startup_lock @ 180001564 =====

ulonglong __scrt_acquire_startup_lock(void)

{
  bool bVar1;
  undefined7 extraout_var;
  void *pvVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  pvVar2 = (void *)CONCAT71(extraout_var,bVar1);
  if ((int)pvVar2 == 0) {
LAB_180001592:
    uVar3 = (ulonglong)pvVar2 & 0xffffffffffffff00;
  }
  else {
    do {
      pvVar2 = (void *)0x0;
      LOCK();
      bVar1 = __scrt_native_startup_lock == (void *)0x0;
      if (bVar1) {
        __scrt_native_startup_lock = StackBase;
      }
      else {
        pvVar2 = __scrt_native_startup_lock;
      }
      UNLOCK();
      if (bVar1) goto LAB_180001592;
    } while (StackBase != pvVar2);
    uVar3 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  return uVar3;
}



===== __scrt_dllmain_after_initialize_c @ 1800015a4 =====

undefined8 __scrt_dllmain_after_initialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar3 = _get_startup_argv_mode();
    uVar3 = _configure_narrow_argv(uVar3 & 0xffffffff);
    if ((int)uVar3 != 0) {
      return uVar3 & 0xffffffffffffff00;
    }
    uVar2 = _o__initialize_narrow_environment();
  }
  else {
    uVar2 = __isa_available_init();
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== __scrt_dllmain_before_initialize_c @ 1800015e0 =====

bool __scrt_dllmain_before_initialize_c(void)

{
  undefined8 uVar1;
  
  uVar1 = __scrt_initialize_onexit_tables(0);
  return (char)uVar1 != '\0';
}



===== __scrt_dllmain_crt_thread_attach @ 1800015fc =====

undefined1 __scrt_dllmain_crt_thread_attach(void)

{
  char cVar1;
  
  cVar1 = __vcrt_thread_attach();
  if (cVar1 != '\0') {
    cVar1 = __vcrt_thread_attach();
    if (cVar1 != '\0') {
      return 1;
    }
    __vcrt_thread_attach();
  }
  return 0;
}



===== __scrt_dllmain_crt_thread_detach @ 18000162c =====

undefined1 __scrt_dllmain_crt_thread_detach(void)

{
  __vcrt_thread_attach();
  __vcrt_thread_attach();
  return 1;
}



===== __scrt_dllmain_exception_filter @ 180001648 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void __scrt_dllmain_exception_filter
               (undefined8 param_1,int param_2,undefined8 param_3,undefined *param_4,
               undefined4 param_5,undefined8 param_6)

{
  bool bVar1;
  undefined7 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if (((int)CONCAT71(extraout_var,bVar1) == 0) && (param_2 == 1)) {
    (*(code *)param_4)(param_1,0,param_3);
  }
  _seh_filter_dll(param_5,param_6);
  return;
}



===== __scrt_dllmain_uninitialize_c @ 1800016b0 =====

void __scrt_dllmain_uninitialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    _o__execute_onexit_table(&DAT_1800090c0);
    return;
  }
  uVar2 = _is_c_termination_complete();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}



===== __scrt_dllmain_uninitialize_critical @ 1800016e8 =====

void __scrt_dllmain_uninitialize_critical(void)

{
  __vcrt_thread_attach();
  __vcrt_thread_attach();
  return;
}



===== __scrt_initialize_crt @ 180001704 =====

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_1800090f1 = 1;
  }
  __isa_available_init();
  cVar1 = __vcrt_thread_attach();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = __vcrt_thread_attach();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    __vcrt_thread_attach();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}



===== __scrt_initialize_onexit_tables @ 180001744 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_1800090f0 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      _DAT_1800090c0 = 0xffffffffffffffff;
      uRam00000001800090c8 = 0xffffffffffffffff;
      _DAT_1800090d0 = 0xffffffffffffffff;
      _DAT_1800090d8 = 0xffffffffffffffff;
      uRam00000001800090e0 = 0xffffffffffffffff;
      _DAT_1800090e8 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _o__initialize_onexit_table(&DAT_1800090c0);
      if (((int)in_RAX != 0) ||
         (in_RAX = _o__initialize_onexit_table(&DAT_1800090d8), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_1800090f0 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== __scrt_is_nonwritable_in_current_image @ 1800017d8 =====

/* WARNING: Removing unreachable block (ram,0x000180001865) */
/* WARNING: Enum "SectionFlags": Some values do not have unique names */

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_180000210; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_180000328;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x180000000U) &&
       (uVar1 = (ulonglong)((pIVar3->Misc).PhysicalAddress + pIVar3->VirtualAddress),
       param_1 - 0x180000000U < uVar1)) goto LAB_18000184e;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_18000184e:
  if (pIVar3 == (IMAGE_SECTION_HEADER *)0x0) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = (uint7)(uVar1 >> 8);
    if ((int)pIVar3->Characteristics < 0) {
      uVar1 = (ulonglong)uVar2 << 8;
    }
    else {
      uVar1 = CONCAT71(uVar2,1);
    }
  }
  return uVar1;
}



===== __scrt_release_startup_lock @ 180001878 =====

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    __scrt_native_startup_lock = 0;
    UNLOCK();
  }
  return;
}



===== __scrt_uninitialize_crt @ 1800018a4 =====

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_1800090f1 == '\0') || (param_2 == '\0')) {
    __vcrt_thread_attach();
    __vcrt_thread_attach();
  }
  return 1;
}



===== __scrt_get_dyn_tls_init_callback @ 1800018d4 =====

undefined * __scrt_get_dyn_tls_init_callback(void)

{
  return &__dyn_tls_init_callback;
}



===== __crt_debugger_hook @ 1800018e4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __crt_debugger_hook(int param_1)

{
  ___scrt_debugger_hook_flag = 0;
  return;
}



===== __scrt_fastfail @ 1800018f4 =====

void __scrt_fastfail(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar4 = auStack_5c8;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x180001928;
  __crt_debugger_hook(3);
  *(undefined8 *)(puVar4 + -8) = 0x180001939;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x180001943;
  RtlCaptureContext(local_4d8);
  local_res10 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x180001965;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    local_res18 = 0;
    local_res20 = 0;
    *(undefined8 **)(puVar4 + 0x30) = &local_res18;
    *(undefined8 **)(puVar4 + 0x28) = &local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x1800019b6;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = auStack_5c8 + 0x5d0;
  *(undefined8 *)(puVar4 + -8) = 0x1800019e8;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x180001a0a;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x180001a27;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x180001a32;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x180001a43;
    __crt_debugger_hook(3);
  }
  return;
}



===== _RTC_Initialize @ 180001a5c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _RTC_Initialize(void)

{
  undefined8 *puVar1;
  
  for (puVar1 = &__rtc_izz; puVar1 < &__rtc_izz; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



===== _RTC_Terminate @ 180001aa0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _RTC_Terminate(void)

{
  undefined8 *puVar1;
  
  for (puVar1 = &__rtc_tzz; puVar1 < &__rtc_tzz; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



===== __raise_securityfailure @ 180001ae8 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000180001b15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



===== __report_gsfailure @ 180001b30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  puVar3 = auStack_38;
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x180001b5b;
  capture_previous_context((PCONTEXT)&DAT_1800091a0);
  _DAT_180009110 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_180009238 = puVar3 + 0x40;
  _DAT_180009220 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_180009100 = 0xc0000409;
  _DAT_180009104 = 1;
  _DAT_180009118 = 1;
  DAT_180009120 = 2;
  *(undefined8 *)(puVar3 + 0x20) = __security_cookie;
  *(undefined8 *)(puVar3 + 0x28) = __security_cookie_complement;
  *(undefined8 *)(puVar3 + -8) = 0x180001bfd;
  DAT_180009298 = _DAT_180009110;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180007000);
  return;
}



===== capture_previous_context @ 180001c08 =====

void capture_previous_context(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  ulonglong local_res8 [2];
  PVOID local_res18 [2];
  
  local_res8[1] = 0;
  local_res8[0] = 0;
  local_res18[0] = (PVOID)0x0;
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8[0],ControlPc,FunctionEntry,param_1,local_res18,local_res8 + 1,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}



===== __isa_available_init @ 180001c94 =====

/* WARNING: Removing unreachable block (ram,0x000180001d5e) */
/* WARNING: Removing unreachable block (ram,0x000180001cce) */
/* WARNING: Removing unreachable block (ram,0x000180001ca7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __isa_available_init(void)

{
  int *piVar1;
  uint *puVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  uVar8 = 0;
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar4 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    ___memset_nt_threshold = 0xffffffffffffffff;
    uVar7 = *puVar2 & 0xfff3ff0;
    ___memset_fast_string_threshold = 0x8000;
    if ((((uVar7 == 0x106c0) || (uVar7 == 0x20660)) || (uVar7 == 0x20670)) ||
       ((uVar7 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar7 - 0x30650) & 0x3f) & 1) != 0)))) {
      __favor = __favor | 1;
    }
  }
  if (6 < *piVar1) {
    lVar3 = cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = *(uint *)(lVar3 + 4);
    if ((uVar8 >> 9 & 1) != 0) {
      __favor = __favor | 2;
    }
  }
  ___isa_available = 1;
  __isa_enabled = 2;
  if ((uVar4 >> 0x14 & 1) != 0) {
    ___isa_available = 2;
    __isa_enabled = 6;
    if (((uVar4 >> 0x1b & 1) != 0) && ((uVar4 >> 0x1c & 1) != 0)) {
      uVar5 = xinuse(0);
      bVar6 = in_XCR0 & (byte)uVar5;
      if ((bVar6 & 6) == 6) {
        ___isa_available = 3;
        __isa_enabled = 0xe;
        if ((uVar8 & 0x20) != 0) {
          ___isa_available = 5;
          __isa_enabled = 0x2e;
          if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
            __isa_enabled = 0x6e;
            ___isa_available = 6;
          }
        }
      }
    }
  }
  return 0;
}



===== _get_startup_argv_mode @ 180001e48 =====

undefined8 _get_startup_argv_mode(void)

{
  return 1;
}



===== __scrt_is_ucrt_dll_in_use @ 180001e54 =====

bool __scrt_is_ucrt_dll_in_use(void)

{
  return __scrt_ucrt_dll_is_in_use != 0;
}



===== _guard_check_icall @ 180001e70 =====

void _guard_check_icall(void)

{
  return;
}



===== _initterm @ 180001e86 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== _initterm_e @ 180001e92 =====

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}



===== __C_specific_handler @ 180001e9e =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180001e9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== _o___std_type_info_destroy_list @ 180001eaa =====

void _o___std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001eaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___std_type_info_destroy_list();
  return;
}



===== _cexit @ 180001eb6 =====

void _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001eb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__cexit();
  return;
}



===== _configure_narrow_argv @ 180001ec2 =====

void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001ec2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configure_narrow_argv();
  return;
}



===== _o__execute_onexit_table @ 180001ece =====

void _o__execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001ece. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__execute_onexit_table();
  return;
}



===== _o__initialize_narrow_environment @ 180001eda =====

void _o__initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001eda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_narrow_environment();
  return;
}



===== _o__initialize_onexit_table @ 180001ee6 =====

void _o__initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001ee6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_onexit_table();
  return;
}



===== _seh_filter_dll @ 180001ef2 =====

void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001ef2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__seh_filter_dll();
  return;
}



===== memset @ 180001efe =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180001efe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== __vcrt_thread_attach @ 180001f0c =====

undefined1 __vcrt_thread_attach(void)

{
  return 1;
}



===== _is_c_termination_complete @ 180001f18 =====

undefined8 _is_c_termination_complete(void)

{
  return 0;
}



===== WinUsb_AbortPipe @ 180001f30 =====

BOOL WinUsb_AbortPipe(undefined8 *param_1,undefined1 param_2)

{
  undefined8 *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  DWORD local_res8 [2];
  _OVERLAPPED local_28;
  
                    /* 0x1f30  1  WinUsb_AbortPipe */
  local_res8[0] = 0;
  local_28.Internal = 0;
  local_28.InternalHigh = 0;
  local_28.u.Pointer = (PVOID)0x0;
  local_28.hEvent = (HANDLE)0x0;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_28.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_28.hEvent != (HANDLE)0x0) {
      local_28.hEvent = (HANDLE)((ulonglong)local_28.hEvent | 1);
      BVar2 = WinUsb_AbortPipeAsync(param_1,param_2,&local_28);
      if (BVar2 == 0) {
        DVar3 = GetLastError();
        BVar2 = 0;
        if (DVar3 != 0x3e5) goto LAB_180001fea;
      }
      BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_28,local_res8,1);
      goto LAB_180001fea;
    }
  }
  BVar2 = 0;
LAB_180001fea:
  if (local_28.hEvent != (HANDLE)0x0) {
    CloseHandle(local_28.hEvent);
  }
  return BVar2;
}



===== WinUsb_AbortPipeAsync @ 180002020 =====

BOOL WinUsb_AbortPipeAsync(undefined8 *param_1,undefined1 param_2,LPOVERLAPPED param_3)

{
  BOOL BVar1;
  undefined2 local_res8;
  DWORD local_res20 [2];
  
                    /* 0x2020  2  WinUsb_AbortPipeAsync */
  BVar1 = 0;
  local_res20[0] = 0;
  local_res8 = 0;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    local_res8 = CONCAT11(param_2,*(undefined1 *)(param_1 + 2));
    BVar1 = DeviceIoControl(*(HANDLE *)*param_1,0x350c028,&local_res8,2,(LPVOID)0x0,0,local_res20,
                            param_3);
  }
  return BVar1;
}



===== WinUsb_ControlTransfer @ 1800020a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BOOL WinUsb_ControlTransfer
               (undefined8 *param_1,undefined8 param_2,LPVOID param_3,DWORD param_4,DWORD *param_5,
               LPOVERLAPPED param_6)

{
  undefined8 *puVar1;
  bool bVar2;
  BOOL BVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  DWORD *lpBytesReturned;
  undefined1 auStackY_a8 [32];
  DWORD local_60 [2];
  LPOVERLAPPED local_58;
  undefined1 local_50;
  undefined7 uStack_4f;
  undefined1 local_48;
  ulonglong local_40;
  
                    /* 0x20a0  3  WinUsb_ControlTransfer */
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = (LPOVERLAPPED)0x0;
  bVar2 = false;
  local_50 = 0;
  uStack_4f = 0;
  local_48 = 0;
  if (param_5 != (DWORD *)0x0) {
    *param_5 = 0;
  }
  local_60[0] = param_4;
  if (param_1 == (undefined8 *)0x0) {
    DVar5 = 6;
LAB_180002105:
    param_6 = local_58;
    SetLastError(DVar5);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    lpBytesReturned = param_5;
    if ((param_4 == 0) && (lpBytesReturned = local_60, param_5 != (DWORD *)0x0)) {
      lpBytesReturned = param_5;
    }
    if (param_6 != (LPOVERLAPPED)0x0) {
      local_58 = param_6;
      bVar2 = false;
LAB_1800021b6:
      local_50 = *(undefined1 *)(param_1 + 2);
      uStack_4f = (undefined7)param_2;
      local_48 = (undefined1)((ulonglong)param_2 >> 0x38);
      BVar3 = DeviceIoControl((HANDLE)*puVar1,0x350c03a,&local_50,9,param_3,local_60[0],
                              lpBytesReturned,param_6);
      if ((bVar2) && ((BVar3 != 0 || (DVar5 = GetLastError(), DVar5 == 0x3e5)))) {
        BVar3 = GetOverlappedResult((HANDLE)*puVar1,param_6,lpBytesReturned,1);
      }
      goto LAB_18000223e;
    }
    pvVar4 = GetProcessHeap();
    param_6 = HeapAlloc(pvVar4,8,0x20);
    local_58 = param_6;
    if (param_6 == (LPOVERLAPPED)0x0) {
      DVar5 = 8;
      goto LAB_180002105;
    }
    bVar2 = true;
    pvVar4 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    param_6->hEvent = pvVar4;
    if (pvVar4 != (HANDLE)0x0) {
      param_6->hEvent = (HANDLE)((ulonglong)pvVar4 | 1);
      bVar2 = true;
      goto LAB_1800021b6;
    }
  }
  BVar3 = 0;
LAB_18000223e:
  if ((bVar2) && (param_6 != (LPOVERLAPPED)0x0)) {
    if (param_6->hEvent != (HANDLE)0x0) {
      CloseHandle(param_6->hEvent);
    }
    pvVar4 = GetProcessHeap();
    HeapFree(pvVar4,0,param_6);
  }
  return BVar3;
}



===== WinUsb_FlushPipe @ 1800022b0 =====

BOOL WinUsb_FlushPipe(undefined8 *param_1,undefined1 param_2)

{
  undefined8 *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined2 local_res8;
  DWORD local_res18 [4];
  _OVERLAPPED local_38;
  
                    /* 0x22b0  4  WinUsb_FlushPipe */
  local_res18[0] = 0;
  local_38.Internal = 0;
  local_38.InternalHigh = 0;
  local_38.u.Pointer = (PVOID)0x0;
  local_res8 = 0;
  local_38.hEvent = (HANDLE)0x0;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_38.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_38.hEvent != (HANDLE)0x0) {
      local_38.hEvent = (HANDLE)((ulonglong)local_38.hEvent | 1);
      local_res8 = CONCAT11(param_2,*(undefined1 *)(param_1 + 2));
      BVar2 = DeviceIoControl((HANDLE)*puVar1,0x3504048,&local_res8,2,(LPVOID)0x0,0,local_res18,
                              &local_38);
      if (BVar2 == 0) {
        DVar3 = GetLastError();
        BVar2 = 0;
        if (DVar3 != 0x3e5) goto LAB_1800023bc;
      }
      BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_38,local_res18,1);
      goto LAB_1800023bc;
    }
  }
  BVar2 = 0;
LAB_1800023bc:
  if (local_38.hEvent != (HANDLE)0x0) {
    CloseHandle(local_38.hEvent);
  }
  return BVar2;
}



===== WinUsb_Free @ 1800023f0 =====

undefined8 WinUsb_Free(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  LPVOID lpMem;
  LPVOID lpMem_00;
  HANDLE pvVar3;
  
                    /* 0x23f0  5  WinUsb_Free */
  if (param_1 != (undefined8 *)0x0) {
    lpMem = (LPVOID)*param_1;
    *(undefined8 *)(*(longlong *)((longlong)lpMem + 0x30) + (ulonglong)*(byte *)(param_1 + 2) * 8) =
         0;
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,param_1);
    LOCK();
    piVar1 = (int *)((longlong)lpMem + 0x28);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      lpMem_00 = *(LPVOID *)((longlong)lpMem + 0x20);
      if (lpMem_00 != (LPVOID)0x0) {
        pvVar3 = GetProcessHeap();
        HeapFree(pvVar3,0,lpMem_00);
      }
      pvVar3 = GetProcessHeap();
      HeapFree(pvVar3,0,*(LPVOID *)((longlong)lpMem + 0x30));
      pvVar3 = GetProcessHeap();
      HeapFree(pvVar3,0,lpMem);
    }
  }
  return 1;
}



===== WinUsb_GetAdjustedFrameNumber @ 1800024d0 =====

BOOL WinUsb_GetAdjustedFrameNumber(int *param_1,longlong param_2)

{
  BOOL BVar1;
  longlong lVar2;
  LARGE_INTEGER local_res18;
  LARGE_INTEGER local_res20;
  
                    /* 0x24d0  6  WinUsb_GetAdjustedFrameNumber */
  local_res18.QuadPart = 0;
  local_res20.QuadPart = 0;
  if (param_1 != (int *)0x0) {
    BVar1 = QueryPerformanceCounter(&local_res18);
    if (BVar1 == 0) {
      return 0;
    }
    BVar1 = QueryPerformanceFrequency(&local_res20);
    if (BVar1 == 0) {
      return 0;
    }
    lVar2 = ((local_res18.QuadPart - param_2) * 1000) / local_res20.QuadPart;
    if (lVar2 < 0x3e9) {
      *param_1 = *param_1 + (int)lVar2;
      return BVar1;
    }
  }
  SetLastError(0x57);
  return 0;
}



===== WinUsb_GetAssociatedInterface @ 180002580 =====

int WinUsb_GetAssociatedInterface(ulonglong *param_1,ulonglong param_2,undefined8 *param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  byte *pbVar3;
  ulonglong *lpMem;
  undefined8 uVar4;
  HANDLE pvVar5;
  DWORD dwErrCode;
  byte *pbVar6;
  byte bVar7;
  uint uVar8;
  int local_44;
  undefined8 local_38;
  ulonglong uStack_30;
  
                    /* 0x2580  7  WinUsb_GetAssociatedInterface */
  local_44 = 1;
  pbVar3 = (byte *)0x0;
  lpMem = (ulonglong *)0x0;
  if (param_1 == (ulonglong *)0x0) {
LAB_1800025b4:
    dwErrCode = 6;
  }
  else {
    uVar2 = *param_1;
    local_38 = uVar2;
    if ((char)param_1[2] != '\0') goto LAB_1800025b4;
    uVar8 = (int)(param_2 & 0xff) + 1;
    pbVar6 = *(byte **)(uVar2 + 0x20);
    if (uVar8 < pbVar6[4]) {
      if (*(longlong *)(*(longlong *)(uVar2 + 0x30) + 8 + (param_2 & 0xff) * 8) == 0) {
        for (bVar7 = 0; bVar7 <= uVar8; bVar7 = bVar7 + 1) {
          pbVar3 = WinUsb_ParseConfigurationDescriptor
                             (*(longlong *)(uVar2 + 0x20),pbVar6,0xffffffff,0,0xffffffff,0xffffffff,
                              0xffffffff);
          if (pbVar3 == (byte *)0x0) goto LAB_1800025f2;
          pbVar6 = pbVar3 + *pbVar3;
        }
        pvVar5 = GetProcessHeap();
        lpMem = HeapAlloc(pvVar5,8,0x298);
        if (lpMem != (ulonglong *)0x0) {
          *lpMem = uVar2;
          lpMem[1] = (ulonglong)pbVar3;
          *(char *)(lpMem + 2) = (char)uVar8;
          LOCK();
          *(int *)(uVar2 + 0x28) = *(int *)(uVar2 + 0x28) + 1;
          UNLOCK();
          *(ulonglong **)(*(longlong *)(uVar2 + 0x30) + (ulonglong)(byte)lpMem[2] * 8) = lpMem;
          for (bVar7 = 0; bVar7 < *(byte *)(lpMem[1] + 4); bVar7 = bVar7 + 1) {
            local_38 = 0;
            uStack_30 = 0;
            uVar4 = WinUsb_QueryPipeEx((longlong *)lpMem,0,bVar7,(uint *)&local_38);
            local_44 = (int)uVar4;
            if (local_44 == 0) goto LAB_180002751;
            if ((local_38 & 0x8000000000) == 0) {
              uVar8 = local_38._4_1_ & 0xf;
            }
            else {
              uVar8 = (local_38._4_1_ & 0xf) + 0x10;
            }
            *(undefined1 *)((longlong)lpMem + ((ulonglong)uVar8 + 1) * 0x14) = 1;
            uVar8 = local_38._4_1_ & 0xf;
            if ((local_38 & 0x8000000000) != 0) {
              uVar8 = uVar8 + 0x10;
            }
            puVar1 = (ulonglong *)((longlong)lpMem + (ulonglong)uVar8 * 0x14 + 0x18);
            *puVar1 = local_38;
            puVar1[1] = uStack_30;
          }
          *param_3 = lpMem;
          goto LAB_180002751;
        }
        dwErrCode = 8;
      }
      else {
        dwErrCode = 0xb7;
      }
    }
    else {
LAB_1800025f2:
      dwErrCode = 0x103;
    }
  }
  SetLastError(dwErrCode);
  local_44 = 0;
LAB_180002751:
  if ((local_44 == 0) && (lpMem != (ulonglong *)0x0)) {
    pvVar5 = GetProcessHeap();
    HeapFree(pvVar5,0,lpMem);
  }
  return local_44;
}



===== WinUsb_GetCurrentAlternateSetting @ 1800027a0 =====

BOOL WinUsb_GetCurrentAlternateSetting(undefined8 *param_1,LPVOID param_2)

{
  undefined8 *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  DWORD local_res8 [2];
  _OVERLAPPED local_28;
  
                    /* 0x27a0  8  WinUsb_GetCurrentAlternateSetting */
  local_res8[0] = 0;
  local_28.Internal = 0;
  local_28.InternalHigh = 0;
  local_28.u.Pointer = (PVOID)0x0;
  local_28.hEvent = (HANDLE)0x0;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_28.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_28.hEvent != (HANDLE)0x0) {
      local_28.hEvent = (HANDLE)((ulonglong)local_28.hEvent | 1);
      BVar2 = DeviceIoControl((HANDLE)*puVar1,0x350c05c,param_1 + 2,1,param_2,1,local_res8,&local_28
                             );
      if (BVar2 == 0) {
        DVar3 = GetLastError();
        BVar2 = 0;
        if (DVar3 != 0x3e5) goto LAB_18000288c;
      }
      BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_28,local_res8,1);
      goto LAB_18000288c;
    }
  }
  BVar2 = 0;
LAB_18000288c:
  if (local_28.hEvent != (HANDLE)0x0) {
    CloseHandle(local_28.hEvent);
  }
  return BVar2;
}



===== WinUsb_GetCurrentFrameNumber @ 1800028c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BOOL WinUsb_GetCurrentFrameNumber(undefined8 *param_1,undefined4 *param_2,undefined8 *param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined1 auStackY_98 [32];
  DWORD local_54;
  _OVERLAPPED local_50;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  ulonglong local_20;
  
                    /* 0x28c0  9  WinUsb_GetCurrentFrameNumber */
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  uStack_28 = 0;
  local_30 = 0;
  local_2c = 0;
  local_50.Internal = 0;
  local_50.InternalHigh = 0;
  local_50.u.Pointer = (PVOID)0x0;
  local_50.hEvent = (HANDLE)0x0;
  local_54 = 0;
  if ((param_2 == (undefined4 *)0x0) || (param_3 == (undefined8 *)0x0)) {
    SetLastError(0x57);
  }
  else {
    local_50.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_50.hEvent != (HANDLE)0x0) {
      BVar1 = DeviceIoControl(*(HANDLE *)*param_1,0x350407c,(LPVOID)0x0,0,&local_30,0x10,
                              (LPDWORD)0x0,&local_50);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        if (DVar2 == 0x3e5) {
          BVar1 = GetOverlappedResult(*(HANDLE *)*param_1,&local_50,&local_54,1);
          if (BVar1 != 0) {
            *param_2 = local_30;
            *param_3 = CONCAT44(uStack_24,uStack_28);
          }
        }
      }
      goto LAB_1800029e9;
    }
  }
  BVar1 = 0;
LAB_1800029e9:
  if (local_50.hEvent != (HANDLE)0x0) {
    CloseHandle(local_50.hEvent);
  }
  return BVar1;
}



===== WinUsb_GetCurrentFrameNumberAndQpc @ 180002a30 =====

BOOL WinUsb_GetCurrentFrameNumberAndQpc(undefined8 *param_1,LPVOID param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_res18 [4];
  _OVERLAPPED local_30;
  
                    /* 0x2a30  10  WinUsb_GetCurrentFrameNumberAndQpc */
  local_30.Internal = 0;
  local_30.InternalHigh = 0;
  local_30.u.Pointer = (PVOID)0x0;
  local_30.hEvent = (HANDLE)0x0;
  local_res18[0] = 0;
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (LPVOID)0x0)) {
    SetLastError(0x57);
  }
  else {
    local_30.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_30.hEvent != (HANDLE)0x0) {
      BVar1 = DeviceIoControl(*(HANDLE *)*param_1,0x350c084,param_2,0x3c,param_2,0x3c,local_res18,
                              &local_30);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        if (DVar2 == 0x3e5) {
          BVar1 = GetOverlappedResult(*(HANDLE *)*param_1,&local_30,local_res18,1);
          if ((BVar1 != 0) && (local_res18[0] != 0x3c)) {
            SetLastError(0x57);
          }
        }
      }
      goto LAB_180002b4b;
    }
  }
  BVar1 = 0;
LAB_180002b4b:
  if (local_30.hEvent != (HANDLE)0x0) {
    CloseHandle(local_30.hEvent);
  }
  return BVar1;
}



===== WinUsb_GetDescriptor @ 180002b80 =====

BOOL WinUsb_GetDescriptor
               (undefined8 *param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
               LPVOID param_5,DWORD param_6,DWORD *param_7)

{
  undefined8 *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 local_res8;
  DWORD local_44;
  _OVERLAPPED local_40;
  
                    /* 0x2b80  11  WinUsb_GetDescriptor */
  local_res8 = 0;
  local_40.Internal = 0;
  local_40.InternalHigh = 0;
  local_40.u.Pointer = (PVOID)0x0;
  local_44 = 0;
  local_40.hEvent = (HANDLE)0x0;
  *param_7 = 0;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_40.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_40.hEvent != (HANDLE)0x0) {
      local_40.hEvent = (HANDLE)((ulonglong)local_40.hEvent | 1);
      local_res8 = CONCAT22(param_4,CONCAT11(param_3,param_2));
      BVar2 = DeviceIoControl((HANDLE)*puVar1,0x350c004,&local_res8,4,param_5,param_6,&local_44,
                              &local_40);
      if (BVar2 == 0) {
        DVar3 = GetLastError();
        BVar2 = 0;
        if (DVar3 != 0x3e5) goto LAB_180002cc2;
      }
      BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_40,&local_44,1);
      if (BVar2 != 0) {
        *param_7 = local_44;
      }
      goto LAB_180002cc2;
    }
  }
  BVar2 = 0;
LAB_180002cc2:
  if (local_40.hEvent != (HANDLE)0x0) {
    CloseHandle(local_40.hEvent);
  }
  return BVar2;
}



===== WinUsb_GetOverlappedResult @ 180002d00 =====

void WinUsb_GetOverlappedResult
               (undefined8 *param_1,LPOVERLAPPED param_2,LPDWORD param_3,BOOL param_4)

{
                    /* 0x2d00  12  WinUsb_GetOverlappedResult */
                    /* WARNING: Could not recover jumptable at 0x000180002d06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetOverlappedResult(*(HANDLE *)*param_1,param_2,param_3,param_4);
  return;
}



===== WinUsb_GetPipePolicy @ 180002d20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BOOL WinUsb_GetPipePolicy
               (undefined8 *param_1,undefined1 param_2,undefined4 param_3,DWORD *param_4,
               LPVOID param_5)

{
  undefined8 *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined1 auStackY_b8 [32];
  DWORD local_74;
  _OVERLAPPED local_70;
  undefined8 local_50;
  undefined4 local_48;
  ulonglong local_40;
  
                    /* 0x2d20  13  WinUsb_GetPipePolicy */
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_74 = 0;
  local_50 = 0;
  local_48 = 0;
  local_70.Internal = 0;
  local_70.InternalHigh = 0;
  local_70.u.Pointer = (PVOID)0x0;
  local_70.hEvent = (HANDLE)0x0;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_70.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_70.hEvent != (HANDLE)0x0) {
      local_70.hEvent = (HANDLE)((ulonglong)local_70.hEvent | 1);
      local_50._0_2_ = CONCAT11(param_2,*(undefined1 *)(param_1 + 2));
      local_50 = CONCAT44(param_3,(undefined4)local_50);
      BVar2 = DeviceIoControl((HANDLE)*puVar1,0x350c050,&local_50,0xc,param_5,*param_4,&local_74,
                              &local_70);
      if (BVar2 == 0) {
        DVar3 = GetLastError();
        BVar2 = 0;
        if (DVar3 != 0x3e5) goto LAB_180002e5e;
      }
      BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_70,&local_74,1);
      if (BVar2 != 0) {
        *param_4 = local_74;
      }
      goto LAB_180002e5e;
    }
  }
  BVar2 = 0;
LAB_180002e5e:
  if (local_70.hEvent != (HANDLE)0x0) {
    CloseHandle(local_70.hEvent);
  }
  return BVar2;
}



===== WinUsb_GetPowerPolicy @ 180002ea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BOOL WinUsb_GetPowerPolicy(undefined8 *param_1,undefined4 param_2,DWORD *param_3,LPVOID param_4)

{
  undefined8 *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined1 auStackY_a8 [32];
  DWORD local_64;
  _OVERLAPPED local_60;
  undefined8 local_40;
  undefined4 local_38;
  ulonglong local_30;
  
                    /* 0x2ea0  14  WinUsb_GetPowerPolicy */
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_64 = 0;
  local_40 = 0;
  local_38 = 0;
  local_60.Internal = 0;
  local_60.InternalHigh = 0;
  local_60.u.Pointer = (PVOID)0x0;
  local_60.hEvent = (HANDLE)0x0;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_60.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_60.hEvent != (HANDLE)0x0) {
      local_60.hEvent = (HANDLE)((ulonglong)local_60.hEvent | 1);
      local_40._0_2_ = (ushort)*(byte *)(param_1 + 2);
      local_40 = CONCAT44(param_2,(undefined4)local_40);
      BVar2 = DeviceIoControl((HANDLE)*puVar1,0x350c058,&local_40,0xc,param_4,*param_3,&local_64,
                              &local_60);
      if (BVar2 == 0) {
        DVar3 = GetLastError();
        BVar2 = 0;
        if (DVar3 != 0x3e5) goto LAB_180002fd4;
      }
      BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_60,&local_64,1);
      if (BVar2 != 0) {
        *param_3 = local_64;
      }
      goto LAB_180002fd4;
    }
  }
  BVar2 = 0;
LAB_180002fd4:
  if (local_60.hEvent != (HANDLE)0x0) {
    CloseHandle(local_60.hEvent);
  }
  return BVar2;
}



===== WinUsb_Initialize @ 180003010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WinUsb_Initialize(HANDLE param_1,undefined8 *param_2)

{
  ulonglong *puVar1;
  ushort uVar2;
  int iVar3;
  BOOL BVar4;
  DWORD DVar5;
  uint uVar6;
  HANDLE pvVar7;
  longlong *lpMem;
  undefined8 *lpMem_00;
  LPVOID pvVar8;
  byte *pbVar9;
  ulonglong uVar10;
  byte bVar11;
  ulonglong uVar12;
  undefined1 auStackY_f8 [32];
  undefined1 local_b4 [4];
  DWORD local_b0;
  undefined4 local_ac;
  byte local_a8;
  undefined2 local_a4 [2];
  undefined2 local_a0 [2];
  uint local_9c;
  _OVERLAPPED local_98;
  DWORD local_78 [2];
  undefined8 *local_70;
  longlong *local_68;
  undefined8 local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined1 local_38;
  ulonglong local_30;
  
                    /* 0x3010  15  WinUsb_Initialize */
  local_30 = __security_cookie ^ (ulonglong)auStackY_f8;
  lpMem_00 = (undefined8 *)0x0;
  local_70 = (undefined8 *)0x0;
  local_40 = 0;
  local_38 = 0;
  local_b0 = 0;
  local_98.Internal = 0;
  local_98.InternalHigh = 0;
  local_98.u.Pointer = (PVOID)0x0;
  local_98.hEvent = (HANDLE)0x0;
  local_50 = 0;
  uStack_48 = 0;
  local_9c = 0;
  lpMem = (longlong *)0x0;
  local_68 = (longlong *)0x0;
  local_a0[0] = 0x100;
  local_a4[0] = 0;
  local_b4[0] = 0;
  local_ac = 0;
  local_98.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  if (local_98.hEvent != (HANDLE)0x0) {
    local_98.hEvent = (HANDLE)((ulonglong)local_98.hEvent | 1);
    if (((0xfffffffffffffffd < (longlong)param_1 - 1U) ||
        (iVar3 = NtQueryInformationFile(param_1,&local_50,&local_9c,4), iVar3 < 0)) ||
       ((local_9c & 0x20) != 0)) {
      DVar5 = 6;
      goto LAB_1800036c9;
    }
    pvVar7 = GetProcessHeap();
    lpMem = HeapAlloc(pvVar7,8,0x298);
    local_68 = lpMem;
    if (lpMem == (longlong *)0x0) {
LAB_180003147:
      DVar5 = 8;
    }
    else {
      pvVar7 = GetProcessHeap();
      lpMem_00 = HeapAlloc(pvVar7,8,0x40);
      local_70 = lpMem_00;
      if (lpMem_00 == (undefined8 *)0x0) goto LAB_180003147;
      *lpMem = (longlong)lpMem_00;
      *lpMem_00 = param_1;
      *(undefined4 *)(lpMem_00 + 5) = 1;
      *(undefined2 *)(lpMem_00 + 7) = 0;
      local_78[0] = 1;
      WinUsb_QueryDeviceInformation(lpMem,1,local_78,local_b4);
      *(undefined1 *)((longlong)lpMem_00 + 0x3a) = local_b4[0];
      BVar4 = DeviceIoControl(param_1,0x350c068,local_a0,2,local_a4,2,&local_b0,&local_98);
      if ((BVar4 == 0) && (DVar5 = GetLastError(), DVar5 == 0x3e5)) {
        BVar4 = GetOverlappedResult((HANDLE)*lpMem_00,&local_98,&local_b0,1);
      }
      if (BVar4 != 0) {
        *(undefined2 *)(lpMem_00 + 7) = local_a4[0];
      }
      uVar6 = ResetEvent(local_98.hEvent);
      uVar12 = (ulonglong)uVar6;
      if (uVar6 == 0) goto LAB_1800036db;
      local_ac = 1;
      BVar4 = DeviceIoControl(param_1,0x350c004,&local_ac,4,lpMem_00 + 1,0x12,&local_b0,&local_98);
      if (BVar4 == 0) {
        DVar5 = GetLastError();
        uVar12 = 0;
        if (DVar5 != 0x3e5) goto LAB_1800036db;
      }
      uVar6 = GetOverlappedResult((HANDLE)*lpMem_00,&local_98,&local_b0,1);
      uVar12 = (ulonglong)uVar6;
      if (uVar6 == 0) goto LAB_1800036db;
      uVar6 = ResetEvent(local_98.hEvent);
      uVar12 = (ulonglong)uVar6;
      if (uVar6 == 0) goto LAB_1800036db;
      local_ac = CONCAT31(local_ac._1_3_,2);
      BVar4 = DeviceIoControl(param_1,0x350c004,&local_ac,4,&local_40,9,&local_b0,&local_98);
      if (BVar4 == 0) {
        DVar5 = GetLastError();
        uVar12 = 0;
        if (DVar5 != 0x3e5) goto LAB_1800036db;
      }
      BVar4 = GetOverlappedResult((HANDLE)*lpMem_00,&local_98,&local_b0,1);
      if (BVar4 == 0) {
        DVar5 = GetLastError();
        uVar12 = 0;
        if (DVar5 != 0xea) goto LAB_1800036db;
      }
      uVar6 = ResetEvent(local_98.hEvent);
      uVar12 = (ulonglong)uVar6;
      if (uVar6 == 0) goto LAB_1800036db;
      uVar2 = local_40._2_2_;
      if (local_40._2_2_ == 0) {
LAB_18000340b:
        DVar5 = 8;
      }
      else {
        pvVar7 = GetProcessHeap();
        pvVar8 = HeapAlloc(pvVar7,8,(ulonglong)uVar2);
        lpMem_00[4] = pvVar8;
        if (pvVar8 == (LPVOID)0x0) {
          DVar5 = 8;
        }
        else {
          if (local_40._2_2_ < local_b0) {
            memcpy(pvVar8,&local_40,(ulonglong)local_40._2_2_);
          }
          else {
            BVar4 = DeviceIoControl(param_1,0x350c004,&local_ac,4,pvVar8,(uint)local_40._2_2_,
                                    &local_b0,&local_98);
            if (BVar4 == 0) {
              DVar5 = GetLastError();
              uVar12 = 0;
              if (DVar5 != 0x3e5) goto LAB_1800036db;
            }
            uVar6 = GetOverlappedResult((HANDLE)*lpMem_00,&local_98,&local_b0,1);
            uVar12 = (ulonglong)uVar6;
            if (uVar6 == 0) goto LAB_1800036db;
            uVar6 = ResetEvent(local_98.hEvent);
            uVar12 = (ulonglong)uVar6;
            if (uVar6 == 0) goto LAB_1800036db;
          }
          BVar4 = DeviceIoControl(param_1,0x350c03c,(LPVOID)0x0,0,(LPVOID)0x0,0,&local_b0,&local_98)
          ;
          if (BVar4 == 0) {
            DVar5 = GetLastError();
            uVar12 = 0;
            if (DVar5 != 0x3e5) goto LAB_1800036db;
          }
          uVar6 = GetOverlappedResult((HANDLE)*lpMem_00,&local_98,&local_b0,1);
          uVar12 = (ulonglong)uVar6;
          if (uVar6 == 0) goto LAB_1800036db;
          pbVar9 = WinUsb_ParseConfigurationDescriptor
                             (lpMem_00[4],(byte *)lpMem_00[4],0xffffffff,0,0xffffffff,0xffffffff,
                              0xffffffff);
          if (pbVar9 != (byte *)0x0) {
            lpMem[1] = (longlong)pbVar9;
            *(undefined1 *)(lpMem + 2) = 0;
            bVar11 = *(byte *)(lpMem_00[4] + 4);
            pvVar7 = GetProcessHeap();
            pvVar8 = HeapAlloc(pvVar7,8,(ulonglong)bVar11 << 3);
            lpMem_00[6] = pvVar8;
            bVar11 = 0;
            if (pvVar8 != (LPVOID)0x0) {
              memset(pvVar8,0,(ulonglong)*(byte *)(lpMem_00[4] + 4) << 3);
              *(longlong **)lpMem_00[6] = lpMem;
              for (; local_a8 = bVar11, bVar11 < *(byte *)(lpMem[1] + 4); bVar11 = bVar11 + 1) {
                local_60 = 0;
                uStack_58 = 0;
                uVar10 = WinUsb_QueryPipeEx(lpMem,0,bVar11,(uint *)&local_60);
                uVar12 = uVar10 & 0xffffffff;
                if ((int)uVar10 == 0) break;
                if ((local_60 & 0x8000000000) == 0) {
                  uVar6 = local_60._4_1_ & 0xf;
                }
                else {
                  uVar6 = (local_60._4_1_ & 0xf) + 0x10;
                }
                *(undefined1 *)((longlong)lpMem + ((ulonglong)uVar6 + 1) * 0x14) = 1;
                uVar6 = local_60._4_1_ & 0xf;
                if ((local_60 & 0x8000000000) != 0) {
                  uVar6 = uVar6 + 0x10;
                }
                puVar1 = (ulonglong *)((longlong)lpMem + (ulonglong)uVar6 * 0x14 + 0x18);
                *puVar1 = local_60;
                puVar1[1] = uStack_58;
              }
              goto LAB_1800036db;
            }
            goto LAB_18000340b;
          }
          DVar5 = 0x4b0;
        }
      }
    }
LAB_1800036c9:
    SetLastError(DVar5);
  }
  uVar12 = 0;
LAB_1800036db:
  if ((int)uVar12 == 0) {
    if (lpMem_00 != (undefined8 *)0x0) {
      pvVar8 = (LPVOID)lpMem_00[4];
      if (pvVar8 != (LPVOID)0x0) {
        pvVar7 = GetProcessHeap();
        HeapFree(pvVar7,0,pvVar8);
      }
      pvVar7 = GetProcessHeap();
      HeapFree(pvVar7,0,lpMem_00);
    }
    if (lpMem != (longlong *)0x0) {
      pvVar7 = GetProcessHeap();
      HeapFree(pvVar7,0,lpMem);
      lpMem = (longlong *)0x0;
    }
  }
  if (local_98.hEvent != (HANDLE)0x0) {
    CloseHandle(local_98.hEvent);
  }
  *param_2 = lpMem;
  return uVar12;
}



===== WinUsb_ParseConfigurationDescriptor @ 1800037b0 =====

byte * WinUsb_ParseConfigurationDescriptor
                 (longlong param_1,byte *param_2,uint param_3,uint param_4,uint param_5,uint param_6
                 ,uint param_7)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  
                    /* 0x37b0  16  WinUsb_ParseConfigurationDescriptor */
  pbVar2 = (byte *)((ulonglong)*(ushort *)(param_1 + 2) + param_1);
  do {
    pbVar1 = WinUsb_ParseDescriptors(param_1,(uint)*(ushort *)(param_1 + 2),param_2,4);
    if (pbVar1 == (byte *)0x0) break;
    pbVar3 = pbVar1;
    if ((param_3 != 0xffffffff) &&
       ((((pbVar2 < pbVar1 || (0xffff < (longlong)pbVar2 - (longlong)pbVar1)) ||
         ((ulonglong)((longlong)pbVar2 - (longlong)pbVar1) < 3)) || (pbVar1[2] != param_3)))) {
      pbVar3 = (byte *)0x0;
    }
    if ((param_4 != 0xffffffff) &&
       (((pbVar2 < pbVar1 || (0xffff < (longlong)pbVar2 - (longlong)pbVar1)) ||
        (((ulonglong)((longlong)pbVar2 - (longlong)pbVar1) < 4 || (pbVar1[3] != param_4)))))) {
      pbVar3 = (byte *)0x0;
    }
    if ((param_5 != 0xffffffff) &&
       (((pbVar2 < pbVar1 || (0xffff < (longlong)pbVar2 - (longlong)pbVar1)) ||
        (((ulonglong)((longlong)pbVar2 - (longlong)pbVar1) < 6 || (pbVar1[5] != param_5)))))) {
      pbVar3 = (byte *)0x0;
    }
    if ((param_6 != 0xffffffff) &&
       ((((pbVar2 < pbVar1 || (0xffff < (longlong)pbVar2 - (longlong)pbVar1)) ||
         ((ulonglong)((longlong)pbVar2 - (longlong)pbVar1) < 7)) || (pbVar1[6] != param_6)))) {
      pbVar3 = (byte *)0x0;
    }
    if ((param_7 != 0xffffffff) &&
       (((pbVar2 < pbVar1 || (0xffff < (longlong)pbVar2 - (longlong)pbVar1)) ||
        (((ulonglong)((longlong)pbVar2 - (longlong)pbVar1) < 8 || (pbVar1[7] != param_7)))))) {
      pbVar3 = (byte *)0x0;
    }
    param_2 = pbVar1 + *pbVar1;
    if (pbVar3 != (byte *)0x0) {
      return pbVar3;
    }
  } while (*pbVar1 != 0);
  SetLastError(0x490);
  return (byte *)0x0;
}



===== WinUsb_ParseDescriptors @ 180003920 =====

byte * WinUsb_ParseDescriptors(longlong param_1,uint param_2,byte *param_3,uint param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  
                    /* 0x3920  17  WinUsb_ParseDescriptors */
  pbVar2 = (byte *)((ulonglong)param_2 + param_1);
  if (param_3 < pbVar2) {
    while (1 < (ulonglong)((longlong)pbVar2 - (longlong)param_3)) {
      if (param_3[1] == param_4) {
        return param_3;
      }
      if (((*param_3 == 0) || (pbVar1 = param_3 + *param_3, pbVar1 < param_3)) ||
         (param_3 = pbVar1, pbVar2 <= pbVar1)) break;
    }
  }
  SetLastError(0x490);
  return (byte *)0x0;
}



===== WinUsb_QueryDeviceInformation @ 180003990 =====

BOOL WinUsb_QueryDeviceInformation
               (undefined8 *param_1,undefined4 param_2,DWORD *param_3,LPVOID param_4)

{
  undefined8 *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  DWORD local_res8 [2];
  undefined4 local_res10 [2];
  _OVERLAPPED local_30;
  
                    /* 0x3990  18  WinUsb_QueryDeviceInformation */
  local_res8[0] = 0;
  local_30.Internal = 0;
  local_30.InternalHigh = 0;
  local_30.u.Pointer = (PVOID)0x0;
  local_30.hEvent = (HANDLE)0x0;
  local_res10[0] = param_2;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_30.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_30.hEvent != (HANDLE)0x0) {
      local_30.hEvent = (HANDLE)((ulonglong)local_30.hEvent | 1);
      BVar2 = DeviceIoControl((HANDLE)*puVar1,0x350c04c,local_res10,4,param_4,*param_3,local_res8,
                              &local_30);
      if (BVar2 == 0) {
        DVar3 = GetLastError();
        BVar2 = 0;
        if (DVar3 != 0x3e5) goto LAB_180003aa2;
      }
      BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_30,local_res8,1);
      if (BVar2 != 0) {
        *param_3 = local_res8[0];
      }
      goto LAB_180003aa2;
    }
  }
  BVar2 = 0;
LAB_180003aa2:
  if (local_30.hEvent != (HANDLE)0x0) {
    CloseHandle(local_30.hEvent);
  }
  return BVar2;
}



===== WinUsb_QueryInterfaceSettings @ 180003ae0 =====

bool WinUsb_QueryInterfaceSettings(longlong *param_1,byte param_2,undefined8 *param_3)

{
  byte *pbVar1;
  bool bVar2;
  
                    /* 0x3ae0  19  WinUsb_QueryInterfaceSettings */
  if (param_1 == (longlong *)0x0) {
    SetLastError(6);
    bVar2 = false;
  }
  else {
    pbVar1 = WinUsb_ParseConfigurationDescriptor
                       (*(longlong *)(*param_1 + 0x20),(byte *)param_1[1],
                        (uint)((byte *)param_1[1])[2],(uint)param_2,0xffffffff,0xffffffff,0xffffffff
                       );
    bVar2 = pbVar1 != (byte *)0x0;
    if (bVar2) {
      *param_3 = *(undefined8 *)pbVar1;
      *(byte *)(param_3 + 1) = pbVar1[8];
    }
    else {
      SetLastError(0x103);
    }
  }
  return bVar2;
}



===== WinUsb_QueryPipe @ 180003b80 =====

undefined8 WinUsb_QueryPipe(longlong *param_1,byte param_2,byte param_3,uint *param_4)

{
  longlong lVar1;
  longlong lVar2;
  byte *pbVar3;
  DWORD dwErrCode;
  ulonglong uVar4;
  
                    /* 0x3b80  20  WinUsb_QueryPipe */
  if (param_1 == (longlong *)0x0) {
    dwErrCode = 6;
  }
  else {
    lVar1 = *param_1;
    if ((param_4 == (uint *)0x0) ||
       (pbVar3 = WinUsb_ParseConfigurationDescriptor
                           (*(longlong *)(lVar1 + 0x20),(byte *)param_1[1],
                            (uint)((byte *)param_1[1])[2],(uint)param_2,0xffffffff,0xffffffff,
                            0xffffffff), pbVar3 == (byte *)0x0)) {
      dwErrCode = 0x57;
    }
    else {
      if (param_3 < pbVar3[4]) {
        uVar4 = (ulonglong)(param_3 + 1);
        do {
          lVar2 = *(longlong *)(lVar1 + 0x20);
          pbVar3 = WinUsb_ParseDescriptors(lVar2,(uint)*(ushort *)(lVar2 + 2),pbVar3 + *pbVar3,5);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        if (pbVar3 != (byte *)0x0) {
          *param_4 = pbVar3[3] & 3;
          *(byte *)(param_4 + 1) = pbVar3[2];
          *(undefined2 *)((longlong)param_4 + 6) = *(undefined2 *)(pbVar3 + 4);
          *(byte *)(param_4 + 2) = pbVar3[6];
          return 1;
        }
      }
      dwErrCode = 0x103;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



===== WinUsb_QueryPipeEx @ 180003c80 =====

undefined8 WinUsb_QueryPipeEx(longlong *param_1,byte param_2,byte param_3,uint *param_4)

{
  ushort uVar1;
  longlong lVar2;
  byte *pbVar3;
  DWORD dwErrCode;
  uint uVar4;
  ulonglong uVar5;
  byte *pbVar6;
  
                    /* 0x3c80  21  WinUsb_QueryPipeEx */
  if (param_1 == (longlong *)0x0) {
    dwErrCode = 6;
  }
  else {
    lVar2 = *param_1;
    if ((param_4 == (uint *)0x0) ||
       (pbVar3 = WinUsb_ParseConfigurationDescriptor
                           (*(longlong *)(lVar2 + 0x20),(byte *)param_1[1],
                            (uint)((byte *)param_1[1])[2],(uint)param_2,0xffffffff,0xffffffff,
                            0xffffffff), pbVar3 == (byte *)0x0)) {
      dwErrCode = 0x57;
    }
    else {
      if (param_3 < pbVar3[4]) {
        uVar5 = (ulonglong)(param_3 + 1);
        do {
          pbVar3 = WinUsb_ParseDescriptors
                             (*(longlong *)(lVar2 + 0x20),
                              (uint)*(ushort *)(*(longlong *)(lVar2 + 0x20) + 2),pbVar3 + *pbVar3,5)
          ;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
        if (pbVar3 != (byte *)0x0) {
          *param_4 = pbVar3[3] & 3;
          *(byte *)(param_4 + 1) = pbVar3[2];
          *(ushort *)((longlong)param_4 + 6) = *(ushort *)(pbVar3 + 4);
          *(byte *)(param_4 + 2) = pbVar3[6];
          pbVar6 = pbVar3 + *pbVar3;
          if ((pbVar6 < (byte *)((ulonglong)*(ushort *)(*(longlong *)(lVar2 + 0x20) + 2) +
                                *(longlong *)(lVar2 + 0x20))) && (pbVar6[1] == 0x30)) {
            if ((pbVar3[3] == 1) && ((char)pbVar6[3] < '\0')) {
              pbVar3 = pbVar6 + *pbVar6;
              if ((pbVar3 + *pbVar3 <=
                   (byte *)((ulonglong)*(ushort *)(*(longlong *)(lVar2 + 0x20) + 2) +
                           *(longlong *)(lVar2 + 0x20))) && ((*pbVar3 == 8 && (pbVar3[1] == 0x31))))
              {
                uVar4 = *(uint *)(pbVar3 + 4);
                goto LAB_180003dce;
              }
            }
            uVar4 = (uint)*(ushort *)(pbVar6 + 4);
          }
          else {
            uVar1 = *(ushort *)(pbVar3 + 4);
            uVar4 = (uint)uVar1;
            if (*(char *)(lVar2 + 0x3a) == '\x03') {
              uVar4 = ((uVar1 >> 0xb & 3) + 1) * (uVar4 & 0x7ff);
            }
          }
LAB_180003dce:
          param_4[3] = uVar4;
          return 1;
        }
      }
      dwErrCode = 0x103;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



===== WinUsb_ReadIsochPipe @ 180003e10 =====

void WinUsb_ReadIsochPipe
               (longlong *param_1,uint param_2,uint param_3,int *param_4,uint param_5,LPVOID param_6
               ,LPOVERLAPPED param_7)

{
                    /* 0x3e10  22  WinUsb_ReadIsochPipe */
  WinUsb_ReadIsochPipeInternal(param_1,param_2,param_3,0,0,param_4,param_5,param_6,param_7);
  return;
}



===== WinUsb_ReadIsochPipeAsap @ 180003e60 =====

void WinUsb_ReadIsochPipeAsap
               (longlong *param_1,uint param_2,uint param_3,int param_4,uint param_5,LPVOID param_6,
               LPOVERLAPPED param_7)

{
                    /* 0x3e60  23  WinUsb_ReadIsochPipeAsap */
  WinUsb_ReadIsochPipeInternal(param_1,param_2,param_3,param_4,1,(int *)0x0,param_5,param_6,param_7)
  ;
  return;
}



===== WinUsb_ReadIsochPipeInternal @ 180003ea8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WinUsb_ReadIsochPipeInternal
                    (longlong *param_1,uint param_2,uint param_3,int param_4,int param_5,
                    int *param_6,uint param_7,LPVOID param_8,LPOVERLAPPED param_9)

{
  ulonglong uVar1;
  byte bVar2;
  char cVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  DWORD DVar7;
  ulonglong uVar8;
  LPOVERLAPPED lpOverlapped;
  ulonglong uVar9;
  int iVar10;
  undefined1 auStackY_e8 [32];
  DWORD local_90 [2];
  LPVOID local_88;
  _OVERLAPPED local_80;
  undefined8 local_60;
  longlong *plStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_88 = param_8;
  local_60 = 0;
  plStack_58 = (longlong *)0x0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_80.Internal = 0;
  local_80.InternalHigh = 0;
  local_80.u.Pointer = (PVOID)0x0;
  local_80.hEvent = (HANDLE)0x0;
  local_90[0] = 0;
  if ((((param_3 == 0) || (param_1 == (longlong *)0x0)) || (param_7 == 0)) ||
     ((param_5 == 0 && (param_6 == (int *)0x0)))) goto LAB_180004201;
  uVar8 = WinUsb_ValidateBuffer();
  uVar9 = uVar8 & 0xffffffff;
  if ((int)uVar8 != 0) {
    if (((longlong *)param_1[2] == param_1) && (param_7 < 0x15555556)) {
      uVar8 = WinUsb_ValidateBuffer();
      uVar9 = uVar8 & 0xffffffff;
      if ((int)uVar8 != 0) {
        lVar4 = param_1[1];
        local_50 = CONCAT44(param_3,param_2);
        bVar2 = *(byte *)((longlong)param_1 + 0x19);
        local_60 = CONCAT62(local_60._2_6_,(short)param_1[3]);
        uStack_48 = CONCAT71(CONCAT61(uStack_48._2_6_,param_4 != 0),param_5 != 0);
        local_40 = CONCAT44(local_40._4_4_,param_7);
        uVar6 = (uint)bVar2;
        uVar8 = (ulonglong)(bVar2 & 0xf) + 0x10;
        if (-1 < (char)bVar2) {
          uVar8 = (ulonglong)(bVar2 & 0xf);
        }
        plStack_58 = param_1;
        if (*(char *)(lVar4 + (uVar8 + 1) * 0x14) == '\0') {
LAB_180004201:
          DVar7 = 0x57;
LAB_180004206:
          SetLastError(DVar7);
        }
        else {
          uVar8 = (ulonglong)(uVar6 & 0xf);
          if ((char)bVar2 < '\0') {
            uVar8 = uVar8 + 0x10;
          }
          if (*(int *)(lVar4 + 0x24 + uVar8 * 0x14) == 0) goto LAB_180004201;
          if (param_6 != (int *)0x0) {
            uStack_48 = CONCAT44(*param_6,(undefined4)uStack_48);
          }
          if (param_5 == 0) {
            uVar5 = uVar6 & 0xf;
            if ((char)bVar2 < '\0') {
              uVar5 = uVar5 + 0x10;
            }
            uVar5 = *(uint *)(lVar4 + 0x24 + (ulonglong)uVar5 * 0x14);
            uVar6 = uVar6 & 0xf;
            if ((char)bVar2 < '\0') {
              uVar6 = uVar6 + 0x10;
            }
            cVar3 = *(char *)(lVar4 + 0x20 + (ulonglong)uVar6 * 0x14);
            if (cVar3 == '\x01') {
              iVar10 = 1;
            }
            else if (cVar3 == '\x02') {
              iVar10 = 2;
            }
            else if (cVar3 == '\x03') {
              iVar10 = 4;
            }
            else {
              iVar10 = 8;
            }
            uVar6 = param_3 / uVar5;
            if (param_3 % uVar5 != 0) {
              uVar6 = uVar6 + 1;
            }
            if ((*(char *)(*param_1 + 0x3a) == '\x03') &&
               (uVar5 = iVar10 * uVar6, uVar6 = uVar5 >> 3, (uVar5 & 7) != 0)) {
              uVar6 = uVar6 + 1;
            }
            *param_6 = *param_6 + uVar6;
          }
          uVar9 = param_1[9];
          uVar8 = uVar9 + param_2;
          if ((((uVar8 < uVar9) ||
               (uVar1 = *(uint *)((longlong)param_1 + 0x44) + uVar9, uVar1 < uVar8)) ||
              (uVar9 = uVar9 + param_3 + (ulonglong)param_2, uVar9 < uVar8)) || (uVar1 < uVar9)) {
            DVar7 = 0x6f8;
            goto LAB_180004206;
          }
          if ((param_9 != (LPOVERLAPPED)0x0) ||
             (local_80.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0),
             local_80.hEvent != (HANDLE)0x0)) {
            lpOverlapped = &local_80;
            if (param_9 != (LPOVERLAPPED)0x0) {
              lpOverlapped = param_9;
            }
            uVar6 = DeviceIoControl(*(HANDLE *)*param_1,0x350007a,&local_60,0x28,local_88,
                                    param_7 * 0xc,(LPDWORD)0x0,lpOverlapped);
            uVar9 = (ulonglong)uVar6;
            if (((param_9 == (LPOVERLAPPED)0x0) && (uVar6 == 0)) &&
               (DVar7 = GetLastError(), DVar7 == 0x3e5)) {
              uVar6 = GetOverlappedResult(*(HANDLE *)*param_1,&local_80,local_90,1);
              uVar9 = (ulonglong)uVar6;
            }
            goto LAB_180004218;
          }
        }
        uVar9 = 0;
        goto LAB_180004218;
      }
    }
    else {
      uVar9 = 0;
    }
  }
  SetLastError(0x57);
LAB_180004218:
  if (local_80.hEvent != (HANDLE)0x0) {
    CloseHandle(local_80.hEvent);
  }
  return uVar9;
}



===== WinUsb_ReadPipe @ 180004270 =====

BOOL WinUsb_ReadPipe(undefined8 *param_1,undefined1 param_2,LPVOID param_3,DWORD param_4,
                    LPDWORD param_5,LPOVERLAPPED param_6)

{
  undefined8 *puVar1;
  bool bVar2;
  BOOL BVar3;
  DWORD DVar4;
  LPOVERLAPPED p_Var5;
  HANDLE pvVar6;
  undefined2 local_res8;
  undefined1 local_res10;
  
                    /* 0x4270  24  WinUsb_ReadPipe */
  p_Var5 = (LPOVERLAPPED)0x0;
  bVar2 = false;
  local_res8 = 0;
  if (param_5 != (LPDWORD)0x0) {
    *param_5 = 0;
  }
  local_res10 = param_2;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
    bVar2 = false;
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    if (param_6 != (LPOVERLAPPED)0x0) {
      bVar2 = false;
LAB_180004369:
      local_res8 = CONCAT11(local_res10,*(undefined1 *)(param_1 + 2));
      BVar3 = DeviceIoControl((HANDLE)*puVar1,0x350401e,&local_res8,2,param_3,param_4,param_5,
                              param_6);
      if ((bVar2) && ((BVar3 != 0 || (DVar4 = GetLastError(), DVar4 == 0x3e5)))) {
        BVar3 = GetOverlappedResult((HANDLE)*puVar1,param_6,param_5,1);
      }
      goto LAB_1800043f9;
    }
    pvVar6 = GetProcessHeap();
    p_Var5 = HeapAlloc(pvVar6,8,0x20);
    if (p_Var5 == (LPOVERLAPPED)0x0) {
      SetLastError(8);
    }
    else {
      bVar2 = true;
      pvVar6 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
      p_Var5->hEvent = pvVar6;
      if (pvVar6 != (HANDLE)0x0) {
        p_Var5->hEvent = (HANDLE)((ulonglong)pvVar6 | 1);
        param_6 = p_Var5;
        bVar2 = true;
        goto LAB_180004369;
      }
    }
  }
  BVar3 = 0;
  param_6 = p_Var5;
LAB_1800043f9:
  if ((bVar2) && (param_6 != (LPOVERLAPPED)0x0)) {
    if (param_6->hEvent != (HANDLE)0x0) {
      CloseHandle(param_6->hEvent);
    }
    pvVar6 = GetProcessHeap();
    HeapFree(pvVar6,0,param_6);
  }
  return BVar3;
}



===== WinUsb_RegisterIsochBuffer @ 180004460 =====

undefined8
WinUsb_RegisterIsochBuffer
          (undefined8 *param_1,char param_2,LPVOID param_3,uint param_4,undefined8 *param_5)

{
  undefined8 *puVar1;
  BOOL BVar2;
  HANDLE pvVar3;
  undefined8 *lpMem;
  DWORD DVar4;
  
                    /* 0x4460  25  WinUsb_RegisterIsochBuffer */
  *param_5 = 0;
  if ((param_4 == 0) || ((LPVOID)((longlong)param_3 + (ulonglong)param_4) < param_3)) {
    DVar4 = 0x6f8;
  }
  else if (param_1 == (undefined8 *)0x0) {
    DVar4 = 6;
  }
  else {
    pvVar3 = GetProcessHeap();
    lpMem = HeapAlloc(pvVar3,8,0x50);
    if (lpMem != (undefined8 *)0x0) {
      pvVar3 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
      lpMem[7] = pvVar3;
      if (pvVar3 != (HANDLE)0x0) {
        puVar1 = (undefined8 *)*param_1;
        *lpMem = puVar1;
        lpMem[1] = param_1;
        lpMem[2] = lpMem;
        lpMem[9] = param_3;
        *(uint *)((longlong)lpMem + 0x44) = param_4;
        *(char *)((longlong)lpMem + 0x19) = param_2;
        *(undefined1 *)(lpMem + 3) = *(undefined1 *)(param_1 + 2);
        lpMem[7] = (ulonglong)pvVar3 | 1;
        BVar2 = DeviceIoControl((HANDLE)*puVar1,((int)param_2 >> 0x1f & 0xffffc004U) + 0x350806e,
                                lpMem + 2,0x10,param_3,param_4,(LPDWORD)0x0,
                                (LPOVERLAPPED)(lpMem + 4));
        if ((BVar2 == 0) && (DVar4 = GetLastError(), DVar4 == 0x3e5)) {
          *param_5 = lpMem;
          return 1;
        }
        CloseHandle((HANDLE)lpMem[7]);
      }
      pvVar3 = GetProcessHeap();
      HeapFree(pvVar3,0,lpMem);
      return 0;
    }
    DVar4 = 8;
  }
  SetLastError(DVar4);
  return 0;
}



===== WinUsb_ResetPipe @ 180004610 =====

BOOL WinUsb_ResetPipe(undefined8 *param_1,undefined1 param_2)

{
  undefined8 *puVar1;
  BOOL BVar2;
  DWORD DVar3;
  DWORD local_res8 [2];
  _OVERLAPPED local_28;
  
                    /* 0x4610  26  WinUsb_ResetPipe */
  local_res8[0] = 0;
  local_28.Internal = 0;
  local_28.InternalHigh = 0;
  local_28.u.Pointer = (PVOID)0x0;
  local_28.hEvent = (HANDLE)0x0;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_28.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_28.hEvent != (HANDLE)0x0) {
      local_28.hEvent = (HANDLE)((ulonglong)local_28.hEvent | 1);
      BVar2 = WinUsb_ResetPipeAsync(param_1,param_2,&local_28);
      if (BVar2 == 0) {
        DVar3 = GetLastError();
        BVar2 = 0;
        if (DVar3 != 0x3e5) goto LAB_1800046ca;
      }
      BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_28,local_res8,1);
      goto LAB_1800046ca;
    }
  }
  BVar2 = 0;
LAB_1800046ca:
  if (local_28.hEvent != (HANDLE)0x0) {
    CloseHandle(local_28.hEvent);
  }
  return BVar2;
}



===== WinUsb_ResetPipeAsync @ 180004700 =====

BOOL WinUsb_ResetPipeAsync(undefined8 *param_1,undefined1 param_2,LPOVERLAPPED param_3)

{
  BOOL BVar1;
  undefined2 local_res8;
  DWORD local_res20 [2];
  
                    /* 0x4700  27  WinUsb_ResetPipeAsync */
  BVar1 = 0;
  local_res20[0] = 0;
  local_res8 = 0;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
  }
  else {
    local_res8 = CONCAT11(param_2,*(undefined1 *)(param_1 + 2));
    BVar1 = DeviceIoControl(*(HANDLE *)*param_1,0x350c024,&local_res8,2,(LPVOID)0x0,0,local_res20,
                            param_3);
  }
  return BVar1;
}



===== WinUsb_SetCurrentAlternateSetting @ 180004780 =====

ulonglong WinUsb_SetCurrentAlternateSetting(longlong *param_1,byte param_2)

{
  undefined8 *puVar1;
  DWORD DVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  DWORD local_res8 [2];
  _OVERLAPPED local_28;
  
                    /* 0x4780  28  WinUsb_SetCurrentAlternateSetting */
  local_res8[0] = 0;
  local_28.Internal = 0;
  local_28.InternalHigh = 0;
  local_28.u.Pointer = (PVOID)0x0;
  local_28.hEvent = (HANDLE)0x0;
  if (param_1 == (longlong *)0x0) {
    SetLastError(6);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_28.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_28.hEvent != (HANDLE)0x0) {
      local_28.hEvent = (HANDLE)((ulonglong)local_28.hEvent | 1);
      uVar4 = WinUsb_SetCurrentAlternateSettingAsync(param_1,param_2,&local_28);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 == 0) {
        DVar2 = GetLastError();
        if (DVar2 != 0x3e5) goto LAB_18000483a;
      }
      uVar3 = GetOverlappedResult((HANDLE)*puVar1,&local_28,local_res8,1);
      uVar5 = (ulonglong)uVar3;
      goto LAB_18000483a;
    }
  }
  uVar5 = 0;
LAB_18000483a:
  if (local_28.hEvent != (HANDLE)0x0) {
    CloseHandle(local_28.hEvent);
  }
  return uVar5;
}



===== WinUsb_SetCurrentAlternateSettingAsync @ 180004870 =====

ulonglong WinUsb_SetCurrentAlternateSettingAsync
                    (longlong *param_1,byte param_2,LPOVERLAPPED param_3)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  BOOL BVar4;
  byte *pbVar5;
  ulonglong uVar6;
  undefined4 extraout_var;
  byte bVar7;
  undefined2 local_res8;
  DWORD local_res20 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  
                    /* 0x4870  29  WinUsb_SetCurrentAlternateSettingAsync */
  local_res8 = 0;
  local_res20[0] = 0;
  if (param_1 == (longlong *)0x0) {
    SetLastError(6);
  }
  else {
    puVar2 = (undefined8 *)*param_1;
    local_res8 = CONCAT11(param_2,(char)param_1[2]);
    for (bVar7 = 0; bVar7 < 0x20; bVar7 = bVar7 + 1) {
      *(undefined1 *)((longlong)param_1 + ((ulonglong)bVar7 + 1) * 0x14) = 0;
    }
    pbVar5 = WinUsb_ParseConfigurationDescriptor
                       (puVar2[4],(byte *)param_1[1],(uint)((byte *)param_1[1])[2],(uint)param_2,
                        0xffffffff,0xffffffff,0xffffffff);
    if (pbVar5 != (byte *)0x0) {
      bVar7 = 0;
      while( true ) {
        if (pbVar5[4] <= bVar7) {
          BVar4 = DeviceIoControl((HANDLE)*puVar2,0x350c008,&local_res8,2,(LPVOID)0x0,0,local_res20,
                                  param_3);
          return CONCAT44(extraout_var,BVar4);
        }
        local_40 = 0;
        uStack_38 = 0;
        uVar6 = WinUsb_QueryPipeEx(param_1,param_2,bVar7,(uint *)&local_40);
        if ((int)uVar6 == 0) break;
        if ((local_40 & 0x8000000000) == 0) {
          uVar3 = local_40._4_1_ & 0xf;
        }
        else {
          uVar3 = (local_40._4_1_ & 0xf) + 0x10;
        }
        *(undefined1 *)((longlong)param_1 + ((ulonglong)uVar3 + 1) * 0x14) = 1;
        uVar3 = local_40._4_1_ & 0xf;
        if ((local_40 & 0x8000000000) != 0) {
          uVar3 = uVar3 + 0x10;
        }
        puVar1 = (uint *)((longlong)param_1 + (ulonglong)uVar3 * 0x14 + 0x18);
        *puVar1 = (uint)local_40;
        puVar1[1] = local_40._4_4_;
        puVar1[2] = (uint)uStack_38;
        puVar1[3] = uStack_38._4_4_;
        bVar7 = bVar7 + 1;
      }
      return uVar6;
    }
  }
  return 0;
}



===== WinUsb_SetPipePolicy @ 180004a00 =====

BOOL WinUsb_SetPipePolicy
               (undefined8 *param_1,undefined1 param_2,undefined4 param_3,uint param_4,void *param_5
               )

{
  undefined8 *puVar1;
  BOOL BVar2;
  undefined1 *lpInBuffer;
  HANDLE pvVar3;
  DWORD DVar4;
  DWORD local_res8 [2];
  undefined1 local_res10;
  _OVERLAPPED local_50;
  
                    /* 0x4a00  30  WinUsb_SetPipePolicy */
  local_res8[0] = 0;
  lpInBuffer = (undefined1 *)0x0;
  local_50.Internal = 0;
  local_50.InternalHigh = 0;
  local_50.u.Pointer = (PVOID)0x0;
  local_50.hEvent = (HANDLE)0x0;
  local_res10 = param_2;
  if (param_1 == (undefined8 *)0x0) {
    DVar4 = 6;
LAB_180004a45:
    SetLastError(DVar4);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_50.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_50.hEvent != (HANDLE)0x0) {
      if (param_4 < 0xfffffff4) {
        local_50.hEvent = (HANDLE)((ulonglong)local_50.hEvent | 1);
        pvVar3 = GetProcessHeap();
        lpInBuffer = HeapAlloc(pvVar3,8,(ulonglong)(param_4 + 0xc));
        if (lpInBuffer != (undefined1 *)0x0) {
          lpInBuffer[1] = local_res10;
          *(undefined4 *)(lpInBuffer + 4) = param_3;
          *(uint *)(lpInBuffer + 8) = param_4;
          *lpInBuffer = *(undefined1 *)(param_1 + 2);
          memcpy(lpInBuffer + 0xc,param_5,(ulonglong)param_4);
          BVar2 = DeviceIoControl((HANDLE)*puVar1,0x350c00c,lpInBuffer,param_4 + 0xc,(LPVOID)0x0,0,
                                  local_res8,&local_50);
          if (BVar2 == 0) {
            DVar4 = GetLastError();
            BVar2 = 0;
            if (DVar4 != 0x3e5) goto LAB_180004b74;
          }
          BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_50,local_res8,1);
          goto LAB_180004b74;
        }
        DVar4 = 8;
      }
      else {
        DVar4 = 0x57;
      }
      goto LAB_180004a45;
    }
  }
  BVar2 = 0;
LAB_180004b74:
  if (local_50.hEvent != (HANDLE)0x0) {
    CloseHandle(local_50.hEvent);
  }
  if (lpInBuffer != (undefined1 *)0x0) {
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,lpInBuffer);
  }
  return BVar2;
}



===== WinUsb_SetPowerPolicy @ 180004be0 =====

BOOL WinUsb_SetPowerPolicy(undefined8 *param_1,undefined4 param_2,uint param_3,void *param_4)

{
  undefined8 *puVar1;
  BOOL BVar2;
  undefined1 *lpInBuffer;
  HANDLE pvVar3;
  DWORD DVar4;
  DWORD local_res8 [2];
  undefined4 local_res10;
  _OVERLAPPED local_50;
  
                    /* 0x4be0  31  WinUsb_SetPowerPolicy */
  local_res8[0] = 0;
  lpInBuffer = (undefined1 *)0x0;
  local_50.Internal = 0;
  local_50.InternalHigh = 0;
  local_50.u.Pointer = (PVOID)0x0;
  local_50.hEvent = (HANDLE)0x0;
  local_res10 = param_2;
  if (param_1 == (undefined8 *)0x0) {
    DVar4 = 6;
LAB_180004c25:
    SetLastError(DVar4);
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    local_50.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_50.hEvent != (HANDLE)0x0) {
      if (param_3 < 0xfffffff4) {
        local_50.hEvent = (HANDLE)((ulonglong)local_50.hEvent | 1);
        pvVar3 = GetProcessHeap();
        lpInBuffer = HeapAlloc(pvVar3,8,(ulonglong)(param_3 + 0xc));
        BVar2 = 0;
        if (lpInBuffer == (undefined1 *)0x0) {
          SetLastError(8);
        }
        else {
          *lpInBuffer = *(undefined1 *)(param_1 + 2);
          lpInBuffer[1] = 0;
          *(undefined4 *)(lpInBuffer + 4) = local_res10;
          *(uint *)(lpInBuffer + 8) = param_3;
          memcpy(lpInBuffer + 0xc,param_4,(ulonglong)param_3);
          BVar2 = DeviceIoControl((HANDLE)*puVar1,0x350c02c,lpInBuffer,param_3 + 0xc,(LPVOID)0x0,0,
                                  local_res8,&local_50);
          if (BVar2 == 0) {
            DVar4 = GetLastError();
            BVar2 = 0;
            if (DVar4 != 0x3e5) goto LAB_180004d59;
          }
          BVar2 = GetOverlappedResult((HANDLE)*puVar1,&local_50,local_res8,1);
        }
        goto LAB_180004d59;
      }
      DVar4 = 0x57;
      goto LAB_180004c25;
    }
  }
  BVar2 = 0;
LAB_180004d59:
  if (local_50.hEvent != (HANDLE)0x0) {
    CloseHandle(local_50.hEvent);
  }
  if (lpInBuffer != (undefined1 *)0x0) {
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,lpInBuffer);
  }
  return BVar2;
}



===== WinUsb_StartTrackingForTimeSync @ 180004dc0 =====

BOOL WinUsb_StartTrackingForTimeSync(undefined8 *param_1,LPVOID param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_res18 [4];
  _OVERLAPPED local_30;
  
                    /* 0x4dc0  32  WinUsb_StartTrackingForTimeSync */
  local_30.Internal = 0;
  local_30.InternalHigh = 0;
  local_30.u.Pointer = (PVOID)0x0;
  local_30.hEvent = (HANDLE)0x0;
  local_res18[0] = 0;
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (LPVOID)0x0)) {
    SetLastError(0x57);
  }
  else {
    local_30.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_30.hEvent != (HANDLE)0x0) {
      BVar1 = DeviceIoControl(*(HANDLE *)*param_1,0x350c080,param_2,9,param_2,9,local_res18,
                              &local_30);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        if (DVar2 == 0x3e5) {
          BVar1 = GetOverlappedResult(*(HANDLE *)*param_1,&local_30,local_res18,1);
          if ((BVar1 != 0) && (local_res18[0] != 9)) {
            SetLastError(0x57);
          }
        }
      }
      goto LAB_180004edb;
    }
  }
  BVar1 = 0;
LAB_180004edb:
  if (local_30.hEvent != (HANDLE)0x0) {
    CloseHandle(local_30.hEvent);
  }
  return BVar1;
}



===== WinUsb_StopTrackingForTimeSync @ 180004f10 =====

BOOL WinUsb_StopTrackingForTimeSync(undefined8 *param_1,LPVOID param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_res18 [4];
  _OVERLAPPED local_30;
  
                    /* 0x4f10  33  WinUsb_StopTrackingForTimeSync */
  local_30.Internal = 0;
  local_30.InternalHigh = 0;
  local_30.u.Pointer = (PVOID)0x0;
  local_30.hEvent = (HANDLE)0x0;
  local_res18[0] = 0;
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (LPVOID)0x0)) {
    SetLastError(0x57);
  }
  else {
    local_30.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
    if (local_30.hEvent != (HANDLE)0x0) {
      BVar1 = DeviceIoControl(*(HANDLE *)*param_1,0x350c088,param_2,8,param_2,8,local_res18,
                              &local_30);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        if (DVar2 == 0x3e5) {
          BVar1 = GetOverlappedResult(*(HANDLE *)*param_1,&local_30,local_res18,1);
          if ((BVar1 != 0) && (local_res18[0] != 8)) {
            SetLastError(0x57);
          }
        }
      }
      goto LAB_18000502b;
    }
  }
  BVar1 = 0;
LAB_18000502b:
  if (local_30.hEvent != (HANDLE)0x0) {
    CloseHandle(local_30.hEvent);
  }
  return BVar1;
}



===== WinUsb_UnregisterIsochBuffer @ 180005060 =====

BOOL WinUsb_UnregisterIsochBuffer(undefined8 *param_1)

{
  BOOL BVar1;
  undefined8 uVar2;
  HANDLE hHeap;
  
                    /* 0x5060  34  WinUsb_UnregisterIsochBuffer */
  if ((param_1 == (undefined8 *)0x0) || (uVar2 = WinUsb_ValidateBuffer(), (int)uVar2 == 0)) {
    SetLastError(6);
    return 0;
  }
  BVar1 = CancelIoEx(*(HANDLE *)*param_1,(LPOVERLAPPED)(param_1 + 4));
  if (BVar1 == 0) {
    return 0;
  }
  WaitForSingleObject((HANDLE)param_1[7],0xffffffff);
  CloseHandle((HANDLE)param_1[7]);
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,param_1);
  return BVar1;
}



===== WinUsb_ValidateBuffer @ 180005118 =====

undefined8 WinUsb_ValidateBuffer(void)

{
  return 1;
}



===== WinUsb_WriteIsochPipe @ 180005140 =====

void WinUsb_WriteIsochPipe
               (longlong *param_1,uint param_2,uint param_3,int *param_4,LPOVERLAPPED param_5)

{
                    /* 0x5140  35  WinUsb_WriteIsochPipe */
  WinUsb_WriteIsochPipeInternal(param_1,param_2,param_3,0,0,param_4,param_5);
  return;
}



===== WinUsb_WriteIsochPipeAsap @ 180005170 =====

void WinUsb_WriteIsochPipeAsap
               (longlong *param_1,uint param_2,uint param_3,int param_4,LPOVERLAPPED param_5)

{
                    /* 0x5170  36  WinUsb_WriteIsochPipeAsap */
  WinUsb_WriteIsochPipeInternal(param_1,param_2,param_3,param_4,1,(int *)0x0,param_5);
  return;
}



===== WinUsb_WriteIsochPipeInternal @ 1800051a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WinUsb_WriteIsochPipeInternal
                    (longlong *param_1,uint param_2,uint param_3,int param_4,int param_5,
                    int *param_6,LPOVERLAPPED param_7)

{
  ulonglong uVar1;
  byte bVar2;
  char cVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  DWORD DVar7;
  ulonglong uVar8;
  LPOVERLAPPED lpOverlapped;
  ulonglong uVar9;
  int iVar10;
  undefined1 auStackY_d8 [32];
  DWORD local_88 [2];
  _OVERLAPPED local_80;
  undefined8 local_60;
  longlong *plStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_60 = 0;
  plStack_58 = (longlong *)0x0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_80.Internal = 0;
  local_80.InternalHigh = 0;
  local_80.u.Pointer = (PVOID)0x0;
  local_80.hEvent = (HANDLE)0x0;
  local_88[0] = 0;
  if (param_3 == 0) {
LAB_18000520b:
    DVar7 = 0x6f8;
LAB_180005210:
    SetLastError(DVar7);
LAB_18000521c:
    uVar9 = 0;
  }
  else {
    if ((param_1 == (longlong *)0x0) || ((param_5 == 0 && (param_6 == (int *)0x0))))
    goto LAB_18000522c;
    uVar8 = WinUsb_ValidateBuffer();
    uVar9 = uVar8 & 0xffffffff;
    if ((int)uVar8 == 0) {
      DVar7 = 0x6f8;
    }
    else {
      if ((longlong *)param_1[2] == param_1) {
        lVar4 = param_1[1];
        local_50 = CONCAT44(param_3,param_2);
        bVar2 = *(byte *)((longlong)param_1 + 0x19);
        local_60 = CONCAT62(local_60._2_6_,(short)param_1[3]);
        uStack_48 = CONCAT71(CONCAT61(uStack_48._2_6_,param_4 != 0),param_5 != 0);
        uVar6 = (uint)bVar2;
        uVar8 = (ulonglong)(bVar2 & 0xf) + 0x10;
        if (-1 < (char)bVar2) {
          uVar8 = (ulonglong)(bVar2 & 0xf);
        }
        plStack_58 = param_1;
        if (*(char *)(lVar4 + (uVar8 + 1) * 0x14) == '\0') {
LAB_18000522c:
          DVar7 = 0x57;
          goto LAB_180005210;
        }
        uVar8 = (ulonglong)(uVar6 & 0xf);
        if ((char)bVar2 < '\0') {
          uVar8 = uVar8 + 0x10;
        }
        if (*(int *)(lVar4 + 0x24 + uVar8 * 0x14) == 0) goto LAB_18000522c;
        if (param_6 != (int *)0x0) {
          uStack_48 = CONCAT44(*param_6,(undefined4)uStack_48);
        }
        if (param_5 == 0) {
          uVar5 = uVar6 & 0xf;
          if ((char)bVar2 < '\0') {
            uVar5 = uVar5 + 0x10;
          }
          uVar5 = *(uint *)(lVar4 + 0x24 + (ulonglong)uVar5 * 0x14);
          uVar6 = uVar6 & 0xf;
          if ((char)bVar2 < '\0') {
            uVar6 = uVar6 + 0x10;
          }
          cVar3 = *(char *)(lVar4 + 0x20 + (ulonglong)uVar6 * 0x14);
          if (cVar3 == '\x01') {
            iVar10 = 1;
          }
          else if (cVar3 == '\x02') {
            iVar10 = 2;
          }
          else if (cVar3 == '\x03') {
            iVar10 = 4;
          }
          else {
            iVar10 = 8;
          }
          uVar6 = param_3 / uVar5;
          if (param_3 % uVar5 != 0) {
            uVar6 = uVar6 + 1;
          }
          if ((*(char *)(*param_1 + 0x3a) == '\x03') &&
             (uVar5 = iVar10 * uVar6, uVar6 = uVar5 >> 3, (uVar5 & 7) != 0)) {
            uVar6 = uVar6 + 1;
          }
          if (param_6 != (int *)0x0) {
            *param_6 = *param_6 + uVar6;
          }
        }
        uVar9 = param_1[9];
        uVar8 = uVar9 + param_2;
        if ((((uVar8 < uVar9) ||
             (uVar1 = *(uint *)((longlong)param_1 + 0x44) + uVar9, uVar1 < uVar8)) ||
            (uVar9 = uVar9 + param_3 + (ulonglong)param_2, uVar9 < uVar8)) || (uVar1 < uVar9))
        goto LAB_18000520b;
        if ((param_7 != (LPOVERLAPPED)0x0) ||
           (local_80.hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0),
           local_80.hEvent != (HANDLE)0x0)) {
          lpOverlapped = &local_80;
          if (param_7 != (LPOVERLAPPED)0x0) {
            lpOverlapped = param_7;
          }
          uVar6 = DeviceIoControl(*(HANDLE *)*param_1,0x3500076,&local_60,0x28,(LPVOID)0x0,0,
                                  (LPDWORD)0x0,lpOverlapped);
          uVar9 = (ulonglong)uVar6;
          if (((param_7 == (LPOVERLAPPED)0x0) && (uVar6 == 0)) &&
             (DVar7 = GetLastError(), DVar7 == 0x3e5)) {
            uVar6 = GetOverlappedResult(*(HANDLE *)*param_1,&local_80,local_88,1);
            uVar9 = (ulonglong)uVar6;
          }
          goto LAB_1800054b9;
        }
        goto LAB_18000521c;
      }
      DVar7 = 0x57;
    }
    SetLastError(DVar7);
  }
LAB_1800054b9:
  if (local_80.hEvent != (HANDLE)0x0) {
    CloseHandle(local_80.hEvent);
  }
  return uVar9;
}



===== WinUsb_WritePipe @ 180005500 =====

BOOL WinUsb_WritePipe(undefined8 *param_1,undefined1 param_2,LPVOID param_3,DWORD param_4,
                     LPDWORD param_5,LPOVERLAPPED param_6)

{
  undefined8 *puVar1;
  bool bVar2;
  BOOL BVar3;
  DWORD DVar4;
  LPOVERLAPPED p_Var5;
  HANDLE pvVar6;
  undefined2 local_res8;
  undefined1 local_res10;
  
                    /* 0x5500  37  WinUsb_WritePipe */
  p_Var5 = (LPOVERLAPPED)0x0;
  bVar2 = false;
  local_res8 = 0;
  if (param_5 != (LPDWORD)0x0) {
    *param_5 = 0;
  }
  local_res10 = param_2;
  if (param_1 == (undefined8 *)0x0) {
    SetLastError(6);
    bVar2 = false;
  }
  else {
    puVar1 = (undefined8 *)*param_1;
    if (param_6 != (LPOVERLAPPED)0x0) {
      bVar2 = false;
LAB_1800055f9:
      local_res8 = CONCAT11(local_res10,*(undefined1 *)(param_1 + 2));
      BVar3 = DeviceIoControl((HANDLE)*puVar1,0x3508021,&local_res8,2,param_3,param_4,param_5,
                              param_6);
      if ((bVar2) && ((BVar3 != 0 || (DVar4 = GetLastError(), DVar4 == 0x3e5)))) {
        BVar3 = GetOverlappedResult((HANDLE)*puVar1,param_6,param_5,1);
      }
      goto LAB_180005689;
    }
    pvVar6 = GetProcessHeap();
    p_Var5 = HeapAlloc(pvVar6,8,0x20);
    if (p_Var5 == (LPOVERLAPPED)0x0) {
      SetLastError(8);
    }
    else {
      bVar2 = true;
      pvVar6 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
      p_Var5->hEvent = pvVar6;
      if (pvVar6 != (HANDLE)0x0) {
        p_Var5->hEvent = (HANDLE)((ulonglong)pvVar6 | 1);
        param_6 = p_Var5;
        bVar2 = true;
        goto LAB_1800055f9;
      }
    }
  }
  BVar3 = 0;
  param_6 = p_Var5;
LAB_180005689:
  if ((bVar2) && (param_6 != (LPOVERLAPPED)0x0)) {
    if (param_6->hEvent != (HANDLE)0x0) {
      CloseHandle(param_6->hEvent);
    }
    pvVar6 = GetProcessHeap();
    HeapFree(pvVar6,0,param_6);
  }
  return BVar3;
}



===== __GSHandlerCheck_SEH @ 1800056ec =====

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



===== __GSHandlerCheckCommon @ 180005778 =====

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



===== memcpy @ 1800057d9 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800057d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== _guard_dispatch_icall @ 180005800 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 180005820 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180005820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 180005840 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== fin$0 @ 18000584c =====

void `dllmain_crt_process_attach'::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}



===== fin$0 @ 180005869 =====

void `dllmain_crt_process_detach'::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}



===== fin$1 @ 180005882 =====

void `dllmain_crt_process_detach'::__l1::fin_1(void)

{
  __scrt_dllmain_uninitialize_critical();
  return;
}



===== filt$0 @ 18000589c =====

void `dllmain_dispatch'::__l1::filt_0(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),dllmain_crt_dispatch,*(undefined4 *)*param_1,param_1);
  return;
}



===== __scrt_is_nonwritable_in_current_image$filt$0 @ 1800058d8 =====

bool __scrt_is_nonwritable_in_current_image_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== WinUsb_AbortPipe$fin$0 @ 1800058f6 =====

void WinUsb_AbortPipe_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(HANDLE *)(param_2 + 0x38) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_2 + 0x38));
  }
  return;
}



===== WinUsb_AbortPipeAsync$fin$0 @ 180005922 =====

void WinUsb_AbortPipeAsync_fin_0(void)

{
  return;
}



===== WinUsb_ControlTransfer$fin$0 @ 180005938 =====

void WinUsb_ControlTransfer_fin_0(undefined8 param_1,longlong param_2)

{
  LPVOID lpMem;
  HANDLE hHeap;
  
  if ((*(int *)(param_2 + 0x44) != 0) && (lpMem = *(LPVOID *)(param_2 + 0x50), lpMem != (LPVOID)0x0)
     ) {
    if (*(longlong *)((longlong)lpMem + 0x18) != 0) {
      CloseHandle(*(HANDLE *)((longlong)lpMem + 0x18));
    }
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  return;
}



===== WinUsb_FlushPipe$fin$0 @ 180005998 =====

void WinUsb_FlushPipe_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(HANDLE *)(param_2 + 0x58) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_2 + 0x58));
  }
  return;
}



===== WinUsb_GetAdjustedFrameNumber$fin$0 @ 1800059c4 =====

void WinUsb_GetAdjustedFrameNumber_fin_0(void)

{
  return;
}



===== WinUsb_GetAssociatedInterface$fin$0 @ 1800059da =====

void WinUsb_GetAssociatedInterface_fin_0(undefined8 param_1,longlong param_2)

{
  LPVOID lpMem;
  HANDLE hHeap;
  
  if ((*(int *)(param_2 + 0x44) == 0) && (lpMem = *(LPVOID *)(param_2 + 0x48), lpMem != (LPVOID)0x0)
     ) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  return;
}



===== WinUsb_GetCurrentFrameNumber$fin$0 @ 180005a22 =====

void WinUsb_GetCurrentFrameNumber_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(HANDLE *)(param_2 + 0x60) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_2 + 0x60));
  }
  return;
}



===== WinUsb_Initialize$fin$0 @ 180005a4e =====

void WinUsb_Initialize_fin_0(undefined8 param_1,longlong param_2)

{
  LPVOID pvVar1;
  HANDLE pvVar2;
  
  if (*(int *)(param_2 + 0x40) == 0) {
    pvVar1 = *(LPVOID *)(param_2 + 0x88);
    if (pvVar1 != (LPVOID)0x0) {
      if (*(longlong *)((longlong)pvVar1 + 0x20) != 0) {
        pvVar2 = GetProcessHeap();
        HeapFree(pvVar2,0,*(LPVOID *)((longlong)pvVar1 + 0x20));
      }
      pvVar2 = GetProcessHeap();
      HeapFree(pvVar2,0,pvVar1);
      *(undefined8 *)(param_2 + 0x88) = 0;
    }
    pvVar1 = *(LPVOID *)(param_2 + 0x90);
    if (pvVar1 != (LPVOID)0x0) {
      pvVar2 = GetProcessHeap();
      HeapFree(pvVar2,0,pvVar1);
      *(undefined8 *)(param_2 + 0x90) = 0;
    }
  }
  if (*(HANDLE *)(param_2 + 0x78) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_2 + 0x78));
  }
  return;
}



===== WinUsb_ReadIsochPipeInternal$fin$0 @ 180005b17 =====

void WinUsb_ReadIsochPipeInternal_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(HANDLE *)(param_2 + 0x80) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_2 + 0x80));
  }
  return;
}



===== WinUsb_ReadPipe$fin$0 @ 180005b46 =====

void WinUsb_ReadPipe_fin_0(undefined8 param_1,longlong param_2)

{
  LPVOID lpMem;
  HANDLE hHeap;
  
  if ((*(int *)(param_2 + 0x44) != 0) && (lpMem = *(LPVOID *)(param_2 + 0x48), lpMem != (LPVOID)0x0)
     ) {
    if (*(longlong *)((longlong)lpMem + 0x18) != 0) {
      CloseHandle(*(HANDLE *)((longlong)lpMem + 0x18));
    }
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  return;
}



===== WinUsb_SetPipePolicy$fin$0 @ 180005ba6 =====

void WinUsb_SetPipePolicy_fin_0(undefined8 param_1,longlong param_2)

{
  LPVOID lpMem;
  HANDLE hHeap;
  
  if (*(HANDLE *)(param_2 + 0x60) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_2 + 0x60));
  }
  lpMem = *(LPVOID *)(param_2 + 0x40);
  if (lpMem != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  return;
}



===== WinUsb_WriteIsochPipeInternal$fin$0 @ 180005bfe =====

void WinUsb_WriteIsochPipeInternal_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(HANDLE *)(param_2 + 0x70) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_2 + 0x70));
  }
  return;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 180006010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


