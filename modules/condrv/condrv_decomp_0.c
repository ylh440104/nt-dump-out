
===== RtlStringCbPrintfW @ 140001010 =====

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
      param_1[uVar2] = L'\0';
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 == uVar2) {
      param_1[uVar2] = L'\0';
      return 0;
    }
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== CdpCancelIoIrp @ 1400010b0 =====

void CdpCancelIoIrp(undefined8 param_1,longlong param_2)

{
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  CdpCancelIoIrpPaged(param_2);
  return;
}



===== __report_gsfailure @ 1400010f0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400010fd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== Feature_3237903672__private_IsEnabledDeviceUsageNoInline @ 140001110 =====

ulonglong Feature_3237903672__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_3237903672__private_featureState;
  if ((Feature_3237903672__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3237903672__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3237903672__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3237903672__private_IsEnabledFallback @ 140001148 =====

void Feature_3237903672__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140001160 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140001238 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000131c =====

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
LAB_140001474:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140001467:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140001474;
      if (uVar5 == 5) goto LAB_140001467;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000149c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

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
              (0x3c3616e,&Feature_3237903672_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140001518 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

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
                     (local_50,(uint *)&Feature_3237903672__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3c3616e,param_3 & 0xffffffff,1,&Feature_3237903672__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3c3616e);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140001604 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140001714 =====

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
  if ((Feature_3237903672__private_featureState & 2) != 0) {
    uVar1 = Feature_3237903672__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3237903672__private_featureState;
      if (bVar3) {
        Feature_3237903672__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3237903672__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 140001768 =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 1400018c8 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_3237903672__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_3237903672__private_featureState,(ulonglong)param_1,
                             0x140005818);
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



===== wil_details_MapReportingKind @ 140001958 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 1400019f8 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000584f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140001a20 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001b80 =====

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



===== CdpCancelKernelConnectionQueuedIrp @ 140001c10 =====

void CdpCancelKernelConnectionQueuedIrp(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar1 + 0xd8,0);
  *(longlong *)(lVar1 + 0x100) = *(longlong *)(lVar1 + 0x100) + -1;
  plVar5 = (longlong *)(param_2 + 0xa8);
  lVar2 = *plVar5;
  if ((*(longlong **)(lVar2 + 8) != plVar5) ||
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 != plVar5)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  if ((*(longlong *)(lVar1 + 0x100) == 0) && (*(longlong *)(lVar1 + 0xe8) != 0)) {
    IoCancelIrp();
  }
  ExReleasePushLockExclusiveEx(lVar1 + 0xd8,0);
  KeLeaveCriticalRegion();
  *(longlong **)(param_2 + 0xb0) = plVar5;
  *plVar5 = (longlong)plVar5;
  return;
}



===== CdpCancelReadIoIrp @ 140001cf0 =====

void CdpCancelReadIoIrp(undefined8 param_1,longlong param_2)

{
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  CdpCancelReadIoIrpPaged(param_2);
  return;
}



===== _guard_check_icall @ 140001d30 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140001d48 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001d6c =====

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



===== __GSHandlerCheck_SEH @ 140001dd4 =====

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



===== __cpu_features_init @ 140001e70 =====

/* WARNING: Removing unreachable block (ram,0x000140001eda) */
/* WARNING: Removing unreachable block (ram,0x000140001e89) */
/* WARNING: Removing unreachable block (ram,0x000140001e7a) */

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



===== __security_check_cookie @ 140001f40 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140001f80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140001fb0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001fb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140001fe0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002040 =====

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



===== memset @ 140002340 =====

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



===== __memset_repmovs @ 140002480 =====

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



===== __memset_query @ 140002500 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002580 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400026c0 =====

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



===== __memset_spec_plain @ 140002740 =====

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



===== CdAccessCheck @ 14000a010 =====

undefined4 CdAccessCheck(longlong param_1,longlong *param_2,undefined8 param_3,undefined1 param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  int local_res8 [2];
  undefined4 local_res18 [2];
  undefined4 local_28 [4];
  
  local_28[0] = 0;
  local_res8[0] = 0;
  local_res18[0] = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1 + 0x28,0);
  cVar1 = SeAccessCheck(*(undefined8 *)(param_1 + 0x38),param_2,0,0x120089,0,0,&CdpGenericMapping,
                        param_4,local_28,local_res18);
  if (cVar1 == '\0') {
    if ((*(uint *)(param_1 + 0x30) & 1) == 0) goto LAB_14000a0eb;
    lVar3 = *param_2;
    if (lVar3 == 0) {
      lVar3 = param_2[2];
    }
    iVar2 = SeQueryInformationToken(lVar3,0x1a,local_res8);
    if ((iVar2 < 0) || (local_res8[0] == 0)) goto LAB_14000a0eb;
  }
  local_res18[0] = 0;
LAB_14000a0eb:
  ExReleasePushLockSharedEx(param_1 + 0x28,0);
  KeLeaveCriticalRegion();
  return local_res18[0];
}



===== CdpCreateBrokerConnectionIo @ 14000a130 =====

int CdpCreateBrokerConnectionIo(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong *local_res10;
  
  plVar7 = (longlong *)0x0;
  local_res10 = (longlong *)0x0;
  lVar3 = CdpGetRequestorProcess(param_1);
  if (lVar3 == 0) {
    iVar2 = -0x3ffffff5;
  }
  else {
    if (*(longlong *)(param_1 + 0x98) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = PsGetThreadId();
    }
    puVar5 = CdFindBroker();
    if (puVar5 == (undefined8 *)0x0) {
      iVar2 = -0x3fffff80;
    }
    else {
      uVar6 = CdAllocateMdlForEaBufferItem((longlong *)&local_res10,param_1,"broker");
      plVar7 = local_res10;
      iVar2 = (int)uVar6;
      if (-1 < iVar2) {
        lVar1 = *(longlong *)(param_1 + 0xb8);
        *(code **)(lVar1 + -0x10) = CdpCompleteBrokerConnection;
        *(undefined8 **)(lVar1 + -8) = puVar5;
        *(undefined1 *)(lVar1 + -0x45) = 0xe0;
        uVar6 = PsGetProcessId(lVar3);
        CdInitializeIo(param_1,puVar5 + 5,1,uVar6,uVar4,plVar7,0);
        iVar2 = CdAddIoToPipe(param_1,0);
        if (-1 < iVar2) {
          return 0x103;
        }
      }
      CdDereferenceBroker((longlong)puVar5);
    }
  }
  CdFreeMdlChain(plVar7);
  *(int *)(param_1 + 0x30) = iVar2;
  *(undefined8 *)(param_1 + 0x38) = 0;
  IofCompleteRequest(param_1,0);
  return iVar2;
}



===== CdCompleteBrokerIoWithServer @ 14000a274 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CdCompleteBrokerIoWithServer
                    (undefined8 param_1,ulonglong *param_2,longlong param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_c8 [32];
  longlong *local_a8;
  undefined8 local_a0;
  longlong local_98;
  ulonglong local_90;
  undefined4 local_88;
  undefined4 local_84;
  longlong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeStackAttachProcess(param_4,&local_68);
  local_a0 = 0;
  local_98 = 0;
  local_a8 = &local_98;
  uVar2 = ObReferenceObjectByHandle(param_1,0,*(undefined8 *)IoFileObjectType_exref,1);
  uVar4 = (ulonglong)uVar2;
  KeUnstackDetachProcess(&local_68);
  if (-1 < (int)uVar2) {
    puVar1 = *(undefined8 **)(local_98 + 0x18);
    if (((*(longlong *)(local_98 + 8) != CdDeviceObject) || (puVar1 == (undefined8 *)0x0)) ||
       ((undefined *)*puVar1 != &CdBrokerType)) {
      ObfDereferenceObject();
      return 0xc000000d;
    }
    local_84 = 0;
    local_90 = *param_2;
    local_88 = 0;
    local_78 = 0;
    uStack_70 = 0;
    LOCK();
    *(longlong *)(param_3 + 0x18) = *(longlong *)(param_3 + 0x18) + 1;
    UNLOCK();
    local_80 = param_3;
    uVar3 = CdCompleteIo(puVar1 + 5,'\0',&local_90,0x28);
    uVar4 = uVar3 & 0xffffffff;
    ObfDereferenceObject(local_98);
    if (-1 < (int)uVar3) {
      return 0;
    }
    CdDereferenceServer(param_3);
  }
  return uVar4;
}



===== CdCreateBroker @ 14000a3c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 CdCreateBroker(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  char cVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined4 local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  lVar1 = *(longlong *)(param_1 + 0xb8);
  local_38[0] = 0;
  local_30 = 1;
  local_2c = 1;
  local_28 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x28);
  local_20 = 0;
  cVar3 = SePrivilegeCheck(&local_30,*(longlong *)(*(longlong *)(lVar1 + 8) + 8) + 0x20,
                           *(undefined1 *)(param_1 + 0x40));
  if (cVar3 == '\0') {
    uVar8 = 0xc0000061;
  }
  else {
    puVar4 = (undefined8 *)ExAllocatePool2(0x101,0xa8,0x72426443);
    if (puVar4 != (undefined8 *)0x0) {
      puVar4[3] = 1;
      *puVar4 = &CdBrokerType;
      puVar4[4] = 0;
      CdInitializeIoPipe(puVar4 + 5,puVar4 + 4);
      lVar5 = PsGetCurrentServerSilo();
      puVar4[0x14] = lVar5;
      if (lVar5 != 0) {
        ObfReferenceObjectWithTag(lVar5,0x6f6c7342);
      }
      puVar9 = auStack_58;
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(&CdpBrokerListLock,0);
      if ((undefined8 **)CdpBrokerList == &CdpBrokerList) {
        local_38[0] = 0x40000006;
        RtlSetSystemGlobalData(0xe,local_38);
      }
      puVar6 = puVar4 + 1;
      puVar7 = CdpBrokerList;
      if ((undefined8 **)CdpBrokerList[1] != &CdpBrokerList) {
        puVar7 = (undefined8 *)0x3;
        pcVar2 = (code *)swi(0x29);
        puVar6 = (undefined8 *)(*pcVar2)();
        puVar9 = auStack_50;
      }
      *puVar6 = puVar7;
      puVar6[1] = &CdpBrokerList;
      puVar7[1] = puVar6;
      *(undefined8 *)(puVar9 + -8) = 0x14000a563;
      CdpBrokerList = puVar6;
      ExReleasePushLockExclusiveEx(&CdpBrokerListLock,0);
      *(undefined8 *)(puVar9 + -8) = 0x14000a56f;
      KeLeaveCriticalRegion();
      *(undefined8 **)(*(longlong *)(lVar1 + 0x30) + 0x18) = puVar4;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x38) = 0;
      *(undefined8 *)(puVar9 + -8) = 0x14000a591;
      IofCompleteRequest(param_1,0);
      uVar8 = 0;
      goto LAB_14000a598;
    }
    uVar8 = 0xc000009a;
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = uVar8;
  IofCompleteRequest(param_1,0);
  puVar9 = auStack_58;
LAB_14000a598:
  *(undefined8 *)(puVar9 + -8) = 0x14000a5a5;
  return uVar8;
}



===== CdDereferenceBroker @ 14000a5c4 =====

void CdDereferenceBroker(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  byte bVar5;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x18);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if (lVar2 < 2) {
    bVar5 = KeGetCurrentIrql();
    if (bVar5 < 2) {
      KeEnterCriticalRegion();
    }
    ExAcquirePushLockExclusiveEx(&CdpBrokerListLock,0);
    plVar1 = (longlong *)(param_1 + 8);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) != plVar1) ||
       (plVar3 = *(longlong **)(param_1 + 0x10), (longlong *)*plVar3 != plVar1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    if ((undefined8 **)CdpBrokerList == &CdpBrokerList) {
      local_res8[0] = 0x80000006;
      RtlSetSystemGlobalData(0xe,local_res8);
    }
    ExReleasePushLockExclusiveEx(&CdpBrokerListLock,0);
    if (bVar5 < 2) {
      KeLeaveCriticalRegion();
    }
    if (*(longlong *)(param_1 + 0xa0) != 0) {
      ObfDereferenceObjectWithTag(*(longlong *)(param_1 + 0xa0),0x6f6c7342);
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== CdFindBroker @ 14000a6e8 =====

undefined8 * CdFindBroker(void)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  bool bVar6;
  
  lVar2 = PsGetCurrentServerSilo();
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&CdpBrokerListLock,0);
  for (puVar4 = CdpBrokerList; (undefined8 **)puVar4 != &CdpBrokerList;
      puVar4 = (undefined8 *)*puVar4) {
    puVar5 = puVar4 + -1;
    if (puVar4[0x13] == lVar2) {
      lVar3 = puVar4[2];
      while (lVar3 != 0) {
        LOCK();
        lVar1 = puVar4[2];
        bVar6 = lVar3 == lVar1;
        if (bVar6) {
          puVar4[2] = lVar3 + 1;
        }
        else {
          lVar3 = lVar1;
        }
        UNLOCK();
        if (bVar6) goto LAB_14000a760;
      }
    }
  }
  puVar5 = (undefined8 *)0x0;
LAB_14000a760:
  ExReleasePushLockExclusiveEx(&CdpBrokerListLock,0);
  KeLeaveCriticalRegion();
  return puVar5;
}



===== CdpBrokerCleanup @ 14000a7a0 =====

undefined8 CdpBrokerCleanup(longlong param_1,longlong param_2)

{
  CdDisconnectIoPipe((undefined8 *)(param_1 + 0x28));
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CdpBrokerClose @ 14000a7e0 =====

undefined8 CdpBrokerClose(longlong param_1,longlong param_2)

{
  CdDereferenceBroker(param_1);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CdpBrokerFastIoctl @ 14000a820 =====

ulonglong CdpBrokerFastIoctl(longlong param_1,ulonglong *param_2,int param_3,undefined8 param_4,
                            undefined8 param_5,int param_6,undefined4 *param_7)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  
  *(longlong *)(param_7 + 2) = 0;
  if (param_6 == 0x500006) {
    uVar3 = 0;
    if (param_3 != 0) {
      if (param_3 != 0x28) {
        *param_7 = 0xc0000206;
        uVar3 = 0;
        goto LAB_14000a879;
      }
      cVar1 = ExGetPreviousMode();
      uVar3 = CdpCompleteBrokerIo(param_1,cVar1,param_2,0x28);
    }
LAB_14000a8f1:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    if (param_6 == 0x50000b) {
      cVar1 = ExGetPreviousMode();
      uVar3 = CdpCompleteBrokerIo(param_1,cVar1,param_2,param_3);
    }
    else {
      uVar2 = param_6 - 0x50000f;
      uVar3 = (ulonglong)uVar2;
      if (uVar2 != 0) {
        if (uVar2 == 0xc) {
          uVar3 = CdDisconnectIoPipe((undefined8 *)(param_1 + 0x28));
          *param_7 = 0;
          goto LAB_14000a879;
        }
        goto LAB_14000a8f1;
      }
      cVar1 = ExGetPreviousMode();
      uVar3 = CdReadIoInput((undefined8 *)(param_1 + 0x28),cVar1,param_2,param_3,
                            (longlong *)(param_7 + 2));
    }
    *param_7 = (int)uVar3;
LAB_14000a879:
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}



===== CdpBrokerIoctl @ 14000a920 =====

ulonglong CdpBrokerIoctl(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x500006) {
    uVar1 = CdReadNextIo((undefined8 *)(param_1 + 0x28),param_2);
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    uVar1 = 0xc0000010;
  }
  return uVar1;
}



===== CdpCompleteBrokerIo @ 14000a970 =====

ulonglong CdpCompleteBrokerIo(longlong param_1,char param_2,ulonglong *param_3,int param_4)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 in_register_0000008c;
  longlong local_38;
  ulonglong local_30;
  ulonglong uStack_28;
  undefined8 *local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  if (param_4 == 0x28) {
    if (param_2 == '\0') {
      local_30 = *param_3;
      uStack_28 = param_3[1];
      local_20 = (undefined8 *)param_3[2];
    }
    else {
      if (((ulonglong)param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_30 = *param_3;
      uStack_28 = param_3[1];
      local_20 = (undefined8 *)param_3[2];
    }
    uStack_18 = 0;
    local_10 = 0;
    if ((int)uStack_28 < 0) {
      uVar2 = CdCompleteIo((undefined8 *)(param_1 + 0x28),'\0',&local_30,0x28);
    }
    else {
      local_38 = 0;
      uVar2 = ObReferenceObjectByHandle
                        (local_20,0,*(undefined8 *)IoFileObjectType_exref,
                         CONCAT71((int7)(CONCAT44(in_register_0000008c,param_4) >> 8),param_2),
                         &local_38,0);
      if (-1 < (int)uVar2) {
        puVar1 = *(undefined8 **)(local_38 + 0x18);
        if (((*(longlong *)(local_38 + 8) == CdDeviceObject) && (puVar1 != (undefined8 *)0x0)) &&
           ((undefined *)*puVar1 == &CdServerType)) {
          LOCK();
          puVar1[3] = puVar1[3] + 1;
          UNLOCK();
          local_20 = puVar1;
          uVar3 = CdCompleteIo((undefined8 *)(param_1 + 0x28),'\0',&local_30,0x28);
          uVar2 = uVar3 & 0xffffffff;
          ObfDereferenceObject(local_38);
          if ((int)uVar3 < 0) {
            CdDereferenceServer((longlong)puVar1);
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          ObfDereferenceObject();
          uVar2 = 0xc000000d;
        }
      }
    }
  }
  else {
    uVar2 = 0xc0000206;
  }
  return uVar2;
}



===== CdpClientFlushBuffers @ 14000ab00 =====

int CdpClientFlushBuffers(longlong param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  longlong local_18;
  longlong lStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lStack_10 = 0;
  uVar2 = CdpGetClientTarget(param_1,param_2,&local_28);
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    CdInitializeIo(param_2,local_18 + 0x40,8,local_28,uStack_20,0,0);
    uVar2 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      lVar3 = 0;
    }
    else {
      lVar3 = lStack_10;
    }
    iVar1 = CdAddIoToPipe(param_2,lVar3);
    uVar2 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar2 == 0) && (lStack_10 != 0)) {
      ObfDereferenceObject(lStack_10);
    }
    if (-1 < iVar1) {
      return 0x103;
    }
  }
  uVar2 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 != 0) && (lStack_10 != 0)) {
    ObfDereferenceObject(lStack_10);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = iVar1;
  IofCompleteRequest(param_2,0);
  return iVar1;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14000abf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== CdpDispatchSetSecurity @ 14000acc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CdpDispatchSetSecurity(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((lVar1 == 0) || (puVar2 = *(undefined8 **)(lVar1 + 0x18), puVar2 == (undefined8 *)0x0)) ||
     (puVar3 = (uint *)*puVar2, puVar3 == (uint *)0x0)) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc000000d;
  }
  else if (*(code **)(puVar3 + 0x12) == (code *)0x0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc00000bb;
  }
  else {
    uVar4 = (**(code **)(puVar3 + 0x12))((longlong)puVar2 - (ulonglong)*puVar3,param_2);
  }
  return uVar4;
}



===== CdpUnload @ 14000ad60 =====

