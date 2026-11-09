
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== DriverEntry @ 140001020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,wchar_t *param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  wchar_t *pwVar4;
  undefined2 uVar5;
  undefined1 auStackY_2f8 [32];
  undefined1 uVar6;
  longlong local_2b8;
  wchar_t local_2b0 [4];
  undefined1 *local_2a8;
  undefined8 local_2a0;
  ulonglong local_298;
  undefined8 local_290;
  code *local_288;
  undefined4 local_280;
  undefined4 local_27c;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined4 local_238;
  uint local_234;
  uint local_230;
  undefined1 local_118 [208];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2f8;
  local_2b0[0] = L'\0';
  local_2b0[1] = L'È';
  local_2b0[2] = L'\0';
  local_2b0[3] = L'\0';
  local_298 = (ulonglong)(uint)local_298;
  local_2a0 = 0;
  local_2a8 = local_118;
  local_2b8 = 0;
  uVar3 = 0x110;
  memset(&local_234,0,0x110);
  local_238 = 0x114;
  iVar1 = RtlGetVersion(&local_238);
  if ((-1 < iVar1) && ((6 < local_234 || ((local_234 == 6 && (1 < local_230)))))) {
    _ExDefaultNonPagedPoolType = 0x200;
    ExDefaultMdlProtection = 0x40000000;
  }
  _WPP_MAIN_CB = 0;
  DAT_14000e488 = &WPP_ThisDir_CTLGUID_UDEHID;
  _DAT_14000e4a8 = 1;
  DAT_14000e490 = 0;
  _DAT_14000e4a0 = 0;
  _DAT_14000e4c0 = 0;
  _DAT_14000e4c8 = 0;
  WppLoadTracingSupport();
  _DAT_14000e4a0 = 0;
  WppInitKm(param_1,param_2);
  uVar6 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar3,10,
                      &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids,uVar6);
  }
  local_298 = 0x20;
  local_248 = 0;
  local_268 = 0;
  local_288 = Driver_EvtDriverUnload;
  uStack_270 = 0;
  local_278 = 0x38;
  local_258 = 0;
  uStack_250 = 0;
  uStack_260 = 0x100000001;
  local_290 = 0;
  local_280 = 1;
  local_27c = 0x78454455;
  pwVar4 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,&local_278);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400013d6;
    uVar5 = 0xb;
  }
  else {
    pwVar4 = L"\x06\b";
    local_2b8 = (**(code **)(WdfFunctions_01015 + 200))(WdfDriverGlobals,*WdfDriverGlobals);
    if (local_2b8 == 0) {
      iVar1 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400013d6;
      uVar5 = 0xc;
      iVar1 = -0x3fffff66;
    }
    else {
      uVar2 = 0;
      iVar1 = -0x3fffffcb;
      do {
        if (99 < uVar2) goto LAB_1400013a7;
        pwVar4 = L"\\Device\\Udecx";
        uVar3 = RtlUnicodeStringPrintf
                          ((ushort *)local_2b0,L"%s%u",L"\\Device\\Udecx",(ulonglong)uVar2);
        iVar1 = (int)uVar3;
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400013d6;
          uVar5 = 0xd;
LAB_140001387:
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pwVar4,uVar5,
                             &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids,uVar6,(char)iVar1);
          goto LAB_1400013a7;
        }
        pwVar4 = local_2b0;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,local_2b8);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar5 = 0xe;
            goto LAB_140001387;
          }
          goto LAB_1400013d6;
        }
        pwVar4 = (wchar_t *)0x0;
        iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                          (WdfDriverGlobals,&local_2b8,0,&g_ClassLibraryDevice);
        uVar2 = uVar2 + 1;
      } while (iVar1 == -0x3fffffcb);
      if (iVar1 < 0) {
LAB_1400013a7:
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400013d6;
        uVar5 = 0xf;
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0xd8))(WdfDriverGlobals,g_ClassLibraryDevice);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        pwVar4 = local_2b0;
        iVar1 = WdfRegisterClassLibrary(&g_WdfClassLibraryInfo,param_2);
        if ((-1 < iVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
        goto LAB_1400013d6;
        uVar5 = 0x11;
      }
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pwVar4,uVar5,
                     &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids,uVar6,(char)iVar1);
LAB_1400013d6:
  if (local_2b8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
  }
  if (iVar1 < 0) {
    if (g_ClassLibraryDevice != (WDFDEVICE__ *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
    }
    WppCleanupKm(param_1);
  }
  return iVar1;
}



===== Driver_CxBindClient @ 140001470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Driver_CxBindClient(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined8 *puVar2;
  undefined **ppuVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined **ppuVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined2 uVar12;
  undefined *in_stack_ffffffffffffffc8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffc8 = &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x15,
                     &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids);
  }
  uVar11 = *WdfDriverGlobals;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x3b0))();
  if (*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x16,
                       &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids);
    }
    return 0xc000000d;
  }
  **(undefined8 **)(param_1 + 0x30) = 0;
  uVar8 = *(uint *)(param_1 + 0x10);
  if (uVar8 == 1) {
    uVar8 = *(uint *)(param_1 + 0x14);
    if (DAT_14000e008 < uVar8) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar12 = 0x18;
      uVar5 = DAT_14000e008;
      goto LAB_14000154c;
    }
    if (uVar8 == 0) {
      uVar5 = 0x21;
    }
    else if (uVar8 == 1) {
      uVar5 = 0x22;
    }
    else {
      uVar5 = 0;
    }
    uVar8 = *(uint *)(param_1 + 0x28);
    if (uVar8 == uVar5) {
      uVar11 = 0x78454455;
      puVar6 = (undefined4 *)ExAllocatePool2(0x40);
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = 0x10;
        lVar10 = 2;
        *(undefined8 *)(puVar6 + 2) = param_2;
        **(undefined8 **)(param_1 + 0x30) = puVar6;
        puVar2 = *(undefined8 **)(param_1 + 0x20);
        ppuVar3 = &PTR__UdecxUrbRetrieveControlSetupPacket_14000e038;
        do {
          ppuVar9 = ppuVar3;
          puVar7 = puVar2;
          puVar1 = ppuVar9[1];
          *puVar7 = *ppuVar9;
          puVar7[1] = puVar1;
          puVar1 = ppuVar9[3];
          puVar7[2] = ppuVar9[2];
          puVar7[3] = puVar1;
          puVar1 = ppuVar9[5];
          puVar7[4] = ppuVar9[4];
          puVar7[5] = puVar1;
          puVar1 = ppuVar9[7];
          puVar7[6] = ppuVar9[6];
          puVar7[7] = puVar1;
          puVar1 = ppuVar9[9];
          puVar7[8] = ppuVar9[8];
          puVar7[9] = puVar1;
          puVar1 = ppuVar9[0xb];
          puVar7[10] = ppuVar9[10];
          puVar7[0xb] = puVar1;
          puVar1 = ppuVar9[0xd];
          puVar7[0xc] = ppuVar9[0xc];
          puVar7[0xd] = puVar1;
          puVar1 = ppuVar9[0xf];
          puVar7[0xe] = ppuVar9[0xe];
          puVar7[0xf] = puVar1;
          lVar10 = lVar10 + -1;
          puVar2 = puVar7 + 0x10;
          ppuVar3 = ppuVar9 + 0x10;
        } while (lVar10 != 0);
        puVar1 = ppuVar9[0x11];
        puVar7[0x10] = ppuVar9[0x10];
        puVar7[0x11] = puVar1;
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000009a;
      }
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar11,0x1a,
                        &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids,uVar4);
      return 0xc000009a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar12 = 0x19;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar12 = 0x17;
    uVar5 = DAT_14000e004;
  }
LAB_14000154c:
  WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar11,param_3,uVar12,
                      in_stack_ffffffffffffffc8,uVar4,(char)uVar8,(char)uVar5);
  return 0xc000000d;
}



===== Driver_CxDeinitialize @ 1400016c0 =====

void Driver_CxDeinitialize(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x14,
                     &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids);
  }
  return;
}



===== Driver_CxInitialize @ 140001710 =====

undefined8 Driver_CxInitialize(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x13,
                     &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids);
  }
  return 0;
}



===== Driver_CxUnbindClient @ 140001760 =====

void Driver_CxUnbindClient(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x1b,
                     &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids);
  }
  if ((*(longlong **)(param_1 + 0x30) != (longlong *)0x0) &&
     (lVar1 = **(longlong **)(param_1 + 0x30), lVar1 != 0)) {
    ExFreePoolWithTag(lVar1,0x78454455);
    **(undefined8 **)(param_1 + 0x30) = 0;
  }
  return;
}



===== Driver_EvtDriverUnload @ 1400017e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Driver_EvtDriverUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x12,
                      &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids,(char)uVar1);
  }
  if (g_ClassLibraryDevice != (WDFDEVICE__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
  }
  WppCleanupKm(uVar1);
  return;
}



===== RtlUnicodeStringPrintf @ 140001884 =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== WPP_RECORDER_SF_ @ 140001924 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                     undefined8 param_5)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 1400019b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qLL @ 140001a64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qZ @ 140001b5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qZ(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  
  pwVar3 = L"NULL";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  goto LAB_140001c24;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_140001bcd:
    pwVar4 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 == L'\0') goto LAB_140001bcd;
    pwVar4 = *(wchar_t **)(in_stack_00000038 + 4);
  }
  pwVar2 = in_stack_00000038;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids,0x10,&uStack0000000000000030,8,pwVar2,
             2,pwVar4,wVar1,0);
LAB_140001c24:
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 != L'\0') {
      pwVar3 = *(wchar_t **)(in_stack_00000038 + 4);
    }
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"\b";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_0f046b77a1033339ccef213a6d7eb63b_Traceguids,0x10,
                  &uStack0000000000000030,8,in_stack_00000038,2,pwVar3,wVar1,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 140001cbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 140001da0 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== Controller_ContextCleanup @ 140001e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Controller_ContextCleanup(void * __ptr64) */

void __cdecl Controller_ContextCleanup(void *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  if (*(code **)(lVar1 + 0x48) != (code *)0x0) {
    (**(code **)(lVar1 + 0x48))(*(undefined8 *)(lVar1 + 0x38));
  }
  memset((void *)(lVar1 + 0x30),0,0x50);
  return;
}



===== Controller_EvtControllerQueryUsbCapability @ 140001e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Controller_EvtControllerQueryUsbCapability(struct UCXCONTROLLER__ * __ptr64,struct
   _GUID * __ptr64,unsigned long,void * __ptr64,unsigned long * __ptr64) */

long __cdecl
Controller_EvtControllerQueryUsbCapability
          (UCXCONTROLLER__ *param_1,_GUID *param_2,ulong param_3,void *param_4,ulong *param_5)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCX_CONTROLLER_CONTEXT_TYPE_INFO_14000e250);
  uVar1 = *puVar3;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  *param_5 = 0;
  lVar5 = RtlCompareMemory(param_2,&GUID_USB_CAPABILITY_FUNCTION_SUSPEND,0x10);
  if (lVar5 == 0x10) {
    return 0;
  }
  lVar5 = RtlCompareMemory(param_2,&GUID_USB_CAPABILITY_SELECTIVE_SUSPEND,0x10);
  if (lVar5 == 0x10) {
    return 0;
  }
  uVar6 = 0x10;
  lVar5 = RtlCompareMemory(param_2,&GUID_USB_CAPABILITY_STATIC_STREAMS);
  if (lVar5 == 0x10) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff45;
    }
    uVar7 = 0x16;
  }
  else {
    uVar6 = 0x10;
    lVar5 = RtlCompareMemory(param_2,&GUID_USB_CAPABILITY_CLEAR_TT_BUFFER_ON_ASYNC_TRANSFER_CANCEL);
    if (lVar5 != 0x10) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DDDDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      lVar2 = (**(code **)(lVar4 + 0x18))(uVar1,param_2,param_3,param_4,param_5);
      return lVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff45;
    }
    uVar7 = 0x17;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar6,uVar7,
                   &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids);
  return -0x3fffff45;
}



===== Controller_EvtControllerReset @ 1400020a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Controller_EvtControllerReset(struct UCXCONTROLLER__ * __ptr64) */

void __cdecl Controller_EvtControllerReset(UCXCONTROLLER__ *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  ulong uVar6;
  uint uVar7;
  undefined1 auStack_48 [32];
  _PORT_CONTEXT *local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = (_PORT_CONTEXT *)0x0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCX_CONTROLLER_CONTEXT_TYPE_INFO_14000e250);
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*puVar2,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,puVar3[1],PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  uStack_1c = 1;
  local_18 = 1;
  local_20 = 0xc;
  if (*(int *)(puVar3 + 4) == 0) {
    uVar7 = *(int *)(lVar4 + 0xc) + *(int *)(lVar4 + 8);
    RootHub_LockAcquire(*(WDFSPINLOCK__ **)(lVar4 + 0x10));
    uVar6 = 0;
    if (uVar7 != 0) {
      do {
        lVar1 = RootHub_PortContextFromPortNumber((UCXROOTHUB__ *)puVar3[1],uVar6,&local_28);
        if ((-1 < lVar1) && (*(longlong *)(local_28 + 8) != 0)) {
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,*(longlong *)(local_28 + 8),
                             PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
          *(undefined1 *)(lVar5 + 0x35) = 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar7);
    }
    RootHub_LockRelease(*(WDFSPINLOCK__ **)(lVar4 + 0x10));
  }
  else if ((code *)puVar3[5] != (code *)0x0) {
    (*(code *)puVar3[5])(*puVar2);
    return;
  }
  (*DAT_14000e758)(UcxDriverGlobals,*puVar3,&local_20);
  return;
}



===== Controller_EvtControllerUsbDeviceAdd @ 140002230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Controller_EvtControllerUsbDeviceAdd(struct UCXCONTROLLER__ * __ptr64,struct
   _UCXUSBDEVICE_INFO * __ptr64,struct _UCXUSBDEVICE_INIT * __ptr64) */

long __cdecl
Controller_EvtControllerUsbDeviceAdd
          (UCXCONTROLLER__ *param_1,_UCXUSBDEVICE_INFO *param_2,_UCXUSBDEVICE_INIT *param_3)

{
  long lVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCX_CONTROLLER_CONTEXT_TYPE_INFO_14000e250);
  lVar1 = UsbDevice_UcxUsbDeviceCreate((WDFDEVICE__ *)*puVar2,param_2,param_3);
  return lVar1;
}



===== Controller_EvtDeviceWdmIrpPnPPreprocess @ 140002290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140002311) */
/* long __cdecl Controller_EvtDeviceWdmIrpPnPPreprocess(struct WDFDEVICE__ * __ptr64,struct _IRP *
   __ptr64) */

long __cdecl Controller_EvtDeviceWdmIrpPnPPreprocess(WDFDEVICE__ *param_1,_IRP *param_2)

{
  long lVar1;
  longlong lVar2;
  bool bVar3;
  
  if ((**(char **)(param_2 + 0xb8) == '\x1b') && ((*(char **)(param_2 + 0xb8))[1] == '\x01')) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
    bVar3 = *(char *)(lVar2 + 0x88) != '\0';
    if (bVar3) {
      *(undefined4 *)(param_2 + 0x30) = 0xc0000507;
    }
    if (*(int *)(lVar2 + 0x84) == 2) {
      *(undefined4 *)(lVar2 + 0x84) = 0;
      *(undefined4 *)(lVar2 + 0x80) = 0;
    }
    if (bVar3) {
      lVar1 = *(long *)(param_2 + 0x30);
      IofCompleteRequest(param_2,0);
      return lVar1;
    }
  }
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return lVar1;
}



===== Controller_UcxControllerCreate @ 140002374 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Controller_UcxControllerCreate(struct WDFDEVICE__ * __ptr64,struct UCXCONTROLLER__ *
   __ptr64 * __ptr64) */

long __cdecl Controller_UcxControllerCreate(WDFDEVICE__ *param_1,UCXCONTROLLER__ **param_2)

{
  long lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  char *pcVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 *puVar8;
  ulonglong *puVar9;
  undefined1 auStackY_1e8 [32];
  ulonglong local_1a0;
  undefined *local_198;
  undefined8 local_190;
  ulonglong local_188 [6];
  undefined *local_158;
  undefined4 local_148;
  undefined4 local_144;
  code *local_140;
  code *local_128;
  code *local_120;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined2 local_f4;
  undefined8 local_f0;
  undefined4 local_e8;
  _UCX_CONTROLLER_ACPI_INFORMATION local_e4 [5];
  undefined1 local_df;
  undefined1 local_da;
  char local_d5 [141];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1e8;
  *param_2 = (UCXCONTROLLER__ *)0x0;
  local_1a0 = (ulonglong)(uint)local_1a0;
  local_190 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  memset(&local_148,0,0xf8);
  local_144 = 0xffffffff;
  local_148 = 0xf8;
  local_fc = 0x7fffffff;
  lVar6 = 0x28;
  local_f8 = 0x7fffffff;
  pcVar5 = local_d5;
  local_100 = 0;
  lVar7 = (longlong)"" - (longlong)local_d5;
  local_e4[0] = (_UCX_CONTROLLER_ACPI_INFORMATION)0x0;
  local_df = 0;
  local_da = 0;
  local_f4 = 0;
  local_f0 = 0;
  local_e8 = 0;
  do {
    if (lVar6 == -0x7fffffd6) goto LAB_140002460;
    if (pcVar5[lVar7] == '\0') break;
    *pcVar5 = pcVar5[lVar7];
    pcVar5 = pcVar5 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  if (lVar6 == 0) {
    pcVar5 = pcVar5 + -1;
  }
LAB_140002460:
  *pcVar5 = '\0';
  local_128 = Controller_EvtControllerUsbDeviceAdd;
  local_140 = Controller_EvtControllerQueryUsbCapability;
  local_120 = Controller_EvtControllerReset;
  lVar1 = Controller_WdfDeviceRetrieveAcpiDataSynchronously(param_1,local_e4);
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,lVar7,0x10,
                        &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,(char)lVar1);
    }
    local_100 = 0;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,lVar7,0x11,
                       &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids);
    }
    local_100 = 2;
  }
  puVar8 = &local_148;
  local_158 = PTR__WDF_UCX_CONTROLLER_CONTEXT_TYPE_INFO_14000e250;
  local_188[2] = 0;
  local_188[1] = 0;
  local_188[0] = 0x38;
  local_188[4] = 0;
  local_188[5] = 0;
  local_188[3] = 0x100000001;
  iVar2 = (*DAT_14000e748)(UcxDriverGlobals,param_1,puVar8,local_188);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar8,0x12,
                      &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,(char)iVar2);
    return iVar2;
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*param_2,PTR__WDF_UCX_CONTROLLER_CONTEXT_TYPE_INFO_14000e250)
  ;
  puVar9 = &local_1a0;
  *puVar4 = param_1;
  local_198 = &DEVPKEY_Device_UsbHostController_IsEmulated;
  local_1a0 = 0x18;
  local_190 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xd98))(WdfDriverGlobals,param_1,puVar9,0x11);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000267c;
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar9,0x13,
                      &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,(char)iVar2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar9,0x14,
                      &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,(char)*param_2);
  }
LAB_14000267c:
  lVar1 = RootHub_UcxRootHubCreate(*param_2,(UCXROOTHUB__ **)(lVar3 + 8));
  if ((-1 < lVar1) &&
     (QueryDeviceResetInterface(param_1,(undefined4 *)(lVar3 + 0x30)),
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar9,0x15,
                      &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,
                      (char)*(undefined8 *)(lVar3 + 8));
  }
  return lVar1;
}



===== Controller_WdfDeviceRetrieveAcpiDataSynchronously @ 140002700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Controller_WdfDeviceRetrieveAcpiDataSynchronously(struct WDFDEVICE__ *
   __ptr64,struct _UCX_CONTROLLER_ACPI_INFORMATION * __ptr64) */

