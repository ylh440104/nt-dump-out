
===== _tlgCreate1Sz_wchar_t @ 140001010 =====

void _tlgCreate1Sz_wchar_t(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_2 == 0) {
    *(undefined4 *)((longlong)param_1 + 0xc) = 0;
    *param_1 = (longlong)L"";
    *(undefined4 *)(param_1 + 1) = 2;
    return;
  }
  lVar2 = -1;
  do {
    lVar1 = lVar2 * 2;
    lVar2 = lVar2 + 1;
  } while (*(short *)(param_2 + 2 + lVar1) != 0);
  *param_1 = param_2;
  *(int *)(param_1 + 1) = (int)lVar2 * 2 + 2;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  return;
}



===== SvchostTelemetryTimerCallback @ 140001070 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SvchostTelemetryTimerCallback(void)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  int iVar3;
  ULONGLONG UVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong local_res20;
  HANDLE local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  code *pcStack_50;
  ulonglong *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  UVar4 = GetTickCount64();
  if (UVar4 - _g_LastQueryHeapInfoTime < 3000) {
    UVar4 = GetTickCount64();
  }
  else {
    _g_LastQueryHeapInfoTime = UVar4;
    if (ServiceCount < 2) {
      local_68 = (HANDLE)0x0;
      uStack_60 = 0;
      local_18 = 0;
      local_58 = 0;
      pcStack_50 = (code *)0x0;
      local_res20 = 0;
      local_48 = (ulonglong *)0x0;
      uStack_40 = 0;
      local_38 = 0;
      uStack_30 = 0;
      local_28 = 0;
      uStack_20 = 0;
      local_68 = GetCurrentProcess();
      local_58 = CONCAT44(local_58._4_4_,0x80000000);
      pcStack_50 = QueryHeapCallback;
      local_48 = &local_res20;
      iVar3 = RtlQueryHeapInformation(0,2,&local_68,0x58,0);
      lVar2 = ServiceArray;
      if (-1 < iVar3) {
        if (*(longlong *)(ServiceArray + 0x40) == 0) {
          uVar6 = local_res20;
        }
        else {
          uVar6 = (local_res20 + *(longlong *)(ServiceArray + 0x40) * 4) * 0x14;
          auVar1._8_8_ = 0;
          auVar1._0_8_ = uVar6;
          lVar5 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8);
          uVar6 = (uVar6 - lVar5 >> 1) + lVar5 >> 6;
        }
        *(ulonglong *)(ServiceArray + 0x40) = uVar6;
        if (*(ulonglong *)(lVar2 + 0x38) < local_res20) {
          *(ulonglong *)(lVar2 + 0x38) = local_res20;
        }
        *(ulonglong *)(lVar2 + 0x48) = local_res20;
      }
    }
    else {
      iVar3 = QueryMultipleServicesHeapInformation();
    }
    UVar4 = GetTickCount64();
    if (iVar3 < 0) {
      return;
    }
  }
  if (21600000 < UVar4 - _g_LastTelemetryUploadTime) {
    DoSvchostHeapInfoTelemetry();
    TelemetryState = 0;
    _g_LastTelemetryUploadTime = UVar4;
  }
  return;
}



===== QueryMultipleServicesHeapInformation @ 140001210 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int QueryMultipleServicesHeapInformation(void)

{
  ulonglong uVar1;
  undefined1 auVar2 [16];
  int iVar3;
  longlong lVar4;
  ulonglong *lpMem;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 auStack_268 [32];
  code *local_248;
  undefined8 local_240;
  SIZE_T local_238;
  ulonglong local_230 [63];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_268;
  local_238 = 0x1e0;
  local_230[2] = 0;
  local_230[0] = 0;
  local_230[1] = 0;
  lpMem = local_230 + 3;
  while( true ) {
    *lpMem = 1;
    local_248 = (code *)&local_238;
    lpMem[2] = 0;
    lpMem[3] = 0;
    lpMem[4] = 0;
    lpMem[5] = 0;
    lpMem[1] = 0xffffffffffffffff;
    iVar3 = RtlQueryHeapInformation(0,4,lpMem,local_238);
    if (iVar3 != -0x3fffffdd) break;
    if (lpMem != local_230 + 3) {
      HeapFree(g_hHeap,0,lpMem);
    }
    lpMem = HeapAlloc(g_hHeap,0,local_238);
    if (lpMem == (ulonglong *)0x0) {
      return -0x3fffffe9;
    }
  }
  if (-1 < iVar3) {
    if ((*lpMem & 0x10000) == 0) {
      iVar3 = -0x3fffff45;
    }
    else {
      local_248 = (code *)0x0;
      _o_qsort_s(lpMem + 3,lpMem[2],0x18,CompareHeapTags);
      uVar5 = 0;
      if (ServiceCount != 0) {
        do {
          lVar6 = (ulonglong)uVar5 * 0x60;
          if (*(int *)(lVar6 + 0x30 + ServiceArray) != 0) {
            local_240 = 0;
            local_230[1] = 0;
            local_230[0] = (ulonglong)*(uint *)(lVar6 + 0x34 + ServiceArray);
            local_248 = CompareHeapTags;
            lVar4 = bsearch_s(local_230,lpMem + 3,lpMem[2],0x18);
            if (lVar4 != 0) {
              uVar1 = *(ulonglong *)(lVar4 + 0x10);
              lVar6 = ServiceArray + lVar6;
              if (*(longlong *)(lVar6 + 0x40) == 0) {
                uVar7 = uVar1;
              }
              else {
                uVar7 = (uVar1 + *(longlong *)(lVar6 + 0x40) * 4) * 0x14;
                auVar2._8_8_ = 0;
                auVar2._0_8_ = uVar7;
                lVar4 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar2,8);
                uVar7 = (uVar7 - lVar4 >> 1) + lVar4 >> 6;
              }
              *(ulonglong *)(lVar6 + 0x40) = uVar7;
              if (*(ulonglong *)(lVar6 + 0x38) < uVar1) {
                *(ulonglong *)(lVar6 + 0x38) = uVar1;
              }
              *(ulonglong *)(lVar6 + 0x48) = uVar1;
            }
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < ServiceCount);
      }
    }
  }
  if (lpMem == local_230 + 3) {
    return iVar3;
  }
  HeapFree(g_hHeap,0,lpMem);
  return iVar3;
}



===== DoSvchostHeapInfoTelemetry @ 140001490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DoSvchostHeapInfoTelemetry(void)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  int iVar9;
  undefined1 auStackY_1d8 [32];
  undefined1 local_1a8;
  undefined1 local_1a7 [3];
  int local_1a4;
  int local_1a0 [2];
  undefined8 local_198;
  longlong local_190;
  longlong local_188;
  longlong local_180 [3];
  longlong local_168;
  longlong local_160;
  EVENT_DESCRIPTOR local_158;
  _EVENT_DATA_DESCRIPTOR local_148;
  undefined *local_138;
  undefined4 local_130;
  undefined4 local_12c;
  longlong *local_128;
  undefined8 local_120;
  wchar_t *local_118;
  int local_110;
  undefined4 local_10c;
  longlong *local_108;
  undefined8 local_100;
  longlong *local_f8;
  undefined8 local_f0;
  longlong *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  int *local_c8;
  undefined8 local_c0;
  _EVENT_DATA_DESCRIPTOR local_b8 [2];
  undefined8 *local_98;
  undefined8 local_90;
  longlong local_88 [2];
  longlong *local_78;
  undefined8 local_70;
  longlong *local_68;
  undefined8 local_60;
  longlong *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1d8;
  uVar7 = (ulonglong)ServiceCount;
  uVar6 = 0;
  if (ServiceCount != 0) {
    uVar4 = DAT_14000e018;
    iVar9 = TelemetryState;
    do {
      plVar8 = (longlong *)(ServiceArray + uVar6 * 0x60);
      if (((int)plVar8[6] != 0) && (plVar8[8] != 0)) {
        if ((uint)((ulonglong)plVar8[8] >> 10) < g_HeapReportingThresholdKb) {
          if (5 < DAT_14000e000) {
            if (((_DAT_14000e010 & 0x200000000000) == 0) || ((uVar4 & 0x200000000000) != uVar4)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              local_128 = local_180 + 1;
              local_180[1] = 0x1000000;
              local_120 = 8;
              local_118 = (wchar_t *)*plVar8;
              if (local_118 == (wchar_t *)0x0) {
                local_118 = L"";
                local_110 = 2;
              }
              else {
                lVar3 = -1;
                do {
                  lVar2 = lVar3 + 1;
                  lVar3 = lVar3 + 1;
                } while (local_118[lVar2] != L'\0');
                local_110 = (int)lVar3 * 2 + 2;
              }
              local_1a7[0] = (int)uVar7 == 1;
              local_10c = 0;
              local_180[2] = plVar8[8];
              local_108 = local_180 + 2;
              local_100 = 8;
              local_168 = plVar8[7];
              local_f8 = &local_168;
              local_f0 = 8;
              local_160 = plVar8[9];
              local_e0 = 8;
              local_e8 = &local_160;
              local_d0 = 1;
              local_d8 = local_1a7;
              local_c8 = local_1a0;
              local_158.Level = '\x05';
              local_158.Opcode = '\0';
              local_158.Task = 0;
              local_148.Ptr = (ULONGLONG)PTR_DAT_14000e008;
              local_c0 = 4;
              local_158.Id = 0;
              local_158.Version = '\0';
              local_158.Channel = '\v';
              local_158.Keyword = 0x200000000000;
              local_148.Size = (ULONG)*(ushort *)PTR_DAT_14000e008;
              local_148.Reserved = 2;
              local_138 = &DAT_14000a94b;
              local_130 = 0x7b;
              local_12c = 1;
              local_1a0[1] = 0x4be;
              local_1a0[0] = iVar9;
              EventWriteTransfer(DAT_14000e020,&local_158,(LPCGUID)0x0,(LPCGUID)0x0,9,&local_148);
LAB_14000171e:
              uVar7 = (ulonglong)ServiceCount;
              uVar4 = DAT_14000e018;
              iVar9 = TelemetryState;
            }
          }
        }
        else if (5 < DAT_14000e000) {
          if (((_DAT_14000e010 & 0x400000000000) == 0) || ((uVar4 & 0x400000000000) != uVar4)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          if (bVar1) {
            local_98 = &local_198;
            local_198 = 0x1000000;
            local_90 = 8;
            _tlgCreate1Sz_wchar_t(local_88,*plVar8);
            local_190 = plVar8[8];
            local_78 = &local_190;
            local_1a8 = (int)uVar7 == 1;
            local_70 = 8;
            local_188 = plVar8[7];
            local_68 = &local_188;
            local_60 = 8;
            local_180[0] = plVar8[9];
            local_58 = local_180;
            local_48 = &local_1a8;
            local_38 = &local_1a4;
            local_50 = 8;
            local_40 = 1;
            local_30 = 4;
            local_1a4 = iVar9;
            _tlgWriteTransfer_EventWriteTransfer(local_190,&DAT_14000a9c7,uVar7,plVar8,9,local_b8);
            goto LAB_14000171e;
          }
        }
        if (iVar9 == 0) {
          *(undefined8 *)(uVar6 * 0x60 + 0x38 + ServiceArray) = 0;
          uVar4 = DAT_14000e018;
        }
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < (uint)uVar7);
  }
  return;
}



===== _tlgWriteTransfer_EventWriteTransfer @ 140001870 =====

void _tlgWriteTransfer_EventWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,ULONG param_5
               ,PEVENT_DATA_DESCRIPTOR param_6)

{
  EVENT_DESCRIPTOR local_18;
  
  local_18._0_4_ = (uint)*param_2 << 0x18;
  local_18._4_4_ = ZEXT24(*(ushort *)(param_2 + 1));
  local_18.Keyword = *(ULONGLONG *)(param_2 + 3);
  param_6->Ptr = (ULONGLONG)PTR_DAT_14000e008;
  param_6->Size = (uint)*(ushort *)PTR_DAT_14000e008;
  param_6[1].Ptr = (ULONGLONG)(param_2 + 0xb);
  param_6->Reserved = 2;
  param_6[1].Size = (uint)*(ushort *)(param_2 + 0xb);
  param_6[1].Reserved = 1;
  EventWriteTransfer(DAT_14000e020,&local_18,(LPCGUID)0x0,(LPCGUID)0x0,param_5,param_6);
  return;
}



===== _tlgEnableCallback @ 140001920 =====

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



===== QueryServiceHeapInformation @ 1400019a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int QueryServiceHeapInformation(void)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  int iVar3;
  ULONGLONG UVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong local_res8 [4];
  HANDLE local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  code *pcStack_50;
  ulonglong *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  UVar4 = GetTickCount64();
  if (UVar4 - _g_LastQueryHeapInfoTime < 3000) {
    return 0x80;
  }
  _g_LastQueryHeapInfoTime = UVar4;
  if (1 < ServiceCount) {
    iVar3 = QueryMultipleServicesHeapInformation();
    return iVar3;
  }
  local_res8[0] = 0;
  local_68 = (HANDLE)0x0;
  uStack_60 = 0;
  local_18 = 0;
  local_58 = 0;
  pcStack_50 = (code *)0x0;
  local_48 = (ulonglong *)0x0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_68 = GetCurrentProcess();
  local_58 = CONCAT44(local_58._4_4_,0x80000000);
  pcStack_50 = QueryHeapCallback;
  local_48 = local_res8;
  iVar3 = RtlQueryHeapInformation(0,2,&local_68,0x58,0);
  lVar2 = ServiceArray;
  if (-1 < iVar3) {
    if (*(longlong *)(ServiceArray + 0x40) == 0) {
      uVar6 = local_res8[0];
    }
    else {
      uVar6 = (local_res8[0] + *(longlong *)(ServiceArray + 0x40) * 4) * 0x14;
      auVar1._8_8_ = 0;
      auVar1._0_8_ = uVar6;
      lVar5 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8);
      uVar6 = (uVar6 - lVar5 >> 1) + lVar5 >> 6;
    }
    *(ulonglong *)(ServiceArray + 0x40) = uVar6;
    if (*(ulonglong *)(lVar2 + 0x38) < local_res8[0]) {
      *(ulonglong *)(lVar2 + 0x38) = local_res8[0];
    }
    *(ulonglong *)(lVar2 + 0x48) = local_res8[0];
  }
  return iVar3;
}



===== wmain @ 140001b00 =====

int __cdecl wmain(int _Argc,wchar_t **_Argv,wchar_t **_Env)

{
  code *pcVar1;
  int iVar2;
  
  SvcHostMain();
  pcVar1 = (code *)swi(3);
  iVar2 = (*pcVar1)();
  return iVar2;
}



===== SvcHostMain @ 140001b10 =====

void SvcHostMain(void)

{
  longlong lVar1;
  int iVar2;
  SERVICE_TABLE_ENTRYW *lpServiceStartTable;
  longlong lVar3;
  undefined1 auStackY_88 [32];
  EVENT_DESCRIPTOR local_50;
  _EVENT_DATA_DESCRIPTOR local_40;
  undefined *local_30;
  undefined4 local_28;
  undefined4 local_24;
  LPWSTR local_20;
  int local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  lpServiceStartTable = (SERVICE_TABLE_ENTRYW *)InitializeSvcHostLib();
  if (lpServiceStartTable != (SERVICE_TABLE_ENTRYW *)0x0) {
    I_RegisterSvchostNotificationCallback(SvcHostNotificationCallback);
    StartServiceCtrlDispatcherW(lpServiceStartTable);
    if (ShouldCoUninit != 0) {
      WaitForServiceDllsToUnload();
      CoUninitialize();
    }
  }
  if (g_TelemetryTimer != 0) {
    iVar2 = TpSetTimerEx(g_TelemetryTimer,0);
    if (iVar2 == 0) {
      TpWaitForTimer(g_TelemetryTimer,1);
    }
    TpReleaseTimer();
    g_TelemetryTimer = 0;
  }
  if (5 < DAT_14000e000) {
    local_20 = GetCommandLineW();
    if (local_20 == (LPWSTR)0x0) {
      local_20 = L"";
      local_18 = 2;
    }
    else {
      lVar3 = -1;
      do {
        lVar1 = lVar3 + 1;
        lVar3 = lVar3 + 1;
      } while (local_20[lVar1] != L'\0');
      local_18 = (int)lVar3 * 2 + 2;
    }
    local_50.Level = '\x05';
    local_50.Opcode = '\0';
    local_50.Task = 0;
    local_40.Ptr = (ULONGLONG)PTR_DAT_14000e008;
    local_14 = 0;
    local_50.Id = 0;
    local_50.Version = '\0';
    local_50.Channel = '\v';
    local_50.Keyword = 0;
    local_40.Size = (ULONG)*(ushort *)PTR_DAT_14000e008;
    local_30 = &DAT_14000a5fc;
    local_40.Reserved = 2;
    local_28 = 0x25;
    local_24 = 1;
    EventWriteTransfer(DAT_14000e020,&local_50,(LPCGUID)0x0,(LPCGUID)0x0,3,&local_40);
  }
                    /* WARNING: Subroutine does not return */
  ExitProcess(0);
}



===== InitializeSvcHostLib @ 140001cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * InitializeSvcHostLib(void)

