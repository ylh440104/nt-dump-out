
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
      DAT_1800100d0 = DAT_1800100d0 + 1;
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
  if (DAT_1800100d0 < 1) {
    uVar1 = 0;
  }
  else {
    DAT_1800100d0 = DAT_1800100d0 + -1;
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

ulonglong dllmain_dispatch(undefined8 param_1,int param_2,longlong param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if ((param_2 == 0) && (DAT_1800100d0 < 1)) {
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

void entry(undefined8 param_1,int param_2,longlong param_3)

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



===== __scrt_initialize_type_info @ 1800014ec =====

/* void __cdecl __scrt_initialize_type_info(void) */

void __cdecl __scrt_initialize_type_info(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800014f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&__type_info_root_node);
  return;
}



===== __scrt_uninitialize_type_info @ 180001500 =====

/* void __cdecl __scrt_uninitialize_type_info(void) */

void __cdecl __scrt_uninitialize_type_info(void)

{
  _o___std_type_info_destroy_list(&__type_info_root_node);
  return;
}



===== __scrt_initialize_default_local_stdio_options @ 180001514 =====

void __scrt_initialize_default_local_stdio_options(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x24;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return;
}



===== __scrt_acquire_startup_lock @ 180001538 =====

ulonglong __scrt_acquire_startup_lock(void)

{
  bool bVar1;
  undefined7 extraout_var;
  void *pvVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  pvVar2 = (void *)CONCAT71(extraout_var,bVar1);
  if ((int)pvVar2 == 0) {
LAB_180001566:
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
      if (bVar1) goto LAB_180001566;
    } while (StackBase != pvVar2);
    uVar3 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  return uVar3;
}



===== __scrt_dllmain_after_initialize_c @ 180001578 =====

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



===== __scrt_dllmain_before_initialize_c @ 1800015b4 =====

bool __scrt_dllmain_before_initialize_c(void)

{
  undefined8 uVar1;
  
  uVar1 = __scrt_initialize_onexit_tables(0);
  return (char)uVar1 != '\0';
}



===== __scrt_dllmain_crt_thread_attach @ 1800015d0 =====

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



===== __scrt_dllmain_crt_thread_detach @ 180001600 =====

undefined1 __scrt_dllmain_crt_thread_detach(void)

{
  __vcrt_thread_attach();
  __vcrt_thread_attach();
  return 1;
}



===== __scrt_dllmain_exception_filter @ 18000161c =====

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



===== __scrt_dllmain_uninitialize_c @ 180001684 =====

void __scrt_dllmain_uninitialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    _o__execute_onexit_table(&DAT_180010100);
    return;
  }
  uVar2 = _is_c_termination_complete();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}



===== __scrt_dllmain_uninitialize_critical @ 1800016bc =====

void __scrt_dllmain_uninitialize_critical(void)

{
  __vcrt_thread_attach();
  __vcrt_thread_attach();
  return;
}



===== __scrt_initialize_crt @ 1800016d8 =====

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_180010131 = 1;
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



===== __scrt_initialize_onexit_tables @ 180001718 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_180010130 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      _DAT_180010100 = 0xffffffffffffffff;
      uRam0000000180010108 = 0xffffffffffffffff;
      _DAT_180010110 = 0xffffffffffffffff;
      _DAT_180010118 = 0xffffffffffffffff;
      uRam0000000180010120 = 0xffffffffffffffff;
      _DAT_180010128 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _o__initialize_onexit_table(&DAT_180010100);
      if (((int)in_RAX != 0) ||
         (in_RAX = _o__initialize_onexit_table(&DAT_180010118), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_180010130 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== __scrt_is_nonwritable_in_current_image @ 1800017ac =====

/* WARNING: Removing unreachable block (ram,0x000180001839) */
/* WARNING: Enum "SectionFlags": Some values do not have unique names */

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_180000218; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_180000358;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x180000000U) &&
       (uVar1 = (ulonglong)((pIVar3->Misc).PhysicalAddress + pIVar3->VirtualAddress),
       param_1 - 0x180000000U < uVar1)) goto LAB_180001822;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_180001822:
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



===== __scrt_release_startup_lock @ 18000184c =====

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



===== __scrt_uninitialize_crt @ 180001878 =====

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_180010131 == '\0') || (param_2 == '\0')) {
    __vcrt_thread_attach();
    __vcrt_thread_attach();
  }
  return 1;
}



===== __scrt_get_dyn_tls_init_callback @ 1800018a8 =====

undefined * __scrt_get_dyn_tls_init_callback(void)

{
  return &__dyn_tls_init_callback;
}



===== __crt_debugger_hook @ 1800018b8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __crt_debugger_hook(int param_1)

{
  ___scrt_debugger_hook_flag = 0;
  return;
}



===== __scrt_fastfail @ 1800018c8 =====

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
  *(undefined8 *)(puVar4 + -8) = 0x1800018fc;
  __crt_debugger_hook(3);
  *(undefined8 *)(puVar4 + -8) = 0x18000190d;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x180001917;
  RtlCaptureContext(local_4d8);
  local_res10 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x180001939;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    local_res18 = 0;
    local_res20 = 0;
    *(undefined8 **)(puVar4 + 0x30) = &local_res18;
    *(undefined8 **)(puVar4 + 0x28) = &local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x18000198a;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = auStack_5c8 + 0x5d0;
  *(undefined8 *)(puVar4 + -8) = 0x1800019bc;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x1800019de;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x1800019fb;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x180001a06;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x180001a17;
    __crt_debugger_hook(3);
  }
  return;
}



===== _RTC_Initialize @ 180001a30 =====

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



===== _RTC_Terminate @ 180001a74 =====

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



===== __raise_securityfailure @ 180001ab8 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000180001ae5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



===== __report_gsfailure @ 180001b00 =====

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
  *(undefined8 *)(puVar3 + -8) = 0x180001b2b;
  capture_previous_context((PCONTEXT)&DAT_1800101e0);
  _DAT_180010150 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_180010278 = puVar3 + 0x40;
  _DAT_180010260 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_180010140 = 0xc0000409;
  _DAT_180010144 = 1;
  _DAT_180010158 = 1;
  DAT_180010160 = 2;
  *(undefined8 *)(puVar3 + 0x20) = __security_cookie;
  *(undefined8 *)(puVar3 + 0x28) = __security_cookie_complement;
  *(undefined8 *)(puVar3 + -8) = 0x180001bcd;
  DAT_1800102d8 = _DAT_180010150;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_18000d000);
  return;
}



===== capture_previous_context @ 180001bd8 =====

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



===== __isa_available_init @ 180001c64 =====

/* WARNING: Removing unreachable block (ram,0x000180001d2e) */
/* WARNING: Removing unreachable block (ram,0x000180001c9e) */
/* WARNING: Removing unreachable block (ram,0x000180001c77) */
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



===== _get_startup_argv_mode @ 180001e18 =====

undefined8 _get_startup_argv_mode(void)

{
  return 1;
}



===== __scrt_is_ucrt_dll_in_use @ 180001e24 =====

bool __scrt_is_ucrt_dll_in_use(void)

{
  return __scrt_ucrt_dll_is_in_use != 0;
}



===== _guard_check_icall @ 180001e40 =====

void _guard_check_icall(void)

{
  return;
}



===== _initterm @ 180001e56 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== _initterm_e @ 180001e62 =====

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}



===== _o___std_type_info_destroy_list @ 180001e6e =====

void _o___std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___std_type_info_destroy_list();
  return;
}



===== _cexit @ 180001e7a =====

void _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__cexit();
  return;
}



===== _configure_narrow_argv @ 180001e86 =====

void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configure_narrow_argv();
  return;
}



===== _o__execute_onexit_table @ 180001e92 =====

void _o__execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__execute_onexit_table();
  return;
}



===== _o__initialize_narrow_environment @ 180001e9e =====

void _o__initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_narrow_environment();
  return;
}



===== _o__initialize_onexit_table @ 180001eaa =====

void _o__initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001eaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_onexit_table();
  return;
}



===== _seh_filter_dll @ 180001eb6 =====

void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001eb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__seh_filter_dll();
  return;
}



===== _o_free @ 180001ec2 =====

void _o_free(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001ec2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_free();
  return;
}



===== malloc @ 180001ece =====

void malloc(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001ece. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_malloc();
  return;
}



===== __C_specific_handler @ 180001eda =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180001eda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== memset @ 180001ee6 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180001ee6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== __vcrt_thread_attach @ 180001f00 =====

undefined1 __vcrt_thread_attach(void)

{
  return 1;
}



===== _is_c_termination_complete @ 180001f0c =====

undefined8 _is_c_termination_complete(void)

{
  return 0;
}



===== __empty_global_delete @ 180001f18 =====

/* void __cdecl __empty_global_delete(void * __ptr64,unsigned __int64) */

void __cdecl __empty_global_delete(void *param_1,__uint64 param_2)

{
  return;
}



===== UsbPm_AssignConnectorPowerLevel @ 180001f30 =====

long UsbPm_AssignConnectorPowerLevel
               (USBPM_CONNECTOR__ *param_1,USBPM_CONNECTOR__ *param_2,
               _USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *param_3)

{
  bool bVar1;
  long lVar2;
  undefined2 uVar3;
  _USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *p_Var4;
  USBPM_CONNECTOR__ *pUVar5;
  
                    /* 0x1f30  1  UsbPm_AssignConnectorPowerLevel */
  p_Var4 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    p_Var4 = (_USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *)
             &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x21,
              &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,param_1,(char)param_2);
  }
  bVar1 = UpaBaseClass::ValidateUpaHandle(param_1);
  if (bVar1) {
    bVar1 = UpaBaseClass::ValidateUpaHandle(param_2);
    if (bVar1) {
      if (param_3 == (_USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
          p_Var4 = (_USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *)
                   &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x24,
                  &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids);
        }
        lVar2 = -0x3ffffff3;
        param_3 = p_Var4;
      }
      else {
        lVar2 = UpaClient::ApiAssignConnectorPowerLevel
                          ((UpaClient *)~(ulonglong)param_1,param_2,param_3);
      }
      goto LAB_18000205c;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar3 = 0x23;
      pUVar5 = param_2;
      goto LAB_180001fb5;
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    uVar3 = 0x22;
    pUVar5 = param_1;
LAB_180001fb5:
    p_Var4 = (_USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *)
             &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,
             &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,pUVar5);
  }
  lVar2 = -0x3ffffff8;
  param_3 = p_Var4;
LAB_18000205c:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x25,param_3,param_1,(char)param_2,
               (char)lVar2);
  }
  return lVar2;
}



===== UsbPm_Deregister @ 1800020b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 UsbPm_Deregister(void *param_1)

{
  int iVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
                    /* 0x20b0  2  UsbPm_Deregister */
  bVar2 = UpaBaseClass::ValidateUpaHandle(param_1);
  if (bVar2) {
    puVar4 = (undefined8 *)~(ulonglong)param_1;
    if (puVar4 != (undefined8 *)0x0) {
      (**(code **)*puVar4)(puVar4,1);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc,
                &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,param_1,(char)puVar4);
    }
    LOCK();
    iVar1 = DAT_1800106b8 + -1;
    UNLOCK();
    bVar2 = DAT_1800106b8 == 1;
    DAT_1800106b8 = iVar1;
    if (bVar2) {
      WppCleanupUm();
    }
    uVar3 = 0;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,
               &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,param_1);
    }
    uVar3 = 0xc0000008;
  }
  return uVar3;
}



===== UsbPm_Register @ 180002190 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long UsbPm_Register(_USBPM_CLIENT_CONFIG *param_1,ulonglong *param_2)

{
  int iVar1;
  UpaClient *pUVar2;
  uchar uVar3;
  long lVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  bool bVar7;
  UpaClient *local_res8;
  longlong local_28 [2];
  
                    /* 0x2190  3  UsbPm_Register */
  local_res8 = (UpaClient *)0x0;
  LOCK();
  iVar1 = DAT_1800106b8 + 1;
  UNLOCK();
  bVar7 = DAT_1800106b8 == 0;
  DAT_1800106b8 = iVar1;
  if (bVar7) {
    DAT_1800106d0 = 0;
    puVar5 = &WPP_MAIN_CB;
    WPP_REGISTRATION_GUIDS = &WPP_ThisDir_CTLGUID_USB_POLICY_MANAGER_API;
    WPP_GLOBAL_Control = (undefined *)&WPP_MAIN_CB;
    plVar6 = (longlong *)&WPP_REGISTRATION_GUIDS;
    WPP_MAIN_CB = 0;
    _DAT_1800106d8 = 1;
    do {
      local_28[0] = *plVar6;
      plVar6 = plVar6 + 1;
      local_28[1] = 0;
      puVar5[4] = local_28[0];
      RegisterTraceGuidsW(WppControlCallback,puVar5,local_28[0],1,local_28,0,0,puVar5 + 1);
      puVar5 = (undefined8 *)*puVar5;
    } while (puVar5 != (undefined8 *)0x0);
  }
  if ((((byte)param_1[4] & 2) == 0) || (uVar3 = UsbPmApip_CheckUserToken(), uVar3 != '\0')) {
    lVar4 = UpaClient::Create(param_1,&local_res8);
    pUVar2 = local_res8;
    if (-1 < lVar4) {
      *param_2 = ~(ulonglong)local_res8;
      UpaClient::Start(local_res8);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return lVar4;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return lVar4;
      }
      if ((byte)WPP_GLOBAL_Control[0x19] < 4) {
        return lVar4;
      }
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10,
                &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,pUVar2,(char)*param_2);
      return lVar4;
    }
  }
  else {
    lVar4 = -0x3fffffde;
  }
  LOCK();
  iVar1 = DAT_1800106b8 + -1;
  UNLOCK();
  bVar7 = DAT_1800106b8 == 1;
  DAT_1800106b8 = iVar1;
  if (bVar7) {
    WppCleanupUm();
  }
  return lVar4;
}



===== UsbPm_RetrieveConnectorProperties @ 180002310 =====

undefined4 UsbPm_RetrieveConnectorProperties(void *param_1,void *param_2,undefined8 *param_3)

{
  bool bVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  
                    /* 0x2310  4  UsbPm_RetrieveConnectorProperties */
  puVar5 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    puVar5 = (undefined8 *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x17,
              &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,param_1,(char)param_2);
  }
  bVar1 = UpaBaseClass::ValidateUpaHandle(param_1);
  uVar4 = 0;
  if (bVar1) {
    bVar1 = UpaBaseClass::ValidateUpaHandle(param_2);
    if (bVar1) {
      if (param_3 == (undefined8 *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
          puVar5 = (undefined8 *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1a,
                  &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids);
        }
        uVar4 = 0xc000000d;
      }
      else {
        *param_3 = 0;
        param_3[1] = 0;
        param_3[2] = 0;
        param_3[3] = 0;
        *(undefined4 *)(param_3 + 4) = 0;
        uVar2 = ~(ulonglong)param_2;
        *(undefined2 *)((longlong)param_3 + 0x24) = 0;
        *param_3 = param_2;
        param_3[1] = ~*(ulonglong *)(uVar2 + 0x28);
        param_3[2] = *(undefined8 *)(uVar2 + 0x40);
        *(undefined4 *)(param_3 + 3) = *(undefined4 *)(uVar2 + 0x50);
        *(undefined4 *)((longlong)param_3 + 0x1c) = *(undefined4 *)(uVar2 + 0x54);
        *(undefined4 *)((longlong)param_3 + 0x22) = *(undefined4 *)(uVar2 + 0x5a);
        *(undefined1 *)((longlong)param_3 + 0x21) = *(undefined1 *)(uVar2 + 0x59);
        *(undefined1 *)(param_3 + 4) = *(undefined1 *)(uVar2 + 0x58);
      }
      goto LAB_18000247a;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar3 = 0x19;
      goto LAB_180002399;
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    uVar3 = 0x18;
    param_2 = param_1;
LAB_180002399:
    puVar5 = (undefined8 *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,
             &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,param_2);
  }
  uVar4 = 0xc0000008;
LAB_18000247a:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1b,puVar5,param_1,(char)param_3,
               (char)uVar4);
  }
  return uVar4;
}



===== UsbPm_RetrieveConnectorState @ 1800024d0 =====

long UsbPm_RetrieveConnectorState
               (USBPM_CONNECTOR__ *param_1,USBPM_CONNECTOR__ *param_2,
               _USBPM_CONNECTOR_STATE *param_3)

{
  bool bVar1;
  long lVar2;
  USBPM_CONNECTOR__ *pUVar3;
  undefined2 uVar4;
  _USBPM_CONNECTOR_STATE *p_Var5;
  
                    /* 0x24d0  5  UsbPm_RetrieveConnectorState */
  p_Var5 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    p_Var5 = (_USBPM_CONNECTOR_STATE *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1c,
              &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,param_1,(char)param_2);
  }
  bVar1 = UpaBaseClass::ValidateUpaHandle(param_1);
  if (bVar1) {
    pUVar3 = param_2;
    bVar1 = UpaBaseClass::ValidateUpaHandle(param_2);
    if (bVar1) {
      if (param_3 == (_USBPM_CONNECTOR_STATE *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
          p_Var5 = (_USBPM_CONNECTOR_STATE *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1f,
                  &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids);
        }
        lVar2 = -0x3ffffff3;
        param_3 = p_Var5;
      }
      else {
        lVar2 = UpaClient::ApiRetrieveConnectorState((UpaClient *)pUVar3,param_2,param_3);
      }
      goto LAB_1800025f6;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar4 = 0x1e;
      pUVar3 = param_2;
      goto LAB_180002555;
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    uVar4 = 0x1d;
    pUVar3 = param_1;
LAB_180002555:
    p_Var5 = (_USBPM_CONNECTOR_STATE *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar4,
             &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,pUVar3);
  }
  lVar2 = -0x3ffffff8;
  param_3 = p_Var5;
LAB_1800025f6:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x20,param_3,param_1,(char)param_2,
               (char)lVar2);
  }
  return lVar2;
}



===== UsbPm_RetrieveHubConnectorHandles @ 180002640 =====

undefined4 UsbPm_RetrieveHubConnectorHandles(void *param_1,void *param_2,undefined8 *param_3)

{
  bool bVar1;
  UpaCollectible *pUVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  ulong uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  void *pvVar9;
  
                    /* 0x2640  6  UsbPm_RetrieveHubConnectorHandles */
  puVar8 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    puVar8 = (undefined8 *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x12,
              &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,param_1,(char)param_2);
  }
  bVar1 = UpaBaseClass::ValidateUpaHandle(param_1);
  uVar5 = 0;
  if (bVar1) {
    bVar1 = UpaBaseClass::ValidateUpaHandle(param_2);
    if (bVar1) {
      if (param_3 == (undefined8 *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
          puVar8 = (undefined8 *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x15,
                  &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids);
        }
        uVar5 = 0xc000000d;
      }
      else {
        uVar7 = ~(ulonglong)param_2;
        if (*(uint *)(param_3 + 1) < *(uint *)(uVar7 + 0x268)) {
          uVar5 = 0xc0000023;
        }
        else {
          *param_3 = param_2;
          uVar6 = 0;
          if (*(int *)(uVar7 + 0x268) != 0) {
            do {
              pUVar2 = UpaCollection::GetItemByIndex((UpaCollection *)(uVar7 + 0x248),uVar6);
              uVar4 = (ulonglong)uVar6;
              uVar6 = uVar6 + 1;
              *(ulonglong *)(*(longlong *)((longlong)param_3 + 0xc) + uVar4 * 8) =
                   ~(ulonglong)pUVar2;
            } while (uVar6 < *(uint *)(uVar7 + 0x268));
          }
        }
      }
      goto LAB_1800027af;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar3 = 0x14;
      pvVar9 = param_2;
      goto LAB_1800026d0;
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    uVar3 = 0x13;
    pvVar9 = param_1;
LAB_1800026d0:
    puVar8 = (undefined8 *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,
             &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,pvVar9);
  }
  uVar5 = 0xc0000008;
LAB_1800027af:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x16,puVar8,param_1,(char)param_2,
               (char)uVar5);
  }
  return uVar5;
}



===== UsbPm_RetrieveHubProperties @ 180002810 =====

undefined4 UsbPm_RetrieveHubProperties(void *param_1,void *param_2,undefined8 *param_3)

{
  bool bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  void *pvVar5;
  
                    /* 0x2810  7  UsbPm_RetrieveHubProperties */
  puVar4 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    puVar4 = (undefined8 *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,
              &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,param_1,(char)param_2);
  }
  bVar1 = UpaBaseClass::ValidateUpaHandle(param_1);
  uVar3 = 0;
  if (bVar1) {
    bVar1 = UpaBaseClass::ValidateUpaHandle(param_2);
    if (bVar1) {
      if (param_3 == (undefined8 *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
          puVar4 = (undefined8 *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x10,
                  &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids);
        }
        uVar3 = 0xc000000d;
      }
      else {
        param_3[1] = param_2;
        *param_3 = *(undefined8 *)(~(ulonglong)param_2 + 0x28);
        *(undefined4 *)(param_3 + 2) = *(undefined4 *)(~(ulonglong)param_2 + 0x38);
      }
      goto LAB_180002944;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar2 = 0xf;
      pvVar5 = param_2;
      goto LAB_180002899;
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    uVar2 = 0xe;
    pvVar5 = param_1;
LAB_180002899:
    puVar4 = (undefined8 *)&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,
             &WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,pvVar5);
  }
  uVar3 = 0xc0000008;
LAB_180002944:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x11,puVar4,param_1,(char)param_2,
               (char)uVar3);
  }
  return uVar3;
}



===== WPP_SF_ @ 180002994 =====

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  TraceMessage(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_q @ 1800029c0 =====

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qq @ 180002a04 =====

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_qqd @ 180002a54 =====

void WPP_SF_qqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_129c2338c2a83a85ca30ecdd315ade8f_Traceguids,param_2,&local_res20,8,
               &param_5,8,&param_6,4,0);
  return;
}



===== WppCleanupUm @ 180002abc =====

void WppCleanupUm(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)WPP_GLOBAL_Control;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
      if (puVar1[1] != 0) {
        UnregisterTraceGuids();
        puVar1[1] = 0;
      }
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppControlCallback @ 180002b20 =====

undefined8 WppControlCallback(int param_1,longlong param_2,undefined4 *param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  *param_3 = 0;
  if (param_1 == 4) {
    uVar3 = GetTraceLoggerHandle(param_4);
    uVar1 = GetTraceEnableLevel(uVar3);
    uVar2 = GetTraceEnableFlags(uVar3);
  }
  else {
    if (param_1 != 5) {
      return 0x57;
    }
    uVar3 = 0;
    uVar2 = 0;
    uVar1 = 0;
  }
  if (((*(byte *)(param_2 + 0x1a) & 2) != 0) && (*(longlong *)(param_2 + 0x10) != 0)) {
    param_2 = *(longlong *)(param_2 + 0x10);
  }
  *(undefined4 *)(param_2 + 0x1c) = uVar2;
  *(undefined8 *)(param_2 + 0x10) = uVar3;
  *(undefined1 *)(param_2 + 0x19) = uVar1;
  return 0;
}



===== UpaBaseClass @ 180002bb8 =====

/* public: __cdecl UpaBaseClass::UpaBaseClass(void) __ptr64 */

UpaBaseClass * __thiscall UpaBaseClass::UpaBaseClass(UpaBaseClass *this)

{
  *(undefined4 *)(this + 8) = 0x414d5055;
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  return this;
}



===== UpaClient @ 180002c1c =====

/* public: __cdecl UpaClient::UpaClient(struct _USBPM_CLIENT_CONFIG * __ptr64) __ptr64 */

UpaClient * __thiscall UpaClient::UpaClient(UpaClient *this,_USBPM_CLIENT_CONFIG *param_1)

{
  undefined8 uVar1;
  
  UpaBaseClass::UpaBaseClass((UpaBaseClass *)this);
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined ***)this = &_vftable_;
  UpaCollection::UpaCollection((UpaCollection *)(this + 0x50));
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xb8) = 0xffffffff;
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined8 *)(this + 200) = 0;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x148) = 0xffffffff;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  UpaCollection::UpaCollection((UpaCollection *)(this + 0x168));
  UpaCollection::UpaCollection((UpaCollection *)(this + 0x1c0));
  UpaCollection::UpaCollection((UpaCollection *)(this + 0x218));
  UpaCollection::UpaCollection((UpaCollection *)(this + 0x270));
  UpaCollection::UpaCollection((UpaCollection *)(this + 0x2c8));
  this[0x116e] = (UpaClient)0x0;
  UpaCollection::UpaCollection((UpaCollection *)(this + 0x1178));
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x18) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x20) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x30) = uVar1;
  *(UpaClient **)(this + 0x30) = this + 0x38;
  *(undefined8 *)(this + 0x120) = 0;
  *(undefined8 *)(this + 0x128) = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x18,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  return this;
}



===== UpaCollectible @ 180002d50 =====

/* public: __cdecl UpaCollectible::UpaCollectible(void) __ptr64 */

UpaCollectible * __thiscall UpaCollectible::UpaCollectible(UpaCollectible *this)

{
  UpaCollectible *pUVar1;
  
  UpaBaseClass::UpaBaseClass((UpaBaseClass *)this);
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xe,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  pUVar1 = this + 0x10;
  *(UpaCollectible **)(this + 0x18) = pUVar1;
  *(UpaCollectible **)pUVar1 = pUVar1;
  return this;
}



===== UpaCollection @ 180002dbc =====

/* public: __cdecl UpaCollection::UpaCollection(void) __ptr64 */

UpaCollection * __thiscall UpaCollection::UpaCollection(UpaCollection *this)

{
  UpaCollection *pUVar1;
  
  UpaBaseClass::UpaBaseClass((UpaBaseClass *)this);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined ***)this = &_vftable_;
  this[0x50] = (UpaCollection)0x1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x46,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  pUVar1 = this + 0x10;
  *(UpaCollection **)(this + 0x18) = pUVar1;
  *(UpaCollection **)pUVar1 = pUVar1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  return this;
}



===== UpaConnector @ 180002e40 =====

/* public: __cdecl UpaConnector::UpaConnector(struct _UPM_CONNECTOR_SNAPSHOT * __ptr64,class
   UpaClient * __ptr64) __ptr64 */

