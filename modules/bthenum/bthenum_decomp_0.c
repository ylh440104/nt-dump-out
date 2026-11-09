
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
  *param_6 = PTR_DAT_140015018;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140015018;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140015030,&local_18,0,0,param_5,param_6);
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



===== BthEnumQueueIrp @ 1400010d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong BthEnumQueueIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  lVar5 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x67,
                     &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 8) + 0x40);
  if ((*(int *)(lVar1 + 0x94) == 0) || (*(int *)(lVar1 + 0x98) == 0)) {
    uVar6 = 0xc0000184;
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar2 + 0x58));
    if (*(longlong *)(lVar1 + 0xa8) == 0) {
      *(longlong *)(lVar1 + 0xa8) = param_2;
      lVar5 = param_2;
      uVar4 = IrpList_EnqueueLocked(lVar2 + 0x40,param_2);
      uVar6 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        LOCK();
        *(longlong *)(param_2 + 0x78) = lVar1;
        UNLOCK();
      }
      lVar5 = CONCAT71((int7)((ulonglong)lVar5 >> 8),uVar3);
      KeReleaseSpinLock(*(undefined8 *)(lVar2 + 0x58));
      if ((int)uVar4 == 0x103) {
        lVar5 = *(longlong *)(lVar1 + 0xc0);
        (**(code **)(lVar2 + 0x30))(*(undefined8 *)(lVar2 + 0x28),lVar5,1);
      }
    }
    else {
      lVar5 = CONCAT71((int7)((ulonglong)lVar5 >> 8),uVar3);
      uVar6 = 0x80000011;
      KeReleaseSpinLock(*(undefined8 *)(lVar2 + 0x58));
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar5,3,0x68,
                      &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar6);
  }
  return uVar6;
}



===== RtlStringCbPrintfW @ 14000122c =====

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



===== RtlStringCchPrintfW @ 1400012a8 =====

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



===== WPP_RECORDER_SF_ @ 140001324 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 1400013dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_S @ 1400014bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,wchar_t *param_6)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,param_4,pwVar2,lVar1,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,4,&WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,param_4,param_6,lVar3
                  ,0);
  return;
}



===== WPP_RECORDER_SF_iS @ 1400015dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iS(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
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
               &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,0x17,&uStack0000000000000030,8,
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
  WppAutoLogTrace(param_1,0,3,&WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,0x17,
                  &uStack0000000000000030,8,in_stack_00000038,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_q @ 140001728 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qD @ 140001808 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,&WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,&WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,param_4,
                  &param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 140001928 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,0,3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qdd @ 1400019f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,0,3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 140001ae4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== BthDispatchCleanup @ 140001c00 =====

uint BthDispatchCleanup(longlong param_1,longlong param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar4 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0xf,
                     &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
  }
  piVar2 = *(int **)(param_1 + 0x40);
  iVar1 = *piVar2;
  if (iVar1 == 0x204f4446) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,3,0x10,
                       &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(*(undefined8 *)(piVar2 + 6));
    lVar4 = param_2;
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar3 = -(uint)(iVar1 != 0x4f445044) & 0xc00000bb;
    lVar4 = 0;
    *(uint *)(param_2 + 0x30) = uVar3;
    IofCompleteRequest(param_2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,4,0x11,
                      &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids,(char)uVar3);
  }
  return uVar3;
}



===== BthDispatchClose @ 140001d20 =====

uint BthDispatchClose(longlong param_1,longlong param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar4 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x12,
                     &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
  }
  piVar2 = *(int **)(param_1 + 0x40);
  iVar1 = *piVar2;
  if (iVar1 == 0x204f4446) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,3,0x13,
                       &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(*(undefined8 *)(piVar2 + 6));
    lVar4 = param_2;
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar3 = -(uint)(iVar1 != 0x4f445044) & 0xc00000bb;
    lVar4 = 0;
    *(uint *)(param_2 + 0x30) = uVar3;
    IofCompleteRequest(param_2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,4,0x14,
                      &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids,(char)uVar3);
  }
  return uVar3;
}



===== BthDispatchCreate @ 140001e40 =====

undefined4 BthDispatchCreate(longlong param_1,longlong param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  lVar4 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,10,
                     &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
  }
  piVar2 = *(int **)(param_1 + 0x40);
  iVar1 = *piVar2;
  if (iVar1 == 0x204f4446) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,3,0xb,
                       &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(*(undefined8 *)(piVar2 + 6));
    lVar4 = param_2;
  }
  else {
    if ((iVar1 == 0x4f445044) && (piVar2[0x34] != 3)) {
      uVar3 = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,3,0xc,
                         &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
      }
    }
    else {
      uVar3 = 0xc00000bb;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,3,0xd,
                          &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids,(char)iVar1);
      }
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    lVar4 = 0;
    *(undefined4 *)(param_2 + 0x30) = uVar3;
    IofCompleteRequest(param_2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,4,0xe,
                      &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids,(char)uVar3);
  }
  return uVar3;
}



===== WPP_RECORDER_SF_qs @ 140001fb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qs(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000038[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids,0x18,&uStack0000000000000030,8,
               pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,0,3,&WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids,0x18,
                  &uStack0000000000000030,8,in_stack_00000038,lVar2,0);
  return;
}



===== WppClassicProviderCallback @ 140002100 =====

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



===== _tlgDefineProvider_annotation__Tlgg_hBthEnumProviderProv @ 14000215c =====

void _tlgDefineProvider_annotation__Tlgg_hBthEnumProviderProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 140002168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  bool bVar7;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  short local_44 [2];
  undefined4 local_40 [10];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = *param_2;
  do {
    LOCK();
    uVar4 = *param_2;
    bVar7 = uVar2 == uVar4;
    if (bVar7) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar7);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar7 = uVar4 == uVar1;
      if (bVar7) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
    uVar4 = uVar3 & ~uVar4;
  }
  puVar5 = &local_48;
  if ((uVar4 & 1) != 0) {
    puVar5 = local_40;
    local_44[0] = 2;
    local_44[1] = 1;
    local_48 = param_1;
  }
  if ((uVar4 & 2) != 0) {
    *puVar5 = param_1;
    puVar5[1] = 0x10006;
    puVar5 = puVar5 + 2;
  }
  if ((uVar4 & 4) != 0) {
    *puVar5 = param_1;
    puVar5[1] = 0x10003;
    puVar5 = puVar5 + 2;
  }
  if (7 < uVar4) {
    *puVar5 = param_1;
    puVar5[1] = 0x10007;
    puVar5 = puVar5 + 2;
  }
  if ((uVar2 >> 5 & 0x1ff) != 0) {
    *puVar5 = param_1;
    *(ushort *)((longlong)puVar5 + 6) = (ushort)(uVar2 >> 5) & 0x1ff;
    *(ushort *)(puVar5 + 1) = ((ushort)(uVar2 >> 0xe) & 1) << 2;
    puVar5 = puVar5 + 2;
  }
  if ((uVar2 >> 0xf & 0x7f) != 0) {
    *puVar5 = param_1;
    *(ushort *)((longlong)puVar5 + 6) = (ushort)(uVar2 >> 0xf) & 0x7f;
    *(ushort *)(puVar5 + 1) = ((ushort)(uVar2 >> 0x16) & 1) * 4 + 1;
    puVar5 = puVar5 + 2;
  }
  lVar6 = (longlong)puVar5 - (longlong)&local_48 >> 3;
  if (0 < lVar6) {
    RtlRecordFeatureUsage(&local_48,lVar6);
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 1400022c0 =====

void wil_details_RecordFeatureUsageReporting(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack0000000000000028;
  undefined2 in_stack_0000002c;
  undefined2 in_stack_0000002e;
  
  iVar2 = g_wil_details_featureUsageCached;
  piVar1 = (int *)CONCAT26(in_stack_0000002e,CONCAT24(in_stack_0000002c,uStack0000000000000028));
  if (*piVar1 != 0) {
    LOCK();
    g_wil_details_featureUsageCached = 1;
    UNLOCK();
    if ((iVar2 == 0) && (g_wil_details_featureUsageProvider != 0)) {
      RtlArmFeatureUsageProviderFlushNotification(g_wil_details_featureUsageProvider,1);
    }
  }
  if (piVar1[1] != 0) {
    in_stack_0000002c = (undefined2)piVar1[2];
    in_stack_0000002e = (undefined2)piVar1[1];
    uStack0000000000000028 = param_1;
    RtlRecordFeatureUsage(&uStack0000000000000028,1);
  }
  return;
}



===== BthEnumFdoPowerComplete @ 140002350 =====

undefined8 BthEnumFdoPowerComplete(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if ((*(char *)(lVar2 + 1) == '\x02') && (*(int *)(lVar2 + 0x10) == 1)) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x24) = *(undefined4 *)(lVar2 + 0x18);
    PoSetPowerState(param_1);
  }
  PoStartNextPowerIrp(param_2);
  return 0;
}



===== BthEnumWaitWakeCancelRoutine @ 1400023c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BthEnumWaitWakeCancelRoutine(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  longlong lVar9;
  undefined1 *puVar10;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  lVar9 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0x90);
  lVar4 = *(longlong *)(*(longlong *)(lVar9 + 8) + 0x40);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x19,
                       &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,(char)param_2,(char)param_1)
    ;
  }
  uVar8 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar3 + 0x18));
  LOCK();
  uVar2 = *(undefined8 *)(param_2 + 0x78);
  *(undefined8 *)(param_2 + 0x78) = 0;
  UNLOCK();
  KeReleaseSpinLock(*(undefined8 *)(lVar3 + 0x18),CONCAT71((int7)((ulonglong)uVar2 >> 8),uVar8));
  (**(code **)(lVar4 + 0x30))(*(undefined8 *)(lVar4 + 0x28),*(undefined8 *)(lVar9 + 0xc0),2);
  *(undefined8 *)(lVar9 + 0xa8) = 0;
  lVar9 = *(longlong *)(param_2 + 0x90);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar9 + 0x18));
  plVar1 = (longlong *)(param_2 + 0xa8);
  plVar5 = (longlong *)*plVar1;
  if (plVar5 == plVar1) {
LAB_1400024ce:
    KeReleaseSpinLock(*(undefined8 *)(lVar9 + 0x18));
    puVar10 = auStackY_58;
    if (*(code **)(lVar9 + 0x30) != (code *)0x0) {
      (**(code **)(lVar9 + 0x30))(param_1,param_2,0xc0000120);
      puVar10 = auStackY_58;
      lVar9 = param_2;
      goto LAB_14000251c;
    }
  }
  else {
    if (((longlong *)plVar5[1] == plVar1) &&
       (plVar6 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar6 == plVar1)) {
      *plVar6 = (longlong)plVar5;
      plVar5[1] = (longlong)plVar6;
      *(int *)(lVar9 + 0x20) = *(int *)(lVar9 + 0x20) + -1;
      goto LAB_1400024ce;
    }
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(3);
    puVar10 = auStackY_50;
  }
  lVar9 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  *(undefined8 *)(puVar10 + -8) = 0x140002517;
  IofCompleteRequest(param_2);
LAB_14000251c:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    *(undefined **)(puVar10 + 0x20) = &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids;
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined8 *)(puVar10 + -8) = 0x140002544;
    WPP_RECORDER_SF_(uVar2,lVar9,3,0x1a,*(undefined8 *)(puVar10 + 0x20));
  }
  return;
}



===== WPP_RECORDER_SF_c @ 14000256c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_c(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,0x10,&uStack0000000000000030,1,0);
  }
  WppAutoLogTrace(param_1,0,3,&WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,0x10,
                  &uStack0000000000000030,1,0);
  return;
}



===== WPP_RECORDER_SF_dD @ 14000260c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,0x11,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,0,3,&WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,0x11,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== ForwardIrp @ 1400026d4 =====

void ForwardIrp(undefined8 param_1,longlong param_2)

{
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver();
  return;
}



===== IoCompletionForOpenChannelSuccess @ 140002700 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 IoCompletionForOpenChannelSuccess(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  short sVar2;
  bool bVar3;
  longlong lVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  undefined1 auStackY_148 [32];
  undefined1 local_118 [4];
  undefined2 local_114 [2];
  undefined4 local_110;
  uint local_10c;
  undefined8 local_108 [2];
  undefined8 local_f8 [4];
  undefined8 *local_d8;
  undefined8 local_d0;
  longlong local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  int local_a0;
  undefined4 local_9c;
  undefined2 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  wchar_t local_68 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  lVar4 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                      &WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids,3,0xf,
                      &WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids,
                      (char)*(undefined4 *)(param_2 + 0x30));
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (((-1 < *(int *)(param_2 + 0x30)) &&
      (lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8), lVar4 != 0)) &&
     ((((sVar2 = *(short *)(lVar4 + 0x16), sVar2 == 0x102 ||
        ((((sVar2 == 0x103 || (sVar2 == 0x202)) || (sVar2 == 0x203)) ||
         ((sVar2 == 0x210 || (sVar2 == 0x211)))))) || (sVar2 == 0x212)) || (sVar2 == 0x213)))) {
    LOCK();
    *(int *)(param_3 + 0xb6c) = *(int *)(param_3 + 0xb6c) + 1;
    UNLOCK();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                        &WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids,2,0x10,
                        &WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids,
                        (char)*(undefined4 *)(param_3 + 0xb6c));
    }
  }
  if (param_3 != 0) {
    uVar8 = 0;
    uVar5 = 0;
    if (-1 < *(int *)(param_2 + 0x30)) {
      sVar2 = *(short *)(lVar4 + 0x16);
      if (((sVar2 == 0x102) || (sVar2 == 0x103)) || ((sVar2 == 0x212 || (sVar2 == 0x213)))) {
        uVar8 = *(undefined2 *)(lVar4 + 0x78);
      }
      if ((sVar2 == 0x102) || (sVar2 == 0x212)) {
        uVar5 = 1;
      }
    }
    uVar7 = 10;
    local_68[0] = L'\0';
    local_68[1] = L'\0';
    local_68[2] = L'\0';
    local_68[3] = L'\0';
    local_68[4] = L'\0';
    local_68[5] = L'\0';
    local_68[6] = L'\0';
    local_68[7] = L'\0';
    local_68[8] = L'\0';
    local_68[9] = L'\0';
    local_68[10] = L'\0';
    local_68[0xb] = L'\0';
    local_68[0xc] = L'\0';
    local_68[0xd] = L'\0';
    local_68[0xe] = L'\0';
    local_68[0xf] = L'\0';
    uVar6 = 0x10;
    _ui64tow_s(*(ulonglong *)(param_3 + 0xc0),local_68,0x10,10);
    if (5 < DAT_140015010) {
      if (((DAT_140015020 & 0x400000000000) == 0) ||
         (bVar3 = true, (DAT_140015028 & 0x400000000000) != DAT_140015028)) {
        bVar3 = false;
      }
      if (bVar3) {
        local_d8 = local_108;
        local_108[0] = 0x3000800;
        local_c8 = param_3 + 0x420;
        local_d0 = 8;
        local_110 = *(undefined4 *)(param_3 + 200);
        local_b8 = &local_110;
        lVar4 = -1;
        local_c0 = 0x10;
        local_b0 = 4;
        do {
          lVar4 = lVar4 + 1;
        } while (local_68[lVar4] != L'\0');
        local_a0 = (int)lVar4 * 2 + 2;
        local_9c = 0;
        local_a8 = local_68;
        local_98 = local_114;
        local_10c = *(uint *)(param_2 + 0x30);
        local_88 = local_118;
        local_78 = &local_10c;
        local_90 = 2;
        local_80 = 1;
        local_70 = 4;
        local_118[0] = uVar5;
        local_114[0] = uVar8;
        _tlgWriteTransfer_EtwWriteTransfer
                  ((ulonglong)local_10c,&DAT_14001398d,uVar6,uVar7,9,local_f8);
      }
    }
  }
  return *(undefined4 *)(param_2 + 0x30);
}



===== IoCompletionSetEvent @ 1400029d0 =====

undefined8 IoCompletionSetEvent(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== WPP_RECORDER_SF_dd @ 1400029fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids,0xe,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,0,3,&WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids,0xe,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== BthEnumDeleteAllPdos @ 140002ac4 =====

void BthEnumDeleteAllPdos(longlong param_1)

{
  longlong lVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  KeEnterCriticalRegion();
  lVar1 = param_1 + 0x98;
  ExAcquireFastMutexUnsafe(lVar1);
  puVar2 = (ulonglong *)(param_1 + 0x88);
  do {
    if ((*(byte *)(param_1 + 0x90) & 1) == 0) {
      uVar3 = *puVar2;
      uVar4 = uVar3;
    }
    else {
      uVar4 = *puVar2;
      if (uVar4 == 0) {
LAB_140002bcd:
        ExReleaseFastMutexUnsafe(lVar1);
        KeLeaveCriticalRegion();
        return;
      }
      uVar3 = uVar4 ^ (ulonglong)puVar2;
    }
    if (uVar3 == 0) goto LAB_140002bcd;
    uVar3 = uVar4;
    RtlRbRemoveNode(puVar2);
    ExReleaseFastMutexUnsafe(lVar1);
    KeLeaveCriticalRegion();
    BthEnumDestroyPdoExt(uVar4 - 0x50);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x13,
                        &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,
                        (char)*(undefined8 *)(uVar4 - 0x40));
    }
    IoDeleteDevice(*(undefined8 *)(uVar4 - 0x40));
    KeEnterCriticalRegion();
    ExAcquireFastMutexUnsafe(lVar1);
  } while( true );
}



===== BthEnumDeleteProtocol @ 140002c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BthEnumDeleteProtocol(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  byte bVar2;
  undefined1 uVar3;
  bool bVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  code *pcVar10;
  
  pcVar10 = (code *)0x0;
  lVar7 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0xc,
                       &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)param_1,(char)param_2)
    ;
  }
  BthEnumUnregisterDeviceInterface(param_2,'\x01');
  uVar3 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(param_1 + 0x58));
  puVar6 = *(undefined8 **)(param_2 + 0xa8);
  if (puVar6 != (undefined8 *)0x0) {
    bVar4 = IrpList_DequeueIrpLocked((undefined8 *)(param_1 + 0x40),puVar6);
    if (bVar4) {
      lVar7 = *(longlong *)(param_2 + 0xa8);
    }
    *(undefined8 *)(param_2 + 0xa8) = 0;
    pcVar10 = *(code **)(param_1 + 0x30);
  }
  puVar6 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar6 >> 8),uVar3);
  KeReleaseSpinLock(*(undefined8 *)(param_1 + 0x58));
  if (pcVar10 != (code *)0x0) {
    puVar6 = *(undefined8 **)(param_2 + 0xc0);
    (*pcVar10)(*(undefined8 *)(param_1 + 0x28),puVar6,2);
  }
  if (lVar7 != 0) {
    puVar6 = (undefined8 *)0x0;
    LOCK();
    *(undefined8 *)(lVar7 + 0x78) = 0;
    UNLOCK();
    *(undefined4 *)(lVar7 + 0x30) = 0xc000009d;
    IofCompleteRequest(lVar7);
  }
  KeEnterCriticalRegion();
  lVar7 = param_1 + 0x98;
  ExAcquireFastMutexUnsafe(lVar7);
  if (*(int *)(param_2 + 0xb0) == 3) {
    puVar1 = (ulonglong *)(param_1 + 0x88);
    puVar8 = (undefined8 *)*puVar1;
    if (((*(byte *)(param_1 + 0x90) & 1) != 0) && (puVar8 != (undefined8 *)0x0)) {
      puVar8 = (undefined8 *)((ulonglong)puVar8 ^ (ulonglong)puVar1);
    }
    bVar2 = *(byte *)(param_1 + 0x90);
    if (puVar8 != (undefined8 *)0x0) {
      do {
        puVar6 = puVar8;
        iVar5 = BthEnumChildCompare(param_2,(longlong)puVar8);
        if (iVar5 < 0) {
          puVar9 = (undefined8 *)*puVar8;
        }
        else {
          if (iVar5 < 1) break;
          puVar9 = (undefined8 *)puVar8[1];
        }
        if (((bVar2 & 1) != 0) && (puVar9 != (undefined8 *)0x0)) {
          puVar9 = (undefined8 *)((ulonglong)puVar8 ^ (ulonglong)puVar9);
        }
        puVar8 = puVar9;
      } while (puVar9 != (undefined8 *)0x0);
      if (puVar8 != (undefined8 *)0x0) {
        puVar6 = (undefined8 *)(param_2 + 0x50);
        RtlRbRemoveNode(puVar1);
        *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
      }
    }
    ExReleaseFastMutexUnsafe(lVar7);
    KeLeaveCriticalRegion();
    BthEnumDestroyPdoExt(param_2);
    IoDeleteDevice(*(undefined8 *)(param_2 + 0x10));
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,4,0xe,
                       &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,4,0xd,
                       &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids);
    }
    ExReleaseFastMutexUnsafe(lVar7);
    KeLeaveCriticalRegion();
  }
  return;
}



===== BthEnumEnumerateFlags @ 140002e80 =====

void BthEnumEnumerateFlags(longlong param_1,ulonglong param_2)

{
  if ((param_2 & 0xfffffffe) == 0) {
    *(int *)(*(longlong *)(param_1 + 0x40) + 0xf8) = (int)param_2;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x29,
                      &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)param_2);
  }
  return;
}



===== BthEnumEnumerateWWSettings @ 140002ee0 =====

void BthEnumEnumerateWWSettings(longlong param_1,undefined8 *param_2,longlong *param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined8 *)(lVar1 + 0x30) = param_2[1];
  *(undefined8 *)(lVar1 + 0x28) = *param_2;
  param_3[1] = (longlong)BthEnumProcessWWIrp;
  *param_3 = param_1;
  return;
}



===== BthEnumGetDeviceList @ 140002f0c =====

undefined4 BthEnumGetDeviceList(longlong param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  uint *puVar6;
  ulonglong *puVar7;
  uint uVar8;
  undefined4 uVar9;
  
  puVar1 = *(uint **)(param_2 + 0xe);
  uVar8 = *(uint *)(param_1 + 0xfc);
  puVar6 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x25,
                     &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids);
  }
  if (puVar1 != (uint *)0x0) {
    uVar8 = uVar8 + *puVar1;
  }
  if ((0xffffffff < (ulonglong)uVar8 * 8) ||
     (uVar8 = (int)((ulonglong)uVar8 * 8) + 0x10, uVar8 < 0x10)) {
    uVar9 = 0xc0000095;
    goto LAB_1400030d6;
  }
  puVar6 = (uint *)(ulonglong)uVar8;
  puVar2 = (uint *)ExAllocatePool2(0x100,puVar6,0x4f4d5442);
  if (puVar2 == (uint *)0x0) {
    uVar9 = 0xc000009a;
    goto LAB_1400030d6;
  }
  *puVar2 = 0;
  uVar9 = 0;
  if (puVar1 != (uint *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x26,
                        &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)*puVar1);
    }
    uVar4 = 0;
    if (*puVar1 != 0) {
      do {
        *(undefined8 *)(puVar2 + uVar4 * 2 + 2) = *(undefined8 *)(puVar1 + uVar4 * 2 + 2);
        uVar8 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar8;
        *puVar2 = *puVar2 + 1;
      } while (uVar8 < *puVar1);
    }
    ExFreePool(puVar1);
  }
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(param_1 + 0x98);
  puVar5 = *(ulonglong **)(param_1 + 0x90);
  if (((ulonglong)puVar5 & 1) == 0) {
joined_r0x000140003062:
    while (puVar5 != (ulonglong *)0x0) {
      puVar7 = (ulonglong *)puVar5[1];
      if (puVar7 == (ulonglong *)0x0) {
        uVar4 = puVar5[2];
        puVar3 = puVar5;
        while ((puVar7 = (ulonglong *)(uVar4 & 0xfffffffffffffffc), puVar7 != (ulonglong *)0x0 &&
               ((ulonglong *)*puVar7 != puVar3))) {
          puVar3 = puVar7;
          uVar4 = puVar7[2];
        }
      }
      else {
        for (puVar3 = (ulonglong *)*puVar7; puVar3 != (ulonglong *)0x0;
            puVar3 = (ulonglong *)*puVar3) {
          puVar7 = puVar3;
        }
      }
      puVar6 = puVar2;
      BthEnumReportID((longlong)puVar5,puVar2);
      puVar5 = puVar7;
    }
  }
  else if (puVar5 != (ulonglong *)0x1) {
    puVar5 = (ulonglong *)((param_1 + 0x88U | 1) ^ (ulonglong)puVar5);
    goto joined_r0x000140003062;
  }
  ExReleaseFastMutexUnsafe(param_1 + 0x98);
  KeLeaveCriticalRegion();
  *(uint **)(param_2 + 0xe) = puVar2;
LAB_1400030d6:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,4,0x27,
                      &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)uVar9);
  }
  return uVar9;
}



===== BthEnumProcessWWIrp @ 140003130 =====

void BthEnumProcessWWIrp(longlong param_1,undefined8 param_2)

{
  longlong ***ppplVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 uVar4;
  bool bVar5;
  longlong ****pppplVar6;
  longlong ****pppplVar7;
  longlong ****pppplVar8;
  longlong ****pppplVar9;
  longlong ****local_18;
  longlong ****local_10;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x24,
                      &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)param_2);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  pppplVar7 = (longlong ****)(lVar2 + 0x40);
  if ((int)param_2 != -0x3ffffee0) {
    local_10 = (longlong ****)&local_18;
    local_18 = (longlong ****)&local_18;
    uVar4 = KeAcquireSpinLockRaiseToDpc(*(undefined8 *)(lVar2 + 0x58));
    pppplVar8 = (longlong ****)*pppplVar7;
    while (pppplVar9 = pppplVar8, pppplVar9 != pppplVar7) {
      pppplVar8 = (longlong ****)*pppplVar9;
      bVar5 = IrpList_DequeueIrpLocked(pppplVar7,pppplVar9 + -0x15);
      if (bVar5) {
        if ((longlong *****)*local_10 != &local_18) goto LAB_140003269;
        pppplVar9[1] = (longlong ***)local_10;
        *pppplVar9 = (longlong ***)&local_18;
        *local_10 = (longlong ***)pppplVar9;
        local_10 = pppplVar9;
      }
    }
    KeReleaseSpinLock(*(undefined8 *)(lVar2 + 0x58),uVar4);
    while (pppplVar7 = local_18, (longlong *****)local_18 != &local_18) {
      if (((longlong *****)local_18[1] != &local_18) ||
         (pppplVar8 = (longlong ****)*local_18, (longlong ****)pppplVar8[1] != local_18)) {
LAB_140003269:
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        return;
      }
      pppplVar8[1] = (longlong ***)&local_18;
      pppplVar6 = local_18 + -0x15;
      LOCK();
      pppplVar9 = local_18 + -6;
      ppplVar1 = *pppplVar9;
      local_18 = pppplVar8;
      *pppplVar9 = (longlong ***)0x0;
      UNLOCK();
      ppplVar1[0x15] = (longlong **)0x0;
      *(int *)(pppplVar7 + -0xf) = (int)param_2;
      IofCompleteRequest(pppplVar6,0);
    }
  }
  return;
}



===== BthEnumUpdateDeviceKey @ 140003294 =====

int BthEnumUpdateDeviceKey(longlong param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined8 uVar3;
  longlong lVar4;
  wchar_t *pwVar5;
  longlong local_res10;
  ulonglong in_stack_ffffffffffffffe0;
  short *psVar6;
  undefined4 uVar7;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10 = 0;
  local_18 = 0;
  uStack_10 = 0;
  pwVar2 = (wchar_t *)ExAllocatePool2(0x100,0x26a,0x4f4d5442);
  if (pwVar2 == (wchar_t *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x10),1,2,&local_res10);
    uVar7 = (undefined4)(in_stack_ffffffffffffffe0 >> 0x20);
    if (-1 < iVar1) {
      psVar6 = (short *)(param_1 + 0x434);
      if (*psVar6 == 0x4c) {
        uVar3 = RtlStringCchPrintfW(pwVar2,0x135,L"%s#%s",*(undefined8 *)(param_1 + 0x38));
        iVar1 = (int)uVar3;
      }
      else {
        if (*psVar6 == 0) {
          pwVar5 = L"%s#%s_%08x";
          psVar6 = (short *)(in_stack_ffffffffffffffe0 & 0xffffffff00000000);
        }
        else {
          pwVar5 = L"%s#%s_%s";
        }
        uVar7 = (undefined4)((ulonglong)psVar6 >> 0x20);
        uVar3 = RtlStringCchPrintfW(pwVar2,0x135,pwVar5,*(undefined8 *)(param_1 + 0x38));
        iVar1 = (int)uVar3;
      }
      if (-1 < iVar1) {
        RtlInitUnicodeString(&local_18,L"Bluetooth_UniqueID");
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (pwVar2[lVar4] != L'\0');
        iVar1 = ZwSetValueKey(local_res10,&local_18,0,1,pwVar2,CONCAT44(uVar7,(int)lVar4 * 2 + 2));
      }
    }
    ExFreePool(pwVar2);
  }
  if (local_res10 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== Feature_56664216__private_IsEnabledDeviceUsageNoInline @ 140003418 =====

ulonglong Feature_56664216__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_56664216__private_featureState;
  if ((Feature_56664216__private_featureState & 0x10) == 0) {
    uVar1 = Feature_56664216__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_56664216__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_56664216__private_IsEnabledFallback @ 140003450 =====

void Feature_56664216__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== GS_Init @ 140003468 =====

void GS_Init(wchar_t *param_1,uint *param_2)

{
  undefined8 uVar1;
  
  uVar1 = RtlStringCbPrintfW(param_1,0x4e,L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
                             (ulonglong)*param_2);
  if (-1 < (int)uVar1) {
    RtlInitUnicodeString(param_1 + 0x28,param_1);
  }
  return;
}



===== WPP_RECORDER_SF_SS @ 14000352c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,wchar_t *param_7)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar6 = -1;
  lVar5 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) {
    if (param_7 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_7[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar4 = param_7;
    if (param_7 == (wchar_t *)0x0) {
      pwVar4 = L"NULL";
    }
    if (param_6 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_6[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,param_4,pwVar3,lVar2,pwVar4,lVar1,0)
    ;
  }
  if (param_7 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_7 == (wchar_t *)0x0) {
    param_7 = L"NULL";
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar6 = lVar6 + 1;
    } while (param_6[lVar6] != L'\0');
    lVar5 = lVar6 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,4,&WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,param_4,param_6,lVar5
                  ,param_7,lVar1,0);
  return;
}



===== WPP_RECORDER_SF_dq @ 1400036b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,0x1c,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,0,4,&WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,0x1c,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_qqq @ 140003784 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,0x1d,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,0,4,&WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,0x1d,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,0);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140003868 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_3 == 0) {
LAB_140003a71:
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar6 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar6 = uVar3 | uVar6 & 0xffffbfff;
      }
      uVar5 = uVar6 >> 5 & 0x1ff;
      uVar3 = uVar5 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 5 ^ uVar6) & 0x3fe0 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_140003943:
        uVar6 = 0;
        if (param_3 == 2) {
          uVar6 = 2;
        }
        else if (param_3 == 3) {
          uVar6 = 8;
        }
        else if (param_3 == 6) {
          uVar6 = 4;
        }
        else if (param_3 == 7) {
          uVar6 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar6 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar5 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar5 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar5;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar5 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_140003a71;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar6 = param_3 - 0x140;
          if ((int)uVar6 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar6)) {
                uVar3 = 0;
              }
              else {
                uVar3 = 1;
              }
              param_1[4] = uVar3;
              LOCK();
              uVar3 = param_2[1];
              bVar7 = uVar4 == uVar3;
              if (bVar7) {
                param_2[1] = (uVar6 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
              }
              else {
                uVar4 = uVar3;
              }
              UNLOCK();
            } while (!bVar7);
            if (param_1[4] != 0) {
              return param_1;
            }
          }
          param_1[2] = param_3;
          param_1[1] = 1;
          param_1[3] = param_4;
          return param_1;
        }
        goto LAB_140003943;
      }
    }
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar6 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar6 = uVar3 | uVar6 & 0xffbfffff;
      }
      uVar5 = uVar6 >> 0xf & 0x7f;
      uVar3 = uVar5 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 0xf ^ uVar6) & 0x3f8000 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140003b5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_140003c1f;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_140003c1f;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_140003c1f;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_140003c1f;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_140003c1f;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_140003c1f;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_140003c1f;
    }
  }
  uVar2 = 0xff;
LAB_140003c1f:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x360a098,&Feature_Standalone_Future_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140003c78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,(uint *)&Feature_56664216__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x360a098,param_3,1,&Feature_56664216__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x360a098);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140003d64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar3 = 0;
  local_88 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar3 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  bVar2 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  iVar4 = RtlQueryFeatureConfiguration
                    (*(undefined4 *)(param_3 + 0x18),1 < (byte)(*(char *)(param_3 + 0x1c) - 2U),
                     &local_78,&local_58);
  if (iVar4 == 0) {
    bVar2 = 1;
    uVar8 = local_58._4_4_ >> 7 & 1;
    local_70 = CONCAT44(local_70._4_4_,local_58._4_4_ >> 4) & 0xffffffff00000003;
    uVar5 = local_58._4_4_ >> 6 & 1;
    uVar11 = local_58._4_4_ >> 4 & 3;
LAB_140003e17:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140003e45;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140003e17;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140003e45:
  uVar6 = -(uint)bVar2 & uVar11 & 3;
  if (uVar6 == 0) {
    uVar9 = -(uint)(*(char *)(param_3 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar9 = 0;
    if (uVar11 == 2) {
      uVar9 = 0x40;
    }
  }
  uVar11 = uVar9 >> 6 ^ (uVar9 | uVar6 << 7 | uVar8 | uVar5);
  if ((uVar9 != 0) && (plVar10 = *(longlong **)(param_3 + 0x20), plVar10 != (longlong *)0x0)) {
    do {
      puVar1 = (undefined8 *)*plVar10;
      if (puVar1 == (undefined8 *)0x0) break;
      if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar1 + 0x1d) == '\0')) {
        uVar8 = *(uint *)*puVar1;
        local_80 = (ulonglong)uVar8;
        if ((uVar8 & 2) == 0) {
          uVar7 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar1,local_80,(longlong)puVar1);
          uVar8 = (uint)uVar7;
        }
        uVar5 = uVar11 & 0xfffffffe;
        uVar11 = (uint)((uVar8 & uVar11 & 1) != 0);
      }
      else {
        if (((uVar11 & 1) == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        uVar11 = uVar11 & 0xfffffffe;
      }
      uVar11 = uVar11 | uVar5;
      plVar10 = plVar10 + 1;
    } while ((uVar11 & 1) != 0);
  }
  bVar12 = *(char *)(param_3 + 0x1c) == '\0';
  uVar7 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar7;
    local_88 = CONCAT44(local_88._4_4_,uVar5);
    if ((!bVar12 || iVar3 != 0) && (local_88 = CONCAT44(local_88._4_4_,uVar5), (uVar7 & 2) == 0)) {
      uVar8 = (uVar11 ^ uVar5) & 0x9c1 ^ uVar5;
      uVar5 = uVar8 | 2;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar8 = (uVar5 ^ uVar11) & 0x400 ^ uVar5;
      uVar5 = uVar8 | 4;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 4;
    }
    uVar7 = param_2 & 0xffffffff;
    LOCK();
    uVar8 = *param_1;
    bVar13 = (uint)param_2 == uVar8;
    if (bVar13) {
      *param_1 = uVar5;
    }
    else {
      uVar7 = (ulonglong)uVar8;
    }
    UNLOCK();
    if (bVar13) break;
    param_2 = uVar7;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (bVar12 && iVar3 == 0) {
    local_88 = CONCAT44(local_88._4_4_,(uVar11 ^ uVar5) & 0x9c1 ^ uVar5);
  }
  return local_88;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140003fd0 =====

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
  if ((Feature_56664216__private_featureState & 2) != 0) {
    uVar1 = Feature_56664216__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_56664216__private_featureState;
      if (bVar3) {
        Feature_56664216__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_56664216__private_featureState;
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



===== wil_details_IsEnabledFallback @ 140004024 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_56664216__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_56664216__private_featureState,(ulonglong)param_1,0x140014700)
    ;
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



===== BthEnumInternalIoctl @ 1400040c0 =====

ulonglong BthEnumInternalIoctl(longlong param_1,longlong param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  bool bVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  int *piVar11;
  longlong lVar12;
  undefined8 uVar13;
  
  piVar3 = *(int **)(param_1 + 0x40);
  uVar8 = 0;
  lVar12 = *(longlong *)(param_2 + 0xb8);
  bVar7 = false;
  if (*piVar3 == 0x204f4446) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = lVar12 + 0x48;
    uVar9 = IofCallDriver(*(undefined8 *)(piVar3 + 6),param_2);
    return uVar9;
  }
  iVar2 = *(int *)(lVar12 + 0x18);
  lVar4 = *(longlong *)(*(longlong *)(piVar3 + 2) + 0x40);
  if (iVar2 == 0x410003) {
    if ((*(longlong *)(lVar12 + 8) != 0) &&
       (((((sVar1 = *(short *)(*(longlong *)(lVar12 + 8) + 0x16), sVar1 == 0x102 || (sVar1 == 0x103)
           ) || (sVar1 == 0x202)) || ((sVar1 == 0x203 || (sVar1 == 0x210)))) ||
        ((sVar1 == 0x211 || ((sVar1 == 0x212 || (sVar1 == 0x213)))))))) {
      if (*(char *)(param_2 + 0x43) < *(char *)(param_1 + 0x4c)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_ddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_Dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        puVar5 = *(undefined8 **)(param_2 + 0xb8);
        bVar7 = true;
        puVar5[-9] = *puVar5;
        puVar5[-8] = puVar5[1];
        puVar5[-7] = puVar5[2];
        puVar5[-6] = puVar5[3];
        puVar5[-5] = puVar5[4];
        puVar5[-4] = puVar5[5];
        puVar5[-3] = puVar5[6];
        *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
        lVar12 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar12 + -0x10) = IoCompletionForOpenChannelSuccess;
        *(int **)(lVar12 + -8) = piVar3;
        *(undefined1 *)(lVar12 + -0x45) = 0xc0;
      }
    }
LAB_14000430f:
    if (!bVar7) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    }
    uVar8 = IofCallDriver(*(undefined8 *)(lVar4 + 0x18),param_2);
  }
  else {
    if (iVar2 == 0x410007) {
      uVar13 = 0x730;
      if (*(uint *)(lVar12 + 8) < 0x730) {
LAB_140004155:
        uVar13 = 0;
        uVar8 = 0xc0000206;
      }
      else {
        memmove(*(void **)(param_2 + 0x70),piVar3 + 0x104,0x730);
      }
    }
    else {
      if (iVar2 != 0x41000b) goto LAB_14000430f;
      uVar13 = 0x110;
      if (*(uint *)(lVar12 + 8) < 0x110) goto LAB_140004155;
      lVar12 = 2;
      puVar5 = *(undefined8 **)(param_2 + 0x70);
      piVar3 = piVar3 + 0x2e;
      do {
        piVar11 = piVar3;
        puVar10 = puVar5;
        uVar6 = *(undefined8 *)(piVar11 + 2);
        *puVar10 = *(undefined8 *)piVar11;
        puVar10[1] = uVar6;
        uVar6 = *(undefined8 *)(piVar11 + 6);
        puVar10[2] = *(undefined8 *)(piVar11 + 4);
        puVar10[3] = uVar6;
        uVar6 = *(undefined8 *)(piVar11 + 10);
        puVar10[4] = *(undefined8 *)(piVar11 + 8);
        puVar10[5] = uVar6;
        uVar6 = *(undefined8 *)(piVar11 + 0xe);
        puVar10[6] = *(undefined8 *)(piVar11 + 0xc);
        puVar10[7] = uVar6;
        uVar6 = *(undefined8 *)(piVar11 + 0x12);
        puVar10[8] = *(undefined8 *)(piVar11 + 0x10);
        puVar10[9] = uVar6;
        uVar6 = *(undefined8 *)(piVar11 + 0x16);
        puVar10[10] = *(undefined8 *)(piVar11 + 0x14);
        puVar10[0xb] = uVar6;
        uVar6 = *(undefined8 *)(piVar11 + 0x1a);
        puVar10[0xc] = *(undefined8 *)(piVar11 + 0x18);
        puVar10[0xd] = uVar6;
        uVar6 = *(undefined8 *)(piVar11 + 0x1e);
        puVar10[0xe] = *(undefined8 *)(piVar11 + 0x1c);
        puVar10[0xf] = uVar6;
        lVar12 = lVar12 + -1;
        puVar5 = puVar10 + 0x10;
        piVar3 = piVar11 + 0x20;
      } while (lVar12 != 0);
      uVar6 = *(undefined8 *)(piVar11 + 0x22);
      puVar10[0x10] = *(undefined8 *)(piVar11 + 0x20);
      puVar10[0x11] = uVar6;
    }
    *(undefined8 *)(param_2 + 0x38) = uVar13;
    *(uint *)(param_2 + 0x30) = uVar8;
    IofCompleteRequest(param_2,0);
  }
  return (ulonglong)uVar8;
}



