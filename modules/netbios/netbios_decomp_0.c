
===== pre_c_init @ 180001010 =====

bool pre_c_init(void)

{
  bool bVar1;
  
  __onexitend = malloc(0x100);
  bVar1 = __onexitend != (undefined8 *)0x0;
  __onexitbegin = __onexitend;
  if (bVar1) {
    *__onexitend = 0;
  }
  return !bVar1;
}



===== _CRT_INIT @ 18000104c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 _CRT_INIT(undefined8 param_1,int param_2,undefined8 param_3)

{
  void *pvVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  BOOL BVar5;
  void *pvVar6;
  undefined8 *_Memory;
  undefined8 *puVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  bool bVar11;
  
  pvVar1 = StackBase;
  if (param_2 == 0) {
    if (DAT_1800070a0 < 1) {
      return 0;
    }
    DAT_1800070a0 = DAT_1800070a0 + -1;
    bVar3 = false;
    while( true ) {
      pvVar6 = (void *)0x0;
      LOCK();
      bVar11 = __native_startup_lock == (void *)0x0;
      if (bVar11) {
        __native_startup_lock = pvVar1;
      }
      else {
        pvVar6 = __native_startup_lock;
      }
      UNLOCK();
      if (bVar11) goto LAB_1800010c2;
      if (pvVar6 == pvVar1) break;
      Sleep(1000);
    }
    bVar3 = true;
LAB_1800010c2:
    if (__native_startup_state == 2) {
      if (__onexitbegin != (undefined8 *)0x0) {
        _Memory = __onexitbegin;
        puVar7 = __onexitend;
        puVar9 = __onexitbegin;
        puVar10 = __onexitend;
        while (puVar7 = puVar7 + -1, _Memory <= puVar7) {
          pcVar2 = (code *)*puVar7;
          if (pcVar2 != (code *)0x0) {
            *puVar7 = 0;
            (*pcVar2)();
            if ((puVar9 != __onexitbegin) || (puVar10 != __onexitend)) {
              _Memory = __onexitbegin;
              puVar7 = __onexitend;
              puVar9 = __onexitbegin;
              puVar10 = __onexitend;
            }
          }
        }
        free(_Memory);
        __onexitend = (undefined8 *)0x0;
        __onexitbegin = (undefined8 *)0x0;
      }
      __native_startup_state = 0;
      if (!bVar3) {
        LOCK();
        __native_startup_lock = (void *)0x0;
        UNLOCK();
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == 1) {
    bVar3 = false;
    while( true ) {
      pvVar6 = (void *)0x0;
      LOCK();
      bVar11 = __native_startup_lock == (void *)0x0;
      if (bVar11) {
        __native_startup_lock = pvVar1;
      }
      else {
        pvVar6 = __native_startup_lock;
      }
      UNLOCK();
      if (bVar11) goto LAB_1800011a4;
      if (pvVar6 == pvVar1) break;
      Sleep(1000);
    }
    bVar3 = true;
LAB_1800011a4:
    if (__native_startup_state == 0) {
      plVar8 = &__xi_a;
      __native_startup_state = 1;
      iVar4 = 0;
      do {
        if (iVar4 != 0) {
          return 0;
        }
        if (*plVar8 != 0) {
          iVar4 = (*(code *)*plVar8)();
        }
        plVar8 = plVar8 + 1;
      } while (plVar8 < &__xi_z);
      if (iVar4 != 0) {
        return 0;
      }
      _initterm(&__xc_a,&__xc_z);
      __native_startup_state = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar3) {
      LOCK();
      __native_startup_lock = (void *)0x0;
      UNLOCK();
    }
    if ((__dyn_tls_init_callback != (code *)0x0) &&
       (BVar5 = _IsNonwritableInCurrentImage((PBYTE)&__dyn_tls_init_callback), BVar5 != 0)) {
      (*__dyn_tls_init_callback)(param_1,2,param_3);
    }
    DAT_1800070a0 = DAT_1800070a0 + 1;
  }
  return 1;
}



===== entry @ 180001290 =====

void entry(HMODULE param_1,uint param_2,longlong param_3,undefined8 param_4)

{
  if (param_2 == 1) {
    __security_init_cookie();
  }
  __DllMainCRTStartup(param_1,(ulonglong)param_2,param_3,param_4);
  return;
}



===== __DllMainCRTStartup @ 1800012d4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong __DllMainCRTStartup(HMODULE param_1,ulonglong param_2,longlong param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = (uint)param_2;
  uVar4 = 1;
  if (uVar3 < 2) {
    ___native_dllmain_reason = uVar3;
  }
  if ((uVar3 == 0) && (DAT_1800070a0 == 0)) {
    uVar4 = 0;
    goto LAB_1800014c5;
  }
  if (uVar3 - 1 < 2) {
    if (_pRawDllMain != (code *)0x0) {
      if (uVar3 == 1) {
        DAT_1800070a4 = 1;
      }
      uVar1 = (*_pRawDllMain)(param_1,param_2,param_3,param_4,1);
      uVar4 = (ulonglong)uVar1;
    }
    if ((int)uVar4 == 0) goto LAB_1800014c5;
    uVar2 = _CRT_INIT(param_1,uVar3,param_3);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) goto LAB_1800014c5;
  }
  uVar2 = DllMain(param_1,uVar3,param_3);
  uVar4 = uVar2 & 0xffffffff;
  if ((uVar3 == 1) && ((int)uVar2 == 0)) {
    DllMain(param_1,0,0);
    _CRT_INIT(param_1,0,0);
    if (_pRawDllMain != (code *)0x0) {
      (*_pRawDllMain)(param_1,0,0);
    }
  }
  if ((uVar3 == 0) || (uVar3 == 3)) {
    uVar4 = _CRT_INIT(param_1,uVar3,param_3);
    uVar4 = uVar4 & 0xffffffff;
    if ((_pRawDllMain != (code *)0x0) && (DAT_1800070a4 != 0)) {
      uVar1 = (*_pRawDllMain)(param_1,param_2 & 0xffffffff,param_3);
      uVar4 = (ulonglong)uVar1;
    }
  }
LAB_1800014c5:
  if (uVar3 < 2) {
    ___native_dllmain_reason = 0xffffffff;
  }
  return uVar4;
}



===== __C_specific_handler @ 1800014e7 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800014e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __raise_securityfailure @ 1800014f8 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000180001525. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



===== __report_gsfailure @ 180001540 =====

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
  RtlCaptureContext(&DAT_180007150);
  ControlPc = DAT_180007248;
  FunctionEntry = RtlLookupFunctionEntry(DAT_180007248,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    DAT_180007248 = *DAT_1800071e8;
    DAT_1800071e8 = DAT_1800071e8 + 1;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_180007150,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_1800070c0 = DAT_180007248;
  _DAT_1800070b0 = 0xc0000409;
  _DAT_1800070b4 = 1;
  _DAT_1800070c8 = 3;
  DAT_1800070d0 = 2;
  DAT_1800070d8 = __security_cookie;
  DAT_1800070e0 = __security_cookie_complement;
  uStack_20 = __security_cookie;
  uStack_18 = __security_cookie_complement;
  _DAT_1800071d0 = _StackCookie;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_180005000);
  return;
}



===== _XcptFilter @ 1800016e4 =====