UpaConnector * __thiscall
UpaConnector::UpaConnector(UpaConnector *this,_UPM_CONNECTOR_SNAPSHOT *param_1,UpaClient *param_2)

{
  UpaCollectible *this_00;
  undefined8 uVar1;
  _UPM_CONNECTOR_SNAPSHOT *p_Var2;
  UpaConnector *pUVar3;
  _UPM_CONNECTOR_SNAPSHOT *p_Var4;
  longlong lVar5;
  UpaConnector *pUVar6;
  
  UpaCollectible::UpaCollectible((UpaCollectible *)this);
  *(UpaClient **)(this + 0x20) = param_2;
  lVar5 = 6;
  *(undefined ***)this = &_vftable_;
  p_Var2 = param_1;
  pUVar3 = this + 0x30;
  do {
    pUVar6 = pUVar3;
    p_Var4 = p_Var2;
    uVar1 = *(undefined8 *)(p_Var4 + 8);
    *(undefined8 *)pUVar6 = *(undefined8 *)p_Var4;
    *(undefined8 *)(pUVar6 + 8) = uVar1;
    uVar1 = *(undefined8 *)(p_Var4 + 0x18);
    *(undefined8 *)(pUVar6 + 0x10) = *(undefined8 *)(p_Var4 + 0x10);
    *(undefined8 *)(pUVar6 + 0x18) = uVar1;
    uVar1 = *(undefined8 *)(p_Var4 + 0x28);
    *(undefined8 *)(pUVar6 + 0x20) = *(undefined8 *)(p_Var4 + 0x20);
    *(undefined8 *)(pUVar6 + 0x28) = uVar1;
    uVar1 = *(undefined8 *)(p_Var4 + 0x38);
    *(undefined8 *)(pUVar6 + 0x30) = *(undefined8 *)(p_Var4 + 0x30);
    *(undefined8 *)(pUVar6 + 0x38) = uVar1;
    uVar1 = *(undefined8 *)(p_Var4 + 0x48);
    *(undefined8 *)(pUVar6 + 0x40) = *(undefined8 *)(p_Var4 + 0x40);
    *(undefined8 *)(pUVar6 + 0x48) = uVar1;
    uVar1 = *(undefined8 *)(p_Var4 + 0x58);
    *(undefined8 *)(pUVar6 + 0x50) = *(undefined8 *)(p_Var4 + 0x50);
    *(undefined8 *)(pUVar6 + 0x58) = uVar1;
    uVar1 = *(undefined8 *)(p_Var4 + 0x68);
    *(undefined8 *)(pUVar6 + 0x60) = *(undefined8 *)(p_Var4 + 0x60);
    *(undefined8 *)(pUVar6 + 0x68) = uVar1;
    uVar1 = *(undefined8 *)(p_Var4 + 0x78);
    *(undefined8 *)(pUVar6 + 0x70) = *(undefined8 *)(p_Var4 + 0x70);
    *(undefined8 *)(pUVar6 + 0x78) = uVar1;
    lVar5 = lVar5 + -1;
    p_Var2 = p_Var4 + 0x80;
    pUVar3 = pUVar6 + 0x80;
  } while (lVar5 != 0);
  uVar1 = *(undefined8 *)(p_Var4 + 0x88);
  *(undefined8 *)(pUVar6 + 0x80) = *(undefined8 *)(p_Var4 + 0x80);
  *(undefined8 *)(pUVar6 + 0x88) = uVar1;
  uVar1 = *(undefined8 *)(p_Var4 + 0x98);
  *(undefined8 *)(pUVar6 + 0x90) = *(undefined8 *)(p_Var4 + 0x90);
  *(undefined8 *)(pUVar6 + 0x98) = uVar1;
  uVar1 = *(undefined8 *)(p_Var4 + 0xa8);
  *(undefined8 *)(pUVar6 + 0xa0) = *(undefined8 *)(p_Var4 + 0xa0);
  *(undefined8 *)(pUVar6 + 0xa8) = uVar1;
  *(undefined2 *)(pUVar6 + 0xb0) = *(undefined2 *)(p_Var4 + 0xb0);
  memcpy(this + 0x362,param_1 + 0x332,0x690);
  *(undefined8 *)(this + 0x9f8) = 0;
  this_00 = (UpaCollectible *)(this + 0xa00);
  UpaCollectible::UpaCollectible(this_00);
  *(UpaConnector **)(this + 0xa20) = this;
  *(undefined ***)this_00 = &UpaConnectorStateChange::_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x13,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this_00);
  }
  this[0xa28] = (UpaConnector)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x15,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  return this;
}



===== UpaHub @ 180002fb4 =====

/* public: __cdecl UpaHub::UpaHub(struct _UPM_HUB_PROPERTIES * __ptr64,class UpaClient * __ptr64)
   __ptr64 */

UpaHub * __thiscall UpaHub::UpaHub(UpaHub *this,_UPM_HUB_PROPERTIES *param_1,UpaClient *param_2)

{
  undefined8 uVar1;
  UpaHub *pUVar2;
  longlong lVar3;
  UpaHub *pUVar4;
  _UPM_HUB_PROPERTIES *p_Var5;
  
  UpaCollectible::UpaCollectible((UpaCollectible *)this);
  *(undefined ***)this = &_vftable_;
  lVar3 = 4;
  pUVar2 = this + 0x20;
  do {
    p_Var5 = param_1;
    pUVar4 = pUVar2;
    uVar1 = *(undefined8 *)(p_Var5 + 8);
    *(undefined8 *)pUVar4 = *(undefined8 *)p_Var5;
    *(undefined8 *)(pUVar4 + 8) = uVar1;
    uVar1 = *(undefined8 *)(p_Var5 + 0x18);
    *(undefined8 *)(pUVar4 + 0x10) = *(undefined8 *)(p_Var5 + 0x10);
    *(undefined8 *)(pUVar4 + 0x18) = uVar1;
    uVar1 = *(undefined8 *)(p_Var5 + 0x28);
    *(undefined8 *)(pUVar4 + 0x20) = *(undefined8 *)(p_Var5 + 0x20);
    *(undefined8 *)(pUVar4 + 0x28) = uVar1;
    uVar1 = *(undefined8 *)(p_Var5 + 0x38);
    *(undefined8 *)(pUVar4 + 0x30) = *(undefined8 *)(p_Var5 + 0x30);
    *(undefined8 *)(pUVar4 + 0x38) = uVar1;
    uVar1 = *(undefined8 *)(p_Var5 + 0x48);
    *(undefined8 *)(pUVar4 + 0x40) = *(undefined8 *)(p_Var5 + 0x40);
    *(undefined8 *)(pUVar4 + 0x48) = uVar1;
    uVar1 = *(undefined8 *)(p_Var5 + 0x58);
    *(undefined8 *)(pUVar4 + 0x50) = *(undefined8 *)(p_Var5 + 0x50);
    *(undefined8 *)(pUVar4 + 0x58) = uVar1;
    uVar1 = *(undefined8 *)(p_Var5 + 0x68);
    *(undefined8 *)(pUVar4 + 0x60) = *(undefined8 *)(p_Var5 + 0x60);
    *(undefined8 *)(pUVar4 + 0x68) = uVar1;
    uVar1 = *(undefined8 *)(p_Var5 + 0x78);
    *(undefined8 *)(pUVar4 + 0x70) = *(undefined8 *)(p_Var5 + 0x70);
    *(undefined8 *)(pUVar4 + 0x78) = uVar1;
    lVar3 = lVar3 + -1;
    pUVar2 = pUVar4 + 0x80;
    param_1 = p_Var5 + 0x80;
  } while (lVar3 != 0);
  uVar1 = *(undefined8 *)(p_Var5 + 0x88);
  *(undefined8 *)(pUVar4 + 0x80) = *(undefined8 *)(p_Var5 + 0x80);
  *(undefined8 *)(pUVar4 + 0x88) = uVar1;
  *(undefined8 *)(pUVar4 + 0x90) = *(undefined8 *)(p_Var5 + 0x90);
  *(undefined4 *)(pUVar4 + 0x98) = *(undefined4 *)(p_Var5 + 0x98);
  *(UpaClient **)(this + 0x240) = param_2;
  UpaCollection::UpaCollection((UpaCollection *)(this + 0x248));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x10,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  return this;
}



===== ~UpaBaseClass @ 1800030ac =====

/* public: virtual __cdecl UpaBaseClass::~UpaBaseClass(void) __ptr64 */

void __thiscall UpaBaseClass::~UpaBaseClass(UpaBaseClass *this)

{
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  return;
}



===== ~UpaCallback @ 180003100 =====

/* public: virtual __cdecl UpaCallback::~UpaCallback(void) __ptr64 */

void __thiscall UpaCallback::~UpaCallback(UpaCallback *this)

{
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x61,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  UpaCollectible::~UpaCollectible((UpaCollectible *)this);
  return;
}



===== ~UpaCallbacks @ 180003160 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl UpaCallbacks::~UpaCallbacks(void) __ptr64 */

void __thiscall UpaCallbacks::~UpaCallbacks(UpaCallbacks *this)

{
  undefined8 *puVar1;
  ulong uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x62,
              &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this,(char)*(undefined8 *)(this + 8))
    ;
  }
  if (*(longlong *)this != 0) {
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,6);
    uVar2 = 1;
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar2 = 99;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),99,
               &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,*(undefined8 *)(this + 8));
    }
    UpaHelperEvent::Wait((UpaHelperEvent *)(this + 0x70),uVar2);
  }
  puVar1 = *(undefined8 **)(this + 0x68);
  if (puVar1 != (undefined8 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    *(undefined8 *)(this + 0x68) = 0;
  }
  UpaHelperEvent::~UpaHelperEvent((UpaHelperEvent *)(this + 0x70));
  UpaCollection::~UpaCollection((UpaCollection *)(this + 0x10));
  return;
}



===== ~UpaClient @ 180003250 =====

/* public: virtual __cdecl UpaClient::~UpaClient(void) __ptr64 */

void __thiscall UpaClient::~UpaClient(UpaClient *this)

{
  StateMachineEngine *this_00;
  ulong uVar1;
  
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x19,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  this_00 = (StateMachineEngine *)(this + 0x10);
  if (*(longlong *)this_00 != 0) {
    SmFx::StateMachineEngine::EnqueueEvent(this_00,0x11);
    uVar1 = 4;
    SmFx::StateMachineEngine::EnqueueEvent(this_00,4);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar1 = 0x1a;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1a,
               &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
    }
    UpaHelperEvent::Wait((UpaHelperEvent *)(this + 0x140),uVar1);
  }
  if (*(longlong *)(this + 0x128) != 0) {
    _o_free();
    RtlInitUnicodeString(this + 0x120,0);
  }
  if (*(longlong *)(this + 0x130) != 0) {
    NtClose();
    *(undefined8 *)(this + 0x130) = 0;
  }
  UpaCollection::~UpaCollection((UpaCollection *)(this + 0x1178));
  UpaCollection::~UpaCollection((UpaCollection *)(this + 0x2c8));
  UpaCollection::~UpaCollection((UpaCollection *)(this + 0x270));
  UpaCollection::~UpaCollection((UpaCollection *)(this + 0x218));
  UpaCollection::~UpaCollection((UpaCollection *)(this + 0x1c0));
  UpaCollection::~UpaCollection((UpaCollection *)(this + 0x168));
  UpaHelperEvent::~UpaHelperEvent((UpaHelperEvent *)(this + 0x140));
  UpaCallbacks::~UpaCallbacks((UpaCallbacks *)(this + 0x40));
  UpaBaseClass::~UpaBaseClass((UpaBaseClass *)this);
  return;
}



===== ~UpaCollectible @ 1800033cc =====

/* public: virtual __cdecl UpaCollectible::~UpaCollectible(void) __ptr64 */

void __thiscall UpaCollectible::~UpaCollectible(UpaCollectible *this)

{
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xf,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  UpaBaseClass::~UpaBaseClass((UpaBaseClass *)this);
  return;
}



===== ~UpaCollection @ 18000342c =====

/* public: virtual __cdecl UpaCollection::~UpaCollection(void) __ptr64 */

void __thiscall UpaCollection::~UpaCollection(UpaCollection *this)

{
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x47,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  Clear(this);
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  UpaBaseClass::~UpaBaseClass((UpaBaseClass *)this);
  return;
}



===== ~UpaConnector @ 1800034a4 =====

/* public: virtual __cdecl UpaConnector::~UpaConnector(void) __ptr64 */

void __thiscall UpaConnector::~UpaConnector(UpaConnector *this)

{
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x16,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  UpaConnectorStateChange::~UpaConnectorStateChange((UpaConnectorStateChange *)(this + 0xa00));
  UpaCollectible::~UpaCollectible((UpaCollectible *)this);
  return;
}



===== ~UpaConnectorStateChange @ 180003510 =====

/* public: virtual __cdecl UpaConnectorStateChange::~UpaConnectorStateChange(void) __ptr64 */

void __thiscall UpaConnectorStateChange::~UpaConnectorStateChange(UpaConnectorStateChange *this)

{
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x14,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  UpaCollectible::~UpaCollectible((UpaCollectible *)this);
  return;
}



===== ~UpaHub @ 180003570 =====

/* public: virtual __cdecl UpaHub::~UpaHub(void) __ptr64 */

void __thiscall UpaHub::~UpaHub(UpaHub *this)

{
  *(undefined ***)this = &_vftable_;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x11,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
  }
  UpaCollection::~UpaCollection((UpaCollection *)(this + 0x248));
  UpaCollectible::~UpaCollectible((UpaCollectible *)this);
  return;
}



===== operator_new @ 1800035dc =====

/* public: static void * __ptr64 __cdecl UpaBaseClass::operator new(unsigned __int64) */

void * __cdecl UpaBaseClass::operator_new(__uint64 param_1)

{
  void *pvVar1;
  undefined8 in_RDX;
  undefined8 in_R8;
  void *local_res10 [3];
  
  pvVar1 = (void *)_o_malloc();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,in_R8,(int)param_1,(char)pvVar1);
  }
  local_res10[0] = pvVar1;
  EnterCriticalSection(&GlobalObjectPointerTable::m_Lock);
  RtlInsertElementGenericTable(&GlobalObjectPointerTable::m_Table,local_res10,8);
  LeaveCriticalSection(&GlobalObjectPointerTable::m_Lock);
  return pvVar1;
}



===== operator_delete @ 180003688 =====

/* public: static void __cdecl UpaBaseClass::operator delete(void * __ptr64) */

void __cdecl UpaBaseClass::operator_delete(void *param_1)

{
  void *local_res8 [4];
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_1);
  }
  if (param_1 != (void *)0x0) {
    _o_free(param_1);
    local_res8[0] = param_1;
    EnterCriticalSection(&GlobalObjectPointerTable::m_Lock);
    RtlDeleteElementGenericTable(&GlobalObjectPointerTable::m_Table,local_res8);
    LeaveCriticalSection(&GlobalObjectPointerTable::m_Lock);
  }
  return;
}



===== `scalar_deleting_destructor' @ 180003730 =====

/* public: virtual void * __ptr64 __cdecl UpaAssignPowerLevel::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
UpaAssignPowerLevel::_scalar_deleting_destructor_(UpaAssignPowerLevel *this,uint param_1)

{
  UpaCollectible::~UpaCollectible((UpaCollectible *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      UpaBaseClass::operator_delete(this);
    }
    else {
      __empty_global_delete(this,0x78);
    }
  }
  return this;
}



===== `scalar_deleting_destructor' @ 180003780 =====

/* public: virtual void * __ptr64 __cdecl UpaBaseClass::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall UpaBaseClass::_scalar_deleting_destructor_(UpaBaseClass *this,uint param_1)

{
  ~UpaBaseClass(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      operator_delete(this);
    }
    else {
      __empty_global_delete(this,0x10);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 1800037d0 =====

/* public: virtual void * __ptr64 __cdecl UpaCallback::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall UpaCallback::_vector_deleting_destructor_(UpaCallback *this,uint param_1)

{
  ~UpaCallback(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      UpaBaseClass::operator_delete(this);
    }
    else {
      __empty_global_delete(this,0x38);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 180003820 =====

/* public: virtual void * __ptr64 __cdecl UpaClient::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall UpaClient::_vector_deleting_destructor_(UpaClient *this,uint param_1)

{
  ~UpaClient(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      UpaBaseClass::operator_delete(this);
    }
    else {
      __empty_global_delete(this,0x11e0);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 180003870 =====

/* public: virtual void * __ptr64 __cdecl UpaCollectible::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall UpaCollectible::_vector_deleting_destructor_(UpaCollectible *this,uint param_1)

{
  ~UpaCollectible(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      UpaBaseClass::operator_delete(this);
    }
    else {
      __empty_global_delete(this,0x20);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 1800038c0 =====

/* public: virtual void * __ptr64 __cdecl UpaCollection::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall UpaCollection::_vector_deleting_destructor_(UpaCollection *this,uint param_1)

{
  ~UpaCollection(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      UpaBaseClass::operator_delete(this);
    }
    else {
      __empty_global_delete(this,0x58);
    }
  }
  return this;
}



===== `scalar_deleting_destructor' @ 180003910 =====

/* public: virtual void * __ptr64 __cdecl UpaConnector::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall UpaConnector::_scalar_deleting_destructor_(UpaConnector *this,uint param_1)

{
  ~UpaConnector(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      UpaBaseClass::operator_delete(this);
    }
    else {
      __empty_global_delete(this,0xa30);
    }
  }
  return this;
}



===== `vector_deleting_destructor' @ 180003960 =====

/* public: virtual void * __ptr64 __cdecl UpaConnectorStateChange::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
UpaConnectorStateChange::_vector_deleting_destructor_(UpaConnectorStateChange *this,uint param_1)

{
  ~UpaConnectorStateChange(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      UpaBaseClass::operator_delete(this);
    }
    else {
      __empty_global_delete(this,0x28);
    }
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1800039b0 =====

/* public: virtual void * __ptr64 __cdecl UpaHub::`scalar deleting destructor'(unsigned int) __ptr64
    */

void * __thiscall UpaHub::_scalar_deleting_destructor_(UpaHub *this,uint param_1)

{
  ~UpaHub(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      UpaBaseClass::operator_delete(this);
    }
    else {
      __empty_global_delete(this,0x2a0);
    }
  }
  return this;
}



===== AddItem @ 1800039fc =====

/* public: bool __cdecl UpaCollection::AddItem(class UpaCollectible * __ptr64) __ptr64 */

bool __thiscall UpaCollection::AddItem(UpaCollection *this,UpaCollectible *param_1)

{
  code *pcVar1;
  UpaCollection *pUVar2;
  UpaCollectible *pUVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  bool bVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  bVar7 = false;
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  puVar5 = auStack_28;
  puVar6 = auStack_28;
  if (this[0x50] != (UpaCollection)0x0) {
    pUVar2 = this + 0x10;
    plVar4 = *(longlong **)(this + 0x18);
    pUVar3 = param_1 + 0x10;
    if ((UpaCollection *)*plVar4 != pUVar2) {
      pUVar3 = (UpaCollectible *)0x3;
      pcVar1 = (code *)swi(0x29);
      pUVar2 = (UpaCollection *)(*pcVar1)();
      puVar5 = auStack_20;
    }
    *(UpaCollection **)pUVar3 = pUVar2;
    bVar7 = true;
    *(longlong **)(pUVar3 + 8) = plVar4;
    *plVar4 = (longlong)pUVar3;
    *(UpaCollectible **)(pUVar2 + 8) = pUVar3;
    *(int *)(this + 0x20) = *(int *)(this + 0x20) + 1;
    puVar6 = puVar5;
  }
  *(undefined8 *)(puVar6 + -8) = 0x180003a68;
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  return bVar7;
}



===== AddingConnectorToCollectionEntry @ 180003a90 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::AddingConnectorToCollectionEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::AddingConnectorToCollectionEntry(void *param_1)

{
  UpaConnector *this;
  UpaCollectible *pUVar1;
  UpaClient *pUVar2;
  
  pUVar2 = (UpaClient *)(-(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U);
  this = UpaBaseClass::operator_new(0xa30);
  if ((this != (UpaConnector *)0x0) &&
     (pUVar1 = (UpaCollectible *)
               UpaConnector::UpaConnector(this,(_UPM_CONNECTOR_SNAPSHOT *)(pUVar2 + 0x7ac),pUVar2),
     pUVar1 != (UpaCollectible *)0x0)) {
    UpaCollection::AddItem((UpaCollection *)(pUVar2 + 0x1178),pUVar1);
    return 5;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1f,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,pUVar2);
  }
  return 5;
}



===== AddingHubToCollectionEntry @ 180003b30 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::AddingHubToCollectionEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::AddingHubToCollectionEntry(void *param_1)

{
  UpaHub *this;
  UpaCollectible *this_00;
  UpaCollectible *pUVar1;
  UpaClient *pUVar2;
  
  pUVar2 = (UpaClient *)(-(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U);
  this = UpaBaseClass::operator_new(0x2a0);
  if ((this != (UpaHub *)0x0) &&
     (this_00 = (UpaCollectible *)
                UpaHub::UpaHub(this,(_UPM_HUB_PROPERTIES *)(pUVar2 + 0x590),pUVar2),
     this_00 != (UpaCollectible *)0x0)) {
    while (pUVar1 = UpaCollection::PopHead((UpaCollection *)(pUVar2 + 0x1178)),
          pUVar1 != (UpaCollectible *)0x0) {
      UpaCollection::AddItem((UpaCollection *)(this_00 + 0x248),pUVar1);
      *(UpaCollectible **)(pUVar1 + 0x28) = this_00;
      *(undefined8 *)(pUVar1 + 0x30) = *(undefined8 *)(this_00 + 0x20);
    }
    UpaCollection::AddItem((UpaCollection *)(pUVar2 + 0x168),this_00);
    UpaHub::DumpAll((UpaHub *)this_00);
    *(UpaCollectible **)(pUVar2 + 0x11d0) = this_00;
    return 5;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x1e,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,pUVar2);
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(pUVar2 + 0x10),0x12);
  return 5;
}



===== ApiAssignConnectorPowerLevel @ 180003c3c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: long __cdecl UpaClient::ApiAssignConnectorPowerLevel(struct USBPM_CONNECTOR__ *
   __ptr64,struct _USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS * __ptr64) __ptr64 */

long __thiscall
UpaClient::ApiAssignConnectorPowerLevel
          (UpaClient *this,USBPM_CONNECTOR__ *param_1,
          _USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *param_2)

{
  bool bVar1;
  UpaCollectible *this_00;
  undefined2 uVar2;
  ulong uVar3;
  long lVar4;
  _USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *p_Var5;
  undefined1 uVar6;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0;
  local_20 = 0xffffffff;
  local_18 = 0;
  uStack_10 = 0;
  uVar6 = SUB81(this,0);
  p_Var5 = param_2;
  if (((byte)this[0x138] & 2) == 0) {
    lVar4 = -0x3fffffde;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x19] < 2))
    goto LAB_180003e6f;
    uVar2 = 0x2e;
  }
  else {
    UpaHelperEvent::Initialize((UpaHelperEvent *)&local_28,(uchar)param_1);
    this_00 = UpaBaseClass::operator_new(0x78);
    if (this_00 == (UpaCollectible *)0x0) {
      lVar4 = -0x3fffff66;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x19] < 2))
      goto LAB_180003e6f;
      uVar2 = 0x2f;
    }
    else {
      UpaCollectible::UpaCollectible(this_00);
      *(undefined4 *)(this_00 + 0x20) = 0x578214;
      *(undefined ***)this_00 = &UpaAssignPowerLevel::_vftable_;
      *(UpaClient **)(this_00 + 0x28) = this;
      *(ulonglong *)(this_00 + 0x30) = ~(ulonglong)param_1;
      *(undefined8 *)(this_00 + 0x38) = *(undefined8 *)param_2;
      *(undefined4 *)(this_00 + 0x40) = *(undefined4 *)(param_2 + 8);
      this_00[0x44] = *(UpaCollectible *)(param_2 + 0xc);
      *(undefined8 **)(this_00 + 0x60) = &local_28;
      bVar1 = UpaCollection::AddItem((UpaCollection *)(this + 0x218),this_00);
      if (bVar1) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
          p_Var5 = (_USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *)
                   &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids;
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x31,
                    &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this_00,uVar6);
        }
        uVar3 = 0x13;
        SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(this + 0x10),0x13);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
          p_Var5 = (_USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *)
                   &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids;
          uVar3 = 0x32;
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x32,
                    &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this_00,uVar6);
        }
        UpaHelperEvent::Wait((UpaHelperEvent *)&local_28,uVar3);
        lVar4 = (long)local_18;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
          WPP_SF_dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x33,p_Var5,(long)local_18,
                     (char)this_00,uVar6);
        }
        goto LAB_180003e6f;
      }
      (*(code *)**(undefined8 **)this_00)(this_00,1);
      lVar4 = -0x3fffff5d;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x19] < 2))
      goto LAB_180003e6f;
      uVar2 = 0x30;
    }
  }
  WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,p_Var5,lVar4,uVar6);
LAB_180003e6f:
  UpaHelperEvent::~UpaHelperEvent((UpaHelperEvent *)&local_28);
  return lVar4;
}



===== ApiRetrieveConnectorState @ 180003e98 =====

/* public: long __cdecl UpaClient::ApiRetrieveConnectorState(struct USBPM_CONNECTOR__ *
   __ptr64,struct _USBPM_CONNECTOR_STATE * __ptr64) __ptr64 */

