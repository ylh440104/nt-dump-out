
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = PTR_DAT_140008050;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140008050;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140008068,&local_18,0,0,param_5,param_6);
  return;
}



===== __report_gsfailure @ 1400010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400010cd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== WerpBlockOnReporting @ 1400010e0 =====

ulonglong WerpBlockOnReporting(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res8 [4];
  undefined8 *puVar3;
  undefined8 local_18;
  undefined8 local_10;
  
  local_res8[0] = 0;
  puVar3 = local_res8;
  local_18 = param_1;
  uVar2 = ObReferenceObjectByHandle
                    (param_2,0x100000,*(undefined8 *)ExEventObjectType_exref,0,puVar3,0);
  local_10 = local_res8[0];
  if (-1 < (int)uVar2) {
    do {
      puVar3 = (undefined8 *)((ulonglong)puVar3 & 0xffffffffffffff00);
      uVar1 = KeWaitForMultipleObjects(2,&local_18,1,0,puVar3,1,0,0);
      uVar2 = (ulonglong)uVar1;
    } while (uVar1 == 0x101);
    ObfDereferenceObject(local_10);
  }
  return uVar2;
}



===== WerpSendWersvcMessage @ 14000118c =====

ulonglong WerpSendWersvcMessage(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  char *pcVar5;
  undefined8 local_res18;
  undefined8 local_res20;
  longlong local_38 [2];
  
  local_res20 = 0;
  local_res18 = 0;
  local_38[0] = 0;
  uVar1 = ZwQuerySystemInformation(0x73,&local_res18,8,0);
  uVar3 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    pcVar5 = 
    "WERKERNELHOST: ZwQuerySystemInformation/SystemErrorPortTimeouts failed with NTSTATUS %08X.\n";
  }
  else {
    uVar1 = WerStartSystemErrorHandler();
    uVar3 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar2 = WerWaitForSystemErrorHandler((int)local_res18);
      uVar3 = uVar2 & 0xffffffff;
      if ((-1 < (int)uVar2) && ((int)uVar2 != 0x102)) {
        plVar4 = local_38;
        if (local_res18._4_4_ == -1) {
          plVar4 = (longlong *)0x0;
        }
        else {
          local_38[0] = (longlong)local_res18._4_4_ * -10000;
        }
        uVar1 = ZwAlpcConnectPort(&local_res20,&DAT_140004000,&DAT_1400048b8,&DAT_140004860,0x20000,
                                  &DAT_1400048a8,0,0,0,0,plVar4);
        uVar3 = (ulonglong)uVar1;
        if (((int)uVar1 < 0) || (uVar1 == 0x102)) {
          pcVar5 = 
          "WERKERNELHOST: WerpSendWersvcMessage: ZwAlpcConnectPort failed with NTSTATUS %08X.\n";
        }
        else {
          local_38[1] = 0x578;
          uVar1 = ZwAlpcSendWaitReceivePort(local_res20,0,param_2,0,param_1,local_38 + 1,0,plVar4);
          uVar3 = (ulonglong)uVar1;
          ZwClose(local_res20);
          if ((-1 < (int)uVar1) && (uVar1 != 0x102)) {
            return uVar3;
          }
          pcVar5 = 
          "WERKERNELHOST: WerpSendWersvcMessage: ZwAlpcSendWaitReceivePort failed with NTSTATUS %08X.\n"
          ;
        }
        goto LAB_140001304;
      }
    }
    pcVar5 = 
    "WERKERNELHOST: WerpSendWersvcMessage: WerStartSystemErrorHandler failed with NTSTATUS %08X.\n";
  }
LAB_140001304:
  DbgPrintEx(5,1,pcVar5,uVar3);
  return uVar3;
}



===== WerpSendWersvcMessageWERSVC_REPORT_CRASH @ 140001338 =====

ulonglong WerpSendWersvcMessageWERSVC_REPORT_CRASH
                    (undefined8 *param_1,ulonglong param_2,undefined4 param_3,undefined4 param_4,
                    ulonglong param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar7;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar8;
  ulonglong local_28;
  undefined8 local_20;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  local_28 = 0;
  puVar3 = (undefined4 *)ExAllocatePoolWithTag(0x401,0xaf0,0x4d534b57);
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    *puVar3 = 0x5780550;
    *(undefined2 *)(puVar3 + 1) = 0x8000;
    puVar3[10] = 0x20000000;
    *(ulonglong *)(puVar3 + 0xe) = param_2;
    puVar3[0xc] = param_3;
    puVar3[0xd] = param_4;
    *(ulonglong *)(puVar3 + 0x10) = param_2 & 0xffffffff;
    iVar1 = ZwDuplicateObject(0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,&local_28,
                              CONCAT44(uVar7,0x101000),CONCAT44(uVar8,2),8);
    if (iVar1 < 0) {
      *(undefined8 *)(puVar3 + 0x12) = 0;
      lVar6 = 0x48;
      local_28 = 0;
    }
    else {
      lVar6 = 0x50;
      *(ulonglong *)(puVar3 + 0x12) = local_28 & 0xffffffff;
    }
    if (param_5 != 0) {
      *(ulonglong *)(lVar6 + (longlong)puVar3) = param_5 & 0xffffffff;
    }
    uVar5 = WerpSendWersvcMessage(puVar3 + 0x15e,puVar3);
    uVar4 = uVar5 & 0xffffffff;
    if (local_28 != 0) {
      ObCloseHandle(local_28,1);
    }
    if ((int)uVar5 < 0) {
      DbgPrintEx(5,0,
                 "WERKERNELHOST: WerpSendWersvcMessageWERSVC_REPORT_CRASH: WerpSendWersvcMessage returned NTSTATUS %08X\n"
                 ,uVar5 & 0xffffffff);
    }
    else {
      DbgPrintEx(5,3,
                 "WERKERNELHOST: WerpSendWersvcMessageWERSVC_REPORT_CRASH: Response message ID: %08X.\n"
                 ,puVar3[0x168]);
      DbgPrintEx(5,3,
                 "WERKERNELHOST: WerpSendWersvcMessageWERSVC_REPORT_CRASH: Response message status: NTSTATUS %08X.\n"
                 ,puVar3[0x169]);
      if (puVar3[0x168] == 0x20000002) {
        local_20 = 0;
        uVar2 = ObReferenceObjectByHandle
                          (*(undefined8 *)(puVar3 + 0x16a),0x100000,
                           *(undefined8 *)PsProcessType_exref,1,&local_20,0);
        uVar4 = (ulonglong)uVar2;
        *param_1 = local_20;
        if ((int)uVar2 < 0) {
          *param_1 = 0;
        }
      }
      else if (puVar3[0x168] == 0x20000004) {
        DbgPrintEx(5,0,
                   "WERKERNELHOST: WerpSendWersvcMessageWERSVC_REPORT_CRASH: WERSVC_CRASH_REPORTING_FAILED with NTSTATUS %08X\n"
                   ,uVar5 & 0xffffffff);
        uVar4 = (ulonglong)(uint)puVar3[0x169];
      }
    }
    ExFreePoolWithTag(puVar3,0x4d534b57);
  }
  return uVar4;
}



===== WerpSuppressReadFaultsFilter @ 140001560 =====

bool WerpSuppressReadFaultsFilter(int param_1,longlong *param_2,ulonglong param_3)

{
  ulonglong uVar1;
  
  if (((param_1 + 0x3ffffffbU < 2) && (*(longlong *)(*param_2 + 0x20) == 0)) &&
     (uVar1 = *(ulonglong *)(*param_2 + 0x28), param_3 <= uVar1)) {
    return uVar1 < param_3 + 0xf8;
  }
  return false;
}



===== McGenControlCallbackV2 @ 1400015a0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1400016b0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (WERKERNEL_EVENT_PROVIDER_GUID_Context == 0) {
    EtwRegister(&WERKERNEL_EVENT_PROVIDER_GUID,McGenControlCallbackV2,
                &WERKERNEL_EVENT_PROVIDER_GUID_Context,&WERKERNEL_EVENT_PROVIDER_GUID_Context);
  }
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 1400016f0 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140008008;
  uVar2 = 0;
  if (DAT_140008008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140008008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(WERKERNEL_EVENT_PROVIDER_GUID_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateU0zqqqq_EtwWriteTransfer @ 140001754 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0zqqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (param_3 == (wchar_t *)0x0) {
    local_60 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_3[lVar1] != L'\0');
    local_60 = (int)lVar1 * 2 + 2;
  }
  local_58 = local_res20;
  local_5c = 0;
  local_48 = &param_5;
  local_50 = 4;
  local_38 = &param_6;
  local_40 = 4;
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  local_68 = param_3;
  McGenEventWrite_EtwWriteTransfer(L"NULL",&WERKERNEL_CREATE_REPORT,param_3,6,local_78);
  return;
}



===== McTemplateU0zqzq_EtwWriteTransfer @ 140001828 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0zqzq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,undefined4 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar1 = -1;
  local_30 = 10;
  if (param_3 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_4c = 0;
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  local_40 = 4;
  local_48 = local_res20;
  if (param_5 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_28 = &param_6;
  local_2c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  local_58 = param_3;
  local_38 = param_5;
  McGenEventWrite_EtwWriteTransfer(local_48,&WERKERNEL_SUBMIT_REPORT,param_3,5,local_68);
  return;
}



===== RtlStringCbPrintfW @ 140001914 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,uVar2,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== RtlStringCchPrintfW @ 140001990 =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== RtlUnicodeStringCatString @ 140001a0c =====

undefined4 RtlUnicodeStringCatString(ushort *param_1,short *param_2)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  short sVar6;
  longlong lVar7;
  longlong lVar8;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) != 0) || (uVar2 = param_1[1], (uVar2 & 1) != 0)) || (uVar2 < uVar1)) ||
      (uVar2 == 0xffff)) ||
     ((uVar5 = 0, *(longlong *)(param_1 + 4) == 0 && ((uVar1 != 0 || (uVar2 != 0)))))) {
    return 0xc000000d;
  }
  lVar8 = 0x7fff;
  lVar3 = *(longlong *)(param_1 + 4);
  sVar6 = 0;
  uVar1 = uVar1 >> 1;
  lVar7 = (ulonglong)(param_1[1] >> 1) - (ulonglong)uVar1;
  if (lVar7 != 0) {
    lVar4 = (ulonglong)uVar1 * 2 - (longlong)param_2;
    do {
      if (lVar8 == 0) goto LAB_140001ab9;
      if (*param_2 == 0) break;
      *(short *)(lVar3 + lVar4 + (longlong)param_2) = *param_2;
      lVar8 = lVar8 + -1;
      param_2 = param_2 + 1;
      sVar6 = sVar6 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    if ((lVar7 != 0) || (lVar8 == 0)) goto LAB_140001ab9;
  }
  uVar5 = 0;
  if (*param_2 != 0) {
    uVar5 = 0x80000005;
  }
LAB_140001ab9:
  *param_1 = (uVar1 + sVar6) * 2;
  return uVar5;
}



===== _tlgDefineProvider_annotation__TlgWerKernelTelemetryLoggingProviderProv @ 140001ae0 =====

void _tlgDefineProvider_annotation__TlgWerKernelTelemetryLoggingProviderProv(void)

{
  return;
}



===== _guard_check_icall @ 140001b00 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140001b18 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001b3c =====

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



===== __cpu_features_init @ 140001bb0 =====

/* WARNING: Removing unreachable block (ram,0x000140001c1a) */
/* WARNING: Removing unreachable block (ram,0x000140001bc9) */
/* WARNING: Removing unreachable block (ram,0x000140001bba) */

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