long __cdecl
Controller_WdfDeviceRetrieveAcpiDataSynchronously
          (WDFDEVICE__ *param_1,_UCX_CONTROLLER_ACPI_INFORMATION *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 uVar7;
  
  *(undefined8 *)param_2 = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined2 *)(param_2 + 0xc) = 0;
  param_2[0xe] = (_UCX_CONTROLLER_ACPI_INFORMATION)0x0;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  uVar7 = 0;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar4,0,0x32c028);
  if (iVar3 != -0x7ffffffb) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x19,
                        &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,(char)iVar3);
    }
    if (iVar3 < 0) {
      return iVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffff;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x1a,
                     &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids);
    return -0x3fffffff;
  }
  lVar5 = ExAllocatePool2(0x40,0);
  if (lVar5 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    return -0x3fffff66;
  }
  uVar7 = 0;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar4,0,0x32c028);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x1c,
                        &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,(char)iVar3);
    }
  }
  else {
    RtlStringCchPrintfA((char *)(param_2 + 10),5,"%04X",(ulonglong)*(ushort *)(lVar5 + 0x1a));
    uVar1 = *(ushort *)(lVar5 + 8);
    if (uVar1 == 0) {
      RtlStringCchPrintfA((char *)param_2,5,"%s","UKWN");
    }
    else {
      uVar2 = *(ushort *)(lVar5 + 0xc);
      if (uVar2 == 0) {
        uVar6 = (uint)*(ushort *)(lVar5 + 10);
      }
      else {
        uVar6 = (uint)uVar2 - (uint)uVar1;
      }
      memcpy(param_2,(void *)(lVar5 + (ulonglong)uVar1),(ulonglong)uVar6);
      if (uVar2 != 0) {
        memcpy(param_2 + 5,(void *)(lVar5 + (ulonglong)uVar2),
               (ulonglong)(*(ushort *)(lVar5 + 10) - uVar6));
        goto LAB_1400029c3;
      }
    }
    RtlStringCchPrintfA((char *)(param_2 + 5),5,"%s","FFFF");
  }
LAB_1400029c3:
  ExFreePoolWithTag(lVar5,0x78454455);
  return iVar3;
}



===== RtlStringCchPrintfA @ 140002a08 =====

undefined8 RtlStringCchPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar2;
}



===== WPP_RECORDER_SF_D @ 140002a7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,0x1b,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,0x1b,
                  &uStack0000000000000030,4,0);
  return;
}



===== WPP_RECORDER_SF_DDDDDDDDDDD @ 140002b28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDDDDDDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,0x18,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,0x18,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 140002d2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,4,0);
  return;
}



===== _UdecxInitializeWdfDeviceInit @ 140002de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int _UdecxInitializeWdfDeviceInit(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  code *pcVar2;
  undefined2 uVar3;
  undefined1 local_res18 [16];
  
  iVar1 = (*DAT_14000e7e8)(UcxDriverGlobals);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 10;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0xd70))(WdfDriverGlobals,param_2,2);
    local_res18[0] = 1;
    pcVar2 = Controller_EvtDeviceWdmIrpPnPPreprocess;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                      (WdfDriverGlobals,param_2,Controller_EvtDeviceWdmIrpPnPPreprocess,0x1b,
                       local_res18,1);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0xb;
    param_3 = pcVar2;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,uVar3,
                    &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,(char)iVar1);
  return iVar1;
}



===== _UdecxWdfDeviceAddUsbDeviceEmulation @ 140002ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int _UdecxWdfDeviceAddUsbDeviceEmulation
              (undefined8 param_1,WDFDEVICE__ *param_2,undefined8 *param_3)

{
  UCXCONTROLLER__ *pUVar1;
  int iVar2;
  UCXCONTROLLER__ **ppUVar3;
  undefined4 *puVar4;
  undefined1 auStackY_98 [32];
  undefined4 local_68;
  undefined4 local_64;
  code *local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_64 = 0;
  local_58 = 0;
  local_1c = 0;
  local_30 = 0x9d7debbc;
  uStack_2c = 0x11d1c85d;
  uStack_28 = 0x6000b49e;
  uStack_24 = 0x9aa1c308;
  local_20 = 0xf;
  local_48 = 0;
  uStack_40 = 0;
  (**(code **)(WdfFunctions_01015 + 0x2a8))(WdfDriverGlobals,0x9d7debbc,&local_30);
  local_64 = 0;
  puVar4 = &local_68;
  local_58 = 0;
  local_50 = 1;
  local_4c = 1;
  local_38 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0;
  local_60 = Controller_ContextCleanup;
  local_48 = 0;
  uStack_40 = 0;
  local_68 = 0x38;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_2,puVar4,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0xc,
                        &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,(char)param_2);
    }
  }
  else {
    ppUVar3 = (UCXCONTROLLER__ **)
              (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_2,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
    pUVar1 = (UCXCONTROLLER__ *)param_3[1];
    ppUVar3[2] = (UCXCONTROLLER__ *)*param_3;
    ppUVar3[3] = pUVar1;
    pUVar1 = (UCXCONTROLLER__ *)param_3[3];
    ppUVar3[4] = (UCXCONTROLLER__ *)param_3[2];
    ppUVar3[5] = pUVar1;
    iVar2 = Controller_UcxControllerCreate(param_2,ppUVar3);
  }
  return iVar2;
}



===== _UdecxWdfDeviceNeedsReset @ 140003070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 _UdecxWdfDeviceNeedsReset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  
  if ((int)param_3 == 2) {
    puVar6 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0;
    puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    iVar2 = 0;
    LOCK();
    iVar1 = *(int *)(puVar4 + 0x10);
    if (iVar1 == 0) {
      *(int *)(puVar4 + 0x10) = 1;
    }
    else {
      iVar2 = iVar1;
    }
    UNLOCK();
    if (iVar2 == 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0xe,
                          &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,
                          (char)*(undefined4 *)((longlong)puVar4 + 0x84));
      }
      uVar3 = 0x80000011;
    }
    else {
      if ((puVar4[10] == 0) || (uVar5 = 2, (*(uint *)(puVar4 + 0xb) & 2) == 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,puVar6,0xf,
                            &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,2);
        }
        uVar5 = 0;
      }
      *(undefined4 *)((longlong)puVar4 + 0x84) = uVar5;
      (*DAT_14000e750)(UcxDriverGlobals,*puVar4);
      uVar3 = 0;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0xd,
                        &WPP_39153baa651c378f3fb5ee90b0af063a_Traceguids,(char)param_3);
    }
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== _UdecxWdfDeviceResetComplete @ 1400031c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _UdecxWdfDeviceResetComplete(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  uStack_24 = 1;
  local_20 = 1;
  local_28 = 0xc;
  (*DAT_14000e758)(UcxDriverGlobals,*puVar1,&local_28);
  return;
}



===== _UdecxWdfDeviceTryHandleUserIoctl @ 140003250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _UdecxWdfDeviceTryHandleUserIoctl(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_18 = 0;
  uStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_3,&local_38);
  local_50 = (undefined4)uStack_20;
  local_58 = local_28;
  (*UcxFunctions)(UcxDriverGlobals,param_2,param_3,uStack_30);
  return;
}



===== EvtRootHubClearHubFeature @ 140003310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubClearHubFeature(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl EvtRootHubClearHubFeature(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
  *(undefined4 *)(lStack_30 + 4) = 0;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
  return;
}



===== EvtRootHubClearPortFeature @ 1400033b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubClearPortFeature(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl EvtRootHubClearPortFeature(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  int iVar1;
  short sVar2;
  longlong lVar3;
  _PORT_CONTEXT *p_Var4;
  longlong lVar5;
  long lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined4 uVar9;
  WDFREQUEST__ *pWVar10;
  char cVar11;
  longlong lVar12;
  undefined1 auStack_b8 [32];
  char local_98;
  WDFREQUEST__ *local_90;
  _PORT_CONTEXT *local_88;
  longlong local_80;
  UCXROOTHUB__ *local_78;
  undefined8 local_70;
  longlong lStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  local_88 = (_PORT_CONTEXT *)0x0;
  local_90 = param_2;
  local_78 = param_1;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  local_50 = 0;
  puVar8 = (undefined8 *)0x0;
  lStack_68 = 0;
  cVar11 = '\0';
  local_60 = 0;
  uStack_58 = 0;
  local_98 = '\0';
  local_70 = 0x28;
  lVar12 = 0;
  local_80 = lVar7;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_70);
  lVar5 = lStack_68;
  sVar2 = *(short *)(lStack_68 + 0x82);
  lVar6 = RootHub_PortContextFromPortNumber(param_1,(uint)*(byte *)(lStack_68 + 0x84),&local_88);
  p_Var4 = local_88;
  if (lVar6 < 0) {
    uVar9 = 0x80000300;
    pWVar10 = local_90;
    goto LAB_140003547;
  }
  lVar3 = *(longlong *)(local_88 + 8);
  if (lVar3 != 0) {
    puVar8 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,lVar3,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
    lVar12 = puVar8[3] + 0x18;
  }
  RootHub_LockAcquire(*(WDFSPINLOCK__ **)(lVar7 + 0x10));
  pWVar10 = local_90;
  if (sVar2 == 1) {
    *(undefined4 *)p_Var4 = 3;
LAB_140003524:
    cVar11 = local_98;
  }
  else {
    if (sVar2 != 2) {
      if (sVar2 == 0x10) {
        p_Var4[4] = (_PORT_CONTEXT)0x0;
      }
      else if (sVar2 == 0x12) {
        p_Var4[6] = (_PORT_CONTEXT)0x0;
        if ((puVar8 == (undefined8 *)0x0) ||
           (*(undefined4 *)((longlong)puVar8 + 0x2c) = 0, *(longlong *)(lVar12 + 8) == 0)) {
          cVar11 = '\0';
          goto LAB_140003529;
        }
        puVar8[7] = local_90;
        lVar6 = (**(code **)(lVar12 + 8))(*puVar8,lVar3);
        if (lVar6 != 0x103) {
          puVar8[7] = 0;
        }
      }
      else if (sVar2 == 0x14) {
        p_Var4[5] = (_PORT_CONTEXT)0x0;
      }
      else if (sVar2 == 0x19) {
        p_Var4[6] = (_PORT_CONTEXT)0x0;
      }
      goto LAB_140003524;
    }
    if (puVar8 == (undefined8 *)0x0) goto LAB_140003524;
    LOCK();
    iVar1 = *(int *)(puVar8 + 6);
    *(int *)(puVar8 + 6) = 0;
    UNLOCK();
    if ((*(int *)((longlong)puVar8 + 0x2c) != 0) && (iVar1 == 0)) goto LAB_140003524;
    cVar11 = '\x01';
    *(undefined4 *)local_88 = 4;
    local_88[6] = (_PORT_CONTEXT)0x1;
  }
LAB_140003529:
  RootHub_LockRelease(*(WDFSPINLOCK__ **)(local_80 + 0x10));
  if (lVar6 == 0x103) {
    return;
  }
  uVar9 = 0;
  param_1 = local_78;
LAB_140003547:
  *(undefined4 *)(lVar5 + 4) = uVar9;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,pWVar10,lVar6);
  if (cVar11 != '\0') {
    (*DAT_14000e770)(UcxDriverGlobals,param_1);
  }
  return;
}



===== EvtRootHubGet20PortInfo @ 140003650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubGet20PortInfo(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl EvtRootHubGet20PortInfo(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  uint *puVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  undefined4 uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  uint *puStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_88;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  local_48 = 0;
  puStack_60 = (uint *)0x0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
  puVar2 = puStack_60;
  lVar1 = *(longlong *)(puStack_60 + 2);
  if ((*puStack_60 < 0x10) || ((uint)(ushort)puStack_60[1] != *(uint *)(lVar3 + 8))) {
    uVar6 = 0xc000000d;
  }
  else {
    uVar6 = 0;
    uVar7 = 0;
    if ((ushort)puStack_60[1] != 0) {
      do {
        (**(code **)(WdfFunctions_01015 + 0x650))
                  (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
        uVar8 = (ulonglong)uVar7;
        lVar5 = 0;
        **(short **)(lVar1 + uVar8 * 8) = (short)uVar7 + 1;
        *(undefined4 *)(*(longlong *)(lVar1 + uVar8 * 8) + 4) = *(undefined4 *)(lVar3 + 0x38);
        *(undefined4 *)(*(longlong *)(lVar1 + uVar8 * 8) + 8) = 0x66;
        *(undefined4 *)(*(longlong *)(lVar1 + uVar8 * 8) + 0xc) = 0x66;
        iVar4 = 0;
        do {
          *(char *)(lVar5 + 2 + *(longlong *)(lVar1 + uVar8 * 8)) = (char)iVar4;
          iVar4 = iVar4 + 1;
          lVar5 = lVar5 + 1;
        } while (iVar4 < 2);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (ushort)puVar2[1]);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar6);
  return;
}



===== EvtRootHubGet30PortInfo @ 1400037d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubGet30PortInfo(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl EvtRootHubGet30PortInfo(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  uint *puVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  undefined4 uVar6;
  ulong uVar7;
  ulonglong uVar8;
  undefined1 auStack_88 [32];
  ulong local_68 [2];
  undefined8 local_60;
  uint *puStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  uVar6 = 0;
  local_68[0] = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  local_40 = 0;
  puStack_58 = (uint *)0x0;
  local_60 = 0x28;
  local_50 = 0;
  uStack_48 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_60);
  puVar2 = puStack_58;
  lVar1 = *(longlong *)(puStack_58 + 2);
  if ((*puStack_58 < 0x10) || ((uint)(ushort)puStack_58[1] != *(uint *)(lVar3 + 0xc))) {
    uVar6 = 0xc000000d;
  }
  else {
    uVar7 = 0;
    if ((ushort)puStack_58[1] != 0) {
      do {
        RootHub_PortNumberFromUsb30PortIndex(param_1,uVar7,local_68);
        lVar5 = 0;
        uVar8 = (ulonglong)uVar7;
        **(undefined2 **)(lVar1 + uVar8 * 8) = (undefined2)local_68[0];
        *(undefined4 *)(*(longlong *)(lVar1 + uVar8 * 8) + 4) = *(undefined4 *)(lVar3 + 0x3c);
        iVar4 = 0;
        do {
          *(char *)(*(longlong *)(lVar1 + uVar8 * 8) + 2 + lVar5) = (char)iVar4;
          iVar4 = iVar4 + 1;
          lVar5 = lVar5 + 1;
        } while (iVar4 < 2);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (ushort)puVar2[1]);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar6);
  return;
}



===== EvtRootHubGetHubStatus @ 140003920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubGetHubStatus(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl EvtRootHubGetHubStatus(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals);
  if ((((*(char *)(lStack_30 + 0x80) == -0x60) && (uVar2 = 0, *(char *)(lStack_30 + 0x81) == '\0'))
      && (*(short *)(lStack_30 + 0x82) == 0)) &&
     ((*(short *)(lStack_30 + 0x84) == 0 && (*(short *)(lStack_30 + 0x86) == 4)))) {
    **(undefined4 **)(lStack_30 + 0x28) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc0000004;
    uVar2 = 0xc0000001;
  }
  *(undefined4 *)(lStack_30 + 4) = uVar1;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
  return;
}



===== EvtRootHubGetInfo @ 140003a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubGetInfo(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl EvtRootHubGetInfo(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  uint *puStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  local_18 = 0;
  puStack_30 = (uint *)0x0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2);
  if (*puStack_30 < 0x10) {
    uVar2 = 0xc000000d;
  }
  else {
    uVar2 = 0;
    puStack_30[1] = 0;
    *(undefined2 *)(puStack_30 + 2) = *(undefined2 *)(lVar1 + 8);
    *(undefined2 *)((longlong)puStack_30 + 10) = *(undefined2 *)(lVar1 + 0xc);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
  return;
}



===== EvtRootHubGetPortErrorCount @ 140003af0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubGetPortErrorCount(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl EvtRootHubGetPortErrorCount(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  ushort uVar1;
  longlong lVar2;
  ulong uVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  local_38 = 0;
  lStack_50 = 0;
  local_58 = 0x28;
  local_48 = 0;
  uStack_40 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
  lVar2 = lStack_50;
  if ((((*(char *)(lStack_50 + 0x80) == -0x5d) && (*(char *)(lStack_50 + 0x81) == '\r')) &&
      (uVar6 = 0, *(short *)(lStack_50 + 0x82) == 0)) &&
     (uVar1 = *(ushort *)(lStack_50 + 0x84), uVar1 != 0)) {
    uVar3 = RootHub_GetNumberOfPorts(param_1);
    if (((uVar1 <= uVar3) && (*(short *)(lVar2 + 0x86) == 2)) &&
       ((uint)uVar1 <= *(uint *)(lVar5 + 0xc))) {
      **(undefined2 **)(lVar2 + 0x28) = 0;
      uVar4 = 0;
      goto LAB_140003bd8;
    }
  }
  uVar6 = 0xc0000001;
  uVar4 = 0xc0000004;
LAB_140003bd8:
  *(undefined4 *)(lVar2 + 4) = uVar4;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar6);
  return;
}



===== EvtRootHubGetPortStatus @ 140003c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubGetPortStatus(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl EvtRootHubGetPortStatus(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  ushort *puVar1;
  longlong lVar2;
  uchar uVar3;
  ushort uVar4;
  ulong uVar5;
  long lVar6;
  longlong lVar7;
  ushort uVar8;
  uint uVar9;
  short sVar10;
  undefined8 *puVar11;
  _PORT_CONTEXT **pp_Var12;
  undefined1 auStackY_a8 [32];
  _PORT_CONTEXT *local_78;
  undefined8 local_70;
  longlong lStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_78 = (_PORT_CONTEXT *)0x0;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  puVar11 = &local_70;
  local_50 = 0;
  lStack_68 = 0;
  local_70 = 0x28;
  local_60 = 0;
  uStack_58 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2);
  lVar2 = lStack_68;
  puVar1 = *(ushort **)(lStack_68 + 0x28);
  uVar4 = *(ushort *)(lStack_68 + 0x84);
  sVar10 = 8;
  if (*(short *)(lStack_68 + 0x82) != 2) {
    sVar10 = 4;
  }
  puVar1[0] = 0;
  puVar1[1] = 0;
  if ((((*(char *)(lStack_68 + 0x80) == -0x5d) && (*(char *)(lStack_68 + 0x81) == '\0')) &&
      ((*(ushort *)(lStack_68 + 0x82) & 0xfffd) == 0)) && (uVar4 != 0)) {
    uVar5 = RootHub_GetNumberOfPorts(param_1);
    uVar9 = (uint)uVar4;
    if ((uVar9 <= uVar5) && (*(short *)(lVar2 + 0x86) == sVar10)) {
      pp_Var12 = &local_78;
      lVar6 = RootHub_PortContextFromPortNumber(param_1,uVar9,pp_Var12);
      if (lVar6 < 0) goto LAB_140003f35;
      RootHub_LockAcquire(*(WDFSPINLOCK__ **)(lVar7 + 0x10));
      uVar3 = RootHub_IsUsb30Port(param_1,uVar9);
      if (uVar3 == '\0') {
        if (*(short *)(lVar2 + 0x82) != 0) {
          *(undefined4 *)(lVar2 + 4) = 0xc0000004;
          lVar6 = -0x3fffffff;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var12,0x11,
                              &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,1);
          }
          RootHub_LockRelease(*(WDFSPINLOCK__ **)(lVar7 + 0x10));
          goto LAB_140003f35;
        }
        uVar4 = *puVar1;
        *puVar1 = uVar4 | 0x100;
        if (*(int *)local_78 != 1) {
          *puVar1 = uVar4 | 0x501;
          if (*(int *)local_78 == 2) {
            uVar4 = uVar4 | 0x507;
          }
          else {
            if (*(int *)local_78 == 3) goto LAB_140003e59;
            uVar4 = uVar4 | 0x503;
          }
          *puVar1 = uVar4;
        }
LAB_140003e59:
        if (local_78[6] != (_PORT_CONTEXT)0x0) {
          puVar1[1] = puVar1[1] | 4;
        }
      }
      else {
        uVar4 = *puVar1;
        *puVar1 = uVar4 | 0x200;
        if (*(int *)local_78 == 1) {
          uVar4 = uVar4 & 0xfebf | 0x200;
          uVar8 = 0xa0;
LAB_140003dd4:
          uVar4 = uVar4 | uVar8;
        }
        else {
          *puVar1 = uVar4 | 0x203;
          if (*(int *)local_78 == 2) {
            uVar4 = uVar4 & 0xfe7f | 0x263;
          }
          else {
            if (*(int *)local_78 == 3) {
              uVar4 = uVar4 & 0xfe9f | 0x203;
              uVar8 = 0x80;
              goto LAB_140003dd4;
            }
            uVar4 = uVar4 & 0xfe1f | 0x203;
          }
        }
        *puVar1 = uVar4;
        if (local_78[6] != (_PORT_CONTEXT)0x0) {
          puVar1[1] = puVar1[1] | 0x40;
        }
        if (*(short *)(lVar2 + 0x82) == 2) {
          puVar1[2] = 0x44;
          puVar1[3] = 0;
        }
      }
      if (local_78[4] != (_PORT_CONTEXT)0x0) {
        puVar1[1] = puVar1[1] | 1;
      }
      if (local_78[5] != (_PORT_CONTEXT)0x0) {
        puVar1[1] = puVar1[1] | 0x10;
      }
      RootHub_LockRelease(*(WDFSPINLOCK__ **)(lVar7 + 0x10));
      *(undefined4 *)(lVar2 + 4) = 0;
      lVar6 = 0;
      goto LAB_140003f35;
    }
  }
  *(undefined4 *)(lVar2 + 4) = 0xc0000004;
  lVar6 = -0x3fffffff;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,0x10,
                      &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,1);
  }
LAB_140003f35:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar6);
  return;
}



