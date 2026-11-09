
===== __report_gsfailure @ 180001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 180001020 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 180001044 =====

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



===== __cpu_features_init @ 1800010c0 =====

/* WARNING: Removing unreachable block (ram,0x00018000112a) */
/* WARNING: Removing unreachable block (ram,0x0001800010d9) */
/* WARNING: Removing unreachable block (ram,0x0001800010ca) */

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



===== WPP_RECORDER_AND_TRACE_SF_ @ 180001188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_d @ 18000120c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_d
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,4,0);
  }
  return;
}



===== WppClassicProviderCallback @ 1800012c0 =====

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



===== wil_details_RecordCachedUsage @ 18000131c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
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
    bVar6 = uVar2 == uVar4;
    if (bVar6) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar6);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
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
  if (0 < (longlong)puVar5 - (longlong)&local_48 >> 3) {
    wil_details_RecordFeatureUsageCallback();
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 180001470 =====

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



===== ~_BtDeviceEntry @ 1800014f4 =====

/* public: __cdecl _BtDeviceEntry::~_BtDeviceEntry(void) __ptr64 */

void __thiscall _BtDeviceEntry::~_BtDeviceEntry(_BtDeviceEntry *this)

{
  _BtDeviceEntry *p_Var1;
  longlong *plVar2;
  longlong lVar3;
  
  while (p_Var1 = *(_BtDeviceEntry **)(this + 0x230), p_Var1 != this + 0x230) {
    plVar2 = *(longlong **)(p_Var1 + 8);
    lVar3 = *(longlong *)p_Var1;
    *plVar2 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar2;
    ExFreePoolWithTag(p_Var1,0x646d4370);
  }
  *(undefined8 *)(this + 0x240) = 0;
  wil::operation_guard::~operation_guard((operation_guard *)(this + 0x1d8));
  wil::operation_guard::~operation_guard((operation_guard *)(this + 0x158));
  wil::operation_guard::~operation_guard((operation_guard *)(this + 0xd8));
  wil::operation_guard::~operation_guard((operation_guard *)(this + 0x58));
  return;
}



===== ~operation_guard @ 180001578 =====

/* public: __cdecl wil::operation_guard::~operation_guard(void) __ptr64 */

void __thiscall wil::operation_guard::~operation_guard(operation_guard *this)

{
  operation_guard *poVar1;
  int iVar2;
  
  LOCK();
  *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
  UNLOCK();
  LOCK();
  poVar1 = this + 0x18;
  iVar2 = *(int *)poVar1;
  *(int *)poVar1 = *(int *)poVar1 + -1;
  UNLOCK();
  if (this[0x1c] == (operation_guard)0x0) {
    if (iVar2 == 1) {
      KeSetEvent(this,0,0);
    }
    this[0x1c] = (operation_guard)0x1;
    LOCK();
    poVar1 = this + 0x18;
    iVar2 = *(int *)poVar1;
    *(int *)poVar1 = *(int *)poVar1 + -1;
    UNLOCK();
    if (1 < iVar2) {
      KeWaitForSingleObject(this,0,0,0,0);
    }
  }
  else if (iVar2 == 1) {
    KeSetEvent(this,0,0);
  }
  return;
}



===== BtaMpmDelayedConnectionTimerCallback @ 180001610 =====

/* void __cdecl BtaMpmDelayedConnectionTimerCallback(struct _EX_TIMER * __ptr64,void * __ptr64) */

void __cdecl BtaMpmDelayedConnectionTimerCallback(_EX_TIMER *param_1,void *param_2)

{
  if (((*(char *)((longlong)param_2 + 0x28) != '\0') &&
      (*(longlong *)((longlong)param_2 + 0x88) == 0)) &&
     (*(char *)((longlong)param_2 + 0x91) == '\0')) {
    EnqueueWorkItem(0,(Profile *)((longlong)param_2 + 0x28),0);
  }
  if (((*(Profile *)((longlong)param_2 + 0xa8) != (Profile)0x0) &&
      (*(longlong *)((longlong)param_2 + 0x108) == 0)) &&
     (*(char *)((longlong)param_2 + 0x111) == '\0')) {
    EnqueueWorkItem(0,(Profile *)((longlong)param_2 + 0xa8),0);
  }
  if (((*(Profile *)((longlong)param_2 + 0x128) != (Profile)0x0) &&
      (*(longlong *)((longlong)param_2 + 0x188) == 0)) &&
     (*(char *)((longlong)param_2 + 0x191) == '\0')) {
    EnqueueWorkItem(0,(Profile *)((longlong)param_2 + 0x128),0);
  }
  if (((*(Profile *)((longlong)param_2 + 0x1a8) != (Profile)0x0) &&
      (*(longlong *)((longlong)param_2 + 0x208) == 0)) &&
     (*(char *)((longlong)param_2 + 0x211) == '\0')) {
    EnqueueWorkItem(0,(Profile *)((longlong)param_2 + 0x1a8),0);
  }
  return;
}



===== BtaMpmSetDelayedConnectionRequestTimer @ 1800016d8 =====

/* void __cdecl BtaMpmSetDelayedConnectionRequestTimer(class _BtDeviceEntry * __ptr64) */

void __cdecl BtaMpmSetDelayedConnectionRequestTimer(_BtDeviceEntry *param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong local_res8;
  
  local_res8 = 0;
  lVar2 = 70000000;
  iVar1 = SystemPrng(&local_res8,8);
  if (iVar1 != 0) {
    lVar2 = local_res8 % 70000000 + 70000000;
  }
  ExSetTimer(*(undefined8 *)(param_1 + 0x18),-lVar2,0,0);
  return;
}



===== BuildIndirectString @ 18000175c =====

/* long __cdecl BuildIndirectString(int,unsigned short const * __ptr64,unsigned short const *
   __ptr64,unsigned short * __ptr64,unsigned __int64,unsigned long,unsigned short * __ptr64 *
   __ptr64,unsigned __int64 * __ptr64) */

long __cdecl
BuildIndirectString(int param_1,ushort *param_2,ushort *param_3,ushort *param_4,__uint64 param_5,
                   ulong param_6,ushort **param_7,__uint64 *param_8)

{
  ulonglong uVar1;
  ushort *puVar2;
  uint uVar3;
  wchar_t *pwVar4;
  ushort *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  wchar_t *pwVar9;
  
  pwVar9 = L"";
  if (param_3 != (ushort *)0x0) {
    pwVar9 = (wchar_t *)param_3;
  }
  if (param_2 == (ushort *)0x0) {
    return -0x3ffffff3;
  }
  lVar8 = 0x7fffffff;
  puVar5 = param_2;
  do {
    if (*puVar5 == 0) break;
    puVar5 = puVar5 + 1;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  if (lVar8 == 0) {
    return -0x3ffffff3;
  }
  if (pwVar9 != (wchar_t *)0x0) {
    lVar6 = 0x7fffffff;
    pwVar4 = pwVar9;
    do {
      if (*pwVar4 == L'\0') break;
      pwVar4 = pwVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    if (lVar6 == 0) {
      return -0x3ffffff3;
    }
    uVar7 = param_5 >> 1;
    if ((param_4 != (ushort *)0x0) && (uVar1 = uVar7, puVar5 = param_4, uVar7 < 0x80000000)) {
      for (; (uVar1 != 0 && (*puVar5 != 0)); puVar5 = puVar5 + 1) {
        uVar1 = uVar1 - 1;
      }
      if (uVar1 == 0) {
        return -0x3ffffff3;
      }
      uVar7 = (-(ulonglong)(lVar8 != 0) & (0x7fffffff - lVar8) * 2) +
              (-(ulonglong)(lVar6 != 0) & (0x7fffffff - lVar6) * 2) + ((uVar7 - uVar1) + 0x10) * 2;
      puVar5 = (ushort *)ExAllocatePool2(0x40,uVar7,param_6);
      if (puVar5 == (ushort *)0x0) {
        return -0x3fffff66;
      }
      uVar3 = RtlStringCbPrintfW(puVar5,uVar7,(ushort *)L"%s,#%d;%s;(%s)",param_2,param_1,pwVar9,
                                 param_4);
      if ((int)uVar3 < 0) {
LAB_180001951:
        ExFreePoolWithTag(puVar5,param_6);
        return uVar3;
      }
      uVar7 = uVar7 >> 1;
      lVar8 = 0;
      uVar1 = uVar7;
      puVar2 = puVar5;
      if (uVar7 < 0x80000000) {
        for (; (uVar1 != 0 && (*puVar2 != 0)); puVar2 = puVar2 + 1) {
          uVar1 = uVar1 - 1;
        }
        uVar3 = ~-(uint)(uVar1 != 0) & 0xc000000d;
        if (uVar1 == 0) {
          lVar8 = 0;
        }
        else {
          lVar8 = uVar7 - uVar1;
        }
      }
      else {
        uVar3 = 0xc000000d;
      }
      if (param_8 == (__uint64 *)0x0) {
        if ((int)uVar3 < 0) goto LAB_180001951;
      }
      else {
        if ((int)uVar3 < 0) {
          *param_8 = 0;
          goto LAB_180001951;
        }
        *param_8 = lVar8 * 2;
      }
      *param_7 = puVar5;
      return 0;
    }
  }
  return -0x3ffffff3;
}



===== EnqueueWorkItem @ 1800019b0 =====

/* long __cdecl EnqueueWorkItem(enum BTAMPM_WORK_TYPE,class Profile * __ptr64,unsigned __int64) */

long __cdecl EnqueueWorkItem(BTAMPM_WORK_TYPE param_1,Profile *param_2,__uint64 param_3)

{
  code *pcVar1;
  undefined1 uVar2;
  long lVar3;
  undefined8 *puVar4;
  _BtMpmData *p_Var5;
  char cVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [56];
  BTAMPM_WORK_TYPE local_18;
  undefined4 local_10;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    local_10 = *(undefined4 *)(param_2 + 0x50);
    local_18 = param_1;
    WPP_RECORDER_AND_TRACE_SF_LL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x28,0x504d5442);
  if (puVar4 == (undefined8 *)0x0) {
    lVar3 = -0x3fffff66;
  }
  else {
    p_Var5 = g_ManagerData + 0x20;
    *(BTAMPM_WORK_TYPE *)(puVar4 + 2) = param_1;
    puVar4[4] = param_2;
    puVar4[3] = param_3;
    uVar2 = KeAcquireSpinLockRaiseToDpc(p_Var5);
    puVar8 = auStack_58;
    plVar7 = *(longlong **)(g_ManagerData + 0x30);
    p_Var5 = g_ManagerData + 0x28;
    if ((_BtMpmData *)*plVar7 != p_Var5) {
      p_Var5 = (_BtMpmData *)0x3;
      pcVar1 = (code *)swi(0x29);
      uVar2 = (*pcVar1)();
      puVar8 = auStack_50;
    }
    *puVar4 = p_Var5;
    puVar4[1] = plVar7;
    *plVar7 = (longlong)puVar4;
    *(undefined8 **)(p_Var5 + 8) = puVar4;
    *(undefined8 *)(puVar8 + -8) = 0x180001ab0;
    KeReleaseSpinLock(g_ManagerData + 0x20,uVar2);
    *(undefined8 *)(puVar8 + -8) = 0x180001acc;
    KeSetEvent(g_ManagerData + 0x38,0,0);
    lVar3 = 0;
  }
  return lVar3;
}



===== FreePoolWithTag @ 180001af0 =====

/* public: static void __cdecl wil::details::pool_helpers<struct _WorkListItem *
   __ptr64,1347245122>::FreePoolWithTag(struct _WorkListItem * __ptr64) */

void __cdecl
wil::details::pool_helpers<_WorkListItem*___ptr64,1347245122>::FreePoolWithTag
          (_WorkListItem *param_1)

{
  if (param_1 != (_WorkListItem *)0x0) {
    ExFreePoolWithTag(param_1,0x504d5442);
  }
  return;
}



===== IsBasebandConnectedToDevice @ 180001b18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* bool __cdecl IsBasebandConnectedToDevice(unsigned __int64) */

bool __cdecl IsBasebandConnectedToDevice(__uint64 param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  char cVar4;
  undefined1 auStackY_3f8 [32];
  undefined1 in_stack_fffffffffffffc38;
  undefined8 local_3a8;
  undefined8 local_3a0;
  _DEVICE_OBJECT *local_398 [2];
  undefined8 local_388;
  undefined8 uStack_380;
  undefined4 local_378;
  undefined4 local_374;
  __uint64 local_370;
  undefined4 local_368;
  undefined1 local_364 [4];
  uint local_360;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_3f8;
  local_3a8 = 0;
  iVar2 = IoGetDeviceInterfaces(&GUID_BTHPORT_DEVICE_INTERFACE,0,0,&local_3a8);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x31,
                 &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,(char)iVar2);
    }
  }
  else {
    local_388 = 0;
    uStack_380 = 0;
    RtlInitUnicodeString(&local_388,local_3a8);
    local_3a0 = 0;
    local_398[0] = (_DEVICE_OBJECT *)0x0;
    iVar2 = IoGetDeviceObjectPointer(&local_388,0x1f01ff,&local_3a0,local_398);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x32,
                   &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,(char)iVar2);
      }
    }
    else {
      memset(local_364,0,0x344);
      bVar1 = true;
      local_374 = 3;
      local_368 = 1;
      local_378 = 1;
      local_370 = param_1;
      lVar3 = SynchronousIo(local_398[0],0x411058,&local_378,0x358,&local_378,0x358,
                            (bool)in_stack_fffffffffffffc38);
      if (-1 < lVar3) {
        ObfDereferenceObject(local_3a0);
        ExFreePool(local_3a8);
        return (local_360 & 0x20) != 0;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar1 = false;
      }
      if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x33,
                   &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,(char)lVar3);
      }
      ObfDereferenceObject(local_3a0);
    }
    ExFreePool(local_3a8);
  }
  return false;
}



===== PnpNotificationHandler @ 180001e10 =====

/* long __cdecl PnpNotificationHandler(void * __ptr64,void * __ptr64) */

long __cdecl PnpNotificationHandler(void *param_1,void *param_2)

{
  _BtDeviceEntry *p_Var1;
  long lVar2;
  char cVar3;
  
  if (((g_ManagerData == (_BtMpmData *)0x0) || (param_1 == (void *)0x0)) || (param_2 == (void *)0x0)
     ) {
    lVar2 = -0x3ffffff3;
  }
  else {
    if (((*(longlong *)((longlong)param_1 + 4) == 0x49be1541fc240062) &&
        (*(longlong *)((longlong)param_1 + 0xc) == 0x7fbfd7dcc48463b4)) &&
       (*(short *)((longlong)param_1 + 2) == 0x37)) {
      cVar3 = '\x01';
      p_Var1 = *(_BtDeviceEntry **)(*(longlong *)param_2 + 0x58);
      if ((*(char *)((longlong)param_1 + 0x2c) == '\x01') &&
         (*(longlong *)((longlong)param_1 + 0x24) == *(longlong *)(p_Var1 + 0x20))) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0 ||
            ((byte)WPP_GLOBAL_Control[0x29] < 4)))) {
          cVar3 = '\0';
        }
        if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_il
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        if (*(char *)((longlong)param_1 + 0x2d) == '\0') {
          ExCancelTimer(*(undefined8 *)(p_Var1 + 0x18),0);
        }
        else {
          BtaMpmSetDelayedConnectionRequestTimer(p_Var1);
        }
      }
    }
    lVar2 = 0;
  }
  return lVar2;
}



===== ProcessWorkItems @ 180001f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000180002169) */
/* WARNING: Removing unreachable block (ram,0x000180002175) */
/* void __cdecl ProcessWorkItems(void * __ptr64) */

void __cdecl ProcessWorkItems(void *param_1)