void CdpUnload(longlong param_1)

{
  IoDeleteDevice(*(undefined8 *)(param_1 + 8));
  wil_UninitializeFeatureStaging();
  return;
}



===== wil_UninitializeFeatureStaging @ 14000ad88 =====

void wil_UninitializeFeatureStaging(void)

{
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000ade0 =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3[0] = 0;
    param_3[1] = 0;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)(param_2 + 4) & 0x40) << 2 | *(uint *)(param_2 + 4) & 0xb0) << 3 | 0x206;
      goto LAB_14000ae3d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000ae3d;
    }
  }
  uVar1 = 0x206;
LAB_14000ae3d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000ae48 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_3237903672__private_descriptor);
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &Feature_3237903672__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000af00 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 >> 9 & 1) != 0) {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,uVar1,param_2);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000af38 =====

uint wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
               (uint *param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 >> 6 & 1;
  if ((uVar5 != 0) && (plVar4 = *(longlong **)(param_3 + 0x20), plVar4 != (longlong *)0x0)) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)*plVar4;
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000afba;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000afba;
        }
        uVar5 = 1;
        plVar4 = plVar4 + 1;
      }
      uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        ((uint *)*puVar1,(longlong)puVar1);
      if ((uVar5 == 0) || ((uVar2 & 1) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      plVar4 = plVar4 + 1;
    } while (uVar5 != 0);
  }
LAB_14000afba:
  do {
    uVar2 = param_2 & 0xffffffce;
    if ((param_2 & 1) == uVar5) {
      uVar2 = param_2 & 0xfffffffe;
    }
    uVar3 = uVar2 & 0xfffffdff | uVar5;
    LOCK();
    uVar2 = *param_1;
    bVar6 = param_2 == uVar2;
    if (bVar6) {
      *param_1 = uVar3;
    }
    else {
      param_2 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000b010 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &Feature_3237903672__private_descriptor;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000b070 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000b08c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &Feature_3237903672__private_descriptor;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) break;
    if (((*(char *)((longlong)plVar2 + 0x1d) == '\0') &&
        (*(char *)((longlong)plVar2 + 0x1e) == '\0')) &&
       (*(char *)((longlong)plVar2 + 0x1c) == '\0')) {
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      iVar1 = RtlQueryFeatureConfiguration((int)plVar2[3],1,&local_30,&local_28);
      local_38[0] = 0;
      local_38[1] = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,local_38);
      LOCK();
      *(uint *)*plVar2 = *(uint *)*plVar2 ^ (*(uint *)*plVar2 ^ local_38[0]) & 0xf80;
      UNLOCK();
    }
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== CdCreateKernelConnection @ 14000b140 =====

int CdCreateKernelConnection(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  ulonglong uVar5;
  int iVar6;
  uint *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong *plVar10;
  ulonglong *puVar11;
  undefined8 uVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  char cVar15;
  bool bVar16;
  ulonglong local_res8;
  longlong local_res18;
  longlong local_res20;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  longlong local_48;
  
  puVar14 = auStack_68;
  puVar11 = (ulonglong *)0x0;
  uVar8 = 0;
  local_res18 = 0;
  bVar16 = false;
  local_res8 = 0;
  if (*(char *)(param_1 + 0x40) != '\0') {
    iVar6 = -0x3fffffde;
    goto LAB_14000b4a3;
  }
  lVar9 = *(longlong *)(param_1 + 0xb8);
  local_48 = lVar9;
  puVar7 = CdpFindEaBufferItem(*(uint **)(param_1 + 0x18),"attach");
  puVar14 = auStack_68;
  if ((puVar7 == (uint *)0x0) || (*(short *)((longlong)puVar7 + 6) != 8)) {
    iVar6 = -0x3ffffff3;
    bVar16 = false;
LAB_14000b47a:
    if (local_res18 != 0) {
      *(undefined8 *)(puVar14 + -8) = 0x14000b48a;
      CdpFreeKernelConnectionIrp(&local_res18);
    }
  }
  else {
    uVar8 = CdpGetProcessServerFromConnection
                      ((longlong *)&local_res8,param_1,
                       *(longlong *)
                        ((ulonglong)*(byte *)((longlong)puVar7 + 5) + 9 + (longlong)puVar7));
    puVar14 = auStack_68;
    iVar6 = (int)uVar8;
    if (-1 < iVar6) {
      KeEnterCriticalRegion();
      uVar5 = local_res8;
      lVar2 = local_res8 + 0xd8;
      local_res20 = lVar2;
      ExAcquirePushLockExclusiveEx(lVar2,0);
      uVar8 = local_res8;
      puVar14 = auStack_68;
      bVar16 = false;
      if (*(longlong *)(uVar5 + 0xe0) == 0) {
        *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + -0x48;
        *(char *)(param_1 + 0x43) = *(char *)(param_1 + 0x43) + -1;
        *(ulonglong *)(*(longlong *)(param_1 + 0xb8) + 8) = uVar5;
        LOCK();
        *(code **)(param_1 + 0x68) = CdpCancelKernelConnectionQueuedIrp;
        UNLOCK();
        if (*(char *)(param_1 + 0x44) != '\0') {
          LOCK();
          lVar9 = *(longlong *)(param_1 + 0x68);
          *(longlong *)(param_1 + 0x68) = 0;
          UNLOCK();
          if (lVar9 != 0) {
            *(char *)(param_1 + 0x43) = *(char *)(param_1 + 0x43) + '\x01';
            iVar6 = -0x3ffffee0;
            *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 0x48;
            goto LAB_14000b436;
          }
        }
        lVar9 = *(longlong *)(local_res8 + 0x100) + 1;
        *(longlong *)(local_res8 + 0x100) = lVar9;
        bVar16 = lVar9 == 1;
        if (bVar16) {
          *(undefined8 *)(local_res8 + 0x100) = 2;
        }
        plVar3 = (longlong *)(local_res8 + 0xf0);
        plVar13 = *(longlong **)(local_res8 + 0xf8);
        plVar10 = (longlong *)(param_1 + 0xa8);
        puVar14 = auStack_68;
        if ((longlong *)*plVar13 != plVar3) {
          plVar13 = (longlong *)0x3;
          pcVar4 = (code *)swi(0x29);
          plVar10 = (longlong *)(*pcVar4)();
          puVar14 = auStack_60;
        }
        plVar10[1] = (longlong)plVar13;
        *plVar10 = (longlong)plVar3;
        *plVar13 = (longlong)plVar10;
        *(longlong **)(uVar8 + 0xf8) = plVar10;
        *(undefined8 *)(puVar14 + -8) = 0x14000b2e6;
        ExReleasePushLockExclusiveEx(lVar2,0);
        *(undefined8 *)(puVar14 + -8) = 0x14000b2f2;
        KeLeaveCriticalRegion();
        local_res8 = local_res8 & 0xffffffffffffff00;
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        if (!bVar16) {
          iVar6 = 0x103;
          goto LAB_14000b48a;
        }
        *(undefined8 *)(puVar14 + -8) = 0x14000b328;
        puVar11 = (ulonglong *)ExAllocatePool2(0x40,0x10,0x63436443);
        if (puVar11 == (ulonglong *)0x0) {
          iVar6 = -0x3fffff66;
LAB_14000b3f0:
          cVar15 = '\x01';
          *(undefined8 *)(puVar14 + -8) = 0x14000b3fa;
          KeEnterCriticalRegion();
          *(undefined8 *)(puVar14 + -8) = 0x14000b40f;
          ExAcquirePushLockExclusiveEx(uVar8 + 0xd8,0);
LAB_14000b414:
          *(longlong *)(uVar8 + 0x100) = *(longlong *)(uVar8 + 0x100) + -1;
          if (iVar6 < 0) {
            *(undefined8 *)(uVar8 + 0xe8) = 0;
            *(undefined8 *)(puVar14 + -8) = 0x14000b431;
            CdpCompleteServerKernelConnectionQueue(uVar8,iVar6);
          }
          if (cVar15 != '\0') goto LAB_14000b436;
          goto LAB_14000b457;
        }
        *puVar11 = uVar8;
        *(undefined8 *)(puVar14 + -8) = 0x14000b355;
        uVar12 = CdpAllocateKernelConnectionIrp(param_1,local_48,puVar11,&local_res18);
        iVar6 = (int)uVar12;
        if (iVar6 < 0) {
          cVar15 = (char)local_res8;
        }
        else {
          *(undefined8 *)(puVar14 + -8) = 0x14000b366;
          KeEnterCriticalRegion();
          *(undefined8 *)(puVar14 + -8) = 0x14000b378;
          ExAcquirePushLockExclusiveEx(local_res20,0);
          lVar9 = local_res18;
          if ((longlong *)*plVar3 == plVar3) {
            *(longlong *)(uVar8 + 0x100) = *(longlong *)(uVar8 + 0x100) + -1;
            iVar6 = -0x3ffffee0;
            goto LAB_14000b436;
          }
          *(longlong *)(uVar8 + 0xe8) = local_res18;
          *(undefined8 *)(puVar14 + -8) = 0x14000b3ac;
          ExReleasePushLockExclusiveEx(local_res20,0);
          *(undefined8 *)(puVar14 + -8) = 0x14000b3b8;
          KeLeaveCriticalRegion();
          *(undefined8 *)(puVar14 + -8) = 0x14000b3cf;
          iVar6 = CdpCreateServerConnectionIo(lVar9,uVar8,puVar11 + 1);
          cVar15 = '\0';
          if (-1 < iVar6) {
            local_res18 = 0;
            puVar11 = (ulonglong *)0x0;
            goto LAB_14000b3f0;
          }
        }
        if (iVar6 != -0x3ffffee0) {
          if (cVar15 == '\0') goto LAB_14000b3f0;
          goto LAB_14000b414;
        }
      }
      else {
        *(longlong *)(uVar5 + 0x100) = *(longlong *)(uVar5 + 0x100) + 1;
        iVar6 = 0;
        *(undefined8 *)(*(longlong *)(lVar9 + 0x30) + 0x18) = *(undefined8 *)(uVar5 + 0xe0);
        *(undefined4 *)(param_1 + 0x30) = 0;
        *(undefined8 *)(param_1 + 0x38) = 0;
        IofCompleteRequest(param_1,0);
        puVar14 = auStack_68;
        uVar8 = uVar5;
LAB_14000b436:
        *(undefined8 *)(puVar14 + -8) = 0x14000b446;
        ExReleasePushLockExclusiveEx(uVar8 + 0xd8,0);
        *(undefined8 *)(puVar14 + -8) = 0x14000b452;
        KeLeaveCriticalRegion();
LAB_14000b457:
        if (puVar11 == (ulonglong *)0x0) goto LAB_14000b47a;
      }
      *(undefined8 *)(puVar14 + -8) = 0x14000b468;
      ExFreePoolWithTag(puVar11,0);
      goto LAB_14000b47a;
    }
    uVar8 = local_res8;
  }
LAB_14000b48a:
  if (uVar8 != 0) {
    *(undefined8 *)(puVar14 + -8) = 0x14000b497;
    CdDereferenceServer(uVar8);
  }
  if (bVar16) {
    return 0x103;
  }
  if (-1 < iVar6) {
    return iVar6;
  }
LAB_14000b4a3:
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(int *)(param_1 + 0x30) = iVar6;
  *(undefined8 *)(puVar14 + -8) = 0x14000b4b8;
  IofCompleteRequest(param_1,0);
  return iVar6;
}



===== CdpAllocateKernelConnectionIrp @ 14000b4dc =====

undefined8
CdpAllocateKernelConnectionIrp
          (longlong param_1,longlong param_2,undefined8 param_3,longlong *param_4)

{
  uint uVar1;
  void *_Src;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  void *_Dst;
  undefined8 uVar5;
  longlong local_res8;
  
  lVar4 = CdDeviceObject;
  _Src = *(void **)(param_1 + 0x18);
  uVar5 = 0;
  uVar1 = *(uint *)(param_2 + 0x20);
  *param_4 = 0;
  lVar4 = IoAllocateIrp(*(char *)(lVar4 + 0x4c) + '\x01',0);
  if (lVar4 == 0) {
    uVar5 = 0xc000009a;
  }
  else {
    local_res8 = lVar4;
    _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)uVar1,0x63436443);
    *(void **)(lVar4 + 0x18) = _Dst;
    if (_Dst == (void *)0x0) {
      uVar5 = 0xc000009a;
      CdpFreeKernelConnectionIrp(&local_res8);
    }
    else {
      memmove(_Dst,_Src,(ulonglong)uVar1);
      *(undefined1 *)(lVar4 + 0x40) = 0;
      *(void **)(lVar4 + 0x98) = SystemReserved1[0xf];
      lVar2 = *(longlong *)(lVar4 + 0xb8);
      *(code **)(lVar2 + -0x10) = CdpCompleteServerKernelConnection;
      *(undefined8 *)(lVar2 + -8) = param_3;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      *(char *)(lVar4 + 0x43) = *(char *)(lVar4 + 0x43) + -1;
      *(longlong *)(lVar4 + 0xb8) = *(longlong *)(lVar4 + 0xb8) + -0x48;
      lVar4 = *(longlong *)(lVar4 + 0xb8);
      uVar3 = *(undefined8 *)(param_2 + 0x10);
      *(undefined8 *)(lVar4 + 8) = *(undefined8 *)(param_2 + 8);
      *(undefined8 *)(lVar4 + 0x10) = uVar3;
      uVar3 = *(undefined8 *)(param_2 + 0x20);
      *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(param_2 + 0x18);
      *(undefined8 *)(lVar4 + 0x20) = uVar3;
      *param_4 = local_res8;
    }
  }
  return uVar5;
}



===== CdpCompleteBrokerConnection @ 14000b600 =====

