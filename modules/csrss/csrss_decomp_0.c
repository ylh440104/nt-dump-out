
===== entry @ 140001010 =====

void entry(longlong param_1)

{
  code *pcVar1;
  
  __security_init_cookie();
  NtProcessStartup_AfterSecurityCookieInitialized(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== NtProcessStartup_AfterSecurityCookieInitialized @ 140001030 =====

void NtProcessStartup_AfterSecurityCookieInitialized(longlong param_1)

{
  uint uVar1;
  short sVar2;
  code *pcVar3;
  longlong lVar4;
  char **ppcVar5;
  short *psVar6;
  int iVar7;
  char **ppcVar8;
  char **ppcVar9;
  char **ppcVar10;
  uint uVar11;
  char **ppcVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  uint uVar16;
  int local_res8;
  int local_res10;
  int local_res18;
  char *local_res20;
  char **local_68;
  undefined8 local_60;
  char *pcStack_58;
  
  local_res20 = (char *)0x0;
  local_60 = 0;
  pcStack_58 = (char *)0x0;
  lVar4 = RtlNormalizeProcessParams(*(undefined8 *)(param_1 + 0x20));
  iVar7 = 1;
  local_res10 = 0;
  local_res8 = 0;
  local_res18 = 0;
  local_68 = &local_res20;
  pcVar13 = (char *)0x0;
  pcVar15 = (char *)0x0;
  uVar16 = 0;
  uVar11 = 1;
  if (lVar4 == 0) {
LAB_1400010e0:
    uVar1 = iVar7 + uVar11;
    if (2 < uVar1) {
      if (1 < uVar11) {
        uVar16 = (uint)(ushort)local_60;
        pcVar15 = pcStack_58;
      }
      ppcVar5 = (char **)RtlAllocateHeap(*(undefined8 *)(param_1 + 0x30),0,
                                         pcVar13 + (ulonglong)uVar1 * 8);
      if (ppcVar5 == (char **)0x0) {
        ppcVar12 = &local_res20;
        local_res18 = -0x3fffffe9;
      }
      else {
        ppcVar12 = ppcVar5;
        if (1 < uVar11) {
          ppcVar10 = ppcVar5 + uVar1;
          ppcVar8 = (char **)(pcVar13 + (ulonglong)uVar1 * 8 + (longlong)ppcVar5);
          while ((((uVar16 != 0 && (*pcVar15 != '\0')) && (ppcVar10 < ppcVar8)) && (uVar16 != 0))) {
            do {
              if (*pcVar15 == '\0') goto LAB_140001388;
              iVar7 = isspace((int)*pcVar15);
              if (iVar7 == 0) break;
              pcVar15 = pcVar15 + 1;
              uVar16 = uVar16 - 1;
            } while (uVar16 != 0);
            if (uVar16 == 0) break;
LAB_140001388:
            if (*pcVar15 != '\0') {
              *ppcVar12 = (char *)ppcVar10;
              ppcVar12 = ppcVar12 + 1;
              local_res8 = local_res8 + 1;
              ppcVar9 = ppcVar10;
              do {
                ppcVar10 = ppcVar9;
                *(char *)ppcVar10 = *pcVar15;
                pcVar15 = pcVar15 + 1;
                ppcVar9 = (char **)((longlong)ppcVar10 + 1);
                uVar16 = uVar16 - 1;
                if (uVar16 == 0) break;
                if (ppcVar8 <= ppcVar9) goto LAB_1400013db;
                iVar7 = isspace((int)*pcVar15);
              } while (iVar7 == 0);
              if (ppcVar9 < ppcVar8) {
                *(char *)ppcVar9 = '\0';
                ppcVar10 = (char **)((longlong)ppcVar10 + 2);
              }
              else {
LAB_1400013db:
                *(char *)ppcVar10 = '\0';
              }
            }
          }
        }
        *ppcVar12 = (char *)0x0;
        ppcVar12 = ppcVar12 + 1;
        psVar6 = *(short **)(lVar4 + 0x80);
        ppcVar8 = ppcVar12;
        if (psVar6 != (short *)0x0) {
          sVar2 = *psVar6;
          while (sVar2 != 0) {
            *ppcVar8 = (char *)psVar6;
            ppcVar8 = ppcVar8 + 1;
            psVar6 = psVar6 + 1;
            do {
              sVar2 = *psVar6;
              psVar6 = psVar6 + 1;
            } while (sVar2 != 0);
            sVar2 = *psVar6;
          }
        }
        *ppcVar8 = (char *)0x0;
        local_68 = ppcVar5;
      }
      goto LAB_140001172;
    }
  }
  else {
    psVar6 = (short *)(lVar4 + 0x70);
    local_res10 = *(int *)(lVar4 + 0xc);
    if ((*(longlong *)(lVar4 + 0x78) == 0) || (*psVar6 == 0)) {
      psVar6 = (short *)(lVar4 + 0x60);
      if (*(longlong *)(lVar4 + 0x68) != 0) goto LAB_14000121f;
LAB_1400010cb:
      iVar7 = 0;
      psVar6 = *(short **)(lVar4 + 0x80);
      if (psVar6 != (short *)0x0) {
        sVar2 = *psVar6;
        while (sVar2 != 0) {
          psVar6 = psVar6 + 1;
          iVar7 = iVar7 + 1;
          do {
            sVar2 = *psVar6;
            psVar6 = psVar6 + 1;
          } while (sVar2 != 0);
          sVar2 = *psVar6;
        }
      }
      iVar7 = iVar7 + 1;
      goto LAB_1400010e0;
    }
LAB_14000121f:
    local_res18 = RtlUnicodeStringToAnsiString(&local_60,psVar6,1);
    if (-1 < local_res18) {
      uVar16 = (uint)(ushort)local_60;
      pcVar15 = pcStack_58;
      if ((ushort)local_60 != 0) {
        do {
          if ((*pcVar15 == '\0') || (uVar16 == 0)) break;
          do {
            pcVar14 = pcVar15;
            if (*pcVar15 == '\0') goto LAB_14000128d;
            iVar7 = isspace((int)*pcVar15);
            if (iVar7 == 0) break;
            pcVar15 = pcVar15 + 1;
            uVar16 = uVar16 - 1;
          } while (uVar16 != 0);
          pcVar14 = pcVar15;
          if (uVar16 == 0) break;
LAB_14000128d:
          pcVar15 = pcVar14;
          if (*pcVar14 != '\0') {
            uVar11 = uVar11 + 1;
            do {
              pcVar15 = pcVar15 + 1;
              uVar16 = uVar16 - 1;
              if (uVar16 == 0) break;
              iVar7 = isspace((int)*pcVar15);
            } while (iVar7 == 0);
            pcVar13 = pcVar15 + (longlong)(pcVar13 + (1 - (longlong)pcVar14));
          }
        } while (uVar16 != 0);
      }
      goto LAB_1400010cb;
    }
  }
  local_res8 = 0;
  ppcVar12 = &local_res20;
LAB_140001172:
  RtlFreeAnsiString(&local_60);
  if (local_res10 != 0) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  if (-1 < local_res18) {
    local_res18 = main(local_res8,local_68,ppcVar12);
  }
  NtTerminateProcess(0xffffffffffffffff,local_res18);
  return;
}



===== __report_gsfailure @ 140001430 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  DWORD64 unaff_retaddr;
  uintptr_t local_res8 [4];
  ulonglong local_38 [2];
  PVOID local_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  local_38[1] = 0;
  local_28 = (PVOID)0x0;
  local_38[0] = 0;
  local_res8[0] = _StackCookie;
  RtlCaptureContext(&DAT_1400030c0);
  ControlPc = DAT_1400031b8;
  FunctionEntry = RtlLookupFunctionEntry(DAT_1400031b8,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    _DAT_140003158 = local_res8;
    DAT_1400031b8 = unaff_retaddr;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_1400030c0,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_140003030 = DAT_1400031b8;
  _DAT_140003140 = local_res8[0];
  _DAT_140003020 = 0xc0000409;
  _DAT_140003024 = 1;
  _DAT_140003038 = 1;
  DAT_140003040 = 2;
  uStack_20 = __security_cookie;
  uStack_18 = __security_cookie_complement;
  RtlUnhandledExceptionFilter(&PTR_DAT_140002000);
  NtTerminateProcess(0xffffffffffffffff,0xc0000409);
  return;
}



===== __security_init_cookie @ 1400015ac =====

void __cdecl __security_init_cookie(void)

{
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    __security_init_cookie_ex(&__security_cookie);
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== __security_init_cookie_ex @ 1400015f8 =====

void __security_init_cookie_ex(ulonglong *param_1)

{
  ulonglong uVar1;
  undefined8 in_RAX;
  
  uVar1 = rdtsc();
  *param_1 = ((CONCAT44((int)((ulonglong)in_RAX >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000)
              >> 4 ^ (ulonglong)param_1) & 0xffffffffffff;
  if ((*param_1 == 0) || (*param_1 == 0x2b992ddfa232)) {
    *param_1 = 0x2b992ddfa233;
  }
  return;
}



===== NtTerminateProcess @ 14000165c =====

void NtTerminateProcess(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000165c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NtTerminateProcess();
  return;
}



===== RtlCaptureContext @ 140001668 =====

void RtlCaptureContext(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001668. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlCaptureContext();
  return;
}



===== RtlLookupFunctionEntry @ 140001674 =====

PRUNTIME_FUNCTION __stdcall
RtlLookupFunctionEntry(DWORD64 ControlPc,PDWORD64 ImageBase,PUNWIND_HISTORY_TABLE HistoryTable)

{
  PRUNTIME_FUNCTION p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001674. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = RtlLookupFunctionEntry(ControlPc,ImageBase,HistoryTable);
  return p_Var1;
}



===== RtlVirtualUnwind @ 140001680 =====

PEXCEPTION_ROUTINE __stdcall
RtlVirtualUnwind(DWORD HandlerType,DWORD64 ImageBase,DWORD64 ControlPc,
                PRUNTIME_FUNCTION FunctionEntry,PCONTEXT ContextRecord,PVOID *HandlerData,
                PDWORD64 EstablisherFrame,PKNONVOLATILE_CONTEXT_POINTERS ContextPointers)

{
  PEXCEPTION_ROUTINE puVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001680. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar1 = RtlVirtualUnwind(HandlerType,ImageBase,ControlPc,FunctionEntry,ContextRecord,HandlerData,
                            EstablisherFrame,ContextPointers);
  return puVar1;
}



===== RtlUnhandledExceptionFilter @ 14000168c =====

void RtlUnhandledExceptionFilter(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000168c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnhandledExceptionFilter();
  return;
}



===== main @ 140001698 =====

int __cdecl main(int _Argc,char **_Argv,char **_Env)

{
  int iVar1;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_18 [2];
  undefined4 local_10;
  undefined4 local_c;
  
  local_res18[0] = 1;
  NtSetInformationProcess(0xffffffffffffffff,0x36,local_res18);
  RtlSetUnhandledExceptionFilter(CsrUnhandledExceptionFilter_exref);
  local_res20[0] = 0xd;
  NtSetInformationProcess(0xffffffffffffffff,5,local_res20,4);
  RtlSetHeapInformation(0,1,0,0);
  local_10 = 2;
  local_c = 1;
  NtSetInformationProcess(0xffffffffffffffff,0x34,&local_10,8);
  iVar1 = CsrServerInitialization(_Argc,_Argv);
  if (iVar1 < 0) {
    CsrFlushToBlackBoxRecorder();
    NtTerminateProcess(0xffffffffffffffff,iVar1);
  }
  local_18[0] = 0;
  NtSetInformationProcess(0xffffffffffffffff,0xc,local_18);
  NtTerminateThread(0xfffffffffffffffe,iVar1);
  return 0;
}



===== _guard_check_icall @ 1400017e0 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140001800 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140001840 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140001870 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