{
  undefined8 uVar1;
  bool bVar2;
  BOOL BVar3;
  LPWSTR pWVar4;
  undefined8 *lpMem;
  HANDLE pvVar5;
  undefined8 *puVar6;
  undefined7 extraout_var;
  undefined8 *puVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  undefined1 auStack_e8 [32];
  longlong local_c8;
  undefined4 local_b8 [4];
  undefined8 local_a8;
  undefined8 uStack_a0;
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  puVar6 = (undefined8 *)0x0;
  local_b8[0] = 1;
  NtSetInformationProcess(0xffffffffffffffff,0x36,local_b8,4);
  SetUnhandledExceptionFilter(SvchostUnhandledExceptionFilter);
  SetErrorMode(1);
  g_hHeap = GetProcessHeap();
  DAT_14000e8f8 = &DllList;
  DllList = &DllList;
  InitializeSRWLock((PSRWLOCK)&ListLock);
  InitializeSRWLock((PSRWLOCK)&g_pSvchostSharedGlobalsLock);
  RegDisablePredefinedCacheEx();
  EtwEventRegister(&MS_Services_Svchost_Provider,0,0,&PerfRegHandle);
  if ((DAT_7ffe02f0 & 0x20) != 0) {
    pvVar5 = GetCurrentProcess();
    BVar3 = SetProcessAffinityUpdateMode(pvVar5,1);
    if (BVar3 == 0) goto LAB_140001fd2;
  }
  pWVar4 = GetCommandLineW();
  lpMem = BuildCommandOptions(pWVar4);
  if (lpMem != (undefined8 *)0x0) {
    local_a8 = 0;
    uStack_a0 = 0x100000000;
    local_98[0] = L'\0';
    local_98[1] = L'\0';
    local_98[2] = L'\0';
    local_98[3] = L'\0';
    local_98[4] = L'\0';
    local_98[5] = L'\0';
    local_98[6] = L'\0';
    local_98[7] = L'\0';
    local_98[8] = L'\0';
    local_98[9] = L'\0';
    local_98[10] = L'\0';
    local_98[0xb] = L'\0';
    local_98[0xc] = L'\0';
    local_98[0xd] = L'\0';
    local_98[0xe] = L'\0';
    local_98[0xf] = L'\0';
    local_98[0x10] = L'\0';
    local_98[0x11] = L'\0';
    local_98[0x12] = L'\0';
    local_98[0x13] = L'\0';
    local_98[0x14] = L'\0';
    local_98[0x15] = L'\0';
    local_98[0x16] = L'\0';
    local_98[0x17] = L'\0';
    local_98[0x18] = L'\0';
    local_98[0x19] = L'\0';
    local_98[0x1a] = L'\0';
    local_98[0x1b] = L'\0';
    local_98[0x1c] = L'\0';
    local_98[0x1d] = L'\0';
    local_98[0x1e] = L'\0';
    local_98[0x1f] = L'\0';
    local_98[0x20] = L'\0';
    local_98[0x21] = L'\0';
    local_98[0x22] = L'\0';
    local_98[0x23] = L'\0';
    local_98[0x24] = L'\0';
    local_98[0x25] = L'\0';
    local_98[0x26] = L'\0';
    local_98[0x27] = L'\0';
    local_98[0x28] = L'\0';
    local_98[0x29] = L'\0';
    local_98[0x2a] = L'\0';
    local_98[0x2b] = L'\0';
    local_98[0x2c] = L'\0';
    local_98[0x2d] = L'\0';
    local_98[0x2e] = L'\0';
    local_98[0x2f] = L'\0';
    local_98[0x30] = L'\0';
    local_98[0x31] = L'\0';
    local_98[0x32] = L'\0';
    local_98[0x33] = L'\0';
    local_98[0x34] = L'\0';
    local_98[0x35] = L'\0';
    local_98[0x36] = L'\0';
    local_98[0x37] = L'\0';
    local_98[0x38] = L'\0';
    local_98[0x39] = L'\0';
    local_98[0x3a] = L'\0';
    local_98[0x3b] = L'\0';
    local_98[0x3c] = L'\0';
    local_98[0x3d] = L'\0';
    local_98[0x3e] = L'\0';
    local_98[0x3f] = L'\0';
    if (lpMem[4] == 0) {
      StringCchPrintfW(local_98,0x40,L"[%ws]",lpMem[3]);
    }
    else {
      local_c8 = lpMem[4];
      StringCchPrintfW(local_98,0x40,L"[%ws] [%ws]",lpMem[3]);
    }
    pvVar5 = GetCurrentProcess();
    NtSetInformationProcess(pvVar5,0x52,&local_a8);
    BuildServiceArray(pvVar5,(longlong)lpMem);
    if ((ServiceArray != (undefined8 *)0x0) && (ServiceCount != 0)) {
      puVar6 = HeapAlloc(g_hHeap,8,(ulonglong)(ServiceCount + 1) << 4);
      if ((puVar6 != (undefined8 *)0x0) && (ServiceCount != 0)) {
        uVar9 = (ulonglong)ServiceCount;
        puVar7 = puVar6;
        puVar8 = ServiceArray;
        do {
          uVar1 = *puVar8;
          puVar8 = puVar8 + 0xc;
          *puVar7 = uVar1;
          puVar7[1] = ServiceStarter;
          puVar7 = puVar7 + 2;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      if ((puVar6 != (undefined8 *)0x0) &&
         (bVar2 = CallPerInstanceInitFunctions((longlong)lpMem),
         (int)CONCAT71(extraout_var,bVar2) == 0)) {
LAB_140001fd2:
                    /* WARNING: Subroutine does not return */
        ExitProcess(1);
      }
    }
    if ((LPVOID)lpMem[0xf] != (LPVOID)0x0) {
      HeapFree(g_hHeap,0,(LPVOID)lpMem[0xf]);
    }
    HeapFree(g_hHeap,0,lpMem);
  }
  return puVar6;
}



===== WaitForServiceDllsToUnload @ 140001ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WaitForServiceDllsToUnload(void)

{
  BOOL BVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStackY_98 [32];
  DWORD local_68 [4];
  _EVENT_DATA_DESCRIPTOR local_58 [2];
  longlong local_38 [2];
  DWORD *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar4 = 0;
  if (ServiceCount != 0) {
    do {
      plVar5 = (longlong *)(uVar4 * 0x60 + ServiceArray);
      AcquireSRWLockExclusive((PSRWLOCK)(plVar5 + 4));
      if (((plVar5[1] != 0) && (*(longlong *)(plVar5[1] + 0x10) != 0)) && ((int)plVar5[0xb] != 0)) {
        do {
          if (*(longlong *)(plVar5[1] + 0x10) == 0) goto LAB_14000204f;
          uVar7 = 0;
          uVar6 = 5000;
          BVar1 = SleepConditionVariableSRW
                            ((PCONDITION_VARIABLE)(plVar5 + 5),(PSRWLOCK)(plVar5 + 4),5000,0);
        } while (BVar1 != 0);
        if (5 < DAT_14000e000) {
          plVar2 = local_38;
          _tlgCreate1Sz_wchar_t(plVar2,*plVar5);
          local_68[0] = GetLastError();
          local_20 = 4;
          local_28 = local_68;
          _tlgWriteTransfer_EventWriteTransfer(plVar2,&DAT_14000a622,uVar6,uVar7,4,local_58);
        }
      }
LAB_14000204f:
      ReleaseSRWLockExclusive((PSRWLOCK)(plVar5 + 4));
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < ServiceCount);
  }
  return;
}



===== StringCchPrintfW @ 140002140 =====

HRESULT __stdcall
StringCchPrintfW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,...)

{
  size_t _Count;
  int iVar1;
  HRESULT HVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (cchDest - 1 < 0x7fffffff) {
    _Count = cchDest - 1;
    HVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf(pszDest,_Count,pszFormat,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      pszDest[_Count] = L'\0';
      HVar2 = -0x7ff8ff86;
    }
    else if ((longlong)iVar1 == _Count) {
      pszDest[_Count] = L'\0';
      return 0;
    }
  }
  else {
    HVar2 = -0x7ff8ffa9;
    if (cchDest != 0) {
      *pszDest = L'\0';
    }
  }
  return HVar2;
}



===== ServiceStarter @ 1400021d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void ServiceStarter(undefined4 param_1,undefined8 *param_2)

{
  LPCWSTR lpString1;
  bool bVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  LSTATUS LVar5;
  undefined7 extraout_var;
  code *pcVar6;
  code **ppcVar7;
  uint uVar8;
  code *pcVar9;
  longlong lVar10;
  code **ppcVar11;
  code **lpType;
  WCHAR *pWVar12;
  undefined1 auStackY_108 [32];
  int local_d4 [2];
  undefined8 local_cc;
  DWORD local_c4;
  int local_c0;
  undefined4 local_bc;
  HKEY local_b8;
  HKEY local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  undefined8 *local_90;
  EVENT_DESCRIPTOR local_88;
  _EVENT_DATA_DESCRIPTOR local_78;
  undefined *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  lpString1 = (LPCWSTR)*param_2;
  uVar8 = 0;
  local_98 = (code *)0x0;
  local_a8 = (code *)0x0;
  local_a0 = (code *)0x0;
  if (ServiceCount != 0) {
    lVar10 = -1;
    local_bc = param_1;
    local_90 = param_2;
    do {
      iVar4 = CompareStringOrdinal
                        (lpString1,-1,*(LPCWSTR *)((ulonglong)uVar8 * 0x60 + ServiceArray),-1,1);
      if (iVar4 == 2) {
        bVar3 = ShouldBreakInForServiceStart(lpString1);
        if ((int)CONCAT71(extraout_var,bVar3) != 0) {
          DebugBreak();
        }
        pWVar12 = (WCHAR *)(ServiceArray + (ulonglong)uVar8 * 0x60);
        if (pWVar12 == (WCHAR *)0x0) {
          return;
        }
        AcquireSRWLockExclusive((PSRWLOCK)(pWVar12 + 0x10));
        lpType = &local_a0;
        ppcVar11 = &local_a8;
        *(int *)(pWVar12 + 0x1a) = (int)SubProcessTag;
        ppcVar7 = &local_98;
        uVar8 = GetServiceMainFunctions(pWVar12,ppcVar7,ppcVar11,(WCHAR *)lpType);
        pcVar9 = local_a0;
        pcVar6 = local_a8;
        if (uVar8 == 0) {
          if ((local_a0 == (code *)0x0) && (local_a8 == (code *)0x0)) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
            AcquireSRWLockExclusive((PSRWLOCK)&g_pSvchostSharedGlobalsLock);
            if (g_pSvchostSharedGlobals == 0) {
              SvchostBuildSharedGlobals();
            }
            ReleaseSRWLockExclusive((PSRWLOCK)&g_pSvchostSharedGlobalsLock);
          }
          *(int *)(pWVar12 + 0x18) = *(int *)(pWVar12 + 0x18) + 1;
          local_cc._0_4_ = 0;
          bVar1 = false;
          local_d4[1] = 0;
          local_cc._4_4_ = 0;
          local_b8 = (HKEY)0x0;
          LVar5 = OpenServiceParametersKey(*(LPCWSTR *)pWVar12,&local_b8);
          if (LVar5 == 0) {
            lpType = (code **)&local_cc;
            local_d4[1] = 4;
            ppcVar11 = (code **)0x0;
            LVar5 = RegQueryValueExW(local_b8,L"ServiceDllUnloadOnStop",(LPDWORD)0x0,(LPDWORD)lpType
                                     ,(LPBYTE)((longlong)&local_cc + 4),(LPDWORD)(local_d4 + 1));
            if (((LVar5 == 0) && ((int)local_cc == 4)) && (bVar1 = false, local_cc._4_4_ != 0)) {
              bVar1 = true;
            }
          }
          if (local_b8 != (HKEY)0x0) {
            RegCloseKey(local_b8);
          }
          if (bVar1) {
            pWVar12[0x2c] = L'\x01';
            pWVar12[0x2d] = L'\0';
          }
          local_c0 = 0;
          bVar1 = false;
          local_c4 = 0;
          local_d4[0] = 0;
          local_b0 = (HKEY)0x0;
          LVar5 = OpenServiceParametersKey(*(LPCWSTR *)pWVar12,&local_b0);
          if (LVar5 == 0) {
            lpType = (code **)&local_c0;
            local_c4 = 4;
            ppcVar11 = (code **)0x0;
            LVar5 = RegQueryValueExW(local_b0,L"LegacyCOMBehavior",(LPDWORD)0x0,(LPDWORD)lpType,
                                     (LPBYTE)local_d4,&local_c4);
            if (((LVar5 == 0) && (local_c0 == 4)) && (bVar1 = false, local_d4[0] != 0)) {
              bVar1 = true;
            }
          }
          if (local_b0 != (HKEY)0x0) {
            RegCloseKey(local_b0);
          }
          if (bVar1) {
            ShouldCoUninit = 0;
          }
          ReleaseSRWLockExclusive((PSRWLOCK)(pWVar12 + 0x10));
          if ((bVar3) && (g_pSvchostSharedGlobals != 0)) {
            if (5 < DAT_14000e000) {
              local_58 = *(wchar_t **)pWVar12;
              if (local_58 == (wchar_t *)0x0) {
                local_58 = L"";
                local_50 = 2;
              }
              else {
                do {
                  lVar2 = lVar10 + 1;
                  lVar10 = lVar10 + 1;
                } while (local_58[lVar2] != L'\0');
                local_50 = (int)lVar10 * 2 + 2;
              }
              local_88.Level = '\x05';
              local_88.Opcode = '\0';
              local_88.Task = 0;
              lpType = (code **)0x0;
              ppcVar11 = (code **)0x0;
              local_78.Ptr = (ULONGLONG)PTR_DAT_14000e008;
              local_4c = 0;
              local_88.Id = 0;
              local_88.Version = '\0';
              local_88.Channel = '\v';
              local_88.Keyword = 0;
              local_78.Size = (ULONG)*(ushort *)PTR_DAT_14000e008;
              local_68 = &DAT_14000a6ec;
              local_5c = 1;
              local_78.Reserved = 2;
              local_60 = 0x20;
              local_d4[0] = 0x4be;
              EventWriteTransfer(DAT_14000e020,&local_88,(LPCGUID)0x0,(LPCGUID)0x0,3,&local_78);
              pcVar9 = local_a0;
              pcVar6 = local_a8;
            }
            if (pcVar9 == (code *)0x0) {
              lVar10 = g_pSvchostSharedGlobals + 8;
            }
            else {
              pcVar6 = pcVar9;
              lVar10 = g_pSvchostSharedGlobals;
            }
            (*pcVar6)(lVar10);
          }
          LogServiceEvent((longlong)lpString1,&SvchostEvt_ServiceMain_Start);
          pcVar6 = local_98;
          (*local_98)(local_bc,local_90);
          ppcVar7 = (code **)&SvchostEvt_ServiceMain_Stop;
          LogServiceEvent((longlong)lpString1,&SvchostEvt_ServiceMain_Stop);
        }
        else {
          ReleaseSRWLockExclusive((PSRWLOCK)(pWVar12 + 0x10));
          pcVar6 = local_98;
        }
        if (pcVar6 == (code *)0x0) {
          AbortHostedService(lpString1,uVar8,ppcVar11,lpType);
          return;
        }
        DecrementDllReferenceCount((longlong *)pWVar12,ppcVar7,ppcVar11,lpType);
        return;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < ServiceCount);
  }
  return;
}



===== GetServiceDllFunction @ 140002610 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

FARPROC GetServiceDllFunction(longlong param_1,char *param_2,WCHAR *param_3,int *param_4)

{
  longlong lVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  HMODULE pHVar6;
  FARPROC pFVar7;
  longlong lVar8;
  char **ppcVar9;
  wchar_t **ppwVar10;
  WCHAR *pWVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined1 auStackY_338 [32];
  int local_308 [2];
  ULONG_PTR local_300;
  undefined8 local_2f8;
  ulonglong local_2f0;
  undefined8 local_2e8;
  ulonglong local_2e0;
  EVENT_DESCRIPTOR local_2d8;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  _EVENT_DATA_DESCRIPTOR local_2b8;
  undefined *local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  wchar_t *local_298;
  int local_290;
  undefined4 local_28c;
  char *local_288;
  int local_280;
  undefined4 local_27c;
  undefined8 *local_278;
  undefined8 local_270;
  ulonglong *local_268;
  undefined8 local_260;
  WCHAR local_258 [264];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_338;
  pFVar7 = (FARPROC)0x0;
  local_300 = 0;
  pWVar11 = param_3;
  BVar2 = ActivateActCtx(*(HANDLE *)(param_1 + 0x28),&local_300);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    uVar12 = 1;
    goto LAB_1400026dc;
  }
  uVar12 = 2;
  uVar14 = 3;
  if (*(longlong *)(param_1 + 0x10) == 0) {
    if (5 < DAT_14000e000) {
      local_298 = *(wchar_t **)(param_1 + 0x18);
      if (local_298 == (wchar_t *)0x0) {
        local_298 = L"";
        local_290 = 2;
      }
      else {
        lVar8 = -1;
        do {
          lVar1 = lVar8 + 1;
          lVar8 = lVar8 + 1;
        } while (local_298[lVar1] != L'\0');
        local_290 = (int)lVar8 * 2 + 2;
      }
      param_4 = (int *)0x0;
      local_2b8.Ptr = (ULONGLONG)PTR_DAT_14000e008;
      local_28c = 0;
      local_2d8.Id = 0;
      local_2d8.Version = '\0';
      local_2d8.Channel = '\v';
      local_2d8.Level = '\x05';
      local_2d8.Opcode = '\0';
      local_2d8.Task = 0;
      local_2d8.Keyword = 0;
      local_2b8.Size = (ULONG)*(ushort *)PTR_DAT_14000e008;
      local_2a8 = &DAT_14000a7f7;
      local_2b8.Reserved = 2;
      local_2a0 = 0x1f;
      local_29c = 1;
      local_308[0] = 0x4be;
      EventWriteTransfer(DAT_14000e020,&local_2d8,(LPCGUID)0x0,(LPCGUID)0x0,3,&local_2b8);
    }
    pWVar11 = (WCHAR *)0x8;
    pHVar6 = LoadLibraryExW(*(LPCWSTR *)(param_1 + 0x18),(HANDLE)0x0,8);
    *(HMODULE *)(param_1 + 0x10) = pHVar6;
    if (pHVar6 != (HMODULE)0x0) goto LAB_14000270a;
    DVar3 = GetLastError();
  }
  else {
LAB_14000270a:
    param_4 = (int *)0xffffffff;
    pWVar11 = (WCHAR *)param_2;
    iVar4 = MultiByteToWideChar(0,0,param_2,-1,local_258,0x104);
    if (iVar4 == 0) {
      DVar3 = GetLastError();
      uVar12 = 3;
    }
    else {
      local_308[0] = 0;
      param_4 = (int *)0x0;
      local_2d8.Id = 0;
      local_2d8.Version = '\0';
      local_2d8.Channel = '\0';
      local_2d8.Level = '\0';
      local_2d8.Opcode = '\0';
      local_2d8.Task = 0;
      local_2d8.Keyword = 0;
      pWVar11 = (WCHAR *)0x20;
      local_2c8 = 0;
      uStack_2c0 = 0;
      iVar4 = NtQuerySystemInformation(0xa4,&local_2d8);
      if ((-1 < iVar4) && (((byte)local_2d8.Id & 0x50) == 0x50)) {
        param_4 = (int *)0x0;
        pWVar11 = (WCHAR *)0x0;
        iVar4 = RtlRunOnceExecuteOnce(&DAT_14000e6e8,LoadWldpLibrary);
        if (iVar4 < 0) {
          uVar5 = RtlNtStatusToDosError(iVar4);
          uVar13 = (ulonglong)uVar5;
          uVar14 = 1;
LAB_1400027b9:
          if ((int)uVar13 == 0) goto LAB_1400027c5;
        }
        else {
          if ((WldpModuleHandle == 0) || (IsAllowedEntryPoint == (code *)0x0)) {
            uVar14 = 2;
          }
          else {
            param_4 = local_308;
            pWVar11 = local_258;
            uVar5 = (*IsAllowedEntryPoint)(1,*(undefined8 *)(param_1 + 0x10));
            uVar13 = (ulonglong)uVar5;
            if ((int)uVar5 < 0) {
              if ((uVar5 & 0x1fff0000) == 0x70000) {
                uVar13 = (ulonglong)(ushort)uVar5;
              }
              goto LAB_1400027b9;
            }
            if (local_308[0] != 0) goto LAB_1400027c5;
            uVar14 = 4;
          }
          uVar13 = 5;
        }
        DVar3 = (DWORD)uVar13;
        if (5 < DAT_14000e000) {
          _tlgCreate1Sz_wchar_t((longlong *)&local_298,*(longlong *)(param_1 + 0x18));
          ppcVar9 = &local_288;
          _tlgCreate1Sz_wchar_t((longlong *)ppcVar9,(longlong)local_258);
          local_278 = &local_2f8;
          local_268 = &local_2f0;
          local_270 = 8;
          local_260 = 8;
          local_2f8 = uVar14;
          local_2f0 = uVar13;
          _tlgWriteTransfer_EventWriteTransfer(ppcVar9,&DAT_14000a817,pWVar11,param_4,6,&local_2b8);
        }
        if (DVar3 != 0) {
          uVar12 = 4;
          goto LAB_1400026c1;
        }
      }
LAB_1400027c5:
      DVar3 = 0;
      pFVar7 = GetProcAddress(*(HMODULE *)(param_1 + 0x10),param_2);
      if (pFVar7 == (FARPROC)0x0) {
        DVar3 = GetLastError();
        uVar12 = 5;
      }
      else {
        uVar12 = 0;
      }
    }
  }
LAB_1400026c1:
  DeactivateActCtx(0,local_300);
LAB_1400026dc:
  if (param_3 != (WCHAR *)0x0) {
    if ((DVar3 != 0) && (5 < DAT_14000e000)) {
      ppwVar10 = &local_298;
      _tlgCreate1Sz_wchar_t((longlong *)ppwVar10,*(longlong *)(param_1 + 0x18));
      if (param_2 == (char *)0x0) {
        param_2 = "";
        local_280 = 1;
      }
      else {
        lVar8 = -1;
        do {
          lVar8 = lVar8 + 1;
        } while (param_2[lVar8] != '\0');
        local_280 = (int)lVar8 + 1;
      }
      local_278 = &local_2e8;
      local_2e0 = (ulonglong)DVar3;
      local_268 = &local_2e0;
      local_27c = 0;
      local_270 = 8;
      local_260 = 8;
      local_2e8 = uVar12;
      local_288 = param_2;
      _tlgWriteTransfer_EventWriteTransfer(ppwVar10,&DAT_14000a793,pWVar11,param_4,6,&local_2b8);
    }
    *(DWORD *)param_3 = DVar3;
  }
  return pFVar7;
}



