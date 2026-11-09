
===== initialize_legacy_wide_specifiers @ 140001010 =====

undefined8 initialize_legacy_wide_specifiers(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 4;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return 0;
}



===== __local_stdio_printf_options @ 140001034 =====

__uint64 * __local_stdio_printf_options(void)

{
  return &`__local_stdio_printf_options'::__l2::_OptionsStorage;
}



===== __local_stdio_scanf_options @ 140001044 =====

__uint64 * __local_stdio_scanf_options(void)

{
  return &`__local_stdio_scanf_options'::__l2::_OptionsStorage;
}



===== initialize_msvcrt_compatibility @ 140001060 =====

undefined8 initialize_msvcrt_compatibility(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x18;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 4;
  return 0;
}



===== pre_c_initialization @ 140001090 =====

void pre_c_initialization(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  
  _o__set_app_type(2);
  uVar4 = _get_startup_file_mode();
  _set_fmode(uVar4 & 0xffffffff);
  uVar5 = _get_startup_commit_mode();
  puVar6 = (undefined4 *)_o___p__commode();
  *puVar6 = (int)uVar5;
  uVar5 = __scrt_initialize_onexit_tables(1);
  if ((char)uVar5 != '\0') {
    _RTC_Initialize();
    atexit(_RTC_Terminate);
    uVar4 = _get_startup_argv_mode();
    iVar3 = _configure_wide_argv(uVar4 & 0xffffffff);
    if (iVar3 == 0) {
      __scrt_initialize_type_info();
      _guard_check_icall();
      _guard_check_icall();
      uVar4 = _get_startup_commit_mode();
      _o__configthreadlocale(uVar4 & 0xffffffff);
      cVar2 = __vcrt_initialize();
      if (cVar2 != '\0') {
        _initialize_wide_environment();
      }
      _get_startup_commit_mode();
      uVar5 = __scrt_initialize_mta();
      if ((int)uVar5 == 0) {
        return;
      }
    }
  }
  __scrt_fastfail(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== post_pgo_initialization @ 140001140 =====

undefined8 post_pgo_initialization(void)

{
  __scrt_initialize_default_local_stdio_options();
  return 0;
}



===== pre_cpp_initialization @ 140001160 =====

void pre_cpp_initialization(void)

{
  ulonglong uVar1;
  
  __scrt_set_unhandled_exception_filter();
  uVar1 = _get_startup_commit_mode();
  _set_new_mode(uVar1 & 0xffffffff);
  return;
}



===== __scrt_common_main_seh @ 140001180 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong __scrt_common_main_seh(void)

{
  code *pcVar1;
  bool bVar2;
  WORD WVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  LPWSTR lpCmdLine;
  IMAGE_DOS_HEADER *pIVar10;
  ulonglong unaff_RBX;
  
  lVar6 = __scrt_initialize_crt(1);
  if ((char)lVar6 == '\0') {
    __scrt_fastfail(7);
  }
  else {
    bVar2 = false;
    uVar7 = __scrt_acquire_startup_lock();
    unaff_RBX = CONCAT71((int7)(unaff_RBX >> 8),(char)uVar7);
    if (__scrt_current_native_startup_state != 1) {
      if (__scrt_current_native_startup_state == 0) {
        __scrt_current_native_startup_state = 1;
        iVar4 = _initterm_e(&__xi_a,&__xi_z);
        if (iVar4 != 0) {
          return 0xff;
        }
        _initterm(&__xc_a);
        __scrt_current_native_startup_state = 2;
      }
      else {
        bVar2 = true;
      }
      __scrt_release_startup_lock((char)uVar7);
      plVar8 = (longlong *)__scrt_get_dyn_tls_init_callback();
      if ((*plVar8 != 0) &&
         (uVar9 = __scrt_is_nonwritable_in_current_image((longlong)plVar8), (char)uVar9 != '\0')) {
        (*(code *)*plVar8)(0);
      }
      plVar8 = (longlong *)__scrt_get_dyn_tls_dtor_callback();
      if ((*plVar8 != 0) &&
         (uVar9 = __scrt_is_nonwritable_in_current_image((longlong)plVar8), (char)uVar9 != '\0')) {
        _register_thread_local_exe_atexit_callback(*plVar8);
      }
      WVar3 = __scrt_get_show_window_mode();
      lpCmdLine = (LPWSTR)_get_wide_winmain_command_line();
      pIVar10 = &IMAGE_DOS_HEADER_140000000;
      uVar5 = wWinMain((HINSTANCE)&IMAGE_DOS_HEADER_140000000,(HINSTANCE)0x0,lpCmdLine,(uint)WVar3);
      unaff_RBX = (ulonglong)uVar5;
      uVar9 = __scrt_is_managed_app();
      if ((char)uVar9 != '\0') {
        if (!bVar2) {
          _cexit();
        }
        __scrt_uninitialize_crt(CONCAT71((int7)((ulonglong)pIVar10 >> 8),1),'\0');
        return unaff_RBX;
      }
      goto LAB_1400012e0;
    }
  }
  __scrt_fastfail(7);
LAB_1400012e0:
  exit(unaff_RBX & 0xffffffff);
  _exit(unaff_RBX & 0xffffffff);
  pcVar1 = (code *)swi(3);
  uVar9 = (*pcVar1)();
  return uVar9;
}



===== entry @ 140001300 =====

void entry(void)

{
  __security_init_cookie();
  __scrt_common_main_seh();
  return;
}



===== __security_check_cookie @ 140001330 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __scrt_acquire_startup_lock @ 140001354 =====

ulonglong __scrt_acquire_startup_lock(void)

{
  bool bVar1;
  undefined7 extraout_var;
  void *pvVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  pvVar2 = (void *)CONCAT71(extraout_var,bVar1);
  if ((int)pvVar2 == 0) {
LAB_140001382:
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
      if (bVar1) goto LAB_140001382;
    } while (StackBase != pvVar2);
    uVar3 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  return uVar3;
}



===== __scrt_initialize_crt @ 140001394 =====

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_1400060d1 = 1;
  }
  __isa_available_init();
  cVar1 = __vcrt_initialize();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = __vcrt_initialize();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    __vcrt_initialize();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}