{
  int *piVar1;
  _WorkListItem *p_Var2;
  undefined8 uVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  int iVar8;
  ulonglong uVar9;
  code *pcVar10;
  _BtMpmData *p_Var11;
  longlong lVar12;
  char cVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  longlong lVar16;
  _WorkListItem *p_Var17;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  
  bVar5 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar13 = '\0';
  }
  else {
    cVar13 = '\x01';
  }
  if ((cVar13 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x2d,
               &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
  }
  puVar14 = auStackY_68;
  if (g_ManagerData != (_BtMpmData *)0x0) {
    KeAcquireSpinLockRaiseToDpc(g_ManagerData + 0x20);
    puVar15 = auStackY_68;
    puVar14 = auStackY_68;
    iVar8 = *(int *)(g_ManagerData + 0x50);
    while (iVar8 != 0) {
      KeReleaseSpinLock(g_ManagerData + 0x20);
      iVar8 = KeWaitForSingleObject(g_ManagerData + 0x38,0,0,0);
      if (-1 < iVar8) {
        uVar6 = KeAcquireSpinLockRaiseToDpc(g_ManagerData + 0x20);
        if (*(int *)(g_ManagerData + 0x50) == 0) {
LAB_180002489:
          *(undefined8 *)(puVar15 + -8) = 0x18000249d;
          KeReleaseSpinLock(g_ManagerData + 0x20,uVar6);
          puVar14 = puVar15;
          goto LAB_18000240e;
        }
        while (*(_BtMpmData **)(g_ManagerData + 0x28) != g_ManagerData + 0x28) {
          p_Var11 = g_ManagerData + 0x28;
          p_Var2 = *(_WorkListItem **)p_Var11;
          if ((*(_BtMpmData **)(p_Var2 + 8) != p_Var11) ||
             (lVar16 = *(longlong *)p_Var2, *(_WorkListItem **)(lVar16 + 8) != p_Var2)) {
            pcVar10 = (code *)swi(0x29);
            uVar6 = (*pcVar10)(3);
            puVar15 = auStackY_60;
            goto LAB_180002489;
          }
          *(longlong *)p_Var11 = lVar16;
          *(_BtMpmData **)(lVar16 + 8) = p_Var11;
          uVar9 = Feature_3736307001__private_IsEnabledDeviceUsageNoInline();
          p_Var17 = (_WorkListItem *)0x0;
          if ((int)uVar9 != 0) {
            p_Var17 = p_Var2;
          }
          if (*(longlong *)(p_Var2 + 0x20) == 0) {
LAB_18000237a:
            uVar9 = Feature_3736307001__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar9 == 0) {
              ExFreePoolWithTag(p_Var2);
            }
          }
          else {
            uVar7 = 0;
            lVar16 = 0;
            uVar9 = Feature_3736307001__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar9 == 0) {
LAB_18000219f:
              iVar8 = *(int *)(p_Var2 + 0x10);
              if ((iVar8 == 0) || (iVar8 == 1)) {
                if (*(longlong *)(*(longlong *)(p_Var2 + 0x20) + 0x10) != 0) {
                  KeReleaseSpinLock(g_ManagerData + 0x20);
                  lVar12 = *(longlong *)(p_Var2 + 0x20);
                  pcVar10 = *(code **)(lVar12 + 0x10);
                  goto LAB_1800022b3;
                }
              }
              else if ((iVar8 == 2) || (iVar8 == 3)) {
                if (*(longlong *)(*(longlong *)(p_Var2 + 0x20) + 0x18) != 0) {
                  KeReleaseSpinLock(g_ManagerData + 0x20,uVar6);
                  lVar12 = *(longlong *)(p_Var2 + 0x20);
                  pcVar10 = *(code **)(lVar12 + 0x18);
                  goto LAB_1800022b3;
                }
              }
              else if ((iVar8 == 4) || (iVar8 == 5)) {
                if (*(longlong *)(*(longlong *)(p_Var2 + 0x20) + 0x20) != 0) {
                  KeReleaseSpinLock(g_ManagerData + 0x20,uVar6);
                  lVar12 = *(longlong *)(p_Var2 + 0x20);
                  pcVar10 = *(code **)(lVar12 + 0x20);
                  goto LAB_1800022b3;
                }
              }
              else if ((iVar8 == 6) && (*(longlong *)(*(longlong *)(p_Var2 + 0x20) + 0x28) != 0)) {
                KeReleaseSpinLock(g_ManagerData + 0x20,uVar6);
                lVar12 = *(longlong *)(p_Var2 + 0x20);
                pcVar10 = *(code **)(lVar12 + 0x28);
LAB_1800022b3:
                uVar7 = (*pcVar10)(*(undefined8 *)(lVar12 + 8));
                uVar6 = KeAcquireSpinLockRaiseToDpc(g_ManagerData + 0x20);
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
                cVar13 = '\0';
              }
              else {
                cVar13 = '\x01';
              }
              if ((cVar13 != '\0') ||
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_AND_TRACE_SF_Ld
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,
                           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                           *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x2f,
                           &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,
                           (char)*(undefined4 *)(p_Var2 + 0x10),uVar7);
              }
              if (lVar16 != 0) {
                LOCK();
                piVar1 = (int *)(lVar16 + 0x18);
                iVar8 = *piVar1;
                *piVar1 = *piVar1 + -1;
                UNLOCK();
                if (iVar8 == 1) {
                  KeSetEvent(lVar16);
                }
              }
              goto LAB_18000237a;
            }
            lVar12 = *(longlong *)(p_Var2 + 0x20);
            lVar16 = lVar12 + 0x30;
            LOCK();
            *(int *)(lVar12 + 0x48) = *(int *)(lVar12 + 0x48) + 1;
            UNLOCK();
            if (*(char *)(lVar12 + 0x4c) == '\0') {
              if (lVar16 != 0) goto LAB_18000219f;
            }
            else {
              LOCK();
              piVar1 = (int *)(lVar12 + 0x48);
              iVar8 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar8 == 1) {
                KeSetEvent(lVar16,0,0);
              }
            }
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
              cVar13 = '\0';
            }
            else {
              cVar13 = '\x01';
            }
            if ((cVar13 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_qL
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
          }
          if (p_Var17 != (_WorkListItem *)0x0) {
            wil::details::pool_helpers<_WorkListItem*___ptr64,1347245122>::FreePoolWithTag(p_Var17);
          }
        }
        KeReleaseSpinLock(g_ManagerData + 0x20,uVar6);
      }
      KeAcquireSpinLockRaiseToDpc(g_ManagerData + 0x20);
      iVar8 = *(int *)(g_ManagerData + 0x50);
    }
    KeReleaseSpinLock(g_ManagerData + 0x20);
  }
LAB_18000240e:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    bVar5 = false;
  }
  if ((bVar5) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined **)(puVar14 + 0x38) = &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids;
    *(undefined2 *)(puVar14 + 0x30) = 0x30;
    *(undefined4 *)(puVar14 + 0x28) = 3;
    puVar14[0x20] = 4;
    *(undefined8 *)(puVar14 + -8) = 0x180002466;
    WPP_RECORDER_AND_TRACE_SF_
              (uVar4,bVar5,(undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,uVar3
               ,puVar14[0x20],*(undefined4 *)(puVar14 + 0x28),*(undefined2 *)(puVar14 + 0x30),
               *(undefined8 *)(puVar14 + 0x38));
  }
  return;
}



===== RtlStringCbPrintfW @ 1800024c4 =====

/* long __cdecl RtlStringCbPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCbPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  int iVar1;
  ulonglong uVar2;
  long lVar3;
  undefined8 in_R9;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    lVar3 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf((wchar_t *)param_1,uVar2,(wchar_t *)param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      lVar3 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = 0;
  }
  else {
    lVar3 = -0x3ffffff3;
    if (uVar2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar3;
}



===== SynchronousIo @ 180002540 =====

/* long __cdecl SynchronousIo(struct _DEVICE_OBJECT * __ptr64,unsigned long,void * __ptr64,unsigned
   long,void * __ptr64,unsigned long,bool) */

long __cdecl
SynchronousIo(_DEVICE_OBJECT *param_1,ulong param_2,void *param_3,ulong param_4,void *param_5,
             ulong param_6,bool param_7)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,0,0);
  local_38 = 0;
  uStack_30 = 0;
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_2,param_1,param_3,param_4,param_5,param_6,0,&local_28,&local_38);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(param_1,lVar2);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar1 = (int)local_38;
    }
  }
  return iVar1;
}



===== BtaMpmBuildIndirectStringFromMessageWithSingleUTF8Arg @ 180002640 =====

int BtaMpmBuildIndirectStringFromMessageWithSingleUTF8Arg
              (longlong param_1,int param_2,ushort *param_3,undefined8 param_4,uint param_5,
              ulong param_6,ushort **param_7,__uint64 *param_8)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar6;
  longlong local_38 [2];
  
  uVar2 = param_6;
  uVar1 = param_5;
                    /* 0x2640  1  BtaMpmBuildIndirectStringFromMessageWithSingleUTF8Arg */
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  puVar5 = (ushort *)0x0;
  param_5 = param_5 * 2 + 2;
  puVar4 = (ushort *)ExAllocatePool2(0x40,param_5,param_6);
  if (puVar4 == (ushort *)0x0) {
    return -0x3fffff66;
  }
  iVar3 = RtlUTF8ToUnicodeN(puVar4,param_5,&param_5,param_4,CONCAT44(uVar6,uVar1));
  if (-1 < iVar3) {
    if (param_1 != 0) {
      local_38[0] = 0;
      iVar3 = RtlFindMessage(param_1,0xb,0,param_2,local_38);
      if (iVar3 < 0) goto LAB_18000274d;
      puVar5 = (ushort *)(local_38[0] + 4);
    }
    iVar3 = BuildIndirectString(param_2,param_3,puVar5,puVar4,(ulonglong)param_5,uVar2,param_7,
                                param_8);
  }
LAB_18000274d:
  ExFreePoolWithTag(puVar4,uVar2);
  return iVar3;
}



===== BtaMpmConnectionRequest @ 180002790 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long BtaMpmConnectionRequest(undefined8 *param_1,int param_2,int param_3)

{
  _BtDeviceEntry *p_Var1;
  int iVar2;
  _BtDeviceEntry *p_Var3;
  _BtDeviceEntry *this;
  undefined8 *puVar4;
  bool bVar5;
  undefined1 uVar6;
  long lVar7;
  undefined8 *puVar8;
  BTAMPM_WORK_TYPE BVar9;
  char cVar10;
  char cVar11;
  _BtDeviceEntry *p_Var12;
  _BtDeviceEntry *p_Var13;
  undefined1 in_stack_ffffffffffffff78;
  undefined7 in_stack_ffffffffffffff79;
  undefined4 in_stack_ffffffffffffff80;
  undefined4 in_stack_ffffffffffffff84;
  undefined8 in_stack_ffffffffffffff90;
  
                    /* 0x2790  2  BtaMpmConnectionRequest */
  p_Var3 = (_BtDeviceEntry *)*param_1;
  lVar7 = 0;
  this = *(_BtDeviceEntry **)(p_Var3 + 0x58);
  cVar11 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
     (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar10 = '\0';
  }
  if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_iLll
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),
               CONCAT44(in_stack_ffffffffffffff84,in_stack_ffffffffffffff80),0x1b,
               in_stack_ffffffffffffff90,(char)*(undefined8 *)(this + 0x20),
               (char)*(undefined4 *)(p_Var3 + 0x50),(char)param_2,(char)param_3);
  }
  bVar5 = false;
  if (((param_2 != 0) && (param_3 != 0)) &&
     ((this[0x90] == (_BtDeviceEntry)0x0 &&
      (((this[0x110] == (_BtDeviceEntry)0x0 && (this[400] == (_BtDeviceEntry)0x0)) &&
       (this[0x210] == (_BtDeviceEntry)0x0)))))) {
    if ((((this[0x28] == (_BtDeviceEntry)0x0) || (*(longlong *)(this + 0x88) == 0)) &&
        ((this[0xa8] == (_BtDeviceEntry)0x0 || (*(longlong *)(this + 0x108) == 0)))) &&
       (((this[0x128] == (_BtDeviceEntry)0x0 || (*(longlong *)(this + 0x188) == 0)) &&
        ((this[0x1a8] == (_BtDeviceEntry)0x0 || (*(longlong *)(this + 0x208) == 0)))))) {
      bVar5 = _BtDeviceEntry::IsBasebandConnected(this);
      if (!bVar5) {
        if ((*(longlong *)(this + 0x228) != 0) &&
           (bVar5 = false,
           (ulonglong)(_DAT_fffff78000000008 - *(longlong *)(this + 0x228)) < 0x5f5e101))
        goto LAB_180002908;
      }
    }
    bVar5 = true;
  }
LAB_180002908:
  uVar6 = KeAcquireSpinLockRaiseToDpc(g_ManagerData);
  iVar2 = *(int *)(p_Var3 + 0x50);
  p_Var1 = this + 0xa8;
  p_Var13 = this + 0x128;
  p_Var12 = this + 0x1a8;
  if (param_2 == 0) {
    if (iVar2 - 1U < 3) {
      if ((*p_Var12 == (_BtDeviceEntry)0x0) || (*(longlong *)(this + 0x208) == 0)) {
        if ((*p_Var13 == (_BtDeviceEntry)0x0) || (*(longlong *)(this + 0x188) == 0)) {
          if ((*p_Var1 == (_BtDeviceEntry)0x0) || (*(longlong *)(this + 0x108) == 0))
          goto LAB_180002f7d;
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 ||
              (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
            cVar11 = '\0';
          }
          if ((cVar11 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x24,
                       &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
          }
          BVar9 = 1;
          goto LAB_180002f6c;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar11 = '\0';
        }
        if ((cVar11 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x23,
                     &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
        }
        this[0x191] = (_BtDeviceEntry)0x1;
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar11 = '\0';
        }
        if ((cVar11 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x22,
                     &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
        }
        this[0x211] = (_BtDeviceEntry)0x1;
        p_Var13 = p_Var12;
      }
    }
    else {
      if (((iVar2 != 0) || (*p_Var3 == (_BtDeviceEntry)0x0)) || (*(longlong *)(p_Var3 + 0x60) == 0))
      goto LAB_180002f7d;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
         (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar11 = '\0';
      }
      if ((cVar11 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x25,
                   &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
      }
      p_Var3[0x69] = (_BtDeviceEntry)0x1;
      p_Var13 = p_Var3;
    }
    BVar9 = 1;
  }
  else {
    if (param_3 != 0) {
      if ((((this[0x90] != (_BtDeviceEntry)0x0) || (this[0x110] != (_BtDeviceEntry)0x0)) ||
          (this[400] != (_BtDeviceEntry)0x0)) || (this[0x210] != (_BtDeviceEntry)0x0)) {
        puVar8 = (undefined8 *)ExAllocatePool2(0x40,0x18,0x646d4370);
        if (puVar8 == (undefined8 *)0x0) {
          lVar7 = -0x3fffff66;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar11 = '\0';
          }
          if ((cVar11 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_L
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,
                       CONCAT44(in_stack_ffffffffffffff84,in_stack_ffffffffffffff80),0x1c,
                       in_stack_ffffffffffffff90,(char)iVar2);
          }
        }
        else {
          puVar8[2] = p_Var3;
          puVar4 = *(undefined8 **)(this + 0x238);
          puVar8[1] = puVar4;
          *puVar8 = this + 0x230;
          *puVar4 = puVar8;
          *(undefined8 **)(this + 0x238) = puVar8;
          *(longlong *)(this + 0x240) = *(longlong *)(this + 0x240) + 1;
        }
        goto LAB_180002f7d;
      }
      if (!bVar5) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar11 = '\0';
        }
        if ((cVar11 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_L
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,
                     CONCAT44(in_stack_ffffffffffffff84,in_stack_ffffffffffffff80),0x1d,
                     in_stack_ffffffffffffff90,(char)iVar2);
        }
        lVar7 = -0x3fffff5d;
        goto LAB_180002f7d;
      }
    }
    if (iVar2 - 1U < 3) {
      if ((*p_Var1 != (_BtDeviceEntry)0x0) && (*(longlong *)(this + 0x108) == 0)) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar11 = '\0';
        }
        if ((cVar11 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1e,
                     &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
        }
        BVar9 = 0;
        this[0x110] = (_BtDeviceEntry)(param_3 != 0);
LAB_180002f6c:
        this[0x111] = (_BtDeviceEntry)0x1;
        p_Var13 = p_Var1;
        goto LAB_180002f73;
      }
      if ((*p_Var13 == (_BtDeviceEntry)0x0) || (*(longlong *)(this + 0x188) != 0)) {
        if ((*p_Var12 == (_BtDeviceEntry)0x0) || (*(longlong *)(this + 0x208) != 0))
        goto LAB_180002f7d;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 ||
            (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
          cVar11 = '\0';
        }
        if ((cVar11 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x20,
                     &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
        }
        this[0x211] = (_BtDeviceEntry)0x1;
        this[0x210] = (_BtDeviceEntry)(param_3 != 0);
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar11 = '\0';
        }
        if ((cVar11 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1f,
                     &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
        }
        this[0x191] = (_BtDeviceEntry)0x1;
        this[400] = (_BtDeviceEntry)(param_3 != 0);
        p_Var12 = p_Var13;
      }
    }
    else {
      if (((iVar2 != 0) || (*p_Var3 == (_BtDeviceEntry)0x0)) || (*(longlong *)(p_Var3 + 0x60) != 0))
      goto LAB_180002f7d;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
         (cVar11 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar11 = '\0';
      }
      if ((cVar11 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x21,
                   &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
      }
      p_Var3[0x69] = (_BtDeviceEntry)0x1;
      p_Var3[0x68] = (_BtDeviceEntry)(param_3 != 0);
      p_Var12 = p_Var3;
    }
    BVar9 = 0;
    p_Var13 = p_Var12;
  }
LAB_180002f73:
  lVar7 = EnqueueWorkItem(BVar9,(Profile *)p_Var13,0);
LAB_180002f7d:
  KeReleaseSpinLock(g_ManagerData,uVar6);
  return lVar7;
}