===== RegQueryDword @ 140002ab0 =====

LSTATUS RegQueryDword(HKEY param_1,LPCWSTR param_2,LPBYTE param_3)

{
  LSTATUS LVar1;
  DWORD local_res20 [2];
  DWORD local_18 [4];
  
  local_res20[0] = 0;
  local_18[0] = 4;
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,local_res20,param_3,local_18);
  if ((LVar1 == 0) && (local_res20[0] != 4)) {
    param_3[0] = '\0';
    param_3[1] = '\0';
    param_3[2] = '\0';
    param_3[3] = '\0';
    LVar1 = 0x70c;
  }
  return LVar1;
}



===== SvchostStopCallback @ 140002b20 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void SvchostStopCallback(undefined8 *param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4
                        )

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  AcquireSRWLockExclusive((PSRWLOCK)(param_1[1] + 0x20));
  lVar3 = param_1[1];
  pcVar1 = *(code **)(lVar3 + 0x18);
  *(undefined8 *)(lVar3 + 0x18) = 0;
  ReleaseSRWLockExclusive((PSRWLOCK)(param_1[1] + 0x20));
  uVar2 = param_2 & 0xff;
  (*pcVar1)(*param_1);
  DecrementDllReferenceCount((longlong *)param_1[1],uVar2,lVar3,param_4);
                    /* WARNING: Could not recover jumptable at 0x000140002ba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapFree(g_hHeap,0,param_1);
  return;
}



===== DecrementDllReferenceCount @ 140002bc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DecrementDllReferenceCount
               (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  BOOL BVar3;
  longlong lVar4;
  wchar_t **ppwVar5;
  undefined1 auStackY_a8 [32];
  DWORD local_78 [2];
  ULONG_PTR local_70;
  EVENT_DESCRIPTOR local_68;
  _EVENT_DATA_DESCRIPTOR local_58;
  undefined *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  DWORD *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_70 = 0;
  AcquireSRWLockExclusive((PSRWLOCK)(param_1 + 4));
  iVar2 = (int)param_1[6] + -1;
  *(int *)(param_1 + 6) = iVar2;
  if (((int)param_1[0xb] != 0) && (iVar2 == 0)) {
    BVar3 = ActivateActCtx(*(HANDLE *)(param_1[1] + 0x28),&local_70);
    if (BVar3 != 0) {
      if (5 < DAT_14000e000) {
        local_38 = *(wchar_t **)(param_1[1] + 0x18);
        if (local_38 == (wchar_t *)0x0) {
          local_38 = L"";
          local_30 = 2;
        }
        else {
          lVar4 = -1;
          do {
            lVar1 = lVar4 + 1;
            lVar4 = lVar4 + 1;
          } while (local_38[lVar1] != L'\0');
          local_30 = (int)lVar4 * 2 + 2;
        }
        local_68.Level = '\x05';
        local_68.Opcode = '\0';
        local_68.Task = 0;
        local_58.Ptr = (ULONGLONG)PTR_DAT_14000e008;
        local_2c = 0;
        local_68.Id = 0;
        local_68.Version = '\0';
        local_68.Channel = '\v';
        local_68.Keyword = 0;
        local_58.Size = (ULONG)*(ushort *)PTR_DAT_14000e008;
        local_48 = &DAT_14000a676;
        local_58.Reserved = 2;
        local_40 = 0x21;
        local_3c = 1;
        local_78[0] = 0x4be;
        EventWriteTransfer(DAT_14000e020,&local_68,(LPCGUID)0x0,(LPCGUID)0x0,3,&local_58);
      }
      FreeLibrary(*(HMODULE *)(param_1[1] + 0x10));
      *(undefined8 *)(param_1[1] + 0x10) = 0;
      DeactivateActCtx(0,local_70);
      ReleaseSRWLockExclusive((PSRWLOCK)(param_1 + 4));
      WakeAllConditionVariable((PCONDITION_VARIABLE)(param_1 + 5));
      return;
    }
    if (5 < DAT_14000e000) {
      ppwVar5 = &local_38;
      _tlgCreate1Sz_wchar_t((longlong *)ppwVar5,*param_1);
      local_78[0] = GetLastError();
      local_20 = 4;
      local_28 = local_78;
      _tlgWriteTransfer_EventWriteTransfer(ppwVar5,&DAT_14000a698,param_3,param_4,4,&local_58);
    }
  }
  ReleaseSRWLockExclusive((PSRWLOCK)(param_1 + 4));
  return;
}



===== GetServiceMainFunctions @ 140002e00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint GetServiceMainFunctions(WCHAR *param_1,undefined8 *param_2,undefined8 *param_3,WCHAR *param_4)

{
  short *psVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  HANDLE pvVar5;
  FARPROC pFVar6;
  longlong *plVar7;
  WCHAR *pWVar8;
  WCHAR *pWVar9;
  char *pcVar10;
  ulonglong uVar11;
  WCHAR *pWVar12;
  WCHAR *lpType;
  bool bVar13;
  undefined1 auStackY_768 [32];
  DWORD local_738;
  int local_734;
  ulonglong local_730;
  HKEY local_728;
  ulonglong local_720;
  ACTCTXW local_718;
  _EVENT_DATA_DESCRIPTOR local_6d8 [2];
  longlong local_6b8 [2];
  ulonglong *local_6a8;
  undefined8 local_6a0;
  ulonglong *local_698;
  undefined8 local_690;
  WCHAR local_688 [264];
  WCHAR local_478 [264];
  WCHAR local_268 [264];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_768;
  local_718.cbSize = 0x38;
  local_718.hModule._4_4_ = 0;
  local_728 = (HKEY)0x0;
  local_730 = local_730 & 0xffffffff00000000;
  local_734 = 0;
  local_738 = 0;
  local_718.dwFlags = 0;
  local_718.lpSource._0_4_ = 0;
  local_718.lpSource._4_4_ = 0;
  local_718.wProcessorArchitecture = 0;
  local_718.wLangId = 0;
  pvVar5 = (HANDLE)0x0;
  local_718._20_8_ = 0;
  local_718._28_8_ = 0;
  pWVar9 = local_268;
  local_718._36_8_ = 0;
  local_718._44_8_ = 0;
  lpType = param_4;
  memset(local_268,0,0x20a);
  memset(local_478,0,0x20a);
  pWVar12 = (WCHAR *)0x20a;
  memset(local_688,0,0x20a);
  lVar3 = *(longlong *)(param_1 + 4);
  if (lVar3 == 0) {
    uVar2 = OpenServiceParametersKey(*(LPCWSTR *)param_1,&local_728);
    if (uVar2 != 0) {
      uVar11 = 1;
      local_718.lpSource = (WCHAR *)CONCAT44(local_718.lpSource._4_4_,local_718.lpSource._0_4_);
      goto LAB_1400031de;
    }
    lpType = (WCHAR *)&local_734;
    local_738 = 0x20a;
    pWVar12 = (WCHAR *)0x0;
    uVar2 = RegQueryValueExW(local_728,L"ServiceDll",(LPDWORD)0x0,(LPDWORD)lpType,(LPBYTE)local_688,
                             &local_738);
    if (uVar2 != 0) {
      uVar11 = 2;
      local_718.lpSource = (WCHAR *)CONCAT44(local_718.lpSource._4_4_,local_718.lpSource._0_4_);
      goto LAB_1400031de;
    }
    if (local_734 != 2) {
      uVar11 = 3;
      uVar2 = 2;
      local_718.lpSource = (WCHAR *)CONCAT44(local_718.lpSource._4_4_,local_718.lpSource._0_4_);
      goto LAB_1400031de;
    }
    if (local_688[0] == L'\0') {
      uVar11 = 4;
      uVar2 = 2;
      local_718.lpSource = (WCHAR *)CONCAT44(local_718.lpSource._4_4_,local_718.lpSource._0_4_);
      goto LAB_1400031de;
    }
    ExpandEnvironmentStringsW(local_688,local_268,0x104);
    SvchostCharLowerW(local_268);
    lpType = (WCHAR *)&local_734;
    local_738 = 0x20a;
    pWVar12 = (WCHAR *)0x0;
    uVar2 = RegQueryValueExW(local_728,L"ServiceManifest",(LPDWORD)0x0,(LPDWORD)lpType,
                             (LPBYTE)local_688,&local_738);
    local_730 = CONCAT44(local_730._4_4_,uVar2);
    if (uVar2 == 0) {
      if (local_734 != 2) {
        uVar11 = 6;
        uVar2 = 2;
        local_718.lpSource = (WCHAR *)CONCAT44(local_718.lpSource._4_4_,local_718.lpSource._0_4_);
        goto LAB_1400031de;
      }
      if (local_688[0] == L'\0') {
        uVar11 = 7;
        uVar2 = 2;
        local_718.lpSource = (WCHAR *)CONCAT44(local_718.lpSource._4_4_,local_718.lpSource._0_4_);
        goto LAB_1400031de;
      }
      ExpandEnvironmentStringsW(local_688,local_478,0x104);
      SvchostCharLowerW(local_478);
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (local_268[lVar3] != L'\0');
      pWVar12 = local_268 + lVar3;
      do {
        pWVar8 = pWVar12;
        if (lVar3 == 0) goto LAB_140003049;
        lVar3 = lVar3 + -1;
      } while ((pWVar8[-1] != L'\\') && (pWVar12 = pWVar8 + -1, pWVar8[-1] != L'/'));
      pWVar9 = pWVar8;
    }
    else if (1 < uVar2 - 2) {
      uVar11 = 5;
      goto LAB_1400031de;
    }
LAB_140003049:
    pWVar8 = pWVar9;
    pWVar12 = param_1;
    puVar4 = FindDll((longlong)local_478,(longlong)pWVar9,(longlong *)param_1);
    if (puVar4 == (undefined8 *)0x0) {
      if (local_478[0] != L'\0') {
        local_718.lpSource = local_478;
        pvVar5 = CreateActCtxW(&local_718);
        if (pvVar5 == (HANDLE)0xffffffffffffffff) {
          uVar2 = GetLastError();
          uVar11 = 8;
          goto LAB_1400031de;
        }
      }
      lpType = (WCHAR *)&local_730;
      pWVar12 = param_1;
      puVar4 = AddDll(local_478,pWVar9,param_1,(undefined4 *)lpType);
      if (puVar4 == (undefined8 *)0x0) {
        uVar11 = 9;
        uVar2 = (uint)local_730;
        goto LAB_1400031de;
      }
      puVar4[5] = pvVar5;
      pWVar8 = pWVar9;
    }
    bVar13 = CustomServiceMainRoutinesAllowed != 0;
    *(undefined8 **)(param_1 + 4) = puVar4;
    if (bVar13) {
      lpType = param_1 + 8;
      RegQueryStringA(local_728,pWVar8,pWVar12,(undefined8 *)lpType);
    }
  }
  else {
    local_718.lpSource = (WCHAR *)CONCAT44(local_718.lpSource._4_4_,local_718.lpSource._0_4_);
    if (((*(longlong *)(lVar3 + 0x10) == 0) &&
        (psVar1 = *(short **)(lVar3 + 0x20),
        local_718.lpSource = (WCHAR *)CONCAT44(local_718.lpSource._4_4_,local_718.lpSource._0_4_),
        psVar1 != (short *)0x0)) &&
       (local_718.lpSource = (WCHAR *)CONCAT44(local_718.lpSource._4_4_,local_718.lpSource._0_4_),
       *psVar1 != 0)) {
      local_718.lpSource._0_4_ = SUB84(psVar1,0);
      local_718.lpSource._4_4_ = (undefined4)((ulonglong)psVar1 >> 0x20);
      pvVar5 = CreateActCtxW(&local_718);
      if (pvVar5 == (HANDLE)0xffffffffffffffff) {
        uVar2 = GetLastError();
        uVar11 = 10;
        pvVar5 = (HANDLE)0xffffffffffffffff;
        goto LAB_1400031de;
      }
      if ((longlong)*(HANDLE *)(*(longlong *)(param_1 + 4) + 0x28) - 1U < 0xfffffffffffffffe) {
        ReleaseActCtx(*(HANDLE *)(*(longlong *)(param_1 + 4) + 0x28));
      }
      *(HANDLE *)(*(longlong *)(param_1 + 4) + 0x28) = pvVar5;
    }
  }
  pWVar12 = (WCHAR *)&local_730;
  pcVar10 = "ServiceMain";
  if (*(char **)(param_1 + 8) != (char *)0x0) {
    pcVar10 = *(char **)(param_1 + 8);
  }
  pFVar6 = GetServiceDllFunction(*(longlong *)(param_1 + 4),pcVar10,pWVar12,(int *)lpType);
  *param_2 = pFVar6;
  if ((uint)local_730 == 0) {
    pWVar12 = (WCHAR *)0x0;
    pFVar6 = GetServiceDllFunction
                       (*(longlong *)(param_1 + 4),"SvchostPushServiceGlobalsEx",(WCHAR *)0x0,
                        (int *)lpType);
    *(FARPROC *)param_4 = pFVar6;
    if (pFVar6 == (FARPROC)0x0) {
      pWVar12 = (WCHAR *)0x0;
      pFVar6 = GetServiceDllFunction
                         (*(longlong *)(param_1 + 4),"SvchostPushServiceGlobals",(WCHAR *)0x0,
                          (int *)lpType);
      *param_3 = pFVar6;
    }
    uVar2 = 0;
    pvVar5 = (HANDLE)0x0;
    uVar11 = 0;
  }
  else {
    pvVar5 = (HANDLE)0x0;
    uVar11 = 0xb;
    uVar2 = (uint)local_730;
  }
LAB_1400031de:
  if (local_728 != (HKEY)0x0) {
    RegCloseKey(local_728);
  }
  if ((longlong)pvVar5 - 1U < 0xfffffffffffffffe) {
    ReleaseActCtx(pvVar5);
  }
  if ((uVar2 != 0) && (5 < DAT_14000e000)) {
    plVar7 = local_6b8;
    _tlgCreate1Sz_wchar_t(plVar7,*(longlong *)param_1);
    local_6a8 = &local_730;
    local_720 = (ulonglong)uVar2;
    local_698 = &local_720;
    local_6a0 = 8;
    local_690 = 8;
    local_730 = uVar11;
    _tlgWriteTransfer_EventWriteTransfer(plVar7,&DAT_14000a742,pWVar12,lpType,5,local_6d8);
  }
  return uVar2;
}



===== OpenServiceParametersKey @ 1400032a0 =====

LSTATUS OpenServiceParametersKey(LPCWSTR param_1,PHKEY param_2)

{
  LSTATUS LVar1;
  HKEY local_res18;
  HKEY local_res20;
  
  local_res20 = (HKEY)0x0;
  local_res18 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0xffffffff80000002,L"System\\CurrentControlSet\\Services",0,0x20019,
                        &local_res20);
  if (((LVar1 == 0) &&
      (LVar1 = RegOpenKeyExW(local_res20,param_1,0,0x20019,&local_res18), LVar1 == 0)) &&
     (LVar1 = RegOpenKeyExW(local_res18,L"Parameters",0,0x20019,param_2), LVar1 == 2)) {
    LVar1 = 0;
    *param_2 = local_res18;
    local_res18 = (HKEY)0x0;
  }
  if (local_res20 != (HKEY)0x0) {
    RegCloseKey(local_res20);
  }
  if (local_res18 != (HKEY)0x0) {
    RegCloseKey(local_res18);
  }
  return LVar1;
}



===== QueryHeapCallback @ 1400033b0 =====

undefined8 QueryHeapCallback(longlong param_1,longlong *param_2)

{
  *param_2 = *param_2 + *(longlong *)(param_1 + 0x50);
  return 0;
}



===== SvcRegisterStopCallback @ 1400033d0 =====

void SvcRegisterStopCallback
               (longlong *param_1,LPCWSTR param_2,HANDLE param_3,longlong param_4,undefined8 param_5
               ,ULONG param_6)

{
  SvcpRegisterStopCallback(param_1,param_2,param_3,param_4,param_5,param_6,'\0');
  return;
}



===== SvcpRegisterStopCallback @ 140003400 =====

DWORD SvcpRegisterStopCallback
                (longlong *param_1,LPCWSTR param_2,HANDLE param_3,longlong param_4,
                undefined8 param_5,ULONG param_6,char param_7)

{
  PSRWLOCK SRWLock;
  int iVar1;
  DWORD DVar2;
  undefined8 *Context;
  HANDLE pvVar3;
  longlong lVar4;
  uint uVar5;
  HANDLE local_38 [2];
  
  DVar2 = 0;
  local_38[0] = (HANDLE)0x0;
  Context = (undefined8 *)0x0;
  if ((((param_1 == (longlong *)0x0) || (param_2 == (LPCWSTR)0x0)) || (param_3 == (HANDLE)0x0)) ||
     (param_4 == 0)) {
    DVar2 = 0x57;
  }
  else {
    for (uVar5 = 0; uVar5 < ServiceCount; uVar5 = uVar5 + 1) {
      iVar1 = CompareStringOrdinal
                        (param_2,-1,*(LPCWSTR *)((ulonglong)uVar5 * 0x60 + ServiceArray),-1,1);
      if (iVar1 == 2) {
        lVar4 = ServiceArray + (ulonglong)uVar5 * 0x60;
        if (lVar4 != 0) {
          SRWLock = (PSRWLOCK)(lVar4 + 0x20);
          AcquireSRWLockExclusive(SRWLock);
          if (*(longlong *)(lVar4 + 0x18) == 0) {
            Context = HeapAlloc(g_hHeap,8,0x10);
            if (Context == (undefined8 *)0x0) {
              DVar2 = 8;
              ReleaseSRWLockExclusive(SRWLock);
            }
            else {
              *Context = param_5;
              Context[1] = lVar4;
              if (param_7 == '\0') {
                iVar1 = TpAllocWait(local_38,SvchostTpStopCallback,Context,0);
                if (-1 < iVar1) {
                  TpSetWait(local_38[0],param_3,0);
                  pvVar3 = local_38[0];
                  goto LAB_14000355f;
                }
              }
              else {
                pvVar3 = RegisterWaitForSingleObjectEx
                                   (param_3,SvchostStopCallback,Context,0xffffffff,param_6);
                iVar1 = 0;
LAB_14000355f:
                *param_1 = (longlong)pvVar3;
              }
              if (*param_1 != 0) {
                *(int *)(lVar4 + 0x30) = *(int *)(lVar4 + 0x30) + 1;
                *(longlong *)(lVar4 + 0x18) = param_4;
                ReleaseSRWLockExclusive(SRWLock);
                goto LAB_140003471;
              }
              if (param_7 == '\0') {
                DVar2 = RtlNtStatusToDosErrorNoTeb(iVar1);
              }
              else {
                DVar2 = GetLastError();
              }
              ReleaseSRWLockExclusive(SRWLock);
              if (DVar2 == 0) goto LAB_140003471;
            }
          }
          else {
            DVar2 = 0xd;
            ReleaseSRWLockExclusive(SRWLock);
          }
          HeapFree(g_hHeap,0,Context);
          goto LAB_140003471;
        }
        break;
      }
    }
    DVar2 = 0xd;
  }
LAB_140003471:
  return DVar2;
}



===== SvchostBuildSharedGlobals @ 140003680 =====

void SvchostBuildSharedGlobals(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((DAT_14000e764 & 1) == 0) {
    DAT_14000e768 = 0;
    iVar1 = RtlInitializeCriticalSection(&DAT_14000e770);
    if (iVar1 < 0) {
      return;
    }
    DAT_14000e764 = DAT_14000e764 | 1;
  }
  if ((DAT_14000e764 & 4) == 0) {
    iVar1 = ScCreateWellKnownSids();
    if (iVar1 < 0) {
      return;
    }
    DAT_14000e764 = DAT_14000e764 | 4;
  }
  puVar2 = HeapAlloc(g_hHeap,8,0xe0);
  g_pSvchostSharedGlobals = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 1;
    *(undefined8 *)(puVar2 + 2) = NullSid;
    *(undefined8 *)(puVar2 + 4) = WorldSid;
    *(undefined8 *)(puVar2 + 6) = LocalSid;
    *(undefined8 *)(puVar2 + 8) = NetworkSid;
    *(undefined8 *)(puVar2 + 10) = LocalSystemSid;
    *(undefined8 *)(puVar2 + 0xc) = LocalServiceSid;
    *(undefined8 *)(puVar2 + 0xe) = NetworkServiceSid;
    *(undefined8 *)(puVar2 + 0x10) = BuiltinDomainSid;
    *(undefined8 *)(puVar2 + 0x12) = AuthenticatedUserSid;
    *(undefined8 *)(puVar2 + 0x14) = AnonymousLogonSid;
    *(undefined8 *)(puVar2 + 0x16) = AliasAdminsSid;
    *(undefined8 *)(puVar2 + 0x18) = AliasUsersSid;
    *(undefined8 *)(puVar2 + 0x1a) = AliasGuestsSid;
    *(undefined8 *)(puVar2 + 0x1c) = AliasPowerUsersSid;
    *(undefined8 *)(puVar2 + 0x1e) = AliasAccountOpsSid;
    *(undefined8 *)(puVar2 + 0x20) = AliasSystemOpsSid;
    *(undefined8 *)(puVar2 + 0x22) = AliasPrintOpsSid;
    *(undefined8 *)(puVar2 + 0x24) = AliasBackupOpsSid;
    *(code **)(puVar2 + 0x26) = RpcpStartRpcServer;
    *(code **)(puVar2 + 0x28) = RpcpStopRpcServer;
    *(code **)(puVar2 + 0x2a) = RpcpStopRpcServerEx;
    *(code **)(puVar2 + 0x34) = SvcRegisterStopCallback;
    *(code **)(puVar2 + 0x36) = SvcUnregisterStopCallback;
    *(code **)(puVar2 + 0x32) = SvcDeprecatedRegisterStopCallback;
  }
  return;
}



===== ScCreateWellKnownSids @ 140003840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ScCreateWellKnownSids(void)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  longlong lVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  char *pcVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  local_44 = 0xf00;
  local_40 = 0;
  local_3c = 0x500;
  RtlAcquireSRWLockExclusive(&DAT_14000e858);
  for (uVar11 = 0; (uint)uVar11 < 0x12; uVar11 = (ulonglong)((uint)uVar11 + 1)) {
    plVar1 = (longlong *)(&PTR_NullSid_140009030)[uVar11 * 3];
    uVar4 = RtlLengthRequiredSid(1);
    lVar7 = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,uVar4);
    *plVar1 = lVar7;
    if (lVar7 == 0) {
      iVar6 = -0x3fffffe9;
      goto LAB_1400039e5;
    }
    RtlInitializeSid(lVar7,&DAT_140009038 + uVar11 * 0x18,1);
    uVar4 = (&DAT_140009040)[uVar11 * 6];
    puVar8 = (undefined4 *)RtlSubAuthoritySid(*(undefined8 *)(&PTR_NullSid_140009030)[uVar11 * 3]);
    *puVar8 = uVar4;
  }
  for (uVar12 = 0; uVar3 = BuiltinDomainSid, uVar12 < 8; uVar12 = uVar12 + 1) {
    plVar1 = (longlong *)(&PTR_AliasAdminsSid_1400091e0)[(ulonglong)uVar12 * 2];
    uVar4 = (&DAT_1400091e8)[(ulonglong)uVar12 * 4];
    uVar2 = *(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30);
    pbVar9 = (byte *)RtlSubAuthorityCountSid(BuiltinDomainSid);
    uVar5 = RtlLengthRequiredSid(*pbVar9 + 1);
    lVar7 = RtlAllocateHeap(uVar2,0,uVar5);
    *plVar1 = lVar7;
    if (lVar7 == 0) goto LAB_1400039cc;
    iVar6 = RtlCopySid(uVar5,lVar7,uVar3);
    if (iVar6 < 0) {
      RtlFreeHeap(uVar2,0);
      goto LAB_1400039e5;
    }
    pcVar10 = (char *)RtlSubAuthorityCountSid(*plVar1);
    *pcVar10 = *pcVar10 + '\x01';
    puVar8 = (undefined4 *)RtlSubAuthoritySid(*plVar1);
    *puVar8 = uVar4;
  }
  uVar4 = RtlLengthRequiredSid(2);
  AnyPackageSid = RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,uVar4)
  ;
  if (AnyPackageSid != 0) {
    RtlInitializeSid(AnyPackageSid,&local_48,2);
    puVar8 = (undefined4 *)RtlSubAuthoritySid(AnyPackageSid,0);
    *puVar8 = 2;
    puVar8 = (undefined4 *)RtlSubAuthoritySid(AnyPackageSid,1);
    *puVar8 = 1;
    iVar6 = RtlDeriveCapabilitySidsFromName
                      (&DAT_140009000,&LpacServicesManagementCapabilityGroupSidBuffer,
                       &LpacServicesManagementCapabilitySidBuffer);
    if (iVar6 < 0) goto LAB_1400039e5;
    _LpacServicesManagementCapabilitySid = &LpacServicesManagementCapabilitySidBuffer;
    uVar4 = RtlLengthRequiredSid(6);
    UserModeDriversSid =
         RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,uVar4);
    if (UserModeDriversSid != 0) {
      RtlInitializeSid(UserModeDriversSid,&local_40,6);
      iVar6 = 0;
      puVar8 = (undefined4 *)RtlSubAuthoritySid(UserModeDriversSid,0);
      *puVar8 = 0x54;
      puVar8 = (undefined4 *)RtlSubAuthoritySid(UserModeDriversSid,1);
      *puVar8 = 0;
      puVar8 = (undefined4 *)RtlSubAuthoritySid(UserModeDriversSid,2);
      *puVar8 = 0;
      puVar8 = (undefined4 *)RtlSubAuthoritySid(UserModeDriversSid,3);
      *puVar8 = 0;
      puVar8 = (undefined4 *)RtlSubAuthoritySid(UserModeDriversSid,4);
      *puVar8 = 0;
      puVar8 = (undefined4 *)RtlSubAuthoritySid(UserModeDriversSid,5);
      *puVar8 = 0;
      goto LAB_1400039e5;
    }
  }
LAB_1400039cc:
  iVar6 = -0x3fffffe9;
LAB_1400039e5:
  RtlReleaseSRWLockExclusive(&DAT_14000e858);
  return iVar6;
}



===== SvcDeprecatedRegisterStopCallback @ 140003c50 =====

DWORD SvcDeprecatedRegisterStopCallback
                (undefined8 *param_1,LPCWSTR param_2,HANDLE param_3,longlong param_4,
                undefined8 param_5,ULONG param_6)

{
  PSRWLOCK SRWLock;
  int iVar1;
  DWORD DVar2;
  undefined8 *Context;
  HANDLE pvVar3;
  longlong lVar4;
  uint uVar5;
  
  Context = (undefined8 *)0x0;
  if ((((param_1 == (undefined8 *)0x0) || (param_2 == (LPCWSTR)0x0)) || (param_3 == (HANDLE)0x0)) ||
     (param_4 == 0)) {
    return 0x57;
  }
  uVar5 = 0;
  while( true ) {
    if (ServiceCount <= uVar5) {
      return 0xd;
    }
    iVar1 = CompareStringOrdinal
                      (param_2,-1,*(LPCWSTR *)((ulonglong)uVar5 * 0x60 + ServiceArray),-1,1);
    if (iVar1 == 2) break;
    uVar5 = uVar5 + 1;
  }
  lVar4 = ServiceArray + (ulonglong)uVar5 * 0x60;
  if (lVar4 == 0) {
    return 0xd;
  }
  SRWLock = (PSRWLOCK)(lVar4 + 0x20);
  AcquireSRWLockExclusive(SRWLock);
  if (*(longlong *)(lVar4 + 0x18) == 0) {
    Context = HeapAlloc(g_hHeap,8,0x10);
    if (Context != (undefined8 *)0x0) {
      *Context = param_5;
      Context[1] = lVar4;
      pvVar3 = RegisterWaitForSingleObjectEx(param_3,SvchostStopCallback,Context,0xffffffff,param_6)
      ;
      *param_1 = pvVar3;
      if (pvVar3 == (HANDLE)0x0) {
        DVar2 = GetLastError();
        ReleaseSRWLockExclusive(SRWLock);
        if (DVar2 != 0) goto LAB_140003e0a;
      }
      else {
        *(int *)(lVar4 + 0x30) = *(int *)(lVar4 + 0x30) + 1;
        *(longlong *)(lVar4 + 0x18) = param_4;
        ReleaseSRWLockExclusive(SRWLock);
      }
      return 0;
    }
    DVar2 = 8;
    ReleaseSRWLockExclusive(SRWLock);
  }
  else {
    DVar2 = 0xd;
    ReleaseSRWLockExclusive(SRWLock);
  }
LAB_140003e0a:
  HeapFree(g_hHeap,0,Context);
  return DVar2;
}



===== __delayLoadHelper2 @ 140003e50 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(&IMAGE_DOS_HEADER_140000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== InitializeServiceMemoryTracing @ 140003ea0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitializeServiceMemoryTracing(void)

{
  int iVar1;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  if (ServiceCount != 0) {
    HeapSetInformation((HANDLE)0x0,4,(PVOID)0x0,0);
    iVar1 = TpAllocTimer(local_res10,SvchostTelemetryTimerCallback,0,0);
    if (-1 < iVar1) {
      g_TelemetryTimer = local_res10[0];
      _g_LastQueryHeapInfoTime = GetTickCount64();
      g_HeapReportingThresholdKb = GetHeapReportingThreshold();
      ArmTheServiceMemoryTracingTimer();
    }
  }
  return;
}



===== GetHeapReportingThreshold @ 140003f30 =====

undefined4 GetHeapReportingThreshold(void)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  DWORD local_res8 [2];
  DWORD local_res10 [2];
  undefined4 local_res18 [2];
  HKEY local_res20;
  
  local_res18[0] = 0;
  local_res8[0] = 0;
  local_res20 = (HKEY)0x0;
  uVar2 = 0x19000;
  LVar1 = RegOpenKeyExW((HKEY)0xffffffff80000002,L"System\\CurrentControlSet\\Control\\SCMConfig",0,
                        0x20019,&local_res20);
  if (LVar1 == 0) {
    local_res10[0] = 4;
    LVar1 = RegQueryValueExW(local_res20,L"SvchostHeapReportingThresholdInKB",(LPDWORD)0x0,
                             local_res8,(LPBYTE)local_res18,local_res10);
    if (((LVar1 == 0) && (local_res8[0] == 4)) && (uVar2 = 0x19000, local_res10[0] == 4)) {
      uVar2 = local_res18[0];
    }
    RegCloseKey(local_res20);
  }
  return uVar2;
}



===== ArmTheServiceMemoryTracingTimer @ 140003ff0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ArmTheServiceMemoryTracingTimer(void)

{
  ULONGLONG UVar1;
  undefined8 local_res8 [4];
  
  UVar1 = GetTickCount64();
  _g_LastTelemetryUploadTime = UVar1 - 21600000;
  local_res8[0] = 0xfffffffe9a5f4400;
  TpSetTimer(g_TelemetryTimer,local_res8,600000,30000);
  return;
}



===== RegQueryValueWithAlloc @ 140004050 =====

LSTATUS RegQueryValueWithAlloc
                  (HKEY param_1,LPCWSTR param_2,DWORD param_3,undefined8 *param_4,uint *param_5)

{
  uint *puVar1;
  LSTATUS LVar2;
  LPVOID pvData;
  DWORD local_res20 [2];
  
  puVar1 = param_5;
  *param_4 = 0;
  *param_5 = 0;
  local_res20[0] = 0;
  param_5._0_4_ = 0;
  LVar2 = RegGetValueW(param_1,(LPCWSTR)0x0,param_2,0xffff,local_res20,(PVOID)0x0,(LPDWORD)&param_5)
  ;
  if (LVar2 == 0) {
    if ((local_res20[0] == param_3) && ((uint)param_5 != 0)) {
      pvData = HeapAlloc(g_hHeap,0,(ulonglong)(uint)param_5);
      if (pvData == (LPVOID)0x0) {
        LVar2 = 0xe;
      }
      else {
        LVar2 = RegGetValueW(param_1,(LPCWSTR)0x0,param_2,0xffff,local_res20,pvData,
                             (LPDWORD)&param_5);
        if (LVar2 == 0) {
          *puVar1 = (uint)param_5;
          *param_4 = pvData;
        }
        else {
          HeapFree(g_hHeap,0,pvData);
        }
      }
    }
    else {
      LVar2 = 0xd;
    }
  }
  return LVar2;
}



===== TraceLoggingRegisterEx_EventRegister_EventSetInformation @ 140004190 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ULONG TraceLoggingRegisterEx_EventRegister_EventSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  ULONG UVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_14000e008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14000e008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14000e008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14000e008 + -4);
  if (DAT_14000e020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_14000e028 = 0;
  uRam000000014000e030 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1400041eb;
  UVar3 = EventRegister((LPCGUID)(puVar4 + 0x20),_tlgEnableCallback,&DAT_14000e000,
                        (PREGHANDLE)&DAT_14000e020);
  if (UVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000e008;
    *(undefined8 *)(puVar4 + -8) = 0x140004212;
    EventSetInformation(DAT_14000e020,2,PTR_DAT_14000e008,uVar1);
  }
  else if (0 < (int)UVar3) {
    UVar3 = UVar3 & 0xffff | 0x80070000;
  }
  *(undefined8 *)(puVar4 + -8) = 0x140004226;
  return UVar3;
}



===== ShouldBreakInForServiceStart @ 140004250 =====

bool ShouldBreakInForServiceStart(LPCWSTR param_1)

{
  LSTATUS LVar1;
  bool bVar2;
  int local_res10 [2];
  DWORD local_res18 [2];
  DWORD local_res20 [2];
  HKEY local_18;
  HKEY local_10;
  
  bVar2 = false;
  local_res10[0] = 0;
  local_18 = (HKEY)0x0;
  local_10 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0xffffffff80000002,
                        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Svchost",0,0x20019,
                        &local_18);
  if ((LVar1 == 0) && (LVar1 = RegOpenKeyExW(local_18,param_1,0,0x20019,&local_10), LVar1 == 0)) {
    local_res18[0] = 0;
    local_res20[0] = 4;
    LVar1 = RegQueryValueExW(local_10,L"DebugBreak",(LPDWORD)0x0,local_res18,(LPBYTE)local_res10,
                             local_res20);
    if (LVar1 == 0) {
      if (local_res18[0] == 4) {
        bVar2 = local_res10[0] != 0;
      }
      else {
        local_res10[0] = 0;
      }
    }
  }
  if (local_18 != (HKEY)0x0) {
    RegCloseKey(local_18);
  }
  if (local_10 != (HKEY)0x0) {
    RegCloseKey(local_10);
  }
  return bVar2;
}



===== ScIsProcessMitigationPolicyActive @ 140004370 =====

uint ScIsProcessMitigationPolicyActive(uint param_1)

{
  LSTATUS LVar1;
  uint local_res10 [2];
  DWORD local_res18 [2];
  int local_res20 [2];
  DWORD local_18 [2];
  HKEY local_10;
  
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  local_10 = (HKEY)0x0;
  RtlGetDeviceFamilyInfoEnum(0,local_res10);
  if ((local_res10[0] < 0xe) && ((0x2208U >> (local_res10[0] & 0x1f) & 1) != 0)) {
    LVar1 = RegOpenKeyExW((HKEY)0xffffffff80000002,L"System\\CurrentControlSet\\Control\\SCMConfig",
                          0,0x20019,&local_10);
    if (LVar1 == 0) {
      local_18[0] = 4;
      LVar1 = RegQueryValueExW(local_10,L"EnableSvchostMitigationPolicy",(LPDWORD)0x0,local_res18,
                               (LPBYTE)local_res20,local_18);
      if ((LVar1 == 0) && (local_res18[0] == 4)) {
        param_1 = (uint)(local_res20[0] != 0);
      }
      RegCloseKey(local_10);
    }
  }
  else {
    param_1 = 1;
  }
  return param_1;
}



===== CompareHeapTags @ 140004460 =====

int CompareHeapTags(undefined8 param_1,int *param_2,int *param_3)

{
  return *param_2 - *param_3;
}



===== _tlgKeywordOn @ 140004470 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _tlgKeywordOn(undefined8 param_1,ulonglong param_2)

{
  ulonglong in_RAX;
  
  if ((param_2 == 0) ||
     (((_DAT_14000e010 & param_2) != 0 &&
      (in_RAX = DAT_14000e018 & param_2, in_RAX == DAT_14000e018)))) {
    return CONCAT71((int7)(in_RAX >> 8),1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== FindDll @ 1400044a0 =====

undefined8 * FindDll(longlong param_1,longlong param_2,longlong *param_3)

{
  short sVar1;
  short sVar2;
  undefined8 *puVar3;
  short *psVar4;
  undefined8 *puVar5;
  longlong lVar6;
  
  AcquireSRWLockShared((PSRWLOCK)&ListLock);
  for (puVar3 = DllList; puVar5 = (undefined8 *)0x0, (undefined8 **)puVar3 != &DllList;
      puVar3 = (undefined8 *)*puVar3) {
    psVar4 = (short *)puVar3[3];
    lVar6 = param_2 - (longlong)psVar4;
    do {
      sVar1 = *psVar4;
      sVar2 = *(short *)((longlong)psVar4 + lVar6);
      if (sVar1 != sVar2) break;
      psVar4 = psVar4 + 1;
    } while (sVar2 != 0);
    if (sVar1 == sVar2) {
      psVar4 = (short *)puVar3[4];
      lVar6 = param_1 - (longlong)psVar4;
      do {
        sVar1 = *psVar4;
        sVar2 = *(short *)((longlong)psVar4 + lVar6);
        if (sVar1 != sVar2) break;
        psVar4 = psVar4 + 1;
      } while (sVar2 != 0);
      if (sVar1 == sVar2) {
        psVar4 = *(short **)puVar3[6];
        lVar6 = *param_3 - (longlong)psVar4;
        do {
          sVar1 = *psVar4;
          sVar2 = *(short *)((longlong)psVar4 + lVar6);
          if (sVar1 != sVar2) break;
          psVar4 = psVar4 + 1;
        } while (sVar2 != 0);
        puVar5 = puVar3;
        if (sVar1 == sVar2) break;
      }
    }
  }
  ReleaseSRWLockShared((PSRWLOCK)&ListLock);
  return puVar5;
}



===== SvchostTpStopCallback @ 1400045a0 =====

void SvchostTpStopCallback
               (undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  SvchostStopCallback(param_2,CONCAT71((int7)((ulonglong)param_2 >> 8),(int)param_4 == 0x102),
                      param_3,param_4);
  return;
}



===== SvcUnregisterStopCallback @ 1400045c0 =====

undefined4 SvcUnregisterStopCallback(longlong param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x57;
  }
  else {
    TpReleaseWait();
    uVar1 = 0;
  }
  return uVar1;
}



===== BuildServiceArray @ 1400045f0 =====

void BuildServiceArray(undefined8 param_1,longlong param_2)

{
  short sVar1;
  longlong lVar2;
  LSTATUS LVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  short *psVar8;
  HKEY local_res18 [2];
  
  local_res18[0] = (HKEY)0x0;
  uVar7 = 0xffffffff80000002;
  LVar3 = RegOpenKeyExW((HKEY)0xffffffff80000002,
                        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Svchost",0,0x20019,
                        local_res18);
  if (LVar3 == 0) {
    LVar3 = ReadPerInstanceRegistryParameters
                      (CONCAT71((int7)((ulonglong)uVar7 >> 8),1),local_res18[0],param_2);
    RegCloseKey(local_res18[0]);
    if (LVar3 == 0) {
      ServiceCount = 0;
      if (*(longlong *)(param_2 + 0x20) == 0) {
        sVar1 = *ServiceNames;
        psVar8 = ServiceNames;
        while (sVar1 != 0) {
          ServiceCount = ServiceCount + 1;
          lVar2 = -1;
          do {
            lVar6 = lVar2;
            lVar2 = lVar6 + 1;
          } while (psVar8[lVar6 + 1] != 0);
          psVar8 = psVar8 + lVar6 + 2;
          sVar1 = *psVar8;
        }
      }
      else {
        ServiceCount = 1;
      }
      puVar5 = HeapAlloc(g_hHeap,8,(ulonglong)ServiceCount * 0x60);
      ServiceArray = puVar5;
      if (puVar5 != (undefined8 *)0x0) {
        psVar8 = ServiceNames;
        if (*(longlong *)(param_2 + 0x20) == 0) {
          sVar1 = *ServiceNames;
          while (sVar1 != 0) {
            *puVar5 = psVar8;
            InitializeSRWLock((PSRWLOCK)(puVar5 + 4));
            InitializeConditionVariable((PCONDITION_VARIABLE)(puVar5 + 5));
            puVar5 = puVar5 + 0xc;
            lVar2 = -1;
            do {
              lVar6 = lVar2;
              lVar2 = lVar6 + 1;
            } while (psVar8[lVar6 + 1] != 0);
            psVar8 = psVar8 + lVar6 + 2;
            sVar1 = *psVar8;
          }
        }
        else {
          for (; *psVar8 != 0; psVar8 = psVar8 + lVar6 + 2) {
            iVar4 = _o__wcsicmp(*(undefined8 *)(param_2 + 0x20),psVar8);
            if (iVar4 == 0) {
              *puVar5 = psVar8;
              InitializeSRWLock((PSRWLOCK)(puVar5 + 4));
              return;
            }
            lVar2 = -1;
            do {
              lVar6 = lVar2;
              lVar2 = lVar6 + 1;
            } while (psVar8[lVar6 + 1] != 0);
          }
        }
      }
    }
  }
  return;
}



===== CallPerInstanceInitFunctions @ 1400047c0 =====

bool CallPerInstanceInitFunctions(longlong param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  ulong ThreadStackSize;
  bool bVar4;
  char local_18 [8];
  undefined8 local_10;
  
  local_18[0] = '\0';
  iVar1 = NtQueryInformationProcess(0xffffffffffffffff,0x3d,local_18,1,0);
  if (iVar1 < 0) {
    return false;
  }
  if (local_18[0] != '\0') {
    CustomServiceMainRoutinesAllowed = 0;
  }
  if ((*(int *)(param_1 + 0x28) != 0) && (uVar2 = InitializeSecurity(param_1), uVar2 == 0)) {
    return false;
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    lVar3 = RtlImageNtHeader(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x10));
    if (lVar3 == 0) goto LAB_140004857;
    ThreadStackSize = *(ulong *)(lVar3 + 0x68);
  }
  else {
    ThreadStackSize = *(int *)(param_1 + 0x50) << 10;
  }
  RpcMgmtSetServerStackSize(ThreadStackSize);
LAB_140004857:
  if (*(int *)(param_1 + 0x54) == 1) {
    I_RpcServerDisableExceptionFilter();
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    RtlSetProcessIsCritical(1,0);
  }
  if (*(int *)(param_1 + 0x60) != 0) {
    local_10 = CONCAT44(local_10._4_4_,*(int *)(param_1 + 0x60));
    SetProcessMitigationPolicy(2,&local_10);
  }
  if (*(int *)(param_1 + 100) != 0) {
    local_10 = CONCAT44(local_10._4_4_,*(int *)(param_1 + 100));
    SetProcessMitigationPolicy(8,&local_10);
  }
  if (*(int *)(param_1 + 0x68) != 0) {
    local_10 = CONCAT44(local_10._4_4_,*(int *)(param_1 + 0x68));
    SetProcessMitigationPolicy(0x10,&local_10);
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    local_10 = CONCAT44(local_10._4_4_,1);
    SetProcessMitigationPolicy(6,&local_10);
    SetProtectedPolicy("NoUrlMimeFilters",1);
  }
  HeapSetInformation((HANDLE)0x0,HeapEnableTerminationOnCorruption,(PVOID)0x0,0);
  if ((*(byte *)(param_1 + 0x70) & 4) != 0) {
    *(uint *)((longlong)ProcessEnvironmentBlock + 0x378) =
         *(uint *)((longlong)ProcessEnvironmentBlock + 0x378) | 1;
  }
  TraceLoggingRegisterEx_EventRegister_EventSetInformation();
  InitializeServiceMemoryTracing();
  if ((*(byte *)(param_1 + 0x70) & 8) == 0) {
    bVar4 = true;
  }
  else {
    local_10 = 0x100000004;
    iVar1 = NtSetInformationProcess(0xffffffffffffffff,0x34,&local_10);
    bVar4 = -1 < iVar1;
  }
  return bVar4;
}



===== LogServiceEvent @ 1400049e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LogServiceEvent(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  undefined1 auStack_48 [32];
  longlong local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  if (PerfRegHandle != 0) {
    cVar2 = EtwEventEnabled();
    if (cVar2 != '\0') {
      lVar3 = -1;
      do {
        lVar1 = lVar3 * 2;
        lVar3 = lVar3 + 1;
      } while (*(short *)(param_1 + 2 + lVar1) != 0);
      local_20 = (int)lVar3 * 2 + 2;
      local_1c = 0;
      local_28 = param_1;
      EtwEventWrite(PerfRegHandle,param_2,1,&local_28);
    }
  }
  return;
}



===== BuildCommandOptions @ 140004a90 =====

undefined8 * BuildCommandOptions(void *param_1)

{
  longlong lVar1;
  short sVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 *lpMem;
  short sVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  undefined8 *puVar9;
  
  if (param_1 == (void *)0x0) {
    return (undefined8 *)0x0;
  }
  lVar4 = -1;
  do {
    lVar1 = lVar4 * 2;
    lVar4 = lVar4 + 1;
  } while (*(short *)((longlong)param_1 + lVar1 + 2) != 0);
  uVar3 = (int)lVar4 * 2 + 2;
  lpMem = HeapAlloc(g_hHeap,8,(ulonglong)uVar3 + 0x80);
  if (lpMem != (undefined8 *)0x0) {
    *lpMem = lpMem + 0x10;
    puVar9 = (undefined8 *)0x0;
    memcpy(lpMem + 0x10,param_1,(ulonglong)uVar3);
    psVar7 = (short *)*lpMem;
    lpMem[1] = psVar7;
    sVar5 = *psVar7;
    if (sVar5 != 0) {
      do {
        if (sVar5 == 0x20) goto LAB_140004b5d;
        if (sVar5 == 9) break;
        sVar5 = psVar7[1];
        psVar7 = psVar7 + 1;
      } while (sVar5 != 0);
      if (sVar5 != 0) {
LAB_140004b5d:
        *psVar7 = 0;
        psVar7 = psVar7 + 1;
      }
    }
    SvchostCharLowerW((LPCWSTR)lpMem[1]);
    while (sVar5 = *psVar7, sVar5 != 0) {
      do {
        if ((sVar5 != 0x20) && (sVar5 != 9)) break;
        sVar5 = psVar7[1];
        psVar7 = psVar7 + 1;
      } while (sVar5 != 0);
      if (sVar5 == 0) break;
      if ((sVar5 == 0x2d) || (psVar6 = psVar7, sVar5 == 0x2f)) {
        sVar2 = psVar7[1];
        psVar6 = psVar7 + 1;
        sVar5 = 0;
        if (sVar2 == 0) goto LAB_140004c0f;
        if ((sVar2 - 0x4bU & 0xffdf) == 0) {
          *(undefined4 *)(lpMem + 2) = 1;
          puVar9 = lpMem + 3;
        }
        else if ((sVar2 - 0x53U & 0xffdf) == 0) {
          puVar9 = lpMem + 4;
        }
        else if ((sVar2 - 0x50U & 0xffdf) == 0) {
          *(undefined4 *)((longlong)lpMem + 0x5c) = 1;
        }
        psVar7 = psVar7 + 2;
      }
      else {
LAB_140004c0f:
        if (sVar5 == 0x22) {
          sVar5 = psVar6[1];
          psVar7 = psVar6 + 1;
          psVar8 = psVar7;
          if (sVar5 != 0) {
            do {
              if (sVar5 == 0x22) break;
              sVar5 = psVar8[1];
              psVar8 = psVar8 + 1;
            } while (sVar5 != 0);
            sVar5 = *psVar8;
            psVar6 = psVar7;
            goto LAB_140004c66;
          }
        }
        else {
          psVar7 = psVar6;
          if (sVar5 != 0) {
            psVar8 = psVar6;
            do {
              if (sVar5 == 0x20) goto LAB_140004c6b;
              if (sVar5 == 9) break;
              sVar5 = psVar8[1];
              psVar8 = psVar8 + 1;
            } while (sVar5 != 0);
LAB_140004c66:
            psVar7 = psVar8;
            if (sVar5 != 0) {
LAB_140004c6b:
              *psVar8 = 0;
              psVar7 = psVar8 + 1;
            }
          }
        }
        if (puVar9 != (undefined8 *)0x0) {
          *puVar9 = psVar6;
          puVar9 = (undefined8 *)0x0;
        }
      }
    }
    *(uint *)(lpMem + 2) = (uint)(lpMem[3] != 0);
    if (lpMem[3] == 0) {
      HeapFree(g_hHeap,0,lpMem);
      lpMem = (undefined8 *)0x0;
    }
  }
  return lpMem;
}



===== initialize_legacy_wide_specifiers @ 140004ce0 =====

undefined8 initialize_legacy_wide_specifiers(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 4;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return 0;
}



===== __local_stdio_printf_options @ 140004d04 =====

__uint64 * __local_stdio_printf_options(void)

{
  return &`__local_stdio_printf_options'::__l2::_OptionsStorage;
}



===== __local_stdio_scanf_options @ 140004d14 =====

__uint64 * __local_stdio_scanf_options(void)

{
  return &`__local_stdio_scanf_options'::__l2::_OptionsStorage;
}



===== initialize_msvcrt_compatibility @ 140004d30 =====

undefined8 initialize_msvcrt_compatibility(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x18;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 4;
  return 0;
}



===== pre_c_initialization @ 140004d60 =====

void pre_c_initialization(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  
  _set_app_type(1);
  uVar4 = _get_startup_file_mode();
  _set_fmode(uVar4 & 0xffffffff);
  uVar5 = __scrt_initialize_winrt();
  puVar6 = (undefined4 *)__p__commode();
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
      uVar4 = __scrt_initialize_winrt();
      _configthreadlocale(uVar4 & 0xffffffff);
      cVar2 = __vcrt_uninitialize();
      if (cVar2 != '\0') {
        _o__initialize_wide_environment();
      }
      __scrt_initialize_winrt();
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



===== post_pgo_initialization @ 140004e10 =====

undefined8 post_pgo_initialization(void)

{
  __scrt_initialize_default_local_stdio_options();
  return 0;
}



===== pre_cpp_initialization @ 140004e30 =====

void pre_cpp_initialization(void)

{
  ulonglong uVar1;
  
  __scrt_set_unhandled_exception_filter();
  uVar1 = __scrt_initialize_winrt();
  _o__set_new_mode(uVar1 & 0xffffffff);
  return;
}



===== __scrt_common_main_seh @ 140004e50 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

ulonglong __scrt_common_main_seh(void)

{
  wchar_t **_Argv;
  code *pcVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  wchar_t **_Env;
  undefined8 *puVar9;
  uint *puVar10;
  ulonglong uVar11;
  ulonglong unaff_RBX;
  undefined8 in_R9;
  undefined1 uVar12;
  
  lVar5 = __scrt_initialize_crt(1);
  if ((char)lVar5 == '\0') {
    __scrt_fastfail(7);
  }
  else {
    bVar2 = false;
    uVar12 = 0;
    uVar6 = __scrt_acquire_startup_lock();
    unaff_RBX = CONCAT71((int7)(unaff_RBX >> 8),(char)uVar6);
    if (__scrt_current_native_startup_state != 1) {
      if (__scrt_current_native_startup_state == 0) {
        __scrt_current_native_startup_state = 1;
        iVar3 = _initterm_e(&__xi_a,&__xi_z);
        if (iVar3 != 0) {
          return 0xff;
        }
        _initterm(&__xc_a,&__xc_z);
        __scrt_current_native_startup_state = 2;
      }
      else {
        bVar2 = true;
        uVar12 = 1;
      }
      __scrt_release_startup_lock((char)uVar6);
      plVar7 = (longlong *)__scrt_get_dyn_tls_init_callback();
      if ((*plVar7 != 0) &&
         (uVar8 = __scrt_is_nonwritable_in_current_image((longlong)plVar7), (char)uVar8 != '\0')) {
        (*(code *)*plVar7)(0,2,0,in_R9,uVar12);
      }
      plVar7 = (longlong *)__scrt_get_dyn_tls_dtor_callback();
      if ((*plVar7 != 0) &&
         (uVar8 = __scrt_is_nonwritable_in_current_image((longlong)plVar7), (char)uVar8 != '\0')) {
        _register_thread_local_exe_atexit_callback(*plVar7);
      }
      _Env = (wchar_t **)_get_initial_wide_environment();
      puVar9 = (undefined8 *)_o___p___wargv();
      _Argv = (wchar_t **)*puVar9;
      puVar10 = (uint *)_o___p___argc();
      uVar11 = (ulonglong)*puVar10;
      uVar4 = wmain(*puVar10,_Argv,_Env);
      unaff_RBX = (ulonglong)uVar4;
      uVar8 = __scrt_is_managed_app();
      if ((char)uVar8 != '\0') {
        if (!bVar2) {
          _cexit();
        }
        __scrt_uninitialize_crt(CONCAT71((int7)(uVar11 >> 8),1),'\0');
        return unaff_RBX;
      }
      goto LAB_140004fbb;
    }
  }
  __scrt_fastfail(7);
LAB_140004fbb:
  _o_exit(unaff_RBX & 0xffffffff);
  _exit(unaff_RBX & 0xffffffff);
  pcVar1 = (code *)swi(3);
  uVar8 = (*pcVar1)();
  return uVar8;
}



===== entry @ 140004fe0 =====

void entry(void)

{
  __security_init_cookie();
  __scrt_common_main_seh();
  return;
}



===== __security_check_cookie @ 140005010 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __scrt_acquire_startup_lock @ 140005034 =====

ulonglong __scrt_acquire_startup_lock(void)

{
  bool bVar1;
  undefined7 extraout_var;
  void *pvVar2;
  ulonglong uVar3;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  pvVar2 = (void *)CONCAT71(extraout_var,bVar1);
  if ((int)pvVar2 == 0) {
LAB_140005062:
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
      if (bVar1) goto LAB_140005062;
    } while (StackBase != pvVar2);
    uVar3 = CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
  }
  return uVar3;
}



===== __scrt_initialize_crt @ 140005074 =====

longlong __scrt_initialize_crt(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_14000e111 = 1;
  }
  __isa_available_init();
  cVar1 = __vcrt_uninitialize();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = __vcrt_uninitialize();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    __vcrt_uninitialize();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}



===== __scrt_initialize_onexit_tables @ 1400050b4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  ulonglong in_RAX;
  undefined7 extraout_var;
  undefined8 uVar3;
  
  if (DAT_14000e110 == '\0') {
    if (1 < param_1) {
      __scrt_fastfail(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    bVar2 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar2) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_14000e0e0 = 0xffffffffffffffff;
      uRam000000014000e0e8 = 0xffffffffffffffff;
      _DAT_14000e0f0 = 0xffffffffffffffff;
      _DAT_14000e0f8 = 0xffffffffffffffff;
      uRam000000014000e100 = 0xffffffffffffffff;
      _DAT_14000e108 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_14000e0e0);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_14000e0f8), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_14000e110 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== __scrt_is_nonwritable_in_current_image @ 140005148 =====

/* WARNING: Removing unreachable block (ram,0x0001400051d5) */
/* WARNING: Enum "SectionFlags": Some values do not have unique names */

