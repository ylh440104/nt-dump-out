
===== __report_gsfailure @ 1c0001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== RtlUnicodeStringPrintf @ 1c0001020 =====

/* long __cdecl RtlUnicodeStringPrintf(struct _UNICODE_STRING * __ptr64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlUnicodeStringPrintf(_UNICODE_STRING *param_1,ushort *param_2,...)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  long lVar5;
  ulonglong _Count;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = param_1->Length;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1->MaximumLength, (uVar2 & 1) == 0)) &&
       (uVar1 <= uVar2)) && (uVar2 != 0xffff)) &&
     ((lVar5 = 0, param_1->Buffer != (wchar_t *)0x0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1->MaximumLength >> 1);
    local_res18 = in_R8;
    local_res20 = in_R9;
    iVar3 = _vsnwprintf(param_1->Buffer,_Count,(wchar_t *)param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      lVar5 = -0x7ffffffb;
      uVar4 = _Count;
    }
    param_1->Length = (short)uVar4 * 2;
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  return lVar5;
}



===== DriverEntry @ 1c00010c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined1 auStackY_1d8 [32];
  longlong local_198;
  _UNICODE_STRING local_190;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  code *local_168;
  undefined4 local_160;
  undefined4 local_15c;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  wchar_t local_118 [104];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_190.Length = 0;
  local_190.MaximumLength = 200;
  local_190._4_4_ = 0;
  local_190.Buffer = local_118;
  local_180 = 0;
  _WPP_MAIN_CB = 0;
  DAT_1c0011218 = &WPP_ThisDir_CTLGUID_URSCX;
  _DAT_1c0011238 = 1;
  DAT_1c0011220 = 0;
  _DAT_1c0011230 = 0;
  DAT_1c0011250 = 0;
  _DAT_1c0011258 = 0;
  WppLoadTracingSupport();
  _DAT_1c0011230 = 0;
  uVar2 = param_2;
  WppInitKm(param_1,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,1,10,
                     &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
  }
  local_198 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                      &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids,(char)param_1);
  }
  local_178 = 0x20;
  local_128 = 0;
  local_148 = 0;
  local_168 = Driver_EvtDriverUnload;
  uStack_150 = 0;
  local_158 = 0x38;
  local_138 = 0;
  uStack_130 = 0;
  uStack_140 = 0x100000001;
  local_170 = 0;
  local_160 = 1;
  local_15c = 0x58737255;
  iVar1 = (**(code **)(WdfFunctions_01021 + 0x3a0))(WdfDriverGlobals,param_1,param_2,&local_158);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001452;
    uVar5 = 0xc;
  }
  else {
    local_198 = (**(code **)(WdfFunctions_01021 + 200))
                          (WdfDriverGlobals,*WdfDriverGlobals,&SDDL_DEVOBJ_KERNEL_ONLY);
    if (local_198 == 0) {
      iVar1 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001452;
      uVar5 = 0xd;
      iVar1 = -0x3fffff66;
    }
    else {
      uVar4 = 0;
      do {
        iVar1 = RtlUnicodeStringPrintf
                          (&local_190,(ushort *)L"%s%u",L"\\Device\\UrsCx",(ulonglong)uVar4);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0001452;
          uVar5 = 0xe;
          goto LAB_1c0001270;
        }
        iVar1 = (**(code **)(WdfFunctions_01021 + 0x218))(WdfDriverGlobals,local_198,&local_190);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0001452;
          uVar5 = 0xf;
          goto LAB_1c0001270;
        }
        iVar1 = (**(code **)(WdfFunctions_01021 + 600))
                          (WdfDriverGlobals,&local_198,0,&g_ClassLibraryDevice);
        uVar4 = uVar4 + 1;
      } while (iVar1 == -0x3fffffcb);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001452;
        uVar5 = 0x10;
      }
      else {
        (**(code **)(WdfFunctions_01021 + 0xd8))(WdfDriverGlobals,g_ClassLibraryDevice);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        iVar1 = WdfRegisterClassLibrary(&g_WdfClassLibraryInfo,param_2,&local_190);
        if ((-1 < iVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
        goto LAB_1c0001452;
        uVar5 = 0x12;
      }
    }
  }
LAB_1c0001270:
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar5,
                     &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids,(char)param_1,(char)iVar1);
LAB_1c0001452:
  lVar3 = local_198;
  if (local_198 != 0) {
    (**(code **)(WdfFunctions_01021 + 0x1b0))(WdfDriverGlobals);
    local_198 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,1,0x13,
                     &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
  }
  if (iVar1 < 0) {
    if (g_ClassLibraryDevice != (WDFDEVICE__ *)0x0) {
      (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
      g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
    }
    WppCleanupKm(param_1);
  }
  return iVar1;
}



===== Driver_CxBindClient @ 1c0001520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 Driver_CxBindClient(longlong param_1,undefined8 param_2)

{
  void *_Dst;
  undefined1 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined **ppuVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0x1b,
                     &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
  }
  uVar5 = *WdfDriverGlobals;
  uVar1 = (**(code **)(WdfFunctions_01021 + 0x3b0))(WdfDriverGlobals,uVar5);
  uVar2 = *(uint *)(param_1 + 0x10);
  if (uVar2 == DAT_1c0011004) {
    uVar2 = *(uint *)(param_1 + 0x14);
    if (DAT_1c0011008 < uVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar8 = 0x1d;
      uVar4 = DAT_1c0011008;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x28);
      if (uVar2 == DAT_1c0011034) {
        uVar5 = 0;
        puVar3 = (undefined4 *)ExAllocatePool2(0x40,8,0x58737255);
        if (puVar3 == (undefined4 *)0x0) {
          uVar7 = 0xc000009a;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000009a;
          }
          ppuVar6 = (undefined **)CONCAT71((int7)((ulonglong)uVar5 >> 8),2);
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1f,
                            &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids,uVar1);
        }
        else {
          uVar2 = *(uint *)(param_1 + 0x28);
          ppuVar6 = &PTR_imp_UrsDeviceInitialize_1c0011038;
          _Dst = *(void **)(param_1 + 0x20);
          *puVar3 = 0x6c476c43;
          memmove(_Dst,&PTR_imp_UrsDeviceInitialize_1c0011038,(ulonglong)uVar2 << 3);
          uVar7 = 0;
          **(undefined8 **)(param_1 + 0x30) = puVar3 + 1;
        }
        goto LAB_1c00016c2;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar8 = 0x1e;
      uVar4 = DAT_1c0011034;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar8 = 0x1c;
    uVar4 = DAT_1c0011004;
  }
  uVar7 = 0xc000000d;
  ppuVar6 = (undefined **)CONCAT71((int7)((ulonglong)uVar5 >> 8),2);
  WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar8,
                      &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids,uVar1,(char)uVar2,(char)uVar4
                     );
LAB_1c00016c2:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),ppuVar6,1,0x20,
                     &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
  }
  return uVar7;
}



===== Driver_CxDeinitialize @ 1c0001720 =====

void Driver_CxDeinitialize(undefined8 param_1,undefined8 param_2)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0x19,
                       &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0x1a,
                       &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
    }
  }
  return;
}



===== Driver_CxInitialize @ 1c00017b0 =====

undefined8 Driver_CxInitialize(undefined8 param_1,undefined8 param_2)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0x17,
                       &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0x18,
                       &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
    }
  }
  return 0;
}



===== Driver_CxUnbindClient @ 1c0001840 =====

void Driver_CxUnbindClient(longlong param_1,undefined8 param_2)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0x21,
                     &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
  }
  if (**(longlong **)(param_1 + 0x30) != 0) {
    param_2 = 0x58737255;
    ExFreePoolWithTag(**(longlong **)(param_1 + 0x30) + -4);
    **(undefined8 **)(param_1 + 0x30) = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0x22,
                     &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
  }
  return;
}



===== Driver_EvtDriverUnload @ 1c0001910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Driver_EvtDriverUnload(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  WDFDEVICE__ *pWVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0x14,
                     &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01021 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x15,
                      &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids,(char)uVar1);
  }
  pWVar2 = g_ClassLibraryDevice;
  (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
  g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,1,0x16,
                     &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids);
  }
  WppCleanupKm(uVar1);
  return;
}



===== WPP_RECORDER_SF_ @ 1c0001a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,5,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 1c0001af4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qLL @ 1c0001bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qZ @ 1c0001d40 =====

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
  goto LAB_1c0001e08;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_1c0001db1:
    pwVar4 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 == L'\0') goto LAB_1c0001db1;
    pwVar4 = *(wchar_t **)(in_stack_00000038 + 4);
  }
  pwVar2 = in_stack_00000038;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids,0x11,&uStack0000000000000030,8,pwVar2,
             2,pwVar4,wVar1,0);
LAB_1c0001e08:
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
  WppAutoLogTrace(param_1,4,1,&WPP_03a89493e5313f2eb41104dffbd046ee_Traceguids,0x11,
                  &uStack0000000000000030,8,in_stack_00000038,2,pwVar3,wVar1,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 1c0001ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001fd0 =====

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



===== UrsCx_ValidateConfig @ 1c000202c =====

/* long __cdecl UrsCx_ValidateConfig(struct WDFDEVICE__ * __ptr64,struct _URS_CONFIG * __ptr64) */

long __cdecl UrsCx_ValidateConfig(WDFDEVICE__ *param_1,_URS_CONFIG *param_2)

{
  char *pcVar1;
  undefined3 uVar4;
  undefined4 uVar2;
  _URS_CONFIG *p_Var3;
  undefined4 uVar5;
  long lVar6;
  
  p_Var3 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,2,0x14,
                     &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  uVar5 = (undefined4)((ulonglong)p_Var3 >> 0x20);
  uVar4 = (undefined3)((ulonglong)p_Var3 >> 8);
  if (param_2->Size == 0x18) {
    if (param_2->EvtUrsFilterRemoveResourceRequirements !=
        (_func___cdecl_long_WDFDEVICE___ptr_WDFIORESREQLIST___ptr_URSIORESLIST___ptr_URSIORESLIST___ptr
         *)0x0) {
      lVar6 = 0;
      goto LAB_1c0002122;
    }
    lVar6 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = CONCAT31(uVar4,2);
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x16,
                        &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids,(char)param_1);
      p_Var3 = (_URS_CONFIG *)CONCAT44(uVar5,uVar2);
    }
    pcVar1 = "EvtUrsFilterRemoveResourceRequirements is a required callback";
  }
  else {
    lVar6 = -0x3ffffffc;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = CONCAT31(uVar4,2);
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x15,
                          &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids,(char)param_1,
                          (char)param_2->Size,0x18);
      p_Var3 = (_URS_CONFIG *)CONCAT44(uVar5,uVar2);
    }
    pcVar1 = "Unexpected size for URS_CONFIG";
  }
  Verifier_DbgBreak(pcVar1,(ulong)p_Var3);
LAB_1c0002122:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var3,2,0x17,
                     &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  return lVar6;
}



===== imp_UrsDeviceInitInitialize @ 1c0002180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl imp_UrsDeviceInitInitialize(struct _URS_DRIVER_GLOBALS * __ptr64,struct
   WDFDEVICE_INIT * __ptr64) */

long __cdecl imp_UrsDeviceInitInitialize(_URS_DRIVER_GLOBALS *param_1,WDFDEVICE_INIT *param_2)

{
  long lVar1;
  longlong lVar2;
  undefined4 *_Dst;
  undefined8 uVar3;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  code *local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8 [12];
  code *local_b8;
  
  uVar3 = 0;
  _Dst = local_e8;
  local_108 = 0;
  uStack_104 = 0;
  uStack_100 = 0;
  uStack_fc = 0;
  local_f8 = (code *)0x0;
  uStack_f0 = 0;
  memset(_Dst,0,200);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (_Dst = (undefined4 *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Dst = *(undefined4 **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(_Dst,uVar3,2,0xc,&WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  lVar1 = Verifier_VerifyIrqlEquals((uchar)_Dst);
  if ((-1 < lVar1) && (lVar1 = Verifier_VerifyDriverGlobals(param_1), -1 < lVar1)) {
    (**(code **)(WdfFunctions_01021 + 0x210))(WdfDriverGlobals,param_2,0x2a);
    local_f8 = Fdo_EvtDeviceFilterRemoveResourceRequirements;
    uStack_104 = 0;
    uStack_100 = 0;
    uStack_fc = 0;
    uStack_f0 = 0;
    local_108 = 0x20;
    (**(code **)(WdfFunctions_01021 + 0x400))(WdfDriverGlobals,param_2,&local_108);
    lVar2 = (**(code **)(WdfFunctions_01021 + 0xc60))(WdfDriverGlobals,param_2);
    if (lVar2 == 0) {
      uVar3 = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar3 = 2;
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xd,
                          &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids,(char)param_2);
      }
      lVar1 = -0x3fffff66;
    }
    else {
      local_b8 = Fdo_EvtWdfCxDevicePreD0Entry;
      local_e8[0] = 200;
      (**(code **)(WdfFunctions_01021 + 0xde8))(WdfDriverGlobals,lVar2,local_e8);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return lVar1;
      }
      uVar3 = CONCAT71((int7)((ulonglong)lVar2 >> 8),4);
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xe,
                        &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids,(char)param_2);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,2,0xf,
                     &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  return lVar1;
}



===== imp_UrsDeviceInitialize @ 1c00023b0 =====

/* long __cdecl imp_UrsDeviceInitialize(struct _URS_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__ *
   __ptr64,struct _URS_CONFIG * __ptr64) */

long __cdecl
imp_UrsDeviceInitialize(_URS_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,_URS_CONFIG *param_3)

{
  long lVar1;
  _URS_DRIVER_GLOBALS *p_Var2;
  _URS_CONFIG *p_Var3;
  
  p_Var2 = param_1;
  p_Var3 = (_URS_CONFIG *)param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (p_Var2 = (_URS_DRIVER_GLOBALS *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0
     )) {
    p_Var2 = *(_URS_DRIVER_GLOBALS **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(p_Var2,param_2,2,10,&WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  lVar1 = Verifier_VerifyIrqlEquals((uchar)p_Var2);
  if (-1 < lVar1) {
    lVar1 = Verifier_VerifyDriverGlobals(param_1);
    if (-1 < lVar1) {
      p_Var3 = param_3;
      lVar1 = UrsCx_ValidateConfig(param_2,param_3);
      if (-1 < lVar1) {
        lVar1 = Fdo_Initialize(param_2,param_3);
        p_Var3 = param_3;
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var3,2,0xb,
                     &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  return lVar1;
}



===== imp_UrsSetHardwareEventSupport @ 1c00024b0 =====

/* void __cdecl imp_UrsSetHardwareEventSupport(struct _URS_DRIVER_GLOBALS * __ptr64,struct
   WDFDEVICE__ * __ptr64,unsigned char) */

void __cdecl
imp_UrsSetHardwareEventSupport(_URS_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,uchar param_3)

{
  long lVar1;
  _URS_DRIVER_GLOBALS *p_Var2;
  uchar uVar3;
  undefined7 uVar4;
  
  uVar3 = (uchar)param_2;
  uVar4 = (undefined7)((ulonglong)param_2 >> 8);
  p_Var2 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (p_Var2 = (_URS_DRIVER_GLOBALS *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0
     )) {
    p_Var2 = *(_URS_DRIVER_GLOBALS **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(p_Var2,param_2,2,0x12,&WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  lVar1 = Verifier_VerifyIrqlEquals((uchar)p_Var2);
  if (-1 < lVar1) {
    lVar1 = Verifier_VerifyDriverGlobals(param_1);
    if (-1 < lVar1) {
      Fdo_SetHardwareEventSupport(param_2,param_3);
      uVar3 = param_3;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(uVar4,uVar3),2,0x13,
                     &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  return;
}



===== imp_UrsSetPoHandle @ 1c0002580 =====

/* void __cdecl imp_UrsSetPoHandle(struct _URS_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__ *
   __ptr64,struct POHANDLE__ * __ptr64) */

void __cdecl
imp_UrsSetPoHandle(_URS_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,POHANDLE__ *param_3)

{
  long lVar1;
  _URS_DRIVER_GLOBALS *p_Var2;
  WDFDEVICE__ *pWVar3;
  
  p_Var2 = param_1;
  pWVar3 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (p_Var2 = (_URS_DRIVER_GLOBALS *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0
     )) {
    p_Var2 = *(_URS_DRIVER_GLOBALS **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(p_Var2,param_2,2,0x10,&WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  lVar1 = Verifier_VerifyIrqlEquals((uchar)p_Var2);
  if (-1 < lVar1) {
    lVar1 = Verifier_VerifyDriverGlobals(param_1);
    if (-1 < lVar1) {
      Fdo_SetPoHandle(param_2,param_3);
      pWVar3 = (WDFDEVICE__ *)param_3;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,2,0x11,
                     &WPP_5898f2effea1398a3af748bf2ff73240_Traceguids);
  }
  return;
}



===== Verifier_DbgBreak @ 1c000264c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Verifier_DbgBreak(char const * __ptr64,unsigned long) */

void __cdecl Verifier_DbgBreak(char *param_1,ulong param_2)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  DbgPrint("UrsCx Verifier Break: %s\n",param_1);
  (**(code **)(WdfFunctions_01021 + 0xb78))(WdfDriverGlobals);
  return;
}



===== Verifier_VerifyDriverGlobals @ 1c00026b8 =====

/* long __cdecl Verifier_VerifyDriverGlobals(struct _URS_DRIVER_GLOBALS * __ptr64) */

long __cdecl Verifier_VerifyDriverGlobals(_URS_DRIVER_GLOBALS *param_1)

{
  ulong in_EDX;
  long lVar1;
  
  lVar1 = 0;
  if ((param_1 + -1 == (_URS_DRIVER_GLOBALS *)0x0) || (param_1[-1].Reserved != 0x6c476c43)) {
    lVar1 = -0x3ffffff0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_EDX = CONCAT31((int3)(in_EDX >> 8),2);
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0xb,
                        &WPP_8e592c1081873b447a5e32ae7fe91d72_Traceguids,(char)param_1);
    }
    Verifier_DbgBreak("Driver globals are invalid",in_EDX);
  }
  return lVar1;
}



===== Verifier_VerifyIrqlEquals @ 1c0002730 =====

/* long __cdecl Verifier_VerifyIrqlEquals(unsigned char) */

long __cdecl Verifier_VerifyIrqlEquals(uchar param_1)

{
  char cVar1;
  undefined7 in_register_00000009;
  ulong in_EDX;
  long lVar2;
  
  cVar1 = KeGetCurrentIrql(CONCAT71(in_register_00000009,param_1));
  lVar2 = 0;
  if (cVar1 != '\0') {
    lVar2 = -0x3ffffff0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    Verifier_DbgBreak("API called at incorrect IRQL",in_EDX);
  }
  return lVar2;
}



===== WPP_RECORDER_SF_DD @ 1c0002790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined4 local_18 [4];
  
  local_18[0] = 0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8e592c1081873b447a5e32ae7fe91d72_Traceguids,0xc,local_18,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_8e592c1081873b447a5e32ae7fe91d72_Traceguids,0xc,local_18,4,
                  &uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_s @ 1c0002864 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *in_stack_00000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000030[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8e592c1081873b447a5e32ae7fe91d72_Traceguids,10,pcVar3,lVar2,0);
  }
  lVar2 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000030[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,2,3,&WPP_8e592c1081873b447a5e32ae7fe91d72_Traceguids,10,in_stack_00000030,
                  lVar1,0);
  return;
}



===== IoResList_Create @ 1c000297c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl IoResList_Create(struct _WDF_OBJECT_ATTRIBUTES * __ptr64,struct URSIORESLIST__ *
   __ptr64 * __ptr64) */

long __cdecl IoResList_Create(_WDF_OBJECT_ATTRIBUTES *param_1,URSIORESLIST__ **param_2)

{
  int iVar1;
  URSIORESLIST__ *local_res18 [2];
  
  local_res18[0] = (URSIORESLIST__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0xf,
                     &WPP_aba52b8ebd813458243f2b2003353bdb_Traceguids);
  }
  iVar1 = (**(code **)(WdfFunctions_01021 + 0x68))(WdfDriverGlobals,param_1,local_res18);
  if (-1 < iVar1) {
    *param_2 = local_res18[0];
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,4,0x10,
                     &WPP_aba52b8ebd813458243f2b2003353bdb_Traceguids);
  }
  return iVar1;
}



===== IoResList_Purge @ 1c0002a4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl IoResList_Purge(struct URSIORESLIST__ * __ptr64) */

void __cdecl IoResList_Purge(URSIORESLIST__ *param_1)

{
  longlong lVar1;
  
  while( true ) {
    lVar1 = (**(code **)(WdfFunctions_01021 + 0x98))(WdfDriverGlobals,param_1);
    if (lVar1 == 0) break;
    (**(code **)(WdfFunctions_01021 + 0x80))(WdfDriverGlobals,param_1,lVar1);
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals,lVar1);
  }
  return;
}



===== imp_UrsIoResourceListAppendDescriptor @ 1c0002ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl imp_UrsIoResourceListAppendDescriptor(struct _URS_DRIVER_GLOBALS * __ptr64,struct
   URSIORESLIST__ * __ptr64,struct _IO_RESOURCE_DESCRIPTOR * __ptr64) */

long __cdecl
imp_UrsIoResourceListAppendDescriptor
          (_URS_DRIVER_GLOBALS *param_1,URSIORESLIST__ *param_2,_IO_RESOURCE_DESCRIPTOR *param_3)

{
  long lVar1;
  _URS_DRIVER_GLOBALS *p_Var2;
  longlong lVar3;
  undefined2 uVar4;
  longlong local_res20;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  URSIORESLIST__ *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_68 = 0;
  uStack_60 = 0;
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (URSIORESLIST__ *)0x0;
  uStack_40 = 0;
  p_Var2 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (p_Var2 = (_URS_DRIVER_GLOBALS *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0
     )) {
    p_Var2 = *(_URS_DRIVER_GLOBALS **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(p_Var2,param_2,4,10,&WPP_aba52b8ebd813458243f2b2003353bdb_Traceguids);
  }
  local_res20 = 0;
  lVar1 = Verifier_VerifyIrqlEquals((uchar)p_Var2);
  if ((lVar1 < 0) || (lVar1 = Verifier_VerifyDriverGlobals(param_1), lVar1 < 0)) goto LAB_1c0002c93;
  local_68 = CONCAT44(local_68._4_4_,0x38);
  uStack_50 = 0x100000001;
  local_48 = param_2;
  lVar1 = (**(code **)(WdfFunctions_01021 + 0x600))
                    (WdfDriverGlobals,&local_68,1,0x58737255,0x20,&local_res20,0);
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002c93;
    uVar4 = 0xb;
  }
  else {
    lVar1 = (**(code **)(WdfFunctions_01021 + 0x628))(WdfDriverGlobals,local_res20,0,param_3,0x20);
    if (lVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002c93;
      uVar4 = 0xc;
    }
    else {
      lVar1 = (**(code **)(WdfFunctions_01021 + 0x78))(WdfDriverGlobals,param_2,local_res20);
      if (-1 < lVar1) {
        local_res20 = 0;
        goto LAB_1c0002c93;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002c93;
      uVar4 = 0xd;
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,uVar4,
                     &WPP_aba52b8ebd813458243f2b2003353bdb_Traceguids,(char)param_2,(char)lVar1);
LAB_1c0002c93:
  lVar3 = local_res20;
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,4,0xe,
                     &WPP_aba52b8ebd813458243f2b2003353bdb_Traceguids);
  }
  return lVar1;
}



===== Fdo_EvtDeviceFilterRemoveResourceRequirements @ 1c0002d10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Fdo_EvtDeviceFilterRemoveResourceRequirements(struct WDFDEVICE__ * __ptr64,struct
   WDFIORESREQLIST__ * __ptr64) */

long __cdecl
Fdo_EvtDeviceFilterRemoveResourceRequirements(WDFDEVICE__ *param_1,WDFIORESREQLIST__ *param_2)

{
  URSIORESLIST__ *pUVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  URSIORESLIST__ *pUVar6;
  URSIORESLIST__ *pUVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,5,0x47,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  lVar5 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8);
  pUVar1 = *(URSIORESLIST__ **)(lVar5 + 0x28);
  pUVar7 = *(URSIORESLIST__ **)(lVar5 + 0x30);
  IoResList_Purge(pUVar1);
  pUVar6 = pUVar7;
  IoResList_Purge(pUVar7);
  Fdo_TransformResourceRequirements((WDFDEVICE__ *)pUVar6,param_2);
  iVar4 = (**(code **)(lVar5 + 0x18))(param_1,param_2,pUVar1,pUVar7);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_2 = (WDFIORESREQLIST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),2);
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x48,
                         &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,(char)param_1,(char)iVar4)
      ;
    }
    IoResList_Purge(pUVar1);
    IoResList_Purge(pUVar7);
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01021 + 0x70))(WdfDriverGlobals,pUVar1);
    uVar3 = (**(code **)(WdfFunctions_01021 + 0x70))(WdfDriverGlobals,pUVar7);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar4;
    }
    param_2 = (WDFIORESREQLIST__ *)CONCAT71((int7)((ulonglong)pUVar7 >> 8),4);
    WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x49,
                        &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,(char)param_1,uVar2,uVar3);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,5,0x4a,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return iVar4;
}