===== WPP_RECORDER_SF_Dddd @ 140004358 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_675adacc7e0537ac2eb578ed1b7b59a6_Traceguids,10,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,0,2,&WPP_675adacc7e0537ac2eb578ed1b7b59a6_Traceguids,10,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_ddD @ 14000445c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_675adacc7e0537ac2eb578ed1b7b59a6_Traceguids,0xb,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,0,1,&WPP_675adacc7e0537ac2eb578ed1b7b59a6_Traceguids,0xb,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== IrpList_DequeueIrpLocked @ 140004540 =====

bool IrpList_DequeueIrpLocked(undefined8 *param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined1 uVar6;
  bool bVar7;
  
  plVar2 = (longlong *)*param_1;
  do {
    plVar5 = plVar2;
    if (plVar5 == param_1) {
      return false;
    }
    plVar2 = (longlong *)*plVar5;
  } while (plVar5 + -0x15 != param_2);
  if (((longlong *)plVar2[1] != plVar5) ||
     (plVar3 = (longlong *)plVar5[1], (longlong *)*plVar3 != plVar5)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    uVar6 = (*pcVar4)();
    return (bool)uVar6;
  }
  *plVar3 = (longlong)plVar2;
  plVar2[1] = (longlong)plVar3;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  LOCK();
  lVar1 = plVar5[-8];
  plVar5[-8] = 0;
  UNLOCK();
  bVar7 = lVar1 != 0;
  if (bVar7) {
    plVar5[-3] = 0;
  }
  plVar5[1] = (longlong)plVar5;
  *plVar5 = (longlong)plVar5;
  return bVar7;
}



===== IrpList_EnqueueLocked @ 1400045ac =====