ulonglong __scrt_is_nonwritable_in_current_image(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  IMAGE_SECTION_HEADER *pIVar3;
  
  uVar1 = 0;
  for (pIVar3 = &IMAGE_SECTION_HEADER_140000200; pIVar3 != (IMAGE_SECTION_HEADER *)&DAT_140000340;
      pIVar3 = pIVar3 + 1) {
    if (((ulonglong)(uint)pIVar3->VirtualAddress <= param_1 - 0x140000000U) &&
       (uVar1 = (ulonglong)((pIVar3->Misc).PhysicalAddress + pIVar3->VirtualAddress),
       param_1 - 0x140000000U < uVar1)) goto LAB_1400051be;
  }
  pIVar3 = (IMAGE_SECTION_HEADER *)0x0;
LAB_1400051be:
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



===== __scrt_release_startup_lock @ 1400051e8 =====

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



===== __scrt_uninitialize_crt @ 140005214 =====

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_14000e111 == '\0') || (param_2 == '\0')) {
    __vcrt_uninitialize();
    __vcrt_uninitialize();
  }
  return 1;
}



===== _onexit @ 140005244 =====

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_14000e0e0 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_14000e0e0);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}



===== atexit @ 140005284 =====

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



===== __security_init_cookie @ 1400052a4 =====

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