undefined8 CdpCompleteBrokerConnection(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  
  CdDereferenceBroker(param_3);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (-1 < *(int *)(param_2 + 0x30)) {
    lVar2 = *(longlong *)(param_2 + 0x38);
    iVar3 = CdpCreateServerConnectionIo
                      (param_2,lVar2,
                       (undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18));
    CdDereferenceServer(lVar2);
    if (-1 < iVar3) {
      return 0xc0000016;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = iVar3;
  }
  return 0;
}



===== CdpCompleteServerKernelConnection @ 14000b690 =====

undefined8 CdpCompleteServerKernelConnection(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  byte bVar3;
  longlong lVar4;
  longlong local_res10;
  
  iVar1 = *(int *)(param_2 + 0x30);
  lVar2 = *param_3;
  lVar4 = 0;
  if (-1 < iVar1) {
    lVar4 = param_3[1];
  }
  local_res10 = param_2;
  bVar3 = KeGetCurrentIrql();
  if (bVar3 < 2) {
    KeEnterCriticalRegion();
  }
  ExAcquirePushLockExclusiveEx(lVar2 + 0xd8,0);
  if (*(longlong *)(lVar2 + 0xe8) == param_2) {
    *(undefined8 *)(lVar2 + 0xe8) = 0;
    *(longlong *)(lVar2 + 0xe0) = lVar4;
    CdpCompleteServerKernelConnectionQueue(lVar2,iVar1);
  }
  ExReleasePushLockExclusiveEx(lVar2 + 0xd8,0);
  if (bVar3 < 2) {
    KeLeaveCriticalRegion();
  }
  ExFreePoolWithTag(param_3,0);
  CdpFreeKernelConnectionIrp(&local_res10);
  return 0xc0000016;
}



===== CdpCompleteServerKernelConnectionQueue @ 14000b784 =====

void CdpCompleteServerKernelConnectionQueue(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  
  plVar2 = *(longlong **)(param_1 + 0xf0);
  while( true ) {
    do {
      plVar5 = plVar2;
      if (plVar5 == (longlong *)(param_1 + 0xf0)) {
        return;
      }
      plVar2 = (longlong *)*plVar5;
      LOCK();
      lVar1 = plVar5[-8];
      plVar5[-8] = 0;
      UNLOCK();
    } while (lVar1 == 0);
    lVar1 = plVar5[2];
    *(char *)((longlong)plVar5 + -0x65) = *(char *)((longlong)plVar5 + -0x65) + '\x01';
    plVar5[2] = lVar1 + 0x48;
    if (param_2 < 0) {
      *(longlong *)(param_1 + 0x100) = *(longlong *)(param_1 + 0x100) + -1;
    }
    else {
      *(undefined8 *)(*(longlong *)(lVar1 + 0x78) + 0x18) = *(undefined8 *)(param_1 + 0xe0);
    }
    lVar1 = *plVar5;
    if ((*(longlong **)(lVar1 + 8) != plVar5) ||
       (plVar3 = (longlong *)plVar5[1], (longlong *)*plVar3 != plVar5)) break;
    *plVar3 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar3;
    plVar5[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar5;
    *(byte *)(plVar5[2] + 3) = *(byte *)(plVar5[2] + 3) | 1;
    plVar5[-0xe] = 0;
    *(int *)(plVar5 + -0xf) = param_2;
    IofCompleteRequest(plVar5 + -0x15,0);
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== CdpFreeKernelConnectionIrp @ 14000b868 =====

void CdpFreeKernelConnectionIrp(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  *param_1 = 0;
  if (lVar1 != 0) {
    if (*(longlong *)(lVar1 + 0x18) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0x18),0);
    }
    IoFreeIrp(lVar1);
  }
  return;
}



===== CdCreateDisplayObject @ 14000b8b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CdCreateDisplayObject(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  lVar1 = *(longlong *)(param_1 + 0xb8);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  cVar2 = PsIsCurrentThreadInServerSilo();
  if (cVar2 == '\0') {
    local_28 = 0x100000001;
    uStack_20 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x28);
    local_18 = 0;
    cVar2 = SePrivilegeCheck(&local_28,*(longlong *)(*(longlong *)(lVar1 + 8) + 8) + 0x20,
                             *(undefined1 *)(param_1 + 0x40));
    if (cVar2 == '\0') {
      iVar3 = -0x3fffff9f;
    }
    else {
      KeEnterCriticalRegion();
      iVar3 = RtlRunOnceBeginInitialize(&CdpDisplayInitialized,0,0);
      if (iVar3 == 0x103) {
        iVar3 = BgkGetConsoleState(&CdpDisplayState);
        if (iVar3 < 0) {
          RtlRunOnceComplete(&CdpDisplayInitialized,4);
          KeLeaveCriticalRegion();
          goto LAB_14000b8fb;
        }
        iVar3 = RtlRunOnceComplete(&CdpDisplayInitialized,0);
      }
      KeLeaveCriticalRegion();
      if (-1 < iVar3) {
        puVar4 = (undefined8 *)ExAllocatePool2(0x101,8,0x69446443);
        if (puVar4 != (undefined8 *)0x0) {
          *puVar4 = &CdDisplayType;
          *(undefined8 **)(*(longlong *)(lVar1 + 0x30) + 0x18) = puVar4;
          *(undefined4 *)(param_1 + 0x30) = 0;
          *(undefined8 *)(param_1 + 0x38) = 0;
          IofCompleteRequest(param_1,0);
          return 0;
        }
        iVar3 = -0x3fffff66;
      }
    }
  }
  else {
    iVar3 = -0x3fffff45;
  }
LAB_14000b8fb:
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(int *)(param_1 + 0x30) = iVar3;
  IofCompleteRequest(param_1,0);
  return iVar3;
}



===== CdpDisplayClose @ 14000ba90 =====

undefined8 CdpDisplayClose(undefined8 param_1,longlong param_2)

{
  ExFreePoolWithTag(param_1,0);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CdpDisplayFastIoctl @ 14000bad0 =====

undefined8
CdpDisplayFastIoctl(undefined8 param_1,ulonglong *param_2,uint param_3,undefined4 *param_4,
                   uint param_5,int param_6,undefined4 *param_7)

{
  undefined8 *puVar1;
  char cVar2;
  undefined8 uVar3;
  
  puVar1 = (undefined8 *)(param_7 + 2);
  *puVar1 = 0;
  if (param_6 == 0x500027) {
    cVar2 = ExGetPreviousMode();
    uVar3 = CdpGetDisplaySize(cVar2,param_4,param_5,puVar1);
  }
  else if (param_6 == 0x50002b) {
    cVar2 = ExGetPreviousMode();
    uVar3 = CdpUpdateDisplay(cVar2,param_2,param_3);
  }
  else if (param_6 == 0x50002f) {
    cVar2 = ExGetPreviousMode();
    uVar3 = CdpSetCursorInformation(cVar2,param_2,param_3);
  }
  else if (param_6 == 0x50003b) {
    cVar2 = ExGetPreviousMode();
    uVar3 = CdpGetFontSize(cVar2,param_4,param_5,puVar1);
  }
  else {
    uVar3 = 0xc0000010;
  }
  *param_7 = (int)uVar3;
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== CdpGetDisplaySize @ 14000bbbc =====

undefined8 CdpGetDisplaySize(char param_1,undefined4 *param_2,uint param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  if (param_3 < 8) {
    uVar1 = 0xc0000206;
  }
  else {
    if (param_1 == '\0') {
      *param_2 = DAT_1400061e8;
      param_2[1] = DAT_1400061ec;
    }
    else {
      ProbeForWrite(param_2,param_3,4);
      *param_2 = DAT_1400061e8;
      param_2[1] = DAT_1400061ec;
    }
    *param_4 = 8;
    uVar1 = 0;
  }
  return uVar1;
}



===== CdpGetFontSize @ 14000bc38 =====

undefined8 CdpGetFontSize(char param_1,undefined4 *param_2,uint param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  if (param_3 < 8) {
    uVar1 = 0xc0000206;
  }
  else {
    if (param_1 == '\0') {
      *param_2 = DAT_1400061f0;
      param_2[1] = DAT_1400061f4;
    }
    else {
      ProbeForWrite(param_2,param_3,4);
      *param_2 = DAT_1400061f0;
      param_2[1] = DAT_1400061f4;
    }
    *param_4 = 8;
    uVar1 = 0;
  }
  return uVar1;
}



===== CdpSetCursorInformation @ 14000bcb4 =====

undefined8 CdpSetCursorInformation(char param_1,ulonglong *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 local_18;
  char local_10;
  
  if (param_3 < 0xc) {
    uVar1 = 0xc0000206;
  }
  else {
    if (param_1 == '\0') {
      local_18 = *param_2;
      local_10 = (char)param_2[1];
    }
    else {
      if (((ulonglong)param_2 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_18 = *param_2;
      local_10 = (char)param_2[1];
    }
    uVar1 = BgkSetCursor(local_18 & 0xffff,local_18._2_2_,-(uint)(local_10 != '\0') & local_18._4_4_
                        );
  }
  return uVar1;
}



===== CdpUpdateDisplay @ 14000bd4c =====

undefined8 CdpUpdateDisplay(char param_1,undefined8 *param_2,uint param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  short local_30;
  ulonglong local_20;
  
  if (param_3 < 0x18) {
    uVar2 = 0xc0000206;
  }
  else {
    if (param_1 == '\0') {
      local_30 = (short)*param_2;
      local_20 = param_2[2];
      lVar4 = param_2[1];
    }
    else {
      if (((ulonglong)param_2 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_30 = (short)*param_2;
      lVar4 = param_2[1];
      local_20 = param_2[2];
      if ((DAT_1400061e8 != 0) && ((local_20 & 3) != 0)) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      ProbeForWrite(lVar4,(ulonglong)DAT_1400061e8 << 2,4);
    }
    if ((local_30 < 0) || (DAT_1400061ec <= (uint)(int)local_30)) {
      uVar2 = 0xc000000d;
    }
    else {
      for (uVar3 = 0; uVar3 < DAT_1400061e8; uVar3 = uVar3 + 1) {
        uVar5 = (ulonglong)uVar3;
        if (*(int *)(local_20 + uVar5 * 4) != *(int *)(lVar4 + uVar5 * 4)) {
          uVar1 = *(ushort *)(local_20 + 2 + uVar5 * 4);
          BgkDisplayCharacter(*(undefined2 *)(local_20 + uVar5 * 4),uVar3,(int)local_30,
                              *(undefined4 *)(&CdpPalette + (ulonglong)(uVar1 & 0xf) * 4),
                              *(undefined4 *)(&CdpPalette + (ulonglong)(uVar1 >> 4 & 0xf) * 4));
          *(undefined4 *)(lVar4 + uVar5 * 4) = *(undefined4 *)(local_20 + uVar5 * 4);
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== CdpCancelIoIrpPaged @ 14000bf00 =====

void CdpCancelIoIrpPaged(longlong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  code *pcVar8;
  byte bVar9;
  ulonglong uVar10;
  
  puVar2 = *(undefined8 **)(*(longlong *)(param_1 + 0xb8) + 8);
  bVar9 = KeGetCurrentIrql();
  if (bVar9 < 2) {
    KeEnterCriticalRegion();
  }
  ExAcquirePushLockExclusiveEx(*puVar2,0);
  lVar3 = *(longlong *)(param_1 + 0xb8);
  plVar1 = (longlong *)(param_1 + 0xa8);
  lVar4 = *plVar1;
  if ((*(longlong **)(lVar4 + 8) != plVar1) ||
     (plVar5 = *(longlong **)(param_1 + 0xb0), (longlong *)*plVar5 != plVar1)) {
    pcVar8 = (code *)swi(0x29);
    (*pcVar8)(3);
    pcVar8 = (code *)swi(3);
    (*pcVar8)();
    return;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  puVar6 = *(undefined8 **)(lVar3 + 0x20);
  if (puVar6 != *(undefined8 **)(param_1 + 8)) {
    while (puVar6 != (undefined8 *)0x0) {
      puVar7 = (undefined8 *)*puVar6;
      if ((*(byte *)((longlong)puVar6 + 10) & 2) != 0) {
        MmUnlockPages(puVar6);
      }
      IoFreeMdl(puVar6);
      puVar6 = puVar7;
    }
  }
  puVar6 = *(undefined8 **)(lVar3 + 0x18);
  if (puVar6 != *(undefined8 **)(param_1 + 8)) {
    while (puVar6 != (undefined8 *)0x0) {
      puVar7 = (undefined8 *)*puVar6;
      if ((*(byte *)((longlong)puVar6 + 10) & 2) != 0) {
        MmUnlockPages(puVar6);
      }
      IoFreeMdl(puVar6);
      puVar6 = puVar7;
    }
  }
  ExReleasePushLockExclusiveEx(*puVar2,0);
  if (bVar9 < 2) {
    KeLeaveCriticalRegion();
  }
  uVar10 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar10 == 0) {
    *(undefined4 *)(param_1 + 0x30) = 0xc0000120;
    *(undefined8 *)(param_1 + 0x38) = 0;
    IofCompleteRequest();
  }
  else {
    lVar3 = *(longlong *)(param_1 + 0x80);
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0xc0000120;
    *(undefined8 *)(param_1 + 0x38) = 0;
    IofCompleteRequest(param_1,0);
    if (lVar3 != 0) {
      ObfDereferenceObject(lVar3);
    }
  }
  return;
}



===== CdpCancelReadIoIrpPaged @ 14000c0bc =====

void CdpCancelReadIoIrpPaged(longlong param_1)

{
  undefined8 *puVar1;
  byte bVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x78);
  bVar2 = KeGetCurrentIrql();
  if (bVar2 < 2) {
    KeEnterCriticalRegion();
  }
  ExAcquirePushLockExclusiveEx(*puVar1,0);
  puVar1[2] = 0;
  ExReleasePushLockExclusiveEx(*puVar1,0);
  if (bVar2 < 2) {
    KeLeaveCriticalRegion();
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_1,0);
  return;
}



===== CdpCompleteIoIrp @ 14000c160 =====

void CdpCompleteIoIrp(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x80);
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x30) = param_2;
  *(undefined8 *)(param_1 + 0x38) = param_3;
  IofCompleteRequest(param_1,0);
  if (lVar1 != 0) {
    ObfDereferenceObject(lVar1);
  }
  return;
}



===== CdpServerSetSecurity @ 14000c1b0 =====

int CdpServerSetSecurity(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  undefined8 local_res18;
  
  local_res8[0] = *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 8);
  local_res18 = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0x28,0);
  local_res10 = *(undefined8 *)(param_1 + 0x38);
  iVar1 = SeSetSecurityDescriptorInfo(0,local_res8,local_res18,&local_res10,1,&CdpGenericMapping);
  if (-1 < iVar1) {
    iVar1 = ObLogSecurityDescriptor(local_res10,&local_res18,1);
    ExFreePoolWithTag(local_res10,0);
    if (-1 < iVar1) {
      ObDereferenceSecurityDescriptor(*(undefined8 *)(param_1 + 0x38),1);
      *(undefined8 *)(param_1 + 0x38) = local_res18;
    }
  }
  ExReleasePushLockExclusiveEx(param_1 + 0x28,0);
  KeLeaveCriticalRegion();
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = iVar1;
  IofCompleteRequest(param_2,0);
  return iVar1;
}



===== CdpServerFastIoctl @ 14000c2e0 =====

ulonglong CdpServerFastIoctl(longlong param_1,ulonglong *param_2,int param_3,undefined8 param_4,
                            undefined8 param_5,int param_6,undefined4 *param_7)

{
  longlong *plVar1;
  char cVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  plVar1 = (longlong *)(param_7 + 2);
  *plVar1 = 0;
  if (param_6 == 0x500006) {
    uVar3 = 0x500006;
    if (param_3 != 0) {
      if (param_3 != 0x28) {
        *param_7 = 0xc0000206;
        return 0x500001;
      }
      cVar2 = ExGetPreviousMode();
      uVar3 = CdCompleteIo((undefined8 *)(param_1 + 0x40),cVar2,param_2,0x28);
    }
  }
  else {
    uVar3 = 0;
    switch(param_6 + -0x50000b) {
    case 0:
      cVar2 = ExGetPreviousMode();
      uVar4 = CdCompleteIo((undefined8 *)(param_1 + 0x40),cVar2,param_2,param_3);
      *param_7 = (int)uVar4;
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    case 4:
      cVar2 = ExGetPreviousMode();
      uVar3 = CdReadIoInput((undefined8 *)(param_1 + 0x40),cVar2,param_2,param_3,plVar1);
      *param_7 = (int)uVar3;
      return CONCAT71((int7)(uVar3 >> 8),1);
    case 8:
      cVar2 = ExGetPreviousMode();
      uVar3 = CdWriteIoOutput((undefined8 *)(param_1 + 0x40),cVar2,(uint *)param_2,param_3,plVar1);
      *param_7 = (int)uVar3;
      return CONCAT71((int7)(uVar3 >> 8),1);
    case 0x10:
      uVar4 = CdDisconnectIoPipe((undefined8 *)(param_1 + 0x40));
      *param_7 = 0;
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    case 0x14:
      cVar2 = ExGetPreviousMode();
      uVar3 = CdpSetServerInformation(param_1,cVar2,param_2,param_3);
      *param_7 = (int)uVar3;
      return CONCAT71((int7)(uVar3 >> 8),1);
    case 0x28:
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(param_1 + 0x28,0);
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 1;
      ExReleasePushLockExclusiveEx(param_1 + 0x28,0);
      uVar4 = KeLeaveCriticalRegion();
      *param_7 = 0;
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    case 0x2c:
      cVar2 = ExGetPreviousMode();
      uVar3 = CdpLaunchServerProcess(param_1,cVar2,param_2);
      *param_7 = (int)uVar3;
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== CdCompleteIo @ 14000c4d0 =====

undefined8 CdCompleteIo(undefined8 *param_1,char param_2,ulonglong *param_3,int param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *plVar6;
  int iVar7;
  longlong lVar8;
  undefined8 local_38;
  int iStack_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  if (param_4 == 0x28) {
    if (param_2 == '\0') {
      local_38 = *param_3;
      iStack_30 = (int)param_3[1];
      local_28 = (undefined4)param_3[2];
      uStack_24 = *(undefined4 *)((longlong)param_3 + 0x14);
      uStack_20 = (undefined4)param_3[3];
      uStack_1c = *(undefined4 *)((longlong)param_3 + 0x1c);
      local_18 = param_3[4];
      iVar7 = (int)local_18;
    }
    else {
      if (((ulonglong)param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_38 = *param_3;
      iStack_30 = (int)param_3[1];
      local_28 = (undefined4)param_3[2];
      uStack_24 = *(undefined4 *)((longlong)param_3 + 0x14);
      uStack_20 = (undefined4)param_3[3];
      uStack_1c = *(undefined4 *)((longlong)param_3 + 0x1c);
      uVar4 = param_3[3];
      local_18 = param_3[4];
      iVar7 = (int)local_18;
      if (((int)local_18 != 0) &&
         ((uVar1 = uVar4 + (local_18 & 0xffffffff), *(ulonglong *)MmUserProbeAddress_exref < uVar1
          || (uVar1 < uVar4)))) {
      }
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(*param_1,0);
    plVar5 = param_1 + ((local_38 & 0xffffffff) % 5) * 2 + 5;
    plVar3 = (longlong *)*plVar5;
    if (plVar3 != plVar5) {
      do {
        plVar6 = plVar3 + -0x15;
        if (((int)plVar3[-4] == (int)local_38) &&
           (*(int *)((longlong)plVar3 + -0x1c) == local_38._4_4_)) {
          if (plVar6 == (longlong *)0x0) goto LAB_14000c622;
          if (iVar7 == 0) {
LAB_14000c690:
            lVar8 = CONCAT44(uStack_24,local_28);
          }
          else {
            uVar2 = CdpWriteIoOutput((longlong)plVar6,(longlong *)&uStack_20,(longlong *)0x0);
            if (-1 < (int)uVar2) goto LAB_14000c690;
            lVar8 = 0;
            iStack_30 = (int)uVar2;
          }
          uVar2 = CdpPrepareIoCompletion((longlong)plVar6,'\0');
          if ((char)uVar2 == '\0') {
            plVar6 = (longlong *)0x0;
            goto LAB_14000c62b;
          }
          uVar2 = 0;
          goto LAB_14000c630;
        }
        plVar3 = (longlong *)*plVar3;
      } while (plVar3 != plVar5);
    }
    plVar6 = (longlong *)0x0;
LAB_14000c622:
    lVar8 = CONCAT44(uStack_24,local_28);
LAB_14000c62b:
    uVar2 = 0xc0000120;
LAB_14000c630:
    ExReleasePushLockExclusiveEx(*param_1,0);
    KeLeaveCriticalRegion();
    if (plVar6 != (longlong *)0x0) {
      uVar4 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 != 0) {
        CdpCompleteIoIrp((longlong)plVar6,iStack_30,lVar8);
        return uVar2;
      }
      *(int *)(plVar6 + 6) = iStack_30;
      plVar6[7] = lVar8;
      IofCompleteRequest(plVar6,0);
    }
  }
  else {
    uVar2 = 0xc0000206;
  }
  return uVar2;
}



===== CdReadIoInput @ 14000c6f0 =====

ulonglong CdReadIoInput(undefined8 *param_1,char param_2,ulonglong *param_3,int param_4,
                       longlong *param_5)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  if (param_4 != 0x18) {
    return 0xc0000206;
  }
  if (param_2 == '\0') {
    local_28 = *param_3;
    uStack_20 = param_3[1];
    local_18 = param_3[2];
  }
  else {
    if (((ulonglong)param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_28 = *param_3;
    uStack_20 = param_3[1];
    local_18 = param_3[2];
    ProbeForWrite(uStack_20,local_18 & 0xffffffff,1);
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(*param_1,0);
  puVar1 = (undefined8 *)param_1[((local_28 & 0xffffffff) % 5) * 2 + 5];
  do {
    if (puVar1 == param_1 + ((local_28 & 0xffffffff) % 5) * 2 + 5) {
LAB_14000c82e:
      uVar2 = 0xc0000120;
LAB_14000c7fe:
      ExReleasePushLockExclusiveEx(*param_1,0);
      KeLeaveCriticalRegion();
      return uVar2;
    }
    if ((*(int *)(puVar1 + -4) == (int)local_28) &&
       (*(int *)((longlong)puVar1 + -0x1c) == local_28._4_4_)) {
      if (puVar1 + -0x15 != (undefined8 *)0x0) {
        uVar2 = CdpReadIoInput((longlong)(puVar1 + -0x15),(longlong *)&uStack_20,param_5);
        uVar2 = uVar2 & 0xffffffff;
        goto LAB_14000c7fe;
      }
      goto LAB_14000c82e;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== CdReadNextIo @ 14000c870 =====

ulonglong CdReadNextIo(undefined8 *param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(*param_1,0);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x28) {
    uVar4 = 0xc0000023;
  }
  else if (*(char *)(param_1 + 1) == '\0') {
    uVar4 = 0xc00000b0;
  }
  else {
    if ((longlong *)param_1[3] != param_1 + 3) {
      uVar3 = CdpCompleteReadIoIrp((longlong)param_1,param_2,'\0');
      uVar4 = (uint)uVar3;
      ExReleasePushLockExclusiveEx(*param_1,0);
      KeLeaveCriticalRegion();
      if (-1 < (int)uVar4) {
        return uVar3 & 0xffffffff;
      }
      goto LAB_14000c8fb;
    }
    *(undefined8 **)(param_2 + 0x78) = param_1;
    LOCK();
    *(code **)(param_2 + 0x68) = CdpCancelReadIoIrp;
    UNLOCK();
    if (*(char *)(param_2 + 0x44) == '\0') {
LAB_14000c943:
      param_1[2] = param_2;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      ExReleasePushLockExclusiveEx(*param_1,0);
      KeLeaveCriticalRegion();
      return 0x103;
    }
    LOCK();
    lVar2 = *(longlong *)(param_2 + 0x68);
    *(longlong *)(param_2 + 0x68) = 0;
    UNLOCK();
    if (lVar2 == 0) goto LAB_14000c943;
    uVar4 = 0xc0000120;
  }
  ExReleasePushLockExclusiveEx(*param_1,0);
  KeLeaveCriticalRegion();
LAB_14000c8fb:
  *(uint *)(param_2 + 0x30) = uVar4;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return (ulonglong)uVar4;
}



===== CdpServerIoctl @ 14000c9f0 =====

ulonglong CdpServerIoctl(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  byte *pbVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) != 0x500006) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return 0xc0000010;
  }
  puVar1 = (undefined8 *)(param_1 + 0x40);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(*puVar1,0);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x28) {
    uVar5 = 0xc0000023;
  }
  else if (*(char *)(param_1 + 0x48) == '\0') {
    uVar5 = 0xc00000b0;
  }
  else {
    if (*(longlong **)(param_1 + 0x58) != (longlong *)(param_1 + 0x58)) {
      uVar4 = CdpCompleteReadIoIrp((longlong)puVar1,param_2,'\0');
      uVar5 = uVar4 & 0xffffffff;
      ExReleasePushLockExclusiveEx(*puVar1,0);
      KeLeaveCriticalRegion();
      if (-1 < (int)uVar4) {
        return uVar5;
      }
      goto LAB_14000caf5;
    }
    *(undefined8 **)(param_2 + 0x78) = puVar1;
    LOCK();
    *(code **)(param_2 + 0x68) = CdpCancelReadIoIrp;
    UNLOCK();
    if (*(char *)(param_2 + 0x44) == '\0') {
LAB_14000ca7b:
      *(longlong *)(param_1 + 0x50) = param_2;
      pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar2 = *pbVar2 | 1;
      ExReleasePushLockExclusiveEx(*puVar1,0);
      KeLeaveCriticalRegion();
      return 0x103;
    }
    LOCK();
    lVar3 = *(longlong *)(param_2 + 0x68);
    *(longlong *)(param_2 + 0x68) = 0;
    UNLOCK();
    if (lVar3 == 0) goto LAB_14000ca7b;
    uVar5 = 0xc0000120;
  }
  ExReleasePushLockExclusiveEx(*puVar1,0);
  KeLeaveCriticalRegion();
LAB_14000caf5:
  *(int *)(param_2 + 0x30) = (int)uVar5;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar5;
}



===== CdpCompleteReadIoIrp @ 14000cb80 =====

ulonglong CdpCompleteReadIoIrp(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  longlong *plVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong local_res10;
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  longlong lStack_50;
  longlong local_48;
  uint uStack_40;
  uint uStack_3c;
  uint local_38;
  undefined4 uStack_34;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_2 + 8);
  if ((*(byte *)(lVar2 + 10) & 5) == 0) {
    plVar6 = (longlong *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
  }
  else {
    plVar6 = *(longlong **)(lVar2 + 0x18);
  }
  if (plVar6 == (longlong *)0x0) {
    uVar8 = 0xc000009a;
LAB_14000cd8a:
    if (param_3 != '\0') {
      *(int *)(param_2 + 0x30) = (int)uVar8;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
    }
    return uVar8;
  }
  local_38 = 0;
  plVar3 = *(longlong **)(param_1 + 0x18);
  uStack_34 = 0;
  lVar2 = plVar3[2];
  local_58 = plVar3[-4];
  lStack_50 = plVar3[-6];
  local_48 = *(longlong *)(lVar2 + 0x10);
  uStack_40 = (uint)*(byte *)(lVar2 + 1);
  for (puVar4 = *(undefined8 **)(lVar2 + 0x20); puVar4 != (undefined8 *)0x0;
      puVar4 = (undefined8 *)*puVar4) {
    local_38 = local_38 + *(int *)(puVar4 + 5);
  }
  uStack_3c = 0;
  for (puVar4 = *(undefined8 **)(lVar2 + 0x18); puVar4 != (undefined8 *)0x0;
      puVar4 = (undefined8 *)*puVar4) {
    uStack_3c = uStack_3c + *(int *)(puVar4 + 5);
  }
  local_res10 = (ulonglong)*(uint *)(lVar1 + 8) - 0x28;
  *plVar6 = local_58;
  plVar6[1] = lStack_50;
  plVar6[2] = local_48;
  plVar6[3] = CONCAT44(uStack_3c,uStack_40);
  plVar6[4] = (ulonglong)local_38;
  if (uStack_3c < local_res10) {
    local_res10 = (ulonglong)uStack_3c;
  }
  if (local_res10 != 0) {
    local_68 = plVar6 + 5;
    local_60 = (undefined4)local_res10;
    local_5c = 0;
    uVar7 = CdpReadIoInput((longlong)(plVar3 + -0x15),(longlong *)&local_68,(longlong *)&local_res10
                          );
    uVar8 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) goto LAB_14000cd8a;
  }
  lVar1 = *plVar3;
  if ((*(longlong **)(lVar1 + 8) == plVar3) &&
     (plVar6 = (longlong *)plVar3[1], (longlong *)*plVar6 == plVar3)) {
    *plVar6 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar6;
    plVar6 = (longlong *)((ulonglong)(*(uint *)(plVar3 + -4) % 5) * 0x10 + 0x28 + param_1);
    lVar1 = *plVar6;
    if (*(longlong **)(lVar1 + 8) == plVar6) {
      *plVar3 = lVar1;
      plVar3[1] = (longlong)plVar6;
      *(longlong **)(lVar1 + 8) = plVar3;
      *plVar6 = (longlong)plVar3;
      *(ulonglong *)(param_2 + 0x38) = local_res10 + 0x28;
      *(undefined4 *)(param_2 + 0x30) = 0;
      IofCompleteRequest(param_2,0);
      return 0;
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  uVar7 = (*pcVar5)();
  return uVar7;
}



===== CdpReadIoInput @ 14000cdd0 =====

undefined8 CdpReadIoInput(longlong param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  void *_Dst;
  uint uVar4;
  uint uVar5;
  
  _Dst = (void *)*param_2;
  uVar5 = *(uint *)(param_2 + 1);
  uVar3 = *(uint *)((longlong)param_2 + 0xc);
  puVar2 = *(undefined8 **)(*(longlong *)(param_1 + 0xb8) + 0x18);
  if (puVar2 == (undefined8 *)0x0) {
LAB_14000ce86:
    if (param_3 != (longlong *)0x0) {
      *param_3 = (longlong)_Dst - *param_2;
    }
    return 0;
  }
  do {
    if ((uVar3 == 0) || (uVar3 < *(uint *)(puVar2 + 5))) break;
    uVar3 = uVar3 - *(uint *)(puVar2 + 5);
    puVar2 = (undefined8 *)*puVar2;
  } while (puVar2 != (undefined8 *)0x0);
  do {
    if ((puVar2 == (undefined8 *)0x0) || (uVar5 == 0)) goto LAB_14000ce86;
    uVar4 = uVar5;
    if (*(int *)(puVar2 + 5) - uVar3 <= uVar5) {
      uVar4 = *(int *)(puVar2 + 5) - uVar3;
    }
    if ((*(byte *)((longlong)puVar2 + 10) & 5) == 0) {
      lVar1 = MmMapLockedPagesSpecifyCache(puVar2,0,1,0,0,0x40000010);
    }
    else {
      lVar1 = puVar2[3];
    }
    if (lVar1 == 0) goto LAB_14000ce86;
    memmove(_Dst,(void *)((ulonglong)uVar3 + lVar1),(ulonglong)uVar4);
    uVar3 = 0;
    _Dst = (void *)((longlong)_Dst + (ulonglong)uVar4);
    uVar5 = uVar5 - uVar4;
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== CdWriteIoOutput @ 14000cee0 =====

ulonglong CdWriteIoOutput(undefined8 *param_1,char param_2,uint *param_3,int param_4,
                         longlong *param_5)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  uint local_28;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  undefined8 local_18;
  
  if (param_4 != 0x18) {
    return 0xc0000206;
  }
  if (param_2 == '\0') {
    local_28 = *param_3;
    uStack_24 = param_3[1];
    uStack_20 = param_3[2];
    uStack_1c = param_3[3];
    local_18 = *(undefined8 *)(param_3 + 4);
  }
  else {
    if (((ulonglong)param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_28 = *param_3;
    uStack_24 = param_3[1];
    uStack_20 = param_3[2];
    uStack_1c = param_3[3];
    local_18 = *(undefined8 *)(param_3 + 4);
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(*param_1,0);
  puVar1 = (undefined8 *)param_1[((ulonglong)local_28 % 5) * 2 + 5];
  do {
    if (puVar1 == param_1 + ((ulonglong)local_28 % 5) * 2 + 5) {
LAB_14000d057:
      uVar2 = 0xc0000120;
LAB_14000cffc:
      ExReleasePushLockExclusiveEx(*param_1,0);
      KeLeaveCriticalRegion();
      return uVar2;
    }
    if ((*(uint *)(puVar1 + -4) == local_28) && (*(uint *)((longlong)puVar1 + -0x1c) == uStack_24))
    {
      if (puVar1 + -0x15 != (undefined8 *)0x0) {
        uVar2 = CdpWriteIoOutput((longlong)(puVar1 + -0x15),(longlong *)&uStack_20,param_5);
        uVar2 = uVar2 & 0xffffffff;
        goto LAB_14000cffc;
      }
      goto LAB_14000d057;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== CdpWriteIoOutput @ 14000d070 =====

undefined8 CdpWriteIoOutput(longlong param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  void *_Src;
  
  _Src = (void *)*param_2;
  uVar3 = *(uint *)(param_2 + 1);
  uVar4 = *(uint *)((longlong)param_2 + 0xc);
  puVar2 = *(undefined8 **)(*(longlong *)(param_1 + 0xb8) + 0x20);
  if (puVar2 == (undefined8 *)0x0) {
LAB_14000d11e:
    if (param_3 != (longlong *)0x0) {
      *param_3 = (longlong)_Src - *param_2;
    }
    return 0;
  }
  do {
    if ((uVar4 == 0) || (uVar4 < *(uint *)(puVar2 + 5))) break;
    uVar4 = uVar4 - *(uint *)(puVar2 + 5);
    puVar2 = (undefined8 *)*puVar2;
  } while (puVar2 != (undefined8 *)0x0);
  do {
    if ((puVar2 == (undefined8 *)0x0) || (uVar3 == 0)) goto LAB_14000d11e;
    uVar5 = uVar3;
    if (*(int *)(puVar2 + 5) - uVar4 <= uVar3) {
      uVar5 = *(int *)(puVar2 + 5) - uVar4;
    }
    if ((*(byte *)((longlong)puVar2 + 10) & 5) == 0) {
      lVar1 = MmMapLockedPagesSpecifyCache(puVar2,0,1,0,0,0x40000010);
    }
    else {
      lVar1 = puVar2[3];
    }
    if (lVar1 == 0) goto LAB_14000d11e;
    memmove((void *)((ulonglong)uVar4 + lVar1),_Src,(ulonglong)uVar5);
    uVar4 = 0;
    _Src = (void *)((longlong)_Src + (ulonglong)uVar5);
    uVar3 = uVar3 - uVar5;
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== CdpLaunchServerProcess @ 14000d180 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CdpLaunchServerProcess(longlong param_1,char param_2,undefined8 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  char *_Str1;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined1 auStack_f8 [32];
  longlong *local_d8;
  wchar_t *local_d0;
  longlong *local_c8;
  undefined1 local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  void *local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_88 = 0;
  if (param_2 == '\x01') {
    local_b0 = 0;
    local_98 = 0;
    lVar8 = 0;
    local_a8 = 0;
    local_a0 = 0;
    bVar1 = false;
    uVar4 = PsGetCurrentProcess();
    _Str1 = (char *)PsGetProcessImageFileName(uVar4);
    uVar2 = Ordinal_1(&local_b0,param_3);
    uVar7 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar4 = PsGetCurrentProcess();
      uVar4 = PsReferencePrimaryToken(uVar4);
      local_c8 = &local_a0;
      local_d0 = (wchar_t *)((ulonglong)local_d0 & 0xffffffffffffff00);
      local_d8 = (longlong *)0x0;
      uVar2 = ObOpenObjectByPointer(uVar4,0x200,0,0xb);
      uVar7 = (ulonglong)uVar2;
      PsDereferencePrimaryToken(uVar4);
      if (-1 < (int)uVar2) {
        uVar4 = PsGetCurrentProcess();
        local_c8 = &local_98;
        local_d0 = (wchar_t *)((ulonglong)local_d0 & 0xffffffffffffff00);
        local_d8 = (longlong *)0x0;
        uVar2 = ObOpenObjectByPointer(uVar4,0x200,0,0x1000);
        uVar7 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          uVar5 = CdpCreateProcess(&local_a8,local_a0,local_98,local_b0);
          uVar7 = uVar5 & 0xffffffff;
          if (-1 < (int)uVar5) {
            local_90 = 0;
            local_d0 = (wchar_t *)0x0;
            local_d8 = &local_90;
            uVar2 = ObReferenceObjectByHandle(local_a8,0,0,0);
            lVar8 = local_90;
            uVar7 = (ulonglong)uVar2;
            local_70 = local_90;
            if ((int)uVar2 < 0) {
              lVar8 = 0;
            }
            else {
              uVar2 = PsAcquireProcessExitSynchronization(local_90);
              uVar7 = (ulonglong)uVar2;
              if (-1 < (int)uVar2) {
                KeStackAttachProcess(lVar8,&local_68);
                bVar1 = true;
                local_b8 = 1;
                local_c8 = &local_88;
                local_d0 = (wchar_t *)CONCAT71(local_d0._1_7_,1);
                local_d8 = *(longlong **)IoFileObjectType_exref;
                uVar2 = ObOpenObjectByPointer(*(undefined8 *)(param_1 + 0x20),0,0,0x10000000);
                uVar7 = (ulonglong)uVar2;
                if (-1 < (int)uVar2) {
                  iVar3 = _stricmp(_Str1,"ntvdm.exe");
                  local_d0 = L" -ForceV1";
                  if (iVar3 != 0) {
                    local_d0 = L"";
                  }
                  local_d8 = (longlong *)CONCAT44(local_d8._4_4_,(undefined4)local_88);
                  uVar5 = RtlStringCbPrintfW(*(wchar_t **)(local_b0 + 0x78),
                                             (ulonglong)*(ushort *)(local_b0 + 0x72),L"%wZ 0x%x%s",
                                             local_b0 + 0x60);
                  uVar7 = uVar5 & 0xffffffff;
                  if (-1 < (int)uVar5) {
                    RtlInitUnicodeString(local_b0 + 0x70,*(undefined8 *)(local_b0 + 0x78));
                    lVar6 = PsGetProcessPeb(lVar8);
                    lVar6 = *(longlong *)(lVar6 + 0x20);
                    local_80 = lVar6;
                    ProbeForWrite(lVar6,0x448,4);
                    local_78 = *(void **)(lVar6 + 0x78);
                    ProbeForWrite(local_78,*(undefined2 *)(local_b0 + 0x72),1);
                    memmove(local_78,*(void **)(local_b0 + 0x78),
                            (ulonglong)*(ushort *)(local_b0 + 0x72));
                    *(undefined2 *)(local_80 + 0x70) = *(undefined2 *)(local_b0 + 0x70);
                    *(undefined2 *)(local_80 + 0x72) = *(undefined2 *)(local_b0 + 0x72);
                    PsResumeProcess(lVar8);
                  }
                }
              }
            }
          }
        }
      }
    }
    if (local_a0 != 0) {
      ObCloseHandle(local_a0,0);
    }
    if (local_98 != 0) {
      ObCloseHandle(local_98,0);
    }
    if (bVar1) {
      KeUnstackDetachProcess(&local_68);
      PsReleaseProcessExitSynchronization(lVar8);
    }
    if (local_a8 != 0) {
      if ((int)uVar7 < 0) {
        ZwTerminateProcess(local_a8,uVar7);
      }
      ObCloseHandle(local_a8,0);
    }
    if (lVar8 != 0) {
      ObfDereferenceObject(lVar8);
    }
    if (local_b0 != 0) {
      ExFreePoolWithTag(local_b0,0);
    }
  }
  else {
    uVar7 = 0xc00000bb;
  }
  return uVar7;
}



===== CdpCreateProcess @ 14000d600 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CdpCreateProcess(undefined8 *param_1,undefined8 param_2,undefined8 param_3,
                          undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStack_1a8 [32];
  undefined4 *local_188;
  undefined4 *local_180;
  undefined4 local_178;
  undefined4 local_170;
  undefined8 local_168;
  undefined8 *local_160;
  undefined8 *local_158;
  int local_148 [2];
  undefined8 local_140;
  undefined4 local_138;
  undefined4 local_134;
  undefined8 local_130;
  undefined8 local_128;
  undefined4 local_120;
  undefined4 local_11c;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined1 local_100 [88];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  wchar_t *local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_148[0] = 0;
  local_134 = 0;
  local_11c = 0;
  local_140 = 0;
  uVar2 = PsGetCurrentProcess();
  lVar3 = PsGetProcessWow64Process(uVar2);
  if (lVar3 != 0) {
    local_188 = (undefined4 *)0x0;
    uVar4 = ZwQueryInformationProcess(0xffffffffffffffff,0x1f,local_148);
    if ((int)uVar4 < 0) {
LAB_14000d7eb:
      *param_1 = 0;
      return uVar4;
    }
    if (local_148[0] == 1) {
      local_148[0] = 0;
      uVar4 = ZwSetInformationProcess(0xffffffffffffffff,0x1f,local_148);
      local_148[0] = 1;
      if ((int)uVar4 < 0) goto LAB_14000d7eb;
    }
  }
  memset(local_100,0,0x50);
  local_108 = 0x58;
  local_88 = 0;
  local_68 = 0;
  local_48 = 0;
  local_a8 = 0x68;
  local_90 = L"\\SystemRoot\\System32\\Conhost.exe";
  local_a0 = 0x20005;
  local_160 = &local_108;
  local_98 = 0x40;
  local_180 = &local_138;
  local_170 = 1;
  local_178 = 0x8000;
  local_188 = &local_138;
  local_80 = 0x60002;
  local_78 = 8;
  local_60 = 0x60000;
  local_58 = 8;
  local_138 = 0x30;
  local_130 = 0;
  local_120 = 0x200;
  local_128 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_168 = param_4;
  local_158 = &local_a8;
  local_70 = param_2;
  local_50 = param_3;
  uVar1 = Ordinal_2(param_1,&local_140,0x2000000);
  if (local_148[0] == 1) {
    ZwSetInformationProcess(0xffffffffffffffff,0x1f,local_148);
  }
  if ((int)uVar1 < 0) {
    *param_1 = 0;
  }
  else {
    ObCloseHandle(local_140,0);
  }
  return (ulonglong)uVar1;
}



===== CdpSetServerInformation @ 14000d850 =====

ulonglong CdpSetServerInformation(longlong param_1,char param_2,undefined8 *param_3,int param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 local_18;
  undefined8 local_10;
  
  if (param_4 == 8) {
    if (param_2 == '\0') {
      uVar2 = *param_3;
    }
    else {
      if (((ulonglong)param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      uVar2 = *param_3;
      local_10 = uVar2;
    }
    local_18 = 0;
    uVar1 = ObReferenceObjectByHandle
                      (uVar2,0x100000,*(undefined8 *)ExEventObjectType_exref,param_2,&local_18,0);
    if (-1 < (int)uVar1) {
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(param_1 + 0x28,0);
      if (*(longlong *)(param_1 + 0xb8) == 0) {
        uVar2 = PsGetCurrentProcessId();
        *(undefined8 *)(param_1 + 0xb8) = uVar2;
        *(undefined8 *)(param_1 + 0xc0) = local_18;
        uVar1 = uVar1 & 0xffffffff;
      }
      else {
        uVar1 = 0xc0000184;
        ObfDereferenceObject(local_18);
      }
      ExReleasePushLockExclusiveEx(param_1 + 0x28,0);
      KeLeaveCriticalRegion();
    }
  }
  else {
    uVar1 = 0xc0000206;
  }
  return uVar1;
}



===== CdpCreateMdlChain @ 14000d9a0 =====

undefined8 CdpCreateMdlChain(undefined8 *param_1,longlong param_2,uint param_3,char param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong **pplVar3;
  ulonglong uVar4;
  uint uVar5;
  int *piVar6;
  longlong **pplVar7;
  longlong *local_28;
  longlong **local_20;
  
  local_28 = (longlong *)0x0;
  uVar5 = 0;
  pplVar7 = &local_28;
  do {
    if (param_3 <= uVar5) {
      *param_1 = local_28;
      return 0;
    }
    piVar6 = (int *)((ulonglong)uVar5 * 0x10 + param_2);
    pplVar3 = pplVar7;
    if (*piVar6 != 0) {
      if (param_4 == '\0') {
LAB_14000da1e:
        uVar4 = *(ulonglong *)(piVar6 + 2);
      }
      else {
        uVar1 = PsGetCurrentProcess();
        lVar2 = PsGetProcessWow64Process(uVar1);
        if (lVar2 == 0) goto LAB_14000da1e;
        uVar4 = (ulonglong)(uint)piVar6[2];
      }
      pplVar3 = (longlong **)IoAllocateMdl(uVar4,*piVar6,0,1,0);
      local_20 = pplVar3;
      if (pplVar3 == (longlong **)0x0) {
        CdFreeMdlChain(local_28);
        return 0xc000009a;
      }
      MmProbeAndLockPages(pplVar3,param_4);
      *pplVar7 = (longlong *)pplVar3;
    }
    uVar5 = uVar5 + 1;
    pplVar7 = pplVar3;
  } while( true );
}



===== CdpReferenceObjectClose @ 14000dae0 =====

undefined8 CdpReferenceObjectClose(longlong param_1,longlong param_2)

{
  CdDereferenceServer(*(longlong *)(param_1 + 8));
  ExFreePoolWithTag(param_1,0);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CdpServerCleanup @ 14000db40 =====

undefined8 CdpServerCleanup(longlong param_1,longlong param_2)

{
  CdDisconnectIoPipe((undefined8 *)(param_1 + 0x40));
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CdpServerClose @ 14000db80 =====

undefined8 CdpServerClose(longlong param_1,longlong param_2)

{
  CdDereferenceServer(param_1);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CdpConnectionClose @ 14000dbc0 =====

undefined8 CdpConnectionClose(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  
  if (*(longlong *)(param_1 + 0x18) != 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(*(longlong *)(param_1 + 0x18) + 0xd8,0);
    if (*(longlong *)(*(longlong *)(param_1 + 0x18) + 0xe0) == param_1) {
      plVar1 = (longlong *)(*(longlong *)(param_1 + 0x18) + 0x100);
      *plVar1 = *plVar1 + -1;
      lVar4 = *(longlong *)(param_1 + 0x18);
      if (*(longlong *)(lVar4 + 0x100) != 0) {
        ExReleasePushLockSharedEx(lVar4 + 0xd8,0);
        KeLeaveCriticalRegion();
        *(undefined4 *)(param_2 + 0x30) = 0;
        *(undefined8 *)(param_2 + 0x38) = 0;
        IofCompleteRequest(param_2,0);
        return 0;
      }
      *(undefined8 *)(lVar4 + 0xe0) = 0;
    }
    ExReleasePushLockSharedEx(*(longlong *)(param_1 + 0x18) + 0xd8,0);
    KeLeaveCriticalRegion();
  }
  lVar4 = IoAllocateIrp(*(undefined1 *)(CdDeviceObject + 0x4c),0);
  if (lVar4 == 0) {
    lVar4 = param_2;
  }
  else {
    lVar2 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar2 + -0x10) = CdCompleteRoutineFreeIrp;
    *(undefined8 *)(lVar2 + -8) = 0;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  }
  CdInitializeIo(lVar4,*(longlong *)(param_1 + 0x18) + 0x40,2,*(undefined8 *)(param_1 + 0x28),0,0,0)
  ;
  iVar3 = CdAddIoToPipe(lVar4,0);
  CdpFreeConnection(param_1);
  if (lVar4 == param_2) {
    if (-1 < iVar3) {
      return 0x103;
    }
  }
  else if (iVar3 < 0) {
    IoFreeIrp(lVar4);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CdCreateDefaultObjectClient @ 14000dda0 =====

undefined4 CdCreateDefaultObjectClient(longlong param_1,undefined4 param_2)

{
  uint *puVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  ulonglong local_res8;
  undefined4 local_res10;
  longlong local_res18;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  lVar7 = 0;
  local_res18 = 0;
  local_res10 = param_2;
  lVar4 = CdpGetRequestorProcess(param_1);
  if (lVar4 == 0) {
    uVar8 = 0xc000000b;
  }
  else if ((*(uint *)(*(longlong *)(lVar2 + 8) + 0x10) & 0xffedfe40) == 0) {
    uVar5 = *(ulonglong *)(*(longlong *)(lVar2 + 0x30) + 0x40);
    local_res8 = uVar5;
    if ((((uVar5 == 0) || (*(longlong *)(uVar5 + 8) != CdDeviceObject)) ||
        (puVar9 = *(undefined8 **)(uVar5 + 0x18), puVar9 == (undefined8 *)0x0)) ||
       ((undefined *)*puVar9 != &CdServerType)) {
      uVar5 = CdGetProcessConnection(&local_res8,&local_res18,param_1,lVar4);
      if ((int)uVar5 < 0) {
        uVar8 = 0xc0000008;
        goto LAB_14000df9c;
      }
      puVar9 = *(undefined8 **)(local_res18 + 0x18);
      lVar7 = local_res18;
      uVar5 = local_res8;
    }
    else {
      ObfReferenceObject(uVar5);
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(puVar9 + 5,0);
    lVar4 = puVar9[0x18];
    if (lVar4 == 0) {
      ExReleasePushLockSharedEx(puVar9 + 5,0);
      KeLeaveCriticalRegion();
      ObfDereferenceObject(uVar5);
      uVar8 = 0xc0000184;
    }
    else {
      ObfReferenceObject(lVar4);
      ExReleasePushLockSharedEx(puVar9 + 5,0);
      KeLeaveCriticalRegion();
      lVar6 = CdpAllocateClient();
      if (lVar6 != 0) {
        *(undefined8 *)(lVar6 + 8) = 0;
        *(undefined4 *)(lVar6 + 0x10) = local_res10;
        *(longlong *)(lVar6 + 0x18) = lVar4;
        if ((lVar7 != 0) &&
           (cVar3 = PsIsSystemProcess(*(undefined8 *)(lVar7 + 0x20)), cVar3 != '\0')) {
          *(undefined4 *)(lVar6 + 0x20) = 1;
          *(undefined8 **)(lVar6 + 8) = puVar9;
          LOCK();
          puVar9[3] = puVar9[3] + 1;
          UNLOCK();
          uVar5 = local_res8;
        }
        *(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x18) = lVar6;
        *(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x20) = lVar4;
        puVar1 = (uint *)(*(longlong *)(lVar2 + 0x30) + 0x50);
        *puVar1 = *puVar1 | 0x10000000;
        ObfDereferenceObject(uVar5);
        *(undefined4 *)(param_1 + 0x30) = 0;
        *(undefined8 *)(param_1 + 0x38) = 0;
        IofCompleteRequest(param_1,0);
        return 0;
      }
      ObfDereferenceObject(uVar5);
      ObfDereferenceObject(lVar4);
      uVar8 = 0xc000009a;
    }
  }
  else {
    uVar8 = 0xc0000022;
  }
LAB_14000df9c:
  *(undefined4 *)(param_1 + 0x30) = uVar8;
  *(undefined8 *)(param_1 + 0x38) = 0;
  IofCompleteRequest(param_1,0);
  return uVar8;
}



===== CdpFreeConnection @ 14000e020 =====

void CdpFreeConnection(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  byte bVar4;
  
  if (*(longlong *)(param_1 + 0x18) != 0) {
    bVar4 = KeGetCurrentIrql();
    if (bVar4 < 2) {
      KeEnterCriticalRegion();
    }
    ExAcquirePushLockExclusiveEx(*(longlong *)(param_1 + 0x18) + 0x28,0);
    lVar1 = *(longlong *)(param_1 + 8);
    if ((*(longlong *)(lVar1 + 8) != param_1 + 8) ||
       (plVar2 = *(longlong **)(param_1 + 0x10), *plVar2 != param_1 + 8)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    ExReleasePushLockExclusiveEx(*(longlong *)(param_1 + 0x18) + 0x28,0);
    if (bVar4 < 2) {
      KeLeaveCriticalRegion();
    }
    CdDereferenceServer(*(longlong *)(param_1 + 0x18));
  }
  if (*(longlong *)(param_1 + 0x20) != 0) {
    ObfDereferenceObject();
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== CdCreateServer @ 14000e100 =====

int CdCreateServer(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  longlong local_res8;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  local_res8 = 0;
  lVar5 = CdpGetRequestorProcess(param_1);
  if (lVar5 == 0) {
    iVar4 = -0x3ffffff5;
  }
  else {
    lVar3 = *(longlong *)(param_1 + 0x18);
    if (lVar3 == 0) {
      uVar8 = 0;
      uVar9 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
    }
    else {
      if (*(short *)(lVar3 + 6) != 0x10) {
        iVar4 = -0x3ffffdfa;
        goto LAB_14000e1d8;
      }
      puVar1 = (undefined4 *)((ulonglong)*(byte *)(lVar3 + 5) + 9 + lVar3);
      uVar8 = *puVar1;
      uVar9 = puVar1[1];
      uStack_20 = puVar1[2];
      uStack_1c = puVar1[3];
    }
    uVar6 = CdpAllocateServer(&local_res8);
    lVar3 = local_res8;
    iVar4 = (int)uVar6;
    if (-1 < iVar4) {
      *(undefined8 *)(local_res8 + 0x20) = *(undefined8 *)(lVar2 + 0x30);
      *(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x18) = local_res8;
      if (CONCAT44(uVar9,uVar8) == 0) {
        uVar7 = CdCreateSecurityDescriptor
                          ((undefined8 *)(local_res8 + 0x38),
                           *(longlong *)(*(longlong *)(lVar2 + 8) + 8));
        iVar4 = (int)uVar7;
      }
      else {
        uVar7 = CdCompleteBrokerIoWithServer
                          (CONCAT44(uVar9,uVar8),(ulonglong *)&uStack_20,local_res8,lVar5);
        iVar4 = (int)uVar7;
      }
      if (-1 < iVar4) {
        *(undefined4 *)(param_1 + 0x30) = 0;
        *(undefined8 *)(param_1 + 0x38) = 0;
        IofCompleteRequest(param_1,0);
        return 0;
      }
    }
    if (lVar3 != 0) {
      CdDereferenceServer(lVar3);
    }
  }
LAB_14000e1d8:
  *(int *)(param_1 + 0x30) = iVar4;
  *(undefined8 *)(param_1 + 0x38) = 0;
  IofCompleteRequest(param_1,0);
  return iVar4;
}



===== CdCreateConnection @ 14000e240 =====

int CdCreateConnection(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  uint *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined1 uVar9;
  longlong local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  local_res8 = 0;
  lVar8 = *(longlong *)(lVar1 + 0x30);
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 8) + 8);
  puVar6 = CdpFindEaBufferItem(*(uint **)(param_1 + 0x18),"attach");
  if (puVar6 == (uint *)0x0) {
    lVar8 = *(longlong *)(lVar8 + 0x40);
    if (lVar8 == 0) {
      iVar5 = CdpCreateBrokerConnectionIo(param_1);
      return iVar5;
    }
    if ((((*(longlong *)(lVar8 + 8) != CdDeviceObject) ||
         (puVar3 = *(undefined8 **)(lVar8 + 0x18), puVar3 == (undefined8 *)0x0)) ||
        ((undefined *)*puVar3 != &CdReferenceType)) || (puVar3[1] == 0)) {
      iVar5 = -0x3ffffff8;
      goto LAB_14000e2f2;
    }
    iVar5 = CdpCreateServerConnectionIo
                      (param_1,puVar3[1],(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x18));
  }
  else {
    if (*(short *)((longlong)puVar6 + 6) != 8) {
      iVar5 = -0x3ffffff3;
      goto LAB_14000e2f2;
    }
    lVar8 = *(longlong *)((ulonglong)*(byte *)((longlong)puVar6 + 5) + 9 + (longlong)puVar6);
    uVar7 = CdpGetProcessServerFromConnection(&local_res8,param_1,lVar8);
    lVar4 = local_res8;
    iVar5 = (int)uVar7;
    if (iVar5 < 0) goto LAB_14000e2f2;
    uVar9 = 1;
    if ((*(byte *)(lVar1 + 2) & 1) == 0) {
      uVar9 = *(undefined1 *)(param_1 + 0x40);
    }
    iVar5 = CdAccessCheck(local_res8,(longlong *)(lVar2 + 0x20),lVar8,uVar9);
    if (iVar5 < 0) {
      CdDereferenceServer(lVar4);
      goto LAB_14000e2f2;
    }
    iVar5 = CdpCreateServerConnectionIo
                      (param_1,lVar4,(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x18));
    CdDereferenceServer(lVar4);
  }
  if (-1 < iVar5) {
    return iVar5;
  }
LAB_14000e2f2:
  *(int *)(param_1 + 0x30) = iVar5;
  *(undefined8 *)(param_1 + 0x38) = 0;
  IofCompleteRequest(param_1,0);
  return iVar5;
}



===== CdCreateClient @ 14000e3b0 =====

int CdCreateClient(longlong param_1,uint param_2)

{
  longlong *plVar1;
  uint *puVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong local_res8;
  ulonglong local_res20;
  longlong local_48 [2];
  
  local_res8 = 0;
  local_48[0] = 0;
  lVar14 = 0;
  local_res20 = 0;
  plVar10 = (longlong *)0x0;
  lVar3 = *(longlong *)(param_1 + 0xb8);
  plVar13 = (longlong *)0x0;
  lVar9 = CdpGetRequestorProcess(param_1);
  if (lVar9 == 0) {
    iVar8 = -0x3ffffff5;
  }
  else {
    plVar10 = (longlong *)ExAllocatePool2(0x41,0x18,0x63436443);
    if (plVar10 == (longlong *)0x0) {
      iVar8 = -0x3fffff66;
    }
    else {
      uVar11 = CdGetProcessConnection(&local_res20,&local_res8,param_1,lVar9);
      iVar8 = (int)uVar11;
      if (-1 < iVar8) {
        KeEnterCriticalRegion();
        lVar4 = local_res8;
        ExAcquirePushLockSharedEx(*(longlong *)(local_res8 + 0x18) + 0x28,0);
        lVar9 = *(longlong *)(*(longlong *)(lVar4 + 0x18) + 0xc0);
        ExReleasePushLockSharedEx(*(longlong *)(lVar4 + 0x18) + 0x28,0);
        KeLeaveCriticalRegion();
        if (lVar9 == 0) {
          iVar8 = -0x3ffffe7c;
        }
        else {
          *(uint *)(plVar10 + 1) = param_2;
          if (param_2 == 3) {
            uVar7 = (uint)*(ushort *)(lVar3 + 0x1a);
          }
          else {
            uVar7 = 3;
          }
          *(uint *)((longlong)plVar10 + 0xc) = uVar7;
          uVar12 = CdpConvertClientDesiredAccess
                             ((uint *)(plVar10 + 2),*(uint *)(*(longlong *)(lVar3 + 8) + 0x10));
          iVar8 = (int)uVar12;
          if (-1 < iVar8) {
            plVar13 = (longlong *)IoAllocateMdl(plVar10 + 1,0xc,0,1,0);
            if (plVar13 != (longlong *)0x0) {
              MmBuildMdlForNonPagedPool(plVar13);
              uVar12 = CdAllocateMdlForEaBufferItem(local_48,param_1,"");
              iVar8 = (int)uVar12;
              if (iVar8 < 0) goto LAB_14000e64c;
              *plVar13 = local_48[0];
              lVar14 = CdpAllocateClient();
              if (lVar14 != 0) {
                *plVar10 = lVar14;
                *(undefined8 *)(lVar14 + 8) = *(undefined8 *)(lVar4 + 0x18);
                LOCK();
                plVar1 = (longlong *)(*(longlong *)(lVar4 + 0x18) + 0x18);
                *plVar1 = *plVar1 + 1;
                UNLOCK();
                *(longlong *)(lVar14 + 0x18) = lVar9;
                ObfReferenceObject(lVar9);
                lVar5 = local_res8;
                *(undefined4 *)(lVar14 + 0x20) = 2;
                cVar6 = PsIsSystemProcess(*(undefined8 *)(local_res8 + 0x20));
                if (cVar6 != '\0') {
                  *(uint *)(lVar14 + 0x20) = *(uint *)(lVar14 + 0x20) | 1;
                }
                *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18) = lVar14;
                *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x20) = lVar9;
                puVar2 = (uint *)(*(longlong *)(lVar3 + 0x30) + 0x50);
                *puVar2 = *puVar2 | 0x10000000;
                lVar3 = *(longlong *)(param_1 + 0xb8);
                *(code **)(lVar3 + -0x10) = CdpCompleteClientCreation;
                *(longlong **)(lVar3 + -8) = plVar10;
                *(undefined1 *)(lVar3 + -0x45) = 0xe0;
                CdInitializeIo(param_1,*(longlong *)(lVar4 + 0x18) + 0x40,3,
                               *(undefined8 *)(lVar5 + 0x28),(ulonglong)param_2,plVar13,0);
                iVar8 = CdAddIoToPipe(param_1,0);
                if (-1 < iVar8) {
                  ObfDereferenceObject(local_res20);
                  return 0x103;
                }
                goto LAB_14000e64c;
              }
            }
            iVar8 = -0x3fffff66;
          }
        }
      }
    }
  }
LAB_14000e64c:
  CdFreeMdlChain(plVar13);
  if (local_res20 != 0) {
    ObfDereferenceObject();
  }
  if (plVar10 != (longlong *)0x0) {
    ExFreePoolWithTag(plVar10,0);
  }
  if (lVar14 != 0) {
    CdpFreeClient(lVar14);
  }
  *(int *)(param_1 + 0x30) = iVar8;
  *(undefined8 *)(param_1 + 0x38) = 0;
  IofCompleteRequest(param_1,0);
  return iVar8;
}



===== CdpCreateServerConnectionIo @ 14000e6f0 =====

int CdpCreateServerConnectionIo(longlong param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  uint *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  undefined8 uVar11;
  longlong *plVar12;
  ulonglong uVar13;
  longlong *plVar14;
  undefined8 local_res8;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  plVar10 = (longlong *)0x0;
  puVar9 = (undefined8 *)0x0;
  plVar14 = (longlong *)0x0;
  lVar6 = CdpGetRequestorProcess(param_1);
  if (lVar6 == 0) {
    iVar5 = -0x3ffffff5;
    goto LAB_14000e969;
  }
  if (*(longlong *)(param_1 + 0x98) == 0) {
    local_res8 = 0;
  }
  else {
    local_res8 = PsGetThreadId();
  }
  puVar7 = CdpFindEaBufferItem(*(uint **)(param_1 + 0x18),"server");
  plVar12 = plVar14;
  if (puVar7 == (uint *)0x0) {
LAB_14000e775:
    bVar3 = KeGetCurrentIrql();
    uVar13 = 0x100;
    if (1 < bVar3) {
      uVar13 = 0x40;
    }
    cVar4 = PsIsSystemProcess(lVar6);
    if (cVar4 == '\0') {
      uVar13 = uVar13 | 1;
    }
    puVar8 = (undefined8 *)ExAllocatePool2(uVar13,0x40,0x6f436443);
    plVar14 = plVar12;
    if (puVar8 != (undefined8 *)0x0) {
      puVar8[2] = 0;
      puVar8[4] = 0;
      puVar8[5] = 0;
      puVar8[6] = 0;
      puVar8[7] = 0;
      puVar1 = puVar8 + 1;
      puVar8[2] = puVar1;
      *puVar1 = puVar1;
      *puVar8 = &CdConnectionType;
      puVar8[3] = param_2;
      LOCK();
      *(longlong *)(param_2 + 0x18) = *(longlong *)(param_2 + 0x18) + 1;
      UNLOCK();
      puVar8[4] = lVar6;
      ObfReferenceObject(lVar6);
      *param_3 = puVar8;
      if ((*(longlong *)(param_2 + 0x38) == 0) && (cVar4 = PsIsSystemProcess(lVar6), cVar4 == '\0'))
      {
        uVar13 = CdCreateSecurityDescriptor
                           ((undefined8 *)(param_2 + 0x38),
                            *(longlong *)(*(longlong *)(lVar2 + 8) + 8));
        iVar5 = (int)uVar13;
        if (-1 < iVar5) goto LAB_14000e81f;
LAB_14000e9b9:
        CdpFreeConnection((longlong)puVar8);
        if (puVar9 == (undefined8 *)0x0) goto LAB_14000e969;
      }
      else {
LAB_14000e81f:
        cVar4 = PsIsSystemProcess(lVar6);
        if (cVar4 == '\0') {
          uVar11 = 0x41;
        }
        else {
          uVar11 = 0x40;
        }
        puVar9 = (undefined8 *)ExAllocatePool2(uVar11,0x20,0x63436443);
        if (puVar9 == (undefined8 *)0x0) {
          iVar5 = -0x3fffff66;
          CdpFreeConnection((longlong)puVar8);
          goto LAB_14000e969;
        }
        *puVar9 = puVar8;
        plVar10 = (longlong *)IoAllocateMdl(puVar9 + 1,0x18,0,1,0);
        if (plVar10 != (longlong *)0x0) {
          MmBuildMdlForNonPagedPool(plVar10);
          lVar2 = *(longlong *)(param_1 + 0xb8);
          *(code **)(lVar2 + -0x10) = CdpCompleteServerConnection;
          *(undefined8 **)(lVar2 + -8) = puVar9;
          *(undefined1 *)(lVar2 + -0x45) = 0xe0;
          uVar11 = PsGetProcessId(lVar6);
          CdInitializeIo(param_1,param_2 + 0x40,1,uVar11,local_res8,plVar12,plVar10);
          iVar5 = CdAddIoToPipe(param_1,0);
          if (-1 < iVar5) {
            return 0x103;
          }
          goto LAB_14000e9b9;
        }
        iVar5 = -0x3fffff66;
        CdpFreeConnection((longlong)puVar8);
      }
      ExFreePoolWithTag(puVar9,0);
      goto LAB_14000e969;
    }
  }
  else {
    plVar12 = (longlong *)
              IoAllocateMdl((longlong)puVar7 + (ulonglong)*(byte *)((longlong)puVar7 + 5) + 9,
                            *(undefined2 *)((longlong)puVar7 + 6),0,1,0);
    if (plVar12 != (longlong *)0x0) {
      MmBuildMdlForNonPagedPool(plVar12);
      goto LAB_14000e775;
    }
  }
  iVar5 = -0x3fffff66;
LAB_14000e969:
  CdFreeMdlChain(plVar14);
  CdFreeMdlChain(plVar10);
  return iVar5;
}



===== CdpGetRequestorProcess @ 14000ea30 =====

undefined8 CdpGetRequestorProcess(longlong param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x40) == '\x01') {
    uVar1 = IoGetRequestorProcess();
  }
  else {
    uVar1 = *(undefined8 *)PsInitialSystemProcess_exref;
  }
  return uVar1;
}



===== CdAllocateMdlForEaBufferItem @ 14000ea60 =====

undefined8 CdAllocateMdlForEaBufferItem(longlong *param_1,longlong param_2,char *param_3)

{
  uint *puVar1;
  longlong lVar2;
  
  *param_1 = 0;
  puVar1 = CdpFindEaBufferItem(*(uint **)(param_2 + 0x18),param_3);
  if (puVar1 != (uint *)0x0) {
    lVar2 = IoAllocateMdl((longlong)puVar1 + (ulonglong)*(byte *)((longlong)puVar1 + 5) + 9,
                          *(undefined2 *)((longlong)puVar1 + 6),0,1,0);
    if (lVar2 == 0) {
      return 0xc000009a;
    }
    MmBuildMdlForNonPagedPool(lVar2);
    *param_1 = lVar2;
  }
  return 0;
}



===== CdpFindEaBufferItem @ 14000eaf0 =====

uint * CdpFindEaBufferItem(uint *param_1,char *param_2)

{
  int iVar1;
  
  if (param_1 != (uint *)0x0) {
    while( true ) {
      iVar1 = _stricmp((char *)(param_1 + 2),param_2);
      if (iVar1 == 0) {
        return param_1;
      }
      if (*param_1 == 0) break;
      param_1 = (uint *)((longlong)param_1 + (ulonglong)*param_1);
    }
  }
  return (uint *)0x0;
}



===== CdGetProcessConnection @ 14000eb50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CdGetProcessConnection
                    (ulonglong *param_1,undefined8 *param_2,longlong param_3,longlong param_4)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined1 auStack_a8 [32];
  ulonglong *local_88;
  undefined8 local_80;
  ulonglong local_78;
  ulonglong local_70;
  longlong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_68 = param_4;
  if (((param_3 == 0) ||
      (uVar3 = *(ulonglong *)(*(longlong *)(*(longlong *)(param_3 + 0xb8) + 0x30) + 0x40),
      uVar3 == 0)) ||
     (puVar5 = CdGetConnectionFromFileObject(uVar3,param_4), puVar5 == (undefined8 *)0x0)) {
    cVar1 = PsIsSystemProcess(param_4);
    if (cVar1 != '\0') {
      return 0xc00000bb;
    }
    uVar3 = PsAcquireProcessExitSynchronization(param_4);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    KeStackAttachProcess(param_4,&local_60);
    lVar4 = PsGetProcessWow64Process(param_4);
    if (lVar4 == 0) {
      lVar4 = PsGetProcessPeb(param_4);
      local_78 = *(ulonglong *)(lVar4 + 0x20);
      if ((local_78 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_70 = *(ulonglong *)(local_78 + 0x10);
    }
    else {
      uVar2 = *(uint *)(lVar4 + 0x10);
      local_78 = (ulonglong)uVar2;
      if ((uVar2 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_70 = (ulonglong)*(uint *)((ulonglong)uVar2 + 0x10);
    }
    local_78 = 0;
    local_80 = 0;
    local_88 = &local_78;
    uVar2 = ObReferenceObjectByHandle(local_70,0,*(undefined8 *)IoFileObjectType_exref,1);
    KeUnstackDetachProcess(&local_60);
    PsReleaseProcessExitSynchronization(param_4);
    if ((int)uVar2 < 0) {
      return (ulonglong)uVar2;
    }
    if (((local_78 == 0) || (*(longlong *)(local_78 + 8) != CdDeviceObject)) ||
       ((puVar5 = *(undefined8 **)(local_78 + 0x18), puVar5 == (undefined8 *)0x0 ||
        (((undefined *)*puVar5 != &CdConnectionType || (puVar5[4] != param_4)))))) {
      ObfDereferenceObject();
      return 0xc0000001;
    }
    *param_2 = puVar5;
    *param_1 = local_78;
  }
  else {
    *param_2 = puVar5;
    *param_1 = uVar3;
    ObfReferenceObject(uVar3);
  }
  return 0;
}



===== CdpConvertClientDesiredAccess @ 14000edd0 =====

undefined8 CdpConvertClientDesiredAccess(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0x80000000;
  if ((param_2 & 0x120089) != 0x120089) {
    uVar2 = 0;
  }
  uVar1 = uVar2 | 0x40000000;
  if ((param_2 & 0x120116) != 0x120116) {
    uVar1 = uVar2;
  }
  if ((param_2 & 0xffedfe40) != 0) {
    return 0xc0000022;
  }
  uVar2 = uVar1 | 0x20000000;
  if ((param_2 & 0x1200a0) != 0x1200a0) {
    uVar2 = uVar1;
  }
  *param_1 = uVar2;
  return 0;
}



===== CdpClientClose @ 14000ee40 =====

undefined8 CdpClientClose(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  
  if ((*(uint *)(param_1 + 0x20) & 2) == 0) {
    CdpFreeClient(param_1);
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return 0;
  }
  lVar3 = IoAllocateIrp(*(undefined1 *)(CdDeviceObject + 0x4c),0);
  if (lVar3 == 0) {
    lVar3 = param_2;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = CdCompleteRoutineFreeIrp;
    *(undefined8 *)(lVar1 + -8) = 0;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  }
  CdInitializeIo(lVar3,*(longlong *)(param_1 + 8) + 0x40,4,0,*(undefined8 *)(param_1 + 0x10),0,0);
  iVar2 = CdAddIoToPipe(lVar3,0);
  CdpFreeClient(param_1);
  if (lVar3 == param_2) {
    if (-1 < iVar2) {
      return 0x103;
    }
  }
  else if (iVar2 < 0) {
    IoFreeIrp(lVar3);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== CdInitializeIo @ 14000ef90 =====

void CdInitializeIo(longlong param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4,
                   undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  *(undefined8 *)(lVar1 + -0x38) = param_5;
  *(undefined8 *)(lVar1 + -0x30) = param_6;
  *(undefined8 *)(lVar1 + -0x28) = param_7;
  *(undefined1 *)(lVar1 + -0x48) = 0xf;
  *(undefined1 *)(lVar1 + -0x47) = param_3;
  *(undefined8 *)(lVar1 + -0x40) = param_2;
  *(undefined8 *)(param_1 + 0x78) = param_4;
  uVar2 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    *(undefined8 *)(param_1 + 0x80) = 0;
  }
  ZwAllocateLocallyUniqueId(param_1 + 0x88);
  return;
}



===== CdAddIoToPipe @ 14000f000 =====

int CdAddIoToPipe(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  byte bVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  int iVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  uint uVar16;
  longlong *plVar17;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined4 local_38;
  undefined4 local_30;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  puVar3 = *(undefined8 **)(lVar2 + -0x40);
  uVar7 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
  bVar6 = KeGetCurrentIrql();
  if (bVar6 < 2) {
    KeEnterCriticalRegion();
  }
  ExAcquirePushLockExclusiveEx(*puVar3,0);
  puVar14 = auStack_58;
  puVar15 = auStack_58;
  uVar16 = 0;
  for (puVar9 = *(undefined8 **)(lVar2 + -0x28); puVar9 != (undefined8 *)0x0;
      puVar9 = (undefined8 *)*puVar9) {
    if ((*(byte *)((longlong)puVar9 + 10) & 5) == 0) {
      local_30 = 0x40000010;
      local_38 = 0;
      lVar8 = MmMapLockedPagesSpecifyCache(puVar9,0,1);
    }
    else {
      lVar8 = puVar9[3];
    }
    if (lVar8 == 0) goto LAB_14000f0e3;
    uVar16 = uVar16 + *(uint *)(puVar9 + 5);
    if (uVar16 < *(uint *)(puVar9 + 5)) goto LAB_14000f0d4;
  }
  uVar16 = 0;
  for (puVar9 = *(undefined8 **)(lVar2 + -0x30); puVar9 != (undefined8 *)0x0;
      puVar9 = (undefined8 *)*puVar9) {
    if ((*(byte *)((longlong)puVar9 + 10) & 5) == 0) {
      local_30 = 0x40000010;
      local_38 = 0;
      lVar8 = MmMapLockedPagesSpecifyCache(puVar9,0,1);
    }
    else {
      lVar8 = puVar9[3];
    }
    if (lVar8 == 0) goto LAB_14000f0e3;
    uVar16 = uVar16 + *(uint *)(puVar9 + 5);
    if (uVar16 < *(uint *)(puVar9 + 5)) goto LAB_14000f0d4;
  }
  if (*(char *)(puVar3 + 1) == '\0') {
    iVar13 = -0x3fffff50;
    puVar15 = auStack_58;
  }
  else {
    *(char *)(param_1 + 0x43) = *(char *)(param_1 + 0x43) + -1;
    *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + -0x48;
    if ((*(char *)(lVar2 + -0x47) - 2U & 0xfd) != 0) {
      uVar10 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar10 != 0) {
        plVar17 = (longlong *)(param_1 + 0x80);
        if ((int)uVar7 == 0) {
          plVar17 = (longlong *)&DAT_00000008;
        }
        *plVar17 = param_2;
      }
      LOCK();
      *(code **)(param_1 + 0x68) = CdpCancelIoIrp;
      UNLOCK();
      if (*(char *)(param_1 + 0x44) != '\0') {
        LOCK();
        lVar2 = *(longlong *)(param_1 + 0x68);
        *(longlong *)(param_1 + 0x68) = 0;
        UNLOCK();
        if (lVar2 != 0) {
          *(char *)(param_1 + 0x43) = *(char *)(param_1 + 0x43) + '\x01';
          iVar13 = -0x3ffffee0;
          *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 0x48;
          puVar15 = auStack_58;
          goto LAB_14000f20e;
        }
      }
    }
    puVar12 = (undefined8 *)puVar3[4];
    puVar9 = puVar3 + 3;
    puVar11 = (undefined8 *)(param_1 + 0xa8);
    if ((undefined8 *)*puVar12 != puVar9) {
      puVar11 = (undefined8 *)0x3;
      pcVar5 = (code *)swi(0x29);
      puVar9 = (undefined8 *)(*pcVar5)();
      puVar14 = auStack_50;
    }
    *puVar11 = puVar9;
    puVar11[1] = puVar12;
    *puVar12 = puVar11;
    puVar9[1] = puVar11;
    if (puVar3[2] != 0) {
      LOCK();
      plVar17 = (longlong *)(puVar3[2] + 0x68);
      lVar2 = *plVar17;
      *plVar17 = 0;
      UNLOCK();
      if (lVar2 != 0) {
        lVar2 = puVar3[2];
        *(undefined8 *)(puVar14 + -8) = 0x14000f1f9;
        CdpCompleteReadIoIrp((longlong)puVar3,lVar2,'\x01');
        puVar3[2] = 0;
      }
    }
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    iVar13 = 0;
    puVar15 = puVar14;
  }
LAB_14000f20e:
  uVar4 = *puVar3;
  *(undefined8 *)(puVar15 + -8) = 0x14000f21a;
  ExReleasePushLockExclusiveEx(uVar4,0);
  if (bVar6 < 2) {
    *(undefined8 *)(puVar15 + -8) = 0x14000f22b;
    KeLeaveCriticalRegion();
  }
  *(undefined8 *)(puVar15 + -8) = 0x14000f235;
  uVar10 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar10 != 0) && (iVar13 < 0)) {
    plVar17 = (longlong *)(param_1 + 0x80);
    if ((int)uVar7 == 0) {
      plVar17 = (longlong *)&DAT_00000008;
    }
    if (*plVar17 == param_2) {
      *plVar17 = 0;
    }
  }
  return iVar13;
LAB_14000f0e3:
  iVar13 = -0x3fffff66;
  goto LAB_14000f20e;
LAB_14000f0d4:
  iVar13 = -0x3fffff6b;
  puVar15 = auStack_58;
  goto LAB_14000f20e;
}



===== CdpFreeClient @ 14000f280 =====

void CdpFreeClient(longlong param_1)

{
  if (*(longlong *)(param_1 + 8) != 0) {
    CdDereferenceServer(*(longlong *)(param_1 + 8));
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    ObfDereferenceObject();
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== CdpCompleteServerConnection @ 14000f2d0 =====

undefined8 CdpCompleteServerConnection(undefined8 param_1,longlong param_2,longlong *param_3)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  byte bVar6;
  undefined8 uVar7;
  longlong *plVar8;
  
  lVar2 = *param_3;
  lVar3 = *(longlong *)(lVar2 + 0x18);
  LOCK();
  *(longlong *)(lVar3 + 0x18) = *(longlong *)(lVar3 + 0x18) + 1;
  UNLOCK();
  if (*(int *)(param_2 + 0x30) < 0) {
    *(undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) = 0;
    CdpFreeConnection(lVar2);
  }
  else {
    if (*(longlong *)(param_2 + 0x38) == 0x18) {
      *(longlong *)(lVar2 + 0x28) = param_3[1];
      *(longlong *)(lVar2 + 0x30) = param_3[2];
      *(longlong *)(lVar2 + 0x38) = param_3[3];
    }
    bVar6 = KeGetCurrentIrql();
    if (bVar6 < 2) {
      KeEnterCriticalRegion();
    }
    ExAcquirePushLockExclusiveEx(lVar3 + 0x28,0);
    plVar8 = (longlong *)(lVar2 + 8);
    plVar4 = *(longlong **)(lVar3 + 0xd0);
    if (*plVar4 != lVar3 + 200) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      uVar7 = (*pcVar5)();
      return uVar7;
    }
    *(longlong **)(lVar2 + 0x10) = plVar4;
    *plVar8 = lVar3 + 200;
    *plVar4 = (longlong)plVar8;
    *(longlong **)(lVar3 + 0xd0) = plVar8;
    ExReleasePushLockExclusiveEx(lVar3 + 0x28,0);
    if (bVar6 < 2) {
      KeLeaveCriticalRegion();
    }
  }
  ExFreePoolWithTag(param_3,0);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  CdDereferenceServer(lVar3);
  return 0;
}



===== CdDereferenceServer @ 14000f420 =====

void CdDereferenceServer(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  byte bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  uVar5 = *(ulonglong *)(param_1 + 0x18);
  do {
    uVar6 = uVar5;
    uVar7 = uVar6 - 1 | 0x8000000000000000;
    if (uVar6 != 2) {
      uVar7 = uVar6 - 1;
    }
    LOCK();
    uVar5 = *(ulonglong *)(param_1 + 0x18);
    if (uVar6 == uVar5) {
      *(ulonglong *)(param_1 + 0x18) = uVar7;
      uVar5 = uVar6;
    }
    else {
    }
    UNLOCK();
  } while (uVar5 != uVar6);
  if (uVar6 == 2) {
    CdDisconnectIoPipe((undefined8 *)(param_1 + 0x40));
    LOCK();
    plVar1 = (longlong *)(param_1 + 0x18);
    lVar2 = *plVar1;
    *plVar1 = *plVar1 + -0x8000000000000000;
    UNLOCK();
    uVar6 = lVar2 + 0x8000000000000001;
  }
  if (uVar6 != 1) {
    return;
  }
  bVar4 = KeGetCurrentIrql();
  if (bVar4 < 2) {
    KeEnterCriticalRegion();
  }
  ExAcquirePushLockExclusiveEx(&CdpServerListLock,0);
  lVar2 = *(longlong *)(param_1 + 8);
  if ((*(longlong *)(lVar2 + 8) != param_1 + 8) ||
     (plVar1 = *(longlong **)(param_1 + 0x10), *plVar1 != param_1 + 8)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar1 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar1;
  ExReleasePushLockExclusiveEx(&CdpServerListLock,0);
  if (bVar4 < 2) {
    KeLeaveCriticalRegion();
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    ObDereferenceSecurityDescriptor(*(longlong *)(param_1 + 0x38),1);
  }
  if (*(longlong *)(param_1 + 0xc0) != 0) {
    ObfDereferenceObject();
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== CdDisconnectIoPipe @ 14000f570 =====

void CdDisconnectIoPipe(undefined8 *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong ***ppplVar3;
  longlong **pplVar4;
  code *pcVar5;
  byte bVar6;
  ulonglong uVar7;
  longlong ***ppplVar8;
  undefined8 uVar9;
  longlong ***ppplVar10;
  uint uVar11;
  longlong ***local_28;
  longlong ***local_20;
  
  local_20 = (longlong ***)&local_28;
  local_28 = (longlong ***)&local_28;
  ppplVar10 = (longlong ***)0x0;
  bVar6 = KeGetCurrentIrql();
  if (bVar6 < 2) {
    KeEnterCriticalRegion();
  }
  ExAcquirePushLockExclusiveEx(*param_1);
  *(undefined1 *)(param_1 + 1) = 0;
  if (param_1[2] != 0) {
    LOCK();
    plVar1 = (longlong *)(param_1[2] + 0x68);
    lVar2 = *plVar1;
    *plVar1 = 0;
    UNLOCK();
    if (lVar2 != 0) {
      uVar7 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar7 == 0) {
        ppplVar8 = (longlong ***)(param_1[2] + 0xa8);
        if ((longlong ****)*local_20 != &local_28) goto LAB_14000f7c9;
        *(longlong ****)(param_1[2] + 0xb0) = local_20;
        *ppplVar8 = (longlong **)&local_28;
        *local_20 = (longlong **)ppplVar8;
        local_20 = ppplVar8;
      }
      else {
        ppplVar10 = (longlong ***)param_1[2];
      }
      param_1[2] = 0;
    }
  }
  uVar11 = 0;
  ppplVar8 = (longlong ***)(param_1 + 5);
  do {
    while (ppplVar3 = (longlong ***)*ppplVar8, ppplVar3 != ppplVar8) {
      uVar9 = CdpPrepareIoCompletion((longlong)(ppplVar3 + -0x15),'\0');
      if ((char)uVar9 != '\0') {
        if ((longlong ****)*local_20 != &local_28) goto LAB_14000f7c9;
        ppplVar3[1] = (longlong **)local_20;
        *ppplVar3 = (longlong **)&local_28;
        *local_20 = (longlong **)ppplVar3;
        local_20 = ppplVar3;
      }
    }
    uVar11 = uVar11 + 1;
    ppplVar8 = ppplVar8 + 2;
  } while (uVar11 < 5);
  while( true ) {
    do {
      ppplVar8 = (longlong ***)param_1[3];
      if (ppplVar8 == (longlong ***)(param_1 + 3)) {
        ExReleasePushLockExclusiveEx(*param_1);
        if (bVar6 < 2) {
          KeLeaveCriticalRegion();
        }
        uVar7 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar7 == 0) goto LAB_14000f730;
        if (ppplVar10 == (longlong ***)0x0) goto LAB_14000f730;
        *(undefined4 *)(ppplVar10 + 6) = 0xc00000b0;
        ppplVar10[7] = (longlong **)0x0;
        do {
          IofCompleteRequest(ppplVar10,0);
LAB_14000f730:
          while( true ) {
            ppplVar8 = local_28;
            if ((longlong ****)local_28 == &local_28) {
              return;
            }
            if (((longlong ****)local_28[1] != &local_28) ||
               (ppplVar3 = (longlong ***)*local_28, (longlong ***)ppplVar3[1] != local_28))
            goto LAB_14000f7c9;
            ppplVar3[1] = (longlong **)&local_28;
            ppplVar10 = local_28 + -0x15;
            local_28 = ppplVar3;
            uVar7 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar7 == 0) break;
            pplVar4 = ppplVar8[-5];
            ppplVar8[-5] = (longlong **)0x0;
            *(undefined4 *)(ppplVar8 + -0xf) = 0xc00000b0;
            ppplVar8[-0xe] = (longlong **)0x0;
            IofCompleteRequest();
            if (pplVar4 != (longlong **)0x0) {
              ObfDereferenceObject(pplVar4);
            }
          }
          *(undefined4 *)(ppplVar8 + -0xf) = 0xc00000b0;
          ppplVar8[-0xe] = (longlong **)0x0;
        } while( true );
      }
      uVar9 = CdpPrepareIoCompletion((longlong)(ppplVar8 + -0x15),'\0');
    } while ((char)uVar9 == '\0');
    if ((longlong ****)*local_20 != &local_28) break;
    ppplVar8[1] = (longlong **)local_20;
    *ppplVar8 = (longlong **)&local_28;
    *local_20 = (longlong **)ppplVar8;
    local_20 = ppplVar8;
  }
LAB_14000f7c9:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  return;
}



===== CdpAllocateClient @ 14000f800 =====

void CdpAllocateClient(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)ExAllocatePool2(0x100,0x28,0x6c436443);
  if (puVar1 != (undefined8 *)0x0) {
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    *puVar1 = &CdClientType;
  }
  return;
}



===== CdFreeMdlChain @ 14000f850 =====

void CdFreeMdlChain(longlong *param_1)

{
  longlong *plVar1;
  
  if (param_1 != (longlong *)0x0) {
    do {
      plVar1 = (longlong *)*param_1;
      if ((*(byte *)((longlong)param_1 + 10) & 2) != 0) {
        MmUnlockPages(param_1);
      }
      IoFreeMdl(param_1);
      param_1 = plVar1;
    } while (plVar1 != (longlong *)0x0);
  }
  return;
}



===== CdpAllocateServer @ 14000f8b0 =====

undefined8 CdpAllocateServer(undefined8 *param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *_Dst;
  undefined8 uVar3;
  
  _Dst = (undefined8 *)ExAllocatePool2(0x101,0x108,0x65536443);
  if (_Dst == (undefined8 *)0x0) {
    return 0xc000009a;
  }
  memset(_Dst,0,0x108);
  _Dst[3] = 1;
  *_Dst = &CdServerType;
  puVar1 = _Dst + 0x19;
  _Dst[0x1a] = puVar1;
  *puVar1 = puVar1;
  puVar1 = _Dst + 0x1e;
  _Dst[0x1f] = puVar1;
  *puVar1 = puVar1;
  CdInitializeIoPipe(_Dst + 8,_Dst + 5);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&CdpServerListLock,0);
  puVar1 = _Dst + 1;
  if ((undefined *)*DAT_1400061c8 == &CdpServerList) {
    *puVar1 = &CdpServerList;
    _Dst[2] = DAT_1400061c8;
    *DAT_1400061c8 = puVar1;
    DAT_1400061c8 = puVar1;
    ExReleasePushLockExclusiveEx(&CdpServerListLock,0);
    KeLeaveCriticalRegion();
    *param_1 = _Dst;
    return 0;
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  uVar3 = (*pcVar2)();
  return uVar3;
}



===== CdInitializeIoPipe @ 14000f9d0 =====

void CdInitializeIoPipe(undefined8 *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  *param_1 = param_2;
  puVar1 = param_1 + 3;
  *(undefined1 *)(param_1 + 1) = 1;
  param_1[2] = 0;
  param_1[4] = puVar1;
  *puVar1 = puVar1;
  puVar1 = param_1 + 5;
  param_1[6] = puVar1;
  *puVar1 = puVar1;
  puVar1 = param_1 + 7;
  param_1[8] = puVar1;
  *puVar1 = puVar1;
  puVar1 = param_1 + 9;
  param_1[10] = puVar1;
  *puVar1 = puVar1;
  puVar1 = param_1 + 0xb;
  param_1[0xc] = puVar1;
  *puVar1 = puVar1;
  puVar1 = param_1 + 0xd;
  param_1[0xe] = puVar1;
  *puVar1 = puVar1;
  return;
}



===== CdCreateSecurityDescriptor @ 14000fa30 =====

ulonglong CdCreateSecurityDescriptor(undefined8 *param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  
  local_res10 = 0;
  local_res18[0] = 0;
  uVar2 = SeAssignSecurityEx(0,*(undefined8 *)(param_2 + 0x40),&local_res10,0,0,0x700,param_2 + 0x20
                             ,&CdpGenericMapping,1);
  if (-1 < (int)uVar2) {
    uVar1 = ObLogSecurityDescriptor(local_res10,local_res18,1);
    SeDeassignSecurity(&local_res10);
    if ((int)uVar1 < 0) {
      return (ulonglong)uVar1;
    }
    *param_1 = local_res18[0];
    uVar2 = 0;
  }
  return uVar2;
}



===== CdGetConnectionFromFileObject @ 14000faf0 =====

undefined8 * CdGetConnectionFromFileObject(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  if ((((param_1 == 0) || (*(longlong *)(param_1 + 8) != CdDeviceObject)) ||
      (puVar1 = *(undefined8 **)(param_1 + 0x18), puVar1 == (undefined8 *)0x0)) ||
     (((undefined *)*puVar1 != &CdConnectionType || (puVar1[4] != param_2)))) {
    puVar1 = (undefined8 *)0x0;
  }
  return puVar1;
}



===== CdpGetProcessServerFromConnection @ 14000fb30 =====

ulonglong CdpGetProcessServerFromConnection(longlong *param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 local_res20;
  longlong local_78;
  longlong local_70;
  ulonglong local_68;
  longlong local_60 [2];
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_70 = 0;
  local_68 = 0;
  local_4c = 0;
  local_34 = 0;
  local_res20 = 0;
  lVar7 = CdpGetRequestorProcess(param_2);
  if (lVar7 == 0) {
    uVar8 = 0xc000000b;
  }
  else {
    local_60[1] = 0;
    if (param_3 == -1) {
      local_60[0] = PsGetProcessInheritedFromUniqueProcessId(lVar7);
    }
    else {
      local_60[0] = param_3;
    }
    local_50 = 0x30;
    local_48 = 0;
    local_38 = 0x600;
    local_40 = 0;
    local_30 = 0;
    uStack_28 = 0;
    uVar8 = ZwOpenProcess(&local_res20,0x1000,&local_50,local_60);
    if (-1 < (int)uVar8) {
      local_78 = 0;
      uVar4 = ObReferenceObjectByHandle(local_res20,0x1000,0,0,&local_78,0);
      lVar2 = local_78;
      uVar8 = (ulonglong)uVar4;
      ZwClose(local_res20);
      if (-1 < (int)uVar4) {
        iVar5 = PsGetProcessSessionId(lVar2);
        iVar6 = PsGetProcessSessionId(lVar7);
        if ((iVar5 != iVar6) && (cVar3 = PsIsSystemProcess(lVar7), cVar3 == '\0')) {
          ObfDereferenceObject(lVar2);
          return 0xc0000022;
        }
        uVar9 = CdGetProcessConnection(&local_68,&local_70,param_2,lVar2);
        uVar8 = uVar9 & 0xffffffff;
        ObfDereferenceObject(lVar2);
        if (-1 < (int)uVar9) {
          lVar7 = *(longlong *)(local_70 + 0x18);
          *param_1 = lVar7;
          LOCK();
          plVar1 = (longlong *)(lVar7 + 0x18);
          *plVar1 = *plVar1 + 1;
          UNLOCK();
          ObfDereferenceObject(local_68);
          return 0;
        }
      }
    }
  }
  return uVar8;
}



===== CdpClientIoctl @ 14000fd00 =====

ulonglong CdpClientIoctl(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  uint uVar2;
  
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x500016) {
    if ((*(uint *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x50) & 2) != 0) {
      uVar1 = CdClientUserIo(param_1,param_2);
      return uVar1;
    }
    uVar2 = 0xc000000d;
  }
  else {
    uVar2 = 0xc0000010;
  }
  *(uint *)(param_2 + 0x30) = uVar2;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return (ulonglong)uVar2;
}



===== CdpConnectionIoctl @ 14000fd70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CdpConnectionIoctl(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStackY_88 [32];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x500016) {
    if ((*(uint *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x50) & 2) != 0) {
      local_50 = 0;
      uStack_48 = 0;
      local_40 = 0;
      uStack_38 = 0;
      local_30 = 0;
      uStack_28 = 0;
      if (*(char *)(param_2 + 0x40) == '\x01') {
        lVar3 = IoGetRequestorProcess(param_2);
      }
      else {
        lVar3 = *(longlong *)PsInitialSystemProcess_exref;
      }
      if (lVar3 == 0) {
        uVar4 = 0xc000000b;
      }
      else if (lVar3 == *(longlong *)(param_1 + 0x20)) {
        if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x10) {
          uVar4 = 0xc0000206;
        }
        else {
          plVar1 = *(longlong **)(param_2 + 0x18);
          if (*plVar1 == 0) {
            uVar5 = CdSubmitUserIo(*(longlong *)(param_1 + 0x18),0,param_2,
                                   *(undefined8 *)(param_1 + 0x28),0);
            uVar4 = uVar5 & 0xffffffff;
            if (-1 < (int)uVar5) {
              return uVar4;
            }
          }
          else {
            KeStackAttachProcess(lVar3,&local_50);
            uVar2 = ObReferenceObjectByHandle(*plVar1,0,*(undefined8 *)IoFileObjectType_exref,1);
            uVar4 = (ulonglong)uVar2;
            KeUnstackDetachProcess(&local_50);
            if (-1 < (int)uVar2) {
              if (((_DAT_00000008 == CdDeviceObject) && (puRam0000000000000018 != (undefined8 *)0x0)
                  ) && ((undefined *)*puRam0000000000000018 == &CdClientType)) {
                uVar4 = CdClientUserIo((longlong)puRam0000000000000018,param_2);
                ObfDereferenceObject(0);
                return uVar4 & 0xffffffff;
              }
              ObfDereferenceObject(0);
              goto LAB_14000ff05;
            }
          }
        }
      }
      else {
LAB_14000ff05:
        uVar4 = 0xc0000008;
      }
      *(int *)(param_2 + 0x30) = (int)uVar4;
      *(undefined8 *)(param_2 + 0x38) = 0;
      goto LAB_14000ff11;
    }
    uVar4 = 0xc000000d;
  }
  else {
    uVar4 = 0xc0000010;
  }
  *(int *)(param_2 + 0x30) = (int)uVar4;
  *(undefined8 *)(param_2 + 0x38) = 0;
LAB_14000ff11:
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== CdClientUserIo @ 14000ff70 =====

ulonglong CdClientUserIo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  longlong local_18;
  longlong lStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lStack_10 = 0;
  uVar2 = CdpGetClientTarget(param_1,param_2,&local_28);
  lVar1 = lStack_10;
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar2 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      uVar3 = CdSubmitUserIo(local_18,0,param_2,local_28,uStack_20);
      uVar3 = uVar3 & 0xffffffff;
      if (lVar1 != 0) {
        ObfDereferenceObject(lVar1);
      }
    }
    else {
      uVar3 = CdSubmitUserIo(local_18,lVar1,param_2,local_28,uStack_20);
      uVar3 = uVar3 & 0xffffffff;
    }
    if (-1 < (int)uVar3) {
      return uVar3;
    }
  }
  uVar2 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 != 0) && (lVar1 != 0)) {
    ObfDereferenceObject(lVar1);
  }
  *(int *)(param_2 + 0x30) = (int)uVar3;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== CdSubmitUserIo @ 140010050 =====

ulonglong CdSubmitUserIo(longlong param_1,longlong param_2,longlong param_3,undefined8 param_4,
                        undefined8 param_5)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  char cVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong *local_res18 [2];
  longlong *local_38 [2];
  
  lVar2 = *(longlong *)(param_3 + 0x18);
  local_res18[0] = (longlong *)0x0;
  local_38[0] = (longlong *)0x0;
  if (*(char *)(param_3 + 0x40) == '\x01') {
    lVar7 = IoGetRequestorProcess(param_3);
  }
  else {
    lVar7 = *(longlong *)PsInitialSystemProcess_exref;
  }
  lVar8 = PsGetCurrentProcess();
  if ((lVar8 != lVar7) && (cVar5 = PsIsSystemProcess(lVar7), cVar5 == '\0')) {
    return 0xc000000d;
  }
  uVar6 = *(uint *)(*(longlong *)(param_3 + 0xb8) + 0x10);
  if (0xf < uVar6) {
    uVar1 = *(uint *)(lVar2 + 8);
    uVar10 = *(int *)(lVar2 + 0xc) + uVar1;
    if ((uVar10 < uVar1) || (0xffffffe < uVar10)) {
      return 0xc0000095;
    }
    if (((ulonglong)uVar10 + 1) * 0x10 <= (ulonglong)uVar6) {
      uVar9 = CdpCreateMdlChain(local_res18,lVar2 + 0x10,uVar1,*(char *)(param_3 + 0x40));
      if ((int)uVar9 < 0) {
        return uVar9;
      }
      uVar9 = CdpCreateMdlChain(local_38,((ulonglong)*(uint *)(lVar2 + 8) + 1) * 0x10 + lVar2,
                                *(uint *)(lVar2 + 0xc),*(char *)(param_3 + 0x40));
      plVar4 = local_38[0];
      plVar3 = local_res18[0];
      if ((int)uVar9 < 0) {
        CdFreeMdlChain(local_res18[0]);
        return uVar9 & 0xffffffff;
      }
      CdInitializeIo(param_3,param_1 + 0x40,7,param_4,param_5,local_res18[0],local_38[0]);
      uVar9 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 == 0) {
        param_2 = 0;
      }
      uVar6 = CdAddIoToPipe(param_3,param_2);
      if ((int)uVar6 < 0) {
        CdFreeMdlChain(plVar3);
        CdFreeMdlChain(plVar4);
        return (ulonglong)uVar6;
      }
      return 0x103;
    }
  }
  return 0xc0000206;
}



===== CdpPrepareIoCompletion @ 140010220 =====

undefined8 CdpPrepareIoCompletion(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  code *pcVar5;
  longlong *plVar6;
  undefined8 uVar7;
  longlong *plVar8;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  plVar8 = (longlong *)(param_1 + 0xa8);
  lVar2 = *plVar8;
  if ((*(longlong **)(lVar2 + 8) != plVar8) ||
     (plVar6 = *(longlong **)(param_1 + 0xb0), (longlong *)*plVar6 != plVar8)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    uVar7 = (*pcVar5)();
    return uVar7;
  }
  *plVar6 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar6;
  if (param_2 == '\0') {
    plVar6 = (longlong *)0x0;
    if ((*(char *)(lVar1 + 1) != '\x02') && (*(char *)(lVar1 + 1) != '\x04')) {
      LOCK();
      plVar6 = *(longlong **)(param_1 + 0x68);
      *(longlong *)(param_1 + 0x68) = 0;
      UNLOCK();
      if (plVar6 == (longlong *)0x0) {
        *(longlong **)(param_1 + 0xb0) = plVar8;
        *plVar8 = (longlong)plVar8;
        return 0;
      }
    }
  }
  puVar3 = *(undefined8 **)(lVar1 + 0x20);
  if (puVar3 != *(undefined8 **)(param_1 + 8)) {
    while (puVar3 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)*puVar3;
      if ((*(byte *)((longlong)puVar3 + 10) & 2) != 0) {
        MmUnlockPages(puVar3);
      }
      plVar6 = (longlong *)IoFreeMdl(puVar3);
      puVar3 = puVar4;
    }
  }
  puVar3 = *(undefined8 **)(lVar1 + 0x18);
  if (puVar3 != *(undefined8 **)(param_1 + 8)) {
    while (puVar3 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)*puVar3;
      if ((*(byte *)((longlong)puVar3 + 10) & 2) != 0) {
        MmUnlockPages(puVar3);
      }
      plVar6 = (longlong *)IoFreeMdl(puVar3);
      puVar3 = puVar4;
    }
  }
  return CONCAT71((int7)((ulonglong)plVar6 >> 8),1);
}



===== CdpFastIoDeviceControl @ 140010340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
CdpFastIoDeviceControl
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
          undefined8 param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8)

{
  undefined8 *puVar1;
  uint *puVar2;
  undefined8 uVar3;
  
  if (((param_1 == 0) || (puVar1 = *(undefined8 **)(param_1 + 0x18), puVar1 == (undefined8 *)0x0))
     || (puVar2 = (uint *)*puVar1, puVar2 == (uint *)0x0)) {
    *(undefined8 *)(param_8 + 2) = 0;
    *param_8 = 0xc000000d;
    return CONCAT71((int7)((ulonglong)param_8 >> 8),1);
  }
  if (*(code **)(puVar2 + 0xc) == (code *)0x0) {
    return (ulonglong)puVar2 & 0xffffffffffffff00;
  }
  uVar3 = (**(code **)(puVar2 + 0xc))
                    ((longlong)puVar1 - (ulonglong)*puVar2,param_3,param_4,param_5,param_6,param_7,
                     param_8);
  return uVar3;
}



===== CdpDispatchDeviceControl @ 1400103f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CdpDispatchDeviceControl(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((lVar1 == 0) || (puVar2 = *(undefined8 **)(lVar1 + 0x18), puVar2 == (undefined8 *)0x0)) ||
     (puVar3 = (uint *)*puVar2, puVar3 == (uint *)0x0)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc000000d;
  }
  else if (*(code **)(puVar3 + 6) == (code *)0x0) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc0000010;
  }
  else {
    uVar4 = (**(code **)(puVar3 + 6))((longlong)puVar2 - (ulonglong)*puVar3,param_2);
  }
  return uVar4;
}



===== CdpConnectionFastIoctl @ 140010490 =====

longlong CdpConnectionFastIoctl
                   (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                   int param_5,int param_6,undefined4 *param_7)

{
  char cVar1;
  undefined8 in_RAX;
  uint7 uVar3;
  longlong lVar2;
  
  *(undefined8 *)(param_7 + 2) = 0;
  uVar3 = (uint7)((ulonglong)in_RAX >> 8);
  if (param_6 == 0x500023) {
    if (param_5 == 8) {
      cVar1 = ExGetPreviousMode();
      if (cVar1 == '\0') {
        lVar2 = *(longlong *)(param_1 + 0x18);
        *param_4 = *(undefined8 *)(lVar2 + 0xb8);
      }
      else {
        ProbeForWrite(param_4,8,4);
        lVar2 = *(longlong *)(param_1 + 0x18);
        *param_4 = *(undefined8 *)(lVar2 + 0xb8);
      }
      *param_7 = 0;
      lVar2 = CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
    }
    else {
      *param_7 = 0xc0000206;
      lVar2 = CONCAT71(uVar3,1);
    }
  }
  else {
    lVar2 = (ulonglong)uVar3 << 8;
  }
  return lVar2;
}



===== CdpDispatchWrite @ 140010550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CdpDispatchWrite(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((lVar1 == 0) || (puVar2 = *(undefined8 **)(lVar1 + 0x18), puVar2 == (undefined8 *)0x0)) ||
     (puVar3 = (uint *)*puVar2, puVar3 == (uint *)0x0)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc000000d;
  }
  else if (*(code **)(puVar3 + 4) == (code *)0x0) {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc00000bb;
  }
  else {
    uVar4 = (**(code **)(puVar3 + 4))((longlong)puVar2 - (ulonglong)*puVar3,param_2);
  }
  return uVar4;
}



===== CdpDispatchCreate @ 1400105f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CdpDispatchCreate(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar4 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  while( true ) {
    if (0xb < uVar4) {
      *(undefined4 *)(param_2 + 0x30) = 0xc0000225;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      return 0xc0000225;
    }
    uVar5 = (ulonglong)uVar4;
    iVar2 = RtlCompareUnicodeString(lVar1 + 0x58,&CdpObjectCreationTable + uVar5 * 0x20,1);
    if (iVar2 == 0) break;
    uVar4 = uVar4 + 1;
  }
  uVar3 = (*(code *)(&PTR_CdCreateConnection_1400054d0)[uVar5 * 4])
                    (param_2,(&DAT_1400054d8)[uVar5 * 8]);
  return uVar3;
}



===== CdpDispatchCleanup @ 1400106b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CdpDispatchCleanup(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((lVar1 == 0) || (puVar2 = *(undefined8 **)(lVar1 + 0x18), puVar2 == (undefined8 *)0x0)) ||
     (puVar3 = (uint *)*puVar2, puVar3 == (uint *)0x0)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc000000d;
  }
  else {
    if (*(code **)(puVar3 + 8) != (code *)0x0) {
      uVar4 = (**(code **)(puVar3 + 8))((longlong)puVar2 - (ulonglong)*puVar3,param_2);
      return uVar4;
    }
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0;
  }
  return uVar4;
}



===== CdpDispatchClose @ 140010750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CdpDispatchClose(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((lVar1 == 0) || (puVar2 = *(undefined8 **)(lVar1 + 0x18), puVar2 == (undefined8 *)0x0)) ||
     (puVar3 = (uint *)*puVar2, puVar3 == (uint *)0x0)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc000000d;
  }
  else if (*(code **)(puVar3 + 10) == (code *)0x0) {
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(puVar3 + 10))((longlong)puVar2 - (ulonglong)*puVar3,param_2);
  }
  return uVar4;
}



===== CdpDispatchQuerySecurity @ 1400107e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CdpDispatchQuerySecurity(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((lVar1 == 0) || (puVar2 = *(undefined8 **)(lVar1 + 0x18), puVar2 == (undefined8 *)0x0)) ||
     (puVar3 = (uint *)*puVar2, puVar3 == (uint *)0x0)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc000000d;
  }
  else {
    if (*(code **)(puVar3 + 0x10) != (code *)0x0) {
      uVar4 = (**(code **)(puVar3 + 0x10))((longlong)puVar2 - (ulonglong)*puVar3,param_2);
      return uVar4;
    }
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc00000bb;
  }
  return uVar4;
}



===== CdCreateReferenceObject @ 140010880 =====

int CdCreateReferenceObject(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 local_res8;
  
  local_res8 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  lVar2 = *(longlong *)(lVar1 + 0x40);
  if (((lVar2 == 0) || (*(longlong *)(lVar2 + 8) != CdDeviceObject)) ||
     (puVar5 = *(undefined8 **)(lVar2 + 0x18), puVar5 == (undefined8 *)0x0)) {
    iVar3 = -0x3ffffff8;
  }
  else {
    if ((undefined *)*puVar5 != &CdServerType) {
      if ((undefined *)*puVar5 != &CdConnectionType) {
        iVar3 = -0x3fffffdc;
        goto LAB_140010911;
      }
      puVar5 = (undefined8 *)puVar5[3];
    }
    uVar4 = CdpAllocateReferenceObject(&local_res8,(longlong)puVar5);
    iVar3 = (int)uVar4;
    if (-1 < iVar3) {
      *(undefined8 *)(lVar1 + 0x18) = local_res8;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x38) = 0;
      IofCompleteRequest(param_1,0);
      return 0;
    }
  }
LAB_140010911:
  *(int *)(param_1 + 0x30) = iVar3;
  *(undefined8 *)(param_1 + 0x38) = 0;
  IofCompleteRequest(param_1,0);
  return iVar3;
}



===== CdpAllocateReferenceObject @ 140010960 =====

undefined8 CdpAllocateReferenceObject(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)ExAllocatePool2(0x101,0x10,0x66526443);
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    puVar1[1] = param_2;
    *puVar1 = &CdReferenceType;
    LOCK();
    *(longlong *)(param_2 + 0x18) = *(longlong *)(param_2 + 0x18) + 1;
    UNLOCK();
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



===== CdpCompleteClientCreation @ 1400109d0 =====

undefined8 CdpCompleteClientCreation(undefined8 param_1,longlong param_2,longlong *param_3)

{
  byte *pbVar1;
  
  if (*(int *)(param_2 + 0x30) < 0) {
    CdpFreeClient(*param_3);
  }
  else {
    *(undefined8 *)(*param_3 + 0x10) = *(undefined8 *)(param_2 + 0x38);
  }
  ExFreePoolWithTag(param_3,0);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  return 0;
}



===== CdpServerQuerySecurity @ 140010a30 =====

int CdpServerQuerySecurity(longlong param_1,longlong param_2)

{
  int iVar1;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  
  local_res8[0] = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  local_res10[0] = *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 8);
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1 + 0x28,0);
  iVar1 = SeQuerySecurityDescriptorInfo
                    (local_res10,*(undefined8 *)(param_2 + 0x70),local_res8,param_1 + 0x38);
  ExReleasePushLockSharedEx(param_1 + 0x28,0);
  KeLeaveCriticalRegion();
  if (iVar1 == -0x3fffffdd) {
    iVar1 = -0x7ffffffb;
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res8[0];
  *(int *)(param_2 + 0x30) = iVar1;
  IofCompleteRequest(param_2,0);
  return iVar1;
}



===== CdCompleteRoutineFreeIrp @ 140010b00 =====

undefined8 CdCompleteRoutineFreeIrp(undefined8 param_1,undefined8 param_2)

{
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== CdpDispatchRead @ 140010b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CdpDispatchRead(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((lVar1 == 0) || (puVar2 = *(undefined8 **)(lVar1 + 0x18), puVar2 == (undefined8 *)0x0)) ||
     (puVar3 = (uint *)*puVar2, puVar3 == (uint *)0x0)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc000000d;
  }
  else if (*(code **)(puVar3 + 2) == (code *)0x0) {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc00000bb;
  }
  else {
    uVar4 = (**(code **)(puVar3 + 2))((longlong)puVar2 - (ulonglong)*puVar3,param_2);
  }
  return uVar4;
}



===== CdpDispatchFlushBuffers @ 140010bd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CdpDispatchFlushBuffers(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if (((lVar1 == 0) || (puVar2 = *(undefined8 **)(lVar1 + 0x18), puVar2 == (undefined8 *)0x0)) ||
     (puVar3 = (uint *)*puVar2, puVar3 == (uint *)0x0)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc000000d;
  }
  else {
    if (*(code **)(puVar3 + 0xe) != (code *)0x0) {
      uVar4 = (**(code **)(puVar3 + 0xe))((longlong)puVar2 - (ulonglong)*puVar3,param_2);
      return uVar4;
    }
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar4 = 0xc00000bb;
  }
  return uVar4;
}



===== CdpClientRead @ 140010c70 =====

int CdpClientRead(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  longlong local_18;
  longlong lStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lStack_10 = 0;
  uVar4 = CdpGetClientTarget(param_1,param_2,&local_28);
  lVar2 = lStack_10;
  iVar3 = (int)uVar4;
  if (-1 < iVar3) {
    lVar5 = *(longlong *)(param_2 + 0xb8);
    uVar1 = *(undefined8 *)(param_2 + 8);
    *(longlong *)(lVar5 + -0x40) = local_18 + 0x40;
    *(undefined8 *)(lVar5 + -0x38) = uStack_20;
    *(undefined2 *)(lVar5 + -0x48) = 0x60f;
    *(undefined8 *)(lVar5 + -0x30) = 0;
    *(undefined8 *)(lVar5 + -0x28) = uVar1;
    *(undefined8 *)(param_2 + 0x78) = local_28;
    uVar4 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      *(undefined8 *)(param_2 + 0x80) = 0;
    }
    ZwAllocateLocallyUniqueId(param_2 + 0x88);
    uVar4 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = lVar2;
    }
    iVar3 = CdAddIoToPipe(param_2,lVar5);
    uVar4 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar4 == 0) && (lVar2 != 0)) {
      ObfDereferenceObject(lVar2);
    }
    if (-1 < iVar3) {
      return 0x103;
    }
  }
  uVar4 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar4 != 0) && (lVar2 != 0)) {
    ObfDereferenceObject(lVar2);
  }
  *(int *)(param_2 + 0x30) = iVar3;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return iVar3;
}



