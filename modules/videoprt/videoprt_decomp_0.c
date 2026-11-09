
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



===== __report_rangecheckfailure @ 1c0001020 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== VideoPortGetCurrentIrql @ 1c0001030 =====

void VideoPortGetCurrentIrql(void)

{
                    /* 0x1030  40  VideoPortGetCurrentIrql */
  KeGetCurrentIrql();
  return;
}



===== VideoPortInterlockedDecrement @ 1c0001050 =====

int VideoPortInterlockedDecrement(int *param_1)

{
  int iVar1;
  
                    /* 0x1050  52  VideoPortInterlockedDecrement */
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  return iVar1 + -1;
}



===== VideoPortInterlockedExchange @ 1c0001070 =====

undefined4 VideoPortInterlockedExchange(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
                    /* 0x1070  53  VideoPortInterlockedExchange */
  LOCK();
  uVar1 = *param_1;
  *param_1 = param_2;
  UNLOCK();
  return uVar1;
}



===== VideoPortInterlockedIncrement @ 1c0001080 =====

int VideoPortInterlockedIncrement(int *param_1)

{
  int iVar1;
  
                    /* 0x1080  54  VideoPortInterlockedIncrement */
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + 1;
  UNLOCK();
  return iVar1 + 1;
}



===== VideoPortQuerySystemTime @ 1c00010a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortQuerySystemTime(undefined8 *param_1)

{
                    /* 0x10a0  67  VideoPortQuerySystemTime */
  *param_1 = _DAT_fffff78000000014;
  return;
}



===== VideoPortQueueDpc @ 1c00010c0 =====

void VideoPortQueueDpc(longlong param_1)

{
                    /* 0x10c0  68  VideoPortQueueDpc */
  KeInsertQueueDpc(*(longlong *)(param_1 + -0x58) + 0x148);
  return;
}



===== VideoPortReadRegisterBufferUchar @ 1c00010f0 =====

void VideoPortReadRegisterBufferUchar(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x10f0  75  VideoPortReadRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== VideoPortReadRegisterBufferUlong @ 1c0001120 =====

void VideoPortReadRegisterBufferUlong(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x1120  76  VideoPortReadRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== VideoPortReadRegisterBufferUshort @ 1c0001150 =====

void VideoPortReadRegisterBufferUshort(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x1150  77  VideoPortReadRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== VideoPortReadRegisterUchar @ 1c0001180 =====

undefined1 VideoPortReadRegisterUchar(undefined1 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  
                    /* 0x1180  78  VideoPortReadRegisterUchar */
  uVar1 = *param_1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,param_3,param_1,uVar1);
  }
  return uVar1;
}



===== VideoPortReadRegisterUlong @ 1c00011d0 =====

undefined4 VideoPortReadRegisterUlong(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
                    /* 0x11d0  79  VideoPortReadRegisterUlong */
  uVar1 = *param_1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_3,param_1,(char)uVar1);
  }
  return uVar1;
}



===== VideoPortReadRegisterUshort @ 1c0001220 =====

undefined2 VideoPortReadRegisterUshort(undefined2 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined2 uVar1;
  
                    /* 0x1220  80  VideoPortReadRegisterUshort */
  uVar1 = *param_1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,param_3,param_1,(char)uVar1);
  }
  return uVar1;
}



===== VideoPortWriteRegisterBufferUchar @ 1c0001270 =====

void VideoPortWriteRegisterBufferUchar(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x1270  113  VideoPortWriteRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== VideoPortWriteRegisterBufferUlong @ 1c00012a0 =====

void VideoPortWriteRegisterBufferUlong(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x12a0  114  VideoPortWriteRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== VideoPortWriteRegisterBufferUshort @ 1c00012d0 =====

void VideoPortWriteRegisterBufferUshort(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x12d0  115  VideoPortWriteRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== VideoPortWriteRegisterUchar @ 1c0001300 =====

void VideoPortWriteRegisterUchar(undefined1 *param_1,undefined1 param_2)

{
                    /* 0x1300  116  VideoPortWriteRegisterUchar */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_3724e864d48c3292fddfb70a1c89e8e6_Traceguids,param_1);
  }
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== VideoPortWriteRegisterUlong @ 1c0001360 =====

void VideoPortWriteRegisterUlong(undefined4 *param_1,undefined4 param_2)

{
                    /* 0x1360  117  VideoPortWriteRegisterUlong */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_3724e864d48c3292fddfb70a1c89e8e6_Traceguids,param_1);
  }
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== VideoPortWriteRegisterUshort @ 1c00013c0 =====

void VideoPortWriteRegisterUshort(undefined2 *param_1,undefined2 param_2)

{
                    /* 0x13c0  118  VideoPortWriteRegisterUshort */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_3724e864d48c3292fddfb70a1c89e8e6_Traceguids,param_1);
  }
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== VpGetProcAddress @ 1c0001420 =====

undefined * VpGetProcAddress(undefined8 param_1,longlong param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined **ppuVar4;
  longlong lVar5;
  
  ppuVar4 = &VideoPortEntryPoints;
  pcVar3 = VideoPortEntryPoints;
  do {
    if (pcVar3 == (char *)0x0) {
      return (undefined *)0x0;
    }
    lVar5 = param_2 - (longlong)pcVar3;
    do {
      cVar1 = *pcVar3;
      cVar2 = pcVar3[lVar5];
      if (cVar1 != cVar2) break;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    if (cVar1 == cVar2) {
      return ppuVar4[1];
    }
    ppuVar4 = ppuVar4 + 2;
    pcVar3 = *ppuVar4;
  } while( true );
}



===== WPP_SF_ @ 1c000146c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_d @ 1c0001498 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_q @ 1c00014dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qD @ 1c0001520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_3724e864d48c3292fddfb70a1c89e8e6_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== pVideoPortDpcDispatcher @ 1c0001580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void pVideoPortDpcDispatcher
               (undefined8 param_1,undefined8 param_2,undefined *param_3,undefined8 param_4)

{
  (*(code *)param_3)(param_2,param_4);
  return;
}



===== VideoPortNotification @ 1c00015a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortNotification(int param_1,undefined8 param_2,undefined8 *param_3)

{
                    /* 0x15a0  63  VideoPortNotification */
  if (param_1 == 0xc) {
    *param_3 = _DAT_fffff78000000320;
  }
  else if (param_1 == 0xd) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0xf7,0,0,0,0);
  }
  return;
}



===== VideoPortAcquireSpinLock @ 1c0001600 =====

void VideoPortAcquireSpinLock(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  
                    /* 0x1600  3  VideoPortAcquireSpinLock */
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_2);
  *param_3 = uVar1;
  return;
}



===== VideoPortAcquireSpinLockAtDpcLevel @ 1c0001630 =====

void VideoPortAcquireSpinLockAtDpcLevel(undefined8 param_1,undefined8 param_2)

{
                    /* 0x1630  4  VideoPortAcquireSpinLockAtDpcLevel */
  KeAcquireSpinLockAtDpcLevel(param_2);
  return;
}



===== VideoPortClearEvent @ 1c0001650 =====

void VideoPortClearEvent(undefined8 param_1,undefined8 *param_2)

{
                    /* 0x1650  12  VideoPortClearEvent */
  KeClearEvent(*param_2);
  return;
}



===== VideoPortDeleteEvent @ 1c0001670 =====

undefined8 VideoPortDeleteEvent(undefined8 param_1,longlong *param_2)

{
  undefined2 uVar1;
  
                    /* 0x1670  23  VideoPortDeleteEvent */
  if (param_2 == (longlong *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x57;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0x57;
    }
    uVar1 = 10;
  }
  else if ((*(uint *)(param_2 + 1) & 1) == 0) {
    if (*param_2 != 0) {
      ExFreePoolWithTag(param_2,0);
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x57;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0x57;
    }
    uVar1 = 0xc;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x57;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0x57;
    }
    uVar1 = 0xb;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
          &WPP_c79f569e3a123a1eb810ffbec2dfb9ea_Traceguids);
  return 0x57;
}



===== VideoPortDeleteSpinLock @ 1c0001720 =====

undefined8 VideoPortDeleteSpinLock(undefined8 param_1,undefined8 param_2)

{
                    /* 0x1720  24  VideoPortDeleteSpinLock */
  ExFreePoolWithTag(param_2,0);
  return 0;
}



===== VideoPortReadStateEvent @ 1c0001750 =====

void VideoPortReadStateEvent(undefined8 param_1,undefined8 *param_2)

{
                    /* 0x1750  81  VideoPortReadStateEvent */
  KeReadStateEvent(*param_2);
  return;
}



===== VideoPortReleaseSpinLock @ 1c0001770 =====

void VideoPortReleaseSpinLock(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
                    /* 0x1770  86  VideoPortReleaseSpinLock */
  KeReleaseSpinLock(param_2,param_3);
  return;
}



===== VideoPortReleaseSpinLockFromDpcLevel @ 1c00017a0 =====

void VideoPortReleaseSpinLockFromDpcLevel(undefined8 param_1,undefined8 param_2)

{
                    /* 0x17a0  87  VideoPortReleaseSpinLockFromDpcLevel */
  KeReleaseSpinLockFromDpcLevel(param_2);
  return;
}



===== VideoPortSetEvent @ 1c00017c0 =====

void VideoPortSetEvent(undefined8 param_1,undefined8 *param_2)

{
                    /* 0x17c0  92  VideoPortSetEvent */
  KeSetEvent(*param_2,0,0);
  return;
}



===== VideoPortWaitForSingleObject @ 1c00017f0 =====

undefined8 VideoPortWaitForSingleObject(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  int iVar1;
  
                    /* 0x17f0  106  VideoPortWaitForSingleObject */
  if ((param_2 != (longlong *)0x0) && (*param_2 != 0)) {
    if ((*(uint *)(param_2 + 1) & 1) == 0) {
      iVar1 = KeWaitForSingleObject(*param_2,0,0,0,param_3);
      if (iVar1 == 0x102) {
        return 0x102;
      }
      if (iVar1 < 0) {
        return 0x57;
      }
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_c79f569e3a123a1eb810ffbec2dfb9ea_Traceguids);
    }
  }
  return 0x57;
}



===== RtlStringCbCatW @ 1c000187c =====