===== BtaMpmGetStatus @ 180002fc0 =====

undefined8 BtaMpmGetStatus(longlong *param_1,uint *param_2,uint *param_3)

{
  ulonglong uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  char cVar7;
  bool bVar8;
  
                    /* 0x2fc0  4  BtaMpmGetStatus */
  if ((param_1 == (longlong *)0x0) || (g_ManagerData == (_BtMpmData *)0x0)) {
    uVar5 = 0xc000000d;
  }
  else {
    if (param_2 != (uint *)0x0) {
      *param_2 = 0;
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = 0;
    }
    uVar2 = KeAcquireSpinLockRaiseToDpc(g_ManagerData);
    uVar1 = *(ulonglong *)(*param_1 + 0x58);
    uVar6 = uVar1;
    if (param_2 != (uint *)0x0) {
      bVar8 = *(char *)(uVar1 + 0x28) != '\0';
      uVar6 = (ulonglong)(bVar8 | 2);
      if (*(char *)(uVar1 + 0xa8) == '\0') {
        uVar6 = (ulonglong)bVar8;
      }
      uVar4 = (uint)uVar6 | 4;
      if (*(char *)(uVar1 + 0x128) == '\0') {
        uVar4 = (uint)uVar6;
      }
      uVar3 = uVar4 | 8;
      if (*(char *)(uVar1 + 0x1a8) == '\0') {
        uVar3 = uVar4;
      }
      *param_2 = uVar3;
    }
    cVar7 = '\x01';
    if (param_3 != (uint *)0x0) {
      uVar4 = 0;
      if (((*(char *)(uVar1 + 0x28) != '\0') && (*(longlong *)(uVar1 + 0x88) != 0)) &&
         (uVar4 = 1, *(char *)(uVar1 + 0x29) != '\0')) {
        uVar4 = 0x11;
      }
      uVar3 = uVar4;
      if (((*(char *)(uVar1 + 0xa8) != '\0') && (*(longlong *)(uVar1 + 0x108) != 0)) &&
         (uVar3 = uVar4 | 2, *(char *)(uVar1 + 0xa9) != '\0')) {
        uVar3 = uVar4 | 0x22;
      }
      uVar4 = uVar3;
      if (((*(char *)(uVar1 + 0x128) != '\0') && (*(longlong *)(uVar1 + 0x188) != 0)) &&
         (uVar4 = uVar3 | 4, *(char *)(uVar1 + 0x129) != '\0')) {
        uVar4 = uVar3 | 0x44;
      }
      uVar3 = uVar4;
      if (((*(char *)(uVar1 + 0x1a8) != '\0') && (*(longlong *)(uVar1 + 0x208) != 0)) &&
         (uVar3 = uVar4 | 8, *(char *)(uVar1 + 0x1a9) != '\0')) {
        uVar3 = uVar4 | 0x88;
      }
      *param_3 = uVar3;
    }
    KeReleaseSpinLock(g_ManagerData,CONCAT71((int7)(uVar6 >> 8),uVar2));
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar7 = '\0';
    }
    if ((cVar7 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xf,
                 &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== BtaMpmRegister @ 1800031a0 =====

long BtaMpmRegister(longlong param_1,BTAMPM_PROFILE param_2,longlong param_3,longlong param_4,
                   undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  _BtDeviceEntry *p_Var1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  long lVar7;
  undefined8 *puVar8;
  Profile *pPVar9;
  _BtDeviceEntry *this;
  longlong lVar10;
  _BtMpmData *p_Var11;
  _BtMpmData *this_00;
  undefined1 *puVar12;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffa0;
  
                    /* 0x31a0  5  BtaMpmRegister */
  bVar5 = false;
  if (((param_3 == 0) || (param_4 == 0)) || (param_8 == (undefined8 *)0x0)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      bVar5 = true;
    }
    if ((bVar5 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_iL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffff90,10,
                 in_stack_ffffffffffffffa0,(char)param_1,(char)param_2);
    }
    return -0x3ffffff3;
  }
  *param_8 = 0;
  if ((g_ManagerData == (_BtMpmData *)0x0) && (lVar7 = InitializeManagerData(), lVar7 < 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      bVar5 = true;
    }
    if ((bVar5) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_iLd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    return lVar7;
  }
  puVar8 = (undefined8 *)ExAllocatePool2(0x40,8,0x504d5442);
  if (puVar8 == (undefined8 *)0x0) {
    return -0x3fffff66;
  }
  *puVar8 = 0;
  uVar6 = KeAcquireSpinLockRaiseToDpc(g_ManagerData);
  p_Var11 = *(_BtMpmData **)(g_ManagerData + 8);
  if (p_Var11 != g_ManagerData + 8) {
    do {
      this_00 = p_Var11;
      if (*(longlong *)(p_Var11 + 0x20) == param_1) break;
      this_00 = (_BtMpmData *)0x0;
      p_Var11 = *(_BtMpmData **)p_Var11;
    } while (p_Var11 != g_ManagerData + 8);
    if (this_00 != (_BtMpmData *)0x0) {
      pPVar9 = _BtDeviceEntry::GetProfile((_BtDeviceEntry *)this_00,param_2);
      puVar12 = auStackY_98;
      if (*pPVar9 == (Profile)0x0) {
        *puVar8 = pPVar9;
        *pPVar9 = (Profile)0x1;
        *(undefined8 *)(pPVar9 + 8) = param_7;
        *(undefined8 *)(pPVar9 + 0x20) = param_5;
        *(undefined8 *)(pPVar9 + 0x28) = param_6;
        *(longlong *)(pPVar9 + 0x10) = param_3;
        *(longlong *)(pPVar9 + 0x18) = param_4;
        goto LAB_180003540;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        bVar5 = true;
      }
      if ((bVar5 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_iL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffff90,0xc,
                   in_stack_ffffffffffffffa0,(char)param_1,(char)param_2);
      }
      lVar7 = -0x3ffff8e8;
      goto LAB_1800034eb;
    }
  }
  this = (_BtDeviceEntry *)ExAllocatePool2(0x40,0x250,0x646d4370);
  if (this != (_BtDeviceEntry *)0x0) {
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined8 *)(this + 0x18) = 0;
    *(longlong *)(this + 0x20) = param_1;
    Profile::Profile((Profile *)(this + 0x28),0,this);
    Profile::Profile((Profile *)(this + 0xa8),1,this);
    Profile::Profile((Profile *)(this + 0x128),2,this);
    Profile::Profile((Profile *)(this + 0x1a8),3,this);
    *(undefined8 *)(this + 0x228) = 0;
    p_Var1 = this + 0x230;
    *(undefined8 *)(this + 0x240) = 0;
    *(undefined8 *)(this + 0x248) = 0;
    *(_BtDeviceEntry **)p_Var1 = p_Var1;
    *(_BtDeviceEntry **)(this + 0x238) = p_Var1;
    pPVar9 = _BtDeviceEntry::GetProfile(this,param_2);
    *puVar8 = pPVar9;
    *(undefined8 *)(pPVar9 + 8) = param_7;
    *(longlong *)(pPVar9 + 0x10) = param_3;
    *(undefined8 *)(pPVar9 + 0x20) = param_5;
    *(undefined8 *)(pPVar9 + 0x28) = param_6;
    *pPVar9 = (Profile)0x1;
    *(longlong *)(pPVar9 + 0x18) = param_4;
    lVar10 = ExAllocateTimer(BtaMpmDelayedConnectionTimerCallback,this,0);
    puVar12 = auStackY_98;
    *(longlong *)(this + 0x18) = lVar10;
    if (lVar10 != 0) {
      p_Var11 = g_ManagerData + 8;
      lVar10 = *(longlong *)p_Var11;
      if (*(_BtMpmData **)(lVar10 + 8) != p_Var11) {
        pcVar4 = (code *)swi(0x29);
        p_Var11 = (_BtMpmData *)(*pcVar4)(3);
        puVar12 = auStackY_90;
      }
      *(longlong *)this = lVar10;
      *(_BtMpmData **)(this + 8) = p_Var11;
      *(_BtDeviceEntry **)(lVar10 + 8) = this;
      *(_BtDeviceEntry **)p_Var11 = this;
LAB_180003540:
      bVar5 = true;
      *param_8 = puVar8;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        bVar5 = false;
      }
      if ((bVar5) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(BTAMPM_PROFILE *)(puVar12 + 0x48) = param_2;
        *(longlong *)(puVar12 + 0x40) = param_1;
        *(undefined2 *)(puVar12 + 0x30) = 0xd;
        puVar12[0x20] = 4;
        *(undefined8 *)(puVar12 + -8) = 0x1800035aa;
        WPP_RECORDER_AND_TRACE_SF_iL
                  (uVar3,bVar5,(undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   uVar2,puVar12[0x20],*(undefined8 *)(puVar12 + 0x28),
                   *(undefined2 *)(puVar12 + 0x30),*(undefined8 *)(puVar12 + 0x38),puVar12[0x40],
                   puVar12[0x48]);
      }
      *(undefined8 *)(puVar12 + -8) = 0x1800035bb;
      KeReleaseSpinLock(g_ManagerData,uVar6);
      return 0;
    }
    _BtDeviceEntry::~_BtDeviceEntry(this);
    ExFreePoolWithTag(this,0x646d4370);
  }
  lVar7 = -0x3fffff66;
LAB_1800034eb:
  KeReleaseSpinLock(g_ManagerData,uVar6);
  ExFreePool(puVar8);
  return lVar7;
}



===== BtaMpmSuspendRequest @ 180003660 =====

long BtaMpmSuspendRequest(longlong *param_1,int param_2,int param_3)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  long lVar4;
  char cVar5;
  undefined1 in_stack_ffffffffffffffa8;
  undefined7 in_stack_ffffffffffffffa9;
  undefined4 in_stack_ffffffffffffffb0;
  undefined4 in_stack_ffffffffffffffb4;
  undefined8 in_stack_ffffffffffffffc0;
  
                    /* 0x3660  7  BtaMpmSuspendRequest */
  lVar4 = 0;
  lVar1 = *(longlong *)(*param_1 + 0x58);
  bVar2 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_iLll
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT71(in_stack_ffffffffffffffa9,in_stack_ffffffffffffffa8),
               CONCAT44(in_stack_ffffffffffffffb4,in_stack_ffffffffffffffb0),0x26,
               in_stack_ffffffffffffffc0,(char)*(undefined8 *)(lVar1 + 0x20),
               (char)*(undefined4 *)(*param_1 + 0x50),(char)param_2,(char)param_3);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(g_ManagerData);
  if (param_2 != 1) {
    if (param_2 == 2) {
      if (*(char *)(lVar1 + 0xa8) != '\0') {
        if (*(longlong *)(lVar1 + 0x108) == 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            bVar2 = false;
          }
          if ((bVar2 != false) ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x29,
                       &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
          }
        }
        else if (param_3 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            bVar2 = false;
          }
          if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x28,
                       &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
          }
          lVar4 = EnqueueWorkItem(3,(Profile *)(lVar1 + 0xa8),0);
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar5 = '\0';
          }
          else {
            cVar5 = '\x01';
          }
          if ((cVar5 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x27,
                       &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
          }
          lVar4 = EnqueueWorkItem(2,(Profile *)(lVar1 + 0xa8),0);
          if (-1 < lVar4) {
            *(undefined1 *)(lVar1 + 0xaa) = 1;
            lVar4 = 0x103;
          }
        }
      }
      goto LAB_1800038f4;
    }
    if ((param_2 != 4) && (param_2 != 8)) {
      lVar4 = -0x3ffffff3;
      goto LAB_1800038f4;
    }
  }
  lVar4 = -0x3fffff45;
LAB_1800038f4:
  KeReleaseSpinLock(g_ManagerData,uVar3);
  return lVar4;
}



===== BtaMpmUnregister @ 180003930 =====

undefined8 BtaMpmUnregister(_BtMpmData *param_1)

{
  Profile *pPVar1;
  int iVar2;
  BTAMPM_PROFILE BVar3;
  Profile *this;
  _BtDeviceEntry *this_00;
  _BtMpmData *p_Var4;
  longlong *plVar5;
  longlong lVar6;
  code *pcVar7;
  bool bVar8;
  undefined1 uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  char cVar12;
  _BtMpmData *p_Var13;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 in_stack_ffffffffffffffc0;
  
                    /* 0x3930  8  BtaMpmUnregister */
  this = *(Profile **)param_1;
  this_00 = *(_BtDeviceEntry **)(this + 0x58);
  bVar8 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     (cVar12 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar12 = '\0';
  }
  if ((cVar12 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_iL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar12,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffffb0,0x2a,
               in_stack_ffffffffffffffc0,(char)*(undefined8 *)(this_00 + 0x20),
               (char)*(undefined4 *)(this + 0x50));
  }
  uVar10 = Feature_3736307001__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar10 != 0) {
    this[0x4c] = (Profile)0x1;
    LOCK();
    pPVar1 = this + 0x48;
    iVar2 = *(int *)pPVar1;
    *(int *)pPVar1 = *(int *)pPVar1 + -1;
    UNLOCK();
    if (1 < iVar2) {
      KeWaitForSingleObject(this + 0x30,0,0,0,0);
    }
  }
  uVar9 = KeAcquireSpinLockRaiseToDpc(g_ManagerData);
  KeAcquireSpinLockAtDpcLevel(g_ManagerData + 0x20);
  if ((*(_BtMpmData **)(g_ManagerData + 0x28) != g_ManagerData + 0x28) &&
     (p_Var13 = *(_BtMpmData **)(g_ManagerData + 0x28),
     *(_BtMpmData **)(g_ManagerData + 0x28) != g_ManagerData + 0x28)) {
    do {
      p_Var4 = *(_BtMpmData **)p_Var13;
      if (this == *(Profile **)(p_Var13 + 0x20)) {
        if ((*(_BtMpmData **)(p_Var4 + 8) != p_Var13) ||
           (plVar5 = *(longlong **)(p_Var13 + 8), (_BtMpmData *)*plVar5 != p_Var13))
        goto LAB_180003cff;
        *plVar5 = (longlong)p_Var4;
        *(longlong **)(p_Var4 + 8) = plVar5;
        uVar10 = Feature_3736307001__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar10 != 0) {
          ExFreePoolWithTag(p_Var13,0x504d5442);
        }
      }
      p_Var13 = p_Var4;
    } while (p_Var4 != g_ManagerData + 0x28);
  }
  uVar10 = Feature_3736307001__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar10 == 0) {
    KeReleaseSpinLockFromDpcLevel(g_ManagerData + 0x20);
  }
  BVar3 = *(BTAMPM_PROFILE *)(this + 0x50);
  wil::operation_guard::~operation_guard((operation_guard *)(this + 0x30));
  Profile::Profile(this,BVar3,this_00);
  uVar10 = Feature_3736307001__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar10 != 0) {
    KeReleaseSpinLockFromDpcLevel(g_ManagerData + 0x20);
  }
  if ((((this_00[0x28] == (_BtDeviceEntry)0x0) && (this_00[0xa8] == (_BtDeviceEntry)0x0)) &&
      (this_00[0x128] == (_BtDeviceEntry)0x0)) && (this_00[0x1a8] == (_BtDeviceEntry)0x0)) {
    lVar6 = *(longlong *)this_00;
    if ((*(_BtDeviceEntry **)(lVar6 + 8) != this_00) ||
       (plVar5 = *(longlong **)(this_00 + 8), (_BtDeviceEntry *)*plVar5 != this_00)) {
LAB_180003cff:
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)(3);
      pcVar7 = (code *)swi(3);
      uVar11 = (*pcVar7)();
      return uVar11;
    }
    *plVar5 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar5;
    ExDeleteTimer(*(undefined8 *)(this_00 + 0x18),1,1,0);
    *(undefined8 *)(this_00 + 0x18) = 0;
    if (*(_BtMpmData **)(g_ManagerData + 8) == g_ManagerData + 8) {
      _BtDeviceEntry::~_BtDeviceEntry(this_00);
      ExFreePoolWithTag(this_00,0x646d4370);
      ExFreePoolWithTag(param_1,0x504d5442);
      KeAcquireSpinLockAtDpcLevel(g_ManagerData + 0x20);
      if ((*(int *)(g_ManagerData + 0x50) == 0) || (*(longlong *)(g_ManagerData + 0x18) == 0)) {
        bVar8 = false;
      }
      *(undefined4 *)(g_ManagerData + 0x50) = 0;
      KeSetEvent(g_ManagerData + 0x38,0,0);
      KeReleaseSpinLockFromDpcLevel(g_ManagerData + 0x20);
      KeReleaseSpinLock(g_ManagerData,uVar9);
      if (bVar8) {
        KeWaitForSingleObject(*(undefined8 *)(g_ManagerData + 0x18),0,0,0,0);
        ObfDereferenceObject(*(undefined8 *)(g_ManagerData + 0x18));
        *(undefined8 *)(g_ManagerData + 0x18) = 0;
      }
      param_1 = g_ManagerData;
      g_ManagerData = (_BtMpmData *)0x0;
      goto LAB_180003ccd;
    }
    _BtDeviceEntry::~_BtDeviceEntry(this_00);
    ExFreePoolWithTag(this_00,0x646d4370);
  }
  KeReleaseSpinLock(g_ManagerData,uVar9);