long __thiscall
UpaClient::ApiRetrieveConnectorState
          (UpaClient *this,USBPM_CONNECTOR__ *param_1,_USBPM_CONNECTOR_STATE *param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
  uVar2 = ~(ulonglong)param_1;
  memset(param_2 + 8,0,0x7c);
  *(USBPM_CONNECTOR__ **)param_2 = param_1;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(uVar2 + 0x36a);
  param_2[0xc] = *(_USBPM_CONNECTOR_STATE *)(uVar2 + 0x36e);
  *(undefined4 *)(param_2 + 0xd) = *(undefined4 *)(uVar2 + 0x36f);
  *(undefined4 *)(param_2 + 0x15) = *(undefined4 *)(uVar2 + 0x377);
  *(undefined4 *)(param_2 + 0x21) = *(undefined4 *)(uVar2 + 0x387);
  *(undefined4 *)(param_2 + 0x11) = *(undefined4 *)(uVar2 + 0x373);
  *(undefined4 *)(param_2 + 0x25) = *(undefined4 *)(uVar2 + 0x38b);
  *(undefined4 *)(param_2 + 0x19) = *(undefined4 *)(uVar2 + 0x37b);
  param_2[99] = *(_USBPM_CONNECTOR_STATE *)(uVar2 + 0x3c9);
  param_2[0x29] = *(_USBPM_CONNECTOR_STATE *)(uVar2 + 0x38f);
  param_2[0x46] = *(_USBPM_CONNECTOR_STATE *)(uVar2 + 0x3ac);
  *(undefined4 *)(param_2 + 0x1d) = *(undefined4 *)(uVar2 + 899);
  uVar1 = *(undefined8 *)(uVar2 + 0x3d2);
  *(undefined8 *)(param_2 + 100) = *(undefined8 *)(uVar2 + 0x3ca);
  *(undefined8 *)(param_2 + 0x6c) = uVar1;
  *(undefined8 *)(param_2 + 0x74) = *(undefined8 *)(uVar2 + 0x3da);
  *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(uVar2 + 0x3e2);
  uVar1 = *(undefined8 *)(uVar2 + 0x398);
  *(undefined8 *)(param_2 + 0x2a) = *(undefined8 *)(uVar2 + 0x390);
  *(undefined8 *)(param_2 + 0x32) = uVar1;
  *(undefined8 *)(param_2 + 0x3a) = *(undefined8 *)(uVar2 + 0x3a0);
  *(undefined4 *)(param_2 + 0x42) = *(undefined4 *)(uVar2 + 0x3a8);
  uVar1 = *(undefined8 *)(uVar2 + 0x3b5);
  *(undefined8 *)(param_2 + 0x47) = *(undefined8 *)(uVar2 + 0x3ad);
  *(undefined8 *)(param_2 + 0x4f) = uVar1;
  *(undefined8 *)(param_2 + 0x57) = *(undefined8 *)(uVar2 + 0x3bd);
  *(undefined4 *)(param_2 + 0x5f) = *(undefined4 *)(uVar2 + 0x3c5);
  return 0;
}



===== CancellingAllUnsentAsyncRequestsEntry @ 180003fb0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::CancellingAllUnsentAsyncRequestsEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::CancellingAllUnsentAsyncRequestsEntry
          (void *param_1)

{
  UpaCollectible *this;
  UpaCollection *this_00;
  UpaCollection *this_01;
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
  local_14 = 0;
  this_00 = (UpaCollection *)((longlong)param_1 + 0x208);
  local_10 = 0;
  local_18 = 0xc000009d;
  if (param_1 == (void *)0x0) {
    this_00 = (UpaCollection *)0x218;
  }
  this = UpaCollection::PopHead(this_00);
  if (this != (UpaCollectible *)0x0) {
    this_01 = (UpaCollection *)((longlong)param_1 + 0x260);
    if (param_1 == (void *)0x0) {
      this_01 = (UpaCollection *)0x270;
    }
    do {
      UpaCollection::AddItem(this_01,this);
      UpaAssignPowerLevel::EvtIoCtlCompleted
                ((UpaAssignPowerLevel *)this,(_IO_STATUS_BLOCK *)&local_18);
      this = UpaCollection::PopHead(this_00);
    } while (this != (UpaCollectible *)0x0);
  }
  return 5;
}



===== CheckingIfPolicyManagerIsBeingQueryRemovedEntry @ 180004060 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::CheckingIfPolicyManagerIsBeingQueryRemovedEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::CheckingIfPolicyManagerIsBeingQueryRemovedEntry
          (void *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)((longlong)param_1 + 0x115e);
  if (param_1 == (void *)0x0) {
    pcVar1 = &DAT_0000116e;
  }
  return (-(ushort)(*pcVar1 != '\0') & 0xb) + 9;
}



===== CheckingIfThereAreIncompleteAsyncRequestsEntry @ 180004090 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::CheckingIfThereAreIncompleteAsyncRequestsEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::CheckingIfThereAreIncompleteAsyncRequestsEntry
          (void *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((longlong)param_1 + 0x280);
  if (param_1 == (void *)0x0) {
    piVar1 = (int *)&DAT_00000290;
  }
  if (*piVar1 == 0) {
    piVar1 = (int *)((longlong)param_1 + 0x2d8);
    if (param_1 == (void *)0x0) {
      piVar1 = (int *)&DAT_000002e8;
    }
    if (*piVar1 == 0) {
      return 9;
    }
  }
  return 0x14;
}



===== Clear @ 1800040d4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl UpaCollection::Clear(void) __ptr64 */

void __thiscall UpaCollection::Clear(UpaCollection *this)

{
  UpaCollection *pUVar1;
  UpaCollection *pUVar2;
  longlong lVar3;
  code *pcVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  pUVar1 = this + 0x10;
  do {
    pUVar2 = *(UpaCollection **)pUVar1;
    if (pUVar2 == pUVar1) {
LAB_18000413d:
                    /* WARNING: Could not recover jumptable at 0x000180004150. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
      return;
    }
    if ((*(UpaCollection **)(pUVar2 + 8) != pUVar1) ||
       (lVar3 = *(longlong *)pUVar2, *(UpaCollection **)(lVar3 + 8) != pUVar2)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      goto LAB_18000413d;
    }
    *(longlong *)pUVar1 = lVar3;
    *(UpaCollection **)(lVar3 + 8) = pUVar1;
    pUVar2 = pUVar2 + -0x10;
    if (pUVar2 != (UpaCollection *)0x0) {
      (*(code *)**(undefined8 **)pUVar2)(pUVar2,1);
    }
    *(int *)(this + 0x20) = *(int *)(this + 0x20) + -1;
  } while( true );
}



===== ClearingHubsEntry @ 180004170 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::ClearingHubsEntry(void * __ptr64) */

ushort __cdecl UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::ClearingHubsEntry(void *param_1)

{
  UpaCollection *this;
  
  this = (UpaCollection *)((longlong)param_1 + 0x158);
  if (param_1 == (void *)0x0) {
    this = (UpaCollection *)0x168;
  }
  UpaCollection::Clear(this);
  return 5;
}



===== ClosingAsyncRequestQueueGateEntry @ 1800041a0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::ClosingAsyncRequestQueueGateEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::ClosingAsyncRequestQueueGateEntry(void *param_1)

{
  undefined1 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((longlong)param_1 + 0x230);
  if (param_1 == (void *)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x240;
  }
  EnterCriticalSection(lpCriticalSection);
  puVar1 = (undefined1 *)((longlong)param_1 + 600);
  if (param_1 == (void *)0x0) {
    puVar1 = &DAT_00000268;
  }
  *puVar1 = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 5;
}



===== CompleteAsyncRequestsToApiClient @ 18000420c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: void __cdecl UpaClient::CompleteAsyncRequestsToApiClient(void) __ptr64 */

void __thiscall UpaClient::CompleteAsyncRequestsToApiClient(UpaClient *this)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  UpaCollectible *pUVar5;
  undefined *in_R8;
  
  pUVar5 = UpaCollection::PopHead((UpaCollection *)(this + 0x2c8));
  while (pUVar5 != (UpaCollectible *)0x0) {
    if (*(longlong *)(pUVar5 + 0x60) != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(byte *)((longlong)WPP_GLOBAL_Control + 0x1c) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x19))) {
        WPP_SF_dqq(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x10),0x5f,in_R8,
                   *(undefined4 *)(pUVar5 + 0x68),(char)pUVar5,(char)*(undefined8 *)(pUVar5 + 0x28))
        ;
      }
      puVar1 = *(undefined8 **)(pUVar5 + 0x60);
      if (pUVar5 + 0x68 != (UpaCollectible *)0x0) {
        uVar2 = *(undefined4 *)(pUVar5 + 0x6c);
        uVar3 = *(undefined4 *)(pUVar5 + 0x70);
        uVar4 = *(undefined4 *)(pUVar5 + 0x74);
        *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(pUVar5 + 0x68);
        *(undefined4 *)((longlong)puVar1 + 0x14) = uVar2;
        *(undefined4 *)(puVar1 + 3) = uVar3;
        *(undefined4 *)((longlong)puVar1 + 0x1c) = uVar4;
      }
      SetEvent((HANDLE)*puVar1);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      in_R8 = &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x20,
                &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,pUVar5,(char)this);
    }
    (*(code *)**(undefined8 **)pUVar5)(pUVar5,1);
    pUVar5 = UpaCollection::PopHead((UpaCollection *)(this + 0x2c8));
  }
  return;
}



===== CompletingAsyncRequestsToApiClientEntry @ 180004320 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::CompletingAsyncRequestsToApiClientEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::CompletingAsyncRequestsToApiClientEntry
          (void *param_1)

{
  UpaClient::CompleteAsyncRequestsToApiClient
            ((UpaClient *)(-(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U));
  return 5;
}



===== DequeuingRequestEntry @ 180004350 =====

/* public: static unsigned short __cdecl UsbPmApiCallbacksStateMachine<class
   UpaCallbacks>::EntryFuncs::DequeuingRequestEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiCallbacksStateMachine<UpaCallbacks>::EntryFuncs::DequeuingRequestEntry(void *param_1)

{
  UpaCollectible *pUVar1;
  
  pUVar1 = UpaCollection::PopHead((UpaCollection *)((longlong)param_1 + 0x10));
  *(UpaCollectible **)((longlong)param_1 + 0x68) = pUVar1;
  return 3 - (pUVar1 != (UpaCollectible *)0x0);
}



===== DumpAll @ 180004380 =====

/* public: void __cdecl UpaHub::DumpAll(void) __ptr64 */

void __thiscall UpaHub::DumpAll(UpaHub *this)

{
  UpaCollectible *this_00;
  undefined8 in_RDX;
  ulong uVar1;
  undefined8 in_R8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_iiiDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,in_R8,
                 *(undefined8 *)(this + 0x20),(char)*(undefined8 *)(this + 0x30),
                 (char)*(undefined8 *)(this + 0x28),(char)*(undefined4 *)(this + 0x38),(char)this);
  }
  uVar1 = 0;
  if (*(int *)(this + 0x268) != 0) {
    do {
      this_00 = UpaCollection::GetItemByIndex((UpaCollection *)(this + 0x248),uVar1);
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((WPP_GLOBAL_Control[0x1c] & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
          WPP_SF_iiiq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),*(undefined8 *)(this_00 + 0x20),
                      in_R8,*(undefined8 *)(this_00 + 0x38),(char)*(undefined8 *)(this_00 + 0x40),
                      (char)*(undefined8 *)(this_00 + 0x30),(char)*(undefined8 *)(this_00 + 0x20));
        }
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if (((WPP_GLOBAL_Control[0x1c] & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
            WPP_SF_LLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x4d,in_R8,
                       (uint)(byte)this_00[0x59],(char)*(undefined4 *)(this_00 + 0x5a),
                       (char)*(undefined8 *)(this_00 + 0x20));
          }
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if (((WPP_GLOBAL_Control[0x1c] & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
              WPP_SF_LLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x4e,in_R8,
                         *(undefined4 *)(this_00 + 0x50),(char)*(undefined4 *)(this_00 + 0x54),
                         (char)*(undefined8 *)(this_00 + 0x20));
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
              WPP_SF_LLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x4f,in_R8,
                         (uint)(byte)this_00[0x58],(char)*(undefined4 *)(this_00 + 0x5e),
                         (char)*(undefined8 *)(this_00 + 0x20));
            }
          }
        }
      }
      UpaConnector::DumpState((UpaConnector *)this_00);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(this + 0x268));
  }
  return;
}



===== DumpPdo @ 180004534 =====

/* private: void __cdecl UpaConnector::DumpPdo(union _USBC_PD_POWER_DATA_OBJECT * __ptr64,bool,bool)
   __ptr64 */

void __thiscall
UpaConnector::DumpPdo
          (UpaConnector *this,_USBC_PD_POWER_DATA_OBJECT *param_1,bool param_2,bool param_3)

{
  uint uVar1;
  byte bVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined7 in_register_00000081;
  char *pcVar5;
  undefined1 uVar6;
  
  uVar1 = *(uint *)param_1;
  pcVar5 = "Partner";
  if (!param_2) {
    pcVar5 = "Local";
  }
  uVar4 = uVar1 >> 0x1e;
  uVar6 = (undefined1)uVar1;
  bVar2 = (byte)(uVar1 >> 0x18);
  if (uVar4 == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x19] < 4) {
      return;
    }
    uVar4 = uVar1 >> 10 & 0x3ff;
    WPP_SF_ssddddddddDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),(ulonglong)(uVar1 & 0x3ff),
                        (ulonglong)uVar4,pcVar5,"Source",(char)(uVar1 & 0x3ff),(char)uVar4,
                        (byte)(uVar1 >> 0x14) & 3,bVar2 >> 1 & 1,bVar2 >> 2 & 1,bVar2 >> 3 & 1,
                        bVar2 >> 4 & 1,bVar2 >> 5 & 1,uVar6,(char)*(undefined8 *)(this + 0x20));
    return;
  }
  if (uVar4 == 1) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x19] < 4) {
      return;
    }
    uVar3 = 0x56;
  }
  else {
    if (uVar4 != 2) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return;
      }
      if ((byte)WPP_GLOBAL_Control[0x19] < 3) {
        return;
      }
      WPP_SF_ssdDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),(ulonglong)uVar4,
                   CONCAT71(in_register_00000081,param_2),pcVar5,"Source",bVar2 >> 6,uVar6,
                   (char)*(undefined8 *)(this + 0x20));
      return;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x19] < 4) {
      return;
    }
    uVar3 = 0x58;
  }
  WPP_SF_ssdddDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,(ulonglong)(uVar1 & 0x3ff),pcVar5,
                 "Source",(char)(uVar1 & 0x3ff),(char)(uVar1 >> 10),(char)(uVar1 >> 0x14),uVar6,
                 (char)*(undefined8 *)(this + 0x20));
  return;
}



===== DumpState @ 18000477c =====

/* private: void __cdecl UpaConnector::DumpState(void) __ptr64 */

void __thiscall UpaConnector::DumpState(UpaConnector *this)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined8 in_RDX;
  uint uVar4;
  ulonglong uVar5;
  undefined8 in_R8;
  ulonglong in_R9;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((WPP_GLOBAL_Control[0x1c] & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      in_R9 = *(ulonglong *)(this + 0x38);
      WPP_SF_iiDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,in_R8,in_R9,
                  (char)*(undefined8 *)(this + 0x40),(char)*(undefined4 *)(this + 0x36a),
                  (char)*(undefined8 *)(this + 0x20));
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((WPP_GLOBAL_Control[0x1c] & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
        in_R9 = (ulonglong)(byte)this[0x36e];
        WPP_SF_dDLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,in_R8,(uint)(byte)this[0x36e],
                    (char)*(undefined4 *)(this + 0x36f),(char)*(undefined4 *)(this + 0x373),
                    (char)*(undefined8 *)(this + 0x20));
      }
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((WPP_GLOBAL_Control[0x1c] & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
          in_R9 = (ulonglong)*(uint *)(this + 0x38b);
          WPP_SF_LLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x52,in_R8,*(uint *)(this + 0x38b),
                     (char)*(undefined4 *)(this + 0x387),(char)*(undefined8 *)(this + 0x20));
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
          in_R9 = (ulonglong)*(uint *)(this + 0x377);
          WPP_SF_LLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x53,in_R8,*(uint *)(this + 0x377),
                     (char)*(undefined4 *)(this + 0x37b),(char)*(undefined8 *)(this + 0x20));
        }
      }
    }
  }
  uVar5 = 0;
  uVar4 = 0;
  if (this[0x38f] != (UpaConnector)0x0) {
    do {
      DumpPdo(this,(_USBC_PD_POWER_DATA_OBJECT *)(this + ((ulonglong)uVar4 + 0xe4) * 4),false,
              SUB81(in_R9,0));
      uVar4 = uVar4 + 1;
    } while (uVar4 < (byte)this[0x38f]);
  }
  if (this[0x3c9] != (UpaConnector)0x0) {
    do {
      DumpPdo(this,(_USBC_PD_POWER_DATA_OBJECT *)(this + uVar5 * 4 + 0x3ca),true,SUB81(in_R9,0));
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < (byte)this[0x3c9]);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    uVar4 = *(uint *)(this + 899);
    uVar2 = (undefined1)(uVar4 >> 10);
    uVar3 = uVar4 >> 0x1b & 1;
    uVar1 = (undefined1)uVar4;
    WPP_SF_dddddddDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),(ulonglong)uVar3,
                     (ulonglong)(uVar4 & 0x3ff),uVar4 >> 0x1c & 7,uVar1,uVar2,uVar1,uVar2,
                     (byte)(uVar4 >> 0x1a) & 1,(char)uVar3,uVar1,(char)*(undefined8 *)(this + 0x20))
    ;
  }
  return;
}



===== EnqueueEvent @ 1800049c0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl UsbPmApiClientStateMachine<class UpaClient>::EnqueueEvent(enum
   UsbPmApiClientStateMachine<class UpaClient>::Event) __ptr64 */

void __thiscall
UsbPmApiClientStateMachine<UpaClient>::EnqueueEvent
          (UsbPmApiClientStateMachine<UpaClient> *this,Event param_1)

{
  StateMachineEngineImpl *this_00;
  bool bVar1;
  DWORD DVar2;
  ushort uVar3;
  undefined2 uVar4;
  bool bVar5;
  
  this_00 = *(StateMachineEngineImpl **)this;
  uVar3 = (ushort)param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)(this_00 + 0x3d0));
  if (*(int *)(this_00 + 0x3cc) == 5) {
    if (uVar3 == *(ushort *)(this_00 + 0x370)) {
      if (*(code **)(this_00 + 0x390) != (code *)0x0) {
        if (uVar3 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined2 *)
                   (*(longlong *)(*(longlong *)(this_00 + 0x378) + 0x10) + (ulonglong)uVar3 * 4);
        }
        (**(code **)(this_00 + 0x390))(*(undefined8 *)(this_00 + 0x380),uVar4);
      }
      *(undefined2 *)(this_00 + 0x370) = 0;
      goto LAB_18000864b;
    }
    bVar5 = false;
  }
  else {
    bVar5 = *(int *)(this_00 + 0x3cc) == 1;
  }
  bVar1 = SmFx::StateMachineEngine::StateMachineEngineImpl::EnqueueEventWithDisposition
                    (this_00,uVar3);
  if (!bVar1) {
    return;
  }
  if (!bVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(this_00 + 0x3d0));
    return;
  }
LAB_18000864b:
  *(undefined2 *)(this_00 + 0x3c6) = 0;
  DVar2 = GetCurrentThreadId();
  *(DWORD *)(this_00 + 0x3c8) = DVar2;
  SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(this_00);
  return;
}



===== EvtDeviceIoControlCompletedByPolicyManager @ 1800049d0 =====

/* private: static void __cdecl UpaClient::EvtDeviceIoControlCompletedByPolicyManager(void *
   __ptr64,struct _IO_STATUS_BLOCK * __ptr64,unsigned long) */

void __cdecl
UpaClient::EvtDeviceIoControlCompletedByPolicyManager
          (void *param_1,_IO_STATUS_BLOCK *param_2,ulong param_3)

{
  ushort uVar1;
  undefined4 in_register_00000084;
  undefined *puVar2;
  
  puVar2 = (undefined *)CONCAT44(in_register_00000084,param_3);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    puVar2 = &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x42,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  if (*(int *)param_2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x44,puVar2,*(int *)param_2,(char)param_1
               );
    }
    uVar1 = 0xe;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x43,
               &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_1);
    }
    uVar1 = 0xf;
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)((longlong)param_1 + 0x10),uVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x45,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  return;
}



===== EvtHubCollectionChanged @ 180004ad0 =====

/* private: static long __cdecl UpaClient::EvtHubCollectionChanged(struct _WNF_STATE_NAME const *
   __ptr64,unsigned long,void * __ptr64,void const * __ptr64,unsigned long) */

long __cdecl
UpaClient::EvtHubCollectionChanged
          (_WNF_STATE_NAME *param_1,ulong param_2,void *param_3,void *param_4,ulong param_5)

{
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)((longlong)param_3 + 0x10),7);
  return 0;
}



===== EvtIoCtlCompleted @ 180004af0 =====

/* public: void __cdecl UpaAssignPowerLevel::EvtIoCtlCompleted(struct _IO_STATUS_BLOCK * __ptr64)
   __ptr64 */

void __thiscall
UpaAssignPowerLevel::EvtIoCtlCompleted(UpaAssignPowerLevel *this,_IO_STATUS_BLOCK *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x68) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x70) = uVar2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_Ldqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x5e,param_1,*(undefined4 *)(this + 0x20)
                ,(char)*(undefined4 *)param_1,(char)this,(char)*(undefined8 *)(this + 0x28));
  }
  lVar1 = *(longlong *)(this + 0x28);
  UpaCollection::RemoveItem((UpaCollection *)(lVar1 + 0x270),(UpaCollectible *)this);
  UpaCollection::AddItem((UpaCollection *)(lVar1 + 0x2c8),(UpaCollectible *)this);
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(lVar1 + 0x10),2);
  return;
}



===== EvtIoCtlCompletedThunk @ 180004b90 =====

/* private: static void __cdecl UpaAssignPowerLevel::EvtIoCtlCompletedThunk(void * __ptr64,struct
   _IO_STATUS_BLOCK * __ptr64,unsigned long) */

void __cdecl
UpaAssignPowerLevel::EvtIoCtlCompletedThunk(void *param_1,_IO_STATUS_BLOCK *param_2,ulong param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x5c,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  EvtIoCtlCompleted(param_1,param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x5d,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  return;
}



===== EvtLogEventEnqueue @ 180004c28 =====

/* private: void __cdecl UpaCallbacks::EvtLogEventEnqueue(enum UsbPmApiCallbacksStateMachine<class
   UpaCallbacks>::EventId) __ptr64 */

void __thiscall UpaCallbacks::EvtLogEventEnqueue(UpaCallbacks *this,EventId param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x67,&WPP_GLOBAL_Control,param_1 & 0xffff,
              (char)*(undefined8 *)(this + 8));
  }
  return;
}



===== EvtLogEventEnqueue @ 180004c78 =====

/* private: void __cdecl UpaClient::EvtLogEventEnqueue(enum UsbPmApiClientStateMachine<class
   UpaClient>::EventId) __ptr64 */

void __thiscall UpaClient::EvtLogEventEnqueue(UpaClient *this,EventId param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x2c,&WPP_GLOBAL_Control,param_1 & 0xffff,
              (char)this);
  }
  return;
}



===== EvtLogEventEnqueueThunk @ 180004cd0 =====

/* private: static void __cdecl UsbPmApiCallbacksStateMachine<class
   UpaCallbacks>::EvtLogEventEnqueueThunk(void * __ptr64,unsigned short) */

void __cdecl
UsbPmApiCallbacksStateMachine<UpaCallbacks>::EvtLogEventEnqueueThunk(void *param_1,ushort param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x67,&WPP_GLOBAL_Control,(uint)param_2,
              (char)*(undefined8 *)((longlong)param_1 + 8));
  }
  return;
}



===== EvtLogEventEnqueueThunk @ 180004ce0 =====

/* private: static void __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EvtLogEventEnqueueThunk(void * __ptr64,unsigned short) */

void __cdecl
UsbPmApiClientStateMachine<UpaClient>::EvtLogEventEnqueueThunk(void *param_1,ushort param_2)

{
  undefined2 in_register_00000012;
  
  UpaClient::EvtLogEventEnqueue
            ((UpaClient *)(-(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U),
             CONCAT22(in_register_00000012,param_2));
  return;
}



===== EvtLogMachineException @ 180004cf8 =====

/* private: void __cdecl UpaCallbacks::EvtLogMachineException(enum SmFx::MachineException,enum
   UsbPmApiCallbacksStateMachine<class UpaCallbacks>::EventId,enum
   UsbPmApiCallbacksStateMachine<class UpaCallbacks>::StateId) __ptr64 */

void __thiscall
UpaCallbacks::EvtLogMachineException
          (UpaCallbacks *this,MachineException param_1,EventId param_2,StateId param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_LLLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x66,(ulonglong)param_3 & 0xffff,param_1,
                (char)param_2,(char)((ulonglong)param_3 & 0xffff),(char)*(undefined8 *)(this + 8));
  }
  return;
}



===== EvtLogMachineException @ 180004d5c =====

/* private: void __cdecl UpaClient::EvtLogMachineException(enum SmFx::MachineException,enum
   UsbPmApiClientStateMachine<class UpaClient>::EventId,enum UsbPmApiClientStateMachine<class
   UpaClient>::StateId) __ptr64 */

void __thiscall
UpaClient::EvtLogMachineException
          (UpaClient *this,MachineException param_1,EventId param_2,StateId param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_LLLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x2b,(ulonglong)(ushort)param_2,param_1,
                (char)param_2,(char)param_3,(char)this);
  }
  return;
}



===== EvtLogMachineExceptionThunk @ 180004dc0 =====

/* private: static void __cdecl UsbPmApiCallbacksStateMachine<class
   UpaCallbacks>::EvtLogMachineExceptionThunk(void * __ptr64,enum SmFx::MachineException,unsigned
   short,unsigned short) */

void __cdecl
UsbPmApiCallbacksStateMachine<UpaCallbacks>::EvtLogMachineExceptionThunk
          (void *param_1,MachineException param_2,ushort param_3,ushort param_4)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_LLLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x66,(ulonglong)param_4,param_2,
                (char)param_3,(char)param_4,(char)*(undefined8 *)((longlong)param_1 + 8));
  }
  return;
}



===== EvtLogMachineExceptionThunk @ 180004dd0 =====

/* private: static void __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EvtLogMachineExceptionThunk(void * __ptr64,enum SmFx::MachineException,unsigned
   short,unsigned short) */

void __cdecl
UsbPmApiClientStateMachine<UpaClient>::EvtLogMachineExceptionThunk
          (void *param_1,MachineException param_2,ushort param_3,ushort param_4)