uint RtlStringCbCatW(short *param_1,ulonglong param_2,longlong param_3)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  
  uVar8 = param_2 >> 1;
  if (uVar8 - 1 < 0x7fffffff) {
    psVar3 = param_1;
    uVar6 = uVar8;
    do {
      if (*psVar3 == 0) break;
      psVar3 = psVar3 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
    if (uVar6 == 0) {
      uVar2 = 0xc000000d;
    }
    else {
      lVar7 = uVar8 - uVar6;
      psVar3 = param_1 + lVar7;
      lVar5 = uVar8 - lVar7;
      if (lVar5 != 0) {
        lVar7 = (lVar7 - uVar8) + 0x7ffffffe + lVar5;
        lVar9 = param_3 - (longlong)psVar3;
        do {
          if ((lVar7 == 0) || (sVar1 = *(short *)(lVar9 + (longlong)psVar3), sVar1 == 0)) break;
          *psVar3 = sVar1;
          lVar7 = lVar7 + -1;
          psVar3 = psVar3 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
      }
      psVar4 = psVar3 + -1;
      if (lVar5 != 0) {
        psVar4 = psVar3;
      }
      *psVar4 = 0;
      uVar2 = ~-(uint)(lVar5 != 0) & 0x80000005;
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== RtlStringCbPrintfW @ 1c0001944 =====

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



===== RtlStringCchPrintfW @ 1c00019c0 =====

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



===== VPGetRegistryParameters @ 1c0001a3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
VPGetRegistryParameters
          (undefined8 param_1,longlong param_2,char param_3,undefined8 param_4,undefined8 param_5,
          longlong param_6,uint param_7)

{
  wchar_t wVar1;
  int iVar2;
  wchar_t *_Str;
  wchar_t *pwVar3;
  code *pcVar4;
  ulonglong uVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  ulonglong uVar8;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  uint local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  code *local_98;
  undefined4 local_90;
  longlong local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined4 local_30;
  
  uVar8 = 0xffffffffffffffff;
  do {
    uVar8 = uVar8 + 1;
  } while (*(short *)(param_2 + uVar8 * 2) != 0);
  if ((uVar8 < 0x105) && (param_7 < 0x209)) {
    uVar8 = (ulonglong)param_7 + 4 + uVar8 * 2;
    _Str = (wchar_t *)ExAllocatePool2(0x100,uVar8,0x74727056);
    if (_Str == (wchar_t *)0x0) {
      local_b0 = 8;
    }
    else {
      uVar5 = uVar8 >> 1;
      if (uVar5 != 0) {
        pwVar3 = _Str;
        if (uVar5 < 0x80000000) {
          lVar6 = 0x7ffffffe - uVar5;
          pwVar7 = _Str;
          do {
            if ((lVar6 + uVar5 == 0) ||
               (wVar1 = *(wchar_t *)((param_6 - (longlong)_Str) + (longlong)pwVar7), wVar1 == L'\0')
               ) break;
            *pwVar7 = wVar1;
            pwVar7 = pwVar7 + 1;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
          pwVar3 = pwVar7 + -1;
          if (uVar5 != 0) {
            pwVar3 = pwVar7;
          }
        }
        *pwVar3 = L'\0';
      }
      RtlStringCbCatW(_Str,uVar8,0x1c00063cc);
      RtlStringCbCatW(_Str,uVar8,param_2);
      pwVar3 = wcsrchr(_Str,L'\\');
      if (pwVar3 != (wchar_t *)0x0) {
        *pwVar3 = L'\0';
      }
      local_b0 = 0;
      local_90 = 4;
      local_ac = (uint)(param_3 != '\0');
      local_b8 = param_5;
      local_98 = pVideoPortGetRegistryCallback;
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      local_58 = 0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      local_38 = 0;
      local_30 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_c8 = param_1;
      local_c0 = param_4;
      local_88 = param_2;
      RtlInitUnicodeString(&local_a8,L"RtlQueryRegistryValuesEx");
      pcVar4 = (code *)MmGetSystemRoutineAddress(&local_a8);
      if (pcVar4 == (code *)0x0) {
        pcVar4 = RtlQueryRegistryValues_exref;
      }
      iVar2 = (*pcVar4)(0,_Str,&local_98,&local_c8,0);
      if (iVar2 < 0) {
        local_b0 = 0x57;
      }
      ExFreePoolWithTag(_Str,0);
    }
  }
  else {
    local_b0 = 0x57;
  }
  return local_b0;
}



===== VPSetRegistryParameters @ 1c0001c64 =====

undefined8
VPSetRegistryParameters
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
          longlong param_5,uint param_6)

{
  ulonglong uVar1;
  wchar_t wVar2;
  short sVar3;
  wchar_t *pwVar4;
  int iVar5;
  short *psVar6;
  undefined8 uVar7;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  short *psVar10;
  wchar_t *pwVar11;
  wchar_t *pwVar12;
  longlong lVar13;
  short *psVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  
  uVar15 = 0xffffffffffffffff;
  do {
    uVar16 = uVar15;
    uVar15 = uVar16 + 1;
  } while (*(short *)(param_2 + uVar15 * 2) != 0);
  if ((uVar15 < 0x105) && (param_6 < 0x209)) {
    uVar1 = (ulonglong)param_6 + 4 + uVar15 * 2;
    psVar6 = (short *)ExAllocatePool2(0x100,uVar1,0x74727056);
    if (psVar6 != (short *)0x0) {
      pwVar8 = (wchar_t *)ExAllocatePool2(0x100,uVar15 * 2 + 2,0x74727056);
      if (pwVar8 != (wchar_t *)0x0) {
        uVar16 = uVar16 + 2;
        if (uVar16 != 0) {
          pwVar9 = pwVar8;
          if (uVar16 < 0x80000000) {
            lVar13 = 0x7ffffffe - uVar16;
            pwVar11 = pwVar8;
            do {
              if ((lVar13 + uVar16 == 0) ||
                 (wVar2 = *(wchar_t *)((param_2 - (longlong)pwVar8) + (longlong)pwVar11),
                 wVar2 == L'\0')) break;
              *pwVar11 = wVar2;
              pwVar11 = pwVar11 + 1;
              uVar16 = uVar16 - 1;
            } while (uVar16 != 0);
            pwVar9 = pwVar11 + -1;
            if (uVar16 != 0) {
              pwVar9 = pwVar11;
            }
          }
          *pwVar9 = L'\0';
        }
        uVar15 = uVar1 >> 1;
        if (uVar15 != 0) {
          if (uVar15 < 0x80000000) {
            lVar13 = 0x7ffffffe - uVar15;
            psVar14 = psVar6;
            do {
              if ((lVar13 + uVar15 == 0) ||
                 (sVar3 = *(short *)((param_5 - (longlong)psVar6) + (longlong)psVar14), sVar3 == 0))
              break;
              *psVar14 = sVar3;
              psVar14 = psVar14 + 1;
              uVar15 = uVar15 - 1;
            } while (uVar15 != 0);
            psVar10 = psVar14 + -1;
            if (uVar15 != 0) {
              psVar10 = psVar14;
            }
            *psVar10 = 0;
          }
          else {
            *psVar6 = 0;
          }
        }
        pwVar11 = wcsrchr(pwVar8,L'\\');
        pwVar9 = pwVar8;
        if (pwVar11 != (wchar_t *)0x0) {
          pwVar9 = pwVar8 + 1;
          if (*pwVar8 != L'\\') {
            pwVar9 = pwVar8;
          }
          pwVar12 = wcschr(pwVar9,L'\\');
          pwVar8 = pwVar9;
          if (pwVar12 != (wchar_t *)0x0) {
            *pwVar12 = L'\0';
            pwVar12 = pwVar12 + 1;
          }
          while ((pwVar4 = pwVar12, pwVar8 != (wchar_t *)0x0 && (pwVar8 != pwVar11 + 1))) {
            RtlStringCbCatW(psVar6,uVar1,0x1c00063cc);
            RtlStringCbCatW(psVar6,uVar1,(longlong)pwVar8);
            iVar5 = RtlCreateRegistryKey(0,psVar6);
            if (iVar5 < 0) {
              ExFreePoolWithTag(pwVar9,0);
              ExFreePoolWithTag(psVar6,0);
              goto LAB_1c0001f0b;
            }
            pwVar12 = wcschr(pwVar9,L'\\');
            pwVar8 = pwVar4;
            if (pwVar12 != (wchar_t *)0x0) {
              *pwVar12 = L'\0';
              pwVar12 = pwVar12 + 1;
            }
          }
        }
        iVar5 = RtlWriteRegistryValue(0,psVar6,pwVar9,3,param_3,param_4);
        ExFreePoolWithTag(pwVar9,0);
        ExFreePoolWithTag(psVar6,0);
        if (-1 < iVar5) {
          return 0;
        }
        goto LAB_1c0001f0b;
      }
      ExFreePoolWithTag(psVar6,0x74727056);
    }
    uVar7 = 8;
  }
  else {
LAB_1c0001f0b:
    uVar7 = 0x57;
  }
  return uVar7;
}



===== VideoPortAllocatePool @ 1c0001f40 =====

void VideoPortAllocatePool(undefined8 param_1,uint param_2,undefined8 param_3,undefined4 param_4)

{
                    /* 0x1f40  8  VideoPortAllocatePool */
  ExAllocatePoolWithTag(param_2 | 0x400,param_3,param_4);
  return;
}



===== VideoPortDebugPrint @ 1c0001f70 =====

void VideoPortDebugPrint(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
                    /* 0x1f70  22  VideoPortDebugPrint */
  if ((VideoDebugLevel != 0) && (param_1 <= VideoDebugLevel)) {
    param_1 = 0;
  }
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintEx(0x1b,param_1,param_2,&local_res18);
  return;
}



===== VideoPortFlushRegistry @ 1c0001fc0 =====

undefined8 VideoPortFlushRegistry(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_res8 [4];
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
  
                    /* 0x1fc0  29  VideoPortFlushRegistry */
  lVar2 = *(longlong *)(param_1 + -0x20);
  if (lVar2 == 0) {
    lVar2 = *(longlong *)(param_1 + -0x10);
  }
  local_1c = 0;
  local_res8[0] = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_48,lVar2);
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(local_res8,0x2001f,&local_38);
  if (-1 < iVar1) {
    ZwFlushKey(local_res8[0]);
    ZwClose(local_res8[0]);
  }
  return 0;
}



===== VideoPortFreePool @ 1c0002070 =====

void VideoPortFreePool(undefined8 param_1,undefined8 param_2)

{
                    /* 0x2070  32  VideoPortFreePool */
  ExFreePoolWithTag(param_2,0);
  return;
}



===== VideoPortGetVersion @ 1c00020a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VideoPortGetVersion(undefined8 param_1,uint *param_2)

{
  int iVar1;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  undefined2 local_24;
  undefined2 local_22;
  ulonglong local_18;
  
                    /* 0x20a0  48  VideoPortGetVersion */
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  if (0x13 < *param_2) {
    memset(&local_134,0,0x118);
    local_138 = 0x11c;
    iVar1 = RtlGetVersion(&local_138);
    if (iVar1 == 0) {
      param_2[1] = local_134;
      param_2[2] = local_130;
      param_2[3] = local_12c;
      *(undefined2 *)(param_2 + 4) = local_24;
      *(undefined2 *)((longlong)param_2 + 0x12) = local_22;
      return 0;
    }
  }
  return 0x57;
}



===== VideoPortLogError @ 1c0002150 =====

void VideoPortLogError(longlong param_1,undefined4 *param_2,undefined *param_3,uint param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 local_28;
  undefined4 uStack_24;
  
                    /* 0x2150  58  VideoPortLogError */
  lVar1 = *(longlong *)(param_1 + -0x58);
  uVar2 = 0;
  if (param_2 != (undefined4 *)0x0) {
    uVar2 = *param_2;
  }
  if ((*(uint *)(lVar1 + 0x128) & 1) == 0) {
    local_28 = (undefined4)lVar1;
    uStack_24 = (undefined4)((ulonglong)lVar1 >> 0x20);
    *(undefined4 *)(lVar1 + 0x130) = local_28;
    *(undefined4 *)(lVar1 + 0x134) = uStack_24;
    *(undefined4 *)(lVar1 + 0x138) = uVar2;
    *(int *)(lVar1 + 0x13c) = (int)param_3;
    *(uint *)(lVar1 + 0x128) = *(uint *)(lVar1 + 0x128) | 1;
    *(ulonglong *)(lVar1 + 0x140) = (ulonglong)param_4;
    KeInsertQueueDpc(lVar1 + 0xe0,0,0);
  }
  else if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar3 = param_3;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
      puVar3 = &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids;
      param_2 = (undefined4 *)0x42;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,puVar3,uVar2,(char)param_3,
                 (char)param_4);
    }
  }
  return;
}



===== VideoPortQueryPerformanceCounter @ 1c0002250 =====

void VideoPortQueryPerformanceCounter(undefined8 param_1,undefined8 param_2)

{
                    /* 0x2250  65  VideoPortQueryPerformanceCounter */
  KeQueryPerformanceCounter(param_2);
  return;
}



===== VideoPortStartTimer @ 1c0002270 =====

void VideoPortStartTimer(longlong param_1)

{
                    /* 0x2270  98  VideoPortStartTimer */
  if (*(longlong *)(*(longlong *)(param_1 + -0x58) + 0xd0) != 0) {
    IoStartTimer(*(undefined8 *)(*(longlong *)(param_1 + -0x58) + 0x98));
  }
  return;
}



===== VideoPortStopTimer @ 1c00022b0 =====

void VideoPortStopTimer(longlong param_1)

{
                    /* 0x22b0  99  VideoPortStopTimer */
  if (*(longlong *)(*(longlong *)(param_1 + -0x58) + 0xd0) != 0) {
    IoStopTimer(*(undefined8 *)(*(longlong *)(param_1 + -0x58) + 0x98));
  }
  return;
}



===== VideoPortZeroDeviceMemory @ 1c00022f0 =====

void VideoPortZeroDeviceMemory(void *param_1,uint param_2)

{
                    /* 0x22f0  119  VideoPortZeroDeviceMemory */
  memset(param_1,0,(ulonglong)param_2);
  return;
}



===== VpCopyRegistry @ 1c000230c =====

int VpCopyRegistry(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  short *psVar4;
  short *psVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  int iVar10;
  short *psVar11;
  int iVar12;
  int iVar13;
  int local_res18 [4];
  longlong in_stack_ffffffffffffff58;
  undefined4 uVar14;
  ulonglong in_stack_ffffffffffffff60;
  int *piVar15;
  longlong local_88;
  longlong local_80 [3];
  undefined8 local_68;
  longlong lStack_60;
  longlong *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  
  iVar12 = 0;
  local_48 = 0;
  uStack_40 = uStack_40 & 0xffffffff00000000;
  local_88 = 0;
  local_80[0] = 0;
  local_res18[0] = 0;
  iVar2 = 0;
  iVar13 = 0x200;
  puVar3 = (undefined4 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  local_58 = (longlong *)0x0;
  uStack_50 = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  if (param_3 == 0) {
    local_88 = param_1;
  }
  else {
    RtlInitUnicodeString(local_80 + 1,param_3);
    local_58 = local_80 + 1;
    local_68 = CONCAT44(local_68._4_4_,0x30);
    uStack_50 = CONCAT44(uStack_50._4_4_,0x240);
    local_48 = 0;
    uStack_40 = 0;
    lStack_60 = param_1;
    iVar2 = ZwOpenKey(&local_88,0x20019,&local_68);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      local_88 = 0;
      goto LAB_1c0002840;
    }
  }
  if (param_4 == 0) {
    local_80[0] = param_2;
LAB_1c0002383:
    iVar10 = 0;
    while( true ) {
      while( true ) {
        uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
        if ((puVar3 == (undefined4 *)0x0) &&
           (puVar3 = (undefined4 *)ExAllocatePool2(0x100,iVar13,0x74727056),
           puVar3 == (undefined4 *)0x0)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
                    &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
          }
          goto LAB_1c0002826;
        }
        in_stack_ffffffffffffff58 = CONCAT44(uVar14,iVar13 + -2);
        iVar2 = ZwEnumerateKey(local_88,iVar10,0,puVar3,in_stack_ffffffffffffff58,local_res18);
        if (iVar2 != -0x3fffffdd) break;
        ExFreePoolWithTag(puVar3,0);
        puVar3 = (undefined4 *)0x0;
        iVar13 = local_res18[0] + 2;
      }
      if (iVar2 < 0) break;
      *(undefined2 *)((longlong)puVar3 + (ulonglong)((uint)puVar3[3] >> 1) * 2 + 0x10) = 0;
      iVar2 = VpCopyRegistry(local_88,local_80[0],(longlong)(puVar3 + 4),(longlong)(puVar3 + 4));
      iVar10 = iVar10 + 1;
    }
    if (iVar2 == -0x7fffffe6) {
      iVar2 = 0;
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
    while ((uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20),
           puVar3 != (undefined4 *)0x0 ||
           (puVar3 = (undefined4 *)ExAllocatePool2(0x100,iVar13,0x74727056),
           puVar3 != (undefined4 *)0x0))) {
      piVar15 = local_res18;
      in_stack_ffffffffffffff58 = CONCAT44(uVar14,iVar13);
      iVar2 = ZwEnumerateValueKey(local_88,iVar12,1,puVar3,in_stack_ffffffffffffff58,piVar15);
      uVar14 = (undefined4)((ulonglong)piVar15 >> 0x20);
      if (iVar2 == -0x3fffffdd) {
        ExFreePoolWithTag(puVar3,0);
        puVar3 = (undefined4 *)0x0;
        iVar13 = local_res18[0];
      }
      else {
        if (iVar2 < 0) {
          if (iVar2 == -0x7fffffe6) {
            iVar2 = 0;
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar7 = 0x61;
            goto LAB_1c00027fc;
          }
LAB_1c000280c:
          if (puVar3 != (undefined4 *)0x0) {
            ExFreePoolWithTag(puVar3,0);
          }
          goto LAB_1c0002826;
        }
        if ((0x104 < (uint)puVar3[4]) ||
           (psVar4 = (short *)ExAllocatePool2(0x100,(ulonglong)(uint)puVar3[4] + 2,0x74727056),
           psVar4 == (short *)0x0)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar7 = 0x62;
LAB_1c00027fc:
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                    &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
          }
          goto LAB_1c000280c;
        }
        uVar6 = (ulonglong)(uint)puVar3[4] + 2 >> 1;
        if (uVar6 - 1 < 0x7fffffff) {
          uVar8 = (ulonglong)((uint)puVar3[4] >> 1);
          if (uVar8 < 0x7fffffff) {
            lVar9 = uVar8 - uVar6;
            psVar11 = psVar4;
            do {
              if ((lVar9 + uVar6 == 0) ||
                 (sVar1 = *(short *)((longlong)puVar3 + (0x14 - (longlong)psVar4) +
                                    (longlong)psVar11), sVar1 == 0)) break;
              *psVar11 = sVar1;
              psVar11 = psVar11 + 1;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
            psVar5 = psVar11 + -1;
            if (uVar6 != 0) {
              psVar5 = psVar11;
            }
            *psVar5 = 0;
          }
          else {
            *psVar4 = 0;
          }
        }
        psVar4[(uint)puVar3[4] >> 1] = 0;
        RtlInitUnicodeString(local_80 + 1,psVar4);
        in_stack_ffffffffffffff58 = (ulonglong)(uint)puVar3[2] + (longlong)puVar3;
        iVar2 = ZwSetValueKey(local_80[0],local_80 + 1,*puVar3,puVar3[1],in_stack_ffffffffffffff58,
                              CONCAT44(uVar14,puVar3[3]));
        if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                  &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
        }
        ExFreePoolWithTag(psVar4,0);
        iVar12 = iVar12 + 1;
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
  }
  else {
    RtlInitUnicodeString(local_80 + 1,param_4);
    local_58 = local_80 + 1;
    local_68 = CONCAT44(local_68._4_4_,0x30);
    uStack_50 = CONCAT44(uStack_50._4_4_,0x240);
    local_48 = 0;
    uStack_40 = 0;
    in_stack_ffffffffffffff58 = 0;
    lStack_60 = param_2;
    iVar2 = ZwCreateKey(local_80,0xc0000000,&local_68,0,0,
                        in_stack_ffffffffffffff60 & 0xffffffff00000000,0);
    if (-1 < iVar2) goto LAB_1c0002383;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
    local_80[0] = 0;
  }
LAB_1c0002826:
  if ((local_88 != 0) && (local_88 != param_1)) {
    ZwClose();
  }
LAB_1c0002840:
  if ((local_80[0] != 0) && (local_80[0] != param_2)) {
    ZwClose();
  }
  return iVar2;
}



===== VpEnableNewRegistryKey @ 1c0002880 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VpEnableNewRegistryKey(undefined8 param_1,longlong param_2,ushort *param_3,uint param_4)

