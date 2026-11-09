
===== NptrigPostFsControlCallback @ 1c0001010 =====

uint NptrigPostFsControlCallback(uint *param_1,ushort *param_2,undefined8 param_3,uint *param_4)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  longlong **pplVar7;
  longlong local_res8;
  longlong *local_38;
  ushort local_30;
  ushort local_2e;
  undefined4 local_2c;
  longlong local_28;
  
  local_2c = 0;
  local_38 = (longlong *)0x0;
  uVar3 = 0xc0000001;
  local_res8 = 0;
  if ((((param_1[6] != 0xc0000034) ||
       (lVar1 = *(longlong *)(param_1 + 4), *(int *)(lVar1 + 0x28) != 0x110018)) ||
      (*(int *)(lVar1 + 0x20) == 0)) ||
     ((*(longlong *)(lVar1 + 0x30) == 0 || ((*param_1 & 1) == 0)))) goto LAB_1c000103e;
  FltGetInstanceContext(*(undefined8 *)(param_2 + 0xc),&local_res8);
  plVar2 = *(longlong **)(*(longlong *)(param_1 + 4) + 0x30);
  local_28 = (longlong)plVar2 + 0xe;
  local_30 = *(ushort *)(plVar2 + 1);
  local_2e = local_30;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    param_4 = param_1;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,param_2,param_1);
  }
  NptrigLock(NptrigDriverInstance);
  pplVar7 = &local_38;
  uVar4 = NptrigFindTrigger(&local_30,pplVar7);
  if ((int)uVar4 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,param_2,param_1);
    }
  }
  else {
    uVar5 = NptrigHandleTriggerableIo(local_38,pplVar7,param_2,(longlong *)param_4);
    uVar3 = (uint)uVar5;
    if ((int)uVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar6 = 0x15;
LAB_1c00011a4:
        WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,param_2,param_1,(char)uVar3);
      }
    }
    else {
      param_2 = &local_30;
      uVar3 = NptrigQueueWaitNamedPipeRequest
                        (param_1,local_res8,param_2,*plVar2,(uint)*(byte *)((longlong)plVar2 + 0xc))
      ;
      if (-1 < (int)uVar3) {
        NptrigUnlock(NptrigDriverInstance);
        uVar3 = 0;
        goto LAB_1c000103e;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar6 = 0x16;
        goto LAB_1c00011a4;
      }
    }
  }
  NptrigUnlock(NptrigDriverInstance);
LAB_1c000103e:
  if (local_res8 != 0) {
    FltReleaseContext(local_res8);
  }
  return ~uVar3 >> 0x1f;
}



===== WPP_SF_qL @ 1c0001200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2963d717a8213e3409efbc10fa8b2ce9_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== RtlUnicodeStringValidateWorker @ 1c0001260 =====

undefined8 RtlUnicodeStringValidateWorker(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) && ((*(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    return 0;
  }
  return 0xc000000d;
}



===== RtlWideCharArrayCopyStringWorker @ 1c00012b0 =====

undefined4
RtlWideCharArrayCopyStringWorker(longlong param_1,longlong param_2,longlong *param_3,short *param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar2 = 0;
  lVar1 = 0x7fff;
  lVar3 = 0;
  if (param_2 != 0) {
    lVar4 = param_1 - (longlong)param_4;
    do {
      if (lVar1 == 0) goto LAB_1c000130b;
      if (*param_4 == 0) {
        if (param_2 != 0) goto LAB_1c000130b;
        break;
      }
      *(short *)(lVar4 + (longlong)param_4) = *param_4;
      lVar1 = lVar1 + -1;
      param_4 = param_4 + 1;
      lVar3 = lVar3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (lVar1 == 0) goto LAB_1c000130b;
  }
  uVar2 = 0;
  if (*param_4 != 0) {
    uVar2 = 0x80000005;
  }
LAB_1c000130b:
  *param_3 = lVar3;
  return uVar2;
}



===== McGenControlCallbackV2 @ 1c0001320 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar3 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar5 = 0;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar5 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar5 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar5 >> 5) * 4);
            *puVar1 = *puVar1 & ~(1 << ((byte)uVar5 & 0x1f));
          }
          else {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar5 >> 5) * 4);
            *puVar1 = *puVar1 | 1 << ((byte)uVar5 & 0x1f);
          }
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *(ushort *)(param_7 + 0x2a));
        return;
      }
    }
  }
  return;
}



===== NptrigWaitNamedPipeTimeoutCallback @ 1c0001440 =====

void NptrigWaitNamedPipeTimeoutCallback(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  puVar3 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    puVar3 = (undefined8 *)0x26;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,param_3,param_2,(char)*param_2);
  }
  uVar1 = 1;
  LOCK();
  uVar2 = *(uint *)((longlong)param_2 + 0xbc);
  if (uVar2 == 1) {
    *(uint *)((longlong)param_2 + 0xbc) = 2;
  }
  else {
    uVar1 = uVar2;
  }
  UNLOCK();
  uVar4 = (ulonglong)uVar1;
  if (uVar2 == 1) {
    puVar3 = *(undefined8 **)(NptrigDriverInstance + 0x38);
    uVar2 = FltQueueGenericWorkItem
                      (param_2[0x18],puVar3,NptrigWaitNamedPipeTimeoutWorkItem,1,param_2);
    uVar4 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      return;
    }
    LOCK();
    if (*(int *)((longlong)param_2 + 0xbc) == 2) {
      *(int *)((longlong)param_2 + 0xbc) = 3;
    }
    UNLOCK();
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar3 = (undefined8 *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      puVar3 = (undefined8 *)0x28;
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,uVar4,param_2,(char)uVar2);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    puVar3 = (undefined8 *)0x27;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,uVar4,param_2,(char)uVar1);
  }
  NptrigReleaseRequestRef((longlong)param_2,puVar3,uVar4);
  return;
}



===== NptrigReleaseRequestRef @ 1c0001560 =====

void NptrigReleaseRequestRef(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x70);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,param_3,param_1,(char)(iVar2 + -1));
  }
  if (iVar2 + -1 == 0) {
    ExFreePoolWithTag(param_1,0x6774704e);
  }
  return;
}



===== McTemplateK0zz_EtwWriteTransfer @ 1c00015e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zz_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5)

{
  wchar_t *pwVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined *local_38;
  int local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar3 = -1;
  lVar2 = -1;
  do {
    pwVar1 = L"f81d131-3fac-4537-9e0c-7e7b0c2f4b55" + lVar2;
    lVar2 = lVar2 + 1;
  } while (*pwVar1 != L'\0');
  local_38 = &u_1f81d131_3fac_4;
  local_30 = (int)lVar2 * 2 + 2;
  local_2c = 0;
  if (param_5 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    do {
      lVar2 = lVar3 + 1;
      lVar3 = lVar3 + 1;
    } while (param_5[lVar2] != L'\0');
    local_20 = (int)lVar3 * 2 + 2;
  }
  local_1c = 0;
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_28 = param_5;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_1,param_2,local_48);
  return;
}



===== McGenEventRegister_EtwRegister @ 1c00016b0 =====

undefined8
McGenEventRegister_EtwRegister
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  undefined8 uVar1;
  
  if (*param_4 == 0) {
    uVar1 = EtwRegister(param_1,McGenControlCallbackV2);
    return uVar1;
  }
  return 0;
}



===== RtlStringCopyWorkerW @ 1c00016f0 =====

undefined4 RtlStringCopyWorkerW(short *param_1)

{
  short sVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  uVar3 = 0;
  lVar4 = (longlong)
          L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\NetworkServiceTriggers\\Triggers\\"
          - (longlong)param_1;
  lVar2 = 0x101;
  while( true ) {
    if (lVar2 == -0x7ffffefd) goto LAB_1c0001739;
    sVar1 = *(short *)(lVar4 + (longlong)param_1);
    if (sVar1 == 0) break;
    *param_1 = sVar1;
    param_1 = param_1 + 1;
    lVar2 = lVar2 + -1;
    if (lVar2 == 0) {
LAB_1c000172f:
      param_1 = param_1 + -1;
      uVar3 = 0x80000005;
LAB_1c0001739:
      *param_1 = 0;
      return uVar3;
    }
  }
  if (lVar2 != 0) goto LAB_1c0001739;
  goto LAB_1c000172f;
}



===== RtdspUnlock @ 1c0001750 =====

void RtdspUnlock(undefined8 param_1)

{
  KeReleaseMutex(param_1,0);
  return;
}



===== RtdspLock @ 1c0001770 =====