===== Fdo_EvtIoDeviceControl @ 1c0002ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Fdo_EvtIoDeviceControl(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
Fdo_EvtIoDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  _URS_ROLE _Var1;
  uint uVar2;
  _URS_ROLE_SWITCH_MODE _Var3;
  undefined8 uVar4;
  _FDO_CONTEXT *p_Var5;
  longlong lVar6;
  undefined8 *puVar7;
  uint uVar8;
  WDFREQUEST__ *pWVar9;
  _URS_HARDWARE_EVENT _Var10;
  ulonglong uVar11;
  undefined2 uVar12;
  longlong lVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  _URS_ROLE_SWITCH_MODE _Var16;
  uint *local_58;
  _URS_ROLE_SWITCH_MODE *local_50;
  _URS_HARDWARE_EVENT *local_48;
  _URS_ROLE *local_40;
  ulonglong local_38;
  
  local_50 = (_URS_ROLE_SWITCH_MODE *)0x0;
  local_40 = (_URS_ROLE *)0x0;
  local_48 = (_URS_HARDWARE_EVENT *)0x0;
  local_58 = (uint *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,5,10,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  uVar4 = (**(code **)(WdfFunctions_01021 + 0x4e8))(WdfDriverGlobals,param_1);
  p_Var5 = (_FDO_CONTEXT *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,uVar4,PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8);
  pWVar9 = (WDFREQUEST__ *)0x2a0008;
  uVar14 = (undefined1)uVar4;
  uVar15 = SUB81(param_2,0);
  if (param_5 == 0x2a0008) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x2a0008,5,0xb,
                          &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,uVar15,8);
    }
    if (param_3 != 4) {
      _Var3 = 0xc0000004;
      _Var16 = 0xc0000004;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar12 = 0xc;
        uVar15 = 4;
LAB_1c00031c9:
        WPP_RECORDER_SF_qPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar9,5,uVar12,
                            &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,(char)param_3,
                            uVar15);
        goto LAB_1c0003794;
      }
      goto LAB_1c000378b;
    }
    _Var3 = (**(code **)(WdfFunctions_01021 + 0x870))(WdfDriverGlobals,param_2,4,&local_50,0);
    if (-1 < (int)_Var3) {
      RoleMgr_GetRoleSwitchMode(p_Var5,local_50);
LAB_1c0003750:
      uVar11 = 4;
LAB_1c0003753:
      (**(code **)(WdfFunctions_01021 + 0x898))(WdfDriverGlobals,param_2,uVar11);
LAB_1c0003777:
      _Var3 = 0;
      goto LAB_1c0003794;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003794;
    uVar12 = 0xd;
LAB_1c000311d:
    _Var16 = _Var3;
LAB_1c0003121:
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar12,
                       &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,(char)_Var16);
    goto LAB_1c0003794;
  }
  if (param_5 == 0x2a000c) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x2a0008,5,0xe,
                          &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,uVar15,0xc);
    }
    if (param_4 == 4) {
      _Var3 = (**(code **)(WdfFunctions_01021 + 0x868))(WdfDriverGlobals,param_2,4,&local_50,0);
      if ((int)_Var3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003794;
        uVar12 = 0x10;
        goto LAB_1c000311d;
      }
      _Var16 = *local_50;
      if (((_Var16 == 5) || (_Var16 - 1 < 4)) || (_Var16 == 6)) {
        RoleMgr_SetRoleSwitchMode(p_Var5,_Var16);
        goto LAB_1c0003777;
      }
      _Var3 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003794;
      uVar12 = 0x11;
      _Var3 = 0xc000000d;
      goto LAB_1c0003121;
    }
    _Var3 = 0xc0000004;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003794;
    uVar12 = 0xf;
LAB_1c0003375:
    _Var3 = 0xc0000004;
    uVar15 = 4;
    param_3 = param_4;
  }
  else {
    if (param_5 == 0x2a0010) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x2a0008,5,0x12,
                            &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,uVar15,0x10);
      }
      if (param_3 == 4) {
        _Var3 = (**(code **)(WdfFunctions_01021 + 0x870))(WdfDriverGlobals,param_2,4,&local_40,0);
        if (-1 < (int)_Var3) {
          (**(code **)(WdfFunctions_01021 + 0x9c8))(WdfDriverGlobals,p_Var5->RoleChangeLock,0);
          _Var1 = p_Var5->CurrentRole;
          (**(code **)(WdfFunctions_01021 + 0x9d0))(WdfDriverGlobals,p_Var5->RoleChangeLock);
          *local_40 = _Var1;
          goto LAB_1c0003750;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003794;
        uVar12 = 0x14;
        goto LAB_1c000311d;
      }
      _Var3 = 0xc0000004;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003794;
      uVar12 = 0x13;
      goto LAB_1c0003375;
    }
    if (param_5 == 0x2a0014) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x2a0008,5,0x15,
                            &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,uVar15,0x14);
      }
      if (p_Var5->HardwareEventReportingSupported != WdfFalse) {
        _Var3 = 0xc0000010;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x16,
                            &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14);
        }
        goto LAB_1c0003794;
      }
      if (param_4 == 4) {
        _Var3 = (**(code **)(WdfFunctions_01021 + 0x868))(WdfDriverGlobals,param_2,4,&local_48,0);
        if ((int)_Var3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0003794;
          uVar12 = 0x18;
        }
        else {
          _Var10 = *local_48;
          if ((_Var10 == UrsHardwareEventPortTypeUfp) &&
             (p_Var5->DynamicHostOnlyModeEnabled != '\0')) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x19,
                                &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14);
            }
            _Var10 = UrsHardwareEventDetach;
            *local_48 = UrsHardwareEventDetach;
          }
          _Var3 = RoleMgr_ReportHardwareEvent(p_Var5,_Var10);
          if (-1 < (int)_Var3) goto LAB_1c0003777;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0003794;
          uVar12 = 0x1a;
        }
        goto LAB_1c000311d;
      }
      _Var3 = 0xc0000004;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003794;
      uVar12 = 0x17;
      goto LAB_1c0003375;
    }
    if (param_5 != 0x2a001c) {
      _Var3 = 0xc0000010;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x20,
                           &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,(char)param_5);
      }
      goto LAB_1c0003794;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x2a0008,5,0x1b,
                          &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,uVar15,0x1c);
    }
    if (0xf < param_3) {
      _Var3 = (**(code **)(WdfFunctions_01021 + 0x870))
                        (WdfDriverGlobals,param_2,param_3,&local_58,0);
      if ((int)_Var3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003794;
        uVar12 = 0x1d;
        goto LAB_1c000311d;
      }
      uVar2 = (**(code **)(WdfFunctions_01021 + 0x70))(WdfDriverGlobals,p_Var5->ConnectorIds);
      uVar8 = uVar2 * 8 + 8;
      local_38 = (ulonglong)uVar8;
      *local_58 = uVar8;
      if (local_38 <= param_3) {
        uVar8 = 0;
        if (uVar2 != 0) {
          lVar13 = 0;
          do {
            lVar6 = (**(code **)(WdfFunctions_01021 + 0x90))
                              (WdfDriverGlobals,p_Var5->ConnectorIds,uVar8);
            if (lVar6 == 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1f,
                                   &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,
                                   (char)uVar8);
              }
              _Var3 = 0xc0000001;
              goto LAB_1c0003794;
            }
            puVar7 = (undefined8 *)
                     (**(code **)(WdfFunctions_01021 + 0x610))(WdfDriverGlobals,lVar6,0);
            uVar8 = uVar8 + 1;
            *(undefined8 *)(lVar13 + 8 + (longlong)local_58) = *puVar7;
            lVar13 = lVar13 + 8;
          } while (uVar8 < uVar2);
        }
        local_58[1] = uVar2;
        uVar11 = local_38;
        goto LAB_1c0003753;
      }
      _Var3 = 0xc0000023;
      pWVar9 = param_2;
      (**(code **)(WdfFunctions_01021 + 0x898))(WdfDriverGlobals,param_2,param_3);
      _Var16 = _Var3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar12 = 0x1e;
        uVar15 = 0x10;
        goto LAB_1c00031c9;
      }
LAB_1c000378b:
      _Var3 = _Var16;
      goto LAB_1c0003794;
    }
    _Var3 = 0xc0000023;
    _Var16 = 0xc0000023;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000378b;
    uVar15 = 0x10;
    uVar12 = 0x1c;
  }
  WPP_RECORDER_SF_qPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar9,5,uVar12,
                      &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar14,(char)param_3,uVar15);
LAB_1c0003794:
  (**(code **)(WdfFunctions_01021 + 0x838))(WdfDriverGlobals,param_2,_Var3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,5,0x21,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return;
}



===== Fdo_EvtWdfCxDevicePreD0Entry @ 1c0003810 =====
/* FAILED */

===== Fdo_FakeUsbFunctionSequenceBegin @ 1c0003914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Fdo_FakeUsbFunctionSequenceBegin(struct _FDO_CONTEXT * __ptr64) */

void __cdecl Fdo_FakeUsbFunctionSequenceBegin(_FDO_CONTEXT *param_1)

{
  undefined8 in_RDX;
  undefined8 uVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,5,0x53,
                       &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x54,
                        &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,(char)param_1->WdfDevice);
    }
  }
  (**(code **)(WdfFunctions_01021 + 0x4e0))(WdfDriverGlobals,param_1->IoQueue);
  uVar1 = 5;
  param_1->FakeLoadUnloadInProgress = '\x01';
  RoleMgr_ReportHardwareEvent(param_1,UrsHardwareEventPortTypeUfp);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,5,0x55,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return;
}



===== Fdo_FakeUsbFunctionSequenceEnd @ 1c0003a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Fdo_FakeUsbFunctionSequenceEnd(struct _FDO_CONTEXT * __ptr64) */

void __cdecl Fdo_FakeUsbFunctionSequenceEnd(_FDO_CONTEXT *param_1)

{
  undefined8 in_RDX;
  WDFQUEUE__ *pWVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,5,0x59,
                       &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5a,
                        &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,(char)param_1->WdfDevice);
    }
  }
  pWVar1 = param_1->IoQueue;
  param_1->FakeLoadUnloadInProgress = '\0';
  (**(code **)(WdfFunctions_01021 + 0x4d0))(WdfDriverGlobals);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar1,5,0x5b,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return;
}



===== Fdo_FakeUsbFunctionSequenceUnload @ 1c0003b00 =====

/* void __cdecl Fdo_FakeUsbFunctionSequenceUnload(struct _FDO_CONTEXT * __ptr64) */

void __cdecl Fdo_FakeUsbFunctionSequenceUnload(_FDO_CONTEXT *param_1)

{
  undefined8 in_RDX;
  undefined8 uVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,5,0x56,
                       &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x57,
                        &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,(char)param_1->WdfDevice);
    }
  }
  uVar1 = 1;
  RoleMgr_ReportHardwareEvent(param_1,UrsHardwareEventDetach);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,5,0x58,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return;
}



===== Fdo_GetDevicePropertyAsStringCollection @ 1c0003bd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Fdo_GetDevicePropertyAsStringCollection(struct _FDO_CONTEXT * __ptr64,enum
   DEVICE_REGISTRY_PROPERTY,struct WDFCOLLECTION__ * __ptr64 * __ptr64) */

long __cdecl
Fdo_GetDevicePropertyAsStringCollection
          (_FDO_CONTEXT *param_1,DEVICE_REGISTRY_PROPERTY param_2,WDFCOLLECTION__ **param_3)

{
  short sVar1;
  WDFDEVICE__ *pWVar2;
  short *psVar3;
  short *psVar4;
  longlong lVar5;
  undefined4 in_register_00000014;
  WDFDEVICE__ *pWVar6;
  uint uVar7;
  WDFDEVICE__ **ppWVar8;
  undefined2 uVar9;
  WDFDEVICE__ *local_res8;
  WDFDEVICE__ *local_res20;
  WDFDEVICE__ **ppWVar10;
  WDFDEVICE__ **local_88;
  undefined8 local_80;
  short *psStack_78;
  WDFDEVICE__ *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  WDFDEVICE__ *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  local_80 = 0;
  psStack_78 = (short *)0x0;
  local_88 = (WDFDEVICE__ **)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_register_00000014,param_2),5,0x2e,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  pWVar2 = param_1->WdfDevice;
  local_40 = 0;
  local_60 = 0;
  ppWVar10 = &local_70;
  local_res20 = (WDFDEVICE__ *)0x0;
  local_res8 = (WDFDEVICE__ *)0x0;
  uStack_68 = 0;
  local_70 = (WDFDEVICE__ *)0x38;
  ppWVar8 = (WDFDEVICE__ **)(ulonglong)param_2;
  uStack_48 = 0;
  uStack_58 = 0x100000001;
  pWVar6 = pWVar2;
  local_50 = pWVar2;
  uVar7 = (**(code **)(WdfFunctions_01021 + 0x290))
                    (WdfDriverGlobals,pWVar2,ppWVar8,1,ppWVar10,&local_res20);
  if ((int)uVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003e8d;
    uVar9 = 0x2f;
  }
  else {
    ppWVar8 = &local_res8;
    pWVar6 = (WDFDEVICE__ *)&local_70;
    local_40 = 0;
    local_60 = 0;
    uStack_68 = 0;
    local_70 = (WDFDEVICE__ *)0x38;
    uStack_48 = 0;
    uStack_58 = 0x100000001;
    local_50 = pWVar2;
    uVar7 = (**(code **)(WdfFunctions_01021 + 0x68))(WdfDriverGlobals);
    if (-1 < (int)uVar7) {
      ppWVar8 = (WDFDEVICE__ **)0x0;
      psVar3 = (short *)(**(code **)(WdfFunctions_01021 + 0x610))(WdfDriverGlobals,local_res20);
      sVar1 = *psVar3;
      while (sVar1 != 0) {
        pWVar6 = (WDFDEVICE__ *)0x2;
        lVar5 = 0x7fff;
        local_80 = 0;
        psStack_78 = (short *)0x0;
        psVar4 = psVar3;
        do {
          if (*psVar4 == 0) break;
          psVar4 = psVar4 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        uVar7 = ~-(uint)(lVar5 != 0) & 0xc000000d;
        if (lVar5 != 0) {
          sVar1 = (0x7fff - (short)lVar5) * 2;
          local_80 = CONCAT44(0,CONCAT22(sVar1 + 2,sVar1));
          psStack_78 = psVar3;
        }
        if ((int)uVar7 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0003e8d;
          uVar9 = 0x31;
          goto LAB_1c0003ccf;
        }
        ppWVar8 = &local_70;
        local_40 = 0;
        pWVar6 = (WDFDEVICE__ *)&local_80;
        local_60 = 0;
        uStack_48 = 0;
        uStack_68 = 0;
        local_70 = (WDFDEVICE__ *)0x38;
        uStack_58 = 0x100000001;
        local_50 = local_res8;
        uVar7 = (**(code **)(WdfFunctions_01021 + 0x9a0))(WdfDriverGlobals,pWVar6,ppWVar8,&local_88)
        ;
        if ((int)uVar7 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0003e8d;
          uVar9 = 0x32;
          goto LAB_1c0003ccf;
        }
        pWVar6 = local_res8;
        ppWVar8 = local_88;
        uVar7 = (**(code **)(WdfFunctions_01021 + 0x78))(WdfDriverGlobals);
        if ((int)uVar7 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0003e8d;
          uVar9 = 0x33;
          goto LAB_1c0003ccf;
        }
        psVar3 = psVar3 + (local_80 >> 1 & 0x7fff) + 1;
        sVar1 = *psVar3;
      }
      uVar7 = 0;
      *param_3 = (WDFCOLLECTION__ *)local_res8;
      goto LAB_1c0003e8d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003e8d;
    uVar9 = 0x30;
  }
LAB_1c0003ccf:
  WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar6,ppWVar8,uVar9,ppWVar10,
                      (char)pWVar2,(char)param_2,(char)uVar7);
LAB_1c0003e8d:
  pWVar6 = local_res20;
  if (local_res20 != (WDFDEVICE__ *)0x0) {
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
  }
  if (((int)uVar7 < 0) && (pWVar6 = local_res8, local_res8 != (WDFDEVICE__ *)0x0)) {
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar6,5,0x34,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return uVar7;
}



===== Fdo_Initialize @ 1c0003f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Fdo_Initialize(struct WDFDEVICE__ * __ptr64,struct _URS_CONFIG * __ptr64) */

long __cdecl Fdo_Initialize(WDFDEVICE__ *param_1,_URS_CONFIG *param_2)

{
  _URS_HOST_INTERFACE_TYPE _Var1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  URSIORESLIST__ **ppUVar6;
  undefined2 uVar7;
  undefined1 auStackY_138 [32];
  undefined1 uVar8;
  _FDO_CONTEXT *local_f8;
  _WDF_OBJECT_ATTRIBUTES local_f0;
  undefined4 local_b8;
  undefined8 local_b4;
  code *local_90;
  undefined8 local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  uVar5 = 0;
  memset(&local_b8,0,0x60);
  local_f8 = (_FDO_CONTEXT *)0x0;
  uStack_48 = 0;
  uStack_44 = 0;
  local_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,5,0x24,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  local_f0.EvtDestroyCallback = (_func___cdecl_void_void_ptr *)0x0;
  local_f0.ExecutionLevel = WdfExecutionLevelInheritFromParent;
  local_f0.SynchronizationScope = WdfSynchronizationScopeInheritFromParent;
  local_f0.ContextTypeInfo =
       (_WDF_OBJECT_CONTEXT_TYPE_INFO *)PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8;
  local_f0.EvtCleanupCallback = (_func___cdecl_void_void_ptr *)0x0;
  local_f0.Size = 0x38;
  local_f0._4_4_ = 0;
  local_f0.ParentObject = (WDFDEVICE__ *)0x0;
  local_f0.ContextSizeOverride = 0;
  lVar4 = (**(code **)(WdfFunctions_01021 + 0x658))(WdfDriverGlobals,param_1,&local_f0,&local_f8);
  uVar8 = SUB81(param_1,0);
  if (lVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar4;
    }
    uVar7 = 0x25;
    ppUVar6 = (URSIORESLIST__ **)0x2;
  }
  else {
    local_f8->Signature = UrsCxSigFdoContext;
    local_f8->WdfDevice = param_1;
    _Var1 = param_2->HostInterfaceType;
    uVar2 = *(undefined4 *)&param_2->EvtUrsFilterRemoveResourceRequirements;
    uVar3 = *(undefined4 *)((longlong)&param_2->EvtUrsFilterRemoveResourceRequirements + 4);
    (local_f8->Config).Size = param_2->Size;
    (local_f8->Config).HostInterfaceType = _Var1;
    *(undefined4 *)&(local_f8->Config).EvtUrsFilterRemoveResourceRequirements = uVar2;
    *(undefined4 *)((longlong)&(local_f8->Config).EvtUrsFilterRemoveResourceRequirements + 4) =
         uVar3;
    (local_f8->Config).EvtUrsSetRole = param_2->EvtUrsSetRole;
    local_58 = 0x20000001c;
    uStack_50 = 2;
    uStack_4c = 2;
    uStack_48 = 0;
    uStack_44 = 2;
    local_40 = 2;
    (**(code **)(WdfFunctions_01021 + 0xe8))(WdfDriverGlobals,param_1,&local_58);
    local_f0.EvtDestroyCallback = (_func___cdecl_void_void_ptr *)0x0;
    ppUVar6 = &local_f8->HostRoleResources;
    local_f0.ExecutionLevel = WdfExecutionLevelInheritFromParent;
    local_f0.SynchronizationScope = WdfSynchronizationScopeInheritFromParent;
    local_f0.EvtCleanupCallback = (_func___cdecl_void_void_ptr *)0x0;
    local_f0.ContextTypeInfo = (_WDF_OBJECT_CONTEXT_TYPE_INFO *)0x0;
    local_f0.ContextSizeOverride = 0;
    local_f0.Size = 0x38;
    local_f0._4_4_ = 0;
    local_f0.ParentObject = param_1;
    lVar4 = IoResList_Create(&local_f0,ppUVar6);
    if (lVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return lVar4;
      }
      uVar7 = 0x26;
      param_1 = (WDFDEVICE__ *)ppUVar6;
    }
    else {
      local_f0.EvtDestroyCallback = (_func___cdecl_void_void_ptr *)0x0;
      local_f0.ContextTypeInfo = (_WDF_OBJECT_CONTEXT_TYPE_INFO *)0x0;
      ppUVar6 = &local_f8->FunctionRoleResources;
      local_f0.EvtCleanupCallback = (_func___cdecl_void_void_ptr *)0x0;
      local_f0.ContextSizeOverride = 0;
      local_f0.ExecutionLevel = WdfExecutionLevelInheritFromParent;
      local_f0.SynchronizationScope = WdfSynchronizationScopeInheritFromParent;
      local_f0.Size = 0x38;
      local_f0._4_4_ = 0;
      local_f0.ParentObject = param_1;
      lVar4 = IoResList_Create(&local_f0,ppUVar6);
      if (lVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return lVar4;
        }
        uVar7 = 0x27;
        param_1 = (WDFDEVICE__ *)ppUVar6;
      }
      else {
        local_b8 = 0x60;
        local_b4 = 0x100000001;
        local_90 = Fdo_EvtIoDeviceControl;
        local_f0.EvtDestroyCallback = (_func___cdecl_void_void_ptr *)0x0;
        local_f0.ContextTypeInfo = (_WDF_OBJECT_CONTEXT_TYPE_INFO *)0x0;
        local_f0.EvtCleanupCallback = (_func___cdecl_void_void_ptr *)0x0;
        local_f0.Size = 0x38;
        local_f0._4_4_ = 0;
        local_f0.ContextSizeOverride = 0;
        local_f0.ExecutionLevel = WdfExecutionLevelPassive;
        local_f0.SynchronizationScope = WdfSynchronizationScopeInheritFromParent;
        ppUVar6 = (URSIORESLIST__ **)param_1;
        local_f0.ParentObject = param_1;
        lVar4 = (**(code **)(WdfFunctions_01021 + 0x4c0))
                          (WdfDriverGlobals,param_1,&local_b8,&local_f0);
        if (lVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return lVar4;
          }
          uVar7 = 0x28;
          param_1 = (WDFDEVICE__ *)ppUVar6;
        }
        else {
          memset(&local_b8,0,0x60);
          local_b8 = 0x60;
          local_f0.EvtDestroyCallback = (_func___cdecl_void_void_ptr *)0x0;
          local_b4 = 1;
          local_f0.ExecutionLevel = WdfExecutionLevelPassive;
          local_f0.SynchronizationScope = WdfSynchronizationScopeInheritFromParent;
          local_90 = Fdo_EvtIoDeviceControl;
          local_f0.ContextTypeInfo = (_WDF_OBJECT_CONTEXT_TYPE_INFO *)0x0;
          local_f0.EvtCleanupCallback = (_func___cdecl_void_void_ptr *)0x0;
          local_f0.Size = 0x38;
          local_f0._4_4_ = 0;
          local_f0.ContextSizeOverride = 0;
          ppUVar6 = (URSIORESLIST__ **)param_1;
          local_f0.ParentObject = param_1;
          lVar4 = (**(code **)(WdfFunctions_01021 + 0x4c0))
                            (WdfDriverGlobals,param_1,&local_b8,&local_f0);
          if (lVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return lVar4;
            }
            uVar7 = 0x29;
            param_1 = (WDFDEVICE__ *)ppUVar6;
          }
          else {
            ppUVar6 = (URSIORESLIST__ **)param_1;
            lVar4 = (**(code **)(WdfFunctions_01021 + 0xca0))
                              (WdfDriverGlobals,param_1,*WdfDriverGlobals,0xe);
            if (lVar4 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return lVar4;
              }
              uVar7 = 0x2a;
              param_1 = (WDFDEVICE__ *)ppUVar6;
            }
            else {
              lVar4 = Fdo_RetrieveIds(local_f8);
              if ((lVar4 < 0) || (lVar4 = Fdo_RetrieveBusInformation(local_f8), lVar4 < 0))
              goto LAB_1c0004446;
              Fdo_RetrieveKseDeviceFlags(local_f8);
              lVar4 = AcpiEnumeratePlds(param_1);
              if (lVar4 < 0) goto LAB_1c0004446;
              lVar4 = (**(code **)(WdfFunctions_01021 + 0x268))
                                (WdfDriverGlobals,param_1,&GUID_DEVINTERFACE_USB_ROLE_SWITCH,0);
              if (-1 < lVar4) {
                local_f8->HardwareEventReportingSupported = WdfUseDefault;
                lVar4 = RoleMgr_Initialize(local_f8);
                ppUVar6 = (URSIORESLIST__ **)param_1;
                if (-1 < lVar4) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    return lVar4;
                  }
                  ppUVar6 = (URSIORESLIST__ **)CONCAT71((int7)((ulonglong)param_1 >> 8),4);
                  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2c,
                                    &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar8);
                }
                goto LAB_1c0004446;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return lVar4;
              }
              uVar7 = 0x2b;
            }
          }
        }
      }
    }
    ppUVar6 = (URSIORESLIST__ **)CONCAT71((int7)((ulonglong)param_1 >> 8),2);
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(byte)ppUVar6,5,uVar7,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar8,(char)lVar4);
LAB_1c0004446:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),ppUVar6,5,0x2d,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return lVar4;
}