===== _get_startup_argv_mode @ 14000535c =====

undefined8 _get_startup_argv_mode(void)

{
  return 1;
}



===== __scrt_initialize_winrt @ 140005368 =====

undefined8 __scrt_initialize_winrt(void)

{
  return 0;
}



===== _get_startup_file_mode @ 140005374 =====

undefined8 _get_startup_file_mode(void)

{
  return 0x4000;
}



===== __scrt_initialize_type_info @ 140005380 =====

/* void __cdecl __scrt_initialize_type_info(void) */

void __cdecl __scrt_initialize_type_info(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005387. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&__type_info_root_node);
  return;
}



===== __vcrt_uninitialize @ 140005394 =====

undefined1 __vcrt_uninitialize(void)

{
  return 1;
}



===== _guard_check_icall @ 1400053a0 =====

void _guard_check_icall(void)

{
  return;
}



===== __scrt_initialize_default_local_stdio_options @ 1400053ac =====

void __scrt_initialize_default_local_stdio_options(void)

{
  __uint64 *p_Var1;
  
  p_Var1 = __local_stdio_printf_options();
  *p_Var1 = *p_Var1 | 0x24;
  p_Var1 = __local_stdio_scanf_options();
  *p_Var1 = *p_Var1 | 2;
  return;
}