void RtdspLock(undefined8 param_1)

{
  KeWaitForSingleObject(param_1,0,0,0,0);
  return;
}



===== WPP_SF_q @ 1c00017a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2963d717a8213e3409efbc10fa8b2ce9_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c00017f0 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  puVar1 = (ushort *)param_1[1];
  if (puVar1 == (ushort *)0x0) {
    uVar3 = 0;
    *param_5 = 0;
    uVar2 = 0;
  }
  else {
    *param_5 = puVar1;
    uVar3 = 2;
    uVar2 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar2;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar3;
  EtwWriteTransfer(*param_1,param_2,0,0,3,param_5);
  return;
}



===== NptrigTakeRequestRef @ 1c0001850 =====

void NptrigTakeRequestRef(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x70);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,WPP_GLOBAL_Control,param_1,
              (char)iVar2 + '\x01');
  }
  return;
}



===== RtdspInitializeLock @ 1c00018a0 =====

void RtdspInitializeLock(undefined8 param_1)

{
  KeInitializeMutex(param_1,0);
  return;
}



===== __report_gsfailure @ 1c00018d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c00018e0 =====

undefined8 McGenEventUnregister_EtwUnregister(longlong *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    *param_1 = 0;
  }
  return uVar1;
}



===== WPP_SF_qq @ 1c0001914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2963d717a8213e3409efbc10fa8b2ce9_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001970 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0;
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
    }
    *(undefined8 *)(param_4 + 0x18) = uVar1;
  }
  return;
}



===== _guard_check_icall @ 1c00019b0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c00019c8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00019ec =====

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



===== __cpu_features_init @ 1c0001a60 =====

/* WARNING: Removing unreachable block (ram,0x0001c0001aca) */
/* WARNING: Removing unreachable block (ram,0x0001c0001a79) */
/* WARNING: Removing unreachable block (ram,0x0001c0001a6a) */

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



===== __security_check_cookie @ 1c0001b30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001b70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001ba0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001ba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001bd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0001c40 =====

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



===== memset @ 1c0001f40 =====

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



===== __memset_repmovs @ 1c0002080 =====

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



===== __memset_query @ 1c0002100 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0002180 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00022c0 =====

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



===== __memset_spec_plain @ 1c0002340 =====

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



===== NptrigFireTrigger @ 1c0008010 =====

ulonglong NptrigFireTrigger(longlong *param_1,undefined8 param_2,undefined8 param_3,
                           undefined8 param_4)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 == param_1)) {
    *plVar4 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar4;
    plVar4 = (longlong *)(NptrigDriverInstance + 8);
    lVar1 = *plVar4;
    if (*(longlong **)(lVar1 + 8) == plVar4) {
      *param_1 = lVar1;
      param_1[1] = (longlong)plVar4;
      *(longlong **)(lVar1 + 8) = param_1;
      *plVar4 = (longlong)param_1;
      *(undefined4 *)(param_1 + 4) = 2;
      if ((Microsoft_Windows_EndpointTriggerProviderEnableBits & 1) == 0) {
        uVar5 = 0;
      }
      else {
        uVar3 = McTemplateK0zz_EtwWriteTransfer
                          ((undefined8 *)&NPTRIG_ETW_PROVIDER_GUID_Context,
                           &ServiceTriggerPerfServiceTriggered,param_3,param_4,(wchar_t *)param_1[3]
                          );
        uVar5 = (ulonglong)uVar3;
      }
      if ((Microsoft_Windows_ServiceTriggerPerfEventProviderEnableBits & 1) != 0) {
        McTemplateK0zz_EtwWriteTransfer
                  ((undefined8 *)&SERVICE_TRIGGER_PERF_EVENT_GUID_Context,
                   &ServiceTriggerPerfServiceTriggered,param_3,param_4,(wchar_t *)param_1[3]);
      }
      return uVar5;
    }
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  uVar5 = (*pcVar2)();
  return uVar5;
}



===== WppLoadTracingSupport @ 1c00080e0 =====

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



===== NptrigInitializeLock @ 1c0008230 =====

void NptrigInitializeLock(void)

{
  FltInitializePushLock();
  return;
}



===== DriverUnload @ 1c0008250 =====

void DriverUnload(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  RtdsUnregisterUpdateCallback(&NAMED_PIPE_EVENT_GUID);
  RtdsReaderShutdown();
  FltAcquirePushLockExclusiveEx(NptrigDriverInstance,0);
  puVar2 = (undefined8 *)(NptrigDriverInstance + 8);
  puVar3 = (undefined8 *)*puVar2;
  while (puVar3 != puVar2) {
    puVar1 = (undefined8 *)*puVar3;
    ExFreePoolWithTag(puVar3,0x6774704e);
    puVar3 = puVar1;
    puVar2 = (undefined8 *)(NptrigDriverInstance + 8);
  }
  FltReleasePushLockEx(NptrigDriverInstance,0);
  FltDeletePushLock(NptrigDriverInstance + 0x18);
  FltDeletePushLock(NptrigDriverInstance);
  ExFreePoolWithTag(NptrigDriverInstance,0x6774704e);
  McGenEventUnregister_EtwUnregister((longlong *)&NPTRIG_ETW_PROVIDER_GUID_Context);
  McGenEventUnregister_EtwUnregister((longlong *)&SERVICE_TRIGGER_PERF_EVENT_GUID_Context);
  WppCleanupKm();
  return;
}



===== NptrigAlterIoStatus @ 1c0008330 =====

void NptrigAlterIoStatus(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,param_3,param_1,(char)param_2);
  }
  *(undefined4 *)(param_1 + 0x18) = param_2;
  FltSetCallbackDataDirty(param_1);
  return;
}



===== NptrigDeleteLock @ 1c0008394 =====

void NptrigDeleteLock(void)

{
  FltDeletePushLock();
  return;
}



===== NptrigDestroyFilterInstance @ 1c00083b0 =====

void NptrigDestroyFilterInstance(longlong param_1)

{
  FltDeletePushLock(param_1 + 0x98);
  return;
}



===== NptrigFilterUnloadCallback @ 1c00083e0 =====

undefined8 NptrigFilterUnloadCallback(void)

{
  if (*(longlong *)(NptrigDriverInstance + 0x38) != 0) {
    FltUnregisterFilter();
  }
  return 0;
}



===== NptrigInstanceTeardownStartCallback @ 1c0008410 =====

void NptrigInstanceTeardownStartCallback
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *local_res8 [4];
  
  local_res8[0] = (longlong *)0x0;
  FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),local_res8);
  FltCbdqDisable(local_res8[0] + 3);
  FltAcquirePushLockExclusiveEx(NptrigDriverInstance,0);
  puVar4 = (undefined8 *)(NptrigDriverInstance + 8);
  for (puVar5 = (undefined8 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined8 *)*puVar5) {
    NptrigReleasePendingRequests((longlong)puVar5,(longlong)local_res8[0],0xc0000034,param_4);
    puVar4 = (undefined8 *)(NptrigDriverInstance + 8);
  }
  FltReleasePushLockEx(NptrigDriverInstance,0);
  FltAcquirePushLockExclusiveEx(NptrigDriverInstance + 0x18,0);
  lVar1 = *local_res8[0];
  if ((*(longlong **)(lVar1 + 8) == local_res8[0]) &&
     (plVar2 = (longlong *)local_res8[0][1], (longlong *)*plVar2 == local_res8[0])) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    FltReleasePushLockEx(NptrigDriverInstance + 0x18,0);
    FltReleaseContext(local_res8[0]);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== NptrigWaitNamedPipeQueueCompleteCanceled @ 1c0008520 =====

void NptrigWaitNamedPipeQueueCompleteCanceled
               (undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong *plVar1;
  char cVar2;
  undefined8 uVar3;
  
  plVar1 = *(longlong **)(param_2 + 0x40);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    param_2 = 0x20;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,param_3,plVar1,(char)*plVar1);
  }
  cVar2 = KeCancelTimer(plVar1 + 0xf);
  if (cVar2 != '\0') {
    NptrigReleaseRequestRef((longlong)plVar1,param_2,param_3);
  }
  uVar3 = 0xc0000120;
  NptrigAlterIoStatus(*plVar1,0xc0000120,param_3);
  FltCompletePendedPostOperation(*plVar1);
  NptrigReleaseRequestRef((longlong)plVar1,uVar3,param_3);
  return;
}



===== WppCleanupKm @ 1c00085ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

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
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppTraceCallback @ 1c0008630 =====

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