===== Fdo_IsUsbFunctionPresent @ 1c00044ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Fdo_IsUsbFunctionPresent(struct _FDO_CONTEXT * __ptr64) */

uchar __cdecl Fdo_IsUsbFunctionPresent(_FDO_CONTEXT *param_1)

{
  int iVar1;
  undefined8 local_res10 [3];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString
            (&local_18,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\UFX01000");
  iVar1 = (**(code **)(WdfFunctions_01021 + 0x728))
                    (WdfDriverGlobals,0,&local_18,0x20019,0,local_res10);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qSd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (-1 < iVar1) {
    (**(code **)(WdfFunctions_01021 + 0x738))(WdfDriverGlobals,local_res10[0]);
  }
  return iVar1 != -0x3fffffcc;
}



===== Fdo_OnDeviceControlDispatch @ 1c0004590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Fdo_OnDeviceControlDispatch(struct WDFDEVICE__ * __ptr64,unsigned char,unsigned
   char,unsigned long,void * __ptr64,struct _IRP * __ptr64,void * __ptr64) */

long __cdecl
Fdo_OnDeviceControlDispatch
          (WDFDEVICE__ *param_1,uchar param_2,uchar param_3,ulong param_4,void *param_5,
          _IRP *param_6,void *param_7)

{
  long lVar1;
  longlong lVar2;
  undefined7 in_register_00000011;
  undefined8 uVar3;
  undefined *in_stack_ffffffffffffffe8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffe8 = &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT71(in_register_00000011,param_2),5,0x22,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  if ((param_4 - 0x2a0008 < 0x15) && ((0x101111U >> (param_4 - 0x2a0008 & 0x1f) & 1) != 0)) {
    lVar2 = (**(code **)(WdfFunctions_01021 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8);
    if (param_4 == 0x2a001c) {
      uVar3 = *(undefined8 *)(lVar2 + 0x80);
    }
    else {
      uVar3 = *(undefined8 *)(lVar2 + 0x78);
    }
    lVar1 = (**(code **)(WdfFunctions_01021 + 0xc90))
                      (WdfDriverGlobals,param_1,param_6,uVar3,
                       (ulonglong)in_stack_ffffffffffffffe8 & 0xffffffff00000000);
  }
  else {
    lVar1 = (**(code **)(WdfFunctions_01021 + 0xc88))(WdfDriverGlobals,param_1,param_6,param_7);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,5,0x23,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return lVar1;
}



===== Fdo_RetrieveAcpiBusInformation @ 1c00046dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Fdo_RetrieveAcpiBusInformation(struct _FDO_CONTEXT * __ptr64) */

long __cdecl Fdo_RetrieveAcpiBusInformation(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined1 auStackY_f8 [32];
  undefined1 uVar6;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  WDFDEVICE__ *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_f8;
  pWVar1 = param_1->WdfDevice;
  local_58 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = (WDFDEVICE__ *)0x0;
  uStack_60 = 0;
  uVar3 = (**(code **)(WdfFunctions_01021 + 0x150))(WdfDriverGlobals,pWVar1);
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  iVar2 = (**(code **)(WdfFunctions_01021 + 0x5d0))(WdfDriverGlobals,uVar3,0,0x32c028);
  uVar6 = SUB81(pWVar1,0);
  if (iVar2 == -0x7ffffffb) {
    puVar4 = &local_88;
    iVar5 = local_50._4_2_ + 8;
    uStack_70 = 0x100000001;
    local_88 = CONCAT44(local_88._4_4_,0x38);
    local_68 = pWVar1;
    iVar2 = (**(code **)(WdfFunctions_01021 + 0x600))(WdfDriverGlobals,puVar4,0x200,0x58737255);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,5,0x45,
                            &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar6,(char)iVar5,
                            (char)iVar2);
      }
      goto LAB_1c0004809;
    }
    uRam0000000000000004 = 1;
    iVar2 = (**(code **)(WdfFunctions_01021 + 0x5d0))(WdfDriverGlobals,uVar3,0,0x32c028);
    if (-1 < iVar2) {
      iRam0000000000000000 = iVar5;
      uRam0000000000000004 = 1;
      return iVar2;
    }
    iRam0000000000000000 = iVar5;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x46,
                         &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar6,(char)iVar2);
      goto LAB_1c0004809;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x44,
                       &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar6,(char)iVar2);
  }
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_1c0004809:
  if (param_1->DeviceInformation != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
    param_1->DeviceInformation = (WDFMEMORY__ *)0x0;
  }
  return iVar2;
}



===== Fdo_RetrieveBusInformation @ 1c00049d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Fdo_RetrieveBusInformation(struct _FDO_CONTEXT * __ptr64) */

long __cdecl Fdo_RetrieveBusInformation(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  wchar_t *_Str1;
  undefined8 in_RDX;
  longlong lVar3;
  longlong local_res8;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  WDFDEVICE__ *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,5,0x37,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  pWVar1 = param_1->WdfDevice;
  local_38 = 0;
  local_58 = 0;
  local_res8 = 0;
  uStack_60 = 0;
  local_68 = 0x38;
  uStack_40 = 0;
  uStack_50 = 0x100000001;
  local_48 = pWVar1;
  iVar2 = (**(code **)(WdfFunctions_01021 + 0x290))
                    (WdfDriverGlobals,pWVar1,0xf,1,&local_68,&local_res8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x38,
                         &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,(char)pWVar1,(char)iVar2);
    }
  }
  else {
    _Str1 = (wchar_t *)(**(code **)(WdfFunctions_01021 + 0x610))(WdfDriverGlobals,local_res8,0);
    iVar2 = wcscmp(_Str1,L"ACPI");
    if (iVar2 == 0) {
      iVar2 = Fdo_RetrieveAcpiBusInformation(param_1);
    }
    else {
      iVar2 = wcscmp(_Str1,L"PCI");
      if (iVar2 == 0) {
        iVar2 = Fdo_RetrievePciBusInformation(param_1);
      }
      else {
        iVar2 = Fdo_RetrieveUnknownBusInformation(param_1);
      }
    }
  }
  lVar3 = local_res8;
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,5,0x39,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return iVar2;
}



===== Fdo_RetrieveIds @ 1c0004bb8 =====

/* long __cdecl Fdo_RetrieveIds(struct _FDO_CONTEXT * __ptr64) */

long __cdecl Fdo_RetrieveIds(_FDO_CONTEXT *param_1)

{
  long lVar1;
  undefined8 in_RDX;
  undefined8 uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,5,0x35,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  uVar2 = 1;
  lVar1 = Fdo_GetDevicePropertyAsStringCollection
                    (param_1,DevicePropertyHardwareID,&param_1->HardwareIds);
  if (-1 < lVar1) {
    uVar2 = 2;
    lVar1 = Fdo_GetDevicePropertyAsStringCollection
                      (param_1,DevicePropertyCompatibleIDs,&param_1->CompatibleIds);
    if (lVar1 < 0) {
      lVar1 = 0;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,5,0x36,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return lVar1;
}



===== Fdo_RetrieveKseDeviceFlags @ 1c0004c98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Fdo_RetrieveKseDeviceFlags(struct _FDO_CONTEXT * __ptr64) */

void __cdecl Fdo_RetrieveKseDeviceFlags(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  uchar uVar2;
  int iVar3;
  longlong lVar4;
  _KSE_URSCX_DEVICE_FLAGS _Var5;
  undefined8 in_RDX;
  WDFMEMORY__ *pWVar6;
  wchar_t *pwVar7;
  undefined2 uVar8;
  undefined1 auStackY_f8 [32];
  undefined1 uVar9;
  _KSE_URSCX_DEVICE_FLAGS local_b8 [2];
  ushort local_a8 [64];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_b8[0].AsULong64 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,5,0x5c,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  pWVar6 = param_1->DeviceInformation;
  pWVar1 = param_1->WdfDevice;
  lVar4 = (**(code **)(WdfFunctions_01021 + 0x610))(WdfDriverGlobals,pWVar6,0);
  uVar9 = SUB81(pWVar1,0);
  if (*(int *)(lVar4 + 4) == 1) {
    if (*(ushort *)(lVar4 + 0x10) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar8 = 0x5d;
    }
    else {
      if (*(short *)(lVar4 + 0x14) != 0) {
        RtlStringCchPrintfW(local_a8,0x3c,(ushort *)L"URSCX:ACPI\\VEN_%.4S&DEV_%.4S",
                            lVar4 + 8 + (ulonglong)*(ushort *)(lVar4 + 0x10));
        goto LAB_1c0004de7;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar8 = 0x5e;
    }
    pwVar7 = (wchar_t *)CONCAT71((int7)((ulonglong)pWVar6 >> 8),3);
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,uVar8,
                      &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar9);
  }
  else {
    RtlStringCchPrintfW(local_a8,0x3c,(ushort *)L"URSCX:PCI\\VEN_%04X&DEV_%04X",
                        (ulonglong)*(ushort *)(lVar4 + 0x50));
LAB_1c0004de7:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    pwVar7 = L"URSCX";
    iVar3 = KseQueryDeviceFlags(local_a8,L"URSCX",local_b8);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      pwVar7 = (wchar_t *)CONCAT71((int7)((ulonglong)pwVar7 >> 8),3);
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x60,
                         &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar9,(char)iVar3);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar7,5,0x61,
                           &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar9,
                           local_b8[0].ExecuteUsbFunctionLoadUnloadSequence);
      }
      param_1->DeviceFlags = (_KSE_URSCX_DEVICE_FLAGS)local_b8[0].AsULong64;
      if (((local_b8[0].AsULong64 & 1) != 0) &&
         (uVar2 = Fdo_IsUsbFunctionPresent(param_1), uVar2 == '\0')) {
        _Var5.AsULong64 = (param_1->DeviceFlags).AsULong64 & 0xfffffffffffffffe;
        param_1->DeviceFlags = (_KSE_URSCX_DEVICE_FLAGS)_Var5.AsULong64;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar7,5,0x62,
                           &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar9,
                           _Var5.ExecuteUsbFunctionLoadUnloadSequence);
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar7,5,99,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return;
}



===== Fdo_RetrievePciBusInformation @ 1c0004f64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Fdo_RetrievePciBusInformation(struct _FDO_CONTEXT * __ptr64) */

long __cdecl Fdo_RetrievePciBusInformation(_FDO_CONTEXT *param_1)

{
  undefined8 *puVar1;
  WDFDEVICE__ *pWVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  WDFMEMORY__ *pWVar8;
  undefined2 uVar9;
  longlong lVar10;
  undefined1 auStackY_208 [32];
  undefined1 uVar11;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  WDFDEVICE__ *local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  code *pcStack_140;
  undefined8 local_138 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_208;
  memset(local_138,0,0x100);
  uVar7 = 0;
  memset(&local_178,0,0x40);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,5,0x3d,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  pWVar2 = param_1->WdfDevice;
  puVar6 = &local_1b0;
  local_180 = 0;
  local_1a0 = 0;
  uStack_198 = 0x100000001;
  uStack_1a8 = 0;
  local_1b0 = 0x38;
  uStack_188 = 0;
  local_190 = pWVar2;
  iVar3 = (**(code **)(WdfFunctions_01021 + 0x600))(WdfDriverGlobals,puVar6,0x200,0x58737255);
  uVar11 = SUB81(pWVar2,0);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,5,0x3e,
                          &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar11,0x50,(char)iVar3);
    }
  }
  else {
    lVar10 = 2;
    uRam0000000000000000 = 0x150;
    uRam0000000000000004 = 2;
    iVar3 = (**(code **)(WdfFunctions_01021 + 0x288))(WdfDriverGlobals,pWVar2,0xe,4);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x3f;
LAB_1c000517d:
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar9,
                           &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar11,(char)iVar3);
      }
    }
    else {
      iVar3 = (**(code **)(WdfFunctions_01021 + 0x288))(WdfDriverGlobals,pWVar2,0x10);
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x40;
          goto LAB_1c000517d;
        }
      }
      else {
        iVar3 = (**(code **)(WdfFunctions_01021 + 0x418))
                          (WdfDriverGlobals,pWVar2,&GUID_BUS_INTERFACE_STANDARD,&local_178);
        if (iVar3 < 0) {
          iVar4 = iVar3;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
LAB_1c000530f:
            iVar3 = iVar4;
          }
          else {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x41,
                               &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar11,(char)iVar3);
          }
        }
        else {
          iVar4 = (*pcStack_140)(uStack_170,0,local_138,0);
          if (iVar4 == 0x100) {
            puVar6 = local_138;
            uRam0000000000000008 = 0;
            pWVar8 = (WDFMEMORY__ *)0x80;
            uRam000000000000000c = 0;
            uRam000000000000000e = 0;
            puVar5 = (undefined8 *)0x50;
            do {
              uVar7 = puVar6[1];
              *puVar5 = *puVar6;
              puVar5[1] = uVar7;
              uVar7 = puVar6[3];
              puVar5[2] = puVar6[2];
              puVar5[3] = uVar7;
              uVar7 = puVar6[5];
              puVar5[4] = puVar6[4];
              puVar5[5] = uVar7;
              uVar7 = puVar6[7];
              puVar5[6] = puVar6[6];
              puVar5[7] = uVar7;
              uVar7 = puVar6[9];
              puVar5[8] = puVar6[8];
              puVar5[9] = uVar7;
              uVar7 = puVar6[0xb];
              puVar5[10] = puVar6[10];
              puVar5[0xb] = uVar7;
              uVar7 = puVar6[0xd];
              puVar5[0xc] = puVar6[0xc];
              puVar5[0xd] = uVar7;
              puVar1 = puVar6 + 0xe;
              uVar7 = puVar6[0xf];
              puVar6 = puVar6 + 0x10;
              puVar5[0xe] = *puVar1;
              puVar5[0xf] = uVar7;
              lVar10 = lVar10 + -1;
              puVar5 = puVar5 + 0x10;
            } while (lVar10 != 0);
            uRam0000000000000010 = local_178;
            uRam0000000000000018 = uStack_170;
            uRam0000000000000020 = local_168;
            uRam0000000000000028 = uStack_160;
            uRam0000000000000030 = local_158;
            uRam0000000000000038 = uStack_150;
            uRam0000000000000040 = local_148;
            pcRam0000000000000048 = pcStack_140;
            goto LAB_1c00053c0;
          }
          iVar3 = -0x3fffffff;
          iVar4 = -0x3fffffff;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000530f;
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x42,
                            &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,uVar11);
        }
      }
    }
  }
  pWVar8 = param_1->DeviceInformation;
  if (pWVar8 != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
    param_1->DeviceInformation = (WDFMEMORY__ *)0x0;
  }
LAB_1c00053c0:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar8,5,0x43,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return iVar3;
}



===== Fdo_RetrieveUnknownBusInformation @ 1c0005428 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Fdo_RetrieveUnknownBusInformation(struct _FDO_CONTEXT * __ptr64) */