===== EvtRootHubInterruptTx @ 140003f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubInterruptTx(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl EvtRootHubInterruptTx(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  uint uVar1;
  void *_Dst;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  ulong uVar5;
  undefined1 auStack_88 [32];
  _PORT_CONTEXT *local_68;
  undefined8 local_60;
  longlong lStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = (_PORT_CONTEXT *)0x0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  local_40 = 0;
  lStack_58 = 0;
  local_60 = 0x28;
  local_50 = 0;
  uStack_48 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_60);
  lVar2 = lStack_58;
  _Dst = *(void **)(lStack_58 + 0x28);
  uVar1 = *(uint *)(lStack_58 + 0x24);
  memset(_Dst,0,(ulonglong)uVar1);
  RootHub_LockAcquire(*(WDFSPINLOCK__ **)(lVar4 + 0x10));
  if (uVar1 != 0) {
    uVar3 = RootHub_GetNumberOfPorts(param_1);
    if (0xff < uVar3) {
      uVar3 = 0xff;
    }
    if ((uVar1 < 0x20) && (uVar1 = uVar1 * 8 - 1, uVar1 < uVar3)) {
      uVar3 = uVar1;
    }
    uVar5 = 1;
    if (uVar3 != 0) {
      do {
        RootHub_PortContextFromPortNumber(param_1,uVar5,&local_68);
        if (((local_68[4] != (_PORT_CONTEXT)0x0) || (local_68[6] != (_PORT_CONTEXT)0x0)) ||
           (local_68[5] != (_PORT_CONTEXT)0x0)) {
          *(byte *)((ulonglong)(uVar5 >> 3) + (longlong)_Dst) =
               *(byte *)((ulonglong)(uVar5 >> 3) + (longlong)_Dst) | (byte)(1 << (uVar5 & 7));
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 <= uVar3);
    }
  }
  RootHub_LockRelease(*(WDFSPINLOCK__ **)(lVar4 + 0x10));
  *(undefined4 *)(lVar2 + 4) = 0;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
  return;
}



===== EvtRootHubSetHubFeature @ 140004120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubSetHubFeature(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl EvtRootHubSetHubFeature(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
  *(undefined4 *)(lStack_30 + 4) = 0xc0000004;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000001);
  return;
}



===== EvtRootHubSetPortFeature @ 1400041c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtRootHubSetPortFeature(struct UCXROOTHUB__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl EvtRootHubSetPortFeature(UCXROOTHUB__ *param_1,WDFREQUEST__ *param_2)

{
  short sVar1;
  longlong lVar2;
  _PORT_CONTEXT *p_Var3;
  longlong lVar4;
  long lVar5;
  undefined4 uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  longlong lVar9;
  char cVar10;
  undefined1 auStack_b8 [32];
  char local_98;
  WDFREQUEST__ *local_90;
  _PORT_CONTEXT *local_88;
  longlong local_80;
  UCXROOTHUB__ *local_78;
  undefined8 local_70;
  longlong lStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  local_88 = (_PORT_CONTEXT *)0x0;
  local_90 = param_2;
  local_78 = param_1;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  local_50 = 0;
  puVar8 = (undefined8 *)0x0;
  lStack_68 = 0;
  cVar10 = '\0';
  local_60 = 0;
  uStack_58 = 0;
  local_98 = '\0';
  local_70 = 0x28;
  lVar9 = 0;
  local_80 = lVar7;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_70);
  lVar4 = lStack_68;
  sVar1 = *(short *)(lStack_68 + 0x82);
  lVar5 = RootHub_PortContextFromPortNumber(param_1,(uint)*(byte *)(lStack_68 + 0x84),&local_88);
  p_Var3 = local_88;
  if (lVar5 < 0) {
    uVar6 = 0x80000300;
    goto LAB_140004431;
  }
  lVar2 = *(longlong *)(local_88 + 8);
  if (lVar2 != 0) {
    puVar8 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,lVar2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
    lVar9 = puVar8[3] + 0x18;
  }
  RootHub_LockAcquire(*(WDFSPINLOCK__ **)(lVar7 + 0x10));
  if (sVar1 == 2) {
    if ((puVar8 != (undefined8 *)0x0) && (*(longlong *)(lVar9 + 0x10) != 0)) {
      puVar8[8] = local_90;
      lVar5 = (**(code **)(lVar9 + 0x10))(*puVar8,lVar2,*(int *)((longlong)puVar8 + 0x2c) != 0);
      if (lVar5 != 0x103) {
        puVar8[7] = 0;
      }
    }
LAB_140004408:
    *(int *)p_Var3 = 2;
LAB_14000440e:
    cVar10 = local_98;
  }
  else {
    if (sVar1 != 4) {
      if (sVar1 == 5) {
        cVar10 = *(char *)(lVar4 + 0x85);
        if (cVar10 == '\x03') {
          if ((puVar8 != (undefined8 *)0x0) && (*(longlong *)(lVar9 + 0x10) != 0)) {
            puVar8[8] = local_90;
            lVar5 = (**(code **)(lVar9 + 0x10))(*puVar8,lVar2,2);
            if (lVar5 != 0x103) {
              puVar8[8] = 0;
            }
          }
          goto LAB_140004408;
        }
        if (cVar10 != '\0') goto LAB_14000440e;
        if ((puVar8 != (undefined8 *)0x0) && (*(longlong *)(lVar9 + 8) != 0)) {
          puVar8[7] = local_90;
          lVar5 = (**(code **)(lVar9 + 8))(*puVar8,lVar2);
          if (lVar5 != 0x103) {
            puVar8[7] = 0;
          }
        }
        *(int *)p_Var3 = 4;
        cVar10 = '\x01';
        p_Var3[6] = (_PORT_CONTEXT)0x1;
        goto LAB_140004413;
      }
      if (sVar1 != 0x1c) goto LAB_14000440e;
    }
    p_Var3[5] = (_PORT_CONTEXT)0x1;
    cVar10 = '\x01';
    if (*(int *)p_Var3 - 2U < 2) {
      *(int *)p_Var3 = 4;
    }
  }
LAB_140004413:
  RootHub_LockRelease(*(WDFSPINLOCK__ **)(local_80 + 0x10));
  if (lVar5 == 0x103) {
    return;
  }
  uVar6 = 0;
  param_2 = local_90;
LAB_140004431:
  *(undefined4 *)(lVar4 + 4) = uVar6;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar5);
  if (cVar10 != '\0') {
    (*DAT_14000e770)(UcxDriverGlobals,local_78);
  }
  return;
}



===== RootHub_ConnectDeviceToPort @ 1400044a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RootHub_ConnectDeviceToPort(struct UCXROOTHUB__ * __ptr64,struct UDECXUSBDEVICE__ *
   __ptr64,unsigned long) */

long __cdecl
RootHub_ConnectDeviceToPort(UCXROOTHUB__ *param_1,UDECXUSBDEVICE__ *param_2,ulong param_3)

{
  bool bVar1;
  long lVar2;
  longlong lVar3;
  ulonglong uVar4;
  _PORT_CONTEXT **pp_Var5;
  _PORT_CONTEXT *local_res20;
  
  local_res20 = (_PORT_CONTEXT *)0x0;
  bVar1 = false;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  RootHub_LockAcquire(*(WDFSPINLOCK__ **)(lVar3 + 0x10));
  pp_Var5 = &local_res20;
  uVar4 = (ulonglong)param_3;
  lVar2 = RootHub_PortContextFromPortNumber(param_1,param_3,pp_Var5);
  if (-1 < lVar2) {
    if (*(int *)local_res20 == 1) {
      *(UDECXUSBDEVICE__ **)(local_res20 + 8) = param_2;
      bVar1 = true;
      *(int *)local_res20 = 4;
      local_res20[4] = (_PORT_CONTEXT)0x1;
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,pp_Var5,0x17,
                         &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,(char)param_3,(char)lVar2)
      ;
    }
  }
  RootHub_LockRelease(*(WDFSPINLOCK__ **)(lVar3 + 0x10));
  if (bVar1) {
    (*DAT_14000e770)(UcxDriverGlobals,param_1);
  }
  return lVar2;
}



===== RootHub_FindPortAndConnectDevice @ 1400045b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RootHub_FindPortAndConnectDevice(struct UCXROOTHUB__ * __ptr64,struct
   UDECXUSBDEVICE__ * __ptr64,enum _USB_DEVICE_SPEED,unsigned long * __ptr64) */

long __cdecl
RootHub_FindPortAndConnectDevice
          (UCXROOTHUB__ *param_1,UDECXUSBDEVICE__ *param_2,_USB_DEVICE_SPEED param_3,ulong *param_4)

{
  bool bVar1;
  longlong lVar2;
  UCXROOTHUB__ *pUVar3;
  uint uVar4;
  int *piVar5;
  undefined *puVar6;
  long lVar7;
  
  bVar1 = false;
  puVar6 = PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  lVar7 = 0;
  if (param_4 != (ulong *)0x0) {
    *param_4 = 0;
  }
  RootHub_LockAcquire(*(WDFSPINLOCK__ **)(lVar2 + 0x10));
  uVar4 = 0;
  if (*(uint *)(lVar2 + 8) != 0) {
    do {
      piVar5 = (int *)((ulonglong)uVar4 * 0x10 + *(longlong *)(lVar2 + 0x18));
      uVar4 = uVar4 + 1;
      if (*piVar5 == 1) {
        pUVar3 = param_1;
        puVar6 = PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0;
        (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
        if (piVar5 != (int *)0x0) {
          if (*piVar5 == 1) {
            *(UDECXUSBDEVICE__ **)(piVar5 + 2) = param_2;
            bVar1 = true;
            *piVar5 = 4;
            *(undefined1 *)(piVar5 + 1) = 1;
            if (param_4 != (ulong *)0x0) {
              *param_4 = uVar4;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar6,0x16,
                                 &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,(char)param_2,
                                 (char)uVar4);
            }
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pUVar3,puVar6,0x15,
                               &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,(char)uVar4,0);
          }
          goto LAB_14000467b;
        }
        break;
      }
    } while (uVar4 < *(uint *)(lVar2 + 8));
  }
  lVar7 = -0x3ffffff2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x14,
                      &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,0xe);
  }
LAB_14000467b:
  RootHub_LockRelease(*(WDFSPINLOCK__ **)(lVar2 + 0x10));
  if (bVar1) {
    (*DAT_14000e770)(UcxDriverGlobals,param_1);
  }
  return lVar7;
}



===== RootHub_GetNumberOfPorts @ 14000479c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned long __cdecl RootHub_GetNumberOfPorts(struct UCXROOTHUB__ * __ptr64) */

ulong __cdecl RootHub_GetNumberOfPorts(UCXROOTHUB__ *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  return *(int *)(lVar1 + 0xc) + *(int *)(lVar1 + 8);
}



===== RootHub_IsUsb30Port @ 1400047d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl RootHub_IsUsb30Port(struct UCXROOTHUB__ * __ptr64,unsigned long) */

uchar __cdecl RootHub_IsUsb30Port(UCXROOTHUB__ *param_1,ulong param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  return *(uint *)(lVar1 + 8) < param_2;
}



===== RootHub_LockAcquire @ 140004818 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RootHub_LockAcquire(struct WDFSPINLOCK__ * __ptr64) */

void __cdecl RootHub_LockAcquire(WDFSPINLOCK__ *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,param_1);
  return;
}



===== RootHub_LockRelease @ 140004848 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RootHub_LockRelease(struct WDFSPINLOCK__ * __ptr64) */

void __cdecl RootHub_LockRelease(WDFSPINLOCK__ *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,param_1);
  return;
}



===== RootHub_PortContextFromPortNumber @ 140004878 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RootHub_PortContextFromPortNumber(struct UCXROOTHUB__ * __ptr64,unsigned long,struct
   _PORT_CONTEXT * __ptr64 * __ptr64) */

long __cdecl
RootHub_PortContextFromPortNumber(UCXROOTHUB__ *param_1,ulong param_2,_PORT_CONTEXT **param_3)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  uchar uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined *puVar7;
  undefined2 uVar8;
  
  uVar3 = WdfDriverGlobals;
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x650);
  *param_3 = (_PORT_CONTEXT *)0x0;
  lVar5 = (*pcVar2)(uVar3,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  uVar4 = RootHub_IsUsb30Port(param_1,param_2);
  puVar7 = PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0;
  if (uVar4 == '\0') {
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    if ((param_2 != 0) && (param_2 <= *(uint *)(lVar6 + 8))) {
      *param_3 = (_PORT_CONTEXT *)((ulonglong)(param_2 - 1) * 0x10 + *(longlong *)(lVar5 + 0x18));
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar8 = 0xb;
  }
  else {
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    uVar1 = *(uint *)(lVar6 + 8);
    param_1 = (UCXROOTHUB__ *)(ulonglong)uVar1;
    if ((uVar1 + 1 <= param_2) && (param_2 <= *(int *)(lVar6 + 0xc) + uVar1)) {
      *param_3 = (_PORT_CONTEXT *)
                 ((ulonglong)((param_2 - uVar1) - 1) * 0x10 + *(longlong *)(lVar5 + 0x28));
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar8 = 10;
  }
  WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,puVar7,uVar8,
                     &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,(char)param_2,0xd);
  return -0x3ffffff3;
}



===== RootHub_PortNumberFromUsb30PortIndex @ 1400049c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RootHub_PortNumberFromUsb30PortIndex(struct UCXROOTHUB__ * __ptr64,unsigned
   long,unsigned long * __ptr64) */

long __cdecl
RootHub_PortNumberFromUsb30PortIndex(UCXROOTHUB__ *param_1,ulong param_2,ulong *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  uVar4 = *(int *)(lVar2 + 8) + 1;
  uVar1 = uVar4 + param_2;
  uVar3 = 0xffffffff;
  if (uVar1 >= uVar4) {
    uVar3 = uVar1;
  }
  *param_3 = uVar3;
  return -(uint)(uVar1 < uVar4) & 0xc0000095;
}



===== RootHub_QueryIsUsbPortsRemovable @ 140004a28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RootHub_QueryIsUsbPortsRemovable(struct WDFDEVICE__ * __ptr64,enum _TRISTATE *
   __ptr64,enum _TRISTATE * __ptr64) */

void __cdecl
RootHub_QueryIsUsbPortsRemovable(WDFDEVICE__ *param_1,_TRISTATE *param_2,_TRISTATE *param_3)

{
  int iVar1;
  undefined8 uVar2;
  int local_res10 [2];
  longlong local_res18;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18 = 0;
  local_res10[0] = 0;
  *param_2 = 0x74;
  *param_3 = 0x74;
  uVar2 = 1;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x180))
                    (WdfDriverGlobals,param_1,1,0x20019,0,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,uVar2,0x1a,
                        &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,(char)iVar1);
    }
  }
  else {
    RtlInitUnicodeString(&local_18,L"IsUsb20PortRemovable");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res18,&local_18,local_res10);
    if ((-1 < iVar1) && (local_res10[0] == 0)) {
      *param_2 = 0x66;
    }
    RtlInitUnicodeString(&local_18,L"IsUsb30PortRemovable");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res18,&local_18,local_res10);
    if ((-1 < iVar1) && (local_res10[0] == 0)) {
      *param_3 = 0x66;
    }
  }
  if (local_res18 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return;
}



===== RootHub_UcxRootHubCreate @ 140004bac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RootHub_UcxRootHubCreate(struct UCXCONTROLLER__ * __ptr64,struct UCXROOTHUB__ *
   __ptr64 * __ptr64) */

long __cdecl RootHub_UcxRootHubCreate(UCXCONTROLLER__ *param_1,UCXROOTHUB__ **param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulonglong uVar8;
  _POOL_TYPE _Var9;
  undefined4 *puVar10;
  undefined2 uVar11;
  UCXROOTHUB__ *local_res10;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  UCXROOTHUB__ *local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined *local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  UCXROOTHUB__ *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined4 local_c8;
  undefined4 local_c4;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_res10 = (UCXROOTHUB__ *)0x0;
  local_d8 = 0;
  local_148 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = (UCXROOTHUB__ *)0x0;
  uStack_e0 = 0;
  local_178 = 0;
  uStack_170 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_158 = (UCXROOTHUB__ *)0x0;
  uStack_150 = 0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCX_CONTROLLER_CONTEXT_TYPE_INFO_14000e250);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  *param_2 = (UCXROOTHUB__ *)0x0;
  memset(&local_c8,0,0xa0);
  local_c8 = 0xa0;
  local_c0 = EvtRootHubClearHubFeature;
  local_c4 = 1;
  local_b8 = EvtRootHubClearPortFeature;
  local_b0 = EvtRootHubGetHubStatus;
  local_a8 = EvtRootHubGetPortStatus;
  local_a0 = EvtRootHubSetHubFeature;
  local_98 = EvtRootHubSetPortFeature;
  local_90 = EvtRootHubGetPortErrorCount;
  local_80 = EvtRootHubInterruptTx;
  local_78 = EvtRootHubGetInfo;
  local_70 = EvtRootHubGet20PortInfo;
  local_68 = EvtRootHubGet30PortInfo;
  local_30 = 0;
  local_50 = 0;
  local_110 = PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0;
  local_130 = 0;
  uStack_58 = 0;
  local_60 = 0x38;
  uStack_138 = 0;
  local_140 = 0x38;
  local_40 = 0;
  uStack_38 = 0;
  uStack_48 = 0x100000001;
  local_120 = 0;
  uStack_118 = 0;
  uStack_128 = 0x100000001;
  puVar10 = &local_c8;
  iVar1 = (*DAT_14000e768)(UcxDriverGlobals,param_1,puVar10,&local_140,&local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004f33;
    uVar11 = 0xc;
  }
  else {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_res10,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
    *(uint *)(lVar4 + 8) = (uint)*(ushort *)(lVar3 + 0x14);
    *(uint *)(lVar4 + 0xc) = (uint)*(ushort *)(lVar3 + 0x16);
    RootHub_QueryIsUsbPortsRemovable
              ((WDFDEVICE__ *)*puVar2,(_TRISTATE *)(lVar4 + 0x38),(_TRISTATE *)(lVar4 + 0x3c));
    puVar10 = (undefined4 *)(lVar4 + 0x10);
    _Var9 = (_POOL_TYPE)&local_108;
    local_e8 = local_res10;
    local_108 = CONCAT44(local_108._4_4_,0x38);
    uStack_f0 = 0x100000001;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004f33;
      uVar11 = 0xd;
    }
    else {
      local_158 = local_res10;
      local_178 = CONCAT44(local_178._4_4_,0x38);
      uStack_160 = 0x100000001;
      puVar10 = (undefined4 *)((ulonglong)*(uint *)(lVar4 + 8) << 4);
      iVar1 = Misc_WdfMemoryCreateAndZero
                        ((_WDF_OBJECT_ATTRIBUTES *)&local_178,_Var9,(__uint64)puVar10,
                         (WDFMEMORY__ **)(lVar4 + 0x20));
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004f33;
        uVar11 = 0xe;
      }
      else {
        uVar6 = *(undefined8 *)(lVar4 + 0x20);
        uVar5 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,uVar6,0);
        *(undefined8 *)(lVar4 + 0x18) = uVar5;
        local_168 = 0;
        local_148 = 0;
        uStack_170 = 0;
        local_178 = 0x38;
        uStack_150 = 0;
        local_158 = local_res10;
        uStack_160 = 0x100000001;
        puVar10 = (undefined4 *)((ulonglong)*(uint *)(lVar4 + 0xc) << 4);
        iVar1 = Misc_WdfMemoryCreateAndZero
                          ((_WDF_OBJECT_ATTRIBUTES *)&local_178,(_POOL_TYPE)uVar6,(__uint64)puVar10,
                           (WDFMEMORY__ **)(lVar4 + 0x30));
        if (-1 < iVar1) {
          uVar6 = (**(code **)(WdfFunctions_01015 + 0x610))
                            (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x30),0);
          *(undefined8 *)(lVar4 + 0x28) = uVar6;
          if (*(int *)(lVar4 + 8) != 0) {
            iVar1 = 0;
            uVar8 = 0;
            do {
              uVar7 = (int)uVar8 + 1;
              puVar10 = (undefined4 *)(uVar8 * 0x10 + *(longlong *)(lVar4 + 0x18));
              *(undefined8 *)(puVar10 + 2) = 0;
              *puVar10 = 1;
              uVar8 = (ulonglong)uVar7;
            } while (uVar7 < *(uint *)(lVar4 + 8));
          }
          if (*(int *)(lVar4 + 0xc) != 0) {
            iVar1 = 0;
            uVar8 = 0;
            do {
              uVar7 = (int)uVar8 + 1;
              puVar10 = (undefined4 *)(uVar8 * 0x10 + *(longlong *)(lVar4 + 0x28));
              *(undefined8 *)(puVar10 + 2) = 0;
              *puVar10 = 1;
              uVar8 = (ulonglong)uVar7;
            } while (uVar7 < *(uint *)(lVar4 + 0xc));
          }
          *param_2 = local_res10;
          return iVar1;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004f33;
        uVar11 = 0xf;
      }
    }
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar10,uVar11,
                    &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,(char)iVar1);