===== RtdsReaderShutdown @ 1c00088b8 =====

undefined8 RtdsReaderShutdown(void)

{
  undefined **ppuVar1;
  longlong lVar2;
  
  ppuVar1 = &PTR_RtdsTriggerDbList_1c00050c8;
  lVar2 = 2;
  do {
    RtdsUnregisterUpdateCallback((longlong *)ppuVar1[-4]);
    RtdspFreeEndpointList((longlong *)*ppuVar1);
    ppuVar1 = ppuVar1 + 7;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return 0;
}



===== RtdsUnregisterUpdateCallback @ 1c0008900 =====

undefined8 RtdsUnregisterUpdateCallback(longlong *param_1)

{
  undefined *puVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = 0;
  while( true ) {
    uVar4 = (ulonglong)uVar3;
    if (1 < uVar3) {
      return 0xc0000225;
    }
    lVar2 = *param_1 - *(longlong *)(&PTR_RPC_INTERFACE_EVENT_GUID_1c0004000)[uVar4 * 2];
    if (lVar2 == 0) {
      lVar2 = param_1[1] -
              *(longlong *)((longlong)(&PTR_RPC_INTERFACE_EVENT_GUID_1c0004000)[uVar4 * 2] + 8);
    }
    if (lVar2 == 0) break;
    uVar3 = uVar3 + 1;
  }
  lVar2 = uVar4 * 0x38;
  RtdspLock((&PTR_RtdsTriggerUpdateLock_1c00050d0)[uVar4 * 7]);
  puVar1 = (&PTR_RtdsTriggerUpdateLock_1c00050d0)[uVar4 * 7];
  if (*(longlong *)(&DAT_1c00050b8 + lVar2) == 0) {
    RtdspUnlock(puVar1);
    return 0xc000000d;
  }
  *(undefined8 *)(&DAT_1c00050b8 + lVar2) = 0;
  RtdspUnlock(puVar1);
  ExUnsubscribeWnfStateChange(*(undefined8 *)(&DAT_1c00050c0 + lVar2));
  return 0;
}



===== NptrigFindTrigger @ 1c00089c0 =====

undefined8 NptrigFindTrigger(ushort *param_1,undefined8 *param_2)

{
  short *psVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  short *psVar4;
  uint uVar5;
  
  psVar1 = *(short **)(param_1 + 4);
  puVar3 = *(undefined8 **)(NptrigDriverInstance + 8);
  psVar4 = psVar1 + 1;
  if (*psVar1 != 0x5c) {
    psVar4 = psVar1;
  }
  uVar5 = *param_1 - 2;
  if (*psVar1 != 0x5c) {
    uVar5 = (uint)*param_1;
  }
  while( true ) {
    if (puVar3 == (undefined8 *)(NptrigDriverInstance + 8)) {
      return 0;
    }
    if ((*(ushort *)(puVar3 + 2) == uVar5) &&
       (uVar2 = RtlCompareMemory(psVar4,puVar3[3],uVar5), uVar2 == uVar5)) break;
    puVar3 = (undefined8 *)*puVar3;
  }
  if (param_2 == (undefined8 *)0x0) {
    return 1;
  }
  *param_2 = puVar3;
  return 1;
}



===== NptrigPostCreateCallback @ 1c0008a80 =====

undefined8
NptrigPostCreateCallback(longlong *param_1,longlong param_2,undefined8 param_3,longlong *param_4)

{
  ushort uVar1;
  short *psVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  longlong *plVar7;
  short *psVar8;
  
  if ((((((ulonglong)param_4 & 0x200001) == 0) && ((int)param_1[3] == -0x3fffffcc)) &&
      ((*(uint *)(param_1[2] + 0x20) & 1) == 0)) &&
     ((*(longlong *)(param_2 + 0x20) != 0 && (*(short *)(*(longlong *)(param_2 + 0x20) + 0x58) != 0)
      ))) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      param_4 = param_1;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_3,param_1);
    }
    FltAcquirePushLockExclusiveEx(NptrigDriverInstance,0);
    psVar2 = *(short **)(*(longlong *)(param_2 + 0x20) + 0x60);
    uVar1 = *(ushort *)(*(longlong *)(param_2 + 0x20) + 0x58);
    uVar4 = (ulonglong)uVar1;
    plVar7 = *(longlong **)(NptrigDriverInstance + 8);
    psVar8 = psVar2 + 1;
    if (*psVar2 != 0x5c) {
      psVar8 = psVar2;
    }
    uVar6 = uVar1 - 2;
    if (*psVar2 != 0x5c) {
      uVar6 = (uint)uVar1;
    }
    for (; plVar7 != (longlong *)(NptrigDriverInstance + 8); plVar7 = (longlong *)*plVar7) {
      if (*(ushort *)(plVar7 + 2) == uVar6) {
        lVar5 = plVar7[3];
        uVar4 = (ulonglong)uVar6;
        uVar3 = RtlCompareMemory(psVar8);
        if (uVar3 == uVar6) {
          uVar4 = NptrigHandleTriggerableIo(plVar7,lVar5,uVar4,param_4);
          uVar3 = uVar4 & 0xffffffff;
          if (-1 < (int)uVar4) {
            FltReleasePushLockEx(NptrigDriverInstance,0);
            NptrigAlterIoStatus((longlong)param_1,0xc00000ac,uVar3);
            return 0;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,uVar3,param_1,(char)uVar4);
          }
          goto LAB_1c0008b54;
        }
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,uVar4,param_1);
    }
LAB_1c0008b54:
    FltReleasePushLockEx(NptrigDriverInstance,0);
  }
  return 0;
}



===== NptrigUnlock @ 1c0008c70 =====

void NptrigUnlock(undefined8 param_1)

{
  FltReleasePushLockEx(param_1,0);
  return;
}



===== NptrigLock @ 1c0008c90 =====

void NptrigLock(undefined8 param_1)

{
  FltAcquirePushLockExclusiveEx(param_1,0);
  return;
}



===== NptrigPostCreateNamedPipeCallback @ 1c0008cb0 =====

undefined8
NptrigPostCreateNamedPipeCallback
          (ulonglong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  ushort uVar1;
  short *psVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  undefined8 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  short *psVar8;
  longlong local_28 [2];
  
  local_28[0] = 0;
  if (((((param_4 & 1) == 0) && (*(int *)(param_1 + 0x18) == 0)) &&
      (uVar6 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20), uVar7 = (ulonglong)uVar6,
      (uVar6 & 1) == 0)) &&
     ((*(longlong *)(param_2 + 0x20) != 0 && (*(short *)(*(longlong *)(param_2 + 0x20) + 0x58) != 0)
      ))) {
    FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),local_28);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      param_4 = param_1;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,uVar7,param_1);
    }
    FltAcquirePushLockExclusiveEx(NptrigDriverInstance,0);
    psVar2 = *(short **)(*(longlong *)(param_2 + 0x20) + 0x60);
    uVar1 = *(ushort *)(*(longlong *)(param_2 + 0x20) + 0x58);
    uVar7 = (ulonglong)uVar1;
    puVar5 = *(undefined8 **)(NptrigDriverInstance + 8);
    psVar8 = psVar2 + 1;
    if (*psVar2 != 0x5c) {
      psVar8 = psVar2;
    }
    uVar6 = uVar1 - 2;
    if (*psVar2 != 0x5c) {
      uVar6 = (uint)uVar1;
    }
    for (; puVar5 != (undefined8 *)(NptrigDriverInstance + 8); puVar5 = (undefined8 *)*puVar5) {
      if (*(ushort *)(puVar5 + 2) == uVar6) {
        uVar7 = (ulonglong)uVar6;
        uVar3 = RtlCompareMemory(psVar8,puVar5[3]);
        if (uVar3 == uVar6) {
          if (*(int *)(puVar5 + 4) == 3) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_1c0008d78;
            uVar4 = 0x11;
            goto LAB_1c0008eab;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,uVar7,param_1);
            param_4 = param_1;
          }
          NptrigReleasePendingRequests((longlong)puVar5,local_28[0],0,param_4);
          *(undefined4 *)(puVar5 + 4) = 3;
          goto LAB_1c0008d78;
        }
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      uVar4 = 0x10;
LAB_1c0008eab:
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,uVar7,param_1);
    }
LAB_1c0008d78:
    FltReleasePushLockEx(NptrigDriverInstance,0);
    if (local_28[0] != 0) {
      FltReleaseContext();
    }
  }
  return 0;
}



===== NptrigReleasePendingRequests @ 1c0008ed0 =====