undefined8 IrpList_EnqueueLocked(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  *(longlong *)(param_2 + 0x90) = param_1;
  LOCK();
  *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(param_1 + 0x28);
  UNLOCK();
  if (*(char *)(param_2 + 0x44) == '\0') {
    plVar4 = *(longlong **)(param_1 + 8);
    plVar5 = (longlong *)(param_2 + 0xa8);
    if (*plVar4 != param_1) {
      param_1 = 3;
      pcVar3 = (code *)swi(0x29);
      plVar4 = (longlong *)(*pcVar3)();
    }
    *plVar5 = param_1;
    plVar5[1] = (longlong)plVar4;
    *plVar4 = (longlong)plVar5;
    *(longlong **)(param_1 + 8) = plVar5;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  else {
    LOCK();
    lVar2 = *(longlong *)(param_2 + 0x68);
    *(longlong *)(param_2 + 0x68) = 0;
    UNLOCK();
    if (lVar2 != 0) {
      *(undefined8 *)(param_2 + 0x90) = 0;
      return 0xc0000120;
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    lVar2 = param_2 + 0xa8;
    *(longlong *)(param_2 + 0xb0) = lVar2;
    *(longlong *)lVar2 = lVar2;
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  *(undefined4 *)(param_2 + 0x30) = 0x103;
  return 0x103;
}



===== IrpList_InitEx @ 140004634 =====

void IrpList_InitEx(longlong param_1,undefined8 param_2)

{
  *(longlong *)(param_1 + 8) = param_1;
  *(longlong *)param_1 = param_1;
  KeInitializeSpinLock(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(code **)(param_1 + 0x28) = BthEnumWaitWakeCancelRoutine;
  return;
}



===== BthLib_Unload @ 140004688 =====

void BthLib_Unload(void)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  code *pcVar3;
  undefined1 uVar4;
  bool bVar5;
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&BthLib_RefObjGlobals);
  while (pppplVar2 = DAT_1400152e8, (longlong *****)DAT_1400152e8 != &DAT_1400152e8) {
    if ((((longlong *****)DAT_1400152e8[1] != &DAT_1400152e8) ||
        (pppplVar1 = (longlong ****)*DAT_1400152e8, (longlong ****)pppplVar1[1] != DAT_1400152e8))
       || (DAT_1400152e8 = pppplVar1, pppplVar1[1] = (longlong ***)&DAT_1400152e8,
          (longlong *****)*local_10 != &local_18)) goto LAB_140004765;
    pppplVar2[1] = (longlong ***)local_10;
    *pppplVar2 = (longlong ***)&local_18;
    *local_10 = (longlong ***)pppplVar2;
    local_10 = pppplVar2;
  }
  KeReleaseSpinLock(&BthLib_RefObjGlobals,uVar4);
  while( true ) {
    if ((longlong *****)local_18 == &local_18) {
      return;
    }
    if (((longlong *****)local_18[1] != &local_18) ||
       (pppplVar2 = (longlong ****)*local_18, (longlong ****)pppplVar2[1] != local_18)) break;
    pppplVar2[1] = (longlong ***)&local_18;
    bVar5 = local_18 != (longlong ****)0x408;
    local_18 = pppplVar2;
    if (bVar5) {
      ExFreePool();
    }
  }
LAB_140004765:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== NtStatusTxt @ 14000477c =====

char * NtStatusTxt(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  bool bVar3;
  
  if (param_1 < -0x7ffffd77) {
    if (param_1 == -0x7ffffd78) {
      return "STATUS_DEVICE_REQUIRES_CLEANING";
    }
    switch(param_1) {
    case -0x7fffffff:
      return "STATUS_GUARD_PAGE_VIOLATION";
    case -0x7ffffffe:
      return "STATUS_DATATYPE_MISALIGNMENT";
    case -0x7ffffffd:
      return "STATUS_BREAKPOINT";
    case -0x7ffffffc:
      return "STATUS_SINGLE_STEP";
    case -0x7ffffffb:
      return "STATUS_BUFFER_OVERFLOW";
    case -0x7ffffffa:
      return "STATUS_NO_MORE_FILES";
    case -0x7ffffff9:
      return "STATUS_WAKE_SYSTEM_DEBUGGER";
    case -0x7ffffff6:
      return "STATUS_HANDLES_CLOSED";
    case -0x7ffffff5:
      return "STATUS_NO_INHERITANCE";
    case -0x7ffffff4:
      return "STATUS_GUID_SUBSTITUTION_MADE";
    case -0x7ffffff3:
      return "STATUS_PARTIAL_COPY";
    case -0x7ffffff2:
      return "STATUS_DEVICE_PAPER_EMPTY";
    case -0x7ffffff1:
      return "STATUS_DEVICE_POWERED_OFF";
    case -0x7ffffff0:
      return "STATUS_DEVICE_OFF_LINE";
    case -0x7fffffef:
      return "STATUS_DEVICE_BUSY";
    case -0x7fffffee:
      return "STATUS_NO_MORE_EAS";
    case -0x7fffffed:
      return "STATUS_INVALID_EA_NAME";
    case -0x7fffffec:
      return "STATUS_EA_LIST_INCONSISTENT";
    case -0x7fffffeb:
      return "STATUS_INVALID_EA_FLAG";
    case -0x7fffffea:
      return "STATUS_VERIFY_REQUIRED";
    case -0x7fffffe9:
      return "STATUS_EXTRANEOUS_INFORMATION";
    case -0x7fffffe8:
      return "STATUS_RXACT_COMMIT_NECESSARY";
    case -0x7fffffe6:
      return "STATUS_NO_MORE_ENTRIES";
    case -0x7fffffe5:
      return "STATUS_FILEMARK_DETECTED";
    case -0x7fffffe4:
      return "STATUS_MEDIA_CHANGED";
    case -0x7fffffe3:
      return "STATUS_BUS_RESET";
    case -0x7fffffe2:
      return "STATUS_END_OF_MEDIA";
    case -0x7fffffe1:
      return "STATUS_BEGINNING_OF_MEDIA";
    case -0x7fffffe0:
      return "STATUS_MEDIA_CHECK";
    case -0x7fffffdf:
      return "STATUS_SETMARK_DETECTED";
    case -0x7fffffde:
      return "STATUS_NO_DATA_DETECTED";
    case -0x7fffffdd:
      return "STATUS_REDIRECTOR_HAS_OPEN_HANDLES";
    case -0x7fffffdc:
      return "STATUS_SERVER_HAS_OPEN_HANDLES";
    case -0x7fffffdb:
      return "STATUS_ALREADY_DISCONNECTED";
    case -0x7fffffda:
      return "STATUS_LONGJUMP";
    case -0x7fffffd9:
      return "STATUS_CLEANER_CARTRIDGE_INSTALLED";
    case -0x7fffffd8:
      return "STATUS_PLUGPLAY_QUERY_VETOED";
    case -0x7fffffd7:
      return "STATUS_UNWIND_CONSOLIDATE";
    case -0x7fffffd6:
      return "STATUS_REGISTRY_HIVE_RECOVERED";
    }
  }
  else if (param_1 < -0x3ffffdd4) {
    if (param_1 == -0x3ffffdd5) {
      return "STATUS_OBJECTID_EXISTS";
    }
    if (param_1 < -0x3fffff20) {
      if (param_1 == -0x3fffff21) {
        return "STATUS_NO_SUCH_DOMAIN";
      }
      if (param_1 < -0x3fffff92) {
        if (param_1 == -0x3fffff93) {
          return "STATUS_LOGON_FAILURE";
        }
        if (param_1 < -0x3fffffcc) {
          if (param_1 == -0x3fffffcd) {
            return "STATUS_OBJECT_NAME_INVALID";
          }
          if (param_1 < -0x3fffffe8) {
            if (param_1 == -0x3fffffe9) {
              return "STATUS_NO_MEMORY";
            }
            if (param_1 < -0x3ffffff6) {
              if (param_1 == -0x3ffffff7) {
                return "STATUS_BAD_INITIAL_STACK";
              }
              if (param_1 < -0x3ffffffd) {
                if (param_1 == -0x3ffffffe) {
                  return "STATUS_NOT_IMPLEMENTED";
                }
                if (param_1 == -0x7ffffd77) {
                  return "STATUS_DEVICE_DOOR_OPEN";
                }
                if (param_1 == -0x7fecffff) {
                  return "STATUS_CLUSTER_NODE_ALREADY_UP";
                }
                if (param_1 == -0x7fecfffe) {
                  return "STATUS_CLUSTER_NODE_ALREADY_DOWN";
                }
                if (param_1 == -0x7fecfffd) {
                  return "STATUS_CLUSTER_NETWORK_ALREADY_ONLINE";
                }
                if (param_1 == -0x7fecfffc) {
                  return "STATUS_CLUSTER_NETWORK_ALREADY_OFFLINE";
                }
                if (param_1 == -0x7fecfffb) {
                  return "STATUS_CLUSTER_NODE_ALREADY_MEMBER";
                }
                pcVar2 = "STATUS_UNSUCCESSFUL";
                bVar3 = param_1 == -0x3fffffff;
              }
              else {
                if (param_1 == -0x3ffffffd) {
                  return "STATUS_INVALID_INFO_CLASS";
                }
                if (param_1 == -0x3ffffffc) {
                  return "STATUS_INFO_LENGTH_MISMATCH";
                }
                if (param_1 == -0x3ffffffb) {
                  return "STATUS_ACCESS_VIOLATION";
                }
                if (param_1 == -0x3ffffffa) {
                  return "STATUS_IN_PAGE_ERROR";
                }
                if (param_1 == -0x3ffffff9) {
                  return "STATUS_PAGEFILE_QUOTA";
                }
                pcVar2 = "STATUS_INVALID_HANDLE";
                bVar3 = param_1 == -0x3ffffff8;
              }
              goto LAB_140006a7c;
            }
            switch(param_1) {
            case -0x3ffffff6:
              return "STATUS_BAD_INITIAL_PC";
            case -0x3ffffff5:
              return "STATUS_INVALID_CID";
            case -0x3ffffff4:
              return "STATUS_TIMER_NOT_CANCELED";
            case -0x3ffffff3:
              return "STATUS_INVALID_PARAMETER";
            case -0x3ffffff2:
              return "STATUS_NO_SUCH_DEVICE";
            case -0x3ffffff1:
              return "STATUS_NO_SUCH_FILE";
            case -0x3ffffff0:
              return "STATUS_INVALID_DEVICE_REQUEST";
            case -0x3fffffef:
              return "STATUS_END_OF_FILE";
            case -0x3fffffee:
              return "STATUS_WRONG_VOLUME";
            case -0x3fffffed:
              return "STATUS_NO_MEDIA_IN_DEVICE";
            case -0x3fffffec:
              return "STATUS_UNRECOGNIZED_MEDIA";
            case -0x3fffffeb:
              return "STATUS_NONEXISTENT_SECTOR";
            case -0x3fffffea:
              return "STATUS_MORE_PROCESSING_REQUIRED";
            }
          }
          else {
            switch(param_1) {
            case -0x3fffffe8:
              return "STATUS_CONFLICTING_ADDRESSES";
            case -0x3fffffe7:
              return "STATUS_NOT_MAPPED_VIEW";
            case -0x3fffffe6:
              return "STATUS_UNABLE_TO_FREE_VM";
            case -0x3fffffe5:
              return "STATUS_UNABLE_TO_DELETE_SECTION";
            case -0x3fffffe4:
              return "STATUS_INVALID_SYSTEM_SERVICE";
            case -0x3fffffe3:
              return "STATUS_ILLEGAL_INSTRUCTION";
            case -0x3fffffe2:
              return "STATUS_INVALID_LOCK_SEQUENCE";
            case -0x3fffffe1:
              return "STATUS_INVALID_VIEW_SIZE";
            case -0x3fffffe0:
              return "STATUS_INVALID_FILE_FOR_SECTION";
            case -0x3fffffdf:
              return "STATUS_ALREADY_COMMITTED";
            case -0x3fffffde:
              return "STATUS_ACCESS_DENIED";
            case -0x3fffffdd:
              return "STATUS_BUFFER_TOO_SMALL";
            case -0x3fffffdc:
              return "STATUS_OBJECT_TYPE_MISMATCH";
            case -0x3fffffdb:
              return "STATUS_NONCONTINUABLE_EXCEPTION";
            case -0x3fffffda:
              return "STATUS_INVALID_DISPOSITION";
            case -0x3fffffd9:
              return "STATUS_UNWIND";
            case -0x3fffffd8:
              return "STATUS_BAD_STACK";
            case -0x3fffffd7:
              return "STATUS_INVALID_UNWIND_TARGET";
            case -0x3fffffd6:
              return "STATUS_NOT_LOCKED";
            case -0x3fffffd5:
              return "STATUS_PARITY_ERROR";
            case -0x3fffffd4:
              return "STATUS_UNABLE_TO_DECOMMIT_VM";
            case -0x3fffffd3:
              return "STATUS_NOT_COMMITTED";
            case -0x3fffffd2:
              return "STATUS_INVALID_PORT_ATTRIBUTES";
            case -0x3fffffd1:
              return "STATUS_PORT_MESSAGE_TOO_LONG";
            case -0x3fffffd0:
              return "STATUS_INVALID_PARAMETER_MIX";
            case -0x3fffffcf:
              return "STATUS_INVALID_QUOTA_LOWER";
            case -0x3fffffce:
              return "STATUS_DISK_CORRUPT_ERROR";
            }
          }
        }
        else {
          switch(param_1) {
          case -0x3fffffcc:
            return "STATUS_OBJECT_NAME_NOT_FOUND";
          case -0x3fffffcb:
            return "STATUS_OBJECT_NAME_COLLISION";
          case -0x3fffffc9:
            return "STATUS_PORT_DISCONNECTED";
          case -0x3fffffc8:
            return "STATUS_DEVICE_ALREADY_ATTACHED";
          case -0x3fffffc7:
            return "STATUS_OBJECT_PATH_INVALID";
          case -0x3fffffc6:
            return "STATUS_OBJECT_PATH_NOT_FOUND";
          case -0x3fffffc5:
            return "STATUS_OBJECT_PATH_SYNTAX_BAD";
          case -0x3fffffc4:
            return "STATUS_DATA_OVERRUN";
          case -0x3fffffc3:
            return "STATUS_DATA_LATE_ERROR";
          case -0x3fffffc2:
            return "STATUS_DATA_ERROR";
          case -0x3fffffc1:
            return "STATUS_CRC_ERROR";
          case -0x3fffffc0:
            return "STATUS_SECTION_TOO_BIG";
          case -0x3fffffbf:
            return "STATUS_PORT_CONNECTION_REFUSED";
          case -0x3fffffbe:
            return "STATUS_INVALID_PORT_HANDLE";
          case -0x3fffffbd:
            return "STATUS_SHARING_VIOLATION";
          case -0x3fffffbc:
            return "STATUS_QUOTA_EXCEEDED";
          case -0x3fffffbb:
            return "STATUS_INVALID_PAGE_PROTECTION";
          case -0x3fffffba:
            return "STATUS_MUTANT_NOT_OWNED";
          case -0x3fffffb9:
            return "STATUS_SEMAPHORE_LIMIT_EXCEEDED";
          case -0x3fffffb8:
            return "STATUS_PORT_ALREADY_SET";
          case -0x3fffffb7:
            return "STATUS_SECTION_NOT_IMAGE";
          case -0x3fffffb6:
            return "STATUS_SUSPEND_COUNT_EXCEEDED";
          case -0x3fffffb5:
            return "STATUS_THREAD_IS_TERMINATING";
          case -0x3fffffb4:
            return "STATUS_BAD_WORKING_SET_LIMIT";
          case -0x3fffffb3:
            return "STATUS_INCOMPATIBLE_FILE_MAP";
          case -0x3fffffb2:
            return "STATUS_SECTION_PROTECTION";
          case -0x3fffffb1:
            return "STATUS_EAS_NOT_SUPPORTED";
          case -0x3fffffb0:
            return "STATUS_EA_TOO_LARGE";
          case -0x3fffffaf:
            return "STATUS_NONEXISTENT_EA_ENTRY";
          case -0x3fffffae:
            return "STATUS_NO_EAS_ON_FILE";
          case -0x3fffffad:
            return "STATUS_EA_CORRUPT_ERROR";
          case -0x3fffffac:
            return "STATUS_FILE_LOCK_CONFLICT";
          case -0x3fffffab:
            return "STATUS_LOCK_NOT_GRANTED";
          case -0x3fffffaa:
            return "STATUS_DELETE_PENDING";
          case -0x3fffffa9:
            return "STATUS_CTL_FILE_NOT_SUPPORTED";
          case -0x3fffffa8:
            return "STATUS_UNKNOWN_REVISION";
          case -0x3fffffa7:
            return "STATUS_REVISION_MISMATCH";
          case -0x3fffffa6:
            return "STATUS_INVALID_OWNER";
          case -0x3fffffa5:
            return "STATUS_INVALID_PRIMARY_GROUP";
          case -0x3fffffa4:
            return "STATUS_NO_IMPERSONATION_TOKEN";
          case -0x3fffffa3:
            return "STATUS_CANT_DISABLE_MANDATORY";
          case -0x3fffffa2:
            return "STATUS_NO_LOGON_SERVERS";
          case -0x3fffffa1:
            return "STATUS_NO_SUCH_LOGON_SESSION";
          case -0x3fffffa0:
            return "STATUS_NO_SUCH_PRIVILEGE";
          case -0x3fffff9f:
            return "STATUS_PRIVILEGE_NOT_HELD";
          case -0x3fffff9e:
            return "STATUS_INVALID_ACCOUNT_NAME";
          case -0x3fffff9d:
            return "STATUS_USER_EXISTS";
          case -0x3fffff9c:
            return "STATUS_NO_SUCH_USER";
          case -0x3fffff9b:
            return "STATUS_GROUP_EXISTS";
          case -0x3fffff9a:
            return "STATUS_NO_SUCH_GROUP";
          case -0x3fffff99:
            return "STATUS_MEMBER_IN_GROUP";
          case -0x3fffff98:
            return "STATUS_MEMBER_NOT_IN_GROUP";
          case -0x3fffff97:
            return "STATUS_LAST_ADMIN";
          case -0x3fffff96:
            return "STATUS_WRONG_PASSWORD";
          case -0x3fffff95:
            return "STATUS_ILL_FORMED_PASSWORD";
          case -0x3fffff94:
            return "STATUS_PASSWORD_RESTRICTION";
          }
        }
      }
      else {
        switch(param_1) {
        case -0x3fffff92:
          return "STATUS_ACCOUNT_RESTRICTION";
        case -0x3fffff91:
          return "STATUS_INVALID_LOGON_HOURS";
        case -0x3fffff90:
          return "STATUS_INVALID_WORKSTATION";
        case -0x3fffff8f:
          return "STATUS_PASSWORD_EXPIRED";
        case -0x3fffff8e:
          return "STATUS_ACCOUNT_DISABLED";
        case -0x3fffff8d:
          return "STATUS_NONE_MAPPED";
        case -0x3fffff8c:
          return "STATUS_TOO_MANY_LUIDS_REQUESTED";
        case -0x3fffff8b:
          return "STATUS_LUIDS_EXHAUSTED";
        case -0x3fffff8a:
          return "STATUS_INVALID_SUB_AUTHORITY";
        case -0x3fffff89:
          return "STATUS_INVALID_ACL";
        case -0x3fffff88:
          return "STATUS_INVALID_SID";
        case -0x3fffff87:
          return "STATUS_INVALID_SECURITY_DESCR";
        case -0x3fffff86:
          return "STATUS_PROCEDURE_NOT_FOUND";
        case -0x3fffff85:
          return "STATUS_INVALID_IMAGE_FORMAT";
        case -0x3fffff84:
          return "STATUS_NO_TOKEN";
        case -0x3fffff83:
          return "STATUS_BAD_INHERITANCE_ACL";
        case -0x3fffff82:
          return "STATUS_RANGE_NOT_LOCKED";
        case -0x3fffff81:
          return "STATUS_DISK_FULL";
        case -0x3fffff80:
          return "STATUS_SERVER_DISABLED";
        case -0x3fffff7f:
          return "STATUS_SERVER_NOT_DISABLED";
        case -0x3fffff7e:
          return "STATUS_TOO_MANY_GUIDS_REQUESTED";
        case -0x3fffff7d:
          return "STATUS_GUIDS_EXHAUSTED";
        case -0x3fffff7c:
          return "STATUS_INVALID_ID_AUTHORITY";
        case -0x3fffff7b:
          return "STATUS_AGENTS_EXHAUSTED";
        case -0x3fffff7a:
          return "STATUS_INVALID_VOLUME_LABEL";
        case -0x3fffff79:
          return "STATUS_SECTION_NOT_EXTENDED";
        case -0x3fffff78:
          return "STATUS_NOT_MAPPED_DATA";
        case -0x3fffff77:
          return "STATUS_RESOURCE_DATA_NOT_FOUND";
        case -0x3fffff76:
          return "STATUS_RESOURCE_TYPE_NOT_FOUND";
        case -0x3fffff75:
          return "STATUS_RESOURCE_NAME_NOT_FOUND";
        case -0x3fffff74:
          return "STATUS_ARRAY_BOUNDS_EXCEEDED";
        case -0x3fffff73:
          return "STATUS_FLOAT_DENORMAL_OPERAND";
        case -0x3fffff72:
          return "STATUS_FLOAT_DIVIDE_BY_ZERO";
        case -0x3fffff71:
          return "STATUS_FLOAT_INEXACT_RESULT";
        case -0x3fffff70:
          return "STATUS_FLOAT_INVALID_OPERATION";
        case -0x3fffff6f:
          return "STATUS_FLOAT_OVERFLOW";
        case -0x3fffff6e:
          return "STATUS_FLOAT_STACK_CHECK";
        case -0x3fffff6d:
          return "STATUS_FLOAT_UNDERFLOW";
        case -0x3fffff6c:
          return "STATUS_INTEGER_DIVIDE_BY_ZERO";
        case -0x3fffff6b:
          return "STATUS_INTEGER_OVERFLOW";
        case -0x3fffff6a:
          return "STATUS_PRIVILEGED_INSTRUCTION";
        case -0x3fffff69:
          return "STATUS_TOO_MANY_PAGING_FILES";
        case -0x3fffff68:
          return "STATUS_FILE_INVALID";
        case -0x3fffff67:
          return "STATUS_ALLOTTED_SPACE_EXCEEDED";
        case -0x3fffff66:
          return "STATUS_INSUFFICIENT_RESOURCES";
        case -0x3fffff65:
          return "STATUS_DFS_EXIT_PATH_FOUND";
        case -0x3fffff64:
          return "STATUS_DEVICE_DATA_ERROR";
        case -0x3fffff63:
          return "STATUS_DEVICE_NOT_CONNECTED";
        case -0x3fffff62:
          return "STATUS_DEVICE_POWER_FAILURE";
        case -0x3fffff61:
          return "STATUS_FREE_VM_NOT_AT_BASE";
        case -0x3fffff60:
          return "STATUS_MEMORY_NOT_ALLOCATED";
        case -0x3fffff5f:
          return "STATUS_WORKING_SET_QUOTA";
        case -0x3fffff5e:
          return "STATUS_MEDIA_WRITE_PROTECTED";
        case -0x3fffff5d:
          return "STATUS_DEVICE_NOT_READY";
        case -0x3fffff5c:
          return "STATUS_INVALID_GROUP_ATTRIBUTES";
        case -0x3fffff5b:
          return "STATUS_BAD_IMPERSONATION_LEVEL";
        case -0x3fffff5a:
          return "STATUS_CANT_OPEN_ANONYMOUS";
        case -0x3fffff59:
          return "STATUS_BAD_VALIDATION_CLASS";
        case -0x3fffff58:
          return "STATUS_BAD_TOKEN_TYPE";
        case -0x3fffff57:
          return "STATUS_BAD_MASTER_BOOT_RECORD";
        case -0x3fffff56:
          return "STATUS_INSTRUCTION_MISALIGNMENT";
        case -0x3fffff55:
          return "STATUS_INSTANCE_NOT_AVAILABLE";
        case -0x3fffff54:
          return "STATUS_PIPE_NOT_AVAILABLE";
        case -0x3fffff53:
          return "STATUS_INVALID_PIPE_STATE";
        case -0x3fffff52:
          return "STATUS_PIPE_BUSY";
        case -0x3fffff51:
          return "STATUS_ILLEGAL_FUNCTION";
        case -0x3fffff50:
          return "STATUS_PIPE_DISCONNECTED";
        case -0x3fffff4f:
          return "STATUS_PIPE_CLOSING";
        case -0x3fffff4e:
          return "STATUS_PIPE_CONNECTED";
        case -0x3fffff4d:
          return "STATUS_PIPE_LISTENING";
        case -0x3fffff4c:
          return "STATUS_INVALID_READ_MODE";
        case -0x3fffff4b:
          return "STATUS_IO_TIMEOUT";
        case -0x3fffff4a:
          return "STATUS_FILE_FORCED_CLOSED";
        case -0x3fffff49:
          return "STATUS_PROFILING_NOT_STARTED";
        case -0x3fffff48:
          return "STATUS_PROFILING_NOT_STOPPED";
        case -0x3fffff47:
          return "STATUS_COULD_NOT_INTERPRET";
        case -0x3fffff46:
          return "STATUS_FILE_IS_A_DIRECTORY";
        case -0x3fffff45:
          return "STATUS_NOT_SUPPORTED";
        case -0x3fffff44:
          return "STATUS_REMOTE_NOT_LISTENING";
        case -0x3fffff43:
          return "STATUS_DUPLICATE_NAME";
        case -0x3fffff42:
          return "STATUS_BAD_NETWORK_PATH";
        case -0x3fffff41:
          return "STATUS_NETWORK_BUSY";
        case -0x3fffff40:
          return "STATUS_DEVICE_DOES_NOT_EXIST";
        case -0x3fffff3f:
          return "STATUS_TOO_MANY_COMMANDS";
        case -0x3fffff3e:
          return "STATUS_ADAPTER_HARDWARE_ERROR";
        case -0x3fffff3d:
          return "STATUS_INVALID_NETWORK_RESPONSE";
        case -0x3fffff3c:
          return "STATUS_UNEXPECTED_NETWORK_ERROR";
        case -0x3fffff3b:
          return "STATUS_BAD_REMOTE_ADAPTER";
        case -0x3fffff3a:
          return "STATUS_PRINT_QUEUE_FULL";
        case -0x3fffff39:
          return "STATUS_NO_SPOOL_SPACE";
        case -0x3fffff38:
          return "STATUS_PRINT_CANCELLED";
        case -0x3fffff37:
          return "STATUS_NETWORK_NAME_DELETED";
        case -0x3fffff36:
          return "STATUS_NETWORK_ACCESS_DENIED";
        case -0x3fffff35:
          return "STATUS_BAD_DEVICE_TYPE";
        case -0x3fffff34:
          return "STATUS_BAD_NETWORK_NAME";
        case -0x3fffff33:
          return "STATUS_TOO_MANY_NAMES";
        case -0x3fffff32:
          return "STATUS_TOO_MANY_SESSIONS";
        case -0x3fffff31:
          return "STATUS_SHARING_PAUSED";
        case -0x3fffff30:
          return "STATUS_REQUEST_NOT_ACCEPTED";
        case -0x3fffff2f:
          return "STATUS_REDIRECTOR_PAUSED";
        case -0x3fffff2e:
          return "STATUS_NET_WRITE_FAULT";
        case -0x3fffff2d:
          return "STATUS_PROFILING_AT_LIMIT";
        case -0x3fffff2c:
          return "STATUS_NOT_SAME_DEVICE";
        case -0x3fffff2b:
          return "STATUS_FILE_RENAMED";
        case -0x3fffff2a:
          return "STATUS_VIRTUAL_CIRCUIT_CLOSED";
        case -0x3fffff29:
          return "STATUS_NO_SECURITY_ON_OBJECT";
        case -0x3fffff28:
          return "STATUS_CANT_WAIT";
        case -0x3fffff27:
          return "STATUS_PIPE_EMPTY";
        case -0x3fffff26:
          return "STATUS_CANT_ACCESS_DOMAIN_INFO";
        case -0x3fffff25:
          return "STATUS_CANT_TERMINATE_SELF";
        case -0x3fffff24:
          return "STATUS_INVALID_SERVER_STATE";
        case -0x3fffff23:
          return "STATUS_INVALID_DOMAIN_STATE";
        case -0x3fffff22:
          return "STATUS_INVALID_DOMAIN_ROLE";
        }
      }
    }
    else if (param_1 + 0x3fffff20U < 0x14b) {
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch((&DAT_140012fbc)[(int)(param_1 + 0x3fffff20U)]) {
      case 0:
        return "STATUS_DOMAIN_EXISTS";
      case 1:
        return "STATUS_DOMAIN_LIMIT_EXCEEDED";
      case 2:
        return "STATUS_OPLOCK_NOT_GRANTED";
      case 3:
        return "STATUS_INVALID_OPLOCK_PROTOCOL";
      case 4:
        return "STATUS_INTERNAL_DB_CORRUPTION";
      case 5:
        return "STATUS_INTERNAL_ERROR";
      case 6:
        return "STATUS_GENERIC_NOT_MAPPED";
      case 7:
        return "STATUS_BAD_DESCRIPTOR_FORMAT";
      case 8:
        return "STATUS_INVALID_USER_BUFFER";
      case 9:
        return "STATUS_UNEXPECTED_IO_ERROR";
      case 10:
        return "STATUS_UNEXPECTED_MM_CREATE_ERR";
      case 0xb:
        return "STATUS_UNEXPECTED_MM_MAP_ERROR";
      case 0xc:
        return "STATUS_UNEXPECTED_MM_EXTEND_ERR";
      case 0xd:
        return "STATUS_NOT_LOGON_PROCESS";
      case 0xe:
        return "STATUS_LOGON_SESSION_EXISTS";
      case 0xf:
        return "STATUS_INVALID_PARAMETER_1";
      case 0x10:
        return "STATUS_INVALID_PARAMETER_2";
      case 0x11:
        return "STATUS_INVALID_PARAMETER_3";
      case 0x12:
        return "STATUS_INVALID_PARAMETER_4";
      case 0x13:
        return "STATUS_INVALID_PARAMETER_5";
      case 0x14:
        return "STATUS_INVALID_PARAMETER_6";
      case 0x15:
        return "STATUS_INVALID_PARAMETER_7";
      case 0x16:
        return "STATUS_INVALID_PARAMETER_8";
      case 0x17:
        return "STATUS_INVALID_PARAMETER_9";
      case 0x18:
        return "STATUS_INVALID_PARAMETER_10";
      case 0x19:
        return "STATUS_INVALID_PARAMETER_11";
      case 0x1a:
        return "STATUS_INVALID_PARAMETER_12";
      case 0x1b:
        return "STATUS_REDIRECTOR_NOT_STARTED";
      case 0x1c:
        return "STATUS_REDIRECTOR_STARTED";
      case 0x1d:
        return "STATUS_STACK_OVERFLOW";
      case 0x1e:
        return "STATUS_NO_SUCH_PACKAGE";
      case 0x1f:
        return "STATUS_BAD_FUNCTION_TABLE";
      case 0x20:
        return "STATUS_VARIABLE_NOT_FOUND";
      case 0x21:
        return "STATUS_DIRECTORY_NOT_EMPTY";
      case 0x22:
        return "STATUS_FILE_CORRUPT_ERROR";
      case 0x23:
        return "STATUS_NOT_A_DIRECTORY";
      case 0x24:
        return "STATUS_BAD_LOGON_SESSION_STATE";
      case 0x25:
        return "STATUS_LOGON_SESSION_COLLISION";
      case 0x26:
        return "STATUS_NAME_TOO_LONG";
      case 0x27:
        return "STATUS_FILES_OPEN";
      case 0x28:
        return "STATUS_CONNECTION_IN_USE";
      case 0x29:
        return "STATUS_MESSAGE_NOT_FOUND";
      case 0x2a:
        return "STATUS_PROCESS_IS_TERMINATING";
      case 0x2b:
        return "STATUS_INVALID_LOGON_TYPE";
      case 0x2c:
        return "STATUS_NO_GUID_TRANSLATION";
      case 0x2d:
        return "STATUS_CANNOT_IMPERSONATE";
      case 0x2e:
        return "STATUS_IMAGE_ALREADY_LOADED";
      case 0x2f:
        return "STATUS_ABIOS_NOT_PRESENT";
      case 0x30:
        return "STATUS_ABIOS_LID_NOT_EXIST";
      case 0x31:
        return "STATUS_ABIOS_LID_ALREADY_OWNED";
      case 0x32:
        return "STATUS_ABIOS_NOT_LID_OWNER";
      case 0x33:
        return "STATUS_ABIOS_INVALID_COMMAND";
      case 0x34:
        return "STATUS_ABIOS_INVALID_LID";
      case 0x35:
        return "STATUS_ABIOS_SELECTOR_NOT_AVAILABLE";
      case 0x36:
        return "STATUS_ABIOS_INVALID_SELECTOR";
      case 0x37:
        return "STATUS_NO_LDT";
      case 0x38:
        return "STATUS_INVALID_LDT_SIZE";
      case 0x39:
        return "STATUS_INVALID_LDT_OFFSET";
      case 0x3a:
        return "STATUS_INVALID_LDT_DESCRIPTOR";
      case 0x3b:
        return "STATUS_INVALID_IMAGE_NE_FORMAT";
      case 0x3c:
        return "STATUS_RXACT_INVALID_STATE";
      case 0x3d:
        return "STATUS_RXACT_COMMIT_FAILURE";
      case 0x3e:
        return "STATUS_MAPPED_FILE_SIZE_ZERO";
      case 0x3f:
        return "STATUS_TOO_MANY_OPENED_FILES";
      case 0x40:
        return "STATUS_CANCELLED";
      case 0x41:
        return "STATUS_CANNOT_DELETE";
      case 0x42:
        return "STATUS_INVALID_COMPUTER_NAME";
      case 0x43:
        return "STATUS_FILE_DELETED";
      case 0x44:
        return "STATUS_SPECIAL_ACCOUNT";
      case 0x45:
        return "STATUS_SPECIAL_GROUP";
      case 0x46:
        return "STATUS_SPECIAL_USER";
      case 0x47:
        return "STATUS_MEMBERS_PRIMARY_GROUP";
      case 0x48:
        return "STATUS_FILE_CLOSED";
      case 0x49:
        return "STATUS_TOO_MANY_THREADS";
      case 0x4a:
        return "STATUS_THREAD_NOT_IN_PROCESS";
      case 0x4b:
        return "STATUS_TOKEN_ALREADY_IN_USE";
      case 0x4c:
        return "STATUS_PAGEFILE_QUOTA_EXCEEDED";
      case 0x4d:
        return "STATUS_COMMITMENT_LIMIT";
      case 0x4e:
        return "STATUS_INVALID_IMAGE_LE_FORMAT";
      case 0x4f:
        return "STATUS_INVALID_IMAGE_NOT_MZ";
      case 0x50:
        return "STATUS_INVALID_IMAGE_PROTECT";
      case 0x51:
        return "STATUS_INVALID_IMAGE_WIN_16";
      case 0x52:
        return "STATUS_LOGON_SERVER_CONFLICT";
      case 0x53:
        return "STATUS_TIME_DIFFERENCE_AT_DC";
      case 0x54:
        return "STATUS_SYNCHRONIZATION_REQUIRED";
      case 0x55:
        return "STATUS_DLL_NOT_FOUND";
      case 0x56:
        return "STATUS_OPEN_FAILED";
      case 0x57:
        return "STATUS_IO_PRIVILEGE_FAILED";
      case 0x58:
        return "STATUS_ORDINAL_NOT_FOUND";
      case 0x59:
        return "STATUS_ENTRYPOINT_NOT_FOUND";
      case 0x5a:
        return "STATUS_CONTROL_C_EXIT";
      case 0x5b:
        return "STATUS_LOCAL_DISCONNECT";
      case 0x5c:
        return "STATUS_REMOTE_DISCONNECT";
      case 0x5d:
        return "STATUS_REMOTE_RESOURCES";
      case 0x5e:
        return "STATUS_LINK_FAILED";
      case 0x5f:
        return "STATUS_LINK_TIMEOUT";
      case 0x60:
        return "STATUS_INVALID_CONNECTION";
      case 0x61:
        return "STATUS_INVALID_ADDRESS";
      case 0x62:
        return "STATUS_DLL_INIT_FAILED";
      case 99:
        return "STATUS_MISSING_SYSTEMFILE";
      case 100:
        return "STATUS_UNHANDLED_EXCEPTION";
      case 0x65:
        return "STATUS_APP_INIT_FAILURE";
      case 0x66:
        return "STATUS_PAGEFILE_CREATE_FAILED";
      case 0x67:
        return "STATUS_NO_PAGEFILE";
      case 0x68:
        return "STATUS_INVALID_LEVEL";
      case 0x69:
        return "STATUS_WRONG_PASSWORD_CORE";
      case 0x6a:
        return "STATUS_ILLEGAL_FLOAT_CONTEXT";
      case 0x6b:
        return "STATUS_PIPE_BROKEN";
      case 0x6c:
        return "STATUS_REGISTRY_CORRUPT";
      case 0x6d:
        return "STATUS_REGISTRY_IO_FAILED";
      case 0x6e:
        return "STATUS_NO_EVENT_PAIR";
      case 0x6f:
        return "STATUS_UNRECOGNIZED_VOLUME";
      case 0x70:
        return "STATUS_SERIAL_NO_DEVICE_INITED";
      case 0x71:
        return "STATUS_NO_SUCH_ALIAS";
      case 0x72:
        return "STATUS_MEMBER_NOT_IN_ALIAS";
      case 0x73:
        return "STATUS_MEMBER_IN_ALIAS";
      case 0x74:
        return "STATUS_ALIAS_EXISTS";
      case 0x75:
        return "STATUS_LOGON_NOT_GRANTED";
      case 0x76:
        return "STATUS_TOO_MANY_SECRETS";
      case 0x77:
        return "STATUS_SECRET_TOO_LONG";
      case 0x78:
        return "STATUS_INTERNAL_DB_ERROR";
      case 0x79:
        return "STATUS_FULLSCREEN_MODE";
      case 0x7a:
        return "STATUS_TOO_MANY_CONTEXT_IDS";
      case 0x7b:
        return "STATUS_LOGON_TYPE_NOT_GRANTED";
      case 0x7c:
        return "STATUS_NOT_REGISTRY_FILE";
      case 0x7d:
        return "STATUS_NT_CROSS_ENCRYPTION_REQUIRED";
      case 0x7e:
        return "STATUS_DOMAIN_CTRLR_CONFIG_ERROR";
      case 0x7f:
        return "STATUS_FT_MISSING_MEMBER";
      case 0x80:
        return "STATUS_ILL_FORMED_SERVICE_ENTRY";
      case 0x81:
        return "STATUS_ILLEGAL_CHARACTER";
      case 0x82:
        return "STATUS_UNMAPPABLE_CHARACTER";
      case 0x83:
        return "STATUS_UNDEFINED_CHARACTER";
      case 0x84:
        return "STATUS_FLOPPY_VOLUME";
      case 0x85:
        return "STATUS_FLOPPY_ID_MARK_NOT_FOUND";
      case 0x86:
        return "STATUS_FLOPPY_WRONG_CYLINDER";
      case 0x87:
        return "STATUS_FLOPPY_UNKNOWN_ERROR";
      case 0x88:
        return "STATUS_FLOPPY_BAD_REGISTERS";
      case 0x89:
        return "STATUS_DISK_RECALIBRATE_FAILED";
      case 0x8a:
        return "STATUS_DISK_OPERATION_FAILED";
      case 0x8b:
        return "STATUS_DISK_RESET_FAILED";
      case 0x8c:
        return "STATUS_SHARED_IRQ_BUSY";
      case 0x8d:
        return "STATUS_FT_ORPHANING";
      case 0x8e:
        return "STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT";
      case 0x8f:
        return "STATUS_PARTITION_FAILURE";
      case 0x90:
        return "STATUS_INVALID_BLOCK_LENGTH";
      case 0x91:
        return "STATUS_DEVICE_NOT_PARTITIONED";
      case 0x92:
        return "STATUS_UNABLE_TO_LOCK_MEDIA";
      case 0x93:
        return "STATUS_UNABLE_TO_UNLOAD_MEDIA";
      case 0x94:
        return "STATUS_EOM_OVERFLOW";
      case 0x95:
        return "STATUS_NO_MEDIA";
      case 0x96:
        return "STATUS_NO_SUCH_MEMBER";
      case 0x97:
        return "STATUS_INVALID_MEMBER";
      case 0x98:
        return "STATUS_KEY_DELETED";
      case 0x99:
        return "STATUS_NO_LOG_SPACE";
      case 0x9a:
        return "STATUS_TOO_MANY_SIDS";
      case 0x9b:
        return "STATUS_LM_CROSS_ENCRYPTION_REQUIRED";
      case 0x9c:
        return "STATUS_KEY_HAS_CHILDREN";
      case 0x9d:
        return "STATUS_CHILD_MUST_BE_VOLATILE";
      case 0x9e:
        return "STATUS_DEVICE_CONFIGURATION_ERROR";
      case 0x9f:
        return "STATUS_DRIVER_INTERNAL_ERROR";
      case 0xa0:
        return "STATUS_INVALID_DEVICE_STATE";
      case 0xa1:
        return "STATUS_IO_DEVICE_ERROR";
      case 0xa2:
        return "STATUS_DEVICE_PROTOCOL_ERROR";
      case 0xa3:
        return "STATUS_BACKUP_CONTROLLER";
      case 0xa4:
        return "STATUS_LOG_FILE_FULL";
      case 0xa5:
        return "STATUS_TOO_LATE";
      case 0xa6:
        return "STATUS_NO_TRUST_LSA_SECRET";
      case 0xa7:
        return "STATUS_NO_TRUST_SAM_ACCOUNT";
      case 0xa8:
        return "STATUS_TRUSTED_DOMAIN_FAILURE";
      case 0xa9:
        return "STATUS_TRUSTED_RELATIONSHIP_FAILURE";
      case 0xaa:
        return "STATUS_EVENTLOG_FILE_CORRUPT";
      case 0xab:
        return "STATUS_EVENTLOG_CANT_START";
      case 0xac:
        return "STATUS_TRUST_FAILURE";
      case 0xad:
        return "STATUS_MUTANT_LIMIT_EXCEEDED";
      case 0xae:
        return "STATUS_NETLOGON_NOT_STARTED";
      case 0xaf:
        return "STATUS_ACCOUNT_EXPIRED";
      case 0xb0:
        return "STATUS_POSSIBLE_DEADLOCK";
      case 0xb1:
        return "STATUS_NETWORK_CREDENTIAL_CONFLICT";
      case 0xb2:
        return "STATUS_REMOTE_SESSION_LIMIT";
      case 0xb3:
        return "STATUS_EVENTLOG_FILE_CHANGED";
      case 0xb4:
        return "STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT";
      case 0xb5:
        return "STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT";
      case 0xb6:
        return "STATUS_NOLOGON_SERVER_TRUST_ACCOUNT";
      case 0xb7:
        return "STATUS_DOMAIN_TRUST_INCONSISTENT";
      case 0xb8:
        return "STATUS_FS_DRIVER_REQUIRED";
      case 0xb9:
        return "STATUS_NO_USER_SESSION_KEY";
      case 0xba:
        return "STATUS_USER_SESSION_DELETED";
      case 0xbb:
        return "STATUS_RESOURCE_LANG_NOT_FOUND";
      case 0xbc:
        return "STATUS_INSUFF_SERVER_RESOURCES";
      case 0xbd:
        return "STATUS_INVALID_BUFFER_SIZE";
      case 0xbe:
        return "STATUS_INVALID_ADDRESS_COMPONENT";
      case 0xbf:
        return "STATUS_INVALID_ADDRESS_WILDCARD";
      case 0xc0:
        return "STATUS_TOO_MANY_ADDRESSES";
      case 0xc1:
        return "STATUS_ADDRESS_ALREADY_EXISTS";
      case 0xc2:
        return "STATUS_ADDRESS_CLOSED";
      case 0xc3:
        return "STATUS_CONNECTION_DISCONNECTED";
      case 0xc4:
        return "STATUS_CONNECTION_RESET";
      case 0xc5:
        return "STATUS_TOO_MANY_NODES";
      case 0xc6:
        return "STATUS_TRANSACTION_ABORTED";
      case 199:
        return "STATUS_TRANSACTION_TIMED_OUT";
      case 200:
        return "STATUS_TRANSACTION_NO_RELEASE";
      case 0xc9:
        return "STATUS_TRANSACTION_NO_MATCH";
      case 0xca:
        return "STATUS_TRANSACTION_RESPONDED";
      case 0xcb:
        return "STATUS_TRANSACTION_INVALID_ID";
      case 0xcc:
        return "STATUS_TRANSACTION_INVALID_TYPE";
      case 0xcd:
        return "STATUS_NOT_SERVER_SESSION";
      case 0xce:
        return "STATUS_NOT_CLIENT_SESSION";
      case 0xcf:
        return "STATUS_CANNOT_LOAD_REGISTRY_FILE";
      case 0xd0:
        return "STATUS_DEBUG_ATTACH_FAILED";
      case 0xd1:
        return "STATUS_SYSTEM_PROCESS_TERMINATED";
      case 0xd2:
        return "STATUS_DATA_NOT_ACCEPTED";
      case 0xd3:
        return "STATUS_NO_BROWSER_SERVERS_FOUND";
      case 0xd4:
        return "STATUS_VDM_HARD_ERROR";
      case 0xd5:
        return "STATUS_DRIVER_CANCEL_TIMEOUT";
      case 0xd6:
        return "STATUS_REPLY_MESSAGE_MISMATCH";
      case 0xd7:
        return "STATUS_MAPPED_ALIGNMENT";
      case 0xd8:
        return "STATUS_IMAGE_CHECKSUM_MISMATCH";
      case 0xd9:
        return "STATUS_LOST_WRITEBEHIND_DATA";
      case 0xda:
        return "STATUS_CLIENT_SERVER_PARAMETERS_INVALID";
      case 0xdb:
        return "STATUS_PASSWORD_MUST_CHANGE";
      case 0xdc:
        return "STATUS_NOT_FOUND";
      case 0xdd:
        return "STATUS_NOT_TINY_STREAM";
      case 0xde:
        return "STATUS_RECOVERY_FAILURE";
      case 0xdf:
        return "STATUS_STACK_OVERFLOW_READ";
      case 0xe0:
        return "STATUS_FAIL_CHECK";
      case 0xe1:
        return "STATUS_DUPLICATE_OBJECTID";
      }
    }
  }
  else if (param_1 < -0x3fff6767) {
    if (param_1 == -0x3fff6768) {
      return "STATUS_WOW_ASSERTION";
    }
    if (param_1 + 0x3ffffdd4U < 0x1dc) {
      switch((&DAT_140013507)[(int)(param_1 + 0x3ffffdd4U)]) {
      case 0:
        return "STATUS_CONVERT_TO_LARGE";
      case 1:
        return "STATUS_RETRY";
      case 2:
        return "STATUS_FOUND_OUT_OF_SCOPE";
      case 3:
        return "STATUS_ALLOCATE_BUCKET";
      case 4:
        return "STATUS_PROPSET_NOT_FOUND";
      case 5:
        return "STATUS_MARSHALL_OVERFLOW";
      case 6:
        return "STATUS_INVALID_VARIANT";
      case 7:
        return "STATUS_DOMAIN_CONTROLLER_NOT_FOUND";
      case 8:
        return "STATUS_ACCOUNT_LOCKED_OUT";
      case 9:
        return "STATUS_HANDLE_NOT_CLOSABLE";
      case 10:
        return "STATUS_CONNECTION_REFUSED";
      case 0xb:
        return "STATUS_GRACEFUL_DISCONNECT";
      case 0xc:
        return "STATUS_ADDRESS_ALREADY_ASSOCIATED";
      case 0xd:
        return "STATUS_ADDRESS_NOT_ASSOCIATED";
      case 0xe:
        return "STATUS_CONNECTION_INVALID";
      case 0xf:
        return "STATUS_CONNECTION_ACTIVE";
      case 0x10:
        return "STATUS_NETWORK_UNREACHABLE";
      case 0x11:
        return "STATUS_HOST_UNREACHABLE";
      case 0x12:
        return "STATUS_PROTOCOL_UNREACHABLE";
      case 0x13:
        return "STATUS_PORT_UNREACHABLE";
      case 0x14:
        return "STATUS_REQUEST_ABORTED";
      case 0x15:
        return "STATUS_CONNECTION_ABORTED";
      case 0x16:
        return "STATUS_BAD_COMPRESSION_BUFFER";
      case 0x17:
        return "STATUS_USER_MAPPED_FILE";
      case 0x18:
        return "STATUS_AUDIT_FAILED";
      case 0x19:
        return "STATUS_TIMER_RESOLUTION_NOT_SET";
      case 0x1a:
        return "STATUS_CONNECTION_COUNT_LIMIT";
      case 0x1b:
        return "STATUS_LOGIN_TIME_RESTRICTION";
      case 0x1c:
        return "STATUS_LOGIN_WKSTA_RESTRICTION";
      case 0x1d:
        return "STATUS_IMAGE_MP_UP_MISMATCH";
      case 0x1e:
        return "STATUS_INSUFFICIENT_LOGON_INFO";
      case 0x1f:
        return "STATUS_BAD_DLL_ENTRYPOINT";
      case 0x20:
        return "STATUS_BAD_SERVICE_ENTRYPOINT";
      case 0x21:
        return "STATUS_LPC_REPLY_LOST";
      case 0x22:
        return "STATUS_IP_ADDRESS_CONFLICT1";
      case 0x23:
        return "STATUS_IP_ADDRESS_CONFLICT2";
      case 0x24:
        return "STATUS_REGISTRY_QUOTA_LIMIT";
      case 0x25:
        return "STATUS_PATH_NOT_COVERED";
      case 0x26:
        return "STATUS_NO_CALLBACK_ACTIVE";
      case 0x27:
        return "STATUS_LICENSE_QUOTA_EXCEEDED";
      case 0x28:
        return "STATUS_PWD_TOO_SHORT";
      case 0x29:
        return "STATUS_PWD_TOO_RECENT";
      case 0x2a:
        return "STATUS_PWD_HISTORY_CONFLICT";
      case 0x2b:
        return "STATUS_PLUGPLAY_NO_DEVICE";
      case 0x2c:
        return "STATUS_UNSUPPORTED_COMPRESSION";
      case 0x2d:
        return "STATUS_INVALID_HW_PROFILE";
      case 0x2e:
        return "STATUS_INVALID_PLUGPLAY_DEVICE_PATH";
      case 0x2f:
        return "STATUS_DRIVER_ORDINAL_NOT_FOUND";
      case 0x30:
        return "STATUS_DRIVER_ENTRYPOINT_NOT_FOUND";
      case 0x31:
        return "STATUS_RESOURCE_NOT_OWNED";
      case 0x32:
        return "STATUS_TOO_MANY_LINKS";
      case 0x33:
        return "STATUS_QUOTA_LIST_INCONSISTENT";
      case 0x34:
        return "STATUS_FILE_IS_OFFLINE";
      case 0x35:
        return "STATUS_EVALUATION_EXPIRATION";
      case 0x36:
        return "STATUS_ILLEGAL_DLL_RELOCATION";
      case 0x37:
        return "STATUS_LICENSE_VIOLATION";
      case 0x38:
        return "STATUS_DLL_INIT_FAILED_LOGOFF";
      case 0x39:
        return "STATUS_DRIVER_UNABLE_TO_LOAD";
      case 0x3a:
        return "STATUS_DFS_UNAVAILABLE";
      case 0x3b:
        return "STATUS_VOLUME_DISMOUNTED";
      case 0x3c:
        return "STATUS_WX86_INTERNAL_ERROR";
      case 0x3d:
        return "STATUS_WX86_FLOAT_STACK_CHECK";
      case 0x3e:
        return "STATUS_VALIDATE_CONTINUE";
      case 0x3f:
        return "STATUS_NO_MATCH";
      case 0x40:
        return "STATUS_NO_MORE_MATCHES";
      case 0x41:
        return "STATUS_NOT_A_REPARSE_POINT";
      case 0x42:
        return "STATUS_IO_REPARSE_TAG_INVALID";
      case 0x43:
        return "STATUS_IO_REPARSE_TAG_MISMATCH";
      case 0x44:
        return "STATUS_IO_REPARSE_DATA_INVALID";
      case 0x45:
        return "STATUS_IO_REPARSE_TAG_NOT_HANDLED";
      case 0x46:
        return "STATUS_REPARSE_POINT_NOT_RESOLVED";
      case 0x47:
        return "STATUS_DIRECTORY_IS_A_REPARSE_POINT";
      case 0x48:
        return "STATUS_RANGE_LIST_CONFLICT";
      case 0x49:
        return "STATUS_SOURCE_ELEMENT_EMPTY";
      case 0x4a:
        return "STATUS_DESTINATION_ELEMENT_FULL";
      case 0x4b:
        return "STATUS_ILLEGAL_ELEMENT_ADDRESS";
      case 0x4c:
        return "STATUS_MAGAZINE_NOT_PRESENT";
      case 0x4d:
        return "STATUS_REINITIALIZATION_NEEDED";
      case 0x4e:
        return "STATUS_ENCRYPTION_FAILED";
      case 0x4f:
        return "STATUS_DECRYPTION_FAILED";
      case 0x50:
        return "STATUS_RANGE_NOT_FOUND";
      case 0x51:
        return "STATUS_NO_RECOVERY_POLICY";
      case 0x52:
        return "STATUS_NO_EFS";
      case 0x53:
        return "STATUS_WRONG_EFS";
      case 0x54:
        return "STATUS_NO_USER_KEYS";
      case 0x55:
        return "STATUS_FILE_NOT_ENCRYPTED";
      case 0x56:
        return "STATUS_NOT_EXPORT_FORMAT";
      case 0x57:
        return "STATUS_FILE_ENCRYPTED";
      case 0x58:
        return "STATUS_WMI_GUID_NOT_FOUND";
      case 0x59:
        return "STATUS_WMI_INSTANCE_NOT_FOUND";
      case 0x5a:
        return "STATUS_WMI_ITEMID_NOT_FOUND";
      case 0x5b:
        return "STATUS_WMI_TRY_AGAIN";
      case 0x5c:
        return "STATUS_SHARED_POLICY";
      case 0x5d:
        return "STATUS_POLICY_OBJECT_NOT_FOUND";
      case 0x5e:
        return "STATUS_POLICY_ONLY_IN_DS";
      case 0x5f:
        return "STATUS_VOLUME_NOT_UPGRADED";
      case 0x60:
        return "STATUS_REMOTE_STORAGE_NOT_ACTIVE";
      case 0x61:
        return "STATUS_REMOTE_STORAGE_MEDIA_ERROR";
      case 0x62:
        return "STATUS_NO_TRACKING_SERVICE";
      case 99:
        return "STATUS_SERVER_SID_MISMATCH";
      case 100:
        return "STATUS_DS_NO_ATTRIBUTE_OR_VALUE";
      case 0x65:
        return "STATUS_DS_INVALID_ATTRIBUTE_SYNTAX";
      case 0x66:
        return "STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED";
      case 0x67:
        return "STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS";
      case 0x68:
        return "STATUS_DS_BUSY";
      case 0x69:
        return "STATUS_DS_UNAVAILABLE";
      case 0x6a:
        return "STATUS_DS_NO_RIDS_ALLOCATED";
      case 0x6b:
        return "STATUS_DS_NO_MORE_RIDS";
      case 0x6c:
        return "STATUS_DS_INCORRECT_ROLE_OWNER";
      case 0x6d:
        return "STATUS_DS_RIDMGR_INIT_ERROR";
      case 0x6e:
        return "STATUS_DS_OBJ_CLASS_VIOLATION";
      case 0x6f:
        return "STATUS_DS_CANT_ON_NON_LEAF";
      case 0x70:
        return "STATUS_DS_CANT_ON_RDN";
      case 0x71:
        return "STATUS_DS_CANT_MOD_OBJ_CLASS";
      case 0x72:
        return "STATUS_DS_CROSS_DOM_MOVE_FAILED";
      case 0x73:
        return "STATUS_DS_GC_NOT_AVAILABLE";
      case 0x74:
        return "STATUS_DIRECTORY_SERVICE_REQUIRED";
      case 0x75:
        return "STATUS_REPARSE_ATTRIBUTE_CONFLICT";
      case 0x76:
        return "STATUS_CANT_ENABLE_DENY_ONLY";
      case 0x77:
        return "STATUS_FLOAT_MULTIPLE_FAULTS";
      case 0x78:
        return "STATUS_FLOAT_MULTIPLE_TRAPS";
      case 0x79:
        return "STATUS_DEVICE_REMOVED";
      case 0x7a:
        return "STATUS_JOURNAL_DELETE_IN_PROGRESS";
      case 0x7b:
        return "STATUS_JOURNAL_NOT_ACTIVE";
      case 0x7c:
        return "STATUS_NOINTERFACE";
      case 0x7d:
        return "STATUS_DS_ADMIN_LIMIT_EXCEEDED";
      case 0x7e:
        return "STATUS_DRIVER_FAILED_SLEEP";
      case 0x7f:
        return "STATUS_MUTUAL_AUTHENTICATION_FAILED";
      case 0x80:
        return "STATUS_CORRUPT_SYSTEM_FILE";
      case 0x81:
        return "STATUS_DATATYPE_MISALIGNMENT_ERROR";
      case 0x82:
        return "STATUS_WMI_READ_ONLY";
      case 0x83:
        return "STATUS_WMI_SET_FAILURE";
      case 0x84:
        return "STATUS_COMMITMENT_MINIMUM";
      case 0x85:
        return "STATUS_REG_NAT_CONSUMPTION";
      case 0x86:
        return "STATUS_TRANSPORT_FULL";
      case 0x87:
        return "STATUS_DS_SAM_INIT_FAILURE";
      case 0x88:
        return "STATUS_ONLY_IF_CONNECTED";
      case 0x89:
        return "STATUS_DS_SENSITIVE_GROUP_VIOLATION";
      case 0x8a:
        return "STATUS_PNP_RESTART_ENUMERATION";
      case 0x8b:
        return "STATUS_JOURNAL_ENTRY_DELETED";
      case 0x8c:
        return "STATUS_DS_CANT_MOD_PRIMARYGROUPID";
      case 0x8d:
        return "STATUS_SYSTEM_IMAGE_BAD_SIGNATURE";
      case 0x8e:
        return "STATUS_PNP_REBOOT_REQUIRED";
      case 0x8f:
        return "STATUS_POWER_STATE_INVALID";
      case 0x90:
        return "STATUS_DS_INVALID_GROUP_TYPE";
      case 0x91:
        return "STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN";
      case 0x92:
        return "STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN";
      case 0x93:
        return "STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER";
      case 0x94:
        return "STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER";
      case 0x95:
        return "STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER";
      case 0x96:
        return "STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER";
      case 0x97:
        return "STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER";
      case 0x98:
        return "STATUS_DS_HAVE_PRIMARY_MEMBERS";
      case 0x99:
        return "STATUS_WMI_NOT_SUPPORTED";
      case 0x9a:
        return "STATUS_INSUFFICIENT_POWER";
      case 0x9b:
        return "STATUS_SAM_NEED_BOOTKEY_PASSWORD";
      case 0x9c:
        return "STATUS_SAM_NEED_BOOTKEY_FLOPPY";
      case 0x9d:
        return "STATUS_DS_CANT_START";
      case 0x9e:
        return "STATUS_DS_INIT_FAILURE";
      case 0x9f:
        return "STATUS_SAM_INIT_FAILURE";
      case 0xa0:
        return "STATUS_DS_GC_REQUIRED";
      case 0xa1:
        return "STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY";
      case 0xa2:
        return "STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS";
      case 0xa3:
        return "STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED";
      case 0xa4:
        return "STATUS_MULTIPLE_FAULT_VIOLATION";
      case 0xa5:
        return "STATUS_CURRENT_DOMAIN_NOT_ALLOWED";
      case 0xa6:
        return "STATUS_CANNOT_MAKE";
      case 0xa7:
        return "STATUS_SYSTEM_SHUTDOWN";
      case 0xa8:
        return "STATUS_DS_INIT_FAILURE_CONSOLE";
      case 0xa9:
        return "STATUS_DS_SAM_INIT_FAILURE_CONSOLE";
      case 0xaa:
        return "STATUS_UNFINISHED_CONTEXT_DELETED";
      case 0xab:
        return "STATUS_NO_TGT_REPLY";
      case 0xac:
        return "STATUS_OBJECTID_NOT_FOUND";
      case 0xad:
        return "STATUS_NO_IP_ADDRESSES";
      case 0xae:
        return "STATUS_WRONG_CREDENTIAL_HANDLE";
      case 0xaf:
        return "STATUS_CRYPTO_SYSTEM_INVALID";
      case 0xb0:
        return "STATUS_MAX_REFERRALS_EXCEEDED";
      case 0xb1:
        return "STATUS_MUST_BE_KDC";
      case 0xb2:
        return "STATUS_STRONG_CRYPTO_NOT_SUPPORTED";
      case 0xb3:
        return "STATUS_TOO_MANY_PRINCIPALS";
      case 0xb4:
        return "STATUS_NO_PA_DATA";
      case 0xb5:
        return "STATUS_PKINIT_NAME_MISMATCH";
      case 0xb6:
        return "STATUS_SMARTCARD_LOGON_REQUIRED";
      case 0xb7:
        return "STATUS_KDC_INVALID_REQUEST";
      case 0xb8:
        return "STATUS_KDC_UNABLE_TO_REFER";
      case 0xb9:
        return "STATUS_KDC_UNKNOWN_ETYPE";
      case 0xba:
        return "STATUS_SHUTDOWN_IN_PROGRESS";
      case 0xbb:
        return "STATUS_SERVER_SHUTDOWN_IN_PROGRESS";
      case 0xbc:
        return "STATUS_NOT_SUPPORTED_ON_SBS";
      case 0xbd:
        return "STATUS_WMI_GUID_DISCONNECTED";
      case 0xbe:
        return "STATUS_WMI_ALREADY_DISABLED";
      case 0xbf:
        return "STATUS_WMI_ALREADY_ENABLED";
      case 0xc0:
        return "STATUS_MFT_TOO_FRAGMENTED";
      case 0xc1:
        return "STATUS_COPY_PROTECTION_FAILURE";
      case 0xc2:
        return "STATUS_CSS_AUTHENTICATION_FAILURE";
      case 0xc3:
        return "STATUS_CSS_KEY_NOT_PRESENT";
      case 0xc4:
        return "STATUS_CSS_KEY_NOT_ESTABLISHED";
      case 0xc5:
        return "STATUS_CSS_SCRAMBLED_SECTOR";
      case 0xc6:
        return "STATUS_CSS_REGION_MISMATCH";
      case 199:
        return "STATUS_CSS_RESETS_EXHAUSTED";
      case 200:
        return "STATUS_PKINIT_FAILURE";
      case 0xc9:
        return "STATUS_SMARTCARD_SUBSYSTEM_FAILURE";
      case 0xca:
        return "STATUS_NO_KERB_KEY";
      case 0xcb:
        return "STATUS_HOST_DOWN";
      case 0xcc:
        return "STATUS_UNSUPPORTED_PREAUTH";
      case 0xcd:
        return "STATUS_EFS_ALG_BLOB_TOO_BIG";
      case 0xce:
        return "STATUS_PORT_NOT_SET";
      case 0xcf:
        return "STATUS_DEBUGGER_INACTIVE";
      case 0xd0:
        return "STATUS_DS_VERSION_CHECK_FAILURE";
      case 0xd1:
        return "STATUS_AUDITING_DISABLED";
      case 0xd2:
        return "STATUS_PRENT4_MACHINE_ACCOUNT";
      case 0xd3:
        return "STATUS_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER";
      case 0xd4:
        return "STATUS_INVALID_IMAGE_WIN_32";
      case 0xd5:
        return "STATUS_INVALID_IMAGE_WIN_64";
      case 0xd6:
        return "STATUS_BAD_BINDINGS";
      case 0xd7:
        return "STATUS_NETWORK_SESSION_EXPIRED";
      case 0xd8:
        return "STATUS_APPHELP_BLOCK";
      case 0xd9:
        return "STATUS_ALL_SIDS_FILTERED";
      case 0xda:
        return "STATUS_NOT_SAFE_MODE_DRIVER";
      case 0xdb:
        return "STATUS_ACCESS_DISABLED_BY_POLICY_DEFAULT";
      case 0xdc:
        return "STATUS_ACCESS_DISABLED_BY_POLICY_PATH";
      case 0xdd:
        return "STATUS_ACCESS_DISABLED_BY_POLICY_PUBLISHER";
      case 0xde:
        return "STATUS_ACCESS_DISABLED_BY_POLICY_OTHER";
      case 0xdf:
        return "STATUS_FAILED_DRIVER_ENTRY";
      case 0xe0:
        return "STATUS_DEVICE_ENUMERATION_ERROR";
      case 0xe1:
        return "STATUS_MOUNT_POINT_NOT_RESOLVED";
      case 0xe2:
        return "STATUS_INVALID_DEVICE_OBJECT_PARAMETER";
      case 0xe3:
        return "STATUS_MCA_OCCURED";
      case 0xe4:
        return "STATUS_DRIVER_BLOCKED_CRITICAL";
      case 0xe5:
        return "STATUS_DRIVER_BLOCKED";
      case 0xe6:
        return "STATUS_DRIVER_DATABASE_ERROR";
      case 0xe7:
        return "STATUS_SYSTEM_HIVE_TOO_LARGE";
      case 0xe8:
        return "STATUS_INVALID_IMPORT_OF_NON_DLL";
      case 0xe9:
        return "STATUS_SMARTCARD_WRONG_PIN";
      case 0xea:
        return "STATUS_SMARTCARD_CARD_BLOCKED";
      case 0xeb:
        return "STATUS_SMARTCARD_CARD_NOT_AUTHENTICATED";
      case 0xec:
        return "STATUS_SMARTCARD_NO_CARD";
      case 0xed:
        return "STATUS_SMARTCARD_NO_KEY_CONTAINER";
      case 0xee:
        return "STATUS_SMARTCARD_NO_CERTIFICATE";
      case 0xef:
        return "STATUS_SMARTCARD_NO_KEYSET";
      case 0xf0:
        return "STATUS_SMARTCARD_IO_ERROR";
      case 0xf1:
        return "STATUS_DOWNGRADE_DETECTED";
      case 0xf2:
        return "STATUS_SMARTCARD_CERT_REVOKED";
      case 0xf3:
        return "STATUS_ISSUING_CA_UNTRUSTED";
      case 0xf4:
        return "STATUS_REVOCATION_OFFLINE_C";
      case 0xf5:
        return "STATUS_PKINIT_CLIENT_FAILURE";
      case 0xf6:
        return "STATUS_SMARTCARD_CERT_EXPIRED";
      case 0xf7:
        return "STATUS_DRIVER_FAILED_PRIOR_UNLOAD";
      case 0xf8:
        return "STATUS_PER_USER_TRUST_QUOTA_EXCEEDED";
      case 0xf9:
        return "STATUS_ALL_USER_TRUST_QUOTA_EXCEEDED";
      case 0xfa:
        return "STATUS_USER_DELETE_TRUST_QUOTA_EXCEEDED";
      case 0xfb:
        return "STATUS_DS_NAME_NOT_UNIQUE";
      case 0xfc:
        return "STATUS_DS_DUPLICATE_ID_FOUND";
      case 0xfd:
        return "STATUS_DS_GROUP_CONVERSION_ERROR";
      case 0xfe:
        return "STATUS_VOLSNAP_PREPARE_HIBERNATE";
      }
    }
  }
  else if (param_1 < -0x3feafff6) {
    if (param_1 == -0x3feafff7) {
      return "STATUS_SXS_VERSION_CONFLICT";
    }
    if (param_1 < -0x3fecfff5) {
      if (param_1 == -0x3fecfff6) {
        return "STATUS_CLUSTER_INVALID_REQUEST";
      }
      if (param_1 < -0x3ff5ffdd) {
        if (param_1 == -0x3ff5ffde) {
          return "STATUS_CTX_GRAPHICS_INVALID";
        }
        if (param_1 < -0x3ff5fff3) {
          if (param_1 == -0x3ff5fff4) {
            return "STATUS_CTX_MODEM_RESPONSE_NO_CARRIER";
          }
          if (param_1 < -0x3ff5fff9) {
            if (param_1 == -0x3ff5fffa) {
              return "STATUS_CTX_CLOSE_PENDING";
            }
            if (param_1 == -0x3ffbffcb) {
              return "STATUS_PNP_BAD_MPS_TABLE";
            }
            if (param_1 == -0x3ffbffca) {
              return "STATUS_PNP_TRANSLATION_FAILED";
            }
            if (param_1 == -0x3ffbffc9) {
              return "STATUS_PNP_IRQ_TRANSLATION_FAILED";
            }
            if (param_1 == -0x3ff5ffff) {
              return "STATUS_CTX_WINSTATION_NAME_INVALID";
            }
            if (param_1 == -0x3ff5fffe) {
              return "STATUS_CTX_INVALID_PD";
            }
            pcVar2 = "STATUS_CTX_PD_NOT_FOUND";
            bVar3 = param_1 == -0x3ff5fffd;
          }
          else {
            if (param_1 == -0x3ff5fff9) {
              return "STATUS_CTX_NO_OUTBUF";
            }
            if (param_1 == -0x3ff5fff8) {
              return "STATUS_CTX_MODEM_INF_NOT_FOUND";
            }
            if (param_1 == -0x3ff5fff7) {
              return "STATUS_CTX_INVALID_MODEMNAME";
            }
            if (param_1 == -0x3ff5fff6) {
              return "STATUS_CTX_RESPONSE_ERROR";
            }
            pcVar2 = "STATUS_CTX_MODEM_RESPONSE_TIMEOUT";
            bVar3 = param_1 == -0x3ff5fff5;
          }
LAB_140006a7c:
          pcVar1 = "NTSTATUS_UNKNOWN";
          if (bVar3) {
            pcVar1 = pcVar2;
          }
          return pcVar1;
        }
        switch(param_1) {
        case -0x3ff5fff3:
          return "STATUS_CTX_MODEM_RESPONSE_NO_DIALTONE";
        case -0x3ff5fff2:
          return "STATUS_CTX_MODEM_RESPONSE_BUSY";
        case -0x3ff5fff1:
          return "STATUS_CTX_MODEM_RESPONSE_VOICE";
        case -0x3ff5fff0:
          return "STATUS_CTX_TD_ERROR";
        case -0x3ff5ffee:
          return "STATUS_CTX_LICENSE_CLIENT_INVALID";
        case -0x3ff5ffed:
          return "STATUS_CTX_LICENSE_NOT_AVAILABLE";
        case -0x3ff5ffec:
          return "STATUS_CTX_LICENSE_EXPIRED";
        case -0x3ff5ffeb:
          return "STATUS_CTX_WINSTATION_NOT_FOUND";
        case -0x3ff5ffea:
          return "STATUS_CTX_WINSTATION_NAME_COLLISION";
        case -0x3ff5ffe9:
          return "STATUS_CTX_WINSTATION_BUSY";
        case -0x3ff5ffe8:
          return "STATUS_CTX_BAD_VIDEO_MODE";
        }
      }
      else {
        if (-0x3fecffff < param_1) {
          if (param_1 == -0x3fecfffe) {
            return "STATUS_CLUSTER_NODE_EXISTS";
          }
          if (param_1 == -0x3fecfffd) {
            return "STATUS_CLUSTER_JOIN_IN_PROGRESS";
          }
          if (param_1 == -0x3fecfffc) {
            return "STATUS_CLUSTER_NODE_NOT_FOUND";
          }
          if (param_1 == -0x3fecfffb) {
            return "STATUS_CLUSTER_LOCAL_NODE_NOT_FOUND";
          }
          if (param_1 == -0x3fecfffa) {
            return "STATUS_CLUSTER_NETWORK_EXISTS";
          }
          if (param_1 == -0x3fecfff9) {
            return "STATUS_CLUSTER_NETWORK_NOT_FOUND";
          }
          if (param_1 == -0x3fecfff8) {
            return "STATUS_CLUSTER_NETINTERFACE_EXISTS";
          }
          pcVar2 = "STATUS_CLUSTER_NETINTERFACE_NOT_FOUND";
          bVar3 = param_1 == -0x3fecfff7;
          goto LAB_140006a7c;
        }
        if (param_1 == -0x3fecffff) {
          return "STATUS_CLUSTER_INVALID_NODE";
        }
        switch(param_1) {
        case -0x3ff5ffdc:
          return "STATUS_CTX_NOT_CONSOLE";
        case -0x3ff5ffda:
          return "STATUS_CTX_CLIENT_QUERY_TIMEOUT";
        case -0x3ff5ffd9:
          return "STATUS_CTX_CONSOLE_DISCONNECT";
        case -0x3ff5ffd8:
          return "STATUS_CTX_CONSOLE_CONNECT";
        case -0x3ff5ffd6:
          return "STATUS_CTX_SHADOW_DENIED";
        case -0x3ff5ffd5:
          return "STATUS_CTX_WINSTATION_ACCESS_DENIED";
        case -0x3ff5ffd2:
          return "STATUS_CTX_INVALID_WD";
        case -0x3ff5ffd1:
          return "STATUS_CTX_WD_NOT_FOUND";
        case -0x3ff5ffd0:
          return "STATUS_CTX_SHADOW_INVALID";
        case -0x3ff5ffcf:
          return "STATUS_CTX_SHADOW_DISABLED";
        case -0x3ff5ffce:
          return "STATUS_RDP_PROTOCOL_ERROR";
        case -0x3ff5ffcd:
          return "STATUS_CTX_CLIENT_LICENSE_NOT_SET";
        case -0x3ff5ffcc:
          return "STATUS_CTX_CLIENT_LICENSE_IN_USE";
        case -0x3ff5ffcb:
          return "STATUS_CTX_SHADOW_ENDED_BY_MODE_CHANGE";
        case -0x3ff5ffca:
          return "STATUS_CTX_SHADOW_NOT_RUNNING";
        }
      }
    }
    else if (param_1 < -0x3febfffe) {
      if (param_1 == -0x3febffff) {
        return "STATUS_ACPI_INVALID_OPCODE";
      }
      switch(param_1) {
      case -0x3fecfff5:
        return "STATUS_CLUSTER_INVALID_NETWORK_PROVIDER";
      case -0x3fecfff4:
        return "STATUS_CLUSTER_NODE_DOWN";
      case -0x3fecfff3:
        return "STATUS_CLUSTER_NODE_UNREACHABLE";
      case -0x3fecfff2:
        return "STATUS_CLUSTER_NODE_NOT_MEMBER";
      case -0x3fecfff1:
        return "STATUS_CLUSTER_JOIN_NOT_IN_PROGRESS";
      case -0x3fecfff0:
        return "STATUS_CLUSTER_INVALID_NETWORK";
      case -0x3fecffef:
        return "STATUS_CLUSTER_NO_NET_ADAPTERS";
      case -0x3fecffee:
        return "STATUS_CLUSTER_NODE_UP";
      case -0x3fecffed:
        return "STATUS_CLUSTER_NODE_PAUSED";
      case -0x3fecffec:
        return "STATUS_CLUSTER_NODE_NOT_PAUSED";
      case -0x3fecffeb:
        return "STATUS_CLUSTER_NO_SECURITY_CONTEXT";
      case -0x3fecffea:
        return "STATUS_CLUSTER_NETWORK_NOT_INTERNAL";
      case -0x3fecffe9:
        return "STATUS_CLUSTER_POISONED";
      }
    }
    else {
      if (-0x3feaffff < param_1) {
        if (param_1 == -0x3feafffe) {
          return "STATUS_SXS_CANT_GEN_ACTCTX";
        }
        if (param_1 == -0x3feafffd) {
          return "STATUS_SXS_INVALID_ACTCTXDATA_FORMAT";
        }
        if (param_1 == -0x3feafffc) {
          return "STATUS_SXS_ASSEMBLY_NOT_FOUND";
        }
        if (param_1 == -0x3feafffb) {
          return "STATUS_SXS_MANIFEST_FORMAT_ERROR";
        }
        if (param_1 == -0x3feafffa) {
          return "STATUS_SXS_MANIFEST_PARSE_ERROR";
        }
        if (param_1 == -0x3feafff9) {
          return "STATUS_SXS_ACTIVATION_CONTEXT_DISABLED";
        }
        pcVar2 = "STATUS_SXS_KEY_NOT_FOUND";
        bVar3 = param_1 == -0x3feafff8;
        goto LAB_140006a7c;
      }
      if (param_1 == -0x3feaffff) {
        return "STATUS_SXS_SECTION_NOT_FOUND";
      }
      switch(param_1) {
      case -0x3febfffe:
        return "STATUS_ACPI_STACK_OVERFLOW";
      case -0x3febfffd:
        return "STATUS_ACPI_ASSERT_FAILED";
      case -0x3febfffc:
        return "STATUS_ACPI_INVALID_INDEX";
      case -0x3febfffb:
        return "STATUS_ACPI_INVALID_ARGUMENT";
      case -0x3febfffa:
        return "STATUS_ACPI_FATAL";
      case -0x3febfff9:
        return "STATUS_ACPI_INVALID_SUPERNAME";
      case -0x3febfff8:
        return "STATUS_ACPI_INVALID_ARGTYPE";
      case -0x3febfff7:
        return "STATUS_ACPI_INVALID_OBJTYPE";
      case -0x3febfff6:
        return "STATUS_ACPI_INVALID_TARGETTYPE";
      case -0x3febfff5:
        return "STATUS_ACPI_INCORRECT_ARGUMENT_COUNT";
      case -0x3febfff4:
        return "STATUS_ACPI_ADDRESS_NOT_MAPPED";
      case -0x3febfff3:
        return "STATUS_ACPI_INVALID_EVENTTYPE";
      case -0x3febfff2:
        return "STATUS_ACPI_HANDLER_COLLISION";
      case -0x3febfff1:
        return "STATUS_ACPI_INVALID_DATA";
      case -0x3febfff0:
        return "STATUS_ACPI_INVALID_REGION";
      case -0x3febffef:
        return "STATUS_ACPI_INVALID_ACCESS_SIZE";
      case -0x3febffee:
        return "STATUS_ACPI_ACQUIRE_GLOBAL_LOCK";
      case -0x3febffed:
        return "STATUS_ACPI_ALREADY_INITIALIZED";
      case -0x3febffec:
        return "STATUS_ACPI_NOT_INITIALIZED";
      case -0x3febffeb:
        return "STATUS_ACPI_INVALID_MUTEX_LEVEL";
      case -0x3febffea:
        return "STATUS_ACPI_MUTEX_NOT_OWNED";
      case -0x3febffe9:
        return "STATUS_ACPI_MUTEX_NOT_OWNER";
      case -0x3febffe8:
        return "STATUS_ACPI_RS_ACCESS";
      case -0x3febffe7:
        return "STATUS_ACPI_INVALID_TABLE";
      case -0x3febffe0:
        return "STATUS_ACPI_REG_HANDLER_FAILED";
      case -0x3febffdf:
        return "STATUS_ACPI_POWER_REQUEST_FAILED";
      }
    }
  }
  else if (param_1 < 0x40000001) {
    if (param_1 == 0x40000000) {
      return "STATUS_OBJECT_NAME_EXISTS";
    }
    if (param_1 < 0x108) {
      if (param_1 == 0x107) {
        return "STATUS_SOME_NOT_MAPPED";
      }
      if (param_1 < 4) {
        if (param_1 == 3) {
          return "STATUS_WAIT_3";
        }
        if (param_1 < -0x3feaffee) {
          if (param_1 == -0x3feaffef) {
            return "STATUS_SXS_MULTIPLE_DEACTIVATION";
          }
          if (param_1 == -0x3feafff6) {
            return "STATUS_SXS_WRONG_SECTION_TYPE";
          }
          if (param_1 == -0x3feafff5) {
            return "STATUS_SXS_THREAD_QUERIES_DISABLED";
          }
          if (param_1 == -0x3feafff4) {
            return "STATUS_SXS_ASSEMBLY_MISSING";
          }
          if (param_1 == -0x3feafff2) {
            return "STATUS_SXS_PROCESS_DEFAULT_ALREADY_SET";
          }
          if (param_1 == -0x3feafff1) {
            return "STATUS_SXS_EARLY_DEACTIVATION";
          }
          pcVar2 = "STATUS_SXS_INVALID_DEACTIVATION";
          bVar3 = param_1 == -0x3feafff0;
        }
        else {
          if (param_1 == -0x3feaffee) {
            return "STATUS_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY";
          }
          if (param_1 == -0x3feaffed) {
            return "STATUS_SXS_PROCESS_TERMINATION_REQUESTED";
          }
          if (param_1 == 0) {
            return "STATUS_SUCCESS";
          }
          if (param_1 == 1) {
            return "STATUS_WAIT_1";
          }
          pcVar2 = "STATUS_WAIT_2";
          bVar3 = param_1 == 2;
        }
        goto LAB_140006a7c;
      }
      if (param_1 < 0x102) {
        if (param_1 == 0x101) {
          return "STATUS_ALERTED";
        }
        if (param_1 == 0x3f) {
          return "STATUS_WAIT_63";
        }
        if (param_1 == 0x80) {
          return "STATUS_ABANDONED";
        }
        if (param_1 == 0xbf) {
          return "STATUS_ABANDONED_WAIT_63";
        }
        if (param_1 == 0xc0) {
          return "STATUS_USER_APC";
        }
        if (param_1 == 0x100) {
          return "STATUS_KERNEL_APC";
        }
      }
      else {
        if (param_1 == 0x102) {
          return "STATUS_TIMEOUT";
        }
        if (param_1 == 0x103) {
          return "STATUS_PENDING";
        }
        if (param_1 == 0x104) {
          return "STATUS_REPARSE";
        }
        if (param_1 == 0x105) {
          return "STATUS_MORE_ENTRIES";
        }
        if (param_1 == 0x106) {
          return "STATUS_NOT_ALL_ASSIGNED";
        }
      }
    }
    else if (param_1 < 0x368) {
      if (param_1 == 0x367) {
        return "STATUS_WAIT_FOR_OPLOCK";
      }
      if (param_1 < 0x115) {
        if (param_1 == 0x114) {
          return "STATUS_PAGE_FAULT_PAGING_FILE";
        }
        if (param_1 < 0x10e) {
          if (param_1 == 0x10d) {
            return "STATUS_NO_QUOTAS_FOR_ACCOUNT";
          }
          if (param_1 == 0x108) {
            return "STATUS_OPLOCK_BREAK_IN_PROGRESS";
          }
          if (param_1 == 0x109) {
            return "STATUS_VOLUME_MOUNTED";
          }
          if (param_1 == 0x10a) {
            return "STATUS_RXACT_COMMITTED";
          }
          if (param_1 == 0x10b) {
            return "STATUS_NOTIFY_CLEANUP";
          }
          if (param_1 == 0x10c) {
            return "STATUS_NOTIFY_ENUM_DIR";
          }
        }
        else {
          if (param_1 == 0x10e) {
            return "STATUS_PRIMARY_TRANSPORT_CONNECT_FAILED";
          }
          if (param_1 == 0x110) {
            return "STATUS_PAGE_FAULT_TRANSITION";
          }
          if (param_1 == 0x111) {
            return "STATUS_PAGE_FAULT_DEMAND_ZERO";
          }
          if (param_1 == 0x112) {
            return "STATUS_PAGE_FAULT_COPY_ON_WRITE";
          }
          if (param_1 == 0x113) {
            return "STATUS_PAGE_FAULT_GUARD_PAGE";
          }
        }
      }
      else if (param_1 < 0x121) {
        if (param_1 == 0x120) {
          return "STATUS_TRANSLATION_COMPLETE";
        }
        if (param_1 == 0x115) {
          return "STATUS_CACHE_PAGE_LOCKED";
        }
        if (param_1 == 0x116) {
          return "STATUS_CRASH_DUMP";
        }
        if (param_1 == 0x117) {
          return "STATUS_BUFFER_ALL_ZEROS";
        }
        if (param_1 == 0x118) {
          return "STATUS_REPARSE_OBJECT";
        }
        if (param_1 == 0x119) {
          return "STATUS_RESOURCE_REQUIREMENTS_CHANGED";
        }
      }
      else {
        if (param_1 == 0x121) {
          return "STATUS_DS_MEMBERSHIP_EVALUATED_LOCALLY";
        }
        if (param_1 == 0x122) {
          return "STATUS_NOTHING_TO_TERMINATE";
        }
        if (param_1 == 0x123) {
          return "STATUS_PROCESS_NOT_IN_JOB";
        }
        if (param_1 == 0x124) {
          return "STATUS_PROCESS_IN_JOB";
        }
        if (param_1 == 0x125) {
          return "STATUS_VOLSNAP_HIBERNATE_READY";
        }
      }
    }
  }
  else if (param_1 < 0x40000295) {
    if (param_1 == 0x40000294) {
      return "STATUS_WAKE_SYSTEM";
    }
    switch(param_1) {
    case 0x40000001:
      return "STATUS_THREAD_WAS_SUSPENDED";
    case 0x40000002:
      return "STATUS_WORKING_SET_LIMIT_RANGE";
    case 0x40000003:
      return "STATUS_IMAGE_NOT_AT_BASE";
    case 0x40000004:
      return "STATUS_RXACT_STATE_CREATED";
    case 0x40000005:
      return "STATUS_SEGMENT_NOTIFICATION";
    case 0x40000006:
      return "STATUS_LOCAL_USER_SESSION_KEY";
    case 0x40000007:
      return "STATUS_BAD_CURRENT_DIRECTORY";
    case 0x40000008:
      return "STATUS_SERIAL_MORE_WRITES";
    case 0x40000009:
      return "STATUS_REGISTRY_RECOVERED";
    case 0x4000000a:
      return "STATUS_FT_READ_RECOVERY_FROM_BACKUP";
    case 0x4000000b:
      return "STATUS_FT_WRITE_RECOVERY";
    case 0x4000000c:
      return "STATUS_SERIAL_COUNTER_TIMEOUT";
    case 0x4000000d:
      return "STATUS_NULL_LM_PASSWORD";
    case 0x4000000e:
      return "STATUS_IMAGE_MACHINE_TYPE_MISMATCH";
    case 0x4000000f:
      return "STATUS_RECEIVE_PARTIAL";
    case 0x40000010:
      return "STATUS_RECEIVE_EXPEDITED";
    case 0x40000011:
      return "STATUS_RECEIVE_PARTIAL_EXPEDITED";
    case 0x40000012:
      return "STATUS_EVENT_DONE";
    case 0x40000013:
      return "STATUS_EVENT_PENDING";
    case 0x40000014:
      return "STATUS_CHECKING_FILE_SYSTEM";
    case 0x40000015:
      return "STATUS_FATAL_APP_EXIT";
    case 0x40000016:
      return "STATUS_PREDEFINED_HANDLE";
    case 0x40000017:
      return "STATUS_WAS_UNLOCKED";
    case 0x40000018:
      return "STATUS_SERVICE_NOTIFICATION";
    case 0x40000019:
      return "STATUS_WAS_LOCKED";
    case 0x4000001a:
      return "STATUS_LOG_HARD_ERROR";
    case 0x4000001b:
      return "STATUS_ALREADY_WIN32";
    case 0x4000001c:
      return "STATUS_WX86_UNSIMULATE";
    case 0x4000001d:
      return "STATUS_WX86_CONTINUE";
    case 0x4000001e:
      return "STATUS_WX86_SINGLE_STEP";
    case 0x4000001f:
      return "STATUS_WX86_BREAKPOINT";
    case 0x40000020:
      return "STATUS_WX86_EXCEPTION_CONTINUE";
    case 0x40000021:
      return "STATUS_WX86_EXCEPTION_LASTCHANCE";
    case 0x40000022:
      return "STATUS_WX86_EXCEPTION_CHAIN";
    case 0x40000023:
      return "STATUS_IMAGE_MACHINE_TYPE_MISMATCH_EXE";
    case 0x40000024:
      return "STATUS_NO_YIELD_PERFORMED";
    case 0x40000025:
      return "STATUS_TIMER_RESUME_IGNORED";
    case 0x40000026:
      return "STATUS_ARBITRATION_UNHANDLED";
    case 0x40000027:
      return "STATUS_CARDBUS_NOT_SUPPORTED";
    case 0x40000028:
      return "STATUS_WX86_CREATEWX86TIB";
    case 0x40000029:
      return "STATUS_MP_PROCESSOR_MISMATCH";
    case 0x4000002a:
      return "STATUS_HIBERNATED";
    case 0x4000002b:
      return "STATUS_RESUME_HIBERNATION";
    }
  }
  else {
    if (param_1 == 0x40000370) {
      return "STATUS_DS_SHUTTING_DOWN";
    }
    if (param_1 == 0x400a0004) {
      return "STATUS_CTX_CDM_CONNECT";
    }
    if (param_1 == 0x400a0005) {
      return "STATUS_CTX_CDM_DISCONNECT";
    }
    if (param_1 == 0x4015000d) {
      return "STATUS_SXS_RELEASE_ACTIVATION_CONTEXT";
    }
  }
  return "NTSTATUS_UNKNOWN";
}



===== RefObj_GlobalsInit @ 140006f20 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RefObj_GlobalsInit(void)

{
  _DAT_1400152f0 = &DAT_1400152e8;
  DAT_1400152e8 = &DAT_1400152e8;
  KeInitializeSpinLock(&BthLib_RefObjGlobals);
  MmIsDriverVerifyingByAddress(RefObj_GlobalsInit);
  return;
}



===== ReadVariableLengthPolicy @ 140006f6c =====

int ReadVariableLengthPolicy
              (undefined8 param_1,longlong param_2,uint param_3,undefined8 param_4,longlong *param_5
              ,uint *param_6)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  *param_5 = 0;
  pvVar3 = (void *)0x0;
  *param_6 = 0;
  uVar4 = 0;
  do {
    iVar2 = BthQueryKeyValueEx(param_1,param_2,pvVar3,uVar4,local_res20);
    uVar1 = local_res20[0];
    if (iVar2 < 0) {
      if ((iVar2 != -0x3fffffdd) && (iVar2 != -0x7ffffffb)) goto LAB_140007009;
    }
    else {
      if (local_res20[0] == *param_6) {
        if (local_res20[0] % param_3 == 0) {
          if (local_res20[0] != 0) {
            *param_6 = local_res20[0];
            return iVar2;
          }
          goto LAB_140007078;
        }
        iVar2 = -0x3fffffff;
LAB_14000706f:
        if (iVar2 < 0) {
LAB_140007073:
          iVar2 = -0x3fffffff;
LAB_140007078:
          if (*param_5 != 0) {
            ExFreePoolWithTag(*param_5,0);
            *param_5 = 0;
          }
          *param_6 = 0;
        }
        return iVar2;
      }
LAB_140007009:
      if (local_res20[0] == *param_6) goto LAB_14000706f;
    }
    if (local_res20[0] % param_3 != 0) goto LAB_140007073;
    if (*param_5 != 0) {
      ExFreePoolWithTag(*param_5);
      *param_5 = 0;
    }
    pvVar3 = (void *)0x0;
    if (uVar1 != 0) {
      pvVar3 = (void *)ExAllocatePool2(0x40,uVar1,0x746d7062);
      *param_5 = (longlong)pvVar3;
      if (pvVar3 == (void *)0x0) goto LAB_140007073;
    }
    *param_6 = uVar1;
    if (uVar4 == uVar1) goto LAB_14000706f;
    uVar4 = uVar1;
  } while( true );
}



===== BthGetPolicyRegistryLocation @ 1400070bc =====

ulonglong BthGetPolicyRegistryLocation(undefined8 param_1)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0;
  uVar2 = RtlGetPersistedStateLocation
                    (L"BluetoothPolicy",0,
                     L"\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\Hardware\\Bluetooth"
                     ,0,0,0,local_res10);
  if ((int)uVar2 < 0) {
    if ((int)uVar2 == -0x7ffffffb) {
      lVar3 = ExAllocatePool2(0x40,local_res10[0],0x746d7062);
      if (lVar3 == 0) {
        uVar2 = 0xc000009a;
      }
      else {
        uVar1 = RtlGetPersistedStateLocation
                          (L"BluetoothPolicy",0,
                           L"\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\Hardware\\Bluetooth"
                           ,0,lVar3,local_res10[0],local_res10);
        uVar2 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          ExFreePoolWithTag(lVar3,0);
        }
        else {
          RtlInitUnicodeString(param_1,lVar3);
        }
      }
    }
  }
  else {
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== BthPolicyDestroy @ 1400071c4 =====

void BthPolicyDestroy(void)

{
  undefined1 uVar1;
  
  McGenEventUnregister_EtwUnregister();
  if (DAT_1400152c8 != 0) {
    ExUnsubscribeWnfStateChange();
    DAT_1400152c8 = 0;
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(&g_PolicyLock);
  if (DAT_140015250 != 0) {
    ExFreePoolWithTag();
  }
  if (DAT_140015258 != 0) {
    ExFreePoolWithTag();
  }
  if (DAT_140015260 != 0) {
    ExFreePoolWithTag();
  }
  memset(&g_Policies,0,0x50);
  KeReleaseSpinLock(&g_PolicyLock,uVar1);
  uVar1 = KeAcquireSpinLockRaiseToDpc(&g_CallbackLock);
  g_Callback = (_func_void_void_ptr *)0x0;
  g_CallbackContext = (void *)0x0;
  KeReleaseSpinLock(&g_CallbackLock,uVar1);
  if (g_PolicyStorePath.Buffer != (wchar_t *)0x0) {
    ExFreePoolWithTag(g_PolicyStorePath.Buffer,0);
  }
  g_PolicyStorePath = (_UNICODE_STRING)ZEXT816(0);
  return;
}



===== BthServiceAllowedByPolicy @ 1400072e4 =====

undefined8 BthServiceAllowedByPolicy(longlong *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  longlong *plVar3;
  undefined8 uVar4;
  bool bVar5;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(&g_PolicyLock);
  uVar4 = 0;
  bVar5 = DAT_14001527c == 0;
  KeReleaseSpinLock(&g_PolicyLock,uVar1);
  if (bVar5) {
    uVar4 = 1;
  }
  else {
    uVar1 = KeAcquireSpinLockRaiseToDpc(&g_PolicyLock);
    uVar2 = 0;
    if (DAT_14001527c != 0) {
      do {
        plVar3 = (longlong *)((ulonglong)uVar2 * 0x10 + DAT_140015260);
        if ((*param_1 == *plVar3) && (param_1[1] == plVar3[1])) {
          uVar4 = 1;
          break;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < DAT_14001527c);
    }
    KeReleaseSpinLock(&g_PolicyLock,uVar1);
  }
  return uVar4;
}



===== BthSyncWithPolicyStore @ 1400073b4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int BthSyncWithPolicyStore(void)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint *_Dst;
  undefined8 uVar5;
  uint local_res8 [2];
  longlong local_res10;
  undefined8 local_88;
  undefined8 uStack_80;
  uint local_78;
  uint uStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint local_68;
  uint uStack_64;
  undefined8 uStack_60;
  longlong local_58;
  longlong lStack_50;
  undefined8 local_48;
  uint uStack_40;
  uint uStack_3c;
  int local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  _Dst = &local_78;
  local_res10 = 0;
  local_res8[0] = 0;
  local_88 = 0;
  uStack_80 = 0;
  memset(_Dst,0,0x50);
  if (g_PolicyStorePath.Buffer == (wchar_t *)0x0) {
    iVar3 = -0x3fffffff;
  }
  else {
    iVar3 = BthOpenKeyEx(_Dst,&g_PolicyStorePath,&local_res10);
    if (-1 < iVar3) {
      RtlInitUnicodeString(&local_88,L"PM_AllowBluetooth");
      iVar4 = BthQueryKeyValueEx(local_res10,(longlong)&local_88,&local_78,4,(undefined4 *)0x0);
      if ((-1 < iVar4) && ((local_78 & 0xfffffffd) == 0)) {
        uStack_34 = uStack_34 | 1;
      }
      RtlInitUnicodeString(&local_88,L"PM_AllowDiscoverableMode");
      iVar4 = BthQueryKeyValueEx(local_res10,(longlong)&local_88,&uStack_74,4,(undefined4 *)0x0);
      if ((-1 < iVar4) && (uStack_74 < 2)) {
        uStack_34 = uStack_34 | 2;
      }
      RtlInitUnicodeString(&local_88,L"PM_AllowConnectableMode");
      iVar4 = BthQueryKeyValueEx(local_res10,(longlong)&local_88,&uStack_70,4,(undefined4 *)0x0);
      if ((-1 < iVar4) && (uStack_70 < 2)) {
        uStack_34 = uStack_34 | 4;
      }
      RtlInitUnicodeString(&local_88,L"PM_AllowAdvertising");
      iVar4 = BthQueryKeyValueEx(local_res10,(longlong)&local_88,&uStack_6c,4,(undefined4 *)0x0);
      if ((-1 < iVar4) && (uStack_6c < 2)) {
        uStack_34 = uStack_34 | 8;
      }
      RtlInitUnicodeString(&local_88,L"PM_AllowOutOfBandPairing");
      iVar4 = BthQueryKeyValueEx(local_res10,(longlong)&local_88,&local_68,4,(undefined4 *)0x0);
      if ((-1 < iVar4) && (local_68 < 2)) {
        uStack_34 = uStack_34 | 0x10;
      }
      RtlInitUnicodeString(&local_88,L"PM_LinkSecurityLevel");
      uVar5 = 4;
      iVar4 = BthQueryKeyValueEx(local_res10,(longlong)&local_88,&uStack_64,4,(undefined4 *)0x0);
      if ((-1 < iVar4) && (uStack_64 < 3)) {
        uStack_34 = uStack_34 | 0x20;
      }
      RtlInitUnicodeString(&local_88,L"PM_LocalDeviceName");
      iVar4 = ReadVariableLengthPolicy(local_res10,(longlong)&local_88,2,uVar5,&local_58,local_res8)
      ;
      if ((iVar4 < 0) || (0xffff < local_res8[0])) {
        if (local_58 != 0) {
          ExFreePoolWithTag(local_58,0);
          uStack_60 = 0;
          local_58 = 0;
        }
      }
      else {
        uVar2 = (ushort)local_res8[0];
        uStack_60._0_4_ = CONCAT22(uVar2,(undefined2)uStack_60);
        if (1 < uVar2) {
          uStack_34 = uStack_34 | 0x40;
          uStack_60 = CONCAT62(uStack_60._2_6_,uVar2 - 2);
        }
      }
      RtlInitUnicodeString(&local_88,L"PM_DevicesAllowedList");
      iVar4 = ReadVariableLengthPolicy
                        (local_res10,(longlong)&local_88,8,uVar5,&lStack_50,local_res8);
      if (iVar4 < 0) {
        if (lStack_50 != 0) {
          ExFreePoolWithTag(lStack_50,0);
          lStack_50 = 0;
          uStack_30 = 0;
        }
      }
      else {
        uStack_30 = local_res8[0] >> 3;
        uStack_34 = uStack_34 | 0x80;
      }
      RtlInitUnicodeString(&local_88,L"PM_ServicesAllowedList");
      iVar4 = ReadVariableLengthPolicy
                        (local_res10,(longlong)&local_88,0x10,uVar5,&local_48,local_res8);
      if (iVar4 < 0) {
        if (local_48 != 0) {
          ExFreePoolWithTag(local_48,0);
          local_48 = 0;
          uStack_2c = 0;
        }
      }
      else {
        uStack_2c = local_res8[0] >> 4;
        uStack_34 = uStack_34 | 0x100;
      }
      RtlInitUnicodeString(&local_88,L"PM_RequireRestrictedMode");
      iVar4 = BthQueryKeyValueEx(local_res10,(longlong)&local_88,&uStack_40,4,(undefined4 *)0x0);
      if ((-1 < iVar4) && (uStack_40 < 2)) {
        uStack_34 = uStack_34 | 0x200;
      }
      RtlInitUnicodeString(&local_88,L"PM_AllowPrepairing");
      iVar4 = BthQueryKeyValueEx(local_res10,(longlong)&local_88,&uStack_3c,4,(undefined4 *)0x0);
      if ((-1 < iVar4) && (uStack_3c < 2)) {
        uStack_34 = uStack_34 | 0x400;
      }
      RtlInitUnicodeString(&local_88,L"PM_SetMinimumEncryptionKeySize");
      iVar4 = BthQueryKeyValueEx(local_res10,(longlong)&local_88,&local_38,4,(undefined4 *)0x0);
      if ((-1 < iVar4) && (local_38 - 1U < 0x10)) {
        uStack_34 = uStack_34 | 0x800;
      }
      uVar1 = KeAcquireSpinLockRaiseToDpc(&g_PolicyLock);
      if (DAT_140015250 != 0) {
        ExFreePoolWithTag(DAT_140015250,0);
      }
      if (DAT_140015258 != 0) {
        ExFreePoolWithTag(DAT_140015258,0);
      }
      if (CONCAT44(DAT_140015260._4_4_,(undefined4)DAT_140015260) != 0) {
        ExFreePoolWithTag(CONCAT44(DAT_140015260._4_4_,(undefined4)DAT_140015260),0);
      }
      _g_Policies = CONCAT44(uStack_74,local_78);
      uRam0000000140015238 = CONCAT44(uStack_6c,uStack_70);
      _DAT_140015240 = CONCAT44(uStack_64,local_68);
      DAT_140015250 = local_58;
      DAT_140015258 = lStack_50;
      uRam0000000140015248 = uStack_60;
      _DAT_140015270 = local_38;
      uRam0000000140015274 = uStack_34;
      uRam0000000140015278 = uStack_30;
      DAT_14001527c = uStack_2c;
      DAT_140015260._0_4_ = (undefined4)local_48;
      DAT_140015260._4_4_ = local_48._4_4_;
      uRam0000000140015268 = uStack_40;
      uRam000000014001526c = uStack_3c;
      KeReleaseSpinLock(&g_PolicyLock,uVar1);
    }
    if (local_res10 != 0) {
      ZwClose();
    }
  }
  return iVar3;
}



===== CallbackInternal @ 1400078a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CallbackInternal(struct _EX_WNF_SUBSCRIPTION * __ptr64,struct _WNF_STATE_NAME const
   * __ptr64,unsigned long,unsigned long,struct _WNF_TYPE_ID const * __ptr64,void * __ptr64) */

long __cdecl
CallbackInternal(_EX_WNF_SUBSCRIPTION *param_1,_WNF_STATE_NAME *param_2,ulong param_3,ulong param_4,
                _WNF_TYPE_ID *param_5,void *param_6)

{
  undefined1 uVar1;
  int iVar2;
  ulong local_res20 [2];
  int local_18;
  int local_14 [3];
  
  local_14[0] = 0;
  local_18 = 4;
  local_res20[0] = param_4;
  iVar2 = ExQueryWnfStateData(param_1,local_res20,local_14,&local_18);
  if (((-1 < iVar2) && (local_18 == 4)) && (local_14[0] == 1)) {
    BthSyncWithPolicyStore();
    uVar1 = KeAcquireSpinLockRaiseToDpc(&g_CallbackLock);
    if (g_Callback != (_func_void_void_ptr *)0x0) {
      (*g_Callback)(g_CallbackContext);
    }
    KeReleaseSpinLock(&g_CallbackLock,uVar1);
  }
  return 0;
}



===== BthReportPolicyServiceBlockAudit @ 140007938 =====

undefined8 BthReportPolicyServiceBlockAudit(void)

{
  undefined8 uVar1;
  
  if ((Microsoft_Windows_Bluetooth_PolicyEnableBits & 1) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = McTemplateK0zjxzz_EtwWriteTransfer();
  }
  return uVar1;
}



===== McGenControlCallbackV2 @ 140007990 =====

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



===== McGenEventRegister_EtwRegister @ 140007aa0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (BTH_POLICY_PROVIDER_Context == 0) {
    EtwRegister(&BTH_POLICY_PROVIDER,McGenControlCallbackV2,&BTH_POLICY_PROVIDER_Context,
                &BTH_POLICY_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140007ae0 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (BTH_POLICY_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    BTH_POLICY_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140007b14 =====

void McGenEventWrite_EtwWriteTransfer(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 *in_stack_00000028;
  
  puVar1 = DAT_140015058;
  uVar2 = 0;
  if (DAT_140015058 == (ushort *)0x0) {
    *in_stack_00000028 = 0;
    uVar3 = 0;
  }
  else {
    *in_stack_00000028 = DAT_140015058;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(in_stack_00000028 + 1) = uVar3;
  *(undefined4 *)((longlong)in_stack_00000028 + 0xc) = uVar2;
  EtwWriteTransfer(BTH_POLICY_PROVIDER_Context,&_PolicyServiceBlockAudit,0,0,6);
  return;
}



===== McTemplateK0zjxzz_EtwWriteTransfer @ 140007b7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zjxzz_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *in_R9;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  wchar_t *in_stack_00000040;
  undefined1 auStack_a8 [32];
  undefined1 *local_88;
  undefined1 local_78 [16];
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar2 = -1;
  local_20 = 10;
  if (in_R9 == (wchar_t *)0x0) {
    local_60 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_R9[lVar1] != L'\0');
    local_60 = (int)lVar1 * 2 + 2;
  }
  local_48 = &uStack0000000000000030;
  if (in_R9 == (wchar_t *)0x0) {
    in_R9 = L"NULL";
  }
  local_5c = 0;
  local_50 = 0x10;
  local_40 = 8;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000038[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  local_2c = 0;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  if (in_stack_00000040 != (wchar_t *)0x0) {
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000040[lVar2] != L'\0');
    local_20 = (int)lVar2 * 2 + 2;
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  local_88 = local_78;
  local_1c = 0;
  local_68 = in_R9;
  local_38 = in_stack_00000038;
  local_28 = in_stack_00000040;
  McGenEventWrite_EtwWriteTransfer();
  return;
}



===== _guard_check_icall @ 140007ca0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140007cb8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140007cdc =====

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



===== __cpu_features_init @ 140007d50 =====

/* WARNING: Removing unreachable block (ram,0x000140007dba) */
/* WARNING: Removing unreachable block (ram,0x000140007d69) */
/* WARNING: Removing unreachable block (ram,0x000140007d5a) */

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



===== __security_check_cookie @ 140007e20 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140007e60 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007e90 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007e90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140007ec0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140007f80 =====

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



===== memset @ 140008280 =====

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



===== __memset_repmovs @ 1400083c0 =====

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



===== __memset_query @ 140008440 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400084c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140008600 =====

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



===== __memset_spec_plain @ 140008680 =====

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



===== BthEnumBuildDeviceCompatibleIds @ 140018008 =====

uint BthEnumBuildDeviceCompatibleIds(undefined8 param_1,undefined8 *param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 in_stack_ffffffffffffffe8;
  
  pwVar2 = (wchar_t *)ExAllocatePool2(0x100,0x30,0x4f4d5442);
  if (pwVar2 == (wchar_t *)0x0) {
    uVar6 = 0xc000009a;
    pwVar2 = (wchar_t *)0x0;
  }
  else {
    lVar5 = 0x18;
    pwVar4 = pwVar2;
    do {
      if ((lVar5 == -0x7fffffe6) ||
         (wVar1 = *(wchar_t *)
                   (((longlong)L"BTHENUM\\GENERIC_DEVICE" - (longlong)pwVar2) + (longlong)pwVar4),
         wVar1 == L'\0')) break;
      *pwVar4 = wVar1;
      pwVar4 = pwVar4 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    pwVar3 = pwVar4 + -1;
    if (lVar5 != 0) {
      pwVar3 = pwVar4;
    }
    *pwVar3 = L'\0';
    uVar6 = ~-(uint)(lVar5 != 0) & 0x80000005;
    if (lVar5 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,4,0x15,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,5);
      }
      ExFreePool(pwVar2);
      pwVar2 = (wchar_t *)0x0;
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar5,
                        (longlong)L"BTHENUM\\GENERIC_DEVICE" - (longlong)pwVar2,0x16,
                        in_stack_ffffffffffffffe8,pwVar2);
    }
  }
  *param_2 = pwVar2;
  return uVar6;
}



===== BthEnumBuildDeviceDeviceId @ 140018144 =====

ulonglong BthEnumBuildDeviceDeviceId(longlong param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar7;
  undefined8 uVar6;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  pwVar1 = (wchar_t *)ExAllocatePool2(0x100,0x34,0x4f4d5442);
  if (pwVar1 == (wchar_t *)0x0) {
    uVar4 = 0xc000009a;
    pwVar1 = (wchar_t *)0x0;
  }
  else {
    pwVar5 = L"BTHENUM\\Dev_%04X%08X";
    uVar3 = 0x1a;
    uVar6 = CONCAT44(uVar7,*(undefined4 *)(param_1 + 0xc0));
    uVar2 = RtlStringCchPrintfW(pwVar1,0x1a,L"BTHENUM\\Dev_%04X%08X",
                                *(ulonglong *)(param_1 + 0xc0) >> 0x20 & 0xffff);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x11,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar2);
      }
      ExFreePool(pwVar1);
      pwVar1 = (wchar_t *)0x0;
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,pwVar5,0x12,uVar6,pwVar1);
    }
  }
  *param_2 = pwVar1;
  return uVar4;
}