LAB_140004f33:
  if (local_res10 != (UCXROOTHUB__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== WPP_RECORDER_SF_dLd @ 140004ff8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dLd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,4
               ,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,1,param_5,param_4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 1400050e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,2,1,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== Misc_WdfMemoryCreateAndZero @ 1400051bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Misc_WdfMemoryCreateAndZero(struct _WDF_OBJECT_ATTRIBUTES * __ptr64,enum
   _POOL_TYPE,unsigned __int64,struct WDFMEMORY__ * __ptr64 * __ptr64) */

long __cdecl
Misc_WdfMemoryCreateAndZero
          (_WDF_OBJECT_ATTRIBUTES *param_1,_POOL_TYPE param_2,__uint64 param_3,WDFMEMORY__ **param_4
          )

{
  int iVar1;
  undefined8 uVar2;
  void *local_18 [2];
  
  local_18[0] = (void *)0x0;
  uVar2 = 0x200;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,param_1,0x200,0,param_3,param_4,local_18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,uVar2,0xb,
                          &WPP_4e1bc8614cbf36f74aa9a1f1d115ddd4_Traceguids,(char)param_3,0,
                          (char)iVar1);
    }
  }
  else {
    memset(local_18[0],0,param_3);
  }
  return iVar1;
}



===== EvtUcxUsbDeviceAddress @ 140005280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtUcxUsbDeviceAddress(struct UCXCONTROLLER__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl EvtUcxUsbDeviceAddress(UCXCONTROLLER__ *param_1,WDFREQUEST__ *param_2)

{
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
  return;
}



===== EvtUcxEndpointAbort @ 1400052b0 =====

/* void __cdecl EvtUcxEndpointAbort(struct UCXCONTROLLER__ * __ptr64,struct UCXENDPOINT__ * __ptr64)
    */

void __cdecl EvtUcxEndpointAbort(UCXCONTROLLER__ *param_1,UCXENDPOINT__ *param_2)

{
  Endpoint_StartQueueOperation(param_2,3);
  return;
}



===== EvtUcxEndpointOkToCancelTransfers @ 1400052d0 =====

/* void __cdecl EvtUcxEndpointOkToCancelTransfers(struct UCXENDPOINT__ * __ptr64) */

void __cdecl EvtUcxEndpointOkToCancelTransfers(UCXENDPOINT__ *param_1)

{
  return;
}



===== EvtUcxEndpointPurge @ 1400052e0 =====

/* void __cdecl EvtUcxEndpointPurge(struct UCXCONTROLLER__ * __ptr64,struct UCXENDPOINT__ * __ptr64)
    */

void __cdecl EvtUcxEndpointPurge(UCXCONTROLLER__ *param_1,UCXENDPOINT__ *param_2)

{
  Endpoint_StartQueueOperation(param_2,2);
  return;
}



===== EvtUcxEndpointReset @ 140005300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtUcxEndpointReset(struct UCXCONTROLLER__ * __ptr64,struct UCXENDPOINT__ *
   __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl
EvtUcxEndpointReset(UCXCONTROLLER__ *param_1,UCXENDPOINT__ *param_2,WDFREQUEST__ *param_3)

{
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,0);
  return;
}



===== EvtUcxEndpointStart @ 140005330 =====

/* void __cdecl EvtUcxEndpointStart(struct UCXCONTROLLER__ * __ptr64,struct UCXENDPOINT__ * __ptr64)
    */

void __cdecl EvtUcxEndpointStart(UCXCONTROLLER__ *param_1,UCXENDPOINT__ *param_2)

{
  Endpoint_StartQueueOperation(param_2,1);
  return;
}



===== EvtUcxEndpointStaticStreamsAdd @ 140005350 =====

/* long __cdecl EvtUcxEndpointStaticStreamsAdd(struct UCXENDPOINT__ * __ptr64,unsigned long,struct
   _UCXSSTREAMS_INIT * __ptr64) */

long __cdecl
EvtUcxEndpointStaticStreamsAdd(UCXENDPOINT__ *param_1,ulong param_2,_UCXSSTREAMS_INIT *param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,param_3,0x31,
                     &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids);
  }
  return -0x3fffff45;
}



===== EvtUcxEndpointStaticStreamsDisable @ 1400053a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtUcxEndpointStaticStreamsDisable(struct UCXENDPOINT__ * __ptr64,struct
   UCXSSTREAMS__ * __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl
EvtUcxEndpointStaticStreamsDisable
          (UCXENDPOINT__ *param_1,UCXSSTREAMS__ *param_2,WDFREQUEST__ *param_3)

{
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,0xc00000bb);
  return;
}



===== EvtUcxUsbDeviceDefaultEndpointAdd @ 1400053e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtUcxUsbDeviceDefaultEndpointAdd(struct UCXCONTROLLER__ * __ptr64,struct
   UCXUSBDEVICE__ * __ptr64,unsigned long,struct _UCXENDPOINT_INIT * __ptr64) */

long __cdecl
EvtUcxUsbDeviceDefaultEndpointAdd
          (UCXCONTROLLER__ *param_1,UCXUSBDEVICE__ *param_2,ulong param_3,_UCXENDPOINT_INIT *param_4
          )

{
  UDECXUSBDEVICE__ *pUVar1;
  long lVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0);
  pUVar1 = (UDECXUSBDEVICE__ *)*puVar3;
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,pUVar1);
  lVar2 = UsbDevice_UcxEndpointAdd
                    ((WDFDEVICE__ *)*puVar3,pUVar1,'\0',(_USB_ENDPOINT_DESCRIPTOR *)0x0,
                     (_USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR *)0x0,param_4);
  return lVar2;
}



===== EvtUcxUsbDeviceDisable @ 140005470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtUcxUsbDeviceDisable(struct UCXCONTROLLER__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl EvtUcxUsbDeviceDisable(UCXCONTROLLER__ *param_1,WDFREQUEST__ *param_2)

{
  UCXENDPOINT__ **ppUVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined *puVar7;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCX_CONTROLLER_CONTEXT_TYPE_INFO_14000e250);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  local_28 = 0;
  lStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_48);
  lVar2 = lStack_40;
  ppUVar1 = (UCXENDPOINT__ **)(lStack_40 + 0x18);
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*ppUVar1,PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
  puVar7 = PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar5 + 0x40) + 0x10));
  if (*(int *)(*(longlong *)(lVar6 + 0x18) + 0x14) == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar7,0x26,
                       &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
  }
  else {
    UsbDevice_PrepareEndpointsConfigure
              (param_2,*(UDECXUSBDEVICE__ **)(lVar5 + 8),0,(UCXENDPOINT__ **)0x0,1,ppUVar1);
  }
  if (((*(int *)(lVar2 + 0x20) == 2) && (*(longlong *)(lVar4 + 0x50) != 0)) &&
     ((*(uint *)(lVar4 + 0x58) & 2) != 0)) {
    *(undefined1 *)(lVar4 + 0x88) = 1;
    DispatchDeviceReset(lVar4 + 0x30);
  }
  return;
}



===== EvtUcxUsbDeviceEnable @ 140005670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtUcxUsbDeviceEnable(struct UCXCONTROLLER__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl EvtUcxUsbDeviceEnable(UCXCONTROLLER__ *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 auStackY_68 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  lStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
  lVar1 = lStack_30;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*(undefined8 *)(lStack_30 + 0x18),
                      PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar3 + 0x40) + 0x10),
                     PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  if (*(int *)(*(longlong *)(lVar4 + 0x18) + 0x14) == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x25,
                       &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
  }
  else {
    UsbDevice_PrepareEndpointsConfigure
              (param_2,*(UDECXUSBDEVICE__ **)(lVar3 + 8),1,(UCXENDPOINT__ **)(lVar1 + 0x18),0,
               (UCXENDPOINT__ **)0x0);
  }
  return;
}



===== EvtUcxUsbDeviceEndpointAdd @ 1400057f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtUcxUsbDeviceEndpointAdd(struct UCXCONTROLLER__ * __ptr64,struct UCXUSBDEVICE__ *
   __ptr64,struct _USB_ENDPOINT_DESCRIPTOR * __ptr64,unsigned long,struct
   _USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR * __ptr64,struct _UCXENDPOINT_INIT * __ptr64) */

long __cdecl
EvtUcxUsbDeviceEndpointAdd
          (UCXCONTROLLER__ *param_1,UCXUSBDEVICE__ *param_2,_USB_ENDPOINT_DESCRIPTOR *param_3,
          ulong param_4,_USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR *param_5,
          _UCXENDPOINT_INIT *param_6)

{
  _USB_ENDPOINT_DESCRIPTOR _Var1;
  UDECXUSBDEVICE__ *pUVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined4 in_register_0000008c;
  
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0,
                      CONCAT44(in_register_0000008c,param_4));
  _Var1 = param_3[2];
  pUVar2 = (UDECXUSBDEVICE__ *)*puVar4;
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,pUVar2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  lVar3 = UsbDevice_UcxEndpointAdd
                    ((WDFDEVICE__ *)*puVar4,pUVar2,(uchar)_Var1,param_3,param_5,param_6);
  return lVar3;
}



===== EvtUcxUsbDeviceEndpointsConfigure @ 140005890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtUcxUsbDeviceEndpointsConfigure(struct UCXCONTROLLER__ * __ptr64,struct
   WDFREQUEST__ * __ptr64) */

void __cdecl EvtUcxUsbDeviceEndpointsConfigure(UCXCONTROLLER__ *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined1 auStackY_68 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  lStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
  lVar1 = lStack_30;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*(undefined8 *)(lStack_30 + 0x10),
                      PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0);
  puVar4 = PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  if (*(int *)(*(longlong *)(lVar3 + 0x18) + 0x14) == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x23,
                       &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
  }
  else {
    UsbDevice_PrepareEndpointsConfigure
              (param_2,(UDECXUSBDEVICE__ *)*puVar2,*(ulong *)(lVar1 + 0x18),
               *(UCXENDPOINT__ ***)(lVar1 + 0x20),*(ulong *)(lVar1 + 0x28),
               *(UCXENDPOINT__ ***)(lVar1 + 0x30));
  }
  return;
}



===== EvtUcxUsbDeviceReset @ 1400059f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl EvtUcxUsbDeviceReset(struct UCXCONTROLLER__ * __ptr64,struct WDFREQUEST__ * __ptr64)
    */

void __cdecl EvtUcxUsbDeviceReset(UCXCONTROLLER__ *param_1,WDFREQUEST__ *param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined1 uVar6;
  undefined1 auStack_78 [48];
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCX_CONTROLLER_CONTEXT_TYPE_INFO_14000e250);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  local_28 = 0;
  lStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_48);
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*(undefined8 *)(lStack_40 + 0x10),
                      PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar4,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  uVar6 = 0;
  if (*(int *)(lVar3 + 0x20) == 0) {
    uVar6 = *(undefined1 *)(lVar5 + 0x35);
    *(undefined1 *)(lVar5 + 0x35) = 0;
  }
  pcVar1 = *(code **)(*(longlong *)(lVar5 + 0x18) + 0x38);
  if ((pcVar1 == (code *)0x0) || (*(char *)(lVar5 + 0x20) == '\0')) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
  }
  else {
    (*pcVar1)(*puVar2,*puVar4,param_2,uVar6);
  }
  return;
}



===== UsbDevice_AddUdecxUsbDeviceInitDescriptor @ 140005b6c =====

/* long __cdecl UsbDevice_AddUdecxUsbDeviceInitDescriptor(struct _UDECXUSBDEVICE_INIT *
   __ptr64,unsigned char * __ptr64,unsigned short,unsigned char,unsigned short) */

long __cdecl
UsbDevice_AddUdecxUsbDeviceInitDescriptor
          (_UDECXUSBDEVICE_INIT *param_1,uchar *param_2,ushort param_3,uchar param_4,ushort param_5)

{
  void *_Dst;
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  _UDECXUSBDEVICE_INIT *p_Var4;
  undefined8 uVar5;
  ulonglong uVar6;
  long lVar7;
  undefined1 *puVar8;
  undefined6 in_register_00000082;
  undefined8 uVar9;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  undefined8 in_stack_ffffffffffffffc8;
  undefined1 uVar10;
  
  lVar7 = 0;
  if (param_1 == (_UDECXUSBDEVICE_INIT *)0x0) {
    lVar7 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,
                        CONCAT62(in_register_00000082,param_3),0x13,
                        &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,0xd);
    }
  }
  else {
    uVar10 = (undefined1)param_3;
    if (param_3 < 2) {
      lVar7 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,
                           CONCAT62(in_register_00000082,param_3),0x14,in_stack_ffffffffffffffc8,
                           uVar10,0xd);
      }
    }
    else {
      uVar5 = 0x20;
      uVar9 = 0x78454455;
      plVar2 = (longlong *)ExAllocatePool2(0x40);
      if (plVar2 == (longlong *)0x0) {
        lVar7 = -0x3fffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar9,0x15,
                             &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,uVar10,1);
        }
      }
      else {
        uVar5 = 0x78454455;
        uVar6 = (ulonglong)param_3;
        lVar3 = ExAllocatePool2(0x40);
        puVar8 = auStackY_58;
        plVar2[2] = lVar3;
        if (lVar3 == 0) {
          lVar7 = -0x3fffffff;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,uVar5,0x16,
                               &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,uVar10,1);
          }
          ExFreePoolWithTag(plVar2,0x78454455);
        }
        else {
          p_Var4 = param_1 + 0x60;
          lVar3 = *(longlong *)p_Var4;
          if (*(_UDECXUSBDEVICE_INIT **)(lVar3 + 8) != p_Var4) {
            lVar3 = 3;
            pcVar1 = (code *)swi(0x29);
            p_Var4 = (_UDECXUSBDEVICE_INIT *)(*pcVar1)();
            puVar8 = auStackY_50;
          }
          *plVar2 = lVar3;
          plVar2[1] = (longlong)p_Var4;
          *(longlong **)(lVar3 + 8) = plVar2;
          _Dst = (void *)plVar2[2];
          *(longlong **)p_Var4 = plVar2;
          *(undefined8 *)(puVar8 + -8) = 0x140005d3a;
          memcpy(_Dst,param_2,(ulonglong)param_3);
          *(uchar *)((longlong)plVar2 + 0x1c) = param_2[1];
          *(undefined2 *)((longlong)plVar2 + 0x1e) = *(undefined2 *)(puVar8 + 0x80);
          *(uint *)(plVar2 + 3) = (uint)param_3;
          *(uchar *)((longlong)plVar2 + 0x1d) = param_4;
        }
      }
    }
  }
  return lVar7;
}