void NptrigReleasePendingRequests
               (longlong param_1,longlong param_2,ulonglong param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar6 = param_3;
  if ((Microsoft_Windows_ServiceTriggerPerfEventProviderEnableBits & 1) != 0) {
    McTemplateK0zz_EtwWriteTransfer
              ((undefined8 *)&SERVICE_TRIGGER_PERF_EVENT_GUID_Context,
               &ServiceTriggerPerfServiceArrived,param_3,param_4,*(wchar_t **)(param_1 + 0x18));
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,uVar6,param_1,(char)param_3);
  }
  lVar4 = param_1 + 0x10;
  lVar3 = FltCbdqRemoveNextIo(param_2 + 0x18);
  while (lVar3 != 0) {
    puVar1 = *(undefined8 **)(lVar3 + 0x40);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      lVar4 = 0x1d;
      WPP_SF_q(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x1d,uVar6,puVar1);
    }
    cVar2 = KeCancelTimer(puVar1 + 0xf);
    if (cVar2 != '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        lVar4 = 0x1e;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,uVar6,puVar1);
      }
      NptrigReleaseRequestRef((longlong)puVar1,lVar4,uVar6);
      FltFreeGenericWorkItem(puVar1[0x18]);
    }
    uVar5 = param_3 & 0xffffffff;
    NptrigAlterIoStatus(lVar3,(int)param_3,uVar6);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      uVar5 = 0x1f;
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,uVar6,*puVar1,(char)param_3);
    }
    FltCompletePendedPostOperation(lVar3);
    NptrigReleaseRequestRef((longlong)puVar1,uVar5,uVar6);
    lVar4 = param_1 + 0x10;
    lVar3 = FltCbdqRemoveNextIo(param_2 + 0x18);
  }
  return;
}



===== NptrigInstanceSetup @ 1c0009070 =====

undefined8 NptrigInstanceSetup(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  longlong lVar8;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  longlong **local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  if (param_4 == 0x19) {
    local_38 = local_18;
    iVar2 = FltAllocateContext(*(undefined8 *)(param_1 + 8),2,0xb0,1);
    if (-1 < iVar2) {
      FltInitializePushLock(local_18[0] + 0x13);
      plVar4 = local_18[0] + 0x14;
      local_18[0][0x15] = (longlong)plVar4;
      *plVar4 = (longlong)plVar4;
      local_20 = NptrigWaitNamedPipeQueueCompleteCanceled;
      local_28 = NptrigWaitNamedPipeQueueRelease;
      local_30 = NptrigWaitNamedPipeQueueAcquire;
      local_38 = (longlong **)NptrigWaitNamedPipeQueuePeekNext;
      iVar2 = FltCbdqInitialize(*(undefined8 *)(param_1 + 0x18),local_18[0] + 3,
                                NptrigWaitNamedPipeQueueInsert,NptrigWaitNamedPipeQueueRemove);
      if ((-1 < iVar2) &&
         (iVar2 = FltSetInstanceContext(*(undefined8 *)(param_1 + 0x18),1,local_18[0]), -1 < iVar2))
      {
        FltAcquirePushLockExclusiveEx(NptrigDriverInstance + 0x18,0);
        puVar7 = auStack_58;
        lVar5 = *(longlong *)(NptrigDriverInstance + 0x20);
        plVar4 = (longlong *)(NptrigDriverInstance + 0x20);
        plVar3 = local_18[0];
        lVar8 = NptrigDriverInstance;
        if (*(longlong **)(lVar5 + 8) != plVar4) {
          plVar4 = (longlong *)0x3;
          pcVar1 = (code *)swi(0x29);
          plVar3 = (longlong *)(*pcVar1)();
          puVar7 = auStack_50;
        }
        *plVar3 = lVar5;
        plVar3[1] = (longlong)plVar4;
        *(longlong **)(lVar5 + 8) = plVar3;
        *plVar4 = (longlong)plVar3;
        *(undefined8 *)(puVar7 + -8) = 0x1c00091d5;
        FltReleasePushLockEx(lVar8 + 0x18,0);
        uVar6 = 0;
        plVar4 = *(longlong **)(puVar7 + 0x40);
        goto LAB_1c000908f;
      }
    }
  }
  puVar7 = auStack_58;
  uVar6 = 0xc01c000f;
  plVar4 = local_18[0];
LAB_1c000908f:
  if (plVar4 != (longlong *)0x0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c00091fa;
    FltReleaseContext(plVar4);
  }
  return uVar6;
}



===== RtdsInternalUpdateCallback @ 1c0009210 =====

void RtdsInternalUpdateCallback(void)

{
  int in_R9D;
  int *in_stack_00000030;
  
  RtdsInternalUpdateCallbackWorker(in_R9D,in_stack_00000030);
  return;
}



===== RtdsInternalUpdateCallbackWorker @ 1c0009230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 RtdsInternalUpdateCallbackWorker(int param_1,int *param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 ***local_28;
  undefined8 ***pppuStack_20;
  undefined8 ***local_18;
  undefined8 uStack_10;
  
  pppuStack_20 = &local_28;
  local_28 = &local_28;
  local_18 = (undefined8 ***)0x0;
  uStack_10 = 0;
  if (param_1 != *param_2) {
    RtdspLock(*(undefined8 *)(param_2 + 0xc));
    pcVar1 = *(code **)(param_2 + 6);
    if (pcVar1 != (code *)0x0) {
      *param_2 = param_1;
      iVar3 = RtdspGetTriggerEndpoints
                        (*(short **)(param_2 + 4),*(undefined8 *)(param_2 + 2),(longlong *)&local_28
                        );
      if (-1 < iVar3) {
        RtdspGenerateEndpointChangelist
                  (*(undefined8 **)(param_2 + 10),&local_28,(longlong *)&local_18);
        if ((undefined8 ****)local_18 == &local_18) {
          RtdspFreeEndpointList((longlong *)&local_28);
        }
        else {
          (*pcVar1)(&local_18);
          RtdspFreeEndpointList(*(longlong **)(param_2 + 10));
          puVar2 = *(undefined8 **)(param_2 + 10);
          if ((undefined8 ****)local_28 == &local_28) {
            puVar2[1] = puVar2;
            *puVar2 = puVar2;
          }
          else {
            *puVar2 = local_28;
            puVar2[1] = pppuStack_20;
            *(longlong **)(**(longlong **)(param_2 + 10) + 8) = *(longlong **)(param_2 + 10);
            **(longlong **)(*(longlong *)(param_2 + 10) + 8) = *(longlong *)(param_2 + 10);
          }
        }
      }
    }
    RtdspUnlock(*(undefined8 *)(param_2 + 0xc));
  }
  return 0;
}



===== RtdspGenerateEndpointChangelist @ 1c0009340 =====