===== BthEnumBuildDeviceHardwareIds @ 140018260 =====

ulonglong BthEnumBuildDeviceHardwareIds(longlong param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar7;
  undefined8 uVar6;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  pwVar1 = (wchar_t *)ExAllocatePool2(0x100,0x34,0x4f4d5442);
  if (pwVar1 == (wchar_t *)0x0) {
    uVar4 = 0xc000009a;
    pwVar1 = (wchar_t *)0x0;
  }
  else {
    pwVar5 = L"BTHENUM\\Dev_%04X%08X";
    uVar3 = 0x1a;
    uVar6 = CONCAT44(uVar7,*(undefined4 *)(param_1 + 0xc0));
    uVar2 = RtlStringCchPrintfW(pwVar1,0x1a,L"BTHENUM\\Dev_%04X%08X",
                                *(ulonglong *)(param_1 + 0xc0) >> 0x20 & 0xffff);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x13,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar2);
      }
      ExFreePool(pwVar1);
      pwVar1 = (wchar_t *)0x0;
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,pwVar5,0x14,uVar6,pwVar1);
    }
  }
  *param_2 = pwVar1;
  return uVar4;
}



===== BthEnumBuildDeviceInstanceId @ 14001837c =====

ulonglong BthEnumBuildDeviceInstanceId(longlong param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  undefined *in_stack_ffffffffffffffd8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids;
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0xd,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)param_1,(char)param_2)
    ;
  }
  uVar3 = 0x3c;
  pwVar1 = (wchar_t *)ExAllocatePool2(0x100,0x3c,0x4f4d5442);
  if (pwVar1 == (wchar_t *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    pwVar5 = L"BluetoothDevice_%04X%08X";
    uVar3 = 0x1e;
    in_stack_ffffffffffffffd8 =
         (undefined *)
         CONCAT44((int)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20),
                  *(undefined4 *)(param_1 + 0xc0));
    uVar2 = RtlStringCchPrintfW(pwVar1,0x1e,L"BluetoothDevice_%04X%08X",
                                *(ulonglong *)(param_1 + 0xc0) >> 0x20 & 0xffff);
    uVar4 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,pwVar5,0xf,
                          in_stack_ffffffffffffffd8,pwVar1);
      }
      *param_2 = pwVar1;
      goto LAB_14001849e;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffffd8 = &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0xe,
                        &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar2);
    }
    ExFreePool(pwVar1);
  }
  *param_2 = 0;