===== __scrt_initialize_onexit_tables @ 1400013d4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  ulonglong in_RAX;
  undefined7 extraout_var;
  undefined8 uVar3;
  
  if (DAT_1400060d0 == '\0') {
    if (1 < param_1) {
      __scrt_fastfail(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    bVar2 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar2) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_1400060a0 = 0xffffffffffffffff;
      uRam00000001400060a8 = 0xffffffffffffffff;
      _DAT_1400060b0 = 0xffffffffffffffff;
      _DAT_1400060b8 = 0xffffffffffffffff;
      uRam00000001400060c0 = 0xffffffffffffffff;
      _DAT_1400060c8 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _o__initialize_onexit_table(&DAT_1400060a0);
      if (((int)in_RAX != 0) ||
         (in_RAX = _o__initialize_onexit_table(&DAT_1400060b8), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_1400060d0 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== __scrt_is_nonwritable_in_current_image @ 140001468 =====

/* WARNING: Removing unreachable block (ram,0x0001400014f5) */
/* WARNING: Enum "SectionFlags": Some values do not have unique names */

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_140000208; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_140000320;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x140000000U) &&
       (uVar1 = (ulonglong)((pIVar3->Misc).PhysicalAddress + pIVar3->VirtualAddress),
       param_1 - 0x140000000U < uVar1)) goto LAB_1400014de;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_1400014de:
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



===== __scrt_release_startup_lock @ 140001508 =====

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



===== __scrt_uninitialize_crt @ 140001534 =====

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_1400060d1 == '\0') || (param_2 == '\0')) {
    __vcrt_initialize();
    __vcrt_initialize();
  }
  return 1;
}



===== _onexit @ 140001564 =====

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_1400060a0 == -1) {
    iVar1 = _o__crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_1400060a0);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}



===== atexit @ 1400015a4 =====

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