===== CdpClientWrite @ 140010db0 =====

int CdpClientWrite(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  longlong local_18;
  longlong lStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lStack_10 = 0;
  uVar4 = CdpGetClientTarget(param_1,param_2,&local_28);
  lVar2 = lStack_10;
  iVar3 = (int)uVar4;
  if (-1 < iVar3) {
    lVar5 = *(longlong *)(param_2 + 0xb8);
    uVar1 = *(undefined8 *)(param_2 + 8);
    *(longlong *)(lVar5 + -0x40) = local_18 + 0x40;
    *(undefined8 *)(lVar5 + -0x38) = uStack_20;
    *(undefined2 *)(lVar5 + -0x48) = 0x50f;
    *(undefined8 *)(lVar5 + -0x30) = uVar1;
    *(undefined8 *)(lVar5 + -0x28) = 0;
    *(undefined8 *)(param_2 + 0x78) = local_28;
    uVar4 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      *(undefined8 *)(param_2 + 0x80) = 0;
    }
    ZwAllocateLocallyUniqueId(param_2 + 0x88);
    uVar4 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = lVar2;
    }
    iVar3 = CdAddIoToPipe(param_2,lVar5);
    uVar4 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar4 == 0) && (lVar2 != 0)) {
      ObfDereferenceObject(lVar2);
    }
    if (-1 < iVar3) {
      return 0x103;
    }
  }
  uVar4 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar4 != 0) && (lVar2 != 0)) {
    ObfDereferenceObject(lVar2);
  }
  *(int *)(param_2 + 0x30) = iVar3;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return iVar3;
}