===== UsbDevice_EvtControlTransferUrb @ 140005d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl UsbDevice_EvtControlTransferUrb(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
UsbDevice_EvtControlTransferUrb
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  byte bVar1;
  longlong lVar2;
  byte bVar3;
  undefined1 uVar4;
  long lVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined7 uVar14;
  ulong *puVar13;
  char cVar15;
  undefined2 uVar16;
  uchar *_Dst;
  longlong *plVar17;
  undefined1 auStackY_e8 [32];
  ulong local_88 [2];
  uchar *local_80;
  longlong local_78;
  undefined8 local_70;
  ulong local_68 [2];
  longlong lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar11 = 0;
  local_80 = (uchar *)0x0;
  lVar5 = 0;
  local_88[0] = 0;
  puVar7 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROL_QUEUE_CONTEXT_TYPE_INFO_14000e278);
  puVar7 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*puVar7,PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0);
  local_70 = *puVar7;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,local_70,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  puVar13 = local_68;
  lVar9 = *(longlong *)(lVar8 + 0x18);
  lStack_60 = 0;
  local_48 = 0;
  local_68[0] = 0x28;
  local_68[1] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = lVar9;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2);
  lVar2 = lStack_60;
  _Dst = (uchar *)0x0;
  if (*(int *)(lStack_60 + 0x24) == 0) {
LAB_140005ed4:
    bVar1 = *(byte *)(lVar2 + 0x80);
    bVar3 = bVar1 & 3;
    uVar14 = (undefined7)((ulonglong)puVar13 >> 8);
    if (bVar3 == 0) {
      if ((bVar1 & 0x60) == 0) {
        if ((char)bVar1 < '\0') {
          if (*(char *)(lVar2 + 0x81) == '\x06') {
            plVar10 = (longlong *)(local_78 + 0x60);
            plVar17 = (longlong *)*plVar10;
            if (plVar10 != plVar17) {
              puVar13 = (ulong *)CONCAT71(uVar14,*(char *)(lVar2 + 0x83));
              do {
                if (((*(char *)((longlong)plVar17 + 0x1c) == *(char *)(lVar2 + 0x83)) &&
                    (*(char *)((longlong)plVar17 + 0x1d) == *(char *)(lVar2 + 0x82))) &&
                   (*(short *)((longlong)plVar17 + 0x1e) == *(short *)(lVar2 + 0x84))) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                  }
                  uVar12 = *(uint *)(plVar17 + 3);
                  if ((uint)*(ushort *)(lVar2 + 0x86) <= *(uint *)(plVar17 + 3)) {
                    uVar12 = (uint)*(ushort *)(lVar2 + 0x86);
                  }
                  uVar6 = *(uint *)(lVar2 + 0x24);
                  if (uVar12 <= *(uint *)(lVar2 + 0x24)) {
                    uVar6 = uVar12;
                  }
                  if (uVar6 != 0) {
                    memcpy(_Dst,(void *)plVar17[2],(ulonglong)uVar6);
                  }
                  *(uint *)(lVar2 + 0x24) = uVar6;
                  goto LAB_1400062b2;
                }
                plVar17 = (longlong *)*plVar17;
              } while (plVar10 != plVar17);
            }
            goto LAB_140005f4e;
          }
          if (-1 < (char)bVar1) goto LAB_140006060;
        }
        else {
LAB_140006060:
          if (*(char *)(lVar2 + 0x81) == '\t') {
            *(undefined2 *)(lVar8 + 0x20) = 0x101;
            *(undefined1 *)(lVar8 + 0x23) = *(undefined1 *)(lVar2 + 0x82);
            goto LAB_14000607e;
          }
        }
LAB_140006163:
        if ((*(char *)(lVar2 + 0x81) == '\x03') && (*(short *)(lVar2 + 0x82) == 1)) {
          *(undefined4 *)(lVar8 + 0x2c) = 1;
          *(undefined4 *)(lVar8 + 0x30) = 1;
        }
        else {
          puVar13 = (ulong *)CONCAT71(uVar14,*(char *)(lVar2 + 0x81));
          if (*(char *)(lVar2 + 0x81) != '\x05') {
LAB_1400061b2:
            if (*(char *)(lVar2 + 0x81) == '\x01') {
              puVar13 = (ulong *)CONCAT71((int7)((ulonglong)puVar13 >> 8),1);
              if (*(short *)(lVar2 + 0x82) == 1) goto LAB_1400061f7;
              if ((bVar1 & 3) != 0) goto LAB_140005f4e;
            }
            puVar13 = (ulong *)CONCAT71((int7)((ulonglong)puVar13 >> 8),*(char *)(lVar2 + 0x81));
            if (*(char *)(lVar2 + 0x81) != '0') goto LAB_1400061dd;
          }
LAB_1400061f7:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_DDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
        }
LAB_14000607e:
        *(uint *)(lVar2 + 0x24) = (uint)*(ushort *)(lVar2 + 0x86);
        goto LAB_1400062b2;
      }
    }
    else if (bVar3 == 1) {
      if ((bVar1 & 0x60) == 0) {
        if (((char)bVar1 < '\0') || (*(char *)(lVar2 + 0x81) != '\v')) {
LAB_1400060d7:
          if ((*(char *)(lVar2 + 0x81) == '\x03') && (*(short *)(lVar2 + 0x82) == 0)) {
            cVar15 = '\0';
            uVar4 = *(undefined1 *)(lVar2 + 0x84);
            *(uint *)(lVar2 + 0x24) = (uint)*(ushort *)(lVar2 + 0x86);
            if ((*(byte *)(lVar2 + 0x85) & 1) != 0) {
              cVar15 = ((*(byte *)(lVar2 + 0x85) & 2) != 0) + '\x01';
            }
            if ((lVar9 != -0x18) && (*(longlong *)(lVar9 + 0x30) != 0)) {
              *(WDFREQUEST__ **)(lVar8 + 0x48) = param_2;
              lVar5 = (**(code **)(lVar9 + 0x30))
                                (*(undefined8 *)(local_78 + 8),local_70,uVar4,cVar15);
              if (lVar5 != 0x103) {
                *(undefined8 *)(lVar8 + 0x48) = 0;
              }
            }
            if (lVar5 == 0x103) {
              return;
            }
            goto LAB_1400062b2;
          }
          goto LAB_140006190;
        }
        *(undefined1 *)(lVar8 + 0x22) = 1;
        *(undefined1 *)(lVar8 + 0x25) = *(undefined1 *)(lVar2 + 0x82);
        *(undefined1 *)(lVar8 + 0x24) = *(undefined1 *)(lVar2 + 0x84);
        goto LAB_14000607e;
      }
    }
    else if ((bVar1 & 0x60) == 0) {
      if (bVar3 == 1) goto LAB_1400060d7;
      if (bVar3 == 0) goto LAB_140006163;
LAB_140006190:
      if (bVar3 != 2) {
LAB_1400061a9:
        if ((bVar1 & 3) != 0) goto LAB_140005f4e;
        goto LAB_1400061b2;
      }
      if (*(char *)(lVar2 + 0x81) == '\x01') {
        puVar13 = (ulong *)CONCAT71(uVar14,1);
        if (*(short *)(lVar2 + 0x82) != 0) goto LAB_1400061a9;
        goto LAB_1400061f7;
      }
LAB_1400061dd:
      if (((bVar1 & 3) == 0) &&
         (puVar13 = (ulong *)CONCAT71((int7)((ulonglong)puVar13 >> 8),*(char *)(lVar2 + 0x81)),
         *(char *)(lVar2 + 0x81) == '1')) goto LAB_1400061f7;
    }
LAB_140005f4e:
    for (uVar12 = 0;
        uVar6 = (**(code **)(WdfFunctions_01015 + 0x70))
                          (WdfDriverGlobals,*(undefined8 *)(lVar8 + 8)), uVar12 < uVar6;
        uVar12 = uVar12 + 1) {
      puVar13 = (ulong *)(ulonglong)uVar12;
      lVar9 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,*(undefined8 *)(lVar8 + 8));
      if (lVar9 == 0) {
        lVar5 = -0x3fffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000634d;
        uVar16 = 0x1a;
        goto LAB_14000632b;
      }
      puVar13 = (ulong *)PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8;
      lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar9);
      if (*(char *)(lVar9 + 0x28) == '\0') {
        puVar13 = *(ulong **)(lVar9 + 0x18);
        lVar5 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2);
        if (-1 < lVar5) {
          return;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400062b2;
        uVar16 = 0x1c;
        goto LAB_140006290;
      }
    }
    lVar5 = -0x3ffffff0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar16 = 0x1b;
LAB_14000632b:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar13,uVar16,
                        &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,(char)lVar5);
    }
  }
  else {
    puVar13 = local_88;
    lVar5 = UrbRetrieveBuffer(param_2,&local_80,puVar13);
    if (-1 < lVar5) {
      _Dst = local_80;
      goto LAB_140005ed4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar16 = 0x17;
LAB_140006290:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar13,uVar16,
                        &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,(char)lVar5);
    }
LAB_1400062b2:
    if (lVar5 == -0x3ffffff2) {
      uVar11 = 0xc0007000;
      goto LAB_140006352;
    }
    if (lVar5 == -0x3fffff66) {
      uVar11 = 0xc0001000;
      goto LAB_140006352;
    }
    if (lVar5 == -0x3fffff45) {
      uVar11 = 0xc0000e00;
      goto LAB_140006352;
    }
    if (lVar5 == -0x3ffffee0) {
      uVar11 = 0xc0010000;
      goto LAB_140006352;
    }
    if (lVar5 == 0) goto LAB_140006352;
  }
LAB_14000634d:
  uVar11 = 0x80000300;
LAB_140006352:
  *(undefined4 *)(lVar2 + 4) = uVar11;
  uVar4 = KfRaiseIrql(2);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar5);
  KeLowerIrql(uVar4);
  return;
}



===== UsbDevice_EvtUcxUsbDeviceCleanup @ 1400063d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UsbDevice_EvtUcxUsbDeviceCleanup(void * __ptr64) */

void __cdecl UsbDevice_EvtUcxUsbDeviceCleanup(void *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined *puVar4;
  
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0);
  if (*plVar1 != 0) {
    puVar4 = PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228;
    puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x27,
                       &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids);
    }
    puVar4 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
    if (*(int *)(lVar3 + 0x80) != 0) {
      if (*(int *)(lVar3 + 0x84) == 2) {
        *(undefined1 *)(lVar3 + 0x88) = 1;
        DispatchDeviceReset(lVar3 + 0x30);
      }
      else {
        *(undefined4 *)(lVar3 + 0x80) = 0;
      }
    }
    if (*(char *)((longlong)puVar2 + 0x34) == '\x01') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x28,
                         &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids);
      }
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*plVar1);
    }
  }
  return;
}



===== UsbDevice_FreeUdecxUsbDeviceInit @ 140006528 =====

/* void __cdecl UsbDevice_FreeUdecxUsbDeviceInit(struct _UDECXUSBDEVICE_INIT * __ptr64) */

void __cdecl UsbDevice_FreeUdecxUsbDeviceInit(_UDECXUSBDEVICE_INIT *param_1)

{
  _UDECXUSBDEVICE_INIT *p_Var1;
  _UDECXUSBDEVICE_INIT *p_Var2;
  
  p_Var1 = *(_UDECXUSBDEVICE_INIT **)(param_1 + 0x60);
  p_Var2 = *(_UDECXUSBDEVICE_INIT **)p_Var1;
  while (param_1 + 0x60 != p_Var1) {
    ExFreePoolWithTag(*(undefined8 *)(p_Var1 + 0x10),0x78454455);
    ExFreePoolWithTag(p_Var1,0x78454455);
    p_Var1 = p_Var2;
    p_Var2 = *(_UDECXUSBDEVICE_INIT **)p_Var2;
  }
  ExFreePoolWithTag(param_1);
  return;
}



===== UsbDevice_PrepareEndpointsConfigure @ 1400065ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UsbDevice_PrepareEndpointsConfigure(struct WDFREQUEST__ * __ptr64,struct
   UDECXUSBDEVICE__ * __ptr64,unsigned long,struct UCXENDPOINT__ * __ptr64 * __ptr64,unsigned
   long,struct UCXENDPOINT__ * __ptr64 * __ptr64) */

void __cdecl
UsbDevice_PrepareEndpointsConfigure
          (WDFREQUEST__ *param_1,UDECXUSBDEVICE__ *param_2,ulong param_3,UCXENDPOINT__ **param_4,
          ulong param_5,UCXENDPOINT__ **param_6)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined4 *local_res8;
  UDECXUSBDEVICE__ *local_res10;
  undefined8 local_88;
  size_t local_80;
  longlong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  WDFREQUEST__ *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  local_88 = 0;
  local_res8 = (undefined4 *)0x0;
  uVar9 = (ulonglong)param_3;
  local_res10 = param_2;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10),
             PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0);
  local_78 = *(longlong *)(lVar3 + 0x18);
  uVar8 = (ulonglong)param_5;
  uVar7 = 0x200;
  local_60 = 0;
  local_80 = (uVar9 + uVar8) * 8 + 0x28;
  uStack_58 = 0x100000001;
  local_40 = 0;
  uStack_68 = 0;
  uStack_48 = 0;
  local_70 = 0x38;
  local_50 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,&local_70,0x200,0x78454455,local_80,&local_88,&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x24,
                        &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,(char)iVar1);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  }
  else {
    memset(local_res8,0,local_80);
    *local_res8 = 0x28;
    local_res8[3] = param_3;
    local_res8[6] = param_5;
    puVar4 = local_res8 + 10;
    if (param_3 != 0) {
      *(undefined4 **)(local_res8 + 4) = puVar4;
      puVar4 = puVar4 + uVar9 * 2;
    }
    if (param_5 != 0) {
      *(undefined4 **)(local_res8 + 8) = puVar4;
    }
    if (param_3 != 0) {
      lVar6 = 0;
      do {
        puVar5 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,*(undefined8 *)(lVar6 + (longlong)param_4),
                            PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188);
        *(undefined8 *)(lVar6 + *(longlong *)(local_res8 + 4)) = *puVar5;
        lVar6 = lVar6 + 8;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    if (param_5 != 0) {
      lVar6 = 0;
      do {
        puVar5 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,*(undefined8 *)(lVar6 + (longlong)param_6),
                            PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188);
        *(undefined8 *)(lVar6 + *(longlong *)(local_res8 + 8)) = *puVar5;
        lVar6 = lVar6 + 8;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    if (*(char *)(lVar3 + 0x22) == '\0') {
      if (*(char *)(lVar3 + 0x21) == '\0') {
        uVar2 = 3;
        if (param_3 != 0) {
          uVar2 = 0;
        }
        local_res8[1] = uVar2;
      }
      else {
        local_res8[1] = 1;
        *(undefined1 *)(local_res8 + 2) = *(undefined1 *)(lVar3 + 0x23);
        *(undefined1 *)(lVar3 + 0x21) = 0;
      }
    }
    else {
      local_res8[1] = 2;
      *(undefined1 *)((longlong)local_res8 + 9) = *(undefined1 *)(lVar3 + 0x24);
      *(undefined1 *)((longlong)local_res8 + 10) = *(undefined1 *)(lVar3 + 0x25);
      *(undefined2 *)(lVar3 + 0x21) = 0;
    }
    (**(code **)(local_78 + 0x50))(local_res10,param_1,local_res8);
  }
  return;
}



===== UsbDevice_UcxEndpointAdd @ 14000689c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UsbDevice_UcxEndpointAdd(struct WDFDEVICE__ * __ptr64,struct UDECXUSBDEVICE__ *
   __ptr64,unsigned char,struct _USB_ENDPOINT_DESCRIPTOR * __ptr64,struct
   _USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR * __ptr64,struct _UCXENDPOINT_INIT * __ptr64) */

long __cdecl
UsbDevice_UcxEndpointAdd
          (WDFDEVICE__ *param_1,UDECXUSBDEVICE__ *param_2,uchar param_3,
          _USB_ENDPOINT_DESCRIPTOR *param_4,_USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR *param_5,
          _UCXENDPOINT_INIT *param_6)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  code *pcVar8;
  longlong *plVar9;
  undefined8 uVar10;
  uint uVar11;
  undefined *puVar12;
  undefined4 *puVar13;
  _UCXENDPOINT_INIT **pp_Var14;
  undefined2 uVar15;
  undefined8 *puVar16;
  undefined8 *in_stack_fffffffffffffe78;
  undefined8 local_168 [2];
  undefined8 local_158;
  code *pcStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined *local_128;
  undefined8 local_120;
  code *pcStack_118;
  code *local_110;
  code *pcStack_108;
  code *local_100;
  code *pcStack_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  code *local_78;
  
  local_f0 = 0;
  local_120 = 0;
  pcStack_118 = (code *)0x0;
  local_110 = (code *)0x0;
  pcStack_108 = (code *)0x0;
  local_100 = (code *)0x0;
  pcStack_f8 = (code *)0x0;
  memset(&local_e8,0,0x60);
  local_128 = (undefined *)0x0;
  local_158 = 0;
  pcStack_150 = (code *)0x0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  memset(&local_88,0,0x60);
  local_168[0] = 0;
  puVar12 = PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
  lVar4 = *(longlong *)(lVar3 + 0x18);
  if (*(int *)(lVar4 + 0x14) == 1) {
    uVar11 = 0;
    while( true ) {
      uVar10 = *(undefined8 *)(lVar3 + 8);
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals);
      if (uVar1 <= uVar11) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff0;
        }
        WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,puVar12,0x2a,
                           in_stack_fffffffffffffe78,param_3,0x10);
        return -0x3ffffff0;
      }
      puVar13 = (undefined4 *)(ulonglong)uVar11;
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 8));
      if (lVar4 == 0) {
        iVar2 = -0x3fffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3fffffff;
        }
        uVar15 = 0x29;
        goto LAB_140006b47;
      }
      puVar12 = PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4);
      if (*(uchar *)(lVar5 + 0x28) == param_3) break;
      uVar11 = uVar11 + 1;
    }
    if (param_3 == '\0') {
      puVar12 = PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0;
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10));
      local_168[0] = *(undefined8 *)(lVar6 + 8);
    }
    else {
      local_88 = 0x60;
      local_84 = 1;
      local_78 = Endpoint_EvtSimpleEndpointQueueIoDefault;
      puVar13 = &local_88;
      uStack_140 = 0x100000001;
      local_128 = PTR__WDF_SIMPLE_ENDPOINT_QUEUE_CONTEXT_TYPE_INFO_14000e160;
      local_80 = 2;
      local_158 = CONCAT44(local_158._4_4_,0x38);
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                        (WdfDriverGlobals,param_1,puVar13,&local_158,local_168);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        uVar15 = 0x2b;
        goto LAB_140006b47;
      }
      *(undefined8 *)(lVar5 + 0x20) = local_168[0];
      puVar12 = PTR__WDF_SIMPLE_ENDPOINT_QUEUE_CONTEXT_TYPE_INFO_14000e160;
      puVar7 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_168[0]);
      *puVar7 = *(undefined8 *)(lVar5 + 0x18);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar12,0x2c,
                        &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,(char)lVar4);
    }
    puVar7 = (undefined8 *)0x0;
    if (param_3 == '\0') goto LAB_140006d2b;
LAB_140006d88:
    local_e8._0_4_ = 0x60;
    local_e0 = EvtUcxEndpointPurge;
    puVar16 = &local_e8;
    local_d8 = EvtUcxEndpointStart;
    local_d0 = EvtUcxEndpointAbort;
    local_c8 = EvtUcxEndpointReset;
    local_c0 = EvtUcxEndpointOkToCancelTransfers;
    local_b8 = EvtUcxEndpointStaticStreamsAdd;
    local_b0 = EvtUcxEndpointStaticStreamsDisable;
    local_a8 = EvtUcxEndpointStaticStreamsDisable;
    pcVar8 = DAT_14000e7a8;
  }
  else {
    puVar13 = (undefined4 *)0x78454455;
    puVar7 = (undefined8 *)ExAllocatePool2(0x40);
    if (puVar7 == (undefined8 *)0x0) {
      iVar2 = -0x3fffffff;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffffff;
      }
      uVar15 = 0x2d;
LAB_140006b47:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar13,uVar15,
                        &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,(char)iVar2);
      return iVar2;
    }
    pp_Var14 = (_UCXENDPOINT_INIT **)0x60;
    memset(puVar7,0,0x60);
    *(undefined4 *)puVar7 = 0x60;
    puVar16 = puVar7 + 3;
    *puVar16 = puVar7;
    puVar7[2] = param_2;
    if (param_3 == '\0') {
      pcVar8 = *(code **)(lVar4 + 0x40);
      puVar16 = puVar7;
    }
    else {
      if (param_4 == (_USB_ENDPOINT_DESCRIPTOR *)0x0) {
        iVar2 = -0x3ffffff3;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_fffffffffffffe78 = (undefined8 *)&WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids
          ;
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var14,0x2e,
                            &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,0xd);
        }
        goto LAB_140006ec3;
      }
      *(uint *)(puVar7 + 4) = (uint)(byte)*param_4;
      puVar7[6] = param_5;
      pcVar8 = *(code **)(lVar4 + 0x48);
      puVar7[5] = param_4;
    }
    iVar2 = (*pcVar8)(param_2);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar16,pp_Var14,0x2f,
                           in_stack_fffffffffffffe78,param_3,(char)iVar2);
      }
      iVar2 = -0x3ffffff0;
      goto LAB_140006ec3;
    }
    lVar4 = puVar7[1];
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar4,PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
    if (param_3 != '\0') {
      local_168[0] = *(undefined8 *)(lVar5 + 0x18);
      goto LAB_140006d88;
    }
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10),
                       PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0);
    local_168[0] = *(undefined8 *)(lVar6 + 8);
LAB_140006d2b:
    local_f0 = 0;
    puVar16 = &local_120;
    pcStack_118 = EvtUcxEndpointPurge;
    local_110 = EvtUcxEndpointStart;
    pcStack_108 = EvtUcxEndpointAbort;
    local_100 = EvtUcxEndpointOkToCancelTransfers;
    pcStack_f8 = EvtUcxUsbDeviceAddress;
    local_120 = 0x38;
    pcVar8 = DAT_14000e7b0;
  }
  (*pcVar8)(UcxDriverGlobals,param_6,puVar16);
  local_148 = 0;
  pp_Var14 = &param_6;
  uStack_140 = 0x100000001;
  puVar16 = (undefined8 *)(lVar5 + 0x10);
  local_128 = PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188;
  pcStack_150 = Endpoint_UcxEndpointCleanup;
  local_138 = 0;
  uStack_130 = 0;
  local_158 = 0x38;
  in_stack_fffffffffffffe78 = puVar16;
  iVar2 = (*DAT_14000e790)(UcxDriverGlobals,*(undefined8 *)(lVar3 + 0x10),pp_Var14,&local_158);
  if (-1 < iVar2) {
    plVar9 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*puVar16,PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188)
    ;
    uVar10 = UcxDriverGlobals;
    *plVar9 = lVar4;
    (*DAT_14000e7b8)(uVar10,*puVar16,local_168[0]);
    return iVar2;
  }
  if (puVar7 == (undefined8 *)0x0) {
    return iVar2;
  }