long __cdecl Fdo_RetrieveUnknownBusInformation(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  undefined8 in_RDX;
  undefined8 *puVar3;
  undefined4 *local_res8;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  WDFDEVICE__ *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res8 = (undefined4 *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,5,0x3a,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  pWVar1 = param_1->WdfDevice;
  local_38 = 0;
  puVar3 = &local_68;
  local_58 = 0;
  uStack_50 = 0x100000001;
  uStack_60 = 0;
  local_68 = 0x38;
  uStack_40 = 0;
  local_48 = pWVar1;
  iVar2 = (**(code **)(WdfFunctions_01021 + 0x600))
                    (WdfDriverGlobals,puVar3,0x200,0x58737255,0x150,&param_1->DeviceInformation,
                     &local_res8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    WPP_RECORDER_SF_qPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,5,0x3b,
                        &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,(char)pWVar1,0x50,
                        (char)iVar2);
  }
  else {
    puVar3 = (undefined8 *)0x0;
    memset(local_res8,0,0x150);
    *local_res8 = 0x150;
    local_res8[1] = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,5,0x3c,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return iVar2;
}



===== Fdo_SetHardwareEventSupport @ 1c00055ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Fdo_SetHardwareEventSupport(struct WDFDEVICE__ * __ptr64,unsigned char) */

void __cdecl Fdo_SetHardwareEventSupport(WDFDEVICE__ *param_1,uchar param_2)

{
  int iVar1;
  longlong lVar2;
  undefined7 in_register_00000011;
  WDFDEVICE__ *pWVar3;
  undefined8 uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT71(in_register_00000011,param_2),5,0x50,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8);
  pWVar3 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01021 + 0x158))(WdfDriverGlobals);
  if (iVar1 == 0x119) {
    Verifier_DbgBreak("Client driver is not allowed to report a change in support for reporting hardware events after the EvtDevicePrepareHardware callback has completed."
                      ,(ulong)pWVar3);
  }
  else {
    *(uint *)(lVar2 + 0x40) = (uint)(param_2 != '\0');
    if (param_2 == '\0') {
      *(undefined1 *)(lVar2 + 0x44) = 1;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar4 = CONCAT71((int7)((ulonglong)pWVar3 >> 8),4);
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x51,
                       &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,(char)param_1,
                       (char)*(undefined4 *)(lVar2 + 0x40));
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,5,0x52,
                       &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
    }
  }
  return;
}



===== Fdo_SetPoHandle @ 1c00056fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Fdo_SetPoHandle(struct WDFDEVICE__ * __ptr64,struct POHANDLE__ * __ptr64) */

void __cdecl Fdo_SetPoHandle(WDFDEVICE__ *param_1,POHANDLE__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,5,0x4d,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  *(POHANDLE__ **)(lVar1 + 0x68) = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,5,0x4f,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return;
}



===== Fdo_TransformResourceRequirements @ 1c0005800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Fdo_TransformResourceRequirements(struct WDFDEVICE__ * __ptr64,struct
   WDFIORESREQLIST__ * __ptr64) */

void __cdecl Fdo_TransformResourceRequirements(WDFDEVICE__ *param_1,WDFIORESREQLIST__ *param_2)

{
  uint uVar1;
  uint uVar2;
  WDFIORESREQLIST__ *pWVar3;
  undefined8 *puVar4;
  WDFIORESREQLIST__ *pWVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStackY_88 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,5,0x4b,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  pWVar5 = param_2;
  uVar1 = (**(code **)(WdfFunctions_01021 + 0x910))(WdfDriverGlobals);
  uVar7 = 0;
  if (uVar1 != 0) {
    do {
      pWVar3 = (WDFIORESREQLIST__ *)
               (**(code **)(WdfFunctions_01021 + 0x918))(WdfDriverGlobals,param_2,uVar7);
      pWVar5 = pWVar3;
      uVar2 = (**(code **)(WdfFunctions_01021 + 0x950))(WdfDriverGlobals);
      uVar6 = 0;
      if (uVar2 != 0) {
        do {
          pWVar5 = pWVar3;
          puVar4 = (undefined8 *)
                   (**(code **)(WdfFunctions_01021 + 0x958))(WdfDriverGlobals,pWVar3,uVar6);
          if ((*(char *)((longlong)puVar4 + 1) - 3U & 0xfb) == 0) {
            uStack_50 = puVar4[1];
            local_48 = puVar4[2];
            uStack_40 = puVar4[3];
            local_58._3_5_ = (undefined5)((ulonglong)*puVar4 >> 0x18);
            local_58._0_3_ = CONCAT12(3,(short)*(undefined4 *)puVar4);
            pWVar5 = pWVar3;
            (**(code **)(WdfFunctions_01021 + 0x948))(WdfDriverGlobals,pWVar3,&local_58,uVar6);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar2);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar5,5,0x4c,
                     &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids);
  }
  return;
}



===== RtlStringCchPrintfW @ 1c00059d0 =====

/* long __cdecl RtlStringCchPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCchPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  ulonglong _Count;
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
      lVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = 0;
  }
  else {
    lVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar2;
}



===== WPP_RECORDER_SF_qDd @ 1c0005a4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qPP @ 1c0005b44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qPP(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,8,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_qPd @ 1c0005c94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qPd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qS @ 1c0005dec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qS(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000038[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,0x5f,&uStack0000000000000030,8,
               pwVar2,lVar1,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000038[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,5,&WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,0x5f,
                  &uStack0000000000000030,8,in_stack_00000038,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_qSd @ 1c0005f44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qSd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,100,&uStack0000000000000030,8,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\UFX01000",0x7a,
               &uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,100,
                  &uStack0000000000000030,8,
                  L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\UFX01000",0x7a,
                  &uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qi @ 1c0006048 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qi(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qqL @ 1c0006174 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqL(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqq @ 1c00062cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,0x4e,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_b046be06556e36804b3f42ef06882e4c_Traceguids,0x4e,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,0);
  return;
}



===== RoleMgr_ClearRoleSwitchModeRecord @ 1c00063b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RoleMgr_ClearRoleSwitchModeRecord(struct _FDO_CONTEXT * __ptr64) */

void __cdecl RoleMgr_ClearRoleSwitchModeRecord(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  byte bVar3;
  undefined2 uVar4;
  longlong local_res8 [4];
  undefined1 uVar5;
  undefined8 local_18;
  undefined8 uStack_10;
  
  pWVar1 = param_1->WdfDevice;
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar2 = (**(code **)(WdfFunctions_01021 + 0x180))(WdfDriverGlobals,pWVar1,1,0x2001f,0,local_res8);
  uVar5 = SUB81(pWVar1,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0006513;
    uVar4 = 0x2f;
    bVar3 = 3;
  }
  else {
    RtlInitUnicodeString(&local_18,L"RoleSwitchMode");
    iVar2 = (**(code **)(WdfFunctions_01021 + 0x750))(WdfDriverGlobals,local_res8[0],&local_18);
    if (iVar2 < 0) {
      if (iVar2 == -0x3fffffcc) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x30,
                            &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar5);
        }
        goto LAB_1c0006513;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0006513;
      uVar4 = 0x31;
      bVar3 = 2;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0006513;
      uVar4 = 0x32;
      bVar3 = 4;
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar3,6,uVar4,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar5,(char)iVar2);
LAB_1c0006513:
  if (local_res8[0] != 0) {
    (**(code **)(WdfFunctions_01021 + 0x738))(WdfDriverGlobals);
  }
  return;
}



===== RoleMgr_EvtPdoPrepareHardware @ 1c0006550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RoleMgr_EvtPdoPrepareHardware(struct _FDO_CONTEXT * __ptr64,enum _URS_ROLE) */

long __cdecl RoleMgr_EvtPdoPrepareHardware(_FDO_CONTEXT *param_1,_URS_ROLE param_2)

{
  _func___cdecl_long_WDFDEVICE___ptr__URS_ROLE *p_Var1;
  int iVar2;
  undefined4 in_register_00000014;
  WDFDEVICE__ *pWVar3;
  WDFDEVICE__ *pWVar4;
  undefined1 uVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_register_00000014,param_2),6,0x52,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  pWVar4 = param_1->WdfDevice;
  pWVar3 = pWVar4;
  iVar2 = (**(code **)(WdfFunctions_01021 + 0xdb0))
                    (WdfDriverGlobals,pWVar4,1,0,0x548,
                     "onecore\\drivers\\wdm\\usb\\urs\\urscx\\src\\rolemgr.cpp");
  uVar5 = SUB81(pWVar4,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    pWVar4 = (WDFDEVICE__ *)CONCAT71((int7)((ulonglong)pWVar3 >> 8),4);
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x53,
                       &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar5,(char)iVar2);
  }
  else {
    p_Var1 = (param_1->Config).EvtUrsSetRole;
    if ((p_Var1 == (_func___cdecl_long_WDFDEVICE___ptr__URS_ROLE *)0x0) ||
       (iVar2 = (*p_Var1)(pWVar4,param_2), -1 < iVar2)) {
      if ((param_2 == UrsRoleHost) && (param_1->DisableVBusManagement == '\0')) {
        iVar2 = VBus_Enable(param_1);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x54,
                         &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar5,(char)iVar2);
    }
    (**(code **)(WdfFunctions_01021 + 0xdb8))
              (WdfDriverGlobals,pWVar4,0,0x56c,
               "onecore\\drivers\\wdm\\usb\\urs\\urscx\\src\\rolemgr.cpp");
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,6,0x55,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return iVar2;
}



===== RoleMgr_EvtPdoReleaseHardware @ 1c0006720 =====

/* long __cdecl RoleMgr_EvtPdoReleaseHardware(struct _FDO_CONTEXT * __ptr64,enum _URS_ROLE) */

long __cdecl RoleMgr_EvtPdoReleaseHardware(_FDO_CONTEXT *param_1,_URS_ROLE param_2)

{
  long lVar1;
  _URS_ROLE _Var2;
  undefined4 in_register_00000014;
  
  _Var2 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_register_00000014,param_2),6,0x56,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  if ((param_2 == UrsRoleHost) && (param_1->DisableVBusManagement == '\0')) {
    lVar1 = VBus_Disable(param_1);
  }
  else {
    lVar1 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_register_00000014,_Var2)
                     ,6,0x57,&WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return lVar1;
}



===== RoleMgr_EvtRoleChangeWorkItem @ 1c00067f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RoleMgr_EvtRoleChangeWorkItem(struct WDFWORKITEM__ * __ptr64) */

void __cdecl RoleMgr_EvtRoleChangeWorkItem(WDFWORKITEM__ *param_1)

{
  undefined8 uVar1;
  _FDO_CONTEXT *p_Var2;
  undefined8 in_RDX;
  WDFWAITLOCK__ *pWVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,6,0x36,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01021 + 0xbe8))(WdfDriverGlobals,param_1);
  p_Var2 = (_FDO_CONTEXT *)
           (**(code **)(WdfFunctions_01021 + 0x650))
                     (WdfDriverGlobals,uVar1,PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8);
  (**(code **)(WdfFunctions_01021 + 0x9c8))(WdfDriverGlobals,p_Var2->RoleChangeLock,0);
  if ((p_Var2->EnableHardwareEvents != '\0') || (p_Var2->DynamicHostOnlyModeEnabled != '\0')) {
    RoleMgr_ProcessHardwareEventLoop(p_Var2);
  }
  pWVar3 = p_Var2->RoleChangeLock;
  (**(code **)(WdfFunctions_01021 + 0x9d0))(WdfDriverGlobals);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,6,0x37,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return;
}



===== RoleMgr_EvtRoleChangeWorkItemLauncherDpc @ 1c0006920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RoleMgr_EvtRoleChangeWorkItemLauncherDpc(struct WDFDPC__ * __ptr64) */

void __cdecl RoleMgr_EvtRoleChangeWorkItemLauncherDpc(WDFDPC__ *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 in_RDX;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,6,0x38,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01021 + 0x390))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8);
  uVar1 = *(undefined8 *)(lVar2 + 0x58);
  (**(code **)(WdfFunctions_01021 + 0xbe0))(WdfDriverGlobals);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,6,0x39,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return;
}



===== RoleMgr_GetConfiguredRoleSwitchMode @ 1c0006a18 =====

/* enum _URS_ROLE_SWITCH_MODE __cdecl RoleMgr_GetConfiguredRoleSwitchMode(struct _FDO_CONTEXT *
   __ptr64) */

_URS_ROLE_SWITCH_MODE __cdecl RoleMgr_GetConfiguredRoleSwitchMode(_FDO_CONTEXT *param_1)

{
  _URS_ROLE_SWITCH_MODE _Var1;
  undefined1 in_DL;
  undefined7 in_register_00000011;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(in_register_00000011,in_DL)
                     ,6,0x1b,&WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  _Var1 = RoleMgr_GetDevNodeRoleSwitchMode(param_1);
  if (((_Var1 == 0) && (_Var1 = RoleMgr_GetOemDefaultRoleSwitchMode(param_1), _Var1 == 0)) &&
     (_Var1 = RoleMgr_GetOsDefaultRoleSwitchMode(param_1), _Var1 == 0)) {
    _Var1 = 3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 3;
    }
    in_DL = 4;
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x1c,
                       &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)param_1->WdfDevice,3);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(in_register_00000011,in_DL)
                     ,6,0x1d,&WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return _Var1;
}



===== RoleMgr_GetDevNodeRoleSwitchMode @ 1c0006b24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _URS_ROLE_SWITCH_MODE __cdecl RoleMgr_GetDevNodeRoleSwitchMode(struct _FDO_CONTEXT *
   __ptr64) */

_URS_ROLE_SWITCH_MODE __cdecl RoleMgr_GetDevNodeRoleSwitchMode(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  _URS_ROLE_SWITCH_MODE _Var2;
  undefined8 in_RDX;
  longlong lVar3;
  _URS_ROLE_SWITCH_MODE _Var4;
  _URS_ROLE_SWITCH_MODE _Var5;
  undefined2 uVar6;
  _URS_ROLE_SWITCH_MODE local_res8 [2];
  longlong local_res10;
  undefined1 uVar7;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_38 = 0;
  uStack_30 = 0;
  local_res8[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,6,0x11,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  pWVar1 = param_1->WdfDevice;
  local_res10 = 0;
  _Var4 = 0;
  _Var2 = (**(code **)(WdfFunctions_01021 + 0x180))
                    (WdfDriverGlobals,pWVar1,1,0x20019,0,&local_res10);
  uVar7 = SUB81(pWVar1,0);
  if ((int)_Var2 < 0) {
    _Var5 = _Var4;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0006ccf;
    uVar6 = 0x12;
LAB_1c0006be1:
  }
  else {
    RtlInitUnicodeString(&local_38,L"RoleSwitchMode");
    _Var2 = (**(code **)(WdfFunctions_01021 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_38,local_res8);
    _Var5 = local_res8[0];
    if ((int)_Var2 < 0) {
      _Var5 = _Var4;
      if ((_Var2 == 0xc0000034) ||
         ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_1c0006ccf;
      uVar6 = 0x13;
      goto LAB_1c0006be1;
    }
    if ((local_res8[0] - 1 < 4) || (local_res8[0] == 6)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x15,
                           &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar7,
                           (char)local_res8[0]);
      }
      goto LAB_1c0006ccf;
    }
    _Var5 = _Var4;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0006ccf;
    uVar6 = 0x14;
    _Var2 = local_res8[0];
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,uVar6,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar7,(char)_Var2);
  _Var5 = _Var4;
LAB_1c0006ccf:
  lVar3 = local_res10;
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01021 + 0x738))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,6,0x16,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return _Var5;
}



===== RoleMgr_GetOemDefaultRoleSwitchMode @ 1c0006d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _URS_ROLE_SWITCH_MODE __cdecl RoleMgr_GetOemDefaultRoleSwitchMode(struct _FDO_CONTEXT *
   __ptr64) */

_URS_ROLE_SWITCH_MODE __cdecl RoleMgr_GetOemDefaultRoleSwitchMode(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  _URS_ROLE_SWITCH_MODE _Var2;
  _URS_ROLE_SWITCH_MODE _Var3;
  _URS_ROLE_SWITCH_MODE _Var4;
  undefined2 uVar5;
  _URS_ROLE_SWITCH_MODE local_res8 [2];
  longlong local_res10;
  undefined1 uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  pWVar1 = param_1->WdfDevice;
  local_res8[0] = 0;
  _Var3 = 0;
  local_res10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_28,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\USB");
  RtlInitUnicodeString(&local_18,L"RoleSwitchMode");
  _Var2 = (**(code **)(WdfFunctions_01021 + 0x728))
                    (WdfDriverGlobals,0,&local_28,0x20019,0,&local_res10);
  uVar6 = SUB81(pWVar1,0);
  _Var4 = _Var3;
  if ((int)_Var2 < 0) {
    if ((_Var2 == 0xc0000034) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_1c0006ee8;
    uVar5 = 0x2b;
LAB_1c0006df7:
  }
  else {
    _Var2 = (**(code **)(WdfFunctions_01021 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_18,local_res8);
    _Var4 = local_res8[0];
    if ((int)_Var2 < 0) {
      _Var4 = _Var3;
      if ((_Var2 == 0xc0000034) ||
         ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_1c0006ee8;
      uVar5 = 0x2c;
      goto LAB_1c0006df7;
    }
    if ((local_res8[0] - 1 < 4) || (local_res8[0] == 6)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x2e,
                           &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar6,
                           (char)local_res8[0]);
      }
      goto LAB_1c0006ee8;
    }
    _Var4 = _Var3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0006ee8;
    uVar5 = 0x2d;
    _Var2 = local_res8[0];
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,uVar5,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar6,(char)_Var2);
  _Var4 = _Var3;
LAB_1c0006ee8:
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01021 + 0x738))(WdfDriverGlobals);
  }
  return _Var4;
}



===== RoleMgr_GetOsDefaultRoleSwitchMode @ 1c0006f28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _URS_ROLE_SWITCH_MODE __cdecl RoleMgr_GetOsDefaultRoleSwitchMode(struct _FDO_CONTEXT *
   __ptr64) */

_URS_ROLE_SWITCH_MODE __cdecl RoleMgr_GetOsDefaultRoleSwitchMode(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  _URS_ROLE_SWITCH_MODE _Var2;
  _URS_ROLE_SWITCH_MODE _Var3;
  _URS_ROLE_SWITCH_MODE _Var4;
  undefined2 uVar5;
  _URS_ROLE_SWITCH_MODE local_res8 [2];
  longlong local_res10;
  undefined1 uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  pWVar1 = param_1->WdfDevice;
  local_res8[0] = 0;
  _Var3 = 0;
  local_res10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_28,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\USB");
  RtlInitUnicodeString(&local_18,L"OsDefaultRoleSwitchMode");
  _Var2 = (**(code **)(WdfFunctions_01021 + 0x728))
                    (WdfDriverGlobals,0,&local_28,0x20019,0,&local_res10);
  uVar6 = SUB81(pWVar1,0);
  _Var4 = _Var3;
  if ((int)_Var2 < 0) {
    if ((_Var2 == 0xc0000034) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_1c00070d0;
    uVar5 = 0x17;
LAB_1c0006fdf:
  }
  else {
    _Var2 = (**(code **)(WdfFunctions_01021 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_18,local_res8);
    _Var4 = local_res8[0];
    if ((int)_Var2 < 0) {
      _Var4 = _Var3;
      if ((_Var2 == 0xc0000034) ||
         ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_1c00070d0;
      uVar5 = 0x18;
      goto LAB_1c0006fdf;
    }
    if ((local_res8[0] - 1 < 4) || (local_res8[0] == 6)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x1a,
                           &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar6,
                           (char)local_res8[0]);
      }
      goto LAB_1c00070d0;
    }
    _Var4 = _Var3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00070d0;
    uVar5 = 0x19;
    _Var2 = local_res8[0];
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,uVar5,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar6,(char)_Var2);
  _Var4 = _Var3;
LAB_1c00070d0:
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01021 + 0x738))(WdfDriverGlobals);
  }
  return _Var4;
}



===== RoleMgr_GetRoleSwitchMode @ 1c0007110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RoleMgr_GetRoleSwitchMode(struct _FDO_CONTEXT * __ptr64,enum _URS_ROLE_SWITCH_MODE *
   __ptr64) */

void __cdecl RoleMgr_GetRoleSwitchMode(_FDO_CONTEXT *param_1,_URS_ROLE_SWITCH_MODE *param_2)

{
  uchar uVar1;
  uchar uVar2;
  _URS_ROLE _Var3;
  
  (**(code **)(WdfFunctions_01021 + 0x9c8))(WdfDriverGlobals,param_1->RoleChangeLock,0);
  _Var3 = param_1->CurrentRole;
  uVar1 = param_1->EnableHardwareEvents;
  uVar2 = param_1->DynamicHostOnlyModeEnabled;
  (**(code **)(WdfFunctions_01021 + 0x9d0))(WdfDriverGlobals,param_1->RoleChangeLock);
  if (uVar1 == '\0') {
    if (uVar2 == '\0') {
      if (_Var3 == UrsRoleNone) {
        *param_2 = 4;
      }
      else if (_Var3 == UrsRoleHost) {
        *param_2 = 1;
      }
      else if (_Var3 == UrsRoleFunction) {
        *param_2 = 2;
      }
      else {
        *param_2 = 0;
      }
    }
    else {
      *param_2 = 6;
    }
  }
  else {
    *param_2 = 3;
  }
  return;
}



===== RoleMgr_Initialize @ 1c00071dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RoleMgr_Initialize(struct _FDO_CONTEXT * __ptr64) */