void RtdspGenerateEndpointChangelist(undefined8 *param_1,undefined8 *param_2,longlong *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  param_3[1] = (longlong)param_3;
  *param_3 = (longlong)param_3;
  puVar2 = (undefined8 *)*param_1;
  while (puVar2 != param_1) {
    plVar1 = puVar2 + -5;
    puVar6 = puVar2;
    puVar5 = RtdspFindEndpoint(param_2,puVar2[-2]);
    if (puVar5 == (undefined8 *)0x0) {
      *(undefined4 *)(puVar2 + -1) = 2;
      lVar3 = *param_3;
      if (*(longlong **)(lVar3 + 8) != param_3) goto LAB_1c0009407;
      *plVar1 = lVar3;
      puVar2[-4] = param_3;
      *(longlong **)(lVar3 + 8) = plVar1;
      *param_3 = (longlong)plVar1;
    }
    else {
      *(undefined4 *)(puVar5 + 7) = 1;
    }
    puVar2 = (undefined8 *)*puVar6;
  }
  puVar2 = (undefined8 *)*param_2;
  do {
    if (puVar2 == param_2) {
      return;
    }
    plVar1 = puVar2 + -5;
    if (*(int *)(puVar2 + 2) == 0) {
      *(undefined4 *)(puVar2 + -1) = 1;
      lVar3 = *param_3;
      if (*(longlong **)(lVar3 + 8) != param_3) {
LAB_1c0009407:
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar1 = lVar3;
      puVar2[-4] = param_3;
      *(longlong **)(lVar3 + 8) = plVar1;
      *param_3 = (longlong)plVar1;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== RtdspGetTriggerEndpoints @ 1c0009420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RtdspGetTriggerEndpoints(short *param_1,undefined8 param_2,longlong *param_3)

{
  undefined8 ***pppuVar1;
  code *pcVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  undefined8 uVar6;
  short *psVar7;
  undefined8 *puVar8;
  short *psVar9;
  short *psVar10;
  longlong lVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  ulonglong uVar16;
  longlong lVar17;
  bool bVar18;
  undefined1 auStack_528 [8];
  undefined1 auStack_520 [24];
  undefined4 local_508;
  undefined4 *local_500;
  undefined8 ***local_4f8;
  undefined8 ***pppuStack_4f0;
  undefined4 local_4e8 [2];
  undefined8 local_4e0;
  ushort local_4d8 [4];
  longlong lStack_4d0;
  longlong local_4c8;
  ushort local_4c0;
  ushort local_4be;
  undefined4 local_4bc;
  undefined1 *local_4b8;
  longlong *local_4b0;
  undefined8 local_4a8;
  undefined8 uStack_4a0;
  ushort *local_498;
  undefined8 uStack_490;
  undefined8 local_488;
  ulonglong uStack_480;
  undefined1 local_478 [12];
  uint local_46c;
  undefined1 local_468 [528];
  short local_258 [264];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_528;
  local_488 = 0;
  uStack_480 = uStack_480 & 0xffffffff00000000;
  local_4bc = 0;
  pppuStack_4f0 = &local_4f8;
  local_4e8[0] = 0;
  psVar9 = (short *)0x0;
  local_4f8 = &local_4f8;
  local_4e0 = 0;
  lVar17 = 0;
  local_4a8 = 0;
  uStack_4a0 = 0;
  local_498 = (ushort *)0x0;
  uStack_490 = 0;
  local_4d8[0] = 0;
  local_4d8[1] = 0;
  local_4d8[2] = 0;
  local_4d8[3] = 0;
  lStack_4d0 = 0;
  local_4b0 = param_3;
  iVar5 = RtlStringCopyWorkerW(local_258);
  puVar15 = auStack_528;
  if (iVar5 == 0) {
    RtlInitUnicodeString(local_4d8,local_258);
    local_4d8[1] = 0x202;
    uVar6 = RtlUnicodeStringValidateWorker(local_4d8);
    iVar5 = (int)uVar6;
    puVar15 = auStack_528;
    if (-1 < iVar5) {
      uVar3 = local_4d8[0] >> 1;
      local_4c8 = 0;
      iVar5 = RtlWideCharArrayCopyStringWorker
                        (lStack_4d0 + (ulonglong)uVar3 * 2,0x101 - (ulonglong)uVar3,&local_4c8,
                         param_1);
      local_4d8[0] = (uVar3 + (short)local_4c8) * 2;
      puVar15 = auStack_528;
      if (iVar5 == 0) {
        local_498 = local_4d8;
        local_4a8 = CONCAT44(local_4a8._4_4_,0x30);
        uStack_490 = CONCAT44(uStack_490._4_4_,0x240);
        uStack_4a0 = 0;
        local_488 = 0;
        uStack_480 = 0;
        iVar5 = ZwOpenKey(&local_4e0,0x20019,&local_4a8);
        puVar14 = auStack_528;
        puVar13 = auStack_528;
        puVar15 = auStack_528;
        if (iVar5 == 0) {
          iVar12 = 0;
LAB_1c00095bc:
          if (lVar17 == 0) goto LAB_1c0009720;
          do {
            local_500 = local_4e8;
            local_508 = 0x21a;
            iVar5 = ZwEnumerateKey(local_4e0,iVar12,0,local_478);
            if (iVar5 == -0x7fffffe6) {
              ExFreePoolWithTag(psVar9,0x73647452);
              ExFreePoolWithTag(lVar17,0x73647452);
              if ((undefined8 ****)local_4f8 == &local_4f8) {
LAB_1c00097f9:
                param_3[1] = (longlong)param_3;
                *param_3 = (longlong)param_3;
                puVar13 = puVar14;
              }
              else {
                *param_3 = (longlong)local_4f8;
                param_3[1] = (longlong)pppuStack_4f0;
                *(longlong **)(*param_3 + 8) = param_3;
                *(longlong **)param_3[1] = param_3;
              }
              iVar5 = 0;
              *(undefined1 **)(puVar13 + 0x38) = puVar13 + 0x30;
              *(undefined1 **)(puVar13 + 0x30) = puVar13 + 0x30;
              puVar15 = puVar13;
              break;
            }
            puVar15 = auStack_528;
            if (iVar5 != 0) break;
            uVar16 = (ulonglong)local_46c;
            if (0x219 < local_46c) goto LAB_1c000976c;
            local_4b8 = local_468;
            local_4c0 = (ushort)local_46c;
            local_4be = local_4c0;
            uVar6 = RtlUnicodeStringValidateWorker(&local_4c0);
            iVar5 = (int)uVar6;
            if (iVar5 < 0) {
              *psVar9 = 0;
              puVar15 = auStack_528;
              break;
            }
            puVar15 = local_468;
            lVar11 = 0x101;
            bVar18 = iVar5 < 0;
            iVar5 = 0;
            if (bVar18) {
              puVar15 = (undefined1 *)0x0;
            }
            psVar10 = psVar9;
            do {
              psVar7 = psVar10;
              if ((((uVar16 & 0xffff) >> 1) - 0x101) + lVar11 == 0) goto LAB_1c0009696;
              *psVar7 = *(short *)(((longlong)puVar15 - (longlong)psVar9) + (longlong)psVar7);
              lVar11 = lVar11 + -1;
              psVar10 = psVar7 + 1;
            } while (lVar11 != 0);
            iVar5 = -0x7ffffffb;
LAB_1c0009696:
            *psVar7 = 0;
            puVar15 = auStack_528;
            if (iVar5 != 0) break;
            sVar4 = *psVar9;
            iVar12 = iVar12 + 1;
            psVar10 = psVar9;
            if (sVar4 != 0) {
              do {
                if (sVar4 == 1) {
                  *psVar10 = 0x5c;
                }
                sVar4 = psVar10[1];
                psVar10 = psVar10 + 1;
              } while (sVar4 != 0);
              param_3 = local_4b0;
            }
            puVar8 = RtdspFindEndpoint(&local_4f8,(longlong)psVar9);
            if (puVar8 != (undefined8 *)0x0) goto LAB_1c00095bc;
            *(undefined4 *)(lVar17 + 0x20) = 0;
            *(short **)(lVar17 + 0x18) = psVar9;
            pppuVar1 = (undefined8 ***)(lVar17 + 0x28);
            *(undefined8 *)(lVar17 + 0x10) = param_2;
            *(undefined4 *)(lVar17 + 0x38) = 0;
            if ((undefined8 ****)*pppuStack_4f0 != &local_4f8) {
              pcVar2 = (code *)swi(0x29);
              (*pcVar2)(3);
              puVar14 = auStack_520;
              goto LAB_1c00097f9;
            }
            *(undefined8 ****)(lVar17 + 0x30) = pppuStack_4f0;
            *pppuVar1 = &local_4f8;
            lVar17 = 0;
            *pppuStack_4f0 = pppuVar1;
            pppuStack_4f0 = pppuVar1;
LAB_1c0009720:
            psVar9 = (short *)ExAllocatePool2(0x100,0x202,0x73647452);
            if (psVar9 == (short *)0x0) goto LAB_1c000976c;
            lVar17 = ExAllocatePool2(0x100,0x40);
            if (lVar17 == 0) {
LAB_1c000976c:
              iVar5 = -0x3fffffe9;
              puVar15 = auStack_528;
              break;
            }
          } while( true );
        }
      }
    }
  }
  if (*(longlong *)(puVar15 + 0x48) != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x1c00094f5;
    ZwClose();
  }
  if (iVar5 != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x1c000980e;
    RtdspFreeEndpointList((longlong *)(puVar15 + 0x30));
    if (psVar9 != (short *)0x0) {
      *(undefined8 *)(puVar15 + -8) = 0x1c0009822;
      ExFreePoolWithTag(psVar9,0x73647452);
    }
    if (lVar17 != 0) {
      *(undefined8 *)(puVar15 + -8) = 0x1c000983f;
      ExFreePoolWithTag(lVar17,0x73647452);
    }
  }
  *(undefined8 *)(puVar15 + -8) = 0x1c0009513;
  return iVar5;
}



===== RtdspFindEndpoint @ 1c0009850 =====

undefined8 * RtdspFindEndpoint(undefined8 *param_1,longlong param_2)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  longlong lVar4;
  undefined8 *puVar5;
  
  puVar5 = (undefined8 *)*param_1;
  do {
    if (puVar5 == param_1) {
      return (undefined8 *)0x0;
    }
    psVar3 = (short *)puVar5[-2];
    lVar4 = param_2 - (longlong)psVar3;
    do {
      sVar1 = *psVar3;
      sVar2 = *(short *)((longlong)psVar3 + lVar4);
      if (sVar1 != sVar2) break;
      psVar3 = psVar3 + 1;
    } while (sVar2 != 0);
    if (sVar1 == sVar2) {
      return puVar5 + -5;
    }
    puVar5 = (undefined8 *)*puVar5;
  } while( true );
}



===== RtdspFreeEndpointList @ 1c00098b0 =====

void RtdspFreeEndpointList(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  plVar3 = (longlong *)*param_1;
  if (plVar3 == param_1) {
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
  }
  else {
    do {
      plVar1 = plVar3 + -2;
      plVar2 = plVar3 + -5;
      plVar3 = (longlong *)*plVar3;
      if (*plVar1 != 0) {
        ExFreePoolWithTag(*plVar1,0x73647452);
      }
      ExFreePoolWithTag(plVar2,0x73647452);
    } while (plVar3 != param_1);
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
  }
  return;
}



===== NptrigWaitNamedPipeQueuePeekNext @ 1c0009930 =====

undefined8 * NptrigWaitNamedPipeQueuePeekNext(longlong param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong local_res8;
  
  local_res8 = 0;
  FltGetInstanceContext(*(undefined8 *)(param_1 + 0x48),&local_res8);
  lVar4 = param_3;
  if (param_3 == 1) {
    lVar4 = 0;
  }
  lVar2 = local_res8;
  if (param_2 == 0) {
    puVar3 = *(undefined8 **)(local_res8 + 0xa0);
  }
  else {
    puVar3 = *(undefined8 **)(param_2 + 0x30);
  }
  do {
    if (puVar3 == (undefined8 *)(lVar2 + 0xa0)) {
      FltReleaseContext();
      return (undefined8 *)0x0;
    }
    if (param_3 == 1) {
      if (*(int *)(puVar3[2] + 0xbc) == 3) goto LAB_1c00099c5;
    }
    else {
      cVar1 = RtlEqualUnicodeString(puVar3[2] + 0x60,lVar4,0);
      lVar2 = local_res8;
      if (cVar1 != '\0') {
LAB_1c00099c5:
        FltReleaseContext();
        return puVar3 + -6;
      }
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== NptrigWaitNamedPipeQueueAcquire @ 1c0009a10 =====

void NptrigWaitNamedPipeQueueAcquire(longlong param_1)

{
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  FltGetInstanceContext(*(undefined8 *)(param_1 + 0x48),local_res8);
  FltAcquirePushLockExclusiveEx(local_res8[0] + 0x98,0);
  FltReleaseContext(local_res8[0]);
  return;
}



===== WppInitKm @ 1c0009a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(void)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0x38) = 0;
        (*pcVar1)(*(undefined8 *)(puVar2 + 8),0,WppClassicProviderCallback,puVar2,puVar2 + 0x38);
        puVar2 = *(undefined **)(puVar2 + 0x10);
      } while (puVar2 != (undefined *)0x0);
      return;
    }
    if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
  }
  return;
}



===== NptrigQueueWaitNamedPipeRequest @ 1c0009b20 =====

int NptrigQueueWaitNamedPipeRequest
              (undefined8 param_1,longlong param_2,ushort *param_3,longlong param_4,int param_5)

{
  ushort uVar1;
  ushort uVar2;
  void *_Src;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined2 uVar6;
  undefined8 *puVar7;
  int iStackX_24;
  
  NptrigCleanupOrphanedWaitNamedPipeRequests(param_2,param_2,param_3);
  uVar1 = *param_3;
  puVar4 = (undefined8 *)ExAllocatePool2(0x40,(ulonglong)(ushort)(uVar1 + 2) + 0xd0,0x6774704e);
  if (puVar4 == (undefined8 *)0x0) {
    iVar3 = -0x3fffffe9;
LAB_1c0009c83:
    if (puVar4 != (undefined8 *)0x0) {
      if (puVar4[0x18] != 0) {
        FltFreeGenericWorkItem();
      }
      ExFreePoolWithTag(puVar4,0x6774704e);
    }
    return iVar3;
  }
  uVar2 = *param_3;
  _Src = *(void **)(param_3 + 4);
  puVar4[0xd] = puVar4 + 0x1a;
  *(ushort *)(puVar4 + 0xc) = uVar2;
  *(ushort *)((longlong)puVar4 + 0x62) = uVar1 + 2;
  memcpy(puVar4 + 0x1a,_Src,(ulonglong)uVar2);
  *(undefined2 *)(puVar4[0xd] + (ulonglong)(uVar2 >> 1) * 2) = 0;
  *(undefined4 *)((longlong)puVar4 + 0xbc) = 1;
  puVar4[0x19] = param_2;
  lVar5 = FltAllocateGenericWorkItem();
  puVar4[0x18] = lVar5;
  if (lVar5 == 0) {
    iVar3 = -0x3fffffe9;
    goto LAB_1c0009c83;
  }
  LOCK();
  *(undefined4 *)(puVar4 + 0xe) = 1;
  UNLOCK();
  puVar7 = puVar4;
  KeInitializeDpc(puVar4 + 1,NptrigWaitNamedPipeTimeoutCallback);
  KeInitializeTimer(puVar4 + 0xf);
  NptrigTakeRequestRef((longlong)puVar4);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,puVar7,puVar4,(char)param_1);
  }
  puVar7 = puVar4 + 9;
  *puVar4 = param_1;
  iVar3 = FltCbdqInsertIo(param_2 + 0x18,param_1,puVar7,puVar4);
  if (iVar3 < 0) goto LAB_1c0009c83;
  if (param_5 == 0) {
    param_4 = *(longlong *)(NptrigDriverInstance + 0x30);
    *(undefined4 *)(puVar4 + 0x17) = 1;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_1c0009d82;
    uVar6 = 0x1a;
  }
  else {
    if (((-1 < param_4) ||
        (*(longlong *)(NptrigDriverInstance + 0x30) == param_4 ||
         -param_4 < -*(longlong *)(NptrigDriverInstance + 0x30))) &&
       (((int)param_4 != 0 ||
        (iStackX_24 = (int)((ulonglong)param_4 >> 0x20), iStackX_24 != -0x80000000)))) {
      *(undefined4 *)(puVar4 + 0x17) = 0;
      goto LAB_1c0009d82;
    }
    param_4 = *(longlong *)(NptrigDriverInstance + 0x30);
    *(undefined4 *)(puVar4 + 0x17) = 1;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_1c0009d82;
    uVar6 = 0x1b;
  }
  WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,puVar7,param_1,(char)puVar4);