{
  undefined2 in_register_00000082;
  undefined2 in_register_0000008a;
  
  UpaClient::EvtLogMachineException
            ((UpaClient *)(-(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U),param_2
             ,CONCAT22(in_register_00000082,param_3),CONCAT22(in_register_0000008a,param_4));
  return;
}



===== EvtLogTransition @ 180004de8 =====

/* private: void __cdecl UpaCallbacks::EvtLogTransition(enum SmFx::TransitionType,enum
   UsbPmApiCallbacksStateMachine<class UpaCallbacks>::StateId,enum
   UsbPmApiCallbacksStateMachine<class UpaCallbacks>::EventId,enum
   UsbPmApiCallbacksStateMachine<class UpaCallbacks>::StateId) __ptr64 */

void __thiscall
UpaCallbacks::EvtLogTransition
          (UpaCallbacks *this,TransitionType param_1,StateId param_2,EventId param_3,StateId param_4
          )

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_LLLLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x68,
                 (ulonglong)(ushort)(undefined2)param_4,param_1,(char)param_2,(char)param_3,
                 (char)param_4,(char)*(undefined8 *)(this + 8));
  }
  return;
}



===== EvtLogTransition @ 180004e5c =====

/* private: void __cdecl UpaClient::EvtLogTransition(enum SmFx::TransitionType,enum
   UsbPmApiClientStateMachine<class UpaClient>::StateId,enum UsbPmApiClientStateMachine<class
   UpaClient>::EventId,enum UsbPmApiClientStateMachine<class UpaClient>::StateId) __ptr64 */

void __thiscall
UpaClient::EvtLogTransition
          (UpaClient *this,TransitionType param_1,StateId param_2,EventId param_3,StateId param_4)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_LLLLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x2d,(ulonglong)param_3 & 0xffff,param_1
                 ,(char)param_2,(char)((ulonglong)param_3 & 0xffff),(char)param_4,(char)this);
  }
  return;
}



===== EvtLogTransitionThunk @ 180004ed0 =====

/* private: static void __cdecl UsbPmApiCallbacksStateMachine<class
   UpaCallbacks>::EvtLogTransitionThunk(void * __ptr64,enum SmFx::TransitionType,unsigned
   short,unsigned short,unsigned short) */

void __cdecl
UsbPmApiCallbacksStateMachine<UpaCallbacks>::EvtLogTransitionThunk
          (void *param_1,TransitionType param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined2 in_register_00000082;
  undefined2 in_register_0000008a;
  undefined2 in_stack_0000002a;
  
  UpaCallbacks::EvtLogTransition
            (param_1,param_2,CONCAT22(in_register_00000082,param_3),
             CONCAT22(in_register_0000008a,param_4),_param_5);
  return;
}



===== EvtLogTransitionThunk @ 180004ef0 =====

/* private: static void __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EvtLogTransitionThunk(void * __ptr64,enum SmFx::TransitionType,unsigned
   short,unsigned short,unsigned short) */

void __cdecl
UsbPmApiClientStateMachine<UpaClient>::EvtLogTransitionThunk
          (void *param_1,TransitionType param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined2 in_register_00000082;
  undefined2 in_register_0000008a;
  undefined2 in_stack_0000002a;
  
  UpaClient::EvtLogTransition
            ((UpaClient *)(-(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U),param_2
             ,CONCAT22(in_register_00000082,param_3),CONCAT22(in_register_0000008a,param_4),_param_5
            );
  return;
}



===== EvtMachineDestroyedThunk @ 180004f20 =====

/* private: static void __cdecl UsbPmApiCallbacksStateMachine<class
   UpaCallbacks>::EvtMachineDestroyedThunk(void * __ptr64) */

void __cdecl UsbPmApiCallbacksStateMachine<UpaCallbacks>::EvtMachineDestroyedThunk(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000180004f24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetEvent(*(HANDLE *)((longlong)param_1 + 0x70));
  return;
}



===== EvtMachineDestroyedThunk @ 180004f40 =====

/* private: static void __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EvtMachineDestroyedThunk(void * __ptr64) */

void __cdecl UsbPmApiClientStateMachine<UpaClient>::EvtMachineDestroyedThunk(void *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)((longlong)param_1 + 0x130);
  if (param_1 == (void *)0x0) {
    puVar1 = (undefined8 *)&DAT_00000140;
  }
                    /* WARNING: Could not recover jumptable at 0x000180004f59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetEvent((HANDLE)*puVar1);
  return;
}



===== EvtPolicyManagerDeviceQueryRemoveCallbackThunk @ 180004f70 =====

/* private: static void __cdecl UpaClient::EvtPolicyManagerDeviceQueryRemoveCallbackThunk(void *
   __ptr64) */

void __cdecl UpaClient::EvtPolicyManagerDeviceQueryRemoveCallbackThunk(void *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x3e,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)((longlong)param_1 + 0x10),0xc);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x3f,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  return;
}



===== EvtPolicyManagerDeviceRemoveFinalCallbackThunk @ 180005000 =====

/* private: static void __cdecl UpaClient::EvtPolicyManagerDeviceRemoveFinalCallbackThunk(void *
   __ptr64) */

void __cdecl UpaClient::EvtPolicyManagerDeviceRemoveFinalCallbackThunk(void *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x40,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)((longlong)param_1 + 0x10),0xd);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x41,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  return;
}



===== EvtPolicyManagerInterfaceArrivalCallback @ 180005090 =====

/* private: long __cdecl UpaClient::EvtPolicyManagerInterfaceArrivalCallback(struct _UNICODE_STRING
   const * __ptr64) __ptr64 */

long __thiscall
UpaClient::EvtPolicyManagerInterfaceArrivalCallback(UpaClient *this,_UNICODE_STRING *param_1)

{
  bool bVar1;
  int iVar2;
  undefined2 uVar3;
  UpaClient *pUVar4;
  undefined *in_R8;
  undefined8 *puVar5;
  undefined4 local_res8 [4];
  undefined4 local_res18 [2];
  longlong local_res20;
  undefined1 uVar6;
  UpaClient *in_stack_ffffffffffffff38;
  undefined8 in_stack_ffffffffffffff40;
  undefined4 uVar7;
  ulonglong in_stack_ffffffffffffff48;
  ulonglong in_stack_ffffffffffffff58;
  undefined4 uVar8;
  undefined8 local_88;
  longlong lStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff40 >> 0x20);
  local_res20 = 0;
  bVar1 = false;
  local_68 = 0;
  uStack_60 = 0;
  local_res8[0] = 0;
  local_58 = (undefined8 *)0x0;
  uStack_50 = 0;
  local_res18[0] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_78 = 0;
  uStack_70 = 0;
  pUVar4 = (UpaClient *)param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    pUVar4 = (UpaClient *)0x34;
    in_R8 = &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x34,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  local_88 = 0;
  lStack_80 = 0;
  uVar6 = SUB81(this,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    pUVar4 = (UpaClient *)0x35;
    in_stack_ffffffffffffff38 = this;
    WPP_SF_Sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x35,in_R8,*(wchar_t **)(param_1 + 8),uVar6
             );
  }
  if (*(longlong *)(this + 0x130) == 0) {
    if (*(longlong *)(this + 0x128) != 0) {
      pUVar4 = this + 0x120;
      in_R8 = (undefined *)0x0;
      iVar2 = RtlCompareUnicodeString(param_1);
      if (iVar2 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x19])) {
          WPP_SF_Sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x37,in_R8,
                    *(wchar_t **)(this + 0x128),uVar6);
        }
        iVar2 = -0x3fffffcc;
        goto LAB_18000547a;
      }
    }
    lStack_80 = _o_malloc(*(undefined2 *)(param_1 + 2));
    if (lStack_80 == 0) {
      iVar2 = -0x3fffff66;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x19])) {
        WPP_SF_Ldq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pUVar4,in_R8,
                   (uint)*(ushort *)(param_1 + 2),in_stack_ffffffffffffff38,uVar6);
        iVar2 = -0x3fffff66;
      }
      goto LAB_18000547a;
    }
    local_88 = (ulonglong)CONCAT42(local_88._4_4_,*(undefined2 *)(param_1 + 2)) << 0x10;
    RtlCopyUnicodeString(&local_88,param_1);
    if ((3 < (ushort)local_88) && (*(short *)(lStack_80 + 2) == 0x5c)) {
      *(undefined2 *)(lStack_80 + 2) = 0x3f;
      bVar1 = true;
    }
    local_58 = &local_88;
    uVar8 = 0;
    puVar5 = &local_68;
    local_68 = CONCAT44(local_68._4_4_,0x30);
    uStack_60 = 0;
    uStack_50 = CONCAT44(uStack_50._4_4_,0x200);
    local_48 = 0;
    uStack_40 = 0;
    iVar2 = NtCreateFile(&local_res20,3,puVar5,&local_78,0,CONCAT44(uVar7,3),
                         in_stack_ffffffffffffff48 & 0xffffffff00000000,0,
                         in_stack_ffffffffffffff58 & 0xffffffff00000000,0,0);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x19] < 2))
      goto LAB_18000547a;
      uVar3 = 0x39;
    }
    else {
      local_res8[0] = *(undefined4 *)(this + 0x1c);
      puVar5 = (undefined8 *)0x0;
      iVar2 = NtDeviceIoControlFile
                        (local_res20,0,0,0,&local_78,0x574200,local_res8,4,local_res18,
                         CONCAT44(uVar8,4));
      if (iVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x19] < 2))
        goto LAB_18000547a;
        uVar3 = 0x3a;
      }
      else {
        *(undefined8 *)(this + 0x118) = 0;
        *(longlong *)(this + 0xf8) = local_res20;
        *(code **)(this + 0x100) = EvtPolicyManagerDeviceQueryRemoveCallbackThunk;
        *(code **)(this + 0x108) = EvtPolicyManagerDeviceRemoveFinalCallbackThunk;
        *(UpaClient **)(this + 0x110) = this;
        iVar2 = UsbPmApip_RegisterDeviceRemovalCallbacks
                          ((_USBPMAPIP_DEVICE_REMOVAL_CALLBACK_CONFIG *)(this + 0xf8));
        if (-1 < iVar2) {
          if (*(longlong *)(this + 0x128) == 0) {
            if (bVar1) {
              *(undefined2 *)(lStack_80 + 2) = 0x5c;
            }
            *(longlong *)(this + 0x120) = local_88;
            *(longlong *)(this + 0x128) = lStack_80;
            local_88 = 0;
            lStack_80 = 0;
          }
          *(undefined4 *)(this + 0x138) = local_res18[0];
          *(longlong *)(this + 0x130) = local_res20;
          local_res20 = 0;
          SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(this + 0x10),0xb);
          goto LAB_180005477;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((WPP_GLOBAL_Control[0x1c] & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x19] < 2))
        goto LAB_18000547a;
        uVar3 = 0x3b;
      }
    }
    WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,puVar5,iVar2,uVar6);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x36,
               &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this);
    }
LAB_180005477:
    iVar2 = 0;
  }
LAB_18000547a:
  if (lStack_80 != 0) {
    _o_free(lStack_80);
    lStack_80 = 0;
  }
  if (local_res20 != 0) {
    NtClose(local_res20);
    local_res20 = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x3d,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  return iVar2;
}



===== EvtPolicyManagerInterfaceArrivalCallbackThunk @ 180005510 =====

/* private: static long __cdecl UpaClient::EvtPolicyManagerInterfaceArrivalCallbackThunk(struct
   _UNICODE_STRING const * __ptr64,void * __ptr64) */

long __cdecl
UpaClient::EvtPolicyManagerInterfaceArrivalCallbackThunk(_UNICODE_STRING *param_1,void *param_2)

{
  long lVar1;
  
  lVar1 = EvtPolicyManagerInterfaceArrivalCallback(param_2,param_1);
  return lVar1;
}



===== EvtRequestCallback @ 180005524 =====

/* public: void __cdecl UpaCallbacks::EvtRequestCallback(struct _USBPM_EVENT_CALLBACK_PARAMS *
   __ptr64) __ptr64 */

void __thiscall
UpaCallbacks::EvtRequestCallback(UpaCallbacks *this,_USBPM_EVENT_CALLBACK_PARAMS *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  UpaCollectible *this_00;
  
  this_00 = UpaBaseClass::operator_new(0x38);
  if (this_00 == (UpaCollectible *)0x0) {
    this_00 = (UpaCollectible *)0x0;
  }
  else {
    UpaCollectible::UpaCollectible(this_00);
    uVar2 = *(undefined8 *)param_1;
    uVar3 = *(undefined8 *)(param_1 + 8);
    *(undefined ***)this_00 = &UpaCallback::_vftable_;
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    *(undefined8 *)(this_00 + 0x20) = uVar2;
    *(undefined8 *)(this_00 + 0x28) = uVar3;
    *(undefined4 *)(this_00 + 0x30) = uVar1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x60,
               &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,this_00);
    }
  }
  UpaCollection::AddItem((UpaCollection *)(this + 0x10),this_00);
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,4);
  return;
}



===== FailedEntry @ 1800055e0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::FailedEntry(void * __ptr64) */

ushort __cdecl UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::FailedEntry(void *param_1)

{
  return 0;
}



===== FindingNextRemovedHubEntry @ 1800055f0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::FindingNextRemovedHubEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::FindingNextRemovedHubEntry(void *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  UpaCollectible *pUVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  longlong *plVar8;
  int *piVar9;
  UpaCollection *this;
  uint *puVar10;
  
  piVar9 = (int *)((longlong)param_1 + 0x37c);
  piVar5 = (int *)((longlong)param_1 + 0x378);
  puVar10 = (uint *)((longlong)param_1 + 0x1160);
  if (param_1 == (void *)0x0) {
    piVar9 = (int *)&DAT_0000038c;
    piVar5 = (int *)&DAT_00000388;
    puVar10 = (uint *)&DAT_00001170;
  }
  uVar7 = *puVar10;
  if (uVar7 < (uint)(*piVar9 + *piVar5)) {
    puVar6 = (uint *)((longlong)param_1 + 0x178);
    plVar8 = (longlong *)((longlong)param_1 + 0x11c0);
    if (param_1 == (void *)0x0) {
      puVar6 = (uint *)&DAT_00000188;
      plVar8 = (longlong *)&DAT_000011d0;
    }
    do {
      *plVar8 = 0;
      plVar1 = (longlong *)((ulonglong)uVar7 * 8 + 0x390);
      plVar3 = (longlong *)((longlong)param_1 + -0x10 + (longlong)plVar1);
      if (param_1 == (void *)0x0) {
        plVar3 = plVar1;
      }
      uVar7 = 0;
      lVar2 = *plVar3;
      if (*puVar6 != 0) {
        this = (UpaCollection *)((longlong)param_1 + 0x158);
        if (param_1 == (void *)0x0) {
          this = (UpaCollection *)0x168;
        }
        do {
          pUVar4 = UpaCollection::GetItemByIndex(this,*puVar10);
          if (*(longlong *)(pUVar4 + 0x20) == lVar2) {
            *plVar8 = (longlong)pUVar4;
            break;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < *puVar6);
      }
      uVar7 = *puVar10 + 1;
      lVar2 = *plVar8;
      *puVar10 = uVar7;
      if (lVar2 != 0) {
        return 5;
      }
    } while (uVar7 < (uint)(*piVar5 + *piVar9));
  }
  return 10;
}



===== GenericTableAllocateRoutine @ 180005720 =====

/* private: static void * __ptr64 __cdecl
   GlobalObjectPointerTable::GenericTableAllocateRoutine(struct _RTL_GENERIC_TABLE *
   __ptr64,unsigned long) */

void * __cdecl
GlobalObjectPointerTable::GenericTableAllocateRoutine(_RTL_GENERIC_TABLE *param_1,ulong param_2)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180005722. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)_o_malloc(param_2);
  return pvVar1;
}



===== GenericTableCompareRoutine @ 180005740 =====

/* private: static enum _RTL_GENERIC_COMPARE_RESULTS __cdecl
   GlobalObjectPointerTable::GenericTableCompareRoutine(struct _RTL_GENERIC_TABLE * __ptr64,void *
   __ptr64,void * __ptr64) */

_RTL_GENERIC_COMPARE_RESULTS __cdecl
GlobalObjectPointerTable::GenericTableCompareRoutine
          (_RTL_GENERIC_TABLE *param_1,void *param_2,void *param_3)

{
  if (*(ulonglong *)param_3 < *(ulonglong *)param_2) {
    return 1;
  }
  return ~-(uint)(*(ulonglong *)param_2 < *(ulonglong *)param_3) & 2;
}



===== GenericTableFreeRoutine @ 180005760 =====

/* private: static void __cdecl GlobalObjectPointerTable::GenericTableFreeRoutine(struct
   _RTL_GENERIC_TABLE * __ptr64,void * __ptr64) */

void __cdecl
GlobalObjectPointerTable::GenericTableFreeRoutine(_RTL_GENERIC_TABLE *param_1,void *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000180005763. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_free(param_2);
  return;
}



===== GetItemByIndex @ 180005778 =====

/* public: class UpaCollectible * __ptr64 __cdecl UpaCollection::GetItemByIndex(unsigned long)
   __ptr64 */

UpaCollectible * __thiscall UpaCollection::GetItemByIndex(UpaCollection *this,ulong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  puVar2 = (undefined8 *)0x0;
  if (param_1 < *(uint *)(this + 0x20)) {
    for (puVar1 = *(undefined8 **)(this + 0x10);
        (puVar2 = puVar1, param_1 != 0 && (puVar2 = (undefined8 *)0x0, puVar1 != (undefined8 *)0x0))
        ; puVar1 = (undefined8 *)*puVar1) {
      param_1 = param_1 - 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  return (UpaCollectible *)(-(ulonglong)(puVar2 != (undefined8 *)0x0) & (ulonglong)(puVar2 + -2));
}



===== GettingConnectorStateEntry @ 180005800 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::GettingConnectorStateEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::GettingConnectorStateEntry(void *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  uVar3 = -(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U;
  lVar1 = *(longlong *)(&DAT_000011d8 + uVar3);
  *(undefined4 *)(uVar3 + 800) = 0x574210;
  uVar2 = *(undefined8 *)(lVar1 + 0x38);
  *(ulonglong *)(uVar3 + 0x380) = uVar3 + 0x7ac;
  *(ulonglong *)(uVar3 + 0x340) = uVar3 + 0x348;
  *(code **)(uVar3 + 0x330) = UpaClient::EvtDeviceIoControlCompletedByPolicyManager;
  *(undefined8 *)(uVar3 + 0x368) = uVar2;
  *(undefined4 *)(uVar3 + 0x324) = 8;
  *(undefined4 *)(uVar3 + 0x328) = 0x690;
  *(ulonglong *)(uVar3 + 0x338) = uVar3;
  return 0;
}



===== GettingHubCollectionDeltaEntry @ 180005880 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::GettingHubCollectionDeltaEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::GettingHubCollectionDeltaEntry(void *param_1)

{
  UpaCollectible *pUVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulong uVar4;
  
  uVar3 = -(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U;
  uVar4 = 0;
  *(undefined4 *)(uVar3 + 800) = 0x574204;
  *(int *)(uVar3 + 0x368) = *(int *)(uVar3 + 0x188);
  if (*(int *)(uVar3 + 0x188) != 0) {
    do {
      pUVar1 = UpaCollection::GetItemByIndex((UpaCollection *)(uVar3 + 0x168),uVar4);
      uVar2 = (ulonglong)uVar4;
      uVar4 = uVar4 + 1;
      *(undefined8 *)(uVar3 + 0x36c + uVar2 * 0x10) = *(undefined8 *)(pUVar1 + 0x20);
      *(undefined8 *)(uVar3 + 0x374 + uVar2 * 0x10) = *(undefined8 *)(pUVar1 + 0x30);
    } while (uVar4 < *(uint *)(uVar3 + 0x188));
  }
  *(ulonglong *)(uVar3 + 0x380) = uVar3 + 0x388;
  *(undefined4 *)(&DAT_00001170 + uVar3) = 0;
  *(ulonglong *)(uVar3 + 0x340) = uVar3 + 0x348;
  *(code **)(uVar3 + 0x330) = UpaClient::EvtDeviceIoControlCompletedByPolicyManager;
  *(undefined4 *)(uVar3 + 0x324) = 0x14;
  *(undefined4 *)(uVar3 + 0x328) = 0x208;
  *(ulonglong *)(uVar3 + 0x338) = uVar3;
  return 0;
}



===== GettingNextConnectorStateChangeEntry @ 180005960 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::GettingNextConnectorStateChangeEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::GettingNextConnectorStateChangeEntry
          (void *param_1)

{
  longlong lVar1;
  ushort uVar2;
  UpaCollectible *pUVar3;
  longlong *plVar4;
  UpaCollection *this;
  
  this = (UpaCollection *)((longlong)param_1 + 0x1b0);
  if (param_1 == (void *)0x0) {
    this = (UpaCollection *)0x1c0;
  }
  pUVar3 = UpaCollection::PopHead(this);
  if (pUVar3 == (UpaCollectible *)0x0) {
    uVar2 = 10;
  }
  else {
    lVar1 = *(longlong *)(pUVar3 + 0x20);
    plVar4 = (longlong *)((longlong)param_1 + 0x11c8);
    if (param_1 == (void *)0x0) {
      plVar4 = (longlong *)&DAT_000011d8;
    }
    *plVar4 = lVar1;
    uVar2 = 5;
    *(undefined1 *)(lVar1 + 0xa28) = 0;
  }
  return uVar2;
}



===== Initialize @ 1800059c0 =====

/* public: long __cdecl UsbPmApiCallbacksStateMachine<class UpaCallbacks>::Initialize(struct
   UsbPmApiCallbacksStateMachine<class UpaCallbacks>::StateMachineEngineConfig const & __ptr64)
   __ptr64 */

long __thiscall
UsbPmApiCallbacksStateMachine<UpaCallbacks>::Initialize
          (UsbPmApiCallbacksStateMachine<UpaCallbacks> *this,StateMachineEngineConfig *param_1)

{
  long lVar1;
  STATE_MACHINE_SPECIFICATION *local_48;
  UsbPmApiCallbacksStateMachine<UpaCallbacks> *local_40;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  undefined2 local_18;
  undefined4 local_16;
  undefined2 local_12;
  
  local_16 = 0;
  local_12 = 0;
  local_48 = &c_specification;
  local_18 = 0x201;
  local_38 = EvtLogMachineExceptionThunk;
  local_30 = EvtLogEventEnqueueThunk;
  local_28 = EvtLogTransitionThunk;
  local_20 = EvtMachineDestroyedThunk;
  local_40 = this;
  lVar1 = SmFx::StateMachineEngine::Initialize
                    ((StateMachineEngine *)this,(STATE_MACHINE_ENGINE_CONFIG *)&local_48);
  return lVar1;
}



===== Initialize @ 180005a2c =====

/* public: long __cdecl UsbPmApiClientStateMachine<class UpaClient>::Initialize(struct
   UsbPmApiClientStateMachine<class UpaClient>::StateMachineEngineConfig const & __ptr64) __ptr64 */

long __thiscall
UsbPmApiClientStateMachine<UpaClient>::Initialize
          (UsbPmApiClientStateMachine<UpaClient> *this,StateMachineEngineConfig *param_1)

{
  long lVar1;
  STATE_MACHINE_SPECIFICATION *local_48;
  UsbPmApiClientStateMachine<UpaClient> *local_40;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  undefined2 local_18;
  undefined4 local_16;
  undefined2 local_12;
  
  local_16 = 0;
  local_12 = 0;
  local_48 = &c_specification;
  local_18 = 0x401;
  local_38 = EvtLogMachineExceptionThunk;
  local_30 = EvtLogEventEnqueueThunk;
  local_28 = EvtLogTransitionThunk;
  local_20 = EvtMachineDestroyedThunk;
  local_40 = this;
  lVar1 = SmFx::StateMachineEngine::Initialize
                    ((StateMachineEngine *)this,(STATE_MACHINE_ENGINE_CONFIG *)&local_48);
  return lVar1;
}



===== InvokingCallbackEntry @ 180005aa0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: static unsigned short __cdecl UsbPmApiCallbacksStateMachine<class
   UpaCallbacks>::EntryFuncs::InvokingCallbackEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiCallbacksStateMachine<UpaCallbacks>::EntryFuncs::InvokingCallbackEntry(void *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 in_RDX;
  undefined8 in_R8;
  
  lVar1 = *(longlong *)((longlong)param_1 + 8);
  lVar2 = *(longlong *)((longlong)param_1 + 0x68);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_Lqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),in_RDX,in_R8,*(undefined4 *)(lVar2 + 0x20)
               ,(char)*(undefined8 *)(lVar2 + 0x24),(char)lVar1);
  }
  (**(code **)(lVar1 + 0x20))(lVar2 + 0x20);
  puVar3 = *(undefined8 **)((longlong)param_1 + 0x68);
  if (puVar3 != (undefined8 *)0x0) {
    (**(code **)*puVar3)(puVar3,1);
  }
  *(undefined8 *)((longlong)param_1 + 0x68) = 0;
  return 2;
}



===== MarkingPolicyManagerBeingQueryRemovedEntry @ 180005b40 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::MarkingPolicyManagerBeingQueryRemovedEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::MarkingPolicyManagerBeingQueryRemovedEntry
          (void *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)((longlong)param_1 + 0x115e);
  if (param_1 == (void *)0x0) {
    puVar1 = &DAT_0000116e;
  }
  *puVar1 = 1;
  return 5;
}



===== PolicyManagerArrivedEntry @ 180005b70 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::PolicyManagerArrivedEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::PolicyManagerArrivedEntry(void *param_1)