{
  short sVar1;
  wchar_t wVar2;
  size_t _Size;
  char cVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  wchar_t *pwVar11;
  undefined2 uVar12;
  short *psVar13;
  ulonglong uVar14;
  wchar_t *_Dst;
  ulonglong uVar15;
  longlong lVar16;
  wchar_t *pwVar17;
  uint uVar18;
  undefined1 auStack_c8 [32];
  short *local_a8;
  undefined4 *local_a0;
  undefined4 local_98;
  uint local_94;
  longlong local_90 [2];
  short *local_80;
  longlong local_78;
  uint local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  psVar6 = *(short **)(param_3 + 4);
  lVar9 = 0;
  local_98 = 0;
  local_90[0] = 0;
  uVar18 = 0;
  psVar7 = psVar6 + ((ulonglong)(*param_3 >> 1) - 1);
  local_90[1] = 0;
  local_94 = 0;
  local_80 = (short *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (psVar6 < psVar7) {
    do {
      if (*psVar7 == 0x5c) break;
      psVar7 = psVar7 + -1;
      uVar18 = uVar18 + 1;
    } while (psVar6 < psVar7);
    local_94 = uVar18;
  }
  uVar18 = local_94;
  _Size = (ulonglong)(local_94 + 1) * 2;
  uVar15 = (ulonglong)(local_94 + 1);
  psVar7 = psVar7 + 1;
  local_78 = param_2;
  local_70 = param_4;
  psVar6 = (short *)ExAllocatePool2(0x100,_Size,0x74727056);
  if (psVar6 == (short *)0x0) {
    _Dst = (wchar_t *)0x0;
    psVar6 = psVar7;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar12 = 0x48;
      goto LAB_1c0002959;
    }
  }
  else {
    memset(psVar6,0,_Size);
    if (uVar15 != 0) {
      if ((uVar15 < 0x80000000) && ((ulonglong)uVar18 < 0x7fffffff)) {
        lVar8 = uVar18 - uVar15;
        psVar13 = psVar6;
        do {
          if ((lVar8 + uVar15 == 0) ||
             (sVar1 = *(short *)(((longlong)psVar7 - (longlong)psVar6) + (longlong)psVar13),
             sVar1 == 0)) break;
          *psVar13 = sVar1;
          psVar13 = psVar13 + 1;
          uVar15 = uVar15 - 1;
        } while (uVar15 != 0);
        psVar7 = psVar13 + -1;
        if (uVar15 != 0) {
          psVar7 = psVar13;
        }
        *psVar7 = 0;
      }
      else {
        *psVar6 = 0;
      }
    }
    _Dst = (wchar_t *)0x0;
    cVar3 = VpGetServiceSubkey(param_3,local_90);
    if (cVar3 == '\0') {
      local_90[0] = 0;
    }
    else {
      RtlInitUnicodeString(&local_68,L"VideoID");
      local_a0 = &local_98;
      local_a8 = (short *)((ulonglong)local_a8 & 0xffffffff00000000);
      iVar4 = ZwQueryValueKey(local_90[0],&local_68,2);
      if ((iVar4 == -0x7ffffffb) || (iVar4 == -0x3fffffdd)) {
        lVar9 = ExAllocatePool2(0x100,local_98,0x74727056);
        if (lVar9 == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar12 = 0x49;
            goto LAB_1c0002a8d;
          }
        }
        else {
          local_a0 = &local_98;
          local_a8 = (short *)CONCAT44(local_a8._4_4_,local_98);
          iVar4 = ZwQueryValueKey(local_90[0],&local_68,2);
          if (iVar4 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c00030ef;
            uVar12 = 0x4a;
LAB_1c0002f36:
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                    &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
          }
          else {
            uVar18 = *(int *)(lVar9 + 8) + 0x8e;
            if (uVar18 < 0x8e) {
LAB_1c00032b5:
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                uVar12 = 0x4b;
                goto LAB_1c0002f36;
              }
            }
            else {
              uVar15 = (ulonglong)uVar18;
              _Dst = (wchar_t *)ExAllocatePool2(0x100,uVar18,0x74727056);
              if (_Dst == (wchar_t *)0x0) goto LAB_1c00032b5;
              memset(_Dst,0,uVar15);
              uVar10 = (ulonglong)(uVar18 >> 1);
              if (uVar10 != 0) {
                pwVar11 = _Dst;
                uVar14 = uVar10;
                do {
                  if (((0x7ffffffe - uVar10) + uVar14 == 0) ||
                     (wVar2 = *(wchar_t *)
                               (((longlong)
                                 L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Video" -
                                (longlong)_Dst) + (longlong)pwVar11), wVar2 == L'\0')) break;
                  *pwVar11 = wVar2;
                  pwVar11 = pwVar11 + 1;
                  uVar14 = uVar14 - 1;
                } while (uVar14 != 0);
                pwVar17 = pwVar11 + -1;
                if (uVar14 != 0) {
                  pwVar17 = pwVar11;
                }
                *pwVar17 = L'\0';
              }
              RtlStringCbCatW(_Dst,uVar15,0x1c00063cc);
              lVar8 = -1;
              do {
                lVar8 = lVar8 + 1;
              } while (_Dst[lVar8] != L'\0');
              pwVar11 = _Dst + lVar8;
              if (uVar10 != 0) {
                uVar14 = (ulonglong)(*(uint *)(lVar9 + 8) >> 1);
                if (uVar14 < 0x7fffffff) {
                  lVar8 = uVar14 - uVar10;
                  lVar16 = lVar9 - (longlong)pwVar11;
                  do {
                    if ((lVar8 + uVar10 == 0) ||
                       (wVar2 = *(wchar_t *)(lVar16 + 0xc + (longlong)pwVar11), wVar2 == L'\0'))
                    break;
                    *pwVar11 = wVar2;
                    pwVar11 = pwVar11 + 1;
                    uVar10 = uVar10 - 1;
                  } while (uVar10 != 0);
                  pwVar17 = pwVar11 + -1;
                  if (uVar10 != 0) {
                    pwVar17 = pwVar11;
                  }
                  *pwVar17 = L'\0';
                }
                else {
                  *pwVar11 = L'\0';
                }
              }
              uVar10 = 0xffffffffffffffff;
              do {
                uVar10 = uVar10 + 1;
              } while (_Dst[uVar10] != L'\0');
              RtlStringCbCatW(_Dst,uVar15,0x1c00063cc);
              RtlStringCbCatW(_Dst,uVar15,0x1c00065d8);
              iVar4 = RtlCheckRegistryKey(0,_Dst);
              if (iVar4 == 0) {
LAB_1c00031e0:
                _Dst[uVar10 & 0xffffffff] = L'\0';
                lVar8 = -1;
                do {
                  lVar8 = lVar8 + 1;
                } while (_Dst[lVar8] != L'\0');
                pwVar17 = L"\\%04d";
                RtlStringCbPrintfW(_Dst + lVar8,uVar15,L"\\%04d",(ulonglong)local_70);
                pwVar11 = _Dst;
                iVar4 = RtlCheckRegistryKey(0);
                if (iVar4 == 0) {
                  lVar8 = local_78;
                }
                else {
                  iVar4 = RtlCreateRegistryKey(0,_Dst);
                  if (iVar4 != 0) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
                      uVar12 = 0x4e;
                      goto LAB_1c0002f36;
                    }
                    goto LAB_1c00030ef;
                  }
LAB_1c0002e42:
                  lVar8 = local_78;
                  pwVar11 = _Dst;
                  VpInitializeLegacyKey(*(undefined8 *)(local_78 + 0x50));
                }
                lVar16 = -1;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
                  WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar11,pwVar17,_Dst);
                }
                *(wchar_t **)(lVar8 + 0x40) = _Dst;
                do {
                  lVar16 = lVar16 + 1;
                } while (_Dst[lVar16] != L'\0');
                *(int *)(lVar8 + 0x48) = (int)lVar16 * 2;
                _Dst = (wchar_t *)0x0;
                if (lVar9 == 0) goto LAB_1c0003100;
              }
              else {
                iVar4 = RtlCreateRegistryKey(0,_Dst);
                if (iVar4 == 0) {
                  local_a0 = (undefined4 *)CONCAT44(local_a0._4_4_,local_94 * 2 + 2);
                  local_a8 = psVar6;
                  iVar4 = RtlWriteRegistryValue(0,_Dst,L"Service",1);
                  if (iVar4 == 0) goto LAB_1c00031e0;
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                    uVar12 = 0x4d;
                    goto LAB_1c00030dd;
                  }
                }
                else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                  uVar12 = 0x4c;
LAB_1c00030dd:
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                          &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
                }
              }
            }
          }
LAB_1c00030ef:
          ExFreePoolWithTag(lVar9,0);
        }
      }
      else {
        iVar4 = ExUuidCreate(&local_58);
        if ((iVar4 == 0) || (iVar4 == 0x40020056)) {
          iVar4 = RtlStringFromGUID(&local_58,local_90 + 1);
          if ((iVar4 != 0) || (local_80 == (short *)0x0)) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                      &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
            }
            local_80 = (short *)0x0;
            goto LAB_1c000312c;
          }
          RtlUpcaseUnicodeString(local_90 + 1,local_90 + 1,0);
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (local_80[lVar8] != 0);
          uVar18 = (int)lVar8 * 2 + 0x8a;
          uVar15 = (ulonglong)uVar18;
          _Dst = (wchar_t *)ExAllocatePool2(0x100,uVar18,0x74727056);
          if (_Dst == (wchar_t *)0x0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              uVar12 = 0x51;
LAB_1c0002a8d:
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                      &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
            }
          }
          else {
            memset(_Dst,0,uVar15);
            uVar10 = (ulonglong)(uVar18 >> 1);
            if (uVar10 != 0) {
              lVar8 = 0x7ffffffe - uVar10;
              pwVar11 = _Dst;
              do {
                if ((lVar8 + uVar10 == 0) ||
                   (wVar2 = *(wchar_t *)
                             (((longlong)
                               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Video" -
                              (longlong)_Dst) + (longlong)pwVar11), wVar2 == L'\0')) break;
                *pwVar11 = wVar2;
                pwVar11 = pwVar11 + 1;
                uVar10 = uVar10 - 1;
              } while (uVar10 != 0);
              pwVar17 = pwVar11 + -1;
              if (uVar10 != 0) {
                pwVar17 = pwVar11;
              }
              *pwVar17 = L'\0';
            }
            iVar4 = RtlCreateRegistryKey(0,_Dst);
            if (iVar4 == 0) {
              RtlStringCbCatW(_Dst,uVar15,0x1c00063cc);
              RtlStringCbCatW(_Dst,uVar15,(longlong)local_80);
              iVar4 = RtlCreateRegistryKey(0,_Dst);
              if (iVar4 == 0) {
                uVar10 = 0xffffffffffffffff;
                do {
                  uVar10 = uVar10 + 1;
                } while (_Dst[uVar10] != L'\0');
                RtlStringCbCatW(_Dst,uVar15,0x1c00063cc);
                RtlStringCbCatW(_Dst,uVar15,0x1c00065d8);
                iVar4 = RtlCreateRegistryKey(0,_Dst);
                if (iVar4 == 0) {
                  iVar4 = local_94 * 2 + 2;
                  local_a0 = (undefined4 *)CONCAT44(local_a0._4_4_,iVar4);
                  local_a8 = psVar6;
                  iVar5 = RtlWriteRegistryValue(0,_Dst,L"Service",1);
                  if (iVar5 == 0) {
                    if (local_90[0] != 0) {
                      local_a0 = (undefined4 *)CONCAT44(local_a0._4_4_,iVar4);
                      local_a8 = psVar6;
                      iVar4 = RtlWriteRegistryValue(0x40000000,local_90[0],L"Service",1);
                      if (iVar4 != 0) {
                        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                          uVar12 = 0x56;
                          goto LAB_1c0002959;
                        }
                        goto LAB_1c0003100;
                      }
                    }
                    _Dst[uVar10 & 0xffffffff] = L'\0';
                    RtlStringCbCatW(_Dst,uVar15,0x1c0006608);
                    iVar4 = RtlCreateRegistryKey(0,_Dst);
                    if (iVar4 == 0) {
                      lVar8 = -1;
                      do {
                        lVar8 = lVar8 + 1;
                      } while (local_80[lVar8] != 0);
                      local_a0 = (undefined4 *)CONCAT44(local_a0._4_4_,(int)lVar8 * 2 + 2);
                      pwVar17 = L"VideoID";
                      local_a8 = local_80;
                      iVar4 = RtlWriteRegistryValue(0x40000000,local_90[0],L"VideoID",1);
                      if (iVar4 == 0) goto LAB_1c0002e42;
                      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                        uVar12 = 0x58;
                        goto LAB_1c0002a8d;
                      }
                    }
                    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
                      uVar12 = 0x57;
                      goto LAB_1c0002a8d;
                    }
                  }
                  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                    uVar12 = 0x55;
                    goto LAB_1c0002959;
                  }
                }
                else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
                  uVar12 = 0x54;
LAB_1c0002959:
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                          &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
                }
              }
              else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
                uVar12 = 0x53;
                goto LAB_1c0002a8d;
              }
            }
            else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
              uVar12 = 0x52;
              goto LAB_1c0002a8d;
            }
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar12 = 0x4f;
          goto LAB_1c0002a8d;
        }
      }
    }
  }
LAB_1c0003100:
  if (local_80 != (short *)0x0) {
    RtlFreeUnicodeString(local_90 + 1);
  }
  if (_Dst != (wchar_t *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1c000312c:
  if (local_90[0] != 0) {
    ZwClose();
  }
  if (psVar6 != (short *)0x0) {
    ExFreePoolWithTag(psVar6,0);
  }
  return;
}



===== VpGetServiceSubkey @ 1c00032e8 =====

undefined1 VpGetServiceSubkey(ushort *param_1,undefined8 param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  short *_Dst;
  ulonglong uVar4;
  short *psVar5;
  ulonglong uVar6;
  longlong lVar7;
  short *psVar8;
  undefined1 uVar10;
  undefined1 uVar9;
  longlong lVar11;
  ulonglong _Size;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar1 = *param_1;
  _Size = (ulonglong)(ushort)(uVar1 + 0xe);
  uVar10 = 0;
  uVar9 = 0;
  local_44 = 0;
  local_2c = 0;
  local_58 = 0;
  uStack_50 = 0;
  _Dst = (short *)ExAllocatePool2(0x100,_Size,0x74727056);
  if (_Dst == (short *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
  }
  else {
    memset(_Dst,0,_Size);
    uVar6 = (ulonglong)((ushort)(uVar1 + 0xe) >> 1);
    if (uVar6 != 0) {
      uVar4 = uVar6;
      psVar8 = _Dst;
      do {
        if (*psVar8 == 0) break;
        psVar8 = psVar8 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      if (uVar4 != 0) {
        psVar8 = _Dst + (uVar6 - uVar4);
        lVar7 = uVar6 - (uVar6 - uVar4);
        if (lVar7 != 0) {
          uVar6 = (ulonglong)(*param_1 >> 1);
          lVar11 = *(longlong *)(param_1 + 4) - (longlong)psVar8;
          do {
            if ((uVar6 == 0) || (sVar2 = *(short *)(lVar11 + (longlong)psVar8), sVar2 == 0)) break;
            *psVar8 = sVar2;
            uVar6 = uVar6 - 1;
            psVar8 = psVar8 + 1;
            lVar7 = lVar7 + -1;
          } while (lVar7 != 0);
        }
        psVar5 = psVar8 + -1;
        if (lVar7 != 0) {
          psVar5 = psVar8;
        }
        *psVar5 = 0;
      }
    }
    RtlStringCbCatW(_Dst,_Size,0x1c00063cc);
    RtlStringCbCatW(_Dst,_Size,0x1c00065d8);
    RtlInitUnicodeString(&local_58,_Dst);
    local_38 = &local_58;
    local_48 = 0x30;
    local_40 = 0;
    local_30 = 0x240;
    local_28 = 0;
    uStack_20 = 0;
    iVar3 = ZwCreateKey(param_2,0xc0000000,&local_48,0,0,0,0);
    if (iVar3 == 0) {
      uVar9 = 1;
    }
    else {
      uVar9 = uVar10;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
    }
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar9;
}



===== VpInitializeLegacyKey @ 1c00034f8 =====

void VpInitializeLegacyKey(undefined8 param_1)

{
  int iVar1;
  longlong local_res18;
  longlong local_res20;
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
  
  local_res18 = 0;
  local_res20 = 0;
  local_1c = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_48);
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(&local_res18,0xf003f,&local_38);
  if (iVar1 == 0) {
    RtlInitUnicodeString(&local_48,param_1);
    local_30 = 0;
    local_28 = &local_48;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwOpenKey(&local_res20,0xc0000000);
    if (iVar1 == 0) {
      VpCopyRegistry(local_res20,local_res18,0,0);
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      local_res20 = 0;
    }
    if (local_res18 != 0) {
      ZwClose();
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
    local_res18 = 0;
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  return;
}



===== VpRegistryCallback @ 1c0003690 =====

undefined8
VpRegistryCallback(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined4 *param_4,
                  int param_5)

{
  if ((param_5 == 0) || (param_4 == (undefined4 *)0x0)) {
    return 0x57;
  }
  *param_2 = *param_4;
  return 0;
}



===== WPP_SF_L @ 1c00036b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DDD @ 1c00036fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids,0x43,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_LLL @ 1c0003760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids,0xb,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_S @ 1c00037c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids,0x59,param_4,lVar1,0);
  return;
}



===== WPP_SF_s @ 1c000383c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids,0x34,param_4,lVar2,0);
  return;
}



===== WPP_SF_sd @ 1c00038a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids,0x35,param_4,lVar2,
             &param_5,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0003930 =====

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



===== pVideoPortEnumBusses @ 1c0003964 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong pVideoPortEnumBusses(uint *param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 auStack_1a8 [32];
  wchar_t *local_188;
  undefined8 local_180;
  code *local_178;
  undefined8 local_170;
  uint local_168 [2];
  undefined8 local_160;
  int local_158 [2];
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 *local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  ulonglong uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  wchar_t local_108 [104];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_168[0] = 0;
  local_160 = 0;
  local_130 = 0;
  uStack_128 = uStack_128 & 0xffffffff00000000;
  local_150 = 0;
  uStack_148 = 0;
  local_140 = (undefined8 *)0x0;
  uStack_138 = 0;
  local_120 = 0;
  uStack_118 = 0;
  if (param_2 == 5) {
    local_188 = L"PCIBus";
  }
  else {
    local_188 = (wchar_t *)0x0;
    *param_1 = *param_1 | 0x80000000;
  }
  uVar2 = *param_1;
  local_158[0] = param_2;
  if (-1 < (int)uVar2) {
    uVar3 = RtlStringCchPrintfW(local_108,0x61,L"%s\\%s",
                                L"\\REGISTRY\\MACHINE\\HARDWARE\\DESCRIPTION\\System\\VideoAdapterBusses"
                               );
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    RtlInitUnicodeString(&local_120,local_108);
    uStack_148 = 0;
    local_140 = &local_120;
    local_150 = CONCAT44(local_150._4_4_,0x30);
    uStack_138 = CONCAT44(uStack_138._4_4_,0x240);
    local_130 = 0;
    uStack_128 = 0;
    iVar1 = ZwOpenKey(&local_160,0x20019,&local_150);
    if (-1 < iVar1) {
      uVar3 = pVideoPortGetBusNumber(local_160,(ulonglong)(*param_1 & 0x7fffffff),local_168);
      if (-1 < (int)uVar3) {
        uVar2 = *param_1;
        *param_1 = (uVar2 + 1 ^ uVar2) & 0x7fffffff ^ uVar2;
        *param_3 = local_168[0];
        ZwClose(local_160);
        return uVar3 & 0xffffffff;
      }
      ZwClose(local_160);
    }
    *param_1 = 0x80000000;
    uVar2 = 0;
  }
  local_170 = 0;
  local_168[0] = uVar2 & 0x7fffffff;
  local_178 = VideoPortGetAssociatedDeviceExtension;
  local_180 = 0;
  local_188 = (wchar_t *)0x0;
  uVar3 = IoQueryDeviceDescription(local_158,local_168,0,0);
  if (-1 < (int)uVar3) {
    *param_3 = local_168[0];
    uVar2 = *param_1;
    *param_1 = (uVar2 + 1 ^ uVar2) & 0x7fffffff ^ uVar2;
  }
  return uVar3;
}



===== pVideoPortGetBusNumber @ 1c0003b3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong pVideoPortGetBusNumber(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined4 *local_d0;
  undefined4 local_c8 [2];
  undefined8 local_c0;
  undefined1 local_b8 [4];
  undefined4 local_b4;
  undefined1 *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [4];
  int local_74;
  int local_70;
  undefined4 local_6c;
  undefined1 local_60 [16];
  undefined1 auStack_50 [40];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  local_8c = 0;
  local_c8[0] = 0;
  local_c0 = 0;
  local_b4 = 0;
  local_a4 = 0;
  local_d0 = local_c8;
  local_d8 = 0x38;
  uVar2 = ZwEnumerateKey(param_1,param_2,0,local_60);
  if (-1 < (int)uVar2) {
    local_b0 = auStack_50;
    local_a8 = 0x30;
    local_98 = local_b8;
    local_90 = 0x240;
    local_88 = 0;
    uStack_80 = 0;
    local_a0 = param_1;
    uVar2 = ZwOpenKey(&local_c0,0x20019,&local_a8);
    if (-1 < (int)uVar2) {
      RtlInitUnicodeString(local_b8,L"");
      local_d0 = local_c8;
      local_d8 = 0x14;
      uVar1 = ZwQueryValueKey(local_c0,local_b8,2,local_78);
      uVar2 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        if ((local_70 == 4) && (local_74 == 4)) {
          *param_3 = local_6c;
        }
        else {
          uVar2 = 0xc0000001;
        }
      }
      ZwClose(local_c0);
    }
  }
  return uVar2;
}