===== __security_init_cookie @ 1400015c4 =====

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



===== _get_startup_argv_mode @ 14000167c =====

undefined8 _get_startup_argv_mode(void)

{
  return 1;
}



===== _get_startup_commit_mode @ 140001688 =====

undefined8 _get_startup_commit_mode(void)

{
  return 0;
}



===== _get_startup_file_mode @ 140001694 =====

undefined8 _get_startup_file_mode(void)

{
  return 0x4000;
}



===== __scrt_initialize_type_info @ 1400016a0 =====

/* void __cdecl __scrt_initialize_type_info(void) */

void __cdecl __scrt_initialize_type_info(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400016a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&__type_info_root_node);
  return;
}



===== __vcrt_initialize @ 1400016b4 =====

undefined1 __vcrt_initialize(void)

{
  return 1;
}



===== _guard_check_icall @ 1400016c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __scrt_initialize_default_local_stdio_options @ 1400016cc =====

void __scrt_initialize_default_local_stdio_options(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x24;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return;
}



===== __scrt_get_dyn_tls_init_callback @ 1400016f0 =====

undefined * __scrt_get_dyn_tls_init_callback(void)

{
  return &__dyn_tls_init_callback;
}



===== __scrt_get_dyn_tls_dtor_callback @ 140001700 =====

undefined * __scrt_get_dyn_tls_dtor_callback(void)

{
  return &__dyn_tls_dtor_callback;
}



===== __crt_debugger_hook @ 140001710 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __crt_debugger_hook(int param_1)

{
  ___scrt_debugger_hook_flag = 0;
  return;
}



===== __scrt_fastfail @ 140001720 =====

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
  *(undefined8 *)(puVar4 + -8) = 0x140001754;
  __crt_debugger_hook(3);
  *(undefined8 *)(puVar4 + -8) = 0x140001765;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x14000176f;
  RtlCaptureContext(local_4d8);
  local_res10 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x140001791;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    local_res18 = 0;
    local_res20 = 0;
    *(undefined8 **)(puVar4 + 0x30) = &local_res18;
    *(undefined8 **)(puVar4 + 0x28) = &local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x1400017e2;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = auStack_5c8 + 0x5d0;
  *(undefined8 *)(puVar4 + -8) = 0x140001814;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x140001836;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x140001853;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x14000185e;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x14000186f;
    __crt_debugger_hook(3);
  }
  return;
}



===== __scrt_get_show_window_mode @ 140001888 =====

WORD __scrt_get_show_window_mode(void)

{
  WORD WVar1;
  _STARTUPINFOW local_78;
  
  memset(&local_78,0,0x68);
  GetStartupInfoW(&local_78);
  WVar1 = 10;
  if (((byte)local_78.dwFlags & 1) != 0) {
    WVar1 = local_78.wShowWindow;
  }
  return WVar1;
}



===== __scrt_initialize_mta @ 1400018c8 =====

undefined8 __scrt_initialize_mta(void)

{
  return 0;
}



===== __scrt_is_managed_app @ 1400018d4 =====

ulonglong __scrt_is_managed_app(void)

{
  HMODULE pHVar1;
  ulonglong uVar2;
  int *piVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || ((short)pHVar1->unused != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)&pHVar1->unused + (longlong)pHVar1[0xf].unused), *piVar3 != 0x4550
      )) || ((pHVar1 = (HMODULE)0x20b, (short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)))) {
    uVar2 = (ulonglong)pHVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = CONCAT71(2,piVar3[0x3e] != 0);
  }
  return uVar2;
}



===== __scrt_set_unhandled_exception_filter @ 14000192c =====

void __scrt_set_unhandled_exception_filter(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001933. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter(__scrt_unhandled_exception_filter);
  return;
}



===== __scrt_unhandled_exception_filter @ 140001940 =====