LAB_14001849e:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,4,0x10,
                       in_stack_ffffffffffffffd8,(char)*param_2,(char)uVar4);
  }
  return uVar4;
}



===== BthEnumBuildL2capCompatibleIds @ 1400184f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BthEnumBuildL2capCompatibleIds(longlong param_1,undefined8 *param_2)

{
  short sVar1;
  int iVar2;
  undefined8 uVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  short *psVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong lVar13;
  longlong lVar12;
  undefined1 auStack_238 [32];
  undefined8 local_218;
  wchar_t *local_210;
  wchar_t local_208 [8];
  uint local_1f8;
  undefined2 local_1f4;
  wchar_t local_1e8 [104];
  wchar_t local_118 [104];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_238;
  uVar9 = 0;
  memset(local_1e8,0,0xca);
  local_1f8 = 0x530053;
  local_1f4 = 0;
  local_218 = *(undefined8 *)(param_1 + 0x38);
  builtin_wcsncpy(local_208,L"_HCIBYPA",8);
  if (*(int *)(param_1 + 0xb40) == 0) {
    uVar3 = RtlStringCchPrintfW(local_1e8,0x65,L"%s%s",busId);
    iVar2 = (int)uVar3;
  }
  else {
    local_210 = local_208;
    uVar3 = RtlStringCchPrintfW(local_1e8,0x65,L"%s%s%s",busId);
    iVar2 = (int)uVar3;
  }
  if (iVar2 < 0) {
    uVar8 = 0;
  }
  else {
    lVar12 = -1;
    do {
      lVar12 = lVar12 + 1;
    } while (local_1e8[lVar12] != L'\0');
    uVar8 = (int)lVar12 + 1;
  }
  memset(local_118,0,0xca);
  local_1f8 = local_1f8 & 0xffff0000;
  local_210 = local_208;
  local_218 = *(undefined8 *)(param_1 + 0x38);
  builtin_wcsncpy(local_208,L"_GENERIC",8);
  uVar3 = RtlStringCchPrintfW(local_118,0x65,L"%s%s%s",busId);
  lVar12 = -1;
  if (-1 < (int)uVar3) {
    do {
      lVar13 = lVar12;
      lVar12 = lVar13 + 1;
    } while (local_118[lVar12] != L'\0');
    uVar9 = (int)lVar13 + 2;
  }
  if ((uVar8 == 0) || (uVar9 == 0)) {
    return 0xc000000d;
  }
  psVar4 = (short *)ExAllocatePool2(0x100,(ulonglong)(uVar8 + 1 + uVar9) * 2,0x4f4d5442);
  if (psVar4 == (short *)0x0) {
    return 0;
  }
  uVar11 = (ulonglong)uVar8;
  if (uVar11 < 0x80000000) {
    psVar7 = psVar4;
    uVar10 = uVar11;
    do {
      if (((0x7ffffffe - uVar11) + uVar10 == 0) ||
         (sVar1 = *(short *)(((longlong)local_1e8 - (longlong)psVar4) + (longlong)psVar7),
         sVar1 == 0)) break;
      *psVar7 = sVar1;
      psVar7 = psVar7 + 1;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
    psVar5 = psVar7 + -1;
    if (uVar10 != 0) {
      psVar5 = psVar7;
    }
    *psVar5 = 0;
    uVar8 = ~-(uint)(uVar10 != 0) & 0x80000005;
    if ((int)uVar8 < 0) goto LAB_14001874f;
    uVar10 = (ulonglong)uVar9;
    psVar7 = psVar4 + uVar11;
    if (uVar10 < 0x80000000) {
      psVar5 = psVar7;
      uVar11 = uVar10;
      do {
        if (((0x7ffffffe - uVar10) + uVar11 == 0) ||
           (sVar1 = *(short *)(((longlong)local_118 - (longlong)psVar7) + (longlong)psVar5),
           sVar1 == 0)) break;
        *psVar5 = sVar1;
        psVar5 = psVar5 + 1;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
      psVar6 = psVar5 + -1;
      if (uVar11 != 0) {
        psVar6 = psVar5;
      }
      *psVar6 = 0;
      uVar9 = ~-(uint)(uVar11 != 0) & 0x80000005;
      if (-1 < (int)uVar9) {
        psVar7[uVar10] = 0;
        *param_2 = psVar4;
        return uVar9;
      }
    }
    else {
      *psVar7 = 0;
    }
  }
  else {
    *psVar4 = 0;
  }
  uVar8 = 0xc000000d;
LAB_14001874f:
  ExFreePool();
  return uVar8;
}



===== BthEnumBuildL2capHardwareIds @ 1400187a0 =====

undefined8 BthEnumBuildL2capHardwareIds(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  int iVar2;
  wchar_t *pwVar3;
  
  uVar1 = 0;
  pwVar3 = (wchar_t *)ExAllocatePool2(0x100,0x194,0x4f4d5442);
  if (pwVar3 == (wchar_t *)0x0) {
    return 0xc000009a;
  }
  if (((*(short *)(param_1 + 0x634) == -1) ||
      (uVar1 = BuildVidPidID(param_1,pwVar3,200), uVar1 != 0)) &&
     (iVar2 = BuildLocalMfgID(param_1,pwVar3 + uVar1,(ulonglong)(200 - uVar1)), iVar2 != 0)) {
    pwVar3[iVar2 + uVar1] = L'\0';
    *param_2 = pwVar3;
    return 0;
  }
  ExFreePool(pwVar3);
  return 0xc000000d;
}



===== BthEnumBuildL2capInstanceId @ 140018870 =====

int BthEnumBuildL2capInstanceId(longlong param_1,undefined8 *param_2)

{
  short sVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  wchar_t *pwVar6;
  short *in_stack_ffffffffffffffc8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffc8 = (short *)&WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids;
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,10,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)param_1,(char)param_2)
    ;
  }
  uVar5 = 0x21e;
  pwVar3 = (wchar_t *)ExAllocatePool2(0x100,0x21e,0x4f4d5442);
  if (pwVar3 == (wchar_t *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    uVar5 = 0x21e;
    sVar1 = *(short *)(param_1 + 0x434);
    if (sVar1 == 0x4c) {
      pwVar6 = L"%s";
      uVar4 = RtlStringCbPrintfW(pwVar3,0x21e,L"%s",param_1 + 0x18);
      iVar2 = (int)uVar4;
    }
    else {
      if (sVar1 == 0) {
        pwVar6 = L"%s_%08X";
        in_stack_ffffffffffffffc8 =
             (short *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20),
                               (uint)*(byte *)(param_1 + 0x430));
      }
      else {
        pwVar6 = L"%s_%s";
        in_stack_ffffffffffffffc8 = (short *)(param_1 + 0x434);
      }
      uVar4 = RtlStringCbPrintfW(pwVar3,0x21e,pwVar6,param_1 + 0x18);
      iVar2 = (int)uVar4;
    }
    if (-1 < iVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,pwVar6,0xb,
                          in_stack_ffffffffffffffc8,pwVar3);
      }
      goto LAB_140018992;
    }
    ExFreePool(pwVar3);
  }
  pwVar3 = (wchar_t *)0x0;
LAB_140018992:
  *param_2 = pwVar3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,4,0xc,
                       in_stack_ffffffffffffffc8,(char)pwVar3,(char)iVar2);
  }
  return iVar2;
}



===== BthEnumForwardQueryInterface @ 1400189e4 =====

int BthEnumForwardQueryInterface(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  int iVar10;
  
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 8);
  lVar2 = *(longlong *)(lVar9 + 0x40);
  lVar9 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar9 >> 8),
                                 *(char *)(*(longlong *)(lVar2 + 0x18) + 0x4c) + '\x01'),0);
  iVar10 = -0x3fffff66;
  if (lVar9 != 0) {
    lVar3 = *(longlong *)(lVar9 + 0xb8);
    iVar1 = *(int *)(param_2 + 0x30);
    *(char *)(lVar9 + 0x43) = *(char *)(lVar9 + 0x43) + -1;
    *(longlong *)(lVar9 + 0xb8) = lVar3 + -0x48;
    puVar4 = *(undefined1 **)(param_2 + 0xb8);
    *(undefined1 *)(lVar3 + -0x90) = *puVar4;
    *(undefined1 *)(lVar3 + -0x8f) = puVar4[1];
    uVar8 = *(undefined8 *)(puVar4 + 0x10);
    *(undefined8 *)(lVar3 + -0x88) = *(undefined8 *)(puVar4 + 8);
    *(undefined8 *)(lVar3 + -0x80) = uVar8;
    uVar8 = *(undefined8 *)(puVar4 + 0x20);
    *(undefined8 *)(lVar3 + -0x78) = *(undefined8 *)(puVar4 + 0x18);
    *(undefined8 *)(lVar3 + -0x70) = uVar8;
    *(undefined4 *)(lVar9 + 0x30) = 0xc00000bb;
    *(undefined8 *)(lVar9 + 0x38) = *(undefined8 *)(param_2 + 0x38);
    WaitForLowerDriverToCompleteIrp(*(undefined8 *)(lVar2 + 0x18),lVar9,'\0');
    lVar2 = *(longlong *)(lVar9 + 0xb8);
    uVar5 = *(undefined4 *)(lVar2 + -0x3c);
    uVar6 = *(undefined4 *)(lVar2 + -0x38);
    uVar7 = *(undefined4 *)(lVar2 + -0x34);
    *(undefined4 *)(puVar4 + 8) = *(undefined4 *)(lVar2 + -0x40);
    *(undefined4 *)(puVar4 + 0xc) = uVar5;
    *(undefined4 *)(puVar4 + 0x10) = uVar6;
    *(undefined4 *)(puVar4 + 0x14) = uVar7;
    uVar5 = *(undefined4 *)(lVar2 + -0x2c);
    uVar6 = *(undefined4 *)(lVar2 + -0x28);
    uVar7 = *(undefined4 *)(lVar2 + -0x24);
    *(undefined4 *)(puVar4 + 0x18) = *(undefined4 *)(lVar2 + -0x30);
    *(undefined4 *)(puVar4 + 0x1c) = uVar5;
    *(undefined4 *)(puVar4 + 0x20) = uVar6;
    *(undefined4 *)(puVar4 + 0x24) = uVar7;
    iVar10 = *(int *)(lVar9 + 0x30);
    *(undefined8 *)(param_2 + 0x38) = *(undefined8 *)(lVar9 + 0x38);
    IoFreeIrp(lVar9);
    if (iVar10 == -0x3fffff45) {
      iVar10 = iVar1;
    }
  }
  *(int *)(param_2 + 0x30) = iVar10;
  return iVar10;
}



===== BthEnumGenerateAepDeviceAddress @ 140018aec =====

ulonglong BthEnumGenerateAepDeviceAddress(ulonglong param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  *param_2 = 0;
  uVar3 = 0x24;
  pwVar1 = (wchar_t *)ExAllocatePool2(0x100,0x24,0x4f4d5442);
  if (pwVar1 == (wchar_t *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,3,0x1c,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
    }
    uVar4 = 0xc000009a;
  }
  else {
    uVar3 = 0x12;
    uVar2 = RtlStringCchPrintfW(pwVar1,0x12,L"%02.2x:%02.2x:%02.2x:%02.2x:%02.2x:%02.2x",
                                param_1 >> 0x28 & 0xff);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,3,0x1d,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar2);
      }
      ExFreePool(pwVar1);
    }
    else {
      *param_2 = pwVar1;
    }
  }
  return uVar4;
}



===== BthEnumGenerateAepId @ 140018c38 =====

ulonglong BthEnumGenerateAepId(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  wchar_t *pwVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  lVar1 = *(longlong *)(param_1 + 8);
  *param_2 = 0;
  uVar4 = 0x6e;
  lVar1 = *(longlong *)(lVar1 + 0x40);
  pwVar2 = (wchar_t *)ExAllocatePool2(0x100,0x6e,0x4f4d5442);
  if (pwVar2 == (wchar_t *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,3,0x18,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
    }
    uVar5 = 0xc000009a;
  }
  else {
    uVar4 = 0x37;
    uVar3 = RtlStringCchPrintfW(pwVar2,0x37,
                                L"Bluetooth#Bluetooth%02.2x:%02.2x:%02.2x:%02.2x:%02.2x:%02.2x-%02.2x:%02.2x:%02.2x:%02.2x:%02.2x:%02.2x"
                                ,*(ulonglong *)(lVar1 + 0x140) >> 0x28 & 0xff);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,3,0x19,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar3);
      }
      ExFreePool(pwVar2);
    }
    else {
      *param_2 = pwVar2;
    }
  }
  return uVar5;
}



===== BthEnumGenerateRfcommAepServiceId @ 140018e14 =====

ulonglong BthEnumGenerateRfcommAepServiceId(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  wchar_t *pwVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  lVar1 = *(longlong *)(param_1 + 8);
  *param_2 = 0;
  uVar4 = 0xdc;
  lVar1 = *(longlong *)(lVar1 + 0x40);
  pwVar2 = (wchar_t *)ExAllocatePool2(0x100,0xdc,0x4f4d5442);
  if (pwVar2 == (wchar_t *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,3,0x1a,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
    }
    uVar5 = 0xc000009a;
  }
  else {
    uVar4 = 0x6e;
    uVar3 = RtlStringCchPrintfW(pwVar2,0x6e,
                                L"Bluetooth#Bluetooth%02.2x:%02.2x:%02.2x:%02.2x:%02.2x:%02.2x-%02.2x:%02.2x:%02.2x:%02.2x:%02.2x:%02.2x#RFCOMM:%08.8lx:{%08.8lx-%04.4hx-%04.4hx-%02.2hhx%02.2hhx-%02.2hhx%02.2hhx%02.2hhx%02.2hhx%02.2hhx%02.2hhx}"
                                ,*(ulonglong *)(lVar1 + 0x140) >> 0x28 & 0xff);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,3,0x1b,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar3);
      }
      ExFreePool(pwVar2);
    }
    else {
      *param_2 = pwVar2;
    }
  }
  return uVar5;
}



===== BthEnumPdoPnp @ 140019114 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BthEnumPdoPnp(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte bVar2;
  short sVar3;
  wchar_t wVar4;
  int *piVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  longlong lVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  wchar_t *pwVar16;
  short *psVar17;
  undefined8 *puVar18;
  undefined8 *puVar19;
  wchar_t *pwVar20;
  void *pvVar21;
  longlong lVar22;
  undefined8 *puVar23;
  undefined8 *puVar24;
  wchar_t *pwVar25;
  ulonglong uVar26;
  longlong *plVar27;
  longlong *plVar28;
  undefined *puVar29;
  short *psVar30;
  ulonglong uVar31;
  uint uVar32;
  undefined2 uVar33;
  longlong lVar34;
  undefined1 auStackY_3f8 [32];
  undefined8 in_stack_fffffffffffffc28;
  undefined4 uVar35;
  undefined1 uVar36;
  wchar_t *local_3a8;
  longlong local_3a0 [3];
  longlong local_388;
  wchar_t *pwStack_380;
  undefined8 local_378 [2];
  undefined8 local_368;
  bool bStack_360;
  undefined8 uStack_35c;
  undefined8 uStack_354;
  bool bStack_34c;
  short asStack_34a [256];
  undefined8 local_14a [32];
  ulonglong local_48;
  
  uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffc28 >> 0x20);
  local_48 = __security_cookie ^ (ulonglong)auStackY_3f8;
  piVar5 = *(int **)(param_1 + 0x40);
  lVar12 = *(longlong *)(param_2 + 0xb8);
  uVar32 = *(uint *)(param_2 + 0x30);
  local_3a8 = (wchar_t *)0x0;
  local_378[0] = 0;
  bVar2 = *(byte *)(lVar12 + 1);
  local_3a0[0] = *(longlong *)(*(longlong *)(piVar5 + 2) + 0x40);
  uVar36 = (undefined1)param_1;
  if (bVar2 < 9) {
    if (bVar2 == 8) {
      uVar32 = BthEnumForwardQueryInterface(param_1,param_2);
      goto LAB_140019268;
    }
    if (bVar2 != 0) {
      if (bVar2 == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar33 = 0x4b;
          goto LAB_1400192dc;
        }
      }
      else {
        if (bVar2 == 2) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar35 = 1;
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x4d,
                              &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,uVar36);
          }
          lVar12 = local_3a0[0];
          if (*(longlong *)(piVar5 + 0x30) != 0) {
            uVar13 = CONCAT44(uVar35,0x11);
            uVar32 = IoSetDevicePropertyData
                               (param_1,&DEVPKEY_DeviceContainer_AlwaysShowDeviceAsConnected,0,0);
            if ((((uVar32 + 0x80000000 & 0x80000000) == 0) && (uVar32 != 0xc0000034)) &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar32,3,0x4e
                                 ,uVar13,uVar36,(char)uVar32);
            }
          }
          BthEnumUpdateProfileConnectionCountKey((longlong)piVar5);
          BthEnumDeleteProtocol(lVar12,(longlong)piVar5);
          uVar32 = 0;
          goto LAB_140019268;
        }
        if (bVar2 == 3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar33 = 0x4f;
            goto LAB_1400192dc;
          }
        }
        else {
          if (bVar2 == 4) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x4a,
                               &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
            }
            if ((*piVar5 == 0x4f445054) ||
               ((*piVar5 == 0x204f4450 &&
                (lVar12 = RtlCompareMemory(piVar5 + 0x108,&SerialPortServiceClass_UUID,0x10),
                lVar12 == 0x10)))) {
              BthEnumUnregisterDeviceInterface((longlong)piVar5,'\0');
            }
            uVar32 = 0;
            goto LAB_140019268;
          }
          if (bVar2 == 5) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar33 = 0x48;
LAB_1400192dc:
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,uVar33,
                               &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
            }
          }
          else {
            if (bVar2 != 6) {
              if (bVar2 != 7) goto LAB_140019268;
              lVar22 = param_2;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x61,
                                 &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
              }
              if (*(int *)(lVar12 + 8) != 4) goto LAB_140019268;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar22,3,0x62,
                                 &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
              }
              puVar11 = (undefined4 *)ExAllocatePool2(0x100,0x10,0x4f4d5442);
              if (puVar11 == (undefined4 *)0x0) {
                uVar32 = 0xc000009a;
                goto LAB_140019268;
              }
              *puVar11 = 1;
              *(undefined8 *)(puVar11 + 2) = *(undefined8 *)(piVar5 + 4);
              ObfReferenceObject(*(undefined8 *)(piVar5 + 4));
              goto LAB_1400192a3;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar33 = 0x49;
              goto LAB_1400192dc;
            }
          }
        }
      }
      uVar32 = 0;
      goto LAB_140019268;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x3f,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
    }
    uVar32 = 0;
    piVar5[0x2d] = 1;
    if ((*piVar5 == 0x4f445054) ||
       ((*piVar5 == 0x204f4450 &&
        (lVar12 = RtlCompareMemory(piVar5 + 0x108,&SerialPortServiceClass_UUID,0x10), lVar12 == 0x10
        )))) {
      plVar27 = (longlong *)(piVar5 + 0x108);
      uVar13 = BthServiceAllowedByPolicy(plVar27);
      local_388 = *plVar27;
      pwStack_380 = *(wchar_t **)(piVar5 + 0x10a);
      plVar28 = &local_388;
      uVar14 = BthReportPolicyServiceBlockAudit();
      if (((int)uVar14 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
         ) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar28,4,0x40,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar14);
      }
      if ((int)uVar13 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar28,4,
                            (short)uVar13 + 0x41,&WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,
                            (char)*plVar27);
        }
        uVar32 = 0xc0000361;
        goto LAB_140019268;
      }
      if ((*(longlong *)(piVar5 + 0x2d4) == 0) &&
         (uVar32 = IoRegisterDeviceInterface(*(undefined8 *)(piVar5 + 4),plVar27,0,piVar5 + 0x2d2),
         (int)uVar32 < 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar33 = 0x42;
LAB_14001970f:
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar27,4,uVar33,
                            &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar32);
        }
      }
      else {
        uVar32 = IoSetDeviceInterfaceState(piVar5 + 0x2d2,1);
        if ((-1 < (int)uVar32) && ((piVar5[0x107] & 0x10000U) != 0)) {
          if (*(longlong *)(piVar5 + 0x2d8) == 0) {
            plVar27 = (longlong *)&GUID_BTH_RFCOMM_SERVICE_DEVICE_INTERFACE;
            uVar32 = IoRegisterDeviceInterface
                               (*(undefined8 *)(piVar5 + 4),
                                &GUID_BTH_RFCOMM_SERVICE_DEVICE_INTERFACE,0,piVar5 + 0x2d6);
            if ((int)uVar32 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar33 = 0x43;
                goto LAB_14001970f;
              }
              goto LAB_140019869;
            }
          }
          uVar32 = IoSetDeviceInterfaceState(piVar5 + 0x2d6,1);
          if (-1 < (int)uVar32) {
            piVar1 = piVar5 + 0x2d6;
            BthEnumSetPdoInterfaceProperties((longlong)piVar5,piVar1);
            puVar29 = &DEVPKEY_Bluetooth_ServiceGUID;
            iVar9 = IoSetDeviceInterfacePropertyData(piVar1,&DEVPKEY_Bluetooth_ServiceGUID,0,0);
            if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
               ) {
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x44,
                                &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar9);
            }
            plVar27 = local_3a0;
            local_3a0[0] = 0;
            uVar15 = BthEnumGenerateRfcommAepServiceId((longlong)piVar5,plVar27);
            lVar12 = local_3a0[0];
            uVar32 = (uint)uVar15;
            if ((int)uVar32 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar33 = 0x46;
                goto LAB_140019839;
              }
            }
            else {
              plVar27 = (longlong *)&DEVPKEY_AepService_ServiceId;
              uVar32 = IoSetDeviceInterfacePropertyData(piVar1,&DEVPKEY_AepService_ServiceId,0,0);
              if (((int)uVar32 < 0) &&
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                uVar33 = 0x45;
LAB_140019839:
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar27,3,uVar33,
                                  &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar32);
              }
            }
            if (lVar12 != 0) {
              ExFreePool(lVar12);
            }
          }
        }
      }
    }
    else if (*piVar5 == 0x4f445044) {
      if (*(longlong *)(piVar5 + 0x2d4) == 0) {
        plVar27 = (longlong *)&GUID_BTH_DEVICE_INTERFACE;
        uVar32 = IoRegisterDeviceInterface
                           (*(undefined8 *)(piVar5 + 4),&GUID_BTH_DEVICE_INTERFACE,0,piVar5 + 0x2d2)
        ;
        if ((int)uVar32 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar33 = 0x47;
            goto LAB_14001970f;
          }
          goto LAB_140019869;
        }
      }
      uVar32 = IoSetDeviceInterfaceState(piVar5 + 0x2d2,1);
      if (-1 < (int)uVar32) {
        BthEnumSetPdoInterfaceProperties((longlong)piVar5,piVar5 + 0x2d2);
      }
    }
LAB_140019869:
    iVar9 = BthEnumGetConnectionCountKey((longlong)piVar5);
    piVar5[0x2db] = iVar9;
    goto LAB_140019268;
  }
  if (bVar2 == 9) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x3d,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
    }
    if (*piVar5 != 0x4f445044) {
      lVar22 = *(longlong *)(*(longlong *)(*(longlong *)(piVar5 + 2) + 0x40) + 0x78);
      if (lVar22 != 0) {
        uVar32 = *(uint *)(*(longlong *)(*(longlong *)(piVar5 + 2) + 0x40) + 0x80);
        uVar10 = 0;
        if (uVar32 != 0) {
          do {
            if ((*(uint *)(lVar22 + (ulonglong)uVar10 * 8) & piVar5[0x32]) ==
                *(uint *)(lVar22 + 4 + (ulonglong)uVar10 * 8)) {
              uVar32 = WaitForLowerDriverToCompleteIrp
                                 (*(undefined8 *)(local_3a0[0] + 0x18),param_2,'\x01');
              if (-1 < (int)uVar32) goto LAB_14001a8b3;
              break;
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar32);
        }
      }
    }
    uVar13 = BthEnumSetDefaultCapabilities(lVar12,piVar5);
    uVar32 = (uint)uVar13;
LAB_14001a8b3:
    puVar18 = *(undefined8 **)(lVar12 + 8);
    lVar12 = *(longlong *)(param_1 + 0x40);
    uVar13 = puVar18[1];
    *(undefined8 *)(lVar12 + 0x68) = *puVar18;
    *(undefined8 *)(lVar12 + 0x70) = uVar13;
    uVar13 = puVar18[3];
    *(undefined8 *)(lVar12 + 0x78) = puVar18[2];
    *(undefined8 *)(lVar12 + 0x80) = uVar13;
    uVar13 = puVar18[5];
    *(undefined8 *)(lVar12 + 0x88) = puVar18[4];
    *(undefined8 *)(lVar12 + 0x90) = uVar13;
    uVar13 = puVar18[7];
    *(undefined8 *)(lVar12 + 0x98) = puVar18[6];
    *(undefined8 *)(lVar12 + 0xa0) = uVar13;
    goto LAB_140019268;
  }
  if (bVar2 == 10) {
    lVar12 = RtlCompareMemory(piVar5 + 0x108,&SerialPortServiceClass_UUID,0x10);
    if ((lVar12 == 0x10) && (*(short *)((longlong)piVar5 + 0x93e) != 0)) {
      local_3a0[0] = 0;
      local_3a0[1] = 0;
      pvVar21 = (void *)ExAllocatePool2(0x100,0x200,0x4f4d5442);
      if (pvVar21 != (void *)0x0) {
        iVar9 = IoOpenDeviceRegistryKey(param_1,1,0x20000,local_378);
        uVar13 = local_378[0];
        if (-1 < iVar9) {
          local_388 = 0;
          pwStack_380 = (wchar_t *)0x0;
          RtlInitUnicodeString(&local_388,L"PortName");
          iVar9 = BthQueryKeyValueEx(uVar13,(longlong)&local_388,pvVar21,0x200,(undefined4 *)0x0);
          if ((iVar9 < 0) || ((piVar5[0x107] & 4U) != 0)) {
            RtlInitUnicodeString(local_3a0,L"PortName");
            lVar12 = -1;
            do {
              lVar12 = lVar12 + 1;
            } while (((short *)((longlong)piVar5 + 0x93e))[lVar12] != 0);
            ZwSetValueKey(local_378[0],local_3a0,0,1);
          }
          ZwClose(local_378[0]);
        }
        ExFreePool(pvVar21);
      }
    }
    goto LAB_140019268;
  }
  if (bVar2 != 0xc) {
    if (bVar2 == 0xf) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x50,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,
                          (char)*(undefined4 *)(lVar12 + 8));
      }
      if (*(int *)(lVar12 + 8) != 0) goto LAB_140019268;
      puVar11 = (undefined4 *)0x320;
      if (*(uint *)(lVar12 + 0x20) < 800) {
        uVar32 = 0xc0000023;
        goto LAB_140019268;
      }
      memset(&local_368,0,800);
      psVar30 = asStack_34a;
      local_368 = *(undefined8 *)(piVar5 + 0x30);
      bStack_360 = piVar5[0x106] != -1;
      lVar22 = 0x100;
      uStack_35c = *(undefined8 *)(piVar5 + 0x108);
      uStack_354 = *(undefined8 *)(piVar5 + 0x10a);
      do {
        if ((lVar22 == -0x7ffffefe) ||
           (sVar3 = *(short *)((longlong)psVar30 +
                              (longlong)piVar5 + (0x63e - (longlong)asStack_34a)), sVar3 == 0))
        break;
        *psVar30 = sVar3;
        psVar30 = psVar30 + 1;
        lVar22 = lVar22 + -1;
      } while (lVar22 != 0);
      psVar17 = psVar30 + -1;
      if (lVar22 != 0) {
        psVar17 = psVar30;
      }
      *psVar17 = 0;
      uVar32 = ~-(uint)(lVar22 != 0) & 0x80000005;
      if (lVar22 == 0) goto LAB_140019268;
      puVar18 = (undefined8 *)((longlong)piVar5 + 0x83e);
      puVar23 = local_14a;
      lVar22 = 2;
      do {
        lVar34 = lVar22;
        uVar13 = puVar18[1];
        uVar14 = puVar18[2];
        uVar6 = puVar18[3];
        *puVar23 = *puVar18;
        puVar23[1] = uVar13;
        uVar13 = puVar18[4];
        uVar7 = puVar18[5];
        puVar23[2] = uVar14;
        puVar23[3] = uVar6;
        uVar14 = puVar18[6];
        uVar6 = puVar18[7];
        puVar23[4] = uVar13;
        puVar23[5] = uVar7;
        uVar13 = puVar18[8];
        uVar7 = puVar18[9];
        puVar23[6] = uVar14;
        puVar23[7] = uVar6;
        uVar14 = puVar18[10];
        uVar6 = puVar18[0xb];
        puVar23[8] = uVar13;
        puVar23[9] = uVar7;
        uVar13 = puVar18[0xc];
        uVar7 = puVar18[0xd];
        puVar23[10] = uVar14;
        puVar23[0xb] = uVar6;
        uVar14 = puVar18[0xe];
        uVar6 = puVar18[0xf];
        puVar18 = puVar18 + 0x10;
        puVar23[0xc] = uVar13;
        puVar23[0xd] = uVar7;
        puVar23[0xe] = uVar14;
        puVar23[0xf] = uVar6;
        puVar23 = puVar23 + 0x10;
        lVar22 = lVar34 + -1;
      } while (lVar34 + -1 != 0);
      uVar15 = (ulonglong)((int)lVar34 + 5);
      bStack_34c = (short)piVar5[0x10d] == (short)((short)lVar34 + 0x4b);
      puVar18 = *(undefined8 **)(lVar12 + 0x10);
      puVar23 = &local_368;
      do {
        puVar24 = puVar23;
        puVar19 = puVar18;
        uVar13 = puVar24[1];
        uVar14 = puVar24[2];
        uVar6 = puVar24[3];
        *puVar19 = *puVar24;
        puVar19[1] = uVar13;
        uVar13 = puVar24[4];
        uVar7 = puVar24[5];
        puVar19[2] = uVar14;
        puVar19[3] = uVar6;
        uVar14 = puVar24[6];
        uVar6 = puVar24[7];
        puVar19[4] = uVar13;
        puVar19[5] = uVar7;
        uVar13 = puVar24[8];
        uVar7 = puVar24[9];
        puVar19[6] = uVar14;
        puVar19[7] = uVar6;
        uVar14 = puVar24[10];
        uVar6 = puVar24[0xb];
        puVar19[8] = uVar13;
        puVar19[9] = uVar7;
        uVar13 = puVar24[0xc];
        uVar7 = puVar24[0xd];
        puVar19[10] = uVar14;
        puVar19[0xb] = uVar6;
        uVar14 = puVar24[0xe];
        uVar6 = puVar24[0xf];
        puVar19[0xc] = uVar13;
        puVar19[0xd] = uVar7;
        puVar19[0xe] = uVar14;
        puVar19[0xf] = uVar6;
        uVar15 = uVar15 - 1;
        puVar18 = puVar19 + 0x10;
        puVar23 = puVar24 + 0x10;
      } while (uVar15 != 0);
      uVar13 = puVar24[0x11];
      uVar14 = puVar24[0x12];
      uVar6 = puVar24[0x13];
      puVar19[0x10] = puVar24[0x10];
      puVar19[0x11] = uVar13;
      puVar19[0x12] = uVar14;
      puVar19[0x13] = uVar6;
LAB_1400192a3:
      uVar32 = 0;
      *(undefined4 **)(param_2 + 0x38) = puVar11;
      goto LAB_140019268;
    }
    if (bVar2 != 0x13) {
      if (bVar2 == 0x14) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,99,
                           &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
        }
        if (*piVar5 == 0x4f445044) {
          KeEnterCriticalRegion();
          lVar12 = local_3a0[0];
          ExAcquireFastMutexUnsafe(local_3a0[0] + 0x98);
          uVar32 = 0;
          uVar10 = *(uint *)(param_2 + 0x38) | 0x40;
          if ((piVar5[0x2e] & 0x20U) != 0) {
            uVar10 = *(uint *)(param_2 + 0x38) & 0xffffffbf;
          }
          *(uint *)(param_2 + 0x38) = uVar10;
          ExReleaseFastMutexUnsafe(lVar12 + 0x98);
          KeLeaveCriticalRegion();
        }
        goto LAB_140019268;
      }
      if (bVar2 == 0x17) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x4c,
                           &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
        }
        uVar32 = BthEnumUnregisterDeviceInterface((longlong)piVar5,'\0');
        goto LAB_140019268;
      }
      if (bVar2 != 0x19) goto LAB_140019268;
      lVar22 = param_2;
      KeEnterCriticalRegion();
      lVar12 = local_3a0[0];
      ExAcquireFastMutexUnsafe(local_3a0[0] + 0x98);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar35 = 1;
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar22,3,0x51,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,uVar36);
      }
      BthEnumUpdateDeviceKey((longlong)piVar5);
      if (*piVar5 == 0x4f445044) {
        uVar13 = CONCAT71((int7)((ulonglong)lVar22 >> 8),1);
        uVar15 = BthEnumSetDevicePdoProperties((longlong)piVar5,uVar13);
        uVar32 = (uint)uVar15;
        if (-1 < (int)uVar32) goto LAB_140019ac7;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar13,3,0x52,
                            &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar15);
        }
      }
      else {
        puVar29 = &DEVPKEY_Device_PresenceNotForDevice;
        uVar13 = CONCAT44(uVar35,0x11);
        iVar9 = IoSetDevicePropertyData(param_1,&DEVPKEY_Device_PresenceNotForDevice,0,0);
        if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x53,uVar13,uVar36
                             ,(char)iVar9);
        }
        uVar35 = (undefined4)((ulonglong)uVar13 >> 0x20);
        plVar27 = &local_388;
        local_388 = 0;
        uVar15 = BthEnumGenerateAepId((longlong)piVar5,plVar27);
        lVar12 = local_388;
        iVar9 = (int)uVar15;
        if (iVar9 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar33 = 0x55;
            goto LAB_140019a8f;
          }
        }
        else {
          plVar27 = (longlong *)&DEVPKEY_Aep_AepId;
          iVar9 = IoSetDevicePropertyData(param_1,&DEVPKEY_Aep_AepId,0,0);
          if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            uVar33 = 0x54;
LAB_140019a8f:
            uVar35 = 1;
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar27,3,uVar33,
                              &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar9);
          }
        }
        if (lVar12 != 0) {
          ExFreePool(lVar12);
        }