===== __security_check_cookie @ 140001c80 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140001cc0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140001cf0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001cf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140001d20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140001d60 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = (longlong)_Buf2 - (longlong)_Buf1;
  if (7 < _Size) {
    for (; ((ulonglong)_Buf1 & 7) != 0; _Buf1 = (void *)((longlong)_Buf1 + 1)) {
      bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140001da3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140001e14;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140001e10:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140001e14;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140001e0c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140001e10;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140001e0c;
          }
          _Buf1 = (void *)((longlong)_Buf1 + 0x20);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 0x1f;
      }
      uVar4 = _Size >> 3;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) {
LAB_140001e14:
            uVar4 = *(ulonglong *)(lVar3 + (longlong)_Buf1);
            uVar1 = (uint)((uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                            (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                            (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 |
                            (uVar2 & 0xff00) << 0x28 | uVar2 << 0x38) <
                          (uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                           (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
                           (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
                           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38));
            return (1 - uVar1) - (uint)(uVar1 != 0);
          }
          _Buf1 = (void *)((longlong)_Buf1 + 8);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 7;
      }
    }
  }
  while( true ) {
    if (_Size == 0) {
      return 0;
    }
    bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
    if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_140001da3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 140001e80 =====

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



===== memset @ 140002180 =====

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



===== __memset_repmovs @ 1400022c0 =====

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



===== __memset_query @ 140002340 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400023c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140002500 =====

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



===== __memset_spec_plain @ 140002580 =====

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



===== WerSubmitUserCrashReport @ 14000b010 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WerSubmitUserCrashReport
                    (undefined8 param_1,undefined8 *param_2,longlong param_3,uint param_4,
                    uint param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined8 local_res18;
  uint local_res20;
  ulonglong uVar7;
  undefined8 in_stack_ffffffffffffff40;
  undefined4 uVar9;
  undefined8 uVar8;
  undefined8 in_stack_ffffffffffffff48;
  undefined4 uVar10;
  longlong local_98;
  ulonglong local_90;
  undefined8 local_88;
  ulonglong local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined4 local_38;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff40 >> 0x20);
                    /* 0xb010  8  WerSubmitUserCrashReport */
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_res20 = param_4;
  if ((param_3 != 0) || ((param_5 & 2) == 0)) {
    DbgPrintEx(5,0,
               "WERKERNELHOST: I can only handle auto-context now. Failing with NTSTATUS %08X.\n",
               0xc00000bb);
    return 0xc00000bb;
  }
  uVar7 = 0;
  uVar3 = ZwQueryInformationThread(0,0,&local_60,0x30,0);
  if ((int)uVar3 < 0) {
    pcVar6 = 
    "WERKERNELHOST: WerSubmitUserCrashReportExt: ZwQueryInformationThread/ThreadBasicInformation returned NTSTATUS %08X\n"
    ;
LAB_14000b0a4:
    DbgPrintEx(5,0,pcVar6,(ulonglong)uVar3);
    return (ulonglong)uVar3;
  }
  local_res18 = CONCAT44(local_res18._4_4_,param_5) & 0xffffffff00000001;
  if ((param_5 & 1) != 0) {
    uVar3 = ZwCreateEvent(&local_98,0x100003,&DAT_140004828,0,uVar7 & 0xffffffffffffff00);
    if ((int)uVar3 < 0) {
      pcVar6 = "WERKERNELHOST: WerSubmitUserCrashReportExt: ZwCreateEvent returned NTSTATUS %08X\n";
      goto LAB_14000b0a4;
    }
    uVar8 = CONCAT44(uVar9,2);
    uVar3 = ZwDuplicateObject(0xffffffffffffffff,local_98,0xffffffffffffffff,&local_90,0x100003,
                              uVar8,CONCAT44(uVar10,8));
    uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
    uVar7 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      DbgPrintEx(5,0,
                 "WERKERNELHOST: WerSubmitUserCrashReportExt: ZwDuplicateObject/CompletionEvent returned NTSTATUS %08X\n"
                 ,uVar3);
      goto LAB_14000b160;
    }
  }
  uVar10 = 0;
  uVar3 = ZwCreateSection(&local_88,0xf0007,&DAT_140004828,&DAT_140004858,4,
                          CONCAT44(uVar9,0x8000000),0);
  if ((int)uVar3 < 0) {
    DbgPrintEx(5,0,
               "WERKERNELHOST: WerSubmitUserCrashReportExt: ZwCreateSection returned NTSTATUS %08X\n"
               ,uVar3);
LAB_14000b1cf:
    uVar7 = (ulonglong)uVar3;
    if (local_90 != 0) {
      ObCloseHandle(local_90,1);
    }
  }
  else {
    uVar3 = ZwDuplicateObject(0xffffffffffffffff,local_88,0xffffffffffffffff,&local_80,6,2,
                              CONCAT44(uVar10,8));
    if ((int)uVar3 < 0) {
      DbgPrintEx(5,0,
                 "WERKERNELHOST: WerSubmitUserCrashReportExt: ZwDuplicateObject/Section returned NTSTATUS %08X\n"
                 ,uVar3);
LAB_14000b24c:
      ZwClose(local_88);
      goto LAB_14000b1cf;
    }
    local_78 = (undefined4 *)0x0;
    local_70 = 0;
    uVar3 = ZwMapViewOfSection(local_88,0xffffffffffffffff,&local_78,0,0,0,&local_70,2,0,4);
    puVar2 = local_78;
    if ((int)uVar3 < 0) {
      DbgPrintEx(5,0,
                 "WERKERNELHOST: WerSubmitUserCrashReportExt: ZwMapViewOfSection returned NTSTATUS %08X\n"
                 ,uVar3);
      ObCloseHandle(local_80,1);
      goto LAB_14000b24c;
    }
    local_68 = local_78;
    memset(local_78,0,0xf8);
    *puVar2 = 0xf8;
    puVar2[1] = (undefined4)local_50;
    puVar2[2] = (undefined4)uStack_48;
    puVar2[0x2c] = 0;
    *(undefined8 *)(puVar2 + 0x2e) = 0;
    *(undefined8 *)(puVar2 + 0x30) = 0;
    *(undefined8 *)(puVar2 + 0x32) = 0;
    *(ulonglong *)(puVar2 + 0x34) = local_90 & 0xffffffff;
    *(undefined8 *)(puVar2 + 0x38) = 0;
    puVar2[0x3a] = 0xc00000bb;
    puVar2[0x3b] = local_res20 | 0x80000000;
    puVar2[0x3c] = (int)((ulonglong)_DAT_fffff78000000004 * _DAT_fffff78000000320 >> 0x18);
    if (param_2 != (undefined8 *)0x0) {
      uVar8 = param_2[1];
      *(undefined8 *)(puVar2 + 4) = *param_2;
      *(undefined8 *)(puVar2 + 6) = uVar8;
      uVar8 = param_2[3];
      *(undefined8 *)(puVar2 + 8) = param_2[2];
      *(undefined8 *)(puVar2 + 10) = uVar8;
      uVar8 = param_2[5];
      *(undefined8 *)(puVar2 + 0xc) = param_2[4];
      *(undefined8 *)(puVar2 + 0xe) = uVar8;
      uVar8 = param_2[7];
      *(undefined8 *)(puVar2 + 0x10) = param_2[6];
      *(undefined8 *)(puVar2 + 0x12) = uVar8;
      uVar8 = param_2[9];
      *(undefined8 *)(puVar2 + 0x14) = param_2[8];
      *(undefined8 *)(puVar2 + 0x16) = uVar8;
      uVar8 = param_2[0xb];
      *(undefined8 *)(puVar2 + 0x18) = param_2[10];
      *(undefined8 *)(puVar2 + 0x1a) = uVar8;
      uVar8 = param_2[0xd];
      *(undefined8 *)(puVar2 + 0x1c) = param_2[0xc];
      *(undefined8 *)(puVar2 + 0x1e) = uVar8;
      uVar9 = *(undefined4 *)((longlong)param_2 + 0x74);
      uVar10 = *(undefined4 *)(param_2 + 0xf);
      uVar1 = *(undefined4 *)((longlong)param_2 + 0x7c);
      puVar2[0x20] = *(undefined4 *)(param_2 + 0xe);
      puVar2[0x21] = uVar9;
      puVar2[0x22] = uVar10;
      puVar2[0x23] = uVar1;
      uVar8 = param_2[0x11];
      *(undefined8 *)(puVar2 + 0x24) = param_2[0x10];
      *(undefined8 *)(puVar2 + 0x26) = uVar8;
      *(undefined8 *)(puVar2 + 0x28) = param_2[0x12];
    }
    ZwUnmapViewOfSection(0xffffffffffffffff,local_78);
    local_res18 = 0;
    uVar5 = WerpSendWersvcMessageWERSVC_REPORT_CRASH
                      (&local_res18,local_80,param_5,(undefined4)local_50,local_90);
    iVar4 = (int)uVar5;
    uVar7 = uVar5 & 0xffffffff;
    if (((iVar4 < 0) || (iVar4 == 0x102)) &&
       (DbgPrintEx(5,0,
                   "WERKERNELHOST: WerSubmitUserCrashReportExt: WerpSendWersvcMessageWERSVC_REPORT_CRASH returned NTSTATUS %08X\n"
                   ,uVar5 & 0xffffffff), iVar4 == 0x102)) {
      uVar7 = 0xc0000240;
    }
    ObCloseHandle(local_80,1);
    ZwClose(local_88);
    if (local_90 != 0) {
      ObCloseHandle(local_90,1);
    }
    if (((-1 < (int)uVar7) && (local_res18 != 0)) && ((param_5 & 1) != 0)) {
      WerpBlockOnReporting(local_res18,local_98);
    }
    if (local_res18 != 0) {
      ObfDereferenceObject();
    }
  }
  if (local_98 == 0) {
    return uVar7;
  }
LAB_14000b160:
  ZwClose(local_98);
  return uVar7;
}



===== WerLiveKernelCancelReport @ 14000b560 =====

int WerLiveKernelCancelReport(int *param_1)

{
  int iVar1;
  
                    /* 0xb560  2  WerLiveKernelCancelReport */
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0x636b6c57) {
      WerpDeleteDumpFile((longlong)param_1);
      iVar1 = WerpCancelReport(*(longlong *)(param_1 + 4));
      if (iVar1 < 0) {
        DbgPrintEx(5,1,"WERKERNELHOST: WerLiveKernelCancelReport returned status 0x%X\n",iVar1);
      }
      DbgPrintEx(5,3,"WERKERNELHOST: WerLiveKernelCancelReportExt returns 0x%X\n",iVar1);
      return iVar1;
    }
    DbgPrintEx(5,1,"WERKERNELHOST: WER context signature validation failed! \n");
  }
  DbgPrintEx(5,1,"WERKERNELHOST: WerLiveKernelCancelReportExt: invalid context.\n");
  return -0x3ffffff3;
}



===== WerLiveKernelCloseHandle @ 14000b620 =====

int WerLiveKernelCloseHandle(int *param_1)

{
  int iVar1;
  
                    /* 0xb620  3  WerLiveKernelCloseHandle */
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0x636b6c57) {
      if (*(longlong *)(param_1 + 4) != 0) {
        iVar1 = WerpCloseHandle(*(longlong *)(param_1 + 4));
        param_1[4] = 0;
        param_1[5] = 0;
      }
      DbgPrintEx(5,3,"WERKERNELHOST: Deleting WerContext %p\n",param_1);
      ExFreePoolWithTag(param_1,0);
      return iVar1;
    }
    DbgPrintEx(5,1,"WERKERNELHOST: WER context signature validation failed! \n");
    DbgPrintEx(5,1,"WERKERNELHOST: WerLiveKernelCloseReportExt: invalid context.\n");
  }
  return -0x3ffffff3;
}



===== WerLiveKernelCreateReport @ 14000b6e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint WerLiveKernelCreateReport(wchar_t *param_1,uint *param_2,undefined8 *param_3,uint *param_4)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  wchar_t *pwVar6;
  uint *puVar7;
  ulonglong uVar8;
  uint *puVar9;
  longlong lVar10;
  uint *puVar11;
  undefined *puVar12;
  uint uVar13;
  char *pcVar14;
  longlong lVar15;
  bool bVar16;
  undefined1 auStackY_128 [32];
  uint local_e8;
  uint local_e4;
  uint local_e0 [2];
  wchar_t *local_d8;
  uint local_d0 [2];
  undefined8 local_c8 [4];
  wchar_t **local_a8;
  undefined8 local_a0;
  wchar_t *local_98;
  int local_90;
  undefined4 local_8c;
  uint *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0xb6e0  4  WerLiveKernelCreateReport */
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  if (param_2 == (uint *)0x0) {
    local_e0[0] = 0;
  }
  else {
    local_e0[0] = *param_2;
  }
  local_e8 = 0;
  uVar13 = 0;
  local_e4 = 0;
  local_d8 = param_1;
  if (param_1 == (wchar_t *)0x0) {
    if (param_3 == (undefined8 *)0x0) goto LAB_14000bafd;
  }
  else {
    if (param_3 == (undefined8 *)0x0) goto LAB_14000bafd;
    if (param_2 != (uint *)0x0) {
      bVar16 = WerKernelLiveReportInitialized == '\0';
      *param_3 = 0;
      if (bVar16) {
        puVar11 = (uint *)0x5;
        DbgPrintEx(5,1,"WERKERNELHOST: WerLiveKernelCreateReportExt: Reports not initialized\n");
        uVar4 = 0xc0000002;
        *param_2 = 0;
        goto LAB_14000b9b5;
      }
      lVar15 = 0x10;
      lVar10 = 0x10;
      pwVar6 = param_1;
      do {
        if (*pwVar6 == L'\0') break;
        pwVar6 = pwVar6 + 1;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      if (lVar10 == 0) {
        puVar11 = (uint *)0x5;
        DbgPrintEx(5,1,"WERKERNELHOST: Key key length exceeded\n");
        *param_2 = 0;
        uVar4 = 0xc000000d;
      }
      else {
        puVar11 = (uint *)0x290;
        puVar7 = (uint *)WerpAllocateMem(0x290);
        if (puVar7 == (uint *)0x0) {
          uVar4 = 0xc0000017;
          *param_2 = 0;
        }
        else {
          param_4 = &local_e4;
          *puVar7 = 0x636b6c57;
          uVar8 = WerpCheckPolicy(local_d8,*param_2,(int *)&local_e8,(int *)param_4);
          uVar4 = (uint)uVar8;
          if ((int)uVar4 < 0) {
            param_4 = (uint *)(uVar8 & 0xffffffff);
            pcVar14 = "WERKERNELHOST: CheckPolicy failed, status 0x%X\n";
LAB_14000b824:
            DbgPrintEx(5,1,pcVar14);
          }
          else if (local_e8 == 0) {
            DbgPrintEx(5,1,"WERKERNELHOST: CheckPolicy throttled dump creation for Component \n");
            uVar4 = 0xc0000022;
          }
          else {
            puVar11 = puVar7 + 6;
            lVar10 = (longlong)local_d8 - (longlong)puVar11;
            puVar7[1] = local_e8;
            do {
              if ((lVar15 == -0x7fffffee) ||
                 (sVar1 = *(short *)(lVar10 + (longlong)puVar11), sVar1 == 0)) break;
              *(short *)puVar11 = sVar1;
              puVar11 = (uint *)((longlong)puVar11 + 2);
              lVar15 = lVar15 + -1;
            } while (lVar15 != 0);
            puVar9 = (uint *)((longlong)puVar11 + -2);
            if (lVar15 != 0) {
              puVar9 = puVar11;
            }
            *(undefined2 *)puVar9 = 0;
            if (lVar15 == 0) {
              param_4 = (uint *)0x80000005;
              pcVar14 = 
              "WERKERNELHOST:  RtlStringCchCopyW failed to copy ComponentName, status 0x%X\n";
              uVar4 = 0x80000005;
              goto LAB_14000b824;
            }
            uVar8 = WerpCreateReportId((longlong)puVar7);
            uVar4 = (uint)uVar8;
            if (-1 < (int)uVar4) {
              uVar4 = WerpCreateReport(local_e8,(longlong)local_d8,(longlong)(puVar7 + 0xe),
                                       (longlong *)(puVar7 + 4),&local_e4);
              if (((int)uVar4 < 0) || (*(longlong *)(puVar7 + 4) == 0)) {
                param_4 = (uint *)(ulonglong)uVar4;
                DbgPrintEx(5,1,"WERKERNELHOST: WerKernelCreateReport failed, status 0x%X\n");
                if ((int)uVar4 < 0) goto LAB_14000b94c;
              }
              puVar11 = (uint *)0x5;
              param_4 = puVar7;
              DbgPrintEx(5,3,
                         "WERKERNELHOST: WerLiveKernelCreateReport: returning reportHandle %p Policy %i\n"
                        );
              *param_3 = puVar7;
              *param_2 = puVar7[1];
              goto LAB_14000b9ad;
            }
            param_4 = (uint *)(uVar8 & 0xffffffff);
            DbgPrintEx(5,1,"WERKERNELHOST: Could not create report ID, error 0x%X\n");
          }
LAB_14000b94c:
          *param_2 = 0;
          if (*(longlong *)(puVar7 + 4) != 0) {
            WerpCancelReport(*(longlong *)(puVar7 + 4));
            WerpCloseHandle(*(longlong *)(puVar7 + 4));
            puVar7[4] = 0;
            puVar7[5] = 0;
          }
          ExFreePoolWithTag();
          puVar11 = puVar7;
        }
LAB_14000b9ad:
        uVar13 = local_e4;
      }
      param_1 = local_d8;
LAB_14000b9b5:
      uVar3 = local_e0[0];
      uVar2 = local_e8;
      puVar12 = (undefined *)0x0;
      if (5 < DAT_140008048) {
        if (((_DAT_140008058 & 0x400000000000) == 0) ||
           (bVar16 = true, (DAT_140008060 & 0x400000000000) != DAT_140008060)) {
          bVar16 = false;
        }
        if (bVar16) {
          local_a8 = &local_d8;
          local_d8 = (wchar_t *)0x3000000;
          lVar10 = -1;
          local_a0 = 8;
          do {
            lVar10 = lVar10 + 1;
          } while (param_1[lVar10] != L'\0');
          local_90 = (int)lVar10 * 2 + 2;
          local_88 = local_d0;
          local_78 = local_e0;
          local_68 = &local_e4;
          local_58 = &local_e8;
          local_8c = 0;
          puVar12 = &DAT_140006e91;
          local_d0[0] = local_e0[0];
          local_80 = 4;
          local_e0[0] = local_e8;
          local_70 = 4;
          local_60 = 4;
          local_50 = 4;
          local_e8 = uVar13;
          local_e4 = uVar4;
          local_98 = param_1;
          _tlgWriteTransfer_EtwWriteTransfer(puVar11,&DAT_140006e91,8,param_4,8,local_c8);
        }
      }
      if (((Microsoft_Windows_WerKernelEnableBits & 1) != 0) &&
         (iVar5 = McTemplateU0zqqqq_EtwWriteTransfer
                            (puVar11,puVar12,param_1,uVar3,(char)uVar2,(char)uVar4,(char)uVar13),
         iVar5 < 0)) {
        DbgPrintEx(5,1,"WERKERNELHOST: EtwWrite failed with 0x%X\n",iVar5);
      }
      return uVar4;
    }
  }
  *param_3 = 0;
LAB_14000bafd:
  if (param_2 != (uint *)0x0) {
    *param_2 = 0;
  }
  DbgPrintEx(5,1,"WERKERNELHOST: WerLiveKernelCreateReportExt: Invalid parameter\n");
  return 0xc000000d;
}



===== WerLiveKernelOpenDumpFile @ 14000bb50 =====