int __cdecl _XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001800016e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _XcptFilter(_ExceptionNum,_ExceptionPtr);
  return iVar1;
}



===== _amsg_exit @ 1800016f0 =====

void __cdecl _amsg_exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001800016f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _amsg_exit(param_1);
  return;
}



===== _FindPESection @ 180001700 =====

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



===== _IsNonwritableInCurrentImage @ 180001750 =====

BOOL __cdecl _IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  uint uVar2;
  PIMAGE_SECTION_HEADER p_Var3;
  
  BVar1 = _ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_180000000);
  uVar2 = 0;
  if (BVar1 != 0) {
    p_Var3 = _FindPESection((PBYTE)&IMAGE_DOS_HEADER_180000000,(DWORD_PTR)(pTarget + -0x180000000));
    uVar2 = 0;
    if (p_Var3 != (PIMAGE_SECTION_HEADER)0x0) {
      uVar2 = ~(p_Var3->Characteristics >> 0x1f) & 1;
    }
  }
  return uVar2;
}



===== _ValidateImageBase @ 1800017b0 =====

BOOL __cdecl _ValidateImageBase(PBYTE pImageBase)

{
  if ((*(short *)pImageBase == 0x5a4d) &&
     (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550)) {
    return (BOOL)((short)*(int *)((longlong)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) ==
                 0x20b);
  }
  return 0;
}



===== __security_init_cookie @ 1800017e4 =====

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



===== _initterm @ 1800018c3 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001800018c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== _guard_check_icall @ 1800018e0 =====

void _guard_check_icall(void)

{
  return;
}



===== __tailMerge_api_ms_win_service_management_l1_1_0_dll @ 1800018f0 =====

void __tailMerge_api_ms_win_service_management_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R9;
  undefined8 in_XMM0_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_180005d7c,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000180001967. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_XMM0_Qa,param_2,param_3,in_R9);
  return;
}



===== DelayLoad_OpenServiceW @ 18000196f =====

void DelayLoad_OpenServiceW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_service_management_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_StartServiceW @ 180001981 =====

void DelayLoad_StartServiceW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_service_management_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_OpenSCManagerW @ 180001993 =====

void DelayLoad_OpenSCManagerW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_service_management_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CloseServiceHandle @ 1800019a5 =====

void DelayLoad_CloseServiceHandle
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_service_management_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== AddNameThreadExit @ 1800019b8 =====