{
  undefined1 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((longlong)param_1 + 0x230);
  if (param_1 == (void *)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x240;
  }
  EnterCriticalSection(lpCriticalSection);
  puVar1 = (undefined1 *)((longlong)param_1 + 600);
  if (param_1 == (void *)0x0) {
    puVar1 = &DAT_00000268;
  }
  *puVar1 = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



===== PopHead @ 180005be8 =====

/* public: class UpaCollectible * __ptr64 __cdecl UpaCollection::PopHead(void) __ptr64 */

UpaCollectible * __thiscall UpaCollection::PopHead(UpaCollection *this)

{
  UpaCollection *pUVar1;
  longlong lVar2;
  code *pcVar3;
  UpaCollectible *pUVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  if (*(int *)(this + 0x20) != 0) {
    pUVar1 = this + 0x10;
    plVar5 = *(longlong **)pUVar1;
    if (((UpaCollection *)plVar5[1] != pUVar1) ||
       (lVar2 = *plVar5, *(longlong **)(lVar2 + 8) != plVar5)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      pUVar4 = (UpaCollectible *)(*pcVar3)();
      return pUVar4;
    }
    *(longlong *)pUVar1 = lVar2;
    *(UpaCollection **)(lVar2 + 8) = pUVar1;
    *(int *)(this + 0x20) = *(int *)(this + 0x20) + -1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  return (UpaCollectible *)(-(ulonglong)(plVar5 != (longlong *)0x0) & (ulonglong)(plVar5 + -2));
}



===== PreparingNextGetConnectorSnapshotEntry @ 180005c70 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::PreparingNextGetConnectorSnapshotEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::PreparingNextGetConnectorSnapshotEntry
          (void *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  ushort uVar4;
  ulonglong uVar5;
  
  uVar5 = -(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U;
  uVar1 = *(uint *)(uVar5 + 0x1174);
  uVar2 = *(uint *)(uVar5 + 0x5a8);
  if (uVar1 < uVar2) {
    *(undefined4 *)(uVar5 + 800) = 0x57420c;
    uVar3 = *(undefined8 *)(uVar5 + 0x5ac + (ulonglong)uVar1 * 8);
    *(ulonglong *)(uVar5 + 0x380) = uVar5 + 0x7ac;
    *(ulonglong *)(uVar5 + 0x340) = uVar5 + 0x348;
    *(code **)(uVar5 + 0x330) = UpaClient::EvtDeviceIoControlCompletedByPolicyManager;
    *(undefined8 *)(uVar5 + 0x368) = uVar3;
    *(undefined4 *)(uVar5 + 0x324) = 8;
    *(undefined4 *)(uVar5 + 0x328) = 0x9c2;
    *(ulonglong *)(uVar5 + 0x338) = uVar5;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_DDiq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),(ulonglong)uVar2,uVar3,uVar1,
                  (char)uVar2,(char)uVar3,(char)uVar5);
    }
    *(int *)(uVar5 + 0x1174) = *(int *)(uVar5 + 0x1174) + 1;
    uVar4 = 5;
  }
  else {
    uVar4 = 10;
  }
  return uVar4;
}



===== PreparingNextGetHubPropertiesEntry @ 180005d50 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::PreparingNextGetHubPropertiesEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::PreparingNextGetHubPropertiesEntry(void *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  ushort uVar4;
  ulonglong uVar5;
  
  uVar5 = -(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U;
  uVar1 = *(uint *)(&DAT_00001170 + uVar5);
  uVar2 = *(uint *)(uVar5 + 0x388);
  if (uVar1 < uVar2) {
    *(undefined4 *)(uVar5 + 800) = 0x574208;
    uVar3 = *(undefined8 *)(uVar5 + 0x390 + (ulonglong)uVar1 * 8);
    *(ulonglong *)(uVar5 + 0x380) = uVar5 + 0x590;
    *(ulonglong *)(uVar5 + 0x340) = uVar5 + 0x348;
    *(code **)(uVar5 + 0x330) = UpaClient::EvtDeviceIoControlCompletedByPolicyManager;
    *(undefined8 *)(uVar5 + 0x368) = uVar3;
    *(undefined4 *)(uVar5 + 0x324) = 8;
    *(undefined4 *)(uVar5 + 0x328) = 0x21c;
    *(ulonglong *)(uVar5 + 0x338) = uVar5;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_Ddiq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),(ulonglong)uVar2,uVar3,uVar1,
                  (char)uVar2,(char)uVar3,(char)uVar5);
    }
    *(int *)(&DAT_00001170 + uVar5) = *(int *)(&DAT_00001170 + uVar5) + 1;
    uVar4 = 5;
    *(undefined4 *)(uVar5 + 0x1174) = 0;
  }
  else {
    uVar4 = 10;
  }
  return uVar4;
}



===== RegisteringConnectorsChangeNotificationsEntry @ 180005e40 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::RegisteringConnectorsChangeNotificationsEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::RegisteringConnectorsChangeNotificationsEntry
          (void *param_1)

{
  UpaCollectible *pUVar1;
  longlong lVar2;
  uint uVar3;
  longlong *plVar4;
  UpaCollectible *pUVar5;
  ulonglong uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 in_R8;
  
  plVar4 = (longlong *)((longlong)param_1 + 0x11c0);
  if (param_1 == (void *)0x0) {
    plVar4 = (longlong *)&DAT_000011d0;
  }
  uVar6 = 0;
  lVar2 = *plVar4;
  if (*(int *)(lVar2 + 0x268) != 0) {
    do {
      uVar8 = (ulong)uVar6;
      pUVar5 = UpaCollection::GetItemByIndex((UpaCollection *)(lVar2 + 0x248),uVar8);
      if (*(longlong *)(pUVar5 + 0x9f8) != 0) {
LAB_180005f69:
        uVar7 = 0;
        if (uVar8 != 0) {
          do {
            pUVar5 = UpaCollection::GetItemByIndex((UpaCollection *)(lVar2 + 0x248),uVar7);
            if (*(longlong *)(pUVar5 + 0x9f8) != 0) {
              UsbPmApip_WnfUnsubscribeChangeNotification((undefined8 *)(pUVar5 + 0x9f8));
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar8);
        }
        SmFx::StateMachineEngine::EnqueueEvent
                  ((StateMachineEngine *)(*(longlong *)(lVar2 + 0x240) + 0x10),0x12);
        return 5;
      }
      pUVar1 = pUVar5 + 0x48;
      uVar3 = UsbPmApip_WnfSubscribeChangeNotification
                        ((undefined8 *)pUVar1,uVar6,in_R8,0x180006c60,pUVar5,
                         (undefined8 *)(pUVar5 + 0x9f8));
      if ((int)uVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
          WPP_SF_qiLLdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),(ulonglong)uVar3,in_R8,pUVar5,
                        (char)*(undefined8 *)(pUVar5 + 0x40),(char)*(undefined4 *)pUVar1,
                        (char)*(undefined4 *)(pUVar5 + 0x4c),(char)uVar3,
                        (char)*(undefined8 *)(pUVar5 + 0x20));
        }
        goto LAB_180005f69;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
        WPP_SF_qiLLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),(ulonglong)uVar3,in_R8,pUVar5,
                     (char)*(undefined8 *)(pUVar5 + 0x40),(char)*(undefined4 *)pUVar1,
                     (char)*(undefined4 *)(pUVar5 + 0x4c),(char)*(undefined8 *)(pUVar5 + 0x20));
      }
      uVar6 = (ulonglong)(uVar8 + 1);
    } while (uVar8 + 1 < *(uint *)(lVar2 + 0x268));
  }
  return 5;
}



===== RegisteringHubCollectionChangeNotificationsEntry @ 180005fd0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::RegisteringHubCollectionChangeNotificationsEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::RegisteringHubCollectionChangeNotificationsEntry
          (void *param_1)

{
  int iVar1;
  undefined8 in_RDX;
  ulonglong uVar2;
  undefined8 in_R8;
  
  uVar2 = -(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U;
  iVar1 = UsbPmApip_WnfSubscribeChangeNotification
                    ((undefined8 *)&WNF_USB_POLICY_MANAGER_HUB_COLLECTION_STATE,in_RDX,in_R8,
                     0x180004ad0,uVar2,(undefined8 *)(uVar2 + 0x160));
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x29,in_R8,iVar1,(char)uVar2);
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x2a,
             &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,uVar2);
  }
  return 5;
}



===== RegisteringPolicyManagerInterfaceNotificationsEntry @ 180006090 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::RegisteringPolicyManagerInterfaceNotificationsEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::
RegisteringPolicyManagerInterfaceNotificationsEntry(void *param_1)

{
  long lVar1;
  ulonglong uVar2;
  undefined8 in_R8;
  
  uVar2 = -(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U;
  *(undefined8 *)(uVar2 + 0xf0) = 0;
  *(code **)(uVar2 + 0xe0) = UpaClient::EvtPolicyManagerInterfaceArrivalCallbackThunk;
  *(ulonglong *)(uVar2 + 0xe8) = uVar2;
  *(undefined8 *)(uVar2 + 0xd0) = 0x486b34a74cedf9cf;
  *(undefined8 *)(uVar2 + 0xd8) = 0x7c46e42e81203690;
  lVar1 = UsbPmApip_RegisterInterfaceArrivalCallbacks
                    ((_USBPMAPIP_INTERFACE_ARRIVAL_CALLBACK_CONFIG *)(uVar2 + 0xd0));
  if (lVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x21,in_R8,lVar1,(char)uVar2);
    }
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(uVar2 + 0x10),0x12);
  }
  return 5;
}



===== RemoveItem @ 180006130 =====

/* public: unsigned long __cdecl UpaCollection::RemoveItem(class UpaCollectible * __ptr64) __ptr64
    */

ulong __thiscall UpaCollection::RemoveItem(UpaCollection *this,UpaCollectible *param_1)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  ulong uVar5;
  UpaCollectible *pUVar6;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
  pUVar6 = param_1 + 0x10;
  lVar2 = *(longlong *)pUVar6;
  if ((*(UpaCollectible **)(lVar2 + 8) == pUVar6) &&
     (plVar3 = *(longlong **)(param_1 + 0x18), (UpaCollectible *)*plVar3 == pUVar6)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    iVar1 = *(int *)(this + 0x20);
    *(ulong *)(this + 0x20) = iVar1 - 1U;
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x28));
    return iVar1 - 1U;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  uVar5 = (*pcVar4)();
  return uVar5;
}



===== RemovingHubFromCollectionEntry @ 1800061b0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::RemovingHubFromCollectionEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::RemovingHubFromCollectionEntry(void *param_1)

{
  UpaCollection *this;
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)((longlong)param_1 + 0x11c0);
  this = (UpaCollection *)((longlong)param_1 + 0x158);
  if (param_1 == (void *)0x0) {
    puVar1 = (undefined8 *)&DAT_000011d0;
    this = (UpaCollection *)0x168;
  }
  UpaCollection::RemoveItem(this,(UpaCollectible *)*puVar1);
  return 5;
}



===== ReportingConnectorStateChangeEntry @ 180006200 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::ReportingConnectorStateChangeEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::ReportingConnectorStateChangeEntry(void *param_1)

{
  UpaConnector *this;
  undefined8 uVar1;
  undefined4 *puVar2;
  UpaConnector *pUVar3;
  undefined8 *puVar4;
  UpaCallbacks *this_00;
  ulonglong *puVar5;
  bool bVar6;
  undefined4 local_28;
  ulonglong local_24;
  undefined8 local_1c;
  
  puVar5 = (ulonglong *)((longlong)param_1 + 0x11c8);
  if (param_1 == (void *)0x0) {
    puVar5 = (ulonglong *)&DAT_000011d8;
  }
  bVar6 = param_1 == (void *)0x0;
  puVar2 = (undefined4 *)((longlong)param_1 + 0x7a4);
  if (bVar6) {
    puVar2 = (undefined4 *)&DAT_000007b4;
  }
  this = (UpaConnector *)*puVar5;
  *(undefined4 *)(this + 0x36a) = *puVar2;
  pUVar3 = (UpaConnector *)((longlong)param_1 + 0x7a8);
  if (bVar6) {
    pUVar3 = (UpaConnector *)&DAT_000007b8;
  }
  this[0x36e] = *pUVar3;
  puVar2 = (undefined4 *)((longlong)param_1 + 0x7a9);
  if (bVar6) {
    puVar2 = (undefined4 *)&DAT_000007b9;
  }
  *(undefined4 *)(this + 0x36f) = *puVar2;
  puVar2 = (undefined4 *)((longlong)param_1 + 0x7b1);
  if (bVar6) {
    puVar2 = (undefined4 *)&DAT_000007c1;
  }
  *(undefined4 *)(this + 0x377) = *puVar2;
  puVar2 = (undefined4 *)((longlong)param_1 + 0x7c1);
  if (bVar6) {
    puVar2 = (undefined4 *)&DAT_000007d1;
  }
  *(undefined4 *)(this + 0x387) = *puVar2;
  puVar2 = (undefined4 *)((longlong)param_1 + 0x7ad);
  if (bVar6) {
    puVar2 = (undefined4 *)&DAT_000007bd;
  }
  *(undefined4 *)(this + 0x373) = *puVar2;
  puVar2 = (undefined4 *)((longlong)param_1 + 0x7c5);
  if (bVar6) {
    puVar2 = (undefined4 *)&DAT_000007d5;
  }
  *(undefined4 *)(this + 0x38b) = *puVar2;
  puVar2 = (undefined4 *)((longlong)param_1 + 0x7b5);
  if (bVar6) {
    puVar2 = (undefined4 *)&DAT_000007c5;
  }
  *(undefined4 *)(this + 0x37b) = *puVar2;
  pUVar3 = (UpaConnector *)((longlong)param_1 + 0x803);
  if (bVar6) {
    pUVar3 = (UpaConnector *)&DAT_00000813;
  }
  this[0x3c9] = *pUVar3;
  pUVar3 = (UpaConnector *)((longlong)param_1 + 0x7c9);
  if (bVar6) {
    pUVar3 = (UpaConnector *)&DAT_000007d9;
  }
  this[0x38f] = *pUVar3;
  pUVar3 = (UpaConnector *)((longlong)param_1 + 0x7e6);
  if (bVar6) {
    pUVar3 = (UpaConnector *)&DAT_000007f6;
  }
  this[0x3ac] = *pUVar3;
  puVar2 = (undefined4 *)((longlong)param_1 + 0x7bd);
  if (bVar6) {
    puVar2 = (undefined4 *)&DAT_000007cd;
  }
  *(undefined4 *)(this + 899) = *puVar2;
  puVar4 = (undefined8 *)((longlong)param_1 + 0x804);
  if (bVar6) {
    puVar4 = (undefined8 *)&DAT_00000814;
  }
  uVar1 = puVar4[1];
  *(undefined8 *)(this + 0x3ca) = *puVar4;
  *(undefined8 *)(this + 0x3d2) = uVar1;
  *(undefined8 *)(this + 0x3da) = puVar4[2];
  *(undefined4 *)(this + 0x3e2) = *(undefined4 *)(puVar4 + 3);
  puVar4 = (undefined8 *)((longlong)param_1 + 0x7ca);
  if (bVar6) {
    puVar4 = (undefined8 *)&DAT_000007da;
  }
  uVar1 = puVar4[1];
  *(undefined8 *)(this + 0x390) = *puVar4;
  *(undefined8 *)(this + 0x398) = uVar1;
  *(undefined8 *)(this + 0x3a0) = puVar4[2];
  *(undefined4 *)(this + 0x3a8) = *(undefined4 *)(puVar4 + 3);
  puVar4 = (undefined8 *)((longlong)param_1 + 0x7e7);
  if (bVar6) {
    puVar4 = (undefined8 *)&DAT_000007f7;
  }
  uVar1 = puVar4[1];
  *(undefined8 *)(this + 0x3ad) = *puVar4;
  *(undefined8 *)(this + 0x3b5) = uVar1;
  *(undefined8 *)(this + 0x3bd) = puVar4[2];
  *(undefined4 *)(this + 0x3c5) = *(undefined4 *)(puVar4 + 3);
  UpaConnector::DumpState(this);
  local_24 = ~*puVar5;
  local_28 = 4;
  puVar4 = (undefined8 *)((longlong)param_1 + 0x18);
  if (param_1 == (void *)0x0) {
    puVar4 = (undefined8 *)&DAT_00000028;
  }
  this_00 = (UpaCallbacks *)((longlong)param_1 + 0x30);
  local_1c = *puVar4;
  if (param_1 == (void *)0x0) {
    this_00 = (UpaCallbacks *)0x40;
  }
  UpaCallbacks::EvtRequestCallback(this_00,(_USBPM_EVENT_CALLBACK_PARAMS *)&local_28);
  return 5;
}



===== ReportingHubArrivalEntry @ 180006440 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::ReportingHubArrivalEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::ReportingHubArrivalEntry(void *param_1)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  UpaCallbacks *this;
  bool bVar3;
  undefined4 local_28;
  ulonglong local_24;
  undefined8 local_1c;
  
  local_28 = 2;
  puVar1 = (ulonglong *)((longlong)param_1 + 0x11c0);
  bVar3 = param_1 == (void *)0x0;
  if (bVar3) {
    puVar1 = (ulonglong *)&DAT_000011d0;
  }
  local_24 = ~*puVar1;
  puVar2 = (undefined8 *)((longlong)param_1 + 0x18);
  if (bVar3) {
    puVar2 = (undefined8 *)&DAT_00000028;
  }
  this = (UpaCallbacks *)((longlong)param_1 + 0x30);
  local_1c = *puVar2;
  if (bVar3) {
    this = (UpaCallbacks *)0x40;
  }
  UpaCallbacks::EvtRequestCallback(this,(_USBPM_EVENT_CALLBACK_PARAMS *)&local_28);
  return 5;
}



===== ReportingHubRemovalEntry @ 1800064b0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::ReportingHubRemovalEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::ReportingHubRemovalEntry(void *param_1)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  UpaCallbacks *this;
  bool bVar3;
  undefined4 local_28;
  ulonglong local_24;
  undefined8 local_1c;
  
  local_28 = 3;
  puVar1 = (ulonglong *)((longlong)param_1 + 0x11c0);
  bVar3 = param_1 == (void *)0x0;
  if (bVar3) {
    puVar1 = (ulonglong *)&DAT_000011d0;
  }
  local_24 = ~*puVar1;
  puVar2 = (undefined8 *)((longlong)param_1 + 0x18);
  if (bVar3) {
    puVar2 = (undefined8 *)&DAT_00000028;
  }
  this = (UpaCallbacks *)((longlong)param_1 + 0x30);
  local_1c = *puVar2;
  if (bVar3) {
    this = (UpaCallbacks *)0x40;
  }
  UpaCallbacks::EvtRequestCallback(this,(_USBPM_EVENT_CALLBACK_PARAMS *)&local_28);
  return 5;
}



===== ReportingPolicyManagerArrivalEntry @ 180006520 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::ReportingPolicyManagerArrivalEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::ReportingPolicyManagerArrivalEntry(void *param_1)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  UpaCallbacks *this;
  bool bVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 local_1c;
  
  local_20 = 0;
  puVar1 = (undefined4 *)((longlong)param_1 + 0x128);
  local_28 = 0;
  bVar3 = param_1 == (void *)0x0;
  if (bVar3) {
    puVar1 = (undefined4 *)&DAT_00000138;
  }
  local_24 = *puVar1;
  puVar2 = (undefined8 *)((longlong)param_1 + 0x18);
  if (bVar3) {
    puVar2 = (undefined8 *)&DAT_00000028;
  }
  this = (UpaCallbacks *)((longlong)param_1 + 0x30);
  local_1c = *puVar2;
  if (bVar3) {
    this = (UpaCallbacks *)0x40;
  }
  UpaCallbacks::EvtRequestCallback(this,(_USBPM_EVENT_CALLBACK_PARAMS *)&local_28);
  return 5;
}



===== ReportingPolicyManagerRemovalEntry @ 180006590 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::ReportingPolicyManagerRemovalEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::ReportingPolicyManagerRemovalEntry(void *param_1)

{
  undefined8 *puVar1;
  UpaCallbacks *this;
  undefined4 local_28;
  undefined8 local_24;
  undefined8 local_1c;
  
  local_24 = 0;
  puVar1 = (undefined8 *)((longlong)param_1 + 0x18);
  local_28 = 1;
  if (param_1 == (void *)0x0) {
    puVar1 = (undefined8 *)&DAT_00000028;
  }
  this = (UpaCallbacks *)((longlong)param_1 + 0x30);
  local_1c = *puVar1;
  if (param_1 == (void *)0x0) {
    this = (UpaCallbacks *)0x40;
  }
  UpaCallbacks::EvtRequestCallback(this,(_USBPM_EVENT_CALLBACK_PARAMS *)&local_28);
  return 5;
}



===== ReportingStoppedToClientMachineEntry @ 1800065f0 =====

/* public: static unsigned short __cdecl UsbPmApiCallbacksStateMachine<class
   UpaCallbacks>::EntryFuncs::ReportingStoppedToClientMachineEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiCallbacksStateMachine<UpaCallbacks>::EntryFuncs::ReportingStoppedToClientMachineEntry
          (void *param_1)

{
  SmFx::StateMachineEngine::EnqueueEvent
            ((StateMachineEngine *)(*(longlong *)((longlong)param_1 + 8) + 0x10),1);
  return 2;
}



===== SendDeviceIoControlInternal @ 180006618 =====

/* private: void __cdecl UpaClient::SendDeviceIoControlInternal(unsigned long,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long,void (__cdecl*)(void * __ptr64,struct
   _IO_STATUS_BLOCK * __ptr64,unsigned long),void * __ptr64,struct _IO_STATUS_BLOCK * __ptr64)
   __ptr64 */

void __thiscall
UpaClient::SendDeviceIoControlInternal
          (UpaClient *this,ulong param_1,void *param_2,ulong param_3,void *param_4,ulong param_5,
          _func_void_void_ptr__IO_STATUS_BLOCK_ptr_ulong *param_6,void *param_7,
          _IO_STATUS_BLOCK *param_8)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 in_stack_ffffffffffffffd0;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffd0 >> 0x20);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x23,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  iVar1 = NtDeviceIoControlFile
                    (*(undefined8 *)(this + 0x130),0,param_6,param_7,param_8,CONCAT44(uVar3,param_1)
                     ,param_2,param_3,param_4,param_5);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((WPP_GLOBAL_Control[0x1c] & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x19] < 2))
    goto LAB_18000672b;
    uVar2 = 0x24;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((WPP_GLOBAL_Control[0x1c] & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x19] < 4))
    goto LAB_18000672b;
    uVar2 = 0x25;
  }
  WPP_SF_Ldqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,param_6,param_1,(char)iVar1,
              (char)param_7,(char)this);
LAB_18000672b:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x26,
            &WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids);
  }
  return;
}



===== SendingAsyncRequestsToPolicyManagerEntry @ 180006780 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::SendingAsyncRequestsToPolicyManagerEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::SendingAsyncRequestsToPolicyManagerEntry
          (void *param_1)

{
  UpaCollectible *pUVar1;
  undefined8 uVar2;
  UpaCollectible *pUVar3;
  UpaCollection *this;
  UpaCollection *this_00;
  
  this_00 = (UpaCollection *)((longlong)param_1 + 0x208);
  if (param_1 == (void *)0x0) {
    this_00 = (UpaCollection *)0x218;
  }
  pUVar3 = UpaCollection::PopHead(this_00);
  if (pUVar3 != (UpaCollectible *)0x0) {
    this = (UpaCollection *)((longlong)param_1 + 0x260);
    if (param_1 == (void *)0x0) {
      this = (UpaCollection *)0x270;
    }
    do {
      UpaCollection::AddItem(this,pUVar3);
      pUVar1 = pUVar3 + 0x45;
      *(undefined8 *)pUVar1 = 0;
      *(undefined8 *)(pUVar3 + 0x4d) = 0;
      *(undefined4 *)(pUVar3 + 0x55) = 0;
      pUVar3[0x59] = (UpaCollectible)0x0;
      uVar2 = *(undefined8 *)(*(longlong *)(pUVar3 + 0x30) + 0x38);
      *(undefined4 *)(pUVar3 + 0x4d) = *(undefined4 *)(pUVar3 + 0x38);
      *(undefined4 *)(pUVar3 + 0x51) = *(undefined4 *)(pUVar3 + 0x3c);
      pUVar3[0x55] = pUVar3[0x40];
      *(undefined4 *)(pUVar3 + 0x56) = *(undefined4 *)(pUVar3 + 0x41);
      *(undefined8 *)pUVar1 = uVar2;
      UpaClient::SendDeviceIoControlInternal
                (*(UpaClient **)(pUVar3 + 0x28),*(ulong *)(pUVar3 + 0x20),pUVar1,0x15,(void *)0x0,0,
                 UpaAssignPowerLevel::EvtIoCtlCompletedThunk,pUVar3,
                 (_IO_STATUS_BLOCK *)(pUVar3 + 0x68));
      pUVar3 = UpaCollection::PopHead(this_00);
    } while (pUVar3 != (UpaCollectible *)0x0);
  }
  return 5;
}



===== StartingApiCallbacksMachineEntry @ 180006880 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::StartingApiCallbacksMachineEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::StartingApiCallbacksMachineEntry(void *param_1)

{
  StateMachineEngine *this;
  
  this = (StateMachineEngine *)((longlong)param_1 + 0x30);
  if (param_1 == (void *)0x0) {
    this = (StateMachineEngine *)0x40;
  }
  SmFx::StateMachineEngine::EnqueueEvent(this,5);
  return 5;
}



===== StoppingApiCallbacksMachineEntry @ 1800068c0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::StoppingApiCallbacksMachineEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::StoppingApiCallbacksMachineEntry(void *param_1)

{
  StateMachineEngine *this;
  
  this = (StateMachineEngine *)((longlong)param_1 + 0x30);
  if (param_1 == (void *)0x0) {
    this = (StateMachineEngine *)0x40;
  }
  SmFx::StateMachineEngine::EnqueueEvent(this,6);
  return 0;
}



===== TryToClosePolicyManagerDeviceFileHandleEntry @ 180006900 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::TryToClosePolicyManagerDeviceFileHandleEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::TryToClosePolicyManagerDeviceFileHandleEntry
          (void *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)((longlong)param_1 + 0x120);
  if (param_1 == (void *)0x0) {
    plVar1 = (longlong *)&DAT_00000130;
  }
  if (*plVar1 != 0) {
    NtClose();
    *plVar1 = 0;
  }
  return 5;
}



===== UnregisterConnectorsChangeNotifications @ 180006944 =====

/* public: void __cdecl UpaHub::UnregisterConnectorsChangeNotifications(void) __ptr64 */

void __thiscall UpaHub::UnregisterConnectorsChangeNotifications(UpaHub *this)