LAB_180003ccd:
  ExFreePoolWithTag(param_1,0x504d5442);
  return 0;
}



===== BtaMpmUnregisterPnp @ 180003d10 =====

long BtaMpmUnregisterPnp(longlong *param_1)

{
  long lVar1;
  
                    /* 0x3d10  9  BtaMpmUnregisterPnp */
  if ((param_1 == (longlong *)0x0) || (*(char *)(*param_1 + 0x78) == '\0')) {
    lVar1 = -0x3ffffe7c;
  }
  else {
    lVar1 = _BtDeviceEntry::UnregisterForPnpNotifications(*(_BtDeviceEntry **)(*param_1 + 0x58));
  }
  return lVar1;
}



===== BtaMpmUpdateConnectionStatus @ 180003d40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long BtaMpmUpdateConnectionStatus(longlong *param_1,int param_2,int param_3)

{
  longlong lVar1;
  _BtDeviceEntry *this;
  _BtDeviceEntry *p_Var2;
  longlong *plVar3;
  longlong lVar4;
  bool bVar5;
  undefined1 uVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  char cVar10;
  Profile *pPVar11;
  undefined1 in_stack_ffffffffffffff98;
  undefined7 in_stack_ffffffffffffff99;
  undefined4 in_stack_ffffffffffffffa0;
  undefined4 in_stack_ffffffffffffffa4;
  undefined8 in_stack_ffffffffffffffb0;
  
                    /* 0x3d40  10  BtaMpmUpdateConnectionStatus */
  lVar1 = *param_1;
  lVar8 = 0;
  this = *(_BtDeviceEntry **)(lVar1 + 0x58);
  bVar5 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar10 = '\0';
  }
  else {
    cVar10 = '\x01';
  }
  if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_iLll
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT71(in_stack_ffffffffffffff99,in_stack_ffffffffffffff98),
               CONCAT44(in_stack_ffffffffffffffa4,in_stack_ffffffffffffffa0),0x10,
               in_stack_ffffffffffffffb0,(char)*(undefined8 *)(this + 0x20),
               (char)*(undefined4 *)(lVar1 + 0x50),(char)param_2,(char)param_3);
  }
  pPVar11 = (Profile *)(this + 0x1a8);
  uVar6 = KeAcquireSpinLockRaiseToDpc(g_ManagerData);
  if (param_2 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = _DAT_fffff78000000008;
  }
  *(undefined8 *)(lVar1 + 0x60) = uVar9;
  if (*(char *)(lVar1 + 0x68) != '\0') {
    if (param_2 == 0) {
      *(undefined8 *)(lVar1 + 0x70) = _DAT_fffff78000000008;
    }
    else {
      *(undefined8 *)(lVar1 + 0x70) = 0;
    }
  }
  if ((param_3 == 0) || (*(char *)(lVar1 + 0x69) == '\0')) goto LAB_18000420d;
  if (*(char *)(lVar1 + 0x68) != '\0') {
    if (param_2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
         (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar10 = '\0';
      }
      if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x12,
                   &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
      }
      *(undefined8 *)(this + 0x228) = *(undefined8 *)(lVar1 + 0x70);
      while (p_Var2 = *(_BtDeviceEntry **)(this + 0x230), p_Var2 != this + 0x230) {
        plVar3 = *(longlong **)(p_Var2 + 8);
        lVar4 = *(longlong *)p_Var2;
        *plVar3 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar3;
        ExFreePoolWithTag(p_Var2,0x646d4370);
      }
      *(undefined8 *)(this + 0x240) = 0;
    }
    else {
      lVar7 = _BtDeviceEntry::InitiatePendedAutoConnectRequests(this);
      if (lVar7 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
           (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar10 = '\0';
        }
        if ((cVar10 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x11,
                     &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
        }
      }
    }
  }
  *(undefined2 *)(lVar1 + 0x68) = 0;
  if (*(int *)(lVar1 + 0x50) == 1) {
    if (param_2 != 0) {
      if ((this[0x128] == (_BtDeviceEntry)0x0) || (*(longlong *)(this + 0x188) != 0))
      goto LAB_18000420d;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 4)))
         ) {
        bVar5 = false;
      }
      if ((bVar5) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x13,
                   &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
      }
      pPVar11 = (Profile *)(this + 0x128);
LAB_1800040da:
      lVar8 = EnqueueWorkItem(0,pPVar11,0);
      goto LAB_18000420d;
    }
  }
  else if (*(int *)(lVar1 + 0x50) == 2) {
    if (param_2 != 0) {
      if ((*pPVar11 == (Profile)0x0) || (*(longlong *)(this + 0x208) != 0)) goto LAB_18000420d;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 4)))
         ) {
        bVar5 = false;
      }
      if ((bVar5 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x14,
                   &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
      }
      goto LAB_1800040da;
    }
    if ((*(Profile *)(this + 0xa8) != (Profile)0x0) && (*(longlong *)(this + 0x108) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 ||
          (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
        cVar10 = '\0';
      }
      if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x15,
                   &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
      }
      lVar8 = EnqueueWorkItem(1,(Profile *)(this + 0xa8),0);
    }
    if ((*pPVar11 != (Profile)0x0) && (*(longlong *)(this + 0x208) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 ||
          (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
        cVar10 = '\0';
      }
      if ((cVar10 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x16,
                   &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
      }
      lVar8 = EnqueueWorkItem(1,pPVar11,0);
    }
  }
  else if (param_2 != 0) goto LAB_18000420d;
  ExCancelTimer(*(undefined8 *)(this + 0x18),0);
LAB_18000420d:
  KeReleaseSpinLock(g_ManagerData,uVar6);
  return lVar8;
}



===== BtaMpmUpdatePlayStatus @ 180004250 =====

long BtaMpmUpdatePlayStatus(longlong *param_1,int param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  long lVar3;
  char cVar4;
  char cVar5;
  
                    /* 0x4250  11  BtaMpmUpdatePlayStatus */
  lVar3 = 0;
  lVar1 = *(longlong *)(*param_1 + 0x58);
  cVar5 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_iLl
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(g_ManagerData);
  if (*(int *)(lVar1 + 0x10) != param_2) {
    *(int *)(lVar1 + 0x10) = param_2;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar5 = '\0';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x1a,
                 &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
    }
    lVar3 = EnqueueWorkItem(6,(Profile *)(lVar1 + 0x128),(longlong)param_2);
  }
  KeReleaseSpinLock(g_ManagerData,uVar2);
  return lVar3;
}



===== BtaMpmUpdateSuspendStatus @ 1800043c0 =====

long BtaMpmUpdateSuspendStatus(longlong *param_1,int param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  long lVar5;
  char cVar6;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 in_stack_ffffffffffffffc0;
  
                    /* 0x43c0  12  BtaMpmUpdateSuspendStatus */
  if (param_1 == (longlong *)0x0) {
    lVar5 = -0x3ffffff3;
  }
  else {
    lVar1 = *param_1;
    bVar3 = true;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_iLll
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffa8,
                 in_stack_ffffffffffffffb0,0x17,in_stack_ffffffffffffffc0,
                 (char)*(undefined8 *)(*(longlong *)(lVar1 + 0x58) + 0x20),
                 (char)*(undefined4 *)(lVar1 + 0x50),(char)param_2,(char)param_3);
    }
    lVar5 = 0;
    uVar4 = KeAcquireSpinLockRaiseToDpc(g_ManagerData);
    *(bool *)(lVar1 + 1) = param_2 == 0;
    if (((param_3 != 0) && (*(int *)(lVar1 + 0x50) == 1)) && (*(char *)(lVar1 + 2) != '\0')) {
      lVar2 = *(longlong *)(lVar1 + 0x58);
      if ((*(char *)(lVar2 + 0x28) != '\0') && (*(longlong *)(lVar2 + 0x88) != 0)) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 4)
            ))) {
          bVar3 = false;
        }
        if ((bVar3) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_s
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar3,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        lVar5 = EnqueueWorkItem(5 - (param_2 != 0),(Profile *)(lVar2 + 0x28),0);
      }
      if (param_2 == 0) {
        *(undefined1 *)(lVar1 + 2) = 0;
      }
    }
    KeReleaseSpinLock(g_ManagerData,uVar4);
  }
  return lVar5;
}



===== Feature_3736307001__private_IsEnabledDeviceUsageNoInline @ 180004580 =====