LAB_140006ec3:
  if (puVar7[1] == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,pp_Var14,0x30,
                         in_stack_fffffffffffffe78,param_3,(char)iVar2);
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  ExFreePoolWithTag(puVar7,0x78454455);
  return iVar2;
}



===== UsbDevice_UcxUsbDeviceCreate @ 140006f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UsbDevice_UcxUsbDeviceCreate(struct WDFDEVICE__ * __ptr64,struct _UCXUSBDEVICE_INFO
   * __ptr64,struct _UCXUSBDEVICE_INIT * __ptr64) */

long __cdecl
UsbDevice_UcxUsbDeviceCreate
          (WDFDEVICE__ *param_1,_UCXUSBDEVICE_INFO *param_2,_UCXUSBDEVICE_INIT *param_3)

{
  uint uVar1;
  UCXROOTHUB__ *pUVar2;
  long lVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  ulonglong uVar9;
  longlong lVar10;
  _PORT_CONTEXT **pp_Var11;
  _UCXUSBDEVICE_INIT **pp_Var12;
  undefined *puVar13;
  undefined2 uVar14;
  undefined8 local_res10;
  _UCXUSBDEVICE_INIT *local_res18;
  longlong local_res20;
  _PORT_CONTEXT *local_188;
  undefined4 local_180;
  undefined4 local_17c;
  code *local_178;
  undefined8 local_170;
  undefined4 local_168;
  undefined4 local_164;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined *local_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined *local_118;
  undefined8 local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 local_98;
  undefined4 local_90;
  code *local_68;
  
  uVar1 = *(uint *)(param_2 + 0x1c);
  local_res10 = 0;
  local_17c = 0;
  local_170 = 0;
  local_res20 = 0;
  local_160 = 0;
  uStack_158 = 0;
  local_res18 = param_3;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  lVar10 = 0;
  local_188 = (_PORT_CONTEXT *)0x0;
  pUVar2 = *(UCXROOTHUB__ **)(lVar5 + 8);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,pUVar2,PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0);
  RootHub_LockAcquire(*(WDFSPINLOCK__ **)(lVar6 + 0x10));
  pp_Var11 = &local_188;
  uVar9 = (ulonglong)uVar1;
  lVar3 = RootHub_PortContextFromPortNumber(pUVar2,uVar1,pp_Var11);
  lVar5 = lVar10;
  if ((-1 < lVar3) && (lVar5 = *(longlong *)(local_188 + 8), lVar5 == 0)) {
    lVar3 = -0x3ffffff3;
    lVar5 = lVar10;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,pp_Var11,0x19,
                          &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,(char)uVar1,
                          (char)*(undefined4 *)local_188,0xd);
    }
  }
  RootHub_LockRelease(*(WDFSPINLOCK__ **)(lVar6 + 0x10));
  if (lVar3 < 0) {
    return lVar3;
  }
  local_17c = 0;
  local_170 = 0;
  local_150 = PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0;
  local_178 = UsbDevice_EvtUcxUsbDeviceCleanup;
  local_a8 = 0;
  local_100 = EvtUcxUsbDeviceEndpointsConfigure;
  local_f8 = EvtUcxUsbDeviceEnable;
  local_f0 = EvtUcxUsbDeviceDisable;
  local_e8 = EvtUcxUsbDeviceReset;
  local_e0 = EvtUcxUsbDeviceAddress;
  local_d8 = EvtUcxUsbDeviceAddress;
  local_d0 = EvtUcxUsbDeviceAddress;
  local_c8 = EvtUcxUsbDeviceDefaultEndpointAdd;
  local_c0 = EvtUcxUsbDeviceEndpointAdd;
  local_160 = 0;
  uStack_158 = 0;
  local_180 = 0x38;
  local_168 = 1;
  local_164 = 1;
  local_108 = 0x68;
  local_b8 = 0;
  uStack_b0 = 0;
  (*DAT_14000e780)(UcxDriverGlobals,local_res18,&local_108);
  puVar7 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  pp_Var12 = &local_res18;
  iVar4 = (*DAT_14000e778)(UcxDriverGlobals,*puVar7,pp_Var12,&local_180,&local_res10);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar4;
    }
    uVar14 = 0x20;
  }
  else {
    plVar8 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res10,
                        PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0);
    *plVar8 = lVar5;
    local_118 = PTR__WDF_CONTROL_QUEUE_CONTEXT_TYPE_INFO_14000e278;
    local_138 = 0;
    local_160 = local_res10;
    uStack_140 = 0;
    local_148 = 0x38;
    local_128 = 0;
    uStack_120 = 0;
    uStack_130 = 0x100000001;
    memset(&local_98,0,0x60);
    local_98._0_4_ = 0x60;
    local_68 = UsbDevice_EvtControlTransferUrb;
    local_90 = 2;
    pp_Var12 = (_UCXUSBDEVICE_INIT **)&local_98;
    local_98._4_4_ = 1;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,param_1,pp_Var12,&local_148,&local_res20);
    if (-1 < iVar4) {
      puVar7 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_res20,
                          PTR__WDF_CONTROL_QUEUE_CONTEXT_TYPE_INFO_14000e278);
      *puVar7 = local_res10;
      plVar8[1] = local_res20;
      puVar13 = PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar5);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar13,0x22,
                         &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids);
      }
      *(undefined8 *)(lVar5 + 0x10) = local_res10;
      return iVar4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar4;
    }
    uVar14 = 0x21;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var12,uVar14,
                    &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,(char)iVar4);
  return iVar4;
}



===== UsbDevice_UdeUsbDeviceCleanup @ 140007380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UsbDevice_UdeUsbDeviceCleanup(void * __ptr64) */

void __cdecl UsbDevice_UdeUsbDeviceCleanup(void *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  UsbDevice_FreeUdecxUsbDeviceInit(*(_UDECXUSBDEVICE_INIT **)(lVar1 + 0x18));
  *(undefined8 *)(lVar1 + 0x18) = 0;
  return;
}



===== WPP_RECORDER_SF_DDDDD @ 1400073c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,0x19,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,0x19,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_Dd @ 1400074f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,param_4,&param_6,4,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_dDDDDD @ 1400075c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dDDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,0x18,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,0x18,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== _UdecxUsbDeviceCreate @ 140007710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int _UdecxUsbDeviceCreate(undefined8 param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  longlong local_res10;
  undefined4 *local_res20;
  int iVar5;
  longlong local_d8;
  code *pcStack_d0;
  longlong local_c8;
  longlong lStack_c0;
  undefined8 local_b8;
  longlong lStack_b0;
  undefined *local_a8;
  longlong local_a0 [3];
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  longlong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_a8 = (undefined *)0x0;
  local_38 = 0;
  *param_4 = 0;
  lVar1 = *param_2;
  local_d8 = 0;
  pcStack_d0 = (code *)0x0;
  local_res10 = 0;
  local_c8 = 0;
  lStack_c0 = 0;
  local_b8 = 0;
  lStack_b0 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (*(int *)(lVar1 + 0x14) == 2) {
    if (((*(longlong *)(lVar1 + 0x40) == 0) || (*(longlong *)(lVar1 + 0x48) == 0)) ||
       (*(longlong *)(lVar1 + 0x50) == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar4 = 0xb;
      goto LAB_1400077a4;
    }
LAB_1400077d4:
    uVar2 = *(undefined8 *)(lVar1 + 8);
    if (param_3 == (longlong *)0x0) {
      local_d8 = 0x38;
      lStack_c0 = 0x100000001;
    }
    else {
      local_d8 = *param_3;
      pcStack_d0 = (code *)param_3[1];
      local_c8 = param_3[2];
      lStack_c0 = param_3[3];
      lStack_b0 = param_3[5];
      local_a8 = (undefined *)param_3[6];
    }
    param_3 = &local_res10;
    local_b8 = uVar2;
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_d8);
    if (iVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140007a1b;
      uVar4 = 0xd;
    }
    else {
      param_3 = local_a0;
      local_70 = PTR__WDF_WdfCustomType_UDECXUSBDEVICE_TYPE_INFO_14000e200;
      local_res20 = (undefined4 *)0x0;
      local_a0[0] = 0x38;
      local_80 = 0;
      uStack_78 = 0;
      local_88 = 1;
      local_84 = 1;
      local_a0[1] = 0;
      local_a0[2] = 0;
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,local_res10,param_3,&local_res20);
      if (iVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140007a1b;
        uVar4 = 0xe;
      }
      else {
        param_3 = &local_d8;
        *local_res20 = 0x10;
        *(undefined8 *)(local_res20 + 2) = 0;
        local_a8 = PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228;
        pcStack_d0 = UsbDevice_UdeUsbDeviceCleanup;
        local_d8 = 0x38;
        local_c8 = 0;
        local_b8 = 0;
        lStack_b0 = 0;
        lStack_c0 = 0x100000001;
        iVar5 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_res10,param_3,0);
        if (iVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140007a1b;
          uVar4 = 0xf;
        }
        else {
          puVar3 = (undefined8 *)
                   (**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,local_res10,
                              PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
          param_3 = puVar3 + 1;
          *puVar3 = uVar2;
          puVar3[3] = *param_2;
          local_48 = local_res10;
          local_68 = CONCAT44(local_68._4_4_,0x38);
          uStack_50 = 0x100000001;
          iVar5 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_68);
          if (-1 < iVar5) {
            *param_4 = local_res10;
            *param_2 = 0;
            return iVar5;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140007a1b;
          uVar4 = 0x10;
        }
      }
    }
  }
  else {
    if (*(int *)(lVar1 + 0x14) != 0) goto LAB_1400077d4;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar4 = 0xc;
LAB_1400077a4:
    iVar5 = -0x3ffffff3;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,uVar4,
                    &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,(char)iVar5);
LAB_140007a1b:
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar5;
}



===== _UdecxUsbDeviceInitAddDescriptor @ 140007a70 =====

void _UdecxUsbDeviceInitAddDescriptor
               (undefined8 param_1,_UDECXUSBDEVICE_INIT *param_2,uchar *param_3,ushort param_4)

{
  UsbDevice_AddUdecxUsbDeviceInitDescriptor(param_2,param_3,param_4,'\0',0);
  return;
}



===== _UdecxUsbDeviceInitAddDescriptorWithIndex @ 140007ab0 =====

void _UdecxUsbDeviceInitAddDescriptorWithIndex
               (undefined8 param_1,_UDECXUSBDEVICE_INIT *param_2,uchar *param_3,ushort param_4,
               uchar param_5)

{
  UsbDevice_AddUdecxUsbDeviceInitDescriptor(param_2,param_3,param_4,param_5,0);
  return;
}



===== _UdecxUsbDeviceInitAddStringDescriptor @ 140007af0 =====

long _UdecxUsbDeviceInitAddStringDescriptor
               (undefined8 param_1,_UDECXUSBDEVICE_INIT *param_2,ushort *param_3,uchar param_4,
               ushort param_5)

{
  ushort uVar1;
  void *_Src;
  long lVar2;
  uchar *puVar3;
  _UDECXUSBDEVICE_INIT *p_Var4;
  uint uVar5;
  ushort *puVar6;
  undefined2 uVar7;
  
  uVar5 = *param_3 + 2;
  if (uVar5 < 0x100) {
    p_Var4 = (_UDECXUSBDEVICE_INIT *)(ulonglong)uVar5;
    puVar6 = (ushort *)0x78454455;
    puVar3 = (uchar *)ExAllocatePool2(0x40);
    if (puVar3 != (uchar *)0x0) {
      uVar1 = *param_3;
      _Src = *(void **)(param_3 + 4);
      *puVar3 = (uchar)uVar5;
      puVar3[1] = '\x03';
      memcpy(puVar3 + 2,_Src,(ulonglong)uVar1);
      lVar2 = UsbDevice_AddUdecxUsbDeviceInitDescriptor
                        (param_2,puVar3,(ushort)uVar5,param_4,param_5);
      ExFreePoolWithTag(puVar3,0x78454455);
      return lVar2;
    }
    lVar2 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffff;
    }
    uVar7 = 0x12;
  }
  else {
    lVar2 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar7 = 0x11;
    p_Var4 = param_2;
    puVar6 = param_3;
  }
  WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var4,puVar6,uVar7,
                     &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,(uchar)uVar5,(char)lVar2);
  return lVar2;
}



===== _UdecxUsbDeviceInitAddStringDescriptorRaw @ 140007c20 =====

void _UdecxUsbDeviceInitAddStringDescriptorRaw
               (undefined8 param_1,_UDECXUSBDEVICE_INIT *param_2,uchar *param_3,ushort param_4,
               uchar param_5,ushort param_6)

{
  UsbDevice_AddUdecxUsbDeviceInitDescriptor(param_2,param_3,param_4,param_5,param_6);
  return;
}



===== _UdecxUsbDeviceInitAllocate @ 140007c60 =====

undefined4 * _UdecxUsbDeviceInitAllocate(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  undefined4 *_Dst;
  undefined8 uVar2;
  
  uVar2 = 0x78454455;
  _Dst = (undefined4 *)ExAllocatePool2(0x40);
  if (_Dst == (undefined4 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,10,
                       &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids);
    }
  }
  else {
    memset(_Dst,0,0x70);
    puVar1 = _Dst + 0x18;
    *_Dst = 0x70;
    *(undefined4 **)(_Dst + 0x1a) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    *(undefined8 *)(_Dst + 2) = param_2;
  }
  return _Dst;
}



===== _UdecxUsbDeviceInitFree @ 140007d00 =====

void _UdecxUsbDeviceInitFree(undefined8 param_1,_UDECXUSBDEVICE_INIT *param_2)

{
  UsbDevice_FreeUdecxUsbDeviceInit(param_2);
  return;
}



===== _UdecxUsbDeviceInitSetEndpointsType @ 140007d20 =====

void _UdecxUsbDeviceInitSetEndpointsType(undefined8 param_1,longlong param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x14) = param_3;
  return;
}



===== _UdecxUsbDeviceInitSetSpeed @ 140007d30 =====

void _UdecxUsbDeviceInitSetSpeed(undefined8 param_1,longlong param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x10) = param_3;
  return;
}



===== _UdecxUsbDeviceInitSetStateChangeCallbacks @ 140007d40 =====

void _UdecxUsbDeviceInitSetStateChangeCallbacks
               (undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = param_3[1];
  *(undefined8 *)(param_2 + 0x18) = *param_3;
  *(undefined8 *)(param_2 + 0x20) = uVar1;
  uVar1 = param_3[3];
  *(undefined8 *)(param_2 + 0x28) = param_3[2];
  *(undefined8 *)(param_2 + 0x30) = uVar1;
  uVar1 = param_3[5];
  *(undefined8 *)(param_2 + 0x38) = param_3[4];
  *(undefined8 *)(param_2 + 0x40) = uVar1;
  uVar1 = param_3[7];
  *(undefined8 *)(param_2 + 0x48) = param_3[6];
  *(undefined8 *)(param_2 + 0x50) = uVar1;
  return;
}



===== _UdecxUsbDeviceLinkPowerEntryComplete @ 140007d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _UdecxUsbDeviceLinkPowerEntryComplete(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  uVar1 = *(undefined8 *)(lVar2 + 0x38);
  *(undefined8 *)(lVar2 + 0x38) = 0;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,uVar1,&local_38);
  if (param_3 == -0x3ffffff2) {
    uVar3 = 0xc0007000;
  }
  else if (param_3 == -0x3fffff66) {
    uVar3 = 0xc0001000;
  }
  else if (param_3 == -0x3fffff45) {
    uVar3 = 0xc0000e00;
  }
  else if (param_3 == -0x3ffffee0) {
    uVar3 = 0xc0010000;
  }
  else {
    uVar3 = -(uint)(param_3 != 0) & 0x80000300;
  }
  *(uint *)(lStack_30 + 4) = uVar3;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar1,param_3);
  return;
}



===== _UdecxUsbDeviceLinkPowerExitComplete @ 140007e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _UdecxUsbDeviceLinkPowerExitComplete(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  uVar1 = *(undefined8 *)(lVar2 + 0x40);
  *(undefined8 *)(lVar2 + 0x40) = 0;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,uVar1,&local_38);
  if (param_3 == -0x3ffffff2) {
    uVar3 = 0xc0007000;
  }
  else if (param_3 == -0x3fffff66) {
    uVar3 = 0xc0001000;
  }
  else if (param_3 == -0x3fffff45) {
    uVar3 = 0xc0000e00;
  }
  else if (param_3 == -0x3ffffee0) {
    uVar3 = 0xc0010000;
  }
  else {
    uVar3 = -(uint)(param_3 != 0) & 0x80000300;
  }
  *(uint *)(lStack_30 + 4) = uVar3;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar1,param_3);
  return;
}



===== _UdecxUsbDevicePlugIn @ 140007fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long _UdecxUsbDevicePlugIn(undefined8 param_1,UDECXUSBDEVICE__ *param_2,longlong param_3)

{
  uint uVar1;
  uint uVar2;
  UCXROOTHUB__ *pUVar3;
  uchar uVar4;
  undefined1 uVar5;
  long lVar6;
  undefined8 *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulong uVar10;
  undefined *puVar11;
  undefined2 uVar12;
  ulong local_res18 [2];
  
  local_res18[0] = 0;
  puVar7 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  puVar11 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar7);
  pUVar3 = *(UCXROOTHUB__ **)(lVar8 + 8);
  if (param_3 == 0) {
LAB_14000812c:
    lVar6 = RootHub_FindPortAndConnectDevice(pUVar3,param_2,(_USB_DEVICE_SPEED)puVar11,local_res18);
    if (-1 < lVar6) {
      *(ulong *)(puVar7 + 5) = local_res18[0];
    }
  }
  else {
    uVar1 = *(uint *)(param_3 + 4);
    uVar2 = *(uint *)(param_3 + 8);
    uVar9 = (ulonglong)uVar2;
    if (uVar1 == 0) {
      if (uVar2 == 0) goto LAB_14000812c;
      uVar4 = RootHub_IsUsb30Port(pUVar3,uVar2);
      if (uVar4 != '\0') {
        uVar10 = *(ulong *)(param_3 + 8);
        goto LAB_140008113;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar12 = 0x1f;
      uVar5 = (undefined1)*(undefined4 *)(param_3 + 8);
    }
    else {
      if (uVar2 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,0x1d,
                          &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,0xd);
        return -0x3ffffff3;
      }
      uVar9 = (ulonglong)uVar1;
      uVar4 = RootHub_IsUsb30Port(pUVar3,uVar1);
      if (uVar4 == '\0') {
        uVar10 = *(ulong *)(param_3 + 4);
LAB_140008113:
        lVar6 = RootHub_ConnectDeviceToPort(pUVar3,param_2,uVar10);
        if (lVar6 < 0) {
          return lVar6;
        }
        *(ulong *)(puVar7 + 5) = uVar10;
        return lVar6;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar12 = 0x1e;
      uVar5 = (undefined1)*(undefined4 *)(param_3 + 4);
    }
    lVar6 = -0x3ffffff3;
    WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,puVar11,uVar12,
                       &WPP_140b8b6c86b63a75f2e340e9afbf9a6b_Traceguids,uVar5,0xd);
  }
  return lVar6;
}



===== _UdecxUsbDevicePlugOutAndDelete @ 140008170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 _UdecxUsbDevicePlugOutAndDelete(undefined8 param_1,longlong param_2)