===== CdpGetClientTarget @ 140010ef0 =====

ulonglong CdpGetClientTarget(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong local_res8;
  ulonglong local_res20;
  
  local_res8 = 0;
  uVar2 = Feature_3237903672__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    param_3[3] = 0;
  }
  local_res20 = 0;
  if ((*(uint *)(param_1 + 0x20) & 1) == 0) {
    lVar3 = IoGetRequestorProcess(param_2);
    if (lVar3 == 0) {
      return 0xc000000b;
    }
    uVar2 = CdGetProcessConnection(&local_res20,&local_res8,0,lVar3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    lVar3 = local_res8;
  }
  else {
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 8) + 0xe0);
    if (lVar3 == 0) {
      return 0xc0000008;
    }
  }
  if ((*(longlong *)(param_1 + 8) != 0) &&
     (*(longlong *)(param_1 + 8) != *(longlong *)(lVar3 + 0x18))) {
    if ((*(uint *)(param_1 + 0x20) & 1) == 0) {
      ObfDereferenceObject(local_res20);
    }
    return 0xc0000008;
  }
  param_3[2] = *(undefined8 *)(lVar3 + 0x18);
  *param_3 = *(undefined8 *)(lVar3 + 0x28);
  uVar1 = *(uint *)(param_1 + 0x20);
  param_3[3] = local_res20;
  if ((uVar1 & 2) == 0) {
    if (*(int *)(param_1 + 0x10) == 1) {
      uVar4 = *(undefined8 *)(lVar3 + 0x30);
    }
    else {
      uVar4 = *(undefined8 *)(lVar3 + 0x38);
    }
  }
  else {
    uVar4 = *(undefined8 *)(param_1 + 0x10);
  }
  param_3[1] = uVar4;
  return 0;
}