ulonglong Feature_3736307001__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_3736307001__private_featureState;
  if ((Feature_3736307001__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3736307001__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3736307001__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3736307001__private_IsEnabledFallback @ 1800045b8 =====

void Feature_3736307001__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_L @ 1800045d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_L
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,param_7,&param_9,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,3,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,param_7,
                    &param_9,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_LL @ 180004680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_LL(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0x2c,
               &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,3,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0x2c,
                    &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_Ld @ 18000474c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_Ld
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,4,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_iL @ 180004828 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_iL
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,param_7,&param_9,8,
               &param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,2,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,param_7,
                    &param_9,8,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_iLd @ 180004904 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_iLd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0xb,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,2,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0xb,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_iLl @ 1800049f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_iLl(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0x19,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,6,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0x19,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_iLll @ 180004aec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_iLll
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,param_7,&param_9,8,
               &param_10,4,&param_11,4,&param_12,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,4,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,param_7,&param_9,8,
                    &param_10,4,&param_11,4,&param_12,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_il @ 180004bfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_il(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0xe,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,7,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0xe,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qL @ 180004cd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qL(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0x2e,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,3,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0x2e,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_s @ 180004da4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_s(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *in_stack_00000048;
  
  if (param_2 != '\0') {
    if (in_stack_00000048 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000048[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000048;
    if (in_stack_00000048 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0x18,pcVar3,lVar2,0);
  }
  if (param_3 != '\0') {
    lVar2 = -1;
    if (in_stack_00000048 == (char *)0x0) {
      lVar1 = 5;
    }
    else {
      do {
        lVar1 = lVar2;
        lVar2 = lVar1 + 1;
      } while (in_stack_00000048[lVar2] != '\0');
      lVar1 = lVar1 + 2;
    }
    if (in_stack_00000048 == (char *)0x0) {
      in_stack_00000048 = "NULL";
    }
    WppAutoLogTrace(param_4,4,4,&WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids,0x18,
                    in_stack_00000048,lVar1,0);
  }
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 180004eb0 =====

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
LAB_1800050b3:
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar5 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar5 = uVar3 | uVar5 & 0xffffbfff;
      }
      uVar6 = uVar5 >> 5 & 0x1ff;
      uVar3 = uVar6 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 5 ^ uVar5) & 0x3fe0;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_180004f8b:
        uVar5 = 0;
        if (param_3 == 2) {
          uVar5 = 2;
        }
        else if (param_3 == 3) {
          uVar5 = 8;
        }
        else if (param_3 == 6) {
          uVar5 = 4;
        }
        else if (param_3 == 7) {
          uVar5 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar5 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar6 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar6 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar6;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar6 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_1800050b3;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar5 = param_3 - 0x140;
          if ((int)uVar5 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar5)) {
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
                param_2[1] = (uVar5 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
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
        goto LAB_180004f8b;
      }
    }
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar5 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar5 = uVar3 | uVar5 & 0xffbfffff;
      }
      uVar6 = uVar5 >> 0xf & 0x7f;
      uVar3 = uVar6 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 0xf ^ uVar5) & 0x3f8000;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 18000519c =====

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
      goto LAB_18000525f;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_18000525f;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_18000525f;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_18000525f;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_18000525f;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_18000525f;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_18000525f;
    }
  }
  uVar2 = 0xff;
LAB_18000525f:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3bdf229,&Feature_3736307001_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1800052b8 =====

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
                     (local_50,&Feature_3736307001__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3bdf229,param_3,1,&Feature_3736307001__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3bdf229);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1800053a4 =====

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
LAB_180005457:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_180005485;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_180005457;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_180005485:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 180005610 =====

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
  if ((Feature_3736307001__private_featureState & 2) != 0) {
    uVar1 = Feature_3736307001__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3736307001__private_featureState;
      if (bVar3) {
        Feature_3736307001__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3736307001__private_featureState;
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



===== wil_details_IsEnabledFallback @ 180005664 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_3736307001__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_3736307001__private_featureState,(ulonglong)param_1,
                             0x180009cc8);
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



===== ~lambda_call<<lambda_726011562b617b6c31188a53cec19341>_> @ 1800056f4 =====

void wil::details::lambda_call<<lambda_726011562b617b6c31188a53cec19341>_>::
     ~lambda_call<<lambda_726011562b617b6c31188a53cec19341>_>(longlong *param_1)

{
  long lVar1;
  char cVar2;
  longlong local_res8 [4];
  bool in_stack_ffffffffffffffd8;
  
  if ((char)param_1[2] != '\0') {
    *(undefined1 *)(param_1 + 2) = 0;
    local_res8[0] = *(longlong *)(*param_1 + 0xc);
    if (local_res8[0] != 0) {
      lVar1 = SynchronousIo(*(_DEVICE_OBJECT **)param_1[1],0x410204,local_res8,8,local_res8,8,
                            in_stack_ffffffffffffffd8);
      if (lVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar2 = '\0';
        }
        else {
          cVar2 = '\x01';
        }
        if ((cVar2 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xb,
                     &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids,(char)lVar1);
        }
      }
    }
  }
  return;
}



===== BtaMpmGetRemoteDeviceProfileVersionAndAttribute @ 1800057d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long BtaMpmGetRemoteDeviceProfileVersionAndAttribute
               (_DEVICE_OBJECT *param_1,undefined8 *param_2,_SDP_NODE *param_3,_GUID *param_4,
               ushort param_5,undefined2 *param_6,undefined2 *param_7)

{
  long lVar1;
  void *pvVar2;
  undefined8 uVar3;
  char cVar4;
  ulong uVar5;
  longlong ****pppplVar6;
  bool bVar7;
  _SDP_NODE **pp_Var8;
  uint uVar9;
  _SDP_NODE *p_Var10;
  uint uVar11;
  bool bVar12;
  undefined1 auStackY_258 [32];
  undefined1 uVar13;
  undefined1 in_stack_fffffffffffffdd8;
  undefined2 uVar14;
  undefined1 uVar15;
  _SDP_NODE *local_1f8;
  _SDP_NODE *local_1f0;
  uint local_1e8 [2];
  _DEVICE_OBJECT *local_1e0;
  longlong ****local_1d8;
  undefined8 local_1d0;
  undefined4 local_1c8;
  undefined8 local_1c4;
  undefined1 local_1bc;
  _SDP_NODE *local_1b8;
  _GUID *local_1b0;
  undefined2 *local_1a8;
  undefined2 *local_1a0;
  undefined8 *local_198;
  _DEVICE_OBJECT **local_190;
  undefined1 local_188;
  undefined8 local_178;
  undefined4 local_170;
  undefined8 local_16c;
  undefined8 uStack_164;
  undefined2 local_15c;
  undefined4 local_7c;
  ushort local_78;
  ushort local_76;
  ushort local_74;
  ushort local_72;
  undefined8 local_68;
  undefined1 local_60;
  ulonglong local_58;
  
                    /* 0x57d0  3  BtaMpmGetRemoteDeviceProfileVersionAndAttribute */
  local_58 = __security_cookie ^ (ulonglong)auStackY_258;
  local_1a8 = param_6;
  local_1a0 = param_7;
  uVar11 = 0;
  bVar7 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  local_1f0 = param_3;
  local_1e0 = param_1;
  local_1b0 = param_4;
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF__guid__guid_H
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  *param_6 = 0;
  if (param_7 != (undefined2 *)0x0) {
    *param_7 = 0;
  }
  local_1d0 = *param_2;
  local_198 = &local_1d0;
  local_190 = &local_1e0;
  local_1c8 = 5;
  local_1c4 = 0;
  local_1bc = 0;
  local_188 = 1;
  lVar1 = SynchronousIo(local_1e0,0x410200,&local_1d0,0x15,&local_1d0,0x15,
                        (bool)in_stack_fffffffffffffdd8);
  if (lVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar7 = false;
    }
    bVar12 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar7 == false) && (!bVar12)) goto LAB_1800062c6;
    uVar14 = 0xc;
  }
  else {
    memset(&local_178,0,0x108);
    local_178 = local_1c4;
    local_15c = 0x430;
    local_170 = 0;
    local_7c = 0x10001;
    local_16c = *(undefined8 *)param_3;
    uStack_164 = *(undefined8 *)(param_3 + 8);
    if ((param_5 == 0) || (local_78 = param_5, 9 < param_5)) {
      local_78 = 9;
    }
    if ((param_5 == 0) || (local_76 = param_5, 9 < param_5)) {
      local_76 = 9;
    }
    local_74 = param_5;
    if (param_5 < 9) {
      local_74 = 9;
    }
    local_68 = 0;
    local_60 = 0;
    uVar9 = -(uint)(param_5 != 0) & 4;
    local_72 = local_74;
    lVar1 = SynchronousIo(local_1e0,0x410210,&local_178,uVar9 + 0x104,&local_68,9,
                          (bool)in_stack_fffffffffffffdd8);
    if (-1 < lVar1) {
      uVar5 = (int)local_68 + 8;
      pvVar2 = (void *)ExAllocatePool2(0x40,uVar5,0x504d5442);
      if (pvVar2 == (void *)0x0) {
        lVar1 = -0x3fffff66;
        goto LAB_1800062c6;
      }
      lVar1 = SynchronousIo(local_1e0,0x410210,&local_178,uVar9 + 0x104,pvVar2,uVar5,
                            (bool)in_stack_fffffffffffffdd8);
      if (lVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar7 = false;
        }
        if ((bVar7) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xe,
                     &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids,(char)lVar1);
        }
LAB_180005b98:
        ExFreePool(pvVar2);
        goto LAB_1800062c6;
      }
      pppplVar6 = (longlong ****)0x0;
      p_Var10 = (_SDP_NODE *)0x0;
      if (*(int *)local_1f0 != 0) {
        while( true ) {
          if (pppplVar6 != (longlong ****)0x0) {
            SdpFreeTree(pppplVar6);
          }
          local_1d8 = (longlong ****)0x0;
          pp_Var8 = &local_1f8;
          local_1f8 = (_SDP_NODE *)0x0;
          local_1e8[0] = 0;
          SdpGetNextElement((byte *)((longlong)pvVar2 + 8),*(int *)((longlong)pvVar2 + 4),
                            (byte *)p_Var10,(ulonglong *)pp_Var8,local_1e8);
          local_1b8 = local_1f8;
          if (local_1f8 == (_SDP_NODE *)0x0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar7 = false;
            }
            if ((bVar7 != false) ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xf,
                         &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids);
            }
            goto LAB_180006100;
          }
          lVar1 = SdpTreeFromStream((byte *)local_1f8,local_1e8[0],(longlong *)&local_1d8,pp_Var8);
          pppplVar6 = local_1d8;
          if (lVar1 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar7 = false;
            }
            if ((bVar7 != false) ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_d
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x10,
                         &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids,(char)lVar1);
            }
            if (local_1d8 != (longlong ****)0x0) {
              SdpFreeTree(local_1d8);
            }
            goto LAB_180005b98;
          }
          local_1f8 = (_SDP_NODE *)0x0;
          uVar3 = SdpFindAttributeInTree((longlong *)local_1d8,1,&local_1f8);
          lVar1 = (long)uVar3;
          if (lVar1 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar7 = false;
            }
            if ((bVar7 != false) ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_d
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x11,
                         &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids,(char)uVar3);
            }
            goto LAB_1800062a7;
          }
          for (p_Var10 = *(_SDP_NODE **)(local_1f8 + 0x20);
              (uVar11 != *(uint *)local_1f0 && (p_Var10 != local_1f8 + 0x20));
              p_Var10 = *(_SDP_NODE **)p_Var10) {
            if (*(short *)(p_Var10 + 0x12) != 0x130) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                bVar7 = false;
              }
              bVar12 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if ((bVar7 == false) && (!bVar12)) goto LAB_1800060f3;
              uVar14 = 0x12;
              goto LAB_1800060d6;
            }
            uVar11 = (uint)*(ushort *)(p_Var10 + 0x20);
          }
          if (uVar11 == *(uint *)local_1f0) break;
          p_Var10 = local_1b8;
        }
      }
      local_1f0 = (_SDP_NODE *)0x0;
      uVar3 = SdpFindAttributeInTree((longlong *)pppplVar6,9,&local_1f0);
      lVar1 = (long)uVar3;
      if (lVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar7 = false;
        }
        bVar12 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar7 != false) || (bVar12)) {
          uVar15 = (undefined1)uVar3;
          uVar14 = 0x13;
          uVar13 = 2;
LAB_180005f03:
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,bVar12,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar13,2,uVar14,
                     &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids,uVar15);
        }
      }
      else {
        local_1f8 = (_SDP_NODE *)0x0;
        lVar1 = SdpGetProfileDescriptorFromDescriptorList(local_1f0,local_1b0,&local_1f8);
        if (-1 < lVar1) {
          p_Var10 = (_SDP_NODE *)**(undefined8 **)(local_1f8 + 0x20);
          if (p_Var10 == local_1f8 + 0x20) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar7 = false;
            }
            if ((bVar7 != false) ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x15,
                         &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids);
            }
            if (pppplVar6 != (longlong ****)0x0) {
              SdpFreeTree(pppplVar6);
            }
            ExFreePool(pvVar2);
            lVar1 = -0x3ffffe7a;
          }
          else if (*(short *)(p_Var10 + 0x12) == 0x110) {
            *local_1a8 = *(undefined2 *)(p_Var10 + 0x20);
            lVar1 = 0;
            if (param_5 != 0) {
              local_1f0 = (_SDP_NODE *)0x0;
              uVar3 = SdpFindAttributeInTree((longlong *)pppplVar6,param_5,&local_1f0);
              lVar1 = (long)uVar3;
              if (lVar1 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  bVar7 = false;
                }
                if ((bVar7 != false) ||
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_AND_TRACE_SF_d
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,
                             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x17,
                             &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids,(char)uVar3);
                }
                if (lVar1 == -0x3ffffddb) {
                  lVar1 = -0x3ffffaf4;
                }
                if (pppplVar6 != (longlong ****)0x0) {
                  SdpFreeTree(pppplVar6);
                }
                ExFreePool(pvVar2);
                goto LAB_1800062c6;
              }
              if (*(short *)(local_1f0 + 0x12) != 0x110) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  bVar7 = false;
                }
                if ((bVar7 != false) ||
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_AND_TRACE_SF_
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,
                             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x18,
                             &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids);
                }
                if (pppplVar6 != (longlong ****)0x0) {
                  SdpFreeTree(pppplVar6);
                }
                ExFreePool(pvVar2);
                lVar1 = -0x3ffffaf4;
                goto LAB_1800062c6;
              }
              *local_1a0 = *(undefined2 *)(local_1f0 + 0x20);
              lVar1 = 0;
            }
LAB_1800062a7:
            if (pppplVar6 != (longlong ****)0x0) {
              SdpFreeTree(pppplVar6);
            }
            ExFreePool(pvVar2);
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar7 = false;
            }
            bVar12 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((bVar7 != false) || (bVar12)) {
              uVar14 = 0x16;
LAB_1800060d6:
              WPP_RECORDER_AND_TRACE_SF_
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,bVar12,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar14,
                         &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids);
            }
LAB_1800060f3:
            if (pppplVar6 != (longlong ****)0x0) {
              SdpFreeTree(pppplVar6);
            }
LAB_180006100:
            ExFreePool(pvVar2);
            lVar1 = -0x3ffffddb;
          }
          goto LAB_1800062c6;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          bVar7 = false;
        }
        bVar12 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar7 != false) || (bVar12)) {
          uVar15 = (undefined1)lVar1;
          uVar14 = 0x14;
          uVar13 = 4;
          goto LAB_180005f03;
        }
      }
      if (pppplVar6 != (longlong ****)0x0) {
        SdpFreeTree(pppplVar6);
      }
      ExFreePool(pvVar2);
      goto LAB_1800062c6;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar7 = false;
    }
    bVar12 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar7 == false) && (!bVar12)) goto LAB_1800062c6;
    uVar14 = 0xd;
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar7,bVar12,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar14,
             &WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids,(char)lVar1);
LAB_1800062c6:
  wil::details::lambda_call<<lambda_726011562b617b6c31188a53cec19341>_>::
  ~lambda_call<<lambda_726011562b617b6c31188a53cec19341>_>((longlong *)&local_198);
  return lVar1;
}



===== WPP_RECORDER_AND_TRACE_SF__guid__guid_H @ 1800062fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF__guid__guid_H
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,&WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids,10);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,2,&WPP_63f22a92b01e3298760d1e21ecbef7ca_Traceguids,10);
  }
  return;
}



===== GetProfile @ 1800063f4 =====

/* public: class Profile & __ptr64 __cdecl _BtDeviceEntry::GetProfile(enum BTAMPM_PROFILE) __ptr64
    */

Profile * __thiscall _BtDeviceEntry::GetProfile(_BtDeviceEntry *this,BTAMPM_PROFILE param_1)

{
  if (param_1 != 0) {
    if (param_1 == 1) {
      return (Profile *)(this + 0xa8);
    }
    if (param_1 == 2) {
      return (Profile *)(this + 0x128);
    }
    if (param_1 == 3) {
      return (Profile *)(this + 0x1a8);
    }
  }
  return (Profile *)(this + 0x28);
}



===== GetRemoteAddress @ 180006430 =====

/* public: unsigned __int64 __cdecl _BtDeviceEntry::GetRemoteAddress(void)const __ptr64 */

__uint64 __thiscall _BtDeviceEntry::GetRemoteAddress(_BtDeviceEntry *this)

{
  return *(__uint64 *)(this + 0x20);
}



===== InitiatePendedAutoConnectRequests @ 18000643c =====

/* public: long __cdecl _BtDeviceEntry::InitiatePendedAutoConnectRequests(void) __ptr64 */

long __thiscall _BtDeviceEntry::InitiatePendedAutoConnectRequests(_BtDeviceEntry *this)

{
  _BtDeviceEntry *p_Var1;
  longlong *plVar2;
  longlong lVar3;
  Profile *pPVar4;
  long lVar5;
  char cVar6;
  long lVar7;
  
  lVar7 = 0;
  while (p_Var1 = *(_BtDeviceEntry **)(this + 0x230), p_Var1 != this + 0x230) {
    plVar2 = *(longlong **)(p_Var1 + 8);
    lVar3 = *(longlong *)p_Var1;
    pPVar4 = *(Profile **)(p_Var1 + 0x10);
    *plVar2 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar2;
    ExFreePoolWithTag(p_Var1,0x646d4370);
    *(longlong *)(this + 0x240) = *(longlong *)(this + 0x240) + -1;
    lVar5 = EnqueueWorkItem(0,pPVar4,0);
    if (lVar5 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)
         ) {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_Ld
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,10,
                   &WPP_435f55f08caa357e6bb1cd4eb2c026b6_Traceguids,
                   (char)*(undefined4 *)(pPVar4 + 0x50),(char)lVar5);
      }
      lVar7 = lVar5;
    }
  }
  return lVar7;
}



===== Profile @ 180006550 =====

/* public: __cdecl Profile::Profile(enum BTAMPM_PROFILE,class _BtDeviceEntry * __ptr64) __ptr64 */

Profile * __thiscall Profile::Profile(Profile *this,BTAMPM_PROFILE param_1,_BtDeviceEntry *param_2)

{
  *(undefined2 *)this = 0;
  this[2] = (Profile)0x0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  KeInitializeEvent(this + 0x30,0,0);
  this[0x4c] = (Profile)0x0;
  *(undefined4 *)(this + 0x48) = 1;
  *(BTAMPM_PROFILE *)(this + 0x50) = param_1;
  *(_BtDeviceEntry **)(this + 0x58) = param_2;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined2 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  this[0x78] = (Profile)0x0;
  return this;
}



===== GetDevice @ 1800065f0 =====

/* public: class _BtDeviceEntry & __ptr64 __cdecl Profile::GetDevice(void)const __ptr64 */

_BtDeviceEntry * __thiscall Profile::GetDevice(Profile *this)

{
  return *(_BtDeviceEntry **)(this + 0x58);
}



===== SetRegisteredForPnpNotifications @ 1800065fc =====

/* public: void __cdecl Profile::SetRegisteredForPnpNotifications(bool) __ptr64 */

void __thiscall Profile::SetRegisteredForPnpNotifications(Profile *this,bool param_1)

{
  this[0x78] = (Profile)param_1;
  return;
}



===== SdpFreePool @ 180006608 =====

void SdpFreePool(void)

{
  ExFreePool();
  return;
}



===== SdpInterlockedDecrement @ 180006624 =====

int SdpInterlockedDecrement(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  return iVar1 + -1;
}



===== SdppAllocatePool @ 180006638 =====

void SdppAllocatePool(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x100,param_1,param_2);
  return;
}



===== RtlStringLengthWorkerW @ 180006660 =====

uint RtlStringLengthWorkerW(short *param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = 0x7fff;
  do {
    if (*param_1 == 0) break;
    param_1 = param_1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 != (longlong *)0x0) {
    if (lVar2 != 0) {
      *param_3 = 0x7fff - lVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== RtlUnicodeStringInitWorker @ 1800066a8 =====

uint RtlUnicodeStringInitWorker(short *param_1,short *param_2)

{
  uint uVar1;
  longlong local_res18 [2];
  
  uVar1 = 0;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (param_2 != (short *)0x0) {
    local_res18[0] = 0;
    uVar1 = RtlStringLengthWorkerW(param_2,param_2,local_res18);
    if (-1 < (int)uVar1) {
      if (param_1 == (short *)0x0) {
        uVar1 = 0xc000000d;
      }
      else {
        *(short **)(param_1 + 4) = param_2;
        *param_1 = (short)local_res18[0] * 2;
        param_1[1] = (short)local_res18[0] * 2 + 2;
      }
    }
  }
  return uVar1;
}



===== _guard_check_icall @ 180006720 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 180006740 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 180006780 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1800067b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001800067b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1800067e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 180006840 =====

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



===== __memset_repmovs @ 180006980 =====

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



===== __memset_query @ 180006a00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 180006a80 =====

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



===== __memset_spec_ermsb_repmovsb @ 180006bc0 =====

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



===== __memset_spec_plain @ 180006c40 =====

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



===== memmove @ 180006d80 =====

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



===== DllInitialize @ 18000d010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DllInitialize(undefined8 param_1)

{
  code *pcVar1;
  int iVar2;
  char cVar3;
  undefined *puVar4;
  uint local_res10 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
                    /* 0xd010  13  DllInitialize */
  _DAT_18000a138 = 1;
  _WPP_MAIN_CB = (code *)0x0;
  DAT_18000a120 = 0;
  DAT_18000a118 = &WPP_ThisDir_CTLGUID_Btampm;
  _DAT_18000a130 = 0;
  DAT_18000a150 = 0;
  _DAT_18000a158 = 0;
  local_res10[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_28,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(&local_28);
  RtlInitUnicodeString(&local_28,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_28);
  RtlInitUnicodeString(&local_28,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_28);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res10,0,0,0);
  }
  if (5 < local_res10[0]) {
    RtlInitUnicodeString(&local_28,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = (code *)MmGetSystemRoutineAddress(&local_28);
    if (pfnEtwRegisterClassicProvider != (code *)0x0) {
      RtlInitUnicodeString(&local_28,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_28);
      WPPTraceSuite = 4;
    }
  }
  _DAT_18000a130 = 0;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar4 = &WPP_MAIN_CB;
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar4 + 0x38) = 0;
        (*pcVar1)(*(undefined8 *)(puVar4 + 8),0,WppClassicProviderCallback,puVar4,puVar4 + 0x38);
        puVar4 = *(undefined **)(puVar4 + 0x10);
      } while (puVar4 != (undefined *)0x0);
    }
    else if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,0,param_1);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
               &WPP_dd06b1027a7233e8e8c2d25117b7ba85_Traceguids);
  }
  iVar2 = wil_InitializeFeatureStaging();
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                 &WPP_dd06b1027a7233e8e8c2d25117b7ba85_Traceguids,(char)iVar2);
    }
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
    WppCleanupKm();
  }
  return iVar2;
}