long __cdecl RoleMgr_Initialize(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  _URS_ROLE_SWITCH_MODE _Var3;
  undefined8 in_RDX;
  longlong lVar4;
  undefined2 uVar5;
  int local_res8 [2];
  longlong local_res10;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  WDFDEVICE__ *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  code *pcStack_78;
  undefined8 local_70;
  undefined8 local_68;
  code *pcStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  local_58 = 0;
  local_res8[0] = 0;
  local_70 = 0;
  local_68 = 0;
  pcStack_60 = (code *)0x0;
  local_80 = 0;
  pcStack_78 = (code *)0x0;
  local_50 = 0;
  uStack_48 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,6,0x1e,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  pWVar1 = param_1->WdfDevice;
  local_res10 = 0;
  param_1->EnableHardwareEvents = '\x01';
  param_1->DynamicHostOnlyModeEnabled = '\0';
  local_88 = 0;
  local_a8 = 0;
  uStack_b0 = 0;
  uStack_a0 = 0x100000001;
  uStack_90 = 0;
  local_b8 = 0x38;
  local_98 = pWVar1;
  iVar2 = (**(code **)(WdfFunctions_01021 + 0x9c0))
                    (WdfDriverGlobals,&local_b8,&param_1->RoleChangeLock);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0007504;
    uVar5 = 0x1f;
  }
  else {
    local_80 = CONCAT44(local_80._4_4_,0x18);
    local_88 = 0;
    local_a8 = 0;
    uStack_b0 = 0;
    pcStack_78 = RoleMgr_EvtRoleChangeWorkItemLauncherDpc;
    uStack_90 = 0;
    uStack_a0 = 0x100000001;
    local_70 = CONCAT71(local_70._1_7_,1);
    local_b8 = 0x38;
    local_98 = pWVar1;
    iVar2 = (**(code **)(WdfFunctions_01021 + 0x378))
                      (WdfDriverGlobals,&local_80,&local_b8,&param_1->RoleChangeWorkItemLauncherDpc)
    ;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0007504;
      uVar5 = 0x20;
    }
    else {
      local_68 = CONCAT44(local_68._4_4_,0x18);
      local_88 = 0;
      local_a8 = 0;
      uStack_b0 = 0;
      pcStack_60 = RoleMgr_EvtRoleChangeWorkItem;
      uStack_90 = 0;
      uStack_a0 = 0x100000001;
      local_58 = CONCAT71(local_58._1_7_,1);
      local_b8 = 0x38;
      local_98 = pWVar1;
      iVar2 = (**(code **)(WdfFunctions_01021 + 0xbd8))
                        (WdfDriverGlobals,&local_68,&local_b8,&param_1->RoleChangeWorkItem);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0007504;
        uVar5 = 0x21;
      }
      else {
        _Var3 = RoleMgr_GetConfiguredRoleSwitchMode(param_1);
        RoleMgr_PublishCapabilities(param_1,_Var3);
        if (_Var3 == 6) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x22,
                              &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)pWVar1);
          }
          param_1->DynamicHostOnlyModeEnabled = '\x01';
        }
        else if (_Var3 != 3) {
          param_1->EnableHardwareEvents = '\0';
          RoleMgr_ProcessRoleSwitchMode(param_1,_Var3);
        }
        iVar2 = (**(code **)(WdfFunctions_01021 + 0x180))
                          (WdfDriverGlobals,pWVar1,1,0x20019,0,&local_res10);
        if (-1 < iVar2) {
          RtlInitUnicodeString(&local_50,L"DisableVBusManagement");
          iVar2 = (**(code **)(WdfFunctions_01021 + 0x780))
                            (WdfDriverGlobals,local_res10,&local_50,local_res8);
          if (iVar2 < 0) {
            iVar2 = 0;
          }
          else {
            param_1->DisableVBusManagement = local_res8[0] != 0;
          }
          param_1->LastHardwareEvent = UrsHardwareEventDetach;
          goto LAB_1c0007504;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0007504;
        uVar5 = 0x23;
      }
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar5,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)pWVar1,(char)iVar2);
LAB_1c0007504:
  lVar4 = local_res10;
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01021 + 0x738))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,6,0x24,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return iVar2;
}



===== RoleMgr_ProcessHardwareEvent @ 1c000757c =====

/* long __cdecl RoleMgr_ProcessHardwareEvent(struct _FDO_CONTEXT * __ptr64,enum _URS_HARDWARE_EVENT)
    */

long __cdecl RoleMgr_ProcessHardwareEvent(_FDO_CONTEXT *param_1,_URS_HARDWARE_EVENT param_2)

{
  long lVar1;
  undefined4 in_register_00000014;
  undefined8 uVar2;
  undefined7 uVar4;
  WDFDEVICE__ *pWVar3;
  _URS_ROLE _Var5;
  undefined1 uVar6;
  
  uVar2 = CONCAT44(in_register_00000014,param_2);
  _Var5 = UrsRoleNone;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,6,0x45,
                       &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,6,0x3a,
                       &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
    }
  }
  pWVar3 = param_1->WdfDevice;
  uVar4 = (undefined7)((ulonglong)pWVar3 >> 8);
  uVar6 = SUB81(pWVar3,0);
  if (param_2 != UrsHardwareEventDetach) {
    if (param_2 == UrsHardwareEventIdGround) {
LAB_1c000766d:
      _Var5 = UrsRoleHost;
    }
    else {
      if (param_2 != UrsHardwareEventIdFloat) {
        if (param_2 == UrsHardwareEventPortTypeDfp) goto LAB_1c000766d;
        if (param_2 != UrsHardwareEventPortTypeUfp) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            pWVar3 = (WDFDEVICE__ *)CONCAT71(uVar4,3);
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,0x3b,
                               &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar6,(char)param_2)
            ;
          }
          lVar1 = -0x3ffffff0;
          goto LAB_1c00076ab;
        }
      }
      _Var5 = UrsRoleFunction;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pWVar3 = (WDFDEVICE__ *)CONCAT71(uVar4,4);
    WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x3c,
                        &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar6,(char)param_2,
                        (char)_Var5);
  }
  lVar1 = 0;
LAB_1c00076ab:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,6,0x3d,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  if (-1 < lVar1) {
    pWVar3 = (WDFDEVICE__ *)(ulonglong)_Var5;
    lVar1 = RoleMgr_ProcessRole(param_1,_Var5);
    if (-1 < lVar1) {
      param_1->LastHardwareEvent = param_2;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,6,0x46,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return lVar1;
}



===== RoleMgr_ProcessHardwareEventLoop @ 1c0007748 =====

/* void __cdecl RoleMgr_ProcessHardwareEventLoop(struct _FDO_CONTEXT * __ptr64) */

void __cdecl RoleMgr_ProcessHardwareEventLoop(_FDO_CONTEXT *param_1)

{
  _URS_HARDWARE_EVENT _Var1;
  long lVar2;
  _URS_HARDWARE_EVENT _Var3;
  ulonglong in_RDX;
  ulonglong uVar4;
  bool bVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,6,0x25,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  _Var1 = UrsHardwareEventNone;
  LOCK();
  _Var3 = param_1->HardwareEventToProcess;
  bVar5 = _Var3 == UrsHardwareEventNone;
  if (bVar5) {
    param_1->HardwareEventToProcess = UrsHardwareEventNone;
  }
  else {
    _Var1 = _Var3;
  }
  UNLOCK();
  while (uVar4 = (ulonglong)_Var1, !bVar5) {
    lVar2 = RoleMgr_ProcessHardwareEvent(param_1,_Var1);
    in_RDX = uVar4;
    if (lVar2 < 0) break;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = CONCAT71((int7)(uVar4 >> 8),4);
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x26,
                         &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)param_1->WdfDevice,
                         (char)_Var1);
    }
    LOCK();
    _Var3 = param_1->HardwareEventToProcess;
    if (_Var1 == _Var3) {
      param_1->HardwareEventToProcess = UrsHardwareEventNone;
      _Var3 = _Var1;
    }
    else {
    }
    UNLOCK();
    bVar5 = _Var3 == _Var1;
    in_RDX = uVar4;
    _Var1 = _Var3;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,6,0x27,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return;
}



===== RoleMgr_ProcessRole @ 1c000784c =====

/* long __cdecl RoleMgr_ProcessRole(struct _FDO_CONTEXT * __ptr64,enum _URS_ROLE) */

long __cdecl RoleMgr_ProcessRole(_FDO_CONTEXT *param_1,_URS_ROLE param_2)

{
  long lVar1;
  undefined4 in_register_00000014;
  ulonglong uVar2;
  
  uVar2 = CONCAT44(in_register_00000014,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,6,0x42,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  if (param_2 == param_1->CurrentRole) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = CONCAT71((int7)(uVar2 >> 8),4);
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x43,
                         &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)param_1->WdfDevice,
                         (char)param_2);
    }
    lVar1 = 0;
  }
  else {
    lVar1 = RoleMgr_TeardownCurrentRole(param_1);
    if (-1 < lVar1) {
      uVar2 = (ulonglong)param_2;
      lVar1 = RoleMgr_SetupRole(param_1,param_2);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,6,0x44,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return lVar1;
}



===== RoleMgr_ProcessRoleSwitchMode @ 1c0007950 =====

/* void __cdecl RoleMgr_ProcessRoleSwitchMode(struct _FDO_CONTEXT * __ptr64,enum
   _URS_ROLE_SWITCH_MODE) */

void __cdecl RoleMgr_ProcessRoleSwitchMode(_FDO_CONTEXT *param_1,_URS_ROLE_SWITCH_MODE param_2)

{
  undefined4 in_register_00000014;
  undefined8 uVar1;
  undefined7 uVar3;
  WDFDEVICE__ *pWVar2;
  _URS_ROLE _Var4;
  int iVar5;
  undefined1 uVar6;
  
  uVar1 = CONCAT44(in_register_00000014,param_2);
  _Var4 = UrsRoleNone;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,6,0x47,
                       &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,6,0x3e,
                       &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
    }
  }
  pWVar2 = param_1->WdfDevice;
  uVar3 = (undefined7)((ulonglong)pWVar2 >> 8);
  uVar6 = SUB81(pWVar2,0);
  if (param_2 == 1) {
    _Var4 = UrsRoleHost;
  }
  else if (param_2 == 2) {
    _Var4 = UrsRoleFunction;
  }
  else if (param_2 != 4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pWVar2 = (WDFDEVICE__ *)CONCAT71(uVar3,3);
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,0x3f,
                         &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar6,(char)param_2);
    }
    iVar5 = -0x3ffffff0;
    goto LAB_1c0007a71;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pWVar2 = (WDFDEVICE__ *)CONCAT71(uVar3,4);
    WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x40,
                        &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar6,(char)param_2,
                        (char)_Var4);
  }
  iVar5 = 0;
LAB_1c0007a71:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,6,0x41,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  if (-1 < iVar5) {
    pWVar2 = (WDFDEVICE__ *)(ulonglong)_Var4;
    RoleMgr_ProcessRole(param_1,_Var4);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,6,0x48,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return;
}



===== RoleMgr_PublishCapabilities @ 1c0007b00 =====

/* void __cdecl RoleMgr_PublishCapabilities(struct _FDO_CONTEXT * __ptr64,enum
   _URS_ROLE_SWITCH_MODE) */

void __cdecl RoleMgr_PublishCapabilities(_FDO_CONTEXT *param_1,_URS_ROLE_SWITCH_MODE param_2)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  undefined4 in_register_00000014;
  undefined4 *puVar3;
  undefined4 local_res10 [2];
  ulonglong in_stack_ffffffffffffffd0;
  
  puVar3 = (undefined4 *)CONCAT44(in_register_00000014,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,6,0x58,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  pWVar1 = param_1->WdfDevice;
  if (param_2 - 2 < 2) {
    puVar3 = local_res10;
    local_res10[0] = 0;
    iVar2 = ZwUpdateWnfStateData
                      (&WNF_USB_FUNCTION_CONTROLLER_STATE,puVar3,4,0,0,
                       in_stack_ffffffffffffffd0 & 0xffffffff00000000,0);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      puVar3 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar3 >> 8),3);
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,0x59,
                         &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)pWVar1,(char)iVar2);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,6,0x5a,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return;
}



===== RoleMgr_RecordRoleSwitchMode @ 1c0007c10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RoleMgr_RecordRoleSwitchMode(struct _FDO_CONTEXT * __ptr64,enum
   _URS_ROLE_SWITCH_MODE) */

void __cdecl RoleMgr_RecordRoleSwitchMode(_FDO_CONTEXT *param_1,_URS_ROLE_SWITCH_MODE param_2)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  undefined2 uVar3;
  longlong local_res8;
  undefined1 uVar4;
  undefined8 local_18;
  undefined8 uStack_10;
  
  pWVar1 = param_1->WdfDevice;
  local_res8 = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar2 = (**(code **)(WdfFunctions_01021 + 0x180))(WdfDriverGlobals,pWVar1,1,0x2001f,0,&local_res8)
  ;
  uVar4 = SUB81(pWVar1,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0007d54;
    uVar3 = 0x33;
  }
  else {
    RtlInitUnicodeString(&local_18,L"RoleSwitchMode");
    iVar2 = (**(code **)(WdfFunctions_01021 + 0x7b0))(WdfDriverGlobals,local_res8,&local_18,param_2)
    ;
    if (-1 < iVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x35,
                           &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar4,(char)param_2);
      }
      goto LAB_1c0007d54;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0007d54;
    uVar3 = 0x34;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar3,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar4,(char)iVar2);
LAB_1c0007d54:
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01021 + 0x738))(WdfDriverGlobals);
  }
  return;
}



===== RoleMgr_ReportHardwareEvent @ 1c0007d8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RoleMgr_ReportHardwareEvent(struct _FDO_CONTEXT * __ptr64,enum _URS_HARDWARE_EVENT)
    */

long __cdecl RoleMgr_ReportHardwareEvent(_FDO_CONTEXT *param_1,_URS_HARDWARE_EVENT param_2)

{
  _URS_HARDWARE_EVENT _Var1;
  byte bVar2;
  code *pcVar3;
  undefined4 in_register_00000014;
  WDFDPC__ *pWVar4;
  undefined7 uVar5;
  long lVar6;
  undefined1 uVar7;
  
  pWVar4 = (WDFDPC__ *)CONCAT44(in_register_00000014,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,6,0xd,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  uVar5 = (undefined7)((ulonglong)pWVar4 >> 8);
  uVar7 = SUB81(param_1->WdfDevice,0);
  if (param_2 - UrsHardwareEventDetach < 5) {
    lVar6 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pWVar4 = (WDFDPC__ *)CONCAT71(uVar5,4);
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xf,
                         &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar7,(char)param_2);
    }
    LOCK();
    _Var1 = param_1->HardwareEventToProcess;
    param_1->HardwareEventToProcess = param_2;
    UNLOCK();
    if (_Var1 == UrsHardwareEventNone) {
      bVar2 = KeGetCurrentIrql();
      if (bVar2 < 3) {
        pcVar3 = *(code **)(WdfFunctions_01021 + 0xbe0);
        pWVar4 = (WDFDPC__ *)param_1->RoleChangeWorkItem;
      }
      else {
        pcVar3 = *(code **)(WdfFunctions_01021 + 0x380);
        pWVar4 = param_1->RoleChangeWorkItemLauncherDpc;
      }
      (*pcVar3)(WdfDriverGlobals);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pWVar4 = (WDFDPC__ *)CONCAT71(uVar5,2);
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xe,
                         &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,uVar7,(char)param_2);
    }
    lVar6 = -0x3ffffff3;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,6,0x10,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return lVar6;
}



===== RoleMgr_SetRoleSwitchMode @ 1c0007ef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl RoleMgr_SetRoleSwitchMode(struct _FDO_CONTEXT * __ptr64,enum _URS_ROLE_SWITCH_MODE)
    */

void __cdecl RoleMgr_SetRoleSwitchMode(_FDO_CONTEXT *param_1,_URS_ROLE_SWITCH_MODE param_2)

{
  _URS_ROLE_SWITCH_MODE _Var1;
  undefined4 in_register_00000014;
  WDFWAITLOCK__ *pWVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     CONCAT44(in_register_00000014,param_2),6,0x28,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  (**(code **)(WdfFunctions_01021 + 0x9c8))(WdfDriverGlobals,param_1->RoleChangeLock,0);
  if (param_2 == 5) {
    _Var1 = RoleMgr_GetOemDefaultRoleSwitchMode(param_1);
  }
  else {
    _Var1 = param_2;
  }
  if ((_Var1 == 3) || (_Var1 == 6)) {
    param_1->EnableHardwareEvents = '\x01';
    LOCK();
    if (param_1->HardwareEventToProcess == UrsHardwareEventNone) {
      param_1->HardwareEventToProcess = param_1->LastHardwareEvent;
    }
    UNLOCK();
    RoleMgr_ProcessHardwareEventLoop(param_1);
  }
  else {
    param_1->EnableHardwareEvents = '\0';
    RoleMgr_ProcessRoleSwitchMode(param_1,_Var1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x29,
                       &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)param_1->WdfDevice,
                       (char)_Var1);
  }
  pWVar2 = param_1->RoleChangeLock;
  (**(code **)(WdfFunctions_01021 + 0x9d0))(WdfDriverGlobals);
  if (param_2 == 5) {
    RoleMgr_ClearRoleSwitchModeRecord(param_1);
  }
  else {
    pWVar2 = (WDFWAITLOCK__ *)(ulonglong)_Var1;
    RoleMgr_RecordRoleSwitchMode(param_1,_Var1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,6,0x2a,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return;
}



===== RoleMgr_SetupRole @ 1c0008070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RoleMgr_SetupRole(struct _FDO_CONTEXT * __ptr64,enum _URS_ROLE) */

long __cdecl RoleMgr_SetupRole(_FDO_CONTEXT *param_1,_URS_ROLE param_2)

{
  _PDO_CONFIG *p_Var1;
  int iVar2;
  undefined4 in_register_00000014;
  _PDO_CONFIG *p_Var3;
  _PDO_CONFIG *p_Var4;
  _PDO_CONFIG *local_res8;
  _PDO_CONFIG local_48;
  
  p_Var3 = (_PDO_CONFIG *)CONCAT44(in_register_00000014,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var3,6,0x4d,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  p_Var1 = (_PDO_CONFIG *)param_1->WdfDevice;
  local_res8 = (_PDO_CONFIG *)0x0;
  if (param_2 == UrsRoleNone) {
    iVar2 = 0;
  }
  else {
    local_48.Size = 0x18;
    local_48.EvtPdoPrepareHardware = RoleMgr_EvtPdoPrepareHardware;
    p_Var3 = &local_48;
    local_48.EvtPdoReleaseHardware = RoleMgr_EvtPdoReleaseHardware;
    local_48.Role = param_2;
    iVar2 = Pdo_Create(param_1,p_Var3,(WDFDEVICE__ **)&local_res8);
    p_Var4 = local_res8;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
    else {
      p_Var3 = p_Var1;
      iVar2 = (**(code **)(WdfFunctions_01021 + 0x428))(WdfDriverGlobals,p_Var1,local_res8);
      if (-1 < iVar2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var3,6,0x50,
                              &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)p_Var1,
                              (char)p_Var4,(char)param_2);
        }
        param_1->CurrentRole = param_2;
        goto LAB_1c00081e6;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        p_Var3 = (_PDO_CONFIG *)CONCAT71((int7)((ulonglong)p_Var3 >> 8),2);
        WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x4f,
                            &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)p_Var1,
                            (char)p_Var4,(char)iVar2);
      }
    }
    if (p_Var4 != (_PDO_CONFIG *)0x0) {
      (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
      p_Var3 = p_Var4;
    }
  }
LAB_1c00081e6:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var3,6,0x51,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return iVar2;
}



===== RoleMgr_TeardownCurrentRole @ 1c0008290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RoleMgr_TeardownCurrentRole(struct _FDO_CONTEXT * __ptr64) */

long __cdecl RoleMgr_TeardownCurrentRole(_FDO_CONTEXT *param_1)

{
  undefined4 uVar1;
  int iVar2;
  WDFDEVICE__ *pWVar3;
  longlong lVar4;
  undefined8 in_RDX;
  WDFDEVICE__ *pWVar5;
  WDFDEVICE__ *pWVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,6,0x49,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  pWVar5 = param_1->WdfDevice;
  (**(code **)(WdfFunctions_01021 + 0x430))(WdfDriverGlobals,pWVar5);
  pWVar3 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01021 + 0x438))(WdfDriverGlobals,pWVar5,0,5);
  if (pWVar3 == (WDFDEVICE__ *)0x0) {
    iVar2 = 0;
    (**(code **)(WdfFunctions_01021 + 0x440))(WdfDriverGlobals);
    pWVar6 = pWVar5;
LAB_1c0008364:
    param_1->CurrentRole = UrsRoleNone;
    if (pWVar3 == (WDFDEVICE__ *)0x0) goto LAB_1c00084d2;
  }
  else {
    lVar4 = (**(code **)(WdfFunctions_01021 + 0x650))
                      (WdfDriverGlobals,pWVar3,PTR__WDF_PDO_CONTEXT_TYPE_INFO_1c0011080);
    uVar1 = *(undefined4 *)(lVar4 + 0x1c);
    (**(code **)(WdfFunctions_01021 + 0x668))
              (WdfDriverGlobals,pWVar3,RoleMgr_TeardownCurrentRole,0x4d1,
               "onecore\\drivers\\wdm\\usb\\urs\\urscx\\src\\rolemgr.cpp");
    iVar2 = (**(code **)(WdfFunctions_01021 + 0x6d8))(WdfDriverGlobals,pWVar3);
    pWVar6 = pWVar5;
    (**(code **)(WdfFunctions_01021 + 0x440))(WdfDriverGlobals);
    if (-1 < iVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar6,6,0x4b,
                            &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)pWVar5,
                            (char)pWVar3,(char)uVar1);
      }
      goto LAB_1c0008364;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x4a,
                          &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)pWVar5,(char)pWVar3
                          ,(char)iVar2);
    }
  }
  (**(code **)(WdfFunctions_01021 + 0x670))
            (WdfDriverGlobals,pWVar3,RoleMgr_TeardownCurrentRole,0x4e6,
             "onecore\\drivers\\wdm\\usb\\urs\\urscx\\src\\rolemgr.cpp");
  pWVar6 = pWVar3;
LAB_1c00084d2:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar6,6,0x4c,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return iVar2;
}



===== imp_UrsReportHardwareEvent @ 1c0008530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl imp_UrsReportHardwareEvent(struct _URS_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__ *
   __ptr64,enum _URS_HARDWARE_EVENT) */

void __cdecl
imp_UrsReportHardwareEvent
          (_URS_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,_URS_HARDWARE_EVENT param_3)