===== pVideoPortHwTimer @ 1c0003c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void pVideoPortHwTimer(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0x40) + 0xd0))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x10));
  return;
}



===== pVideoPortLogErrorEntryDPC @ 1c0003cc0 =====

void pVideoPortLogErrorEntryDPC(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined2 *puVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  puVar2 = (undefined2 *)IoAllocateErrorLogEntry(param_2,0x34);
  if (puVar2 == (undefined2 *)0x0) goto LAB_1c0003d64;
  *puVar2 = 0xe;
  *(undefined4 *)(puVar2 + 2) = 0;
  puVar2[4] = 0;
  iVar3 = *(int *)(lVar1 + 0x13c);
  if (iVar3 == 0) {
LAB_1c0003d29:
    iVar3 = 0;
  }
  else if (iVar3 == 1) {
LAB_1c0003d82:
    iVar3 = -0x3ffbfff0;
  }
  else if (iVar3 == 8) {
LAB_1c0003d7a:
    iVar3 = -0x3ffbfffe;
  }
  else if (iVar3 == 0x37) {
    iVar3 = -0x3ffbfffd;
  }
  else {
    if (iVar3 == 0x57) goto LAB_1c0003d82;
    if (iVar3 == 0x7a) goto LAB_1c0003d7a;
    if ((iVar3 == 0xea) || (iVar3 == 0x3e5)) goto LAB_1c0003d29;
  }
  *(int *)(puVar2 + 6) = iVar3;
  *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(lVar1 + 0x140);
  *(undefined8 *)(puVar2 + 10) = 0;
  *(undefined4 *)(puVar2 + 0xe) = *(undefined4 *)(lVar1 + 0x138);
  puVar2[1] = 4;
  *(undefined4 *)(puVar2 + 0x14) = *(undefined4 *)(lVar1 + 0x13c);
  IoWriteErrorLogEntry(puVar2);
LAB_1c0003d64:
  *(uint *)(lVar1 + 0x128) = *(uint *)(lVar1 + 0x128) & 0xfffffffe;
  return;
}



===== VideoPortCreateSecondaryDisplay @ 1c0003d90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortCreateSecondaryDisplay(void)

{
                    /* 0x3d90  16  VideoPortCreateSecondaryDisplay */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x2fd;
  return 0x57;
}



===== _guard_check_icall @ 1c0003dd0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0003de8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0003e0c =====

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



===== __cpu_features_init @ 1c0003e80 =====

/* WARNING: Removing unreachable block (ram,0x0001c0003eea) */
/* WARNING: Removing unreachable block (ram,0x0001c0003e99) */
/* WARNING: Removing unreachable block (ram,0x0001c0003e8a) */

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



===== __security_check_cookie @ 1c0003f50 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0003f90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0003fc0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003ff0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0004040 =====

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



===== memset @ 1c0004340 =====

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



===== __memset_repmovs @ 1c0004480 =====

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



===== __memset_query @ 1c0004500 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0004580 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00046c0 =====

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



===== __memset_spec_plain @ 1c0004740 =====

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



===== VideoPortDbgReportComplete @ 1c000b010 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortDbgReportComplete(void)

{
                    /* 0xb010  19  VideoPortDbgReportComplete */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x49;
  return;
}



===== VideoPortDbgReportCreate @ 1c000b040 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortDbgReportCreate(void)

{
                    /* 0xb040  20  VideoPortDbgReportCreate */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x2f;
  return 0;
}



===== VideoPortDbgReportSecondaryData @ 1c000b070 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortDbgReportSecondaryData(void)

{
                    /* 0xb070  21  VideoPortDbgReportSecondaryData */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x3d;
  return 0;
}



===== VideoPortAcquireDeviceLock @ 1c000b0a0 =====

void VideoPortAcquireDeviceLock(longlong param_1)

{
                    /* 0xb0a0  2  VideoPortAcquireDeviceLock */
  KeWaitForSingleObject(*(longlong *)(param_1 + -0x58) + 0x40,0,0,0,0);
  return;
}



===== VideoPortGetAssociatedDeviceExtension @ 1c000b0e0 =====

undefined8 VideoPortGetAssociatedDeviceExtension(void)

{
                    /* 0xb0e0  35  VideoPortGetAssociatedDeviceExtension */
  return 0;
}



===== VideoPortGetAssociatedDeviceID @ 1c000b0f0 =====

undefined8 VideoPortGetAssociatedDeviceID(void)

{
                    /* 0xb0f0  36  VideoPortGetAssociatedDeviceID */
  return 0xffffffff;
}



===== VideoPortRegisterBugcheckCallback @ 1c000b100 =====

undefined8
VideoPortRegisterBugcheckCallback(longlong param_1,int param_2,longlong param_3,int param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  
                    /* 0xb100  82  VideoPortRegisterBugcheckCallback */
  lVar1 = *(longlong *)(param_1 + -0x58);
  uVar2 = 0xc000009a;
  if (param_2 != 0xea) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_3724e864d48c3292fddfb70a1c89e8e6_Traceguids);
    }
    return 0xc000000d;
  }
  uVar3 = param_4 + 0xfU & 0xfffffff0;
  if (4000 < uVar3) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc000000d;
    }
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_3724e864d48c3292fddfb70a1c89e8e6_Traceguids,4000);
    return 0xc000000d;
  }
  KeWaitForSingleObject(&VpGlobalLock,0,0,0,0);
  if ((param_3 == 0) || (uVar3 == 0)) {
    if (*(longlong *)(lVar1 + 0x198) != 0) {
      *(undefined8 *)(lVar1 + 0x198) = 0;
      *(undefined4 *)(lVar1 + 0x1a0) = 0;
    }
  }
  else {
    if ((VpBugcheckData == 0) &&
       (VpBugcheckData = ExAllocatePool2(0x40,0x8015,0x74727056), VpBugcheckData == 0))
    goto LAB_1c000b22a;
    *(longlong *)(lVar1 + 0x198) = param_3;
    *(uint *)(lVar1 + 0x1a0) = uVar3;
  }
  uVar2 = 0;
LAB_1c000b22a:
  KeReleaseMutex(&VpGlobalLock,0);
  return uVar2;
}



===== VideoPortReleaseDeviceLock @ 1c000b260 =====

void VideoPortReleaseDeviceLock(longlong param_1)

{
                    /* 0xb260  85  VideoPortReleaseDeviceLock */
  KeReleaseMutex(*(longlong *)(param_1 + -0x58) + 0x40,0);
  return;
}



===== VideoPortCreateEvent @ 1c000b290 =====

undefined8
VideoPortCreateEvent(undefined8 param_1,byte param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong *plVar1;
  undefined8 uVar2;
  
                    /* 0xb290  15  VideoPortCreateEvent */
  uVar2 = 0x74727056;
  plVar1 = (longlong *)ExAllocatePool2(0x40,0x28,0x74727056);
  if (plVar1 == (longlong *)0x0) {
    uVar2 = 8;
  }
  else {
    *(undefined4 *)(plVar1 + 1) = 0;
    *plVar1 = (longlong)(plVar1 + 2);
    KeInitializeEvent(plVar1 + 2,~param_2 & 1,
                      CONCAT71((int7)((ulonglong)uVar2 >> 8),param_2) & 0xffffffffffffff02);
    uVar2 = 0;
    *param_4 = plVar1;
  }
  return uVar2;
}



===== VideoPortCreateSpinLock @ 1c000b310 =====