LAB_1c0009d82:
  KeSetTimer(puVar4 + 0xf,param_4,puVar4 + 1);
  return iVar3;
}



===== NptrigCleanupOrphanedWaitNamedPipeRequests @ 1c0009dc0 =====

void NptrigCleanupOrphanedWaitNamedPipeRequests
               (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = FltCbdqRemoveNextIo(param_1 + 0x18,1);
  while (lVar2 != 0) {
    plVar1 = *(longlong **)(lVar2 + 0x40);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_qq(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x17,param_3,plVar1,
                (char)*plVar1);
    }
    uVar3 = 0xc00000b5;
    if ((int)plVar1[0x17] != 0) {
      uVar3 = 0xc0000034;
    }
    NptrigAlterIoStatus(*plVar1,(int)uVar3,param_3);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      uVar3 = 0x18;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,param_3,plVar1,(char)*plVar1);
    }
    FltCompletePendedPostOperation(*plVar1);
    FltFreeGenericWorkItem(plVar1[0x18]);
    NptrigReleaseRequestRef((longlong)plVar1,uVar3,param_3);
    lVar2 = FltCbdqRemoveNextIo(param_1 + 0x18,1);
  }
  return;
}



===== NptrigWaitNamedPipeQueueRemove @ 1c0009ee0 =====