===== __scrt_get_dyn_tls_init_callback @ 1400053d0 =====

undefined * __scrt_get_dyn_tls_init_callback(void)

{
  return &__dyn_tls_init_callback;
}



===== __scrt_get_dyn_tls_dtor_callback @ 1400053e0 =====

undefined * __scrt_get_dyn_tls_dtor_callback(void)

{
  return &__dyn_tls_dtor_callback;
}



===== __crt_debugger_hook @ 1400053f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __crt_debugger_hook(int param_1)

{
  ___scrt_debugger_hook_flag = 0;
  return;
}



===== __scrt_fastfail @ 140005400 =====

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
  *(undefined8 *)(puVar4 + -8) = 0x140005434;
  __crt_debugger_hook(3);
  *(undefined8 *)(puVar4 + -8) = 0x140005445;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x14000544f;
  RtlCaptureContext(local_4d8);
  local_res10 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x140005471;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    local_res18 = 0;
    local_res20 = 0;
    *(undefined8 **)(puVar4 + 0x30) = &local_res18;
    *(undefined8 **)(puVar4 + 0x28) = &local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x1400054c2;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = auStack_5c8 + 0x5d0;
  *(undefined8 *)(puVar4 + -8) = 0x1400054f4;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x140005516;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x140005533;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x14000553e;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x14000554f;
    __crt_debugger_hook(3);
  }
  return;
}



===== __scrt_initialize_mta @ 140005568 =====

undefined8 __scrt_initialize_mta(void)

{
  return 0;
}



===== __scrt_is_managed_app @ 140005574 =====

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



===== __scrt_set_unhandled_exception_filter @ 1400055cc =====

void __scrt_set_unhandled_exception_filter(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400055d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter(__scrt_unhandled_exception_filter);
  return;
}



===== __scrt_unhandled_exception_filter @ 1400055e0 =====

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



===== _RTC_Initialize @ 140005644 =====

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



===== _RTC_Terminate @ 140005690 =====

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



===== __raise_securityfailure @ 1400056d8 =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000140005705. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



===== __report_gsfailure @ 140005720 =====

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
  *(undefined8 *)(puVar3 + -8) = 0x14000574b;
  capture_previous_context((PCONTEXT)&DAT_14000e1e0);
  _DAT_14000e150 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_14000e278 = puVar3 + 0x40;
  _DAT_14000e260 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_14000e140 = 0xc0000409;
  _DAT_14000e144 = 1;
  _DAT_14000e158 = 1;
  DAT_14000e160 = 2;
  *(undefined8 *)(puVar3 + 0x20) = __security_cookie;
  *(undefined8 *)(puVar3 + 0x28) = __security_cookie_complement;
  *(undefined8 *)(puVar3 + -8) = 0x1400057ed;
  DAT_14000e2d8 = _DAT_14000e150;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_140009010);
  return;
}



===== capture_previous_context @ 1400057f8 =====

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



===== __isa_available_init @ 140005884 =====

/* WARNING: Removing unreachable block (ram,0x00014000594e) */
/* WARNING: Removing unreachable block (ram,0x0001400058be) */
/* WARNING: Removing unreachable block (ram,0x000140005897) */
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



===== __scrt_is_ucrt_dll_in_use @ 140005a38 =====

bool __scrt_is_ucrt_dll_in_use(void)

{
  return __scrt_ucrt_dll_is_in_use != 0;
}



===== _initterm @ 140005a56 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005a56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== _initterm_e @ 140005a62 =====

void _initterm_e(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005a62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm_e();
  return;
}



===== _c_exit @ 140005a6e =====

void __cdecl _c_exit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005a6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _c_exit();
  return;
}



===== _register_thread_local_exe_atexit_callback @ 140005a7a =====

void _register_thread_local_exe_atexit_callback(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005a7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _register_thread_local_exe_atexit_callback();
  return;
}



===== _o___p___argc @ 140005a86 =====

void _o___p___argc(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005a86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___p___argc();
  return;
}



===== _o___p___wargv @ 140005a92 =====

void _o___p___wargv(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005a92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___p___wargv();
  return;
}



===== __p__commode @ 140005a9e =====

void __p__commode(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005a9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___p__commode();
  return;
}



===== __stdio_common_vswprintf @ 140005aaa =====

void __stdio_common_vswprintf(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005aaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o___stdio_common_vswprintf();
  return;
}



===== _cexit @ 140005ab6 =====

void _cexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005ab6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__cexit();
  return;
}



===== _configthreadlocale @ 140005ac2 =====

void _configthreadlocale(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005ac2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configthreadlocale();
  return;
}



===== _configure_wide_argv @ 140005ace =====

void _configure_wide_argv(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005ace. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__configure_wide_argv();
  return;
}



===== _crt_atexit @ 140005ada =====

void _crt_atexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005ada. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__crt_atexit();
  return;
}



===== _exit @ 140005ae6 =====

void _exit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005ae6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__exit();
  return;
}



===== _get_initial_wide_environment @ 140005af2 =====

void _get_initial_wide_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005af2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__get_initial_wide_environment();
  return;
}



===== _initialize_onexit_table @ 140005afe =====

void _initialize_onexit_table(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005afe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_onexit_table();
  return;
}



===== _o__initialize_wide_environment @ 140005b0a =====

void _o__initialize_wide_environment(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__initialize_wide_environment();
  return;
}



===== _register_onexit_function @ 140005b16 =====

void _register_onexit_function(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__register_onexit_function();
  return;
}



===== _o__seh_filter_exe @ 140005b22 =====

void _o__seh_filter_exe(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__seh_filter_exe();
  return;
}



===== _set_app_type @ 140005b2e =====

void _set_app_type(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__set_app_type();
  return;
}



===== _set_fmode @ 140005b3a =====

void _set_fmode(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__set_fmode();
  return;
}



===== _o__set_new_mode @ 140005b46 =====

void _o__set_new_mode(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__set_new_mode();
  return;
}



===== _o__wcsicmp @ 140005b52 =====

void _o__wcsicmp(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o__wcsicmp();
  return;
}



===== bsearch_s @ 140005b5e =====

void bsearch_s(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_bsearch_s();
  return;
}



===== _o_exit @ 140005b6a =====

void _o_exit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_exit();
  return;
}



===== _o_qsort_s @ 140005b76 =====

void _o_qsort_s(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_qsort_s();
  return;
}



===== terminate @ 140005b82 =====

void terminate(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _o_terminate();
  return;
}



===== __C_specific_handler @ 140005b8e =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140005b8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __current_exception @ 140005b9a =====

void __current_exception(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005b9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception();
  return;
}



===== __current_exception_context @ 140005ba6 =====

void __current_exception_context(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140005ba6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __current_exception_context();
  return;
}



===== memset @ 140005bb2 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140005bb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== __tailMerge_api_ms_win_service_private_l1_1_3_dll @ 140005bb8 =====

void __tailMerge_api_ms_win_service_private_l1_1_3_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_R9;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_14000b798,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140005c2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,in_XMM2_Qa,in_R9);
  return;
}



===== DelayLoad_I_RegisterSvchostNotificationCallback @ 140005c37 =====

void DelayLoad_I_RegisterSvchostNotificationCallback
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_service_private_l1_1_3_dll(param_1,param_2,param_3,param_4);
  return;
}



===== _vsnwprintf @ 140005c4c =====

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



===== __tailMerge_api_ms_win_service_winsvc_l1_1_0_dll @ 140005cae =====

void __tailMerge_api_ms_win_service_winsvc_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_XMM0_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_14000b7b8,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140005d25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_XMM0_Qa,in_RDX,param_3,param_4);
  return;
}



===== DelayLoad_RegisterServiceCtrlHandlerW @ 140005d2d =====

void DelayLoad_RegisterServiceCtrlHandlerW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_service_winsvc_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_service_core_l1_1_0_dll @ 140005d39 =====

void __tailMerge_api_ms_win_service_core_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_14000b7d8,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140005db0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,param_3,param_4);
  return;
}



===== DelayLoad_SetServiceStatus @ 140005db8 =====

void DelayLoad_SetServiceStatus
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_service_core_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== RegOpenKeyExW @ 140005dca =====

LSTATUS __stdcall
RegOpenKeyExW(HKEY hKey,LPCWSTR lpSubKey,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult)

{
  LSTATUS LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140005dca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = RegOpenKeyExW(hKey,lpSubKey,ulOptions,samDesired,phkResult);
  return LVar1;
}



===== RegCloseKey @ 140005dd6 =====

LSTATUS __stdcall RegCloseKey(HKEY hKey)

{
  LSTATUS LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140005dd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = RegCloseKey(hKey);
  return LVar1;
}



===== RegQueryValueExW @ 140005de2 =====

LSTATUS __stdcall
RegQueryValueExW(HKEY hKey,LPCWSTR lpValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,
                LPDWORD lpcbData)

{
  LSTATUS LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140005de2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = RegQueryValueExW(hKey,lpValueName,lpReserved,lpType,lpData,lpcbData);
  return LVar1;
}



===== __tailMerge_api_ms_win_core_com_l1_1_0_dll @ 140005de8 =====

void __tailMerge_api_ms_win_core_com_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_14000b7f8,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140005e5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_XMM0_Qa,in_RDX,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_CLSIDFromString @ 140005e67 =====

void DelayLoad_CLSIDFromString
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_rpcrt4_dll @ 140005e73 =====

void __tailMerge_rpcrt4_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RDX;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_14000b818,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140005eea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_RDX,in_XMM2_Qa,param_4);
  return;
}



===== DelayLoad_RpcMgmtSetServerStackSize @ 140005ef2 =====

void DelayLoad_RpcMgmtSetServerStackSize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_I_RpcServerDisableExceptionFilter @ 140005f04 =====

void DelayLoad_I_RpcServerDisableExceptionFilter
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_StartServiceCtrlDispatcherW @ 140005f16 =====

void DelayLoad_StartServiceCtrlDispatcherW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_service_core_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoUninitialize @ 140005f28 =====

void DelayLoad_CoUninitialize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoCreateInstance @ 140005f3a =====

void DelayLoad_CoCreateInstance
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoInitializeSecurity @ 140005f4c =====

void DelayLoad_CoInitializeSecurity
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoInitializeEx @ 140005f5e =====

void DelayLoad_CoInitializeEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_I_RpcMapWin32Status @ 140005f70 =====

void DelayLoad_I_RpcMapWin32Status
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcServerUseProtseqEpW @ 140005f82 =====

void DelayLoad_RpcServerUseProtseqEpW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcServerUnregisterIfEx @ 140005f94 =====

void DelayLoad_RpcServerUnregisterIfEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcServerUnregisterIf @ 140005fa6 =====

void DelayLoad_RpcServerUnregisterIf
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcServerRegisterIf @ 140005fb8 =====

void DelayLoad_RpcServerRegisterIf
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcMgmtWaitServerListen @ 140005fca =====

void DelayLoad_RpcMgmtWaitServerListen
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcServerListen @ 140005fdc =====

void DelayLoad_RpcServerListen
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcMgmtStopServerListening @ 140005fee =====

void DelayLoad_RpcMgmtStopServerListening
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== AbortHostedService @ 140006000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AbortHostedService(LPCWSTR param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  DWORD DVar1;
  BOOL BVar2;
  SERVICE_STATUS_HANDLE hServiceStatus;
  longlong *plVar3;
  ulonglong uVar4;
  undefined1 auStackY_d8 [32];
  ulonglong local_a8;
  ulonglong local_a0;
  _SERVICE_STATUS local_98;
  _EVENT_DATA_DESCRIPTOR local_78 [2];
  longlong local_58 [2];
  ulonglong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98.dwCheckPoint = 0;
  uVar4 = 1;
  local_98.dwWaitHint = 0;
  local_98.dwServiceSpecificExitCode = 0;
  local_98.dwServiceType = 0x30;
  local_98.dwCurrentState = 1;
  local_98.dwControlsAccepted = 1;
  local_98.dwWin32ExitCode = param_2;
  if (5 < DAT_14000e000) {
    plVar3 = local_58;
    _tlgCreate1Sz_wchar_t(plVar3,(longlong)param_1);
    local_3c = 0;
    local_48 = &local_a8;
    local_40 = 8;
    local_a8 = (ulonglong)param_2;
    _tlgWriteTransfer_EventWriteTransfer(plVar3,&DAT_14000a8be,param_3,param_4,4,local_78);
  }
  hServiceStatus = RegisterServiceCtrlHandlerW(param_1,DummySvchostCtrlHandler);
  if (hServiceStatus == (SERVICE_STATUS_HANDLE)0x0) {
    DVar1 = GetLastError();
  }
  else {
    BVar2 = SetServiceStatus(hServiceStatus,&local_98);
    if (BVar2 != 0) {
      return;
    }
    DVar1 = GetLastError();
    uVar4 = 2;
  }
  if ((DVar1 != 0) && (5 < DAT_14000e000)) {
    plVar3 = local_58;
    _tlgCreate1Sz_wchar_t(plVar3,(longlong)param_1);
    local_3c = 0;
    local_48 = &local_a8;
    local_2c = 0;
    local_38 = &local_a0;
    local_40 = 8;
    local_30 = 8;
    local_a8 = uVar4;
    local_a0 = (ulonglong)param_2;
    _tlgWriteTransfer_EventWriteTransfer(plVar3,&DAT_14000a876,param_3,param_4,5,local_78);
  }
  return;
}