===== entry @ 140011010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
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



===== DriverEntry @ 140011080 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1)

{
  int iVar1;
  longlong local_res8;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_18 = 0x1e001c;
  local_10 = L"\\Device\\ConDrv";
  local_res8 = 0;
  wil_InitializeFeatureStaging();
  _CdpBrokerListLock = 0;
  _DAT_140006218 = &CdpBrokerList;
  CdpBrokerList = &CdpBrokerList;
  DAT_1400061c8 = &CdpServerList;
  _CdpServerList = &CdpServerList;
  _CdpServerListLock = 0;
  RtlRunOnceInitialize(&CdpDisplayInitialized);
  *(undefined **)(param_1 + 0x50) = &CdpFastIoDispatchTable;
  *(code **)(param_1 + 0x68) = CdpUnload;
  *(code **)(param_1 + 0x70) = CdpDispatchCreate;
  *(code **)(param_1 + 0x90) = CdpDispatchWrite;
  *(code **)(param_1 + 0x88) = CdpDispatchRead;
  *(code **)(param_1 + 0x100) = CdpDispatchCleanup;
  *(code **)(param_1 + 0x80) = CdpDispatchClose;
  *(code **)(param_1 + 0x118) = CdpDispatchSetSecurity;
  *(code **)(param_1 + 0xb8) = CdpDispatchFlushBuffers;
  *(code **)(param_1 + 0x110) = CdpDispatchQuerySecurity;
  *(code **)(param_1 + 0xe0) = CdpDispatchDeviceControl;
  iVar1 = IoCreateDevice(param_1,0,&local_18,0x50,0x20000,0,&local_res8);
  if (-1 < iVar1) {
    CdDeviceObject = local_res8;
    *(undefined1 *)(local_res8 + 0x4c) = 2;
    *(uint *)(local_res8 + 0x30) = *(uint *)(local_res8 + 0x30) | 0x10;
    *(uint *)(local_res8 + 0x30) = *(uint *)(local_res8 + 0x30) & 0xffffff7f;
    return 0;
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
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14001124c =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &Feature_3237903672__private_descriptor;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
      if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') &&
          (*(char *)((longlong)plVar3 + 0x1e) == '\0')) &&
         (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
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
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001133c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &Feature_3237903672__private_descriptor;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