{
  long lVar1;
  _FDO_CONTEXT *p_Var2;
  char *pcVar3;
  WDFDEVICE__ *pWVar4;
  
  pWVar4 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,6,10,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  lVar1 = Verifier_VerifyDriverGlobals(param_1);
  if (-1 < lVar1) {
    if (param_3 == UrsHardwareEventNone) {
      pcVar3 = "Client driver is not allowed to report UrsHardwareEventNone";
    }
    else {
      pWVar4 = param_2;
      p_Var2 = (_FDO_CONTEXT *)
               (**(code **)(WdfFunctions_01021 + 0x650))
                         (WdfDriverGlobals,param_2,PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8);
      if (p_Var2->HardwareEventReportingSupported == WdfTrue) {
        pWVar4 = (WDFDEVICE__ *)(ulonglong)param_3;
        if ((p_Var2->DynamicHostOnlyModeEnabled != '\0') &&
           ((param_3 - UrsHardwareEventIdFloat & 0xfffffffd) == 0)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xb,
                               &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,(char)param_2,
                               (char)param_3);
          }
          pWVar4 = (WDFDEVICE__ *)0x1;
        }
        lVar1 = RoleMgr_ReportHardwareEvent(p_Var2,(_URS_HARDWARE_EVENT)pWVar4);
        if (-1 < lVar1) goto LAB_1c0008644;
        pcVar3 = "Client driver has reported an invalid hardware event";
      }
      else {
        pcVar3 = 
        "Client driver has not indicated to the class extension that it supports hardware events. This must be done using UrsSetHardwareEventSupport before it can report any hardware events"
        ;
      }
    }
    Verifier_DbgBreak(pcVar3,(ulong)pWVar4);
  }
LAB_1c0008644:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,6,0xc,
                     &WPP_2b997fc038883d6f1740cf388b023789_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_qLd @ 1c0008694 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2b997fc038883d6f1740cf388b023789_Traceguids,0x4e,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,6,&WPP_2b997fc038883d6f1740cf388b023789_Traceguids,0x4e,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 1c0008788 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== Pdo_AssignIds @ 1c00088d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Pdo_AssignIds(struct _FDO_CONTEXT * __ptr64,enum _URS_ROLE,struct WDFDEVICE_INIT *
   __ptr64) */

long __cdecl Pdo_AssignIds(_FDO_CONTEXT *param_1,_URS_ROLE param_2,WDFDEVICE_INIT *param_3)

{
  _URS_HOST_INTERFACE_TYPE _Var1;
  WDFCOLLECTION__ *pWVar2;
  WDFDEVICE__ *pWVar3;
  _URS_ROLE _Var4;
  uint uVar5;
  int iVar6;
  WDFDEVICE_INIT *pWVar7;
  longlong lVar8;
  WDFDEVICE_INIT *pWVar9;
  WDFDEVICE_INIT *pWVar10;
  uint uVar11;
  int iVar12;
  undefined **ppuVar13;
  undefined2 uVar14;
  WDFDEVICE_INIT *pWVar15;
  undefined1 auStackY_d8 [32];
  undefined1 uVar16;
  WDFDEVICE_INIT *local_98;
  _URS_ROLE local_90;
  WDFDEVICE_INIT *local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  WDFDEVICE_INIT *local_70;
  undefined8 local_68;
  undefined4 *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined2 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_48 = 0x30;
  local_44 = 0;
  local_60 = &local_48;
  local_80 = 0;
  uStack_78 = 0;
  local_68 = 0x60004;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = param_2;
  local_88 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,7,0x2b,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  local_70 = (WDFDEVICE_INIT *)param_1->CompatibleIds;
  pWVar2 = param_1->HardwareIds;
  pWVar3 = param_1->WdfDevice;
  local_98 = (WDFDEVICE_INIT *)0x0;
  uVar5 = (**(code **)(WdfFunctions_01021 + 0x70))(WdfDriverGlobals,pWVar2);
  uVar11 = 0;
  uVar16 = SUB81(pWVar3,0);
  if (uVar5 != 0) {
    do {
      pWVar7 = (WDFDEVICE_INIT *)
               (**(code **)(WdfFunctions_01021 + 0x90))(WdfDriverGlobals,pWVar2,uVar11);
      iVar6 = Pdo_TransformId(param_1,(WDFSTRING__ *)pWVar7,param_2,(WDFSTRING__ **)&local_98);
      pWVar10 = local_98;
      if (iVar6 < 0) goto LAB_1c0008ebb;
      (**(code **)(WdfFunctions_01021 + 0x9a8))(WdfDriverGlobals,local_98,&local_80);
      pWVar7 = local_88;
      iVar6 = (**(code **)(WdfFunctions_01021 + 0x6b0))(WdfDriverGlobals,local_88,&local_80);
      if (iVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0008bb6;
        uVar14 = 0x2c;
        goto LAB_1c0008b90;
      }
      (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals,pWVar10);
      _Var4 = local_90;
      local_98 = (WDFDEVICE_INIT *)0x0;
      uVar11 = uVar11 + 1;
      param_2 = local_90;
    } while (uVar11 < uVar5);
    pWVar7 = (WDFDEVICE_INIT *)(**(code **)(WdfFunctions_01021 + 0x98))(WdfDriverGlobals,pWVar2);
    iVar6 = Pdo_TransformId(param_1,(WDFSTRING__ *)pWVar7,_Var4,(WDFSTRING__ **)&local_98);
    pWVar9 = local_98;
    if (iVar6 < 0) {
LAB_1c0008ebb:
      pWVar9 = local_98;
    }
    else {
      (**(code **)(WdfFunctions_01021 + 0x9a8))(WdfDriverGlobals,local_98,&local_80);
      pWVar15 = local_88;
      pWVar7 = local_88;
      iVar6 = (**(code **)(WdfFunctions_01021 + 0x6a0))(WdfDriverGlobals,local_88,&local_80);
      if (-1 < iVar6) {
        (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals,pWVar9);
        local_98 = (WDFDEVICE_INIT *)0x0;
        param_2 = local_90;
        goto LAB_1c0008beb;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pWVar7 = (WDFDEVICE_INIT *)CONCAT71((int7)((ulonglong)pWVar7 >> 8),2);
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x2d,
                           &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar16,(char)iVar6);
      }
    }
LAB_1c0008bb9:
    pWVar10 = pWVar7;
    if (pWVar9 != (WDFDEVICE_INIT *)0x0) {
      (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
      pWVar10 = pWVar9;
    }
    goto LAB_1c0008e1e;
  }
  pWVar15 = local_88;
LAB_1c0008beb:
  pWVar10 = pWVar15;
  iVar6 = (**(code **)(WdfFunctions_01021 + 0x6a8))(WdfDriverGlobals,pWVar15,&local_68);
  if (iVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar6;
    }
    uVar14 = 0x2e;
LAB_1c0008c2c:
    pWVar10 = (WDFDEVICE_INIT *)CONCAT71((int7)((ulonglong)pWVar10 >> 8),2);
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar14,
                       &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar16,(char)iVar6);
    goto LAB_1c0008e1e;
  }
  lVar8 = (**(code **)(WdfFunctions_01021 + 0x610))(WdfDriverGlobals,param_1->DeviceInformation,0);
  pWVar10 = (WDFDEVICE_INIT *)0x1;
  if (param_2 == UrsRoleHost) {
    _Var1 = (param_1->Config).HostInterfaceType;
    if (_Var1 == UrsHostInterfaceTypeEhci) {
      if (*(int *)(lVar8 + 4) == 1) {
        ppuVar13 = &EhciAcpiCompatIds;
      }
      else {
        if (*(int *)(lVar8 + 4) != 2) goto LAB_1c0008d1b;
        ppuVar13 = &EhciPciCompatIds;
      }
    }
    else {
      if (_Var1 != UrsHostInterfaceTypeXhci) goto LAB_1c0008d1b;
      if (*(int *)(lVar8 + 4) == 1) {
        ppuVar13 = &XhciAcpiCompatIds;
      }
      else {
        if (*(int *)(lVar8 + 4) != 2) goto LAB_1c0008d1b;
        ppuVar13 = &XhciPciCompatIds;
      }
    }
    iVar12 = 1;
    do {
      RtlInitUnicodeString(&local_58,*ppuVar13);
      pWVar10 = pWVar15;
      iVar6 = (**(code **)(WdfFunctions_01021 + 0x6b8))(WdfDriverGlobals,pWVar15,&local_58);
      if (iVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar6;
        }
        uVar14 = 0x2f;
        goto LAB_1c0008c2c;
      }
      ppuVar13 = ppuVar13 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
LAB_1c0008d1b:
  pWVar7 = local_70;
  if (local_70 != (WDFDEVICE_INIT *)0x0) {
    pWVar10 = local_70;
    uVar5 = (**(code **)(WdfFunctions_01021 + 0x70))(WdfDriverGlobals);
    uVar11 = 0;
    if (uVar5 != 0) {
LAB_1c0008d4f:
      pWVar7 = (WDFDEVICE_INIT *)
               (**(code **)(WdfFunctions_01021 + 0x90))(WdfDriverGlobals,pWVar7,uVar11);
      iVar6 = Pdo_TransformId(param_1,(WDFSTRING__ *)pWVar7,local_90,(WDFSTRING__ **)&local_98);
      pWVar10 = local_98;
      if (-1 < iVar6) {
        (**(code **)(WdfFunctions_01021 + 0x9a8))(WdfDriverGlobals,local_98,&local_80);
        pWVar7 = pWVar15;
        iVar6 = (**(code **)(WdfFunctions_01021 + 0x6b8))(WdfDriverGlobals,pWVar15,&local_80);
        if (-1 < iVar6) goto code_r0x0001c0008ddc;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar14 = 0x30;
LAB_1c0008b90:
          pWVar7 = (WDFDEVICE_INIT *)CONCAT71((int7)((ulonglong)pWVar7 >> 8),2);
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar14,
                             &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar16,(char)iVar6);
        }
LAB_1c0008bb6:
        pWVar9 = pWVar10;
        goto LAB_1c0008bb9;
      }
      goto LAB_1c0008ebb;
    }
  }
LAB_1c0008e1e:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar10,7,0x31,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return iVar6;
code_r0x0001c0008ddc:
  (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
  local_98 = (WDFDEVICE_INIT *)0x0;
  uVar11 = uVar11 + 1;
  pWVar7 = local_70;
  if (uVar5 <= uVar11) goto LAB_1c0008e1e;
  goto LAB_1c0008d4f;
}



===== Pdo_Create @ 1c0008ed8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Pdo_Create(struct _FDO_CONTEXT * __ptr64,struct _PDO_CONFIG * __ptr64,struct
   WDFDEVICE__ * __ptr64 * __ptr64) */

long __cdecl Pdo_Create(_FDO_CONTEXT *param_1,_PDO_CONFIG *param_2,WDFDEVICE__ **param_3)

{
  _URS_ROLE _Var1;
  _func___cdecl_long__FDO_CONTEXT_ptr__URS_ROLE *p_Var2;
  _URS_ROLE _Var3;
  int iVar4;
  undefined4 uVar5;
  longlong lVar6;
  _PDO_CONTEXT *p_Var7;
  URSIORESLIST__ *pUVar8;
  undefined8 uVar9;
  WDFDEVICE_INIT *pWVar10;
  undefined2 uVar11;
  undefined1 auStackY_1d8 [32];
  WDFDEVICE_INIT *local_190;
  WDFDEVICE_INIT *local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined *local_150;
  undefined4 local_148 [4];
  code *local_138;
  undefined4 local_108 [10];
  code *local_e0;
  code *local_d8;
  code *local_a8;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_150 = (undefined *)0x0;
  local_180 = 0;
  uStack_178 = 0;
  local_170 = 0;
  uStack_168 = 0;
  local_160 = 0;
  uStack_158 = 0;
  memset(local_108,0,0x90);
  uVar9 = 0;
  memset(local_148,0,0x40);
  local_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,7,0xe,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  pWVar10 = (WDFDEVICE_INIT *)param_1->WdfDevice;
  _Var1 = param_2->Role;
  local_188 = (WDFDEVICE_INIT *)0x0;
  local_190 = (WDFDEVICE_INIT *)(**(code **)(WdfFunctions_01021 + 0x690))(WdfDriverGlobals,pWVar10);
  if (local_190 == (WDFDEVICE_INIT *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0xf,
                        &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)pWVar10);
    }
    iVar4 = -0x3fffff66;
    goto LAB_1c0009367;
  }
  (**(code **)(WdfFunctions_01021 + 0x210))(WdfDriverGlobals,local_190,4);
  local_a8 = Pdo_EvtDeviceSurpriseRemoval;
  local_e0 = Pdo_EvtDevicePrepareHardware;
  local_d8 = Pdo_EvtDeviceReleaseHardware;
  local_108[0] = 0x90;
  (**(code **)(WdfFunctions_01021 + 0x1b8))(WdfDriverGlobals,local_190,local_108);
  local_138 = Pdo_EvtDeviceResourceRequirementsQuery;
  local_148[0] = 0x40;
  (**(code **)(WdfFunctions_01021 + 0x698))(WdfDriverGlobals,local_190,local_148);
  iVar4 = Pdo_AssignIds(param_1,_Var1,local_190);
  if (iVar4 < 0) goto LAB_1c0009367;
  lVar6 = (**(code **)(WdfFunctions_01021 + 0xc60))(WdfDriverGlobals,local_190);
  if (lVar6 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x10,
                        &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)pWVar10);
    }
    iVar4 = -0x3fffff66;
    goto LAB_1c0009367;
  }
  iVar4 = (**(code **)(WdfFunctions_01021 + 0xc68))
                    (WdfDriverGlobals,lVar6,Pdo_EvtDeviceWdmIrpPnPPreprocess,0x1b);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0009367;
    uVar11 = 0x11;
    pWVar10 = local_188;
  }
  else {
    local_180 = CONCAT44(local_180._4_4_,0x38);
    uStack_168 = 0x100000001;
    local_150 = PTR__WDF_PDO_CONTEXT_TYPE_INFO_1c0011080;
    iVar4 = (**(code **)(WdfFunctions_01021 + 600))
                      (WdfDriverGlobals,&local_190,&local_180,&local_188);
    if (-1 < iVar4) {
      p_Var7 = (_PDO_CONTEXT *)
               (**(code **)(WdfFunctions_01021 + 0x650))
                         (WdfDriverGlobals,local_188,PTR__WDF_PDO_CONTEXT_TYPE_INFO_1c0011080);
      p_Var7->Signature = UrsCxSigPdoContext;
      p_Var7->WdfDevice = (WDFDEVICE__ *)local_188;
      p_Var7->ParentFdoContext = param_1;
      _Var3 = param_2->Role;
      p_Var2 = param_2->EvtPdoPrepareHardware;
      (p_Var7->Config).Size = param_2->Size;
      (p_Var7->Config).Role = _Var3;
      (p_Var7->Config).EvtPdoPrepareHardware = p_Var2;
      (p_Var7->Config).EvtPdoReleaseHardware = param_2->EvtPdoReleaseHardware;
      if (_Var1 == UrsRoleHost) {
        pUVar8 = param_1->HostRoleResources;
LAB_1c00092ca:
        p_Var7->IoResourceList = pUVar8;
      }
      else if (_Var1 == UrsRoleFunction) {
        pUVar8 = param_1->FunctionRoleResources;
        goto LAB_1c00092ca;
      }
      local_78 = 0x30;
      uStack_74 = 2;
      uStack_70 = 2;
      uStack_6c = 2;
      local_68 = 2;
      uStack_60 = 0x200000002;
      local_58 = 0x200000002;
      if (_Var1 == UrsRoleHost) {
        uStack_50 = 0xffffffff00000000;
      }
      else {
        uVar5 = 0xffffffff;
        if (_Var1 == UrsRoleFunction) {
          uVar5 = 1;
        }
        uStack_50 = CONCAT44(0xffffffff,uVar5);
      }
      uStack_64 = 0;
      (**(code **)(WdfFunctions_01021 + 0x298))(WdfDriverGlobals,0x200000002,&local_78);
      iVar4 = Pdo_InitializeQueues(p_Var7);
      if (-1 < iVar4) {
        *param_3 = (WDFDEVICE__ *)local_188;
      }
      goto LAB_1c0009367;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0009367;
    uVar11 = 0x12;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar11,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)pWVar10,(char)iVar4);
LAB_1c0009367:
  pWVar10 = local_190;
  if (local_190 != (WDFDEVICE_INIT *)0x0) {
    (**(code **)(WdfFunctions_01021 + 0x1b0))(WdfDriverGlobals);
    local_190 = (WDFDEVICE_INIT *)0x0;
  }
  if ((iVar4 < 0) && (pWVar10 = local_188, local_188 != (WDFDEVICE_INIT *)0x0)) {
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
    local_188 = (WDFDEVICE_INIT *)0x0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar10,7,0x13,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return iVar4;
}



===== Pdo_DefaultQueueEvtIoInternalDeviceControl @ 1c0009420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Pdo_DefaultQueueEvtIoInternalDeviceControl(struct WDFQUEUE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
Pdo_DefaultQueueEvtIoInternalDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  undefined1 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x17;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x17,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01021 + 0x4e8))(WdfDriverGlobals,param_1);
  if (param_5 == 0x2a0004) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = 0x18;
      WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x2a0004,7,0x18,
                          &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar1,(char)param_2,4);
    }
    Pdo_InternalIoctlGetDeviceInformation(param_1,param_2,param_3,param_4);
  }
  else if (param_5 == 0x2a0018) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = 0x19;
      WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x2a0018,7,0x19,
                          &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar1,(char)param_2,0x18)
      ;
    }
    Pdo_InternalIoctlIsFakeLoadInProgress(param_1,param_2,param_3,param_4);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,0x1a,
                         &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar1,(char)param_5);
    }
    (**(code **)(WdfFunctions_01021 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x1b,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return;
}



===== Pdo_EvtDevicePrepareHardware @ 1c00095f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Pdo_EvtDevicePrepareHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
Pdo_EvtDevicePrepareHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  _FDO_CONTEXT *p_Var1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x3d,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PDO_CONTEXT_TYPE_INFO_1c0011080);
  p_Var1 = *(_FDO_CONTEXT **)(lVar3 + 0x10);
  uVar4 = (ulonglong)*(uint *)(lVar3 + 0x1c);
  iVar2 = (**(code **)(lVar3 + 0x20))(p_Var1);
  if (-1 < iVar2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = CONCAT71((int7)(uVar4 >> 8),4);
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x3e,
                        &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)param_1);
    }
    if (p_Var1->FakeLoadUnloadInProgress != '\0') {
      Fdo_FakeUsbFunctionSequenceUnload(p_Var1);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,7,0x3f,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return iVar2;
}



===== Pdo_EvtDeviceReleaseHardware @ 1c0009720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Pdo_EvtDeviceReleaseHardware(struct WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ *
   __ptr64) */

long __cdecl Pdo_EvtDeviceReleaseHardware(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  _FDO_CONTEXT *p_Var1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x40,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PDO_CONTEXT_TYPE_INFO_1c0011080);
  p_Var1 = *(_FDO_CONTEXT **)(lVar3 + 0x10);
  uVar4 = (ulonglong)*(uint *)(lVar3 + 0x1c);
  iVar2 = (**(code **)(lVar3 + 0x28))(p_Var1);
  if (-1 < iVar2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = CONCAT71((int7)(uVar4 >> 8),4);
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x41,
                        &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)param_1);
    }
    if (p_Var1->FakeLoadUnloadInProgress != '\0') {
      Fdo_FakeUsbFunctionSequenceEnd(p_Var1);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,7,0x42,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return iVar2;
}



===== Pdo_EvtDeviceResourceRequirementsQuery @ 1c0009850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Pdo_EvtDeviceResourceRequirementsQuery(struct WDFDEVICE__ * __ptr64,struct
   WDFIORESREQLIST__ * __ptr64) */

long __cdecl Pdo_EvtDeviceResourceRequirementsQuery(WDFDEVICE__ *param_1,WDFIORESREQLIST__ *param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  WDFIORESREQLIST__ *pWVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  WDFIORESREQLIST__ *local_res18;
  
  local_res18 = (WDFIORESREQLIST__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x25,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PDO_CONTEXT_TYPE_INFO_1c0011080);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x26,
                      &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)param_1);
  }
  pWVar5 = *(WDFIORESREQLIST__ **)(lVar3 + 0x30);
  uVar1 = (**(code **)(WdfFunctions_01021 + 0x70))(WdfDriverGlobals);
  if (uVar1 == 0) {
    iVar2 = 0;
    param_2 = pWVar5;
  }
  else {
    pWVar5 = param_2;
    iVar2 = (**(code **)(WdfFunctions_01021 + 0x930))(WdfDriverGlobals,param_2,0,&local_res18);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar8 = 0x27;
    }
    else {
      uVar6 = 0;
      if (uVar1 != 0) {
        do {
          lVar4 = (**(code **)(WdfFunctions_01021 + 0x90))
                            (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x30),uVar6);
          if (lVar4 == 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = (**(code **)(WdfFunctions_01021 + 0x610))(WdfDriverGlobals,lVar4,0);
          }
          pWVar5 = local_res18;
          iVar2 = (**(code **)(WdfFunctions_01021 + 0x938))(WdfDriverGlobals,local_res18,uVar7);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return iVar2;
            }
            uVar8 = 0x28;
            goto LAB_1c0009975;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar1);
      }
      iVar2 = (**(code **)(WdfFunctions_01021 + 0x900))(WdfDriverGlobals,param_2,local_res18);
      if (-1 < iVar2) goto LAB_1c0009a81;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar8 = 0x29;
      pWVar5 = param_2;
    }
LAB_1c0009975:
    param_2 = (WDFIORESREQLIST__ *)CONCAT71((int7)((ulonglong)pWVar5 >> 8),2);
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar8,
                       &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)param_1,(char)iVar2);
  }
LAB_1c0009a81:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x2a,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return iVar2;
}



===== Pdo_EvtDeviceSurpriseRemoval @ 1c0009ae0 =====

/* void __cdecl Pdo_EvtDeviceSurpriseRemoval(struct WDFDEVICE__ * __ptr64) */