===== AddDll @ 14000616c =====

undefined8 * AddDll(void *param_1,void *param_2,undefined8 param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  lVar6 = -1;
  lVar5 = -1;
  do {
    lVar5 = lVar5 + 1;
  } while (*(short *)((longlong)param_2 + lVar5 * 2) != 0);
  do {
    lVar6 = lVar6 + 1;
  } while (*(short *)((longlong)param_1 + lVar6 * 2) != 0);
  puVar2 = HeapAlloc(g_hHeap,8,(lVar6 + lVar5) * 2 + 0x3c);
  if (puVar2 == (undefined8 *)0x0) {
    *param_4 = 8;
  }
  else {
    puVar2[3] = puVar2 + 7;
    puVar2[4] = (longlong)puVar2 + lVar5 * 2 + 0x3aU;
    memcpy(puVar2 + 7,param_2,lVar5 * 2);
    memcpy((void *)puVar2[4],param_1,lVar6 * 2);
    puVar2[6] = param_3;
    AcquireSRWLockExclusive((PSRWLOCK)&ListLock);
    puVar4 = auStack_48;
    puVar3 = &DllList;
    if ((undefined8 *)*DAT_14000e8f8 != &DllList) {
      puVar3 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      DAT_14000e8f8 = (undefined8 *)(*pcVar1)();
      puVar4 = auStack_40;
    }
    *puVar2 = puVar3;
    puVar2[1] = DAT_14000e8f8;
    *DAT_14000e8f8 = puVar2;
    *(undefined8 *)(puVar4 + -8) = 0x140006261;
    DAT_14000e8f8 = puVar2;
    ReleaseSRWLockExclusive((PSRWLOCK)&ListLock);
  }
  return puVar2;
}



===== DummySvchostCtrlHandler @ 1400062a0 =====

void DummySvchostCtrlHandler(void)

{
  return;
}



===== LoadWldpLibrary @ 1400062b0 =====

undefined8 LoadWldpLibrary(void)

{
  WldpModuleHandle = LoadLibraryExW(L"WLDP.DLL",(HANDLE)0x0,0x800);
  if (WldpModuleHandle != (HMODULE)0x0) {
    IsAllowedEntryPoint = GetProcAddress(WldpModuleHandle,"WldpIsAllowedEntryPoint");
  }
  return 1;
}



===== ReadPerInstanceRegistryParameters @ 14000630c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

LSTATUS ReadPerInstanceRegistryParameters(undefined8 param_1,HKEY param_2,longlong param_3)

{
  char cVar1;
  LSTATUS LVar2;
  LSTATUS LVar3;
  HRESULT HVar4;
  uint uVar5;
  LSTATUS LVar6;
  int iVar7;
  short *psVar8;
  longlong lVar9;
  longlong lVar10;
  DWORD DVar11;
  short *_Src;
  LPVOID lpMem;
  short *_Dst;
  longlong lVar12;
  LPCWSTR lpMem_00;
  uint uVar13;
  LPCOLESTR lpMem_01;
  undefined1 auStackY_2d8 [32];
  int local_298 [2];
  HKEY local_290;
  DWORD local_288;
  uint local_284;
  uint local_280 [2];
  LPCOLESTR local_278;
  LPVOID local_270;
  LPCWSTR local_268;
  HKEY local_260;
  WCHAR local_258 [264];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2d8;
  lpMem = (LPVOID)0x0;
  ServiceNames = (short *)0x0;
  local_298[0] = 0;
  local_288 = 0;
  psVar8 = (short *)0x0;
  local_280[0] = 0;
  local_290 = (HKEY)0x0;
  lpMem_00 = (LPCWSTR)0x0;
  local_260 = (HKEY)0x0;
  local_278 = (LPCOLESTR)0x0;
  local_268 = (LPCWSTR)0x0;
  local_270 = (LPVOID)0x0;
  local_284 = 0;
  LVar2 = RegQueryValueWithAlloc(param_2,*(LPCWSTR *)(param_3 + 0x18),7,&ServiceNames,&local_284);
  uVar13 = local_284;
  LVar3 = RegOpenKeyExW(param_2,*(LPCWSTR *)(param_3 + 0x18),0,0x20019,&local_290);
  if (LVar3 != 0) {
    lpMem_01 = local_278;
    goto LAB_140006875;
  }
  DVar11 = 0;
  while( true ) {
    local_288 = 0x101;
    LVar3 = RegEnumKeyExW(local_290,DVar11,local_258,&local_288,(LPDWORD)0x0,(LPWSTR)0x0,
                          (LPDWORD)0x0,(PFILETIME)0x0);
    DVar11 = DVar11 + 1;
    if (LVar3 != 0) break;
    uVar13 = uVar13 + local_288 * 2 + 2;
  }
  if (((uVar13 != 0) && (1 < DVar11)) &&
     (psVar8 = HeapAlloc(g_hHeap,0,(ulonglong)(uVar13 + 2)), psVar8 != (short *)0x0)) {
    _Dst = psVar8;
    if (((LVar2 == 0) && (1 < local_284)) && (_Src = ServiceNames, ServiceNames != (short *)0x0)) {
      for (; *_Src != 0; _Src = _Src + lVar10 + 2) {
        lVar12 = -1;
        do {
          lVar12 = lVar12 + 1;
        } while (_Src[lVar12] != 0);
        memcpy(_Dst,_Src,lVar12 * 2 + 2);
        lVar12 = -1;
        do {
          lVar9 = lVar12;
          lVar12 = lVar9 + 1;
        } while (_Src[lVar12] != 0);
        lVar12 = -1;
        do {
          lVar10 = lVar12;
          lVar12 = lVar10 + 1;
        } while (_Src[lVar12] != 0);
        _Dst = _Dst + lVar9 + 2;
      }
    }
    DVar11 = 0;
    while( true ) {
      local_288 = 0x101;
      LVar2 = RegEnumKeyExW(local_290,DVar11,local_258,&local_288,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
      DVar11 = DVar11 + 1;
      if (LVar2 != 0) break;
      lVar12 = -1;
      do {
        lVar12 = lVar12 + 1;
      } while (local_258[lVar12] != L'\0');
      memcpy(_Dst,local_258,lVar12 * 2 + 2);
      _Dst = _Dst + (local_288 + 1);
    }
    *_Dst = 0;
    if (ServiceNames != (short *)0x0) {
      HeapFree(g_hHeap,0,ServiceNames);
    }
    LVar2 = 0;
    ServiceNames = psVar8;
  }
  if ((ServiceNames == (short *)0x0) ||
     (((1 < local_284 || (psVar8 != (short *)0x0)) && (*ServiceNames == 0)))) {
    LVar3 = 0xd;
    goto LAB_140006a35;
  }
  LVar3 = RegQueryDword(local_290,L"CoInitializeSecurityParam",(LPBYTE)local_298);
  if (LVar3 == 0) {
    *(int *)(param_3 + 0x28) = local_298[0];
  }
  LVar3 = RegQueryDword(local_290,L"CoInitializeSecurityAllowLowBox",(LPBYTE)local_298);
  if ((LVar3 == 0) && (local_298[0] != 0)) {
    *(uint *)(param_3 + 0x70) = *(uint *)(param_3 + 0x70) | 2;
  }
  LVar3 = RegQueryDword(local_290,L"CoInitializeSecurityAllowInteractiveUsers",(LPBYTE)local_298);
  if ((LVar3 == 0) && (local_298[0] != 0)) {
    *(uint *)(param_3 + 0x70) = *(uint *)(param_3 + 0x70) | 0x10;
  }
  LVar3 = RegQueryDword(local_290,L"CoInitializeSecurityAllowComCapability",(LPBYTE)local_298);
  if ((LVar3 == 0) && (local_298[0] != 0)) {
    *(uint *)(param_3 + 0x70) = *(uint *)(param_3 + 0x70) | 0x20;
  }
  LVar3 = RegQueryDword(local_290,L"CoInitializeSecurityAllowCrossContainer",(LPBYTE)local_298);
  if ((LVar3 == 0) && (local_298[0] != 0)) {
    *(uint *)(param_3 + 0x70) = *(uint *)(param_3 + 0x70) | 0x40;
  }
  if (*(int *)(param_3 + 0x28) == 0) {
    lpMem_01 = local_278;
  }
  else {
    LVar3 = RegQueryDword(local_290,L"AuthenticationLevel",(LPBYTE)local_298);
    iVar7 = 4;
    if (LVar3 == 0) {
      iVar7 = local_298[0];
    }
    *(int *)(param_3 + 0x2c) = iVar7;
    LVar3 = RegQueryDword(local_290,L"ImpersonationLevel",(LPBYTE)local_298);
    iVar7 = 2;
    if (LVar3 == 0) {
      iVar7 = local_298[0];
    }
    *(int *)(param_3 + 0x30) = iVar7;
    LVar3 = RegQueryDword(local_290,L"AuthenticationCapabilities",(LPBYTE)local_298);
    iVar7 = 0x3000;
    if (LVar3 == 0) {
      iVar7 = local_298[0];
    }
    *(int *)(param_3 + 0x34) = iVar7;
    local_284 = 0;
    LVar3 = RegQueryValueWithAlloc(local_290,L"CoInitializeSecurityAppID",1,&local_278,&local_284);
    lpMem_01 = local_278;
    if ((LVar3 == 0) && (HVar4 = CLSIDFromString(local_278,(LPCLSID)(param_3 + 0x38)), HVar4 < 0)) {
      *(undefined8 *)(param_3 + 0x38) = 0;
      *(undefined8 *)(param_3 + 0x40) = 0;
    }
    LVar3 = RegQueryDword(local_290,L"COM_UnmarshalingPolicy",(LPBYTE)local_298);
    iVar7 = 0xffff;
    if (LVar3 == 0) {
      iVar7 = local_298[0];
    }
    *(int *)(param_3 + 0x48) = iVar7;
    LVar3 = RegQueryDword(local_290,L"COM_RoSettings",(LPBYTE)local_298);
    iVar7 = 0xffff;
    if (LVar3 == 0) {
      iVar7 = local_298[0];
    }
    *(int *)(param_3 + 0x4c) = iVar7;
  }
  LVar3 = RegQueryDword(local_290,L"DefaultRpcStackSize",(LPBYTE)local_298);
  if (LVar3 == 0) {
    *(int *)(param_3 + 0x50) = local_298[0];
  }
  LVar3 = RegQueryDword(local_290,L"RpcExceptionFilterMode",(LPBYTE)local_298);
  if ((LVar3 == 0) && (local_298[0] == 0)) {
    *(undefined4 *)(param_3 + 0x54) = 1;
  }
  LVar3 = RegQueryDword(local_290,L"SystemCritical",(LPBYTE)local_298);
  if (LVar3 == 0) {
    *(uint *)(param_3 + 0x58) = (uint)(local_298[0] != 0);
  }
  LVar3 = RegQueryDword(local_290,L"NoGuiAccess",(LPBYTE)local_298);
  if ((LVar3 == 0) && (local_298[0] != 0)) {
    *(uint *)(param_3 + 0x70) = *(uint *)(param_3 + 0x70) | 8;
  }
  LVar3 = RegQueryValueWithAlloc(local_290,L"COMAccessPermissionsSD",3,&local_270,local_280);
  lpMem = local_270;
  if (LVar3 == 0) {
    cVar1 = RtlValidSecurityDescriptor();
    if (cVar1 != '\0') {
      *(LPVOID *)(param_3 + 0x78) = lpMem;
      lpMem = (LPVOID)0x0;
      goto LAB_140006875;
    }
    LVar3 = 0xd;
  }
  else if (LVar3 == 2) {
LAB_140006875:
    uVar5 = ScIsProcessMitigationPolicyActive(0);
    uVar13 = 0;
    if (uVar5 != 0) {
      uVar13 = *(uint *)(param_3 + 0x5c);
    }
    if ((local_290 == (HKEY)0x0) ||
       (LVar3 = RegQueryDword(local_290,L"DynamicCodePolicy",(LPBYTE)local_298), LVar3 != 0)) {
      if (uVar13 != 0) {
        *(undefined4 *)(param_3 + 0x60) = 1;
      }
    }
    else {
      *(int *)(param_3 + 0x60) = local_298[0];
    }
    if ((local_290 == (HKEY)0x0) ||
       (LVar3 = RegQueryDword(local_290,L"BinarySignaturePolicy",(LPBYTE)local_298), LVar3 != 0)) {
      if (uVar13 != 0) {
        *(undefined4 *)(param_3 + 100) = 1;
      }
    }
    else {
      *(int *)(param_3 + 100) = local_298[0];
    }
    if ((local_290 == (HKEY)0x0) ||
       (LVar3 = RegQueryDword(local_290,L"RedirectionTrustPolicy",(LPBYTE)local_298), LVar3 != 0)) {
      *(undefined4 *)(param_3 + 0x68) = 2;
    }
    else {
      *(int *)(param_3 + 0x68) = local_298[0];
    }
    if ((local_290 == (HKEY)0x0) ||
       (LVar3 = RegQueryDword(local_290,L"ExtensionPointsPolicy",(LPBYTE)local_298), LVar3 != 0)) {
      if (uVar13 != 0) {
        *(undefined4 *)(param_3 + 0x6c) = 1;
      }
    }
    else {
      *(int *)(param_3 + 0x6c) = local_298[0];
    }
    LVar6 = RegOpenKeyExW((HKEY)0xffffffff80000002,
                          L"Software\\Microsoft\\Windows\\CurrentVersion\\Diagnostics\\PerfTrack\\TraceProfile"
                          ,0,0x20019,&local_260);
    LVar3 = LVar2;
    if (LVar6 == 0) {
      local_280[0] = 0;
      LVar2 = RegQueryValueWithAlloc(local_260,L"svchost",1,&local_268,local_280);
      lpMem_00 = local_268;
      if ((LVar2 == 0) &&
         (iVar7 = CompareStringOrdinal(*(LPCWSTR *)(param_3 + 0x18),-1,local_268,-1,1), iVar7 == 2))
      {
        *(uint *)(param_3 + 0x70) = *(uint *)(param_3 + 0x70) | 4;
      }
    }
  }
  if (lpMem != (LPVOID)0x0) {
    HeapFree(g_hHeap,0,lpMem);
  }
  if (lpMem_00 != (LPCWSTR)0x0) {
    HeapFree(g_hHeap,0,lpMem_00);
  }
  if (lpMem_01 != (LPCOLESTR)0x0) {
    HeapFree(g_hHeap,0,lpMem_01);
  }
LAB_140006a35:
  if (local_290 != (HKEY)0x0) {
    RegCloseKey(local_290);
  }
  if (local_260 != (HKEY)0x0) {
    RegCloseKey(local_260);
  }
  return LVar3;
}



===== SvcHostNotificationCallback @ 140006aa0 =====

undefined8 SvcHostNotificationCallback(int param_1,LPCWSTR param_2,ulonglong *param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x32;
  if (param_1 == 0x60) {
    uVar1 = LowResourceNotificationCallback(param_2,param_3,(LPCWSTR)param_3,param_2);
  }
  return uVar1;
}



===== SvchostCharLowerW @ 140006ac8 =====

void SvchostCharLowerW(LPCWSTR param_1)

{
  int cchSrc;
  longlong lVar1;
  
  if (param_1 != (LPCWSTR)0x0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_1[lVar1] != L'\0');
    cchSrc = (int)lVar1 + 1;
    LCMapStringW(0x400,0x100,param_1,cchSrc,param_1,cchSrc);
  }
  return;
}



===== SvchostUnhandledExceptionFilter @ 140006b20 =====

void SvchostUnhandledExceptionFilter(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140006b20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnhandledExceptionFilter();
  return;
}



===== RegQueryStringA @ 140006b40 =====