===== DllUnload @ 18000d390 =====

undefined8 DllUnload(void)

{
  char cVar1;
  
                    /* 0xd390  14  DllUnload */
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xc,
               &WPP_dd06b1027a7233e8e8c2d25117b7ba85_Traceguids);
  }
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  WppCleanupKm();
  return 0;
}



===== DriverEntry @ 18000d45c =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== WppCleanupKm @ 18000d468 =====

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
    WppAutoLogStop(WPP_GLOBAL_Control,0);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppTraceCallback @ 18000d510 =====

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



===== wil_details_EvaluateFeatureDependencies @ 18000d798 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &wil_details_featureDescriptors_a;
  ppuVar2 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00018000d7d3;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_18000d84d:
  while( true ) {
    if (&UNK_180009cff < ppuVar3) {
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
      if (&UNK_180009cff < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00018000d7d3:
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
      if (&UNK_180009cff < ppuVar2) goto LAB_18000d84d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_18000d84d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 18000d888 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_18000d924;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_18000d924;
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
LAB_18000d924:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 18000d990 =====

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
      for (ppuVar2 = &wil_details_featureDescriptors_a; ppuVar2 < &wil_details_featureDescriptors_z;
          ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_180009cff < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 18000da10 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 18000da30 =====

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
  for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_18000db2d;
  }
LAB_18000db36:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_18000db2d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_18000db36;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_18000dafe:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_18000dafe;
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
    if (&UNK_180009cff < ppuVar3) goto LAB_18000db36;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_18000db2d;
}



===== InitializeManagerData @ 18000db5c =====

/* long __cdecl InitializeManagerData(void) */

long __cdecl InitializeManagerData(void)

{
  _BtMpmData *p_Var1;
  int iVar2;
  _BtMpmData *p_Var3;
  char cVar4;
  bool bVar5;
  undefined8 local_res8;
  
  iVar2 = 0;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x2b,
               &WPP_ca993d7a41d533ca7b28eba04318f9c6_Traceguids);
  }
  p_Var3 = (_BtMpmData *)ExAllocatePool2(0x40,0x58,0x504d5442);
  if (p_Var3 == (_BtMpmData *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    KeInitializeSpinLock(p_Var3);
    p_Var1 = p_Var3 + 8;
    *(_BtMpmData **)(p_Var3 + 0x10) = p_Var1;
    *(_BtMpmData **)p_Var1 = p_Var1;
    KeInitializeSpinLock(p_Var3 + 0x20);
    p_Var1 = p_Var3 + 0x28;
    *(_BtMpmData **)(p_Var3 + 0x30) = p_Var1;
    *(_BtMpmData **)p_Var1 = p_Var1;
    KeInitializeEvent(p_Var3 + 0x38,1);
    *(undefined4 *)(p_Var3 + 0x50) = 1;
    LOCK();
    bVar5 = g_ManagerData == (_BtMpmData *)0x0;
    if (bVar5) {
      g_ManagerData = p_Var3;
    }
    UNLOCK();
    if (bVar5) {
      local_res8 = 0;
      iVar2 = PsCreateSystemThread(&local_res8,0,0,0,0,ProcessWorkItems,0);
      if (-1 < iVar2) {
        iVar2 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,g_ManagerData + 0x18,0);
        if (iVar2 < 0) {
          *(undefined4 *)(g_ManagerData + 0x50) = 0;
          KeSetEvent(g_ManagerData + 0x38,0,0);
        }
        ZwClose(local_res8);
        if (-1 < iVar2) {
          return iVar2;
        }
      }
      p_Var3 = g_ManagerData;
      g_ManagerData = (_BtMpmData *)0x0;
    }
    ExFreePoolWithTag(p_Var3,0x504d5442);
  }
  return iVar2;
}



===== BtaMpmRegisterPnp @ 18000dd50 =====

void BtaMpmRegisterPnp(undefined8 *param_1,_DRIVER_OBJECT *param_2,ushort *param_3)

{
  long lVar1;
  _BtDeviceEntry *this;
  _func_long_void_ptr_void_ptr *in_stack_ffffffffffffffe8;
  
                    /* 0xdd50  6  BtaMpmRegisterPnp */
  if (param_1 != (undefined8 *)0x0) {
    this = Profile::GetDevice((Profile *)*param_1);
    lVar1 = _BtDeviceEntry::RegisterForPnpNotifications
                      (this,param_1,param_2,param_3,in_stack_ffffffffffffffe8);
    Profile::SetRegisteredForPnpNotifications
              ((Profile *)*param_1,(bool)((byte)((uint)lVar1 >> 0x1f) ^ 1));
  }
  return;
}



===== IsBasebandConnected @ 18000dd9c =====

/* private: bool __cdecl _BtDeviceEntry::IsBasebandConnected(void)const __ptr64 */

bool __thiscall _BtDeviceEntry::IsBasebandConnected(_BtDeviceEntry *this)

{
  bool bVar1;
  __uint64 _Var2;
  
  _Var2 = GetRemoteAddress(this);
  bVar1 = IsBasebandConnectedToDevice(_Var2);
  return bVar1;
}



===== RegisterForPnpNotifications @ 18000ddbc =====

/* public: long __cdecl _BtDeviceEntry::RegisterForPnpNotifications(void * __ptr64,struct
   _DRIVER_OBJECT * __ptr64,unsigned short const * __ptr64,long (__cdecl*)(void * __ptr64,void *
   __ptr64)) __ptr64 */

long __thiscall
_BtDeviceEntry::RegisterForPnpNotifications
          (_BtDeviceEntry *this,void *param_1,_DRIVER_OBJECT *param_2,ushort *param_3,
          _func_long_void_ptr_void_ptr *param_4)