void __cdecl Pdo_EvtDeviceSurpriseRemoval(WDFDEVICE__ *param_1)

{
  undefined1 in_DL;
  undefined1 uVar1;
  undefined7 in_register_00000011;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       CONCAT71(in_register_00000011,in_DL),7,0x3a,
                       &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar1 = 4;
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x3b,
                        &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)param_1);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                         CONCAT71(in_register_00000011,uVar1),7,0x3c,
                         &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
      }
    }
  }
  return;
}



===== Pdo_EvtDeviceWdmIrpPnPPreprocess @ 1c0009bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Pdo_EvtDeviceWdmIrpPnPPreprocess(struct WDFDEVICE__ * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl Pdo_EvtDeviceWdmIrpPnPPreprocess(WDFDEVICE__ *param_1,_IRP *param_2,void *param_3)

{
  void **ppvVar1;
  undefined1 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,10,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  puVar2 = (param_2->Tail).Apc.SystemArgument1;
  iVar8 = (param_2->IoStatus).field0_0x0.Status;
  plVar3 = *(longlong **)(puVar2 + 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if ((iVar8 == 0) || ((*plVar3 == 0x47db0afb70211b0e && (plVar3[1] == 0x7a4942f80b41c1af)))) {
    param_2->CurrentLocation = param_2->CurrentLocation + '\x01';
    ppvVar1 = &(param_2->Tail).Apc.SystemArgument1;
    *ppvVar1 = (void *)((longlong)*ppvVar1 + 0x48);
    iVar8 = (**(code **)(WdfFunctions_01021 + 0xc88))(WdfDriverGlobals,param_1,param_2,param_3);
  }
  else {
    (**(code **)(WdfFunctions_01021 + 0x650))
              (WdfDriverGlobals,param_1,PTR__WDF_PDO_CONTEXT_TYPE_INFO_1c0011080);
    uVar10 = (**(code **)(WdfFunctions_01021 + 0xf8))(WdfDriverGlobals);
    lVar11 = IoGetAttachedDeviceReference(uVar10);
    lVar12 = IoAllocateIrp(*(undefined1 *)(lVar11 + 0x4c));
    if (lVar12 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0xc,
                          &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)param_1);
      }
      iVar8 = -0x3fffff66;
      (param_2->IoStatus).field0_0x0.Status = -0x3fffff66;
    }
    else {
      lVar4 = *(longlong *)(lVar12 + 0xb8);
      *(undefined4 *)(lVar12 + 0x30) = 0xc00000bb;
      *(undefined1 *)(lVar4 + -0x48) = *puVar2;
      *(undefined1 *)(lVar4 + -0x47) = puVar2[1];
      uVar5 = *(undefined4 *)(puVar2 + 0xc);
      uVar6 = *(undefined4 *)(puVar2 + 0x10);
      uVar7 = *(undefined4 *)(puVar2 + 0x14);
      *(undefined4 *)(lVar4 + -0x40) = *(undefined4 *)(puVar2 + 8);
      *(undefined4 *)(lVar4 + -0x3c) = uVar5;
      *(undefined4 *)(lVar4 + -0x38) = uVar6;
      *(undefined4 *)(lVar4 + -0x34) = uVar7;
      uVar5 = *(undefined4 *)(puVar2 + 0x1c);
      uVar6 = *(undefined4 *)(puVar2 + 0x20);
      uVar7 = *(undefined4 *)(puVar2 + 0x24);
      *(undefined4 *)(lVar4 + -0x30) = *(undefined4 *)(puVar2 + 0x18);
      *(undefined4 *)(lVar4 + -0x2c) = uVar5;
      *(undefined4 *)(lVar4 + -0x28) = uVar6;
      *(undefined4 *)(lVar4 + -0x24) = uVar7;
      *(ulong64 *)(lVar12 + 0x38) = (param_2->IoStatus).Information;
      iVar9 = IoSynchronousCallDriver(lVar11);
      if (iVar9 != -0x3fffff45) {
        iVar8 = iVar9;
      }
      lVar4 = *(longlong *)(lVar12 + 0xb8);
      uVar5 = *(undefined4 *)(lVar4 + -0x3c);
      uVar6 = *(undefined4 *)(lVar4 + -0x38);
      uVar7 = *(undefined4 *)(lVar4 + -0x34);
      *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(lVar4 + -0x40);
      *(undefined4 *)(puVar2 + 0xc) = uVar5;
      *(undefined4 *)(puVar2 + 0x10) = uVar6;
      *(undefined4 *)(puVar2 + 0x14) = uVar7;
      uVar5 = *(undefined4 *)(lVar4 + -0x2c);
      uVar6 = *(undefined4 *)(lVar4 + -0x28);
      uVar7 = *(undefined4 *)(lVar4 + -0x24);
      *(undefined4 *)(puVar2 + 0x18) = *(undefined4 *)(lVar4 + -0x30);
      *(undefined4 *)(puVar2 + 0x1c) = uVar5;
      *(undefined4 *)(puVar2 + 0x20) = uVar6;
      *(undefined4 *)(puVar2 + 0x24) = uVar7;
      (param_2->IoStatus).field0_0x0.Status = iVar8;
      (param_2->IoStatus).Information = *(ulong64 *)(lVar12 + 0x38);
      IoFreeIrp(lVar12);
    }
    param_1 = (WDFDEVICE__ *)0x0;
    IofCompleteRequest(param_2);
    ObfDereferenceObject(lVar11);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,7,0xd,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return iVar8;
}



===== Pdo_InitializeQueues @ 1c0009e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Pdo_InitializeQueues(struct _PDO_CONTEXT * __ptr64) */

long __cdecl Pdo_InitializeQueues(_PDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  undefined8 in_RDX;
  WDFDEVICE__ *pWVar3;
  undefined4 local_68;
  undefined8 local_64;
  undefined1 local_5b;
  code *local_38;
  undefined4 local_18;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,7,0x14,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  pWVar1 = param_1->WdfDevice;
  memset(&local_68,0,0x60);
  local_18 = 0xffffffff;
  local_38 = Pdo_DefaultQueueEvtIoInternalDeviceControl;
  local_68 = 0x60;
  local_5b = 1;
  local_64 = 2;
  pWVar3 = pWVar1;
  iVar2 = (**(code **)(WdfFunctions_01021 + 0x4c0))(WdfDriverGlobals,pWVar1,&local_68,0,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    pWVar3 = (WDFDEVICE__ *)CONCAT71((int7)((ulonglong)pWVar3 >> 8),2);
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x15,
                       &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)pWVar1,(char)iVar2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,7,0x16,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return iVar2;
}



===== Pdo_InternalIoctlGetDeviceInformation @ 1c0009fb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Pdo_InternalIoctlGetDeviceInformation(struct WDFQUEUE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
Pdo_InternalIoctlGetDeviceInformation
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint *_Src;
  WDFREQUEST__ *pWVar5;
  ulonglong _Size;
  uint *local_res20;
  undefined1 uVar6;
  
  local_res20 = (uint *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x1c,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  uVar3 = (**(code **)(WdfFunctions_01021 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_PDO_CONTEXT_TYPE_INFO_1c0011080);
  _Src = (uint *)(**(code **)(WdfFunctions_01021 + 0x610))
                           (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0x60),0);
  uVar1 = *_Src;
  _Size = (ulonglong)uVar1;
  uVar6 = (undefined1)uVar3;
  if (param_3 < 8) {
    pWVar5 = param_2;
    (**(code **)(WdfFunctions_01021 + 0x898))(WdfDriverGlobals,param_2,0);
    iVar2 = -0x3fffffdd;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a231;
    WPP_RECORDER_SF_qPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar5,7,0x1d,
                        &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar6,(char)param_3,
                        (char)uVar1);
    iVar2 = -0x3fffffdd;
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01021 + 0x870))(WdfDriverGlobals,param_2,8,&local_res20,0);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a231;
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x1e,
                         &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar6,(char)iVar2);
    }
    else {
      *local_res20 = uVar1;
      local_res20[1] = _Src[1];
      if (param_3 < _Size) {
        (**(code **)(WdfFunctions_01021 + 0x898))(WdfDriverGlobals,param_2,8);
        iVar2 = -0x7ffffffb;
      }
      else {
        memmove(local_res20,_Src,_Size);
        (**(code **)(WdfFunctions_01021 + 0x898))(WdfDriverGlobals,param_2,_Size);
        iVar2 = 0;
      }
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x1f,
                        &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar6,(char)param_2,
                        (char)iVar2);
  }
LAB_1c000a231:
  (**(code **)(WdfFunctions_01021 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x20,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return;
}



===== Pdo_InternalIoctlIsFakeLoadInProgress @ 1c000a2a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Pdo_InternalIoctlIsFakeLoadInProgress(struct WDFQUEUE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
Pdo_InternalIoctlIsFakeLoadInProgress
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 *local_res20;
  
  local_res20 = (undefined1 *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x21,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01021 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_PDO_CONTEXT_TYPE_INFO_1c0011080);
  lVar3 = *(longlong *)(lVar3 + 0x10);
  if (param_3 == 0) {
    iVar1 = -0x3fffffdd;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01021 + 0x870))(WdfDriverGlobals,param_2,1,&local_res20,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a442;
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x22,
                         &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)uVar2,(char)iVar1);
    }
    else {
      *local_res20 = *(undefined1 *)(lVar3 + 0x88);
      (**(code **)(WdfFunctions_01021 + 0x898))(WdfDriverGlobals,param_2,1);
      iVar1 = 0;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x23,
                        &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,(char)uVar2,(char)param_2,
                        (char)iVar1);
  }
LAB_1c000a442:
  (**(code **)(WdfFunctions_01021 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x24,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return;
}



===== Pdo_TransformId @ 1c000a4b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Pdo_TransformId(struct _FDO_CONTEXT * __ptr64,struct WDFSTRING__ * __ptr64,enum
   _URS_ROLE,struct WDFSTRING__ * __ptr64 * __ptr64) */

long __cdecl
Pdo_TransformId(_FDO_CONTEXT *param_1,WDFSTRING__ *param_2,_URS_ROLE param_3,WDFSTRING__ **param_4)

{
  wchar_t wVar1;
  WDFDEVICE__ *pWVar2;
  short sVar3;
  ushort uVar4;
  long lVar5;
  wchar_t *pwVar6;
  ushort uVar7;
  ushort uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined2 uVar11;
  wchar_t *pwVar12;
  longlong lVar13;
  wchar_t *pwVar14;
  wchar_t *pwVar15;
  WDFSTRING__ *local_res8;
  undefined1 uVar16;
  undefined8 local_48;
  wchar_t *pwStack_40;
  _UNICODE_STRING local_38;
  
  local_48 = 0;
  pwStack_40 = (wchar_t *)0x0;
  local_res8 = (WDFSTRING__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,7,0x32,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  pWVar2 = param_1->WdfDevice;
  pwVar15 = L"&HOST";
  local_38.Length = 0;
  local_38.MaximumLength = 0;
  local_38._4_4_ = 0;
  local_38.Buffer = (wchar_t *)0x0;
  if (param_3 != UrsRoleHost) {
    pwVar15 = L"&FUNCTION";
  }
  (**(code **)(WdfFunctions_01021 + 0x9a8))(WdfDriverGlobals,param_2,&local_48);
  sVar3 = 0xc;
  if (param_3 != UrsRoleHost) {
    sVar3 = 0x14;
  }
  uVar4 = sVar3 + 8 + (ushort)local_48;
  uVar10 = (uint)uVar4;
  pwVar6 = (wchar_t *)ExAllocatePool2(0x100,uVar4,0x58737255);
  uVar16 = SUB81(pWVar2,0);
  if (pwVar6 == (wchar_t *)0x0) {
    lVar5 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x33,
                         &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar16,(char)uVar4);
    }
    goto LAB_1c000a5eb;
  }
  uVar7 = (ushort)local_48 >> 1;
  uVar8 = 0;
  local_38.MaximumLength = uVar4;
  local_38.Buffer = pwVar6;
  if (uVar7 != 0) {
    do {
      if (pwStack_40[uVar8] == L'\\') break;
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar7);
    if (uVar7 <= uVar8) goto LAB_1c000a777;
    local_48 = CONCAT62(CONCAT42(local_48._4_4_,local_48._2_2_ + uVar8 * -2),
                        (ushort)local_48 + uVar8 * -2);
    pwStack_40 = pwStack_40 + uVar8;
    lVar5 = RtlUnicodeStringCatString(&local_38,(ushort *)L"URS");
    if (-1 < lVar5) {
      uVar10 = (uint)local_38.MaximumLength;
      goto LAB_1c000a777;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a5eb;
    uVar11 = 0x34;
    goto LAB_1c000a73b;
  }
LAB_1c000a777:
  if ((((ulonglong)local_38.Length & 1) == 0) && ((uVar10 & 1) == 0)) {
    uVar4 = (ushort)uVar10;
    if (((uVar4 < local_38.Length) || (uVar4 == 0xffff)) ||
       ((local_38.Buffer == (wchar_t *)0x0 && ((local_38.Length != 0 || (uVar4 != 0))))))
    goto LAB_1c000a90f;
    uVar4 = local_38.Length >> 1;
    if (((((ushort)local_48 & 1) != 0) ||
        ((((local_48 & 0x10000) != 0 || (local_48._2_2_ < (ushort)local_48)) ||
         (local_48._2_2_ == 0xffff)))) ||
       ((pwStack_40 == (wchar_t *)0x0 && (((ushort)local_48 != 0 || (local_48._2_2_ != 0))))))
    goto LAB_1c000a90f;
    pwVar14 = local_38.Buffer + uVar4;
    uVar9 = (ulonglong)((ushort)local_48 >> 1);
    lVar5 = 0;
    sVar3 = 0;
    pwVar12 = pwStack_40;
    for (lVar13 = (ulonglong)(uVar10 >> 1) - (ulonglong)uVar4; lVar13 != 0; lVar13 = lVar13 + -1) {
      if (uVar9 == 0) goto LAB_1c000a855;
      wVar1 = *pwVar12;
      pwVar12 = pwVar12 + 1;
      *pwVar14 = wVar1;
      uVar9 = uVar9 - 1;
      sVar3 = sVar3 + 1;
      pwVar14 = pwVar14 + 1;
    }
    lVar5 = 0;
    if (uVar9 != 0) {
      lVar5 = -0x7ffffffb;
    }
LAB_1c000a855:
    local_38.Length = (uVar4 + sVar3) * 2;
    if (lVar5 < 0) goto LAB_1c000a916;
    lVar5 = RtlUnicodeStringCatString(&local_38,(ushort *)pwVar15);
    if (lVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a5eb;
      uVar11 = 0x36;
      goto LAB_1c000a73b;
    }
    lVar5 = (**(code **)(WdfFunctions_01021 + 0x9a0))(WdfDriverGlobals,&local_38,0,&local_res8);
    if (lVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0x37;
        goto LAB_1c000a73b;
      }
      goto LAB_1c000a5eb;
    }
    *param_4 = local_res8;
  }
  else {
LAB_1c000a90f:
    lVar5 = -0x3ffffff3;
LAB_1c000a916:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0x35;
LAB_1c000a73b:
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar11,
                         &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,uVar16,(char)lVar5);
    }
LAB_1c000a5eb:
    (**(code **)(WdfFunctions_01021 + 0x9a8))(WdfDriverGlobals,param_2,&local_48);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if (pwVar6 == (wchar_t *)0x0) goto LAB_1c000a650;
  }
  param_2 = (WDFSTRING__ *)0x58737255;
  ExFreePoolWithTag(pwVar6);
LAB_1c000a650:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x39,
                     &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids);
  }
  return lVar5;
}



===== RtlUnicodeStringCatString @ 1c000a944 =====

/* long __cdecl RtlUnicodeStringCatString(struct _UNICODE_STRING * __ptr64,unsigned short const *
   __ptr64) */

long __cdecl RtlUnicodeStringCatString(_UNICODE_STRING *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  long lVar4;
  wchar_t *pwVar5;
  longlong lVar6;
  longlong lVar7;
  
  uVar1 = param_1->Length;
  if ((((((uVar1 & 1) != 0) || (uVar2 = param_1->MaximumLength, (uVar2 & 1) != 0)) ||
       (uVar2 < uVar1)) || (uVar2 == 0xffff)) ||
     ((lVar4 = 0, param_1->Buffer == (wchar_t *)0x0 && ((uVar1 != 0 || (uVar2 != 0)))))) {
    return -0x3ffffff3;
  }
  lVar7 = 0x7fff;
  uVar1 = uVar1 >> 1;
  pwVar5 = param_1->Buffer + uVar1;
  sVar3 = 0;
  lVar6 = (ulonglong)(param_1->MaximumLength >> 1) - (ulonglong)uVar1;
  if (lVar6 != 0) {
    do {
      if (lVar7 == 0) goto LAB_1c000a9fa;
      if (*param_2 == L'\0') break;
      *pwVar5 = *param_2;
      param_2 = param_2 + 1;
      pwVar5 = pwVar5 + 1;
      lVar7 = lVar7 + -1;
      sVar3 = sVar3 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    if ((lVar6 != 0) || (lVar7 == 0)) goto LAB_1c000a9fa;
  }
  lVar4 = 0;
  if (*param_2 != L'\0') {
    lVar4 = -0x7ffffffb;
  }
LAB_1c000a9fa:
  param_1->Length = (uVar1 + sVar3) * 2;
  return lVar4;
}



===== WPP_RECORDER_SF_qZd @ 1c000aa20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qZd(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000040;
  
  pwVar3 = L"NULL";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
  goto LAB_1c000ab07;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_1c000aa94:
    pwVar4 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 == L'\0') goto LAB_1c000aa94;
    pwVar4 = *(wchar_t **)(in_stack_00000038 + 4);
  }
  pwVar2 = in_stack_00000038;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,0x38,&uStack0000000000000030,8,pwVar2,
             2,pwVar4,wVar1,&uStack0000000000000040,4,0);
LAB_1c000ab07:
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
  WppAutoLogTrace(param_1,2,7,&WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,0x38,
                  &uStack0000000000000030,8,in_stack_00000038,2,pwVar3,wVar1,&uStack0000000000000040
                  ,4,0);
  return;
}



===== WPP_RECORDER_SF_q_guid_ @ 1c000abb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q_guid_(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,0xb,&uStack0000000000000030,8);
  }
  WppAutoLogTrace(param_1,5,7,&WPP_cb312262d9503b8ed17c5b50d6870eba_Traceguids,0xb,
                  &uStack0000000000000030,8);
  return;
}



===== VBus_Disable @ 1c000ac8c =====

/* long __cdecl VBus_Disable(struct _FDO_CONTEXT * __ptr64) */

long __cdecl VBus_Disable(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  long lVar2;
  undefined8 in_RDX;
  undefined7 uVar4;
  undefined8 uVar3;
  undefined1 uVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,8,0xe,
                     &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids);
  }
  pWVar1 = param_1->WdfDevice;
  uVar3 = 0;
  lVar2 = VBus_QcPepPstateRequest(param_1,0);
  uVar4 = (undefined7)((ulonglong)uVar3 >> 8);
  uVar5 = SUB81(pWVar1,0);
  if (lVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    uVar3 = CONCAT71(uVar4,2);
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0xf,
                       &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids,uVar5,(char)lVar2);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    uVar3 = CONCAT71(uVar4,4);
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,8,0x10,
                      &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids,uVar5);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,8,0x11,
                     &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids);
  }
  return lVar2;
}



===== VBus_Enable @ 1c000adb4 =====

/* long __cdecl VBus_Enable(struct _FDO_CONTEXT * __ptr64) */

long __cdecl VBus_Enable(_FDO_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  long lVar2;
  undefined8 in_RDX;
  undefined7 uVar4;
  undefined8 uVar3;
  undefined1 uVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,8,10,
                     &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids);
  }
  pWVar1 = param_1->WdfDevice;
  uVar3 = 0;
  lVar2 = VBus_QcPepPstateRequest(param_1,1);
  uVar4 = (undefined7)((ulonglong)uVar3 >> 8);
  uVar5 = SUB81(pWVar1,0);
  if (lVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    uVar3 = CONCAT71(uVar4,2);
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0xb,
                       &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids,uVar5,(char)lVar2);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    uVar3 = CONCAT71(uVar4,4);
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,8,0xc,
                      &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids,uVar5);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,8,0xd,
                     &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids);
  }
  return lVar2;
}



===== VBus_QcPepPstateRequest @ 1c000aedc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000b06a) */
/* WARNING: Removing unreachable block (ram,0x0001c000b071) */
/* WARNING: Removing unreachable block (ram,0x0001c000b07a) */
/* long __cdecl VBus_QcPepPstateRequest(struct _FDO_CONTEXT * __ptr64,unsigned long) */

long __cdecl VBus_QcPepPstateRequest(_FDO_CONTEXT *param_1,ulong param_2)

{
  int iVar1;
  undefined4 in_register_00000014;
  undefined *puVar2;
  undefined7 uVar3;
  undefined1 auStackY_b8 [32];
  undefined1 uVar4;
  undefined8 local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  ulong uStack_3c;
  ulonglong local_38;
  
  puVar2 = (undefined *)CONCAT44(in_register_00000014,param_2);
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_58 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,8,0x12,
                     &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids);
  }
  uVar4 = SUB81(param_1->WdfDevice,0);
  if (param_1->PoHandle == (POHANDLE__ *)0x0) {
    Verifier_DbgBreak("Client driver should have already reported a POHANDLE to UrsCx by now",
                      (ulong)puVar2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar2 = (undefined *)CONCAT71((int7)((ulonglong)puVar2 >> 8),2);
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x13,
                        &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids,uVar4);
    }
    iVar1 = -0x3fffff62;
  }
  else {
    uStack_4c = 0;
    uStack_48 = 0;
    puVar2 = &GUID_QCPEP_POFXCONTROL_PSTATE_REQUEST_V2;
    uStack_44 = 0;
    uStack_40 = 0;
    local_58 = 2;
    uStack_50 = 0;
    uStack_3c = param_2;
    iVar1 = PoFxPowerControl(param_1->PoHandle,&GUID_QCPEP_POFXCONTROL_PSTATE_REQUEST_V2,&local_58,
                             0x20);
    uVar3 = (undefined7)((ulonglong)puVar2 >> 8);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      puVar2 = (undefined *)CONCAT71(uVar3,2);
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x14,
                         &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids,uVar4,(char)iVar1);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        puVar2 = (undefined *)CONCAT71(uVar3,2);
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x15,
                          &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids,uVar4);
      }
      iVar1 = -0x3ffffffc;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,8,0x17,
                     &WPP_4b05cb3ce3b23ca5c8ae1ee2d83f502a_Traceguids);
  }
  return iVar1;
}