undefined8 VideoPortCreateSpinLock(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
                    /* 0xb310  17  VideoPortCreateSpinLock */
  lVar1 = ExAllocatePool2(0x40,8,0x74727056);
  *param_2 = lVar1;
  if (lVar1 == 0) {
    uVar2 = 8;
  }
  else {
    KeInitializeSpinLock(lVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== VideoPortAllocateBuffer @ 1c000b360 =====

byte VideoPortAllocateBuffer(undefined8 param_1,uint param_2,longlong *param_3)

{
  longlong lVar1;
  
                    /* 0xb360  5  VideoPortAllocateBuffer */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
            &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
  }
  lVar1 = VideoPortAllocatePool(param_1,1,(ulonglong)param_2,0x20706d56);
  *param_3 = lVar1;
  return ~-(lVar1 != 0) & 8;
}



===== VideoPortFindAdapter2 @ 1c000b3e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VideoPortFindAdapter2
              (undefined8 param_1,ushort *param_2,uint *param_3,undefined8 param_4,longlong param_5,
              undefined8 param_6)

{
  ushort uVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  void *pvVar8;
  undefined4 *puVar9;
  wchar_t *_Str;
  wchar_t *pwVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  longlong *plVar14;
  undefined2 uVar15;
  undefined4 local_78 [2];
  longlong local_70;
  void *local_68;
  longlong local_60;
  undefined8 local_58;
  void *pvStack_50;
  short local_48 [8];
  
  local_78[0] = 0;
  bVar3 = false;
  local_58 = 0;
  pvStack_50 = (void *)0x0;
  _Str = (wchar_t *)0x0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  lVar7 = ExAllocatePool2(0x40,0x208,0x74727056);
  local_70 = lVar7;
  pvVar8 = (void *)ExAllocatePool2(0x40,0x208,0x74727056);
  local_68 = pvVar8;
  local_60 = ExAllocatePool2(0x40,0x208,0x74727056);
  if (((lVar7 == 0) || (pvVar8 == (void *)0x0)) || (local_60 == 0)) {
    iVar4 = -0x3fffffe9;
    iVar5 = -0x3fffffe9;
    if (local_60 == 0) goto LAB_1c000ba0a;
  }
  else {
    iVar5 = -0x3ffffff2;
    lVar2 = *(longlong *)(param_5 + 0x40);
    ObQueryNameString(param_5,lVar7,0x208,local_78);
    puVar9 = (undefined4 *)ExAllocatePool2(0x100,0x80,0x74727056);
    if (puVar9 == (undefined4 *)0x0) {
LAB_1c000b4f4:
      iVar5 = -0x3fffff66;
    }
    else {
      memset(puVar9 + 1,0,0x7c);
      *puVar9 = 0x80;
      puVar9[1] = *(undefined4 *)(lVar2 + 0xdc);
      puVar9[2] = *(undefined4 *)(lVar2 + 0xd8);
      *(code **)(puVar9 + 0x1a) = VpGetProcAddress;
      *(longlong *)(lVar2 + 0x10) = lVar2 + 0x238;
      *(uint *)(lVar2 + 0x120) = param_3[10];
      *(undefined4 **)(lVar2 + 0xb0) = puVar9;
      *(undefined8 *)(lVar2 + 0xb8) = *(undefined8 *)(param_3 + 2);
      *(undefined8 *)(lVar2 + 0xc0) = *(undefined8 *)(param_3 + 4);
      *(undefined8 *)(lVar2 + 200) = *(undefined8 *)(param_3 + 8);
      pvStack_50 = local_68;
      local_58._0_4_ = CONCAT22(0x208,(ushort)local_58);
      iVar4 = RtlAppendUnicodeToString(&local_58,L"\\Video");
      if (iVar4 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar15 = 0x3b;
          iVar5 = -0x3ffffff2;
          goto LAB_1c000b9cb;
        }
      }
      else {
        uVar1 = *param_2;
        *(uint *)(lVar2 + 0x230) = (uint)(ushort)local_58 + (uint)uVar1;
        _Str = (wchar_t *)ExAllocatePool2(0x100,(uint)(ushort)local_58 + (uint)uVar1 + 4,0x74727056)
        ;
        if (_Str == (wchar_t *)0x0) goto LAB_1c000b4f4;
        memcpy(_Str,*(void **)(param_2 + 4),(ulonglong)*param_2);
        memcpy((void *)((ulonglong)*param_2 + (longlong)_Str),local_68,local_58 & 0xffff);
        *(undefined2 *)((ulonglong)*(uint *)(lVar2 + 0x230) + (longlong)_Str) = 0;
        *(undefined2 *)((ulonglong)*(uint *)(lVar2 + 0x230) + 2 + (longlong)_Str) = 0;
        pwVar10 = wcsstr(_Str,L"MACHINE");
        if (pwVar10 != (wchar_t *)0x0) {
          pwVar10 = wcsstr(_Str,L"MACHINE");
          builtin_wcsncpy(pwVar10,L"Machine",7);
        }
        pwVar10 = wcsstr(_Str,L"SYSTEM");
        if (pwVar10 != (wchar_t *)0x0) {
          pwVar10 = wcsstr(_Str,L"SYSTEM");
          builtin_wcsncpy(pwVar10,L"System",6);
        }
        *(wchar_t **)(lVar2 + 0x228) = _Str;
        VpEnableNewRegistryKey(lVar2,lVar2 + 0x1d8,param_2,*(uint *)(lVar2 + 0x194));
        lVar7 = *(longlong *)(lVar2 + 0x218);
        if (lVar7 == 0) {
          uVar13 = *(undefined4 *)(lVar2 + 0x230);
          lVar7 = *(longlong *)(lVar2 + 0x228);
        }
        else {
          uVar13 = *(undefined4 *)(lVar2 + 0x220);
        }
        *(longlong *)(lVar2 + 0x1f0) = lVar7;
        *(undefined4 *)(lVar2 + 0x1f8) = uVar13;
        *(longlong *)(puVar9 + 0x1c) = lVar7;
        *(undefined8 *)(puVar9 + 0x1e) = VpSystemMemorySize;
        KeInitializeDpc(lVar2 + 0xe0,pVideoPortLogErrorEntryDPC);
        VideoPortGetRegistryParameters
                  (*(longlong *)(lVar2 + 0x10),0x1c0006500,'\0',VpRegistryCallback,&VideoDebugLevel)
        ;
        VpEnableDisplay(lVar2,0);
        iVar5 = (**(code **)(lVar2 + 0xb8))(*(undefined8 *)(lVar2 + 0x10),param_4,0,puVar9,param_6);
        VpEnableDisplay(lVar2,1);
        if (iVar5 == 0) {
          KeInitializeDpc(lVar2 + 0x148,pVideoPortDpcDispatcher);
          if ((((*(longlong *)(param_3 + 6) != 0) && ((puVar9[3] != 0 || (puVar9[4] != 0)))) &&
              ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                    &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
          }
          iVar5 = -0x3ffffff2;
          if (((0x38 < *param_3) &&
              (lVar7 = *(longlong *)(param_3 + 0xe), *(longlong *)(lVar2 + 0xd0) = lVar7, lVar7 != 0
              )) && (iVar5 = IoInitializeTimer(param_5,pVideoPortHwTimer), iVar5 < 0)) {
            *(undefined8 *)(lVar2 + 0xd0) = 0;
          }
          uVar11 = 0;
          plVar14 = &FdoList;
          do {
            if (*plVar14 == 0) {
              (&FdoList)[uVar11] = lVar2;
              break;
            }
            uVar6 = (int)uVar11 + 1;
            uVar11 = (ulonglong)uVar6;
            plVar14 = plVar14 + 1;
          } while (uVar6 < 8);
          *(longlong *)(lVar2 + 0xa8) = FdoHead;
          FdoHead = lVar2;
          uVar12 = pVideoPortCreateDeviceName
                             (L"\\DosDevices\\DISPLAY",*(int *)(lVar2 + 0x208) + 1,local_48,local_60
                             );
          if ((int)uVar12 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              uVar15 = 0x3e;
              goto LAB_1c000b9cb;
            }
          }
          else {
            iVar5 = IoCreateSymbolicLink(local_48,local_70);
            if (iVar5 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                uVar15 = 0x3f;
                goto LAB_1c000b9cb;
              }
            }
            else {
              bVar3 = true;
              iVar5 = RtlWriteRegistryValue
                                (4,L"VIDEO",*(undefined8 *)(local_70 + 8),1,
                                 *(undefined8 *)(lVar2 + 0x1f0),*(int *)(lVar2 + 0x1f8) + 2);
              if (((iVar5 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                        &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
              }
              iVar5 = DMgrWriteDeviceCountToRegistry();
              if (((iVar5 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                uVar15 = 0x41;
LAB_1c000b9cb:
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar15,
                        &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
              }
            }
          }
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                    &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
          }
          iVar5 = -0x3fffffff;
        }
      }
    }
    if (((*(uint *)(lVar2 + 400) & 2) == 0) && (-1 < iVar5)) {
      param_3[0xb] = param_3[0xb] + 1;
    }
    else {
      if (puVar9 != (undefined4 *)0x0) {
        ExFreePoolWithTag(puVar9,0);
      }
      if (_Str != (wchar_t *)0x0) {
        ExFreePoolWithTag(_Str,0);
        *(undefined8 *)(lVar2 + 0x228) = 0;
      }
      if (*(longlong *)(lVar2 + 0x218) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar2 + 0x218),0);
        *(undefined8 *)(lVar2 + 0x218) = 0;
      }
      *(undefined8 *)(lVar2 + 0x1f0) = 0;
      if (bVar3) {
        IoDeleteSymbolicLink(local_48);
      }
    }
    pvVar8 = local_68;
    lVar7 = local_70;
  }
  iVar4 = iVar5;
  ExFreePoolWithTag(local_60,0x74727056);
LAB_1c000ba0a:
  if (pvVar8 != (void *)0x0) {
    ExFreePoolWithTag(pvVar8,0x74727056);
  }
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0x74727056);
  }
  return iVar4;
}



===== VideoPortGetDeviceData @ 1c000bae0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
VideoPortGetDeviceData(longlong param_1,int param_2,undefined *param_3,undefined8 param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  code *pcVar6;
  undefined2 uVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined1 auStack_1c8 [32];
  undefined *local_1a8;
  undefined4 *local_1a0;
  code *local_198;
  longlong *local_190;
  undefined4 local_188;
  undefined8 local_178;
  longlong lStack_170;
  longlong local_168;
  undefined *local_160;
  undefined8 local_158;
  undefined4 local_150;
  int local_14c;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined4 local_130;
  wchar_t *local_128;
  undefined8 *local_120;
  undefined4 local_118;
  undefined8 local_110;
  undefined4 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  wchar_t *local_f0;
  undefined4 *local_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  wchar_t *local_b8;
  undefined4 *local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined4 local_60;
  ulonglong local_58;
  
                    /* 0xbae0  42  VideoPortGetDeviceData */
  local_58 = __security_cookie ^ (ulonglong)auStack_1c8;
  lVar1 = *(longlong *)(param_1 + -0x58);
  local_150 = 0;
  uVar8 = 0xc0000001;
  uVar2 = 0xc0000001;
  local_178 = 0;
  lStack_170 = 0;
  local_168 = param_1;
  local_160 = param_3;
  local_158 = param_4;
  local_14c = param_2;
  if (param_2 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
    puVar4 = (undefined4 *)ExAllocatePool2(0x100,0x1000,0x74727056);
    puVar5 = (undefined4 *)ExAllocatePool2(0x100,0x1000);
    puVar9 = (undefined8 *)0x0;
    uVar2 = uVar8;
    if (puVar4 != (undefined4 *)0x0) {
      if (puVar5 != (undefined4 *)0x0) {
        local_138 = 0;
        local_f8 = 0x124;
        local_e0 = 0x3000000;
        local_128 = L"Identifier";
        local_120 = &local_178;
        local_c0 = 0x124;
        local_a8 = 0x3000000;
        local_f0 = L"Configuration Data";
        local_130 = 0x134;
        local_b8 = L"Component Information";
        *puVar4 = 0xffc;
        *puVar5 = 0xffc;
        local_118 = 0x1000000;
        local_110 = 0;
        local_108 = 0;
        local_100 = 0;
        local_d8 = 0;
        local_d0 = 0;
        local_c8 = 0;
        local_a0 = 0;
        local_98 = 0;
        local_90 = 0;
        local_88 = 0;
        local_80 = 0;
        local_78 = 0;
        local_70 = 0;
        local_68 = 0;
        local_60 = 0;
        local_148 = 0;
        uStack_140 = 0;
        local_e8 = puVar4;
        local_b0 = puVar5;
        RtlInitUnicodeString(&local_148,L"RtlQueryRegistryValuesEx");
        pcVar6 = (code *)MmGetSystemRoutineAddress(&local_148);
        puVar9 = &local_138;
        if (pcVar6 == (code *)0x0) {
          pcVar6 = RtlQueryRegistryValues_exref;
        }
        local_1a8 = (undefined *)0x0;
        iVar3 = (*pcVar6)(0,L"\\Registry\\Machine\\Hardware\\Description\\System",puVar9,0);
        if (-1 < iVar3) {
          local_188 = *puVar5;
          local_190 = (longlong *)(puVar5 + 1);
          local_1a0 = puVar4 + 1;
          puVar9 = (undefined8 *)0x0;
          local_198 = (code *)CONCAT44(local_198._4_4_,*puVar4);
          local_1a8 = (undefined *)CONCAT44(local_1a8._4_4_,(uint)(ushort)local_178);
          iVar3 = (*(code *)param_3)(param_1,param_4,0,lStack_170);
          uVar8 = -(uint)(iVar3 != 0) & 0xc0000001;
        }
        if (lStack_170 != 0) {
          ExFreePoolWithTag(lStack_170,0);
        }
      }
      ExFreePoolWithTag(puVar4,0);
      uVar2 = uVar8;
    }
    if (puVar5 != (undefined4 *)0x0) {
      ExFreePoolWithTag(puVar5,0);
    }
  }
  else {
    if (param_2 == 1) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0x57;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) goto LAB_1c000bb95;
      uVar7 = 0x26;
LAB_1c000bb85:
      puVar9 = (undefined8 *)&WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      param_3 = (undefined *)puVar9;
      goto LAB_1c000bb95;
    }
    if (param_2 == 2) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      local_190 = &local_168;
      puVar9 = (undefined8 *)0x0;
      local_198 = pVideoPortGetDeviceDataRegistry;
      local_1a0 = (undefined4 *)0x0;
      local_1a8 = (undefined *)0x0;
      uVar2 = IoQueryDeviceDescription(lVar1 + 0xd8,lVar1 + 0xdc,0,0);
    }
    else if (param_2 == 3) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      _VpQueryDeviceControllerNumber = _VpQueryDeviceControllerNumber + 1;
      local_190 = &local_168;
      local_198 = pVideoPortGetDeviceDataRegistry;
      local_1a0 = (undefined4 *)0x0;
      local_1a8 = (undefined *)0x0;
      uVar2 = IoQueryDeviceDescription
                        (lVar1 + 0xd8,lVar1 + 0xdc,&VpQueryDeviceControllerType,
                         &VpQueryDeviceControllerNumber);
      puVar9 = (undefined8 *)0x0;
      _VpQueryDevicePeripheralNumber = 0;
    }
    else {
      if (param_2 != 4) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_1c000bb95;
        uVar7 = 0x2a;
        goto LAB_1c000bb85;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      local_190 = &local_168;
      local_198 = pVideoPortGetDeviceDataRegistry;
      local_1a0 = (undefined4 *)&VpQueryDevicePeripheralNumber;
      puVar9 = (undefined8 *)&VpQueryDeviceControllerType;
      local_1a8 = &VpQueryDevicePeripheralType;
      uVar2 = IoQueryDeviceDescription
                        (lVar1 + 0xd8,lVar1 + 0xdc,&VpQueryDeviceControllerType,
                         &VpQueryDeviceControllerNumber);
      _VpQueryDevicePeripheralNumber = _VpQueryDevicePeripheralNumber + 1;
    }
  }
  param_3 = (undefined *)puVar9;
  if (-1 < (int)uVar2) {
    return 0;
  }
LAB_1c000bb95:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_3,uVar2);
  }
  return 0x57;
}



===== VideoPortGetRegistryParameters @ 1c000bfc0 =====

void VideoPortGetRegistryParameters
               (longlong param_1,longlong param_2,char param_3,undefined8 param_4,undefined8 param_5
               )

{
  longlong lVar1;
  uint uVar2;
  
                    /* 0xbfc0  46  VideoPortGetRegistryParameters */
  lVar1 = *(longlong *)(param_1 + -0x20);
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + -0x10);
    uVar2 = *(uint *)(param_1 + -8);
  }
  else {
    uVar2 = *(uint *)(param_1 + -0x18);
  }
  VPGetRegistryParameters(param_1,param_2,param_3,param_4,param_5,lVar1,uVar2);
  return;
}



===== VideoPortInitialize @ 1c000c000 =====

ulonglong VideoPortInitialize(longlong param_1,ushort *param_2,uint *param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined2 uVar2;
  uint *puVar3;
  bool bVar4;
  uint local_res8 [2];
  byte in_stack_ffffffffffffffd8;
  undefined4 in_stack_ffffffffffffffe0;
  
                    /* 0xc000  50  VideoPortInitialize */
  LOCK();
  bVar4 = VpInitState == 0;
  if (bVar4) {
    VpInitState = 1;
  }
  UNLOCK();
  puVar3 = param_3;
  if (bVar4) {
    __security_init_cookie();
    VpInitialize();
    pVPInit();
    LOCK();
    VpInitState = 2;
    UNLOCK();
  }
  else {
    while (VpInitState != 2) {
      puVar3 = local_res8;
      local_res8[0] = 0xfffe7960;
      local_res8[1] = 0xffffffff;
      KeDelayExecutionThread(0);
    }
  }
  if (*param_3 < 0x91) {
    if (((*(longlong *)(param_3 + 2) != 0) && (*(longlong *)(param_3 + 4) != 0)) &&
       (*(longlong *)(param_3 + 8) != 0)) {
      if ((VpSetupTypeAtBoot == 4) && (*param_3 < 0x90)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                  &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
        }
        return 0xc0000001;
      }
      *(code **)(param_1 + 0xe0) = pVideoPortDispatch;
      *(code **)(param_1 + 0xe8) = pVideoPortDispatchInternalIoctl;
      *(code **)(param_1 + 0x68) = VpDriverUnload;
      *(code **)(param_1 + 0x70) = pVideoPortDispatch;
      *(code **)(param_1 + 0x80) = pVideoPortDispatch;
      *(code **)(param_1 + 0xf0) = pVideoPortDispatch;
      LOCK();
      VpMiniportCount = VpMiniportCount + 1;
      UNLOCK();
      if (VpSystemInitialized != '\0') {
        return 0xc000000d;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0,puVar3,(&BusType)[(int)param_3[1]]);
      }
      uVar1 = VideoPortLegacyFindAdapter
                        (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffd8,
                         in_stack_ffffffffffffffe0);
      return uVar1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000059;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc0000059;
    }
    uVar2 = 0x31;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000059;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc0000059;
    }
    uVar2 = 0x30;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
          &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
  return 0xc0000059;
}



===== VideoPortLegacyFindAdapter @ 1c000c210 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong VideoPortLegacyFindAdapter
                    (undefined8 param_1,ushort *param_2,uint *param_3,undefined8 param_4,
                    byte param_5,undefined4 param_6)