{
  UCXROOTHUB__ *pUVar1;
  bool bVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  ulong uVar7;
  undefined8 uVar8;
  _PORT_CONTEXT **pp_Var9;
  _PORT_CONTEXT *local_res18 [2];
  
  puVar5 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar5,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  bVar2 = false;
  local_res18[0] = (_PORT_CONTEXT *)0x0;
  pUVar1 = *(UCXROOTHUB__ **)(lVar6 + 8);
  pp_Var9 = (_PORT_CONTEXT **)PTR__WDF_ROOTHUB_CONTEXT_TYPE_INFO_14000e2a0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,pUVar1);
  RootHub_LockAcquire(*(WDFSPINLOCK__ **)(lVar6 + 0x10));
  uVar7 = 1;
  uVar4 = RootHub_GetNumberOfPorts(pUVar1);
  if (uVar4 != 0) {
    do {
      pp_Var9 = local_res18;
      RootHub_PortContextFromPortNumber(pUVar1,uVar7,pp_Var9);
      if (*(longlong *)(local_res18[0] + 8) == param_2) {
        *(undefined4 *)local_res18[0] = 1;
        bVar2 = true;
        *(undefined8 *)(local_res18[0] + 8) = 0;
        uVar8 = 0;
        local_res18[0][4] = (_PORT_CONTEXT)0x1;
        goto LAB_140008286;
      }
      uVar7 = uVar7 + 1;
      uVar4 = RootHub_GetNumberOfPorts(pUVar1);
    } while (uVar7 <= uVar4);
  }
  uVar8 = 0xc000000e;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pp_Var9,0x18,
                       &WPP_27f6b11d774f37ac30dee80ebc8b13b1_Traceguids,(char)param_2,0xe);
  }
LAB_140008286:
  RootHub_LockRelease(*(WDFSPINLOCK__ **)(lVar6 + 0x10));
  if (bVar2) {
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
    uVar3 = UcxDriverGlobals;
    *(undefined1 *)(lVar6 + 0x34) = 1;
    (*DAT_14000e770)(uVar3,pUVar1);
  }
  return uVar8;
}



===== _UdecxUsbDeviceSetFunctionSuspendAndWakeComplete @ 140008310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _UdecxUsbDeviceSetFunctionSuspendAndWakeComplete
               (undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  uVar1 = *(undefined8 *)(lVar2 + 0x48);
  *(undefined8 *)(lVar2 + 0x48) = 0;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,uVar1,&local_38);
  if (param_3 == -0x3ffffff2) {
    uVar3 = 0xc0007000;
  }
  else if (param_3 == -0x3fffff66) {
    uVar3 = 0xc0001000;
  }
  else if (param_3 == -0x3fffff45) {
    uVar3 = 0xc0000e00;
  }
  else if (param_3 == -0x3ffffee0) {
    uVar3 = 0xc0010000;
  }
  else {
    uVar3 = -(uint)(param_3 != 0) & 0x80000300;
  }
  *(uint *)(lStack_30 + 4) = uVar3;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,uVar1,param_3);
  return;
}



===== _UdecxUsbDeviceSignalFunctionWake @ 140008430 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UdecxUsbDeviceSignalFunctionWake(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  (*DAT_14000e788)(UcxDriverGlobals,*(undefined8 *)(lVar1 + 0x10),param_3);
  return;
}



===== _UdecxUsbDeviceSignalWake @ 140008490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UdecxUsbDeviceSignalWake(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  UCXROOTHUB__ *pUVar2;
  undefined8 *puVar3;
  longlong lVar4;
  _PORT_CONTEXT *local_res18 [2];
  
  local_res18[0] = (_PORT_CONTEXT *)0x0;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_14000e2f0);
  pUVar2 = *(UCXROOTHUB__ **)(lVar4 + 8);
  LOCK();
  iVar1 = *(int *)(puVar3 + 6);
  *(int *)(puVar3 + 6) = 0;
  UNLOCK();
  if (iVar1 != 0) {
    RootHub_PortContextFromPortNumber(pUVar2,*(ulong *)(puVar3 + 5),local_res18);
    *(undefined4 *)local_res18[0] = 4;
    local_res18[0][6] = (_PORT_CONTEXT)0x1;
    (*DAT_14000e770)(UcxDriverGlobals,pUVar2);
  }
  return;
}



===== Endpoint_EvtSimpleEndpointQueueIoDefault @ 140008540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Endpoint_EvtSimpleEndpointQueueIoDefault(struct WDFQUEUE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64) */

void __cdecl Endpoint_EvtSimpleEndpointQueueIoDefault(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_SIMPLE_ENDPOINT_QUEUE_CONTEXT_TYPE_INFO_14000e160);
  uVar3 = *puVar2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2);
  if (-1 < iVar1) {
    return;
  }
  if (iVar1 != -0x3fdffdfc) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400085ff;
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar3,0x10,
                      &WPP_8bc7dcdd32cf39aa5c49cfbdfc34e206_Traceguids,(char)iVar1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar3,0x11,
                     &WPP_8bc7dcdd32cf39aa5c49cfbdfc34e206_Traceguids);
  }
LAB_1400085ff:
  UrbCompleteWithNtStatus(param_2,-0x3ffffee0);
  return;
}



===== Endpoint_QueuePurgeOrAbortComplete @ 140008630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Endpoint_QueuePurgeOrAbortComplete(struct WDFQUEUE__ * __ptr64,void * __ptr64) */

void __cdecl Endpoint_QueuePurgeOrAbortComplete(WDFQUEUE__ *param_1,void *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  code *pcVar4;
  
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
  iVar1 = *(int *)(lVar3 + 0x48);
  pcVar4 = *(code **)(*(longlong *)(lVar3 + 0x40) + 0x58);
  if (pcVar4 == (code *)0x0) {
    *(undefined4 *)(lVar3 + 0x48) = 0;
    if (iVar1 == 2) {
      pcVar4 = DAT_14000e7c0;
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      pcVar4 = DAT_14000e7c8;
    }
    (*pcVar4)(UcxDriverGlobals,param_2);
  }
  else {
    (*pcVar4)(*puVar2);
  }
  return;
}



===== Endpoint_StartQueueOperation @ 1400086e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Endpoint_StartQueueOperation(struct UCXENDPOINT__ * __ptr64,enum
   _UDE_ENDPOINT_PENDING_QUEUE_OPERATION) */

void __cdecl
Endpoint_StartQueueOperation(UCXENDPOINT__ *param_1,_UDE_ENDPOINT_PENDING_QUEUE_OPERATION param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  undefined8 uVar7;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(lVar4 + 8),
                     PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  lVar2 = *(longlong *)(lVar4 + 0x40);
  uVar7 = 0;
  if (*(char *)(lVar4 + 0x28) == '\0') {
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x10),
                       PTR__WDF_UCX_USB_DEVICE_CONTEXT_TYPE_INFO_14000e1b0);
    uVar7 = *(undefined8 *)(lVar5 + 8);
  }
  else {
    iVar1 = *(int *)(*(longlong *)(lVar5 + 0x18) + 0x14);
    if (iVar1 == 1) {
      uVar7 = *(undefined8 *)(lVar4 + 0x20);
    }
    else if (iVar1 == 2) {
      uVar7 = *(undefined8 *)(lVar4 + 0x18);
    }
  }
  if (param_2 == 1) {
    pcVar6 = *(code **)(lVar2 + 0x50);
    if (pcVar6 != (code *)0x0) {
      puVar3 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,param_1,PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188
                         );
      (*pcVar6)(*puVar3);
    }
    (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,uVar7);
  }
  else {
    if (param_2 == 2) {
      *(undefined4 *)(lVar4 + 0x48) = 2;
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x528);
    }
    else {
      if (param_2 != 3) {
        return;
      }
      *(undefined4 *)(lVar4 + 0x48) = 3;
      pcVar6 = *(code **)(WdfFunctions_01015 + 0xd10);
    }
    (*pcVar6)(WdfDriverGlobals,uVar7,Endpoint_QueuePurgeOrAbortComplete,param_1);
  }
  return;
}



===== Endpoint_UcxEndpointCleanup @ 1400088a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Endpoint_UcxEndpointCleanup(void * __ptr64) */

void __cdecl Endpoint_UcxEndpointCleanup(void *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCX_ENDPOINT_CONTEXT_TYPE_INFO_14000e188);
  if (*plVar1 != 0) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*plVar1,PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(lVar2 + 8),
                       PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
    if (*(int *)(*(longlong *)(lVar2 + 0x18) + 0x14) == 2) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*plVar1);
    }
  }
  return;
}



===== Endpoint_UdeUsbEndpointCleanup @ 140008950 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Endpoint_UdeUsbEndpointCleanup(void * __ptr64) */

void __cdecl Endpoint_UdeUsbEndpointCleanup(void *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(lVar1 + 8),
                     PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228);
  (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 8),param_1);
  ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x40),0x78454455);
  *(undefined8 *)(lVar1 + 0x40) = 0;
  return;
}



===== _UdecxUsbEndpointCreate @ 140008a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int _UdecxUsbEndpointCreate
              (undefined8 param_1,longlong *param_2,undefined8 *param_3,longlong *param_4)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 ****ppppuVar5;
  undefined2 uVar6;
  undefined8 ****local_res10;
  undefined4 *local_res18;
  undefined8 ***local_98;
  code *pcStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined *local_30;
  
  *param_4 = 0;
  local_res10 = (undefined8 ****)0x0;
  local_68 = (undefined *)0x0;
  local_98 = (undefined8 ***)0x0;
  pcStack_90 = (code *)0x0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  uVar1 = *(undefined8 *)(*param_2 + 0x10);
  ppppuVar5 = (undefined8 ****)PTR__WDF_VIRT_DEVICE_CONTEXT_TYPE_INFO_14000e228;
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar1);
  if (param_3 == (undefined8 *)0x0) {
    local_98 = (undefined8 ***)CONCAT44(local_98._4_4_,0x38);
    uStack_80 = 0x100000001;
  }
  else {
    local_98 = (undefined8 ***)*param_3;
    pcStack_90 = (code *)param_3[1];
    local_88 = param_3[2];
    uStack_80 = param_3[3];
    uStack_70 = param_3[5];
    local_68 = (undefined *)param_3[6];
  }
  local_78 = uVar1;
  if (*(longlong *)(*param_2 + 0x48) == 0) {
    iVar2 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140008ceb;
    uVar6 = 0xb;
    iVar2 = -0x3ffffff3;
  }
  else {
    ppppuVar5 = &local_res10;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_98);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140008ceb;
      uVar6 = 0xc;
    }
    else {
      ppppuVar5 = (undefined8 ****)&local_60;
      local_res18 = (undefined4 *)0x0;
      local_5c = 0;
      local_58 = 0;
      local_50 = 0;
      *(undefined8 *****)(*param_2 + 8) = local_res10;
      local_30 = PTR__WDF_WdfCustomType_UDECXUSBENDPOINT_TYPE_INFO_14000e1d8;
      local_40 = 0;
      uStack_38 = 0;
      local_60 = 0x38;
      local_48 = 1;
      local_44 = 1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,local_res10,ppppuVar5,&local_res18);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140008ceb;
        uVar6 = 0xd;
      }
      else {
        ppppuVar5 = &local_98;
        *local_res18 = 0x10;
        *(undefined8 *)(local_res18 + 2) = 0;
        local_88 = 0;
        local_68 = PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8;
        pcStack_90 = Endpoint_UdeUsbEndpointCleanup;
        local_78 = 0;
        uStack_70 = 0;
        local_98 = (undefined8 ***)0x38;
        uStack_80 = 0x100000001;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_res10,ppppuVar5,0);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140008ceb;
          uVar6 = 0xe;
        }
        else {
          puVar4 = (undefined8 *)
                   (**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,local_res10,
                              PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
          *puVar4 = *puVar3;
          puVar4[1] = uVar1;
          *(undefined1 *)(puVar4 + 5) = *(undefined1 *)(*param_2 + 0x38);
          puVar4[8] = *param_2;
          ppppuVar5 = local_res10;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x78))(WdfDriverGlobals,puVar3[1]);
          if (-1 < iVar2) {
            *param_4 = (longlong)local_res10;
            *param_2 = 0;
            return iVar2;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140008ceb;
          uVar6 = 0xf;
        }
      }
    }
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,ppppuVar5,uVar6,
                    &WPP_8bc7dcdd32cf39aa5c49cfbdfc34e206_Traceguids,(char)iVar2);
LAB_140008ceb:
  if (local_res10 != (undefined8 ****)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar2;
}



===== _UdecxUsbEndpointInitFree @ 140008d40 =====

void _UdecxUsbEndpointInitFree(undefined8 param_1,undefined8 param_2)

{
  ExFreePoolWithTag(param_2,0x78454455);
  return;
}



===== _UdecxUsbEndpointInitSetCallbacks @ 140008d70 =====

void _UdecxUsbEndpointInitSetCallbacks(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = param_3[1];
  *(undefined8 *)(param_2 + 0x40) = *param_3;
  *(undefined8 *)(param_2 + 0x48) = uVar1;
  uVar1 = param_3[3];
  *(undefined8 *)(param_2 + 0x50) = param_3[2];
  *(undefined8 *)(param_2 + 0x58) = uVar1;
  return;
}



===== _UdecxUsbEndpointInitSetEndpointAddress @ 140008d90 =====

void _UdecxUsbEndpointInitSetEndpointAddress(undefined8 param_1,longlong param_2,undefined1 param_3)

{
  *(undefined1 *)(param_2 + 0x38) = param_3;
  return;
}



===== _UdecxUsbEndpointPurgeComplete @ 140008da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UdecxUsbEndpointPurgeComplete(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  code *pcVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
  iVar1 = *(int *)(lVar2 + 0x48);
  *(undefined4 *)(lVar2 + 0x48) = 0;
  if (iVar1 == 2) {
    pcVar3 = DAT_14000e7c0;
  }
  else {
    if (iVar1 != 3) {
      return;
    }
    pcVar3 = DAT_14000e7c8;
  }
  (*pcVar3)(UcxDriverGlobals,*(undefined8 *)(lVar2 + 0x10));
  return;
}



===== _UdecxUsbEndpointSetWdfIoQueue @ 140008e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _UdecxUsbEndpointSetWdfIoQueue(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_VIRT_ENDPOINT_CONTEXT_TYPE_INFO_14000e2c8);
  *(undefined8 *)(lVar1 + 0x18) = param_3;
  return;
}



===== _UdecxUsbSimpleEndpointInitAllocate @ 140008e50 =====

undefined4 * _UdecxUsbSimpleEndpointInitAllocate(undefined8 param_1,undefined8 param_2)

{
  undefined4 *_Dst;
  undefined8 uVar1;
  
  uVar1 = 0x78454455;
  _Dst = (undefined4 *)ExAllocatePool2(0x40);
  if (_Dst == (undefined4 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar1,10,
                       &WPP_8bc7dcdd32cf39aa5c49cfbdfc34e206_Traceguids);
    }
  }
  else {
    memset(_Dst,0,0x60);
    *_Dst = 0x60;
    *(undefined8 *)(_Dst + 4) = param_2;
  }
  return _Dst;
}



===== UrbCompleteWithNtStatus @ 140008ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl UrbCompleteWithNtStatus(struct WDFREQUEST__ * __ptr64,long) */

void __cdecl UrbCompleteWithNtStatus(WDFREQUEST__ *param_1,long param_2)

{
  uint uVar1;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  if (param_2 == -0x3ffffff2) {
    uVar1 = 0xc0007000;
  }
  else if (param_2 == -0x3fffff66) {
    uVar1 = 0xc0001000;
  }
  else if (param_2 == -0x3fffff45) {
    uVar1 = 0xc0000e00;
  }
  else if (param_2 == -0x3ffffee0) {
    uVar1 = 0xc0010000;
  }
  else {
    uVar1 = -(uint)(param_2 != 0) & 0x80000300;
  }
  *(uint *)(lStack_30 + 4) = uVar1;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== UrbRetrieveBuffer @ 140008fd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl UrbRetrieveBuffer(struct WDFREQUEST__ * __ptr64,unsigned char * __ptr64 *
   __ptr64,unsigned long * __ptr64) */

long __cdecl UrbRetrieveBuffer(WDFREQUEST__ *param_1,uchar **param_2,ulong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  uchar *puVar3;
  long lVar4;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  uint local_50;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  lVar4 = 0;
  if (param_2 != (uchar **)0x0) {
    *param_2 = (uchar *)0x0;
  }
  if (param_3 != (ulong *)0x0) {
    *param_3 = 0;
  }
  local_28 = 0;
  lStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_48);
  lVar2 = lStack_40;
  if (*(int *)(lStack_40 + 0x24) == 0) {
    lVar4 = -0x3ffffff3;
  }
  else if (*(uchar **)(lStack_40 + 0x28) == (uchar *)0x0) {
    lVar1 = *(longlong *)(lStack_40 + 0x30);
    if ((*(byte *)(lVar1 + 10) & 5) == 0) {
      local_50 = ExDefaultMdlProtection | 0x10;
      local_58 = 0;
      puVar3 = (uchar *)MmMapLockedPagesSpecifyCache(lVar1,0,1);
    }
    else {
      puVar3 = *(uchar **)(lVar1 + 0x18);
    }
    if (puVar3 == (uchar *)0x0) {
      lVar4 = -0x3fffff66;
    }
    else if (param_2 != (uchar **)0x0) {
      *param_2 = puVar3;
      *param_3 = *(ulong *)(*(longlong *)(lVar2 + 0x30) + 0x28);
    }
  }
  else if (param_2 != (uchar **)0x0) {
    *param_2 = *(uchar **)(lStack_40 + 0x28);
    *param_3 = *(ulong *)(lStack_40 + 0x24);
  }
  return lVar4;
}



===== _UdecxUrbComplete @ 1400090f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _UdecxUrbComplete(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
  *(uint *)(lStack_30 + 4) = param_3;
  if ((int)param_3 < -0x3fffefff) {
    if (param_3 == 0xc0001000) {
      uVar1 = 0xc000009a;
      goto LAB_1400091cf;
    }
    if ((((param_3 == 0x80000200) || (param_3 == 0x80000300)) || (param_3 == 0x80000600)) ||
       (param_3 == 0xc0000a00)) {
      uVar1 = 0xc000000d;
      goto LAB_1400091cf;
    }
    if (param_3 == 0xc0000e00) {
      uVar1 = 0xc00000bb;
      goto LAB_1400091cf;
    }
  }
  else {
    if (param_3 == 0xc0007000) {
      uVar1 = 0xc000000e;
      goto LAB_1400091cf;
    }
    if (param_3 == 0xc0010000) {
      uVar1 = 0xc0000120;
      goto LAB_1400091cf;
    }
    if (param_3 < 2) {
      uVar1 = 0;
      goto LAB_1400091cf;
    }
  }
  uVar1 = 0xc0000001;
LAB_1400091cf:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar1);
  return;
}



===== _UdecxUrbCompleteWithNtStatus @ 140009210 =====

void _UdecxUrbCompleteWithNtStatus(undefined8 param_1,WDFREQUEST__ *param_2,long param_3)

{
  UrbCompleteWithNtStatus(param_2,param_3);
  return;
}



===== _UdecxUrbRetrieveBuffer @ 140009230 =====

void _UdecxUrbRetrieveBuffer
               (undefined8 param_1,WDFREQUEST__ *param_2,uchar **param_3,ulong *param_4)

{
  UrbRetrieveBuffer(param_2,param_3,param_4);
  return;
}



===== _UdecxUrbRetrieveControlSetupPacket @ 140009260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
_UdecxUrbRetrieveControlSetupPacket(undefined8 param_1,undefined1 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined1 auStackY_78 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  lStack_30 = 0;
  uVar1 = 0;
  puVar2 = &local_38;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals);
  if ((*(short *)(lStack_30 + 2) == 8) || (*(short *)(lStack_30 + 2) == 0x32)) {
    *param_3 = *(undefined8 *)(lStack_30 + 0x80);
  }
  else {
    uVar1 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar2,10,
                         &WPP_1e6488316100328186af34694d4d9a0a_Traceguids,param_2,0xd);
    }
  }
  return uVar1;
}



===== _UdecxUrbSetBytesCompleted @ 140009350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void _UdecxUrbSetBytesCompleted(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
  *(undefined4 *)(lStack_30 + 0x24) = param_3;
  return;
}