ulonglong WerLiveKernelOpenDumpFile(int *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  char *pcVar3;
  undefined8 local_res8;
  
                    /* 0xbb50  6  WerLiveKernelOpenDumpFile */
  if ((param_1 == (int *)0x0) || (param_2 == (undefined8 *)0x0)) {
    pcVar3 = "WERKERNELHOST:  WerLiveKernelOpenDumpFileExt: Invalid parameter\n";
  }
  else {
    *param_2 = 0;
    if (*param_1 == 0x636b6c57) {
      local_res8 = 0;
      uVar2 = WerpCreateDumpFile((longlong)param_1,&local_res8);
      uVar1 = local_res8;
      if ((int)uVar2 < 0) {
        DbgPrintEx(5,1,"WERKERNELHOST: WepCreateDumpFile failed, status 0x%x\n",uVar2 & 0xffffffff);
      }
      else {
        DbgPrintEx(5,3,
                   "WERKERNELHOST: WerLiveKernelOpenDumpFileExt: returning dump handle %p, report reportHandle %p\n"
                   ,local_res8,param_1);
        *param_2 = uVar1;
      }
      return uVar2 & 0xffffffff;
    }
    DbgPrintEx(5,1,"WERKERNELHOST: WER context signature validation failed! \n");
    pcVar3 = "WERKERNELHOST: WerLiveKernelOpenDumpFileExt: invalid context.\n";
  }
  DbgPrintEx(5,1,pcVar3);
  return 0xc000000d;
}



===== WerLiveKernelSubmitReport @ 14000bc40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint WerLiveKernelSubmitReport(int *param_1,undefined *param_2,undefined8 param_3,ulonglong param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 auStackY_c8 [32];
  int local_98;
  uint local_94;
  undefined8 local_90;
  undefined8 local_88 [4];
  undefined8 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  int *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  uint *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
                    /* 0xbc40  7  WerLiveKernelSubmitReport */
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0x636b6c57) {
      piVar4 = param_1;
      uVar2 = WerpSubmitReport((longlong)param_1);
      if ((int)uVar2 < 0) {
        param_2 = (undefined *)0x1;
        param_4 = (ulonglong)uVar2;
        piVar4 = (int *)0x5;
        DbgPrintEx(5,1,"WERKERNELHOST: WerLiveKernelSubmitReport failed with status 0x%X\n");
      }
      if (5 < DAT_140008048) {
        param_2 = (undefined *)0x400000000000;
        if (((_DAT_140008058 & 0x400000000000) == 0) ||
           (bVar1 = true, (DAT_140008060 & 0x400000000000) != DAT_140008060)) {
          bVar1 = false;
        }
        if (bVar1) {
          local_68 = &local_90;
          local_90 = 0x3000000;
          piVar4 = (int *)0xffffffffffffffff;
          local_58 = (wchar_t *)(param_1 + 6);
          local_60 = 8;
          uVar6 = 2;
          if (local_58 == (wchar_t *)0x0) {
            local_58 = L"";
            local_50 = 2;
          }
          else {
            lVar5 = -1;
            do {
              lVar5 = lVar5 + 1;
            } while (local_58[lVar5] != L'\0');
            local_50 = (int)lVar5 * 2 + 2;
          }
          local_98 = param_1[1];
          local_48 = &local_98;
          local_38 = (wchar_t *)(param_1 + 0xe);
          local_4c = 0;
          local_40 = 4;
          if (local_38 == (wchar_t *)0x0) {
            local_38 = L"";
          }
          else {
            do {
              piVar4 = (int *)((longlong)piVar4 + 1);
            } while (local_38[(longlong)piVar4] != L'\0');
            uVar6 = (ulonglong)((int)piVar4 * 2 + 2);
          }
          param_2 = &DAT_140006f14;
          local_28 = &local_94;
          local_30 = (undefined4)uVar6;
          local_2c = 0;
          local_20 = 4;
          local_94 = uVar2;
          _tlgWriteTransfer_EtwWriteTransfer(piVar4,&DAT_140006f14,uVar6,param_4,7,local_88);
        }
      }
      if (((Microsoft_Windows_WerKernelEnableBits & 1) != 0) &&
         (iVar3 = McTemplateU0zqzq_EtwWriteTransfer
                            (piVar4,param_2,(wchar_t *)(param_1 + 6),param_1[1],
                             (wchar_t *)(param_1 + 0xe),(char)uVar2), iVar3 < 0)) {
        DbgPrintEx(5,1,"WERKERNELHOST: EtwWrite failed with 0x%X\n",iVar3);
      }
      return uVar2;
    }
    DbgPrintEx(5,1,"WERKERNELHOST: WER context signature validation failed! \n");
  }
  DbgPrintEx(5,1,"WERKERNELHOST: WerLiveKernelSubmitReportExt: Invalid report handle passed %p\n",
             param_1);
  return 0xc000000d;
}



===== WerStartSystemErrorHandler @ 14000be6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 WerStartSystemErrorHandler(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_48;
  int local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = CONCAT44(local_58._4_4_,4);
  local_30 = 0;
  local_38[0] = 0;
  iVar4 = 0;
  iVar2 = ZwQueryWnfStateNameInformation(&WNF_WER_SERVICE_START,1,0,local_38);
  if ((-1 < iVar2) && (local_38[0] != 0)) {
    local_48 = 0;
    local_50 = 0;
    local_58 = 0;
    iVar2 = ZwUpdateWnfStateData(&WNF_WER_SERVICE_START,0,0,0);
    iVar4 = 0;
    if (-1 < iVar2) {
      iVar4 = 1;
    }
  }
  iVar2 = EtwRegister(&DAT_140006d28,0,0,&local_30);
  if (-1 < iVar2) {
    local_28 = 0;
    uStack_20 = 0;
    cVar1 = EtwEventEnabled(local_30,&local_28);
    if (cVar1 != '\0') {
      local_58 = 0;
      iVar2 = EtwWrite(local_30,&local_28,0,0);
      if (-1 < iVar2) {
        iVar4 = iVar4 + 1;
      }
    }
    EtwUnregister(local_30);
  }
  uVar3 = 0;
  if (iVar4 == 0) {
    uVar3 = 0xc0000080;
  }
  return uVar3;
}



===== WerWaitForSystemErrorHandler @ 14000bfa4 =====

ulonglong WerWaitForSystemErrorHandler(int param_1)

{
  uint uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  undefined8 local_res10;
  longlong local_res18;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_48 = 0x480046;
  local_40 = L"\\KernelObjects\\SystemErrorPortReady";
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x200;
  local_res10 = 0;
  local_res18 = 0;
  local_30 = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = ZwOpenEvent(&local_res10,0x100001,&local_38);
  if (-1 < (int)uVar2) {
    plVar3 = &local_res18;
    if (param_1 == -1) {
      plVar3 = (longlong *)0x0;
    }
    else {
      local_res18 = (longlong)param_1 * -10000;
    }
    uVar1 = ZwWaitForSingleObject(local_res10,0,plVar3);
    uVar2 = (ulonglong)uVar1;
    ZwClose(local_res10);
  }
  return uVar2;
}



===== WerpAllocateAndInitializeSid @ 14000c078 =====

int WerpAllocateAndInitializeSid(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  longlong *in_stack_00000058;
  
  iVar2 = -0x3fffffff;
  iVar1 = RtlLengthRequiredSid(1);
  if (in_stack_00000058 == (longlong *)0x0) {
    DbgPrintEx(5,1,"WERKERNELHOST: Invalid params\n");
    iVar2 = -0x3ffffff3;
  }
  else {
    lVar3 = WerpAllocateMem(iVar1);
    if (lVar3 == 0) {
      DbgPrintEx(5,1,"WERKERNELHOST: NtAllocateVirtualMemory failed\n");
    }
    else {
      iVar2 = RtlInitializeSid(lVar3,param_1,1);
      if (iVar2 < 0) {
        DbgPrintEx(5,1,"WERKERNELHOST: RtlInitializeSid failed\n");
        ExFreePoolWithTag(lVar3,0);
        lVar3 = 0;
      }
      else {
        puVar4 = (undefined4 *)RtlSubAuthoritySid(lVar3,0);
        iVar2 = 0;
        *puVar4 = 0x12;
      }
    }
    *in_stack_00000058 = lVar3;
  }
  return iVar2;
}



===== WerpAllocateMem @ 14000c184 =====

void WerpAllocateMem(int param_1)

{
  ExAllocatePoolWithTag(0x401,(longlong)param_1,0x7765726b);
  return;
}



===== WerpCancelReport @ 14000c1b0 =====

int WerpCancelReport(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong local_res8;
  
  local_res8 = 0;
  if (param_1 == 0) {
    DbgPrintEx(5,1,"WERKERNELHOST: Invalid handle passed to WerpCancelReport\n");
    iVar1 = -0x3ffffff3;
  }
  else {
    iVar1 = WerpCreateRegistryKey(param_1,0x140005178,0x10000,'\x01',(longlong)&local_res8,0);
    if ((-1 < iVar1) && (local_res8 != 0)) {
      ZwDeleteKey();
      ZwClose(local_res8);
    }
    iVar2 = ZwDeleteKey(param_1);
    if (iVar2 < 0) {
      DbgPrintEx(5,1,"WERKERNELHOST: ZwDeleteKey failed with 0x%x\n",iVar1);
    }
  }
  return iVar1;
}



===== WerpCheckDiskSpace @ 14000c284 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 WerpCheckDiskSpace(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  int iVar3;
  undefined1 uVar4;
  char *pcVar5;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined4 local_80;
  longlong local_78 [2];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined2 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_3c = 0;
  local_78[0] = 0;
  local_50 = 0;
  local_58 = 0x30;
  local_18 = 0;
  local_40 = 0x200;
  local_48 = &WerKernelLiveReportRootPath;
  local_80 = 1;
  uVar4 = 0;
  local_88 = 3;
  local_68 = 0;
  uStack_60 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar3 = ZwOpenFile(local_78,0x20000,&local_58,&local_68);
  if (iVar3 < 0) {
    pcVar5 = "WERKERNELHOST: Could not open root dump directory, status 0x%X\n";
  }
  else {
    local_88 = 3;
    iVar3 = ZwQueryVolumeInformationFile(local_78[0],&local_68,&local_28,0x18);
    if (-1 < iVar3) {
      if (SUB168(ZEXT416(local_18._4_4_) * ZEXT416((uint)local_18),8) == 0) {
        auVar1._8_8_ = 0;
        auVar1._0_8_ = SUB168(ZEXT416(local_18._4_4_) * ZEXT416((uint)local_18),0);
        auVar2._8_8_ = 0;
        auVar2._0_8_ = uStack_20;
        if (SUB168(auVar1 * auVar2,8) == 0) {
          if (0xaeffffff < (SUB168(auVar1 * auVar2,0) & 0xfffffffffff00000)) {
            uVar4 = 1;
            goto LAB_14000c3cd;
          }
          pcVar5 = "WERKERNELHOST: Free disk space is below minimum allowed by policy\n";
        }
        else {
          pcVar5 = "WERKERNELHOST: Failed to calcalate DiskTotalFreeSpaceInBytes\n";
        }
      }
      else {
        pcVar5 = "WERKERNELHOST: Failed to calcalate BytesPerAllocationUnit\n";
      }
      DbgPrintEx(5,1,pcVar5);
      goto LAB_14000c3cd;
    }
    pcVar5 = "WERKERNELHOST: Failed to retrieve disk free space, status 0x%X\n";
  }
  DbgPrintEx(5,1,pcVar5,iVar3);
LAB_14000c3cd:
  if (local_78[0] != 0) {
    ZwClose();
  }
  return uVar4;
}



===== WerpCheckPolicy @ 14000c40c =====

undefined8 WerpCheckPolicy(wchar_t *param_1,int param_2,int *param_3,int *param_4)

{
  undefined8 uVar1;
  int iVar2;
  
  if ((param_3 == (int *)0x0) || (param_1 == (wchar_t *)0x0)) {
    DbgPrintEx(5,1,"WERKERNELHOST: WerpCheckPolicy: invalid parameter\n");
    if (param_3 != (int *)0x0) {
      *param_3 = 0;
    }
    uVar1 = 0xc000000d;
  }
  else {
    DbgPrintEx(5,3,"WERKERNELHOST: WerpCheckPolicy: Requested Policy is %i \n",param_2);
    if (WerHighestAllowedPolicy < param_2) {
      DbgPrintEx(5,1,
                 "WERKERNELHOST: WerpCheckPolicy: Requested Policy %i is higher than highest allowed %i\n"
                 ,param_2,WerHighestAllowedPolicy);
      iVar2 = WerHighestAllowedPolicy;
    }
    else {
      iVar2 = param_2;
    }
    if (iVar2 == 2) {
      uVar1 = WerpFullDumpIsThrottled(param_1,param_4);
      if ((char)uVar1 != '\0') {
        iVar2 = 0;
      }
    }
    if (iVar2 < param_2) {
      DbgPrintEx(5,1,
                 "WERKERNELHOST: WerpCheckPolicy: Requested Policy %i is higher than granted %i\n",
                 param_2,iVar2);
    }
    else {
      DbgPrintEx(5,3,"WERKERNELHOST: WerpCheckPolicy: Granting requested policy %i\n",iVar2);
    }
    *param_3 = iVar2;
    uVar1 = 0;
  }
  return uVar1;
}



===== WerpCheckSpaceAvailable @ 14000c544 =====

undefined8 WerpCheckSpaceAvailable(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  int local_res10 [2];
  
  uVar3 = 0;
  local_res10[0] = 0;
  iVar1 = ZwQueryKey(param_1,2,0,0,local_res10);
  if ((iVar1 == -0x7ffffffb) || (iVar1 == -0x3fffffdd)) {
    lVar2 = WerpAllocateMem(local_res10[0]);
    if (lVar2 == 0) {
      DbgPrintEx(5,1,"WERKERNELHOST: Out of memory.\n");
    }
    else {
      iVar1 = ZwQueryKey(param_1,2,lVar2,local_res10[0],local_res10);
      if (iVar1 < 0) {
        DbgPrintEx(5,1,"WERKERNELHOST: ZwQueryKey failed with 0x%x\n",iVar1);
      }
      else if (*(uint *)(lVar2 + 0x14) < 10) {
        uVar3 = 1;
      }
      else {
        DbgPrintEx(5,1,"WERKERNELHOST: Live kernel queue size exceeded\n");
      }
      ExFreePoolWithTag(lVar2,0);
    }
  }
  else {
    DbgPrintEx(5,1,"WERKERNELHOST: ZwQueryKey failed while determining the size with 0x%x\n",iVar1);
  }
  return uVar3;
}



===== WerpCheckSpaceAvailableFull @ 14000c674 =====