{
  uint *puVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint local_res18 [2];
  undefined8 local_res20;
  ulonglong in_stack_ffffffffffffff78;
  undefined4 uVar12;
  byte *in_stack_ffffffffffffff80;
  uint local_68;
  int local_64;
  ulonglong local_60;
  short local_58 [12];
  
  _VpQueryDeviceControllerNumber = 0xffffffff;
  iVar10 = param_3[10] + 0x238;
  local_res18[0] = 0;
  iVar11 = 0;
  uVar8 = 0xc000000e;
  local_res20 = param_4;
  local_64 = iVar10;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    in_stack_ffffffffffffff78 = in_stack_ffffffffffffff78 & 0xffffffff00000000;
    WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,(&BusType)[(int)param_3[1]]
              ,0);
  }
  puVar9 = local_res18;
  local_68 = 0x80000000;
  uVar6 = pVideoPortEnumBusses(&local_68,param_3[1],puVar9);
  if (-1 < (int)uVar6) {
    do {
      do {
        local_60 = 0;
        param_6 = 0;
        param_5 = 0;
        uVar5 = DMgrAcquireGdiViewId(&param_6);
        uVar4 = param_6;
        uVar8 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar8;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
            return uVar8;
          }
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,puVar9,uVar5);
          return uVar8;
        }
        local_58[0] = 0;
        local_58[1] = 0;
        local_58[2] = 0;
        local_58[3] = 0;
        local_58[4] = 0;
        local_58[5] = 0;
        local_58[6] = 0;
        local_58[7] = 0;
        lVar7 = ExAllocatePool2(0x40,0x208,0x74727056);
        if (lVar7 == 0) {
          uVar8 = 0xc0000017;
LAB_1c000c612:
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                    &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
          }
          DMgrReleaseGdiViewId(param_6,1);
          return uVar8;
        }
        uVar6 = pVideoPortCreateDeviceName(L"\\Device\\Video",uVar4,local_58,lVar7);
        uVar12 = (undefined4)(in_stack_ffffffffffffff78 >> 0x20);
        uVar8 = uVar6 & 0xffffffff;
        if (-1 < (int)uVar6) {
          in_stack_ffffffffffffff80 =
               (byte *)((ulonglong)in_stack_ffffffffffffff80 & 0xffffffffffffff00);
          uVar8 = in_stack_ffffffffffffff78 & 0xffffffff00000000;
          uVar5 = IoCreateDevice(param_1,iVar10,local_58,0x23,uVar8,in_stack_ffffffffffffff80,
                                 &local_60);
          uVar12 = (undefined4)(uVar8 >> 0x20);
          uVar8 = (ulonglong)uVar5;
          if (-1 < (int)uVar5) {
            uVar5 = IoRegisterShutdownNotification(local_60);
            uVar8 = (ulonglong)uVar5;
            if ((int)uVar5 < 0) {
              IoDeleteDevice(local_60);
              local_60 = 0;
            }
            else {
              *(undefined4 *)(local_60 + 0x48) = 0x23;
              puVar2 = *(undefined4 **)(local_60 + 0x40);
              puVar2[0x84] = 0;
              puVar2[0x8d] = 0xffffffff;
              puVar2[1] = 0;
              puVar2[0x76] = 0x74727056;
              *puVar2 = 0x74727056;
              *(undefined4 **)(puVar2 + 0x7a) = puVar2 + 0x8e;
              puVar2[0x82] = uVar4;
              *(undefined4 **)(puVar2 + 0x78) = puVar2;
              puVar2[0x77] = 1;
              *(undefined4 **)(puVar2 + 2) = puVar2;
              *(ulonglong *)(puVar2 + 0x26) = local_60;
              *(undefined8 *)(puVar2 + 0x62) = param_1;
              puVar2[0x69] = 1;
              KeInitializeMutex(puVar2 + 0x10,0);
            }
          }
        }
        ExFreePoolWithTag(lVar7,0x74727056);
        if ((int)uVar8 < 0) goto LAB_1c000c612;
        lVar7 = *(longlong *)(local_60 + 0x40);
        *(uint *)(lVar7 + 0xdc) = local_res18[0];
        *(uint *)(lVar7 + 0xd8) = param_3[1];
        *(int *)(lVar7 + 0x194) = iVar11;
        IoInitializeRemoveLockEx(lVar7 + 0x78,0x74727056,0,0x100,CONCAT44(uVar12,0x20));
        in_stack_ffffffffffffff78 = 0;
        *(undefined4 *)(lVar7 + 400) = 8;
        puVar9 = (uint *)0x0;
        KeWaitForSingleObject(lVar7 + 0x40,0,0,0,0);
        uVar6 = local_60;
        lVar3 = *(longlong *)(local_60 + 0x40);
        if (VpSetupType == 4) {
          uVar8 = 0xc000000e;
        }
        else {
          in_stack_ffffffffffffff80 = &param_5;
          puVar9 = param_3;
          in_stack_ffffffffffffff78 = local_60;
          uVar5 = VideoPortFindAdapter2
                            (param_1,param_2,param_3,local_res20,local_60,in_stack_ffffffffffffff80)
          ;
          uVar8 = (ulonglong)uVar5;
          if (-1 < (int)uVar5) {
            puVar9 = (uint *)0x1;
            *(undefined4 *)(lVar3 + 0x1c) = 1;
            PoSetPowerState(uVar6,1);
            *(uint *)(uVar6 + 0x30) = *(uint *)(uVar6 + 0x30) & 0xffffbf7f | 0x2004;
            puVar1 = (uint *)(lVar3 + 400);
            *puVar1 = *puVar1 | 0x80;
          }
        }
        KeReleaseMutex(lVar7 + 0x40,0);
        iVar10 = (int)uVar8;
        if (iVar10 < 0) {
          DMgrReleaseGdiViewId(param_6,1);
        }
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,puVar9,iVar10);
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
            puVar9 = (uint *)&WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids;
            WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                     &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids,(uint)param_5);
          }
        }
        if (iVar10 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            puVar9 = (uint *)&WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                    &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
          }
          IoDeleteDevice(local_60);
        }
        else {
          iVar11 = iVar11 + 1;
        }
        iVar10 = local_64;
      } while (param_5 != 0);
      puVar9 = local_res18;
      uVar6 = pVideoPortEnumBusses(&local_68,param_3[1],puVar9);
    } while (-1 < (int)uVar6);
    if (iVar11 != 0) {
      return 0;
    }
  }
  return uVar8;
}



===== VideoPortQueryServices @ 1c000c6a0 =====

undefined8 VideoPortQueryServices(void)

{
                    /* 0xc6a0  66  VideoPortQueryServices */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
            &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
  }
  return 0x57;
}



===== VideoPortReleaseBuffer @ 1c000c6f0 =====

void VideoPortReleaseBuffer(undefined8 param_1,undefined8 param_2)

{
                    /* 0xc6f0  83  VideoPortReleaseBuffer */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
            &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
  }
  VideoPortFreePool(param_1,param_2);
  return;
}



===== VideoPortSetRegistryParameters @ 1c000c750 =====

void VideoPortSetRegistryParameters
               (longlong param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  
                    /* 0xc750  93  VideoPortSetRegistryParameters */
  lVar1 = *(longlong *)(param_1 + -0x20);
  if (lVar1 == 0) {
    uVar2 = *(uint *)(param_1 + -8);
    lVar1 = *(longlong *)(param_1 + -0x10);
  }
  else {
    uVar2 = *(uint *)(param_1 + -0x18);
  }
  VPSetRegistryParameters(param_1,param_2,param_3,param_4,lVar1,uVar2);
  return;
}



===== VpDriverUnload @ 1c000c790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VpDriverUnload(void)

{
  int iVar1;
  undefined *puVar2;
  bool bVar3;
  
  LOCK();
  iVar1 = VpMiniportCount + -1;
  UNLOCK();
  bVar3 = VpMiniportCount == 1;
  VpMiniportCount = iVar1;
  if ((bVar3) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) {
    puVar2 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x10)) {
        if (*(longlong *)(puVar2 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar2 + 0x38) = 0;
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



===== VpEnableDisplay @ 1c000c820 =====

void VpEnableDisplay(longlong param_1,byte param_2)

{
  char cVar1;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  ulonglong local_18;
  undefined4 local_10;
  
  cVar1 = InbvCheckDisplayOwnership();
  if (cVar1 == '\0') {
    local_1c = 0;
    local_10 = 0;
    local_28 = 4;
    uStack_24 = 0;
    uStack_20 = 0;
    local_18 = (ulonglong)param_2;
    KeReleaseMutex(param_1 + 0x40,0);
    SMgrGdiCallout(&local_28,0x200000000,1,0,0,0);
    KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
  }
  else {
    InbvEnableBootDriver(param_2);
  }
  return;
}



===== WppInitGlobalLogger @ 1c000c8e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WppInitGlobalLogger(undefined8 param_1,undefined8 *param_2,uint *param_3,undefined1 *param_4)

{
  int iVar1;
  code *pcVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 auStack_1c8 [32];
  undefined8 local_1a8;
  undefined4 local_198;
  int local_194;
  uint local_190;
  undefined4 local_18c;
  ulonglong local_188;
  longlong lStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined4 local_160;
  wchar_t *local_158;
  uint *local_150;
  undefined4 local_148;
  undefined4 *local_140;
  undefined4 local_138;
  undefined8 local_130;
  undefined4 local_128;
  wchar_t *local_120;
  undefined4 *local_118;
  undefined4 local_110;
  undefined4 *local_108;
  undefined4 local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  wchar_t local_b8 [56];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1c8;
  local_160 = 0x20;
  local_190 = 0;
  local_18c = 0;
  local_158 = L"Start";
  local_150 = (uint *)&local_194;
  local_194 = 0;
  local_140 = &local_198;
  local_198 = 0;
  local_168 = 0;
  local_148 = 4;
  local_138 = 4;
  local_130 = 0;
  local_188 = 0;
  lStack_180 = 0;
  local_128 = 0;
  local_178 = 0;
  uStack_170 = 0;
  RtlInitUnicodeString(&local_178,L"RtlQueryRegistryValuesEx");
  pcVar2 = (code *)MmGetSystemRoutineAddress(&local_178);
  local_1a8 = 0;
  if (pcVar2 == (code *)0x0) {
    pcVar2 = RtlQueryRegistryValues_exref;
  }
  iVar1 = (*pcVar2)(0x80000002,L"WMI\\GlobalLogger\\",&local_168,0);
  if ((-1 < iVar1) && (local_194 != 0)) {
    local_148 = 4;
    local_158 = L"Flags";
    local_150 = &local_190;
    local_138 = 4;
    local_140 = &local_198;
    local_110 = 4;
    local_168 = 0;
    local_120 = L"Level";
    local_118 = &local_18c;
    local_108 = &local_198;
    builtin_wcsncpy(local_b8,L"WMI\\GlobalLogger\\",0x12);
    local_160 = 0x20;
    local_130 = 0;
    local_128 = 0x20;
    local_100 = 1;
    local_f8 = 0;
    local_f0 = 0;
    iVar1 = RtlStringFromGUID(param_1,&local_188);
    if (iVar1 == 0) {
      if ((ushort)local_188 < 0x4d) {
        lVar4 = -1;
        uVar3 = 0xffffffffffffffff;
        do {
          uVar3 = uVar3 + 1;
        } while (local_b8[uVar3] != L'\0');
        memcpy(local_b8 + (uVar3 & 0xffffffff),(void *)(lStack_180 + 2),local_188 & 0xffff);
        do {
          lVar4 = lVar4 + 1;
        } while (local_b8[lVar4] != L'\0');
        uVar3 = (ulonglong)((int)lVar4 - 1);
        if (0x6f < uVar3 * 2) {
          __report_rangecheckfailure();
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        local_b8[uVar3] = L'\0';
        RtlFreeUnicodeString(&local_188);
        local_178 = 0;
        uStack_170 = 0;
        RtlInitUnicodeString(&local_178,L"RtlQueryRegistryValuesEx");
        pcVar2 = (code *)MmGetSystemRoutineAddress(&local_178);
        local_1a8 = 0;
        if (pcVar2 == (code *)0x0) {
          pcVar2 = RtlQueryRegistryValues_exref;
        }
        iVar1 = (*pcVar2)(0x80000002,local_b8,&local_168,0);
        if ((-1 < iVar1) && (local_194 == 1)) {
          *param_2 = 1;
          *param_3 = local_190 & 0x7fffffff;
          *param_4 = (undefined1)local_18c;
        }
      }
      else {
        RtlFreeUnicodeString(&local_188);
      }
    }
  }
  return;
}



===== WppInitKm @ 1c000cbbc =====

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
    }
    else if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
  }
  return;
}



===== WppLoadTracingSupport @ 1c000cc4c =====

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



===== WppTraceCallback @ 1c000cd90 =====

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
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
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
    if ((param_1 == 6) || (param_1 == 7)) {
      return 0;
    }
    if (param_1 == 8) {
      uVar9 = 0;
      puVar3 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar9 = uVar9 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar9) {
        return 0xc000000d;
      }
      uVar10 = uVar9 * 0x20 + 0x18;
      if (puVar3 == (ushort *)0x0) {
        uVar11 = uVar10;
        uVar10 = 0;
      }
      else {
        uVar11 = *puVar3 + 2 + uVar10;
      }
      if (param_3 < uVar11) {
        uVar6 = 0xc0000023;
        if (3 < param_3) {
          *param_4 = uVar11;
          *param_6 = 4;
        }
      }
      else {
        memset(param_4,0,(ulonglong)param_3);
        *param_4 = uVar11;
        param_4[2] = uVar10;
        param_4[4] = uVar9;
        if (puVar3 != (ushort *)0x0) {
          *(ushort *)((ulonglong)uVar10 + (longlong)param_4) = *puVar3;
          memcpy((ushort *)((ulonglong)uVar10 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
                 (ulonglong)*puVar3);
        }
        if (uVar9 != 0) {
          uVar8 = (ulonglong)uVar9;
          lVar7 = param_5;
          puVar12 = param_4 + 10;
          do {
            uVar2 = **(undefined8 **)(lVar7 + 8);
            uVar4 = (*(undefined8 **)(lVar7 + 8))[1];
            *puVar12 = 0x81000;
            *(undefined8 *)(puVar12 + -4) = uVar2;
            *(undefined8 *)(puVar12 + -2) = uVar4;
            *(undefined4 *)(lVar7 + 0x2c) = 0;
            *(undefined1 *)(lVar7 + 0x29) = 0;
            lVar7 = *(longlong *)(lVar7 + 0x10);
            uVar8 = uVar8 - 1;
            puVar12 = puVar12 + 8;
          } while (uVar8 != 0);
        }
        uVar6 = 0;
        *puVar1 = uVar11;
      }
      do {
        WppInitGlobalLogger(*(undefined8 *)(param_5 + 8),(undefined8 *)(param_5 + 0x18),
                            (uint *)(param_5 + 0x2c),(undefined1 *)(param_5 + 0x29));
        param_5 = *(longlong *)(param_5 + 0x10);
      } while (param_5 != 0);
      return uVar6;
    }
  }
  return 0xc0000010;
}



===== pVideoPortCreateDeviceName @ 1c000d034 =====

undefined8
pVideoPortCreateDeviceName(undefined8 param_1,undefined4 param_2,short *param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  longlong local_20;
  
  uVar3 = 0;
  local_24 = 0;
  lVar2 = ExAllocatePool2(0x40,0x208,0x74727056);
  if (lVar2 == 0) {
    return 0xc0000017;
  }
  *(undefined8 *)(param_3 + 4) = param_4;
  param_3[0] = 0;
  param_3[1] = 0x208;
  local_28 = 0x2080000;
  local_20 = lVar2;
  iVar1 = RtlIntegerToUnicodeString(param_2,10,&local_28);
  if (((iVar1 < 0) || (iVar1 = RtlAppendUnicodeToString(param_3,param_1), iVar1 < 0)) ||
     (iVar1 = RtlAppendUnicodeStringToString(param_3,&local_28), iVar1 < 0)) {
    uVar3 = 0xc000009a;
  }
  else {
    param_3[1] = *param_3 + 2;
  }
  ExFreePoolWithTag(lVar2,0x74727056);
  return uVar3;
}



===== pVideoPortDispatch @ 1c000d140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int pVideoPortDispatch(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  undefined2 uVar9;
  undefined8 *puVar10;
  int *piVar11;
  int *piVar12;
  undefined *puVar13;
  undefined8 local_68;
  int *piStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  
  piVar12 = *(int **)(param_1 + 0x40);
  local_48 = 0;
  local_68 = 0;
  piStack_60 = (int *)0x0;
  local_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uVar4 = *(undefined8 *)(piVar12 + 4);
  if (((piVar12 == (int *)0x0) || (*piVar12 != 0x74727056)) || (piVar12[1] != 0)) {
    piVar11 = *(int **)(piVar12 + 2);
  }
  else {
    piVar11 = piVar12;
    piVar12 = piVar12 + 0x76;
  }
  pcVar5 = *(char **)(param_2 + 0xb8);
  piVar1 = (int *)(param_2 + 0x30);
  iVar8 = IoAcquireRemoveLockEx(piVar11 + 0x1e,param_2,"",1,0x20);
  if (iVar8 < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *piVar1 = iVar8;
    IofCompleteRequest(param_2,1);
    return iVar8;
  }
  KeWaitForSingleObject(piVar11 + 0x10,0,0,0,0);
  *(undefined1 *)(piVar11 + 6) = *(undefined1 *)(param_2 + 0x40);
  cVar7 = *pcVar5;
  if (cVar7 != '\0') {
    if (cVar7 == '\x02') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      *piVar1 = 0;
      goto LAB_1c000d559;
    }
    if (cVar7 != '\x0e') {
      if (cVar7 != '\x10') {
        *piVar1 = 0;
      }
      goto LAB_1c000d559;
    }
    uVar2 = *(undefined4 *)(pcVar5 + 8);
    iVar8 = *(int *)(pcVar5 + 0x18);
    uVar3 = *(undefined4 *)(pcVar5 + 0x10);
    uVar6 = *(undefined8 *)(param_2 + 0x18);
    *piVar1 = 0;
    if (iVar8 == 0x230000) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      *piVar1 = -0x3fffff45;
LAB_1c000d390:
      if (*piVar1 < 0) goto LAB_1c000d559;
    }
    else {
      if (iVar8 == 0x230200) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar9 = 0x19;
LAB_1c000d355:
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                  &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
        }