===== FxStubDriverUnloadCommon @ 1400093c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = &_Ucx_BIND_INFO;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000e428 != &__KMDF_CLASS_BIND_START) {
    puVar2 = (uint *)(PTR___KMDF_CLASS_BIND_START_14000e428 + 0x50);
    while( true ) {
      for (; (puVar1 + 2 <= puVar2 && (*(longlong *)puVar1 == 0)); puVar1 = puVar1 + 2) {
      }
      if (puVar1 < puVar2) break;
      puVar1 = puVar2;
LAB_140009421:
      if (puVar1 == (uint *)0x0) goto LAB_140009477;
      if (puVar2 <= puVar1) goto LAB_14000948f;
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      puVar1 = (uint *)((longlong)puVar1 + (ulonglong)*puVar1);
    }
    if ((puVar1 + 0x14 <= puVar2) && (*puVar1 == 0x50)) goto LAB_140009421;
LAB_140009477:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14000948f:
  WdfVersionUnbind(&DAT_14000e4d0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1400094d0 =====

void entry(_WDF_BIND_INFO *param_1,wchar_t *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140009504 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,wchar_t *param_2)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_14000e4d0 = 0x2080000;
    _DAT_14000e4d8 = &DAT_14000e520;
    RtlCopyUnicodeString(&DAT_14000e4d0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14000e4d0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14000e728 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14000e4d0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000e428 != &__KMDF_CLASS_BIND_START) {
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
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 140009690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14000e728 != (code *)0x0) && (DAT_14000e728 != FxStubDriverUnload)) {
    (*DAT_14000e728)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1400096c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400096e9) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  puVar2 = &_Ucx_BIND_INFO;
  while( true ) {
    for (; (puVar2 + 2 < (uint *)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*(longlong *)puVar2 == 0)); puVar2 = puVar2 + 2) {
    }
    if ((uint *)0x14000e41f < puVar2) break;
    if (((&__KMDF_CLASS_BIND_END < puVar2 + 0x14) || (*puVar2 != 0x50)) || (puVar2 == (uint *)0x0))
    {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_14000e428 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,*(undefined8 *)(puVar2 + 0xe),puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    puVar2 = (uint *)((ulonglong)*puVar2 + (longlong)puVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 14000984c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140009869) */
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
    if ((void **)0x14000e43f < ppvVar2) break;
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



===== __GSHandlerCheck @ 140009918 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000993c =====

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



===== __cpu_features_init @ 1400099b0 =====

/* WARNING: Removing unreachable block (ram,0x000140009a1a) */
/* WARNING: Removing unreachable block (ram,0x0001400099c9) */
/* WARNING: Removing unreachable block (ram,0x0001400099ba) */

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



===== __security_check_cookie @ 140009a80 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140009ac0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140009af0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140009af0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140009b20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140009b80 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  longlong lVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  
  if (_Size < 8) {
    if (_Size != 0) {
      puVar9 = _Dst;
      if (_Src < _Dst) {
        puVar9 = (undefined1 *)((longlong)_Dst + _Size);
        do {
          puVar2 = puVar9 + ((longlong)_Src - (longlong)_Dst) + -1;
          puVar9 = puVar9 + -1;
          _Size = _Size - 1;
          *puVar9 = *puVar2;
        } while (_Size != 0);
        return _Dst;
      }
      do {
        _Size = _Size - 1;
        *puVar9 = puVar9[(longlong)_Src - (longlong)_Dst];
        puVar9 = puVar9 + 1;
      } while (_Size != 0);
    }
    return _Dst;
  }
  if (_Size < 0x11) {
    uVar3 = *(undefined8 *)((longlong)_Src + (_Size - 8));
    *(undefined8 *)_Dst = *(undefined8 *)_Src;
    *(undefined8 *)((longlong)_Dst + (_Size - 8)) = uVar3;
    return _Dst;
  }
  if (_Size < 0x21) {
    uVar3 = *(undefined8 *)((longlong)_Src + 8);
    puVar10 = (undefined8 *)((longlong)_Src + (_Size - 0x10));
    uVar4 = *puVar10;
    uVar5 = puVar10[1];
    *(undefined8 *)_Dst = *(undefined8 *)_Src;
    *(undefined8 *)((longlong)_Dst + 8) = uVar3;
    puVar10 = (undefined8 *)((longlong)_Dst + (_Size - 0x10));
    *puVar10 = uVar4;
    puVar10[1] = uVar5;
    return _Dst;
  }
  lVar15 = (longlong)_Src - (longlong)_Dst;
  if ((_Src < _Dst) && (_Dst < (void *)((longlong)_Src + _Size))) {
    puVar14 = (undefined4 *)((longlong)_Dst + lVar15 + (_Size - 0x10));
    uVar18 = puVar14[1];
    uVar20 = puVar14[2];
    uVar22 = puVar14[3];
    puVar12 = (undefined4 *)((longlong)_Dst + (_Size - 0x10));
    uVar16 = _Size - 0x10;
    puVar13 = puVar12;
    uVar19 = *puVar14;
    uVar21 = uVar18;
    uVar23 = uVar20;
    uVar25 = uVar22;
    if (((ulonglong)puVar12 & 0xf) != 0) {
      puVar13 = (undefined4 *)((ulonglong)puVar12 & 0xfffffffffffffff0);
      puVar1 = (undefined4 *)((longlong)puVar13 + lVar15);
      uVar19 = *puVar1;
      uVar21 = puVar1[1];
      uVar23 = puVar1[2];
      uVar25 = puVar1[3];
      *puVar12 = *puVar14;
      *(undefined4 *)((longlong)_Dst + (_Size - 0xc)) = uVar18;
      *(undefined4 *)((longlong)_Dst + (_Size - 8)) = uVar20;
      *(undefined4 *)((longlong)_Dst + (_Size - 4)) = uVar22;
      uVar16 = (longlong)puVar13 - (longlong)_Dst;
    }
    uVar17 = uVar16 >> 6;
    if (uVar17 != 0) {
      uVar16 = uVar16 & 0x3f;
      puVar14 = puVar13;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        puVar10 = (undefined8 *)((longlong)puVar14 + lVar15 + -0x10);
        uVar3 = *puVar10;
        uVar4 = puVar10[1];
        puVar10 = (undefined8 *)((longlong)puVar14 + lVar15 + -0x20);
        uVar5 = *puVar10;
        uVar6 = puVar10[1];
        puVar10 = (undefined8 *)((longlong)puVar14 + lVar15 + -0x30);
        uVar7 = *puVar10;
        uVar8 = puVar10[1];
        puVar13 = (undefined4 *)((longlong)puVar14 + lVar15 + -0x40);
        uVar19 = *puVar13;
        uVar21 = puVar13[1];
        uVar23 = puVar13[2];
        uVar25 = puVar13[3];
        *puVar14 = uVar18;
        puVar14[1] = uVar20;
        puVar14[2] = uVar22;
        puVar14[3] = uVar24;
        puVar13 = puVar14 + -0x10;
        uVar17 = uVar17 - 1;
        *(undefined8 *)(puVar14 + -4) = uVar3;
        *(undefined8 *)(puVar14 + -2) = uVar4;
        *(undefined8 *)(puVar14 + -8) = uVar5;
        *(undefined8 *)(puVar14 + -6) = uVar6;
        *(undefined8 *)(puVar14 + -0xc) = uVar7;
        *(undefined8 *)(puVar14 + -10) = uVar8;
        puVar14 = puVar13;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar17 != 0);
    }
    for (uVar17 = uVar16 >> 4; uVar17 != 0; uVar17 = uVar17 - 1) {
      *puVar13 = uVar19;
      puVar13[1] = uVar21;
      puVar13[2] = uVar23;
      puVar13[3] = uVar25;
      puVar14 = (undefined4 *)((longlong)puVar13 + lVar15 + -0x10);
      uVar19 = *puVar14;
      uVar21 = puVar14[1];
      uVar23 = puVar14[2];
      uVar25 = puVar14[3];
      puVar13 = puVar13 + -4;
    }
    if ((uVar16 & 0xf) != 0) {
      puVar10 = (undefined8 *)((longlong)puVar13 - (uVar16 & 0xf));
      uVar3 = ((undefined8 *)((longlong)puVar10 + lVar15))[1];
      *puVar10 = *(undefined8 *)((longlong)puVar10 + lVar15);
      puVar10[1] = uVar3;
    }
    *puVar13 = uVar19;
    puVar13[1] = uVar21;
    puVar13[2] = uVar23;
    puVar13[3] = uVar25;
    return _Dst;
  }
  puVar14 = (undefined4 *)((longlong)_Dst + lVar15);
  uVar18 = puVar14[1];
  uVar20 = puVar14[2];
  uVar22 = puVar14[3];
  puVar10 = (undefined8 *)((longlong)_Dst + 0x10);
  uVar19 = *puVar14;
  uVar21 = uVar18;
  uVar23 = uVar20;
  uVar25 = uVar22;
  if (((ulonglong)puVar10 & 0xf) != 0) {
    puVar13 = (undefined4 *)(((ulonglong)puVar10 & 0xfffffffffffffff0) + lVar15);
    uVar19 = *puVar13;
    uVar21 = puVar13[1];
    uVar23 = puVar13[2];
    uVar25 = puVar13[3];
    *(undefined4 *)_Dst = *puVar14;
    *(undefined4 *)((longlong)_Dst + 4) = uVar18;
    *(undefined4 *)((longlong)_Dst + 8) = uVar20;
    *(undefined4 *)((longlong)_Dst + 0xc) = uVar22;
    puVar10 = (undefined8 *)(((ulonglong)puVar10 & 0xfffffffffffffff0) + 0x10);
  }
  uVar16 = (longlong)_Dst + (_Size - (longlong)puVar10);
  uVar17 = uVar16 >> 6;
  if (uVar17 != 0) {
    if (uVar17 < 0x1001) {
      uVar16 = uVar16 & 0x3f;
      puVar11 = puVar10;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        uVar3 = *(undefined8 *)((longlong)puVar11 + lVar15);
        uVar4 = ((undefined8 *)((longlong)puVar11 + lVar15))[1];
        puVar10 = (undefined8 *)((longlong)puVar11 + lVar15 + 0x10);
        uVar5 = *puVar10;
        uVar6 = puVar10[1];
        puVar10 = (undefined8 *)((longlong)puVar11 + lVar15 + 0x20);
        uVar7 = *puVar10;
        uVar8 = puVar10[1];
        puVar14 = (undefined4 *)((longlong)puVar11 + lVar15 + 0x30);
        uVar19 = *puVar14;
        uVar21 = puVar14[1];
        uVar23 = puVar14[2];
        uVar25 = puVar14[3];
        *(undefined4 *)(puVar11 + -2) = uVar18;
        *(undefined4 *)((longlong)puVar11 + -0xc) = uVar20;
        *(undefined4 *)(puVar11 + -1) = uVar22;
        *(undefined4 *)((longlong)puVar11 + -4) = uVar24;
        puVar10 = puVar11 + 8;
        uVar17 = uVar17 - 1;
        *puVar11 = uVar3;
        puVar11[1] = uVar4;
        puVar11[2] = uVar5;
        puVar11[3] = uVar6;
        puVar11[4] = uVar7;
        puVar11[5] = uVar8;
        puVar11 = puVar10;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar17 != 0);
    }
    else {
      uVar17 = uVar16 >> 6;
      uVar16 = uVar16 & 0x3f;
      puVar11 = puVar10;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        uVar3 = *(undefined8 *)((longlong)puVar11 + lVar15);
        uVar4 = ((undefined8 *)((longlong)puVar11 + lVar15))[1];
        puVar10 = (undefined8 *)((longlong)puVar11 + lVar15 + 0x10);
        uVar5 = *puVar10;
        uVar6 = puVar10[1];
        puVar10 = (undefined8 *)((longlong)puVar11 + lVar15 + 0x20);
        uVar7 = *puVar10;
        uVar8 = puVar10[1];
        puVar14 = (undefined4 *)((longlong)puVar11 + lVar15 + 0x30);
        uVar19 = *puVar14;
        uVar21 = puVar14[1];
        uVar23 = puVar14[2];
        uVar25 = puVar14[3];
        *(undefined4 *)(puVar11 + -2) = uVar18;
        *(undefined4 *)((longlong)puVar11 + -0xc) = uVar20;
        *(undefined4 *)(puVar11 + -1) = uVar22;
        *(undefined4 *)((longlong)puVar11 + -4) = uVar24;
        puVar10 = puVar11 + 8;
        uVar17 = uVar17 - 1;
        *puVar11 = uVar3;
        puVar11[1] = uVar4;
        puVar11[2] = uVar5;
        puVar11[3] = uVar6;
        puVar11[4] = uVar7;
        puVar11[5] = uVar8;
        puVar11 = puVar10;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar17 != 0);
    }
  }
  for (uVar17 = uVar16 >> 4; uVar17 != 0; uVar17 = uVar17 - 1) {
    *(undefined4 *)(puVar10 + -2) = uVar19;
    *(undefined4 *)((longlong)puVar10 + -0xc) = uVar21;
    *(undefined4 *)(puVar10 + -1) = uVar23;
    *(undefined4 *)((longlong)puVar10 + -4) = uVar25;
    puVar14 = (undefined4 *)((longlong)puVar10 + lVar15);
    uVar19 = *puVar14;
    uVar21 = puVar14[1];
    uVar23 = puVar14[2];
    uVar25 = puVar14[3];
    puVar10 = puVar10 + 2;
  }
  if ((uVar16 & 0xf) != 0) {
    puVar11 = (undefined8 *)((longlong)puVar10 + ((uVar16 & 0xf) - 0x10));
    uVar3 = ((undefined8 *)((longlong)puVar11 + lVar15))[1];
    *puVar11 = *(undefined8 *)((longlong)puVar11 + lVar15);
    puVar11[1] = uVar3;
  }
  *(undefined4 *)(puVar10 + -2) = uVar19;
  *(undefined4 *)((longlong)puVar10 + -0xc) = uVar21;
  *(undefined4 *)(puVar10 + -1) = uVar23;
  *(undefined4 *)((longlong)puVar10 + -4) = uVar25;
  return _Dst;
}



===== memset @ 140009e80 =====

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



===== __memset_repmovs @ 140009fc0 =====

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



===== __memset_query @ 14000a040 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000a0c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000a200 =====

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



===== __memset_spec_plain @ 14000a280 =====

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



===== WppCleanupKm @ 140011008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0x10)) {
        if (*(longlong *)(puVar1 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar1 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 1400110b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0x38) = 0;
        (*pcVar1)(*(undefined8 *)(puVar2 + 8),0,WppClassicProviderCallback,puVar2,puVar2 + 0x38);
        puVar2 = *(undefined **)(puVar2 + 0x10);
      } while (puVar2 != (undefined *)0x0);
    }
    else if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 140011194 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_18);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 1400112e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  uint *puVar1;
  undefined8 uVar2;
  ushort *puVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar1 = param_6;
  *param_6 = 0;
  if (param_1 < 6) {
    if ((param_1 == 5) ||
       ((((param_1 != 0 && (param_1 != 1)) && (param_1 != 2)) && ((param_1 != 3 && (param_1 == 4))))
       )) {
      local_res8[0] = 0;
      param_6._0_4_ = 0;
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          puVar1 = *(uint **)(param_5 + 8);
          if (((*puVar1 == param_4[6]) && (puVar1[1] == param_4[7])) &&
             ((puVar1[2] == param_4[8] && (puVar1[3] == param_4[9])))) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
            *(undefined1 *)(param_5 + 0x29) = 0;
            return 0;
          }
          bVar13 = WPPTraceSuite != 2;
          uVar2 = *(undefined8 *)(param_4 + 2);
          *(undefined8 *)(param_5 + 0x18) = uVar2;
          if (bVar13) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = uStack_36;
            return 0;
          }
          iVar5 = (*pfnWppQueryTraceInformation)(3,local_res8,4,&param_6,param_4);
          if (iVar5 == 0) {
            *(undefined1 *)(param_5 + 0x29) = (undefined1)local_res8[0];
          }
          uVar6 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
  }
  else {
    if (param_1 == 6) {
      return 0;
    }
    if (param_1 == 7) {
      return 0;
    }
    if (param_1 == 8) {
      uVar10 = 0;
      puVar3 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar10) {
        return 0xc000000d;
      }
      uVar11 = uVar10 * 0x20 + 0x18;
      if (puVar3 == (ushort *)0x0) {
        uVar12 = uVar11;
        uVar11 = 0;
      }
      else {
        uVar12 = *puVar3 + 2 + uVar11;
      }
      if (param_3 < uVar12) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar12;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar12;
      param_4[2] = uVar11;
      param_4[4] = uVar10;
      if (puVar3 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar3;
        memcpy((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
               (ulonglong)*puVar3);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar9 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar4 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar2;
          *(undefined8 *)(puVar9 + -2) = uVar4;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar8 != 0);
      }
      *puVar1 = uVar12;
      return 0;
    }
  }
  return 0xc0000010;
}



===== DispatchDeviceReset @ 140011568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DispatchDeviceReset(longlong param_1)

{
  (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 8),1,0);
  return;
}



===== QueryDeviceResetInterface @ 1400115a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int QueryDeviceResetInterface(undefined8 param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_178 [48];
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 local_118;
  undefined4 local_114;
  undefined8 local_f8;
  undefined2 local_88 [4];
  undefined *local_80;
  undefined4 local_78;
  undefined4 *local_70;
  undefined8 local_68;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_178;
  local_140 = 0;
  uStack_128 = 0;
  uStack_124 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_138 = 0;
  uStack_130 = 0;
  uStack_12c = 0;
  memset(local_88,0,0x48);
  memset(&local_118,0,0x88);
  local_148 = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
  uVar3 = IoGetAttachedDeviceReference(uVar3);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_1,0,&local_140);
  if (-1 < iVar2) {
    local_118 = 0x88;
    local_114 = 1;
    local_f8 = uVar3;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_140,&local_118);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,0,local_140,&local_148);
      if (-1 < iVar2) {
        uStack_12c = 0;
        uStack_128 = 0;
        uStack_124 = 0;
        local_138 = 0x18;
        uStack_130 = 0xc00000bb;
        (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,local_148,&local_138);
        memset(param_2,0,0x50);
        local_68 = 0;
        *param_2 = 0x10050;
        local_80 = &GUID_DEVICE_RESET_INTERFACE_STANDARD;
        local_88[0] = 0x81b;
        local_78 = 0x10050;
        local_70 = param_2;
        (**(code **)(WdfFunctions_01015 + 0x7e0))(WdfDriverGlobals,local_148,local_88);
        uStack_38 = 0;
        local_40 = 0x200000010;
        cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                          (WdfDriverGlobals,local_148,local_140,&local_40);
        if (cVar1 == '\0') {
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,local_148);
        }
      }
    }
  }
  ObfDereferenceObject(uVar3);
  return iVar2;
}



===== __security_init_cookie @ 140012008 =====

/* WARNING: Control flow encountered bad instruction data */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  byte *pbVar4;
  char in_DL;
  char unaff_BL;
  char *unaff_RSI;
  
  if ((__security_cookie != 0) && (__security_cookie != 0x2b992ddfa232)) {
    __security_cookie_complement = ~__security_cookie;
    return;
  }
  pcVar2 = (code *)swi(0x29);
  pbVar4 = (byte *)(*pcVar2)(6);
  bVar3 = (byte)pbVar4;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + bVar3;
  bVar1 = *pbVar4;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + in_DL + CARRY1(bVar1,bVar3);
  bVar1 = *pbVar4;
  *pbVar4 = *pbVar4 + bVar3;
  if (SCARRY1(bVar1,bVar3)) {
    *pbVar4 = *pbVar4 + bVar3;
    *unaff_RSI = *unaff_RSI + unaff_BL;
    *pbVar4 = *pbVar4 + bVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *pbVar4 = *pbVar4 + bVar3;
  *unaff_RSI = *unaff_RSI;
  *pbVar4 = *pbVar4 + in_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