DWORD RegQueryStringA(HKEY param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  LPCWSTR lpWideCharStr;
  DWORD DVar1;
  int cbMultiByte;
  int iVar2;
  LPSTR lpMultiByteStr;
  longlong lVar4;
  longlong lVar3;
  LPCWSTR local_res10;
  uint local_res18 [2];
  
  *param_4 = 0;
  local_res10 = (LPCWSTR)0x0;
  local_res18[0] = 0;
  DVar1 = RegQueryValueWithAlloc(param_1,L"ServiceMain",1,&local_res10,local_res18);
  lpWideCharStr = local_res10;
  if (DVar1 == 0) {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (local_res10[lVar3] != L'\0');
    iVar2 = (int)lVar4;
    cbMultiByte = WideCharToMultiByte(0,0x400,local_res10,iVar2 + 2,(LPSTR)0x0,0,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
    if (cbMultiByte != 0) {
      DVar1 = 0xe;
      lpMultiByteStr = HeapAlloc(g_hHeap,0,(longlong)cbMultiByte);
      if (lpMultiByteStr != (LPSTR)0x0) {
        DVar1 = 0;
        iVar2 = WideCharToMultiByte(0,0x400,lpWideCharStr,iVar2 + 2,lpMultiByteStr,cbMultiByte,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar2 == 0) {
          HeapFree(g_hHeap,0,lpMultiByteStr);
          DVar1 = GetLastError();
        }
        else {
          *param_4 = lpMultiByteStr;
        }
      }
    }
    HeapFree(g_hHeap,0,lpWideCharStr);
  }
  return DVar1;
}



===== GetAbsoluteSd @ 140006ca4 =====

/* unsigned long __cdecl GetAbsoluteSd(void * __ptr64,void * __ptr64 * __ptr64) */

ulong __cdecl GetAbsoluteSd(void *param_1,void **param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor;
  ulonglong uVar3;
  ulonglong uVar4;
  DWORD local_res18 [2];
  DWORD local_res20 [2];
  DWORD local_28;
  DWORD local_24;
  DWORD local_20 [2];
  
  local_24 = 0;
  local_28 = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_20[0] = 0;
  BVar1 = MakeAbsoluteSD(param_1,(PSECURITY_DESCRIPTOR)0x0,&local_24,(PACL)0x0,&local_28,(PACL)0x0,
                         local_res20,(PSID)0x0,local_res18,(PSID)0x0,local_20);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 == 0x7a) {
      DVar2 = 8;
      pAbsoluteSecurityDescriptor =
           (PSECURITY_DESCRIPTOR)
           RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8,
                           local_20[0] + local_res18[0] + local_res20[0] + local_28 + local_24);
      if (pAbsoluteSecurityDescriptor != (PSECURITY_DESCRIPTOR)0x0) {
        uVar4 = (ulonglong)local_24;
        uVar3 = (ulonglong)local_28;
        BVar1 = MakeAbsoluteSD(param_1,pAbsoluteSecurityDescriptor,&local_24,
                               (PACL)(uVar4 + (longlong)pAbsoluteSecurityDescriptor),&local_28,
                               (PACL)(uVar3 + uVar4 + (longlong)pAbsoluteSecurityDescriptor),
                               local_res20,
                               (PSID)(local_res20[0] + uVar3 + uVar4 +
                                     (longlong)pAbsoluteSecurityDescriptor),local_res18,
                               (PSID)((ulonglong)local_res18[0] + (ulonglong)local_res20[0] + uVar3
                                      + uVar4 + (longlong)pAbsoluteSecurityDescriptor),local_20);
        if (BVar1 == 0) {
          DVar2 = GetLastError();
          RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,
                      pAbsoluteSecurityDescriptor);
        }
        else {
          DVar2 = 0;
          *param_2 = pAbsoluteSecurityDescriptor;
        }
      }
    }
  }
  else {
    DVar2 = 0x57;
  }
  return DVar2;
}



===== InitializeSdFromProcessToken @ 140006e4c =====

/* unsigned long __cdecl InitializeSdFromProcessToken(int,int,int,int,void * __ptr64 *
   __ptr64,struct _ACL * __ptr64 * __ptr64) */

ulong __cdecl
InitializeSdFromProcessToken
          (int param_1,int param_2,int param_3,int param_4,void **param_5,_ACL **param_6)

{
  undefined8 *TokenInformation;
  BOOL BVar1;
  DWORD DVar2;
  HANDLE ProcessHandle;
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
  PACL pAcl;
  uint uVar3;
  DWORD DVar4;
  undefined8 *TokenInformation_00;
  DWORD AccessMask;
  DWORD AccessMask_00;
  DWORD local_res8 [2];
  DWORD local_res10 [2];
  HANDLE local_48 [2];
  
  local_res8[0] = 0;
  pSecurityDescriptor = (PSECURITY_DESCRIPTOR)0x0;
  local_res10[0] = 0;
  pAcl = (PACL)0x0;
  local_48[0] = (HANDLE)0x0;
  AccessMask_00 = 0;
  AccessMask = 0;
  if ((param_2 != 0) && (AccessMask_00 = 7, param_4 != 0)) {
    AccessMask_00 = 0x27;
  }
  if ((param_1 != 0) && (AccessMask = 7, param_4 != 0)) {
    AccessMask = 0x27;
  }
  *param_5 = (void *)0x0;
  *param_6 = (_ACL *)0x0;
  ProcessHandle = GetCurrentProcess();
  BVar1 = OpenProcessToken(ProcessHandle,8,local_48);
  if (BVar1 != 0) {
    BVar1 = GetTokenInformation(local_48[0],TokenUser,(LPVOID)0x0,0,local_res8);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      if (DVar2 != 0x7a) goto LAB_1400071fa;
    }
    BVar1 = GetTokenInformation(local_48[0],TokenPrimaryGroup,(LPVOID)0x0,0,local_res10);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      if (DVar2 != 0x7a) goto LAB_1400071fa;
    }
    uVar3 = local_res8[0] + 7 & 0xfffffff8;
    pSecurityDescriptor =
         (PSECURITY_DESCRIPTOR)
         RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),8,
                         local_res10[0] + 0x28 + uVar3);
    if (pSecurityDescriptor == (PSECURITY_DESCRIPTOR)0x0) {
LAB_140006fa1:
      DVar2 = 8;
      goto LAB_1400071fa;
    }
    TokenInformation = (undefined8 *)((longlong)pSecurityDescriptor + 0x28);
    TokenInformation_00 = (undefined8 *)((ulonglong)uVar3 + (longlong)TokenInformation);
    BVar1 = InitializeSecurityDescriptor(pSecurityDescriptor,1);
    if (BVar1 != 0) {
      BVar1 = GetTokenInformation(local_48[0],TokenUser,TokenInformation,local_res8[0],local_res8);
      if (BVar1 != 0) {
        BVar1 = GetTokenInformation(local_48[0],TokenPrimaryGroup,TokenInformation_00,local_res10[0]
                                    ,local_res10);
        if (BVar1 != 0) {
          BVar1 = SetSecurityDescriptorOwner(pSecurityDescriptor,(PSID)*TokenInformation,0);
          if (BVar1 != 0) {
            BVar1 = SetSecurityDescriptorGroup(pSecurityDescriptor,(PSID)*TokenInformation_00,0);
            if (BVar1 != 0) {
              DVar2 = GetLengthSid(&DAT_14000a420);
              DVar4 = DVar2 + 0x10;
              if (AccessMask != 0) {
                DVar4 = GetLengthSid(&DAT_14000a400);
                DVar4 = DVar2 + 0x18 + DVar4;
              }
              if (AccessMask_00 != 0) {
                DVar2 = GetLengthSid(&DAT_14000a410);
                DVar4 = DVar4 + DVar2 + 8;
              }
              if (param_3 != 0) {
                DVar2 = GetLengthSid(&DAT_14000a3d0);
                DVar4 = DVar4 + DVar2 + 8;
              }
              pAcl = (PACL)RtlAllocateHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30)
                                           ,8,DVar4);
              if (pAcl == (PACL)0x0) goto LAB_140006fa1;
              BVar1 = InitializeAcl(pAcl,DVar4,2);
              if (BVar1 != 0) {
                BVar1 = AddAccessAllowedAce(pAcl,2,7,&DAT_14000a420);
                if (BVar1 != 0) {
                  if (AccessMask != 0) {
                    BVar1 = AddAccessAllowedAce(pAcl,2,AccessMask,&DAT_14000a400);
                    if (BVar1 == 0) goto LAB_140006eda;
                  }
                  if (AccessMask_00 != 0) {
                    BVar1 = AddAccessAllowedAce(pAcl,2,AccessMask_00,&DAT_14000a410);
                    if (BVar1 == 0) goto LAB_140006eda;
                  }
                  if (param_3 != 0) {
                    BVar1 = AddAccessAllowedAce(pAcl,2,7,&DAT_14000a3d0);
                    if (BVar1 == 0) goto LAB_140006eda;
                  }
                  BVar1 = SetSecurityDescriptorDacl(pSecurityDescriptor,1,pAcl,0);
                  if (BVar1 != 0) {
                    *param_5 = pSecurityDescriptor;
                    pSecurityDescriptor = (PSECURITY_DESCRIPTOR)0x0;
                    *param_6 = pAcl;
                    pAcl = (PACL)0x0;
                    DVar2 = 0;
                    goto LAB_1400071fa;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_140006eda:
  DVar2 = GetLastError();
LAB_1400071fa:
  if (local_48[0] != (HANDLE)0x0) {
    CloseHandle(local_48[0]);
  }
  if (pSecurityDescriptor != (PSECURITY_DESCRIPTOR)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pSecurityDescriptor);
  }
  if (pAcl != (PACL)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,pAcl);
  }
  return DVar2;
}



===== InitializeSecurity @ 140007278 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint InitializeSecurity(longlong param_1)

{
  ulong uVar1;
  uint uVar2;
  longlong lVar3;
  longlong *local_res8;
  void *local_res10;
  _ACL *local_res18 [2];
  
  uVar2 = *(uint *)(param_1 + 0x70);
  local_res10 = (PSECURITY_DESCRIPTOR)0x0;
  local_res18[0] = (_ACL *)0x0;
  local_res8 = (longlong *)0x0;
  if (*(void **)(param_1 + 0x78) == (void *)0x0) {
    uVar1 = InitializeSdFromProcessToken
                      ((uint)((uVar2 & 2) != 0),(uint)((uVar2 & 0x10) != 0),
                       (uint)((uVar2 & 0x20) != 0),(uint)((uVar2 & 0x40) != 0),&local_res10,
                       local_res18);
  }
  else {
    uVar1 = GetAbsoluteSd(*(void **)(param_1 + 0x78),&local_res10);
  }
  if (uVar1 == 0) {
    uVar2 = CoInitializeEx((LPVOID)0x0,4);
    if (((((-1 < (int)uVar2) &&
          (uVar2 = CoCreateInstance((IID *)&CLSID_GlobalOptions,(LPUNKNOWN)0x0,1,
                                    (IID *)&IID_IGlobalOptions,&local_res8), -1 < (int)uVar2)) &&
         ((*(int *)(param_1 + 0x4c) == 0xffff ||
          (uVar2 = (**(code **)(*local_res8 + 0x18))(local_res8,4,*(undefined4 *)(param_1 + 0x4c)),
          -1 < (int)uVar2)))) &&
        ((((ServiceCount < 2 ||
           (uVar2 = (**(code **)(*local_res8 + 0x18))(local_res8,8,1), -1 < (int)uVar2)) &&
          (uVar2 = CoInitializeSecurity
                             (local_res10,-1,(SOLE_AUTHENTICATION_SERVICE *)0x0,(void *)0x0,
                              *(DWORD *)(param_1 + 0x2c),*(DWORD *)(param_1 + 0x30),(void *)0x0,
                              *(DWORD *)(param_1 + 0x34),(void *)0x0), -1 < (int)uVar2)) &&
         (uVar2 = (**(code **)(*local_res8 + 0x18))(local_res8,1,2), -1 < (int)uVar2)))) &&
       (((*(int *)(param_1 + 0x48) == 0xffff ||
         (uVar2 = (**(code **)(*local_res8 + 0x18))(local_res8,5,*(undefined4 *)(param_1 + 0x48)),
         -1 < (int)uVar2)) && (ServiceCount == 1)))) {
      lVar3 = *(longlong *)(param_1 + 0x38);
      if (lVar3 == 0) {
        lVar3 = *(longlong *)(param_1 + 0x40);
      }
      if (lVar3 != 0) {
        uVar2 = (**(code **)(*local_res8 + 0x18))(local_res8,2);
      }
    }
  }
  else {
    uVar2 = 0x80070000;
    if ((int)uVar1 < 1) {
      uVar2 = uVar1;
    }
  }
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x10))();
  }
  if (local_res10 != (PSECURITY_DESCRIPTOR)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_res10);
  }
  if (local_res18[0] != (_ACL *)0x0) {
    RtlFreeHeap(*(undefined8 *)((longlong)ProcessEnvironmentBlock + 0x30),0,local_res18[0]);
  }
  return ~uVar2 >> 0x1f;
}



===== LowResourceNotificationCallback @ 1400074f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
LowResourceNotificationCallback
          (LPCWSTR param_1,ulonglong *param_2,LPCWSTR param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  LPCWSTR pWVar3;
  ulonglong uVar4;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [2];
  ulonglong local_80;
  _EVENT_DATA_DESCRIPTOR local_78 [2];
  longlong local_58 [2];
  ulonglong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  iVar1 = QueryServiceHeapInformation();
  if (iVar1 == 0) {
    TelemetryState = 1;
    DoSvchostHeapInfoTelemetry();
    TelemetryState = 2;
    ArmTheServiceMemoryTracingTimer();
  }
  pWVar3 = (LPCWSTR)(ulonglong)ServiceCount;
  if (ServiceCount == 1) {
LAB_1400075aa:
    *(undefined4 *)(param_2 + 1) = 1;
  }
  else {
    *(undefined4 *)(param_2 + 1) = 0;
    for (uVar4 = 0; (uint)uVar4 < (uint)pWVar3; uVar4 = (ulonglong)((uint)uVar4 + 1)) {
      param_3 = (LPCWSTR)(uVar4 * 0x60);
      if ((*(int *)((longlong)param_3 + ServiceArray + 0x30) != 0) &&
         (*param_2 <= *(ulonglong *)((longlong)param_3 + ServiceArray + 0x48))) {
        param_3 = *(LPCWSTR *)((longlong)param_3 + ServiceArray);
        param_4 = 0xffffffff;
        pWVar3 = param_1;
        iVar1 = CompareStringOrdinal(param_1,-1,param_3,-1,1);
        if (iVar1 == 2) goto LAB_1400075aa;
        pWVar3 = (LPCWSTR)(ulonglong)ServiceCount;
      }
    }
  }
  if (5 < DAT_14000e000) {
    uVar2 = _tlgKeywordOn(pWVar3,0x400000000000);
    if ((char)uVar2 != '\0') {
      _tlgCreate1Sz_wchar_t(local_58,(longlong)param_1);
      local_80 = *param_2;
      local_48 = &local_80;
      local_3c = 0;
      local_2c = 0;
      local_88[0] = (undefined4)param_2[1];
      local_38 = local_88;
      local_40 = 8;
      local_30 = 4;
      _tlgWriteTransfer_EventWriteTransfer(local_80,&DAT_14000a8f5,param_3,param_4,5,local_78);
    }
  }
  return 0;
}



===== RpcpAddInterface @ 140007654 =====

long RpcpAddInterface(longlong param_1,RPC_IF_HANDLE param_2,undefined8 param_3)

{
  uint uVar1;
  RPC_STATUS Status;
  long lVar2;
  RPC_WSTR Endpoint;
  RPC_WSTR puVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (*(short *)(param_1 + lVar4 * 2) != 0);
  uVar5 = lVar4 * 2 + 0x10;
  Endpoint = LocalAlloc(0,uVar5);
  if (Endpoint == (RPC_WSTR)0x0) {
    lVar2 = -0x3fffffe9;
  }
  else {
    uVar5 = uVar5 >> 1;
    if (uVar5 != 0) {
      if (uVar5 < 0x80000000) {
        uVar1 = RtlStringCopyWorkerW((short *)Endpoint,uVar5,param_3,0x14000a438);
        if (-1 < (int)uVar1) {
          puVar3 = Endpoint;
          uVar6 = uVar5;
          do {
            if (*puVar3 == 0) break;
            puVar3 = puVar3 + 1;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
          if ((uVar6 != 0) &&
             (uVar1 = RtlStringCopyWorkerW
                                ((short *)(Endpoint + (uVar5 - uVar6)),uVar5 - (uVar5 - uVar6),
                                 param_3,param_1), -1 < (int)uVar1)) {
            Status = RpcServerUseProtseqEpW((RPC_WSTR)L"ncacn_np",10,Endpoint,(void *)0x0);
            if ((Status == 0) || (Status == 0x6cc)) {
              Status = RpcServerRegisterIf(param_2,(UUID *)0x0,(void *)0x0);
            }
            LocalFree(Endpoint);
            lVar2 = I_RpcMapWin32Status(Status);
            return lVar2;
          }
        }
      }
      else {
        *Endpoint = 0;
      }
    }
    LocalFree(Endpoint);
    lVar2 = -0x3ffffff3;
  }
  return lVar2;
}



===== RpcpStartRpcServer @ 1400077b0 =====

void RpcpStartRpcServer(longlong param_1,RPC_IF_HANDLE param_2,undefined8 param_3)

{
  long Status;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_14000e770);
  Status = RpcpAddInterface(param_1,param_2,param_3);
  if (Status == 0) {
    DAT_14000e768 = DAT_14000e768 + 1;
    if (DAT_14000e768 == 1) {
      Status = RpcServerListen(1,0x3039,1);
      if (Status == 0x6b1) {
        Status = 0;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_14000e770);
                    /* WARNING: Could not recover jumptable at 0x000140007838. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  I_RpcMapWin32Status(Status);
  return;
}



===== RpcpStopRpcServer @ 140007850 =====

void RpcpStopRpcServer(RPC_IF_HANDLE param_1)

{
  RPC_STATUS Status;
  
  Status = RpcServerUnregisterIf(param_1,(UUID *)0x0,1);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_14000e770);
  DAT_14000e768 = DAT_14000e768 + -1;
  if (DAT_14000e768 == 0) {
    RpcMgmtStopServerListening((RPC_BINDING_HANDLE)0x0);
    RpcMgmtWaitServerListen();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_14000e770);
                    /* WARNING: Could not recover jumptable at 0x0001400078ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  I_RpcMapWin32Status(Status);
  return;
}



===== RpcpStopRpcServerEx @ 1400078d0 =====

void RpcpStopRpcServerEx(undefined8 param_1)

{
  RPC_STATUS Status;
  
  Status = RpcServerUnregisterIfEx(param_1,0,1);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_14000e770);
  DAT_14000e768 = DAT_14000e768 + -1;
  if (DAT_14000e768 == 0) {
    RpcMgmtStopServerListening((RPC_BINDING_HANDLE)0x0);
    RpcMgmtWaitServerListen();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_14000e770);
                    /* WARNING: Could not recover jumptable at 0x00014000793a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  I_RpcMapWin32Status(Status);
  return;
}



===== RtlStringCopyWorkerW @ 14000794c =====

uint RtlStringCopyWorkerW(short *param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  longlong lVar4;
  
  if (param_2 != 0) {
    lVar2 = 0x7ffffffe;
    lVar4 = param_4 - (longlong)param_1;
    do {
      if ((lVar2 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      lVar2 = lVar2 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar3 = param_1 + -1;
  if (param_2 != 0) {
    psVar3 = param_1;
  }
  *psVar3 = 0;
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== __GSHandlerCheck @ 1400079a8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400079cc =====

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



===== memcpy @ 140007a2d =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140007a2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== _guard_dispatch_icall @ 140007a60 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007a80 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007a80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140007aa0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== filt$0 @ 140007aac =====

void `__scrt_common_main_seh'::__l1::filt_0(undefined8 *param_1)

{
  _o__seh_filter_exe(*(undefined4 *)*param_1,param_1);
  return;
}



===== __scrt_is_nonwritable_in_current_image$filt$0 @ 140007ad0 =====

bool __scrt_is_nonwritable_in_current_image_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 140008010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


