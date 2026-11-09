
===== _tlgWriteTransfer_EtwEventWriteTransfer @ 140001008 =====

void _tlgWriteTransfer_EtwEventWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = PTR_DAT_140030e50;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140030e50;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwEventWriteTransfer(DAT_140030e68,&local_18,0,0,param_5,param_6);
  return;
}



===== SmpLogFailureString @ 1400010b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpLogFailureString(longlong param_1,undefined4 param_2,longlong param_3,undefined4 param_4)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  longlong lVar4;
  undefined1 auStack_118 [32];
  char local_f8 [64];
  short local_b8 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  memset(local_f8,0,0xe0);
  if (param_3 != 0) {
    lVar4 = 0x40;
    psVar3 = local_b8;
    do {
      if ((lVar4 == -0x7fffffbe) ||
         (sVar1 = *(short *)((param_3 - (longlong)local_b8) + (longlong)psVar3), sVar1 == 0)) break;
      *psVar3 = sVar1;
      psVar3 = psVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    psVar2 = psVar3 + -1;
    if (lVar4 != 0) {
      psVar2 = psVar3;
    }
    *psVar2 = 0;
  }
  SmpInternalLogFailure(param_1,param_2,param_4,local_f8);
  return;
}



===== entry @ 140001190 =====

void entry(longlong param_1)

{
  code *pcVar1;
  
  __security_init_cookie();
  NtProcessStartupW_AfterSecurityCookieInitialized(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== NtProcessStartupW_AfterSecurityCookieInitialized @ 1400011b0 =====

void NtProcessStartupW_AfterSecurityCookieInitialized(longlong param_1)

{
  uint uVar1;
  wchar_t **ppwVar2;
  short sVar3;
  wchar_t wVar4;
  code *pcVar5;
  int iVar6;
  longlong lVar7;
  short *psVar8;
  wchar_t **ppwVar9;
  wchar_t *pwVar10;
  int iVar11;
  wchar_t **ppwVar12;
  wchar_t **ppwVar13;
  uint uVar14;
  ushort *puVar15;
  wchar_t **ppwVar16;
  longlong lVar17;
  wchar_t *pwVar18;
  uint uVar19;
  uint local_res8;
  int local_res10;
  wchar_t **local_res18;
  wchar_t *local_res20;
  
  local_res20 = (wchar_t *)0x0;
  lVar7 = RtlNormalizeProcessParams(*(undefined8 *)(param_1 + 0x20));
  ppwVar9 = (wchar_t **)0x0;
  local_res8 = 0;
  local_res10 = 0;
  local_res18 = &local_res20;
  iVar11 = 1;
  uVar14 = 1;
  lVar17 = 0;
  puVar15 = (ushort *)0x0;
  pwVar10 = (wchar_t *)0x0;
  uVar19 = 0;
  if (lVar7 != 0) {
    puVar15 = (ushort *)(lVar7 + 0x70);
    local_res8 = *(uint *)(lVar7 + 0xc);
    if (((*(longlong *)(lVar7 + 0x78) != 0) && (*puVar15 != 0)) ||
       (puVar15 = (ushort *)(lVar7 + 0x60), *(longlong *)(lVar7 + 0x68) != 0)) {
      uVar19 = (uint)*puVar15;
      pwVar10 = *(wchar_t **)(puVar15 + 4);
      if (uVar19 != 0) {
        do {
          if ((*pwVar10 == L'\0') || (uVar19 == 0)) break;
          do {
            pwVar18 = pwVar10;
            if (*pwVar10 == L'\0') goto LAB_140001494;
            iVar11 = iswspace(*pwVar10);
            if (iVar11 == 0) break;
            pwVar10 = pwVar10 + 1;
            uVar19 = uVar19 - 2;
          } while (uVar19 != 0);
          pwVar18 = pwVar10;
          if (uVar19 == 0) break;
LAB_140001494:
          pwVar10 = pwVar18;
          if (*pwVar18 != L'\0') {
            uVar14 = uVar14 + 1;
            do {
              pwVar10 = pwVar10 + 1;
              uVar19 = uVar19 - 2;
              if (uVar19 == 0) break;
              iVar11 = iswspace(*pwVar10);
            } while (iVar11 == 0);
            lVar17 = lVar17 + ((longlong)pwVar10 - (longlong)pwVar18 >> 1) * 2 + 2;
          }
        } while (uVar19 != 0);
      }
    }
    ppwVar9 = (wchar_t **)(ulonglong)local_res8;
    iVar11 = 0;
    psVar8 = *(short **)(lVar7 + 0x80);
    if (psVar8 != (short *)0x0) {
      sVar3 = *psVar8;
      while (sVar3 != 0) {
        psVar8 = psVar8 + 1;
        iVar11 = iVar11 + 1;
        do {
          sVar3 = *psVar8;
          psVar8 = psVar8 + 1;
        } while (sVar3 != 0);
        sVar3 = *psVar8;
      }
    }
    iVar11 = iVar11 + 1;
  }
  iVar6 = 0;
  uVar1 = iVar11 + uVar14;
  if (2 < uVar1) {
    if (1 < uVar14) {
      pwVar10 = *(wchar_t **)(puVar15 + 4);
      uVar19 = (uint)*puVar15;
    }
    lVar17 = lVar17 + (ulonglong)uVar1 * 8;
    ppwVar9 = (wchar_t **)RtlAllocateHeap(*(undefined8 *)(param_1 + 0x30),0,lVar17);
    if (ppwVar9 == (wchar_t **)0x0) {
      iVar6 = -0x3fffffe9;
    }
    else {
      ppwVar16 = ppwVar9;
      if (1 < uVar14) {
        ppwVar13 = ppwVar9 + uVar1;
        ppwVar2 = (wchar_t **)(lVar17 + (longlong)ppwVar9);
        if (uVar19 != 0) {
          local_res10 = 0;
          do {
            if (((ppwVar2 <= ppwVar13) || (*pwVar10 == L'\0')) || (uVar19 == 0)) break;
            do {
              if (*pwVar10 == L'\0') goto LAB_140001394;
              iVar11 = iswspace(*pwVar10);
              if (iVar11 == 0) break;
              pwVar10 = pwVar10 + 1;
              uVar19 = uVar19 - 2;
            } while (uVar19 != 0);
            if (uVar19 == 0) break;
LAB_140001394:
            if (*pwVar10 != L'\0') {
              *ppwVar16 = (wchar_t *)ppwVar13;
              ppwVar16 = ppwVar16 + 1;
              local_res10 = local_res10 + 1;
              ppwVar12 = ppwVar13;
              do {
                ppwVar13 = ppwVar12;
                *(wchar_t *)ppwVar13 = *pwVar10;
                pwVar10 = pwVar10 + 1;
                ppwVar12 = (wchar_t **)((longlong)ppwVar13 + 2);
                uVar19 = uVar19 - 2;
                if (uVar19 == 0) break;
                if (ppwVar2 <= ppwVar12) goto LAB_1400013f0;
                iVar11 = iswspace(*pwVar10);
              } while (iVar11 == 0);
              if (ppwVar12 < ppwVar2) {
                *(wchar_t *)ppwVar12 = L'\0';
                ppwVar13 = (wchar_t **)((longlong)ppwVar13 + 4);
              }
              else {
LAB_1400013f0:
                *(wchar_t *)ppwVar13 = L'\0';
              }
            }
          } while (uVar19 != 0);
        }
      }
      iVar6 = 0;
      *ppwVar16 = (wchar_t *)0x0;
      ppwVar16 = ppwVar16 + 1;
      pwVar10 = *(wchar_t **)(lVar7 + 0x80);
      if (pwVar10 != (wchar_t *)0x0) {
        wVar4 = *pwVar10;
        while (wVar4 != L'\0') {
          *ppwVar16 = pwVar10;
          ppwVar16 = ppwVar16 + 1;
          pwVar10 = pwVar10 + 1;
          do {
            wVar4 = *pwVar10;
            pwVar10 = pwVar10 + 1;
          } while (wVar4 != L'\0');
          wVar4 = *pwVar10;
        }
      }
      *ppwVar16 = (wchar_t *)0x0;
      local_res18 = ppwVar9;
    }
    ppwVar9 = (wchar_t **)(ulonglong)local_res8;
  }
  if ((int)ppwVar9 != 0) {
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  if (-1 < iVar6) {
    iVar6 = wmain(local_res10,local_res18,ppwVar9);
  }
                    /* WARNING: Could not recover jumptable at 0x000140001331. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NtTerminateProcess(0xffffffffffffffff,iVar6);
  return;
}



===== wmain @ 140001510 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl wmain(int _Argc,wchar_t **_Argv,wchar_t **_Env)

{
  undefined2 uVar1;
  wchar_t *pwVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int *piVar10;
  byte bVar11;
  undefined4 uVar12;
  undefined8 *puVar13;
  undefined1 *puVar14;
  int in_R9D;
  undefined8 *puVar15;
  undefined1 auStack_278 [8];
  undefined1 auStack_270 [56];
  undefined4 local_238;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined4 auStack_208 [4];
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined4 local_178;
  undefined4 local_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_278;
  local_1a0 = 0;
  uStack_198 = 0;
  local_190 = 0;
  uStack_188 = 0;
  local_180 = 0;
  local_178 = 0;
  local_230 = 0;
  uStack_228 = 0;
  local_238 = 0;
  uStack_1d8 = 0;
  uStack_1d0 = 0;
  local_1c8 = 0;
  local_58 = &local_230;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_1f8 = 2;
  local_1f4 = 1;
  NtSetInformationProcess(0xffffffffffffffff,0x34,&local_1f8,8);
  auStack_208[0] = 1;
  NtSetInformationProcess(0xffffffffffffffff,0x36,auStack_208,4);
  RtlSetHeapInformation(0,1,0,0);
  puVar14 = auStack_278;
  local_170 = *(undefined4 *)(PTR_DAT_140030e50 + -0x10);
  uStack_16c = *(undefined4 *)(PTR_DAT_140030e50 + -0xc);
  uStack_168 = *(undefined4 *)(PTR_DAT_140030e50 + -8);
  uStack_164 = *(undefined4 *)(PTR_DAT_140030e50 + -4);
  if (DAT_140030e68 != 0) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(5);
    puVar14 = auStack_270;
  }
  _DAT_140030e70 = 0;
  uRam0000000140030e78 = 0;
  *(undefined8 *)(puVar14 + -8) = 0x14000165f;
  iVar4 = EtwEventRegister(puVar14 + 0x108,_tlgEnableCallback,&DAT_140030e48,&DAT_140030e68);
  if (iVar4 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_140030e50;
    *(undefined8 *)(puVar14 + -8) = 0x140001684;
    EtwEventSetInformation(DAT_140030e68,2,PTR_DAT_140030e50,uVar1);
  }
  *(undefined8 *)(puVar14 + -8) = 0x1400016a3;
  iVar4 = EtwEventRegister(&SmssEventProvider,0,0,&SmpTraceHandle);
  if (iVar4 != 0) {
    SmpTraceHandle = 0;
  }
  _DAT_1400324f0 = 0;
  WPP_MAIN_CB = 0;
  _DAT_1400324f8 = 1;
  WPP_REGISTRATION_GUIDS = &WPP_ThisDir_CTLGUID_Smss;
  puVar13 = &WPP_MAIN_CB;
  WPP_GLOBAL_Control = (undefined *)&WPP_MAIN_CB;
  puVar15 = &WPP_REGISTRATION_GUIDS;
  do {
    uVar7 = *puVar15;
    puVar15 = puVar15 + 1;
    *(undefined8 *)(puVar14 + 0x60) = uVar7;
    *(undefined8 *)(puVar14 + 0x68) = 0;
    puVar13[4] = uVar7;
    *(undefined8 **)(puVar14 + 0x38) = puVar13 + 1;
    *(undefined8 *)(puVar14 + 0x30) = 0;
    *(undefined8 *)(puVar14 + 0x28) = 0;
    *(undefined1 **)(puVar14 + 0x20) = puVar14 + 0x60;
    *(undefined8 *)(puVar14 + -8) = 0x140001738;
    EtwRegisterTraceGuidsW(WppControlCallback,puVar13,uVar7,1);
    puVar13 = (undefined8 *)*puVar13;
  } while (puVar13 != (undefined8 *)0x0);
  *(undefined8 *)(puVar14 + -8) = 0x14000174c;
  iVar4 = RtlGetCurrentServiceSessionId();
  SmpHostSmss = iVar4 == 0;
  *(undefined8 *)(puVar14 + 0x118) = 0;
  *(undefined8 *)(puVar14 + 0x120) = 0;
  *(undefined8 *)(puVar14 + 0x128) = 0;
  *(undefined8 *)(puVar14 + 0x130) = 0;
  *(undefined8 *)(puVar14 + -8) = 0x140001786;
  NtQuerySystemInformation(0x5a,puVar14 + 0x118,0x20,0);
  bVar11 = (byte)*(ulonglong *)(puVar14 + 0x130);
  SmpSoftBoot = bVar11 >> 2 & 1;
  SmpSoftBootSystemHiveReady = bVar11 >> 5 & 1;
  SmpBugcheckRecovery = (byte)(*(ulonglong *)(puVar14 + 0x130) >> 0xe) & 1;
  if (1 < _Argc) {
    *(undefined8 *)(puVar14 + 0x60) = 0;
    *(undefined8 *)(puVar14 + 0x68) = 0;
    *(undefined4 *)(puVar14 + 0x58) = 0;
    if (in_R9D != 0) {
      SmpDebug = in_R9D;
    }
    SmpDefaultEnvironment = 0;
    uVar7 = *(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30);
    *(undefined8 *)(puVar14 + -8) = 0x140001807;
    RtlCreateTagHeap(uVar7,0,L"SMSC!",L"PARS");
    *(undefined8 *)(puVar14 + -8) = 0x14000181a;
    RtlInitUnicodeString(puVar14 + 0x60,0);
    *(undefined8 *)(puVar14 + -8) = 0x140001833;
    uVar7 = SmscpParseArgs(_Argc,(longlong)_Argv,(uint *)(puVar14 + 0x58),
                           (undefined2 *)(puVar14 + 0x60));
    puVar15 = SmscpSharedWindow;
    if ((int)uVar7 < 0) {
      if (*(longlong *)(puVar14 + 0x68) != 0) {
        uVar7 = *(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30);
        *(undefined8 *)(puVar14 + -8) = 0x140001859;
        RtlFreeHeap(uVar7,0,*(undefined8 *)(puVar14 + 0x68));
      }
LAB_14000185e:
      *(undefined8 *)(puVar14 + -8) = 0x140001870;
      return 0;
    }
    uVar7 = *SmscpSharedWindow;
    *SmscpSharedWindow = 0;
    puVar15[1] = 0;
    *(undefined4 *)SmscpSharedWindow = 0;
    *(undefined8 *)(puVar14 + -8) = 0x1400018ac;
    NtSetEvent(uVar7);
    *(undefined8 *)(puVar14 + 0x108) = 0xfffffffffd050f80;
    *(undefined8 *)(puVar14 + -8) = 0x1400018d2;
    iVar4 = RtlConnectToSm(0,0,0,&SmpApiConnectionPort);
    while (iVar4 < 0) {
      *(undefined8 *)(puVar14 + -8) = 0x1400018ef;
      SmpLogFailure(0x140022738,0x115,iVar4);
      *(undefined8 *)(puVar14 + -8) = 0x140001900;
      NtDelayExecution(0);
      *(undefined8 *)(puVar14 + 0x108) = 0xfffffffffd050f80;
      *(undefined8 *)(puVar14 + -8) = 0x140001926;
      iVar4 = RtlConnectToSm(0,0,0,&SmpApiConnectionPort);
    }
    uVar5 = *(uint *)((longlong)ProcessEnvironmentBlock + 0x2c0);
    *(undefined8 *)(puVar14 + -8) = 0x140001943;
    SmpLoadPnPSerializeSettings();
    *(undefined8 *)(puVar14 + -8) = 0x14000194a;
    iVar4 = SmscpLoadSubSystemsForMuSession(uVar5);
    if (iVar4 < 0) {
      *(undefined8 *)(puVar14 + -8) = 0x140001965;
      memset(puVar14 + 0x140,0,0xe0);
      uVar12 = 299;
    }
    else {
      *(undefined8 *)(puVar14 + -8) = 0x140001980;
      uVar8 = SmscpExecuteInitialCommand
                        (uVar5,(uint *)(puVar14 + 0x58),(undefined8 *)(puVar14 + 0x60));
      iVar4 = (int)uVar8;
      if (-1 < iVar4) goto LAB_14000185e;
      *(undefined8 *)(puVar14 + -8) = 0x14000199f;
      memset(puVar14 + 0x140,0,0xe0);
      uVar12 = 0x139;
    }
    *(undefined8 *)(puVar14 + -8) = 0x1400019bb;
    SmpInternalLogFailure(0x140022738,uVar12,iVar4,puVar14 + 0x140);
    *(undefined8 *)(puVar14 + -8) = 0x1400019c0;
    SmscpNotifySmOfFailure();
    pcVar3 = (code *)swi(3);
    iVar4 = (*pcVar3)();
    return iVar4;
  }
  SmpPrimarySmss = 1;
  *(undefined8 *)(puVar14 + -8) = 0x1400019cd;
  SmpReadyBootSync();
  pwVar2 = *_Argv;
  *(undefined8 *)(puVar14 + -8) = 0x1400019de;
  RtlInitUnicodeStringEx(&SmpHelperCmd,pwVar2);
  *(undefined8 *)(puVar14 + -8) = 0x1400019f1;
  RtlSetThreadIsCritical(1,0,0);
  *(undefined4 *)(puVar14 + 0x74) = 0xb;
  *(undefined8 *)(puVar14 + -8) = 0x140001a1b;
  NtSetInformationProcess(0xffffffffffffffff,5,puVar14 + 0x74);
  if ((DAT_7ffe02f0 & 0x20) != 0) {
    *(undefined4 *)(puVar14 + 0x40) = 0;
    *(undefined4 *)(puVar14 + 0x40) = 1;
    *(undefined4 *)(puVar14 + 0x40) = 3;
    *(undefined8 *)(puVar14 + -8) = 0x140001a5d;
    uVar5 = NtSetInformationProcess(0xffffffffffffffff,0x2d,puVar14 + 0x40);
    if ((int)uVar5 < 0) {
      *(undefined8 *)(puVar14 + -8) = 0x140001a7c;
      SmpLogFailure(0x14002a714,0x161,uVar5);
      *(undefined8 *)(puVar14 + -8) = 0x140001a8f;
      RtlInitUnicodeString(puVar14 + 0x48,L"Session Manager failed to set affinity update mode");
      *(ulonglong *)(puVar14 + 0x228) = (ulonglong)uVar5;
      goto LAB_140001f9e;
    }
  }
  if (in_R9D != 0) {
    SmpDebug = in_R9D;
  }
  *(undefined8 *)(puVar14 + 0xd0) = 0;
  *(undefined8 *)(puVar14 + 0x88) = 0;
  *(undefined8 *)(puVar14 + -8) = 0x140001acd;
  RtlInitializeSRWLock(puVar14 + 0xa0);
  *(undefined8 *)(puVar14 + -8) = 0x140001ae3;
  uVar5 = TpAllocPool(puVar14 + 0xa8,0);
  *(uint *)(puVar14 + 0x44) = uVar5;
  if ((int)uVar5 < 0) {
    *(undefined8 *)(puVar14 + -8) = 0x140001b06;
    SmpLogFailure(0x14002a714,0x17c,uVar5);
    *(undefined8 *)(puVar14 + -8) = 0x140001b19;
    RtlInitUnicodeString(puVar14 + 0x48,L"Thread pool allocation");
    _SmpInitProgressByLine = 0x186;
    _SmpInitLastCall = TpAllocPool_exref;
    uVar8 = (ulonglong)uVar5;
    *(ulonglong *)(puVar14 + 0x228) = (ulonglong)uVar5;
    _SmpInitReturnStatus = uVar5;
  }
  else {
    *(uint *)(puVar14 + 0xb0) = SmpNumberInitialSessions;
    *(undefined8 *)(puVar14 + -8) = 0x140001b6a;
    uVar5 = TpSetPoolMinThreads(*(undefined8 *)(puVar14 + 0xa8),SmpNumberInitialSessions + 1);
    uVar8 = (ulonglong)(int)uVar5;
    *(uint *)(puVar14 + 0x44) = uVar5;
    if ((int)uVar5 < 0) {
      *(undefined8 *)(puVar14 + -8) = 0x140001b8e;
      SmpLogFailure(0x14002a714,0x196,uVar5);
      *(undefined8 *)(puVar14 + -8) = 0x140001ba1;
      RtlInitUnicodeString(puVar14 + 0x48,L"Configuring thread pool minimum thread number");
      _SmpInitProgressByLine = 0x1a0;
      _SmpInitLastCall = TpSetPoolMinThreads_exref;
      *(ulonglong *)(puVar14 + 0x228) = uVar8;
      _SmpInitReturnStatus = uVar5;
    }
    else {
      _SmpCallbackEnviron = 3;
      uRam0000000140032530 = 0;
      _DAT_140032538 = 0;
      _DAT_140032540 = 0;
      uRam0000000140032548 = 0;
      _DAT_140032550 = 0;
      _DAT_140032558 = 0;
      _DAT_14003255c = 1;
      _DAT_140032560 = 0x48;
      _DAT_140032528 = *(undefined8 *)(puVar14 + 0xa8);
      *(undefined8 *)(puVar14 + -8) = 0x140001c31;
      uVar9 = SmpInit();
      if ((int)uVar9 < 0) {
        *(undefined8 *)(puVar14 + -8) = 0x140001c4b;
        SmpLogFailure(0x14002a714,0x1ac,(int)uVar9);
        *(undefined8 *)(puVar14 + -8) = 0x140001c5e;
        RtlInitUnicodeString(puVar14 + 0x48,L"Session Manager Initialization");
        uVar8 = uVar9 & 0xffffffff;
        *(ulonglong *)(puVar14 + 0x228) = uVar9 & 0xffffffff;
      }
      else {
        *(undefined **)(puVar14 + 0x20) = &SmpCallbackEnviron;
        *(undefined8 *)(puVar14 + -8) = 0x140001ca4;
        uVar5 = TpAllocAlpcCompletion
                          (puVar14 + 0xd0,SmpApiConnectionPort,SmpApiCallback,puVar14 + 0xa0);
        *(uint *)(puVar14 + 0x44) = uVar5;
        if ((int)uVar5 < 0) {
          *(undefined8 *)(puVar14 + -8) = 0x140001cc7;
          SmpLogFailure(0x14002a714,0x1be,uVar5);
          *(undefined8 *)(puVar14 + -8) = 0x140001cda;
          RtlInitUnicodeString(puVar14 + 0x48,L"ALPC Completion object allocation");
          _SmpInitProgressByLine = 0x1c8;
          _SmpInitLastCall = TpAllocAlpcCompletion_exref;
          uVar8 = (ulonglong)uVar5;
          *(ulonglong *)(puVar14 + 0x228) = (ulonglong)uVar5;
          _SmpInitReturnStatus = uVar5;
        }
        else {
          *(undefined8 *)(puVar14 + -8) = 0x140001d29;
          uVar5 = TpAllocWork(puVar14 + 0x88,SmpCreateInitialSession,0,&SmpCallbackEnviron);
          uVar8 = (ulonglong)(int)uVar5;
          *(uint *)(puVar14 + 0x44) = uVar5;
          if ((int)uVar5 < 0) {
            *(undefined8 *)(puVar14 + -8) = 0x140001d4d;
            SmpLogFailure(0x14002a714,0x1dc,uVar5);
            *(undefined8 *)(puVar14 + -8) = 0x140001d60;
            RtlInitUnicodeString(puVar14 + 0x48,L"Thread pool work object allocation.");
            _SmpInitProgressByLine = 0x1e6;
            _SmpInitLastCall = TpAllocWork_exref;
            *(ulonglong *)(puVar14 + 0x228) = uVar8;
            _SmpInitReturnStatus = uVar5;
          }
          else {
            for (uVar5 = 0; *(uint *)(puVar14 + 0x78) = uVar5, uVar5 < SmpNumberInitialSessions;
                uVar5 = uVar5 + 1) {
              *(undefined8 *)(puVar14 + -8) = 0x140001db5;
              TpPostWork();
              if ((1 < SmpNumberInitialSessions) && (uVar5 == 0)) {
                *(undefined8 *)(puVar14 + 0x94) = 0;
                *(undefined8 *)(puVar14 + 0x90) = 0;
                *(undefined4 *)(puVar14 + 0xbc) = 0;
                *(undefined8 *)(puVar14 + 0xb8) = 0;
                *(undefined8 *)(puVar14 + 0xc0) = 0;
                *(undefined4 *)(puVar14 + 200) = 0;
                *(undefined4 *)(puVar14 + 0xb8) = 1;
                *(undefined1 **)(puVar14 + 0xc0) = puVar14 + 0x90;
                *(undefined4 *)(puVar14 + 200) = 2;
                do {
                  *(undefined8 *)(puVar14 + -8) = 0x140001e25;
                  uVar6 = SmpGetFirstSessionId();
                  *(undefined8 *)(puVar14 + -8) = 0x140001e3b;
                  SmpWaitForSubSysStartup(uVar6,2,0,(uint *)(puVar14 + 0x90));
                  *(undefined8 *)(puVar14 + -8) = 0x140001e40;
                  uVar6 = SmpGetFirstSessionId();
                  *(undefined8 *)(puVar14 + -8) = 0x140001e4f;
                  piVar10 = SmpSearchKnownSubSysDatabase(uVar6,(int *)(puVar14 + 0xb8));
                  *(undefined8 *)(puVar14 + -8) = 0x140001e5f;
                  SmpUnlockKnownSubSysList((int *)(puVar14 + 0x90));
                } while (piVar10 == (int *)0x0);
                *(undefined8 *)(puVar14 + -8) = 0x140001e6c;
                uVar6 = SmpWaitForSingleSubSys((longlong)piVar10);
                uVar8 = (ulonglong)(int)uVar6;
                *(uint *)(puVar14 + 0x44) = uVar6;
                if ((int)uVar6 < 0) {
                  *(undefined8 *)(puVar14 + -8) = 0x140001e8b;
                  SmpLogFailure(0x14002a714,0x219,uVar6);
                  *(undefined8 *)(puVar14 + -8) = 0x140001e9e;
                  RtlInitUnicodeString(puVar14 + 0x48,L"Failed to locate core GUI process.");
                  _SmpInitProgressByLine = 0x21f;
                  _SmpInitLastCall = SmpWaitForSingleSubSys;
                  *(ulonglong *)(puVar14 + 0x228) = uVar8;
                  _SmpInitReturnStatus = uVar6;
                  goto LAB_140001f94;
                }
                *(undefined8 *)(puVar14 + -8) = 0x140001ed9;
                SmpDereferenceKnownSubSys(piVar10);
              }
            }
            *(undefined8 *)(puVar14 + -8) = 0x140001ef1;
            SmpGetCoreProcessIds(0,(longlong *)(puVar14 + 0x60));
            *(undefined8 *)(puVar14 + 0x20) = 0;
            *(undefined8 *)(puVar14 + -8) = 0x140001f10;
            iVar4 = NtWaitForMultipleObjects(1,&SmpCoreSubsysProcess,1,0);
            if (iVar4 == 0) {
              *(undefined8 *)(puVar14 + -8) = 0x140001f2e;
              RtlInitUnicodeString(puVar14 + 0x48,L"Master Subsystem Process");
              *(undefined8 *)(puVar14 + 0x20) = 0;
              *(undefined8 *)(puVar14 + -8) = 0x140001f54;
              iVar4 = NtQueryInformationProcess(SmpCoreSubsysProcess,0,puVar14 + 0xd8,0x30);
              if (-1 < iVar4) {
                iVar4 = *(int *)(puVar14 + 0xd8);
                goto LAB_140001f89;
              }
              uVar8 = 0xffffffffc0000001;
            }
            else {
              *(undefined8 *)(puVar14 + -8) = 0x140001f7d;
              RtlInitUnicodeString
                        (puVar14 + 0x48,L"Unexpected error code from NtWaitForMultipleObjects");
              *(int *)(puVar14 + 0xd8) = iVar4;
LAB_140001f89:
              uVar8 = (ulonglong)iVar4;
            }
            *(ulonglong *)(puVar14 + 0x228) = uVar8;
          }
        }
      }
    }
  }
LAB_140001f94:
  uVar5 = (uint)uVar8;
LAB_140001f9e:
  *(undefined8 *)(puVar14 + -8) = 0x140001fb4;
  SmpLogFailureString(0x14002a714,0x263,*(longlong *)(puVar14 + 0x50),uVar5);
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar14 + -8) = &UNK_140001fca;
  SmpTerminate(puVar14 + 0x220,1,4);
}



===== SmscpParseArgs @ 140001fe0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SmscpParseArgs(uint param_1,longlong param_2,uint *param_3,undefined2 *param_4)

{
  longlong lVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined2 *puVar7;
  uint uVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined2 *puVar12;
  uint local_res8 [2];
  undefined4 uVar13;
  uint local_48 [2];
  undefined8 local_40;
  undefined8 local_38 [2];
  
  local_48[0] = 0;
  local_res8[0] = 0;
  puVar12 = (undefined2 *)0x0;
  if (param_1 < 3) {
    return 0xc00000ef;
  }
  *param_3 = 0;
  uVar2 = wcstoul(*(wchar_t **)(param_2 + 8),(wchar_t **)0x0,0x10);
  uVar3 = wcstoul(*(wchar_t **)(param_2 + 0x10),(wchar_t **)0x0,0x10);
  local_40 = 0;
  local_38[0] = 0;
  uVar5 = NtMapViewOfSection(uVar3,0xffffffffffffffff,&SmpMappedView,0,0,&local_40,local_38,2,0,2);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  local_40 = 0;
  uVar13 = 0;
  local_38[0] = 0;
  uVar5 = NtMapViewOfSection(uVar2,0xffffffffffffffff,&SmscpSharedWindow,0,0,&local_40,local_38,2,0,
                             4);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  DAT_140033018 = *(longlong *)(SmpMappedView + 2) + (longlong)SmpMappedView;
  SmpDefaultLibPath = (short)SmpMappedView[4];
  DAT_140033012 = SmpDefaultLibPath + 2;
  PTR_u_wininit_exe_140030e40 =
       (undefined *)(*(longlong *)(SmpMappedView + 6) + (longlong)SmpMappedView);
  SmpS0InitCmd = *(ushort *)(SmpMappedView + 8);
  DAT_140030e3a = SmpS0InitCmd + 2;
  _DAT_140032498 = *(longlong *)(SmpMappedView + 10) + (longlong)SmpMappedView;
  SmscpInitExecuteCmd = *(ushort *)(SmpMappedView + 0xc);
  _DAT_140032492 = SmscpInitExecuteCmd + 2;
  SmscpSubsystemRegistered = *(undefined8 *)(SmscpSharedWindow + 8);
  iVar4 = SmpGetFirstSessionId();
  uVar8 = 0;
  if (*(int *)((longlong)ProcessEnvironmentBlock + 0x2c0) == iVar4) {
    uVar8 = 8;
  }
  uVar8 = uVar8 | *param_3 & 0xfffffff7;
  local_res8[0] = 0;
  *param_3 = uVar8;
  *param_3 = (*SmpMappedView << 2 ^ uVar8) & 4 ^ uVar8;
  if (param_1 < 4) {
LAB_1400023c9:
    uVar8 = *param_3;
    if ((uVar8 & 8) == 0) {
      local_res8[0] = (uint)SmscpInitExecuteCmd;
      if (SmscpInitExecuteCmd == 0) {
        local_res8[0] = 0x4a;
        puVar12 = (undefined2 *)&SmscpDefaultCmd;
        goto LAB_140002406;
      }
    }
    else {
      local_res8[0] = (uint)SmpS0InitCmd;
      if ((uVar8 & 4) == 0) {
        local_res8[0] = local_res8[0] + 0x32;
        puVar12 = &SmpS0InitCmd;
LAB_140002406:
        uVar8 = uVar8 | 1;
      }
    }
    local_res8[0] = local_res8[0] + 2;
    *param_3 = uVar8 | 2;
  }
  else {
    plVar9 = (longlong *)(param_2 + 0x18);
    uVar11 = (ulonglong)(param_1 - 3);
    do {
      lVar6 = -1;
      do {
        lVar1 = lVar6 * 2;
        lVar6 = lVar6 + 1;
      } while (*(short *)(*plVar9 + 2 + lVar1) != 0);
      plVar9 = plVar9 + 1;
      local_res8[0] = local_res8[0] + (int)lVar6 * 2 + 2;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
    if (local_res8[0] == 0) goto LAB_1400023c9;
  }
  puVar7 = (undefined2 *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                           SmBaseTag + 0xc0000);
  *(undefined2 **)(param_4 + 4) = puVar7;
  if (puVar7 == (undefined2 *)0x0) {
    return 0xc0000017;
  }
  param_4[1] = (undefined2)local_res8[0];
  *param_4 = 0;
  *puVar7 = 0;
  uVar8 = *param_3;
  if ((uVar8 & 2) == 0) {
    if (3 < param_1 - 1) {
      puVar10 = (undefined8 *)(param_2 + 0x18);
      uVar11 = (ulonglong)(param_1 - 4);
      do {
        RtlAppendUnicodeToString(param_4,*puVar10);
        RtlAppendUnicodeToString(param_4,L" ");
        puVar10 = puVar10 + 1;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
    RtlAppendUnicodeToString(param_4,*(undefined8 *)(param_2 + (ulonglong)(param_1 - 1) * 8));
    return 0;
  }
  if ((uVar8 & 1) == 0) {
    if ((uVar8 & 8) == 0) {
      RtlAppendUnicodeStringToString(param_4,&SmscpInitExecuteCmd);
      return 0;
    }
    RtlAppendUnicodeStringToString(param_4,&SmpS0InitCmd);
    return 0;
  }
  uVar5 = CONCAT44(uVar13,0x30);
  iVar4 = LdrQueryImageFileExecutionOptions
                    (puVar12,L"Debugger",1,*(undefined8 *)(param_4 + 4),uVar5,local_res8);
  uVar8 = local_res8[0];
  uVar13 = (undefined4)((ulonglong)uVar5 >> 0x20);
  if (iVar4 == -0x7ffffffb) {
    uVar11 = (ulonglong)((ushort)puVar12[1] + local_res8[0]) + 2;
    if ((local_res8[0] < uVar11) && (uVar11 < 0xffff)) {
      local_res8[0] = (ushort)puVar12[1] + local_res8[0] + 2;
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                  *(undefined8 *)(param_4 + 4));
      lVar6 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                              SmBaseTag + 0xc0000,local_res8[0]);
      *(longlong *)(param_4 + 4) = lVar6;
      if (lVar6 == 0) {
        return 0xc0000017;
      }
      param_4[1] = (undefined2)local_res8[0];
      iVar4 = LdrQueryImageFileExecutionOptions
                        (puVar12,L"Debugger",1,lVar6,CONCAT44(uVar13,uVar8),local_res8);
      goto LAB_14000244f;
    }
  }
  else {
LAB_14000244f:
    if (-1 < iVar4) {
      uVar8 = local_res8[0] & 0xfffffffe;
      if ((2 < uVar8) &&
         (*(short *)(*(longlong *)(param_4 + 4) + -2 + (ulonglong)(local_res8[0] >> 1) * 2) == 0)) {
        uVar8 = uVar8 - 2;
      }
      local_res8[0] = uVar8;
      *param_4 = (short)local_res8[0];
      RtlAppendUnicodeToString(param_4,L" ");
      goto LAB_140002499;
    }
  }
  if (((((*param_3 & 8) != 0) && (iVar4 = NtQuerySystemInformation(9,local_48,4), -1 < iVar4)) &&
      ((local_48[0] & 0x4000004) != 0)) && (iVar4 = SmscpIsDebuggerPresent(), -1 < iVar4)) {
    RtlAppendUnicodeStringToString(param_4,&DAT_140021ba8);
    if ((local_48[0] >> 0x11 & 1) != 0) {
      RtlAppendUnicodeStringToString(param_4,&DAT_140021b98);
    }
    if ((local_48[0] >> 0x1a & 1) != 0) {
      RtlAppendUnicodeStringToString(param_4,&DAT_140021b88);
    }
  }
LAB_140002499:
  RtlAppendUnicodeStringToString(param_4,puVar12);
  return 0;
}



===== SmscpLoadSubSystemsForMuSession @ 140002580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmscpLoadSubSystemsForMuSession(uint param_1)

{
  uint *puVar1;
  undefined2 uVar2;
  short sVar3;
  bool bVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  short *psVar12;
  longlong *plVar13;
  uint uVar14;
  ulonglong uVar15;
  undefined8 *puVar16;
  longlong lVar17;
  uint uVar18;
  undefined1 local_1f8 [32];
  ulonglong *puVar19;
  undefined8 local_1b8;
  longlong local_1b0;
  uint local_1a8 [2];
  uint local_1a0 [2];
  ulonglong local_198;
  longlong lStack_190;
  ulonglong local_188;
  longlong lStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 local_150;
  longlong lStack_148;
  ulonglong local_140 [5];
  char local_118 [64];
  short local_d8 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_1f8;
  local_158 = 0;
  local_1b8 = 0;
  local_1b0 = 0;
  bVar4 = false;
  local_150 = 0;
  lStack_148 = 0;
  iVar7 = RtlAcquirePrivilege(&SmpSessionCreatePrivilege,1,2,&local_158);
  if (iVar7 < 0) {
    SmpLogFailure(0x1400228d0,0x32e,iVar7);
    *SmscpSharedWindow = 1;
    LOCK();
    UNLOCK();
    SmscpSharedWindow[2] = 0x330;
    SmscpSharedWindow[1] = iVar7;
    *(code **)(SmscpSharedWindow + 4) = SmscpLoadSubSystemsForMuSession;
  }
  else {
    if ((param_1 == 0) && (SmpSerializeBoot == 1)) {
      iVar7 = SmpNtSerializeBoot();
      if (iVar7 < 0) {
        SmpLogFailure(0x1400228d0,0x347,iVar7);
        *SmscpSharedWindow = 1;
        pcVar5 = NtSerializeBoot_exref;
        LOCK();
        UNLOCK();
        SmscpSharedWindow[2] = 0x349;
        SmscpSharedWindow[1] = iVar7;
        *(code **)(SmscpSharedWindow + 4) = pcVar5;
      }
      else {
        bVar4 = true;
      }
    }
    uVar15 = 0;
    puVar1 = (uint *)(SmpMappedView + 0x40);
    lVar17 = *(longlong *)(SmpMappedView + 0x38) + SmpMappedView;
    if (*puVar1 != 0) {
      do {
        local_1b0 = SmpMappedView + *(longlong *)(lVar17 + uVar15 * 0x10);
        uVar2 = *(undefined2 *)(lVar17 + 8 + uVar15 * 0x10);
        local_1b8 = CONCAT62(CONCAT42(local_1b8._4_4_,uVar2),uVar2);
        iVar7 = NtSetSystemInformation(0x26);
        if (iVar7 < 0) break;
        uVar18 = (int)uVar15 + 1;
        uVar15 = (ulonglong)uVar18;
      } while (uVar18 < *puVar1);
    }
    RtlReleasePrivilege(local_158);
    if (iVar7 < 0) {
      memset(local_118,0,0xe0);
      if (local_1b0 != 0) {
        lVar17 = 0x40;
        psVar12 = local_d8;
        do {
          if ((lVar17 == -0x7fffffbe) ||
             (sVar3 = *(short *)((local_1b0 - (longlong)local_d8) + (longlong)psVar12), sVar3 == 0))
          break;
          *psVar12 = sVar3;
          psVar12 = psVar12 + 1;
          lVar17 = lVar17 + -1;
        } while (lVar17 != 0);
        psVar9 = psVar12 + -1;
        if (lVar17 != 0) {
          psVar9 = psVar12;
        }
        *psVar9 = 0;
      }
      SmpInternalLogFailure(0x1400228d0,0x370,iVar7,local_118);
      *SmscpSharedWindow = 1;
      LOCK();
      UNLOCK();
      SmscpSharedWindow[2] = 0x372;
      SmscpSharedWindow[1] = iVar7;
      *(code **)(SmscpSharedWindow + 4) = SmscpLoadSubSystemsForMuSession;
    }
    else {
      puVar1 = (uint *)(SmpMappedView + 0x50);
      lVar17 = *(longlong *)(SmpMappedView + 0x48) + SmpMappedView;
      uVar18 = 0;
      while (uVar18 < *puVar1) {
        plVar13 = (longlong *)((ulonglong)uVar18 * 0x10 + lVar17);
        lStack_148 = *plVar13 + SmpMappedView;
        local_150 = CONCAT62(CONCAT42(local_150._4_4_,(short)plVar13[1]),(short)plVar13[1]);
        local_1b0 = plVar13[2] + SmpMappedView;
        local_1b8 = CONCAT62(CONCAT42(local_1b8._4_4_,(short)plVar13[3]),(short)plVar13[3]);
        uVar14 = 0x3008;
        if (param_1 != 0) {
          uVar14 = 0x1008;
        }
        cVar6 = RtlEqualUnicodeString(&local_150,&SmpDebugKeyword,1);
        if (cVar6 != '\0') {
          uVar14 = uVar14 | 1;
        }
        if (((!bVar4) && (param_1 == 1)) && (SmpSerializeBoot == 2)) {
          iVar7 = SmpNtSerializeBoot();
          if (iVar7 < 0) {
            SmpLogFailure(0x1400228d0,0x3ad,iVar7);
            *SmscpSharedWindow = 1;
            LOCK();
            UNLOCK();
            SmscpSharedWindow[2] = 0x3af;
            SmscpSharedWindow[1] = iVar7;
            *(code **)(SmscpSharedWindow + 4) = NtSerializeBoot_exref;
          }
          else {
            bVar4 = true;
          }
        }
        local_198 = 0;
        lStack_190 = 0;
        local_178 = 0;
        uStack_170 = 0;
        local_140[0] = 0;
        local_140[1] = 0;
        local_1a8[0] = uVar14;
        if ((uVar14 & 1) == 0) {
          puVar19 = local_140;
          puVar16 = &local_178;
          iVar7 = SmpParseCommandLine(&local_1b8,local_1a8,&local_198,(longlong)puVar16,puVar19);
          if (iVar7 < 0) {
            SmpLogFailureString(0x140022808,0x2789,local_1b0,iVar7);
LAB_140002af9:
            SmpLogFailureString(0x1400228d0,0x3be,lStack_148,iVar7);
            *SmscpSharedWindow = 1;
            LOCK();
            UNLOCK();
            SmscpSharedWindow[2] = 0x3c0;
            SmscpSharedWindow[1] = iVar7;
            *(code **)(SmscpSharedWindow + 4) = SmscpLoadSubSystemsForMuSession;
            goto LAB_140002814;
          }
          if ((local_1a8[0] & 4) == 0) {
            if ((local_1a8[0] & 8) != 0) {
              if (SmpPrimarySmss == '\0') {
                iVar7 = SmscpLoadSubSystem((ushort *)&local_198,&local_178,(longlong)&local_1b8,
                                           (undefined8 **)(ulonglong)param_1,local_1a8[0]);
              }
              else {
                iVar7 = SmpLoadSubSystem((ushort *)&local_198,&local_178,&local_1b8,param_1,puVar19,
                                         local_1a8[0]);
              }
              goto LAB_140002a79;
            }
            if ((local_1a8[0] & 0x10) == 0) {
              iVar7 = SmpExecuteImage((ushort *)&local_198,&local_178,&local_1b8,puVar16,(uint *)0x0
                                      ,local_1a8[0],(undefined8 *)0x0);
              goto LAB_140002a79;
            }
            iVar7 = -0x3fffffcc;
            SmpLogFailureString(0x140022808,0x27af,lStack_190,0xc0000034);
            RtlFreeUnicodeString(&local_198);
            RtlFreeUnicodeString(local_140);
            RtlFreeUnicodeString(&local_178);
LAB_140002aaf:
            SmpLogFailureString(0x140022808,0x27ca,local_1b0,iVar7);
          }
          else {
            if ((SmpSoftBoot == '\0') || (SmpBugcheckRecovery != '\0')) {
              uVar10 = SmpInvokeAutoChk((ushort *)&local_198,&local_178,local_140,
                                        (ulonglong)local_1a8[0]);
              iVar7 = (int)uVar10;
            }
LAB_140002a79:
            RtlFreeUnicodeString(&local_198);
            RtlFreeUnicodeString(local_140);
            RtlFreeUnicodeString(&local_178);
            if (iVar7 < 0) goto LAB_140002aaf;
          }
          if (iVar7 < 0) goto LAB_140002af9;
          uVar18 = uVar18 + 2;
        }
        else {
          iVar7 = 0;
          uVar18 = uVar18 + 2;
        }
      }
      puVar1 = (uint *)(SmpMappedView + 0x60);
      lVar17 = *(longlong *)(SmpMappedView + 0x58) + SmpMappedView;
      uVar15 = 0;
      if (*puVar1 != 0) {
        do {
          local_1a0[0] = 0;
          puVar16 = &local_168;
          local_188 = 0;
          lStack_180 = 0;
          local_1b0 = *(longlong *)(lVar17 + uVar15 * 0x10) + SmpMappedView;
          uVar2 = *(undefined2 *)(lVar17 + 8 + uVar15 * 0x10);
          local_1b8 = CONCAT62(CONCAT42(local_1b8._4_4_,uVar2),uVar2);
          puVar19 = local_140 + 2;
          local_168 = 0;
          uStack_160 = 0;
          local_140[2] = 0;
          local_140[3] = 0;
          iVar8 = SmpParseCommandLine(&local_1b8,local_1a0,&local_188,(longlong)puVar16,puVar19);
          if (iVar8 < 0) {
            uVar11 = 0x2789;
LAB_140002d0c:
            SmpLogFailureString(0x140022808,uVar11,local_1b0,iVar8);
          }
          else {
            if ((local_1a0[0] & 4) == 0) {
              if ((local_1a0[0] & 8) != 0) {
                if (SmpPrimarySmss == '\0') {
                  iVar8 = SmscpLoadSubSystem((ushort *)&local_188,&local_168,(longlong)&local_1b8,
                                             (undefined8 **)(ulonglong)param_1,local_1a0[0]);
                }
                else {
                  iVar8 = SmpLoadSubSystem((ushort *)&local_188,&local_168,&local_1b8,param_1,
                                           puVar19,local_1a0[0]);
                }
                goto LAB_140002cce;
              }
              if ((local_1a0[0] & 0x10) == 0) {
                iVar8 = SmpExecuteImage((ushort *)&local_188,&local_168,&local_1b8,puVar16,
                                        (uint *)0x0,local_1a0[0],(undefined8 *)0x0);
                goto LAB_140002cce;
              }
              iVar8 = -0x3fffffcc;
              SmpLogFailureString(0x140022808,0x27af,lStack_180,0xc0000034);
              RtlFreeUnicodeString(&local_188);
              RtlFreeUnicodeString(local_140 + 2);
              RtlFreeUnicodeString(&local_168);
LAB_140002d04:
              uVar11 = 0x27ca;
              goto LAB_140002d0c;
            }
            if ((SmpSoftBoot == '\0') || (SmpBugcheckRecovery != '\0')) {
              uVar10 = SmpInvokeAutoChk((ushort *)&local_188,&local_168,local_140 + 2,
                                        (ulonglong)local_1a0[0]);
              iVar8 = (int)uVar10;
            }
LAB_140002cce:
            RtlFreeUnicodeString(&local_188);
            RtlFreeUnicodeString(local_140 + 2);
            RtlFreeUnicodeString(&local_168);
            if (iVar8 < 0) goto LAB_140002d04;
          }
          uVar18 = (int)uVar15 + 1;
          uVar15 = (ulonglong)uVar18;
        } while (uVar18 < *puVar1);
      }
    }
  }
LAB_140002814:
  return iVar7;
}



===== SmscpLoadSubSystem @ 140002d40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmscpLoadSubSystem(ushort *param_1,undefined8 param_2,longlong param_3,undefined8 **param_4,
                      uint param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 **ppuVar5;
  undefined1 auStackY_158 [32];
  ushort local_118 [4];
  undefined8 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  int local_b0;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  ushort *local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  ppuVar5 = param_4;
  memset(&local_f8,0,0x68);
  local_110 = CONCAT44(local_110._4_4_,(int)param_4);
  local_108 = 0;
  uStack_100 = 0;
  if (SmpTraceHandle != 0) {
    cVar1 = EtwEventEnabled(SmpTraceHandle,&SmssEvt_LoadSubsystem_Start);
    if (cVar1 != '\0') {
      ppuVar5 = &local_78;
      local_50 = (uint)*param_1;
      local_118[0] = *param_1 >> 1;
      local_78 = &local_110;
      local_68 = local_118;
      local_58 = *(undefined8 *)(param_1 + 4);
      local_70 = 4;
      local_60 = 2;
      local_4c = 0;
      EtwEventWrite(SmpTraceHandle,&SmssEvt_LoadSubsystem_Start,3);
    }
  }
  if ((param_5 & 0x10) != 0) {
    iVar2 = -0x3fffffcc;
    if (param_1 == (ushort *)0x0) {
      lVar4 = 0;
    }
    else {
      lVar4 = *(longlong *)(param_1 + 4);
    }
    SmpLogFailureString(0x14002abf8,0x476,lVar4,0xc0000034);
    goto LAB_14000300d;
  }
  iVar2 = SmpExecuteImage(param_1,param_2,param_3,ppuVar5,(uint *)0x0,param_5 | 0x20,&local_f8);
  if (iVar2 < 0) {
    SmpLogFailure(0x14002abf8,0x488,iVar2);
    goto LAB_14000300d;
  }
  *(undefined8 *)(SmscpSharedWindow + 8) = local_e0;
  if (local_b0 == 1) {
    iVar2 = NtResumeThread(local_e8,0);
    if (-1 < iVar2) goto LAB_140002ef6;
    SmpLogFailure(0x14002abf8,0x4b1,iVar2);
LAB_140002efa:
    if (param_3 == 0) {
      lVar4 = 0;
    }
    else {
      lVar4 = *(longlong *)(param_3 + 8);
    }
    uVar3 = 0x4b7;
  }
  else {
    iVar2 = SmExecPgmEx(local_e0,&local_f8);
    if (iVar2 < 0) {
      SmpLogFailure(0x14002abf8,0x4a8,iVar2);
      goto LAB_140002efa;
    }
LAB_140002ef6:
    if (iVar2 < 0) goto LAB_140002efa;
    local_108 = SmscpSubsystemRegistered;
    uStack_100 = local_f0;
    iVar2 = NtWaitForMultipleObjects(2,&local_108,1);
    if (-1 < iVar2) {
      if (iVar2 == 1) {
        local_110 = 0;
        NtQueryEvent(SmscpSubsystemRegistered,0,&local_110,8);
        if (local_110._4_4_ == 0) {
          iVar2 = -0x3fffffff;
          if (param_3 == 0) {
            lVar4 = 0;
          }
          else {
            lVar4 = *(longlong *)(param_3 + 8);
          }
          SmpLogFailureString(0x14002abf8,0x4e7,lVar4,0xc0000001);
          goto LAB_14000300d;
        }
      }
      *(undefined8 *)(SmscpSharedWindow + 8) = 0;
      NtSetInformationProcess(local_f0,0x44,0,0);
      iVar2 = 0;
      goto LAB_14000300d;
    }
    if (param_3 == 0) {
      lVar4 = 0;
    }
    else {
      lVar4 = *(longlong *)(param_3 + 8);
    }
    uVar3 = 0x4cd;
  }
  SmpLogFailureString(0x14002abf8,uVar3,lVar4,iVar2);
  NtTerminateProcess(local_f0,iVar2);
LAB_14000300d:
  local_110 = CONCAT44(local_110._4_4_,iVar2);
  if (SmpTraceHandle != 0) {
    cVar1 = EtwEventEnabled(SmpTraceHandle,&SmssEvt_LoadSubsystem_Stop);
    if (cVar1 != '\0') {
      local_88 = &local_110;
      local_80 = 4;
      EtwEventWrite(SmpTraceHandle,&SmssEvt_LoadSubsystem_Stop,1,&local_88);
    }
  }
  return iVar2;
}



===== SmpExecuteImage @ 140003090 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpExecuteImage(ushort *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   uint *param_5,uint param_6,undefined8 *param_7)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  short *psVar6;
  undefined4 uVar7;
  longlong lVar8;
  short *psVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined1 auStackY_288 [32];
  uint local_228 [2];
  longlong local_220;
  ushort local_218 [2];
  undefined4 local_214;
  undefined2 local_210;
  short local_20e;
  undefined8 local_20c;
  undefined8 uStack_204;
  undefined8 local_1fc;
  undefined8 uStack_1f4;
  undefined8 local_1ec;
  undefined4 local_1e4;
  uint *local_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined4 local_178;
  char local_168 [64];
  short local_128 [80];
  uint *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 uStack_70;
  ushort *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  uint local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  lVar10 = 0;
  local_214 = 0;
  local_88 = param_5;
  local_1ec = 0;
  local_178 = 0;
  local_1e4 = 0;
  puVar11 = &local_1d8;
  if (param_7 != (undefined8 *)0x0) {
    puVar11 = param_7;
  }
  local_20c = 0;
  uStack_204 = 0;
  local_220 = 0;
  local_1fc = 0;
  uStack_1f4 = 0;
  local_1d8 = 0;
  uStack_1d0 = 0;
  local_1c8 = 0;
  uStack_1c0 = 0;
  local_1b8 = 0;
  uStack_1b0 = 0;
  local_1a8 = 0;
  uStack_1a0 = 0;
  local_198 = 0;
  uStack_190 = 0;
  local_188 = 0;
  uStack_180 = 0;
  iVar3 = RtlCreateProcessParametersEx(&local_220,param_1,0,param_2);
  if (iVar3 < 0) {
    if (param_1 == (ushort *)0x0) {
      lVar10 = 0;
    }
    else {
      lVar10 = *(longlong *)(param_1 + 4);
    }
    memset(local_168,0,0xe0);
    if (lVar10 != 0) {
      lVar8 = 0x40;
      psVar9 = local_128;
      do {
        if ((lVar8 == -0x7fffffbe) ||
           (sVar2 = *(short *)((lVar10 - (longlong)local_128) + (longlong)psVar9), sVar2 == 0))
        break;
        *psVar9 = sVar2;
        psVar9 = psVar9 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      psVar6 = psVar9 + -1;
      if (lVar8 != 0) {
        psVar6 = psVar9;
      }
      *psVar6 = 0;
    }
    SmpInternalLogFailure(0x1400226a0,0x26bb,iVar3,local_168);
    return iVar3;
  }
  uVar7 = SmpDebug;
  if ((param_6 & 1) != 0) {
    uVar7 = 1;
  }
  *(undefined4 *)(local_220 + 0xc) = uVar7;
  if ((param_6 & 0x400) == 0) {
    sVar2 = 0;
  }
  else {
    *(uint *)(local_220 + 8) = *(uint *)(local_220 + 8) | 0x40000;
    sVar2 = SmpSelectNodeNumber();
    sVar2 = sVar2 + 1;
  }
  if ((param_6 >> 0xc & 1) != 0) {
    *(uint *)(local_220 + 8) = *(uint *)(local_220 + 8) | 0x400000;
  }
  if ((param_6 >> 0xe & 1) != 0) {
    *(uint *)(local_220 + 8) = *(uint *)(local_220 + 8) | 0x800000;
  }
  if ((param_6 & 0x8000) != 0) {
    *(uint *)(local_220 + 8) = *(uint *)(local_220 + 8) | 0x80000000;
  }
  local_228[0] = param_6;
  *(uint *)(local_220 + 8) = *(uint *)(local_220 + 8) | 0x20000;
  *(undefined4 *)puVar11 = 0x68;
  if ((SmpTraceHandle != 0) &&
     (cVar1 = EtwEventEnabled(SmpTraceHandle,&SmssEvt_ExecuteImage_Start), cVar1 != '\0')) {
    local_50 = (uint)*param_1;
    local_218[0] = *param_1 >> 1;
    local_78 = local_228;
    local_68 = local_218;
    local_58 = *(undefined8 *)(param_1 + 4);
    uStack_70 = 4;
    uStack_60 = 2;
    local_4c = 0;
    EtwEventWrite(SmpTraceHandle,&SmssEvt_ExecuteImage_Start,3,&local_78);
  }
  local_1ec = 0;
  local_210 = 1;
  local_1e0 = local_88;
  local_1e4 = 0;
  local_20c = 0;
  uStack_204 = 0;
  local_1fc = 0;
  uStack_1f4 = 0;
  local_20e = sVar2;
  iVar3 = RtlCreateUserProcessEx(param_1,local_220,(param_6 & 0x400) != 0,&local_210);
  RtlDestroyProcessParameters(local_220);
  if (iVar3 < 0) {
    local_228[0] = 0;
    if ((SmpTraceHandle != 0) && (cVar1 = EtwEventEnabled(), cVar1 != '\0')) {
      local_88 = local_228;
      local_80 = 4;
      EtwEventWrite(SmpTraceHandle,&SmssEvt_ExecuteImage_Stop,1,&local_88);
    }
    if (param_1 == (ushort *)0x0) {
      lVar10 = 0;
    }
    else {
      lVar10 = *(longlong *)(param_1 + 4);
    }
    memset(local_168,0,0xe0);
    if (lVar10 != 0) {
      lVar8 = 0x40;
      psVar9 = local_128;
      do {
        if ((lVar8 == -0x7fffffbe) ||
           (sVar2 = *(short *)((lVar10 - (longlong)local_128) + (longlong)psVar9), sVar2 == 0))
        break;
        *psVar9 = sVar2;
        psVar9 = psVar9 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      psVar6 = psVar9 + -1;
      if (lVar8 != 0) {
        psVar6 = psVar9;
      }
      *psVar6 = 0;
    }
    SmpInternalLogFailure(0x1400226a0,9999,iVar3,local_168);
    return iVar3;
  }
  local_58 = 0;
  local_50 = 0;
  local_78 = (uint *)0x0;
  uStack_70 = 0;
  local_68 = (ushort *)0x0;
  uStack_60 = 0;
  iVar4 = NtQueryInformationProcess(puVar11[1],0,&local_78,0x30);
  local_228[0] = (uint)local_58;
  if (iVar4 < 0) {
    local_228[0] = 0;
  }
  if ((SmpTraceHandle != 0) &&
     (cVar1 = EtwEventEnabled(SmpTraceHandle,&SmssEvt_ExecuteImage_Stop), cVar1 != '\0')) {
    local_88 = local_228;
    local_80 = 4;
    EtwEventWrite(SmpTraceHandle,&SmssEvt_ExecuteImage_Stop,1,&local_88);
  }
  if (((param_6 >> 0xd & 1) == 0) ||
     (local_214 = 1, iVar3 = NtSetInformationProcess(puVar11[1],0x1d,&local_214), -1 < iVar3)) {
    if ((param_6 & 0x20) != 0) {
LAB_1400032fb:
      if ((param_6 & 0x20) != 0) {
        return iVar3;
      }
      goto LAB_140003680;
    }
    if ((*(int *)(puVar11 + 9) != 1) && ((param_6 & 0x8000) == 0)) {
      iVar3 = -0x3fffff85;
      if (param_1 != (ushort *)0x0) {
        lVar10 = *(longlong *)(param_1 + 4);
      }
      SmpLogFailureString(0x1400226a0,0x272d,lVar10,0xc000007b);
      goto LAB_140003621;
    }
    NtResumeThread(puVar11[2],0);
    if ((param_6 & 2) != 0) goto LAB_1400032fb;
    if ((param_6 >> 0x10 & 1) == 0) {
      NtWaitForSingleObject(puVar11[2],0,0);
      goto LAB_140003680;
    }
  }
  else {
    uVar5 = SmpGetProcessId();
    SmLogFailureInt(0x1400226a0,0x271d,uVar5,0,iVar3);
LAB_140003621:
    NtTerminateProcess(puVar11[1],iVar3);
  }
  NtWaitForSingleObject(puVar11[1],0,0);
LAB_140003680:
  NtClose(puVar11[2]);
  NtClose(puVar11[1]);
  return iVar3;
}



===== SmpInternalLogFailure @ 1400036fc =====

void SmpInternalLogFailure(longlong param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  undefined8 uVar1;
  char *pcVar2;
  char *pcVar3;
  longlong lVar4;
  
  *(undefined4 *)(param_4 + 0xc0) = param_3;
  *(undefined4 *)(param_4 + 0xd8) = param_2;
  if (param_1 != 0) {
    lVar4 = 0x40;
    pcVar3 = param_4;
    do {
      if ((lVar4 == -0x7fffffbe) || (pcVar3[param_1 - (longlong)param_4] == '\0')) break;
      *pcVar3 = pcVar3[param_1 - (longlong)param_4];
      pcVar3 = pcVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    pcVar2 = pcVar3 + -1;
    if (lVar4 != 0) {
      pcVar2 = pcVar3;
    }
    *pcVar2 = '\0';
  }
  LOCK();
  UNLOCK();
  uVar1 = *(undefined8 *)(param_4 + 8);
  lVar4 = (longlong)((DAT_140030ed4 + 1) % 0x10) * 0xe0;
  DAT_140030ed4 = DAT_140030ed4 + 1;
  *(undefined8 *)(&DAT_140030ed8 + lVar4) = *(undefined8 *)param_4;
  *(undefined8 *)(lVar4 + 0x140030ee0) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0x18);
  *(undefined8 *)(&DAT_140030ee8 + lVar4) = *(undefined8 *)(param_4 + 0x10);
  *(undefined8 *)(lVar4 + 0x140030ef0) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0x28);
  *(undefined8 *)(&DAT_140030ef8 + lVar4) = *(undefined8 *)(param_4 + 0x20);
  *(undefined8 *)(lVar4 + 0x140030f00) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0x38);
  *(undefined8 *)(&DAT_140030f08 + lVar4) = *(undefined8 *)(param_4 + 0x30);
  *(undefined8 *)(lVar4 + 0x140030f10) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0x48);
  *(undefined8 *)(&DAT_140030f18 + lVar4) = *(undefined8 *)(param_4 + 0x40);
  *(undefined8 *)(lVar4 + 0x140030f20) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0x58);
  *(undefined8 *)(&DAT_140030f28 + lVar4) = *(undefined8 *)(param_4 + 0x50);
  *(undefined8 *)(lVar4 + 0x140030f30) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0x68);
  *(undefined8 *)(&DAT_140030f38 + lVar4) = *(undefined8 *)(param_4 + 0x60);
  *(undefined8 *)(lVar4 + 0x140030f40) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0x78);
  *(undefined8 *)(&DAT_140030f48 + lVar4) = *(undefined8 *)(param_4 + 0x70);
  *(undefined8 *)(lVar4 + 0x140030f50) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0x88);
  *(undefined8 *)(&DAT_140030f58 + lVar4) = *(undefined8 *)(param_4 + 0x80);
  *(undefined8 *)(lVar4 + 0x140030f60) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0x98);
  *(undefined8 *)(&DAT_140030f68 + lVar4) = *(undefined8 *)(param_4 + 0x90);
  *(undefined8 *)(lVar4 + 0x140030f70) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0xa8);
  *(undefined8 *)(&DAT_140030f78 + lVar4) = *(undefined8 *)(param_4 + 0xa0);
  *(undefined8 *)(lVar4 + 0x140030f80) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0xb8);
  *(undefined8 *)(&DAT_140030f88 + lVar4) = *(undefined8 *)(param_4 + 0xb0);
  *(undefined8 *)(lVar4 + 0x140030f90) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 200);
  *(undefined8 *)(&DAT_140030f98 + lVar4) = *(undefined8 *)(param_4 + 0xc0);
  *(undefined8 *)(lVar4 + 0x140030fa0) = uVar1;
  uVar1 = *(undefined8 *)(param_4 + 0xd8);
  *(undefined8 *)(&DAT_140030fa8 + lVar4) = *(undefined8 *)(param_4 + 0xd0);
  *(undefined8 *)(lVar4 + 0x140030fb0) = uVar1;
  return;
}



===== SmpSelectNodeNumber @ 140003810 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SmpSelectNodeNumber(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 local_418 [8];
  longlong alStack_410 [129];
  
  memset(local_418,0,0x408);
  uVar4 = SmpActiveProcessorCount;
  uVar1 = _DAT_7ffe03c0;
  if ((SmpActiveProcessorCount < _DAT_7ffe03c0) &&
     (iVar3 = NtQuerySystemInformation(0x37,local_418,0x408), -1 < iVar3)) {
    uVar6 = 0;
    if (SmpMaximumNodeCount != 0) {
      do {
        if ((alStack_410[uVar6 * 2] != 0) &&
           (cVar2 = RtlTestBit(&SmpNodeBitmap,uVar6), cVar2 == '\0')) {
          RtlInterlockedSetBitRun(&SmpNodeBitmap,uVar6,1);
        }
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < SmpMaximumNodeCount);
    }
    do {
      LOCK();
      if (uVar4 == SmpActiveProcessorCount) {
        SmpActiveProcessorCount = uVar1;
        uVar5 = uVar4;
      }
      else {
        uVar5 = SmpActiveProcessorCount;
      }
      UNLOCK();
    } while ((uVar5 != uVar4) && (uVar4 = uVar5, uVar5 < uVar1));
  }
  LOCK();
  UNLOCK();
  uVar6 = (ulonglong)SmpCurrentNodeCount;
  SmpCurrentNodeCount = SmpCurrentNodeCount + 1;
  RtlFindSetBits(&SmpNodeBitmap,1,uVar6 % (ulonglong)SmpMaximumNodeCount);
  return;
}



===== SmpLoadPnPSerializeSettings @ 140003930 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SmpLoadPnPSerializeSettings(void)

{
  int iVar1;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 *local_90;
  undefined4 local_88 [2];
  longlong local_80 [2];
  wchar_t *local_70;
  longlong local_68;
  wchar_t *local_60;
  longlong local_58 [2];
  longlong *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [4];
  int local_24;
  undefined4 local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_b8;
  local_80[1] = 0x6e006c;
  local_88[0] = 0;
  local_70 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\PnP";
  local_58[1] = 0;
  local_60 = L"BootOptions";
  local_48 = local_80 + 1;
  local_80[0] = 0;
  local_68 = 0x180016;
  local_58[0] = 0x30;
  local_40 = 0x40;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = NtOpenKey(local_80,0x20019,local_80 + 5);
  if (iVar1 < 0) {
    _SmpInitProgressByLine = 0x56f;
    _SmpInitLastCall = NtOpenKey_exref;
    _SmpInitReturnStatus = iVar1;
  }
  else {
    local_90 = local_88;
    local_98 = 0x14;
    iVar1 = NtQueryValueKey(local_80[0],local_80 + 3,2,local_28);
    if (iVar1 < 0) {
      _SmpInitProgressByLine = 0x581;
      _SmpInitLastCall = NtQueryValueKey_exref;
      _SmpInitReturnStatus = iVar1;
    }
    else if (local_24 == 4) {
      SmpSerializeBoot = local_1c;
    }
  }
  if (local_80[0] != 0) {
    NtClose();
  }
  return iVar1;
}



===== SmpGetFirstSessionId @ 140003a88 =====

void SmpGetFirstSessionId(void)

{
  int iVar1;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_resc = 0xffffffff;
  local_res8 = 0xffd9da60;
  while( true ) {
    iVar1 = RtlGetCurrentServiceSessionId();
    if (iVar1 != -1) break;
    NtDelayExecution(0,&local_res8);
  }
  return;
}



===== SmpInsertControlBlock @ 140003acc =====

undefined4 SmpInsertControlBlock(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 1;
  }
  if (*(uint *)(param_2 + 8) < *(uint *)(param_1 + -0x60)) {
    iVar1 = SmpInsertControlBlock(*(longlong *)(param_1 + 8),param_2);
    if (iVar1 == 0) {
      return 0;
    }
    *(longlong *)(param_1 + 8) = param_2 + 0x68;
  }
  else {
    iVar1 = SmpInsertControlBlock(*(longlong *)(param_1 + 0x10),param_2);
    if (iVar1 == 0) {
      return 0;
    }
    *(longlong *)(param_1 + 0x10) = param_2 + 0x68;
  }
  *(longlong *)(param_2 + 0x68) = param_1;
  return 0;
}



===== SmscpExecuteInitialCommand @ 140003b40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmscpExecuteInitialCommand(uint param_1,uint *param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 local_268 [32];
  ulonglong *puVar7;
  uint local_228 [2];
  ulonglong local_220;
  longlong lStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  ulonglong local_200 [3];
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined4 local_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined8 local_188;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined4 local_150;
  undefined4 local_14c;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  undefined1 local_e0;
  undefined1 local_df [183];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)local_268;
  memset(&local_1e8,0,0x68);
  local_228[0] = 0x820;
  if (((*param_2 & 8) != 0) && (local_228[0] = 0x2820, ((byte)*param_2 & 6) == 2)) {
    local_228[0] = 0x3820;
  }
  puVar7 = local_200;
  puVar5 = &local_210;
  local_220 = 0;
  lStack_218 = 0;
  local_210 = 0;
  uStack_208 = 0;
  local_200[0] = 0;
  local_200[1] = 0;
  uVar1 = SmpParseCommandLine(param_3,local_228,&local_220,(longlong)puVar5,puVar7);
  lVar6 = 0;
  if ((int)uVar1 < 0) {
    if (param_3 == (undefined8 *)0x0) {
      lVar4 = 0;
    }
    else {
      lVar4 = param_3[1];
    }
    SmpLogFailureString(0x140022808,0x2789,lVar4,uVar1);
LAB_140003d49:
    *SmscpSharedWindow = 1;
    LOCK();
    UNLOCK();
    SmscpSharedWindow[2] = 0x414;
    SmscpSharedWindow[1] = uVar1;
    *(code **)(SmscpSharedWindow + 4) = SmscpExecuteInitialCommand;
    if (param_3 != (undefined8 *)0x0) {
      lVar6 = param_3[1];
    }
    SmpLogFailureString(0x140022898,0x415,lVar6,uVar1);
  }
  else {
    if ((local_228[0] & 4) == 0) {
      if ((local_228[0] & 8) != 0) {
        if (SmpPrimarySmss == '\0') {
          uVar1 = SmscpLoadSubSystem((ushort *)&local_220,&local_210,(longlong)param_3,
                                     (undefined8 **)(ulonglong)param_1,local_228[0]);
        }
        else {
          uVar1 = SmpLoadSubSystem((ushort *)&local_220,&local_210,param_3,param_1,puVar7,
                                   local_228[0]);
        }
        goto LAB_140003c04;
      }
      if ((local_228[0] & 0x10) == 0) {
        uVar1 = SmpExecuteImage((ushort *)&local_220,&local_210,param_3,puVar5,(uint *)0x0,
                                local_228[0],&local_1e8);
        goto LAB_140003c04;
      }
      uVar1 = 0xc0000034;
      SmpLogFailureString(0x140022808,0x27af,lStack_218,0xc0000034);
      RtlFreeUnicodeString(&local_220);
      RtlFreeUnicodeString(local_200);
      RtlFreeUnicodeString(&local_210);
LAB_140003e77:
      if (param_3 == (undefined8 *)0x0) {
        lVar4 = 0;
      }
      else {
        lVar4 = param_3[1];
      }
      SmpLogFailureString(0x140022808,0x27ca,lVar4,uVar1);
      if ((int)uVar1 < 0) goto LAB_140003d49;
    }
    else {
      if ((SmpSoftBoot == '\0') || (SmpBugcheckRecovery != '\0')) {
        uVar3 = SmpInvokeAutoChk((ushort *)&local_220,&local_210,local_200,(ulonglong)local_228[0]);
        uVar1 = (uint)uVar3;
      }
LAB_140003c04:
      RtlFreeUnicodeString(&local_220);
      RtlFreeUnicodeString(local_200);
      RtlFreeUnicodeString(&local_210);
      if ((int)uVar1 < 0) goto LAB_140003e77;
    }
    local_178 = 0;
    uStack_170 = 0;
    *SmscpSharedWindow = 2;
    local_158 = 0;
    local_14c = 0;
    local_168 = 0;
    uStack_160 = 0;
    memset(local_df,0,0xaf);
    local_148 = local_1e8;
    uStack_140 = uStack_1e0;
    local_128 = local_1c8;
    uStack_120 = uStack_1c0;
    local_138 = local_1d8;
    uStack_130 = uStack_1d0;
    local_108 = local_1a8;
    uStack_100 = uStack_1a0;
    local_118 = local_1b8;
    uStack_110 = uStack_1b0;
    local_e8 = local_188;
    local_f8 = local_198;
    uStack_f4 = uStack_194;
    uStack_f0 = uStack_190;
    uStack_ec = uStack_18c;
    local_e0 = 0;
    local_150 = 3;
    uVar2 = RtlSendMsgToSm(SmpApiConnectionPort,&local_178);
    uVar1 = (uint)uVar2;
    if (-1 < (int)uVar1) {
      return uVar2;
    }
    SmpLogFailure(0x140022898,0x429,uVar1);
    *SmscpSharedWindow = 1;
    LOCK();
    UNLOCK();
    SmscpSharedWindow[2] = 0x42b;
    SmscpSharedWindow[1] = uVar1;
    *(code **)(SmscpSharedWindow + 4) = SmscpExecuteInitialCommand;
    NtTerminateProcess(uStack_1e0,uVar2 & 0xffffffff);
  }
  return (ulonglong)uVar1;
}



===== SmpExecuteCommand @ 140003f30 =====

int SmpExecuteCommand(undefined8 *param_1,uint param_2,undefined8 param_3,uint param_4,
                     undefined8 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  ulonglong *puVar4;
  longlong lVar5;
  ulonglong *puVar6;
  uint local_res20 [2];
  ulonglong *puVar7;
  ulonglong local_48;
  longlong lStack_40;
  ulonglong local_38 [4];
  
  local_48 = 0;
  lStack_40 = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  if ((param_4 & 1) != 0) {
    return 0;
  }
  puVar7 = local_38;
  puVar4 = local_38 + 2;
  lVar5 = 0;
  if ((param_4 >> 10 & 1) != 0) {
    puVar4 = (ulonglong *)0x0;
  }
  puVar6 = puVar4;
  local_res20[0] = param_4;
  iVar1 = SmpParseCommandLine(param_1,local_res20,&local_48,(longlong)puVar4,puVar7);
  if (iVar1 < 0) {
    if (param_1 != (undefined8 *)0x0) {
      lVar5 = param_1[1];
    }
    uVar3 = 0x2789;
  }
  else {
    if ((local_res20[0] & 4) == 0) {
      if ((local_res20[0] & 8) == 0) {
        if ((local_res20[0] & 0x10) == 0) {
          iVar1 = SmpExecuteImage((ushort *)&local_48,puVar4,param_1,puVar6,(uint *)0x0,
                                  local_res20[0],param_5);
        }
        else {
          iVar1 = -0x3fffffcc;
          SmpLogFailureString(0x140022808,0x27af,lStack_40,0xc0000034);
        }
      }
      else if (SmpPrimarySmss == '\0') {
        iVar1 = SmscpLoadSubSystem((ushort *)&local_48,puVar4,(longlong)param_1,
                                   (undefined8 **)(ulonglong)param_2,local_res20[0]);
      }
      else {
        iVar1 = SmpLoadSubSystem((ushort *)&local_48,puVar4,param_1,param_2,puVar7,local_res20[0]);
      }
    }
    else if ((SmpSoftBoot == '\0') || (SmpBugcheckRecovery != '\0')) {
      uVar2 = SmpInvokeAutoChk((ushort *)&local_48,puVar4,local_38,(ulonglong)local_res20[0]);
      iVar1 = (int)uVar2;
    }
    RtlFreeUnicodeString(&local_48);
    RtlFreeUnicodeString(local_38);
    if (puVar4 != (ulonglong *)0x0) {
      RtlFreeUnicodeString(local_38 + 2);
    }
    if (-1 < iVar1) {
      return iVar1;
    }
    if (param_1 != (undefined8 *)0x0) {
      lVar5 = param_1[1];
    }
    uVar3 = 0x27ca;
  }
  SmpLogFailureString(0x140022808,uVar3,lVar5,iVar1);
  return iVar1;
}



===== SmpStartCsr @ 140004120 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpStartCsr(undefined8 *param_1)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  undefined8 *puVar8;
  char *pcVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  char *pcVar12;
  undefined4 uVar13;
  ulonglong uVar14;
  longlong lVar15;
  int iVar16;
  int iVar17;
  bool bVar18;
  undefined1 auStackY_4a8 [32];
  ulonglong *puVar19;
  undefined8 local_468;
  undefined8 uStack_460;
  uint local_458 [2];
  uint local_450 [2];
  int *local_448 [2];
  ulonglong local_438;
  longlong lStack_430;
  undefined8 local_428;
  ulonglong local_420;
  undefined8 uStack_418;
  undefined8 local_410;
  undefined8 uStack_408;
  undefined8 local_3f8;
  undefined8 uStack_3f0;
  undefined8 local_3e8;
  undefined8 uStack_3e0;
  undefined8 local_3d8;
  undefined8 uStack_3d0;
  undefined8 local_3c8;
  undefined8 uStack_3c0;
  undefined8 local_3b8;
  undefined8 uStack_3b0;
  undefined8 local_3a8;
  undefined8 uStack_3a0;
  undefined8 local_398;
  int local_388;
  undefined4 uStack_384;
  undefined4 uStack_380;
  undefined4 uStack_37c;
  undefined8 local_378;
  undefined8 uStack_370;
  undefined8 local_368;
  undefined8 uStack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  undefined8 local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined8 uStack_330;
  undefined8 local_328;
  undefined8 uStack_320;
  undefined8 local_318;
  undefined8 uStack_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined4 local_2a8;
  undefined4 uStack_2a4;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  int local_1c8;
  undefined4 uStack_1c4;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  char local_1a8 [40];
  undefined4 local_180;
  undefined4 local_178;
  wchar_t local_58 [20];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_4a8;
  local_468 = (ulonglong)(uint)local_468;
  local_398 = 0;
  iVar16 = 1;
  local_410 = 0;
  uStack_408 = 0;
  local_458[0] = 0;
  local_3f8 = 0;
  uStack_3f0 = 0;
  local_3e8 = 0;
  uStack_3e0 = 0;
  local_3d8 = 0;
  uStack_3d0 = 0;
  local_3c8 = 0;
  uStack_3c0 = 0;
  local_3b8 = 0;
  uStack_3b0 = 0;
  local_3a8 = 0;
  uStack_3a0 = 0;
  local_448[0] = (int *)0x0;
  local_448[1] = (int *)0x0;
  if (*(uint *)(param_1 + 6) < SmpNumberInitialSessions) {
    iVar17 = 0;
    lVar15 = SmpCoreProcessIds + (ulonglong)*(uint *)(param_1 + 6) * 0x28;
    RtlAcquireSRWLockShared(lVar15 + 8);
    iVar5 = *(int *)(lVar15 + 4);
    while (iVar5 == 0) {
      RtlSleepConditionVariableSRW(lVar15 + 0x10,lVar15 + 8,0,1);
      iVar5 = *(int *)(lVar15 + 4);
    }
    if (*(longlong *)(lVar15 + 0x20) == 0) {
      iVar17 = -0x3fffffff;
    }
    else {
      uVar10 = 0;
      do {
        iVar5 = (int)uVar10;
        piVar3 = *(int **)(lVar15 + 0x18 + uVar10 * 8);
        local_448[uVar10] = piVar3;
        if ((iVar5 == 0) && (local_448[0] != (int *)0x0)) {
          LOCK();
          *piVar3 = *piVar3 + 1;
          UNLOCK();
        }
        uVar6 = iVar5 + 1;
        piVar3 = *(int **)(lVar15 + 0x18 + (ulonglong)uVar6 * 8);
        local_448[uVar6] = piVar3;
        if ((uVar6 == 0) && (local_448[0] != (int *)0x0)) {
          LOCK();
          *piVar3 = *piVar3 + 1;
          UNLOCK();
        }
        uVar10 = (ulonglong)(iVar5 + 2U);
      } while (iVar5 + 2U < 2);
    }
    piVar3 = local_448[0];
    RtlReleaseSRWLockShared(lVar15 + 8);
    *(undefined4 *)(param_1 + 6) =
         *(undefined4 *)(SmpCoreProcessIds + (ulonglong)*(uint *)(param_1 + 6) * 0x28);
    if (-1 < iVar17) {
      memset(local_1a8,0,0x148);
      if ((piVar3 == (int *)0x0) || (piVar3[6] != 2)) {
        iVar17 = -0x3fffffff;
      }
      else {
        param_1[0x28] = *(undefined8 *)(piVar3 + 0xc);
      }
      if (piVar3 != (int *)0x0) {
        SmpDereferenceKnownSubSys(piVar3);
      }
      if (iVar17 < 0) {
        local_178 = *(undefined4 *)(param_1 + 6);
        local_180 = 6;
        SmpStopCsr((longlong)local_1a8);
        return iVar17;
      }
      param_1[0x27] = local_448[1];
      return 0;
    }
  }
  NtWaitForSingleObject(SmpSessionCreateBlockEvent,0,0);
  local_468._0_4_ =
       CONCAT22(*(undefined2 *)((longlong)param_1 + 0x34),*(undefined2 *)((longlong)param_1 + 0x34))
  ;
  uStack_460 = param_1 + 7;
  puVar7 = SmpAllocateControlBlock();
  if (puVar7 == (uint *)0x0) {
    memset(&local_368,0,0xe0);
    local_2a8 = 0xc000009a;
    uStack_290 = 0x1cc;
    pcVar12 = (char *)&local_368;
    lVar15 = 0x40;
    do {
      if ((lVar15 == -0x7fffffbe) ||
         (pcVar12[(longlong)"SmpStartCsr" - (longlong)&local_368] == '\0')) break;
      *pcVar12 = pcVar12[(longlong)"SmpStartCsr" - (longlong)&local_368];
      pcVar12 = pcVar12 + 1;
      lVar15 = lVar15 + -1;
    } while (lVar15 != 0);
    pcVar9 = pcVar12 + -1;
    if (lVar15 != 0) {
      pcVar9 = pcVar12;
    }
    *pcVar9 = '\0';
    LOCK();
    UNLOCK();
    uVar6 = DAT_140030ed4 + 1U & 0x8000000f;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
    }
    lVar15 = (longlong)(int)uVar6 * 0xe0;
    DAT_140030ed4 = DAT_140030ed4 + 1;
    *(undefined8 *)(&DAT_140030ed8 + lVar15) = local_368;
    *(undefined8 *)(lVar15 + 0x140030ee0) = uStack_360;
    *(undefined8 *)(&DAT_140030ee8 + lVar15) = local_358;
    *(undefined8 *)(lVar15 + 0x140030ef0) = uStack_350;
    *(undefined8 *)(&DAT_140030ef8 + lVar15) = local_348;
    *(undefined8 *)(lVar15 + 0x140030f00) = uStack_340;
    *(undefined8 *)(&DAT_140030f08 + lVar15) = local_338;
    *(undefined8 *)(lVar15 + 0x140030f10) = uStack_330;
    *(undefined8 *)(&DAT_140030f18 + lVar15) = local_328;
    *(undefined8 *)(lVar15 + 0x140030f20) = uStack_320;
    *(undefined8 *)(&DAT_140030f28 + lVar15) = local_318;
    *(undefined8 *)(lVar15 + 0x140030f30) = uStack_310;
    *(undefined8 *)(&DAT_140030f38 + lVar15) = local_308;
    *(undefined8 *)(lVar15 + 0x140030f40) = uStack_300;
    *(undefined8 *)(&DAT_140030f48 + lVar15) = local_2f8;
    *(undefined8 *)(lVar15 + 0x140030f50) = uStack_2f0;
    *(undefined8 *)(&DAT_140030f58 + lVar15) = local_2e8;
    *(undefined8 *)(lVar15 + 0x140030f60) = uStack_2e0;
    *(undefined8 *)(&DAT_140030f68 + lVar15) = local_2d8;
    *(undefined8 *)(lVar15 + 0x140030f70) = uStack_2d0;
    *(undefined8 *)(&DAT_140030f78 + lVar15) = local_2c8;
    *(undefined8 *)(lVar15 + 0x140030f80) = uStack_2c0;
    *(undefined8 *)(&DAT_140030f88 + lVar15) = local_2b8;
    *(undefined8 *)(lVar15 + 0x140030f90) = uStack_2b0;
    *(ulonglong *)(&DAT_140030f98 + lVar15) = CONCAT44(uStack_2a4,local_2a8);
    *(undefined8 *)(lVar15 + 0x140030fa0) = uStack_2a0;
    *(undefined8 *)(&DAT_140030fa8 + lVar15) = local_298;
    *(ulonglong *)(lVar15 + 0x140030fb0) = CONCAT44(uStack_28c,uStack_290);
    return -0x3fffff66;
  }
  uVar10 = *(ulonglong *)(puVar7 + 6);
  local_388 = (uint)local_468;
  uStack_384 = local_468._4_4_;
  uStack_380 = (undefined4)uStack_460;
  uStack_37c = uStack_460._4_4_;
  uVar14 = (ulonglong)(ushort)(uint)local_468 + (ulonglong)SmpHelperCmd + 0x28;
  if (uVar14 < 0x10000) {
    puVar8 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                             SmBaseTag + 0x80000,uVar14);
    if (puVar8 == (undefined8 *)0x0) {
      memset(local_1a8,0,0xe0);
      iVar5 = -0x3fffffe9;
      SmpInternalLogFailure(0x1400227b0,0x11d,0xc0000017,local_1a8);
      goto LAB_140004a33;
    }
    local_468._0_4_ = (uint)(ushort)uVar14 << 0x10;
    local_468._4_4_ = 0;
    uStack_460 = puVar8;
    RtlAppendUnicodeStringToString(&local_468,&SmpHelperCmd);
    RtlStringCbPrintfW(local_58,0x28,L" %08x %08x ",uVar10 & 0xffffffff);
    RtlAppendUnicodeToString(&local_468,local_58);
    RtlAppendUnicodeStringToString(&local_468,&local_388);
    local_450[0] = 0x1420;
    puVar19 = &local_420;
    uVar11 = 0;
    local_438 = 0;
    lStack_430 = 0;
    local_378 = 0;
    uStack_370 = 0;
    local_420 = 0;
    uStack_418 = 0;
    iVar5 = SmpParseCommandLine(&local_468,local_450,&local_438,0,puVar19);
    if (iVar5 < 0) {
      SmpLogFailureString(0x140022808,0x2789,(longlong)uStack_460,iVar5);
      RtlFreeUnicodeString(&local_468);
LAB_1400048b3:
      uVar13 = 0x1eb;
    }
    else {
      if ((local_450[0] & 4) == 0) {
        if ((local_450[0] & 8) != 0) {
          if (SmpPrimarySmss == '\0') {
            iVar5 = SmscpLoadSubSystem((ushort *)&local_438,0,(longlong)&local_468,
                                       (undefined8 **)0x0,local_450[0]);
          }
          else {
            iVar5 = SmpLoadSubSystem((ushort *)&local_438,0,&local_468,0,puVar19,local_450[0]);
          }
          goto LAB_14000432e;
        }
        if ((local_450[0] & 0x10) == 0) {
          iVar5 = SmpExecuteImage((ushort *)&local_438,0,&local_468,uVar11,(uint *)0x0,local_450[0],
                                  &local_3f8);
          goto LAB_14000432e;
        }
        iVar5 = -0x3fffffcc;
        SmpLogFailureString(0x140022808,0x27af,lStack_430,0xc0000034);
        RtlFreeUnicodeString(&local_438);
        RtlFreeUnicodeString(&local_420);
LAB_140004ad8:
        SmpLogFailureString(0x140022808,0x27ca,(longlong)uStack_460,iVar5);
      }
      else {
        if ((SmpSoftBoot == '\0') || (SmpBugcheckRecovery != '\0')) {
          uVar11 = SmpInvokeAutoChk((ushort *)&local_438,0,&local_420,(ulonglong)local_450[0]);
          iVar5 = (int)uVar11;
        }
LAB_14000432e:
        RtlFreeUnicodeString(&local_438);
        RtlFreeUnicodeString(&local_420);
        if (iVar5 < 0) goto LAB_140004ad8;
      }
      RtlFreeUnicodeString(&local_468);
      if (iVar5 < 0) goto LAB_1400048b3;
      iVar5 = NtQueryInformationProcess(uStack_3f0,0x18,local_458);
      if (iVar5 < 0) {
        NtTerminateProcess(uStack_3f0,iVar5);
        NtClose(uStack_3f0);
        NtClose(local_3e8);
        goto LAB_1400043d2;
      }
      puVar8 = *(undefined8 **)(puVar7 + 4);
      *puVar8 = *(undefined8 *)(puVar7 + 8);
      puVar8[1] = *(undefined8 *)(puVar7 + 10);
      *(undefined8 *)(puVar7 + 0xc) = uStack_3f0;
      *(undefined8 *)(puVar7 + 0xe) = uStack_3e0;
      puVar7[2] = local_458[0];
      LOCK();
      UNLOCK();
      if (SmpNumberInitialSessions < DAT_1400322f8 + 1) {
        LOCK();
        UNLOCK();
      }
      else {
        uVar10 = (ulonglong)DAT_1400322f8;
        DAT_1400322f8 = DAT_1400322f8 + 1;
        *(uint *)(SmpCoreProcessIds + uVar10 * 0x28) = local_458[0];
      }
      uVar11 = param_1[1];
      puVar1 = puVar7 + 0x1a;
      *(undefined8 *)(puVar7 + 0x10) = *param_1;
      *(undefined8 *)(puVar7 + 0x12) = uVar11;
      uVar6 = *(uint *)((longlong)param_1 + 0x14);
      uVar2 = *(uint *)(param_1 + 3);
      uVar4 = *(uint *)((longlong)param_1 + 0x1c);
      puVar7[0x14] = *(uint *)(param_1 + 2);
      puVar7[0x15] = uVar6;
      puVar7[0x16] = uVar2;
      puVar7[0x17] = uVar4;
      *(undefined8 *)(puVar7 + 0x18) = param_1[4];
      *(uint **)puVar1 = puVar1;
      puVar7[0x1c] = 0;
      puVar7[0x1d] = 0;
      puVar7[0x1e] = 0;
      puVar7[0x1f] = 0;
      puVar7[1] = puVar7[1] + 1;
      RtlAcquireSRWLockExclusive(&SmpControlLock);
      iVar5 = SmpInsertControlBlock((longlong)SmpControlBlockRoot,(longlong)puVar7);
      if (iVar5 != 0) {
        SmpControlBlockRoot = puVar1;
      }
      RtlReleaseSRWLockExclusive(&SmpControlLock);
      iVar5 = NtResumeThread(local_3e8,0);
      NtClose(local_3e8);
      if (iVar5 < 0) {
        if ((*puVar7 & 1) == 0) {
          LOCK();
          *puVar7 = *puVar7 | 1;
          UNLOCK();
        }
        SmpDestroyControlBlock(puVar7,1);
        goto LAB_1400043d2;
      }
      local_410 = *(undefined8 *)(puVar7 + 0xc);
      uStack_408 = *(undefined8 *)(puVar7 + 8);
      iVar5 = NtWaitForMultipleObjects(2,&local_410,1);
      if (iVar5 < 0) {
        memset(&local_288,0,0xe0);
        local_1c8 = iVar5;
        uStack_1b0 = 0x253;
        lVar15 = 0x40;
        pcVar12 = (char *)&local_288;
        do {
          if ((lVar15 == -0x7fffffbe) ||
             (pcVar12[(longlong)"SmpStartCsr" - (longlong)&local_288] == '\0')) break;
          *pcVar12 = pcVar12[(longlong)"SmpStartCsr" - (longlong)&local_288];
          pcVar12 = pcVar12 + 1;
          lVar15 = lVar15 + -1;
        } while (lVar15 != 0);
        pcVar9 = pcVar12 + -1;
        if (lVar15 != 0) {
          pcVar9 = pcVar12;
        }
        *pcVar9 = '\0';
        LOCK();
        UNLOCK();
        uVar6 = DAT_140030ed4 + 1U & 0x8000000f;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
        }
        lVar15 = (longlong)(int)uVar6 * 0xe0;
        DAT_140030ed4 = DAT_140030ed4 + 1;
        *(undefined8 *)(&DAT_140030ed8 + lVar15) = local_288;
        *(undefined8 *)(lVar15 + 0x140030ee0) = uStack_280;
        *(undefined8 *)(&DAT_140030ee8 + lVar15) = local_278;
        *(undefined8 *)(lVar15 + 0x140030ef0) = uStack_270;
        *(undefined8 *)(&DAT_140030ef8 + lVar15) = local_268;
        *(undefined8 *)(lVar15 + 0x140030f00) = uStack_260;
        *(undefined8 *)(&DAT_140030f08 + lVar15) = local_258;
        *(undefined8 *)(lVar15 + 0x140030f10) = uStack_250;
        *(undefined8 *)(&DAT_140030f18 + lVar15) = local_248;
        *(undefined8 *)(lVar15 + 0x140030f20) = uStack_240;
        *(undefined8 *)(&DAT_140030f28 + lVar15) = local_238;
        *(undefined8 *)(lVar15 + 0x140030f30) = uStack_230;
        *(undefined8 *)(&DAT_140030f38 + lVar15) = local_228;
        *(undefined8 *)(lVar15 + 0x140030f40) = uStack_220;
        *(undefined8 *)(&DAT_140030f48 + lVar15) = local_218;
        *(undefined8 *)(lVar15 + 0x140030f50) = uStack_210;
        *(undefined8 *)(&DAT_140030f58 + lVar15) = local_208;
        *(undefined8 *)(lVar15 + 0x140030f60) = uStack_200;
        *(undefined8 *)(&DAT_140030f68 + lVar15) = local_1f8;
        *(undefined8 *)(lVar15 + 0x140030f70) = uStack_1f0;
        *(undefined8 *)(&DAT_140030f78 + lVar15) = local_1e8;
        *(undefined8 *)(lVar15 + 0x140030f80) = uStack_1e0;
        *(undefined8 *)(&DAT_140030f88 + lVar15) = local_1d8;
        *(undefined8 *)(lVar15 + 0x140030f90) = uStack_1d0;
        *(ulonglong *)(&DAT_140030f98 + lVar15) = CONCAT44(uStack_1c4,local_1c8);
        *(undefined8 *)(lVar15 + 0x140030fa0) = uStack_1c0;
        *(undefined8 *)(&DAT_140030fa8 + lVar15) = local_1b8;
        *(ulonglong *)(lVar15 + 0x140030fb0) = CONCAT44(uStack_1ac,uStack_1b0);
        if ((*puVar7 & 1) != 0) {
LAB_140004660:
          SmpReleaseControlBlock((byte *)puVar7);
          return 0x103;
        }
        uVar6 = *puVar7;
        do {
          LOCK();
          uVar2 = *puVar7;
          bVar18 = uVar6 == uVar2;
          if (bVar18) {
            *puVar7 = uVar6 | 1;
          }
          else {
            uVar6 = uVar2;
          }
          UNLOCK();
        } while (!bVar18);
        if ((uVar6 & 1) != 0) goto LAB_140004660;
      }
      else {
        if (iVar5 != 0) goto LAB_140004660;
        local_428 = 0;
        NtQueryEvent(*(undefined8 *)(puVar7 + 8),0,&local_428,8);
        if (local_428._4_4_ == 0) {
          if ((*puVar7 & 1) == 0) {
            LOCK();
            *puVar7 = *puVar7 | 1;
            UNLOCK();
          }
          iVar16 = 0;
          iVar5 = -0x3fffffff;
        }
        else {
          iVar5 = NtClearEvent(*(undefined8 *)(puVar7 + 8));
          if (-1 < iVar5) goto LAB_140004660;
        }
      }
      SmpDestroyControlBlock(puVar7,iVar16);
      uVar13 = 0x286;
    }
  }
  else {
    iVar5 = -0x3ffffff3;
LAB_140004a33:
    uVar13 = 0x1d7;
  }
  SmpLogFailure(0x1400227a0,uVar13,iVar5);
LAB_1400043d2:
  SmpReleaseControlBlock((byte *)puVar7);
  return iVar5;
}



===== SmpAllocateControlBlock @ 140004b60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void * SmpAllocateControlBlock(void)

{
  int iVar1;
  void *_Dst;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStack_2c8 [32];
  ulonglong local_2a8;
  undefined8 local_2a0;
  longlong *local_298;
  undefined4 local_290;
  undefined4 local_288;
  undefined4 local_280;
  longlong local_278;
  longlong local_270;
  longlong local_268 [4];
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  ulonglong uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  ulonglong uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined8 local_118;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  char local_108 [224];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2c8;
  local_1f8 = 0;
  local_218 = 0;
  uStack_210 = 0;
  uStack_1f0 = uStack_1f0 & 0xffffffff00000000;
  local_208 = 0;
  uStack_200 = 0;
  local_268[1] = 0;
  local_278 = 0;
  _Dst = (void *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                 SmBaseTag + 0x80000,0x80);
  if (_Dst == (void *)0x0) {
    memset(&local_1e8,0,0xe0);
    local_128 = 0xc000009a;
    uStack_110 = 0xb9;
    lVar5 = 0x40;
    pcVar3 = (char *)&local_1e8;
    do {
      if ((lVar5 == -0x7fffffbe) ||
         (pcVar3[(longlong)"SmpAllocateControlBlock" - (longlong)&local_1e8] == '\0')) break;
      *pcVar3 = pcVar3[(longlong)"SmpAllocateControlBlock" - (longlong)&local_1e8];
      pcVar3 = pcVar3 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    pcVar2 = pcVar3 + -1;
    if (lVar5 != 0) {
      pcVar2 = pcVar3;
    }
    *pcVar2 = '\0';
    LOCK();
    UNLOCK();
    uVar4 = DAT_140030ed4 + 1U & 0x8000000f;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff0) + 1;
    }
    lVar5 = (longlong)(int)uVar4 * 0xe0;
    DAT_140030ed4 = DAT_140030ed4 + 1;
    *(undefined8 *)(&DAT_140030ed8 + lVar5) = local_1e8;
    *(undefined8 *)(lVar5 + 0x140030ee0) = uStack_1e0;
    *(undefined8 *)(&DAT_140030ee8 + lVar5) = local_1d8;
    *(undefined8 *)(lVar5 + 0x140030ef0) = uStack_1d0;
    *(undefined8 *)(&DAT_140030ef8 + lVar5) = local_1c8;
    *(undefined8 *)(lVar5 + 0x140030f00) = uStack_1c0;
    *(undefined8 *)(&DAT_140030f08 + lVar5) = local_1b8;
    *(undefined8 *)(lVar5 + 0x140030f10) = uStack_1b0;
    *(undefined8 *)(&DAT_140030f18 + lVar5) = local_1a8;
    *(undefined8 *)(lVar5 + 0x140030f20) = uStack_1a0;
    *(undefined8 *)(&DAT_140030f28 + lVar5) = local_198;
    *(undefined8 *)(lVar5 + 0x140030f30) = uStack_190;
    *(undefined8 *)(&DAT_140030f38 + lVar5) = local_188;
    *(undefined8 *)(lVar5 + 0x140030f40) = uStack_180;
    *(undefined8 *)(&DAT_140030f48 + lVar5) = local_178;
    *(undefined8 *)(lVar5 + 0x140030f50) = uStack_170;
    *(undefined8 *)(&DAT_140030f58 + lVar5) = local_168;
    *(undefined8 *)(lVar5 + 0x140030f60) = uStack_160;
    *(undefined8 *)(&DAT_140030f68 + lVar5) = local_158;
    *(undefined8 *)(lVar5 + 0x140030f70) = uStack_150;
    *(undefined8 *)(&DAT_140030f78 + lVar5) = local_148;
    *(undefined8 *)(lVar5 + 0x140030f80) = uStack_140;
    *(undefined8 *)(&DAT_140030f88 + lVar5) = local_138;
    *(undefined8 *)(lVar5 + 0x140030f90) = uStack_130;
    *(undefined4 *)(&DAT_140030f98 + lVar5) = local_128;
    *(undefined4 *)(lVar5 + 0x140030f9c) = uStack_124;
    *(undefined4 *)(lVar5 + 0x140030fa0) = uStack_120;
    *(undefined4 *)(lVar5 + 0x140030fa4) = uStack_11c;
    *(undefined8 *)(&DAT_140030fa8 + lVar5) = local_118;
    *(ulonglong *)(lVar5 + 0x140030fb0) = CONCAT44(uStack_10c,uStack_110);
  }
  else {
    local_298 = (longlong *)0x0;
    local_2a0 = CONCAT44(local_2a0._4_4_,0x8400000);
    local_2a8 = CONCAT44(local_2a8._4_4_,4);
    local_218 = CONCAT44(local_218._4_4_,0x30);
    uStack_210 = 0;
    local_1f8 = 0;
    uStack_1f0 = 0;
    uStack_200 = CONCAT44(uStack_200._4_4_,2);
    local_208 = 0;
    local_268[1] = 0x18;
    iVar1 = NtCreateSection(&local_278,6,&local_218,local_268 + 1);
    lVar5 = local_278;
    if (iVar1 < 0) {
      SmpLogFailure(0x140022788,0xce,iVar1);
      local_278 = 0;
      goto LAB_140004f63;
    }
    local_280 = 4;
    local_288 = 0;
    local_290 = 2;
    local_228 = 0;
    uStack_220 = uStack_220 & 0xffffffff00000000;
    local_298 = local_268 + 3;
    local_2a0 = 0;
    local_2a8 = 0;
    local_248 = 0;
    uStack_240 = 0;
    local_268[2] = 0;
    local_238 = 0;
    uStack_230 = 0;
    local_268[0] = 0;
    local_270 = 0;
    local_268[3] = 0;
    iVar1 = NtMapViewOfSection(local_278,0xffffffffffffffff,&local_270);
    if (iVar1 < 0) {
      SmpLogFailure(0x140022958,0x124,iVar1);
      local_270 = 0;
LAB_140004f2f:
      if (local_268[0] != 0) {
        NtClose();
      }
    }
    else {
      local_248 = CONCAT44(local_248._4_4_,0x30);
      uStack_240 = 0;
      uStack_230 = CONCAT44(uStack_230._4_4_,2);
      local_238 = 0;
      local_2a8 = local_2a8 & 0xffffffffffffff00;
      local_228 = 0;
      uStack_220 = 0;
      iVar1 = NtCreateEvent(local_268,0x1f0003,&local_248,1);
      if (-1 < iVar1) {
        local_2a8 = local_2a8 & 0xffffffffffffff00;
        iVar1 = NtCreateEvent(local_268 + 2,0x1f0003,&local_248,1);
        if (-1 < iVar1) {
          memset(_Dst,0,0x80);
          *(longlong *)((longlong)_Dst + 0x10) = local_270;
          *(longlong *)((longlong)_Dst + 0x20) = local_268[0];
          *(longlong *)((longlong)_Dst + 0x28) = local_268[2];
          *(longlong *)((longlong)_Dst + 0x18) = lVar5;
          *(undefined4 *)((longlong)_Dst + 4) = 1;
          return _Dst;
        }
        SmpLogFailure(0x140022958,0x145,iVar1);
        goto LAB_140004f2f;
      }
      memset(local_108,0,0xe0);
      SmpInternalLogFailure(0x140022958,0x137,iVar1,local_108);
      local_268[0] = 0;
    }
    if (local_270 != 0) {
      NtUnmapViewOfSection(0xffffffffffffffff);
    }
  }
  if (local_278 != 0) {
    NtClose();
  }
  if (_Dst == (void *)0x0) {
    return (void *)0x0;
  }
LAB_140004f63:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,_Dst);
  return (void *)0x0;
}



===== SmpParseCommandLine @ 140004fd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpParseCommandLine(undefined8 *param_1,uint *param_2,ulonglong *param_3,longlong param_4,
                       ulonglong *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  longlong lVar8;
  wint_t *pwVar9;
  wint_t *_Src;
  ulonglong *puVar10;
  undefined1 auStack_318 [32];
  wchar_t *local_2f8;
  wchar_t **local_2f0;
  int local_2e8;
  undefined8 local_2d8;
  void *pvStack_2d0;
  ulonglong local_2c8;
  void *pvStack_2c0;
  ulonglong local_2b8;
  void *pvStack_2b0;
  undefined8 local_2a8;
  wint_t *pwStack_2a0;
  wchar_t *local_298;
  longlong local_290;
  ulonglong *local_288;
  undefined8 local_280;
  wchar_t *local_278;
  wchar_t local_268 [264];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_318;
  local_278 = L"Path";
  local_280 = 0xa0008;
  local_298 = (wchar_t *)0x0;
  local_2e8 = 0;
  local_2d8 = 0;
  pvStack_2d0 = (void *)0x0;
  local_290 = param_4;
  local_288 = param_3;
  RtlInitUnicodeString(param_3,0);
  RtlInitUnicodeString(param_5,0);
  local_2a8 = *param_1;
  pwStack_2a0 = (wint_t *)param_1[1];
  uVar5 = (ushort)local_2a8;
  do {
    uVar6 = 0;
    RtlInitUnicodeString(&local_2d8,0);
    if (uVar5 != 0) {
      pwVar9 = pwStack_2a0;
      _Src = pwStack_2a0;
      if (uVar5 != 0) {
        do {
          iVar2 = iswctype(*pwVar9,8);
          _Src = pwVar9;
          if (iVar2 == 0) break;
          pwVar9 = pwVar9 + 1;
          uVar6 = uVar6 + 2;
          _Src = pwVar9;
        } while (uVar6 < uVar5);
      }
      while ((uVar6 < uVar5 && (iVar2 = iswctype(*pwVar9,8), iVar2 == 0))) {
        uVar6 = uVar6 + 2;
        pwVar9 = pwVar9 + 1;
      }
      uVar7 = (int)pwVar9 - (int)_Src;
      while ((uVar6 < uVar5 && (iVar2 = iswctype(*pwVar9,8), iVar2 != 0))) {
        pwVar9 = pwVar9 + 1;
        uVar6 = uVar6 + 2;
      }
      if (uVar7 != 0) {
        pvStack_2d0 = (void *)RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                              (ulonglong)uVar7 + 2);
        if (pvStack_2d0 == (void *)0x0) {
          return -0x3fffffff;
        }
        local_2d8._0_4_ = CONCAT22((short)uVar7 + 2,(short)uVar7);
        memcpy(pvStack_2d0,_Src,(ulonglong)uVar7);
        *(undefined2 *)((longlong)pvStack_2d0 + (ulonglong)(uVar7 >> 1) * 2) = 0;
        uVar5 = (ushort)local_2a8;
      }
      uVar5 = uVar5 + ((short)pwStack_2a0 - (short)pwVar9);
      local_2a8 = CONCAT62(local_2a8._2_6_,uVar5);
      pwStack_2a0 = pwVar9;
    }
    iVar2 = 0;
    if (pvStack_2d0 == (void *)0x0) {
      return -0x3fffffff;
    }
    if (param_2 == (uint *)0x0) {
      uVar4 = RtlStringCbPrintfW(local_268,0x208,L"%s",pvStack_2d0);
      iVar2 = (int)uVar4;
LAB_140005388:
      RtlFreeUnicodeString(&local_2d8);
      puVar10 = local_288;
      if (iVar2 < 0) {
        return iVar2;
      }
      cVar1 = RtlDosPathNameToNtPathName_U(local_268,local_288,0,0);
      lVar8 = local_290;
      if (cVar1 == '\0') {
        SmpLogFailureString(0x14002a2b8,0x2598,(longlong)local_268,0xc0000039);
        return -0x3fffffc7;
      }
      if (local_290 != 0) {
        if (local_268 < local_298) {
          local_298 = local_298 + -1;
          *local_298 = L'\0';
          cVar1 = RtlCreateUnicodeString(local_290,local_268);
          if (cVar1 == '\x01') goto LAB_1400054e4;
          iVar2 = -0x3fffffff;
        }
        RtlInitUnicodeString(lVar8,0);
        if (iVar2 < 0) goto LAB_14000566b;
      }
LAB_1400054e4:
      RtlInitUnicodeString(param_5,0);
      iVar2 = 0;
      if (uVar5 == 0) goto LAB_140005573;
      pwVar9 = pwStack_2a0;
      if (uVar5 != 0) break;
      goto LAB_14000550c;
    }
    cVar1 = RtlEqualUnicodeString(&local_2d8,&SmpDebugKeyword,1);
    if (cVar1 == '\0') {
      cVar1 = RtlEqualUnicodeString(&local_2d8,&SmpASyncKeyword,1);
      if (cVar1 == '\0') {
        cVar1 = RtlEqualUnicodeString(&local_2d8,&SmpSecureKeyword,1);
        if (cVar1 == '\0') {
          cVar1 = RtlEqualUnicodeString(&local_2d8,&SmpAutoChkKeyword,1);
          if (cVar1 == '\0') {
            if ((*param_2 >> 10 & 1) == 0) {
              if ((*param_2 & 8) != 0) {
                pvStack_2b0 = (void *)0x0;
                uVar5 = local_2d8._2_2_;
                if (local_2d8._2_2_ < 0x208) {
                  uVar5 = 0x208;
                }
                local_2b8 = (ulonglong)uVar5 << 0x10;
                pvStack_2b0 = (void *)RtlAllocateHeap(*(undefined8 *)
                                                       ((longlong)ProcessEnvironmentBlock + 0x30),
                                                      SmBaseTag,uVar5);
                if (pvStack_2b0 == (void *)0x0) {
                  return -0x3fffffe9;
                }
                local_2b8 = local_2b8 & 0xffffffffffff0000;
                iVar2 = RtlExpandEnvironmentStrings_U(SmpDefaultEnvironment,&local_2d8,&local_2b8,0)
                ;
                if (iVar2 < 0) {
                  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                              pvStack_2b0);
                  return iVar2;
                }
                RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pvStack_2d0)
                ;
                local_2d8 = local_2b8;
                pvStack_2d0 = pvStack_2b0;
                uVar5 = (ushort)local_2a8;
              }
              iVar3 = RtlCompareUnicodeString(&SmpS0InitCmd,&local_2d8,0);
              if (((iVar3 == 0) ||
                  (iVar3 = RtlCompareUnicodeString(&SmscpDefaultCmd,&local_2d8,0), iVar3 == 0)) ||
                 (iVar3 = RtlCompareUnicodeString(&SmpSetupClCmd,&local_2d8,0), iVar3 == 0)) {
                iVar3 = local_2e8;
              }
              else {
                local_2b8 = 0;
                pvStack_2b0 = (void *)0x0;
                RtlInitUnicodeString(&local_2b8,0);
                uVar4 = SmpDefaultEnvironment;
                local_2c8 = 0x10000000;
                iVar3 = 0;
                pvStack_2c0 = (void *)RtlAllocateHeap(*(undefined8 *)
                                                       ((longlong)ProcessEnvironmentBlock + 0x30),
                                                      SmBaseTag,0x1000);
                if (pvStack_2c0 == (void *)0x0) {
                  iVar2 = -0x3fffff66;
                }
                else {
                  iVar2 = RtlQueryEnvironmentVariable_U(uVar4,&local_280,&local_2c8);
                  if (iVar2 == -0x3fffffdd) {
                    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                pvStack_2c0);
                    local_2c8 = (ulonglong)CONCAT42((int)(local_2c8 >> 0x20),(short)local_2c8 + 2)
                                << 0x10;
                    pvStack_2c0 = (void *)RtlAllocateHeap(*(undefined8 *)
                                                           ((longlong)ProcessEnvironmentBlock + 0x30
                                                           ),SmBaseTag);
                    if (pvStack_2c0 == (void *)0x0) {
                      iVar2 = -0x3fffff66;
                      goto LAB_14000534e;
                    }
                    iVar2 = RtlQueryEnvironmentVariable_U(uVar4,&local_280,&local_2c8);
                  }
                  if (iVar2 < 0) {
                    SmpLogFailureString(0x14002a2a0,0x2474,(longlong)local_278,iVar2);
                    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                pvStack_2c0);
                    iVar2 = -0x3fffffcc;
                  }
                  else {
                    local_2f0 = &local_298;
                    local_2b8 = local_2c8;
                    pvStack_2b0 = pvStack_2c0;
                    local_2f8 = local_268;
                    iVar3 = RtlDosSearchPath_U(pvStack_2c0,pvStack_2d0,L".exe",0x208);
                  }
                }
LAB_14000534e:
                if (pvStack_2b0 != (void *)0x0) {
                  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                              pvStack_2b0);
                }
                uVar5 = (ushort)local_2a8;
              }
              if ((-1 < iVar2) && (iVar3 == 0)) {
                local_2f0 = &local_298;
                local_2f8 = local_268;
                iVar3 = RtlDosSearchPath_U(DAT_140033018,pvStack_2d0,L".exe",0x208);
                if (iVar3 == 0) {
                  *param_2 = *param_2 | 0x10;
                  *local_288 = local_2d8;
                  local_288[1] = (ulonglong)pvStack_2d0;
                  if (local_290 != 0) {
                    RtlInitUnicodeString(local_290,0);
                  }
                  return 0;
                }
              }
              goto LAB_140005388;
            }
            *local_288 = local_2d8;
            local_288[1] = (ulonglong)pvStack_2d0;
            puVar10 = local_288;
            goto LAB_1400054e4;
          }
          if (SmpPrimarySmss == '\0') {
            return -0x3ffffff3;
          }
          if (SmpHostSmss != '\0') {
            *param_2 = *param_2 | 4;
          }
        }
        else {
          *param_2 = *param_2 | 0x8000;
        }
      }
      else {
        *param_2 = *param_2 | 2;
      }
    }
    else {
      *param_2 = *param_2 | 1;
    }
    RtlFreeUnicodeString(&local_2d8);
  } while( true );
  while( true ) {
    pwVar9 = pwVar9 + 1;
    iVar2 = iVar2 + 2;
    if (uVar5 <= (ushort)iVar2) break;
    iVar3 = iswctype(*pwVar9,8);
    if (iVar3 == 0) break;
  }
LAB_14000550c:
  uVar7 = (uint)uVar5 + iVar2 * -2;
  if (uVar7 != 0) {
    _Dst = (void *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                   SmBaseTag,(ulonglong)uVar7 + 2);
    param_5[1] = (ulonglong)_Dst;
    if (_Dst == (void *)0x0) {
      iVar2 = -0x3fffffe9;
      goto LAB_140005667;
    }
    *(short *)param_5 = (short)uVar7;
    *(short *)((longlong)param_5 + 2) = (short)uVar7 + 2;
    memcpy(_Dst,pwVar9,(ulonglong)uVar7);
    *(undefined2 *)(param_5[1] + (ulonglong)(uVar7 >> 1) * 2) = 0;
  }
LAB_140005573:
  if (param_2 == (uint *)0x0) {
    return 0;
  }
  if ((*param_2 & 8) == 0) {
    return 0;
  }
  if ((short)*param_5 == 0) {
    return 0;
  }
  iVar2 = SmpExpandEnvironmentString(param_5);
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_140005667:
  lVar8 = local_290;
LAB_14000566b:
  RtlFreeUnicodeString(puVar10);
  if (lVar8 == 0) {
    return iVar2;
  }
  RtlFreeUnicodeString(lVar8);
  return iVar2;
}



===== RtlStringCbPrintfW @ 1400058d0 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _MaxCount;
  int iVar1;
  undefined8 uVar2;
  ulonglong _SizeInWords;
  undefined8 local_res20;
  
  _SizeInWords = param_2 >> 1;
  if (_SizeInWords - 1 < 0x7fffffff) {
    _MaxCount = _SizeInWords - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf_s(param_1,_SizeInWords,_MaxCount,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_MaxCount < (ulonglong)(longlong)iVar1)) {
      param_1[_MaxCount] = L'\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _MaxCount) {
      param_1[_MaxCount] = L'\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (_SizeInWords != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== SmpApiCallback @ 140005960 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SmpApiCallback(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  undefined8 uVar5;
  ushort uVar6;
  int iVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined8 uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  bool bVar15;
  undefined1 auStack_228 [32];
  undefined1 *local_208;
  undefined8 *local_200;
  ulonglong *local_1f8;
  undefined8 local_1f0;
  int local_1e8;
  uint local_1e4;
  uint *local_1e0;
  undefined4 local_1d8;
  undefined1 *local_1d0;
  int local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined8 local_1b8;
  ulonglong local_1b0 [5];
  undefined1 local_188 [4];
  ushort local_184;
  uint local_160;
  int local_15c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_228;
  memset(local_188,0,0x148);
  bVar4 = false;
  bVar3 = false;
  local_1b8 = 0;
  bVar15 = false;
  local_1c4 = 0;
  RtlSetThreadIsCritical(1,0);
  uVar5 = SmpApiConnectionPort;
  local_1d0 = (undefined1 *)0x0;
  local_1b0[0] = 0;
  local_1b0[1] = 0;
  local_1b0[2] = 0;
  local_1b0[3] = 0;
  local_1b0[4] = 0;
  AlpcInitializeMessageAttribute(0x20000000,local_1b0,0x28,&local_1b8);
  local_1d8 = 0;
  do {
    local_1b8 = 0x148;
    local_1b0[0] = local_1b0[0] | 0x2000000000000000;
    local_1f0 = 0;
    local_1f8 = local_1b0;
    local_200 = &local_1b8;
    local_208 = local_188;
    iVar7 = NtAlpcSendWaitReceivePort(uVar5,0x10000,0,0);
    local_1e8 = iVar7;
  } while (iVar7 < 0);
  puVar8 = (undefined8 *)AlpcGetMessageAttribute(local_1b0,0x20000000);
  puVar13 = (uint *)*puVar8;
  local_1e0 = puVar13;
  lVar9 = AlpcGetMessageAttribute(local_1b0,0x20000000);
  uVar14 = *(uint *)(lVar9 + 0x10);
  uVar6 = local_184 & 0xff;
  local_1d8 = 0;
  local_1e4 = uVar14;
  if (uVar6 == 1) {
    local_1d0 = local_188;
    if (local_160 < 9) {
      if (*(int *)(&DAT_140021a48 + (longlong)(int)local_160 * 0x10) != 0) {
        iVar7 = 0;
        local_1c8 = 0;
        RtlAcquireSRWLockExclusive(param_2);
        *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
        if (*(uint *)(param_2 + 0x10) < *(int *)(param_2 + 0x14) + 1U) {
          iVar12 = *(int *)(param_2 + 0x14) + 1;
          iVar7 = TpSetPoolMinThreads(*(undefined8 *)(param_2 + 8),iVar12);
          local_1c8 = iVar7;
          if (iVar7 < 0) {
            *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + -1;
          }
          else {
            *(int *)(param_2 + 0x10) = iVar12;
          }
        }
        RtlReleaseSRWLockExclusive(param_2);
        puVar13 = local_1e0;
        local_1e8 = iVar7;
        if (iVar7 < 0) {
          local_15c = -0x3fffff66;
          uVar14 = local_1e4;
          goto LAB_140005baa;
        }
        bVar15 = true;
        local_1c4 = 1;
      }
      uVar14 = local_1e4;
      local_15c = 0x103;
      if (local_160 != 8) {
        if (local_160 != 1) {
          switch(local_160) {
          case 0:
          case 2:
            break;
          default:
            goto switchD_140005e4a_caseD_1;
          case 3:
          case 4:
            goto switchD_140005e4a_caseD_3;
          case 5:
          case 6:
          case 7:
            goto switchD_140005e4a_caseD_5;
          }
        }
        if ((*puVar13 & 0x10) == 0) {
          iVar7 = -0x3ffffff3;
          local_1e8 = -0x3ffffff3;
        }
        else {
switchD_140005e4a_caseD_3:
          iVar7 = (*(code *)(&SmpApiDispatch)[(longlong)(int)local_160 * 2])
                            (local_188,puVar13,uVar5);
          local_1e8 = iVar7;
        }
        goto switchD_140005e4a_caseD_1;
      }
switchD_140005e4a_caseD_5:
      if ((*puVar13 & 6) == 0) {
        iVar7 = SmpEstablishClientSecurity(local_188,puVar13);
        local_1e8 = iVar7;
      }
      if (-1 < iVar7) {
        if ((*puVar13 & 4) == 0) {
          iVar7 = -0x3fffffde;
          local_1e8 = -0x3fffffde;
        }
        else {
          iVar7 = (*(code *)(&SmpApiDispatch)[(longlong)(int)local_160 * 2])
                            (local_188,puVar13,uVar5);
          local_1e8 = iVar7;
        }
      }
      if ((local_160 == 5) && (iVar7 == 0x103)) {
        local_1d0 = (undefined1 *)0x0;
      }
      else {
switchD_140005e4a_caseD_1:
        local_15c = iVar7;
      }
      bVar3 = bVar4;
      if (bVar15) {
        RtlAcquireSRWLockExclusive(param_2);
        *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + -1;
        if (*(int *)(param_2 + 0x14) + 1U < *(uint *)(param_2 + 0x10)) {
          iVar12 = *(int *)(param_2 + 0x14) + 1;
          iVar7 = TpSetPoolMinThreads(*(undefined8 *)(param_2 + 8),iVar12);
          if (-1 < iVar7) {
            *(int *)(param_2 + 0x10) = iVar12;
          }
        }
        RtlReleaseSRWLockExclusive(param_2);
        puVar13 = local_1e0;
        uVar14 = local_1e4;
      }
    }
    else {
      local_15c = -0x3ffffffe;
      bVar3 = bVar4;
    }
  }
  else if (uVar6 == 10) {
    SmpHandleConnectionRequest
              (uVar5,(longlong)local_188,(longlong)local_1b0,(uint)(local_184 >> 0xf));
    bVar3 = bVar4;
  }
  else if (uVar6 == 5) {
    local_1d8 = 1;
    bVar3 = true;
  }
  else {
    bVar3 = bVar4;
    if ((local_184 >> 0xd & 1) != 0) {
      uVar10 = AlpcGetMessageAttribute(local_1b0,0x20000000);
      NtAlpcCancelMessage(uVar5,0,uVar10);
      local_1d0 = local_188;
    }
  }
LAB_140005baa:
  if (puVar13 != (uint *)0x0) {
    RtlAcquireSRWLockExclusive(puVar13 + 6);
    if (bVar3) {
      *puVar13 = *puVar13 | 1;
    }
    if (puVar13[1] < uVar14) {
      uVar11 = (puVar13[2] - puVar13[1]) + -1 + uVar14;
      puVar13[2] = uVar11;
      puVar13[1] = uVar14;
    }
    else {
      uVar11 = puVar13[2] - 1;
      puVar13[2] = uVar11;
    }
    uVar14 = *puVar13;
    if (((uVar14 & 1) == 0) || (uVar11 != 0)) {
      RtlReleaseSRWLockExclusive(puVar13 + 6);
    }
    else {
      puVar1 = puVar13 + 8;
      if ((uVar14 & 0x10) == 0) {
        if ((uVar14 & 8) == 0) {
          if (*(longlong *)puVar1 != 0) {
            NtClose();
          }
        }
        else {
          puVar2 = *(uint **)puVar1;
          local_1c0 = 0;
          if ((*puVar2 & 2) == 0) {
            uVar14 = *puVar2;
            do {
              LOCK();
              uVar11 = *puVar2;
              bVar15 = uVar14 == uVar11;
              if (bVar15) {
                *puVar2 = uVar14 | 2;
              }
              else {
                uVar14 = uVar11;
              }
              UNLOCK();
            } while (!bVar15);
            if ((uVar14 & 2) == 0) {
              SmpReleaseControlBlock((byte *)puVar2);
            }
            puVar13 = local_1e0;
          }
          NtWaitForSingleObject(*(undefined8 *)(puVar2 + 0xc),0,0);
          SmpReleaseControlBlock(*(byte **)puVar1);
        }
      }
      else {
        SmpDereferenceKnownSubSys(*(int **)puVar1);
      }
      NtAlpcDisconnectPort(*(undefined8 *)(puVar13 + 4),1);
      NtClose(*(undefined8 *)(puVar13 + 4));
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_1e0);
    }
  }
  if (local_1d0 != (undefined1 *)0x0) {
    local_1f0 = 0;
    local_1f8 = (ulonglong *)0x0;
    local_200 = (undefined8 *)0x0;
    local_208 = (undefined1 *)0x0;
    local_1e8 = NtAlpcSendWaitReceivePort(uVar5,0x10000,local_1d0,0);
  }
  RtlSetThreadIsCritical(0,0,1);
  return;
}



===== SmpReleaseControlBlock @ 140005ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpReleaseControlBlock(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_1a8 [32];
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined8 local_148;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1a8;
  memset(&local_168,0,0x148);
  LOCK();
  pbVar1 = param_1 + 4;
  iVar2 = *(int *)pbVar1;
  *(int *)pbVar1 = *(int *)pbVar1 + -1;
  UNLOCK();
  if (iVar2 < 2) {
    lVar3 = *(longlong *)(param_1 + 0x30);
    if (lVar3 != 0) {
      if (((*param_1 & 1) == 0) && (*(longlong *)(param_1 + 0x48) != SmpUniqueProcessId)) {
        local_168 = *(undefined8 *)(param_1 + 0x40);
        uStack_160 = *(undefined8 *)(param_1 + 0x48);
        local_138 = *(undefined4 *)(param_1 + 8);
        local_158 = *(undefined4 *)(param_1 + 0x50);
        uStack_154 = *(undefined4 *)(param_1 + 0x54);
        uStack_150 = *(undefined4 *)(param_1 + 0x58);
        uStack_14c = *(undefined4 *)(param_1 + 0x5c);
        local_148 = *(undefined8 *)(param_1 + 0x60);
        local_170 = 0;
        local_178 = 0;
        local_180 = 0;
        local_188 = 0;
        local_140 = 5;
        local_13c = 0xc0000001;
        NtAlpcSendWaitReceivePort(SmpApiConnectionPort,0x10000,&local_168,0);
      }
      RtlAcquireSRWLockExclusive(&SmpControlLock);
      RtlDeleteNoSplay(param_1 + 0x68,&SmpControlBlockRoot);
      RtlReleaseSRWLockExclusive(&SmpControlLock);
      NtClose(lVar3);
    }
    NtClose(*(undefined8 *)(param_1 + 0x20));
    NtClose(*(undefined8 *)(param_1 + 0x28));
    NtUnmapViewOfSection(0xffffffffffffffff,*(undefined8 *)(param_1 + 0x10));
    NtClose(*(undefined8 *)(param_1 + 0x18));
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
  }
  return;
}



===== SmpHandleConnectionRequest @ 1400061a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpHandleConnectionRequest(undefined8 param_1,longlong param_2,longlong param_3,int param_4)

{
  uint uVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint *puVar9;
  int *piVar10;
  undefined7 extraout_var;
  undefined8 *puVar11;
  int *piVar12;
  uint *puVar13;
  uint *puVar14;
  longlong lVar15;
  short *psVar16;
  short *psVar17;
  char cVar18;
  char cVar19;
  int *piVar20;
  ulonglong uVar21;
  bool bVar22;
  undefined1 auStack_298 [32];
  undefined8 local_278;
  uint *local_270;
  longlong local_268;
  longlong local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 local_248;
  char local_238;
  char local_237;
  uint local_234;
  uint local_230 [2];
  uint *local_228;
  int *local_220;
  uint local_218;
  uint *local_210;
  longlong local_208;
  int local_200 [2];
  undefined8 uStack_1f8;
  int *local_1f0;
  int local_1e8 [2];
  int *local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  longlong lStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  ulonglong uStack_188;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  uint local_16c;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  char local_128 [64];
  short local_e8 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_298;
  uStack_1f8._0_4_ = 0;
  local_200[0] = 0;
  local_200[1] = 0;
  local_190 = 0;
  cVar18 = '\0';
  cVar19 = '\0';
  uStack_188 = uStack_188 & 0xffffffff00000000;
  local_218 = local_218 & 0xffffff00;
  piVar20 = (int *)(param_2 + 0x28);
  puVar9 = (uint *)0x0;
  piVar12 = (int *)0x0;
  bVar3 = true;
  local_1d0 = 0;
  local_1c0 = 0;
  lStack_1b8 = 0;
  local_228 = (uint *)0x0;
  local_1b0 = 0;
  uStack_1a8 = 0;
  local_230[0] = 0;
  local_1a0 = 0;
  uStack_198 = 0;
  local_1e8[1] = 0;
  local_234 = 0;
  local_238 = '\0';
  local_208 = param_3;
  local_1c8 = param_1;
  if ((*(longlong *)(param_2 + 8) == SmpUniqueProcessId) || (param_4 != 0)) {
    piVar8 = (int *)0x0;
LAB_140006601:
    puVar13 = (uint *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                      SmBaseTag + 0x80000,0x28);
    puVar11 = (undefined8 *)CONCAT44(uStack_1f8._4_4_,(undefined4)uStack_1f8);
    if (puVar13 == (uint *)0x0) {
      bVar3 = false;
      local_218 = local_218 & 0xff;
      if (local_238 != '\0') {
        local_218 = 1;
      }
    }
    else {
      RtlInitializeSRWLock(puVar13 + 6);
      puVar13[2] = 0;
      if (piVar8 == (int *)0x0) {
        puVar14 = local_228;
        if (local_234 != 0) {
          puVar14 = puVar9;
        }
        *(uint **)(puVar13 + 8) = puVar14;
      }
      else {
        local_234 = local_234 | 0x10;
        *(int **)(puVar13 + 8) = piVar8;
      }
      *puVar13 = local_234;
      *(uint *)(local_208 + 4) = *(uint *)(local_208 + 4) | 0x20000000;
      puVar13[4] = 0;
      puVar13[5] = 0;
      RtlAcquireSRWLockExclusive(puVar13 + 6);
      puVar11 = (undefined8 *)CONCAT44(uStack_1f8._4_4_,(undefined4)uStack_1f8);
    }
  }
  else {
    uStack_1a8 = 0;
    local_270 = (uint *)&local_1b0;
    uStack_198 = 0;
    local_1a0 = 0;
    local_278 = CONCAT44(local_278._4_4_,0x100441);
    local_1b0 = 0x30;
    local_190 = 0;
    uStack_188 = 0;
    iVar6 = NtAlpcOpenSenderProcess(&local_228,param_1,param_2);
    puVar11 = (undefined8 *)CONCAT44(uStack_1f8._4_4_,(undefined4)uStack_1f8);
    if (iVar6 < 0) {
      bVar3 = false;
      piVar8 = (int *)0x0;
      local_228 = (uint *)0x0;
    }
    else {
      SmpGetProcessMuSessionId(local_228,local_230);
      local_1e8[0] = 0;
      local_1e0 = (int *)0x0;
      local_1d8 = *(undefined8 *)(param_2 + 8);
      piVar8 = SmpSearchKnownSubSysDatabase(local_230[0],local_1e8);
      uStack_1f8 = (undefined8 *)CONCAT44(uStack_1f8._4_4_,(undefined4)uStack_1f8);
      if (piVar8 == (int *)0x0) {
        puVar9 = (uint *)SmpLookupControlBlock(local_230[0]);
        puVar11 = (undefined8 *)CONCAT44(uStack_1f8._4_4_,(undefined4)uStack_1f8);
        uStack_1f8 = (undefined8 *)CONCAT44(uStack_1f8._4_4_,(undefined4)uStack_1f8);
        if (puVar9 == (uint *)0x0) goto LAB_1400064b9;
        local_1f0 = *(int **)(puVar9 + 4);
        if (*(longlong *)(local_1f0 + 2) == *(longlong *)(param_2 + 8)) {
          piVar10 = (int *)SmpCreateKnownSubSys(1);
          local_200[0] = 0;
          local_1e0 = local_200;
          uStack_1f8 = (undefined8 *)(SmpKnownSubSysTable + (ulonglong)(local_230[0] & 0x1f) * 0x18)
          ;
          RtlAcquireSRWLockExclusive(uStack_1f8 + 2);
          local_210 = (uint *)uStack_1f8;
LAB_140006334:
          puVar11 = *(undefined8 **)local_210;
          uVar21 = (ulonglong)local_230[0];
          while( true ) {
            uVar7 = local_230[0];
            if ((uint *)puVar11 == local_210) goto LAB_1400063b6;
            if (*(uint *)(puVar11 + -1) == local_230[0]) break;
            puVar11 = (undefined8 *)*puVar11;
          }
          local_220 = (int *)(puVar11 + -9);
          puVar13 = local_210;
          if (local_220 != (int *)0x0) {
            do {
              if ((*(byte *)(local_220 + 2) & 1) == 0) {
                puVar11 = (undefined8 *)*puVar11;
              }
              else {
                piVar12 = local_220;
                bVar22 = SmpCheckSubSysStatus((longlong)local_220);
                if ((int)CONCAT71(extraout_var,bVar22) == 0) {
                  LOCK();
                  *piVar12 = *piVar12 + 1;
                  UNLOCK();
                  SmpWaitForStatusChange((longlong)piVar12,0,local_200);
                  if ((*(byte *)(local_220 + 2) & 4) != 0) goto LAB_14000640d;
                  SmpDereferenceKnownSubSys(local_220);
                  uVar21 = (ulonglong)local_230[0];
                  piVar12 = local_220;
                  puVar13 = local_210;
                }
                puVar11 = *(undefined8 **)(piVar12 + 0x12);
              }
              uVar7 = (uint)uVar21;
              if (((uint *)puVar11 == puVar13) ||
                 (local_220 = (int *)(puVar11 + -9), *(uint *)(puVar11 + -1) != uVar7)) break;
            } while( true );
          }
LAB_1400063b6:
          piVar12 = piVar10;
          cVar19 = cVar18;
          if ((*local_1f0 == 0) && (*(longlong *)(local_1f0 + 2) == *(longlong *)(param_2 + 8))) {
            piVar8 = SmpSearchKnownSubSysDatabase(uVar7,local_1e8);
            local_1e8[0] = 1;
            local_1d8 = CONCAT44(local_1d8._4_4_,*piVar20);
            if (piVar8 == (int *)0x0) {
              piVar8 = SmpSearchKnownSubSysDatabase(local_230[0],local_1e8);
              if (piVar8 == (int *)0x0) {
                if (piVar10 == (int *)0x0) {
                  SmpLogFailure(0x1400227e8,0x40c,0);
                  bVar3 = false;
                }
                else {
                  piVar10[0x10] = local_230[0];
                  *(uint **)(piVar10 + 8) = local_228;
                  piVar10[6] = *piVar20;
                  piVar12 = (int *)0x0;
                  local_228 = (uint *)0x0;
                  SmpAddKnownSubSys((longlong)local_200,piVar10);
                  cVar19 = '\x01';
                  piVar8 = piVar10;
                }
              }
              else {
                SmpLogFailure(0x1400227e8,0x402,0);
                bVar3 = false;
              }
            }
            else {
              SmpLogFailure(0x1400227e8,0x3f8,0);
              bVar3 = false;
            }
          }
          if (local_200[0] == 1) {
            RtlReleaseSRWLockShared();
          }
          else {
            RtlReleaseSRWLockExclusive(uStack_1f8 + 2);
          }
          goto LAB_1400064b9;
        }
        uStack_1f8 = puVar11;
        if (*(longlong *)(puVar9 + 0xe) != *(longlong *)(param_2 + 8)) goto LAB_1400064b9;
        local_234 = 8;
        cVar19 = '\x01';
      }
      else {
LAB_1400064b9:
        puVar11 = uStack_1f8;
      }
      uStack_1f8._4_4_ = (undefined4)((ulonglong)puVar11 >> 0x20);
      uStack_1f8._0_4_ = SUB84(puVar11,0);
      local_220 = (int *)CONCAT44(local_220._4_4_,local_234);
      local_238 = cVar19;
      local_237 = cVar19;
      local_210 = puVar9;
      if (piVar8 == (int *)0x0) {
        if (bVar3) goto LAB_140006601;
      }
      else if (bVar3) {
        if ((*(byte *)(piVar8 + 2) & 1) == 0) {
          local_1d8 = CONCAT44(local_1d8._4_4_,*piVar20);
          local_1e8[0] = 1;
          local_1e0 = (int *)0x0;
          uStack_1f8 = puVar11;
          piVar12 = SmpSearchKnownSubSysDatabase(local_230[0],local_1e8);
          if (piVar12 != (int *)0x0) {
            bVar3 = false;
            SmpLogFailure(0x1400227e8,0x44c,0);
            local_238 = local_237;
            local_234 = (uint)local_220;
            puVar11 = uStack_1f8;
            goto LAB_1400065f7;
          }
          local_234 = (uint)local_220;
          puVar11 = uStack_1f8;
        }
        uStack_1f8._4_4_ = (undefined4)((ulonglong)puVar11 >> 0x20);
        uStack_1f8._0_4_ = SUB84(puVar11,0);
        uVar7 = piVar8[2];
        do {
          LOCK();
          uVar1 = piVar8[2];
          bVar22 = uVar7 == uVar1;
          if (bVar22) {
            piVar8[2] = uVar7 | 2;
          }
          else {
            uVar7 = uVar1;
          }
          UNLOCK();
        } while (!bVar22);
        local_238 = local_237;
        if ((uVar7 & 2) == 0) goto LAB_140006601;
        bVar3 = false;
        local_238 = local_237;
        uStack_1f8 = puVar11;
        SmpLogFailure(0x1400227e8,0x460,0);
        local_238 = local_237;
        local_234 = (uint)local_220;
        puVar9 = local_210;
        puVar11 = uStack_1f8;
      }
    }
LAB_1400065f7:
    puVar13 = (uint *)0x0;
  }
  local_258 = CONCAT71(local_258._1_7_,bVar3);
  local_260 = local_208;
  local_278 = 0;
  local_270 = puVar13;
  local_268 = param_2;
  uStack_1f8 = puVar11;
  iVar6 = NtAlpcAcceptConnectPort(&local_1d0,local_1c8,0,0);
  if (bVar3 == false) {
LAB_140006976:
    if ((char)local_218 == '\0') goto LAB_140006996;
  }
  else {
    if (-1 < iVar6) {
      lVar15 = AlpcGetMessageAttribute(local_208,0x20000000);
      puVar13[1] = *(uint *)(lVar15 + 0x10);
      *(undefined8 *)(puVar13 + 4) = local_1d0;
      RtlReleaseSRWLockExclusive(puVar13 + 6);
      if (piVar8 == (int *)0x0) {
        if ((local_234 & 8) == 0) {
          if (local_228 != (uint *)0x0) {
            local_228 = (uint *)0x0;
          }
        }
        else {
          puVar9 = (uint *)0x0;
        }
      }
      else {
        local_208 = 0;
        local_16c = local_16c & 0xffff;
        local_160 = 0;
        local_158 = 0;
        uStack_150 = 0;
        local_148 = 0;
        uStack_140 = 0;
        local_138 = 0;
        *(undefined2 *)(param_2 + 0x11a) = 0;
        RtlInitUnicodeStringEx(&local_1c0,param_2 + 0x2c);
        local_248 = 0;
        local_250 = 0;
        local_258 = 0;
        local_260 = 0;
        local_268 = 0;
        local_270 = (uint *)0x0;
        local_278 = CONCAT44(local_278._4_4_,0x20000);
        local_178 = 0;
        local_16c = 0x101;
        local_160 = 0;
        local_158 = 0;
        uStack_150 = 0;
        local_148 = 0;
        uStack_140 = 0;
        local_138 = 0;
        local_174 = 0xc;
        local_170 = 1;
        local_168 = 0x120;
        iVar6 = NtAlpcConnectPort(&local_208,&local_1c0,0,&local_178);
        if (iVar6 < 0) {
          memset(local_128,0,0xe0);
          if (lStack_1b8 != 0) {
            lVar15 = 0x40;
            psVar17 = local_e8;
            do {
              if ((lVar15 == -0x7fffffbe) ||
                 (sVar2 = *(short *)((longlong)psVar17 + (lStack_1b8 - (longlong)local_e8)),
                 sVar2 == 0)) break;
              *psVar17 = sVar2;
              psVar17 = psVar17 + 1;
              lVar15 = lVar15 + -1;
            } while (lVar15 != 0);
            psVar16 = psVar17 + -1;
            if (lVar15 != 0) {
              psVar16 = psVar17;
            }
            *psVar16 = 0;
          }
          SmpInternalLogFailure(0x1400227e8,0x4e4,iVar6,local_128);
        }
        else {
          *(longlong *)(piVar8 + 10) = local_208;
        }
        if (puVar9 != (uint *)0x0) {
          NtSetEvent(*(undefined8 *)(puVar9 + 10),0);
        }
        if ((*(byte *)(piVar8 + 2) & 1) != 0) {
          piVar20 = (int *)(param_2 + 8);
        }
        lVar15 = SmpKnownSubSysTable + (ulonglong)(piVar8[0x10] & 0x1f) * 0x18;
        RtlAcquireSRWLockExclusive(lVar15 + 0x10);
        if ((*(byte *)(piVar8 + 2) & 1) == 0) {
          piVar8[6] = *piVar20;
        }
        else {
          iVar6 = piVar20[1];
          iVar4 = piVar20[2];
          iVar5 = piVar20[3];
          piVar8[0xc] = *piVar20;
          piVar8[0xd] = iVar6;
          piVar8[0xe] = iVar4;
          piVar8[0xf] = iVar5;
        }
        RtlReleaseSRWLockExclusive(lVar15 + 0x10);
        if (*(longlong *)(piVar8 + 4) != 0) {
          LOCK();
          piVar8 = piVar8 + 4;
          piVar20 = *(int **)piVar8;
          piVar8[0] = 0;
          piVar8[1] = 0;
          UNLOCK();
          if (piVar20 != (int *)0x0) {
            if (*piVar20 == 0) {
              SmpDisposeSubSysSynch((undefined8 *)piVar20);
            }
            else {
              NtSetEvent(*(undefined8 *)(piVar20 + 2),0);
            }
          }
        }
        RtlWakeAllConditionVariable(&SmpSubSysReadyCondition);
        piVar8 = (int *)0x0;
      }
      goto LAB_140006976;
    }
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar13);
    if (local_238 == '\0') goto LAB_140006976;
  }
  if (piVar8 != (int *)0x0) {
    SmpDeleteSubSys(piVar8);
  }
  SmpDestroyControlBlock(puVar9,1);
LAB_140006996:
  if (local_228 != (uint *)0x0) {
    NtClose();
  }
  if (piVar8 != (int *)0x0) {
    SmpDereferenceKnownSubSys(piVar8);
  }
  if (piVar12 != (int *)0x0) {
    SmpDereferenceKnownSubSys(piVar12);
  }
  if (puVar9 != (uint *)0x0) {
    SmpReleaseControlBlock((byte *)puVar9);
  }
  return;
LAB_14000640d:
  SmpDereferenceKnownSubSys(local_220);
  goto LAB_140006334;
}



===== SmpDereferenceKnownSubSys @ 140006a10 =====

void SmpDereferenceKnownSubSys(int *param_1)

{
  int iVar1;
  code *pcVar2;
  longlong *plVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 *local_18;
  undefined8 local_10;
  
  if (param_1 != (int *)0x0) {
    LOCK();
    iVar1 = *param_1;
    *param_1 = *param_1 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      if ((((*(byte *)(param_1 + 2) & 4) != 0) && (param_1[6] == 2)) &&
         (param_1[0x10] == *SmpCoreProcessIds)) {
        local_28 = 0;
        uStack_20 = 0;
        RtlInitUnicodeString(&local_28,L"Core Windows subsystem terminated");
        local_10 = 0xffffffffc0000001;
        local_18 = &local_28;
                    /* WARNING: Subroutine does not return */
        SmpTerminate(&local_18,1,2);
      }
      if (*(undefined8 **)(param_1 + 4) != (undefined8 *)0x0) {
        SmpDisposeSubSysSynch(*(undefined8 **)(param_1 + 4));
      }
      if (*(longlong *)(param_1 + 10) != 0) {
        NtClose();
      }
      if ((*(byte *)(param_1 + 2) & 8) == 0) {
        if (*(longlong *)(param_1 + 8) != 0) {
          NtClose();
        }
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
      }
      else {
        plVar3 = (longlong *)(param_1 + 0x12);
        if ((longlong **)SmpOverflowSubSysList[1] != &SmpOverflowSubSysList) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(3);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        *plVar3 = (longlong)SmpOverflowSubSysList;
        *(longlong ***)(param_1 + 0x14) = &SmpOverflowSubSysList;
        SmpOverflowSubSysList[1] = (longlong)plVar3;
        SmpOverflowSubSysList = plVar3;
      }
    }
  }
  return;
}



===== SmpExpandEnvironmentString @ 140006b50 =====

int SmpExpandEnvironmentString(ulonglong *param_1)

{
  ushort uVar1;
  int iVar2;
  ulonglong local_18;
  ulonglong uStack_10;
  
  uVar1 = *(ushort *)((longlong)param_1 + 2);
  uStack_10 = 0;
  if (uVar1 < 0x208) {
    local_18 = 0x2080000;
    uVar1 = 0x208;
  }
  else {
    local_18 = (ulonglong)uVar1 << 0x10;
  }
  uStack_10 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                              uVar1);
  if (uStack_10 == 0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    local_18 = local_18 & 0xffffffffffff0000;
    iVar2 = RtlExpandEnvironmentStrings_U(SmpDefaultEnvironment,param_1,&local_18,0);
    if (iVar2 < 0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,uStack_10);
    }
    else {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1[1]);
      *param_1 = local_18;
      param_1[1] = uStack_10;
    }
  }
  return iVar2;
}



===== SmpTerminateCSR @ 140006c40 =====

undefined8 SmpTerminateCSR(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  longlong *****ppppplVar3;
  longlong ****pppplVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  undefined8 *puVar8;
  longlong ******pppppplVar9;
  undefined8 uVar10;
  undefined7 extraout_var;
  int *piVar11;
  undefined8 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  longlong ******pppppplVar15;
  int *piVar16;
  longlong ******in_R11;
  uint unaff_R14D;
  undefined1 local_68 [48];
  longlong ******local_38;
  longlong ******local_30;
  int local_28 [2];
  undefined8 *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_30 = (longlong ******)&local_38;
  local_38 = (longlong ******)&local_38;
  puVar12 = (undefined8 *)(SmpKnownSubSysTable + (ulonglong)(param_1 & 0x1f) * 0x18);
  local_20 = puVar12;
  RtlAcquireSRWLockExclusive(puVar12 + 2);
  puVar14 = local_68;
LAB_140006ca2:
  puVar8 = (undefined8 *)*puVar12;
  while( true ) {
    if (puVar8 == puVar12) goto LAB_140006cc0;
    if (*(uint *)(puVar8 + -1) == param_1) break;
    puVar8 = (undefined8 *)*puVar8;
  }
  piVar16 = (int *)(puVar8 + -9);
  if (piVar16 != (int *)0x0) {
    do {
      puVar1 = (uint *)(piVar16 + 2);
      piVar11 = piVar16;
      bVar6 = SmpCheckSubSysStatus((longlong)piVar16);
      puVar12 = local_20;
      if ((int)CONCAT71(extraout_var,bVar6) == 0) {
        LOCK();
        *piVar16 = *piVar16 + 1;
        UNLOCK();
        SmpWaitForStatusChange((longlong)piVar11,0,local_28);
        if ((*puVar1 & 4) != 0) goto LAB_140006e8d;
        SmpDereferenceKnownSubSys(piVar16);
        puVar12 = local_20;
      }
      puVar8 = *(undefined8 **)(piVar16 + 0x12);
      pppppplVar15 = (longlong ******)(piVar16 + 0x12);
      LOCK();
      *puVar1 = *puVar1 | 4;
      UNLOCK();
      ppppplVar3 = *pppppplVar15;
      puVar13 = local_68;
      if ((longlong ******)ppppplVar3[1] != pppppplVar15) goto LAB_140006d0e;
      pppplVar4 = *(longlong *****)(piVar16 + 0x14);
      puVar13 = local_68;
      if ((longlong ******)*pppplVar4 != pppppplVar15) goto LAB_140006d0e;
      *pppplVar4 = (longlong ***)ppppplVar3;
      ppppplVar3[1] = pppplVar4;
      puVar13 = local_68;
      if ((longlong *******)*local_30 != &local_38) goto LAB_140006d0e;
      *pppppplVar15 = (longlong *****)&local_38;
      *(longlong *******)(piVar16 + 0x14) = local_30;
      local_20 = puVar12;
      *local_30 = (longlong *****)pppppplVar15;
      local_30 = pppppplVar15;
      if ((puVar8 == puVar12) || (piVar16 = (int *)(puVar8 + -9), *(uint *)(puVar8 + -1) != param_1)
         ) break;
    } while( true );
  }
LAB_140006cc0:
  RtlReleaseSRWLockExclusive(puVar12 + 2);
  if ((longlong *******)local_38 == &local_38) {
    return 0;
  }
  in_R11 = local_38;
  bVar6 = SmpSessionIdIsInitialSessions(param_1);
  if (bVar6) {
    local_18 = 0;
    uStack_10 = 0;
    SmpSetCoreProcessIds(param_1,&local_18,'\x01');
    in_R11 = local_38;
  }
  unaff_R14D = 0x80000000;
  pppppplVar15 = (longlong ******)(ulonglong)param_1;
  do {
    puVar13 = puVar14;
    puVar12 = local_20;
    if (((longlong *******)in_R11[1] != &local_38) ||
       (pppppplVar9 = (longlong ******)*in_R11, (longlong ******)pppppplVar9[1] != in_R11)) {
LAB_140006d0e:
      pcVar5 = (code *)swi(0x29);
      local_20 = puVar12;
      pppppplVar9 = (longlong ******)(*pcVar5)(3);
      puVar14 = puVar13 + 8;
    }
    pppppplVar9[1] = (longlong *****)&local_38;
    ppppplVar3 = in_R11[-5];
    local_38 = pppppplVar9;
    *(undefined8 *)(puVar14 + -8) = 0x140006d32;
    iVar7 = NtTerminateProcess(ppppplVar3,0);
    if (((unaff_R14D & iVar7 + unaff_R14D) == 0) && (iVar7 != -0x3ffffef6)) {
      *(undefined8 *)(puVar14 + -8) = 0x140006da1;
      uVar10 = SmpGetProcessId();
      *(int *)(puVar14 + 0x20) = iVar7;
      *(undefined8 *)(puVar14 + -8) = 0x140006dbb;
      SmLogFailureInt(0x14002ab48,0x5b,uVar10,0,*(undefined4 *)(puVar14 + 0x20));
LAB_140006dbb:
      uVar2 = *(uint *)(in_R11 + -6);
      *(int *)(puVar14 + 0x20) = iVar7;
      *(undefined8 *)(puVar14 + -8) = 0x140006dd7;
      SmLogFailureInt(0x14002ab68,0xdd,(ulonglong)uVar2,pppppplVar15,*(undefined4 *)(puVar14 + 0x20)
                     );
    }
    else {
      ppppplVar3 = in_R11[-5];
      *(undefined8 *)(puVar14 + -8) = 0x140006d52;
      iVar7 = NtWaitForSingleObject(ppppplVar3,0,0);
      if (iVar7 < 0) goto LAB_140006dbb;
    }
    *(undefined8 *)(puVar14 + -8) = 0x140006d65;
    SmpDereferenceKnownSubSys((int *)(in_R11 + -9));
    in_R11 = local_38;
    if ((longlong *******)local_38 == &local_38) {
      return 0;
    }
  } while( true );
LAB_140006e8d:
  SmpDereferenceKnownSubSys(piVar16);
  puVar12 = local_20;
  goto LAB_140006ca2;
}



===== SmpWaitForSingleSubSys @ 140006ec0 =====

int SmpWaitForSingleSubSys(longlong param_1)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  longlong lVar3;
  int local_18 [4];
  
  iVar2 = 0;
  local_18[2] = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  if ((*(uint *)(param_1 + 8) & 4) == 0) {
    if ((*(uint *)(param_1 + 8) & 1) == 0) {
      if (*(int *)(param_1 + 0x18) != -1) goto LAB_140006f34;
    }
    else if (*(longlong *)(param_1 + 0x30) != 0) goto LAB_140006f34;
    SmpLockKnownSubSysList(*(uint *)(param_1 + 0x40),1,local_18);
    lVar3 = param_1;
    bVar1 = SmpCheckSubSysStatus(param_1);
    if ((int)CONCAT71(extraout_var,bVar1) == 0) {
      iVar2 = SmpWaitForStatusChange(lVar3,~*(uint *)(param_1 + 8) & 1,local_18);
    }
    SmpUnlockKnownSubSysList(local_18);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
LAB_140006f34:
  if ((*(byte *)(param_1 + 8) & 4) == 0) {
    return iVar2;
  }
  SmpLogFailure(0x14002ab30,0x4b5,0xc0000001);
  return -0x3fffffff;
}



===== SmpExecPgm @ 140006f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpExecPgm(longlong param_1,uint *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar11;
  int *piVar12;
  bool bVar13;
  undefined1 auStackY_2f8 [32];
  uint local_2b8 [2];
  int local_2b0 [2];
  undefined8 local_2a8;
  uint *local_2a0;
  int *local_298;
  undefined8 local_290;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  int local_1b8;
  undefined4 uStack_1b4;
  int *piStack_1b0;
  undefined8 local_1a8;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined8 local_198;
  undefined8 uStack_190;
  uint local_188;
  uint uStack_184;
  uint uStack_180;
  uint uStack_17c;
  undefined8 local_178;
  undefined8 local_170;
  uint local_168;
  undefined8 local_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2f8;
  uVar8 = 0;
  lVar11 = *(longlong *)(param_2 + 8);
  local_2b8[0] = 0;
  if ((*param_2 & 0x10) == 0) {
    if ((*param_2 & 8) != 0) {
      local_2b8[0] = *(uint *)(lVar11 + 8);
      lVar11 = *(longlong *)(lVar11 + 0x30);
      goto LAB_140006fc6;
    }
    if (lVar11 == 0) goto LAB_140007444;
    iVar3 = SmpGetProcessMuSessionId(lVar11,local_2b8);
    if (iVar3 < 0) {
      local_2b8[0] = 0;
      lVar11 = 0;
      goto LAB_140006fc6;
    }
  }
  else {
    local_2b8[0] = *(uint *)(lVar11 + 0x40);
    lVar11 = *(longlong *)(lVar11 + 0x20);
LAB_140006fc6:
    if (lVar11 == 0) {
LAB_140007444:
      SmpLogFailure(0x140022868,0xa5,0xc0000001);
      return 0xc0000001;
    }
  }
  uVar10 = local_2b8[0];
  bVar13 = false;
  piVar12 = (int *)0x0;
  local_2a0 = (uint *)0x0;
  if ((*param_2 & 8) != 0) {
    local_2a0 = *(uint **)(param_2 + 8);
    bVar13 = **(int **)(local_2a0 + 4) == 2;
  }
  puVar4 = (undefined8 *)(param_1 + 8);
  if (*(char *)(param_1 + 0x98) == '\0') {
    puVar4 = (undefined8 *)0x0;
  }
  uVar5 = SmpSbCreateSession(local_2b8[0],lVar11,(undefined8 *)(param_1 + 0x30),param_4,puVar4);
  uVar9 = uVar5 & 0xffffffff;
  if (!bVar13) {
    return uVar9;
  }
  if ((int)uVar5 < 0) {
    return uVar9;
  }
  memset(&local_198,0,0x148);
  iVar3 = *(int *)(param_1 + 0x78);
  if (iVar3 != 1) {
    local_298 = (int *)(ulonglong)uVar10;
    local_2b0[0] = 1;
    local_2b0[1] = 0;
    local_2a8 = (undefined8 *)(SmpKnownSubSysTable + (ulonglong)(uVar10 & 0x1f) * 0x18);
    RtlAcquireSRWLockShared(local_2a8 + 2);
    for (puVar4 = (undefined8 *)*local_2a8; puVar4 != local_2a8; puVar4 = (undefined8 *)*puVar4) {
      if (*(uint *)(puVar4 + -1) == uVar10) {
        if (*(int *)(puVar4 + -6) == iVar3) {
          piVar12 = (int *)(puVar4 + -9);
        }
        if (piVar12 != (int *)0x0) {
          LOCK();
          *piVar12 = *piVar12 + 1;
          UNLOCK();
          SmpUnlockKnownSubSysList(local_2b0);
          uVar10 = local_2b8[0];
          goto LAB_14000704f;
        }
      }
    }
    SmpUnlockKnownSubSysList(local_2b0);
    if (piVar12 == (int *)0x0) {
      memset(&local_278,0,0xe0);
      piStack_1b0 = local_298;
      lVar11 = 0x40;
      local_1a8 = 0;
      local_1b8 = (int)uVar5;
      uStack_1a0 = 0xf2;
      pcVar7 = (char *)&local_278;
      do {
        if ((lVar11 == -0x7fffffbe) ||
           (pcVar7[(longlong)"SmpExecPgm" - (longlong)&local_278] == '\0')) break;
        *pcVar7 = pcVar7[(longlong)"SmpExecPgm" - (longlong)&local_278];
        pcVar7 = pcVar7 + 1;
        lVar11 = lVar11 + -1;
      } while (lVar11 != 0);
      pcVar6 = pcVar7 + -1;
      if (lVar11 != 0) {
        pcVar6 = pcVar7;
      }
      *pcVar6 = '\0';
      LOCK();
      UNLOCK();
      uVar8 = DAT_140030ed4 + 1U & 0x8000000f;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xfffffff0) + 1;
      }
      lVar11 = (longlong)(int)uVar8 * 0xe0;
      DAT_140030ed4 = DAT_140030ed4 + 1;
      *(undefined8 *)(&DAT_140030ed8 + lVar11) = local_278;
      *(undefined8 *)(lVar11 + 0x140030ee0) = uStack_270;
      *(undefined8 *)(&DAT_140030ee8 + lVar11) = local_268;
      *(undefined8 *)(lVar11 + 0x140030ef0) = uStack_260;
      *(undefined8 *)(&DAT_140030ef8 + lVar11) = local_258;
      *(undefined8 *)(lVar11 + 0x140030f00) = uStack_250;
      *(undefined8 *)(&DAT_140030f08 + lVar11) = local_248;
      *(undefined8 *)(lVar11 + 0x140030f10) = uStack_240;
      *(undefined8 *)(&DAT_140030f18 + lVar11) = local_238;
      *(undefined8 *)(lVar11 + 0x140030f20) = uStack_230;
      *(undefined8 *)(&DAT_140030f28 + lVar11) = local_228;
      *(undefined8 *)(lVar11 + 0x140030f30) = uStack_220;
      *(undefined8 *)(&DAT_140030f38 + lVar11) = local_218;
      *(undefined8 *)(lVar11 + 0x140030f40) = uStack_210;
      *(undefined8 *)(&DAT_140030f48 + lVar11) = local_208;
      *(undefined8 *)(lVar11 + 0x140030f50) = uStack_200;
      *(undefined8 *)(&DAT_140030f58 + lVar11) = local_1f8;
      *(undefined8 *)(lVar11 + 0x140030f60) = uStack_1f0;
      *(undefined8 *)(&DAT_140030f68 + lVar11) = local_1e8;
      *(undefined8 *)(lVar11 + 0x140030f70) = uStack_1e0;
      *(undefined8 *)(&DAT_140030f78 + lVar11) = local_1d8;
      *(undefined8 *)(lVar11 + 0x140030f80) = uStack_1d0;
      *(undefined8 *)(&DAT_140030f88 + lVar11) = local_1c8;
      *(undefined8 *)(lVar11 + 0x140030f90) = uStack_1c0;
      *(ulonglong *)(&DAT_140030f98 + lVar11) = CONCAT44(uStack_1b4,local_1b8);
      *(int **)(lVar11 + 0x140030fa0) = piStack_1b0;
      *(undefined8 *)(&DAT_140030fa8 + lVar11) = local_1a8;
      *(ulonglong *)(lVar11 + 0x140030fb0) = CONCAT44(uStack_19c,uStack_1a0);
      return uVar9;
    }
  }
LAB_14000704f:
  uVar2 = local_2b8[0];
  if (uVar10 == *SmpCoreProcessIds) {
    if (*(int *)(param_1 + 0x78) == 1) {
      SmpCoreSubsysProcess = 0xffffffffffffffff;
    }
    else {
      SmpCoreSubsysProcess = *(undefined8 *)(piVar12 + 8);
    }
  }
  local_290 = *(undefined8 *)(param_1 + 0x48);
  local_298 = piVar12;
  if (*(longlong *)(local_2a0 + 0x12) == SmpUniqueProcessId) {
LAB_140007082:
    if (uVar10 != 0xffffffff) {
      for (; uVar8 < SmpNumberInitialSessions; uVar8 = uVar8 + 1) {
        if (uVar10 == SmpCoreProcessIds[(ulonglong)uVar8 * 10]) {
          if (uVar8 != 0xffffffff) {
            SmpSetCoreProcessIds(uVar10,&local_298,'\0');
          }
          break;
        }
      }
    }
    if (uVar10 == *SmpCoreProcessIds) {
      return uVar9;
    }
  }
  else {
    if ((piVar12 != (int *)0x0) && (piVar12[6] - 2U < 2)) {
      if ((*local_2a0 & 1) == 0) {
        uVar10 = *local_2a0;
        do {
          LOCK();
          uVar1 = *local_2a0;
          bVar13 = uVar10 == uVar1;
          if (bVar13) {
            *local_2a0 = uVar10 | 1;
          }
          else {
            uVar10 = uVar1;
          }
          UNLOCK();
        } while (!bVar13);
        if ((uVar10 & 1) == 0) {
          local_198 = *(undefined8 *)(local_2a0 + 0x10);
          uStack_190 = *(undefined8 *)(local_2a0 + 0x12);
          local_188 = local_2a0[0x14];
          uStack_184 = local_2a0[0x15];
          uStack_180 = local_2a0[0x16];
          uStack_17c = local_2a0[0x17];
          local_178 = *(undefined8 *)(local_2a0 + 0x18);
          local_170 = 5;
          local_168 = local_2b8[0];
          local_58 = *(undefined8 *)(piVar12 + 0xc);
          local_60 = local_290;
          NtAlpcSendWaitReceivePort(SmpApiConnectionPort,0x10000,&local_198,0);
          uVar10 = uVar2;
          goto LAB_140007082;
        }
      }
      uVar9 = 0xc0000001;
      goto LAB_1400072ab;
    }
    uVar9 = 0xc0000001;
    SmLogFailureInt(0x140022868,0x129,(ulonglong)uVar10,0,0xc0000001);
  }
  if (piVar12 == (int *)0x0) {
    return uVar9;
  }
LAB_1400072ab:
  SmpDereferenceKnownSubSys(piVar12);
  return uVar9;
}



===== SmpSbCreateSession @ 140007470 =====

ulonglong SmpSbCreateSession(uint param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
                            undefined8 *param_5)

{
  int iVar1;
  code *pcVar2;
  bool bVar3;
  undefined8 *puVar4;
  undefined7 extraout_var;
  ulonglong uVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  undefined8 local_res18;
  undefined8 in_stack_fffffffffffffe48;
  undefined4 uVar11;
  undefined8 uVar9;
  undefined8 *puVar10;
  uint uVar12;
  ulonglong in_stack_fffffffffffffe50;
  ulonglong *puVar13;
  ulonglong in_stack_fffffffffffffe58;
  ulonglong local_198 [3];
  int local_180 [2];
  undefined8 *local_178;
  int local_170 [4];
  ulonglong *local_160;
  undefined8 local_158;
  undefined8 local_148 [5];
  undefined4 local_120;
  uint local_11c;
  int local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined8 local_b0;
  undefined4 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  
  uVar11 = (undefined4)((ulonglong)in_stack_fffffffffffffe48 >> 0x20);
  memset(local_148,0,0x120);
  iVar1 = *(int *)(param_3 + 9);
  local_198[0] = (ulonglong)param_1;
  local_res18 = 0;
  piVar7 = (int *)0x0;
  local_198[2] = 0;
  local_180[0] = 1;
  local_180[1] = 0;
  puVar10 = (undefined8 *)(SmpKnownSubSysTable + (ulonglong)(param_1 & 0x1f) * 0x18);
  local_178 = puVar10;
  RtlAcquireSRWLockShared(puVar10 + 2);
  for (puVar4 = (undefined8 *)*puVar10; puVar4 != puVar10; puVar4 = (undefined8 *)*puVar4) {
    if (*(uint *)(puVar4 + -1) == param_1) {
      if (*(int *)(puVar4 + -6) == iVar1) {
        piVar7 = (int *)(puVar4 + -9);
      }
      if (piVar7 != (int *)0x0) {
        LOCK();
        *piVar7 = *piVar7 + 1;
        UNLOCK();
        SmpUnlockKnownSubSysList(local_180);
        goto LAB_140007521;
      }
    }
  }
  SmpUnlockKnownSubSysList(local_180);
  if (piVar7 == (int *)0x0) {
    if (*(int *)(param_3 + 9) != 1) {
      return 0xc00000fe;
    }
    uVar5 = NtDuplicateObject(param_2,param_3[2],0xffffffffffffffff,&local_res18,CONCAT44(uVar11,2),
                              in_stack_fffffffffffffe50 & 0xffffffff00000000,
                              in_stack_fffffffffffffe58 & 0xffffffff00000000);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    uVar8 = NtResumeThread(local_res18,0);
    NtClose(local_res18);
    return (ulonglong)uVar8;
  }
LAB_140007521:
  uVar8 = 0;
  local_170[2] = 0;
  local_170[0] = 0;
  local_170[1] = 0;
  if ((piVar7[2] & 4U) == 0) {
    if ((piVar7[2] & 1U) == 0) {
      if (piVar7[6] == -1) goto LAB_1400078f3;
      goto LAB_14000754c;
    }
    if (*(longlong *)(piVar7 + 0xc) != 0) goto LAB_14000754c;
LAB_1400078f3:
    SmpLockKnownSubSysList(piVar7[0x10],1,local_170);
    piVar6 = piVar7;
    bVar3 = SmpCheckSubSysStatus((longlong)piVar7);
    if ((int)CONCAT71(extraout_var,bVar3) == 0) {
      uVar8 = SmpWaitForStatusChange((longlong)piVar6,~piVar7[2] & 1,local_170);
    }
    SmpUnlockKnownSubSysList(local_170);
    if (-1 < (int)uVar8) goto LAB_14000754c;
LAB_1400075a1:
    if (-1 < (int)uVar8) {
      local_110 = *param_3;
      uStack_108 = param_3[1];
      local_a0 = 0;
      local_100 = param_3[2];
      uStack_f8 = param_3[3];
      local_f0 = param_3[4];
      uStack_e8 = param_3[5];
      local_e0 = param_3[6];
      uStack_d8 = param_3[7];
      local_d0 = param_3[8];
      uStack_c8 = param_3[9];
      local_c0 = *(undefined4 *)(param_3 + 10);
      uStack_bc = *(undefined4 *)((longlong)param_3 + 0x54);
      uStack_b8 = *(undefined4 *)(param_3 + 0xb);
      uStack_b4 = *(undefined4 *)((longlong)param_3 + 0x5c);
      local_b0 = param_3[0xc];
      if (param_5 == (undefined8 *)0x0) {
        local_98 = 0;
        uStack_90 = 0;
      }
      else {
        local_98 = *param_5;
        uStack_90 = param_5[1];
      }
      in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
      in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffffffff00000000;
      uVar9 = CONCAT44(uVar11,0x1fffff);
      uVar8 = NtDuplicateObject(param_2,param_3[1],*(undefined8 *)(piVar7 + 8),&uStack_108,uVar9,
                                in_stack_fffffffffffffe50,in_stack_fffffffffffffe58);
      if ((int)uVar8 < 0) {
        SmLogFailureInt(0x1400228b8,0xb3,local_198[0],0,uVar8);
      }
      else {
        in_stack_fffffffffffffe58 = in_stack_fffffffffffffe58 & 0xffffffff00000000;
        in_stack_fffffffffffffe50 = in_stack_fffffffffffffe50 & 0xffffffff00000000;
        uVar9 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),0x1fffff);
        uVar8 = NtDuplicateObject(param_2,param_3[2],*(undefined8 *)(piVar7 + 8),&local_100,uVar9,
                                  in_stack_fffffffffffffe50,in_stack_fffffffffffffe58);
        uVar11 = (undefined4)(in_stack_fffffffffffffe58 >> 0x20);
        if ((int)uVar8 < 0) {
          uVar5 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),uVar8);
          SmLogFailureInt(0x1400228b8,0xc3,(ulonglong)(uint)piVar7[0x10],0,uVar8);
        }
        else {
          LOCK();
          piVar6 = piVar7 + 1;
          local_118 = *piVar6;
          *piVar6 = *piVar6 + 1;
          UNLOCK();
          local_118 = local_118 + 1;
          if (local_118 == 0) {
            LOCK();
            piVar7[2] = piVar7[2] | 8;
            UNLOCK();
          }
          puVar13 = local_198 + 2;
          uVar11 = 0;
          puVar10 = local_148;
          local_120 = 0;
          local_148[0] = 0xc00098;
          local_198[2] = 0x120;
          uVar8 = NtAlpcSendWaitReceivePort
                            (*(undefined8 *)(piVar7 + 10),0x20000,local_148,0,puVar10,puVar13,0,0);
          if (-1 < (int)uVar8) {
            uVar8 = local_11c;
            goto LAB_1400076dc;
          }
          uVar12 = (uint)((ulonglong)puVar10 >> 0x20);
          SmLogFailureInt(0x1400228b8,0xe8,(ulonglong)(uint)piVar7[0x10],0,uVar8);
          uVar9 = CONCAT44(uVar11,1);
          in_stack_fffffffffffffe50 = (ulonglong)puVar13 & 0xffffffff00000000;
          uVar5 = (ulonglong)uVar12 << 0x20;
          NtDuplicateObject(*(undefined8 *)(piVar7 + 8),local_100,0,0,uVar5,
                            in_stack_fffffffffffffe50,uVar9);
          uVar11 = (undefined4)((ulonglong)uVar9 >> 0x20);
        }
        NtDuplicateObject(*(undefined8 *)(piVar7 + 8),uStack_108,0,0,uVar5 & 0xffffffff00000000,
                          in_stack_fffffffffffffe50 & 0xffffffff00000000,CONCAT44(uVar11,1));
      }
      goto LAB_1400076dc;
    }
  }
  else {
LAB_14000754c:
    if ((*(byte *)(piVar7 + 2) & 4) == 0) goto LAB_1400075a1;
    uVar8 = 0xc0000001;
    SmpLogFailure(0x14002ab30,0x4b5,0xc0000001);
  }
  SmLogFailureInt(0x1400228b8,0x94,local_198[0],0,uVar8);
LAB_1400076dc:
  LOCK();
  iVar1 = *piVar7;
  *piVar7 = *piVar7 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    if ((((*(byte *)(piVar7 + 2) & 4) != 0) && (piVar7[6] == 2)) &&
       (piVar7[0x10] == *SmpCoreProcessIds)) {
      local_198[0] = 0;
      local_198[1] = 0;
      RtlInitUnicodeString(local_198,L"Core Windows subsystem terminated");
      local_158 = 0xffffffffc0000001;
      local_160 = local_198;
                    /* WARNING: Subroutine does not return */
      SmpTerminate(&local_160,1,2);
    }
    if (*(undefined8 **)(piVar7 + 4) != (undefined8 *)0x0) {
      SmpDisposeSubSysSynch(*(undefined8 **)(piVar7 + 4));
    }
    if (*(longlong *)(piVar7 + 10) != 0) {
      NtClose();
    }
    if ((*(byte *)(piVar7 + 2) & 8) == 0) {
      if (*(longlong *)(piVar7 + 8) != 0) {
        NtClose();
      }
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,piVar7);
    }
    else {
      piVar6 = piVar7 + 0x12;
      if ((int **)*(undefined8 **)(SmpOverflowSubSysList + 2) != &SmpOverflowSubSysList) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        uVar5 = (*pcVar2)();
        return uVar5;
      }
      *(int **)piVar6 = SmpOverflowSubSysList;
      *(int ***)(piVar7 + 0x14) = &SmpOverflowSubSysList;
      *(int **)(SmpOverflowSubSysList + 2) = piVar6;
      SmpOverflowSubSysList = piVar6;
    }
  }
  return (ulonglong)uVar8;
}



===== SmpUnlockKnownSubSysList @ 1400079f0 =====

void SmpUnlockKnownSubSysList(int *param_1)

{
  if (*param_1 == 1) {
                    /* WARNING: Could not recover jumptable at 0x000140007a0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    RtlReleaseSRWLockShared(*(longlong *)(param_1 + 2) + 0x10);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000140007a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlReleaseSRWLockExclusive();
  return;
}



===== SmpSearchKnownSubSysDatabase @ 140007a20 =====

int * SmpSearchKnownSubSysDatabase(uint param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined8 *puVar3;
  int local_18 [2];
  longlong lStack_10;
  
  piVar1 = *(int **)(param_2 + 2);
  piVar2 = (int *)0x0;
  lStack_10._0_4_ = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  if (piVar1 == (int *)0x0) {
    local_18[0] = 1;
    lStack_10 = SmpKnownSubSysTable + (ulonglong)(param_1 & 0x1f) * 0x18;
    RtlAcquireSRWLockShared(lStack_10 + 0x10);
    piVar1 = local_18;
  }
  puVar3 = (undefined8 *)**(undefined8 **)(piVar1 + 2);
  do {
    if (puVar3 == *(undefined8 **)(piVar1 + 2)) {
LAB_140007a8d:
      if (piVar1 == local_18) {
        SmpUnlockKnownSubSysList(piVar1);
      }
      return piVar2;
    }
    if (*(uint *)(puVar3 + -1) == param_1) {
      if (*param_2 == 0) {
        if (puVar3[-3] == *(longlong *)(param_2 + 4)) {
          piVar2 = (int *)(puVar3 + -9);
        }
      }
      else if ((*param_2 == 1) && (*(int *)(puVar3 + -6) == param_2[4])) {
        piVar2 = (int *)(puVar3 + -9);
      }
      if (piVar2 != (int *)0x0) {
        LOCK();
        *piVar2 = *piVar2 + 1;
        UNLOCK();
        goto LAB_140007a8d;
      }
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== SmpStopCsr @ 140007b00 =====

ulonglong SmpStopCsr(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  ulonglong uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x30);
  puVar2 = (uint *)SmpLookupControlBlock(uVar1);
  if (puVar2 == (uint *)0x0) {
    uVar3 = SmpTerminateCSR(uVar1);
  }
  else {
    uVar3 = SmpDestroyControlBlock(puVar2,1);
    SmpReleaseControlBlock((byte *)puVar2);
  }
  return uVar3 & 0xffffffff;
}



===== SmpLookupControlBlock @ 140007b60 =====

longlong SmpLookupControlBlock(uint param_1)

{
  longlong lVar1;
  
  RtlAcquireSRWLockShared(&SmpControlLock);
  lVar1 = SmpTreeLookupControlBlock(SmpControlBlockRoot,param_1);
  RtlReleaseSRWLockShared(&SmpControlLock);
  return lVar1;
}



===== SmpTreeLookupControlBlock @ 140007bb0 =====

longlong SmpTreeLookupControlBlock(longlong param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
LAB_140007bb2:
  if (param_1 != 0) {
    if (*(uint *)(param_1 + -0x60) != param_2) {
      if (param_2 < *(uint *)(param_1 + -0x60)) {
        param_1 = *(longlong *)(param_1 + 8);
      }
      else {
        param_1 = *(longlong *)(param_1 + 0x10);
      }
      goto LAB_140007bb2;
    }
    iVar1 = *(int *)(param_1 + -100);
    while (iVar1 != 0) {
      LOCK();
      iVar2 = *(int *)(param_1 + -100);
      if (iVar1 == iVar2) {
        *(int *)(param_1 + -100) = iVar1 + 1;
        iVar2 = iVar1;
      }
      else {
      }
      UNLOCK();
      bVar3 = iVar2 == iVar1;
      iVar1 = iVar2;
      if (bVar3) {
        return param_1 + -0x68;
      }
    }
  }
  return 0;
}



===== SmpDestroyControlBlock @ 140007bf4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpDestroyControlBlock(uint *param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 *local_38;
  longlong local_30;
  ulonglong local_28;
  longlong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar4 = 0;
  if ((*param_1 & 2) == 0) {
    uVar3 = *param_1;
    do {
      LOCK();
      uVar1 = *param_1;
      bVar5 = uVar3 == uVar1;
      if (bVar5) {
        *param_1 = uVar3 | 2;
      }
      else {
        uVar3 = uVar1;
      }
      UNLOCK();
    } while (!bVar5);
    if ((uVar3 & 2) == 0) {
      uVar3 = param_1[2];
      SmpReleaseControlBlock((byte *)param_1);
      if (param_2 != 0) {
        bVar5 = SmpSessionIdIsInitialSessions(uVar3);
        if (bVar5) {
          uVar4 = SmpSessionIdToInitialSessionIndex(uVar3);
          if (*(int *)(SmpCoreProcessIds + 4 + (uVar4 & 0xffffffff) * 0x28) == 0) {
            lVar2 = *(longlong *)(param_1 + 4);
            local_48 = 0;
            uStack_40 = 0;
            RtlInitUnicodeString(&local_48,L"initial session process or");
            local_38 = &local_48;
            local_30 = (longlong)*(int *)(lVar2 + 4);
            local_28 = (ulonglong)uVar3;
            local_20 = lVar2;
            SmLogFailureInt(0x14002a6c0,0x2a3,*(undefined8 *)(param_1 + 0xe),0,
                            *(undefined4 *)(lVar2 + 4));
                    /* WARNING: Subroutine does not return */
            SmpTerminate(&local_38,1,4);
          }
        }
        NtTerminateProcess(*(undefined8 *)(param_1 + 0xc),0xc0000001);
        uVar4 = SmpTerminateCSR(uVar3);
        uVar4 = uVar4 & 0xffffffff;
      }
    }
  }
  NtWaitForSingleObject(*(undefined8 *)(param_1 + 0xc),0,0);
  return uVar4;
}



===== SmpSessionIdIsInitialSessions @ 140007d50 =====

bool SmpSessionIdIsInitialSessions(int param_1)

{
  ulonglong uVar1;
  
  if (param_1 != -1) {
    for (uVar1 = 0; (uint)uVar1 < SmpNumberInitialSessions; uVar1 = (ulonglong)((uint)uVar1 + 1)) {
      if (param_1 == *(int *)(SmpCoreProcessIds + uVar1 * 0x28)) goto LAB_140007d7e;
    }
  }
  uVar1 = 0xffffffff;
LAB_140007d7e:
  return (int)uVar1 != -1;
}



===== SmpGetProcessMuSessionId @ 140007d90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpGetProcessMuSessionId(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  longlong lVar5;
  undefined1 auStack_148 [32];
  undefined8 local_128;
  undefined4 local_118 [4];
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  int local_48;
  undefined4 uStack_44;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_148;
  local_118[0] = 0;
  local_128 = 0;
  iVar1 = NtQueryInformationProcess(param_1,0x18,local_118,4);
  if (iVar1 < 0) {
    memset(&local_108,0,0xe0);
    uStack_40 = SmpGetProcessId();
    local_38 = 0;
    local_48 = iVar1;
    uStack_30 = 0x8c;
    pcVar4 = (char *)&local_108;
    lVar5 = 0x40;
    do {
      if ((lVar5 == -0x7fffffbe) ||
         (pcVar4[(longlong)"SmpGetProcessMuSessionId" - (longlong)&local_108] == '\0')) break;
      *pcVar4 = pcVar4[(longlong)"SmpGetProcessMuSessionId" - (longlong)&local_108];
      pcVar4 = pcVar4 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    pcVar3 = pcVar4 + -1;
    if (lVar5 != 0) {
      pcVar3 = pcVar4;
    }
    *pcVar3 = '\0';
    LOCK();
    UNLOCK();
    uVar2 = DAT_140030ed4 + 1U & 0x8000000f;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffff0) + 1;
    }
    lVar5 = (longlong)(int)uVar2 * 0xe0;
    DAT_140030ed4 = DAT_140030ed4 + 1;
    *(undefined8 *)(&DAT_140030ed8 + lVar5) = local_108;
    *(undefined8 *)(lVar5 + 0x140030ee0) = uStack_100;
    *(undefined8 *)(&DAT_140030ee8 + lVar5) = local_f8;
    *(undefined8 *)(lVar5 + 0x140030ef0) = uStack_f0;
    *(undefined8 *)(&DAT_140030ef8 + lVar5) = local_e8;
    *(undefined8 *)(lVar5 + 0x140030f00) = uStack_e0;
    *(undefined8 *)(&DAT_140030f08 + lVar5) = local_d8;
    *(undefined8 *)(lVar5 + 0x140030f10) = uStack_d0;
    *(undefined8 *)(&DAT_140030f18 + lVar5) = local_c8;
    *(undefined8 *)(lVar5 + 0x140030f20) = uStack_c0;
    *(undefined8 *)(&DAT_140030f28 + lVar5) = local_b8;
    *(undefined8 *)(lVar5 + 0x140030f30) = uStack_b0;
    *(undefined8 *)(&DAT_140030f38 + lVar5) = local_a8;
    *(undefined8 *)(lVar5 + 0x140030f40) = uStack_a0;
    *(undefined8 *)(&DAT_140030f48 + lVar5) = local_98;
    *(undefined8 *)(lVar5 + 0x140030f50) = uStack_90;
    *(undefined8 *)(&DAT_140030f58 + lVar5) = local_88;
    *(undefined8 *)(lVar5 + 0x140030f60) = uStack_80;
    *(undefined8 *)(&DAT_140030f68 + lVar5) = local_78;
    *(undefined8 *)(lVar5 + 0x140030f70) = uStack_70;
    *(undefined8 *)(&DAT_140030f78 + lVar5) = local_68;
    *(undefined8 *)(lVar5 + 0x140030f80) = uStack_60;
    *(undefined8 *)(&DAT_140030f88 + lVar5) = local_58;
    *(undefined8 *)(lVar5 + 0x140030f90) = uStack_50;
    *(ulonglong *)(&DAT_140030f98 + lVar5) = CONCAT44(uStack_44,local_48);
    *(undefined8 *)(lVar5 + 0x140030fa0) = uStack_40;
    *(undefined8 *)(&DAT_140030fa8 + lVar5) = local_38;
    *(ulonglong *)(lVar5 + 0x140030fb0) = CONCAT44(uStack_2c,uStack_30);
    *param_2 = 0;
  }
  else {
    *param_2 = local_118[0];
  }
  return iVar1;
}



===== SmpGetProcessId @ 140007f50 =====

undefined8 SmpGetProcessId(void)

{
  int iVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = NtQueryInformationProcess(0,0,&local_38,0x30,0);
  if (iVar1 < 0) {
    return 0;
  }
  return local_18;
}



===== SmpCreateKnownSubSys @ 140007fb0 =====

undefined8 * SmpCreateKnownSubSys(uint param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = (undefined8 *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                           SmBaseTag + 0x80000,0x58);
  if (puVar1 == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  if ((param_1 & 1) == 0) {
    puVar2 = SmpGetSubSysSynch();
    puVar1[2] = puVar2;
    if (puVar2 == (undefined8 *)0x0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar1);
      return (undefined8 *)0x0;
    }
  }
  else {
    puVar1[2] = 0;
  }
  *puVar1 = 1;
  *(uint *)(puVar1 + 1) = param_1;
  *(undefined4 *)(puVar1 + 3) = 0xffffffff;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  return puVar1;
}



===== SmLogFailureInt @ 140008078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmLogFailureInt(longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                    undefined4 param_5)

{
  undefined1 auStack_128 [32];
  char local_108 [200];
  undefined8 local_40;
  undefined8 local_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_128;
  memset(local_108,0,0xe0);
  local_40 = param_3;
  local_38 = param_4;
  SmpInternalLogFailure(param_1,param_2,param_5,local_108);
  return;
}



===== ApiSetpSearchForApiSet @ 140008110 =====

longlong ApiSetpSearchForApiSet(longlong param_1,ushort *param_2,ushort param_3)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  ulonglong uVar9;
  
  uVar6 = 0;
  if (param_3 != 0) {
    puVar8 = param_2;
    uVar9 = (ulonglong)param_3;
    do {
      uVar2 = *puVar8;
      if ((ushort)(uVar2 - 0x41) < 0x1a) {
        uVar2 = uVar2 + 0x20;
      }
      puVar8 = puVar8 + 1;
      uVar6 = (uint)uVar2 + *(int *)(param_1 + 0x18) * uVar6;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  iVar3 = 0;
  iVar7 = *(int *)(param_1 + 0xc) + -1;
  while( true ) {
    while( true ) {
      if (iVar7 < iVar3) {
        return 0;
      }
      iVar5 = iVar3 + iVar7 >> 1;
      lVar4 = (ulonglong)*(uint *)(param_1 + 0x14) + param_1;
      uVar1 = *(uint *)(lVar4 + (longlong)iVar5 * 8);
      if (uVar1 <= uVar6) break;
      iVar7 = iVar5 + -1;
    }
    if (uVar6 <= uVar1) break;
    iVar3 = iVar5 + 1;
  }
  lVar4 = (ulonglong)*(uint *)(param_1 + 0x10) + param_1 +
          (ulonglong)*(uint *)(lVar4 + (longlong)iVar5 * 8 + 4) * 0x18;
  if (lVar4 == 0) {
    return 0;
  }
  iVar3 = RtlCompareUnicodeStrings
                    (param_2,(ulonglong)param_3,(ulonglong)*(uint *)(lVar4 + 4) + param_1,
                     *(uint *)(lVar4 + 0xc) >> 1,1);
  if (iVar3 == 0) {
    return lVar4;
  }
  return 0;
}



===== _tlgEnableCallback @ 140008220 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  int iVar1;
  
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        iVar1 = 0x100;
      }
      else {
        iVar1 = param_3 + 1;
      }
      *param_7 = iVar1;
      *(undefined8 *)(param_7 + 4) = param_4;
      *(undefined8 *)(param_7 + 6) = param_5;
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== SmpUpdatePagefileUsageCallback @ 1400082b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpUpdatePagefileUsageCallback(void)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  uint *puVar4;
  char *pcVar5;
  uint uVar6;
  uint *puVar7;
  ulonglong uVar8;
  char *pcVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined1 auStack_208 [32];
  undefined4 *local_1e8;
  undefined4 local_1e0;
  int local_1d8 [2];
  undefined8 local_1d0;
  ulonglong uStack_1c8;
  undefined8 local_1c0;
  ulonglong uStack_1b8;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  int local_e8;
  undefined4 uStack_e4;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined1 local_c8 [168];
  longlong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_208;
  local_1d0 = 0;
  uStack_1c8 = 0;
  local_1c0 = 0;
  uStack_1b8 = 0;
  memset(local_c8,0,0xb0);
  uVar12 = 0;
  uVar3 = SmpMemorySize / DAT_140032b08;
  local_1d8[0] = 0;
  iVar2 = NtQuerySystemInformation(0x7b,&local_1d0,0x20,0);
  if (-1 < iVar2) {
    uVar8 = uStack_1c8;
    if (DAT_140032c28 < uStack_1b8) {
      DAT_140032c28 = uStack_1b8;
      uVar8 = uStack_1b8;
    }
    iVar2 = NtQuerySystemInformation(0x50,local_c8,0xb0,local_1d8);
    if (-1 < iVar2) {
      iVar2 = 0x100;
      while( true ) {
        puVar4 = (uint *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0
                                         ,iVar2);
        if (puVar4 == (uint *)0x0) {
          return;
        }
        iVar2 = NtQuerySystemInformation(0x12,puVar4,iVar2,local_1d8);
        if (-1 < iVar2) break;
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
        if (iVar2 != -0x3ffffffc) {
          return;
        }
        iVar2 = local_1d8[0];
      }
      if (local_1d8[0] != 0) {
        uVar12 = (ulonglong)puVar4[2];
        uVar6 = *puVar4;
        puVar7 = puVar4;
        while (uVar6 != 0) {
          puVar7 = (uint *)((longlong)puVar7 + (ulonglong)uVar6);
          uVar12 = uVar12 + puVar7[2];
          uVar6 = *puVar7;
        }
      }
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
      uVar12 = local_20 + uVar12;
      uVar10 = (uVar8 * 10) / 9;
      uVar8 = 0x400000000 / (ulonglong)DAT_140032b08 + uVar8;
      if (uVar10 <= uVar8) {
        uVar8 = uVar10;
      }
      if (uVar3 < uVar8) {
        uVar8 = uVar8 - uVar3;
        if (uVar12 < uVar8) {
          uVar12 = uVar8;
        }
      }
      if (0xffffffff < uVar12) {
        uVar12 = 0xffffffff;
      }
      *(int *)(&DAT_140032c34 + (ulonglong)(DAT_140032c30 % 0xf0) * 4) = (int)uVar12;
      DAT_140032c30 = DAT_140032c30 + 1;
      uVar6 = SmpPagefileUsage + 1;
      if (6 < SmpPagefileUsage) {
        SmpPagefileUsage = 7;
      }
      uVar1 = SmpPagefileUsage & uVar6;
      SmpPagefileUsage = uVar6;
      if (uVar1 == 0) {
        local_1e0 = 0x3c4;
        local_1e8 = &DAT_140032c30;
        local_e8 = NtSetValueKey(SmpMmKey,&SmpPagefileUsageValue,0,3);
        if (-1 < local_e8) {
          return;
        }
        memset(&local_1a8,0,0xe0);
        uStack_d0 = 0x37d;
        pcVar9 = (char *)&local_1a8;
        lVar11 = 0x40;
        do {
          if ((lVar11 == -0x7fffffbe) ||
             (pcVar9[(longlong)"SmpUpdatePagefileUsageCallback" - (longlong)&local_1a8] == '\0'))
          break;
          *pcVar9 = pcVar9[(longlong)"SmpUpdatePagefileUsageCallback" - (longlong)&local_1a8];
          pcVar9 = pcVar9 + 1;
          lVar11 = lVar11 + -1;
        } while (lVar11 != 0);
        pcVar5 = pcVar9 + -1;
        if (lVar11 != 0) {
          pcVar5 = pcVar9;
        }
        *pcVar5 = '\0';
        LOCK();
        UNLOCK();
        uVar6 = DAT_140030ed4 + 1U & 0x8000000f;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
        }
        lVar11 = (longlong)(int)uVar6 * 0xe0;
        DAT_140030ed4 = DAT_140030ed4 + 1;
        *(undefined8 *)(&DAT_140030ed8 + lVar11) = local_1a8;
        *(undefined8 *)(lVar11 + 0x140030ee0) = uStack_1a0;
        *(undefined8 *)(&DAT_140030ee8 + lVar11) = local_198;
        *(undefined8 *)(lVar11 + 0x140030ef0) = uStack_190;
        *(undefined8 *)(&DAT_140030ef8 + lVar11) = local_188;
        *(undefined8 *)(lVar11 + 0x140030f00) = uStack_180;
        *(undefined8 *)(&DAT_140030f08 + lVar11) = local_178;
        *(undefined8 *)(lVar11 + 0x140030f10) = uStack_170;
        *(undefined8 *)(&DAT_140030f18 + lVar11) = local_168;
        *(undefined8 *)(lVar11 + 0x140030f20) = uStack_160;
        *(undefined8 *)(&DAT_140030f28 + lVar11) = local_158;
        *(undefined8 *)(lVar11 + 0x140030f30) = uStack_150;
        *(undefined8 *)(&DAT_140030f38 + lVar11) = local_148;
        *(undefined8 *)(lVar11 + 0x140030f40) = uStack_140;
        *(undefined8 *)(&DAT_140030f48 + lVar11) = local_138;
        *(undefined8 *)(lVar11 + 0x140030f50) = uStack_130;
        *(undefined8 *)(&DAT_140030f58 + lVar11) = local_128;
        *(undefined8 *)(lVar11 + 0x140030f60) = uStack_120;
        *(undefined8 *)(&DAT_140030f68 + lVar11) = local_118;
        *(undefined8 *)(lVar11 + 0x140030f70) = uStack_110;
        *(undefined8 *)(&DAT_140030f78 + lVar11) = local_108;
        *(undefined8 *)(lVar11 + 0x140030f80) = uStack_100;
        *(undefined8 *)(&DAT_140030f88 + lVar11) = local_f8;
        *(undefined8 *)(lVar11 + 0x140030f90) = uStack_f0;
        *(ulonglong *)(&DAT_140030f98 + lVar11) = CONCAT44(uStack_e4,local_e8);
        *(undefined8 *)(lVar11 + 0x140030fa0) = uStack_e0;
        *(undefined8 *)(&DAT_140030fa8 + lVar11) = local_d8;
        *(ulonglong *)(lVar11 + 0x140030fb0) = CONCAT44(uStack_cc,uStack_d0);
      }
    }
  }
  return;
}



===== SmpProcessModuleImports @ 1400086d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpProcessModuleImports(undefined8 *param_1,char *param_2)

{
  short sVar1;
  int iVar2;
  undefined8 uVar3;
  short *psVar4;
  ulonglong *puVar5;
  undefined1 auStackY_298 [32];
  char local_268 [16];
  ulonglong local_258;
  short *psStack_250;
  ulonglong local_248;
  short *psStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  short local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_298;
  local_268[0] = '\0';
  local_238 = 0;
  uStack_230 = 0;
  local_248 = 0;
  psStack_240 = (short *)0x0;
  iVar2 = _stricmp(param_2,"ntdll.dll");
  if ((iVar2 != 0) && (iVar2 = _stricmp(param_2,"ntdll32.dll"), iVar2 != 0)) {
    RtlInitAnsiString(&local_238,param_2);
    local_258 = 0x20a0000;
    psStack_250 = local_228;
    iVar2 = RtlAnsiStringToUnicodeString(&local_258,&local_238,0);
    if ((-1 < iVar2) &&
       (uVar3 = ApiSetResolveToHost(*(int **)((longlong)ProcessEnvironmentBlock + 0x68),
                                    (ushort *)&local_258,(ushort *)*param_1,local_268,
                                    (short *)&local_248), -1 < (int)uVar3)) {
      if (local_268[0] != '\0') {
        if ((short)local_248 == 0) {
          return;
        }
        local_258 = local_248;
        psStack_250 = psStack_240;
      }
      for (psVar4 = (short *)(((local_258 & 0xffff) - 2) + (longlong)psStack_250);
          psStack_250 <= psVar4; psVar4 = psVar4 + -1) {
        if (*psVar4 == 0x2e) {
          if (psStack_250 <= psVar4) {
            puVar5 = &local_248;
            sVar1 = (short)((longlong)psVar4 - (longlong)psStack_250 >> 1) * 2;
            psStack_240 = psStack_250;
            local_248 = (ulonglong)CONCAT22(sVar1,sVar1);
            goto LAB_140008844;
          }
          break;
        }
      }
      puVar5 = &local_258;
LAB_140008844:
      SmpSaveRegistryValue_U((longlong *)param_1[1],(undefined2 *)puVar5,(ushort *)&local_258,1);
    }
  }
  return;
}



===== SmpSaveRegistryValue_U @ 140008890 =====

undefined8
SmpSaveRegistryValue_U(longlong *param_1,undefined2 *param_2,ushort *param_3,uint param_4)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  longlong *plVar4;
  void *_Dst;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  longlong local_28;
  longlong lStack_20;
  
  puVar8 = auStack_48;
  bVar2 = true;
  local_28 = 0;
  lStack_20 = 0;
  if ((param_4 & 1) != 0) {
    for (plVar4 = (longlong *)*param_1; plVar4 != param_1; plVar4 = (longlong *)*plVar4) {
      iVar3 = RtlCompareUnicodeString(plVar4 + 2,param_2,1);
      if (iVar3 == 0) {
        if (plVar4[5] == 0) {
          if (param_3 == (ushort *)0x0) {
            return 0x40000000;
          }
LAB_140008910:
          iVar3 = RtlCompareUnicodeString(plVar4 + 4,param_3,1);
          if (iVar3 == 0) {
            return 0x40000000;
          }
        }
        else if (param_3 != (ushort *)0x0) goto LAB_140008910;
        bVar2 = false;
        if ((plVar4[5] != 0) &&
           (RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0), plVar4[6] != 0
           )) {
          RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0);
        }
        goto LAB_1400089f6;
      }
    }
  }
  plVar4 = (longlong *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                           (ulonglong)(ushort)param_2[1] + 0x38);
  if (plVar4 == (longlong *)0x0) {
LAB_140008ac8:
    uVar6 = 0xc0000017;
  }
  else {
    plVar4[1] = (longlong)plVar4;
    *plVar4 = (longlong)plVar4;
    plVar4[3] = (longlong)(plVar4 + 7);
    *(undefined2 *)(plVar4 + 2) = *param_2;
    *(undefined2 *)((longlong)plVar4 + 0x12) = param_2[1];
    plVar4[6] = 0;
    memcpy(plVar4 + 7,*(void **)(param_2 + 4),(ulonglong)(ushort)param_2[1]);
    plVar4[5] = 0;
LAB_1400089f6:
    if (param_3 == (ushort *)0x0) {
      RtlInitUnicodeString(plVar4 + 4,0);
    }
    else {
      _Dst = (void *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                     SmBaseTag,param_3[1]);
      plVar4[5] = (longlong)_Dst;
      if (_Dst == (void *)0x0) {
LAB_140008ac0:
        SmpFreeSavedRegistryEntry(plVar4);
        goto LAB_140008ac8;
      }
      *(ushort *)(plVar4 + 4) = *param_3;
      *(ushort *)((longlong)plVar4 + 0x22) = param_3[1];
      memcpy(_Dst,*(void **)(param_3 + 4),(ulonglong)param_3[1]);
      if ((param_4 & 2) != 0) {
        lVar5 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                (*param_3 >> 1) + 1);
        plVar4[6] = lVar5;
        if (lVar5 == 0) goto LAB_140008ac0;
        local_28 = (ulonglong)CONCAT42((int)((ulonglong)local_28 >> 0x20),(*param_3 >> 1) + 1) <<
                   0x10;
        lStack_20 = lVar5;
        RtlUnicodeStringToAnsiString(&local_28,param_3,0);
      }
    }
    puVar9 = auStack_48;
    if (bVar2) {
      plVar7 = (longlong *)param_1[1];
      if ((longlong *)*plVar7 != param_1) {
        pcVar1 = (code *)swi(0x29);
        plVar7 = (longlong *)(*pcVar1)(3);
        puVar8 = auStack_40;
      }
      *plVar4 = (longlong)param_1;
      plVar4[1] = (longlong)plVar7;
      *plVar7 = (longlong)plVar4;
      param_1[1] = (longlong)plVar4;
      puVar9 = puVar8;
    }
    if (*(undefined8 **)(puVar9 + 0x70) != (undefined8 *)0x0) {
      **(undefined8 **)(puVar9 + 0x70) = plVar4;
    }
    uVar6 = 0;
  }
  return uVar6;
}



===== ApiSetResolveToHost @ 140008b40 =====

undefined8
ApiSetResolveToHost(int *param_1,ushort *param_2,ushort *param_3,undefined1 *param_4,short *param_5)

{
  ulonglong *puVar1;
  int iVar2;
  undefined8 uVar3;
  short *psVar4;
  longlong lVar5;
  int *piVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  longlong lVar9;
  longlong lVar10;
  int iVar11;
  int iVar12;
  ushort uVar13;
  uint uVar14;
  int iVar15;
  
  piVar6 = param_1;
  if (((char)*param_1 == '\a') ||
     ((((*param_1 == 6 && (8 < (uint)param_1[4])) && (piVar6 = param_1 + 7, (char)*piVar6 == '\a'))
      && ((*(byte *)((longlong)param_1 + 0x1e) & 4) == 0)))) {
    uVar3 = ApiSetpResolveHost((longlong)piVar6,*(ulonglong **)(param_2 + 4),
                               (ulonglong)(*param_2 >> 1),param_4,param_3,param_4,param_5);
    return uVar3;
  }
  uVar8 = 0;
  param_5[0] = 0;
  param_5[1] = 0;
  param_5[2] = 0;
  param_5[3] = 0;
  param_5[4] = 0;
  param_5[5] = 0;
  param_5[6] = 0;
  param_5[7] = 0;
  uVar13 = *param_2;
  uVar7 = (ulonglong)uVar13;
  if (7 < uVar13) {
    puVar1 = *(ulonglong **)(param_2 + 4);
    if (((*puVar1 & 0xffffffdfffdfffdf) == 0x2d004900500041) ||
       ((*puVar1 & 0xffffffdfffdfffdf) == 0x2d005400580045)) {
      psVar4 = (short *)((longlong)puVar1 + uVar7);
      if (1 < uVar13) {
        do {
          uVar14 = (int)uVar7 - 2;
          uVar7 = (ulonglong)uVar14;
          psVar4 = psVar4 + -1;
          if (*psVar4 == 0x2d) break;
        } while (1 < uVar14);
      }
      uVar13 = (ushort)uVar7 >> 1;
      if (uVar13 != 0) {
        lVar5 = ApiSetpSearchForApiSet((longlong)param_1,(ushort *)puVar1,uVar13);
        uVar8 = 0;
        if (lVar5 != 0) {
          if ((param_3 == (ushort *)0x0) || (*(uint *)(lVar5 + 0x14) < 2)) {
            if (*(int *)(lVar5 + 0x14) == 0) goto LAB_140008d67;
            lVar10 = (ulonglong)*(uint *)(lVar5 + 0x10) + (longlong)param_1;
          }
          else {
            uVar13 = *param_3;
            iVar15 = 1;
            uVar3 = *(undefined8 *)(param_3 + 4);
            lVar9 = (ulonglong)*(uint *)(lVar5 + 0x10) + (longlong)param_1;
            iVar11 = *(uint *)(lVar5 + 0x14) - 1;
            lVar10 = lVar9;
            if (0 < iVar11) {
              do {
                iVar12 = iVar15 + iVar11 >> 1;
                lVar10 = (longlong)param_1 +
                         (longlong)iVar12 * 0x14 + (ulonglong)*(uint *)(lVar5 + 0x10);
                iVar2 = RtlCompareUnicodeStrings
                                  (uVar3,uVar13 >> 1,
                                   (ulonglong)
                                   *(uint *)((longlong)param_1 +
                                            (longlong)iVar12 * 0x14 +
                                            (ulonglong)*(uint *)(lVar5 + 0x10) + 4) +
                                   (longlong)param_1,*(uint *)(lVar10 + 8) >> 1,1);
                if (iVar2 < 0) {
                  iVar11 = iVar12 + -1;
                }
                else {
                  if (iVar2 < 1) break;
                  iVar15 = iVar12 + 1;
                }
                lVar10 = lVar9;
              } while (iVar15 <= iVar11);
            }
          }
          *(ulonglong *)(param_5 + 4) = (ulonglong)*(uint *)(lVar10 + 0xc) + (longlong)param_1;
          param_5[1] = *(short *)(lVar10 + 0x10);
          *param_5 = *(short *)(lVar10 + 0x10);
          uVar8 = 1;
        }
      }
    }
  }
LAB_140008d67:
  *param_4 = uVar8;
  return 0;
}



===== SmpWaitForSubSysStartup @ 140008d90 =====

void SmpWaitForSubSysStartup(uint param_1,ulonglong param_2,longlong param_3,uint *param_4)

{
  uint *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  undefined7 extraout_var;
  undefined8 *puVar7;
  int *piVar8;
  int *piVar9;
  longlong *plVar10;
  
  lVar2 = SmpKnownSubSysTable + (ulonglong)(param_1 & 0x1f) * 0x18;
  if (param_4 != (uint *)0x0) {
    *(longlong *)(param_4 + 2) = lVar2;
    *param_4 = (uint)((param_2 & 2) != 0);
  }
  if ((param_2 & 2) != 0) {
    RtlAcquireSRWLockShared(lVar2 + 0x10);
    plVar10 = *(longlong **)(param_4 + 2);
    while ((longlong *)*plVar10 == plVar10) {
      RtlSleepConditionVariableSRW(&SmpSubSysReadyCondition,plVar10 + 2,0,1);
    }
    return;
  }
  RtlAcquireSRWLockExclusive();
  puVar3 = *(undefined8 **)(param_4 + 2);
LAB_140008dfc:
  puVar7 = (undefined8 *)*puVar3;
  while( true ) {
    if (puVar7 == puVar3) {
      return;
    }
    if (*(uint *)(puVar7 + -1) == param_1) break;
    puVar7 = (undefined8 *)*puVar7;
  }
  piVar9 = (int *)(puVar7 + -9);
  if (piVar9 == (int *)0x0) {
    return;
  }
  do {
    puVar1 = (uint *)(piVar9 + 2);
    if (((param_2 & 1) == 0) || ((*puVar1 & 1) != 0)) {
      piVar8 = piVar9;
      bVar6 = SmpCheckSubSysStatus((longlong)piVar9);
      if ((int)CONCAT71(extraout_var,bVar6) == 0) {
        LOCK();
        *piVar9 = *piVar9 + 1;
        UNLOCK();
        SmpWaitForStatusChange((longlong)piVar8,0,(int *)param_4);
        if ((*puVar1 & 4) != 0) break;
        SmpDereferenceKnownSubSys(piVar9);
      }
      puVar7 = *(undefined8 **)(piVar9 + 0x12);
      plVar10 = (longlong *)(piVar9 + 0x12);
      if (param_3 != 0) {
        LOCK();
        *puVar1 = *puVar1 | 4;
        UNLOCK();
        lVar2 = *plVar10;
        if ((*(longlong **)(lVar2 + 8) != plVar10) ||
           (plVar4 = *(longlong **)(piVar9 + 0x14), (longlong *)*plVar4 != plVar10)) {
LAB_140008f19:
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
        *plVar4 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar4;
        plVar4 = *(longlong **)(param_3 + 8);
        if (*plVar4 != param_3) goto LAB_140008f19;
        *plVar10 = param_3;
        *(longlong **)(piVar9 + 0x14) = plVar4;
        *plVar4 = (longlong)plVar10;
        *(longlong **)(param_3 + 8) = plVar10;
      }
    }
    else {
      puVar7 = (undefined8 *)*puVar7;
    }
    if (puVar7 == puVar3) {
      return;
    }
    piVar9 = (int *)(puVar7 + -9);
    if (*(uint *)(puVar7 + -1) != param_1) {
      return;
    }
  } while( true );
  SmpDereferenceKnownSubSys(piVar9);
  goto LAB_140008dfc;
}



===== SmpInitializeKnownDllsInternal @ 140008f30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpInitializeKnownDllsInternal
                    (undefined8 param_1,undefined8 param_2,int param_3,int param_4,byte param_5)

{
  ushort *puVar1;
  longlong lVar2;
  longlong ****pppplVar3;
  code *pcVar4;
  longlong ***ppplVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined4 *puVar11;
  longlong ****pppplVar12;
  longlong ****pppplVar13;
  ulonglong uVar14;
  undefined1 *puVar15;
  uint uVar16;
  ushort uVar17;
  bool bVar18;
  undefined1 auStack_1a8 [8];
  undefined1 auStack_1a0 [24];
  int *local_188;
  undefined8 local_180;
  char local_178 [4];
  int local_174;
  uint local_170;
  int local_16c;
  longlong ****local_168;
  longlong ****local_160;
  longlong local_158;
  ulonglong local_150;
  undefined8 local_148;
  undefined8 uStack_140;
  ulonglong local_138 [2];
  undefined4 local_128;
  undefined4 local_124;
  undefined8 local_120;
  ushort *local_118;
  undefined4 local_110;
  undefined4 local_10c;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  ushort *local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  longlong local_d8;
  undefined8 local_d0;
  ushort *local_c8;
  longlong ****local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  code *local_a0;
  ushort **local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 *local_80;
  undefined4 local_78;
  ulonglong local_74;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 *local_58;
  longlong local_50;
  ushort *local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_150 = 0;
  local_c8 = (ushort *)0x0;
  local_124 = 0;
  local_10c = 0;
  local_174 = 0;
  local_f4 = 0;
  local_dc = 0;
  local_178[0] = '\0';
  local_b8 = 0;
  uStack_b0 = 0;
  uVar17 = 0;
  local_90 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_84 = 0;
  local_138[0] = 0;
  local_138[1] = 0;
  local_74 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_6c = 0;
  local_158 = 0;
  local_170 = 0;
  local_16c = param_3;
  uVar9 = SmpRandomizeDllList(&SmpKnownDllsList,&local_158,&local_170);
  puVar15 = auStack_1a8;
  uVar14 = uVar9 & 0xffffffff;
  if ((int)uVar9 < 0) {
    SmpLogFailure(0x14002a078,0x134a,(int)uVar9);
    puVar15 = auStack_1a8;
  }
  else {
    local_c0 = (longlong ****)&local_168;
    local_128 = 0x30;
    local_98 = &local_c8;
    local_a0 = SmpProcessModuleImports;
    local_d8 = SmpKnownDllSecurityDescriptor;
    local_80 = &local_f8;
    local_110 = 0x40;
    local_118 = (ushort *)0x0;
    local_108 = 0;
    uStack_100 = 0;
    local_a8 = 0x40;
    local_a4 = 7;
    local_f8 = 0x30;
    local_e0 = 0x50;
    local_e8 = (ushort *)0x0;
    local_d0 = 0;
    local_88 = 0xf001f;
    local_78 = 0x10;
    local_120 = param_2;
    local_f0 = param_1;
    do {
      local_160 = (longlong ****)&local_168;
      local_168 = (longlong ****)&local_168;
      for (uVar9 = 0; (uint)uVar9 < local_170; uVar9 = (ulonglong)((uint)uVar9 + 1)) {
        lVar2 = *(longlong *)(local_158 + 8 + uVar9 * 0x10);
        for (puVar10 = SmpExcludeKnownDllsList; (undefined8 **)puVar10 != &SmpExcludeKnownDllsList;
            puVar10 = (undefined8 *)*puVar10) {
          iVar7 = RtlCompareUnicodeString(puVar10 + 2,lVar2 + 0x10);
          if (iVar7 == 0) {
            if (puVar10 != (undefined8 *)0x0) goto LAB_1400093fe;
            break;
          }
        }
        puVar1 = (ushort *)(lVar2 + 0x20);
        puVar10 = SmpFindRegistryValueEx(&SmpExcludeKnownDllsList,puVar1);
        if (puVar10 != (undefined8 *)0x0) goto LAB_1400093fe;
        bVar18 = false;
        if (*(ushort *)(lVar2 + 0x10) < 2) {
LAB_14000914e:
          local_74 = CONCAT44(local_74._4_4_,0x1000000);
          if (bVar18) {
            if ((param_3 != 0) || (param_4 == 0)) goto LAB_1400093fe;
            local_74 = CONCAT44(local_74._4_4_,0x1100000);
          }
          local_118 = puVar1;
          if ((*(uint *)((longlong)ProcessEnvironmentBlock + 0xbc) & 0x40000) != 0) {
            local_188 = &local_174;
            local_138[0] = local_138[0] & 0xffffffff00000000;
            local_138[1] = 0;
            local_174 = 0;
            iVar7 = NtQueryObject(local_120,1,local_138);
            if (iVar7 == -0x3ffffffc) {
              local_174 = (uint)*local_118 + local_174 + 2;
              puVar11 = (undefined4 *)
                        RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                        local_174);
              if (puVar11 != (undefined4 *)0x0) {
                local_188 = &local_174;
                iVar7 = NtQueryObject(local_120,1,puVar11,local_174);
                if (iVar7 < 0) {
LAB_1400092be:
                  if (puVar11 == (undefined4 *)0x0) goto LAB_1400092e1;
                }
                else {
                  uStack_140 = *(undefined8 *)(puVar11 + 2);
                  local_148 = CONCAT44(puVar11[1],
                                       CONCAT22((short)*puVar11 + 2 + *local_118,(short)*puVar11));
                  iVar7 = RtlAppendUnicodeToString(&local_148,L"\\");
                  if (-1 < iVar7) {
                    iVar7 = RtlAppendUnicodeStringToString(&local_148,local_118);
                    if (-1 < iVar7) {
                      local_180 = 0;
                      local_188 = (int *)((ulonglong)local_188 & 0xffffffff00000000);
                      NtSystemDebugControl(0x26,&local_148,0x10);
                    }
                    goto LAB_1400092be;
                  }
                }
                RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar11);
              }
LAB_1400092e1:
              param_3 = local_16c;
            }
          }
          local_180 = CONCAT44(local_180._4_4_,0x60);
          local_188 = (int *)CONCAT44(local_188._4_4_,5);
          iVar7 = NtOpenFile(&local_150,0x120020);
          if (-1 < iVar7) {
            if (local_d8 != 0) {
              uVar17 = *(ushort *)(local_d8 + 2) & 8;
              *(ushort *)(local_d8 + 2) = *(ushort *)(local_d8 + 2) | 8;
            }
            local_e8 = puVar1;
            local_c8 = puVar1;
            iVar7 = LdrVerifyImageMatchesChecksumEx(local_150 | 1,&local_a8);
            if (local_d8 != 0) {
              *(ushort *)(local_d8 + 2) =
                   *(ushort *)(local_d8 + 2) ^ (*(ushort *)(local_d8 + 2) ^ uVar17) & 8;
            }
            if (iVar7 < 0) {
              local_178[0] = '\x01';
              if (iVar7 == -0x3ffffbd8) {
                iVar8 = RtlAppxIsFileOwnedByTrustedInstaller(local_150,local_178);
                if ((iVar8 < 0) || (local_178[0] != '\0')) {
LAB_1400093a9:
                  RtlInitUnicodeString(&local_b8,L"Verification of a KnownDLL failed.");
LAB_14000955b:
                  local_58 = &local_b8;
                  local_50 = (longlong)iVar7;
                  local_48 = puVar1;
                  SmpLogFailureString(0x14002a078,0x145d,*(longlong *)(lVar2 + 0x18),iVar7);
                    /* WARNING: Subroutine does not return */
                  SmpTerminate(&local_58,5,3);
                }
              }
              else if (iVar7 != -0x3fffffcb) goto LAB_1400093a9;
            }
            else {
              if ((local_74 & 0x200000000000) == 0) {
                RtlInitUnicodeString(&local_b8,L"Non-DLL file included in KnownDLL list.");
                iVar7 = -0x3ffffc91;
                goto LAB_14000955b;
              }
              NtClose(local_90);
            }
            NtClose(local_150);
          }
        }
        else {
          bVar18 = **(short **)(lVar2 + 0x18) == 0x5f;
          if (**(short **)(lVar2 + 0x18) == 0x2a) {
            if ((param_5 & 2) == 0) goto LAB_14000914e;
          }
          else if ((param_5 & 3) != 1) goto LAB_14000914e;
        }
LAB_1400093fe:
      }
      pppplVar12 = *(longlong *****)((longlong)ProcessEnvironmentBlock + 0x30);
      RtlFreeHeap(pppplVar12,0,local_158);
      local_158 = 0;
      uVar16 = 0;
      local_170 = 0;
      pppplVar13 = local_168;
      puVar6 = auStack_1a8;
      if ((longlong *****)local_168 == &local_168) {
LAB_1400095a0:
        puVar15 = puVar6;
        uVar14 = 0;
        goto LAB_1400095a3;
      }
      do {
        pppplVar3 = (longlong ****)*pppplVar13;
        puVar10 = SmpFindModuleInModuleList(pppplVar12,pppplVar13 + 2);
        if (puVar10 == (undefined8 *)0x0) {
          uVar16 = uVar16 + 1;
        }
        else {
          SmpFreeSavedRegistryEntry((longlong *)pppplVar13);
          pppplVar12 = pppplVar13;
        }
        pppplVar13 = pppplVar3;
      } while ((longlong *****)pppplVar3 != &local_168);
      puVar6 = auStack_1a8;
      if (uVar16 == 0) goto LAB_1400095a0;
      local_170 = uVar16;
      uVar9 = SmpRandomizeDllList((longlong *)&local_168,&local_158,&local_170);
      pppplVar13 = local_160;
      pppplVar12 = local_168;
      ppplVar5 = DAT_140032a78;
      uVar14 = uVar9 & 0xffffffff;
      if (((longlong *****)local_168[1] != &local_168) || ((longlong *****)*local_160 != &local_168)
         ) {
LAB_140009599:
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar6 = auStack_1a0;
        goto LAB_1400095a0;
      }
      *local_160 = (longlong ***)local_168;
      pppplVar12[1] = (longlong ***)pppplVar13;
      if ((*(undefined8 **)(SmpKnownDllsList + 8) != &SmpKnownDllsList) ||
         (((*DAT_140032a78 != (longlong **)&SmpKnownDllsList ||
           ((longlong ****)(*pppplVar12)[1] != pppplVar12)) ||
          ((longlong ****)*pppplVar13 != pppplVar12)))) goto LAB_140009599;
      *DAT_140032a78 = (longlong **)pppplVar12;
      DAT_140032a78 = pppplVar12[1];
      *pppplVar12[1] = (longlong **)&SmpKnownDllsList;
      pppplVar12[1] = ppplVar5;
    } while (-1 < (int)uVar9);
    SmpLogFailure(0x14002a078,0x1491,(int)uVar9);
  }
LAB_1400095a3:
  *(undefined8 *)(puVar15 + -8) = 0x1400095b1;
  return uVar14;
}



===== SmpFindRegistryValueEx @ 1400095d4 =====

undefined8 * SmpFindRegistryValueEx(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)*param_1;
  while( true ) {
    if (puVar2 == param_1) {
      return (undefined8 *)0x0;
    }
    iVar1 = RtlCompareUnicodeString(puVar2 + 2,param_2,1);
    if (iVar1 == 0) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2;
}



===== SmpFindModuleInModuleList @ 140009630 =====

undefined8 * SmpFindModuleInModuleList(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_18;
  longlong lStack_10;
  
  puVar3 = SmpKnownDllsList;
  while( true ) {
    if ((undefined8 **)puVar3 == &SmpKnownDllsList) {
      return (undefined8 *)0x0;
    }
    uVar1 = puVar3[2];
    lStack_10 = puVar3[3];
    local_18 = uVar1;
    if ((*(short *)(puVar3 + 2) != 0) &&
       ((*(short *)puVar3[3] == 0x5f || (*(short *)puVar3[3] == 0x2a)))) {
      lStack_10 = lStack_10 + 2;
      local_18._0_2_ = (short)*(undefined4 *)(puVar3 + 2);
      local_18._0_2_ = (short)local_18 + -2;
      local_18._2_2_ = (short)((ulonglong)uVar1 >> 0x10);
      local_18._2_2_ = local_18._2_2_ + -2;
      local_18._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
    }
    iVar2 = RtlCompareUnicodeString(&local_18,param_2,1);
    if (iVar2 == 0) break;
    puVar3 = (undefined8 *)*puVar3;
  }
  return puVar3;
}



===== SmpRandomizeDllList @ 1400096f0 =====

undefined8 SmpRandomizeDllList(longlong *param_1,undefined8 *param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 *_Base;
  longlong *plVar4;
  undefined4 *puVar5;
  
  if ((longlong *)*param_1 == param_1) {
    *param_2 = 0;
    *param_3 = 0;
  }
  else {
    if (DAT_1400322e8 == 0) {
      uVar3 = rdtsc();
      if ((int)uVar3 == 0) {
        uVar3 = NtQueryInformationProcess(0xffffffffffffffff,0x24,&DAT_1400322e8,4,0);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
      }
      else {
        DAT_1400322e8 = (int)uVar3;
      }
    }
    uVar1 = *param_3;
    if (uVar1 == 0) {
      for (plVar4 = (longlong *)*param_1; plVar4 != param_1; plVar4 = (longlong *)*plVar4) {
        uVar1 = uVar1 + 1;
      }
      *param_3 = uVar1;
    }
    _Base = (undefined4 *)
            RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                            (ulonglong)uVar1 << 4);
    if (_Base == (undefined4 *)0x0) {
      return 0xc000009a;
    }
    puVar5 = _Base;
    for (plVar4 = (longlong *)*param_1; plVar4 != param_1; plVar4 = (longlong *)*plVar4) {
      uVar2 = RtlRandomEx(&DAT_1400322e8);
      *puVar5 = uVar2;
      *(longlong **)(puVar5 + 2) = plVar4;
      puVar5 = puVar5 + 4;
    }
    qsort_s(_Base,(ulonglong)uVar1,0x10,SmpSortDllList,(void *)0x0);
    *param_2 = _Base;
  }
  return 0;
}



===== SmpLockKnownSubSysList @ 140009840 =====

void SmpLockKnownSubSysList(uint param_1,int param_2,int *param_3)

{
  longlong lVar1;
  
  lVar1 = SmpKnownSubSysTable + (ulonglong)(param_1 & 0x1f) * 0x18;
  if (param_3 != (int *)0x0) {
    *(longlong *)(param_3 + 2) = lVar1;
    *param_3 = param_2;
  }
  if (param_2 == 1) {
                    /* WARNING: Could not recover jumptable at 0x000140009873. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    RtlAcquireSRWLockShared(lVar1 + 0x10);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000140009867. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAcquireSRWLockExclusive();
  return;
}



===== SmpEventWriteULONG @ 140009890 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpEventWriteULONG(undefined8 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 local_res10 [6];
  undefined1 auStack_48 [32];
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  if (SmpTraceHandle != 0) {
    local_res10[0] = param_2;
    cVar1 = EtwEventEnabled(SmpTraceHandle,param_1);
    if (cVar1 != '\0') {
      local_28 = local_res10;
      local_20 = 4;
      EtwEventWrite(SmpTraceHandle,param_1,1,&local_28);
    }
  }
  return;
}



===== SmExecPgmEx @ 140009920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmExecPgmEx(undefined8 param_1,undefined8 *param_2)

{
  undefined1 auStack_188 [32];
  undefined1 local_168 [40];
  undefined4 local_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined8 local_d8;
  undefined1 local_d0;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_188;
  memset(local_168,0,0x148);
  local_138 = *param_2;
  uStack_130 = param_2[1];
  local_128 = param_2[2];
  uStack_120 = param_2[3];
  local_118 = param_2[4];
  uStack_110 = param_2[5];
  local_f8 = param_2[8];
  uStack_f0 = param_2[9];
  local_108 = param_2[6];
  uStack_100 = param_2[7];
  local_d8 = param_2[0xc];
  local_e8 = *(undefined4 *)(param_2 + 10);
  uStack_e4 = *(undefined4 *)((longlong)param_2 + 0x54);
  uStack_e0 = *(undefined4 *)(param_2 + 0xb);
  uStack_dc = *(undefined4 *)((longlong)param_2 + 0x5c);
  local_d0 = 0;
  local_140 = 3;
  RtlSendMsgToSm(SmpApiConnectionPort,local_168);
  return;
}



===== SmpSessionIdToInitialSessionIndex @ 1400099f0 =====

ulonglong SmpSessionIdToInitialSessionIndex(int param_1)

{
  ulonglong uVar1;
  
  if (param_1 != -1) {
    for (uVar1 = 0; (uint)uVar1 < SmpNumberInitialSessions; uVar1 = (ulonglong)((uint)uVar1 + 1)) {
      if (param_1 == *(int *)(SmpCoreProcessIds + uVar1 * 0x28)) {
        return uVar1;
      }
    }
  }
  return 0xffffffff;
}



===== SmpGetMuSessionIdFromClientContext @ 140009a30 =====

undefined4 SmpGetMuSessionIdFromClientContext(uint *param_1,longlong *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  undefined4 local_res8 [2];
  
  lVar4 = *(longlong *)(param_1 + 8);
  local_res8[0] = 0;
  if ((*param_1 & 0x10) != 0) {
    uVar2 = *(undefined4 *)(lVar4 + 0x40);
    *param_2 = *(longlong *)(lVar4 + 0x20);
    return uVar2;
  }
  if ((*param_1 & 8) == 0) {
    uVar2 = 0;
    if (lVar4 != 0) {
      iVar3 = SmpGetProcessMuSessionId(lVar4,local_res8);
      if (iVar3 < 0) {
        lVar4 = 0;
        uVar2 = 0;
      }
      else {
        uVar2 = local_res8[0];
      }
    }
  }
  else {
    puVar1 = (undefined4 *)(lVar4 + 8);
    lVar4 = *(longlong *)(lVar4 + 0x30);
    uVar2 = *puVar1;
  }
  *param_2 = lVar4;
  return uVar2;
}



===== SmpAddKnownSubSys @ 140009ab0 =====

void SmpAddKnownSubSys(longlong param_1,int *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar1 = *(longlong **)(param_1 + 8);
  *param_2 = *param_2 + 1;
  plVar4 = (longlong *)plVar1[1];
  if (plVar4 != plVar1) {
    do {
      if ((int)plVar4[-1] == param_2[0x10]) break;
      plVar4 = (longlong *)plVar4[1];
    } while (plVar4 != plVar1);
  }
  lVar2 = *plVar4;
  plVar1 = (longlong *)(param_2 + 0x12);
  plVar4 = *(longlong **)(lVar2 + 8);
  if (*plVar4 == lVar2) {
    *plVar1 = lVar2;
    *(longlong **)(param_2 + 0x14) = plVar4;
    *plVar4 = (longlong)plVar1;
    *(longlong **)(lVar2 + 8) = plVar1;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== CreateMergeLink @ 140009b10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CreateMergeLink(undefined8 *param_1,undefined *param_2)

{
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int iVar1;
  undefined4 uVar3;
  ushort *puVar2;
  undefined1 auStack_b8 [32];
  undefined4 *local_98;
  uint local_90;
  undefined8 local_88;
  undefined4 local_80 [2];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 *local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined4 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  local_30 = 0;
  local_28 = 0;
  local_50 = 0;
  uStack_48 = uStack_48 & 0xffffffff00000000;
  local_80[0] = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_88 = 0;
  local_60 = (undefined8 *)0x0;
  uStack_58 = 0;
  local_78 = 0;
  local_40 = 0;
  uStack_38 = 0;
  uVar3 = (undefined4)((ulonglong)param_2 >> 0x20);
  iVar1 = CreateKeyRecursively(&local_88,param_2,param_1,'\x01');
  puVar2 = (ushort *)CONCAT44(uVar3,iVar1);
  if (extraout_EAX == -0x3fffffde) {
    return;
  }
  iVar1 = extraout_EAX;
  if (extraout_EAX == -0x3fffffcb) {
    local_40 = *param_1;
    uStack_38 = param_1[1];
    local_60 = &local_40;
    local_70 = CONCAT44(local_70._4_4_,0x30);
    uStack_68 = 0;
    uStack_58 = CONCAT44(uStack_58._4_4_,0x140);
    local_50 = 0;
    uStack_48 = 0;
    iVar1 = NtOpenKey(&local_88,0x3001f,&local_70);
    if (iVar1 < 0) {
      return;
    }
    local_98 = local_80;
    param_2 = (undefined *)0x5;
    iVar1 = NtQueryKey(local_88,5,&local_30);
    if (iVar1 < 0) {
      NtClose();
      return;
    }
    if (((byte)((ulonglong)local_30 >> 0x20) & 3) != 2) {
      NtClose(local_88);
      goto LAB_140009cbe;
    }
    iVar1 = NtDeleteKey();
    NtClose(local_88);
    if (iVar1 < 0) {
      return;
    }
    iVar1 = CreateKeyRecursively(&local_88,param_2,param_1,'\x01');
    puVar2 = (ushort *)CONCAT44(uVar3,iVar1);
    iVar1 = extraout_EAX_00;
  }
  if (iVar1 < 0) {
    if (iVar1 != -0x3fffffcb) {
      return;
    }
  }
  else {
    param_2 = &SymbolicLinkValueName;
    local_90 = (uint)*puVar2;
    local_98 = *(undefined4 **)(puVar2 + 4);
    iVar1 = NtSetValueKey(local_88,&SymbolicLinkValueName,0);
    NtClose(local_88);
    if (iVar1 < 0) {
      return;
    }
  }
LAB_140009cbe:
  CreateKeyRecursively(&local_78,param_2,(undefined8 *)puVar2,'\0');
  if (-1 < extraout_EAX_01) {
    NtClose(local_78);
  }
  return;
}



===== CreateKeyRecursively @ 140009d28 =====

int CreateKeyRecursively(undefined8 *param_1,undefined8 param_2,undefined8 *param_3,char param_4)

{
  ulonglong uVar1;
  short sVar2;
  int iVar3;
  ushort uVar4;
  short *psVar5;
  short sVar6;
  int unaff_EDI;
  byte bVar7;
  uint uVar8;
  int iVar9;
  undefined8 local_res10 [2];
  undefined4 local_res20 [2];
  undefined8 local_78;
  short *psStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 *local_58;
  int local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_78 = *param_3;
  psStack_70 = (short *)param_3[1];
  local_68 = 0x30;
  local_res20[0] = 0;
  local_4c = 0;
  local_res10[0] = 0;
  local_60 = 0;
  bVar7 = -(param_4 != '\0') & 3;
  local_58 = &local_78;
  uVar8 = -(uint)(param_4 != '\0') & 0x20;
  iVar9 = (-(uint)(param_4 != '\0') & 0x100) + 0x40;
  local_48 = 0;
  uStack_40 = 0;
  local_50 = iVar9;
  iVar3 = NtCreateKey(local_res10,uVar8 + 0x20006,&local_68,0,0,bVar7,local_res20);
  if (iVar3 == -0x3fffffcc) {
    local_78._0_4_ = CONCAT22((ushort)local_78,(ushort)local_78);
    uVar4 = (ushort)local_78 >> 1;
    local_50 = 0x40;
    psVar5 = psStack_70 + ((ulonglong)uVar4 - 1);
    iVar3 = -0x3fffffcc;
LAB_140009e09:
    if (iVar3 == -0x3fffffcc) {
      if (uVar4 == 0) {
        return unaff_EDI;
      }
      do {
        if (*psVar5 == 0x5c) goto LAB_140009e3b;
        psVar5 = psVar5 + -1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      goto LAB_140009e44;
    }
    if (iVar3 < 0) {
      return unaff_EDI;
    }
    local_60 = local_res10[0];
    sVar6 = (local_78._2_2_ >> 1) - uVar4;
    psVar5 = psStack_70 + uVar4;
    while (local_res10[0] = 0, sVar6 != 0) {
      do {
        psStack_70 = psVar5;
        if (*psVar5 != 0x5c) break;
        psVar5 = psVar5 + 1;
        sVar6 = sVar6 + -1;
        psStack_70 = psVar5;
      } while (sVar6 != 0);
      sVar2 = 0;
      local_78 = local_78 & 0xffffffffffff0000;
      uVar1 = local_78;
      for (psVar5 = psStack_70; (sVar6 != 0 && (*psVar5 != 0x5c)); psVar5 = psVar5 + 1) {
        sVar2 = sVar2 + 2;
        local_78._2_6_ = (undefined6)(uVar1 >> 0x10);
        local_78 = CONCAT62(local_78._2_6_,sVar2);
        sVar6 = sVar6 + -1;
        uVar1 = local_78;
      }
      local_78._4_4_ = (undefined4)(uVar1 >> 0x20);
      local_78._0_2_ = (ushort)uVar1;
      local_78._0_4_ = CONCAT22(sVar2,(ushort)local_78);
      if (sVar6 == 0) break;
      iVar3 = NtCreateKey(local_res10,0x20006,&local_68,0,0,0,local_res20);
      NtClose(local_60);
      if (iVar3 < 0) {
        return unaff_EDI;
      }
      local_60 = local_res10[0];
    }
    local_50 = iVar9;
    iVar3 = NtCreateKey(local_res10,uVar8 + 0x20006,&local_68,0,0,bVar7,local_res20);
    NtClose(local_60);
  }
  if (-1 < iVar3) {
    *param_1 = local_res10[0];
  }
  return unaff_EDI;
  while (*psVar5 == 0x5c) {
LAB_140009e3b:
    psVar5 = psVar5 + -1;
    uVar4 = uVar4 - 1;
    if (uVar4 == 0) break;
  }
LAB_140009e44:
  local_78 = CONCAT62(local_78._2_6_,uVar4 * 2);
  iVar3 = NtCreateKey(local_res10,0x20006,&local_68,0,0,0,local_res20);
  goto LAB_140009e09;
}



===== SmpSaveOldPageFiles @ 140009fd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpSaveOldPageFiles(void)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *_Dst;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 *puVar8;
  short *psVar9;
  undefined1 auStack_2a8 [32];
  wchar_t *local_288;
  undefined4 *local_280;
  undefined8 local_278;
  wchar_t *pwStack_270;
  undefined4 local_268 [2];
  longlong local_260 [2];
  wchar_t *local_250;
  longlong local_248;
  wchar_t *local_240;
  longlong local_238;
  wchar_t *local_230;
  longlong local_228;
  wchar_t *local_220;
  undefined8 local_218;
  undefined8 uStack_210;
  longlong *local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  ulonglong uStack_1f0;
  short local_1e8 [8];
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  uint local_1b8;
  int local_1b4;
  undefined1 local_1b0 [8];
  longlong local_1a8 [32];
  wchar_t local_a8 [64];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2a8;
  local_1f8 = 0;
  _Dst = &local_1b8;
  uStack_1f0 = uStack_1f0 & 0xffffffff00000000;
  local_250 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\MachineCrash"
  ;
  uVar6 = 0;
  local_240 = L"SavePageFileContents";
  local_260[1] = 0x9a0098;
  local_230 = L"SavedPageFilePath";
  local_248 = 0x2a0028;
  local_220 = L"SavedPageFiles";
  psVar9 = (short *)0x0;
  local_218 = 0;
  uStack_210 = 0;
  local_238 = 0x240022;
  local_208 = (longlong *)0x0;
  uStack_200 = 0;
  local_228 = 0x1e001c;
  local_1e8[0] = 0;
  local_1e8[1] = 0;
  local_1e8[2] = 0;
  local_1e8[3] = 0;
  local_1e8[4] = 0;
  local_1e8[5] = 0;
  local_1e8[6] = 0;
  local_1e8[7] = 0;
  local_268[0] = 0;
  local_1d8 = 0;
  uStack_1d0 = 0;
  memset(_Dst,0,0x108);
  local_260[0] = 0;
  local_278 = 0;
  pwStack_270 = (wchar_t *)0x0;
  local_1c8 = 0;
  uStack_1c0 = 0;
  if (SmpUseDedicatedDumpFile == '\0') {
LAB_14000a183:
    if (SmpSavePageFiles == '\0') {
      iVar2 = 0;
      goto LAB_14000a2f6;
    }
  }
  else {
    local_208 = local_260 + 1;
    local_218 = CONCAT44(local_218._4_4_,0x30);
    uStack_210 = 0;
    _Dst = (uint *)local_260;
    uStack_200 = CONCAT44(uStack_200._4_4_,0x40);
    local_1f8 = 0;
    uStack_1f0 = 0;
    iVar2 = NtOpenKey(_Dst,0x20019);
    if (iVar2 < 0) goto LAB_14000a183;
    local_280 = local_268;
    local_288 = (wchar_t *)CONCAT44(local_288._4_4_,0x10);
    _Dst = SmpCrashDumpKey;
    iVar2 = NtQueryValueKey(SmpCrashDumpKey,local_260 + 3,4,&local_1c8);
    if (((iVar2 < 0) || ((int)local_1c8 != 4)) || ((int)uStack_1c0 != 1)) goto LAB_14000a183;
    SmpSavePageFiles = '\x01';
  }
  uVar3 = SmpQueryPathFromRegistry(_Dst,local_260 + 5,(undefined1 *)0x0,local_1e8);
  psVar9 = local_1e8;
  puVar8 = SmpExistingPageFilesList;
  if ((int)uVar3 < 0) {
    psVar9 = (short *)0x0;
  }
  for (; (undefined8 **)puVar8 != &SmpExistingPageFilesList; puVar8 = (undefined8 *)*puVar8) {
    iVar2 = SmpSaveOldPageFile((short *)(puVar8 + 2),psVar9,&local_1b8);
    if (iVar2 < 0) goto LAB_14000a2f6;
  }
  local_288 = L"swapfile.sys";
  uVar4 = RtlStringCbPrintfW(local_a8,0x80,L"\\??\\%c:\\%s",(ulonglong)SmpOsVolumeLetter);
  iVar2 = (int)uVar4;
  if (-1 < iVar2) {
    RtlInitUnicodeString(&local_1d8,local_a8);
    SmpSaveOldPageFile((short *)&local_1d8,psVar9,&local_1b8);
    uVar5 = local_1b4 + (local_1b8 + 1) * 2;
    if (uVar5 < 0x10000) {
      pwStack_270 = (wchar_t *)
                    RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                    uVar5);
      if (pwStack_270 == (wchar_t *)0x0) {
        iVar2 = -0x3fffff66;
      }
      else {
        uVar3 = 0;
        local_278._0_4_ = CONCAT22((short)uVar5,(ushort)local_278);
        if (local_1b8 == 0) {
          uVar1 = (ushort)local_278;
        }
        else {
          do {
            RtlAppendUnicodeStringToString(&local_278,local_1b0 + uVar3 * 0x10);
            uVar7 = (int)uVar3 + 1;
            uVar3 = (ulonglong)uVar7;
            uVar1 = (ushort)local_278 + 2;
            local_278 = CONCAT62(local_278._2_6_,uVar1);
          } while (uVar7 < local_1b8);
        }
        local_280 = (undefined4 *)CONCAT44(local_280._4_4_,uVar5);
        pwStack_270[uVar1 >> 1] = L'\0';
        local_278 = CONCAT62(local_278._2_6_,(ushort)local_278 + 2);
        local_288 = pwStack_270;
        iVar2 = NtSetValueKey(SmpCrashDumpKey,local_260 + 7,0,7);
        if (-1 < iVar2) {
          NtFlushKey(SmpCrashDumpKey);
        }
      }
    }
    else {
      iVar2 = -0x3ffffefa;
    }
  }
LAB_14000a2f6:
  if (local_260[0] != 0) {
    NtClose();
  }
  if (local_1b8 != 0) {
    do {
      if (local_1a8[uVar6 * 2] != 0) {
        if (iVar2 < 0) {
          SmpDeletePagingFile(local_1b0 + uVar6 * 0x10);
        }
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_1a8[uVar6 * 2]
                   );
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < local_1b8);
  }
  if (pwStack_270 != (wchar_t *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pwStack_270);
  }
  if (psVar9 != (short *)0x0) {
    RtlFreeUnicodeString(psVar9);
  }
  return;
}



===== SmpConfigureSharedSessionData @ 14000a3d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SmpConfigureSharedSessionData(void)

{
  ushort uVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  longlong *plVar6;
  undefined4 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  longlong lVar12;
  void *_Dst;
  undefined2 *puVar13;
  undefined2 *puVar14;
  undefined4 *puVar15;
  undefined8 *puVar16;
  bool bVar17;
  undefined1 auStack_1f8 [32];
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 *local_1c8;
  undefined4 local_1c0;
  undefined4 local_1b8;
  undefined4 local_1b0;
  undefined8 local_1a8;
  undefined2 *local_1a0;
  longlong local_198;
  undefined4 local_190;
  undefined4 local_18c;
  undefined8 local_188;
  undefined8 local_180;
  undefined4 local_178;
  undefined4 local_174;
  undefined8 local_170;
  undefined8 uStack_168;
  code *local_158;
  undefined4 local_150;
  wchar_t *local_148;
  undefined4 *local_140;
  undefined4 local_138;
  undefined8 local_130;
  undefined4 local_128;
  code *local_120;
  undefined4 local_118;
  wchar_t *local_110;
  undefined4 *local_108;
  undefined4 local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  code *local_e8;
  undefined4 local_e0;
  wchar_t *local_d8;
  undefined4 *local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  code *local_b0;
  undefined4 local_a8;
  wchar_t *local_a0;
  undefined4 *local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1f8;
  local_150 = 0x11;
  local_18c = 0;
  local_140 = &DAT_140032358;
  local_120 = SmpBuildSubSystemLists;
  local_158 = SmpConfigureSubSystems;
  local_108 = &DAT_140032358;
  local_148 = L"SubSystems";
  local_e8 = SmpBuildSubSystemLists;
  local_110 = L"Required";
  local_d0 = &DAT_140032358;
  local_d8 = L"Optional";
  local_98 = &DAT_140032358;
  local_b0 = SmpConfigureExecute;
  local_174 = 0;
  local_a0 = L"Execute";
  local_138 = 0;
  local_130 = 0;
  local_128 = 0;
  local_118 = 0x10;
  local_100 = 0;
  local_f8 = 0;
  local_f0 = 0;
  local_e0 = 0x10;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_a8 = 2;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  _DAT_140032368 = &DAT_140032360;
  DAT_140032360 = (longlong *)&DAT_140032360;
  DAT_140032378 = &DAT_140032370;
  DAT_140032370 = (longlong *)&DAT_140032370;
  DAT_140032388 = &DAT_140032380;
  DAT_140032380 = (longlong *)&DAT_140032380;
  local_1d8 = 0;
  uVar9 = RtlQueryRegistryValuesEx(2,L"Session Manager",&local_158,0);
  plVar6 = DAT_140032360;
  puVar16 = DAT_140032388;
  if ((int)uVar9 < 0) {
    return uVar9;
  }
  while (DAT_140032388 = puVar16, (longlong **)plVar6 != &DAT_140032360) {
    plVar2 = (longlong *)*plVar6;
    SmpFreeSavedRegistryEntry(plVar6);
    plVar6 = plVar2;
    puVar16 = DAT_140032388;
  }
  if ((longlong **)DAT_140032380 == &DAT_140032380) {
    lVar12 = (ulonglong)DAT_140032358 * 0x10 + 0x68;
    SmpInitExecuteCmd = (undefined8 *)0x0;
  }
  else {
    DAT_140032388 = (undefined8 *)puVar16[1];
    if (((longlong **)*puVar16 != &DAT_140032380) || ((undefined8 *)*DAT_140032388 != puVar16)) {
LAB_14000abfa:
      DAT_140032388 = puVar16;
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      uVar9 = (*pcVar5)();
      return uVar9;
    }
    *DAT_140032388 = &DAT_140032380;
    lVar12 = (ulonglong)DAT_140032358 * 0x10 + 0x68;
    SmpInitExecuteCmd = puVar16;
    if (puVar16 != (undefined8 *)0x0) {
      uVar9 = (ulonglong)*(ushort *)(puVar16 + 2);
      goto LAB_14000a5a9;
    }
  }
  uVar9 = 0;
LAB_14000a5a9:
  local_1c8 = (undefined8 *)0x0;
  local_1d0._4_4_ = (undefined4)((ulonglong)local_1d0 >> 0x20);
  local_1d0 = CONCAT44(local_1d0._4_4_,0x8400000);
  local_190 = 0x30;
  local_198 = (ulonglong)SmpDefaultLibPath + 6 + SmpS0InitCmd + uVar9 + (ulonglong)DAT_14003235c +
              lVar12;
  local_188 = 0;
  local_178 = 2;
  local_180 = 0;
  local_170 = 0;
  uStack_168 = 0;
  local_1d8._4_4_ = (undefined4)((ulonglong)local_1d8 >> 0x20);
  local_1d8 = CONCAT44(local_1d8._4_4_,4);
  uVar8 = NtCreateSection(&SmpSharedSection,6,&local_190,&local_198);
  uVar9 = (ulonglong)uVar8;
  if ((int)uVar8 < 0) {
    SmpLogFailure(0x140022b10,0x20b8,uVar8);
  }
  else {
    local_1c8 = &local_1a8;
    local_1b0 = 4;
    local_1b8 = 0;
    local_1c0 = 2;
    local_1d0 = 0;
    local_1a8 = 0;
    local_1d8 = 0;
    uVar8 = NtMapViewOfSection(SmpSharedSection,0xffffffffffffffff,&SmpMappedView);
    uVar9 = (ulonglong)uVar8;
    if ((int)uVar8 < 0) {
      SmpLogFailure(0x140022b10,0x20d1,uVar8);
    }
    else {
      bVar17 = SmpS0CommandOverride != 0;
      *SmpMappedView = 0;
      if (bVar17) {
        *SmpMappedView = 1;
      }
      _Dst = (void *)(lVar12 + (longlong)SmpMappedView);
      *(longlong *)(SmpMappedView + 2) = (longlong)_Dst - (longlong)SmpMappedView;
      *(ushort *)(SmpMappedView + 4) = SmpDefaultLibPath;
      memcpy(_Dst,DAT_140033018,(ulonglong)SmpDefaultLibPath);
      uVar9 = (ulonglong)SmpDefaultLibPath;
      *(undefined2 *)((longlong)_Dst + uVar9) = 0;
      puVar13 = (undefined2 *)((longlong)_Dst + uVar9) + 1;
      *(longlong *)(SmpMappedView + 6) = (longlong)puVar13 - (longlong)SmpMappedView;
      *(ushort *)(SmpMappedView + 8) = SmpS0InitCmd;
      memcpy(puVar13,PTR_u_wininit_exe_140030e40,(ulonglong)SmpS0InitCmd);
      puVar16 = SmpInitExecuteCmd;
      uVar9 = (ulonglong)SmpS0InitCmd;
      *(undefined2 *)((longlong)puVar13 + uVar9) = 0;
      puVar13 = (undefined2 *)((longlong)puVar13 + uVar9) + 1;
      *(longlong *)(SmpMappedView + 10) = (longlong)puVar13 - (longlong)SmpMappedView;
      if ((puVar16 == (undefined8 *)0x0) || (puVar16[3] == 0)) {
        *(undefined2 *)(SmpMappedView + 0xc) = 0;
      }
      else {
        *(undefined2 *)(SmpMappedView + 0xc) = *(undefined2 *)(puVar16 + 2);
        memcpy(puVar13,(void *)puVar16[3],(ulonglong)*(ushort *)(puVar16 + 2));
        puVar13 = (undefined2 *)((longlong)puVar13 + (ulonglong)*(ushort *)(puVar16 + 2));
      }
      *puVar13 = 0;
      puVar7 = SmpMappedView;
      uVar8 = 0;
      puVar13 = puVar13 + 1;
      puVar15 = SmpMappedView + 0x1a;
      puVar14 = puVar13;
      local_1a0 = puVar13;
      plVar6 = DAT_140032370;
      while ((longlong **)plVar6 != &DAT_140032370) {
        plVar2 = (longlong *)*plVar6;
        *(longlong *)(puVar15 + (ulonglong)uVar8 * 4) = (longlong)puVar14 - (longlong)SmpMappedView;
        *(short *)(puVar7 + (ulonglong)uVar8 * 4 + 0x1c) = (short)plVar6[2];
        memcpy(puVar14,(void *)plVar6[3],(ulonglong)*(ushort *)(plVar6 + 2));
        uVar1 = *(ushort *)(plVar6 + 2);
        uVar8 = uVar8 + 1;
        *(undefined2 *)((longlong)puVar14 + (ulonglong)uVar1) = 0;
        puVar14 = (undefined2 *)((longlong)puVar14 + (ulonglong)uVar1) + 1;
        lVar12 = *plVar6;
        puVar16 = DAT_140032388;
        if ((*(longlong **)(lVar12 + 8) != plVar6) ||
           (plVar3 = (longlong *)plVar6[1], (longlong *)*plVar3 != plVar6)) goto LAB_14000abfa;
        *plVar3 = lVar12;
        *(longlong **)(lVar12 + 8) = plVar3;
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,plVar6);
        plVar6 = plVar2;
      }
      *(longlong *)(SmpMappedView + 0xe) = (longlong)puVar15 - (longlong)SmpMappedView;
      SmpMappedView[0x10] = uVar8;
      SmpMappedView[0x11] = 0;
      if (uVar8 != 0) {
        puVar15 = puVar15 + (ulonglong)uVar8 * 4;
        puVar13 = puVar14;
        local_1a0 = puVar14;
      }
      uVar9 = 0;
      uVar8 = 0;
      puVar14 = puVar13;
      puVar16 = SmpSubSystemsRequired;
      if ((undefined8 **)SmpSubSystemsRequired != &SmpSubSystemsRequired) {
        do {
          puVar4 = (undefined8 *)*puVar16;
          *(longlong *)(puVar15 + uVar9 * 4) = (longlong)puVar13 - (longlong)SmpMappedView;
          *(undefined2 *)(puVar15 + uVar9 * 4 + 2) = *(undefined2 *)(puVar16 + 2);
          memcpy(puVar13,(void *)puVar16[3],(ulonglong)*(ushort *)(puVar16 + 2));
          uVar1 = *(ushort *)(puVar16 + 2);
          uVar10 = (ulonglong)((int)uVar9 + 1);
          *(undefined2 *)((longlong)puVar13 + (ulonglong)uVar1) = 0;
          puVar13 = (undefined2 *)((longlong)puVar13 + (ulonglong)uVar1) + 1;
          *(longlong *)(puVar15 + uVar10 * 4) = (longlong)puVar13 - (longlong)SmpMappedView;
          *(undefined2 *)(puVar15 + uVar10 * 4 + 2) = *(undefined2 *)(puVar16 + 4);
          memcpy(puVar13,(void *)puVar16[5],(ulonglong)*(ushort *)(puVar16 + 4));
          uVar1 = *(ushort *)(puVar16 + 4);
          uVar8 = (int)uVar9 + 2;
          uVar9 = (ulonglong)uVar8;
          *(undefined2 *)((longlong)puVar13 + (ulonglong)uVar1) = 0;
          puVar13 = (undefined2 *)((longlong)puVar13 + (ulonglong)uVar1) + 1;
          puVar16 = puVar4;
        } while ((undefined8 **)puVar4 != &SmpSubSystemsRequired);
        puVar14 = local_1a0;
      }
      *(longlong *)(SmpMappedView + 0x12) = (longlong)puVar15 - (longlong)SmpMappedView;
      SmpMappedView[0x14] = uVar8;
      SmpMappedView[0x15] = 1;
      if (uVar8 != 0) {
        puVar15 = puVar15 + (ulonglong)uVar8 * 4;
        puVar14 = puVar13;
      }
      uVar9 = 0;
      uVar8 = 0;
      plVar6 = DAT_140032380;
      while ((longlong **)plVar6 != &DAT_140032380) {
        plVar2 = (longlong *)*plVar6;
        *(longlong *)(puVar15 + uVar9 * 4) = (longlong)puVar14 - (longlong)SmpMappedView;
        *(short *)(puVar15 + uVar9 * 4 + 2) = (short)plVar6[2];
        memcpy(puVar14,(void *)plVar6[3],(ulonglong)*(ushort *)(plVar6 + 2));
        uVar1 = *(ushort *)(plVar6 + 2);
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
        *(undefined2 *)((longlong)puVar14 + (ulonglong)uVar1) = 0;
        puVar14 = (undefined2 *)((longlong)puVar14 + (ulonglong)uVar1) + 1;
        lVar12 = *plVar6;
        puVar16 = DAT_140032388;
        if ((*(longlong **)(lVar12 + 8) != plVar6) ||
           (plVar3 = (longlong *)plVar6[1], (longlong *)*plVar3 != plVar6)) goto LAB_14000abfa;
        *plVar3 = lVar12;
        *(longlong **)(lVar12 + 8) = plVar3;
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,plVar6);
        plVar6 = plVar2;
      }
      *(longlong *)(SmpMappedView + 0x16) = (longlong)puVar15 - (longlong)SmpMappedView;
      SmpMappedView[0x18] = uVar8;
      SmpMappedView[0x19] = 0;
      NtUnmapViewOfSection(0xffffffffffffffff,SmpMappedView);
      local_1c8 = (undefined8 *)CONCAT44(local_1c8._4_4_,9);
      local_1d0 = CONCAT44(local_1d0._4_4_,2);
      local_1d8 = CONCAT44(local_1d8._4_4_,4);
      uVar8 = NtDuplicateObject(0xffffffffffffffff,SmpSharedSection,0xffffffffffffffff,
                                &SmpSharedSection);
      if ((int)uVar8 < 0) {
        uVar11 = 0x2135;
      }
      else {
        local_1c8 = &local_1a8;
        local_1b0 = 2;
        local_1b8 = 0;
        local_1c0 = 2;
        local_1d0 = 0;
        local_1a8 = 0;
        SmpMappedView = (undefined4 *)0x0;
        local_1d8 = 0;
        uVar8 = NtMapViewOfSection(SmpSharedSection,0xffffffffffffffff,&SmpMappedView);
        if (-1 < (int)uVar8) {
          return 0;
        }
        uVar11 = 0x214a;
      }
      uVar9 = (ulonglong)uVar8;
      SmpLogFailure(0x140022b10,uVar11,uVar8);
    }
  }
  return uVar9;
}



===== SmpCreateProtectedPrefixes @ 14000ac10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpCreateProtectedPrefixes(void)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_a28 [32];
  ulonglong local_a08;
  undefined4 local_a00;
  undefined4 local_9f8;
  undefined4 local_9f0;
  undefined4 local_9e8;
  ulonglong local_9e0;
  longlong *local_9d8;
  char local_9c8 [8];
  undefined8 local_9c0;
  undefined8 uStack_9b8;
  longlong *local_9b0;
  undefined8 uStack_9a8;
  longlong *local_9a0;
  ulonglong uStack_998;
  undefined8 local_990;
  undefined8 uStack_988;
  longlong local_980;
  longlong local_978;
  longlong local_970;
  longlong local_968;
  longlong local_960;
  longlong local_958;
  longlong local_950;
  longlong local_948;
  longlong local_940;
  longlong local_938 [2];
  wchar_t *local_928;
  longlong local_920;
  wchar_t *local_918;
  longlong local_910;
  wchar_t *local_908;
  longlong local_900;
  wchar_t *local_8f8;
  longlong local_8f0;
  wchar_t *local_8e8;
  longlong local_8e0;
  wchar_t *local_8d8;
  longlong local_8d0;
  wchar_t *local_8c8;
  longlong local_8c0;
  wchar_t *local_8b8;
  longlong local_8b0;
  wchar_t *local_8a8;
  longlong local_8a0;
  wchar_t *local_898;
  longlong local_890;
  wchar_t *local_888;
  longlong local_880 [5];
  undefined4 local_858;
  undefined2 local_854;
  undefined4 local_850;
  undefined2 local_84c;
  undefined4 local_848;
  undefined2 local_844;
  undefined1 local_838 [1040];
  undefined1 local_428 [1040];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a28;
  local_84c = 0x100;
  local_9a0 = (longlong *)0x0;
  uStack_998 = uStack_998 & 0xffffffff00000000;
  local_880[4] = 0;
  local_850 = 0;
  local_858 = 0;
  bVar1 = true;
  local_848 = 0;
  local_980 = 0;
  local_8a8 = L"\\Device\\NamedPipe\\";
  local_978 = 0;
  local_898 = L"\\Device\\mailslot\\";
  local_928 = L"\\Device\\NamedPipe\\ProtectedPrefix";
  local_918 = L"\\Device\\mailslot\\ProtectedPrefix";
  local_908 = L"\\Device\\NamedPipe\\ProtectedPrefix\\Administrators";
  local_8f8 = L"\\Device\\mailslot\\ProtectedPrefix\\Administrators";
  local_8e8 = L"\\Device\\NamedPipe\\ProtectedPrefix\\LocalService";
  local_8d8 = L"\\Device\\mailslot\\ProtectedPrefix\\LocalService";
  local_8c8 = L"\\Device\\NamedPipe\\ProtectedPrefix\\NetWorkService";
  local_8b8 = L"\\Device\\mailslot\\ProtectedPrefix\\NetWorkService";
  local_888 = L"\\Device\\NamedPipe\\Sessions";
  local_9c0 = 0;
  uStack_9b8 = 0;
  local_854 = 0x500;
  local_9b0 = (longlong *)0x0;
  uStack_9a8 = 0;
  local_844 = 0x1000;
  local_990 = 0;
  uStack_988 = 0;
  local_968 = 0;
  local_880[0] = 0;
  local_880[1] = 0;
  local_960 = 0;
  local_880[2] = 0;
  local_880[3] = 0;
  local_958 = 0;
  local_950 = 0;
  local_970 = 0;
  local_948 = 0;
  local_940 = 0;
  local_938[0] = 0;
  local_9c8[0] = '\x01';
  local_8b0 = 0x260024;
  local_8a0 = 0x240022;
  local_938[1] = 0x440042;
  local_920 = 0x420040;
  local_910 = 0x620060;
  local_900 = 0x60005e;
  local_8f0 = 0x5e005c;
  local_8e0 = 0x5c005a;
  local_8d0 = 0x620060;
  local_8c0 = 0x60005e;
  local_890 = 0x360034;
  iVar2 = RtlCreateSecurityDescriptor(local_938 + 0x17,1);
  if (-1 < iVar2) {
    iVar2 = RtlCreateAcl(local_838,0x408,2);
    if (-1 < iVar2) {
      iVar2 = RtlSetDaclSecurityDescriptor(local_938 + 0x17,1,local_838,0);
      if (-1 < iVar2) {
        local_9d8 = (longlong *)((ulonglong)local_9d8 & 0xffffffff00000000);
        local_9b0 = local_938 + 1;
        local_9e0 = 0;
        local_9e8 = 1;
        local_9f0 = 2;
        local_9f8 = 3;
        local_9a0 = local_938 + 0x17;
        local_a00 = 0x80;
        local_a08 = 0;
        local_9c0 = CONCAT44(local_9c0._4_4_,0x30);
        uStack_9b8 = 0;
        uStack_9a8 = CONCAT44(uStack_9a8._4_4_,0x40);
        uStack_998 = 0;
        iVar2 = NtCreateFile(&PipePrefix1,0x1f01ff,&local_9c0,&local_990);
        if (-1 < iVar2) {
          local_9d8 = (longlong *)((ulonglong)local_9d8 & 0xffffffff00000000);
          local_9b0 = local_938 + 3;
          local_9e0 = 0;
          local_9e8 = 1;
          local_9f0 = 2;
          local_9f8 = 3;
          local_a00 = 0x80;
          local_a08 = 0;
          iVar2 = NtCreateFile(&MailPrefix1,0x1f01ff,&local_9c0,&local_990);
          if (iVar2 == -0x3fffffc6) {
            bVar1 = false;
          }
          else if (iVar2 < 0) goto LAB_14000b74c;
          local_9d8 = &local_968;
          local_9e0 = local_9e0 & 0xffffffff00000000;
          local_9e8 = 0;
          local_9f0 = 0;
          local_9f8 = 0;
          local_a00 = 0;
          local_a08 = local_a08 & 0xffffffff00000000;
          iVar2 = RtlAllocateAndInitializeSid(&local_858,2,0x20,0x220);
          if (-1 < iVar2) {
            iVar2 = RtlAddAccessAllowedAce(local_838,2,2,local_968);
            if (-1 < iVar2) {
              local_9d8 = &local_960;
              local_9e0 = local_9e0 & 0xffffffff00000000;
              local_9e8 = 0;
              local_9f0 = 0;
              local_9f8 = 0;
              local_a00 = 0;
              local_a08 = local_a08 & 0xffffffff00000000;
              iVar2 = RtlAllocateAndInitializeSid(&local_858,1,0x12);
              if (-1 < iVar2) {
                iVar2 = RtlAddAccessAllowedAce(local_838,2,2,local_960);
                if (-1 < iVar2) {
                  local_9d8 = (longlong *)((ulonglong)local_9d8 & 0xffffffff00000000);
                  local_9b0 = local_938 + 5;
                  local_9e0 = 0;
                  local_9e8 = 1;
                  local_9f0 = 2;
                  local_9f8 = 3;
                  local_a00 = 0x80;
                  local_a08 = 0;
                  iVar2 = NtCreateFile(&PipePrefix2,0x1f01ff,&local_9c0,&local_990);
                  if (-1 < iVar2) {
                    if (bVar1) {
                      local_9d8 = (longlong *)((ulonglong)local_9d8 & 0xffffffff00000000);
                      local_9b0 = local_938 + 7;
                      local_9e0 = 0;
                      local_9e8 = 1;
                      local_9f0 = 2;
                      local_9f8 = 3;
                      local_a00 = 0x80;
                      local_a08 = 0;
                      NtCreateFile(&MailPrefix2,0x1f01ff,&local_9c0,&local_990);
                    }
                    iVar2 = RtlCreateAcl(local_838,0x408,2);
                    if (-1 < iVar2) {
                      local_9d8 = &local_958;
                      local_9e0 = local_9e0 & 0xffffffff00000000;
                      local_9e8 = 0;
                      local_9f0 = 0;
                      local_9f8 = 0;
                      local_a00 = 0;
                      local_a08 = local_a08 & 0xffffffff00000000;
                      iVar2 = RtlAllocateAndInitializeSid(&local_858,1,0x13);
                      if (-1 < iVar2) {
                        iVar2 = RtlAddAccessAllowedAce(local_838,2,2,local_958);
                        if (-1 < iVar2) {
                          local_9d8 = (longlong *)((ulonglong)local_9d8 & 0xffffffff00000000);
                          local_9b0 = local_938 + 9;
                          local_9e0 = 0;
                          local_9e8 = 1;
                          local_9f0 = 2;
                          local_9f8 = 3;
                          local_a00 = 0x80;
                          local_a08 = 0;
                          iVar2 = NtCreateFile(&PipePrefix3,0x1f01ff,&local_9c0,&local_990);
                          if (-1 < iVar2) {
                            if (bVar1) {
                              local_9d8 = (longlong *)((ulonglong)local_9d8 & 0xffffffff00000000);
                              local_9b0 = local_938 + 0xb;
                              local_9e0 = 0;
                              local_9e8 = 1;
                              local_9f0 = 2;
                              local_9f8 = 3;
                              local_a00 = 0x80;
                              local_a08 = 0;
                              iVar2 = NtCreateFile(&MailPrefix3,0x1f01ff,&local_9c0,&local_990);
                              if (iVar2 < 0) goto LAB_14000b74c;
                            }
                            iVar2 = RtlCreateAcl(local_838,0x408,2);
                            if (-1 < iVar2) {
                              local_9d8 = &local_950;
                              local_9e0 = local_9e0 & 0xffffffff00000000;
                              local_9e8 = 0;
                              local_9f0 = 0;
                              local_9f8 = 0;
                              local_a00 = 0;
                              local_a08 = local_a08 & 0xffffffff00000000;
                              iVar2 = RtlAllocateAndInitializeSid(&local_858,1,0x14);
                              if (-1 < iVar2) {
                                iVar2 = RtlAddAccessAllowedAce(local_838,2,2,local_950);
                                if (-1 < iVar2) {
                                  local_9d8 = (longlong *)
                                              ((ulonglong)local_9d8 & 0xffffffff00000000);
                                  local_9b0 = local_938 + 0xd;
                                  local_9e0 = 0;
                                  local_9e8 = 1;
                                  local_9f0 = 2;
                                  local_9f8 = 3;
                                  local_a00 = 0x80;
                                  local_a08 = 0;
                                  iVar2 = NtCreateFile(&PipePrefix4,0x1f01ff,&local_9c0,&local_990);
                                  if (-1 < iVar2) {
                                    if (bVar1) {
                                      local_9d8 = (longlong *)
                                                  ((ulonglong)local_9d8 & 0xffffffff00000000);
                                      local_9b0 = local_938 + 0xf;
                                      local_9e0 = 0;
                                      local_9e8 = 1;
                                      local_9f0 = 2;
                                      local_9f8 = 3;
                                      local_a00 = 0x80;
                                      local_a08 = 0;
                                      iVar2 = NtCreateFile(&MailPrefix4,0x1f01ff,&local_9c0,
                                                           &local_990);
                                      if (iVar2 < 0) goto LAB_14000b74c;
                                    }
                                    iVar2 = RtlCreateAcl(local_838,0x408,2);
                                    if (-1 < iVar2) {
                                      local_9d8 = &local_970;
                                      local_9e0 = local_9e0 & 0xffffffff00000000;
                                      local_9e8 = 0;
                                      local_9f0 = 0;
                                      local_9f8 = 0;
                                      local_a00 = 0;
                                      local_a08 = local_a08 & 0xffffffff00000000;
                                      iVar2 = RtlAllocateAndInitializeSid(&local_850,1,0,0);
                                      if (-1 < iVar2) {
                                        iVar2 = RtlAddAccessAllowedAce(local_838,2,2,local_970);
                                        if (-1 < iVar2) {
                                          local_9d8 = local_938;
                                          local_9e0 = local_9e0 & 0xffffffff00000000;
                                          local_9e8 = 0;
                                          local_9f0 = 0;
                                          local_9f8 = 0;
                                          local_a00 = 0;
                                          local_a08 = local_a08 & 0xffffffff00000000;
                                          iVar2 = RtlAllocateAndInitializeSid(&local_858,1,0xc);
                                          if (-1 < iVar2) {
                                            iVar2 = RtlAddAccessAllowedAce
                                                              (local_838,2,2,local_938[0]);
                                            if (-1 < iVar2) {
                                              local_9d8 = &local_940;
                                              local_9e0 = local_9e0 & 0xffffffff00000000;
                                              local_9e8 = 0;
                                              local_9f0 = 0;
                                              local_9f8 = 0;
                                              local_a00 = 0;
                                              local_a08 = local_a08 & 0xffffffff00000000;
                                              iVar2 = RtlAllocateAndInitializeSid(&local_858,1,7);
                                              if (-1 < iVar2) {
                                                iVar2 = RtlAddAccessAllowedAce
                                                                  (local_838,2,2,local_940);
                                                if (-1 < iVar2) {
                                                  iVar2 = RtlCreateAcl(local_428,0x408,2);
                                                  if (-1 < iVar2) {
                                                    local_9d8 = &local_948;
                                                    local_9e0 = local_9e0 & 0xffffffff00000000;
                                                    local_9e8 = 0;
                                                    local_9f0 = 0;
                                                    local_9f8 = 0;
                                                    local_a00 = 0;
                                                    local_a08 = local_a08 & 0xffffffff00000000;
                                                    iVar2 = RtlAllocateAndInitializeSid
                                                                      (&local_848,1,0x1000,0);
                                                    if (-1 < iVar2) {
                                                      local_a00 = 1;
                                                      local_a08 = CONCAT71(local_a08._1_7_,0x11);
                                                      iVar2 = RtlAddMandatoryAce(local_428,2,0,
                                                                                 local_948);
                                                      if (-1 < iVar2) {
                                                        iVar2 = RtlSetSaclSecurityDescriptor
                                                                          (local_938 + 0x17,1,
                                                                           local_428,0);
                                                        if (-1 < iVar2) {
                                                          iVar2 = RtlAdjustPrivilege(8,1,0,local_9c8
                                                                                    );
                                                          if (iVar2 < 0) {
                                                            local_9c8[0] = '\x01';
                                                          }
                                                          local_9b0 = local_938 + 0x11;
                                                          local_a00 = 0x20;
                                                          local_9c0 = CONCAT44(local_9c0._4_4_,0x30)
                                                          ;
                                                          uStack_9b8 = 0;
                                                          uStack_9a8 = CONCAT44(uStack_9a8._4_4_,
                                                                                0x40);
                                                          local_a08 = CONCAT44(local_a08._4_4_,3);
                                                          local_9a0 = (longlong *)0x0;
                                                          uStack_998 = 0;
                                                          iVar2 = NtOpenFile(&local_978,0x11e0000,
                                                                             &local_9c0,&local_990);
                                                          if (-1 < iVar2) {
                                                            iVar2 = NtSetSecurityObject(local_978,
                                                                                        0x1c,
                                                  local_938 + 0x17);
                                                  if (-1 < iVar2) {
                                                    if (bVar1) {
                                                      local_9b0 = local_938 + 0x13;
                                                      local_a00 = 0x20;
                                                      local_a08 = CONCAT44(local_a08._4_4_,3);
                                                      iVar2 = NtOpenFile(&local_980,0x11e0000,
                                                                         &local_9c0,&local_990);
                                                      if (iVar2 < 0) goto LAB_14000b74c;
                                                      NtSetSecurityObject(local_980,0x1c,
                                                                          local_938 + 0x17);
                                                    }
                                                    local_9d8 = (longlong *)
                                                                ((ulonglong)local_9d8 &
                                                                0xffffffff00000000);
                                                    local_9b0 = local_938 + 0x15;
                                                    local_9e0 = 0;
                                                    local_9e8 = 1;
                                                    local_9f0 = 2;
                                                    local_9f8 = 3;
                                                    local_a00 = 0x80;
                                                    local_a08 = 0;
                                                    local_9c0 = CONCAT44(local_9c0._4_4_,0x30);
                                                    uStack_9b8 = 0;
                                                    uStack_9a8 = CONCAT44(uStack_9a8._4_4_,0x40);
                                                    local_9a0 = SmpPrimarySecurityDescriptor;
                                                    uStack_998 = 0;
                                                    iVar2 = NtCreateFile(&SmpPipeSessionsPrefix,
                                                                         0x1f01ff,&local_9c0,
                                                                         &local_990);
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_14000b74c:
  if (local_980 != 0) {
    NtClose();
  }
  if (local_978 != 0) {
    NtClose();
  }
  if (local_9c8[0] == '\0') {
    RtlAdjustPrivilege(8,0,0,local_9c8);
  }
  if (local_970 != 0) {
    RtlFreeSid();
  }
  if (local_968 != 0) {
    RtlFreeSid();
  }
  if (local_960 != 0) {
    RtlFreeSid();
  }
  if (local_958 != 0) {
    RtlFreeSid();
  }
  if (local_950 != 0) {
    RtlFreeSid();
  }
  if (local_948 != 0) {
    RtlFreeSid();
  }
  if (local_940 != 0) {
    RtlFreeSid();
  }
  if (local_938[0] != 0) {
    RtlFreeSid();
  }
  return iVar2;
}



===== SmpCheckSubSysStatus @ 14000b880 =====

bool SmpCheckSubSysStatus(longlong param_1)

{
  if ((*(uint *)(param_1 + 8) & 4) == 0) {
    if ((*(uint *)(param_1 + 8) & 1) == 0) {
      return *(int *)(param_1 + 0x18) != -1;
    }
    if (*(longlong *)(param_1 + 0x30) == 0) {
      return false;
    }
  }
  return true;
}



===== SmpSessionComplete @ 14000b8b0 =====

undefined8 SmpSessionComplete(void)

{
  return 0;
}



===== SmpCreateSecurityDescriptors @ 14000b8c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpCreateSecurityDescriptors(char param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStack_118 [32];
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 local_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  longlong *local_c8;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  undefined4 local_68;
  undefined2 local_64;
  undefined4 local_60;
  undefined2 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined4 local_50;
  undefined2 local_4c;
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  local_54 = 0x100;
  local_a8 = 0;
  local_80 = 0;
  local_78 = 0;
  local_b0 = 0;
  local_70 = 0;
  local_a0 = 0;
  local_90 = 0;
  local_88 = 0;
  local_98 = 0;
  local_58 = 0;
  local_60 = 0;
  local_5c = 0xf00;
  local_68 = 0;
  local_64 = 0x500;
  local_48 = 0;
  local_44 = 0x1000;
  local_50 = 0;
  local_4c = 0x300;
  local_40 = 0;
  local_3c = 0x1300;
  local_b8 = 0;
  if (param_1 == '\0') {
    if ((SmpProtectionMode & 1) == 0) {
      return 0;
    }
    iVar2 = 0;
    if ((SmpProtectionMode & 1) != 0) goto LAB_14000bae0;
  }
  else {
    SmpPrimarySecurityDescriptor = &SmpPrimarySDBody;
    RtlCreateSecurityDescriptor(&SmpPrimarySDBody,1);
    RtlSetDaclSecurityDescriptor(SmpPrimarySecurityDescriptor,1,0,0);
    SmpLiberalSecurityDescriptor = &SmpLiberalSDBody;
    RtlCreateSecurityDescriptor(&SmpLiberalSDBody,1);
    RtlSetDaclSecurityDescriptor(SmpLiberalSecurityDescriptor,1,0,0);
    SmpKnownDllsDirSecurityDescriptor = &SmpKnownDllsDirSDBody;
    RtlCreateSecurityDescriptor(&SmpKnownDllsDirSDBody,1);
    RtlSetDaclSecurityDescriptor(SmpKnownDllsDirSecurityDescriptor,1,0,0);
    SmpKnownDllSecurityDescriptor = &SmpKnownDllSDBody;
    RtlCreateSecurityDescriptor(&SmpKnownDllSDBody,1);
    RtlSetDaclSecurityDescriptor(SmpKnownDllSecurityDescriptor,1,0,0);
    SmpKnownDllsSymLinkSecurityDescriptor = &SmpKnownDllsSymLinkSDBody;
    RtlCreateSecurityDescriptor(&SmpKnownDllsSymLinkSDBody,1);
    RtlSetDaclSecurityDescriptor(SmpKnownDllsSymLinkSecurityDescriptor,1,0,0);
    SmpApiPortSecurityDescriptor = &SmpApiPortSDBody;
    RtlCreateSecurityDescriptor(&SmpApiPortSDBody,1);
    RtlSetDaclSecurityDescriptor(SmpApiPortSecurityDescriptor,1,0,0);
LAB_14000bae0:
    local_c8 = &local_a8;
    local_d0 = 0;
    local_d8 = 0;
    local_e0 = 0;
    local_e8 = 0;
    local_f0 = 0;
    local_f8 = 0;
    iVar2 = RtlAllocateAndInitializeSid(&local_58,1,0,0);
    if (iVar2 < 0) {
      local_a8 = 0;
    }
    else {
      local_c8 = &local_80;
      local_d0 = 0;
      local_d8 = 0;
      local_e0 = 0;
      local_e8 = 0;
      local_f0 = 0;
      local_f8 = 0;
      iVar2 = RtlAllocateAndInitializeSid(&local_60,2,2,1);
      if (iVar2 < 0) {
        local_80 = 0;
      }
      else {
        local_c8 = &local_78;
        local_d0 = 0;
        local_d8 = 0;
        local_e0 = 0;
        local_e8 = 0;
        local_f0 = 0;
        local_f8 = 0;
        iVar2 = RtlAllocateAndInitializeSid(&local_60,2,2,2);
        if (iVar2 < 0) {
          local_78 = 0;
        }
        else {
          local_c8 = &local_b0;
          local_d0 = 0;
          local_d8 = 0;
          local_e0 = 0;
          local_e8 = 0;
          local_f0 = 0;
          local_f8 = 0;
          iVar2 = RtlAllocateAndInitializeSid(&local_68,2,0x20,0x220);
          if (iVar2 < 0) {
            local_b0 = 0;
          }
          else {
            local_c8 = &local_88;
            local_d0 = 0;
            local_d8 = 0;
            local_e0 = 0;
            local_e8 = 0;
            local_f0 = 0;
            local_f8 = 0;
            iVar2 = RtlAllocateAndInitializeSid(&local_50,1,0,0);
            if (iVar2 < 0) {
              local_88 = 0;
            }
            else {
              local_c8 = &local_a0;
              local_d0 = 0;
              local_d8 = 0;
              local_e0 = 0;
              local_e8 = 0;
              local_f0 = 0;
              local_f8 = 0;
              iVar2 = RtlAllocateAndInitializeSid(&local_68,1,0xc);
              if (iVar2 < 0) {
                local_a0 = 0;
              }
              else {
                local_c8 = &local_70;
                local_d0 = 0;
                local_d8 = 0;
                local_e0 = 0;
                local_e8 = 0;
                local_f0 = 0;
                local_f8 = 0;
                iVar2 = RtlAllocateAndInitializeSid(&local_68,1,0x12);
                if (iVar2 < 0) {
                  local_70 = 0;
                }
                else {
                  local_c8 = &local_90;
                  local_d0 = 0;
                  local_d8 = 0;
                  local_e0 = 0;
                  local_e8 = 0;
                  local_f0 = 0;
                  local_f8 = 0;
                  iVar2 = RtlAllocateAndInitializeSid(&local_48,1,0x1000,0);
                  if (iVar2 < 0) {
                    local_90 = 0;
                  }
                  else {
                    local_c8 = &local_98;
                    local_d0 = 0;
                    local_d8 = 0;
                    local_e0 = 0;
                    local_e8 = 0;
                    local_f0 = 0;
                    local_f8 = 0;
                    iVar2 = RtlAllocateAndInitializeSid(&local_40,2,0x200,0x2000);
                    if (iVar2 < 0) {
                      local_98 = 0;
                      goto LAB_14000c793;
                    }
                    if (param_1 != '\0') {
                      iVar2 = RtlLengthSid(local_70);
                      iVar3 = RtlLengthSid(local_b0);
                      iVar2 = iVar3 + 0x20 + iVar2;
                      lVar8 = RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                              iVar2);
                      if (lVar8 == 0) {
                        iVar2 = -0x3fffffe9;
                      }
                      else {
                        RtlCreateAcl(lVar8,iVar2,2);
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_b0);
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_70);
                        iVar2 = RtlSetDaclSecurityDescriptor(SmpApiPortSecurityDescriptor,1,lVar8,0)
                        ;
                      }
                      iVar3 = RtlLengthSid(local_a0);
                      iVar4 = RtlLengthSid(local_b0);
                      iVar5 = RtlLengthSid(local_78);
                      iVar6 = RtlLengthSid(local_80);
                      iVar7 = RtlLengthSid(local_a8);
                      iVar3 = iVar3 + iVar4 + iVar5 + iVar6 + iVar7 + 0x44;
                      lVar8 = RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                              iVar3);
                      if (lVar8 == 0) {
                        iVar2 = -0x3fffffe9;
                      }
                      iVar4 = RtlLengthSid(local_98);
                      lVar9 = RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                              iVar4 + 0x14);
                      if (lVar9 == 0) {
                        iVar2 = -0x3fffffe9;
                      }
                      else if (-1 < iVar2) {
                        RtlCreateAcl(lVar8,iVar3,2);
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_b0);
                        RtlAddAccessAllowedAce(lVar8,2,0xa0000000,local_a8);
                        RtlAddAccessAllowedAce(lVar8,2,0xa0000000,local_80);
                        RtlAddAccessAllowedAce(lVar8,2,0xa0000000,local_a0);
                        RtlAddAccessAllowedAce(lVar8,2,0xa0000000,local_78);
                        RtlCreateAcl(lVar9,iVar4 + 0x14,2);
                        local_f0 = 0x20003;
                        local_f8 = CONCAT31(local_f8._1_3_,0x14);
                        RtlAddProcessTrustLabelAce(lVar9,2,0,local_98);
                        RtlSetDaclSecurityDescriptor(SmpKnownDllsDirSecurityDescriptor,1,lVar8,0);
                        RtlSetSaclSecurityDescriptor(SmpKnownDllsDirSecurityDescriptor,1,lVar9,0);
                        iVar2 = RtlSetDaclSecurityDescriptor
                                          (SmpKnownDllsSymLinkSecurityDescriptor,1,lVar8,0);
                      }
                      iVar3 = RtlLengthSid(local_a0);
                      iVar4 = RtlLengthSid(local_b0);
                      iVar5 = RtlLengthSid(local_78);
                      iVar6 = RtlLengthSid(local_80);
                      iVar7 = RtlLengthSid(local_a8);
                      iVar3 = iVar3 + iVar4 + iVar5 + iVar6 + iVar7 + 0x44;
                      lVar8 = RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                              iVar3);
                      if (lVar8 == 0) {
                        iVar2 = -0x3fffffe9;
                      }
                      iVar4 = RtlLengthSid(local_98);
                      iVar5 = RtlLengthSid(local_90);
                      iVar4 = iVar5 + 0x20 + iVar4;
                      lVar9 = RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                              iVar4);
                      if (lVar9 == 0) {
                        iVar2 = -0x3fffffe9;
                      }
                      else if (-1 < iVar2) {
                        RtlCreateAcl(lVar8,iVar3,2);
                        RtlAddAccessAllowedAce(lVar8,2,0xe0000000,local_a8);
                        RtlAddAccessAllowedAce(lVar8,2,0xe0000000,local_80);
                        RtlAddAccessAllowedAce(lVar8,2,0xe0000000,local_78);
                        RtlAddAccessAllowedAce(lVar8,2,0xe0000000,local_a0);
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_b0);
                        RtlCreateAcl(lVar9,iVar4,2);
                        local_f0 = 1;
                        local_f8._0_1_ = 0x11;
                        RtlAddMandatoryAce(lVar9,2,0,local_90);
                        local_f0 = 0x2000f;
                        if (SmpHostSmss == '\0') {
                          local_f0 = 0x3000f;
                        }
                        local_f8 = CONCAT31(local_f8._1_3_,0x14);
                        RtlAddProcessTrustLabelAce(lVar9,2,0,local_98);
                        RtlSetDaclSecurityDescriptor(SmpKnownDllSecurityDescriptor,1,lVar8,0);
                        iVar2 = RtlSetSaclSecurityDescriptor
                                          (SmpKnownDllSecurityDescriptor,1,lVar9,0);
                      }
                    }
                    if ((SmpProtectionMode & 1) != 0) {
                      iVar3 = RtlLengthSid(local_a0);
                      iVar4 = RtlLengthSid(local_b0);
                      iVar5 = RtlLengthSid(local_a8);
                      iVar6 = RtlLengthSid(local_88);
                      iVar3 = (iVar3 + iVar4 + iVar5) * 2 + iVar6 + 0x5c;
                      lVar8 = RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                              iVar3);
                      if (lVar8 == 0) {
                        iVar2 = -0x3fffffe9;
                      }
                      else if (-1 < iVar2) {
                        RtlCreateAcl(lVar8,iVar3,2);
                        RtlAddAccessAllowedAce(lVar8,2,0xa0000000,local_a8);
                        RtlAddAccessAllowedAce(lVar8,2,0xa0000000,local_a0);
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_b0);
                        RtlAddAccessAllowedAce(lVar8,2,0xa0000000,local_a8);
                        RtlGetAce(lVar8,3,&local_b8);
                        *(undefined1 *)(local_b8 + 1) = 0xb;
                        RtlAddAccessAllowedAce(lVar8,2,0xa0000000,local_a0);
                        RtlGetAce(lVar8,4,&local_b8);
                        *(undefined1 *)(local_b8 + 1) = 0xb;
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_b0);
                        RtlGetAce(lVar8,5,&local_b8);
                        *(undefined1 *)(local_b8 + 1) = 0xb;
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_88);
                        RtlGetAce(lVar8,6,&local_b8);
                        puVar1 = SmpPrimarySecurityDescriptor;
                        *(undefined1 *)(local_b8 + 1) = 0xb;
                        iVar2 = RtlSetDaclSecurityDescriptor(puVar1,1,lVar8,0);
                      }
                      iVar3 = RtlLengthSid(local_a0);
                      iVar4 = RtlLengthSid(local_b0);
                      iVar5 = RtlLengthSid(local_a8);
                      iVar6 = RtlLengthSid(local_88);
                      iVar3 = (iVar3 + iVar4 + iVar5) * 2 + iVar6 + 0x5c;
                      lVar8 = RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                              iVar3);
                      if (lVar8 == 0) {
                        iVar2 = -0x3fffffe9;
                      }
                      iVar4 = RtlLengthSid(local_90);
                      lVar9 = RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                                              iVar4 + 0x14);
                      if (lVar9 == 0) {
                        iVar2 = -0x3fffffe9;
                      }
                      else if (-1 < iVar2) {
                        RtlCreateAcl(lVar8,iVar3,2);
                        RtlAddAccessAllowedAce(lVar8,2,0xe0000000,local_a8);
                        RtlAddAccessAllowedAce(lVar8,2,0xe0000000,local_a0);
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_b0);
                        RtlAddAccessAllowedAce(lVar8,2,0xe0000000,local_a8);
                        RtlGetAce(lVar8,3,&local_b8);
                        *(undefined1 *)(local_b8 + 1) = 0xb;
                        RtlAddAccessAllowedAce(lVar8,2,0xe0000000,local_a0);
                        RtlGetAce(lVar8,4,&local_b8);
                        *(undefined1 *)(local_b8 + 1) = 0xb;
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_b0);
                        RtlGetAce(lVar8,5,&local_b8);
                        *(undefined1 *)(local_b8 + 1) = 0xb;
                        RtlAddAccessAllowedAce(lVar8,2,0x10000000,local_88);
                        RtlGetAce(lVar8,6,&local_b8);
                        *(undefined1 *)(local_b8 + 1) = 0xb;
                        RtlCreateAcl(lVar9,iVar4 + 0x14,2);
                        local_f0 = 1;
                        local_f8 = CONCAT31(local_f8._1_3_,0x11);
                        RtlAddMandatoryAce(lVar9,2,0,local_90);
                        RtlSetDaclSecurityDescriptor(SmpLiberalSecurityDescriptor,1,lVar8,0);
                        iVar2 = RtlSetSaclSecurityDescriptor(SmpLiberalSecurityDescriptor,1,lVar9,0)
                        ;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_98 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_98);
  }
LAB_14000c793:
  if (local_90 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_90);
  }
  if (local_88 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_88);
  }
  if (local_b0 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_b0);
  }
  if (local_80 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_80);
  }
  if (local_78 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_78);
  }
  if (local_a8 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_a8);
  }
  if (local_70 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_70);
  }
  if (local_a0 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_a0);
  }
  return iVar2;
}



===== RtlStringCbPrintfExW @ 14000c8f4 =====

int RtlStringCbPrintfExW
              (wchar_t *param_1,ulonglong param_2,size_t *param_3,longlong *param_4,uint param_5,
              wchar_t *param_6,char param_7)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  size_t *psVar4;
  wchar_t *pwVar5;
  wchar_t *local_58;
  ulonglong local_50 [2];
  
  uVar3 = param_2 >> 1;
  iVar2 = 0;
  if ((param_5 & 0x100) == 0) {
    iVar2 = 0;
    if (0x7ffffffe < uVar3 - 1) {
      iVar2 = -0x3ffffff3;
    }
  }
  else if (((param_1 == (wchar_t *)0x0) && (uVar3 != 0)) || (0x7fffffff < uVar3)) {
    iVar2 = -0x3ffffff3;
  }
  if (iVar2 < 0) {
    if (uVar3 == 0) {
      return iVar2;
    }
    *param_1 = L'\0';
    return iVar2;
  }
  if (((param_5 & 0x100) != 0) && (param_6 == (wchar_t *)0x0)) {
    param_6 = L"";
  }
  iVar2 = 0;
  psVar4 = param_3;
  local_50[0] = uVar3;
  if ((param_5 & 0xffffe000) == 0) {
    if (uVar3 == 0) {
      pwVar5 = param_1;
      if (*param_6 == L'\0') goto LAB_14000c9e4;
      iVar2 = (-(uint)(param_1 != (wchar_t *)0x0) & 0xbffffff8) + 0xc000000d;
      local_58 = param_1;
    }
    else {
      local_50[0] = 0;
      psVar4 = local_50;
      local_58 = (wchar_t *)0x0;
      iVar2 = RtlStringVPrintfWorkerW(param_1,uVar3,psVar4,param_6,&param_7);
      uVar3 = uVar3 - local_50[0];
      pwVar5 = param_1 + local_50[0];
      local_58 = pwVar5;
      local_50[0] = uVar3;
      if (-1 < iVar2) {
        if (((param_5 >> 9 & 1) != 0) &&
           (uVar1 = (ulonglong)((uint)param_2 & 1) + uVar3 * 2, 2 < uVar1)) {
          memset(pwVar5 + 1,param_5 & 0xff,uVar1 - 2);
        }
        goto LAB_14000c9e4;
      }
    }
  }
  else {
    iVar2 = -0x3ffffff3;
    local_58 = param_1;
    if (uVar3 != 0) {
      *param_1 = L'\0';
      local_58 = param_1;
    }
  }
  if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
    RtlStringExHandleOtherFlagsW(param_1,param_2,psVar4,&local_58,local_50,param_5);
  }
  uVar3 = local_50[0];
  pwVar5 = local_58;
  if (((iVar2 + 0x80000000U & 0x80000000) == 0) && (iVar2 != -0x7ffffffb)) {
    return iVar2;
  }
LAB_14000c9e4:
  if (param_3 != (size_t *)0x0) {
    *param_3 = (size_t)pwVar5;
  }
  if (param_4 != (longlong *)0x0) {
    *param_4 = (ulonglong)((uint)param_2 & 1) + uVar3 * 2;
  }
  return iVar2;
}



===== SmpGetCoreProcessIds @ 14000cac0 =====

undefined8 SmpGetCoreProcessIds(ulonglong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int *piVar3;
  uint uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  
  uVar6 = 0;
  lVar2 = SmpCoreProcessIds + (param_1 & 0xffffffff) * 0x28;
  lVar1 = lVar2 + 8;
  RtlAcquireSRWLockShared(lVar1);
  while (*(int *)(lVar2 + 4) == 0) {
    RtlSleepConditionVariableSRW(lVar2 + 0x10,lVar1,0,1);
  }
  if (*(longlong *)(lVar2 + 0x20) == 0) {
    uVar6 = 0xc0000001;
  }
  else {
    uVar4 = 0;
    plVar5 = param_2;
    do {
      piVar3 = *(int **)((lVar2 - (longlong)param_2) + 0x18 + (longlong)plVar5);
      *plVar5 = (longlong)piVar3;
      if ((uVar4 == 0) && (*param_2 != 0)) {
        LOCK();
        *piVar3 = *piVar3 + 1;
        UNLOCK();
      }
      uVar4 = uVar4 + 1;
      plVar5 = plVar5 + 1;
    } while (uVar4 < 2);
  }
  RtlReleaseSRWLockShared(lVar1);
  return uVar6;
}



===== InitializeWow64OnBoot @ 14000cb90 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int InitializeWow64OnBoot(void)

{
  uint *puVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint *puVar7;
  undefined8 uStack_60;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  uint *local_30;
  uint local_28 [2];
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_28;
  local_20 = 0;
  local_28[0] = 0;
  local_38[0] = 0;
  uStack_60 = 0x14000cbe2;
  local_30 = local_28;
  iVar3 = NtQuerySystemInformationEx(0xe6,&local_20,8);
  uVar5 = local_28[0];
  puVar6 = auStack_58;
  if (iVar3 == -0x3fffffdd) {
    uVar4 = (ulonglong)local_28[0] + 0xf;
    if (uVar4 <= local_28[0]) {
      uVar4 = 0xffffffffffffff0;
    }
    uStack_60 = 0x14000cc16;
    lVar2 = -(uVar4 & 0xfffffffffffffff0);
    *(uint **)((longlong)local_38 + lVar2 + 8) = local_28;
    puVar1 = (uint *)((longlong)local_28 + lVar2);
    *(uint *)((longlong)local_38 + lVar2) = uVar5;
    *(undefined8 *)(auStack_58 + lVar2 + -8) = 0x14000cc41;
    iVar3 = NtQuerySystemInformationEx(0xe6,&local_20,8,puVar1);
    puVar6 = auStack_58 + lVar2;
    if (-1 < iVar3) {
      uVar5 = *puVar1;
      uVar4 = 0;
      puVar6 = auStack_58 + lVar2;
      if ((short)uVar5 != 0) {
        puVar7 = puVar1;
        do {
          if ((uVar5 & 0x160000) == 0x120000) {
            uVar5 = *puVar7;
            *(undefined8 *)(auStack_58 + lVar2 + -8) = 0x14000cc6f;
            iVar3 = CreateRegistryLinksForMachine((short)uVar5);
            puVar6 = auStack_58 + lVar2;
            if (iVar3 < 0) break;
          }
          uVar4 = (ulonglong)((int)uVar4 + 1);
          puVar7 = puVar1 + uVar4;
          uVar5 = *puVar7;
          puVar6 = auStack_58 + lVar2;
        } while ((short)uVar5 != 0);
      }
    }
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000cc91;
  return iVar3;
}



===== CreateRegistryLinksForMachine @ 14000cca8 =====

int CreateRegistryLinksForMachine(short param_1)

{
  short sVar1;
  ushort *puVar2;
  ulonglong uVar3;
  ushort uVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  bool bVar10;
  longlong local_48;
  longlong lStack_40;
  longlong local_38;
  longlong lStack_30;
  
  puVar2 = (ushort *)0x0;
  bVar10 = param_1 != 0x14c;
  if (bVar10) {
    puVar2 = (ushort *)Wow64SelectWowNodePathInternal(param_1);
  }
  iVar7 = 0;
  uVar5 = 0;
  while( true ) {
    if (0x4d < uVar5) {
      return iVar7;
    }
    uVar3 = (ulonglong)uVar5;
    local_48 = 0;
    lStack_40 = 0;
    local_38 = 0;
    lStack_30 = 0;
    plVar9 = (longlong *)(&DAT_140021070 + uVar3 * 0x20);
    plVar8 = (longlong *)(&RegistrySymbolicLinks + uVar3 * 0x20);
    if (bVar10) {
      iVar7 = -(0x18 - (uint)*puVar2);
      if (iVar7 < 0) {
        iVar7 = 0x18 - (uint)*puVar2;
      }
      sVar1 = (short)iVar7 * 2;
      uVar6 = sVar1 + (&DAT_140021072)[uVar3 * 0x10];
      uVar4 = sVar1 + (&DAT_140021062)[uVar3 * 0x10];
      lStack_40 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,uVar4)
      ;
      local_48 = (ulonglong)uVar4 << 0x10;
      lStack_30 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,uVar6)
      ;
      local_38 = (ulonglong)uVar6 << 0x10;
      if (lStack_40 == 0) {
        return -0x3fffffe9;
      }
      if (lStack_30 == 0) {
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lStack_40);
        return -0x3fffffe9;
      }
      RtlCopyUnicodeString(&local_48,plVar8);
      RtlCopyUnicodeString(&local_38,plVar9);
      PathReplaceGreedy((ushort *)&Wowx86NodeString,puVar2,(ushort *)&local_48);
      PathReplaceGreedy((ushort *)&Wowx86NodeString,puVar2,(ushort *)&local_38);
      plVar8 = &local_48;
      plVar9 = &local_38;
    }
    iVar7 = CreateMergeLink(plVar8,(undefined *)plVar9);
    if (bVar10) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,plVar8[1]);
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,plVar9[1]);
    }
    if (iVar7 < 0) break;
    uVar5 = uVar5 + 1;
  }
  return iVar7;
}



===== SmpMakeSystemManagedPagingFileDescriptor @ 14000ceb0 =====

void SmpMakeSystemManagedPagingFileDescriptor(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  SmpInitializeManagedPagefileSupport();
  uVar2 = SmpMemorySize * 3;
  if (uVar2 < 0x100000000) {
    uVar2 = 0x100000000;
  }
  uVar4 = SmpMemorySize;
  uVar1 = SmpRoundDownToPowerOf2(uVar2 >> 4);
  uVar3 = 0x4000000;
  uVar5 = 0x4000000;
  if (0x4000000 < uVar1) {
    uVar5 = uVar1;
  }
  uVar5 = (uVar2 - 1) + uVar5 & ~(uVar5 - 1);
  uVar2 = SmpDesiredPfSizeBasedOnRAM;
  if (SmpNumberOfManagedPagefilesCreated == 0) {
    uVar2 = SmpDesiredPfSizeBasedOnHistory;
  }
  if (uVar2 < 0x4000000) {
    uVar2 = 0x4000000;
  }
  uVar4 = uVar4 >> 4;
  uVar1 = 0x400000000;
  if (uVar4 < 0x400000000) {
    uVar1 = uVar4;
  }
  if ((uVar2 < uVar1) && (uVar2 = 0x400000000, uVar4 < 0x400000000)) {
    uVar2 = uVar4;
  }
  uVar1 = SmpRoundDownToPowerOf2(uVar2 >> 4);
  uVar4 = uVar3;
  if (uVar3 < uVar1) {
    uVar4 = uVar1;
  }
  uVar4 = (uVar2 - 1) + uVar4 & ~(uVar4 - 1);
  uVar2 = uVar5;
  if (uVar4 <= uVar5) {
    uVar2 = uVar4;
  }
  if ((SmpNumberOfManagedPagefilesCreated == 0) && (uVar2 < SmpDesiredPfSizeForApps)) {
    uVar4 = SmpDesiredPfSizeForApps;
    uVar1 = SmpRoundDownToPowerOf2(SmpDesiredPfSizeForApps >> 4);
    uVar2 = uVar3;
    if (uVar3 < uVar1) {
      uVar2 = uVar1;
    }
    uVar2 = (uVar4 - 1) + uVar2 & ~(uVar2 - 1);
    *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 8;
  }
  uVar4 = uVar2;
  if ((SmpNumberOfPagefilesCreated == 0) && (uVar2 < SmpDesiredPfSizeForCrashDump)) {
    uVar2 = SmpDesiredPfSizeForCrashDump;
    uVar1 = SmpRoundDownToPowerOf2(SmpDesiredPfSizeForCrashDump >> 4);
    if (uVar3 < uVar1) {
      uVar3 = uVar1;
    }
    uVar2 = (uVar2 - 1) + uVar3 & ~(uVar3 - 1);
    if (SmpDumpType != 1) {
      uVar4 = uVar2;
    }
    if (SmpTryHardForCrashDump == '\x01') {
      *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 8;
    }
  }
  *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 2;
  *(ulonglong *)(param_1 + 0x30) = uVar4;
  *(ulonglong *)(param_1 + 0x38) = uVar2;
  *(ulonglong *)(param_1 + 0x40) = uVar5;
  return;
}



===== SmpRoundDownToPowerOf2 @ 14000d030 =====

longlong SmpRoundDownToPowerOf2(ulonglong param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    param_1 = param_1 >> 1;
    if (param_1 == 0) break;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x40);
  return 1L << ((byte)uVar1 & 0x3f);
}



===== SmpPagefileUsageSampleCompare @ 14000d050 =====

int SmpPagefileUsageSampleCompare(uint *param_1,uint *param_2)

{
  if (*param_2 < *param_1) {
    return 1;
  }
  return -(uint)(*param_1 < *param_2);
}



===== SmpDeallocSavedRegistryEntry @ 14000d068 =====

void SmpDeallocSavedRegistryEntry(longlong param_1)

{
  if (param_1 != 0) {
    RtlFreeUnicodeString(param_1 + 0x20);
    if (*(longlong *)(param_1 + 0x30) != 0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0);
    }
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,param_1);
  }
  return;
}



===== SmpProcessPagefileDescriptor @ 14000d0d4 =====

void SmpProcessPagefileDescriptor(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  if ((*(byte *)(param_1 + 0x5c) & 2) != 0) {
    SmpMakeSystemManagedPagingFileDescriptor(param_1);
  }
  lVar2 = param_1;
  SmpValidatePagingFileSizes(param_1);
  if (((*(byte *)(param_1 + 0x5c) & 4) == 0) ||
     (iVar1 = SmpCreatePagefileFromDescriptor(lVar2,0), iVar1 < 0)) {
    SmpCreatePagefileFromDescriptor(param_1,1);
    return;
  }
  return;
}



===== SmpEnableSwapOnPagingFiles @ 14000d11c =====

void SmpEnableSwapOnPagingFiles(undefined8 *param_1,short param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  int iVar3;
  
  for (puVar2 = (undefined8 *)*param_1; puVar2 != param_1; puVar2 = (undefined8 *)*puVar2) {
    if (((*(byte *)((longlong)puVar2 + 0x5c) & 1) != 0) &&
       ((param_2 == 0x3f || (*(short *)(puVar2[3] + 8) == param_2)))) {
      uVar1 = *(uint *)(puVar2 + 0xb);
      iVar3 = SmpCreatePagingFile((longlong)(puVar2 + 2),puVar2[9],puVar2[10]);
      if (-1 < iVar3) {
        *(uint *)(puVar2 + 0xb) = uVar1 | 0x2000000;
      }
    }
  }
  return;
}



===== SmpTranslateSystemPartitionInformation @ 14000d19c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpTranslateSystemPartitionInformation(void)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined1 auStack_768 [32];
  undefined4 *local_748;
  undefined4 *local_740;
  undefined8 local_738;
  undefined8 local_728;
  undefined4 local_720;
  undefined4 local_71c;
  undefined8 local_718;
  undefined8 local_710;
  undefined4 *local_708;
  undefined8 local_700;
  undefined8 local_6f8;
  ulonglong *local_6f0;
  undefined8 local_6e8;
  undefined8 local_6e0;
  undefined8 uStack_6d8;
  ulonglong local_6d0;
  wchar_t *local_6c8;
  undefined8 local_6c0;
  wchar_t *local_6b8;
  undefined8 local_6b0;
  wchar_t *local_6a8;
  ulonglong local_6a0 [3];
  wchar_t *local_688;
  ulonglong local_680;
  wchar_t *local_678;
  short local_668 [4];
  undefined4 *local_660;
  undefined1 local_658 [16];
  undefined4 local_648 [136];
  undefined4 local_428;
  undefined4 local_424;
  undefined1 local_228 [12];
  undefined1 local_21c [516];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_768;
  local_700 = 0x30;
  local_6e8 = 0x40;
  local_728 = 0;
  local_6c8 = L"\\Registry\\Machine\\System\\Setup";
  local_71c = 0;
  local_6b8 = L"SystemPartition";
  local_720 = 0;
  local_6a8 = L"SymbolicLink";
  local_718 = 0;
  local_688 = L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Setup";
  local_678 = L"BootDir";
  local_6f0 = &local_6d0;
  local_6a0[0] = 0;
  local_6a0[1] = 0;
  local_710 = 0;
  local_6d0 = 0x3e003c;
  local_6c0 = 0x20001e;
  local_6b0 = 0x1a0018;
  local_6a0[2] = 0x840082;
  local_680 = 0x10000e;
  local_6f8 = 0;
  local_6e0 = 0;
  uStack_6d8 = 0;
  iVar2 = NtOpenKey(&local_728,0x20019,&local_700);
  if (iVar2 < 0) {
    uVar4 = 0x2e91;
  }
  else {
    local_740 = &local_71c;
    local_748 = (undefined4 *)CONCAT44(local_748._4_4_,0x210);
    iVar2 = NtQueryValueKey(local_728,&local_6c0,2,local_228);
    NtClose(local_728);
    if (iVar2 < 0) {
      uVar4 = 0x2ea3;
    }
    else {
      RtlInitUnicodeString(local_6a0,local_21c);
      local_708 = &local_428;
      local_740 = &local_720;
      local_738 = 0;
      local_748 = (undefined4 *)CONCAT71(local_748._1_7_,1);
      iVar2 = NtQueryDirectoryObject(SmpDosDevicesObjectDirectory,local_668,0x23a,1);
      while (-1 < iVar2) {
        cVar1 = RtlEqualUnicodeString(local_658,&local_6b0,1);
        if (((cVar1 != '\0') && (local_668[0] == 4)) &&
           (*(short *)((longlong)local_660 + 2) == 0x3a)) {
          local_6f8 = SmpDosDevicesObjectDirectory;
          local_700 = CONCAT44(local_700._4_4_,0x30);
          local_6e8 = CONCAT44(local_6e8._4_4_,0x40);
          local_6e0 = 0;
          uStack_6d8 = 0;
          local_6f0 = (ulonglong *)local_668;
          iVar2 = NtOpenSymbolicLinkObject(&local_718,0xf0001,&local_700);
          if (-1 < iVar2) {
            local_710 = CONCAT44(local_710._4_4_,0x2000000);
            iVar2 = NtQuerySymbolicLinkObject(local_718,&local_710,0);
            NtClose(local_718);
            if ((-1 < iVar2) &&
               ((cVar1 = RtlEqualUnicodeString(local_6a0,&local_710,1), cVar1 != '\0' ||
                ((cVar1 = RtlPrefixUnicodeString(local_6a0,&local_710,1), cVar1 != '\0' &&
                 (*(short *)((longlong)local_708 + (local_6a0[0] >> 1 & 0x7fff) * 2) == 0x5c))))))
            goto LAB_14000d4dc;
          }
        }
        local_740 = &local_720;
        local_738 = 0;
        local_748 = (undefined4 *)((ulonglong)local_748 & 0xffffffffffffff00);
        iVar2 = NtQueryDirectoryObject(SmpDosDevicesObjectDirectory,local_668,0x23a,1);
      }
      if (iVar2 == -0x7fffffe6) {
        lVar3 = RtlGetNtSystemRoot();
        local_660 = local_648;
        lVar5 = 0;
        do {
          *(undefined2 *)(lVar5 + (longlong)local_660) = *(undefined2 *)(lVar5 + lVar3);
          lVar5 = lVar5 + 2;
        } while (lVar5 < 4);
LAB_14000d4dc:
        local_6f0 = local_6a0 + 2;
        local_700 = CONCAT44(local_700._4_4_,0x30);
        local_6f8 = 0;
        local_6e8 = CONCAT44(local_6e8._4_4_,0x40);
        local_6e0 = 0;
        uStack_6d8 = 0;
        iVar2 = NtOpenKey(&local_728,0xf003f,&local_700);
        if (-1 < iVar2) {
          local_740 = (undefined4 *)CONCAT44(local_740._4_4_,8);
          local_428 = *local_660;
          local_748 = &local_428;
          local_424 = 0x5c;
          iVar2 = NtSetValueKey(local_728,local_6a0 + 4,0,1);
          if (iVar2 < 0) {
            SmpLogFailure(0x140028308,0x2f34,iVar2);
          }
          NtClose(local_728);
          return;
        }
        uVar4 = 0x2f1f;
      }
      else {
        uVar4 = 0x2f0a;
      }
    }
  }
  SmpLogFailure(0x140028308,uVar4,iVar2);
  return;
}



===== SmpCompleteSubSysStatusChange @ 14000d5e0 =====

void SmpCompleteSubSysStatusChange(longlong param_1)

{
  int *piVar1;
  
  if (*(longlong *)(param_1 + 0x10) != 0) {
    LOCK();
    piVar1 = *(int **)(param_1 + 0x10);
    *(undefined8 *)(param_1 + 0x10) = 0;
    UNLOCK();
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00014000d608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        NtSetEvent(*(undefined8 *)(piVar1 + 2),0);
        return;
      }
      SmpDisposeSubSysSynch((undefined8 *)piVar1);
    }
  }
  return;
}



===== SmpNtSerializeBoot @ 14000d628 =====

undefined4 SmpNtSerializeBoot(void)

{
  undefined4 uVar1;
  
  SmpEventWrite(&SmssEvt_SerializeBoot_Start);
  uVar1 = NtSerializeBoot();
  SmpEventWriteULONG(&SmssEvt_SerializeBoot_Stop,uVar1);
  return uVar1;
}



===== SmpEventWrite @ 14000d668 =====

void SmpEventWrite(undefined8 param_1)

{
  char cVar1;
  
  if (SmpTraceHandle != 0) {
    cVar1 = EtwEventEnabled(SmpTraceHandle,param_1);
    if (cVar1 != '\0') {
      EtwEventWrite(SmpTraceHandle,param_1,0,0);
    }
  }
  return;
}



===== SmpFreeSavedRegistryEntry @ 14000d6bc =====

void SmpFreeSavedRegistryEntry(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    SmpDeallocSavedRegistryEntry((longlong)param_1);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== SmpBuildFilesStringFromList @ 14000d6e8 =====

undefined8 SmpBuildFilesStringFromList(longlong *param_1,ushort *param_2)

{
  ushort *puVar1;
  ushort uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  uint uVar6;
  
  plVar5 = (longlong *)*param_1;
  uVar6 = 2;
  if (plVar5 != param_1) {
    do {
      puVar1 = (ushort *)(plVar5 + 2);
      plVar5 = (longlong *)*plVar5;
      uVar6 = uVar6 + *puVar1 + 2;
    } while (plVar5 != param_1);
    if (0xffff < uVar6) {
      return 0xc0000001;
    }
  }
  param_2[1] = (ushort)uVar6;
  lVar3 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0);
  *(longlong *)(param_2 + 4) = lVar3;
  if (lVar3 == 0) {
    SmpLogFailure(0x140028c00,0x1101,0xc0000017);
    uVar4 = 0xc0000017;
  }
  else {
    *param_2 = 0;
    uVar2 = 0;
    for (plVar5 = (longlong *)*param_1; plVar5 != param_1; plVar5 = (longlong *)*plVar5) {
      RtlAppendUnicodeStringToString(param_2,plVar5 + 2);
      uVar2 = *param_2 + 2;
      *param_2 = uVar2;
    }
    *(undefined2 *)(*(longlong *)(param_2 + 4) + (ulonglong)(uVar2 >> 1) * 2) = 0;
    *param_2 = *param_2 + 2;
    uVar4 = 0;
  }
  return uVar4;
}



===== SmpLogFailure @ 14000d7f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpLogFailure(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_118 [32];
  char local_f8 [224];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  memset(local_f8,0,0xe0);
  SmpInternalLogFailure(param_1,param_2,param_3,local_f8);
  return;
}



===== SmpEventWriteString2 @ 14000d86c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpEventWriteString2(undefined8 param_1,ushort *param_2,ushort *param_3)

{
  char cVar1;
  undefined1 auStack_88 [32];
  ushort local_68 [2];
  ushort local_64 [6];
  ushort *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ushort *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  uint local_30;
  undefined4 local_2c;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  if (SmpTraceHandle != 0) {
    cVar1 = EtwEventEnabled(SmpTraceHandle,&SmssEvt_FileRename_Info);
    if (cVar1 != '\0') {
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_68[0] = *param_2 >> 1;
      local_64[0] = *param_3 >> 1;
      local_58 = local_68;
      local_48 = local_64;
      local_38 = *(undefined8 *)(param_2 + 4);
      local_28 = *(undefined8 *)(param_3 + 4);
      local_50 = 2;
      local_40 = 2;
      local_30 = (uint)*param_2;
      local_20 = (uint)*param_3;
      EtwEventWrite(SmpTraceHandle,&SmssEvt_FileRename_Info,4,&local_58);
    }
  }
  return;
}



===== SmpValidatePagingFileSizes @ 14000d970 =====

undefined8 SmpValidatePagingFileSizes(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar1 = *(ulonglong *)(param_1 + 0x38);
  uVar2 = uVar1;
  if (uVar1 <= *(ulonglong *)(param_1 + 0x40)) {
    uVar2 = *(ulonglong *)(param_1 + 0x40);
  }
  uVar3 = uVar1;
  if (0xffffffff000 < uVar1) {
    uVar3 = 0xffffffff000;
  }
  if (uVar2 < 0xffffffff001) {
    if (uVar1 < 0xffffffff001) goto LAB_14000d9a6;
  }
  else {
    uVar2 = 0xffffffff000;
  }
  uVar1 = uVar3;
LAB_14000d9a6:
  *(ulonglong *)(param_1 + 0x38) = uVar1;
  *(ulonglong *)(param_1 + 0x40) = uVar2;
  if (uVar1 < *(ulonglong *)(param_1 + 0x30)) {
    *(ulonglong *)(param_1 + 0x30) = uVar1;
  }
  return 0;
}



===== SmpCheckMemoryCoolingCompatibility @ 14000d9c4 =====

void SmpCheckMemoryCoolingCompatibility(void)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int local_res8;
  
  lVar2 = 0;
  local_res8 = 0;
  iVar1 = 0;
  iVar4 = SmpMaximumNodeCount * 0x2000 + 0x30;
  for (uVar3 = 0; uVar3 < 2; uVar3 = uVar3 + 1) {
    lVar2 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,iVar4);
    if (lVar2 == 0) {
      return;
    }
    iVar1 = NtQuerySystemInformation(0x8a);
    if (iVar1 < 0) {
      if (iVar1 != -0x3fffffdd) goto LAB_14000daa7;
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
      lVar2 = 0;
      iVar4 = local_res8;
    }
  }
  if ((-1 < iVar1) && (1 < *(uint *)(lVar2 + 0xc))) {
    NtUpdateWnfStateData(&WNF_SMSS_MEMORY_COOLING_COMPATIBLE,0,0,0,0,0,0);
  }
  if (lVar2 != 0) {
LAB_14000daa7:
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar2);
  }
  return;
}



===== SmpExpandKnownDllsPath @ 14000dae4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SmpExpandKnownDllsPath(short *param_1,ushort *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  ushort uVar3;
  
  uVar3 = *param_1 + 2 + _SmpSystemRoot;
  lVar1 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,uVar3);
  uVar2 = 0;
  *(longlong *)(param_2 + 4) = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *param_2 = 0;
    param_2[1] = uVar3;
    RtlCopyUnicodeString(param_2,&SmpSystemRoot);
    RtlAppendUnicodeStringToString(param_2,param_1);
    *(undefined2 *)(*(longlong *)(param_2 + 4) + (ulonglong)(*param_2 >> 1) * 2) = 0;
  }
  return uVar2;
}



===== SmpSortDllList @ 14000dba0 =====

int SmpSortDllList(undefined8 param_1,int *param_2,int *param_3)

{
  return *param_2 - *param_3;
}



===== SmpUpdatePagingFileSizes @ 14000dbb0 =====

bool SmpUpdatePagingFileSizes(ulonglong *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  bool bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar1 = *param_1;
  uVar3 = *param_2;
  uVar4 = uVar1;
  if (0xffffffff000 < uVar1) {
    uVar4 = 0xffffffff000;
  }
  bVar2 = 0xffffffff000 < uVar1;
  if (uVar3 < 0xffffffff001) {
    if (*param_1 < 0xffffffff001) {
      return bVar2;
    }
  }
  else {
    bVar2 = true;
    uVar3 = 0xffffffff000;
  }
  *param_1 = uVar4;
  *param_2 = uVar3;
  return bVar2;
}



===== SmpIsVhdVolume @ 14000dbec =====

bool SmpIsVhdVolume(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  lVar2 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8,0x208);
  bVar3 = false;
  if (lVar2 != 0) {
    iVar1 = NtDeviceIoControlFile(param_1,0,0,0,&local_18,0x2d5928,0,0,lVar2,0x208);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar2);
    if (iVar1 == 0) {
      bVar3 = true;
    }
    else {
      bVar3 = iVar1 == -0x3fffffdd;
    }
  }
  return bVar3;
}



===== SmpInitializePendingRename @ 14000dcc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpInitializePendingRename(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined4 local_b0;
  undefined8 *local_a8;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 *local_70;
  undefined8 uStack_68;
  undefined8 *local_60;
  ulonglong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_f8;
  local_14 = 0x500;
  local_88 = 0;
  local_98 = 0;
  local_60 = (undefined8 *)0x0;
  local_58 = local_58 & 0xffffffff00000000;
  local_20 = 0;
  local_a8 = &local_90;
  local_90 = 0;
  local_b0 = 0;
  local_b8 = 0;
  local_c0 = 0;
  local_c8 = 0;
  local_d0 = 0;
  local_d8 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_18 = 0;
  local_70 = (undefined8 *)0x0;
  uStack_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  iVar1 = RtlAllocateAndInitializeSid(&local_18,2,0x20,0x220);
  if (iVar1 < 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    local_a8 = &local_98;
    local_b0 = 0;
    local_b8 = 0;
    local_c0 = 0;
    local_c8 = 0;
    local_d0 = 0;
    local_d8 = 0;
    iVar1 = RtlAllocateAndInitializeSid(&local_18,1,0x12);
    if (-1 < iVar1) {
      iVar2 = RtlLengthSid(local_90);
      iVar3 = RtlLengthSid(local_98);
      iVar2 = iVar3 + 0x20 + iVar2;
      lVar4 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                              iVar2);
      if (lVar4 != 0) {
        iVar1 = RtlCreateSecurityDescriptor(&local_40,1);
        if (-1 < iVar1) {
          iVar1 = RtlCreateAcl(lVar4,iVar2,2);
          if (-1 < iVar1) {
            iVar1 = RtlAddAccessAllowedAce(lVar4,2,0x120001,local_90);
            if (-1 < iVar1) {
              iVar1 = RtlAddAccessAllowedAce(lVar4,2,0x120001,local_98);
              if (-1 < iVar1) {
                iVar1 = RtlSetDaclSecurityDescriptor(&local_40,1,lVar4,0);
                if (-1 < iVar1) {
                  RtlInitUnicodeString(&local_50,L"\\PendingRenameMutex");
                  local_70 = &local_50;
                  local_80 = CONCAT44(local_80._4_4_,0x30);
                  local_60 = &local_40;
                  uStack_78 = 0;
                  uStack_68 = CONCAT44(uStack_68._4_4_,0x50);
                  local_58 = 0;
                  iVar1 = NtCreateMutant(&local_88,0x1f0001,&local_80,0);
                  if (-1 < iVar1) {
                    iVar1 = NtClose(local_88);
                  }
                }
              }
            }
          }
        }
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar4);
      }
      RtlFreeSid(local_98);
    }
    RtlFreeSid(local_90);
  }
  return iVar1;
}



===== SmpReadyBootSync @ 14000dfa8 =====

ulonglong SmpReadyBootSync(void)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 local_res8 [2];
  undefined8 local_res10 [3];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  local_res8[0] = 0x10;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = SmpGetControlDeviceHandle(local_res10);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar1 = NtDeviceIoControlFile(local_res10[0],0,0,0,&local_18,0x2281dc,local_res8,4,0,0);
    uVar3 = (ulonglong)uVar1;
    NtClose(local_res10[0]);
  }
  return uVar3;
}



===== SmpGetControlDeviceHandle @ 14000e03c =====

undefined8 SmpGetControlDeviceHandle(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 local_res18 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res18[0] = 0;
  local_34 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_58,L"\\Device\\RdyBoost");
  local_30 = 0;
  local_28 = &local_58;
  local_38 = 0x30;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  uVar1 = NtOpenFile(local_res18,0x12019f,&local_38,&local_48,7,0x20);
  if (-1 < (int)uVar1) {
    *param_1 = local_res18[0];
    uVar1 = 0;
  }
  return uVar1;
}



===== SmpClearTemporaryFiles @ 14000e0f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpClearTemporaryFiles(void)

{
  int iVar1;
  uint *puVar2;
  undefined8 uVar3;
  uint *puVar4;
  undefined1 auStack_2f8 [32];
  uint *local_2d8;
  uint *local_2d0;
  undefined4 local_2c8;
  undefined4 local_2c0;
  undefined1 local_2b8;
  undefined8 *local_2b0;
  undefined1 local_2a8;
  longlong local_298;
  undefined8 local_290;
  undefined8 uStack_288;
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 local_270;
  undefined8 uStack_268;
  undefined8 local_260;
  undefined8 local_258;
  undefined *local_250;
  undefined4 local_248;
  undefined4 local_244;
  undefined8 local_240;
  undefined8 uStack_238;
  wchar_t local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_2f8;
  local_244 = 0;
  local_298 = 0;
  local_260 = 0x30;
  local_2d0 = (uint *)CONCAT44(local_2d0._4_4_,0x4021);
  puVar2 = (uint *)0x0;
  local_250 = &SmpTempFilesDir;
  local_258 = 0;
  local_248 = 0x40;
  local_280 = 0;
  uStack_278 = 0;
  local_2d8 = (uint *)CONCAT44(local_2d8._4_4_,3);
  local_270 = 0;
  uStack_268 = 0;
  local_290 = 0;
  uStack_288 = 0;
  local_240 = 0;
  uStack_238 = 0;
  iVar1 = NtOpenFile(&local_298,0x100001,&local_260,&local_280);
  if ((-1 < iVar1) &&
     (puVar2 = (uint *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                       0x8a8), puVar2 != (uint *)0x0)) {
    RtlInitUnicodeString(&local_290,L"SMSS-PFRO*.tmp");
    local_2a8 = 1;
    while( true ) {
      local_2b0 = &local_290;
      local_2b8 = 0;
      local_2d8 = (uint *)&local_280;
      local_2c0 = 0xc;
      local_2c8 = 0x8a8;
      local_2d0 = puVar2;
      iVar1 = NtQueryDirectoryFile(local_298,0,0,0);
      if ((iVar1 == -0x3ffffff1) || (iVar1 < 0)) break;
      for (puVar4 = puVar2; puVar4 < puVar2 + 0x22a;
          puVar4 = (uint *)((longlong)puVar4 + (ulonglong)*puVar4)) {
        local_2d8 = puVar4 + 3;
        uVar3 = RtlStringCbPrintfW(local_228,0x20a,L"%s\\%s",DAT_1400329f8);
        if (-1 < (int)uVar3) {
          RtlInitUnicodeString(&local_270,local_228);
          SmpForceDeleteTargetFile((ushort *)&local_270,'\x01');
        }
        if (*puVar4 == 0) break;
      }
      local_2a8 = 0;
    }
  }
  RtlDeleteRegistryValue(2,L"Session Manager",L"ClearTempFiles");
  if (puVar2 != (uint *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar2);
  }
  if (local_298 != 0) {
    NtClose();
  }
  return;
}



===== SmpInitializeKnownSubSystems @ 14000e340 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SmpInitializeKnownSubSystems(void)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  
  SmpKnownSubSysTable =
       RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,0x300);
  lVar4 = 0;
  if (SmpKnownSubSysTable == 0) {
    uVar2 = 0xc0000017;
  }
  else {
    lVar6 = 0;
    lVar5 = 0x20;
    do {
      lVar1 = lVar4 + SmpKnownSubSysTable;
      lVar3 = SmpKnownSubSysTable + 0x10;
      *(longlong *)(lVar1 + 8) = lVar1;
      *(longlong *)lVar1 = lVar1;
      RtlInitializeSRWLock(lVar3 + lVar6);
      lVar6 = lVar6 + 0x18;
      lVar4 = lVar4 + 0x18;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    RtlInitializeConditionVariable(&SmpSubSysReadyCondition);
    _DAT_1400324b8 = &SmpOverflowSubSysList;
    SmpOverflowSubSysList = &SmpOverflowSubSysList;
    uVar2 = 0;
  }
  return uVar2;
}



===== RtlQueryVolumeDiskSpeedPolicy @ 14000e40c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RtlQueryVolumeDiskSpeedPolicy(undefined8 param_1,int *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 *local_68;
  undefined4 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_30 = 0;
  local_34 = 0;
  local_28 = 0;
  local_20 = 0;
  local_38 = 7;
  local_50 = 0xc;
  local_58 = &local_28;
  local_60 = 0xc;
  local_68 = &local_38;
  local_78 = &local_48;
  local_70 = 0x2d1400;
  local_48 = 0;
  uStack_40 = 0;
  uVar2 = NtDeviceIoControlFile(0,0,0,0);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    if ((iVar1 != -0x3fffffff) && (iVar1 != -0x3ffffff0)) {
      return uVar2;
    }
    *param_2 = 10;
  }
  else {
    *param_2 = (-(uint)((char)local_20 != '\0') & 0xfffffff6) + 0x14;
  }
  return 0;
}



===== RtlStringCbCopyW @ 14000e4d4 =====

uint RtlStringCbCopyW(short *param_1,ulonglong param_2,longlong param_3)

{
  short sVar1;
  short *psVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  
  uVar3 = param_2 >> 1;
  if (0x7ffffffe < uVar3 - 1) {
    if (uVar3 != 0) {
      *param_1 = 0;
    }
    return 0xc000000d;
  }
  lVar4 = 0x7ffffffe - uVar3;
  lVar5 = param_3 - (longlong)param_1;
  do {
    if ((lVar4 + uVar3 == 0) || (sVar1 = *(short *)(lVar5 + (longlong)param_1), sVar1 == 0)) break;
    *param_1 = sVar1;
    param_1 = param_1 + 1;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  psVar2 = param_1 + -1;
  if (uVar3 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  return ~-(uint)(uVar3 != 0) & 0x80000005;
}



===== SmpIsVolumeOnSCMDevice @ 14000e548 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 SmpIsVolumeOnSCMDevice(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 *local_68;
  undefined4 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  undefined8 local_48;
  ulonglong uStack_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_50 = 0x10;
  local_58 = &local_28;
  local_68 = &local_38;
  local_60 = 0xc;
  uVar2 = 0;
  local_78 = &local_48;
  local_34 = 0;
  local_70 = 0x2d1400;
  local_38 = 0x37;
  local_48 = 0;
  uStack_40 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = NtDeviceIoControlFile(0,0,0,0);
  if (((-1 < iVar1) && (0xf < uStack_40)) && (uVar2 = 0, (uStack_20 & 1) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



===== SmpFinalizePathStrings @ 14000e600 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SmpFinalizePathStrings(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined2 local_18;
  short sStack_16;
  undefined4 uStack_14;
  longlong lStack_10;
  
  uVar2 = 0;
  uStack_14 = 0;
  uVar1 = RtlGetNtSystemRoot();
  RtlInitUnicodeString(&SmpSystemRoot,uVar1);
  local_18 = 0;
  sStack_16 = DAT_140033012 + 0x14 + _DAT_140032ad2;
  lStack_10 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag);
  if (lStack_10 == 0) {
    uVar2 = 0xc0000017;
  }
  else {
    RtlAppendUnicodeStringToString(&local_18,&SmpSystemRoot);
    RtlAppendUnicodeToString(&local_18,L"\\system32;");
    RtlAppendUnicodeStringToString(&local_18,&SmpDefaultLibPath);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,DAT_140033018);
    _SmpDefaultLibPath = CONCAT44(uStack_14,CONCAT22(sStack_16,local_18));
    DAT_140033018 = lStack_10;
  }
  return uVar2;
}



===== SmpGetVolumeDiskNumber @ 14000e708 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SmpGetVolumeDiskNumber(undefined8 param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_50 = 0x20;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_58 = &local_38;
  local_78 = &local_48;
  local_60 = 0;
  local_68 = 0;
  local_70 = 0x560000;
  local_48 = 0;
  uStack_40 = 0;
  uVar1 = NtDeviceIoControlFile(0,0,0,0);
  if (-1 < (int)uVar1) {
    if ((int)local_38 == 1) {
      *param_2 = (undefined4)uStack_30;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc0000001;
    }
  }
  return uVar1;
}



===== SmpReadSafeBootOption @ 14000e7b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpReadSafeBootOption(void)

{
  int iVar1;
  undefined1 auStack_288 [32];
  undefined4 local_268;
  undefined4 *local_260;
  undefined4 local_258 [2];
  undefined8 local_250;
  undefined8 local_248;
  undefined8 local_240;
  undefined *local_238;
  undefined4 local_230;
  undefined4 local_22c;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined1 local_218 [12];
  undefined4 local_20c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_288;
  local_250 = 0;
  local_22c = 0;
  local_258[0] = 0;
  local_240 = 0;
  local_248 = 0x30;
  local_238 = &SmpSafebootOptionKey;
  local_228 = 0;
  uStack_220 = 0;
  local_230 = 0x40;
  iVar1 = NtOpenKey(&local_250,0xf003f,&local_248);
  if (-1 < iVar1) {
    local_260 = local_258;
    local_268 = 0x200;
    iVar1 = NtQueryValueKey(local_250,&SmpSafebootOptionValue,2,local_218);
    NtClose(local_250);
    if (-1 < iVar1) {
      SmpSafeBootOption = local_20c;
    }
  }
  return iVar1;
}



===== SmpComputeDesiredPfSizeForCrashDump @ 14000e8c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SmpComputeDesiredPfSizeForCrashDump(void)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  SmpTryHardForCrashDump = 0;
  if (SmpUseDedicatedDumpFile == '\x01') {
    SmpTryHardForCrashDump = 0;
    return 0;
  }
  if (SmpDumpType == 7) {
    if (SmpMemorySize < 0x100000000) {
      uVar3 = SmpMemorySize / 6;
    }
    else {
      uVar1 = SmpMemorySize - 0x100000000 >> 3;
      uVar3 = 0x800000000;
      if (uVar1 < 0x800000000) {
        uVar3 = uVar1;
      }
      uVar3 = uVar3 + (SmpMemorySize - 0x100000000 >> 6) + 0x2aaaaaaa;
    }
    if (uVar3 < 0x10000000) {
      uVar3 = 0x10000000;
    }
    lVar2 = SmpQueryPagefileTooSmallForDump();
    if (0x1600a390ffff < (ulonglong)(_DAT_7ffe0014 - lVar2)) {
      return uVar3;
    }
    uVar1 = 0x800000000;
    if (SmpMemorySize < 0x800000000) {
      uVar1 = SmpMemorySize;
    }
    if (uVar3 < uVar1) {
      return uVar1;
    }
    return uVar3;
  }
  if (SmpDumpType != 2) {
    if (SmpDumpType != 1) {
      SmpTryHardForCrashDump = 0;
      return 0;
    }
    if (SmpUseFilterPagesDumpFile == '\0') {
      uVar3 = SmpMemorySize + 0x10000000 +
              ((ulonglong)(DAT_140032b08 - 1) + 0x2040 +
               (SmpHighestPhysicalAddress / DAT_140032b08 + 7 >> 3) &
              (ulonglong)~(DAT_140032b08 - 1));
      if (uVar3 < 0x40000001) {
        SmpTryHardForCrashDump = 1;
        return 0x40000000;
      }
      SmpTryHardForCrashDump = 1;
      return uVar3;
    }
  }
  SmpTryHardForCrashDump = 1;
  return SmpMemorySize;
}



===== SmpInitializeManagedPagefileSupport @ 14000ea24 =====

void SmpInitializeManagedPagefileSupport(void)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 local_res8;
  undefined8 local_res10 [3];
  
  local_res8 = 0;
  if (SmpManagedPfInitialized != '\x01') {
    SmpDesiredPfSizeBasedOnRAM = 0x40000000;
    if ((0x40000000 < SmpMemorySize) &&
       (SmpDesiredPfSizeBasedOnRAM = (SmpMemorySize - 0x40000000 >> 3) + 0x40000000,
       0x800000000 < SmpDesiredPfSizeBasedOnRAM)) {
      SmpDesiredPfSizeBasedOnRAM = 0x800000000;
    }
    SmpDesiredPfSizeForCrashDump = SmpComputeDesiredPfSizeForCrashDump();
    SmpDesiredPfSizeBasedOnHistory = SmpComputeDesiredPfSizeBasedOnHistory();
    SmpDesiredPfSizeForApps = 0;
    if (SmpClientSku == '\x01') {
      if (SmpMemorySize < 0xa38e38e3) {
        uVar2 = 0xa38e38e3 - SmpMemorySize;
      }
      else {
        uVar2 = 0;
      }
      SmpDesiredPfSizeForApps = uVar2 + (uVar2 >> 4);
    }
    iVar1 = TpAllocTimer(&local_res8,SmpUpdatePagefileUsageCallback,0,&SmpCallbackEnviron);
    if (iVar1 < 0) {
      SmpLogFailure(0x1400287e8,0x2c0,iVar1);
    }
    else {
      local_res10[0] = 0xfffffff79e3b9800;
      TpSetTimer(local_res8,local_res10,3600000,300000);
    }
    SmpManagedPfInitialized = '\x01';
  }
  return;
}



===== SmpPlatformBinaryTableExists @ 14000eb40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool SmpPlatformBinaryTableExists(void)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined8 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_30 = 0x41435049;
  local_38[0] = 0;
  local_24 = 0;
  local_2c = 1;
  local_28 = 0x54504257;
  iVar1 = NtQuerySystemInformation(0x4c,&local_30,0x14,local_38);
  return iVar1 == -0x3fffffdd;
}



===== SmpInitializeSessionManagement @ 14000ebc0 =====

void SmpInitializeSessionManagement(void)

{
  int iVar1;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_30 = 0;
  local_28 = 0;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = 2;
  iVar1 = NtCreateEvent(&SmpSessionCreateBlockEvent,0x100002,&local_38,0,1);
  if (-1 < iVar1) {
    SmpInitCoreProcessArray();
  }
  return;
}



===== SmpCreatePagefileFromDescriptor @ 14000ec28 =====

int SmpCreatePagefileFromDescriptor(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  bool bVar4;
  
  iVar2 = -0x3fffffcc;
  puVar1 = SmpVolumeDescriptorList;
LAB_14000ec49:
  do {
    puVar3 = puVar1;
    if ((undefined8 **)puVar3 == &SmpVolumeDescriptorList) {
      return iVar2;
    }
    puVar1 = (undefined8 *)*puVar3;
    if ((*(byte *)(param_1 + 0x5c) & 4) == 0) {
      bVar4 = *(short *)((longlong)puVar3 + 0x1c) == *(short *)(*(longlong *)(param_1 + 0x18) + 8);
    }
    else {
      if ((*(byte *)(puVar3 + 2) & 0x12) != 0) goto LAB_14000ec49;
      bVar4 = (*(byte *)(puVar3 + 2) & 1) != 0 || (*(uint *)(puVar3 + 3) & 0x40000) == 0;
    }
    if ((bVar4) && (iVar2 = SmpCreatePagefileOnVolume(param_1,(longlong)puVar3,param_2), -1 < iVar2)
       ) {
      return iVar2;
    }
  } while( true );
}



===== SmpGetTime @ 14000ecb8 =====

void SmpGetTime(undefined8 param_1)

{
  longlong local_res10;
  longlong local_res18 [2];
  
  local_res10 = 0;
  local_res18[0] = RtlGetSystemTimeAndBias(&local_res10,0,0);
  local_res18[0] = local_res18[0] - local_res10;
  RtlTimeToTimeFields(local_res18,param_1);
  return;
}



===== __report_gsfailure @ 14000ed20 =====

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
  RtlCaptureContext(&DAT_140031de0);
  ControlPc = DAT_140031ed8;
  FunctionEntry = RtlLookupFunctionEntry(DAT_140031ed8,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    _DAT_140031e78 = local_res8;
    DAT_140031ed8 = unaff_retaddr;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_140031de0,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_140031d50 = DAT_140031ed8;
  _DAT_140031e60 = local_res8[0];
  _DAT_140031d40 = 0xc0000409;
  _DAT_140031d44 = 1;
  _DAT_140031d58 = 1;
  DAT_140031d60 = 2;
  uStack_20 = __security_cookie;
  uStack_18 = __security_cookie_complement;
  RtlUnhandledExceptionFilter(&PTR_DAT_140021a30);
  NtTerminateProcess(0xffffffffffffffff,0xc0000409);
  return;
}



===== __security_init_cookie @ 14000ee9c =====

void __cdecl __security_init_cookie(void)

{
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    __security_init_cookie_ex(&__security_cookie);
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== __security_init_cookie_ex @ 14000eee8 =====

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



===== NtDeviceIoControlFile @ 14000ef4c =====

void NtDeviceIoControlFile(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ef4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NtDeviceIoControlFile();
  return;
}



===== NtTerminateProcess @ 14000ef58 =====

void NtTerminateProcess(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ef58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NtTerminateProcess();
  return;
}



===== __C_specific_handler @ 14000ef64 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ef64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== RtlCaptureContext @ 14000ef70 =====

void RtlCaptureContext(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ef70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlCaptureContext();
  return;
}



===== RtlLookupFunctionEntry @ 14000ef7c =====

PRUNTIME_FUNCTION __stdcall
RtlLookupFunctionEntry(DWORD64 ControlPc,PDWORD64 ImageBase,PUNWIND_HISTORY_TABLE HistoryTable)

{
  PRUNTIME_FUNCTION p_Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ef7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  p_Var1 = RtlLookupFunctionEntry(ControlPc,ImageBase,HistoryTable);
  return p_Var1;
}



===== RtlVirtualUnwind @ 14000ef88 =====

PEXCEPTION_ROUTINE __stdcall
RtlVirtualUnwind(DWORD HandlerType,DWORD64 ImageBase,DWORD64 ControlPc,
                PRUNTIME_FUNCTION FunctionEntry,PCONTEXT ContextRecord,PVOID *HandlerData,
                PDWORD64 EstablisherFrame,PKNONVOLATILE_CONTEXT_POINTERS ContextPointers)

{
  PEXCEPTION_ROUTINE puVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ef88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar1 = RtlVirtualUnwind(HandlerType,ImageBase,ControlPc,FunctionEntry,ContextRecord,HandlerData,
                            EstablisherFrame,ContextPointers);
  return puVar1;
}



===== RtlUnhandledExceptionFilter @ 14000ef94 =====

void RtlUnhandledExceptionFilter(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ef94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnhandledExceptionFilter();
  return;
}



===== SmpAdjustPagefileSizeforLowStorage @ 14000efa8 =====

void SmpAdjustPagefileSizeforLowStorage(void)

{
  undefined2 uVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int local_res8 [2];
  int local_res10 [2];
  int local_res18 [4];
  undefined8 local_28;
  wchar_t *local_20;
  
  puVar2 = SmpPagingFileDescriptorList;
  uVar6 = 0;
  local_28 = 0x5c005a;
  local_20 = L"System-ConfigurePagefileForLowStorage-Enabled";
  local_res8[0] = 0;
  local_res10[0] = 0;
  local_res18[0] = 0;
  if ((((SmpNumberOfPagefileDescriptors == 1) &&
       ((undefined8 **)SmpPagingFileDescriptorList != &SmpPagingFileDescriptorList)) &&
      (((byte)*(undefined4 *)((longlong)SmpPagingFileDescriptorList + 0x5c) & 6) == 6)) &&
     ((SmpOsVolumeDescriptor != 0 && (*(ulonglong *)(SmpOsVolumeDescriptor + 0x28) < 0x800000001))))
  {
    iVar3 = NtQueryLicenseValue(&local_28,local_res8,local_res18,4,local_res10);
    uVar1 = SmpOsVolumeLetter;
    if (((-1 < iVar3) && ((local_res8[0] == 4 && (local_res10[0] == 4)))) && (local_res18[0] != 0))
    {
      *(uint *)((longlong)puVar2 + 0x5c) = *(uint *)((longlong)puVar2 + 0x5c) & 0xfffffff9;
      SmpAnyDriveDescriptorCreated = 0;
      *(undefined2 *)(puVar2[3] + 8) = uVar1;
      if (*(ulonglong *)(SmpOsVolumeDescriptor + 0x28) < 0x400000001) {
        uVar4 = 0x80000000;
        if (0xc0000000 < SmpMemorySize) {
          uVar4 = 0x4000000;
        }
        uVar5 = uVar4;
      }
      else {
        uVar6 = 0x10000000;
        uVar5 = 0x80000000;
        if (0xc0000000 < SmpMemorySize) {
          uVar5 = 0x60000000;
        }
        uVar4 = 0xf0000000;
      }
      puVar2[7] = uVar5;
      SmpMaxSwapFileSize = uVar6;
      puVar2[8] = uVar4;
      puVar2[6] = puVar2[7];
    }
  }
  return;
}



===== SmpAsyncMemoryConfiguration @ 14000f110 =====

void SmpAsyncMemoryConfiguration(void)

{
  bool bVar1;
  int iVar2;
  char local_res20 [8];
  undefined4 local_18 [4];
  
  local_18[0] = 0;
  bVar1 = true;
  iVar2 = SmpPagefileInitialize();
  if (iVar2 < 0) {
    return;
  }
  iVar2 = SmpNtSerializeBoot();
  if (iVar2 < 0) {
    SmpLogFailure(0x140028c88,0x126c,iVar2);
  }
  if (SmpHostSmss != '\0') {
    if ((SmpUseDedicatedDumpFile == '\0') &&
       (iVar2 = NtSetSystemInformation(0x22,local_18), iVar2 < 0)) {
      SmpLogFailure(0x140028c88,0x127f,iVar2);
    }
    if (SmpHostSmss != '\0') goto LAB_14000f19e;
  }
  bVar1 = false;
  SmpPagefileOnOsVolume = 0;
LAB_14000f19e:
  if (SmpMiniNTBoot == '\x01') {
    local_res20[0] = '\0';
    iVar2 = SmpIsRamdiskBoot(local_res20);
    if (iVar2 < 0) {
      SmpLogFailure(0x140028c88,0x129f,iVar2);
    }
    if (local_res20[0] == '\x01') {
      bVar1 = false;
    }
    else {
      SmpPagefileOnOsVolume = 1;
    }
  }
  if (SmpMiniNTBoot == '\0') {
    SmpCheckMemoryCoolingCompatibility();
  }
  if (bVar1) {
    if (SmpMiniNTBoot == '\0') {
      SmpEnableCachingOnDedicatedMemoryWorker();
      RtlSubscribeWnfStateChangeNotification
                (&SmpPhysicalMemoryChangeSubscription,0x41c60320a3bc1075,0,
                 SmpDedicatedMemoryCachingCallback,0,0,0,1);
    }
    SmpCreatePagingFiles();
    NtInitializeRegistry(2);
  }
  if (SmpCrashDumpKey != 0) {
    NtClose();
  }
  return;
}



===== SmpCheckHybridPriority @ 14000f27c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SmpCheckHybridPriority(uint param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  byte *pbVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined4 *local_70;
  undefined4 local_68 [2];
  undefined8 local_60;
  wchar_t *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  uint uStack_38;
  uint auStack_34 [3];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_68[0] = 0;
  local_58 = L"PagefileHybridPriority";
  local_60 = 0x2e002c;
  auStack_34[1] = 0;
  local_70 = local_68;
  local_78 = 0x24;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  _uStack_38 = 0;
  uVar3 = NtQueryValueKey(SmpMmKey,&local_60,4,&local_50);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if (((int)local_50 == 3) && (local_50._4_4_ == 0x18)) {
    pbVar5 = (byte *)((longlong)&uStack_48 + 4);
    lVar7 = 0x14;
    do {
      *pbVar5 = *pbVar5 ^ (byte)uStack_48;
      pbVar5 = pbVar5 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    if ((uStack_48._4_4_ == 3) && (local_40._4_1_ < 2)) {
      iVar1 = (int)uStack_48;
      uStack_48 = 0x300000000;
      iVar2 = RtlComputeCrc32();
      if (iVar2 == iVar1) {
        uVar6 = 0;
        while( true ) {
          if ((uint)local_40._4_1_ <= (uint)uVar6) break;
          if (0xfd < (ushort)auStack_34[uVar6 * 2] - 1) goto LAB_14000f3b9;
          uVar6 = (ulonglong)((uint)uVar6 + 1);
        }
        uVar6 = 0;
        if (local_40._4_1_ != 0) {
          do {
            if (auStack_34[uVar6 * 2 + -1] == param_1) break;
            uVar4 = (int)uVar6 + 1;
            uVar6 = (ulonglong)uVar4;
          } while (uVar4 < local_40._4_1_);
        }
        if ((uint)uVar6 < (uint)local_40._4_1_) {
          uVar4 = auStack_34[uVar6 * 2];
          *param_2 = uVar4 & 0xffff;
          if (param_3 != (uint *)0x0) {
            *param_3 = uVar4 >> 0x10 & 1;
          }
          return 0;
        }
        goto LAB_14000f3c0;
      }
    }
LAB_14000f3b9:
    uVar3 = 0xc000007b;
  }
  else {
LAB_14000f3c0:
    uVar3 = 0xc0000225;
  }
  return uVar3;
}



===== SmpCleanupStalePageFiles @ 14000f3f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpCleanupStalePageFiles(void)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  undefined1 auStack_268 [32];
  wchar_t *local_248;
  undefined8 local_238;
  undefined8 uStack_230;
  wchar_t local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_268;
  local_238 = 0;
  uStack_230 = 0;
  plVar3 = SmpExistingPageFilesList;
  while ((longlong **)plVar3 != &SmpExistingPageFilesList) {
    iVar2 = SmpDeletePagingFile(plVar3 + 2);
    if (iVar2 < 0) {
      SmpLogFailureString(0x140028be0,0x1093,plVar3[3],iVar2);
    }
    plVar1 = (longlong *)*plVar3;
    SmpFreeSavedRegistryEntry(plVar3);
    plVar3 = plVar1;
  }
  if (SmpWsSwapPagefileCreated == '\0') {
    local_248 = L"swapfile.sys";
    RtlStringCbPrintfW(local_228,0x208,L"\\??\\%c:\\%s",(ulonglong)SmpOsVolumeLetter);
    RtlInitUnicodeString(&local_238,local_228);
    SmpDeletePagingFile(&local_238);
  }
  return;
}



===== SmpClearPagingFileDescriptorList @ 14000f4e4 =====

void SmpClearPagingFileDescriptorList(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  while( true ) {
    puVar4 = SmpPagingFileDescriptorList;
    if ((undefined8 **)SmpPagingFileDescriptorList == &SmpPagingFileDescriptorList) {
      SmpNumberOfPagefileDescriptors = 0;
      return;
    }
    if (((undefined8 **)SmpPagingFileDescriptorList[1] != &SmpPagingFileDescriptorList) ||
       (puVar2 = (undefined8 *)*SmpPagingFileDescriptorList,
       (undefined8 *)puVar2[1] != SmpPagingFileDescriptorList)) break;
    puVar1 = SmpPagingFileDescriptorList + 2;
    SmpPagingFileDescriptorList = puVar2;
    puVar2[1] = &SmpPagingFileDescriptorList;
    RtlFreeUnicodeString(puVar1);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  SmpNumberOfPagefileDescriptors = 0;
  return;
}



===== SmpComputeDesiredPfSizeBasedOnHistory @ 14000f56c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong SmpComputeDesiredPfSizeBasedOnHistory(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int *piVar5;
  undefined8 *puVar6;
  int iVar7;
  int *piVar8;
  undefined8 *puVar9;
  longlong lVar10;
  ulonglong _NumOfElements;
  uint uVar11;
  undefined1 auStack_848 [32];
  undefined4 local_828;
  undefined4 *local_820;
  undefined4 local_818 [2];
  undefined8 local_810;
  longlong local_808 [2];
  wchar_t *local_7f8;
  longlong local_7f0;
  wchar_t *local_7e8;
  undefined4 local_7e0;
  undefined4 local_7dc;
  undefined8 local_7d8;
  longlong *local_7d0;
  undefined4 local_7c8;
  undefined4 local_7c4;
  undefined8 local_7c0;
  undefined8 uStack_7b8;
  int local_7a8;
  int local_7a4;
  int local_7a0 [242];
  uint local_3d8 [240];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_848;
  local_818[0] = 0;
  local_808[0] = 0;
  local_7c4 = 0;
  local_810 = 0;
  local_7dc = 0;
  local_7f8 = L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion";
  local_7e8 = L"InstallDate";
  local_808[1] = 0x7e007c;
  local_7f0 = 0x180016;
  memset(&local_7a8,0,0x3cc);
  local_820 = local_818;
  local_828 = 0x3cc;
  iVar7 = NtQueryValueKey(SmpMmKey,&SmpPagefileUsageValue,4,&local_7a8);
  if ((((iVar7 < 0) || (local_7a8 != 3)) || (local_7a4 != 0x3c4)) || (local_7a0[0] == 0)) {
    DAT_140032c30 = 0;
  }
  else {
    lVar10 = 7;
    piVar5 = local_7a0;
    puVar6 = (undefined8 *)&DAT_140032c30;
    do {
      puVar9 = puVar6;
      piVar8 = piVar5;
      uVar1 = *(undefined8 *)(piVar8 + 2);
      uVar2 = *(undefined8 *)(piVar8 + 4);
      uVar3 = *(undefined8 *)(piVar8 + 6);
      *puVar9 = *(undefined8 *)piVar8;
      puVar9[1] = uVar1;
      uVar1 = *(undefined8 *)(piVar8 + 8);
      uVar4 = *(undefined8 *)(piVar8 + 10);
      puVar9[2] = uVar2;
      puVar9[3] = uVar3;
      uVar2 = *(undefined8 *)(piVar8 + 0xc);
      uVar3 = *(undefined8 *)(piVar8 + 0xe);
      puVar9[4] = uVar1;
      puVar9[5] = uVar4;
      uVar1 = *(undefined8 *)(piVar8 + 0x10);
      uVar4 = *(undefined8 *)(piVar8 + 0x12);
      puVar9[6] = uVar2;
      puVar9[7] = uVar3;
      uVar2 = *(undefined8 *)(piVar8 + 0x14);
      uVar3 = *(undefined8 *)(piVar8 + 0x16);
      puVar9[8] = uVar1;
      puVar9[9] = uVar4;
      uVar1 = *(undefined8 *)(piVar8 + 0x18);
      uVar4 = *(undefined8 *)(piVar8 + 0x1a);
      puVar9[10] = uVar2;
      puVar9[0xb] = uVar3;
      uVar2 = *(undefined8 *)(piVar8 + 0x1c);
      uVar3 = *(undefined8 *)(piVar8 + 0x1e);
      puVar9[0xc] = uVar1;
      puVar9[0xd] = uVar4;
      puVar9[0xe] = uVar2;
      puVar9[0xf] = uVar3;
      lVar10 = lVar10 + -1;
      piVar5 = piVar8 + 0x20;
      puVar6 = puVar9 + 0x10;
    } while (lVar10 != 0);
    uVar1 = *(undefined8 *)(piVar8 + 0x22);
    uVar2 = *(undefined8 *)(piVar8 + 0x24);
    uVar3 = *(undefined8 *)(piVar8 + 0x26);
    puVar9[0x10] = *(undefined8 *)(piVar8 + 0x20);
    puVar9[0x11] = uVar1;
    uVar1 = *(undefined8 *)(piVar8 + 0x28);
    uVar4 = *(undefined8 *)(piVar8 + 0x2a);
    puVar9[0x12] = uVar2;
    puVar9[0x13] = uVar3;
    uVar2 = *(undefined8 *)(piVar8 + 0x2c);
    uVar3 = *(undefined8 *)(piVar8 + 0x2e);
    iVar7 = piVar8[0x30];
    puVar9[0x14] = uVar1;
    puVar9[0x15] = uVar4;
    puVar9[0x16] = uVar2;
    puVar9[0x17] = uVar3;
    *(int *)(puVar9 + 0x18) = iVar7;
  }
  local_7d8 = 0;
  local_7d0 = local_808 + 1;
  uVar11 = 0x30;
  local_7c8 = 0x40;
  local_7e0 = 0x30;
  local_7c0 = 0;
  uStack_7b8 = 0;
  iVar7 = NtOpenKey(&local_810,0x20019,&local_7e0);
  if (iVar7 < 0) {
    SmpLogFailure(0x140028b68,0xdc2,iVar7);
  }
  else {
    local_820 = local_818;
    local_828 = 0x3cc;
    iVar7 = NtQueryValueKey(local_810,local_808 + 3,4,&local_7a8);
    NtClose(local_810);
    lVar10 = _DAT_7ffe0014;
    if (((-1 < iVar7) && (local_7a8 == 4)) &&
       (RtlSecondsSince1970ToTime(local_7a0[0],local_808),
       0x649534dffff < (ulonglong)(lVar10 - local_808[0]))) {
      uVar11 = 8;
    }
  }
  _NumOfElements = (ulonglong)DAT_140032c30;
  if (DAT_140032c30 < uVar11) {
    return SmpDesiredPfSizeBasedOnRAM;
  }
  if (DAT_140032c30 < 0xf0) {
    if (DAT_140032c30 == 0) {
      iVar7 = 0;
      goto LAB_14000f7f9;
    }
  }
  else {
    _NumOfElements = 0xf0;
  }
  iVar7 = (int)_NumOfElements;
  memcpy(local_3d8,&DAT_140032c34,_NumOfElements << 2);
LAB_14000f7f9:
  qsort(local_3d8,_NumOfElements,4,SmpPagefileUsageSampleCompare);
  return ((ulonglong)local_3d8[(ulonglong)(uint)(iVar7 * 9) / 10] * (ulonglong)DAT_140032b08 >> 4) +
         (ulonglong)local_3d8[(ulonglong)(uint)(iVar7 * 9) / 10] * (ulonglong)DAT_140032b08;
}



===== SmpCreateDedicatedMemoryPagefile @ 14000f870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SmpCreateDedicatedMemoryPagefile(void)

{
  undefined8 uVar1;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined4 *local_60;
  undefined4 local_58 [2];
  longlong local_50 [2];
  wchar_t *local_40;
  longlong local_38;
  wchar_t *local_30;
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_58[0] = 0;
  local_40 = L"DedicatedMemoryPagefileSizeMB";
  local_50[1] = 0x3c003a;
  local_30 = L"Dedicated memory pagefile";
  local_60 = local_58;
  local_38 = 0x340032;
  local_68 = 0x10;
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = NtQueryValueKey(SmpMmKey,local_50 + 1,4,&local_28);
  if (-1 < (int)uVar1) {
    if (((int)local_28 == 4) && (local_28._4_4_ == 4)) {
      local_50[0] = (uStack_20 & 0xffffffff) << 0x14;
      uVar1 = NtCreatePagingFile(local_50 + 3,local_50,local_50,0x800000);
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== SmpCreateEmergencyPagingFile @ 14000f94c =====

undefined8 SmpCreateEmergencyPagingFile(void)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  plVar2 = (longlong *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8,0x60);
  if (plVar2 != (longlong *)0x0) {
    *(undefined2 *)((longlong)plVar2 + 0x12) = 0x28;
    lVar3 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0);
    plVar2[3] = lVar3;
    if (lVar3 != 0) {
      RtlInitUnicodeString(plVar2 + 4,0);
      RtlAppendUnicodeToString(plVar2 + 2,L"\\??\\?:\\pagefile.sys");
      *(undefined2 *)(plVar2[3] + 8) = 0x3f;
      *(uint *)((longlong)plVar2 + 0x5c) = *(uint *)((longlong)plVar2 + 0x5c) | 6;
      SmpClearPagingFileDescriptorList();
      puVar5 = &SmpPagingFileDescriptorList;
      SmpNumberOfPagefileDescriptors = SmpNumberOfPagefileDescriptors + 1;
      if ((longlong **)*(undefined8 **)((longlong)SmpPagingFileDescriptorList + 8) !=
          &SmpPagingFileDescriptorList) {
        puVar5 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        SmpPagingFileDescriptorList = (longlong *)(*pcVar1)();
      }
      plVar2[1] = (longlong)puVar5;
      *plVar2 = (longlong)SmpPagingFileDescriptorList;
      *(longlong **)((longlong)SmpPagingFileDescriptorList + 8) = plVar2;
      SmpPagingFileDescriptorList = plVar2;
      uVar4 = SmpProcessPagefileDescriptor((longlong)plVar2);
      return uVar4;
    }
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,plVar2);
  }
  return 0xc0000017;
}



===== SmpCreatePagefileOnVolume @ 14000fa5c =====

int SmpCreatePagefileOnVolume(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  bool bVar5;
  int iVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  longlong lVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  uint local_res8 [2];
  undefined8 local_res10;
  longlong local_res20;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_64 = 0;
  local_4c = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_res10 = 0;
  lVar13 = 0;
  local_res8[0] = 0;
  bVar5 = false;
  local_res20 = 0;
  if ((*(byte *)(param_1 + 0x5c) & 4) != 0) {
    *(undefined2 *)(*(longlong *)(param_1 + 0x18) + 8) = *(undefined2 *)(param_2 + 0x1c);
  }
  lVar1 = param_1 + 0x10;
  local_68 = 0x30;
  local_60 = 0;
  local_50 = 0x40;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = lVar1;
  iVar6 = NtOpenFile(&local_res10,0xc0100000,&local_68,&local_78,3,0x28);
  if (-1 < iVar6) {
    iVar6 = SmpGetPagingFileSize(local_res10,lVar1,&local_res20);
    lVar13 = local_res20;
    if (-1 < iVar6) {
      bVar5 = false;
      if (local_res20 != 0) {
        bVar5 = true;
      }
    }
    SmpTrimPagingFileExtents(local_res10,lVar1);
    NtClose(local_res10);
  }
  uVar15 = *(longlong *)(param_2 + 0x20) + lVar13;
  if (*(ulonglong *)(param_2 + 0x28) < uVar15) {
    uVar15 = *(ulonglong *)(param_2 + 0x28);
  }
  uVar4 = *(ulonglong *)(param_1 + 0x38);
  uVar11 = *(ulonglong *)(param_1 + 0x40);
  *(ulonglong *)(param_1 + 0x48) = uVar4;
  *(ulonglong *)(param_1 + 0x50) = uVar11;
  if ((*(byte *)(param_1 + 0x5c) & 2) == 0) {
    if (uVar15 < uVar4) {
      if (param_3 == 0) {
        return -0x3fffff81;
      }
      *(ulonglong *)(param_1 + 0x48) = uVar15;
    }
    if (*(ulonglong *)(param_2 + 0x28) < uVar11) {
      *(ulonglong *)(param_1 + 0x50) = *(ulonglong *)(param_2 + 0x28);
    }
  }
  else {
    uVar14 = *(ulonglong *)(param_2 + 0x28) >> 3;
    uVar8 = uVar15 >> 2;
    if (uVar15 >> 2 <= SmpMemorySize) {
      uVar8 = SmpMemorySize;
    }
    uVar10 = uVar15 >> 1;
    if (uVar8 <= uVar15 >> 1) {
      uVar10 = uVar8;
    }
    uVar8 = uVar14;
    if (uVar10 <= uVar14) {
      uVar8 = uVar10;
    }
    uVar10 = uVar4;
    if (uVar4 <= uVar8) goto LAB_14000fc39;
    if (param_3 == 0) {
      uVar12 = 0x888;
      goto LAB_14000fbd6;
    }
    if ((*(byte *)(param_1 + 0x5c) & 8) != 0) {
      uVar7 = uVar15 >> 5;
      if (0x40000000 < uVar7) {
        uVar7 = 0x40000000;
      }
      uVar7 = uVar15 - uVar7;
      if (((uVar4 <= uVar7) || (uVar4 == *(ulonglong *)(param_1 + 0x30))) &&
         (uVar8 = uVar7, uVar14 < uVar7)) {
        uVar14 = uVar7;
      }
    }
    if (uVar8 < uVar4) {
      uVar10 = *(ulonglong *)(param_1 + 0x30);
      if (uVar10 < uVar4) {
        *(ulonglong *)(param_1 + 0x48) = uVar10;
        goto LAB_14000fc39;
      }
LAB_14000fc3e:
      *(ulonglong *)(param_1 + 0x48) = uVar8;
    }
    else {
LAB_14000fc39:
      if (uVar8 < uVar10) goto LAB_14000fc3e;
    }
    if (uVar14 < uVar11) {
      *(ulonglong *)(param_1 + 0x50) = uVar14;
    }
  }
  puVar2 = (uint *)(param_1 + 0x58);
  *puVar2 = 0;
  if ((*(byte *)(param_2 + 0x10) & 4) != 0) {
    *puVar2 = 0x40000000;
  }
  if ((((*(byte *)(param_2 + 0x10) & 8) != 0) &&
      (uVar9 = SmpCheckHybridPriority(*(uint *)(param_2 + 0x14),local_res8,(uint *)0x0),
      -1 < (int)uVar9)) && ((local_res8[0] & 0xfffffff0) == 0)) {
    *puVar2 = *puVar2 | (local_res8[0] | 0x10) << 0x1a;
  }
  if ((*(byte *)(param_2 + 0x10) & 0x40) != 0) {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x1000000;
  }
  while (iVar6 = SmpCreatePagingFile(param_1 + 0x10,*(undefined8 *)(param_1 + 0x48),
                                     *(undefined8 *)(param_1 + 0x50)), iVar6 < 0) {
    if ((param_3 == 0) || (uVar4 = *(ulonglong *)(param_1 + 0x48), uVar4 < 0x1000001))
    goto LAB_14000fd3f;
    uVar11 = 0x1000000;
    if (0x1000000 < uVar4 >> 4) {
      uVar11 = uVar4 >> 4;
    }
    *(ulonglong *)(param_1 + 0x48) = uVar4 - uVar11;
    if (uVar4 - uVar11 < 0x1000000) {
      *(undefined8 *)(param_1 + 0x48) = 0x1000000;
    }
  }
  *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 1;
  uVar3 = *(uint *)(param_2 + 0x10);
  *(uint *)(param_2 + 0x10) = uVar3 | 0x10;
  if ((*(uint *)(param_1 + 0x58) & 0x40000000) != 0) {
    *(uint *)(param_2 + 0x10) = uVar3 | 0x30;
  }
  if ((*(byte *)(param_1 + 0x5c) & 2) != 0) {
    SmpNumberOfManagedPagefilesCreated = SmpNumberOfManagedPagefilesCreated + 1;
  }
  SmpNumberOfPagefilesCreated = SmpNumberOfPagefilesCreated + 1;
LAB_14000fd3f:
  if ((*(byte *)(param_1 + 0x5c) & 1) != 0) {
    return iVar6;
  }
  if ((bVar5) && (iVar6 = SmpDeletePagingFile(param_1 + 0x10), -1 < iVar6)) {
    *(ulonglong *)(param_2 + 0x20) = uVar15;
  }
  uVar12 = 0x953;
LAB_14000fbd6:
  SmpLogFailure(0x1400289e0,uVar12,0xc000007f);
  return -0x3fffff81;
}



===== SmpCreatePagingFile @ 14000fd88 =====

int SmpCreatePagingFile(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  
  local_res10 = param_3;
  local_res18[0] = param_2;
  iVar2 = NtCreatePagingFile(param_1,local_res18,&local_res10);
  lVar5 = 0;
  if (iVar2 < 0) {
    if (param_1 != 0) {
      lVar5 = *(longlong *)(param_1 + 8);
    }
    SmpLogFailureString(0x1400289c8,0x7fe,lVar5,iVar2);
  }
  else {
    plVar4 = SmpExistingPageFilesList;
    if ((longlong **)SmpExistingPageFilesList != &SmpExistingPageFilesList) {
      do {
        iVar3 = RtlCompareUnicodeString(plVar4 + 2,param_1,1);
        plVar1 = (longlong *)*plVar4;
        if (iVar3 == 0) {
          SmpFreeSavedRegistryEntry(plVar4);
        }
        plVar4 = plVar1;
      } while ((longlong **)plVar1 != &SmpExistingPageFilesList);
    }
  }
  return iVar2;
}



===== SmpCreatePagingFileDescriptor @ 14000fe40 =====

int SmpCreatePagingFileDescriptor(undefined8 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short sVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  longlong lVar10;
  uint local_res10 [2];
  uint local_res18 [2];
  ulonglong local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  lStack_30 = 0;
  if (0xf < SmpNumberOfPagefileDescriptors) {
    SmLogFailureInt(0x140028810,0x3b9,(ulonglong)SmpNumberOfPagefileDescriptors,0,0xc0000097);
    return -0x3fffff69;
  }
  iVar6 = SmpParseCommandLine(param_1,(uint *)0x0,&local_28,0,&local_38);
  lVar10 = 0;
  if (iVar6 < 0) {
    if (param_1 != (undefined8 *)0x0) {
      lVar10 = param_1[1];
    }
    SmpLogFailureString(0x140028810,0x3cd,lVar10,iVar6);
    return iVar6;
  }
  SmpRegistrySpecifierPresent = 1;
  local_res10[0] = 0;
  local_res18[0] = 0;
  if (lStack_30 == 0) {
LAB_14000ff46:
    iVar6 = 1;
  }
  else {
    iVar6 = SmpParseSwapOrPageFileArguments((ushort *)&local_38,local_res10,local_res18);
    if (iVar6 < 0) {
      SmpLogFailure(0x140028810,0x3ee,iVar6);
      RtlFreeUnicodeString(&local_28);
      RtlFreeUnicodeString(&local_38);
      return iVar6;
    }
    if ((local_res10[0] == 0) || (iVar6 = 0, local_res18[0] == 0)) goto LAB_14000ff46;
  }
  RtlFreeUnicodeString(&local_38);
  puVar7 = (undefined8 *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8,0x60);
  if (puVar7 == (undefined8 *)0x0) {
    RtlFreeUnicodeString(&local_28);
    return -0x3fffffe9;
  }
  uVar2 = *(undefined4 *)((longlong)param_1 + 4);
  uVar3 = *(undefined4 *)(param_1 + 1);
  uVar4 = *(undefined4 *)((longlong)param_1 + 0xc);
  *(undefined4 *)(puVar7 + 4) = *(undefined4 *)param_1;
  *(undefined4 *)((longlong)puVar7 + 0x24) = uVar2;
  *(undefined4 *)(puVar7 + 5) = uVar3;
  *(undefined4 *)((longlong)puVar7 + 0x2c) = uVar4;
  *(undefined4 *)(puVar7 + 2) = (undefined4)local_28;
  *(undefined4 *)((longlong)puVar7 + 0x14) = local_28._4_4_;
  *(undefined4 *)(puVar7 + 3) = (undefined4)uStack_20;
  *(undefined4 *)((longlong)puVar7 + 0x1c) = uStack_20._4_4_;
  puVar7[7] = (ulonglong)local_res10[0] << 0x14;
  puVar7[6] = (ulonglong)local_res10[0] << 0x14;
  puVar7[8] = (ulonglong)local_res18[0] << 0x14;
  *(uint *)((longlong)puVar7 + 0x5c) = *(uint *)((longlong)puVar7 + 0x5c) & 0xfffffffd | iVar6 * 2;
  sVar5 = RtlUpcaseUnicodeChar(*(undefined2 *)(puVar7[3] + 8));
  *(short *)(puVar7[3] + 8) = sVar5;
  if (sVar5 == 0x3f) {
    if (SmpAnyDriveDescriptorCreated == '\x01') {
      SmpLogFailureString(0x140028810,0x420,param_1[1],0xc000000d);
      RtlFreeUnicodeString(&local_28);
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar7);
      return -0x3ffffff3;
    }
    *(uint *)((longlong)puVar7 + 0x5c) = *(uint *)((longlong)puVar7 + 0x5c) | 4;
    SmpAnyDriveDescriptorCreated = '\x01';
  }
  if (((*(byte *)((longlong)puVar7 + 0x5c) & 2) == 0) ||
     ((sVar5 != 0x3f && (sVar5 != SmpOsVolumeLetter)))) {
    puVar8 = &SmpPagingFileDescriptorList;
    if ((undefined8 **)*DAT_140032bb8 != &SmpPagingFileDescriptorList) goto LAB_1400100b6;
  }
  else {
    if ((undefined8 **)SmpPagingFileDescriptorList[1] == &SmpPagingFileDescriptorList) {
      *puVar7 = SmpPagingFileDescriptorList;
      puVar7[1] = &SmpPagingFileDescriptorList;
      SmpPagingFileDescriptorList[1] = puVar7;
      SmpPagingFileDescriptorList = puVar7;
      goto LAB_1400100ce;
    }
LAB_1400100b6:
    puVar9 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar8 = (undefined8 *)(*pcVar1)();
    DAT_140032bb8 = puVar9;
  }
  *puVar7 = puVar8;
  puVar7[1] = DAT_140032bb8;
  *DAT_140032bb8 = puVar7;
  DAT_140032bb8 = puVar7;
LAB_1400100ce:
  SmpNumberOfPagefileDescriptors = SmpNumberOfPagefileDescriptors + 1;
  return 0;
}



===== SmpCreatePagingFiles @ 1400100f4 =====

void SmpCreatePagingFiles(void)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  short sVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  undefined4 local_res10 [2];
  longlong local_res18;
  ushort local_28 [4];
  longlong lStack_20;
  
  local_res18 = 0;
  local_res10[0] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  lStack_20 = 0;
  SmpCreateDedicatedMemoryPagefile();
  uVar6 = SmpBuildFilesStringFromList((longlong *)&SmpExistingPageFilesList,local_28);
  uVar5 = (uint)uVar6;
  if ((int)uVar5 < 0) {
    uVar8 = 0xad2;
LAB_140010135:
    SmpLogFailure(0x140028a60,uVar8,uVar5);
    goto LAB_140010296;
  }
  SmpSaveOldPageFiles();
  for (puVar9 = SmpExistingPageFilesList; (undefined8 **)puVar9 != &SmpExistingPageFilesList;
      puVar9 = (undefined8 *)*puVar9) {
    SmpCheckForCrashDump(puVar9 + 2);
  }
  local_res10[0] = 2;
  iVar4 = NtSetSystemInformation(0x22,local_res10);
  if (iVar4 < 0) {
    SmpLogFailure(0x140028a60,0xaea,iVar4);
  }
  plVar10 = SmpPagingFileList;
  while ((longlong **)plVar10 != &SmpPagingFileList) {
    SmpCreatePagingFileDescriptor(plVar10 + 2);
    plVar1 = (longlong *)*plVar10;
    SmpFreeSavedRegistryEntry(plVar10);
    plVar10 = plVar1;
  }
  if ((SmpNumberOfPagefileDescriptors == 0) && (SmpRegistrySpecifierPresent == '\0')) {
    SmpCleanupStalePageFiles();
    goto LAB_140010296;
  }
  uVar5 = SmpCreateVolumeDescriptors();
  if ((int)uVar5 < 0) {
    uVar8 = 0xb1b;
    goto LAB_140010135;
  }
  SmpAdjustPagefileSizeforLowStorage();
  bVar2 = false;
  puVar9 = SmpPagingFileDescriptorList;
  bVar3 = false;
  if ((undefined8 **)SmpPagingFileDescriptorList == &SmpPagingFileDescriptorList) {
LAB_14001023d:
    uVar6 = SmpCreateEmergencyPagingFile();
    if (-1 < (int)uVar6) goto LAB_140010246;
  }
  else {
    do {
      iVar4 = SmpProcessPagefileDescriptor((longlong)puVar9);
      puVar9 = (undefined8 *)*puVar9;
      bVar2 = bVar3;
      if (-1 < iVar4) {
        bVar2 = true;
      }
      bVar3 = bVar2;
    } while ((undefined8 **)puVar9 != &SmpPagingFileDescriptorList);
    if (!bVar2) goto LAB_14001023d;
LAB_140010246:
    iVar4 = SmpCreateWorkingSetSwapPagingFile(&local_res18);
    if (iVar4 < 0) {
      if ((iVar4 == -0x3fffff8e) && (SmpNumberOfPagefilesCreated == 1)) {
        sVar7 = 0x3f;
        goto LAB_14001027a;
      }
    }
    else if ((*(byte *)(local_res18 + 0x10) & 0x10) != 0) {
      sVar7 = *(short *)(local_res18 + 0x1c);
LAB_14001027a:
      SmpEnableSwapOnPagingFiles(&SmpPagingFileDescriptorList,sVar7);
    }
  }
  SmpCleanupStalePageFiles();
  SmpRecordCreatedPageFiles(!bVar2,(short *)local_28);
LAB_140010296:
  if (lStack_20 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lStack_20);
  }
  return;
}



===== SmpCreateVolumeDescriptor @ 1400102d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpCreateVolumeDescriptor(ushort param_1,longlong param_2,longlong param_3)

{
  uint *puVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined4 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  bool bVar13;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  longlong local_98;
  int local_90;
  undefined4 local_8c;
  undefined8 uStack_88;
  longlong local_80 [3];
  undefined8 local_68;
  undefined8 local_60;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  longlong local_38;
  longlong lStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_4c = 0;
  local_80[0] = 0;
  uStack_88 = 0;
  local_8c = 0;
  local_90 = 0;
  local_60 = 0;
  local_98 = 0;
  local_68 = 0x30;
  local_80[1] = 0;
  local_80[2] = 0;
  local_28 = 0;
  local_38 = 0;
  lStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_50 = 0x40;
  local_58 = param_3;
  iVar4 = NtOpenFile(&local_98,0x120089,&local_68);
  if (iVar4 < 0) {
    uVar8 = 0x52c;
  }
  else {
    iVar4 = NtQueryVolumeInformationFile(local_98,local_80 + 1);
    if (iVar4 < 0) {
      uVar8 = 0x53d;
    }
    else {
      if ((uStack_88 & 0x1700000000) != 0) {
        if (param_3 == 0) {
          lVar10 = 0;
        }
        else {
          lVar10 = *(longlong *)(param_3 + 8);
        }
        SmpLogFailureString(0x1400288d0,0x54b,lVar10,iVar4);
        puVar12 = auStackY_c8;
        goto LAB_1400105d2;
      }
      local_60 = 0;
      local_68 = CONCAT44(local_68._4_4_,0x30);
      local_50 = 0x40;
      local_48 = 0;
      uStack_40 = 0;
      local_58 = param_2;
      iVar4 = NtOpenFile(local_80,0x100080,&local_68);
      if (iVar4 < 0) {
        uVar8 = 0x563;
      }
      else {
        iVar4 = NtQueryVolumeInformationFile(local_80[0],local_80 + 1,&local_38);
        if (-1 < iVar4) {
          puVar5 = (undefined8 *)
                   RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8,0x30)
          ;
          if (puVar5 == (undefined8 *)0x0) {
            SmpLogFailure(0x1400288d0,0x583,0xc000009a);
            puVar12 = auStackY_c8;
            goto LAB_1400105d2;
          }
          bVar13 = param_1 == SmpOsVolumeLetter;
          puVar1 = (uint *)(puVar5 + 2);
          *(ushort *)((longlong)puVar5 + 0x1c) = param_1;
          *(undefined4 *)(puVar5 + 3) = uStack_88._4_4_;
          if (bVar13) {
            *puVar1 = *puVar1 | 1;
            SmpOsVolumeDescriptor = puVar5;
          }
          uVar6 = RtlQueryVolumeDiskSpeedPolicy(local_98,&local_90);
          if ((-1 < (int)uVar6) && (0x13 < local_90)) {
            *puVar1 = *puVar1 | 4;
          }
          cVar3 = SmpIsVolumeOnSCMDevice();
          if (cVar3 != '\0') {
            *puVar1 = *puVar1 | 0x40;
          }
          uVar9 = (ulonglong)local_28._4_4_ * (local_28 & 0xffffffff) * lStack_30;
          puVar5[4] = uVar9;
          puVar5[5] = (ulonglong)local_28._4_4_ * (local_28 & 0xffffffff) * local_38;
          if (uVar9 < 0x2000001) {
            lVar10 = 0;
          }
          else {
            lVar10 = uVar9 - 0x2000000;
          }
          puVar5[4] = lVar10;
          bVar13 = SmpIsVhdVolume(local_98);
          if (bVar13) {
            *(uint *)(puVar5 + 2) = *(uint *)(puVar5 + 2) | 2;
          }
          puVar11 = (undefined8 *)&local_8c;
          uVar6 = SmpGetVolumeDiskNumber(local_98,(undefined4 *)puVar11);
          puVar12 = auStackY_c8;
          if (-1 < (int)uVar6) {
            *(uint *)(puVar5 + 2) = *(uint *)(puVar5 + 2) | 8;
            *(undefined4 *)((longlong)puVar5 + 0x14) = local_8c;
          }
          puVar7 = &SmpVolumeDescriptorList;
          if ((*(byte *)(puVar5 + 2) & 1) == 0) {
            puVar11 = DAT_140032b98;
            if ((undefined8 **)*DAT_140032b98 != &SmpVolumeDescriptorList) goto LAB_1400105ba;
          }
          else {
            if ((undefined8 **)SmpVolumeDescriptorList[1] == &SmpVolumeDescriptorList) {
              *puVar5 = SmpVolumeDescriptorList;
              puVar5[1] = &SmpVolumeDescriptorList;
              SmpVolumeDescriptorList[1] = puVar5;
              puVar12 = auStackY_c8;
              SmpVolumeDescriptorList = puVar5;
              goto LAB_1400105d2;
            }
LAB_1400105ba:
            pcVar2 = (code *)swi(0x29);
            puVar7 = (undefined8 *)(*pcVar2)(3);
            puVar12 = auStackY_c0;
            DAT_140032b98 = puVar11;
          }
          *puVar5 = puVar7;
          puVar5[1] = DAT_140032b98;
          *DAT_140032b98 = puVar5;
          DAT_140032b98 = puVar5;
          goto LAB_1400105d2;
        }
        uVar8 = 0x574;
      }
    }
  }
  SmLogFailureInt(0x1400288d0,uVar8,(ulonglong)param_1,0,iVar4);
  puVar12 = auStackY_c8;
LAB_1400105d2:
  if (local_98 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400105e2;
    NtClose();
  }
  if (local_80[0] != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400105f7;
    NtClose();
  }
  *(undefined8 *)(puVar12 + -8) = 0x140010608;
  return;
}



===== SmpCreateVolumeDescriptors @ 140010624 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint SmpCreateVolumeDescriptors(void)

{
  uint uVar1;
  ushort uVar2;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  undefined8 local_78;
  longlong lStack_70;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  short local_30 [8];
  short local_20 [8];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_88 = 0;
  local_38 = 0;
  local_68 = 0;
  lStack_60 = 0;
  local_78 = 0;
  lStack_70 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar1 = NtQueryInformationProcess(0xffffffffffffffff,0x17,&local_58,0x24);
  if ((int)uVar1 < 0) {
    SmpLogFailure(0x1400288f0,0x62b,uVar1);
  }
  else {
    RtlStringCbCopyW(local_30,0x10,0x140028910);
    RtlInitUnicodeStringEx(&local_68,local_30);
    RtlStringCbCopyW(local_20,0x10,0x140028920);
    RtlInitUnicodeStringEx(&local_78,local_20);
    uVar1 = 0x43;
    do {
      uVar2 = (ushort)uVar1;
      if ((((uint)local_58 >> (uVar1 - 0x41 & 0x1f) & 1) != 0) &&
         ((SmpPagefileOnOsVolume != 1 || (uVar2 == SmpOsVolumeLetter)))) {
        *(ushort *)(lStack_60 + 8) = uVar2;
        *(ushort *)(lStack_70 + 8) = uVar2;
        SmpCreateVolumeDescriptor(uVar2,(longlong)&local_68,(longlong)&local_78);
      }
      uVar1 = (uint)(ushort)(uVar2 + 1);
    } while ((ushort)(uVar2 + 1) < 0x5b);
    uVar1 = -(uint)((undefined8 **)SmpVolumeDescriptorList == &SmpVolumeDescriptorList) & 0xc00000e9
    ;
  }
  return uVar1;
}



===== SmpCreateWorkingSetSwapPagingFile @ 14001078c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpCreateWorkingSetSwapPagingFile(undefined8 *param_1)

{
  undefined8 *puVar1;
  short sVar2;
  int iVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined1 auStackY_568 [32];
  uint local_538;
  uint local_534;
  uint local_530;
  uint local_52c;
  ulonglong local_528;
  undefined8 local_520;
  undefined1 *local_518;
  undefined4 local_510;
  undefined4 local_50c;
  undefined8 local_508 [2];
  ulonglong local_4f8;
  longlong lStack_4f0;
  ulonglong local_4e8;
  ulonglong local_4e0 [2];
  wchar_t *local_4d0;
  ulonglong local_4c8;
  wchar_t *local_4c0;
  ulonglong local_4b8;
  longlong lStack_4b0;
  ulonglong local_4a8 [2];
  undefined8 local_498;
  undefined8 uStack_490;
  ulonglong *local_488;
  undefined8 uStack_480;
  undefined8 local_478;
  ulonglong uStack_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  uint local_440;
  undefined1 auStack_43c [516];
  wchar_t local_238 [264];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_568;
  local_4e0[1] = 0x20001e;
  local_534 = 0;
  local_530 = 0;
  local_478 = 0;
  uStack_470 = uStack_470 & 0xffffffff00000000;
  local_4e0[0] = 0;
  local_4d0 = L"SwapfileControl";
  local_4e8 = 0;
  local_4c0 = L"SwapFile";
  local_508[0] = 0;
  local_4c8 = 0x120010;
  local_4b8 = 0;
  lStack_4b0 = 0;
  local_538 = 0;
  local_4f8 = 0;
  lStack_4f0 = 0;
  local_52c = 0;
  local_498 = 0;
  uStack_490 = 0;
  local_510 = 0;
  local_488 = (ulonglong *)0x0;
  uStack_480 = 0;
  local_520 = (ulonglong)(uint)local_520;
  local_468 = 0;
  uStack_460 = 0;
  local_50c = 0;
  local_4a8[0] = 0;
  local_4a8[1] = 0;
  local_458 = 0;
  uStack_450 = 0;
  RtlInitUnicodeString(local_4e0 + 5,0);
  if (SmpClientSku == '\0') {
    iVar3 = -0x3fffff45;
    goto LAB_140010c25;
  }
  iVar3 = NtQueryValueKey(SmpMmKey,local_4e0 + 1,4,&local_458);
  if ((((iVar3 < 0) || ((int)local_458 != 4)) || (local_458._4_4_ != 4)) || ((int)uStack_450 != 0))
  {
    iVar3 = NtQueryValueKey(SmpMmKey,local_4e0 + 3,2);
    if ((iVar3 < 0) || (0x204 < local_440)) {
      if (SmpMaxSwapFileSize != 0) {
        if (SmpOsVolumeDescriptor == (undefined8 *)0x0) {
          iVar3 = -0x3ffffddb;
          goto LAB_140010c25;
        }
        uVar4 = RtlStringCbPrintfW(local_238,0x208,L"\\??\\%c:\\%s",
                                   (ulonglong)*(ushort *)((longlong)SmpOsVolumeDescriptor + 0x1c));
        iVar3 = (int)uVar4;
        if (iVar3 < 0) goto LAB_140010c25;
        RtlInitUnicodeString(&local_4f8,local_238);
        local_528 = (-(ulonglong)((*(uint *)(SmpOsVolumeDescriptor + 2) & 0x20) != 0) &
                    0xfffffffff1000000) + 0x10000000;
        if (SmpMaxSwapFileSize == 0xffffffffffffffff) {
          local_520 = (ulonglong)(SmpMemorySize * 3) >> 1;
        }
        else {
          local_520 = SmpMaxSwapFileSize;
          if (SmpMaxSwapFileSize <= local_528) {
            local_528 = SmpMaxSwapFileSize;
          }
        }
        if ((ulonglong)SmpOsVolumeDescriptor[5] / 10 <= local_520) {
          local_520 = (ulonglong)SmpOsVolumeDescriptor[5] / 10;
        }
        if (local_520 <= local_528) {
          local_520 = local_528;
        }
        puVar8 = SmpOsVolumeDescriptor;
LAB_140010b11:
        SmpUpdatePagingFileSizes(&local_528,&local_520);
        local_488 = &local_4f8;
        local_498 = CONCAT44(local_498._4_4_,0x30);
        uStack_490 = 0;
        uStack_480 = CONCAT44(uStack_480._4_4_,0x40);
        local_478 = 0;
        uStack_470 = 0;
        iVar3 = NtOpenFile(local_508,0xc0100000,&local_498,&local_468);
        if (-1 < iVar3) {
          SmpTrimPagingFileExtents(local_508[0],(longlong)&local_4f8);
          NtClose(local_508[0]);
        }
        iVar3 = -0x80000000;
        if (((((*(byte *)(puVar8 + 2) & 8) != 0) &&
             (uVar4 = SmpCheckHybridPriority
                                (*(uint *)((longlong)puVar8 + 0x14),&local_538,&local_52c),
             -1 < (int)uVar4)) && (local_52c != 0)) && ((local_538 & 0xfffffff0) == 0)) {
          iVar3 = (local_538 | 0xffffffe0) << 0x1a;
        }
        local_4e0[0] = local_528;
        local_4e8 = local_520;
        iVar3 = NtCreatePagingFile(&local_4f8,local_4e0,&local_4e8,iVar3);
        if (iVar3 < 0) {
          SmpLogFailure(0x1400289a0,0x7ca,iVar3);
        }
        else {
          SmpWsSwapPagefileCreated = 1;
          *param_1 = puVar8;
        }
        goto LAB_140010c25;
      }
    }
    else {
      local_520._0_4_ = CONCAT22((short)local_440,(short)local_440);
      local_518 = auStack_43c;
      iVar3 = SmpParseCommandLine(&local_520,(uint *)0x0,local_4e0 + 5,0,local_4a8);
      if (iVar3 < 0) goto LAB_140010c25;
      local_4f8 = local_4b8;
      lStack_4f0 = lStack_4b0;
      iVar3 = SmpParseSwapOrPageFileArguments((ushort *)local_4a8,&local_534,&local_530);
      RtlFreeUnicodeString(local_4a8);
      if (iVar3 < 0) goto LAB_140010c25;
      if ((local_534 != 0) && (local_530 != 0)) {
        uVar7 = 0;
        local_528 = (ulonglong)local_534 << 0x14;
        local_520 = (ulonglong)local_530 << 0x14;
        uVar5 = 0x3f;
        if ((ushort)local_4f8 != 0) {
          do {
            if (*(short *)(lStack_4f0 + uVar7 * 2) == 0x3a) break;
            uVar5 = *(undefined2 *)(lStack_4f0 + uVar7 * 2);
            uVar6 = (int)uVar7 + 1;
            uVar7 = (ulonglong)uVar6;
          } while ((ushort)local_4f8 != uVar6);
          if ((uint)(ushort)local_4f8 != (uint)uVar7) {
            sVar2 = RtlUpcaseUnicodeChar(uVar5);
            puVar1 = SmpVolumeDescriptorList;
            do {
              puVar8 = puVar1;
              if ((undefined8 **)puVar8 == &SmpVolumeDescriptorList) goto LAB_140010a0c;
              puVar1 = (undefined8 *)*puVar8;
            } while (*(short *)((longlong)puVar8 + 0x1c) != sVar2);
            goto LAB_140010b11;
          }
        }
LAB_140010a0c:
        iVar3 = -0x3fffffcc;
        goto LAB_140010c25;
      }
    }
  }
  iVar3 = -0x3fffff8e;
LAB_140010c25:
  RtlFreeUnicodeString(local_4e0 + 5);
  return iVar3;
}



===== SmpDedicatedMemoryCachingCallback @ 140010c70 =====

undefined8 SmpDedicatedMemoryCachingCallback(void)

{
  SmpEnableCachingOnDedicatedMemoryWorker();
  return 0;
}



===== SmpDeletePagingFile @ 140010c88 =====

int SmpDeletePagingFile(undefined8 param_1)

{
  int iVar1;
  undefined1 local_res8 [8];
  undefined8 local_res10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res10 = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_48 = 0;
  uStack_40 = 0;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = param_1;
  iVar1 = NtOpenFile(&local_res10,0x10000,&local_38,&local_48,7,0x40);
  if (iVar1 < 0) {
    SmpLogFailure(0x140028b90,0xfa2,iVar1);
  }
  else {
    local_res8[0] = 1;
    iVar1 = NtSetInformationFile(local_res10,&local_48,local_res8,1,0xd);
    SmpLogFailure(0x140028b90,(iVar1 >> 0x1f & 4U) + 0xfb1,iVar1);
    NtClose(local_res10);
  }
  return iVar1;
}



===== SmpEnableCachingOnDedicatedMemoryWorker @ 140010d7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpEnableCachingOnDedicatedMemoryWorker(void)

{
  longlong lVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint *puVar7;
  undefined1 auStack_1a8 [32];
  undefined4 local_188;
  undefined4 *local_180;
  undefined4 local_178 [2];
  undefined8 local_170;
  undefined8 uStack_168;
  longlong local_160;
  undefined4 local_158 [2];
  undefined8 local_150;
  undefined8 local_148;
  wchar_t *local_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined1 local_128 [4];
  undefined4 local_124;
  undefined4 local_120;
  ulonglong local_f8;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_158[0] = 0;
  memset(local_128,0,0xf0);
  local_150 = 0;
  local_160 = 0;
  local_148 = 0x3c003a;
  local_178[0] = 0;
  local_140 = L"DisableDedicatedMemoryCaching";
  local_180 = local_158;
  lVar6 = 0;
  local_188 = 0x10;
  local_170 = 0;
  uStack_168 = 0;
  local_138 = 0;
  uStack_130 = 0;
  iVar2 = NtQueryValueKey(SmpMmKey,&local_148,4,&local_138);
  if ((((-1 < iVar2) && ((int)local_138 == 4)) && (local_138._4_4_ == 4)) && ((int)uStack_130 == 1))
  {
    return -0x3fffffff;
  }
  while( true ) {
    local_188 = 4;
    iVar2 = NtManagePartition(0xfffffffffffffffe,0,9,local_178);
    if (iVar2 != -0x3fffffdd) {
      return iVar2;
    }
    puVar3 = (uint *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                     local_178[0]);
    if (puVar3 == (uint *)0x0) {
      return -0x3fffff66;
    }
    local_188 = local_178[0];
    iVar2 = NtManagePartition(0xfffffffffffffffe,0,9,puVar3);
    if (-1 < iVar2) break;
    if (iVar2 != -0x3fffffdd) goto LAB_14001105b;
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar3);
  }
  puVar7 = (uint *)0x0;
  uVar5 = 0;
  for (puVar4 = puVar3; *puVar4 != 0; puVar4 = (uint *)((longlong)puVar4 + (ulonglong)*puVar4)) {
    local_160 = 0;
    local_170 = *(undefined8 *)(puVar4 + 6);
    uStack_168 = 0x1f000300000000;
    local_188 = 0x18;
    iVar2 = NtManagePartition(0xfffffffffffffffe,0,10,&local_170);
    if (-1 < iVar2) {
      memset(local_128,0,0xf0);
      local_124 = 0xffffffff;
      local_120 = 0xffffffff;
      local_188 = 0xf0;
      iVar2 = NtManagePartition(local_160,0,0,local_128);
      NtClose(local_160);
      if (iVar2 < 0) goto LAB_14001105b;
      if (uVar5 < local_f8) {
        uVar5 = local_f8;
        puVar7 = puVar4;
      }
    }
  }
  if (puVar7 == (uint *)0x0) {
    iVar2 = -0x3ffffddb;
  }
  else {
    local_188 = 0x18;
    local_160 = 0;
    local_170 = *(undefined8 *)(puVar7 + 6);
    uStack_168 = 0x1f000300000000;
    iVar2 = NtManagePartition(0xfffffffffffffffe,0,10,&local_170);
    lVar1 = local_160;
    if (-1 < iVar2) {
      local_150 = 4;
      local_188 = 8;
      iVar2 = NtManagePartition(local_160,0,6,&local_150);
      lVar6 = lVar1;
      if (-1 < iVar2) {
        iVar2 = 0;
      }
    }
  }
LAB_14001105b:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar3);
  if (lVar6 != 0) {
    NtClose(lVar6);
  }
  return iVar2;
}



===== SmpGetPagingFileSize @ 1400110cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpGetPagingFileSize(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 5;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = NtQueryInformationFile(0,&local_38,&local_28,0x18);
  lVar2 = 0;
  if (iVar1 < 0) {
    if (param_2 != 0) {
      lVar2 = *(longlong *)(param_2 + 8);
    }
    SmpLogFailureString(0x140028ba8,0xfe7,lVar2,iVar1);
  }
  else {
    *param_3 = local_28;
    iVar1 = 0;
  }
  return iVar1;
}



===== SmpIsRamdiskBoot @ 140011184 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpIsRamdiskBoot(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 auStack_2d8 [32];
  undefined4 local_2b8;
  undefined4 *local_2b0;
  undefined4 local_2a8 [2];
  longlong local_2a0 [2];
  wchar_t *local_290;
  longlong local_288;
  wchar_t *local_280;
  longlong local_278;
  wchar_t *local_270;
  longlong local_268 [4];
  longlong *local_248;
  undefined4 local_240;
  undefined4 local_23c;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined1 local_228 [4];
  int local_224;
  undefined1 local_21c [516];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_2d8;
  local_23c = 0;
  local_2a0[0] = 0;
  local_2a8[0] = 0;
  local_268[3] = 0;
  local_290 = L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control";
  local_268[2] = 0x30;
  local_280 = L"SystemBootDevice";
  local_270 = L"ramdisk";
  local_248 = local_2a0 + 1;
  local_2a0[1] = 0x660064;
  local_288 = 0x220020;
  local_278 = 0x10000e;
  local_268[0] = 0;
  local_268[1] = 0;
  local_240 = 0x40;
  local_238 = 0;
  uStack_230 = 0;
  iVar2 = NtOpenKey(local_2a0,0x20019,local_2a0 + 9);
  if (-1 < iVar2) {
    local_2b0 = local_2a8;
    local_2b8 = 0x210;
    local_2a8[0] = 0x210;
    iVar2 = NtQueryValueKey(local_2a0[0],local_2a0 + 3,2,local_228);
    if (-1 < iVar2) {
      if (local_224 == 1) {
        RtlInitUnicodeString(local_2a0 + 7,local_21c);
        uVar1 = RtlPrefixUnicodeString(local_2a0 + 5,local_2a0 + 7,1);
        *param_1 = uVar1;
        iVar2 = 0;
      }
      else {
        iVar2 = -0x3ffffddb;
      }
    }
  }
  if (local_2a0[0] != 0) {
    NtClose();
  }
  return iVar2;
}



===== SmpPagefileInitialize @ 140011310 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpPagefileInitialize(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  undefined1 auStack_1d8 [32];
  uint local_1b8 [2];
  undefined8 local_1b0;
  wchar_t *local_1a8;
  undefined8 local_1a0;
  wchar_t *local_198;
  undefined8 local_190;
  wchar_t *local_188;
  undefined4 local_180;
  undefined4 local_17c;
  undefined8 local_178;
  undefined8 *local_170;
  undefined4 local_168;
  undefined4 local_164;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined4 local_138;
  undefined1 local_134 [278];
  char local_1e;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1d8;
  local_1a0 = 0xaa00a8;
  local_198 = 
  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management";
  local_190 = 0x80007e;
  local_188 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl";
  local_164 = 0;
  local_17c = 0;
  local_140 = 0;
  DAT_140032bb8 = &SmpPagingFileDescriptorList;
  SmpPagingFileDescriptorList = &SmpPagingFileDescriptorList;
  DAT_140032b98 = &SmpVolumeDescriptorList;
  SmpVolumeDescriptorList = &SmpVolumeDescriptorList;
  local_150 = 0;
  uStack_148 = 0;
  NtQuerySystemInformation(0xb8,&local_150,0x18);
  SmpMemorySize = local_150;
  SmpHighestPhysicalAddress = local_140;
  puVar2 = (undefined2 *)RtlGetNtSystemRoot();
  SmpOsVolumeLetter = RtlUpcaseUnicodeChar(*puVar2);
  local_178 = 0;
  local_170 = &local_1a0;
  local_168 = 0x40;
  local_180 = 0x30;
  local_160 = 0;
  uStack_158 = 0;
  iVar1 = NtOpenKey(&SmpMmKey,0x2001f,&local_180);
  if (iVar1 < 0) {
    uVar6 = 0x247;
  }
  else {
    local_178 = 0;
    local_170 = &local_190;
    local_180 = 0x30;
    local_168 = 0x40;
    puVar4 = &SmpCrashDumpKey;
    local_160 = 0;
    uStack_158 = 0;
    iVar1 = NtOpenKey(&SmpCrashDumpKey,0x2001f,&local_180);
    if (-1 < iVar1) {
      local_1b8[0] = 0;
      local_1b0 = 0x220020;
      local_1a8 = L"CrashDumpEnabled";
      uVar3 = SmpQueryDwordFromRegistry(puVar4,&local_1b0,4,local_1b8);
      uVar5 = (ulonglong)local_1b8[0];
      if ((int)uVar3 < 0) {
        uVar5 = 4;
      }
      SmpDumpType = (undefined4)uVar5;
      SmpUseDedicatedDumpFile = SmpQueryDedicatedDumpSetting();
      local_1b8[0] = 0;
      local_1b0 = 0x180016;
      local_1a8 = L"FilterPages";
      uVar3 = SmpQueryDwordFromRegistry(uVar5,&local_1b0,0,local_1b8);
      SmpUseFilterPagesDumpFile = 0;
      if (-1 < (int)uVar3) {
        SmpUseFilterPagesDumpFile = 0;
        if (local_1b8[0] != 0) {
          SmpUseFilterPagesDumpFile = 1;
        }
      }
      SmpForceCopyDumpFile = (byte)(SmpSystemWriteConstraintInfo >> 2) & 1;
      memset(local_134,0,0x118);
      local_138 = 0x11c;
      iVar1 = RtlGetVersion(&local_138);
      if ((-1 < iVar1) && (local_1e == '\x01')) {
        SmpClientSku = 1;
      }
      return 0;
    }
    uVar6 = 600;
  }
  SmpLogFailure(0x1400287d0,uVar6,iVar1);
  return iVar1;
}



===== SmpParseSwapOrPageFileArguments @ 1400115cc =====

int SmpParseSwapOrPageFileArguments(ushort *param_1,undefined4 *param_2,undefined4 *param_3)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  int iVar4;
  ushort uVar5;
  short *psVar6;
  undefined4 uVar7;
  
  *param_2 = 0;
  *param_3 = 0;
  lVar2 = *(longlong *)(param_1 + 4);
  if (lVar2 == 0) {
    return 0;
  }
  uVar5 = 0;
  while( true ) {
    if (*param_1 >> 1 <= uVar5) {
      return 0;
    }
    if ((0x30 < *(ushort *)(lVar2 + (ulonglong)uVar5 * 2)) ||
       ((0x1000100000200U >> ((ulonglong)*(ushort *)(lVar2 + (ulonglong)uVar5 * 2) & 0x3f) & 1) == 0
       )) break;
    uVar5 = uVar5 + 1;
  }
  iVar4 = RtlUnicodeStringToInteger(param_1,0,param_2);
  if (iVar4 < 0) {
    uVar7 = 0x1314;
  }
  else {
    psVar3 = *(short **)(param_1 + 4);
    psVar6 = psVar3;
    do {
      sVar1 = *psVar6;
      if (sVar1 == 0) {
        return 0;
      }
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0x20);
    *(short **)(param_1 + 4) = psVar6;
    *param_1 = *param_1 + ((short)psVar3 - (short)psVar6);
    param_1[1] = *param_1;
    iVar4 = RtlUnicodeStringToInteger(param_1,0,param_3);
    *(short **)(param_1 + 4) = psVar3;
    if (-1 < iVar4) {
      return 0;
    }
    uVar7 = 0x132a;
  }
  SmpLogFailure(0x140028ca8,uVar7,iVar4);
  return iVar4;
}



===== SmpRecordCreatedPageFiles @ 1400116e4 =====

ulonglong SmpRecordCreatedPageFiles(char param_1,short *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 local_res18 [2];
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_18 = 0x240022;
  local_10 = L"ExistingPageFiles";
  local_28 = 0x1a0018;
  local_20 = L"TempPageFile";
  bVar1 = false;
  local_38 = 0;
  uStack_30 = 0;
  uVar4 = SmpBuildFilesStringFromList(&SmpPagingFileDescriptorList,(ushort *)&local_38);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  if ((param_2 != (short *)0x0) &&
     ((*param_2 != (short)local_38 ||
      (uVar4 = RtlCompareMemory(*(undefined8 *)(param_2 + 4),uStack_30,local_38 & 0xffff),
      (local_38 & 0xffff) != uVar4)))) {
    bVar1 = true;
  }
  if (param_1 == '\0') {
    NtDeleteValueKey(SmpMmKey,&local_28);
  }
  else {
    local_res18[0] = 1;
    iVar2 = NtSetValueKey(SmpMmKey,&local_28,0,4,local_res18,4);
    if (iVar2 < 0) {
      SmpLogFailure(0x140028c68,0x1177,iVar2);
    }
  }
  uVar3 = NtSetValueKey(SmpMmKey,&local_18,0,7,uStack_30,(short)local_38);
  if (bVar1) {
    NtFlushKey(SmpMmKey);
  }
  if ((int)uVar3 < 0) {
    SmpLogFailure(0x140028c68,0x118a,uVar3);
  }
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,uStack_30);
  return (ulonglong)uVar3;
}



===== SmpTrimPagingFileExtents @ 14001187c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpTrimPagingFileExtents(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined4 local_60;
  undefined4 *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  lVar2 = 0;
  local_24 = 1;
  local_40 = 0;
  local_58 = &local_28;
  local_48 = 0;
  local_50 = 0x18;
  local_28 = 0;
  local_68 = &local_38;
  local_18 = 0xffffffffffffffff;
  local_60 = 0x98208;
  local_38 = 0;
  uStack_30 = 0;
  local_20 = 0;
  iVar1 = NtFsControlFile(0,0,0,0);
  if (iVar1 < 0) {
    if (param_2 != 0) {
      lVar2 = *(longlong *)(param_2 + 8);
    }
    SmpLogFailureString(0x140028bc0,0x102e,lVar2,iVar1);
  }
  return iVar1;
}



===== RtlUnicodeStringPrintf @ 140011950 =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  if ((((((*param_1 & 1) == 0) && (uVar1 = param_1[1], (uVar1 & 1) == 0)) && (*param_1 <= uVar1)) &&
      (uVar1 != 0xffff)) &&
     ((uVar4 = 0, *(longlong *)(param_1 + 4) != 0 || ((*param_1 == 0 && (uVar1 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar2 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar2 < 0) || (uVar3 = (longlong)iVar2, _Count < (ulonglong)(longlong)iVar2)) {
      uVar4 = 0x80000005;
      uVar3 = _Count;
    }
    *param_1 = (short)uVar3 * 2;
  }
  else {
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== SmpCheckForCrashDump @ 1400119ec =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool SmpCheckForCrashDump(undefined8 *param_1)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStackY_2148 [32];
  undefined8 local_20f8;
  undefined8 local_20f0;
  undefined8 local_20e8;
  wchar_t *local_20e0;
  undefined8 local_20d8;
  wchar_t *local_20d0;
  ushort local_20c8 [8];
  undefined8 local_20b8;
  wchar_t *local_20b0;
  undefined8 local_20a8;
  wchar_t *local_20a0;
  undefined8 local_2098;
  undefined8 local_2090;
  undefined8 *local_2088;
  undefined8 local_2080;
  undefined8 local_2078;
  undefined8 uStack_2070;
  ushort local_2068 [12];
  undefined8 local_2050;
  undefined8 local_2048;
  undefined8 uStack_2040;
  int local_2038;
  int local_2034;
  ulonglong local_1098;
  byte local_fe8;
  ulonglong local_38;
  undefined8 local_30;
  
  local_30 = 0x140011a10;
  local_38 = __security_cookie ^ (ulonglong)auStackY_2148;
  memset(&local_2038,0,0x2000);
  local_2098 = 0x30;
  local_20d0 = 
  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\MachineCrash";
  local_2080 = 0x40;
  local_20a0 = L"TempDestination";
  local_20d8 = 0x9a0098;
  local_20b0 = L"DumpFile";
  local_20a8 = 0x20001e;
  local_2068[8] = 0;
  local_2068[9] = 0;
  local_2068[10] = 0;
  local_2068[0xb] = 0;
  local_20b8 = 0x120010;
  local_20f8 = 0xffffffffffffffff;
  local_2048 = 0;
  uStack_2040 = 0;
  local_20f0 = 0xffffffffffffffff;
  local_2068[0] = 0;
  local_2068[1] = 0;
  local_2068[2] = 0;
  local_2068[3] = 0;
  local_2068[4] = 0;
  local_2068[5] = 0;
  local_2068[6] = 0;
  local_2068[7] = 0;
  bVar1 = false;
  local_20c8[0] = 0;
  local_20c8[1] = 0;
  local_20c8[2] = 0;
  local_20c8[3] = 0;
  local_20c8[4] = 0;
  local_20c8[5] = 0;
  local_20c8[6] = 0;
  local_20c8[7] = 0;
  local_2090 = 0;
  local_2078 = 0;
  uStack_2070 = 0;
  local_2088 = param_1;
  iVar2 = NtOpenFile(&local_20f8,0xc0150000,&local_2098,&local_2048);
  if (iVar2 < 0) {
    bVar1 = false;
  }
  else {
    iVar2 = NtReadFile(local_20f8,0,0,0);
    if (((-1 < iVar2) && (local_2038 == 0x45474150)) && (local_2034 == 0x34365544)) {
      if ((local_fe8 & 4) != 0) {
        local_20e8 = 0x220020;
        local_20e0 = L"PagefileTooSmall";
        local_2050 = _DAT_7ffe0014;
        NtSetValueKey(SmpCrashDumpKey,&local_20e8,0,0xb);
      }
      uVar3 = SmpGetCrashParameters((longlong)local_2068);
      if (((-1 < (int)uVar3) &&
          (uVar3 = SmpGetDumpDestination
                             ((longlong)&local_2038,local_2068,local_20f8,(longlong)param_1,
                              (undefined8 *)local_20c8), -1 < (int)uVar3)) &&
         (iVar2 = SmpSavePageFile(local_20f8,local_20c8,local_1098,
                                  (uint)(SmpForceCopyDumpFile == '\0')), -1 < iVar2)) {
        bVar1 = true;
      }
    }
    NtClose(local_20f8);
    local_20f8 = 0xffffffffffffffff;
    if (bVar1) {
      local_2088 = &local_20d8;
      local_2098 = CONCAT44(local_2098._4_4_,0x30);
      local_2090 = 0;
      local_2078 = 0;
      uStack_2070 = 0;
      local_2080 = CONCAT44(local_2080._4_4_,0x40);
      iVar2 = NtCreateKey(&local_20f0,0x2001f,&local_2098,0);
      if (-1 < iVar2) {
        NtSetValueKey(local_20f0,&local_20b8,0,1);
        NtSetValueKey(local_20f0,&local_20a8,0,4);
        NtClose(local_20f0);
        local_20f0 = 0xffffffffffffffff;
      }
    }
  }
  if (local_2068[0] != 0) {
    RtlFreeUnicodeString(local_2068);
  }
  return bVar1;
}



===== SmpCopyFile @ 140011d40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpCopyFile(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 auStackY_168 [32];
  undefined1 local_108 [8];
  ulonglong local_100;
  longlong local_f8;
  longlong local_f0 [6];
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  ulonglong uStack_98;
  undefined8 local_88 [4];
  ulonglong *local_68;
  undefined8 local_60;
  longlong *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_168;
  local_a0 = 0;
  uStack_98 = uStack_98 & 0xffffffff00000000;
  local_f0[3] = 0;
  local_108[0] = 0;
  uVar5 = 0x100000;
  local_f8 = 0;
  local_f0[0] = 0;
  local_100 = 0;
  local_f0[4] = 0x100000;
  uVar6 = 1;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_f0[1] = 0;
  local_f0[2] = 0;
  iVar1 = NtAllocateVirtualMemory(0xffffffffffffffff,local_f0,0,local_f0 + 4);
  uVar2 = 0;
  if (iVar1 < 0) {
LAB_140011e14:
    param_3 = uVar2;
  }
  else {
    if (param_3 == 0) {
      iVar1 = SmpQueryFileSize(param_1,&local_100);
      uVar2 = local_100;
      param_3 = local_100;
      if (iVar1 < 0) goto LAB_140011e14;
    }
    if (param_3 == 0) {
      iVar1 = -0x3fffff68;
      uVar2 = param_3;
      goto LAB_140011e14;
    }
    local_c0 = CONCAT44(local_c0._4_4_,0x30);
    uStack_a8 = CONCAT44(uStack_a8._4_4_,0x40);
    uVar6 = 1;
    if (param_3 % (ulonglong)DAT_140032b08 != 0) {
      uVar6 = DAT_140032b08;
    }
    uStack_b8 = 0;
    local_a0 = 0;
    uStack_98 = 0;
    local_b0 = param_2;
    iVar1 = NtCreateFile(&local_f8,0xc0150000,&local_c0,local_f0 + 1);
    if ((-1 < iVar1) && (iVar1 = SmpSetDumpSecurityAndAttributes(local_f8), -1 < iVar1)) {
      for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + uVar5) {
        local_f0[3] = uVar2;
        iVar1 = NtReadFile(param_1,0,0,0);
        if (iVar1 < 0) break;
        if (local_f0[2] != uVar5) {
          if ((param_3 - uVar2 < uVar5) && (local_f0[2] == param_3 - uVar2)) {
            uVar5 = (ulonglong)(((int)param_3 - (int)uVar2) + -1 + uVar6 & -uVar6);
            goto LAB_140012068;
          }
LAB_1400120c2:
          iVar1 = -0x3fffffff;
          break;
        }
LAB_140012068:
        iVar1 = NtWriteFile(local_f8);
        if (iVar1 < 0) break;
        if (local_f0[2] != uVar5) goto LAB_1400120c2;
      }
    }
  }
  if (local_f8 == 0) goto LAB_140011ef2;
  if (iVar1 < 0) {
LAB_140011e71:
    uVar4 = 1;
    local_108[0] = 1;
    puVar3 = local_108;
    NtSetInformationFile(local_f8,local_f0 + 1);
    if (5 < DAT_140030e48) {
      local_100 = CONCAT44(local_100._4_4_,iVar1);
      local_68 = &local_100;
      local_60 = 4;
      local_58 = local_f0 + 5;
      local_50 = 8;
      local_f0[5] = param_3;
      _tlgWriteTransfer_EtwEventWriteTransfer(4,&DAT_14002bf99,puVar3,uVar4,4,local_88);
    }
  }
  else if ((param_3 != 0) && (uVar6 != 1)) {
    local_100 = param_3;
    iVar1 = NtSetInformationFile(local_f8,local_f0 + 1,&local_100,8);
    if (iVar1 < 0) goto LAB_140011e71;
  }
  NtClose(local_f8);
LAB_140011ef2:
  if (local_f0[0] != 0) {
    local_f0[4] = 0;
    NtFreeVirtualMemory(0xffffffffffffffff,local_f0,local_f0 + 4,0x8000);
  }
  return iVar1;
}



===== SmpCreateTempFile @ 1400120d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SmpCreateTempFile(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  char cVar1;
  bool bVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStack_288 [32];
  undefined8 local_268;
  uint local_260;
  undefined8 local_258;
  undefined8 uStack_250;
  wchar_t local_248 [264];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_288;
  local_258 = 0;
  uStack_250 = 0;
  lVar5 = (ulonglong)_DAT_7ffe0004 * _DAT_7ffe0320;
  uVar4 = 0;
  while( true ) {
    if (99 < uVar4) {
      return 0xc0000001;
    }
    local_260 = (int)((ulonglong)lVar5 >> 0x18) + uVar4 & 0xffff;
    local_268 = param_2;
    uVar3 = RtlStringCbPrintfW(local_248,0x208,L"%s\\%s%4.4x.tmp",*(undefined8 *)(param_1 + 8));
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    cVar1 = RtlDosPathNameToNtPathName_U(local_248,&local_258,0,0);
    if (cVar1 == '\0') {
      return 0xc0000001;
    }
    bVar2 = SmpQueryFileExists(&local_258);
    if (!bVar2) break;
    RtlFreeUnicodeString(&local_258);
    uVar4 = uVar4 + 1;
  }
  *param_3 = local_258;
  param_3[1] = uStack_250;
  return 0;
}



===== SmpEventWriteString @ 1400121cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpEventWriteString(undefined8 param_1,ushort *param_2)

{
  char cVar1;
  undefined1 auStack_58 [32];
  ushort local_38 [4];
  ushort *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  uint local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  if (SmpTraceHandle != 0) {
    cVar1 = EtwEventEnabled(SmpTraceHandle,&SmssEvt_CrashDumpCopy_Error);
    if (cVar1 != '\0') {
      local_24 = 0;
      local_14 = 0;
      local_38[0] = *param_2 >> 1;
      local_30 = local_38;
      local_20 = *(undefined8 *)(param_2 + 4);
      local_18 = (uint)*param_2;
      local_28 = 2;
      EtwEventWrite(SmpTraceHandle,&SmssEvt_CrashDumpCopy_Error,2,&local_30);
    }
  }
  return;
}



===== SmpGetCrashParameters @ 14001227c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpGetCrashParameters(longlong param_1)

{
  ulonglong uVar1;
  wchar_t *pwVar2;
  undefined1 auStack_268 [32];
  undefined8 local_248;
  wchar_t *local_240;
  undefined8 local_238;
  wchar_t *local_230;
  wchar_t local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_268;
  local_230 = L"Overwrite";
  local_238 = 0x140012;
  local_240 = L"DumpFile";
  local_248 = 0x120010;
  pwVar2 = local_228;
  uVar1 = RtlStringCbPrintfW(pwVar2,0x208,L"%s\\MEMORY.DMP",DAT_140032ad8);
  if (-1 < (int)uVar1) {
    uVar1 = SmpQueryPathFromRegistry(pwVar2,&local_248,(undefined1 *)local_228,param_1);
    if (-1 < (int)uVar1) {
      uVar1 = SmpQueryDwordFromRegistry(pwVar2,&local_238,1,(undefined4 *)(param_1 + 0x10));
      if (-1 < (int)uVar1) {
        *(undefined4 *)(param_1 + 0x14) = 0;
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



===== SmpGetDumpDestination @ 14001234c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpGetDumpDestination
                    (longlong param_1,ushort *param_2,undefined8 param_3,longlong param_4,
                    undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  ushort *puVar9;
  ulonglong uVar10;
  byte bVar11;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined4 local_d0;
  char local_c8 [8];
  undefined8 local_c0;
  longlong local_b8;
  ushort *puStack_b0;
  longlong local_a8 [5];
  ushort *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  local_c8[0] = '\0';
  local_b8 = 0;
  local_a8[0] = 0;
  local_50 = 0x5c003a003f;
  lVar8 = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  bVar11 = 0;
  if (*(int *)(param_1 + 0xf98) == 4) {
LAB_140012480:
    bVar11 = 1;
  }
  else {
    uVar6 = SmpQuerySameVolume(param_3,param_2,local_c8);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    if (local_c8[0] != '\x01') {
      if (*(int *)(param_2 + 8) != 0) {
        local_d0 = 0x60;
        local_a8[3] = 0x30;
        local_78 = 0x40;
        local_c0 = 0;
        local_a8[4] = 0;
        local_60 = 0;
        uStack_58 = 0;
        local_70 = 0;
        uStack_68 = 0;
        local_d8 = 7;
        local_80 = param_2;
        iVar5 = NtOpenFile(&local_c0,0x100080,local_a8 + 3,&local_60);
        if (-1 < iVar5) {
          SmpQueryFileSize(local_c0,local_a8);
          NtClose(local_c0);
          lVar8 = local_a8[0];
        }
      }
      goto LAB_140012480;
    }
    bVar3 = SmpQueryFileExists(param_2);
    if (bVar3) {
      if (*(int *)(param_2 + 8) == 0) {
        return 0xc0000001;
      }
      SmpDeleteFile((longlong)param_2);
    }
  }
  uVar6 = *(ulonglong *)(param_1 + 4000);
  puVar9 = param_2;
  uVar7 = SmpQueryVolumeFreeSpace(param_2,&local_b8);
  uVar10 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) {
    return uVar7;
  }
  if (uVar6 < (ulonglong)(local_b8 + lVar8)) {
    if (bVar11 != 0) {
      RtlInitUnicodeString(local_a8 + 1,&local_50);
      local_50 = CONCAT62(local_50._2_6_,*(undefined2 *)(*(longlong *)(param_4 + 8) + 8));
      uVar10 = SmpCreateTempFile((longlong)(local_a8 + 1),L"DUMP",param_5);
      uVar10 = uVar10 & 0xffffffff;
      goto LAB_140012567;
    }
    cVar4 = RtlCreateUnicodeString(param_5,*(undefined8 *)(param_2 + 4));
    if (cVar4 != '\0') goto LAB_140012567;
  }
  else {
    uVar2 = *(undefined4 *)param_2;
    local_b8 = *(longlong *)param_2;
    puStack_b0 = *(ushort **)(param_2 + 4);
    puVar1 = *(ushort **)(param_2 + 4);
    if (((puVar1 != (ushort *)0x0) && (7 < (ushort)uVar2)) &&
       (puVar9 = puVar1, lVar8 = RtlCompareMemory(puVar1,L"\\??\\",8), lVar8 == 8)) {
      puStack_b0 = puVar1 + 4;
      local_b8 = CONCAT62(local_b8._2_6_,(ushort)uVar2 - 8);
    }
    SmpEventWriteString(puVar9,(ushort *)&local_b8);
  }
  uVar10 = 0xc000009a;
LAB_140012567:
  *(uint *)(param_2 + 10) = (uint)bVar11;
  return uVar10;
}



===== SmpQueryDedicatedDumpSetting @ 1400125a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

byte SmpQueryDedicatedDumpSetting(void)

{
  byte extraout_var;
  undefined1 auStack_278 [32];
  undefined4 local_258;
  undefined4 *local_250;
  undefined4 local_248 [2];
  undefined8 local_240;
  wchar_t *local_238;
  undefined1 local_228 [528];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_278;
  local_240 = 0x240022;
  local_248[0] = 0x210;
  local_238 = L"DedicatedDumpFile";
  local_250 = local_248;
  local_258 = 0x210;
  NtQueryValueKey(SmpCrashDumpKey,&local_240,0,local_228);
  return extraout_var >> 7 ^ 1;
}



===== SmpQueryDwordFromRegistry @ 14001262c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
SmpQueryDwordFromRegistry
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 auStack_268 [32];
  undefined4 local_248;
  undefined4 *local_240;
  undefined4 local_238 [4];
  undefined1 local_228 [4];
  int local_224;
  undefined4 local_21c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_268;
  local_240 = local_238;
  local_248 = 0x210;
  local_238[0] = 0x210;
  iVar1 = NtQueryValueKey(SmpCrashDumpKey,param_2,2,local_228);
  if ((-1 < iVar1) && (local_224 == 4)) {
    param_3 = local_21c;
  }
  *param_4 = param_3;
  return 0;
}



===== SmpQueryFileExists @ 1400126c4 =====

bool SmpQueryFileExists(undefined8 param_1)

{
  int iVar1;
  undefined8 local_res8 [4];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_1c = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_48 = 0;
  uStack_40 = 0;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = param_1;
  iVar1 = NtOpenFile(local_res8,0x100080,&local_38,&local_48,3,0x20);
  if (-1 < iVar1) {
    NtClose(local_res8[0]);
  }
  return -1 < iVar1;
}



===== SmpQueryFileSize @ 140012754 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpQueryFileSize(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 5;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = NtQueryInformationFile(0,&local_38,&local_28,0x18);
  if (-1 < iVar1) {
    *param_2 = local_28;
  }
  return;
}



===== SmpQueryPagefileTooSmallForDump @ 1400127cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SmpQueryPagefileTooSmallForDump(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  undefined8 local_30;
  wchar_t *local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = 0;
  local_28 = L"PagefileTooSmall";
  local_40 = local_38;
  local_30 = 0x220020;
  local_48 = 0x10;
  local_38[0] = 0;
  local_20 = 0;
  uStack_18 = 0;
  iVar1 = NtQueryValueKey(SmpCrashDumpKey,&local_30,4,&local_20);
  if (((-1 < iVar1) && ((int)local_20 == 0xb)) && (local_20._4_4_ == 8)) {
    uVar2 = uStack_18;
  }
  return uVar2;
}



===== SmpQueryPathFromRegistry @ 14001286c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpQueryPathFromRegistry
                    (undefined8 param_1,undefined8 param_2,undefined1 *param_3,undefined8 param_4)

{
  char cVar1;
  ulonglong uVar2;
  undefined1 *puVar3;
  undefined1 auStack_4a8 [32];
  undefined4 local_488;
  undefined4 *local_480;
  undefined4 local_478 [2];
  undefined8 local_470;
  undefined1 *puStack_468;
  undefined8 local_460;
  undefined1 *puStack_458;
  undefined1 local_448 [4];
  int local_444;
  undefined1 local_43c [516];
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_4a8;
  local_480 = local_478;
  local_488 = 0x210;
  local_478[0] = 0x210;
  local_470 = 0;
  puStack_468 = (undefined1 *)0x0;
  local_460 = 0;
  puStack_458 = (undefined1 *)0x0;
  uVar2 = NtQueryValueKey(SmpCrashDumpKey,0,2,local_448);
  if (-1 < (int)uVar2) {
    if (local_444 == 2) {
      local_470._0_4_ = CONCAT22((short)local_478[0] + -0xc,(short)local_478[0] + -0xc);
      puStack_468 = local_43c;
      local_460._0_4_ = CONCAT22(0x204,(undefined2)local_460);
      puStack_458 = local_238;
      uVar2 = RtlExpandEnvironmentStrings_U(0,&local_470,&local_460,0);
      if ((-1 < (int)uVar2) && (puVar3 = puStack_458, puStack_458 != (undefined1 *)0x0))
      goto LAB_14001294e;
    }
    else if (local_444 == 1) {
      puVar3 = local_43c;
      goto LAB_14001294e;
    }
  }
  if (param_3 == (undefined1 *)0x0) {
    return uVar2;
  }
  puVar3 = param_3;
LAB_14001294e:
  cVar1 = RtlDosPathNameToNtPathName_U(puVar3,param_4,0,0);
  return (ulonglong)(~-(uint)(cVar1 != '\0') & 0xc0000001);
}



===== SmpQuerySameVolume @ 1400129a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpQuerySameVolume(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 auStack_1c8 [32];
  undefined8 local_1a8;
  undefined4 local_1a0;
  undefined4 local_198;
  undefined4 local_190;
  undefined4 local_188;
  undefined8 local_180;
  undefined4 local_178;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined4 local_150;
  undefined4 local_14c;
  undefined8 local_148;
  undefined8 local_140;
  undefined4 local_138;
  undefined4 local_134;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined1 local_118 [8];
  int local_110;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1c8;
  local_168 = 0;
  memset(local_118,0,0xe0);
  local_1a8._0_4_ = 1;
  local_134 = 0;
  local_14c = 0;
  local_160 = 0;
  uStack_158 = 0;
  uVar3 = NtQueryVolumeInformationFile(param_1,&local_160,local_118,0xe0);
  iVar1 = local_110;
  if (-1 < (int)uVar3) {
    local_148 = 0;
    local_1a0 = 0x60;
    local_150 = 0x30;
    local_138 = 0x40;
    local_130 = 0;
    uStack_128 = 0;
    local_1a8 = CONCAT44(local_1a8._4_4_,3);
    local_140 = param_2;
    uVar3 = NtOpenFile(&local_168,0x100000,&local_150,&local_160);
    if ((int)uVar3 == -0x3fffffcc) {
      local_178 = 0;
      local_180 = 0;
      local_188 = 0x1060;
      local_190 = 2;
      local_198 = 0;
      local_1a0 = 0x80;
      local_1a8 = 0;
      uVar3 = NtCreateFile(&local_168,0x110000,&local_150,&local_160);
    }
    if (-1 < (int)uVar3) {
      local_1a8 = CONCAT44(local_1a8._4_4_,1);
      uVar2 = NtQueryVolumeInformationFile(local_168,&local_160,local_118,0xe0);
      uVar3 = (ulonglong)uVar2;
      NtClose(local_168);
      if (-1 < (int)uVar2) {
        *(bool *)param_3 = iVar1 == local_110;
      }
    }
  }
  return uVar3;
}



===== SmpQueryVolumeFreeSpace @ 140012b44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpQueryVolumeFreeSpace(ushort *param_1,longlong *param_2)

{
  ulonglong uVar1;
  short *psVar2;
  uint uVar3;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 local_a0;
  undefined8 local_98;
  short local_90;
  ushort uStack_8e;
  ushort uStack_8c;
  ushort uStack_8a;
  ushort uStack_88;
  ushort uStack_86;
  ushort uStack_84;
  ushort uStack_82;
  undefined8 local_80;
  undefined8 uStack_78;
  short *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  longlong lStack_38;
  ulonglong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_98 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_30 = 0;
  uStack_8e = param_1[1];
  uStack_8c = param_1[2];
  uStack_8a = param_1[3];
  uStack_88 = param_1[4];
  uStack_86 = param_1[5];
  uStack_84 = param_1[6];
  uStack_82 = param_1[7];
  local_40 = 0;
  lStack_38 = 0;
  uVar3 = (uint)*param_1;
  psVar2 = *(short **)(param_1 + 4);
  do {
    if (uVar3 == 0) {
LAB_140012bcb:
      local_90 = (short)psVar2 - uStack_88;
      local_70 = &local_90;
      local_a0 = 0x21;
      local_80 = 0x30;
      uStack_78 = 0;
      uStack_68 = 0x40;
      local_60 = 0;
      uStack_58 = 0;
      local_a8 = 3;
      uVar1 = NtOpenFile(&local_98,0x100001,&local_80,&local_50);
      if (-1 < (int)uVar1) {
        local_a8 = 3;
        uVar3 = NtQueryVolumeInformationFile(local_98,&local_50,&local_40,0x18);
        uVar1 = (ulonglong)uVar3;
        NtClose(local_98);
        if (-1 < (int)uVar3) {
          uVar1 = 0;
          *param_2 = (local_30 >> 0x20) * (local_30 & 0xffffffff) * lStack_38;
        }
      }
      return uVar1;
    }
    if ((*psVar2 == 0x3a) && (psVar2[1] == 0x5c)) {
      psVar2 = psVar2 + 2;
      goto LAB_140012bcb;
    }
    uVar3 = uVar3 - 2;
    psVar2 = psVar2 + 1;
  } while( true );
}



===== SmpSaveOldPageFile @ 140012c9c =====

int SmpSaveOldPageFile(short *param_1,short *param_2,uint *param_3)

{
  int iVar1;
  undefined8 uVar2;
  short sVar3;
  uint uVar4;
  longlong local_res18 [2];
  undefined8 local_78;
  longlong lStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  short *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar4 = 0;
  local_3c = 0;
  local_res18[0] = 0;
  local_54 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  lStack_70 = 0;
  if (*param_3 < 0x10) {
    local_50 = 0;
    local_58 = 0x30;
    local_40 = 0x40;
    local_38 = 0;
    uStack_30 = 0;
    local_48 = param_1;
    iVar1 = NtOpenFile(local_res18,0x80150100,&local_58,&local_68,1,0x68);
    if (-1 < iVar1) {
      if (param_2 == (short *)0x0) {
        sVar3 = *param_1 + 10;
      }
      else {
        sVar3 = *param_2 + 0x14;
      }
      local_78._0_4_ = CONCAT22(sVar3,(ushort)local_78);
      lStack_70 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0);
      if (lStack_70 != 0) {
        if (param_2 == (short *)0x0) {
          RtlCopyUnicodeString(&local_78,param_1);
          iVar1 = RtlAppendUnicodeToString(&local_78,L".dmp");
        }
        else {
          uVar2 = RtlUnicodeStringPrintf
                            ((ushort *)&local_78,L"%wZ\\pf%02u.dmp",param_2,(ulonglong)*param_3);
          iVar1 = (int)uVar2;
        }
        if (-1 < iVar1) {
          if ((param_2 == (short *)0x0) && (uVar4 = 0, SmpForceCopyDumpFile == '\0')) {
            uVar4 = 1;
          }
          iVar1 = SmpSavePageFile(local_res18[0],(ushort *)&local_78,0,uVar4);
          if (-1 < iVar1) {
            uVar4 = *param_3;
            *(undefined8 *)(param_3 + (ulonglong)uVar4 * 4 + 2) = local_78;
            *(longlong *)(param_3 + (ulonglong)uVar4 * 4 + 2 + 2) = lStack_70;
            param_3[1] = param_3[1] + (uint)(ushort)local_78;
            *param_3 = *param_3 + 1;
          }
        }
      }
    }
    if (local_res18[0] != 0) {
      NtClose();
    }
    if ((iVar1 < 0) && (lStack_70 != 0)) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lStack_70);
    }
  }
  else {
    iVar1 = -0x3fffff69;
  }
  return iVar1;
}



===== SmpSavePageFile @ 140012e7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpSavePageFile(undefined8 param_1,ushort *param_2,ulonglong param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined1 auStack_2a8 [32];
  undefined4 local_288;
  char local_278 [8];
  ulonglong local_270;
  ulonglong local_268 [6];
  undefined1 local_238 [4];
  undefined4 local_234;
  undefined8 local_230;
  uint local_228;
  short local_224 [246];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2a8;
  local_234 = 0;
  memset(local_238,0,0x1fc);
  local_268[3] = 0;
  local_268[4] = 0;
  local_278[0] = '\0';
  if (SmpForceCopyDumpFile == '\0') {
    if (param_3 != 0) {
      local_288 = 0x14;
      local_268[1] = 0;
      local_268[2] = 0;
      local_270 = param_3;
      iVar1 = NtSetInformationFile(param_1,local_268 + 1,&local_270,8);
      if (iVar1 < 0) {
        return;
      }
      local_288 = 0x13;
      local_268[0] = param_3;
      iVar1 = NtSetInformationFile(param_1,local_268 + 1,local_268,8);
      if (iVar1 < 0) {
        return;
      }
    }
    if ((param_4 & 1) == 0) {
      uVar3 = SmpQuerySameVolume(param_1,param_2,local_278);
      if ((int)uVar3 < 0) {
        return;
      }
      if (local_278[0] != '\x01') {
        param_3 = 0;
        goto LAB_140012ee0;
      }
    }
    uVar4 = (uint)*param_2;
    local_230 = 0;
    local_228 = (uint)*param_2;
    local_238[0] = 1;
    uVar2 = RtlStringCbCopyW(local_224,0x1ec,*(longlong *)(param_2 + 4));
    if (-1 < (int)uVar2) {
      local_288 = 10;
      iVar1 = NtSetInformationFile(param_1,local_268 + 3,local_238,uVar4 + 0x18);
      if (-1 < iVar1) {
        SmpSetDumpSecurityAndAttributes(param_1);
      }
    }
  }
  else {
LAB_140012ee0:
    SmpCopyFile(param_1,param_2,param_3);
  }
  return;
}



===== SmpSetDumpSecurityAndAttributes @ 14001300c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpSetDumpSecurityAndAttributes(undefined8 param_1)

{
  int iVar1;
  undefined1 auStack_508 [32];
  undefined4 local_4e8;
  undefined4 local_4e0;
  undefined4 local_4d8;
  undefined4 local_4d0;
  undefined4 local_4c8;
  undefined4 local_4c0;
  longlong *local_4b8;
  longlong local_4a8;
  longlong local_4a0;
  longlong local_498 [8];
  undefined4 local_458;
  undefined2 local_454;
  undefined4 local_450;
  undefined2 local_44c;
  undefined8 local_448;
  undefined8 uStack_440;
  undefined8 local_438;
  undefined8 uStack_430;
  ulonglong local_428;
  undefined1 local_418 [1024];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_508;
  local_454 = 0x500;
  local_458 = 0;
  local_498[7] = 0;
  local_428 = 0;
  local_4b8 = local_498;
  local_450 = 0;
  local_4c0 = 0;
  local_4c8 = 0;
  local_4d0 = 0;
  local_4d8 = 0;
  local_4e0 = 0;
  local_4e8 = 0;
  local_44c = 0x100;
  local_498[0] = 0;
  local_4a0 = 0;
  local_4a8 = 0;
  local_498[3] = 0;
  local_498[4] = 0;
  local_498[5] = 0;
  local_498[6] = 0;
  local_498[1] = 0;
  local_498[2] = 0;
  local_448 = 0;
  uStack_440 = 0;
  local_438 = 0;
  uStack_430 = 0;
  iVar1 = RtlAllocateAndInitializeSid(&local_450,1,0,0);
  if (-1 < iVar1) {
    local_4b8 = &local_4a0;
    local_4c0 = 0;
    local_4c8 = 0;
    local_4d0 = 0;
    local_4d8 = 0;
    local_4e0 = 0;
    local_4e8 = 0;
    iVar1 = RtlAllocateAndInitializeSid(&local_458,1,0x12,0);
    if (-1 < iVar1) {
      local_4b8 = &local_4a8;
      local_4c0 = 0;
      local_4c8 = 0;
      local_4d0 = 0;
      local_4d8 = 0;
      local_4e0 = 0;
      local_4e8 = 0;
      iVar1 = RtlAllocateAndInitializeSid(&local_458,2,0x20,0x220);
      if (-1 < iVar1) {
        RtlCreateSecurityDescriptor(local_498 + 3,1);
        RtlCreateAcl(local_418,0x400,2);
        RtlAddAccessAllowedAce(local_418,2,0x100d0000,local_4a8);
        RtlAddAccessAllowedAce(local_418,2,0x100d0000,local_4a0);
        RtlSetDaclSecurityDescriptor(local_498 + 3,1,local_418,0);
        RtlSetOwnerSecurityDescriptor(local_498 + 3,local_4a8,0);
        iVar1 = NtSetSecurityObject(param_1,4,local_498 + 3);
        if (-1 < iVar1) {
          local_4e8 = 4;
          iVar1 = NtQueryInformationFile(param_1,local_498 + 1,&local_448,0x28);
          if (-1 < iVar1) {
            local_428 = local_428 & 0xfffffffffffffff9;
            local_4e8 = 4;
            iVar1 = NtSetInformationFile(param_1,local_498 + 1,&local_448,0x28);
          }
        }
      }
    }
  }
  if (local_498[0] != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_498[0]);
  }
  if (local_4a0 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_4a0);
  }
  if (local_4a8 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_4a8);
  }
  return iVar1;
}



===== RtlStringExHandleOtherFlagsW @ 140013308 =====

undefined8
RtlStringExHandleOtherFlagsW
          (undefined2 *param_1,ulonglong param_2,undefined8 param_3,undefined8 *param_4,
          ulonglong *param_5,uint param_6)

{
  ulonglong uVar1;
  
  uVar1 = param_2 >> 1;
  if ((uVar1 != 0) && ((param_6 & 0x1000) != 0)) {
    *param_4 = param_1;
    *param_5 = uVar1;
    *param_1 = 0;
  }
  if ((param_6 & 0x400) != 0) {
    memset(param_1,param_6 & 0xff,param_2);
    if ((char)param_6 != '\0') {
      if (uVar1 == 0) {
        return 0;
      }
      *param_5 = 1;
      *param_4 = param_1 + (uVar1 - 1);
      param_1[uVar1 - 1] = 0;
      goto LAB_140013373;
    }
    *param_4 = param_1;
    *param_5 = uVar1;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_140013373:
  if ((param_6 & 0x800) != 0) {
    *param_4 = param_1;
    *param_5 = uVar1;
    *param_1 = 0;
  }
  return 0;
}



===== RtlStringVPrintfWorkerW @ 1400133c8 =====

undefined4
RtlStringVPrintfWorkerW
          (wchar_t *param_1,size_t param_2,size_t *param_3,wchar_t *param_4,va_list param_5)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong _MaxCount;
  undefined4 uVar3;
  
  _MaxCount = param_2 - 1;
  uVar3 = 0;
  iVar1 = _vsnwprintf_s(param_1,param_2,_MaxCount,param_4,param_5);
  if (iVar1 < 0) {
LAB_14001341b:
    uVar3 = 0x80000005;
  }
  else {
    uVar2 = (ulonglong)iVar1;
    if (_MaxCount < uVar2) goto LAB_14001341b;
    if (uVar2 != _MaxCount) {
      _MaxCount = uVar2;
      goto LAB_140013425;
    }
  }
  param_1[_MaxCount] = L'\0';
LAB_140013425:
  if (param_3 != (size_t *)0x0) {
    *param_3 = _MaxCount;
  }
  return uVar3;
}



===== RtlUnicodeStringCat @ 140013454 =====

ulonglong RtlUnicodeStringCat(ushort *param_1,ushort *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  short sVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  longlong lVar7;
  ulonglong local_res18;
  ulonglong local_res20;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res18 = 0;
  local_res20 = 0;
  uVar1 = RtlUnicodeStringValidateDestWorker(param_1,local_18,&local_res18,&local_res20);
  uVar5 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    uVar1 = RtlUnicodeStringValidateWorker(param_2);
    if (((int)uVar1 < 0) || (param_2 == (ushort *)0x0)) {
      puVar6 = (undefined2 *)0x0;
      uVar3 = 0;
      if ((int)uVar1 < 0) {
        return uVar1 & 0xffffffff;
      }
    }
    else {
      puVar6 = *(undefined2 **)(param_2 + 4);
      uVar3 = (ulonglong)(*param_2 >> 1);
    }
    uVar5 = 0;
    sVar4 = 0;
    lVar7 = local_res18 - local_res20;
    if (lVar7 != 0) {
      lVar2 = local_res20 * 2 - (longlong)puVar6;
      do {
        if (uVar3 == 0) goto LAB_140013508;
        uVar3 = uVar3 - 1;
        *(undefined2 *)(lVar2 + local_18[0] + (longlong)puVar6) = *puVar6;
        sVar4 = sVar4 + 1;
        puVar6 = puVar6 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    uVar5 = 0;
    if (uVar3 != 0) {
      uVar5 = 0x80000005;
    }
LAB_140013508:
    *param_1 = (sVar4 + (short)local_res20) * 2;
  }
  return uVar5;
}



===== RtlUnicodeStringCatString @ 14001352c =====

ulonglong RtlUnicodeStringCatString(ushort *param_1,short *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong local_res18;
  ulonglong local_res20;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res18 = 0;
  local_res20 = 0;
  uVar1 = RtlUnicodeStringValidateDestWorker(param_1,local_18,&local_res18,&local_res20);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffffff;
  }
  lVar5 = 0x7fff;
  uVar1 = 0;
  sVar3 = 0;
  lVar4 = local_res18 - local_res20;
  if (lVar4 != 0) {
    lVar2 = local_res20 * 2 - (longlong)param_2;
    do {
      if (lVar5 == 0) goto LAB_1400135c5;
      if (*param_2 == 0) break;
      *(short *)(lVar2 + local_18[0] + (longlong)param_2) = *param_2;
      lVar5 = lVar5 + -1;
      param_2 = param_2 + 1;
      sVar3 = sVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    if ((lVar4 != 0) || (lVar5 == 0)) goto LAB_1400135c5;
  }
  uVar1 = 0;
  if (*param_2 != 0) {
    uVar1 = 0x80000005;
  }
LAB_1400135c5:
  *param_1 = (sVar3 + (short)local_res20) * 2;
  return uVar1;
}



===== RtlUnicodeStringValidateDestWorker @ 1400135ec =====

ulonglong RtlUnicodeStringValidateDestWorker
                    (ushort *param_1,undefined8 *param_2,ulonglong *param_3,ulonglong *param_4)

{
  ulonglong uVar1;
  ushort *puVar2;
  
  *param_2 = 0;
  *param_3 = 0;
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = 0;
  }
  puVar2 = param_1;
  uVar1 = RtlUnicodeStringValidateWorker(param_1);
  if ((-1 < (int)uVar1) && (puVar2 != (ushort *)0x0)) {
    *param_2 = *(undefined8 *)(param_1 + 4);
    *param_3 = (ulonglong)(puVar2[1] >> 1);
    if (param_4 != (ulonglong *)0x0) {
      *param_4 = (ulonglong)(*puVar2 >> 1);
    }
  }
  return uVar1 & 0xffffffff;
}



===== RtlUnicodeStringValidateWorker @ 140013658 =====

undefined8 RtlUnicodeStringValidateWorker(ushort *param_1)

{
  ushort uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if ((((((*param_1 & 1) != 0) || (uVar1 = param_1[1], (uVar1 & 1) != 0)) || (uVar1 < *param_1)) ||
      (uVar1 == 0xffff)) || ((*(longlong *)(param_1 + 4) == 0 && ((*param_1 != 0 || (uVar1 != 0)))))
     ) {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== SmpBuildSubSystemLists @ 1400136a0 =====

undefined8
SmpBuildSubSystemLists
          (wchar_t *param_1,undefined8 param_2,short *param_3,undefined8 param_4,undefined8 param_5,
          int *param_6)

{
  ushort *puVar1;
  short sVar2;
  ushort uVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  undefined8 uVar10;
  short *psVar11;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_38 = 0;
  uStack_30 = 0;
  iVar8 = _wcsicmp(param_1,L"Required");
  sVar2 = *param_3;
  do {
    if (sVar2 == 0) {
      return 0;
    }
    local_48 = 0;
    uStack_40 = 0;
    RtlInitUnicodeString(&local_48,param_3);
    plVar9 = SmpFindRegistryValueEx((undefined8 *)(param_6 + 2),&local_48);
    if (plVar9 == (longlong *)0x0) {
      SmpLogFailureString(0x14002a288,0x22b2,(longlong)param_3,0);
      do {
        psVar11 = param_3;
        param_3 = psVar11 + 1;
      } while (*psVar11 != 0);
    }
    else {
      lVar4 = *plVar9;
      if ((*(longlong **)(lVar4 + 8) != plVar9) ||
         (plVar5 = (longlong *)plVar9[1], (longlong *)*plVar5 != plVar9)) goto LAB_140013859;
      *plVar5 = lVar4;
      puVar1 = (ushort *)(plVar9 + 2);
      *(longlong **)(lVar4 + 8) = plVar5;
      uVar3 = *puVar1;
      if ((short)plVar9[4] == 0) {
LAB_1400137f6:
        SmpDeallocSavedRegistryEntry((longlong)plVar9);
      }
      else {
        RtlInitUnicodeString(&local_38,L"Posix");
        cVar7 = RtlEqualUnicodeString(puVar1,&local_38,0);
        if (cVar7 != '\0') goto LAB_1400137f6;
        if (iVar8 == 0) {
          if ((undefined8 *)*DAT_140032a98 != &SmpSubSystemsRequired) {
LAB_140013859:
            pcVar6 = (code *)swi(0x29);
            (*pcVar6)(3);
            pcVar6 = (code *)swi(3);
            uVar10 = (*pcVar6)();
            return uVar10;
          }
          *plVar9 = (longlong)&SmpSubSystemsRequired;
          plVar9[1] = (longlong)DAT_140032a98;
          *DAT_140032a98 = (longlong)plVar9;
          DAT_140032a98 = plVar9;
          *param_6 = *param_6 + 2;
          param_6[1] = param_6[1] + *puVar1 + 4 + (uint)*(ushort *)(plVar9 + 4);
        }
        else {
          if ((undefined8 *)*DAT_140032aa8 != &SmpSubSystemsToDefer) goto LAB_140013859;
          *plVar9 = (longlong)&SmpSubSystemsToDefer;
          plVar9[1] = (longlong)DAT_140032aa8;
          *DAT_140032aa8 = (longlong)plVar9;
          DAT_140032aa8 = plVar9;
        }
      }
      psVar11 = (short *)((longlong)param_3 + (ulonglong)uVar3);
    }
    param_3 = psVar11 + 1;
    sVar2 = *param_3;
  } while( true );
}



===== SmpCheckDirectoryWritable @ 140013868 =====

undefined4 SmpCheckDirectoryWritable(undefined8 param_1)

{
  undefined4 uVar1;
  longlong local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res8 = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_48 = 0;
  uStack_40 = 0;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = param_1;
  uVar1 = NtOpenFile(&local_res8,2,&local_38,&local_48,3,0);
  if (local_res8 != 0) {
    NtClose();
  }
  return uVar1;
}



===== SmpCheckFolderForRedirections @ 140013900 =====

bool SmpCheckFolderForRedirections(ushort *param_1,longlong *param_2)

{
  size_t _Size;
  short sVar1;
  bool bVar2;
  bool bVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  HANDLE local_res8;
  ushort local_68 [4];
  void *pvStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ushort *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  local_res8 = (HANDLE)0xffffffffffffffff;
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  local_58 = 0;
  uStack_50 = 0;
  bVar3 = false;
  local_48 = (ushort *)0x0;
  uStack_40 = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  pvStack_60 = (void *)0x0;
  RtlInitUnicodeString(local_68,0);
  if (0xd < *param_1) {
    uVar4 = InternalGetFileAttributesW(*(undefined8 *)(param_1 + 4));
    if ((uint)uVar4 == 0xffffffff) {
LAB_140013983:
      bVar2 = false;
    }
    else {
      if (((uint)uVar4 >> 10 & 1) != 0) goto LAB_1400139aa;
      bVar2 = true;
      if ((uVar4 & 0x10) == 0) goto LAB_140013983;
    }
    uVar6 = (*param_1 >> 1) - 1;
    uVar4 = (ulonglong)uVar6;
    if (bVar2) {
LAB_140013a07:
      pvStack_60 = (void *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30)
                                           ,SmBaseTag,(ulonglong)((int)uVar4 + 3) * 2);
      if (pvStack_60 != (void *)0x0) {
        uVar6 = (int)uVar4 + 1;
        _Size = (ulonglong)uVar6 * 2;
        memcpy(pvStack_60,*(void **)(param_1 + 4),_Size);
        sVar1 = (short)uVar4 * 2;
        local_68[1] = sVar1 + 4;
        local_68[0] = sVar1 + 2;
        if ((bVar2) && (*(short *)((longlong)pvStack_60 + uVar4 * 2) != 0x5c)) {
          *(undefined2 *)(_Size + (longlong)pvStack_60) = 0x5c;
          uVar4 = (ulonglong)uVar6;
          local_68[1] = sVar1 + 5;
          local_68[0] = sVar1 + 3;
        }
        *(undefined2 *)((longlong)pvStack_60 + (ulonglong)((int)uVar4 + 1) * 2) = 0;
        local_48 = local_68;
        local_58 = CONCAT44(local_58._4_4_,0x30);
        uStack_50 = 0;
        uStack_40 = CONCAT44(uStack_40._4_4_,0x40);
        local_38 = 0;
        uStack_30 = 0;
        uVar5 = SmpOpenTargetFile(&local_res8,0x100080,&local_58,'\0');
        if (-1 < (int)uVar5) {
          bVar3 = SmpPathCanBeTrustedIsNotARedirection(local_res8,local_68,1);
          if (bVar3) {
            *param_2 = (longlong)local_res8;
            goto LAB_1400139c0;
          }
        }
      }
    }
    else if (uVar6 != 0) {
      do {
        if (*(short *)(*(longlong *)(param_1 + 4) + uVar4 * 2) == 0x5c) goto LAB_140013a07;
        uVar6 = (int)uVar4 - 1;
        uVar4 = (ulonglong)uVar6;
      } while (uVar6 != 0);
    }
  }
LAB_1400139aa:
  if (local_res8 != (HANDLE)0xffffffffffffffff) {
    NtClose();
  }
LAB_1400139c0:
  if (pvStack_60 != (void *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pvStack_60);
  }
  return bVar3;
}



===== SmpConfigureAllowProtectedRenames @ 140013b20 =====

undefined8
SmpConfigureAllowProtectedRenames(undefined8 param_1,undefined8 param_2,int *param_3,int param_4)

{
  SmpAllowProtectedRenames = false;
  if (param_4 == 4) {
    SmpAllowProtectedRenames = *param_3 != 0;
  }
  return 0;
}



===== SmpConfigureBackgroundLoadKnownDlls @ 140013b40 =====

undefined8
SmpConfigureBackgroundLoadKnownDlls(undefined8 param_1,int param_2,undefined4 *param_3,int param_4)

{
  if ((param_2 == 4) && (param_4 == 4)) {
    SmpLoadKnownDllsFlags = *param_3;
  }
  return 0;
}



===== SmpConfigureClearTempFiles @ 140013b60 =====

undefined8 SmpConfigureClearTempFiles(void)

{
  int in_R9D;
  
  if (in_R9D == 4) {
    SmpClearTempFiles = 1;
  }
  return 0;
}



===== SmpConfigureDosDevices @ 140013b80 =====

void SmpConfigureDosDevices
               (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
               undefined8 param_5,longlong *param_6)

{
  SmpSaveRegistryValue(param_6,param_1,param_3,1);
  return;
}



===== SmpConfigureEnvironment @ 140013bb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SmpConfigureEnvironment(wchar_t *param_1,undefined8 param_2,void *param_3,ulonglong param_4)

{
  int iVar1;
  void *_Dst;
  undefined8 local_28;
  longlong lStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0;
  lStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_28,param_1);
  RtlInitUnicodeString(&local_18,param_3);
  iVar1 = RtlSetEnvironmentVariable(0,&local_28,&local_18);
  if (iVar1 < 0) {
    SmpLogFailureString(0x14002a250,0x1fbf,lStack_20,iVar1);
  }
  else {
    iVar1 = _wcsicmp(param_1,L"Path");
    if ((iVar1 == 0) && (SmpCalledConfigEnv = SmpCalledConfigEnv + 1, SmpCalledConfigEnv == 2)) {
      _Dst = (void *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                     SmBaseTag,param_4 & 0xffffffff);
      if (_Dst == (void *)0x0) {
        _SmpDefaultLibPathBuffer = _Dst;
        return -0x3fffffe9;
      }
      _SmpDefaultLibPathBuffer = _Dst;
      memcpy(_Dst,param_3,param_4 & 0xffffffff);
      RtlInitUnicodeString(&SmpDefaultLibPath,_Dst);
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== SmpConfigureExcludeKnownDlls @ 140013cf0 =====

undefined8
SmpConfigureExcludeKnownDlls
          (undefined8 param_1,int param_2,short *param_3,undefined8 param_4,undefined8 param_5,
          longlong *param_6)

{
  short sVar1;
  undefined8 uVar2;
  
  if ((param_2 == 7) || (param_2 == 1)) {
    while (*param_3 != 0) {
      uVar2 = SmpSaveRegistryValue(param_6,param_3,0,1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      if (param_2 == 1) {
        return uVar2;
      }
      do {
        sVar1 = *param_3;
        param_3 = param_3 + 1;
      } while (sVar1 != 0);
    }
  }
  return 0;
}



===== SmpConfigureExecute @ 140013d60 =====

void SmpConfigureExecute(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,undefined8 param_5,int *param_6)

{
  int iVar1;
  
  iVar1 = SmpSaveRegistryValue((longlong *)(param_6 + 10),param_3,0,1);
  if (-1 < iVar1) {
    *param_6 = *param_6 + 1;
    param_6[1] = param_6[1] + uRam0000000000000010 + 2;
  }
  return;
}



===== SmpConfigureExistingPageFiles @ 140013dc0 =====

void SmpConfigureExistingPageFiles
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,longlong *param_6)

{
  SmpSaveRegistryValue(param_6,param_3,0,1);
  return;
}



===== SmpConfigureFileRenames @ 140013df0 =====

undefined8
SmpConfigureFileRenames
          (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
          undefined8 param_5,longlong *param_6)

{
  undefined8 uVar1;
  
  if (DAT_1400322e0 == 0) {
    uVar1 = 0;
    DAT_1400322e0 = param_3;
  }
  else {
    uVar1 = SmpSaveRegistryValue(param_6,DAT_1400322e0,param_3,0);
    DAT_1400322e0 = 0;
  }
  return uVar1;
}



===== SmpConfigureKnownDlls @ 140013e40 =====

undefined8
SmpConfigureKnownDlls
          (wchar_t *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
          undefined8 param_5,longlong *param_6)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = _wcsicmp(param_1,L"DllDirectory");
  if ((iVar1 == 0) || (iVar1 = _wcsicmp(param_1,L"DllDirectory32"), iVar1 == 0)) {
    return 0;
  }
  uVar2 = SmpSaveRegistryValue(param_6,param_1,param_3,1);
  return uVar2;
}



===== SmpConfigureNumberInitialSessions @ 140013ec0 =====

undefined8
SmpConfigureNumberInitialSessions(undefined8 param_1,int param_2,uint *param_3,int param_4)

{
  if ((SmpManufacturingMode != '\x01') && (SmpHostSmss != '\0')) {
    if ((param_4 == 4) && (param_2 == 4)) {
      SmpNumberInitialSessions = *param_3;
    }
    else {
      SmpNumberInitialSessions = 1;
    }
    if (2 < SmpNumberInitialSessions) {
      SmpNumberInitialSessions = 2;
      return 0;
    }
    if (SmpNumberInitialSessions != 0) {
      return 0;
    }
  }
  SmpNumberInitialSessions = 1;
  return 0;
}



===== SmpConfigureObjectDirectories @ 140013f20 =====

undefined8 SmpConfigureObjectDirectories(undefined8 param_1,undefined8 param_2,short *param_3)

{
  short sVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  undefined8 local_res18;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  wchar_t *local_50;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_58 = 0x1a0018;
  local_18 = 0;
  local_10 = local_10 & 0xffffffff00000000;
  local_50 = L"\\RPC Control";
  local_40 = L"\\Windows";
  local_68 = 0;
  lStack_60 = 0;
  local_res18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0x120010;
  local_28 = (undefined8 *)0x0;
  uStack_20 = 0;
  sVar1 = *param_3;
  while (sVar1 != 0) {
    RtlInitUnicodeString(&local_68,param_3);
    uVar2 = SmpPrimarySecurityDescriptor;
    cVar3 = RtlEqualUnicodeString(&local_68,&local_58,1);
    if ((cVar3 != '\0') ||
       (cVar3 = RtlEqualUnicodeString(&local_68,&local_48,1), local_18 = uVar2, cVar3 != '\0')) {
      local_18 = SmpLiberalSecurityDescriptor;
    }
    local_28 = &local_68;
    local_38 = CONCAT44(local_38._4_4_,0x30);
    uStack_30 = 0;
    uStack_20 = CONCAT44(uStack_20._4_4_,0xd0);
    local_10 = 0;
    iVar4 = NtCreateDirectoryObject(&local_res18,0xf000f,&local_38);
    if (iVar4 < 0) {
      SmpLogFailureString(0x14002a1f0,0x1cee,lStack_60,iVar4);
    }
    else {
      NtClose(local_res18);
    }
    do {
      sVar1 = *param_3;
      param_3 = param_3 + 1;
    } while (sVar1 != 0);
    sVar1 = *param_3;
  }
  return 0;
}



===== SmpConfigureOneTimeExecute @ 140014090 =====

undefined8
SmpConfigureOneTimeExecute
          (undefined8 param_1,undefined8 param_2,short *param_3,ulonglong param_4,undefined8 param_5
          ,longlong *param_6)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  short *psVar4;
  
  if (param_3 != (short *)0x0) {
    uVar1 = (param_4 & 0xffffffff) >> 1;
    uVar2 = uVar1;
    for (psVar4 = param_3; (uVar2 != 0 && (*psVar4 != 0)); psVar4 = psVar4 + 1) {
      uVar2 = uVar2 - 1;
    }
    if ((uVar2 != 0) && ((uVar1 - uVar2 & 0x7fffffffffffffff) != 0)) {
      uVar3 = SmpSaveRegistryValue(param_6,param_3,0,1);
      return uVar3;
    }
  }
  return 0;
}



===== SmpConfigurePagefileOptions @ 140014100 =====

undefined8
SmpConfigurePagefileOptions(undefined8 param_1,undefined8 param_2,undefined4 *param_3,int param_4)

{
  if (param_4 == 4) {
    SmpPagefileOnOsVolume = *param_3;
  }
  else {
    SmpPagefileOnOsVolume = 0;
  }
  return 0;
}



===== SmpConfigureProtectionMode @ 140014120 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SmpConfigureProtectionMode(undefined8 param_1,undefined8 param_2,undefined4 *param_3,int param_4)

{
  _SmpProtectionMode = 1;
  if (param_4 == 4) {
    _SmpProtectionMode = *param_3;
  }
  SmpCreateSecurityDescriptors('\0');
  return 0;
}



===== SmpConfigureRenameTempDir @ 140014150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SmpConfigureRenameTempDir(undefined8 param_1,int param_2,undefined8 param_3,int param_4)

{
  char cVar1;
  undefined8 local_18;
  longlong local_10;
  
  local_18 = 0;
  local_10 = 0;
  if ((param_4 - 1U < 0x209) && (param_2 == 1)) {
    cVar1 = RtlDosPathNameToNtPathName_U(param_3,&local_18,0,0);
    if (cVar1 != '\0') {
      if ((ushort)local_18 < 0x20a) {
        _DAT_1400329f2 = 0x20a;
        RtlCopyUnicodeString(&SmpTempFilesDir,&local_18);
      }
      if (local_10 != 0) {
        RtlFreeUnicodeString(&local_18);
      }
    }
  }
  return 0;
}



===== SmpConfigureS0InitCmd @ 1400141f0 =====

undefined8 SmpConfigureS0InitCmd(undefined8 param_1,undefined8 param_2,void *param_3)

{
  undefined8 uVar1;
  
  if (param_3 == (void *)0x0) {
    SmpS0CommandOverride = 0;
  }
  else {
    uVar1 = RtlInitUnicodeStringEx(&SmpS0InitCmd,param_3);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    PTR_u_wininit_exe_140030e40 =
         (undefined *)
         RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                         DAT_140030e3a);
    if (PTR_u_wininit_exe_140030e40 == (undefined *)0x0) {
      return 0xc0000017;
    }
    memcpy(PTR_u_wininit_exe_140030e40,param_3,(ulonglong)DAT_140030e3a);
    SmpS0CommandOverride = 1;
  }
  return 0;
}



===== SmpConfigureSubSystems @ 140014290 =====

int SmpConfigureSubSystems
              (wchar_t *param_1,int param_2,longlong param_3,int param_4,undefined8 param_5,
              int *param_6)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 != 7) {
    iVar1 = _wcsicmp(param_1,L"Kmode");
    if (iVar1 == 0) {
      if (param_2 - 1U < 2) {
        iVar2 = SmpSaveRegistryValue((longlong *)(param_6 + 6),param_3,0,1);
        if (-1 < iVar2) {
          *param_6 = *param_6 + 1;
          param_6[1] = param_6[1] + param_4 + 2;
        }
      }
    }
    else {
      iVar1 = _wcsicmp(param_1,L"Required");
      if (iVar1 != 0) {
        iVar1 = _wcsicmp(param_1,L"Optional");
        if (iVar1 != 0) {
          iVar2 = SmpSaveRegistryValue((longlong *)(param_6 + 2),param_1,param_3,1);
        }
      }
    }
  }
  return iVar2;
}



===== SmpConfigureWaitForPagingFiles @ 140014390 =====

undefined8
SmpConfigureWaitForPagingFiles
          (undefined8 param_1,undefined8 param_2,undefined4 *param_3,int param_4)

{
  if (param_4 == 4) {
    SmpWaitForPagingFiles = *param_3;
  }
  else {
    SmpWaitForPagingFiles = 0;
  }
  return 0;
}



===== SmpCreateDynamicEnvironmentVariables @ 1400143b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpCreateDynamicEnvironmentVariables(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  undefined1 auStack_5a8 [32];
  wchar_t *local_588;
  undefined4 *local_580;
  undefined4 local_578 [2];
  undefined8 local_570;
  undefined8 local_568;
  wchar_t *local_560;
  undefined8 local_558;
  wchar_t *local_550;
  undefined8 local_548;
  wchar_t *local_540;
  undefined8 local_538;
  wchar_t *local_530;
  undefined8 local_528;
  wchar_t *local_520;
  undefined8 local_518;
  wchar_t *local_510;
  undefined8 local_508;
  wchar_t *local_500;
  undefined8 local_4f8;
  wchar_t *local_4f0;
  undefined4 local_4d8;
  undefined4 local_4d4;
  undefined8 local_4d0;
  undefined8 *local_4c8;
  undefined4 local_4c0;
  undefined4 local_4bc;
  undefined8 local_4b8;
  undefined8 uStack_4b0;
  undefined8 local_4a8;
  undefined4 local_4a0;
  wchar_t local_498 [16];
  wchar_t local_478 [8];
  wchar_t local_468 [12];
  wchar_t local_450 [12];
  wchar_t local_438 [6];
  wchar_t local_42c [250];
  undefined1 local_238 [12];
  undefined1 local_22c [500];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_5a8;
  local_568 = 0x60004;
  local_4a8 = 0;
  local_4a0 = 0;
  builtin_wcsncpy(local_468,L"Windows_NT",0xb);
  builtin_wcsncpy(local_498 + 4,L"x86",4);
  builtin_wcsncpy(local_478,L"AMD64",6);
  builtin_wcsncpy(local_498,L"ARM",4);
  builtin_wcsncpy(local_498 + 8,L"ARM64",6);
  local_560 = L"OS";
  local_530 = L"\\Registry\\Machine\\Hardware\\Description\\System\\CentralProcessor\\0";
  local_550 = L"PROCESSOR_ARCHITECTURE";
  local_540 = L"PROCESSOR_LEVEL";
  local_510 = L"PROCESSOR_IDENTIFIER";
  local_500 = L"PROCESSOR_REVISION";
  local_520 = L"Identifier";
  local_4f0 = L"VendorIdentifier";
  local_4d4 = 0;
  local_4bc = 0;
  local_570 = 0;
  builtin_wcsncpy(local_450,L"Unknown",8);
  local_538 = 0x820080;
  local_558 = 0x2e002c;
  local_548 = 0x20001e;
  local_518 = 0x2a0028;
  local_508 = 0x260024;
  local_528 = 0x160014;
  local_4f8 = 0x220020;
  uVar1 = NtQuerySystemInformation(1,&local_4a8,0xc,0);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    uVar5 = 0xc91;
    goto LAB_1400147bb;
  }
  local_588 = local_468;
  local_580 = (undefined4 *)CONCAT44(local_580._4_4_,0x16);
  uVar1 = NtSetValueKey(param_1,&local_568,0,1);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    uVar5 = 0xca0;
    pwVar7 = local_560;
  }
  else {
    if ((short)local_4a8 == 0) {
      local_588 = local_498 + 4;
LAB_1400145d4:
      local_578[0] = 8;
    }
    else {
      if ((short)local_4a8 == 5) {
        local_588 = local_498;
        goto LAB_1400145d4;
      }
      if ((short)local_4a8 == 9) {
        local_588 = local_478;
LAB_1400145bd:
        local_578[0] = 0xc;
      }
      else {
        if ((short)local_4a8 == 0xc) {
          local_588 = local_498 + 8;
          goto LAB_1400145bd;
        }
        local_588 = local_450;
        local_578[0] = 0x10;
      }
    }
    local_580 = (undefined4 *)CONCAT44(local_580._4_4_,local_578[0]);
    uVar1 = NtSetValueKey(param_1,&local_558,0,1);
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      uVar5 = 0xccb;
      pwVar7 = local_550;
    }
    else {
      RtlStringCbPrintfW(local_438,0x200,L"%u",local_4a8 >> 0x10 & 0xffff);
      lVar6 = -1;
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (local_438[lVar3] != L'\0');
      local_580 = (undefined4 *)CONCAT44(local_580._4_4_,(int)lVar3 * 2 + 2);
      local_588 = local_438;
      uVar1 = NtSetValueKey(param_1,&local_548,0,1);
      uVar4 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        uVar5 = 0xcf0;
        pwVar7 = local_540;
      }
      else {
        local_4c8 = &local_538;
        local_4d8 = 0x30;
        local_4d0 = 0;
        local_4c0 = 0x40;
        local_4b8 = 0;
        uStack_4b0 = 0;
        uVar1 = NtOpenKey(&local_570,0x20019,&local_4d8);
        uVar4 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          uVar5 = 0xd04;
          pwVar7 = local_530;
        }
        else {
          local_580 = local_578;
          local_588 = (wchar_t *)CONCAT44(local_588._4_4_,0x200);
          uVar1 = NtQueryValueKey(local_570,&local_528,2,local_438);
          uVar4 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            NtClose();
            uVar5 = 0xd17;
            pwVar7 = local_520;
            goto LAB_140014580;
          }
          local_580 = local_578;
          local_588 = (wchar_t *)CONCAT44(local_588._4_4_,0x200);
          iVar2 = NtQueryValueKey(local_570,&local_4f8,2,local_238);
          NtClose(local_570);
          if (-1 < iVar2) {
            lVar3 = -1;
            do {
              lVar3 = lVar3 + 1;
            } while (local_42c[lVar3] != L'\0');
            uVar4 = RtlStringCbPrintfW(local_42c + lVar3,(0xfa - lVar3) * 2,L", %ws",local_22c);
            uVar1 = (uint)uVar4;
            uVar4 = uVar4 & 0xffffffff;
            if ((int)uVar1 < 0) {
              uVar5 = 0xd42;
LAB_1400147bb:
              SmpLogFailure(0x140029e70,uVar5,uVar1);
              return uVar4;
            }
          }
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_42c[lVar3] != L'\0');
          local_580 = (undefined4 *)CONCAT44(local_580._4_4_,(int)lVar3 * 2 + 2);
          local_588 = local_42c;
          uVar1 = NtSetValueKey(param_1,&local_518,0,1);
          uVar4 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            uVar5 = 0xd52;
            pwVar7 = local_510;
          }
          else {
            if ((short)local_4a8 == 0) {
              if ((local_4a8._4_2_ & 0xff00) != 0xff00) goto LAB_140014881;
              RtlStringCbPrintfW(local_438,0x200,L"%02x",local_4a8 >> 0x20 & 0xff);
              _wcsupr_s(local_438,0x100);
            }
            else {
              if ((((short)local_4a8 == 5) || ((short)local_4a8 == 9)) || ((short)local_4a8 == 0xc))
              {
LAB_140014881:
                pwVar7 = L"%04x";
              }
              else {
                pwVar7 = L"%u";
              }
              RtlStringCbPrintfW(local_438,0x200,pwVar7,(ulonglong)local_4a8._4_2_);
            }
            do {
              lVar6 = lVar6 + 1;
            } while (local_438[lVar6] != L'\0');
            local_580 = (undefined4 *)CONCAT44(local_580._4_4_,(int)lVar6 * 2 + 2);
            local_588 = local_438;
            uVar1 = NtSetValueKey(param_1,&local_508,0,1);
            uVar4 = (ulonglong)uVar1;
            if ((int)uVar1 < 0) {
              uVar5 = 0xd9e;
              pwVar7 = local_500;
            }
            else {
              if (SmpSafeBootOption == -1) {
                return 0;
              }
              uVar5 = 0x12;
              if (SmpSafeBootOption == 1) {
LAB_140014917:
                local_588 = L"MINIMAL";
LAB_14001491e:
                uVar5 = 0x10;
              }
              else {
                if (SmpSafeBootOption == 2) {
                  local_588 = L"NETWORK";
                  goto LAB_14001491e;
                }
                if (SmpSafeBootOption != 3) goto LAB_140014917;
                local_588 = L"DSREPAIR";
              }
              local_580 = (undefined4 *)CONCAT44(local_580._4_4_,uVar5);
              uVar1 = NtSetValueKey(param_1,&SmpSafeBootEnvironmentValue,0,1);
              uVar4 = (ulonglong)uVar1;
              if (-1 < (int)uVar1) {
                return 0;
              }
              pwVar7 = L"SAFEBOOT_OPTION";
              uVar5 = 0xdc7;
            }
          }
        }
      }
    }
  }
LAB_140014580:
  SmpLogFailureString(0x140029e70,uVar5,(longlong)pwVar7,uVar1);
  return uVar4;
}



===== SmpDeleteFile @ 14001499c =====

int SmpDeleteFile(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res8 = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_48 = 0;
  uStack_40 = 0;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = param_1;
  iVar1 = NtOpenFile(&local_res8,0x10100,&local_38,&local_48,7,0x4040);
  if (iVar1 < 0) {
    if (param_1 == 0) {
      lVar3 = 0;
    }
    else {
      lVar3 = *(longlong *)(param_1 + 8);
    }
    uVar2 = 0x2f6f;
  }
  else {
    iVar1 = SmpSetTargetAttributes(local_res8,0x80);
    if (-1 < iVar1) {
      iVar1 = SmpDeleteTargetFile();
      goto LAB_140014a6c;
    }
    if (param_1 == 0) {
      lVar3 = 0;
    }
    else {
      lVar3 = *(longlong *)(param_1 + 8);
    }
    uVar2 = 0x2f7c;
  }
  SmpLogFailureString(0x14002a360,uVar2,lVar3,iVar1);
LAB_140014a6c:
  if (local_res8 != 0) {
    NtClose();
  }
  return iVar1;
}



===== SmpDeleteTargetFile @ 140014a9c =====

void SmpDeleteTargetFile(void)

{
  undefined1 local_res10 [24];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 1;
  local_18 = 0;
  uStack_10 = 0;
  NtSetInformationFile(0,&local_18,local_res10,1,0xd);
  return;
}



===== SmpFinishPFROLogging @ 140014adc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpFinishPFROLogging(undefined8 param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStackY_2b8 [32];
  longlong local_248 [6];
  wchar_t local_218 [256];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_2b8;
  local_248[0] = 0;
  local_248[1] = 0;
  local_248[2] = 0;
  local_248[3] = 0;
  local_248[4] = 0;
  if (SmpLogFileHandle == 0) {
    return;
  }
  if (param_2 != '\0') {
    SmpGetTime(local_248 + 3);
    iVar1 = RtlStringCbPrintfExW
                      (local_218,0x200,(size_t *)0x0,local_248,0,
                       L"%d/%d/%d %d:%d:%d - %d Successful PFRO operations\r\n\r\n",
                       (char)((ulonglong)local_248[3] >> 0x10));
    if (iVar1 < 0) {
      uVar2 = 0x308c;
    }
    else {
      iVar1 = NtWriteFile(SmpLogFileHandle,0,0,0);
      if (-1 < iVar1) goto LAB_140014c02;
      uVar2 = 0x30a1;
    }
    SmpLogFailure(0x14002a460,uVar2,iVar1);
  }
LAB_140014c02:
  NtClose(SmpLogFileHandle);
  SmpLogFileHandle = 0;
  return;
}



===== SmpForceDeleteTargetFile @ 140014c44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpForceDeleteTargetFile(ushort *param_1,char param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  HANDLE local_88;
  undefined8 local_80;
  undefined8 local_78;
  ushort *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  local_64 = 0;
  local_88 = (HANDLE)0x0;
  local_78 = 0;
  local_80 = 0x30;
  local_30 = 0;
  local_68 = 0x40;
  local_50 = 0;
  uStack_48 = 0;
  bVar1 = false;
  local_98 = 3;
  local_40 = 0;
  uStack_38 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = param_1;
  uVar5 = SmpOpenTargetFile(&local_88,0x110100,&local_80,'\0');
  uVar6 = uVar5 & 0xffffffff;
  if (-1 < (int)uVar5) {
    if (param_2 == '\x01') {
      bVar2 = SmpPathCanBeTrustedIsNotARedirection(local_88,param_1,0);
      if (!bVar2) {
        uVar6 = 0xc000050b;
        goto LAB_140014d4b;
      }
    }
    uVar3 = SmpDeleteTargetFile();
    uVar6 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      iVar4 = NtQueryAttributesFile(&local_80,&local_50);
      if ((-1 < iVar4) && ((local_30 & 1) != 0)) {
        uVar3 = SmpSetTargetAttributes(local_88,(uint)local_30 & 0xfffffffe);
        uVar6 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          bVar1 = true;
          uVar3 = SmpDeleteTargetFile();
          uVar6 = (ulonglong)uVar3;
          if (-1 < (int)uVar3) {
            bVar1 = false;
            uVar6 = 0;
          }
        }
      }
    }
  }
LAB_140014d4b:
  if (local_88 != (HANDLE)0x0) {
    if (bVar1) {
      SmpSetTargetAttributes(local_88,(uint)local_30);
    }
    NtClose(local_88);
  }
  return uVar6;
}



===== SmpGetPlatformBinary @ 140014da0 =====

/* WARNING: Removing unreachable block (ram,0x000140014f9d) */
/* WARNING: Removing unreachable block (ram,0x000140014e77) */
/* WARNING: Removing unreachable block (ram,0x000140014ff6) */
/* WARNING: Removing unreachable block (ram,0x000140015053) */

int SmpGetPlatformBinary(undefined8 *param_1,undefined8 *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong local_res18;
  undefined8 local_res20;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined *local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  local_res20 = 0;
  local_res18 = 0;
  bVar1 = false;
  lVar5 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (undefined *)0x0;
  uStack_40 = 0;
  iVar3 = NtQuerySystemInformation(0x85);
  if (iVar3 != -0x3fffffdd) {
    if (iVar3 != -0x3fffff45) {
      SmpSendPlatformBinaryStatus(1,0,0,(int **)0x0);
    }
    return -0x3fffffff;
  }
  lVar4 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
  bVar2 = false;
  if (lVar4 != 0) {
    iVar3 = NtQuerySystemInformation(0x85);
    if (iVar3 < 0) goto LAB_140015028;
    local_res20 = 0;
    local_48 = &SmpPlatformBinaryName;
    local_58 = CONCAT44(local_58._4_4_,0x30);
    uStack_50 = 0;
    uStack_40 = uStack_40 & 0xffffffff00000000;
    local_38 = 0;
    uStack_30 = 0;
    iVar3 = NtCreateFile(&local_res18);
    if (iVar3 < 0) {
      local_res18 = 0;
      goto LAB_140015028;
    }
    bVar1 = true;
    iVar3 = NtWriteFile(local_res18);
    if (iVar3 < 0) goto LAB_140015028;
    lVar5 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
    bVar2 = bVar1;
    if (lVar5 != 0) {
      *param_1 = 0;
      param_1[1] = 0;
      *(undefined2 *)((longlong)param_1 + 2) = 0x16;
      param_1[1] = lVar5;
      iVar3 = RtlAppendUnicodeToString(param_1);
      *param_2 = 0;
      goto LAB_140015028;
    }
  }
  bVar1 = bVar2;
  iVar3 = -0x3fffffff;
LAB_140015028:
  if (lVar4 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
  }
  if (local_res18 != 0) {
    NtClose();
  }
  if (iVar3 < 0) {
    param_1[1] = 0;
    if (lVar5 != 0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
    }
    if (bVar1) {
      NtDeleteFile(&local_58);
    }
    SmpSendPlatformBinaryStatus(1,0,0,(int **)0x0);
  }
  return iVar3;
}



===== SmpInit @ 1400150fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SmpInit(void)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  byte *pbVar4;
  undefined4 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStack_508 [32];
  undefined4 local_4e8 [2];
  longlong local_4e0;
  undefined4 local_4d8 [2];
  undefined8 local_4d0;
  wchar_t *local_4c8;
  undefined4 local_4c0;
  undefined4 local_4bc;
  undefined8 local_4b8;
  undefined8 *local_4b0;
  undefined4 local_4a8;
  undefined4 local_4a4;
  undefined8 local_4a0;
  undefined8 uStack_498;
  undefined8 local_490;
  wchar_t *local_488;
  int local_478 [2];
  longlong alStack_470 [129];
  undefined4 local_68 [4];
  undefined8 local_58;
  undefined8 local_48;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_508;
  local_4bc = 0;
  local_4a4 = 0;
  memset(local_478,0,0x408);
  local_4e8[0] = 0;
  local_488 = L"\\SmApiPort";
  local_4e0 = 0;
  local_4c8 = L"\\Device\\VolumesSafeForWriteAccess";
  local_490 = 0x160014;
  local_4d0 = 0x440042;
  _SmpInitSaveGlobals = &SmpInitLastCall;
  SmBaseTag = RtlCreateTagHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,L"SMSS!",
                               L"INIT");
  uVar1 = NtQuerySystemInformation(0,&SmpSystemInfo,0x40,0);
  uVar7 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    uVar5 = 0x6ba;
    _SmpInitProgressByLine = 0x6b8;
    _SmpInitLastCall = NtQuerySystemInformation_exref;
    _SmpInitReturnStatus = uVar1;
    goto LAB_140015225;
  }
  iVar2 = NtQuerySystemInformation(0xc3,&SmpSystemWriteConstraintInfo,8);
  if (iVar2 < 0) {
    SmpLogFailure(0x1400295a8,0x6ca,iVar2);
    SmpSystemWriteConstraintInfo = 0;
  }
  local_4d8[0] = 1;
  NtSetInformationProcess(0xffffffffffffffff,0xc,local_4d8);
  uVar3 = SmpInitializeKnownSubSystems();
  uVar7 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    _SmpInitProgressByLine = 0x6df;
    uVar5 = 0x6e0;
    _SmpInitLastCall = SmpInitializeKnownSubSystems;
  }
  else {
    SmpManufacturingMode = 0;
    uVar1 = NtQuerySystemInformation(0x9d,0,0,local_4e8);
    uVar7 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      _SmpInitProgressByLine = 0x719;
      _SmpInitLastCall = NtQuerySystemInformation_exref;
      _SmpInitReturnStatus = uVar1;
      SmpLogFailure(0x1400295a8,0x71a,uVar1);
      return 0xc0000001;
    }
    if (uVar1 == 0xc0000004) {
      pbVar4 = (byte *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                       SmBaseTag,local_4e8[0]);
      if (pbVar4 == (byte *)0x0) {
        uVar7 = 0xc000009a;
        _SmpInitProgressByLine = 0x6f7;
        uVar5 = 0x6f8;
        _SmpInitReturnStatus = 0xc000009a;
        _SmpInitLastCall = RtlAllocateHeap_exref;
        goto LAB_140015225;
      }
      uVar1 = NtQuerySystemInformation(0x9d,pbVar4,local_4e8[0],local_4e8);
      if ((int)uVar1 < 0) {
        RtlFreeHeap();
        _SmpInitProgressByLine = 0x704;
        _SmpInitLastCall = NtQuerySystemInformation_exref;
        _SmpInitReturnStatus = uVar1;
        SmpLogFailure(0x1400295a8,0x706,uVar1);
        return (ulonglong)uVar1;
      }
      SmpManufacturingMode = *pbVar4 & 1;
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pbVar4);
      uVar1 = SmpCreateSecurityDescriptors('\x01');
      uVar7 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        _SmpInitProgressByLine = 0x726;
        uVar5 = 0x727;
        _SmpInitLastCall = SmpCreateSecurityDescriptors;
      }
      else {
        local_4c0 = 0x30;
        local_4b0 = &local_490;
        local_4b8 = 0;
        local_4a8 = 0;
        local_4a0 = SmpApiPortSecurityDescriptor;
        uStack_498 = 0;
        memset(local_68,0,0x48);
        local_68[0] = 0x20000;
        local_58 = 0x148;
        local_48 = 1000000;
        uVar1 = NtAlpcCreatePort(&SmpApiConnectionPort,&local_4c0,local_68);
        uVar7 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          uVar5 = 0x73f;
          _SmpInitProgressByLine = 0x73e;
          _SmpInitLastCall = NtAlpcCreatePort_exref;
          _SmpInitReturnStatus = uVar1;
          goto LAB_140015225;
        }
        SmpUniqueProcessId = (ulonglong)ClientId.UniqueProcess & 0xffffffff;
        SmpActiveProcessorCount = _DAT_7ffe03c0;
        uVar1 = NtQuerySystemInformation(0x37,local_478,0x408);
        uVar7 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          uVar5 = 0x752;
          _SmpInitProgressByLine = 0x751;
          _SmpInitLastCall = NtQuerySystemInformation_exref;
          _SmpInitReturnStatus = uVar1;
          goto LAB_140015225;
        }
        SmpMaximumNodeCount = local_478[0] + 1;
        RtlInitializeBitMap(&SmpNodeBitmap,&SmpNodeBitmapBuffer);
        RtlClearAllBits(&SmpNodeBitmap);
        uVar6 = 0;
        uVar1 = SmpMaximumNodeCount;
        if (SmpMaximumNodeCount != 0) {
          do {
            if (alStack_470[(ulonglong)uVar6 * 2] != 0) {
              RtlSetBits(&SmpNodeBitmap,uVar6,1);
              uVar1 = SmpMaximumNodeCount;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar1);
        }
        local_4b0 = &local_4d0;
        local_4c0 = 0x30;
        local_4b8 = 0;
        local_4a8 = 0x40;
        local_4a0 = 0;
        uStack_498 = 0;
        iVar2 = NtOpenEvent(&local_4e0,0x1f0003,&local_4c0);
        if (iVar2 < 0) {
          SmpLogFailureString(0x1400295a8,0x77c,(longlong)local_4c8,iVar2);
          local_4e0 = 0;
        }
        uVar1 = SmpInitializePendingRename();
        uVar7 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          _SmpInitProgressByLine = 0x788;
          uVar5 = 0x78a;
          _SmpInitLastCall = SmpInitializePendingRename;
        }
        else {
          uVar7 = SmpLoadDataFromRegistry(local_4e0);
          if (-1 < iVar2) {
            NtClose(local_4e0);
          }
          if ((int)uVar7 < 0) {
            return uVar7 & 0xffffffff;
          }
          uVar1 = InitializeWow64OnBoot();
          uVar7 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            return uVar7;
          }
          _SmpInitProgressByLine = 0x7a3;
          uVar5 = 0x7a5;
          _SmpInitLastCall = InitializeWow64OnBoot;
        }
      }
    }
    else {
      uVar5 = 0x713;
      _SmpInitProgressByLine = 0x711;
      _SmpInitLastCall = NtQuerySystemInformation_exref;
    }
  }
  _SmpInitReturnStatus = (uint)uVar7;
LAB_140015225:
  SmpLogFailure(0x1400295a8,uVar5,(int)uVar7);
  return uVar7;
}



===== SmpInitializeDosDevices @ 140015700 =====

int SmpInitializeDosDevices(void)

{
  longlong *plVar1;
  int iVar2;
  undefined4 uVar3;
  longlong *plVar4;
  wchar_t *pwVar5;
  ushort uVar6;
  undefined8 local_res8;
  longlong local_68;
  wchar_t *local_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong *local_48;
  uint local_40;
  undefined4 uStack_3c;
  longlong local_38;
  undefined8 uStack_30;
  
  local_58 = 0x30;
  local_40 = 0xd0;
  uStack_3c = 0;
  local_60 = L"\\??";
  local_48 = &local_68;
  local_res8 = 0;
  local_68 = 0x80006;
  local_50 = 0;
  uVar6 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar2 = NtOpenDirectoryObject(&SmpDosDevicesObjectDirectory,0xf000f,&local_58);
  if (iVar2 < 0) {
    uVar3 = 0xe0a;
    pwVar5 = local_60;
LAB_1400158b6:
    SmpLogFailureString(0x140029f08,uVar3,(longlong)pwVar5,iVar2);
  }
  else {
    plVar4 = SmpDosDevicesList;
    while ((longlong **)plVar4 != &SmpDosDevicesList) {
      local_50 = SmpDosDevicesObjectDirectory;
      local_48 = plVar4 + 2;
      local_58 = CONCAT44(local_58._4_4_,0x30);
      local_40 = 0xd0;
      local_38 = SmpPrimarySecurityDescriptor;
      uStack_30 = 0;
      if (SmpPrimarySecurityDescriptor != 0) {
        uVar6 = *(ushort *)(SmpPrimarySecurityDescriptor + 2) & 8;
        *(ushort *)(SmpPrimarySecurityDescriptor + 2) =
             *(ushort *)(SmpPrimarySecurityDescriptor + 2) | 8;
      }
      plVar1 = plVar4 + 4;
      iVar2 = NtCreateSymbolicLinkObject(&local_res8,0xf0001,&local_58,plVar1);
      if (iVar2 == 0x40000000) {
        NtMakeTemporaryObject(local_res8);
        NtClose(local_res8);
        if ((short)*plVar1 == 0) {
          iVar2 = 0;
        }
        else {
          local_40 = local_40 & 0xffffff7f;
          iVar2 = NtCreateSymbolicLinkObject(&local_res8,0xf0001,&local_58,plVar1);
        }
      }
      if (local_38 != 0) {
        *(ushort *)(local_38 + 2) =
             *(ushort *)(local_38 + 2) ^ (*(ushort *)(local_38 + 2) ^ uVar6) & 8;
      }
      if (iVar2 < 0) {
        pwVar5 = (wchar_t *)plVar4[3];
        uVar3 = 0xe3e;
        goto LAB_1400158b6;
      }
      NtClose(local_res8);
      plVar1 = (longlong *)*plVar4;
      SmpFreeSavedRegistryEntry(plVar4);
      plVar4 = plVar1;
    }
  }
  return iVar2;
}



===== SmpInitializeKnownDlls @ 1400158f0 =====

ulonglong SmpInitializeKnownDlls(uint param_1)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  longlong lVar7;
  byte bVar8;
  longlong *plVar9;
  longlong lVar10;
  char local_res8 [8];
  longlong local_res10;
  longlong local_res18;
  short local_48 [4];
  wchar_t *local_40;
  undefined8 local_38;
  wchar_t *local_30;
  
  local_30 = L"\\KnownDlls32";
  local_38 = 0x1a0018;
  local_40 = L"\\SysWOW64";
  local_res18 = 0;
  local_res10 = 0;
  local_48[0] = 0x12;
  local_48[1] = 0x14;
  local_48[2] = 0;
  local_48[3] = 0;
  local_res8[0] = '\0';
  iVar2 = RtlWow64IsWowGuestMachineSupported(0x14c,local_res8);
  bVar8 = (byte)param_1;
  lVar7 = 0;
  lVar10 = 0;
  if ((iVar2 < 0) || (local_res8[0] == '\0')) {
LAB_1400159b3:
    iVar2 = 0;
  }
  else {
    uVar4 = SmpOpenKnownDllsHandles(&local_38,local_48,0,&local_res18,&local_res10);
    uVar5 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      SmLogFailureInt(0x14002a060,0x11cf,(ulonglong)param_1,0,(int)uVar4);
      goto LAB_140015a4a;
    }
    lVar7 = local_res18;
    lVar10 = local_res10;
    if (local_res18 == 0) goto LAB_1400159b3;
    iVar2 = 1;
  }
  uVar5 = SmpInitializeKnownDllsInternal
                    (SmpKnownDllsObjectDirectory,SmpKnownDllsFileDirectory,0,iVar2,bVar8);
  iVar3 = (int)uVar5;
  if (iVar3 < 0) {
    uVar6 = 0x11fa;
LAB_1400159de:
    uVar5 = uVar5 & 0xffffffff;
    SmLogFailureInt(0x14002a060,uVar6,(ulonglong)param_1,0,iVar3);
  }
  else {
    if (lVar7 != 0) {
      uVar5 = SmpInitializeKnownDllsInternal(lVar7,lVar10,1,iVar2,bVar8);
      iVar3 = (int)uVar5;
      if (iVar3 < 0) {
        uVar6 = 0x1228;
        goto LAB_1400159de;
      }
    }
    uVar5 = 0;
  }
  if (lVar10 != 0) {
    NtClose(lVar10);
  }
  if (lVar7 != 0) {
    NtClose(lVar7);
  }
LAB_140015a4a:
  if ((bVar8 & 3) != 1) {
    if (SmpKnownDllsFileDirectory != 0) {
      NtClose();
    }
    if (SmpKnownDllsObjectDirectory != 0) {
      NtClose();
    }
    plVar9 = SmpKnownDllsList;
    while ((longlong **)plVar9 != &SmpKnownDllsList) {
      plVar1 = (longlong *)*plVar9;
      SmpFreeSavedRegistryEntry(plVar9);
      plVar9 = plVar1;
    }
    plVar9 = SmpExcludeKnownDllsList;
    while ((longlong **)plVar9 != &SmpExcludeKnownDllsList) {
      plVar1 = (longlong *)*plVar9;
      SmpFreeSavedRegistryEntry(plVar9);
      plVar9 = plVar1;
    }
    SmpEventWriteULONG(&SmssEvt_InitializeKnownDlls_Stop,(int)uVar5);
  }
  return uVar5;
}



===== SmpInitializeKnownDllsAsync @ 140015af0 =====

int SmpInitializeKnownDllsAsync(void)

{
  int iVar1;
  longlong local_res8;
  undefined8 local_res10;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  local_1c = 0;
  local_res10 = 0;
  local_30 = 0;
  local_40 = L"\\KnownDlls\\SmKnownDllsInitialized";
  local_28 = &local_48;
  local_38 = 0x30;
  local_48 = 0x440042;
  local_20 = 0x50;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = NtCreateEvent(&local_res8,0x1f0003,&local_38,0,0);
  if (-1 < iVar1) {
    iVar1 = TpAllocWork(&local_res10,SmpInitializeKnownDllsWorker,local_res8,&SmpCallbackEnviron);
    if (iVar1 < 0) {
      SmpLogFailure(0x14002a008,0x1063,iVar1);
    }
    else {
      TpPostWork(local_res10);
      TpReleaseWork();
      local_res8 = 0;
    }
  }
  if (local_res8 != 0) {
    NtSetEvent(local_res8,0);
    NtClose(local_res8);
  }
  return iVar1;
}



===== SmpInitializeKnownDllsWorker @ 140015c10 =====

void SmpInitializeKnownDllsWorker(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 *local_18;
  longlong local_10;
  
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = SmpInitializeKnownDlls(3);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    RtlInitUnicodeString(&local_28,L"Failure in known dll worker.");
    local_18 = &local_28;
    local_10 = (longlong)iVar1;
    SmpLogFailure(0x140029f98,0x1019,iVar1);
                    /* WARNING: Subroutine does not return */
    SmpTerminate(&local_18,1,2);
  }
  NtSetEvent(param_2,0);
  NtClose(param_2);
  return;
}



===== SmpInvokeAutoChk @ 140015cb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SmpInvokeAutoChk(ushort *param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined1 auStackY_488 [32];
  undefined8 local_448;
  wchar_t *pwStack_440;
  wchar_t local_438 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_488;
  local_448 = 0;
  pwStack_440 = (wchar_t *)0x0;
  if ((param_4 & 0x10) == 0) {
    local_448 = 0x4000000;
    pwStack_440 = local_438;
    uVar3 = param_4;
    iVar1 = RtlAppendUnicodeStringToString(&local_448,param_1);
    if (-1 < iVar1) {
      iVar1 = RtlAppendUnicodeToString(&local_448,L" ");
      if (-1 < iVar1) {
        iVar1 = RtlAppendUnicodeStringToString(&local_448,param_3);
        if (-1 < iVar1) {
          SmpExecuteImage(param_1,param_2,&local_448,uVar3,(uint *)0x0,
                          (uint)param_4 & 0xfffffffb | 0x10000,(undefined8 *)0x0);
        }
      }
    }
  }
  else {
    uVar2 = RtlStringCbPrintfW(local_438,0x400,L"%wZ program not found - skipping AUTOCHECK\n",
                               param_1);
    if (-1 < (int)uVar2) {
      RtlInitUnicodeStringEx(&local_448,local_438);
      NtDisplayString(&local_448);
    }
  }
  return 0;
}



===== SmpLoadDataFromRegistry @ 140015df4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SmpLoadDataFromRegistry(longlong param_1)

{
  byte bVar1;
  longlong *plVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  byte *pbVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong *plVar15;
  wchar_t *pwVar16;
  undefined8 *puVar17;
  undefined1 auStackY_3a8 [32];
  char local_378 [4];
  undefined4 local_374;
  longlong local_370;
  undefined4 local_368 [2];
  longlong local_360;
  longlong local_358;
  longlong local_350;
  undefined8 local_348;
  undefined8 uStack_340;
  longlong *local_338;
  undefined8 uStack_330;
  undefined8 local_328;
  ulonglong uStack_320;
  int *local_318;
  longlong lStack_310;
  undefined8 local_308;
  longlong local_300;
  longlong local_2f8 [2];
  wchar_t *local_2e8;
  longlong local_2e0;
  wchar_t *local_2d8;
  longlong local_2d0;
  wchar_t *local_2c8;
  longlong local_2c0;
  wchar_t *local_2b8;
  undefined8 local_2a8;
  undefined8 local_2a0;
  undefined8 local_298;
  byte local_252;
  wchar_t local_238 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_3a8;
  local_328 = 0;
  uStack_320 = uStack_320 & 0xffffffff00000000;
  local_358 = 0;
  local_2f8[0] = 0;
  local_300 = 0;
  local_348 = 0;
  uStack_340 = 0;
  local_2a8._4_4_ = 0;
  local_338 = (longlong *)0x0;
  uStack_330 = 0;
  local_318 = (int *)0x0;
  lStack_310 = 0;
  memset(&local_2a8,0,100);
  local_2d0 = 0x740072;
  local_2c8 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MiniNT";
  local_2e0 = 0x140012;
  local_2d8 = L"\\Sessions";
  local_2c0 = 0x9e009c;
  local_2b8 = 
  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Environment";
  local_2f8[1] = 0x2a0028;
  local_2e8 = L"NUMBER_OF_PROCESSORS";
  lVar9 = 0;
  local_374 = 0;
  _DAT_140032a08 = &SmpBootExecuteList;
  SmpBootExecuteList = (longlong *)&SmpBootExecuteList;
  _DAT_140032a18 = &SmpBootExecuteNoPnpSyncList;
  SmpBootExecuteNoPnpSyncList = (longlong *)&SmpBootExecuteNoPnpSyncList;
  _DAT_140032a28 = &SmpPlatformExecuteList;
  SmpPlatformExecuteList = (longlong *)&SmpPlatformExecuteList;
  _DAT_140032a38 = &SmpSetupExecuteList;
  SmpSetupExecuteList = (longlong *)&SmpSetupExecuteList;
  _DAT_140032a48 = &SmpSetupExecuteNoPnpSyncList;
  SmpSetupExecuteNoPnpSyncList = (longlong *)&SmpSetupExecuteNoPnpSyncList;
  _DAT_140032b68 = &SmpPagingFileList;
  SmpPagingFileList = &SmpPagingFileList;
  _DAT_140032a58 = &SmpDosDevicesList;
  SmpDosDevicesList = &SmpDosDevicesList;
  _DAT_140032a68 = &SmpFileRenameList;
  SmpFileRenameList = &SmpFileRenameList;
  DAT_140032a78 = &SmpKnownDllsList;
  SmpKnownDllsList = &SmpKnownDllsList;
  _DAT_140032a88 = &SmpExcludeKnownDllsList;
  SmpExcludeKnownDllsList = &SmpExcludeKnownDllsList;
  DAT_140032a98 = &SmpSubSystemsRequired;
  SmpSubSystemsRequired = &SmpSubSystemsRequired;
  DAT_140032aa8 = &SmpSubSystemsToDefer;
  SmpSubSystemsToDefer = &SmpSubSystemsToDefer;
  _DAT_140032b58 = &SmpExistingPageFilesList;
  SmpExistingPageFilesList = &SmpExistingPageFilesList;
  local_368[0] = 0;
  SmpClearTempFiles = 0;
  local_360 = 0;
  local_370 = 0;
  local_350 = 0;
  local_378[0] = '\0';
  RtlInitUnicodeString(&local_318,0);
  uVar8 = RtlGetNtSystemRoot();
  RtlStringCbPrintfW((wchar_t *)&SmpTempDirNameBuffer,0x20a,L"\\??\\%s",uVar8);
  RtlInitUnicodeString(&SmpTempFilesDir,&SmpTempDirNameBuffer);
  uVar5 = RtlCreateEnvironment(1,&SmpDefaultEnvironment);
  uVar14 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    uVar12 = 0x925;
    _SmpInitProgressByLine = 0x923;
    _SmpInitLastCall = RtlCreateEnvironment_exref;
  }
  else {
    local_338 = local_2f8 + 5;
    local_348 = CONCAT44(local_348._4_4_,0x30);
    uStack_340 = 0;
    uStack_330 = CONCAT44(uStack_330._4_4_,0x40);
    local_328 = 0;
    uStack_320 = 0;
    iVar6 = NtOpenKey(&local_370,0xf003f,&local_348);
    if (-1 < iVar6) {
      NtClose(local_370);
      local_370 = 0;
      SmpMiniNTBoot = '\x01';
    }
    SmpReadSafeBootOption();
    local_338 = local_2f8 + 7;
    local_348 = CONCAT44(local_348._4_4_,0x30);
    uStack_340 = 0;
    uStack_330 = CONCAT44(uStack_330._4_4_,0x40);
    local_328 = 0;
    uStack_320 = 0;
    uVar5 = NtOpenKey(&local_370,0xf003f,&local_348);
    uVar14 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) {
      uVar12 = 0x955;
      _SmpInitProgressByLine = 0x953;
      _SmpInitLastCall = NtOpenKey_exref;
    }
    else {
      NtDeleteValueKey(local_370,&SmpSafeBootEnvironmentValue);
      local_368[0] = 4;
      uVar5 = NtQuerySystemInformationEx(0x6b,local_368,4,0);
      uVar14 = (ulonglong)uVar5;
      if (uVar5 == 0xc0000004) {
        lVar9 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                local_374);
        if (lVar9 == 0) {
          uVar14 = 0xc000009a;
          _SmpInitProgressByLine = 0x980;
          uVar12 = 0x982;
          _SmpInitLastCall = RtlAllocateHeap_exref;
        }
        else {
          uVar5 = NtQuerySystemInformationEx(0x6b,local_368,4,lVar9);
          uVar14 = (ulonglong)uVar5;
          if ((int)uVar5 < 0) {
            uVar12 = 0x992;
            _SmpInitProgressByLine = 0x990;
            _SmpInitLastCall = NtQuerySystemInformationEx_exref;
          }
          else {
            uVar14 = 0;
            if (*(short *)(lVar9 + 10) != 0) {
              uVar13 = (ulonglong)*(ushort *)(lVar9 + 10);
              pbVar11 = (byte *)(lVar9 + 0x21);
              do {
                bVar1 = *pbVar11;
                pbVar11 = pbVar11 + 0x30;
                uVar14 = (ulonglong)((int)uVar14 + (uint)bVar1);
                uVar13 = uVar13 - 1;
              } while (uVar13 != 0);
            }
            RtlStringCbPrintfW(local_238,0x200,L"%u",uVar14);
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (local_238[lVar10] != L'\0');
            uVar5 = NtSetValueKey(local_370,local_2f8 + 1,0,1);
            if ((int)uVar5 < 0) {
              uVar12 = 0x9b1;
              _SmpInitProgressByLine = 0x9af;
              _SmpInitLastCall = NtSetValueKey_exref;
              pwVar16 = local_2e8;
LAB_1400162fd:
              uVar14 = (ulonglong)uVar5;
              _SmpInitReturnStatus = uVar5;
              SmpLogFailureString(0x140029c30,uVar12,(longlong)pwVar16,uVar5);
              goto LAB_140016b89;
            }
            RtlSetCurrentEnvironment(SmpDefaultEnvironment,&local_350);
            uVar5 = RtlQueryRegistryValuesEx(2,L"Session Manager",&SmpRegistryConfigurationTable);
            uVar14 = (ulonglong)uVar5;
            if ((int)uVar5 < 0) {
              uVar12 = 0x9c9;
              _SmpInitProgressByLine = 0x9c7;
              _SmpInitLastCall = RtlQueryRegistryValuesEx_exref;
            }
            else {
              uVar13 = SmpFinalizePathStrings();
              uVar14 = uVar13 & 0xffffffff;
              if ((int)uVar13 < 0) {
                _SmpInitProgressByLine = 0x9d2;
                _SmpInitLastCall = SmpFinalizePathStrings;
                uVar12 = 0x9d4;
              }
              else {
                SmpEventWrite(&SmssEvt_InitializeKnownDlls_Start);
                uVar13 = SmpOpenKnownDllsHandles
                                   ((undefined8 *)&SmpKnownDllsObjectDirectoryName,
                                    (short *)&SmpKnownDllsPathSuffix,1,&SmpKnownDllsObjectDirectory,
                                    &SmpKnownDllsFileDirectory);
                uVar14 = uVar13 & 0xffffffff;
                if ((int)uVar13 < 0) {
                  _SmpInitProgressByLine = 0x9e7;
                  _SmpInitLastCall = SmpOpenKnownDllsHandles;
                  uVar12 = 0x9e9;
                }
                else {
                  if ((SmpSoftBoot != '\0') && ((SmpLoadKnownDllsFlags & 2) != 0)) {
                    SmpLoadKnownDllsFlags = SmpLoadKnownDllsFlags | 1;
                  }
                  if ((SmpLoadKnownDllsFlags & 1) == 0) {
                    uVar14 = SmpInitializeKnownDlls(0);
                    uVar5 = (uint)uVar14;
LAB_140016434:
                    uVar14 = (ulonglong)uVar5;
                    if (-1 < (int)uVar5) {
                      uVar5 = SmpInitializeSessionManagement();
                      uVar14 = (ulonglong)uVar5;
                      if ((int)uVar5 < 0) {
                        _SmpInitProgressByLine = 0xa10;
                        _SmpInitLastCall = SmpInitializeSessionManagement;
                        uVar12 = 0xa12;
                      }
                      else {
                        RtlSetCurrentEnvironment(local_350,&SmpDefaultEnvironment);
                        local_350 = 0;
                        uVar5 = SmpInitializeDosDevices();
                        uVar14 = (ulonglong)uVar5;
                        if ((int)uVar5 < 0) {
                          _SmpInitProgressByLine = 0xa23;
                          _SmpInitLastCall = SmpInitializeDosDevices;
                          uVar12 = 0xa25;
                        }
                        else {
                          local_338 = local_2f8 + 3;
                          local_348 = CONCAT44(local_348._4_4_,0x30);
                          puVar17 = &local_348;
                          local_328 = SmpPrimarySecurityDescriptor;
                          uStack_340 = 0;
                          uStack_330 = CONCAT44(uStack_330._4_4_,0xd0);
                          uStack_320 = 0;
                          uVar5 = NtCreateDirectoryObject(&SmpSessionsObjectDirectory);
                          if ((int)uVar5 < 0) {
                            uVar12 = 0xa41;
                            _SmpInitProgressByLine = 0xa3f;
                            _SmpInitLastCall = NtCreateDirectoryObject_exref;
                            pwVar16 = local_2d8;
                            goto LAB_1400162fd;
                          }
                          uVar5 = SmpCreateProtectedPrefixes();
                          uVar14 = (ulonglong)uVar5;
                          if ((int)uVar5 < 0) {
                            _SmpInitProgressByLine = 0xa4e;
                            _SmpInitLastCall = SmpCreateProtectedPrefixes;
                            uVar12 = 0xa50;
                            goto LAB_140016076;
                          }
                          uVar8 = 0;
                          local_308 = 0;
                          if (SmpHostSmss == '\0') {
                            iVar6 = -0x3fffffff;
                          }
                          else if (((SmpMiniNTBoot == '\0') && (SmpSafeBootOption == -1)) &&
                                  (SmpDisableWpbtExecution == '\0')) {
                            iVar6 = SmpGetPlatformBinary(&local_318,&local_308);
                            uVar8 = local_308;
                          }
                          else {
                            iVar6 = -0x3fffffff;
                            bVar3 = SmpPlatformBinaryTableExists();
                            if (bVar3) {
                              puVar17 = (undefined8 *)0x0;
                              SmpSendPlatformBinaryStatus(2,0,0,(int **)0x0);
                            }
                          }
                          plVar15 = SmpSetupExecuteList;
                          if ((longlong **)SmpBootExecuteList == &SmpBootExecuteList) {
LAB_140016628:
                            if ((((longlong **)SmpSetupExecuteList != &SmpSetupExecuteList) &&
                                ((((longlong **)*plVar15 != &SmpSetupExecuteList ||
                                  (SmpSoftBoot == '\0')) ||
                                 (uVar14 = SmpSuffixUnicodeString
                                                     (&SmpSetupExecuteList,(ushort *)(plVar15 + 2)),
                                 (char)uVar14 == '\0')))) || (-1 < iVar6)) goto LAB_140016653;
                          }
                          else {
                            if ((longlong **)*SmpBootExecuteList == &SmpBootExecuteList) {
                              puVar17 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar17 >> 8),1);
                              cVar4 = RtlEqualUnicodeString(&SmpAutoChkDefaultCommand);
                              if (cVar4 != '\0') goto LAB_140016628;
                              if (SmpSoftBoot != '\0') {
                                puVar17 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar17 >> 8),1);
                                cVar4 = RtlPrefixUnicodeString(&SmpAutoChkKeyword);
                                if (cVar4 != '\0') goto LAB_140016628;
                              }
                            }
LAB_140016653:
                            uVar5 = SmpNtSerializeBoot();
                            puVar17 = (undefined8 *)(ulonglong)uVar5;
                            if ((int)uVar5 < 0) {
                              _SmpInitProgressByLine = 0xaac;
                              _SmpInitLastCall = NtSerializeBoot_exref;
                              _SmpInitReturnStatus = uVar5;
                              SmpLogFailure(0x140029c30,0xaae,uVar5);
                            }
                          }
                          SmpEventWrite(&SmssEvt_RunSecureKernelTrustlets_Start);
                          if (SmpHostSmss == '\0') {
LAB_1400166ed:
                            cVar4 = local_378[0];
                          }
                          else {
                            uVar14 = SmpRunSecureKernelTrustlets(local_378);
                            cVar4 = local_378[0];
                            uVar5 = (uint)uVar14;
                            if (-1 < (int)uVar5) goto LAB_1400166ed;
                            if (local_378[0] != '\0') {
                              _SmpInitProgressByLine = 0xabd;
                              puVar17 = (undefined8 *)(uVar14 & 0xffffffff);
                              _SmpInitLastCall = SmpRunSecureKernelTrustlets;
                              _SmpInitReturnStatus = uVar5;
                              SmpLogFailure(0x140029c30,0xabf,uVar5);
                            }
                          }
                          SmpEventWrite(&SmssEvt_RunSecureKernelTrustlets_Stop);
                          if ((cVar4 == '\0') &&
                             ((longlong **)SmpPlatformExecuteList != &SmpPlatformExecuteList)) {
                            SmpEventWrite(&SmssEvt_PlatformExecuteList_Start);
                            plVar15 = SmpPlatformExecuteList;
                            do {
                              if (SmpHostSmss != '\0') {
                                SmpExecuteCommand(plVar15 + 2,0,puVar17,0,(undefined8 *)0x0);
                              }
                              plVar2 = (longlong *)*plVar15;
                              SmpFreeSavedRegistryEntry(plVar15);
                              plVar15 = plVar2;
                            } while ((longlong **)plVar2 != &SmpPlatformExecuteList);
                            SmpEventWrite(&SmssEvt_PlatformExecuteList_Stop);
                          }
                          lVar10 = 0;
                          if ((longlong **)SmpBootExecuteList != &SmpBootExecuteList) {
                            SmpEventWrite(&SmssEvt_BootExecuteList_Start);
                            plVar15 = SmpBootExecuteList;
                            do {
                              SmpExecuteCommand(plVar15 + 2,0,puVar17,0,(undefined8 *)0x0);
                              plVar2 = (longlong *)*plVar15;
                              SmpFreeSavedRegistryEntry(plVar15);
                              plVar15 = plVar2;
                            } while ((longlong **)plVar2 != &SmpBootExecuteList);
                            SmpEventWrite(&SmssEvt_BootExecuteList_Stop);
                            lVar10 = local_360;
                          }
                          if ((longlong **)SmpBootExecuteNoPnpSyncList !=
                              &SmpBootExecuteNoPnpSyncList) {
                            SmpEventWrite(&SmssEvt_BootExecuteNoPnpSyncList_Start);
                            plVar15 = SmpBootExecuteNoPnpSyncList;
                            do {
                              SmpExecuteCommand(plVar15 + 2,0,puVar17,0,(undefined8 *)0x0);
                              plVar2 = (longlong *)*plVar15;
                              SmpFreeSavedRegistryEntry(plVar15);
                              plVar15 = plVar2;
                            } while ((longlong **)plVar2 != &SmpBootExecuteNoPnpSyncList);
                            SmpEventWrite(&SmssEvt_BootExecuteNoPnpSyncList_Stop);
                            lVar10 = local_360;
                          }
                          if (param_1 != 0) {
                            NtSetEvent(param_1);
                          }
                          SmpEventWrite(&SmssEvt_InitializeRegistry_Start);
                          if (SmpSoftBootSystemHiveReady != '\0') {
                            SmpReplaceSystemHiveOnSoftReboot();
                          }
                          NtInitializeRegistry(0);
                          SmpEventWrite(&SmssEvt_InitializeRegistry_Stop);
                          if (-1 < iVar6) {
                            iVar6 = RtlQueryPerformanceFrequency(&local_358);
                            if (iVar6 == 0) {
                              local_358 = 0;
                            }
                            iVar6 = RtlQueryPerformanceCounter(local_2f8);
                            if (iVar6 == 0) {
                              local_358 = 0;
                            }
                            iVar6 = SmpExecuteCommand(&local_318,0,puVar17,0x20,&local_2a8);
                            if (iVar6 < 0) {
                              iVar6 = 1;
                            }
                            else {
                              if ((local_252 & 0x80) == 0) {
                                iVar6 = 3;
                                NtTerminateProcess(local_2a0,0xc0000428);
                              }
                              else {
                                iVar6 = 0;
                                NtResumeThread(local_298,0);
                                NtWaitForSingleObject(local_2a0,0,0);
                              }
                              NtClose(local_2a0);
                              NtClose(local_298);
                            }
                            iVar7 = RtlQueryPerformanceCounter(&local_300);
                            if (iVar7 == 0) {
                              local_358 = 0;
                            }
                            if (0 < local_358) {
                              lVar10 = ((local_300 - local_2f8[0]) * 1000) / local_358;
                            }
                            SmpSendPlatformBinaryStatus(iVar6,uVar8,lVar10,&local_318);
                          }
                          iVar6 = 0;
                          cVar4 = RtlIsStateSeparationEnabled();
                          if (cVar4 != '\0') {
                            iVar7 = RtlQueryRegistryValuesEx
                                              (0,L"\\REGISTRY\\MACHINE\\OSDATA\\Session Manager",
                                               &SmpRegistryConfigurationTable2,0);
                            if (iVar7 < 0) {
                              SmpLogFailure(0x140029c30,0xb87,iVar7);
                            }
                            else {
                              iVar6 = 1;
                            }
                          }
                          if (SmpMiniNTBoot == '\0') {
                            SmpProcessFileRenames(iVar6);
                          }
                          local_360 = 0;
                          uVar8 = 0;
                          uVar5 = TpAllocWork(&local_360);
                          uVar14 = (ulonglong)uVar5;
                          if ((int)uVar5 < 0) {
                            uVar12 = 0xbac;
                            _SmpInitProgressByLine = 0xbaa;
                            _SmpInitLastCall = TpAllocWork_exref;
                          }
                          else {
                            TpPostWork(local_360);
                            if (SmpWaitForPagingFiles != 0) {
                              TpWaitForWork(local_360);
                            }
                            TpReleaseWork(local_360);
                            uVar13 = SmpCreateDynamicEnvironmentVariables(local_370);
                            uVar14 = uVar13 & 0xffffffff;
                            if ((int)(uint)uVar13 < 0) {
                              _SmpInitProgressByLine = 0xbc1;
                              _SmpInitLastCall = SmpCreateDynamicEnvironmentVariables;
                              _SmpInitReturnStatus = (uint)uVar13;
                              goto LAB_140016b89;
                            }
                            if ((longlong **)SmpSetupExecuteList != &SmpSetupExecuteList) {
                              SmpEventWrite(&SmssEvt_SetupExecuteList_Start);
                              plVar15 = SmpSetupExecuteList;
                              do {
                                SmpExecuteCommand(plVar15 + 2,0,uVar8,0,(undefined8 *)0x0);
                                plVar2 = (longlong *)*plVar15;
                                SmpFreeSavedRegistryEntry(plVar15);
                                plVar15 = plVar2;
                              } while ((longlong **)plVar2 != &SmpSetupExecuteList);
                              SmpEventWrite(&SmssEvt_SetupExecuteList_Stop);
                            }
                            if ((longlong **)SmpSetupExecuteNoPnpSyncList !=
                                &SmpSetupExecuteNoPnpSyncList) {
                              SmpEventWrite(&SmssEvt_SetupExecuteNoPnpSyncList_Start);
                              plVar15 = SmpSetupExecuteNoPnpSyncList;
                              do {
                                SmpExecuteCommand(plVar15 + 2,0,uVar8,0,(undefined8 *)0x0);
                                plVar2 = (longlong *)*plVar15;
                                SmpFreeSavedRegistryEntry(plVar15);
                                plVar15 = plVar2;
                              } while ((longlong **)plVar2 != &SmpSetupExecuteNoPnpSyncList);
                              SmpEventWrite(&SmssEvt_SetupExecuteNoPnpSyncList_Stop);
                            }
                            uVar13 = SmpConfigureSharedSessionData();
                            uVar14 = uVar13 & 0xffffffff;
                            if (-1 < (int)uVar13) {
                              SmpTranslateSystemPartitionInformation();
                              uVar14 = 0;
                              goto LAB_140016b89;
                            }
                            _SmpInitProgressByLine = 0xbf9;
                            _SmpInitLastCall = SmpConfigureSharedSessionData;
                            uVar12 = 0xbfb;
                          }
                        }
                      }
                      goto LAB_140016076;
                    }
                  }
                  else {
                    uVar13 = SmpInitializeKnownDlls(1);
                    uVar14 = uVar13 & 0xffffffff;
                    if (-1 < (int)uVar13) {
                      uVar5 = SmpInitializeKnownDllsAsync();
                      goto LAB_140016434;
                    }
                  }
                  _SmpInitProgressByLine = 0xa06;
                  _SmpInitLastCall = SmpInitializeKnownDlls;
                  uVar12 = 0xa08;
                }
              }
            }
          }
        }
      }
      else {
        uVar12 = 0x977;
        _SmpInitProgressByLine = 0x975;
        _SmpInitLastCall = NtQuerySystemInformationEx_exref;
      }
    }
  }
LAB_140016076:
  _SmpInitReturnStatus = (uint)uVar14;
  SmpLogFailure(0x140029c30,uVar12,_SmpInitReturnStatus);
LAB_140016b89:
  if (lStack_310 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lStack_310);
  }
  if (local_370 != 0) {
    NtClose();
  }
  if (lVar9 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar9);
  }
  if (local_350 != 0) {
    RtlSetCurrentEnvironment(local_350,&SmpDefaultEnvironment);
  }
  return uVar14;
}



===== SmpLoadDeferredSubsystem @ 140016c40 =====

int SmpLoadDeferredSubsystem(longlong param_1,uint *param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong local_res8;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  longlong local_10;
  
  local_18 = *(undefined2 *)(param_1 + 0x30);
  local_14 = 0;
  local_res8 = 0;
  local_10 = param_1 + 0x34;
  local_16 = local_18;
  uVar2 = SmpGetMuSessionIdFromClientContext(param_2,&local_res8);
  if (local_res8 == 0) {
    SmpLogFailureString(0x14002a328,0x286b,local_10,0xc0000001);
    iVar3 = -0x3fffffff;
  }
  else {
    puVar5 = &SmpSubSystemsRequired;
    if ((*param_2 >> 3 & 1) == 0) {
      puVar5 = &SmpSubSystemsToDefer;
      puVar4 = SmpSubSystemsToDefer;
    }
    else {
      puVar4 = SmpSubSystemsRequired;
    }
    for (; puVar4 != puVar5; puVar4 = (undefined8 *)*puVar4) {
      param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
      cVar1 = RtlEqualUnicodeString(&local_18,puVar4 + 2);
      if (cVar1 != '\0') {
        iVar3 = SmpExecuteCommand(puVar4 + 4,uVar2,param_3,0x48,(undefined8 *)0x0);
        return iVar3;
      }
    }
    iVar3 = -0x3fffffcc;
  }
  return iVar3;
}



===== SmpLoadSubSystem @ 140016d30 =====

int SmpLoadSubSystem(ushort *param_1,undefined8 param_2,undefined8 param_3,uint param_4,
                    undefined8 param_5,uint param_6)

{
  int iVar1;
  int *piVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  longlong lVar5;
  uint *puVar6;
  uint local_a8 [4];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  int local_50;
  
  memset(&local_98,0,0x68);
  local_a8[2] = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  if ((param_6 & 0x10) != 0) {
    lVar5 = 0;
    if (param_1 != (ushort *)0x0) {
      lVar5 = *(longlong *)(param_1 + 4);
    }
    iVar1 = -0x3fffffcc;
    uVar4 = 0x28d3;
LAB_140016d97:
    SmpLogFailureString(0x14002a348,uVar4,lVar5,iVar1);
    return iVar1;
  }
  piVar2 = (int *)SmpCreateKnownSubSys(0);
  lVar5 = 0;
  if (piVar2 == (int *)0x0) {
    if (param_1 != (ushort *)0x0) {
      lVar5 = *(longlong *)(param_1 + 4);
    }
    iVar1 = -0x3fffffe9;
    uVar4 = 0x28e3;
    goto LAB_140016d97;
  }
  puVar6 = local_a8;
  piVar2[0x10] = param_4;
  SmpWaitForSubSysStartup(param_4,0,0,puVar6);
  SmpAddKnownSubSys((longlong)local_a8,piVar2);
  SmpUnlockKnownSubSysList((int *)local_a8);
  iVar1 = SmpExecuteImage(param_1,param_2,param_3,puVar6,(uint *)0x0,param_6 | 0x20,&local_98);
  if (iVar1 < 0) {
    SmpLogFailure(0x14002a348,0x290b,iVar1);
    goto LAB_140016ec2;
  }
  *(undefined8 *)(piVar2 + 8) = local_90;
  *(undefined8 *)(piVar2 + 0xc) = local_80;
  *(undefined8 *)(piVar2 + 0xe) = uStack_78;
  if (local_50 == 1) {
LAB_140016e74:
    iVar1 = NtResumeThread(local_88,0);
    if (iVar1 < 0) {
      SmpLogFailure(0x14002a348,0x292a,iVar1);
    }
    else {
      NtClose(local_88);
      iVar1 = SmpWaitForSingleSubSys((longlong)piVar2);
      if (iVar1 < 0) {
        SmLogFailureInt(0x14002a348,0x293f,(ulonglong)param_4,0,iVar1);
        goto LAB_140016ec2;
      }
    }
  }
  else {
    uVar3 = SmpSbCreateSession(param_4,0xffffffffffffffff,&local_98,puVar6,(undefined8 *)0x0);
    iVar1 = (int)uVar3;
    if (-1 < iVar1) goto LAB_140016e74;
  }
  NtTerminateProcess(local_90,iVar1);
  NtClose(local_88);
LAB_140016ec2:
  SmpDeleteSubSys(piVar2);
  SmpDereferenceKnownSubSys(piVar2);
  return iVar1;
}



===== SmpLogPFROError @ 140016f38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpLogPFROError(void)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined1 auStackY_348 [32];
  longlong local_2c8 [4];
  undefined8 local_2a8;
  undefined8 local_2a0;
  undefined *local_298;
  undefined8 local_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  wchar_t local_248 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_348;
  local_2c8[0] = 0;
  local_2c8[1] = 0;
  local_2c8[2] = 0;
  local_278 = 0;
  uStack_270 = 0;
  if (SmpLogFileHandle == 0) {
    local_258 = 0;
    local_2a8 = 0x30;
    local_290 = 0x40;
    local_268 = 0;
    uStack_260 = 0;
    local_2a0 = 0;
    local_298 = &SmpLogfileName;
    local_288 = 0;
    uStack_280 = 0;
    iVar1 = NtCreateFile(&SmpLogFileHandle,0x120002,&local_2a8,local_2c8 + 1);
    if (iVar1 < 0) {
      uVar4 = 0x2ff2;
    }
    else {
      iVar1 = NtQueryInformationFile(SmpLogFileHandle,local_2c8 + 1,&local_268,0x18);
      if (iVar1 < 0) {
        NtClose();
        uVar4 = 0x3003;
      }
      else {
        local_2c8[3] = uStack_260;
        iVar1 = NtSetInformationFile(SmpLogFileHandle,local_2c8 + 1,local_2c8 + 3,8);
        if (-1 < iVar1) goto LAB_1400170c8;
        NtClose(SmpLogFileHandle);
        uVar4 = 0x3015;
      }
    }
    SmpLogFileHandle = 0;
    uVar2 = SmpLogFailure(0x14002a370,uVar4,iVar1);
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
LAB_1400170c8:
    SmpGetTime(&local_278);
    iVar1 = RtlStringCbPrintfExW
                      (local_248,0x200,(size_t *)0x0,local_2c8,0,
                       L"%d/%d/%d %d:%d:%d - PFRO Error: %wZ, %wZ, 0x%x\r\n",
                       (char)((ulonglong)local_278 >> 0x10));
    if (iVar1 < 0) {
      SmpLogFailure(0x14002a370,0x3035,iVar1);
    }
    uVar3 = NtWriteFile(SmpLogFileHandle,0,0,0);
    uVar2 = uVar3;
    if ((int)uVar3 < 0) {
      uVar2 = SmpLogFailure(0x14002a370,0x304c,(int)uVar3);
    }
    uVar2 = CONCAT71((int7)(uVar2 >> 8),(char)(uVar3 >> 0x1f)) & 0xffffffffffffff01 ^ 1;
  }
  return uVar2;
}



===== SmpOpenKnownDllsHandles @ 140017200 =====

ulonglong SmpOpenKnownDllsHandles
                    (undefined8 *param_1,short *param_2,int param_3,longlong *param_4,
                    undefined8 *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong local_res20;
  undefined4 local_a8;
  undefined4 uStack_a4;
  longlong lStack_a0;
  undefined8 *local_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined8 local_88;
  ulonglong uStack_80;
  undefined8 local_78;
  longlong local_70;
  ushort local_68 [4];
  longlong lStack_60;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  *param_4 = 0;
  local_78 = 0;
  local_88 = 0;
  uStack_80 = uStack_80 & 0xffffffff00000000;
  *param_5 = 0;
  local_40 = L"KnownDllPath";
  local_res20 = 0;
  local_70 = 0;
  local_48 = 0x1a0018;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  lStack_60 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_58 = 0;
  lStack_50 = 0;
  local_a8 = 0;
  uStack_a4 = 0;
  lStack_a0 = 0;
  local_98 = (undefined8 *)0x0;
  uStack_90 = 0;
  uStack_8c = 0;
  uVar2 = SmpExpandKnownDllsPath(param_2,local_68);
  uVar1 = (uint)uVar2;
  uVar2 = uVar2 & 0xffffffff;
  if ((int)uVar1 < 0) {
    lStack_60 = 0;
    if (param_2 == (short *)0x0) {
      lVar4 = 0;
    }
    else {
      lVar4 = *(longlong *)(param_2 + 4);
    }
    uVar3 = 0xf07;
  }
  else {
    uVar1 = RtlDosPathNameToNtPathName_U_WithStatus(lStack_60,&local_58,0,0);
    uVar2 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      local_98 = &local_58;
      lStack_a0 = 0;
      local_a8 = 0x30;
      uStack_90 = 0x40;
      local_88 = 0;
      uStack_80 = 0;
      uVar1 = NtOpenFile(&local_78,0x100001,&local_a8,&local_38,3,0x21);
      uVar2 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        local_78 = 0;
        if ((uVar1 != 0xc0000034) || (param_3 != 0)) {
          uVar3 = 0xf37;
          lVar4 = lStack_50;
          goto LAB_1400172a7;
        }
      }
      else {
        local_88 = SmpKnownDllsDirSecurityDescriptor;
        local_a8 = 0x30;
        lStack_a0 = 0;
        uStack_90 = 0xd0;
        uStack_80 = 0;
        local_98 = param_1;
        uVar1 = NtCreateDirectoryObject(&local_res20,0xf000f,&local_a8);
        if (uVar1 != 0x40000000) {
          if ((int)uVar1 < 0) {
            local_res20 = 0;
            uVar3 = 0xf5a;
          }
          else {
            lStack_a0 = local_res20;
            local_98 = &local_48;
            local_a8 = 0x30;
            local_88 = SmpKnownDllsSymLinkSecurityDescriptor;
            uStack_90 = 0x50;
            uStack_80 = 0;
            uVar1 = NtCreateSymbolicLinkObject(&local_70,0xf0001,&local_a8,local_68);
            if (-1 < (int)uVar1) goto LAB_140017419;
            local_70 = 0;
            uVar3 = 0xf71;
          }
          uVar2 = (ulonglong)uVar1;
          SmpLogFailure(0x140029f40,uVar3,uVar1);
          goto LAB_14001742e;
        }
LAB_140017419:
        *param_4 = local_res20;
        *param_5 = local_78;
        local_res20 = 0;
      }
      uVar2 = 0;
      goto LAB_14001742e;
    }
    uVar3 = 0xf18;
    lStack_50 = 0;
    lVar4 = lStack_60;
  }
LAB_1400172a7:
  SmpLogFailureString(0x140029f40,uVar3,lVar4,uVar1);
LAB_14001742e:
  if (lStack_50 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lStack_50);
  }
  if (lStack_60 != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lStack_60);
  }
  if (local_70 != 0) {
    NtClose();
  }
  if (local_res20 != 0) {
    NtClose();
  }
  return uVar2;
}



===== SmpOpenTargetFile @ 1400174cc =====

undefined8 SmpOpenTargetFile(undefined8 *param_1,undefined8 param_2,undefined8 param_3,char param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong local_28 [4];
  
  local_28[0] = 0;
  iVar1 = (-(uint)(param_4 != '\0') & 0x200000) + 0x4020;
  local_28[1] = 0;
  local_28[2] = 0;
  uVar2 = NtOpenFile();
  if (-1 < (int)uVar2) {
    iVar1 = NtQueryInformationFile(*param_1,local_28 + 1,local_28,8,0x23,iVar1);
    if (((iVar1 < 0) || ((local_28[0] & 0x400) == 0)) || ((local_28[0] & 0x2000000000000000) != 0))
    {
      uVar2 = 0;
    }
    else {
      NtClose(*param_1);
      *param_1 = 0;
      uVar2 = 0xc00000d8;
    }
  }
  return uVar2;
}



===== SmpPathCanBeTrustedIsNotARedirection @ 140017580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool SmpPathCanBeTrustedIsNotARedirection(HANDLE param_1,ushort *param_2,int param_3)

{
  DWORD cchFilePath;
  int iVar1;
  LPWSTR lpszFilePath;
  WCHAR WVar2;
  uint uVar3;
  LPWSTR pWVar4;
  bool bVar5;
  undefined1 auStack_278 [32];
  undefined1 local_258;
  WCHAR local_248 [4];
  WCHAR local_240 [260];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_278;
  lpszFilePath = (LPWSTR)0x0;
  bVar5 = false;
  if (*param_2 < 0xc) {
    return false;
  }
  cchFilePath = GetFinalPathNameByHandleW(param_1,local_248,0x104,0);
  if (cchFilePath == 0) {
    return false;
  }
  if (cchFilePath + 2 < 0x107) {
    pWVar4 = local_240;
  }
  else {
    lpszFilePath = (LPWSTR)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30)
                                           ,SmBaseTag,(ulonglong)(cchFilePath + 2) * 2);
    if (lpszFilePath == (LPWSTR)0x0) {
      return false;
    }
    cchFilePath = GetFinalPathNameByHandleW(param_1,lpszFilePath,cchFilePath,0);
    if (cchFilePath == 0) goto LAB_1400176a6;
    pWVar4 = lpszFilePath + 4;
  }
  if ((ulonglong)((longlong)(int)cchFilePath * 2) <= (ulonglong)*param_2) {
    if ((param_3 == 0) || (cchFilePath < 8)) {
      WVar2 = L'\0';
      uVar3 = cchFilePath;
    }
    else {
      WVar2 = L'\\';
      pWVar4[cchFilePath - 3] = L'\0';
      uVar3 = cchFilePath + 1;
    }
    pWVar4[cchFilePath - 4] = WVar2;
    local_258 = 1;
    iVar1 = RtlCompareUnicodeStrings(*(longlong *)(param_2 + 4) + 8,uVar3 - 3,pWVar4,uVar3 - 3);
    bVar5 = iVar1 == 0;
  }
  if (lpszFilePath == (LPWSTR)0x0) {
    return bVar5;
  }
LAB_1400176a6:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lpszFilePath);
  return bVar5;
}



===== SmpProcessFileRenames @ 1400176fc =====

void SmpProcessFileRenames(int param_1)

{
  ushort *puVar1;
  short sVar2;
  short *psVar3;
  longlong *plVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ushort uVar10;
  longlong *plVar11;
  int iVar12;
  byte bVar13;
  uint uVar14;
  bool bVar15;
  char local_res10 [8];
  int local_res18 [2];
  HANDLE local_res20;
  ushort local_90;
  undefined1 auStack_8e [6];
  short *psStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  longlong *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  
  local_res10[0] = '\x01';
  local_res20 = (HANDLE)0x0;
  _local_90 = 0;
  psStack_88 = (short *)0x0;
  local_60 = 0;
  bVar13 = 0;
  local_80 = 0;
  uStack_78 = 0;
  uStack_58 = uStack_58 & 0xffffffff00000000;
  local_70 = (longlong *)0x0;
  uStack_68 = 0;
  if ((SmpAllowProtectedRenames != '\0') && (iVar7 = RtlAdjustPrivilege(0x12,1,0), iVar7 < 0)) {
    local_res10[0] = '\x01';
  }
  if (SmpClearTempFiles != 0) {
    SmpClearTemporaryFiles();
  }
  SmpEventWrite(&SmssEvt_ProcessFileRenames_Start);
  uVar14 = 0;
  local_res18[0] = 0;
  plVar11 = SmpFileRenameList;
  while ((longlong **)SmpFileRenameList != &SmpFileRenameList) {
    local_res20 = (HANDLE)0x0;
    bVar5 = false;
    puVar1 = (ushort *)(plVar11 + 2);
    bVar15 = true;
    SmpEventWriteString2(&SmpFileRenameList,puVar1,(ushort *)(plVar11 + 4));
    uVar10 = *puVar1;
    if ((3 < uVar10) && (psVar3 = (short *)plVar11[3], *psVar3 == 0x2a)) {
      sVar2 = psVar3[1];
      uVar10 = uVar10 - 4;
      *puVar1 = uVar10;
      *(short *)((longlong)plVar11 + 0x12) = *(short *)((longlong)plVar11 + 0x12) + -4;
      plVar11[3] = (longlong)(psVar3 + 2);
      bVar15 = sVar2 != 0x30;
      bVar5 = true;
    }
    if ((short)plVar11[4] == 0) {
      if (*(short *)plVar11[3] == 0x40) {
        plVar11[3] = (longlong)((short *)plVar11[3] + 1);
        *puVar1 = uVar10 - 2;
      }
      uVar8 = SmpForceDeleteTargetFile((ushort *)(plVar11 + 2),bVar15);
      iVar7 = (int)uVar8;
    }
    else {
      uStack_78 = 0;
      local_70 = plVar11 + 2;
      local_80 = CONCAT44(local_80._4_4_,0x30);
      uStack_68 = CONCAT44(uStack_68._4_4_,0x40);
      local_60 = 0;
      uStack_58 = 0;
      uVar9 = SmpOpenTargetFile(&local_res20,0x110000,&local_80,'\0');
      iVar7 = (int)uVar9;
      if (-1 < iVar7) {
        if ((bVar15 != true) ||
           (bVar6 = SmpPathCanBeTrustedIsNotARedirection(local_res20,(ushort *)(plVar11 + 2),0),
           bVar6)) {
          RtlInitUnicodeString(&local_90,plVar11[5]);
          uVar10 = local_90;
          if ((3 < local_90) && (*psStack_88 == 0x2a)) {
            uVar10 = local_90 - 4;
            psStack_88 = psStack_88 + 2;
            _local_90 = CONCAT62(CONCAT42(auStack_8e._2_4_,auStack_8e._0_2_ + -4),uVar10);
          }
          if ((*psStack_88 == 0x21) || (*psStack_88 == 0x40)) {
            psStack_88 = psStack_88 + 1;
            iVar12 = 1;
            _local_90 = CONCAT62(CONCAT42(auStack_8e._2_4_,auStack_8e._0_2_ + -2),uVar10 - 2);
          }
          else {
            iVar12 = 0;
          }
          iVar7 = SmpRenameTargetFile(&local_90,local_res20,iVar12,bVar15);
          if (((iVar7 < 0) && (iVar12 != 0)) && (iVar7 == -0x3fffffde)) {
            uVar8 = SmpTryOverwriteReadonlyFile(&local_90,local_res20,bVar15);
            iVar7 = (int)uVar8;
            if (((iVar7 + 0x80000000U & 0x80000000) == 0) && (iVar7 != -0x3fffff46)) {
              uVar8 = SmpShuffleMove(&local_90,local_res20,bVar15);
              iVar7 = (int)uVar8;
              if (-1 < iVar7) {
                local_res18[0] = 1;
              }
            }
          }
        }
        else {
          iVar7 = -0x3ffffaf5;
        }
      }
    }
    if (local_res20 != (HANDLE)0x0) {
      NtClose();
    }
    if (iVar7 < 0) {
      SmpLogFailureString(0x14002a1a0,0x1c3b,plVar11[3],iVar7);
      uVar8 = SmpLogPFROError();
      bVar13 = bVar13 | (byte)uVar8;
    }
    else {
      uVar14 = uVar14 + 1;
    }
    if (bVar5) {
      *(short *)(plVar11 + 2) = (short)plVar11[2] + 4;
      *(short *)((longlong)plVar11 + 0x12) = *(short *)((longlong)plVar11 + 0x12) + 4;
      plVar11[3] = plVar11[3] + -4;
    }
    plVar4 = (longlong *)*plVar11;
    SmpFreeSavedRegistryEntry(plVar11);
    plVar11 = plVar4;
  }
  if (local_res10[0] == '\0') {
    RtlAdjustPrivilege(0x12,0,0,local_res10);
  }
  RtlDeleteRegistryValue(2,L"Session Manager",L"PendingFileRenameOperations");
  RtlDeleteRegistryValue(2,L"Session Manager",L"PendingFileRenameOperations2");
  if (param_1 != 0) {
    RtlDeleteRegistryValue
              (0,L"\\REGISTRY\\MACHINE\\OSDATA\\Session Manager",L"PendingFileRenameOperations");
    RtlDeleteRegistryValue
              (0,L"\\REGISTRY\\MACHINE\\OSDATA\\Session Manager",L"PendingFileRenameOperations2");
  }
  if (local_res18[0] != 0) {
    RtlWriteRegistryValue(2,L"Session Manager",L"ClearTempFiles",4,local_res18,4);
  }
  SmpFinishPFROLogging((ulonglong)uVar14,bVar13);
  SmpEventWrite(&SmssEvt_ProcessFileRenames_Stop);
  return;
}



===== SmpQueryWpbtExecutionPolicy @ 140017b00 =====

undefined8 SmpQueryWpbtExecutionPolicy(undefined8 param_1,int param_2,int *param_3,int param_4)

{
  if ((param_4 == 4) && (param_2 == 4)) {
    SmpDisableWpbtExecution = *param_3 != 0;
  }
  else {
    SmpDisableWpbtExecution = false;
  }
  return 0;
}



===== SmpRenameTargetFile @ 140017b28 =====

undefined4 SmpRenameTargetFile(ushort *param_1,undefined8 param_2,int param_3,char param_4)

{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  void *_Dst;
  uint uVar4;
  longlong local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res8 = -1;
  local_38 = 0;
  uStack_30 = 0;
  uVar4 = *param_1 + 0x1a;
  _Dst = (void *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag
                                 ,uVar4);
  if (_Dst == (void *)0x0) {
    return 0xc0000017;
  }
  if ((param_4 == '\0') || (bVar2 = SmpCheckFolderForRedirections(param_1,&local_res8), bVar2)) {
    memset(_Dst,0,(ulonglong)uVar4);
    *(undefined8 *)((longlong)_Dst + 8) = 0;
    *(bool *)_Dst = param_3 != 0;
    uVar1 = *param_1;
    *(uint *)((longlong)_Dst + 0x10) = (uint)uVar1;
    memcpy((void *)((longlong)_Dst + 0x14),*(void **)(param_1 + 4),(ulonglong)(uint)uVar1);
    uVar3 = NtSetInformationFile(param_2,&local_38,_Dst,uVar4,10);
  }
  else {
    uVar3 = 0xc000050b;
  }
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,_Dst);
  if (local_res8 != -1) {
    NtClose();
  }
  return uVar3;
}



===== SmpReplaceSystemHiveOnSoftReboot @ 140017c5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpReplaceSystemHiveOnSoftReboot(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  ushort local_a0 [8];
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 *local_30;
  longlong local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_e8;
  local_44 = 0;
  local_b8 = 0;
  local_5c = 0;
  local_a0[0] = 0;
  local_a0[1] = 0;
  local_a0[2] = 0;
  local_a0[3] = 0;
  local_a0[4] = 0;
  local_a0[5] = 0;
  local_a0[6] = 0;
  local_a0[7] = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  RtlInitUnicodeString(&local_b0,L"\\SystemRoot\\System32\\config\\SYSTEM.ksr.tmp");
  local_58 = 0;
  local_50 = &local_b0;
  local_60 = 0x30;
  local_48 = 0x40;
  local_c8 = 3;
  local_40 = 0;
  uStack_38 = 0;
  uVar2 = SmpOpenTargetFile(&local_b8,0x110000,&local_60,'\x01');
  if (-1 < (int)uVar2) {
    RtlInitUnicodeString(local_a0,L"\\SystemRoot\\System32\\config\\SYSTEM");
    iVar1 = SmpRenameTargetFile(local_a0,local_b8,1,'\0');
    if (iVar1 < 0) {
      local_90 = 0;
      uStack_88 = 0;
      RtlInitUnicodeString(&local_90,L"Failed to replace system hive on soft reboot");
      local_30 = &local_90;
      local_20 = 0;
      uStack_18 = 0;
      local_28 = (longlong)iVar1;
      SmpLogFailure(0x14002a5a0,0x33ae,iVar1);
                    /* WARNING: Subroutine does not return */
      SmpTerminate(&local_30,1,4);
    }
    NtClose(local_b8);
    RtlInitUnicodeString(&local_80,L"\\SystemRoot\\System32\\config\\SYSTEM.LOG1");
    RtlInitUnicodeString(&local_70,L"\\SystemRoot\\System32\\config\\SYSTEM.LOG2");
    SmpDeleteFile((longlong)&local_80);
    SmpDeleteFile((longlong)&local_70);
  }
  return;
}



===== SmpRunSecureKernelTrustlets @ 140017e00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140017f18) */
/* WARNING: Removing unreachable block (ram,0x000140017f1d) */
/* WARNING: Removing unreachable block (ram,0x000140017f29) */
/* WARNING: Removing unreachable block (ram,0x000140017f4b) */
/* WARNING: Removing unreachable block (ram,0x000140017f7b) */
/* WARNING: Removing unreachable block (ram,0x00014001823a) */

ulonglong SmpRunSecureKernelTrustlets(undefined1 *param_1)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar5;
  longlong lVar4;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  ushort uVar8;
  short *psVar9;
  undefined1 auStackY_8b8 [32];
  longlong local_880;
  longlong local_878;
  wchar_t *pwStack_870;
  ushort local_868 [8];
  undefined8 local_858;
  undefined8 uStack_850;
  int local_844;
  uint local_840;
  short local_83c [514];
  short local_438 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_8b8;
  pwVar7 = (wchar_t *)0x400;
  local_858 = 0;
  uStack_850 = 0;
  local_878 = 0;
  pwStack_870 = (wchar_t *)0x0;
  local_868[0] = 0;
  local_868[1] = 0;
  local_868[2] = 0;
  local_868[3] = 0;
  local_868[4] = 0;
  local_868[5] = 0;
  local_868[6] = 0;
  local_868[7] = 0;
  memset(local_438,0,0x400);
  local_880 = 0;
  *param_1 = 0;
  RtlInitUnicodeString(&local_858,L"SecureKernelTrustlet");
  pwVar6 = L"async secure ";
  RtlInitUnicodeString(local_868);
  uVar3 = NtPnpInitializeLibrary();
  if ((int)uVar3 < 0) {
    SmpLogFailureString(0x140029640,0x80c,0x140029600,(int)uVar3);
    return uVar3 & 0xffffffff;
  }
  psVar9 = local_438;
  uVar1 = NtPnpGetDeviceInterfaceList();
  uVar3 = (ulonglong)uVar1;
  if (uVar1 == 0xc0000023) {
    uVar3 = 0xc00000e5;
    SmpLogFailureString(0x140029640,0x82b,0x140029660,0xc00000e5);
  }
  else if (-1 < (int)uVar1) {
    if (local_438[0] != 0) {
      do {
        if (local_880 != 0) {
          NtClose();
          local_880 = 0;
        }
        uVar1 = NtPnpOpenDeviceInterfaceKey((longlong)psVar9,pwVar6,pwVar7,&local_880);
        uVar3 = (ulonglong)uVar1;
        if (uVar1 != 0xc0000034) {
          if ((int)uVar1 < 0) {
            pwVar7 = L"Failed to open interface key.";
            pwVar6 = (wchar_t *)0x85d;
          }
          else {
            uVar1 = NtQueryValueKey(local_880,&local_858,2);
            uVar3 = (ulonglong)uVar1;
            if (uVar1 == 0xc0000034) {
              uVar1 = 0xc0000034;
              pwVar7 = L"SecureKernelTrustlet registry key not found";
              pwVar6 = (wchar_t *)0x86c;
            }
            else if ((uVar1 == 0x80000005) || (uVar1 == 0xc0000023)) {
              pwVar7 = L"Registry Buffer too small";
              pwVar6 = (wchar_t *)0x873;
            }
            else if ((int)uVar1 < 0) {
              pwVar7 = L"Failed to query SecureKernelTrustlet registry value.";
              pwVar6 = (wchar_t *)0x879;
            }
            else if (local_844 == 1) {
              uVar8 = (short)local_840 + local_868[0];
              if ((uVar8 < local_868[0]) || (uVar8 < local_840)) {
                uVar1 = 0xc000000d;
                pwVar7 = L"Provided trustlet path is too long.";
                pwVar6 = (wchar_t *)0x889;
              }
              else {
                *param_1 = 1;
                pwVar7 = (wchar_t *)(ulonglong)uVar8;
                pwStack_870 = (wchar_t *)
                              RtlAllocateHeap(*(undefined8 *)
                                               ((longlong)ProcessEnvironmentBlock + 0x30),0);
                if (pwStack_870 != (wchar_t *)0x0) {
                  local_878 = (ulonglong)CONCAT42((int)((ulonglong)local_878 >> 0x20),uVar8) << 0x10
                  ;
                  uVar3 = RtlUnicodeStringCat((ushort *)&local_878,local_868);
                  iVar2 = (int)uVar3;
                  if (iVar2 < 0) {
                    pwVar7 = L"Failed to add prefix to trustlet path.";
                    pwVar6 = (wchar_t *)0x8a2;
LAB_140018153:
                    uVar3 = uVar3 & 0xffffffff;
                    SmpLogFailureString(0x140029640,(int)pwVar6,(longlong)pwVar7,iVar2);
                  }
                  else {
                    uVar3 = RtlUnicodeStringCatString((ushort *)&local_878,local_83c);
                    iVar2 = (int)uVar3;
                    if (iVar2 < 0) {
                      pwVar7 = L"Failed to append registry data to trustlet path.";
                      pwVar6 = (wchar_t *)0x8aa;
                      goto LAB_140018153;
                    }
                    pwVar6 = (wchar_t *)0x0;
                    uVar1 = SmpExecuteCommand(&local_878,0,pwVar7,0,(undefined8 *)0x0);
                    uVar3 = (ulonglong)uVar1;
                  }
                  if (pwStack_870 != (wchar_t *)0x0) {
                    pwVar6 = (wchar_t *)0x0;
                    pwVar7 = pwStack_870;
                    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30));
                  }
                  goto LAB_1400181ed;
                }
                uVar1 = 0xc000009a;
                pwVar7 = L"Failed to allocate memory for trustlet path buffer.";
                pwVar6 = (wchar_t *)0x897;
              }
            }
            else {
              uVar1 = 0xc0000024;
              pwVar7 = L"SecureKernelTrustlet registry value is the wrong type.";
              pwVar6 = (wchar_t *)0x881;
            }
          }
          SmpLogFailureString(0x140029640,(int)pwVar6,(longlong)pwVar7,uVar1);
        }
LAB_1400181ed:
        lVar4 = -1;
        do {
          lVar5 = lVar4;
          lVar4 = lVar5 + 1;
        } while (psVar9[lVar4] != 0);
        psVar9 = psVar9 + lVar5 + 2;
      } while (*psVar9 != 0);
      if (local_880 != 0) {
        NtClose();
      }
    }
    goto LAB_140018229;
  }
  SmpLogFailureString(0x140029640,0x843,0x140029740,(int)uVar3);
LAB_140018229:
  if (NtPnpDeviceApiDriverHandle != 0) {
    NtClose();
    NtPnpDeviceApiDriverHandle = 0;
  }
  return uVar3;
}



===== SmpSendPlatformBinaryStatus @ 1400182b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpSendPlatformBinaryStatus(int param_1,undefined8 param_2,undefined8 param_3,int **param_4)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined *puVar4;
  byte *pbVar5;
  undefined8 *puVar6;
  int **ppiVar7;
  int local_res8 [2];
  undefined1 auStackY_158 [32];
  undefined4 uVar8;
  int local_108 [2];
  longlong local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined *local_e0;
  ulonglong uStack_d8;
  undefined8 local_d0;
  ulonglong uStack_c8;
  int *local_c0;
  undefined8 uStack_b8;
  int *local_b0;
  undefined8 uStack_a8;
  undefined8 local_98 [4];
  int *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  int *local_48;
  uint local_40 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_158;
  local_d0 = 0;
  uStack_c8 = uStack_c8 & 0xffffffff00000000;
  local_b0 = (int *)0x0;
  uStack_a8 = 0;
  local_100 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_e0 = (undefined *)0x0;
  uStack_d8 = 0;
  puVar6 = (undefined8 *)0x34;
  local_c0 = (int *)0x0;
  uStack_b8 = 0;
  if (param_1 != 0) {
    param_2 = 0;
  }
  ppiVar7 = param_4;
  local_res8[0] = param_1;
  puVar2 = (undefined8 *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8);
  if (puVar2 != (undefined8 *)0x0) {
    local_e0 = &SmpPlatformBinarySymbolicLink;
    ppiVar7 = &local_c0;
    local_f0 = CONCAT44(local_f0._4_4_,0x30);
    puVar6 = &local_f0;
    uStack_e8 = 0;
    uStack_d8 = uStack_d8 & 0xffffffff00000000;
    local_d0 = 0;
    uStack_c8 = 0;
    iVar1 = NtOpenFile(&local_100,0x120003);
    if (-1 < iVar1) {
      *(undefined4 *)((longlong)puVar2 + 0x14) = 1;
      ppiVar7 = (int **)0x0;
      *(undefined4 *)((longlong)puVar2 + 0x1c) = 1;
      puVar6 = (undefined8 *)0x0;
      *(undefined4 *)puVar2 = 0x43696541;
      *(undefined4 *)((longlong)puVar2 + 4) = 0x5342505f;
      *(undefined4 *)(puVar2 + 1) = 0x34;
      *(undefined4 *)((longlong)puVar2 + 0xc) = 4;
      *(undefined4 *)(puVar2 + 2) = 0x40000;
      *(undefined4 *)(puVar2 + 3) = 0x40000;
      *(undefined4 *)(puVar2 + 4) = 0x40000;
      *(int *)((longlong)puVar2 + 0x24) = local_res8[0];
      *(undefined4 *)(puVar2 + 5) = 0x80002;
      *(undefined8 *)((longlong)puVar2 + 0x2c) = param_2;
      NtDeviceIoControlFile(local_100,0);
    }
  }
  if (local_100 != 0) {
    NtClose();
  }
  if (puVar2 != (undefined8 *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0);
    puVar6 = puVar2;
  }
  lVar3 = SmpTraceHandle;
  if (SmpTraceHandle != 0) {
    if (local_res8[0] != 0) {
      local_b0 = local_res8;
      uStack_a8 = 4;
      ppiVar7 = &local_b0;
      puVar4 = &SmssEvt_PlatformBinaryExecutionFailed;
    }
    else {
      ppiVar7 = (int **)0x0;
      puVar4 = &SmssEvt_PlatformBinaryExecuted;
    }
    puVar6 = (undefined8 *)(ulonglong)(local_res8[0] != 0);
    EtwEventWrite(SmpTraceHandle,puVar4);
  }
  if (param_4 == (int **)0x0) {
    if (DAT_140030e48 < 6) {
      return;
    }
    pbVar5 = &DAT_14002bfce;
    uVar8 = 4;
  }
  else {
    if (DAT_140030e48 < 6) {
      return;
    }
    pbVar5 = &DAT_14002bfff;
    local_58 = local_40;
    local_48 = param_4[1];
    local_40[0] = (uint)*(ushort *)param_4;
    uVar8 = 6;
    local_50 = 2;
    local_40[1] = 0;
  }
  local_68 = &local_f8;
  local_78 = local_108;
  local_108[0] = local_res8[0];
  local_70 = 4;
  local_60 = 8;
  local_f8 = param_3;
  _tlgWriteTransfer_EtwEventWriteTransfer(lVar3,pbVar5,puVar6,ppiVar7,uVar8,local_98);
  return;
}



===== SmpSetTargetAttributes @ 14001859c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpSetTargetAttributes(undefined8 param_1,uint param_2)

{
  int iVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_18 = (ulonglong)param_2;
  iVar1 = NtSetInformationFile(0,&local_48,&local_38);
  if (iVar1 < 0) {
    SmLogFailureInt(0x14002a140,0x18ca,(ulonglong)param_2,0,iVar1);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



===== SmpShuffleMove @ 140018644 =====

ulonglong SmpShuffleMove(ushort *param_1,undefined8 param_2,char param_3)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  ushort uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong local_res20;
  longlong local_88;
  ushort local_80 [4];
  longlong local_78;
  undefined8 local_70;
  longlong lStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ushort *local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong uStack_28;
  
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_res20 = 0;
  local_78 = 0;
  local_30 = 0;
  uStack_28 = uStack_28 & 0xffffffff00000000;
  local_88 = -1;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  lStack_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = (ushort *)0x0;
  uStack_38 = 0;
  if (param_3 == '\x01') {
    bVar1 = SmpCheckFolderForRedirections(param_1,&local_88);
    if (!bVar1) {
      uVar5 = 0xc000050b;
      lVar6 = local_88;
      goto LAB_1400186e3;
    }
  }
  lVar6 = local_88;
  uVar4 = *param_1 >> 1;
  if (uVar4 != 0) {
    do {
      if (*(short *)(*(longlong *)(param_1 + 4) + (ulonglong)uVar4 * 2) == 0x5c) {
        local_70._0_4_ = CONCAT22(uVar4 * 2,uVar4 * 2);
        lStack_68 = *(longlong *)(param_1 + 4);
        uVar2 = SmpCheckDirectoryWritable(&local_70);
        uVar5 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          RtlInitUnicodeString(&local_60,DAT_1400329f8 + 8);
          uVar3 = SmpCreateTempFile((longlong)&local_60,L"SMSS-PFRO",(undefined8 *)local_80);
          uVar5 = uVar3 & 0xffffffff;
          if (-1 < (int)uVar3) {
            uStack_48 = 0;
            local_50 = CONCAT44(local_50._4_4_,0x30);
            uStack_38 = CONCAT44(uStack_38._4_4_,0x40);
            local_30 = 0;
            uStack_28 = 0;
            local_40 = param_1;
            uVar3 = SmpOpenTargetFile(&local_res20,0x110000,&local_50,'\x01');
            uVar5 = uVar3 & 0xffffffff;
            if (-1 < (int)uVar3) {
              uVar2 = SmpRenameTargetFile(local_80,local_res20,1,param_3);
              uVar5 = (ulonglong)uVar2;
              if (-1 < (int)uVar2) {
                uVar2 = SmpRenameTargetFile(param_1,param_2,1,param_3);
                uVar5 = (ulonglong)uVar2;
                if ((int)uVar2 < 0) {
                  SmpRenameTargetFile(param_1,local_res20,1,param_3);
                }
                else {
                  uVar5 = 0;
                }
              }
            }
          }
        }
        goto LAB_1400186e3;
      }
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  uVar5 = 0xc000000d;
LAB_1400186e3:
  if (local_78 != 0) {
    RtlFreeUnicodeString(local_80);
  }
  if (local_res20 != 0) {
    NtClose();
  }
  if (lVar6 != -1) {
    NtClose(lVar6);
  }
  return uVar5;
}



===== SmpSuffixUnicodeString @ 140018844 =====

ulonglong SmpSuffixUnicodeString(undefined8 param_1,ushort *param_2)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  ushort uVar2;
  undefined2 local_18;
  short local_16;
  undefined4 local_14;
  longlong local_10;
  
  local_14 = 0;
  if (*param_2 < 0x24) {
    uVar1 = in_RAX & 0xffffffffffffff00;
  }
  else {
    uVar2 = *param_2 - 0x24;
    local_18 = 0x24;
    local_10 = *(longlong *)(param_2 + 4) + (ulonglong)(uVar2 >> 1) * 2;
    local_16 = param_2[1] - uVar2;
    uVar1 = RtlEqualUnicodeString
                      (&SmpStateMigrationKeyword,&local_18,CONCAT71((uint7)(byte)(uVar2 >> 8),1));
  }
  return uVar1;
}



===== SmpTryOverwriteReadonlyFile @ 1400188b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SmpTryOverwriteReadonlyFile(ushort *param_1,undefined8 param_2,char param_3)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  longlong local_98;
  longlong local_90 [3];
  ushort *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_c8;
  local_6c = 0;
  local_98 = 0;
  local_90[2] = 0;
  local_90[1] = 0x30;
  lVar6 = -1;
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90[0] = -1;
  local_48 = 0;
  uStack_40 = 0;
  local_70 = 0x40;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = param_1;
  uVar2 = NtQueryAttributesFile(local_90 + 1,&local_58);
  uVar5 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    if ((local_38 & 0x10) == 0) {
      if ((local_38 & 1) == 0) {
        uVar5 = 0xc0000001;
      }
      else {
        if (param_3 == '\x01') {
          bVar1 = SmpCheckFolderForRedirections(param_1,local_90);
          lVar6 = local_90[0];
          if (!bVar1) {
            uVar5 = 0xc000050b;
            goto LAB_140018a1e;
          }
        }
        local_a8 = 3;
        uVar3 = SmpOpenTargetFile(&local_98,0x100100,local_90 + 1,'\x01');
        uVar5 = uVar3 & 0xffffffff;
        if (-1 < (int)uVar3) {
          uVar2 = SmpSetTargetAttributes(local_98,(uint)local_38 & 0xfffffffe);
          uVar5 = (ulonglong)uVar2;
          if (-1 < (int)uVar2) {
            NtClose(local_98);
            local_98 = 0;
            uVar2 = SmpRenameTargetFile(param_1,param_2,1,param_3);
            uVar5 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              local_a8 = 3;
              uVar4 = SmpOpenTargetFile(&local_98,0x110100,local_90 + 1,'\x01');
              if (-1 < (int)uVar4) {
                SmpSetTargetAttributes(local_98,(uint)local_38);
              }
            }
            else {
              uVar5 = 0;
            }
          }
        }
      }
    }
    else {
      uVar5 = 0xc00000ba;
    }
  }
LAB_140018a1e:
  if (local_98 != 0) {
    NtClose();
  }
  if (lVar6 != -1) {
    NtClose(lVar6);
  }
  return uVar5;
}



===== SmpEstablishClientSecurity @ 140018a80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpEstablishClientSecurity(undefined8 param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_a8 [32];
  undefined4 *local_88;
  undefined4 local_78 [2];
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  local_68 = 0;
  local_78[0] = 0;
  local_70 = 0;
  local_30 = 0;
  uVar2 = 2;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (*(longlong *)(param_2 + 4) == 0) {
    RtlAcquireSRWLockShared(param_2 + 6);
    RtlReleaseSRWLockShared(param_2 + 6);
  }
  iVar1 = NtAlpcImpersonateClientOfPort(*(undefined8 *)(param_2 + 4),param_1,0);
  if (-1 < iVar1) {
    iVar1 = NtOpenThreadToken(0xfffffffffffffffe,0xc,0,&local_70);
    if (-1 < iVar1) {
      local_88 = local_78;
      iVar1 = NtQueryInformationToken(local_70,10,&local_60,0x38);
      if (((-1 < iVar1) &&
          ((((int)uStack_48 != 2 || (1 < uStack_48._4_4_)) && ((int)uStack_58 == 999)))) &&
         (uVar2 = 2, uStack_58._4_4_ == 0)) {
        uVar2 = 4;
      }
      NtClose(local_70);
    }
    NtSetInformationThread(0xfffffffffffffffe,5,&local_68);
  }
  RtlAcquireSRWLockExclusive(param_2 + 6);
  if ((*param_2 & 6) == 0) {
    if (-1 < iVar1) {
      *param_2 = *param_2 | uVar2;
    }
  }
  else {
    iVar1 = 0;
  }
  RtlReleaseSRWLockExclusive(param_2 + 6);
  return iVar1;
}



===== SmpInitCoreProcessArray @ 140018c14 =====

undefined8 SmpInitCoreProcessArray(void)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  
  uVar1 = SmpNumberInitialSessions;
  uVar4 = (ulonglong)SmpNumberInitialSessions;
  puVar2 = (undefined8 *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),SmBaseTag,
                           uVar4 * 0x28);
  SmpCoreProcessIds = puVar2;
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc0000017;
  }
  else {
    if (uVar1 != 0) {
      *puVar2 = 0xffffffff;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar5 = puVar2 + 5;
      for (uVar4 = uVar4 * 0x28 - 0x28 >> 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== SmpSetCoreProcessIds @ 140018cc4 =====

void SmpSetCoreProcessIds(int param_1,undefined8 *param_2,char param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  
  uVar5 = SmpSessionIdToInitialSessionIndex(param_1);
  puVar2 = (undefined4 *)(SmpCoreProcessIds + (uVar5 & 0xffffffff) * 0x28);
  if (param_3 != '\0') {
    *puVar2 = 0xffffffff;
  }
  puVar1 = puVar2 + 2;
  iVar7 = 0;
  RtlAcquireSRWLockExclusive(puVar1);
  piVar3 = (int *)*param_2;
  if (piVar3 != (int *)0x0) {
    if ((*(byte *)(piVar3 + 2) & 4) != 0) {
      RtlReleaseSRWLockExclusive(puVar1);
      SmpLogFailure(0x14002a6d8,0x44f,0xc0000001);
      return;
    }
    LOCK();
    *piVar3 = *piVar3 + 1;
    UNLOCK();
  }
  puVar6 = param_2;
  lVar9 = 2;
  do {
    lVar8 = lVar9;
    uVar4 = *(undefined8 *)((longlong)puVar2 + (0x18 - (longlong)param_2) + (longlong)puVar6);
    *(undefined8 *)((longlong)puVar2 + (0x18 - (longlong)param_2) + (longlong)puVar6) = *puVar6;
    *puVar6 = uVar4;
    puVar6 = puVar6 + 1;
    lVar9 = lVar8 + -1;
  } while (lVar9 != 0);
  if ((puVar2[1] == 0) && (*(longlong *)(puVar2 + 8) != 0)) {
    iVar7 = (int)lVar8;
    puVar2[1] = iVar7;
  }
  RtlReleaseSRWLockExclusive(puVar1);
  if (iVar7 == 1) {
    RtlWakeAllConditionVariable(puVar2 + 4);
  }
  if ((int *)*param_2 != (int *)0x0) {
    SmpDereferenceKnownSubSys((int *)*param_2);
  }
  return;
}



===== SmpAdoptJob @ 140018dd0 =====

int SmpAdoptJob(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = NtDuplicateObject(*(undefined8 *)(param_2 + 0x20),*(undefined8 *)(param_1 + 0x30),
                            0xffffffffffffffff,local_res8,0x1f003f,0,0);
  if (iVar1 < 0) {
    SmpLogFailure(0x14002a708,0x227,iVar1);
  }
  else {
    iVar1 = NtAssignProcessToJobObject(local_res8[0],0xfffffffffffffff9);
    NtClose(local_res8[0]);
  }
  return iVar1;
}



===== SmpNotImplemented @ 140018e70 =====

undefined8 SmpNotImplemented(void)

{
  return 0xc0000002;
}



===== SmpStartServerSilo @ 140018e80 =====

int SmpStartServerSilo(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint *local_res8;
  undefined8 in_stack_ffffffffffffff38;
  undefined8 in_stack_ffffffffffffff48;
  uint uVar4;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
  uVar4 = (uint)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  local_res8 = (uint *)0x0;
  local_78._4_4_ = 0;
  memset(&local_78,0,100);
  iVar1 = NtDuplicateObject(*(undefined8 *)(param_2 + 0x20),*(undefined8 *)(param_1 + 0x30),
                            0xffffffffffffffff,&local_res8,CONCAT44(uVar2,0x1f003f),0,
                            (ulonglong)uVar4 << 0x20);
  if (iVar1 < 0) {
    uVar2 = 0x1b8;
  }
  else {
    uVar3 = 0x28;
    iVar1 = NtQueryInformationJobObject(local_res8);
    if (-1 < iVar1) {
      iVar1 = SmpExecuteImage(&SmpHelperCmd,0,0,uVar3,local_res8,0x5020,&local_78);
      if (iVar1 < 0) {
        NtClose(local_res8);
        SmpLogFailureString(0x14002a6f0,0x1db,DAT_1400324a8,iVar1);
        return iVar1;
      }
      if ((*(char *)(param_1 + 0x38) == '\0') && (iVar1 = NtResumeThread(local_68,0), iVar1 < 0)) {
        SmpLogFailure(0x14002a6f0,0x1e8,iVar1);
        NtTerminateProcess(local_70,0);
      }
      NtClose(local_res8);
      NtClose(local_70);
      NtClose(local_68);
      return iVar1;
    }
    NtClose(local_res8);
    uVar2 = 0x1ca;
  }
  SmpLogFailure(0x14002a6f0,uVar2,iVar1);
  return iVar1;
}



===== SmpCreateInitialSession @ 140019050 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmpCreateInitialSession(void)

{
  int iVar1;
  undefined1 auStack_1b8 [32];
  int local_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 *local_180;
  longlong local_178;
  undefined8 local_168;
  undefined8 local_160;
  undefined4 local_140;
  undefined4 local_138;
  undefined4 local_134;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1b8;
  memset(&local_168,0,0x148);
  local_190 = 0;
  uStack_188 = 0;
  local_138 = 0xffffffff;
  local_134 = 0;
  local_140 = 5;
  local_160 = SmpUniqueProcessId;
  iVar1 = SmpStartCsr(&local_168);
  if (iVar1 < 0) {
    local_198 = iVar1;
    RtlInitUnicodeString(&local_190,L"Session Manager Core Session failure");
    local_180 = &local_190;
    local_178 = (longlong)iVar1;
    SmpLogFailure(0x14002aab0,0x337,iVar1);
                    /* WARNING: Subroutine does not return */
    SmpTerminate(&local_180,1,2);
  }
  return;
}



===== SmpTerminate @ 14001913c =====

void SmpTerminate(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_res20 [8];
  undefined4 local_38 [2];
  undefined *local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_18 = 0x17;
  local_28 = 0xe08;
  local_38[0] = 0;
  local_res20[0] = 0;
  local_20 = 0;
  local_30 = &SmpBlackboxBuffer;
  NtPowerInformation(0x5e,&local_30,0x20,0,0);
  iVar1 = RtlAdjustPrivilege(0x13,1,1,local_res20);
  if (iVar1 == -0x3fffff84) {
    RtlAdjustPrivilege(0x13,1,0,local_res20);
  }
  uVar2 = NtRaiseHardError(0xc000021a,param_3,param_2,param_1,6,local_38);
  NtTerminateProcess(0xffffffffffffffff,uVar2);
  return;
}



===== SmpUnhandledExceptionFilter @ 140019234 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SmpUnhandledExceptionFilter(undefined8 *param_1)

{
  int *piVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_48 = 0;
  uStack_40 = 0;
  if (*(char *)((longlong)ProcessEnvironmentBlock + 2) != '\x01') {
    RtlInitUnicodeString(&local_48,L"Unhandled Exception in Session Manager");
    piVar1 = (int *)*param_1;
    local_38 = &local_48;
    local_30 = (longlong)*piVar1;
    local_28 = *(undefined8 *)(piVar1 + 4);
    local_20 = param_1[1];
    SmLogFailureInt(0x14002aa40,0x2e9,*(undefined8 *)(piVar1 + 8),*(undefined8 *)(piVar1 + 4),
                    *piVar1);
                    /* WARNING: Subroutine does not return */
    SmpTerminate(&local_38,1,4);
  }
  return 0;
}



===== WppControlCallback @ 140019300 =====

undefined8 WppControlCallback(int param_1,longlong param_2,undefined4 *param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  *param_3 = 0;
  if (param_1 == 4) {
    uVar3 = EtwGetTraceLoggerHandle(param_4);
    uVar1 = EtwGetTraceEnableLevel(uVar3);
    uVar2 = EtwGetTraceEnableFlags(uVar3);
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



===== SmpDeleteSubSys @ 140019398 =====

void SmpDeleteSubSys(int *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 *puVar6;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  int local_18 [4];
  
  local_18[2] = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  if ((*(byte *)(param_1 + 2) & 4) != 0) {
    return;
  }
  bVar5 = true;
  SmpLockKnownSubSysList(param_1[0x10],0,local_18);
  puVar6 = auStack_38;
  if ((*(byte *)(param_1 + 2) & 4) == 0) {
    LOCK();
    param_1[2] = param_1[2] | 4;
    UNLOCK();
    plVar1 = (longlong *)(param_1 + 0x12);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar3 = *(longlong **)(param_1 + 0x14), (longlong *)*plVar3 == plVar1)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      puVar6 = auStack_38;
      goto LAB_1400193fb;
    }
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar6 = auStack_30;
  }
  bVar5 = false;
LAB_1400193fb:
  *(undefined8 *)(puVar6 + -8) = 0x140019405;
  SmpUnlockKnownSubSysList((int *)(puVar6 + 0x20));
  if (bVar5) {
    *(undefined8 *)(puVar6 + -8) = 0x140019412;
    SmpCompleteSubSysStatusChange((longlong)param_1);
    *(undefined8 *)(puVar6 + -8) = 0x14001941a;
    SmpDereferenceKnownSubSys(param_1);
  }
  return;
}



===== SmpDisposeSubSysSynch @ 14001942c =====

void SmpDisposeSubSysSynch(undefined8 *param_1)

{
  undefined8 *puVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    puVar1 = param_1;
    if (SmpSubSysSynchCacheSize < 0x10) {
      NtClearEvent(param_1[1]);
      RtlAcquireSRWLockExclusive(&SmpSubSysSynchLock);
      if (SmpSubSysSynchCacheSize < 0x10) {
        SmpSubSysSynchCacheSize = SmpSubSysSynchCacheSize + 1;
        *param_1 = SmpSubSysSynchCache;
        puVar1 = (undefined8 *)0x0;
        SmpSubSysSynchCache = param_1;
      }
      RtlReleaseSRWLockExclusive(&SmpSubSysSynchLock);
      if (puVar1 == (undefined8 *)0x0) {
        return;
      }
    }
    NtClose(puVar1[1]);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar1);
  }
  return;
}



===== SmpGetSubSysSynch @ 1400194e4 =====

undefined8 * SmpGetSubSysSynch(void)

{
  int iVar1;
  undefined8 *puVar2;
  
  if (SmpSubSysSynchCache != (undefined8 *)0x0) {
    RtlAcquireSRWLockExclusive(&SmpSubSysSynchLock);
    puVar2 = (undefined8 *)0x0;
    if (SmpSubSysSynchCache != (undefined8 *)0x0) {
      SmpSubSysSynchCacheSize = SmpSubSysSynchCacheSize + -1;
      puVar2 = SmpSubSysSynchCache;
      SmpSubSysSynchCache = (undefined8 *)*SmpSubSysSynchCache;
    }
    RtlReleaseSRWLockExclusive(&SmpSubSysSynchLock);
    if (puVar2 != (undefined8 *)0x0) goto LAB_1400195b8;
  }
  puVar2 = (undefined8 *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                           SmBaseTag + 0x80000,0x10);
  if (puVar2 == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  iVar1 = NtCreateEvent(puVar2 + 1,0x100002,0,0,0);
  if (iVar1 < 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar2);
    return (undefined8 *)0x0;
  }
LAB_1400195b8:
  *(undefined4 *)puVar2 = 0;
  return puVar2;
}



===== SmpWaitForStatusChange @ 1400195cc =====

int SmpWaitForStatusChange(longlong param_1,int param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined7 extraout_var;
  int *piVar4;
  undefined8 uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  do {
    piVar6 = *(int **)(param_1 + 0x10);
    piVar7 = (int *)0x0;
    if (*(int **)(param_1 + 0x10) != (int *)0x0) goto LAB_14001966c;
    SmpUnlockKnownSubSysList(param_3);
    piVar3 = (int *)SmpGetSubSysSynch();
    if (piVar3 == (int *)0x0) {
      local_resc = 0xffffffff;
      local_res8 = 0xfd050f80;
      NtDelayExecution(0,&local_res8);
    }
    SmpLockKnownSubSysList(*(uint *)(param_1 + 0x40),*param_3,(int *)0x0);
    bVar1 = SmpCheckSubSysStatus(param_1);
    if ((int)CONCAT71(extraout_var,bVar1) != 0) {
      if (piVar3 != (int *)0x0) {
        SmpDisposeSubSysSynch((undefined8 *)piVar3);
      }
      return 0;
    }
  } while (piVar3 == (int *)0x0);
  if (*(longlong *)(param_1 + 0x10) == 0) {
    LOCK();
    piVar4 = *(int **)(param_1 + 0x10);
    bVar1 = piVar4 == (int *)0x0;
    if (bVar1) {
      *(int **)(param_1 + 0x10) = piVar3;
      piVar4 = (int *)0x0;
    }
    UNLOCK();
    piVar6 = piVar3;
    if (!bVar1) {
      piVar6 = piVar4;
      piVar7 = piVar3;
    }
  }
  else {
    piVar6 = *(int **)(param_1 + 0x10);
    piVar7 = piVar3;
  }
LAB_14001966c:
  LOCK();
  *piVar6 = *piVar6 + 1;
  UNLOCK();
  SmpUnlockKnownSubSysList(param_3);
  if (piVar7 != (int *)0x0) {
    SmpDisposeSubSysSynch((undefined8 *)piVar7);
  }
  local_28 = *(undefined8 *)(piVar6 + 2);
  uVar5 = 1;
  if (param_2 == 1) {
    uStack_20 = *(undefined8 *)(param_1 + 0x20);
    uVar5 = 2;
  }
  iVar2 = NtWaitForMultipleObjects(uVar5,&local_28,1,0,0);
  if (iVar2 == 0) {
    LOCK();
    iVar2 = *piVar6;
    *piVar6 = *piVar6 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      SmpDisposeSubSysSynch((undefined8 *)piVar6);
    }
    iVar2 = 0;
  }
  else if (iVar2 == 1) {
    uVar5 = SmpGetProcessId();
    SmLogFailureInt(0x14002ab18,0x3c5,uVar5,0,1);
    iVar2 = -0x3fffffff;
  }
  SmpLockKnownSubSysList(*(uint *)(param_1 + 0x40),*param_3,(int *)0x0);
  return iVar2;
}



===== SmpSaveRegistryValue @ 140019758 =====

void SmpSaveRegistryValue(longlong *param_1,undefined8 param_2,longlong param_3,uint param_4)

{
  ushort *puVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  RtlInitUnicodeString(&local_18);
  puVar1 = (ushort *)0x0;
  if (param_3 != 0) {
    RtlInitUnicodeString(local_28,param_3);
    puVar1 = local_28;
  }
  SmpSaveRegistryValue_U(param_1,(undefined2 *)&local_18,puVar1,param_4);
  return;
}



===== SmscpIsDebuggerPresent @ 1400197e4 =====

int SmscpIsDebuggerPresent(void)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  local_1c = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_48 = 0;
  uStack_40 = 0;
  local_28 = &SmscpDebuggerString;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = 0x40;
  iVar1 = NtOpenFile(&local_res8,0x120089,&local_38,&local_48,5,0x60);
  if (-1 < iVar1) {
    NtClose(local_res8);
  }
  return iVar1;
}



===== SmscpNotifySmOfFailure @ 140019884 =====

void SmscpNotifySmOfFailure(void)

{
  undefined4 uVar1;
  undefined1 auStack_198 [32];
  undefined4 local_178;
  undefined4 local_174;
  undefined1 local_168 [40];
  undefined4 local_140;
  undefined4 local_138;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_198;
  local_174 = 0xffffffff;
  local_178 = 0xfd050f80;
  uVar1 = *(undefined4 *)((longlong)ProcessEnvironmentBlock + 0x2c0);
  do {
    memset(local_168,0,0x148);
    local_140 = 6;
    local_138 = uVar1;
    RtlSendMsgToSm(SmpApiConnectionPort,local_168);
    NtDelayExecution(0);
  } while( true );
}



===== ApiSetpResolveHost @ 14001990c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ApiSetpResolveHost(longlong param_1,ulonglong *param_2,undefined8 param_3,undefined8 param_4,
                  ushort *param_5,undefined1 *param_6,short *param_7)

{
  short sVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  int *piVar7;
  ushort uVar8;
  ushort uVar9;
  undefined1 uVar10;
  undefined1 auStackY_c8 [32];
  longlong local_98 [2];
  undefined8 uStack_88;
  int iStack_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ushort *local_68;
  undefined1 *local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_68 = param_5;
  local_60 = param_6;
  uVar10 = 0;
  local_70 = 0;
  param_7[0] = 0;
  param_7[1] = 0;
  param_7[2] = 0;
  param_7[3] = 0;
  param_7[4] = 0;
  param_7[5] = 0;
  param_7[6] = 0;
  param_7[7] = 0;
  local_98[1] = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  uVar5 = ApiSetpGetContractKeyInfo(param_2,(ushort)param_3,param_3,local_98 + 1);
  if ((char)uVar5 == '\0') goto LAB_140019cb8;
  if (iStack_84 == 1) {
    uVar3 = ApiSetpSearchForSectionIndex_V7(param_1,(int *)(param_1 + 0x2c),local_98 + 1);
    if (uVar3 == 0xffff) goto LAB_140019cb8;
    uVar5 = (ulonglong)*(ushort *)(param_1 + 0x12);
    piVar7 = (int *)((ulonglong)*(uint *)(param_1 + 0x2c) +
                    ((ulonglong)uVar3 * (ulonglong)*(byte *)(param_1 + 0x34) - uVar5) + param_1);
    iVar4 = ApiSetpGetSearchKeyHash
                      (local_98 + 1,'\x01',*(byte *)(param_1 + 2) >> 3 & 1,
                       *(byte *)(param_1 + 2) >> 4 & 1,*(byte *)(param_1 + 0x37));
    if (*piVar7 != iVar4) goto LAB_140019cb8;
    uVar3 = *(ushort *)(piVar7 + 2);
    bVar2 = *(byte *)((longlong)piVar7 + 10);
    uVar8 = *(ushort *)(piVar7 + 1);
    uVar9 = *(ushort *)((longlong)piVar7 + 6);
  }
  else if (iStack_84 == 2) {
    uVar10 = 1;
    uVar3 = ApiSetpSearchForSectionIndex_V7(param_1,(int *)(param_1 + 0x38),local_98 + 1);
    if (uVar3 == 0xffff) goto LAB_140019cb8;
    piVar7 = (int *)((ulonglong)*(uint *)(param_1 + 0x38) +
                    param_1 + ((ulonglong)*(byte *)(param_1 + 0x40) * (ulonglong)uVar3 -
                              (ulonglong)*(ushort *)(param_1 + 0x12)));
    iVar4 = ApiSetpGetSearchKeyHash
                      (local_98 + 1,'\0',*(byte *)(param_1 + 2) >> 3 & 1,
                       *(byte *)(param_1 + 2) >> 4 & 1,*(byte *)(param_1 + 0x43));
    if (*piVar7 != iVar4) {
      uVar10 = 0;
      goto LAB_140019cb8;
    }
    if ((*(byte *)((longlong)piVar7 + 6) & 4) != 0) {
      if ((*(byte *)((longlong)piVar7 + 6) & 2) != 0) goto LAB_140019cb8;
      if (piVar7[2] != 0) {
        local_98[0] = 0;
        local_58 = 0;
        local_50 = 0;
        iVar4 = RtlQueryFeatureConfiguration(piVar7[2],0,local_98,&local_58);
        if ((((iVar4 != 0) || (local_98[0] == 0)) || ((int)local_58 != piVar7[2])) ||
           (((byte)((ulonglong)local_58 >> 0x20) & 0x30) != 0x20)) goto LAB_140019cb8;
      }
    }
    uVar5 = (ulonglong)*(ushort *)(param_1 + 0x12);
    lVar6 = (((ulonglong)*(byte *)(param_1 + 0x34) * (ulonglong)*(ushort *)(piVar7 + 1) +
             (ulonglong)*(uint *)(param_1 + 0x2c)) - (ulonglong)*(ushort *)(param_1 + 0x12)) +
            param_1;
    uVar3 = *(ushort *)(lVar6 + 8);
    bVar2 = *(byte *)(lVar6 + 10);
    uVar8 = *(ushort *)(lVar6 + 4);
    uVar9 = *(ushort *)(lVar6 + 6);
  }
  else {
    if (iStack_84 != 3) goto LAB_140019cb8;
    uVar3 = ApiSetpSearchForSectionIndex_V7(param_1,(int *)(param_1 + 0x44),local_98 + 1);
    if (uVar3 == 0xffff) goto LAB_140019cb8;
    uVar5 = (ulonglong)*(ushort *)(param_1 + 0x12);
    piVar7 = (int *)((ulonglong)*(uint *)(param_1 + 0x44) +
                    ((ulonglong)uVar3 * (ulonglong)*(byte *)(param_1 + 0x4c) - uVar5) + param_1);
    iVar4 = ApiSetpGetSearchKeyHash
                      (local_98 + 1,'\0',*(byte *)(param_1 + 2) >> 3 & 1,
                       *(byte *)(param_1 + 2) >> 4 & 1,*(byte *)(param_1 + 0x4f));
    if ((*piVar7 != iVar4) ||
       (((*(byte *)((longlong)piVar7 + 10) & 4) != 0 &&
        (*(byte *)((longlong)piVar7 + 9) < (ushort)uStack_78)))) goto LAB_140019cb8;
    lVar6 = (((ulonglong)*(byte *)(param_1 + 0x34) * (ulonglong)*(ushort *)(piVar7 + 1) +
             (ulonglong)*(uint *)(param_1 + 0x2c)) - uVar5) + param_1;
    uVar3 = *(ushort *)(lVar6 + 8);
    bVar2 = *(byte *)(lVar6 + 10);
    uVar8 = *(ushort *)(lVar6 + 4);
    uVar9 = *(ushort *)(lVar6 + 6);
  }
  uVar10 = 1;
  if (((bVar2 >> 1 & 1) != 0) &&
     (lVar6 = ((ulonglong)*(byte *)(param_1 + 100) * (ulonglong)uVar8 +
              (ulonglong)*(uint *)(param_1 + 0x5c)) - uVar5,
     *(byte *)(lVar6 + 10 + param_1) <= *(byte *)(param_1 + 3))) {
    *(ulonglong *)(param_7 + 4) =
         (ulonglong)*(uint *)(param_1 + 0x24) + (*(uint *)(lVar6 + 4 + param_1) - uVar5) + param_1;
    sVar1 = *(short *)(lVar6 + 8 + param_1) * 2;
    *param_7 = sVar1;
    param_7[1] = sVar1;
    if ((local_68 != (ushort *)0x0) && (uVar3 != 0)) {
      uVar5 = ApiSetpSearchForHostOverrideIndex_V7
                        (param_1,(uint)uVar9,(uint)uVar3,*(undefined8 *)(local_68 + 4),
                         *local_68 >> 1);
      if ((int)uVar5 != 0xffff) {
        lVar6 = ((ulonglong)*(ushort *)(param_1 + 0x72) * (uVar5 & 0xffffffff) +
                (ulonglong)*(uint *)(param_1 + 0x68)) - (ulonglong)*(ushort *)(param_1 + 0x12);
        *(ulonglong *)(param_7 + 4) =
             (ulonglong)*(uint *)(param_1 + 0x24) +
             ((ulonglong)*(uint *)(lVar6 + 8 + param_1) - (ulonglong)*(ushort *)(param_1 + 0x12)) +
             param_1;
        param_7[1] = *(short *)(lVar6 + 0xe + param_1) * 2;
        *param_7 = *(short *)(lVar6 + 0xe + param_1) * 2;
      }
    }
  }
LAB_140019cb8:
  *local_60 = uVar10;
  return 0;
}



===== ApiSetpGetContractKeyInfo @ 140019cf0 =====

ulonglong ApiSetpGetContractKeyInfo
                    (ulonglong *param_1,ushort param_2,undefined8 param_3,undefined8 *param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  uint uVar7;
  ulonglong uVar8;
  ushort uVar9;
  ulonglong uVar10;
  short sVar11;
  char *pcVar12;
  byte *pbVar13;
  
  uVar10 = (ulonglong)param_2;
  uVar8 = 0;
  *param_4 = 0;
  param_4[1] = 0;
  param_4[2] = 0;
  param_4[3] = 0;
  param_4[4] = 0;
  if (((param_2 < 5) || (uVar8 = (ulonglong)(ushort)(param_2 * 2), (ushort)(param_2 * 2) < 8)) ||
     ((uVar8 = *param_1 & 0xffffffdfffdfffdf, uVar8 != 0x2d004900500041 &&
      (uVar8 != 0x2d005400580045)))) {
LAB_140019e48:
    return uVar8 & 0xffffffffffffff00;
  }
  *param_4 = param_1;
  *(ushort *)(param_4 + 1) = param_2;
  *(undefined1 *)((longlong)param_4 + 10) = 1;
  pbVar13 = (byte *)((longlong)param_1 + uVar10 * 2);
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  sVar11 = 0;
  bVar5 = true;
  do {
    param_2 = param_2 - 1;
    pbVar13 = pbVar13 + -2;
    uVar9 = (ushort)uVar10;
    if (*pbVar13 == 0x2d) {
      if (bVar2) {
        if (!bVar3) {
          *(short *)(param_4 + 3) = sVar11;
          bVar3 = true;
          sVar11 = 0;
          *(undefined4 *)((longlong)param_4 + 0xc) = 3;
          *(ushort *)((longlong)param_4 + 0x12) = param_2;
          bVar5 = true;
          bVar2 = false;
          goto LAB_140019e3e;
        }
      }
      else {
        *(undefined4 *)((longlong)param_4 + 0xc) = 1;
        *(ushort *)((longlong)param_4 + 0x12) = uVar9;
        param_2 = uVar9;
      }
LAB_140019e94:
      *(ushort *)((longlong)param_4 + 0x14) = param_2;
      if ((((7 < param_2) && (((char)param_1[1] + 0xb3U & 0xdf) == 0)) &&
          ((*(char *)((longlong)param_1 + 10) + 0xadU & 0xdf) == 0)) &&
         (*(char *)((longlong)param_1 + 0xc) == '-')) {
        *(undefined4 *)((longlong)param_4 + 0x1a) = 0x60004;
      }
      uVar8 = (ulonglong)param_2;
      bVar2 = false;
      bVar6 = 0;
      pcVar12 = (char *)(uVar8 * 2 + (longlong)param_1);
      break;
    }
    if (*pbVar13 == 0x7e) {
      if (!bVar3) {
        *(ushort *)((longlong)param_4 + 0x12) = uVar9;
        uVar9 = (uVar9 - param_2) - 1;
        uVar10 = (ulonglong)uVar9;
        *(undefined4 *)((longlong)param_4 + 0xc) = 2;
        *(ushort *)((longlong)param_4 + 0x16) = uVar9;
        goto LAB_140019e94;
      }
      goto LAB_140019e48;
    }
    if (*pbVar13 == 0x2e) {
      if ((bVar3) || (bVar4)) goto LAB_140019e48;
      uVar10 = (ulonglong)param_2;
      bVar4 = true;
      bVar5 = true;
      bVar2 = false;
    }
    else {
      uVar8 = CONCAT71((int7)(uVar8 >> 8),*pbVar13 - 0x30);
      if ((byte)(*pbVar13 - 0x30) < 10) {
        uVar8 = 0;
        sVar11 = sVar11 * 10 + -0x30 + (ushort)*pbVar13;
        if (bVar5) {
          bVar2 = true;
        }
      }
      else {
        bVar2 = false;
      }
      bVar5 = false;
    }
LAB_140019e3e:
    if (param_2 < 2) goto LAB_140019e48;
  } while( true );
LAB_140019f03:
  if (param_2 < 5) {
LAB_140019f3c:
    return CONCAT71((int7)(uVar8 >> 8),1);
  }
  cVar1 = pcVar12[-2];
  uVar10 = CONCAT71((int7)(uVar10 >> 8),cVar1);
  uVar7 = (int)uVar10 - 0x30;
  uVar8 = (ulonglong)uVar7;
  if (9 < (byte)uVar7) {
    if (((bVar2) && ((cVar1 + 0xb4U & 0xdf) == 0)) && (pcVar12[-4] == '-')) {
      *(ushort *)((longlong)param_4 + 0x1e) = param_2 - 2;
      *(ushort *)(param_4 + 4) = bVar6 + 1 + (param_2 - 2);
    }
    goto LAB_140019f3c;
  }
  if ((!bVar2) && (cVar1 == '1')) {
    bVar6 = 1;
  }
  bVar2 = true;
  pcVar12 = pcVar12 + -2;
  param_2 = param_2 - 1;
  goto LAB_140019f03;
}



===== ApiSetpGetSearchKeyHash @ 140019f4c =====

int ApiSetpGetSearchKeyHash(longlong *param_1,char param_2,char param_3,char param_4,byte param_5)

{
  bool bVar1;
  ushort uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  
  pbVar6 = (byte *)((ulonglong)*(ushort *)(param_1 + 2) + *param_1);
  iVar5 = 0;
  if (param_2 == '\0') {
    uVar2 = *(ushort *)((longlong)param_1 + 0x12);
  }
  else {
    uVar2 = *(ushort *)((longlong)param_1 + 0x14);
  }
  uVar4 = 0;
  if (param_4 != '\0') {
    uVar4 = 4;
    pbVar6 = pbVar6 + (-(ulonglong)(*(char *)((longlong)param_1 + 10) != '\0') & 4) + 4;
  }
  if (uVar4 < uVar2) {
    do {
      if (param_3 == '\0') {
LAB_140019ff9:
        bVar3 = *pbVar6;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          bVar3 = bVar3 + 0x20;
        }
        iVar5 = (uint)bVar3 + (uint)param_5 * iVar5;
      }
      else {
        bVar1 = false;
        if ((*(short *)((longlong)param_1 + 0x1a) != 0) &&
           (*(ushort *)((longlong)param_1 + 0x1a) <= uVar4)) {
          bVar1 = false;
          if (uVar4 <= *(ushort *)((longlong)param_1 + 0x1c)) {
            bVar1 = true;
          }
        }
        if ((((*(short *)((longlong)param_1 + 0x1e) == 0) ||
             (uVar4 < *(ushort *)((longlong)param_1 + 0x1e))) || (*(ushort *)(param_1 + 4) < uVar4))
           && (!bVar1)) goto LAB_140019ff9;
      }
      pbVar6 = pbVar6 + (ulonglong)(*(char *)((longlong)param_1 + 10) != '\0') + 1;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  return iVar5;
}



===== ApiSetpSearchForHostOverrideIndex_V7 @ 14001a040 =====

ulonglong ApiSetpSearchForHostOverrideIndex_V7
                    (longlong param_1,uint param_2,uint param_3,undefined8 param_4,
                    undefined2 param_5)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  
  if ((param_3 != 0) && (uVar3 = 0, param_3 != 0)) {
    do {
      lVar2 = ((ulonglong)*(ushort *)(param_1 + 0x72) * (ulonglong)param_2 +
              (ulonglong)*(uint *)(param_1 + 0x68)) - (ulonglong)*(ushort *)(param_1 + 0x12);
      iVar1 = RtlCompareUnicodeStrings
                        (param_4,param_5,
                         (((ulonglong)*(uint *)(lVar2 + 4 + param_1) +
                          (ulonglong)*(uint *)(param_1 + 0x24)) -
                         (ulonglong)*(ushort *)(param_1 + 0x12)) + param_1,
                         *(undefined2 *)(lVar2 + 0xc + param_1),1);
      if (iVar1 == 0) {
        return (ulonglong)param_2;
      }
      param_2 = (uint)*(ushort *)(lVar2 + param_1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_3);
  }
  return 0xffff;
}



===== ApiSetpSearchForSectionIndex_V7 @ 14001a104 =====

undefined2 ApiSetpSearchForSectionIndex_V7(longlong param_1,int *param_2,longlong *param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = ApiSetpGetSearchKeyHash
                    (param_3,*(byte *)((longlong)param_2 + 9) >> 1 & 1,
                     *(byte *)(param_1 + 2) >> 3 & 1,*(byte *)(param_1 + 2) >> 4 & 1,
                     *(byte *)((longlong)param_2 + 10));
  iVar5 = 0;
  iVar6 = *(ushort *)(param_2 + 1) - 1;
  if (-1 < iVar6) {
    do {
      iVar4 = iVar5 + iVar6 >> 1;
      lVar3 = ((longlong)iVar4 * 8 - (ulonglong)*(ushort *)(param_1 + 0x12)) +
              (ulonglong)((uint)*(byte *)(param_2 + 2) * (uint)*(ushort *)(param_2 + 1) + *param_2);
      uVar1 = *(uint *)(lVar3 + param_1);
      if (uVar2 < uVar1) {
        iVar6 = iVar4 + -1;
      }
      else {
        if (uVar2 <= uVar1) {
          return *(undefined2 *)(lVar3 + 4 + param_1);
        }
        iVar5 = iVar4 + 1;
      }
    } while (iVar5 <= iVar6);
  }
  return 0xffff;
}



===== PathReplaceGreedy @ 14001a1b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PathReplaceGreedy(ushort *param_1,ushort *param_2,ushort *param_3)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  int iVar13;
  ulonglong uVar14;
  ushort uVar15;
  ushort uVar16;
  ushort *puVar17;
  ushort *puVar18;
  undefined8 uStack_70;
  undefined1 local_68 [16];
  ushort local_58 [4];
  longlong local_50;
  ushort local_48 [4];
  ushort *local_40;
  ulonglong local_38;
  
  puVar9 = local_68;
  local_38 = __security_cookie ^ (ulonglong)local_48;
  local_40 = param_2;
  local_48[0] = 0;
  uVar16 = *param_3;
  uVar12 = 0;
  puVar17 = (ushort *)0x0;
  puVar8 = local_68;
  if (*param_1 <= uVar16) {
    uVar15 = 0;
    puVar8 = local_68;
    puVar18 = puVar17;
    if ((uVar16 & 0xfffe) != 0) {
      do {
        uVar16 = 0;
        if ((*param_1 & 0xfffe) != 0) {
          while ((uint)uVar16 + (uint)uVar15 < (uint)(*param_3 >> 1)) {
            uVar2 = *(undefined2 *)
                     (*(longlong *)(param_3 + 4) + (ulonglong)((uint)uVar16 + (uint)uVar15) * 2);
            *(undefined8 *)(puVar8 + -8) = 0x14001a256;
            sVar3 = RtlUpcaseUnicodeChar(uVar2);
            uVar2 = *(undefined2 *)(*(longlong *)(param_1 + 4) + (ulonglong)uVar16 * 2);
            *(undefined8 *)(puVar8 + -8) = 0x14001a271;
            sVar4 = RtlUpcaseUnicodeChar(uVar2);
            if ((sVar3 != sVar4) || (uVar16 = uVar16 + 1, *param_1 >> 1 <= uVar16)) break;
          }
          uVar12 = local_48[0];
        }
        puVar9 = puVar8;
        puVar17 = puVar18;
        if ((uVar16 == *param_1 >> 1) &&
           (((uint)uVar16 + (uint)uVar15 == (uint)(*param_3 >> 1) ||
            (*(short *)(*(longlong *)(param_3 + 4) + (ulonglong)((uint)uVar16 + (uint)uVar15) * 2)
             == 0x5c)))) {
          puVar9 = puVar8 + -0x10;
          puVar17 = (ushort *)(puVar8 + 0x10);
          *(ushort **)(puVar8 + 0x18) = puVar18;
          uVar12 = uVar12 + 1;
          *puVar17 = uVar15;
          local_48[0] = uVar12;
          *(ushort *)(puVar8 + 0x12) = uVar16 + uVar15;
        }
        uVar16 = *param_3;
        uVar15 = uVar15 + 1;
        puVar8 = puVar9;
        puVar18 = puVar17;
      } while (uVar15 < uVar16 >> 1);
      param_2 = local_40;
    }
    iVar10 = 0;
    puVar8 = puVar9;
    if (puVar17 != (ushort *)0x0) {
      if ((*param_1 < *param_2) &&
         ((uint)param_3[1] < ((uint)*param_2 - (uint)*param_1) * (uint)uVar12 + (uint)uVar16)) {
        uVar5 = 0x80000005;
        goto LAB_14001a42e;
      }
      iVar13 = (param_3[1] >> 1) - 1;
      uVar11 = (uint)(uVar16 >> 1);
      while (uVar11 = uVar11 - 1, -1 < (int)uVar11) {
        if ((puVar17 == (ushort *)0x0) || ((int)(uint)puVar17[1] <= (int)uVar11)) {
          lVar7 = (longlong)iVar13;
          iVar13 = iVar13 + -1;
          *(undefined2 *)(*(longlong *)(param_3 + 4) + lVar7 * 2) =
               *(undefined2 *)(*(longlong *)(param_3 + 4) + (longlong)(int)uVar11 * 2);
        }
        else {
          uVar16 = *param_2;
          uVar14 = 0;
          if ((uVar16 & 0xfffe) != 0) {
            do {
              uVar12 = (short)uVar14 + 1;
              lVar7 = (longlong)iVar13;
              iVar13 = iVar13 + -1;
              *(undefined2 *)(*(longlong *)(param_3 + 4) + lVar7 * 2) =
                   *(undefined2 *)(*(longlong *)(param_2 + 4) + -2 + ((uVar16 >> 1) - uVar14) * 2);
              uVar16 = *param_2;
              uVar14 = (ulonglong)uVar12;
            } while (uVar12 < uVar16 >> 1);
          }
          uVar11 = (uint)*puVar17;
          puVar17 = *(ushort **)(puVar17 + 4);
        }
      }
      iVar13 = iVar13 + 1;
      if (iVar13 < (int)(uint)(param_3[1] >> 1)) {
        lVar7 = (longlong)iVar13 * 2;
        do {
          iVar13 = iVar13 + 1;
          lVar6 = (longlong)iVar10;
          iVar10 = iVar10 + 1;
          puVar1 = (undefined2 *)(lVar7 + *(longlong *)(param_3 + 4));
          lVar7 = lVar7 + 2;
          *(undefined2 *)(*(longlong *)(param_3 + 4) + lVar6 * 2) = *puVar1;
        } while (iVar13 < (int)(uint)(param_3[1] >> 1));
      }
      *param_3 = (short)iVar10 * 2;
    }
  }
  uVar5 = 0;
LAB_14001a42e:
  *(undefined8 *)(puVar8 + -8) = 0x14001a43a;
  return uVar5;
}



===== Wow64SelectWowNodePathInternal @ 14001a45c =====

undefined * Wow64SelectWowNodePathInternal(short param_1)

{
  if (param_1 == 0x14c) {
    return &Wowx86NodeString;
  }
  if (param_1 == 0x1c4) {
    return &WowArmNodeString;
  }
  return (undefined *)0x0;
}



===== BasepGetFileNameInformation @ 14001a488 =====

undefined8 BasepGetFileNameInformation(undefined8 param_1,undefined4 param_2,undefined8 *param_3)

{
  ushort uVar1;
  int iVar2;
  ushort *_Dst;
  undefined8 uVar3;
  int iVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  
  _Dst = (ushort *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  iVar4 = 0x210;
  do {
    if (_Dst != (ushort *)0x0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,_Dst);
    }
    _Dst = (ushort *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                           KernelBaseGlobalData,iVar4);
    if (_Dst == (ushort *)0x0) goto LAB_14001a55e;
    iVar2 = NtQueryInformationFile(param_1,&local_28,_Dst,iVar4,param_2);
    iVar4 = *(int *)_Dst + 8;
  } while (iVar2 == -0x7ffffffb);
  if (iVar2 < 0) {
LAB_14001a55e:
    BaseSetLastNTError();
    if (_Dst != (ushort *)0x0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,_Dst);
    }
    uVar3 = 0;
  }
  else {
    uVar1 = *_Dst;
    memmove(_Dst,_Dst + 2,(ulonglong)uVar1);
    uVar3 = 1;
    *param_3 = _Dst;
    _Dst[uVar1 >> 1] = 0;
  }
  return uVar3;
}



===== BasepGetObjectNTName @ 14001a5ac =====

undefined8 BasepGetObjectNTName(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  ushort *_Dst;
  undefined8 uVar2;
  uint uVar3;
  uint local_res18 [2];
  
  _Dst = (ushort *)0x0;
  local_res18[0] = 0;
  iVar1 = -0x7ffffffb;
  uVar3 = 0x218;
  while (iVar1 == -0x7ffffffb) {
    if (_Dst != (ushort *)0x0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,_Dst);
    }
    _Dst = (ushort *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                           KernelBaseGlobalData,uVar3);
    if (_Dst == (ushort *)0x0) goto LAB_14001a667;
    iVar1 = NtQueryObject(param_1,1,_Dst,uVar3,local_res18);
    uVar3 = local_res18[0];
  }
  if (iVar1 < 0) {
LAB_14001a667:
    BaseSetLastNTError();
    if (_Dst != (ushort *)0x0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,_Dst);
    }
    uVar2 = 0;
  }
  else {
    local_res18[0] = (uint)*_Dst;
    memmove(_Dst,*(void **)(_Dst + 4),(ulonglong)local_res18[0]);
    uVar2 = 1;
    *param_2 = _Dst;
    _Dst[local_res18[0] >> 1] = 0;
  }
  return uVar2;
}



===== BasepGetVolumeDosLetterNameFromNTName @ 14001a6e0 =====

BOOL BasepGetVolumeDosLetterNameFromNTName(wchar_t *param_1,undefined8 *param_2)

{
  uint *lpOutBuffer;
  uint uVar1;
  ushort uVar2;
  BOOL BVar3;
  undefined8 *puVar4;
  HANDLE hDevice;
  size_t sVar5;
  ushort *lpInBuffer;
  int iVar6;
  DWORD nInBufferSize;
  DWORD local_res18 [2];
  LPOVERLAPPED in_stack_ffffffffffffffc0;
  undefined8 local_38;
  short *psStack_30;
  
  puVar4 = (undefined8 *)0x0;
  local_38 = 0;
  psStack_30 = (short *)0x0;
  local_res18[0] = _wcsnicmp(param_1,L"\\Device\\MUP",0xb);
  if (local_res18[0] == 0) {
    puVar4 = (undefined8 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                             KernelBaseGlobalData,0x10);
    *param_2 = puVar4;
    if (puVar4 != (undefined8 *)0x0) {
      *puVar4 = 0x5c003f005c005c;
      *(undefined4 *)(puVar4 + 1) = 0x4e0055;
      *(undefined2 *)((longlong)puVar4 + 0xc) = 0x43;
      *(undefined2 *)((longlong)puVar4 + 0xe) = 0;
      return 1;
    }
    RtlSetLastWin32Error(8);
  }
  else {
    hDevice = CreateFileW(L"\\\\.\\MountPointManager",0,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                          (HANDLE)0x0);
    if (hDevice != (HANDLE)0xffffffffffffffff) {
      sVar5 = wcslen(param_1);
      nInBufferSize = (int)sVar5 * 2 + 4;
      lpInBuffer = (ushort *)
                   RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                   KernelBaseGlobalData,nInBufferSize);
      if (lpInBuffer == (ushort *)0x0) {
LAB_14001aa11:
        RtlSetLastWin32Error(8);
LAB_14001aa22:
        BVar3 = 0;
      }
      else {
        sVar5 = wcslen(param_1);
        uVar2 = (short)sVar5 * 2;
        *lpInBuffer = uVar2;
        memcpy(lpInBuffer + 1,param_1,(ulonglong)uVar2);
        iVar6 = 0x218;
        do {
          if (puVar4 != (undefined8 *)0x0) {
            RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
          }
          puVar4 = (undefined8 *)
                   RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                   KernelBaseGlobalData,iVar6);
          if (puVar4 == (undefined8 *)0x0) goto LAB_14001aa11;
          lpOutBuffer = (uint *)(puVar4 + 1);
          BVar3 = DeviceIoControl(hDevice,0x6d0030,lpInBuffer,nInBufferSize,lpOutBuffer,iVar6 - 8,
                                  local_res18,in_stack_ffffffffffffffc0);
          iVar6 = *lpOutBuffer + 0x10;
          if (BVar3 != 0) {
            RtlInitUnicodeString(&local_38,(longlong)puVar4 + 0xc);
            if (((((short)local_38 == 0x60) ||
                 (((short)local_38 == 0x62 && (psStack_30[0x30] == 0x5c)))) &&
                ((*psStack_30 == 0x5c &&
                 (((psStack_30[1] == 0x3f || (psStack_30[1] == 0x5c)) && (psStack_30[2] == 0x3f)))))
                ) && (((((psStack_30[3] == 0x5c && (psStack_30[4] == 0x56)) &&
                        ((psStack_30[5] == 0x6f &&
                         ((psStack_30[6] == 0x6c && (psStack_30[7] == 0x75)))))) &&
                       (psStack_30[8] == 0x6d)) &&
                      (((((psStack_30[9] == 0x65 && (psStack_30[10] == 0x7b)) &&
                         (psStack_30[0x13] == 0x2d)) &&
                        ((psStack_30[0x18] == 0x2d && (psStack_30[0x1d] == 0x2d)))) &&
                       ((psStack_30[0x22] == 0x2d && (psStack_30[0x2f] == 0x7d)))))))) {
              RtlSetLastWin32Error(3);
              goto LAB_14001aa22;
            }
            uVar1 = *lpOutBuffer;
            *param_2 = puVar4;
            *puVar4 = 0x5c003f005c005c;
            memmove(lpOutBuffer,(void *)((longlong)puVar4 + 0xc),(ulonglong)uVar1);
            *(undefined2 *)((longlong)puVar4 + (ulonglong)(uVar1 >> 1) * 2 + 8) = 0;
            goto LAB_14001a90a;
          }
        } while (LastErrorValue == 0xea);
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
LAB_14001a90a:
        puVar4 = (undefined8 *)0x0;
      }
      CloseHandle(hDevice);
      if (puVar4 != (undefined8 *)0x0) {
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar4);
      }
      if (lpInBuffer == (ushort *)0x0) {
        return BVar3;
      }
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lpInBuffer);
      return BVar3;
    }
  }
  return 0;
}



===== BasepGetVolumeGUIDFromNTName @ 14001aa9c =====

BOOL BasepGetVolumeGUIDFromNTName(wchar_t *param_1,undefined8 *param_2)

{
  ushort uVar1;
  BOOL BVar2;
  HANDLE hDevice;
  size_t sVar3;
  undefined8 *lpInBuffer;
  int *lpOutBuffer;
  ulonglong uVar4;
  void *_Dst;
  DWORD nOutBufferSize;
  short *_Src;
  uint uVar5;
  ulonglong uVar6;
  DWORD nInBufferSize;
  DWORD local_res18 [2];
  LPOVERLAPPED in_stack_ffffffffffffffd0;
  
  local_res18[0] = 0;
  lpOutBuffer = (int *)0x0;
  hDevice = CreateFileW(L"\\\\.\\MountPointManager",0,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                        (HANDLE)0x0);
  if (hDevice == (HANDLE)0xffffffffffffffff) {
    return 0;
  }
  sVar3 = wcslen(param_1);
  nInBufferSize = (int)sVar3 * 2 + 0x18;
  lpInBuffer = (undefined8 *)
               RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                               KernelBaseGlobalData,nInBufferSize);
  if (lpInBuffer == (undefined8 *)0x0) {
LAB_14001adb4:
    RtlSetLastWin32Error(8);
LAB_14001adc5:
    BVar2 = 0;
  }
  else {
    *lpInBuffer = 0;
    lpInBuffer[1] = 0;
    lpInBuffer[2] = 0;
    *(undefined4 *)(lpInBuffer + 2) = 0x18;
    sVar3 = wcslen(param_1);
    uVar1 = (short)sVar3 * 2;
    *(ushort *)((longlong)lpInBuffer + 0x14) = uVar1;
    memcpy(lpInBuffer + 3,param_1,(ulonglong)uVar1);
    nOutBufferSize = 0x2a0;
    do {
      if (lpOutBuffer != (int *)0x0) {
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lpOutBuffer);
      }
      lpOutBuffer = (int *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30)
                                           ,KernelBaseGlobalData,nOutBufferSize);
      if (lpOutBuffer == (int *)0x0) goto LAB_14001adb4;
      BVar2 = DeviceIoControl(hDevice,0x6d0008,lpInBuffer,nInBufferSize,lpOutBuffer,nOutBufferSize,
                              local_res18,in_stack_ffffffffffffffd0);
      nOutBufferSize = *lpOutBuffer + 0x20;
      if (BVar2 != 0) {
        uVar6 = 0;
        if (lpOutBuffer[1] == 0) goto LAB_14001ad12;
        uVar4 = 0;
        goto LAB_14001ac5f;
      }
    } while (LastErrorValue == 0xea);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lpOutBuffer);
LAB_14001ac39:
    lpOutBuffer = (int *)0x0;
  }
  goto LAB_14001adc8;
  while( true ) {
    uVar5 = (int)uVar6 + 1;
    uVar6 = (ulonglong)uVar5;
    uVar4 = (ulonglong)uVar5;
    if ((uint)lpOutBuffer[1] <= uVar5) break;
LAB_14001ac5f:
    uVar1 = *(ushort *)(lpOutBuffer + uVar4 * 6 + 3);
    _Src = (short *)((ulonglong)(uint)lpOutBuffer[uVar6 * 6 + 2] + (longlong)lpOutBuffer);
    if ((((uVar1 == 0x60) || ((uVar1 == 0x62 && (_Src[0x30] == 0x5c)))) &&
        ((*_Src == 0x5c && (((_Src[1] == 0x3f || (_Src[1] == 0x5c)) && (_Src[2] == 0x3f)))))) &&
       (((((_Src[3] == 0x5c && (_Src[4] == 0x56)) &&
          ((_Src[5] == 0x6f && ((_Src[6] == 0x6c && (_Src[7] == 0x75)))))) && (_Src[8] == 0x6d)) &&
        (((((_Src[9] == 0x65 && (_Src[10] == 0x7b)) && (_Src[0x13] == 0x2d)) &&
          ((_Src[0x18] == 0x2d && (_Src[0x1d] == 0x2d)))) &&
         ((_Src[0x22] == 0x2d && (_Src[0x2f] == 0x7d)))))))) {
      _Dst = (void *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                     KernelBaseGlobalData,(ulonglong)uVar1 + 2);
      *param_2 = _Dst;
      if (_Dst != (void *)0x0) {
        memcpy(_Dst,_Src,(ulonglong)uVar1);
        *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar1 >> 1) * 2) = 0;
        *(undefined2 *)((longlong)_Dst + 2) = 0x5c;
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lpOutBuffer);
        goto LAB_14001ac39;
      }
      RtlSetLastWin32Error(8);
      goto LAB_14001adc5;
    }
  }
LAB_14001ad12:
  RtlSetLastWin32Error(0x32);
LAB_14001adc8:
  CloseHandle(hDevice);
  if (lpInBuffer != (undefined8 *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lpInBuffer);
  }
  if (lpOutBuffer != (int *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lpOutBuffer);
  }
  return BVar2;
}



===== DeviceIoControl @ 14001ae40 =====

BOOL __stdcall
DeviceIoControl(HANDLE hDevice,DWORD dwIoControlCode,LPVOID lpInBuffer,DWORD nInBufferSize,
               LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesReturned,
               LPOVERLAPPED lpOverlapped)

{
  uint uVar1;
  BOOL BVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  if ((dwIoControlCode & 0xffff0000) == 0x90000) {
    uVar1 = NtFsControlFile(0,0,0,0,&local_18,dwIoControlCode,lpInBuffer,nInBufferSize,lpOutBuffer,
                            nOutBufferSize);
  }
  else {
    uVar1 = NtDeviceIoControlFile(0,0,0,0);
  }
  if (uVar1 == 0x103) {
    uVar1 = NtWaitForSingleObject(hDevice,0,0);
    if (-1 < (int)uVar1) {
      uVar1 = (uint)local_18;
    }
  }
  if ((int)uVar1 < 0) {
    if (((uVar1 & 0xc0000000) != 0xc0000000) && (lpBytesReturned != (LPDWORD)0x0)) {
      *lpBytesReturned = (DWORD)uStack_10;
    }
    BaseSetLastNTError();
    BVar2 = 0;
  }
  else {
    if (lpBytesReturned != (LPDWORD)0x0) {
      *lpBytesReturned = (DWORD)uStack_10;
    }
    BVar2 = 1;
  }
  return BVar2;
}



===== GetFinalPathNameByHandleW @ 14001af30 =====

DWORD __stdcall
GetFinalPathNameByHandleW(HANDLE hFile,LPWSTR lpszFilePath,DWORD cchFilePath,DWORD dwFlags)

{
  wchar_t *_Str;
  ushort uVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  undefined8 uVar5;
  size_t sVar6;
  size_t sVar7;
  STRSAFE_LPWSTR pszDest;
  ushort uVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  ulonglong cchDest;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  STRSAFE_LPWSTR local_res8;
  LPWSTR local_res10;
  DWORD local_res18;
  DWORD local_res20;
  wchar_t *local_68;
  wchar_t *local_60;
  wchar_t *local_58;
  STRSAFE_LPWSTR local_50 [2];
  
  local_60 = (wchar_t *)0x0;
  local_res8 = (STRSAFE_LPWSTR)0x0;
  uVar12 = 0;
  local_58 = (wchar_t *)0x0;
  local_res10 = lpszFilePath;
  local_res18 = cchFilePath;
  local_res20 = dwFlags;
  if (hFile == (HANDLE)0xffffffffffffffff) {
    uVar5 = 6;
LAB_14001af71:
    RtlSetLastWin32Error(uVar5);
    return 0;
  }
  uVar11 = dwFlags & 1;
  uVar1 = (ushort)uVar11;
  if ((dwFlags & 2) != 0) {
    uVar11 = 2;
  }
  uVar8 = uVar1 + 1;
  if ((dwFlags & 2) == 0) {
    uVar8 = uVar1;
  }
  uVar1 = uVar8 + 1;
  if ((dwFlags & 4) == 0) {
    uVar1 = uVar8;
  }
  if (1 < uVar1) {
    uVar5 = 0x57;
    goto LAB_14001af71;
  }
  uVar13 = 0;
  if ((dwFlags & 4) == 0) {
    uVar13 = uVar11;
  }
  if (uVar1 == 0) {
    uVar13 = 3;
  }
  uVar5 = BasepGetObjectNTName(hFile,&local_58);
  if (((int)uVar5 == 0) ||
     (uVar5 = BasepGetFileNameInformation(hFile,9,&local_res8), (int)uVar5 == 0))
  goto LAB_14001b47a;
  if (*local_res8 == L'\\') {
    sVar6 = wcslen(local_58);
    sVar7 = wcslen(local_res8);
    pwVar9 = local_58;
    if (sVar7 < sVar6) {
      sVar6 = wcslen(local_58);
      sVar7 = wcslen(local_res8);
      pwVar9[sVar6 - sVar7] = L'\0';
      if (uVar13 == 1) {
        BVar2 = BasepGetVolumeGUIDFromNTName(local_58,&local_60);
        if (BVar2 == 0) {
          if (LastErrorValue != 1) goto LAB_14001b47a;
          uVar5 = 3;
          goto LAB_14001b012;
        }
      }
      else if (uVar13 == 2) {
        local_60 = local_58;
        local_58 = (wchar_t *)0x0;
      }
      else if ((uVar13 == 3) &&
              (BVar2 = BasepGetVolumeDosLetterNameFromNTName(pwVar9,&local_60), BVar2 == 0))
      goto LAB_14001b47a;
      if ((local_res20 & 8) == 0) {
        local_50[0] = (STRSAFE_LPWSTR)0x0;
        local_68 = (wchar_t *)0x0;
        uVar5 = BasepGetFileNameInformation(hFile,0x30,local_50);
        if ((int)uVar5 == 0) {
          if (((LastErrorValue != 0x57) && (LastErrorValue != 0x7c)) && (LastErrorValue != 0x32))
          goto LAB_14001b47a;
          if ((uVar13 & 0xfffffffd) == 0) {
            pwVar9 = local_60;
            if (local_58 != (wchar_t *)0x0) {
              pwVar9 = local_58;
            }
            BVar2 = BasepGetVolumeDosLetterNameFromNTName(pwVar9,&local_68);
            if ((BVar2 == 0) && (LastErrorValue == 8)) goto LAB_14001b47a;
            pwVar9 = local_68;
            if (local_68 == (wchar_t *)0x0) {
              pwVar9 = local_60;
              if (local_58 != (wchar_t *)0x0) {
                pwVar9 = local_58;
              }
              BVar2 = BasepGetVolumeGUIDFromNTName(pwVar9,&local_68);
              if (BVar2 == 0) goto LAB_14001b47a;
              pwVar9 = local_68;
              if (local_68 == (wchar_t *)0x0) goto LAB_14001b1b7;
            }
          }
          else {
LAB_14001b1b7:
            pwVar9 = local_60;
          }
          sVar6 = wcslen(pwVar9);
          sVar7 = wcslen(local_res8);
          uVar11 = ((int)sVar7 + (int)sVar6 + local_res18) * 2 + 2;
          pszDest = (STRSAFE_LPWSTR)
                    RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                    KernelBaseGlobalData,uVar11);
          _Str = local_60;
          pwVar9 = local_68;
          local_50[0] = pszDest;
          if (pszDest == (STRSAFE_LPWSTR)0x0) {
            if (local_68 != (wchar_t *)0x0) {
              RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_68);
            }
            uVar5 = 8;
            goto LAB_14001b012;
          }
          pwVar10 = local_60;
          if (local_68 != (wchar_t *)0x0) {
            pwVar10 = local_68;
          }
          StringCchCopyW(pszDest,(ulonglong)(uVar11 >> 1),pwVar10);
          StringCchCatW(pszDest,(ulonglong)(uVar11 >> 1),local_res8);
          DVar3 = GetLongPathNameW(pszDest,pszDest,uVar11 >> 1);
          if (DVar3 == 0) {
            RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_50[0]);
            if (local_68 != (wchar_t *)0x0) {
              RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_68);
            }
            goto LAB_14001b47a;
          }
          if (uVar11 >> 1 <= DVar3) {
            if (pwVar9 != (wchar_t *)0x0) {
              sVar6 = wcslen(pwVar9);
              iVar4 = 0;
              if (_Str != (wchar_t *)0x0) {
                sVar7 = wcslen(_Str);
                iVar4 = (int)sVar7;
              }
              DVar3 = (DVar3 - (int)sVar6) + iVar4;
              RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_68);
            }
            uVar12 = DVar3 + 1;
            RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_50[0]);
            uVar5 = 0;
            goto LAB_14001b050;
          }
          pwVar10 = pwVar9;
          if (pwVar9 == (wchar_t *)0x0) {
            pwVar10 = _Str;
          }
          sVar6 = wcslen(pwVar10);
          sVar7 = wcslen(pszDest);
          memmove(pszDest,pszDest + (sVar6 & 0xffffffff),(sVar7 + (1 - (sVar6 & 0xffffffff))) * 2);
          if (pwVar9 != (wchar_t *)0x0) {
            RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_68);
          }
          RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_res8);
          lpszFilePath = local_res10;
        }
        else {
          RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_res8);
        }
        local_res8 = local_50[0];
      }
      iVar4 = 0;
      if (local_60 != (wchar_t *)0x0) {
        sVar6 = wcslen(local_60);
        iVar4 = (int)sVar6;
      }
      sVar6 = wcslen(local_res8);
      cchDest = (ulonglong)local_res18;
      uVar11 = iVar4 + (int)sVar6;
      uVar12 = uVar11 + 1;
      if (uVar12 <= local_res18) {
        *lpszFilePath = L'\0';
        if (local_60 != (STRSAFE_LPCWSTR)0x0) {
          StringCchCopyW(lpszFilePath,cchDest,local_60);
        }
        StringCchCatW(lpszFilePath,cchDest,local_res8);
        uVar12 = uVar11;
        goto LAB_14001b47a;
      }
      uVar5 = 8;
    }
    else {
      uVar5 = 0xa1;
    }
LAB_14001b050:
    RtlSetLastWin32Error(uVar5);
  }
  else {
    uVar5 = 5;
LAB_14001b012:
    RtlSetLastWin32Error(uVar5);
  }
LAB_14001b47a:
  if (local_58 != (wchar_t *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_58);
  }
  if (local_res8 != (STRSAFE_LPWSTR)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_res8);
  }
  if (local_60 == (wchar_t *)0x0) {
    return uVar12;
  }
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_60);
  return uVar12;
}



===== StringCchCatW @ 14001b504 =====

HRESULT __stdcall StringCchCatW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc)

{
  STRSAFE_LPWSTR pwVar1;
  uint uVar2;
  size_t *pcchNewDestLength;
  size_t sVar3;
  size_t in_stack_ffffffffffffffe8;
  
  if (cchDest - 1 < 0x7fffffff) {
    pwVar1 = pszDest;
    sVar3 = cchDest;
    do {
      if (*pwVar1 == L'\0') break;
      pwVar1 = pwVar1 + 1;
      sVar3 = sVar3 - 1;
    } while (sVar3 != 0);
    uVar2 = ~-(uint)(sVar3 != 0) & 0x80070057;
    pcchNewDestLength = (size_t *)(-(ulonglong)(sVar3 != 0) & cchDest - sVar3);
    if (sVar3 != 0) {
      uVar2 = StringCopyWorkerW(pszDest + (longlong)pcchNewDestLength,
                                cchDest - (longlong)pcchNewDestLength,pcchNewDestLength,pszSrc,
                                in_stack_ffffffffffffffe8);
    }
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



===== StringCchCopyW @ 14001b590 =====

HRESULT __stdcall StringCchCopyW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc)

{
  HRESULT HVar1;
  size_t in_stack_ffffffffffffffe8;
  
  if (cchDest - 1 < 0x7fffffff) {
    HVar1 = StringCopyWorkerW(pszDest,cchDest,(size_t *)pszSrc,pszSrc,in_stack_ffffffffffffffe8);
  }
  else {
    HVar1 = -0x7ff8ffa9;
    if (cchDest != 0) {
      *pszDest = L'\0';
    }
  }
  return HVar1;
}



===== StringCopyWorkerW @ 14001b5c8 =====

HRESULT __stdcall
StringCopyWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t *pcchNewDestLength,
                 STRSAFE_PCNZWCH pszSrc,size_t cchToCopy)

{
  wchar_t wVar1;
  longlong lVar2;
  STRSAFE_LPWSTR pwVar3;
  longlong lVar4;
  
  if (cchDest != 0) {
    lVar2 = 0x7ffffffe;
    lVar4 = (longlong)pszSrc - (longlong)pszDest;
    do {
      if ((lVar2 == 0) || (wVar1 = *(wchar_t *)(lVar4 + (longlong)pszDest), wVar1 == L'\0')) break;
      *pszDest = wVar1;
      lVar2 = lVar2 + -1;
      pszDest = pszDest + 1;
      cchDest = cchDest - 1;
    } while (cchDest != 0);
  }
  pwVar3 = pszDest + -1;
  if (cchDest != 0) {
    pwVar3 = pszDest;
  }
  *pwVar3 = L'\0';
  return ~-(uint)(cchDest != 0) & 0x8007007a;
}



===== Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline @ 14001b624 =====

uint Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline(void)

{
  uint uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)
               (ulonglong)Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState;
  if ((Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState & 0x10) == 0) {
    uVar1 = wil_details_IsEnabledFallback(local_res8,3);
    return uVar1;
  }
  return Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState & 1;
}



===== InternalGetFileAttributesW @ 14001b660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong InternalGetFileAttributesW(undefined8 param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_98;
  local_4c = 0;
  local_64 = 0;
  local_18 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar2 = RtlDosPathNameToNtPathName_U_WithStatus(0,&local_78,0,0);
  uVar1 = uStack_70;
  if (iVar2 < 0) {
    if ((iVar2 != -0x3fffffe9) && (iVar2 != -0x3fffff66)) {
      RtlSetLastWin32Error(3);
      return 0xffffffff;
    }
  }
  else {
    local_58 = &local_78;
    local_60 = 0;
    local_68 = 0x30;
    local_48 = 0;
    uStack_40 = 0;
    local_50 = 0x40;
    iVar2 = NtQueryAttributesFile(&local_68,&local_38);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,uVar1);
    if (-1 < iVar2) {
      return local_18 & 0xffffffff;
    }
    iVar2 = RtlIsDosDeviceName_U(param_1);
    if (iVar2 != 0) {
      return 0x20;
    }
  }
  BaseSetLastNTError();
  return 0xffffffff;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14001b7a8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_68 [48];
  undefined8 local_38;
  undefined8 local_30;
  uint local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  if ((g_wil_details_pfnRtlQueryFeatureConfiguration == (code *)0x0) &&
     (g_wil_details_pfnRtlQueryFeatureConfiguration =
           (code *)wil_details_GetNtDllProcedureAddress((LPCWSTR)"RtlQueryFeatureConfiguration"),
     g_wil_details_pfnRtlQueryFeatureConfiguration == (code *)0x0)) {
    return 0;
  }
  iVar1 = (*g_wil_details_pfnRtlQueryFeatureConfiguration)(param_2,param_3 == 0,&local_38,&local_30)
  ;
  if (iVar1 == 0) {
    uVar2 = 1;
    *param_1 = local_30._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_30 >> 0x28) & 0x3f;
    param_1[3] = local_28;
    param_1[2] = local_30._4_4_ >> 0xe & 3;
    param_1[5] = local_30._4_4_ >> 6 & 1;
    param_1[4] = local_30._4_4_ >> 7 & 1;
  }
  else if (iVar1 == 0x117) {
    uVar2 = 1;
    param_1[4] = local_30._4_4_ >> 7 & 1;
  }
  return uVar2;
}



===== wil_RtlStagingConfig_RecordFeatureUsage @ 14001b8a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8
wil_RtlStagingConfig_RecordFeatureUsage(undefined4 param_1,undefined2 param_2,int param_3)

{
  uint6 uVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  local_res20._0_6_ = CONCAT24(param_2,param_1);
  uVar1 = (uint6)local_res20;
  local_res20 = (ulonglong)(uint6)local_res20;
  if (param_3 != 0) {
    local_res20 = CONCAT26(1,uVar1);
  }
  if ((g_wil_details_pfnRtlNotifyFeatureUsage == (code *)0x0) &&
     (g_wil_details_pfnRtlNotifyFeatureUsage =
           (code *)wil_details_GetNtDllProcedureAddress((LPCWSTR)"RtlNotifyFeatureUsage"),
     g_wil_details_pfnRtlNotifyFeatureUsage == (code *)0x0)) {
    return 0xc0000139;
  }
  uVar2 = (*g_wil_details_pfnRtlNotifyFeatureUsage)(&local_res20);
  return uVar2;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14001b900 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14001b9d8 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14001babc =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_14001bc14:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14001bc07:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_14001bc14;
      if (uVar5 == 5) goto LAB_14001bc07;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 14001bc3c =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x295e137,&Feature_Servicing_CD_PathRedirectionAPI_2503_logged_traits,0,uVar4,
               local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14001bcb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint *puVar1;
  undefined1 auStack_78 [48];
  uint local_48 [10];
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  puVar1 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_48,(uint *)&
                                       Feature_Servicing_CD_PathRedirectionAPI_2503__private_reporting
                      ,param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_20 = *(undefined8 *)(puVar1 + 4);
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    wil_RtlStagingConfig_RecordFeatureUsage(0x295e137,(short)param_3,(uint)param_2 >> 0xb & 1);
  }
  return (int)local_20 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14001bd48 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14001be58 =====

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
  if ((Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState & 2) != 0) {
    uVar1 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState;
      if (bVar3) {
        Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 14001beac =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong *plVar7;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar4 = wil_RtlStagingConfig_QueryFeatureState
                    (local_28,*(undefined4 *)(param_1 + 0x18),(uint)((byte)(cVar1 - 2U) < 2));
  uVar3 = -(uint)((int)uVar4 != 0) & local_28[0] & 3;
  if (uVar3 == 0) {
    uVar6 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar6 = 0;
    if (local_28[0] == 2) {
      uVar6 = 0x40;
    }
  }
  local_res8 = uVar6 >> 6 ^
               (uVar3 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar6);
  if ((uVar6 != 0) && (plVar7 = *(longlong **)(param_1 + 0x20), plVar7 != (longlong *)0x0)) {
    do {
      puVar2 = (undefined8 *)*plVar7;
      if (puVar2 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar2 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar2 + 0x1d) == '\0')) {
        uVar6 = *(uint *)*puVar2;
        local_res10 = (ulonglong)uVar6;
        if ((uVar6 & 2) == 0) {
          uVar5 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar2,local_res10,(longlong)puVar2);
          uVar6 = (uint)uVar5;
        }
        uVar3 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar6 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar2 + 0x1f) == '\0')) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar3;
      plVar7 = plVar7 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_GetNtDllProcedureAddress @ 14001c008 =====

void wil_details_GetNtDllProcedureAddress(LPCWSTR param_1)

{
  undefined8 unaff_retaddr;
  
  if (`wil_details_GetNtDllModuleHandle'::__l2::wil_details_ntdllModuleHandle == (HMODULE)0x0) {
    `wil_details_GetNtDllModuleHandle'::__l2::wil_details_ntdllModuleHandle =
         GetModuleHandleW(param_1);
  }
  GetProcAddressForCaller
            ((ulonglong)`wil_details_GetNtDllModuleHandle'::__l2::wil_details_ntdllModuleHandle,
             (ulonglong)param_1,unaff_retaddr);
  return;
}



===== wil_details_IsEnabledFallback @ 14001c044 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_Servicing_CD_PathRedirectionAPI_2503__private_featureState,
                             (ulonglong)param_1,0x14002db80);
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



===== wil_details_MapReportingKind @ 14001c0d4 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== CreateFile2 @ 14001c174 =====

void CreateFile2(longlong param_1)

{
  uint *in_stack_00000028;
  
  CreateFileInternal(param_1,0x80000000,1,3,in_stack_00000028,2);
  return;
}



===== _guard_check_icall @ 14001c1b0 =====

void _guard_check_icall(void)

{
  return;
}



===== CreateFileDowngrade_Win7 @ 14001c1c0 =====

void CreateFileDowngrade_Win7(uint *param_1)

{
  *param_1 = *param_1 | 0x20000;
  return;
}



===== CreateFileInternal @ 14001c1cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

HANDLE CreateFileInternal(longlong param_1,uint param_2,uint param_3,int param_4,uint *param_5,
                         uint param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  code *pcVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  short *psVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  bool bVar14;
  undefined1 auStack_178 [32];
  ulonglong local_158;
  undefined8 local_150;
  uint local_148;
  undefined8 local_140;
  uint local_138;
  longlong local_130;
  undefined4 local_128;
  uint local_118;
  int local_114;
  uint local_110;
  HANDLE local_108;
  uint local_100;
  int local_fc;
  int local_f8 [2];
  short *local_f0;
  uint local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  longlong lStack_d0;
  int local_c8 [2];
  undefined8 local_c0;
  short *psStack_b8;
  undefined8 local_b0;
  longlong local_a8;
  undefined8 local_a0;
  short *psStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_178;
  local_60 = 0;
  local_58 = (undefined8 *)((ulonglong)local_58 & 0xffffffff00000000);
  local_50 = 0;
  local_48 = 0;
  local_118 = 0;
  local_b0 = 0;
  local_c8[0] = 0;
  local_108 = (HANDLE)0xffffffffffffffff;
  local_a8 = -1;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = (undefined8 *)0x0;
  uStack_68 = 0;
  local_c0 = 0;
  psStack_b8 = (short *)0x0;
  local_d8 = 0;
  lStack_d0 = 0;
  local_a0 = 0;
  psStack_98 = (short *)0x0;
  local_90 = 0;
  uStack_88 = 0;
  local_110 = param_2;
  local_e8 = param_3;
  local_e0 = param_1;
  if (param_5 == (uint *)0x0) {
    uVar3 = 0;
    uVar4 = 0;
    uVar12 = 0;
  }
  else {
    if (*param_5 < 0x20) goto LAB_14001c2f5;
    uVar3 = param_5[2];
    uVar4 = param_5[1];
    uVar12 = param_5[3];
  }
  if ((param_6 & 3) == 0) {
    bVar10 = (byte)(uVar3 >> 0x10) & 1;
  }
  else {
    bVar10 = 0;
  }
  uVar1 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline();
  lVar5 = local_e0;
  if (((uVar1 != 0) && (bVar10 != 0)) && ((local_110 == 0 || ((local_e8 & 4) != 0)))) {
    uVar8 = 0xa0;
    goto LAB_14001c2b5;
  }
  if (param_4 == 1) {
    local_114 = 2;
    iVar2 = local_114;
  }
  else if (param_4 == 2) {
    local_114 = 5;
    iVar2 = local_114;
  }
  else if (param_4 == 3) {
    local_114 = 1;
    iVar2 = local_114;
  }
  else if (param_4 == 4) {
    local_114 = 3;
    iVar2 = local_114;
  }
  else {
    if (param_4 != 5) goto LAB_14001c2f5;
    local_114 = 1;
    iVar2 = 1;
    if ((local_110 >> 0x1e & 1) == 0) goto LAB_14001c2f5;
  }
  local_114 = iVar2;
  iVar2 = RtlInitUnicodeStringEx(&local_c0,local_e0);
  if (iVar2 < 0) {
LAB_14001c2f5:
    BaseSetLastNTError();
    return (HANDLE)0xffffffffffffffff;
  }
  if (((ushort)local_c0 < 2) ||
     (local_fc = 1, *(short *)(lVar5 + -2 + (ulonglong)((ushort)local_c0 >> 1) * 2) != 0x5c)) {
    local_fc = 0;
  }
  local_118 = 0;
  iVar2 = RtlDosPathNameToRelativeNtPathName_U_WithStatus(lVar5,&local_c0,0,&local_a0);
  if (iVar2 < 0) {
    if ((iVar2 != -0x3fffffe9) && (iVar2 != -0x3fffff66)) {
      uVar8 = 3;
      goto LAB_14001c2b5;
    }
    goto LAB_14001c2f5;
  }
  local_f0 = psStack_b8;
  if ((short)local_a0 == 0) {
    local_90 = 0;
  }
  else {
    local_c0 = local_a0;
    psStack_b8 = psStack_98;
  }
  uVar1 = uVar3 >> 6 & 0x800;
  local_80 = CONCAT44(local_80._4_4_,0x30);
  local_60 = 0;
  local_100 = uVar3 & 0x1000000;
  local_70 = &local_c0;
  uStack_68 = CONCAT44(uStack_68._4_4_,~-(uint)(local_100 != 0) & 0x40 | uVar1);
  if ((uVar12 >> 0x14 & 1) == 0) {
    local_48 = CONCAT22(local_48._2_2_,0x101);
    local_50._4_4_ = 2;
  }
  else {
    uVar11 = uVar12 & 0xf0000;
    bVar14 = (uVar11 >> 0x12 & 1) != 0;
    local_50._4_4_ = uVar12 & 0xb0000;
    if ((uVar11 >> 0x12 & 1) == 0) {
      local_50._4_4_ = uVar11;
    }
    if (local_50._4_4_ >> 0x13 == 0) {
      local_48._0_2_ = (ushort)bVar14;
    }
    else {
      local_48._0_2_ = CONCAT11(1,bVar14);
      local_50._4_4_ = local_50._4_4_ & 0xfff7ffff;
    }
    local_50._4_4_ = local_50._4_4_ >> 0x10;
  }
  local_50 = CONCAT44(local_50._4_4_,0xc);
  local_58 = &local_50;
  uStack_78 = local_90;
  if (((param_5 == (uint *)0x0) || (lVar5 = *(longlong *)(param_5 + 4), lVar5 == 0)) ||
     (local_60 = *(undefined8 *)(lVar5 + 8), *(int *)(lVar5 + 0x10) == 0)) {
    local_e0 = (ulonglong)local_e0._4_4_ << 0x20;
    lVar5 = 0;
    if (param_5 != (uint *)0x0) goto LAB_14001c4b8;
  }
  else {
    local_e0 = (ulonglong)local_e0._4_4_ << 0x20;
    uStack_68 = CONCAT44(uStack_68._4_4_,(-(uint)(local_100 != 0) & 0xffffffc0) + 0x42 | uVar1);
LAB_14001c4b8:
    lVar5 = 0;
    if (*(longlong *)(param_5 + 6) - 1U < 0xfffffffffffffffe) {
      local_158 = CONCAT44(local_158._4_4_,7);
      iVar2 = NtQueryInformationFile(*(longlong *)(param_5 + 6),&local_d8,local_c8,4);
      if ((-1 < iVar2) && (iVar2 = local_c8[0], local_c8[0] != 0)) {
        do {
          iVar2 = iVar2 * 2;
          lVar5 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                  KernelBaseGlobalData,iVar2);
          if (lVar5 == 0) {
            uVar3 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline
                              ();
            if (uVar3 == 0) {
              RtlReleaseRelativeName(&local_a0);
              RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_f0);
              goto LAB_14001c2f5;
            }
            uVar3 = 0xc0000017;
            goto LAB_14001c6a9;
          }
          local_138 = CONCAT31(local_138._1_3_,1);
          local_140 = 0;
          local_148 = 0;
          local_150 = 0;
          local_158 = local_158 & 0xffffffffffffff00;
          local_f8[0] = NtQueryEaFile(*(undefined8 *)(param_5 + 6),&local_d8,lVar5,iVar2);
          if (local_f8[0] < 0) {
            RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar5);
            lVar5 = 0;
            lStack_d0 = 0;
          }
          local_e0 = lStack_d0;
        } while ((local_f8[0] == -0x7ffffffb) || (local_f8[0] == -0x3fffffdd));
      }
    }
  }
  iVar2 = local_114;
  local_118 = (((uVar3 >> 8 & 0x80000 | uVar3 & 0x10000000) >> 0xc | uVar3 & 0x800000) >> 3 |
              uVar3 & 0x40000) >> 2 | uVar3 >> 0x1a & 8 | (int)uVar3 >> 0x1f & 2U |
              ~(uVar3 >> 0x19) & 0x20 | -(uint)((uVar3 & 0x2000000) != 0) & 0x4000 | local_118;
  if ((SameTebFlags & 0x800) != 0) {
    local_118 = local_118 | 0x40000;
  }
  uVar1 = uVar3 & 0x4000000;
  uVar12 = local_110;
  if (uVar1 != 0) {
    local_118 = local_118 | 0x1000;
    uVar12 = local_110 | 0x10000;
  }
  if ((uVar3 & 0x200000) != 0) {
    local_118 = local_118 | 0x200000;
  }
  if ((uVar3 >> 0x14 & 1) != 0) {
    local_118 = local_118 | 0x400000;
  }
  if ((uVar3 & 0x2000000) == 0) {
    local_118 = local_118 | 0x40;
  }
  else if ((((uVar4 & 0x10) != 0) && (local_100 != 0)) && (local_114 == 2)) {
    local_118 = local_118 | 1;
  }
  local_100 = uVar1;
  if ((param_6 & 2) == 0) {
    pcVar6 = (code *)SbSelectProcedure(0xabababab,1,&g_SbModuleTable_KernelBase,1);
    if (pcVar6 != (code *)0x0) {
      (*pcVar6)(&local_118);
    }
  }
  else {
    local_118 = local_118 | 0x20000;
  }
  uVar3 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline();
  if (((uVar3 == 0) || (bVar10 == 0)) || ((1 < param_4 - 1U && (param_4 != 4)))) {
LAB_14001c836:
    local_110 = uVar12 | 0x100080;
    uVar13 = (undefined4)local_e0;
    local_138 = local_118;
    local_140 = CONCAT44(local_140._4_4_,iVar2);
    local_148 = local_e8;
    local_150 = CONCAT44(local_150._4_4_,uVar4) & 0xffffffff005affa7;
    local_158 = 0;
    local_130 = lVar5;
    local_128 = uVar13;
    uVar3 = NtCreateFile(&local_108,local_110,&local_80,&local_d8);
    if (((uVar3 == 0xc0000022) && ((param_6 & 2) == 0)) &&
       (((local_118 >> 0x11 & 1) != 0 && ((local_e8 & 1) == 0)))) {
      local_138 = local_118 & 0xfffdffff;
      local_140 = CONCAT44(local_140._4_4_,iVar2);
      local_148 = local_e8;
      local_150 = CONCAT44(local_150._4_4_,uVar4) & 0xffffffff005affa7;
      local_158 = 0;
      local_130 = lVar5;
      local_128 = uVar13;
      local_118 = local_138;
      uVar3 = NtCreateFile(&local_108,local_110,&local_80,&local_d8);
    }
    uVar4 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline();
    if (uVar4 == 0) {
      RtlReleaseRelativeName(&local_a0);
      psVar9 = local_f0;
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_f0);
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar5);
      if ((int)uVar3 < 0) {
        BaseSetLastNTError();
        if (uVar3 == 0xc0000035) {
          uVar8 = 0x50;
        }
        else {
          if (uVar3 != 0xc00000ba) {
            return (HANDLE)0xffffffffffffffff;
          }
          uVar8 = 3;
          if (local_fc == 0) {
            uVar8 = 5;
          }
        }
LAB_14001c2b5:
        RtlSetLastWin32Error(uVar8);
        return (HANDLE)0xffffffffffffffff;
      }
      RtlSetLastWin32Error();
    }
    else {
      if ((int)uVar3 < 0) {
LAB_14001c9e0:
        local_108 = (HANDLE)0xffffffffffffffff;
        goto LAB_14001c6a9;
      }
      if (bVar10 != 0) {
        if ((local_118 & 1) == 0) {
          uVar7 = BasepGetFileRedirectionStatus(psStack_b8,local_108);
          uVar3 = (uint)uVar7;
        }
        else {
          uVar3 = BasepGetDirectoryRedirectionStatus(psStack_b8,local_108);
        }
        if ((int)uVar3 < 0) {
          if (local_100 != 0) {
            local_f8[0] = 8;
            local_158 = CONCAT44(local_158._4_4_,0x40);
            NtSetInformationFile(local_108,&local_d8,local_f8,4);
          }
          NtClose(local_108);
          goto LAB_14001c9e0;
        }
      }
      psVar9 = local_f0;
    }
    if (param_4 == 5) {
      local_b0 = 0;
      local_158 = CONCAT44(local_158._4_4_,0x13);
      uVar3 = NtSetInformationFile(local_108,&local_d8,&local_b0,8);
      if ((int)uVar3 < 0) {
        uVar4 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline()
        ;
        if (uVar4 != 0) {
          NtClose(local_108);
          local_108 = (HANDLE)0xffffffffffffffff;
          goto LAB_14001c6ad;
        }
        BaseSetLastNTError();
        NtClose(local_108);
        local_108 = (HANDLE)0xffffffffffffffff;
      }
    }
    uVar4 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline();
    if (uVar4 != 0) {
      if (((param_4 == 2) && (lStack_d0 == 3)) || ((param_4 == 4 && (lStack_d0 == 1)))) {
        uVar8 = 0xb7;
      }
      else {
        uVar8 = 0;
      }
      RtlSetLastWin32Error(uVar8);
    }
  }
  else {
    uVar7 = BasepOpenParentDirectoryNoRedirection((ushort *)&local_c0,&local_a8);
    uVar3 = (uint)uVar7;
    if (-1 < (int)uVar3) goto LAB_14001c836;
LAB_14001c6a9:
    psVar9 = local_f0;
  }
LAB_14001c6ad:
  uVar4 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline();
  if (uVar4 != 0) {
    if (local_a8 != -1) {
      NtClose();
    }
    RtlReleaseRelativeName(&local_a0);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,psVar9);
    if (lVar5 != 0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar5);
    }
    if ((int)uVar3 < 0) {
      BaseSetLastNTError();
      if (uVar3 == 0xc0000035) {
        uVar8 = 0x50;
      }
      else {
        if (uVar3 != 0xc00000ba) {
          return local_108;
        }
        uVar8 = 3;
        if (local_fc == 0) {
          uVar8 = 5;
        }
      }
      RtlSetLastWin32Error(uVar8);
    }
  }
  return local_108;
}



===== CreateFileW @ 14001cb70 =====

HANDLE __stdcall
CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,
           LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,
           DWORD dwFlagsAndAttributes,HANDLE hTemplateFile)

{
  uint uVar1;
  HANDLE pvVar2;
  uint local_28 [8];
  
  local_28[0] = 0x20;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_28[1] = 0x80;
  local_28[2] = 0;
  uVar1 = Feature_Servicing_CD_PathRedirectionAPI_2503__private_IsEnabledDeviceUsageNoInline();
  pvVar2 = CreateFileInternal(0x14002ac90,0,3,3,local_28,(uint)(uVar1 != 0));
  return pvVar2;
}



===== CloseHandle @ 14001cbd0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

BOOL __stdcall CloseHandle(HANDLE hObject)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = (int)hObject;
  if (iVar1 != -0xc) {
    if ((iVar1 != -0xb) && (iVar1 != -10)) goto LAB_14001cc52;
    if (iVar1 != -0xc) {
      if (iVar1 == -0xb) {
        hObject = *(HANDLE *)(*(longlong *)((longlong)ProcessEnvironmentBlock + 0x20) + 0x28);
        *(undefined8 *)(*(longlong *)((longlong)ProcessEnvironmentBlock + 0x20) + 0x28) = 0;
      }
      else if (iVar1 == -10) {
        hObject = *(HANDLE *)(*(longlong *)((longlong)ProcessEnvironmentBlock + 0x20) + 0x20);
        *(undefined8 *)(*(longlong *)((longlong)ProcessEnvironmentBlock + 0x20) + 0x20) = 0;
      }
      else {
        BaseSetLastNTError();
      }
      goto LAB_14001cc52;
    }
  }
  hObject = *(HANDLE *)(*(longlong *)((longlong)ProcessEnvironmentBlock + 0x20) + 0x30);
  *(undefined8 *)(*(longlong *)((longlong)ProcessEnvironmentBlock + 0x20) + 0x30) = 0;
LAB_14001cc52:
  pcVar2 = (code *)SbSelectProcedure(0xabababab,1,&g_SbModuleTable_KernelBase);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)();
  }
  iVar1 = NtClose(hObject);
  if (iVar1 < 0) {
    BaseSetLastNTError();
  }
  return (uint)(iVar1 >= 0);
}



===== SwitchedCloseHandleNoRaiseUMException_WinBLUE @ 14001ccb0 =====

void SwitchedCloseHandleNoRaiseUMException_WinBLUE(void)

{
  int iVar1;
  undefined4 local_res8 [8];
  
  if ((*(char *)((longlong)ProcessEnvironmentBlock + 2) != '\x01') && (DAT_140031cf0 != 0)) {
    local_res8[0] = 0;
    iVar1 = NtSetInformationProcess(0xffffffffffffffff,0x47,local_res8);
    if (iVar1 == 0) {
      DAT_140031cf0 = 0;
    }
  }
  return;
}



===== SwitchedCloseHandleRaiseUMException_Current @ 14001cd10 =====

void SwitchedCloseHandleRaiseUMException_Current(void)

{
  int iVar1;
  undefined4 local_res8 [8];
  
  if (DAT_140031cf0 != 1) {
    local_res8[0] = 1;
    iVar1 = NtSetInformationProcess(0xffffffffffffffff,0x47,local_res8);
    if (iVar1 == 0) {
      DAT_140031cf0 = 1;
    }
  }
  return;
}



===== FindLFNorSFN_U @ 14001cd60 =====

undefined8 FindLFNorSFN_U(short *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  short sVar2;
  short *psVar3;
  
  do {
    sVar2 = *param_1;
    if (sVar2 == 0) {
      return 0;
    }
    do {
      if ((sVar2 != 0x5c) && (sVar2 != 0x2f)) break;
      param_1 = param_1 + 1;
      sVar2 = *param_1;
    } while (sVar2 != 0);
    psVar3 = param_1;
    if (sVar2 == 0) {
      return 0;
    }
    do {
      psVar3 = psVar3 + 1;
      sVar2 = *psVar3;
      if ((sVar2 == 0) || (sVar2 == 0x5c)) break;
    } while (sVar2 != 0x2f);
    uVar1 = IsLongName_U(param_1,(int)((longlong)psVar3 - (longlong)param_1 >> 1));
    if ((int)uVar1 == 0) {
      if (param_2 == (undefined8 *)0x0) {
        return 1;
      }
      if (param_3 == (undefined8 *)0x0) {
        return 1;
      }
      *param_2 = param_1;
      *param_3 = psVar3;
      return 1;
    }
    if (*psVar3 == 0) {
      return 0;
    }
    param_1 = psVar3 + 1;
  } while( true );
}



===== GetLongPathNameW @ 14001ce30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD __stdcall GetLongPathNameW(LPCWSTR lpszShortPath,LPWSTR lpszLongPath,DWORD cchBuffer)

{
  WCHAR WVar1;
  LPCWSTR *ppWVar2;
  UINT uMode;
  int iVar3;
  uint uVar4;
  uint extraout_EAX;
  ulonglong uVar5;
  short *psVar6;
  undefined8 uVar7;
  size_t sVar8;
  LPCWSTR *_Dst;
  undefined8 *hFindFile;
  LPCWSTR *ppWVar9;
  uint uVar10;
  DWORD DVar11;
  DWORD DVar12;
  LPCWSTR *_Str;
  LPWSTR _Dst_00;
  undefined1 auStack_308 [48];
  DWORD local_2d8;
  UINT local_2d4;
  LPCWSTR local_2d0;
  DWORD local_2c8;
  LPWSTR local_2c0;
  LPCWSTR *local_2b8;
  LPCWSTR *local_2b0;
  LPWSTR local_2a8;
  LPCWSTR *local_2a0;
  uint local_298 [11];
  wchar_t local_26c [274];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_308;
  local_2d8 = 0;
  local_2d0 = (LPCWSTR)0x0;
  local_2b8 = (LPCWSTR *)0x0;
  local_2c0 = (LPWSTR)0x0;
  _Dst = (LPCWSTR *)0x0;
  local_2b0 = (LPCWSTR *)0x0;
  local_2c8 = cchBuffer;
  memset(local_298,0,0x250);
  if (lpszShortPath == (LPCWSTR)0x0) {
    RtlSetLastWin32Error(0x57);
    return 0;
  }
  uMode = SetErrorMode(0x8001);
  local_2d4 = uMode;
  uVar5 = InternalGetFileAttributesW(lpszShortPath);
  DVar12 = 0;
  if ((int)uVar5 == -1) goto LAB_14001d222;
  psVar6 = SkipPathTypeIndicator_U(lpszShortPath);
  if (((psVar6 == (short *)0x0) || (*psVar6 == 0)) ||
     (uVar7 = FindLFNorSFN_U(psVar6,&local_2d0,&local_2b8), (int)uVar7 == 0)) {
    sVar8 = wcslen(lpszShortPath);
    extraout_EAX = (uint)sVar8;
    if ((extraout_EAX < cchBuffer) && (lpszLongPath != (LPWSTR)0x0)) {
      DVar12 = extraout_EAX;
      local_2d8 = extraout_EAX;
      if (lpszLongPath != lpszShortPath) {
        local_2d8 = extraout_EAX;
        memmove(lpszLongPath,lpszShortPath,(ulonglong)(extraout_EAX + 1) * 2);
      }
    }
    else {
      DVar12 = extraout_EAX + 1;
      local_2d8 = DVar12;
    }
    goto LAB_14001d222;
  }
  sVar8 = wcslen(lpszShortPath);
  uVar5 = (ulonglong)((int)sVar8 + 1);
  sVar8 = uVar5 * 2;
  _Dst = (LPCWSTR *)
         RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                         KernelBaseGlobalData + 0x200000,sVar8);
  local_2b0 = _Dst;
  if (_Dst == (LPCWSTR *)0x0) {
    RtlSetLastWin32Error(8);
    DVar12 = local_2d8;
    goto LAB_14001d222;
  }
  ppWVar9 = (LPCWSTR *)lpszShortPath;
  memmove(_Dst,lpszShortPath,sVar8);
  local_2d0 = (LPCWSTR)((longlong)_Dst + ((longlong)local_2d0 - (longlong)lpszShortPath >> 1) * 2);
  local_2b8 = (LPCWSTR *)((longlong)_Dst + ((longlong)local_2b8 - (longlong)lpszShortPath >> 1) * 2)
  ;
  local_2a8 = lpszLongPath;
  if ((cchBuffer == 0) || (lpszLongPath == (LPWSTR)0x0)) {
LAB_14001d06d:
    _Str = _Dst;
    _Dst_00 = local_2a8;
    DVar11 = local_2d8;
    local_2a0 = _Dst;
    do {
      ppWVar2 = local_2b8;
      uVar5 = (longlong)local_2d0 - (longlong)_Str >> 1;
      iVar3 = (int)uVar5;
      uVar10 = DVar11 + iVar3;
      local_2d8 = uVar10;
      if ((iVar3 != 0) && (uVar10 < local_2c8)) {
        uVar5 = uVar5 & 0xffffffff;
        ppWVar9 = _Str;
        memmove(_Dst_00,_Str,uVar5 * 2);
        _Dst_00 = _Dst_00 + uVar5;
        local_2a8 = _Dst_00;
      }
      WVar1 = *(WCHAR *)ppWVar2;
      *(WCHAR *)ppWVar2 = L'\0';
      hFindFile = InternalFindFirstFileExW(_Dst,ppWVar9,local_298);
      *(WCHAR *)ppWVar2 = WVar1;
      if (hFindFile == (undefined8 *)0xffffffffffffffff) {
        DVar11 = 0;
        local_2d8 = 0;
        break;
      }
      FindClose(hFindFile);
      sVar8 = wcslen(local_26c);
      if ((uint)sVar8 == 0) {
        uVar4 = (uint)((longlong)ppWVar2 - (longlong)local_2d0 >> 1);
      }
      else {
        local_2d0 = local_26c;
        uVar4 = (uint)sVar8;
      }
      DVar11 = uVar10 + uVar4;
      local_2d8 = DVar11;
      if ((DVar11 < local_2c8) && (lpszLongPath != (LPWSTR)0x0)) {
        memmove(_Dst_00,local_2d0,(ulonglong)uVar4 * 2);
        _Dst_00 = _Dst_00 + uVar4;
        local_2a8 = _Dst_00;
      }
      _Str = ppWVar2;
      local_2a0 = ppWVar2;
      if (*(WCHAR *)ppWVar2 == L'\0') break;
      ppWVar9 = &local_2d0;
      uVar7 = FindLFNorSFN_U((short *)ppWVar2,ppWVar9,&local_2b8);
    } while ((int)uVar7 != 0);
    DVar12 = 0;
    if (DVar11 != 0) {
      sVar8 = wcslen((wchar_t *)_Str);
      DVar12 = DVar11 + (int)sVar8;
      if ((DVar12 < local_2c8) && (lpszLongPath != (LPWSTR)0x0)) {
        local_2d8 = DVar12;
        memmove(_Dst_00,_Str,(ulonglong)((int)sVar8 + 1) * 2);
        if (local_2c0 != (LPWSTR)0x0) {
          memmove(lpszLongPath,local_2c0,(ulonglong)(DVar12 + 1) * 2);
        }
      }
      else {
        DVar12 = DVar12 + 1;
        local_2d8 = DVar12;
      }
    }
  }
  else {
    if (lpszLongPath < lpszShortPath) {
LAB_14001cffb:
      if (lpszLongPath + cchBuffer < lpszShortPath) goto LAB_14001d06d;
    }
    else if (lpszShortPath + uVar5 <= lpszLongPath) {
      if (lpszShortPath <= lpszLongPath) goto LAB_14001d06d;
      goto LAB_14001cffb;
    }
    ppWVar9 = (LPCWSTR *)(ulonglong)(KernelBaseGlobalData + 0x200000);
    local_2c0 = (LPWSTR)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                                        ppWVar9,(ulonglong)cchBuffer * 2);
    if (local_2c0 != (LPWSTR)0x0) {
      _Dst = local_2b0;
      local_2a8 = local_2c0;
      goto LAB_14001d06d;
    }
    RtlSetLastWin32Error(8);
    _Dst = local_2b0;
    DVar12 = local_2d8;
  }
  uMode = local_2d4;
LAB_14001d222:
  if (_Dst != (LPCWSTR *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_2b0);
    DVar12 = local_2d8;
  }
  if (local_2c0 != (LPWSTR)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_2c0);
    DVar12 = local_2d8;
  }
  SetErrorMode(uMode);
  return DVar12;
}



===== IsLongName_U @ 14001d28c =====

undefined8 IsLongName_U(short *param_1,int param_2)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (((param_2 == 0) || (0xc < param_2)) || (*param_1 == 0x2e)) {
    return 1;
  }
  bVar1 = false;
  lVar3 = (longlong)param_2;
  lVar2 = 0;
  do {
    param_2 = param_2 + -1;
    if (lVar3 <= lVar2) {
      return 0;
    }
    if (param_1[lVar2] == 0x2e) {
      if (bVar1) {
        return 1;
      }
      if (3 < param_2) {
        return 1;
      }
      bVar1 = true;
    }
    if ((7 < lVar2) && (!bVar1)) {
      return 1;
    }
    lVar2 = lVar2 + 1;
  } while( true );
}



===== SkipPathTypeIndicator_U @ 14001d2ec =====

short * SkipPathTypeIndicator_U(short *param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  iVar1 = RtlDetermineDosPathNameType_U();
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      return param_1 + 3;
    }
    if (iVar1 == 3) {
      return param_1 + 2;
    }
    if (iVar1 == 4) {
      return param_1 + 1;
    }
    if (iVar1 == 5) {
      return param_1;
    }
    if (iVar1 != 6) {
      return (short *)0x0;
    }
  }
  iVar3 = 2;
  iVar1 = _wcsnicmp(param_1 + 2,L"?\\UNC",5);
  psVar2 = (short *)((longlong)param_1 + (-(ulonglong)(iVar1 != 0) & 0xfffffffffffffff4) + 0x10);
  do {
    if (*psVar2 == 0) {
      return psVar2;
    }
    if ((*psVar2 == 0x5c) || (*psVar2 == 0x2f)) {
      iVar3 = iVar3 + -1;
    }
    psVar2 = psVar2 + 1;
  } while (iVar3 != 0);
  return psVar2;
}



===== BasepGetModuleHandleExW @ 14001d3a0 =====

uint BasepGetModuleHandleExW(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 local_res10 [3];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"ntdll.dll");
  uVar1 = LdrGetDllHandle(0,0,&local_18,local_res10);
  if ((int)uVar1 < 0) {
    BaseSetLastNTError();
    local_res10[0] = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = local_res10[0];
  }
  return ~uVar1 >> 0x1f;
}



===== GetModuleHandleW @ 14001d428 =====

HMODULE __stdcall GetModuleHandleW(LPCWSTR lpModuleName)

{
  uint uVar1;
  undefined8 in_RDX;
  ulonglong local_res8 [4];
  
  local_res8[0] = 0;
  uVar1 = BasepGetModuleHandleExW(lpModuleName,in_RDX,local_res8);
  return (HMODULE)(-(ulonglong)(uVar1 != 0) & local_res8[0]);
}



===== GetProcAddressForCaller @ 14001d458 =====

ulonglong GetProcAddressForCaller(ulonglong param_1,ulonglong param_2,undefined8 param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  ulonglong local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (param_2 < 0x10000) {
    uVar2 = BasepMapModuleHandle(param_1);
    puVar3 = (undefined8 *)0x0;
    uVar4 = param_2 & 0xffffffff;
  }
  else {
    RtlInitString(&local_18);
    uVar2 = BasepMapModuleHandle(param_1);
    uVar4 = 0;
    puVar3 = &local_18;
  }
  iVar1 = LdrGetProcedureAddressForCaller(uVar2,puVar3,uVar4,&local_res10,0,param_3);
  if ((iVar1 < 0) || (uVar2 = BasepMapModuleHandle(param_1), local_res10 == uVar2)) {
    BaseSetLastNTError();
    local_res10 = 0;
  }
  return local_res10;
}



===== GetVersionExW_Win8 @ 14001d530 =====

undefined8 GetVersionExW_Win8(void)

{
  return 1;
}



===== GetVersionExW_WinBLUE @ 14001d540 =====

undefined8 GetVersionExW_WinBLUE(void)

{
  return 2;
}



===== GetVersion_Current @ 14001d550 =====

uint GetVersion_Current(void)

{
  return ((*(uint *)((longlong)ProcessEnvironmentBlock + 0x124) ^ 0xfffffffe) << 0x16 |
         *(uint *)((longlong)ProcessEnvironmentBlock + 0x11c)) << 8 |
         (uint)*(ushort *)((longlong)ProcessEnvironmentBlock + 0x120) << 0x10 |
         *(uint *)((longlong)ProcessEnvironmentBlock + 0x118);
}



===== GetVersion_Win8 @ 14001d590 =====

undefined8 GetVersion_Win8(void)

{
  return 0x23f00206;
}



===== GetVersion_WinBLUE @ 14001d5a0 =====

undefined8 GetVersion_WinBLUE(void)

{
  return 0x25800306;
}



===== BasepGetDirectoryRedirectionStatus @ 14001d5b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BasepGetDirectoryRedirectionStatus(short *param_1,HANDLE param_2)

{
  longlong lVar1;
  uint uVar2;
  short *psVar3;
  ulonglong uVar4;
  short *psVar5;
  undefined1 auStack_278 [32];
  longlong local_258 [2];
  short local_248 [264];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_278;
  local_258[0] = 0;
  psVar3 = (short *)0x0;
  uVar2 = RtlStringCchLengthW(param_1,0x7fffffff,local_258);
  lVar1 = local_258[0];
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (param_1[local_258[0] + -1] == 0x5c) {
    psVar5 = param_1;
  }
  else {
    uVar4 = local_258[0] + 2;
    psVar5 = local_248;
    if (0x104 < uVar4) {
      psVar3 = (short *)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                        uVar4 * 2);
      if (psVar3 == (short *)0x0) {
        return 0xc0000017;
      }
      psVar5 = psVar3;
    }
    uVar2 = RtlStringCchCopyW(psVar5,uVar4,param_1);
    if ((int)uVar2 < 0) goto LAB_14001d681;
    (psVar5 + lVar1)[0] = 0x5c;
    (psVar5 + lVar1)[1] = 0;
  }
  uVar4 = BasepGetFileRedirectionStatus(psVar5,param_2);
  uVar2 = (uint)uVar4;
LAB_14001d681:
  if (psVar3 != (short *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,psVar3);
  }
  return uVar2;
}



===== BasepGetFileRedirectionStatus @ 14001d6dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BasepGetFileRedirectionStatus(undefined8 param_1,HANDLE param_2)

{
  int iVar1;
  DWORD cchFilePath;
  DWORD DVar2;
  ulonglong uVar3;
  LPWSTR lpszFilePath;
  uint uVar4;
  LPWSTR pWVar5;
  undefined1 auStack_318 [32];
  undefined4 local_2f8;
  undefined8 local_2e8;
  wchar_t *local_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  undefined1 local_2c8 [16];
  byte local_2b8;
  WCHAR local_248 [264];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_318;
  local_2e8 = 0;
  lpszFilePath = local_248;
  uVar4 = 0;
  local_2e0 = (wchar_t *)0x0;
  DVar2 = 0;
  uVar3 = RtlDosPathNameToNtPathName_U_WithStatus(param_1,&local_2e8,0,0);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  iVar1 = _wcsnicmp(local_2e0,L"\\??\\UNC\\",8);
  if ((iVar1 == 0) || (iVar1 = _wcsnicmp(local_2e0,L"\\\\?\\UNC\\",8), iVar1 == 0)) {
    local_2d8 = 0;
    uStack_2d0 = 0;
    memset(local_2c8,0,0x74);
    local_2f8 = 0x37;
    iVar1 = NtQueryInformationFile(param_2,&local_2d8,local_2c8,0x74);
    if ((iVar1 < 0) || ((local_2b8 & 1) == 0)) {
      DVar2 = 8;
    }
  }
  else {
    DVar2 = 8;
  }
  cchFilePath = GetFinalPathNameByHandleW(param_2,(LPWSTR)0x0,0,DVar2);
  if (cchFilePath == 0) {
LAB_14001d7f2:
    uVar4 = 0xc0000017;
  }
  else {
    pWVar5 = (LPWSTR)0x0;
    if (0x104 < cchFilePath) {
      lpszFilePath = (LPWSTR)RtlAllocateHeap(*(undefined8 *)
                                              ((longlong)ProcessEnvironmentBlock + 0x30),
                                             KernelBaseGlobalData,(ulonglong)cchFilePath * 2);
      if (lpszFilePath == (LPWSTR)0x0) goto LAB_14001d7f2;
      pWVar5 = lpszFilePath;
    }
    DVar2 = GetFinalPathNameByHandleW(param_2,lpszFilePath,cchFilePath,DVar2);
    if (DVar2 == 0) {
      uVar4 = 0xc0000017;
    }
    else if (DVar2 < 5) {
      uVar4 = 0xc0000039;
    }
    else {
      iVar1 = _wcsnicmp(lpszFilePath,L"\\\\?\\",4);
      if ((iVar1 == 0) || (iVar1 = _wcsnicmp(lpszFilePath,L"\\??\\",4), iVar1 == 0)) {
        uVar4 = 4;
      }
      iVar1 = _wcsnicmp(local_2e0 + 4,lpszFilePath + uVar4,(ulonglong)(DVar2 - uVar4));
      uVar4 = -(uint)(iVar1 != 0) & 0xc000050b;
    }
    if (pWVar5 != (LPWSTR)0x0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pWVar5);
    }
  }
  if (local_2e0 != (wchar_t *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_2e0);
  }
  return (ulonglong)uVar4;
}



===== BasepOpenParentDirectoryNoRedirection @ 14001d94c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BasepOpenParentDirectoryNoRedirection(ushort *param_1,undefined8 *param_2)

{
  undefined2 *puVar1;
  ulonglong uVar2;
  HANDLE pvVar3;
  ushort uVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  undefined1 auStack_298 [32];
  undefined8 *local_278;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined2 local_248 [264];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_298;
  puVar1 = (undefined2 *)0x0;
  local_268 = 0;
  uStack_260 = 0;
  local_258 = 0;
  uStack_250 = 0;
  if (*param_1 == 0) {
    return 0xc000000d;
  }
  puVar6 = local_248;
  if (0x208 < (*param_1 & 0xfffe)) {
    puVar1 = (undefined2 *)
             RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                             KernelBaseGlobalData,(ulonglong)*param_1 + 2);
    if (puVar1 == (undefined2 *)0x0) {
      return 0xc0000017;
    }
    puVar6 = puVar1;
  }
  uVar2 = RtlStringCbCopyUnicodeString(puVar6,(ulonglong)*param_1 + 2,param_1);
  uVar5 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar4 = *param_1 >> 1;
    do {
      uVar4 = uVar4 - 1;
    } while (puVar6[uVar4] == 0x5c);
    if (uVar4 == 0) {
      uVar5 = 0xc000000d;
      goto LAB_14001daa7;
    }
    for (; puVar6[uVar4] != 0x5c; uVar4 = uVar4 - 1) {
    }
    puVar6[(ulonglong)uVar4 + 1] = 0;
    local_278 = &local_268;
    local_268 = CONCAT44(local_268._4_4_,0x20);
    uStack_260 = CONCAT44(uStack_260._4_4_,0x2000000);
    pvVar3 = (HANDLE)CreateFile2(puVar6);
    if (pvVar3 == (HANDLE)0xffffffffffffffff) goto LAB_14001daa7;
    uVar2 = BasepGetFileRedirectionStatus(puVar6,pvVar3);
    uVar5 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      *param_2 = pvVar3;
      goto LAB_14001daa7;
    }
    NtClose(pvVar3);
  }
  BaseSetLastNTError();
LAB_14001daa7:
  if (puVar1 != (undefined2 *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar1);
  }
  return uVar5;
}



===== RtlStringCbCopyUnicodeString @ 14001dafc =====

ulonglong RtlStringCbCopyUnicodeString(undefined2 *param_1,ulonglong param_2,ushort *param_3)

{
  ulonglong uVar1;
  undefined2 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong local_res10 [2];
  longlong local_res20;
  
  uVar4 = param_2 >> 1;
  if (uVar4 - 1 < 0x7fff) {
    local_res20 = 0;
    local_res10[0] = 0;
    uVar1 = RtlUnicodeStringValidateSrcWorker(param_3,&local_res20,local_res10);
    if ((int)uVar1 < 0) {
      *param_1 = 0;
    }
    else {
      lVar3 = local_res10[0] - uVar4;
      local_res20 = local_res20 - (longlong)param_1;
      do {
        if (lVar3 + uVar4 == 0) break;
        *param_1 = *(undefined2 *)(local_res20 + (longlong)param_1);
        param_1 = param_1 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      puVar2 = param_1 + -1;
      if (uVar4 != 0) {
        puVar2 = param_1;
      }
      *puVar2 = 0;
      uVar1 = (ulonglong)(~-(uint)(uVar4 != 0) & 0x80000005);
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== RtlStringCchCopyW @ 14001dba4 =====

uint RtlStringCchCopyW(short *param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  
  if (param_2 - 1U < 0x7fffffff) {
    uVar1 = RtlStringCopyWorkerW(param_1,param_2,param_3,param_3,0x7ffffffe);
  }
  else {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return uVar1;
}



===== RtlStringCchLengthW @ 14001dbe4 =====

uint RtlStringCchLengthW(short *param_1,ulonglong param_2,longlong *param_3)

{
  uint uVar1;
  
  if ((param_1 == (short *)0x0) || (0x7fffffff < param_2)) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = RtlStringLengthWorkerW(param_1,param_2,param_3);
    if (-1 < (int)uVar1) {
      return uVar1;
    }
  }
  if (param_3 != (longlong *)0x0) {
    *param_3 = 0;
  }
  return uVar1;
}



===== RtlStringCopyWorkerW @ 14001dc1c =====

uint RtlStringCopyWorkerW
               (short *param_1,longlong param_2,undefined8 param_3,longlong param_4,longlong param_5
               )

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  
  if (param_2 != 0) {
    lVar3 = param_4 - (longlong)param_1;
    do {
      if ((param_5 == 0) || (sVar1 = *(short *)(lVar3 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      param_5 = param_5 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar2 = param_1 + -1;
  if (param_2 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== RtlStringLengthWorkerW @ 14001dc78 =====

uint RtlStringLengthWorkerW(short *param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = param_2;
  for (; (lVar2 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
    lVar2 = lVar2 + -1;
  }
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 != (longlong *)0x0) {
    if (lVar2 != 0) {
      *param_3 = param_2 - lVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== RtlUnicodeStringValidateSrcWorker @ 14001dcc0 =====

undefined8 RtlUnicodeStringValidateSrcWorker(ushort *param_1,undefined8 *param_2,ulonglong *param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  uVar1 = *param_1;
  *param_2 = 0;
  *param_3 = 0;
  if ((((((uVar1 & 1) == 0) && (uVar1 = param_1[1], (uVar1 & 1) == 0)) && (*param_1 <= uVar1)) &&
      (uVar1 != 0xffff)) && ((*(longlong *)(param_1 + 4) != 0 || ((*param_1 == 0 && (uVar1 == 0)))))
     ) {
    *param_2 = *(undefined8 *)(param_1 + 4);
    *param_3 = (ulonglong)(*param_1 >> 1);
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== SbFilterProcedure_KernelBase @ 14001dd30 =====

/* void * __ptr64 __cdecl SbFilterProcedure_KernelBase(void * __ptr64) */

void * __cdecl SbFilterProcedure_KernelBase(void *param_1)

{
  return "SbFilterProcedure_KernelBase";
}



===== GetOverlappedResult_Vista @ 14001dd40 =====

void GetOverlappedResult_Vista(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}



===== GetOverlappedResult_Win7 @ 14001dd50 =====

void GetOverlappedResult_Win7(undefined4 *param_1)

{
  *param_1 = 1;
  return;
}



===== SetErrorMode @ 14001dd60 =====

UINT __stdcall SetErrorMode(UINT uMode)

{
  int iVar1;
  uint uVar2;
  uint local_res8 [2];
  uint local_res10 [2];
  
  local_res8[0] = 0;
  iVar1 = NtQueryInformationProcess(0xffffffffffffffff,0xc,local_res8,4,0);
  if (iVar1 < 0) {
    BaseSetLastNTError();
    uVar2 = 0;
  }
  else if ((local_res8[0] & 1) == 0) {
    uVar2 = local_res8[0] | 1;
  }
  else {
    uVar2 = local_res8[0] & 0xfffffffe;
  }
  local_res10[0] = uMode & 0xfffffffe;
  if ((uMode & 1) == 0) {
    local_res10[0] = uMode | 1;
  }
  local_res10[0] = local_res10[0] | uVar2 & 4;
  NtSetInformationProcess(0xffffffffffffffff,0xc,local_res10);
  return uVar2;
}



===== BasepInitializeFindFileHandle @ 14001de0c =====

undefined8 * BasepInitializeFindFileHandle(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),
                           KernelBaseGlobalData + 0xc0000,0x50);
  if (puVar2 != (undefined8 *)0x0) {
    puVar2[1] = 0;
    puVar2[2] = 0;
    *(undefined4 *)(puVar2 + 3) = 0;
    *(undefined4 *)((longlong)puVar2 + 0x1c) = 0;
    *(undefined4 *)(puVar2 + 4) = 0;
    *(undefined4 *)((longlong)puVar2 + 0x24) = 0;
    *puVar2 = param_1;
    iVar1 = RtlInitializeCriticalSection(puVar2 + 5);
    if (iVar1 < 0) {
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,puVar2);
      puVar2 = (undefined8 *)0x0;
    }
  }
  return puVar2;
}



===== FindClose @ 14001deb4 =====

BOOL __stdcall FindClose(HANDLE hFindFile)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  BOOL BVar4;
  int iVar5;
  
  if (hFindFile == (HANDLE)0x1) {
    BVar4 = 1;
  }
  else if (hFindFile == (HANDLE)0xffffffffffffffff) {
    RtlSetLastWin32Error(6);
    BVar4 = 0;
  }
  else {
    lVar1 = (longlong)hFindFile + 0x28;
    RtlEnterCriticalSection(lVar1);
    uVar2 = *(undefined8 *)hFindFile;
    lVar3 = *(longlong *)((longlong)hFindFile + 8);
    *(undefined8 *)hFindFile = 0xffffffffffffffff;
    *(undefined8 *)((longlong)hFindFile + 8) = 0;
    RtlLeaveCriticalSection(lVar1);
    iVar5 = NtClose(uVar2);
    if (iVar5 < 0) {
      BaseSetLastNTError();
      BVar4 = 0;
    }
    else {
      if (lVar3 != 0) {
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar3);
      }
      RtlDeleteCriticalSection(lVar1);
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,hFindFile);
      BVar4 = 1;
    }
  }
  return BVar4;
}



===== InternalFindFirstFileExW @ 14001dfc8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * InternalFindFirstFileExW(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  short *psVar3;
  char cVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  undefined8 *puVar9;
  short sVar10;
  undefined8 uVar11;
  short *psVar12;
  void *_Src;
  size_t _Size;
  undefined1 auStack_3a8 [32];
  undefined8 *local_388;
  undefined1 *local_380;
  undefined4 local_378;
  undefined4 local_370;
  undefined4 local_368;
  undefined8 *local_360;
  undefined8 local_358;
  undefined8 local_350;
  short *psStack_348;
  undefined8 local_340;
  short *psStack_338;
  undefined8 local_330;
  longlong lStack_328;
  undefined8 local_320;
  short *psStack_318;
  undefined8 local_310;
  undefined8 uStack_308;
  undefined8 local_300;
  undefined8 uStack_2f8;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined8 local_2e8;
  undefined8 *local_2e0;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined1 local_2b8 [8];
  undefined8 local_2b0;
  undefined8 local_2a8;
  undefined8 local_2a0;
  uint local_290;
  uint local_28c;
  uint local_280;
  uint uStack_27c;
  uint local_278;
  byte local_274;
  undefined1 local_272 [24];
  undefined1 local_25a [530];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_3a8;
  local_358 = 0;
  local_2ec = 0;
  local_2d4 = 0;
  local_340 = 0;
  psStack_338 = (short *)0x0;
  local_350 = 0;
  psStack_348 = (short *)0x0;
  local_300 = 0;
  uStack_2f8 = 0;
  memset(local_2b8,0,0x268);
  local_320 = 0;
  psStack_318 = (short *)0x0;
  local_310 = 0;
  uStack_308 = 0;
  local_330 = 0;
  lStack_328 = 0;
  RtlInitUnicodeString(&local_330,param_1);
  if (((ushort)local_330 == 0) ||
     (bVar2 = true, *(short *)(lStack_328 + -2 + (ulonglong)((ushort)local_330 >> 1) * 2) != 0x2e))
  {
    bVar2 = false;
  }
  cVar4 = RtlDosPathNameToRelativeNtPathName_U(param_1,&local_350,&psStack_338,&local_320);
  psVar3 = psStack_348;
  if (cVar4 == '\0') {
    uVar11 = 3;
    goto LAB_14001e518;
  }
  uVar6 = RtlIsDosDeviceName_U(lStack_328);
  if (uVar6 != 0) {
    RtlReleaseRelativeName(&local_320);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,psVar3);
    _Src = (void *)((ulonglong)(uVar6 >> 0x10) + lStack_328);
    memset(param_3 + 1,0,0x24c);
    _Size = 0x208;
    *param_3 = 0x20;
    if ((ushort)uVar6 < 0x208) {
      _Size = (size_t)(uVar6 & 0xffff);
    }
    memmove(param_3 + 0xb,_Src,_Size);
    *(undefined2 *)((longlong)param_3 + 0x232) = 0;
    return (undefined8 *)0x1;
  }
  if (psStack_338 == (short *)0x0) {
    sVar10 = 0;
  }
  else {
    sVar10 = ((short)psStack_348 - (short)psStack_338) + (ushort)local_350;
  }
  local_340._0_4_ = CONCAT22(sVar10,sVar10);
  uVar5 = (ushort)local_350;
  if (((short)local_320 == 0) || (psStack_318 == psStack_338)) {
    local_310 = 0;
    if (psStack_338 != (short *)0x0) {
      sVar10 = (short)psStack_348;
      goto LAB_14001e1a0;
    }
  }
  else if (psStack_338 != (short *)0x0) {
    psStack_348 = psStack_318;
    sVar10 = (short)psStack_318;
LAB_14001e1a0:
    uVar5 = (short)psStack_338 - sVar10;
    local_350 = CONCAT62(CONCAT42(local_350._4_4_,uVar5),uVar5);
  }
  uVar6 = (uint)(uVar5 >> 1);
  if (((uVar6 < 2) || (psStack_348[uVar6 - 2] == 0x3a)) ||
     (bVar1 = true, psStack_348[uVar6 - 1] != 0x5c)) {
    bVar1 = false;
  }
  local_2e8 = local_310;
  local_2e0 = &local_350;
  local_380 = (undefined1 *)CONCAT44(local_380._4_4_,0x4021);
  local_2f0 = 0x30;
  local_2d8 = 0x40;
  local_2d0 = 0;
  uStack_2c8 = 0;
  local_388 = (undefined8 *)CONCAT44(local_388._4_4_,7);
  iVar7 = NtOpenFile(&local_358,0x100001,&local_2f0,&local_300);
  if ((bVar1) && ((iVar7 == -0x3ffffff3 || (iVar7 == -0x3ffffefd)))) {
    local_380 = (undefined1 *)CONCAT44(local_380._4_4_,0x4021);
    local_350 = CONCAT62(local_350._2_6_,(ushort)local_350 + -2);
    local_388 = (undefined8 *)CONCAT44(local_388._4_4_,7);
    iVar7 = NtOpenFile(&local_358,0x100001,&local_2f0,&local_300);
  }
  if (iVar7 < 0) {
    RtlReleaseRelativeName(&local_320);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,psVar3);
LAB_14001e2c9:
    BaseSetLastNTError();
    return (undefined8 *)0xffffffffffffffff;
  }
  if ((ushort)local_340 == 0) {
    RtlReleaseRelativeName(&local_320);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,psVar3);
    NtClose(local_358);
    uVar11 = 2;
  }
  else {
    if (((ushort)local_340 == 6) && (lVar8 = RtlCompareMemory(psStack_338,L"*.*",6), lVar8 == 6)) {
      local_340 = CONCAT62(local_340._2_6_,2);
    }
    else {
      uVar6 = 0;
      psVar12 = psStack_338;
      if ((local_340 & 0xfffe) != 0) {
        do {
          if (((uVar6 != 0) && (*psVar12 == 0x2e)) && (psVar12[-1] == 0x2a)) {
            psVar12[-1] = 0x3c;
          }
          if (*psVar12 == 0x3f) {
            *psVar12 = 0x3e;
LAB_14001e399:
            if ((uVar6 != 0) && (psVar12[-1] == 0x2e)) {
              psVar12[-1] = 0x22;
            }
          }
          else if (*psVar12 == 0x2a) goto LAB_14001e399;
          uVar6 = uVar6 + 1;
          psVar12 = psVar12 + 1;
        } while (uVar6 < (ushort)local_340 >> 1);
      }
      if ((bVar2) && (psVar12[-1] == 0x2a)) {
        psVar12[-1] = 0x3c;
      }
    }
    local_360 = &local_340;
    local_368 = 2;
    local_380 = local_2b8;
    local_370 = 3;
    local_378 = 0x268;
    local_388 = &local_300;
    iVar7 = NtQueryDirectoryFileEx(local_358,0,0,0);
    RtlReleaseRelativeName(&local_320);
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,psVar3);
    if (iVar7 < 0) {
      NtClose(local_358);
      goto LAB_14001e2c9;
    }
    *(undefined8 *)(param_3 + 1) = local_2b0;
    *(undefined8 *)(param_3 + 3) = local_2a8;
    *(undefined8 *)(param_3 + 5) = local_2a0;
    param_3[7] = local_28c;
    param_3[8] = local_290;
    *param_3 = local_280;
    uVar6 = uStack_27c;
    if (0x206 < uStack_27c) {
      uVar6 = 0x206;
    }
    memcpy(param_3 + 0xb,local_25a,(ulonglong)uVar6);
    *(undefined2 *)((longlong)param_3 + (ulonglong)(uVar6 >> 1) * 2 + 0x2c) = 0;
    if ((0x1a < local_274) || (uVar6 = (uint)(char)local_274, 0x17 < uVar6)) {
      uVar6 = 0x18;
    }
    memcpy(param_3 + 0x8d,local_272,(ulonglong)uVar6);
    *(undefined2 *)((longlong)param_3 + (ulonglong)(uVar6 >> 1) * 2 + 0x234) = 0;
    if ((local_280 >> 10 & 1) != 0) {
      param_3[9] = local_278;
    }
    puVar9 = BasepInitializeFindFileHandle(local_358);
    if (puVar9 != (undefined8 *)0x0) {
      return puVar9;
    }
    NtClose(local_358);
    uVar11 = 8;
  }
LAB_14001e518:
  RtlSetLastWin32Error(uVar11);
  return (undefined8 *)0xffffffffffffffff;
}



===== NtPnpGetDeviceInterfaceList @ 14001e55c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint NtPnpGetDeviceInterfaceList(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint in_R9D;
  longlong lVar6;
  longlong lVar5;
  ulonglong uVar7;
  ulonglong uVar8;
  short *in_stack_00000028;
  int *in_stack_00000030;
  undefined1 auStackY_278 [32];
  char local_228 [4];
  uint local_224;
  int local_220;
  uint local_21c;
  short *local_218;
  ulonglong local_210;
  short *local_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined4 local_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined8 local_1d8;
  undefined4 local_1d0;
  undefined4 local_1cc;
  short local_1c8 [200];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_278;
  local_200 = 0;
  uStack_1f8 = 0;
  if (NtPnpDeviceApiDriverHandle == 0) {
    return 0xc0000429;
  }
  if ((in_stack_00000028 != (short *)0x0) && (in_R9D < 2)) {
    return 0xc000000d;
  }
  local_1d0 = 0;
  local_1f0 = 0x28;
  local_1e8 = 0xec8324a9;
  uStack_1e4 = 0x44773fe1;
  uStack_1e0 = 0x51aa7090;
  uStack_1dc = 0xe1350d82;
  local_1cc = 0x14;
  local_1d8 = 0;
  lVar4 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                          in_R9D * 2 + 0x14);
  if (lVar4 == 0) {
    return 0xc000009a;
  }
  uVar2 = NtDeviceIoControlFile(NtPnpDeviceApiDriverHandle,0,0,0);
  if ((int)uVar2 < 0) goto LAB_14001e962;
  uVar2 = *(uint *)(lVar4 + 4);
  if (uVar2 == 0xc0000034) {
    if (in_stack_00000030 != (int *)0x0) {
      *in_stack_00000030 = 1;
    }
    if (in_R9D == 0) {
      uVar2 = 0xc0000023;
      goto LAB_14001e962;
    }
    uVar2 = 0;
  }
  else {
    if (((uVar2 + 0x80000000 & 0x80000000) == 0) && (uVar2 != 0xc0000023)) goto LAB_14001e962;
    uVar3 = *(uint *)(lVar4 + 8);
    if ((uVar3 & 0xfffffffe) != 2) {
      if (uVar2 == 0xc0000023) {
        RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar4);
        lVar4 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                                uVar3 + 0x14);
        if (lVar4 == 0) {
          return 0xc000009a;
        }
        uVar2 = NtDeviceIoControlFile(NtPnpDeviceApiDriverHandle,0,0,0);
        if (((int)uVar2 < 0) || (uVar2 = *(uint *)(lVar4 + 4), (int)uVar2 < 0)) goto LAB_14001e962;
      }
      if ((*(uint *)(lVar4 + 8) & 0xfffffffe) != 2) {
        local_208 = (short *)(lVar4 + 0x10);
        local_224 = 0;
        uVar8 = (ulonglong)(in_R9D - 1);
        sVar1 = *local_208;
        local_210 = uVar8;
        local_218 = in_stack_00000028;
        while (sVar1 != 0) {
          lVar5 = -1;
          do {
            lVar6 = lVar5;
            lVar5 = lVar6 + 1;
          } while (local_208[lVar5] != 0);
          local_220 = 0;
          local_1c8[0] = 0;
          uVar7 = lVar6 + 2;
          local_21c = 400;
          uVar3 = NtPnpGetObjectProperty
                            (4,local_208,(int)uVar7 * 2,(undefined8 *)&DEVPKEY_Device_InstanceId,
                             &local_220,local_1c8,&local_21c);
          if (((-1 < (int)uVar3) && (local_220 == 0x12)) && (1 < local_21c)) {
            local_220 = 0;
            local_228[0] = '\0';
            local_21c = 1;
            uVar3 = NtPnpGetObjectProperty
                              (1,local_1c8,400,(undefined8 *)&DEVPKEY_Device_IsPresent,&local_220,
                               local_228,&local_21c);
            if (((-1 < (int)uVar3) && (local_220 == 0x11)) &&
               ((local_21c == 1 && (local_228[0] == -1)))) {
              if (uVar7 <= uVar8) {
                uVar2 = RtlStringCchCopyExW(local_218,uVar8,(longlong)local_208,
                                            (longlong *)&local_218,&local_210);
                if ((int)uVar2 < 0) goto LAB_14001e933;
                local_218 = local_218 + 1;
                uVar8 = local_210 - 1;
                local_210 = uVar8;
              }
              local_224 = local_224 + (int)uVar7;
            }
          }
          local_208 = local_208 + uVar7;
          sVar1 = *local_208;
        }
        if ((int)uVar2 < 0) {
LAB_14001e933:
          if (in_R9D != 0) {
            *in_stack_00000028 = 0;
          }
        }
        else {
          if (local_224 < in_R9D) {
            in_stack_00000028[local_224] = 0;
          }
          else {
            uVar2 = 0xc0000023;
            if (in_R9D != 0) {
              *in_stack_00000028 = 0;
            }
          }
          if (in_stack_00000030 != (int *)0x0) {
            *in_stack_00000030 = local_224 + 1;
          }
        }
        goto LAB_14001e962;
      }
    }
    if (in_stack_00000030 != (int *)0x0) {
      *in_stack_00000030 = 1;
    }
    if ((int)uVar2 < 0) goto LAB_14001e962;
    if (in_R9D == 0) {
      uVar2 = 0xc00000e5;
      goto LAB_14001e962;
    }
  }
  *in_stack_00000028 = 0;
LAB_14001e962:
  RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar4);
  return uVar2;
}



===== NtPnpGetObjectProperty @ 14001e9bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint NtPnpGetObjectProperty
               (undefined4 param_1,short *param_2,uint param_3,undefined8 *param_4,
               undefined4 *param_5,void *param_6,uint *param_7)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 *_Dst;
  undefined1 auStackY_f8 [32];
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  _Dst = local_98;
  memset(_Dst,0,0x48);
  uVar1 = *param_7;
  uVar2 = NtPnpInitializeInputPropertyData(_Dst,param_1,param_2,param_3,param_4);
  if (-1 < (int)uVar2) {
    lVar3 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                            *param_7 + 0x14);
    if (lVar3 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      uVar2 = NtDeviceIoControlFile(NtPnpDeviceApiDriverHandle,0,0,0);
      if (-1 < (int)uVar2) {
        *param_7 = *(uint *)(lVar3 + 8);
        *param_5 = *(undefined4 *)(lVar3 + 0xc);
        uVar2 = *(uint *)(lVar3 + 4);
        if (-1 < (int)uVar2) {
          if (uVar1 < *(uint *)(lVar3 + 8)) {
            uVar2 = 0xc0000023;
          }
          else {
            memcpy(param_6,(void *)(lVar3 + 0x10),(ulonglong)*(uint *)(lVar3 + 8));
          }
        }
      }
      RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,lVar3);
    }
  }
  return uVar2;
}



===== NtPnpInitializeInputPropertyData @ 14001eb50 =====

uint NtPnpInitializeInputPropertyData
               (undefined8 param_1,undefined4 param_2,short *param_3,uint param_4,
               undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  longlong local_res18 [2];
  undefined4 *in_stack_00000050;
  
  uVar2 = 0;
  local_res18[0] = 0;
  memset(in_stack_00000050,0,0x48);
  *in_stack_00000050 = 0x48;
  in_stack_00000050[2] = param_2;
  in_stack_00000050[0x11] = 0x14;
  uVar1 = param_5[1];
  *(undefined8 *)(in_stack_00000050 + 7) = *param_5;
  *(undefined8 *)(in_stack_00000050 + 9) = uVar1;
  in_stack_00000050[0xb] = *(undefined4 *)(param_5 + 2);
  *(short **)(in_stack_00000050 + 4) = param_3;
  if (param_3 != (short *)0x0) {
    uVar2 = RtlStringCchLengthW(param_3,(ulonglong)(param_4 >> 1),local_res18);
    if (-1 < (int)uVar2) {
      in_stack_00000050[6] = (int)local_res18[0] * 2 + 2;
    }
  }
  return uVar2;
}



===== NtPnpInitializeInputRegistryData @ 14001ebf8 =====

uint NtPnpInitializeInputRegistryData
               (undefined8 param_1,undefined8 param_2,short *param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 *param_9)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = param_9;
  uVar1 = 0;
  param_9 = (undefined4 *)0x0;
  puVar2[3] = 0;
  puVar2[6] = 0;
  puVar2[0xb] = 0;
  puVar2[1] = 0;
  puVar2[9] = 0;
  *puVar2 = 0x30;
  puVar2[2] = 4;
  puVar2[7] = 1;
  puVar2[8] = param_6;
  puVar2[10] = 0x10;
  *(short **)(puVar2 + 4) = param_3;
  if (param_3 != (short *)0x0) {
    uVar1 = RtlStringCchLengthW(param_3,0x7fffffff,(longlong *)&param_9);
    if (-1 < (int)uVar1) {
      puVar2[6] = (int)param_9 * 2 + 2;
    }
  }
  return uVar1;
}



===== NtPnpInitializeLibrary @ 14001ec84 =====

undefined8 NtPnpInitializeLibrary(void)

{
  undefined8 uVar1;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_34 = 0;
  local_1c = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (NtPnpDeviceApiDriverHandle == 0) {
    RtlInitUnicodeString(&local_58,L"\\Device\\DeviceApi\\CMApi");
    local_28 = &local_58;
    local_30 = 0;
    local_20 = 0;
    local_38 = 0x30;
    local_18 = 0;
    uStack_10 = 0;
    uVar1 = NtCreateFile(&NtPnpDeviceApiDriverHandle,0x80000000,&local_38,&local_48,0,0,0,1,0,0,0);
  }
  else {
    uVar1 = 0xc0000510;
  }
  return uVar1;
}



===== NtPnpOpenDeviceInterfaceKey @ 14001ed48 =====

uint NtPnpOpenDeviceInterfaceKey
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined8 in_stack_ffffffffffffff78;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 in_stack_ffffffffffffff90;
  undefined4 in_stack_ffffffffffffff94;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (NtPnpDeviceApiDriverHandle == 0) {
    uVar1 = 0xc0000429;
  }
  else if ((param_1 == 0) || (param_4 == (undefined8 *)0x0)) {
    uVar1 = 0xc000000d;
  }
  else {
    *param_4 = 0;
    uVar1 = NtPnpInitializeInputRegistryData
                      (param_1,param_2,(short *)param_1,param_4,in_stack_ffffffffffffff78,2,
                       in_stack_ffffffffffffff88,
                       CONCAT44(in_stack_ffffffffffffff94,in_stack_ffffffffffffff90),
                       (undefined4 *)&local_38);
    if (-1 < (int)uVar1) {
      uVar1 = NtDeviceIoControlFile
                        (NtPnpDeviceApiDriverHandle,0,0,0,&local_48,0x470853,&local_38,0x30,
                         &local_58,0x10);
      if ((-1 < (int)uVar1) && (uVar1 = local_58._4_4_, -1 < local_58)) {
        *param_4 = uStack_50;
      }
    }
  }
  return uVar1;
}



===== RtlStringCchCopyExW @ 14001ee3c =====

uint RtlStringCchCopyExW(short *param_1,ulonglong param_2,longlong param_3,longlong *param_4,
                        ulonglong *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  short *psVar3;
  longlong local_18 [2];
  
  if (param_2 - 1 < 0x7fffffff) {
    local_18[0] = 0;
    uVar1 = RtlStringCopyWorkerW(param_1,param_2,local_18,param_3);
    uVar2 = param_2 - local_18[0];
    psVar3 = param_1 + local_18[0];
    if ((int)uVar1 < 0) {
      if ((param_2 & 0x7fffffffffffffff) != 0) {
        *param_1 = 0;
        uVar2 = param_2 & 0x7fffffffffffffff;
        psVar3 = param_1;
      }
      if (uVar1 != 0x80000005) {
        return uVar1;
      }
    }
    if (param_4 != (longlong *)0x0) {
      *param_4 = (longlong)psVar3;
    }
    if (param_5 != (ulonglong *)0x0) {
      *param_5 = uVar2;
    }
  }
  else {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return uVar1;
}



===== RtlStringCopyWorkerW @ 14001eefc =====

uint RtlStringCopyWorkerW(short *param_1,longlong param_2,longlong *param_3,longlong param_4)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar5 = 0;
  if (param_2 != 0) {
    lVar2 = 0x7ffffffe;
    lVar4 = param_4 - (longlong)param_1;
    do {
      if ((lVar2 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      lVar2 = lVar2 + -1;
      param_1 = param_1 + 1;
      lVar5 = lVar5 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar3 = param_1 + -1;
  if (param_2 != 0) {
    psVar3 = param_1;
  }
  *psVar3 = 0;
  if (param_3 != (longlong *)0x0) {
    lVar2 = lVar5 + -1;
    if (param_2 != 0) {
      lVar2 = lVar5;
    }
    *param_3 = lVar2;
  }
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== BaseSetLastNTError @ 14001ef78 =====

undefined4 BaseSetLastNTError(void)

{
  undefined4 uVar1;
  
  uVar1 = RtlNtStatusToDosError();
  RtlSetLastWin32Error(uVar1);
  return uVar1;
}



===== BasepMapModuleHandle @ 14001efac =====

ulonglong BasepMapModuleHandle(ulonglong param_1)

{
  ulonglong uVar1;
  
  if (param_1 == 0) {
    return *(ulonglong *)((longlong)ProcessEnvironmentBlock + 0x10);
  }
  uVar1 = 0;
  if ((param_1 & 3) == 0) {
    uVar1 = param_1;
  }
  return uVar1;
}



===== __GSHandlerCheck @ 14001efd8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001effc =====

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



===== __GSHandlerCheck_SEH @ 14001f060 =====

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



===== __chkstk @ 14001f0eb =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014001f0eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== memcpy @ 14001f0f7 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001f0f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== memmove @ 14001f103 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001f103. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



===== memset @ 14001f10f =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001f10f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== __security_check_cookie @ 14001f130 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== SwitchToFiberContext @ 14001f160 =====

void SwitchToFiberContext(void *param_1)

{
  undefined8 *puVar1;
  void *pvVar2;
  undefined8 unaff_RBX;
  undefined8 unaff_RBP;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  undefined8 unaff_R12;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  longlong in_SSP;
  undefined2 in_FPUControlWord;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  undefined4 unaff_XMM11_Da;
  undefined4 unaff_XMM11_Db;
  undefined4 unaff_XMM11_Dc;
  undefined4 unaff_XMM11_Dd;
  undefined4 unaff_XMM12_Da;
  undefined4 unaff_XMM12_Db;
  undefined4 unaff_XMM12_Dc;
  undefined4 unaff_XMM12_Dd;
  undefined4 unaff_XMM13_Da;
  undefined4 unaff_XMM13_Db;
  undefined4 unaff_XMM13_Dc;
  undefined4 unaff_XMM13_Dd;
  undefined4 unaff_XMM14_Da;
  undefined4 unaff_XMM14_Db;
  undefined4 unaff_XMM14_Dc;
  undefined4 unaff_XMM14_Dd;
  undefined4 unaff_XMM15_Da;
  undefined4 unaff_XMM15_Db;
  undefined4 unaff_XMM15_Dc;
  undefined4 unaff_XMM15_Dd;
  undefined8 unaff_retaddr;
  
  pvVar2 = FiberData;
  DeallocationStack = *(void **)((longlong)param_1 + 0x20);
  puVar1 = (undefined8 *)((longlong)FiberData + 0x18);
  FiberData = param_1;
  *puVar1 = StackLimit;
  *(undefined4 *)((longlong)pvVar2 + 0x518) = DAT_ff00001748;
  *(void **)((longlong)pvVar2 + 0x510) = FlsData;
  *(void **)((longlong)pvVar2 + 0x508) = ActivationContextStackPointer;
  *(undefined8 *)((longlong)pvVar2 + 0xc0) = unaff_RBX;
  *(undefined8 *)((longlong)pvVar2 + 0xd0) = unaff_RBP;
  *(undefined8 *)((longlong)pvVar2 + 0xd8) = unaff_RSI;
  *(undefined8 *)((longlong)pvVar2 + 0xe0) = unaff_RDI;
  *(undefined8 *)((longlong)pvVar2 + 0x108) = unaff_R12;
  *(undefined8 *)((longlong)pvVar2 + 0x110) = unaff_R13;
  *(undefined8 *)((longlong)pvVar2 + 0x118) = unaff_R14;
  *(undefined8 *)((longlong)pvVar2 + 0x120) = unaff_R15;
  *(undefined4 *)((longlong)pvVar2 + 0x230) = unaff_XMM6_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x234) = unaff_XMM6_Db;
  *(undefined4 *)((longlong)pvVar2 + 0x238) = unaff_XMM6_Dc;
  *(undefined4 *)((longlong)pvVar2 + 0x23c) = unaff_XMM6_Dd;
  *(undefined4 *)((longlong)pvVar2 + 0x240) = unaff_XMM7_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x244) = unaff_XMM7_Db;
  *(undefined4 *)((longlong)pvVar2 + 0x248) = unaff_XMM7_Dc;
  *(undefined4 *)((longlong)pvVar2 + 0x24c) = unaff_XMM7_Dd;
  *(undefined4 *)((longlong)pvVar2 + 0x250) = unaff_XMM8_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x254) = unaff_XMM8_Db;
  *(undefined4 *)((longlong)pvVar2 + 600) = unaff_XMM8_Dc;
  *(undefined4 *)((longlong)pvVar2 + 0x25c) = unaff_XMM8_Dd;
  *(undefined4 *)((longlong)pvVar2 + 0x260) = unaff_XMM9_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x264) = unaff_XMM9_Db;
  *(undefined4 *)((longlong)pvVar2 + 0x268) = unaff_XMM9_Dc;
  *(undefined4 *)((longlong)pvVar2 + 0x26c) = unaff_XMM9_Dd;
  *(undefined4 *)((longlong)pvVar2 + 0x270) = unaff_XMM10_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x274) = unaff_XMM10_Db;
  *(undefined4 *)((longlong)pvVar2 + 0x278) = unaff_XMM10_Dc;
  *(undefined4 *)((longlong)pvVar2 + 0x27c) = unaff_XMM10_Dd;
  *(undefined4 *)((longlong)pvVar2 + 0x280) = unaff_XMM11_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x284) = unaff_XMM11_Db;
  *(undefined4 *)((longlong)pvVar2 + 0x288) = unaff_XMM11_Dc;
  *(undefined4 *)((longlong)pvVar2 + 0x28c) = unaff_XMM11_Dd;
  *(undefined4 *)((longlong)pvVar2 + 0x290) = unaff_XMM12_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x294) = unaff_XMM12_Db;
  *(undefined4 *)((longlong)pvVar2 + 0x298) = unaff_XMM12_Dc;
  *(undefined4 *)((longlong)pvVar2 + 0x29c) = unaff_XMM12_Dd;
  *(undefined4 *)((longlong)pvVar2 + 0x2a0) = unaff_XMM13_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x2a4) = unaff_XMM13_Db;
  *(undefined4 *)((longlong)pvVar2 + 0x2a8) = unaff_XMM13_Dc;
  *(undefined4 *)((longlong)pvVar2 + 0x2ac) = unaff_XMM13_Dd;
  *(undefined4 *)((longlong)pvVar2 + 0x2b0) = unaff_XMM14_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x2b4) = unaff_XMM14_Db;
  *(undefined4 *)((longlong)pvVar2 + 0x2b8) = unaff_XMM14_Dc;
  *(undefined4 *)((longlong)pvVar2 + 700) = unaff_XMM14_Dd;
  *(undefined4 *)((longlong)pvVar2 + 0x2c0) = unaff_XMM15_Da;
  *(undefined4 *)((longlong)pvVar2 + 0x2c4) = unaff_XMM15_Db;
  *(undefined4 *)((longlong)pvVar2 + 0x2c8) = unaff_XMM15_Dc;
  *(undefined4 *)((longlong)pvVar2 + 0x2cc) = unaff_XMM15_Dd;
  *(undefined4 *)((longlong)pvVar2 + 100) = MXCSR;
  *(undefined2 *)((longlong)pvVar2 + 0x130) = in_FPUControlWord;
  *(undefined8 *)((longlong)pvVar2 + 0x128) = unaff_retaddr;
  *(BADSPACEBASE **)((longlong)pvVar2 + 200) = register0x00000020;
  StackBase = *(void **)((longlong)param_1 + 0x10);
  StackLimit = *(void **)((longlong)param_1 + 0x18);
  DAT_ff00001748 = *(undefined4 *)((longlong)param_1 + 0x518);
  FlsData = *(void **)((longlong)param_1 + 0x510);
  ActivationContextStackPointer = *(void **)((longlong)param_1 + 0x508);
  if (*(longlong *)((longlong)param_1 + 0x528) != 0) {
    ShadowStackPush8B(**(ulonglong **)((longlong)param_1 + 0x528) & 0xfffffffffffffffe);
    *(longlong *)((longlong)pvVar2 + 0x528) = in_SSP + -8;
  }
  MXCSR = *(undefined4 *)((longlong)param_1 + 100);
  return;
}



===== _guard_dispatch_icall @ 14001f390 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14001f3c0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001f3c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14001f3f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== wmain$filt$0 @ 14001f400 =====

void wmain_filt_0(undefined8 *param_1)

{
  SmpUnhandledExceptionFilter(param_1);
  return;
}



===== wmain$fin$1 @ 14001f416 =====

void wmain_fin_1(undefined8 param_1,longlong param_2)

{
  SmpLogFailureString(0x14002a714,0x263,*(longlong *)(param_2 + 0x50),
                      *(undefined4 *)(param_2 + 0x228));
                    /* WARNING: Subroutine does not return */
  SmpTerminate(param_2 + 0x220,1,4);
}



===== SmpApiCallback$filt$0 @ 14001f460 =====

void SmpApiCallback_filt_0(undefined8 *param_1)

{
  SmpUnhandledExceptionFilter(param_1);
  return;
}



===== SmpCreateInitialSession$filt$0 @ 14001f47c =====

void SmpCreateInitialSession_filt_0(undefined8 *param_1)

{
  SmpUnhandledExceptionFilter(param_1);
  return;
}



===== GetLongPathNameW$fin$0 @ 14001f498 =====

void GetLongPathNameW_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x58) != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                *(undefined8 *)(param_2 + 0x58));
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                *(undefined8 *)(param_2 + 0x48));
  }
  return;
}



===== FindClose$filt$0 @ 14001f4fc =====

bool FindClose_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 != -0x3fffff03;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 140020010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