{
  UpaCollectible *pUVar1;
  ulong uVar2;
  
  uVar2 = 0;
  if (*(int *)(this + 0x268) != 0) {
    do {
      pUVar1 = UpaCollection::GetItemByIndex((UpaCollection *)(this + 0x248),uVar2);
      if (*(longlong *)(pUVar1 + 0x9f8) != 0) {
        UsbPmApip_WnfUnsubscribeChangeNotification((undefined8 *)(pUVar1 + 0x9f8));
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(this + 0x268));
  }
  return;
}



===== UnregisterPolicyManagerDeviceNotificationsEntry @ 1800069b0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::UnregisterPolicyManagerDeviceNotificationsEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::UnregisterPolicyManagerDeviceNotificationsEntry
          (void *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)((longlong)param_1 + 0x108);
  if (param_1 == (void *)0x0) {
    puVar1 = (undefined8 *)&DAT_00000118;
  }
  if ((HCMNOTIFICATION__ *)*puVar1 != (HCMNOTIFICATION__ *)0x0) {
    UsbPmApip_UnregisterCallbacks((HCMNOTIFICATION__ *)*puVar1);
    *puVar1 = 0;
  }
  return 5;
}



===== UnregisteringAllNotificationsExceptPolicyManagerDeviceRemovalEntry @ 1800069f0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::UnregisteringAllNotificationsExceptPolicyManagerDeviceRemovalEntry(void *
   __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::
UnregisteringAllNotificationsExceptPolicyManagerDeviceRemovalEntry(void *param_1)

{
  UpaCollectible *this;
  longlong *plVar1;
  undefined8 *puVar2;
  uint *puVar3;
  UpaCollection *this_00;
  ulong uVar4;
  
  puVar2 = (undefined8 *)((longlong)param_1 + 0xe0);
  uVar4 = 0;
  if (param_1 == (void *)0x0) {
    puVar2 = (undefined8 *)&DAT_000000f0;
  }
  UsbPmApip_UnregisterCallbacks((HCMNOTIFICATION__ *)*puVar2);
  *puVar2 = 0;
  plVar1 = (longlong *)((longlong)param_1 + 0x150);
  if (param_1 == (void *)0x0) {
    plVar1 = (longlong *)&DAT_00000160;
  }
  if (*plVar1 != 0) {
    UsbPmApip_WnfUnsubscribeChangeNotification(plVar1);
  }
  puVar3 = (uint *)((longlong)param_1 + 0x178);
  if (param_1 == (void *)0x0) {
    puVar3 = (uint *)&DAT_00000188;
  }
  if (*puVar3 != 0) {
    this_00 = (UpaCollection *)((longlong)param_1 + 0x158);
    if (param_1 == (void *)0x0) {
      this_00 = (UpaCollection *)0x168;
    }
    do {
      this = UpaCollection::GetItemByIndex(this_00,uVar4);
      UpaHub::UnregisterConnectorsChangeNotifications((UpaHub *)this);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar3);
  }
  return 5;
}



===== UnregisteringConnectorsChangeNotificationsEntry @ 180006ab0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::UnregisteringConnectorsChangeNotificationsEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::UnregisteringConnectorsChangeNotificationsEntry
          (void *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)((longlong)param_1 + 0x11c0);
  if (param_1 == (void *)0x0) {
    puVar1 = (undefined8 *)&DAT_000011d0;
  }
  UpaHub::UnregisterConnectorsChangeNotifications((UpaHub *)*puVar1);
  return 5;
}



===== UnregisteringPolicyManagerInterfaceNotificationsEntry @ 180006af0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::UnregisteringPolicyManagerInterfaceNotificationsEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::
UnregisteringPolicyManagerInterfaceNotificationsEntry(void *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)((longlong)param_1 + 0xe0);
  if (param_1 == (void *)0x0) {
    puVar1 = (undefined8 *)&DAT_000000f0;
  }
  UsbPmApip_UnregisterCallbacks((HCMNOTIFICATION__ *)*puVar1);
  *puVar1 = 0;
  return 5;
}



===== ValidateUpaHandle @ 180006b28 =====

/* public: static bool __cdecl UpaBaseClass::ValidateUpaHandle(void * __ptr64) */

bool __cdecl UpaBaseClass::ValidateUpaHandle(void *param_1)

{
  longlong lVar1;
  ulonglong local_res8 [4];
  
  local_res8[0] = ~(ulonglong)param_1;
  EnterCriticalSection(&GlobalObjectPointerTable::m_Lock);
  lVar1 = RtlLookupElementGenericTable(&GlobalObjectPointerTable::m_Table,local_res8);
  LeaveCriticalSection(&GlobalObjectPointerTable::m_Lock);
  return lVar1 != 0;
}



===== WaitingForPolicyManagerRemoveFinalEntry @ 180006b90 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::WaitingForPolicyManagerRemoveFinalEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::WaitingForPolicyManagerRemoveFinalEntry
          (void *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)((longlong)param_1 + 0x115e);
  if (param_1 == (void *)0x0) {
    puVar1 = &DAT_0000116e;
  }
  *puVar1 = 0;
  return 0;
}



===== WaitingForRequestCompletionEntry @ 180006bb0 =====

/* public: static unsigned short __cdecl UsbPmApiClientStateMachine<class
   UpaClient>::EntryFuncs::WaitingForRequestCompletionEntry(void * __ptr64) */

ushort __cdecl
UsbPmApiClientStateMachine<UpaClient>::EntryFuncs::WaitingForRequestCompletionEntry(void *param_1)

{
  void *pvVar1;
  UpaClient *this;
  
  this = (UpaClient *)(-(ulonglong)(param_1 != (void *)0x0) & (longlong)param_1 - 0x10U);
  if (*(ulong *)(this + 0x328) == 0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = *(void **)(this + 0x380);
  }
  UpaClient::SendDeviceIoControlInternal
            (this,*(ulong *)(this + 800),
             (void *)(-(ulonglong)(*(ulong *)(this + 0x324) != 0) & (ulonglong)(this + 0x368)),
             *(ulong *)(this + 0x324),pvVar1,*(ulong *)(this + 0x328),
             *(_func_void_void_ptr__IO_STATUS_BLOCK_ptr_ulong **)(this + 0x330),
             *(void **)(this + 0x338),*(_IO_STATUS_BLOCK **)(this + 0x340));
  return 0;
}



===== WnfCallback @ 180006c60 =====

/* private: static long __cdecl UpaConnector::WnfCallback(struct _WNF_STATE_NAME const *
   __ptr64,unsigned long,void * __ptr64,void const * __ptr64,unsigned long) */

long __cdecl
UpaConnector::WnfCallback
          (_WNF_STATE_NAME *param_1,ulong param_2,void *param_3,void *param_4,ulong param_5)

{
  longlong lVar1;
  void *pvVar2;
  
  pvVar2 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_iiq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x48,param_3,
               *(undefined8 *)((longlong)param_3 + 0x38),
               (char)*(undefined8 *)((longlong)param_3 + 0x40),
               (char)*(undefined8 *)((longlong)param_3 + 0x20));
  }
  if (*(char *)((longlong)param_3 + 0xa28) == '\0') {
    lVar1 = *(longlong *)((longlong)param_3 + 0x20);
    *(undefined1 *)((longlong)param_3 + 0xa28) = 1;
    UpaCollection::AddItem
              ((UpaCollection *)(lVar1 + 0x1c0),(UpaCollectible *)((longlong)param_3 + 0xa00));
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(lVar1 + 0x10),3);
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_iiq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x49,pvVar2,
               *(undefined8 *)((longlong)param_3 + 0x38),
               (char)*(undefined8 *)((longlong)param_3 + 0x40),
               (char)*(undefined8 *)((longlong)param_3 + 0x20));
  }
  return 0;
}



===== WPP_SF_DDiq @ 180006d38 =====

void WPP_SF_DDiq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x28,local_res20,4,
               &param_5,4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_Ddiq @ 180006dac =====

void WPP_SF_Ddiq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x27,local_res20,4,
               &param_5,4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_Dq @ 180006e20 =====

void WPP_SF_Dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,10,local_res20,4,
               &param_5,8,0);
  return;
}



===== WPP_SF_LLLLq @ 180006e7c =====

void WPP_SF_LLLLq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_2,local_res20,4,
               &param_5,4,&param_6,4,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_SF_LLLq @ 180006f00 =====

void WPP_SF_LLLq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_2,local_res20,4,
               &param_5,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_LLq @ 180006f74 =====

void WPP_SF_LLq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_2,local_res20,4,
               &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_Ldq @ 180006fdc =====

void WPP_SF_Ldq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined4 local_18 [6];
  
  local_18[0] = 0xc000009a;
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x38,local_res20,4,
               local_18,4,&param_6,8,0);
  return;
}



===== WPP_SF_Ldqq @ 18000704c =====

void WPP_SF_Ldqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_2,local_res20,4,
               &param_5,4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_Lq @ 1800070c0 =====

void WPP_SF_Lq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_2,local_res20,4,
               &param_5,8,0);
  return;
}



===== WPP_SF_Lqq @ 180007118 =====

void WPP_SF_Lqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x22,local_res20,4,
               &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_Sq @ 180007180 =====

void WPP_SF_Sq(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_2,param_4,lVar1,
               &param_5,8,0);
  return;
}



===== WPP_SF_dDLq @ 180007204 =====

void WPP_SF_dDLq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x51,local_res20,4,
               &param_5,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_dddddddDq @ 180007278 =====

void WPP_SF_dddddddDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                     undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x5b,local_res20,4,
               &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,
               &param_12,8,0);
  return;
}



===== WPP_SF_dqq @ 180007330 =====

void WPP_SF_dqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_2,local_res20,4,
               &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_iiDq @ 180007398 =====

void WPP_SF_iiDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x50,&local_res20,8,
               &param_5,8,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_iiiDq @ 18000740c =====

void WPP_SF_iiiDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x12,&local_res20,8,
               &param_5,8,&param_6,8,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_SF_iiiq @ 180007490 =====

void WPP_SF_iiiq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x4c,&local_res20,8,
               &param_5,8,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_iiq @ 180007500 =====

void WPP_SF_iiq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_2,&local_res20,8,
               &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qiLLdq @ 180007564 =====

void WPP_SF_qiLLdq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x4a,&local_res20,8,
               &param_5,8,&param_6,4,&param_7,4,&param_8,4,&param_9,8,0);
  return;
}



===== WPP_SF_qiLLq @ 1800075f4 =====

void WPP_SF_qiLLq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x4b,&local_res20,8,
               &param_5,8,&param_6,4,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_SF_ssdDq @ 180007678 =====

void WPP_SF_ssdDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                 char *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_5[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x5a,param_4,lVar1,
               param_5,lVar3,&param_6,4,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_SF_ssdddDq @ 180007760 =====

void WPP_SF_ssdddDq(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
                   char *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_5[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,param_2,param_4,lVar1,
               param_5,lVar3,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,8,0);
  return;
}



===== WPP_SF_ssddddddddDq @ 180007880 =====

void WPP_SF_ssddddddddDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                        char *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                        undefined1 param_9,undefined1 param_10,undefined1 param_11,
                        undefined1 param_12,undefined1 param_13,undefined1 param_14,
                        undefined1 param_15)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_5[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  TraceMessage(param_1,0x2b,&WPP_8a1ad8facc4e37534e99c2056b1baa11_Traceguids,0x54,param_4,lVar1,
               param_5,lVar3,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,
               &param_12,4,&param_13,4,&param_14,4,&param_15,8,0);
  return;
}



===== DllMain @ 180007a0c =====

undefined8 DllMain(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    DeleteCriticalSection(&GlobalObjectPointerTable::m_Lock);
  }
  else if (param_2 == 1) {
    InitializeCriticalSection(&GlobalObjectPointerTable::m_Lock);
    RtlInitializeGenericTable
              (&GlobalObjectPointerTable::m_Table,
               GlobalObjectPointerTable::GenericTableCompareRoutine,
               GlobalObjectPointerTable::GenericTableAllocateRoutine,
               GlobalObjectPointerTable::GenericTableFreeRoutine,0);
  }
  return 1;
}



===== ~UpaHelperEvent @ 180007a80 =====

/* public: __cdecl UpaHelperEvent::~UpaHelperEvent(void) __ptr64 */

void __thiscall UpaHelperEvent::~UpaHelperEvent(UpaHelperEvent *this)

{
  if (*(HANDLE *)this != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)this);
    *(undefined8 *)this = 0;
  }
  return;
}



===== Initialize @ 180007ab0 =====

/* public: long __cdecl UpaHelperEvent::Initialize(unsigned char) __ptr64 */

long __thiscall UpaHelperEvent::Initialize(UpaHelperEvent *this,uchar param_1)

{
  DWORD DVar1;
  uint uVar2;
  HANDLE pvVar3;
  
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  *(HANDLE *)this = pvVar3;
  if (pvVar3 == (HANDLE)0x0) {
    DVar1 = GetLastError();
    if ((int)DVar1 < 1) {
                    /* WARNING: Could not recover jumptable at 0x000180007aee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      DVar1 = GetLastError();
      return DVar1;
    }
    DVar1 = GetLastError();
    uVar2 = DVar1 & 0xffff | 0xc0070000;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== UsbPmApip_CheckUserToken @ 180007b20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl UsbPmApip_CheckUserToken(void) */

uchar __cdecl UsbPmApip_CheckUserToken(void)

{
  BOOL BVar1;
  undefined1 auStackY_98 [32];
  BOOL local_38 [2];
  PSID local_30;
  PSID local_28;
  _SID_IDENTIFIER_AUTHORITY local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_20.Value[4] = '\0';
  local_20.Value[5] = '\x05';
  local_20.Value[0] = '\0';
  local_20.Value[1] = '\0';
  local_20.Value[2] = '\0';
  local_20.Value[3] = '\0';
  local_28 = (PSID)0x0;
  local_30 = (PSID)0x0;
  BVar1 = AllocateAndInitializeSid(&local_20,'\x02',0x12,0,0,0,0,0,0,0,&local_28);
  if (BVar1 != 0) {
    BVar1 = AllocateAndInitializeSid(&local_20,'\x06',0x54,0,0,0,0,0,0,0,&local_30);
    if (BVar1 != 0) {
      local_38[0] = 0;
      CheckTokenMembership((HANDLE)0x0,local_28,local_38);
      if (local_38[0] == 0) {
        CheckTokenMembership((HANDLE)0x0,local_30,local_38);
      }
      goto LAB_180007c08;
    }
  }
  local_38[0] = 0;
LAB_180007c08:
  if (local_30 != (PSID)0x0) {
    FreeSid(local_30);
  }
  if (local_28 != (PSID)0x0) {
    FreeSid(local_28);
  }
  return local_38[0] != 0;
}



===== UsbPmApip_PnpDeviceInterfaceChangeCallback @ 180007c60 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* unsigned long __cdecl UsbPmApip_PnpDeviceInterfaceChangeCallback(struct HCMNOTIFICATION__ *
   __ptr64,void * __ptr64,enum _CM_NOTIFY_ACTION,struct _CM_NOTIFY_EVENT_DATA * __ptr64,unsigned
   long) */

ulong __cdecl
UsbPmApip_PnpDeviceInterfaceChangeCallback
          (HCMNOTIFICATION__ *param_1,void *param_2,_CM_NOTIFY_ACTION param_3,
          _CM_NOTIFY_EVENT_DATA *param_4,ulong param_5)

{
  undefined4 in_register_00000084;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  if (param_3 == 0) {
    RtlInitUnicodeString(&local_18,param_4 + 0x18);
    (**(code **)((longlong)param_2 + 0x10))(&local_18,*(undefined8 *)((longlong)param_2 + 0x18));
  }
  else if (param_3 == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,CONCAT44(in_register_00000084,1),
               (wchar_t *)(param_4 + 0x18));
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x13,CONCAT44(in_register_00000084,param_3),
             param_3);
  }
  return 0;
}



===== UsbPmApip_PnpTargetDeviceChangeCallback @ 180007d20 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* unsigned long __cdecl UsbPmApip_PnpTargetDeviceChangeCallback(struct HCMNOTIFICATION__ *
   __ptr64,void * __ptr64,enum _CM_NOTIFY_ACTION,struct _CM_NOTIFY_EVENT_DATA * __ptr64,unsigned
   long) */

ulong __cdecl
UsbPmApip_PnpTargetDeviceChangeCallback
          (HCMNOTIFICATION__ *param_1,void *param_2,_CM_NOTIFY_ACTION param_3,
          _CM_NOTIFY_EVENT_DATA *param_4,ulong param_5)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined4 in_register_00000084;
  
  if (param_3 == 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x14,
              &WPP_a90f6ff0477e33f2b7f005f636985b14_Traceguids);
    }
    pcVar1 = *(code **)((longlong)param_2 + 8);
    goto LAB_180007e45;
  }
  if (param_3 == 3) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar2 = 0x15;
      goto LAB_180007da8;
    }
  }
  else if (param_3 == 4) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar2 = 0x16;
      goto LAB_180007da8;
    }
  }
  else {
    if (param_3 != 5) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x19] < 3) {
        return 0;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_2,
               CONCAT44(in_register_00000084,param_3),param_3);
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x19])) {
      uVar2 = 0x17;
LAB_180007da8:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,
              &WPP_a90f6ff0477e33f2b7f005f636985b14_Traceguids);
    }
  }
  pcVar1 = *(code **)((longlong)param_2 + 0x10);
LAB_180007e45:
  (*pcVar1)(*(undefined8 *)((longlong)param_2 + 0x18));
  return 0;
}



===== UsbPmApip_RegisterDeviceRemovalCallbacks @ 180007e60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl UsbPmApip_RegisterDeviceRemovalCallbacks(struct
   _USBPMAPIP_DEVICE_REMOVAL_CALLBACK_CONFIG * __ptr64) */

long __cdecl
UsbPmApip_RegisterDeviceRemovalCallbacks(_USBPMAPIP_DEVICE_REMOVAL_CALLBACK_CONFIG *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined1 auStack_1e8 [32];
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined1 local_1a0 [392];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1e8;
  uVar4 = 0;
  memset(local_1a0,0,0x188);
  local_1a8 = *(undefined8 *)param_1;
  pcVar5 = UsbPmApip_PnpTargetDeviceChangeCallback;
  local_1b8 = 0x1a0;
  local_1b0 = 1;
  iVar2 = CM_Register_Notification
                    (&local_1b8,param_1,UsbPmApip_PnpTargetDeviceChangeCallback,param_1 + 0x20);
  if (iVar2 != 0) {
    iVar3 = CM_MapCrToWin32Err(iVar2,2);
    if (iVar3 < 1) {
      uVar4 = CM_MapCrToWin32Err();
    }
    else {
      uVar1 = CM_MapCrToWin32Err(iVar2,2);
      uVar4 = uVar1 | 0xc0070000;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xe,pcVar5,iVar2,(char)uVar4);
    }
  }
  return uVar4;
}



===== UsbPmApip_RegisterInterfaceArrivalCallbacks @ 180007f74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* long __cdecl UsbPmApip_RegisterInterfaceArrivalCallbacks(struct
   _USBPMAPIP_INTERFACE_ARRIVAL_CALLBACK_CONFIG * __ptr64) */

long __cdecl
UsbPmApip_RegisterInterfaceArrivalCallbacks(_USBPMAPIP_INTERFACE_ARRIVAL_CALLBACK_CONFIG *param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  HANDLE pvVar7;
  short *lpMem;
  undefined2 uVar8;
  short *psVar9;
  code *dwBytes;
  undefined8 uVar10;
  undefined1 auStack_218 [32];
  uint local_1e8 [2];
  ulonglong local_1e0 [3];
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_218;
  memset(&local_1b8,0,400);
  local_1e8[0] = 1;
  local_1e0[0] = 0;
  local_1e0[1] = 0;
  uVar5 = 0;
  local_1b8 = *(undefined4 *)param_1;
  uStack_1b4 = *(undefined4 *)(param_1 + 4);
  uStack_1b0 = *(undefined4 *)(param_1 + 8);
  uStack_1ac = *(undefined4 *)(param_1 + 0xc);
  dwBytes = UsbPmApip_PnpDeviceInterfaceChangeCallback;
  local_1c8 = 0x1a0;
  local_1c0 = 0;
  uVar3 = CM_Register_Notification
                    (&local_1c8,param_1,UsbPmApip_PnpDeviceInterfaceChangeCallback,param_1 + 0x20);
  if (uVar3 == 0) {
    uVar10 = 0;
    iVar4 = CM_Get_Device_Interface_List_SizeW(local_1e8,param_1,0,0);
    if ((iVar4 != 0) || (local_1e8[0] < 2)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x19] < 4) {
        return 0;
      }
      iVar6 = CM_MapCrToWin32Err(iVar4,2);
      if (iVar6 < 1) {
        uVar1 = CM_MapCrToWin32Err();
      }
      else {
        uVar1 = CM_MapCrToWin32Err(iVar4,2);
      }
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,uVar10,iVar4,uVar1);
      return 0;
    }
    dwBytes = (code *)((ulonglong)local_1e8[0] * 2);
    pvVar7 = GetProcessHeap();
    lpMem = HeapAlloc(pvVar7,8,(SIZE_T)dwBytes);
    if (lpMem != (short *)0x0) {
      psVar9 = lpMem;
      iVar4 = CM_Get_Device_Interface_ListW(param_1,0,lpMem,local_1e8[0]);
      if (iVar4 == 0) {
        psVar9 = lpMem;
        if (*lpMem != 0) {
          while (psVar9 < lpMem + local_1e8[0]) {
            RtlInitUnicodeString(local_1e0,psVar9);
            iVar4 = (**(code **)(param_1 + 0x10))(local_1e0,*(undefined8 *)(param_1 + 0x18));
            if ((-1 < iVar4) || (psVar9 = psVar9 + (local_1e0[0] >> 0x11 & 0x7fff), *psVar9 == 0))
            break;
          }
        }
      }
      else {
        iVar6 = CM_MapCrToWin32Err(iVar4,2);
        if (iVar6 < 1) {
          uVar5 = CM_MapCrToWin32Err();
        }
        else {
          uVar2 = CM_MapCrToWin32Err(iVar4,2);
          uVar5 = uVar2 | 0xc0070000;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x19])) {
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,psVar9,iVar4,(char)uVar5);
        }
      }
      pvVar7 = GetProcessHeap();
      HeapFree(pvVar7,0,lpMem);
      return uVar5;
    }
    uVar5 = 0xc000009a;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff66;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return -0x3fffff66;
    }
    if ((byte)WPP_GLOBAL_Control[0x19] < 2) {
      return -0x3fffff66;
    }
    uVar8 = 0xc;
    uVar3 = local_1e8[0];
  }
  else {
    iVar4 = CM_MapCrToWin32Err(uVar3,2);
    if (iVar4 < 1) {
      uVar5 = CM_MapCrToWin32Err();
    }
    else {
      uVar2 = CM_MapCrToWin32Err(uVar3,2);
      uVar5 = uVar2 | 0xc0070000;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar5;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return uVar5;
    }
    if ((byte)WPP_GLOBAL_Control[0x19] < 2) {
      return uVar5;
    }
    uVar8 = 10;
  }
  WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar8,dwBytes,uVar3,(char)uVar5);
  return uVar5;
}



===== UsbPmApip_UnregisterCallbacks @ 1800082f0 =====

/* long __cdecl UsbPmApip_UnregisterCallbacks(struct HCMNOTIFICATION__ * __ptr64) */

long __cdecl UsbPmApip_UnregisterCallbacks(HCMNOTIFICATION__ *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined *in_R8;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    in_R8 = &WPP_a90f6ff0477e33f2b7f005f636985b14_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xf,
            &WPP_a90f6ff0477e33f2b7f005f636985b14_Traceguids);
  }
  uVar4 = 0;
  if (param_1 != (HCMNOTIFICATION__ *)0x0) {
    iVar2 = CM_Unregister_Notification(param_1);
    uVar4 = 0;
    if (iVar2 != 0) {
      iVar3 = CM_MapCrToWin32Err(iVar2,6);
      if (iVar3 < 1) {
        uVar4 = CM_MapCrToWin32Err();
      }
      else {
        uVar1 = CM_MapCrToWin32Err(iVar2,6);
        uVar4 = uVar1 | 0xc0070000;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar4;
      }
      if (((WPP_GLOBAL_Control[0x1c] & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x10,in_R8,uVar4);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x19])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x11,
            &WPP_a90f6ff0477e33f2b7f005f636985b14_Traceguids);
  }
  return uVar4;
}



===== Wait @ 18000840c =====

/* public: enum UpaHelperEvent::WaitResult __cdecl UpaHelperEvent::Wait(unsigned long) __ptr64 */

WaitResult __thiscall UpaHelperEvent::Wait(UpaHelperEvent *this,ulong param_1)

{
  DWORD DVar1;
  WaitResult WVar2;
  
  do {
    DVar1 = WaitForSingleObjectEx(*(HANDLE *)this,0xffffffff,1);
    if (DVar1 == 0) {
      return 0;
    }
  } while (DVar1 == 0xc0);
  if (DVar1 == 0x102) {
    WVar2 = 1;
  }
  else {
    WVar2 = 2;
  }
  return WVar2;
}



===== WPP_SF_D @ 18000845c =====

void WPP_SF_D(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_a90f6ff0477e33f2b7f005f636985b14_Traceguids,0x18,local_res20,4,0);
  return;
}



===== WPP_SF_dd @ 1800084a8 =====

void WPP_SF_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_a90f6ff0477e33f2b7f005f636985b14_Traceguids,param_2,local_res20,4,
               &param_5,4,0);
  return;
}



===== WPP_SF_S @ 180008500 =====

void WPP_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  TraceMessage(param_1,0x2b,&WPP_a90f6ff0477e33f2b7f005f636985b14_Traceguids,0x12,param_4,lVar1,0);
  return;
}



===== WPP_SF_d @ 180008574 =====

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,&WPP_a90f6ff0477e33f2b7f005f636985b14_Traceguids,param_2,local_res20,4,0
              );
  return;
}



===== EnqueueEvent @ 1800085bc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl SmFx::StateMachineEngine::EnqueueEvent(unsigned short) __ptr64 */

void __thiscall SmFx::StateMachineEngine::EnqueueEvent(StateMachineEngine *this,ushort param_1)