void AddNameThreadExit(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&Crit);
  AddNameThreadCount = AddNameThreadCount + -1;
  if (AddNameThreadCount == 0) {
    NtSetEvent(AddNameEvent,0);
  }
                    /* WARNING: Could not recover jumptable at 0x000180001a07. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
  return;
}



===== ChainSendPostRoutine @ 180001a20 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void ChainSendPostRoutine(char *param_1,int *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  code *pcVar3;
  longlong lVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = *puVar2;
  if (*param_2 == -0x7ffeffff) {
    HangupConnection((longlong)param_1);
  }
  pcVar3 = *(code **)(param_1 + 0x38);
  lVar4 = *(longlong *)(param_1 + 0x58);
  cVar1 = *param_1;
  param_1[0x41] = param_1[1];
  EnterCriticalSection((LPCRITICAL_SECTION)&Crit);
  param_1[0x42] = '\0';
  param_1[0x43] = '\0';
  LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
  if (lVar4 != 0) {
    NtSetEvent(lVar4,0);
  }
  if ((pcVar3 != (code *)0x0) && (cVar1 < '\0')) {
    (*pcVar3)(param_1);
  }
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar2);
  return;
}



===== HangupConnection @ 180001b08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HangupConnection(longlong param_1)

{
  int iVar1;
  undefined1 auStack_c8 [32];
  undefined1 *local_a8;
  undefined4 local_a0;
  undefined1 *local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_30 [16];
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  memset(&local_78,0,0x60);
  local_76 = *(undefined1 *)(param_1 + 2);
  local_38 = *(undefined1 *)(param_1 + 0x40);
  local_78 = 0x12;
  local_37 = 0xff;
  local_77 = 0xff;
  local_a8 = (undefined1 *)((ulonglong)local_a8 & 0xffffffffffffff00);
  iVar1 = NtCreateEvent(&local_20,0x1f0003,0,1);
  if (-1 < iVar1) {
    local_98 = &local_78;
    local_80 = 0;
    local_88 = 0;
    local_90 = 0x60;
    local_a8 = local_30;
    local_a0 = 0x210053;
    NtDeviceIoControlFile(NB,local_20,0,0);
    do {
      do {
        iVar1 = NtWaitForSingleObject(local_20,1,0);
      } while (iVar1 == 0xc0);
    } while (iVar1 == 0x101);
    NtClose(local_20);
  }
  return;
}



===== Netbios @ 180001c20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

UCHAR __stdcall Netbios(PNCB pncb)

{
  HANDLE *ppvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  HANDLE pvVar20;
  int iVar21;
  DWORD DVar22;
  int iVar23;
  longlong lVar24;
  ulonglong uVar25;
  bool bVar26;
  undefined1 auStackY_2d8 [32];
  DWORD local_2a8 [4];
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined4 local_250;
  WCHAR local_248 [260];
  undefined2 local_40;
  ulonglong local_38;
  
                    /* 0x1c20  1  Netbios */
  local_38 = __security_cookie ^ (ulonglong)auStackY_2d8;
  if (((ulonglong)pncb & 3) != 0) {
    pncb->ncb_cmd_cplt = '\a';
    pncb->ncb_retcode = '\a';
    return '\a';
  }
  bVar26 = Initialized != 0;
  pncb->ncb_reserve[0] = '\0';
  pncb->ncb_reserve[1] = '\0';
  pncb->ncb_cmd_cplt = 0xff;
  pncb->ncb_retcode = 0xff;
  if (bVar26) {
LAB_180001f8c:
    iVar21 = EventUse;
    if (NB == 0) {
      pncb->ncb_retcode = '?';
      pncb->ncb_cmd_cplt = '?';
      goto LAB_1800021cb;
    }
    ppvVar1 = &pncb->ncb_event;
    if (-1 < (char)pncb->ncb_command) {
      LOCK();
      UNLOCK();
      if (EventUse == 1) {
        EventUse = EventUse + -1;
        *ppvVar1 = ReservedEvent;
      }
      else {
        LOCK();
        UNLOCK();
        iVar23 = NtCreateEvent(ppvVar1,0x1f0003,0,1);
        if (iVar23 < 0) {
          pncb->ncb_retcode = '@';
          pncb->ncb_cmd_cplt = '@';
          goto LAB_1800021cb;
        }
      }
      bVar26 = WorkerHandle == (HANDLE)0x0;
      pncb->ncb_post = (_func_3759 *)0x0;
      if (bVar26) {
        uVar25 = (ulonglong)g_dwNextSCEntry;
        *(PNCB *)(&g_SyncCmdsHistory + uVar25 * 0x78) = pncb;
        uVar2 = *(undefined4 *)&pncb->field_0x4;
        uVar3 = *(undefined4 *)&pncb->ncb_buffer;
        uVar4 = *(undefined4 *)((longlong)&pncb->ncb_buffer + 4);
        uVar5 = *(undefined4 *)&pncb->ncb_length;
        uVar6 = *(undefined4 *)(pncb->ncb_callname + 2);
        uVar7 = *(undefined4 *)(pncb->ncb_callname + 6);
        uVar8 = *(undefined4 *)(pncb->ncb_callname + 10);
        uVar9 = *(undefined4 *)(pncb->ncb_callname + 0xe);
        uVar10 = *(undefined4 *)(pncb->ncb_name + 2);
        uVar11 = *(undefined4 *)(pncb->ncb_name + 6);
        uVar12 = *(undefined4 *)(pncb->ncb_name + 10);
        uVar13 = *(undefined4 *)(pncb->ncb_name + 0xe);
        uVar14 = *(undefined4 *)&pncb->field_0x34;
        uVar15 = *(undefined4 *)&pncb->ncb_post;
        uVar16 = *(undefined4 *)((longlong)&pncb->ncb_post + 4);
        uVar17 = *(undefined8 *)&pncb->ncb_lana_num;
        uVar18 = *(undefined8 *)(pncb->ncb_reserve + 6);
        uVar19 = *(undefined8 *)(pncb->ncb_reserve + 0xe);
        pvVar20 = pncb->ncb_event;
        lVar24 = uVar25 * 0x78;
        *(undefined4 *)(&DAT_1800086e8 + lVar24) = *(undefined4 *)pncb;
        *(undefined4 *)(lVar24 + 0x1800086ec) = uVar2;
        *(undefined4 *)(lVar24 + 0x1800086f0) = uVar3;
        *(undefined4 *)(lVar24 + 0x1800086f4) = uVar4;
        *(undefined4 *)(&DAT_1800086f8 + lVar24) = uVar5;
        *(undefined4 *)(lVar24 + 0x1800086fc) = uVar6;
        *(undefined4 *)(lVar24 + 0x180008700) = uVar7;
        *(undefined4 *)(lVar24 + 0x180008704) = uVar8;
        *(undefined4 *)(&DAT_180008708 + lVar24) = uVar9;
        *(undefined4 *)(lVar24 + 0x18000870c) = uVar10;
        *(undefined4 *)(lVar24 + 0x180008710) = uVar11;
        *(undefined4 *)(lVar24 + 0x180008714) = uVar12;
        *(undefined4 *)(&DAT_180008718 + lVar24) = uVar13;
        *(undefined4 *)(lVar24 + 0x18000871c) = uVar14;
        *(undefined4 *)(lVar24 + 0x180008720) = uVar15;
        *(undefined4 *)(lVar24 + 0x180008724) = uVar16;
        *(undefined8 *)(&DAT_180008728 + lVar24) = uVar17;
        *(undefined8 *)(lVar24 + 0x180008730) = uVar18;
        *(undefined8 *)(&DAT_180008738 + lVar24) = uVar19;
        *(HANDLE *)(lVar24 + 0x180008740) = pvVar20;
        DVar22 = GetTickCount();
        *(DWORD *)(&DAT_180008748 + (ulonglong)g_dwNextSCEntry * 0x78) = DVar22;
        DVar22 = GetCurrentThreadId();
        *(DWORD *)(&DAT_18000874c + (ulonglong)g_dwNextSCEntry * 0x78) = DVar22;
        g_dwNextSCEntry = g_dwNextSCEntry + 1 & 0xf;
        SendNcbToDriver(&pncb->ncb_command);
      }
      else {
        QueueToWorker((undefined4 *)pncb);
      }
      do {
        do {
          iVar23 = NtWaitForSingleObject(*ppvVar1,1,0);
        } while (iVar23 == 0xc0);
      } while (iVar23 == 0x101);
      if (iVar23 < 0) {
        pncb->ncb_retcode = '@';
        pncb->ncb_cmd_cplt = '@';
      }
      if (iVar21 == 1) {
        LOCK();
        EventUse = EventUse + 1;
        UNLOCK();
      }
      else {
        NtClose(pncb->ncb_event);
      }
      pncb->ncb_event = (HANDLE)0x0;
      goto LAB_1800021cb;
    }
    if ((*ppvVar1 != (HANDLE)0x0) && (pncb->ncb_post != (_func_3759 *)0x0)) {
      pncb->ncb_retcode = '\x03';
      pncb->ncb_cmd_cplt = '\x03';
      goto LAB_1800021cb;
    }
    if (WorkerHandle != (HANDLE)0x0) goto LAB_18000205b;
    EnterCriticalSection((LPCRITICAL_SECTION)&Crit);
    if (WorkerHandle == (HANDLE)0x0) {
      local_2a8[2] = 0;
      local_2a8[3] = 0;
      WorkerHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,NetbiosWorker,(LPVOID)0x0,0,
                                  local_2a8 + 2);
      if (WorkerHandle == (HANDLE)0x0) {
        pncb->ncb_retcode = '@';
        pncb->ncb_cmd_cplt = '@';
        goto LAB_180001d19;
      }
      SetThreadPriority(WorkerHandle,1);
      AddNameThreadCount = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
LAB_18000205b:
    QueueToWorker((undefined4 *)pncb);
    return '\0';
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&Crit);
  if (Initialized != 0) {
LAB_180001f76:
    Initialized = 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
    goto LAB_180001f8c;
  }
  local_2a8[0] = 0;
  local_2a8[1] = 0;
  local_258 = 0;
  local_288 = 0;
  uStack_280 = 0;
  local_250 = 0;
  local_278 = 0;
  uStack_270 = 0;
  local_268 = 0;
  uStack_260 = 0;
  local_298 = 0;
  uStack_290 = 0;
  RtlInitUnicodeString(&local_298,L"\\Device\\Netbios");
  iVar21 = StartNB((undefined4 *)&local_278,&local_298,&local_288);
  if ((-1 < iVar21) ||
     ((DVar22 = StartNetBIOSDriver(), DVar22 == 0 &&
      (iVar21 = StartNB((undefined4 *)&local_278,&local_298,&local_288), -1 < iVar21)))) {
    iVar21 = NtCreateEvent(&ReservedEvent,0x1f0003,0,1);
    if (iVar21 < 0) {
      pncb->ncb_retcode = '@';
      pncb->ncb_cmd_cplt = '@';
      LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
    }
    else {
      EventUse = 1;
      DAT_180007e18 = &WorkQueue;
      WorkQueue = &WorkQueue;
      iVar21 = NtCreateEvent(&Event,0x1f0003,0,1);
      if (iVar21 < 0) {
        pncb->ncb_retcode = '@';
        pncb->ncb_cmd_cplt = '@';
        LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
      }
      else {
        iVar21 = NtCreateEvent(&AddNameEvent,0x1f0003,0,0);
        if (iVar21 < 0) {
          pncb->ncb_retcode = '@';
          pncb->ncb_cmd_cplt = '@';
          LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
        }
        else {
          iVar21 = NtCreateEvent(&StopEvent,0x1f0003,0,1);
          if (iVar21 < 0) {
            pncb->ncb_retcode = '@';
            pncb->ncb_cmd_cplt = '@';
            LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
          }
          else {
            iVar21 = NtCreateEvent(&LanaResetEvent,0x1f0003,0,1);
            if (-1 < iVar21) {
              GetModuleFileNameW(g_hModule,local_248,0x105);
              local_40 = 0;
              LoadLibraryExW(local_248,(HANDLE)0x0,0);
              _WaiterHandle =
                   CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,NetbiosWaiter,(LPVOID)0x0,0,local_2a8);
              if (_WaiterHandle != (HANDLE)0x0) goto LAB_180001f76;
            }
            pncb->ncb_retcode = '@';
            pncb->ncb_cmd_cplt = '@';
            LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
            NtClose(StopEvent);
          }
          NtClose(AddNameEvent);
        }
        NtClose(Event);
      }
      NtClose(ReservedEvent);
    }
    NtClose(NB);
    NB = 0;
    goto LAB_1800021cb;
  }
  pncb->ncb_retcode = '?';
  pncb->ncb_cmd_cplt = '?';