undefined8 __scrt_unhandled_exception_filter(undefined8 *param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  piVar1 = (int *)*param_1;
  if ((*piVar1 == -0x1f928c9d) && (piVar1[6] == 4)) {
    if ((piVar1[8] + 0xe66cfae0U < 3) || (piVar1[8] == 0x1994000)) {
      puVar3 = (undefined8 *)__current_exception();
      *puVar3 = piVar1;
      uVar4 = param_1[1];
      puVar3 = (undefined8 *)__current_exception_context();
      *puVar3 = uVar4;
      terminate();
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
  }
  return 0;
}



===== _RTC_Initialize @ 1400019a4 =====

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



===== _RTC_Terminate @ 1400019f0 =====

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



===== __raise_securityfailure @ 140001a38 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE hProcess;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  hProcess = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000140001a65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(hProcess,0xc0000409);
  return;
}



===== __report_gsfailure @ 140001a80 =====

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
  *(undefined8 *)(puVar3 + -8) = 0x140001aab;
  capture_previous_context((PCONTEXT)&DAT_1400061a0);
  _DAT_140006110 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_140006238 = puVar3 + 0x40;
  _DAT_140006220 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_140006100 = 0xc0000409;
  _DAT_140006104 = 1;
  _DAT_140006118 = 1;
  DAT_140006120 = 2;
  *(undefined8 *)(puVar3 + 0x20) = __security_cookie;
  *(undefined8 *)(puVar3 + 0x28) = __security_cookie_complement;
  *(undefined8 *)(puVar3 + -8) = 0x140001b4d;
  DAT_140006298 = _DAT_140006110;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_140004000);
  return;
}



===== capture_previous_context @ 140001b58 =====

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



===== __isa_available_init @ 140001be4 =====

/* WARNING: Removing unreachable block (ram,0x000140001cae) */
/* WARNING: Removing unreachable block (ram,0x000140001c1e) */
/* WARNING: Removing unreachable block (ram,0x000140001bf7) */
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



===== __scrt_is_ucrt_dll_in_use @ 140001d98 =====

bool __scrt_is_ucrt_dll_in_use(void)

{
  return __scrt_ucrt_dll_is_in_use != 0;
}



===== _initterm @ 140001db6 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001db6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== _initterm_e @ 140001dc2 =====

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001dc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}



===== _c_exit @ 140001dce =====

void __cdecl _c_exit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001dce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _c_exit();
  return;
}



===== _register_thread_local_exe_atexit_callback @ 140001dda =====

void _register_thread_local_exe_atexit_callback(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001dda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_thread_local_exe_atexit_callback();
  return;
}



===== _o___p__commode @ 140001de6 =====

void _o___p__commode(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001de6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___p__commode();
  return;
}



===== _cexit @ 140001df2 =====

void _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001df2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__cexit();
  return;
}



===== _o__configthreadlocale @ 140001dfe =====

void _o__configthreadlocale(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001dfe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configthreadlocale();
  return;
}



===== _configure_wide_argv @ 140001e0a =====

void _configure_wide_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configure_wide_argv();
  return;
}



===== _o__crt_atexit @ 140001e16 =====

void _o__crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__crt_atexit();
  return;
}



===== _exit @ 140001e22 =====

void _exit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__exit();
  return;
}



===== _get_wide_winmain_command_line @ 140001e2e =====

void _get_wide_winmain_command_line(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__get_wide_winmain_command_line();
  return;
}



===== _o__initialize_onexit_table @ 140001e3a =====

void _o__initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_onexit_table();
  return;
}



===== _initialize_wide_environment @ 140001e46 =====

void _initialize_wide_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_wide_environment();
  return;
}



===== _register_onexit_function @ 140001e52 =====

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__register_onexit_function();
  return;
}



===== _o__seh_filter_exe @ 140001e5e =====

void _o__seh_filter_exe(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__seh_filter_exe();
  return;
}



===== _o__set_app_type @ 140001e6a =====

void _o__set_app_type(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__set_app_type();
  return;
}



===== _set_fmode @ 140001e76 =====

void _set_fmode(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__set_fmode();
  return;
}



===== _set_new_mode @ 140001e82 =====

void _set_new_mode(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__set_new_mode();
  return;
}



===== exit @ 140001e8e =====

void exit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_exit();
  return;
}



