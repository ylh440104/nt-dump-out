
===== `dynamic_initializer_for_'g_header_init_InitializeResultExceptions'' @ 180001010 =====

void wil::details::_dynamic_initializer_for__g_header_init_InitializeResultExceptions__(void)

{
  g_pfnRethrow = Rethrow;
  g_pfnThrowResultException = ThrowResultExceptionInternal;
  g_pfnResultFromCaughtExceptionInternal = ResultFromCaughtExceptionInternal;
  return;
}



===== `dynamic_initializer_for_'g_header_init_InitializeResultHeader'' @ 180001050 =====

void wil::details::_dynamic_initializer_for__g_header_init_InitializeResultHeader__(void)

{
  g_pfnGetContextAndNotifyFailure = GetContextAndNotifyFailure;
  details_abi::g_pProcessLocalData =
       (ProcessLocalStorage<wil::details_abi::ProcessLocalData> *)&g_processLocalData;
  g_pThreadFailureCallbacks = &g_threadFailureCallbacks;
  return;
}



===== `dynamic_initializer_for_'g_header_init_WilInitialize_ResultMacros_DesktopOrSystem'' @ 180001090 =====

void wil::details::
     _dynamic_initializer_for__g_header_init_WilInitialize_ResultMacros_DesktopOrSystem__(void)

{
  g_pfnGetModuleName = GetCurrentModuleName;
  g_pfnDebugBreak = DebugBreak;
  g_pfnRaiseFailFastException = WilDynamicLoadRaiseFailFastException;
  g_pfnFormatNtStatusMsg = FormatNtStatusMsg;
  g_pfnNotifyFailure = MicrosoftInternalNotifyFailure;
  g_pfnRtlNtStatusToDosErrorNoTeb = RtlNtStatusToDosErrorNoTeb;
  g_pfnDllShutdownInProgress = RtlDllShutdownInProgress;
  return;
}



===== `dynamic_initializer_for_'g_processLocalData'' @ 180001100 =====

void wil::details::_dynamic_initializer_for__g_processLocalData__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_processLocalData__);
  return;
}



===== `dynamic_atexit_destructor_for_'g_threadFailureCallbacks'' @ 180001120 =====

void wil::details::_dynamic_atexit_destructor_for__g_threadFailureCallbacks__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_threadFailureCallbacks__);
  return;
}



===== `dynamic_initializer_for_'g_featureStateManager'' @ 180001140 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wil::details::_dynamic_initializer_for__g_featureStateManager__(void)

{
  InitializeCriticalSectionEx((LPCRITICAL_SECTION)&DAT_180021058,0,0);
  _DAT_1800210a0 = 0;
  _DAT_180021080 = 0;
  uRam0000000180021088 = 0;
  _DAT_180021090 = 0;
  uRam0000000180021098 = 0;
  InitializeCriticalSectionEx((LPCRITICAL_SECTION)&DAT_1800210a8,0,0);
  _DAT_180021110 = 0;
  g_featureStateManager = (shutdown_aware_object<wil::details::FeatureStateManager>)0x1;
  _DAT_1800210d0 = 0;
  uRam00000001800210d8 = 0;
  _DAT_1800210e0 = 0;
  uRam00000001800210e8 = 0;
  _DAT_1800210f0 = 0;
  uRam00000001800210f8 = 0;
  _DAT_180021100 = 0;
  uRam0000000180021108 = 0;
  atexit(_dynamic_atexit_destructor_for__g_featureStateManager__);
  return;
}



===== `dynamic_initializer_for_'g_header_init_InitializeStagingHeaderInternalApi'' @ 1800011e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wil::details::_dynamic_initializer_for__g_header_init_InitializeStagingHeaderInternalApi__
               (void)

{
  _g_wil_details_internalRecordFeatureUsage = WilApiImpl_RecordFeatureUsage;
  _g_wil_details_internalSubscribeFeatureStateChangeNotification =
       WilApiImpl_SubscribeFeatureStateChangeNotification;
  _g_wil_details_internalUnsubscribeFeatureStateChangeNotification =
       WilApiImpl_UnsubscribeFeatureStateChangeNotification;
  return;
}



===== __std_find_trivial_8 @ 180001220 =====

ulonglong * __std_find_trivial_8(ulonglong *param_1,ulonglong *param_2,ulonglong param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [32];
  undefined1 auVar8 [16];
  
  uVar5 = (longlong)param_2 - (longlong)param_1;
  if (((uVar5 & 0xffffffffffffffe0) != 0) && ((__isa_enabled >> 5 & 1) != 0)) {
    auVar8._8_8_ = 0;
    auVar8._0_8_ = param_3;
    auVar8 = vpunpcklqdq_avx(auVar8,auVar8);
    puVar4 = (ulonglong *)((uVar5 & 0xffffffffffffffe0) + (longlong)param_1);
    do {
      auVar7._0_8_ = -(ulonglong)(auVar8._0_8_ == *param_1);
      auVar7._8_8_ = -(ulonglong)(auVar8._8_8_ == param_1[1]);
      auVar7._16_8_ = -(ulonglong)(auVar8._0_8_ == param_1[2]);
      auVar7._24_8_ = -(ulonglong)(auVar8._8_8_ == param_1[3]);
      uVar2 = (uint)(SUB321(auVar7 >> 7,0) & 1) | (uint)(SUB321(auVar7 >> 0xf,0) & 1) << 1 |
              (uint)(SUB321(auVar7 >> 0x17,0) & 1) << 2 | (uint)(SUB321(auVar7 >> 0x1f,0) & 1) << 3
              | (uint)(SUB321(auVar7 >> 0x27,0) & 1) << 4 |
              (uint)(SUB321(auVar7 >> 0x2f,0) & 1) << 5 | (uint)(SUB321(auVar7 >> 0x37,0) & 1) << 6
              | (uint)(SUB321(auVar7 >> 0x3f,0) & 1) << 7 |
              (uint)(SUB321(auVar7 >> 0x47,0) & 1) << 8 | (uint)(SUB321(auVar7 >> 0x4f,0) & 1) << 9
              | (uint)(SUB321(auVar7 >> 0x57,0) & 1) << 10 |
              (uint)(SUB321(auVar7 >> 0x5f,0) & 1) << 0xb |
              (uint)(SUB321(auVar7 >> 0x67,0) & 1) << 0xc |
              (uint)(SUB321(auVar7 >> 0x6f,0) & 1) << 0xd |
              (uint)(SUB321(auVar7 >> 0x77,0) & 1) << 0xe | (uint)SUB321(auVar7 >> 0x7f,0) << 0xf |
              (uint)(SUB321(auVar7 >> 0x87,0) & 1) << 0x10 |
              (uint)(SUB321(auVar7 >> 0x8f,0) & 1) << 0x11 |
              (uint)(SUB321(auVar7 >> 0x97,0) & 1) << 0x12 |
              (uint)(SUB321(auVar7 >> 0x9f,0) & 1) << 0x13 |
              (uint)(SUB321(auVar7 >> 0xa7,0) & 1) << 0x14 |
              (uint)(SUB321(auVar7 >> 0xaf,0) & 1) << 0x15 |
              (uint)(SUB321(auVar7 >> 0xb7,0) & 1) << 0x16 | (uint)SUB321(auVar7 >> 0xbf,0) << 0x17
              | (uint)((byte)(auVar7._24_8_ >> 7) & 1) << 0x18 |
              (uint)((byte)(auVar7._24_8_ >> 0xf) & 1) << 0x19 |
              (uint)((byte)(auVar7._24_8_ >> 0x17) & 1) << 0x1a |
              (uint)((byte)(auVar7._24_8_ >> 0x1f) & 1) << 0x1b |
              (uint)((byte)(auVar7._24_8_ >> 0x27) & 1) << 0x1c |
              (uint)((byte)(auVar7._24_8_ >> 0x2f) & 1) << 0x1d |
              (uint)((byte)(auVar7._24_8_ >> 0x37) & 1) << 0x1e |
              (uint)(byte)(auVar7._24_8_ >> 0x3f) << 0x1f;
      if (uVar2 != 0) {
        uVar3 = 0;
        for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
          uVar3 = uVar3 + 1;
        }
        return (ulonglong *)((ulonglong)uVar3 + (longlong)param_1);
      }
      param_1 = param_1 + 4;
    } while (param_1 != puVar4);
    uVar5 = (ulonglong)((uint)uVar5 & 0x1f);
  }
  if (((uVar5 & 0xfffffffffffffff0) != 0) && ((__isa_enabled >> 2 & 1) != 0)) {
    puVar4 = (ulonglong *)((uVar5 & 0xfffffffffffffff0) + (longlong)param_1);
    do {
      auVar6._0_8_ = -(ulonglong)(*param_1 == param_3);
      auVar6._8_8_ = -(ulonglong)(param_1[1] == param_3);
      uVar1 = (ushort)(SUB161(auVar6 >> 7,0) & 1) | (ushort)(SUB161(auVar6 >> 0xf,0) & 1) << 1 |
              (ushort)(SUB161(auVar6 >> 0x17,0) & 1) << 2 |
              (ushort)(SUB161(auVar6 >> 0x1f,0) & 1) << 3 |
              (ushort)(SUB161(auVar6 >> 0x27,0) & 1) << 4 |
              (ushort)(SUB161(auVar6 >> 0x2f,0) & 1) << 5 |
              (ushort)(SUB161(auVar6 >> 0x37,0) & 1) << 6 |
              (ushort)(SUB161(auVar6 >> 0x3f,0) & 1) << 7 |
              (ushort)((byte)(auVar6._8_8_ >> 7) & 1) << 8 |
              (ushort)((byte)(auVar6._8_8_ >> 0xf) & 1) << 9 |
              (ushort)((byte)(auVar6._8_8_ >> 0x17) & 1) << 10 |
              (ushort)((byte)(auVar6._8_8_ >> 0x1f) & 1) << 0xb |
              (ushort)((byte)(auVar6._8_8_ >> 0x27) & 1) << 0xc |
              (ushort)((byte)(auVar6._8_8_ >> 0x2f) & 1) << 0xd |
              (ushort)((byte)(auVar6._8_8_ >> 0x37) & 1) << 0xe |
              (ushort)(byte)(auVar6._8_8_ >> 0x3f) << 0xf;
      if (uVar1 != 0) {
        uVar2 = 0;
        if (uVar1 != 0) {
          for (; (uVar1 >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
          }
        }
        return (ulonglong *)((ulonglong)uVar2 + (longlong)param_1);
      }
      param_1 = param_1 + 2;
    } while (param_1 != puVar4);
  }
  for (; (param_1 != param_2 && (*param_1 != param_3)); param_1 = param_1 + 1) {
  }
  return param_1;
}



===== initialize_legacy_wide_specifiers @ 180001300 =====

undefined8 initialize_legacy_wide_specifiers(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 4;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return 0;
}



===== __local_stdio_printf_options @ 180001324 =====

__uint64 * __local_stdio_printf_options(void)

{
  return &`__local_stdio_printf_options'::__l2::_OptionsStorage;
}



===== __local_stdio_scanf_options @ 180001334 =====

__uint64 * __local_stdio_scanf_options(void)

{
  return &`__local_stdio_scanf_options'::__l2::_OptionsStorage;
}



===== initialize_msvcrt_compatibility @ 180001350 =====

undefined8 initialize_msvcrt_compatibility(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x18;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 4;
  return 0;
}



===== dllmain_crt_dispatch @ 180001380 =====

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



===== dllmain_crt_process_attach @ 1800013d8 =====

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
      DAT_180021410 = DAT_180021410 + 1;
      return 1;
    }
  }
  return 0;
}



===== dllmain_crt_process_detach @ 1800014f0 =====

undefined1 dllmain_crt_process_detach(undefined8 param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined7 uVar3;
  
  uVar1 = (undefined1)param_1;
  if (DAT_180021410 < 1) {
    uVar1 = 0;
  }
  else {
    DAT_180021410 = DAT_180021410 + -1;
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



===== dllmain_dispatch @ 180001578 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00018000163b) */
/* WARNING: Removing unreachable block (ram,0x0001800015cb) */
/* WARNING: Removing unreachable block (ram,0x00018000167d) */

ulonglong dllmain_dispatch(HMODULE param_1,int param_2,longlong param_3)

{
  bool bVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  if ((param_2 == 0) && (DAT_180021410 < 1)) {
    return 0;
  }
  if (param_2 - 1U < 2) {
    uVar2 = dllmain_crt_dispatch(param_1,param_2,param_3);
    if ((int)uVar2 == 0) {
      return uVar2 & 0xffffffff;
    }
  }
  bVar1 = DllMain(param_1,param_2);
  uVar2 = CONCAT71(extraout_var,bVar1) & 0xffffffff;
  if ((param_2 == 1) && ((int)CONCAT71(extraout_var,bVar1) == 0)) {
    DllMain(param_1,0);
    dllmain_crt_dispatch(param_1,0,param_3);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    uVar3 = dllmain_crt_dispatch(param_1,param_2,param_3);
    uVar2 = uVar3 & 0xffffffff;
    if ((int)uVar3 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== entry @ 1800016b0 =====

void entry(HMODULE param_1,int param_2,longlong param_3)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}



===== __security_check_cookie @ 180001700 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __scrt_acquire_startup_lock @ 180001724 =====

ulonglong __scrt_acquire_startup_lock(void)

{
  bool bVar1;
  undefined7 extraout_var;
  void *pvVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  pvVar2 = (void *)CONCAT71(extraout_var,bVar1);
  if ((int)pvVar2 == 0) {
LAB_180001752:
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
      if (bVar1) goto LAB_180001752;
    } while (StackBase != pvVar2);
    uVar3 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  return uVar3;
}



===== __scrt_dllmain_after_initialize_c @ 180001764 =====

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



===== __scrt_dllmain_before_initialize_c @ 1800017a0 =====

bool __scrt_dllmain_before_initialize_c(void)

{
  undefined8 uVar1;
  
  uVar1 = __scrt_initialize_onexit_tables(0);
  return (char)uVar1 != '\0';
}



===== __scrt_dllmain_crt_thread_attach @ 1800017bc =====

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



===== __scrt_dllmain_crt_thread_detach @ 1800017ec =====

undefined1 __scrt_dllmain_crt_thread_detach(void)

{
  __vcrt_thread_attach();
  __vcrt_thread_attach();
  return 1;
}



===== __scrt_dllmain_exception_filter @ 180001808 =====

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



===== __scrt_dllmain_uninitialize_c @ 180001870 =====

void __scrt_dllmain_uninitialize_c(void)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((int)CONCAT71(extraout_var,bVar1) != 0) {
    _o__execute_onexit_table(&DAT_180021420);
    return;
  }
  uVar2 = _is_c_termination_complete();
  if ((int)uVar2 == 0) {
    _cexit();
  }
  return;
}



===== __scrt_dllmain_uninitialize_critical @ 1800018a8 =====

void __scrt_dllmain_uninitialize_critical(void)

{
  __vcrt_thread_attach();
  __vcrt_thread_attach();
  return;
}



===== __scrt_initialize_crt @ 1800018c4 =====

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_180021451 = 1;
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



===== __scrt_initialize_onexit_tables @ 180001904 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  
  if (DAT_180021450 == '\0') {
    if (1 < param_1) {
                    /* WARNING: Subroutine does not return */
      __scrt_fastfail(5);
    }
    bVar1 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar1) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_180021420 = 0xffffffffffffffff;
      uRam0000000180021428 = 0xffffffffffffffff;
      _DAT_180021430 = 0xffffffffffffffff;
      _DAT_180021438 = 0xffffffffffffffff;
      uRam0000000180021440 = 0xffffffffffffffff;
      _DAT_180021448 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _o__initialize_onexit_table(&DAT_180021420);
      if (((int)in_RAX != 0) ||
         (in_RAX = _o__initialize_onexit_table(&DAT_180021438), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_180021450 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== __scrt_is_nonwritable_in_current_image @ 180001998 =====

/* WARNING: Removing unreachable block (ram,0x000180001a25) */
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
       param_1 - 0x180000000U < uVar1)) goto LAB_180001a0e;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_180001a0e:
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



===== __scrt_release_startup_lock @ 180001a38 =====

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



===== __scrt_uninitialize_crt @ 180001a64 =====

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_180021451 == '\0') || (param_2 == '\0')) {
    __vcrt_thread_attach();
    __vcrt_thread_attach();
  }
  return 1;
}



===== _onexit @ 180001a94 =====

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_180021420 == -1) {
    iVar1 = _o__crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_180021420);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}



===== atexit @ 180001ad4 =====

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



===== operator_delete @ 180001af4 =====

/* void __cdecl operator delete(void * __ptr64,unsigned __int64) */

void __cdecl operator_delete(void *param_1,__uint64 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0001800023f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_free();
  return;
}



===== `vector_deleting_destructor' @ 180001b00 =====

/* public: virtual void * __ptr64 __cdecl type_info::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall type_info::_vector_deleting_destructor_(type_info *this,uint param_1)

{
  *(undefined ***)this = _vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== operator_new @ 180001b2c =====

/* void * __ptr64 __cdecl operator new(unsigned __int64) */

void * __cdecl operator_new(__uint64 param_1)

{
  int iVar1;
  void *pvVar2;
  
  do {
    pvVar2 = (void *)malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    iVar1 = _callnewh(param_1);
  } while (iVar1 != 0);
  if (param_1 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    std::_Throw_bad_array_new_length();
  }
                    /* WARNING: Subroutine does not return */
  __scrt_throw_std_bad_alloc();
}



===== __GSHandlerCheck @ 180001b70 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 180001b94 =====

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



===== __isa_available_init @ 180001bf8 =====

/* WARNING: Removing unreachable block (ram,0x000180001cc2) */
/* WARNING: Removing unreachable block (ram,0x000180001c32) */
/* WARNING: Removing unreachable block (ram,0x000180001c0b) */
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



===== __security_init_cookie @ 180001dac =====

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



===== __scrt_initialize_type_info @ 180001e64 =====

/* void __cdecl __scrt_initialize_type_info(void) */

void __cdecl __scrt_initialize_type_info(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180001e6b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&__type_info_root_node);
  return;
}



===== __scrt_uninitialize_type_info @ 180001e78 =====

/* void __cdecl __scrt_uninitialize_type_info(void) */

void __cdecl __scrt_uninitialize_type_info(void)

{
  _o___std_type_info_destroy_list(&__type_info_root_node);
  return;
}



===== __scrt_initialize_default_local_stdio_options @ 180001e8c =====

void __scrt_initialize_default_local_stdio_options(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x24;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return;
}



===== __scrt_get_dyn_tls_init_callback @ 180001eb0 =====

undefined * __scrt_get_dyn_tls_init_callback(void)

{
  return &__dyn_tls_init_callback;
}



===== __crt_debugger_hook @ 180001ec0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __crt_debugger_hook(int param_1)

{
  ___scrt_debugger_hook_flag = 0;
  return;
}



===== __scrt_fastfail @ 180001ed0 =====

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
  *(undefined8 *)(puVar4 + -8) = 0x180001f04;
  __crt_debugger_hook(3);
  *(undefined8 *)(puVar4 + -8) = 0x180001f15;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x180001f1f;
  RtlCaptureContext(local_4d8);
  local_res10 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x180001f41;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    local_res18 = 0;
    local_res20 = 0;
    *(undefined8 **)(puVar4 + 0x30) = &local_res18;
    *(undefined8 **)(puVar4 + 0x28) = &local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x180001f92;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = auStack_5c8 + 0x5d0;
  *(undefined8 *)(puVar4 + -8) = 0x180001fc4;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x180001fe6;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x180002003;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x18000200e;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x18000201f;
    __crt_debugger_hook(3);
  }
  return;
}



===== _RTC_Initialize @ 180002038 =====

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



===== _RTC_Terminate @ 18000207c =====

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



===== __raise_securityfailure @ 1800020c8 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x0001800020f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



===== __report_gsfailure @ 180002110 =====

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
  *(undefined8 *)(puVar3 + -8) = 0x18000213b;
  capture_previous_context((PCONTEXT)&DAT_180021520);
  _DAT_180021490 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_1800215b8 = puVar3 + 0x40;
  _DAT_1800215a0 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_180021480 = 0xc0000409;
  _DAT_180021484 = 1;
  _DAT_180021498 = 1;
  DAT_1800214a0 = 2;
  *(undefined8 *)(puVar3 + 0x20) = __security_cookie;
  *(undefined8 *)(puVar3 + 0x28) = __security_cookie_complement;
  *(undefined8 *)(puVar3 + -8) = 0x1800021dd;
  DAT_180021618 = _DAT_180021490;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_18001a010);
  return;
}



===== capture_previous_context @ 1800021e8 =====

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



===== _get_startup_argv_mode @ 180002274 =====

undefined8 _get_startup_argv_mode(void)

{
  return 1;
}



===== __scrt_is_ucrt_dll_in_use @ 180002280 =====

bool __scrt_is_ucrt_dll_in_use(void)

{
  return __scrt_ucrt_dll_is_in_use != 0;
}



===== operator_delete @ 180002294 =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800023f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_free();
  return;
}



===== bad_alloc @ 1800022a0 =====

/* public: __cdecl std::bad_alloc::bad_alloc(void) __ptr64 */

bad_alloc * __thiscall std::bad_alloc::bad_alloc(bad_alloc *this)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(char **)(this + 8) = "bad allocation";
  *(undefined ***)this = _vftable_;
  return this;
}



===== __scrt_throw_std_bad_alloc @ 1800022c4 =====

/* void __cdecl __scrt_throw_std_bad_alloc(void) */

void __cdecl __scrt_throw_std_bad_alloc(void)

{
  bad_alloc local_28 [40];
  
  std::bad_alloc::bad_alloc(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&_TI2_AVbad_alloc_std__);
}



===== _guard_check_icall @ 1800022f0 =====

void _guard_check_icall(void)

{
  return;
}



===== _initterm @ 180002306 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002306. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== _initterm_e @ 180002312 =====

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002312. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}



===== __CxxFrameHandler4 @ 18000231e =====

void __CxxFrameHandler4(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000231e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __CxxFrameHandler4();
  return;
}



===== __std_exception_copy @ 180002336 =====

void __std_exception_copy(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002336. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___std_exception_copy();
  return;
}



===== __std_exception_destroy @ 180002342 =====

void __std_exception_destroy(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002342. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___std_exception_destroy();
  return;
}



===== _o___std_type_info_destroy_list @ 18000234e =====

void _o___std_type_info_destroy_list(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000234e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___std_type_info_destroy_list();
  return;
}



===== __stdio_common_vswprintf @ 18000235a =====

void __stdio_common_vswprintf(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000235a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___stdio_common_vswprintf();
  return;
}



===== _callnewh @ 180002366 =====

void _callnewh(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002366. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__callnewh();
  return;
}



===== _cexit @ 180002372 =====

void _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002372. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__cexit();
  return;
}



===== _configure_narrow_argv @ 18000237e =====

void _configure_narrow_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000237e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configure_narrow_argv();
  return;
}



===== _o__crt_atexit @ 18000238a =====

void _o__crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000238a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__crt_atexit();
  return;
}



===== _o__execute_onexit_table @ 180002396 =====

void _o__execute_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002396. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__execute_onexit_table();
  return;
}



===== _o__initialize_narrow_environment @ 1800023a2 =====

void _o__initialize_narrow_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800023a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_narrow_environment();
  return;
}



===== _o__initialize_onexit_table @ 1800023ae =====

void _o__initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800023ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_onexit_table();
  return;
}



===== _o__invalid_parameter_noinfo @ 1800023ba =====

void _o__invalid_parameter_noinfo(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800023ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__invalid_parameter_noinfo();
  return;
}



===== _o__purecall @ 1800023d0 =====

void _o__purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800023d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__purecall();
  return;
}



===== _register_onexit_function @ 1800023dc =====

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800023dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__register_onexit_function();
  return;
}



===== _seh_filter_dll @ 1800023e8 =====

void _seh_filter_dll(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800023e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__seh_filter_dll();
  return;
}



===== _o_free @ 1800023f4 =====

void _o_free(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800023f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_free();
  return;
}



===== malloc @ 180002400 =====

void malloc(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_malloc();
  return;
}



===== terminate @ 18000240c =====

void terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000240c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_terminate();
  return;
}



===== __C_specific_handler @ 180002418 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180002418. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __current_exception @ 180002424 =====

void __current_exception(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002424. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception();
  return;
}



===== __current_exception_context @ 180002430 =====

void __current_exception_context(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180002430. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception_context();
  return;
}



===== memset @ 18000243c =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000243c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== _CxxThrowException @ 180002448 =====

void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    /* WARNING: Could not recover jumptable at 0x000180002448. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}



===== _vsnwprintf @ 180002454 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  __uint64 *p_Var2;
  
  p_Var2 = __local_stdio_printf_options();
  iVar1 = __stdio_common_vswprintf(*p_Var2 | 1,_Dest,_Count,_Format,0,_Args);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}



===== __scrt_initialize_thread_safe_statics @ 1800024c0 =====

undefined8 __scrt_initialize_thread_safe_statics(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  FARPROC pFVar2;
  undefined8 uVar3;
  
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_180021a00,4000);
  hModule = GetModuleHandleW(L"api-ms-win-core-synch-l1-2-0.dll");
  if (hModule == (HMODULE)0x0) {
    hModule = GetModuleHandleW(L"kernel32.dll");
    if (hModule == (HMODULE)0x0) goto LAB_180002585;
  }
  pFVar1 = GetProcAddress(hModule,"SleepConditionVariableCS");
  pFVar2 = GetProcAddress(hModule,"WakeAllConditionVariable");
  if ((pFVar1 == (FARPROC)0x0) || (pFVar2 == (FARPROC)0x0)) {
    DAT_1800219f8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    if (DAT_1800219f8 == (HANDLE)0x0) goto LAB_180002585;
  }
  else {
    DAT_180021a28 = pFVar1;
    DAT_180021a30 = pFVar2;
  }
  uVar3 = __scrt_initialize_onexit_tables(0);
  if ((char)uVar3 != '\0') {
    atexit(__scrt_uninitialize_thread_safe_statics);
    return 0;
  }
LAB_180002585:
                    /* WARNING: Subroutine does not return */
  __scrt_fastfail(7);
}



===== __scrt_uninitialize_thread_safe_statics @ 1800025a0 =====

void __scrt_uninitialize_thread_safe_statics(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_180021a00);
  if (DAT_1800219f8 != (HANDLE)0x0) {
    CloseHandle(DAT_1800219f8);
  }
  return;
}



===== _Init_thread_abort @ 1800025d0 =====

void _Init_thread_abort(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_180021a00);
  *param_1 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180021a00);
  _Init_thread_notify();
  return;
}



===== _Init_thread_footer @ 180002608 =====

void _Init_thread_footer(int *param_1)

{
  ulonglong uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_180021a00);
  uVar1 = (ulonglong)_tls_index;
  _Init_global_epoch = _Init_global_epoch + 1;
  *param_1 = _Init_global_epoch;
  *(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + uVar1 * 8) + 4) = _Init_global_epoch;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180021a00);
  _Init_thread_notify();
  return;
}



===== _Init_thread_header @ 180002670 =====

void _Init_thread_header(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_180021a00);
  do {
    if (*param_1 == 0) {
      *param_1 = -1;
LAB_1800026bf:
                    /* WARNING: Could not recover jumptable at 0x0001800026cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180021a00);
      return;
    }
    if (*param_1 != -1) {
      *(undefined4 *)
       (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) =
           _Init_global_epoch;
      goto LAB_1800026bf;
    }
    _Init_thread_wait_v2();
  } while( true );
}



===== _Init_thread_notify @ 1800026d8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _Init_thread_notify(void)

{
  if (DAT_180021a30 == (code *)0x0) {
    SetEvent(DAT_1800219f8);
                    /* WARNING: Could not recover jumptable at 0x000180002710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ResetEvent(DAT_1800219f8);
    return;
  }
  (*DAT_180021a30)(&DAT_1800219f0);
  return;
}



===== _Init_thread_wait_v2 @ 180002720 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _Init_thread_wait_v2(void)

{
  if (DAT_180021a28 == (code *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_180021a00);
    WaitForSingleObjectEx(DAT_1800219f8,100,0);
                    /* WARNING: Could not recover jumptable at 0x000180002777. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_180021a00);
    return;
  }
  (*DAT_180021a28)(&DAT_1800219f0,&DAT_180021a00,0xffffffff);
  return;
}



===== `eh_vector_destructor_iterator' @ 180002784 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl `eh vector destructor iterator'(void * __ptr64,unsigned __int64,unsigned
   __int64,void (__cdecl*)(void * __ptr64)) */

void __cdecl
_eh_vector_destructor_iterator_
          (void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4)

{
  void *pvVar1;
  
  pvVar1 = (void *)(param_2 * param_3 + (longlong)param_1);
  while( true ) {
    if (param_3 == 0) break;
    pvVar1 = (void *)((longlong)pvVar1 - param_2);
    (*param_4)(pvVar1);
    param_3 = param_3 - 1;
  }
  return;
}



===== __ArrayUnwind @ 1800027f4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl __ArrayUnwind(void * __ptr64,unsigned __int64,unsigned __int64,void (__cdecl*)(void
   * __ptr64)) */

void __cdecl
__ArrayUnwind(void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4)

{
  __uint64 _Var1;
  
  for (_Var1 = 0; _Var1 != param_3; _Var1 = _Var1 + 1) {
    param_1 = (void *)((longlong)param_1 - param_2);
    (*param_4)(param_1);
  }
  return;
}



===== __vcrt_thread_attach @ 18000285c =====

undefined1 __vcrt_thread_attach(void)

{
  return 1;
}



===== _is_c_termination_complete @ 180002868 =====

undefined8 _is_c_termination_complete(void)

{
  return 0;
}



===== ReportFailure_Base<1,0> @ 180002874 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl wil::details::ReportFailure_Base<1,0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Base<1,0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  BOOL BVar1;
  bool bVar2;
  undefined1 auStack_1508 [32];
  undefined4 uStack_14e8;
  uint uStack_14e4;
  long lStack_14e0;
  undefined4 uStack_14dc;
  int iStack_14d8;
  ushort *puStack_14d0;
  DWORD DStack_14c8;
  undefined8 uStack_14c0;
  undefined8 uStack_14b8;
  char *pcStack_14b0;
  uint uStack_14a8;
  int iStack_14a4;
  undefined8 uStack_14a0;
  undefined8 uStack_1498;
  undefined8 uStack_1490;
  undefined8 uStack_1488;
  undefined8 uStack_1480;
  undefined8 uStack_1478;
  undefined8 uStack_1470;
  char *pcStack_1468;
  void *pvStack_1460;
  void *pvStack_1458;
  char acStack_1448 [1024];
  WCHAR aWStack_1048 [2048];
  ulonglong uStack_48;
  undefined8 uStack_40;
  
  uStack_40 = 0x180002e19;
  uStack_48 = __security_cookie ^ (ulonglong)auStack_1508;
  memset(&uStack_14e8,0,0x98);
  aWStack_1048[0] = L'\0';
  acStack_1448[0] = '\0';
  lStack_14e0 = *(long *)param_7;
  uStack_14dc = *(undefined4 *)(param_7 + 4);
  iStack_14a4 = RecordReturn(lStack_14e0);
  uStack_14e8 = 1;
  uStack_14e4 = 0;
  if (*(int *)(param_7 + 8) == 1) {
    uStack_14e4 = 8;
  }
  LOCK();
  UNLOCK();
  iStack_14d8 = `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
                ::__l2::s_failureId + 1;
  if ((param_8 == (ushort *)0x0) || (puStack_14d0 = param_8, *param_8 == 0)) {
    puStack_14d0 = (ushort *)0x0;
  }
  `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
  ::__l2::s_failureId =
       `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
       ::__l2::s_failureId + 1;
  DStack_14c8 = GetCurrentThreadId();
  uStack_14c0 = 0;
  uStack_14b8 = 0;
  pvStack_1460 = param_6;
  uStack_14a0 = 0;
  uStack_1480 = 0;
  uStack_1478 = 0;
  uStack_1470 = 0;
  uStack_1498 = 0;
  uStack_1490 = 0;
  uStack_1488 = 0;
  pcStack_14b0 = param_3;
  uStack_14a8 = param_2;
  pvStack_1458 = param_1;
  if (g_pfnGetModuleName == (_func_char_ptr *)0x0) {
    pcStack_1468 = (char *)0x0;
  }
  else {
    pcStack_1468 = (*g_pfnGetModuleName)();
  }
  if (g_pfnNotifyFailure != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnNotifyFailure)((FailureInfo *)&uStack_14e8);
  }
  if (g_pfnGetContextAndNotifyFailure != (_func_void_FailureInfo_ptr_char_ptr___uint64 *)0x0) {
    (*g_pfnGetContextAndNotifyFailure)((FailureInfo *)&uStack_14e8,acStack_1448,0x400);
  }
  if (g_pfnLoggingCallback != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnLoggingCallback)((FailureInfo *)&uStack_14e8);
  }
  if ((g_pfnOriginateCallback != (_func_void_FailureInfo_ptr *)0x0) && ((uStack_14e4 & 2) == 0)) {
    (*g_pfnOriginateCallback)((FailureInfo *)&uStack_14e8);
  }
  if (-1 < lStack_14e0) {
                    /* WARNING: Subroutine does not return */
    wistd::__throw_bad_function_call();
  }
  if (g_fIsDebuggerPresent == false) {
    if (g_pfnIsDebuggerPresent == (_func_bool *)0x0) {
      BVar1 = IsDebuggerPresent();
      bVar2 = BVar1 == 0;
    }
    else {
      bVar2 = (*g_pfnIsDebuggerPresent)();
      bVar2 = !bVar2;
    }
    if (!bVar2) goto LAB_180002fcd;
  }
  else {
LAB_180002fcd:
    if ((uStack_14e4 & 2) == 0) {
      if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
        (*g_pfnResultLoggingCallback)(&uStack_14e8,aWStack_1048,0x800);
      }
      if (aWStack_1048[0] == L'\0') {
        GetFailureLogString((ushort *)aWStack_1048,0x800,(FailureInfo *)&uStack_14e8);
      }
      OutputDebugStringW(aWStack_1048);
      goto LAB_180003059;
    }
  }
  if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
    (*g_pfnResultLoggingCallback)(&uStack_14e8,0,0);
  }
LAB_180003059:
  if ((((uStack_14e4 & 4) != 0) || (g_fBreakOnFailure != false)) &&
     (g_pfnDebugBreak != (_func_void *)0x0)) {
    (*g_pfnDebugBreak)();
  }
  if ((uStack_14e4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    WilFailFast((FailureInfo *)&uStack_14e8);
  }
  return;
}



===== ReportFailure_Base<2,0> @ 180002880 =====

/* void __cdecl wil::details::ReportFailure_Base<2,0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Base<2,0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  ReportFailureOptions in_stack_ffffffffffffffe8;
  
  ReportFailure_Return<2>
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,(ushort *)0x0,
             in_stack_ffffffffffffffe8);
  return;
}



===== ReportFailure_Base<3,0> @ 1800028c4 =====

/* void __cdecl wil::details::ReportFailure_Base<3,0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Base<3,0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  code *pcVar1;
  char *in_stack_ffffffffffffffc8;
  ReportFailureOptions in_stack_ffffffffffffffe8;
  
  ReportFailure_NoReturn<3>
            (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffc8,param_6,param_7,param_8,
             in_stack_ffffffffffffffe8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ReportFailure_GetLastError<3> @ 1800028fc =====

/* unsigned long __cdecl wil::details::ReportFailure_GetLastError<3>(void * __ptr64,unsigned
   int,char const * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64) */

ulong __cdecl
wil::details::ReportFailure_GetLastError<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6)

{
  undefined8 *puVar1;
  char *in_stack_ffffffffffffffa8;
  ReportFailureOptions in_stack_ffffffffffffffc8;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_18 [16];
  
  GetLastErrorFail(param_1,param_2,"onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h",
                   param_4,in_stack_ffffffffffffffa8,param_6);
  puVar1 = (undefined8 *)ResultStatus::FromResult((long)local_18);
  local_28 = *puVar1;
  local_20 = *(undefined4 *)(puVar1 + 1);
                    /* WARNING: Subroutine does not return */
  ReportFailure_Base<3,0>
            (param_1,param_2,"onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h",param_4,
             in_stack_ffffffffffffffa8,param_6,(ResultStatus *)&local_28,(ushort *)0x0,
             in_stack_ffffffffffffffc8);
}



===== ReportFailure_GetLastErrorHr<1> @ 180002980 =====

/* long __cdecl wil::details::ReportFailure_GetLastErrorHr<1>(void * __ptr64,unsigned int,char const
   * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64) */

long __cdecl
wil::details::ReportFailure_GetLastErrorHr<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6)

{
  DWORD DVar1;
  char *in_stack_ffffffffffffffb8;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  uint local_18;
  long local_14;
  undefined4 local_10;
  
  DVar1 = GetLastError();
  if (DVar1 == 0) {
    in_stack_ffffffffffffffb8 = (char *)0x0;
    param_4 = (char *)0x0;
    ReportFailure_Hr<2>(param_1,param_2,"wil",(char *)0x0,(char *)0x0,param_6,-0x7ff8fd64);
    DVar1 = 0x29c;
  }
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  local_18 = DVar1;
  local_14 = HrToNtStatus(DVar1);
  local_10 = 0;
  ReportFailure_Base<1,0>
            (param_1,param_2,"wil",param_4,in_stack_ffffffffffffffb8,param_6,
             (ResultStatus *)&local_18,(ushort *)0x0,in_stack_ffffffffffffffd8);
  return DVar1;
}



===== ReportFailure_Hr<1> @ 180002a48 =====

/* void __cdecl wil::details::ReportFailure_Hr<1>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

void __cdecl
wil::details::ReportFailure_Hr<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  char *pcVar1;
  char *in_stack_ffffffffffffffb8;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  long local_18;
  long local_14;
  undefined4 local_10;
  
  pcVar1 = (char *)(ulonglong)param_2;
  local_18 = param_7;
  local_14 = HrToNtStatus(param_7);
  local_10 = 0;
  ReportFailure_Base<1,0>
            (param_1,(uint)pcVar1,"wil",pcVar1,in_stack_ffffffffffffffb8,param_6,
             (ResultStatus *)&local_18,(ushort *)0x0,in_stack_ffffffffffffffd8);
  return;
}



===== ReportFailure_Hr<2> @ 180002aa8 =====

/* void __cdecl wil::details::ReportFailure_Hr<2>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

void __cdecl
wil::details::ReportFailure_Hr<2>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  ushort *in_stack_ffffffffffffffd0;
  ReportFailureOptions in_stack_ffffffffffffffd8;
  long local_18;
  long local_14;
  undefined4 local_10;
  
  local_18 = param_7;
  local_14 = HrToNtStatus(param_7);
  local_10 = 0;
  ReportFailure_Base<2,0>
            (param_1,param_2,param_3,param_4,param_5,param_6,(ResultStatus *)&local_18,
             in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8);
  return;
}



===== ReportFailure_Hr<3> @ 180002b08 =====

/* void __cdecl wil::details::ReportFailure_Hr<3>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

void __cdecl
wil::details::ReportFailure_Hr<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  undefined8 *puVar1;
  char *in_stack_ffffffffffffffa8;
  ReportFailureOptions in_stack_ffffffffffffffc8;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_18 [24];
  
  puVar1 = (undefined8 *)ResultStatus::FromResult((long)local_18);
  local_28 = *puVar1;
  local_20 = *(undefined4 *)(puVar1 + 1);
                    /* WARNING: Subroutine does not return */
  ReportFailure_Base<3,0>
            (param_1,param_2,param_3,param_3,in_stack_ffffffffffffffa8,param_6,
             (ResultStatus *)&local_28,(ushort *)0x0,in_stack_ffffffffffffffc8);
}



===== ReportFailure_NoReturn<3> @ 180002b68 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::ReportFailure_NoReturn<3>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_NoReturn<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  BOOL BVar1;
  bool bVar2;
  undefined4 local_14d8;
  uint local_14d4;
  int local_14d0;
  long local_14cc;
  int local_14c8;
  ushort *local_14c0;
  DWORD local_14b8;
  undefined8 local_14b0;
  undefined8 local_14a8;
  char *local_14a0;
  uint local_1498;
  int local_1494;
  undefined8 local_1490;
  undefined8 local_1488;
  undefined8 uStack_1480;
  undefined8 local_1478;
  undefined8 local_1470;
  undefined8 uStack_1468;
  undefined8 local_1460;
  char *local_1458;
  void *local_1450;
  void *local_1448;
  char local_1438 [1024];
  WCHAR local_1038 [2044];
  undefined8 uStack_40;
  
  uStack_40 = 0x180002b8a;
  memset(&local_14d8,0,0x98);
  local_1038[0] = L'\0';
  local_1438[0] = '\0';
  local_14d0 = *(int *)param_7;
  local_14cc = *(long *)(param_7 + 4);
  local_1494 = RecordFailFast(local_14d0);
  local_14d8 = 3;
  local_14d4 = 0;
  if (*(int *)(param_7 + 8) == 1) {
    local_14d4 = 8;
  }
  LOCK();
  UNLOCK();
  local_14c8 = `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
               ::__l2::s_failureId + 1;
  if ((param_8 == (ushort *)0x0) || (local_14c0 = param_8, *param_8 == 0)) {
    local_14c0 = (ushort *)0x0;
  }
  `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
  ::__l2::s_failureId =
       `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
       ::__l2::s_failureId + 1;
  local_14b8 = GetCurrentThreadId();
  local_14b0 = 0;
  local_14a8 = 0;
  local_1450 = param_6;
  local_1490 = 0;
  local_1470 = 0;
  uStack_1468 = 0;
  local_1460 = 0;
  local_1488 = 0;
  uStack_1480 = 0;
  local_1478 = 0;
  local_14a0 = param_3;
  local_1498 = param_2;
  local_1448 = param_1;
  if (g_pfnGetModuleName == (_func_char_ptr *)0x0) {
    local_1458 = (char *)0x0;
  }
  else {
    local_1458 = (*g_pfnGetModuleName)();
  }
  if (g_pfnNotifyFailure != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnNotifyFailure)((FailureInfo *)&local_14d8);
  }
  if (g_pfnGetContextAndNotifyFailure != (_func_void_FailureInfo_ptr_char_ptr___uint64 *)0x0) {
    (*g_pfnGetContextAndNotifyFailure)((FailureInfo *)&local_14d8,local_1438,0x400);
  }
  if (g_pfnLoggingCallback != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnLoggingCallback)((FailureInfo *)&local_14d8);
  }
  if ((g_pfnOriginateCallback != (_func_void_FailureInfo_ptr *)0x0) && ((local_14d4 & 2) == 0)) {
    (*g_pfnOriginateCallback)((FailureInfo *)&local_14d8);
  }
  if (-1 < local_14d0) {
    local_14d0 = -0x7fff0001;
    local_14cc = HrToNtStatus(-0x7fff0001);
  }
  if (g_fIsDebuggerPresent == false) {
    if (g_pfnIsDebuggerPresent == (_func_bool *)0x0) {
      BVar1 = IsDebuggerPresent();
      bVar2 = BVar1 == 0;
    }
    else {
      bVar2 = (*g_pfnIsDebuggerPresent)();
      bVar2 = !bVar2;
    }
    if (!bVar2) goto LAB_180002d3a;
  }
  else {
LAB_180002d3a:
    if ((local_14d4 & 2) == 0) {
      if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
        (*g_pfnResultLoggingCallback)(&local_14d8,local_1038,0x800);
      }
      if (local_1038[0] == L'\0') {
        GetFailureLogString((ushort *)local_1038,0x800,(FailureInfo *)&local_14d8);
      }
      OutputDebugStringW(local_1038);
      goto LAB_180002dc6;
    }
  }
  if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
    (*g_pfnResultLoggingCallback)(&local_14d8,0,0);
  }
LAB_180002dc6:
  if ((((local_14d4 & 4) != 0) || (g_fBreakOnFailure != false)) &&
     (g_pfnDebugBreak != (_func_void *)0x0)) {
    (*g_pfnDebugBreak)();
  }
                    /* WARNING: Subroutine does not return */
  WilFailFast((FailureInfo *)&local_14d8);
}



===== ReportFailure_Return<1> @ 180002dfc =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl wil::details::ReportFailure_Return<1>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Return<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  BOOL BVar1;
  bool bVar2;
  undefined1 auStack_1508 [32];
  undefined4 local_14e8;
  uint local_14e4;
  long local_14e0;
  undefined4 local_14dc;
  int local_14d8;
  ushort *local_14d0;
  DWORD local_14c8;
  undefined8 local_14c0;
  undefined8 local_14b8;
  char *local_14b0;
  uint local_14a8;
  int local_14a4;
  undefined8 local_14a0;
  undefined8 local_1498;
  undefined8 uStack_1490;
  undefined8 local_1488;
  undefined8 local_1480;
  undefined8 uStack_1478;
  undefined8 local_1470;
  char *local_1468;
  void *local_1460;
  void *local_1458;
  char local_1448 [1024];
  WCHAR local_1048 [2048];
  ulonglong local_48;
  undefined8 uStack_40;
  
  uStack_40 = 0x180002e19;
  local_48 = __security_cookie ^ (ulonglong)auStack_1508;
  memset(&local_14e8,0,0x98);
  local_1048[0] = L'\0';
  local_1448[0] = '\0';
  local_14e0 = *(long *)param_7;
  local_14dc = *(undefined4 *)(param_7 + 4);
  local_14a4 = RecordReturn(local_14e0);
  local_14e8 = 1;
  local_14e4 = 0;
  if (*(int *)(param_7 + 8) == 1) {
    local_14e4 = 8;
  }
  LOCK();
  UNLOCK();
  local_14d8 = `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
               ::__l2::s_failureId + 1;
  if ((param_8 == (ushort *)0x0) || (local_14d0 = param_8, *param_8 == 0)) {
    local_14d0 = (ushort *)0x0;
  }
  `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
  ::__l2::s_failureId =
       `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
       ::__l2::s_failureId + 1;
  local_14c8 = GetCurrentThreadId();
  local_14c0 = 0;
  local_14b8 = 0;
  local_1460 = param_6;
  local_14a0 = 0;
  local_1480 = 0;
  uStack_1478 = 0;
  local_1470 = 0;
  local_1498 = 0;
  uStack_1490 = 0;
  local_1488 = 0;
  local_14b0 = param_3;
  local_14a8 = param_2;
  local_1458 = param_1;
  if (g_pfnGetModuleName == (_func_char_ptr *)0x0) {
    local_1468 = (char *)0x0;
  }
  else {
    local_1468 = (*g_pfnGetModuleName)();
  }
  if (g_pfnNotifyFailure != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnNotifyFailure)((FailureInfo *)&local_14e8);
  }
  if (g_pfnGetContextAndNotifyFailure != (_func_void_FailureInfo_ptr_char_ptr___uint64 *)0x0) {
    (*g_pfnGetContextAndNotifyFailure)((FailureInfo *)&local_14e8,local_1448,0x400);
  }
  if (g_pfnLoggingCallback != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnLoggingCallback)((FailureInfo *)&local_14e8);
  }
  if ((g_pfnOriginateCallback != (_func_void_FailureInfo_ptr *)0x0) && ((local_14e4 & 2) == 0)) {
    (*g_pfnOriginateCallback)((FailureInfo *)&local_14e8);
  }
  if (-1 < local_14e0) {
                    /* WARNING: Subroutine does not return */
    wistd::__throw_bad_function_call();
  }
  if (g_fIsDebuggerPresent == false) {
    if (g_pfnIsDebuggerPresent == (_func_bool *)0x0) {
      BVar1 = IsDebuggerPresent();
      bVar2 = BVar1 == 0;
    }
    else {
      bVar2 = (*g_pfnIsDebuggerPresent)();
      bVar2 = !bVar2;
    }
    if (!bVar2) goto LAB_180002fcd;
  }
  else {
LAB_180002fcd:
    if ((local_14e4 & 2) == 0) {
      if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
        (*g_pfnResultLoggingCallback)(&local_14e8,local_1048,0x800);
      }
      if (local_1048[0] == L'\0') {
        GetFailureLogString((ushort *)local_1048,0x800,(FailureInfo *)&local_14e8);
      }
      OutputDebugStringW(local_1048);
      goto LAB_180003059;
    }
  }
  if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
    (*g_pfnResultLoggingCallback)(&local_14e8,0,0);
  }
LAB_180003059:
  if ((((local_14e4 & 4) != 0) || (g_fBreakOnFailure != false)) &&
     (g_pfnDebugBreak != (_func_void *)0x0)) {
    (*g_pfnDebugBreak)();
  }
  if ((local_14e4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    WilFailFast((FailureInfo *)&local_14e8);
  }
  return;
}



===== ReportFailure_Return<2> @ 1800030bc =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl wil::details::ReportFailure_Return<2>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Return<2>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  undefined1 auStackY_1578 [32];
  FailureInfo local_14f8 [4];
  byte local_14f4;
  char local_1458 [1024];
  ushort local_1058 [2048];
  ulonglong local_58;
  undefined8 uStack_48;
  
  uStack_48 = 0x1800030d3;
  local_58 = __security_cookie ^ (ulonglong)auStackY_1578;
  memset(local_14f8,0,0x98);
  LogFailure(param_1,param_2,param_3,param_4,param_5,param_6,2,param_7,param_8,false,local_1058,
             0x800,local_1458,0x400,local_14f8);
  if ((local_14f4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    WilFailFast(local_14f8);
  }
  return;
}



===== WriteResultString<unsigned_short_const*___ptr64> @ 1800031d8 =====

/* unsigned char * __ptr64 __cdecl wil::details::WriteResultString<unsigned short const *
   __ptr64>(unsigned char * __ptr64,unsigned char * __ptr64,unsigned short const * __ptr64,unsigned
   short const * __ptr64 * __ptr64) */

uchar * __cdecl
wil::details::WriteResultString<unsigned_short_const*___ptr64>
          (uchar *param_1,uchar *param_2,ushort *param_3,ushort **param_4)

{
  ulonglong _MaxCount;
  longlong lVar1;
  
  if (((param_1 != param_2) && (param_3 != (ushort *)0x0)) && (*param_3 != 0)) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_3[lVar1] != 0);
    _MaxCount = lVar1 * 2 + 2;
    if (_MaxCount <= (ulonglong)((longlong)param_2 - (longlong)param_1)) {
      memcpy_s(param_1,(longlong)param_2 - (longlong)param_1,param_3,_MaxCount);
      if (param_4 != (ushort **)0x0) {
        *param_4 = (ushort *)param_1;
      }
      return param_1 + _MaxCount;
    }
  }
  if (param_4 != (ushort **)0x0) {
    *param_4 = (ushort *)0x0;
  }
  return param_1;
}



===== verify_hresult<long> @ 180003260 =====

/* long __cdecl wil::verify_hresult<long>(long) */

long __cdecl wil::verify_hresult<long>(long param_1)

{
  return param_1;
}



===== ResultException @ 18000326c =====

/* public: __cdecl wil::ResultException::ResultException(struct wil::FailureInfo const & __ptr64)
   __ptr64 */

ResultException * __thiscall
wil::ResultException::ResultException(ResultException *this,FailureInfo *param_1)

{
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  StoredFailureInfo::SetFailureInfo((StoredFailureInfo *)(this + 0x18),param_1);
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined8 *)(this + 200) = 0;
  return this;
}



===== ResultException @ 1800032c0 =====

/* public: __cdecl wil::ResultException::ResultException(class wil::ResultException const & __ptr64)
   __ptr64 */

ResultException * __thiscall
wil::ResultException::ResultException(ResultException *this,ResultException *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  
  *(undefined ***)this = std::exception::_vftable_;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  *(undefined ***)this = &_vftable_;
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x18) = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x20) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x30);
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(this + 0x30) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x40);
  *(undefined8 *)(this + 0x38) = *(undefined8 *)(param_1 + 0x38);
  *(undefined8 *)(this + 0x40) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x50);
  *(undefined8 *)(this + 0x48) = *(undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(this + 0x50) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(this + 0x58) = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(this + 0x60) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x70);
  *(undefined8 *)(this + 0x68) = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(this + 0x70) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x80);
  *(undefined8 *)(this + 0x78) = *(undefined8 *)(param_1 + 0x78);
  *(undefined8 *)(this + 0x80) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x90);
  *(undefined8 *)(this + 0x88) = *(undefined8 *)(param_1 + 0x88);
  *(undefined8 *)(this + 0x90) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0xa0);
  *(undefined8 *)(this + 0x98) = *(undefined8 *)(param_1 + 0x98);
  *(undefined8 *)(this + 0xa0) = uVar2;
  *(undefined8 *)(this + 0xa8) = *(undefined8 *)(param_1 + 0xa8);
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  piVar1 = *(int **)(param_1 + 0xb0);
  uVar2 = *(undefined8 *)(param_1 + 0xb8);
  if (piVar1 != (int *)0x0) {
    *(int **)(this + 0xb0) = piVar1;
    *(undefined8 *)(this + 0xb8) = uVar2;
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined8 *)(this + 200) = 0;
  piVar1 = *(int **)(param_1 + 0xc0);
  uVar2 = *(undefined8 *)(param_1 + 200);
  if (piVar1 != (int *)0x0) {
    *(int **)(this + 0xc0) = piVar1;
    *(undefined8 *)(this + 200) = uVar2;
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  return this;
}



===== exception @ 1800033d4 =====

/* public: __cdecl std::exception::exception(class std::exception const & __ptr64) __ptr64 */

exception * __thiscall std::exception::exception(exception *this,exception *param_1)

{
  *(undefined ***)this = _vftable_;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  return this;
}



===== ~ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> @ 180003410 =====

/* public: __cdecl wil::details_abi::ThreadLocalStorage<class
   wil::details::ThreadFailureCallbackHolder * __ptr64>::~ThreadLocalStorage<class
   wil::details::ThreadFailureCallbackHolder * __ptr64>(void) __ptr64 */

void __thiscall
wil::details_abi::ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>::
~ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>
          (ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *this)

{
  ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *pTVar1;
  LPVOID pvVar2;
  HANDLE hHeap;
  LPVOID lpMem;
  
  pTVar1 = this + 0x50;
  for (; this != pTVar1; this = this + 8) {
    lpMem = *(LPVOID *)this;
    while (lpMem != (LPVOID)0x0) {
      pvVar2 = *(LPVOID *)((longlong)lpMem + 8);
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,lpMem);
      lpMem = pvVar2;
    }
    *(undefined8 *)this = 0;
  }
  return;
}



===== ~ThreadLocalStorage<wil::details_abi::ThreadLocalData> @ 18000348c =====

/* public: __cdecl wil::details_abi::ThreadLocalStorage<struct
   wil::details_abi::ThreadLocalData>::~ThreadLocalStorage<struct
   wil::details_abi::ThreadLocalData>(void) __ptr64 */

void __thiscall
wil::details_abi::ThreadLocalStorage<wil::details_abi::ThreadLocalData>::
~ThreadLocalStorage<wil::details_abi::ThreadLocalData>
          (ThreadLocalStorage<wil::details_abi::ThreadLocalData> *this)

{
  ThreadLocalStorage<wil::details_abi::ThreadLocalData> *pTVar1;
  LPVOID pvVar2;
  HANDLE hHeap;
  LPVOID lpMem;
  
  pTVar1 = this + 0x50;
  for (; this != pTVar1; this = this + 8) {
    lpMem = *(LPVOID *)this;
    while (lpMem != (LPVOID)0x0) {
      pvVar2 = *(LPVOID *)((longlong)lpMem + 8);
      ThreadLocalData::~ThreadLocalData((ThreadLocalData *)((longlong)lpMem + 0x10));
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,lpMem);
      lpMem = pvVar2;
    }
    *(undefined8 *)this = 0;
  }
  return;
}



===== ~ResultException @ 180003510 =====

/* public: virtual __cdecl wil::ResultException::~ResultException(void) __ptr64 */

void __thiscall wil::ResultException::~ResultException(ResultException *this)

{
  int iVar1;
  int *piVar2;
  LPVOID lpMem;
  HANDLE hHeap;
  
  piVar2 = *(int **)(this + 0xc0);
  if (piVar2 != (int *)0x0) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      lpMem = *(LPVOID *)(this + 0xc0);
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,lpMem);
    }
    *(undefined8 *)(this + 0xc0) = 0;
    *(undefined8 *)(this + 200) = 0;
  }
  StoredFailureInfo::~StoredFailureInfo((StoredFailureInfo *)(this + 0x18));
  *(undefined ***)this = std::exception::_vftable_;
  __std_exception_destroy(this + 8);
  return;
}



===== ~SemaphoreValue @ 180003598 =====

/* public: __cdecl wil::details_abi::SemaphoreValue::~SemaphoreValue(void) __ptr64 */

void __thiscall wil::details_abi::SemaphoreValue::~SemaphoreValue(SemaphoreValue *this)

{
  BOOL BVar1;
  char *in_R8;
  void *unaff_retaddr;
  
  if (*(HANDLE *)(this + 8) != (HANDLE)0x0) {
    BVar1 = CloseHandle(*(HANDLE *)(this + 8));
    if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,in_R8);
    }
  }
  if (*(HANDLE *)this != (HANDLE)0x0) {
    BVar1 = CloseHandle(*(HANDLE *)this);
    if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,in_R8);
    }
  }
  return;
}



===== ~StoredFailureInfo @ 180003600 =====

/* public: __cdecl wil::StoredFailureInfo::~StoredFailureInfo(void) __ptr64 */

void __thiscall wil::StoredFailureInfo::~StoredFailureInfo(StoredFailureInfo *this)

{
  int iVar1;
  int *piVar2;
  LPVOID lpMem;
  HANDLE hHeap;
  
  piVar2 = *(int **)(this + 0x98);
  if (piVar2 != (int *)0x0) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      lpMem = *(LPVOID *)(this + 0x98);
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,lpMem);
    }
    *(undefined8 *)(this + 0x98) = 0;
    *(undefined8 *)(this + 0xa0) = 0;
  }
  return;
}



===== ~ThreadLocalData @ 180003670 =====

/* public: __cdecl wil::details_abi::ThreadLocalData::~ThreadLocalData(void) __ptr64 */

void __thiscall wil::details_abi::ThreadLocalData::~ThreadLocalData(ThreadLocalData *this)

{
  undefined8 *puVar1;
  ushort uVar2;
  undefined8 *puVar3;
  LPVOID pvVar4;
  HANDLE pvVar5;
  undefined8 *puVar6;
  
  puVar3 = *(undefined8 **)(this + 0x18);
  uVar2 = *(ushort *)(this + 0x20);
  if (puVar3 != puVar3 + (ulonglong)uVar2 * 10) {
    puVar6 = puVar3 + 8;
    do {
      pvVar4 = (LPVOID)*puVar6;
      pvVar5 = GetProcessHeap();
      HeapFree(pvVar5,0,pvVar4);
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar1 = puVar6 + 2;
      puVar6 = puVar6 + 10;
    } while (puVar1 != puVar3 + (ulonglong)uVar2 * 10);
  }
  pvVar4 = *(LPVOID *)(this + 0x18);
  pvVar5 = GetProcessHeap();
  HeapFree(pvVar5,0,pvVar4);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  return;
}



===== `vector_deleting_destructor' @ 180003730 =====

/* public: virtual void * __ptr64 __cdecl wil::ResultException::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
wil::ResultException::_vector_deleting_destructor_(ResultException *this,uint param_1)

{
  ~ResultException(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this,0xd0);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 180003770 =====

/* public: virtual void * __ptr64 __cdecl std::bad_array_new_length::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
std::bad_array_new_length::_scalar_deleting_destructor_(bad_array_new_length *this,uint param_1)

{
  *(undefined ***)this = exception::_vftable_;
  __std_exception_destroy(this + 8);
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x18);
  }
  return this;
}



===== Acquire @ 1800037bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl wil::details_abi::ProcessLocalStorageData<struct
   wil::details_abi::ProcessLocalData>::Acquire(char const * __ptr64,class
   wil::details_abi::ProcessLocalStorageData<struct wil::details_abi::ProcessLocalData> * __ptr64 *
   __ptr64) */

long __cdecl
wil::details_abi::ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Acquire
          (char *param_1,
          ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **param_2)

{
  __uint64 _Var1;
  DWORD DVar2;
  long lVar3;
  BOOL BVar4;
  HANDLE pvVar5;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *pPVar6;
  HANDLE hHeap;
  undefined1 uVar7;
  HANDLE hMutex;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *pPVar8;
  bool *pbVar9;
  void *unaff_retaddr;
  undefined1 auStack_298 [32];
  undefined4 local_278;
  char *local_270;
  HANDLE local_268;
  __uint64 local_260;
  __uint64 _Stack_258;
  longlong local_250;
  WCHAR local_248 [264];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_298;
  *param_2 = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
  DVar2 = GetCurrentProcessId();
  local_278 = 0x78;
  local_270 = param_1;
  StringCchPrintfW((ushort *)local_248,0x104,(ushort *)L"Local\\SM0:%lu:%lu:%hs",(ulonglong)DVar2);
  local_268 = (HANDLE)0x0;
  pbVar9 = (bool *)0x1f0001;
  pvVar5 = CreateMutexExW((LPSECURITY_ATTRIBUTES)0x0,local_248,0,0x1f0001);
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *)&local_268,pvVar5);
  pvVar5 = local_268;
  if (local_268 == (HANDLE)0x0) {
    lVar3 = details::GetLastErrorFailHr();
    return lVar3;
  }
  uVar7 = 0xff;
  DVar2 = WaitForSingleObjectEx(local_268,0xffffffff,0);
  if (DVar2 == 0x102) {
    hMutex = (HANDLE)0x0;
  }
  else {
    if ((DVar2 & 0xffffff7f) != 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::FailFast_Unexpected
                (unaff_retaddr,0xc37,"onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
    }
    hMutex = pvVar5;
  }
  local_250 = 0;
  pPVar8 = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)&local_250;
  lVar3 = SemaphoreValue::TryGetValueInternal
                    ((ushort *)local_248,(bool)uVar7,(__uint64 *)pPVar8,pbVar9);
  if (lVar3 < 0) {
    details::in1diag3::Return_Hr(unaff_retaddr,100,(char *)pPVar8,lVar3);
    details::in1diag3::Return_Hr(unaff_retaddr,0x6d,(char *)pPVar8,lVar3);
    details::in1diag3::Return_Hr(unaff_retaddr,299,(char *)pPVar8,lVar3);
    if ((hMutex != (HANDLE)0x0) && (BVar4 = ReleaseMutex(hMutex), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,(char *)pPVar8);
    }
    BVar4 = CloseHandle(pvVar5);
    if (BVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pPVar8);
    }
    return lVar3;
  }
  pPVar6 = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)(local_250 * 4);
  if (pPVar6 == (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0) {
    *param_2 = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
    pPVar6 = details::ProcessHeapAlloc(8,0x78);
    if (pPVar6 == (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0) {
      lVar3 = -0x7ff8fff2;
      details::in1diag3::Return_Hr(unaff_retaddr,0x148,(char *)pPVar8,-0x7ff8fff2);
      pPVar6 = pPVar8;
    }
    else {
      local_260 = 0;
      _Stack_258 = 0;
      pPVar8 = pPVar6;
      lVar3 = SemaphoreValue::CreateFromPointer
                        ((SemaphoreValue *)&local_260,(ushort *)local_248,pPVar6);
      _Var1 = _Stack_258;
      if (-1 < lVar3) {
        *(HANDLE *)(pPVar6 + 8) = pvVar5;
        pvVar5 = (HANDLE)0x0;
        *(__uint64 *)(pPVar6 + 0x10) = local_260;
        local_260 = 0;
        _Stack_258 = 0;
        *(undefined4 *)pPVar6 = 1;
        local_268 = (HANDLE)0x0;
        *(__uint64 *)(pPVar6 + 0x18) = _Var1;
        memset(pPVar6 + 0x22,0,0x56);
        *(undefined2 *)(pPVar6 + 0x20) = 0x58;
        *(undefined4 *)(pPVar6 + 0x24) = 1;
        pPVar8 = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x50;
        memset(pPVar6 + 0x28,0,0x50);
        *param_2 = pPVar6;
        SemaphoreValue::~SemaphoreValue((SemaphoreValue *)&local_260);
        goto LAB_180003aa3;
      }
      details::in1diag3::Return_Hr(unaff_retaddr,0x14b,(char *)pPVar8,lVar3);
      SemaphoreValue::~SemaphoreValue((SemaphoreValue *)&local_260);
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,pPVar6);
    }
    details::in1diag3::Return_Hr(unaff_retaddr,0x134,(char *)pPVar6,lVar3);
    if ((hMutex != (HANDLE)0x0) && (BVar4 = ReleaseMutex(hMutex), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,(char *)pPVar6);
    }
    if ((pvVar5 != (HANDLE)0x0) && (BVar4 = CloseHandle(pvVar5), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pPVar6);
    }
  }
  else {
    *param_2 = pPVar6;
    *(int *)*param_2 = *(int *)pPVar6 + 1;
    pvVar5 = local_268;
LAB_180003aa3:
    if ((hMutex != (HANDLE)0x0) && (BVar4 = ReleaseMutex(hMutex), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,(char *)pPVar8);
    }
    if ((pvVar5 != (HANDLE)0x0) && (BVar4 = CloseHandle(pvVar5), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pPVar8);
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== CreateFromPointer @ 180003b8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl wil::details_abi::SemaphoreValue::CreateFromPointer(unsigned short const *
   __ptr64,void * __ptr64) __ptr64 */

long __thiscall
wil::details_abi::SemaphoreValue::CreateFromPointer
          (SemaphoreValue *this,ushort *param_1,void *param_2)

{
  WCHAR WVar1;
  long lVar2;
  WCHAR *pWVar3;
  HANDLE pvVar4;
  HANDLE pvVar5;
  WCHAR *pWVar6;
  __uint64 _Var7;
  uint uVar8;
  uint lInitialCount;
  uint lMaximumCount;
  char *pcVar9;
  void *unaff_retaddr;
  undefined1 auStackY_268 [32];
  WCHAR local_238 [264];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_268;
  if (((ulonglong)param_2 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
    wistd::__throw_bad_function_call();
  }
  pWVar6 = local_238;
  _Var7 = 0x104;
  do {
    if ((_Var7 == 0xffffffff80000106) ||
       (WVar1 = *(WCHAR *)(((longlong)param_1 - (longlong)local_238) + (longlong)pWVar6),
       WVar1 == L'\0')) break;
    *pWVar6 = WVar1;
    pWVar6 = pWVar6 + 1;
    _Var7 = _Var7 - 1;
  } while (_Var7 != 0);
  pWVar3 = pWVar6 + -1;
  if (_Var7 != 0) {
    pWVar3 = pWVar6;
  }
  *pWVar3 = L'\0';
  StringCchCatW((ushort *)local_238,_Var7,(ushort *)L"_p0");
  uVar8 = (uint)((ulonglong)param_2 >> 2) & 0x7fffffff;
  pvVar5 = (HANDLE)(ulonglong)uVar8;
  pcVar9 = (char *)0x1;
  if (((ulonglong)param_2 >> 2 & 0x7fffffff) != 0) {
    pcVar9 = (char *)(ulonglong)uVar8;
  }
  pvVar4 = CreateSemaphoreExW((LPSECURITY_ATTRIBUTES)0x0,uVar8,(LONG)pcVar9,local_238,0,0x1f0003);
  if (pvVar4 == (HANDLE)0x0) {
    lVar2 = details::GetLastErrorFailHr();
    pvVar4 = pvVar5;
    if (-1 < lVar2) goto LAB_180003c9e;
    uVar8 = 0x88;
LAB_180003c72:
    details::in1diag3::Return_Hr(unaff_retaddr,uVar8,pcVar9,lVar2);
  }
  else {
    GetLastError();
    details::
    unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
             *)this,pvVar4);
LAB_180003c9e:
    StringCchCatW((ushort *)local_238,(__uint64)pvVar4,(ushort *)L"h");
    uVar8 = (uint)((ulonglong)param_2 >> 0x20);
    lInitialCount = uVar8 >> 1;
    lMaximumCount = 1;
    if (uVar8 >> 1 != 0) {
      lMaximumCount = lInitialCount;
    }
    pcVar9 = (char *)(ulonglong)lMaximumCount;
    pvVar5 = CreateSemaphoreExW((LPSECURITY_ATTRIBUTES)0x0,lInitialCount,lMaximumCount,local_238,0,
                                0x1f0003);
    if (pvVar5 == (HANDLE)0x0) {
      lVar2 = details::GetLastErrorFailHr();
      if (lVar2 < 0) {
        uVar8 = 0x8d;
        goto LAB_180003c72;
      }
    }
    else {
      GetLastError();
      details::
      unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
      ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
               *)(this + 8),pvVar5);
    }
    lVar2 = 0;
  }
  return lVar2;
}



===== DebugBreak @ 180003d50 =====

/* void __cdecl wil::details::DebugBreak(void) */

void __cdecl wil::details::DebugBreak(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180003d50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ::DebugBreak();
  return;
}



===== FailFast_Unexpected @ 180003d64 =====

/* void __cdecl wil::details::in1diag3::FailFast_Unexpected(void * __ptr64,unsigned int,char const *
   __ptr64) */

void __cdecl wil::details::in1diag3::FailFast_Unexpected(void *param_1,uint param_2,char *param_3)

{
  code *pcVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  long in_stack_ffffffffffffffe8;
  
  ReportFailure_Hr<3>(param_1,param_2,param_3,in_R9,in_stack_ffffffffffffffd8,unaff_retaddr,
                      in_stack_ffffffffffffffe8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== FormatNtStatusMsg @ 180003d80 =====

/* void __cdecl wil::details::FormatNtStatusMsg(long,unsigned short * __ptr64,unsigned long) */

void __cdecl wil::details::FormatNtStatusMsg(long param_1,ushort *param_2,ulong param_3)

{
  if (`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
      wil_details_ntdllModuleHandle == (HINSTANCE__ *)0x0) {
    `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
    wil_details_ntdllModuleHandle = GetModuleHandleW(L"ntdll.dll");
  }
  FormatMessageW(0x1a00,`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'
                        ::__l2::wil_details_ntdllModuleHandle,param_1,0x400,(LPWSTR)param_2,param_3,
                 (va_list *)0x0);
  return;
}



===== FromResult @ 180003e00 =====

/* public: static struct wil::details::ResultStatus __cdecl
   wil::details::ResultStatus::FromResult(long) */

long * __cdecl wil::details::ResultStatus::FromResult(long param_1)

{
  long lVar1;
  undefined4 in_register_0000000c;
  long *plVar2;
  long in_EDX;
  
  plVar2 = (long *)CONCAT44(in_register_0000000c,param_1);
  *plVar2 = in_EDX;
  lVar1 = HrToNtStatus(in_EDX);
  plVar2[2] = 0;
  plVar2[1] = lVar1;
  return plVar2;
}



===== GetContextAndNotifyFailure @ 180003e30 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::GetContextAndNotifyFailure(struct wil::FailureInfo * __ptr64,char *
   __ptr64,unsigned __int64) */

void __cdecl
wil::details::GetContextAndNotifyFailure(FailureInfo *param_1,char *param_2,__uint64 param_3)

{
  int iVar1;
  ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *pTVar2;
  bool bVar3;
  byte bVar4;
  DWORD DVar5;
  ThreadLocalData *this;
  int iVar6;
  DWORD *pDVar7;
  longlong lVar8;
  byte bVar9;
  
  *param_2 = '\0';
  pTVar2 = g_pThreadFailureCallbacks;
  bVar9 = 0;
  if (g_pThreadFailureCallbacks !=
      (ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64> *)0x0) {
    DVar5 = GetCurrentThreadId();
    for (pDVar7 = *(DWORD **)(pTVar2 + ((ulonglong)DVar5 + ((ulonglong)DVar5 / 10) * -10) * 8);
        pDVar7 != (DWORD *)0x0; pDVar7 = *(DWORD **)(pDVar7 + 2)) {
      if (*pDVar7 == DVar5) {
        pDVar7 = pDVar7 + 4;
        break;
      }
    }
    if ((pDVar7 != (DWORD *)0x0) && (*(longlong *)pDVar7 != 0)) {
      *param_2 = '\0';
      bVar3 = ThreadFailureCallbackHolder::GetThreadContext
                        (param_1,*(ThreadFailureCallbackHolder **)pDVar7,param_2,param_3);
      if (bVar3) {
        *(char **)(param_1 + 0x48) = param_2;
      }
      lVar8 = *(longlong *)pDVar7;
      do {
        bVar4 = (**(code **)**(undefined8 **)(lVar8 + 8))(*(undefined8 **)(lVar8 + 8),param_1);
        bVar9 = bVar9 | bVar4;
        lVar8 = *(longlong *)(lVar8 + 0x10);
      } while (lVar8 != 0);
    }
  }
  if (g_pfnTelemetryCallback != (_func_void_bool_FailureInfo_ptr *)0x0) {
    if ((bVar9 == 0) && (((byte)param_1[4] & 2) == 0)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    (*g_pfnTelemetryCallback)(bVar3,param_1);
  }
  DVar5 = GetCurrentThreadId();
  if (`void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l2::lastThread != DVar5)
  {
    LOCK();
    iVar1 = `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth + 1;
    UNLOCK();
    iVar6 = `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth + 1;
    `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth = iVar1;
    if (iVar6 < 4) {
      `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l2::lastThread = DVar5;
      this = details_abi::GetThreadLocalDataCache(SUB41(iVar6,0));
      if (this != (ThreadLocalData *)0x0) {
        details_abi::ThreadLocalData::SetLastError(this,param_1);
      }
      `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l2::lastThread = 0;
    }
    LOCK();
    `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth =
         `void___cdecl_wil::SetLastError(wil::FailureInfo_const&___ptr64)'::__l5::depth + -1;
    UNLOCK();
  }
  return;
}



===== GetCurrentModuleName @ 180003fa0 =====

/* char const * __ptr64 __cdecl wil::details::GetCurrentModuleName(void) */

char * __cdecl wil::details::GetCurrentModuleName(void)

{
  if (!`char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2::s_fModuleValid)
  {
    GetModuleInformation
              (RecordFailFast,(uint *)0x0,
               (char *)&`char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2
                        ::s_szModule,0x40);
    `char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2::s_fModuleValid =
         true;
  }
  return (char *)&`char_const*___ptr64___cdecl_wil::details::GetCurrentModuleName(void)'::__l2::
                  s_szModule;
}



===== GetFailureLogString @ 180003fe4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl wil::GetFailureLogString(unsigned short * __ptr64,unsigned __int64,struct
   wil::FailureInfo const & __ptr64) */

long __cdecl wil::GetFailureLogString(ushort *param_1,__uint64 param_2,FailureInfo *param_3)

{
  ushort *puVar1;
  int iVar2;
  char *pcVar3;
  ushort *puVar4;
  char *pcVar5;
  undefined1 auStackY_278 [32];
  WCHAR local_238 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_278;
  if (param_2 == 0) {
    return 0;
  }
  if (param_1 == (ushort *)0x0) {
    return 0;
  }
  *param_1 = 0;
  if (((g_pfnResultLoggingCallback != (code *)0x0) && (details::g_resultMessageCallbackSet != false)
      ) && ((*g_pfnResultLoggingCallback)(param_3,param_1,param_2), *param_1 != 0)) {
    return 0;
  }
  iVar2 = *(int *)param_3;
  if (iVar2 == 0) {
    pcVar5 = "Exception";
  }
  else {
    if (iVar2 == 1) {
      pcVar3 = "ReturnHr";
      pcVar5 = "ReturnNt";
    }
    else {
      if (iVar2 != 2) {
        pcVar5 = "";
        if (iVar2 == 3) {
          pcVar5 = "FailFast";
        }
        goto LAB_1800040af;
      }
      pcVar3 = "LogHr";
      pcVar5 = "LogNt";
    }
    if (((byte)param_3[4] & 8) == 0) {
      pcVar5 = pcVar3;
    }
  }
LAB_1800040af:
  memset(local_238,0,0x200);
  if (((byte)param_3[4] & 8) == 0) {
    FormatMessageW(0x1200,(LPCVOID)0x0,*(DWORD *)(param_3 + 8),0x400,local_238,0x100,(va_list *)0x0)
    ;
  }
  else if (details::g_pfnFormatNtStatusMsg != (_func_void_long_ushort_ptr_ulong *)0x0) {
    (*details::g_pfnFormatNtStatusMsg)(*(long *)(param_3 + 0xc),(ushort *)local_238,0x100);
  }
  puVar1 = param_1 + param_2;
  if (*(longlong *)(param_3 + 0x38) == 0) {
    puVar4 = details::LogStringPrintf
                       (param_1,puVar1,(ushort *)L"%hs!%p: ",*(undefined8 *)(param_3 + 0x80));
  }
  else {
    puVar4 = details::LogStringPrintf(param_1,puVar1,(ushort *)L"%hs(%u)\\%hs!%p: ");
  }
  if (*(longlong *)(param_3 + 0x90) != 0) {
    puVar4 = details::LogStringPrintf(puVar4,puVar1,(ushort *)L"(caller: %p) ");
  }
  GetCurrentThreadId();
  puVar4 = details::LogStringPrintf(puVar4,puVar1,(ushort *)L"%hs(%d) tid(%x) %08X %ws",pcVar5);
  if (((*(longlong *)(param_3 + 0x18) != 0) || (*(longlong *)(param_3 + 0x48) != 0)) ||
     (*(longlong *)(param_3 + 0x30) != 0)) {
    puVar4 = details::LogStringPrintf(puVar4,puVar1,(ushort *)L"    ");
    if (*(longlong *)(param_3 + 0x18) != 0) {
      puVar4 = details::LogStringPrintf(puVar4,puVar1,(ushort *)L"Msg:[%ws] ");
    }
    if (*(longlong *)(param_3 + 0x48) != 0) {
      puVar4 = details::LogStringPrintf(puVar4,puVar1,(ushort *)L"CallContext:[%hs] ");
    }
    if (*(longlong *)(param_3 + 0x28) == 0) {
      if (*(longlong *)(param_3 + 0x30) == 0) {
        details::LogStringPrintf(puVar4,puVar1,(ushort *)L"\n");
      }
      else {
        details::LogStringPrintf(puVar4,puVar1,(ushort *)L"[%hs]\n");
      }
    }
    else {
      details::LogStringPrintf(puVar4,puVar1,(ushort *)L"[%hs(%hs)]\n");
    }
  }
  return 0;
}



===== GetLastErrorFail @ 1800042ac =====

/* unsigned long __cdecl wil::details::GetLastErrorFail(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64) */

ulong __cdecl
wil::details::GetLastErrorFail
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (DVar1 == 0) {
    ReportFailure_Hr<2>(param_1,param_2,param_3,(char *)0x0,(char *)0x0,param_6,-0x7ff8fd64);
    DVar1 = 0x29c;
  }
  return DVar1;
}



===== GetLastErrorFailHr @ 180004318 =====

/* long __cdecl wil::details::GetLastErrorFailHr(void) */

long __cdecl wil::details::GetLastErrorFailHr(void)

{
  uint uVar1;
  void *unaff_retaddr;
  
  uVar1 = GetLastError();
  if (uVar1 == 0) {
    ReportFailure_Hr<2>((void *)0x0,0,(char *)0x0,(char *)0x0,(char *)0x0,unaff_retaddr,-0x7ff8fd64)
    ;
    uVar1 = 0x29c;
  }
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  return uVar1;
}



===== GetModuleInformation @ 180004374 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* bool __cdecl wil::details::GetModuleInformation(void * __ptr64,unsigned int * __ptr64,char *
   __ptr64,unsigned __int64) */

bool __cdecl
wil::details::GetModuleInformation(void *param_1,uint *param_2,char *param_3,__uint64 param_4)

{
  bool bVar1;
  BOOL BVar2;
  DWORD DVar3;
  char *pcVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 auStack_168 [32];
  HMODULE local_148 [2];
  CHAR local_138;
  char acStack_137 [271];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_168;
  local_148[0] = (HMODULE)0x0;
  if ((param_1 == (void *)0x0) || (BVar2 = GetModuleHandleExW(6,param_1,local_148), BVar2 != 0)) {
    if (param_2 != (uint *)0x0) {
      uVar6 = 0;
      if (param_1 != (void *)0x0) {
        uVar6 = (int)param_1 - (int)local_148[0];
      }
      *param_2 = uVar6;
    }
    if (param_3 != (char *)0x0) {
      DVar3 = GetModuleFileNameA(local_148[0],&local_138,0x104);
      if (DVar3 == 0) goto LAB_18000440d;
      lVar5 = -1;
      do {
        lVar7 = lVar5;
        lVar5 = lVar7 + 1;
      } while (acStack_137[lVar7] != '\0');
      for (pcVar4 = acStack_137 + lVar7; (&local_138 < pcVar4 && (pcVar4[-1] != '\\'));
          pcVar4 = pcVar4 + -1) {
      }
      if (param_4 != 0) {
        if (param_4 < 0x80000000) {
          lVar7 = 0x7ffffffe - param_4;
          lVar5 = (longlong)pcVar4 - (longlong)param_3;
          do {
            if ((lVar7 + param_4 == 0) || (param_3[lVar5] == '\0')) break;
            *param_3 = param_3[lVar5];
            param_3 = param_3 + 1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
          pcVar4 = param_3 + -1;
          if (param_4 != 0) {
            pcVar4 = param_3;
          }
          *pcVar4 = '\0';
        }
        else {
          *param_3 = '\0';
        }
      }
    }
    bVar1 = true;
  }
  else {
    if (param_2 != (uint *)0x0) {
      *param_2 = 0;
    }
LAB_18000440d:
    bVar1 = false;
  }
  return bVar1;
}



===== GetThreadContext @ 1800044b8 =====

/* public: static bool __cdecl wil::details::ThreadFailureCallbackHolder::GetThreadContext(struct
   wil::FailureInfo * __ptr64,class wil::details::ThreadFailureCallbackHolder * __ptr64,char *
   __ptr64,unsigned __int64) */

bool __cdecl
wil::details::ThreadFailureCallbackHolder::GetThreadContext
          (FailureInfo *param_1,ThreadFailureCallbackHolder *param_2,char *param_3,__uint64 param_4)

{
  int *piVar1;
  undefined8 uVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  char *_DstSize;
  longlong lVar6;
  char *_MaxCount;
  char *pcVar7;
  
  bVar3 = false;
  *param_3 = '\0';
  if (param_2 != (ThreadFailureCallbackHolder *)0x0) {
    bVar3 = GetThreadContext(param_1,*(ThreadFailureCallbackHolder **)(param_2 + 0x10),param_3,
                             param_4);
    piVar1 = *(int **)(param_2 + 0x20);
    if (piVar1 != (int *)0x0) {
      if (*piVar1 == 0) {
        LOCK();
        UNLOCK();
        iVar4 = s_telemetryId + 1;
        s_telemetryId = s_telemetryId + 1;
        *piVar1 = iVar4;
      }
      if (*(int *)(param_1 + 0x50) == 0) {
        uVar2 = *(undefined8 *)(piVar1 + 2);
        *(undefined8 *)(param_1 + 0x50) = *(undefined8 *)piVar1;
        *(undefined8 *)(param_1 + 0x58) = uVar2;
        *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(piVar1 + 4);
      }
      uVar2 = *(undefined8 *)(piVar1 + 2);
      *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)piVar1;
      *(undefined8 *)(param_1 + 0x70) = uVar2;
      *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(piVar1 + 4);
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (param_3[lVar5] != '\0');
      pcVar7 = param_3 + lVar5;
      if (2 < (longlong)(param_3 + (param_4 - (longlong)pcVar7))) {
        *pcVar7 = '\\';
        pcVar7 = pcVar7 + 1;
        lVar5 = -1;
        do {
          lVar6 = lVar5;
          lVar5 = lVar6 + 1;
        } while (*(char *)((longlong)*(void **)(piVar1 + 2) + lVar5) != '\0');
        _DstSize = param_3 + (param_4 - (longlong)pcVar7);
        _MaxCount = (char *)(lVar6 + 2);
        if (_DstSize <= _MaxCount) {
          _MaxCount = _DstSize;
        }
        memcpy_s(pcVar7,(rsize_t)_DstSize,*(void **)(piVar1 + 2),(rsize_t)_MaxCount);
        pcVar7[(longlong)(_MaxCount + -1)] = '\0';
      }
      bVar3 = true;
    }
  }
  return bVar3;
}



===== GetThreadLocalDataCache @ 1800045b0 =====

/* struct wil::details_abi::ThreadLocalData * __ptr64 __cdecl
   wil::details_abi::GetThreadLocalDataCache(bool) */

ThreadLocalData * __cdecl wil::details_abi::GetThreadLocalDataCache(bool param_1)

{
  ProcessLocalStorage<wil::details_abi::ProcessLocalData> *pPVar1;
  long lVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  ThreadLocalData *pTVar5;
  ulonglong uVar6;
  ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *local_res10 [3];
  
  pPVar1 = g_pProcessLocalData;
  if (g_pProcessLocalData != (ProcessLocalStorage<wil::details_abi::ProcessLocalData> *)0x0) {
    if (*(longlong *)(g_pProcessLocalData + 8) == 0) {
      local_res10[0] = (ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> *)0x0;
      lVar2 = ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Acquire
                        (*(char **)g_pProcessLocalData,local_res10);
      if ((-1 < lVar2) && (*(longlong *)(pPVar1 + 8) == 0)) {
        *(ProcessLocalStorageData<struct_wil::details_abi::ProcessLocalData> **)(pPVar1 + 8) =
             local_res10[0];
      }
    }
    uVar6 = -(ulonglong)(*(longlong *)(pPVar1 + 8) != 0) & *(longlong *)(pPVar1 + 8) + 0x20U;
    if (uVar6 != 0) {
      DVar3 = GetCurrentThreadId();
      for (pDVar4 = *(DWORD **)(uVar6 + 8 + ((ulonglong)DVar3 + ((ulonglong)DVar3 / 10) * -10) * 8);
          pDVar4 != (DWORD *)0x0; pDVar4 = *(DWORD **)(pDVar4 + 2)) {
        if (*pDVar4 == DVar3) {
          pTVar5 = (ThreadLocalData *)(pDVar4 + 4);
          if (pTVar5 == (ThreadLocalData *)0x0) {
            return (ThreadLocalData *)0x0;
          }
          if (*(longlong *)(pDVar4 + 6) == 0) {
            *(ulonglong *)(pDVar4 + 6) = uVar6 + 4;
            return pTVar5;
          }
          return pTVar5;
        }
      }
    }
  }
  return (ThreadLocalData *)0x0;
}



===== GetValueFromSemaphore @ 18000467c =====

/* private: static long __cdecl wil::details_abi::SemaphoreValue::GetValueFromSemaphore(void *
   __ptr64,long * __ptr64) */

long __cdecl wil::details_abi::SemaphoreValue::GetValueFromSemaphore(void *param_1,long *param_2)

{
  DWORD DVar1;
  long lVar2;
  BOOL BVar3;
  uint uVar4;
  LPLONG in_R8;
  void *unaff_retaddr;
  long local_res18 [2];
  long local_res20 [2];
  
  DVar1 = WaitForSingleObject(param_1,0);
  if (DVar1 == 0xffffffff) {
    uVar4 = 0x99;
    goto LAB_1800046a4;
  }
  if ((DVar1 == 0) || (DVar1 == 0x102)) {
    local_res18[0] = 0;
    if (DVar1 == 0) {
      in_R8 = local_res18;
      BVar3 = ReleaseSemaphore(param_1,1,in_R8);
      if (BVar3 == 0) {
        uVar4 = 0xa2;
LAB_1800046a4:
        lVar2 = details::in1diag3::Return_GetLastError(unaff_retaddr,uVar4,(char *)in_R8);
        return lVar2;
      }
      local_res18[0] = local_res18[0] + 1;
      in_R8 = (LPLONG)0x0;
      BVar3 = ReleaseSemaphore(param_1,1,(LPLONG)0x0);
      if ((BVar3 == 0) && (DVar1 = GetLastError(), DVar1 == 0x12a)) {
LAB_1800047be:
        *param_2 = local_res18[0];
        return 0;
      }
      uVar4 = 0xa7;
    }
    else {
      local_res20[0] = 0;
      in_R8 = local_res20;
      BVar3 = ReleaseSemaphore(param_1,1,in_R8);
      if (BVar3 == 0) {
        uVar4 = 0xb1;
        goto LAB_1800046a4;
      }
      if (local_res20[0] == 0) {
        in_R8 = (LPLONG)0x0;
        BVar3 = ReleaseSemaphore(param_1,1,(LPLONG)0x0);
        if ((BVar3 == 0) && (DVar1 = GetLastError(), DVar1 == 0x12a)) {
          DVar1 = WaitForSingleObject(param_1,0);
          if (DVar1 == 0xffffffff) {
            uVar4 = 0xb8;
            goto LAB_1800046a4;
          }
          if (DVar1 == 0) goto LAB_1800047be;
          uVar4 = 0xb9;
        }
        else {
          uVar4 = 0xb5;
        }
      }
      else {
        uVar4 = 0xb2;
      }
    }
  }
  else {
    uVar4 = 0x9a;
  }
  details::in1diag3::Return_Hr(unaff_retaddr,uVar4,(char *)in_R8,-0x7fff0001);
  return -0x7fff0001;
}



===== HrToNtStatus @ 1800047f4 =====

/* long __cdecl wil::details::HrToNtStatus(long) */

long __cdecl wil::details::HrToNtStatus(long param_1)

{
  if (param_1 < -0x7ff8ff15) {
    if (param_1 == -0x7ff8ff16) {
      return -0x7ffffffb;
    }
    if (param_1 < -0x7ff8ffa8) {
      if (param_1 == -0x7ff8ffa9) {
        return -0x3ffffff3;
      }
      if (param_1 == -0x7fffbffb) {
        return -0x3fffffff;
      }
      if (param_1 == -0x7ff8ffff) {
        return -0x3ffffffe;
      }
      if (param_1 == -0x7ff8fffe) {
        return -0x3fffffcc;
      }
      if (param_1 == -0x7ff8fffd) {
        return -0x3fffffc6;
      }
      if (param_1 == -0x7ff8fff2) {
        return -0x3fffffe9;
      }
    }
    else {
      if (param_1 == -0x7ff8ff90) {
        return -0x3fffff81;
      }
      if (param_1 == -0x7ff8ff86) {
        return -0x3fffffdd;
      }
      if (param_1 == -0x7ff8ff85) {
        return -0x3fffffcd;
      }
      if (param_1 == -0x7ff8ff82) {
        return -0x3ffffecb;
      }
    }
  }
  else if (param_1 < -0x7ff8fb81) {
    if (param_1 == -0x7ff8fb82) {
      return -0x3fffffa7;
    }
    if (param_1 == -0x7ff8fdea) {
      return -0x3fffff6b;
    }
    if (param_1 == -0x7ff8fdc2) {
      return -0x3fffffdb;
    }
    if (param_1 == -0x7ff8fdba) {
      return -0x3ffffe9f;
    }
    if (param_1 == -0x7ff8fdb9) {
      return -0x3ffffe9d;
    }
    if (param_1 == -0x7ff8fd8e) {
      return -0x3ffffd8d;
    }
  }
  else {
    if (param_1 == -0x7ff8faf4) {
      return -0x3ffffbd5;
    }
    if (param_1 == -0x7ff8fab1) {
      return -0x3fffff1b;
    }
    if (param_1 == -0x7ff8fa47) {
      return -0x3fff5f7d;
    }
    if (param_1 == 0) {
      return 0;
    }
  }
  if (((uint)param_1 >> 0x1c & 1) != 0) {
    return param_1 & 0xefffffff;
  }
  if ((param_1 & 0x1fff0000U) == 0x70000) {
    if ((param_1 & 0xffffU) == 0) {
      return 0;
    }
    return param_1 & 0xffffU | 0xc0070000;
  }
  if ((param_1 & 0x1fff0000U) != 0x90000) {
    return -0x3fffff1b;
  }
  if (param_1 < 1) {
    return param_1;
  }
  return param_1 & 0xffffU | 0xc0090000;
}



===== LogFailure @ 1800049c4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::LogFailure(void * __ptr64,unsigned int,char const * __ptr64,char const
   * __ptr64,char const * __ptr64,void * __ptr64,enum wil::FailureType,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,bool,unsigned short *
   __ptr64,unsigned __int64,char * __ptr64,unsigned __int64,struct wil::FailureInfo * __ptr64) */

void __cdecl
wil::details::LogFailure
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          FailureType param_7,ResultStatus *param_8,ushort *param_9,bool param_10,ushort *param_11,
          __uint64 param_12,char *param_13,__uint64 param_14,FailureInfo *param_15)

{
  int iVar1;
  long lVar2;
  int iVar3;
  DWORD DVar4;
  long lVar5;
  BOOL BVar6;
  ushort *puVar7;
  bool bVar8;
  
  *param_11 = 0;
  *param_13 = '\0';
  lVar5 = *(long *)param_8;
  *(long *)(param_15 + 8) = lVar5;
  *(undefined4 *)(param_15 + 0xc) = *(undefined4 *)(param_8 + 4);
  iVar1 = 0;
  if (param_7 == 0) {
    iVar1 = RecordException(lVar5);
  }
  else if (param_7 == 1) {
    iVar1 = RecordReturn(lVar5);
  }
  else if (param_7 == 2) {
    if (-1 < lVar5) {
      lVar5 = -0x7ff8fd64;
      ReportFailure_Hr<2>(param_1,param_2,param_3,param_4,param_5,param_6,-0x7ff8fd64);
      *(undefined4 *)(param_15 + 8) = 0x8007029c;
      lVar2 = HrToNtStatus(-0x7ff8fd64);
      *(long *)(param_15 + 0xc) = lVar2;
    }
    iVar1 = RecordLog(lVar5);
  }
  else if (param_7 == 3) {
    iVar1 = RecordFailFast(lVar5);
  }
  *(FailureType *)param_15 = param_7;
  puVar7 = (ushort *)0x0;
  *(undefined4 *)(param_15 + 4) = 0;
  if (*(int *)(param_8 + 8) == 1) {
    *(undefined4 *)(param_15 + 4) = 8;
  }
  LOCK();
  UNLOCK();
  iVar3 = `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
          ::__l2::s_failureId + 1;
  `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
  ::__l2::s_failureId =
       `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
       ::__l2::s_failureId + 1;
  *(int *)(param_15 + 0x10) = iVar3;
  if ((param_9 == (ushort *)0x0) || (*param_9 == 0)) {
    param_9 = puVar7;
  }
  *(ushort **)(param_15 + 0x18) = param_9;
  DVar4 = GetCurrentThreadId();
  *(DWORD *)(param_15 + 0x20) = DVar4;
  *(char **)(param_15 + 0x38) = param_3;
  *(uint *)(param_15 + 0x40) = param_2;
  *(int *)(param_15 + 0x44) = iVar1;
  *(char **)(param_15 + 0x28) = param_5;
  *(char **)(param_15 + 0x30) = param_4;
  *(void **)(param_15 + 0x88) = param_6;
  *(void **)(param_15 + 0x90) = param_1;
  *(undefined8 *)(param_15 + 0x48) = 0;
  *(undefined8 *)(param_15 + 0x68) = 0;
  *(undefined8 *)(param_15 + 0x70) = 0;
  *(undefined8 *)(param_15 + 0x78) = 0;
  *(undefined8 *)(param_15 + 0x50) = 0;
  *(undefined8 *)(param_15 + 0x58) = 0;
  *(undefined8 *)(param_15 + 0x60) = 0;
  if (g_pfnGetModuleName != (_func_char_ptr *)0x0) {
    puVar7 = (ushort *)(*g_pfnGetModuleName)();
  }
  *(ushort **)(param_15 + 0x80) = puVar7;
  if (g_pfnNotifyFailure != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnNotifyFailure)(param_15);
  }
  if (g_pfnGetContextAndNotifyFailure != (_func_void_FailureInfo_ptr_char_ptr___uint64 *)0x0) {
    (*g_pfnGetContextAndNotifyFailure)(param_15,param_13,0x400);
  }
  if (g_pfnLoggingCallback != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnLoggingCallback)(param_15);
  }
  if ((g_pfnOriginateCallback != (_func_void_FailureInfo_ptr *)0x0) &&
     (((byte)param_15[4] & 2) == 0)) {
    (*g_pfnOriginateCallback)(param_15);
  }
  if (-1 < *(int *)(param_15 + 8)) {
    if (param_7 != 3) {
                    /* WARNING: Subroutine does not return */
      wistd::__throw_bad_function_call();
    }
    *(undefined4 *)(param_15 + 8) = 0x8000ffff;
    lVar5 = HrToNtStatus(-0x7fff0001);
    *(long *)(param_15 + 0xc) = lVar5;
  }
  if (g_fIsDebuggerPresent == false) {
    if (g_pfnIsDebuggerPresent == (_func_bool *)0x0) {
      BVar6 = IsDebuggerPresent();
      bVar8 = BVar6 != 0;
    }
    else {
      bVar8 = (*g_pfnIsDebuggerPresent)();
    }
    if (bVar8 != false) goto LAB_180004c1f;
  }
  else {
LAB_180004c1f:
    if (((byte)param_15[4] & 2) == 0) {
      if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
        (*g_pfnResultLoggingCallback)(param_15,param_11,0x800);
      }
      if (*param_11 == 0) {
        GetFailureLogString(param_11,0x800,param_15);
      }
      OutputDebugStringW((LPCWSTR)param_11);
      goto LAB_180004c94;
    }
  }
  if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
    (*g_pfnResultLoggingCallback)(param_15,0,0);
  }
LAB_180004c94:
  if (((((byte)param_15[4] & 4) != 0) || (g_fBreakOnFailure != false)) &&
     (g_pfnDebugBreak != (_func_void *)0x0)) {
    (*g_pfnDebugBreak)();
  }
  return;
}



===== LogStringPrintf @ 180004cdc =====

/* unsigned short * __ptr64 __cdecl wil::details::LogStringPrintf(unsigned short * __ptr64,unsigned
   short const * __ptr64,unsigned short const * __ptr64,...) */

ushort * __cdecl wil::details::LogStringPrintf(ushort *param_1,ushort *param_2,ushort *param_3,...)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  size_t _Count;
  undefined8 in_R9;
  undefined8 local_res20;
  
  uVar3 = (longlong)param_2 - (longlong)param_1 >> 1;
  if (uVar3 != 0) {
    if (uVar3 < 0x80000000) {
      _Count = uVar3 - 1;
      local_res20 = in_R9;
      iVar1 = _vsnwprintf((wchar_t *)param_1,_Count,(wchar_t *)param_3,(va_list)&local_res20);
      if (((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) || ((longlong)iVar1 == _Count)) {
        param_1[_Count] = 0;
      }
    }
    else {
      *param_1 = 0;
    }
  }
  if (param_2 != param_1) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_1[lVar2] != 0);
    param_1 = param_1 + lVar2;
  }
  return param_1;
}



===== MicrosoftInternalNotifyFailure @ 180004d60 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::MicrosoftInternalNotifyFailure(struct wil::FailureInfo * __ptr64) */

void __cdecl wil::details::MicrosoftInternalNotifyFailure(FailureInfo *param_1)

{
  _func_void_uint_WilFailureReport_ptr_WilFailureReportInformation_ptr *p_Var1;
  undefined8 local_res8;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  FailureInfo local_28;
  undefined1 local_27;
  undefined2 local_26;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_34 = 0;
  local_27 = 0;
  local_24 = 0;
  local_1e = 0;
  local_38 = *(undefined4 *)(param_1 + 8);
  local_30 = *(undefined8 *)(param_1 + 0x18);
  local_28 = *param_1;
  local_26 = (undefined2)g_moduleFailureReportFlags;
  local_20 = *(undefined2 *)(param_1 + 0x40);
  local_1c = 0;
  local_18 = *(undefined8 *)(param_1 + 0x38);
  local_10 = *(undefined8 *)(param_1 + 0x80);
  local_res8 = 0;
  if (`void___cdecl_wil::details::WilFailureNotifyWatchers(unsigned_int,WilFailureReport_const*___ptr64,WilFailureReportInformation*___ptr64)'
      ::__l2::s_pfnFailureNotifyWatchers ==
      (_func_void_uint_WilFailureReport_ptr_WilFailureReportInformation_ptr *)0x0) {
    p_Var1 = (_func_void_uint_WilFailureReport_ptr_WilFailureReportInformation_ptr *)0x0;
    if (`__int64_(__cdecl*__cdecl_wil_details_GetKernelBaseProcAddress(char_const*___ptr64))(void)'
        ::__l2::wil_details_kernelbaseModuleHandle == (HINSTANCE__ *)0x0) {
      `__int64_(__cdecl*__cdecl_wil_details_GetKernelBaseProcAddress(char_const*___ptr64))(void)'::
      __l2::wil_details_kernelbaseModuleHandle = GetModuleHandleW(L"kernelbase.dll");
      if (`__int64_(__cdecl*__cdecl_wil_details_GetKernelBaseProcAddress(char_const*___ptr64))(void)'
          ::__l2::wil_details_kernelbaseModuleHandle != (HMODULE)0x0) goto LAB_180004e03;
    }
    else {
LAB_180004e03:
      p_Var1 = (_func_void_uint_WilFailureReport_ptr_WilFailureReportInformation_ptr *)
               GetProcAddress(`__int64_(__cdecl*__cdecl_wil_details_GetKernelBaseProcAddress(char_const*___ptr64))(void)'
                              ::__l2::wil_details_kernelbaseModuleHandle,"WilFailureNotifyWatchers")
      ;
    }
    `void___cdecl_wil::details::WilFailureNotifyWatchers(unsigned_int,WilFailureReport_const*___ptr64,WilFailureReportInformation*___ptr64)'
    ::__l2::s_pfnFailureNotifyWatchers = p_Var1;
    if (p_Var1 == (_func_void_uint_WilFailureReport_ptr_WilFailureReportInformation_ptr *)0x0)
    goto LAB_180004e3b;
  }
  (*`void___cdecl_wil::details::WilFailureNotifyWatchers(unsigned_int,WilFailureReport_const*___ptr64,WilFailureReportInformation*___ptr64)'
    ::__l2::s_pfnFailureNotifyWatchers)
            (0,(WilFailureReport *)&local_38,(WilFailureReportInformation *)&local_res8);
LAB_180004e3b:
  *(undefined4 *)(param_1 + 0x10) = (undefined4)local_res8;
  if (local_res8._4_1_ == '\x01') {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
  }
  else if (local_res8._4_1_ == '\x02') {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
  }
  else if (local_res8._4_1_ == '\x03') {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
  }
  return;
}



===== ProcessHeapAlloc @ 180004e80 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void * __ptr64 __cdecl wil::details::ProcessHeapAlloc(unsigned long,unsigned __int64) */

void * __cdecl wil::details::ProcessHeapAlloc(ulong param_1,__uint64 param_2)

{
  HANDLE hHeap;
  LPVOID pvVar1;
  HMODULE hModule;
  
  hHeap = GetProcessHeap();
  pvVar1 = HeapAlloc(hHeap,param_1,param_2);
  if (`void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2::
      pfnRtlDisownModuleHeapAllocation == (_func_long_void_ptr_void_ptr *)0x0) {
    if (g_moduleFailureReportFlags._2_1_ != 0) {
      return pvVar1;
    }
    hModule = GetModuleHandleW(L"ntdll.dll");
    if (hModule != (HMODULE)0x0) {
      `void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2::
      pfnRtlDisownModuleHeapAllocation =
           (_func_long_void_ptr_void_ptr *)GetProcAddress(hModule,"RtlDisownModuleHeapAllocation");
    }
    g_moduleFailureReportFlags._2_1_ = 1;
    if (`void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2
        ::pfnRtlDisownModuleHeapAllocation == (_func_long_void_ptr_void_ptr *)0x0) {
      g_moduleFailureReportFlags._2_1_ = 1;
      return pvVar1;
    }
  }
  (*`void*___ptr64___cdecl_wil::details::ProcessHeapAlloc(unsigned_long,unsigned___int64)'::__l2::
    pfnRtlDisownModuleHeapAllocation)(hHeap,pvVar1);
  return pvVar1;
}



===== RecognizeCaughtExceptionFromCallback @ 180004f40 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* long __cdecl wil::details::RecognizeCaughtExceptionFromCallback(unsigned short * __ptr64,unsigned
   __int64) */

long __cdecl wil::details::RecognizeCaughtExceptionFromCallback(ushort *param_1,__uint64 param_2)

{
  long lVar1;
  
  lVar1 = (*g_pfnResultFromCaughtException)();
  if ((-1 < lVar1) || (param_1 != (ushort *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
  }
  return lVar1;
}



===== RecordException @ 180004f8c =====

/* int __cdecl wil::details::RecordException(long) */

int __cdecl wil::details::RecordException(long param_1)

{
  long lVar1;
  
  lVar1 = `int___cdecl_wil::details::RecordException(long)'::__l2::s_cErrorCount;
  `int___cdecl_wil::details::RecordException(long)'::__l2::s_hrErrorLast = param_1;
  LOCK();
  `int___cdecl_wil::details::RecordException(long)'::__l2::s_cErrorCount =
       `int___cdecl_wil::details::RecordException(long)'::__l2::s_cErrorCount + 1;
  UNLOCK();
  return lVar1 + 1;
}



===== RecordFailFast @ 180004fb0 =====

/* int __cdecl wil::details::RecordFailFast(long) */

int __cdecl wil::details::RecordFailFast(long param_1)

{
  `int___cdecl_wil::details::RecordFailFast(long)'::__l2::s_hrErrorLast = param_1;
  return 1;
}



===== RecordLog @ 180004fc4 =====

/* int __cdecl wil::details::RecordLog(long) */

int __cdecl wil::details::RecordLog(long param_1)

{
  long lVar1;
  
  lVar1 = `int___cdecl_wil::details::RecordLog(long)'::__l2::s_cErrorCount;
  `int___cdecl_wil::details::RecordLog(long)'::__l2::s_hrErrorLast = param_1;
  LOCK();
  `int___cdecl_wil::details::RecordLog(long)'::__l2::s_cErrorCount =
       `int___cdecl_wil::details::RecordLog(long)'::__l2::s_cErrorCount + 1;
  UNLOCK();
  return lVar1 + 1;
}



===== RecordReturn @ 180004fe4 =====

/* int __cdecl wil::details::RecordReturn(long) */

int __cdecl wil::details::RecordReturn(long param_1)

{
  long lVar1;
  
  lVar1 = `int___cdecl_wil::details::RecordReturn(long)'::__l2::s_cErrorCount;
  `int___cdecl_wil::details::RecordReturn(long)'::__l2::s_hrErrorLast = param_1;
  LOCK();
  `int___cdecl_wil::details::RecordReturn(long)'::__l2::s_cErrorCount =
       `int___cdecl_wil::details::RecordReturn(long)'::__l2::s_cErrorCount + 1;
  UNLOCK();
  return lVar1 + 1;
}



===== Release @ 180005004 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details_abi::ProcessLocalStorageData<struct
   wil::details_abi::ProcessLocalData>::Release(void) __ptr64 */

void __thiscall
wil::details_abi::ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Release
          (ProcessLocalStorageData<wil::details_abi::ProcessLocalData> *this)

{
  uchar uVar1;
  DWORD DVar2;
  BOOL BVar3;
  HANDLE pvVar4;
  char *pcVar5;
  void *unaff_retaddr;
  
  if ((details::g_processShutdownInProgress) ||
     ((details::g_pfnDllShutdownInProgress != (_func_uchar *)0x0 &&
      (uVar1 = (*details::g_pfnDllShutdownInProgress)(), uVar1 != '\0')))) {
    *(int *)this = *(int *)this + -1;
  }
  else {
    pvVar4 = *(HANDLE *)(this + 8);
    pcVar5 = (char *)0x0;
    DVar2 = WaitForSingleObjectEx(pvVar4,0xffffffff,0);
    if (DVar2 == 0x102) {
      pvVar4 = (HANDLE)0x0;
    }
    else if ((DVar2 & 0xffffff7f) != 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::FailFast_Unexpected
                (unaff_retaddr,0xc37,"onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
    }
    *(int *)this = *(int *)this + -1;
    if (*(int *)this == 0) {
      details::
      unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
      ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
               *)(this + 0x10),(void *)0x0);
      details::
      unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
      ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
               *)(this + 0x18),(void *)0x0);
      if (pvVar4 != (HANDLE)0x0) {
        DVar2 = GetLastError();
        BVar3 = ReleaseMutex(pvVar4);
        if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,pcVar5);
        }
        SetLastError(DVar2);
      }
      ThreadLocalStorage<wil::details_abi::ThreadLocalData>::
      ~ThreadLocalStorage<wil::details_abi::ThreadLocalData>
                ((ThreadLocalStorage<wil::details_abi::ThreadLocalData> *)(this + 0x28));
      SemaphoreValue::~SemaphoreValue((SemaphoreValue *)(this + 0x10));
      if ((*(HANDLE *)(this + 8) != (HANDLE)0x0) &&
         (BVar3 = CloseHandle(*(HANDLE *)(this + 8)), BVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
        details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,pcVar5);
      }
      pvVar4 = GetProcessHeap();
      HeapFree(pvVar4,0,this);
    }
    else if ((pvVar4 != (HANDLE)0x0) && (BVar3 = ReleaseMutex(pvVar4), BVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,pcVar5);
    }
  }
  return;
}



===== ResultFromCaughtExceptionInternal @ 1800051a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* struct wil::details::ResultStatus __cdecl
   wil::details::ResultFromCaughtExceptionInternal(unsigned short * __ptr64,unsigned __int64,bool *
   __ptr64) */

ushort * __cdecl
wil::details::ResultFromCaughtExceptionInternal(ushort *param_1,__uint64 param_2,bool *param_3)

{
  long lVar1;
  undefined1 *in_R9;
  
  if (param_2 != 0) {
    *(undefined2 *)param_2 = 0;
  }
  *in_R9 = 0;
  if (g_pfnResultFromCaughtException_CppWinRt != (code *)0x0) {
    lVar1 = (*g_pfnResultFromCaughtException_CppWinRt)();
    if (lVar1 < 0) goto LAB_1800051f5;
  }
  if (g_pfnResultFromCaughtException_WinRt == (code *)0x0) {
    if (g_pfnResultFromCaughtException == (_func_long *)0x0) {
                    /* WARNING: Subroutine does not return */
      _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
    }
                    /* WARNING: Subroutine does not return */
    _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
  }
  lVar1 = (*g_pfnResultFromCaughtException_WinRt)(param_2,param_3);
LAB_1800051f5:
  *(long *)param_1 = lVar1;
  lVar1 = HrToNtStatus(lVar1);
  *(long *)(param_1 + 2) = lVar1;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



===== Rethrow @ 1800052a0 =====

/* void __cdecl wil::details::Rethrow(void) */

void __cdecl wil::details::Rethrow(void)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== Return_GetLastError @ 1800052b4 =====

/* long __cdecl wil::details::in1diag3::Return_GetLastError(void * __ptr64,unsigned int,char const *
   __ptr64) */

long __cdecl wil::details::in1diag3::Return_GetLastError(void *param_1,uint param_2,char *param_3)

{
  long lVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffe8;
  
  lVar1 = ReportFailure_GetLastErrorHr<1>
                    (param_1,param_2,param_3,in_R9,in_stack_ffffffffffffffe8,unaff_retaddr);
  return lVar1;
}



===== Return_Hr @ 1800052d4 =====

/* void __cdecl wil::details::in1diag3::Return_Hr(void * __ptr64,unsigned int,char const *
   __ptr64,long) */

void __cdecl
wil::details::in1diag3::Return_Hr(void *param_1,uint param_2,char *param_3,long param_4)

{
  undefined4 in_register_0000008c;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  
  ReportFailure_Hr<1>(param_1,param_2,param_3,(char *)CONCAT44(in_register_0000008c,param_4),
                      in_stack_ffffffffffffffd8,unaff_retaddr,param_4);
  return;
}



===== RtlDllShutdownInProgress @ 180005300 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* unsigned char __cdecl wil::details::RtlDllShutdownInProgress(void) */

uchar __cdecl wil::details::RtlDllShutdownInProgress(void)

{
  uchar uVar1;
  
  if (`unsigned_char___cdecl_wil::details::RtlDllShutdownInProgress(void)'::__l2::
      s_pfnRtlDllShutdownInProgress == (_func_uchar *)0x0) {
    if (`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
        wil_details_ntdllModuleHandle == (HINSTANCE__ *)0x0) {
      `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
      wil_details_ntdllModuleHandle = GetModuleHandleW(L"ntdll.dll");
    }
    `unsigned_char___cdecl_wil::details::RtlDllShutdownInProgress(void)'::__l2::
    s_pfnRtlDllShutdownInProgress =
         (_func_uchar *)
         GetProcAddress(`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'
                        ::__l2::wil_details_ntdllModuleHandle,"RtlDllShutdownInProgress");
    if ((FARPROC)`unsigned_char___cdecl_wil::details::RtlDllShutdownInProgress(void)'::__l2::
                 s_pfnRtlDllShutdownInProgress == (FARPROC)0x0) {
      return '\0';
    }
  }
  uVar1 = (*`unsigned_char___cdecl_wil::details::RtlDllShutdownInProgress(void)'::__l2::
            s_pfnRtlDllShutdownInProgress)();
  return uVar1;
}



===== RtlNtStatusToDosErrorNoTeb @ 180005380 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* unsigned long __cdecl wil::details::RtlNtStatusToDosErrorNoTeb(long) */

ulong __cdecl wil::details::RtlNtStatusToDosErrorNoTeb(long param_1)

{
  ulong uVar1;
  
  if (`unsigned_long___cdecl_wil::details::RtlNtStatusToDosErrorNoTeb(long)'::__l2::
      s_pfnRtlNtStatusToDosErrorNoTeb == (_func_ulong_long *)0x0) {
    if (`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
        wil_details_ntdllModuleHandle == (HINSTANCE__ *)0x0) {
      `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
      wil_details_ntdllModuleHandle = GetModuleHandleW(L"ntdll.dll");
    }
    `unsigned_long___cdecl_wil::details::RtlNtStatusToDosErrorNoTeb(long)'::__l2::
    s_pfnRtlNtStatusToDosErrorNoTeb =
         (_func_ulong_long *)
         GetProcAddress(`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'
                        ::__l2::wil_details_ntdllModuleHandle,"RtlNtStatusToDosErrorNoTeb");
    if (`unsigned_long___cdecl_wil::details::RtlNtStatusToDosErrorNoTeb(long)'::__l2::
        s_pfnRtlNtStatusToDosErrorNoTeb == (_func_ulong_long *)0x0) {
      return 0;
    }
  }
  uVar1 = (*`unsigned_long___cdecl_wil::details::RtlNtStatusToDosErrorNoTeb(long)'::__l2::
            s_pfnRtlNtStatusToDosErrorNoTeb)(param_1);
  return uVar1;
}



===== Set @ 180005400 =====

/* public: void __cdecl wil::details_abi::ThreadLocalFailureInfo::Set(struct wil::FailureInfo const
   & __ptr64,unsigned int) __ptr64 */

void __thiscall
wil::details_abi::ThreadLocalFailureInfo::Set
          (ThreadLocalFailureInfo *this,FailureInfo *param_1,uint param_2)

{
  ThreadLocalFailureInfo *pTVar1;
  uchar *puVar2;
  LPVOID lpMem;
  char *pcVar3;
  longlong lVar4;
  void *pvVar5;
  HANDLE hHeap;
  longlong lVar6;
  uchar *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong _MaxCount;
  
  *(uint *)(this + 4) = param_2;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x18) = *(undefined2 *)(param_1 + 0x40);
  this[0x1a] = *(ThreadLocalFailureInfo *)param_1;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(param_1 + 0x88);
  *(undefined8 *)(this + 0x30) = *(undefined8 *)(param_1 + 0x90);
  *(undefined8 *)(this + 0x38) = 0;
  if (*(longlong *)(param_1 + 0x38) == 0) {
    lVar4 = 1;
  }
  else {
    lVar9 = -1;
    do {
      lVar4 = lVar9;
      lVar9 = lVar4 + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x38) + lVar9) != '\0');
    lVar4 = lVar4 + 2;
  }
  if (*(longlong *)(param_1 + 0x80) == 0) {
    lVar6 = 1;
  }
  else {
    lVar9 = -1;
    do {
      lVar6 = lVar9;
      lVar9 = lVar6 + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x80) + lVar9) != '\0');
    lVar6 = lVar6 + 2;
  }
  if (*(longlong *)(param_1 + 0x18) == 0) {
    lVar9 = 2;
  }
  else {
    lVar9 = -1;
    do {
      lVar9 = lVar9 + 1;
    } while (*(short *)(*(longlong *)(param_1 + 0x18) + lVar9 * 2) != 0);
    lVar9 = lVar9 * 2 + 2;
  }
  uVar8 = lVar9 + lVar6 + lVar4;
  pTVar1 = this + 0x48;
  if (((*(longlong *)(this + 0x40) == 0) || (*(ulonglong *)pTVar1 < uVar8)) &&
     (pvVar5 = details::ProcessHeapAlloc(8,uVar8), pvVar5 != (void *)0x0)) {
    lpMem = *(LPVOID *)(this + 0x40);
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
    *(void **)(this + 0x40) = pvVar5;
    *(ulonglong *)pTVar1 = uVar8;
  }
  puVar7 = *(uchar **)(this + 0x40);
  if (puVar7 == (uchar *)0x0) {
    return;
  }
  uVar8 = *(ulonglong *)pTVar1;
  pTVar1 = this + 0x10;
  pcVar3 = *(char **)(param_1 + 0x38);
  puVar2 = puVar7 + uVar8;
  if (((puVar7 == puVar2) || (pcVar3 == (char *)0x0)) || (*pcVar3 == '\0')) {
LAB_180005572:
    if (pTVar1 != (ThreadLocalFailureInfo *)0x0) {
      *(undefined8 *)pTVar1 = 0;
    }
  }
  else {
    lVar9 = -1;
    do {
      lVar4 = lVar9;
      lVar9 = lVar4 + 1;
    } while (pcVar3[lVar9] != '\0');
    _MaxCount = lVar4 + 2;
    if (uVar8 < _MaxCount) goto LAB_180005572;
    memcpy_s(puVar7,uVar8,pcVar3,_MaxCount);
    if (pTVar1 != (ThreadLocalFailureInfo *)0x0) {
      *(uchar **)pTVar1 = puVar7;
    }
    puVar7 = puVar7 + _MaxCount;
  }
  pcVar3 = *(char **)(param_1 + 0x80);
  pTVar1 = this + 0x20;
  if (((puVar7 != puVar2) && (pcVar3 != (char *)0x0)) && (lVar9 = -1, *pcVar3 != '\0')) {
    do {
      lVar4 = lVar9;
      lVar9 = lVar4 + 1;
    } while (pcVar3[lVar9] != '\0');
    uVar8 = lVar4 + 2;
    if (uVar8 <= (ulonglong)((longlong)puVar2 - (longlong)puVar7)) {
      memcpy_s(puVar7,(longlong)puVar2 - (longlong)puVar7,pcVar3,uVar8);
      if (pTVar1 != (ThreadLocalFailureInfo *)0x0) {
        *(uchar **)pTVar1 = puVar7;
      }
      puVar7 = puVar7 + uVar8;
      goto LAB_1800055cc;
    }
  }
  if (pTVar1 != (ThreadLocalFailureInfo *)0x0) {
    *(undefined8 *)pTVar1 = 0;
  }
LAB_1800055cc:
  puVar7 = details::WriteResultString<unsigned_short_const*___ptr64>
                     (puVar7,puVar2,*(ushort **)(param_1 + 0x18),(ushort **)(this + 0x38));
  memset(puVar7,0,(longlong)puVar2 - (longlong)puVar7);
  return;
}



===== SetFailureInfo @ 180005614 =====

/* public: void __cdecl wil::StoredFailureInfo::SetFailureInfo(struct wil::FailureInfo const &
   __ptr64) __ptr64 */

void __thiscall wil::StoredFailureInfo::SetFailureInfo(StoredFailureInfo *this,FailureInfo *param_1)

{
  StoredFailureInfo *pSVar1;
  shared_buffer *this_00;
  uchar *puVar2;
  int iVar3;
  int *piVar4;
  LPVOID lpMem;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  longlong lVar10;
  longlong lVar11;
  HANDLE hHeap;
  longlong lVar12;
  uchar *puVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  longlong lVar20;
  ulonglong uVar21;
  longlong local_res8;
  
  uVar9 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(undefined8 *)(this + 8) = uVar9;
  uVar9 = *(undefined8 *)(param_1 + 0x18);
  lVar16 = 2;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x18) = uVar9;
  uVar9 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x28) = uVar9;
  uVar9 = *(undefined8 *)(param_1 + 0x38);
  *(undefined8 *)(this + 0x30) = *(undefined8 *)(param_1 + 0x30);
  *(undefined8 *)(this + 0x38) = uVar9;
  uVar9 = *(undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(this + 0x40) = *(undefined8 *)(param_1 + 0x40);
  *(undefined8 *)(this + 0x48) = uVar9;
  uVar9 = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(this + 0x50) = *(undefined8 *)(param_1 + 0x50);
  *(undefined8 *)(this + 0x58) = uVar9;
  uVar9 = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(this + 0x60) = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(this + 0x68) = uVar9;
  uVar6 = *(undefined4 *)(param_1 + 0x74);
  uVar7 = *(undefined4 *)(param_1 + 0x78);
  uVar8 = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(this + 0x74) = uVar6;
  *(undefined4 *)(this + 0x78) = uVar7;
  *(undefined4 *)(this + 0x7c) = uVar8;
  uVar6 = *(undefined4 *)(param_1 + 0x84);
  uVar7 = *(undefined4 *)(param_1 + 0x88);
  uVar8 = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = uVar6;
  *(undefined4 *)(this + 0x88) = uVar7;
  *(undefined4 *)(this + 0x8c) = uVar8;
  *(undefined8 *)(this + 0x90) = *(undefined8 *)(param_1 + 0x90);
  if (*(longlong *)(param_1 + 0x18) == 0) {
    local_res8 = 2;
  }
  else {
    lVar11 = -1;
    do {
      lVar11 = lVar11 + 1;
    } while (*(short *)(*(longlong *)(param_1 + 0x18) + lVar11 * 2) != 0);
    local_res8 = lVar11 * 2 + 2;
  }
  if (*(longlong *)(param_1 + 0x28) == 0) {
    lVar19 = 1;
  }
  else {
    lVar11 = -1;
    do {
      lVar19 = lVar11;
      lVar11 = lVar19 + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x28) + lVar11) != '\0');
    lVar19 = lVar19 + 2;
  }
  lVar11 = 1;
  if (*(longlong *)(param_1 + 0x30) == 0) {
    lVar15 = lVar11;
  }
  else {
    lVar20 = -1;
    do {
      lVar15 = lVar20;
      lVar20 = lVar15 + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x30) + lVar20) != '\0');
    lVar15 = lVar15 + 2;
  }
  if (*(longlong *)(param_1 + 0x38) == 0) {
    lVar18 = lVar11;
  }
  else {
    lVar20 = -1;
    do {
      lVar18 = lVar20;
      lVar20 = lVar18 + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x38) + lVar20) != '\0');
    lVar18 = lVar18 + 2;
  }
  if (*(longlong *)(param_1 + 0x48) == 0) {
    lVar17 = lVar11;
  }
  else {
    lVar20 = -1;
    do {
      lVar17 = lVar20;
      lVar20 = lVar17 + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x48) + lVar20) != '\0');
    lVar17 = lVar17 + 2;
  }
  if (*(longlong *)(param_1 + 0x80) == 0) {
    lVar14 = lVar11;
  }
  else {
    lVar20 = -1;
    do {
      lVar14 = lVar20;
      lVar20 = lVar14 + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x80) + lVar20) != '\0');
    lVar14 = lVar14 + 2;
  }
  if (*(longlong *)(param_1 + 0x70) == 0) {
    lVar12 = lVar11;
  }
  else {
    lVar20 = -1;
    do {
      lVar12 = lVar20;
      lVar20 = lVar12 + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x70) + lVar20) != '\0');
    lVar12 = lVar12 + 2;
  }
  if (*(longlong *)(param_1 + 0x78) == 0) {
    lVar20 = 2;
  }
  else {
    lVar20 = -1;
    do {
      lVar20 = lVar20 + 1;
    } while (*(short *)(*(longlong *)(param_1 + 0x78) + lVar20 * 2) != 0);
    lVar20 = lVar20 * 2 + 2;
  }
  if (*(longlong *)(param_1 + 0x58) != 0) {
    lVar10 = -1;
    do {
      lVar11 = lVar10;
      lVar10 = lVar11 + 1;
    } while (*(char *)(*(longlong *)(param_1 + 0x58) + lVar10) != '\0');
    lVar11 = lVar11 + 2;
  }
  if (*(longlong *)(param_1 + 0x60) != 0) {
    lVar16 = -1;
    do {
      lVar16 = lVar16 + 1;
    } while (*(short *)(*(longlong *)(param_1 + 0x60) + lVar16 * 2) != 0);
    lVar16 = lVar16 * 2 + 2;
  }
  this_00 = (shared_buffer *)(this + 0x98);
  piVar4 = *(int **)this_00;
  uVar21 = lVar16 + lVar11 + lVar20 + lVar12 + lVar14 + lVar17 + lVar18 + lVar15 + lVar19 +
           local_res8;
  if (piVar4 == (int *)0x0) {
LAB_180005851:
    details::shared_buffer::create(this_00,uVar21);
  }
  else if ((*piVar4 != 1) || (*(ulonglong *)(this + 0xa0) < uVar21)) {
    if (piVar4 != (int *)0x0) {
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        lpMem = *(LPVOID *)this_00;
        hHeap = GetProcessHeap();
        HeapFree(hHeap,0,lpMem);
      }
      *(undefined8 *)this_00 = 0;
      *(undefined8 *)(this + 0xa0) = 0;
    }
    goto LAB_180005851;
  }
  puVar13 = (uchar *)(-(ulonglong)(*(longlong *)this_00 != 0) & *(longlong *)this_00 + 4U);
  if (puVar13 == (uchar *)0x0) {
    return;
  }
  puVar2 = puVar13 + *(longlong *)(this + 0xa0);
  puVar13 = details::WriteResultString<unsigned_short_const*___ptr64>
                      (puVar13,puVar2,*(ushort **)(param_1 + 0x18),(ushort **)(this + 0x18));
  pcVar5 = *(char **)(param_1 + 0x28);
  pSVar1 = this + 0x28;
  if (((puVar13 == puVar2) || (pcVar5 == (char *)0x0)) || (*pcVar5 == '\0')) {
LAB_1800058dd:
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(undefined8 *)pSVar1 = 0;
    }
  }
  else {
    lVar16 = -1;
    do {
      lVar11 = lVar16;
      lVar16 = lVar11 + 1;
    } while (pcVar5[lVar16] != '\0');
    uVar21 = lVar11 + 2;
    if ((ulonglong)((longlong)puVar2 - (longlong)puVar13) < uVar21) goto LAB_1800058dd;
    memcpy_s(puVar13,(longlong)puVar2 - (longlong)puVar13,pcVar5,uVar21);
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(uchar **)pSVar1 = puVar13;
    }
    puVar13 = puVar13 + uVar21;
  }
  pcVar5 = *(char **)(param_1 + 0x30);
  pSVar1 = this + 0x30;
  if (((puVar13 == puVar2) || (pcVar5 == (char *)0x0)) || (*pcVar5 == '\0')) {
LAB_180005932:
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(undefined8 *)pSVar1 = 0;
    }
  }
  else {
    lVar16 = -1;
    do {
      lVar11 = lVar16;
      lVar16 = lVar11 + 1;
    } while (pcVar5[lVar16] != '\0');
    uVar21 = lVar11 + 2;
    if ((ulonglong)((longlong)puVar2 - (longlong)puVar13) < uVar21) goto LAB_180005932;
    memcpy_s(puVar13,(longlong)puVar2 - (longlong)puVar13,pcVar5,uVar21);
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(uchar **)pSVar1 = puVar13;
    }
    puVar13 = puVar13 + uVar21;
  }
  pcVar5 = *(char **)(param_1 + 0x38);
  pSVar1 = this + 0x38;
  if (((puVar13 == puVar2) || (pcVar5 == (char *)0x0)) || (*pcVar5 == '\0')) {
LAB_180005987:
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(undefined8 *)pSVar1 = 0;
    }
  }
  else {
    lVar16 = -1;
    do {
      lVar11 = lVar16;
      lVar16 = lVar11 + 1;
    } while (pcVar5[lVar16] != '\0');
    uVar21 = lVar11 + 2;
    if ((ulonglong)((longlong)puVar2 - (longlong)puVar13) < uVar21) goto LAB_180005987;
    memcpy_s(puVar13,(longlong)puVar2 - (longlong)puVar13,pcVar5,uVar21);
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(uchar **)pSVar1 = puVar13;
    }
    puVar13 = puVar13 + uVar21;
  }
  pcVar5 = *(char **)(param_1 + 0x48);
  pSVar1 = this + 0x48;
  if (((puVar13 == puVar2) || (pcVar5 == (char *)0x0)) || (*pcVar5 == '\0')) {
LAB_1800059dc:
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(undefined8 *)pSVar1 = 0;
    }
  }
  else {
    lVar16 = -1;
    do {
      lVar11 = lVar16;
      lVar16 = lVar11 + 1;
    } while (pcVar5[lVar16] != '\0');
    uVar21 = lVar11 + 2;
    if ((ulonglong)((longlong)puVar2 - (longlong)puVar13) < uVar21) goto LAB_1800059dc;
    memcpy_s(puVar13,(longlong)puVar2 - (longlong)puVar13,pcVar5,uVar21);
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(uchar **)pSVar1 = puVar13;
    }
    puVar13 = puVar13 + uVar21;
  }
  pcVar5 = *(char **)(param_1 + 0x80);
  pSVar1 = this + 0x80;
  if (((puVar13 == puVar2) || (pcVar5 == (char *)0x0)) || (*pcVar5 == '\0')) {
LAB_180005a37:
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(undefined8 *)pSVar1 = 0;
    }
  }
  else {
    lVar16 = -1;
    do {
      lVar11 = lVar16;
      lVar16 = lVar11 + 1;
    } while (pcVar5[lVar16] != '\0');
    uVar21 = lVar11 + 2;
    if ((ulonglong)((longlong)puVar2 - (longlong)puVar13) < uVar21) goto LAB_180005a37;
    memcpy_s(puVar13,(longlong)puVar2 - (longlong)puVar13,pcVar5,uVar21);
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(uchar **)pSVar1 = puVar13;
    }
    puVar13 = puVar13 + uVar21;
  }
  pcVar5 = *(char **)(param_1 + 0x70);
  pSVar1 = this + 0x70;
  if (((puVar13 == puVar2) || (pcVar5 == (char *)0x0)) || (*pcVar5 == '\0')) {
LAB_180005a8a:
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(undefined8 *)pSVar1 = 0;
    }
  }
  else {
    lVar16 = -1;
    do {
      lVar11 = lVar16;
      lVar16 = lVar11 + 1;
    } while (pcVar5[lVar16] != '\0');
    uVar21 = lVar11 + 2;
    if ((ulonglong)((longlong)puVar2 - (longlong)puVar13) < uVar21) goto LAB_180005a8a;
    memcpy_s(puVar13,(longlong)puVar2 - (longlong)puVar13,pcVar5,uVar21);
    if (pSVar1 != (StoredFailureInfo *)0x0) {
      *(uchar **)pSVar1 = puVar13;
    }
    puVar13 = puVar13 + uVar21;
  }
  puVar13 = details::WriteResultString<unsigned_short_const*___ptr64>
                      (puVar13,puVar2,*(ushort **)(param_1 + 0x78),(ushort **)(this + 0x78));
  pcVar5 = *(char **)(param_1 + 0x58);
  pSVar1 = this + 0x58;
  if (((puVar13 != puVar2) && (pcVar5 != (char *)0x0)) && (lVar16 = -1, *pcVar5 != '\0')) {
    do {
      lVar11 = lVar16;
      lVar16 = lVar11 + 1;
    } while (pcVar5[lVar16] != '\0');
    uVar21 = lVar11 + 2;
    if (uVar21 <= (ulonglong)((longlong)puVar2 - (longlong)puVar13)) {
      memcpy_s(puVar13,(longlong)puVar2 - (longlong)puVar13,pcVar5,uVar21);
      if (pSVar1 != (StoredFailureInfo *)0x0) {
        *(uchar **)pSVar1 = puVar13;
      }
      puVar13 = puVar13 + uVar21;
      goto LAB_180005afa;
    }
  }
  if (pSVar1 != (StoredFailureInfo *)0x0) {
    *(undefined8 *)pSVar1 = 0;
  }
LAB_180005afa:
  puVar13 = details::WriteResultString<unsigned_short_const*___ptr64>
                      (puVar13,puVar2,*(ushort **)(param_1 + 0x60),(ushort **)(this + 0x60));
  memset(puVar13,0,(longlong)puVar2 - (longlong)puVar13);
  return;
}



===== SetLastError @ 180005b44 =====

/* public: void __cdecl wil::details_abi::ThreadLocalData::SetLastError(struct wil::FailureInfo
   const & __ptr64) __ptr64 */

void __thiscall
wil::details_abi::ThreadLocalData::SetLastError(ThreadLocalData *this,FailureInfo *param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  int *piVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  int *piVar7;
  
  iVar3 = *(int *)(this + 0x10);
  if ((*(longlong *)(this + 0x18) == 0) && (iVar3 != 0)) {
    puVar6 = details::ProcessHeapAlloc(8,400);
    *(undefined2 **)(this + 0x18) = puVar6;
    if (puVar6 != (undefined2 *)0x0) {
      *(undefined4 *)(this + 0x20) = 5;
      puVar2 = puVar6 + 200;
      for (; puVar6 != puVar2; puVar6 = puVar6 + 0x28) {
        *puVar6 = 0x50;
      }
    }
  }
  piVar4 = *(int **)(this + 0x18);
  if (piVar4 != (int *)0x0) {
    if ((iVar3 != 0) && (piVar4 != piVar4 + (ulonglong)*(ushort *)(this + 0x20) * 0x14)) {
      piVar7 = piVar4 + 2;
      do {
        if ((*(uint *)(this + 0x10) < (uint)piVar7[-1]) && (*piVar7 == *(int *)(param_1 + 8))) {
          return;
        }
        piVar1 = piVar7 + 0x12;
        piVar7 = piVar7 + 0x14;
      } while (piVar1 != piVar4 + (ulonglong)*(ushort *)(this + 0x20) * 0x14);
    }
    uVar5 = (ulonglong)(*(ushort *)(this + 0x22) + 1) % (ulonglong)*(ushort *)(this + 0x20);
    *(short *)(this + 0x22) = (short)uVar5;
    piVar7 = *(int **)(this + 8);
    LOCK();
    iVar3 = *piVar7;
    *piVar7 = *piVar7 + 1;
    UNLOCK();
    ThreadLocalFailureInfo::Set((ThreadLocalFailureInfo *)(piVar4 + uVar5 * 0x14),param_1,iVar3 + 1)
    ;
  }
  return;
}



===== StringCchCatW @ 180005c48 =====

/* long __cdecl StringCchCatW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64) */

long __cdecl StringCchCatW(ushort *param_1,__uint64 param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  longlong lVar4;
  ushort *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  
  lVar7 = 0x104;
  puVar3 = param_1;
  do {
    if (*puVar3 == 0) break;
    puVar3 = puVar3 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar6 = -(ulonglong)(lVar7 != 0) & 0x104U - lVar7;
  uVar2 = ~-(uint)(lVar7 != 0) & 0x80070057;
  if (lVar7 != 0) {
    puVar3 = param_1 + uVar6;
    lVar7 = 0x104 - uVar6;
    if (lVar7 != 0) {
      lVar4 = 0x7ffffffe;
      lVar8 = (longlong)param_3 - (longlong)puVar3;
      do {
        if ((lVar4 == 0) || (uVar1 = *(ushort *)(lVar8 + (longlong)puVar3), uVar1 == 0)) break;
        *puVar3 = uVar1;
        lVar4 = lVar4 + -1;
        puVar3 = puVar3 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    puVar5 = puVar3 + -1;
    if (lVar7 != 0) {
      puVar5 = puVar3;
    }
    *puVar5 = 0;
    uVar2 = ~-(uint)(lVar7 != 0) & 0x8007007a;
  }
  return uVar2;
}



===== StringCchPrintfW @ 180005cf0 =====

/* long __cdecl StringCchPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl StringCchPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  size_t _Count;
  int iVar1;
  long lVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (param_2 - 1 < 0x7fffffff) {
    _Count = param_2 - 1;
    lVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf((wchar_t *)param_1,_Count,(wchar_t *)param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      lVar2 = -0x7ff8ff86;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = 0;
  }
  else {
    lVar2 = -0x7ff8ffa9;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar2;
}



===== ThrowResultException @ 180005d64 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::ThrowResultException(struct wil::FailureInfo const & __ptr64) */

void __cdecl wil::ThrowResultException(FailureInfo *param_1)

{
  if (details::g_pfnThrowResultException != (_func_void_FailureInfo_ptr *)0x0) {
    (*details::g_pfnThrowResultException)(param_1);
  }
  return;
}



===== ThrowResultExceptionInternal @ 180005d90 =====

/* void __cdecl wil::details::ThrowResultExceptionInternal(struct wil::FailureInfo const & __ptr64)
    */

void __cdecl wil::details::ThrowResultExceptionInternal(FailureInfo *param_1)

{
  ResultException local_d8 [216];
  
  ResultException::ResultException(local_d8,param_1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_d8,(ThrowInfo *)&_TI2_AVResultException_wil__);
}



===== TryGetValueInternal @ 180005dbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static long __cdecl wil::details_abi::SemaphoreValue::TryGetValueInternal(unsigned short
   const * __ptr64,bool,unsigned __int64 * __ptr64,bool * __ptr64) */

long __cdecl
wil::details_abi::SemaphoreValue::TryGetValueInternal
          (ushort *param_1,bool param_2,__uint64 *param_3,bool *param_4)

{
  WCHAR WVar1;
  long lVar2;
  BOOL BVar3;
  DWORD DVar4;
  WCHAR *pWVar5;
  HANDLE hObject;
  HANDLE hObject_00;
  WCHAR *pWVar6;
  long *plVar7;
  LPCWSTR pWVar8;
  longlong lVar9;
  void *unaff_retaddr;
  undefined1 auStack_268 [32];
  long local_248;
  long local_244 [3];
  WCHAR local_238 [264];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_268;
  *param_3 = 0;
  pWVar6 = local_238;
  lVar9 = 0x104;
  do {
    if ((lVar9 == -0x7ffffefa) ||
       (WVar1 = *(WCHAR *)(((longlong)param_1 - (longlong)local_238) + (longlong)pWVar6),
       WVar1 == L'\0')) break;
    *pWVar6 = WVar1;
    pWVar6 = pWVar6 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  pWVar5 = pWVar6 + -1;
  if (lVar9 != 0) {
    pWVar5 = pWVar6;
  }
  *pWVar5 = L'\0';
  StringCchCatW((ushort *)local_238,(__uint64)pWVar6,(ushort *)L"_p0");
  pWVar8 = local_238;
  hObject = OpenSemaphoreW(0x1f0003,0,pWVar8);
  if (hObject == (HANDLE)0x0) {
    DVar4 = GetLastError();
    if (DVar4 != 2) {
      lVar2 = details::in1diag3::Return_GetLastError(unaff_retaddr,0xcd,(char *)pWVar8);
      return lVar2;
    }
  }
  else {
    plVar7 = local_244;
    local_244[0] = 0;
    local_248 = 0;
    lVar2 = GetValueFromSemaphore(hObject,plVar7);
    if (lVar2 < 0) {
      details::in1diag3::Return_Hr(unaff_retaddr,0xd3,(char *)pWVar8,lVar2);
      BVar3 = CloseHandle(hObject);
      if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pWVar8);
      }
      goto LAB_180005fe5;
    }
    StringCchCatW((ushort *)local_238,(__uint64)plVar7,(ushort *)L"h");
    pWVar8 = local_238;
    hObject_00 = OpenSemaphoreW(0x1f0003,0,pWVar8);
    if (hObject_00 == (HANDLE)0x0) {
      lVar2 = details::in1diag3::Return_GetLastError(unaff_retaddr,0xd9,(char *)pWVar8);
      BVar3 = CloseHandle(hObject);
      if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pWVar8);
      }
      goto LAB_180005fe5;
    }
    lVar2 = GetValueFromSemaphore(hObject_00,&local_248);
    if (lVar2 < 0) {
      details::in1diag3::Return_Hr(unaff_retaddr,0xdb,(char *)pWVar8,lVar2);
      BVar3 = CloseHandle(hObject_00);
      if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pWVar8);
      }
      BVar3 = CloseHandle(hObject);
      if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pWVar8);
      }
      return lVar2;
    }
    BVar3 = CloseHandle(hObject_00);
    if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pWVar8);
    }
    *param_3 = (longlong)local_248 << 0x1f | (longlong)local_244[0];
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pWVar8);
    }
  }
  lVar2 = 0;
LAB_180005fe5:
  return lVar2;
}



===== WilDynamicLoadRaiseFailFastException @ 180006090 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilDynamicLoadRaiseFailFastException(struct _EXCEPTION_RECORD *
   __ptr64,struct _CONTEXT * __ptr64,unsigned long) */

void __cdecl
wil::details::WilDynamicLoadRaiseFailFastException
          (_EXCEPTION_RECORD *param_1,_CONTEXT *param_2,ulong param_3)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleW(L"kernelbase.dll");
  pFVar1 = GetProcAddress(hModule,"RaiseFailFastException");
  if (pFVar1 != (FARPROC)0x0) {
    (*pFVar1)(param_1,param_2,param_3);
  }
  return;
}



===== WilFailFast @ 1800060fc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilFailFast(struct wil::FailureInfo const & __ptr64) */

void __cdecl wil::details::WilFailFast(FailureInfo *param_1)

{
  code *pcVar1;
  _CONTEXT *p_Var2;
  _EXCEPTION_RECORD local_a8;
  
  if (g_pfnWilFailFast != (_func_bool_FailureInfo_ptr *)0x0) {
    (*g_pfnWilFailFast)(param_1);
  }
  if (g_pfnFailfastWithContextCallback != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnFailfastWithContextCallback)(param_1);
  }
  p_Var2 = (_CONTEXT *)0x0;
  memset(&local_a8,0,0x98);
  local_a8.ExceptionAddress = *(PVOID *)(param_1 + 0x88);
  local_a8.NumberParameters = 1;
  local_a8.ExceptionCode = 0xc0000409;
  local_a8.ExceptionFlags = 1;
  local_a8.ExceptionInformation[0] = 7;
  if (local_a8.ExceptionAddress == (PVOID)0x0) {
    WilRaiseFailFastException(&local_a8,p_Var2,1);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  local_a8.ExceptionInformation[1] = (ULONG_PTR)*(int *)(param_1 + 8);
  local_a8.ExceptionInformation[2] = (ULONG_PTR)*(uint *)(param_1 + 0x40);
  local_a8.NumberParameters = 3;
  WilRaiseFailFastException(&local_a8,p_Var2,0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== WilRaiseFailFastException @ 1800061ac =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilRaiseFailFastException(struct _EXCEPTION_RECORD * __ptr64,struct
   _CONTEXT * __ptr64,unsigned long) */

void __cdecl
wil::details::WilRaiseFailFastException(_EXCEPTION_RECORD *param_1,_CONTEXT *param_2,ulong param_3)

{
  code *pcVar1;
  
  if (g_pfnRaiseFailFastException != (_func_void__EXCEPTION_RECORD_ptr__CONTEXT_ptr_ulong *)0x0) {
    (*g_pfnRaiseFailFastException)(param_1,(_CONTEXT *)0x0,param_3);
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(7);
  return;
}



===== __throw_bad_function_call @ 1800061d8 =====

/* void __cdecl wistd::__throw_bad_function_call(void) */

void __cdecl wistd::__throw_bad_function_call(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(7);
  return;
}



===== _FailFast_GetLastError @ 1800061e8 =====

/* void __cdecl wil::details::in1diag3::_FailFast_GetLastError(void * __ptr64,unsigned int,char
   const * __ptr64) */

void __cdecl
wil::details::in1diag3::_FailFast_GetLastError(void *param_1,uint param_2,char *param_3)

{
  code *pcVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffe8;
  
  ReportFailure_GetLastError<3>
            (param_1,param_2,param_3,in_R9,in_stack_ffffffffffffffe8,unaff_retaddr);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== create @ 180006204 =====

/* public: bool __cdecl wil::details::shared_buffer::create(unsigned __int64) __ptr64 */

bool __thiscall wil::details::shared_buffer::create(shared_buffer *this,__uint64 param_1)

{
  int iVar1;
  LPVOID pvVar2;
  int *piVar3;
  bool bVar4;
  HANDLE pvVar5;
  int *piVar6;
  
  if (param_1 == 0) {
    piVar6 = *(int **)this;
    if (piVar6 != (int *)0x0) {
      LOCK();
      iVar1 = *piVar6;
      *piVar6 = *piVar6 + -1;
      UNLOCK();
      if (iVar1 == 1) {
        pvVar2 = *(LPVOID *)this;
        pvVar5 = GetProcessHeap();
        HeapFree(pvVar5,0,pvVar2);
      }
      *(undefined8 *)this = 0;
      *(undefined8 *)(this + 8) = 0;
    }
    bVar4 = true;
  }
  else {
    pvVar5 = GetProcessHeap();
    piVar6 = HeapAlloc(pvVar5,0,param_1 + 4);
    bVar4 = false;
    if (piVar6 != (int *)0x0) {
      *piVar6 = 0;
      piVar3 = *(int **)this;
      if (piVar3 != (int *)0x0) {
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar1 == 1) {
          pvVar2 = *(LPVOID *)this;
          pvVar5 = GetProcessHeap();
          HeapFree(pvVar5,0,pvVar2);
        }
        *(undefined8 *)(this + 8) = 0;
      }
      *(int **)this = piVar6;
      bVar4 = true;
      *(__uint64 *)(this + 8) = param_1;
      LOCK();
      *piVar6 = *piVar6 + 1;
      UNLOCK();
    }
  }
  return bVar4;
}



===== reset @ 180006300 =====

/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64) noexcept,&void __cdecl wil::details::CloseHandle(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void *
   __ptr64,0,std::nullptr_t> >::reset(void * __ptr64) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::reset(unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
        *this,void *param_1)

{
  HANDLE hObject;
  DWORD dwErrCode;
  BOOL BVar1;
  char *in_R8;
  void *unaff_retaddr;
  
  hObject = *(HANDLE *)this;
  if (hObject != (HANDLE)0x0) {
    dwErrCode = GetLastError();
    BVar1 = CloseHandle(hObject);
    if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,in_R8);
    }
    SetLastError(dwErrCode);
  }
  *(void **)this = param_1;
  return;
}



===== what @ 180006380 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual char const * __ptr64 __cdecl wil::ResultException::what(void)const __ptr64 */

char * __thiscall wil::ResultException::what(ResultException *this)

{
  shared_buffer *this_00;
  bool bVar1;
  int cbMultiByte;
  undefined1 auStackY_1058 [32];
  WCHAR local_1018 [2048];
  ulonglong local_18;
  undefined8 uStack_10;
  
  uStack_10 = 0x180006390;
  local_18 = __security_cookie ^ (ulonglong)auStackY_1058;
  this_00 = (shared_buffer *)(this + 0xc0);
  if (*(longlong *)this_00 == 0) {
    GetFailureLogString((ushort *)local_1018,0x800,(FailureInfo *)(this + 0x18));
    cbMultiByte = WideCharToMultiByte(0,0,local_1018,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    bVar1 = details::shared_buffer::create(this_00,(longlong)cbMultiByte);
    if (!bVar1) {
      return "WIL Exception";
    }
    WideCharToMultiByte(0,0,local_1018,-1,
                        (LPSTR)(-(ulonglong)(*(longlong *)this_00 != 0) & *(longlong *)this_00 + 4U)
                        ,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
  }
  return (char *)(-(ulonglong)(*(longlong *)this_00 != 0) & *(longlong *)this_00 + 4U);
}



===== what @ 180006490 =====

/* public: virtual char const * __ptr64 __cdecl std::exception::what(void)const __ptr64 */

char * __thiscall std::exception::what(exception *this)

{
  char *pcVar1;
  
  pcVar1 = "Unknown exception";
  if (*(longlong *)(this + 8) != 0) {
    pcVar1 = *(char **)(this + 8);
  }
  return pcVar1;
}



===== memcpy_s @ 1800064ac =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t *peVar1;
  errno_t eVar2;
  
  if (_MaxCount == 0) {
LAB_1800064c9:
    eVar2 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_1800064d2:
      peVar1 = (errno_t *)_o__errno();
      eVar2 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memcpy(_Dst,_Src,_MaxCount);
        goto LAB_1800064c9;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_1800064d2;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      peVar1 = (errno_t *)_o__errno();
      eVar2 = 0x22;
    }
    *peVar1 = eVar2;
    _o__invalid_parameter_noinfo();
  }
  return eVar2;
}



===== DllMain @ 180006548 =====

bool DllMain(HMODULE param_1,int param_2)

{
  BOOL BVar1;
  bool bVar2;
  
  if (param_2 == 1) {
    BVar1 = DisableThreadLibraryCalls(param_1);
    bVar2 = BVar1 != 0;
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}



===== ReportFailure_Base<0,0> @ 18000657c =====

/* void __cdecl wil::details::ReportFailure_Base<0,0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_Base<0,0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  code *pcVar1;
  char *in_stack_ffffffffffffffc8;
  ReportFailureOptions in_stack_ffffffffffffffe8;
  
  ReportFailure_NoReturn<0>
            (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffc8,param_6,param_7,param_8,
             in_stack_ffffffffffffffe8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ReportFailure_HrMsg<0> @ 1800065b4 =====

/* void __cdecl wil::details::ReportFailure_HrMsg<0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long,char const * __ptr64,char *
   __ptr64) */

void __cdecl
wil::details::ReportFailure_HrMsg<0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7,char *param_8,char *param_9)

{
  code *pcVar1;
  undefined8 *puVar2;
  char *in_stack_ffffffffffffffa8;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_18 [24];
  
  puVar2 = (undefined8 *)ResultStatus::FromResult((long)local_18);
  local_28 = *puVar2;
  local_20 = *(undefined4 *)(puVar2 + 1);
  ReportFailure_Msg<0>
            (param_1,param_2,param_3,param_3,in_stack_ffffffffffffffa8,param_6,
             (ResultStatus *)&local_28,param_8,param_9);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ReportFailure_Msg<0> @ 18000662c =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* void __cdecl wil::details::ReportFailure_Msg<0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,char const * __ptr64,char * __ptr64) */

void __cdecl
wil::details::ReportFailure_Msg<0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,char *param_8,char *param_9)

{
  undefined4 in_register_00000014;
  char *in_stack_ffffffffffffefa8;
  ReportFailureOptions in_stack_ffffffffffffefc8;
  ushort local_1028 [2044];
  undefined8 uStack_30;
  
  uStack_30 = 0x18000663d;
  PrintLoggingMessage(local_1028,CONCAT44(in_register_00000014,param_2),param_8,param_9);
                    /* WARNING: Subroutine does not return */
  ReportFailure_Base<0,0>
            (param_1,param_2,param_3,param_9,in_stack_ffffffffffffefa8,param_6,param_7,local_1028,
             in_stack_ffffffffffffefc8);
}



===== ReportFailure_NoReturn<0> @ 18000669c =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::ReportFailure_NoReturn<0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,struct
   wil::details::ResultStatus const & __ptr64,unsigned short const * __ptr64,enum
   wil::details::ReportFailureOptions) */

void __cdecl
wil::details::ReportFailure_NoReturn<0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ResultStatus *param_7,ushort *param_8,ReportFailureOptions param_9)

{
  BOOL BVar1;
  bool bVar2;
  bool bVar3;
  undefined4 local_14d8;
  uint local_14d4;
  long local_14d0;
  undefined4 local_14cc;
  int local_14c8;
  ushort *local_14c0;
  DWORD local_14b8;
  undefined8 local_14b0;
  undefined8 local_14a8;
  char *local_14a0;
  uint local_1498;
  int local_1494;
  undefined8 local_1490;
  undefined8 local_1488;
  undefined8 uStack_1480;
  undefined8 local_1478;
  undefined8 local_1470;
  undefined8 uStack_1468;
  undefined8 local_1460;
  char *local_1458;
  void *local_1450;
  void *local_1448;
  char local_1438 [1024];
  WCHAR local_1038 [2044];
  undefined8 uStack_40;
  
  uStack_40 = 0x1800066be;
  bVar2 = g_pfnThrowPlatformException != (code *)0x0;
  memset(&local_14d8,0,0x98);
  local_1038[0] = L'\0';
  local_1438[0] = '\0';
  local_14d0 = *(long *)param_7;
  local_14cc = *(undefined4 *)(param_7 + 4);
  local_1494 = RecordException(local_14d0);
  local_14d8 = 0;
  local_14d4 = 0;
  if (*(int *)(param_7 + 8) == 1) {
    local_14d4 = 8;
  }
  LOCK();
  UNLOCK();
  local_14c8 = `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
               ::__l2::s_failureId + 1;
  if ((param_8 == (ushort *)0x0) || (local_14c0 = param_8, *param_8 == 0)) {
    local_14c0 = (ushort *)0x0;
  }
  `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
  ::__l2::s_failureId =
       `void___cdecl_wil::details::LogFailure(void*___ptr64,unsigned_int,char_const*___ptr64,char_const*___ptr64,char_const*___ptr64,void*___ptr64,wil::FailureType,wil::details::ResultStatus_const&___ptr64,unsigned_short_const*___ptr64,bool,unsigned_short*___ptr64,unsigned___int64,char*___ptr64,unsigned___int64,wil::FailureInfo*___ptr64)'
       ::__l2::s_failureId + 1;
  local_14b8 = GetCurrentThreadId();
  local_14b0 = 0;
  local_14a8 = 0;
  local_1450 = param_6;
  local_1490 = 0;
  local_1470 = 0;
  uStack_1468 = 0;
  local_1460 = 0;
  local_1488 = 0;
  uStack_1480 = 0;
  local_1478 = 0;
  local_14a0 = param_3;
  local_1498 = param_2;
  local_1448 = param_1;
  if (g_pfnGetModuleName == (_func_char_ptr *)0x0) {
    local_1458 = (char *)0x0;
  }
  else {
    local_1458 = (*g_pfnGetModuleName)();
  }
  if (g_pfnNotifyFailure != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnNotifyFailure)((FailureInfo *)&local_14d8);
  }
  if (g_pfnGetContextAndNotifyFailure != (_func_void_FailureInfo_ptr_char_ptr___uint64 *)0x0) {
    (*g_pfnGetContextAndNotifyFailure)((FailureInfo *)&local_14d8,local_1438,0x400);
  }
  if (g_pfnLoggingCallback != (_func_void_FailureInfo_ptr *)0x0) {
    (*g_pfnLoggingCallback)((FailureInfo *)&local_14d8);
  }
  if (((g_pfnOriginateCallback != (_func_void_FailureInfo_ptr *)0x0) && (!bVar2)) &&
     ((local_14d4 & 2) == 0)) {
    (*g_pfnOriginateCallback)((FailureInfo *)&local_14d8);
  }
  if (-1 < local_14d0) {
                    /* WARNING: Subroutine does not return */
    wistd::__throw_bad_function_call();
  }
  if (g_fIsDebuggerPresent == false) {
    if (g_pfnIsDebuggerPresent == (_func_bool *)0x0) {
      BVar1 = IsDebuggerPresent();
      bVar3 = BVar1 == 0;
    }
    else {
      bVar3 = (*g_pfnIsDebuggerPresent)();
      bVar3 = !bVar3;
    }
    if (!bVar3) goto LAB_18000686f;
  }
  else {
LAB_18000686f:
    bVar3 = true;
    if ((local_14d4 & 2) == 0) goto LAB_18000687b;
  }
  bVar3 = false;
LAB_18000687b:
  if ((bVar2) || (bVar3)) {
    if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
      (*g_pfnResultLoggingCallback)(&local_14d8,local_1038,0x800);
    }
    if (local_1038[0] == L'\0') {
      GetFailureLogString((ushort *)local_1038,0x800,(FailureInfo *)&local_14d8);
    }
    if (bVar3) {
      OutputDebugStringW(local_1038);
    }
  }
  else if ((g_pfnResultLoggingCallback != (code *)0x0) && (g_resultMessageCallbackSet == false)) {
    (*g_pfnResultLoggingCallback)(&local_14d8,0,0);
  }
  if ((((local_14d4 & 4) != 0) || (g_fBreakOnFailure != false)) &&
     (g_pfnDebugBreak != (_func_void *)0x0)) {
    (*g_pfnDebugBreak)();
  }
  if ((local_14d4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    WilFailFast((FailureInfo *)&local_14d8);
  }
  if (bVar2) {
    (*g_pfnThrowPlatformException)(&local_14d8,local_1038);
  }
  ThrowResultException((FailureInfo *)&local_14d8);
                    /* WARNING: Subroutine does not return */
  WilFailFast((FailureInfo *)&local_14d8);
}



===== bad_alloc @ 18000697c =====

/* public: __cdecl std::bad_alloc::bad_alloc(class std::bad_alloc const & __ptr64) __ptr64 */

bad_alloc * __thiscall std::bad_alloc::bad_alloc(bad_alloc *this,bad_alloc *param_1)

{
  *(undefined ***)this = exception::_vftable_;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  *(undefined ***)this = _vftable_;
  return this;
}



===== bad_array_new_length @ 1800069c0 =====

/* public: __cdecl std::bad_array_new_length::bad_array_new_length(class std::bad_array_new_length
   const & __ptr64) __ptr64 */

bad_array_new_length * __thiscall
std::bad_array_new_length::bad_array_new_length
          (bad_array_new_length *this,bad_array_new_length *param_1)

{
  *(undefined ***)this = exception::_vftable_;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  *(undefined ***)this = _vftable_;
  return this;
}



===== bad_array_new_length @ 180006a04 =====

/* public: __cdecl std::bad_array_new_length::bad_array_new_length(void) __ptr64 */

bad_array_new_length * __thiscall
std::bad_array_new_length::bad_array_new_length(bad_array_new_length *this)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(char **)(this + 8) = "bad array new length";
  *(undefined ***)this = _vftable_;
  return this;
}



===== ~_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> @ 180006a2c =====

/* public: __cdecl std::_Tidy_guard<class std::vector<unsigned char,class std::allocator<unsigned
   char> > >::~_Tidy_guard<class std::vector<unsigned char,class std::allocator<unsigned char> >
   >(void) __ptr64 */

void __thiscall
std::_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>::
~_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>
          (_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *this)

{
  longlong *plVar1;
  void *pvVar2;
  code *pcVar3;
  void *pvVar4;
  __uint64 _Var5;
  
  plVar1 = *(longlong **)this;
  if ((plVar1 != (longlong *)0x0) && (pvVar2 = (void *)*plVar1, pvVar2 != (void *)0x0)) {
    _Var5 = plVar1[2] - (longlong)pvVar2;
    pvVar4 = pvVar2;
    if (0xfff < _Var5) {
      pvVar4 = *(void **)((longlong)pvVar2 + -8);
      _Var5 = _Var5 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar4))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
    }
    operator_delete(pvVar4,_Var5);
    *plVar1 = 0;
    plVar1[1] = 0;
    plVar1[2] = 0;
  }
  return;
}



===== ~vector<unsigned_char,std::allocator<unsigned_char>_> @ 180006a98 =====

/* public: __cdecl std::vector<unsigned char,class std::allocator<unsigned char> >::~vector<unsigned
   char,class std::allocator<unsigned char> >(void) __ptr64 */

void __thiscall
std::vector<unsigned_char,std::allocator<unsigned_char>_>::
~vector<unsigned_char,std::allocator<unsigned_char>_>
          (vector<unsigned_char,std::allocator<unsigned_char>_> *this)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = *(longlong *)(this + 0x10) - (longlong)pvVar1;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== ~bad_optional_access @ 180006b00 =====

/* public: virtual __cdecl std::bad_optional_access::~bad_optional_access(void) __ptr64 */

void __thiscall std::bad_optional_access::~bad_optional_access(bad_optional_access *this)

{
  *(undefined ***)this = exception::_vftable_;
  __std_exception_destroy(this + 8);
  return;
}



===== ConvertComponentKernelToUser @ 180006b1c =====

void ConvertComponentKernelToUser(longlong param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ushort uVar8;
  void *unaff_retaddr;
  
  *param_2 = *(undefined4 *)(param_1 + 0x184);
  param_2[1] = *(undefined4 *)(param_1 + 0x180);
  _o_wcsncpy_s(param_2 + 2,0x40,param_1,0x40);
  _o_wcsncpy_s(param_2 + 0x22,0x80,param_1 + 0x80,0x40);
  *(undefined2 *)((longlong)param_2 + 0x18a) = *(undefined2 *)(param_1 + 0x1c8);
  uVar8 = 0;
  if (*(short *)(param_1 + 0x1c8) != 0) {
    do {
      ConvertPropertyKernelToUser
                ((int *)((ulonglong)uVar8 * 0x108 + 0x1cc + param_1),
                 (undefined2 *)(param_2 + (ulonglong)uVar8 * 0x44 + 100));
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(ushort *)(param_1 + 0x1c8));
  }
  uVar8 = 0;
  *(undefined2 *)(param_2 + 0x394) = *(undefined2 *)(param_1 + 0xe2c);
  if (*(short *)(param_1 + 0xe2c) != 0) {
    do {
      wil::details::in1diag3::Throw_HrIfMsg
                (unaff_retaddr,0x166,
                 "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonlegacyapi.cpp",
                 -0x7ff8fae6,false,"Mismatch edge size",0);
      uVar5 = (ulonglong)uVar8;
      uVar8 = uVar8 + 1;
      puVar6 = (undefined8 *)(param_1 + 0xe30 + uVar5 * 0xb0);
      puVar7 = (undefined8 *)(param_2 + uVar5 * 0x2c + 0x396);
      uVar4 = puVar6[1];
      *puVar7 = *puVar6;
      puVar7[1] = uVar4;
      uVar4 = puVar6[3];
      puVar7[2] = puVar6[2];
      puVar7[3] = uVar4;
      uVar4 = puVar6[5];
      puVar7[4] = puVar6[4];
      puVar7[5] = uVar4;
      uVar4 = puVar6[7];
      puVar7[6] = puVar6[6];
      puVar7[7] = uVar4;
      uVar4 = puVar6[9];
      puVar7[8] = puVar6[8];
      puVar7[9] = uVar4;
      uVar4 = puVar6[0xb];
      puVar7[10] = puVar6[10];
      puVar7[0xb] = uVar4;
      uVar4 = puVar6[0xd];
      puVar7[0xc] = puVar6[0xc];
      puVar7[0xd] = uVar4;
      uVar4 = puVar6[0xf];
      puVar7[0xe] = puVar6[0xe];
      puVar7[0xf] = uVar4;
      uVar4 = puVar6[0x11];
      puVar7[0x10] = puVar6[0x10];
      puVar7[0x11] = uVar4;
      uVar4 = puVar6[0x13];
      puVar7[0x12] = puVar6[0x12];
      puVar7[0x13] = uVar4;
      uVar1 = *(undefined4 *)((longlong)puVar6 + 0xa4);
      uVar2 = *(undefined4 *)(puVar6 + 0x15);
      uVar3 = *(undefined4 *)((longlong)puVar6 + 0xac);
      *(undefined4 *)(puVar7 + 0x14) = *(undefined4 *)(puVar6 + 0x14);
      *(undefined4 *)((longlong)puVar7 + 0xa4) = uVar1;
      *(undefined4 *)(puVar7 + 0x15) = uVar2;
      *(undefined4 *)((longlong)puVar7 + 0xac) = uVar3;
    } while (uVar8 < *(ushort *)(param_1 + 0xe2c));
  }
  wil::details::in1diag3::Throw_HrIfMsg
            (unaff_retaddr,0x194,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonlegacyapi.cpp",-0x7ff8fae6,
             false,"Mismatch drop counter structure size",0);
  uVar4 = *(undefined8 *)(param_1 + 0x198);
  *(undefined8 *)(param_2 + 0x4f6) = *(undefined8 *)(param_1 + 400);
  *(undefined8 *)(param_2 + 0x4f8) = uVar4;
  uVar4 = *(undefined8 *)(param_1 + 0x1a8);
  *(undefined8 *)(param_2 + 0x4fa) = *(undefined8 *)(param_1 + 0x1a0);
  *(undefined8 *)(param_2 + 0x4fc) = uVar4;
  uVar4 = *(undefined8 *)(param_1 + 0x1b8);
  *(undefined8 *)(param_2 + 0x4fe) = *(undefined8 *)(param_1 + 0x1b0);
  *(undefined8 *)(param_2 + 0x500) = uVar4;
  return;
}



===== ConvertFilterKernelToUser @ 180006d30 =====

void ConvertFilterKernelToUser(longlong param_1,ushort *param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  bool bVar3;
  void *unaff_retaddr;
  
  uVar1 = *param_2;
  if ((uVar1 == 0xc3) || (uVar1 == 200)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  wil::details::in1diag3::Throw_HrIfMsg
            (unaff_retaddr,0x55,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonlegacyapi.cpp",-0x7ff8fae6,
             bVar3,"Unknown or invalid filter size",bVar3);
  memset(param_2,0,(ulonglong)uVar1);
  *param_2 = uVar1;
  _o_wcscpy_s(param_2 + 1,0x40,param_1);
  *(undefined4 *)(param_2 + 0x41) = *(undefined4 *)(param_1 + 0x84);
  param_2[0x43] = *(ushort *)(param_1 + 0x88);
  *(undefined4 *)(param_2 + 0x44) = *(undefined4 *)(param_1 + 0x8a);
  param_2[0x46] = *(ushort *)(param_1 + 0x8e);
  uVar2 = *(undefined8 *)(param_1 + 0xa0);
  *(undefined8 *)(param_2 + 0x4c) = *(undefined8 *)(param_1 + 0x98);
  *(undefined8 *)(param_2 + 0x50) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0xb0);
  *(undefined8 *)(param_2 + 0x54) = *(undefined8 *)(param_1 + 0xa8);
  *(undefined8 *)(param_2 + 0x58) = uVar2;
  *(byte *)((longlong)param_2 + 0x93) = (byte)((uint)*(undefined4 *)(param_1 + 0x80) >> 8) & 1;
  param_2[0x47] = *(ushort *)(param_1 + 0x90);
  param_2[0x48] = *(ushort *)(param_1 + 0x92);
  *(undefined1 *)(param_2 + 0x49) = *(undefined1 *)(param_1 + 0x96);
  *(undefined1 *)(param_2 + 0x5c) = *(undefined1 *)(param_1 + 0xb8);
  *(undefined1 *)((longlong)param_2 + 0xb9) = *(undefined1 *)(param_1 + 0xb9);
  param_2[0x5d] = *(ushort *)(param_1 + 0xba);
  param_2[0x5e] = *(ushort *)(param_1 + 0xbc);
  *(undefined1 *)(param_2 + 0x5f) = *(undefined1 *)(param_1 + 0xbe);
  param_2[0x60] = *(ushort *)(param_1 + 0xc4);
  *(byte *)(param_2 + 0x61) = *(byte *)(param_1 + 0x82) & 1;
  if (199 < *param_2) {
    *(uint *)(param_2 + 0x62) = (uint)*(ushort *)(param_1 + 0x94);
  }
  return;
}



===== ConvertFilterUserToKernel @ 180006ed0 =====

void ConvertFilterUserToKernel(ushort *param_1,void *param_2)

{
  undefined8 uVar1;
  bool bVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  void *unaff_retaddr;
  
  if ((*param_1 == 0xc3) || (bVar2 = true, *param_1 == 200)) {
    bVar2 = false;
  }
  wil::details::in1diag3::Throw_HrIfMsg
            (unaff_retaddr,0x89,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonlegacyapi.cpp",-0x7ff8fae6,
             bVar2,"Unknown or invalid filter size",bVar2);
  memset(param_2,0,0xd8);
  _o_wcscpy_s(param_2,0x40,param_1 + 1);
  if ((*(int *)(param_1 + 0x41) != DAT_180021ca8) || (param_1[0x43] != DAT_180021cac)) {
    *(uint *)((longlong)param_2 + 0x80) = *(uint *)((longlong)param_2 + 0x80) | 1;
    *(undefined4 *)((longlong)param_2 + 0x84) = *(undefined4 *)(param_1 + 0x41);
    *(ushort *)((longlong)param_2 + 0x88) = param_1[0x43];
  }
  puVar4 = (uint *)((longlong)param_2 + 0x80);
  if ((*(int *)(param_1 + 0x44) != DAT_180021ca8) || (param_1[0x46] != DAT_180021cac)) {
    *puVar4 = *puVar4 | 2;
    *(undefined4 *)((longlong)param_2 + 0x8a) = *(undefined4 *)(param_1 + 0x44);
    *(ushort *)((longlong)param_2 + 0x8e) = param_1[0x46];
  }
  if (param_1[0x47] != 0) {
    *puVar4 = *puVar4 | 4;
    *(ushort *)((longlong)param_2 + 0x90) = param_1[0x47];
  }
  puVar5 = (uint *)((longlong)param_2 + 0x80);
  if (param_1[0x48] != 0) {
    *puVar5 = *puVar4 | 8;
    *(ushort *)((longlong)param_2 + 0x92) = param_1[0x48];
  }
  if ((char)param_1[0x49] != '\0') {
    *puVar5 = *puVar5 | 0x20;
    *(char *)((longlong)param_2 + 0x96) = (char)param_1[0x49];
  }
  puVar4 = (uint *)((longlong)param_2 + 0x80);
  if ((*(longlong *)(param_1 + 0x4c) != DAT_180021c98) ||
     (*(longlong *)(param_1 + 0x50) != DAT_180021ca0)) {
    uVar3 = *puVar5 | 0x40;
    *puVar4 = uVar3;
    *puVar4 = ((uint)*(byte *)((longlong)param_1 + 0x93) << 8 ^ uVar3) & 0x100 ^ uVar3;
    uVar1 = *(undefined8 *)(param_1 + 0x50);
    *(undefined8 *)((longlong)param_2 + 0x98) = *(undefined8 *)(param_1 + 0x4c);
    *(undefined8 *)((longlong)param_2 + 0xa0) = uVar1;
  }
  if ((*(longlong *)(param_1 + 0x54) != DAT_180021c98) ||
     (*(longlong *)(param_1 + 0x58) != DAT_180021ca0)) {
    uVar3 = *puVar4 | 0x80;
    *puVar4 = uVar3;
    *puVar4 = ((uint)*(byte *)((longlong)param_1 + 0x93) << 8 ^ uVar3) & 0x100 ^ uVar3;
    uVar1 = *(undefined8 *)(param_1 + 0x58);
    *(undefined8 *)((longlong)param_2 + 0xa8) = *(undefined8 *)(param_1 + 0x54);
    *(undefined8 *)((longlong)param_2 + 0xb0) = uVar1;
  }
  puVar5 = (uint *)((longlong)param_2 + 0x80);
  if ((char)param_1[0x5c] != '\0') {
    *puVar5 = *puVar4 | 0x200;
    *(char *)((longlong)param_2 + 0xb8) = (char)param_1[0x5c];
  }
  if (*(char *)((longlong)param_1 + 0xb9) != '\0') {
    *puVar5 = *puVar5 | 0x400;
    *(undefined1 *)((longlong)param_2 + 0xb9) = *(undefined1 *)((longlong)param_1 + 0xb9);
  }
  puVar4 = (uint *)((longlong)param_2 + 0x80);
  if (param_1[0x5d] != 0) {
    *puVar4 = *puVar5 | 0x800;
    *(ushort *)((longlong)param_2 + 0xba) = param_1[0x5d];
  }
  if (param_1[0x5e] != 0) {
    *puVar4 = *puVar4 | 0x1000;
    *(ushort *)((longlong)param_2 + 0xbc) = param_1[0x5d];
  }
  puVar5 = (uint *)((longlong)param_2 + 0x80);
  if ((char)param_1[0x5f] != '\0') {
    *puVar5 = *puVar4 | 0x2000;
    *(char *)((longlong)param_2 + 0xbe) = (char)param_1[0x5f];
  }
  if (*(char *)((longlong)param_1 + 0xbf) != '\0') {
    *puVar5 = *puVar5 | 0x4000;
    *(undefined4 *)((longlong)param_2 + 0xc0) = 0xff;
  }
  puVar4 = (uint *)((longlong)param_2 + 0x80);
  if (param_1[0x60] != 0) {
    *puVar4 = *puVar5 | 0x8000;
    *(ushort *)((longlong)param_2 + 0xc4) = param_1[0x60];
  }
  if ((char)param_1[0x61] != '\0') {
    *puVar4 = *puVar4 | 0x10000;
  }
  if ((199 < *param_1) && (*(int *)(param_1 + 0x62) != 0)) {
    *(uint *)((longlong)param_2 + 0x80) = *(uint *)((longlong)param_2 + 0x80) | 0x10;
    *(ushort *)((longlong)param_2 + 0x94) = param_1[0x62];
  }
  return;
}



===== ConvertPropertyKernelToUser @ 18000724c =====

void ConvertPropertyKernelToUser(int *param_1,undefined2 *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  void *unaff_retaddr;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar9;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  *param_2 = (short)param_1[1];
  *(int *)(param_2 + 2) = *param_1;
  iVar5 = *param_1;
  if (iVar5 < 10) {
    if (iVar5 == 9) {
LAB_1800072bc:
      wil::details::in1diag3::Throw_HrIfMsg
                (unaff_retaddr,0x126,
                 "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonlegacyapi.cpp",
                 -0x7ff8fae6,2 < *(ushort *)(param_1 + 1),
                 "incorrect property size. property id: 0x%x",iVar5);
      *(undefined4 *)(param_2 + 4) = 2;
      param_2[8] = *(undefined2 *)((longlong)param_1 + 6);
      return;
    }
    if (((iVar5 != 1) && (iVar5 != 2)) && (iVar5 != 3)) {
      if (iVar5 == 4) {
        *(undefined4 *)(param_2 + 4) = 3;
        goto LAB_18000732d;
      }
      if (iVar5 != 5) {
        if (iVar5 == 6) {
          *(undefined4 *)(param_2 + 4) = 5;
          memcpy(param_2 + 8,(void *)((longlong)param_1 + 6),(ulonglong)*(ushort *)(param_1 + 1));
          return;
        }
        if ((iVar5 != 7) && (iVar5 != 8)) goto LAB_180007445;
        goto LAB_1800072bc;
      }
    }
  }
  else {
    if (iVar5 == 10) {
      lVar7 = 2;
      *(undefined4 *)(param_2 + 4) = 4;
      puVar8 = (undefined8 *)((longlong)param_1 + 6);
      puVar6 = (undefined8 *)(param_2 + 8);
      do {
        uVar3 = puVar8[1];
        *puVar6 = *puVar8;
        puVar6[1] = uVar3;
        uVar3 = puVar8[3];
        puVar6[2] = puVar8[2];
        puVar6[3] = uVar3;
        uVar3 = puVar8[5];
        puVar6[4] = puVar8[4];
        puVar6[5] = uVar3;
        uVar3 = puVar8[7];
        puVar6[6] = puVar8[6];
        puVar6[7] = uVar3;
        uVar3 = puVar8[9];
        puVar6[8] = puVar8[8];
        puVar6[9] = uVar3;
        uVar3 = puVar8[0xb];
        puVar6[10] = puVar8[10];
        puVar6[0xb] = uVar3;
        uVar3 = puVar8[0xd];
        puVar6[0xc] = puVar8[0xc];
        puVar6[0xd] = uVar3;
        puVar1 = puVar8 + 0xe;
        uVar3 = puVar8[0xf];
        puVar8 = puVar8 + 0x10;
        puVar6[0xe] = *puVar1;
        puVar6[0xf] = uVar3;
        lVar7 = lVar7 + -1;
        puVar6 = puVar6 + 0x10;
      } while (lVar7 != 0);
      return;
    }
    if ((iVar5 != 0xb) && (iVar5 != 0xc)) {
      if (iVar5 == 0xd) {
        if ((short)param_1[1] == 0x10) {
          *(undefined4 *)(param_2 + 4) = 7;
LAB_18000732d:
          uVar3 = *(undefined8 *)((longlong)param_1 + 0xe);
          *(undefined8 *)(param_2 + 8) = *(undefined8 *)((longlong)param_1 + 6);
          *(undefined8 *)(param_2 + 0xc) = uVar3;
          return;
        }
        *(undefined4 *)(param_2 + 4) = 6;
        goto LAB_1800073cb;
      }
      if ((((iVar5 != 0xe) && (iVar5 != 0xf)) && (iVar5 != 0x10)) && (iVar5 != 0x11)) {
LAB_180007445:
        lVar4 = wil::verify_hresult<long>(-0x7ff8fae6);
        wil::details::in1diag3::Throw_HrMsg
                  (unaff_retaddr,0x14c,
                   "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonlegacyapi.cpp",lVar4,
                   "Unknown property id: 0x%x",CONCAT44(uVar9,iVar5));
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
  }
  wil::details::in1diag3::Throw_HrIfMsg
            (unaff_retaddr,0x11a,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonlegacyapi.cpp",-0x7ff8fae6,
             (short)param_1[1] != 4,"incorrect property size. property id: 0x%x",iVar5);
  *(undefined4 *)(param_2 + 4) = 1;
LAB_1800073cb:
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)((longlong)param_1 + 6);
  return;
}



===== IsValidFilter @ 180007480 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool IsValidFilter(ushort *param_1)

{
  int iVar1;
  
  _DAT_180021bd0 = *param_1;
  iVar1 = memcmp(param_1,&DAT_180021bd0,200);
  if ((((iVar1 == 0) || (((char)param_1[0x5f] != '\0' && ((char)param_1[0x49] != '\x06')))) ||
      (((char)param_1[0x5c] != '\0' &&
       ((*(longlong *)(param_1 + 0x4c) == DAT_180021c98 &&
        (*(longlong *)(param_1 + 0x50) == DAT_180021ca0)))))) ||
     ((*(char *)((longlong)param_1 + 0xb9) != '\0' &&
      ((*(longlong *)(param_1 + 0x54) == DAT_180021c98 &&
       (*(longlong *)(param_1 + 0x58) == DAT_180021ca0)))))) {
    return false;
  }
  if ((*param_1 < 200) || (*(uint *)(param_1 + 0x62) == 0)) {
    return true;
  }
  return *(uint *)(param_1 + 0x62) < 0x40;
}



===== PktmonAddFilter @ 180007540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl PktmonAddFilter(struct _PKTMON_FILTER * __ptr64) */

ulong __cdecl PktmonAddFilter(_PKTMON_FILTER *param_1)

{
  bool bVar1;
  _PKTMON_FILTER *p_Var2;
  undefined1 auStackY_138 [32];
  undefined1 local_f8 [224];
  ulonglong local_18;
  
                    /* 0x7540  1  PktmonAddFilter */
  local_18 = __security_cookie ^ (ulonglong)auStackY_138;
  if (param_1 != (_PKTMON_FILTER *)0x0) {
    if ((*(short *)param_1 != 0xc3) && (*(short *)param_1 != 200)) {
      return 0x51a;
    }
    p_Var2 = param_1;
    bVar1 = IsValidFilter((ushort *)param_1);
    if (bVar1) {
      ValidateDriverVersion((DriverInterface *)p_Var2);
      memset(local_f8,0,0xd8);
      ConvertFilterUserToKernel((ushort *)param_1,local_f8);
      PktMon::DriverInterface::SendIoCtl
                ((DriverInterface *)param_1,0x220410,local_f8,0xd8,(void *)0x0,0);
      return 0;
    }
  }
  return 0x57;
}



===== PktmonGetComponentList @ 180007600 =====

/* unsigned long __cdecl PktmonGetComponentList(struct _PKTMON_COMPONENT * __ptr64,unsigned long *
   __ptr64) */

ulong __cdecl PktmonGetComponentList(_PKTMON_COMPONENT *param_1,ulong *param_2)

{
  ushort uVar1;
  code *pcVar2;
  ulong uVar3;
  _Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *this;
  void *pvVar4;
  ulong *puVar5;
  __uint64 _Var6;
  ushort uVar7;
  undefined8 local_res10;
  void *local_30;
  longlong lStack_28;
  longlong local_20;
  
                    /* 0x7600  2  PktmonGetComponentList */
  if ((param_2 == (ulong *)0x0) || ((param_1 == (_PKTMON_COMPONENT *)0x0 && (*param_2 != 0)))) {
    uVar3 = 0x57;
  }
  else {
    this = (_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *)param_1;
    puVar5 = param_2;
    ValidateDriverVersion((DriverInterface *)param_1);
    uVar3 = PktMon::DriverInterface::GetBytesNeeded((DriverInterface *)this,(ulong)puVar5);
    local_30 = (void *)0x0;
    lStack_28 = 0;
    local_20 = 0;
    if (uVar3 != 0) {
      std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Buy_nonzero
                ((vector<unsigned_char,std::allocator<unsigned_char>_> *)&local_30,(ulonglong)uVar3)
      ;
      pvVar4 = local_30;
      memset(local_30,0,(ulonglong)uVar3);
      lStack_28 = (longlong)pvVar4 + (ulonglong)uVar3;
      local_res10 = 0;
      this = (_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *)&local_res10
      ;
      std::_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>::
      ~_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>(this);
    }
    PktMon::DriverInterface::SendIoCtl
              ((DriverInterface *)this,0x220418,(void *)0x0,0,local_30,uVar3);
    pvVar4 = local_30;
    if ((ushort)*param_2 < *(ushort *)((longlong)local_30 + 4)) {
      *param_2 = (uint)*(ushort *)((longlong)local_30 + 4);
      _Var6 = local_20 - (longlong)local_30;
      if (0xfff < _Var6) {
        _Var6 = _Var6 + 0x27;
        pvVar4 = *(void **)((longlong)local_30 + -8);
        if (0x1f < (ulonglong)((longlong)local_30 + (-8 - (longlong)pvVar4))) {
LAB_180007764:
          _o__invalid_parameter_noinfo_noreturn();
          pcVar2 = (code *)swi(3);
          uVar3 = (*pcVar2)();
          return uVar3;
        }
      }
      operator_delete(pvVar4,_Var6);
      uVar3 = 0x7a;
    }
    else {
      for (uVar7 = 0; uVar1 = *(ushort *)((longlong)pvVar4 + 4), uVar7 < uVar1; uVar7 = uVar7 + 1) {
        ConvertComponentKernelToUser
                  ((ulonglong)uVar7 * 0x13b0 + 8 + (longlong)pvVar4,
                   (undefined4 *)(param_1 + (ulonglong)uVar7 * 0x1408));
      }
      *param_2 = (uint)uVar1;
      if (local_30 != (void *)0x0) {
        _Var6 = local_20 - (longlong)local_30;
        pvVar4 = local_30;
        if (0xfff < _Var6) {
          _Var6 = _Var6 + 0x27;
          pvVar4 = *(void **)((longlong)local_30 + -8);
          if (0x1f < (ulonglong)((longlong)local_30 + (-8 - (longlong)pvVar4))) goto LAB_180007764;
        }
        operator_delete(pvVar4,_Var6);
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== PktmonGetFilterList @ 1800077b0 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl PktmonGetFilterList(struct _PKTMON_FILTER * __ptr64,unsigned long *
   __ptr64) */

ulong __cdecl PktmonGetFilterList(_PKTMON_FILTER *param_1,ulong *param_2)

{
  ulong uVar1;
  DriverInterface *this;
  uint uVar2;
  undefined1 auStackY_1b78 [32];
  undefined2 local_1b38;
  DriverInterface local_1b36 [2];
  ushort local_1b34;
  undefined1 local_1b30 [6920];
  ulonglong local_28;
  undefined8 uStack_20;
  
                    /* 0x77b0  3  PktmonGetFilterList */
  uStack_20 = 0x1800077c3;
  local_28 = __security_cookie ^ (ulonglong)auStackY_1b78;
  if ((param_2 == (ulong *)0x0) || ((param_1 == (_PKTMON_FILTER *)0x0 && (*param_2 != 0)))) {
    uVar1 = 0x57;
  }
  else {
    ValidateDriverVersion((DriverInterface *)param_1);
    local_1b38 = 0;
    this = local_1b36;
    memset(this,0,0x1b06);
    PktMon::DriverInterface::SendIoCtl(this,0x22040c,(void *)0x0,0,&local_1b38,0x1b08);
    if ((ushort)*param_2 < local_1b34) {
      *param_2 = (uint)local_1b34;
      uVar1 = 0x7a;
    }
    else {
      for (uVar2 = 0; uVar2 < local_1b34; uVar2 = uVar2 + 1) {
        if (*(short *)param_1 == 0) {
          *(undefined2 *)param_1 = 0xc3;
        }
        ConvertFilterKernelToUser
                  ((longlong)(local_1b30 + (ulonglong)uVar2 * 0xd8),(ushort *)param_1);
        param_1 = param_1 + *(ushort *)param_1;
      }
      *param_2 = (uint)local_1b34;
      uVar1 = 0;
    }
  }
  return uVar1;
}



===== PktmonGetStatus @ 1800078d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl PktmonGetStatus(struct _PKTMON_STATUS * __ptr64) */

ulong __cdecl PktmonGetStatus(_PKTMON_STATUS *param_1)

{
  ulong uVar1;
  _PKTMON_STATUS *this;
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
                    /* 0x78d0  4  PktmonGetStatus */
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  if (param_1 == (_PKTMON_STATUS *)0x0) {
    uVar1 = 0x57;
  }
  else {
    this = param_1;
    ValidateDriverVersion((DriverInterface *)param_1);
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    PktMon::DriverInterface::SendIoCtl
              ((DriverInterface *)this,0x220424,(void *)0x0,0,&local_28,0x14);
    memset(param_1,0,0x103c);
    *param_1 = local_28._4_1_;
    *(undefined4 *)(param_1 + 8) = (undefined4)uStack_20;
    *(undefined4 *)(param_1 + 4) = uStack_20._4_4_;
    *(undefined2 *)(param_1 + 0xc) = local_18._2_2_;
    param_1[0xe] = local_18._0_1_;
    uVar1 = 0;
  }
  return uVar1;
}



===== PktmonRemoveAllFilters @ 180007980 =====

/* unsigned long __cdecl PktmonRemoveAllFilters(void) */

ulong __cdecl PktmonRemoveAllFilters(void)

{
  DriverInterface *in_RCX;
  
                    /* 0x7980  5  PktmonRemoveAllFilters */
  ValidateDriverVersion(in_RCX);
  PktMon::DriverInterface::SendIoCtl(in_RCX,0x220414,(void *)0x0,0,(void *)0x0,0);
  return 0;
}



===== PktmonResetCounters @ 1800079c0 =====

/* unsigned long __cdecl PktmonResetCounters(void) */

ulong __cdecl PktmonResetCounters(void)

{
  DriverInterface *in_RCX;
  
                    /* 0x79c0  6  PktmonResetCounters */
  ValidateDriverVersion(in_RCX);
  PktMon::DriverInterface::SendIoCtl(in_RCX,0x220420,(void *)0x0,0,(void *)0x0,0);
  return 0;
}



===== PktmonStart @ 180007a00 =====

/* unsigned long __cdecl PktmonStart(struct _PKTMON_START * __ptr64,struct _PKTMON_LOG_CONFIG *
   __ptr64) */

ulong __cdecl PktmonStart(_PKTMON_START *param_1,_PKTMON_LOG_CONFIG *param_2)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  _Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *this;
  ushort *puVar4;
  __uint64 _Var5;
  ushort uVar6;
  ushort uVar7;
  ulonglong uVar8;
  undefined8 local_res8;
  ushort *local_30;
  longlong lStack_28;
  longlong local_20;
  
                    /* 0x7a00  7  PktmonStart */
  if (param_1 != (_PKTMON_START *)0x0) {
    if (param_2 != (_PKTMON_LOG_CONFIG *)0x0) {
      return 0x78;
    }
    if (*(int *)(param_1 + 8) == 3) {
      if ((*(short *)(param_1 + 0xc) != 0) && (*(longlong *)(param_1 + 0x10) != 0))
      goto LAB_180007a5f;
    }
    else if (*(short *)(param_1 + 0xc) == 0) {
LAB_180007a5f:
      this = (_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *)param_1;
      ValidateDriverVersion((DriverInterface *)param_1);
      uVar6 = (*(short *)(param_1 + 0xc) + 5) * 4;
      uVar8 = (ulonglong)uVar6;
      local_30 = (ushort *)0x0;
      lStack_28 = 0;
      local_20 = 0;
      if (uVar8 != 0) {
        std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Buy_nonzero
                  ((vector<unsigned_char,std::allocator<unsigned_char>_> *)&local_30,uVar8);
        puVar4 = local_30;
        memset(local_30,0,(ulonglong)uVar6);
        lStack_28 = (longlong)puVar4 + uVar8;
        local_res8 = 0;
        this = (_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *)
               &local_res8;
        std::_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>::
        ~_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>(this);
      }
      *local_30 = uVar6;
      *(undefined4 *)(local_30 + 6) = *(undefined4 *)param_1;
      local_30[9] = *(ushort *)(param_1 + 0x18);
      *(undefined1 *)(local_30 + 8) = 1;
      *(undefined4 *)(local_30 + 2) = *(undefined4 *)(param_1 + 8);
      local_30[5] = *(ushort *)(param_1 + 0xc);
      local_30[4] = 0x14;
      uVar7 = 0;
      if (*(short *)(param_1 + 0xc) != 0) {
        do {
          uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + (ulonglong)uVar7 * 4);
          this = (_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *)
                 (ulonglong)uVar1;
          *(uint *)(local_30 + (ulonglong)uVar7 * 2 + 10) = uVar1;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(param_1 + 0xc));
      }
      PktMon::DriverInterface::SendIoCtl
                ((DriverInterface *)this,0x220404,local_30,(uint)uVar6,(void *)0x0,0);
      if (local_30 != (ushort *)0x0) {
        _Var5 = local_20 - (longlong)local_30;
        puVar4 = local_30;
        if (0xfff < _Var5) {
          _Var5 = _Var5 + 0x27;
          puVar4 = *(ushort **)(local_30 + -4);
          if (0x1f < (ulonglong)((longlong)local_30 + (-8 - (longlong)puVar4))) {
            _o__invalid_parameter_noinfo_noreturn();
            pcVar2 = (code *)swi(3);
            uVar3 = (*pcVar2)();
            return uVar3;
          }
        }
        operator_delete(puVar4,_Var5);
      }
      return 0;
    }
  }
  return 0x57;
}



===== PktmonStop @ 180007ba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl PktmonStop(struct _PKTMON_STATUS * __ptr64) */

ulong __cdecl PktmonStop(_PKTMON_STATUS *param_1)

{
  _PKTMON_STATUS *this;
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
                    /* 0x7ba0  8  PktmonStop */
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  this = param_1;
  ValidateDriverVersion((DriverInterface *)param_1);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  PktMon::DriverInterface::SendIoCtl((DriverInterface *)this,0x220408,(void *)0x0,0,&local_28,0x14);
  if (param_1 != (_PKTMON_STATUS *)0x0) {
    memset(param_1,0,0x103c);
    *param_1 = local_28._4_1_;
    *(undefined4 *)(param_1 + 8) = (undefined4)uStack_20;
    *(undefined4 *)(param_1 + 4) = uStack_20._4_4_;
    *(undefined2 *)(param_1 + 0xc) = local_18._2_2_;
    param_1[0xe] = local_18._0_1_;
  }
  return 0;
}



===== PktmonUnload @ 180007c50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl PktmonUnload(void) */

ulong __cdecl PktmonUnload(void)

{
  BOOL BVar1;
  DWORD DVar2;
  SC_HANDLE hSCManager;
  SC_HANDLE hService;
  bool bVar3;
  void *unaff_retaddr;
  undefined1 auStackY_78 [32];
  _SERVICE_STATUS local_30;
  ulonglong local_10;
  
                    /* 0x7c50  9  PktmonUnload */
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  bVar3 = true;
  hSCManager = OpenSCManagerW((LPCWSTR)0x0,L"ServicesActive",1);
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x71,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",
             hSCManager == (SC_HANDLE)0x0,"OpenSCManager failed");
  hService = OpenServiceW(hSCManager,L"PktMon",0x30);
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x75,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",
             hService == (SC_HANDLE)0x0,"OpenService failed");
  local_30.dwServiceType = 0;
  local_30.dwCurrentState = 0;
  local_30.dwControlsAccepted = 0;
  local_30.dwWin32ExitCode = 0;
  local_30.dwServiceSpecificExitCode = 0;
  local_30.dwCheckPoint = 0;
  local_30.dwWaitHint = 0;
  BVar1 = ControlService(hService,1,&local_30);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 != 0x426) goto LAB_180007d4d;
  }
  bVar3 = false;
LAB_180007d4d:
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x7b,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",bVar3,
             "Failed to unload the Pktmon driver. ControlService has failed");
  if (hService != (SC_HANDLE)0x0) {
    CloseServiceHandle(hService);
  }
  if (hSCManager != (SC_HANDLE)0x0) {
    CloseServiceHandle(hSCManager);
  }
  return 0;
}



===== PrintLoggingMessage @ 180007dcc =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl wil::details::PrintLoggingMessage(unsigned short * __ptr64,unsigned __int64,char
   const * __ptr64,char * __ptr64) */

void __cdecl
wil::details::PrintLoggingMessage(ushort *param_1,__uint64 param_2,char *param_3,char *param_4)

{
  uint uVar1;
  undefined1 auStack_1048 [32];
  wchar_t local_1028 [2048];
  ulonglong local_28;
  undefined8 uStack_20;
  
  uStack_20 = 0x180007dda;
  local_28 = __security_cookie ^ (ulonglong)auStack_1048;
  if (param_3 == (char *)0x0) {
    *param_1 = 0;
  }
  else if (param_4 == (char *)0x0) {
    StringCchPrintfW(param_1,0x800,(ushort *)L"%hs",param_3);
  }
  else {
    StringCchPrintfW((ushort *)local_1028,0x800,(ushort *)L"%hs",param_3);
    uVar1 = _vsnwprintf((wchar_t *)param_1,0x7ff,local_1028,param_4);
    if ((((int)uVar1 < 0) || (0x7ff < uVar1)) || (uVar1 == 0x7ff)) {
      param_1[0x7ff] = 0;
    }
  }
  return;
}



===== Throw_HrIfMsg @ 180007e70 =====

/* bool __cdecl wil::details::in1diag3::Throw_HrIfMsg(void * __ptr64,unsigned int,char const *
   __ptr64,long,bool,char const * __ptr64,...) */

bool __cdecl
wil::details::in1diag3::Throw_HrIfMsg
          (void *param_1,uint param_2,char *param_3,long param_4,bool param_5,char *param_6,...)

{
  code *pcVar1;
  undefined1 uVar2;
  void *unaff_retaddr;
  char cStack0000000000000038;
  
  if (param_5) {
    _Throw_HrMsg(param_1,param_2,param_3,unaff_retaddr,param_4,param_6,&cStack0000000000000038);
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return (bool)uVar2;
  }
  return false;
}



===== Throw_HrMsg @ 180007ebc =====

/* void __cdecl wil::details::in1diag3::Throw_HrMsg(void * __ptr64,unsigned int,char const *
   __ptr64,long,char const * __ptr64,...) */

void __cdecl
wil::details::in1diag3::Throw_HrMsg
          (void *param_1,uint param_2,char *param_3,long param_4,char *param_5,...)

{
  code *pcVar1;
  void *unaff_retaddr;
  char cStack0000000000000030;
  char *in_stack_ffffffffffffffb8;
  
  ReportFailure_HrMsg<0>
            (param_1,param_2,param_3,_param_4,in_stack_ffffffffffffffb8,unaff_retaddr,(long)_param_4
             ,param_5,&cStack0000000000000030);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ValidateDriverVersion @ 180007eec =====

void ValidateDriverVersion(DriverInterface *param_1)

{
  void *unaff_retaddr;
  int local_res8 [8];
  
  local_res8[0] = 0;
  PktMon::DriverInterface::SendIoCtl(param_1,0x220428,(void *)0x0,0,local_res8,4);
  wil::details::in1diag3::Throw_HrIfMsg
            (unaff_retaddr,0x3a,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonlegacyapi.cpp",-0x7ff8fae6,
             local_res8[0] != 600,"User and kernel version aren\'t matched");
  return;
}



===== _Buy_nonzero @ 180007f5c =====

/* private: void __cdecl std::vector<unsigned char,class std::allocator<unsigned char>
   >::_Buy_nonzero(unsigned __int64) __ptr64 */

void __thiscall
std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Buy_nonzero
          (vector<unsigned_char,std::allocator<unsigned_char>_> *this,__uint64 param_1)

{
  code *pcVar1;
  void *pvVar2;
  void *pvVar3;
  
  if (0x7fffffffffffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  if (param_1 < 0x1000) {
    pvVar3 = (void *)0x0;
    if (param_1 != 0) {
      pvVar3 = operator_new(param_1);
    }
  }
  else {
    if (param_1 + 0x27 <= param_1) {
                    /* WARNING: Subroutine does not return */
      _Throw_bad_array_new_length();
    }
    pvVar2 = operator_new(param_1 + 0x27);
    if (pvVar2 == (void *)0x0) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    pvVar3 = (void *)((longlong)pvVar2 + 0x27U & 0xffffffffffffffe0);
    *(void **)((longlong)pvVar3 - 8) = pvVar2;
  }
  *(void **)this = pvVar3;
  *(void **)(this + 8) = pvVar3;
  *(__uint64 *)(this + 0x10) = (longlong)pvVar3 + param_1;
  return;
}



===== _Throw_HrMsg @ 180007ff0 =====

/* void __cdecl wil::details::in1diag3::_Throw_HrMsg(void * __ptr64,unsigned int,char const *
   __ptr64,void * __ptr64,long,char const * __ptr64,char * __ptr64) */

void __cdecl
wil::details::in1diag3::_Throw_HrMsg
          (void *param_1,uint param_2,char *param_3,void *param_4,long param_5,char *param_6,
          char *param_7)

{
  code *pcVar1;
  char *in_stack_ffffffffffffffc8;
  
  ReportFailure_HrMsg<0>
            (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffc8,param_4,param_5,param_6,
             param_7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _Throw_bad_array_new_length @ 18000802c =====

/* void __cdecl std::_Throw_bad_array_new_length(void) */

void __cdecl std::_Throw_bad_array_new_length(void)

{
  bad_array_new_length local_28 [40];
  
  bad_array_new_length::bad_array_new_length(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&_TI3_AVbad_array_new_length_std__);
}



===== _Xlength @ 180008054 =====

/* private: static void __cdecl std::vector<struct _PKTMON_PROPERTY_OUT const * __ptr64,class
   std::allocator<struct _PKTMON_PROPERTY_OUT const * __ptr64> >::_Xlength(void) */

void __cdecl
std::
vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>::
_Xlength(void)

{
  code *pcVar1;
  
  std::_Xlength_error("vector too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== deallocate @ 180008074 =====

/* public: void __cdecl std::allocator<unsigned char>::deallocate(unsigned char * __ptr64
   const,unsigned __int64) __ptr64 */

void __thiscall
std::allocator<unsigned_char>::deallocate
          (allocator<unsigned_char> *this,uchar *param_1,__uint64 param_2)

{
  code *pcVar1;
  uchar *puVar2;
  
  puVar2 = param_1;
  if (0xfff < param_2) {
    puVar2 = *(uchar **)(param_1 + -8);
    param_2 = param_2 + 0x27;
    if ((uchar *)0x1f < param_1 + (-8 - (longlong)puVar2)) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  operator_delete(puVar2,param_2);
  return;
}



===== ReportFailure_GetLastErrorMsg<0> @ 1800080c0 =====

/* unsigned long __cdecl wil::details::ReportFailure_GetLastErrorMsg<0>(void * __ptr64,unsigned
   int,char const * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,char const *
   __ptr64,char * __ptr64) */

ulong __cdecl
wil::details::ReportFailure_GetLastErrorMsg<0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          char *param_7,char *param_8)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 *puVar3;
  char *in_stack_ffffffffffffffa8;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_18 [16];
  
  GetLastErrorFail(param_1,param_2,param_3,param_4,in_stack_ffffffffffffffa8,param_6);
  puVar3 = (undefined8 *)ResultStatus::FromResult((long)local_18);
  local_28 = *puVar3;
  local_20 = *(undefined4 *)(puVar3 + 1);
  ReportFailure_Msg<0>
            (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffa8,param_6,
             (ResultStatus *)&local_28,param_7,param_8);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== ~unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_> @ 180008154 =====

/* public: __cdecl wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::handle_null_resource_policy<int (__cdecl*)(void * __ptr64),&int __cdecl
   CloseHandle(void * __ptr64)> > >::~unique_any_t<class wil::details::unique_storage<struct
   wil::details::handle_null_resource_policy<int (__cdecl*)(void * __ptr64),&int __cdecl
   CloseHandle(void * __ptr64)> > >(void) __ptr64 */

void __thiscall
wil::
unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
::
~unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
          (unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
           *this)

{
  if ((longlong)*(HANDLE *)this - 1U < 0xfffffffffffffffe) {
    CloseHandle(*(HANDLE *)this);
  }
  return;
}



===== ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_> @ 180008180 =====

/* public: __cdecl wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct SC_HANDLE__ * __ptr64,int (__cdecl*)(struct SC_HANDLE__ *
   __ptr64),&int __cdecl CloseServiceHandle(struct SC_HANDLE__ * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct SC_HANDLE__ * __ptr64,struct SC_HANDLE__ *
   __ptr64,0,std::nullptr_t> > >::~unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct SC_HANDLE__ * __ptr64,int (__cdecl*)(struct SC_HANDLE__ *
   __ptr64),&int __cdecl CloseServiceHandle(struct SC_HANDLE__ * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct SC_HANDLE__ * __ptr64,struct SC_HANDLE__ *
   __ptr64,0,std::nullptr_t> > >(void) __ptr64 */

void __thiscall
wil::
unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
::
~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
          (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
           *this)

{
  if (*(SC_HANDLE *)this != (SC_HANDLE)0x0) {
    CloseServiceHandle(*(SC_HANDLE *)this);
  }
  return;
}



===== GetBytesNeeded @ 1800081a4 =====

/* public: unsigned long __cdecl PktMon::DriverInterface::GetBytesNeeded(unsigned long) __ptr64 */

ulong __thiscall PktMon::DriverInterface::GetBytesNeeded(DriverInterface *this,ulong param_1)

{
  ulong uVar1;
  BOOL BVar2;
  DWORD DVar3;
  bool bVar4;
  void *unaff_retaddr;
  DriverInterface *local_res8;
  ulong local_res10 [2];
  HANDLE local_res18;
  
  local_res8 = this;
  local_res10[0] = param_1;
  GetHandle(this);
  bVar4 = false;
  local_res10[0] = 0;
  local_res8 = (DriverInterface *)((ulonglong)local_res8 & 0xffffffff00000000);
  BVar2 = DeviceIoControl(local_res18,0x220418,(LPVOID)0x0,0,local_res10,4,(LPDWORD)&local_res8,
                          (LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    if (DVar3 != 0xea) {
      bVar4 = true;
    }
  }
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x96,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",bVar4,
             "Failed to get the buffer size needed for IOCTL 0x%x",0x220418);
  uVar1 = local_res10[0];
  if ((longlong)local_res18 - 1U < 0xfffffffffffffffe) {
    CloseHandle(local_res18);
  }
  return uVar1;
}



===== GetHandle @ 18000827c =====

/* private: class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::handle_null_resource_policy<int (__cdecl*)(void * __ptr64),&int __cdecl
   CloseHandle(void * __ptr64)> > > __cdecl PktMon::DriverInterface::GetHandle(void) __ptr64 */

void __thiscall PktMon::DriverInterface::GetHandle(DriverInterface *this)

{
  DWORD DVar1;
  HANDLE pvVar2;
  HANDLE pvVar3;
  DriverInterface *this_00;
  undefined8 *in_RDX;
  DriverInterface *unaff_retaddr;
  
  pvVar2 = CreateFileW(L"\\\\.\\PktMonDev",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                       (HANDLE)0x0);
  *in_RDX = pvVar2;
  if (0xfffffffffffffffd < (longlong)pvVar2 - 1U) {
    DVar1 = GetLastError();
    this_00 = unaff_retaddr;
    wil::details::in1diag3::Throw_GetLastErrorIfMsg
              (unaff_retaddr,0x3c,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",
               DVar1 != 2,"Failed to get an handle to Pktmon driver");
    StartDriverService(this_00);
    pvVar3 = CreateFileW(L"\\\\.\\PktMonDev",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                         (HANDLE)0x0);
    pvVar2 = (HANDLE)*in_RDX;
    if ((longlong)pvVar2 - 1U < 0xfffffffffffffffe) {
      DVar1 = GetLastError();
      CloseHandle(pvVar2);
      SetLastError(DVar1);
    }
    *in_RDX = pvVar3;
    wil::details::in1diag3::Throw_GetLastErrorIfMsg
              (unaff_retaddr,0x49,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",
               0xfffffffffffffffd < (longlong)pvVar3 - 1U,"Failed to get an handle to Pktmon driver"
              );
  }
  return;
}



===== SendIoCtl @ 1800083d4 =====

/* public: void __cdecl PktMon::DriverInterface::SendIoCtl(unsigned long,void * __ptr64,unsigned
   long,void * __ptr64,unsigned long) __ptr64 */

void __thiscall
PktMon::DriverInterface::SendIoCtl
          (DriverInterface *this,ulong param_1,void *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  BOOL BVar1;
  void *unaff_retaddr;
  DWORD local_res10 [2];
  
  GetHandle(this);
  local_res10[0] = 0;
  BVar1 = DeviceIoControl(this,param_1,param_2,param_3,param_4,param_5,local_res10,(LPOVERLAPPED)0x0
                         );
  wil::details::in1diag3::Throw_IfWin32BoolFalseMsg
            (unaff_retaddr,0x66,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",BVar1,
             "DeviceIoControl Failed to execute IoCtrl0x%x code",param_1);
  if (this + -1 < (DriverInterface *)0xfffffffffffffffe) {
    CloseHandle(this);
  }
  return;
}



===== StartDriverService @ 180008498 =====

/* private: void __cdecl PktMon::DriverInterface::StartDriverService(void) __ptr64 */

void __thiscall PktMon::DriverInterface::StartDriverService(DriverInterface *this)

{
  BOOL BVar1;
  DWORD DVar2;
  SC_HANDLE hSCManager;
  SC_HANDLE hService;
  bool bVar3;
  void *unaff_retaddr;
  
  bVar3 = true;
  hSCManager = OpenSCManagerW((LPCWSTR)0x0,L"ServicesActive",1);
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x18,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",
             hSCManager == (SC_HANDLE)0x0,"OpenSCManager failed");
  hService = OpenServiceW(hSCManager,L"PktMon",0x30);
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x1c,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",
             hService == (SC_HANDLE)0x0,"OpenService failed");
  BVar1 = StartServiceW(hService,0,(LPCWSTR *)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 != 0x420) goto LAB_180008576;
  }
  bVar3 = false;
LAB_180008576:
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x21,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmondriverservice.cpp",bVar3,
             "Failed to start the Pktmon driver");
  if (hService != (SC_HANDLE)0x0) {
    CloseServiceHandle(hService);
  }
  if (hSCManager != (SC_HANDLE)0x0) {
    CloseServiceHandle(hSCManager);
  }
  return;
}



===== Throw_GetLastErrorIfMsg @ 1800085e0 =====

/* bool __cdecl wil::details::in1diag3::Throw_GetLastErrorIfMsg(void * __ptr64,unsigned int,char
   const * __ptr64,bool,char const * __ptr64,...) */

bool __cdecl
wil::details::in1diag3::Throw_GetLastErrorIfMsg
          (void *param_1,uint param_2,char *param_3,bool param_4,char *param_5,...)

{
  code *pcVar1;
  undefined1 uVar2;
  void *unaff_retaddr;
  char cStack0000000000000030;
  
  if (param_4) {
    _Throw_GetLastErrorMsg(param_1,param_2,param_3,unaff_retaddr,param_5,&cStack0000000000000030);
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return (bool)uVar2;
  }
  return false;
}



===== Throw_IfWin32BoolFalseMsg @ 180008618 =====

/* int __cdecl wil::details::in1diag3::Throw_IfWin32BoolFalseMsg(void * __ptr64,unsigned int,char
   const * __ptr64,int,char const * __ptr64,...) */

int __cdecl
wil::details::in1diag3::Throw_IfWin32BoolFalseMsg
          (void *param_1,uint param_2,char *param_3,int param_4,char *param_5,...)

{
  code *pcVar1;
  int iVar2;
  void *unaff_retaddr;
  char cStack0000000000000030;
  
  if (param_4 == 0) {
    _Throw_GetLastErrorMsg(param_1,param_2,param_3,unaff_retaddr,param_5,&cStack0000000000000030);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return param_4;
}



===== _Throw_GetLastErrorMsg @ 180008650 =====

/* void __cdecl wil::details::in1diag3::_Throw_GetLastErrorMsg(void * __ptr64,unsigned int,char
   const * __ptr64,void * __ptr64,char const * __ptr64,char * __ptr64) */

void __cdecl
wil::details::in1diag3::_Throw_GetLastErrorMsg
          (void *param_1,uint param_2,char *param_3,void *param_4,char *param_5,char *param_6)

{
  code *pcVar1;
  char *in_stack_ffffffffffffffd8;
  
  ReportFailure_GetLastErrorMsg<0>
            (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffd8,param_4,param_5,param_6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ReportFailure_CaughtException<1> @ 18000867c =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl wil::details::ReportFailure_CaughtException<1>(void * __ptr64,unsigned int,char
   const * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,enum
   wil::SupportedExceptions) */

long __cdecl
wil::details::ReportFailure_CaughtException<1>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          SupportedExceptions param_7)

{
  long lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined1 auStackY_10a8 [32];
  char *in_stack_ffffffffffffef78;
  ReportFailureOptions in_stack_ffffffffffffef98;
  char local_1058 [8];
  undefined8 local_1050;
  undefined4 local_1048;
  undefined1 local_1040 [24];
  ushort local_1028 [2048];
  ulonglong local_28;
  undefined8 local_20;
  
  local_20 = 0x18000869c;
  local_28 = __security_cookie ^ (ulonglong)auStackY_10a8;
  memset(local_1028,0,0x1000);
  local_1058[0] = '\0';
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (local_1028[lVar3] != 0);
  if (g_pfnResultFromCaughtExceptionInternal != (code *)0x0) {
    param_4 = local_1058;
    puVar2 = (undefined8 *)
             (*g_pfnResultFromCaughtExceptionInternal)(local_1040,local_1028 + lVar3,0x800 - lVar3);
    local_1050 = *puVar2;
    local_1048 = *(undefined4 *)(puVar2 + 1);
    if ((int)local_1050 < 0) {
      ReportFailure_Base<1,0>
                (param_1,param_2,"onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapi.cpp",
                 param_4,in_stack_ffffffffffffef78,param_6,(ResultStatus *)&local_1050,local_1028,
                 in_stack_ffffffffffffef98);
      return (int)local_1050;
    }
  }
  local_1050 = CONCAT44(local_1050._4_4_,0x8007023e);
  lVar1 = HrToNtStatus(-0x7ff8fdc2);
  local_1050 = CONCAT44(lVar1,(int)local_1050);
  local_1048 = 0;
                    /* WARNING: Subroutine does not return */
  ReportFailure_Base<3,0>
            (param_1,param_2,"onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapi.cpp",
             param_4,in_stack_ffffffffffffef78,param_6,(ResultStatus *)&local_1050,local_1028,
             in_stack_ffffffffffffef98);
}



===== ReportFailure_CaughtException<3> @ 1800087cc =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* long __cdecl wil::details::ReportFailure_CaughtException<3>(void * __ptr64,unsigned int,char
   const * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,enum
   wil::SupportedExceptions) */

long __cdecl
wil::details::ReportFailure_CaughtException<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          SupportedExceptions param_7)

{
  code *pcVar1;
  long lVar2;
  char *in_stack_ffffffffffffefb8;
  void *in_stack_ffffffffffffefc0;
  SupportedExceptions in_stack_ffffffffffffefd8;
  undefined1 local_1018 [16];
  undefined1 local_1008 [4088];
  undefined8 uStack_10;
  
  uStack_10 = 0x1800087e1;
  memset(local_1008,0,0x1000);
  ReportFailure_CaughtExceptionCommon<3>
            (local_1018,(uint)param_1,(char *)(ulonglong)param_2,param_4,in_stack_ffffffffffffefb8,
             in_stack_ffffffffffffefc0,param_6,(__uint64)local_1008,in_stack_ffffffffffffefd8);
  pcVar1 = (code *)swi(3);
  lVar2 = (*pcVar1)();
  return lVar2;
}



===== ReportFailure_CaughtExceptionCommon<3> @ 180008828 =====

/* struct wil::details::ResultStatus __cdecl
   wil::details::ReportFailure_CaughtExceptionCommon<3>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,unsigned short *
   __ptr64,unsigned __int64,enum wil::SupportedExceptions) */

void __cdecl
wil::details::ReportFailure_CaughtExceptionCommon<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ushort *param_7,__uint64 param_8,SupportedExceptions param_9)

{
  code *pcVar1;
  char *in_stack_ffffffffffffffb8;
  void *in_stack_ffffffffffffffc0;
  SupportedExceptions in_stack_ffffffffffffffd8;
  undefined1 local_18 [24];
  
  ReportFailure_CaughtExceptionCommonNoReturnBase<3>
            (local_18,param_2,param_3,param_4,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
             param_7,param_8,in_stack_ffffffffffffffd8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ReportFailure_CaughtExceptionCommonNoReturnBase<3> @ 180008858 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* struct wil::details::ResultStatus __cdecl
   wil::details::ReportFailure_CaughtExceptionCommonNoReturnBase<3>(void * __ptr64,unsigned int,char
   const * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,unsigned short *
   __ptr64,unsigned __int64,enum wil::SupportedExceptions) */

void __cdecl
wil::details::ReportFailure_CaughtExceptionCommonNoReturnBase<3>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          ushort *param_7,__uint64 param_8,SupportedExceptions param_9)

{
  long lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 in_register_00000014;
  char cStack0000000000000050;
  char *in_stack_ffffffffffffffa8;
  ReportFailureOptions in_stack_ffffffffffffffc8;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_18 [16];
  
  cStack0000000000000050 = '\0';
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (*(short *)(param_8 + lVar3 * 2) != 0);
  if (g_pfnResultFromCaughtExceptionInternal != (code *)0x0) {
    param_4 = &cStack0000000000000050;
    puVar2 = (undefined8 *)
             (*g_pfnResultFromCaughtExceptionInternal)(local_18,param_8 + lVar3 * 2,0x800 - lVar3);
    local_28 = *puVar2;
    local_20 = *(undefined4 *)(puVar2 + 1);
    if ((int)local_28 < 0) {
                    /* WARNING: Subroutine does not return */
      ReportFailure_Base<3,0>
                ((void *)CONCAT44(in_register_00000014,param_2),(uint)param_3,
                 "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapi.cpp",param_4,
                 in_stack_ffffffffffffffa8,param_7,(ResultStatus *)&local_28,(ushort *)param_8,
                 in_stack_ffffffffffffffc8);
    }
  }
  local_28 = CONCAT44(local_28._4_4_,0x8007023e);
  lVar1 = HrToNtStatus(-0x7ff8fdc2);
  local_28 = CONCAT44(lVar1,(int)local_28);
  local_20 = 0;
                    /* WARNING: Subroutine does not return */
  ReportFailure_Base<3,0>
            ((void *)CONCAT44(in_register_00000014,param_2),(uint)param_3,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapi.cpp",param_4,
             in_stack_ffffffffffffffa8,param_7,(ResultStatus *)&local_28,(ushort *)param_8,
             in_stack_ffffffffffffffc8);
}



===== ~vector<unsigned_short,std::allocator<unsigned_short>_> @ 180008948 =====

/* public: __cdecl std::vector<unsigned short,class std::allocator<unsigned short>
   >::~vector<unsigned short,class std::allocator<unsigned short> >(void) __ptr64 */

void __thiscall
std::vector<unsigned_short,std::allocator<unsigned_short>_>::
~vector<unsigned_short,std::allocator<unsigned_short>_>
          (vector<unsigned_short,std::allocator<unsigned_short>_> *this)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  ulonglong uVar4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    uVar4 = (*(longlong *)(this + 0x10) - (longlong)pvVar1 >> 1) * 2;
    pvVar3 = pvVar1;
    if (0xfff < uVar4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      uVar4 = uVar4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,uVar4);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_> @ 1800089b4 =====

/* public: __cdecl std::vector<class PktMon::GatewayGroup const * __ptr64,class std::allocator<class
   PktMon::GatewayGroup const * __ptr64> >::~vector<class PktMon::GatewayGroup const * __ptr64,class
   std::allocator<class PktMon::GatewayGroup const * __ptr64> >(void) __ptr64 */

void __thiscall
std::
vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
          (vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
           *this)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = *(longlong *)(this + 0x10) - (longlong)pvVar1 & 0xfffffffffffffff8;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== `vector_deleting_destructor' @ 180008a20 =====

/* public: virtual void * __ptr64 __cdecl PacketMonitorObjectBase<101>::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
PacketMonitorObjectBase<101>::_vector_deleting_destructor_
          (PacketMonitorObjectBase<101> *this,uint param_1)

{
  *(uint *)(this + 8) = ~*(uint *)(this + 8);
  *(undefined ***)this = &PacketMonitorObjectBase<100>::_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x10);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 180008a60 =====

/* public: virtual void * __ptr64 __cdecl PacketMonitorSession::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
PacketMonitorSession::_scalar_deleting_destructor_(PacketMonitorSession *this,uint param_1)

{
  ~PacketMonitorSession(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x58);
  }
  return this;
}



===== FailFast_CaughtException @ 180008a9c =====

/* void __cdecl wil::details::in1diag3::FailFast_CaughtException(void * __ptr64,unsigned int,char
   const * __ptr64) */

void __cdecl
wil::details::in1diag3::FailFast_CaughtException(void *param_1,uint param_2,char *param_3)

{
  code *pcVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  SupportedExceptions in_stack_ffffffffffffffe8;
  
  ReportFailure_CaughtException<3>
            (param_1,param_2,param_3,in_R9,in_stack_ffffffffffffffd8,unaff_retaddr,
             in_stack_ffffffffffffffe8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== Return_CaughtException @ 180008ab8 =====

/* long __cdecl wil::details::in1diag3::Return_CaughtException(void * __ptr64,unsigned int,char
   const * __ptr64) */

long __cdecl
wil::details::in1diag3::Return_CaughtException(void *param_1,uint param_2,char *param_3)

{
  long lVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  SupportedExceptions in_stack_ffffffffffffffe8;
  
  lVar1 = ReportFailure_CaughtException<1>
                    (param_1,param_2,param_3,in_R9,in_stack_ffffffffffffffd8,unaff_retaddr,
                     in_stack_ffffffffffffffe8);
  return lVar1;
}



===== deallocate @ 180008ad8 =====

/* public: void __cdecl std::allocator<unsigned short>::deallocate(unsigned short * __ptr64
   const,unsigned __int64) __ptr64 */

void __thiscall
std::allocator<unsigned_short>::deallocate
          (allocator<unsigned_short> *this,ushort *param_1,__uint64 param_2)

{
  code *pcVar1;
  ushort *puVar2;
  ulonglong uVar3;
  
  uVar3 = param_2 * 2;
  puVar2 = param_1;
  if (0xfff < uVar3) {
    puVar2 = *(ushort **)(param_1 + -4);
    uVar3 = uVar3 + 0x27;
    if (0x1f < (ulonglong)((longlong)param_1 + (-8 - (longlong)puVar2))) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  operator_delete(puVar2,uVar3);
  return;
}



===== deallocate @ 180008b24 =====

/* public: void __cdecl std::allocator<class PktMon::GatewayGroup const * __ptr64>::deallocate(class
   PktMon::GatewayGroup const * __ptr64 * __ptr64 const,unsigned __int64) __ptr64 */

void __thiscall
std::allocator<PktMon::GatewayGroup_const*___ptr64>::deallocate
          (allocator<PktMon::GatewayGroup_const*___ptr64> *this,GatewayGroup **param_1,
          __uint64 param_2)

{
  code *pcVar1;
  GatewayGroup *pGVar2;
  ulonglong uVar3;
  
  uVar3 = param_2 * 8;
  pGVar2 = (GatewayGroup *)param_1;
  if (0xfff < uVar3) {
    pGVar2 = param_1[-1];
    uVar3 = uVar3 + 0x27;
    if (0x1f < (ulonglong)((longlong)param_1 + (-8 - (longlong)pGVar2))) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  operator_delete(pGVar2,uVar3);
  return;
}



===== PacketMonitorAddCaptureConstraint @ 180008b80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PacketMonitorAddCaptureConstraint(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  HANDLE hDevice;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  BOOL BVar7;
  undefined1 *puVar8;
  undefined1 auStack_148 [8];
  undefined1 auStack_140 [296];
  ulonglong local_18;
  
                    /* 0x8b80  10  PacketMonitorAddCaptureConstraint */
  puVar8 = auStack_148;
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  if (*(int *)(param_1 + 8) != 0x65) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(5);
    puVar8 = auStack_140;
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(puVar8 + -8) = 0x180008bd1;
  memset(puVar8 + 0x58,0,0xd8);
  *(undefined8 *)(puVar8 + 0x50) = uVar2;
  uVar2 = param_2[1];
  *(undefined8 *)(puVar8 + 0x58) = *param_2;
  *(undefined8 *)(puVar8 + 0x60) = uVar2;
  uVar2 = param_2[3];
  *(undefined8 *)(puVar8 + 0x68) = param_2[2];
  *(undefined8 *)(puVar8 + 0x70) = uVar2;
  uVar2 = param_2[5];
  *(undefined8 *)(puVar8 + 0x78) = param_2[4];
  *(undefined8 *)(puVar8 + 0x80) = uVar2;
  uVar2 = param_2[7];
  *(undefined8 *)(puVar8 + 0x88) = param_2[6];
  *(undefined8 *)(puVar8 + 0x90) = uVar2;
  uVar2 = param_2[9];
  *(undefined8 *)(puVar8 + 0x98) = param_2[8];
  *(undefined8 *)(puVar8 + 0xa0) = uVar2;
  uVar2 = param_2[0xb];
  *(undefined8 *)(puVar8 + 0xa8) = param_2[10];
  *(undefined8 *)(puVar8 + 0xb0) = uVar2;
  uVar2 = param_2[0xd];
  *(undefined8 *)(puVar8 + 0xb8) = param_2[0xc];
  *(undefined8 *)(puVar8 + 0xc0) = uVar2;
  uVar2 = param_2[0xf];
  *(undefined8 *)(puVar8 + 200) = param_2[0xe];
  *(undefined8 *)(puVar8 + 0xd0) = uVar2;
  uVar2 = param_2[0x11];
  *(undefined8 *)(puVar8 + 0xd8) = param_2[0x10];
  *(undefined8 *)(puVar8 + 0xe0) = uVar2;
  uVar2 = param_2[0x13];
  *(undefined8 *)(puVar8 + 0xe8) = param_2[0x12];
  *(undefined8 *)(puVar8 + 0xf0) = uVar2;
  uVar2 = param_2[0x15];
  *(undefined8 *)(puVar8 + 0xf8) = param_2[0x14];
  *(undefined8 *)(puVar8 + 0x100) = uVar2;
  uVar4 = *(undefined4 *)((longlong)param_2 + 0xb4);
  uVar5 = *(undefined4 *)(param_2 + 0x17);
  uVar6 = *(undefined4 *)((longlong)param_2 + 0xbc);
  *(undefined4 *)(puVar8 + 0x108) = *(undefined4 *)(param_2 + 0x16);
  *(undefined4 *)(puVar8 + 0x10c) = uVar4;
  *(undefined4 *)(puVar8 + 0x110) = uVar5;
  *(undefined4 *)(puVar8 + 0x114) = uVar6;
  uVar4 = *(undefined4 *)((longlong)param_2 + 0xc4);
  uVar5 = *(undefined4 *)(param_2 + 0x19);
  uVar6 = *(undefined4 *)((longlong)param_2 + 0xcc);
  *(undefined4 *)(puVar8 + 0x118) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(puVar8 + 0x11c) = uVar4;
  *(undefined4 *)(puVar8 + 0x120) = uVar5;
  *(undefined4 *)(puVar8 + 0x124) = uVar6;
  *(undefined8 *)(puVar8 + 0x128) = param_2[0x1a];
  *(undefined4 *)(puVar8 + 0x40) = 0;
  *(undefined8 *)(puVar8 + 0x38) = 0;
  *(undefined1 **)(puVar8 + 0x30) = puVar8 + 0x40;
  *(undefined4 *)(puVar8 + 0x28) = 0;
  *(undefined8 *)(puVar8 + 0x20) = 0;
  hDevice = *(HANDLE *)(lVar1 + 0x10);
  *(undefined8 *)(puVar8 + -8) = 0x180008c8b;
  BVar7 = DeviceIoControl(hDevice,0x228440,puVar8 + 0x50,0xe0,*(LPVOID *)(puVar8 + 0x20),
                          *(DWORD *)(puVar8 + 0x28),*(LPDWORD *)(puVar8 + 0x30),
                          *(LPOVERLAPPED *)(puVar8 + 0x38));
  if (BVar7 == 0) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar8 + -8) = &UNK_180008cdb;
    wil::details::in1diag3::_Throw_GetLastError
              (*(void **)(puVar8 + 0x148),0xdb,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp");
  }
  *(undefined8 *)(puVar8 + -8) = 0x180008cb4;
  return 0;
}



===== PacketMonitorAddSingleDataSourceToSession @ 180008cf0 =====

undefined8 PacketMonitorAddSingleDataSourceToSession(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ushort *puVar2;
  PacketMonitorApiHandle *this;
  undefined8 *lpInBuffer;
  HANDLE hDevice;
  code *pcVar3;
  BOOL BVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  __uint64 _Var9;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [104];
  
                    /* 0x8cf0  11  PacketMonitorAddSingleDataSourceToSession */
  puVar8 = auStack_88;
  if (*(int *)(param_1 + 8) != 0x65) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(5);
    puVar8 = auStack_80;
  }
  uVar1 = *(ushort *)(param_2 + 0x184);
  *(ushort *)(puVar8 + 0x90) = uVar1;
  puVar2 = *(ushort **)(param_1 + 0x28);
  if (puVar2 == *(ushort **)(param_1 + 0x30)) {
    *(undefined8 *)(puVar8 + -8) = 0x180008d41;
    std::vector<unsigned_short,std::allocator<unsigned_short>_>::
    _Emplace_reallocate<unsigned_short&___ptr64>
              ((vector<unsigned_short,std::allocator<unsigned_short>_> *)(param_1 + 0x20),puVar2,
               (ushort *)(puVar8 + 0x90));
  }
  else {
    *puVar2 = uVar1;
    *(longlong *)(param_1 + 0x28) = *(longlong *)(param_1 + 0x28) + 2;
  }
  this = *(PacketMonitorApiHandle **)(param_1 + 0x10);
  uVar5 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(puVar8 + 0x58) = 0;
  *(undefined8 *)(puVar8 + 0x60) = 0;
  *(undefined8 *)(puVar8 + 0x68) = 0;
  *(undefined8 *)(puVar8 + -8) = 0x180008d68;
  PacketMonitorApiHandle::GetDataSourceList(this,(__uint64)(puVar8 + 0x98));
  *(undefined8 *)(puVar8 + -8) = 0x180008d7f;
  DataSourceList::NormalizeAndValidateSelection
            ((DataSourceList *)(puVar8 + 0x98),
             (vector<unsigned_short,std::allocator<unsigned_short>_> *)(puVar8 + 0x40));
  if (*(longlong *)(puVar8 + 0x48) - *(longlong *)(puVar8 + 0x40) >> 2 == 0) {
    *(undefined8 *)(puVar8 + 0xa0) = 0x10;
    *(undefined8 *)(puVar8 + -8) = 0x180008df0;
    std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Reallocate<0>
              ((vector<unsigned_char,std::allocator<unsigned_char>_> *)(puVar8 + 0x58),
               (__uint64 *)(puVar8 + 0xa0));
  }
  else {
    uVar6 = (longlong)
            ((int)(*(longlong *)(puVar8 + 0x48) - *(longlong *)(puVar8 + 0x40) >> 2) * 4 + 0xc) + 4;
    *(ulonglong *)(puVar8 + 0xa0) = uVar6;
    if (uVar6 != 0) {
      if (0x7fffffffffffffff < uVar6) {
                    /* WARNING: Subroutine does not return */
        *(undefined8 *)(puVar8 + -8) = 0x180008ef0;
        std::
        vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
        ::_Xlength();
      }
      *(undefined8 *)(puVar8 + -8) = 0x180008dd0;
      std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Reallocate<0>
                ((vector<unsigned_char,std::allocator<unsigned_char>_> *)(puVar8 + 0x58),
                 (__uint64 *)(puVar8 + 0xa0));
    }
  }
  lpInBuffer = *(undefined8 **)(puVar8 + 0x58);
  *lpInBuffer = uVar5;
  *(undefined4 *)(lpInBuffer + 1) = 3;
  *(short *)((longlong)lpInBuffer + 0xc) =
       (short)(*(longlong *)(puVar8 + 0x48) - *(longlong *)(puVar8 + 0x40) >> 2);
  *(undefined8 *)(puVar8 + -8) = 0x180008e27;
  memmove(lpInBuffer + 2,*(void **)(puVar8 + 0x40),
          *(longlong *)(puVar8 + 0x48) - (longlong)*(void **)(puVar8 + 0x40));
  *(undefined4 *)(puVar8 + 0x90) = 0;
  _Var9 = *(longlong *)(puVar8 + 0x68) - (longlong)lpInBuffer;
  *(undefined8 *)(puVar8 + 0x38) = 0;
  *(undefined1 **)(puVar8 + 0x30) = puVar8 + 0x90;
  *(undefined4 *)(puVar8 + 0x28) = 0;
  *(undefined8 *)(puVar8 + 0x20) = 0;
  hDevice = *(HANDLE *)(this + 0x10);
  *(undefined8 *)(puVar8 + -8) = 0x180008e6b;
  BVar4 = DeviceIoControl(hDevice,0x228460,lpInBuffer,(DWORD)_Var9,*(LPVOID *)(puVar8 + 0x20),
                          *(DWORD *)(puVar8 + 0x28),*(LPDWORD *)(puVar8 + 0x30),
                          *(LPOVERLAPPED *)(puVar8 + 0x38));
  if (BVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar8 + -8) = &UNK_180008f01;
    wil::details::in1diag3::_Throw_GetLastError
              (*(void **)(puVar8 + 0x88),0x9d,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp");
  }
  *(undefined8 *)(puVar8 + -8) = 0x180008e86;
  std::vector<int,std::allocator<int>_>::~vector<int,std::allocator<int>_>
            ((vector<int,std::allocator<int>_> *)(puVar8 + 0x40));
  *(undefined8 *)(puVar8 + -8) = 0x180008e94;
  DataSourceList::~DataSourceList((DataSourceList *)(puVar8 + 0x98));
  puVar7 = lpInBuffer;
  if (0xfff < _Var9) {
    _Var9 = _Var9 + 0x27;
    puVar7 = (undefined8 *)lpInBuffer[-1];
    if (0x1f < (ulonglong)((longlong)lpInBuffer + (-8 - (longlong)puVar7))) {
      *(undefined8 *)(puVar8 + -8) = 0x180008ebd;
      _o__invalid_parameter_noinfo_noreturn();
      pcVar3 = (code *)swi(3);
      uVar5 = (*pcVar3)();
      return uVar5;
    }
  }
  *(undefined8 *)(puVar8 + -8) = 0x180008ece;
  operator_delete(puVar7,_Var9);
  return 0;
}



===== PacketMonitorAttachOutputToSession @ 180008f10 =====

undefined8 PacketMonitorAttachOutputToSession(longlong param_1,PacketMonitorStream *param_2)

{
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *this;
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  HANDLE hDevice;
  Component **ppCVar8;
  code *pcVar9;
  BOOL BVar10;
  long lVar11;
  ulonglong uVar12;
  PacketMonitorStream *pPVar13;
  undefined1 *puVar14;
  ulonglong auStackX_8 [3];
  undefined8 uStack_90;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  longlong lStack_68;
  DWORD aDStack_60 [2];
  longlong local_58 [4];
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined4 local_28;
  undefined2 local_24 [6];
  
                    /* 0x8f10  12  PacketMonitorAttachOutputToSession */
  puVar14 = auStack_88;
  pPVar13 = param_2;
  if (*(int *)(param_1 + 8) != 0x65) {
    pcVar9 = (code *)swi(0x29);
    (*pcVar9)(5);
    puVar14 = auStack_80;
  }
  if (*(int *)(pPVar13 + 8) != 0x66) {
    pcVar9 = (code *)swi(0x29);
    (*pcVar9)(5);
    puVar14 = puVar14 + 8;
  }
  *(PacketMonitorStream **)(puVar14 + 0xa0) = param_2;
  if (*(longlong *)(pPVar13 + 0x60) != 0) {
    *(undefined8 *)(puVar14 + -8) = 0x1800090b0;
    lVar11 = wil::verify_hresult<long>(-0x7ff8ffa9);
    *(undefined8 *)(puVar14 + -8) = 0x1800090cb;
    wil::details::in1diag3::Throw_Hr
              (*(void **)(puVar14 + 0x88),0x40,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonsession.cpp",lVar11);
LAB_1800090cb:
                    /* WARNING: Subroutine does not return */
    *(undefined8 *)(puVar14 + -8) = 0x1800090d0;
    std::
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  if (*(char *)(param_1 + 0x39) != '\0') {
    *(undefined8 *)(puVar14 + -8) = 0x180008f60;
    PacketMonitorStream::Start(param_2);
  }
  this = (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
         (param_1 + 0x40);
  uVar12 = (*(longlong *)(param_1 + 0x48) - *(longlong *)this >> 3) + 1;
  *(ulonglong *)(puVar14 + 0x90) = uVar12;
  if ((ulonglong)(*(longlong *)(param_1 + 0x50) - *(longlong *)this >> 3) < uVar12) {
    if (0x1fffffffffffffff < uVar12) goto LAB_1800090cb;
    *(undefined8 *)(puVar14 + -8) = 0x180008fad;
    std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
    _Reallocate<0>(this,(__uint64 *)(puVar14 + 0x90));
  }
  lVar4 = *(longlong *)(param_1 + 0x10);
  uVar1 = *(undefined2 *)(param_2 + 0x3a);
  uVar5 = *(undefined8 *)(param_1 + 0x18);
  uVar6 = *(undefined8 *)(param_2 + 0x48);
  uVar2 = *(undefined4 *)(param_2 + 0x58);
  uVar7 = *(undefined8 *)(param_2 + 0x40);
  uVar3 = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(puVar14 + 0x54) = 0;
  *(undefined2 *)(puVar14 + 0x66) = 0;
  *(undefined8 *)(puVar14 + 0x98) = 0;
  *(undefined8 *)(puVar14 + 0x40) = uVar5;
  *(undefined2 *)(puVar14 + 100) = uVar1;
  *(undefined8 *)(puVar14 + 0x58) = uVar7;
  *(undefined4 *)(puVar14 + 0x60) = uVar3;
  *(undefined8 *)(puVar14 + 0x48) = uVar6;
  *(undefined4 *)(puVar14 + 0x50) = uVar2;
  *(undefined4 *)(puVar14 + 0x90) = 0;
  *(undefined8 *)(puVar14 + 0x38) = 0;
  *(undefined1 **)(puVar14 + 0x30) = puVar14 + 0x90;
  *(undefined4 *)(puVar14 + 0x28) = 8;
  *(undefined1 **)(puVar14 + 0x20) = puVar14 + 0x98;
  hDevice = *(HANDLE *)(lVar4 + 0x10);
  *(undefined8 *)(puVar14 + -8) = 0x180009044;
  BVar10 = DeviceIoControl(hDevice,0x22042c,puVar14 + 0x40,0x28,*(LPVOID *)(puVar14 + 0x20),
                           *(DWORD *)(puVar14 + 0x28),*(LPDWORD *)(puVar14 + 0x30),
                           *(LPOVERLAPPED *)(puVar14 + 0x38));
  if (BVar10 == 0) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar14 + -8) = &UNK_1800090e1;
    wil::details::in1diag3::_Throw_GetLastError
              (*(void **)(puVar14 + 0x88),0x14e,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp");
  }
  *(longlong *)(param_2 + 0x60) = param_1;
  *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(puVar14 + 0x98);
  ppCVar8 = *(Component ***)(param_1 + 0x48);
  if (ppCVar8 == *(Component ***)(param_1 + 0x50)) {
    *(undefined8 *)(puVar14 + -8) = 0x180009089;
    std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
    _Emplace_reallocate<PktMon::Component*___ptr64>(this,ppCVar8,(Component **)(puVar14 + 0xa0));
  }
  else {
    *ppCVar8 = (Component *)param_2;
    *(longlong *)(param_1 + 0x48) = *(longlong *)(param_1 + 0x48) + 8;
  }
  return 0;
}



===== PacketMonitorCloseRealtimeStream @ 1800090f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void PacketMonitorCloseRealtimeStream(undefined8 *param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
                    /* 0x90f0  13  PacketMonitorCloseRealtimeStream */
  puVar2 = auStack_28;
  if (*(int *)(param_1 + 1) != 0x66) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar2 = auStack_20;
  }
  pcVar1 = *(code **)*param_1;
  *(undefined8 *)(puVar2 + -8) = 0x180009117;
  (*pcVar1)(param_1,1);
  return;
}



===== PacketMonitorCloseSessionHandle @ 180009130 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void PacketMonitorCloseSessionHandle(undefined8 *param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
                    /* 0x9130  14  PacketMonitorCloseSessionHandle */
  puVar2 = auStack_28;
  if (*(int *)(param_1 + 1) != 0x65) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar2 = auStack_20;
  }
  pcVar1 = *(code **)*param_1;
  *(undefined8 *)(puVar2 + -8) = 0x180009157;
  (*pcVar1)(param_1,1);
  return;
}



===== PacketMonitorCreateLiveSession @ 180009170 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PacketMonitorCreateLiveSession(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  HANDLE hDevice;
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  long lVar4;
  int extraout_EAX;
  undefined8 *puVar5;
  void *pvVar6;
  undefined1 *puVar7;
  undefined1 auStack_488 [8];
  undefined1 auStack_480 [1112];
  ulonglong local_28;
  
                    /* 0x9170  15  PacketMonitorCreateLiveSession */
  puVar7 = auStack_488;
  local_28 = __security_cookie ^ (ulonglong)auStack_488;
  *param_3 = 0;
  if (*(int *)(param_1 + 8) != 100) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar7 = auStack_480;
  }
  *(undefined8 *)(puVar7 + -8) = 0x1800091b9;
  memset(puVar7 + 0x50,0,0x200);
  *(undefined8 *)(puVar7 + -8) = 0x1800091ce;
  memset(puVar7 + 0x250,0,0x210);
  *(undefined8 *)(puVar7 + -8) = 0x1800091e2;
  iVar2 = _o_wcscpy_s(puVar7 + 0x50,0x100,param_2);
  if (iVar2 == 0) {
    *(undefined4 *)(puVar7 + 0x40) = 0;
    *(undefined8 *)(puVar7 + 0x38) = 0;
    *(undefined1 **)(puVar7 + 0x30) = puVar7 + 0x40;
    *(undefined4 *)(puVar7 + 0x28) = 0x210;
    *(undefined1 **)(puVar7 + 0x20) = puVar7 + 0x250;
    hDevice = *(HANDLE *)(param_1 + 0x10);
    *(undefined8 *)(puVar7 + -8) = 0x180009234;
    BVar3 = DeviceIoControl(hDevice,0x228434,puVar7 + 0x50,0x200,*(LPVOID *)(puVar7 + 0x20),
                            *(DWORD *)(puVar7 + 0x28),*(LPDWORD *)(puVar7 + 0x30),
                            *(LPOVERLAPPED *)(puVar7 + 0x38));
    pvVar6 = *(void **)(puVar7 + 0x488);
    iVar2 = 0;
    if (BVar3 != 0) {
      *(undefined8 *)(puVar7 + -8) = 0x180009253;
      puVar5 = operator_new(0x58);
      *(undefined4 *)(puVar5 + 1) = 0x65;
      *puVar5 = &PacketMonitorSession::_vftable_;
      puVar5[2] = param_1;
      puVar5[3] = *(undefined8 *)(puVar7 + 0x250);
      puVar5[4] = 0;
      puVar5[5] = 0;
      puVar5[6] = 0;
      *(undefined2 *)(puVar5 + 7) = 1;
      puVar5[8] = 0;
      puVar5[9] = 0;
      puVar5[10] = 0;
      *param_3 = puVar5;
      *(undefined8 *)(puVar7 + -8) = 0x1800092b3;
      return 0;
    }
  }
  else {
    *(undefined8 *)(puVar7 + -8) = 0x1800092c9;
    lVar4 = wil::verify_hresult<long>(-0x7ff8ffa9);
    pvVar6 = *(void **)(puVar7 + 0x488);
    *(undefined8 *)(puVar7 + -8) = 0x1800092e5;
    wil::details::in1diag3::Throw_Hr
              (pvVar6,0x4e,"onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp",
               lVar4);
    iVar2 = extraout_EAX;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar7 + -8) = &UNK_1800092f4;
  wil::details::in1diag3::_Throw_GetLastError
            (pvVar6,iVar2 + 0x5b,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp");
}



===== PacketMonitorCreateRealtimeStream @ 180009300 =====

undefined8
PacketMonitorCreateRealtimeStream
          (PacketMonitorApiHandle *param_1,PACKETMONITOR_REALTIME_STREAM_CONFIGURATION *param_2,
          undefined8 *param_3)

{
  code *pcVar1;
  PacketMonitorStream *this;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
                    /* 0x9300  16  PacketMonitorCreateRealtimeStream */
  puVar3 = auStack_28;
  *param_3 = 0;
  if (*(int *)(param_1 + 8) != 100) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar3 = auStack_20;
  }
  *(undefined8 *)(puVar3 + -8) = 0x180009333;
  this = operator_new(0x90);
  *(PacketMonitorStream **)(puVar3 + 0x30) = this;
  *(undefined8 *)(puVar3 + -8) = 0x180009346;
  uVar2 = PacketMonitorStream::PacketMonitorStream(this,param_1,param_2);
  *param_3 = uVar2;
  return 0;
}



===== PacketMonitorEnumDataSources @ 180009370 =====

undefined8
PacketMonitorEnumDataSources
          (PacketMonitorApiHandle *param_1,PACKETMONITOR_DATA_SOURCE_KIND param_2,uchar param_3,
          __uint64 param_4,undefined8 *param_5,longlong param_6)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
                    /* 0x9370  17  PacketMonitorEnumDataSources */
  puVar3 = auStack_38;
  *param_5 = 0;
  if ((param_6 == 0) == (param_4 == 0)) {
    if (*(int *)(param_1 + 8) != 100) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(5);
      puVar3 = auStack_30;
    }
    if ((param_2 == 0) || (param_2 == 1)) {
      *(longlong *)(puVar3 + 0x28) = param_6;
      *(undefined8 **)(puVar3 + 0x20) = param_5;
      *(undefined8 *)(puVar3 + -8) = 0x1800093e1;
      PacketMonitorApiHandle::EnumDataSources
                (param_1,param_2,param_4,param_3,*(__uint64 **)(puVar3 + 0x20),
                 *(PACKETMONITOR_DATA_SOURCE_LIST **)(puVar3 + 0x28));
      uVar2 = 0;
    }
    else {
      uVar2 = 0x80070057;
    }
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



===== PacketMonitorInitialize @ 180009400 =====

undefined8 PacketMonitorInitialize(int param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  PacketMonitorApiHandle *this;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
                    /* 0x9400  18  PacketMonitorInitialize */
  puVar3 = auStack_28;
  *param_3 = 0;
  if (param_2 != 0) {
    pcVar1 = (code *)swi(0x29);
    param_1 = (*pcVar1)(5);
    puVar3 = auStack_20;
  }
  if (param_1 == 0x10000) {
    *(undefined8 *)(puVar3 + -8) = 0x180009433;
    this = operator_new(0x20);
    *(PacketMonitorApiHandle **)(puVar3 + 0x38) = this;
    *(undefined8 *)(puVar3 + -8) = 0x180009445;
    uVar2 = PacketMonitorApiHandle::PacketMonitorApiHandle(this,0x10000);
    *param_3 = uVar2;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80070519;
  }
  return uVar2;
}



===== PacketMonitorSetSessionActive @ 180009460 =====

undefined8 PacketMonitorSetSessionActive(longlong param_1,char param_2)

{
  PacketMonitorApiHandle *this;
  __uint64 _Var1;
  undefined8 *puVar2;
  PacketMonitorStream *pPVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  undefined8 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
                    /* 0x9460  19  PacketMonitorSetSessionActive */
  puVar5 = auStack_28;
  if (*(int *)(param_1 + 8) != 0x65) {
    pcVar4 = (code *)swi(0x29);
    param_2 = (*pcVar4)(5);
    puVar5 = auStack_20;
  }
  this = *(PacketMonitorApiHandle **)(param_1 + 0x10);
  _Var1 = *(__uint64 *)(param_1 + 0x18);
  uVar6 = 0;
  if (param_2 == '\0') {
    *(undefined8 *)(puVar5 + -8) = 0x1800094c6;
    PacketMonitorApiHandle::SetSessionActive(this,_Var1,false);
    puVar2 = *(undefined8 **)(param_1 + 0x48);
    for (puVar7 = *(undefined8 **)(param_1 + 0x40); puVar7 != puVar2; puVar7 = puVar7 + 1) {
      pPVar3 = (PacketMonitorStream *)*puVar7;
      *(undefined8 *)(puVar5 + -8) = 0x1800094d8;
      PacketMonitorStream::Stop(pPVar3);
    }
  }
  else {
    uVar6 = 1;
    *(undefined8 *)(puVar5 + -8) = 0x1800094a1;
    PacketMonitorApiHandle::SetSessionActive(this,_Var1,true);
    puVar2 = *(undefined8 **)(param_1 + 0x48);
    for (puVar7 = *(undefined8 **)(param_1 + 0x40); puVar7 != puVar2; puVar7 = puVar7 + 1) {
      pPVar3 = (PacketMonitorStream *)*puVar7;
      *(undefined8 *)(puVar5 + -8) = 0x1800094b3;
      PacketMonitorStream::Start(pPVar3);
    }
  }
  *(undefined1 *)(param_1 + 0x39) = uVar6;
  return 0;
}



===== PacketMonitorUninitialize @ 180009510 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void PacketMonitorUninitialize(undefined8 *param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
                    /* 0x9510  20  PacketMonitorUninitialize */
  puVar2 = auStack_28;
  if (*(int *)(param_1 + 1) != 100) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar2 = auStack_20;
  }
  pcVar1 = *(code **)*param_1;
  *(undefined8 *)(puVar2 + -8) = 0x180009537;
  (*pcVar1)(param_1,1);
  return;
}



===== ReportFailure_GetLastError<0> @ 180009544 =====

/* unsigned long __cdecl wil::details::ReportFailure_GetLastError<0>(void * __ptr64,unsigned
   int,char const * __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64) */

ulong __cdecl
wil::details::ReportFailure_GetLastError<0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6)

{
  undefined8 *puVar1;
  char *in_stack_ffffffffffffffa8;
  ReportFailureOptions in_stack_ffffffffffffffc8;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_18 [16];
  
  GetLastErrorFail(param_1,param_2,param_3,param_4,in_stack_ffffffffffffffa8,param_6);
  puVar1 = (undefined8 *)ResultStatus::FromResult((long)local_18);
  local_28 = *puVar1;
  local_20 = *(undefined4 *)(puVar1 + 1);
                    /* WARNING: Subroutine does not return */
  ReportFailure_Base<0,0>
            (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffa8,param_6,
             (ResultStatus *)&local_28,(ushort *)0x0,in_stack_ffffffffffffffc8);
}



===== ReportFailure_Hr<0> @ 1800095c4 =====

/* void __cdecl wil::details::ReportFailure_Hr<0>(void * __ptr64,unsigned int,char const *
   __ptr64,char const * __ptr64,char const * __ptr64,void * __ptr64,long) */

void __cdecl
wil::details::ReportFailure_Hr<0>
          (void *param_1,uint param_2,char *param_3,char *param_4,char *param_5,void *param_6,
          long param_7)

{
  undefined8 *puVar1;
  char *in_stack_ffffffffffffffa8;
  ReportFailureOptions in_stack_ffffffffffffffc8;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 local_18 [24];
  
  puVar1 = (undefined8 *)ResultStatus::FromResult((long)local_18);
  local_28 = *puVar1;
  local_20 = *(undefined4 *)(puVar1 + 1);
                    /* WARNING: Subroutine does not return */
  ReportFailure_Base<0,0>
            (param_1,param_2,param_3,param_3,in_stack_ffffffffffffffa8,param_6,
             (ResultStatus *)&local_28,(ushort *)0x0,in_stack_ffffffffffffffc8);
}



===== _Reallocate<0> @ 180009628 =====

/* private: void __cdecl std::vector<unsigned char,class std::allocator<unsigned char>
   >::_Reallocate<0>(unsigned __int64 & __ptr64) __ptr64 */

void __thiscall
std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Reallocate<0>
          (vector<unsigned_char,std::allocator<unsigned_char>_> *this,__uint64 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  __uint64 _Var3;
  code *pcVar4;
  void *pvVar5;
  uchar *_Dst;
  
  lVar1 = *(longlong *)(this + 8);
  lVar2 = *(longlong *)this;
  _Var3 = *param_1;
  if (_Var3 < 0x1000) {
    _Dst = (uchar *)0x0;
    if (_Var3 != 0) {
      _Dst = operator_new(_Var3);
    }
  }
  else {
    if (_Var3 + 0x27 <= _Var3) {
                    /* WARNING: Subroutine does not return */
      _Throw_bad_array_new_length();
    }
    pvVar5 = operator_new(_Var3 + 0x27);
    if (pvVar5 == (void *)0x0) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    _Dst = (uchar *)((longlong)pvVar5 + 0x27U & 0xffffffffffffffe0);
    *(void **)(_Dst + -8) = pvVar5;
  }
  memmove(_Dst,*(void **)this,*(longlong *)(this + 8) - *(longlong *)this);
  _Change_array(this,_Dst,lVar1 - lVar2,*param_1);
  return;
}



===== _Resize_reallocate<std::_Value_init_tag> @ 1800096d8 =====

/* private: void __cdecl std::vector<unsigned char,class std::allocator<unsigned char>
   >::_Resize_reallocate<struct std::_Value_init_tag>(unsigned __int64,struct std::_Value_init_tag
   const & __ptr64) __ptr64 */

void __thiscall
std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Resize_reallocate<std::_Value_init_tag>
          (vector<unsigned_char,std::allocator<unsigned_char>_> *this,__uint64 param_1,
          _Value_init_tag *param_2)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  void *pvVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uchar *_Dst;
  
  uVar6 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  lVar1 = *(longlong *)(this + 8);
  lVar2 = *(longlong *)this;
  uVar5 = *(longlong *)(this + 0x10) - *(longlong *)this;
  if (0x7fffffffffffffff - (uVar5 >> 1) < uVar5) {
    uVar5 = 0x8000000000000026;
  }
  else {
    uVar6 = (uVar5 >> 1) + uVar5;
    if (uVar6 < param_1) {
      uVar6 = param_1;
    }
    if (uVar6 < 0x1000) {
      _Dst = (uchar *)0x0;
      if (uVar6 != 0) {
        _Dst = operator_new(uVar6);
      }
      goto LAB_18000979a;
    }
    uVar5 = uVar6 + 0x27;
    if (uVar5 <= uVar6) {
                    /* WARNING: Subroutine does not return */
      _Throw_bad_array_new_length();
    }
  }
  pvVar4 = operator_new(uVar5);
  if (pvVar4 == (void *)0x0) {
    _o__invalid_parameter_noinfo_noreturn();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  _Dst = (uchar *)((longlong)pvVar4 + 0x27U & 0xffffffffffffffe0);
  *(void **)(_Dst + -8) = pvVar4;
LAB_18000979a:
  memset(_Dst + (lVar1 - lVar2),0,param_1 - (lVar1 - lVar2));
  memmove(_Dst,*(void **)this,*(longlong *)(this + 8) - *(longlong *)this);
  _Change_array(this,_Dst,param_1,uVar6);
  return;
}



===== PacketMonitorApiHandle @ 1800097fc =====

/* public: __cdecl PacketMonitorApiHandle::PacketMonitorApiHandle(unsigned int) __ptr64 */

PacketMonitorApiHandle * __thiscall
PacketMonitorApiHandle::PacketMonitorApiHandle(PacketMonitorApiHandle *this,uint param_1)

{
  HANDLE pvVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  void *unaff_retaddr;
  
  *(undefined4 *)(this + 8) = 100;
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x10) = 0xffffffffffffffff;
  *(uint *)(this + 0x18) = param_1;
  pvVar3 = CreateFileW(L"\\\\.\\PktMonDev",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                       (HANDLE)0x0);
  pvVar1 = *(HANDLE *)(this + 0x10);
  if ((longlong)pvVar1 - 1U < 0xfffffffffffffffe) {
    DVar2 = GetLastError();
    CloseHandle(pvVar1);
    SetLastError(DVar2);
  }
  *(HANDLE *)(this + 0x10) = pvVar3;
  if (pvVar3 == (HANDLE)0xffffffffffffffff) {
    DVar2 = GetLastError();
    wil::details::in1diag3::Throw_GetLastErrorIfMsg
              (unaff_retaddr,0x36,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp",DVar2 != 2,
               "Failed to get an handle to Pktmon driver");
    StartDriverService();
    pvVar3 = CreateFileW(L"\\\\.\\PktMonDev",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                         (HANDLE)0x0);
    pvVar1 = *(HANDLE *)(this + 0x10);
    if ((longlong)pvVar1 - 1U < 0xfffffffffffffffe) {
      DVar2 = GetLastError();
      CloseHandle(pvVar1);
      SetLastError(DVar2);
    }
    *(HANDLE *)(this + 0x10) = pvVar3;
    wil::details::in1diag3::Throw_GetLastErrorIfMsg
              (unaff_retaddr,0x43,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp",
               pvVar3 == (HANDLE)0xffffffffffffffff,"Failed to get an handle to Pktmon driver");
  }
  return this;
}



===== ~PacketMonitorObjectBase<102> @ 1800099a4 =====

/* public: virtual __cdecl PacketMonitorObjectBase<102>::~PacketMonitorObjectBase<102>(void) __ptr64
    */

void __thiscall
PacketMonitorObjectBase<102>::~PacketMonitorObjectBase<102>(PacketMonitorObjectBase<102> *this)

{
  *(uint *)(this + 8) = ~*(uint *)(this + 8);
  *(undefined ***)this = &PacketMonitorObjectBase<100>::_vftable_;
  return;
}



===== ~vector<int,std::allocator<int>_> @ 1800099bc =====

/* public: __cdecl std::vector<int,class std::allocator<int> >::~vector<int,class
   std::allocator<int> >(void) __ptr64 */

void __thiscall
std::vector<int,std::allocator<int>_>::~vector<int,std::allocator<int>_>
          (vector<int,std::allocator<int>_> *this)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = *(longlong *)(this + 0x10) - (longlong)pvVar1 & 0xfffffffffffffffc;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== ~vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_> @ 180009a28 =====

/* public: __cdecl std::vector<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class
   std::allocator<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION> >::~vector<struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class std::allocator<struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION> >(void) __ptr64 */

void __thiscall
std::
vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
::
~vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
          (vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
           *this)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = (*(longlong *)(this + 0x10) - (longlong)pvVar1 >> 3) * 8;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== operator= @ 180009aa8 =====

/* public: class std::vector<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class
   std::allocator<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION> > & __ptr64 __cdecl
   std::vector<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class std::allocator<struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION> >::operator=(class std::vector<struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class std::allocator<struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION> > && __ptr64) __ptr64 */

vector<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class_std::allocator<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
* __thiscall
std::
vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
::operator=(vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
            *this,vector<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class_std::allocator<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
                  *param_1)

{
  void *pvVar1;
  code *pcVar2;
  vector<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class_std::allocator<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
  *pvVar3;
  void *pvVar4;
  __uint64 _Var5;
  
  if (this != (vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
               *)param_1) {
    pvVar1 = *(void **)this;
    if (pvVar1 != (void *)0x0) {
      _Var5 = (*(longlong *)(this + 0x10) - (longlong)pvVar1 >> 3) * 8;
      pvVar4 = pvVar1;
      if (0xfff < _Var5) {
        pvVar4 = *(void **)((longlong)pvVar1 + -8);
        _Var5 = _Var5 + 0x27;
        if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4))) {
          _o__invalid_parameter_noinfo_noreturn();
          pcVar2 = (code *)swi(3);
          pvVar3 = (vector<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class_std::allocator<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
                    *)(*pcVar2)();
          return pvVar3;
        }
      }
      operator_delete(pvVar4,_Var5);
      *(undefined8 *)this = 0;
      *(undefined8 *)(this + 8) = 0;
      *(undefined8 *)(this + 0x10) = 0;
    }
    *(undefined8 *)this = *(undefined8 *)param_1;
    *(undefined8 *)(this + 8) = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  return (vector<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class_std::allocator<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
          *)this;
}



===== `scalar_deleting_destructor' @ 180009b70 =====

/* public: virtual void * __ptr64 __cdecl PacketMonitorApiHandle::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
PacketMonitorApiHandle::_scalar_deleting_destructor_(PacketMonitorApiHandle *this,uint param_1)

{
  if ((longlong)*(HANDLE *)(this + 0x10) - 1U < 0xfffffffffffffffe) {
    CloseHandle(*(HANDLE *)(this + 0x10));
  }
  *(uint *)(this + 8) = ~*(uint *)(this + 8);
  *(undefined ***)this = &PacketMonitorObjectBase<100>::_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x20);
  }
  return this;
}



===== EnumDataSources @ 180009bd0 =====

/* public: void __cdecl PacketMonitorApiHandle::EnumDataSources(enum
   PACKETMONITOR_DATA_SOURCE_KIND,unsigned __int64,unsigned char,unsigned __int64 * __ptr64,struct
   PACKETMONITOR_DATA_SOURCE_LIST * __ptr64) __ptr64 */

void __thiscall
PacketMonitorApiHandle::EnumDataSources
          (PacketMonitorApiHandle *this,PACKETMONITOR_DATA_SOURCE_KIND param_1,__uint64 param_2,
          uchar param_3,__uint64 *param_4,PACKETMONITOR_DATA_SOURCE_LIST *param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  PACKETMONITOR_DATA_SOURCE_LIST *pPVar4;
  vector<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class_std::allocator<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
  *pvVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  PACKETMONITOR_DATA_SOURCE_LIST *pPVar10;
  undefined8 *puVar11;
  longlong lVar12;
  PACKETMONITOR_DATA_SOURCE_LIST *pPVar13;
  ulonglong uVar14;
  DataSourceList local_1f8 [8];
  undefined8 *local_1f0;
  undefined8 *puStack_1e8;
  undefined8 local_1e0;
  vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
  local_1d8 [32];
  undefined8 local_1b8 [54];
  
  GetDataSourceList(this,(__uint64)local_1f8);
  local_1f0 = (undefined8 *)0x0;
  puStack_1e8 = (undefined8 *)0x0;
  local_1e0 = 0;
  if (param_1 == 0) {
    pvVar5 = (vector<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class_std::allocator<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
              *)DataSourceList::GetAllDataSources(local_1f8,SUB81(local_1d8,0));
  }
  else {
    if (param_1 != 1) goto LAB_180009dca;
    pvVar5 = (vector<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class_std::allocator<struct_PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
              *)DataSourceList::GetNetworkAdapters(local_1f8,SUB81(local_1d8,0));
  }
  std::
  vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
  ::operator=((vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
               *)&local_1f0,pvVar5);
  std::
  vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
  ::
  ~vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
            (local_1d8);
  lVar8 = (longlong)puStack_1e8 - (longlong)local_1f0 >> 3;
  iVar1 = (int)lVar8;
  lVar12 = (longlong)(iVar1 * 0x609a90e8 + 8) + 8;
  uVar14 = lVar8 * 8 + lVar12;
  *param_4 = uVar14;
  if ((param_5 != (PACKETMONITOR_DATA_SOURCE_LIST *)0x0) && (uVar14 <= param_2)) {
    *(int *)param_5 = iVar1 * -0x73ecade3;
    pPVar13 = param_5 + lVar12;
    for (puVar11 = local_1f0; puVar11 != puStack_1e8; puVar11 = puVar11 + 0x35) {
      param_5 = param_5 + 8;
      lVar8 = 3;
      puVar3 = puVar11;
      puVar7 = local_1b8;
      do {
        puVar9 = puVar7;
        puVar6 = puVar3;
        uVar2 = puVar6[1];
        *puVar9 = *puVar6;
        puVar9[1] = uVar2;
        uVar2 = puVar6[3];
        puVar9[2] = puVar6[2];
        puVar9[3] = uVar2;
        uVar2 = puVar6[5];
        puVar9[4] = puVar6[4];
        puVar9[5] = uVar2;
        uVar2 = puVar6[7];
        puVar9[6] = puVar6[6];
        puVar9[7] = uVar2;
        uVar2 = puVar6[9];
        puVar9[8] = puVar6[8];
        puVar9[9] = uVar2;
        uVar2 = puVar6[0xb];
        puVar9[10] = puVar6[10];
        puVar9[0xb] = uVar2;
        uVar2 = puVar6[0xd];
        puVar9[0xc] = puVar6[0xc];
        puVar9[0xd] = uVar2;
        uVar2 = puVar6[0xf];
        puVar9[0xe] = puVar6[0xe];
        puVar9[0xf] = uVar2;
        lVar8 = lVar8 + -1;
        puVar3 = puVar6 + 0x10;
        puVar7 = puVar9 + 0x10;
      } while (lVar8 != 0);
      uVar2 = puVar6[0x11];
      puVar9[0x10] = puVar6[0x10];
      puVar9[0x11] = uVar2;
      uVar2 = puVar6[0x13];
      puVar9[0x12] = puVar6[0x12];
      puVar9[0x13] = uVar2;
      puVar9[0x14] = puVar6[0x14];
      lVar8 = 3;
      puVar3 = local_1b8;
      pPVar4 = pPVar13;
      do {
        pPVar10 = pPVar4;
        puVar7 = puVar3;
        uVar2 = puVar7[1];
        *(undefined8 *)pPVar10 = *puVar7;
        *(undefined8 *)(pPVar10 + 8) = uVar2;
        uVar2 = puVar7[3];
        *(undefined8 *)(pPVar10 + 0x10) = puVar7[2];
        *(undefined8 *)(pPVar10 + 0x18) = uVar2;
        uVar2 = puVar7[5];
        *(undefined8 *)(pPVar10 + 0x20) = puVar7[4];
        *(undefined8 *)(pPVar10 + 0x28) = uVar2;
        uVar2 = puVar7[7];
        *(undefined8 *)(pPVar10 + 0x30) = puVar7[6];
        *(undefined8 *)(pPVar10 + 0x38) = uVar2;
        uVar2 = puVar7[9];
        *(undefined8 *)(pPVar10 + 0x40) = puVar7[8];
        *(undefined8 *)(pPVar10 + 0x48) = uVar2;
        uVar2 = puVar7[0xb];
        *(undefined8 *)(pPVar10 + 0x50) = puVar7[10];
        *(undefined8 *)(pPVar10 + 0x58) = uVar2;
        uVar2 = puVar7[0xd];
        *(undefined8 *)(pPVar10 + 0x60) = puVar7[0xc];
        *(undefined8 *)(pPVar10 + 0x68) = uVar2;
        uVar2 = puVar7[0xf];
        *(undefined8 *)(pPVar10 + 0x70) = puVar7[0xe];
        *(undefined8 *)(pPVar10 + 0x78) = uVar2;
        lVar8 = lVar8 + -1;
        puVar3 = puVar7 + 0x10;
        pPVar4 = pPVar10 + 0x80;
      } while (lVar8 != 0);
      uVar2 = puVar7[0x11];
      *(undefined8 *)(pPVar10 + 0x80) = puVar7[0x10];
      *(undefined8 *)(pPVar10 + 0x88) = uVar2;
      uVar2 = puVar7[0x13];
      *(undefined8 *)(pPVar10 + 0x90) = puVar7[0x12];
      *(undefined8 *)(pPVar10 + 0x98) = uVar2;
      *(undefined8 *)(pPVar10 + 0xa0) = puVar7[0x14];
      *(PACKETMONITOR_DATA_SOURCE_LIST **)param_5 = pPVar13;
      pPVar13 = pPVar13 + 0x1a8;
    }
  }
LAB_180009dca:
  std::
  vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
  ::
  ~vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
            ((vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
              *)&local_1f0);
  DataSourceList::~DataSourceList(local_1f8);
  return;
}



===== GetDataSourceList @ 180009e00 =====

/* private: class DataSourceList __cdecl PacketMonitorApiHandle::GetDataSourceList(unsigned __int64)
   __ptr64 */

__uint64 __thiscall
PacketMonitorApiHandle::GetDataSourceList(PacketMonitorApiHandle *this,__uint64 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  undefined8 uVar3;
  uint *puVar4;
  __uint64 _Var5;
  uint *lpOutBuffer;
  undefined1 uVar6;
  ulonglong in_R8;
  undefined8 *lpInBuffer;
  void *unaff_retaddr;
  undefined8 local_res8 [2];
  ulonglong local_res18;
  CompList *local_res20;
  uint *local_40;
  undefined8 uStack_38;
  longlong local_30;
  
  lpOutBuffer = (uint *)0x0;
  local_res18 = in_R8 & 0xffffffff00000000;
  local_40 = (uint *)0x0;
  uStack_38 = 0;
  local_30 = 0;
  local_res8[0] = 1;
  std::vector<unsigned_char,std::allocator<unsigned_char>_>::resize
            ((vector<unsigned_char,std::allocator<unsigned_char>_> *)&local_40,0xc);
  puVar4 = local_40;
  while( true ) {
    if (lpOutBuffer != (uint *)0x0) {
      std::vector<unsigned_char,std::allocator<unsigned_char>_>::resize
                ((vector<unsigned_char,std::allocator<unsigned_char>_> *)&local_40,
                 (ulonglong)lpOutBuffer[2]);
      puVar4 = local_40;
    }
    lpOutBuffer = puVar4;
    lpInBuffer = local_res8;
    BVar2 = DeviceIoControl(*(HANDLE *)(this + 0x10),0x220458,lpInBuffer,8,lpOutBuffer,
                            (int)uStack_38 - (int)lpOutBuffer,(LPDWORD)&local_res18,
                            (LPOVERLAPPED)0x0);
    uVar6 = SUB81(lpInBuffer,0);
    if (BVar2 == 0) break;
    puVar4 = lpOutBuffer;
    if (*lpOutBuffer <= lpOutBuffer[1]) {
      *(undefined8 *)param_1 = 0;
      local_res20 = operator_new(0x88);
      uVar3 = PktMon::CompList::CompList
                        (local_res20,
                         (vector<unsigned_char,std::allocator<unsigned_char>_> *)&local_40,
                         (bool)uVar6);
      *(undefined8 *)param_1 = uVar3;
      if (local_40 != (uint *)0x0) {
        _Var5 = local_30 - (longlong)local_40;
        puVar4 = local_40;
        if (0xfff < _Var5) {
          _Var5 = _Var5 + 0x27;
          puVar4 = *(uint **)(local_40 + -2);
          if (0x1f < (ulonglong)((longlong)local_40 + (-8 - (longlong)puVar4))) {
            _o__invalid_parameter_noinfo_noreturn();
            pcVar1 = (code *)swi(3);
            _Var5 = (*pcVar1)();
            return _Var5;
          }
        }
        operator_delete(puVar4,_Var5);
      }
      return param_1;
    }
  }
                    /* WARNING: Subroutine does not return */
  wil::details::in1diag3::_Throw_GetLastError
            (unaff_retaddr,0xfc,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp");
}



===== SetSessionActive @ 180009f34 =====

/* public: void __cdecl PacketMonitorApiHandle::SetSessionActive(unsigned __int64,bool) __ptr64 */

void __thiscall
PacketMonitorApiHandle::SetSessionActive(PacketMonitorApiHandle *this,__uint64 param_1,bool param_2)

{
  BOOL BVar1;
  void *unaff_retaddr;
  DWORD local_res18 [2];
  __uint64 local_res20;
  
  local_res18[0] = 0;
  local_res20 = param_1;
  if (param_2) {
    BVar1 = DeviceIoControl(*(HANDLE *)(this + 0x10),0x228450,&local_res20,8,(LPVOID)0x0,0,
                            local_res18,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      wil::details::in1diag3::_Throw_GetLastError
                (unaff_retaddr,0xb4,
                 "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp");
    }
  }
  else {
    BVar1 = DeviceIoControl(*(HANDLE *)(this + 0x10),0x228454,&local_res20,8,(LPVOID)0x0,0,
                            local_res18,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      wil::details::in1diag3::_Throw_GetLastError
                (unaff_retaddr,0xc4,
                 "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp");
    }
  }
  return;
}



===== StartDriverService @ 18000a018 =====

void StartDriverService(void)

{
  BOOL BVar1;
  DWORD DVar2;
  SC_HANDLE hSCManager;
  SC_HANDLE hService;
  bool bVar3;
  void *unaff_retaddr;
  
  bVar3 = true;
  hSCManager = OpenSCManagerW((LPCWSTR)0x0,L"ServicesActive",1);
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x19,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp",
             hSCManager == (SC_HANDLE)0x0,"OpenSCManager failed");
  hService = OpenServiceW(hSCManager,L"PktMon",0x10);
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x1d,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp",
             hService == (SC_HANDLE)0x0,"OpenService failed");
  BVar1 = StartServiceW(hService,0,(LPCWSTR *)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 != 0x420) goto LAB_18000a0f1;
  }
  bVar3 = false;
LAB_18000a0f1:
  wil::details::in1diag3::Throw_GetLastErrorIfMsg
            (unaff_retaddr,0x22,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp",bVar3,
             "Failed to start the Pktmon driver");
  if (hService != (SC_HANDLE)0x0) {
    CloseServiceHandle(hService);
  }
  if (hSCManager != (SC_HANDLE)0x0) {
    CloseServiceHandle(hSCManager);
  }
  return;
}



===== Throw_Hr @ 18000a158 =====

/* void __cdecl wil::details::in1diag3::Throw_Hr(void * __ptr64,unsigned int,char const *
   __ptr64,long) */

void __cdecl wil::details::in1diag3::Throw_Hr(void *param_1,uint param_2,char *param_3,long param_4)

{
  code *pcVar1;
  undefined4 in_register_0000008c;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  
  ReportFailure_Hr<0>(param_1,param_2,param_3,(char *)CONCAT44(in_register_0000008c,param_4),
                      in_stack_ffffffffffffffd8,unaff_retaddr,param_4);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _Change_array @ 18000a178 =====

/* private: void __cdecl std::vector<unsigned char,class std::allocator<unsigned char>
   >::_Change_array(unsigned char * __ptr64 const,unsigned __int64,unsigned __int64) __ptr64 */

void __thiscall
std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Change_array
          (vector<unsigned_char,std::allocator<unsigned_char>_> *this,uchar *param_1,
          __uint64 param_2,__uint64 param_3)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = *(longlong *)(this + 0x10) - (longlong)pvVar1;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
  }
  *(uchar **)this = param_1;
  *(uchar **)(this + 8) = param_1 + param_2;
  *(uchar **)(this + 0x10) = param_1 + param_3;
  return;
}



===== _Throw_GetLastError @ 18000a20c =====

/* void __cdecl wil::details::in1diag3::_Throw_GetLastError(void * __ptr64,unsigned int,char const *
   __ptr64) */

void __cdecl wil::details::in1diag3::_Throw_GetLastError(void *param_1,uint param_2,char *param_3)

{
  code *pcVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffe8;
  
  ReportFailure_GetLastError<0>
            (param_1,param_2,param_3,in_R9,in_stack_ffffffffffffffe8,unaff_retaddr);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== deallocate @ 18000a228 =====

/* public: void __cdecl std::allocator<int>::deallocate(int * __ptr64 const,unsigned __int64)
   __ptr64 */

void __thiscall std::allocator<int>::deallocate(allocator<int> *this,int *param_1,__uint64 param_2)

{
  code *pcVar1;
  int *piVar2;
  ulonglong uVar3;
  
  uVar3 = param_2 * 4;
  piVar2 = param_1;
  if (0xfff < uVar3) {
    piVar2 = *(int **)(param_1 + -2);
    uVar3 = uVar3 + 0x27;
    if (0x1f < (ulonglong)((longlong)param_1 + (-8 - (longlong)piVar2))) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  operator_delete(piVar2,uVar3);
  return;
}



===== deallocate @ 18000a278 =====

/* public: void __cdecl std::allocator<struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION>::deallocate(struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION * __ptr64 const,unsigned __int64) __ptr64 */

void __thiscall
std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>::deallocate
          (allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION> *this,
          PACKETMONITOR_DATA_SOURCE_SPECIFICATION *param_1,__uint64 param_2)

{
  code *pcVar1;
  PACKETMONITOR_DATA_SOURCE_SPECIFICATION *pPVar2;
  __uint64 _Var3;
  
  _Var3 = param_2 * 0x1a8;
  pPVar2 = param_1;
  if (0xfff < _Var3) {
    pPVar2 = *(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)(param_1 + -8);
    _Var3 = _Var3 + 0x27;
    if ((PACKETMONITOR_DATA_SOURCE_SPECIFICATION *)0x1f < param_1 + (-8 - (longlong)pPVar2)) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  operator_delete(pPVar2,_Var3);
  return;
}



===== resize @ 18000a2c8 =====

/* public: void __cdecl std::vector<unsigned char,class std::allocator<unsigned char>
   >::resize(unsigned __int64) __ptr64 */

void __thiscall
std::vector<unsigned_char,std::allocator<unsigned_char>_>::resize
          (vector<unsigned_char,std::allocator<unsigned_char>_> *this,__uint64 param_1)

{
  void *_Dst;
  longlong lVar1;
  ulonglong uVar2;
  _Value_init_tag *in_R8;
  
  _Dst = *(void **)(this + 8);
  lVar1 = *(longlong *)this;
  uVar2 = (longlong)_Dst - lVar1;
  if (param_1 < uVar2) {
    lVar1 = lVar1 + param_1;
  }
  else {
    if (param_1 <= uVar2) {
      return;
    }
    if ((ulonglong)(*(longlong *)(this + 0x10) - lVar1) < param_1) {
      _Resize_reallocate<std::_Value_init_tag>(this,param_1,in_R8);
      return;
    }
    memset(_Dst,0,param_1 - uVar2);
    lVar1 = (param_1 - uVar2) + (longlong)_Dst;
  }
  *(longlong *)(this + 8) = lVar1;
  return;
}



===== _Emplace_reallocate<unsigned_short&___ptr64> @ 18000a340 =====

/* private: unsigned short * __ptr64 __cdecl std::vector<unsigned short,class
   std::allocator<unsigned short> >::_Emplace_reallocate<unsigned short & __ptr64>(unsigned short *
   __ptr64 const,unsigned short & __ptr64) __ptr64 */

ushort * __thiscall
std::vector<unsigned_short,std::allocator<unsigned_short>_>::
_Emplace_reallocate<unsigned_short&___ptr64>
          (vector<unsigned_short,std::allocator<unsigned_short>_> *this,ushort *param_1,
          ushort *param_2)

{
  ulonglong uVar1;
  ushort *puVar2;
  longlong lVar3;
  ushort *_Src;
  code *pcVar4;
  longlong lVar5;
  void *pvVar6;
  ulonglong uVar7;
  ushort *_Dst;
  void *pvVar8;
  ushort *puVar9;
  size_t _Size;
  ulonglong uVar10;
  
  lVar3 = *(longlong *)this;
  lVar5 = *(longlong *)(this + 8) - *(longlong *)this >> 1;
  if (lVar5 == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  uVar1 = lVar5 + 1;
  uVar7 = *(longlong *)(this + 0x10) - *(longlong *)this >> 1;
  if (0x7fffffffffffffff - (uVar7 >> 1) < uVar7) {
LAB_18000a4cf:
                    /* WARNING: Subroutine does not return */
    _Throw_bad_array_new_length();
  }
  uVar7 = (uVar7 >> 1) + uVar7;
  uVar10 = uVar1;
  if (uVar1 <= uVar7) {
    uVar10 = uVar7;
  }
  if (0x7fffffffffffffff < uVar10) goto LAB_18000a4cf;
  uVar7 = uVar10 * 2;
  if (uVar7 < 0x1000) {
    if (uVar7 == 0) {
      puVar9 = (ushort *)0x0;
    }
    else {
      puVar9 = operator_new(uVar7);
    }
  }
  else {
    if (uVar7 + 0x27 <= uVar7) goto LAB_18000a4cf;
    pvVar6 = operator_new(uVar7 + 0x27);
    if (pvVar6 == (void *)0x0) goto LAB_18000a4c2;
    puVar9 = (ushort *)((longlong)pvVar6 + 0x27U & 0xffffffffffffffe0);
    *(void **)(puVar9 + -4) = pvVar6;
  }
  puVar2 = puVar9 + ((longlong)param_1 - lVar3 >> 1);
  *puVar2 = *param_2;
  _Src = *(ushort **)this;
  if (param_1 == *(ushort **)(this + 8)) {
    _Size = (longlong)*(ushort **)(this + 8) - (longlong)_Src;
    _Dst = puVar9;
    param_1 = _Src;
  }
  else {
    memmove(puVar9,_Src,(longlong)param_1 - *(longlong *)this);
    _Dst = puVar2 + 1;
    _Size = *(longlong *)(this + 8) - (longlong)param_1;
  }
  memmove(_Dst,param_1,_Size);
  pvVar6 = *(void **)this;
  if (pvVar6 != (void *)0x0) {
    uVar7 = (*(longlong *)(this + 0x10) - (longlong)pvVar6 >> 1) * 2;
    pvVar8 = pvVar6;
    if (0xfff < uVar7) {
      uVar7 = uVar7 + 0x27;
      pvVar8 = *(void **)((longlong)pvVar6 + -8);
      if (0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar8))) {
LAB_18000a4c2:
        _o__invalid_parameter_noinfo_noreturn();
        pcVar4 = (code *)swi(3);
        puVar9 = (ushort *)(*pcVar4)();
        return puVar9;
      }
    }
    operator_delete(pvVar8,uVar7);
  }
  *(ushort **)this = puVar9;
  *(ushort **)(this + 8) = puVar9 + uVar1;
  *(ushort **)(this + 0x10) = puVar9 + uVar10;
  return puVar2;
}



===== _Emplace_reallocate<PktMon::Component*___ptr64> @ 18000a4e4 =====

/* private: class PktMon::Component * __ptr64 * __ptr64 __cdecl std::vector<class PktMon::Component
   * __ptr64,class std::allocator<class PktMon::Component * __ptr64> >::_Emplace_reallocate<class
   PktMon::Component * __ptr64>(class PktMon::Component * __ptr64 * __ptr64 const,class
   PktMon::Component * __ptr64 && __ptr64) __ptr64 */

Component ** __thiscall
std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
_Emplace_reallocate<PktMon::Component*___ptr64>
          (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *this,
          Component **param_1,Component **param_2)

{
  ulonglong uVar1;
  Component **ppCVar2;
  longlong lVar3;
  Component **_Src;
  void *pvVar4;
  code *pcVar5;
  longlong lVar6;
  Component *pCVar7;
  ulonglong uVar8;
  Component **_Dst;
  void *pvVar9;
  __uint64 _Var10;
  Component **ppCVar11;
  size_t _Size;
  ulonglong uVar12;
  
  lVar3 = *(longlong *)this;
  lVar6 = *(longlong *)(this + 8) - *(longlong *)this >> 3;
  if (lVar6 == 0x1fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  uVar1 = lVar6 + 1;
  uVar8 = *(longlong *)(this + 0x10) - *(longlong *)this >> 3;
  if (0x1fffffffffffffff - (uVar8 >> 1) < uVar8) {
LAB_18000a677:
                    /* WARNING: Subroutine does not return */
    _Throw_bad_array_new_length();
  }
  uVar8 = (uVar8 >> 1) + uVar8;
  uVar12 = uVar1;
  if (uVar1 <= uVar8) {
    uVar12 = uVar8;
  }
  if (0x1fffffffffffffff < uVar12) goto LAB_18000a677;
  uVar8 = uVar12 * 8;
  if (uVar8 < 0x1000) {
    if (uVar8 == 0) {
      ppCVar11 = (Component **)0x0;
    }
    else {
      ppCVar11 = operator_new(uVar8);
    }
  }
  else {
    if (uVar8 + 0x27 <= uVar8) goto LAB_18000a677;
    pCVar7 = operator_new(uVar8 + 0x27);
    if (pCVar7 == (Component *)0x0) goto LAB_18000a66a;
    ppCVar11 = (Component **)((ulonglong)(pCVar7 + 0x27) & 0xffffffffffffffe0);
    ppCVar11[-1] = pCVar7;
  }
  ppCVar2 = ppCVar11 + ((longlong)param_1 - lVar3 >> 3);
  *ppCVar2 = *param_2;
  _Src = *(Component ***)this;
  if (param_1 == *(Component ***)(this + 8)) {
    _Size = (longlong)*(Component ***)(this + 8) - (longlong)_Src;
    _Dst = ppCVar11;
    param_1 = _Src;
  }
  else {
    memmove(ppCVar11,_Src,(longlong)param_1 - *(longlong *)this);
    _Dst = ppCVar2 + 1;
    _Size = *(longlong *)(this + 8) - (longlong)param_1;
  }
  memmove(_Dst,param_1,_Size);
  pvVar4 = *(void **)this;
  if (pvVar4 != (void *)0x0) {
    _Var10 = *(longlong *)(this + 0x10) - (longlong)pvVar4 & 0xfffffffffffffff8;
    pvVar9 = pvVar4;
    if (0xfff < _Var10) {
      _Var10 = _Var10 + 0x27;
      pvVar9 = *(void **)((longlong)pvVar4 + -8);
      if (0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar9))) {
LAB_18000a66a:
        _o__invalid_parameter_noinfo_noreturn();
        pcVar5 = (code *)swi(3);
        ppCVar11 = (Component **)(*pcVar5)();
        return ppCVar11;
      }
    }
    operator_delete(pvVar9,_Var10);
  }
  *(Component ***)this = ppCVar11;
  *(Component ***)(this + 8) = ppCVar11 + uVar1;
  *(Component ***)(this + 0x10) = ppCVar11 + uVar12;
  return ppCVar2;
}



===== _Reallocate<0> @ 18000a68c =====

/* private: void __cdecl std::vector<class PktMon::Component * __ptr64,class std::allocator<class
   PktMon::Component * __ptr64> >::_Reallocate<0>(unsigned __int64 & __ptr64) __ptr64 */

void __thiscall
std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::_Reallocate<0>
          (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *this,
          __uint64 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  void *pvVar4;
  __uint64 _Var5;
  void *pvVar6;
  __uint64 _Var7;
  void *_Dst;
  
  lVar1 = *(longlong *)(this + 8);
  lVar2 = *(longlong *)this;
  if (0x1fffffffffffffff < *param_1) {
LAB_18000a792:
                    /* WARNING: Subroutine does not return */
    _Throw_bad_array_new_length();
  }
  _Var5 = *param_1 * 8;
  if (_Var5 < 0x1000) {
    if (_Var5 == 0) {
      _Dst = (void *)0x0;
    }
    else {
      _Dst = operator_new(_Var5);
    }
  }
  else {
    if (_Var5 + 0x27 <= _Var5) goto LAB_18000a792;
    pvVar4 = operator_new(_Var5 + 0x27);
    if (pvVar4 == (void *)0x0) goto LAB_18000a785;
    _Dst = (void *)((longlong)pvVar4 + 0x27U & 0xffffffffffffffe0);
    *(void **)((longlong)_Dst - 8) = pvVar4;
  }
  memmove(_Dst,*(void **)this,*(longlong *)(this + 8) - *(longlong *)this);
  _Var5 = *param_1;
  pvVar4 = *(void **)this;
  if (pvVar4 != (void *)0x0) {
    _Var7 = *(longlong *)(this + 0x10) - (longlong)pvVar4 & 0xfffffffffffffff8;
    pvVar6 = pvVar4;
    if (0xfff < _Var7) {
      _Var7 = _Var7 + 0x27;
      pvVar6 = *(void **)((longlong)pvVar4 + -8);
      if (0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar6))) {
LAB_18000a785:
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
    }
    operator_delete(pvVar6,_Var7);
  }
  *(void **)this = _Dst;
  *(void **)(this + 8) = (void *)((longlong)_Dst + (lVar1 - lVar2 >> 3) * 8);
  *(void **)(this + 0x10) = (void *)((longlong)_Dst + _Var5 * 8);
  return;
}



===== ~PacketMonitorSession @ 18000a7a0 =====

/* public: virtual __cdecl PacketMonitorSession::~PacketMonitorSession(void) __ptr64 */

void __thiscall PacketMonitorSession::~PacketMonitorSession(PacketMonitorSession *this)

{
  PSRWLOCK SRWLock;
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  BOOL BVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  void *unaff_retaddr;
  DWORD local_res8 [2];
  undefined8 local_res10;
  
  *(undefined ***)this = &_vftable_;
  if (this[0x38] != (PacketMonitorSession)0x0) {
    local_res10 = *(undefined8 *)(this + 0x18);
    local_res8[0] = 0;
    BVar4 = DeviceIoControl(*(HANDLE *)(*(longlong *)(this + 0x10) + 0x10),0x228438,&local_res10,8,
                            (LPVOID)0x0,0,local_res8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      wil::details::in1diag3::_Throw_GetLastError
                (unaff_retaddr,0x70,
                 "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp");
    }
    if (this[0x39] != (PacketMonitorSession)0x0) {
      puVar1 = *(undefined8 **)(this + 0x48);
      for (puVar5 = *(undefined8 **)(this + 0x40); puVar5 != puVar1; puVar5 = puVar5 + 1) {
        PacketMonitorStream::Stop((PacketMonitorStream *)*puVar5);
      }
    }
    plVar2 = *(longlong **)(this + 0x48);
    for (plVar6 = *(longlong **)(this + 0x40); plVar6 != plVar2; plVar6 = plVar6 + 1) {
      lVar3 = *plVar6;
      SRWLock = (PSRWLOCK)(lVar3 + 0x78);
      AcquireSRWLockExclusive(SRWLock);
      memset(*(void **)(lVar3 + 0x40),0,(ulonglong)*(uint *)(lVar3 + 0x54));
      memset(*(void **)(lVar3 + 0x48),0,(ulonglong)*(uint *)(lVar3 + 0x58));
      *(undefined8 *)(lVar3 + 0x60) = 0;
      *(undefined8 *)(lVar3 + 0x68) = 0;
      if (SRWLock != (PSRWLOCK)0x0) {
        ReleaseSRWLockExclusive(SRWLock);
      }
    }
  }
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(this + 0x40));
  std::vector<unsigned_short,std::allocator<unsigned_short>_>::
  ~vector<unsigned_short,std::allocator<unsigned_short>_>
            ((vector<unsigned_short,std::allocator<unsigned_short>_> *)(this + 0x20));
  *(undefined ***)this = &PacketMonitorObjectBase<100>::_vftable_;
  *(uint *)(this + 8) = ~*(uint *)(this + 8);
  return;
}



===== PacketMonitorStream @ 18000a8f0 =====

/* public: __cdecl PacketMonitorStream::PacketMonitorStream(class PacketMonitorApiHandle *
   __ptr64,struct PACKETMONITOR_REALTIME_STREAM_CONFIGURATION const * __ptr64) __ptr64 */

PacketMonitorStream * __thiscall
PacketMonitorStream::PacketMonitorStream
          (PacketMonitorStream *this,PacketMonitorApiHandle *param_1,
          PACKETMONITOR_REALTIME_STREAM_CONFIGURATION *param_2)

{
  uint uVar1;
  LPVOID pvVar2;
  HANDLE hObject;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ushort uVar6;
  DWORD dwErrCode;
  LPVOID pvVar7;
  HANDLE pvVar8;
  void *unaff_retaddr;
  
  *(undefined4 *)(this + 8) = 0x66;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0x10) = 0;
  *(PacketMonitorApiHandle **)(this + 0x18) = param_1;
  uVar3 = *(undefined4 *)(param_2 + 4);
  uVar4 = *(undefined4 *)(param_2 + 8);
  uVar5 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x24) = uVar3;
  *(undefined4 *)(this + 0x28) = uVar4;
  *(undefined4 *)(this + 0x2c) = uVar5;
  uVar3 = *(undefined4 *)(param_2 + 0x14);
  uVar4 = *(undefined4 *)(param_2 + 0x18);
  uVar5 = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(this + 0x34) = uVar3;
  *(undefined4 *)(this + 0x38) = uVar4;
  *(undefined4 *)(this + 0x3c) = uVar5;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  uVar6 = *(ushort *)(this + 0x38);
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  else if (9 < uVar6) {
    uVar6 = 10;
  }
  *(ushort *)(this + 0x38) = uVar6;
  *(uint *)(this + 0x50) = (uint)uVar6 * 1000;
  uVar1 = (uint)uVar6 * 8000 + 0x94;
  *(uint *)(this + 0x54) = uVar1;
  pvVar7 = VirtualAlloc((LPVOID)0x0,(ulonglong)uVar1,0x3000,4);
  pvVar2 = *(LPVOID *)(this + 0x40);
  *(LPVOID *)(this + 0x40) = pvVar7;
  if (pvVar2 != (LPVOID)0x0) {
    VirtualFree(pvVar2,0,0x8000);
  }
  if (*(longlong *)(this + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
    wil::details::in1diag3::_Throw_GetLastError
              (unaff_retaddr,0x34,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonstream.cpp");
  }
  *(uint *)(this + 0x58) = (uint)*(ushort *)(this + 0x38) << 0x12;
  pvVar7 = VirtualAlloc((LPVOID)0x0,(ulonglong)((uint)*(ushort *)(this + 0x38) << 0x12),0x3000,4);
  pvVar2 = *(LPVOID *)(this + 0x48);
  *(LPVOID *)(this + 0x48) = pvVar7;
  if (pvVar2 != (LPVOID)0x0) {
    VirtualFree(pvVar2,0,0x8000);
  }
  if (*(longlong *)(this + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
    wil::details::in1diag3::_Throw_GetLastError
              (unaff_retaddr,0x38,
               "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonstream.cpp");
  }
  if (8999 < (ushort)(*(short *)(this + 0x3a) - 1U)) {
    *(undefined2 *)(this + 0x3a) = 0x80;
  }
  pvVar8 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,EventDeliveryThread,this,0,(LPDWORD)0x0);
  hObject = *(HANDLE *)(this + 0x88);
  if ((longlong)hObject - 1U < 0xfffffffffffffffe) {
    dwErrCode = GetLastError();
    CloseHandle(hObject);
    SetLastError(dwErrCode);
  }
  *(HANDLE *)(this + 0x88) = pvVar8;
  return this;
}



===== ~unique_ptr<void,wil::virtualalloc_deleter> @ 18000ab08 =====

/* public: __cdecl wistd::unique_ptr<void,struct wil::virtualalloc_deleter>::~unique_ptr<void,struct
   wil::virtualalloc_deleter>(void) __ptr64 */

void __thiscall
wistd::unique_ptr<void,wil::virtualalloc_deleter>::~unique_ptr<void,wil::virtualalloc_deleter>
          (unique_ptr<void,wil::virtualalloc_deleter> *this)

{
  LPVOID lpAddress;
  
  lpAddress = *(LPVOID *)this;
  *(undefined8 *)this = 0;
  if (lpAddress != (LPVOID)0x0) {
    VirtualFree(lpAddress,0,0x8000);
  }
  return;
}



===== ~PacketMonitorStream @ 18000ab3c =====

/* public: virtual __cdecl PacketMonitorStream::~PacketMonitorStream(void) __ptr64 */

void __thiscall PacketMonitorStream::~PacketMonitorStream(PacketMonitorStream *this)

{
  PacketMonitorStream *SRWLock;
  longlong lVar1;
  ulonglong *_Src;
  LPVOID pvVar2;
  BOOL BVar3;
  DWORD dwErrCode;
  ulonglong *puVar4;
  size_t _Size;
  ulonglong *_Dst;
  void *unaff_retaddr;
  DWORD local_res8 [2];
  longlong local_res10;
  
  *(undefined ***)this = &_vftable_;
  if (*(longlong *)(this + 0x68) != 0) {
    local_res8[0] = 0;
    local_res10 = *(longlong *)(this + 0x68);
    BVar3 = DeviceIoControl(*(HANDLE *)(*(longlong *)(this + 0x18) + 0x10),0x220430,&local_res10,8,
                            (LPVOID)0x0,0,local_res8,(LPOVERLAPPED)0x0);
    if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      wil::details::in1diag3::_Throw_GetLastError
                (unaff_retaddr,0x164,
                 "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonapihandle.cpp");
    }
  }
  Stop(this);
  SRWLock = this + 0x78;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  *(undefined4 *)(this + 0x70) = 3;
  WakeAllConditionVariable((PCONDITION_VARIABLE)(this + 0x80));
  if (SRWLock != (PacketMonitorStream *)0x0) {
    dwErrCode = GetLastError();
    ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    SetLastError(dwErrCode);
  }
  WaitForSingleObject(*(HANDLE *)(this + 0x88),0xffffffff);
  lVar1 = *(longlong *)(this + 0x60);
  if (lVar1 != 0) {
    _Src = *(ulonglong **)(lVar1 + 0x48);
    puVar4 = __std_find_trivial_8(*(ulonglong **)(lVar1 + 0x40),_Src,(ulonglong)this);
    _Dst = puVar4;
    if (puVar4 != _Src) {
      while (puVar4 = puVar4 + 1, puVar4 != _Src) {
        if ((PacketMonitorStream *)*puVar4 != this) {
          *_Dst = *puVar4;
          _Dst = _Dst + 1;
        }
      }
    }
    if (_Dst != _Src) {
      _Size = *(longlong *)(lVar1 + 0x48) - (longlong)_Src;
      memmove(_Dst,_Src,_Size);
      *(size_t *)(lVar1 + 0x48) = _Size + (longlong)_Dst;
    }
  }
  if ((longlong)*(HANDLE *)(this + 0x88) - 1U < 0xfffffffffffffffe) {
    CloseHandle(*(HANDLE *)(this + 0x88));
  }
  pvVar2 = *(LPVOID *)(this + 0x48);
  *(undefined8 *)(this + 0x48) = 0;
  if (pvVar2 != (LPVOID)0x0) {
    VirtualFree(pvVar2,0,0x8000);
  }
  pvVar2 = *(LPVOID *)(this + 0x40);
  *(undefined8 *)(this + 0x40) = 0;
  if (pvVar2 != (LPVOID)0x0) {
    VirtualFree(pvVar2,0,0x8000);
  }
  *(undefined ***)this = &PacketMonitorObjectBase<100>::_vftable_;
  *(uint *)(this + 8) = ~*(uint *)(this + 8);
  return;
}



===== `vector_deleting_destructor' @ 18000ad30 =====

/* public: virtual void * __ptr64 __cdecl PacketMonitorStream::`vector deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
PacketMonitorStream::_vector_deleting_destructor_(PacketMonitorStream *this,uint param_1)

{
  ~PacketMonitorStream(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x90);
  }
  return this;
}



===== EventDeliveryThread @ 18000ad6c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: void __cdecl PacketMonitorStream::EventDeliveryThread(void) __ptr64 */

void __thiscall PacketMonitorStream::EventDeliveryThread(PacketMonitorStream *this)

{
  PacketMonitorStream *SRWLock;
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  char cVar5;
  BOOL BVar6;
  DWORD DVar7;
  uint uVar8;
  HANDLE pvVar9;
  ulonglong uVar10;
  __uint64 _Var11;
  short sVar12;
  uint uVar13;
  void *pvVar14;
  void *pvVar15;
  uint uVar16;
  uint uVar17;
  void *unaff_retaddr;
  undefined4 local_88;
  short sStack_84;
  undefined2 uStack_82;
  uint uStack_80;
  undefined4 uStack_7c;
  void *local_78;
  undefined8 local_70;
  longlong local_68;
  longlong local_60;
  uint local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  undefined4 local_44;
  
  pvVar9 = GetCurrentThread();
  SetThreadDescription(pvVar9,L"Packet Monitor real-time stream");
  local_88 = 0;
  sStack_84 = 0;
  uStack_82 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  lVar2 = *(longlong *)(this + 0x40);
  local_78 = (void *)0x0;
  local_70 = 0;
  local_68 = 0;
  std::vector<unsigned_char,std::allocator<unsigned_char>_>::resize
            ((vector<unsigned_char,std::allocator<unsigned_char>_> *)&local_78,9000);
  SRWLock = this + 0x78;
  pvVar14 = local_78;
  do {
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    while( true ) {
      while (iVar1 = *(int *)(this + 0x70), iVar1 == 0) {
        BVar6 = SleepConditionVariableSRW
                          ((PCONDITION_VARIABLE)(this + 0x80),(PSRWLOCK)SRWLock,0xffffffff,0);
        if ((BVar6 == 0) && (DVar7 = GetLastError(), DVar7 != 0x5b4)) {
                    /* WARNING: Subroutine does not return */
          wil::details::in1diag3::FailFast_Unexpected
                    (unaff_retaddr,0xd7c,
                     "onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
        }
      }
      if (iVar1 == 1) break;
      if (iVar1 != 2) {
        if (iVar1 != 3) {
                    /* WARNING: Subroutine does not return */
          wil::details::in1diag3::FailFast_Unexpected
                    (unaff_retaddr,0xae,
                     "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonstream.cpp");
        }
        if (SRWLock != (PacketMonitorStream *)0x0) {
          ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
        }
        goto LAB_18000b0d0;
      }
      *(undefined4 *)(this + 0x70) = 0;
      WakeAllConditionVariable((PCONDITION_VARIABLE)(this + 0x80));
    }
    if (SRWLock != (PacketMonitorStream *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    }
    local_88 = *(undefined4 *)(this + 0x58);
    sStack_84 = *(short *)(this + 0x3a);
    if (*(code **)(this + 0x28) != (code *)0x0) {
      (**(code **)(this + 0x28))(*(undefined8 *)(this + 0x20));
    }
    sVar12 = 0;
    local_88 = 0;
    sStack_84 = 0;
    uStack_82 = 0;
    uStack_80 = 0;
    uStack_7c = 0;
    while (*(int *)(this + 0x70) == 1) {
      uVar17 = (int)local_70 - (int)pvVar14;
      iVar1 = *(int *)(this + 0x58);
      lVar3 = *(longlong *)(this + 0x48);
      if (*(int *)(lVar2 + 0x8c) == 0) {
        sVar12 = 0xe8;
        Sleep(1);
LAB_18000aed8:
        pvVar14 = local_78;
      }
      else {
        if ((local_78 == (void *)0x0) || (uVar17 == 0)) {
          sVar12 = 0xa0;
LAB_18000b051:
          local_88 = CONCAT31(local_88._1_3_,1);
          pvVar14 = local_78;
          cVar5 = '\x01';
          goto LAB_18000b05b;
        }
        uVar10 = *(ulonglong *)(lVar2 + 0x94 + (ulonglong)*(uint *)(lVar2 + 4) * 8);
        *(uint *)(lVar2 + 4) = (*(uint *)(lVar2 + 4) + 1) % *(uint *)(this + 0x50);
        LOCK();
        *(int *)(lVar2 + 0x8c) = *(int *)(lVar2 + 0x8c) + -1;
        UNLOCK();
        sVar12 = 0;
        uVar13 = (uint)(uVar10 >> 0x20);
        if (uVar13 == 0) {
          sVar12 = 0x54f;
        }
        else {
          uVar16 = iVar1 - (int)uVar10;
          if (uVar17 < uVar13) {
            sVar12 = 0x7a;
            uVar17 = uVar13;
          }
          else {
            uVar17 = 0;
            uVar8 = uVar13;
            if (uVar16 < uVar13) {
              memcpy(local_78,(void *)((uVar10 & 0xffffffff) + lVar3),(ulonglong)uVar16);
              uVar8 = uVar13 - uVar16;
              uVar10 = 0;
              uVar17 = uVar16;
            }
            memcpy((void *)((ulonglong)uVar17 + (longlong)local_78),
                   (void *)((uVar10 & 0xffffffff) + lVar3),(ulonglong)uVar8);
            uVar17 = uVar13;
          }
        }
        pvVar14 = local_78;
        LOCK();
        *(int *)(lVar2 + 0x90) = *(int *)(lVar2 + 0x90) - uVar13;
        UNLOCK();
        if (sVar12 != 0) {
          if (sVar12 == 0x7a) {
            local_88 = CONCAT31(local_88._1_3_,1);
            sStack_84 = 0x7a;
            uStack_82 = 0;
            uStack_7c = 0;
            *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
            if (*(code **)(this + 0x28) != (code *)0x0) {
              uStack_80 = uVar17;
              (**(code **)(this + 0x28))(*(undefined8 *)(this + 0x20));
            }
            local_88 = 0;
            sStack_84 = 0;
            uStack_82 = 0;
            uStack_80 = 0;
            uStack_7c = 0;
            goto LAB_18000aed8;
          }
          goto LAB_18000b051;
        }
        if (uVar17 < 0x18) {
          local_88 = CONCAT31(local_88._1_3_,1);
          sVar12 = 0x54f;
          cVar5 = '\x01';
          goto LAB_18000b05b;
        }
        local_54 = 0;
        uStack_4c = 0;
        local_44 = 0;
        local_60 = (longlong)local_78 + 0x18;
        local_58 = uVar17 - 0x18;
        if (*(int *)((longlong)local_78 + 8) != 0x28) {
          local_88 = CONCAT31(local_88._1_3_,1);
          sVar12 = 0x65d;
          cVar5 = '\x01';
          goto LAB_18000b05b;
        }
        if (0x28 < local_58) {
          local_54 = 0x2800000000;
          uStack_4c = (ulonglong)(uVar17 - 0x40);
        }
        uStack_4c = CONCAT44(*(undefined4 *)((longlong)local_78 + 0xc),(undefined4)uStack_4c);
        local_44 = *(undefined4 *)(this + 0x10);
        if (*(code **)(this + 0x30) != (code *)0x0) {
          (**(code **)(this + 0x30))(*(undefined8 *)(this + 0x20));
        }
      }
    }
    cVar5 = (char)local_88;
LAB_18000b05b:
    pcVar4 = *(code **)(this + 0x28);
    if (cVar5 != '\0') {
      uStack_82 = 0;
      sStack_84 = sVar12;
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(*(undefined8 *)(this + 0x20),&local_88,2);
      }
      Stop(this);
LAB_18000b0d0:
      if (pvVar14 != (void *)0x0) {
        _Var11 = local_68 - (longlong)pvVar14;
        pvVar15 = pvVar14;
        if (0xfff < _Var11) {
          _Var11 = _Var11 + 0x27;
          pvVar15 = *(void **)((longlong)pvVar14 + -8);
          if (0x1f < (ulonglong)((longlong)pvVar14 + (-8 - (longlong)pvVar15))) {
            _o__invalid_parameter_noinfo_noreturn();
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
        }
        operator_delete(pvVar15,_Var11);
      }
      return;
    }
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(*(undefined8 *)(this + 0x20));
    }
    local_88 = 0;
    sStack_84 = 0;
    uStack_82 = 0;
    uStack_80 = 0;
    uStack_7c = 0;
  } while( true );
}



===== EventDeliveryThread @ 18000b160 =====

/* private: static unsigned long __cdecl PacketMonitorStream::EventDeliveryThread(void * __ptr64) */

ulong __cdecl PacketMonitorStream::EventDeliveryThread(void *param_1)

{
  EventDeliveryThread(param_1);
  return 0;
}



===== Start @ 18000b178 =====

/* public: void __cdecl PacketMonitorStream::Start(void) __ptr64 */

void __thiscall PacketMonitorStream::Start(PacketMonitorStream *this)

{
  PacketMonitorStream *SRWLock;
  DWORD dwErrCode;
  
  SRWLock = this + 0x78;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  *(undefined4 *)(this + 0x70) = 1;
  WakeAllConditionVariable((PCONDITION_VARIABLE)(this + 0x80));
  if (SRWLock != (PacketMonitorStream *)0x0) {
    dwErrCode = GetLastError();
    ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    SetLastError(dwErrCode);
  }
                    /* WARNING: Could not recover jumptable at 0x00018000b1fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WakeAllConditionVariable((PCONDITION_VARIABLE)(this + 0x80));
  return;
}



===== Stop @ 18000b210 =====

/* public: void __cdecl PacketMonitorStream::Stop(void) __ptr64 */

void __thiscall PacketMonitorStream::Stop(PacketMonitorStream *this)

{
  PacketMonitorStream *SRWLock;
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  void *unaff_retaddr;
  
  SRWLock = this + 0x78;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  while( true ) {
    while( true ) {
      iVar1 = *(int *)(this + 0x70);
      if (iVar1 == 0) {
        if (SRWLock != (PacketMonitorStream *)0x0) {
          ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
        }
        return;
      }
      if (iVar1 != 1) break;
      *(undefined4 *)(this + 0x70) = 2;
      WakeAllConditionVariable((PCONDITION_VARIABLE)(this + 0x80));
    }
    if (iVar1 != 2) break;
    BVar2 = SleepConditionVariableSRW
                      ((PCONDITION_VARIABLE)(this + 0x80),(PSRWLOCK)SRWLock,0xffffffff,0);
    if ((BVar2 == 0) && (DVar3 = GetLastError(), DVar3 != 0x5b4)) {
                    /* WARNING: Subroutine does not return */
      wil::details::in1diag3::FailFast_Unexpected
                (unaff_retaddr,0xd7c,"onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
    }
  }
                    /* WARNING: Subroutine does not return */
  wil::details::in1diag3::FailFast_Unexpected
            (unaff_retaddr,0x71,
             "onecore\\net\\diagnostics\\pktmon\\pktmonapi\\dll\\pktmonstream.cpp");
}



===== _Allocate_at_least_helper<std::allocator<PktMon::Component_const*___ptr64>_> @ 18000b2f0 =====

/* class PktMon::Component const * __ptr64 * __ptr64 __cdecl std::_Allocate_at_least_helper<class
   std::allocator<class PktMon::Component const * __ptr64> >(class std::allocator<class
   PktMon::Component const * __ptr64> & __ptr64,unsigned __int64 & __ptr64) */

Component ** __cdecl
std::_Allocate_at_least_helper<std::allocator<PktMon::Component_const*___ptr64>_>
          (allocator<PktMon::Component_const*___ptr64> *param_1,__uint64 *param_2)

{
  code *pcVar1;
  Component *pCVar2;
  Component **ppCVar3;
  __uint64 _Var4;
  
  if (0x1fffffffffffffff < *param_2) {
LAB_18000b35b:
                    /* WARNING: Subroutine does not return */
    _Throw_bad_array_new_length();
  }
  _Var4 = *param_2 * 8;
  if (_Var4 < 0x1000) {
    ppCVar3 = (Component **)0x0;
    if (_Var4 != 0) {
      ppCVar3 = operator_new(_Var4);
      return ppCVar3;
    }
  }
  else {
    if (_Var4 + 0x27 <= _Var4) goto LAB_18000b35b;
    pCVar2 = operator_new(_Var4 + 0x27);
    if (pCVar2 == (Component *)0x0) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      ppCVar3 = (Component **)(*pcVar1)();
      return ppCVar3;
    }
    ppCVar3 = (Component **)((ulonglong)(pCVar2 + 0x27) & 0xffffffffffffffe0);
    ppCVar3[-1] = pCVar2;
  }
  return ppCVar3;
}



===== _Allocate_for_capacity<0> @ 18000b368 =====

/* private: static unsigned short * __ptr64 __cdecl std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short>
   >::_Allocate_for_capacity<0>(class std::allocator<unsigned short> & __ptr64,unsigned __int64 &
   __ptr64) */

ushort * __cdecl
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
_Allocate_for_capacity<0>(allocator<unsigned_short> *param_1,__uint64 *param_2)

{
  code *pcVar1;
  __uint64 _Var2;
  void *pvVar3;
  ushort *puVar4;
  
  *param_2 = *param_2 + 1;
  if (0x7fffffffffffffff < *param_2) {
LAB_18000b3dc:
                    /* WARNING: Subroutine does not return */
    _Throw_bad_array_new_length();
  }
  _Var2 = *param_2 * 2;
  if (_Var2 < 0x1000) {
    puVar4 = (ushort *)0x0;
    if (_Var2 != 0) {
      puVar4 = operator_new(_Var2);
    }
  }
  else {
    if (_Var2 + 0x27 <= _Var2) goto LAB_18000b3dc;
    pvVar3 = operator_new(_Var2 + 0x27);
    if (pvVar3 == (void *)0x0) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      puVar4 = (ushort *)(*pcVar1)();
      return puVar4;
    }
    puVar4 = (ushort *)((longlong)pvVar3 + 0x27U & 0xffffffffffffffe0);
    *(void **)(puVar4 + -4) = pvVar3;
  }
  *param_2 = *param_2 - 1;
  return puVar4;
}



===== _Construct<1,unsigned_short_const*___ptr64> @ 18000b3e8 =====

/* private: void __cdecl std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Construct<1,unsigned short const *
   __ptr64>(unsigned short const * __ptr64 const,unsigned __int64) __ptr64 */

void __thiscall
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
_Construct<1,unsigned_short_const*___ptr64>
          (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
           *this,ushort *param_1,__uint64 param_2)

{
  ushort *_Dst;
  allocator<unsigned_short> *paVar1;
  allocator<unsigned_short> *local_res8;
  
  if (0x7ffffffffffffffe < param_2) {
                    /* WARNING: Subroutine does not return */
    _Xlen_string();
  }
  *(undefined8 *)(this + 0x18) = 7;
  if (param_2 < 8) {
    *(__uint64 *)(this + 0x10) = param_2;
    memcpy(this,param_1,param_2 * 2);
    *(undefined2 *)(this + param_2 * 2) = 0;
  }
  else {
    paVar1 = (allocator<unsigned_short> *)(param_2 | 7);
    local_res8 = (allocator<unsigned_short> *)0x7ffffffffffffffe;
    if ((paVar1 < (allocator<unsigned_short> *)0x7fffffffffffffff) &&
       (local_res8 = paVar1, paVar1 < (allocator<unsigned_short> *)0xa)) {
      local_res8 = (allocator<unsigned_short> *)0xa;
    }
    _Dst = _Allocate_for_capacity<0>(paVar1,(__uint64 *)&local_res8);
    *(__uint64 *)(this + 0x10) = param_2;
    *(allocator<unsigned_short> **)(this + 0x18) = local_res8;
    *(ushort **)this = _Dst;
    memcpy(_Dst,param_1,param_2 * 2);
    _Dst[param_2] = 0;
  }
  return;
}



===== _Emplace_reallocate<PACKETMONITOR_DATA_SOURCE_SPECIFICATION_const&___ptr64> @ 18000b4b4 =====

/* private: struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION * __ptr64 __cdecl std::vector<struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class std::allocator<struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION> >::_Emplace_reallocate<struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION const & __ptr64>(struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION * __ptr64 const,struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION const & __ptr64) __ptr64 */

PACKETMONITOR_DATA_SOURCE_SPECIFICATION * __thiscall
std::
vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
::_Emplace_reallocate<PACKETMONITOR_DATA_SOURCE_SPECIFICATION_const&___ptr64>
          (vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
           *this,PACKETMONITOR_DATA_SOURCE_SPECIFICATION *param_1,
          PACKETMONITOR_DATA_SOURCE_SPECIFICATION *param_2)

{
  ulonglong uVar1;
  PACKETMONITOR_DATA_SOURCE_SPECIFICATION *pPVar2;
  code *pcVar3;
  undefined8 uVar4;
  longlong lVar5;
  void *pvVar6;
  longlong lVar7;
  ulonglong uVar8;
  PACKETMONITOR_DATA_SOURCE_SPECIFICATION *pPVar9;
  void *pvVar10;
  __uint64 _Var11;
  PACKETMONITOR_DATA_SOURCE_SPECIFICATION *pPVar12;
  ulonglong uVar13;
  size_t _Size;
  PACKETMONITOR_DATA_SOURCE_SPECIFICATION *pPVar14;
  PACKETMONITOR_DATA_SOURCE_SPECIFICATION *pPVar15;
  
  lVar7 = *(longlong *)this;
  lVar5 = (*(longlong *)(this + 8) - *(longlong *)this >> 3) * 0x21cfb2b78c13521d;
  if (lVar5 == 0x9a90e7d95bc609) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  uVar1 = lVar5 + 1;
  uVar8 = (*(longlong *)(this + 0x10) - *(longlong *)this >> 3) * 0x21cfb2b78c13521d;
  if (0x9a90e7d95bc609 - (uVar8 >> 1) < uVar8) {
    uVar13 = 0xfffffffffffffee8;
    uVar8 = 0xffffffffffffff0f;
LAB_18000b591:
    pvVar6 = operator_new(uVar8);
    if (pvVar6 == (void *)0x0) goto LAB_18000b707;
    pPVar12 = (PACKETMONITOR_DATA_SOURCE_SPECIFICATION *)
              ((longlong)pvVar6 + 0x27U & 0xffffffffffffffe0);
    *(void **)(pPVar12 + -8) = pvVar6;
  }
  else {
    uVar8 = (uVar8 >> 1) + uVar8;
    uVar13 = uVar1;
    if (uVar1 <= uVar8) {
      uVar13 = uVar8;
    }
    if (0x9a90e7d95bc609 < uVar13) {
LAB_18000b714:
                    /* WARNING: Subroutine does not return */
      _Throw_bad_array_new_length();
    }
    uVar13 = uVar13 * 0x1a8;
    if (0xfff < uVar13) {
      uVar8 = uVar13 + 0x27;
      if (uVar8 <= uVar13) goto LAB_18000b714;
      goto LAB_18000b591;
    }
    if (uVar13 == 0) {
      pPVar12 = (PACKETMONITOR_DATA_SOURCE_SPECIFICATION *)0x0;
    }
    else {
      pPVar12 = operator_new(uVar13);
    }
  }
  pPVar14 = pPVar12 + (((longlong)param_1 - lVar7) / 0x1a8) * 0x1a8;
  lVar7 = 3;
  pPVar2 = pPVar14;
  do {
    pPVar15 = param_2;
    pPVar9 = pPVar2;
    uVar4 = *(undefined8 *)(pPVar15 + 8);
    *(undefined8 *)pPVar9 = *(undefined8 *)pPVar15;
    *(undefined8 *)(pPVar9 + 8) = uVar4;
    uVar4 = *(undefined8 *)(pPVar15 + 0x18);
    *(undefined8 *)(pPVar9 + 0x10) = *(undefined8 *)(pPVar15 + 0x10);
    *(undefined8 *)(pPVar9 + 0x18) = uVar4;
    uVar4 = *(undefined8 *)(pPVar15 + 0x28);
    *(undefined8 *)(pPVar9 + 0x20) = *(undefined8 *)(pPVar15 + 0x20);
    *(undefined8 *)(pPVar9 + 0x28) = uVar4;
    uVar4 = *(undefined8 *)(pPVar15 + 0x38);
    *(undefined8 *)(pPVar9 + 0x30) = *(undefined8 *)(pPVar15 + 0x30);
    *(undefined8 *)(pPVar9 + 0x38) = uVar4;
    uVar4 = *(undefined8 *)(pPVar15 + 0x48);
    *(undefined8 *)(pPVar9 + 0x40) = *(undefined8 *)(pPVar15 + 0x40);
    *(undefined8 *)(pPVar9 + 0x48) = uVar4;
    uVar4 = *(undefined8 *)(pPVar15 + 0x58);
    *(undefined8 *)(pPVar9 + 0x50) = *(undefined8 *)(pPVar15 + 0x50);
    *(undefined8 *)(pPVar9 + 0x58) = uVar4;
    uVar4 = *(undefined8 *)(pPVar15 + 0x68);
    *(undefined8 *)(pPVar9 + 0x60) = *(undefined8 *)(pPVar15 + 0x60);
    *(undefined8 *)(pPVar9 + 0x68) = uVar4;
    uVar4 = *(undefined8 *)(pPVar15 + 0x78);
    *(undefined8 *)(pPVar9 + 0x70) = *(undefined8 *)(pPVar15 + 0x70);
    *(undefined8 *)(pPVar9 + 0x78) = uVar4;
    lVar7 = lVar7 + -1;
    pPVar2 = pPVar9 + 0x80;
    param_2 = pPVar15 + 0x80;
  } while (lVar7 != 0);
  uVar4 = *(undefined8 *)(pPVar15 + 0x88);
  *(undefined8 *)(pPVar9 + 0x80) = *(undefined8 *)(pPVar15 + 0x80);
  *(undefined8 *)(pPVar9 + 0x88) = uVar4;
  uVar4 = *(undefined8 *)(pPVar15 + 0x98);
  *(undefined8 *)(pPVar9 + 0x90) = *(undefined8 *)(pPVar15 + 0x90);
  *(undefined8 *)(pPVar9 + 0x98) = uVar4;
  *(undefined8 *)(pPVar9 + 0xa0) = *(undefined8 *)(pPVar15 + 0xa0);
  pPVar2 = *(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)this;
  if (param_1 == *(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)(this + 8)) {
    _Size = (longlong)*(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)(this + 8) - (longlong)pPVar2;
    pPVar9 = pPVar12;
    param_1 = pPVar2;
  }
  else {
    memmove(pPVar12,pPVar2,(longlong)param_1 - *(longlong *)this);
    pPVar9 = pPVar14 + 0x1a8;
    _Size = *(longlong *)(this + 8) - (longlong)param_1;
  }
  memmove(pPVar9,param_1,_Size);
  pvVar6 = *(void **)this;
  if (pvVar6 != (void *)0x0) {
    _Var11 = (*(longlong *)(this + 0x10) - (longlong)pvVar6 >> 3) * 8;
    pvVar10 = pvVar6;
    if (0xfff < _Var11) {
      _Var11 = _Var11 + 0x27;
      pvVar10 = *(void **)((longlong)pvVar6 + -8);
      if (0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar10))) {
LAB_18000b707:
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        pPVar12 = (PACKETMONITOR_DATA_SOURCE_SPECIFICATION *)(*pcVar3)();
        return pPVar12;
      }
    }
    operator_delete(pvVar10,_Var11);
  }
  *(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)this = pPVar12;
  *(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)(this + 8) = pPVar12 + uVar1 * 0x1a8;
  *(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)(this + 0x10) = pPVar12 + uVar13;
  return pPVar14;
}



===== _Emplace_reallocate<int> @ 18000b728 =====

/* private: int * __ptr64 __cdecl std::vector<int,class std::allocator<int>
   >::_Emplace_reallocate<int>(int * __ptr64 const,int && __ptr64) __ptr64 */

int * __thiscall
std::vector<int,std::allocator<int>_>::_Emplace_reallocate<int>
          (vector<int,std::allocator<int>_> *this,int *param_1,int *param_2)

{
  ulonglong uVar1;
  int *piVar2;
  longlong lVar3;
  int *_Src;
  code *pcVar4;
  longlong lVar5;
  void *pvVar6;
  ulonglong uVar7;
  int *_Dst;
  void *pvVar8;
  __uint64 _Var9;
  int *piVar10;
  size_t _Size;
  ulonglong uVar11;
  
  lVar3 = *(longlong *)this;
  lVar5 = *(longlong *)(this + 8) - *(longlong *)this >> 2;
  if (lVar5 == 0x3fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  uVar1 = lVar5 + 1;
  uVar7 = *(longlong *)(this + 0x10) - *(longlong *)this >> 2;
  if (0x3fffffffffffffff - (uVar7 >> 1) < uVar7) {
LAB_18000b8ba:
                    /* WARNING: Subroutine does not return */
    _Throw_bad_array_new_length();
  }
  uVar7 = (uVar7 >> 1) + uVar7;
  uVar11 = uVar1;
  if (uVar1 <= uVar7) {
    uVar11 = uVar7;
  }
  if (0x3fffffffffffffff < uVar11) goto LAB_18000b8ba;
  uVar7 = uVar11 * 4;
  if (uVar7 < 0x1000) {
    if (uVar7 == 0) {
      piVar10 = (int *)0x0;
    }
    else {
      piVar10 = operator_new(uVar7);
    }
  }
  else {
    if (uVar7 + 0x27 <= uVar7) goto LAB_18000b8ba;
    pvVar6 = operator_new(uVar7 + 0x27);
    if (pvVar6 == (void *)0x0) goto LAB_18000b8ad;
    piVar10 = (int *)((longlong)pvVar6 + 0x27U & 0xffffffffffffffe0);
    *(void **)(piVar10 + -2) = pvVar6;
  }
  piVar2 = piVar10 + ((longlong)param_1 - lVar3 >> 2);
  *piVar2 = *param_2;
  _Src = *(int **)this;
  if (param_1 == *(int **)(this + 8)) {
    _Size = (longlong)*(int **)(this + 8) - (longlong)_Src;
    _Dst = piVar10;
    param_1 = _Src;
  }
  else {
    memmove(piVar10,_Src,(longlong)param_1 - *(longlong *)this);
    _Dst = piVar2 + 1;
    _Size = *(longlong *)(this + 8) - (longlong)param_1;
  }
  memmove(_Dst,param_1,_Size);
  pvVar6 = *(void **)this;
  if (pvVar6 != (void *)0x0) {
    _Var9 = *(longlong *)(this + 0x10) - (longlong)pvVar6 & 0xfffffffffffffffc;
    pvVar8 = pvVar6;
    if (0xfff < _Var9) {
      _Var9 = _Var9 + 0x27;
      pvVar8 = *(void **)((longlong)pvVar6 + -8);
      if (0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar8))) {
LAB_18000b8ad:
        _o__invalid_parameter_noinfo_noreturn();
        pcVar4 = (code *)swi(3);
        piVar10 = (int *)(*pcVar4)();
        return piVar10;
      }
    }
    operator_delete(pvVar8,_Var9);
  }
  *(int **)this = piVar10;
  *(int **)(this + 8) = piVar10 + uVar1;
  *(int **)(this + 0x10) = piVar10 + uVar11;
  return piVar2;
}



===== _Erase_tree<std::allocator<std::_Tree_node<long,void*___ptr64>_>_> @ 18000b8cc =====

/* public: void __cdecl std::_Tree_val<struct std::_Tree_simple_types<long> >::_Erase_tree<class
   std::allocator<struct std::_Tree_node<long,void * __ptr64> > >(class std::allocator<struct
   std::_Tree_node<long,void * __ptr64> > & __ptr64,struct std::_Tree_node<long,void * __ptr64> *
   __ptr64) __ptr64 */

void __thiscall
std::_Tree_val<std::_Tree_simple_types<long>_>::
_Erase_tree<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
          (_Tree_val<std::_Tree_simple_types<long>_> *this,
          allocator<std::_Tree_node<long,void*___ptr64>_> *param_1,
          _Tree_node<long,void*___ptr64> *param_2)

{
  _Tree_node<long,void*___ptr64> _Var1;
  _Tree_node<long,void*___ptr64> *p_Var2;
  
  _Var1 = param_2[0x19];
  while (_Var1 == (_Tree_node<long,void*___ptr64>)0x0) {
    _Erase_tree<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
              (this,param_1,*(_Tree_node<long,void*___ptr64> **)(param_2 + 0x10));
    p_Var2 = *(_Tree_node<long,void*___ptr64> **)param_2;
    operator_delete(param_2,0x20);
    param_2 = p_Var2;
    _Var1 = p_Var2[0x19];
  }
  return;
}



===== _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_> @ 18000b928 =====

/* public: void __cdecl std::_Tree_val<struct std::_Tree_simple_types<struct std::pair<unsigned long
   const ,class PktMon::GatewayGroup> > >::_Erase_tree<class std::allocator<struct
   std::_Tree_node<struct std::pair<unsigned long const ,class PktMon::GatewayGroup>,void * __ptr64>
   > >(class std::allocator<struct std::_Tree_node<struct std::pair<unsigned long const ,class
   PktMon::GatewayGroup>,void * __ptr64> > & __ptr64,struct std::_Tree_node<struct
   std::pair<unsigned long const ,class PktMon::GatewayGroup>,void * __ptr64> * __ptr64) __ptr64 */

void __thiscall
std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>::
_Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_>
          (_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
           *this,allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>
                 *param_1,
          _Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64> *param_2)

{
  _Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64> _Var1;
  _Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64> *p_Var2;
  
  _Var1 = param_2[0x19];
  while (_Var1 == (_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>)
                  0x0) {
    _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_>
              (this,param_1,
               *(_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64> **)
                (param_2 + 0x10));
    p_Var2 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64> **)
              param_2;
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(param_2 + 0x38));
    operator_delete(param_2,0x50);
    param_2 = p_Var2;
    _Var1 = p_Var2[0x19];
  }
  return;
}



===== _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_> @ 18000b99c =====

/* public: void __cdecl std::_Tree_val<struct std::_Tree_simple_types<struct std::pair<unsigned long
   const ,class PktMon::NicGroup> > >::_Erase_tree<class std::allocator<struct
   std::_Tree_node<struct std::pair<unsigned long const ,class PktMon::NicGroup>,void * __ptr64> >
   >(class std::allocator<struct std::_Tree_node<struct std::pair<unsigned long const ,class
   PktMon::NicGroup>,void * __ptr64> > & __ptr64,struct std::_Tree_node<struct std::pair<unsigned
   long const ,class PktMon::NicGroup>,void * __ptr64> * __ptr64) __ptr64 */

void __thiscall
std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>::
_Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
          (_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
           *this,allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>
                 *param_1,
          _Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *param_2)

{
  _Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> _Var1;
  _Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *p_Var2;
  
  _Var1 = param_2[0x19];
  while (_Var1 == (_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>)0x0) {
    _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
              (this,param_1,
               *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)
                (param_2 + 0x10));
    p_Var2 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)param_2
    ;
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(param_2 + 0x78));
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(param_2 + 0x60));
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(param_2 + 0x48));
    operator_delete(param_2,0x98);
    param_2 = p_Var2;
    _Var1 = p_Var2[0x19];
  }
  return;
}



===== _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_> @ 18000ba20 =====

/* public: void __cdecl std::_Tree_val<struct std::_Tree_simple_types<struct std::pair<unsigned long
   const ,class PktMon::VMSwitch> > >::_Erase_tree<class std::allocator<struct
   std::_Tree_node<struct std::pair<unsigned long const ,class PktMon::VMSwitch>,void * __ptr64> >
   >(class std::allocator<struct std::_Tree_node<struct std::pair<unsigned long const ,class
   PktMon::VMSwitch>,void * __ptr64> > & __ptr64,struct std::_Tree_node<struct std::pair<unsigned
   long const ,class PktMon::VMSwitch>,void * __ptr64> * __ptr64) __ptr64 */

void __thiscall
std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>::
_Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
          (_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
           *this,allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>
                 *param_1,
          _Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *param_2)

{
  _Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> _Var1;
  _Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *p_Var2;
  
  _Var1 = param_2[0x19];
  while (_Var1 == (_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>)0x0) {
    _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
              (this,param_1,
               *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)
                (param_2 + 0x10));
    p_Var2 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)param_2
    ;
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(param_2 + 0x78));
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(param_2 + 0x60));
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(param_2 + 0x38));
    operator_delete(param_2,0x90);
    param_2 = p_Var2;
    _Var1 = p_Var2[0x19];
  }
  return;
}



===== vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_> @ 18000baa4 =====

/* public: __cdecl std::vector<class PktMon::Component const * __ptr64,class std::allocator<class
   PktMon::Component const * __ptr64> >::vector<class PktMon::Component const * __ptr64,class
   std::allocator<class PktMon::Component const * __ptr64> >(class std::vector<class
   PktMon::Component const * __ptr64,class std::allocator<class PktMon::Component const * __ptr64> >
   const & __ptr64) __ptr64 */

vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_> *
__thiscall
std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
          (vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
           *this,vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  Component **_Dst;
  ulonglong uVar3;
  __uint64 local_res8;
  
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  uVar3 = *(longlong *)(param_1 + 8) - *(longlong *)param_1 >> 3;
  if (uVar3 != 0) {
    if (0x1fffffffffffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
      vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
      ::_Xlength();
    }
    local_res8 = uVar3;
    _Dst = _Allocate_at_least_helper<std::allocator<PktMon::Component_const*___ptr64>_>
                     ((allocator<PktMon::Component_const*___ptr64> *)this,&local_res8);
    *(Component ***)this = _Dst;
    *(Component ***)(this + 8) = _Dst;
    *(Component ***)(this + 0x10) = _Dst + uVar3;
    lVar1 = *(longlong *)(param_1 + 8);
    lVar2 = *(longlong *)param_1;
    memmove(_Dst,*(void **)param_1,lVar1 - lVar2);
    local_res8 = 0;
    *(Component ***)(this + 8) = _Dst + (lVar1 - lVar2 >> 3);
    _Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
    ::
    ~_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
              ((_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
                *)&local_res8);
  }
  return this;
}



===== vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_> @ 18000bb64 =====

/* public: __cdecl std::vector<class PktMon::NicGroup const * __ptr64,class std::allocator<class
   PktMon::NicGroup const * __ptr64> >::vector<class PktMon::NicGroup const * __ptr64,class
   std::allocator<class PktMon::NicGroup const * __ptr64> >(class std::vector<class PktMon::NicGroup
   const * __ptr64,class std::allocator<class PktMon::NicGroup const * __ptr64> > const & __ptr64)
   __ptr64 */

vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_> *
__thiscall
std::vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>::
vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
          (vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
           *this,vector<class_PktMon::NicGroup_const*___ptr64,class_std::allocator<class_PktMon::NicGroup_const*___ptr64>_>
                 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *pvVar5;
  vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_> *pvVar6;
  void *_Dst;
  undefined8 local_res8;
  
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  uVar4 = *(longlong *)(param_1 + 8) - *(longlong *)param_1 >> 3;
  if (uVar4 != 0) {
    if (0x1fffffffffffffff < uVar4) {
                    /* WARNING: Subroutine does not return */
      vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
      ::_Xlength();
    }
    uVar4 = uVar4 * 8;
    if (uVar4 < 0x1000) {
      if (uVar4 == 0) {
        _Dst = (void *)0x0;
      }
      else {
        _Dst = operator_new(uVar4);
      }
    }
    else {
      if (uVar4 + 0x27 <= uVar4) {
                    /* WARNING: Subroutine does not return */
        _Throw_bad_array_new_length();
      }
      pvVar5 = operator_new(uVar4 + 0x27);
      if (pvVar5 == (void *)0x0) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        pvVar6 = (vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
                  *)(*pcVar3)();
        return pvVar6;
      }
      _Dst = (void *)((longlong)pvVar5 + 0x27U & 0xffffffffffffffe0);
      *(void **)((longlong)_Dst - 8) = pvVar5;
    }
    *(void **)this = _Dst;
    *(void **)(this + 8) = _Dst;
    *(void **)(this + 0x10) = (void *)(uVar4 + (longlong)_Dst);
    lVar1 = *(longlong *)(param_1 + 8);
    lVar2 = *(longlong *)param_1;
    memmove(_Dst,*(void **)param_1,lVar1 - lVar2);
    local_res8 = 0;
    *(void **)(this + 8) = (void *)((longlong)_Dst + (lVar1 - lVar2 >> 3) * 8);
    _Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
    ::
    ~_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
              ((_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
                *)&local_res8);
  }
  return this;
}



===== ~_Tidy_guard<std::vector<long,std::allocator<long>_>_> @ 18000bc78 =====

/* public: __cdecl std::_Tidy_guard<class std::vector<long,class std::allocator<long> >
   >::~_Tidy_guard<class std::vector<long,class std::allocator<long> > >(void) __ptr64 */

void __thiscall
std::_Tidy_guard<std::vector<long,std::allocator<long>_>_>::
~_Tidy_guard<std::vector<long,std::allocator<long>_>_>
          (_Tidy_guard<std::vector<long,std::allocator<long>_>_> *this)

{
  longlong *plVar1;
  void *pvVar2;
  code *pcVar3;
  void *pvVar4;
  __uint64 _Var5;
  
  plVar1 = *(longlong **)this;
  if ((plVar1 != (longlong *)0x0) && (pvVar2 = (void *)*plVar1, pvVar2 != (void *)0x0)) {
    _Var5 = plVar1[2] - (longlong)pvVar2 & 0xfffffffffffffffc;
    pvVar4 = pvVar2;
    if (0xfff < _Var5) {
      pvVar4 = *(void **)((longlong)pvVar2 + -8);
      _Var5 = _Var5 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar4))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
    }
    operator_delete(pvVar4,_Var5);
    *plVar1 = 0;
    plVar1[1] = 0;
    plVar1[2] = 0;
  }
  return;
}



===== ~_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_> @ 18000bce8 =====

/* public: __cdecl std::_Tidy_guard<class std::vector<class PktMon::Component const * __ptr64,class
   std::allocator<class PktMon::Component const * __ptr64> > >::~_Tidy_guard<class std::vector<class
   PktMon::Component const * __ptr64,class std::allocator<class PktMon::Component const * __ptr64> >
   >(void) __ptr64 */

void __thiscall
std::
_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
::
~_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
          (_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
           *this)

{
  longlong *plVar1;
  void *pvVar2;
  code *pcVar3;
  void *pvVar4;
  __uint64 _Var5;
  
  plVar1 = *(longlong **)this;
  if ((plVar1 != (longlong *)0x0) && (pvVar2 = (void *)*plVar1, pvVar2 != (void *)0x0)) {
    _Var5 = plVar1[2] - (longlong)pvVar2 & 0xfffffffffffffff8;
    pvVar4 = pvVar2;
    if (0xfff < _Var5) {
      pvVar4 = *(void **)((longlong)pvVar2 + -8);
      _Var5 = _Var5 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar4))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
    }
    operator_delete(pvVar4,_Var5);
    *plVar1 = 0;
    plVar1[1] = 0;
    plVar1[2] = 0;
  }
  return;
}



===== ~_Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_> @ 18000bd58 =====

/* public: __cdecl std::_Tree<class std::_Tmap_traits<unsigned long,class
   PktMon::GatewayGroup,struct std::less<unsigned long>,class std::allocator<struct
   std::pair<unsigned long const ,class PktMon::GatewayGroup> >,0> >::~_Tree<class
   std::_Tmap_traits<unsigned long,class PktMon::GatewayGroup,struct std::less<unsigned long>,class
   std::allocator<struct std::pair<unsigned long const ,class PktMon::GatewayGroup> >,0> >(void)
   __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_>
::
~_Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_>
          (_Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_>
           *this)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(*(longlong *)this + 8);
  while (*(char *)((longlong)puVar2 + 0x19) == '\0') {
    _Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>::
    _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_>
              ((_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
                *)this,(allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>
                        *)this,
               (_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64> *)
               puVar2[2]);
    puVar1 = (undefined8 *)*puVar2;
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(puVar2 + 7));
    operator_delete(puVar2,0x50);
    puVar2 = puVar1;
  }
  operator_delete(*(void **)this,0x50);
  return;
}



===== ~set<long,std::less<long>,std::allocator<long>_> @ 18000bdc8 =====

/* public: __cdecl std::set<long,struct std::less<long>,class std::allocator<long>
   >::~set<long,struct std::less<long>,class std::allocator<long> >(void) __ptr64 */

void __thiscall
std::set<long,std::less<long>,std::allocator<long>_>::
~set<long,std::less<long>,std::allocator<long>_>
          (set<long,std::less<long>,std::allocator<long>_> *this)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(*(longlong *)this + 8);
  while (*(char *)((longlong)puVar2 + 0x19) == '\0') {
    _Tree_val<std::_Tree_simple_types<long>_>::
    _Erase_tree<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
              ((_Tree_val<std::_Tree_simple_types<long>_> *)this,
               (allocator<std::_Tree_node<long,void*___ptr64>_> *)this,
               (_Tree_node<long,void*___ptr64> *)puVar2[2]);
    puVar1 = (undefined8 *)*puVar2;
    operator_delete(puVar2,0x20);
    puVar2 = puVar1;
  }
  operator_delete(*(void **)this,0x20);
  return;
}



===== ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_> @ 18000be20 =====

/* public: __cdecl std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> >::~basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >(void) __ptr64 */

void __thiscall
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
           *this)

{
  longlong lVar1;
  void *pvVar2;
  code *pcVar3;
  void *pvVar4;
  ulonglong uVar5;
  
  if (7 < *(ulonglong *)(this + 0x18)) {
    pvVar2 = *(void **)this;
    lVar1 = *(ulonglong *)(this + 0x18) * 2;
    uVar5 = lVar1 + 2;
    pvVar4 = pvVar2;
    if (0xfff < uVar5) {
      pvVar4 = *(void **)((longlong)pvVar2 + -8);
      uVar5 = lVar1 + 0x29;
      if (0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar4))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
    }
    operator_delete(pvVar4,uVar5);
  }
  *(undefined8 *)(this + 0x18) = 7;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined2 *)this = 0;
  return;
}



===== ~map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_> @ 18000be90 =====

/* public: __cdecl std::map<unsigned long,class PktMon::GatewayGroup,struct std::less<unsigned
   long>,class std::allocator<struct std::pair<unsigned long const ,class PktMon::GatewayGroup> >
   >::~map<unsigned long,class PktMon::GatewayGroup,struct std::less<unsigned long>,class
   std::allocator<struct std::pair<unsigned long const ,class PktMon::GatewayGroup> > >(void)
   __ptr64 */

void __thiscall
std::
map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
::
~map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
          (map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
           *this)

{
  _Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_>
  ::
  ~_Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_>
            ((_Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_>
              *)this);
  return;
}



===== ~map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_> @ 18000be9c =====

/* public: __cdecl std::map<unsigned long,class PktMon::NicGroup,struct std::less<unsigned
   long>,class std::allocator<struct std::pair<unsigned long const ,class PktMon::NicGroup> >
   >::~map<unsigned long,class PktMon::NicGroup,struct std::less<unsigned long>,class
   std::allocator<struct std::pair<unsigned long const ,class PktMon::NicGroup> > >(void) __ptr64 */

void __thiscall
std::
map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
::
~map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
          (map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
           *this)

{
  _Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>::
  _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
            ((_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
              *)this,(allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>
                      *)this,
             *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)
              (*(longlong *)this + 8));
  operator_delete(*(void **)this,0x98);
  return;
}



===== ~map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_> @ 18000becc =====

/* public: __cdecl std::map<unsigned long,class PktMon::VMSwitch,struct std::less<unsigned
   long>,class std::allocator<struct std::pair<unsigned long const ,class PktMon::VMSwitch> >
   >::~map<unsigned long,class PktMon::VMSwitch,struct std::less<unsigned long>,class
   std::allocator<struct std::pair<unsigned long const ,class PktMon::VMSwitch> > >(void) __ptr64 */

void __thiscall
std::
map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
::
~map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
          (map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
           *this)

{
  _Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>::
  _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
            ((_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
              *)this,(allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>
                      *)this,
             *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)
              (*(longlong *)this + 8));
  operator_delete(*(void **)this,0x90);
  return;
}



===== ~vector<PktMon::Component,std::allocator<PktMon::Component>_> @ 18000befc =====

/* public: __cdecl std::vector<class PktMon::Component,class std::allocator<class PktMon::Component>
   >::~vector<class PktMon::Component,class std::allocator<class PktMon::Component> >(void) __ptr64
    */

void __thiscall
std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::
~vector<PktMon::Component,std::allocator<PktMon::Component>_>
          (vector<PktMon::Component,std::allocator<PktMon::Component>_> *this)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = (*(longlong *)(this + 0x10) - (longlong)pvVar1 >> 3) * 8;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== ~CompList @ 18000bf7c =====

/* public: __cdecl PktMon::CompList::~CompList(void) __ptr64 */

void __thiscall PktMon::CompList::~CompList(CompList *this)

{
  _Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_> *this_00;
  _Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_> *this_01;
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(this + 0x70));
  this_00 = (_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
             *)(this + 0x50);
  std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>::
  _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
            (this_00,(allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>
                      *)this_00,
             *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)
              (*(longlong *)this_00 + 8));
  operator_delete(*(void **)this_00,0x98);
  this_01 = (_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
             *)(this + 0x40);
  std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>::
  _Erase_tree<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
            (this_01,(allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>
                      *)this_01,
             *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)
              (*(longlong *)this_01 + 8));
  operator_delete(*(void **)this_01,0x90);
  std::
  _Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_>
  ::
  ~_Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_>
            ((_Tree<std::_Tmap_traits<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>,0>_>
              *)(this + 0x30));
  std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::
  ~vector<PktMon::Component,std::allocator<PktMon::Component>_>
            ((vector<PktMon::Component,std::allocator<PktMon::Component>_> *)(this + 0x18));
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = *(longlong *)(this + 0x10) - (longlong)pvVar1;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== ~DataSourceList @ 18000c04c =====

/* public: __cdecl DataSourceList::~DataSourceList(void) __ptr64 */

void __thiscall DataSourceList::~DataSourceList(DataSourceList *this)

{
  CompList *this_00;
  
  this_00 = *(CompList **)this;
  if (this_00 != (CompList *)0x0) {
    PktMon::CompList::~CompList(this_00);
    operator_delete(this_00,0x88);
  }
  return;
}



===== ~GatewayGroup @ 18000c07c =====

/* public: __cdecl PktMon::GatewayGroup::~GatewayGroup(void) __ptr64 */

void __thiscall PktMon::GatewayGroup::~GatewayGroup(GatewayGroup *this)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(this + 0x10));
  return;
}



===== AddComponentAsDataSource @ 18000c08c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
AddComponentAsDataSource
          (allocator<PktMon::Component_const*___ptr64> *param_1,Component *param_2,char param_3,
          undefined4 param_4)

{
  int iVar1;
  Component *this;
  vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
  *pvVar2;
  wchar_t *_Source;
  wchar_t ***_Source_00;
  undefined4 uVar3;
  __uint64 _Var4;
  undefined8 *puVar5;
  bool bVar6;
  undefined1 auStack_2b8 [32];
  undefined4 local_298;
  undefined4 local_294;
  __uint64 local_290;
  Component **local_288;
  Component **ppCStack_280;
  Component **local_278;
  Component *local_270;
  undefined8 *local_268;
  undefined8 *local_260;
  vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
  local_248 [24];
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
  local_230 [24];
  wchar_t ***local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  ulonglong local_200;
  undefined4 local_1f8;
  wchar_t local_1f4 [64];
  wchar_t local_174 [128];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_2b8;
  uVar3 = 0;
  local_298 = 0;
  local_288 = (Component **)0x0;
  ppCStack_280 = (Component **)0x0;
  local_278 = (Component **)0x0;
  local_290 = 1;
  local_294 = param_4;
  local_270 = param_2;
  local_288 = std::_Allocate_at_least_helper<std::allocator<PktMon::Component_const*___ptr64>_>
                        (param_1,&local_290);
  ppCStack_280 = local_288 + 1;
  *local_288 = param_2;
  local_290 = 0;
  local_278 = ppCStack_280;
  std::
  _Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
  ::
  ~_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
            ((_Tidy_guard<std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>_>
              *)&local_290);
  if (param_2 != (Component *)0x0) {
    if (param_3 == '\0') {
      pvVar2 = (vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                *)std::
                  vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                  ::
                  vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                            (local_248,
                             (vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                              *)&local_288);
      local_298 = 2;
    }
    else {
      pvVar2 = (vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                *)PktMon::Component::GetRelated(param_2);
      local_298 = 1;
    }
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
              ((vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                *)&local_268,pvVar2);
    if (param_3 == '\0') {
      std::
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)local_248);
    }
    else {
      std::
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                (local_230);
    }
    uVar3 = local_294;
    puVar5 = local_268;
    if (local_268 != local_260) {
      do {
        this = (Component *)*puVar5;
        memset(&local_1f8,0,0x1a8);
        local_218 = (wchar_t ***)0x0;
        uStack_210 = 0;
        local_208 = 0;
        local_200 = 0;
        _Var4 = 0xffffffffffffffff;
        do {
          _Var4 = _Var4 + 1;
        } while ((*(ushort **)this)[_Var4] != 0);
        std::
        basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
        ::_Construct<1,unsigned_short_const*___ptr64>
                  ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                    *)&local_218,*(ushort **)this,_Var4);
        _Source_00 = (wchar_t ***)&local_218;
        if (7 < local_200) {
          _Source_00 = local_218;
        }
        wcsncpy(local_1f4,(wchar_t *)_Source_00,0x40);
        std::
        basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
        ::
        ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                    *)&local_218);
        _Source = (wchar_t *)PktMon::Component::GetDescription(this,SUB81(&local_218,0));
        if (7 < *(ulonglong *)(_Source + 0xc)) {
          _Source = *(wchar_t **)_Source;
        }
        wcsncpy(local_174,_Source,0x80);
        std::
        basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
        ::
        ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                    *)&local_218);
        iVar1 = *(int *)(*(longlong *)this + 0x180);
        local_1f8 = 6;
        if (iVar1 < 8) {
          if (((iVar1 == 7) || (iVar1 == 1)) || (iVar1 == 2)) goto LAB_18000c2ac;
          if (iVar1 == 3) {
            local_1f8 = 2;
          }
          else {
            if (iVar1 != 4) {
              if (iVar1 != 5) {
                bVar6 = iVar1 == 6;
                goto LAB_18000c2aa;
              }
              goto LAB_18000c2ac;
            }
LAB_18000c352:
            local_1f8 = 3;
          }
        }
        else {
          if ((iVar1 != 8) && (iVar1 != 9)) {
            if (iVar1 == 10) {
              local_1f8 = 4;
            }
            else {
              if (iVar1 == 0xb) goto LAB_18000c352;
              bVar6 = iVar1 == 0xe;
LAB_18000c2aa:
              if (bVar6) goto LAB_18000c2ac;
            }
            goto LAB_18000c2b1;
          }
LAB_18000c2ac:
          local_1f8 = 1;
        }
LAB_18000c2b1:
        local_74 = *(undefined4 *)(**(longlong **)(this + 8) + 0x184);
        local_70 = *(undefined4 *)(*(longlong *)this + 0x184);
        local_6c = uVar3;
        CopyComponentPropertiesToDataSource((longlong)&local_1f8,this);
        std::
        vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
        ::push_back((vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
                     *)param_1,(PACKETMONITOR_DATA_SOURCE_SPECIFICATION *)&local_1f8);
        puVar5 = puVar5 + 1;
      } while (puVar5 != local_260);
      param_2 = local_270;
    }
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_268);
    uVar3 = *(undefined4 *)(**(longlong **)(param_2 + 8) + 0x184);
  }
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_288);
  return uVar3;
}



===== AddMiniportsAsDataSources @ 18000c370 =====

void AddMiniportsAsDataSources
               (allocator<PktMon::Component_const*___ptr64> *param_1,undefined8 *param_2,
               char param_3,undefined4 param_4)

{
  undefined8 *puVar1;
  NicGroup *this;
  bool bVar2;
  undefined8 *puVar3;
  Component *pCVar4;
  
  puVar1 = (undefined8 *)param_2[1];
  puVar3 = (undefined8 *)*param_2;
  do {
    if (puVar3 == puVar1) {
      return;
    }
    this = (NicGroup *)*puVar3;
    pCVar4 = *(Component **)(this + 0x10);
    if ((pCVar4 != (Component *)0x0) ||
       (pCVar4 = *(Component **)(this + 0x18), pCVar4 != (Component *)0x0)) {
      if (param_3 == '\0') {
        bVar2 = PktMon::NicGroup::IsHidden(this);
        if (bVar2) goto LAB_18000c3ce;
      }
      AddComponentAsDataSource(param_1,pCVar4,param_3,param_4);
    }
LAB_18000c3ce:
    puVar3 = puVar3 + 1;
  } while( true );
}



===== AddNicGroupAsDataSources @ 18000c3f8 =====

void AddNicGroupAsDataSources
               (allocator<PktMon::Component_const*___ptr64> *param_1,NicGroup *param_2,char param_3,
               undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  Component *pCVar3;
  Component *pCVar4;
  undefined8 *local_78;
  undefined8 *local_70;
  undefined8 *local_60;
  undefined8 *local_58;
  undefined8 *local_48;
  undefined8 *local_40;
  
  if ((param_2 != (NicGroup *)0x0) &&
     ((pCVar4 = (Component *)0x0, param_3 != '\0' ||
      (bVar1 = PktMon::NicGroup::IsHidden(param_2), !bVar1)))) {
    pCVar3 = *(Component **)(param_2 + 0x10);
    if (pCVar3 == (Component *)0x0) {
      pCVar3 = *(Component **)(param_2 + 0x18);
    }
    uVar2 = AddComponentAsDataSource(param_1,pCVar3,param_3,param_4);
    if (*(longlong *)(param_2 + 0x10) != 0) {
      pCVar4 = *(Component **)(param_2 + 0x18);
    }
    AddComponentAsDataSource(param_1,pCVar4,param_3,uVar2);
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
              ((vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                *)&local_48,
               (vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                *)(param_2 + 0x20));
    for (; local_48 != local_40; local_48 = local_48 + 1) {
      AddComponentAsDataSource(param_1,(Component *)*local_48,param_3,uVar2);
    }
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
              ((vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                *)&local_60,
               (vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                *)(param_2 + 0x38));
    for (; local_60 != local_58; local_60 = local_60 + 1) {
      AddComponentAsDataSource(param_1,(Component *)*local_60,param_3,uVar2);
    }
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
              ((vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                *)&local_78,
               (vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                *)(param_2 + 0x50));
    for (; local_78 != local_70; local_78 = local_78 + 1) {
      AddComponentAsDataSource(param_1,(Component *)*local_78,param_3,uVar2);
    }
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_78);
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_60);
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_48);
  }
  return;
}



===== AddVmSwitchAsDataSource @ 18000c54c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
AddVmSwitchAsDataSource
          (vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
           *param_1,VMSwitch *param_2)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *_Source;
  Component *pCVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined1 auStack_218 [32];
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  local_1f8 [32];
  undefined4 local_1d8;
  wchar_t local_1d4 [192];
  undefined4 local_54;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_218;
  lVar1 = *(longlong *)(param_2 + 0x30);
  uVar4 = 0;
  if (lVar1 != 0) {
    lVar5 = *(longlong *)(lVar1 + 0x10);
    lVar2 = lVar5;
    if (lVar5 == 0) {
      lVar2 = *(longlong *)(lVar1 + 0x18);
    }
    if (lVar2 != 0) {
      memset(&local_1d8,0,0x1a8);
      if (lVar5 == 0) {
        lVar5 = *(longlong *)(lVar1 + 0x18);
      }
      uVar4 = *(undefined4 *)(**(longlong **)(lVar5 + 8) + 0x184);
      _Source = (wchar_t *)PktMon::VMSwitch::GetName(param_2);
      if (7 < *(ulonglong *)(_Source + 0xc)) {
        _Source = *(wchar_t **)_Source;
      }
      wcsncpy(local_1d4,_Source,0x40);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                (local_1f8);
      pCVar3 = *(Component **)(lVar1 + 0x10);
      local_1d8 = 5;
      if (pCVar3 == (Component *)0x0) {
        pCVar3 = *(Component **)(lVar1 + 0x18);
      }
      local_54 = uVar4;
      CopyComponentPropertiesToDataSource((longlong)&local_1d8,pCVar3);
      std::
      vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
      ::push_back(param_1,(PACKETMONITOR_DATA_SOURCE_SPECIFICATION *)&local_1d8);
    }
  }
  return uVar4;
}



===== CopyComponentPropertiesToDataSource @ 18000c668 =====

void CopyComponentPropertiesToDataSource(longlong param_1,Component *param_2)

{
  undefined8 *_Dst;
  undefined8 uVar1;
  undefined8 uVar2;
  _PKTMON_PROPERTY_OUT *p_Var3;
  uint uVar4;
  
  p_Var3 = PktMon::Component::FindProperty(param_2,4);
  _Dst = (undefined8 *)(param_1 + 0x198);
  if (p_Var3 != (_PKTMON_PROPERTY_OUT *)0x0) {
    uVar1 = *(undefined8 *)(p_Var3 + 6);
    uVar2 = *(undefined8 *)(p_Var3 + 0xe);
    *(uint *)(param_1 + 400) = *(uint *)(param_1 + 400) | 1;
    *_Dst = uVar1;
    *(undefined8 *)(param_1 + 0x1a0) = uVar2;
  }
  p_Var3 = PktMon::Component::FindProperty(param_2,0xd);
  if (p_Var3 != (_PKTMON_PROPERTY_OUT *)0x0) {
    memcpy(_Dst,p_Var3 + 6,(ulonglong)*(ushort *)(p_Var3 + 4));
    if (*(short *)(p_Var3 + 4) == 0x10) {
      uVar4 = *(uint *)(param_1 + 400) | 2;
    }
    else {
      uVar4 = *(uint *)(param_1 + 400) | 4;
    }
    *(uint *)(param_1 + 400) = uVar4;
  }
  p_Var3 = PktMon::Component::FindProperty(param_2,6);
  if ((p_Var3 != (_PKTMON_PROPERTY_OUT *)0x0) && (*(short *)(p_Var3 + 4) == 6)) {
    *(undefined4 *)_Dst = *(undefined4 *)(p_Var3 + 6);
    *(undefined2 *)(param_1 + 0x19c) = *(undefined2 *)(p_Var3 + 10);
    *(uint *)(param_1 + 400) = *(uint *)(param_1 + 400) | 8;
  }
  return;
}



===== GetAllDataSources @ 18000c738 =====

/* public: class std::vector<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class
   std::allocator<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION> > __cdecl
   DataSourceList::GetAllDataSources(bool) __ptr64 */

vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
* __thiscall DataSourceList::GetAllDataSources(DataSourceList *this,bool param_1)

{
  VMSwitch *pVVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  undefined7 in_register_00000011;
  vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
  *pvVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  char in_R8B;
  longlong *plVar8;
  undefined8 *local_88;
  undefined8 *local_80;
  undefined8 *local_70;
  undefined8 *local_68;
  longlong *local_58;
  longlong *local_50;
  undefined8 *local_40;
  
  pvVar5 = (vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
            *)CONCAT71(in_register_00000011,param_1);
  *(undefined8 *)pvVar5 = 0;
  *(undefined8 *)(pvVar5 + 8) = 0;
  *(undefined8 *)(pvVar5 + 0x10) = 0;
  PktMon::CompList::GetVMSwitches(*(CompList **)this);
  local_40 = local_80;
  puVar4 = local_80;
  puVar6 = local_88;
  if (local_88 != local_80) {
    do {
      pVVar1 = (VMSwitch *)*puVar6;
      if (pVVar1 != (VMSwitch *)0x0) {
        uVar3 = AddVmSwitchAsDataSource(pvVar5,pVVar1);
        std::
        vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>::
        vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
                  ((vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
                    *)&local_70,
                   (vector<class_PktMon::NicGroup_const*___ptr64,class_std::allocator<class_PktMon::NicGroup_const*___ptr64>_>
                    *)(pVVar1 + 0x10));
        puVar2 = local_68;
        for (puVar4 = local_70; puVar4 != puVar2; puVar4 = puVar4 + 1) {
          AddNicGroupAsDataSources
                    ((allocator<PktMon::Component_const*___ptr64> *)pvVar5,(NicGroup *)*puVar4,
                     in_R8B,uVar3);
        }
        std::
        vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
        ::
        ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                    *)&local_70);
        AddNicGroupAsDataSources
                  ((allocator<PktMon::Component_const*___ptr64> *)pvVar5,
                   *(NicGroup **)(pVVar1 + 0x30),in_R8B,uVar3);
        std::
        vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>::
        vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
                  ((vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
                    *)&local_70,
                   (vector<class_PktMon::NicGroup_const*___ptr64,class_std::allocator<class_PktMon::NicGroup_const*___ptr64>_>
                    *)(pVVar1 + 0x38));
        puVar2 = local_68;
        for (puVar4 = local_70; puVar4 != puVar2; puVar4 = puVar4 + 1) {
          AddNicGroupAsDataSources
                    ((allocator<PktMon::Component_const*___ptr64> *)pvVar5,(NicGroup *)*puVar4,
                     in_R8B,uVar3);
        }
        std::
        vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
        ::
        ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                    *)&local_70);
        std::
        vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
        vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                  ((vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                    *)&local_58,
                   (vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                    *)(pVVar1 + 0x50));
        plVar7 = local_50;
        for (plVar8 = local_58; plVar8 != plVar7; plVar8 = plVar8 + 1) {
          AddComponentAsDataSource
                    ((allocator<PktMon::Component_const*___ptr64> *)pvVar5,(Component *)*plVar8,
                     in_R8B,uVar3);
        }
        std::
        vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
        ::
        ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                    *)&local_58);
        puVar4 = local_40;
      }
      puVar6 = puVar6 + 1;
    } while (puVar6 != puVar4);
  }
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_88);
  PktMon::CompList::GetNics(*(CompList **)this);
  puVar4 = local_80;
  for (puVar6 = local_88; puVar6 != puVar4; puVar6 = puVar6 + 1) {
    AddNicGroupAsDataSources
              ((allocator<PktMon::Component_const*___ptr64> *)pvVar5,(NicGroup *)*puVar6,in_R8B,0);
  }
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_88);
  PktMon::CompList::GetGateways(*(CompList **)this);
  for (plVar7 = local_58; plVar7 != local_50; plVar7 = plVar7 + 1) {
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
              ((vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                *)&local_88,
               (vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                *)(*plVar7 + 0x10));
    puVar4 = local_80;
    for (puVar6 = local_88; puVar6 != puVar4; puVar6 = puVar6 + 1) {
      AddComponentAsDataSource
                ((allocator<PktMon::Component_const*___ptr64> *)pvVar5,(Component *)*puVar6,in_R8B,0
                );
    }
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_88);
  }
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_58);
  return pvVar5;
}



===== GetComponents @ 18000c990 =====

/* public: virtual class std::vector<class PktMon::Component const * __ptr64,class
   std::allocator<class PktMon::Component const * __ptr64> > __cdecl
   PktMon::GatewayGroup::GetComponents(void)const __ptr64 */

void __thiscall PktMon::GatewayGroup::GetComponents(GatewayGroup *this)

{
  vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_> *in_RDX
  ;
  
  std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
  vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
            (in_RDX,(vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                     *)(this + 0x10));
  return;
}



===== GetNetworkAdapters @ 18000c9b8 =====

/* public: class std::vector<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class
   std::allocator<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION> > __cdecl
   DataSourceList::GetNetworkAdapters(bool) __ptr64 */

allocator<PktMon::Component_const*___ptr64> * __thiscall
DataSourceList::GetNetworkAdapters(DataSourceList *this,bool param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined7 in_register_00000011;
  allocator<PktMon::Component_const*___ptr64> *paVar6;
  longlong *plVar7;
  char in_R8B;
  undefined4 uVar8;
  undefined8 *local_68;
  undefined8 *local_60;
  longlong *local_50;
  longlong *local_48;
  
  paVar6 = (allocator<PktMon::Component_const*___ptr64> *)CONCAT71(in_register_00000011,param_1);
  *(undefined8 *)paVar6 = 0;
  *(undefined8 *)(paVar6 + 8) = 0;
  *(undefined8 *)(paVar6 + 0x10) = 0;
  PktMon::CompList::GetVMSwitches(*(CompList **)this);
  plVar7 = local_50;
  do {
    uVar8 = 0;
    if (plVar7 == local_48) {
      std::
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)&local_50);
      puVar4 = (undefined8 *)PktMon::CompList::GetNics(*(CompList **)this);
      AddMiniportsAsDataSources(paVar6,puVar4,in_R8B,0);
      std::
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)&local_50);
      return paVar6;
    }
    lVar1 = *plVar7;
    lVar2 = *(longlong *)(lVar1 + 0x30);
    if (lVar2 != 0) {
      lVar5 = *(longlong *)(lVar2 + 0x10);
      if (lVar5 == 0) {
        if (*(longlong *)(lVar2 + 0x18) == 0) goto LAB_18000ca44;
        lVar5 = *(longlong *)(lVar2 + 0x18);
      }
      uVar8 = *(undefined4 *)(**(longlong **)(lVar5 + 8) + 0x184);
    }
LAB_18000ca44:
    std::vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>::
    vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
              ((vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
                *)&local_68,
               (vector<class_PktMon::NicGroup_const*___ptr64,class_std::allocator<class_PktMon::NicGroup_const*___ptr64>_>
                *)(lVar1 + 0x10));
    AddMiniportsAsDataSources(paVar6,&local_68,in_R8B,uVar8);
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_68);
    std::vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>::
    vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
              ((vector<PktMon::NicGroup_const*___ptr64,std::allocator<PktMon::NicGroup_const*___ptr64>_>
                *)&local_68,
               (vector<class_PktMon::NicGroup_const*___ptr64,class_std::allocator<class_PktMon::NicGroup_const*___ptr64>_>
                *)(lVar1 + 0x38));
    AddMiniportsAsDataSources(paVar6,&local_68,in_R8B,uVar8);
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_68);
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
              ((vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
                *)&local_68,
               (vector<class_PktMon::Component_const*___ptr64,class_std::allocator<class_PktMon::Component_const*___ptr64>_>
                *)(lVar1 + 0x50));
    puVar3 = local_60;
    for (puVar4 = local_68; puVar4 != puVar3; puVar4 = puVar4 + 1) {
      AddComponentAsDataSource(paVar6,(Component *)*puVar4,in_R8B,uVar8);
    }
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_68);
    plVar7 = plVar7 + 1;
  } while( true );
}



===== IsHidden @ 18000cb60 =====

/* public: virtual bool __cdecl PktMon::GatewayGroup::IsHidden(void)const __ptr64 */

bool __thiscall PktMon::GatewayGroup::IsHidden(GatewayGroup *this)

{
  return false;
}



===== NormalizeAndValidateSelection @ 18000cb6c =====

/* public: class std::vector<int,class std::allocator<int> > __cdecl
   DataSourceList::NormalizeAndValidateSelection(class std::vector<unsigned short,class
   std::allocator<unsigned short> > const & __ptr64) __ptr64 */

vector<unsigned_short,std::allocator<unsigned_short>_> * __thiscall
DataSourceList::NormalizeAndValidateSelection
          (DataSourceList *this,vector<unsigned_short,std::allocator<unsigned_short>_> *param_1)

{
  char cVar1;
  ushort *puVar2;
  int *piVar3;
  longlong *plVar4;
  code *pcVar5;
  void *pvVar6;
  vector<unsigned_short,std::allocator<unsigned_short>_> *pvVar7;
  longlong *plVar8;
  longlong *plVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 *in_R8;
  ushort *puVar12;
  int local_res18 [2];
  undefined8 *local_50 [2];
  uint *local_40;
  uint *puStack_38;
  uint *local_30;
  
  puVar2 = (ushort *)in_R8[1];
  puVar12 = (ushort *)*in_R8;
  local_40 = (uint *)0x0;
  puStack_38 = (uint *)0x0;
  local_30 = (uint *)0x0;
  uVar10 = (longlong)puVar2 - (longlong)puVar12 >> 1;
  if (uVar10 != 0) {
    if (0x3fffffffffffffff < uVar10) {
                    /* WARNING: Subroutine does not return */
      std::
      vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
      ::_Xlength();
    }
    uVar11 = uVar10 * 4;
    if (uVar11 < 0x1000) {
      if (uVar11 == 0) {
        local_40 = (uint *)0x0;
      }
      else {
        local_40 = operator_new(uVar11);
      }
    }
    else {
      if (uVar11 + 0x27 <= uVar11) {
                    /* WARNING: Subroutine does not return */
        std::_Throw_bad_array_new_length();
      }
      pvVar6 = operator_new(uVar11 + 0x27);
      if (pvVar6 == (void *)0x0) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar5 = (code *)swi(3);
        pvVar7 = (vector<unsigned_short,std::allocator<unsigned_short>_> *)(*pcVar5)();
        return pvVar7;
      }
      local_40 = (uint *)((longlong)pvVar6 + 0x27U & 0xffffffffffffffe0);
      *(void **)(local_40 + -2) = pvVar6;
    }
    local_30 = local_40 + uVar10;
    puStack_38 = local_40;
    for (; puVar12 != puVar2; puVar12 = puVar12 + 1) {
      *puStack_38 = (uint)*puVar12;
      puStack_38 = puStack_38 + 1;
    }
    local_res18[0] = 0;
    local_res18[1] = 0;
    std::_Tidy_guard<std::vector<long,std::allocator<long>_>_>::
    ~_Tidy_guard<std::vector<long,std::allocator<long>_>_>
              ((_Tidy_guard<std::vector<long,std::allocator<long>_>_> *)local_res18);
  }
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  PktMon::CompList::NormalizeAndValidateSelection
            (*(CompList **)this,(vector<long,std::allocator<long>_> *)local_50);
  plVar8 = (longlong *)*local_50[0];
  while (*(char *)((longlong)plVar8 + 0x19) == '\0') {
    local_res18[0] = *(int *)((longlong)plVar8 + 0x1c);
    piVar3 = *(int **)(param_1 + 8);
    if (piVar3 == *(int **)(param_1 + 0x10)) {
      std::vector<int,std::allocator<int>_>::_Emplace_reallocate<int>
                ((vector<int,std::allocator<int>_> *)param_1,piVar3,local_res18);
    }
    else {
      *piVar3 = *(int *)((longlong)plVar8 + 0x1c);
      *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 4;
    }
    plVar4 = (longlong *)plVar8[2];
    if (*(char *)((longlong)plVar4 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar4 + 0x19);
      plVar8 = plVar4;
      plVar4 = (longlong *)*plVar4;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar4 + 0x19);
        plVar8 = plVar4;
        plVar4 = (longlong *)*plVar4;
      }
    }
    else {
      plVar4 = (longlong *)plVar8[1];
      plVar9 = plVar8;
      while ((plVar8 = plVar4, *(char *)((longlong)plVar8 + 0x19) == '\0' &&
             (plVar9 == (longlong *)plVar8[2]))) {
        plVar4 = (longlong *)plVar8[1];
        plVar9 = plVar8;
      }
    }
  }
  plVar8 = (longlong *)local_50[0][1];
  if (*(char *)((longlong)local_50[0][1] + 0x19) == '\0') {
    do {
      std::_Tree_val<std::_Tree_simple_types<long>_>::
      _Erase_tree<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
                ((_Tree_val<std::_Tree_simple_types<long>_> *)local_50,
                 (allocator<std::_Tree_node<long,void*___ptr64>_> *)local_50,
                 (_Tree_node<long,void*___ptr64> *)plVar8[2]);
      plVar4 = (longlong *)*plVar8;
      operator_delete(plVar8,0x20);
      plVar8 = plVar4;
    } while (*(char *)((longlong)plVar4 + 0x19) == '\0');
  }
  operator_delete(local_50[0],0x20);
  std::vector<int,std::allocator<int>_>::~vector<int,std::allocator<int>_>
            ((vector<int,std::allocator<int>_> *)&local_40);
  return param_1;
}



===== _Xlen_string @ 18000cd70 =====

/* void __cdecl std::_Xlen_string(void) */

void __cdecl std::_Xlen_string(void)

{
  code *pcVar1;
  
  std::_Xlength_error("string too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== deallocate @ 18000cd90 =====

/* public: void __cdecl std::allocator<class PktMon::Component>::deallocate(class PktMon::Component
   * __ptr64 const,unsigned __int64) __ptr64 */

void __thiscall
std::allocator<PktMon::Component>::deallocate
          (allocator<PktMon::Component> *this,Component *param_1,__uint64 param_2)

{
  code *pcVar1;
  Component *pCVar2;
  __uint64 _Var3;
  
  _Var3 = param_2 * 0x18;
  pCVar2 = param_1;
  if (0xfff < _Var3) {
    pCVar2 = *(Component **)(param_1 + -8);
    _Var3 = _Var3 + 0x27;
    if ((Component *)0x1f < param_1 + (-8 - (longlong)pCVar2)) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  operator_delete(pCVar2,_Var3);
  return;
}



===== push_back @ 18000cde0 =====

/* public: void __cdecl std::vector<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION,class
   std::allocator<struct PACKETMONITOR_DATA_SOURCE_SPECIFICATION> >::push_back(struct
   PACKETMONITOR_DATA_SOURCE_SPECIFICATION const & __ptr64) __ptr64 */

void __thiscall
std::
vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
::push_back(vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
            *this,PACKETMONITOR_DATA_SOURCE_SPECIFICATION *param_1)

{
  PACKETMONITOR_DATA_SOURCE_SPECIFICATION *pPVar1;
  undefined8 uVar2;
  longlong lVar3;
  PACKETMONITOR_DATA_SOURCE_SPECIFICATION *pPVar4;
  PACKETMONITOR_DATA_SOURCE_SPECIFICATION *pPVar5;
  
  pPVar1 = *(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)(this + 8);
  if (pPVar1 == *(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)(this + 0x10)) {
    _Emplace_reallocate<PACKETMONITOR_DATA_SOURCE_SPECIFICATION_const&___ptr64>(this,pPVar1,param_1)
    ;
    return;
  }
  lVar3 = 3;
  do {
    pPVar5 = param_1;
    pPVar4 = pPVar1;
    uVar2 = *(undefined8 *)(pPVar5 + 8);
    *(undefined8 *)pPVar4 = *(undefined8 *)pPVar5;
    *(undefined8 *)(pPVar4 + 8) = uVar2;
    uVar2 = *(undefined8 *)(pPVar5 + 0x18);
    *(undefined8 *)(pPVar4 + 0x10) = *(undefined8 *)(pPVar5 + 0x10);
    *(undefined8 *)(pPVar4 + 0x18) = uVar2;
    uVar2 = *(undefined8 *)(pPVar5 + 0x28);
    *(undefined8 *)(pPVar4 + 0x20) = *(undefined8 *)(pPVar5 + 0x20);
    *(undefined8 *)(pPVar4 + 0x28) = uVar2;
    uVar2 = *(undefined8 *)(pPVar5 + 0x38);
    *(undefined8 *)(pPVar4 + 0x30) = *(undefined8 *)(pPVar5 + 0x30);
    *(undefined8 *)(pPVar4 + 0x38) = uVar2;
    uVar2 = *(undefined8 *)(pPVar5 + 0x48);
    *(undefined8 *)(pPVar4 + 0x40) = *(undefined8 *)(pPVar5 + 0x40);
    *(undefined8 *)(pPVar4 + 0x48) = uVar2;
    uVar2 = *(undefined8 *)(pPVar5 + 0x58);
    *(undefined8 *)(pPVar4 + 0x50) = *(undefined8 *)(pPVar5 + 0x50);
    *(undefined8 *)(pPVar4 + 0x58) = uVar2;
    uVar2 = *(undefined8 *)(pPVar5 + 0x68);
    *(undefined8 *)(pPVar4 + 0x60) = *(undefined8 *)(pPVar5 + 0x60);
    *(undefined8 *)(pPVar4 + 0x68) = uVar2;
    uVar2 = *(undefined8 *)(pPVar5 + 0x78);
    *(undefined8 *)(pPVar4 + 0x70) = *(undefined8 *)(pPVar5 + 0x70);
    *(undefined8 *)(pPVar4 + 0x78) = uVar2;
    lVar3 = lVar3 + -1;
    pPVar1 = pPVar4 + 0x80;
    param_1 = pPVar5 + 0x80;
  } while (lVar3 != 0);
  uVar2 = *(undefined8 *)(pPVar5 + 0x88);
  *(undefined8 *)(pPVar4 + 0x80) = *(undefined8 *)(pPVar5 + 0x80);
  *(undefined8 *)(pPVar4 + 0x88) = uVar2;
  uVar2 = *(undefined8 *)(pPVar5 + 0x98);
  *(undefined8 *)(pPVar4 + 0x90) = *(undefined8 *)(pPVar5 + 0x90);
  *(undefined8 *)(pPVar4 + 0x98) = uVar2;
  *(undefined8 *)(pPVar4 + 0xa0) = *(undefined8 *)(pPVar5 + 0xa0);
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 0x1a8;
  return;
}



===== <lambda_invoker_cdecl> @ 18000ce80 =====

/* private: static __cdecl <lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>(void *
   __ptr64) */

void __cdecl <lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>(void *param_1)

{
  if (*(char *)param_1 != '\0') {
    wil::details_abi::SubscriptionList::OnSignaled
              ((SubscriptionList *)((longlong)param_1 + 0x98),(srwlock *)((longlong)param_1 + 0x20))
    ;
  }
  return;
}



===== <lambda_invoker_cdecl> @ 18000ceb0 =====

/* private: static __cdecl <lambda_1ad7ecfab602a777ecf020873216a663>::<lambda_invoker_cdecl>(void *
   __ptr64) */

void __cdecl <lambda_1ad7ecfab602a777ecf020873216a663>::<lambda_invoker_cdecl>(void *param_1)

{
  if (*(char *)param_1 != '\0') {
    wil::details_abi::SubscriptionList::OnSignaled
              ((SubscriptionList *)((longlong)param_1 + 0x48),(srwlock *)((longlong)param_1 + 0x20))
    ;
  }
  return;
}



===== <lambda_invoker_cdecl> @ 18000cee0 =====

/* private: static __cdecl <lambda_5035b992506f4af81a770c5842624510>::<lambda_invoker_cdecl>(struct
   _TP_CALLBACK_INSTANCE * __ptr64,void * __ptr64,struct _TP_TIMER * __ptr64) */

void __cdecl
<lambda_5035b992506f4af81a770c5842624510>::<lambda_invoker_cdecl>
          (_TP_CALLBACK_INSTANCE *param_1,void *param_2,_TP_TIMER *param_3)

{
  PSRWLOCK SRWLock;
  heap_vector<wil_details_FeatureUsageSRUM> *phVar1;
  
  if (*(char *)param_2 != '\0') {
    SRWLock = (PSRWLOCK)((longlong)param_2 + 0x28);
    AcquireSRWLockExclusive(SRWLock);
    phVar1 = (heap_vector<wil_details_FeatureUsageSRUM> *)((longlong)param_2 + 0xe8);
    if (0xb < (ulonglong)(*(longlong *)((longlong)param_2 + 0xf0) - *(longlong *)phVar1)) {
      wil_details_WriteSRUMWnfUsageBuffer(phVar1);
      *(undefined8 *)((longlong)param_2 + 0xf0) = *(undefined8 *)phVar1;
    }
    *(undefined1 *)((longlong)param_2 + 0x40) = 0;
    if (SRWLock != (PSRWLOCK)0x0) {
      ReleaseSRWLockExclusive(SRWLock);
    }
  }
  return;
}



===== <lambda_invoker_cdecl> @ 18000cf60 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: static __cdecl <lambda_d51448ba32f8ef42e59400edd4566183>::<lambda_invoker_cdecl>(struct
   _TP_CALLBACK_INSTANCE * __ptr64,void * __ptr64,struct _TP_TIMER * __ptr64) */

void __cdecl
<lambda_d51448ba32f8ef42e59400edd4566183>::<lambda_invoker_cdecl>
          (_TP_CALLBACK_INSTANCE *param_1,void *param_2,_TP_TIMER *param_3)

{
  PSRWLOCK SRWLock;
  uchar uVar1;
  bool bVar2;
  
  if (*(char *)param_2 != '\0') {
    SRWLock = (PSRWLOCK)((longlong)param_2 + 0x20);
    AcquireSRWLockExclusive(SRWLock);
    *(undefined1 *)((longlong)param_2 + 0x41) = 0;
    if (SRWLock != (PSRWLOCK)0x0) {
      ReleaseSRWLockExclusive(SRWLock);
    }
    if (wil::details::g_processShutdownInProgress == false) {
      if ((wil::details::g_pfnDllShutdownInProgress != (_func_uchar *)0x0) &&
         (uVar1 = (*wil::details::g_pfnDllShutdownInProgress)(), uVar1 != '\0')) {
        return;
      }
      bVar2 = wil::details::FeatureStateManager::EnsureStateData(param_2);
      if (bVar2) {
        wil::details_abi::SubscriptionList::OnSignaled
                  ((SubscriptionList *)(*(srwlock **)((longlong)param_2 + 0x18) + 200),
                   *(srwlock **)((longlong)param_2 + 0x18));
        wil::details_abi::FeatureStateData::RecordUsage
                  (*(FeatureStateData **)((longlong)param_2 + 0x18));
      }
    }
  }
  return;
}



===== _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_><std::piecewise_construct_t_const&___ptr64,std::tuple<unsigned_long_const&___ptr64>,std::tuple<unsigned_long&___ptr64>_> @ 18000cff4 =====

/* public: __cdecl std::_Tree_temp_node<class std::allocator<struct std::_Tree_node<struct
   std::pair<unsigned long const ,class PktMon::NicGroup>,void * __ptr64> > >::_Tree_temp_node<class
   std::allocator<struct std::_Tree_node<struct std::pair<unsigned long const ,class
   PktMon::NicGroup>,void * __ptr64> > ><struct std::piecewise_construct_t const & __ptr64,class
   std::tuple<unsigned long const & __ptr64>,class std::tuple<unsigned long & __ptr64> >(class
   std::allocator<struct std::_Tree_node<struct std::pair<unsigned long const ,class
   PktMon::NicGroup>,void * __ptr64> > & __ptr64,struct std::_Tree_node<struct std::pair<unsigned
   long const ,class PktMon::NicGroup>,void * __ptr64> * __ptr64,struct std::piecewise_construct_t
   const & __ptr64,class std::tuple<unsigned long const & __ptr64> && __ptr64,class
   std::tuple<unsigned long & __ptr64> && __ptr64) __ptr64 */

_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
* __thiscall
std::
_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
::
_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_><std::piecewise_construct_t_const&___ptr64,std::tuple<unsigned_long_const&___ptr64>,std::tuple<unsigned_long&___ptr64>_>
          (_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
           *this,allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>
                 *param_1,
          _Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *param_2,
          piecewise_construct_t *param_3,tuple<unsigned_long_const&___ptr64> *param_4,
          tuple<unsigned_long&___ptr64> *param_5)

{
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *this_00;
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *this_01;
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *this_02;
  undefined4 *puVar1;
  void *pvVar2;
  longlong lVar3;
  piecewise_construct_t *local_res20;
  
  *(allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_> **)
   this = param_1;
  *(undefined8 *)(this + 8) = 0;
  local_res20 = param_3;
  pvVar2 = operator_new(0x98);
  *(void **)(this + 8) = pvVar2;
  puVar1 = *(undefined4 **)param_5;
  *(undefined4 *)((longlong)pvVar2 + 0x20) = **(undefined4 **)param_4;
  *(undefined4 *)((longlong)pvVar2 + 0x30) = *puVar1;
  *(undefined1 *)((longlong)pvVar2 + 0x34) = 0;
  *(undefined ***)((longlong)pvVar2 + 0x28) = &PktMon::NicGroup::_vftable_;
  *(undefined8 *)((longlong)pvVar2 + 0x38) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x40) = 0;
  this_00 = (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
            ((longlong)pvVar2 + 0x48);
  *(undefined8 *)this_00 = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x50) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x58) = 0;
  this_01 = (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
            ((longlong)pvVar2 + 0x60);
  *(undefined8 *)this_01 = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x68) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x70) = 0;
  this_02 = (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
            ((longlong)pvVar2 + 0x78);
  *(undefined8 *)this_02 = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x80) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x88) = 0;
  *(undefined1 *)((longlong)pvVar2 + 0x91) = 0;
  local_res20 = (piecewise_construct_t *)0x2;
  if ((ulonglong)(*(longlong *)((longlong)pvVar2 + 0x58) - *(longlong *)this_00 >> 3) < 2) {
    vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::_Reallocate<0>
              (this_00,(__uint64 *)&local_res20);
  }
  local_res20 = (piecewise_construct_t *)0x2;
  if ((ulonglong)(*(longlong *)((longlong)pvVar2 + 0x70) - *(longlong *)this_01 >> 3) < 2) {
    vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::_Reallocate<0>
              (this_01,(__uint64 *)&local_res20);
  }
  local_res20 = (piecewise_construct_t *)0x2;
  if ((ulonglong)(*(longlong *)((longlong)pvVar2 + 0x88) - *(longlong *)this_02 >> 3) < 2) {
    vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::_Reallocate<0>
              (this_02,(__uint64 *)&local_res20);
  }
  **(undefined8 **)(this + 8) = param_2;
  *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)
   (*(longlong *)(this + 8) + 8) = param_2;
  *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)
   (*(longlong *)(this + 8) + 0x10) = param_2;
  lVar3 = 0;
  do {
    *(undefined1 *)(*(longlong *)(this + 8) + 0x18 + lVar3) = 0;
    lVar3 = lVar3 + 1;
  } while (lVar3 < 2);
  return this;
}



===== _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_><std::piecewise_construct_t_const&___ptr64,std::tuple<unsigned_long_const&___ptr64>,std::tuple<unsigned_long&___ptr64>_> @ 18000d148 =====

/* public: __cdecl std::_Tree_temp_node<class std::allocator<struct std::_Tree_node<struct
   std::pair<unsigned long const ,class PktMon::VMSwitch>,void * __ptr64> > >::_Tree_temp_node<class
   std::allocator<struct std::_Tree_node<struct std::pair<unsigned long const ,class
   PktMon::VMSwitch>,void * __ptr64> > ><struct std::piecewise_construct_t const & __ptr64,class
   std::tuple<unsigned long const & __ptr64>,class std::tuple<unsigned long & __ptr64> >(class
   std::allocator<struct std::_Tree_node<struct std::pair<unsigned long const ,class
   PktMon::VMSwitch>,void * __ptr64> > & __ptr64,struct std::_Tree_node<struct std::pair<unsigned
   long const ,class PktMon::VMSwitch>,void * __ptr64> * __ptr64,struct std::piecewise_construct_t
   const & __ptr64,class std::tuple<unsigned long const & __ptr64> && __ptr64,class
   std::tuple<unsigned long & __ptr64> && __ptr64) __ptr64 */

_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
* __thiscall
std::
_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
::
_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_><std::piecewise_construct_t_const&___ptr64,std::tuple<unsigned_long_const&___ptr64>,std::tuple<unsigned_long&___ptr64>_>
          (_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
           *this,allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>
                 *param_1,
          _Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *param_2,
          piecewise_construct_t *param_3,tuple<unsigned_long_const&___ptr64> *param_4,
          tuple<unsigned_long&___ptr64> *param_5)

{
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *this_00;
  undefined4 *puVar1;
  void *pvVar2;
  longlong lVar3;
  piecewise_construct_t *local_res20;
  
  *(allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_> **)
   this = param_1;
  *(undefined8 *)(this + 8) = 0;
  local_res20 = param_3;
  pvVar2 = operator_new(0x90);
  *(void **)(this + 8) = pvVar2;
  puVar1 = *(undefined4 **)param_5;
  *(undefined4 *)((longlong)pvVar2 + 0x20) = **(undefined4 **)param_4;
  *(undefined4 *)((longlong)pvVar2 + 0x30) = *puVar1;
  *(undefined1 *)((longlong)pvVar2 + 0x34) = 0;
  *(undefined ***)((longlong)pvVar2 + 0x28) = &PktMon::VMSwitch::_vftable_;
  this_00 = (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
            ((longlong)pvVar2 + 0x38);
  *(undefined8 *)this_00 = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x40) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x48) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x50) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x58) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x60) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x68) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x70) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x78) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x80) = 0;
  *(undefined8 *)((longlong)pvVar2 + 0x88) = 0;
  local_res20 = (piecewise_construct_t *)0x1;
  if (*(longlong *)((longlong)pvVar2 + 0x48) - *(longlong *)this_00 >> 3 == 0) {
    vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::_Reallocate<0>
              (this_00,(__uint64 *)&local_res20);
  }
  **(undefined8 **)(this + 8) = param_2;
  *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)
   (*(longlong *)(this + 8) + 8) = param_2;
  *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)
   (*(longlong *)(this + 8) + 0x10) = param_2;
  lVar3 = 0;
  do {
    *(undefined1 *)(*(longlong *)(this + 8) + 0x18 + lVar3) = 0;
    lVar3 = lVar3 + 1;
  } while (lVar3 < 2);
  return this;
}



===== operator+<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_> @ 18000d250 =====

/* class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > __cdecl std::operator+<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > && __ptr64,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > && __ptr64) */

basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
* __cdecl std::
          operator+<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                    (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                     *param_1,
                    basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                    *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar5;
  allocator<unsigned_short> *paVar6;
  ushort *_Dst;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *in_R8;
  size_t _Size;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *local_res8;
  
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  uVar2 = *(ulonglong *)(param_2 + 0x10);
  uVar3 = *(ulonglong *)(in_R8 + 0x10);
  uVar1 = uVar3 + uVar2;
  local_res8 = param_1;
  if ((*(longlong *)(param_2 + 0x18) - uVar2 < uVar3) ||
     (*(ulonglong *)(param_2 + 0x18) < *(ulonglong *)(in_R8 + 0x18))) {
    if (*(ulonglong *)(in_R8 + 0x18) - uVar3 < uVar2) {
      if (0x7ffffffffffffffe - uVar2 < uVar3) {
                    /* WARNING: Subroutine does not return */
        _Xlen_string();
      }
      paVar6 = (allocator<unsigned_short> *)(uVar1 | 7);
      local_res8 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                    *)(allocator<unsigned_short> *)0x7ffffffffffffffe;
      if ((paVar6 < (allocator<unsigned_short> *)0x7fffffffffffffff) &&
         (local_res8 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                        *)paVar6, paVar6 < (allocator<unsigned_short> *)0xa)) {
        local_res8 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                      *)0xa;
      }
      _Dst = basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
             ::_Allocate_for_capacity<0>
                       ((allocator<unsigned_short> *)local_res8,(__uint64 *)&local_res8);
      *(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
        **)(param_1 + 0x18) = local_res8;
      *(ushort **)param_1 = _Dst;
      *(ulonglong *)(param_1 + 0x10) = uVar1;
      if (7 < *(ulonglong *)(param_2 + 0x18)) {
        param_2 = *(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                    **)param_2;
      }
      memcpy(_Dst,param_2,uVar2 * 2);
      if (7 < *(ulonglong *)(in_R8 + 0x18)) {
        in_R8 = *(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                  **)in_R8;
      }
      memcpy(_Dst + uVar2,in_R8,uVar3 * 2 + 2);
      return param_1;
    }
    uVar4 = *(undefined8 *)(in_R8 + 8);
    _Size = uVar2 * 2;
    *(undefined8 *)param_1 = *(undefined8 *)in_R8;
    *(undefined8 *)(param_1 + 8) = uVar4;
    uVar4 = *(undefined8 *)(in_R8 + 0x18);
    *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(in_R8 + 0x10);
    *(undefined8 *)(param_1 + 0x18) = uVar4;
    *(undefined8 *)(in_R8 + 0x10) = 0;
    *(undefined2 *)in_R8 = 0;
    *(undefined8 *)(in_R8 + 0x18) = 7;
    pbVar5 = *(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
               **)param_1;
    memmove(pbVar5 + _Size,pbVar5,uVar3 * 2 + 2);
    if (7 < *(ulonglong *)(param_2 + 0x18)) {
      param_2 = *(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                  **)param_2;
    }
  }
  else {
    uVar4 = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)param_1 = *(undefined8 *)param_2;
    *(undefined8 *)(param_1 + 8) = uVar4;
    uVar4 = *(undefined8 *)(param_2 + 0x18);
    *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    *(undefined8 *)(param_1 + 0x18) = uVar4;
    *(undefined8 *)(param_2 + 0x10) = 0;
    *(undefined8 *)(param_2 + 0x18) = 7;
    *(undefined2 *)param_2 = 0;
    pbVar5 = param_1;
    if (7 < *(ulonglong *)(param_1 + 0x18)) {
      pbVar5 = *(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                 **)param_1;
    }
    param_2 = in_R8;
    if (7 < *(ulonglong *)(in_R8 + 0x18)) {
      param_2 = *(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                  **)in_R8;
    }
    _Size = uVar3 * 2 + 2;
    pbVar5 = pbVar5 + uVar2 * 2;
  }
  memcpy(pbVar5,param_2,_Size);
  *(ulonglong *)(param_1 + 0x10) = uVar1;
  return param_1;
}



===== operator<<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_> @ 18000d404 =====

/* bool __cdecl std::operator<<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> >(class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const & __ptr64,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const & __ptr64) */

bool __cdecl
std::operator<<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
           *param_1,
          basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  byte bVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  uVar1 = *(ulonglong *)(param_2 + 0x10);
  if (7 < *(ulonglong *)(param_2 + 0x18)) {
    param_2 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                **)param_2;
  }
  uVar2 = *(ulonglong *)(param_1 + 0x10);
  if (7 < *(ulonglong *)(param_1 + 0x18)) {
    param_1 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                **)param_1;
  }
  uVar5 = uVar1;
  if (uVar2 <= uVar1) {
    uVar5 = uVar2;
  }
  if (uVar5 != 0) {
    lVar4 = (longlong)param_1 - (longlong)param_2;
    do {
      if (*(ushort *)(param_2 + lVar4) != *(ushort *)param_2) {
        bVar3 = (byte)((-(uint)(*(ushort *)(param_2 + lVar4) < *(ushort *)param_2) & 0xfffffffe) + 1
                      >> 0x18);
        goto LAB_18000d464;
      }
      param_2 = param_2 + 2;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  if (uVar2 < uVar1) {
    bVar3 = 0xff;
  }
  else {
    bVar3 = 0;
  }
LAB_18000d464:
  return (bool)(bVar3 >> 7);
}



===== GetObjectWithFilter<NetSetup2::NetworkInterface> @ 18000d474 =====

/* class NetSetup2::NetworkInterface __cdecl NetSetup2::details::GetObjectWithFilter<class
   NetSetup2::NetworkInterface>(class NetSetup2::details::TransactionBase const & __ptr64,enum
   _NETSETUP_OBJECT_TYPE,struct _GUID const * __ptr64,unsigned long,struct
   _NETSETUPPROP_FILTER_EXPRESSION const * __ptr64) */

TransactionBase * __cdecl
NetSetup2::details::GetObjectWithFilter<NetSetup2::NetworkInterface>
          (TransactionBase *param_1,_NETSETUP_OBJECT_TYPE param_2,_GUID *param_3,ulong param_4,
          _NETSETUPPROP_FILTER_EXPRESSION *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_register_00000014;
  undefined4 in_register_0000008c;
  undefined4 local_res18 [4];
  int in_stack_ffffffffffffffc8;
  int local_20 [2];
  longlong local_18;
  
  local_res18[0] = SUB84(param_3,0);
  GetObjectWithFilterInner
            (local_20,(undefined8 *)CONCAT44(in_register_00000014,param_2),param_3,
             CONCAT44(in_register_0000008c,param_4),in_stack_ffffffffffffffc8);
  if (local_20[0] == 0) {
    local_res18[0] = 0x80070490;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res18,(ThrowInfo *)&_TI1J);
  }
  *(undefined8 **)param_1 = (undefined8 *)CONCAT44(in_register_00000014,param_2);
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 2;
  uVar1 = *(undefined4 *)(local_18 + 8);
  uVar2 = *(undefined4 *)(local_18 + 0xc);
  uVar3 = *(undefined4 *)(local_18 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(local_18 + 4);
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  *(undefined4 *)(param_1 + 0x20) = uVar3;
  if (local_18 != 0) {
    NetSetupFreeObjects();
  }
  return param_1;
}



===== _Emplace_reallocate<PktMon::Component_const*___ptr64_const&___ptr64> @ 18000d4fc =====

/* private: class PktMon::Component const * __ptr64 * __ptr64 __cdecl std::vector<class
   PktMon::Component const * __ptr64,class std::allocator<class PktMon::Component const * __ptr64>
   >::_Emplace_reallocate<class PktMon::Component const * __ptr64 const & __ptr64>(class
   PktMon::Component const * __ptr64 * __ptr64 const,class PktMon::Component const * __ptr64 const &
   __ptr64) __ptr64 */

Component ** __thiscall
std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
_Emplace_reallocate<PktMon::Component_const*___ptr64_const&___ptr64>
          (vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
           *this,Component **param_1,Component **param_2)

{
  allocator<PktMon::Component_const*___ptr64> *paVar1;
  longlong lVar2;
  Component **_Src;
  longlong lVar3;
  allocator<PktMon::Component_const*___ptr64> *_Dst;
  allocator<PktMon::Component_const*___ptr64> *paVar4;
  allocator<PktMon::Component_const*___ptr64> *_Dst_00;
  allocator<PktMon::Component_const*___ptr64> *paVar5;
  size_t _Size;
  allocator<PktMon::Component_const*___ptr64> *local_res10;
  
  lVar2 = *(longlong *)this;
  lVar3 = *(longlong *)(this + 8) - *(longlong *)this >> 3;
  if (lVar3 == 0x1fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  paVar1 = (allocator<PktMon::Component_const*___ptr64> *)(lVar3 + 1);
  paVar4 = (allocator<PktMon::Component_const*___ptr64> *)
           (*(longlong *)(this + 0x10) - *(longlong *)this >> 3);
  paVar5 = (allocator<PktMon::Component_const*___ptr64> *)0x1fffffffffffffff;
  if ((paVar4 <= (allocator<PktMon::Component_const*___ptr64> *)
                 (0x1fffffffffffffff - ((ulonglong)paVar4 >> 1))) &&
     (paVar5 = paVar4 + ((ulonglong)paVar4 >> 1), paVar4 + ((ulonglong)paVar4 >> 1) < paVar1)) {
    paVar5 = paVar1;
  }
  local_res10 = paVar5;
  _Dst = (allocator<PktMon::Component_const*___ptr64> *)
         _Allocate_at_least_helper<std::allocator<PktMon::Component_const*___ptr64>_>
                   (paVar4,(__uint64 *)&local_res10);
  paVar4 = _Dst + ((longlong)param_1 - lVar2 >> 3) * 8;
  *(Component **)paVar4 = *param_2;
  _Src = *(Component ***)this;
  local_res10 = _Dst;
  if (param_1 == *(Component ***)(this + 8)) {
    _Size = (longlong)*(Component ***)(this + 8) - (longlong)_Src;
    _Dst_00 = _Dst;
    param_1 = _Src;
  }
  else {
    memmove(_Dst,_Src,(longlong)param_1 - *(longlong *)this);
    _Dst_00 = paVar4 + 8;
    _Size = *(longlong *)(this + 8) - (longlong)param_1;
  }
  memmove(_Dst_00,param_1,_Size);
  vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>::
  _Change_array((vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>
                 *)this,(CompGroup **)_Dst,(__uint64)paVar1,(__uint64)paVar5);
  return (Component **)paVar4;
}



===== _Emplace_reallocate<PktMon::CounterInfo&___ptr64> @ 18000d604 =====

/* private: struct PktMon::CounterInfo * __ptr64 __cdecl std::vector<struct
   PktMon::CounterInfo,class std::allocator<struct PktMon::CounterInfo>
   >::_Emplace_reallocate<struct PktMon::CounterInfo & __ptr64>(struct PktMon::CounterInfo * __ptr64
   const,struct PktMon::CounterInfo & __ptr64) __ptr64 */

CounterInfo * __thiscall
std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
_Emplace_reallocate<PktMon::CounterInfo&___ptr64>
          (vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *this,
          CounterInfo *param_1,CounterInfo *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  CounterInfo *_Src;
  code *pcVar3;
  undefined8 uVar4;
  longlong lVar5;
  void *pvVar6;
  ulonglong uVar7;
  __uint64 _Var8;
  CounterInfo *_Dst;
  CounterInfo *pCVar9;
  CounterInfo *pCVar10;
  ulonglong uVar11;
  size_t _Size;
  
  lVar2 = *(longlong *)this;
  lVar5 = (*(longlong *)(this + 8) - *(longlong *)this >> 4) * -0x3333333333333333;
  if (lVar5 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  uVar1 = lVar5 + 1;
  uVar7 = (*(longlong *)(this + 0x10) - *(longlong *)this >> 4) * -0x3333333333333333;
  if (uVar7 <= 0x333333333333333 - (uVar7 >> 1)) {
    uVar7 = (uVar7 >> 1) + uVar7;
    uVar11 = uVar1;
    if (uVar1 <= uVar7) {
      uVar11 = uVar7;
    }
    if (uVar11 < 0x333333333333334) {
      _Var8 = uVar11 * 0x50;
      if (_Var8 < 0x1000) {
        pCVar9 = (CounterInfo *)0x0;
        if (_Var8 != 0) {
          pCVar9 = operator_new(_Var8);
        }
      }
      else {
        if (_Var8 + 0x27 <= _Var8) goto LAB_18000d7b9;
        pvVar6 = operator_new(_Var8 + 0x27);
        if (pvVar6 == (void *)0x0) {
          _o__invalid_parameter_noinfo_noreturn();
          pcVar3 = (code *)swi(3);
          pCVar9 = (CounterInfo *)(*pcVar3)();
          return pCVar9;
        }
        pCVar9 = (CounterInfo *)((longlong)pvVar6 + 0x27U & 0xffffffffffffffe0);
        *(void **)(pCVar9 + -8) = pvVar6;
      }
      pCVar10 = pCVar9 + (((longlong)param_1 - lVar2) / 0x50) * 0x50;
      uVar4 = *(undefined8 *)(param_2 + 8);
      *(undefined8 *)pCVar10 = *(undefined8 *)param_2;
      *(undefined8 *)(pCVar10 + 8) = uVar4;
      uVar4 = *(undefined8 *)(param_2 + 0x18);
      *(undefined8 *)(pCVar10 + 0x10) = *(undefined8 *)(param_2 + 0x10);
      *(undefined8 *)(pCVar10 + 0x18) = uVar4;
      uVar4 = *(undefined8 *)(param_2 + 0x28);
      *(undefined8 *)(pCVar10 + 0x20) = *(undefined8 *)(param_2 + 0x20);
      *(undefined8 *)(pCVar10 + 0x28) = uVar4;
      uVar4 = *(undefined8 *)(param_2 + 0x38);
      *(undefined8 *)(pCVar10 + 0x30) = *(undefined8 *)(param_2 + 0x30);
      *(undefined8 *)(pCVar10 + 0x38) = uVar4;
      uVar4 = *(undefined8 *)(param_2 + 0x48);
      *(undefined8 *)(pCVar10 + 0x40) = *(undefined8 *)(param_2 + 0x40);
      *(undefined8 *)(pCVar10 + 0x48) = uVar4;
      _Src = *(CounterInfo **)this;
      if (param_1 == *(CounterInfo **)(this + 8)) {
        _Size = (longlong)*(CounterInfo **)(this + 8) - (longlong)_Src;
        _Dst = pCVar9;
        param_1 = _Src;
      }
      else {
        memmove(pCVar9,_Src,(longlong)param_1 - *(longlong *)this);
        _Dst = pCVar10 + 0x50;
        _Size = *(longlong *)(this + 8) - (longlong)param_1;
      }
      memmove(_Dst,param_1,_Size);
      _Change_array(this,pCVar9,uVar1,uVar11);
      return pCVar10;
    }
  }
LAB_18000d7b9:
                    /* WARNING: Subroutine does not return */
  _Throw_bad_array_new_length();
}



===== _Emplace_reallocate<_PKTMON_COMPONENT_OUT_const&___ptr64> @ 18000d7cc =====

/* private: class PktMon::Component * __ptr64 __cdecl std::vector<class PktMon::Component,class
   std::allocator<class PktMon::Component> >::_Emplace_reallocate<struct _PKTMON_COMPONENT_OUT const
   & __ptr64>(class PktMon::Component * __ptr64 const,struct _PKTMON_COMPONENT_OUT const & __ptr64)
   __ptr64 */

Component * __thiscall
std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::
_Emplace_reallocate<_PKTMON_COMPONENT_OUT_const&___ptr64>
          (vector<PktMon::Component,std::allocator<PktMon::Component>_> *this,Component *param_1,
          _PKTMON_COMPONENT_OUT *param_2)

{
  ulonglong uVar1;
  Component *pCVar2;
  __uint64 _Var3;
  Component *_Src;
  code *pcVar4;
  longlong lVar5;
  void *pvVar6;
  ulonglong uVar7;
  Component *_Dst;
  longlong lVar8;
  Component *pCVar9;
  ulonglong uVar10;
  size_t _Size;
  
  lVar8 = ((longlong)param_1 - *(longlong *)this) / 6 +
          ((longlong)param_1 - *(longlong *)this >> 0x3f);
  lVar5 = (*(longlong *)(this + 8) - *(longlong *)this >> 3) * -0x5555555555555555;
  if (lVar5 == 0xaaaaaaaaaaaaaaa) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  uVar1 = lVar5 + 1;
  uVar7 = (*(longlong *)(this + 0x10) - *(longlong *)this >> 3) * -0x5555555555555555;
  if (uVar7 <= 0xaaaaaaaaaaaaaaa - (uVar7 >> 1)) {
    uVar7 = (uVar7 >> 1) + uVar7;
    uVar10 = uVar1;
    if (uVar1 <= uVar7) {
      uVar10 = uVar7;
    }
    if (uVar10 < 0xaaaaaaaaaaaaaab) {
      _Var3 = uVar10 * 0x18;
      if (_Var3 < 0x1000) {
        pCVar9 = (Component *)0x0;
        if (_Var3 != 0) {
          pCVar9 = operator_new(_Var3);
        }
      }
      else {
        if (_Var3 + 0x27 <= _Var3) goto LAB_18000d962;
        pvVar6 = operator_new(_Var3 + 0x27);
        if (pvVar6 == (void *)0x0) {
          _o__invalid_parameter_noinfo_noreturn();
          pcVar4 = (code *)swi(3);
          pCVar9 = (Component *)(*pcVar4)();
          return pCVar9;
        }
        pCVar9 = (Component *)((longlong)pvVar6 + 0x27U & 0xffffffffffffffe0);
        *(void **)(pCVar9 + -8) = pvVar6;
      }
      pCVar2 = pCVar9 + ((lVar8 >> 2) - (lVar8 >> 0x3f)) * 0x18;
      *(_PKTMON_COMPONENT_OUT **)pCVar2 = param_2;
      *(Component **)(pCVar2 + 8) = pCVar2;
      *(Component **)(pCVar2 + 0x10) = pCVar2;
      _Src = *(Component **)this;
      if (param_1 == *(Component **)(this + 8)) {
        _Size = (longlong)*(Component **)(this + 8) - (longlong)_Src;
        _Dst = pCVar9;
        param_1 = _Src;
      }
      else {
        memmove(pCVar9,_Src,(longlong)param_1 - *(longlong *)this);
        _Dst = pCVar2 + 0x18;
        _Size = *(longlong *)(this + 8) - (longlong)param_1;
      }
      memmove(_Dst,param_1,_Size);
      _Change_array(this,pCVar9,uVar1,uVar10);
      return pCVar2;
    }
  }
LAB_18000d962:
                    /* WARNING: Subroutine does not return */
  _Throw_bad_array_new_length();
}



===== _Emplace_reallocate<PktMon::Component_const&___ptr64,unsigned_short_const_(&___ptr64)[64],_PKTMON_COUNTER_SET_const&___ptr64,PktMon::CounterType> @ 18000d974 =====

/* private: struct PktMon::CounterInfo * __ptr64 __cdecl std::vector<struct
   PktMon::CounterInfo,class std::allocator<struct PktMon::CounterInfo> >::_Emplace_reallocate<class
   PktMon::Component const & __ptr64,unsigned short const (& __ptr64)[64],struct _PKTMON_COUNTER_SET
   const & __ptr64,enum PktMon::CounterType>(struct PktMon::CounterInfo * __ptr64 const,class
   PktMon::Component const & __ptr64,unsigned short const (& __ptr64)[64],struct _PKTMON_COUNTER_SET
   const & __ptr64,enum PktMon::CounterType && __ptr64) __ptr64 */

CounterInfo * __thiscall
std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
_Emplace_reallocate<PktMon::Component_const&___ptr64,unsigned_short_const_(&___ptr64)[64],_PKTMON_COUNTER_SET_const&___ptr64,PktMon::CounterType>
          (vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *this,
          CounterInfo *param_1,Component *param_2,ushort *param_3,_PKTMON_COUNTER_SET *param_4,
          CounterType *param_5)

{
  ulonglong uVar1;
  CounterType CVar2;
  longlong lVar3;
  CounterInfo *_Src;
  code *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  void *pvVar7;
  ulonglong uVar8;
  __uint64 _Var9;
  CounterInfo *_Dst;
  ulonglong uVar10;
  CounterInfo *pCVar11;
  CounterInfo *pCVar12;
  size_t _Size;
  
  lVar3 = *(longlong *)this;
  lVar6 = (*(longlong *)(this + 8) - *(longlong *)this >> 4) * -0x3333333333333333;
  if (lVar6 == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
    vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
    ::_Xlength();
  }
  uVar1 = lVar6 + 1;
  uVar8 = (*(longlong *)(this + 0x10) - *(longlong *)this >> 4) * -0x3333333333333333;
  if (uVar8 <= 0x333333333333333 - (uVar8 >> 1)) {
    uVar8 = (uVar8 >> 1) + uVar8;
    uVar10 = uVar1;
    if (uVar1 <= uVar8) {
      uVar10 = uVar8;
    }
    if (uVar10 < 0x333333333333334) {
      _Var9 = uVar10 * 0x50;
      if (_Var9 < 0x1000) {
        if (_Var9 == 0) {
          pCVar12 = (CounterInfo *)0x0;
        }
        else {
          pCVar12 = operator_new(_Var9);
        }
      }
      else {
        if (_Var9 + 0x27 <= _Var9) goto LAB_18000db3f;
        pvVar7 = operator_new(_Var9 + 0x27);
        if (pvVar7 == (void *)0x0) {
          _o__invalid_parameter_noinfo_noreturn();
          pcVar4 = (code *)swi(3);
          pCVar12 = (CounterInfo *)(*pcVar4)();
          return pCVar12;
        }
        pCVar12 = (CounterInfo *)((longlong)pvVar7 + 0x27U & 0xffffffffffffffe0);
        *(void **)(pCVar12 + -8) = pvVar7;
      }
      pCVar11 = pCVar12 + (((longlong)param_1 - lVar3) / 0x50) * 0x50;
      CVar2 = *param_5;
      *(Component **)pCVar11 = param_2;
      *(ushort **)(pCVar11 + 8) = param_3;
      uVar5 = *(undefined8 *)(param_4 + 8);
      *(undefined8 *)(pCVar11 + 0x10) = *(undefined8 *)param_4;
      *(undefined8 *)(pCVar11 + 0x18) = uVar5;
      *(undefined8 *)(pCVar11 + 0x20) = *(undefined8 *)(param_4 + 0x10);
      uVar5 = *(undefined8 *)(param_4 + 0x20);
      *(undefined8 *)(pCVar11 + 0x28) = *(undefined8 *)(param_4 + 0x18);
      *(undefined8 *)(pCVar11 + 0x30) = uVar5;
      *(undefined8 *)(pCVar11 + 0x38) = *(undefined8 *)(param_4 + 0x28);
      *(CounterType *)(pCVar11 + 0x40) = CVar2;
      pCVar11[0x44] = (CounterInfo)0x0;
      *(undefined4 *)(pCVar11 + 0x48) = 0;
      _Src = *(CounterInfo **)this;
      if (param_1 == *(CounterInfo **)(this + 8)) {
        _Size = (longlong)*(CounterInfo **)(this + 8) - (longlong)_Src;
        _Dst = pCVar12;
        param_1 = _Src;
      }
      else {
        memmove(pCVar12,_Src,(longlong)param_1 - *(longlong *)this);
        _Dst = pCVar11 + 0x50;
        _Size = *(longlong *)(this + 8) - (longlong)param_1;
      }
      memmove(_Dst,param_1,_Size);
      _Change_array(this,pCVar12,uVar1,uVar10);
      return pCVar11;
    }
  }
LAB_18000db3f:
                    /* WARNING: Subroutine does not return */
  _Throw_bad_array_new_length();
}



===== _Erase_tree<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_> @ 18000db54 =====

/* public: void __cdecl std::_Tree_val<struct std::_Tree_simple_types<struct std::pair<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const > >
   >::_Erase_tree<class std::allocator<struct std::_Tree_node<struct std::pair<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const >,void * __ptr64> >
   >(class std::allocator<struct std::_Tree_node<struct std::pair<class std::basic_string<unsigned
   short,struct std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const >,void * __ptr64> > & __ptr64,struct
   std::_Tree_node<struct std::pair<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const >,void * __ptr64> * __ptr64) __ptr64 */

void __thiscall
std::
_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
::
_Erase_tree<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
          (_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
           *this,allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>
                 *param_1,
          _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
          *param_2)

{
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  _Var1;
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  *p_Var2;
  
  _Var1 = param_2[0x19];
  while (_Var1 == (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                   )0x0) {
    _Erase_tree<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
              (this,param_1,
               *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                 **)(param_2 + 0x10));
    p_Var2 = *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
               **)param_2;
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(param_2 + 0x40));
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(param_2 + 0x20));
    operator_delete(param_2,0x60);
    param_2 = p_Var2;
    _Var1 = p_Var2[0x19];
  }
  return;
}



===== _Find_hint<long> @ 18000dbdc =====

/* protected: struct std::_Tree_find_hint_result<struct std::_Tree_node<long,void * __ptr64> *
   __ptr64> __cdecl std::_Tree<class std::_Tset_traits<long,struct std::less<long>,class
   std::allocator<long>,0> >::_Find_hint<long>(struct std::_Tree_node<long,void * __ptr64> * __ptr64
   const,long const & __ptr64)const __ptr64 */

_Tree_node<long,void*___ptr64> * __thiscall
std::_Tree<std::_Tset_traits<long,std::less<long>,std::allocator<long>,0>_>::_Find_hint<long>
          (_Tree<std::_Tset_traits<long,std::less<long>,std::allocator<long>,0>_> *this,
          _Tree_node<long,void*___ptr64> *param_1,long *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  bool bVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  int iVar9;
  int *in_R9;
  undefined8 *local_38;
  undefined8 uStack_30;
  
  plVar7 = *(longlong **)this;
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    iVar9 = *in_R9;
    if (param_2 == (long *)*plVar7) {
      if (param_2[7] <= iVar9) goto LAB_18000dd59;
      *(long **)param_1 = param_2;
      *(undefined8 *)(param_1 + 8) = 1;
      goto LAB_18000dc50;
    }
    if (iVar9 < param_2[7]) {
      plVar7 = *(longlong **)param_2;
      if (*(char *)((longlong)plVar7 + 0x19) == '\0') {
        plVar4 = (longlong *)plVar7[2];
        while (plVar6 = plVar4, *(char *)((longlong)plVar6 + 0x19) == '\0') {
          plVar7 = plVar6;
          plVar4 = (longlong *)plVar6[2];
        }
      }
      else {
        plVar7 = *(longlong **)(param_2 + 2);
        plVar4 = (longlong *)param_2;
        if (*(char *)((longlong)plVar7 + 0x19) == '\0') {
          do {
            plVar6 = plVar7;
            plVar7 = plVar6;
            if (plVar4 != (longlong *)*plVar6) break;
            plVar7 = (longlong *)plVar6[1];
            plVar4 = plVar6;
          } while (*(char *)((longlong)plVar7 + 0x19) == '\0');
        }
        if (*(char *)((longlong)plVar4 + 0x19) != '\0') {
          plVar7 = plVar4;
        }
      }
      iVar9 = *in_R9;
      if (iVar9 <= *(int *)((longlong)plVar7 + 0x1c)) goto LAB_18000dd59;
      cVar1 = *(char *)(plVar7[2] + 0x19);
      param_1[0x10] = (_Tree_node<long,void*___ptr64>)0x0;
      if (cVar1 != '\0') {
        *(longlong **)param_1 = plVar7;
        goto LAB_18000dde5;
      }
      *(long **)param_1 = param_2;
LAB_18000dcec:
      *(undefined8 *)(param_1 + 8) = 1;
      goto LAB_18000dde9;
    }
    if (param_2[7] < iVar9) {
      plVar7 = *(longlong **)(param_2 + 4);
      if (*(char *)((longlong)plVar7 + 0x19) == '\0') {
        cVar1 = *(char *)(*plVar7 + 0x19);
        plVar4 = (longlong *)*plVar7;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*plVar4 + 0x19);
          plVar7 = plVar4;
          plVar4 = (longlong *)*plVar4;
        }
LAB_18000dd4a:
        if ((*(char *)((longlong)plVar7 + 0x19) == '\0') &&
           (iVar9 = *in_R9, *(int *)((longlong)plVar7 + 0x1c) <= iVar9)) goto LAB_18000dd59;
      }
      else {
        plVar7 = *(longlong **)(param_2 + 2);
        if (*(char *)((longlong)plVar7 + 0x19) == '\0') {
          plVar4 = (longlong *)param_2;
          plVar6 = plVar7;
          do {
            plVar7 = plVar6;
            if (plVar4 != (longlong *)plVar6[2]) break;
            plVar7 = (longlong *)plVar6[1];
            plVar4 = plVar6;
            plVar6 = plVar7;
          } while (*(char *)((longlong)plVar7 + 0x19) == '\0');
          goto LAB_18000dd4a;
        }
      }
      cVar1 = *(char *)(*(longlong *)(param_2 + 4) + 0x19);
      param_1[0x10] = (_Tree_node<long,void*___ptr64>)0x0;
      if (cVar1 == '\0') {
        *(longlong **)param_1 = plVar7;
        goto LAB_18000dcec;
      }
    }
    else {
      param_1[0x10] = (_Tree_node<long,void*___ptr64>)0x1;
    }
    *(long **)param_1 = param_2;
  }
  else {
    if ((*(char *)(plVar7[1] + 0x19) == '\0') &&
       (iVar9 = *in_R9, iVar9 <= *(int *)(plVar7[2] + 0x1c))) {
LAB_18000dd59:
      uStack_30 = 0;
      puVar2 = (undefined8 *)(*(undefined8 **)this)[1];
      puVar8 = *(undefined8 **)this;
      local_38 = puVar2;
      while (puVar5 = puVar2, *(char *)((longlong)puVar5 + 0x19) == '\0') {
        local_38 = puVar5;
        if (*(int *)((longlong)puVar5 + 0x1c) < iVar9) {
          uStack_30 = 0;
          puVar2 = (undefined8 *)puVar5[2];
        }
        else {
          uStack_30 = 1;
          puVar2 = (undefined8 *)*puVar5;
          puVar8 = puVar5;
        }
      }
      if ((*(char *)((longlong)puVar8 + 0x19) != '\0') ||
         (bVar3 = true, *in_R9 < *(int *)((longlong)puVar8 + 0x1c))) {
        bVar3 = false;
      }
      if (bVar3) {
        *(undefined8 **)param_1 = puVar8;
        *(undefined8 *)(param_1 + 8) = 2;
        param_1[0x10] = (_Tree_node<long,void*___ptr64>)0x1;
        goto LAB_18000dde9;
      }
      *(undefined8 **)param_1 = local_38;
      *(undefined8 *)(param_1 + 8) = uStack_30;
LAB_18000dc50:
      param_1[0x10] = (_Tree_node<long,void*___ptr64>)0x0;
      goto LAB_18000dde9;
    }
    *(longlong *)param_1 = plVar7[2];
    param_1[0x10] = (_Tree_node<long,void*___ptr64>)0x0;
  }
LAB_18000dde5:
  *(undefined8 *)(param_1 + 8) = 0;
LAB_18000dde9:
  *(undefined4 *)(param_1 + 0x11) = 0;
  *(undefined2 *)(param_1 + 0x15) = 0;
  param_1[0x17] = (_Tree_node<long,void*___ptr64>)0x0;
  return param_1;
}



===== _Find_hint<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_> @ 18000de18 =====

/* protected: struct std::_Tree_find_hint_result<struct std::_Tree_node<struct std::pair<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const >,void * __ptr64> *
   __ptr64> __cdecl std::_Tree<class std::_Tmap_traits<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,struct std::less<class std::basic_string<unsigned
   short,struct std::char_traits<unsigned short>,class std::allocator<unsigned short> > const
   >,class std::allocator<struct std::pair<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const > >,0> >::_Find_hint<class std::basic_string<unsigned
   short,struct std::char_traits<unsigned short>,class std::allocator<unsigned short> > >(struct
   std::_Tree_node<struct std::pair<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const >,void * __ptr64> * __ptr64 const,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const & __ptr64)const __ptr64 */

_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
* __thiscall
std::
_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
::
_Find_hint<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_>
          (_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
           *this,_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                 *param_1,
          basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          *param_2)

{
  char cVar1;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  bVar2;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  bVar3;
  bool bVar4;
  bool bVar5;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar6;
  longlong *plVar7;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar8;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar9;
  longlong *plVar10;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *in_R9;
  longlong *local_38;
  undefined8 uStack_30;
  
  plVar7 = DAT_180021d00;
  if (param_2[0x19] ==
      (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      )0x0) {
    bVar4 = operator<<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                      (in_R9,param_2 + 0x20);
    if (param_2 !=
        (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
         *)*plVar7) {
      if (bVar4) {
        pbVar9 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                   **)param_2;
        if (pbVar9[0x19] ==
            (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
             )0x0) {
          pbVar6 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                     **)(pbVar9 + 0x10);
          while (pbVar8 = pbVar6,
                pbVar8[0x19] ==
                (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 )0x0) {
            pbVar9 = pbVar8;
            pbVar6 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                       **)(pbVar8 + 0x10);
          }
        }
        else {
          pbVar9 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                     **)(param_2 + 8);
          pbVar6 = param_2;
          if (pbVar9[0x19] ==
              (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
               )0x0) {
            do {
              pbVar8 = pbVar9;
              pbVar9 = pbVar8;
              if (pbVar6 != *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                              **)pbVar8) break;
              pbVar9 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                         **)(pbVar8 + 8);
              pbVar6 = pbVar8;
            } while (pbVar9[0x19] ==
                     (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                      )0x0);
          }
          if (pbVar6[0x19] !=
              (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
               )0x0) {
            pbVar9 = pbVar6;
          }
        }
        bVar4 = operator<<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                          (pbVar9 + 0x20,in_R9);
        if (!bVar4) goto LAB_18000dfd5;
        cVar1 = *(char *)(*(longlong *)(pbVar9 + 0x10) + 0x19);
        param_1[0x10] =
             (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
              )0x0;
        if (cVar1 == '\0') {
          *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            **)param_1 = param_2;
          *(undefined8 *)(param_1 + 8) = 1;
          goto LAB_18000e085;
        }
        *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          **)param_1 = pbVar9;
      }
      else {
        bVar4 = operator<<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                          (param_2 + 0x20,in_R9);
        if (bVar4) {
          pbVar9 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                     **)(param_2 + 0x10);
          bVar2 = pbVar9[0x19];
          if (bVar2 == (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                        )0x0) {
            bVar3 = (*(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                       **)pbVar9)[0x19];
            pbVar6 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                       **)pbVar9;
            while (bVar3 == (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                             )0x0) {
              bVar3 = (*(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                         **)pbVar6)[0x19];
              pbVar9 = pbVar6;
              pbVar6 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                         **)pbVar6;
            }
LAB_18000dfb7:
            if ((pbVar9[0x19] ==
                 (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  )0x0) &&
               (bVar4 = operator<<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                                  (in_R9,pbVar9 + 0x20), !bVar4)) goto LAB_18000dfd5;
          }
          else {
            pbVar9 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                       **)(param_2 + 8);
            if (pbVar9[0x19] ==
                (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 )0x0) {
              pbVar6 = param_2;
              pbVar8 = pbVar9;
              do {
                pbVar9 = pbVar8;
                if (pbVar6 != *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                                **)(pbVar8 + 0x10)) break;
                pbVar9 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                           **)(pbVar8 + 8);
                pbVar6 = pbVar8;
                pbVar8 = pbVar9;
              } while (pbVar9[0x19] ==
                       (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                        )0x0);
              goto LAB_18000dfb7;
            }
          }
          param_1[0x10] =
               (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                )0x0;
          if (bVar2 == (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                        )0x0) {
            *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              **)param_1 = pbVar9;
            *(undefined8 *)(param_1 + 8) = 1;
          }
          else {
            *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              **)param_1 = param_2;
            *(undefined8 *)(param_1 + 8) = 0;
          }
          goto LAB_18000e085;
        }
        *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          **)param_1 = param_2;
        param_1[0x10] =
             (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
              )0x1;
      }
LAB_18000e07f:
      *(undefined8 *)(param_1 + 8) = 0;
      goto LAB_18000e085;
    }
    if (!bVar4) goto LAB_18000dfd5;
    *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      **)param_1 = param_2;
    *(undefined8 *)(param_1 + 8) = 1;
  }
  else {
    if ((*(char *)(DAT_180021d00[1] + 0x19) != '\0') ||
       (bVar4 = operator<<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                          ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                            *)(DAT_180021d00[2] + 0x20),in_R9), bVar4)) {
      *(longlong *)param_1 = plVar7[2];
      param_1[0x10] =
           (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
            )0x0;
      goto LAB_18000e07f;
    }
LAB_18000dfd5:
    uStack_30 = 0;
    plVar10 = (longlong *)plVar7[1];
    local_38 = (longlong *)plVar7[1];
    while (*(char *)((longlong)plVar10 + 0x19) == '\0') {
      bVar4 = operator<<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                        ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                          *)(plVar10 + 4),in_R9);
      local_38 = plVar10;
      if (bVar4) {
        uStack_30 = 0;
        plVar10 = (longlong *)plVar10[2];
      }
      else {
        uStack_30 = 1;
        plVar7 = plVar10;
        plVar10 = (longlong *)*plVar10;
      }
    }
    if (*(char *)((longlong)plVar7 + 0x19) == '\0') {
      bVar5 = operator<<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                        (in_R9,(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                                *)(plVar7 + 4));
      bVar4 = true;
      if (bVar5) goto LAB_18000e031;
    }
    else {
LAB_18000e031:
      bVar4 = false;
    }
    if (bVar4) {
      *(longlong **)param_1 = plVar7;
      *(undefined8 *)(param_1 + 8) = 2;
      param_1[0x10] =
           (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
            )0x1;
      goto LAB_18000e085;
    }
    *(longlong **)param_1 = local_38;
    *(undefined8 *)(param_1 + 8) = uStack_30;
  }
  param_1[0x10] =
       (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
        )0x0;
LAB_18000e085:
  *(undefined4 *)(param_1 + 0x11) = 0;
  *(undefined2 *)(param_1 + 0x15) = 0;
  param_1[0x17] =
       (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
        )0x0;
  return param_1;
}



===== _Insert_counted_range<PktMon::Component_const*___ptr64*___ptr64> @ 18000e0b8 =====

/* private: void __cdecl std::vector<class PktMon::Component const * __ptr64,class
   std::allocator<class PktMon::Component const * __ptr64> >::_Insert_counted_range<class
   PktMon::Component const * __ptr64 * __ptr64>(class std::_Vector_const_iterator<class
   std::_Vector_val<struct std::_Simple_types<class PktMon::Component const * __ptr64> > >,class
   PktMon::Component const * __ptr64 * __ptr64,unsigned __int64) __ptr64 */

void __thiscall
std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
_Insert_counted_range<PktMon::Component_const*___ptr64*___ptr64>
          (vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
           *this,void *param_2,void *param_3,allocator<PktMon::Component_const*___ptr64> *param_4)

{
  void *_Dst;
  Component **_Dst_00;
  longlong lVar1;
  allocator<PktMon::Component_const*___ptr64> *paVar2;
  Component **_Dst_01;
  ulonglong uVar3;
  allocator<PktMon::Component_const*___ptr64> *paVar4;
  void *pvVar5;
  size_t _Size;
  size_t sVar6;
  allocator<PktMon::Component_const*___ptr64> *paVar7;
  allocator<PktMon::Component_const*___ptr64> *local_res20;
  
  pvVar5 = *(void **)this;
  _Dst = *(void **)(this + 8);
  if (param_4 != (allocator<PktMon::Component_const*___ptr64> *)0x0) {
    local_res20 = param_4;
    if ((allocator<PktMon::Component_const*___ptr64> *)
        (*(longlong *)(this + 0x10) - (longlong)_Dst >> 3) < param_4) {
      sVar6 = (longlong)_Dst - (longlong)pvVar5;
      if ((allocator<PktMon::Component_const*___ptr64> *)
          (0x1fffffffffffffffU - ((longlong)sVar6 >> 3)) < param_4) {
                    /* WARNING: Subroutine does not return */
        vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
        ::_Xlength();
      }
      paVar7 = param_4 + ((longlong)sVar6 >> 3);
      uVar3 = *(longlong *)(this + 0x10) - (longlong)pvVar5 >> 3;
      paVar2 = (allocator<PktMon::Component_const*___ptr64> *)(uVar3 >> 1);
      paVar4 = (allocator<PktMon::Component_const*___ptr64> *)0x1fffffffffffffff;
      if ((uVar3 <= 0x1fffffffffffffffU - (longlong)paVar2) &&
         (paVar4 = paVar2 + uVar3, paVar2 + uVar3 < paVar7)) {
        paVar4 = paVar7;
      }
      local_res20 = paVar4;
      _Dst_00 = _Allocate_at_least_helper<std::allocator<PktMon::Component_const*___ptr64>_>
                          (paVar2,(__uint64 *)&local_res20);
      local_res20 = (allocator<PktMon::Component_const*___ptr64> *)
                    ((longlong)param_2 - (longlong)pvVar5);
      lVar1 = (longlong)local_res20 >> 3;
      memmove(_Dst_00 + lVar1,param_3,(longlong)param_4 * 8);
      if ((param_4 == (allocator<PktMon::Component_const*___ptr64> *)0x1) && (param_2 == _Dst)) {
        _Dst_01 = _Dst_00;
        param_2 = pvVar5;
      }
      else {
        memmove(_Dst_00,pvVar5,(size_t)local_res20);
        _Dst_01 = _Dst_00 + (longlong)(param_4 + lVar1);
        sVar6 = (longlong)_Dst - (longlong)param_2;
      }
      memmove(_Dst_01,param_2,sVar6);
      vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>::
      _Change_array((vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>
                     *)this,(CompGroup **)_Dst_00,(__uint64)paVar7,(__uint64)paVar4);
    }
    else {
      paVar7 = (allocator<PktMon::Component_const*___ptr64> *)
               ((longlong)_Dst - (longlong)param_2 >> 3);
      sVar6 = (longlong)param_4 * 8;
      if (param_4 < paVar7) {
        pvVar5 = (void *)((longlong)_Dst + (longlong)param_4 * -8);
        memmove(_Dst,pvVar5,sVar6);
        *(void **)(this + 8) = (void *)(sVar6 + (longlong)_Dst);
        _Size = (longlong)pvVar5 - (longlong)param_2;
        memmove((void *)((longlong)_Dst - _Size),param_2,_Size);
        memmove(param_2,param_3,sVar6);
      }
      else {
        paVar4 = (allocator<PktMon::Component_const*___ptr64> *)(sVar6 + (longlong)param_2);
        local_res20 = paVar4;
        memmove(paVar4,param_2,(longlong)_Dst - (longlong)param_2);
        *(allocator<PktMon::Component_const*___ptr64> **)(this + 8) = paVar4 + (longlong)paVar7 * 8;
        memmove(param_2,param_3,sVar6);
      }
    }
  }
  return;
}



===== _Insert_counted_range<PktMon::VMSwitch_const*___ptr64*___ptr64> @ 18000e2dc =====

/* private: void __cdecl std::vector<class PktMon::CompGroup const * __ptr64,class
   std::allocator<class PktMon::CompGroup const * __ptr64> >::_Insert_counted_range<class
   PktMon::VMSwitch const * __ptr64 * __ptr64>(class std::_Vector_const_iterator<class
   std::_Vector_val<struct std::_Simple_types<class PktMon::CompGroup const * __ptr64> > >,class
   PktMon::VMSwitch const * __ptr64 * __ptr64,unsigned __int64) __ptr64 */

void __thiscall
std::vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>::
_Insert_counted_range<PktMon::VMSwitch_const*___ptr64*___ptr64>
          (vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>
           *this,void *param_2,undefined8 *param_3,ulonglong param_4)

{
  __uint64 _Var1;
  void *_Dst;
  code *pcVar2;
  CompGroup *pCVar3;
  CompGroup **_Dst_00;
  ulonglong uVar4;
  longlong lVar5;
  CompGroup **_Dst_01;
  void *pvVar6;
  size_t sVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  pvVar6 = *(void **)this;
  _Dst = *(void **)(this + 8);
  _Dst_01 = (CompGroup **)0x0;
  if (param_4 != 0) {
    if ((ulonglong)(*(longlong *)(this + 0x10) - (longlong)_Dst >> 3) < param_4) {
      sVar7 = (longlong)_Dst - (longlong)pvVar6;
      if (0x1fffffffffffffffU - ((longlong)sVar7 >> 3) < param_4) {
                    /* WARNING: Subroutine does not return */
        vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
        ::_Xlength();
      }
      uVar10 = ((longlong)sVar7 >> 3) + param_4;
      uVar4 = *(longlong *)(this + 0x10) - (longlong)pvVar6 >> 3;
      if (uVar4 <= 0x1fffffffffffffff - (uVar4 >> 1)) {
        uVar4 = (uVar4 >> 1) + uVar4;
        uVar9 = uVar10;
        if (uVar10 <= uVar4) {
          uVar9 = uVar4;
        }
        if (uVar9 < 0x2000000000000000) {
          _Var1 = uVar9 * 8;
          if (_Var1 < 0x1000) {
            if (_Var1 != 0) {
              _Dst_01 = operator_new(_Var1);
            }
          }
          else {
            if (_Var1 + 0x27 <= _Var1) goto LAB_18000e55c;
            pCVar3 = operator_new(_Var1 + 0x27);
            if (pCVar3 == (CompGroup *)0x0) {
              _o__invalid_parameter_noinfo_noreturn();
              pcVar2 = (code *)swi(3);
              (*pcVar2)();
              return;
            }
            _Dst_01 = (CompGroup **)((ulonglong)(pCVar3 + 0x27) & 0xffffffffffffffe0);
            _Dst_01[-1] = pCVar3;
          }
          lVar8 = (longlong)param_2 - (longlong)pvVar6 >> 3;
          lVar5 = lVar8 * 8 - (longlong)param_3;
          uVar4 = param_4;
          do {
            *(undefined8 *)((longlong)_Dst_01 + lVar5 + (longlong)param_3) = *param_3;
            param_3 = param_3 + 1;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
          if ((param_4 == 1) && (param_2 == _Dst)) {
            _Dst_00 = _Dst_01;
            param_2 = pvVar6;
          }
          else {
            memmove(_Dst_01,pvVar6,(longlong)param_2 - (longlong)pvVar6);
            _Dst_00 = _Dst_01 + param_4 + lVar8;
            sVar7 = (longlong)_Dst - (longlong)param_2;
          }
          memmove(_Dst_00,param_2,sVar7);
          _Change_array(this,_Dst_01,uVar10,uVar9);
          return;
        }
      }
LAB_18000e55c:
                    /* WARNING: Subroutine does not return */
      _Throw_bad_array_new_length();
    }
    uVar10 = (longlong)_Dst - (longlong)param_2 >> 3;
    sVar7 = param_4 * 8;
    if (param_4 < uVar10) {
      pvVar6 = (void *)((longlong)_Dst + param_4 * -8);
      memmove(_Dst,pvVar6,sVar7);
      *(void **)(this + 8) = (void *)((longlong)_Dst + sVar7);
      sVar7 = (longlong)pvVar6 - (longlong)param_2;
      memmove((void *)((longlong)_Dst - sVar7),param_2,sVar7);
      lVar5 = (longlong)param_2 - (longlong)param_3;
      do {
        *(undefined8 *)((longlong)param_3 + lVar5) = *param_3;
        param_3 = param_3 + 1;
        param_4 = param_4 - 1;
      } while (param_4 != 0);
    }
    else {
      memmove((void *)((longlong)param_2 + sVar7),param_2,(longlong)_Dst - (longlong)param_2);
      *(void **)(this + 8) = (void *)((longlong)((longlong)param_2 + sVar7) + uVar10 * 8);
      lVar5 = (longlong)param_2 - (longlong)param_3;
      do {
        *(undefined8 *)((longlong)param_3 + lVar5) = *param_3;
        param_3 = param_3 + 1;
        param_4 = param_4 - 1;
      } while (param_4 != 0);
    }
  }
  return;
}



===== _Move_unchecked<PktMon::Component_const*___ptr64*___ptr64,PktMon::Component_const*___ptr64*___ptr64> @ 18000e568 =====

/* class PktMon::Component const * __ptr64 * __ptr64 __cdecl std::_Move_unchecked<class
   PktMon::Component const * __ptr64 * __ptr64,class PktMon::Component const * __ptr64 *
   __ptr64>(class PktMon::Component const * __ptr64 * __ptr64,class PktMon::Component const *
   __ptr64 * __ptr64,class PktMon::Component const * __ptr64 * __ptr64) */

Component ** __cdecl
std::
_Move_unchecked<PktMon::Component_const*___ptr64*___ptr64,PktMon::Component_const*___ptr64*___ptr64>
          (Component **param_1,Component **param_2,Component **param_3)

{
  memmove(param_3,param_1,(longlong)param_2 - (longlong)param_1);
  return (Component **)(((longlong)param_2 - (longlong)param_1) + (longlong)param_3);
}



===== _Reallocate<0> @ 18000e5a0 =====

/* private: void __cdecl std::vector<class PktMon::CompGroup const * __ptr64,class
   std::allocator<class PktMon::CompGroup const * __ptr64> >::_Reallocate<0>(unsigned __int64 &
   __ptr64) __ptr64 */

void __thiscall
std::vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>::
_Reallocate<0>(vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>
               *this,__uint64 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  CompGroup *pCVar4;
  __uint64 _Var5;
  CompGroup **_Dst;
  
  lVar1 = *(longlong *)(this + 8);
  lVar2 = *(longlong *)this;
  if (0x1fffffffffffffff < *param_1) {
LAB_18000e65c:
                    /* WARNING: Subroutine does not return */
    _Throw_bad_array_new_length();
  }
  _Var5 = *param_1 * 8;
  if (_Var5 < 0x1000) {
    _Dst = (CompGroup **)0x0;
    if (_Var5 != 0) {
      _Dst = operator_new(_Var5);
    }
  }
  else {
    if (_Var5 + 0x27 <= _Var5) goto LAB_18000e65c;
    pCVar4 = operator_new(_Var5 + 0x27);
    if (pCVar4 == (CompGroup *)0x0) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _Dst = (CompGroup **)((ulonglong)(pCVar4 + 0x27) & 0xffffffffffffffe0);
    _Dst[-1] = pCVar4;
  }
  memmove(_Dst,*(void **)this,*(longlong *)(this + 8) - *(longlong *)this);
  _Change_array(this,_Dst,lVar1 - lVar2 >> 3,*param_1);
  return;
}



===== _Reallocate<0> @ 18000e668 =====

/* private: void __cdecl std::vector<class PktMon::Component const * __ptr64,class
   std::allocator<class PktMon::Component const * __ptr64> >::_Reallocate<0>(unsigned __int64 &
   __ptr64) __ptr64 */

void __thiscall
std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
_Reallocate<0>(vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
               *this,__uint64 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  Component **_Dst;
  
  lVar1 = *(longlong *)(this + 8);
  lVar2 = *(longlong *)this;
  _Dst = _Allocate_at_least_helper<std::allocator<PktMon::Component_const*___ptr64>_>
                   ((allocator<PktMon::Component_const*___ptr64> *)this,param_1);
  memmove(_Dst,*(void **)this,*(longlong *)(this + 8) - *(longlong *)this);
  vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>::
  _Change_array((vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>
                 *)this,(CompGroup **)_Dst,lVar1 - lVar2 >> 3,*param_1);
  return;
}



===== _Reallocate<0> @ 18000e6d0 =====

/* private: void __cdecl std::vector<class PktMon::Component,class std::allocator<class
   PktMon::Component> >::_Reallocate<0>(unsigned __int64 & __ptr64) __ptr64 */

void __thiscall
std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::_Reallocate<0>
          (vector<PktMon::Component,std::allocator<PktMon::Component>_> *this,__uint64 *param_1)

{
  __uint64 _Var1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  void *pvVar5;
  Component *_Dst;
  
  lVar2 = *(longlong *)(this + 8);
  lVar3 = *(longlong *)this;
  if (0xaaaaaaaaaaaaaaa < *param_1) {
LAB_18000e7a2:
                    /* WARNING: Subroutine does not return */
    _Throw_bad_array_new_length();
  }
  _Var1 = *param_1 * 0x18;
  if (_Var1 < 0x1000) {
    _Dst = (Component *)0x0;
    if (_Var1 != 0) {
      _Dst = operator_new(_Var1);
    }
  }
  else {
    if (_Var1 + 0x27 <= _Var1) goto LAB_18000e7a2;
    pvVar5 = operator_new(_Var1 + 0x27);
    if (pvVar5 == (void *)0x0) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    _Dst = (Component *)((longlong)pvVar5 + 0x27U & 0xffffffffffffffe0);
    *(void **)(_Dst + -8) = pvVar5;
  }
  memmove(_Dst,*(void **)this,*(longlong *)(this + 8) - *(longlong *)this);
  _Change_array(this,_Dst,(lVar2 - lVar3 >> 3) * -0x5555555555555555,*param_1);
  return;
}



===== _Reallocate_for<<lambda_05cef1f6fdf474c9f3ed207deba0f73b>,unsigned_short_const*___ptr64> @ 18000e7b0 =====

/* private: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __ptr64 __cdecl std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::_Reallocate_for<class
   <lambda_05cef1f6fdf474c9f3ed207deba0f73b>,unsigned short const * __ptr64>(unsigned __int64,class
   <lambda_05cef1f6fdf474c9f3ed207deba0f73b>,unsigned short const * __ptr64) __ptr64 */

basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
* __thiscall
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
_Reallocate_for<<lambda_05cef1f6fdf474c9f3ed207deba0f73b>,unsigned_short_const*___ptr64>
          (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
           *this,ulonglong param_1,undefined8 param_3,void *param_4)

{
  ulonglong uVar1;
  void *pvVar2;
  code *pcVar3;
  ushort *_Dst;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar4;
  allocator<unsigned_short> *paVar5;
  void *pvVar6;
  ulonglong uVar7;
  allocator<unsigned_short> *local_res10;
  
  if (0x7ffffffffffffffe < param_1) {
                    /* WARNING: Subroutine does not return */
    _Xlen_string();
  }
  uVar1 = *(ulonglong *)(this + 0x18);
  paVar5 = (allocator<unsigned_short> *)(param_1 | 7);
  local_res10 = (allocator<unsigned_short> *)0x7ffffffffffffffe;
  if (((paVar5 < (allocator<unsigned_short> *)0x7fffffffffffffff) &&
      (uVar1 <= 0x7ffffffffffffffe - (uVar1 >> 1))) &&
     (local_res10 = (allocator<unsigned_short> *)((uVar1 >> 1) + uVar1), local_res10 <= paVar5)) {
    local_res10 = paVar5;
  }
  _Dst = _Allocate_for_capacity<0>(paVar5,(__uint64 *)&local_res10);
  *(ulonglong *)(this + 0x10) = param_1;
  *(allocator<unsigned_short> **)(this + 0x18) = local_res10;
  memcpy(_Dst,param_4,param_1 * 2);
  _Dst[param_1] = 0;
  if (7 < uVar1) {
    pvVar2 = *(void **)this;
    uVar7 = uVar1 * 2 + 2;
    pvVar6 = pvVar2;
    if (0xfff < uVar7) {
      pvVar6 = *(void **)((longlong)pvVar2 + -8);
      uVar7 = uVar1 * 2 + 0x29;
      if (0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar6))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        pbVar4 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                  *)(*pcVar3)();
        return pbVar4;
      }
    }
    operator_delete(pvVar6,uVar7);
  }
  *(ushort **)this = _Dst;
  return (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
          *)this;
}



===== _Reallocate_grow_by<<lambda_7030d12a21dba11210293044e97fe9c7>,unsigned_short_const*___ptr64,unsigned___int64> @ 18000e8ac =====

/* private: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __ptr64 __cdecl std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short>
   >::_Reallocate_grow_by<class <lambda_7030d12a21dba11210293044e97fe9c7>,unsigned short const *
   __ptr64,unsigned __int64>(unsigned __int64,class
   <lambda_7030d12a21dba11210293044e97fe9c7>,unsigned short const * __ptr64,unsigned __int64)
   __ptr64 */

basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
* __thiscall
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
_Reallocate_grow_by<<lambda_7030d12a21dba11210293044e97fe9c7>,unsigned_short_const*___ptr64,unsigned___int64>
          (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
           *this,ulonglong param_1,undefined8 param_3,void *param_4,longlong param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  void *_Src;
  code *pcVar3;
  ushort *_Dst;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar4;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar5;
  allocator<unsigned_short> *paVar6;
  ulonglong uVar7;
  void *pvVar8;
  allocator<unsigned_short> *local_res8;
  
  lVar1 = *(longlong *)(this + 0x10);
  if (0x7ffffffffffffffeU - lVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
    _Xlen_string();
  }
  uVar2 = *(ulonglong *)(this + 0x18);
  paVar6 = (allocator<unsigned_short> *)(lVar1 + param_1 | 7);
  pbVar5 = this;
  local_res8 = (allocator<unsigned_short> *)0x7ffffffffffffffe;
  if (((paVar6 < (allocator<unsigned_short> *)0x7fffffffffffffff) &&
      (pbVar5 = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 *)(uVar2 >> 1), uVar2 <= 0x7ffffffffffffffeU - (longlong)pbVar5)) &&
     (local_res8 = (allocator<unsigned_short> *)(pbVar5 + uVar2),
     (allocator<unsigned_short> *)(pbVar5 + uVar2) <= paVar6)) {
    local_res8 = paVar6;
  }
  _Dst = _Allocate_for_capacity<0>((allocator<unsigned_short> *)pbVar5,(__uint64 *)&local_res8);
  *(ulonglong *)(this + 0x10) = lVar1 + param_1;
  *(allocator<unsigned_short> **)(this + 0x18) = local_res8;
  if (uVar2 < 8) {
    memcpy(_Dst,this,lVar1 * 2);
    memcpy(_Dst + lVar1,param_4,param_5 * 2);
    _Dst[lVar1 + param_5] = 0;
  }
  else {
    _Src = *(void **)this;
    memcpy(_Dst,_Src,lVar1 * 2);
    memcpy(_Dst + lVar1,param_4,param_5 * 2);
    uVar7 = uVar2 * 2 + 2;
    _Dst[lVar1 + param_5] = 0;
    pvVar8 = _Src;
    if (0xfff < uVar7) {
      pvVar8 = *(void **)((longlong)_Src + -8);
      uVar7 = uVar2 * 2 + 0x29;
      if (0x1f < (ulonglong)((longlong)_Src + (-8 - (longlong)pvVar8))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        pbVar4 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                  *)(*pcVar3)();
        return pbVar4;
      }
    }
    operator_delete(pvVar8,uVar7);
  }
  *(ushort **)this = _Dst;
  return (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
          *)this;
}



===== _Reallocate_grow_by<<lambda_f68dc91b63048d8e897893337fb617c1>,unsigned___int64,unsigned___int64,unsigned_short_const*___ptr64,unsigned___int64> @ 18000ea08 =====

/* private: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __ptr64 __cdecl std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short>
   >::_Reallocate_grow_by<class <lambda_f68dc91b63048d8e897893337fb617c1>,unsigned __int64,unsigned
   __int64,unsigned short const * __ptr64,unsigned __int64>(unsigned __int64,class
   <lambda_f68dc91b63048d8e897893337fb617c1>,unsigned __int64,unsigned __int64,unsigned short const
   * __ptr64,unsigned __int64) __ptr64 */

basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
* __thiscall
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
_Reallocate_grow_by<<lambda_f68dc91b63048d8e897893337fb617c1>,unsigned___int64,unsigned___int64,unsigned_short_const*___ptr64,unsigned___int64>
          (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
           *this,ulonglong param_1,undefined8 param_3,allocator<unsigned_short> *param_4,
          longlong param_5,void *param_6,longlong param_7)

{
  size_t _Size;
  longlong lVar1;
  ulonglong uVar2;
  void *pvVar3;
  code *pcVar4;
  ushort *_Dst;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar5;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar6;
  allocator<unsigned_short> *paVar7;
  ulonglong uVar8;
  void *pvVar9;
  allocator<unsigned_short> *local_res20;
  
  lVar1 = *(longlong *)(this + 0x10);
  if (0x7ffffffffffffffeU - lVar1 < param_1) {
    local_res20 = param_4;
                    /* WARNING: Subroutine does not return */
    _Xlen_string();
  }
  uVar2 = *(ulonglong *)(this + 0x18);
  paVar7 = (allocator<unsigned_short> *)(lVar1 + param_1 | 7);
  pbVar6 = this;
  local_res20 = (allocator<unsigned_short> *)0x7ffffffffffffffe;
  if (((paVar7 < (allocator<unsigned_short> *)0x7fffffffffffffff) &&
      (pbVar6 = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 *)(uVar2 >> 1), uVar2 <= 0x7ffffffffffffffeU - (longlong)pbVar6)) &&
     (local_res20 = (allocator<unsigned_short> *)(pbVar6 + uVar2),
     (allocator<unsigned_short> *)(pbVar6 + uVar2) <= paVar7)) {
    local_res20 = paVar7;
  }
  _Dst = _Allocate_for_capacity<0>((allocator<unsigned_short> *)pbVar6,(__uint64 *)&local_res20);
  *(allocator<unsigned_short> **)(this + 0x18) = local_res20;
  *(ulonglong *)(this + 0x10) = lVar1 + param_1;
  _Size = (lVar1 - param_5) * 2 + 2;
  if (uVar2 < 8) {
    memcpy(_Dst,param_6,param_7 * 2);
    memcpy(_Dst + param_7,this + param_5 * 2,_Size);
  }
  else {
    pvVar3 = *(void **)this;
    memcpy(_Dst,param_6,param_7 * 2);
    memcpy(_Dst + param_7,(void *)((longlong)pvVar3 + param_5 * 2),_Size);
    uVar8 = uVar2 * 2 + 2;
    pvVar9 = pvVar3;
    if (0xfff < uVar8) {
      pvVar9 = *(void **)((longlong)pvVar3 + -8);
      uVar8 = uVar2 * 2 + 0x29;
      if (0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar9))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar4 = (code *)swi(3);
        pbVar5 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                  *)(*pcVar4)();
        return pbVar5;
      }
    }
    operator_delete(pvVar9,uVar8);
  }
  *(ushort **)this = _Dst;
  return (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
          *)this;
}



===== _Uninitialized_move<PktMon::Component_const*___ptr64*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_> @ 18000eb58 =====

/* class PktMon::Component const * __ptr64 * __ptr64 __cdecl std::_Uninitialized_move<class
   PktMon::Component const * __ptr64 * __ptr64,class std::allocator<class PktMon::Component const *
   __ptr64> >(class PktMon::Component const * __ptr64 * __ptr64 const,class PktMon::Component const
   * __ptr64 * __ptr64 const,class PktMon::Component const * __ptr64 * __ptr64,class
   std::allocator<class PktMon::Component const * __ptr64> & __ptr64) */

Component ** __cdecl
std::
_Uninitialized_move<PktMon::Component_const*___ptr64*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
          (Component **param_1,Component **param_2,Component **param_3,
          allocator<PktMon::Component_const*___ptr64> *param_4)

{
  memmove(param_3,param_1,(longlong)param_2 - (longlong)param_1);
  return param_3 + ((longlong)param_2 - (longlong)param_1 >> 3);
}



===== begin<std::set<long,std::less<long>,std::allocator<long>_>_> @ 18000eb94 =====

/* class std::_Tree_const_iterator<class std::_Tree_val<struct std::_Tree_simple_types<long> > >
   __cdecl std::begin<class std::set<long,struct std::less<long>,class std::allocator<long> >
   >(class std::set<long,struct std::less<long>,class std::allocator<long> > & __ptr64) */

set<long,std::less<long>,std::allocator<long>_> * __cdecl
std::begin<std::set<long,std::less<long>,std::allocator<long>_>_>
          (set<long,std::less<long>,std::allocator<long>_> *param_1)

{
  undefined8 *in_RDX;
  
  *(undefined8 *)param_1 = *(undefined8 *)*in_RDX;
  return param_1;
}



===== lower_bound<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>_>,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>,<lambda_aa490cf9a2687414692223e5a1c065db>_> @ 18000eba8 =====

undefined8 *
std::
lower_bound<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>_>,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>,<lambda_aa490cf9a2687414692223e5a1c065db>_>
          (undefined8 *param_1,longlong *param_2,longlong *param_3,undefined8 *param_4)

{
  char cVar1;
  ushort uVar2;
  longlong *plVar3;
  longlong *plVar4;
  ushort *puVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  
  uVar12 = 0;
  plVar3 = param_2;
  while (plVar3 != param_3) {
    plVar4 = (longlong *)plVar3[2];
    uVar12 = uVar12 + 1;
    if (*(char *)((longlong)plVar4 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar4 + 0x19);
      plVar3 = plVar4;
      plVar4 = (longlong *)*plVar4;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar4 + 0x19);
        plVar3 = plVar4;
        plVar4 = (longlong *)*plVar4;
      }
    }
    else {
      plVar4 = plVar3;
      plVar3 = (longlong *)plVar3[1];
      while ((*(char *)((longlong)plVar3 + 0x19) == '\0' && (plVar4 == (longlong *)plVar3[2]))) {
        plVar4 = plVar3;
        plVar3 = (longlong *)plVar3[1];
      }
    }
  }
  do {
    if ((longlong)uVar12 < 1) {
      *param_1 = param_2;
      return param_1;
    }
    uVar9 = uVar12 >> 1;
    plVar3 = param_2;
    if (uVar9 != 0) {
      uVar10 = uVar9;
      do {
        plVar4 = (longlong *)plVar3[2];
        if (*(char *)((longlong)plVar4 + 0x19) == '\0') {
          cVar1 = *(char *)(*plVar4 + 0x19);
          plVar3 = plVar4;
          plVar4 = (longlong *)*plVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*plVar4 + 0x19);
            plVar3 = plVar4;
            plVar4 = (longlong *)*plVar4;
          }
        }
        else {
          plVar4 = (longlong *)plVar3[1];
          plVar6 = plVar3;
          while ((plVar3 = plVar4, *(char *)((longlong)plVar3 + 0x19) == '\0' &&
                 (plVar6 == (longlong *)plVar3[2]))) {
            plVar4 = (longlong *)plVar3[1];
            plVar6 = plVar3;
          }
        }
        uVar10 = uVar10 - 1;
      } while (0 < (longlong)uVar10);
    }
    puVar5 = (ushort *)(plVar3 + 4);
    uVar10 = plVar3[6];
    if (7 < (ulonglong)plVar3[7]) {
      puVar5 = *(ushort **)puVar5;
    }
    uVar11 = param_4[2];
    if (uVar10 <= (ulonglong)param_4[2]) {
      uVar11 = uVar10;
    }
    puVar7 = param_4;
    if (7 < (ulonglong)param_4[3]) {
      puVar7 = (undefined8 *)*param_4;
    }
    uVar13 = uVar11;
    if (uVar10 < uVar11) {
      uVar13 = uVar10;
    }
    if (uVar13 != 0) {
      lVar8 = (longlong)puVar7 - (longlong)puVar5;
      do {
        uVar2 = *(ushort *)((longlong)puVar5 + lVar8);
        if (uVar2 != *puVar5) {
          if ((int)((-(uint)(uVar2 < *puVar5) & 0xfffffffe) + 1) < 1) goto LAB_18000ece9;
          goto LAB_18000ecce;
        }
        puVar5 = puVar5 + 1;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
    if (uVar10 < uVar11) {
LAB_18000ecce:
      param_2 = (longlong *)plVar3[2];
      if (*(char *)((longlong)param_2 + 0x19) == '\0') {
        cVar1 = *(char *)(*param_2 + 0x19);
        plVar3 = (longlong *)*param_2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*plVar3 + 0x19);
          param_2 = plVar3;
          plVar3 = (longlong *)*plVar3;
        }
      }
      else {
        param_2 = (longlong *)plVar3[1];
        while ((*(char *)((longlong)param_2 + 0x19) == '\0' && (plVar3 == (longlong *)param_2[2])))
        {
          plVar3 = param_2;
          param_2 = (longlong *)param_2[1];
        }
      }
      uVar12 = uVar12 + (-1 - uVar9);
    }
    else {
LAB_18000ece9:
      uVar12 = uVar9;
    }
  } while( true );
}



===== try_emplace<unsigned_long&___ptr64> @ 18000ed5c =====

/* public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<unsigned long const ,class PktMon::GatewayGroup> > >
   >,bool> __cdecl std::map<unsigned long,class PktMon::GatewayGroup,struct std::less<unsigned
   long>,class std::allocator<struct std::pair<unsigned long const ,class PktMon::GatewayGroup> >
   >::try_emplace<unsigned long & __ptr64>(unsigned long const & __ptr64,unsigned long & __ptr64)
   __ptr64 */

ulong * __thiscall
std::
map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
::try_emplace<unsigned_long&___ptr64>
          (map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
           *this,ulong *param_1,ulong *param_2)

{
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  *p_Var1;
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  *p_Var2;
  longlong *plVar3;
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  *p_Var4;
  undefined1 uVar5;
  undefined4 *in_R9;
  map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
  *local_48;
  ulonglong uStack_40;
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  *local_38;
  ulonglong uStack_30;
  
  p_Var1 = *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
             **)this;
  local_38 = *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
               **)(p_Var1 + 8);
  uVar5 = 0;
  uStack_30 = 0;
  p_Var4 = p_Var1;
  if (local_38[0x19] ==
      (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
       )0x0) {
    p_Var2 = local_38;
    do {
      local_38 = p_Var2;
      if (*param_2 <= *(uint *)(local_38 + 0x20)) {
        p_Var2 = *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                   **)local_38;
        p_Var4 = local_38;
      }
      else {
        p_Var2 = *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                   **)(local_38 + 0x10);
      }
      uStack_30 = (ulonglong)(*param_2 <= *(uint *)(local_38 + 0x20));
    } while (p_Var2[0x19] ==
             (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
              )0x0);
  }
  if ((p_Var4[0x19] !=
       (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
        )0x0) || (*param_2 < *(uint *)(p_Var4 + 0x20))) {
    if (*(longlong *)(this + 8) == 0x333333333333333) {
                    /* WARNING: Subroutine does not return */
      _Throw_tree_length_error();
    }
    uStack_40 = 0;
    local_48 = this;
    plVar3 = operator_new(0x50);
    *(ulong *)(plVar3 + 4) = *param_2;
    *(undefined4 *)(plVar3 + 6) = *in_R9;
    *(undefined1 *)((longlong)plVar3 + 0x34) = 0;
    plVar3[5] = (longlong)&PktMon::GatewayGroup::_vftable_;
    plVar3[7] = 0;
    plVar3[8] = 0;
    plVar3[9] = 0;
    *plVar3 = (longlong)p_Var1;
    plVar3[1] = (longlong)p_Var1;
    plVar3[2] = (longlong)p_Var1;
    *(undefined2 *)(plVar3 + 3) = 0;
    local_48 = (map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
                *)local_38;
    uStack_40 = uStack_30;
    p_Var4 = _Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
             ::_Insert_node((_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
                             *)this,&local_48);
    uVar5 = 1;
  }
  *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
    **)param_1 = p_Var4;
  *(undefined1 *)(param_1 + 2) = uVar5;
  return param_1;
}



===== try_emplace<unsigned_long&___ptr64> @ 18000ee88 =====

/* public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<unsigned long const ,class PktMon::NicGroup> > > >,bool>
   __cdecl std::map<unsigned long,class PktMon::NicGroup,struct std::less<unsigned long>,class
   std::allocator<struct std::pair<unsigned long const ,class PktMon::NicGroup> >
   >::try_emplace<unsigned long & __ptr64>(unsigned long const & __ptr64,unsigned long & __ptr64)
   __ptr64 */

ulong * __thiscall
std::
map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
::try_emplace<unsigned_long&___ptr64>
          (map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
           *this,ulong *param_1,ulong *param_2)

{
  _Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *p_Var1;
  undefined8 uVar2;
  void *pvVar3;
  _Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *p_Var4;
  longlong lVar5;
  _Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *p_Var6;
  undefined1 uVar7;
  piecewise_construct_t *in_R9;
  tuple<unsigned_long&___ptr64> local_res8 [8];
  _Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
  local_48 [8];
  void *local_40;
  _Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *local_38;
  undefined8 uStack_30;
  
  uVar7 = 0;
  p_Var1 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)this;
  uStack_30 = 0;
  local_38 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)
              (p_Var1 + 8);
  p_Var6 = p_Var1;
  if (local_38[0x19] ==
      (_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>)0x0) {
    p_Var4 = local_38;
    do {
      local_38 = p_Var4;
      if (*param_2 <= *(uint *)(local_38 + 0x20)) {
        p_Var4 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)
                  local_38;
        p_Var6 = local_38;
      }
      else {
        p_Var4 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)
                  (local_38 + 0x10);
      }
      uStack_30 = (ulonglong)(*param_2 <= *(uint *)(local_38 + 0x20));
    } while (p_Var4[0x19] ==
             (_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>)0x0);
  }
  if ((p_Var6[0x19] !=
       (_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>)0x0) ||
     (*param_2 < *(uint *)(p_Var6 + 0x20))) {
    if (*(longlong *)(this + 8) == 0x1af286bca1af286) {
                    /* WARNING: Subroutine does not return */
      _Throw_tree_length_error();
    }
    local_58 = (_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *)param_2
    ;
    lVar5 = _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
            ::
            _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_><std::piecewise_construct_t_const&___ptr64,std::tuple<unsigned_long_const&___ptr64>,std::tuple<unsigned_long&___ptr64>_>
                      (local_48,(allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>
                                 *)this,p_Var1,in_R9,
                       (tuple<unsigned_long_const&___ptr64> *)&local_58,local_res8);
    pvVar3 = local_40;
    uVar2 = *(undefined8 *)(lVar5 + 8);
    *(undefined8 *)(lVar5 + 8) = 0;
    if (local_40 != (void *)0x0) {
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)((longlong)local_40 + 0x78));
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)((longlong)pvVar3 + 0x60));
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)((longlong)pvVar3 + 0x48));
      if (local_40 != (void *)0x0) {
        operator_delete(local_40,0x98);
      }
    }
    local_58 = local_38;
    uStack_50 = (undefined4)uStack_30;
    uStack_4c = uStack_30._4_4_;
    p_Var6 = (_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> *)
             _Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
             ::_Insert_node((_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
                             *)this,&local_58,uVar2);
    uVar7 = 1;
  }
  *(undefined1 *)(param_1 + 2) = uVar7;
  *(_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64> **)param_1 = p_Var6;
  return param_1;
}



===== try_emplace<unsigned_long&___ptr64> @ 18000efc8 =====

/* public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<unsigned long const ,class PktMon::VMSwitch> > > >,bool>
   __cdecl std::map<unsigned long,class PktMon::VMSwitch,struct std::less<unsigned long>,class
   std::allocator<struct std::pair<unsigned long const ,class PktMon::VMSwitch> >
   >::try_emplace<unsigned long & __ptr64>(unsigned long const & __ptr64,unsigned long & __ptr64)
   __ptr64 */

ulong * __thiscall
std::
map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
::try_emplace<unsigned_long&___ptr64>
          (map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
           *this,ulong *param_1,ulong *param_2)

{
  _Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *p_Var1;
  undefined8 uVar2;
  void *pvVar3;
  _Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *p_Var4;
  longlong lVar5;
  _Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *p_Var6;
  undefined1 uVar7;
  piecewise_construct_t *in_R9;
  tuple<unsigned_long&___ptr64> local_res8 [8];
  _Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
  local_48 [8];
  void *local_40;
  _Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *local_38;
  undefined8 uStack_30;
  
  uVar7 = 0;
  p_Var1 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)this;
  uStack_30 = 0;
  local_38 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)
              (p_Var1 + 8);
  p_Var6 = p_Var1;
  if (local_38[0x19] ==
      (_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>)0x0) {
    p_Var4 = local_38;
    do {
      local_38 = p_Var4;
      if (*param_2 <= *(uint *)(local_38 + 0x20)) {
        p_Var4 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)
                  local_38;
        p_Var6 = local_38;
      }
      else {
        p_Var4 = *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)
                  (local_38 + 0x10);
      }
      uStack_30 = (ulonglong)(*param_2 <= *(uint *)(local_38 + 0x20));
    } while (p_Var4[0x19] ==
             (_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>)0x0);
  }
  if ((p_Var6[0x19] !=
       (_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>)0x0) ||
     (*param_2 < *(uint *)(p_Var6 + 0x20))) {
    if (*(longlong *)(this + 8) == 0x1c71c71c71c71c7) {
                    /* WARNING: Subroutine does not return */
      _Throw_tree_length_error();
    }
    local_58 = (_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *)param_2
    ;
    lVar5 = _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
            ::
            _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_><std::piecewise_construct_t_const&___ptr64,std::tuple<unsigned_long_const&___ptr64>,std::tuple<unsigned_long&___ptr64>_>
                      (local_48,(allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>
                                 *)this,p_Var1,in_R9,
                       (tuple<unsigned_long_const&___ptr64> *)&local_58,local_res8);
    pvVar3 = local_40;
    uVar2 = *(undefined8 *)(lVar5 + 8);
    *(undefined8 *)(lVar5 + 8) = 0;
    if (local_40 != (void *)0x0) {
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)((longlong)local_40 + 0x78));
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)((longlong)pvVar3 + 0x60));
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)((longlong)pvVar3 + 0x38));
      if (local_40 != (void *)0x0) {
        operator_delete(local_40,0x90);
      }
    }
    local_58 = local_38;
    uStack_50 = (undefined4)uStack_30;
    uStack_4c = uStack_30._4_4_;
    p_Var6 = (_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> *)
             _Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
             ::_Insert_node((_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
                             *)this,&local_58,uVar2);
    uVar7 = 1;
  }
  *(undefined1 *)(param_1 + 2) = uVar7;
  *(_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64> **)param_1 = p_Var6;
  return param_1;
}



===== basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_> @ 18000f108 =====

/* public: __cdecl std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> >::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >(class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const & __ptr64) __ptr64
    */

basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_> *
__thiscall
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
           *this,basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                 *param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ushort *_Dst;
  allocator<unsigned_short> *paVar3;
  allocator<unsigned_short> *local_res8;
  
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  uVar1 = *(ulonglong *)(param_1 + 0x10);
  if (7 < *(ulonglong *)(param_1 + 0x18)) {
    param_1 = *(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                **)param_1;
  }
  if (0x7ffffffffffffffe < uVar1) {
                    /* WARNING: Subroutine does not return */
    _Xlen_string();
  }
  *(undefined8 *)(this + 0x18) = 7;
  if (uVar1 < 8) {
    *(ulonglong *)(this + 0x10) = uVar1;
    uVar2 = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)this = *(undefined8 *)param_1;
    *(undefined8 *)(this + 8) = uVar2;
  }
  else {
    paVar3 = (allocator<unsigned_short> *)(uVar1 | 7);
    local_res8 = (allocator<unsigned_short> *)0x7ffffffffffffffe;
    if ((paVar3 < (allocator<unsigned_short> *)0x7fffffffffffffff) &&
       (local_res8 = paVar3, paVar3 < (allocator<unsigned_short> *)0xa)) {
      local_res8 = (allocator<unsigned_short> *)0xa;
    }
    _Dst = _Allocate_for_capacity<0>(paVar3,(__uint64 *)&local_res8);
    *(allocator<unsigned_short> **)(this + 0x18) = local_res8;
    *(ushort **)this = _Dst;
    *(ulonglong *)(this + 0x10) = uVar1;
    memcpy(_Dst,param_1,uVar1 * 2 + 2);
  }
  return this;
}



===== map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_> @ 18000f1d0 =====

/* public: __cdecl std::map<class std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> > const ,class std::basic_string<unsigned
   short,struct std::char_traits<unsigned short>,class std::allocator<unsigned short> > const
   ,struct std::less<class std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> > const >,class std::allocator<struct std::pair<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const > > >::map<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,struct
   std::less<class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const >,class std::allocator<struct std::pair<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const > > >(class
   std::initializer_list<struct std::pair<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const > >) __ptr64 */

undefined8 * __thiscall
std::
map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
::
map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
          (undefined8 param_1,undefined8 *param_2)

{
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar1;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar2;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *this;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar6;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  local_48 [32];
  
  DAT_180021d00 =
       (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
        *)0x0;
  DAT_180021d08 = 0;
  pbVar3 = operator_new(0x60);
  *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_> **
   )pbVar3 = pbVar3;
  *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_> **
   )(pbVar3 + 8) = pbVar3;
  *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_> **
   )(pbVar3 + 0x10) = pbVar3;
  *(undefined2 *)(pbVar3 + 0x18) = 0x101;
  pbVar6 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
            *)*param_2;
  pbVar1 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
            *)param_2[1];
  pbVar2 = pbVar3;
  do {
    if (pbVar6 == pbVar1) {
      DAT_180021d00 = pbVar2;
      return &DAT_180021d00;
    }
    DAT_180021d00 = pbVar2;
    puVar4 = operator_new(0x60);
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(puVar4 + 4),pbVar6);
    this = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            *)(puVar4 + 8);
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              (this,pbVar6 + 0x20);
    *puVar4 = pbVar2;
    puVar4[1] = pbVar2;
    puVar4[2] = pbVar2;
    *(undefined2 *)(puVar4 + 3) = 0;
    puVar5 = (undefined4 *)
             _Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
             ::
             _Find_hint<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_>
                       ((_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
                         *)this,local_48,pbVar3);
    local_58 = *(undefined8 *)(puVar5 + 4);
    if ((char)local_58 == '\0') {
      if (DAT_180021d08 == 0x2aaaaaaaaaaaaaa) {
                    /* WARNING: Subroutine does not return */
        _Throw_tree_length_error();
      }
      local_68 = *puVar5;
      uStack_64 = puVar5[1];
      uStack_60 = puVar5[2];
      uStack_5c = puVar5[3];
      _Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
      ::_Insert_node((_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
                      *)&DAT_180021d00,&local_68,puVar4);
    }
    else if (puVar4 != (undefined8 *)0x0) {
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)(puVar4 + 8));
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)(puVar4 + 4));
      operator_delete(puVar4,0x60);
    }
    pbVar6 = pbVar6 + 0x40;
    pbVar2 = DAT_180021d00;
  } while( true );
}



===== vector<unsigned_char,std::allocator<unsigned_char>_> @ 18000f368 =====

/* public: __cdecl std::vector<unsigned char,class std::allocator<unsigned char> >::vector<unsigned
   char,class std::allocator<unsigned char> >(class std::vector<unsigned char,class
   std::allocator<unsigned char> > const & __ptr64) __ptr64 */

vector<unsigned_char,std::allocator<unsigned_char>_> * __thiscall
std::vector<unsigned_char,std::allocator<unsigned_char>_>::
vector<unsigned_char,std::allocator<unsigned_char>_>
          (vector<unsigned_char,std::allocator<unsigned_char>_> *this,
          vector<unsigned_char,class_std::allocator<unsigned_char>_> *param_1)

{
  longlong lVar1;
  longlong lVar2;
  void *_Dst;
  undefined8 local_res8;
  
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  if (*(longlong *)(param_1 + 8) - *(longlong *)param_1 != 0) {
    _Buy_nonzero(this,*(longlong *)(param_1 + 8) - *(longlong *)param_1);
    lVar1 = *(longlong *)(param_1 + 8);
    lVar2 = *(longlong *)param_1;
    _Dst = *(void **)this;
    memmove(_Dst,*(void **)param_1,lVar1 - lVar2);
    local_res8 = 0;
    *(longlong *)(this + 8) = (lVar1 - lVar2) + (longlong)_Dst;
    _Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>::
    ~_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>
              ((_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *)
               &local_res8);
  }
  return this;
}



===== CompList @ 18000f3f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: __cdecl PktMon::CompList::CompList(class std::vector<unsigned char,class
   std::allocator<unsigned char> > && __ptr64,bool) __ptr64 */

CompList * __thiscall
PktMon::CompList::CompList
          (CompList *this,vector<unsigned_char,std::allocator<unsigned_char>_> *param_1,bool param_2
          )

{
  vector<PktMon::Component,std::allocator<PktMon::Component>_> *this_00;
  CompList *pCVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  void *pvVar6;
  _PKTMON_PROPERTY_OUT *p_Var7;
  undefined8 *puVar8;
  CompGroup *pCVar9;
  short *****pppppsVar10;
  _PKTMON_COMPONENT_PROPERTY_ID _Var11;
  longlong lVar12;
  Component *pCVar13;
  uint uVar14;
  longlong lVar15;
  _PKTMON_COMPONENT_OUT *p_Var16;
  uint uVar17;
  undefined1 auStack_128 [32];
  CompList *local_108;
  undefined8 local_100;
  CompList *local_f8;
  short *****local_f0;
  undefined8 uStack_e8;
  longlong local_e0;
  ulonglong local_d8;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  local_d0 [56];
  undefined8 local_98;
  undefined **local_88;
  CompList *local_80;
  undefined ***local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_128;
  uVar14 = 0;
  bVar4 = false;
  local_100 = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
               *)((ulonglong)local_100 & 0xffffffff00000000);
  local_f8 = this;
  std::vector<unsigned_char,std::allocator<unsigned_char>_>::
  vector<unsigned_char,std::allocator<unsigned_char>_>
            ((vector<unsigned_char,std::allocator<unsigned_char>_> *)this,
             (vector<unsigned_char,class_std::allocator<unsigned_char>_> *)param_1);
  this_00 = (vector<PktMon::Component,std::allocator<PktMon::Component>_> *)(this + 0x18);
  *(undefined8 *)this_00 = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  pCVar1 = this + 0x30;
  *(undefined8 *)pCVar1 = 0;
  *(undefined8 *)(this + 0x38) = 0;
  local_108 = pCVar1;
  pvVar6 = operator_new(0x50);
  *(void **)pvVar6 = pvVar6;
  *(void **)((longlong)pvVar6 + 8) = pvVar6;
  *(void **)((longlong)pvVar6 + 0x10) = pvVar6;
  *(undefined2 *)((longlong)pvVar6 + 0x18) = 0x101;
  *(void **)pCVar1 = pvVar6;
  pCVar1 = this + 0x40;
  *(undefined8 *)pCVar1 = 0;
  *(undefined8 *)(this + 0x48) = 0;
  local_108 = pCVar1;
  pvVar6 = operator_new(0x90);
  *(void **)pvVar6 = pvVar6;
  *(void **)((longlong)pvVar6 + 8) = pvVar6;
  *(void **)((longlong)pvVar6 + 0x10) = pvVar6;
  *(undefined2 *)((longlong)pvVar6 + 0x18) = 0x101;
  *(void **)pCVar1 = pvVar6;
  pCVar1 = this + 0x50;
  *(undefined8 *)pCVar1 = 0;
  *(undefined8 *)(this + 0x58) = 0;
  local_108 = pCVar1;
  pvVar6 = operator_new(0x98);
  *(void **)pvVar6 = pvVar6;
  *(void **)((longlong)pvVar6 + 8) = pvVar6;
  *(void **)((longlong)pvVar6 + 0x10) = pvVar6;
  *(undefined2 *)((longlong)pvVar6 + 0x18) = 0x101;
  *(void **)pCVar1 = pvVar6;
  *(undefined4 *)(this + 0x68) = 0xffffffff;
  this[0x6c] = (CompList)0x0;
  *(undefined ***)(this + 0x60) = &GatewayGroup::_vftable_;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0;
  uVar17 = *(uint *)(*(longlong *)this + 4);
  local_108 = (CompList *)(ulonglong)uVar17;
  p_Var16 = (_PKTMON_COMPONENT_OUT *)(*(longlong *)this + 0x10);
  local_100 = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
               *)local_108;
  if ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
       *)((*(longlong *)(this + 0x28) - *(longlong *)this_00 >> 3) * -0x5555555555555555) <
      local_108) {
    std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::_Reallocate<0>
              (this_00,&local_100);
  }
  local_88 = &PTR__Copy_18001a0e8;
  local_80 = this;
  local_50 = &local_88;
  if (uVar17 != 0) {
    do {
      bVar5 = false;
      pCVar13 = *(Component **)(this + 0x20);
      if (pCVar13 == *(Component **)(this + 0x28)) {
        std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::
        _Emplace_reallocate<_PKTMON_COMPONENT_OUT_const&___ptr64>(this_00,pCVar13,p_Var16);
      }
      else {
        *(_PKTMON_COMPONENT_OUT **)pCVar13 = p_Var16;
        *(Component **)(pCVar13 + 8) = pCVar13;
        *(Component **)(pCVar13 + 0x10) = pCVar13;
        *(longlong *)(this + 0x20) = *(longlong *)(this + 0x20) + 0x18;
      }
      pCVar13 = (Component *)(*(longlong *)(this + 0x20) + -0x18);
      uVar17 = 0xffffffff;
      iVar2 = *(int *)(*(longlong *)pCVar13 + 0x180);
      if (iVar2 < 10) {
        if ((iVar2 == 9) || (iVar2 == 2)) {
LAB_18000f5dc:
          _Var11 = 1;
        }
        else {
          if ((iVar2 != 5) && (iVar2 != 6)) {
            if (iVar2 == 7) goto LAB_18000f5dc;
            if (iVar2 != 8) {
LAB_18000f5d5:
              _Var11 = 2;
              goto LAB_18000f5f1;
            }
          }
          _Var11 = 0xb;
        }
LAB_18000f5f1:
        p_Var7 = Component::FindProperty(pCVar13,_Var11);
        if (p_Var7 != (_PKTMON_PROPERTY_OUT *)0x0) {
          uVar17 = *(uint *)(p_Var7 + 6);
        }
      }
      else {
        if (iVar2 == 0xb) {
          _Var11 = 0xe;
          goto LAB_18000f5f1;
        }
        if ((iVar2 != 0xc) && (iVar2 != 0xd)) {
          if (iVar2 == 0xe) goto LAB_18000f5dc;
          if (iVar2 != 0xf) goto LAB_18000f5d5;
        }
        uVar17 = -iVar2 - 1;
      }
      if (1 < uVar17) {
        if (*(int *)(*(longlong *)pCVar13 + 0x180) == 4) {
          local_f0 = (short *****)0x0;
          uStack_e8 = 0;
          local_e0 = 0;
          local_d8 = 0;
          std::
          basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          ::_Construct<1,unsigned_short_const*___ptr64>
                    ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                      *)&local_f0,(ushort *)L"RDMANDK",7);
          local_100 = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                       *)(CONCAT44(local_100._4_4_,uVar14) | 1);
          puVar8 = (undefined8 *)Component::GetDescription(pCVar13,SUB81(local_d0,0));
          uVar14 = 3;
          bVar4 = true;
          pppppsVar10 = (short *****)&local_f0;
          if (7 < local_d8) {
            pppppsVar10 = local_f0;
          }
          lVar15 = puVar8[2];
          if (7 < (ulonglong)puVar8[3]) {
            puVar8 = (undefined8 *)*puVar8;
          }
          if (lVar15 == local_e0) {
            if (lVar15 != 0) {
              lVar12 = (longlong)puVar8 - (longlong)pppppsVar10;
              do {
                if (*(short *)((longlong)pppppsVar10 + lVar12) != *(short *)pppppsVar10)
                goto LAB_18000f6a1;
                pppppsVar10 = (short *****)((longlong)pppppsVar10 + 2);
                lVar15 = lVar15 + -1;
              } while (lVar15 != 0);
            }
            bVar5 = true;
          }
        }
LAB_18000f6a1:
        if ((uVar14 & 2) != 0) {
          uVar14 = uVar14 & 0xfffffffd;
          std::
          basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          ::
          ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                    (local_d0);
        }
        if (bVar4) {
          uVar14 = uVar14 & 0xfffffffe;
          bVar4 = false;
          std::
          basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          ::
          ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                    ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                      *)&local_f0);
        }
        if (!bVar5) {
          pCVar9 = FindOrCreateGroup(this,uVar17,
                                     *(_PKTMON_COMPONENT_TYPE *)(*(longlong *)pCVar13 + 0x180));
          pcVar3 = (code *)**(undefined8 **)pCVar9;
          local_100 = local_d0;
          local_98 = 0;
          if (local_50 != (undefined ***)0x0) {
            local_98 = (*(code *)**local_50)(local_50,local_d0);
          }
          (*pcVar3)(pCVar9,pCVar13,local_d0);
        }
      }
      p_Var16 = p_Var16 + 0x13b0;
      local_108 = local_108 + -1;
    } while (local_108 != (CompList *)0x0);
    local_108 = (CompList *)0x0;
  }
  if (local_50 != (undefined ***)0x0) {
    (*(code *)(*local_50)[4])
              (local_50,CONCAT71((int7)((ulonglong)&local_88 >> 8),local_50 != &local_88));
  }
  return this;
}



===== InvalidComponentId @ 18000f790 =====

/* public: __cdecl PktMon::InvalidComponentId::InvalidComponentId(class PktMon::InvalidComponentId
   const & __ptr64) __ptr64 */

InvalidComponentId * __thiscall
PktMon::InvalidComponentId::InvalidComponentId(InvalidComponentId *this,InvalidComponentId *param_1)

{
  *(undefined ***)this = std::exception::_vftable_;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  return this;
}



===== InvalidComponentId @ 18000f7e4 =====

/* public: __cdecl PktMon::InvalidComponentId::InvalidComponentId(long) __ptr64 */

InvalidComponentId * __thiscall
PktMon::InvalidComponentId::InvalidComponentId(InvalidComponentId *this,long param_1)

{
  char *local_18;
  undefined1 local_10;
  undefined4 local_f;
  undefined2 local_b;
  undefined1 local_9;
  
  local_10 = 1;
  *(undefined ***)this = std::exception::_vftable_;
  local_18 = "Invalid component ID.";
  local_f = 0;
  local_b = 0;
  local_9 = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(&local_18);
  *(long *)(this + 0x18) = param_1;
  *(undefined ***)this = &_vftable_;
  return this;
}



===== PktMonError @ 18000f854 =====

/* public: __cdecl PktMon::PktMonError::PktMonError(class PktMon::PktMonError const & __ptr64)
   __ptr64 */

PktMonError * __thiscall PktMon::PktMonError::PktMonError(PktMonError *this,PktMonError *param_1)

{
  *(undefined ***)this = std::exception::_vftable_;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  *(undefined ***)this = &_vftable_;
  return this;
}



===== Property @ 18000f898 =====

/* public: __cdecl NetSetup2::Property::Property(struct _NETSETUPPROPERTY const & __ptr64) __ptr64
    */

Property * __thiscall NetSetup2::Property::Property(Property *this,_NETSETUPPROPERTY *param_1)

{
  vector<unsigned_char,std::allocator<unsigned_char>_> *this_00;
  uint uVar1;
  void *_Src;
  void *_Dst;
  undefined8 uVar2;
  ulonglong uVar3;
  Property *local_res8;
  
  uVar2 = *(undefined8 *)(param_1 + 8);
  this_00 = (vector<unsigned_char,std::allocator<unsigned_char>_> *)(this + 0x18);
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(undefined8 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x20);
  uVar1 = *(uint *)(param_1 + 0x24);
  uVar3 = (ulonglong)uVar1;
  _Src = *(void **)(param_1 + 0x28);
  *(undefined8 *)this_00 = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  if (uVar3 != 0) {
    local_res8 = this;
    std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Buy_nonzero(this_00,uVar3);
    _Dst = *(void **)this_00;
    memmove(_Dst,_Src,(ulonglong)uVar1);
    local_res8 = (Property *)0x0;
    *(ulonglong *)(this + 0x20) = uVar3 + (longlong)_Dst;
    std::_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>::
    ~_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_>
              ((_Tidy_guard<std::vector<unsigned_char,std::allocator<unsigned_char>_>_> *)
               &local_res8);
  }
  return this;
}



===== UsageIndexes @ 18000f934 =====

/* public: __cdecl wil::details_abi::UsageIndexes::UsageIndexes(void) __ptr64 */

UsageIndexes * __thiscall wil::details_abi::UsageIndexes::UsageIndexes(UsageIndexes *this)

{
  *(undefined4 *)this = 0x40000;
  this[4] = (UsageIndexes)0x1;
  this[8] = (UsageIndexes)0x0;
  *(undefined2 *)(this + 0x38) = 0;
  this[0x3a] = (UsageIndexes)0x0;
  *(undefined2 *)(this + 6) = 4;
  *(undefined8 *)(this + 0x10) = 4;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x46) = 4;
  *(undefined4 *)(this + 0x40) = 0x40000;
  this[0x44] = (UsageIndexes)0x1;
  this[0x48] = (UsageIndexes)0x2;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x50) = 8;
  *(undefined2 *)(this + 0x78) = 0;
  this[0x7a] = (UsageIndexes)0x0;
  *(undefined4 *)(this + 0x80) = 0x40000;
  this[0x84] = (UsageIndexes)0x1;
  *(undefined2 *)(this + 0x86) = 0;
  this[0x88] = (UsageIndexes)0x1;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined2 *)(this + 0xb8) = 0;
  this[0xba] = (UsageIndexes)0x0;
  return this;
}



===== bad_optional_access @ 18000f9f4 =====

/* public: __cdecl std::bad_optional_access::bad_optional_access(class std::bad_optional_access
   const & __ptr64) __ptr64 */

bad_optional_access * __thiscall
std::bad_optional_access::bad_optional_access
          (bad_optional_access *this,bad_optional_access *param_1)

{
  *(undefined ***)this = exception::_vftable_;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  __std_exception_copy(param_1 + 8);
  *(undefined ***)this = &_vftable_;
  return this;
}



===== bad_optional_access @ 18000fa38 =====

/* public: __cdecl std::bad_optional_access::bad_optional_access(void) __ptr64 */

bad_optional_access * __thiscall
std::bad_optional_access::bad_optional_access(bad_optional_access *this)

{
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined ***)this = &_vftable_;
  return this;
}



===== ~_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_> @ 18000fa54 =====

/* public: __cdecl std::_Alloc_construct_ptr<class std::allocator<struct std::_Tree_node<long,void *
   __ptr64> > >::~_Alloc_construct_ptr<class std::allocator<struct std::_Tree_node<long,void *
   __ptr64> > >(void) __ptr64 */

void __thiscall
std::_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>::
~_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
          (_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_> *this)

{
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete(*(void **)(this + 8),0x20);
  }
  return;
}



===== ~_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_> @ 18000fa78 =====

/* public: __cdecl std::_Alloc_construct_ptr<class std::allocator<struct std::_Tree_node<struct
   std::pair<unsigned long const ,class PktMon::GatewayGroup>,void * __ptr64> >
   >::~_Alloc_construct_ptr<class std::allocator<struct std::_Tree_node<struct std::pair<unsigned
   long const ,class PktMon::GatewayGroup>,void * __ptr64> > >(void) __ptr64 */

void __thiscall
std::
_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_>
::
~_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_>
          (_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_>
           *this)

{
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete(*(void **)(this + 8),0x50);
  }
  return;
}



===== ~_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_> @ 18000fa9c =====

/* public: __cdecl std::_Tree_temp_node_alloc<class std::allocator<struct std::_Tree_node<struct
   std::pair<unsigned long const ,class PktMon::NicGroup>,void * __ptr64> >
   >::~_Tree_temp_node_alloc<class std::allocator<struct std::_Tree_node<struct std::pair<unsigned
   long const ,class PktMon::NicGroup>,void * __ptr64> > >(void) __ptr64 */

void __thiscall
std::
_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
::
~_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
          (_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
           *this)

{
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete(*(void **)(this + 8),0x98);
  }
  return;
}



===== ~_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_> @ 18000fac0 =====

/* public: __cdecl std::_Tree_temp_node_alloc<class std::allocator<struct std::_Tree_node<struct
   std::pair<unsigned long const ,class PktMon::VMSwitch>,void * __ptr64> >
   >::~_Tree_temp_node_alloc<class std::allocator<struct std::_Tree_node<struct std::pair<unsigned
   long const ,class PktMon::VMSwitch>,void * __ptr64> > >(void) __ptr64 */

void __thiscall
std::
_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
::
~_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
          (_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
           *this)

{
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete(*(void **)(this + 8),0x90);
  }
  return;
}



===== ~_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_> @ 18000fae4 =====

/* public: __cdecl std::_Alloc_construct_ptr<class std::allocator<struct std::_Tree_node<struct
   std::pair<class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const >,void * __ptr64> >
   >::~_Alloc_construct_ptr<class std::allocator<struct std::_Tree_node<struct std::pair<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const >,void * __ptr64> >
   >(void) __ptr64 */

void __thiscall
std::
_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
::
~_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
          (_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
           *this)

{
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete(*(void **)(this + 8),0x60);
  }
  return;
}



===== ~function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)> @ 18000fb08 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl std::function<class PktMon::CompGroup * __ptr64 __cdecl(unsigned long,enum
   _PKTMON_COMPONENT_TYPE)>::~function<class PktMon::CompGroup * __ptr64 __cdecl(unsigned long,enum
   _PKTMON_COMPONENT_TYPE)>(void) __ptr64 */

void __thiscall
std::function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>::
~function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
          (function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
           *this)

{
  function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)> *pfVar1;
  
  pfVar1 = *(function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
             **)(this + 0x38);
  if (pfVar1 != (function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
                 *)0x0) {
    (**(code **)(*(longlong *)pfVar1 + 0x20))(pfVar1,pfVar1 != this);
    *(undefined8 *)(this + 0x38) = 0;
  }
  return;
}



===== ~_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_> @ 18000fb40 =====

/* public: __cdecl std::_Tree<class std::_Tmap_traits<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,struct std::less<class std::basic_string<unsigned
   short,struct std::char_traits<unsigned short>,class std::allocator<unsigned short> > const
   >,class std::allocator<struct std::pair<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const > >,0> >::~_Tree<class std::_Tmap_traits<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,struct
   std::less<class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const >,class std::allocator<struct std::pair<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const > >,0> >(void)
   __ptr64 */

void __thiscall
std::
_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
::
~_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
          (_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
           *this)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(*(longlong *)this + 8);
  while (*(char *)((longlong)puVar2 + 0x19) == '\0') {
    _Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
    ::
    _Erase_tree<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
              ((_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
                *)this,(allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>
                        *)this,
               (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                *)puVar2[2]);
    puVar1 = (undefined8 *)*puVar2;
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(puVar2 + 8));
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(puVar2 + 4));
    operator_delete(puVar2,0x60);
    puVar2 = puVar1;
  }
  operator_delete(*(void **)this,0x60);
  return;
}



===== ~_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_> @ 18000fbc4 =====

/* public: __cdecl std::_Tree_temp_node<class std::allocator<struct std::_Tree_node<struct
   std::pair<class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const >,void * __ptr64> >
   >::~_Tree_temp_node<class std::allocator<struct std::_Tree_node<struct std::pair<class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const >,void * __ptr64> >
   >(void) __ptr64 */

void __thiscall
std::
_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
::
~_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
          (_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
           *this)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 8);
  if (lVar1 != 0) {
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(lVar1 + 0x40));
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(lVar1 + 0x20));
  }
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete(*(void **)(this + 8),0x60);
  }
  return;
}



===== ~function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)> @ 18000fc14 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl wistd::function<bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::~function<bool __cdecl(void * __ptr64,unsigned
   __int64,void * __ptr64,unsigned __int64,unsigned int)>(void) __ptr64 */

void __thiscall
wistd::
function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>::
~function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
          (function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
           *this)

{
  if (*(longlong **)(this + 0x70) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x70) + 0x18))();
  }
  return;
}



===== ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_> @ 18000fc40 =====

/* public: __cdecl std::pair<class std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> > const ,class std::basic_string<unsigned
   short,struct std::char_traits<unsigned short>,class std::allocator<unsigned short> > const
   >::~pair<class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const >(void) __ptr64 */

void __thiscall
std::
pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
::
~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
          (pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
           *this)

{
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
  ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(this + 0x20));
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
  ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)this);
  return;
}



===== ~vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> @ 18000fc68 =====

/* public: __cdecl std::vector<struct PktMon::CounterInfo,class std::allocator<struct
   PktMon::CounterInfo> >::~vector<struct PktMon::CounterInfo,class std::allocator<struct
   PktMon::CounterInfo> >(void) __ptr64 */

void __thiscall
std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
~vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>
          (vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *this)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = (*(longlong *)(this + 0x10) - (longlong)pvVar1 >> 4) * 0x10;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== ~vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_> @ 18000fce8 =====

/* public: __cdecl std::vector<class NetSetup2::Property,class std::allocator<class
   NetSetup2::Property> >::~vector<class NetSetup2::Property,class std::allocator<class
   NetSetup2::Property> >(void) __ptr64 */

void __thiscall
std::vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_>::
~vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_>
          (vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_> *this)

{
  Property *pPVar1;
  void *pvVar2;
  code *pcVar3;
  void *pvVar4;
  __uint64 _Var5;
  Property *this_00;
  
  this_00 = *(Property **)this;
  if (this_00 != (Property *)0x0) {
    pPVar1 = *(Property **)(this + 8);
    for (; this_00 != pPVar1; this_00 = this_00 + 0x30) {
      NetSetup2::Property::~Property(this_00);
    }
    pvVar2 = *(void **)this;
    _Var5 = (*(longlong *)(this + 0x10) - (longlong)pvVar2 >> 4) * 0x10;
    pvVar4 = pvVar2;
    if (0xfff < _Var5) {
      pvVar4 = *(void **)((longlong)pvVar2 + -8);
      _Var5 = _Var5 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar4))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
    }
    operator_delete(pvVar4,_Var5);
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== ~AutoFreeObjects @ 18000fd98 =====

/* public: __cdecl NetSetup2::details::AutoFreeObjects::~AutoFreeObjects(void) __ptr64 */

void __thiscall NetSetup2::details::AutoFreeObjects::~AutoFreeObjects(AutoFreeObjects *this)

{
  if (*(longlong *)(this + 8) != 0) {
    NetSetupFreeObjects(*(undefined4 *)this);
  }
  return;
}



===== ~AutoFreeProperties @ 18000fdc0 =====

/* public: __cdecl NetSetup2::details::AutoFreeProperties::~AutoFreeProperties(void) __ptr64 */

void __thiscall
NetSetup2::details::AutoFreeProperties::~AutoFreeProperties(AutoFreeProperties *this)

{
                    /* WARNING: Could not recover jumptable at 0x00018000fdc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NetSetupFreeObjectProperties(*(undefined4 *)this,*(undefined8 *)(this + 8));
  return;
}



===== ~FeatureStateData @ 18000fdd8 =====

/* public: __cdecl wil::details_abi::FeatureStateData::~FeatureStateData(void) __ptr64 */

void __thiscall wil::details_abi::FeatureStateData::~FeatureStateData(FeatureStateData *this)

{
  LPVOID lpMem;
  HANDLE hHeap;
  UsageIndexes local_c8 [64];
  RawUsageIndex local_88 [64];
  RawUsageIndex local_48 [64];
  
  UsageIndexes::UsageIndexes(local_c8);
  if (this[0x40] != (FeatureStateData)0x0) {
    RawUsageIndex::Swap((RawUsageIndex *)local_c8,(RawUsageIndex *)(this + 8));
  }
  if (this[0x80] != (FeatureStateData)0x0) {
    RawUsageIndex::Swap(local_88,(RawUsageIndex *)(this + 0x48));
  }
  if (this[0xc0] != (FeatureStateData)0x0) {
    RawUsageIndex::Swap(local_48,(RawUsageIndex *)(this + 0x88));
  }
  UsageIndexes::Record(local_c8);
  UsageIndexes::~UsageIndexes(local_c8);
  lpMem = *(LPVOID *)(this + 0x108);
  *(undefined8 *)(this + 0x108) = 0;
  if (lpMem != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 200));
  UsageIndexes::~UsageIndexes((UsageIndexes *)(this + 8));
  return;
}



===== ~FeatureStateManager @ 18000fec0 =====

/* public: __cdecl wil::details::FeatureStateManager::~FeatureStateManager(void) __ptr64 */

void __thiscall wil::details::FeatureStateManager::~FeatureStateManager(FeatureStateManager *this)

{
  LPVOID pvVar1;
  PTP_TIMER p_Var2;
  HANDLE pvVar3;
  
  *this = (FeatureStateManager)0x0;
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
           *)(this + 0x30),(_TP_TIMER *)0x0);
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
           *)(this + 0x38),(_TP_TIMER *)0x0);
  pvVar1 = *(LPVOID *)(this + 0x100);
  *(undefined8 *)(this + 0x100) = 0;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,pvVar1);
  }
  if ((*(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)(this + 0xe0) !=
       (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) && (DAT_180021028 != (srwlock *)0x0)) {
    details_abi::SubscriptionList::Unsubscribe
              ((SubscriptionList *)(DAT_180021028 + 200),DAT_180021028,
               *(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)(this + 0xe0));
  }
  pvVar1 = *(LPVOID *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = 0;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,pvVar1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x98));
  if (*(void **)(this + 0x90) != (void *)0x0) {
    UnregisterWilFeatureConfigurationChange(*(void **)(this + 0x90));
  }
  pvVar1 = *(LPVOID *)(this + 0x88);
  *(undefined8 *)(this + 0x88) = 0;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,pvVar1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x48));
  p_Var2 = *(PTP_TIMER *)(this + 0x38);
  if (p_Var2 != (PTP_TIMER)0x0) {
    SetThreadpoolTimer(p_Var2,(PFILETIME)0x0,0,0);
    WaitForThreadpoolTimerCallbacks(p_Var2,1);
    CloseThreadpoolTimer(p_Var2);
  }
  p_Var2 = *(PTP_TIMER *)(this + 0x30);
  if (p_Var2 != (PTP_TIMER)0x0) {
    SetThreadpoolTimer(p_Var2,(PFILETIME)0x0,0,0);
    WaitForThreadpoolTimerCallbacks(p_Var2,1);
    CloseThreadpoolTimer(p_Var2);
  }
  if (*(ProcessLocalStorageData<wil::details_abi::FeatureStateData> **)(this + 0x10) !=
      (ProcessLocalStorageData<wil::details_abi::FeatureStateData> *)0x0) {
    details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Release
              (*(ProcessLocalStorageData<wil::details_abi::FeatureStateData> **)(this + 0x10));
  }
  return;
}



===== ~NetworkInterface @ 1800100a0 =====

/* public: __cdecl NetSetup2::NetworkInterface::~NetworkInterface(void) __ptr64 */

void __thiscall NetSetup2::NetworkInterface::~NetworkInterface(NetworkInterface *this)

{
  vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_> *this_00;
  
  this_00 = *(vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_> **)(this + 8);
  if (this_00 != (vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_> *)0x0) {
    std::vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_>::
    ~vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_>(this_00);
    operator_delete(this_00,0x18);
  }
  return;
}



===== ~Property @ 1800100d4 =====

/* public: __cdecl NetSetup2::Property::~Property(void) __ptr64 */

void __thiscall NetSetup2::Property::~Property(Property *this)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)(this + 0x18);
  if (pvVar1 != (void *)0x0) {
    _Var4 = *(longlong *)(this + 0x28) - (longlong)pvVar1;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
    *(undefined8 *)(this + 0x18) = 0;
    *(undefined8 *)(this + 0x20) = 0;
    *(undefined8 *)(this + 0x28) = 0;
  }
  return;
}



===== ~RawUsageIndex @ 18001013c =====

/* public: __cdecl wil::details_abi::RawUsageIndex::~RawUsageIndex(void) __ptr64 */

void __thiscall wil::details_abi::RawUsageIndex::~RawUsageIndex(RawUsageIndex *this)

{
  LPVOID lpMem;
  HANDLE hHeap;
  
  lpMem = *(LPVOID *)(this + 0x30);
  *(undefined8 *)(this + 0x30) = 0;
  if (lpMem != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  return;
}



===== ~Transaction @ 180010180 =====

/* public: __cdecl NetSetup2::Transaction::~Transaction(void) __ptr64 */

void __thiscall NetSetup2::Transaction::~Transaction(Transaction *this)

{
  if (*(longlong *)this != 0) {
    NetSetupClose();
    *(undefined8 *)this = 0;
  }
  return;
}



===== ~UsageIndexes @ 1800101b0 =====

/* public: __cdecl wil::details_abi::UsageIndexes::~UsageIndexes(void) __ptr64 */

void __thiscall wil::details_abi::UsageIndexes::~UsageIndexes(UsageIndexes *this)

{
  LPVOID pvVar1;
  HANDLE pvVar2;
  
  pvVar1 = *(LPVOID *)(this + 0xb0);
  *(undefined8 *)(this + 0xb0) = 0;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar2 = GetProcessHeap();
    HeapFree(pvVar2,0,pvVar1);
  }
  pvVar1 = *(LPVOID *)(this + 0x70);
  *(undefined8 *)(this + 0x70) = 0;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar2 = GetProcessHeap();
    HeapFree(pvVar2,0,pvVar1);
  }
  pvVar1 = *(LPVOID *)(this + 0x30);
  *(undefined8 *)(this + 0x30) = 0;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar2 = GetProcessHeap();
    HeapFree(pvVar2,0,pvVar1);
  }
  return;
}



===== operator= @ 180010260 =====

/* public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __ptr64 __cdecl std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::operator=(class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > && __ptr64) __ptr64 */

basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
* __thiscall
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
operator=(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
          *this,basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                *param_1)

{
  longlong lVar1;
  void *pvVar2;
  code *pcVar3;
  undefined8 uVar4;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar5;
  void *pvVar6;
  ulonglong uVar7;
  
  if (this != (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
               *)param_1) {
    if (7 < *(ulonglong *)(this + 0x18)) {
      pvVar2 = *(void **)this;
      lVar1 = *(ulonglong *)(this + 0x18) * 2;
      uVar7 = lVar1 + 2;
      pvVar6 = pvVar2;
      if (0xfff < uVar7) {
        pvVar6 = *(void **)((longlong)pvVar2 + -8);
        uVar7 = lVar1 + 0x29;
        if (0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar6))) {
          _o__invalid_parameter_noinfo_noreturn();
          pcVar3 = (code *)swi(3);
          pbVar5 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                    *)(*pcVar3)();
          return pbVar5;
        }
      }
      operator_delete(pvVar6,uVar7);
    }
    *(undefined8 *)(this + 0x18) = 7;
    *(undefined8 *)(this + 0x10) = 0;
    *(undefined2 *)this = 0;
    uVar4 = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)this = *(undefined8 *)param_1;
    *(undefined8 *)(this + 8) = uVar4;
    uVar4 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(this + 0x18) = uVar4;
    *(undefined8 *)(param_1 + 0x10) = 0;
    *(undefined8 *)(param_1 + 0x18) = 7;
    *(undefined2 *)param_1 = 0;
  }
  return (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
          *)this;
}



===== operator* @ 180010300 =====

/* public: long const & __ptr64 __cdecl std::_Tree_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<long> > >::operator*(void)const __ptr64 */

long * __thiscall
std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<long>_>_>::operator*
          (_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<long>_>_> *this)

{
  return (long *)(*(longlong *)this + 0x1c);
}



===== operator() @ 180010310 =====

/* public: virtual bool __cdecl wistd::__function::__func<class
   <lambda_8db0ce862824541f40dfb767113f1e28>,bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::operator()(void * __ptr64 && __ptr64,unsigned __int64 &&
   __ptr64,void * __ptr64 && __ptr64,unsigned __int64 && __ptr64,unsigned int && __ptr64) __ptr64 */

bool __thiscall
wistd::__function::
__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
::operator()(__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
             *this,void **param_1,__uint64 *param_2,void **param_3,__uint64 *param_4,uint *param_5)

{
  bool bVar1;
  
  if ((**(ulonglong **)(this + 8) < **(ulonglong **)(this + 0x10)) ||
     (bVar1 = wil::details_abi::RawUsageIndex::RecordUsage
                        (*(RawUsageIndex **)(this + 0x18),*param_1,*param_2,*param_3,*param_4,
                         *param_5), bVar1)) {
    **(longlong **)(this + 8) = **(longlong **)(this + 8) + 1;
    return true;
  }
  return false;
}



===== operator+= @ 180010378 =====

/* public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __ptr64 __cdecl std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::operator+=(unsigned
   short const * __ptr64 const) __ptr64 */

basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
* __thiscall
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
operator+=(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
           *this,ushort *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar3;
  
  uVar2 = 0xffffffffffffffff;
  do {
    uVar2 = uVar2 + 1;
  } while (param_1[uVar2] != 0);
  lVar1 = *(longlong *)(this + 0x10);
  if ((ulonglong)(*(longlong *)(this + 0x18) - lVar1) < uVar2) {
    this = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            *)_Reallocate_grow_by<<lambda_7030d12a21dba11210293044e97fe9c7>,unsigned_short_const*___ptr64,unsigned___int64>
                        (this);
  }
  else {
    *(ulonglong *)(this + 0x10) = lVar1 + uVar2;
    pbVar3 = this;
    if (7 < *(ulonglong *)(this + 0x18)) {
      pbVar3 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 **)this;
    }
    memmove(pbVar3 + lVar1 * 2,param_1,uVar2 * 2);
    *(undefined2 *)(pbVar3 + (lVar1 + uVar2) * 2) = 0;
  }
  return (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
          *)this;
}



===== `scalar_deleting_destructor' @ 180010410 =====

/* public: virtual void * __ptr64 __cdecl wistd::__function::__base<bool __cdecl(void *
   __ptr64,unsigned __int64,void * __ptr64,unsigned __int64,unsigned int)>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
wistd::__function::
__base<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>::
_scalar_deleting_destructor_
          (__base<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
           *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this,8);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 180010450 =====

/* public: virtual void * __ptr64 __cdecl wistd::__function::__func<class
   <lambda_8db0ce862824541f40dfb767113f1e28>,bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::`scalar deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
wistd::__function::
__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
::_scalar_deleting_destructor_
          (__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
           *this,uint param_1)

{
  *(undefined ***)this =
       &__base<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
        ::_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x20);
  }
  return this;
}



===== `vector_deleting_destructor' @ 180010490 =====

/* public: virtual void * __ptr64 __cdecl PktMon::InvalidComponentId::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
PktMon::InvalidComponentId::_vector_deleting_destructor_(InvalidComponentId *this,uint param_1)

{
  *(undefined ***)this = std::exception::_vftable_;
  __std_exception_destroy(this + 8);
  if ((param_1 & 1) != 0) {
    operator_delete(this,0x20);
  }
  return this;
}



===== Acquire @ 1800104dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl wil::details_abi::ProcessLocalStorageData<class
   wil::details_abi::FeatureStateData>::Acquire(char const * __ptr64,class
   wil::details_abi::ProcessLocalStorageData<class wil::details_abi::FeatureStateData> * __ptr64 *
   __ptr64) */

long __cdecl
wil::details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Acquire
          (char *param_1,ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> **param_2
          )

{
  __uint64 _Var1;
  DWORD DVar2;
  long lVar3;
  BOOL BVar4;
  HANDLE pvVar5;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *pPVar6;
  HANDLE hHeap;
  undefined1 uVar7;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *pPVar8;
  bool *pbVar9;
  HANDLE hMutex;
  void *unaff_retaddr;
  undefined1 auStack_298 [32];
  undefined4 local_278;
  char *local_270;
  HANDLE local_268;
  __uint64 local_260;
  __uint64 _Stack_258;
  longlong local_250;
  WCHAR local_248 [264];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_298;
  *param_2 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
  DVar2 = GetCurrentProcessId();
  local_278 = 0x130;
  local_270 = param_1;
  StringCchPrintfW((ushort *)local_248,0x104,(ushort *)L"Local\\SM0:%lu:%lu:%hs",(ulonglong)DVar2);
  local_268 = (HANDLE)0x0;
  pbVar9 = (bool *)0x1f0001;
  pvVar5 = CreateMutexExW((LPSECURITY_ATTRIBUTES)0x0,local_248,0,0x1f0001);
  details::
  unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *)&local_268,pvVar5);
  pvVar5 = local_268;
  if (local_268 == (HANDLE)0x0) {
    lVar3 = details::GetLastErrorFailHr();
    return lVar3;
  }
  uVar7 = 0xff;
  DVar2 = WaitForSingleObjectEx(local_268,0xffffffff,0);
  if (DVar2 == 0x102) {
    hMutex = (HANDLE)0x0;
  }
  else {
    if ((DVar2 & 0xffffff7f) != 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::FailFast_Unexpected
                (unaff_retaddr,0xc37,"onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
    }
    hMutex = pvVar5;
  }
  local_250 = 0;
  pPVar8 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)&local_250;
  lVar3 = SemaphoreValue::TryGetValueInternal
                    ((ushort *)local_248,(bool)uVar7,(__uint64 *)pPVar8,pbVar9);
  if (lVar3 < 0) {
    details::in1diag3::Return_Hr(unaff_retaddr,100,(char *)pPVar8,lVar3);
    details::in1diag3::Return_Hr(unaff_retaddr,0x6d,(char *)pPVar8,lVar3);
    details::in1diag3::Return_Hr(unaff_retaddr,299,(char *)pPVar8,lVar3);
    if ((hMutex != (HANDLE)0x0) && (BVar4 = ReleaseMutex(hMutex), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,(char *)pPVar8);
    }
    BVar4 = CloseHandle(pvVar5);
    if (BVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pPVar8);
    }
    return lVar3;
  }
  pPVar6 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)(local_250 * 4);
  if (pPVar6 == (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0) {
    *param_2 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
    pPVar6 = details::ProcessHeapAlloc(8,0x130);
    if (pPVar6 == (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0) {
      lVar3 = -0x7ff8fff2;
      details::in1diag3::Return_Hr(unaff_retaddr,0x148,(char *)pPVar8,-0x7ff8fff2);
      pPVar6 = pPVar8;
    }
    else {
      local_260 = 0;
      _Stack_258 = 0;
      pPVar8 = pPVar6;
      lVar3 = SemaphoreValue::CreateFromPointer
                        ((SemaphoreValue *)&local_260,(ushort *)local_248,pPVar6);
      _Var1 = _Stack_258;
      if (-1 < lVar3) {
        *(__uint64 *)(pPVar6 + 0x10) = local_260;
        *(HANDLE *)(pPVar6 + 8) = pvVar5;
        pvVar5 = (HANDLE)0x0;
        local_260 = 0;
        _Stack_258 = 0;
        *(__uint64 *)(pPVar6 + 0x18) = _Var1;
        *(undefined4 *)pPVar6 = 1;
        memset(pPVar6 + 0x28,0,0x108);
        *(__uint64 *)(pPVar6 + 0x20) = 0;
        UsageIndexes::UsageIndexes((UsageIndexes *)(pPVar6 + 0x28));
        pPVar8 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
        InitializeCriticalSectionEx((LPCRITICAL_SECTION)(pPVar6 + 0xe8),0,0);
        *(__uint64 *)(pPVar6 + 0x110) = 0;
        *(__uint64 *)(pPVar6 + 0x118) = 0;
        *(__uint64 *)(pPVar6 + 0x120) = 0;
        *(__uint64 *)(pPVar6 + 0x128) = 0;
        *param_2 = pPVar6;
        SemaphoreValue::~SemaphoreValue((SemaphoreValue *)&local_260);
        goto LAB_1800107d8;
      }
      details::in1diag3::Return_Hr(unaff_retaddr,0x14b,(char *)pPVar8,lVar3);
      SemaphoreValue::~SemaphoreValue((SemaphoreValue *)&local_260);
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,pPVar6);
    }
    details::in1diag3::Return_Hr(unaff_retaddr,0x134,(char *)pPVar6,lVar3);
    if ((hMutex != (HANDLE)0x0) && (BVar4 = ReleaseMutex(hMutex), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,(char *)pPVar6);
    }
    if ((pvVar5 != (HANDLE)0x0) && (BVar4 = CloseHandle(pvVar5), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pPVar6);
    }
  }
  else {
    *param_2 = pPVar6;
    *(int *)*param_2 = *(int *)pPVar6 + 1;
    pvVar5 = local_268;
LAB_1800107d8:
    if ((hMutex != (HANDLE)0x0) && (BVar4 = ReleaseMutex(hMutex), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,(char *)pPVar8);
    }
    if ((pvVar5 != (HANDLE)0x0) && (BVar4 = CloseHandle(pvVar5), BVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,(char *)pPVar8);
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== AddComp @ 1800108c0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual void __cdecl PktMon::GatewayGroup::AddComp(class PktMon::Component &
   __ptr64,class std::function<class PktMon::CompGroup * __ptr64 __cdecl(unsigned long,enum
   _PKTMON_COMPONENT_TYPE)>) __ptr64 */

void __thiscall
PktMon::GatewayGroup::AddComp(GatewayGroup *this,Component *param_1,longlong *param_3)

{
  Component **ppCVar1;
  longlong *plVar2;
  Component *local_res8 [2];
  longlong *local_res18;
  
  ppCVar1 = *(Component ***)(this + 0x18);
  local_res8[0] = param_1;
  local_res18 = param_3;
  if (ppCVar1 == *(Component ***)(this + 0x20)) {
    std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
    _Emplace_reallocate<PktMon::Component*___ptr64>
              ((vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
               (this + 0x10),ppCVar1,local_res8);
  }
  else {
    *ppCVar1 = param_1;
    *(longlong *)(this + 0x18) = *(longlong *)(this + 0x18) + 8;
  }
  plVar2 = (longlong *)param_3[7];
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != param_3);
    param_3[7] = 0;
  }
  return;
}



===== AddComp @ 180010930 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual void __cdecl PktMon::NicGroup::AddComp(class PktMon::Component & __ptr64,class
   std::function<class PktMon::CompGroup * __ptr64 __cdecl(unsigned long,enum
   _PKTMON_COMPONENT_TYPE)>) __ptr64 */

void __thiscall PktMon::NicGroup::AddComp(NicGroup *this,Component *param_1,longlong *param_3)

{
  int iVar1;
  longlong *plVar2;
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *this_00;
  Component **ppCVar3;
  Component *local_res10;
  longlong *local_res18;
  
  iVar1 = *(int *)(*(longlong *)param_1 + 0x180);
  local_res18 = param_3;
  if (iVar1 < 8) {
    if (((iVar1 != 7) && (iVar1 != 1)) && (iVar1 != 2)) {
      if (iVar1 == 3) {
        ppCVar3 = *(Component ***)(this + 0x28);
        if (ppCVar3 != *(Component ***)(this + 0x30)) {
          *ppCVar3 = param_1;
          *(longlong *)(this + 0x28) = *(longlong *)(this + 0x28) + 8;
          local_res10 = param_1;
          goto LAB_1800109ff;
        }
        this_00 = (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
                  (this + 0x20);
        goto LAB_18001099e;
      }
      if (iVar1 == 4) goto LAB_1800109c8;
      if (iVar1 != 6) goto LAB_1800109ff;
    }
  }
  else if (iVar1 != 9) {
    if (iVar1 != 10) {
      if (iVar1 != 0xb) {
        if (iVar1 == 0xe) {
          *(Component **)(this + 0x10) = param_1;
        }
        goto LAB_1800109ff;
      }
LAB_1800109c8:
      InsertRelatedProtocol
                (param_1,(vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>
                          *)(this + 0x38));
      goto LAB_1800109ff;
    }
    ppCVar3 = *(Component ***)(this + 0x58);
    if (ppCVar3 != *(Component ***)(this + 0x60)) {
      *ppCVar3 = param_1;
      *(longlong *)(this + 0x58) = *(longlong *)(this + 0x58) + 8;
      local_res10 = param_1;
      goto LAB_1800109ff;
    }
    this_00 = (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
              (this + 0x50);
LAB_18001099e:
    local_res10 = param_1;
    std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
    _Emplace_reallocate<PktMon::Component*___ptr64>(this_00,ppCVar3,&local_res10);
    goto LAB_1800109ff;
  }
  if (*(longlong *)(this + 0x18) == 0) {
    *(Component **)(this + 0x18) = param_1;
  }
  else {
    Component::MakeRelated(*(Component **)(this + 0x18),param_1);
  }
LAB_1800109ff:
  plVar2 = (longlong *)param_3[7];
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != param_3);
    param_3[7] = 0;
  }
  return;
}



===== AddComp @ 180010a30 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual void __cdecl PktMon::VMSwitch::AddComp(class PktMon::Component & __ptr64,class
   std::function<class PktMon::CompGroup * __ptr64 __cdecl(unsigned long,enum
   _PKTMON_COMPONENT_TYPE)>) __ptr64 */

void __thiscall PktMon::VMSwitch::AddComp(VMSwitch *this,Component *param_1,longlong *param_3)

{
  int iVar1;
  longlong *plVar2;
  Component **ppCVar3;
  undefined8 *puVar4;
  _PKTMON_PROPERTY_OUT *p_Var5;
  NicGroup *pNVar6;
  longlong *plVar7;
  Component *local_res10;
  longlong *local_res18;
  Component *local_res20;
  longlong *local_88;
  longlong *local_80;
  Component local_70 [56];
  undefined8 local_38;
  
  iVar1 = *(int *)(*(longlong *)param_1 + 0x180);
  local_res18 = param_3;
  if (iVar1 == 5) {
    ppCVar3 = *(Component ***)(this + 0x58);
    local_res10 = param_1;
    if (ppCVar3 == *(Component ***)(this + 0x60)) {
      std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
      _Emplace_reallocate<PktMon::Component*___ptr64>
                ((vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
                 (this + 0x50),ppCVar3,&local_res10);
    }
    else {
      *ppCVar3 = param_1;
      *(longlong *)(this + 0x58) = *(longlong *)(this + 0x58) + 8;
    }
  }
  else if (iVar1 == 6) {
    p_Var5 = Component::FindProperty(param_1,1);
    if (p_Var5 != (_PKTMON_PROPERTY_OUT *)0x0) {
      local_res10 = (Component *)CONCAT44(local_res10._4_4_,2);
      local_res20 = (Component *)CONCAT44(local_res20._4_4_,*(undefined4 *)(p_Var5 + 6));
      plVar7 = (longlong *)param_3[7];
      if (plVar7 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        std::_Xbad_function_call();
      }
      pNVar6 = (NicGroup *)(**(code **)(*plVar7 + 0x10))(plVar7,&local_res20,&local_res10);
      local_res20 = local_70;
      local_38 = 0;
      puVar4 = (undefined8 *)param_3[7];
      local_res10 = (Component *)pNVar6;
      if (puVar4 != (undefined8 *)0x0) {
        local_38 = (**(code **)*puVar4)(puVar4,local_70);
      }
      NicGroup::AddComp(pNVar6,param_1,local_70);
      ppCVar3 = *(Component ***)(this + 0x40);
      if (ppCVar3 == *(Component ***)(this + 0x48)) {
        std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
        _Emplace_reallocate<PktMon::Component*___ptr64>
                  ((vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *
                   )(this + 0x38),ppCVar3,&local_res10);
      }
      else {
        *ppCVar3 = (Component *)pNVar6;
        *(longlong *)(this + 0x40) = *(longlong *)(this + 0x40) + 8;
      }
    }
  }
  else if (iVar1 == 7) {
    p_Var5 = Component::FindProperty(param_1,1);
    if (p_Var5 != (_PKTMON_PROPERTY_OUT *)0x0) {
      local_res10 = (Component *)CONCAT44(local_res10._4_4_,2);
      local_res20 = (Component *)CONCAT44(local_res20._4_4_,*(undefined4 *)(p_Var5 + 6));
      plVar7 = (longlong *)param_3[7];
      if (plVar7 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        std::_Xbad_function_call();
      }
      pNVar6 = (NicGroup *)(**(code **)(*plVar7 + 0x10))(plVar7,&local_res20,&local_res10);
      local_res10 = local_70;
      local_38 = 0;
      puVar4 = (undefined8 *)param_3[7];
      if (puVar4 != (undefined8 *)0x0) {
        local_38 = (**(code **)*puVar4)(puVar4,local_70);
      }
      NicGroup::AddComp(pNVar6,param_1,local_70);
      *(NicGroup **)(this + 0x30) = pNVar6;
    }
  }
  else if (iVar1 == 8) {
    *(Component **)(this + 0x28) = param_1;
    Component::FindAllProperties(param_1,(_PKTMON_COMPONENT_PROPERTY_ID)&local_88);
    for (plVar7 = local_88; plVar7 != local_80; plVar7 = plVar7 + 1) {
      local_res10 = (Component *)CONCAT44(local_res10._4_4_,2);
      local_res20 = (Component *)CONCAT44(local_res20._4_4_,*(undefined4 *)(*plVar7 + 6));
      plVar2 = (longlong *)param_3[7];
      if (plVar2 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        std::_Xbad_function_call();
      }
      local_res10 = (Component *)(**(code **)(*plVar2 + 0x10))(plVar2,&local_res20,&local_res10);
      ppCVar3 = *(Component ***)(this + 0x18);
      if (ppCVar3 == *(Component ***)(this + 0x20)) {
        std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
        _Emplace_reallocate<PktMon::Component*___ptr64>
                  ((vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *
                   )(this + 0x10),ppCVar3,&local_res10);
      }
      else {
        *ppCVar3 = local_res10;
        *(longlong *)(this + 0x18) = *(longlong *)(this + 0x18) + 8;
      }
    }
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_88);
  }
  plVar7 = (longlong *)param_3[7];
  if (plVar7 != (longlong *)0x0) {
    (**(code **)(*plVar7 + 0x20))(plVar7,plVar7 != param_3);
    param_3[7] = 0;
  }
  return;
}



===== EnsureStateData @ 180010ca8 =====

/* private: bool __cdecl wil::details::FeatureStateManager::EnsureStateData(void) __ptr64 */

bool __thiscall wil::details::FeatureStateManager::EnsureStateData(FeatureStateManager *this)

{
  FeatureStateManager *SRWLock;
  DWORD dwErrCode;
  long lVar1;
  ulonglong uVar2;
  ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *local_res8;
  
  if (*(longlong *)(this + 0x18) == 0) {
    dwErrCode = GetLastError();
    if (*(longlong *)(this + 0x18) == 0) {
      if (*(longlong *)(this + 0x10) == 0) {
        local_res8 = (ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> *)0x0;
        lVar1 = details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Acquire
                          (*(char **)(this + 8),&local_res8);
        if ((-1 < lVar1) && (*(longlong *)(this + 0x10) == 0)) {
          *(ProcessLocalStorageData<class_wil::details_abi::FeatureStateData> **)(this + 0x10) =
               local_res8;
        }
      }
      uVar2 = -(ulonglong)(*(longlong *)(this + 0x10) != 0) & *(longlong *)(this + 0x10) + 0x20U;
    }
    else {
      uVar2 = 0;
    }
    SRWLock = this + 0x20;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    if (*(longlong *)(this + 0x18) == 0) {
      *(ulonglong *)(this + 0x18) = uVar2;
    }
    if (SRWLock != (FeatureStateManager *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    }
    SetLastError(dwErrCode);
  }
  return *(longlong *)(this + 0x18) != 0;
}



===== EnsureTimerUnderLock @ 180010d88 =====

/* private: void __cdecl wil::details::FeatureStateManager::EnsureTimerUnderLock(void) __ptr64 */

void __thiscall wil::details::FeatureStateManager::EnsureTimerUnderLock(FeatureStateManager *this)

{
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  *this_00;
  DWORD dwErrCode;
  PTP_TIMER p_Var1;
  _FILETIME local_res8;
  
  this_00 = (unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
             *)(this + 0x30);
  if (this[0x41] == (FeatureStateManager)0x0) {
    if (*(longlong *)this_00 == 0) {
      dwErrCode = GetLastError();
      p_Var1 = CreateThreadpoolTimer
                         (<lambda_d51448ba32f8ef42e59400edd4566183>::<lambda_invoker_cdecl>,this,
                          (PTP_CALLBACK_ENVIRON)0x0);
      unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
      ::reset(this_00,p_Var1);
      SetLastError(dwErrCode);
    }
    if (*(PTP_TIMER *)this_00 != (PTP_TIMER)0x0) {
      local_res8.dwLowDateTime = 0x4d2fa200;
      local_res8.dwHighDateTime = 0xffffffff;
      SetThreadpoolTimer(*(PTP_TIMER *)this_00,&local_res8,0,75000);
      this[0x41] = (FeatureStateManager)0x1;
    }
  }
  return;
}



===== FindAllProperties @ 180010e38 =====

/* public: class std::vector<struct _PKTMON_PROPERTY_OUT const * __ptr64,class std::allocator<struct
   _PKTMON_PROPERTY_OUT const * __ptr64> > __cdecl PktMon::Component::FindAllProperties(enum
   _PKTMON_COMPONENT_PROPERTY_ID)const __ptr64 */

vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> * __thiscall
PktMon::Component::FindAllProperties(Component *this,_PKTMON_COMPONENT_PROPERTY_ID param_1)

{
  longlong *plVar1;
  Component **ppCVar2;
  undefined4 in_register_00000014;
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *this_00;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  Component *local_res20;
  undefined8 *local_40;
  undefined8 *local_38;
  
  this_00 = (vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *)
            CONCAT44(in_register_00000014,param_1);
  *(undefined8 *)this_00 = 0;
  *(undefined8 *)(this_00 + 8) = 0;
  *(undefined8 *)(this_00 + 0x10) = 0;
  GetRelated(this);
  for (; local_40 != local_38; local_40 = local_40 + 1) {
    plVar1 = (longlong *)*local_40;
    iVar5 = 0;
    lVar3 = *plVar1;
    if (*(short *)(lVar3 + 0x1c8) != 0) {
      lVar4 = 0;
      do {
        if (*(int *)(lVar3 + 0x1cc + lVar4) == 0xc) {
          local_res20 = (Component *)((longlong)iVar5 * 0x108 + lVar3 + 0x1cc);
          ppCVar2 = *(Component ***)(this_00 + 8);
          if (ppCVar2 == *(Component ***)(this_00 + 0x10)) {
            std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
            _Emplace_reallocate<PktMon::Component*___ptr64>(this_00,ppCVar2,&local_res20);
          }
          else {
            *ppCVar2 = local_res20;
            *(longlong *)(this_00 + 8) = *(longlong *)(this_00 + 8) + 8;
          }
        }
        iVar5 = iVar5 + 1;
        lVar4 = lVar4 + 0x108;
        lVar3 = *plVar1;
      } while (iVar5 < (int)(uint)*(ushort *)(lVar3 + 0x1c8));
    }
  }
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_40);
  return this_00;
}



===== FindInsertionPointOrIncrement @ 180010f34 =====

/* private: unsigned char * __ptr64 __cdecl
   wil::details_abi::RawUsageIndex::FindInsertionPointOrIncrement(struct
   wil::details_abi::UsageIndexProperty & __ptr64,unsigned char * __ptr64,void * __ptr64,unsigned
   __int64,unsigned int) __ptr64 */

uchar * __thiscall
wil::details_abi::RawUsageIndex::FindInsertionPointOrIncrement
          (RawUsageIndex *this,UsageIndexProperty *param_1,uchar *param_2,void *param_3,
          __uint64 param_4,uint param_5)

{
  UsageIndexProperty *pUVar1;
  longlong lVar2;
  uint *puVar3;
  bool bVar4;
  int iVar5;
  ulonglong uVar6;
  uchar *puVar7;
  undefined4 *puVar8;
  RawUsageIndex RVar9;
  uint uVar10;
  ulonglong uVar11;
  int iVar12;
  uchar *local_res8;
  undefined2 local_80;
  RawUsageIndex local_7e;
  int local_7c;
  ushort local_78;
  int *local_70;
  void *pvStack_68;
  undefined2 local_60;
  RawUsageIndex local_5e;
  undefined4 local_5c;
  ushort local_58;
  undefined8 local_50;
  void *pvStack_48;
  
  local_80 = *(undefined2 *)(this + 6);
  pUVar1 = param_1 + 4;
  RVar9 = (RawUsageIndex)0x0;
  local_7e = this[8];
  iVar5 = -1;
  local_7c = 0;
  local_78 = 0;
  local_70 = (int *)0x0;
  pvStack_68 = (void *)0x0;
  iVar12 = (int)param_4;
  if (*(longlong *)(this + 0x10) == 0) {
    uVar10 = 0;
    if (*(uint *)pUVar1 == 0) {
      return param_2;
    }
    while (local_res8 = param_2,
          bVar4 = UsageIndexProperty::Read
                            ((UsageIndexProperty *)&local_80,&local_res8,*(uchar **)(this + 0x20)),
          bVar4) {
      if (param_4 == local_78) {
        iVar5 = memcmp(param_3,pvStack_68,param_4);
      }
      else {
        iVar5 = iVar12 - (uint)local_78;
      }
      if (iVar5 < 1) goto LAB_1800111a0;
      uVar10 = uVar10 + 1;
      param_2 = local_res8;
      if (*(uint *)pUVar1 <= uVar10) {
        return local_res8;
      }
    }
    if (*(uint *)pUVar1 != uVar10) {
      *(uint *)pUVar1 = uVar10;
      if (param_1[2] == (UsageIndexProperty)0x1) {
        if (*(undefined2 **)(param_1 + 0x10) == (undefined2 *)0x0) goto LAB_180011186;
        **(undefined2 **)(param_1 + 0x10) = (short)uVar10;
      }
      else if (param_1[2] == (UsageIndexProperty)0x2) {
        puVar3 = *(uint **)(param_1 + 0x10);
        if (puVar3 != (uint *)0x0) {
          if (pUVar1 != (UsageIndexProperty *)0x0) {
            *puVar3 = uVar10;
            goto LAB_1800111a0;
          }
          *puVar3 = 0;
        }
LAB_180011186:
        puVar8 = (undefined4 *)_o__errno();
        *puVar8 = 0x16;
        _o__invalid_parameter_noinfo();
      }
    }
  }
  else {
    lVar2 = *(longlong *)(this + 0x20);
    uVar11 = *(ulonglong *)(this + 0x10);
    uVar6 = (ulonglong)(lVar2 - (longlong)param_2) / uVar11;
    if ((uVar6 < *(uint *)pUVar1) && (uVar10 = (uint)uVar6, *(uint *)pUVar1 != uVar10)) {
      *(uint *)pUVar1 = uVar10;
      if (param_1[2] == (UsageIndexProperty)0x1) {
        if (*(undefined2 **)(param_1 + 0x10) == (undefined2 *)0x0) goto LAB_180010fda;
        **(undefined2 **)(param_1 + 0x10) = (short)uVar6;
      }
      else if (param_1[2] == (UsageIndexProperty)0x2) {
        puVar3 = *(uint **)(param_1 + 0x10);
        if (puVar3 != (uint *)0x0) {
          if (pUVar1 != (UsageIndexProperty *)0x0) {
            *puVar3 = uVar10;
            goto LAB_180010fed;
          }
          *puVar3 = 0;
        }
LAB_180010fda:
        puVar8 = (undefined4 *)_o__errno(0,(ulonglong)(lVar2 - (longlong)param_2) % uVar11);
        *puVar8 = 0x16;
        _o__invalid_parameter_noinfo();
      }
    }
LAB_180010fed:
    local_50 = 0;
    pvStack_48 = (void *)0x0;
    local_5c = 0;
    puVar7 = param_2 + (ulonglong)*(uint *)pUVar1 * *(longlong *)(this + 0x10);
    local_58 = 0;
    local_60 = *(undefined2 *)(this + 6);
    local_5e = this[8];
    uVar11 = (ulonglong)*(uint *)pUVar1;
    while (uVar11 != 0) {
      uVar6 = uVar11 >> 1;
      local_res8 = param_2 + uVar6 * *(longlong *)(this + 0x10);
      UsageIndexProperty::Read((UsageIndexProperty *)&local_60,&local_res8,*(uchar **)(this + 0x20))
      ;
      if (param_4 == local_58) {
        iVar5 = memcmp(param_3,pvStack_48,param_4);
      }
      else {
        iVar5 = iVar12 - (uint)local_58;
      }
      if (iVar5 < 1) {
        uVar11 = uVar6;
      }
      else {
        uVar11 = uVar11 + (-1 - uVar6);
        param_2 = local_res8;
      }
    }
    if (puVar7 <= param_2) {
      return param_2;
    }
    local_res8 = param_2;
    UsageIndexProperty::Read((UsageIndexProperty *)&local_80,&local_res8,*(uchar **)(this + 0x20));
    if (param_4 == local_78) {
      iVar5 = memcmp(param_3,pvStack_68,param_4);
    }
    else {
      iVar5 = iVar12 - (uint)local_78;
    }
  }
LAB_1800111a0:
  if (iVar5 != 0) {
    return param_2;
  }
  if (local_7e == (RawUsageIndex)0x0) {
    if (this[0x38] == (RawUsageIndex)0x0) goto LAB_1800111ff;
  }
  else {
    iVar5 = param_5 + local_7c;
    if (local_7c != iVar5) {
      if (local_7e == (RawUsageIndex)0x1) {
        if (local_70 == (int *)0x0) {
LAB_1800111cb:
          puVar8 = (undefined4 *)_o__errno();
          *puVar8 = 0x16;
          _o__invalid_parameter_noinfo();
        }
        else {
          *(short *)local_70 = (short)iVar5;
        }
      }
      else if (local_7e == (RawUsageIndex)0x2) {
        if (local_70 == (int *)0x0) goto LAB_1800111cb;
        *local_70 = iVar5;
      }
    }
  }
  RVar9 = (RawUsageIndex)0x1;
LAB_1800111ff:
  this[0x38] = RVar9;
  return (uchar *)0x0;
}



===== FindOrCreateGroup @ 180011210 =====

/* private: class PktMon::CompGroup * __ptr64 __cdecl PktMon::CompList::FindOrCreateGroup(unsigned
   long,enum _PKTMON_COMPONENT_TYPE) __ptr64 */

CompGroup * __thiscall
PktMon::CompList::FindOrCreateGroup(CompList *this,ulong param_1,_PKTMON_COMPONENT_TYPE param_2)

{
  longlong *plVar1;
  ulong local_res10 [6];
  ulong local_18 [6];
  
  local_res10[0] = param_1;
  if ((int)param_2 < 9) {
    if (param_2 != 8) {
      if (((param_2 == 1) || (param_2 == 2)) || ((param_2 == 3 || (param_2 == 4))))
      goto LAB_1800112b6;
      if (((param_2 != 5) && (param_2 != 6)) && (param_2 != 7)) {
LAB_180011296:
        return (CompGroup *)(this + 0x60);
      }
    }
    plVar1 = (longlong *)
             std::
             map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
             ::try_emplace<unsigned_long&___ptr64>
                       ((map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
                         *)(this + 0x40),local_18,local_res10);
    goto LAB_1800112ce;
  }
  if (((param_2 == 9) || (param_2 == 10)) || (param_2 == 0xb)) {
LAB_1800112b6:
    plVar1 = (longlong *)
             std::
             map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
             ::try_emplace<unsigned_long&___ptr64>
                       ((map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
                         *)(this + 0x50),local_18,local_res10);
  }
  else {
    if ((param_2 != 0xc) && (param_2 != 0xd)) {
      if (param_2 == 0xe) goto LAB_1800112b6;
      if (param_2 != 0xf) goto LAB_180011296;
    }
    plVar1 = (longlong *)
             std::
             map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
             ::try_emplace<unsigned_long&___ptr64>
                       ((map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
                         *)(this + 0x30),local_18,local_res10);
  }
LAB_1800112ce:
  return (CompGroup *)(*plVar1 + 0x28);
}



===== FindProperty @ 1800112e4 =====

/* public: struct _PKTMON_PROPERTY_OUT const * __ptr64 __cdecl PktMon::Component::FindProperty(enum
   _PKTMON_COMPONENT_PROPERTY_ID)const __ptr64 */

_PKTMON_PROPERTY_OUT * __thiscall
PktMon::Component::FindProperty(Component *this,_PKTMON_COMPONENT_PROPERTY_ID param_1)

{
  _PKTMON_PROPERTY_OUT *p_Var1;
  undefined8 *local_28;
  undefined8 *local_20;
  
  p_Var1 = (_PKTMON_PROPERTY_OUT *)0x0;
  GetRelated(this);
  for (; local_28 != local_20; local_28 = local_28 + 1) {
    p_Var1 = FindPropertyAux((Component *)*local_28,param_1);
    if (p_Var1 != (_PKTMON_PROPERTY_OUT *)0x0) break;
  }
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_28);
  return p_Var1;
}



===== FindPropertyAux @ 180011340 =====

/* private: struct _PKTMON_PROPERTY_OUT const * __ptr64 __cdecl
   PktMon::Component::FindPropertyAux(enum _PKTMON_COMPONENT_PROPERTY_ID)const __ptr64 */

_PKTMON_PROPERTY_OUT * __thiscall
PktMon::Component::FindPropertyAux(Component *this,_PKTMON_COMPONENT_PROPERTY_ID param_1)

{
  longlong lVar1;
  int iVar2;
  _PKTMON_COMPONENT_PROPERTY_ID *p_Var3;
  longlong lVar4;
  
  lVar1 = *(longlong *)this;
  iVar2 = 0;
  if (*(ushort *)(lVar1 + 0x1c8) != 0) {
    lVar4 = 0;
    p_Var3 = (_PKTMON_COMPONENT_PROPERTY_ID *)(lVar1 + 0x1cc);
    do {
      if (*p_Var3 == param_1) {
        return (_PKTMON_PROPERTY_OUT *)((longlong)iVar2 * 0x108 + 0x1cc + lVar1);
      }
      iVar2 = iVar2 + 1;
      lVar4 = lVar4 + 1;
      p_Var3 = p_Var3 + 0x42;
    } while (lVar4 < (longlong)(ulonglong)*(ushort *)(lVar1 + 0x1c8));
  }
  return (_PKTMON_PROPERTY_OUT *)0x0;
}



===== GetBoolean @ 180011394 =====

/* public: bool __cdecl NetSetup2::Property::GetBoolean(void)const __ptr64 */

bool __thiscall NetSetup2::Property::GetBoolean(Property *this)

{
  char cVar1;
  bool bVar2;
  undefined4 local_res8 [8];
  
  if (*(int *)(this + 0x14) != 0x11) {
    local_res8[0] = 0x8007065d;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&_TI1J);
  }
  if (*(longlong *)(this + 0x20) - (longlong)*(char **)(this + 0x18) != 1) {
    local_res8[0] = 0x8007000d;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&_TI1J);
  }
  cVar1 = **(char **)(this + 0x18);
  if (cVar1 == '\0') {
    bVar2 = false;
  }
  else {
    if (cVar1 != '\x01') {
      local_res8[0] = 0x8007000d;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res8,(ThrowInfo *)&_TI1J);
    }
    bVar2 = true;
  }
  return bVar2;
}



===== GetComponents @ 180011420 =====

/* public: virtual class std::vector<class PktMon::Component const * __ptr64,class
   std::allocator<class PktMon::Component const * __ptr64> > __cdecl
   PktMon::NicGroup::GetComponents(void)const __ptr64 */

void __thiscall PktMon::NicGroup::GetComponents(NicGroup *this)

{
  Component *pCVar1;
  Component **ppCVar2;
  vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_> *in_RDX
  ;
  ulonglong local_res8 [2];
  
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  local_res8[0] =
       (*(longlong *)(this + 0x28) - *(longlong *)(this + 0x20) >> 3) + 1 +
       (*(longlong *)(this + 0x40) - *(longlong *)(this + 0x38) >> 3) +
       (*(longlong *)(this + 0x58) - *(longlong *)(this + 0x50) >> 3);
  if (local_res8[0] != 0) {
    if (0x1fffffffffffffff < local_res8[0]) {
                    /* WARNING: Subroutine does not return */
      std::
      vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
      ::_Xlength();
    }
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::_Reallocate<0>(in_RDX,local_res8);
  }
  pCVar1 = *(Component **)(this + 0x10);
  if (pCVar1 != (Component *)0x0) {
    ppCVar2 = *(Component ***)(in_RDX + 8);
    if (ppCVar2 == *(Component ***)(in_RDX + 0x10)) {
      std::
      vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
      _Emplace_reallocate<PktMon::Component_const*___ptr64_const&___ptr64>
                (in_RDX,ppCVar2,(Component **)(this + 0x10));
    }
    else {
      *ppCVar2 = pCVar1;
      *(longlong *)(in_RDX + 8) = *(longlong *)(in_RDX + 8) + 8;
    }
  }
  pCVar1 = *(Component **)(this + 0x18);
  if (pCVar1 != (Component *)0x0) {
    ppCVar2 = *(Component ***)(in_RDX + 8);
    if (ppCVar2 == *(Component ***)(in_RDX + 0x10)) {
      std::
      vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
      _Emplace_reallocate<PktMon::Component_const*___ptr64_const&___ptr64>
                (in_RDX,ppCVar2,(Component **)(this + 0x18));
    }
    else {
      *ppCVar2 = pCVar1;
      *(longlong *)(in_RDX + 8) = *(longlong *)(in_RDX + 8) + 8;
    }
  }
  std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
  _Insert_counted_range<PktMon::Component_const*___ptr64*___ptr64>();
  std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
  _Insert_counted_range<PktMon::Component_const*___ptr64*___ptr64>();
  std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
  _Insert_counted_range<PktMon::Component_const*___ptr64*___ptr64>();
  return;
}



===== GetComponents @ 180011560 =====

/* public: virtual class std::vector<class PktMon::Component const * __ptr64,class
   std::allocator<class PktMon::Component const * __ptr64> > __cdecl
   PktMon::VMSwitch::GetComponents(void)const __ptr64 */

void __thiscall PktMon::VMSwitch::GetComponents(VMSwitch *this)

{
  undefined8 *puVar1;
  Component *pCVar2;
  Component **ppCVar3;
  vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_> *in_RDX
  ;
  undefined8 *puVar4;
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
  local_30 [24];
  
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  puVar1 = *(undefined8 **)(this + 0x18);
  for (puVar4 = *(undefined8 **)(this + 0x10); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    NicGroup::GetComponents((NicGroup *)*puVar4);
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::_Insert_counted_range<PktMon::Component_const*___ptr64*___ptr64>();
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              (local_30);
  }
  pCVar2 = *(Component **)(this + 0x28);
  if (pCVar2 != (Component *)0x0) {
    ppCVar3 = *(Component ***)(in_RDX + 8);
    if (ppCVar3 == *(Component ***)(in_RDX + 0x10)) {
      std::
      vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
      _Emplace_reallocate<PktMon::Component_const*___ptr64_const&___ptr64>
                (in_RDX,ppCVar3,(Component **)(this + 0x28));
    }
    else {
      *ppCVar3 = pCVar2;
      *(longlong *)(in_RDX + 8) = *(longlong *)(in_RDX + 8) + 8;
    }
  }
  if (*(NicGroup **)(this + 0x30) != (NicGroup *)0x0) {
    NicGroup::GetComponents(*(NicGroup **)(this + 0x30));
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::_Insert_counted_range<PktMon::Component_const*___ptr64*___ptr64>();
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              (local_30);
  }
  puVar1 = *(undefined8 **)(this + 0x40);
  for (puVar4 = *(undefined8 **)(this + 0x38); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    NicGroup::GetComponents((NicGroup *)*puVar4);
    std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
    ::_Insert_counted_range<PktMon::Component_const*___ptr64*___ptr64>();
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              (local_30);
  }
  std::vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
  _Insert_counted_range<PktMon::Component_const*___ptr64*___ptr64>();
  return;
}



===== GetCounters @ 1800116bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl PktMon::Component::GetCounters(struct PktMon::CounterFilter const &
   __ptr64,class std::vector<struct PktMon::CounterInfo,class std::allocator<struct
   PktMon::CounterInfo> > & __ptr64)const __ptr64 */

void __thiscall
PktMon::Component::GetCounters
          (Component *this,CounterFilter *param_1,
          vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *param_2)

{
  Component *this_00;
  CounterInfo *pCVar1;
  undefined8 uVar2;
  CounterFilter *pCVar3;
  longlong lVar4;
  CounterInfo *pCVar5;
  longlong lVar6;
  CounterInfo *pCVar7;
  ushort *puVar8;
  undefined8 *puVar9;
  int iVar10;
  bool bVar11;
  undefined1 auStackY_128 [32];
  CounterType local_e4;
  int local_e0;
  CounterInfo *local_d8;
  CounterInfo *pCStack_d0;
  CounterInfo *local_c8;
  CounterFilter *local_c0;
  undefined8 *local_b8;
  undefined8 *local_b0;
  undefined8 local_98;
  undefined8 uStack_90;
  int local_88;
  undefined4 uStack_84;
  longlong lStack_80;
  longlong local_78;
  int iStack_70;
  undefined4 uStack_6c;
  longlong local_68;
  longlong lStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  if ((*param_1 == (CounterFilter)0x0) || (*(char *)(*(longlong *)this + 0x188) != '\0')) {
    iVar10 = *(int *)(param_1 + 4);
    bVar11 = iVar10 != 2;
    local_e0 = iVar10;
    local_c0 = param_1;
    GetRelated(this);
    for (puVar9 = local_b8; puVar9 != local_b0; puVar9 = puVar9 + 1) {
      this_00 = (Component *)*puVar9;
      if (bVar11) {
        bVar11 = param_1[9] != (CounterFilter)0x0;
        GetDropCounters(this_00,SUB81(&local_98,0));
        if (((param_1[8] != (CounterFilter)0x0) ||
            ((local_88 != 0 && ((lStack_80 != 0 || (local_78 != 0)))))) ||
           ((iStack_70 != 0 && ((local_68 != 0 || (lStack_60 != 0)))))) {
          pCVar5 = *(CounterInfo **)(param_2 + 8);
          if (pCVar5 == *(CounterInfo **)(param_2 + 0x10)) {
            std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
            _Emplace_reallocate<PktMon::CounterInfo&___ptr64>
                      (param_2,pCVar5,(CounterInfo *)&local_98);
          }
          else {
            *(undefined8 *)pCVar5 = local_98;
            *(undefined8 *)(pCVar5 + 8) = uStack_90;
            *(ulonglong *)(pCVar5 + 0x10) = CONCAT44(uStack_84,local_88);
            *(longlong *)(pCVar5 + 0x18) = lStack_80;
            *(longlong *)(pCVar5 + 0x20) = local_78;
            *(ulonglong *)(pCVar5 + 0x28) = CONCAT44(uStack_6c,iStack_70);
            *(longlong *)(pCVar5 + 0x30) = local_68;
            *(longlong *)(pCVar5 + 0x38) = lStack_60;
            *(undefined4 *)(pCVar5 + 0x40) = local_58;
            *(undefined4 *)(pCVar5 + 0x44) = uStack_54;
            *(undefined4 *)(pCVar5 + 0x48) = uStack_50;
            *(undefined4 *)(pCVar5 + 0x4c) = uStack_4c;
            *(longlong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + 0x50;
          }
        }
      }
      if (iVar10 != 1) {
        local_d8 = (CounterInfo *)0x0;
        pCStack_d0 = (CounterInfo *)0x0;
        pCVar5 = (CounterInfo *)0x0;
        local_c8 = (CounterInfo *)0x0;
        iVar10 = 0;
        lVar4 = *(longlong *)this_00;
        if (*(short *)(lVar4 + 0xe2c) != 0) {
          lVar6 = 0;
          do {
            if (0x57f < lVar6) break;
            puVar8 = (ushort *)(lVar4 + 0xe30 + lVar6);
            local_e4 = 2;
            if (pCStack_d0 == pCVar5) {
              std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
              _Emplace_reallocate<PktMon::Component_const&___ptr64,unsigned_short_const_(&___ptr64)[64],_PKTMON_COUNTER_SET_const&___ptr64,PktMon::CounterType>
                        ((vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *)
                         &local_d8,pCStack_d0,this_00,puVar8,(_PKTMON_COUNTER_SET *)(puVar8 + 0x40),
                         &local_e4);
              pCVar5 = local_c8;
            }
            else {
              *(Component **)pCStack_d0 = this_00;
              *(ushort **)(pCStack_d0 + 8) = puVar8;
              uVar2 = *(undefined8 *)(puVar8 + 0x44);
              *(undefined8 *)(pCStack_d0 + 0x10) = *(undefined8 *)(puVar8 + 0x40);
              *(undefined8 *)(pCStack_d0 + 0x18) = uVar2;
              *(undefined8 *)(pCStack_d0 + 0x20) = *(undefined8 *)(puVar8 + 0x48);
              uVar2 = *(undefined8 *)(puVar8 + 0x50);
              *(undefined8 *)(pCStack_d0 + 0x28) = *(undefined8 *)(puVar8 + 0x4c);
              *(undefined8 *)(pCStack_d0 + 0x30) = uVar2;
              *(undefined8 *)(pCStack_d0 + 0x38) = *(undefined8 *)(puVar8 + 0x54);
              *(undefined4 *)(pCStack_d0 + 0x40) = 2;
              pCStack_d0[0x44] = (CounterInfo)0x0;
              *(undefined4 *)(pCStack_d0 + 0x48) = 0;
              pCStack_d0 = pCStack_d0 + 0x50;
            }
            iVar10 = iVar10 + 1;
            lVar6 = lVar6 + 0xb0;
            lVar4 = *(longlong *)this_00;
          } while (iVar10 < (int)(uint)*(ushort *)(lVar4 + 0xe2c));
        }
        pCVar3 = local_c0;
        pCVar5 = pCStack_d0;
        if (local_d8 != pCStack_d0) {
          pCVar7 = local_d8 + 0x18;
          do {
            if (((pCVar3[8] != (CounterFilter)0x0) ||
                ((*(int *)(pCVar7 + -8) != 0 &&
                 ((*(longlong *)pCVar7 != 0 || (*(longlong *)(pCVar7 + 8) != 0)))))) ||
               ((*(int *)(pCVar7 + 0x10) != 0 &&
                ((*(longlong *)(pCVar7 + 0x18) != 0 || (*(longlong *)(pCVar7 + 0x20) != 0)))))) {
              pCVar1 = *(CounterInfo **)(param_2 + 8);
              if (pCVar1 == *(CounterInfo **)(param_2 + 0x10)) {
                std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
                _Emplace_reallocate<PktMon::CounterInfo&___ptr64>(param_2,pCVar1,pCVar7 + -0x18);
              }
              else {
                lVar4 = *(longlong *)(pCVar7 + -0x10);
                *(undefined8 *)pCVar1 = *(undefined8 *)(pCVar7 + -0x18);
                *(longlong *)(pCVar1 + 8) = lVar4;
                lVar4 = *(longlong *)pCVar7;
                *(longlong *)(pCVar1 + 0x10) = *(longlong *)(pCVar7 + -8);
                *(longlong *)(pCVar1 + 0x18) = lVar4;
                lVar4 = *(longlong *)(pCVar7 + 0x10);
                *(longlong *)(pCVar1 + 0x20) = *(longlong *)(pCVar7 + 8);
                *(longlong *)(pCVar1 + 0x28) = lVar4;
                lVar4 = *(longlong *)(pCVar7 + 0x20);
                *(longlong *)(pCVar1 + 0x30) = *(longlong *)(pCVar7 + 0x18);
                *(longlong *)(pCVar1 + 0x38) = lVar4;
                lVar4 = *(longlong *)(pCVar7 + 0x30);
                *(longlong *)(pCVar1 + 0x40) = *(longlong *)(pCVar7 + 0x28);
                *(longlong *)(pCVar1 + 0x48) = lVar4;
                *(longlong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + 0x50;
              }
            }
            pCVar1 = pCVar7 + 0x38;
            pCVar7 = pCVar7 + 0x50;
          } while (pCVar1 != pCVar5);
        }
        std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
        ~vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>
                  ((vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *)&local_d8);
        param_1 = local_c0;
        iVar10 = local_e0;
      }
    }
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_b8);
  }
  return;
}



===== GetCounters @ 1800119e0 =====

/* public: virtual void __cdecl PktMon::GatewayGroup::GetCounters(struct PktMon::CounterFilter const
   & __ptr64,class std::vector<struct PktMon::CounterInfo,class std::allocator<struct
   PktMon::CounterInfo> > & __ptr64)const __ptr64 */

void __thiscall
PktMon::GatewayGroup::GetCounters
          (GatewayGroup *this,CounterFilter *param_1,
          vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = *(undefined8 **)(this + 0x18);
  for (puVar2 = *(undefined8 **)(this + 0x10); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    Component::GetCounters((Component *)*puVar2,param_1,param_2);
  }
  if (*(longlong *)param_2 != *(longlong *)(param_2 + 8)) {
    *(undefined4 *)(*(longlong *)(param_2 + 8) + -8) = 0;
  }
  return;
}



===== GetCounters @ 180011a50 =====

/* public: virtual void __cdecl PktMon::NicGroup::GetCounters(struct PktMon::CounterFilter const &
   __ptr64,class std::vector<struct PktMon::CounterInfo,class std::allocator<struct
   PktMon::CounterInfo> > & __ptr64)const __ptr64 */

void __thiscall
PktMon::NicGroup::GetCounters
          (NicGroup *this,CounterFilter *param_1,
          vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *param_2)

{
  undefined8 *puVar1;
  bool bVar2;
  Component *this_00;
  undefined8 *puVar3;
  
  if ((param_1[9] == (CounterFilter)0x0) && (bVar2 = IsHidden(this), bVar2)) {
    return;
  }
  this_00 = *(Component **)(this + 0x10);
  if (this_00 == (Component *)0x0) {
    if (*(longlong *)(this + 0x18) == 0) goto LAB_180011ada;
    this_00 = *(Component **)(this + 0x18);
  }
  Component::GetCounters(this_00,param_1,param_2);
  if ((*(longlong *)(this + 0x10) != 0) && (*(longlong *)(this + 0x18) != 0)) {
    Component::GetCounters(*(Component **)(this + 0x18),param_1,param_2);
  }
  if (*(longlong *)param_2 != *(longlong *)(param_2 + 8)) {
    *(undefined4 *)(*(longlong *)(param_2 + 8) + -8) = 1;
  }
LAB_180011ada:
  puVar1 = *(undefined8 **)(this + 0x28);
  for (puVar3 = *(undefined8 **)(this + 0x20); puVar3 != puVar1; puVar3 = puVar3 + 1) {
    Component::GetCounters((Component *)*puVar3,param_1,param_2);
  }
  if (*(longlong *)param_2 != *(longlong *)(param_2 + 8)) {
    *(undefined4 *)(*(longlong *)(param_2 + 8) + -8) = 1;
  }
  puVar1 = *(undefined8 **)(this + 0x40);
  for (puVar3 = *(undefined8 **)(this + 0x38); puVar3 != puVar1; puVar3 = puVar3 + 1) {
    Component::GetCounters((Component *)*puVar3,param_1,param_2);
  }
  if (*(longlong *)param_2 != *(longlong *)(param_2 + 8)) {
    *(undefined4 *)(*(longlong *)(param_2 + 8) + -8) = 1;
  }
  puVar1 = *(undefined8 **)(this + 0x58);
  for (puVar3 = *(undefined8 **)(this + 0x50); puVar3 != puVar1; puVar3 = puVar3 + 1) {
    Component::GetCounters((Component *)*puVar3,param_1,param_2);
  }
  if (*(longlong *)param_2 != *(longlong *)(param_2 + 8)) {
    *(undefined4 *)(*(longlong *)(param_2 + 8) + -8) = 0;
  }
  return;
}



===== GetCounters @ 180011b90 =====

/* public: virtual void __cdecl PktMon::VMSwitch::GetCounters(struct PktMon::CounterFilter const &
   __ptr64,class std::vector<struct PktMon::CounterInfo,class std::allocator<struct
   PktMon::CounterInfo> > & __ptr64)const __ptr64 */

void __thiscall
PktMon::VMSwitch::GetCounters
          (VMSwitch *this,CounterFilter *param_1,
          vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *param_2)

{
  vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *pvVar1;
  undefined8 *puVar2;
  CounterInfo *pCVar3;
  longlong lVar4;
  undefined8 uVar5;
  CounterInfo *pCVar6;
  undefined8 *puVar7;
  CounterInfo *pCVar8;
  CounterInfo *pCVar9;
  CounterInfo *local_38;
  CounterInfo *pCStack_30;
  undefined8 local_28;
  
  puVar2 = *(undefined8 **)(this + 0x18);
  pvVar1 = param_2 + 8;
  for (puVar7 = *(undefined8 **)(this + 0x10); puVar7 != puVar2; puVar7 = puVar7 + 1) {
    NicGroup::GetCounters((NicGroup *)*puVar7,param_1,param_2);
    if (*(longlong *)param_2 != *(longlong *)pvVar1) {
      *(undefined4 *)(*(longlong *)pvVar1 + -8) = 2;
    }
  }
  if (*(Component **)(this + 0x28) != (Component *)0x0) {
    Component::GetCounters(*(Component **)(this + 0x28),param_1,param_2);
    if (*(longlong *)param_2 != *(longlong *)pvVar1) {
      *(undefined4 *)(*(longlong *)pvVar1 + -8) = 2;
    }
  }
  if (*(longlong *)(this + 0x30) != 0) {
    if (*(longlong *)param_2 != *(longlong *)pvVar1) {
      *(undefined4 *)(*(longlong *)pvVar1 + -8) = 2;
    }
    local_38 = (CounterInfo *)0x0;
    pCStack_30 = (CounterInfo *)0x0;
    local_28 = 0;
    NicGroup::GetCounters
              (*(NicGroup **)(this + 0x30),param_1,
               (vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *)&local_38);
    pCVar6 = local_38;
    pCVar8 = pCStack_30;
    while (pCVar8 != pCVar6) {
      pCVar9 = pCVar8 + -0x50;
      pCVar3 = *(CounterInfo **)(param_2 + 8);
      if (pCVar3 == *(CounterInfo **)(param_2 + 0x10)) {
        std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
        _Emplace_reallocate<PktMon::CounterInfo&___ptr64>(param_2,pCVar3,pCVar9);
      }
      else {
        uVar5 = *(undefined8 *)(pCVar8 + -0x48);
        *(undefined8 *)pCVar3 = *(undefined8 *)pCVar9;
        *(undefined8 *)(pCVar3 + 8) = uVar5;
        uVar5 = *(undefined8 *)(pCVar8 + -0x38);
        *(undefined8 *)(pCVar3 + 0x10) = *(undefined8 *)(pCVar8 + -0x40);
        *(undefined8 *)(pCVar3 + 0x18) = uVar5;
        uVar5 = *(undefined8 *)(pCVar8 + -0x28);
        *(undefined8 *)(pCVar3 + 0x20) = *(undefined8 *)(pCVar8 + -0x30);
        *(undefined8 *)(pCVar3 + 0x28) = uVar5;
        uVar5 = *(undefined8 *)(pCVar8 + -0x18);
        *(undefined8 *)(pCVar3 + 0x30) = *(undefined8 *)(pCVar8 + -0x20);
        *(undefined8 *)(pCVar3 + 0x38) = uVar5;
        uVar5 = *(undefined8 *)(pCVar8 + -8);
        *(undefined8 *)(pCVar3 + 0x40) = *(undefined8 *)(pCVar8 + -0x10);
        *(undefined8 *)(pCVar3 + 0x48) = uVar5;
        *(longlong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + 0x50;
      }
      lVar4 = *(longlong *)(param_2 + 8);
      *(undefined8 *)(lVar4 + -0x40) = *(undefined8 *)(lVar4 + -0x28);
      *(undefined8 *)(lVar4 + -0x38) = *(undefined8 *)(lVar4 + -0x20);
      *(undefined8 *)(lVar4 + -0x30) = *(undefined8 *)(lVar4 + -0x18);
      *(undefined4 *)(lVar4 + -0x40) = 5;
      *(undefined4 *)(lVar4 + -0x28) = 0;
      *(undefined4 *)(lVar4 + -8) = 0;
      pCVar8 = pCVar9;
    }
    for (; pCVar6 != pCStack_30; pCVar6 = pCVar6 + 0x50) {
      pCVar8 = *(CounterInfo **)(param_2 + 8);
      if (pCVar8 == *(CounterInfo **)(param_2 + 0x10)) {
        std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
        _Emplace_reallocate<PktMon::CounterInfo&___ptr64>(param_2,pCVar8,pCVar6);
      }
      else {
        uVar5 = *(undefined8 *)(pCVar6 + 8);
        *(undefined8 *)pCVar8 = *(undefined8 *)pCVar6;
        *(undefined8 *)(pCVar8 + 8) = uVar5;
        uVar5 = *(undefined8 *)(pCVar6 + 0x18);
        *(undefined8 *)(pCVar8 + 0x10) = *(undefined8 *)(pCVar6 + 0x10);
        *(undefined8 *)(pCVar8 + 0x18) = uVar5;
        uVar5 = *(undefined8 *)(pCVar6 + 0x28);
        *(undefined8 *)(pCVar8 + 0x20) = *(undefined8 *)(pCVar6 + 0x20);
        *(undefined8 *)(pCVar8 + 0x28) = uVar5;
        uVar5 = *(undefined8 *)(pCVar6 + 0x38);
        *(undefined8 *)(pCVar8 + 0x30) = *(undefined8 *)(pCVar6 + 0x30);
        *(undefined8 *)(pCVar8 + 0x38) = uVar5;
        uVar5 = *(undefined8 *)(pCVar6 + 0x48);
        *(undefined8 *)(pCVar8 + 0x40) = *(undefined8 *)(pCVar6 + 0x40);
        *(undefined8 *)(pCVar8 + 0x48) = uVar5;
        *(longlong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + 0x50;
      }
      lVar4 = *(longlong *)(param_2 + 8);
      *(undefined4 *)(lVar4 + -0x40) = 6;
      *(undefined4 *)(lVar4 + -0x28) = 0;
      *(undefined4 *)(lVar4 + -8) = 0;
    }
    if (*(longlong *)param_2 != *(longlong *)(param_2 + 8)) {
      *(undefined4 *)(*(longlong *)(param_2 + 8) + -8) = 2;
    }
    std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
    ~vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>
              ((vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *)&local_38);
  }
  puVar2 = *(undefined8 **)(this + 0x40);
  for (puVar7 = *(undefined8 **)(this + 0x38); puVar7 != puVar2; puVar7 = puVar7 + 1) {
    NicGroup::GetCounters((NicGroup *)*puVar7,param_1,param_2);
    if (*(longlong *)param_2 != *(longlong *)(param_2 + 8)) {
      *(undefined4 *)(*(longlong *)(param_2 + 8) + -8) = 2;
    }
  }
  puVar2 = *(undefined8 **)(this + 0x58);
  for (puVar7 = *(undefined8 **)(this + 0x50); puVar7 != puVar2; puVar7 = puVar7 + 1) {
    Component::GetCounters((Component *)*puVar7,param_1,param_2);
  }
  if (*(longlong *)param_2 != *(longlong *)(param_2 + 8)) {
    *(undefined4 *)(*(longlong *)(param_2 + 8) + -8) = 0;
  }
  return;
}



===== GetDescription @ 180011dc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > __cdecl PktMon::Component::GetDescription(bool)const __ptr64 */

basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_> *
__thiscall PktMon::Component::GetDescription(Component *this,bool param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar4;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar5;
  undefined7 in_register_00000011;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *this_00;
  wchar_t *pwVar6;
  ulonglong uVar7;
  undefined8 ***pppuVar8;
  __uint64 _Var9;
  void *_Src;
  undefined1 auStack_f8 [32];
  ulonglong local_d8;
  undefined4 local_c8;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *local_c0;
  undefined8 ***local_b8;
  undefined8 uStack_b0;
  longlong local_a8;
  ulonglong uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  local_58 [32];
  ulonglong local_38;
  
  this_00 = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
             *)CONCAT71(in_register_00000011,param_1);
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  local_c8 = 0;
  lVar3 = *(longlong *)this;
  *(undefined8 *)this_00 = 0;
  *(undefined8 *)(this_00 + 8) = 0;
  *(undefined8 *)(this_00 + 0x10) = 0;
  *(undefined8 *)(this_00 + 0x18) = 0;
  uVar7 = 0xffffffffffffffff;
  _Var9 = 0xffffffffffffffff;
  do {
    _Var9 = _Var9 + 1;
  } while (((ushort *)(lVar3 + 0x80))[_Var9] != 0);
  local_c0 = this_00;
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::_Construct<1,unsigned_short_const*___ptr64>(this_00,(ushort *)(lVar3 + 0x80),_Var9);
  local_c8 = 1;
  iVar2 = *(int *)(*(longlong *)this + 0x180);
  if (iVar2 == 6) {
    local_98 = 0;
    uStack_90 = 0;
    local_88 = 0;
    uStack_80 = 0;
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    _Construct<1,unsigned_short_const*___ptr64>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_98,(ushort *)L")",1);
    local_b8 = (undefined8 ***)0x0;
    uStack_b0 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    _Construct<1,unsigned_short_const*___ptr64>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_b8,(ushort *)L"vEthernet (",0xb);
    lVar3 = local_a8;
    uVar7 = *(ulonglong *)(this_00 + 0x10);
    pbVar5 = this_00;
    if (7 < *(ulonglong *)(this_00 + 0x18)) {
      pbVar5 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 **)this_00;
    }
    if (uStack_a0 - local_a8 < uVar7) {
      local_d8 = uVar7;
      pbVar4 = std::
               basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
               ::
               _Reallocate_grow_by<<lambda_7030d12a21dba11210293044e97fe9c7>,unsigned_short_const*___ptr64,unsigned___int64>
                         ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                           *)&local_b8,uVar7);
    }
    else {
      pppuVar8 = &local_b8;
      if (7 < uStack_a0) {
        pppuVar8 = local_b8;
      }
      lVar1 = local_a8 * 2;
      local_a8 = local_a8 + uVar7;
      memmove((void *)((longlong)pppuVar8 + lVar1),pbVar5,uVar7 * 2);
      *(undefined2 *)((longlong)pppuVar8 + (uVar7 + lVar3) * 2) = 0;
      pbVar4 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                *)&local_b8;
    }
    local_78 = *(undefined8 *)pbVar4;
    uStack_70 = *(undefined8 *)(pbVar4 + 8);
    local_68 = *(undefined8 *)(pbVar4 + 0x10);
    uStack_60 = *(undefined8 *)(pbVar4 + 0x18);
    *(undefined8 *)(pbVar4 + 0x10) = 0;
    *(undefined8 *)(pbVar4 + 0x18) = 7;
    *(undefined2 *)pbVar4 = 0;
    local_c8 = 3;
    pbVar4 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              *)std::
                operator+<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                          (local_58,(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                                     *)&local_78);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    operator=(this_00,pbVar4);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)local_58);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_78);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_b8);
    pbVar5 = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)&local_98;
LAB_18001201c:
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              (pbVar5);
  }
  else {
    if (iVar2 == 7) {
      if (this == *(Component **)(this + 0x10)) {
        pwVar6 = L"VMS ExtMp";
        goto LAB_180011e71;
      }
      _Src = (void *)(*(longlong *)*(Component **)(this + 0x10) + 0x80);
      do {
        uVar7 = uVar7 + 1;
      } while (*(short *)((longlong)_Src + uVar7 * 2) != 0);
      if (*(ulonglong *)(this_00 + 0x18) < uVar7) {
        std::
        basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
        ::_Reallocate_for<<lambda_05cef1f6fdf474c9f3ed207deba0f73b>,unsigned_short_const*___ptr64>
                  (this_00,uVar7);
      }
      else {
        pbVar5 = this_00;
        if (7 < *(ulonglong *)(this_00 + 0x18)) {
          pbVar5 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                     **)this_00;
        }
        *(ulonglong *)(this_00 + 0x10) = uVar7;
        memmove(pbVar5,_Src,uVar7 * 2);
        *(undefined2 *)(pbVar5 + uVar7 * 2) = 0;
      }
    }
    else {
      if (iVar2 == 8) {
        pwVar6 = L"VMS PtNic";
LAB_180011e71:
        local_a8 = 0;
        uStack_a0 = 0;
        local_b8 = (undefined8 ***)0x0;
        uStack_b0 = 0;
        std::
        basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
        ::_Construct<1,unsigned_short_const*___ptr64>
                  ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                    *)&local_b8,(ushort *)pwVar6,9);
        std::
        basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
        ::operator=(this_00,(basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                             *)&local_b8);
        pbVar5 = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_b8;
        goto LAB_18001201c;
      }
      if (iVar2 == 10) {
        return this_00;
      }
    }
    ShortenDescription(this_00);
  }
  return this_00;
}



===== GetDropCounters @ 180012050 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: struct PktMon::CounterInfo __cdecl PktMon::Component::GetDropCounters(bool)const __ptr64
    */

undefined8 * __thiscall PktMon::Component::GetDropCounters(Component *this,bool param_1)

{
  undefined8 uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined7 in_register_00000011;
  undefined8 *puVar5;
  char in_R8B;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  longlong lStack_50;
  longlong local_48;
  undefined8 uStack_40;
  longlong local_38;
  longlong lStack_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined8 uStack_20;
  ulonglong local_18;
  
  puVar5 = (undefined8 *)CONCAT71(in_register_00000011,param_1);
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  if (in_R8B == '\0') {
    lVar3 = *(longlong *)this;
    *puVar5 = this;
    puVar5[1] = lVar3;
    uVar1 = *(undefined8 *)(lVar3 + 0x198);
    puVar5[2] = *(undefined8 *)(lVar3 + 400);
    puVar5[3] = uVar1;
    puVar5[4] = *(undefined8 *)(lVar3 + 0x1a0);
    uVar1 = *(undefined8 *)(lVar3 + 0x1b0);
    puVar5[5] = *(undefined8 *)(lVar3 + 0x1a8);
    puVar5[6] = uVar1;
    uVar1 = *(undefined8 *)(lVar3 + 0x1b8);
    *(undefined4 *)(puVar5 + 9) = 0;
    puVar5[7] = uVar1;
    *(undefined4 *)(puVar5 + 8) = 1;
    *(undefined1 *)((longlong)puVar5 + 0x44) = 0;
  }
  else {
    GetDropCounters(*(Component **)(this + 8),SUB81(&local_68,0));
    plVar2 = *(longlong **)(this + 8);
    uStack_24 = CONCAT31(uStack_24._1_3_,1);
    plVar4 = (longlong *)plVar2[2];
    if (plVar4 != plVar2) {
      do {
        lVar3 = *plVar4;
        lStack_50 = lStack_50 + *(longlong *)(lVar3 + 0x198);
        local_48 = local_48 + *(longlong *)(lVar3 + 0x1a0);
        local_38 = local_38 + *(longlong *)(lVar3 + 0x1b0);
        lStack_30 = lStack_30 + *(longlong *)(lVar3 + 0x1b8);
        plVar4 = (longlong *)plVar4[2];
      } while (plVar4 != plVar2);
    }
    *puVar5 = local_68;
    puVar5[1] = uStack_60;
    puVar5[2] = local_58;
    puVar5[3] = lStack_50;
    puVar5[4] = local_48;
    puVar5[5] = uStack_40;
    puVar5[6] = local_38;
    puVar5[7] = lStack_30;
    puVar5[8] = CONCAT44(uStack_24,local_28);
    puVar5[9] = uStack_20;
  }
  return puVar5;
}



===== GetGateways @ 180012188 =====

/* public: class std::vector<class PktMon::GatewayGroup const * __ptr64,class std::allocator<class
   PktMon::GatewayGroup const * __ptr64> > __cdecl PktMon::CompList::GetGateways(void)const __ptr64
    */

void __thiscall PktMon::CompList::GetGateways(CompList *this)

{
  char cVar1;
  Component **ppCVar2;
  longlong *plVar3;
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *in_RDX;
  longlong *plVar4;
  longlong *plVar5;
  Component *local_res8 [2];
  
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  local_res8[0] = *(Component **)(this + 0x38);
  if (local_res8[0] != (Component *)0x0) {
    if ((Component *)0x1fffffffffffffff < local_res8[0]) {
                    /* WARNING: Subroutine does not return */
      std::
      vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
      ::_Xlength();
    }
    std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
    _Reallocate<0>(in_RDX,(__uint64 *)local_res8);
  }
  plVar4 = (longlong *)**(undefined8 **)(this + 0x30);
  while (*(char *)((longlong)plVar4 + 0x19) == '\0') {
    local_res8[0] = (Component *)(plVar4 + 5);
    if (*(char *)((longlong)plVar4 + 0x34) == '\0') {
      ppCVar2 = *(Component ***)(in_RDX + 8);
      if (ppCVar2 == *(Component ***)(in_RDX + 0x10)) {
        std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
        _Emplace_reallocate<PktMon::Component*___ptr64>(in_RDX,ppCVar2,local_res8);
      }
      else {
        *ppCVar2 = local_res8[0];
        *(longlong *)(in_RDX + 8) = *(longlong *)(in_RDX + 8) + 8;
      }
    }
    plVar3 = (longlong *)plVar4[2];
    if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar3 + 0x19);
      plVar4 = plVar3;
      plVar3 = (longlong *)*plVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar3 + 0x19);
        plVar4 = plVar3;
        plVar3 = (longlong *)*plVar3;
      }
    }
    else {
      plVar3 = (longlong *)plVar4[1];
      plVar5 = plVar4;
      while ((plVar4 = plVar3, *(char *)((longlong)plVar4 + 0x19) == '\0' &&
             (plVar5 == (longlong *)plVar4[2]))) {
        plVar3 = (longlong *)plVar4[1];
        plVar5 = plVar4;
      }
    }
  }
  return;
}



===== GetGroups @ 180012284 =====

/* public: class std::vector<class PktMon::CompGroup const * __ptr64,class std::allocator<class
   PktMon::CompGroup const * __ptr64> > __cdecl PktMon::CompList::GetGroups(void)const __ptr64 */

void __thiscall PktMon::CompList::GetGroups(CompList *this)

{
  vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_> *in_RDX
  ;
  ulonglong local_res18;
  longlong local_50;
  longlong local_48;
  longlong local_38;
  longlong local_30;
  longlong local_20;
  longlong local_18;
  
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  GetVMSwitches(this);
  GetNics(this);
  GetGateways(this);
  local_res18 = (local_30 - local_38 >> 3) + (local_48 - local_50 >> 3) + (local_18 - local_20 >> 3)
  ;
  if ((ulonglong)(*(longlong *)(in_RDX + 0x10) - *(longlong *)in_RDX >> 3) < local_res18) {
    if (0x1fffffffffffffff < local_res18) {
                    /* WARNING: Subroutine does not return */
      std::
      vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
      ::_Xlength();
    }
    std::vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>
    ::_Reallocate<0>(in_RDX,&local_res18);
  }
  std::vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>::
  _Insert_counted_range<PktMon::VMSwitch_const*___ptr64*___ptr64>();
  std::vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>::
  _Insert_counted_range<PktMon::VMSwitch_const*___ptr64*___ptr64>();
  std::vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>::
  _Insert_counted_range<PktMon::VMSwitch_const*___ptr64*___ptr64>();
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_50);
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_38);
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_20);
  return;
}



===== GetName @ 1800123d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual class std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> > __cdecl PktMon::GatewayGroup::GetName(void)const
   __ptr64 */

void __thiscall PktMon::GatewayGroup::GetName(GatewayGroup *this)

{
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar1;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *in_RDX;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  local_38 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  *(undefined8 *)(in_RDX + 0x18) = 0;
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::_Construct<1,unsigned_short_const*___ptr64>(in_RDX,(ushort *)L"EmptyGroup",10);
  local_48 = 1;
  if (*(undefined8 **)(this + 0x10) != *(undefined8 **)(this + 0x18)) {
    pbVar1 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              *)Component::GetDescription
                          ((Component *)**(undefined8 **)(this + 0x10),SUB81(local_38,0));
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    operator=(in_RDX,pbVar1);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              (local_38);
  }
  return;
}



===== GetName @ 180012480 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual class std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> > __cdecl PktMon::NicGroup::GetName(void)const
   __ptr64 */

void __thiscall PktMon::NicGroup::GetName(NicGroup *this)

{
  Component *pCVar1;
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar2;
  Component *this_00;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *in_RDX;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  local_38 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  *(undefined8 *)(in_RDX + 0x18) = 7;
  *(undefined2 *)in_RDX = 0;
  local_48 = 1;
  this_00 = *(Component **)(this + 0x10);
  pCVar1 = this_00;
  if (this_00 == (Component *)0x0) {
    pCVar1 = *(Component **)(this + 0x18);
  }
  if (pCVar1 != (Component *)0x0) {
    if (this_00 == (Component *)0x0) {
      this_00 = *(Component **)(this + 0x18);
    }
    pbVar2 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              *)Component::GetDescription(this_00,SUB81(local_38,0));
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    operator=(in_RDX,pbVar2);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              (local_38);
  }
  return;
}



===== GetName @ 180012520 =====

/* public: virtual class std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> > __cdecl PktMon::VMSwitch::GetName(void)const
   __ptr64 */

void __thiscall PktMon::VMSwitch::GetName(VMSwitch *this)

{
  longlong lVar1;
  _PKTMON_PROPERTY_OUT *p_Var2;
  Component *this_00;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *in_RDX;
  
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  *(undefined8 *)(in_RDX + 0x18) = 7;
  *(undefined2 *)in_RDX = 0;
  lVar1 = *(longlong *)(this + 0x30);
  if ((lVar1 != 0) &&
     ((this_00 = *(Component **)(lVar1 + 0x10), this_00 != (Component *)0x0 ||
      (this_00 = *(Component **)(lVar1 + 0x18), this_00 != (Component *)0x0)))) {
    p_Var2 = Component::FindProperty(this_00,10);
    if (p_Var2 != (_PKTMON_PROPERTY_OUT *)0x0) {
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::operator+=(in_RDX,(ushort *)(p_Var2 + 6));
    }
  }
  return;
}



===== GetNics @ 1800125a0 =====

/* public: class std::vector<class PktMon::NicGroup const * __ptr64,class std::allocator<class
   PktMon::NicGroup const * __ptr64> > __cdecl PktMon::CompList::GetNics(void)const __ptr64 */

void __thiscall PktMon::CompList::GetNics(CompList *this)

{
  char cVar1;
  Component **ppCVar2;
  longlong *plVar3;
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *in_RDX;
  longlong *plVar4;
  longlong *plVar5;
  Component *local_res8 [2];
  
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  local_res8[0] = *(Component **)(this + 0x58);
  if (local_res8[0] != (Component *)0x0) {
    if ((Component *)0x1fffffffffffffff < local_res8[0]) {
                    /* WARNING: Subroutine does not return */
      std::
      vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
      ::_Xlength();
    }
    std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
    _Reallocate<0>(in_RDX,(__uint64 *)local_res8);
  }
  plVar4 = (longlong *)**(undefined8 **)(this + 0x50);
  while (*(char *)((longlong)plVar4 + 0x19) == '\0') {
    local_res8[0] = (Component *)(plVar4 + 5);
    if (*(char *)((longlong)plVar4 + 0x34) == '\0') {
      ppCVar2 = *(Component ***)(in_RDX + 8);
      if (ppCVar2 == *(Component ***)(in_RDX + 0x10)) {
        std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
        _Emplace_reallocate<PktMon::Component*___ptr64>(in_RDX,ppCVar2,local_res8);
      }
      else {
        *ppCVar2 = local_res8[0];
        *(longlong *)(in_RDX + 8) = *(longlong *)(in_RDX + 8) + 8;
      }
    }
    plVar3 = (longlong *)plVar4[2];
    if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar3 + 0x19);
      plVar4 = plVar3;
      plVar3 = (longlong *)*plVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar3 + 0x19);
        plVar4 = plVar3;
        plVar3 = (longlong *)*plVar3;
      }
    }
    else {
      plVar3 = (longlong *)plVar4[1];
      plVar5 = plVar4;
      while ((plVar4 = plVar3, *(char *)((longlong)plVar4 + 0x19) == '\0' &&
             (plVar5 == (longlong *)plVar4[2]))) {
        plVar3 = (longlong *)plVar4[1];
        plVar5 = plVar4;
      }
    }
  }
  return;
}



===== GetObjectWithFilterInner @ 18001269c =====

undefined4 *
NetSetup2::details::GetObjectWithFilterInner
          (undefined4 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,int param_5
          )

{
  undefined8 local_res10;
  undefined4 local_res18 [4];
  
  local_res18[0] = 0;
  local_res10 = 0;
  param_5 = NetSetupGetObjects(*param_2,2,param_4,0,0,0,0,0,local_res18,&local_res10);
  if (param_5 < 0) {
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&param_5,(ThrowInfo *)&_TI1J);
  }
  *param_1 = local_res18[0];
  *(undefined8 *)(param_1 + 2) = local_res10;
  return param_1;
}



===== GetProperty @ 180012734 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class NetSetup2::Property __cdecl NetSetup2::ActiveObject::GetProperty(struct
   _NETSETUPPROPKEY const & __ptr64,unsigned long)const __ptr64 */

_NETSETUPPROPKEY * __thiscall
NetSetup2::ActiveObject::GetProperty(ActiveObject *this,_NETSETUPPROPKEY *param_1,ulong param_2)

{
  _NETSETUPPROPERTY *p_Var1;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined8 *local_90;
  int *local_88;
  _NETSETUPPROPERTY **local_80;
  int local_78;
  int local_74;
  _NETSETUPPROPERTY *local_70 [3];
  int local_58;
  undefined4 uStack_54;
  _NETSETUPPROPERTY *p_Stack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  local_48 = 0x47c05923a111f1f0;
  uStack_40 = 0x17957fbbad0689a;
  local_38 = 0x14;
  local_34 = 0;
  local_2c = 0;
  local_70[0] = (_NETSETUPPROPERTY *)0x0;
  local_74 = 0;
  local_58 = *(int *)(this + 0x14);
  uStack_54 = *(undefined4 *)(this + 0x18);
  p_Stack_50 = *(_NETSETUPPROPERTY **)(this + 0x1c);
  local_80 = local_70;
  local_88 = &local_74;
  local_90 = &local_48;
  local_98 = 1;
  local_78 = NetSetupGetObjectProperties
                       (**(undefined8 **)this,*(undefined4 *)(this + 0x10),&local_58,0);
  p_Var1 = local_70[0];
  if (local_78 < 0) {
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_78,(ThrowInfo *)&_TI1J);
  }
  local_58 = local_74;
  p_Stack_50 = local_70[0];
  if (local_74 != 1) {
    local_78 = -0x7fff0001;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_78,(ThrowInfo *)&_TI1J);
  }
  Property::Property((Property *)param_1,local_70[0]);
  NetSetupFreeObjectProperties(1,p_Var1);
  return param_1;
}



===== GetRelated @ 180012854 =====

/* public: class std::vector<class PktMon::Component const * __ptr64,class std::allocator<class
   PktMon::Component const * __ptr64> > __cdecl PktMon::Component::GetRelated(void)const __ptr64 */

void __thiscall PktMon::Component::GetRelated(Component *this)

{
  Component **ppCVar1;
  vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_> *in_RDX
  ;
  Component *local_res8 [2];
  
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  local_res8[0] = *(Component **)(this + 8);
  do {
    ppCVar1 = *(Component ***)(in_RDX + 8);
    if (ppCVar1 == *(Component ***)(in_RDX + 0x10)) {
      std::
      vector<PktMon::Component_const*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>::
      _Emplace_reallocate<PktMon::Component_const*___ptr64_const&___ptr64>
                (in_RDX,ppCVar1,local_res8);
    }
    else {
      *ppCVar1 = local_res8[0];
      *(longlong *)(in_RDX + 8) = *(longlong *)(in_RDX + 8) + 8;
    }
    local_res8[0] = *(Component **)(local_res8[0] + 0x10);
  } while (local_res8[0] != *(Component **)(this + 8));
  return;
}



===== GetVMSwitches @ 1800128d8 =====

/* public: class std::vector<class PktMon::VMSwitch const * __ptr64,class std::allocator<class
   PktMon::VMSwitch const * __ptr64> > __cdecl PktMon::CompList::GetVMSwitches(void)const __ptr64 */

void __thiscall PktMon::CompList::GetVMSwitches(CompList *this)

{
  char cVar1;
  Component **ppCVar2;
  longlong *plVar3;
  vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_> *in_RDX;
  longlong *plVar4;
  longlong *plVar5;
  Component *local_res8 [2];
  
  *(undefined8 *)in_RDX = 0;
  *(undefined8 *)(in_RDX + 8) = 0;
  *(undefined8 *)(in_RDX + 0x10) = 0;
  local_res8[0] = *(Component **)(this + 0x48);
  if (local_res8[0] != (Component *)0x0) {
    if ((Component *)0x1fffffffffffffff < local_res8[0]) {
                    /* WARNING: Subroutine does not return */
      std::
      vector<_PKTMON_PROPERTY_OUT_const*___ptr64,std::allocator<_PKTMON_PROPERTY_OUT_const*___ptr64>_>
      ::_Xlength();
    }
    std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
    _Reallocate<0>(in_RDX,(__uint64 *)local_res8);
  }
  plVar4 = (longlong *)**(undefined8 **)(this + 0x40);
  while (*(char *)((longlong)plVar4 + 0x19) == '\0') {
    local_res8[0] = (Component *)(plVar4 + 5);
    ppCVar2 = *(Component ***)(in_RDX + 8);
    if (ppCVar2 == *(Component ***)(in_RDX + 0x10)) {
      std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
      _Emplace_reallocate<PktMon::Component*___ptr64>(in_RDX,ppCVar2,local_res8);
    }
    else {
      *ppCVar2 = local_res8[0];
      *(longlong *)(in_RDX + 8) = *(longlong *)(in_RDX + 8) + 8;
    }
    plVar3 = (longlong *)plVar4[2];
    if (*(char *)((longlong)plVar3 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar3 + 0x19);
      plVar4 = plVar3;
      plVar3 = (longlong *)*plVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar3 + 0x19);
        plVar4 = plVar3;
        plVar3 = (longlong *)*plVar3;
      }
    }
    else {
      plVar3 = (longlong *)plVar4[1];
      plVar5 = plVar4;
      while ((plVar4 = plVar3, *(char *)((longlong)plVar4 + 0x19) == '\0' &&
             (plVar5 == (longlong *)plVar4[2]))) {
        plVar3 = (longlong *)plVar4[1];
        plVar5 = plVar4;
      }
    }
  }
  return;
}



===== InsertRelatedProtocol @ 1800129cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PktMon::InsertRelatedProtocol
               (Component *param_1,
               vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>
               *param_2)

{
  undefined8 *puVar1;
  Component *this;
  Component **ppCVar2;
  bool bVar3;
  bool bVar4;
  short ****ppppsVar5;
  longlong lVar6;
  undefined4 uVar7;
  __uint64 _Var8;
  undefined8 ****ppppuVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  undefined8 ****local_80;
  undefined8 uStack_78;
  longlong local_70;
  ulonglong local_68;
  short ****local_60;
  undefined8 uStack_58;
  longlong local_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar7 = 0;
  local_88 = (Component *)((ulonglong)local_88 & 0xffffffff00000000);
  puVar11 = *(undefined8 **)param_2;
  puVar1 = *(undefined8 **)(param_2 + 8);
  do {
    bVar3 = false;
    if (puVar11 == puVar1) {
      ppCVar2 = *(Component ***)(param_2 + 8);
      if (ppCVar2 == *(Component ***)(param_2 + 0x10)) {
        local_88 = param_1;
        std::vector<PktMon::Component*___ptr64,std::allocator<PktMon::Component*___ptr64>_>::
        _Emplace_reallocate<PktMon::Component*___ptr64>(param_2,ppCVar2,(Component **)&local_88);
      }
      else {
        *ppCVar2 = param_1;
        *(longlong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + 8;
      }
      return;
    }
    this = (Component *)*puVar11;
    local_60 = (short ****)0x0;
    uStack_58 = 0;
    local_50 = 0;
    local_48 = 0;
    _Var8 = 0xffffffffffffffff;
    do {
      _Var8 = _Var8 + 1;
    } while ((*(ushort **)param_1)[_Var8] != 0);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    _Construct<1,unsigned_short_const*___ptr64>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_60,*(ushort **)param_1,_Var8);
    local_88 = (Component *)(CONCAT44(local_88._4_4_,uVar7) | 5);
    local_80 = (undefined8 ****)0x0;
    uStack_78 = 0;
    local_70 = 0;
    local_68 = 0;
    _Var8 = 0xffffffffffffffff;
    do {
      _Var8 = _Var8 + 1;
    } while ((*(ushort **)this)[_Var8] != 0);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    _Construct<1,unsigned_short_const*___ptr64>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_80,*(ushort **)this,_Var8);
    local_88 = (Component *)CONCAT44(local_88._4_4_,0xf);
    ppppsVar5 = (short ****)&local_60;
    if (7 < local_48) {
      ppppsVar5 = local_60;
    }
    ppppuVar9 = &local_80;
    if (7 < local_68) {
      ppppuVar9 = local_80;
    }
    if (local_70 == local_50) {
      if (local_70 != 0) {
        lVar10 = (longlong)ppppuVar9 - (longlong)ppppsVar5;
        lVar6 = local_70;
        do {
          if (*(short *)(lVar10 + (longlong)ppppsVar5) != *(short *)ppppsVar5) goto LAB_180012ad0;
          ppppsVar5 = (short ****)((longlong)ppppsVar5 + 2);
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
      }
      bVar3 = Component::IsIPv6(param_1);
      bVar4 = Component::IsIPv6(this);
      if (bVar4 == bVar3) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
    }
LAB_180012ad0:
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_80);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_60);
    uVar7 = 0xc;
    if (bVar3) {
      Component::MakeRelated(this,param_1);
      return;
    }
    puVar11 = puVar11 + 1;
  } while( true );
}



===== IsHidden @ 180012b70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual bool __cdecl PktMon::NicGroup::IsHidden(void)const __ptr64 */

bool __thiscall PktMon::NicGroup::IsHidden(NicGroup *this)

{
  bool bVar1;
  _PKTMON_PROPERTY_OUT *p_Var2;
  ulong in_R8D;
  undefined4 in_register_00000084;
  undefined1 auStackY_b8 [32];
  _NETSETUPPROP_FILTER_EXPRESSION *in_stack_ffffffffffffff68;
  undefined2 local_88;
  int local_84;
  undefined8 local_80;
  NicGroup *local_78;
  TransactionBase local_70 [8];
  vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_> *local_68;
  _NETSETUPPROPKEY local_48 [48];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = this;
  if (this[0x69] == (NicGroup)0x0) {
    *(undefined2 *)(this + 0x68) = 0x100;
    if (*(Component **)(this + 0x18) != (Component *)0x0) {
      p_Var2 = Component::FindProperty(*(Component **)(this + 0x18),4);
      if (p_Var2 != (_PKTMON_PROPERTY_OUT *)0x0) {
        local_80 = 0;
        local_84 = NetSetupInitialize(0,&local_80);
        if (local_84 < 0) {
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_84,(ThrowInfo *)&_TI1J);
        }
        NetSetup2::details::GetObjectWithFilter<NetSetup2::NetworkInterface>
                  (local_70,(_NETSETUP_OBJECT_TYPE)&local_80,
                   (_GUID *)CONCAT44(in_register_00000084,in_R8D),(int)p_Var2 + 6,
                   in_stack_ffffffffffffff68);
        NetSetup2::ActiveObject::GetProperty((ActiveObject *)local_70,local_48,in_R8D);
        bVar1 = NetSetup2::Property::GetBoolean((Property *)local_48);
        NetSetup2::Property::~Property((Property *)local_48);
        local_88 = CONCAT11(1,bVar1);
        *(undefined2 *)(this + 0x68) = local_88;
        if (local_68 != (vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_> *)0x0) {
          std::vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_>::
          ~vector<NetSetup2::Property,std::allocator<NetSetup2::Property>_>(local_68);
          operator_delete(local_68,0x18);
        }
        NetSetup2::Transaction::~Transaction((Transaction *)&local_80);
      }
    }
  }
  if (this[0x69] == (NicGroup)0x0) {
                    /* WARNING: Subroutine does not return */
    std::_Throw_bad_optional_access();
  }
  return (bool)this[0x68];
}



===== IsIPv6 @ 180012cc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: bool __cdecl PktMon::Component::IsIPv6(void)const __ptr64 */

bool __thiscall PktMon::Component::IsIPv6(Component *this)

{
  longlong *plVar1;
  ushort *puVar2;
  bool bVar3;
  _PKTMON_PROPERTY_OUT *p_Var4;
  longlong lVar5;
  short *psVar6;
  longlong lVar7;
  wchar_t *pwVar8;
  short *psVar9;
  __uint64 _Var10;
  undefined8 ***pppuVar11;
  bool bVar12;
  undefined1 auStack_78 [40];
  undefined8 ***local_50;
  undefined8 uStack_48;
  longlong local_40;
  ulonglong uStack_38;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  local_30 [32];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  puVar2 = *(ushort **)this;
  bVar12 = false;
  if (*(int *)(puVar2 + 0xc0) == 10) {
    p_Var4 = FindPropertyAux(this,0xd);
    if (p_Var4 != (_PKTMON_PROPERTY_OUT *)0x0) {
      bVar12 = *(short *)(p_Var4 + 4) == 0x10;
    }
  }
  else {
    local_50 = (undefined8 ***)0x0;
    uStack_48 = 0;
    _Var10 = 0xffffffffffffffff;
    local_40 = 0;
    uStack_38 = 0;
    do {
      _Var10 = _Var10 + 1;
    } while (puVar2[_Var10] != 0);
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    _Construct<1,unsigned_short_const*___ptr64>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_50,puVar2,_Var10);
    pwVar8 = L"tcpip.sys";
    lVar5 = -1;
    do {
      lVar5 = lVar5 + 1;
    } while (L"tcpip.sys"[lVar5] != L'\0');
    pppuVar11 = &local_50;
    if (7 < uStack_38) {
      pppuVar11 = local_50;
    }
    if (local_40 == lVar5) {
      bVar3 = true;
      if (local_40 != 0) {
        lVar5 = local_40;
        do {
          if (*(wchar_t *)((longlong)(pppuVar11 + -0x30003745) + (longlong)pwVar8) != *pwVar8)
          goto LAB_180012d92;
          pwVar8 = pwVar8 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
      }
    }
    else {
LAB_180012d92:
      bVar3 = false;
    }
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)&local_50);
    if (bVar3) {
      psVar6 = (short *)GetDescription(this,SUB81(local_30,0));
      plVar1 = (longlong *)(psVar6 + 8);
      if (7 < *(ulonglong *)(psVar6 + 0xc)) {
        psVar6 = *(short **)psVar6;
      }
      if (*plVar1 == 0) {
LAB_180012df1:
        lVar5 = -1;
      }
      else {
        lVar7 = *plVar1 + -1;
        lVar5 = -1;
        if (lVar7 != -1) {
          lVar5 = lVar7;
        }
        for (psVar9 = psVar6 + lVar5; *psVar9 != 0x36; psVar9 = psVar9 + -1) {
          if (psVar9 == psVar6) goto LAB_180012df1;
        }
        lVar5 = (longlong)psVar9 - (longlong)psVar6 >> 1;
      }
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                (local_30);
      bVar12 = lVar5 != -1;
    }
  }
  return bVar12;
}



===== MakeRelated @ 180012e30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl PktMon::Component::MakeRelated(class PktMon::Component & __ptr64) __ptr64 */

void __thiscall PktMon::Component::MakeRelated(Component *this,Component *param_1)

{
  ushort uVar1;
  ushort ****ppppuVar2;
  _PKTMON_PROPERTY_OUT *p_Var3;
  ulonglong uVar4;
  undefined8 ****ppppuVar5;
  longlong lVar6;
  uint uVar7;
  __uint64 _Var8;
  ulonglong uVar9;
  undefined1 auStack_98 [32];
  longlong *local_78;
  longlong *local_70;
  ushort ****local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  ulonglong local_48;
  undefined8 ****local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  ulonglong local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(this + 8);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(this + 0x10);
  *(Component **)(this + 0x10) = param_1;
  local_40 = (undefined8 ****)0x0;
  uStack_38 = 0;
  local_30 = 0;
  local_28 = 0;
  uVar7 = 0xffffffff;
  _Var8 = 0xffffffffffffffff;
  do {
    _Var8 = _Var8 + 1;
  } while (((ushort *)(*(longlong *)param_1 + 0x80))[_Var8] != 0);
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::_Construct<1,unsigned_short_const*___ptr64>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)&local_40,(ushort *)(*(longlong *)param_1 + 0x80),_Var8);
  local_60 = (ushort ****)0x0;
  uStack_58 = 0;
  local_50 = 0;
  local_48 = 0;
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::_Construct<1,unsigned_short_const*___ptr64>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)&local_60,(ushort *)L"TCPIP",5);
  ppppuVar2 = (ushort ****)&local_60;
  if (7 < local_48) {
    ppppuVar2 = local_60;
  }
  uVar9 = local_30;
  if (local_50 <= local_30) {
    uVar9 = local_50;
  }
  ppppuVar5 = &local_40;
  if (7 < local_28) {
    ppppuVar5 = local_40;
  }
  uVar4 = uVar9;
  if (local_50 < uVar9) {
    uVar4 = local_50;
  }
  if (uVar4 != 0) {
    lVar6 = (longlong)ppppuVar5 - (longlong)ppppuVar2;
    do {
      uVar1 = *(ushort *)(lVar6 + (longlong)ppppuVar2);
      if (uVar1 != *(ushort *)ppppuVar2) {
        uVar7 = (-(uint)(uVar1 < *(ushort *)ppppuVar2) & 0xfffffffe) + 1;
        goto LAB_180012f28;
      }
      ppppuVar2 = (ushort ****)((longlong)ppppuVar2 + 2);
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (local_50 <= uVar9) {
    uVar7 = (uint)(local_50 < uVar9);
  }
LAB_180012f28:
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)&local_60);
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)&local_40);
  if (uVar7 != 0) {
    p_Var3 = FindPropertyAux(this,9);
    if (p_Var3 == (_PKTMON_PROPERTY_OUT *)0x0) {
      return;
    }
    if (p_Var3 == (_PKTMON_PROPERTY_OUT *)0xfffffffffffffffa) {
      return;
    }
  }
  GetRelated(this);
  for (; local_78 != local_70; local_78 = local_78 + 1) {
    *(Component **)(*local_78 + 8) = param_1;
  }
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)&local_78);
  return;
}



===== NormalizeAndValidateSelection @ 180012fbc =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: class std::set<long,struct std::less<long>,class std::allocator<long> > __cdecl
   PktMon::CompList::NormalizeAndValidateSelection(class std::vector<long,class std::allocator<long>
   > const & __ptr64) __ptr64 */

vector<long,std::allocator<long>_> * __thiscall
PktMon::CompList::NormalizeAndValidateSelection
          (CompList *this,vector<long,std::allocator<long>_> *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  Component *this_00;
  undefined8 uVar4;
  longlong *plVar5;
  vector<long,std::allocator<long>_> *pvVar6;
  longlong *plVar7;
  long *plVar8;
  void *pvVar9;
  long *plVar10;
  _Tree_node<long,void*___ptr64> *p_Var11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  _Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<long>_>_> *this_01;
  undefined8 *puVar14;
  undefined8 *puVar15;
  long *plVar16;
  long *plVar17;
  undefined4 *puVar18;
  long *plVar19;
  undefined8 *in_R8;
  undefined8 *puVar20;
  bool bVar21;
  undefined8 *local_res20;
  long *local_108;
  longlong local_100;
  undefined8 *local_f8;
  undefined8 *puStack_f0;
  undefined8 *local_d8;
  long **local_d0;
  undefined8 local_c8;
  vector<long,std::allocator<long>_> *local_b8;
  undefined8 uStack_b0;
  undefined8 *local_a8;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined8 local_98;
  undefined8 *local_88;
  undefined8 *local_80;
  undefined8 *local_78;
  undefined8 *local_68;
  undefined8 *local_60;
  
  puVar3 = (undefined4 *)in_R8[1];
  puVar18 = (undefined4 *)*in_R8;
  local_108 = (long *)0x0;
  local_100 = 0;
  plVar8 = operator_new(0x20);
  *(long **)plVar8 = plVar8;
  *(long **)(plVar8 + 2) = plVar8;
  *(long **)(plVar8 + 4) = plVar8;
  *(undefined2 *)(plVar8 + 6) = 0x101;
  local_108 = plVar8;
  for (; puVar18 != puVar3; puVar18 = puVar18 + 1) {
    puVar13 = (undefined8 *)
              std::_Tree<std::_Tset_traits<long,std::less<long>,std::allocator<long>,0>_>::
              _Find_hint<long>((_Tree<std::_Tset_traits<long,std::less<long>,std::allocator<long>,0>_>
                                *)&local_108,(_Tree_node<long,void*___ptr64> *)&local_80,plVar8);
    plVar10 = local_108;
    pvVar6 = (vector<long,std::allocator<long>_> *)*puVar13;
    uVar4 = puVar13[1];
    local_98 = puVar13[2];
    if ((char)local_98 == '\0') {
      if (local_100 == 0x7ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
        std::_Throw_tree_length_error();
      }
      local_d0 = &local_108;
      local_c8 = 0;
      puVar13 = operator_new(0x20);
      *(undefined4 *)((longlong)puVar13 + 0x1c) = *puVar18;
      *puVar13 = plVar10;
      puVar13[1] = plVar10;
      puVar13[2] = plVar10;
      *(undefined2 *)(puVar13 + 3) = 0;
      local_c8 = 0;
      local_b8 = pvVar6;
      uStack_b0 = uVar4;
      std::
      _Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
      ::_Insert_node((_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
                      *)&local_108,&local_b8);
    }
  }
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  pvVar9 = operator_new(0x20);
  *(void **)pvVar9 = pvVar9;
  *(void **)((longlong)pvVar9 + 8) = pvVar9;
  *(void **)((longlong)pvVar9 + 0x10) = pvVar9;
  *(undefined2 *)((longlong)pvVar9 + 0x18) = 0x101;
  *(void **)param_1 = pvVar9;
  GetGroups(this);
  local_d0 = (long **)local_78;
  bVar21 = local_80 == local_78;
  do {
    local_d8 = local_80;
    if (bVar21) {
      std::
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)&local_80);
      if (local_100 != 0) {
        this_01 = (_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<long>_>_> *)
                  std::begin<std::set<long,std::less<long>,std::allocator<long>_>_>
                            ((set<long,std::less<long>,std::allocator<long>_> *)&local_res20);
        plVar8 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<long>_>_>::
                 operator*(this_01);
        InvalidComponentId::InvalidComponentId((InvalidComponentId *)&local_a8,*plVar8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_a8,(ThrowInfo *)&_TI3_AVInvalidComponentId_PktMon__);
      }
      local_100 = 0;
      cVar1 = *(char *)((longlong)*(longlong **)(local_108 + 2) + 0x19);
      plVar7 = *(longlong **)(local_108 + 2);
      while (cVar1 == '\0') {
        std::_Tree_val<std::_Tree_simple_types<long>_>::
        _Erase_tree<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
                  ((_Tree_val<std::_Tree_simple_types<long>_> *)&local_108,
                   (allocator<std::_Tree_node<long,void*___ptr64>_> *)&local_108,
                   (_Tree_node<long,void*___ptr64> *)plVar7[2]);
        plVar5 = (longlong *)*plVar7;
        operator_delete(plVar7,0x20);
        plVar7 = plVar5;
        cVar1 = *(char *)((longlong)plVar5 + 0x19);
      }
LAB_1800134b1:
      operator_delete(local_108,0x20);
      return param_1;
    }
    (**(code **)(*(longlong *)*local_80 + 0x18))((longlong *)*local_80,&local_68);
    local_88 = local_60;
    puVar14 = local_60;
    for (puVar13 = local_68; local_res20 = puVar13, puVar13 != puVar14; puVar13 = puVar13 + 1) {
      this_00 = (Component *)*puVar13;
      bVar21 = false;
      Component::GetRelated(this_00);
      for (puVar15 = local_f8; puVar15 != puStack_f0; puVar15 = puVar15 + 1) {
        uStack_9c = 0;
        plVar8 = *(long **)(local_108 + 2);
        plVar10 = local_108;
        while (plVar16 = plVar8, *(char *)((longlong)plVar16 + 0x19) == '\0') {
          if (plVar16[7] < *(int *)(*(longlong *)*puVar15 + 0x184)) {
            plVar8 = *(long **)(plVar16 + 4);
          }
          else {
            plVar8 = *(long **)plVar16;
            plVar10 = plVar16;
          }
        }
        if ((*(char *)((longlong)plVar10 + 0x19) != '\0') ||
           (*(int *)(*(longlong *)*puVar15 + 0x184) < plVar10[7])) {
          plVar10 = local_108;
        }
        if (plVar10 != local_108) {
          bVar21 = true;
          break;
        }
      }
      std::
      vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
      ::
      ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  *)&local_f8);
      if (bVar21) {
        Component::GetRelated(this_00);
        puVar15 = (undefined8 *)CONCAT44(uStack_9c,local_a0);
        puVar20 = local_a8;
        if (local_a8 != puVar15) {
LAB_1800131ea:
          plVar8 = local_108;
          iVar2 = *(int *)(*(longlong *)*puVar20 + 0x184);
          plVar10 = *(long **)(local_108 + 2);
          plVar16 = local_108;
          plVar19 = local_108;
          while (plVar17 = plVar10, *(char *)((longlong)plVar17 + 0x19) == '\0') {
            if (plVar17[7] < iVar2) {
              plVar10 = *(long **)(plVar17 + 4);
            }
            else {
              if ((*(char *)((longlong)plVar19 + 0x19) != '\0') && (iVar2 < plVar17[7])) {
                plVar19 = plVar17;
              }
              plVar10 = *(long **)plVar17;
              plVar16 = plVar17;
            }
          }
          plVar10 = local_108 + 2;
          if (*(char *)((longlong)plVar19 + 0x19) == '\0') {
            plVar10 = plVar19;
          }
          do {
            plVar10 = *(long **)plVar10;
LAB_18001324f:
            if (*(char *)((longlong)plVar10 + 0x19) != '\0') goto code_r0x000180013255;
            if (plVar10[7] <= iVar2) goto LAB_18001324b;
            plVar19 = plVar10;
          } while( true );
        }
LAB_1800133cf:
        std::
        vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
        ::
        ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                  ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                    *)&local_a8);
        if (local_100 == 0) {
          std::
          vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
          ::
          ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                    ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                      *)&local_68);
          std::
          vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
          ::
          ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                    ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                      *)&local_80);
          cVar1 = *(char *)((longlong)*(longlong **)(local_108 + 2) + 0x19);
          plVar7 = *(longlong **)(local_108 + 2);
          while (cVar1 == '\0') {
            std::_Tree_val<std::_Tree_simple_types<long>_>::
            _Erase_tree<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
                      ((_Tree_val<std::_Tree_simple_types<long>_> *)&local_108,
                       (allocator<std::_Tree_node<long,void*___ptr64>_> *)&local_108,
                       (_Tree_node<long,void*___ptr64> *)plVar7[2]);
            plVar5 = (longlong *)*plVar7;
            operator_delete(plVar7,0x20);
            plVar7 = plVar5;
            cVar1 = *(char *)((longlong)plVar5 + 0x19);
          }
          goto LAB_1800134b1;
        }
      }
    }
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)&local_68);
    local_80 = local_d8 + 1;
    bVar21 = (long **)local_80 == local_d0;
  } while( true );
code_r0x000180013255:
  if ((plVar16 == *(long **)local_108) && (*(char *)((longlong)plVar19 + 0x19) != '\0')) {
    puVar13 = *(undefined8 **)(local_108 + 2);
    while (*(char *)((longlong)puVar13 + 0x19) == '\0') {
      std::_Tree_val<std::_Tree_simple_types<long>_>::
      _Erase_tree<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
                ((_Tree_val<std::_Tree_simple_types<long>_> *)&local_108,
                 (allocator<std::_Tree_node<long,void*___ptr64>_> *)&local_108,
                 (_Tree_node<long,void*___ptr64> *)puVar13[2]);
      puVar14 = (undefined8 *)*puVar13;
      operator_delete(puVar13,0x20);
      puVar13 = puVar14;
    }
    *(long **)(plVar8 + 2) = plVar8;
    *(long **)plVar8 = plVar8;
    *(long **)(plVar8 + 4) = plVar8;
    local_100 = 0;
  }
  else {
    while (plVar16 != plVar19) {
      plVar8 = *(long **)(plVar16 + 4);
      if (*(char *)((longlong)plVar8 + 0x19) == '\0') {
        cVar1 = *(char *)((longlong)*(long **)plVar8 + 0x19);
        plVar10 = *(long **)plVar8;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((longlong)*(long **)plVar10 + 0x19);
          plVar8 = plVar10;
          plVar10 = *(long **)plVar10;
        }
      }
      else {
        plVar10 = *(long **)(plVar16 + 2);
        plVar17 = plVar16;
        while ((plVar8 = plVar10, *(char *)((longlong)plVar8 + 0x19) == '\0' &&
               (plVar17 == *(long **)(plVar8 + 4)))) {
          plVar10 = *(long **)(plVar8 + 2);
          plVar17 = plVar8;
        }
      }
      p_Var11 = std::_Tree_val<std::_Tree_simple_types<long>_>::_Extract
                          ((_Tree_val<std::_Tree_simple_types<long>_> *)&local_108,plVar16);
      operator_delete(p_Var11,0x20);
      plVar16 = plVar8;
    }
  }
  puVar13 = (undefined8 *)(*(undefined8 **)param_1)[1];
  puStack_f0 = (undefined8 *)0x0;
  puVar14 = *(undefined8 **)param_1;
  local_f8 = puVar13;
  while (puVar12 = puVar13, *(char *)((longlong)puVar12 + 0x19) == '\0') {
    local_f8 = puVar12;
    if (*(int *)((longlong)puVar12 + 0x1c) < iVar2) {
      puStack_f0 = (undefined8 *)0x0;
      puVar13 = (undefined8 *)puVar12[2];
    }
    else {
      puStack_f0 = (undefined8 *)0x1;
      puVar13 = (undefined8 *)*puVar12;
      puVar14 = puVar12;
    }
  }
  if ((*(char *)((longlong)puVar14 + 0x19) != '\0') || (iVar2 < *(int *)((longlong)puVar14 + 0x1c)))
  {
    if (*(longlong *)(param_1 + 8) == 0x7ffffffffffffff) {
                    /* WARNING: Subroutine does not return */
      std::_Throw_tree_length_error();
    }
    uVar4 = *(undefined8 *)param_1;
    uStack_b0 = 0;
    local_b8 = param_1;
    puVar13 = operator_new(0x20);
    *(int *)((longlong)puVar13 + 0x1c) = iVar2;
    *puVar13 = uVar4;
    puVar13[1] = uVar4;
    puVar13[2] = uVar4;
    *(undefined2 *)(puVar13 + 3) = 0;
    uStack_b0 = 0;
    std::
    _Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
    ::_Insert_node((_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
                    *)param_1,&local_f8);
  }
  puVar20 = puVar20 + 1;
  if (puVar20 == puVar15) {
    puVar13 = local_res20;
    puVar14 = local_88;
    goto LAB_1800133cf;
  }
  goto LAB_1800131ea;
LAB_18001324b:
  plVar10 = *(long **)(plVar10 + 4);
  goto LAB_18001324f;
}



===== NtStatusToHr @ 180013524 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* long __cdecl wil::details::NtStatusToHr(long) */

long __cdecl wil::details::NtStatusToHr(long param_1)

{
  ulong uVar1;
  uint uVar2;
  
  if (param_1 < 0) {
    if (param_1 == -0x3fffffe9) {
      uVar2 = 0x8007000e;
    }
    else {
      if (((g_pfnRtlNtStatusToDosErrorNoTeb != (_func_ulong_long *)0x0) &&
          (uVar1 = (*g_pfnRtlNtStatusToDosErrorNoTeb)(param_1), uVar1 != 0)) && (uVar1 != 0x13d)) {
        if ((int)uVar1 < 1) {
          return uVar1;
        }
        return uVar1 & 0xffff | 0x80070000;
      }
      uVar2 = param_1 | 0x10000000;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== OnSignaled @ 180013580 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details_abi::SubscriptionList::OnSignaled(class wil::srwlock & __ptr64)
   __ptr64 */

void __thiscall
wil::details_abi::SubscriptionList::OnSignaled(SubscriptionList *this,srwlock *param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  code *pcVar6;
  undefined8 uVar7;
  
  AcquireSRWLockShared((PSRWLOCK)param_1);
  uVar5 = (ulonglong)(*(longlong *)(this + 0x30) - *(longlong *)(this + 0x28)) >> 4;
  if (param_1 != (srwlock *)0x0) {
    ReleaseSRWLockShared((PSRWLOCK)param_1);
  }
  uVar3 = 0;
  if (uVar5 != 0) {
    do {
      pcVar6 = (code *)0x0;
      uVar7 = 0;
      EnterCriticalSection((LPCRITICAL_SECTION)this);
      AcquireSRWLockExclusive((PSRWLOCK)param_1);
      if (uVar3 < uVar5) {
        plVar2 = (longlong *)(uVar3 * 0x10 + *(longlong *)(this + 0x28));
        uVar4 = uVar3;
        do {
          uVar3 = uVar4 + 1;
          if (*plVar2 != 0) {
            puVar1 = (undefined8 *)(*(longlong *)(this + 0x28) + uVar4 * 0x10);
            pcVar6 = (code *)*puVar1;
            uVar7 = puVar1[1];
            break;
          }
          plVar2 = plVar2 + 2;
          uVar4 = uVar3;
        } while (uVar3 < uVar5);
      }
      if (param_1 != (srwlock *)0x0) {
        ReleaseSRWLockExclusive((PSRWLOCK)param_1);
      }
      if (pcVar6 != (code *)0x0) {
        (*pcVar6)(uVar7);
      }
      if (this != (SubscriptionList *)0x0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)this);
      }
    } while (uVar3 < uVar5);
  }
  return;
}



===== QueueBackgroundSRUMUsageReporting @ 1800136a4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl
   wil::details::FeatureStateManager::QueueBackgroundSRUMUsageReporting(unsigned int,unsigned
   short,unsigned int) __ptr64 */

void __thiscall
wil::details::FeatureStateManager::QueueBackgroundSRUMUsageReporting
          (FeatureStateManager *this,uint param_1,ushort param_2,uint param_3)

{
  FeatureStateManager *SRWLock;
  unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
  *this_00;
  uchar uVar1;
  DWORD dwErrCode;
  PTP_TIMER p_Var2;
  _FILETIME local_res8;
  uint local_28;
  ushort local_24;
  undefined2 local_22;
  uint local_20;
  
  if ((*this != (FeatureStateManager)0x0) && (!g_processShutdownInProgress)) {
    if ((g_pfnDllShutdownInProgress != (_func_uchar *)0x0) &&
       (uVar1 = (*g_pfnDllShutdownInProgress)(), uVar1 != '\0')) {
      return;
    }
    SRWLock = this + 0x28;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    local_22 = 0;
    local_28 = param_1;
    local_24 = param_2;
    local_20 = param_3;
    details_abi::heap_buffer::push_back((heap_buffer *)(this + 0xe8),&local_28,0xc);
    this_00 = (unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
               *)(this + 0x38);
    if (this[0x40] == (FeatureStateManager)0x0) {
      if (*(longlong *)this_00 == 0) {
        dwErrCode = GetLastError();
        p_Var2 = CreateThreadpoolTimer
                           (<lambda_5035b992506f4af81a770c5842624510>::<lambda_invoker_cdecl>,this,
                            (PTP_CALLBACK_ENVIRON)0x0);
        unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
        ::reset(this_00,p_Var2);
        SetLastError(dwErrCode);
      }
      if (*(PTP_TIMER *)this_00 != (PTP_TIMER)0x0) {
        local_res8.dwLowDateTime = 0xfd050f80;
        local_res8.dwHighDateTime = 0xffffffff;
        SetThreadpoolTimer(*(PTP_TIMER *)this_00,&local_res8,0,0x4e2);
        this[0x40] = (FeatureStateManager)0x1;
      }
    }
    if (SRWLock != (FeatureStateManager *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    }
  }
  return;
}



===== Read @ 1800137ec =====

/* public: bool __cdecl wil::details_abi::UsageIndexProperty::Read(unsigned char * __ptr64 &
   __ptr64,unsigned char * __ptr64) __ptr64 */

bool __thiscall
wil::details_abi::UsageIndexProperty::Read(UsageIndexProperty *this,uchar **param_1,uchar *param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  UsageIndexProperty *pUVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  puVar5 = (ushort *)*param_1;
  if (this[2] == (UsageIndexProperty)0x1) {
    puVar4 = puVar5 + 1;
    if (param_2 < puVar4) {
      return false;
    }
    *(ushort **)(this + 0x10) = puVar5;
    if (puVar5 == (ushort *)0x0) {
      puVar2 = (undefined4 *)_o__errno();
      *puVar2 = 0x16;
      _o__invalid_parameter_noinfo();
      uVar1 = 0;
    }
    else {
      uVar1 = *puVar5;
    }
    *(uint *)(this + 4) = (uint)uVar1;
LAB_180013896:
    puVar5 = puVar4;
  }
  else if (this[2] == (UsageIndexProperty)0x2) {
    puVar4 = puVar5 + 2;
    if (param_2 < puVar4) {
      return false;
    }
    *(ushort **)(this + 0x10) = puVar5;
    pUVar3 = this + 4;
    if (pUVar3 != (UsageIndexProperty *)0x0) {
      if (puVar5 != (ushort *)0x0) {
        *(undefined4 *)pUVar3 = *(undefined4 *)puVar5;
        goto LAB_180013896;
      }
      *(undefined4 *)pUVar3 = 0;
    }
    puVar2 = (undefined4 *)_o__errno();
    *puVar2 = 0x16;
    _o__invalid_parameter_noinfo();
    goto LAB_180013896;
  }
  pUVar3 = this + 8;
  *(ushort *)pUVar3 = *(ushort *)this;
  puVar4 = puVar5;
  if (*(ushort *)this == 0) {
    puVar4 = puVar5 + 1;
    if (param_2 < puVar4) {
      return false;
    }
    if (pUVar3 != (UsageIndexProperty *)0x0) {
      if (puVar5 != (ushort *)0x0) {
        *(ushort *)pUVar3 = *puVar5;
        goto LAB_1800138e0;
      }
      *(ushort *)pUVar3 = 0;
    }
    puVar2 = (undefined4 *)_o__errno();
    *puVar2 = 0x16;
    _o__invalid_parameter_noinfo();
  }
LAB_1800138e0:
  if (param_2 < (uchar *)((ulonglong)*(ushort *)pUVar3 + (longlong)puVar4)) {
    return false;
  }
  *(ushort **)(this + 0x18) = puVar4;
  *param_1 = (uchar *)((ulonglong)*(ushort *)pUVar3 + (longlong)puVar4);
  return true;
}



===== Record @ 180013918 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl wil::details_abi::UsageIndexes::Record(void) __ptr64 */

void __thiscall wil::details_abi::UsageIndexes::Record(UsageIndexes *this)

{
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  if (this[0x38] != (UsageIndexes)0x0) {
    local_48 = 0x418a073aa3bc1c75;
    local_40 = 0x418a073aa3bc2475;
    local_38 = 0x418a073aa3bc2c75;
    RecordWnfUsageIndex((__WIL__WNF_STATE_NAME *)&local_48,3,(RawUsageIndex *)this);
  }
  if (this[0x78] != (UsageIndexes)0x0) {
    local_48 = 0x418a073aa3bc3475;
    local_40 = 0x418a073aa3bc3c75;
    local_38 = 0x418a073aa3bc4475;
    RecordWnfUsageIndex((__WIL__WNF_STATE_NAME *)&local_48,3,(RawUsageIndex *)(this + 0x40));
  }
  if (this[0xb8] != (UsageIndexes)0x0) {
    local_48 = 0x418a073aa3bc4c75;
    local_40 = 0x418a073aa3bc5475;
    local_38 = 0x418a073aa3bc5c75;
    local_30 = 0x418a073aa3bc6475;
    local_28 = 0x418a073aa3bc6c75;
    local_20 = 0x418a073aa3bc7475;
    RecordWnfUsageIndex((__WIL__WNF_STATE_NAME *)&local_48,6,(RawUsageIndex *)(this + 0x80));
  }
  return;
}



===== RecordFeatureUsage @ 180013a28 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details::FeatureStateManager::RecordFeatureUsage(unsigned int,enum
   wil_details_ServiceReportingKind,unsigned __int64) __ptr64 */

void __thiscall
wil::details::FeatureStateManager::RecordFeatureUsage
          (FeatureStateManager *this,uint param_1,wil_details_ServiceReportingKind param_2,
          __uint64 param_3)

{
  FeatureStateManager *SRWLock;
  FeatureStateData *this_00;
  bool bVar1;
  FeatureStateData FVar2;
  uchar uVar3;
  uint uVar4;
  
  if (*this == (FeatureStateManager)0x0) {
    return;
  }
  uVar4 = (uint)param_3;
  bVar1 = EnsureStateData(this);
  if (!bVar1) {
    return;
  }
  this_00 = *(FeatureStateData **)(this + 0x18);
  if (param_2 == 0xfe) {
    details_abi::FeatureStateData::RecordUsage(this_00);
  }
  else {
    if (199 < param_2) {
      if ((int)param_2 < 0x100) {
        return;
      }
      if (0x1ff < param_2) {
        return;
      }
    }
    AcquireSRWLockExclusive((PSRWLOCK)this_00);
    if (((param_2 < 8) && ((0xccU >> (param_2 & 0x1f) & 1) != 0)) || (param_2 - 0x100 < 0x80)) {
      details_abi::UsageIndex<wil_details_ServiceReportingKind,unsigned_int,0>::RecordUsage
                ((UsageIndex<wil_details_ServiceReportingKind,unsigned_int,0> *)(this_00 + 8),
                 param_2,param_1,uVar4);
      FVar2 = this_00[0x40];
    }
    else {
      FVar2 = (FeatureStateData)
              details_abi::UsageIndex<wil_details_ServiceReportingKind,unsigned_int,2>::RecordUsage
                        ((UsageIndex<wil_details_ServiceReportingKind,unsigned_int,2> *)
                         (this_00 + 0x48),param_2,param_1,(uint)param_3);
    }
    if (this_00 != (FeatureStateData *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)this_00);
    }
    if (FVar2 == (FeatureStateData)0x0) {
      return;
    }
  }
  if ((g_processShutdownInProgress == false) &&
     ((g_pfnDllShutdownInProgress == (_func_uchar *)0x0 ||
      (uVar3 = (*g_pfnDllShutdownInProgress)(), uVar3 == '\0')))) {
    SRWLock = this + 0x20;
    AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
    EnsureTimerUnderLock(this);
    if (SRWLock != (FeatureStateManager *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
    }
  }
  return;
}



===== RecordUsage @ 180013b74 =====

/* public: bool __cdecl wil::details_abi::UsageIndex<enum wil_details_ServiceReportingKind,unsigned
   int,2>::RecordUsage(enum wil_details_ServiceReportingKind,unsigned int,unsigned int) __ptr64 */

bool __thiscall
wil::details_abi::UsageIndex<wil_details_ServiceReportingKind,unsigned_int,2>::RecordUsage
          (UsageIndex<wil_details_ServiceReportingKind,unsigned_int,2> *this,
          wil_details_ServiceReportingKind param_1,uint param_2,uint param_3)

{
  bool bVar1;
  wil_details_ServiceReportingKind local_res10 [2];
  uint local_res18 [4];
  
  local_res10[0] = param_1;
  local_res18[0] = param_2;
  bVar1 = RawUsageIndex::RecordUsage((RawUsageIndex *)this,local_res10,4,local_res18,4,param_3);
  return bVar1;
}



===== RecordUsage @ 180013bac =====

/* public: bool __cdecl wil::details_abi::UsageIndex<enum wil_details_ServiceReportingKind,unsigned
   int,0>::RecordUsage(enum wil_details_ServiceReportingKind,unsigned int,unsigned int) __ptr64 */

bool __thiscall
wil::details_abi::UsageIndex<wil_details_ServiceReportingKind,unsigned_int,0>::RecordUsage
          (UsageIndex<wil_details_ServiceReportingKind,unsigned_int,0> *this,
          wil_details_ServiceReportingKind param_1,uint param_2,uint param_3)

{
  bool bVar1;
  wil_details_ServiceReportingKind local_res10 [2];
  uint local_res18 [4];
  
  local_res10[0] = param_1;
  local_res18[0] = param_2;
  bVar1 = RawUsageIndex::RecordUsage((RawUsageIndex *)this,local_res10,4,local_res18,4,1);
  return bVar1;
}



===== RecordUsage @ 180013be4 =====

/* public: void __cdecl wil::details_abi::FeatureStateData::RecordUsage(void) __ptr64 */

void __thiscall wil::details_abi::FeatureStateData::RecordUsage(FeatureStateData *this)

{
  UsageIndexes local_c8 [64];
  RawUsageIndex local_88 [64];
  RawUsageIndex local_48 [64];
  
  UsageIndexes::UsageIndexes(local_c8);
  AcquireSRWLockExclusive((PSRWLOCK)this);
  if (this[0x40] != (FeatureStateData)0x0) {
    RawUsageIndex::Swap((RawUsageIndex *)local_c8,(RawUsageIndex *)(this + 8));
  }
  if (this[0x80] != (FeatureStateData)0x0) {
    RawUsageIndex::Swap(local_88,(RawUsageIndex *)(this + 0x48));
  }
  if (this[0xc0] != (FeatureStateData)0x0) {
    RawUsageIndex::Swap(local_48,(RawUsageIndex *)(this + 0x88));
  }
  ReleaseSRWLockExclusive((PSRWLOCK)this);
  UsageIndexes::Record(local_c8);
  UsageIndexes::~UsageIndexes(local_c8);
  return;
}



===== RecordUsage @ 180013c88 =====

/* public: bool __cdecl wil::details_abi::RawUsageIndex::RecordUsage(void * __ptr64,unsigned
   __int64,void * __ptr64,unsigned __int64,unsigned int) __ptr64 */

bool __thiscall
wil::details_abi::RawUsageIndex::RecordUsage
          (RawUsageIndex *this,void *param_1,__uint64 param_2,void *param_3,__uint64 param_4,
          uint param_5)

{
  heap_buffer *this_00;
  bool bVar1;
  HANDLE pvVar2;
  ulonglong uVar3;
  LPVOID pvVar4;
  ulonglong uVar5;
  void *local_48;
  undefined8 uStack_40;
  longlong local_38;
  LPVOID pvStack_30;
  
  bVar1 = RecordUsageInternal(this,param_1,param_2,param_3,param_4,param_5);
  if (bVar1) {
    bVar1 = true;
  }
  else {
    uVar5 = param_4 + 0x20 + param_2;
    this_00 = (heap_buffer *)(this + 0x18);
    if (*(longlong *)this_00 == 0) {
      local_48 = (void *)0x0;
      uStack_40 = 0;
      local_38 = 0;
      pvStack_30 = (LPVOID)0x0;
      bVar1 = heap_buffer::reserve((heap_buffer *)&local_48,param_4 + 0x2a + param_2);
      if (bVar1) {
        SetBuffer(this,local_48,0,local_38 - (longlong)local_48);
        pvVar4 = *(LPVOID *)(this + 0x30);
        *(LPVOID *)(this + 0x30) = pvStack_30;
        if (pvVar4 != (LPVOID)0x0) {
          pvVar2 = GetProcessHeap();
          HeapFree(pvVar2,0,pvVar4);
        }
        this[0x3a] = (RawUsageIndex)0x1;
        pvVar4 = (LPVOID)0x0;
      }
      else {
        pvVar4 = pvStack_30;
      }
      if (pvVar4 != (LPVOID)0x0) {
        pvVar2 = GetProcessHeap();
        HeapFree(pvVar2,0,pvVar4);
      }
    }
    else if ((this[0x3a] != (RawUsageIndex)0x0) &&
            ((ulonglong)(*(longlong *)(this + 0x28) - *(longlong *)this_00) <=
             (*(longlong *)(this + 0x20) - *(longlong *)this_00) + uVar5)) {
      uVar3 = (*(longlong *)(this + 0x28) - *(longlong *)this_00) * 2;
      if (uVar3 <= uVar5) {
        uVar3 = uVar5;
      }
      heap_buffer::reserve(this_00,uVar3);
    }
    bVar1 = RecordUsageInternal(this,param_1,param_2,param_3,param_4,param_5);
  }
  return bVar1;
}



===== RecordUsageInternal @ 180013e00 =====

/* WARNING: Removing unreachable block (ram,0x000180014062) */
/* private: bool __cdecl wil::details_abi::RawUsageIndex::RecordUsageInternal(void *
   __ptr64,unsigned __int64,void * __ptr64,unsigned __int64,unsigned int) __ptr64 */

bool __thiscall
wil::details_abi::RawUsageIndex::RecordUsageInternal
          (RawUsageIndex *this,void *param_1,__uint64 param_2,void *param_3,__uint64 param_4,
          uint param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  bool bVar3;
  RawUsageIndex RVar4;
  uint *puVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  uint uVar13;
  uchar *puVar14;
  uchar *puVar15;
  size_t _Size;
  uchar *local_88;
  ushort local_80;
  RawUsageIndex local_7e;
  uint local_7c;
  ushort local_78;
  uint *local_70;
  void *pvStack_68;
  ushort local_60;
  RawUsageIndex local_5e;
  uint local_5c;
  undefined2 local_58;
  undefined8 local_50;
  void *pvStack_48;
  
  if (*(longlong *)(this + 0x18) == 0) {
    return false;
  }
  local_80 = *(ushort *)(this + 2);
  puVar15 = *(uchar **)(this + 0x20);
  puVar14 = (uchar *)(*(longlong *)(this + 0x18) + 10);
  local_7e = this[4];
  local_7c = 0;
  local_78 = 0;
  local_70 = (uint *)0x0;
  pvStack_68 = (void *)0x0;
  bVar3 = false;
  while( true ) {
    bVar6 = false;
    local_88 = puVar14;
    bVar7 = UsageIndexProperty::Read((UsageIndexProperty *)&local_80,&local_88,puVar15);
    if (!bVar7) break;
    if (param_2 == local_78) {
      iVar8 = memcmp(param_1,pvStack_68,param_2);
    }
    else {
      iVar8 = (int)param_2 - (uint)local_78;
    }
    uVar9 = local_7c;
    puVar15 = local_88;
    uVar13 = 0;
    if (iVar8 < 0) {
      local_88 = puVar14;
      goto LAB_180013fd5;
    }
    if (iVar8 == 0) {
      local_88 = FindInsertionPointOrIncrement
                           (this,(UsageIndexProperty *)&local_80,local_88,param_3,param_4,param_5);
      if (local_88 == (uchar *)0x0) {
        return true;
      }
      bVar6 = true;
      bVar3 = true;
      goto LAB_180013fd5;
    }
    if (*(longlong *)(this + 0x10) == 0) {
      local_60 = *(ushort *)(this + 6);
      local_5e = this[8];
      local_5c = 0;
      local_58 = 0;
      local_50 = 0;
      pvStack_48 = (void *)0x0;
      if (local_7c != 0) {
        do {
          bVar6 = UsageIndexProperty::Read
                            ((UsageIndexProperty *)&local_60,&local_88,*(uchar **)(this + 0x20));
          if (!bVar6) break;
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar9);
      }
      puVar14 = local_88;
      if (uVar9 != uVar13) {
        local_7c = uVar13;
        if (local_7e == (RawUsageIndex)0x1) {
          if (local_70 == (uint *)0x0) {
LAB_180013f93:
            puVar11 = (undefined4 *)_o__errno();
            *puVar11 = 0x16;
            _o__invalid_parameter_noinfo();
          }
          else {
            *(short *)local_70 = (short)uVar13;
          }
        }
        else if (local_7e == (RawUsageIndex)0x2) {
          if (local_70 == (uint *)0x0) goto LAB_180013f93;
          *local_70 = uVar13;
        }
      }
    }
    else {
      uVar12 = (ulonglong)(*(longlong *)(this + 0x20) - *(longlong *)(this + 0x18)) /
               *(ulonglong *)(this + 0x10);
      uVar10 = (ulonglong)local_7c;
      if (uVar12 < uVar10) {
        uVar9 = (uint)uVar12;
        if (local_7c != uVar9) {
          uVar10 = uVar12 & 0xffffffff;
          local_7c = uVar9;
          if (local_7e == (RawUsageIndex)0x1) {
            if (local_70 == (uint *)0x0) {
LAB_180013ef1:
              puVar11 = (undefined4 *)
                        _o__errno(iVar8,(ulonglong)
                                        (*(longlong *)(this + 0x20) - *(longlong *)(this + 0x18)) %
                                        *(ulonglong *)(this + 0x10));
              *puVar11 = 0x16;
              _o__invalid_parameter_noinfo();
            }
            else {
              *(short *)local_70 = (short)uVar10;
            }
          }
          else if (local_7e == (RawUsageIndex)0x2) {
            if (local_70 == (uint *)0x0) goto LAB_180013ef1;
            *local_70 = uVar9;
          }
        }
      }
      puVar14 = puVar15 + uVar10 * *(longlong *)(this + 0x10);
    }
    puVar15 = *(uchar **)(this + 0x20);
  }
  bVar3 = false;
  bVar6 = false;
  *(uchar **)(this + 0x20) = local_88;
LAB_180013fd5:
  RVar4 = local_7e;
  uVar12 = 0;
  if (!bVar6) {
    uVar12 = (ulonglong)local_80;
    local_7c = 1;
    local_78 = (ushort)param_2;
    local_70 = (uint *)0x0;
    if (local_80 == 0) {
      uVar12 = (param_2 & 0xffff) + 2;
    }
    pvStack_68 = param_1;
    if (local_7e == (RawUsageIndex)0x1) {
      uVar12 = uVar12 + 2;
    }
    else if (local_7e == (RawUsageIndex)0x2) {
      uVar12 = uVar12 + 4;
    }
  }
  puVar5 = local_70;
  uVar9 = local_7c;
  local_60 = *(ushort *)(this + 6);
  uVar10 = (ulonglong)local_60;
  local_5e = this[8];
  local_5c = param_5;
  local_58 = (undefined2)param_4;
  local_50 = 0;
  if (local_60 == 0) {
    uVar10 = (param_4 & 0xffff) + 2;
  }
  if (local_5e == (RawUsageIndex)0x1) {
    uVar10 = uVar10 + 2;
  }
  else if (local_5e == (RawUsageIndex)0x2) {
    uVar10 = uVar10 + 4;
  }
  uVar1 = *(ulonglong *)(this + 0x28);
  uVar10 = uVar10 + uVar12;
  uVar12 = *(ulonglong *)(this + 0x20);
  if ((-(ulonglong)(uVar12 < uVar1) & uVar1 - uVar12) < uVar10) {
    return false;
  }
  _Size = uVar12 - (longlong)local_88;
  pvStack_48 = param_3;
  if (_Size != 0) {
    if ((local_88 + uVar10 == (uchar *)0x0) || (local_88 == (uchar *)0x0)) {
      puVar11 = (undefined4 *)_o__errno();
      *puVar11 = 0x16;
    }
    else {
      if (_Size <= (uVar1 - uVar10) - (longlong)local_88) {
        memmove(local_88 + uVar10,local_88,_Size);
        goto LAB_18001414f;
      }
      puVar11 = (undefined4 *)_o__errno();
      *puVar11 = 0x22;
    }
    _o__invalid_parameter_noinfo();
  }
LAB_18001414f:
  lVar2 = *(longlong *)(this + 0x20);
  *(uchar **)(this + 0x20) = (uchar *)(lVar2 + uVar10);
  if (bVar3) {
    if ((RVar4 != (RawUsageIndex)0x0) && (uVar13 = uVar9 + 1, uVar9 != uVar13)) {
      if (RVar4 == (RawUsageIndex)0x1) {
        if (puVar5 != (uint *)0x0) {
          *(short *)puVar5 = (short)uVar13;
          goto LAB_1800141b3;
        }
      }
      else {
        if (RVar4 != (RawUsageIndex)0x2) goto LAB_1800141b3;
        if (puVar5 != (uint *)0x0) {
          *puVar5 = uVar13;
          goto LAB_1800141b3;
        }
      }
      puVar11 = (undefined4 *)_o__errno();
      *puVar11 = 0x16;
      _o__invalid_parameter_noinfo();
    }
  }
  else {
    UsageIndexProperty::Write((UsageIndexProperty *)&local_80,&local_88,(uchar *)(lVar2 + uVar10));
  }
LAB_1800141b3:
  UsageIndexProperty::Write((UsageIndexProperty *)&local_60,&local_88,*(uchar **)(this + 0x20));
  this[0x38] = (RawUsageIndex)0x1;
  return true;
}



===== RecordWnfUsageIndex @ 1800141f4 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl wil::details_abi::RecordWnfUsageIndex(struct __WIL__WNF_STATE_NAME const *
   __ptr64,unsigned __int64,class wil::details_abi::RawUsageIndex const & __ptr64) */

void __cdecl
wil::details_abi::RecordWnfUsageIndex
          (__WIL__WNF_STATE_NAME *param_1,__uint64 param_2,RawUsageIndex *param_3)

{
  __WIL__WNF_STATE_NAME *p_Var1;
  uint uVar2;
  uchar *puVar3;
  char cVar4;
  bool bVar5;
  INT_PTR IVar6;
  __uint64 _Var7;
  HANDLE pvVar8;
  uint uVar9;
  RawUsageIndex *pRVar10;
  RawUsageIndex *lpMem;
  undefined8 *puVar11;
  ulonglong uVar12;
  undefined1 auStackY_11d8 [32];
  ulonglong *puVar13;
  uint local_1198 [2];
  undefined4 local_1190 [2];
  uchar *local_1188 [2];
  undefined8 local_1178;
  ulonglong uStack_1170;
  undefined8 local_1168;
  uchar *puStack_1160;
  undefined2 local_1158;
  undefined2 local_1156;
  RawUsageIndex local_1154;
  ushort local_1152;
  RawUsageIndex local_1150;
  ulonglong local_1148;
  uchar **local_1140;
  undefined8 local_1138;
  undefined8 uStack_1130;
  RawUsageIndex *local_1128;
  undefined2 local_1120;
  undefined1 local_111e;
  undefined8 local_1118;
  undefined8 local_1110;
  uchar *local_1108;
  undefined2 local_1100;
  RawUsageIndex local_10fe;
  uint local_10fc;
  ushort local_10f8;
  undefined8 local_10f0;
  undefined8 uStack_10e8;
  ulonglong local_10e0;
  undefined8 local_10d8;
  ulonglong local_10d0;
  undefined1 *local_10c8;
  undefined1 local_10c0 [8];
  undefined **local_10b8;
  undefined8 *local_10b0;
  undefined8 *puStack_10a8;
  undefined2 *local_10a0;
  undefined ***local_1050;
  ulonglong local_1048 [512];
  ulonglong local_48;
  undefined8 uStack_40;
  
  uStack_40 = 0x180014216;
  local_48 = __security_cookie ^ (ulonglong)auStackY_11d8;
  p_Var1 = param_1 + param_2 * 8;
  uVar12 = 0;
  local_1110 = 0;
  pRVar10 = param_3;
  do {
    _Var7 = 0;
    local_1150 = param_3[8];
    local_1152 = *(ushort *)(param_3 + 6);
    local_1148 = (ulonglong)local_1152;
    local_1154 = param_3[4];
    local_1156 = *(undefined2 *)(param_3 + 2);
    local_1158 = *(undefined2 *)param_3;
    if (local_1152 == 0) {
      local_1148 = 0;
    }
    else if (local_1150 == (RawUsageIndex)0x1) {
      local_1148 = local_1148 + 2;
    }
    else if (local_1150 == (RawUsageIndex)0x2) {
      local_1148 = local_1148 + 4;
    }
    local_1140 = (uchar **)0x0;
    local_1138 = 0;
    uStack_1130 = 0;
    local_1128 = (RawUsageIndex *)0x0;
    local_1120 = 0;
    local_111e = 0;
    local_1190[0] = 0;
    local_1198[0] = 0x1000;
    puVar13 = local_1048;
    IVar6 = wil_details_NtQueryWnfStateData
                      (param_1,CONCAT71((int7)(param_2 >> 8),local_1154),
                       CONCAT71((int7)((ulonglong)pRVar10 >> 8),local_1150),local_1190,puVar13,
                       local_1198);
    details::NtStatusToHr((long)IVar6);
    if ((long)IVar6 == 0) {
      _Var7 = (__uint64)local_1198[0];
    }
    else {
      local_1198[0] = 0;
      local_1190[0] = 0;
    }
    puVar11 = (undefined8 *)0x1000;
    RawUsageIndex::SetBuffer((RawUsageIndex *)&local_1158,local_1048,_Var7,0x1000);
    pRVar10 = local_1128;
    if (local_1120._1_1_ != '\0') {
      local_1128 = (RawUsageIndex *)0x0;
      if (pRVar10 != (RawUsageIndex *)0x0) {
        pvVar8 = GetProcessHeap();
        HeapFree(pvVar8,0,pRVar10);
      }
      return;
    }
    local_1118 = 0;
    local_10b0 = &local_1118;
    puStack_10a8 = &local_1110;
    local_10a0 = &local_1158;
    local_10b8 = &wistd::__function::
                  __func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
                  ::_vftable_;
    local_1050 = &local_10b8;
    local_10c8 = local_10c0;
    local_1188[0] = (uchar *)(*(longlong *)(param_3 + 0x18) + 10);
    local_1178 = CONCAT53((int5)((ulonglong)local_10b0 >> 0x18),*(undefined3 *)(param_3 + 2));
    local_1178 = local_1178 & 0xffffffff;
    uStack_1170 = (ulonglong)puStack_10a8 & 0xffffffffffff0000;
    local_1168 = 0;
    puStack_1160 = (uchar *)0x0;
    local_10fe = param_3[8];
    local_1100 = *(undefined2 *)(param_3 + 6);
    local_10fc = 0;
    local_10f8 = 0;
    local_10f0 = 0;
    uStack_10e8 = 0;
LAB_180014455:
    uVar9 = 0;
    pRVar10 = *(RawUsageIndex **)(param_3 + 0x20);
    param_2 = (__uint64)local_1188;
    bVar5 = UsageIndexProperty::Read
                      ((UsageIndexProperty *)&local_1178,(uchar **)param_2,(uchar *)pRVar10);
    puVar3 = puStack_1160;
    if (bVar5) {
      uVar2 = local_1178._4_4_;
      if (local_1178._4_4_ != 0) {
        do {
          bVar5 = UsageIndexProperty::Read
                            ((UsageIndexProperty *)&local_1100,local_1188,
                             *(uchar **)(param_3 + 0x20));
          if (!bVar5) break;
          local_1198[0] = local_10fc;
          local_10e0 = (ulonglong)local_10f8;
          local_10d8 = uStack_10e8;
          local_10d0 = uStack_1170 & 0xffff;
          local_1108 = puVar3;
          if (local_1050 == (undefined ***)0x0) {
                    /* WARNING: Subroutine does not return */
            wistd::__throw_bad_function_call();
          }
          puVar13 = &local_10e0;
          pRVar10 = (RawUsageIndex *)&local_10d0;
          param_2 = (__uint64)&local_1108;
          puVar11 = &local_10d8;
          cVar4 = (*(code *)(*local_1050)[4])(local_1050,param_2,pRVar10);
          if (cVar4 == '\0') {
            if (local_1050 != (undefined ***)0x0) {
              (*(code *)(*local_1050)[3])();
            }
            bVar5 = false;
            goto LAB_18001448a;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar2);
      }
      goto LAB_180014455;
    }
    if (local_1050 != (undefined ***)0x0) {
      (*(code *)(*local_1050)[3])();
    }
    bVar5 = true;
LAB_18001448a:
    if ((char)local_1120 == '\0') {
LAB_180014505:
      param_1 = param_1 + 8;
      local_1110 = local_1118;
    }
    else {
      pRVar10 = (RawUsageIndex *)(ulonglong)(uint)((int)local_1138 - (int)local_1140);
      param_2 = (__uint64)local_1140;
      IVar6 = wil_details_NtUpdateWnfStateData
                        (param_1,local_1140,(int)local_1138 - (int)local_1140,puVar11,puVar13,
                         local_1190[0],1);
      if ((int)IVar6 != -0x3fffffff) {
        if ((int)IVar6 != 0) {
          pRVar10 = (RawUsageIndex *)(ulonglong)(uint)((int)local_1138 - (int)local_1140);
          param_2 = (__uint64)local_1140;
          wil_details_NtUpdateWnfStateData
                    (param_1,local_1140,(int)local_1138 - (int)local_1140,puVar11,puVar13,0,0);
        }
        goto LAB_180014505;
      }
      uVar12 = uVar12 + 1;
      bVar5 = false;
    }
    lpMem = local_1128;
    local_1128 = (RawUsageIndex *)0x0;
    if (lpMem != (RawUsageIndex *)0x0) {
      pvVar8 = GetProcessHeap();
      param_2 = 0;
      HeapFree(pvVar8,0,lpMem);
      pRVar10 = lpMem;
    }
    if (bVar5) {
      return;
    }
    if (p_Var1 <= param_1) {
      return;
    }
    if (0x31 < uVar12) {
      return;
    }
  } while( true );
}



===== Release @ 1800145b8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details_abi::ProcessLocalStorageData<class
   wil::details_abi::FeatureStateData>::Release(void) __ptr64 */

void __thiscall
wil::details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Release
          (ProcessLocalStorageData<wil::details_abi::FeatureStateData> *this)

{
  uchar uVar1;
  DWORD DVar2;
  BOOL BVar3;
  HANDLE pvVar4;
  char *pcVar5;
  void *unaff_retaddr;
  UsageIndexes local_c8 [64];
  RawUsageIndex local_88 [64];
  RawUsageIndex local_48 [64];
  
  if ((details::g_processShutdownInProgress) ||
     ((details::g_pfnDllShutdownInProgress != (_func_uchar *)0x0 &&
      (uVar1 = (*details::g_pfnDllShutdownInProgress)(), uVar1 != '\0')))) {
    *(int *)this = *(int *)this + -1;
    if (*(int *)this == 0) {
      UsageIndexes::UsageIndexes(local_c8);
      if (this[0x60] != (ProcessLocalStorageData<wil::details_abi::FeatureStateData>)0x0) {
        RawUsageIndex::Swap((RawUsageIndex *)local_c8,(RawUsageIndex *)(this + 0x28));
      }
      if (this[0xa0] != (ProcessLocalStorageData<wil::details_abi::FeatureStateData>)0x0) {
        RawUsageIndex::Swap(local_88,(RawUsageIndex *)(this + 0x68));
      }
      if (this[0xe0] != (ProcessLocalStorageData<wil::details_abi::FeatureStateData>)0x0) {
        RawUsageIndex::Swap(local_48,(RawUsageIndex *)(this + 0xa8));
      }
      UsageIndexes::Record(local_c8);
      UsageIndexes::~UsageIndexes(local_c8);
    }
  }
  else {
    pvVar4 = *(HANDLE *)(this + 8);
    pcVar5 = (char *)0x0;
    DVar2 = WaitForSingleObjectEx(pvVar4,0xffffffff,0);
    if (DVar2 == 0x102) {
      pvVar4 = (HANDLE)0x0;
    }
    else if ((DVar2 & 0xffffff7f) != 0) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::FailFast_Unexpected
                (unaff_retaddr,0xc37,"onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
    }
    *(int *)this = *(int *)this + -1;
    if (*(int *)this == 0) {
      details::
      unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
      ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
               *)(this + 0x10),(void *)0x0);
      details::
      unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
      ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64)_noexcept,&void___cdecl_wil::details::CloseHandle(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
               *)(this + 0x18),(void *)0x0);
      if (pvVar4 != (HANDLE)0x0) {
        DVar2 = GetLastError();
        BVar3 = ReleaseMutex(pvVar4);
        if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,pcVar5);
        }
        SetLastError(DVar2);
      }
      FeatureStateData::~FeatureStateData((FeatureStateData *)(this + 0x20));
      SemaphoreValue::~SemaphoreValue((SemaphoreValue *)(this + 0x10));
      if ((*(HANDLE *)(this + 8) != (HANDLE)0x0) &&
         (BVar3 = CloseHandle(*(HANDLE *)(this + 8)), BVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
        details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9dd,pcVar5);
      }
      pvVar4 = GetProcessHeap();
      HeapFree(pvVar4,0,this);
    }
    else if ((pvVar4 != (HANDLE)0x0) && (BVar3 = ReleaseMutex(pvVar4), BVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
      details::in1diag3::_FailFast_GetLastError(unaff_retaddr,0x9e7,pcVar5);
    }
  }
  return;
}



===== SetBuffer @ 1800147e4 =====

/* public: void __cdecl wil::details_abi::RawUsageIndex::SetBuffer(void * __ptr64,unsigned
   __int64,unsigned __int64) __ptr64 */

void __thiscall
wil::details_abi::RawUsageIndex::SetBuffer
          (RawUsageIndex *this,void *param_1,__uint64 param_2,__uint64 param_3)

{
  LPVOID lpMem;
  code *pcVar1;
  RawUsageIndex RVar2;
  HANDLE hHeap;
  void *unaff_retaddr;
  
  if (param_3 < 10) {
    details::in1diag3::_FailFast_Unexpected(unaff_retaddr,(uint)param_1,(char *)param_2);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  lpMem = *(LPVOID *)(this + 0x30);
  *(undefined8 *)(this + 0x30) = 0;
  if (lpMem != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  *(void **)(this + 0x18) = param_1;
  *(__uint64 *)(this + 0x20) = (longlong)param_1 + param_2;
  *(__uint64 *)(this + 0x28) = (longlong)param_1 + param_3;
  this[0x39] = (RawUsageIndex)0x0;
  if (9 < param_2) {
    if ((*(short *)param_1 != 0) ||
       (RVar2 = (RawUsageIndex)0x0, *(ushort *)this < *(ushort *)((longlong)param_1 + 2))) {
      RVar2 = (RawUsageIndex)0x1;
    }
    this[0x39] = RVar2;
    if ((((*(short *)param_1 == 0) && (*(ushort *)((longlong)param_1 + 2) == *(ushort *)this)) &&
        (*(short *)((longlong)param_1 + 4) == *(short *)(this + 2))) &&
       (((*(RawUsageIndex *)((longlong)param_1 + 8) == this[4] &&
         (*(short *)((longlong)param_1 + 6) == *(short *)(this + 6))) &&
        (*(RawUsageIndex *)((longlong)param_1 + 9) == this[8])))) {
      return;
    }
  }
  *(undefined2 *)param_1 = 0;
  *(undefined2 *)((longlong)param_1 + 2) = *(undefined2 *)this;
  *(undefined2 *)((longlong)param_1 + 4) = *(undefined2 *)(this + 2);
  *(RawUsageIndex *)((longlong)param_1 + 8) = this[4];
  *(undefined2 *)((longlong)param_1 + 6) = *(undefined2 *)(this + 6);
  *(RawUsageIndex *)((longlong)param_1 + 9) = this[8];
  *(longlong *)(this + 0x20) = *(longlong *)(this + 0x18) + 10;
  return;
}



===== ShortenDescription @ 18001490c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PktMon::ShortenDescription
               (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *param_1)

{
  basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
  *pbVar1;
  map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
  *pmVar5;
  undefined8 uVar2;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar3;
  ulonglong *puVar4;
  undefined1 auStack_6e8 [48];
  ulonglong *local_6b8;
  ulonglong *local_6b0;
  ulonglong local_6a8;
  undefined8 uStack_6a0;
  undefined8 local_698;
  undefined8 uStack_690;
  ulonglong local_688;
  undefined8 uStack_680;
  undefined8 local_678;
  undefined8 uStack_670;
  ulonglong local_668;
  undefined8 uStack_660;
  undefined8 local_658;
  undefined8 uStack_650;
  ulonglong local_648;
  undefined8 uStack_640;
  undefined8 local_638;
  undefined8 uStack_630;
  ulonglong local_628;
  undefined8 uStack_620;
  undefined8 local_618;
  undefined8 uStack_610;
  ulonglong local_608;
  undefined8 uStack_600;
  undefined8 local_5f8;
  undefined8 uStack_5f0;
  ulonglong local_5e8;
  undefined8 uStack_5e0;
  undefined8 local_5d8;
  undefined8 uStack_5d0;
  ulonglong local_5c8;
  undefined8 uStack_5c0;
  undefined8 local_5b8;
  undefined8 uStack_5b0;
  ulonglong local_5a8;
  undefined8 uStack_5a0;
  undefined8 local_598;
  undefined8 uStack_590;
  ulonglong local_588;
  undefined8 uStack_580;
  undefined8 local_578;
  undefined8 uStack_570;
  ulonglong local_568;
  undefined8 uStack_560;
  undefined8 local_558;
  undefined8 uStack_550;
  ulonglong local_548;
  undefined8 uStack_540;
  undefined8 local_538;
  undefined8 uStack_530;
  ulonglong local_528;
  undefined8 uStack_520;
  undefined8 local_518;
  undefined8 uStack_510;
  ulonglong local_508;
  undefined8 uStack_500;
  undefined8 local_4f8;
  undefined8 uStack_4f0;
  ulonglong local_4e8;
  undefined8 uStack_4e0;
  undefined8 local_4d8;
  undefined8 uStack_4d0;
  ulonglong local_4c8;
  undefined8 uStack_4c0;
  undefined8 local_4b8;
  undefined8 uStack_4b0;
  ulonglong local_4a8;
  undefined8 uStack_4a0;
  undefined8 local_498;
  undefined8 uStack_490;
  ulonglong local_488;
  undefined8 uStack_480;
  undefined8 local_478;
  undefined8 uStack_470;
  ulonglong local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  ulonglong local_448;
  undefined8 uStack_440;
  undefined8 local_438;
  undefined8 uStack_430;
  ulonglong local_428;
  undefined8 uStack_420;
  undefined8 local_418;
  undefined8 uStack_410;
  ulonglong local_408;
  undefined8 uStack_400;
  undefined8 local_3f8;
  undefined8 uStack_3f0;
  ulonglong local_3e8;
  undefined8 uStack_3e0;
  undefined8 local_3d8;
  undefined8 uStack_3d0;
  ulonglong local_3c8;
  undefined8 uStack_3c0;
  undefined8 local_3b8;
  undefined8 uStack_3b0;
  ulonglong local_3a8;
  undefined8 uStack_3a0;
  undefined8 local_398;
  undefined8 uStack_390;
  ulonglong local_388;
  undefined8 uStack_380;
  undefined8 local_378;
  undefined8 uStack_370;
  ulonglong local_368;
  undefined8 uStack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  ulonglong local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined8 uStack_330;
  ulonglong local_328;
  undefined8 uStack_320;
  undefined8 local_318;
  undefined8 uStack_310;
  ulonglong local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  ulonglong local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  ulonglong local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  ulonglong local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  ulonglong local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  ulonglong local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  ulonglong local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  ulonglong local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  ulonglong local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  ulonglong local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  ulonglong local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  ulonglong local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  ulonglong local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  ulonglong local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  ulonglong local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  ulonglong local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  ulonglong local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  ulonglong local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  ulonglong local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  ulonglong local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  ulonglong local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28 [2];
  
  local_28[0] = __security_cookie ^ (ulonglong)auStack_6e8;
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4) <
      DAT_180021cf8) {
    _Init_thread_header(&DAT_180021cf8);
    if (DAT_180021cf8 == -1) {
      local_388 = 0;
      uStack_380 = 0;
      local_378 = 0;
      uStack_370 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_388,(ushort *)L"Hyper-V Virtual Ethernet Adapter",0x20);
      local_3a8 = 0;
      uStack_3a0 = 0;
      local_398 = 0;
      uStack_390 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_3a8,(ushort *)L"Host vNic",9);
      local_368 = local_388;
      uStack_360 = uStack_380;
      local_358 = local_378;
      uStack_350 = uStack_370;
      local_378 = 0;
      uStack_370 = 7;
      local_388 = local_388 & 0xffffffffffff0000;
      local_348 = local_3a8;
      uStack_340 = uStack_3a0;
      local_338 = local_398;
      uStack_330 = uStack_390;
      local_398 = 0;
      uStack_390 = 7;
      local_3a8 = local_3a8 & 0xffffffffffff0000;
      local_3c8 = 0;
      uStack_3c0 = 0;
      local_3b8 = 0;
      uStack_3b0 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_3c8,(ushort *)L"Hyper-V Virtual Switch Extension Adapter",0x28);
      local_3e8 = 0;
      uStack_3e0 = 0;
      local_3d8 = 0;
      uStack_3d0 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_3e8,(ushort *)L"VMS ExtMp",9);
      local_328 = local_3c8;
      uStack_320 = uStack_3c0;
      local_318 = local_3b8;
      uStack_310 = uStack_3b0;
      local_3b8 = 0;
      uStack_3b0 = 7;
      local_3c8 = local_3c8 & 0xffffffffffff0000;
      local_308 = local_3e8;
      uStack_300 = uStack_3e0;
      local_2f8 = local_3d8;
      uStack_2f0 = uStack_3d0;
      local_3d8 = 0;
      uStack_3d0 = 7;
      local_3e8 = local_3e8 & 0xffffffffffff0000;
      local_408 = 0;
      uStack_400 = 0;
      local_3f8 = 0;
      uStack_3f0 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_408,(ushort *)L"Hyper-V Virtual Switch Extension Filter",0x27);
      local_428 = 0;
      uStack_420 = 0;
      local_418 = 0;
      uStack_410 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_428,(ushort *)L"VMS Ext Filter",0xe);
      local_2e8 = local_408;
      uStack_2e0 = uStack_400;
      local_2d8 = local_3f8;
      uStack_2d0 = uStack_3f0;
      local_3f8 = 0;
      uStack_3f0 = 7;
      local_408 = local_408 & 0xffffffffffff0000;
      local_2c8 = local_428;
      uStack_2c0 = uStack_420;
      local_2b8 = local_418;
      uStack_2b0 = uStack_410;
      local_418 = 0;
      uStack_410 = 7;
      local_428 = local_428 & 0xffffffffffff0000;
      local_448 = 0;
      uStack_440 = 0;
      local_438 = 0;
      uStack_430 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_448,(ushort *)L"Microsoft Hyper-V Network Adapter",0x21);
      local_468 = 0;
      uStack_460 = 0;
      local_458 = 0;
      uStack_450 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_468,(ushort *)L"Microsoft NetVsc Nic",0x14);
      local_2a8 = local_448;
      uStack_2a0 = uStack_440;
      local_298 = local_438;
      uStack_290 = uStack_430;
      local_438 = 0;
      uStack_430 = 7;
      local_448 = local_448 & 0xffffffffffff0000;
      local_288 = local_468;
      uStack_280 = uStack_460;
      local_278 = local_458;
      uStack_270 = uStack_450;
      local_458 = 0;
      uStack_450 = 7;
      local_468 = local_468 & 0xffffffffffff0000;
      local_488 = 0;
      uStack_480 = 0;
      local_478 = 0;
      uStack_470 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_488,(ushort *)L"Microsoft Kernel Debug Network Adapter",0x26);
      local_4a8 = 0;
      uStack_4a0 = 0;
      local_498 = 0;
      uStack_490 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_4a8,(ushort *)L"Microsoft KD Nic",0x10);
      local_268 = local_488;
      uStack_260 = uStack_480;
      local_258 = local_478;
      uStack_250 = uStack_470;
      local_478 = 0;
      uStack_470 = 7;
      local_488 = local_488 & 0xffffffffffff0000;
      local_248 = local_4a8;
      uStack_240 = uStack_4a0;
      local_238 = local_498;
      uStack_230 = uStack_490;
      local_498 = 0;
      uStack_490 = 7;
      local_4a8 = local_4a8 & 0xffffffffffff0000;
      local_4c8 = 0;
      uStack_4c0 = 0;
      local_4b8 = 0;
      uStack_4b0 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_4c8,(ushort *)L"Netmon Lightweight Filter Driver",0x20);
      local_4e8 = 0;
      uStack_4e0 = 0;
      local_4d8 = 0;
      uStack_4d0 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_4e8,(ushort *)L"Netmon Filter",0xd);
      local_228 = local_4c8;
      uStack_220 = uStack_4c0;
      local_218 = local_4b8;
      uStack_210 = uStack_4b0;
      local_4b8 = 0;
      uStack_4b0 = 7;
      local_4c8 = local_4c8 & 0xffffffffffff0000;
      local_208 = local_4e8;
      uStack_200 = uStack_4e0;
      local_1f8 = local_4d8;
      uStack_1f0 = uStack_4d0;
      local_4d8 = 0;
      uStack_4d0 = 7;
      local_4e8 = local_4e8 & 0xffffffffffff0000;
      local_508 = 0;
      uStack_500 = 0;
      local_4f8 = 0;
      uStack_4f0 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_508,(ushort *)L"Virtual Filtering Platform VMSwitch Extension",0x2d);
      local_528 = 0;
      uStack_520 = 0;
      local_518 = 0;
      uStack_510 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_528,(ushort *)L"VFP Extension",0xd);
      local_1e8 = local_508;
      uStack_1e0 = uStack_500;
      local_1d8 = local_4f8;
      uStack_1d0 = uStack_4f0;
      local_4f8 = 0;
      uStack_4f0 = 7;
      local_508 = local_508 & 0xffffffffffff0000;
      local_1c8 = local_528;
      uStack_1c0 = uStack_520;
      local_1b8 = local_518;
      uStack_1b0 = uStack_510;
      local_518 = 0;
      uStack_510 = 7;
      local_528 = local_528 & 0xffffffffffff0000;
      local_548 = 0;
      uStack_540 = 0;
      local_538 = 0;
      uStack_530 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_548,(ushort *)L"SLBMUX",6);
      local_568 = 0;
      uStack_560 = 0;
      local_558 = 0;
      uStack_550 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_568,(ushort *)L"SLB MUX",7);
      local_1a8 = local_548;
      uStack_1a0 = uStack_540;
      local_198 = local_538;
      uStack_190 = uStack_530;
      local_538 = 0;
      uStack_530 = 7;
      local_548 = local_548 & 0xffffffffffff0000;
      local_188 = local_568;
      uStack_180 = uStack_560;
      local_178 = local_558;
      uStack_170 = uStack_550;
      local_558 = 0;
      uStack_550 = 7;
      local_568 = local_568 & 0xffffffffffff0000;
      local_588 = 0;
      uStack_580 = 0;
      local_578 = 0;
      uStack_570 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_588,(ushort *)L"VMSP",4);
      local_5a8 = 0;
      uStack_5a0 = 0;
      local_598 = 0;
      uStack_590 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_5a8,(ushort *)L"VMS Protocol",0xc);
      local_168 = local_588;
      uStack_160 = uStack_580;
      local_158 = local_578;
      uStack_150 = uStack_570;
      local_578 = 0;
      uStack_570 = 7;
      local_588 = local_588 & 0xffffffffffff0000;
      local_148 = local_5a8;
      uStack_140 = uStack_5a0;
      local_138 = local_598;
      uStack_130 = uStack_590;
      local_598 = 0;
      uStack_590 = 7;
      local_5a8 = local_5a8 & 0xffffffffffff0000;
      local_5c8 = 0;
      uStack_5c0 = 0;
      local_5b8 = 0;
      uStack_5b0 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_5c8,(ushort *)L"VMSVSP",6);
      local_5e8 = 0;
      uStack_5e0 = 0;
      local_5d8 = 0;
      uStack_5d0 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_5e8,(ushort *)L"VMS Ext Protocol",0x10);
      local_128 = local_5c8;
      uStack_120 = uStack_5c0;
      local_118 = local_5b8;
      uStack_110 = uStack_5b0;
      local_5b8 = 0;
      uStack_5b0 = 7;
      local_5c8 = local_5c8 & 0xffffffffffff0000;
      local_108 = local_5e8;
      uStack_100 = uStack_5e0;
      local_f8 = local_5d8;
      uStack_f0 = uStack_5d0;
      local_5d8 = 0;
      uStack_5d0 = 7;
      local_5e8 = local_5e8 & 0xffffffffffff0000;
      local_608 = 0;
      uStack_600 = 0;
      local_5f8 = 0;
      uStack_5f0 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_608,(ushort *)L"WFP 802.3 MAC Layer LightWeight Filter",0x26);
      local_628 = 0;
      uStack_620 = 0;
      local_618 = 0;
      uStack_610 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_628,(ushort *)L"WFP 802.3 Filter",0x10);
      local_e8 = local_608;
      uStack_e0 = uStack_600;
      local_d8 = local_5f8;
      uStack_d0 = uStack_5f0;
      local_5f8 = 0;
      uStack_5f0 = 7;
      local_608 = local_608 & 0xffffffffffff0000;
      local_c8 = local_628;
      uStack_c0 = uStack_620;
      local_b8 = local_618;
      uStack_b0 = uStack_610;
      local_618 = 0;
      uStack_610 = 7;
      local_628 = local_628 & 0xffffffffffff0000;
      local_648 = 0;
      uStack_640 = 0;
      local_638 = 0;
      uStack_630 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_648,(ushort *)L"WFP Native MAC Layer LightWeight Filter",0x27);
      local_668 = 0;
      uStack_660 = 0;
      local_658 = 0;
      uStack_650 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_668,(ushort *)L"WFP Native Filter",0x11);
      local_a8 = local_648;
      uStack_a0 = uStack_640;
      local_98 = local_638;
      uStack_90 = uStack_630;
      local_638 = 0;
      uStack_630 = 7;
      local_648 = local_648 & 0xffffffffffff0000;
      local_88 = local_668;
      uStack_80 = uStack_660;
      local_78 = local_658;
      uStack_70 = uStack_650;
      local_658 = 0;
      uStack_650 = 7;
      local_668 = local_668 & 0xffffffffffff0000;
      local_688 = 0;
      uStack_680 = 0;
      local_678 = 0;
      uStack_670 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_688,(ushort *)L"WFP vSwitch Layers LightWeight Filter",0x25);
      local_6a8 = 0;
      uStack_6a0 = 0;
      local_698 = 0;
      uStack_690 = 0;
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::_Construct<1,unsigned_short_const*___ptr64>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_6a8,(ushort *)L"WFP vSwitch Filter",0x12);
      local_68 = local_688;
      uStack_60 = uStack_680;
      local_58 = local_678;
      uStack_50 = uStack_670;
      local_678 = 0;
      uStack_670 = 7;
      local_688 = local_688 & 0xffffffffffff0000;
      local_48 = local_6a8;
      uStack_40 = uStack_6a0;
      pmVar5._0_4_ = (map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
                      *)local_698;
      local_38._0_4_ =
           (map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
            *)local_698;
      local_38._4_4_ = local_698._4_4_;
      uStack_30 = (undefined4)uStack_690;
      uStack_2c = uStack_690._4_4_;
      local_698 = 0;
      uStack_690 = 7;
      local_6a8 = local_6a8 & 0xffffffffffff0000;
      local_6b8 = &local_368;
      local_6b0 = local_28;
      std::
      map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
      ::
      map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
                (pmVar5._0_4_,&local_6b8);
      _eh_vector_destructor_iterator_
                (&local_368,0x40,0xd,
                 std::
                 pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
                 ::
                 ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
                );
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_6a8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_688);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_668);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_648);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_628);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_608);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_5e8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_5c8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_5a8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_588);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_568);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_548);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_528);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_508);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_4e8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_4c8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_4a8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_488);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_468);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_448);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_428);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_408);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_3e8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_3c8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_3a8);
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::
      ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                  *)&local_388);
      atexit(`PktMon::ShortenDescription'::__l2::_dynamic_atexit_destructor_for__replacementMap__);
      _Init_thread_footer(&DAT_180021cf8);
    }
  }
  std::
  lower_bound<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>_>,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>,<lambda_aa490cf9a2687414692223e5a1c065db>_>
            (&local_6b8,(longlong *)*DAT_180021d00,(longlong *)DAT_180021d00,(undefined8 *)param_1);
  puVar4 = local_6b8 + 4;
  pbVar1 = (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
            *)(local_6b8 + 8);
  if (local_6b8 != DAT_180021d00) {
    pbVar3 = param_1;
    uVar2 = StartsWith((ushort *)puVar4,(undefined8 *)param_1);
    if ((char)uVar2 != '\0') {
      std::
      basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
      ::replace(param_1,(__uint64)pbVar3,puVar4[2],pbVar1);
    }
  }
  return;
}



===== StartsWith @ 1800154ac =====

undefined8 PktMon::StartsWith(ushort *param_1,undefined8 *param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  uVar3 = *(ulonglong *)(param_1 + 8);
  if (7 < *(ulonglong *)(param_1 + 0xc)) {
    param_1 = *(ushort **)param_1;
  }
  uVar5 = param_2[2];
  if (uVar3 <= (ulonglong)param_2[2]) {
    uVar5 = uVar3;
  }
  if (7 < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  uVar2 = uVar5;
  if (uVar3 < uVar5) {
    uVar2 = uVar3;
  }
  if (uVar2 != 0) {
    lVar4 = (longlong)param_2 - (longlong)param_1;
    do {
      uVar1 = *(ushort *)(lVar4 + (longlong)param_1);
      if (uVar1 != *param_1) {
        uVar3 = (ulonglong)((-(uint)(uVar1 < *param_1) & 0xfffffffe) + 1);
        goto LAB_180015511;
      }
      param_1 = param_1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  if (uVar5 < uVar3) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = (ulonglong)(uVar3 < uVar5);
  }
LAB_180015511:
  return CONCAT71((int7)(uVar3 >> 8),(int)uVar3 == 0);
}



===== SubscribeToEnabledStateChanges @ 180015520 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details::FeatureStateManager::SubscribeToEnabledStateChanges(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64),void *
   __ptr64) __ptr64 */

void __thiscall
wil::details::FeatureStateManager::SubscribeToEnabledStateChanges
          (FeatureStateManager *this,FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,
          _func_void_void_ptr *param_2,void *param_3)

{
  FeatureStateManager *SRWLock;
  FeatureStateManager *pFVar1;
  int iVar2;
  INT_PTR IVar3;
  
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  if (*this == (FeatureStateManager)0x0) {
    return;
  }
  SRWLock = this + 0x20;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  pFVar1 = this + 0x90;
  if (*(longlong *)pFVar1 == 0) {
    *(longlong *)pFVar1 = 0;
    if (g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification == (FARPROC)0x0) {
      if (`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
          wil_details_ntdllModuleHandle == (HINSTANCE__ *)0x0) {
        `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
        wil_details_ntdllModuleHandle = GetModuleHandleW(L"ntdll.dll");
      }
      g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification =
           GetProcAddress(`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'
                          ::__l2::wil_details_ntdllModuleHandle,
                          "RtlRegisterFeatureConfigurationChangeNotification");
      if (g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification != (FARPROC)0x0)
      goto LAB_1800155d0;
      iVar2 = -0x3ffffec7;
    }
    else {
LAB_1800155d0:
      IVar3 = (*g_wil_details_pfnRtlRegisterFeatureConfigurationChangeNotification)
                        (<lambda_1ad7ecfab602a777ecf020873216a663>::<lambda_invoker_cdecl>,this,0,
                         pFVar1);
      iVar2 = (int)IVar3;
    }
    if (iVar2 != 0) goto LAB_1800155fb;
  }
  details_abi::SubscriptionList::SubscribeUnderLock
            ((SubscriptionList *)(this + 0x48),param_1,param_2,param_3);
LAB_1800155fb:
  if (SRWLock != (FeatureStateManager *)0x0) {
    ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
  }
  return;
}



===== SubscribeToUsageFlush @ 180015630 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl wil::details::FeatureStateManager::SubscribeToUsageFlush(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64)) __ptr64
    */

void __thiscall
wil::details::FeatureStateManager::SubscribeToUsageFlush
          (FeatureStateManager *this,FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,
          _func_void_void_ptr *param_2)

{
  FeatureStateManager *SRWLock;
  FeatureStateManager *pFVar1;
  PSRWLOCK SRWLock_00;
  uchar uVar2;
  bool bVar3;
  
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  if ((*this != (FeatureStateManager)0x0) && (g_processShutdownInProgress == false)) {
    if ((g_pfnDllShutdownInProgress != (_func_uchar *)0x0) &&
       (uVar2 = (*g_pfnDllShutdownInProgress)(), uVar2 != '\0')) {
      return;
    }
    bVar3 = EnsureStateData(this);
    if (bVar3) {
      SRWLock = this + 0x20;
      AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
      pFVar1 = this + 0xe0;
      if ((*(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)pFVar1 ==
           (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) &&
         (SRWLock_00 = *(PSRWLOCK *)(this + 0x18), SRWLock_00 != (PSRWLOCK)0x0)) {
        *(FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)pFVar1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0
        ;
        AcquireSRWLockExclusive(SRWLock_00);
        details_abi::SubscriptionList::SubscribeUnderLock
                  ((SubscriptionList *)(SRWLock_00 + 0x19),
                   (FEATURE_STATE_CHANGE_SUBSCRIPTION__ **)pFVar1,
                   <lambda_152aa9d2a3a0648fa2fa7fcef514b376>::<lambda_invoker_cdecl>,this);
        ReleaseSRWLockExclusive(SRWLock_00);
      }
      details_abi::SubscriptionList::SubscribeUnderLock
                ((SubscriptionList *)(this + 0x98),param_1,param_2,(void *)0x0);
      if (*param_1 != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) {
        *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)((ulonglong)*param_1 | 0x80000000);
      }
      if (SRWLock != (FeatureStateManager *)0x0) {
        ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
      }
    }
  }
  return;
}



===== SubscribeUnderLock @ 180015754 =====

/* public: void __cdecl wil::details_abi::SubscriptionList::SubscribeUnderLock(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64),void *
   __ptr64) __ptr64 */

void __thiscall
wil::details_abi::SubscriptionList::SubscribeUnderLock
          (SubscriptionList *this,FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,
          _func_void_void_ptr *param_2,void *param_3)

{
  heap_buffer *this_00;
  FEATURE_STATE_CHANGE_SUBSCRIPTION__ *pFVar1;
  longlong *plVar2;
  bool bVar3;
  FEATURE_STATE_CHANGE_SUBSCRIPTION__ *pFVar4;
  longlong *plVar5;
  FEATURE_STATE_CHANGE_SUBSCRIPTION__ *pFVar6;
  _func_void_void_ptr *local_18;
  void *local_10;
  
  *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
  this_00 = (heap_buffer *)(this + 0x28);
  plVar2 = *(longlong **)this_00;
  pFVar6 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
           ((ulonglong)(*(longlong *)(this + 0x30) - (longlong)plVar2) >> 4);
  if (pFVar6 != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) {
    pFVar4 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0;
    plVar5 = plVar2;
    do {
      pFVar1 = pFVar4 + 1;
      if (*plVar5 == 0) {
        plVar2[(longlong)pFVar4 * 2] = (longlong)param_2;
        plVar2[(longlong)pFVar4 * 2 + 1] = (longlong)param_3;
        *param_1 = pFVar1;
        return;
      }
      plVar5 = plVar5 + 2;
      pFVar4 = pFVar1;
    } while (pFVar1 < pFVar6);
  }
  local_18 = param_2;
  local_10 = param_3;
  bVar3 = heap_buffer::push_back(this_00,&local_18,0x10);
  if (bVar3) {
    *param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
               ((ulonglong)(*(longlong *)(this + 0x30) - *(longlong *)this_00) >> 4);
  }
  return;
}



===== Swap @ 1800157ec =====

/* public: void __cdecl wil::details_abi::RawUsageIndex::Swap(class wil::details_abi::RawUsageIndex
   & __ptr64) __ptr64 */

void __thiscall wil::details_abi::RawUsageIndex::Swap(RawUsageIndex *this,RawUsageIndex *param_1)

{
  undefined8 uVar1;
  RawUsageIndex RVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  LPVOID pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  HANDLE pvVar11;
  
  uVar9 = *(undefined8 *)(this + 0x18);
  uVar10 = *(undefined8 *)(this + 0x20);
  uVar1 = *(undefined8 *)(this + 0x28);
  uVar3 = *(undefined8 *)(this + 0x30);
  *(undefined8 *)(this + 0x30) = 0;
  uVar6 = *(undefined4 *)(param_1 + 0x1c);
  uVar7 = *(undefined4 *)(param_1 + 0x20);
  uVar8 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = uVar6;
  *(undefined4 *)(this + 0x20) = uVar7;
  *(undefined4 *)(this + 0x24) = uVar8;
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(param_1 + 0x28);
  uVar4 = *(undefined8 *)(param_1 + 0x30);
  *(undefined8 *)(param_1 + 0x30) = 0;
  pvVar5 = *(LPVOID *)(this + 0x30);
  *(undefined8 *)(this + 0x30) = uVar4;
  if (pvVar5 != (LPVOID)0x0) {
    pvVar11 = GetProcessHeap();
    HeapFree(pvVar11,0,pvVar5);
  }
  *(undefined8 *)(param_1 + 0x18) = uVar9;
  *(undefined8 *)(param_1 + 0x20) = uVar10;
  *(undefined8 *)(param_1 + 0x28) = uVar1;
  pvVar5 = *(LPVOID *)(param_1 + 0x30);
  *(undefined8 *)(param_1 + 0x30) = uVar3;
  if (pvVar5 != (LPVOID)0x0) {
    pvVar11 = GetProcessHeap();
    HeapFree(pvVar11,0,pvVar5);
  }
  RVar2 = this[0x38];
  this[0x38] = param_1[0x38];
  param_1[0x38] = RVar2;
  RVar2 = this[0x39];
  this[0x39] = param_1[0x39];
  param_1[0x39] = RVar2;
  return;
}



===== UnregisterWilFeatureConfigurationChange @ 1800158e0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::UnregisterWilFeatureConfigurationChange(void * __ptr64) */

void __cdecl wil::details::UnregisterWilFeatureConfigurationChange(void *param_1)

{
  if (g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification == (FARPROC)0x0) {
    if (`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
        wil_details_ntdllModuleHandle == (HINSTANCE__ *)0x0) {
      `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
      wil_details_ntdllModuleHandle = GetModuleHandleW(L"ntdll.dll");
    }
    g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification =
         GetProcAddress(`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'
                        ::__l2::wil_details_ntdllModuleHandle,
                        "RtlUnregisterFeatureConfigurationChangeNotification");
    if (g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification == (FARPROC)0x0) {
      return;
    }
  }
  (*g_wil_details_pfnRtlUnregisterFeatureConfigurationChangeNotification)(param_1);
  return;
}



===== Unsubscribe @ 180015954 =====

/* public: void __cdecl wil::details_abi::SubscriptionList::Unsubscribe(class wil::srwlock &
   __ptr64,struct FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64) __ptr64 */

void __thiscall
wil::details_abi::SubscriptionList::Unsubscribe
          (SubscriptionList *this,srwlock *param_1,FEATURE_STATE_CHANGE_SUBSCRIPTION__ *param_2)

{
  undefined8 *puVar1;
  
  if (param_2 != (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)this);
    AcquireSRWLockExclusive((PSRWLOCK)param_1);
    if (param_2 + -1 <
        (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)
        ((ulonglong)(*(longlong *)(this + 0x30) - *(longlong *)(this + 0x28)) >> 4)) {
      puVar1 = (undefined8 *)(*(longlong *)(this + 0x28) + (longlong)(param_2 + -1) * 0x10);
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    if (param_1 != (srwlock *)0x0) {
      ReleaseSRWLockExclusive((PSRWLOCK)param_1);
    }
    if (this != (SubscriptionList *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)this);
    }
  }
  return;
}



===== WilApiImpl_RecordFeatureUsage @ 180015a00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl wil::details::WilApiImpl_RecordFeatureUsage(unsigned int,unsigned int,unsigned
   int,char const * __ptr64) */

void __cdecl
wil::details::WilApiImpl_RecordFeatureUsage(uint param_1,uint param_2,uint param_3,char *param_4)

{
  uint6 uVar1;
  uchar uVar2;
  bool bVar3;
  wil_details_ServiceReportingKind wVar4;
  undefined8 local_18;
  
  wVar4 = param_2 & 0x7fffffff;
  if (((param_1 == 0) && (param_3 == 0)) && (wVar4 == 0)) {
    if (!g_processShutdownInProgress) {
      if ((g_pfnDllShutdownInProgress != (_func_uchar *)0x0) &&
         (uVar2 = (*g_pfnDllShutdownInProgress)(), uVar2 != '\0')) {
        return;
      }
      bVar3 = FeatureStateManager::EnsureStateData((FeatureStateManager *)&g_featureStateManager);
      if (bVar3) {
        details_abi::SubscriptionList::OnSignaled
                  ((SubscriptionList *)(DAT_180021028 + 200),DAT_180021028);
        details_abi::FeatureStateData::RecordUsage((FeatureStateData *)DAT_180021028);
      }
    }
    return;
  }
  if (wVar4 >> 0x1e != 0) {
    FeatureStateManager::QueueBackgroundSRUMUsageReporting
              ((FeatureStateManager *)&g_featureStateManager,param_1,(ushort)param_2,param_3);
    return;
  }
  if ((param_3 != 0) || (wVar4 == 0xfe)) {
    FeatureStateManager::RecordFeatureUsage
              ((FeatureStateManager *)&g_featureStateManager,param_1,wVar4,(ulonglong)param_3);
    return;
  }
  local_18._0_6_ = CONCAT24((short)wVar4,param_1);
  uVar1 = (uint6)local_18;
  local_18 = (ulonglong)(uint6)local_18;
  if ((int)param_2 < 0) {
    local_18 = CONCAT26(1,uVar1);
  }
  if (g_wil_details_pfnRtlNotifyFeatureUsage == (FARPROC)0x0) {
    if (`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
        wil_details_ntdllModuleHandle == (HINSTANCE__ *)0x0) {
      `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
      wil_details_ntdllModuleHandle = GetModuleHandleW(L"ntdll.dll");
    }
    g_wil_details_pfnRtlNotifyFeatureUsage =
         GetProcAddress(`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'
                        ::__l2::wil_details_ntdllModuleHandle,"RtlNotifyFeatureUsage");
    if (g_wil_details_pfnRtlNotifyFeatureUsage == (FARPROC)0x0) {
      return;
    }
  }
  (*g_wil_details_pfnRtlNotifyFeatureUsage)(&local_18);
  return;
}



===== WilApiImpl_SubscribeFeatureStateChangeNotification @ 180015b40 =====

/* void __cdecl wil::details::WilApiImpl_SubscribeFeatureStateChangeNotification(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64 * __ptr64,void (__cdecl*)(void * __ptr64),void *
   __ptr64) */

void __cdecl
wil::details::WilApiImpl_SubscribeFeatureStateChangeNotification
          (FEATURE_STATE_CHANGE_SUBSCRIPTION__ **param_1,_func_void_void_ptr *param_2,void *param_3)

{
  if (param_3 == (void *)0xffffffffffffffff) {
    FeatureStateManager::SubscribeToUsageFlush
              ((FeatureStateManager *)&g_featureStateManager,param_1,param_2);
    return;
  }
  FeatureStateManager::SubscribeToEnabledStateChanges
            ((FeatureStateManager *)&g_featureStateManager,param_1,param_2,param_3);
  return;
}



===== WilApiImpl_UnsubscribeFeatureStateChangeNotification @ 180015b80 =====

/* void __cdecl wil::details::WilApiImpl_UnsubscribeFeatureStateChangeNotification(struct
   FEATURE_STATE_CHANGE_SUBSCRIPTION__ * __ptr64) */

void __cdecl
wil::details::WilApiImpl_UnsubscribeFeatureStateChangeNotification
          (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *param_1)

{
  SubscriptionList *this;
  
  if (((ulonglong)param_1 >> 0x1f & 1) == 0) {
    if (g_featureStateManager == (shutdown_aware_object<wil::details::FeatureStateManager>)0x0) {
      return;
    }
    this = (SubscriptionList *)&DAT_180021058;
  }
  else {
    if (g_featureStateManager == (shutdown_aware_object<wil::details::FeatureStateManager>)0x0) {
      return;
    }
    param_1 = (FEATURE_STATE_CHANGE_SUBSCRIPTION__ *)((ulonglong)param_1 & 0xffffffff7fffffff);
    this = (SubscriptionList *)&DAT_1800210a8;
  }
  details_abi::SubscriptionList::Unsubscribe(this,(srwlock *)&DAT_180021030,param_1);
  return;
}



===== Write @ 180015bd8 =====

/* public: bool __cdecl wil::details_abi::UsageIndexProperty::Write(unsigned char * __ptr64 &
   __ptr64,unsigned char * __ptr64)const __ptr64 */

bool __thiscall
wil::details_abi::UsageIndexProperty::Write(UsageIndexProperty *this,uchar **param_1,uchar *param_2)

{
  undefined4 *puVar1;
  uchar *_Dst;
  uchar *puVar2;
  ulonglong _MaxCount;
  
  _Dst = *param_1;
  if (this[2] == (UsageIndexProperty)0x1) {
    puVar2 = _Dst + 2;
    if (param_2 < puVar2) {
      return false;
    }
    if (_Dst != (uchar *)0x0) {
      *(undefined2 *)_Dst = *(undefined2 *)(this + 4);
      _Dst = puVar2;
      goto LAB_180015c5e;
    }
  }
  else {
    if (this[2] != (UsageIndexProperty)0x2) goto LAB_180015c5e;
    puVar2 = _Dst + 4;
    if (param_2 < puVar2) {
      return false;
    }
    if (_Dst != (uchar *)0x0) {
      if (this + 4 != (UsageIndexProperty *)0x0) {
        *(undefined4 *)_Dst = *(undefined4 *)(this + 4);
        _Dst = puVar2;
        goto LAB_180015c5e;
      }
      _Dst[0] = '\0';
      _Dst[1] = '\0';
      _Dst[2] = '\0';
      _Dst[3] = '\0';
    }
  }
  puVar1 = (undefined4 *)_o__errno();
  *puVar1 = 0x16;
  _o__invalid_parameter_noinfo();
  _Dst = puVar2;
LAB_180015c5e:
  if (*(short *)this == 0) {
    if (param_2 < _Dst + 2) {
      return false;
    }
    memcpy_s(_Dst,(longlong)param_2 - (longlong)_Dst,this + 8,2);
    _Dst = _Dst + 2;
  }
  _MaxCount = (ulonglong)*(ushort *)(this + 8);
  if (param_2 < _Dst + _MaxCount) {
    return false;
  }
  memcpy_s(_Dst,(longlong)param_2 - (longlong)_Dst,*(void **)(this + 0x18),_MaxCount);
  *param_1 = _Dst + *(ushort *)(this + 8);
  return true;
}



===== _Change_array @ 180015ce4 =====

/* private: void __cdecl std::vector<class PktMon::CompGroup const * __ptr64,class
   std::allocator<class PktMon::CompGroup const * __ptr64> >::_Change_array(class PktMon::CompGroup
   const * __ptr64 * __ptr64 const,unsigned __int64,unsigned __int64) __ptr64 */

void __thiscall
std::vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>::
_Change_array(vector<PktMon::CompGroup_const*___ptr64,std::allocator<PktMon::CompGroup_const*___ptr64>_>
              *this,CompGroup **param_1,__uint64 param_2,__uint64 param_3)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = *(longlong *)(this + 0x10) - (longlong)pvVar1 & 0xfffffffffffffff8;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
  }
  *(CompGroup ***)this = param_1;
  *(CompGroup ***)(this + 8) = param_1 + param_2;
  *(CompGroup ***)(this + 0x10) = param_1 + param_3;
  return;
}



===== _Change_array @ 180015d7c =====

/* private: void __cdecl std::vector<struct PktMon::CounterInfo,class std::allocator<struct
   PktMon::CounterInfo> >::_Change_array(struct PktMon::CounterInfo * __ptr64 const,unsigned
   __int64,unsigned __int64) __ptr64 */

void __thiscall
std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::_Change_array
          (vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *this,
          CounterInfo *param_1,__uint64 param_2,__uint64 param_3)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = (*(longlong *)(this + 0x10) - (longlong)pvVar1 >> 4) * 0x10;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
  }
  *(CounterInfo **)this = param_1;
  *(CounterInfo **)(this + 8) = param_1 + param_2 * 0x50;
  *(CounterInfo **)(this + 0x10) = param_1 + param_3 * 0x50;
  return;
}



===== _Change_array @ 180015e38 =====

/* private: void __cdecl std::vector<class PktMon::Component,class std::allocator<class
   PktMon::Component> >::_Change_array(class PktMon::Component * __ptr64 const,unsigned
   __int64,unsigned __int64) __ptr64 */

void __thiscall
std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::_Change_array
          (vector<PktMon::Component,std::allocator<PktMon::Component>_> *this,Component *param_1,
          __uint64 param_2,__uint64 param_3)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  __uint64 _Var4;
  
  pvVar1 = *(void **)this;
  if (pvVar1 != (void *)0x0) {
    _Var4 = (*(longlong *)(this + 0x10) - (longlong)pvVar1 >> 3) * 8;
    pvVar3 = pvVar1;
    if (0xfff < _Var4) {
      pvVar3 = *(void **)((longlong)pvVar1 + -8);
      _Var4 = _Var4 + 0x27;
      if (0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar3))) {
        _o__invalid_parameter_noinfo_noreturn();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    operator_delete(pvVar3,_Var4);
  }
  *(Component **)this = param_1;
  *(Component **)(this + 8) = param_1 + param_2 * 0x18;
  *(Component **)(this + 0x10) = param_1 + param_3 * 0x18;
  return;
}



===== _Copy @ 180015ef0 =====

undefined8 *
std::
_Func_impl_no_alloc<<lambda_286206d2d200759d6dc9d044133ee447>,PktMon::CompGroup_*,unsigned_long,enum__PKTMON_COMPONENT_TYPE>
::_Copy(longlong param_1,undefined8 *param_2)

{
  *param_2 = &PTR__Copy_18001a0e8;
  param_2[1] = *(undefined8 *)(param_1 + 8);
  return param_2;
}



===== _Delete_this @ 180015f10 =====

void std::
     _Func_impl_no_alloc<<lambda_286206d2d200759d6dc9d044133ee447>,PktMon::CompGroup_*,unsigned_long,enum__PKTMON_COMPONENT_TYPE>
     ::_Delete_this(void *param_1,char param_2)

{
  if (param_2 != '\0') {
    operator_delete(param_1,0x10);
  }
  return;
}



===== _Do_call @ 180015f30 =====

void std::
     _Func_impl_no_alloc<<lambda_286206d2d200759d6dc9d044133ee447>,PktMon::CompGroup_*,unsigned_long,enum__PKTMON_COMPONENT_TYPE>
     ::_Do_call(longlong param_1,ulong *param_2,_PKTMON_COMPONENT_TYPE *param_3)

{
  CompGroup *pCVar1;
  
  pCVar1 = PktMon::CompList::FindOrCreateGroup(*(CompList **)(param_1 + 8),*param_2,*param_3);
  pCVar1[0xc] = (CompGroup)0x1;
  return;
}



===== _Extract @ 180015f54 =====

/* public: struct std::_Tree_node<long,void * __ptr64> * __ptr64 __cdecl std::_Tree_val<struct
   std::_Tree_simple_types<long> >::_Extract(class std::_Tree_unchecked_const_iterator<class
   std::_Tree_val<struct std::_Tree_simple_types<long> >,struct std::_Iterator_base0>) __ptr64 */

_Tree_node<long,void*___ptr64> * __thiscall
std::_Tree_val<std::_Tree_simple_types<long>_>::_Extract
          (_Tree_val<std::_Tree_simple_types<long>_> *this,_Tree_node<long,void*___ptr64> *param_2)

{
  _Tree_node<long,void*___ptr64> _Var1;
  longlong lVar2;
  undefined8 *puVar3;
  _Tree_node<long,void*___ptr64> *p_Var4;
  _Tree_node<long,void*___ptr64> *p_Var5;
  longlong *plVar6;
  _Tree_node<long,void*___ptr64> *p_Var7;
  _Tree_node<long,void*___ptr64> *p_Var8;
  _Tree_node<long,void*___ptr64> *p_Var9;
  
  p_Var5 = param_2 + 0x10;
  p_Var4 = *(_Tree_node<long,void*___ptr64> **)p_Var5;
  if (p_Var4[0x19] == (_Tree_node<long,void*___ptr64>)0x0) {
    _Var1 = (*(_Tree_node<long,void*___ptr64> **)p_Var4)[0x19];
    p_Var8 = *(_Tree_node<long,void*___ptr64> **)p_Var4;
    while (_Var1 == (_Tree_node<long,void*___ptr64>)0x0) {
      _Var1 = (*(_Tree_node<long,void*___ptr64> **)p_Var8)[0x19];
      p_Var4 = p_Var8;
      p_Var8 = *(_Tree_node<long,void*___ptr64> **)p_Var8;
    }
  }
  else {
    p_Var8 = *(_Tree_node<long,void*___ptr64> **)(param_2 + 8);
    p_Var7 = param_2;
    while ((p_Var4 = p_Var8, p_Var4[0x19] == (_Tree_node<long,void*___ptr64>)0x0 &&
           (p_Var7 == *(_Tree_node<long,void*___ptr64> **)(p_Var4 + 0x10)))) {
      p_Var8 = *(_Tree_node<long,void*___ptr64> **)(p_Var4 + 8);
      p_Var7 = p_Var4;
    }
  }
  p_Var9 = param_2 + 8;
  p_Var8 = *(_Tree_node<long,void*___ptr64> **)param_2;
  p_Var7 = *(_Tree_node<long,void*___ptr64> **)p_Var5;
  if (p_Var8[0x19] == (_Tree_node<long,void*___ptr64>)0x0) {
    if ((*(_Tree_node<long,void*___ptr64> **)p_Var5)[0x19] == (_Tree_node<long,void*___ptr64>)0x0) {
      p_Var7 = *(_Tree_node<long,void*___ptr64> **)(p_Var4 + 0x10);
      if (p_Var4 != param_2) {
        *(_Tree_node<long,void*___ptr64> **)(p_Var8 + 8) = p_Var4;
        *(longlong *)p_Var4 = *(longlong *)param_2;
        if (p_Var4 == *(_Tree_node<long,void*___ptr64> **)p_Var5) {
          p_Var8 = p_Var4;
        }
        else {
          p_Var8 = *(_Tree_node<long,void*___ptr64> **)(p_Var4 + 8);
          if (p_Var7[0x19] == (_Tree_node<long,void*___ptr64>)0x0) {
            *(_Tree_node<long,void*___ptr64> **)(p_Var7 + 8) = p_Var8;
          }
          *(_Tree_node<long,void*___ptr64> **)p_Var8 = p_Var7;
          *(longlong *)(p_Var4 + 0x10) = *(longlong *)p_Var5;
          *(_Tree_node<long,void*___ptr64> **)(*(longlong *)p_Var5 + 8) = p_Var4;
        }
        if (*(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8) == param_2) {
          *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8) = p_Var4;
        }
        else {
          puVar3 = *(undefined8 **)p_Var9;
          if ((_Tree_node<long,void*___ptr64> *)*puVar3 == param_2) {
            *puVar3 = p_Var4;
          }
          else {
            puVar3[2] = p_Var4;
          }
        }
        _Var1 = p_Var4[0x18];
        *(longlong *)(p_Var4 + 8) = *(longlong *)p_Var9;
        p_Var4[0x18] = param_2[0x18];
        param_2[0x18] = _Var1;
        goto LAB_1800160cb;
      }
    }
    else {
      p_Var7 = p_Var8;
    }
  }
  p_Var8 = *(_Tree_node<long,void*___ptr64> **)p_Var9;
  if (p_Var7[0x19] == (_Tree_node<long,void*___ptr64>)0x0) {
    *(_Tree_node<long,void*___ptr64> **)(p_Var7 + 8) = p_Var8;
  }
  if (*(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8) == param_2) {
    *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8) = p_Var7;
  }
  else if (*(_Tree_node<long,void*___ptr64> **)p_Var8 == param_2) {
    *(_Tree_node<long,void*___ptr64> **)p_Var8 = p_Var7;
  }
  else {
    *(_Tree_node<long,void*___ptr64> **)(p_Var8 + 0x10) = p_Var7;
  }
  if ((_Tree_node<long,void*___ptr64> *)**(undefined8 **)this == param_2) {
    if (p_Var7[0x19] == (_Tree_node<long,void*___ptr64>)0x0) {
      _Var1 = (*(_Tree_node<long,void*___ptr64> **)p_Var7)[0x19];
      p_Var5 = *(_Tree_node<long,void*___ptr64> **)p_Var7;
      p_Var4 = p_Var7;
      while (p_Var9 = p_Var5, _Var1 == (_Tree_node<long,void*___ptr64>)0x0) {
        p_Var5 = *(_Tree_node<long,void*___ptr64> **)p_Var9;
        _Var1 = p_Var5[0x19];
        p_Var4 = p_Var9;
      }
    }
    else {
      p_Var4 = p_Var8;
    }
    **(undefined8 **)this = p_Var4;
  }
  if (*(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 0x10) == param_2) {
    if (p_Var7[0x19] == (_Tree_node<long,void*___ptr64>)0x0) {
      p_Var5 = p_Var7;
      for (p_Var4 = *(_Tree_node<long,void*___ptr64> **)(p_Var7 + 0x10);
          p_Var4[0x19] == (_Tree_node<long,void*___ptr64>)0x0;
          p_Var4 = *(_Tree_node<long,void*___ptr64> **)(p_Var4 + 0x10)) {
        p_Var5 = p_Var4;
      }
    }
    else {
      p_Var5 = p_Var8;
    }
    *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 0x10) = p_Var5;
  }
LAB_1800160cb:
  if (param_2[0x18] == (_Tree_node<long,void*___ptr64>)0x1) {
    if (p_Var7 != *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8)) {
      do {
        p_Var5 = p_Var8;
        if (p_Var7[0x18] != (_Tree_node<long,void*___ptr64>)0x1) break;
        p_Var4 = *(_Tree_node<long,void*___ptr64> **)p_Var5;
        if (p_Var7 == p_Var4) {
          p_Var4 = *(_Tree_node<long,void*___ptr64> **)(p_Var5 + 0x10);
          if (p_Var4[0x18] == (_Tree_node<long,void*___ptr64>)0x0) {
            p_Var4[0x18] = (_Tree_node<long,void*___ptr64>)0x1;
            plVar6 = *(longlong **)(p_Var5 + 0x10);
            p_Var5[0x18] = (_Tree_node<long,void*___ptr64>)0x0;
            *(longlong *)(p_Var5 + 0x10) = *plVar6;
            if (*(char *)(*plVar6 + 0x19) == '\0') {
              *(_Tree_node<long,void*___ptr64> **)(*plVar6 + 8) = p_Var5;
            }
            plVar6[1] = *(longlong *)(p_Var5 + 8);
            if (p_Var5 == *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8)) {
              *(longlong **)(*(longlong *)this + 8) = plVar6;
            }
            else {
              puVar3 = *(undefined8 **)(p_Var5 + 8);
              if (p_Var5 == (_Tree_node<long,void*___ptr64> *)*puVar3) {
                *puVar3 = plVar6;
              }
              else {
                puVar3[2] = plVar6;
              }
            }
            *plVar6 = (longlong)p_Var5;
            *(longlong **)(p_Var5 + 8) = plVar6;
            p_Var4 = *(_Tree_node<long,void*___ptr64> **)(p_Var5 + 0x10);
          }
          if (p_Var4[0x19] == (_Tree_node<long,void*___ptr64>)0x0) {
            if ((*(char *)(*(longlong *)p_Var4 + 0x18) != '\x01') ||
               (*(char *)(*(longlong *)(p_Var4 + 0x10) + 0x18) != '\x01')) {
              if (*(char *)(*(longlong *)(p_Var4 + 0x10) + 0x18) == '\x01') {
                *(undefined1 *)(*(longlong *)p_Var4 + 0x18) = 1;
                lVar2 = *(longlong *)p_Var4;
                p_Var4[0x18] = (_Tree_node<long,void*___ptr64>)0x0;
                *(longlong *)p_Var4 = *(longlong *)(lVar2 + 0x10);
                if (*(char *)(*(longlong *)(lVar2 + 0x10) + 0x19) == '\0') {
                  *(_Tree_node<long,void*___ptr64> **)(*(longlong *)(lVar2 + 0x10) + 8) = p_Var4;
                }
                *(longlong *)(lVar2 + 8) = *(longlong *)(p_Var4 + 8);
                if (p_Var4 == *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8)) {
                  *(longlong *)(*(longlong *)this + 8) = lVar2;
                }
                else {
                  plVar6 = *(longlong **)(p_Var4 + 8);
                  if (p_Var4 == (_Tree_node<long,void*___ptr64> *)plVar6[2]) {
                    plVar6[2] = lVar2;
                  }
                  else {
                    *plVar6 = lVar2;
                  }
                }
                *(_Tree_node<long,void*___ptr64> **)(lVar2 + 0x10) = p_Var4;
                *(longlong *)(p_Var4 + 8) = lVar2;
                p_Var4 = *(_Tree_node<long,void*___ptr64> **)(p_Var5 + 0x10);
              }
              p_Var4[0x18] = p_Var5[0x18];
              p_Var5[0x18] = (_Tree_node<long,void*___ptr64>)0x1;
              *(undefined1 *)(*(longlong *)(p_Var4 + 0x10) + 0x18) = 1;
              plVar6 = *(longlong **)(p_Var5 + 0x10);
              *(longlong *)(p_Var5 + 0x10) = *plVar6;
              if (*(char *)(*plVar6 + 0x19) == '\0') {
                *(_Tree_node<long,void*___ptr64> **)(*plVar6 + 8) = p_Var5;
              }
              plVar6[1] = *(longlong *)(p_Var5 + 8);
              if (p_Var5 == *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8)) {
                *(longlong **)(*(longlong *)this + 8) = plVar6;
              }
              else {
                puVar3 = *(undefined8 **)(p_Var5 + 8);
                if (p_Var5 == (_Tree_node<long,void*___ptr64> *)*puVar3) {
                  *puVar3 = plVar6;
                }
                else {
                  puVar3[2] = plVar6;
                }
              }
              *plVar6 = (longlong)p_Var5;
              goto LAB_180016393;
            }
            goto LAB_180016245;
          }
        }
        else {
          if (p_Var4[0x18] == (_Tree_node<long,void*___ptr64>)0x0) {
            p_Var4[0x18] = (_Tree_node<long,void*___ptr64>)0x1;
            lVar2 = *(longlong *)p_Var5;
            p_Var5[0x18] = (_Tree_node<long,void*___ptr64>)0x0;
            *(longlong *)p_Var5 = *(longlong *)(lVar2 + 0x10);
            if (*(char *)(*(longlong *)(lVar2 + 0x10) + 0x19) == '\0') {
              *(_Tree_node<long,void*___ptr64> **)(*(longlong *)(lVar2 + 0x10) + 8) = p_Var5;
            }
            *(longlong *)(lVar2 + 8) = *(longlong *)(p_Var5 + 8);
            if (p_Var5 == *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8)) {
              *(longlong *)(*(longlong *)this + 8) = lVar2;
            }
            else {
              plVar6 = *(longlong **)(p_Var5 + 8);
              if (p_Var5 == (_Tree_node<long,void*___ptr64> *)plVar6[2]) {
                plVar6[2] = lVar2;
              }
              else {
                *plVar6 = lVar2;
              }
            }
            *(_Tree_node<long,void*___ptr64> **)(lVar2 + 0x10) = p_Var5;
            *(longlong *)(p_Var5 + 8) = lVar2;
            p_Var4 = *(_Tree_node<long,void*___ptr64> **)p_Var5;
          }
          if (p_Var4[0x19] == (_Tree_node<long,void*___ptr64>)0x0) {
            if ((*(char *)(*(longlong *)(p_Var4 + 0x10) + 0x18) != '\x01') ||
               (*(char *)(*(longlong *)p_Var4 + 0x18) != '\x01')) {
              if (*(char *)(*(longlong *)p_Var4 + 0x18) == '\x01') {
                *(undefined1 *)(*(longlong *)(p_Var4 + 0x10) + 0x18) = 1;
                plVar6 = *(longlong **)(p_Var4 + 0x10);
                p_Var4[0x18] = (_Tree_node<long,void*___ptr64>)0x0;
                *(longlong *)(p_Var4 + 0x10) = *plVar6;
                if (*(char *)(*plVar6 + 0x19) == '\0') {
                  *(_Tree_node<long,void*___ptr64> **)(*plVar6 + 8) = p_Var4;
                }
                plVar6[1] = *(longlong *)(p_Var4 + 8);
                if (p_Var4 == *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8)) {
                  *(longlong **)(*(longlong *)this + 8) = plVar6;
                }
                else {
                  puVar3 = *(undefined8 **)(p_Var4 + 8);
                  if (p_Var4 == (_Tree_node<long,void*___ptr64> *)*puVar3) {
                    *puVar3 = plVar6;
                  }
                  else {
                    puVar3[2] = plVar6;
                  }
                }
                *plVar6 = (longlong)p_Var4;
                *(longlong **)(p_Var4 + 8) = plVar6;
                p_Var4 = *(_Tree_node<long,void*___ptr64> **)p_Var5;
              }
              p_Var4[0x18] = p_Var5[0x18];
              p_Var5[0x18] = (_Tree_node<long,void*___ptr64>)0x1;
              *(undefined1 *)(*(longlong *)p_Var4 + 0x18) = 1;
              plVar6 = *(longlong **)p_Var5;
              *(longlong *)p_Var5 = plVar6[2];
              if (*(char *)(plVar6[2] + 0x19) == '\0') {
                *(_Tree_node<long,void*___ptr64> **)(plVar6[2] + 8) = p_Var5;
              }
              plVar6[1] = *(longlong *)(p_Var5 + 8);
              if (p_Var5 == *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8)) {
                *(longlong **)(*(longlong *)this + 8) = plVar6;
              }
              else {
                puVar3 = *(undefined8 **)(p_Var5 + 8);
                if (p_Var5 == (_Tree_node<long,void*___ptr64> *)puVar3[2]) {
                  puVar3[2] = plVar6;
                }
                else {
                  *puVar3 = plVar6;
                }
              }
              plVar6[2] = (longlong)p_Var5;
LAB_180016393:
              *(longlong **)(p_Var5 + 8) = plVar6;
              break;
            }
LAB_180016245:
            p_Var4[0x18] = (_Tree_node<long,void*___ptr64>)0x0;
          }
        }
        p_Var8 = *(_Tree_node<long,void*___ptr64> **)(p_Var5 + 8);
        p_Var7 = p_Var5;
      } while (p_Var5 != *(_Tree_node<long,void*___ptr64> **)(*(longlong *)this + 8));
    }
    p_Var7[0x18] = (_Tree_node<long,void*___ptr64>)0x1;
  }
  if (*(longlong *)(this + 8) != 0) {
    *(longlong *)(this + 8) = *(longlong *)(this + 8) + -1;
  }
  return param_2;
}



===== _FailFast_Unexpected @ 1800163c8 =====

/* void __cdecl wil::details::in1diag3::_FailFast_Unexpected(void * __ptr64,unsigned int,char const
   * __ptr64) */

void __cdecl wil::details::in1diag3::_FailFast_Unexpected(void *param_1,uint param_2,char *param_3)

{
  code *pcVar1;
  char *in_R9;
  void *unaff_retaddr;
  char *in_stack_ffffffffffffffd8;
  long in_stack_ffffffffffffffe8;
  
  ReportFailure_Hr<3>(param_1,0x137b,"onecore\\internal\\sdk\\inc\\wil\\Staging.h",in_R9,
                      in_stack_ffffffffffffffd8,unaff_retaddr,in_stack_ffffffffffffffe8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _Get @ 1800163f0 =====

longlong std::
         _Func_impl_no_alloc<<lambda_286206d2d200759d6dc9d044133ee447>,PktMon::CompGroup_*,unsigned_long,enum__PKTMON_COMPONENT_TYPE>
         ::_Get(longlong param_1)

{
  return param_1 + 8;
}



===== _Insert_node @ 1800163fc =====

/* public: struct std::_Tree_node<struct std::pair<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const >,void * __ptr64> * __ptr64 __cdecl std::_Tree_val<struct
   std::_Tree_simple_types<struct std::pair<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const > > >::_Insert_node(struct std::_Tree_id<struct
   std::_Tree_node<struct std::pair<class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const ,class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const >,void * __ptr64> * __ptr64>,struct std::_Tree_node<struct
   std::pair<class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const ,class std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> > const >,void * __ptr64> *
   __ptr64 const) __ptr64 */

_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
* __thiscall
std::
_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
::_Insert_node(_Tree_val<std::_Tree_simple_types<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>_>
               *this,longlong *param_2,
              _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
              *param_3)

{
  longlong *plVar1;
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  *p_Var2;
  longlong *plVar3;
  undefined8 *puVar4;
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  *p_Var5;
  longlong lVar6;
  longlong *plVar7;
  _Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
  *p_Var8;
  longlong *plVar9;
  
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 1;
  plVar1 = *(longlong **)this;
  plVar7 = (longlong *)*param_2;
  *(longlong **)(param_3 + 8) = plVar7;
  if (plVar7 == plVar1) {
    *plVar1 = (longlong)param_3;
    plVar1[1] = (longlong)param_3;
    plVar1[2] = (longlong)param_3;
    param_3[0x18] =
         (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
          )0x1;
  }
  else {
    if ((int)param_2[1] == 0) {
      plVar7[2] = (longlong)param_3;
      if (plVar7 == (longlong *)plVar1[2]) {
        plVar1[2] = (longlong)param_3;
      }
    }
    else {
      *plVar7 = (longlong)param_3;
      if (plVar7 == (longlong *)*plVar1) {
        *plVar1 = (longlong)param_3;
      }
    }
    lVar6 = *(longlong *)(param_3 + 8);
    p_Var8 = param_3;
    while (*(char *)(lVar6 + 0x18) == '\0') {
      p_Var2 = *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                 **)(p_Var8 + 8);
      p_Var5 = (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                *)**(longlong **)(p_Var2 + 8);
      if (p_Var2 == p_Var5) {
        p_Var5 = (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                  *)(*(longlong **)(p_Var2 + 8))[2];
        if (p_Var5[0x18] !=
            (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
             )0x0) {
          p_Var5 = *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                     **)(p_Var2 + 0x10);
          if (p_Var8 == p_Var5) {
            *(longlong *)(p_Var2 + 0x10) = *(longlong *)p_Var5;
            if (*(char *)(*(longlong *)p_Var5 + 0x19) == '\0') {
              *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                **)(*(longlong *)p_Var5 + 8) = p_Var2;
            }
            *(longlong *)(p_Var5 + 8) = *(longlong *)(p_Var2 + 8);
            if (p_Var2 == *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                            **)(*(longlong *)this + 8)) {
              *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                **)(*(longlong *)this + 8) = p_Var5;
            }
            else {
              plVar7 = *(longlong **)(p_Var2 + 8);
              if (p_Var2 == (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                             *)*plVar7) {
                *plVar7 = (longlong)p_Var5;
              }
              else {
                plVar7[2] = (longlong)p_Var5;
              }
            }
            *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
              **)p_Var5 = p_Var2;
            *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
              **)(p_Var2 + 8) = p_Var5;
            p_Var8 = p_Var2;
          }
          *(undefined1 *)(*(longlong *)(p_Var8 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var8 + 8) + 8) + 0x18) = 0;
          plVar7 = *(longlong **)(*(longlong *)(p_Var8 + 8) + 8);
          plVar9 = (longlong *)*plVar7;
          *plVar7 = plVar9[2];
          if (*(char *)(plVar9[2] + 0x19) == '\0') {
            *(longlong **)(plVar9[2] + 8) = plVar7;
          }
          plVar9[1] = plVar7[1];
          if (plVar7 == *(longlong **)(*(longlong *)this + 8)) {
            *(longlong **)(*(longlong *)this + 8) = plVar9;
          }
          else {
            plVar3 = (longlong *)plVar7[1];
            if (plVar7 == (longlong *)plVar3[2]) {
              plVar3[2] = (longlong)plVar9;
            }
            else {
              *plVar3 = (longlong)plVar9;
            }
          }
          plVar9[2] = (longlong)plVar7;
          goto LAB_180016603;
        }
LAB_180016534:
        p_Var2[0x18] = (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                        )0x1;
        p_Var5[0x18] = (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                        )0x1;
        *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var8 + 8) + 8) + 0x18) = 0;
        p_Var8 = *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                   **)(*(longlong *)(p_Var8 + 8) + 8);
      }
      else {
        if (p_Var5[0x18] ==
            (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
             )0x0) goto LAB_180016534;
        p_Var5 = *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                   **)p_Var2;
        if (p_Var8 == p_Var5) {
          *(longlong *)p_Var2 = *(longlong *)(p_Var5 + 0x10);
          if (*(char *)(*(longlong *)(p_Var5 + 0x10) + 0x19) == '\0') {
            *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
              **)(*(longlong *)(p_Var5 + 0x10) + 8) = p_Var2;
          }
          *(longlong *)(p_Var5 + 8) = *(longlong *)(p_Var2 + 8);
          if (p_Var2 == *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                          **)(*(longlong *)this + 8)) {
            *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
              **)(*(longlong *)this + 8) = p_Var5;
          }
          else {
            puVar4 = *(undefined8 **)(p_Var2 + 8);
            if (p_Var2 == (_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
                           *)puVar4[2]) {
              puVar4[2] = p_Var5;
            }
            else {
              *puVar4 = p_Var5;
            }
          }
          *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
            **)(p_Var5 + 0x10) = p_Var2;
          *(_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>
            **)(p_Var2 + 8) = p_Var5;
          p_Var8 = p_Var2;
        }
        *(undefined1 *)(*(longlong *)(p_Var8 + 8) + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var8 + 8) + 8) + 0x18) = 0;
        plVar7 = *(longlong **)(*(longlong *)(p_Var8 + 8) + 8);
        plVar9 = (longlong *)plVar7[2];
        plVar7[2] = *plVar9;
        if (*(char *)(*plVar9 + 0x19) == '\0') {
          *(longlong **)(*plVar9 + 8) = plVar7;
        }
        plVar9[1] = plVar7[1];
        if (plVar7 == *(longlong **)(*(longlong *)this + 8)) {
          *(longlong **)(*(longlong *)this + 8) = plVar9;
        }
        else {
          puVar4 = (undefined8 *)plVar7[1];
          if (plVar7 == (longlong *)*puVar4) {
            *puVar4 = plVar9;
          }
          else {
            puVar4[2] = plVar9;
          }
        }
        *plVar9 = (longlong)plVar7;
LAB_180016603:
        plVar7[1] = (longlong)plVar9;
      }
      lVar6 = *(longlong *)(p_Var8 + 8);
    }
    *(undefined1 *)(plVar1[1] + 0x18) = 1;
  }
  return param_3;
}



===== _Target_type @ 180016630 =====

TypeDescriptor *
std::
_Func_impl_no_alloc<<lambda_286206d2d200759d6dc9d044133ee447>,PktMon::CompGroup_*,unsigned_long,enum__PKTMON_COMPONENT_TYPE>
::_Target_type(void)

{
  return &<lambda_286206d2d200759d6dc9d044133ee447>::RTTI_Type_Descriptor;
}



===== _Throw_bad_optional_access @ 180016640 =====

/* void __cdecl std::_Throw_bad_optional_access(void) */

void __cdecl std::_Throw_bad_optional_access(void)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  bad_optional_access::bad_optional_access((bad_optional_access *)&local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_28,(ThrowInfo *)&_TI2_AVbad_optional_access_std__);
}



===== _Throw_tree_length_error @ 180016678 =====

/* void __cdecl std::_Throw_tree_length_error(void) */

void __cdecl std::_Throw_tree_length_error(void)

{
  code *pcVar1;
  
  std::_Xlength_error("map/set too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __clone @ 1800166a0 =====

/* public: virtual void __cdecl wistd::__function::__func<class
   <lambda_8db0ce862824541f40dfb767113f1e28>,bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::__clone(class wistd::__function::__base<bool
   __cdecl(void * __ptr64,unsigned __int64,void * __ptr64,unsigned __int64,unsigned int)> *
   __ptr64)const __ptr64 */

void __thiscall
wistd::__function::
__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
::__clone(__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
          *this,__base<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
                *param_1)

{
  undefined8 uVar1;
  
  *(undefined ***)param_1 = &_vftable_;
  uVar1 = *(undefined8 *)(this + 0x10);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(this + 8);
  *(undefined8 *)(param_1 + 0x10) = uVar1;
  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(this + 0x18);
  return;
}



===== deallocate @ 1800166c4 =====

/* public: void __cdecl std::allocator<struct PktMon::CounterInfo>::deallocate(struct
   PktMon::CounterInfo * __ptr64 const,unsigned __int64) __ptr64 */

void __thiscall
std::allocator<PktMon::CounterInfo>::deallocate
          (allocator<PktMon::CounterInfo> *this,CounterInfo *param_1,__uint64 param_2)

{
  code *pcVar1;
  CounterInfo *pCVar2;
  __uint64 _Var3;
  
  _Var3 = param_2 * 0x50;
  pCVar2 = param_1;
  if (0xfff < _Var3) {
    pCVar2 = *(CounterInfo **)(param_1 + -8);
    _Var3 = _Var3 + 0x27;
    if ((CounterInfo *)0x1f < param_1 + (-8 - (longlong)pCVar2)) {
      _o__invalid_parameter_noinfo_noreturn();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  operator_delete(pCVar2,_Var3);
  return;
}



===== destroy @ 180016720 =====

/* public: virtual void __cdecl wistd::__function::__func<class
   <lambda_8db0ce862824541f40dfb767113f1e28>,bool __cdecl(void * __ptr64,unsigned __int64,void *
   __ptr64,unsigned __int64,unsigned int)>::destroy(void) __ptr64 */

void __thiscall
wistd::__function::
__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
::destroy(__func<<lambda_8db0ce862824541f40dfb767113f1e28>,bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
          *this)

{
  return;
}



===== push_back @ 18001672c =====

/* public: bool __cdecl wil::details_abi::heap_buffer::push_back(void const * __ptr64,unsigned
   __int64) __ptr64 */

bool __thiscall
wil::details_abi::heap_buffer::push_back(heap_buffer *this,void *param_1,__uint64 param_2)

{
  void *_Dst;
  ulonglong uVar1;
  bool bVar2;
  __uint64 _Var3;
  
  if ((ulonglong)(*(longlong *)(this + 0x10) - *(longlong *)this) <=
      (*(longlong *)(this + 8) - *(longlong *)this) + param_2) {
    uVar1 = (*(longlong *)(this + 0x10) - *(longlong *)this) * 2;
    _Var3 = param_2;
    if (param_2 < uVar1) {
      _Var3 = uVar1;
    }
    bVar2 = reserve(this,_Var3);
    if (!bVar2) {
      return bVar2;
    }
  }
  _Dst = *(void **)(this + 8);
  memcpy_s(_Dst,-(ulonglong)(_Dst < *(void **)(this + 0x10)) &
                *(longlong *)(this + 0x10) - (longlong)_Dst,param_1,param_2);
  *(__uint64 *)(this + 8) = *(longlong *)(this + 8) + param_2;
  return true;
}



===== replace @ 1800167d0 =====

/* public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __ptr64 __cdecl std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::replace(unsigned
   __int64,unsigned __int64,class std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> > const & __ptr64) __ptr64 */

basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
* __thiscall
std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
replace(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
        *this,__uint64 param_1,__uint64 param_2,
       basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       *param_3)

{
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *_Src;
  ulonglong uVar1;
  ulonglong uVar2;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *pbVar3;
  basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  *_Src_00;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar1 = *(ulonglong *)(param_3 + 0x10);
  _Src_00 = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
             *)param_3;
  if (7 < *(ulonglong *)(param_3 + 0x18)) {
    _Src_00 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                **)param_3;
  }
  uVar6 = *(ulonglong *)(this + 0x10);
  if (uVar6 < param_2) {
    param_2 = uVar6;
  }
  if (param_2 == uVar1) {
    pbVar3 = this;
    if (7 < *(ulonglong *)(this + 0x18)) {
      pbVar3 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 **)this;
    }
    memmove(pbVar3,_Src_00,uVar1 * 2);
  }
  else {
    uVar2 = *(ulonglong *)(this + 0x18);
    lVar4 = uVar6 - param_2;
    if (uVar1 < param_2) {
      pbVar3 = this;
      if (7 < uVar2) {
        pbVar3 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                   **)this;
      }
      memmove(pbVar3,_Src_00,uVar1 * 2);
      memmove(pbVar3 + uVar1 * 2,pbVar3 + param_2 * 2,lVar4 * 2 + 2);
      *(ulonglong *)(this + 0x10) = (uVar1 - param_2) + uVar6;
    }
    else {
      uVar5 = uVar1 - param_2;
      if (uVar2 - uVar6 < uVar5) {
        this = (basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)_Reallocate_grow_by<<lambda_f68dc91b63048d8e897893337fb617c1>,unsigned___int64,unsigned___int64,unsigned_short_const*___ptr64,unsigned___int64>
                            (this,uVar5,lVar4,param_3,param_2,_Src_00,uVar1);
      }
      else {
        *(ulonglong *)(this + 0x10) = uVar6 + uVar5;
        pbVar3 = this;
        if (7 < uVar2) {
          pbVar3 = *(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                     **)this;
        }
        _Src = pbVar3 + param_2 * 2;
        if ((pbVar3 < _Src_00 + uVar1 * 2) && (_Src_00 <= pbVar3 + uVar6 * 2)) {
          if (_Src_00 < _Src) {
            uVar6 = (longlong)_Src - (longlong)_Src_00 >> 1;
          }
          else {
            uVar6 = 0;
          }
        }
        else {
          uVar6 = uVar1;
        }
        memmove(_Src + uVar5 * 2,_Src,lVar4 * 2 + 2);
        memmove(pbVar3,_Src_00,uVar6 * 2);
        memcpy(pbVar3 + uVar6 * 2,_Src_00 + (uVar6 + uVar5) * 2,(uVar1 - uVar6) * 2);
      }
    }
  }
  return (basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
          *)this;
}



===== reserve @ 180016964 =====

/* public: bool __cdecl wil::details_abi::heap_buffer::reserve(unsigned __int64) __ptr64 */

bool __thiscall wil::details_abi::heap_buffer::reserve(heap_buffer *this,__uint64 param_1)

{
  longlong lVar1;
  longlong lVar2;
  LPVOID lpMem;
  DWORD dwErrCode;
  void *_Dst;
  HANDLE hHeap;
  __uint64 _DstSize;
  
  if ((ulonglong)(*(longlong *)(this + 0x10) - *(longlong *)this) < param_1) {
    dwErrCode = GetLastError();
    _DstSize = (param_1 & 0xffffffffffffffc0) + 0x40;
    _Dst = details::ProcessHeapAlloc(0,_DstSize);
    if (_Dst == (void *)0x0) {
      SetLastError(dwErrCode);
      return false;
    }
    lVar1 = *(longlong *)(this + 8);
    lVar2 = *(longlong *)this;
    memcpy_s(_Dst,_DstSize,*(void **)this,lVar1 - lVar2);
    lpMem = *(LPVOID *)(this + 0x18);
    *(void **)(this + 0x18) = _Dst;
    if (lpMem != (LPVOID)0x0) {
      hHeap = GetProcessHeap();
      HeapFree(hHeap,0,lpMem);
    }
    *(void **)this = _Dst;
    *(longlong *)(this + 8) = (lVar1 - lVar2) + (longlong)_Dst;
    *(__uint64 *)(this + 0x10) = (longlong)_Dst + _DstSize;
    SetLastError(dwErrCode);
  }
  return true;
}



===== reset @ 180016a54 =====

/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   _TP_TIMER * __ptr64,void (__cdecl*)(struct _TP_TIMER * __ptr64),&public: static void __cdecl
   wil::details::DestroyThreadPoolTimer<struct
   wil::details::SystemThreadPoolMethods,0>::Destroy(struct _TP_TIMER * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,struct _TP_TIMER * __ptr64,struct _TP_TIMER *
   __ptr64,0,std::nullptr_t> >::reset(struct _TP_TIMER * __ptr64) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
::reset(unique_storage<wil::details::resource_policy<_TP_TIMER*___ptr64,void_(__cdecl*)(_TP_TIMER*___ptr64),&public:_static_void___cdecl_wil::details::DestroyThreadPoolTimer<struct_wil::details::SystemThreadPoolMethods,0>::Destroy(struct__TP_TIMER*___ptr64),wistd::integral_constant<unsigned___int64,0>,_TP_TIMER*___ptr64,_TP_TIMER*___ptr64,0,std::nullptr_t>_>
        *this,_TP_TIMER *param_1)

{
  PTP_TIMER pti;
  DWORD dwErrCode;
  
  pti = *(PTP_TIMER *)this;
  if (pti != (PTP_TIMER)0x0) {
    dwErrCode = GetLastError();
    SetThreadpoolTimer(pti,(PFILETIME)0x0,0,0);
    WaitForThreadpoolTimerCallbacks(pti,1);
    CloseThreadpoolTimer(pti);
    SetLastError(dwErrCode);
  }
  *(_TP_TIMER **)this = param_1;
  return;
}



===== what @ 180016af0 =====

/* public: virtual char const * __ptr64 __cdecl std::bad_optional_access::what(void)const __ptr64 */

char * __thiscall std::bad_optional_access::what(bad_optional_access *this)

{
  return "Bad optional access";
}



===== wil_details_WriteSRUMWnfUsageBuffer @ 180016b00 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl wil_details_WriteSRUMWnfUsageBuffer(class wil::details_abi::heap_vector<struct
   wil_details_FeatureUsageSRUM> * __ptr64) */

long __cdecl wil_details_WriteSRUMWnfUsageBuffer(heap_vector<wil_details_FeatureUsageSRUM> *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  INT_PTR IVar4;
  ulonglong uVar5;
  int *piVar6;
  undefined8 uVar7;
  int iVar8;
  long lVar9;
  undefined8 uVar10;
  int *piVar11;
  ulonglong uVar12;
  undefined1 auStackY_1078 [32];
  int *piVar13;
  uint local_1038;
  undefined4 local_1034 [3];
  int local_1028 [1024];
  ulonglong local_28;
  undefined8 local_20;
  
  local_20 = 0x180016b25;
  local_28 = __security_cookie ^ (ulonglong)auStackY_1078;
  iVar3 = 0;
  uVar5 = 0;
  lVar9 = 0;
  if (0xb < (ulonglong)(*(longlong *)(param_1 + 8) - *(longlong *)param_1)) {
    iVar8 = 0;
    do {
      uVar7 = 0;
      uVar10 = 0x1000;
      memset(local_1028,0,0x1000);
      local_1034[0] = 0;
      piVar13 = local_1028;
      local_1038 = 0x1000;
      IVar4 = wil_details_NtQueryWnfStateData
                        (&__WIL_WNF_WIL_FEATURE_USAGE_FOR_SRUM,uVar7,uVar10,local_1034,piVar13,
                         &local_1038);
      iVar3 = (int)IVar4;
      if (iVar3 == 0) {
        uVar5 = (ulonglong)local_1038;
        if (uVar5 != (uVar5 / 0xc) * 0xc) {
          uVar5 = 0;
          local_1038 = 0;
        }
        piVar11 = *(int **)param_1;
        uVar12 = uVar5 / 0xc;
        piVar1 = piVar11 + ((ulonglong)(*(longlong *)(param_1 + 8) - (longlong)piVar11) / 0xc) * 3;
        while( true ) {
          if (piVar11 == piVar1) break;
          piVar2 = local_1028 + uVar12 * 3;
          piVar6 = local_1028;
          if (local_1028 != piVar2) {
            do {
              if ((*piVar6 == *piVar11) && ((short)piVar6[1] == (short)piVar11[1])) {
                piVar6[2] = piVar6[2] + piVar11[2];
                uVar5 = (ulonglong)local_1038;
                goto LAB_180016c62;
              }
              piVar6 = piVar6 + 3;
            } while (piVar6 != piVar2);
          }
          if (uVar5 + 0xc < 0x1001) {
            local_1038 = (uint)uVar5 + 0xc;
            uVar5 = (ulonglong)local_1038;
            *(undefined8 *)piVar2 = *(undefined8 *)piVar11;
            local_1028[uVar12 * 3 + 2] = piVar11[2];
            uVar12 = (ulonglong)((int)uVar12 + 1);
          }
LAB_180016c62:
          piVar11 = piVar11 + 3;
        }
        uVar5 = wil_details_NtUpdateWnfStateData
                          (&__WIL_WNF_WIL_FEATURE_USAGE_FOR_SRUM,local_1028,(uint)uVar5,uVar5,
                           piVar13,local_1034[0],1);
        uVar5 = uVar5 & 0xffffffff;
      }
      iVar8 = iVar8 + 1;
      lVar9 = (long)uVar5;
    } while (((lVar9 == -0x3fffffff) && (iVar8 < 100)) && (iVar3 == 0));
  }
  if (iVar3 == 0) {
    iVar3 = lVar9;
  }
  return iVar3;
}



===== wil_details_NtQueryWnfStateData @ 180016cf4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

INT_PTR wil_details_NtQueryWnfStateData
                  (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6)

{
  INT_PTR IVar1;
  
  if (g_wil_details_pfnNtQueryWnfStateData == (FARPROC)0x0) {
    if (`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
        wil_details_ntdllModuleHandle == (HINSTANCE__ *)0x0) {
      `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
      wil_details_ntdllModuleHandle = GetModuleHandleW(L"ntdll.dll");
    }
    g_wil_details_pfnNtQueryWnfStateData =
         GetProcAddress(`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'
                        ::__l2::wil_details_ntdllModuleHandle,"NtQueryWnfStateData");
    if (g_wil_details_pfnNtQueryWnfStateData == (FARPROC)0x0) {
      return 0xc0000139;
    }
  }
  IVar1 = (*g_wil_details_pfnNtQueryWnfStateData)(param_1,0,0,param_4,param_5,param_6);
  return IVar1;
}



===== wil_details_NtUpdateWnfStateData @ 180016d9c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

INT_PTR wil_details_NtUpdateWnfStateData
                  (undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4,
                  undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  INT_PTR IVar1;
  
  if (g_wil_details_pfnNtUpdateWnfStateData == (FARPROC)0x0) {
    if (`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
        wil_details_ntdllModuleHandle == (HINSTANCE__ *)0x0) {
      `struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'::__l2::
      wil_details_ntdllModuleHandle = GetModuleHandleW(L"ntdll.dll");
    }
    g_wil_details_pfnNtUpdateWnfStateData =
         GetProcAddress(`struct_HINSTANCE__*___ptr64___cdecl_wil_details_GetNtDllModuleHandle(void)'
                        ::__l2::wil_details_ntdllModuleHandle,"NtUpdateWnfStateData");
    if (g_wil_details_pfnNtUpdateWnfStateData == (FARPROC)0x0) {
      return 0xc0000139;
    }
  }
  IVar1 = (*g_wil_details_pfnNtUpdateWnfStateData)(param_1,param_2,param_3,0,0,param_6,param_7);
  return IVar1;
}



===== __GSHandlerCheck_EH4 @ 180016e58 =====

void __GSHandlerCheck_EH4(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_4 + 0x38);
  __GSHandlerCheckCommon(param_2,param_4);
  if ((*(uint *)(lVar1 + 4) & ((*(uint *)(param_1 + 4) & 0x66) != 0) + 1) != 0) {
    __CxxFrameHandler4(param_1,param_2,param_3,param_4);
  }
  return;
}



===== __chkstk @ 180016ef0 =====

/* WARNING: This is an inlined function */

void __chkstk(void)

{
  undefined1 *in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 local_res8 [32];
  
  puVar1 = local_res8 + -(longlong)in_RAX;
  if (local_res8 < in_RAX) {
    puVar1 = (undefined1 *)0x0;
  }
  if (puVar1 < StackLimit) {
    puVar2 = StackLimit;
    do {
      puVar2 = puVar2 + -0x1000;
      *puVar2 = 0;
    } while ((undefined1 *)((ulonglong)puVar1 & 0xfffffffffffff000) != puVar2);
  }
  return;
}



===== memcmp @ 180016f44 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180016f44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  return iVar1;
}



===== memcpy @ 180016f50 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180016f50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== memmove @ 180016f5c =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180016f5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



===== _guard_dispatch_icall @ 180016f90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 180016fb0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180016fb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 180016fd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== fin$0 @ 180016fdc =====

void `dllmain_crt_process_attach'::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x40));
  return;
}



===== fin$0 @ 180016ff9 =====

void `dllmain_crt_process_detach'::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  __scrt_release_startup_lock(*(char *)(param_2 + 0x20));
  return;
}



===== fin$1 @ 180017012 =====

void `dllmain_crt_process_detach'::__l1::fin_1(void)

{
  __scrt_dllmain_uninitialize_critical();
  return;
}



===== filt$0 @ 18001702c =====

void `dllmain_dispatch'::__l1::filt_0(undefined8 *param_1,longlong param_2)

{
  __scrt_dllmain_exception_filter
            (*(undefined8 *)(param_2 + 0x60),*(int *)(param_2 + 0x68),
             *(undefined8 *)(param_2 + 0x70),dllmain_crt_dispatch,*(undefined4 *)*param_1,param_1);
  return;
}



===== __scrt_is_nonwritable_in_current_image$filt$0 @ 180017068 =====

bool __scrt_is_nonwritable_in_current_image_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== fin$0 @ 180017086 =====

void ``eh_vector_destructor_iterator''::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x20) == '\0') {
    __ArrayUnwind(*(void **)(param_2 + 0x60),*(__uint64 *)(param_2 + 0x68),
                  *(__uint64 *)(param_2 + 0x70),*(_func_void_void_ptr **)(param_2 + 0x78));
  }
  return;
}



===== filt$0 @ 1800170b8 =====

ulonglong `__ArrayUnwind'::__l1::filt_0(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  
  *(undefined8 *)(param_2 + 0x40) = param_1;
  *(undefined8 *)(param_2 + 0x30) = param_1;
  *(undefined8 *)(param_2 + 0x28) = **(undefined8 **)(param_2 + 0x30);
  if (**(int **)(param_2 + 0x28) == -0x1f928c9d) {
    puVar2 = (undefined8 *)__current_exception();
    *puVar2 = *(undefined8 *)(param_2 + 0x28);
    uVar1 = *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 8);
    puVar2 = (undefined8 *)__current_exception_context();
    *puVar2 = uVar1;
    uVar3 = terminate();
  }
  else {
    *(undefined4 *)(param_2 + 0x20) = 0;
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x20);
  }
  return uVar3;
}



===== catch$0 @ 18001711d =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8
`wil::details::RecognizeCaughtExceptionFromCallback'::__l1::catch_0
          (undefined8 param_1,longlong param_2)

{
  ushort *puVar1;
  int iVar2;
  undefined8 uVar3;
  
  puVar1 = *(ushort **)(param_2 + 0x40);
  if (puVar1 != (ushort *)0x0) {
    uVar3 = (**(code **)(**(longlong **)(param_2 + 0x20) + 8))();
    StringCchPrintfW(puVar1,*(__uint64 *)(param_2 + 0x48),(ushort *)L"std::exception: %hs",uVar3);
  }
  iVar2 = *(int *)(param_2 + 0x50);
  if (-1 < iVar2) {
    iVar2 = -0x7ff8fdc2;
  }
  *(int *)(param_2 + 0x50) = iVar2;
  return 0;
}



===== catch$1 @ 180017182 =====

undefined8 `wil::details::RecognizeCaughtExceptionFromCallback'::__l1::catch_1(void)

{
  return 0;
}



===== catch$0 @ 1800171a6 =====

undefined8
`wil::details::ResultFromCaughtExceptionInternal'::__l1::catch_0
          (undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  **(undefined1 **)(param_2 + 0xa8) = 1;
  lVar1 = *(longlong *)(param_2 + 0x20);
  if (*(ushort **)(param_2 + 0x98) != (ushort *)0x0) {
    wil::GetFailureLogString
              (*(ushort **)(param_2 + 0x98),*(__uint64 *)(param_2 + 0xa0),
               (FailureInfo *)(lVar1 + 0x18));
  }
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(lVar1 + 0x20);
  *(undefined4 *)(param_2 + 0x4c) = *(undefined4 *)(lVar1 + 0x24);
  *(uint *)(param_2 + 0x50) = ((int)*(char *)(lVar1 + 0x1c) & 8U) >> 3;
  return 0;
}



===== catch$1 @ 18001720f =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8
`wil::details::ResultFromCaughtExceptionInternal'::__l1::catch_1
          (undefined8 param_1,longlong param_2)

{
  ushort *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  puVar1 = *(ushort **)(param_2 + 0x98);
  if (puVar1 != (ushort *)0x0) {
    uVar3 = (**(code **)(**(longlong **)(param_2 + 0x30) + 8))();
    StringCchPrintfW(puVar1,*(__uint64 *)(param_2 + 0xa0),(ushort *)L"std::exception: %hs",uVar3);
  }
  *(undefined4 *)(param_2 + 0x48) = 0x8007000e;
  lVar2 = wil::details::HrToNtStatus(-0x7ff8fff2);
  *(long *)(param_2 + 0x4c) = lVar2;
  *(undefined4 *)(param_2 + 0x50) = 0;
  return 0;
}



===== catch$2 @ 180017282 =====

bool `wil::details::ResultFromCaughtExceptionInternal'::__l1::catch_2
               (undefined8 param_1,longlong param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = wil::details::RecognizeCaughtExceptionFromCallback
                    (*(ushort **)(param_2 + 0x98),*(__uint64 *)(param_2 + 0xa0));
  if (-1 >= lVar1) {
    *(long *)(param_2 + 0x48) = lVar1;
    lVar2 = wil::details::HrToNtStatus(lVar1);
    *(long *)(param_2 + 0x4c) = lVar2;
    *(undefined4 *)(param_2 + 0x50) = 0;
  }
  return -1 < lVar1;
}



===== catch$3 @ 1800172da =====

undefined8
`wil::details::ResultFromCaughtExceptionInternal'::__l1::catch_3
          (undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  **(undefined1 **)(param_2 + 0xa8) = 1;
  lVar1 = *(longlong *)(param_2 + 0x28);
  if (*(ushort **)(param_2 + 0x98) != (ushort *)0x0) {
    wil::GetFailureLogString
              (*(ushort **)(param_2 + 0x98),*(__uint64 *)(param_2 + 0xa0),
               (FailureInfo *)(lVar1 + 0x18));
  }
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(lVar1 + 0x20);
  *(undefined4 *)(param_2 + 0x4c) = *(undefined4 *)(lVar1 + 0x24);
  *(uint *)(param_2 + 0x50) = ((int)*(char *)(lVar1 + 0x1c) & 8U) >> 3;
  return 0;
}



===== catch$4 @ 180017343 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8
`wil::details::ResultFromCaughtExceptionInternal'::__l1::catch_4
          (undefined8 param_1,longlong param_2)

{
  ushort *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  puVar1 = *(ushort **)(param_2 + 0x98);
  if (puVar1 != (ushort *)0x0) {
    uVar3 = (**(code **)(**(longlong **)(param_2 + 0x38) + 8))();
    StringCchPrintfW(puVar1,*(__uint64 *)(param_2 + 0xa0),(ushort *)L"std::exception: %hs",uVar3);
  }
  *(undefined4 *)(param_2 + 0x48) = 0x8007000e;
  lVar2 = wil::details::HrToNtStatus(-0x7ff8fff2);
  *(long *)(param_2 + 0x4c) = lVar2;
  *(undefined4 *)(param_2 + 0x50) = 0;
  return 0;
}



===== catch$5 @ 1800173b6 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8
`wil::details::ResultFromCaughtExceptionInternal'::__l1::catch_5
          (undefined8 param_1,longlong param_2)

{
  ushort *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  puVar1 = *(ushort **)(param_2 + 0x98);
  if (puVar1 != (ushort *)0x0) {
    uVar3 = (**(code **)(**(longlong **)(param_2 + 0x40) + 8))();
    StringCchPrintfW(puVar1,*(__uint64 *)(param_2 + 0xa0),(ushort *)L"std::exception: %hs",uVar3);
  }
  *(undefined4 *)(param_2 + 0x48) = 0x8007023e;
  lVar2 = wil::details::HrToNtStatus(-0x7ff8fdc2);
  *(long *)(param_2 + 0x4c) = lVar2;
  *(undefined4 *)(param_2 + 0x50) = 0;
  return 0;
}



===== catch$6 @ 180017429 =====

undefined8 `wil::details::ResultFromCaughtExceptionInternal'::__l1::catch_6(void)

{
  return 0;
}



===== catch$0 @ 18001744d =====

undefined8 `PktmonAddFilter'::__l1::catch_0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0x38) + 0x20);
  if (((int)uVar1 < 0) && ((uVar1 & 0x1fff0000) == 0x70000)) {
    *(uint *)(param_2 + 0x30) = uVar1 & 0xffff;
  }
  else {
    *(uint *)(param_2 + 0x30) = uVar1;
  }
  return 0;
}



===== dtor$0 @ 180017495 =====

void `PktmonGetComponentList'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::vector<unsigned_char,std::allocator<unsigned_char>_>::
  ~vector<unsigned_char,std::allocator<unsigned_char>_>
            ((vector<unsigned_char,std::allocator<unsigned_char>_> *)(param_2 + 0x38));
  return;
}



===== catch$2 @ 1800174a7 =====

undefined8 `PktmonGetComponentList'::__l1::catch_2(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0x30) + 0x20);
  if (((int)uVar1 < 0) && ((uVar1 & 0x1fff0000) == 0x70000)) {
    *(uint *)(param_2 + 0x78) = uVar1 & 0xffff;
  }
  else {
    *(uint *)(param_2 + 0x78) = uVar1;
  }
  return 0;
}



===== catch$3 @ 1800174ef =====

undefined8 `PktmonGetComponentList'::__l1::catch_3(void)

{
  return 0;
}



===== catch$0 @ 180017513 =====

undefined8 `PktmonRemoveAllFilters'::__l1::catch_0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0x30) + 0x20);
  if (((int)uVar1 < 0) && ((uVar1 & 0x1fff0000) == 0x70000)) {
    *(uint *)(param_2 + 0x50) = uVar1 & 0xffff;
  }
  else {
    *(uint *)(param_2 + 0x50) = uVar1;
  }
  return 0;
}



===== catch$2 @ 18001755b =====

undefined8 `PktmonStart'::__l1::catch_2(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0x30) + 0x20);
  if (((int)uVar1 < 0) && ((uVar1 & 0x1fff0000) == 0x70000)) {
    *(uint *)(param_2 + 0x70) = uVar1 & 0xffff;
  }
  else {
    *(uint *)(param_2 + 0x70) = uVar1;
  }
  return 0;
}



===== dtor$0 @ 1800175a3 =====

void `PktmonUnload'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  wil::
  unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
  ::
  ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
            ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
              *)(param_2 + 0x30));
  return;
}



===== dtor$1 @ 1800175b5 =====

void `PktmonUnload'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  wil::
  unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
  ::
  ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
            ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
              *)(param_2 + 0x38));
  return;
}



===== catch$10 @ 1800175c7 =====

undefined8 `PktmonUnload'::__l1::catch_10(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0x40) + 0x20);
  if (((int)uVar1 < 0) && ((uVar1 & 0x1fff0000) == 0x70000)) {
    *(uint *)(param_2 + 0x30) = uVar1 & 0xffff;
  }
  else {
    *(uint *)(param_2 + 0x30) = uVar1;
  }
  return 0;
}



===== dtor$0 @ 18001760f =====

void `PktMon::DriverInterface::GetBytesNeeded'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  wil::
  unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
  ::
  ~unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
            ((unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
              *)(param_2 + 0x60));
  return;
}



===== dtor$0 @ 180017621 =====

void `PktMon::DriverInterface::GetHandle'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x60) & 1) != 0) {
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffffe;
    wil::
    unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
    ::
    ~unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
              (*(unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
                 **)(param_2 + 0x68));
  }
  return;
}



===== dtor$0 @ 18001764e =====

void `PktMon::DriverInterface::SendIoCtl'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  wil::
  unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
  ::
  ~unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
            ((unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
              *)(param_2 + 0x50));
  return;
}



===== dtor$0 @ 180017660 =====

void `PktMon::DriverInterface::StartDriverService'::__l1::dtor_0
               (undefined8 param_1,longlong param_2)

{
  wil::
  unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
  ::
  ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
            ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
              *)(param_2 + 0x40));
  return;
}



===== dtor$1 @ 180017672 =====

void `PktMon::DriverInterface::StartDriverService'::__l1::dtor_1
               (undefined8 param_1,longlong param_2)

{
  wil::
  unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
  ::
  ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
            ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<SC_HANDLE__*___ptr64,int_(__cdecl*)(SC_HANDLE__*___ptr64),&int___cdecl_CloseServiceHandle(struct_SC_HANDLE__*___ptr64),wistd::integral_constant<unsigned___int64,0>,SC_HANDLE__*___ptr64,SC_HANDLE__*___ptr64,0,std::nullptr_t>_>_>
              *)(param_2 + 0x48));
  return;
}



===== PacketMonitorAddCaptureConstraint$catch$0 @ 180017684 =====

undefined8
PacketMonitorAddCaptureConstraint_catch_0(undefined8 param_1,longlong param_2,char *param_3)

{
  long lVar1;
  
  lVar1 = wil::details::in1diag3::Return_CaughtException(*(void **)(param_2 + 0x148),0xd8,param_3);
  *(long *)(param_2 + 0x40) = lVar1;
  return 0;
}



===== PacketMonitorAddSingleDataSourceToSession$dtor$0 @ 1800176bc =====

void PacketMonitorAddSingleDataSourceToSession_dtor_0(undefined8 param_1,longlong param_2)

{
  std::vector<unsigned_char,std::allocator<unsigned_char>_>::
  ~vector<unsigned_char,std::allocator<unsigned_char>_>
            ((vector<unsigned_char,std::allocator<unsigned_char>_> *)(param_2 + 0x58));
  return;
}



===== PacketMonitorAddSingleDataSourceToSession$dtor$1 @ 1800176ce =====

void PacketMonitorAddSingleDataSourceToSession_dtor_1(undefined8 param_1,longlong param_2)

{
  DataSourceList::~DataSourceList((DataSourceList *)(param_2 + 0x98));
  return;
}



===== PacketMonitorAddSingleDataSourceToSession$dtor$2 @ 1800176e0 =====

void PacketMonitorAddSingleDataSourceToSession_dtor_2(undefined8 param_1,longlong param_2)

{
  std::vector<int,std::allocator<int>_>::~vector<int,std::allocator<int>_>
            ((vector<int,std::allocator<int>_> *)(param_2 + 0x40));
  return;
}



===== PacketMonitorAddSingleDataSourceToSession$catch$3 @ 1800176f2 =====

undefined8
PacketMonitorAddSingleDataSourceToSession_catch_3(undefined8 param_1,longlong param_2,char *param_3)

{
  long lVar1;
  
  lVar1 = wil::details::in1diag3::Return_CaughtException(*(void **)(param_2 + 0x88),0xbf,param_3);
  *(long *)(param_2 + 0x90) = lVar1;
  return 0;
}



===== PacketMonitorAttachOutputToSession$catch$0 @ 18001772d =====

undefined8
PacketMonitorAttachOutputToSession_catch_0(undefined8 param_1,longlong param_2,char *param_3)

{
  long lVar1;
  
  lVar1 = wil::details::in1diag3::Return_CaughtException(*(void **)(param_2 + 0x88),0x103,param_3);
  *(long *)(param_2 + 0x90) = lVar1;
  return 0;
}



===== PacketMonitorCloseRealtimeStream$catch$0 @ 180017768 =====

void PacketMonitorCloseRealtimeStream_catch_0(undefined8 param_1,longlong param_2,char *param_3)

{
                    /* WARNING: Subroutine does not return */
  wil::details::in1diag3::FailFast_CaughtException(*(void **)(param_2 + 0x28),0xf5,param_3);
}



===== PacketMonitorCloseSessionHandle$catch$0 @ 18001778a =====

void PacketMonitorCloseSessionHandle_catch_0(undefined8 param_1,longlong param_2,char *param_3)

{
                    /* WARNING: Subroutine does not return */
  wil::details::in1diag3::FailFast_CaughtException(*(void **)(param_2 + 0x28),0x7f,param_3);
}



===== PacketMonitorCreateLiveSession$catch$1 @ 1800177ac =====

undefined8 PacketMonitorCreateLiveSession_catch_1(undefined8 param_1,longlong param_2,char *param_3)

{
  long lVar1;
  
  lVar1 = wil::details::in1diag3::Return_CaughtException(*(void **)(param_2 + 0x488),0x77,param_3);
  *(long *)(param_2 + 0x40) = lVar1;
  return 0;
}



===== PacketMonitorCreateRealtimeStream$dtor$0 @ 1800177e4 =====

void PacketMonitorCreateRealtimeStream_dtor_0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x30),0x90);
  return;
}



===== PacketMonitorCreateRealtimeStream$catch$1 @ 180017808 =====

undefined8
PacketMonitorCreateRealtimeStream_catch_1(undefined8 param_1,longlong param_2,char *param_3)

{
  long lVar1;
  
  lVar1 = wil::details::in1diag3::Return_CaughtException(*(void **)(param_2 + 0x28),0xea,param_3);
  *(long *)(param_2 + 0x30) = lVar1;
  return 0;
}



===== PacketMonitorEnumDataSources$catch$0 @ 18001783d =====

undefined8 PacketMonitorEnumDataSources_catch_0(undefined8 param_1,longlong param_2,char *param_3)

{
  long lVar1;
  
  lVar1 = wil::details::in1diag3::Return_CaughtException(*(void **)(param_2 + 0x38),0xb4,param_3);
  *(long *)(param_2 + 0x60) = lVar1;
  return 0;
}



===== PacketMonitorInitialize$dtor$0 @ 180017872 =====

void PacketMonitorInitialize_dtor_0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x38),0x20);
  return;
}



===== PacketMonitorInitialize$catch$1 @ 180017896 =====

undefined8 PacketMonitorInitialize_catch_1(undefined8 param_1,longlong param_2,char *param_3)

{
  long lVar1;
  
  lVar1 = wil::details::in1diag3::Return_CaughtException(*(void **)(param_2 + 0x28),0x35,param_3);
  *(long *)(param_2 + 0x30) = lVar1;
  return 0;
}



===== PacketMonitorSetSessionActive$catch$0 @ 1800178cb =====

undefined8 PacketMonitorSetSessionActive_catch_0(undefined8 param_1,longlong param_2,char *param_3)

{
  long lVar1;
  
  lVar1 = wil::details::in1diag3::Return_CaughtException(*(void **)(param_2 + 0x28),0x92,param_3);
  *(long *)(param_2 + 0x38) = lVar1;
  return 0;
}



===== PacketMonitorUninitialize$catch$0 @ 180017900 =====

void PacketMonitorUninitialize_catch_0(undefined8 param_1,longlong param_2,char *param_3)

{
                    /* WARNING: Subroutine does not return */
  wil::details::in1diag3::FailFast_CaughtException(*(void **)(param_2 + 0x28),0x3d,param_3);
}



===== catch$0 @ 180017922 =====

void `std::vector<unsigned_char,std::allocator<unsigned_char>_>::_Reallocate<0>'::__l1::catch_0
               (allocator<unsigned_char> *param_1,longlong param_2)

{
  std::allocator<unsigned_char>::deallocate
            (param_1,*(uchar **)(param_2 + 0x40),**(__uint64 **)(param_2 + 0x48));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 18001794f =====

void `std::vector<unsigned_char,std::allocator<unsigned_char>_>::
     _Resize_reallocate<std::_Value_init_tag>'::__l1::catch_0
               (allocator<unsigned_char> *param_1,longlong param_2)

{
  std::allocator<unsigned_char>::deallocate
            (param_1,*(uchar **)(param_2 + 0x48),*(__uint64 *)(param_2 + 0x50));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== dtor$0 @ 180017979 =====

void `PacketMonitorApiHandle::PacketMonitorApiHandle'::__l1::dtor_0
               (undefined8 param_1,longlong param_2)

{
  PacketMonitorObjectBase<102>::~PacketMonitorObjectBase<102>
            (*(PacketMonitorObjectBase<102> **)(param_2 + 0x60));
  return;
}



===== dtor$1 @ 18001798b =====

void `PacketMonitorApiHandle::PacketMonitorApiHandle'::__l1::dtor_1
               (undefined8 param_1,longlong param_2)

{
  wil::
  unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
  ::
  ~unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
            ((unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
              *)(*(longlong *)(param_2 + 0x60) + 0x10));
  return;
}



===== dtor$0 @ 1800179a1 =====

void `PacketMonitorApiHandle::EnumDataSources'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  DataSourceList::~DataSourceList((DataSourceList *)(param_2 + 0x20));
  return;
}



===== dtor$1 @ 1800179b3 =====

void `PacketMonitorApiHandle::EnumDataSources'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  std::
  vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
  ::
  ~vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
            ((vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
              *)(param_2 + 0x28));
  return;
}



===== dtor$0 @ 1800179c5 =====

void `PacketMonitorApiHandle::GetDataSourceList'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::vector<unsigned_char,std::allocator<unsigned_char>_>::
  ~vector<unsigned_char,std::allocator<unsigned_char>_>
            ((vector<unsigned_char,std::allocator<unsigned_char>_> *)(param_2 + 0x48));
  return;
}



===== dtor$2 @ 1800179d7 =====

void `PacketMonitorApiHandle::GetDataSourceList'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0xa8),0x88);
  return;
}



===== dtor$0 @ 1800179fe =====

void `PacketMonitorApiHandle::SetSessionActive'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::vector<unsigned_char,std::allocator<unsigned_char>_>::
  ~vector<unsigned_char,std::allocator<unsigned_char>_>
            ((vector<unsigned_char,std::allocator<unsigned_char>_> *)(param_2 + 0x40));
  return;
}



===== catch$0 @ 180017a10 =====

void `std::vector<unsigned_short,std::allocator<unsigned_short>_>::
     _Emplace_reallocate<unsigned_short_&>'::__l1::catch_0
               (allocator<unsigned_short> *param_1,longlong param_2)

{
  std::allocator<unsigned_short>::deallocate
            (param_1,*(ushort **)(param_2 + 0x68),*(__uint64 *)(param_2 + 0x60));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 180017a3a =====

void `std::vector<PacketMonitorStream_*,std::allocator<PacketMonitorStream_*>_>::
     _Emplace_reallocate<PacketMonitorStream_*_&>'::__l1::catch_0
               (allocator<PktMon::GatewayGroup_const*___ptr64> *param_1,longlong param_2)

{
  std::allocator<PktMon::GatewayGroup_const*___ptr64>::deallocate
            (param_1,*(GatewayGroup ***)(param_2 + 0x68),*(__uint64 *)(param_2 + 0x60));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 180017a64 =====

void `std::vector<PacketMonitorStream_*,std::allocator<PacketMonitorStream_*>_>::_Reallocate<0>'::
     __l1::catch_0(allocator<PktMon::GatewayGroup_const*___ptr64> *param_1,longlong param_2)

{
  std::allocator<PktMon::GatewayGroup_const*___ptr64>::deallocate
            (param_1,*(GatewayGroup ***)(param_2 + 0x40),**(__uint64 **)(param_2 + 0x48));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== dtor$0 @ 180017a91 =====

void `PacketMonitorStream::PacketMonitorStream'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  PacketMonitorObjectBase<102>::~PacketMonitorObjectBase<102>
            (*(PacketMonitorObjectBase<102> **)(param_2 + 0x50));
  return;
}



===== dtor$1 @ 180017aa3 =====

void `PacketMonitorStream::PacketMonitorStream'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  wistd::unique_ptr<void,wil::virtualalloc_deleter>::~unique_ptr<void,wil::virtualalloc_deleter>
            ((unique_ptr<void,wil::virtualalloc_deleter> *)(*(longlong *)(param_2 + 0x50) + 0x40));
  return;
}



===== dtor$2 @ 180017ab9 =====

void `PacketMonitorStream::PacketMonitorStream'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  wistd::unique_ptr<void,wil::virtualalloc_deleter>::~unique_ptr<void,wil::virtualalloc_deleter>
            ((unique_ptr<void,wil::virtualalloc_deleter> *)(*(longlong *)(param_2 + 0x50) + 0x48));
  return;
}



===== dtor$3 @ 180017acf =====

void `PacketMonitorStream::PacketMonitorStream'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  wil::
  unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
  ::
  ~unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
            ((unique_any_t<wil::details::unique_storage<wil::details::handle_null_resource_policy<int_(__cdecl*)(void*___ptr64),&int___cdecl_CloseHandle(void*___ptr64)>_>_>
              *)(*(longlong *)(param_2 + 0x50) + 0x88));
  return;
}



===== dtor$0 @ 180017ae8 =====

void `PacketMonitorStream::EventDeliveryThread'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::vector<unsigned_char,std::allocator<unsigned_char>_>::
  ~vector<unsigned_char,std::allocator<unsigned_char>_>
            ((vector<unsigned_char,std::allocator<unsigned_char>_> *)(param_2 + 0x30));
  return;
}



===== catch$0 @ 180017afa =====

void `std::
     vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
     ::_Emplace_reallocate<PACKETMONITOR_DATA_SOURCE_SPECIFICATION_const_&>'::__l1::catch_0
               (allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION> *param_1,longlong param_2)

{
  std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>::deallocate
            (param_1,*(PACKETMONITOR_DATA_SOURCE_SPECIFICATION **)(param_2 + 0x68),
             *(__uint64 *)(param_2 + 0x60));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 180017b24 =====

void `std::vector<int,std::allocator<int>_>::_Emplace_reallocate<int>'::__l1::catch_0
               (allocator<int> *param_1,longlong param_2)

{
  std::allocator<int>::deallocate(param_1,*(int **)(param_2 + 0x68),*(__uint64 *)(param_2 + 0x60));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== dtor$0 @ 180017b4e =====

void `AddComponentAsDataSource'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x30));
  return;
}



===== dtor$1 @ 180017b60 =====

void `AddComponentAsDataSource'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(param_2 + 0x88));
  }
  return;
}



===== dtor$2 @ 180017b90 =====

void `AddComponentAsDataSource'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 2) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffd;
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                *)(param_2 + 0x70));
  }
  return;
}



===== dtor$3 @ 180017bbd =====

void `AddComponentAsDataSource'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x50));
  return;
}



===== dtor$1 @ 180017bcf =====

void `AddNicGroupAsDataSources'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x38));
  return;
}



===== dtor$2 @ 180017be1 =====

void `AddNicGroupAsDataSources'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x20));
  return;
}



===== dtor$0 @ 180017bf3 =====

void `DataSourceList::GetAllDataSources'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
    ::
    ~vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
              (*(vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
                 **)(param_2 + 200));
  }
  return;
}



===== dtor$7 @ 180017c23 =====

void `DataSourceList::GetAllDataSources'::__l1::dtor_7(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x60));
  return;
}



===== dtor$5 @ 180017c35 =====

void `DataSourceList::GetAllDataSources'::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x48));
  return;
}



===== dtor$0 @ 180017c47 =====

void `DataSourceList::GetNetworkAdapters'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
    ::
    ~vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
              (*(vector<PACKETMONITOR_DATA_SOURCE_SPECIFICATION,std::allocator<PACKETMONITOR_DATA_SOURCE_SPECIFICATION>_>
                 **)(param_2 + 0xa8));
  }
  return;
}



===== dtor$0 @ 180017c77 =====

void `DataSourceList::NormalizeAndValidateSelection'::__l1::dtor_0
               (undefined8 param_1,longlong param_2)

{
  std::vector<int,std::allocator<int>_>::~vector<int,std::allocator<int>_>
            ((vector<int,std::allocator<int>_> *)(param_2 + 0x38));
  return;
}



===== dtor$1 @ 180017c89 =====

void `DataSourceList::NormalizeAndValidateSelection'::__l1::dtor_1
               (undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::vector<int,std::allocator<int>_>::~vector<int,std::allocator<int>_>
              (*(vector<int,std::allocator<int>_> **)(param_2 + 0x88));
  }
  return;
}



===== dtor$2 @ 180017cb9 =====

void `DataSourceList::NormalizeAndValidateSelection'::__l1::dtor_2
               (undefined8 param_1,longlong param_2)

{
  std::set<long,std::less<long>,std::allocator<long>_>::
  ~set<long,std::less<long>,std::allocator<long>_>
            ((set<long,std::less<long>,std::allocator<long>_> *)(param_2 + 0x28));
  return;
}



===== dtor$1 @ 180017ccb =====

void `std::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void_*>_>_>
     ::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void_*>_>_><std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<unsigned_long_&>_>'
     ::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  std::
  _Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
  ::
  ~_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
            (*(_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void*___ptr64>_>_>
               **)(param_2 + 0x50));
  return;
}



===== dtor$4 @ 180017cdd =====

void `std::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void_*>_>_>
     ::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void_*>_>_><std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<unsigned_long_&>_>'
     ::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(*(longlong *)(param_2 + 0x78) + 0x20));
  return;
}



===== dtor$5 @ 180017cf3 =====

void `std::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void_*>_>_>
     ::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void_*>_>_><std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<unsigned_long_&>_>'
     ::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(*(longlong *)(param_2 + 0x78) + 0x38));
  return;
}



===== dtor$6 @ 180017d09 =====

void `std::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void_*>_>_>
     ::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::NicGroup>,void_*>_>_><std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<unsigned_long_&>_>'
     ::__l1::dtor_6(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(*(longlong *)(param_2 + 0x78) + 0x50));
  return;
}



===== dtor$1 @ 180017d1f =====

void `std::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void_*>_>_>
     ::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void_*>_>_><std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<unsigned_long_&>_>'
     ::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  std::
  _Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
  ::
  ~_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
            (*(_Tree_temp_node_alloc<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void*___ptr64>_>_>
               **)(param_2 + 0x30));
  return;
}



===== dtor$4 @ 180017d31 =====

void `std::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void_*>_>_>
     ::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void_*>_>_><std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<unsigned_long_&>_>'
     ::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(*(longlong *)(param_2 + 0x58) + 0x10));
  return;
}



===== dtor$5 @ 180017d47 =====

void `std::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void_*>_>_>
     ::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void_*>_>_><std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<unsigned_long_&>_>'
     ::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(*(longlong *)(param_2 + 0x58) + 0x38));
  return;
}



===== dtor$6 @ 180017d5d =====

void `std::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void_*>_>_>
     ::
     _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::VMSwitch>,void_*>_>_><std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<unsigned_long_&>_>'
     ::__l1::dtor_6(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(*(longlong *)(param_2 + 0x58) + 0x50));
  return;
}



===== dtor$0 @ 180017d73 =====

void `NetSetup2::details::GetObjectWithFilter<NetSetup2::NetworkInterface>'::__l1::dtor_0
               (undefined8 param_1,longlong param_2)

{
  NetSetup2::details::AutoFreeObjects::~AutoFreeObjects((AutoFreeObjects *)(param_2 + 0x38));
  return;
}



===== catch$0 @ 180017d85 =====

void `std::vector<PktMon::Component_const_*,std::allocator<PktMon::Component_const_*>_>::
     _Emplace_reallocate<PktMon::Component_const_*_&>'::__l1::catch_0
               (allocator<PktMon::GatewayGroup_const*___ptr64> *param_1,longlong param_2)

{
  std::allocator<PktMon::GatewayGroup_const*___ptr64>::deallocate
            (param_1,*(GatewayGroup ***)(param_2 + 0x58),*(__uint64 *)(param_2 + 0x50));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 180017daf =====

void `std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
     _Emplace_reallocate<PktMon::CounterInfo_&>'::__l1::catch_0
               (allocator<PktMon::CounterInfo> *param_1,longlong param_2)

{
  std::allocator<PktMon::CounterInfo>::deallocate
            (param_1,*(CounterInfo **)(param_2 + 0x58),*(__uint64 *)(param_2 + 0x50));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 180017dd9 =====

void `std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::
     _Emplace_reallocate<_PKTMON_COMPONENT_OUT_const_&>'::__l1::catch_0
               (allocator<PktMon::Component> *param_1,longlong param_2)

{
  std::allocator<PktMon::Component>::deallocate
            (param_1,*(Component **)(param_2 + 0x58),*(__uint64 *)(param_2 + 0x50));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 180017e03 =====

void `std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
     _Emplace_reallocate<PktMon::Component_const_&,unsigned_short_const_(&)[64],_PKTMON_COUNTER_SET_const_&,enum_PktMon::CounterType>'
     ::__l1::catch_0(allocator<PktMon::CounterInfo> *param_1,longlong param_2)

{
  std::allocator<PktMon::CounterInfo>::deallocate
            (param_1,*(CounterInfo **)(param_2 + 0x68),*(__uint64 *)(param_2 + 0x60));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 180017e2d =====

void `std::vector<PktMon::Component_const_*,std::allocator<PktMon::Component_const_*>_>::
     _Insert_counted_range<PktMon::Component_const_*_*>'::__l1::catch_0
               (allocator<PktMon::GatewayGroup_const*___ptr64> *param_1,longlong param_2)

{
  std::allocator<PktMon::GatewayGroup_const*___ptr64>::deallocate
            (param_1,*(GatewayGroup ***)(param_2 + 0x30),*(__uint64 *)(param_2 + 0x88));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$1 @ 180017e5a =====

void `std::vector<PktMon::Component_const_*,std::allocator<PktMon::Component_const_*>_>::
     _Insert_counted_range<PktMon::Component_const_*_*>'::__l1::catch_1
               (undefined8 param_1,longlong param_2)

{
  **(undefined8 **)(param_2 + 0x20) = *(undefined8 *)(param_2 + 0x88);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$2 @ 180017e85 =====

void `std::vector<PktMon::Component_const_*,std::allocator<PktMon::Component_const_*>_>::
     _Insert_counted_range<PktMon::Component_const_*_*>'::__l1::catch_2
               (undefined8 param_1,longlong param_2,undefined8 param_3,
               allocator<PktMon::Component_const*___ptr64> *param_4)

{
  longlong lVar1;
  Component **ppCVar2;
  undefined8 *puVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x98);
  ppCVar2 = *(Component ***)(param_2 + 0x88);
  std::
  _Uninitialized_move<PktMon::Component_const*___ptr64*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
            (ppCVar2 + lVar1,ppCVar2 + lVar1 * 2,ppCVar2,param_4);
  puVar3 = *(undefined8 **)(param_2 + 0x20);
  std::
  _Move_unchecked<PktMon::Component_const*___ptr64*___ptr64,PktMon::Component_const*___ptr64*___ptr64>
            (ppCVar2 + lVar1 * 2,(Component **)*puVar3,ppCVar2 + lVar1);
  *puVar3 = *(undefined8 *)(param_2 + 0x28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$4 @ 180017ee7 =====

void `std::vector<PktMon::Component_const_*,std::allocator<PktMon::Component_const_*>_>::
     _Insert_counted_range<PktMon::Component_const_*_*>'::__l1::catch_4
               (undefined8 param_1,longlong param_2,undefined8 param_3,
               allocator<PktMon::Component_const*___ptr64> *param_4)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_2 + 0x20);
  std::
  _Uninitialized_move<PktMon::Component_const*___ptr64*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
            (*(Component ***)(param_2 + 0x98),(Component **)*puVar1,*(Component ***)(param_2 + 0x88)
             ,param_4);
  *puVar1 = *(undefined8 *)(param_2 + 0x28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 180017f27 =====

void `std::vector<PktMon::CompGroup_const_*,std::allocator<PktMon::CompGroup_const_*>_>::
     _Insert_counted_range<PktMon::GatewayGroup_const_*_*>'::__l1::catch_0
               (allocator<PktMon::GatewayGroup_const*___ptr64> *param_1,longlong param_2)

{
  std::allocator<PktMon::GatewayGroup_const*___ptr64>::deallocate
            (param_1,*(GatewayGroup ***)(param_2 + 0x98),*(__uint64 *)(param_2 + 0x88));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$2 @ 180017f57 =====

void `std::vector<PktMon::CompGroup_const_*,std::allocator<PktMon::CompGroup_const_*>_>::
     _Insert_counted_range<PktMon::GatewayGroup_const_*_*>'::__l1::catch_2
               (undefined8 param_1,longlong param_2,undefined8 param_3,
               allocator<PktMon::Component_const*___ptr64> *param_4)

{
  longlong lVar1;
  Component **ppCVar2;
  undefined8 *puVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x98);
  ppCVar2 = *(Component ***)(param_2 + 0x88);
  std::
  _Uninitialized_move<PktMon::Component_const*___ptr64*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
            (ppCVar2 + lVar1,ppCVar2 + lVar1 * 2,ppCVar2,param_4);
  puVar3 = *(undefined8 **)(param_2 + 0x20);
  std::
  _Move_unchecked<PktMon::Component_const*___ptr64*___ptr64,PktMon::Component_const*___ptr64*___ptr64>
            (ppCVar2 + lVar1 * 2,(Component **)*puVar3,ppCVar2 + lVar1);
  *puVar3 = *(undefined8 *)(param_2 + 0x30);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$4 @ 180017fb9 =====

void `std::vector<PktMon::CompGroup_const_*,std::allocator<PktMon::CompGroup_const_*>_>::
     _Insert_counted_range<PktMon::GatewayGroup_const_*_*>'::__l1::catch_4
               (undefined8 param_1,longlong param_2,undefined8 param_3,
               allocator<PktMon::Component_const*___ptr64> *param_4)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_2 + 0x20);
  std::
  _Uninitialized_move<PktMon::Component_const*___ptr64*___ptr64,std::allocator<PktMon::Component_const*___ptr64>_>
            (*(Component ***)(param_2 + 0x98),(Component **)*puVar1,*(Component ***)(param_2 + 0x88)
             ,param_4);
  *puVar1 = *(undefined8 *)(param_2 + 0x30);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 180017ff9 =====

void `std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::_Reallocate<0>'::__l1::
     catch_0(allocator<PktMon::Component> *param_1,longlong param_2)

{
  std::allocator<PktMon::Component>::deallocate
            (param_1,*(Component **)(param_2 + 0x40),**(__uint64 **)(param_2 + 0x48));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== dtor$2 @ 180018026 =====

void `std::
     map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
     ::try_emplace<unsigned_long_&>'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  std::
  _Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_>
  ::
  ~_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_>
            ((_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<unsigned_long_const_,PktMon::GatewayGroup>,void*___ptr64>_>_>
              *)(param_2 + 0x20));
  return;
}



===== dtor$0 @ 180018038 =====

void `std::
     map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>
     ::
     map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>'
     ::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::
  _Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
  ::
  ~_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
            (*(_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
               **)(param_2 + 0xa0));
  return;
}



===== dtor$1 @ 18001804a =====

void `std::
     map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>
     ::
     map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>'
     ::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  std::
  _Tree_temp_node<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
  ::
  ~_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
            ((_Tree_temp_node<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
              *)(param_2 + 0x20));
  return;
}



===== dtor$3 @ 18001805c =====

void `std::
     map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>
     ::
     map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>'
     ::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  std::
  _Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
  ::
  ~_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
            ((_Alloc_construct_ptr<std::allocator<std::_Tree_node<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>,void*___ptr64>_>_>
              *)(param_2 + 0x20));
  return;
}



===== dtor$4 @ 18001806e =====

void `std::
     map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>
     ::
     map<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>_>_>'
     ::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            (*(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
               **)(param_2 + 0xa8));
  return;
}



===== dtor$0 @ 180018080 =====

void `PktMon::CompList::CompList'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::vector<unsigned_char,std::allocator<unsigned_char>_>::
  ~vector<unsigned_char,std::allocator<unsigned_char>_>
            (*(vector<unsigned_char,std::allocator<unsigned_char>_> **)(param_2 + 0x30));
  return;
}



===== dtor$1 @ 180018092 =====

void `PktMon::CompList::CompList'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  std::vector<PktMon::Component,std::allocator<PktMon::Component>_>::
  ~vector<PktMon::Component,std::allocator<PktMon::Component>_>
            ((vector<PktMon::Component,std::allocator<PktMon::Component>_> *)
             (*(longlong *)(param_2 + 0x30) + 0x18));
  return;
}



===== dtor$2 @ 1800180a8 =====

void `PktMon::CompList::CompList'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  std::
  map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
  ::
  ~map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
            ((map<unsigned_long,PktMon::GatewayGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::GatewayGroup>_>_>
              *)(*(longlong *)(param_2 + 0x30) + 0x30));
  return;
}



===== dtor$3 @ 1800180be =====

void `PktMon::CompList::CompList'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  std::
  map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
  ::
  ~map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
            ((map<unsigned_long,PktMon::VMSwitch,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::VMSwitch>_>_>
              *)(*(longlong *)(param_2 + 0x30) + 0x40));
  return;
}



===== dtor$4 @ 1800180d4 =====

void `PktMon::CompList::CompList'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  std::
  map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
  ::
  ~map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
            ((map<unsigned_long,PktMon::NicGroup,std::less<unsigned_long>,std::allocator<std::pair<unsigned_long_const_,PktMon::NicGroup>_>_>
              *)(*(longlong *)(param_2 + 0x30) + 0x50));
  return;
}



===== dtor$5 @ 1800180ea =====

void `PktMon::CompList::CompList'::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
  PktMon::GatewayGroup::~GatewayGroup((GatewayGroup *)(*(longlong *)(param_2 + 0x30) + 0x60));
  return;
}



===== dtor$6 @ 180018100 =====

void `PktMon::CompList::CompList'::__l1::dtor_6(undefined8 param_1,longlong param_2)

{
  std::function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>::
  ~function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
            ((function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
              *)(param_2 + 0xa0));
  return;
}



===== dtor$7 @ 180018112 =====

void `PktMon::CompList::CompList'::__l1::dtor_7(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x28) & 1) != 0) {
    *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) & 0xfffffffe;
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(param_2 + 0x38));
  }
  return;
}



===== dtor$15 @ 18001813f =====

void `PktMon::CompList::CompList'::__l1::dtor_15(undefined8 param_1,longlong param_2)

{
  std::function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>::
  ~function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
            (*(function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
               **)(param_2 + 0x28));
  return;
}



===== dtor$0 @ 180018151 =====

void `PktMon::GatewayGroup::AddComp'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>::
  ~function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
            (*(function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
               **)(param_2 + 0x40));
  return;
}



===== dtor$0 @ 180018163 =====

void `PktMon::VMSwitch::AddComp'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>::
  ~function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
            (*(function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
               **)(param_2 + 0xc0));
  return;
}



===== dtor$4 @ 180018175 =====

void `PktMon::VMSwitch::AddComp'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  std::function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>::
  ~function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
            (*(function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
               **)(param_2 + 200));
  return;
}



===== dtor$5 @ 180018187 =====

void `PktMon::VMSwitch::AddComp'::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
  std::function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>::
  ~function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
            (*(function<class_PktMon::CompGroup*___ptr64___cdecl(unsigned_long,_PKTMON_COMPONENT_TYPE)>
               **)(param_2 + 0xb8));
  return;
}



===== dtor$0 @ 180018199 =====

void `PktMon::Component::FindAllProperties'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              (*(vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                 **)(param_2 + 0x78));
  }
  return;
}



===== dtor$1 @ 1800181c6 =====

void `PktMon::Component::FindAllProperties'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x28));
  return;
}



===== dtor$0 @ 1800181d8 =====

void `PktMon::NicGroup::GetComponents'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              (*(vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                 **)(param_2 + 0x48));
  }
  return;
}



===== dtor$0 @ 180018205 =====

void `PktMon::VMSwitch::GetComponents'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              (*(vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                 **)(param_2 + 0x68));
  }
  return;
}



===== dtor$0 @ 180018232 =====

void `PktMon::Component::GetCounters'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x70));
  return;
}



===== dtor$2 @ 180018244 =====

void `PktMon::Component::GetCounters'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x40) & 1) != 0) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0xfffffffe;
    std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
    ~vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>
              ((vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *)(param_2 + 0x50))
    ;
  }
  return;
}



===== dtor$0 @ 180018271 =====

void `PktMon::VMSwitch::GetCounters'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>::
  ~vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_>
            ((vector<PktMon::CounterInfo,std::allocator<PktMon::CounterInfo>_> *)(param_2 + 0x20));
  return;
}



===== dtor$0 @ 180018283 =====

void `PktMon::Component::GetDescription'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              (*(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 **)(param_2 + 0x38));
  }
  return;
}



===== dtor$2 @ 1800182b0 =====

void `PktMon::Component::GetDescription'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x60));
  return;
}



===== dtor$3 @ 1800182c2 =====

void `PktMon::Component::GetDescription'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x40));
  return;
}



===== dtor$4 @ 1800182d4 =====

void `PktMon::Component::GetDescription'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x80));
  return;
}



===== dtor$0 @ 1800182e6 =====

void `PktMon::CompList::GetGroups'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
    ::
    ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              (*(vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
                 **)(param_2 + 0x88));
  }
  return;
}



===== dtor$1 @ 180018316 =====

void `PktMon::CompList::GetGroups'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x58));
  return;
}



===== dtor$2 @ 180018328 =====

void `PktMon::CompList::GetGroups'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x40));
  return;
}



===== dtor$0 @ 18001833a =====

void `PktMon::GatewayGroup::GetName'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              (*(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 **)(param_2 + 0x28));
  }
  return;
}



===== dtor$0 @ 180018367 =====

void `PktMon::VMSwitch::GetName'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              (*(basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                 **)(param_2 + 0x48));
  }
  return;
}



===== dtor$0 @ 180018394 =====

void `NetSetup2::ActiveObject::GetProperty'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  NetSetup2::details::AutoFreeProperties::~AutoFreeProperties
            ((AutoFreeProperties *)(param_2 + 0x60));
  return;
}



===== dtor$0 @ 1800183a6 =====

void `PktMon::InsertRelatedProtocol'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 1) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(param_2 + 0x48));
  }
  return;
}



===== dtor$1 @ 1800183d3 =====

void `PktMon::InsertRelatedProtocol'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x20) & 2) != 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffd;
    std::
    basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>::
    ~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
                *)(param_2 + 0x28));
  }
  return;
}



===== dtor$0 @ 180018400 =====

void `PktMon::NicGroup::IsHidden'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  NetSetup2::Transaction::~Transaction((Transaction *)(param_2 + 0x38));
  return;
}



===== dtor$1 @ 180018412 =====

void `PktMon::NicGroup::IsHidden'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  NetSetup2::NetworkInterface::~NetworkInterface((NetworkInterface *)(param_2 + 0x48));
  return;
}



===== dtor$4 @ 180018424 =====

void `PktMon::NicGroup::IsHidden'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  NetSetup2::Property::~Property((Property *)(param_2 + 0x70));
  return;
}



===== dtor$0 @ 180018436 =====

void `PktMon::Component::MakeRelated'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x58));
  return;
}



===== dtor$5 @ 180018448 =====

void `PktMon::CompList::NormalizeAndValidateSelection'::__l1::dtor_5
               (undefined8 param_1,longlong param_2)

{
  std::set<long,std::less<long>,std::allocator<long>_>::
  ~set<long,std::less<long>,std::allocator<long>_>
            ((set<long,std::less<long>,std::allocator<long>_> *)(param_2 + 0x20));
  return;
}



===== dtor$1 @ 18001845a =====

void `PktMon::CompList::NormalizeAndValidateSelection'::__l1::dtor_1
               (undefined8 param_1,longlong param_2)

{
  if ((*(uint *)(param_2 + 0x140) & 1) != 0) {
    *(uint *)(param_2 + 0x140) = *(uint *)(param_2 + 0x140) & 0xfffffffe;
    std::set<long,std::less<long>,std::allocator<long>_>::
    ~set<long,std::less<long>,std::allocator<long>_>
              (*(set<long,std::less<long>,std::allocator<long>_> **)(param_2 + 0x138));
  }
  return;
}



===== dtor$2 @ 180018490 =====

void `PktMon::CompList::NormalizeAndValidateSelection'::__l1::dtor_2
               (undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0xa8));
  return;
}



===== dtor$3 @ 1800184a2 =====

void `PktMon::CompList::NormalizeAndValidateSelection'::__l1::dtor_3
               (undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0xc0));
  return;
}



===== dtor$4 @ 1800184b4 =====

void `PktMon::CompList::NormalizeAndValidateSelection'::__l1::dtor_4
               (undefined8 param_1,longlong param_2)

{
  std::
  vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>::
  ~vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
            ((vector<PktMon::GatewayGroup_const*___ptr64,std::allocator<PktMon::GatewayGroup_const*___ptr64>_>
              *)(param_2 + 0x80));
  return;
}



===== dtor$8 @ 1800184c6 =====

void `PktMon::CompList::NormalizeAndValidateSelection'::__l1::dtor_8
               (undefined8 param_1,longlong param_2)

{
  std::_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>::
  ~_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
            ((_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_> *)
             (param_2 + 0x58));
  return;
}



===== dtor$19 @ 1800184d8 =====

void `PktMon::CompList::NormalizeAndValidateSelection'::__l1::dtor_19
               (undefined8 param_1,longlong param_2)

{
  std::_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>::
  ~_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_>
            ((_Alloc_construct_ptr<std::allocator<std::_Tree_node<long,void*___ptr64>_>_> *)
             (param_2 + 0x70));
  return;
}



===== dtor$0 @ 1800184ea =====

void `wil::details_abi::FeatureStateData::RecordUsage'::__l1::dtor_0
               (undefined8 param_1,longlong param_2)

{
  wil::details_abi::UsageIndexes::~UsageIndexes((UsageIndexes *)(param_2 + 0x20));
  return;
}



===== dtor$0 @ 1800184fc =====

void `wil::details_abi::RecordWnfUsageIndex'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  wil::details_abi::RawUsageIndex::~RawUsageIndex((RawUsageIndex *)(param_2 + 0x80));
  return;
}



===== dtor$4 @ 18001850e =====

void `wil::details_abi::RecordWnfUsageIndex'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  wistd::
  function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
  ::
  ~function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
            (*(function<bool___cdecl(void*___ptr64,unsigned___int64,void*___ptr64,unsigned___int64,unsigned_int)>
               **)(param_2 + 0x110));
  return;
}



===== dtor$0 @ 180018520 =====

void `PktMon::ShortenDescription'::__l1::dtor_0(void)

{
  _Init_thread_abort(&DAT_180021cf8);
  return;
}



===== dtor$1 @ 180018532 =====

void `PktMon::ShortenDescription'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x360));
  return;
}



===== dtor$2 @ 180018544 =====

void `PktMon::ShortenDescription'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x340));
  return;
}



===== dtor$3 @ 180018556 =====

void `PktMon::ShortenDescription'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x380));
  return;
}



===== dtor$4 @ 180018568 =====

void `PktMon::ShortenDescription'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 800));
  return;
}



===== dtor$5 @ 18001857a =====

void `PktMon::ShortenDescription'::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x300));
  return;
}



===== dtor$6 @ 18001858c =====

void `PktMon::ShortenDescription'::__l1::dtor_6(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x3c0));
  return;
}



===== dtor$7 @ 18001859e =====

void `PktMon::ShortenDescription'::__l1::dtor_7(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x2e0));
  return;
}



===== dtor$8 @ 1800185b0 =====

void `PktMon::ShortenDescription'::__l1::dtor_8(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x2c0));
  return;
}



===== dtor$9 @ 1800185c2 =====

void `PktMon::ShortenDescription'::__l1::dtor_9(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x400));
  return;
}



===== dtor$10 @ 1800185d4 =====

void `PktMon::ShortenDescription'::__l1::dtor_10(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x2a0));
  return;
}



===== dtor$11 @ 1800185e6 =====

void `PktMon::ShortenDescription'::__l1::dtor_11(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x280));
  return;
}



===== dtor$12 @ 1800185f8 =====

void `PktMon::ShortenDescription'::__l1::dtor_12(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x440));
  return;
}



===== dtor$13 @ 18001860a =====

void `PktMon::ShortenDescription'::__l1::dtor_13(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x260));
  return;
}



===== dtor$14 @ 18001861c =====

void `PktMon::ShortenDescription'::__l1::dtor_14(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x240));
  return;
}



===== dtor$15 @ 18001862e =====

void `PktMon::ShortenDescription'::__l1::dtor_15(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x480));
  return;
}



===== dtor$16 @ 180018640 =====

void `PktMon::ShortenDescription'::__l1::dtor_16(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x220));
  return;
}



===== dtor$17 @ 180018652 =====

void `PktMon::ShortenDescription'::__l1::dtor_17(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x200));
  return;
}



===== dtor$18 @ 180018664 =====

void `PktMon::ShortenDescription'::__l1::dtor_18(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x4c0));
  return;
}



===== dtor$19 @ 180018676 =====

void `PktMon::ShortenDescription'::__l1::dtor_19(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x1e0));
  return;
}



===== dtor$20 @ 180018688 =====

void `PktMon::ShortenDescription'::__l1::dtor_20(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x1c0));
  return;
}



===== dtor$21 @ 18001869a =====

void `PktMon::ShortenDescription'::__l1::dtor_21(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x500));
  return;
}



===== dtor$22 @ 1800186ac =====

void `PktMon::ShortenDescription'::__l1::dtor_22(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x1a0));
  return;
}



===== dtor$23 @ 1800186be =====

void `PktMon::ShortenDescription'::__l1::dtor_23(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x180));
  return;
}



===== dtor$24 @ 1800186d0 =====

void `PktMon::ShortenDescription'::__l1::dtor_24(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x540));
  return;
}



===== dtor$25 @ 1800186e2 =====

void `PktMon::ShortenDescription'::__l1::dtor_25(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x160));
  return;
}



===== dtor$26 @ 1800186f4 =====

void `PktMon::ShortenDescription'::__l1::dtor_26(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x140));
  return;
}



===== dtor$27 @ 180018706 =====

void `PktMon::ShortenDescription'::__l1::dtor_27(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x580));
  return;
}



===== dtor$28 @ 180018718 =====

void `PktMon::ShortenDescription'::__l1::dtor_28(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x120));
  return;
}



===== dtor$29 @ 18001872a =====

void `PktMon::ShortenDescription'::__l1::dtor_29(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0x100));
  return;
}



===== dtor$30 @ 18001873c =====

void `PktMon::ShortenDescription'::__l1::dtor_30(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x5c0));
  return;
}



===== dtor$31 @ 18001874e =====

void `PktMon::ShortenDescription'::__l1::dtor_31(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0xe0));
  return;
}



===== dtor$32 @ 180018760 =====

void `PktMon::ShortenDescription'::__l1::dtor_32(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0xc0));
  return;
}



===== dtor$33 @ 180018772 =====

void `PktMon::ShortenDescription'::__l1::dtor_33(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x600));
  return;
}



===== dtor$34 @ 180018784 =====

void `PktMon::ShortenDescription'::__l1::dtor_34(undefined8 param_1,longlong param_2)

{
  std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
  ::~basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
            ((basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>
              *)(param_2 + 0xa0));
  return;
}



===== dtor$36 @ 180018796 =====

void `PktMon::ShortenDescription'::__l1::dtor_36(undefined8 param_1,longlong param_2)

{
  std::
  pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
  ::
  ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            ((pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
              *)(param_2 + 0x640));
  return;
}



===== dtor$40 @ 1800187a8 =====

void `PktMon::ShortenDescription'::__l1::dtor_40(undefined8 param_1,longlong param_2)

{
  _eh_vector_destructor_iterator_
            ((void *)(param_2 + 0x380),0x40,0xd,
             std::
             pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
             ::
             ~pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>
            );
  return;
}



===== `dynamic_atexit_destructor_for_'g_processLocalData'' @ 1800187e0 =====

void wil::details::_dynamic_atexit_destructor_for__g_processLocalData__(void)

{
  if (DAT_180021008 != (ProcessLocalStorageData<wil::details_abi::ProcessLocalData> *)0x0) {
    details_abi::ProcessLocalStorageData<wil::details_abi::ProcessLocalData>::Release(DAT_180021008)
    ;
  }
  return;
}



===== `dynamic_atexit_destructor_for_'g_threadFailureCallbacks'' @ 180018810 =====

void wil::details::_dynamic_atexit_destructor_for__g_threadFailureCallbacks__(void)

{
  details_abi::ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>::
  ~ThreadLocalStorage<wil::details::ThreadFailureCallbackHolder*___ptr64>(&g_threadFailureCallbacks)
  ;
  return;
}



===== `dynamic_atexit_destructor_for_'g_featureStateManager'' @ 180018830 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void wil::details::_dynamic_atexit_destructor_for__g_featureStateManager__(void)

{
  uchar uVar1;
  
  if (g_processShutdownInProgress) {
LAB_180018860:
    g_featureStateManager = (shutdown_aware_object<wil::details::FeatureStateManager>)0x0;
    if (DAT_180021020 != (ProcessLocalStorageData<wil::details_abi::FeatureStateData> *)0x0) {
      details_abi::ProcessLocalStorageData<wil::details_abi::FeatureStateData>::Release
                (DAT_180021020);
    }
  }
  else {
    if (g_pfnDllShutdownInProgress != (_func_uchar *)0x0) {
      uVar1 = (*g_pfnDllShutdownInProgress)();
      if (uVar1 != '\0') goto LAB_180018860;
    }
    FeatureStateManager::~FeatureStateManager((FeatureStateManager *)&g_featureStateManager);
  }
  return;
}



===== `dynamic_atexit_destructor_for_'replacementMap'' @ 180018890 =====

void `PktMon::ShortenDescription'::__l2::_dynamic_atexit_destructor_for__replacementMap__(void)

{
  std::
  _Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
  ::
  ~_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
            ((_Tree<std::_Tmap_traits<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_,std::less<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_>,std::allocator<std::pair<std::basic_string<unsigned_short,std::char_traits<unsigned_short>,std::allocator<unsigned_short>_>_const_,std::basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>_const_>_>,0>_>
              *)&DAT_180021d00);
  return;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 180019010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