LAB_180001d19:
  LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
LAB_1800021cb:
  return pncb->ncb_cmd_cplt;
}



===== NetbiosDelete @ 180002200 =====

void NetbiosDelete(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *lpMem;
  HANDLE hHeap;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar3 = auStack_28;
  do {
    lpMem = LanaResetList;
    if ((undefined8 **)LanaResetList == &LanaResetList) {
LAB_180002260:
      *(undefined8 *)(puVar3 + -8) = 0x18000226e;
      DeleteCriticalSection((LPCRITICAL_SECTION)&ResetCS);
      *(undefined8 *)(puVar3 + -8) = 0x180002281;
      DeleteCriticalSection((LPCRITICAL_SECTION)&Crit);
      if (Initialized != 0) {
        *(undefined8 *)(puVar3 + -8) = 0x18000229d;
        NtClose(NB);
      }
      return;
    }
    if (((undefined8 **)LanaResetList[1] != &LanaResetList) ||
       (puVar1 = (undefined8 *)*LanaResetList, (undefined8 *)puVar1[1] != LanaResetList)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar3 = auStack_20;
      goto LAB_180002260;
    }
    LanaResetList = puVar1;
    puVar1[1] = &LanaResetList;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  } while( true );
}



===== NetbiosInitialize @ 1800022b4 =====

undefined8 NetbiosInitialize(undefined8 param_1)

{
  void *pvVar1;
  
  Initialized = 0;
  WorkerHandle = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&Crit);
  InitializeCriticalSection((LPCRITICAL_SECTION)&ResetCS);
  DAT_180007e38 = &LanaResetList;
  LanaResetList = &LanaResetList;
  pvVar1 = memset(&OutputNCB,0,0x60);
  g_hModule = param_1;
  return CONCAT71((int7)((ulonglong)pvVar1 >> 8),1);
}



===== NetbiosWaiter @ 180002350 =====

void NetbiosWaiter(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 local_18;
  undefined8 local_10;
  
  NtDeviceIoControlFile(NB,StopEvent,0,0,&StopStatusBlock,0x210057,0,0,0,0);
  NtDeviceIoControlFile(NB,LanaResetEvent,0,0,&ResetStatusBlock,0x21005c,0,0,&OutputNCB,0x60);
  do {
    do {
      while( true ) {
        local_18 = StopEvent;
        local_10 = LanaResetEvent;
        iVar1 = NtWaitForMultipleObjects(2,&local_18,1,1,0);
        if (iVar1 != 0) break;
        NtClose(NB);
        LOCK();
        NB = 0;
        UNLOCK();
      }
    } while (((iVar1 != 1) || (NB == 0)) || (DAT_180007e80 == -1));
    EnterCriticalSection((LPCRITICAL_SECTION)&ResetCS);
    puVar2 = LanaResetList;
    if ((undefined8 **)LanaResetList != &LanaResetList) {
      do {
        if (*(char *)(puVar2 + 10) == DAT_180007e80) {
          QueueToWorker((undefined4 *)(puVar2 + 2));
          break;
        }
        puVar2 = (undefined8 *)*puVar2;
      } while ((undefined8 **)puVar2 != &LanaResetList);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&ResetCS);
    DAT_180007e80 = '\0';
    NtDeviceIoControlFile(NB,LanaResetEvent,0,0,&ResetStatusBlock,0x21005c,0,0,&OutputNCB,0x60);
  } while( true );
}



===== NetbiosWorker @ 180002520 =====

void NetbiosWorker(void)