undefined8 WerpCheckSpaceAvailableFull(undefined8 param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  int local_res18 [2];
  undefined4 local_res20 [2];
  uint local_48;
  uint local_44;
  longlong local_40;
  
  local_res18[0] = 0;
  local_res20[0] = 0;
  uVar8 = 0;
  local_40 = 0;
  local_48 = 0;
  lVar4 = WerpAllocateMem(0x38);
  uVar1 = DAT_140008348;
  uVar6 = 0;
  if (lVar4 == 0) {
    return 0;
  }
LAB_14000c844:
  do {
    iVar3 = ZwEnumerateKey(param_1,uVar6,0,lVar4,0x36,local_res20);
    if (iVar3 == -0x7fffffe6) {
LAB_14000c8cc:
      iVar3 = WerpCountFullDump((int *)&local_48);
      if (iVar3 < 0) {
        DbgPrintEx(5,1,"WERKERNELHOST: WerpCountFullDump failed with 0x%x\n",iVar3);
      }
      ExFreePoolWithTag(lVar4,0);
      if (uVar1 == 0) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        pcVar7 = "WERKERNELHOST: Full live kernel collection is disabled\n";
      }
      else if (uVar1 < uVar8) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 0x20;
        }
        pcVar7 = "WERKERNELHOST: Full live kernel queue size exceeded\n";
      }
      else {
        if (local_48 < uVar1) {
          return 1;
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 0x21;
        }
        pcVar7 = "WERKERNELHOST: Full live kernel dump count exceeded\n";
      }
      DbgPrintEx(5,1,pcVar7);
      return 0;
    }
    if (-1 < iVar3) {
      uVar2 = uVar6 + 1;
      if (uVar2 < uVar6) goto LAB_14000c8cc;
      *(undefined2 *)(lVar4 + 0x10 + (ulonglong)(*(uint *)(lVar4 + 0xc) >> 1) * 2) = 0;
      local_44 = uVar2;
      iVar3 = WerpGetRegistryKey(param_1,lVar4 + 0x10,0x20019,(longlong)&local_40);
      if (iVar3 < 0) {
        DbgPrintEx(5,1,"WERKERNELHOST: WerpCheckSpaceAvailableFull: Failed to open key %ws\n",
                   lVar4 + 0x10);
        uVar6 = uVar2;
        if (local_40 != 0) {
          ZwClose();
          local_40 = 0;
        }
      }
      else {
        iVar3 = ZwQueryKey(local_40,2,0,0,local_res18);
        if ((iVar3 != -0x7ffffffb) && (iVar3 != -0x3fffffdd)) {
          DbgPrintEx(5,1,
                     "WERKERNELHOST: WerpCheckSpaceAvailableFull: ZwQueryKey failed while determining the size with 0x%x\n"
                     ,iVar3);
          goto LAB_14000c8cc;
        }
        lVar5 = WerpAllocateMem(local_res18[0]);
        if (lVar5 == 0) {
          DbgPrintEx(5,1,"WERKERNELHOST: WerpCheckSpaceAvailableFull: Out of memory\n");
          if (local_40 != 0) {
            ZwClose();
            local_40 = 0;
          }
          goto LAB_14000c8cc;
        }
        iVar3 = ZwQueryKey(local_40,2,lVar5,local_res18[0],local_res18);
        if (iVar3 < 0) {
          DbgPrintEx(5,1,"WERKERNELHOST: ZwQueryKey failed with 0x%x\n",iVar3);
        }
        else {
          uVar8 = uVar8 + *(int *)(lVar5 + 0x14);
        }
        if (local_40 != 0) {
          ZwClose();
          local_40 = 0;
        }
        ExFreePoolWithTag(lVar5,0);
        if ((iVar3 < 0) || (uVar6 = local_44, uVar1 < uVar8)) goto LAB_14000c8cc;
      }
      goto LAB_14000c844;
    }
    DbgPrintEx(5,1,
               "WERKERNELHOST: WerpCheckSpaceAvailableFull: ZwEnumerateKey returned status 0x%X\n",
               iVar3);
  } while( true );
}



===== WerpCloseHandle @ 14000c990 =====

int WerpCloseHandle(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    DbgPrintEx(5,3,"WERKERNELHOST: WerpCloseHandle: NULL handle\n");
    iVar1 = -0x3ffffff3;
  }
  else {
    iVar1 = ZwClose();
    uVar2 = 1;
    if (-1 < iVar1) {
      uVar2 = 3;
    }
    DbgPrintEx(5,uVar2,"WERKERNELHOST: WerpCloseHandle: ZwClose(%p) returned 0x%X\n",param_1,iVar1);
  }
  return iVar1;
}



===== WerpCountFullDump @ 14000ca10 =====

int WerpCountFullDump(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  char *pcVar4;
  uint uVar5;
  longlong local_res8;
  undefined1 uVar6;
  undefined8 local_68;
  wchar_t *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined2 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_68 = 0xc000a;
  local_2c = 0;
  local_44 = 0;
  local_60 = L"*.dmp";
  if (param_1 == (int *)0x0) {
    DbgPrintEx(5,1,"WERKERNELHOST: WerpCountFullDump: Invalid params\n");
    iVar1 = -0x3ffffff3;
  }
  else {
    local_res8 = 0;
    puVar2 = (uint *)0x0;
    local_48 = 0x30;
    *param_1 = 0;
    local_40 = 0;
    local_30 = 0x240;
    local_38 = &WerKernelLiveReportRootPath;
    local_58 = 0;
    uStack_50 = 0;
    local_28 = 0;
    uStack_20 = 0;
    iVar1 = ZwOpenFile(&local_res8,0x100001,&local_48,&local_58,3,0x11);
    if (iVar1 < 0) {
      pcVar4 = "WERKERNELHOST: Could not open root dump directory, status 0x%X\n";
LAB_14000caef:
      DbgPrintEx(5,1,pcVar4,iVar1);
    }
    else {
      uVar5 = 10;
      if (DAT_140008348 < 10) {
        uVar5 = DAT_140008348;
      }
      uVar5 = (uVar5 + 1) * 0x214;
      puVar2 = (uint *)WerpAllocateMem(uVar5);
      if (puVar2 == (uint *)0x0) {
        iVar1 = -0x3fffffe9;
      }
      else {
        uVar6 = 1;
        while ((iVar1 = ZwQueryDirectoryFile
                                  (local_res8,0,0,0,&local_58,puVar2,uVar5,0xc,0,&local_68,uVar6),
               iVar1 != -0x3ffffff1 && (iVar1 != -0x7ffffffa))) {
          if (iVar1 < 0) {
            pcVar4 = "WERKERNELHOST: ZwQueryDirectoryFile failed with status 0x%X\n";
            goto LAB_14000caef;
          }
          for (puVar3 = puVar2; puVar3 < (uint *)((ulonglong)uVar5 + (longlong)puVar2);
              puVar3 = (uint *)((longlong)puVar3 + (ulonglong)*puVar3)) {
            *param_1 = *param_1 + 1;
            if (*puVar3 == 0) break;
          }
          uVar6 = 0;
        }
        iVar1 = 0;
      }
    }
    if (local_res8 != 0) {
      ZwClose();
      local_res8 = 0;
    }
    if (puVar2 != (uint *)0x0) {
      ExFreePoolWithTag(puVar2,0);
    }
    DbgPrintEx(5,3,"WERKERNELHOST: WerpCountFullDump returned FileCount 0x%X\n",*param_1);
  }
  return iVar1;
}



===== WerpCreateDumpFile @ 14000cc44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WerpCreateDumpFile(longlong param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  uint uVar2;
  ulonglong uVar3;
  char *pcVar4;
  undefined1 auStack_148 [32];
  wchar_t *local_128;
  longlong local_120;
  undefined4 local_118;
  undefined4 local_110;
  undefined4 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_148;
  local_58 = 0x101;
  local_d8 = 0;
  local_cc = 0;
  local_b4 = 0;
  local_70 = 0;
  local_54 = 0x5000000;
  local_50 = 0x12;
  local_a0 = 0;
  uStack_98 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  if ((param_1 == 0) || (param_2 == (undefined8 *)0x0)) {
    DbgPrintEx(5,1,"WERKERNELHOST: WerpCreateDumpFile: Invalid parameter\n");
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = 0;
    }
    return 0xc000000d;
  }
  pwVar1 = (wchar_t *)(param_1 + 0x88);
  *param_2 = 0;
  if (*pwVar1 != L'\0') {
    DbgPrintEx(5,1,"WERKERNELHOST: A dump file has already been opened. Filename %ws\n",pwVar1);
    return 0xc0000107;
  }
  if (*(int *)(param_1 + 4) == 1) {
    local_120 = param_1 + 0x38;
    local_128 = (wchar_t *)(param_1 + 0x18);
    uVar3 = RtlStringCchPrintfW(pwVar1,0x104,L"%wZ\\%ws\\%ws",&WerKernelLiveReportRootPath);
    if ((int)uVar3 < 0) {
      DbgPrintEx(5,1,"WERKERNELHOST: RtlStringCbPrintfW failed for wszFileName, status 0x%X. \n",
                 uVar3 & 0xffffffff);
      pcVar4 = "WERKERNELHOST: WerpSetDumpFileNameMini failed with status 0x%X.\n";
LAB_14000cd68:
      uVar3 = uVar3 & 0xffffffff;
      *pwVar1 = L'\0';
    }
    else {
      uVar2 = WerpCreateReportDirectory(param_1);
      if (-1 < (int)uVar2) goto LAB_14000cdf7;
      uVar3 = (ulonglong)uVar2;
      pcVar4 = "WERKERNELHOST: Failed to create report directory, status 0x%X\n";
    }
    DbgPrintEx(5,1,pcVar4,uVar3);
  }
  else {
    if (*(int *)(param_1 + 4) == 2) {
      local_128 = (wchar_t *)(param_1 + 0x38);
      uVar3 = RtlStringCchPrintfW(pwVar1,0x104,L"%wZ\\%ws",&WerKernelLiveReportRootPath);
      if ((int)uVar3 < 0) {
        DbgPrintEx(5,1,"WERKERNELHOST: RtlStringCbPrintfW failed for wszFileName, status 0x%X. \n",
                   uVar3 & 0xffffffff);
        pcVar4 = "WERKERNELHOST: WerpSetDumpFileNameKernel failed with status 0x%X.\n";
        goto LAB_14000cd68;
      }
    }
LAB_14000cdf7:
    uVar2 = RtlCreateSecurityDescriptor(&local_90,1);
    uVar3 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar2 = RtlSetOwnerSecurityDescriptor(&local_90,&local_58,0);
      uVar3 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        RtlInitUnicodeString(&local_a0,pwVar1);
        local_e0 = 0x100;
        local_c0 = &local_a0;
        local_e8 = 0;
        local_f0 = 0;
        local_f8 = 0;
        local_100 = 0;
        local_108 = 0x22;
        local_110 = 2;
        local_b0 = &local_90;
        local_118 = 0;
        local_120 = CONCAT44(local_120._4_4_,0x80);
        local_128 = (wchar_t *)0x0;
        local_d0 = 0x30;
        local_c8 = 0;
        local_b8 = 0x240;
        local_a8 = 0;
        uVar2 = IoCreateFile(&local_d8,0x120116,&local_d0,&local_68);
        uVar3 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          local_128 = (wchar_t *)CONCAT44(local_128._4_4_,uVar2);
          DbgPrintEx(5,1,"WERKERNELHOST: Could not create file %ws, status 0x%X\n",pwVar1);
          *pwVar1 = L'\0';
        }
        else {
          local_128 = pwVar1;
          DbgPrintEx(5,3,"WERKERNELHOST: WerpCreateDumpFile - created file handle %p, name %ws\n",
                     local_d8);
          *param_2 = local_d8;
        }
      }
    }
  }
  return uVar3;
}



===== WerpCreateRegistryKey @ 14000cf7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WerpCreateRegistryKey
              (undefined8 param_1,longlong param_2,undefined4 param_3,char param_4,longlong param_5,
              longlong param_6)