===== terminate @ 140001e9a =====

void terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001e9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_terminate();
  return;
}



===== __C_specific_handler @ 140001ea6 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001ea6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __current_exception @ 140001eb2 =====

void __current_exception(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001eb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception();
  return;
}



===== __current_exception_context @ 140001ebe =====

void __current_exception_context(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001ebe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception_context();
  return;
}



===== memset @ 140001eca =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001eca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== wWinMain @ 140001ed8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __stdcall wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd)

{
  short sVar1;
  OLECHAR OVar2;
  int iVar3;
  HRESULT HVar4;
  short *psVar5;
  OLECHAR *pOVar6;
  HANDLE hProcess;
  short *psVar7;
  OLECHAR *pOVar8;
  longlong lVar9;
  undefined1 auStack_2b8 [32];
  IID local_298;
  OLECHAR local_288 [48];
  short local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_2b8;
  HeapSetInformation((HANDLE)0x0,HeapEnableTerminationOnCorruption,(PVOID)0x0,0);
  psVar7 = local_228;
  lVar9 = 0x105;
  local_298.Data1 = 0;
  local_298.Data2 = 0;
  local_298.Data3 = 0;
  local_298.Data4[0] = '\0';
  local_298.Data4[1] = '\0';
  local_298.Data4[2] = '\0';
  local_298.Data4[3] = '\0';
  local_298.Data4[4] = '\0';
  local_298.Data4[5] = '\0';
  local_298.Data4[6] = '\0';
  local_298.Data4[7] = '\0';
  do {
    if ((lVar9 == -0x7ffffef9) ||
       (sVar1 = *(short *)(((longlong)lpCmdLine - (longlong)local_228) + (longlong)psVar7),
       sVar1 == 0)) break;
    *psVar7 = sVar1;
    psVar7 = psVar7 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  psVar5 = psVar7 + -1;
  if (lVar9 != 0) {
    psVar5 = psVar7;
  }
  *psVar5 = 0;
  if (lVar9 != 0) {
    psVar7 = local_228;
    while (local_228[0] != 0) {
      psVar5 = psVar7 + 1;
      if (local_228[0] == 0x3a) {
        *psVar7 = 0;
        if ((*psVar5 != 0) && (iVar3 = _o__wcsicmp(local_228,L"/ProcessID"), iVar3 == 0))
        goto LAB_140001fbc;
        break;
      }
      psVar7 = psVar5;
      local_228[0] = *psVar5;
    }
    psVar5 = local_228;
LAB_140001fbc:
    lVar9 = 0x29;
    pOVar8 = local_288;
    do {
      if ((lVar9 == -0x7fffffd5) ||
         (OVar2 = *(OLECHAR *)(((longlong)psVar5 - (longlong)local_288) + (longlong)pOVar8),
         OVar2 == L'\0')) break;
      *pOVar8 = OVar2;
      pOVar8 = pOVar8 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    pOVar6 = pOVar8 + -1;
    if (lVar9 != 0) {
      pOVar6 = pOVar8;
    }
    *pOVar6 = L'\0';
    if (((lVar9 != 0) && (HVar4 = IIDFromString(local_288,&local_298), -1 < HVar4)) &&
       (HVar4 = CoInitializeEx((LPVOID)0x0,0), -1 < HVar4)) {
      CoRegisterSurrogateEx(&local_298,0);
      CoUninitialize();
      hProcess = GetCurrentProcess();
      TerminateProcess(hProcess,0);
    }
  }
  return 0;
}



===== __GSHandlerCheck @ 140002098 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400020bc =====

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



===== _guard_dispatch_icall @ 140002140 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002160 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002180 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== filt$0 @ 14000218c =====

void `__scrt_common_main_seh'::__l1::filt_0(undefined8 *param_1)

{
  _o__seh_filter_exe(*(undefined4 *)*param_1,param_1);
  return;
}



===== __scrt_is_nonwritable_in_current_image$filt$0 @ 1400021b0 =====

bool __scrt_is_nonwritable_in_current_image_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 140003010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