{
  byte *lpParameter;
  longlong *plVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  longlong lVar20;
  longlong lVar21;
  longlong *plVar22;
  int iVar23;
  DWORD DVar24;
  HANDLE hObject;
  longlong lVar25;
  ulonglong uVar26;
  DWORD local_res10 [2];
  
LAB_180002548:
  do {
    do {
      iVar23 = NtWaitForSingleObject(Event,1,0);
    } while (iVar23 != 0);
  } while (NB == 0);
LAB_18000256e:
  do {
    EnterCriticalSection((LPCRITICAL_SECTION)&Crit);
    plVar22 = WorkQueue;
    if ((longlong **)WorkQueue == &WorkQueue) break;
    if (((longlong **)WorkQueue[1] != &WorkQueue) ||
       (plVar1 = (longlong *)*WorkQueue, (longlong *)plVar1[1] != WorkQueue)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar26 = (ulonglong)g_dwNextDQHEntry;
    lpParameter = (byte *)(WorkQueue + -9);
    WorkQueue = plVar1;
    plVar1[1] = (longlong)&WorkQueue;
    plVar22[1] = 0;
    *plVar22 = 0;
    *(byte **)(&g_DeQueuedHistory + uVar26 * 0x78) = lpParameter;
    uVar3 = *(undefined4 *)((longlong)plVar22 + -0x44);
    lVar15 = plVar22[-8];
    uVar4 = *(undefined4 *)((longlong)plVar22 + -0x3c);
    lVar16 = plVar22[-7];
    uVar5 = *(undefined4 *)((longlong)plVar22 + -0x34);
    lVar17 = plVar22[-6];
    uVar6 = *(undefined4 *)((longlong)plVar22 + -0x2c);
    lVar18 = plVar22[-5];
    uVar7 = *(undefined4 *)((longlong)plVar22 + -0x24);
    lVar19 = plVar22[-4];
    uVar8 = *(undefined4 *)((longlong)plVar22 + -0x1c);
    lVar20 = plVar22[-3];
    uVar9 = *(undefined4 *)((longlong)plVar22 + -0x14);
    lVar21 = plVar22[-2];
    uVar10 = *(undefined4 *)((longlong)plVar22 + -0xc);
    lVar11 = plVar22[-1];
    lVar12 = *plVar22;
    lVar13 = plVar22[1];
    lVar14 = plVar22[2];
    lVar25 = uVar26 * 0x78;
    *(undefined4 *)(&DAT_180007688 + lVar25) = *(undefined4 *)lpParameter;
    *(undefined4 *)(lVar25 + 0x18000768c) = uVar3;
    *(int *)(lVar25 + 0x180007690) = (int)lVar15;
    *(undefined4 *)(lVar25 + 0x180007694) = uVar4;
    *(int *)(&DAT_180007698 + lVar25) = (int)lVar16;
    *(undefined4 *)(lVar25 + 0x18000769c) = uVar5;
    *(int *)(lVar25 + 0x1800076a0) = (int)lVar17;
    *(undefined4 *)(lVar25 + 0x1800076a4) = uVar6;
    *(int *)(&DAT_1800076a8 + lVar25) = (int)lVar18;
    *(undefined4 *)(lVar25 + 0x1800076ac) = uVar7;
    *(int *)(lVar25 + 0x1800076b0) = (int)lVar19;
    *(undefined4 *)(lVar25 + 0x1800076b4) = uVar8;
    *(int *)(&DAT_1800076b8 + lVar25) = (int)lVar20;
    *(undefined4 *)(lVar25 + 0x1800076bc) = uVar9;
    *(int *)(lVar25 + 0x1800076c0) = (int)lVar21;
    *(undefined4 *)(lVar25 + 0x1800076c4) = uVar10;
    *(longlong *)(&DAT_1800076c8 + lVar25) = lVar11;
    *(longlong *)(lVar25 + 0x1800076d0) = lVar12;
    *(longlong *)(&DAT_1800076d8 + lVar25) = lVar13;
    *(longlong *)(lVar25 + 0x1800076e0) = lVar14;
    DVar24 = GetTickCount();
    *(DWORD *)(&DAT_1800076e8 + (ulonglong)g_dwNextDQHEntry * 0x78) = DVar24;
    DVar24 = GetCurrentThreadId();
    *(DWORD *)(&DAT_1800076ec + (ulonglong)g_dwNextDQHEntry * 0x78) = DVar24;
    g_dwNextDQHEntry = g_dwNextDQHEntry + 1 & 0xf;
    LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
    if ((*lpParameter & 0x7f) == 0x32) {
      while( true ) {
        EnterCriticalSection((LPCRITICAL_SECTION)&Crit);
        NtResetEvent(AddNameEvent,0);
        if (AddNameThreadCount == 0) break;
        LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
        NtWaitForSingleObject(AddNameEvent);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
    }
    if (((*lpParameter & 0xffffff7f) < 0x37) &&
       ((0x49000000000000U >> ((ulonglong)(*lpParameter & 0xffffff7f) & 0x3f) & 1) != 0)) {
      local_res10[0] = 0;
      local_res10[1] = 0;
      EnterCriticalSection((LPCRITICAL_SECTION)&Crit);
      AddNameThreadCount = AddNameThreadCount + 1;
      NtResetEvent(AddNameEvent,0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
      hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,SendAddNcbToDriver,lpParameter,0,
                             local_res10);
      if (hObject == (HANDLE)0x0) {
        Sleep(2000);
        hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,SendAddNcbToDriver,lpParameter,0,
                               local_res10);
        if (hObject == (HANDLE)0x0) {
          AddNameThreadExit();
          *(undefined4 *)plVar22 = 0;
          *(undefined1 *)((longlong)plVar22 + -0x47) = 9;
          PostRoutineCaller((char *)lpParameter,(int *)plVar22);
          goto LAB_18000256e;
        }
      }
      CloseHandle(hObject);
      goto LAB_18000256e;
    }
    SendNcbToDriver(lpParameter);
  } while( true );
  LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
  goto LAB_180002548;
}



===== PostRoutineCaller @ 180002810 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void PostRoutineCaller(char *param_1,int *param_2)

{
  char cVar1;
  code *pcVar2;
  longlong lVar3;
  
  if (*param_2 == -0x7ffeffff) {
    HangupConnection((longlong)param_1);
  }
  pcVar2 = *(code **)(param_1 + 0x38);
  lVar3 = *(longlong *)(param_1 + 0x58);
  cVar1 = *param_1;
  param_1[0x41] = param_1[1];
  EnterCriticalSection((LPCRITICAL_SECTION)&Crit);
  param_1[0x42] = '\0';
  param_1[0x43] = '\0';
  LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
  if (lVar3 != 0) {
    NtSetEvent(lVar3,0);
  }
  if ((pcVar2 != (code *)0x0) && (cVar1 < '\0')) {
    (*pcVar2)(param_1);
  }
  return;
}



===== QueueToWorker @ 1800028bc =====

void QueueToWorker(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  DWORD DVar21;
  undefined8 *puVar22;
  longlong lVar23;
  undefined8 *puVar24;
  ulonglong uVar25;
  undefined1 *puVar26;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*(longlong *)(param_1 + 0x16) != 0) {
    NtResetEvent(*(longlong *)(param_1 + 0x16),0);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&Crit);
  puVar26 = auStack_28;
  if (*(short *)((longlong)param_1 + 0x42) == 0) {
    puVar24 = &WorkQueue;
    puVar22 = (undefined8 *)(param_1 + 0x12);
    puVar26 = auStack_28;
    if ((undefined8 *)*DAT_180007e18 != &WorkQueue) {
      puVar22 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      DAT_180007e18 = (undefined8 *)(*pcVar1)();
      puVar26 = auStack_20;
    }
    *puVar22 = puVar24;
    uVar25 = (ulonglong)g_dwNextQHEntry;
    puVar22[1] = DAT_180007e18;
    *DAT_180007e18 = puVar22;
    DAT_180007e18 = puVar22;
    *(undefined2 *)((longlong)param_1 + 0x42) = 1;
    *(undefined4 **)(&g_QueuedHistory + uVar25 * 0x78) = param_1;
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    uVar5 = param_1[4];
    uVar6 = param_1[5];
    uVar7 = param_1[6];
    uVar8 = param_1[7];
    uVar9 = param_1[8];
    uVar10 = param_1[9];
    uVar11 = param_1[10];
    uVar12 = param_1[0xb];
    uVar13 = param_1[0xc];
    uVar14 = param_1[0xd];
    uVar15 = param_1[0xe];
    uVar16 = param_1[0xf];
    uVar17 = *(undefined8 *)(param_1 + 0x10);
    uVar18 = *(undefined8 *)(param_1 + 0x12);
    uVar19 = *(undefined8 *)(param_1 + 0x14);
    uVar20 = *(undefined8 *)(param_1 + 0x16);
    lVar23 = uVar25 * 0x78;
    *(undefined4 *)(&DAT_180007ee8 + lVar23) = *param_1;
    *(undefined4 *)(lVar23 + 0x180007eec) = uVar2;
    *(undefined4 *)(lVar23 + 0x180007ef0) = uVar3;
    *(undefined4 *)(lVar23 + 0x180007ef4) = uVar4;
    *(undefined4 *)(&DAT_180007ef8 + lVar23) = uVar5;
    *(undefined4 *)(lVar23 + 0x180007efc) = uVar6;
    *(undefined4 *)(lVar23 + 0x180007f00) = uVar7;
    *(undefined4 *)(lVar23 + 0x180007f04) = uVar8;
    *(undefined4 *)(&DAT_180007f08 + lVar23) = uVar9;
    *(undefined4 *)(lVar23 + 0x180007f0c) = uVar10;
    *(undefined4 *)(lVar23 + 0x180007f10) = uVar11;
    *(undefined4 *)(lVar23 + 0x180007f14) = uVar12;
    *(undefined4 *)(&DAT_180007f18 + lVar23) = uVar13;
    *(undefined4 *)(lVar23 + 0x180007f1c) = uVar14;
    *(undefined4 *)(lVar23 + 0x180007f20) = uVar15;
    *(undefined4 *)(lVar23 + 0x180007f24) = uVar16;
    *(undefined8 *)(&DAT_180007f28 + lVar23) = uVar17;
    *(undefined8 *)(lVar23 + 0x180007f30) = uVar18;
    *(undefined8 *)(&DAT_180007f38 + lVar23) = uVar19;
    *(undefined8 *)(lVar23 + 0x180007f40) = uVar20;
    *(undefined8 *)(puVar26 + -8) = 0x180002989;
    DVar21 = GetTickCount();
    *(DWORD *)(&DAT_180007f48 + (ulonglong)g_dwNextQHEntry * 0x78) = DVar21;
    *(undefined8 *)(puVar26 + -8) = 0x1800029a3;
    DVar21 = GetCurrentThreadId();
    *(DWORD *)(&DAT_180007f4c + (ulonglong)g_dwNextQHEntry * 0x78) = DVar21;
    g_dwNextQHEntry = g_dwNextQHEntry + 1 & 0xf;
  }
  *(undefined8 *)(puVar26 + -8) = 0x1800029d3;
  LeaveCriticalSection((LPCRITICAL_SECTION)&Crit);
                    /* WARNING: Could not recover jumptable at 0x0001800029eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NtSetEvent(Event,0);
  return;
}



===== SendAddNcbToDriver @ 180002a00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 SendAddNcbToDriver(byte *param_1)

{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  longlong lVar4;
  undefined2 uVar5;
  int iVar6;
  byte bVar7;
  undefined8 uVar8;
  undefined8 local_res20;
  ulonglong in_stack_ffffffffffffff98;
  
  local_res20 = 0;
  bVar2 = *param_1;
  pcVar3 = *(code **)(param_1 + 0x38);
  lVar4 = *(longlong *)(param_1 + 0x58);
  iVar6 = NtCreateEvent(&local_res20,0x1f0003,0,1,in_stack_ffffffffffffff98 & 0xffffffffffffff00);
  if (iVar6 < 0) {
    param_1[1] = 9;
    pbVar1 = param_1 + 0x48;
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    PostRoutineCaller((char *)param_1,(int *)pbVar1);
    AddNameThreadExit();
    return 0;
  }
  *param_1 = *param_1 & 0x7f;
  if (*param_1 == 0x33) {
    uVar8 = *(undefined8 *)(param_1 + 8);
    uVar5 = *(undefined2 *)(param_1 + 0x10);
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
  }
  iVar6 = NtDeviceIoControlFile
                    (NB,local_res20,0,0,param_1 + 0x48,0x210053,param_1,0x60,uVar8,uVar5,uVar8);
  if (((iVar6 == 0) || (iVar6 == 0x103)) || (iVar6 == -0x7ffeffff)) {
    do {
      do {
        iVar6 = NtWaitForSingleObject(local_res20,1,0);
      } while (iVar6 == 0xc0);
    } while (iVar6 == 0x101);
  }
  else {
    bVar7 = 0x40;
    if (iVar6 == -0x3ffffffb) {
      bVar7 = 1;
    }
    param_1[1] = bVar7;
  }
  *param_1 = bVar2;
  param_1[0x41] = param_1[1];
  if (lVar4 != 0) {
    NtSetEvent(lVar4,0);
  }
  if ((pcVar3 != (code *)0x0) && ((char)bVar2 < '\0')) {
    (*pcVar3)(param_1);
  }
  NtClose();
  AddNameThreadExit();
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



===== SendNcbToDriver @ 180002bc0 =====

void SendNcbToDriver(byte *param_1)

{
  void *_Src;
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  HANDLE hHeap;
  undefined8 *puVar6;
  undefined8 *puVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  undefined1 *puVar11;
  ushort uVar12;
  undefined8 uVar13;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  byte *local_58;
  undefined4 local_50;
  byte *local_48;
  undefined4 local_40;
  undefined8 *local_38;
  int local_30;
  
  puVar11 = auStack_78;
  uVar9 = *param_1 & 0xffffff7f;
  if (uVar9 < 0x33) {
    if (uVar9 != 0x32) {
      if (((uVar9 == 0x14) || (uVar9 == 0x15)) || (uVar9 == 0x16)) goto LAB_180002f12;
      if (uVar9 == 0x17) {
LAB_180002dc5:
        puVar7 = (undefined8 *)
                 RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                 (ulonglong)*(ushort *)(param_1 + 0x10) +
                                 (ulonglong)*(ushort *)(param_1 + 0x12) + 8);
        puVar11 = auStack_78;
        if (puVar7 != (undefined8 *)0x0) {
          *puVar7 = *(undefined8 *)(param_1 + 8);
          _Src = *(void **)(param_1 + 8);
          *(undefined8 **)(param_1 + 8) = puVar7;
          memmove(puVar7 + 1,_Src,(ulonglong)*(ushort *)(param_1 + 0x10));
          memmove((void *)((ulonglong)*(ushort *)(param_1 + 0x10) + 8 + (longlong)puVar7),
                  *(void **)(param_1 + 0x14),(ulonglong)*(ushort *)(param_1 + 0x12));
          local_30 = (uint)*(ushort *)(param_1 + 0x12) + (uint)*(ushort *)(param_1 + 0x10);
          local_40 = 0x60;
          local_50 = 0x210053;
          local_58 = param_1 + 0x48;
          local_48 = param_1;
          local_38 = puVar7 + 1;
          iVar10 = NtDeviceIoControlFile(NB,0,ChainSendPostRoutine,param_1);
          if (iVar10 == 0) {
            return;
          }
          if (iVar10 == 0x103) {
            return;
          }
          if (iVar10 == -0x7ffeffff) {
            return;
          }
          bVar8 = 0x40;
          if (iVar10 == -0x3ffffffb) {
            bVar8 = 1;
          }
          param_1[1] = bVar8;
          ChainSendPostRoutine((char *)param_1,(int *)(param_1 + 0x48));
          return;
        }
        param_1[1] = 9;
        param_1[0x41] = 9;
        param_1[0x48] = 0;
        param_1[0x49] = 0;
        param_1[0x4a] = 0;
        param_1[0x4b] = 0;
        goto LAB_180002f92;
      }
      if ((uVar9 == 0x20) || (uVar9 == 0x21)) goto LAB_180002f12;
      iVar10 = uVar9 - 0x22;
LAB_180002da9:
      if ((iVar10 == 0) || (iVar10 == 1)) goto LAB_180002f12;
      uVar13 = 0;
      uVar12 = 0;
      goto LAB_180002f1b;
    }
    uVar13 = 0;
    uVar12 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&ResetCS);
    puVar11 = auStack_78;
    if ((undefined8 **)LanaResetList == &LanaResetList) {
LAB_180002c7c:
      hHeap = GetProcessHeap();
      puVar6 = HeapAlloc(hHeap,0,0x70);
      if (puVar6 == (undefined8 *)0x0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&ResetCS);
        goto LAB_180002f1b;
      }
      memset(puVar6 + 2,0,0x60);
      puVar11 = auStack_78;
      puVar6[1] = puVar6;
      *puVar6 = puVar6;
      uVar5 = *(undefined8 *)(param_1 + 8);
      puVar6[2] = *(undefined8 *)param_1;
      puVar6[3] = uVar5;
      uVar5 = *(undefined8 *)(param_1 + 0x18);
      puVar6[4] = *(undefined8 *)(param_1 + 0x10);
      puVar6[5] = uVar5;
      uVar2 = *(undefined4 *)(param_1 + 0x24);
      uVar3 = *(undefined4 *)(param_1 + 0x28);
      uVar4 = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(puVar6 + 6) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)((longlong)puVar6 + 0x34) = uVar2;
      *(undefined4 *)(puVar6 + 7) = uVar3;
      *(undefined4 *)((longlong)puVar6 + 0x3c) = uVar4;
      uVar2 = *(undefined4 *)(param_1 + 0x34);
      uVar3 = *(undefined4 *)(param_1 + 0x38);
      uVar4 = *(undefined4 *)(param_1 + 0x3c);
      *(undefined4 *)(puVar6 + 8) = *(undefined4 *)(param_1 + 0x30);
      *(undefined4 *)((longlong)puVar6 + 0x44) = uVar2;
      *(undefined4 *)(puVar6 + 9) = uVar3;
      *(undefined4 *)((longlong)puVar6 + 0x4c) = uVar4;
      *(byte *)(puVar6 + 10) = param_1[0x40];
      if ((undefined8 **)*DAT_180007e38 != &LanaResetList) {
        pcVar1 = (code *)swi(0x29);
        DAT_180007e38 = (undefined8 *)(*pcVar1)(3);
        puVar11 = auStack_70;
      }
      *puVar6 = &LanaResetList;
      puVar6[1] = DAT_180007e38;
      *DAT_180007e38 = puVar6;
      DAT_180007e38 = puVar6;
    }
    else {
      puVar7 = LanaResetList;
      do {
        puVar6 = puVar7;
        puVar7 = puVar6;
        if (*(byte *)(puVar6 + 10) == param_1[0x40]) break;
        puVar7 = (undefined8 *)*puVar6;
      } while ((undefined8 **)puVar7 != &LanaResetList);
      if ((undefined8 **)puVar7 == &LanaResetList) goto LAB_180002c7c;
      uVar5 = *(undefined8 *)(param_1 + 8);
      puVar6[2] = *(undefined8 *)param_1;
      puVar6[3] = uVar5;
      uVar5 = *(undefined8 *)(param_1 + 0x18);
      puVar6[4] = *(undefined8 *)(param_1 + 0x10);
      puVar6[5] = uVar5;
      uVar2 = *(undefined4 *)(param_1 + 0x24);
      uVar3 = *(undefined4 *)(param_1 + 0x28);
      uVar4 = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(puVar6 + 6) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)((longlong)puVar6 + 0x34) = uVar2;
      *(undefined4 *)(puVar6 + 7) = uVar3;
      *(undefined4 *)((longlong)puVar6 + 0x3c) = uVar4;
      uVar5 = *(undefined8 *)(param_1 + 0x38);
      puVar6[8] = *(undefined8 *)(param_1 + 0x30);
      puVar6[9] = uVar5;
      *(byte *)(puVar6 + 10) = param_1[0x40];
    }
    puVar6[0xd] = 0;
    puVar6[9] = 0;
    *(byte *)(puVar6 + 2) = *param_1 | 0x80;
    *(undefined8 *)(puVar11 + -8) = 0x180002d6a;
    LeaveCriticalSection((LPCRITICAL_SECTION)&ResetCS);
  }
  else {
    if ((uVar9 != 0x33) && (uVar9 != 0x34)) {
      if (uVar9 == 0x35) {
        uVar13 = *(undefined8 *)(param_1 + 8);
        uVar12 = 0x60;
        goto LAB_180002f21;
      }
      if ((uVar9 != 0x37) && (uVar9 != 0x71)) {
        if (uVar9 != 0x72) {
          iVar10 = uVar9 - 0x77;
          goto LAB_180002da9;
        }
        goto LAB_180002dc5;
      }
    }
LAB_180002f12:
    uVar13 = *(undefined8 *)(param_1 + 8);
    uVar12 = *(ushort *)(param_1 + 0x10);
LAB_180002f1b:
    puVar11 = auStack_78;
  }
LAB_180002f21:
  *(uint *)(puVar11 + 0x48) = (uint)uVar12;
  *(undefined8 *)(puVar11 + 0x40) = uVar13;
  *(undefined4 *)(puVar11 + 0x38) = 0x60;
  *(byte **)(puVar11 + 0x30) = param_1;
  *(undefined4 *)(puVar11 + 0x28) = 0x210053;
  *(byte **)(puVar11 + 0x20) = param_1 + 0x48;
  *(undefined8 *)(puVar11 + -8) = 0x180002f63;
  iVar10 = NtDeviceIoControlFile(NB,0,PostRoutineCaller,param_1);
  if (iVar10 == 0) {
    return;
  }
  if (iVar10 == 0x103) {
    return;
  }
  if (iVar10 == -0x7ffeffff) {
    return;
  }
  bVar8 = 0x40;
  if (iVar10 == -0x3ffffffb) {
    bVar8 = 1;
  }
  param_1[1] = bVar8;
LAB_180002f92:
  *(undefined8 *)(puVar11 + -8) = 0x180002f9d;
  PostRoutineCaller((char *)param_1,(int *)(param_1 + 0x48));
  return;
}



===== StartNB @ 180002fc0 =====

void StartNB(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  *(undefined8 *)(param_1 + 4) = param_2;
  *param_1 = 0x30;
  *(undefined8 *)(param_1 + 2) = 0;
  param_1[6] = 0x40;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 10) = 0;
  NtCreateFile(&NB,0xc0000000,param_1,param_3,0,0x80,7,3,0,0,0);
  return;
}



===== StartNetBIOSDriver @ 180003038 =====

DWORD StartNetBIOSDriver(void)

{
  DWORD DVar1;
  BOOL BVar2;
  SC_HANDLE hSCManager;
  SC_HANDLE hService;
  
  DVar1 = 0;
  hSCManager = OpenSCManagerW((LPCWSTR)0x0,(LPCWSTR)0x0,1);
  if (hSCManager != (SC_HANDLE)0x0) {
    hService = OpenServiceW(hSCManager,L"netbios",0x10);
    if (hService != (SC_HANDLE)0x0) {
      BVar2 = StartServiceW(hService,0,(LPCWSTR *)0x0);
      if (BVar2 == 0) {
        DVar1 = GetLastError();
      }
      CloseServiceHandle(hService);
      CloseServiceHandle(hSCManager);
      return DVar1;
    }
    CloseServiceHandle(hSCManager);
  }
  DVar1 = GetLastError();
  return DVar1;
}



===== DllMain @ 180003108 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllMain(HMODULE param_1,int param_2,longlong param_3)

{
  undefined8 in_RAX;
  
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    in_RAX = NetbiosInitialize(param_1);
    if ((char)in_RAX == '\0') {
      return in_RAX;
    }
    _DAT_180007634 = _DAT_180007634 | 1;
  }
  else if (((param_2 == 0) && (param_3 == 0)) && ((_DAT_180007634 & 1) != 0)) {
    in_RAX = NetbiosDelete();
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== __delayLoadHelper2 @ 180003160 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(0x180000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== __GSHandlerCheck @ 1800031a4 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1800031c8 =====

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



===== memmove @ 180003229 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180003229. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



===== memset @ 180003235 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180003235. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== __security_check_cookie @ 180003260 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1800032a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1800032d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001800032d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 180003300 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== __DllMainCRTStartup$filt$0 @ 180003310 =====

undefined4 __DllMainCRTStartup_filt_0(undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined8 **)(param_2 + 0x108) = param_1;
  uVar1 = *(undefined4 *)*param_1;
  *(undefined4 *)(param_2 + 0xa4) = uVar1;
  *(undefined8 **)(param_2 + 200) = param_1;
  *(undefined4 *)(param_2 + 0x28) = uVar1;
  if (*(int *)(param_2 + 0x28) == -0x1f928c9d) {
    iVar2 = _XcptFilter(*(ulong *)(param_2 + 0x28),*(_EXCEPTION_POINTERS **)(param_2 + 200));
    *(int *)(param_2 + 0x30) = iVar2;
  }
  else {
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  return *(undefined4 *)(param_2 + 0x30);
}



===== __DllMainCRTStartup$filt$1 @ 180003364 =====

undefined4 __DllMainCRTStartup_filt_1(undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined8 **)(param_2 + 0x110) = param_1;
  uVar1 = *(undefined4 *)*param_1;
  *(undefined4 *)(param_2 + 0xa8) = uVar1;
  *(undefined8 **)(param_2 + 0xd0) = param_1;
  *(undefined4 *)(param_2 + 0x38) = uVar1;
  if (*(int *)(param_2 + 0x38) == -0x1f928c9d) {
    iVar2 = _XcptFilter(*(ulong *)(param_2 + 0x38),*(_EXCEPTION_POINTERS **)(param_2 + 0xd0));
    *(int *)(param_2 + 0x40) = iVar2;
  }
  else {
    *(undefined4 *)(param_2 + 0x40) = 0;
  }
  return *(undefined4 *)(param_2 + 0x40);
}



===== __DllMainCRTStartup$filt$2 @ 1800033b8 =====

undefined4 __DllMainCRTStartup_filt_2(undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined8 **)(param_2 + 0x118) = param_1;
  uVar1 = *(undefined4 *)*param_1;
  *(undefined4 *)(param_2 + 0xac) = uVar1;
  *(undefined8 **)(param_2 + 0xd8) = param_1;
  *(undefined4 *)(param_2 + 0x48) = uVar1;
  if (*(int *)(param_2 + 0x48) == -0x1f928c9d) {
    iVar2 = _XcptFilter(*(ulong *)(param_2 + 0x48),*(_EXCEPTION_POINTERS **)(param_2 + 0xd8));
    *(int *)(param_2 + 0x50) = iVar2;
  }
  else {
    *(undefined4 *)(param_2 + 0x50) = 0;
  }
  return *(undefined4 *)(param_2 + 0x50);
}



===== __DllMainCRTStartup$filt$3 @ 18000340c =====

undefined4 __DllMainCRTStartup_filt_3(undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined8 **)(param_2 + 0x120) = param_1;
  uVar1 = *(undefined4 *)*param_1;
  *(undefined4 *)(param_2 + 0xb0) = uVar1;
  *(undefined8 **)(param_2 + 0xe0) = param_1;
  *(undefined4 *)(param_2 + 0x58) = uVar1;
  if (*(int *)(param_2 + 0x58) == -0x1f928c9d) {
    iVar2 = _XcptFilter(*(ulong *)(param_2 + 0x58),*(_EXCEPTION_POINTERS **)(param_2 + 0xe0));
    *(int *)(param_2 + 0x60) = iVar2;
  }
  else {
    *(undefined4 *)(param_2 + 0x60) = 0;
  }
  return *(undefined4 *)(param_2 + 0x60);
}



===== __DllMainCRTStartup$filt$4 @ 180003460 =====

undefined4 __DllMainCRTStartup_filt_4(undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined8 **)(param_2 + 0x128) = param_1;
  uVar1 = *(undefined4 *)*param_1;
  *(undefined4 *)(param_2 + 0xb4) = uVar1;
  *(undefined8 **)(param_2 + 0xe8) = param_1;
  *(undefined4 *)(param_2 + 0x68) = uVar1;
  if (*(int *)(param_2 + 0x68) == -0x1f928c9d) {
    iVar2 = _XcptFilter(*(ulong *)(param_2 + 0x68),*(_EXCEPTION_POINTERS **)(param_2 + 0xe8));
    *(int *)(param_2 + 0x70) = iVar2;
  }
  else {
    *(undefined4 *)(param_2 + 0x70) = 0;
  }
  return *(undefined4 *)(param_2 + 0x70);
}



===== __DllMainCRTStartup$filt$5 @ 1800034b4 =====

undefined4 __DllMainCRTStartup_filt_5(undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined8 **)(param_2 + 0x130) = param_1;
  uVar1 = *(undefined4 *)*param_1;
  *(undefined4 *)(param_2 + 0xb8) = uVar1;
  *(undefined8 **)(param_2 + 0xf0) = param_1;
  *(undefined4 *)(param_2 + 0x78) = uVar1;
  if (*(int *)(param_2 + 0x78) == -0x1f928c9d) {
    iVar2 = _XcptFilter(*(ulong *)(param_2 + 0x78),*(_EXCEPTION_POINTERS **)(param_2 + 0xf0));
    *(int *)(param_2 + 0x80) = iVar2;
  }
  else {
    *(undefined4 *)(param_2 + 0x80) = 0;
  }
  return *(undefined4 *)(param_2 + 0x80);
}



===== __DllMainCRTStartup$filt$6 @ 180003511 =====

undefined4 __DllMainCRTStartup_filt_6(undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined8 **)(param_2 + 0x138) = param_1;
  uVar1 = *(undefined4 *)*param_1;
  *(undefined4 *)(param_2 + 0xbc) = uVar1;
  *(undefined8 **)(param_2 + 0xf8) = param_1;
  *(undefined4 *)(param_2 + 0x88) = uVar1;
  if (*(int *)(param_2 + 0x88) == -0x1f928c9d) {
    iVar2 = _XcptFilter(*(ulong *)(param_2 + 0x88),*(_EXCEPTION_POINTERS **)(param_2 + 0xf8));
    *(int *)(param_2 + 0x90) = iVar2;
  }
  else {
    *(undefined4 *)(param_2 + 0x90) = 0;
  }
  return *(undefined4 *)(param_2 + 0x90);
}



===== __DllMainCRTStartup$filt$7 @ 180003577 =====

undefined4 __DllMainCRTStartup_filt_7(undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined8 **)(param_2 + 0x140) = param_1;
  uVar1 = *(undefined4 *)*param_1;
  *(undefined4 *)(param_2 + 0xc0) = uVar1;
  *(undefined8 **)(param_2 + 0x100) = param_1;
  *(undefined4 *)(param_2 + 0x98) = uVar1;
  if (*(int *)(param_2 + 0x98) == -0x1f928c9d) {
    iVar2 = _XcptFilter(*(ulong *)(param_2 + 0x98),*(_EXCEPTION_POINTERS **)(param_2 + 0x100));
    *(int *)(param_2 + 0xa0) = iVar2;
  }
  else {
    *(undefined4 *)(param_2 + 0xa0) = 0;
  }
  return *(undefined4 *)(param_2 + 0xa0);
}



===== __DllMainCRTStartup$fin$8 @ 1800035dd =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __DllMainCRTStartup_fin_8(undefined8 param_1,longlong param_2)

{
  if (*(uint *)(param_2 + 0x178) < 2) {
    ___native_dllmain_reason = 0xffffffff;
  }
  return;
}



===== _IsNonwritableInCurrentImage$filt$0 @ 180003610 =====

bool _IsNonwritableInCurrentImage_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 180004010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