LAB_1c000d35e:
        *piVar1 = -0x3fffff45;
        goto LAB_1c000d559;
      }
      if (iVar8 == 0x230460) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                  &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
        }
        cVar7 = SeSinglePrivilegeCheck(7,(char)piVar11[6]);
        if (cVar7 == '\0') {
          *piVar1 = -0x3fffff9f;
        }
        goto LAB_1c000d390;
      }
      if (iVar8 == 0x230480) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                  &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
          goto LAB_1c000d390;
        }
      }
      else if (iVar8 == 0x32c004) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar9 = 0x1c;
          goto LAB_1c000d355;
        }
        goto LAB_1c000d35e;
      }
    }
    puVar13 = &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
    puVar10 = &local_68;
    local_68 = CONCAT44(local_68._4_4_,iVar8);
    uStack_50 = CONCAT44(uStack_50._4_4_,uVar3);
    piStack_60 = piVar1;
    local_58 = uVar6;
    local_48 = uVar6;
    local_40 = uVar2;
    (**(code **)(piVar11 + 0x32))(uVar4);
    if (*piVar1 != 0) {
      if (*piVar1 != 0xea) {
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
      pVideoPortMapToNtStatus(piVar1,puVar10,puVar13);
      if (((iVar8 == 0x230000) &&
          (*piVar1 = 0, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
    }
    goto LAB_1c000d559;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
  }
  VpSystemInitialized = 1;
  if ((*(char *)(param_2 + 0x40) == '\x01') || ((pcVar5[2] & 1U) != 0)) {
    *piVar1 = -0x3fffffde;
    goto LAB_1c000d559;
  }
  if ((*(int *)(*(longlong *)(pcVar5 + 8) + 0x10) == 0x80) || ((char)piVar12[0xd] != '\0')) {
    *piVar1 = 0;
  }
  *(undefined8 *)(param_2 + 0x38) = 1;
  VpSetupType = 0;
  if ((char)piVar11[100] < '\0') {
    if ((piVar11[0x49] == 0) &&
       (cVar7 = (**(code **)(piVar11 + 0x30))(*(undefined8 *)(piVar11 + 4)), cVar7 == '\0')) {
      *piVar1 = -0x3ffffe7e;
      piVar11[0x49] = 2;
    }
    else {
      if (piVar11[0x49] == 2) goto LAB_1c000d540;
      piVar11[0x49] = 1;
      *piVar1 = 0;
    }
  }
  else {
LAB_1c000d540:
    *piVar1 = -0x3ffffe7e;
  }
  *(undefined1 *)(piVar12 + 0xd) = 1;
LAB_1c000d559:
  iVar8 = *piVar1;
  KeReleaseMutex(piVar11 + 0x10,0);
  puVar13 = (undefined *)0x20;
  IoReleaseRemoveLockEx(piVar11 + 0x1e,param_2);
  if (iVar8 == 0x103) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
    iVar8 = 0x103;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      puVar13 = &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
               &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids,param_2);
    }
    IofCompleteRequest(param_2,1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,puVar13,iVar8);
    }
  }
  return iVar8;
}



===== pVideoPortDispatchInternalIoctl @ 1c000d640 =====

int pVideoPortDispatchInternalIoctl(longlong param_1,longlong param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined2 uVar8;
  longlong lVar9;
  undefined8 uVar10;
  char *pcVar11;
  int *piVar12;
  int *piVar13;
  bool bVar14;
  
  iVar6 = -0x3fffff45;
  iVar5 = -0x3fffff45;
  uVar10 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
  }
  if (((*(char *)(param_2 + 0x40) != '\0') ||
      (piVar2 = *(int **)(param_1 + 0x40), piVar2 == (int *)0x0)) || (*piVar2 != 0x74727056))
  goto LAB_1c000dbbf;
  if (piVar2[1] == 0) {
    piVar12 = piVar2 + 0x76;
    piVar13 = piVar2;
  }
  else if ((piVar2[1] != 1) ||
          (piVar13 = *(int **)(piVar2 + 2), piVar12 = piVar2, piVar13 == (int *)0x0))
  goto LAB_1c000dbbf;
  pcVar11 = "";
  piVar2 = *(int **)(param_2 + 0x70);
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  piVar3 = *(int **)(*(longlong *)(param_2 + 0xb8) + 0x20);
  lVar9 = param_2;
  iVar5 = IoAcquireRemoveLockEx(piVar13 + 0x1e,param_2,"",1,0x20);
  if (iVar5 < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = iVar5;
    IofCompleteRequest(param_2,1);
    return iVar5;
  }
  iVar5 = iVar6;
  if ((uVar1 & 0x80002000) == 0) {
    if (uVar1 != 0x23200b) {
      if ((piVar12[0x17] != -1) && (iVar6 = PsGetCurrentProcessSessionId(), iVar6 != piVar12[0x17]))
      {
        if ((uVar1 & 0x7fff1ffc) < 0x23202c) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar4 = PsGetCurrentProcessSessionId();
            WPP_SF_LLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar9,pcVar11,uVar1,
                       (char)piVar12[0x17],uVar4);
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,pcVar11,uVar1);
        }
      }
      goto LAB_1c000d80e;
    }
  }
  else {
LAB_1c000d80e:
    if (uVar1 == 0x23200f) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      iVar5 = 0;
    }
    else if (uVar1 == 0x23201b) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        uVar8 = 0xe;
LAB_1c000d87f:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
    }
    else if (uVar1 == 0x23201f) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      bVar14 = Win32kCallout == 0;
      *(undefined8 *)(piVar12 + 10) = *(undefined8 *)piVar3;
      if (bVar14) {
        Win32kCallout = *(longlong *)(piVar3 + 2);
      }
      piVar3[4] = 0;
      piVar3[6] = 0;
      piVar3[7] = 0;
      uVar10 = 0x28;
      piVar3[8] = piVar12[0xe];
      iVar5 = 0;
    }
    else if (uVar1 == 0x232027) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        uVar8 = 0x11;
        goto LAB_1c000d87f;
      }
    }
    else {
      if (uVar1 == 0x23202b) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
        }
        if (*piVar3 == 0) {
          iVar5 = PsGetCurrentProcessSessionId();
          if (piVar12[0x17] != iVar5) goto LAB_1c000dac0;
          piVar12[0x17] = -1;
LAB_1c000daa0:
          iVar5 = 1;
        }
        else {
          if (piVar12[0x17] == -1) {
            iVar5 = PsGetCurrentProcessSessionId();
            piVar12[0x17] = iVar5;
            goto LAB_1c000daa0;
          }
LAB_1c000dac0:
          iVar5 = 0;
        }
        piVar3[1] = iVar5;
      }
      else {
        if (uVar1 != 0x23203b) {
          if (uVar1 != 0x23203f) {
            if (((uVar1 == 0x232403) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control))
               && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
              uVar8 = 0xf;
              goto LAB_1c000d87f;
            }
            goto LAB_1c000db99;
          }
          piVar13[0x6a] = *piVar3;
          piVar13[0x6b] = piVar3[1];
          piVar13[0x6c] = piVar3[2];
          piVar13[0x6d] = piVar3[3];
          piVar13[0x70] = piVar3[6];
          piVar13[0x74] = piVar3[10];
          if (*(longlong *)(piVar13 + 0x6e) != 0) {
            ExFreePoolWithTag(*(longlong *)(piVar13 + 0x6e),0x74727056);
            piVar13[0x6e] = 0;
            piVar13[0x6f] = 0;
          }
          if (*(longlong *)(piVar13 + 0x72) != 0) {
            ExFreePoolWithTag(*(longlong *)(piVar13 + 0x72),0x74727056);
            piVar13[0x72] = 0;
            piVar13[0x73] = 0;
          }
          if ((piVar3[6] == 0) || (*(longlong *)(piVar3 + 4) == 0)) {
LAB_1c000d990:
            if ((piVar3[10] != 0) && (*(longlong *)(piVar3 + 8) != 0)) {
              pvVar7 = (void *)ExAllocatePool2(0x100,piVar3[10],0x74727056);
              *(void **)(piVar13 + 0x72) = pvVar7;
              if (pvVar7 == (void *)0x0) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                  uVar8 = 0x14;
                  goto LAB_1c000d966;
                }
                goto LAB_1c000d976;
              }
              memcpy(pvVar7,*(void **)(piVar3 + 8),(ulonglong)(uint)piVar3[10]);
            }
            uVar10 = 0x30;
            iVar5 = 0;
          }
          else {
            pvVar7 = (void *)ExAllocatePool2(0x100,piVar3[6],0x74727056);
            *(void **)(piVar13 + 0x6e) = pvVar7;
            if (pvVar7 != (void *)0x0) {
              memcpy(pvVar7,*(void **)(piVar3 + 4),(ulonglong)(uint)piVar3[6]);
              goto LAB_1c000d990;
            }
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              uVar8 = 0x13;
LAB_1c000d966:
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                      &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
            }
LAB_1c000d976:
            iVar5 = -0x3fffff66;
          }
          goto LAB_1c000db99;
        }
        *piVar2 = piVar13[0x6a];
        piVar2[1] = piVar13[0x6b];
        piVar2[2] = piVar13[0x6c];
        piVar2[3] = piVar13[0x6d];
        *(undefined8 *)(piVar2 + 4) = *(undefined8 *)(piVar13 + 0x6e);
        piVar2[6] = piVar13[0x70];
        *(undefined8 *)(piVar2 + 8) = *(undefined8 *)(piVar13 + 0x72);
        piVar2[10] = piVar13[0x74];
      }
      uVar10 = 8;
      iVar5 = 0;
    }
  }
LAB_1c000db99:
  IoReleaseRemoveLockEx(piVar13 + 0x1e,param_2,0x20);
LAB_1c000dbbf:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids,param_2);
  }
  *(int *)(param_2 + 0x30) = iVar5;
  *(undefined8 *)(param_2 + 0x38) = uVar10;
  IofCompleteRequest(param_2,1);
  return iVar5;
}



===== pVideoPortGetDeviceDataRegistry @ 1c000dc30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint pVideoPortGetDeviceDataRegistry(undefined8 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong *in_stack_00000028;
  longlong *in_stack_00000040;
  longlong *in_stack_00000058;
  
  iVar3 = *(int *)((longlong)param_1 + 0x1c);
  if (iVar3 == 2) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
              &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
    }
    lVar1 = in_stack_00000028[2];
    lVar2 = *in_stack_00000028;
    lVar5 = (ulonglong)*(uint *)(in_stack_00000028[1] + 8) + in_stack_00000028[1];
    iVar3 = (*(code *)param_1[1])
                      (*param_1,param_1[2],*(undefined4 *)((longlong)param_1 + 0x1c),
                       (ulonglong)*(uint *)(lVar2 + 8) + lVar2,*(undefined4 *)(lVar2 + 0xc),
                       lVar5 + 0x24,*(undefined4 *)(lVar5 + 0x14),
                       (ulonglong)*(uint *)(lVar1 + 8) + lVar1,*(undefined4 *)(lVar1 + 0xc));
    uVar4 = -(uint)(iVar3 != 0) & 0xc00000c0;
  }
  else {
    if (iVar3 == 3) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
      in_stack_00000058 = in_stack_00000040;
    }
    else {
      if (iVar3 != 4) {
        return 0xc0000001;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
      }
    }
    lVar1 = in_stack_00000058[2];
    lVar2 = in_stack_00000058[1];
    lVar5 = *in_stack_00000058;
    iVar3 = (*(code *)param_1[1])
                      (*param_1,param_1[2],*(undefined4 *)((longlong)param_1 + 0x1c),
                       (ulonglong)*(uint *)(lVar5 + 8) + lVar5,*(undefined4 *)(lVar5 + 0xc),
                       (ulonglong)*(uint *)(lVar2 + 8) + lVar2,*(undefined4 *)(lVar2 + 0xc),
                       (ulonglong)*(uint *)(lVar1 + 8) + lVar1,*(undefined4 *)(lVar1 + 0xc));
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0xc00000c0;
    }
  }
  return uVar4;
}



===== pVideoPortGetRegistryCallback @ 1c000ddf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int pVideoPortGetRegistryCallback
              (undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 param_4,
              undefined8 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined2 uVar4;
  undefined1 auStack_108 [32];
  undefined8 local_e8;
  longlong local_e0;
  undefined4 local_d8;
  longlong *local_d0;
  undefined8 local_c8;
  longlong local_b8 [4];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_108;
  local_b8[0] = 0;
  local_b8[1] = 0;
  iVar1 = 0;
  lVar3 = 0;
  local_78 = 0;
  uStack_70 = uStack_70 & 0xffffffff00000000;
  local_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = (undefined8 *)0x0;
  uStack_80 = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (*(int *)((longlong)param_5 + 0x1c) != 1) {
LAB_1c000e01d:
    local_e8 = (longlong *)CONCAT44(local_e8._4_4_,param_4);
    uVar2 = (*(code *)param_5[1])(*param_5,param_5[2],param_1,param_3);
    *(undefined4 *)(param_5 + 3) = uVar2;
    goto LAB_1c000e03b;
  }
  RtlInitUnicodeString(&local_68,param_3);
  uStack_90 = 0;
  local_88 = &local_68;
  local_e0 = CONCAT44(local_e0._4_4_,0x10);
  local_e8 = (longlong *)((ulonglong)local_e8._4_4_ << 0x20);
  local_98 = CONCAT44(local_98._4_4_,0x30);
  uStack_80 = CONCAT44(uStack_80._4_4_,0x240);
  local_78 = 0;
  uStack_70 = 0;
  iVar1 = ZwOpenFile(local_b8,0x120089,&local_98,local_b8 + 2);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c000e03b;
    uVar4 = 0x2c;
  }
  else {
    local_e8 = (longlong *)CONCAT44(local_e8._4_4_,5);
    iVar1 = ZwQueryInformationFile(local_b8[0],local_b8 + 2,&local_58,0x18);
    if (-1 < iVar1) {
      if (uStack_50._4_4_ == 0) {
        param_4 = (undefined4)uStack_50;
        lVar3 = ExAllocatePool2(0x100,uStack_50 & 0xffffffff,0x74727056);
        if (lVar3 != 0) {
          local_c8 = 0;
          local_d0 = local_b8 + 1;
          local_d8 = param_4;
          local_e8 = local_b8 + 2;
          local_e0 = lVar3;
          iVar1 = ZwReadFile(local_b8[0],0,0,0);
          param_3 = lVar3;
          if (-1 < iVar1) goto LAB_1c000e01d;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c000e03b;
          uVar4 = 0x2f;
          goto LAB_1c000deea;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                  &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
        }
      }
      iVar1 = -0x3fffff66;
      goto LAB_1c000e03b;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c000e03b;
    uVar4 = 0x2d;
  }
LAB_1c000deea:
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
          &WPP_b019b9a88d2d3c807dc705800ac171dc_Traceguids);
LAB_1c000e03b:
  if (local_b8[0] != 0) {
    ZwClose();
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return iVar1;
}



===== pVideoPortMapToNtStatus @ 1c000e090 =====