{
  int iVar1;
  undefined1 auStack_108 [32];
  undefined8 local_e8;
  uint local_e0;
  int *local_d8;
  int local_c8 [2];
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  local_60 = 0;
  local_58 = 0x101;
  local_bc = 0;
  local_a4 = 0;
  local_54 = 0x5000000;
  local_50 = 0x12;
  local_c8[0] = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  if ((param_2 == 0) || (param_5 == 0)) {
    DbgPrintEx(5,1,"WERKERNELHOST: Invalid params\n");
    iVar1 = -0x3ffffff3;
  }
  else {
    iVar1 = RtlCreateSecurityDescriptor(&local_80,1);
    if ((-1 < iVar1) && (iVar1 = RtlSetOwnerSecurityDescriptor(&local_80,&local_58,0), -1 < iVar1))
    {
      RtlInitUnicodeString(&local_90,param_2);
      local_98 = 0;
      local_b0 = &local_90;
      local_d8 = local_c8;
      local_a0 = &local_80;
      local_c0 = 0x30;
      local_a8 = 0x240;
      local_e0 = (uint)(param_4 != '\0');
      local_e8 = 0;
      local_b8 = param_1;
      iVar1 = ZwCreateKey(param_5,param_3,&local_c0,0);
      if (iVar1 < 0) {
        DbgPrintEx(5,1,"WERKERNELHOST: ZwCreateKey failed with scode 0x%x\n",iVar1);
      }
      else {
        if (param_6 != 0) {
          *(bool *)param_6 = local_c8[0] == 1;
        }
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



===== WerpCreateReport @ 14000d138 =====

int WerpCreateReport(int param_1,longlong param_2,longlong param_3,longlong *param_4,
                    undefined4 *param_5)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char *pcVar4;
  
  if ((((param_2 != 0) && (param_3 != 0)) && (param_4 != (longlong *)0x0)) && (param_1 != 0)) {
    uVar2 = 0xffffffffffffffff;
    uVar3 = 0xffffffffffffffff;
    do {
      uVar3 = uVar3 + 1;
    } while (*(short *)(param_2 + uVar3 * 2) != 0);
    if (uVar3 < 0x10) {
      do {
        uVar2 = uVar2 + 1;
      } while (*(short *)(param_3 + uVar2 * 2) != 0);
      if (uVar2 < 0x28) {
        if (WerKernelLiveReportInitialized == '\0') {
          return -0x3ffffffe;
        }
        iVar1 = WerpRefreshRootPath();
        if (param_1 == 1) {
          iVar1 = WerpCreateReportMini(param_2,param_3,param_4);
          return iVar1;
        }
        if (param_1 == 2) {
          iVar1 = WerpCreateReportFull(param_2,param_3,param_4,param_5);
          return iVar1;
        }
        return iVar1;
      }
      pcVar4 = "WERKERNELHOST: Key id length exceeded\n";
    }
    else {
      pcVar4 = "WERKERNELHOST: Key key length exceeded\n";
    }
    DbgPrintEx(5,1,pcVar4);
  }
  return -0x3ffffff3;
}



===== WerpCreateReportDirectory @ 14000d21c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WerpCreateReportDirectory(longlong param_1)

{
  int iVar1;
  undefined1 auStack_328 [32];
  undefined8 local_308;
  undefined4 local_300;
  undefined4 local_2f8;
  undefined4 local_2f0;
  undefined4 local_2e8;
  undefined8 local_2e0;
  undefined4 local_2d8;
  undefined4 local_2d0;
  undefined8 local_2c8;
  undefined4 local_2c0;
  ushort local_2b8 [4];
  undefined1 *puStack_2b0;
  undefined8 local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined8 local_298;
  ushort *local_290;
  undefined4 local_288;
  undefined4 local_284;
  undefined8 *local_280;
  undefined8 local_278;
  undefined8 local_270;
  longlong lStack_268;
  undefined8 local_260;
  undefined8 uStack_258;
  undefined8 local_250;
  undefined8 uStack_248;
  undefined8 local_240;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined1 local_228 [528];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_328;
  local_2a8 = 0;
  local_29c = 0;
  local_284 = 0;
  local_270 = 0;
  lStack_268 = 0;
  memset(local_228,0,0x208);
  local_238 = 0x101;
  local_234 = 0x5000000;
  local_240 = 0;
  local_230 = 0x12;
  local_260 = 0;
  uStack_258 = 0;
  local_2b8[0] = 0;
  local_2b8[1] = 0x208;
  local_2b8[2] = 0;
  local_2b8[3] = 0;
  local_250 = 0;
  uStack_248 = 0;
  puStack_2b0 = local_228;
  RtlCopyUnicodeString(local_2b8,&WerKernelLiveReportRootPath);
  iVar1 = RtlUnicodeStringCatString(local_2b8,L"\\");
  if (-1 < iVar1) {
    iVar1 = RtlUnicodeStringCatString(local_2b8,(short *)(param_1 + 0x18));
    if (iVar1 < 0) {
      DbgPrintEx(5,1,
                 "WERKERNELHOST: Failed to initialize report directory ReportType, status 0x%X\n",
                 iVar1);
    }
    else {
      iVar1 = RtlCreateSecurityDescriptor(&local_260,1);
      if (-1 < iVar1) {
        iVar1 = RtlSetOwnerSecurityDescriptor(&local_260,&local_238,0);
        if (-1 < iVar1) {
          local_2c0 = 0x100;
          local_290 = local_2b8;
          local_2c8 = 0;
          local_2d0 = 0;
          local_2d8 = 0;
          local_2e0 = 0;
          local_2e8 = 1;
          local_2f0 = 2;
          local_280 = &local_260;
          local_2f8 = 3;
          local_300 = 0x80;
          local_308 = 0;
          local_2a0 = 0x30;
          local_298 = 0;
          local_288 = 0x240;
          local_278 = 0;
          iVar1 = IoCreateFile(&local_2a8,0x10000000,&local_2a0,&local_270);
          if (iVar1 < 0) {
            if ((iVar1 == -0x3fffffcb) || (lStack_268 == 4)) {
              iVar1 = 0;
            }
          }
          else {
            ZwClose(local_2a8);
          }
        }
      }
    }
  }
  return iVar1;
}



===== WerpCreateReportFull @ 14000d42c =====

int WerpCreateReportFull(longlong param_1,longlong param_2,longlong *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  char local_48 [8];
  longlong local_40;
  longlong local_38;
  longlong local_30;
  longlong local_28;
  longlong local_20;
  
  local_40 = 0;
  local_38 = 0;
  local_28 = 0;
  local_20 = 0;
  local_30 = 0;
  iVar1 = WerpCreateRegistryKey(0,0x140008090,0x20004,'\0',(longlong)&local_30,0);
  if (iVar1 < 0) {
LAB_14000d497:
    pcVar3 = "WERKERNELHOST: ZwCreateKey failed with scode 0x%x for the root\n";
  }
  else {
    iVar1 = WerpCreateRegistryKey(local_30,0x140005a40,0x20004,'\0',(longlong)&local_40,0);
    if (iVar1 < 0) goto LAB_14000d497;
    uVar2 = WerpCheckSpaceAvailableFull(local_40,param_4);
    if ((int)uVar2 == 0) {
      iVar1 = -0x3fffff67;
      DbgPrintEx(5,1,"WERKERNELHOST: WerpCheckSpaceAvailable returned no more space available\n");
      goto LAB_14000d5fa;
    }
    iVar1 = WerpCreateRegistryKey(local_40,param_1,0x2001d,'\0',(longlong)&local_38,0);
    if (iVar1 < 0) {
LAB_14000d543:
      pcVar3 = "WERKERNELHOST: ZwCreateKey failed with scode 0x%x for the report type\n";
    }
    else {
      local_48[0] = '\0';
      iVar1 = WerpCreateRegistryKey
                        (local_38,param_2,0x30004,'\0',(longlong)&local_28,(longlong)local_48);
      if (-1 < iVar1) {
        if (local_48[0] == '\0') {
          iVar1 = -0x3fffffcb;
          DbgPrintEx(5,1,"WERKERNELHOST: Report id %S already exists\n",param_2);
          goto LAB_14000d5fa;
        }
        iVar1 = WerpCreateRegistryKey(local_28,0x140005178,0x30004,'\x01',(longlong)&local_20,0);
        if (-1 < iVar1) {
          ZwFlushKey(local_38);
          iVar1 = 0;
          goto LAB_14000d5fa;
        }
        goto LAB_14000d543;
      }
      pcVar3 = "WERKERNELHOST: ZwCreateKey failed with scode 0x%x for the report id\n";
    }
  }
  DbgPrintEx(5,1,pcVar3,iVar1);
LAB_14000d5fa:
  if (local_40 != 0) {
    ZwClose();
    local_40 = 0;
  }
  if (local_38 != 0) {
    ZwClose();
    local_38 = 0;
  }
  if (local_30 != 0) {
    ZwClose();
    local_30 = 0;
  }
  if (local_28 != 0) {
    if (iVar1 < 0) {
      ZwClose(local_28);
      local_28 = 0;
    }
    else {
      *param_3 = local_28;
    }
  }
  if (local_20 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== WerpCreateReportId @ 14000d6a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WerpCreateReportId(longlong param_1)

{
  ulonglong uVar1;
  undefined1 auStack_88 [32];
  int local_68;
  int local_60;
  int local_58;
  int local_50;
  int local_48;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  local_30 = _DAT_fffff78000000014;
  ExSystemTimeToLocalTime(&local_30,&local_38);
  RtlTimeToTimeFields(&local_38,&local_28);
  local_50 = (int)local_28._6_2_;
  local_58 = (int)local_28._4_2_;
  local_60 = (int)local_28._2_2_;
  local_48 = (int)(short)uStack_20;
  local_68 = (int)(short)local_28;
  uVar1 = RtlStringCbPrintfW((wchar_t *)(param_1 + 0x38),0x50,L"%ws-%04u%02u%02u-%02u%02u.dmp",
                             param_1 + 0x18);
  if ((int)uVar1 < 0) {
    *(wchar_t *)(param_1 + 0x38) = L'\0';
    DbgPrintEx(5,1,"WERKERNELHOST: RtlStringCbPrintfW failed for wszReportId, status 0x%X.\n",
               uVar1 & 0xffffffff);
  }
  return uVar1 & 0xffffffff;
}



===== WerpCreateReportMini @ 14000d7b4 =====

int WerpCreateReportMini(longlong param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  char local_res20 [8];
  longlong local_48;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  longlong local_28 [2];
  
  local_40 = 0;
  local_48 = 0;
  local_30 = 0;
  local_28[0] = 0;
  local_38 = 0;
  iVar1 = WerpCreateRegistryKey(0,0x140008090,0x20004,'\0',(longlong)&local_38,0);
  if (iVar1 < 0) {
LAB_14000d818:
    pcVar3 = "WERKERNELHOST: ZwCreateKey failed with scode 0x%x for the root\n";
  }
  else {
    iVar1 = WerpCreateRegistryKey(local_38,0x140005c18,0x20004,'\0',(longlong)&local_40,0);
    if (iVar1 < 0) goto LAB_14000d818;
    iVar1 = WerpCreateRegistryKey(local_40,param_1,0x2001d,'\0',(longlong)&local_48,0);
    if (iVar1 < 0) {
LAB_14000d891:
      pcVar3 = "WERKERNELHOST: ZwCreateKey failed with scode 0x%x for the report type\n";
    }
    else {
      uVar2 = WerpCheckSpaceAvailable(local_48);
      if ((int)uVar2 == 0) {
        iVar1 = -0x3fffff67;
        DbgPrintEx(5,1,"WERKERNELHOST: WerpCheckSpaceAvailable returned no more space available\n");
        goto LAB_14000d975;
      }
      local_res20[0] = '\0';
      iVar1 = WerpCreateRegistryKey
                        (local_48,param_2,0x30004,'\0',(longlong)&local_30,(longlong)local_res20);
      if (-1 < iVar1) {
        if (local_res20[0] == '\0') {
          iVar1 = -0x3fffffcb;
          DbgPrintEx(5,1,"WERKERNELHOST: Report id %S already exists\n",param_2);
          goto LAB_14000d975;
        }
        iVar1 = WerpCreateRegistryKey(local_30,0x140005178,0x30004,'\x01',(longlong)local_28,0);
        if (-1 < iVar1) {
          ZwFlushKey(local_48);
          iVar1 = 0;
          goto LAB_14000d975;
        }
        goto LAB_14000d891;
      }
      pcVar3 = "WERKERNELHOST: ZwCreateKey failed with scode 0x%x for the report id\n";
    }
  }
  DbgPrintEx(5,1,pcVar3,iVar1);
LAB_14000d975:
  if (local_40 != 0) {
    ZwClose();
    local_40 = 0;
  }
  if (local_48 != 0) {
    ZwClose();
    local_48 = 0;
  }
  if (local_38 != 0) {
    ZwClose();
    local_38 = 0;
  }
  if (local_30 != 0) {
    if (iVar1 < 0) {
      ZwClose(local_30);
      local_30 = 0;
    }
    else {
      *param_3 = local_30;
    }
  }
  if (local_28[0] != 0) {
    ZwClose();
  }
  return iVar1;
}



===== WerpCreateStoreDirectory @ 14000da20 =====

int WerpCreateStoreDirectory(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  int local_res8 [2];
  undefined8 local_res10;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined2 *local_48;
  undefined8 uStack_40;
  longlong local_38;
  ulonglong local_30;
  
  local_res10 = 0;
  local_res8[0] = 0;
  local_38 = 0;
  local_68 = 0;
  lStack_60 = 0;
  local_30 = local_30 & 0xffffffff00000000;
  lVar6 = 0;
  local_58 = 0;
  uStack_50 = 0;
  lVar7 = 0;
  local_48 = (undefined2 *)0x0;
  uStack_40 = 0;
  iVar1 = SecLookupWellKnownSid(0x1a,0,0,local_res8);
  if (iVar1 != -0x3fffffdd) {
    return iVar1;
  }
  lVar4 = WerpAllocateMem(local_res8[0]);
  if (lVar4 == 0) {
    return -0x3fffffff;
  }
  iVar1 = SecLookupWellKnownSid(0x1a,lVar4,local_res8[0],local_res8);
  if (-1 < iVar1) {
    iVar2 = RtlLengthSid(lVar4);
    iVar1 = SecLookupWellKnownSid(0x16,0,0,local_res8);
    if (iVar1 == -0x3fffffdd) {
      lVar5 = WerpAllocateMem(local_res8[0]);
      if (lVar5 == 0) {
        iVar1 = -0x3fffffff;
      }
      else {
        iVar1 = SecLookupWellKnownSid(0x16,lVar5,local_res8[0],local_res8);
        if (-1 < iVar1) {
          iVar3 = RtlLengthSid(lVar5);
          lVar6 = WerpAllocateMem(0x28);
          if ((lVar6 == 0) || (lVar7 = WerpAllocateMem(iVar2 + iVar3 + 0x20), lVar7 == 0)) {
            iVar1 = -0x3fffffff;
          }
          else {
            iVar1 = RtlCreateSecurityDescriptor(lVar6,1);
            if ((-1 < iVar1) &&
               ((iVar1 = RtlCreateAcl(lVar7,iVar2 + iVar3 + 0x20,2), -1 < iVar1 &&
                (iVar1 = RtlAddAccessAllowedAceEx(lVar7,2,3,0x10000000,lVar5), -1 < iVar1)))) {
              iVar1 = RtlAddAccessAllowedAceEx(lVar7,2,3,0x10000000,lVar4);
              if ((-1 < iVar1) &&
                 ((iVar1 = RtlSetDaclSecurityDescriptor(lVar6,1,lVar7,0), -1 < iVar1 &&
                  (iVar1 = RtlSetOwnerSecurityDescriptor(lVar6,lVar5,0), -1 < iVar1)))) {
                uStack_50 = 0;
                local_30 = 0;
                local_58 = CONCAT44(local_58._4_4_,0x30);
                uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
                local_48 = &WerKernelLiveReportRootPath;
                local_38 = lVar6;
                iVar1 = IoCreateFile(&local_res10,0x10000000,&local_58,&local_68,0,0x80,3,2,1,0,0,0,
                                     0,0x100);
                if (iVar1 < 0) {
                  if ((iVar1 == -0x3fffffcb) || (lStack_60 == 4)) {
                    iVar1 = 0;
                  }
                }
                else {
                  ZwClose(local_res10);
                }
              }
            }
          }
        }
        ExFreePoolWithTag(lVar5,0);
      }
    }
  }
  ExFreePoolWithTag(lVar4,0);
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0);
  }
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0);
  }
  return iVar1;
}



===== WerpDeleteDumpFile @ 14000dd80 =====

void WerpDeleteDumpFile(longlong param_1)

{
  short *psVar1;
  int iVar2;
  undefined8 local_res8;
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
  
  psVar1 = (short *)(param_1 + 0x88);
  local_res8 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_1c = 0;
  if (*psVar1 == 0) {
    DbgPrintEx(5,1,"WERKERNELHOST: WerpDeleteDumpFile No dump file to delete. \n");
  }
  else {
    RtlInitUnicodeString(&local_58,psVar1);
    local_28 = &local_58;
    local_38 = 0x30;
    local_30 = 0;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar2 = IoCreateFile(&local_res8,0x110000,&local_38,&local_48,0,0x80,7,1,0x1000,0,0,0,0,0x100);
    if (-1 < iVar2) {
      ZwClose(local_res8);
      *psVar1 = 0;
    }
  }
  return;
}



===== WerpExceedsPerComponentThreshold @ 14000de9c =====

ulonglong WerpExceedsPerComponentThreshold
                    (wchar_t *param_1,longlong param_2,ulonglong param_3,undefined1 *param_4)

{
  ulonglong uVar1;
  int iVar2;
  char cVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  char local_res20 [8];
  ulonglong local_58 [6];
  
  local_res20[0] = '\0';
  local_58[0] = 0;
  lVar6 = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  if (param_4 == (undefined1 *)0x0) {
    DbgPrintEx(5,1,
               "WERKERNELHOST: WerpExceedsPerComponentThreshold: Invalid param OverrideSystemPolicy\n"
              );
  }
  else {
    *param_4 = 0;
  }
  RtlInitUnicodeString(local_58 + 3,param_1);
  for (lVar5 = DAT_140008358; lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x28)) {
    RtlInitUnicodeString(local_58 + 1,lVar5);
    cVar3 = RtlEqualUnicodeString(local_58 + 3,local_58 + 1,0);
    if (cVar3 != '\0') {
      lVar6 = *(longlong *)(lVar5 + 0x20);
      break;
    }
  }
  uVar4 = WerpQueryComponentOverridePolicy(param_1,local_res20,local_58);
  uVar1 = local_58[0];
  if (local_res20[0] != '\0') {
    if (param_4 != (undefined1 *)0x0) {
      *param_4 = 1;
    }
    uVar4 = DbgPrintEx(5,3,
                       "WERKERNELHOST: Component %ws: OverridePolicy enabled. New threshold time %lli\n"
                       ,param_1,local_58[0]);
    param_3 = uVar1;
  }
  if (lVar6 == 0) {
LAB_14000e022:
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else {
    uVar1 = lVar6 + param_3;
    iVar2 = (int)(lVar6 >> 0x3f);
    if ((-iVar2 != -(int)((longlong)param_3 >> 0x3f)) ||
       (-(uint)(0x7fffffffffffffff < uVar1) == iVar2)) {
      if ((longlong)uVar1 <= param_2) {
        uVar4 = DbgPrintEx(5,3,
                           "WERKERNELHOST: Component %ws: Threshold time is met. Threshold time %lli, Current time %lli\n"
                           ,param_1,uVar1,param_2);
        goto LAB_14000e022;
      }
      uVar4 = DbgPrintEx(5,1,
                         "WERKERNELHOST: Component %ws: Threshold time is not met. Threshold time %lli, Current time %lli\n"
                         ,param_1,uVar1,param_2);
    }
    uVar4 = CONCAT71((int7)(uVar4 >> 8),1);
  }
  return uVar4;
}



===== WerpExceedsSystemThreshold @ 14000e04c =====

undefined8 WerpExceedsSystemThreshold(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
  uVar2 = WerKernelThrottlePolicy + param_2;
  if (((uint)(WerKernelThrottlePolicy < 0) != -(int)(param_2 >> 0x3f)) ||
     (uVar1 = 0, WerKernelThrottlePolicy < 0 == 0x7fffffffffffffff < uVar2)) {
    if ((longlong)uVar2 <= param_1) {
      uVar2 = DbgPrintEx(5,3,
                         "WERKERNELHOST: System threshold time is met. Threshold time %lli, Current time %lli\n"
                         ,uVar2,param_1);
      return uVar2 & 0xffffffffffffff00;
    }
    uVar1 = DbgPrintEx(5,1,
                       "WERKERNELHOST: System threshold time is not met. Threshold time %lli, Current time %lli\n"
                       ,uVar2,param_1);
  }
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== WerpFreeMem @ 14000e0e0 =====

void WerpFreeMem(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== WerpFullDumpIsThrottled @ 14000e104 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WerpFullDumpIsThrottled(wchar_t *param_1,int *param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  uint7 extraout_var;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  char local_res18 [8];
  uint local_res20 [2];
  
  WerpRefreshThrottlePolicy();
  lVar1 = _DAT_fffff78000000014;
  uVar6 = 0xffffffffffffffff;
  if (DAT_140008350 != 0xffffffffffffffff) {
    lVar4 = MmGetPhysicalMemoryRanges();
    if (lVar4 == 0) {
      DbgPrintEx(5,1,
                 "WERKERNELHOST: Failed to get the number of pages. System Memory Policy will be disabled.\n"
                );
    }
    else {
      uVar5 = 0;
      lVar7 = 0;
      uVar6 = *(ulonglong *)(lVar4 + 8);
      while (uVar6 != 0) {
        uVar5 = uVar5 + 1;
        lVar7 = lVar7 + (uVar6 >> 0xc);
        uVar6 = *(ulonglong *)(lVar4 + 8 + (ulonglong)uVar5 * 0x10);
      }
      uVar6 = lVar7 << 0xc;
      ExFreePoolWithTag(lVar4,0);
    }
    if (DAT_140008350 < uVar6) {
      uVar6 = DbgPrintEx(5,1,
                         "WERKERNELHOST: System memory threshold is not met. Memory Threshold %I64u bytes, SystemMemory %I64u bytes\n"
                         ,DAT_140008350,uVar6);
      if (param_2 != (int *)0x0) {
        *param_2 = 0x10;
      }
      goto LAB_14000e2b3;
    }
    DbgPrintEx(5,1,
               "WERKERNELHOST: System memory threshold is met. Memory Threshold %I64u bytes, SystemMemory %I64u bytes\n"
               ,DAT_140008350,uVar6);
  }
  local_res18[0] = '\0';
  iVar3 = _wcsicmp(L"VerifierExt",param_1);
  if (iVar3 == 0) {
    local_res20[0] = 0;
    iVar3 = MmIsVerifierEnabled(local_res20);
    if ((iVar3 < 0) || ((local_res20[0] & 0x400000) == 0)) goto LAB_14000e25d;
    uVar6 = WerpExceedsPerComponentThreshold(param_1,lVar1,DAT_140008340,local_res18);
    if ((char)uVar6 != '\0') goto LAB_14000e278;
    if (local_res18[0] == '\0') {
      lVar4 = DAT_140008338;
      goto LAB_14000e29c;
    }
  }
  else {
LAB_14000e25d:
    uVar6 = WerpExceedsPerComponentThreshold(param_1,lVar1,DAT_140008330,local_res18);
    if ((char)uVar6 != '\0') {
LAB_14000e278:
      if (param_2 != (int *)0x0) {
        uVar6 = uVar6 & 0xffffffffffffff00;
        *param_2 = (local_res18[0] != '\0') + 0x11;
      }
      goto LAB_14000e2b3;
    }
    if (local_res18[0] == '\0') {
      lVar4 = DAT_140008328;
LAB_14000e29c:
      uVar6 = WerpExceedsSystemThreshold(lVar1,lVar4);
      if ((char)uVar6 != '\0') {
        if (param_2 != (int *)0x0) {
          *param_2 = 0x13;
        }
        goto LAB_14000e2b3;
      }
    }
  }
  cVar2 = WerpCheckDiskSpace();
  uVar6 = CONCAT71(extraout_var,cVar2);
  if (cVar2 != '\0') {
    return (ulonglong)extraout_var << 8;
  }
  *param_2 = 0x14;
LAB_14000e2b3:
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== WerpGetRegistryKey @ 14000e2e0 =====

int WerpGetRegistryKey(undefined8 param_1,longlong param_2,undefined4 param_3,longlong param_4)

{
  int iVar1;
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
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if ((param_2 == 0) || (param_4 == 0)) {
    DbgPrintEx(5,1,"WERKERNELHOST: Invalid params\n");
    iVar1 = -0x3ffffff3;
  }
  else {
    RtlInitUnicodeString(&local_48);
    local_28 = &local_48;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    local_30 = param_1;
    iVar1 = ZwOpenKey(param_4,param_3,&local_38);
    if (iVar1 < 0) {
      DbgPrintEx(5,1,"WERKERNELHOST: ZwOpenKey failed with scode 0x%x\n",iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== WerpGetRegistryLong64Value @ 14000e3cc =====

int WerpGetRegistryLong64Value
              (longlong param_1,longlong param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  longlong local_res18 [2];
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_4 == (undefined8 *)0x0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    local_res18[0] = 0;
    iVar1 = WerpGetRegistryValueInfo(param_1,param_2,local_res18);
    if (((iVar1 < 0) || (local_res18[0] == 0)) ||
       ((*(int *)(local_res18[0] + 4) != 0xb || (*(int *)(local_res18[0] + 8) != 8)))) {
      *param_4 = 0;
    }
    else {
      *param_4 = *(undefined8 *)(local_res18[0] + 0xc);
    }
    if (local_res18[0] != 0) {
      ExFreePoolWithTag(local_res18[0],0);
    }
  }
  return iVar1;
}



===== WerpGetRegistryTimeoutValue @ 14000e458 =====

int WerpGetRegistryTimeoutValue(longlong param_1,longlong param_2,uint param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  if (param_4 == (longlong *)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    iVar1 = WerpGetRegistryUlongValue(param_1,param_2,param_3,local_res20);
    if ((iVar1 < 0) || (lVar2 = (ulonglong)local_res20[0] * 36000000000, lVar2 < 0)) {
      lVar2 = (ulonglong)param_3 * 36000000000;
    }
    *param_4 = lVar2;
  }
  return iVar1;
}



===== WerpGetRegistryUlongValue @ 14000e4c0 =====

int WerpGetRegistryUlongValue
              (longlong param_1,longlong param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  longlong local_res8;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_4 == (undefined4 *)0x0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    local_res8 = 0;
    iVar1 = WerpGetRegistryValueInfo(param_1,param_2,&local_res8);
    if (((iVar1 < 0) || (local_res8 == 0)) ||
       ((*(int *)(local_res8 + 4) != 4 || (*(int *)(local_res8 + 8) != 4)))) {
      *param_4 = param_3;
    }
    else {
      *param_4 = *(undefined4 *)(local_res8 + 0xc);
    }
    if (local_res8 != 0) {
      ExFreePoolWithTag(local_res8,0);
    }
  }
  return iVar1;
}



===== WerpGetRegistryValueInfo @ 14000e54c =====

int WerpGetRegistryValueInfo(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_res18 [2];
  
  local_res18[0] = 0;
  *param_3 = 0;
  lVar2 = WerpAllocateMem(0x206);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = ZwQueryValueKey(param_1,param_2,2,lVar2,0x206,local_res18);
    if (-1 < iVar1) goto LAB_14000e5d0;
    ExFreePoolWithTag(lVar2,0);
  }
  lVar2 = 0;
LAB_14000e5d0:
  *param_3 = lVar2;
  return iVar1;
}



===== WerpQueryComponentOverridePolicy @ 14000e5f4 =====

ulonglong WerpQueryComponentOverridePolicy(wchar_t *param_1,undefined1 *param_2,ulonglong *param_3)

{
  uint uVar1;
  wchar_t *pwVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  char *pcVar5;
  longlong local_res18 [2];
  wchar_t *pwVar6;
  ulonglong uVar7;
  undefined8 local_28;
  wchar_t *local_20;
  
  local_28 = 0x340032;
  local_20 = L"OverrideThrottleThreshold";
  if ((param_3 == (ulonglong *)0x0) || (param_2 == (undefined1 *)0x0)) {
    DbgPrintEx(5,1,"WERKERNELHOST: WerpQueryComponentOverridePolicy: Invalid params\n");
    return 0xc000000d;
  }
  *param_3 = 0;
  local_res18[0] = 0;
  *param_2 = 0;
  pwVar2 = (wchar_t *)WerpAllocateMem(0xd0);
  if (pwVar2 == (wchar_t *)0x0) {
    DbgPrintEx(5,1,"WERKERNELHOST: WerpAllocateMem failed: Out of memory.\n");
    uVar4 = 0xc0000017;
    goto LAB_14000e75b;
  }
  pwVar6 = param_1;
  uVar4 = RtlStringCchPrintfW(pwVar2,0x68,L"%ws\\%ws",
                              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\FullLiveKernelReports"
                             );
  uVar1 = (uint)uVar4;
  uVar4 = uVar4 & 0xffffffff;
  if ((int)uVar1 < 0) {
    pcVar5 = 
    "WERKERNELHOST: RtlStringCbPrintfW failed for generating KeyBuffer for component %ws, status 0x%X.\n"
    ;
LAB_14000e73e:
    uVar3 = 1;
LAB_14000e746:
    uVar7 = (ulonglong)uVar1;
  }
  else {
    uVar1 = WerpGetRegistryKey(0,(longlong)pwVar2,0x20019,(longlong)local_res18);
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      pcVar5 = "WERKERNELHOST: WerpGetRegistryKey failed for opening %ws, status 0x%X.\n";
      uVar3 = 3;
      param_1 = pwVar2;
      goto LAB_14000e746;
    }
    uVar1 = WerpGetRegistryTimeoutValue(local_res18[0],(longlong)&local_28,0xa8,(longlong *)param_3)
    ;
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        uVar4 = 0;
        DbgPrintEx(5,3,"WERKERNELHOST: OverridePolicy not found for component %ws\n",param_1,pwVar6)
        ;
        goto LAB_14000e75b;
      }
      pcVar5 = "WERKERNELHOST: Failed to query OverridePolicy for component %ws, status 0x%X\n";
      goto LAB_14000e73e;
    }
    uVar7 = *param_3;
    pcVar5 = 
    "WERKERNELHOST: OverridePolicy found for component %ws, Overridden threshold time %lli\n";
    *param_2 = 1;
    uVar3 = 3;
  }
  DbgPrintEx(5,uVar3,pcVar5,param_1,uVar7);
LAB_14000e75b:
  if (local_res18[0] != 0) {
    ZwClose();
    local_res18[0] = 0;
  }
  if (pwVar2 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar2,0);
  }
  return uVar4;
}



===== WerpRefreshRootPath @ 14000e7cc =====

int WerpRefreshRootPath(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  wchar_t *pwVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  ulonglong _Size;
  char *pcVar9;
  bool bVar10;
  bool bVar11;
  longlong local_res10;
  longlong local_res18;
  undefined8 local_58;
  wchar_t *local_50;
  undefined8 local_48;
  wchar_t *pwStack_40;
  
  local_58 = 0x2c002a;
  local_50 = L"LiveKernelReportsPath";
  if (WerKernelLiveReportInitialized == '\0') {
    return -0x3fffffff;
  }
  local_res10 = 0;
  bVar10 = DAT_140008368 != L"\\SystemRoot\\LiveKernelReports";
  local_res18 = 0;
  bVar2 = false;
  iVar7 = WerpGetRegistryKey(0,0x140006970,0x20000,(longlong)&local_res18);
  if (iVar7 < 0) goto LAB_14000ea6f;
  iVar7 = WerpGetRegistryValueInfo(local_res18,&local_58,&local_res10);
  lVar6 = local_res10;
  bVar3 = true;
  if (iVar7 < 0) {
    if (bVar10) {
LAB_14000e90b:
      DbgPrintEx(5,3,"WERKERNELHOST: The live reports root path has changed.\n");
      pwVar5 = DAT_140008368;
      uVar4 = WerKernelLiveReportRootPath;
      local_res10 = CONCAT62(local_res10._2_6_,DAT_140008362);
      if (bVar10) {
        if (bVar2) goto LAB_14000e993;
        WerKernelLiveReportRootPath = 0x3a;
        DAT_140008362 = 0x3c;
        DAT_140008368 = L"\\SystemRoot\\LiveKernelReports";
      }
      else {
        DAT_140008368 = (wchar_t *)0x0;
        bVar3 = false;
        WerKernelLiveReportRootPath = 0;
        DAT_140008362 = 0;
        if (bVar2) {
LAB_14000e993:
          DAT_140008368 = (wchar_t *)0x0;
          DAT_140008362 = 0;
          WerKernelLiveReportRootPath = 0;
          DAT_140008368 = (wchar_t *)WerpAllocateMem(*(int *)(lVar6 + 8));
          if (DAT_140008368 == (wchar_t *)0x0) {
            pcVar9 = 
            "WERKERNELHOST: New root path buffer could not be allocated. Using existing path.\n";
            DAT_140008362 = (undefined2)local_res10;
            iVar7 = -0x3fffffe9;
            WerKernelLiveReportRootPath = uVar4;
            DAT_140008368 = pwVar5;
            goto LAB_14000e8ef;
          }
          DAT_140008362 = *(undefined2 *)(lVar6 + 8);
          WerKernelLiveReportRootPath = *(short *)(lVar6 + 8) - 2;
          memcpy(DAT_140008368,(void *)(lVar6 + 0xc),(ulonglong)WerKernelLiveReportRootPath);
        }
      }
      iVar7 = WerpCreateStoreDirectory();
      if (iVar7 < 0) {
        DbgPrintEx(5,0,"WERKERNELHOST: Could not create new root path. Using existing path.\n");
        DAT_140008362 = (undefined2)local_res10;
        WerKernelLiveReportRootPath = uVar4;
        DAT_140008368 = pwVar5;
      }
      else if ((bVar3) && (pwVar5 != (wchar_t *)0x0)) {
        ExFreePoolWithTag(pwVar5,0);
      }
    }
  }
  else {
    if (*(int *)(local_res10 + 4) == 1) {
      uVar1 = *(uint *)(local_res10 + 8);
      if ((((uVar1 & 1) == 0) && (uVar1 - 1 < 0x206)) &&
         (*(short *)((ulonglong)uVar1 + 10 + local_res10) == 0)) {
        local_48 = CONCAT44(uRam0000000140008364,CONCAT22(DAT_140008362,WerKernelLiveReportRootPath)
                           );
        pwStack_40 = DAT_140008368;
        if ((DAT_140008368 == (wchar_t *)0x0) ||
           (_Size = (ulonglong)CONCAT22(DAT_140008362,WerKernelLiveReportRootPath) & 0xffff,
           _Size + 2 != (ulonglong)*(ushort *)(local_res10 + 8))) {
          bVar11 = true;
        }
        else {
          iVar8 = memcmp(DAT_140008368,(void *)(local_res10 + 0xc),_Size);
          bVar11 = iVar8 != 0;
        }
        bVar2 = true;
        if (bVar11) goto LAB_14000e90b;
        goto LAB_14000ea59;
      }
    }
    pcVar9 = 
    "WERKERNELHOST: WerpRefreshRootPath: LiveKernelReportsPath value is an invalid string.\n";
LAB_14000e8ef:
    DbgPrintEx(5,0,pcVar9);
  }
LAB_14000ea59:
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0);
  }