{
  uint uVar1;
  longlong lVar2;
  undefined8 local_res8;
  short local_18 [8];
  
  if (*(longlong *)(this + 0x248) == 0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_3[lVar2] != 0);
    if ((ulonglong)(lVar2 * 2) < 0x10000) {
      local_18[0] = 0;
      local_18[1] = 0;
      local_18[2] = 0;
      local_18[3] = 0;
      local_18[4] = 0;
      local_18[5] = 0;
      local_18[6] = 0;
      local_18[7] = 0;
      uVar1 = RtlUnicodeStringInitWorker(local_18,(short *)param_3);
      if (-1 < (int)uVar1) {
        local_res8 = 0;
        param_4 = (_func_long_void_ptr_void_ptr *)0x0;
        uVar1 = IoGetDeviceObjectPointer(local_18,0x1f01ff,&local_res8,&param_4);
        if (-1 < (int)uVar1) {
          uVar1 = IoRegisterPlugPlayNotification
                            (3,0,local_res8,param_2,PnpNotificationHandler,param_1,this + 0x248);
          ObfDereferenceObject(local_res8);
        }
      }
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  else {
    uVar1 = 0xc0000718;
  }
  return uVar1;
}



===== UnregisterForPnpNotifications @ 18000dec0 =====

/* public: long __cdecl _BtDeviceEntry::UnregisterForPnpNotifications(void) __ptr64 */

long __thiscall _BtDeviceEntry::UnregisterForPnpNotifications(_BtDeviceEntry *this)

{
  long lVar1;
  
  lVar1 = 0;
  if (*(longlong *)(this + 0x248) != 0) {
    lVar1 = IoUnregisterPlugPlayNotification();
    *(undefined8 *)(this + 0x248) = 0;
  }
  return lVar1;
}



===== SdppStreamToNode @ 18000def8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* struct _SDP_NODE * __ptr64 __cdecl SdppStreamToNode(unsigned char * __ptr64,unsigned long,struct
   _SDP_TREE_ROOT_NODE * __ptr64,struct _SDP_NODE * __ptr64,char * __ptr64,unsigned char) */

_SDP_NODE * __cdecl
SdppStreamToNode(uchar *param_1,ulong param_2,_SDP_TREE_ROOT_NODE *param_3,_SDP_NODE *param_4,
                char *param_5,uchar param_6)

{
  _SDP_NODE *p_Var1;
  undefined8 uVar2;
  code *pcVar3;
  longlong lVar4;
  char *pcVar5;
  _SDP_NODE _Var6;
  ushort uVar7;
  long lVar8;
  longlong *plVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  _SDP_NODE *p_Var15;
  int *piVar16;
  byte bVar17;
  byte bVar18;
  ulong uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined1 auStack_2d8 [32];
  ulonglong local_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  undefined8 local_2a0;
  undefined8 uStack_298;
  uint local_290;
  uint local_28c;
  uint local_288;
  char *local_280;
  undefined8 local_278;
  undefined8 uStack_270;
  _SDP_NODE *local_268;
  undefined8 local_258;
  int *local_250;
  int *local_248;
  int *local_240;
  undefined4 local_238;
  int local_230 [122];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_2d8;
  local_280 = param_5;
  local_258 = 0;
  local_268 = param_4;
  memset(local_230,0,0x1e0);
  local_238 = 0x14;
  local_240 = local_230;
  local_290 = 0;
  local_28c = 0;
  local_248 = local_230;
  local_2b0 = 0;
  uStack_2a8 = 0;
  local_2b8 = 0;
  local_2a0 = 0;
  uStack_298 = 0;
  local_278 = 0;
  uStack_270 = 0;
  local_250 = local_230;
  do {
    while( true ) {
      bVar18 = *param_1 >> 3;
      bVar17 = *param_1 & 7;
      p_Var15 = (_SDP_NODE *)(param_1 + 1);
      uVar19 = param_2 - 1;
      if (bVar18 != 0) break;
      *(undefined4 *)(param_4 + 0x10) = 0;
      *(_SDP_NODE **)(param_4 + 8) = param_4;
      *(_SDP_NODE **)param_4 = param_4;
      plVar9 = *(longlong **)(param_3 + 8);
      param_2 = uVar19;
      if ((_LIST_ENTRY *)*plVar9 != (_LIST_ENTRY *)param_3) goto LAB_18000e8f2;
LAB_18000e850:
      *(_SDP_TREE_ROOT_NODE **)param_4 = param_3;
      *(longlong **)(param_4 + 8) = plVar9;
      *plVar9 = (longlong)param_4;
LAB_18000e85a:
      *(_SDP_NODE **)(param_3 + 8) = param_4;
      param_4 = param_4 + 0x40;
      param_1 = (uchar *)p_Var15;
      if (param_2 == 0) {
        do {
          if (local_250 == local_248) {
            if (local_248 != local_240) {
              SdpFreePool();
            }
            return local_268;
          }
          piVar16 = local_250 + -6;
          param_3 = *(_SDP_TREE_ROOT_NODE **)(local_250 + -2);
          param_2 = *piVar16 - *(int *)(*(longlong *)(local_250 + -4) + 0x18);
          local_250 = piVar16;
        } while (param_2 == 0);
      }
    }
    if (bVar18 == 1) {
      if (bVar17 == 0) {
        _Var6 = *p_Var15;
        *(undefined4 *)(param_4 + 0x10) = 0x100001;
LAB_18000e5be:
        *(_SDP_NODE **)(param_4 + 8) = param_4;
        *(_SDP_NODE **)param_4 = param_4;
        *(undefined4 *)(param_4 + 0x18) = 1;
        param_4[0x20] = _Var6;
      }
      else {
        if (bVar17 == 1) {
          uVar7 = *(ushort *)p_Var15;
          *(undefined4 *)(param_4 + 0x10) = 0x1100001;
          goto LAB_18000e28e;
        }
        if (bVar17 == 2) {
          uVar10 = *(uint *)p_Var15;
          *(undefined4 *)(param_4 + 0x10) = 0x2100001;
          goto LAB_18000e26f;
        }
        if (bVar17 != 3) {
          if (bVar17 == 4) {
            if (((ulonglong)p_Var15 & 7) == 0) {
              uVar11 = *(ulonglong *)p_Var15;
            }
            else {
              uVar11 = *(ulonglong *)p_Var15;
            }
            p_Var1 = (_SDP_NODE *)(param_1 + 9);
            if (((ulonglong)p_Var1 & 7) == 0) {
              uVar12 = *(ulonglong *)p_Var1;
            }
            else {
              uVar12 = *(ulonglong *)p_Var1;
            }
            *(undefined4 *)(param_4 + 0x10) = 0x4100001;
            uVar13 = ((uVar11 & 0xff000000000000 | uVar11 >> 0x10) >> 0x10 | uVar11 & 0xff0000000000
                     ) >> 0x10 | uVar11 & 0xff00000000;
            uVar11 = ((uVar11 << 0x10 | uVar11 & 0xff00) << 0x10 | uVar11 & 0xff0000) << 0x10 |
                     uVar11 & 0xff000000;
            uVar14 = ((uVar12 & 0xff000000000000 | uVar12 >> 0x10) >> 0x10 | uVar12 & 0xff0000000000
                     ) >> 0x10 | uVar12 & 0xff00000000;
            uVar12 = ((uVar12 << 0x10 | uVar12 & 0xff00) << 0x10 | uVar12 & 0xff0000) << 0x10 |
                     uVar12 & 0xff000000;
            local_2a0._0_4_ = (uint)(uVar14 >> 8);
            local_2a0._4_4_ = (undefined4)(uVar12 >> 0x18);
            uStack_298._0_4_ = (undefined4)(uVar13 >> 8);
            uStack_298._4_4_ = (undefined4)(uVar11 >> 0x18);
            uVar10 = (uint)local_2a0;
            uVar20 = local_2a0._4_4_;
            uVar21 = (undefined4)uStack_298;
            uVar22 = uStack_298._4_4_;
            local_2a0 = uVar14 >> 8 | uVar12 << 8;
            uStack_298 = uVar13 >> 8 | uVar11 << 8;
            goto LAB_18000e251;
          }
          goto LAB_18000e8a2;
        }
        if (((ulonglong)p_Var15 & 7) == 0) {
          local_2b8 = *(ulonglong *)p_Var15;
        }
        else {
          local_2b8 = *(ulonglong *)p_Var15;
        }
        *(undefined4 *)(param_4 + 0x10) = 0x3100001;
LAB_18000e4fe:
        *(_SDP_NODE **)(param_4 + 8) = param_4;
        *(_SDP_NODE **)param_4 = param_4;
        *(undefined4 *)(param_4 + 0x18) = 8;
        *(ulonglong *)(param_4 + 0x20) =
             (((local_2b8 & 0xff000000000000 | local_2b8 >> 0x10) >> 0x10 |
              local_2b8 & 0xff0000000000) >> 0x10 | local_2b8 & 0xff00000000) >> 8 |
             (((local_2b8 << 0x10 | (ulonglong)((uint)local_2b8 & 0xff00)) << 0x10 |
              (ulonglong)((uint)local_2b8 & 0xff0000)) << 0x10 | local_2b8 & 0xff000000) << 8;
      }
LAB_18000e2a1:
      plVar9 = *(longlong **)(param_3 + 8);
      if ((_LIST_ENTRY *)*plVar9 == (_LIST_ENTRY *)param_3) {
        p_Var15 = p_Var15 + *(uint *)(&g_IndexToDataSize + (ulonglong)bVar17 * 4);
        param_2 = uVar19 - *(uint *)(&g_IndexToDataSize + (ulonglong)bVar17 * 4);
        goto LAB_18000e850;
      }
LAB_18000e8f2:
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      p_Var15 = (_SDP_NODE *)(*pcVar3)();
      return p_Var15;
    }
    if (bVar18 == 2) {
      if (bVar17 == 0) {
        _Var6 = *p_Var15;
        *(undefined4 *)(param_4 + 0x10) = 0x200002;
        goto LAB_18000e5be;
      }
      if (bVar17 == 1) {
        uVar7 = *(ushort *)p_Var15;
        *(undefined4 *)(param_4 + 0x10) = 0x1200002;
        goto LAB_18000e28e;
      }
      if (bVar17 == 2) {
        uVar10 = *(uint *)p_Var15;
        *(undefined4 *)(param_4 + 0x10) = 0x2200002;
        goto LAB_18000e26f;
      }
      if (bVar17 == 3) {
        if (((ulonglong)p_Var15 & 7) == 0) {
          local_2b8 = *(ulonglong *)p_Var15;
        }
        else {
          local_2b8 = *(ulonglong *)p_Var15;
        }
        *(undefined4 *)(param_4 + 0x10) = 0x3200002;
        goto LAB_18000e4fe;
      }
      if (bVar17 == 4) {
        if (((ulonglong)p_Var15 & 7) == 0) {
          uVar11 = *(ulonglong *)p_Var15;
        }
        else {
          uVar11 = *(ulonglong *)p_Var15;
        }
        p_Var1 = (_SDP_NODE *)(param_1 + 9);
        if (((ulonglong)p_Var1 & 7) == 0) {
          uVar12 = *(ulonglong *)p_Var1;
        }
        else {
          uVar12 = *(ulonglong *)p_Var1;
        }
        *(undefined4 *)(param_4 + 0x10) = 0x4200002;
        uVar13 = ((uVar11 & 0xff000000000000 | uVar11 >> 0x10) >> 0x10 | uVar11 & 0xff0000000000) >>
                 0x10 | uVar11 & 0xff00000000;
        uVar11 = ((uVar11 << 0x10 | uVar11 & 0xff00) << 0x10 | uVar11 & 0xff0000) << 0x10 |
                 uVar11 & 0xff000000;
        uVar14 = ((uVar12 & 0xff000000000000 | uVar12 >> 0x10) >> 0x10 | uVar12 & 0xff0000000000) >>
                 0x10 | uVar12 & 0xff00000000;
        uVar12 = ((uVar12 << 0x10 | uVar12 & 0xff00) << 0x10 | uVar12 & 0xff0000) << 0x10 |
                 uVar12 & 0xff000000;
        local_2b0._0_4_ = (uint)(uVar14 >> 8);
        local_2b0._4_4_ = (undefined4)(uVar12 >> 0x18);
        uStack_2a8._0_4_ = (undefined4)(uVar13 >> 8);
        uStack_2a8._4_4_ = (undefined4)(uVar11 >> 0x18);
        uVar10 = (uint)local_2b0;
        uVar20 = local_2b0._4_4_;
        uVar21 = (undefined4)uStack_2a8;
        uVar22 = uStack_2a8._4_4_;
        local_2b0 = uVar14 >> 8 | uVar12 << 8;
        uStack_2a8 = uVar13 >> 8 | uVar11 << 8;
        goto LAB_18000e251;
      }
LAB_18000e8a2:
      if (local_248 == local_240) {
        return (_SDP_NODE *)0x0;
      }
LAB_18000e8ab:
      SdpFreePool();
      return (_SDP_NODE *)0x0;
    }
    if (bVar18 == 3) {
      if (bVar17 == 1) {
        uVar7 = *(ushort *)p_Var15;
        *(undefined4 *)(param_4 + 0x10) = 0x1300003;
LAB_18000e28e:
        *(_SDP_NODE **)(param_4 + 8) = param_4;
        *(_SDP_NODE **)param_4 = param_4;
        *(ushort *)(param_4 + 0x20) = uVar7 >> 8 | uVar7 << 8;
        *(undefined4 *)(param_4 + 0x18) = 2;
        goto LAB_18000e2a1;
      }
      if (bVar17 == 2) {
        uVar10 = *(uint *)p_Var15;
        *(undefined4 *)(param_4 + 0x10) = 0x2200003;
LAB_18000e26f:
        *(_SDP_NODE **)(param_4 + 8) = param_4;
        *(_SDP_NODE **)param_4 = param_4;
        *(undefined4 *)(param_4 + 0x18) = 4;
        *(uint *)(param_4 + 0x20) =
             uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18;
        goto LAB_18000e2a1;
      }
      if (bVar17 == 4) {
        uVar10 = *(uint *)p_Var15;
        uVar2 = *(undefined8 *)(param_1 + 9);
        uVar10 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18
        ;
        local_278 = CONCAT26(*(ushort *)(param_1 + 7) >> 8 | *(ushort *)(param_1 + 7) << 8,
                             CONCAT24(*(ushort *)(param_1 + 5) >> 8 | *(ushort *)(param_1 + 5) << 8,
                                      uVar10));
        uStack_270._0_4_ = (undefined4)uVar2;
        uStack_270._4_4_ = (undefined4)((ulonglong)uVar2 >> 0x20);
        *(undefined4 *)(param_4 + 0x10) = 0x4300003;
        uVar20 = local_278._4_4_;
        uVar21 = (undefined4)uStack_270;
        uVar22 = uStack_270._4_4_;
        uStack_270 = uVar2;
LAB_18000e251:
        *(_SDP_NODE **)(param_4 + 8) = param_4;
        *(_SDP_NODE **)param_4 = param_4;
        *(undefined4 *)(param_4 + 0x18) = 0x10;
        *(uint *)(param_4 + 0x20) = uVar10;
        *(undefined4 *)(param_4 + 0x24) = uVar20;
        *(undefined4 *)(param_4 + 0x28) = uVar21;
        *(undefined4 *)(param_4 + 0x2c) = uVar22;
        goto LAB_18000e2a1;
      }
      goto LAB_18000e8a2;
    }
    if (bVar18 != 4) {
      if (bVar18 == 5) {
        _Var6 = *p_Var15;
        *(undefined4 *)(param_4 + 0x10) = 5;
        *(_SDP_NODE **)(param_4 + 8) = param_4;
        *(_SDP_NODE **)param_4 = param_4;
        *(undefined4 *)(param_4 + 0x18) = 1;
        param_4[0x20] = _Var6;
        plVar9 = *(longlong **)(param_3 + 8);
        if ((_LIST_ENTRY *)*plVar9 == (_LIST_ENTRY *)param_3) {
          p_Var15 = (_SDP_NODE *)(param_1 + 2);
          param_2 = param_2 - 2;
          goto LAB_18000e850;
        }
        goto LAB_18000e8f2;
      }
      if (((bVar18 != 6) && (bVar18 != 7)) && (bVar18 != 8)) goto LAB_18000e8a2;
    }
    SdpRetrieveVariableSize((uint *)p_Var15,bVar17,&local_28c,(int *)&local_290);
    pcVar5 = local_280;
    param_2 = local_28c;
    uVar11 = (ulonglong)local_28c;
    local_288 = local_290;
    if (bVar18 == 4) {
      *(undefined4 *)(param_4 + 0x10) = 4;
      *(_SDP_NODE **)(param_4 + 8) = param_4;
      *(_SDP_NODE **)param_4 = param_4;
      memmove(local_280,p_Var15 + local_290,uVar11);
      lVar4 = (~-(ulonglong)((param_2 & 7) != 0) & 8) + (uVar11 + 7 & 0xfffffffffffffff8);
LAB_18000e1c4:
      local_280 = pcVar5 + lVar4;
      *(char **)(param_4 + 0x20) = pcVar5;
      *(ulong *)(param_4 + 0x18) = param_2;
LAB_18000e1d3:
      plVar9 = *(longlong **)(param_3 + 8);
      if ((_LIST_ENTRY *)*plVar9 == (_LIST_ENTRY *)param_3) {
        *(longlong **)(param_4 + 8) = plVar9;
        *(_SDP_TREE_ROOT_NODE **)param_4 = param_3;
        p_Var15 = p_Var15 + (param_2 + local_288);
        *plVar9 = (longlong)param_4;
        param_2 = uVar19 - (param_2 + local_288);
        goto LAB_18000e85a;
      }
      goto LAB_18000e8f2;
    }
    if ((bVar18 != 6) && (bVar18 != 7)) {
      if (bVar18 == 8) {
        *(undefined4 *)(param_4 + 0x10) = 8;
        *(_SDP_NODE **)(param_4 + 8) = param_4;
        *(_SDP_NODE **)param_4 = param_4;
        memmove(local_280,p_Var15 + local_290,uVar11);
        lVar4 = (~-(ulonglong)((param_2 & 7) != 0) & 8) + (uVar11 + 7 & 0xfffffffffffffff8);
        goto LAB_18000e1c4;
      }
      goto LAB_18000e1d3;
    }
    p_Var1 = param_4 + 0x20;
    *(ushort *)(param_4 + 0x10) = (bVar18 != 6) + 6;
    *(undefined2 *)(param_4 + 0x12) = 0;
    *(_SDP_NODE **)(param_4 + 8) = param_4;
    *(_SDP_NODE **)param_4 = param_4;
    *(undefined4 *)(param_4 + 0x30) = 0x21;
    *(_SDP_NODE **)(param_4 + 0x28) = param_4 + 0x20;
    *(_SDP_NODE **)(param_4 + 0x20) = param_4 + 0x20;
    *(uint *)(param_4 + 0x18) = local_28c;
    if (local_28c == 0) goto LAB_18000e1d3;
    uVar11 = (ulonglong)local_290;
    lVar8 = SdpStack::Push((SdpStack *)&local_258,param_4,uVar19 - local_290,(_LIST_ENTRY *)param_3)
    ;
    if (lVar8 < 0) {
      if (local_248 == local_240) {
        return (_SDP_NODE *)0x0;
      }
      goto LAB_18000e8ab;
    }
    plVar9 = *(longlong **)(param_3 + 8);
    if ((_LIST_ENTRY *)*plVar9 != (_LIST_ENTRY *)param_3) goto LAB_18000e8f2;
    *(_SDP_TREE_ROOT_NODE **)param_4 = param_3;
    *(longlong **)(param_4 + 8) = plVar9;
    *plVar9 = (longlong)param_4;
    *(_SDP_NODE **)(param_3 + 8) = param_4;
    param_4 = param_4 + 0x40;
    param_1 = (uchar *)(p_Var15 + uVar11);
    param_3 = (_SDP_TREE_ROOT_NODE *)p_Var1;
  } while( true );
}



===== SdpGetNextElement @ 18000e900 =====

void SdpGetNextElement(byte *param_1,int param_2,byte *param_3,ulonglong *param_4,uint *param_5)

{
  byte bVar1;
  ulonglong uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint *puVar7;
  uint uVar8;
  uint local_res8 [2];
  
  puVar3 = param_5;
  local_res8[0] = 0;
  bVar1 = *param_1;
  param_5._0_4_ = 0;
  *param_4 = 0;
  *puVar3 = 0;
  if (1 < (byte)((bVar1 >> 3) - 6)) {
    return;
  }
  puVar7 = (uint *)(param_1 + 1);
  uVar8 = param_2 - 1;
  if (param_3 == (byte *)0x0) {
    SdpRetrieveVariableSize(puVar7,bVar1 & 7,(uint *)&param_5,(int *)local_res8);
    pbVar6 = (byte *)0x0;
    if ((int)param_5 == 0) goto LAB_18000e9b5;
    if ((ulonglong)uVar8 - 1 <= (ulonglong)local_res8[0]) {
      return;
    }
    pbVar6 = (byte *)((ulonglong)local_res8[0] + (longlong)puVar7);
  }
  else {
    uVar4 = SdpGetElementSize((uint *)(param_3 + 1),*param_3 >> 3,*param_3 & 7);
    if (uVar4 + 1 < uVar4) {
      return;
    }
    pbVar6 = param_3 + (uVar4 + 1);
    if (pbVar6 < param_3) {
      return;
    }
    if ((byte *)((ulonglong)uVar8 + (longlong)puVar7) <= pbVar6) {
      return;
    }
  }
  *param_4 = (ulonglong)pbVar6;
LAB_18000e9b5:
  if (pbVar6 != (byte *)0x0) {
    uVar5 = SdpGetElementSize((uint *)(pbVar6 + 1),*pbVar6 >> 3,*pbVar6 & 7);
    uVar4 = uVar5 + 1;
    if (uVar5 <= uVar4) {
      uVar2 = *param_4;
      *puVar3 = uVar4;
      if ((uVar2 <= uVar5 + uVar2) && ((ulonglong)uVar4 <= (uVar8 - uVar2) + (longlong)puVar7)) {
        return;
      }
    }
    *puVar3 = 0;
    *param_4 = 0;
  }
  return;
}



===== SdpRetrieveVariableSize @ 18000ea1c =====

void SdpRetrieveVariableSize(uint *param_1,char param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  
  *param_4 = 1 << (param_2 - 5U & 0x1f);
  if (param_2 == '\x05') {
    uVar1 = (uint)(byte)*param_1;
  }
  else if (param_2 == '\x06') {
    uVar1 = (uint)(ushort)((ushort)*param_1 >> 8 | (ushort)*param_1 << 8);
  }
  else {
    if (param_2 != '\a') {
      *param_3 = 0;
      return;
    }
    uVar1 = *param_1;
    uVar1 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  }
  *param_3 = uVar1;
  return;
}



===== SdpTreeFromStream_P @ 18000ea6c =====

long SdpTreeFromStream_P(byte *param_1,ulong param_2,longlong *param_3,undefined8 param_4,
                        uint param_5)

{
  longlong lVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  longlong *plVar5;
  _SDP_NODE *p_Var6;
  _SDP_NODE *p_Var7;
  _SDP_NODE *p_Var8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  bool bVar12;
  uint local_res20 [2];
  longlong local_48 [2];
  
  local_48[0] = 0;
  local_res20[0] = 0;
  param_5 = 0;
  lVar3 = SdpValidateStream(param_1,param_2,(int *)local_res20,&param_5,local_48);
  if (-1 < lVar3) {
    bVar12 = *param_3 != 0;
    uVar10 = local_res20[0];
    if (!bVar12) {
      uVar10 = local_res20[0] + 1;
    }
    plVar5 = (longlong *)SdppAllocatePool(0x10,0x504d5442);
    uVar2 = param_5;
    if (plVar5 != (longlong *)0x0) {
      uVar11 = (ulonglong)uVar10;
      uVar9 = uVar11 * 0x48;
      if ((0xffffffff < uVar9) || (uVar4 = (uint)uVar9 + param_5, uVar4 < (uint)uVar9)) {
        SdpFreePool();
        return -0x3fffff6b;
      }
      p_Var6 = (_SDP_NODE *)SdppAllocatePool((ulonglong)uVar4,0x504d5442);
      if (p_Var6 != (_SDP_NODE *)0x0) {
        p_Var8 = (_SDP_NODE *)0x0;
        if (uVar2 != 0) {
          p_Var8 = p_Var6 + (uVar9 & 0xffffffff);
        }
        *plVar5 = (longlong)p_Var6;
        *(uint *)(plVar5 + 1) = uVar10;
        p_Var7 = p_Var6;
        if (uVar10 != 0) {
          do {
            *(_SDP_NODE **)(p_Var7 + 8) = p_Var7;
            *(_SDP_NODE **)p_Var7 = p_Var7;
            *(longlong **)(p_Var7 + 0x38) = plVar5;
            p_Var7 = p_Var7 + 0x40;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        if (bVar12) {
          p_Var7 = p_Var6;
        }
        else {
          *param_3 = (longlong)p_Var6;
          p_Var7 = p_Var6 + 0x40;
          *(undefined4 *)(p_Var6 + 0x10) = 0x21;
          *(_SDP_NODE **)(p_Var6 + 8) = p_Var6;
          *(_SDP_NODE **)p_Var6 = p_Var6;
        }
        p_Var6 = SdppStreamToNode(param_1,param_2,(_SDP_TREE_ROOT_NODE *)*param_3,p_Var7,
                                  (char *)p_Var8,'\x01');
        if (p_Var6 != (_SDP_NODE *)0x0) {
          return 0;
        }
        if (bVar12) {
          lVar1 = *param_3;
          *(undefined4 *)(lVar1 + 0x10) = 0x21;
          *(longlong *)(lVar1 + 8) = lVar1;
          *(longlong *)lVar1 = lVar1;
        }
        else {
          *param_3 = 0;
        }
        SdpFreePool();
      }
      SdpFreePool();
    }
    lVar3 = -0x3fffff66;
  }
  return lVar3;
}



===== SdpFreeTree @ 18000ec10 =====

undefined8 SdpFreeTree(longlong ****param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(short *)(param_1 + 2) == 0x21) {
    SdppFreeTreeWorker(param_1);
    uVar2 = 0;
    if (param_1[7] != (longlong ***)0x0) {
      iVar1 = SdpInterlockedDecrement((int *)(param_1[7] + 1));
      if (iVar1 != 0) {
        return 0;
      }
      SdpFreePool();
    }
    SdpFreePool();
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== SdppFreeTreeWorker @ 18000ec7c =====

void SdppFreeTreeWorker(longlong ****param_1)

{
  longlong ******pppppplVar1;
  longlong ******pppppplVar2;
  longlong ******pppppplVar3;
  longlong *****ppppplVar4;
  code *pcVar5;
  int iVar6;
  longlong ******local_18;
  longlong *****local_10;
  
  local_18 = (longlong ******)*param_1;
  if (local_18 != (longlong ******)param_1) {
    local_10 = (longlong *****)param_1[1];
    local_18[1] = (longlong *****)&local_18;
    *local_10 = (longlong ****)&local_18;
LAB_18000ecb8:
    if ((longlong *******)local_18 != &local_18) {
      if (((longlong *******)local_18[1] == &local_18) &&
         (pppppplVar2 = (longlong ******)*local_18, (longlong ******)pppppplVar2[1] == local_18)) {
        pppppplVar2[1] = (longlong *****)&local_18;
        if ((*(short *)(local_18 + 2) == 6) || (*(short *)(local_18 + 2) == 7)) {
          pppppplVar1 = local_18 + 4;
          pppppplVar3 = (longlong ******)*pppppplVar1;
          if ((pppppplVar3 != pppppplVar1) && (pppppplVar1 != (longlong ******)0x0)) {
            ppppplVar4 = local_18[5];
            *local_10 = (longlong ****)pppppplVar3;
            pppppplVar3[1] = local_10;
            *ppppplVar4 = (longlong ****)&local_18;
            local_18[5] = (longlong *****)pppppplVar1;
            *pppppplVar1 = (longlong *****)pppppplVar1;
            local_10 = ppppplVar4;
          }
        }
        pppppplVar1 = local_18 + 7;
        local_18 = pppppplVar2;
        if (*pppppplVar1 != (longlong *****)0x0) goto code_r0x00018000ed37;
        goto LAB_18000ed53;
      }
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
    }
    param_1[1] = (longlong ***)param_1;
    *param_1 = (longlong ***)param_1;
  }
  return;
code_r0x00018000ed37:
  iVar6 = SdpInterlockedDecrement((int *)(*pppppplVar1 + 1));
  if (iVar6 == 0) {
    SdpFreePool();
LAB_18000ed53:
    SdpFreePool();
  }
  goto LAB_18000ecb8;
}



===== SdppGetDescriptorFromDescriptorList @ 18000ed84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl SdppGetDescriptorFromDescriptorList(struct _SDP_NODE * __ptr64,struct _GUID const &
   __ptr64,struct _SDP_NODE * __ptr64 * __ptr64) */

long __cdecl
SdppGetDescriptorFromDescriptorList(_SDP_NODE *param_1,_GUID *param_2,_SDP_NODE **param_3)

{
  _SDP_NODE *p_Var1;
  uint uVar2;
  long lVar3;
  _SDP_NODE *p_Var4;
  undefined1 auStack_58 [32];
  longlong local_38;
  longlong lStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  *param_3 = (_SDP_NODE *)0x0;
  p_Var4 = *(_SDP_NODE **)(param_1 + 0x20);
  uVar2 = -(uint)(*(short *)(param_1 + 0x10) != 6) & 0xc0000186;
  if (*(short *)(param_1 + 0x10) == 6) {
    for (; p_Var4 != param_1 + 0x20; p_Var4 = *(_SDP_NODE **)p_Var4) {
      if (((*(short *)(p_Var4 + 0x10) != 6) ||
          (p_Var1 = *(_SDP_NODE **)(p_Var4 + 0x20), p_Var1 == p_Var4 + 0x20)) ||
         (*(short *)(p_Var1 + 0x10) != 3)) {
        return -0x3ffffe7a;
      }
      local_38 = 0;
      lStack_30 = 0;
      lVar3 = 0;
      SdpNormalizeUuid((longlong)p_Var1,(int *)&local_38);
      if ((local_38 == *(longlong *)param_2) && (lStack_30 == *(longlong *)(param_2 + 8))) {
        if (p_Var4 != (_SDP_NODE *)0x0) {
          *param_3 = p_Var4;
          return lVar3;
        }
        break;
      }
    }
    uVar2 = 0xc0000225;
  }
  return uVar2;
}



===== SdpGetElementSize @ 18000ee68 =====

int SdpGetElementSize(uint *param_1,char param_2,byte param_3)

{
  uint local_res10 [4];
  int local_res20 [2];
  
  local_res10[0] = 0;
  local_res20[0] = 0;
  if (param_2 == '\0') {
LAB_18000eeb2:
    local_res20[0] = 0;
  }
  else {
    if (((param_2 == '\x01') || (param_2 == '\x02')) || (param_2 == '\x03')) {
      return *(int *)(&g_IndexToDataSize + (ulonglong)param_3 * 4);
    }
    if (param_2 != '\x04') {
      if (param_2 == '\x05') {
        return 1;
      }
      if (((param_2 != '\x06') && (param_2 != '\a')) && (param_2 != '\b')) goto LAB_18000eeb2;
    }
    SdpRetrieveVariableSize(param_1,param_3,local_res10,local_res20);
    local_res20[0] = local_res20[0] + local_res10[0];
  }
  return local_res20[0];
}



===== SdpGetProfileDescriptorFromDescriptorList @ 18000eef0 =====

void SdpGetProfileDescriptorFromDescriptorList
               (_SDP_NODE *param_1,_GUID *param_2,_SDP_NODE **param_3)

{
  SdppGetDescriptorFromDescriptorList(param_1,param_2,param_3);
  return;
}



===== SdpNormalizeUuid @ 18000ef08 =====

void SdpNormalizeUuid(longlong param_1,int *param_2)

{
  short sVar1;
  undefined8 uVar2;
  uint uVar3;
  
  sVar1 = *(short *)(param_1 + 0x12);
  if (sVar1 == 0x430) {
    uVar2 = *(undefined8 *)(param_1 + 0x28);
    *(undefined8 *)param_2 = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(param_2 + 2) = uVar2;
    return;
  }
  param_2[0] = 0;
  param_2[1] = 0x10000000;
  param_2[2] = -0x7fffff80;
  param_2[3] = -0x4cb64a1;
  if (sVar1 == 0x220) {
    uVar3 = *(uint *)(param_1 + 0x20);
  }
  else {
    uVar3 = (uint)*(ushort *)(param_1 + 0x20);
  }
  *param_2 = *param_2 + uVar3;
  return;
}



===== SdpValidateStream @ 18000ef4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long SdpValidateStream(byte *param_1,int param_2,int *param_3,uint *param_4,longlong *param_5)

{
  long lVar1;
  byte bVar2;
  uint uVar3;
  uint *puVar4;
  byte *pbVar5;
  longlong lVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  ulonglong uVar10;
  byte bVar11;
  byte bVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined1 auStack_298 [32];
  uint local_278;
  uint local_274;
  uint local_270;
  int *local_268;
  uint *local_260;
  undefined8 local_258;
  int *local_250;
  int *local_248;
  int *local_240;
  undefined4 local_238;
  int local_230 [122];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_298;
  local_258 = 0;
  local_268 = param_3;
  local_260 = param_4;
  memset(local_230,0,0x1e0);
  local_278 = 0;
  local_274 = 0;
  piVar7 = local_230;
  piVar8 = local_230;
  local_240 = local_230;
  local_238 = 0x14;
  local_248 = piVar7;
  pbVar5 = param_1;
  local_250 = piVar8;
  do {
    uVar14 = param_2 - 1;
    puVar4 = (uint *)(pbVar5 + 1);
    bVar11 = *pbVar5 >> 3;
    bVar2 = *pbVar5 & 7;
    if (param_3 != (int *)0x0) {
      *param_3 = *param_3 + 1;
    }
    if ((uVar14 == 0) && (bVar11 != 0)) goto LAB_18000f27b;
    if (bVar11 == 0) {
      if (bVar2 != 0) goto LAB_18000f27b;
      uVar13 = 0;
LAB_18000f20f:
      if (uVar14 < (uint)uVar13) {
        if (param_5 != (longlong *)0x0) {
          lVar6 = (longlong)puVar4 - (longlong)param_1;
LAB_18000f286:
          *param_5 = lVar6;
        }
LAB_18000f289:
        if (piVar7 != local_240) {
          SdpFreePool();
        }
        return -0x3ffffff3;
      }
    }
    else {
      if ((bVar11 == 1) || (bVar11 == 2)) {
        if ((bVar2 != 0) && (((bVar2 != 1 && (bVar2 != 2)) && (bVar2 != 3)))) {
LAB_18000f1de:
          if (bVar2 != 4) goto LAB_18000f27b;
        }
LAB_18000f1e4:
        uVar13 = (ulonglong)*(uint *)(&g_IndexToDataSize + (ulonglong)bVar2 * 4);
        goto LAB_18000f20f;
      }
      if (bVar11 == 3) {
        if ((bVar2 != 1) && (bVar2 != 2)) goto LAB_18000f1de;
        goto LAB_18000f1e4;
      }
      if (bVar11 != 4) {
        if (bVar11 == 5) {
          if (bVar2 == 0) {
            uVar13 = 1;
            goto LAB_18000f20f;
          }
          if (param_5 == (longlong *)0x0) goto LAB_18000f289;
          lVar6 = (longlong)puVar4 + (1 - (longlong)param_1);
          goto LAB_18000f286;
        }
        if (((bVar11 != 6) && (bVar11 != 7)) && (bVar11 != 8)) goto LAB_18000f27b;
      }
      if (bVar2 < 5) {
LAB_18000f27b:
        if (param_5 == (longlong *)0x0) goto LAB_18000f289;
        lVar6 = (longlong)puVar4 + (-1 - (longlong)param_1);
        goto LAB_18000f286;
      }
      bVar12 = '\x01' << (bVar2 - 5 & 0x1f);
      local_270 = (uint)bVar12;
      if (uVar14 < local_270) goto LAB_18000f27b;
      SdpRetrieveVariableSize(puVar4,bVar2,&local_278,(int *)&local_274);
      uVar10 = (ulonglong)local_278;
      uVar3 = uVar14 - local_270;
      if (uVar3 < local_278) {
        if (bVar12 == 1) {
          if (uVar3 < 0x100) {
            *(byte *)puVar4 = (byte)uVar3;
LAB_18000f0e3:
            uVar10 = (ulonglong)uVar3;
            piVar7 = local_248;
            local_278 = uVar3;
          }
        }
        else if ((bVar12 == 2) && (uVar3 < 0x10000)) {
          pbVar5[2] = (byte)uVar3;
          *(char *)puVar4 = (char)(uVar3 >> 8);
          goto LAB_18000f0e3;
        }
      }
      uVar13 = (ulonglong)local_274;
      iVar9 = (int)uVar10;
      if (((ulonglong)uVar14 < uVar10 + uVar13) || (0xffffffff < uVar10 + uVar13))
      goto LAB_18000f27b;
      if ((bVar11 - 4 & 0xfb) == 0) {
        if (local_260 != (uint *)0x0) {
          uVar3 = (~-(uint)((uVar10 & 7) != 0) & 8) + *local_260 + (iVar9 + 7U & 0xfffffff8);
          if (uVar3 < *local_260) {
            if (param_5 != (longlong *)0x0) {
              *param_5 = (longlong)puVar4 + (-1 - (longlong)param_1);
            }
            if (piVar7 != local_240) {
              SdpFreePool();
            }
            return -0x3fffff6b;
          }
          *local_260 = uVar3;
        }
        uVar13 = (ulonglong)(local_274 + iVar9);
      }
      else if ((iVar9 != 0) && (uVar3 = local_274 + iVar9, uVar14 != uVar3)) {
        lVar1 = SdpStack::Push((SdpStack *)&local_258,(_SDP_NODE *)0x0,(uVar14 - local_274) - iVar9,
                               (_LIST_ENTRY *)0x0);
        if (lVar1 < 0) {
          if (local_248 != local_240) {
            SdpFreePool();
          }
          return lVar1;
        }
        piVar7 = local_248;
        uVar14 = uVar3;
      }
      piVar8 = local_250;
    }
    pbVar5 = (byte *)((longlong)puVar4 + uVar13);
    param_2 = uVar14 - (int)uVar13;
    while (param_3 = local_268, param_2 == 0) {
      if (piVar8 == piVar7) {
        if (piVar7 != local_240) {
          SdpFreePool();
        }
        return 0;
      }
      piVar8 = piVar8 + -6;
      local_250 = piVar8;
      param_2 = *piVar8;
    }
  } while( true );
}



===== SdpFindAttributeInTree @ 18000f2d0 =====

undefined8 SdpFindAttributeInTree(longlong *param_1,short param_2,undefined8 *param_3)

{
  short sVar1;
  bool bVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)*param_1;
  bVar2 = false;
  *param_3 = 0;
  if (plVar5 != param_1) {
    if ((short)plVar5[2] != 6) {
      return 0xc000000d;
    }
    plVar5 = plVar5 + 4;
    plVar4 = (longlong *)*plVar5;
    if (plVar4 != plVar5) {
      do {
        plVar4 = (longlong *)*plVar4;
        bVar2 = (bool)(bVar2 ^ 1);
      } while (plVar4 != plVar5);
      if (bVar2) {
        return 0xc000000d;
      }
      puVar3 = (undefined8 *)*plVar5;
      sVar1 = *(short *)(puVar3 + 2);
      do {
        if (sVar1 != 1) {
          return 0xc000000d;
        }
        if (*(short *)((longlong)puVar3 + 0x12) != 0x110) {
          return 0xc000000d;
        }
        if (*(int *)(puVar3 + 3) != 2) {
          return 0xc000000d;
        }
        if (*(short *)(puVar3 + 4) == param_2) {
          *param_3 = (longlong *)*puVar3;
          return 0;
        }
        puVar3 = *(undefined8 **)*puVar3;
        sVar1 = *(short *)(puVar3 + 2);
      } while (sVar1 != 0x21);
    }
  }
  return 0xc0000225;
}



===== SdpTreeFromStream @ 18000f35c =====

void SdpTreeFromStream(byte *param_1,ulong param_2,longlong *param_3,undefined8 param_4)

{
  uint in_stack_ffffffffffffffe8;
  
  SdpTreeFromStream_P(param_1,param_2,param_3,param_4,in_stack_ffffffffffffffe8);
  return;
}



===== Push @ 18000f374 =====

/* public: long __cdecl SdpStack::Push(struct _SDP_NODE * __ptr64,unsigned long,struct _LIST_ENTRY *
   __ptr64) __ptr64 */

long __thiscall SdpStack::Push(SdpStack *this,_SDP_NODE *param_1,ulong param_2,_LIST_ENTRY *param_3)

{
  uint uVar1;
  void *_Src;
  void *_Dst;
  ulong *puVar2;
  
  puVar2 = *(ulong **)(this + 8);
  if (puVar2 == (ulong *)(*(longlong *)(this + 0x10) + (ulonglong)*(uint *)(this + 0x20) * 0x18)) {
    _Dst = (void *)SdppAllocatePool((ulonglong)(*(uint *)(this + 0x20) * 2) * 0x18,0x4c706453);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    uVar1 = *(uint *)(this + 0x20);
    _Src = *(void **)(this + 0x10);
    memmove(_Dst,_Src,(ulonglong)uVar1 * 0x18);
    puVar2 = (ulong *)((ulonglong)uVar1 * 0x18 + (longlong)_Dst);
    *(ulong **)(this + 8) = puVar2;
    if (_Src != *(void **)(this + 0x18)) {
      SdpFreePool();
      puVar2 = *(ulong **)(this + 8);
    }
    *(void **)(this + 0x10) = _Dst;
    *(int *)(this + 0x20) = *(int *)(this + 0x20) * 2;
  }
  *puVar2 = param_2;
  *(_SDP_NODE **)(*(longlong *)(this + 8) + 8) = param_1;
  *(_LIST_ENTRY **)(*(longlong *)(this + 8) + 0x10) = param_3;
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 0x18;
  if (*(longlong *)this <
      (*(longlong *)(this + 8) - *(longlong *)(this + 0x10) >> 3) * -0x5555555555555555) {
    *(longlong *)this = *(longlong *)this + 1;
  }
  return 0;
}



===== entry @ 180011010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 180011044 =====

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



===== wil_InitializeFeatureStaging @ 180011078 =====

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
    for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
        ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1800110ff;
    }
LAB_180011139:
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
LAB_1800110ff:
  if (ppuVar3 == (undefined **)0x0) goto LAB_180011139;
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
    goto LAB_180011139;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_180009cff < ppuVar3) goto LAB_180011139;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1800110ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 18001118c =====

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
  ppuVar4 = &wil_details_featureDescriptors_a;
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
            if (&UNK_180009cff < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_180011276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_180011276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_180011276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_180009cff < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