{
  StateMachineEngineImpl *this_00;
  bool bVar1;
  DWORD DVar2;
  undefined2 uVar3;
  bool bVar4;
  
  this_00 = *(StateMachineEngineImpl **)this;
  EnterCriticalSection((LPCRITICAL_SECTION)(this_00 + 0x3d0));
  if (*(int *)(this_00 + 0x3cc) == 5) {
    if (param_1 == *(ushort *)(this_00 + 0x370)) {
      if (*(code **)(this_00 + 0x390) != (code *)0x0) {
        if (param_1 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(undefined2 *)
                   (*(longlong *)(*(longlong *)(this_00 + 0x378) + 0x10) + (ulonglong)param_1 * 4);
        }
        (**(code **)(this_00 + 0x390))(*(undefined8 *)(this_00 + 0x380),uVar3);
      }
      *(undefined2 *)(this_00 + 0x370) = 0;
      goto LAB_18000864b;
    }
    bVar4 = false;
  }
  else {
    bVar4 = *(int *)(this_00 + 0x3cc) == 1;
  }
  bVar1 = StateMachineEngineImpl::EnqueueEventWithDisposition(this_00,param_1);
  if (!bVar1) {
    return;
  }
  if (!bVar4) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(this_00 + 0x3d0));
    return;
  }
LAB_18000864b:
  *(undefined2 *)(this_00 + 0x3c6) = 0;
  DVar2 = GetCurrentThreadId();
  *(DWORD *)(this_00 + 0x3c8) = DVar2;
  StateMachineEngineImpl::ProcessEventQueue(this_00);
  return;
}



===== Initialize @ 1800086bc =====

/* public: long __cdecl SmFx::StateMachineEngine::Initialize(struct
   SmFx::STATE_MACHINE_ENGINE_CONFIG const & __ptr64) __ptr64 */

long __thiscall
SmFx::StateMachineEngine::Initialize(StateMachineEngine *this,STATE_MACHINE_ENGINE_CONFIG *param_1)

{
  long lVar1;
  HANDLE hHeap;
  StateMachineEngineImpl *this_00;
  
  hHeap = GetProcessHeap();
  this_00 = HeapAlloc(hHeap,0,0x420);
  if (this_00 == (StateMachineEngineImpl *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    memset(this_00,0,0x420);
    *(undefined2 *)(this_00 + 0x3c5) = 0x101;
    this_00[0x3c7] = (StateMachineEngineImpl)0x2;
    *(undefined8 *)(this_00 + 0x408) = 0;
    *(undefined8 *)(this_00 + 0x410) = 0;
    *(StateMachineEngineImpl **)this = this_00;
    *(StateMachineEngine **)(this_00 + 0x418) = this;
    lVar1 = StateMachineEngineImpl::Initialize(this_00,param_1);
    if (lVar1 < 0) {
      StateMachineEngineImpl::Destroy(this_00);
      *(undefined8 *)this = 0;
    }
    else {
      lVar1 = 0;
    }
  }
  return lVar1;
}



===== <lambda_invoker_cdecl> @ 180008780 =====

void <lambda_c276094d149607b901f7fae525da7e78>::<lambda_invoker_cdecl>
               (StateMachineEngineImpl *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  EngineState EVar4;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x3d0);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = *(int *)(param_1 + 0x3cc);
  *(undefined4 *)(param_1 + 0x3cc) = 2;
  LeaveCriticalSection(lpCriticalSection);
  *(undefined2 *)(param_1 + 0x3c6) = 1;
  DVar2 = GetCurrentThreadId();
  *(DWORD *)(param_1 + 0x3c8) = DVar2;
  if (iVar1 == 3) {
    SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction
              (param_1,(EVENT_ACTION *)(param_1 + 0x3b0));
    uVar3 = Feature_SMST__private_IsEnabledDeviceUsageNoInline();
    if (uVar3 != 0) {
      *(undefined8 *)(param_1 + 0x3b0) = 0;
      *(undefined8 *)(param_1 + 0x3b8) = 0;
      EVar4 = SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(param_1);
      EnterCriticalSection(lpCriticalSection);
      if (EVar4 != 1) {
        SmFx::StateMachineEngine::StateMachineEngineImpl::UpdateEngineState(param_1,EVar4);
        return;
      }
      goto LAB_18000886e;
    }
    SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(param_1);
  }
  else {
    if (iVar1 != 4) {
      return;
    }
    SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction
              (param_1,(EVENT_ACTION *)(param_1 + 0x3b0));
    *(undefined8 *)(param_1 + 0x3b0) = 0;
    *(undefined8 *)(param_1 + 0x3b8) = 0;
  }
  EnterCriticalSection(lpCriticalSection);
LAB_18000886e:
  SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(param_1);
  return;
}



===== ~StateMachineEngineImpl @ 18000888c =====

/* private: __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::~StateMachineEngineImpl(void)
   __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::~StateMachineEngineImpl
          (StateMachineEngineImpl *this)

{
  LPCRITICAL_SECTION lpCriticalSection;
  Worker *this_00;
  LPVOID lpMem;
  HANDLE hHeap;
  
  **(undefined8 **)(this + 0x418) = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(this + 0x3d0);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(this + 0x3cc) = 0;
  LeaveCriticalSection(lpCriticalSection);
  this_00 = (Worker *)(this + 0x400);
  if (*(PTP_WORK *)this_00 != (PTP_WORK)0x0) {
    CloseThreadpoolWork(*(PTP_WORK *)this_00);
    *(undefined8 *)this_00 = 0;
    *(undefined8 *)(this + 0x408) = 0;
    *(undefined8 *)(this + 0x410) = 0;
  }
  lpMem = *(LPVOID *)(this + 0x368);
  if (lpMem != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
    *(undefined8 *)(this + 0x368) = 0;
  }
  if (this[0x3f8] != (StateMachineEngineImpl)0x0) {
    DeleteCriticalSection(lpCriticalSection);
    this[0x3f8] = (StateMachineEngineImpl)0x0;
  }
  Worker::~Worker(this_00);
  SpinLock::~SpinLock((SpinLock *)lpCriticalSection);
  return;
}



===== AddEventToEventQueue @ 18000897c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: bool __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::AddEventToEventQueue(unsigned short) __ptr64 */

bool __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::AddEventToEventQueue
          (StateMachineEngineImpl *this,ushort param_1)

{
  bool bVar1;
  undefined2 uVar2;
  StateMachineEngineImpl SVar3;
  
  SVar3 = (StateMachineEngineImpl)((char)this[0x3c3] + 1U & 0xf);
  if (SVar3 == this[0x3c2]) {
    ReportExceptionWithLockHeld(this,2,param_1,0);
    bVar1 = false;
  }
  else {
    *(ushort *)(this + (ulonglong)(byte)this[0x3c3] * 2 + 0x340) = param_1;
    uVar2 = 0;
    this[0x3c3] = SVar3;
    if (*(code **)(this + 0x390) != (code *)0x0) {
      if (param_1 != 0) {
        uVar2 = *(undefined2 *)
                 (*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + (ulonglong)param_1 * 4);
      }
      (**(code **)(this + 0x390))(*(undefined8 *)(this + 0x380),uVar2);
    }
    bVar1 = true;
  }
  return bVar1;
}



===== Destroy @ 180008a08 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::Destroy(void) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::Destroy(StateMachineEngineImpl *this)

{
  code *pcVar1;
  undefined8 uVar2;
  HANDLE hHeap;
  
  pcVar1 = *(code **)(this + 0x3a0);
  uVar2 = *(undefined8 *)(this + 0x380);
  ~StateMachineEngineImpl(this);
  hHeap = GetProcessHeap();
  HeapFree(hHeap,0,this);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(uVar2);
  }
  return;
}



===== EnqueueEventWithDisposition @ 180008a74 =====

/* private: bool __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::EnqueueEventWithDisposition(unsigned short)
   __ptr64 */

bool __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::EnqueueEventWithDisposition
          (StateMachineEngineImpl *this,ushort param_1)

{
  char cVar1;
  bool bVar2;
  ulonglong uVar3;
  StateMachineEngineImpl SVar4;
  StateMachineEngineImpl SVar5;
  
  cVar1 = *(char *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + 2 + (ulonglong)param_1 * 4);
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      SVar5 = this[0x3c2];
      bVar2 = false;
      SVar4 = SVar5;
      if (SVar5 != this[0x3c3]) {
        do {
          if (*(ushort *)(this + (ulonglong)(byte)SVar4 * 2 + 0x340) == param_1) {
            bVar2 = true;
          }
          else {
            uVar3 = (ulonglong)(byte)SVar5;
            SVar5 = (StateMachineEngineImpl)((char)SVar5 + 1U & 0xf);
            *(ushort *)(this + uVar3 * 2 + 0x340) =
                 *(ushort *)(this + (ulonglong)(byte)SVar4 * 2 + 0x340);
          }
          SVar4 = (StateMachineEngineImpl)((char)SVar4 + 1U & 0xf);
        } while (SVar4 != this[0x3c3]);
        if (bVar2) {
          *(ushort *)(this + (ulonglong)((byte)((char)this[0x3c3] - 1) & 0xf) * 2 + 0x340) = param_1
          ;
          goto LAB_180008b38;
        }
      }
    }
    else {
      if (cVar1 != '\x03') {
LAB_180008b38:
        LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
        return false;
      }
      for (SVar5 = this[0x3c2]; SVar5 != this[0x3c3];
          SVar5 = (StateMachineEngineImpl)((char)SVar5 + 1U & 0xf)) {
        if (*(ushort *)(this + (ulonglong)(byte)SVar5 * 2 + 0x340) == param_1) goto LAB_180008b38;
      }
    }
  }
  bVar2 = AddEventToEventQueue(this,param_1);
  return bVar2;
}



===== ExecuteCurrentState @ 180008b5c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(void) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(StateMachineEngineImpl *this)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  EngineState EVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  EVENT_ACTION *pEVar8;
  StateMachineEngineImpl SVar9;
  StateMachineEngineImpl SVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  do {
    uVar2 = 0;
    if (this[0x3c4] != (StateMachineEngineImpl)0x0) {
      uVar2 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2);
    }
    lVar5 = *(longlong *)(this + 0x378);
    lVar11 = (ulonglong)uVar2 * 0x10 + *(longlong *)(lVar5 + 0x18);
    if ((*(byte *)(lVar11 + 4) & 1) == 0) {
      if (*(char *)(lVar11 + 3) == '\x01') {
        uVar12 = (ulonglong)*(ushort *)(lVar5 + 2);
      }
      else {
        uVar12 = 0;
      }
    }
    else {
      uVar2 = (*(code *)**(undefined8 **)(lVar11 + 8))(*(undefined8 *)(this + 0x380));
      lVar5 = *(longlong *)(this + 0x378);
      uVar12 = (ulonglong)uVar2;
    }
    if (this[0x3c4] == (StateMachineEngineImpl)0x0) {
      uVar13 = 0;
    }
    else {
      uVar13 = (ulonglong)
               *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2);
    }
    lVar5 = uVar13 * 0x10 + *(longlong *)(lVar5 + 0x18);
    uVar2 = *(ushort *)(lVar5 + 4);
    if ((uVar2 & 0x20) != 0) {
      uVar3 = 1;
      uVar7 = 0;
      do {
        uVar6 = (ulonglong)((int)uVar7 + 1);
        if ((uVar2 & uVar3) != uVar3) {
          uVar6 = uVar7;
        }
        uVar3 = uVar3 * 2;
        uVar7 = uVar6;
      } while (uVar3 != 0x20);
      puVar1 = *(ushort **)(*(longlong *)(lVar5 + 8) + uVar6 * 8);
      if (puVar1 != (ushort *)0x0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
        SVar9 = this[0x3c2];
        SVar10 = SVar9;
        if (SVar9 != this[0x3c3]) {
          do {
            lVar5 = 0;
            uVar2 = *(ushort *)(this + (ulonglong)(byte)SVar10 * 2 + 0x340);
            uVar3 = *puVar1;
            while (uVar3 != 0) {
              if (uVar3 == uVar2) {
                LogTransition(this,7,(ushort)uVar13,uVar2,0,(char)this[0x3c4] + 0xff);
                goto LAB_180008cbb;
              }
              lVar5 = lVar5 + 1;
              uVar3 = puVar1[lVar5];
            }
            uVar7 = (ulonglong)(byte)SVar9;
            SVar9 = (StateMachineEngineImpl)((char)SVar9 + 1U & 0xf);
            *(ushort *)(this + uVar7 * 2 + 0x340) = uVar2;
LAB_180008cbb:
            SVar10 = (StateMachineEngineImpl)((char)SVar10 + 1U & 0xf);
          } while (SVar10 != this[0x3c3]);
        }
        this[0x3c3] = SVar9;
        LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
      }
    }
    if (*(char *)(lVar11 + 3) == '\x01') {
      local_38 = 0;
      uStack_30 = 0;
      FindActionForEvent(this,(ushort)uVar12,(EVENT_ACTION *)&local_38);
      pEVar8 = (EVENT_ACTION *)&local_38;
    }
    else {
      if (*(char *)(lVar11 + 3) != '\x03') {
        return 1;
      }
      local_48 = 6;
      local_40 = *(longlong *)(*(longlong *)(this + 0x378) + 8) +
                 (ulonglong)*(byte *)(lVar11 + 6) * 2;
      pEVar8 = (EVENT_ACTION *)&local_48;
    }
    EVar4 = ExecuteEventAction(this,pEVar8);
    if (EVar4 != 2) {
      return EVar4;
    }
  } while( true );
}



===== ExecuteEventAction @ 180008da0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction(struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION const & __ptr64) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction
          (StateMachineEngineImpl *this,EVENT_ACTION *param_1)

{
  StateMachineEngineImpl SVar1;
  longlong lVar2;
  undefined8 uVar3;
  EngineState EVar4;
  MachineException MVar5;
  ushort uVar6;
  int iVar7;
  ushort uVar8;
  undefined8 local_28;
  longlong lStack_20;
  
  iVar7 = *(int *)param_1;
  if (iVar7 == 1) {
    uVar8 = 0;
    if (this[0x3c4] != (StateMachineEngineImpl)0x0) {
      uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2);
    }
    uVar6 = *(ushort *)(param_1 + 4);
    MVar5 = 1;
LAB_180009180:
    ReportException(this,MVar5,uVar6,uVar8);
    return 1;
  }
  if (iVar7 == 2) {
    EVar4 = PopToStackDepth(this,param_1);
    if (EVar4 != 1) {
      return EVar4;
    }
    EVar4 = ExitCurrentState(this,param_1);
    if (EVar4 != 1) {
      return EVar4;
    }
    uVar8 = *(ushort *)(*(longlong *)(param_1 + 8) + 2);
    if ((((*(byte *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + 2 + (ulonglong)uVar8 * 0x10
                    ) & 2) == 0) || (this[0x3c6] != (StateMachineEngineImpl)0x0)) &&
       (((*(byte *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + 2 + (ulonglong)uVar8 * 0x10)
         & 1) == 0 || (this[0x3c7] == (StateMachineEngineImpl)0x0)))) {
      if (this[0x3c4] == (StateMachineEngineImpl)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2);
      }
      LogTransition(this,1,uVar6,*(ushort *)(param_1 + 4),uVar8,(uchar)param_1[6]);
      *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2) = uVar8;
LAB_180009147:
      this[0x3c5] = (StateMachineEngineImpl)0x0;
      return 2;
    }
  }
  else {
    if (iVar7 == 3) {
      lVar2 = *(longlong *)(param_1 + 8);
      uVar8 = 0;
      if (*(longlong *)(lVar2 + 8) == 0) {
        if (this[0x3c4] != (StateMachineEngineImpl)0x0) {
          uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2);
        }
        LogTransition(this,6,uVar8,*(ushort *)(param_1 + 4),
                      *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)param_1[6] * 2),
                      (uchar)param_1[6]);
        return 1;
      }
      if ((((*(byte *)(lVar2 + 2) & 2) == 0) || (this[0x3c6] != (StateMachineEngineImpl)0x0)) &&
         (((*(byte *)(lVar2 + 2) & 1) == 0 || (this[0x3c7] == (StateMachineEngineImpl)0x0)))) {
        if (this[0x3c4] != (StateMachineEngineImpl)0x0) {
          uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2);
        }
        LogTransition(this,2,uVar8,*(ushort *)(param_1 + 4),
                      *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)param_1[6] * 2),
                      (uchar)param_1[6]);
        (**(code **)(*(longlong *)(param_1 + 8) + 8))(*(undefined8 *)(this + 0x380));
        return 1;
      }
      EVar4 = 4;
      goto LAB_1800090e4;
    }
    if (iVar7 == 4) {
      local_28 = *(undefined8 *)param_1;
      lStack_20 = *(longlong *)(param_1 + 8);
      do {
        EVar4 = PopToStackDepth(this,(EVENT_ACTION *)&local_28);
        if (EVar4 != 1) {
          return EVar4;
        }
        EVar4 = ExitCurrentState(this,(EVENT_ACTION *)&local_28);
        if (EVar4 != 1) {
          return EVar4;
        }
        SVar1 = this[0x3c4];
        if ((byte)SVar1 < 2) {
          uVar8 = 0;
          uVar6 = 0;
          if (SVar1 != (StateMachineEngineImpl)0x0) goto LAB_180008f04;
        }
        else {
          uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -4 + (ulonglong)(byte)SVar1 * 2);
LAB_180008f04:
          uVar6 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2);
        }
        LogTransition(this,3,uVar6,local_28._4_2_,uVar8,local_28._6_1_);
        *(undefined2 *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2) = 0;
        SVar1 = this[0x3c4];
        this[0x3c4] = (StateMachineEngineImpl)((char)SVar1 + -1);
        this[0x3c5] = (StateMachineEngineImpl)0x0;
        FindActionForEvent(this,*(ushort *)(lStack_20 + 2),(EVENT_ACTION *)&local_28);
        if ((int)local_28 != 4) {
          if ((StateMachineEngineImpl)((char)SVar1 + -1) == (StateMachineEngineImpl)0x0) {
            return 1;
          }
          iVar7 = (int)local_28;
          if ((int)local_28 == 5) {
            iVar7 = 1;
          }
          local_28 = CONCAT44(local_28._4_4_,iVar7);
          EVar4 = ExecuteEventAction(this,(EVENT_ACTION *)&local_28);
          return EVar4;
        }
      } while( true );
    }
    if (iVar7 == 5) {
      return 1;
    }
    if (iVar7 != 6) {
      return 1;
    }
    SVar1 = this[0x3c4];
    if (SVar1 == (StateMachineEngineImpl)0x0) {
      uVar8 = 0;
    }
    else {
      uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2);
    }
    if (SVar1 == this[0x360]) {
      uVar6 = 0;
      MVar5 = 3;
      goto LAB_180009180;
    }
    uVar6 = **(ushort **)(param_1 + 8);
    if ((((*(byte *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + 2 + (ulonglong)uVar6 * 0x10
                    ) & 2) == 0) || (this[0x3c6] != (StateMachineEngineImpl)0x0)) &&
       (((*(byte *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + 2 + (ulonglong)uVar6 * 0x10)
         & 1) == 0 || (this[0x3c7] == (StateMachineEngineImpl)0x0)))) {
      LogTransition(this,5,uVar8,0,uVar6,(uchar)SVar1);
      *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)this[0x3c4] * 2) = uVar6;
      this[0x3c4] = (StateMachineEngineImpl)((char)this[0x3c4] + '\x01');
      goto LAB_180009147;
    }
  }
  EVar4 = 3;
LAB_1800090e4:
  uVar3 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x3b0) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x3b8) = uVar3;
  return EVar4;
}



===== ExitCurrentState @ 1800091ac =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ExitCurrentState(struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION const & __ptr64) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ExitCurrentState
          (StateMachineEngineImpl *this,EVENT_ACTION *param_1)

{
  short *psVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  ushort uVar5;
  longlong lVar6;
  ulonglong uVar7;
  ushort uVar8;
  
  if (this[0x3c5] == (StateMachineEngineImpl)0x0) {
    this[0x3c5] = (StateMachineEngineImpl)0x1;
    if (this[0x3c4] == (StateMachineEngineImpl)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2);
    }
    lVar6 = (ulonglong)uVar5 * 0x10 + *(longlong *)(*(longlong *)(this + 0x378) + 0x18);
    uVar5 = *(ushort *)(lVar6 + 4);
    if ((uVar5 & 0x40) != 0) {
      uVar8 = 1;
      uVar7 = 0;
      do {
        uVar4 = (ulonglong)((int)uVar7 + 1);
        if ((uVar5 & uVar8) != uVar8) {
          uVar4 = uVar7;
        }
        uVar8 = uVar8 * 2;
        uVar7 = uVar4;
      } while (uVar8 != 0x40);
      psVar1 = *(short **)(*(longlong *)(lVar6 + 8) + uVar4 * 8);
      if (((psVar1 != (short *)0x0) && (*(short *)(param_1 + 4) != *psVar1)) &&
         (iVar3 = (**(code **)(psVar1 + 4))(*(undefined8 *)(this + 0x380)), iVar3 != 1)) {
        uVar2 = *(undefined8 *)(param_1 + 8);
        *(undefined8 *)(this + 0x3b0) = *(undefined8 *)param_1;
        *(undefined8 *)(this + 0x3b8) = uVar2;
        *(short *)(this + 0x370) = *psVar1;
        return 5;
      }
    }
  }
  return 1;
}



===== FindActionForEvent @ 1800092ac =====

/* private: void __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::FindActionForEvent(unsigned short,struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION * __ptr64) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::FindActionForEvent
          (StateMachineEngineImpl *this,ushort param_1,EVENT_ACTION *param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  ushort uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  StateMachineEngineImpl SVar7;
  uint uVar8;
  longlong lVar9;
  
  SVar7 = this[0x3c4];
  *(ushort *)(param_2 + 4) = param_1;
  if (SVar7 == (StateMachineEngineImpl)0x0) {
    *(undefined4 *)param_2 = 1;
    param_2[6] = (EVENT_ACTION)0xff;
  }
  else {
    do {
      SVar7 = (StateMachineEngineImpl)((char)SVar7 + -1);
      lVar9 = (ulonglong)*(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)SVar7 * 2) *
              0x10 + *(longlong *)(*(longlong *)(this + 0x378) + 0x18);
      param_2[6] = (EVENT_ACTION)0xff;
      uVar4 = *(ushort *)(lVar9 + 4);
      uVar6 = (ulonglong)(uVar4 & 1);
      if ((uVar4 & 2) != 0) {
        uVar5 = 0;
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar3 = *puVar1;
        if (uVar3 != 0) {
          puVar2 = puVar1;
          do {
            if (uVar3 == param_1) {
              *(undefined4 *)param_2 = 2;
              goto LAB_180009432;
            }
            uVar5 = (ulonglong)((int)uVar5 + 1);
            puVar2 = puVar1 + uVar5 * 2;
            uVar3 = *puVar2;
          } while (uVar3 != 0);
        }
        uVar6 = (ulonglong)((uVar4 & 1) + 1);
      }
      if ((uVar4 & 4) != 0) {
        uVar8 = 0;
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar3 = *puVar1;
        if (uVar3 != 0) {
          puVar2 = puVar1;
          do {
            if (uVar3 == param_1) {
              *(undefined4 *)param_2 = 3;
              goto LAB_180009432;
            }
            uVar8 = uVar8 + 1;
            puVar2 = puVar1 + (ulonglong)uVar8 * 8;
            uVar3 = *puVar2;
          } while (uVar3 != 0);
        }
        uVar6 = (ulonglong)((int)uVar6 + 1);
      }
      if ((uVar4 & 8) != 0) {
        uVar5 = 0;
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar3 = *puVar1;
        while (uVar3 != 0) {
          if (uVar3 == param_1) {
            *(undefined4 *)param_2 = 5;
            goto LAB_180009436;
          }
          uVar5 = (ulonglong)((int)uVar5 + 1);
          uVar3 = puVar1[uVar5];
        }
        uVar6 = (ulonglong)((int)uVar6 + 1);
      }
      if ((uVar4 & 0x10) != 0) {
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar6 = 0;
        uVar4 = *puVar1;
        if (uVar4 != 0) {
          puVar2 = puVar1;
          do {
            if (uVar4 == param_1) {
              *(undefined4 *)param_2 = 4;
LAB_180009432:
              *(ushort **)(param_2 + 8) = puVar2;
LAB_180009436:
              *(StateMachineEngineImpl *)(param_2 + 6) = SVar7;
              return;
            }
            uVar6 = (ulonglong)((int)uVar6 + 1);
            puVar2 = puVar1 + uVar6 * 2;
            uVar4 = *puVar2;
          } while (uVar4 != 0);
        }
      }
      *(undefined4 *)param_2 = 1;
    } while ((*(char *)(lVar9 + 3) != '\x01') && (SVar7 != (StateMachineEngineImpl)0x0));
  }
  return;
}



===== Initialize @ 18000945c =====

/* private: long __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::Initialize(struct
   SmFx::STATE_MACHINE_ENGINE_CONFIG const & __ptr64) __ptr64 */

long __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::Initialize
          (StateMachineEngineImpl *this,STATE_MACHINE_ENGINE_CONFIG *param_1)