void NptrigWaitNamedPipeQueueRemove(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x30);
  if ((*(longlong *)(lVar1 + 8) == param_2 + 0x30) &&
     (plVar2 = *(longlong **)(param_2 + 0x38), *plVar2 == param_2 + 0x30)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== NptrigWaitNamedPipeQueueRelease @ 1c0009f10 =====

void NptrigWaitNamedPipeQueueRelease(longlong param_1)

{
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  FltGetInstanceContext(*(undefined8 *)(param_1 + 0x48),local_res8);
  FltReleasePushLockEx(local_res8[0] + 0x98,0);
  FltReleaseContext(local_res8[0]);
  return;
}



===== NptrigTriggerChangeCallback @ 1c0009f70 =====

void NptrigTriggerChangeCallback
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  for (puVar1 = (undefined8 *)*param_1; puVar1 != param_1; puVar1 = (undefined8 *)*puVar1) {
    if (*(int *)(puVar1 + 4) == 1) {
      NptrigCreateTrigger((void *)puVar1[3]);
    }
    else if (*(int *)(puVar1 + 4) == 2) {
      NptrigDestroyTrigger(puVar1[3],param_2,param_3,param_4);
    }
  }
  return;
}



===== NptrigWaitNamedPipeTimeoutWorkItem @ 1c0009fc0 =====

void NptrigWaitNamedPipeTimeoutWorkItem
               (undefined8 param_1,undefined8 param_2,longlong *param_3,longlong *param_4)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  plVar3 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    param_4 = param_3;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,param_3,param_3,(char)*param_3);
  }
  plVar2 = param_3 + 9;
  lVar1 = FltCbdqRemoveIo(param_3[0x19] + 0x18);
  if (lVar1 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      plVar2 = (longlong *)0x22;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,plVar3,param_3,(char)*param_3);
    }
  }
  else {
    if ((Microsoft_Windows_ServiceTriggerPerfEventProviderEnableBits & 1) != 0) {
      McTemplateK0zz_EtwWriteTransfer
                ((undefined8 *)&SERVICE_TRIGGER_PERF_EVENT_GUID_Context,
                 &ServiceTriggerPerfServiceTimedOut,plVar3,param_4,(wchar_t *)param_3[0xd]);
    }
    plVar2 = (longlong *)0xc00000b5;
    if ((int)param_3[0x17] != 0) {
      plVar2 = (longlong *)0xc0000034;
    }
    NptrigAlterIoStatus(*param_3,(int)plVar2,plVar3);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      plVar2 = (longlong *)0x23;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,plVar3,param_3,(char)*param_3);
    }
    FltCompletePendedPostOperation(*param_3);
    NptrigReleaseRequestRef((longlong)param_3,plVar2,plVar3);
  }
  FltFreeGenericWorkItem(param_1);
  NptrigReleaseRequestRef((longlong)param_3,plVar2,plVar3);
  return;
}



===== NptrigWaitNamedPipeQueueInsert @ 1c000a120 =====

undefined8 NptrigWaitNamedPipeQueueInsert(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 *puVar5;
  longlong *plVar6;
  longlong local_res8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res8 = 0;
  FltGetInstanceContext(*(undefined8 *)(param_1 + 0x48),&local_res8);
  puVar5 = auStack_28;
  plVar3 = (longlong *)(param_2 + 0x30);
  lVar4 = local_res8 + 0xa0;
  plVar6 = *(longlong **)(local_res8 + 0xa8);
  if (*plVar6 != lVar4) {
    lVar4 = 3;
    pcVar2 = (code *)swi(0x29);
    plVar3 = (longlong *)(*pcVar2)();
    puVar5 = auStack_20;
  }
  *plVar3 = lVar4;
  plVar3[1] = (longlong)plVar6;
  *plVar6 = (longlong)plVar3;
  *(longlong **)(lVar4 + 8) = plVar3;
  uVar1 = *(undefined8 *)(puVar5 + 0x30);
  *(undefined8 *)(param_2 + 0x40) = param_3;
  *(undefined8 *)(puVar5 + -8) = 0x1c000a18c;
  FltReleaseContext(uVar1);
  return 0;
}



===== NptrigDestroyTrigger @ 1c000a1b0 =====

void NptrigDestroyTrigger
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  short *psVar6;
  uint uVar7;
  longlong *plVar8;
  undefined4 uVar9;
  undefined4 extraout_XMM0_Da;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  short *psStack_10;
  
  local_18 = 0;
  psStack_10 = (short *)0x0;
  RtlInitUnicodeString(&local_18,param_1);
  uVar9 = FltAcquirePushLockExclusiveEx(NptrigDriverInstance,0);
  puVar5 = auStack_38;
  uVar7 = (uint)(ushort)local_18;
  psVar6 = psStack_10;
  if (*psStack_10 == 0x5c) {
    uVar7 = (ushort)local_18 - 2;
    psVar6 = psStack_10 + 1;
  }
  plVar4 = *(longlong **)(NptrigDriverInstance + 8);
  do {
    if (plVar4 == (longlong *)(NptrigDriverInstance + 8)) {
LAB_1c000a313:
      *(undefined8 *)(puVar5 + -8) = 0x1c000a31c;
      FltReleasePushLockEx(uVar9,0);
      return;
    }
    if ((*(ushort *)(plVar4 + 2) == uVar7) &&
       (uVar2 = RtlCompareMemory(psVar6,plVar4[3],uVar7), uVar9 = extraout_XMM0_Da, uVar2 == uVar7))
    {
      lVar3 = *plVar4;
      if ((*(longlong **)(lVar3 + 8) == plVar4) &&
         (plVar8 = (longlong *)plVar4[1], (longlong *)*plVar8 == plVar4)) {
        *plVar8 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar8;
        FltReleasePushLockEx(NptrigDriverInstance,0);
        lVar3 = NptrigDriverInstance + 0x18;
        *(undefined4 *)(plVar4 + 4) = 4;
        FltAcquirePushLockExclusiveEx(lVar3,0);
        plVar8 = *(longlong **)(NptrigDriverInstance + 0x20);
        if (plVar8 != (longlong *)(NptrigDriverInstance + 0x20)) {
          do {
            NptrigReleasePendingRequests((longlong)plVar4,(longlong)plVar8,0xc0000034,param_4);
            plVar8 = (longlong *)*plVar8;
          } while (plVar8 != (longlong *)(NptrigDriverInstance + 0x20));
        }
        FltReleasePushLockEx(NptrigDriverInstance + 0x18,0);
        ExFreePoolWithTag(plVar4,0x6774704e);
        return;
      }
      pcVar1 = (code *)swi(0x29);
      uVar9 = (*pcVar1)(3);
      puVar5 = auStack_30;
      goto LAB_1c000a313;
    }
    plVar4 = (longlong *)*plVar4;
  } while( true );
}



===== RtdsRegisterUpdateCallback @ 1c000a340 =====

undefined8 RtdsRegisterUpdateCallback(void)

{
  undefined *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar5 = 0;
  while( true ) {
    uVar6 = (ulonglong)uVar5;
    if (1 < uVar5) {
      return 0xc0000225;
    }
    lVar3 = 0x45373fac1f81d131 - *(longlong *)(&PTR_RPC_INTERFACE_EVENT_GUID_1c0004000)[uVar6 * 2];
    if (lVar3 == 0) {
      lVar3 = 0x554b2f0c7b7e0c9e -
              *(longlong *)((longlong)(&PTR_RPC_INTERFACE_EVENT_GUID_1c0004000)[uVar6 * 2] + 8);
    }
    if (lVar3 == 0) break;
    uVar5 = uVar5 + 1;
  }
  lVar3 = uVar6 * 0x38;
  RtdspLock((&PTR_RtdsTriggerUpdateLock_1c00050d0)[uVar6 * 7]);
  puVar1 = (&PTR_RtdsTriggerUpdateLock_1c00050d0)[uVar6 * 7];
  if (*(longlong *)(&DAT_1c00050b8 + lVar3) == 0) {
    *(code **)(&DAT_1c00050b8 + lVar3) = NptrigTriggerChangeCallback;
    RtdspUnlock(puVar1);
    iVar2 = ExSubscribeWnfStateChange
                      (&DAT_1c00050c0 + lVar3,
                       (&PTR_WNF_RTDS_RPC_INTERFACE_TRIGGER_CHANGED_1c0004008)[uVar6 * 2],1,0,
                       RtdsInternalUpdateCallback,&RtdsProviderWnfState + lVar3);
    if (iVar2 < 0) {
      RtdspLock((&PTR_RtdsTriggerUpdateLock_1c00050d0)[uVar6 * 7]);
      puVar1 = (&PTR_RtdsTriggerUpdateLock_1c00050d0)[uVar6 * 7];
      *(undefined8 *)(&DAT_1c00050b8 + lVar3) = 0;
      RtdspUnlock(puVar1);
      uVar4 = 0xc0000001;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    RtdspUnlock(puVar1);
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== NptrigHandleTriggerableIo @ 1c000a480 =====

ulonglong NptrigHandleTriggerableIo
                    (longlong *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  ulonglong uVar1;
  
  if ((int)param_1[4] == 3) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      param_2 = 0xb;
      param_4 = param_1;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,param_3,param_1);
    }
    *(undefined4 *)(param_1 + 4) = 1;
  }
  else if ((int)param_1[4] != 1) {
    return 0;
  }
  uVar1 = NptrigFireTrigger(param_1,param_2,param_3,param_4);
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  return 0;
}