LAB_140019ac7:
        puVar29 = &DEVPKEY_Bluetooth_ServiceGUID;
        uVar13 = CONCAT44(uVar35,0xd);
        uVar32 = IoSetDevicePropertyData(param_1,&DEVPKEY_Bluetooth_ServiceGUID,0,0);
        if (((int)uVar32 < 0) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x56,uVar13,uVar36
                             ,(char)uVar32);
        }
        if (*(longlong *)(piVar5 + 0x30) != 0) {
          puVar29 = &DEVPKEY_DeviceContainer_AlwaysShowDeviceAsConnected;
          uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),0x11);
          iVar9 = IoSetDevicePropertyData
                            (param_1,&DEVPKEY_DeviceContainer_AlwaysShowDeviceAsConnected,0,0);
          if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x57,uVar13,
                               uVar36,(char)iVar9);
          }
          puVar29 = &DEVPKEY_DeviceContainer_UnpairUninstall;
          uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),0x11);
          iVar9 = IoSetDevicePropertyData(param_1,&DEVPKEY_DeviceContainer_UnpairUninstall,0,0);
          if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x58,uVar13,
                               uVar36,(char)iVar9);
          }
          puVar29 = &DEVPKEY_Bluetooth_DeviceAddress;
          uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),0x12);
          iVar9 = IoSetDevicePropertyData(param_1,&DEVPKEY_Bluetooth_DeviceAddress,0,0);
          if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x59,uVar13,
                               uVar36,(char)iVar9);
          }
          puVar29 = &DEVPKEY_Bluetooth_DeviceFlags;
          uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),7);
          iVar9 = IoSetDevicePropertyData(param_1,&DEVPKEY_Bluetooth_DeviceFlags,0,0);
          if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x5a,uVar13,
                               uVar36,(char)iVar9);
          }
          puVar29 = &DEVPKEY_Bluetooth_ClassOfDevice;
          uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),7);
          iVar9 = IoSetDevicePropertyData(param_1,&DEVPKEY_Bluetooth_ClassOfDevice,0,0);
          if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x5b,uVar13,
                               uVar36,(char)iVar9);
          }
          puVar29 = &DEVPKEY_Bluetooth_ClassOfDevice_Deprecated;
          uVar14 = 0;
          uVar35 = (undefined4)((ulonglong)uVar13 >> 0x20);
          uVar32 = IoSetDevicePropertyData(param_1,&DEVPKEY_Bluetooth_ClassOfDevice_Deprecated,0,0);
          if (((int)uVar32 < 0) &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar35 = 1;
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,uVar14,0x5c,
                               &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,uVar36,(char)uVar32)
            ;
          }
          if ((piVar5[0x2e] & 0x8000000U) != 0) {
            puVar29 = &DEVPKEY_Bluetooth_SecureConnectionPaired;
            uVar32 = IoSetDevicePropertyData(param_1,&DEVPKEY_Bluetooth_SecureConnectionPaired,0,0);
            if (((int)uVar32 < 0) &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar35 = 1;
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x5d,
                                &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar32);
            }
          }
          if ((short)piVar5[399] != 0) {
            puVar29 = &DEVPKEY_Bluetooth_DeviceVIDSource;
            uVar13 = CONCAT44(uVar35,3);
            iVar9 = IoSetDevicePropertyData(param_1,&DEVPKEY_Bluetooth_DeviceVIDSource,0,0);
            if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
               ) {
              WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x5e,uVar13,
                                 uVar36,(char)iVar9);
            }
            puVar29 = &DEVPKEY_Bluetooth_DeviceVID;
            uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),5);
            iVar9 = IoSetDevicePropertyData(param_1,&DEVPKEY_Bluetooth_DeviceVID,0,0);
            if ((iVar9 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
               ) {
              WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x5f,uVar13,
                                 uVar36,(char)iVar9);
            }
            puVar29 = &DEVPKEY_Bluetooth_DevicePID;
            uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),5);
            uVar32 = IoSetDevicePropertyData(param_1,&DEVPKEY_Bluetooth_DevicePID,0,0);
            if (((int)uVar32 < 0) &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar29,3,0x60,uVar13,
                                 uVar36,(char)uVar32);
            }
          }
        }
        *(undefined1 *)(piVar5 + 0x2da) = 1;
        lVar12 = local_3a0[0];
      }
      ExReleaseFastMutexUnsafe(lVar12 + 0x98);
      KeLeaveCriticalRegion();
      goto LAB_140019268;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x3e,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
    }
    iVar9 = *(int *)(lVar12 + 8);
    if (iVar9 == 0) {
      iVar9 = piVar5[0x104];
      if ((iVar9 == 0) || (iVar9 == 1)) {
        uVar32 = 0;
        pwVar16 = (wchar_t *)ExAllocatePool2(0x100,0xca,0x4f4d5442);
        if (pwVar16 == (wchar_t *)0x0) {
          uVar32 = 0xc000009a;
        }
        else {
          if ((short)piVar5[0x18d] == -1) {
            uVar10 = BuildLocalMfgID((longlong)piVar5,pwVar16,100);
          }
          else {
            uVar10 = BuildVidPidID((longlong)piVar5,pwVar16,100);
          }
          if (uVar10 == 0) {
            uVar32 = 0xc000000d;
            ExFreePool(pwVar16);
          }
          else {
            pwVar16[uVar10] = L'\0';
            local_3a8 = pwVar16;
          }
        }
      }
      else if (iVar9 == 2) {
        uVar15 = BthEnumBuildDeviceDeviceId((longlong)piVar5,&local_3a8);
        uVar32 = (uint)uVar15;
        goto LAB_14001a24b;
      }
      goto LAB_14001a2ca;
    }
    if (iVar9 == 1) {
      iVar9 = piVar5[0x104];
      if ((iVar9 == 0) || (iVar9 == 1)) {
        uVar13 = BthEnumBuildL2capHardwareIds((longlong)piVar5,&local_3a8);
        uVar32 = (uint)uVar13;
      }
      else {
        if (iVar9 != 2) goto LAB_14001a2ca;
        uVar15 = BthEnumBuildDeviceHardwareIds((longlong)piVar5,&local_3a8);
        uVar32 = (uint)uVar15;
      }
LAB_14001a24b:
    }
    else {
      if (iVar9 == 2) {
        iVar9 = piVar5[0x104];
        if ((iVar9 == 0) || (iVar9 == 1)) {
          uVar32 = BthEnumBuildL2capCompatibleIds((longlong)piVar5,&local_3a8);
        }
        else {
          if (iVar9 != 2) goto LAB_14001a2ca;
          uVar32 = BthEnumBuildDeviceCompatibleIds(1,&local_3a8);
        }
        goto LAB_14001a24b;
      }
      if (iVar9 == 3) {
        iVar9 = piVar5[0x104];
        if ((iVar9 == 0) || (iVar9 == 1)) {
          uVar32 = BthEnumBuildL2capInstanceId((longlong)piVar5,&local_3a8);
        }
        else {
          if (iVar9 != 2) goto LAB_14001a2ca;
          uVar15 = BthEnumBuildDeviceInstanceId((longlong)piVar5,&local_3a8);
          uVar32 = (uint)uVar15;
        }
        goto LAB_14001a24b;
      }
      if (((iVar9 != 5) || (*(longlong *)(piVar5 + 0x30) == 0)) ||
         (((piVar5[0x32] & 0x1f00U) == 0x100 &&
          (lVar12 = RtlCompareMemory(&HCRPrintServiceClass_UUID,piVar5 + 0x108,0x10), lVar12 == 0x10
          )))) goto LAB_140019268;
      local_388 = 0;
      pwStack_380 = (wchar_t *)0x0;
      RtlInitUnicodeString(&local_388,0);
      uVar32 = RtlStringFromGUID(piVar5 + 0x75,&local_388);
      if (-1 < (int)uVar32) {
        local_3a8 = pwStack_380;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_iS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
    }
LAB_14001a2ca:
    *(wchar_t **)(param_2 + 0x38) = local_3a8;
    goto LAB_140019268;
  }
  if (*(int *)(lVar12 + 8) != 0) goto LAB_140019268;
  if (*(longlong *)(piVar5 + 0x12) == 0) {
LAB_14001a59f:
    uVar15 = (ulonglong)DAT_1400153b8 + 0x18;
    pwVar16 = (wchar_t *)ExAllocatePool2(0x100,uVar15,0x4f4d5442);
    if (pwVar16 == (wchar_t *)0x0) {
LAB_14001a6a3:
      uVar32 = 0xc000009a;
    }
    else {
      uVar26 = uVar15 >> 1;
      if (uVar26 == 0) {
        uVar32 = 0xc000000d;
      }
      else {
        uVar8 = DAT_1400153b8 >> 1;
        lVar12 = DAT_1400153c0 - (longlong)pwVar16;
        lVar22 = 0;
        uVar31 = uVar26;
        pwVar25 = pwVar16;
        do {
          if ((uVar31 + (uVar8 - uVar26) == 0) ||
             (wVar4 = *(wchar_t *)((longlong)pwVar25 + lVar12), wVar4 == L'\0')) break;
          *pwVar25 = wVar4;
          lVar22 = lVar22 + 1;
          pwVar25 = pwVar25 + 1;
          uVar31 = uVar31 - 1;
        } while (uVar31 != 0);
        pwVar20 = pwVar25 + -1;
        if (uVar31 != 0) {
          pwVar20 = pwVar25;
        }
        *pwVar20 = L'\0';
        lVar12 = lVar22 + -1;
        if (uVar31 != 0) {
          lVar12 = lVar22;
        }
        uVar32 = ~-(uint)(uVar31 != 0) & 0x80000005;
        if ((-1 < (int)uVar32) || (pwVar25 = (wchar_t *)0x0, uVar32 == 0x80000005)) {
          uVar15 = (ulonglong)((uint)uVar15 & 1) + (uVar26 - lVar12) * 2;
          pwVar25 = pwVar16 + lVar12;
        }
        if (uVar32 == 0) {
          uVar13 = RtlStringCbPrintfW(pwVar25,uVar15,L",%d",1);
          uVar32 = (uint)uVar13;
          if (uVar32 == 0) {
            local_3a8 = pwVar16;
            goto LAB_14001a6a8;
          }
        }
      }
      ExFreePool(pwVar16);
    }
  }
  else {
    lVar12 = -1;
    do {
      lVar12 = lVar12 + 1;
    } while (*(short *)(*(longlong *)(piVar5 + 0x12) + lVar12 * 2) != 0);
    iVar9 = (int)lVar12 * 2;
    if (iVar9 == 0) goto LAB_14001a59f;
    uVar32 = iVar9 + 6;
    local_3a8 = (wchar_t *)ExAllocatePool2(0x100,uVar32,0x4f4d5442);
    if (local_3a8 == (wchar_t *)0x0) goto LAB_14001a6a3;
    pwVar16 = *(wchar_t **)(piVar5 + 0x12);
    if (pwVar16 == (wchar_t *)0x0) {
      uVar32 = 0;
    }
    else {
      uVar15 = (ulonglong)(uVar32 >> 1);
      if (uVar15 == 0) {
        uVar32 = 0xc000000d;
      }
      else {
        lVar12 = 0x7ffffffe - uVar15;
        pwVar25 = local_3a8;
        do {
          if ((lVar12 + uVar15 == 0) || (*pwVar16 == L'\0')) break;
          *pwVar25 = *pwVar16;
          pwVar16 = pwVar16 + 1;
          pwVar25 = pwVar25 + 1;
          uVar15 = uVar15 - 1;
        } while (uVar15 != 0);
        pwVar16 = pwVar25 + -1;
        if (uVar15 != 0) {
          pwVar16 = pwVar25;
        }
        *pwVar16 = L'\0';
        uVar32 = ~-(uint)(uVar15 != 0) & 0x80000005;
        if (-1 < (int)uVar32) goto LAB_14001a6a8;
      }
      ExFreePoolWithTag(local_3a8,0x454d5442);
      local_3a8 = (wchar_t *)0x0;
    }
  }
LAB_14001a6a8:
  *(wchar_t **)(param_2 + 0x38) = local_3a8;
LAB_140019268:
  *(uint *)(param_2 + 0x30) = uVar32;
  IofCompleteRequest(param_2,0);
  return uVar32;
}



===== BthEnumPdoPower @ 14001a920 =====

int BthEnumPdoPower(longlong param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  lVar5 = *(longlong *)(param_1 + 0x40);
  iVar6 = 0;
  iVar2 = *(int *)(lVar4 + 0x10);
  iVar3 = *(int *)(lVar4 + 0x18);
  uVar9 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,param_3,100,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,uVar9,*(char *)(lVar4 + 1));
  }
  cVar1 = *(char *)(lVar4 + 1);
  if (cVar1 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                         &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,3,0x66,
                         &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)param_2,uVar9);
    }
    uVar7 = BthEnumQueueIrp(param_1,param_2);
    iVar6 = (int)uVar7;
    if (iVar6 == 0x103) {
      return 0x103;
    }
    goto LAB_14001aa8e;
  }
  if (cVar1 == '\x01') {
LAB_14001a9d9:
    iVar6 = -0x3ffffffe;
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        BthEnumUpdateProfileConnectionCountKey(lVar5);
      }
      else {
        iVar6 = *(int *)(param_2 + 0x30);
      }
      goto LAB_14001aa8e;
    }
    if (iVar2 == 0) {
      uVar8 = 0;
    }
    else {
      if (iVar2 != 1) goto LAB_14001a9d9;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                            &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,param_3,0x65,
                            &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,uVar9,
                            (char)*(undefined4 *)(lVar5 + 0xb4),(char)iVar3);
      }
      if (*(int *)(lVar5 + 0xb4) == iVar3) goto LAB_14001aa8e;
      *(int *)(lVar5 + 0xb4) = iVar3;
      uVar8 = 1;
    }
    PoSetPowerState(param_1,uVar8,iVar3);
  }
LAB_14001aa8e:
  *(int *)(param_2 + 0x30) = iVar6;
  PoStartNextPowerIrp(param_2);
  IofCompleteRequest(param_2,0);
  return iVar6;
}



===== BthEnumSetDefaultCapabilities @ 14001aad8 =====

undefined8 BthEnumSetDefaultCapabilities(longlong param_1,int *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  ulonglong local_18;
  undefined8 uStack_10;
  
  puVar2 = *(undefined4 **)(param_1 + 8);
  uVar4 = 0;
  uVar1 = puVar2[1];
  *puVar2 = 0x10040;
  puVar2[1] = uVar1 & 0xfffffff3;
  *(undefined8 *)(puVar2 + 0xb) = 0;
  *(undefined8 *)(puVar2 + 0xd) = 0;
  puVar2[0xf] = 0;
  puVar2[1] = -(uint)(*(longlong *)(param_2 + 0x30) != 0) & 0x10 | uVar1 & 0xffffffe3 | 0x200;
  if (*param_2 != 0x4f445044) {
    local_18 = *(ulonglong *)(param_2 + 0x108);
    uStack_10 = *(undefined8 *)(param_2 + 0x10a);
    iVar3 = BthCheckForUnsupportedServiceID(&local_18);
    if (iVar3 == 0) {
      uVar4 = 0x20000;
    }
  }
  puVar2[1] = puVar2[1] & 0xfffdffdf | uVar4 | 0x100;
  return 0;
}



===== BthEnumSetDevicePdoProperties @ 14001ab74 =====

ulonglong BthEnumSetDevicePdoProperties(longlong param_1,undefined8 param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  short *psVar8;
  short *psVar9;
  uint uVar10;
  longlong *plVar11;
  short *psVar12;
  ulonglong uVar13;
  wchar_t *pwVar14;
  undefined1 uVar15;
  longlong lVar16;
  undefined2 uVar17;
  longlong lVar18;
  longlong lVar19;
  int local_res8;
  undefined4 local_resc;
  char local_res18 [8];
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff98;
  undefined8 uVar20;
  undefined4 uVar21;
  longlong local_40;
  
  uVar21 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  local_res20 = 0;
  lVar19 = 0;
  local_40 = 0;
  psVar8 = (short *)0x0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar21 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x2c,
                     &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
  }
  lVar5 = ExAllocatePool2(0x100,0x1f2,0x4f4d5442);
  if (lVar5 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,3,0x2d,
                       &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
    }
    uVar13 = 0xc000009a;
    lVar18 = 0;
    goto LAB_14001b570;
  }
  lVar18 = -1;
  if ((char)param_2 == '\0') {
LAB_14001ae96:
    if ((*(uint *)(param_1 + 0xb8) & 4) == 0) {
LAB_14001af56:
      pwVar14 = L"Unknown";
      uVar2 = *(uint *)(param_1 + 200) >> 2;
      uVar10 = *(uint *)(param_1 + 200) >> 8 & 0x1f;
      uVar4 = uVar2 & 0x3f;
      if (uVar10 == 1) {
        if (uVar4 == 1) {
          pwVar14 = L"Computer.Desktop";
        }
        else if (uVar4 == 2) {
          pwVar14 = L"Computer.Server";
        }
        else if (uVar4 == 3) {
          pwVar14 = L"Computer.Laptop";
        }
        else if ((uVar4 == 4) || (uVar4 == 5)) {
          pwVar14 = L"Computer.Handheld";
        }
        else {
          if (uVar4 == 6) goto LAB_14001b0e4;
          pwVar14 = L"Computer";
        }
      }
      else if (uVar10 == 2) {
        if ((((uVar4 == 1) || (uVar4 == 2)) || (uVar4 == 3)) || (uVar4 != 4)) {
          pwVar14 = L"Communication.Phone";
        }
        else {
          pwVar14 = L"Network.Modem";
        }
      }
      else if (uVar10 == 3) {
        pwVar14 = L"Network";
      }
      else if (uVar10 == 4) {
        if (uVar4 < 10) {
          if (uVar4 == 9) goto LAB_14001b165;
          if (((uVar4 == 1) || (uVar4 == 2)) || (uVar4 == 3)) {
            pwVar14 = L"Communication.Headset.Bluetooth";
          }
          else if (uVar4 == 4) {
            pwVar14 = L"Audio.Microphone";
          }
          else if (uVar4 == 5) {
            pwVar14 = L"Audio.Speakers";
          }
          else {
            if (uVar4 != 6) {
              if ((uVar4 != 7) && (uVar4 != 8)) goto LAB_14001b0e4;
              goto LAB_14001b165;
            }
            pwVar14 = L"Audio.Headphone";
          }
        }
        else if ((uVar4 == 10) || (uVar4 == 0xb)) {
LAB_14001b165:
          pwVar14 = L"Multimedia";
        }
        else if ((uVar4 == 0xc) || (uVar4 == 0xd)) {
          pwVar14 = L"Imaging.Camcorder";
        }
        else {
          if (uVar4 != 0xe) {
            if ((uVar4 == 0xf) || (uVar4 == 0x10)) goto LAB_14001b047;
            goto LAB_14001b0e4;
          }
          pwVar14 = L"Display.Monitor";
        }
      }
      else if (uVar10 == 5) {
        if ((uVar2 & 0x10) == 0) {
          if ((uVar2 & 0x20) == 0) {
            pwVar14 = L"Input.Gaming";
            if (uVar4 != 2) {
              pwVar14 = L"Input";
            }
          }
          else {
            pwVar14 = L"Input.Mouse";
          }
        }
        else {
          pwVar14 = L"Input.Keyboard";
        }
      }
      else if (uVar10 == 6) {
        if ((uVar2 & 0x20) == 0) {
          if ((uVar2 & 0x10) == 0) {
            if ((uVar2 & 4) == 0) {
              pwVar14 = L"Imaging.Camera";
              if ((uVar2 & 8) == 0) {
                pwVar14 = L"Other";
              }
            }
            else {
LAB_14001b047:
              pwVar14 = L"Display";
            }
          }
          else {
            pwVar14 = L"Imaging.Scanner";
          }
        }
        else {
          pwVar14 = L"PrintFax.Printer";
        }
      }
      else if ((uVar10 == 7) || (uVar10 == 8)) {
LAB_14001b0e4:
        pwVar14 = L"Other";
      }
      else if (uVar10 == 9) {
        if (uVar4 == 1) {
          pwVar14 = L"Health.BloodPressure";
        }
        else if ((uVar4 == 2) || (uVar4 == 3)) {
LAB_14001b00b:
          pwVar14 = L"Health";
        }
        else if (uVar4 == 4) {
          pwVar14 = L"Health.BloodGlucose";
        }
        else {
          if (uVar4 == 5) goto LAB_14001b00b;
          if (uVar4 == 6) {
            pwVar14 = L"Health.HeartRate";
          }
          else {
            if ((uVar4 == 7) || (uVar4 != 8)) goto LAB_14001b00b;
            pwVar14 = L"Health.Pedometer";
          }
        }
      }
      lVar7 = -1;
      do {
        lVar7 = lVar7 + 1;
      } while (pwVar14[lVar7] != L'\0');
      psVar12 = (short *)(lVar7 * 2 + 4);
      psVar8 = (short *)ExAllocatePool2(0x100,psVar12,0x4f4d5442);
      if (psVar8 == (short *)0x0) {
        uVar13 = 0xc000009a;
        uVar2 = 0xc000009a;
LAB_14001b2c0:
        uVar15 = (undefined1)uVar2;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001b56c;
        uVar17 = 0x36;
      }
      else {
        lVar7 = -1;
        do {
          lVar16 = lVar7;
          lVar7 = lVar16 + 1;
        } while (pwVar14[lVar16 + 1] != L'\0');
        lVar7 = lVar16 + 2;
        if (0x7ffffffe < lVar16 + 1U) {
          psVar12 = (short *)0x0;
          uVar13 = 0xc000000d;
          uVar2 = 0xc000000d;
          if (lVar7 == 0) goto LAB_14001b28a;
          *psVar8 = 0;
LAB_14001b290:
          ExFreePool(psVar8);
          uVar2 = (uint)uVar13;
          psVar8 = (short *)0x0;
          goto LAB_14001b2c0;
        }
        lVar16 = 0x7ffffffe - lVar7;
        psVar12 = psVar8;
        do {
          if ((lVar7 + lVar16 == 0) ||
             (sVar1 = *(short *)((longlong)psVar12 + ((longlong)pwVar14 - (longlong)psVar8)),
             sVar1 == 0)) break;
          *psVar12 = sVar1;
          psVar12 = psVar12 + 1;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        psVar9 = psVar12 + -1;
        if (lVar7 != 0) {
          psVar9 = psVar12;
        }
        *psVar9 = 0;
        uVar2 = ~-(uint)(lVar7 != 0) & 0x80000005;
LAB_14001b28a:
        uVar13 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) goto LAB_14001b290;
        uVar13 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) goto LAB_14001b2c0;
        do {
          lVar18 = lVar18 + 1;
        } while (psVar8[lVar18] != 0);
        psVar12 = (short *)&DEVPKEY_DeviceContainer_Category;
        uVar20 = CONCAT44(uVar21,0x2012);
        uVar2 = IoSetDevicePropertyData
                          (*(undefined8 *)(param_1 + 0x10),&DEVPKEY_DeviceContainer_Category,0,0,
                           uVar20,(int)lVar18 * 2 + 4,psVar8);
        uVar13 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          psVar12 = (short *)&DEVPKEY_Bluetooth_LastConnectedTime;
          uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
          if ((*(uint *)(param_1 + 0xb8) & 0x20) == 0) {
            local_res8 = *(int *)(param_1 + 1000);
            local_resc = *(undefined4 *)(param_1 + 0x3ec);
            uVar2 = IoSetDevicePropertyData();
LAB_14001b3cd:
            uVar13 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_14001b56c;
              uVar17 = 0x38;
              goto LAB_14001b545;
            }
          }
          else {
            uVar20 = CONCAT44(uVar21,0x10);
            uVar2 = IoSetDevicePropertyData
                              (*(undefined8 *)(param_1 + 0x10),&DEVPKEY_Bluetooth_LastConnectedTime,
                               0,0,uVar20,0,0);
            uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
            if (uVar2 != 0xc0000034) goto LAB_14001b3cd;
          }
          psVar12 = (short *)&DEVPKEY_Bluetooth_LastConnectedTime_Deprecated;
          if ((*(uint *)(param_1 + 0xb8) & 0x20) == 0) {
            local_res8 = *(int *)(param_1 + 1000);
            local_resc = *(undefined4 *)(param_1 + 0x3ec);
            uVar2 = IoSetDevicePropertyData();
LAB_14001b46d:
            uVar13 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_14001b56c;
              uVar17 = 0x39;
              goto LAB_14001b545;
            }
          }
          else {
            uVar20 = CONCAT44(uVar21,0x10);
            uVar2 = IoSetDevicePropertyData
                              (*(undefined8 *)(param_1 + 0x10),
                               &DEVPKEY_Bluetooth_LastConnectedTime_Deprecated,0,0,uVar20,0,0);
            uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
            if (uVar2 != 0xc0000034) goto LAB_14001b46d;
          }
          psVar12 = (short *)&DEVPKEY_Bluetooth_LastConnectionStatus;
          uVar2 = IoSetDevicePropertyData
                            (*(undefined8 *)(param_1 + 0x10),&DEVPKEY_Bluetooth_LastConnectionStatus
                             ,0,0,CONCAT44(uVar21,3),1,param_1 + 0x3f8);
          uVar13 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar17 = 0x3a;
              goto LAB_14001b545;
            }
          }
          else {
            psVar12 = (short *)&DEVPKEY_Bluetooth_LastConnectionBlockedBySystem;
            local_res18[0] = -(*(char *)(param_1 + 0x3f9) != '\0');
            uVar2 = IoSetDevicePropertyData
                              (*(undefined8 *)(param_1 + 0x10),
                               &DEVPKEY_Bluetooth_LastConnectionBlockedBySystem,0,0,0x11,1,
                               local_res18);
            uVar13 = (ulonglong)uVar2;
            if (((int)uVar2 < 0) &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar17 = 0x3b;
              goto LAB_14001b545;
            }
          }
          goto LAB_14001b56c;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001b56c;
        uVar17 = 0x37;
LAB_14001b545:
        uVar15 = (undefined1)uVar13;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),psVar12,1,uVar17,
                        &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,uVar15);
    }
    else {
      local_res8 = 0;
      lVar7 = -1;
      do {
        lVar7 = lVar7 + 1;
      } while (*(char *)(param_1 + 0xcc + lVar7) != '\0');
      uVar20 = CONCAT44(uVar21,(int)lVar7);
      plVar11 = (longlong *)0x1f2;
      uVar2 = RtlUTF8ToUnicodeN(lVar5,0x1f2,&local_res8,param_1 + 0xcc,uVar20);
      uVar13 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar17 = 0x34;
LAB_14001aef7:
          uVar2 = (uint)uVar13;
          goto LAB_14001ac77;
        }
      }
      else {
        plVar11 = (longlong *)&DEVPKEY_Device_FriendlyName;
        uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0x12);
        uVar2 = IoSetDevicePropertyData
                          (*(undefined8 *)(param_1 + 0x10),&DEVPKEY_Device_FriendlyName,0,0,uVar20,
                           local_res8 + 2,lVar5);
        uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
        uVar13 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) goto LAB_14001af56;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar17 = 0x35;
          goto LAB_14001aef7;
        }
      }
    }
  }
  else {
    plVar11 = &local_res20;
    uVar13 = BthEnumGenerateAepId(param_1,plVar11);
    uVar2 = (uint)uVar13;
    uVar13 = uVar13 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar17 = 0x2e;
LAB_14001ac77:
        uVar4 = 3;
LAB_14001ac7d:
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar11,uVar4,uVar17,
                          &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar2);
      }
    }
    else {
      plVar11 = (longlong *)&DEVPKEY_Aep_AepId;
      uVar20 = CONCAT44(uVar21,0x12);
      uVar2 = IoSetDevicePropertyData
                        (*(undefined8 *)(param_1 + 0x10),&DEVPKEY_Aep_AepId,0,0,uVar20,0x6e,
                         local_res20);
      uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
      uVar13 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar17 = 0x2f;
          goto LAB_14001ac77;
        }
      }
      else {
        plVar11 = &local_40;
        uVar6 = BthEnumGenerateAepDeviceAddress(*(ulonglong *)(param_1 + 0xc0),plVar11);
        lVar19 = local_40;
        uVar13 = uVar6 & 0xffffffff;
        if ((int)uVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar11,3,0x30,
                              &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar6);
          }
          lVar19 = local_40;
        }
        else {
          plVar11 = (longlong *)&DEVPKEY_Aep_DeviceAddress;
          uVar20 = CONCAT44(uVar21,0x12);
          uVar2 = IoSetDevicePropertyData
                            (*(undefined8 *)(param_1 + 0x10),&DEVPKEY_Aep_DeviceAddress,0,0,uVar20,
                             0x24,local_40);
          uVar13 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar17 = 0x31;
              goto LAB_14001ac77;
            }
          }
          else {
            uVar20 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),0x2012);
            uVar2 = IoSetDevicePropertyData
                              (*(undefined8 *)(param_1 + 0x10),
                               &DEVPKEY_DeviceContainer_DiscoveryMethod,0,0,uVar20,0x16,L"Bluetooth"
                              );
            uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
            plVar11 = (longlong *)0x0;
            uVar13 = (ulonglong)uVar2;
            if (-1 < (int)uVar2) {
              local_res8 = CONCAT31(local_res8._1_3_,0xff);
              if ((*(uint *)(param_1 + 0xb8) & 0x8000000) != 0) {
                uVar20 = CONCAT44(uVar21,0x11);
                iVar3 = IoSetDevicePropertyData
                                  (*(undefined8 *)(param_1 + 0x10),
                                   &DEVPKEY_Bluetooth_SecureConnectionPaired,0,0,uVar20,1,
                                   &local_res8);
                uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
                if ((iVar3 < 0) &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  uVar21 = 1;
                  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,3,0x33,
                                    &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
                }
              }
              goto LAB_14001ae96;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar17 = 0x32;
              uVar4 = 1;
              goto LAB_14001ac7d;
            }
          }
        }
      }
    }
  }
LAB_14001b56c:
  lVar18 = local_res20;
LAB_14001b570:
  psVar12 = (short *)(param_1 + 0xb48);
  if (*psVar12 != 0) {
    BthEnumSetPdoInterfaceProperties(param_1,psVar12);
  }
  if (lVar5 != 0) {
    ExFreePool(lVar5);
  }
  if (lVar18 != 0) {
    ExFreePool(lVar18);
  }
  if (lVar19 != 0) {
    ExFreePool(lVar19);
  }
  if (psVar8 != (short *)0x0) {
    ExFreePool(psVar8);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),psVar12,3,0x3c,
                      &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)uVar13);
  }
  return uVar13;
}



===== BthEnumSetPdoInterfaceProperties @ 14001b634 =====

void BthEnumSetPdoInterfaceProperties(longlong param_1,undefined8 param_2)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined *puVar6;
  int local_res8 [2];
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar8;
  undefined8 uVar7;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar8 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x1e,
                     &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
  }
  puVar6 = &DEVPKEY_Bluetooth_DeviceAddress;
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x40);
  uVar7 = CONCAT44(uVar8,0x12);
  iVar3 = IoSetDeviceInterfacePropertyData
                    (param_2,&DEVPKEY_Bluetooth_DeviceAddress,0,0,uVar7,0x1a,param_1 + 0x18);
  uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
  if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar8 = 1;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x1f,
                      &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
  }
  puVar6 = &DEVPKEY_Bluetooth_RadioAddress;
  uVar7 = CONCAT44(uVar8,9);
  iVar3 = IoSetDeviceInterfacePropertyData
                    (param_2,&DEVPKEY_Bluetooth_RadioAddress,0,0,uVar7,8,lVar4 + 0x140);
  uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
  if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar8 = 1;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x20,
                      &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
  }
  puVar1 = (uint *)(param_1 + 0xb8);
  puVar6 = &DEVPKEY_Bluetooth_DeviceFlags;
  uVar7 = CONCAT44(uVar8,7);
  iVar3 = IoSetDeviceInterfacePropertyData
                    (param_2,&DEVPKEY_Bluetooth_DeviceFlags,0,0,uVar7,4,puVar1);
  uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
  if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar8 = 1;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x21,
                      &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
  }
  cVar2 = KeGetCurrentIrql();
  if (cVar2 != '\0') goto LAB_14001bbf6;
  puVar6 = &DEVPKEY_Bluetooth_ClassOfDevice;
  uVar7 = CONCAT44(uVar8,7);
  iVar3 = IoSetDeviceInterfacePropertyData
                    (param_2,&DEVPKEY_Bluetooth_ClassOfDevice,0,0,uVar7,4,param_1 + 200);
  uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
  if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar8 = 1;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x22,
                      &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
  }
  puVar6 = &DEVPKEY_Bluetooth_ClassOfDevice_Deprecated;
  uVar7 = CONCAT44(uVar8,7);
  iVar3 = IoSetDeviceInterfacePropertyData
                    (param_2,&DEVPKEY_Bluetooth_ClassOfDevice_Deprecated,0,0,uVar7,4,param_1 + 200);
  uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
  if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar8 = 1;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x23,
                      &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
  }
  if ((*puVar1 & 4) != 0) {
    puVar6 = (undefined *)0x1f2;
    lVar4 = ExAllocatePool2(0x100,0x1f2,0x4f4d5442);
    if (lVar4 == 0) {
      iVar3 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 1;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x24,
                         &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
        goto LAB_14001b987;
      }
    }
    else {
      if (iVar3 < 0) {
LAB_14001b987:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 1;
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x25,
                            &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
        }
        if (lVar4 == 0) goto LAB_14001b9d4;
      }
      else {
        local_res8[0] = 0;
        lVar5 = -1;
        do {
          lVar5 = lVar5 + 1;
        } while (*(char *)(param_1 + 0xcc + lVar5) != '\0');
        uVar7 = CONCAT44(uVar8,(int)lVar5);
        puVar6 = (undefined *)0x1f2;
        iVar3 = RtlUTF8ToUnicodeN(lVar4,0x1f2,local_res8,param_1 + 0xcc,uVar7);
        uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
        if (iVar3 < 0) goto LAB_14001b987;
        puVar6 = &DEVPKEY_DeviceInterface_FriendlyName;
        uVar7 = CONCAT44(uVar8,0x12);
        iVar3 = IoSetDeviceInterfacePropertyData
                          (param_2,&DEVPKEY_DeviceInterface_FriendlyName,0,0,uVar7,local_res8[0] + 2
                           ,lVar4);
        uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
        if (iVar3 < 0) goto LAB_14001b987;
      }
      ExFreePool(lVar4);
    }
  }
LAB_14001b9d4:
  if ((*(short *)(param_1 + 0x63c) != 0) && (*(short *)(param_1 + 0x634) != 0)) {
    puVar6 = &DEVPKEY_Bluetooth_DeviceVIDSource;
    uVar7 = CONCAT44(uVar8,3);
    iVar3 = IoSetDeviceInterfacePropertyData
                      (param_2,&DEVPKEY_Bluetooth_DeviceVIDSource,0,0,uVar7,1,
                       (short *)(param_1 + 0x63c));
    uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar8 = 1;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x26,
                        &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
    }
    puVar6 = &DEVPKEY_Bluetooth_DeviceVID;
    uVar7 = CONCAT44(uVar8,5);
    iVar3 = IoSetDeviceInterfacePropertyData
                      (param_2,&DEVPKEY_Bluetooth_DeviceVID,0,0,uVar7,2,(short *)(param_1 + 0x634));
    uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar8 = 1;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x27,
                        &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
    }
    puVar6 = &DEVPKEY_Bluetooth_DevicePID;
    uVar7 = CONCAT44(uVar8,5);
    iVar3 = IoSetDeviceInterfacePropertyData
                      (param_2,&DEVPKEY_Bluetooth_DevicePID,0,0,uVar7,2,param_1 + 0x636);
    uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar8 = 1;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x28,
                        &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
    }
  }
  if ((*puVar1 & 0x8000000) != 0) {
    local_res8[0] = CONCAT31(local_res8[0]._1_3_,0xff);
    puVar6 = &DEVPKEY_Bluetooth_SecureConnectionPaired;
    uVar7 = CONCAT44(uVar8,0x11);
    iVar3 = IoSetDeviceInterfacePropertyData
                      (param_2,&DEVPKEY_Bluetooth_SecureConnectionPaired,0,0,uVar7,1,local_res8);
    uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar8 = 1;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x29,
                        &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
    }
  }
  if ((*puVar1 & 0x4000000) != 0) {
    local_res8[0] = CONCAT31(local_res8[0]._1_3_,0xff);
    puVar6 = &DEVPKEY_Bluetooth_SdpCachePopulated;
    iVar3 = IoSetDeviceInterfacePropertyData
                      (param_2,&DEVPKEY_Bluetooth_SdpCachePopulated,0,0,CONCAT44(uVar8,0x11),1,
                       local_res8);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x2a,
                        &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids,(char)iVar3);
    }
  }
LAB_14001bbf6:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,3,0x2b,
                     &WPP_2de2e0e631453f5f69f68f01ca725c87_Traceguids);
  }
  return;
}



===== BuildLocalMfgID @ 14001bc44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BuildLocalMfgID(longlong param_1,wchar_t *param_2,ulonglong param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  wchar_t *local_60;
  undefined8 *local_58;
  uint local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined2 local_34;
  wchar_t local_30 [12];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_38 = 0x260047;
  local_34 = 0;
  local_30[8] = L'S';
  local_30[9] = L'S';
  local_48 = 0x43004f004c005f;
  uStack_40 = 0x46004d004c0041;
  local_30[10] = 0;
  local_68 = *(undefined8 *)(param_1 + 0x38);
  builtin_wcsncpy(local_30,L"_HCIBYPA",8);
  local_50 = (uint)*(ushort *)(param_1 + 0x63a);
  if (*(int *)(param_1 + 0xb40) == 0) {
    local_58 = (undefined8 *)CONCAT44(local_58._4_4_,local_50);
    local_60 = (wchar_t *)&local_48;
    uVar2 = RtlStringCchPrintfW(param_2,param_3 & 0xffffffff,L"%s%s%s%04x",busId);
    iVar1 = (int)uVar2;
  }
  else {
    local_58 = &local_48;
    local_60 = local_30;
    uVar2 = RtlStringCchPrintfW(param_2,param_3 & 0xffffffff,L"%s%s%s%s%04x",busId);
    iVar1 = (int)uVar2;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (param_2[lVar3] != L'\0');
    iVar1 = (int)lVar3 + 1;
  }
  return iVar1;
}



===== BuildVidPidID @ 14001bd4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BuildVidPidID(longlong param_1,wchar_t *param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  wchar_t *local_90;
  undefined8 *local_88;
  uint local_80;
  undefined8 *local_78;
  undefined8 *local_70;
  uint local_68;
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  wchar_t local_38 [12];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  local_98 = *(undefined8 *)(param_1 + 0x38);
  local_40 = 0x26;
  local_50 = 0x26;
  local_48 = 0x4400490056005f;
  local_38[8] = L'S';
  local_38[9] = L'S';
  local_58 = 0x4400490050005f;
  local_38[10] = 0;
  builtin_wcsncpy(local_38,L"_HCIBYPA",8);
  local_68 = (uint)*(ushort *)(param_1 + 0x636);
  local_80 = (uint)*(ushort *)(param_1 + 0x634);
  if (*(int *)(param_1 + 0xb40) == 0) {
    local_70 = (undefined8 *)CONCAT44(local_70._4_4_,local_68);
    local_78 = &local_58;
    local_90 = (wchar_t *)&local_48;
    local_88 = (undefined8 *)CONCAT44(local_88._4_4_,(uint)*(ushort *)(param_1 + 0x63c));
    uVar2 = RtlStringCchPrintfW(param_2,(ulonglong)param_3,L"%s%s%s%04x%04x%s%04x",busId);
    iVar1 = (int)uVar2;
  }
  else {
    local_70 = &local_58;
    local_88 = &local_48;
    local_78 = (undefined8 *)CONCAT44(local_78._4_4_,local_80);
    local_90 = local_38;
    local_80 = (uint)*(ushort *)(param_1 + 0x63c);
    uVar2 = RtlStringCchPrintfW(param_2,(ulonglong)param_3,L"%s%s%s%s%04x%04x%s%04x",busId);
    iVar1 = (int)uVar2;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (param_2[lVar3] != L'\0');
    iVar1 = (int)lVar3 + 1;
  }
  return iVar1;
}