{
  StateMachineEngineImpl *pv;
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  DWORD DVar9;
  HANDLE hHeap;
  LPVOID pvVar10;
  PTP_WORK p_Var11;
  ulonglong uVar12;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  uVar6 = *(undefined8 *)(param_1 + 0x10);
  uVar7 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x378) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x380) = uVar1;
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  uVar3 = *(undefined4 *)(param_1 + 0x24);
  uVar4 = *(undefined4 *)(param_1 + 0x28);
  uVar5 = *(undefined4 *)(param_1 + 0x2c);
  *(undefined8 *)(this + 0x388) = uVar6;
  *(undefined8 *)(this + 0x390) = uVar7;
  uVar1 = *(undefined8 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x398) = uVar2;
  *(undefined4 *)(this + 0x39c) = uVar3;
  *(undefined4 *)(this + 0x3a0) = uVar4;
  *(undefined4 *)(this + 0x3a4) = uVar5;
  *(undefined8 *)(this + 0x3a8) = uVar1;
  if (this[0x3f8] == (StateMachineEngineImpl)0x0) {
    InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(this + 0x3d0),4000);
    this[0x3f8] = (StateMachineEngineImpl)0x1;
  }
  uVar12 = 0x10;
  if (this[0x3a9] != (StateMachineEngineImpl)0x0) {
    uVar12 = (ulonglong)(byte)this[0x3a9];
  }
  this[0x360] = SUB81(uVar12,0);
  hHeap = GetProcessHeap();
  pvVar10 = HeapAlloc(hHeap,0,uVar12 * 2);
  *(LPVOID *)(this + 0x368) = pvVar10;
  if (pvVar10 == (LPVOID)0x0) {
    lVar8 = -0x3fffff66;
  }
  else {
    if (this[0x3a8] != (StateMachineEngineImpl)0x0) {
      pv = this + 0x400;
      if (*(longlong *)pv != 0) {
        return -0x3ff8ec61;
      }
      p_Var11 = CreateThreadpoolWork
                          (<lambda_8a03d23fdee2c1785e106aafab25a0f7>::<lambda_invoker_cdecl>,pv,
                           (PTP_CALLBACK_ENVIRON)0x0);
      *(PTP_WORK *)pv = p_Var11;
      if (p_Var11 == (PTP_WORK)0x0) {
        DVar9 = GetLastError();
        if ((int)DVar9 < 1) {
          DVar9 = GetLastError();
        }
        else {
          DVar9 = GetLastError();
          DVar9 = DVar9 & 0xffff | 0xc0070000;
        }
        if ((int)DVar9 < 0) {
          return DVar9;
        }
      }
      else {
        *(StateMachineEngineImpl **)(this + 0x410) = this;
        *(code **)(this + 0x408) = <lambda_c276094d149607b901f7fae525da7e78>::<lambda_invoker_cdecl>
        ;
      }
    }
    InitiateFirstRun(this);
    lVar8 = 0;
  }
  return lVar8;
}



===== InitiateFirstRun @ 1800095b0 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::InitiateFirstRun(void)
   __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::InitiateFirstRun(StateMachineEngineImpl *this)

{
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD DVar1;
  EngineState EVar2;
  undefined8 local_18;
  longlong local_10;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(this + 0x3d0);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(this + 0x3cc) = 2;
  LeaveCriticalSection(lpCriticalSection);
  *(undefined2 *)(this + 0x3c6) = 0;
  DVar1 = GetCurrentThreadId();
  local_18 = 6;
  *(DWORD *)(this + 0x3c8) = DVar1;
  local_10 = *(longlong *)(*(byte **)(this + 0x378) + 8) + (ulonglong)**(byte **)(this + 0x378) * 2;
  EVar2 = ExecuteEventAction(this,(EVENT_ACTION *)&local_18);
  if (EVar2 == 2) {
    EVar2 = ExecuteCurrentState(this);
  }
  EnterCriticalSection(lpCriticalSection);
  if (EVar2 == 1) {
    ProcessEventQueue(this);
  }
  else {
    UpdateEngineState(this,EVar2);
  }
  return;
}



===== LogTransition @ 180009688 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::LogTransition(enum
   SmFx::TransitionType,unsigned short,unsigned short,unsigned short,unsigned char) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::LogTransition
          (StateMachineEngineImpl *this,TransitionType param_1,ushort param_2,ushort param_3,
          ushort param_4,uchar param_5)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  *(TransitionType *)(this + (ulonglong)(byte)this[0x3c0] * 0xc) = param_1;
  *(ushort *)(this + (ulonglong)(byte)this[0x3c0] * 0xc + 4) = param_3;
  if ((param_1 - 2 & 0xfffffffb) == 0) {
    *(ushort *)(this + (ulonglong)(byte)this[0x3c0] * 0xc + 6) = param_4;
  }
  else {
    *(ushort *)(this + (ulonglong)(byte)this[0x3c0] * 0xc + 6) = param_2;
  }
  uVar1 = 0;
  this[(ulonglong)(byte)this[0x3c0] * 0xc + 8] = (StateMachineEngineImpl)param_5;
  this[0x3c0] = (StateMachineEngineImpl)((char)this[0x3c0] + 1U & 0x3f);
  if (*(longlong *)(this + 0x398) != 0) {
    if (param_4 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + (ulonglong)param_4 * 0x10);
    }
    if (param_3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + (ulonglong)param_3 * 4);
    }
    if (param_2 != 0) {
      uVar1 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + (ulonglong)param_2 * 0x10);
    }
    (**(code **)(this + 0x398))(*(undefined8 *)(this + 0x380),param_1,uVar1,uVar2,uVar3);
  }
  return;
}



===== PopToStackDepth @ 1800097a8 =====

/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::PopToStackDepth(struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION const & __ptr64) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::PopToStackDepth
          (StateMachineEngineImpl *this,EVENT_ACTION *param_1)

{
  StateMachineEngineImpl SVar1;
  EngineState EVar2;
  ushort uVar3;
  
  if ((byte)param_1[6] + 1 < (uint)(byte)this[0x3c4]) {
    do {
      EVar2 = ExitCurrentState(this,param_1);
      if (EVar2 != 1) {
        return EVar2;
      }
      SVar1 = this[0x3c4];
      if ((byte)SVar1 < 2) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(ushort *)(*(longlong *)(this + 0x368) + -4 + (ulonglong)(byte)SVar1 * 2);
      }
      LogTransition(this,4,*(ushort *)
                            (*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2),
                    *(ushort *)(param_1 + 4),uVar3,(char)SVar1 - 1);
      *(undefined2 *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2) = 0;
      this[0x3c4] = (StateMachineEngineImpl)((char)this[0x3c4] + -1);
      this[0x3c5] = (StateMachineEngineImpl)0x0;
    } while ((byte)param_1[6] + 1 < (uint)(byte)this[0x3c4]);
  }
  return 1;
}



===== ProcessEventQueue @ 180009888 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(void)
   __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(StateMachineEngineImpl *this)

{
  ushort uVar1;
  short sVar2;
  EngineState EVar3;
  ulonglong uVar4;
  StateMachineEngineImpl SVar5;
  StateMachineEngineImpl SVar6;
  StateMachineEngineImpl SVar7;
  bool bVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  
  bVar8 = *(int *)(this + 0x3cc) == 5;
  *(undefined4 *)(this + 0x3cc) = 2;
LAB_1800098c5:
  do {
    if (!bVar8) {
      SVar5 = this[0x3c2];
      SVar7 = this[0x3c3];
      SVar6 = SVar5;
      if (SVar5 != SVar7) {
        while( true ) {
          local_28 = 0;
          uStack_20 = 0;
          uVar1 = *(ushort *)(this + (ulonglong)(byte)SVar6 * 2 + 0x340);
          FindActionForEvent(this,uVar1,(EVENT_ACTION *)&local_28);
          if ((int)local_28 != 5) break;
          SVar6 = (StateMachineEngineImpl)((char)SVar6 + 1U & 0xf);
          if (SVar6 == SVar7) goto LAB_18000992e;
        }
        if (SVar6 != SVar5) {
          do {
            uVar4 = (ulonglong)(byte)SVar6;
            SVar6 = (StateMachineEngineImpl)((char)SVar6 - 1U & 0xf);
            *(undefined2 *)(this + uVar4 * 2 + 0x340) =
                 *(undefined2 *)(this + (ulonglong)(byte)SVar6 * 2 + 0x340);
            SVar5 = this[0x3c2];
          } while (SVar6 != SVar5);
        }
        this[0x3c2] = (StateMachineEngineImpl)((char)SVar5 + 1U & 0xf);
        if (uVar1 != 0) goto LAB_1800099b1;
      }
LAB_18000992e:
      EVar3 = 1;
      goto LAB_180009933;
    }
    local_28 = *(undefined8 *)(this + 0x3b0);
    uStack_20 = *(undefined8 *)(this + 0x3b8);
    bVar8 = false;
LAB_1800099b1:
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
    EVar3 = ExecuteEventAction(this,(EVENT_ACTION *)&local_28);
    if (EVar3 == 2) {
      EVar3 = ExecuteCurrentState(this);
    }
    if (EVar3 == 1) {
      EVar3 = 2;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
    if (EVar3 == 5) {
      SVar5 = this[0x3c2];
      bVar8 = false;
      sVar2 = *(short *)(this + 0x370);
      SVar7 = SVar5;
      if (SVar5 != this[0x3c3]) {
        do {
          *(undefined2 *)(this + (ulonglong)(byte)SVar5 * 2 + 0x340) =
               *(undefined2 *)(this + (ulonglong)(byte)SVar7 * 2 + 0x340);
          if ((bVar8) || (*(short *)(this + (ulonglong)(byte)SVar7 * 2 + 0x340) != sVar2)) {
            SVar5 = (StateMachineEngineImpl)((char)SVar5 + 1U & 0xf);
          }
          else {
            bVar8 = true;
          }
          SVar7 = (StateMachineEngineImpl)((char)SVar7 + 1U & 0xf);
        } while (SVar7 != this[0x3c3]);
      }
      this[0x3c3] = SVar5;
      if (!bVar8) goto LAB_180009933;
      *(undefined2 *)(this + 0x370) = 0;
      bVar8 = true;
      goto LAB_1800098c5;
    }
    if (EVar3 != 2) {
LAB_180009933:
      UpdateEngineState(this,EVar3);
      return;
    }
  } while( true );
}



===== ReportException @ 180009a94 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::ReportException(enum
   SmFx::MachineException,unsigned short,unsigned short) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ReportException
          (StateMachineEngineImpl *this,MachineException param_1,ushort param_2,ushort param_3)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
  ReportExceptionWithLockHeld(this,param_1,param_2,param_3);
  return;
}



===== ReportExceptionWithLockHeld @ 180009af4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: void __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ReportExceptionWithLockHeld(enum
   SmFx::MachineException,unsigned short,unsigned short) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ReportExceptionWithLockHeld
          (StateMachineEngineImpl *this,MachineException param_1,ushort param_2,ushort param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  *(MachineException *)(this + (ulonglong)(byte)this[0x3c1] * 8 + 0x300) = param_1;
  *(ushort *)(this + (ulonglong)(byte)this[0x3c1] * 8 + 0x304) = param_2;
  *(ushort *)(this + (ulonglong)(byte)this[0x3c1] * 8 + 0x306) = param_3;
  this[0x3c1] = (StateMachineEngineImpl)((char)this[0x3c1] + 1U & 7);
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
  uVar2 = 0;
  if (*(code **)(this + 0x388) != (code *)0x0) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + (ulonglong)param_2 * 4);
    }
    if (param_3 != 0) {
      uVar2 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + (ulonglong)param_3 * 0x10);
    }
    (**(code **)(this + 0x388))(*(undefined8 *)(this + 0x380),param_1,uVar1,uVar2);
  }
  return;
}



===== UpdateEngineState @ 180009bd8 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::UpdateEngineState(enum
   SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::UpdateEngineState
          (StateMachineEngineImpl *this,EngineState param_1)

{
  short sVar1;
  
  if (param_1 - 3 < 2) {
    *(EngineState *)(this + 0x3cc) = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
    SubmitThreadpoolWork(*(PTP_WORK *)(this + 0x400));
  }
  else if (param_1 == 5) {
    *(undefined4 *)(this + 0x3cc) = 5;
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
  }
  else {
    *(EngineState *)(this + 0x3cc) = param_1;
    if (this[0x3c4] == (StateMachineEngineImpl)0x0) {
      sVar1 = 0;
    }
    else {
      sVar1 = *(short *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3c4] * 2);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x3d0));
    if (sVar1 == 0) {
      Destroy(this);
    }
  }
  return;
}



===== Feature_SMST__private_IsEnabledDeviceUsageNoInline @ 180009ca0 =====

uint Feature_SMST__private_IsEnabledDeviceUsageNoInline(void)

{
  uint uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_SMST__private_featureState;
  if ((Feature_SMST__private_featureState & 0x10) == 0) {
    uVar1 = wil_details_IsEnabledFallback(local_res8,3);
    return uVar1;
  }
  return Feature_SMST__private_featureState & 1;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 180009cdc =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_3 == 0) {
LAB_180009edf:
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar5 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar5 = uVar3 | uVar5 & 0xffffbfff;
      }
      uVar6 = uVar5 >> 5 & 0x1ff;
      uVar3 = uVar6 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 5 ^ uVar5) & 0x3fe0;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_180009db7:
        uVar5 = 0;
        if (param_3 == 2) {
          uVar5 = 2;
        }
        else if (param_3 == 3) {
          uVar5 = 8;
        }
        else if (param_3 == 6) {
          uVar5 = 4;
        }
        else if (param_3 == 7) {
          uVar5 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar5 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar6 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar6 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar6;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar6 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_180009edf;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar5 = param_3 - 0x140;
          if ((int)uVar5 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar5)) {
                uVar3 = 0;
              }
              else {
                uVar3 = 1;
              }
              param_1[4] = uVar3;
              LOCK();
              uVar3 = param_2[1];
              bVar7 = uVar4 == uVar3;
              if (bVar7) {
                param_2[1] = (uVar5 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
              }
              else {
                uVar4 = uVar3;
              }
              UNLOCK();
            } while (!bVar7);
            if (param_1[4] != 0) {
              return param_1;
            }
          }
          param_1[2] = param_3;
          param_1[1] = 1;
          param_1[3] = param_4;
          return param_1;
        }
        goto LAB_180009db7;
      }
    }
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar5 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar5 = uVar3 | uVar5 & 0xffbfffff;
      }
      uVar6 = uVar5 >> 0xf & 0x7f;
      uVar3 = uVar6 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 0xf ^ uVar5) & 0x3f8000;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 180009fc8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_18000a08b;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_18000a08b;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_18000a08b;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_18000a08b;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_18000a08b;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_18000a08b;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_18000a08b;
    }
  }
  uVar2 = 0xff;
LAB_18000a08b:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3803791,&Feature_Standalone_Future_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 18000a0e4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,(uint *)&Feature_SMST__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3803791,param_3,1,&Feature_SMST__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3803791);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 18000a1d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar3 = 0;
  local_88 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar3 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  bVar2 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  iVar4 = RtlQueryFeatureConfiguration
                    (*(undefined4 *)(param_3 + 0x18),1 < (byte)(*(char *)(param_3 + 0x1c) - 2U),
                     &local_78,&local_58);
  if (iVar4 == 0) {
    bVar2 = 1;
    uVar8 = local_58._4_4_ >> 7 & 1;
    local_70 = CONCAT44(local_70._4_4_,local_58._4_4_ >> 4) & 0xffffffff00000003;
    uVar5 = local_58._4_4_ >> 6 & 1;
    uVar11 = local_58._4_4_ >> 4 & 3;
LAB_18000a283:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_18000a2b1;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_18000a283;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_18000a2b1:
  uVar6 = -(uint)bVar2 & uVar11 & 3;
  if (uVar6 == 0) {
    uVar9 = -(uint)(*(char *)(param_3 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar9 = 0;
    if (uVar11 == 2) {
      uVar9 = 0x40;
    }
  }
  uVar11 = uVar9 >> 6 ^ (uVar9 | uVar6 << 7 | uVar8 | uVar5);
  if ((uVar9 != 0) && (plVar10 = *(longlong **)(param_3 + 0x20), plVar10 != (longlong *)0x0)) {
    do {
      puVar1 = (undefined8 *)*plVar10;
      if (puVar1 == (undefined8 *)0x0) break;
      if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar1 + 0x1d) == '\0')) {
        uVar8 = *(uint *)*puVar1;
        local_80 = (ulonglong)uVar8;
        if ((uVar8 & 2) == 0) {
          uVar7 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar1,local_80,(longlong)puVar1);
          uVar8 = (uint)uVar7;
        }
        uVar5 = uVar11 & 0xfffffffe;
        uVar11 = (uint)((uVar8 & uVar11 & 1) != 0);
      }
      else {
        if (((uVar11 & 1) == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        uVar11 = uVar11 & 0xfffffffe;
      }
      uVar11 = uVar11 | uVar5;
      plVar10 = plVar10 + 1;
    } while ((uVar11 & 1) != 0);
  }
  bVar12 = *(char *)(param_3 + 0x1c) == '\0';
  uVar7 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar7;
    local_88 = CONCAT44(local_88._4_4_,uVar5);
    if ((!bVar12 || iVar3 != 0) && (local_88 = CONCAT44(local_88._4_4_,uVar5), (uVar7 & 2) == 0)) {
      uVar8 = (uVar11 ^ uVar5) & 0x9c1 ^ uVar5;
      uVar5 = uVar8 | 2;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar8 = (uVar5 ^ uVar11) & 0x400 ^ uVar5;
      uVar5 = uVar8 | 4;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 4;
    }
    uVar7 = param_2 & 0xffffffff;
    LOCK();
    uVar8 = *param_1;
    bVar13 = (uint)param_2 == uVar8;
    if (bVar13) {
      *param_1 = uVar5;
    }
    else {
      uVar7 = (ulonglong)uVar8;
    }
    UNLOCK();
    if (bVar13) break;
    param_2 = uVar7;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (bVar12 && iVar3 == 0) {
    local_88 = CONCAT44(local_88._4_4_,(uVar11 ^ uVar5) & 0x9c1 ^ uVar5);
  }
  return local_88;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 18000a43c =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 == 3) {
    uVar2 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar2 = 0x20;
  }
  if ((Feature_SMST__private_featureState & 2) != 0) {
    uVar1 = Feature_SMST__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_SMST__private_featureState;
      if (bVar3) {
        Feature_SMST__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_SMST__private_featureState;
      }
      UNLOCK();
      if (bVar3) {
        return;
      }
      if ((uVar1 & 2) == 0) {
        return;
      }
    }
  }
  return;
}



===== wil_details_IsEnabledFallback @ 18000a490 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_SMST__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_SMST__private_featureState,(ulonglong)param_1,0x18000ecf8);
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== ~SpinLock @ 18000a520 =====

/* public: __cdecl SmFx::SpinLock::~SpinLock(void) __ptr64 */

void __thiscall SmFx::SpinLock::~SpinLock(SpinLock *this)

{
  if (this[0x28] != (SpinLock)0x0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)this);
    this[0x28] = (SpinLock)0x0;
  }
  return;
}



===== <lambda_invoker_cdecl> @ 18000a550 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void <lambda_8a03d23fdee2c1785e106aafab25a0f7>::<lambda_invoker_cdecl>
               (PTP_CALLBACK_INSTANCE param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = LdrAddRefDll(0,0x180000000);
  if (-1 < iVar1) {
    FreeLibraryWhenCallbackReturns(param_1,(HMODULE)&IMAGE_DOS_HEADER_180000000);
  }
  (**(code **)(param_2 + 8))(*(undefined8 *)(param_2 + 0x10));
  return;
}



===== ~Worker @ 18000a5ac =====

/* public: __cdecl SmFx::Worker::~Worker(void) __ptr64 */

void __thiscall SmFx::Worker::~Worker(Worker *this)

{
  if (*(PTP_WORK *)this != (PTP_WORK)0x0) {
    CloseThreadpoolWork(*(PTP_WORK *)this);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== UsbPmApiWnf_CallbackWrapper @ 18000a5f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl UsbPmApiWnf_CallbackWrapper(struct _WNF_STATE_NAME,unsigned long,struct _WNF_TYPE_ID
   * __ptr64,void * __ptr64,void const * __ptr64,unsigned long) */

long __cdecl
UsbPmApiWnf_CallbackWrapper
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,int *param_4,undefined8 param_5,
          undefined4 param_6)

{
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  if (*param_4 == 0x53574d50) {
    local_28 = param_6;
    local_18 = param_1;
    (**(code **)(param_4 + 8))(&local_18,param_2,*(undefined8 *)(param_4 + 10),param_5);
  }
  return 0;
}



===== UsbPmApip_WnfSubscribeChangeNotification @ 18000a650 =====

int UsbPmApip_WnfSubscribeChangeNotification
              (undefined8 *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
              undefined8 param_5,undefined8 *param_6)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_6 == (undefined8 *)0x0) || (param_4 == 0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    puVar3 = (undefined4 *)malloc(0x30);
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = -0x3fffff66;
    }
    else {
      uVar1 = *param_1;
      puVar3[6] = 0;
      *puVar3 = 0x53574d50;
      *(undefined8 *)(puVar3 + 4) = *param_1;
      *(undefined8 *)(puVar3 + 10) = param_5;
      *(longlong *)(puVar3 + 8) = param_4;
      iVar2 = RtlSubscribeWnfStateChangeNotification
                        (puVar3 + 2,uVar1,0,UsbPmApiWnf_CallbackWrapper,puVar3,0,0,0);
      if (iVar2 < 0) {
        _o_free(puVar3);
      }
      else {
        *param_6 = puVar3;
      }
    }
  }
  return iVar2;
}



===== UsbPmApip_WnfUnsubscribeChangeNotification @ 18000a720 =====

int UsbPmApip_WnfUnsubscribeChangeNotification(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((param_1 == (undefined8 *)0x0) || (piVar1 = (int *)*param_1, piVar1 == (int *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else if (*piVar1 == 0x53574d50) {
    iVar2 = RtlUnsubscribeWnfStateChangeNotification(*(undefined8 *)(piVar1 + 2));
    if (-1 < iVar2) {
      _o_free(piVar1);
      *param_1 = 0;
    }
  }
  else {
    iVar2 = -0x3ffffff8;
  }
  return iVar2;
}



===== __GSHandlerCheck @ 18000a790 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 18000a7b4 =====

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



===== memcpy @ 18000a815 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a815. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== _guard_dispatch_icall @ 18000a840 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 18000a860 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00018000a860. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 18000a880 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== fin$0 @ 18000a88c =====

void `dllmain_crt_process_attach'::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}



===== fin$0 @ 18000a8a9 =====

void `dllmain_crt_process_detach'::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}



===== fin$1 @ 18000a8c2 =====

void `dllmain_crt_process_detach'::__l1::fin_1(void)

{
  __scrt_dllmain_uninitialize_critical();
  return;
}



===== filt$0 @ 18000a8dc =====

void `dllmain_dispatch'::__l1::filt_0(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),dllmain_crt_dispatch,*(undefined4 *)*param_1,param_1);
  return;
}



===== __scrt_is_nonwritable_in_current_image$filt$0 @ 18000a918 =====

bool __scrt_is_nonwritable_in_current_image_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== Create @ 18000b008 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: static long __cdecl UpaClient::Create(struct _USBPM_CLIENT_CONFIG * __ptr64,class
   UpaClient * __ptr64 * __ptr64) */

long __cdecl UpaClient::Create(_USBPM_CLIENT_CONFIG *param_1,UpaClient **param_2)

{
  long lVar1;
  UpaClient *pUVar2;
  undefined8 in_R8;
  
  if ((param_1 == (_USBPM_CLIENT_CONFIG *)0x0) || (*(int *)param_1 != 1)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    pUVar2 = UpaBaseClass::operator_new(0x11e0);
    if ((pUVar2 != (UpaClient *)0x0) &&
       (pUVar2 = (UpaClient *)UpaClient(pUVar2,param_1), pUVar2 != (UpaClient *)0x0)) {
      lVar1 = Initialize(pUVar2);
      if (-1 < lVar1) {
        *param_2 = pUVar2;
        return lVar1;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
        WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x17,in_R8,lVar1,(char)pUVar2);
      }
      (*(code *)**(undefined8 **)pUVar2)(pUVar2,1);
      return lVar1;
    }
    lVar1 = -0x3fffff66;
  }
  return lVar1;
}



===== Initialize @ 18000b0d0 =====

/* private: long __cdecl UpaClient::Initialize(void) __ptr64 */

long __thiscall UpaClient::Initialize(UpaClient *this)

{
  long lVar1;
  undefined2 uVar2;
  StateMachineEngineConfig *in_RDX;
  undefined8 in_R8;
  
  *(undefined8 *)(this + 0xa8) = 0;
  *(UpaClient **)(this + 0x48) = this;
  lVar1 = UpaHelperEvent::Initialize((UpaHelperEvent *)(this + 0xb0),(uchar)in_RDX);
  if (lVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x19])) {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),100,in_R8,lVar1,
                (char)*(undefined8 *)(this + 0x48));
    }
  }
  else {
    lVar1 = UsbPmApiCallbacksStateMachine<UpaCallbacks>::Initialize
                      ((UsbPmApiCallbacksStateMachine<UpaCallbacks> *)(this + 0x40),
                       (StateMachineEngineConfig *)in_RDX);
    if (((lVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((WPP_GLOBAL_Control[0x1c] & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x19])))) {
      WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x65,in_R8,lVar1,
                (char)*(undefined8 *)(this + 0x48));
    }
    else if (-1 < lVar1) {
      lVar1 = UpaHelperEvent::Initialize((UpaHelperEvent *)(this + 0x140),(uchar)in_RDX);
      if (lVar1 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return lVar1;
        }
        if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
          return lVar1;
        }
        if ((byte)WPP_GLOBAL_Control[0x19] < 2) {
          return lVar1;
        }
        uVar2 = 0x1c;
      }
      else {
        lVar1 = UsbPmApiClientStateMachine<UpaClient>::Initialize
                          ((UsbPmApiClientStateMachine<UpaClient> *)(this + 0x10),in_RDX);
        if (-1 < lVar1) {
          return lVar1;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return lVar1;
        }
        if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
          return lVar1;
        }
        if ((byte)WPP_GLOBAL_Control[0x19] < 2) {
          return lVar1;
        }
        uVar2 = 0x1d;
      }
      goto LAB_18000b224;
    }
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return lVar1;
  }
  if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
    return lVar1;
  }
  if ((byte)WPP_GLOBAL_Control[0x19] < 2) {
    return lVar1;
  }
  uVar2 = 0x1b;
LAB_18000b224:
  WPP_SF_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar2,in_R8,lVar1,(char)this);
  return lVar1;
}



===== Start @ 18000b258 =====

/* public: long __cdecl UpaClient::Start(void) __ptr64 */

long __thiscall UpaClient::Start(UpaClient *this)

{
  UsbPmApiClientStateMachine<UpaClient>::EnqueueEvent
            ((UsbPmApiClientStateMachine<UpaClient> *)(this + 0x10),0x10);
  return 0;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 18000c010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