void pVideoPortMapToNtStatus(int *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      *param_1 = -0x3ffffffe;
      return;
    }
    if (iVar1 == 8) {
      *param_1 = -0x3fffff66;
      return;
    }
    if (iVar1 == 0x37) {
      *param_1 = -0x3fffff40;
      return;
    }
    if (iVar1 == 0x57) {
      *param_1 = -0x3ffffff3;
      return;
    }
    if (iVar1 == 0x7a) {
      *param_1 = -0x3fffffdd;
      param_1[2] = 0;
      param_1[3] = 0;
      return;
    }
    if (iVar1 == 0xea) {
      *param_1 = -0x7ffffffb;
      return;
    }
    if (iVar1 != 0x3e5) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,param_3,iVar1);
      }
      *param_1 = -0x3fffffff;
      return;
    }
  }
  *param_1 = 0;
  return;
}



===== VideoPortAllocateCommonBuffer @ 1c000e150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortAllocateCommonBuffer(void)

{
                    /* 0xe150  6  VideoPortAllocateCommonBuffer */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x2d3;
  return 0;
}



===== VideoPortAllocateContiguousMemory @ 1c000e180 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortAllocateContiguousMemory(void)

{
                    /* 0xe180  7  VideoPortAllocateContiguousMemory */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x6f;
  return 0;
}



===== VideoPortAssociateEventsWithDmaHandle @ 1c000e1b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortAssociateEventsWithDmaHandle(void)

{
                    /* 0xe1b0  9  VideoPortAssociateEventsWithDmaHandle */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x7b;
  return 0;
}



===== VideoPortCheckForDeviceExistence @ 1c000e1e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortCheckForDeviceExistence(void)

{
                    /* 0xe1e0  11  VideoPortCheckForDeviceExistence */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x8a;
  return 0;
}



===== VideoPortCompleteDma @ 1c000e210 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortCompleteDma(void)

{
                    /* 0xe210  14  VideoPortCompleteDma */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x96;
  return 0x57;
}



===== VideoPortDDCMonitorHelper @ 1c000e240 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortDDCMonitorHelper(void)

{
                    /* 0xe240  18  VideoPortDDCMonitorHelper */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0xa2;
  return 0;
}



===== VideoPortDisableInterrupt @ 1c000e270 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortDisableInterrupt(void)

{
                    /* 0xe270  25  VideoPortDisableInterrupt */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0xab;
  return 0x57;
}



===== VideoPortDoDma @ 1c000e2a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortDoDma(void)

{
                    /* 0xe2a0  26  VideoPortDoDma */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0xb6;
  return 0;
}



===== VideoPortEnableInterrupt @ 1c000e2d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortEnableInterrupt(void)

{
                    /* 0xe2d0  27  VideoPortEnableInterrupt */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0xbf;
  return 0x57;
}



===== VideoPortEnumerateChildren @ 1c000e300 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortEnumerateChildren(void)

{
                    /* 0xe300  28  VideoPortEnumerateChildren */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 100;
  return 0x57;
}



===== VideoPortFreeCommonBuffer @ 1c000e330 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortFreeCommonBuffer(void)

{
                    /* 0xe330  30  VideoPortFreeCommonBuffer */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0xcc;
  return;
}



===== VideoPortFreeDeviceBase @ 1c000e360 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortFreeDeviceBase(void)

{
                    /* 0xe360  31  VideoPortFreeDeviceBase */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0xd6;
  return;
}



===== VideoPortGetAccessRanges @ 1c000e390 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetAccessRanges(void)

{
                    /* 0xe390  33  VideoPortGetAccessRanges */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0xe7;
  return 0x57;
}



===== VideoPortGetAgpServices @ 1c000e3c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortGetAgpServices(void)

{
                    /* 0xe3c0  34  VideoPortGetAgpServices */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0xf2;
  return 0;
}



===== VideoPortGetBusData @ 1c000e3f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetBusData(void)

{
                    /* 0xe3f0  37  VideoPortGetBusData */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x100;
  return 0;
}



===== VideoPortGetBytesUsed @ 1c000e420 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetBytesUsed(void)

{
                    /* 0xe420  38  VideoPortGetBytesUsed */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x10a;
  return 0;
}



===== VideoPortGetCommonBuffer @ 1c000e450 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetCommonBuffer(void)

{
                    /* 0xe450  39  VideoPortGetCommonBuffer */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x118;
  return 0;
}



===== VideoPortGetDeviceBase @ 1c000e480 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetDeviceBase(void)

{
                    /* 0xe480  41  VideoPortGetDeviceBase */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x124;
  return 0;
}



===== VideoPortGetDmaAdapter @ 1c000e4b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetDmaAdapter(void)

{
                    /* 0xe4b0  43  VideoPortGetDmaAdapter */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x12e;
  return 0;
}



===== VideoPortGetDmaContext @ 1c000e4e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetDmaContext(void)

{
                    /* 0xe4e0  44  VideoPortGetDmaContext */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x138;
  return 0;
}



===== VideoPortGetMdl @ 1c000e510 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetMdl(void)

{
                    /* 0xe510  45  VideoPortGetMdl */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x142;
  return 0;
}



===== VideoPortGetRomImage @ 1c000e540 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetRomImage(void)

{
                    /* 0xe540  47  VideoPortGetRomImage */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x14e;
  return 0;
}



===== VideoPortGetVgaStatus @ 1c000e570 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortGetVgaStatus(void)

{
                    /* 0xe570  49  VideoPortGetVgaStatus */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x158;
  return 0x57;
}



===== VideoPortInt10 @ 1c000e5a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortInt10(void)

{
                    /* 0xe5a0  51  VideoPortInt10 */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x162;
  return 0x57;
}



===== VideoPortIsNoVesa @ 1c000e5d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortIsNoVesa(void)

{
                    /* 0xe5d0  55  VideoPortIsNoVesa */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x16b;
  return 0;
}



===== VideoPortLockBuffer @ 1c000e600 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortLockBuffer(void)

{
                    /* 0xe600  56  VideoPortLockBuffer */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x177;
  return 0;
}



===== VideoPortLockPages @ 1c000e630 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortLockPages(void)

{
                    /* 0xe630  57  VideoPortLockPages */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x184;
  return 0;
}



===== VideoPortMapBankedMemory @ 1c000e660 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortMapBankedMemory(void)

{
                    /* 0xe660  59  VideoPortMapBankedMemory */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x1a5;
  return 0x57;
}



===== VideoPortMapDmaMemory @ 1c000e690 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortMapDmaMemory(void)

{
                    /* 0xe690  60  VideoPortMapDmaMemory */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x194;
  return 0;
}



===== VideoPortMapMemory @ 1c000e6c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortMapMemory(void)

{
                    /* 0xe6c0  61  VideoPortMapMemory */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x2ea;
  return 0x57;
}



===== VideoPortPutDmaAdapter @ 1c000e6f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortPutDmaAdapter(void)

{
                    /* 0xe6f0  64  VideoPortPutDmaAdapter */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x1af;
  return;
}



===== VideoPortReadPortBufferUchar @ 1c000e720 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortReadPortBufferUchar(void)

{
                    /* 0xe720  69  VideoPortReadPortBufferUchar */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x1ba;
  return;
}



===== VideoPortReadPortBufferUlong @ 1c000e750 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortReadPortBufferUlong(void)

{
                    /* 0xe750  70  VideoPortReadPortBufferUlong */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x1c5;
  return;
}



===== VideoPortReadPortBufferUshort @ 1c000e780 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortReadPortBufferUshort(void)

{
                    /* 0xe780  71  VideoPortReadPortBufferUshort */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x1d0;
  return;
}



===== VideoPortReadPortUchar @ 1c000e7b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortReadPortUchar(void)

{
                    /* 0xe7b0  72  VideoPortReadPortUchar */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x1d9;
  return 0;
}



===== VideoPortReadPortUlong @ 1c000e7e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortReadPortUlong(void)

{
                    /* 0xe7e0  73  VideoPortReadPortUlong */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x1e2;
  return 0;
}



===== VideoPortReadPortUshort @ 1c000e810 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortReadPortUshort(void)

{
                    /* 0xe810  74  VideoPortReadPortUshort */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x1eb;
  return 0;
}



===== VideoPortReleaseCommonBuffer @ 1c000e840 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortReleaseCommonBuffer(void)

{
                    /* 0xe840  84  VideoPortReleaseCommonBuffer */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x1f9;
  return;
}



===== VideoPortScanRom @ 1c000e870 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortScanRom(void)

{
                    /* 0xe870  88  VideoPortScanRom */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x205;
  return 0;
}



===== VideoPortSetBusData @ 1c000e8a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortSetBusData(void)

{
                    /* 0xe8a0  89  VideoPortSetBusData */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x213;
  return 0;
}



===== VideoPortSetBytesUsed @ 1c000e8d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortSetBytesUsed(void)

{
                    /* 0xe8d0  90  VideoPortSetBytesUsed */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x21e;
  return;
}



===== VideoPortSetDmaContext @ 1c000e900 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortSetDmaContext(void)

{
                    /* 0xe900  91  VideoPortSetDmaContext */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x229;
  return;
}



===== VideoPortSetTrappedEmulatorPorts @ 1c000e930 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortSetTrappedEmulatorPorts(void)

{
                    /* 0xe930  94  VideoPortSetTrappedEmulatorPorts */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x234;
  return 0x57;
}



===== VideoPortSignalDmaComplete @ 1c000e960 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortSignalDmaComplete(void)

{
                    /* 0xe960  95  VideoPortSignalDmaComplete */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x23e;
  return 0;
}



===== VideoPortStartDma @ 1c000e990 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortStartDma(void)

{
                    /* 0xe990  97  VideoPortStartDma */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x24e;
  return 0x57;
}



===== VideoPortSynchronizeExecution @ 1c000e9c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortSynchronizeExecution(void)

{
                    /* 0xe9c0  100  VideoPortSynchronizeExecution */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x25a;
  return 0;
}



===== VideoPortUnlockBuffer @ 1c000e9f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortUnlockBuffer(void)

{
                    /* 0xe9f0  101  VideoPortUnlockBuffer */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x2dd;
  return;
}



===== VideoPortUnlockPages @ 1c000ea20 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortUnlockPages(void)

{
                    /* 0xea20  102  VideoPortUnlockPages */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x264;
  return 0;
}



===== VideoPortUnmapDmaMemory @ 1c000ea50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 VideoPortUnmapDmaMemory(void)

{
                    /* 0xea50  103  VideoPortUnmapDmaMemory */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x270;
  return 0;
}



===== VideoPortUnmapMemory @ 1c000ea80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortUnmapMemory(void)

{
                    /* 0xea80  104  VideoPortUnmapMemory */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x27b;
  return 0x57;
}



===== VideoPortVerifyAccessRanges @ 1c000eab0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 VideoPortVerifyAccessRanges(void)

{
                    /* 0xeab0  105  VideoPortVerifyAccessRanges */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x286;
  return 0x57;
}



===== VideoPortWritePortBufferUchar @ 1c000eae0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortWritePortBufferUchar(void)

{
                    /* 0xeae0  107  VideoPortWritePortBufferUchar */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x291;
  return;
}



===== VideoPortWritePortBufferUlong @ 1c000eb10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortWritePortBufferUlong(void)

{
                    /* 0xeb10  108  VideoPortWritePortBufferUlong */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x29c;
  return;
}



===== VideoPortWritePortBufferUshort @ 1c000eb40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortWritePortBufferUshort(void)

{
                    /* 0xeb40  109  VideoPortWritePortBufferUshort */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x2a7;
  return;
}



===== VideoPortWritePortUchar @ 1c000eb70 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortWritePortUchar(void)

{
                    /* 0xeb70  110  VideoPortWritePortUchar */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x2b1;
  return;
}



===== VideoPortWritePortUlong @ 1c000eba0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortWritePortUlong(void)

{
                    /* 0xeba0  111  VideoPortWritePortUlong */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 699;
  return;
}



===== VideoPortWritePortUshort @ 1c000ebd0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void VideoPortWritePortUshort(void)

{
                    /* 0xebd0  112  VideoPortWritePortUshort */
  WdLogSingleEntry0(1);
  _WdLogGlobalForLineNumber = 0x2c5;
  return;
}



===== entry @ 1c0012010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c0012044 =====

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



===== DriverEntry @ 1c0012078 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== pVPInit @ 1c0012084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pVPInit(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined1 auStack_188 [32];
  undefined8 local_168;
  undefined4 local_158;
  int local_154;
  int local_150;
  int local_14c;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined1 local_138 [8];
  uint local_130;
  uint local_12c;
  undefined8 local_f8;
  undefined4 local_f0;
  wchar_t *local_e8;
  int *local_e0;
  undefined4 local_d8;
  undefined4 *local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  wchar_t *local_b0;
  int *local_a8;
  undefined4 local_a0;
  undefined4 *local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined4 local_80;
  wchar_t *local_78;
  int *local_70;
  undefined4 local_68;
  undefined4 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_188;
  memset(local_138,0,0x40);
  local_e8 = L"SystemSetupInProgress";
  local_f0 = 0x120;
  local_d8 = 0x4000004;
  uVar3 = 4;
  local_b8 = 0x120;
  local_e0 = &local_150;
  local_a0 = 0x4000004;
  local_d0 = &local_158;
  local_b0 = L"UpgradeInProgress";
  local_a8 = &local_154;
  local_98 = &local_158;
  local_78 = L"MiniSetupInProgress";
  local_70 = &local_14c;
  local_60 = &local_158;
  local_80 = 0x120;
  local_68 = 0x4000004;
  local_158 = 0;
  local_154 = 0;
  local_150 = 0;
  local_14c = 0;
  local_f8 = 0;
  local_c8 = 4;
  local_c0 = 0;
  local_90 = 4;
  local_88 = 0;
  local_58 = 4;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_148 = 0;
  uStack_140 = 0;
  RtlInitUnicodeString(&local_148,L"RtlQueryRegistryValuesEx");
  pcVar2 = (code *)MmGetSystemRoutineAddress(&local_148);
  local_168 = 0;
  if (pcVar2 == (code *)0x0) {
    pcVar2 = RtlQueryRegistryValues_exref;
  }
  (*pcVar2)(0,L"\\Registry\\Machine\\System\\Setup",&local_f8,0);
  if ((local_154 == 0) && ((local_150 == 0 || (uVar3 = 1, local_14c != 0)))) {
    uVar3 = 0;
  }
  DAT_1c00081a8 = &WPP_ThisDir_CTLGUID_VideoPrt;
  _WPP_MAIN_CB = 0;
  DAT_1c00081b0 = 0;
  _DAT_1c00081c0 = 0;
  _DAT_1c00081c8 = 1;
  VpSetupType = uVar3;
  VpSetupTypeAtBoot = uVar3;
  WppLoadTracingSupport();
  _DAT_1c00081c0 = 0;
  WppInitKm();
  VpSystemMemorySize = 0;
  iVar1 = ZwQuerySystemInformation(0,local_138,0x40);
  if (-1 < iVar1) {
    VpSystemMemorySize = (ulonglong)local_130 * (ulonglong)local_12c;
  }
  KeInitializeMutex(&VpGlobalLock,0);
  return;
}



===== ScsiPortNotification @ 1c0016000 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0xf4fa  1  ScsiPortNotification  (forwarder -> VIDEOPRT.VideoPortNotification) */

void ScsiPortNotification(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== VideoPortCheckForDeviceExistance @ 1c0016008 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0xf625  10  VideoPortCheckForDeviceExistance  (forwarder ->
   VIDEOPRT.VideoPortCheckForDeviceExistence) */

void VideoPortCheckForDeviceExistance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== VideoPortCompareMemory @ 1c0016010 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0xf69b  13  VideoPortCompareMemory  (forwarder -> NTOSKRNL.RtlCompareMemory) */

void VideoPortCompareMemory(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== VideoPortMoveMemory @ 1c0016018 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0xfb36  62  VideoPortMoveMemory  (forwarder -> NTOSKRNL.RtlMoveMemory) */

void VideoPortMoveMemory(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== VideoPortStallExecution @ 1c0016020 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0xfecf  96  VideoPortStallExecution  (forwarder -> HAL.KeStallExecutionProcessor) */

void VideoPortStallExecution(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



===== VideoPortZeroMemory @ 1c0016028 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0x10163  120  VideoPortZeroMemory  (forwarder -> NTOSKRNL.RtlZeroMemory) */

void VideoPortZeroMemory(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