LAB_14000ea6f:
  if (local_res18 != 0) {
    ZwClose();
  }
  return iVar7;
}



===== WerpRefreshThrottlePolicy @ 14000eaa8 =====

void WerpRefreshThrottlePolicy(void)

{
  int iVar1;
  uint local_res8 [2];
  longlong local_res10;
  undefined8 local_68;
  wchar_t *local_60;
  undefined8 local_58;
  wchar_t *local_50;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  wchar_t *local_30;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_res10 = 0;
  local_60 = L"FullLiveReportsMax";
  local_68 = 0x260024;
  local_30 = L"ComponentThrottleThreshold";
  local_38 = 0x360034;
  local_50 = L"SystemMemoryThrottleThresholdInGB";
  local_58 = 0x440042;
  local_40 = L"SystemThrottleThreshold";
  local_48 = 0x30002e;
  local_10 = L"VrfComponentThrottleThreshold";
  local_18 = 0x3c003a;
  local_20 = L"VrfSystemThrottleThreshold";
  local_28 = 0x360034;
  iVar1 = WerpGetRegistryKey(0,0x140005f90,0x20019,(longlong)&local_res10);
  if (-1 < iVar1) {
    WerpGetRegistryUlongValue(local_res10,(longlong)&local_68,1,&DAT_140008348);
    local_res8[0] = 0x100;
    WerpGetRegistryUlongValue(local_res10,(longlong)&local_58,0x100,local_res8);
    if (local_res8[0] == 0xffffffff) {
      DAT_140008350 = -1;
    }
    else {
      DAT_140008350 = (ulonglong)local_res8[0] << 0x1e;
    }
    WerpGetRegistryTimeoutValue(local_res10,(longlong)&local_48,0x30,&DAT_140008328);
    WerpGetRegistryTimeoutValue(local_res10,(longlong)&local_38,0xa8,&DAT_140008330);
    if (DAT_140008330 < DAT_140008328) {
      DbgPrintEx(5,1,
                 "WERKERNELHOST: Registry PerComponentThreshold cannot be shorter than SystemThreshold.\n"
                );
      DAT_140008330 = DAT_140008328;
    }
    WerpGetRegistryTimeoutValue(local_res10,(longlong)&local_28,1,&DAT_140008338);
    WerpGetRegistryTimeoutValue(local_res10,(longlong)&local_18,0x18,&DAT_140008340);
    if (DAT_140008340 < DAT_140008338) {
      DbgPrintEx(5,1,
                 "WERKERNELHOST: Registry VrfComponentThreshold cannot be shorter than VrfSystemThreshold.\n"
                );
      DAT_140008340 = DAT_140008338;
    }
  }
  if (local_res10 != 0) {
    ZwClose();
  }
  return;
}