===== NptrigCreateTrigger @ 1c000a4f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 NptrigCreateTrigger(void *param_1)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (*(short *)((longlong)param_1 + lVar4 * 2) != 0);
  uVar8 = (int)lVar4 * 2 + 2;
  plVar2 = (longlong *)ExAllocatePool2(0x40,(ulonglong)uVar8 + 0x28,0x6774704e);
  if (plVar2 == (longlong *)0x0) {
    uVar6 = 0xc000009a;
    if (_DAT_00000018 != 0) {
      ExFreePoolWithTag(_DAT_00000018,0x6774704e);
    }
  }
  else {
    plVar2[3] = (longlong)(plVar2 + 5);
    uVar6 = 0;
    memcpy(plVar2 + 5,param_1,(ulonglong)uVar8);
    lVar7 = NptrigDriverInstance;
    *(short *)(plVar2 + 2) = (short)lVar4 * 2;
    *(short *)((longlong)plVar2 + 0x12) = (short)uVar8;
    *(undefined4 *)(plVar2 + 4) = 1;
    FltAcquirePushLockExclusiveEx(lVar7,0);
    puVar5 = auStack_38;
    lVar4 = *(longlong *)(NptrigDriverInstance + 8);
    plVar3 = (longlong *)(NptrigDriverInstance + 8);
    lVar7 = NptrigDriverInstance;
    if (*(longlong **)(lVar4 + 8) != plVar3) {
      lVar4 = 3;
      pcVar1 = (code *)swi(0x29);
      plVar3 = (longlong *)(*pcVar1)();
      puVar5 = auStack_30;
    }
    *plVar2 = lVar4;
    plVar2[1] = (longlong)plVar3;
    *(longlong **)(lVar4 + 8) = plVar2;
    *plVar3 = (longlong)plVar2;
    *(undefined8 *)(puVar5 + -8) = 0x1c000a5e9;
    FltReleasePushLockEx(lVar7,0);
  }
  return uVar6;
}



===== RtdsReaderInitialize @ 1c000a610 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 RtdsReaderInitialize(void)

{
  RtdspInitializeLock(&RtdsTriggerUpdateLock);
  _DAT_1c0005288 = &RtdsTriggerDbList;
  _RtdsTriggerDbList = &RtdsTriggerDbList;
  _DAT_1c00050b8 = 0;
  RtdspInitializeLock(&DAT_1c0005238);
  _DAT_1c00050f0 = 0;
  _DAT_1c0005298 = &DAT_1c0005290;
  _DAT_1c0005290 = &DAT_1c0005290;
  return 0;
}



===== entry @ 1c000b010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c000b044 =====

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



===== DriverEntry @ 1c000b080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined8 *puVar4;
  int iVar5;
  uint uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 *local_a0;
  undefined8 local_98;
  undefined4 local_90 [2];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined1 local_38 [12];
  longlong local_2c;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_c8;
  bVar2 = false;
  local_68 = 0;
  uStack_60 = uStack_60 & 0xffffffff00000000;
  local_90[0] = 0;
  *(code **)(param_1 + 0x68) = DriverUnload;
  local_98 = 0;
  DAT_1c00052c8 = &WPP_ThisDir_CTLGUID_NptrigTracing;
  bVar1 = false;
  local_88 = 0;
  uStack_80 = 0;
  _WPP_MAIN_CB = 0;
  local_78 = (undefined8 *)0x0;
  uStack_70 = 0;
  DAT_1c00052d0 = 0;
  local_58 = 0;
  uStack_50 = 0;
  _DAT_1c00052e0 = 0;
  local_48 = 0;
  uStack_40 = 0;
  _DAT_1c00052e8 = 1;
  WppLoadTracingSupport();
  _DAT_1c00052e0 = 0;
  WppInitKm();
  puVar7 = (undefined8 *)ExAllocatePool2(0x40,0x40,0x6774704e);
  NptrigDriverInstance = puVar7;
  if (puVar7 == (undefined8 *)0x0) {
    uVar9 = 0xc0000017;
    bVar3 = false;
    goto LAB_1c000b31d;
  }
  *puVar7 = 0;
  puVar7[1] = 0;
  puVar7[2] = 0;
  puVar7[3] = 0;
  puVar7[4] = 0;
  puVar7[5] = 0;
  puVar7[6] = 0;
  puVar7[7] = 0;
  NptrigInitializeLock();
  NptrigInitializeLock();
  puVar4 = NptrigDriverInstance;
  puVar7 = NptrigDriverInstance + 1;
  NptrigDriverInstance[2] = puVar7;
  *puVar7 = puVar7;
  puVar7 = puVar4 + 4;
  puVar4[5] = puVar7;
  *puVar7 = puVar7;
  RtlInitUnicodeString
            (&local_58,
             L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\NetworkServiceTriggers\\Config\\"
            );
  local_78 = &local_58;
  local_88 = CONCAT44(local_88._4_4_,0x30);
  uStack_80 = 0;
  puVar7 = (undefined8 *)0x80000000;
  uStack_70 = CONCAT44(uStack_70._4_4_,0x240);
  local_68 = 0;
  uStack_60 = 0;
  iVar5 = ZwOpenKey(&local_98,0x80000000,&local_88);
  if (iVar5 < 0) {
LAB_1c000b272:
    NptrigDriverInstance[6] = 0xffffffffee1e5d00;
  }
  else {
    RtlInitUnicodeString(&local_48,L"NamedPipeTimeout");
    local_a0 = local_90;
    local_a8 = 0x18;
    puVar7 = &local_48;
    iVar5 = ZwQueryValueKey(local_98,puVar7,2,local_38);
    if (iVar5 < 0) {
      ZwClose(local_98);
      goto LAB_1c000b272;
    }
    NptrigDriverInstance[6] = -local_2c;
    ZwClose(local_98);
  }
  McGenEventRegister_EtwRegister
            (&NPTRIG_ETW_PROVIDER_GUID,puVar7,&NPTRIG_ETW_PROVIDER_GUID_Context,
             (longlong *)&NPTRIG_ETW_PROVIDER_GUID_Context);
  McGenEventRegister_EtwRegister
            (&SERVICE_TRIGGER_PERF_EVENT_GUID,puVar7,&SERVICE_TRIGGER_PERF_EVENT_GUID_Context,
             (longlong *)&SERVICE_TRIGGER_PERF_EVENT_GUID_Context);
  uVar8 = RtdsReaderInitialize();
  uVar9 = uVar8 & 0xffffffff;
  bVar3 = true;
  if (-1 < (int)uVar8) {
    bVar2 = true;
    uVar8 = RtdsRegisterUpdateCallback();
    uVar9 = uVar8 & 0xffffffff;
    if (-1 < (int)uVar8) {
      bVar1 = true;
      uVar6 = FltRegisterFilter(param_1,&NptrigRegistration,NptrigDriverInstance + 7);
      uVar9 = (ulonglong)uVar6;
      if (-1 < (int)uVar6) {
        uVar8 = FltStartFiltering(NptrigDriverInstance[7]);
        uVar9 = uVar8 & 0xffffffff;
        if (-1 < (int)uVar8) {
          return uVar8;
        }
      }
    }
  }
LAB_1c000b31d:
  if (NptrigDriverInstance != (undefined8 *)0x0) {
    if (NptrigDriverInstance[7] != 0) {
      FltUnregisterFilter();
    }
    if (bVar1) {
      RtdsUnregisterUpdateCallback(&NAMED_PIPE_EVENT_GUID);
    }
    if (bVar2) {
      RtdsReaderShutdown();
    }
    NptrigDeleteLock();
    NptrigDeleteLock();
    ExFreePoolWithTag(NptrigDriverInstance,0x6774704e);
    if (bVar3) {
      McGenEventUnregister_EtwUnregister((longlong *)&NPTRIG_ETW_PROVIDER_GUID_Context);
      McGenEventUnregister_EtwUnregister((longlong *)&SERVICE_TRIGGER_PERF_EVENT_GUID_Context);
    }
  }
  WppCleanupKm();
  return uVar9;
}