===== BthUnload @ 14001bea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BthUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 local_58 [4];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar2 = param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = 0x19;
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    param_3 = 3;
    WPP_RECORDER_SF_(uVar2,param_2,3,0x19,&WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
  }
  if (5 < DAT_140015010) {
    if (((DAT_140015020 & 0x400000000000) == 0) ||
       ((DAT_140015028 & 0x400000000000) != DAT_140015028)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_2c = 0;
      local_38 = local_68;
      local_1c = 0;
      local_28 = L"BthEnum.sys";
      local_68[0] = 0x2000800;
      local_30 = 8;
      local_20 = 0x18;
      _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140013911,param_3,param_4,4,local_58);
    }
  }
  uVar2 = DAT_140015030;
  DAT_140015030 = 0;
  DAT_140015010 = 0;
  EtwUnregister(uVar2);
  BthLib_Unload();
  if (DAT_1400153c0 != 0) {
    ExFreePool();
    DAT_1400153c0 = 0;
  }
  BthPolicyDestroy();
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar3 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar3 != (undefined *)0x0; puVar3 = *(undefined **)(puVar3 + 0x10)) {
        if (*(longlong *)(puVar3 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar3 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== UnHandledDispatch @ 14001c0e0 =====

undefined4 UnHandledDispatch(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  piVar1 = *(int **)(param_1 + 0x40);
  uVar2 = 0xc00000bb;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x1a,
                     &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
  }
  if (*piVar1 == 0x204f4446) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar2 = IofCallDriver(*(undefined8 *)(piVar1 + 6));
    lVar3 = param_2;
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    lVar3 = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,4,0x1c,
                      &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids,(char)uVar2);
  }
  return uVar2;
}



===== WppInitKm @ 14001c1d0 =====

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



===== WppLoadTracingSupport @ 14001c2ac =====

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



===== WppTraceCallback @ 14001c3f0 =====

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



===== _tlgEnableCallback @ 14001c680 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14001c6fc =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_GatePerf__private_descriptor;
  ppuVar2 = &Feature_GatePerf__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014001c737;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001c7b1:
  while( true ) {
    if (&UNK_1400148bf < ppuVar3) {
      return;
    }
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  do {
    if (ppuVar3 == (undefined **)0x0) {
      return;
    }
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*ppuVar3,(longlong)ppuVar3);
    ppuVar3 = ppuVar3 + 7;
    while( true ) {
      if (&UNK_1400148bf < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014001c737:
  while (ppuVar2 != (undefined **)0x0) {
    uVar1 = *(uint *)*ppuVar2;
    if ((uVar1 >> 9 & 1) != 0) {
      if ((uVar1 & 0x180) == 0) {
        bVar5 = *(char *)((longlong)ppuVar2 + 0x1f) != '\0';
      }
      else {
        bVar5 = (uVar1 & 0x180) == 0x100;
      }
      LOCK();
      *(uint *)*ppuVar2 = *(uint *)*ppuVar2 ^ uVar1 & 0x40 ^ (uint)bVar5 << 6;
      UNLOCK();
    }
    ppuVar2 = ppuVar2 + 7;
    while( true ) {
      if (&UNK_1400148bf < ppuVar2) goto LAB_14001c7b1;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001c7b1;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001c7ec =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = *param_1;
  if ((uVar6 >> 9 & 1) == 0) {
    uVar3 = uVar6;
  }
  else {
    uVar4 = uVar6 >> 6 & 1;
    if ((uVar4 != 0) && (plVar5 = *(longlong **)(param_2 + 0x20), plVar5 != (longlong *)0x0)) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)*plVar5;
          if (puVar1 == (undefined8 *)0x0) goto LAB_14001c884;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14001c884;
          }
          uVar4 = 1;
          plVar5 = plVar5 + 1;
        }
        uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                          ((uint *)*puVar1,(longlong)puVar1);
        if ((uVar4 == 0) || ((uVar2 & 1) == 0)) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        plVar5 = plVar5 + 1;
      } while (uVar4 != 0);
    }
LAB_14001c884:
    do {
      uVar2 = uVar6 & 0xffffffce;
      if ((uVar6 & 1) == uVar4) {
        uVar2 = uVar6 & 0xfffffffe;
      }
      uVar3 = uVar2 & 0xfffffdff | uVar4;
      LOCK();
      uVar2 = *param_1;
      bVar7 = uVar6 == uVar2;
      if (bVar7) {
        *param_1 = uVar3;
      }
      else {
        uVar6 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001c8d0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (ppuVar2 = &Feature_GatePerf__private_descriptor;
          ppuVar2 < &wil_details_featureDescriptors_z; ppuVar2 = ppuVar2 + 1) {
        if (*ppuVar2 != (undefined *)0x0) {
          do {
            if (ppuVar2 == (undefined **)0x0) {
              return;
            }
            if ((*(uint *)ppuVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage(*(undefined4 *)(ppuVar2 + 3),(uint *)ppuVar2[1]);
            }
            ppuVar2 = ppuVar2 + 7;
            while( true ) {
              if (&UNK_1400148bf < ppuVar2) {
                return;
              }
              if (*ppuVar2 != (undefined *)0x0) break;
              ppuVar2 = ppuVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001c950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (ppuVar3 = &Feature_GatePerf__private_descriptor; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001ca4d;
  }
LAB_14001ca56:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001ca4d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001ca56;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001ca1e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001ca1e;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*ppuVar3 = *(uint *)*ppuVar3 ^ (*(uint *)*ppuVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400148bf < ppuVar3) goto LAB_14001ca56;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001ca4d;
}



===== BthEnumAddDevice @ 14001ca80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014001cc2d) */

int BthEnumAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 auStackY_d8 [32];
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined1 *puStack_78;
  undefined1 local_70 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_90 = 0;
  uStack_8c = 0;
  uStack_88 = 0;
  local_80 = 0;
  puStack_78 = (undefined1 *)0x0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,10,
                     &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids);
  }
  lVar3 = ExAllocatePool2(0x100,0x102,0x4f4d5442);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    local_90 = 0x800000;
    uStack_88 = lVar3;
    RtlAppendUnicodeToString(&local_90,L"\\Device\\BthEnum");
    iVar2 = DAT_1400153d0;
    puStack_78 = local_70;
    local_80 = CONCAT44(local_80._4_4_,0x280000);
    DAT_1400153d0 = DAT_1400153d0 + 1;
    RtlIntegerToUnicodeString(iVar2,10,&local_80);
    RtlAppendUnicodeStringToString(&local_90,&local_80);
    iVar2 = IoCreateDevice(param_1,0x260,&local_90,0x15);
    if (-1 < iVar2) {
      uVar5 = param_2;
      lVar4 = IoAttachDeviceToDeviceStack(0);
      puVar1 = puRam0000000000000040;
      if (lVar4 != 0) {
        uRam0000000000000030 = uRam0000000000000030 | *(uint *)(lVar4 + 0x30);
        cRam000000000000004c = *(char *)(lVar4 + 0x4c) + '\x01';
        memset(puRam0000000000000040 + 1,0,0x25c);
        *puVar1 = 0x204f4446;
        *(undefined8 *)(puVar1 + 2) = 0;
        *(undefined8 *)(puVar1 + 4) = param_2;
        *(longlong *)(puVar1 + 6) = lVar4;
        *(undefined8 *)(puVar1 + 0x3a) = 0;
        *(undefined8 *)(puVar1 + 0x3c) = 0;
        IrpList_InitEx((longlong)(puVar1 + 0x10),puVar1 + 0x14);
        puVar1[0x36] = local_90;
        puVar1[0x37] = uStack_8c;
        puVar1[0x38] = (undefined4)uStack_88;
        puVar1[0x39] = uStack_88._4_4_;
        *(undefined8 *)(puVar1 + 0x22) = 0;
        *(undefined8 *)(puVar1 + 0x24) = 0;
        puVar1[0x26] = 1;
        *(undefined8 *)(puVar1 + 0x28) = 0;
        puVar1[0x2a] = 0;
        KeInitializeEvent(puVar1 + 0x2c,1);
        uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f;
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,1,0xb,
                         &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids);
      }
      iVar2 = -0x3fffff66;
    }
    ExFreePool(lVar3);
  }
  return iVar2;
}



===== BthEnumFdoPower @ 14001cd28 =====

void BthEnumFdoPower(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  bool bVar7;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  lVar5 = *(longlong *)(param_1 + 0x40);
  bVar7 = false;
  iVar2 = *(int *)(lVar4 + 0x10);
  iVar3 = *(int *)(lVar4 + 0x18);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                       &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,0x16,
                       &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,(char)param_2,
                       *(char *)(lVar4 + 1));
  }
  cVar1 = *(char *)(lVar4 + 1);
  if (cVar1 == '\x02') {
    if (*(char *)(lVar5 + 0x22) == '\x01') {
      if (iVar2 == 1) {
        *(undefined4 *)(param_2 + 0x30) = 0;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                              &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,0x17,
                              &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,(char)param_1,
                              (char)*(undefined4 *)(lVar5 + 0x24),(char)iVar3);
        }
        if (*(int *)(lVar5 + 0x24) < iVar3) {
          PoSetPowerState(param_1,1,iVar3);
          *(int *)(lVar5 + 0x24) = iVar3;
        }
        else {
          bVar7 = false;
          if (iVar3 < *(int *)(lVar5 + 0x24)) {
            bVar7 = true;
          }
        }
      }
      goto LAB_14001ce35;
    }
  }
  else if (cVar1 != '\x03') goto LAB_14001ce35;
  *(undefined4 *)(param_2 + 0x30) = 0;
LAB_14001ce35:
  puVar6 = *(undefined8 **)(param_2 + 0xb8);
  puVar6[-9] = *puVar6;
  puVar6[-8] = puVar6[1];
  puVar6[-7] = puVar6[2];
  puVar6[-6] = puVar6[3];
  *(undefined4 *)(puVar6 + -5) = *(undefined4 *)(puVar6 + 4);
  *(undefined4 *)((longlong)puVar6 + -0x24) = *(undefined4 *)((longlong)puVar6 + 0x24);
  *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(puVar6 + 5);
  *(undefined4 *)((longlong)puVar6 + -0x1c) = *(undefined4 *)((longlong)puVar6 + 0x2c);
  puVar6[-3] = puVar6[6];
  *(undefined1 *)((longlong)puVar6 + -0x45) = 0;
  if (bVar7) {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar4 + -8) = 0;
    *(code **)(lVar4 + -0x10) = BthEnumFdoPowerComplete;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  }
  else {
    PoStartNextPowerIrp(param_2);
  }
  PoCallDriver(*(undefined8 *)(lVar5 + 0x18),param_2);
  return;
}



===== BthEnumGetLocalRadioInfo @ 14001cecc =====

int BthEnumGetLocalRadioInfo(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  int unaff_EBX;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,1,0);
  lVar3 = IoBuildDeviceIoControlRequest
                    (0x410000,*(undefined8 *)(lVar1 + 0x18),0,0,lVar1 + 0x138,0x124,0,&local_28,
                     &local_38);
  if (lVar3 == 0) {
    return unaff_EBX;
  }
  iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18));
  if (iVar2 == 0x103) {
    lVar3 = 0;
    KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  else if (iVar2 < 0) goto LAB_14001cfa7;
  iVar2 = (int)local_38;
  if (-1 < (int)local_38) {
    return unaff_EBX;
  }
LAB_14001cfa7:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,1,0xe,
                      &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,(char)iVar2);
  }
  return unaff_EBX;
}



===== BthEnumPnP @ 14001d000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint BthEnumPnP(longlong param_1,uint *param_2)

{
  char cVar1;
  int *piVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint extraout_EAX;
  undefined8 uVar5;
  longlong lVar6;
  uint *puVar7;
  int iVar8;
  longlong lVar9;
  code *pcVar10;
  ulonglong uVar11;
  undefined1 auStackY_a8 [32];
  undefined8 local_68;
  code *local_60 [2];
  undefined1 local_50 [24];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  piVar2 = *(int **)(param_1 + 0x40);
  lVar9 = *(longlong *)(param_2 + 0x2e);
  iVar8 = *piVar2;
  if ((iVar8 == 0x204f4450) ||
     ((((puVar7 = param_2, iVar8 + 0xb0bbafbcU < 0x35 &&
        (puVar7 = (uint *)0x10000000010001,
        (0x10000000010001U >> ((ulonglong)(iVar8 + 0xb0bbafbcU) & 0x3f) & 1) != 0)) ||
       (iVar8 == 0x44505478)) || (iVar8 == 0x44504478)))) {
    uVar4 = BthEnumPdoPnp(param_1,(longlong)param_2);
    return uVar4;
  }
  if (iVar8 != 0x204f4446) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,1,0xf,
                       &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids);
    }
    param_2[0xc] = 0;
    IofCompleteRequest(param_2,0);
    return 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_c(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  cVar1 = *(char *)(lVar9 + 1);
  if (cVar1 == '\0') {
    if (*(char *)((longlong)piVar2 + 0x22) == '\0') {
      uVar4 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(piVar2 + 6),(longlong)param_2,'\x01');
      if (-1 < (int)uVar4) {
        if (*(longlong *)(piVar2 + 0x3a) == 0) {
          iVar8 = BthEnumGetLocalRadioInfo(param_1);
          lVar9 = CONCAT44((int)((ulonglong)piVar2 >> 0x20),iVar8);
          uVar4 = extraout_EAX;
          if (-1 < (int)extraout_EAX) {
            uVar5 = BthEnumQueryProtocol(param_1);
            uVar4 = (uint)uVar5;
            if ((-1 < (int)uVar4) &&
               (lVar6 = param_1, uVar4 = BthEnumQueryEnumeratorInterface(param_1), -1 < (int)uVar4))
            {
              *(undefined4 *)(lVar9 + 0x24) = 1;
              *(undefined1 *)(lVar9 + 0x22) = 1;
              uVar5 = *(undefined8 *)(param_1 + 0x40);
              pcVar10 = BthEnumRegUpdateWWCapableCodMasks;
              local_60[0] = BthEnumRegUpdateWWCapableCodMasks;
              local_68 = 0;
              local_60[1] = (code *)0x0;
              iVar8 = BthOpenKey(lVar6,
                                 L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\BTHPORT\\Parameters"
                                 ,&local_68);
              if (-1 < iVar8) {
                uVar11 = 0;
                do {
                  (*pcVar10)(uVar5,local_68,local_50);
                  uVar11 = (ulonglong)((int)uVar11 + 1);
                  pcVar10 = local_60[uVar11];
                } while (pcVar10 != (code *)0x0);
                ZwClose(local_68);
              }
            }
          }
        }
        else {
          *(undefined1 *)((longlong)piVar2 + 0x22) = 1;
          piVar2[9] = 1;
        }
      }
      param_2[0xc] = uVar4;
LAB_14001d464:
      IofCompleteRequest(param_2,0);
      return uVar4;
    }
  }
  else if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      *(undefined2 *)(piVar2 + 8) = 0x101;
      puVar3 = *(undefined8 **)(param_2 + 0x2e);
      puVar3[-9] = *puVar3;
      puVar3[-8] = puVar3[1];
      puVar3[-7] = puVar3[2];
      puVar3[-6] = puVar3[3];
      *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
      *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
      *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
      *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
      puVar3[-3] = puVar3[6];
      *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
      uVar4 = IofCallDriver(*(undefined8 *)(piVar2 + 6));
      BthEnumDeleteAllPdos((longlong)piVar2);
      IoDetachDevice(*(undefined8 *)(piVar2 + 6));
      *piVar2 = 0x4f444678;
      if (*(longlong *)(piVar2 + 0x3a) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x12,
                           &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids);
        }
        (**(code **)(*(longlong *)(piVar2 + 0x3a) + 0x18))
                  (*(undefined8 *)(*(longlong *)(piVar2 + 0x3a) + 8));
        ExFreePool(*(undefined8 *)(piVar2 + 0x3a));
        piVar2[0x3a] = 0;
        piVar2[0x3b] = 0;
      }
      if (*(longlong *)(piVar2 + 0x3c) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x13,
                           &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids);
        }
        (**(code **)(*(longlong *)(piVar2 + 0x3c) + 0x18))
                  (*(undefined8 *)(*(longlong *)(piVar2 + 0x3c) + 8));
        ExFreePool(*(undefined8 *)(piVar2 + 0x3c));
        piVar2[0x3c] = 0;
        piVar2[0x3d] = 0;
      }
      ExFreePool(*(undefined8 *)(piVar2 + 0x38));
      piVar2[0x38] = 0;
      piVar2[0x39] = 0;
      if (*(longlong *)(piVar2 + 0x1e) != 0) {
        ExFreePool();
        piVar2[0x1e] = 0;
        piVar2[0x1f] = 0;
      }
      IoDeleteDevice(param_1);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x14,
                          &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,(char)uVar4);
      }
      return uVar4;
    }
    if (cVar1 != '\x03') {
      if (cVar1 == '\x04') {
        *(undefined1 *)((longlong)piVar2 + 0x22) = 0;
      }
      else if ((cVar1 != '\x05') && (cVar1 != '\x06')) {
        if (cVar1 == '\a') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          if (*(int *)(lVar9 + 8) == 0) {
            uVar4 = BthEnumGetDeviceList((longlong)piVar2,param_2);
            param_2[0xc] = uVar4;
            if ((int)uVar4 < 0) goto LAB_14001d464;
          }
          goto LAB_14001d386;
        }
        if (cVar1 != '\x17') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,3,0x15,
                             &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids);
          }
          goto LAB_14001d386;
        }
      }
    }
  }
  param_2[0xc] = 0;
LAB_14001d386:
  uVar4 = ForwardIrp(*(undefined8 *)(piVar2 + 6),(longlong)param_2);
  return uVar4;
}



===== BthEnumPower @ 14001d4b0 =====

void BthEnumPower(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x40);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_3 = 3;
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x18,
                       &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,(char)param_1,(char)param_2)
    ;
  }
  iVar1 = *piVar2;
  if (((iVar1 == 0x204f4450) ||
      (((iVar1 + 0xb0bbafbcU < 0x35 &&
        ((0x10000000010001U >> ((ulonglong)(iVar1 + 0xb0bbafbcU) & 0x3f) & 1) != 0)) ||
       (iVar1 == 0x44505478)))) || (iVar1 == 0x44504478)) {
    BthEnumPdoPower(param_1,param_2,param_3);
  }
  else {
    BthEnumFdoPower(param_1,param_2);
  }
  return;
}



===== BthEnumQueryEnumeratorInterface @ 14001d56c =====

int BthEnumQueryEnumeratorInterface(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar6 = 0;
  lVar7 = 0;
  lVar4 = IoAllocateIrp(*(char *)(param_1 + 0x4c) + '\x01',0);
  if (lVar4 == 0) {
    ExFreePool(0);
    return -0x3fffff66;
  }
  *(char *)(lVar4 + 0x43) = *(char *)(lVar4 + 0x43) + -1;
  *(longlong *)(lVar4 + 0xb8) = *(longlong *)(lVar4 + 0xb8) + -0x48;
  if (*(int *)(lVar1 + 0xd0) == 3) {
    lVar5 = ExAllocatePool2(0x40);
    if (lVar5 != 0) {
      lVar2 = *(longlong *)(lVar4 + 0xb8);
      *(undefined8 *)(lVar5 + 0x30) = 0;
      *(undefined8 *)(lVar5 + 0x40) = 0;
      *(code **)(lVar5 + 0x28) = BthEnumEnumerateProtocolOrDevice;
      *(longlong *)(lVar5 + 0x20) = param_1;
      *(undefined4 *)(lVar5 + 0x38) = 1;
      *(undefined8 *)(lVar2 + -0x28) = 0;
      *(undefined2 *)(lVar2 + -0x48) = 0x81b;
      *(undefined **)(lVar2 + -0x40) = &GUID_BTHDDI_ENUMERATOR_INTERFACE;
      *(undefined4 *)(lVar2 + -0x38) = 0x2000048;
      *(longlong *)(lVar2 + -0x30) = lVar5;
      *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
      iVar3 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(lVar1 + 0x18),lVar4,'\0');
      if (-1 < iVar3) {
        *(longlong *)(lVar1 + 0xe8) = lVar5;
        goto LAB_14001d6e3;
      }
LAB_14001d6c0:
      ExFreePool(lVar5);
      if (lVar6 != 0) {
        ExFreePool(lVar6);
      }
      goto LAB_14001d6e3;
    }
  }
  else {
    lVar5 = ExAllocatePool2(0x40,0x48);
    if (lVar5 != 0) {
      lVar6 = ExAllocatePool2(0x40,0x48);
      if (lVar6 != 0) {
        lVar7 = IoAllocateIrp(*(char *)(param_1 + 0x4c) + '\x01',0);
        if (lVar7 != 0) {
          *(longlong *)(lVar7 + 0xb8) = *(longlong *)(lVar7 + 0xb8) + -0x48;
          *(char *)(lVar7 + 0x43) = *(char *)(lVar7 + 0x43) + -1;
          lVar2 = *(longlong *)(lVar4 + 0xb8);
          *(undefined4 *)(lVar5 + 0x38) = 0;
          *(code **)(lVar5 + 0x30) = BthEnumEnumerateWWSettings;
          *(code **)(lVar5 + 0x28) = BthEnumEnumerateProtocolOrDevice;
          *(code **)(lVar5 + 0x40) = BthEnumEnumerateFlags;
          *(longlong *)(lVar5 + 0x20) = param_1;
          *(undefined8 *)(lVar2 + -0x28) = 0;
          *(undefined2 *)(lVar2 + -0x48) = 0x81b;
          *(undefined **)(lVar2 + -0x40) = &GUID_BTHDDI_ENUMERATOR_INTERFACE;
          *(undefined4 *)(lVar2 + -0x38) = 0x2000048;
          *(longlong *)(lVar2 + -0x30) = lVar5;
          *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
          iVar3 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(lVar1 + 0x18),lVar4,'\0');
          if (-1 < iVar3) {
            *(longlong *)(lVar1 + 0xe8) = lVar5;
            lVar2 = *(longlong *)(lVar7 + 0xb8);
            *(undefined8 *)(lVar6 + 0x30) = 0;
            *(undefined8 *)(lVar6 + 0x40) = 0;
            *(code **)(lVar6 + 0x28) = BthEnumEnumerateProtocolOrDevice;
            *(longlong *)(lVar6 + 0x20) = param_1;
            *(undefined4 *)(lVar6 + 0x38) = 2;
            *(undefined8 *)(lVar2 + -0x28) = 0;
            *(undefined2 *)(lVar2 + -0x48) = 0x81b;
            *(undefined **)(lVar2 + -0x40) = &GUID_BTHDDI_ENUMERATOR_INTERFACE;
            *(undefined4 *)(lVar2 + -0x38) = 0x2000048;
            *(longlong *)(lVar2 + -0x30) = lVar6;
            *(undefined4 *)(lVar7 + 0x30) = 0xc00000bb;
            iVar3 = WaitForLowerDriverToCompleteIrp(*(undefined8 *)(lVar1 + 0x18),lVar7,'\0');
            if (-1 < iVar3) {
              *(longlong *)(lVar1 + 0xf0) = lVar6;
              goto LAB_14001d6e3;
            }
          }
          goto LAB_14001d6c0;
        }
        ExFreePool(0);
      }
      iVar3 = -0x3fffff66;
      goto LAB_14001d6c0;
    }
  }
  iVar3 = -0x3fffff66;
LAB_14001d6e3:
  IoFreeIrp(lVar4);
  if (lVar7 != 0) {
    IoFreeIrp(lVar7);
  }
  return iVar3;
}



===== BthEnumQueryProtocol @ 14001d850 =====

undefined8 BthEnumQueryProtocol(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined4 local_res8 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,1,0);
  lVar3 = IoBuildDeviceIoControlRequest
                    (0x12008c,*(undefined8 *)(lVar1 + 0x18),0,0,local_res8,4,1,&local_28,&local_38);
  if (lVar3 == 0) {
    return 0xc000009a;
  }
  iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18));
  if (iVar2 == 0x103) {
    lVar3 = 0;
    KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  else if (iVar2 < 0) goto LAB_14001d970;
  if (-1 < (int)local_38) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,3,0xc,
                        &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids,(char)local_res8[0]);
    }
    *(undefined4 *)(lVar1 + 0xd0) = local_res8[0];
    return 0;
  }
LAB_14001d970:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,3,0xd,
                     &WPP_1bade311f6663955504d4f7ce8ae9a67_Traceguids);
  }
  *(undefined4 *)(lVar1 + 0xd0) = 0;
  return 0;
}



===== BthEnumRegUpdateWWCapableCodMasks @ 14001d9d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BthEnumRegUpdateWWCapableCodMasks(longlong param_1,undefined8 param_2)

{
  size_t _Size;
  int iVar1;
  void *_Dst;
  uint uVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  undefined1 auStackY_1c8 [32];
  uint local_198 [2];
  undefined8 local_190;
  undefined8 uStack_188;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1c8;
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  local_198[0] = 0;
  local_190 = 0;
  uStack_188 = 0;
  memset(&local_178,0,0x140);
  RtlInitUnicodeString(&local_190,L"WaitWake Capable COD Masks");
  iVar1 = BthQueryKeyValueEx(param_2,(longlong)&local_190,&local_178,0x140,local_198);
  if ((iVar1 < 0) || (uVar2 = local_198[0] >> 3, uVar2 == 0)) {
    uVar2 = 2;
    local_178 = 0xfc1f0000;
    local_174 = 0x40050000;
    local_170 = 0xfc1f0000;
    local_16c = 0x80050000;
  }
  uVar5 = (ulonglong)uVar2;
  _Size = uVar5 * 8;
  _Dst = (void *)ExAllocatePool2(0x40,_Size,0x4f4d5442);
  *(void **)(param_1 + 0x78) = _Dst;
  if (_Dst == (void *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    if (uVar2 != 0) {
      puVar4 = (undefined1 *)((longlong)&local_174 + 1);
      do {
        *(uint *)(puVar4 + -1) =
             CONCAT31(CONCAT21(CONCAT11(puVar4[-1],*puVar4),puVar4[1]),puVar4[2]);
        *(uint *)(puVar4 + -5) =
             CONCAT31(CONCAT21(CONCAT11(puVar4[-5],puVar4[-4]),puVar4[-3]),puVar4[-2]);
        uVar5 = uVar5 - 1;
        puVar4 = puVar4 + 8;
      } while (uVar5 != 0);
    }
    memmove(_Dst,&local_178,_Size);
    *(uint *)(param_1 + 0x80) = uVar2;
  }
  return uVar3;
}



===== BthEnumWmi @ 14001db80 =====

undefined4 BthEnumWmi(longlong param_1,longlong param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = *(int **)(param_1 + 0x40);
  uVar3 = *(undefined4 *)(param_2 + 0x30);
  iVar1 = *piVar2;
  if (((iVar1 == 0x204f4450) ||
      (((iVar1 + 0xb0bbafbcU < 0x35 &&
        ((0x10000000010001U >> ((ulonglong)(iVar1 + 0xb0bbafbcU) & 0x3f) & 1) != 0)) ||
       (iVar1 == 0x44505478)))) || (iVar1 == 0x44504478)) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(*(undefined8 *)(piVar2 + 6),param_2);
  }
  return uVar3;
}



===== BthEnumGetConnectionCountKey @ 14001dc10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 BthEnumGetConnectionCountKey(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined1 auStackY_78 [32];
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [4];
  int local_24;
  undefined4 local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = 0;
  uStack_30 = 0;
  local_40 = 0;
  uVar2 = 1;
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x10),1,1,&local_40);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,3,0xb,
                        &WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids,(char)iVar1);
    }
    uVar4 = 0;
  }
  else {
    RtlInitUnicodeString(&local_38,L"ConnectionCount");
    puVar3 = &local_38;
    iVar1 = ZwQueryValueKey(local_40,puVar3,2,local_28);
    uVar4 = 0;
    if ((-1 < iVar1) && (local_24 == 4)) {
      uVar4 = local_1c;
    }
    ZwClose(local_40);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,3,0xc,
                        &WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids,(char)uVar4);
    }
  }
  return uVar4;
}



===== BthEnumUpdateProfileConnectionCountKey @ 14001dd5c =====

undefined4 BthEnumUpdateProfileConnectionCountKey(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_res8 [2];
  undefined8 local_res10 [3];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  uVar2 = 1;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x10),1,3,local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,3,0xd,
                        &WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids,(char)iVar1);
    }
    local_res8[0] = 0;
  }
  else {
    RtlInitUnicodeString(&local_18,L"ConnectionCount");
    local_res8[0] = *(undefined4 *)(param_1 + 0xb6c);
    ZwSetValueKey(local_res10[0],&local_18,0,4,local_res8,4);
    ZwClose(local_res10[0]);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  return local_res8[0];
}



===== WaitForLowerDriverToCompleteIrp @ 14001de78 =====

undefined4 WaitForLowerDriverToCompleteIrp(undefined8 param_1,longlong param_2,char param_3)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,0,0);
  if (param_3 != '\0') {
    puVar1 = *(undefined8 **)(param_2 + 0xb8);
    puVar1[-9] = *puVar1;
    puVar1[-8] = puVar1[1];
    puVar1[-7] = puVar1[2];
    puVar1[-6] = puVar1[3];
    *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
    *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
    *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
    *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
    puVar1[-3] = puVar1[6];
    *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  }
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar3 + -0x10) = IoCompletionSetEvent;
  *(undefined8 **)(lVar3 + -8) = &local_28;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  lVar3 = param_2;
  iVar2 = IofCallDriver(param_1);
  if (iVar2 == 0x103) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,1,0x11,
                       &WPP_f24dc5fc8d98372b7b5478949da3430c_Traceguids);
    }
    KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  return *(undefined4 *)(param_2 + 0x30);
}



===== BthEnumCheckGuidAgainstRegistry @ 14001df8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BthEnumCheckGuidAgainstRegistry(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 auStackY_c8 [32];
  undefined4 local_98 [2];
  undefined8 local_90;
  wchar_t local_88 [39];
  undefined2 local_3a;
  undefined1 local_28 [8];
  undefined4 local_20;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_3a = 0;
  pwVar3 = local_88;
  memset(pwVar3,0,0x5e);
  local_90 = 0;
  local_98[0] = 0;
  uVar1 = BthOpenKey(pwVar3,
                     L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\BTHPORT\\Parameters\\HciBypassServices"
                     ,&local_90);
  if (-1 < (int)uVar1) {
    uVar5 = 0;
    do {
      GS_Init(local_88,(uint *)(uVar5 * 0x10 + param_1));
      local_20 = 4;
      pwVar3 = local_88;
      uVar2 = BthQueryKeyValueUlong(local_90,pwVar3,(longlong)local_28,local_98);
      uVar1 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar3,3,0x28,
                            &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)uVar2);
        }
        break;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 == 0);
    ZwClose(local_90);
  }
  return uVar1;
}



===== BthEnumChildCompare @ 14001e0a8 =====

void BthEnumChildCompare(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(int *)(param_1 + 0x410) == *(int *)(param_2 + 0x3c0)) {
    RtlInitUnicodeString(&local_18,*(undefined8 *)(param_1 + 0x38));
    RtlInitUnicodeString(&local_28,*(undefined8 *)(param_2 + -0x18));
    iVar1 = RtlCompareUnicodeString(&local_18,&local_28,0);
    if (iVar1 == 0) {
      RtlInitUnicodeString(&local_18,param_1 + 0x18);
      RtlInitUnicodeString(&local_28,param_2 + -0x38);
      iVar1 = RtlCompareUnicodeString(&local_18,&local_28,0);
      if ((iVar1 == 0) && (*(int *)(param_1 + 0x430) == *(int *)(param_2 + 0x3e0))) {
        RtlInitUnicodeString(&local_18,param_1 + 0x434);
        RtlInitUnicodeString(&local_28,param_2 + 0x3e4);
        RtlCompareUnicodeString(&local_18,&local_28,0);
      }
    }
  }
  return;
}



===== BthEnumDestroyPdoExt @ 14001e1d4 =====

void BthEnumDestroyPdoExt(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x48) != 0) {
    ExFreePool();
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    ExFreePool();
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  RtlFreeUnicodeString(param_1 + 0xb48);
  RtlFreeUnicodeString(param_1 + 0xb58);
  return;
}



===== BthEnumEnumerateProtocolOrDevice @ 14001e250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BthEnumEnumerateProtocolOrDevice(longlong param_1,wchar_t *param_2,wchar_t *param_3)