===== WerpSetLastFullReportTime @ 14000ecac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WerpSetLastFullReportTime(longlong param_1)

{
  wchar_t *pwVar1;
  short sVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  ulonglong uVar8;
  short *psVar9;
  longlong *plVar10;
  longlong lVar11;
  char local_res8 [8];
  undefined8 local_res10;
  longlong local_res18;
  longlong local_res20;
  undefined4 uVar13;
  undefined8 *puVar12;
  longlong local_78 [3];
  wchar_t *local_60;
  longlong local_58 [5];
  
  uVar3 = WerKernelThrottlePolicy;
  pwVar1 = (wchar_t *)(param_1 + 0x18);
  local_78[2] = 0x260024;
  local_60 = L"LastFullLiveReport";
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_res10 = _DAT_fffff78000000014;
  WerKernelThrottlePolicy = _DAT_fffff78000000014;
  RtlInitUnicodeString(local_78 + 6,pwVar1);
  plVar10 = &DAT_140008358;
  lVar11 = DAT_140008358;
  while (lVar11 != 0) {
    RtlInitUnicodeString(local_78 + 4,lVar11);
    cVar4 = RtlEqualUnicodeString(local_78 + 6,local_78 + 4,0);
    if (cVar4 != '\0') {
      *(undefined8 *)(lVar11 + 0x20) = local_res10;
      goto LAB_14000edd8;
    }
    plVar10 = (longlong *)(lVar11 + 0x28);
    lVar11 = *plVar10;
  }
  psVar6 = (short *)WerpAllocateMem(0x30);
  if (psVar6 != (short *)0x0) {
    lVar11 = 0x10;
    psVar9 = psVar6;
    do {
      if ((lVar11 == -0x7fffffee) ||
         (sVar2 = *(short *)(((longlong)pwVar1 - (longlong)psVar6) + (longlong)psVar9), sVar2 == 0))
      break;
      *psVar9 = sVar2;
      psVar9 = psVar9 + 1;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
    psVar7 = psVar9 + -1;
    if (lVar11 != 0) {
      psVar7 = psVar9;
    }
    *psVar7 = 0;
    if (lVar11 != 0) {
      *(undefined8 *)(psVar6 + 0x10) = local_res10;
      *plVar10 = (longlong)psVar6;
    }
    else {
      ExFreePoolWithTag(psVar6,0);
    }
  }
LAB_14000edd8:
  local_res20 = 0;
  local_res18 = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  cVar4 = '\0';
  local_res8[0] = '\0';
  iVar5 = WerpGetRegistryKey(0,0x140008090,0x20006,(longlong)local_78);
  if ((iVar5 < 0) || (local_78[0] == 0)) {
    DbgPrintEx(5,1,"WERKERNELHOST: Could not open NT_FULL_LIVE_KERNEL_REG_KEY_PATH, status 0x%X\n",
               iVar5);
    return iVar5;
  }
  iVar5 = WerpGetRegistryKey(local_78[0],0x140005a40,0x20006,(longlong)&local_res20);
  if ((iVar5 < 0) || (local_res20 == 0)) {
    DbgPrintEx(5,1,"WERKERNELHOST: Could not open NT_FULL_LIVE_KERNEL_REG_KEY_PATH, status 0x%X\n",
               iVar5);
  }
  else {
    iVar5 = WerpGetRegistryKey(local_res20,(longlong)pwVar1,0x20006,(longlong)&local_res18);
    if ((iVar5 < 0) || (local_res18 == 0)) {
      DbgPrintEx(5,1,"WERKERNELHOST: Could not open report type key %ws, status 0x%X\n",pwVar1,iVar5
                );
LAB_14000eeaf:
      if (cVar4 == '\0') goto LAB_14000eeb4;
LAB_14000ef10:
      if (local_res18 == 0) goto LAB_14000ef7e;
      puVar12 = &local_res10;
      iVar5 = ZwSetValueKey(local_res18,local_78 + 2,0,0xb,puVar12,8);
      uVar13 = (undefined4)((ulonglong)puVar12 >> 0x20);
      if (-1 < iVar5) goto LAB_14000ef69;
    }
    else {
      uVar8 = WerpQueryComponentOverridePolicy(pwVar1,local_res8,(ulonglong *)(local_78 + 1));
      iVar5 = (int)uVar8;
      if (local_res8[0] != '\0') {
        cVar4 = local_res8[0];
        WerKernelThrottlePolicy = uVar3;
        goto LAB_14000eeaf;
      }
LAB_14000eeb4:
      puVar12 = &local_res10;
      iVar5 = ZwSetValueKey(local_res20,local_78 + 2,0,0xb,puVar12,8);
      uVar13 = (undefined4)((ulonglong)puVar12 >> 0x20);
      if (-1 < iVar5) goto LAB_14000ef10;
    }
    DbgPrintEx(5,1,"WERKERNELHOST: Could not set value %ws, status 0x%X\n",L"LastFullLiveReport",
               CONCAT44(uVar13,iVar5));
  }
LAB_14000ef69:
  if (local_res18 != 0) {
    ZwClose();
  }
LAB_14000ef7e:
  if (local_78[0] != 0) {
    ZwClose();
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  return iVar5;
}



===== WerpSubmitReport @ 14000efe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WerpSubmitReport(longlong param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *_Dst;
  undefined4 *puVar4;
  short *psVar5;
  ulonglong uVar6;
  short *psVar7;
  longlong lVar8;
  char *pcVar9;
  longlong lVar10;
  longlong lVar11;
  undefined1 auStack_178 [32];
  undefined4 *local_158;
  longlong *local_150;
  undefined8 local_148;
  longlong **local_140;
  undefined8 local_138;
  undefined8 local_130;
  longlong **local_128;
  longlong local_118;
  undefined8 local_110;
  ulonglong local_108;
  longlong *local_100;
  longlong local_f8;
  longlong *local_f0;
  longlong local_e8;
  ulonglong local_e0;
  longlong **local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  ulonglong uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  undefined2 local_8c;
  undefined1 local_88 [16];
  undefined8 local_78;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_178;
  local_8c = 0x500;
  local_f8 = 0;
  local_e8 = 0;
  local_b0 = 0;
  uStack_a8 = uStack_a8 & 0xffffffff00000000;
  local_100 = (longlong *)0x0;
  local_90 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_f0 = (longlong *)0x0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_118 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  memset(local_88,0,0x48);
  local_110 = 0;
  if ((param_1 == 0) || (lVar8 = *(longlong *)(param_1 + 0x10), lVar8 == 0)) {
    return 0xc000000d;
  }
  _Dst = (undefined4 *)WerpAllocateMem(0x578);
  puVar4 = (undefined4 *)WerpAllocateMem(0x578);
  if ((_Dst == (undefined4 *)0x0) || (puVar4 == (undefined4 *)0x0)) {
    uVar2 = 0xc0000017;
    if (_Dst == (undefined4 *)0x0) goto LAB_14000f552;
  }
  else if ((*(int *)(param_1 + 4) != 2) ||
          (uVar2 = WerpSetLastFullReportTime(param_1), -1 < (int)uVar2)) {
    iVar3 = WerpGetRegistryKey(lVar8,0x140005178,0x20000,(longlong)&local_118);
    if (iVar3 < 0) {
      DbgPrintEx(5,1,"WERKERNELHOST: WerpGetRegistryKey failed for the busy key 0x%X\n",iVar3);
    }
    else {
      ZwDeleteKey(local_118);
      ZwClose(local_118);
      local_118 = 0;
    }
    psVar5 = (short *)(param_1 + 0x18);
    psVar7 = (short *)(param_1 + 0x38);
    if (psVar5 == (short *)0x0) {
      uVar2 = 0xc000000d;
    }
    else {
      lVar11 = 0x10;
      lVar8 = 0x10;
      do {
        if (*psVar5 == 0) break;
        psVar5 = psVar5 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      uVar2 = ~-(uint)(lVar8 != 0) & 0xc000000d;
      local_e0 = -(ulonglong)(lVar8 != 0) & 0x10U - lVar8;
      if (lVar8 != 0) {
        if (psVar7 == (short *)0x0) {
          uVar2 = 0xc000000d;
        }
        else {
          lVar10 = 0x28;
          lVar8 = 0x28;
          do {
            if (*psVar7 == 0) break;
            psVar7 = psVar7 + 1;
            lVar8 = lVar8 + -1;
          } while (lVar8 != 0);
          uVar2 = ~-(uint)(lVar8 != 0) & 0xc000000d;
          local_108 = -(ulonglong)(lVar8 != 0) & 0x28U - lVar8;
          if (lVar8 != 0) {
            RtlInitUnicodeString(&local_a0,L"\\WindowsErrorReportingServicePort");
            local_128 = &local_100;
            local_78 = 0x578;
            uVar2 = WerpAllocateAndInitializeSid(&local_90);
            if (-1 < (int)uVar2) {
              iVar3 = WerStartSystemErrorHandler();
              if (iVar3 < 0) {
                DbgPrintEx(5,1,
                           "WERKERNELHOST: WerStartSystemErrorHandler failed with 0x%x. Continuing submission.\n"
                           ,iVar3);
                uVar2 = 0x102;
              }
              else {
                uVar2 = ZwQuerySystemInformation(0x73,&local_110);
                if ((int)uVar2 < 0) {
                  pcVar9 = "WERKERNELHOST: ZwQuerySysInfo(ErrorPortTimeouts) failed with 0x%x\n";
                }
                else {
                  uVar6 = WerWaitForSystemErrorHandler((int)local_110);
                  uVar2 = (uint)uVar6;
                  if ((int)uVar2 < 0) {
                    pcVar9 = "WERKERNELHOST: WerWaitForSystemErrorHandler failed with 0x%x\n";
                  }
                  else {
                    if (uVar2 == 0x102) {
                      pcVar9 = "WERKERNELHOST: WerWaitForSystemErrorHandler timed out\n";
LAB_14000f2a1:
                      DbgPrintEx(5,1,pcVar9);
                      goto LAB_14000f541;
                    }
                    local_b0 = 0;
                    uStack_a8 = 0;
                    local_d0 = CONCAT44(local_d0._4_4_,0x30);
                    uStack_c8 = 0;
                    uStack_b8 = CONCAT44(uStack_b8._4_4_,0x200);
                    local_c0 = 0;
                    local_128 = &local_f0;
                    if (local_110._4_4_ == -1) {
                      local_128 = (longlong **)0x0;
                    }
                    else {
                      local_f0 = (longlong *)((longlong)local_110._4_4_ * -10000);
                    }
                    local_130 = 0;
                    local_138 = 0;
                    local_140 = (longlong **)0x0;
                    local_148 = 0;
                    local_150 = local_100;
                    local_158 = (undefined4 *)CONCAT44(local_158._4_4_,0x20000);
                    local_d8 = local_128;
                    uVar2 = ZwAlpcConnectPort(&local_f8,&local_a0,&local_d0,local_88);
                    if ((int)uVar2 < 0) {
                      pcVar9 = "WERKERNELHOST: ZwAlpcConnectPort failed with 0x%x\n";
                    }
                    else {
                      if (uVar2 == 0x102) {
                        pcVar9 = "WERKERNELHOST: ZwAlpcConnectPort timed out\n";
                        goto LAB_14000f2a1;
                      }
                      memset(_Dst,0,0x578);
                      psVar5 = (short *)(_Dst + 0xe);
                      *_Dst = 0x5780550;
                      _Dst[10] = 0x60000000;
                      _Dst[0xc] = (uint)(*(int *)(param_1 + 4) == 2);
                      uVar6 = 0xf;
                      if (local_e0 < 0x10) {
                        uVar6 = local_e0;
                      }
                      lVar8 = (param_1 + 0x18) - (longlong)psVar5;
                      do {
                        if ((lVar11 + -0x10 + uVar6 == 0) ||
                           (sVar1 = *(short *)(lVar8 + (longlong)psVar5), sVar1 == 0)) break;
                        *psVar5 = sVar1;
                        psVar5 = psVar5 + 1;
                        lVar11 = lVar11 + -1;
                      } while (lVar11 != 0);
                      psVar7 = psVar5 + -1;
                      if (lVar11 != 0) {
                        psVar7 = psVar5;
                      }
                      *psVar7 = 0;
                      if (lVar11 != 0) {
                        psVar5 = (short *)(_Dst + 0x16);
                        uVar6 = 0x27;
                        if (local_108 < 0x28) {
                          uVar6 = local_108;
                        }
                        lVar8 = (param_1 + 0x38) - (longlong)psVar5;
                        do {
                          if ((lVar10 + -0x28 + uVar6 == 0) ||
                             (sVar1 = *(short *)(lVar8 + (longlong)psVar5), sVar1 == 0)) break;
                          *psVar5 = sVar1;
                          psVar5 = psVar5 + 1;
                          lVar10 = lVar10 + -1;
                        } while (lVar10 != 0);
                        psVar7 = psVar5 + -1;
                        if (lVar10 != 0) {
                          psVar7 = psVar5;
                        }
                        *psVar7 = 0;
                        if (lVar10 == 0) {
                          DbgPrintEx(5,1,"WERKERNELHOST: StringCchCopy failed for id with 0x%x\n",
                                     0x80000005);
                          uVar2 = 0x80000005;
                        }
                        else {
                          memset(puVar4 + 1,0,0x574);
                          *puVar4 = 0x5780550;
                          local_e8 = 0x578;
                          local_140 = local_d8;
                          local_150 = &local_e8;
                          local_148 = 0;
                          local_158 = puVar4;
                          iVar3 = ZwAlpcSendWaitReceivePort(local_f8,0,_Dst,0);
                          if ((iVar3 < 0) || (iVar3 == 0x102)) {
                            pcVar9 = 
                            "WERKERNELHOST: ZwAlpcSendWaitReceivePort failed, status 0x%X\n";
                          }
                          else {
                            iVar3 = puVar4[0xb];
                            if (-1 < iVar3) {
                              uVar2 = 0;
                              goto LAB_14000f541;
                            }
                            pcVar9 = 
                            "WERKERNELHOST: Service returned failure, ReplyMsg->u.status 0x%X\n";
                          }
                          DbgPrintEx(5,1,pcVar9,iVar3);
                          uVar2 = 0x102;
                        }
                        goto LAB_14000f541;
                      }
                      pcVar9 = "WERKERNELHOST: StringCchCopy failed for key with 0x%x\n";
                      uVar2 = 0x80000005;
                    }
                  }
                }
                DbgPrintEx(5,1,pcVar9,uVar2);
              }
            }
          }
        }
      }
    }
  }
LAB_14000f541:
  ExFreePoolWithTag(_Dst,0);
LAB_14000f552:
  if (puVar4 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar4,0);
  }
  if (local_118 != 0) {
    ZwClose();
    local_118 = 0;
  }
  if (local_100 != (longlong *)0x0) {
    ExFreePoolWithTag(local_100,0);
  }
  if (local_f8 != 0) {
    ZwClose();
  }
  return uVar2;
}



===== _tlgEnableCallback @ 14000f5f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

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



===== DllUnload @ 14000f670 =====

undefined8 DllUnload(void)

{
                    /* 0xf670  1  DllUnload */
  return 0;
}



===== WerSubmitUserCrashReportExt$filt$0 @ 14000f67a =====

void WerSubmitUserCrashReportExt_filt_0(longlong *param_1,longlong param_2)

{
  WerpSuppressReadFaultsFilter(*(int *)*param_1,param_1,*(ulonglong *)(param_2 + 0x80));
  return;
}



===== entry @ 140011010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140011044 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}



===== WerLiveKernelInitSystem @ 140011080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WerLiveKernelInitSystem(void)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  int extraout_EAX;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [24];
  undefined8 *local_b8;
  longlong local_b0;
  int local_a8;
  undefined4 local_a0;
  undefined1 local_98;
  undefined8 *local_90;
  undefined1 local_88;
  undefined8 local_78;
  undefined8 local_70;
  wchar_t *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
                    /* 0x11080  5  WerLiveKernelInitSystem */
  local_10 = __security_cookie ^ (ulonglong)auStack_d8;
  local_34 = 0;
  local_78 = 0;
  local_48 = 0;
  local_58 = L"\\SystemRoot\\System32";
  local_50 = 0x30;
  local_68 = L"wersvc.dll";
  local_40 = &local_60;
  local_b0 = CONCAT44(local_b0._4_4_,0x11);
  local_60 = 0x2a0028;
  local_70 = 0x160014;
  local_20 = 0;
  uStack_18 = 0;
  local_38 = 0x240;
  local_30 = 0;
  uStack_28 = 0;
  local_b8 = (undefined8 *)CONCAT44(local_b8._4_4_,3);
  iVar3 = ZwOpenFile(&local_78,0x100001,&local_50,&local_20);
  if (-1 < iVar3) {
    uVar6 = (uint)(ushort)local_70;
    lVar5 = WerpAllocateMem(uVar6 + 0xc);
    if (lVar5 == 0) {
      ZwClose();
    }
    else {
      local_88 = 1;
      local_90 = &local_70;
      local_98 = 1;
      local_b8 = &local_20;
      local_a0 = 0xc;
      local_b0 = lVar5;
      local_a8 = uVar6 + 0xc;
      iVar3 = ZwQueryDirectoryFile(local_78,0,0,0);
      WerpFreeMem(lVar5);
      ZwClose(local_78);
      if (-1 < iVar3) {
        WerpInitRootPath();
        if (extraout_EAX < 0) {
          pcVar8 = "WERKERNELHOST: WerpInitRootPath failed with status 0x%X\n";
          iVar3 = extraout_EAX;
        }
        else {
          iVar3 = WerpInitThrottlePolicy();
          puVar7 = auStack_d8;
          if (-1 < iVar3) {
            WerHighestAllowedPolicy = 2;
            WerKernelLiveReportInitialized = 1;
            local_20 = *(undefined8 *)(PTR_DAT_140008050 + -0x10);
            uStack_18 = *(undefined8 *)(PTR_DAT_140008050 + -8);
            if (DAT_140008068 != 0) {
              pcVar2 = (code *)swi(0x29);
              (*pcVar2)(5);
              puVar7 = auStack_d0;
            }
            _DAT_140008070 = 0;
            uRam0000000140008078 = 0;
            *(undefined8 *)(puVar7 + -8) = 0x140011284;
            iVar4 = EtwRegister(&local_20,_tlgEnableCallback,&DAT_140008048,&DAT_140008068);
            if (iVar4 == 0) {
              uVar1 = *(undefined2 *)PTR_DAT_140008050;
              *(undefined8 *)(puVar7 + -8) = 0x1400112a8;
              EtwSetInformation(DAT_140008068,2,PTR_DAT_140008050,uVar1);
            }
            *(undefined8 *)(puVar7 + -8) = 0x1400112b2;
            McGenEventRegister_EtwRegister();
            goto LAB_14001115c;
          }
          pcVar8 = "WERKERNELHOST: WerpInitThrottlePolicy failed with status 0x%X\n";
        }
        puVar7 = auStack_d8;
        DbgPrintEx(5,1,pcVar8,iVar3);
        goto LAB_14001115c;
      }
    }
  }
  puVar7 = auStack_d8;
  iVar3 = -0x3ffffffe;
LAB_14001115c:
  *(undefined8 *)(puVar7 + -8) = 0x140011168;
  return iVar3;
}