===== AcpiEnumChildren @ 1c000b108 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl AcpiEnumChildren(struct WDFDEVICE__ * __ptr64,struct WDFMEMORY__ * __ptr64 *
   __ptr64) */

long __cdecl AcpiEnumChildren(WDFDEVICE__ *param_1,WDFMEMORY__ **param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  WDFMEMORY__ *pWVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  uint uVar8;
  WDFMEMORY__ *local_res8;
  undefined8 *local_res18;
  longlong local_res20;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined1 uVar11;
  int *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  WDFDEVICE__ *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  WDFMEMORY__ *pWStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong lStack_48;
  undefined8 local_40;
  
  local_res18 = (undefined8 *)0x0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  lStack_48 = 0;
  local_a8 = (int *)0x0;
  local_68 = 0;
  pWStack_60 = (WDFMEMORY__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,9,10,
                     &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids);
  }
  local_res20 = 0;
  local_res8 = (WDFMEMORY__ *)0x0;
  uVar2 = (**(code **)(WdfFunctions_01021 + 0x150))(WdfDriverGlobals,param_1);
  puVar3 = &local_a0;
  local_90 = 0;
  local_70 = 0;
  uVar6 = 0x200;
  uStack_98 = 0;
  uStack_78 = 0;
  uStack_88 = 0x100000001;
  local_a0 = 0x38;
  uVar9 = 0x10;
  local_80 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01021 + 0x600))
                    (WdfDriverGlobals,puVar3,0x200,0,0x10,&local_res20,&local_res18);
  uVar11 = SUB81(param_1,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,uVar6,0xb,uVar9,uVar11,
                         0x10);
    }
    goto LAB_1c000b4eb;
  }
  uVar5 = 0x14;
  uVar8 = 0;
  *local_res18 = 0;
  local_res18[1] = 0;
  *(undefined4 *)local_res18 = 0x48696541;
  *(undefined4 *)((longlong)local_res18 + 4) = 2;
  lStack_48 = local_res20;
  local_50 = 3;
  local_40 = 0;
  while( true ) {
    puVar3 = &local_a0;
    local_70 = 0;
    local_90 = 0;
    uStack_88 = 0x100000001;
    uVar6 = 0x200;
    uStack_98 = 0;
    local_a0 = 0x38;
    uStack_78 = 0;
    uVar10 = uVar5;
    local_80 = param_1;
    iVar1 = (**(code **)(WdfFunctions_01021 + 0x600))
                      (WdfDriverGlobals,puVar3,0x200,0,uVar5,&local_res8,&local_a8);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,uVar6,0xc,uVar10,uVar11
                           ,(char)uVar5);
      }
      goto LAB_1c000b4eb;
    }
    pWStack_60 = local_res8;
    local_68 = 3;
    local_58 = 0;
    iVar1 = (**(code **)(WdfFunctions_01021 + 0x5d0))
                      (WdfDriverGlobals,uVar2,0,0x32c020,&local_50,&local_68,0,0);
    if (-1 < iVar1) break;
    if (iVar1 != -0x7ffffffb) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0xf,
                           &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,uVar11,(char)iVar1);
      }
      goto LAB_1c000b4eb;
    }
    if (*local_a8 != 0x47696541) {
      iVar1 = -0x3febfff1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0x10;
        goto LAB_1c000b452;
      }
      goto LAB_1c000b4eb;
    }
    uVar5 = (ulonglong)(uint)local_a8[1];
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals,local_res8);
    uVar8 = uVar8 + 1;
    local_res8 = (WDFMEMORY__ *)0x0;
    if (1 < uVar8) goto LAB_1c000b4eb;
  }
  if (*local_a8 == 0x47696541) {
    if (local_a8[1] != 0) {
      *param_2 = local_res8;
      local_res8 = (WDFMEMORY__ *)0x0;
      goto LAB_1c000b4eb;
    }
    iVar1 = -0x3febfff1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000b4eb;
    uVar7 = 0xe;
  }
  else {
    iVar1 = -0x3febfff1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000b4eb;
    uVar7 = 0xd;
  }
LAB_1c000b452:
  iVar1 = -0x3febfff1;
  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar7,
                    &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,uVar11);
LAB_1c000b4eb:
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
    local_res20 = 0;
  }
  pWVar4 = local_res8;
  if (local_res8 != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
    local_res8 = (WDFMEMORY__ *)0x0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,9,0x11,
                     &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids);
  }
  return iVar1;
}



===== AcpiEnumeratePlds @ 1c000b58c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl AcpiEnumeratePlds(struct WDFDEVICE__ * __ptr64) */

long __cdecl AcpiEnumeratePlds(WDFDEVICE__ *param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined8 *puVar7;
  _ACPI_PLD_BUFFER *p_Var8;
  undefined2 uVar9;
  uint uVar10;
  uint uVar11;
  undefined8 *puVar12;
  WDFMEMORY__ *local_res8;
  longlong local_res10;
  ulonglong *local_res18;
  longlong local_res20;
  undefined *in_stack_ffffffffffffff48;
  undefined1 uVar13;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  WDFDEVICE__ *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_res18 = (ulonglong *)0x0;
  local_res20 = 0;
  local_res8 = (WDFMEMORY__ *)0x0;
  local_88 = 0;
  uStack_80 = 0;
  lVar4 = (**(code **)(WdfFunctions_01021 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_CONTEXT_TYPE_INFO_1c00110a8);
  local_68 = 0;
  local_48 = 0;
  puVar12 = (undefined8 *)(lVar4 + 0xa8);
  uStack_70 = 0;
  local_78 = 0x38;
  uStack_50 = 0;
  uStack_60 = 0x100000001;
  local_58 = param_1;
  iVar2 = (**(code **)(WdfFunctions_01021 + 0x68))(WdfDriverGlobals,&local_78,puVar12);
  uVar13 = SUB81(param_1,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar9 = 0x21;
    uVar10 = 5;
  }
  else {
    iVar2 = AcpiEnumChildren(param_1,&local_res8);
    if (-1 < iVar2) {
      lVar4 = (**(code **)(WdfFunctions_01021 + 0x610))(WdfDriverGlobals,local_res8,0);
      uVar10 = 0;
      local_res8 = (WDFMEMORY__ *)CONCAT44(local_res8._4_4_,1);
      pbVar5 = (byte *)(lVar4 + 8);
      if (*(uint *)(lVar4 + 4) < 2) {
        return iVar2;
      }
      local_res10 = lVar4;
      do {
        pbVar5 = pbVar5 + (ulonglong)*(uint *)(pbVar5 + 4) + 8;
        if ((*pbVar5 & 1) != 0) {
          pbVar1 = pbVar5 + 8;
          p_Var8 = (_ACPI_PLD_BUFFER *)&local_88;
          pbVar6 = pbVar1;
          iVar2 = AcpiEvaluatePld(param_1,(char *)pbVar1,p_Var8);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar6,p_Var8,0x23,
                                  in_stack_ffffffffffffff48,uVar13,(char *)pbVar1,(char)iVar2);
            }
            iVar2 = 0;
          }
          else {
            uVar11 = 0;
            uVar3 = 0;
            if (uVar10 != 0) {
              do {
                uVar11 = uVar3;
                local_res20 = (**(code **)(WdfFunctions_01021 + 0x90))
                                        (WdfDriverGlobals,*puVar12,uVar11);
                if (local_res20 == 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x24,
                                       &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,uVar13,
                                       (char)uVar11);
                  }
                  return -0x3fffffff;
                }
                local_res18 = (ulonglong *)
                              (**(code **)(WdfFunctions_01021 + 0x610))
                                        (WdfDriverGlobals,local_res20,0);
              } while ((*local_res18 !=
                        (ulonglong)
                        (((uint)uStack_80 >> 0x10 & 0x7f80 | (uint)uStack_80 & 0x7f8000) >> 7)) &&
                      (uVar11 = uVar11 + 1, uVar3 = uVar11, uVar11 < uVar10));
            }
            if (uVar11 == uVar10) {
              local_48 = 0;
              local_68 = 0;
              uStack_70 = 0;
              local_78 = 0x38;
              uStack_50 = 0;
              uStack_60 = 0x100000001;
              puVar7 = &local_78;
              local_58 = (WDFDEVICE__ *)*puVar12;
              in_stack_ffffffffffffff48 = (undefined *)0x8;
              iVar2 = (**(code **)(WdfFunctions_01021 + 0x600))
                                (WdfDriverGlobals,puVar7,0x200,0x58737255,8,&local_res20,
                                 &local_res18);
              if (iVar2 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return iVar2;
                }
                uVar9 = 0x25;
                goto LAB_1c000b953;
              }
              uVar3 = ((uint)uStack_80 >> 0x10 & 0x7f80 | (uint)uStack_80 & 0x7f8000) >> 7;
              *local_res18 = (ulonglong)uVar3;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                in_stack_ffffffffffffff48 = &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids;
                WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,9,0x26,
                                   &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,uVar13,
                                   (char)uVar3);
              }
              iVar2 = (**(code **)(WdfFunctions_01021 + 0x78))
                                (WdfDriverGlobals,*puVar12,local_res20);
              if (iVar2 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return iVar2;
                }
                uVar9 = 0x27;
                goto LAB_1c000b953;
              }
              uVar10 = uVar10 + 1;
            }
          }
          lVar4 = local_res10;
        }
        uVar3 = (int)local_res8 + 1;
        local_res8 = (WDFMEMORY__ *)CONCAT44(local_res8._4_4_,uVar3);
        if (*(uint *)(lVar4 + 4) <= uVar3) {
          return iVar2;
        }
      } while( true );
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar9 = 0x22;
LAB_1c000b953:
    uVar10 = 9;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar10,uVar9,
                     &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,uVar13,(char)iVar2);
  return iVar2;
}



===== AcpiEvaluateMethod @ 1c000b994 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000bd29) */
/* WARNING: Removing unreachable block (ram,0x0001c000bd38) */
/* WARNING: Removing unreachable block (ram,0x0001c000bd51) */
/* WARNING: Removing unreachable block (ram,0x0001c000bd6c) */
/* WARNING: Removing unreachable block (ram,0x0001c000bdee) */
/* long __cdecl AcpiEvaluateMethod(struct WDFDEVICE__ * __ptr64,char const * __ptr64,struct
   WDFMEMORY__ * __ptr64 * __ptr64) */

long __cdecl AcpiEvaluateMethod(WDFDEVICE__ *param_1,char *param_2,WDFMEMORY__ **param_3)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined8 *puVar5;
  char cVar6;
  longlong lVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined1 auStackY_228 [32];
  undefined1 uVar10;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  WDFDEVICE__ *local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined4 local_158;
  char local_154 [268];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_228;
  lVar7 = 0x100;
  uVar2 = 0;
  memset(local_154,0,0x100);
  local_190 = 0;
  uStack_188 = 0;
  local_160 = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_170 = (WDFDEVICE__ *)0x0;
  uStack_168 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,9,0x12,
                     &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01021 + 0x150))(WdfDriverGlobals,param_1);
  local_158 = 0x41696541;
  pcVar4 = local_154;
  do {
    if ((lVar7 == -0x7ffffefe) || (pcVar4[(longlong)param_2 - (longlong)local_154] == '\0')) break;
    *pcVar4 = pcVar4[(longlong)param_2 - (longlong)local_154];
    pcVar4 = pcVar4 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  pcVar3 = pcVar4 + -1;
  if (lVar7 != 0) {
    pcVar3 = pcVar4;
  }
  *pcVar3 = '\0';
  uVar10 = SUB81(param_1,0);
  if (lVar7 == 0) {
    iVar1 = -0x7ffffffb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x13,
                         &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,uVar10,5);
    }
  }
  else {
    cVar6 = '\x01';
    uVar9 = 0x200;
    while( true ) {
      local_160 = 0;
      puVar5 = &local_190;
      local_180 = 0;
      uStack_188 = 0;
      uStack_168 = 0;
      local_190 = 0x38;
      uStack_178 = 0x100000001;
      local_170 = param_1;
      iVar1 = (**(code **)(WdfFunctions_01021 + 0x600))(WdfDriverGlobals,puVar5,0x200,0);
      if (iVar1 < 0) break;
      memset((void *)0x0,0,(ulonglong)uVar9);
      iVar1 = (**(code **)(WdfFunctions_01021 + 0x5d0))(WdfDriverGlobals,uVar2,0);
      if (-1 < iVar1) {
        iVar1 = -0x3fffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x17;
          iVar1 = -0x3fffffff;
LAB_1c000bcfb:
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar8,
                             &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,uVar10,(char)iVar1);
        }
        goto LAB_1c000bde4;
      }
      if (iVar1 != -0x7ffffffb) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x16;
          goto LAB_1c000bcfb;
        }
        goto LAB_1c000bde4;
      }
      (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals,0);
      if (cVar6 == '\x02') {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x7ffffffb;
        }
        WPP_RECORDER_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        goto LAB_1c000bde4;
      }
      cVar6 = cVar6 + '\x01';
      uVar9 = uRam0000000000000004;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,9,0x14,
                          &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,uVar10,(char)uVar9,
                          (char)iVar1);
    }
  }
LAB_1c000bde4:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,9,0x19,
                     &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids);
  }
  return iVar1;
}



===== AcpiEvaluatePld @ 1c000be70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl AcpiEvaluatePld(struct WDFDEVICE__ * __ptr64,char const * __ptr64,struct
   _ACPI_PLD_BUFFER * __ptr64) */

long __cdecl AcpiEvaluatePld(WDFDEVICE__ *param_1,char *param_2,_ACPI_PLD_BUFFER *param_3)

{
  long lVar1;
  longlong lVar2;
  undefined8 uVar3;
  WDFMEMORY__ *pWVar4;
  WDFMEMORY__ **ppWVar5;
  undefined2 uVar6;
  undefined1 auStackY_198 [32];
  undefined *in_stack_fffffffffffffe88;
  WDFMEMORY__ *local_148 [2];
  WDFMEMORY__ local_138 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_198;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_fffffffffffffe88 = &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,9,0x1a,
                     &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids);
  }
  local_148[0] = (WDFMEMORY__ *)0x0;
  uVar3 = 0x100;
  lVar1 = RtlStringCchPrintfA((char *)local_138,0x100,"%s._PLD",param_2);
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    pWVar4 = (WDFMEMORY__ *)CONCAT71((int7)((ulonglong)uVar3 >> 8),2);
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x1b,
                       &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,(char)param_1,(char)lVar1);
    goto LAB_1c000c080;
  }
  ppWVar5 = local_148;
  pWVar4 = local_138;
  lVar1 = AcpiEvaluateMethod(param_1,(char *)pWVar4,ppWVar5);
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x1c;
LAB_1c000bf6c:
      WPP_RECORDER_SF_qsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,ppWVar5,uVar6,
                          in_stack_fffffffffffffe88,(char)param_1,(char *)local_138,(char)lVar1);
    }
  }
  else {
    ppWVar5 = (WDFMEMORY__ **)0x0;
    pWVar4 = local_148[0];
    lVar2 = (**(code **)(WdfFunctions_01021 + 0x610))(WdfDriverGlobals);
    if (*(int *)(lVar2 + 8) == 0) {
      lVar1 = -0x3febfff1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 0x1d;
        lVar1 = -0x3febfff1;
        goto LAB_1c000bf6c;
      }
    }
    else if (*(short *)(lVar2 + 0xc) == 2) {
      if (*(ushort *)(lVar2 + 0xe) < 0x10) {
        lVar1 = -0x3febfff1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qsPPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      else {
        uVar3 = *(undefined8 *)(lVar2 + 0x18);
        *(undefined8 *)param_3 = *(undefined8 *)(lVar2 + 0x10);
        *(undefined8 *)(param_3 + 8) = uVar3;
      }
    }
    else {
      lVar1 = -0x3febfff1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qsHd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
  }
  if (local_148[0] != (WDFMEMORY__ *)0x0) {
    pWVar4 = local_148[0];
    (**(code **)(WdfFunctions_01021 + 0x680))(WdfDriverGlobals);
  }
LAB_1c000c080:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,9,0x20,
                     &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids);
  }
  return lVar1;
}



===== RtlStringCchPrintfA @ 1c000c0e0 =====

/* long __cdecl RtlStringCchPrintfA(char * __ptr64,unsigned __int64,char const * __ptr64,...) */

long __cdecl RtlStringCchPrintfA(char *param_1,__uint64 param_2,char *param_3,...)

{
  ulonglong _Count;
  int iVar1;
  long lVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (param_2 - 1 < 0x7fffffff) {
    _Count = param_2 - 1;
    lVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      lVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    lVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return lVar2;
}



===== WPP_RECORDER_SF_qD @ 1c000c154 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,0x18,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,9,&WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,0x18,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qP @ 1c000c228 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,2,9,&WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qdD @ 1c000c2fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,0x15,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,9,&WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,0x15,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qsHd @ 1c000c3f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsHd(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc014000f;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000038 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,0x1e,&uStack0000000000000030,8,
               pcVar3,lVar2,&uStack0000000000000040,2,local_18,4,0);
  }
  lVar2 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000038[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,2,9,&WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,0x1e,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,&uStack0000000000000040,2,
                  local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qsPPd @ 1c000c59c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsPPd(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000048;
  undefined4 local_18 [2];
  undefined8 local_10;
  
  local_18[0] = 0xc014000f;
  local_10 = 0x10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000038 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,0x1f,&uStack0000000000000030,8,
               pcVar3,lVar2,&local_10,8,&uStack0000000000000048,8,local_18,4,0);
  }
  lVar2 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000038[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,2,9,&WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,0x1f,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,&local_10,8,
                  &uStack0000000000000048,8,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qsd @ 1c000c778 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,char *param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = param_7;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (param_7 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_7[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,param_4,&param_6,8,pcVar3,lVar2,
               &param_8,4,0);
  }
  lVar2 = -1;
  if (pcVar4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (pcVar4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  WppAutoLogTrace(param_1,2,9,&WPP_27aad93e4b0535316a2f44c9c5ac03e3_Traceguids,param_4,&param_6,8,
                  pcVar4,lVar1,&param_8,4,0);
  return;
}



===== FxStubDriverUnloadCommon @ 1c000c8f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c00111d8 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c00111d8 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c000c94d:
      if (ppvVar1 == (void **)0x0) goto LAB_1c000c9a3;
      if (ppvVar2 <= ppvVar1) goto LAB_1c000c9bb;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c000c94d;
LAB_1c000c9a3:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c000c9bb:
  WdfVersionUnbind(&DAT_1c0011260,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c000c9f0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c000ca24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

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
    _DAT_1c0011260 = 0x2080000;
    _DAT_1c0011268 = &DAT_1c00112b0;
    RtlCopyUnicodeString(&DAT_1c0011260);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c0011260,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00114b8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c0011260);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c00111d8 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c000cbb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00114b8 != (code *)0x0) && (DAT_1c00114b8 != FxStubDriverUnload)) {
    (*DAT_1c00114b8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c000cbe4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c000cc09) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x1c00111cf < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c00111d8 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 1c000cd6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c000cd89) */
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
    if ((void **)0x1c00111ef < ppvVar2) break;
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



===== _guard_check_icall @ 1c000ce40 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c000ce58 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000ce7c =====

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



===== wcscmp @ 1c000cee6 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000cee6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== __cpu_features_init @ 1c000cf00 =====

/* WARNING: Removing unreachable block (ram,0x0001c000cf6a) */
/* WARNING: Removing unreachable block (ram,0x0001c000cf19) */
/* WARNING: Removing unreachable block (ram,0x0001c000cf0a) */

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



===== __security_check_cookie @ 1c000cfd0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c000d010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c000d040 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000d040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c000d070 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1c000d0c0 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

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



===== memset @ 1c000d3c0 =====

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



===== __memset_repmovs @ 1c000d500 =====

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



===== __memset_query @ 1c000d580 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c000d600 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c000d740 =====

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



===== __memset_spec_plain @ 1c000d7c0 =====

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



===== WppCleanupKm @ 1c0014008 =====

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



===== WppInitKm @ 1c00140b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  
  if ((undefined4 *)WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = (undefined *)&WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0xe) = 0;
        (*pcVar1)(*(undefined8 *)(puVar2 + 2),0,WppClassicProviderCallback,puVar2,puVar2 + 0xe);
        puVar2 = *(undefined4 **)(puVar2 + 4);
      } while (puVar2 != (undefined4 *)0x0);
    }
    else if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 1c0014194 =====

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



===== WppTraceCallback @ 1c00142e0 =====

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
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== __security_init_cookie @ 1c0015008 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  byte *pbVar4;
  byte in_DL;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
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
    *pbVar4 = *pbVar4 + bVar3;
    bRam00000001d721600a = bRam00000001d721600a & in_DL;
    *pbVar4 = *pbVar4 + bVar3;
    pbVar4 = (byte *)CONCAT71((int7)((ulonglong)pbVar4 >> 8),0x17);
    bVar1 = *pbVar4;
    *pbVar4 = *pbVar4 + 0x17;
    *pbVar4 = (*pbVar4 - 0x17) - (0xe8 < bVar1);
    bVar1 = *pbVar4;
    *pbVar4 = *pbVar4 + in_DL;
    *(uint *)pbVar4 = (*(int *)pbVar4 - (int)pbVar4) - (uint)CARRY1(bVar1,in_DL);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