{
  ulonglong *puVar1;
  byte bVar2;
  uint uVar3;
  wchar_t *pwVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  ulonglong *puVar12;
  wchar_t *pwVar13;
  undefined8 *puVar14;
  wchar_t *pwVar15;
  wchar_t *pwVar16;
  wchar_t *pwVar17;
  ulonglong *puVar18;
  undefined8 uVar19;
  undefined2 uVar20;
  longlong lVar21;
  undefined1 auStackY_108 [32];
  undefined8 in_stack_ffffffffffffff18;
  uint uVar24;
  ulonglong uVar22;
  undefined4 uVar25;
  undefined *puVar23;
  undefined1 uVar26;
  int local_c0 [2];
  longlong local_b8;
  longlong local_b0;
  undefined8 local_a8;
  undefined8 *puStack_a0;
  undefined8 local_98;
  longlong lStack_90;
  undefined8 local_88;
  wchar_t *pwStack_80;
  ulonglong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  uVar24 = (uint)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  iVar7 = 0;
  uVar11 = 0;
  local_88 = 0;
  pwStack_80 = (wchar_t *)0x0;
  if (param_2 != (wchar_t *)0x0) {
    uVar11 = *(ulonglong *)(param_2 + 4);
  }
  local_c0[0] = 0;
  local_98 = 0;
  lStack_90 = 0;
  lVar21 = 0;
  local_a8 = 0;
  puStack_a0 = (undefined8 *)0x0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  local_b8 = *(longlong *)(param_1 + 0x40);
  uVar3 = *(uint *)param_3;
  pwVar15 = (wchar_t *)(ulonglong)uVar3;
  if ((int)uVar3 < 3) {
    iVar8 = *(int *)(param_3 + 2);
    if (iVar8 == 0) {
      if (uVar3 == 1) {
        pwVar15 = param_3 + 8;
        lVar9 = RtlCompareMemory(&DialupNetworkingServiceClass_UUID,pwVar15,0x10);
        if (((lVar9 != 0x10) &&
            (lVar9 = RtlCompareMemory(&SerialPortServiceClass_UUID,pwVar15,0x10), lVar9 != 0x10)) &&
           (lVar9 = RtlCompareMemory(&FaxServiceClass_UUID,pwVar15,0x10), lVar9 != 0x10))
        goto LAB_14001e35f;
      }
      RtlInitUnicodeString(&local_88,0);
      pwVar15 = (wchar_t *)&local_88;
      iVar7 = RtlStringFromGUID(param_3 + 8);
      if (iVar7 < 0) {
        iVar7 = -0x3fffff66;
      }
      else {
        pwVar15 = (wchar_t *)0xb70;
        lVar21 = ExAllocatePool2(0x100,0xb70,0x4f4d5442);
        local_b0 = lVar21;
        if (lVar21 == 0) {
          iVar7 = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar20 = 0x1f;
            uVar26 = 0x9a;
LAB_14001e4ad:
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar15,4,uVar20,
                              &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,uVar26);
          }
        }
        else {
          uVar22 = (ulonglong)uVar24 << 0x20;
          pwVar15 = (wchar_t *)0x1a;
          uVar10 = RtlStringCbPrintfW((wchar_t *)(lVar21 + 0x18),0x1a,L"%04X%08X",
                                      uVar11 >> 0x20 & 0xffff);
          iVar7 = (int)uVar10;
          if (-1 < iVar7) {
            *(wchar_t **)(lVar21 + 0x38) = pwStack_80;
            pwVar15 = param_3;
            memmove((void *)(lVar21 + 0x410),param_3,0x730);
            KeEnterCriticalRegion();
            lVar9 = local_b8;
            ExAcquireFastMutexUnsafe(local_b8 + 0x98);
            pwVar16 = *(wchar_t **)(lVar9 + 0x88U);
            if (((*(byte *)(lVar9 + 0x90) & 1) != 0) && (pwVar16 != (wchar_t *)0x0)) {
              pwVar16 = (wchar_t *)((ulonglong)pwVar16 ^ (ulonglong)(lVar9 + 0x88U));
            }
            bVar2 = *(byte *)(lVar9 + 0x90);
            while (pwVar4 = pwVar16, pwVar4 != (wchar_t *)0x0) {
              pwVar15 = pwVar4;
              iVar7 = BthEnumChildCompare(lVar21,(longlong)pwVar4);
              if (iVar7 < 0) {
                pwVar16 = *(wchar_t **)pwVar4;
              }
              else {
                if (iVar7 < 1) break;
                pwVar16 = *(wchar_t **)(pwVar4 + 4);
              }
              if (((bVar2 & 1) != 0) && (pwVar16 != (wchar_t *)0x0)) {
                pwVar16 = (wchar_t *)((ulonglong)pwVar4 ^ (ulonglong)pwVar16);
              }
            }
            uVar25 = (undefined4)(uVar22 >> 0x20);
            iVar7 = 0;
            if (pwVar4 == (wchar_t *)0x0) {
              if (*(int *)param_3 == 1) {
                lVar21 = RtlCompareMemory(&DialupNetworkingServiceClass_UUID,param_3 + 8,0x10);
                if (lVar21 != 0x10) {
                  lVar21 = RtlCompareMemory(&SerialPortServiceClass_UUID,param_3 + 8,0x10);
                  uVar25 = (undefined4)(uVar22 >> 0x20);
                  if (lVar21 != 0x10) goto LAB_14001e8a4;
                }
                local_98._0_4_ = CONCAT22(0x100,(undefined2)local_98);
                pwVar15 = (wchar_t *)0x102;
                lStack_90 = ExAllocatePool2(0x100,0x102,0x4f4d5442);
                if (lStack_90 == 0) {
                  iVar7 = -0x3fffff66;
                }
                else {
                  pwVar15 = L"\\Device\\BthModem";
                  iVar7 = RtlAppendUnicodeToString(&local_98);
                  if (-1 < iVar7) {
                    RtlInitUnicodeString(&local_a8,0);
                    iVar7 = DAT_140015200;
                    local_a8 = CONCAT44(local_a8._4_4_,0x280000);
                    local_50 = 0;
                    puStack_a0 = &local_70;
                    pwVar15 = (wchar_t *)0xa;
                    DAT_140015200 = DAT_140015200 + 1;
                    local_70 = 0;
                    uStack_68 = 0;
                    local_60 = 0;
                    uStack_58 = 0;
                    iVar7 = RtlIntegerToUnicodeString(iVar7,10,&local_a8);
                    if (-1 < iVar7) {
                      pwVar15 = (wchar_t *)&local_a8;
                      iVar7 = RtlAppendUnicodeStringToString(&local_98);
                      if (-1 < iVar7) {
                        pwVar15 = (wchar_t *)0xb70;
                        puVar23 = (undefined *)(uVar22 & 0xffffffff00000000);
                        iVar7 = IoCreateDevice(*(undefined8 *)(param_1 + 8),0xb70,&local_98,0x22);
                        ExFreePool(lStack_90);
                        goto LAB_14001e8dd;
                      }
                    }
                  }
                }
              }
              else {
LAB_14001e8a4:
                pwVar15 = (wchar_t *)0xb70;
                puVar23 = (undefined *)CONCAT44(uVar25,0x80);
                iVar7 = IoCreateDevice(*(undefined8 *)(param_1 + 8),0xb70,0,0x22);
LAB_14001e8dd:
                puVar5 = puRam0000000000000040;
                if (-1 < iVar7) {
                  memset(puRam0000000000000040,0,0xb70);
                  iVar8 = *(int *)param_3;
                  if (iVar8 == 0) {
                    *puVar5 = 0x4f445054;
                  }
                  else if (iVar8 == 1) {
                    *puVar5 = 0x204f4450;
                  }
                  else if (iVar8 == 2) {
                    *puVar5 = 0x4f445044;
                  }
                  *(longlong *)(puVar5 + 2) = param_1;
                  *(undefined8 *)(puVar5 + 4) = 0;
                  puVar5[0x2d] = 0;
                  *(wchar_t **)(puVar5 + 0xe) = pwStack_80;
                  puVar5[0x2c] = 0;
                  *(undefined1 *)(puVar5 + 0x2da) = 0;
                  if ((*(longlong *)(puVar5 + 0x12) == 0) &&
                     (pwVar15 = param_3 + 0x217, pwVar15 != (wchar_t *)0x0)) {
                    lVar21 = 0x100;
                    do {
                      if ((char)*pwVar15 == '\0') break;
                      pwVar15 = (wchar_t *)((longlong)pwVar15 + 1);
                      lVar21 = lVar21 + -1;
                    } while (lVar21 != 0);
                    local_78 = 0x100 - lVar21;
                    uVar11 = -(ulonglong)(lVar21 != 0) & local_78;
                    if ((lVar21 != 0) && (uVar11 != 0)) {
                      iVar8 = (int)uVar11;
                      local_c0[0] = iVar8 * 2 + 2;
                      lVar21 = ExAllocatePool2(0x40,local_c0[0],0x4f4d5442);
                      *(longlong *)(puVar5 + 0x12) = lVar21;
                      if (lVar21 != 0) {
                        puVar23 = (undefined *)CONCAT44((int)((ulonglong)puVar23 >> 0x20),iVar8);
                        iVar8 = RtlUTF8ToUnicodeN(lVar21,local_c0[0],local_c0,param_3 + 0x217);
                        if (iVar8 < 0) {
                          ExFreePoolWithTag(*(undefined8 *)(puVar5 + 0x12),0x42544d45);
                          *(undefined8 *)(puVar5 + 0x12) = 0;
                        }
                      }
                    }
                  }
                  uVar19 = 0x730;
                  uVar10 = *(undefined8 *)(local_b0 + 0x20);
                  *(undefined8 *)(puVar5 + 6) = *(undefined8 *)(local_b0 + 0x18);
                  *(undefined8 *)(puVar5 + 8) = uVar10;
                  *(undefined8 *)(puVar5 + 10) = *(undefined8 *)(local_b0 + 0x28);
                  *(undefined2 *)(puVar5 + 0xc) = *(undefined2 *)(local_b0 + 0x30);
                  cRam000000000000004c = cRam000000000000004c + *(char *)(param_1 + 0x4c);
                  memmove(puVar5 + 0x104,param_3,0x730);
                  lVar21 = local_b8;
                  if (param_2 != (wchar_t *)0x0) {
                    lVar9 = 6;
                    puVar6 = (undefined8 *)(puVar5 + 0x2e);
                    do {
                      pwVar15 = param_2;
                      puVar14 = puVar6;
                      uVar10 = *(undefined8 *)(pwVar15 + 4);
                      *puVar14 = *(undefined8 *)pwVar15;
                      puVar14[1] = uVar10;
                      uVar10 = *(undefined8 *)(pwVar15 + 0xc);
                      puVar14[2] = *(undefined8 *)(pwVar15 + 8);
                      puVar14[3] = uVar10;
                      uVar10 = *(undefined8 *)(pwVar15 + 0x14);
                      puVar14[4] = *(undefined8 *)(pwVar15 + 0x10);
                      puVar14[5] = uVar10;
                      uVar10 = *(undefined8 *)(pwVar15 + 0x1c);
                      puVar14[6] = *(undefined8 *)(pwVar15 + 0x18);
                      puVar14[7] = uVar10;
                      uVar10 = *(undefined8 *)(pwVar15 + 0x24);
                      puVar14[8] = *(undefined8 *)(pwVar15 + 0x20);
                      puVar14[9] = uVar10;
                      uVar10 = *(undefined8 *)(pwVar15 + 0x2c);
                      puVar14[10] = *(undefined8 *)(pwVar15 + 0x28);
                      puVar14[0xb] = uVar10;
                      uVar10 = *(undefined8 *)(pwVar15 + 0x34);
                      puVar14[0xc] = *(undefined8 *)(pwVar15 + 0x30);
                      puVar14[0xd] = uVar10;
                      uVar10 = *(undefined8 *)(pwVar15 + 0x3c);
                      puVar14[0xe] = *(undefined8 *)(pwVar15 + 0x38);
                      puVar14[0xf] = uVar10;
                      lVar9 = lVar9 + -1;
                      puVar6 = puVar14 + 0x10;
                      param_2 = pwVar15 + 0x40;
                    } while (lVar9 != 0);
                    uVar10 = *(undefined8 *)(pwVar15 + 0x44);
                    puVar14[0x10] = *(undefined8 *)(pwVar15 + 0x40);
                    puVar14[0x11] = uVar10;
                    uVar10 = *(undefined8 *)(pwVar15 + 0x4c);
                    puVar14[0x12] = *(undefined8 *)(pwVar15 + 0x48);
                    puVar14[0x13] = uVar10;
                    uVar10 = *(undefined8 *)(pwVar15 + 0x54);
                    puVar14[0x14] = *(undefined8 *)(pwVar15 + 0x50);
                    puVar14[0x15] = uVar10;
                    uVar10 = *(undefined8 *)(pwVar15 + 0x5c);
                    puVar14[0x16] = *(undefined8 *)(pwVar15 + 0x58);
                    puVar14[0x17] = uVar10;
                    uVar10 = *(undefined8 *)(pwVar15 + 100);
                    puVar14[0x18] = *(undefined8 *)(pwVar15 + 0x60);
                    puVar14[0x19] = uVar10;
                    puVar14[0x1a] = *(undefined8 *)(pwVar15 + 0x68);
                  }
                  *(undefined8 *)(puVar5 + 0x2a) = 0;
                  if ((*(uint *)(local_b8 + 0xf8) & 1) != 0) {
                    uVar11 = BthEnumCheckGuidAgainstRegistry((longlong)(puVar5 + 0x108));
                    iVar7 = (int)uVar11;
                    if (iVar7 < 0) {
                      puVar5[0x2d0] = 0;
                      iVar7 = 0;
                    }
                    else {
                      puVar5[0x2d0] = 1;
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        puVar23 = &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids;
                        uVar19 = 3;
                        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,3,0x21,
                                         &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids);
                      }
                    }
                  }
                  if ((*(uint *)(param_1 + 0x30) & 4) != 0) {
                    uRam0000000000000030 = uRam0000000000000030 | 4;
                  }
                  if ((*(uint *)(param_1 + 0x30) & 0x10) != 0) {
                    uRam0000000000000030 = uRam0000000000000030 | 4;
                  }
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_SS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,uVar19,
                                       0x22,puVar23,pwStack_80,(wchar_t *)(puVar5 + 6));
                  }
                  puVar1 = (ulonglong *)(lVar21 + 0x88);
                  if ((*(byte *)(lVar21 + 0x90) & 1) == 0) {
                    puVar18 = (ulonglong *)*puVar1;
                  }
                  else if (*puVar1 == 0) {
                    puVar18 = (ulonglong *)0x0;
                  }
                  else {
                    puVar18 = (ulonglong *)((ulonglong)puVar1 ^ *puVar1);
                  }
                  bVar2 = *(byte *)(lVar21 + 0x90);
                  uVar10 = 0;
                  if (puVar18 != (ulonglong *)0x0) {
                    do {
                      iVar8 = BthEnumChildCompare((longlong)puVar5,(longlong)puVar18);
                      if (iVar8 < 0) {
                        puVar12 = (ulonglong *)*puVar18;
                        if ((bVar2 & 1) == 0) {
LAB_14001ec12:
                          if (puVar12 != (ulonglong *)0x0) goto LAB_14001ec17;
                        }
                        else if (puVar12 != (ulonglong *)0x0) {
                          puVar12 = (ulonglong *)((ulonglong)puVar12 ^ (ulonglong)puVar18);
                          goto LAB_14001ec12;
                        }
                        uVar10 = 0;
                        break;
                      }
                      puVar12 = (ulonglong *)puVar18[1];
                      if ((bVar2 & 1) != 0) {
                        if (puVar12 == (ulonglong *)0x0) goto LAB_14001ebfd;
                        puVar12 = (ulonglong *)((ulonglong)puVar12 ^ (ulonglong)puVar18);
                      }
                      if (puVar12 == (ulonglong *)0x0) goto LAB_14001ebfd;
LAB_14001ec17:
                      puVar18 = puVar12;
                    } while( true );
                  }
                  goto LAB_14001ec1f;
                }
              }
            }
            else {
              if (*(int *)param_3 == 2) {
                if (param_2 != (wchar_t *)0x0) {
                  lVar21 = 6;
                  pwVar16 = pwVar4 + 0x34;
                  do {
                    pwVar17 = param_2;
                    pwVar13 = pwVar16;
                    uVar10 = *(undefined8 *)(pwVar17 + 4);
                    *(undefined8 *)pwVar13 = *(undefined8 *)pwVar17;
                    *(undefined8 *)(pwVar13 + 4) = uVar10;
                    uVar10 = *(undefined8 *)(pwVar17 + 0xc);
                    *(undefined8 *)(pwVar13 + 8) = *(undefined8 *)(pwVar17 + 8);
                    *(undefined8 *)(pwVar13 + 0xc) = uVar10;
                    uVar10 = *(undefined8 *)(pwVar17 + 0x14);
                    *(undefined8 *)(pwVar13 + 0x10) = *(undefined8 *)(pwVar17 + 0x10);
                    *(undefined8 *)(pwVar13 + 0x14) = uVar10;
                    uVar10 = *(undefined8 *)(pwVar17 + 0x1c);
                    *(undefined8 *)(pwVar13 + 0x18) = *(undefined8 *)(pwVar17 + 0x18);
                    *(undefined8 *)(pwVar13 + 0x1c) = uVar10;
                    uVar10 = *(undefined8 *)(pwVar17 + 0x24);
                    *(undefined8 *)(pwVar13 + 0x20) = *(undefined8 *)(pwVar17 + 0x20);
                    *(undefined8 *)(pwVar13 + 0x24) = uVar10;
                    uVar10 = *(undefined8 *)(pwVar17 + 0x2c);
                    *(undefined8 *)(pwVar13 + 0x28) = *(undefined8 *)(pwVar17 + 0x28);
                    *(undefined8 *)(pwVar13 + 0x2c) = uVar10;
                    uVar10 = *(undefined8 *)(pwVar17 + 0x34);
                    *(undefined8 *)(pwVar13 + 0x30) = *(undefined8 *)(pwVar17 + 0x30);
                    *(undefined8 *)(pwVar13 + 0x34) = uVar10;
                    uVar10 = *(undefined8 *)(pwVar17 + 0x3c);
                    *(undefined8 *)(pwVar13 + 0x38) = *(undefined8 *)(pwVar17 + 0x38);
                    *(undefined8 *)(pwVar13 + 0x3c) = uVar10;
                    lVar21 = lVar21 + -1;
                    pwVar16 = pwVar13 + 0x40;
                    param_2 = pwVar17 + 0x40;
                  } while (lVar21 != 0);
                  uVar10 = *(undefined8 *)(pwVar17 + 0x44);
                  *(undefined8 *)(pwVar13 + 0x40) = *(undefined8 *)(pwVar17 + 0x40);
                  *(undefined8 *)(pwVar13 + 0x44) = uVar10;
                  uVar10 = *(undefined8 *)(pwVar17 + 0x4c);
                  *(undefined8 *)(pwVar13 + 0x48) = *(undefined8 *)(pwVar17 + 0x48);
                  *(undefined8 *)(pwVar13 + 0x4c) = uVar10;
                  uVar10 = *(undefined8 *)(pwVar17 + 0x54);
                  *(undefined8 *)(pwVar13 + 0x50) = *(undefined8 *)(pwVar17 + 0x50);
                  *(undefined8 *)(pwVar13 + 0x54) = uVar10;
                  uVar10 = *(undefined8 *)(pwVar17 + 0x5c);
                  *(undefined8 *)(pwVar13 + 0x58) = *(undefined8 *)(pwVar17 + 0x58);
                  *(undefined8 *)(pwVar13 + 0x5c) = uVar10;
                  uVar10 = *(undefined8 *)(pwVar17 + 100);
                  *(undefined8 *)(pwVar13 + 0x60) = *(undefined8 *)(pwVar17 + 0x60);
                  *(undefined8 *)(pwVar13 + 100) = uVar10;
                  *(undefined8 *)(pwVar13 + 0x68) = *(undefined8 *)(pwVar17 + 0x68);
                }
                if (((param_3[0x116] != L'\0') && (param_3[0x112] != L'\0')) &&
                   (param_3[0x113] != L'\0')) {
                  pwVar4[0x2f6] = param_3[0x116];
                  pwVar4[0x2f2] = param_3[0x112];
                  pwVar4[0x2f3] = param_3[0x113];
                }
                if ((char)pwVar4[0x58c] != '\0') {
                  pwVar15 = (wchar_t *)0x0;
                  BthEnumSetDevicePdoProperties((longlong)(pwVar4 + -0x28),0);
                  IoInvalidateDeviceState(*(undefined8 *)(pwVar4 + -0x20));
                }
                uVar11 = Feature_56664216__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar11 != 0) goto LAB_14001e6d1;
              }
              iVar7 = -0x3ffffff3;
            }
LAB_14001e6d1:
            ExReleaseFastMutexUnsafe(local_b8 + 0x98);
            KeLeaveCriticalRegion();
            goto LAB_14001e6f4;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar20 = 0x20;
            uVar26 = (undefined1)uVar10;
            goto LAB_14001e4ad;
          }
        }
      }
      goto LAB_14001e703;
    }
    if ((iVar8 == 1) || (iVar8 == 2)) {
      BthEnumRemoveProtocol(param_1,(longlong)param_2,(undefined8 *)param_3);
      pwVar15 = param_2;
      goto LAB_14001e35f;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar15,4,0x1e,
                     &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids);
  }
  iVar7 = -0x3ffffff3;
LAB_14001e703:
  RtlFreeUnicodeString(&local_88);
  if (lVar21 == 0) goto LAB_14001e35f;
LAB_14001e71c:
  ExFreePool(lVar21);
LAB_14001e35f:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar15,4,0x23,
                      &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)iVar7);
  }
  return iVar7;
LAB_14001ebfd:
  uVar10 = 1;
LAB_14001ec1f:
  RtlRbInsertNodeEx(puVar1,puVar18,uVar10,puVar5 + 0x14);
  *(int *)(lVar21 + 0xfc) = *(int *)(lVar21 + 0xfc) + 1;
  ExReleaseFastMutexUnsafe(lVar21 + 0x98);
  KeLeaveCriticalRegion();
  pwVar15 = (wchar_t *)0x0;
  uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f | 0x2000;
  IoInvalidateDeviceRelations(*(undefined8 *)(lVar21 + 0x10));
LAB_14001e6f4:
  lVar21 = local_b0;
  if (iVar7 < 0) goto LAB_14001e703;
  goto LAB_14001e71c;
}



===== BthEnumRemoveProtocol @ 14001ec90 =====

void BthEnumRemoveProtocol(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  ulonglong *puVar2;
  byte bVar3;
  longlong lVar4;
  bool bVar5;
  int iVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  wchar_t *pwVar12;
  undefined2 uVar13;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar15;
  undefined8 uVar14;
  undefined8 local_38;
  wchar_t *pwStack_30;
  
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  local_38 = 0;
  pwStack_30 = (wchar_t *)0x0;
  if (param_2 == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = *(ulonglong *)(param_2 + 8);
  }
  lVar4 = *(longlong *)(param_1 + 0x40);
  uVar9 = 0xb70;
  bVar5 = false;
  lVar7 = ExAllocatePool2(0x100,0xb70,0x4f4d5442);
  if (lVar7 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,4,0x14,
                        &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,0x9a);
    }
    goto LAB_14001f082;
  }
  uVar14 = CONCAT44(uVar15,(int)uVar11);
  pwVar12 = L"%04X%08X";
  puVar10 = (undefined8 *)0x1a;
  uVar9 = RtlStringCbPrintfW((wchar_t *)(lVar7 + 0x18),0x1a,L"%04X%08X",uVar11 >> 0x20 & 0xffff);
  iVar6 = (int)uVar9;
  if (iVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar13 = 0x15;
LAB_14001ed78:
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar10,4,uVar13,
                        &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)iVar6);
    }
  }
  else {
    RtlInitUnicodeString(&local_38,0);
    puVar10 = &local_38;
    iVar6 = RtlStringFromGUID(param_3 + 2);
    if (iVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar13 = 0x16;
        goto LAB_14001ed78;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_SS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar10,pwVar12,0x17,uVar14,
                           pwStack_30,(wchar_t *)(lVar7 + 0x18));
      }
      *(wchar_t **)(lVar7 + 0x38) = pwStack_30;
      memmove((void *)(lVar7 + 0x410),param_3,0x730);
      KeEnterCriticalRegion();
      lVar1 = lVar4 + 0x98;
      ExAcquireFastMutexUnsafe(lVar1);
      puVar2 = (ulonglong *)(lVar4 + 0x88);
      puVar10 = (undefined8 *)*puVar2;
      if (((*(byte *)(lVar4 + 0x90) & 1) != 0) && (puVar10 != (undefined8 *)0x0)) {
        puVar10 = (undefined8 *)((ulonglong)puVar10 ^ (ulonglong)puVar2);
      }
      bVar3 = *(byte *)(lVar4 + 0x90);
      while (puVar10 != (undefined8 *)0x0) {
        param_3 = puVar10;
        iVar6 = BthEnumChildCompare(lVar7,(longlong)puVar10);
        if (iVar6 < 0) {
          puVar8 = (undefined8 *)*puVar10;
        }
        else {
          if (iVar6 < 1) break;
          puVar8 = (undefined8 *)puVar10[1];
        }
        if (((bVar3 & 1) == 0) || (puVar8 == (undefined8 *)0x0)) {
          puVar10 = puVar8;
        }
        else {
          puVar10 = (undefined8 *)((ulonglong)puVar10 ^ (ulonglong)puVar8);
        }
      }
      if (puVar10 == (undefined8 *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,4,0x18,
                           &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids);
        }
        ExReleaseFastMutexUnsafe(lVar1);
        KeLeaveCriticalRegion();
      }
      else {
        iVar6 = *(int *)(puVar10 + 0xc);
        if (iVar6 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,4,0x19,
                              &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)puVar10[-8]);
          }
          *(undefined4 *)(puVar10 + 0xc) = 3;
          RtlRbRemoveNode(puVar2,puVar10);
          *(int *)(lVar4 + 0xfc) = *(int *)(lVar4 + 0xfc) + -1;
          bVar5 = true;
        }
        else if (iVar6 == 1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x1a,
                              &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)puVar10[-8]);
          }
          *(undefined4 *)(puVar10 + 0xc) = 2;
        }
        else if (iVar6 == 3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x1b,
                              &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)puVar10[-8]);
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        ExReleaseFastMutexUnsafe(lVar1);
        KeLeaveCriticalRegion();
        if (bVar5) {
          BthEnumDestroyPdoExt((longlong)(puVar10 + -10));
          IoDeleteDevice(puVar10[-8]);
        }
        IoInvalidateDeviceRelations(*(undefined8 *)(lVar4 + 0x10),0);
      }
    }
  }
  ExFreePool(lVar7);
LAB_14001f082:
  RtlFreeUnicodeString(&local_38);
  return;
}



===== BthEnumReportID @ 14001f0b8 =====

void BthEnumReportID(longlong param_1,uint *param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint *puVar3;
  undefined2 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x60);
  puVar3 = param_2;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x60) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0xf,
                        &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,
                        (char)*(undefined8 *)(param_1 + -0x40));
    }
  }
  else if (iVar1 != 1) {
    if (iVar1 == 2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x11,
                          &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,
                          (char)*(undefined8 *)(param_1 + -0x40));
      }
      *(undefined4 *)(param_1 + 0x60) = 3;
      return;
    }
    if (iVar1 != 3) {
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar2 = (undefined1)*(undefined8 *)(param_1 + -0x40);
    uVar4 = 0x12;
    goto LAB_14001f1e8;
  }
  *(undefined8 *)(param_2 + (ulonglong)*param_2 * 2 + 2) = *(undefined8 *)(param_1 + -0x40);
  ObfReferenceObject(*(undefined8 *)(param_2 + (ulonglong)*param_2 * 2 + 2));
  *param_2 = *param_2 + 1;
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return;
  }
  uVar2 = (undefined1)*(undefined8 *)(param_1 + -0x40);
  uVar4 = 0x10;
LAB_14001f1e8:
  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,4,uVar4,
                    &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,uVar2);
  return;
}



===== BthEnumUnregisterDeviceInterface @ 14001f224 =====

int BthEnumUnregisterDeviceInterface(longlong param_1,char param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = 0;
  if (*(longlong *)(param_1 + 0xb50) != 0) {
    uVar2 = 0;
    iVar1 = IoSetDeviceInterfaceState(param_1 + 0xb48);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,4,10,
                        &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)iVar1);
    }
    if (param_2 != '\0') {
      RtlFreeUnicodeString(param_1 + 0xb48);
    }
  }
  if (*(longlong *)(param_1 + 0xb60) != 0) {
    uVar2 = 0;
    iVar1 = IoSetDeviceInterfaceState(param_1 + 0xb58);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,4,0xb,
                        &WPP_3ad0aac993a937fca10a477fa33a3037_Traceguids,(char)iVar1);
    }
    if (param_2 != '\0') {
      RtlFreeUnicodeString(param_1 + 0xb58);
    }
  }
  return iVar1;
}



===== BthEnumIoctl @ 14001f350 =====

void BthEnumIoctl(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 0x204f4446) {
    uVar2 = *(undefined8 *)(piVar1 + 6);
  }
  else {
    uVar2 = *(undefined8 *)(*(longlong *)(*(longlong *)(piVar1 + 2) + 0x40) + 0x18);
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(uVar2);
  return;
}



===== BthCheckForUnsupportedServiceID @ 14001f398 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BthCheckForUnsupportedServiceID(ulonglong *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined1 auStack_158 [32];
  uint local_138;
  undefined4 *local_130;
  uint local_128;
  uint local_120;
  uint local_118;
  uint local_110;
  uint local_108;
  uint local_100;
  uint local_f8;
  uint local_f0;
  undefined4 local_e8 [4];
  undefined8 local_d8;
  undefined8 uStack_d0;
  longlong local_c8 [5];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  longlong *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  wchar_t local_68 [40];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  local_d8 = *param_1;
  uStack_d0 = param_1[1];
  local_c8[0] = 0;
  local_84 = 0;
  local_e8[0] = 0;
  local_9c = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[1] = 0;
  local_c8[2] = 0;
  RtlInitUnicodeString
            (local_c8 + 3,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\BTHPORT\\Parameters\\UnsupportedServices"
            );
  local_98 = 0;
  local_90 = local_c8 + 3;
  local_a0 = 0x30;
  local_88 = 0x240;
  local_80 = 0;
  uStack_78 = 0;
  iVar2 = ZwOpenKey(local_c8,0x20019,&local_a0);
  if (-1 < iVar2) {
    local_f0 = (uint)uStack_d0._7_1_;
    local_f8 = (uint)uStack_d0._6_1_;
    local_100 = (uint)uStack_d0._5_1_;
    local_108 = (uint)uStack_d0._4_1_;
    local_110 = (uint)uStack_d0._3_1_;
    local_118 = (uint)uStack_d0._2_1_;
    local_120 = (uint)uStack_d0._1_1_;
    local_128 = (uint)(byte)uStack_d0;
    local_130 = (undefined4 *)CONCAT44(local_130._4_4_,(uint)local_d8._6_2_);
    local_138 = (uint)local_d8._4_2_;
    RtlStringCchPrintfW(local_68,0x28,L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
                        local_d8 & 0xffffffff);
    RtlInitUnicodeString(local_c8 + 1,local_68);
    local_130 = local_e8;
    local_138 = 0;
    iVar2 = ZwQueryValueKey(local_c8[0],local_c8 + 1,0,0);
    uVar1 = local_e8[0];
    if ((iVar2 == -0x3fffffdd) || (iVar2 == -0x7ffffffb)) {
      lVar4 = ExAllocatePool2(0x40,local_e8[0],0x6c687442);
      if (lVar4 != 0) {
        local_130 = local_e8;
        local_138 = uVar1;
        iVar3 = ZwQueryValueKey(local_c8[0],local_c8 + 1,0,lVar4);
        ExFreePoolWithTag(lVar4,0x6c687442);
        iVar2 = 0;
        if (iVar3 < 0) {
          iVar2 = iVar3;
        }
      }
    }
  }
  if (local_c8[0] != 0) {
    ZwClose();
  }
  return iVar2;
}



===== BthOpenKey @ 14001f5b0 =====

void BthOpenKey(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_48);
  local_38 = 0x30;
  local_30 = 0;
  local_28 = &local_48;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  ZwOpenKey(param_3,0xf003f,&local_38);
  return;
}



===== BthOpenKeyEx @ 14001f628 =====

void BthOpenKeyEx(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_30 = 0;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = param_2;
  ZwOpenKey(param_3,0xf003f,&local_38);
  return;
}



===== BthQueryKeyValueEx @ 14001f67c =====

int BthQueryKeyValueEx(undefined8 param_1,longlong param_2,void *param_3,uint param_4,
                      undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint local_res20 [2];
  
  uVar1 = *(ushort *)(param_2 + 2) + 0x18;
  local_res20[0] = param_4 + uVar1;
  if (local_res20[0] < uVar1) {
    iVar2 = -0x3fffff6b;
  }
  else {
    lVar3 = ExAllocatePool2(0x100,local_res20[0],0x6c687442);
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      iVar2 = ZwQueryValueKey(param_1,param_2,1,lVar3,local_res20[0],local_res20);
      if (-1 < iVar2) {
        if (param_4 < *(uint *)(lVar3 + 0xc)) {
          iVar2 = -0x3fffffdd;
        }
        else {
          memmove(param_3,(void *)((ulonglong)*(uint *)(lVar3 + 8) + lVar3),
                  (ulonglong)*(uint *)(lVar3 + 0xc));
        }
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = *(undefined4 *)(lVar3 + 0xc);
      }
      ExFreePoolWithTag(lVar3,0);
    }
  }
  return iVar2;
}



===== BthQueryKeyValueUlong @ 14001f770 =====

undefined8
BthQueryKeyValueUlong(undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_20 = 0;
  uStack_18 = 0;
  RtlInitUnicodeString(&local_20);
  local_28[0] = 0x13;
  uVar1 = ZwQueryValueKey(param_1,&local_20,2,param_3,0x13,local_28);
  if (-1 < (int)uVar1) {
    if (*(int *)(param_3 + 4) == 4) {
      *param_4 = *(undefined4 *)(param_3 + 0xc);
    }
    else {
      uVar1 = 0xc0000024;
    }
  }
  return uVar1;
}



===== entry @ 140020010 =====

void entry(longlong param_1,ushort *param_2,undefined1 *param_3,undefined8 param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 140020044 =====

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



===== DriverEntry @ 140020078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,ushort *param_2,undefined1 *param_3,undefined8 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  ushort *puVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined8 *puVar11;
  undefined1 auStackY_1b8 [8];
  undefined1 auStackY_1b0 [24];
  undefined8 local_178;
  undefined8 uStack_170;
  wchar_t *local_138;
  undefined8 local_130;
  undefined1 local_128 [8];
  undefined4 local_120;
  wchar_t *local_118;
  undefined *local_110;
  undefined4 local_108;
  wchar_t *local_100;
  undefined4 local_f8;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1b8;
  _WPP_MAIN_CB = 0;
  DAT_140015308 = &WPP_ThisDir_CTLGUID_BthEnumTraceGuid;
  DAT_140015310 = 0;
  bVar1 = true;
  _DAT_140015320 = 0;
  _DAT_140015328 = 1;
  _DAT_140015340 = 0;
  _DAT_140015348 = 0;
  WppLoadTracingSupport();
  _DAT_140015320 = 0;
  puVar8 = param_2;
  WppInitKm(param_1,param_2);
  iVar2 = wil_InitializeFeatureStaging();
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = 0x15;
      param_3 = (undefined1 *)0x4;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar8,4,0x15,
                        &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids,(char)iVar2);
      goto LAB_140020145;
    }
  }
  else {
    memset(&BthEnumGlobals,0,0x78);
    _DAT_140015364 = 0x6e457442;
    _DAT_1400153b0 = &DAT_140015368;
    _DAT_1400153a8 = 0x400000;
    DAT_1400153d0 = 0;
    _DAT_1400153c8 = param_1;
    RefObj_GlobalsInit();
    DAT_1400153b8 = *param_2;
    _DAT_1400153ba = DAT_1400153b8 + 2;
    param_3 = (undefined1 *)0x4f4d5442;
    puVar8 = (ushort *)(ulonglong)_DAT_1400153ba;
    DAT_1400153c0 = (ushort *)ExAllocatePool2(0x100);
    if (DAT_1400153c0 == (ushort *)0x0) {
      iVar2 = -0x3fffff66;
    }
    else {
      memmove(DAT_1400153c0,*(void **)(param_2 + 4),(ulonglong)*param_2);
      DAT_1400153c0[*param_2 >> 1] = 0;
      memset(local_128,0,0xe0);
      puVar8 = DAT_1400153c0;
      local_118 = L"DUNDevice";
      local_120 = 0x120;
      local_110 = &DAT_1400153a8;
      local_108 = 0x1000001;
      local_100 = L"";
      local_f8 = 0;
      local_178 = 0;
      uStack_170 = 0;
      RtlInitUnicodeString(&local_178,L"RtlQueryRegistryValuesEx");
      pcVar4 = (code *)MmGetSystemRoutineAddress(&local_178);
      param_3 = local_128;
      if (pcVar4 == (code *)0x0) {
        pcVar4 = RtlQueryRegistryValues_exref;
      }
      param_4 = 0;
      iVar3 = (*pcVar4)(0x80000000);
      iVar2 = 0;
      if (-1 < iVar3) {
        iVar2 = iVar3;
      }
      *(code **)(*(longlong *)(param_1 + 0x30) + 8) = BthEnumAddDevice;
      *(code **)(param_1 + 0x68) = BthUnload;
      puVar11 = (undefined8 *)(param_1 + 0x70);
      for (lVar6 = 0x1c; lVar6 != 0; lVar6 = lVar6 + -1) {
        *puVar11 = UnHandledDispatch;
        puVar11 = puVar11 + 1;
      }
      *(code **)(param_1 + 0x70) = BthDispatchCreate;
      *(code **)(param_1 + 0x100) = BthDispatchCleanup;
      *(code **)(param_1 + 0x80) = BthDispatchClose;
      *(code **)(param_1 + 0x148) = BthEnumPnP;
      *(code **)(param_1 + 0x120) = BthEnumPower;
      *(code **)(param_1 + 0x128) = BthEnumWmi;
      *(code **)(param_1 + 0xe0) = BthEnumIoctl;
      *(code **)(param_1 + 0xe8) = BthEnumInternalIoctl;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_4 = 0x16;
        param_3 = (undefined1 *)0x3;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar8,3,0x16,
                         &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          param_4 = 0x17;
          param_3 = (undefined1 *)0x4;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar8,4,0x17,
                           &WPP_c8568bf54bc733d6f91a7ac4a8ca9399_Traceguids);
        }
      }
      if (-1 < iVar2) {
        memset(&g_Policies,0,0x50);
        g_PolicyStorePath = (_UNICODE_STRING)ZEXT816(0);
        KeInitializeSpinLock(&g_PolicyLock);
        KeInitializeSpinLock(&g_CallbackLock);
        uVar5 = BthGetPolicyRegistryLocation(&g_PolicyStorePath);
        if (-1 < (int)uVar5) {
          McGenEventRegister_EtwRegister();
          iVar3 = ExSubscribeWnfStateChange
                            (&DAT_1400152c8,&WNF_ENTR_BLUETOOTH_POLICY_VALUE_CHANGED,1,0);
          if (-1 < iVar3) {
            BthSyncWithPolicyStore();
          }
        }
        puVar9 = auStackY_1b8;
        local_178 = *(undefined8 *)(PTR_DAT_140015018 + -0x10);
        uStack_170 = *(undefined8 *)(PTR_DAT_140015018 + -8);
        if (DAT_140015030 != (undefined1 *)0x0) {
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(5);
          puVar9 = auStackY_1b0;
        }
        puVar11 = &DAT_140015030;
        puVar10 = &DAT_140015010;
        puVar7 = puVar9 + 0x40;
        _DAT_140015038 = 0;
        DAT_140015040 = 0;
        *(undefined8 *)(puVar9 + -8) = 0x1400204d4;
        iVar3 = EtwRegister(puVar7,_tlgEnableCallback);
        if (iVar3 == 0) {
          puVar11 = (undefined8 *)(ulonglong)*(ushort *)PTR_DAT_140015018;
          *(undefined8 *)(puVar9 + -8) = 0x1400204f9;
          puVar7 = DAT_140015030;
          puVar10 = (undefined4 *)PTR_DAT_140015018;
          EtwSetInformation(DAT_140015030,2);
        }
        if (5 < DAT_140015010) {
          if (((DAT_140015020 & 0x400000000000) == 0) ||
             ((DAT_140015028 & 0x400000000000) != DAT_140015028)) {
            bVar1 = false;
          }
          if (bVar1) {
            *(undefined8 *)(puVar9 + 0x40) = 0x2000800;
            *(undefined1 **)(puVar9 + 0x70) = puVar9 + 0x40;
            *(undefined8 *)(puVar9 + 0x78) = 8;
            local_138 = L"BthEnum.sys";
            *(undefined1 **)(puVar9 + 0x28) = puVar9 + 0x50;
            *(undefined4 *)(puVar9 + 0x20) = 4;
            local_130 = 0x18;
            *(undefined8 *)(puVar9 + -8) = 0x14002058a;
            _tlgWriteTransfer_EtwWriteTransfer
                      (puVar7,&DAT_140013950,puVar10,puVar11,*(undefined4 *)(puVar9 + 0x20),
                       *(undefined8 **)(puVar9 + 0x28));
          }
        }
        goto LAB_140020177;
      }
    }
LAB_140020145:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      NtStatusTxt(iVar2);
      WPP_RECORDER_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  puVar9 = auStackY_1b8;
  BthUnload(param_1,puVar8,param_3,param_4);
LAB_140020177:
  *(undefined8 *)(puVar9 + -8) = 0x140020185;
  return iVar2;
}



===== wil_InitializeFeatureStaging @ 140020598 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (ppuVar3 = &Feature_GatePerf__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14002061f;
    }
LAB_140020659:
    g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
    iVar2 = RtlRegisterFeatureUsageProvider
                      (wil_details_OnFeatureUsageProviderFlushNotification,0,
                       &g_wil_details_featureUsageProvider);
    if (iVar2 != 0) {
      if (bVar1) {
        iVar2 = 0;
      }
      g_wil_details_featureUsageProvider = 0;
      return iVar2;
    }
  }
  return 0;
LAB_14002061f:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140020659;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_140020659;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400148bf < ppuVar3) goto LAB_140020659;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14002061f;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400206ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar4 = &Feature_GatePerf__private_descriptor;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= ppuVar4) {
      return;
    }
    if (*ppuVar4 != (undefined *)0x0) break;
    ppuVar4 = ppuVar4 + 1;
  }
  do {
    if (ppuVar4 == (undefined **)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) {
      iVar3 = RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar4 + 3),
                         1 < (byte)(*(char *)((longlong)ppuVar4 + 0x1c) - 2U),&local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar4;
          ppuVar4 = ppuVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_1400148bf < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140020796;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140020796;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140020796:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400148bf < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