===== WerpInitRootPath @ 1400112c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WerpInitRootPath(void)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  longlong lVar4;
  longlong lVar5;
  int unaff_EDI;
  longlong local_res8;
  longlong local_res10;
  longlong local_res18;
  longlong local_res20;
  longlong local_58;
  longlong local_50 [2];
  wchar_t *local_40;
  longlong local_38;
  wchar_t *local_30;
  
  local_res10 = 0;
  local_res18 = 0;
  local_58 = 0;
  lVar5 = 0;
  local_50[0] = 0;
  local_40 = L"LiveKernelReportsPath";
  local_30 = L"LiveKernelReportsQueueRoot";
  local_res8 = 0;
  local_res20 = 0;
  local_50[1] = 0x2c002a;
  local_38 = 0x360034;
  if (WerKernelLiveReportInitialized != '\0') {
    return unaff_EDI;
  }
  _WerKernelLiveReportRootPath = 0;
  DAT_140008368 = (wchar_t *)0x0;
  iVar1 = WerpGetRegistryKey(0,0x140006970,0x20000,(longlong)&local_res10);
  lVar4 = 0;
  if (-1 < iVar1) {
    iVar1 = WerpGetRegistryValueInfo(local_res10,local_50 + 1,&local_res8);
    iVar2 = WerpGetRegistryValueInfo(local_res10,local_50 + 3,&local_res20);
    lVar5 = local_res20;
    if ((((iVar2 < 0) || (local_res20 == 0)) || (*(int *)(local_res20 + 4) != 1)) ||
       (0x206 < *(uint *)(local_res20 + 8))) {
      if (iVar1 < 0) {
        lVar4 = local_res8;
        goto LAB_1400114d9;
      }
    }
    else {
      memset(g_wszLiveKernelReportsQueueRoot,0,0x208);
      memcpy(g_wszLiveKernelReportsQueueRoot,(void *)(lVar5 + 0xc),(ulonglong)*(uint *)(lVar5 + 8));
      iVar1 = WerpCreateRegistryKey(0,0x140008090,0x20004,'\0',(longlong)&local_res18,0);
      if (((iVar1 < 0) ||
          (iVar1 = WerpCreateRegistryKey(local_res18,0x140005c18,0x20004,'\0',(longlong)&local_58,0)
          , iVar1 < 0)) ||
         (iVar1 = WerpCreateRegistryKey(local_res18,0x140005a40,0x20004,'\0',(longlong)local_50,0),
         iVar1 < 0)) {
        DbgPrintEx(5,1,"WERKERNELHOST: ZwCreateKey failed with scode 0x%x for the root\n",iVar1);
        lVar4 = local_res8;
        goto LAB_1400114f3;
      }
    }
    lVar4 = local_res8;
    if (((local_res8 != 0) && (*(int *)(local_res8 + 4) == 1)) &&
       ((*(uint *)(local_res8 + 8) < 0x207 &&
        (DAT_140008368 = (wchar_t *)WerpAllocateMem(*(uint *)(local_res8 + 8)),
        DAT_140008368 != (wchar_t *)0x0)))) {
      uVar3 = *(short *)(lVar4 + 8) - 2;
      _WerKernelLiveReportRootPath = CONCAT22(*(undefined2 *)(lVar4 + 8),uVar3);
      memcpy(DAT_140008368,(void *)(lVar4 + 0xc),(ulonglong)uVar3);
      WerpCreateStoreDirectory();
      goto LAB_1400114f3;
    }
  }
LAB_1400114d9:
  _WerKernelLiveReportRootPath = CONCAT44(WerKernelLiveReportRootPath_4,0x3c003a);
  DAT_140008368 = L"\\SystemRoot\\LiveKernelReports";
LAB_1400114f3:
  if (lVar4 != 0) {
    WerpFreeMem(lVar4);
  }
  if (lVar5 != 0) {
    WerpFreeMem(lVar5);
  }
  if (local_res10 != 0) {
    ZwClose();
  }
  if (local_res18 != 0) {
    ZwClose();
  }
  if (local_58 != 0) {
    ZwClose();
  }
  if (local_50[0] != 0) {
    ZwClose();
  }
  return unaff_EDI;
}



===== WerpInitThrottlePolicy @ 140011574 =====

int WerpInitThrottlePolicy(void)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  int iVar4;
  longlong lVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  uint uVar9;
  undefined8 uVar10;
  longlong lVar11;
  short *psVar12;
  ulonglong local_res8;
  undefined4 local_res10 [2];
  longlong local_res18;
  longlong local_res20;
  longlong local_b8 [2];
  wchar_t *local_a8;
  longlong local_a0;
  wchar_t *local_98;
  longlong local_90;
  wchar_t *local_88;
  longlong local_80;
  wchar_t *local_78;
  longlong local_70;
  wchar_t *local_68;
  longlong local_60;
  wchar_t *local_58;
  longlong local_50;
  wchar_t *local_48;
  
  local_b8[1] = 0x260024;
  local_a8 = L"LastFullLiveReport";
  local_a0 = 0x260024;
  local_98 = L"FullLiveReportsMax";
  local_70 = 0x360034;
  local_68 = L"ComponentThrottleThreshold";
  local_90 = 0x440042;
  local_88 = L"SystemMemoryThrottleThresholdInGB";
  local_80 = 0x30002e;
  local_78 = L"SystemThrottleThreshold";
  local_50 = 0x3c003a;
  local_48 = L"VrfComponentThrottleThreshold";
  local_58 = L"VrfSystemThrottleThreshold";
  local_60 = 0x360034;
  local_res20 = 0;
  local_res10[0] = 0;
  memset(&WerKernelThrottlePolicy,0,0x40);
  local_res18 = 0;
  local_b8[0] = 0;
  lVar11 = 0;
  iVar4 = WerpGetRegistryKey(0,0x140005f90,0x20019,(longlong)&local_res18);
  DAT_140008348 = 1;
  if (iVar4 < 0) {
    DAT_140008350 = 0x4000000000;
    iVar4 = 0;
    DAT_140008328 = 0x19254d38000;
    DAT_140008330 = 0x58028e44000;
    DAT_140008338 = 36000000000;
    DAT_140008340 = 864000000000;
  }
  else {
    WerpGetRegistryUlongValue(local_res18,(longlong)(local_b8 + 3),1,&DAT_140008348);
    local_res8 = CONCAT44(local_res8._4_4_,0x100);
    WerpGetRegistryUlongValue(local_res18,(longlong)(local_b8 + 5),0x100,(undefined4 *)&local_res8);
    if ((int)local_res8 == -1) {
      DAT_140008350 = -1;
    }
    else {
      DAT_140008350 = (local_res8 & 0xffffffff) << 0x1e;
    }
    WerpGetRegistryTimeoutValue(local_res18,(longlong)(local_b8 + 7),0x30,&DAT_140008328);
    WerpGetRegistryTimeoutValue(local_res18,(longlong)(local_b8 + 9),0xa8,&DAT_140008330);
    if (DAT_140008330 < DAT_140008328) {
      DbgPrintEx(5,1,
                 "WERKERNELHOST: Registry PerComponentThreshold cannot be shorter than SystemThreshold.\n"
                );
      DAT_140008330 = DAT_140008328;
    }
    WerpGetRegistryTimeoutValue(local_res18,(longlong)(local_b8 + 0xb),1,&DAT_140008338);
    WerpGetRegistryTimeoutValue(local_res18,(longlong)(local_b8 + 0xd),0x18,&DAT_140008340);
    if (DAT_140008340 < DAT_140008338) {
      DbgPrintEx(5,1,
                 "WERKERNELHOST: Registry VrfComponentThreshold cannot be shorter than VrfSystemThreshold.\n"
                );
      DAT_140008340 = DAT_140008338;
    }
    ZwClose();
    local_res18 = 0;
    iVar4 = WerpGetRegistryKey(0,0x140008090,0x20019,(longlong)local_b8);
    lVar5 = lVar11;
    if (-1 < iVar4) {
      uVar10 = 0x20019;
      iVar4 = WerpGetRegistryKey(local_b8[0],0x140005a40,0x20019,(longlong)&local_res18);
      if (-1 < iVar4) {
        WerpGetRegistryLong64Value
                  (local_res18,(longlong)(local_b8 + 1),uVar10,&WerKernelThrottlePolicy);
        lVar5 = WerpAllocateMem(0x38);
        if (lVar5 == 0) {
          iVar4 = -0x3fffff66;
          lVar5 = lVar11;
        }
        else {
          psVar12 = (short *)&DAT_140008358;
          uVar9 = 0;
          do {
            while( true ) {
              iVar4 = ZwEnumerateKey(local_res18,uVar9,0,lVar5,0x36,local_res10);
              if (iVar4 == -0x7fffffe6) {
                iVar4 = 0;
                goto LAB_1400119c6;
              }
              if (iVar4 < 0) {
                DbgPrintEx(5,1,
                           "WERKERNELHOST: WerpInitThrottlePolicy: ZwEnumerateKey returned status 0x%X\n"
                           ,iVar4);
                goto LAB_1400119c6;
              }
              uVar1 = uVar9 + 1;
              if (uVar1 < uVar9) {
                iVar4 = -0x3fffff6b;
                goto LAB_1400119c6;
              }
              uVar10 = 0x20019;
              *(undefined2 *)(lVar5 + 0x10 + (ulonglong)(*(uint *)(lVar5 + 0xc) >> 1) * 2) = 0;
              iVar4 = WerpGetRegistryKey(local_res18,lVar5 + 0x10,0x20019,(longlong)&local_res20);
              uVar9 = uVar1;
              if (-1 < iVar4) break;
              DbgPrintEx(5,1,"WERKERNELHOST: WerpInitThrottlePolicy: Failed to open key %ws\n",
                         lVar5 + 0x10);
              if (local_res20 != 0) {
                ZwClose();
                local_res20 = 0;
              }
            }
            local_res8 = 0;
            WerpGetRegistryLong64Value(local_res20,(longlong)(local_b8 + 1),uVar10,&local_res8);
            uVar3 = local_res8;
            if (local_res8 != 0) {
              psVar6 = (short *)WerpAllocateMem(0x30);
              if (psVar6 == (short *)0x0) {
                iVar4 = -0x3fffffe9;
              }
              else {
                lVar11 = 0x10;
                psVar8 = psVar6;
                do {
                  if ((lVar11 == -0x7fffffee) ||
                     (sVar2 = *(short *)((lVar5 - (longlong)psVar6) + 0x10 + (longlong)psVar8),
                     sVar2 == 0)) break;
                  *psVar8 = sVar2;
                  psVar8 = psVar8 + 1;
                  lVar11 = lVar11 + -1;
                } while (lVar11 != 0);
                psVar7 = psVar8 + -1;
                if (lVar11 != 0) {
                  psVar7 = psVar8;
                }
                *psVar7 = 0;
                *(ulonglong *)(psVar6 + 0x10) = uVar3;
                *(short **)psVar12 = psVar6;
                psVar12 = psVar6 + 0x14;
              }
            }
            if (local_res20 != 0) {
              ZwClose();
              local_res20 = 0;
            }
          } while (-1 < iVar4);
        }
      }
    }
LAB_1400119c6:
    if (local_res18 != 0) {
      ZwClose();
    }
    if (local_b8[0] != 0) {
      ZwClose();
    }
    if (lVar5 != 0) {
      WerpFreeMem(lVar5);
    }
  }
  return iVar4;
}



===== DriverEntry @ 140011a40 =====

undefined8 DriverEntry(void)

{
  return 0xc0000001;
}


