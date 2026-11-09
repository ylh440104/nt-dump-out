
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



===== Feature_Servicing_ApplockerFilterOOBR__private_IsEnabledDeviceUsageNoInline @ 140001020 =====

ulonglong Feature_Servicing_ApplockerFilterOOBR__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_ApplockerFilterOOBR__private_featureState;
  if ((Feature_Servicing_ApplockerFilterOOBR__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_ApplockerFilterOOBR__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_ApplockerFilterOOBR__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_ApplockerFilterOOBR__private_IsEnabledFallback @ 140001058 =====

void Feature_Servicing_ApplockerFilterOOBR__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_ApplockerFilterOOBR__private_descriptor);
  return;
}



===== Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledDeviceUsageNoInline @ 140001074 =====

ulonglong Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_ApplockerPickBestClaim__private_featureState;
  if ((Feature_Servicing_ApplockerPickBestClaim__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_ApplockerPickBestClaim__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledFallback @ 1400010ac =====

void Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_ApplockerPickBestClaim__private_descriptor);
  return;
}



===== SmAcquireTrackLockExclusive @ 1400010c8 =====

void SmAcquireTrackLockExclusive(void)

{
  FltAcquireResourceExclusive(DAT_140006178);
  return;
}



===== SmAllocUninstallStringData @ 1400010ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SmAllocUninstallStringData(void)

{
  if (DAT_140006130 != (code *)0x0) {
    (*DAT_140006130)();
  }
  return;
}



===== SmGetTrackSessionOriginData @ 140001110 =====

longlong SmGetTrackSessionOriginData(void)

{
  longlong lVar1;
  
  lVar1 = 0;
  if (DAT_140006128 != (longlong *)0x0) {
    LOCK();
    if (*DAT_140006128 == 0) {
      *DAT_140006128 = 0;
    }
    else {
      lVar1 = *DAT_140006128;
    }
    UNLOCK();
  }
  return lVar1;
}



===== SmGetTrackSessionOriginDataLocked @ 140001130 =====

undefined8 SmGetTrackSessionOriginDataLocked(void)

{
  if (DAT_140006128 == (undefined8 *)0x0) {
    return 0;
  }
  return *DAT_140006128;
}



===== SmPostWrite @ 140001150 =====

undefined8 SmPostWrite(longlong param_1,undefined8 param_2,int *param_3)

{
  char cVar1;
  
  cVar1 = *(char *)(*(longlong *)(param_1 + 0x10) + 4);
  if ((cVar1 == '\x04') ||
     ((cVar1 == '\r' && (*(int *)(*(longlong *)(param_1 + 0x10) + 0x28) == 0x98268)))) {
    if (-1 < *(int *)(param_1 + 0x18)) {
      LOCK();
      if (*param_3 == 0) {
        *param_3 = 1;
      }
      UNLOCK();
    }
    FltReleaseContext(param_3);
  }
  return 0;
}



===== SmPreWrite @ 1400011a0 =====

undefined8 SmPreWrite(longlong param_1,longlong param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  int *local_res8 [4];
  
  local_res8[0] = (int *)0x0;
  cVar1 = *(char *)(*(longlong *)(param_1 + 0x10) + 4);
  if (((cVar1 == '\x04') ||
      ((cVar1 == '\r' && (*(int *)(*(longlong *)(param_1 + 0x10) + 0x28) == 0x98268)))) &&
     (iVar2 = FltGetStreamHandleContext
                        (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),local_res8)
     , -1 < iVar2)) {
    if (*local_res8[0] == 0) {
      *param_3 = local_res8[0];
      return 0;
    }
    FltReleaseContext();
  }
  return 1;
}



===== SmQueryTeardown @ 140001220 =====

undefined8 SmQueryTeardown(void)

{
  return 0;
}



===== SmReleaseOriginProcessData @ 14000122c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SmReleaseOriginProcessData(void)

{
  if (DAT_140006160 != (code *)0x0) {
    (*DAT_140006160)();
  }
  return;
}



===== SmReleaseTrackLock @ 140001250 =====

void SmReleaseTrackLock(void)

{
  FltReleaseResource(DAT_140006178);
  return;
}



===== SmUnload @ 140001280 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SmUnload(void)

{
  undefined8 uVar1;
  
  FltUnregisterFilter(DAT_140006188);
  CmUnRegisterCallback(DAT_140006118);
  ZwClose(DAT_140006190);
  uVar1 = DAT_140006030;
  DAT_140006030 = 0;
  _DAT_140006010 = 0;
  EtwUnregister(uVar1);
  if (g_EtwEventHandle != 0) {
    EtwUnregister();
    g_EtwEventHandle = 0;
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
  return 0;
}



===== SmpFindSubStr @ 140001354 =====

ulonglong SmpFindSubStr(undefined8 param_1,ushort *param_2,ushort *param_3)

{
  int iVar1;
  undefined4 extraout_var;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0xf;
  if (0xf < *param_2 >> 1) {
    uVar2 = (uint)(*param_3 >> 1);
    register0x00000020 = (BADSPACEBASE *)(ulonglong)(uVar2 + 0xf);
    if (uVar2 + 0xf <= (uint)(*param_2 >> 1)) {
      do {
        iVar1 = _wcsnicmp((wchar_t *)(*(longlong *)(param_2 + 4) + (ulonglong)uVar3 * 2),
                          *(wchar_t **)(param_3 + 4),(ulonglong)uVar2);
        if (iVar1 == 0) {
          return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),1);
        }
        uVar3 = uVar3 + 1;
        register0x00000020 = (BADSPACEBASE *)(ulonglong)(uVar2 + uVar3);
      } while (uVar2 + uVar3 <= (uint)(*param_2 >> 1));
    }
  }
  return (ulonglong)register0x00000020 & 0xffffffffffffff00;
}



===== SmpQueryFile @ 1400013f0 =====

void SmpQueryFile(undefined8 *param_1,undefined8 param_2)

{
  undefined4 local_res8 [8];
  
  local_res8[0] = 0;
  FltQueryInformationFile(*param_1,param_1[1],param_2,0x18,5,local_res8);
  return;
}



===== SmpReadFile @ 140001440 =====

void SmpReadFile(undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  FltReadFile(*param_1,param_1[1],param_2,param_3,param_4,4,0,0,0);
  return;
}



===== _tlgDefineProvider_annotation__Tlgg_hLogProviderProv @ 140001488 =====

void _tlgDefineProvider_annotation__Tlgg_hLogProviderProv(void)

{
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001494 =====

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
LAB_14000169d:
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
LAB_14000156f:
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
      if (param_3 == 4) goto LAB_14000169d;
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
        goto LAB_14000156f;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140001788 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar3 = (uVar2 ^ 1) << 2;
      goto LAB_140001859;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140001859;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140001859;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140001859;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140001859;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140001859;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140001859;
    }
  }
  uVar3 = 0xff;
LAB_140001859:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar3);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400018b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  uint local_60 [6];
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_60,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_48 = *puVar2;
  uStack_44 = puVar2[1];
  uStack_40 = puVar2[2];
  uStack_3c = puVar2[3];
  local_38 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_48;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400019a0 =====

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
LAB_140001a53:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140001a81;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140001a53;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140001a81:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140001c0c =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
               (uint param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = (uint *)*param_3;
  if (param_2 == 3) {
    uVar4 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar4 = 0x20;
  }
  if ((*(char *)((longlong)param_3 + 0x1e) == '\0') && (*(char *)((longlong)param_3 + 0x1d) == '\0')
     ) {
    uVar3 = *puVar2;
    if ((uVar3 & 2) != 0) {
      while ((uVar3 & 1) == (param_1 & 1)) {
        LOCK();
        uVar1 = *puVar2;
        bVar5 = uVar3 == uVar1;
        if (bVar5) {
          *puVar2 = uVar4 | uVar3;
        }
        else {
          uVar3 = uVar1;
        }
        UNLOCK();
        if (bVar5) {
          return;
        }
        if ((uVar3 & 2) == 0) {
          return;
        }
      }
    }
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== wil_details_IsEnabledFallback @ 140001c70 =====

uint wil_details_IsEnabledFallback(ulonglong param_1,int param_2,undefined8 *param_3)

{
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffff;
  if ((param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           ((uint *)*param_3,param_1,(longlong)param_3);
    param_1 = local_res8 & 0xffffffff;
  }
  if ((param_2 != 0) &&
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== wil_details_RecordCachedUsage @ 140001d04 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001e60 =====

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



===== SmCheckProcessOrigin @ 140001ee4 =====

longlong SmCheckProcessOrigin(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  
  lVar4 = 0;
  if (DAT_1400061c8 != (longlong *)0x0) {
    LOCK();
    lVar1 = *DAT_1400061c8;
    if (lVar1 == 0) {
      *DAT_1400061c8 = 0;
    }
    UNLOCK();
    if (lVar1 != 0) {
      FltAcquireResourceShared(DAT_140006178);
      if ((DAT_1400061c8 != (longlong *)0x0) &&
         (plVar2 = (longlong *)*DAT_1400061c8, plVar2 != (longlong *)0x0)) {
        plVar3 = (longlong *)plVar2[2];
        do {
          if (param_1 == plVar3[2]) {
            lVar4 = *plVar2;
            LOCK();
            *(int *)(lVar4 + 0x18) = *(int *)(lVar4 + 0x18) + 1;
            UNLOCK();
            break;
          }
          plVar3 = (longlong *)*plVar3;
        } while (plVar3 != plVar2 + 2);
      }
      FltReleaseResource(DAT_140006178);
    }
  }
  return lVar4;
}



===== SmCheckProcessSessionOrigin @ 140001f78 =====

undefined8 SmCheckProcessSessionOrigin(longlong param_1,undefined4 *param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  void *_Dst;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  uVar4 = 0;
  if (DAT_1400061b8 != (longlong *)0x0) {
    LOCK();
    lVar1 = *DAT_1400061b8;
    if (lVar1 == 0) {
      *DAT_1400061b8 = 0;
    }
    UNLOCK();
    if (lVar1 != 0) {
      FltAcquireResourceShared(DAT_140006178);
      if ((DAT_1400061b8 != (longlong *)0x0) && (*DAT_1400061b8 != 0)) {
        puVar3 = (undefined8 *)(*DAT_1400061b8 + 0x10);
        puVar5 = (undefined8 *)*puVar3;
        do {
          if (param_1 == puVar5[2]) {
            uVar2 = *(undefined4 *)(puVar5 + 4);
            _Dst = (void *)ExAllocatePool2(0x102,uVar2,0x53746d73);
            if (_Dst == (void *)0x0) {
              uVar4 = 0xc0000017;
            }
            else {
              memmove(_Dst,(void *)puVar5[3],(ulonglong)*(uint *)(puVar5 + 4));
              *param_3 = _Dst;
              *param_2 = uVar2;
            }
            break;
          }
          puVar5 = (undefined8 *)*puVar5;
        } while (puVar5 != puVar3);
      }
      FltReleaseResource(DAT_140006178);
    }
  }
  return uVar4;
}



===== _guard_check_icall @ 140002080 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002098 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400020bc =====

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



===== __cpu_features_init @ 140002130 =====

/* WARNING: Removing unreachable block (ram,0x00014000219a) */
/* WARNING: Removing unreachable block (ram,0x000140002149) */
/* WARNING: Removing unreachable block (ram,0x00014000213a) */

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



===== __security_check_cookie @ 140002200 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002240 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002270 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400022a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002300 =====

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



===== memset @ 140002600 =====

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



===== __memset_repmovs @ 140002740 =====

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



===== __memset_query @ 1400027c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002840 =====

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



===== __memset_spec_ermsb_repmovsb @ 140002980 =====

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



===== __memset_spec_plain @ 140002a00 =====

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



===== SmInstanceSetup @ 140009010 =====

undefined8 SmInstanceSetup(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_3 == 0x14) {
    uVar1 = 0xc01c000f;
  }
  return uVar1;
}



===== SmPostCreate @ 140009030 =====

undefined8 SmPostCreate(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  char cVar6;
  longlong lVar7;
  void *pvVar8;
  undefined4 uVar9;
  undefined8 *local_res8;
  uint local_58 [2];
  void *local_50;
  longlong local_48;
  undefined8 local_40;
  longlong local_38 [2];
  
  local_40 = 0;
  local_res8 = (undefined8 *)((ulonglong)local_res8 & 0xffffffffffffff00);
  if (*(int *)(param_1 + 0x18) < 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x18) == 0x104) {
    return 0;
  }
  if (((*(ulonglong *)(param_1 + 0x20) & 0xfffffffffffffffc) != 0) ||
     (uVar9 = 1, *(ulonglong *)(param_1 + 0x20) == 1)) {
    if ((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18) + 0x10) & 0x40000006) == 0) {
      return 0;
    }
    uVar9 = 0;
  }
  iVar1 = FltGetFileNameInformation(param_1,0x101,&local_40);
  if (iVar1 < 0) {
    return 0;
  }
  FltParseFileNameInformation(local_40);
  lVar7 = 0;
  local_48 = 0;
  lVar4 = 0;
  lVar2 = IoThreadToProcess(*(undefined8 *)(param_1 + 8));
  local_50 = (void *)0x0;
  local_58[0] = 0;
  local_38[0] = 0;
  uVar3 = Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    uVar5 = SmCheckProcessSessionOrigin(lVar2,local_58,&local_50);
    pvVar8 = local_50;
    if (((int)uVar5 < 0) || (local_50 == (void *)0x0)) {
      iVar1 = SmCheckOrigin(lVar2,(undefined1 *)&local_res8,&local_48);
      cVar6 = (char)local_res8;
      if ((iVar1 < 0) || ((char)local_res8 == '\0')) {
        lVar4 = SmCheckProcessOrigin(lVar2);
        goto LAB_140009171;
      }
      goto LAB_140009188;
    }
  }
  else {
    lVar4 = SmCheckProcessOrigin(lVar2);
    SmCheckProcessSessionOrigin(lVar2,local_58,&local_50);
    SmCheckOrigin(lVar2,(undefined1 *)&local_res8,&local_48);
    pvVar8 = local_50;
    cVar6 = (char)local_res8;
LAB_140009171:
    if (((cVar6 == '\0') && (lVar4 == 0)) && (pvVar8 == (void *)0x0)) {
      lVar7 = local_48;
      goto LAB_140009244;
    }
LAB_140009188:
    lVar7 = local_48;
  }
  iVar1 = SmpSetEaFromOrigin(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),lVar7,
                             lVar4,pvVar8,local_58[0],local_38);
  if (-1 < iVar1) {
    local_res8 = (undefined8 *)0x0;
    iVar1 = FltAllocateContext(*(undefined8 *)(param_2 + 8),0x10,8,0x200,&local_res8);
    if (-1 < iVar1) {
      *local_res8 = 0;
      *(undefined4 *)local_res8 = uVar9;
      *(undefined4 *)((longlong)local_res8 + 4) = *(undefined4 *)(local_38[0] + 8);
      FltSetStreamHandleContext
                (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),0,local_res8,0);
      FltReleaseContext(local_res8);
    }
  }
  SmReleaseOriginProcessData();
LAB_140009244:
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0x41746d73);
  }
  if (pvVar8 != (void *)0x0) {
    ExFreePoolWithTag(pvVar8,0x53746d73);
  }
  FltReleaseFileNameInformation(local_40);
  return 0;
}



===== SmPreCleanup @ 1400092b0 =====

undefined8 SmPreCleanup(undefined8 param_1,longlong param_2)

{
  int iVar1;
  int *local_res20;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined **local_18;
  int local_10;
  undefined4 local_c;
  
  local_res20 = (int *)0x0;
  iVar1 = FltGetStreamHandleContext
                    (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),&local_res20);
  if (-1 < iVar1) {
    LOCK();
    iVar1 = *local_res20;
    if (iVar1 == 0) {
      *local_res20 = 0;
    }
    UNLOCK();
    if (iVar1 != 0) {
      local_28 = *(undefined8 *)(param_2 + 0x18);
      local_20 = *(undefined8 *)(param_2 + 0x20);
      local_18 = &PTR_SmpQueryFile_140006000;
      local_38 = 0;
      uStack_30 = 0;
      local_10 = local_res20[1];
      local_c = 0;
      ZwDeviceIoControlFile(DAT_140006190,0,0,0,&local_38,0x22a018,&local_28,0x20,0,0);
    }
    FltReleaseContext(local_res20);
  }
  return 1;
}



===== SmPreCreate @ 1400093b0 =====

undefined8 SmPreCreate(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  longlong local_res8 [3];
  undefined8 local_res20;
  
  if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) & 1) == 0) {
    uVar3 = *(undefined8 *)(param_2 + 8);
    local_res8[0] = 0;
    local_res20 = 0;
    iVar2 = FltGetEcpListFromCallbackData(uVar3,param_1,local_res8);
    if ((-1 < iVar2) && (local_res8[0] != 0)) {
      iVar2 = FltFindExtraCreateParameter
                        (uVar3,local_res8[0],&GUID_ECP_PREFETCH_OPEN,&local_res20,0);
      if (-1 < iVar2) {
        cVar1 = FltIsEcpFromUserMode(uVar3,local_res20);
        if (cVar1 == '\0') goto LAB_14000943a;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_14000943a:
    uVar3 = 1;
  }
  return uVar3;
}



===== SmpRegistryCallback @ 140009450 =====

ulonglong SmpRegistryCallback(undefined8 param_1,int param_2,undefined8 *param_3)

{
  short sVar1;
  undefined8 uVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  ushort uVar10;
  undefined *puVar11;
  longlong lVar12;
  char local_res10 [16];
  undefined4 local_res20 [2];
  ushort *local_78;
  longlong local_70;
  longlong local_68;
  longlong local_60 [2];
  undefined8 local_50;
  longlong lStack_48;
  
  local_78 = (ushort *)0x0;
  local_60[0] = 0;
  lVar12 = 0;
  local_70 = 0;
  lVar9 = 0;
  local_68 = 0;
  local_res20[0] = 0;
  local_res10[0] = '\0';
  local_50 = 0;
  lStack_48 = 0;
  if (param_2 != 1) {
    return 0;
  }
  uVar2 = *param_3;
  if (((*(int *)((longlong)param_3 + 0x14) - 1U < 2) &&
      (cVar4 = RtlEqualUnicodeString(param_3[1],&DAT_140004130,1), cVar4 != '\0')) &&
     ((uVar6 = Feature_Servicing_ApplockerFilterOOBR__private_IsEnabledDeviceUsageNoInline(),
      (int)uVar6 == 0 || (*(uint *)(param_3 + 4) < 0x10000)))) {
    lStack_48 = param_3[3];
    local_50 = CONCAT62(CONCAT42(local_50._4_4_,*(undefined2 *)(param_3 + 4)),
                        *(undefined2 *)(param_3 + 4));
    uVar6 = Feature_Servicing_ApplockerFilterOOBR__private_IsEnabledDeviceUsageNoInline();
    uVar10 = (ushort)local_50;
    if ((int)uVar6 == 0) {
      if (3 < (ushort)local_50) {
        sVar1 = *(short *)(lStack_48 + -2 + (ulonglong)((ushort)local_50 >> 1) * 2);
        while (sVar1 == 0) {
          uVar10 = uVar10 - 2;
          local_50._2_6_ = (undefined6)(local_50 >> 0x10);
          local_50 = CONCAT62(local_50._2_6_,uVar10);
          sVar1 = *(short *)(lStack_48 + -2 + (ulonglong)(uVar10 >> 1) * 2);
        }
LAB_14000957f:
        if (3 < uVar10) {
          uVar5 = CmCallbackGetKeyObjectID(&DAT_140006118,uVar2,0,&local_78);
          uVar6 = (ulonglong)uVar5;
          if ((int)uVar5 < 0) goto LAB_140009648;
          uVar6 = Feature_Servicing_ApplockerFilterOOBR__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar6 == 0) {
            cVar4 = RtlPrefixUnicodeString();
            if (((cVar4 == '\0') &&
                (cVar4 = RtlPrefixUnicodeString(&DAT_1400041e8,local_78,1), cVar4 == '\0')) &&
               (cVar4 = RtlPrefixUnicodeString(&DAT_140004140,local_78,1), cVar4 == '\0')) {
              cVar4 = RtlPrefixUnicodeString(&DAT_140004150,local_78,1);
LAB_14000963d:
              if (cVar4 == '\0') goto LAB_140009645;
            }
          }
          else {
            cVar4 = RtlPrefixUnicodeString(&DAT_140004208,local_78,1);
            if ((cVar4 == '\0') &&
               (cVar4 = RtlPrefixUnicodeString(&DAT_1400041e8,local_78,1), cVar4 == '\0')) {
              puVar11 = &DAT_1400041f8;
              cVar4 = RtlPrefixUnicodeString(&DAT_1400041f8,local_78,1);
              if (cVar4 == '\0') goto LAB_140009645;
              uVar6 = SmpFindSubStr(puVar11,local_78,(ushort *)&DAT_140004110);
              if ((char)uVar6 == '\0') {
                uVar6 = SmpFindSubStr(puVar11,local_78,(ushort *)&DAT_140004198);
                cVar4 = (char)uVar6;
                goto LAB_14000963d;
              }
            }
          }
          lVar7 = IoGetCurrentProcess();
          uVar8 = SmCheckProcessSessionOrigin(lVar7,local_res20,&local_68);
          lVar3 = local_68;
          uVar6 = uVar8 & 0xffffffff;
          if (((int)uVar8 < 0) || (local_68 == 0)) {
            uVar5 = SmCheckOrigin(lVar7,local_res10,local_60);
            lVar12 = local_60[0];
            cVar4 = local_res10[0];
            uVar6 = (ulonglong)uVar5;
            if ((((-1 < (int)uVar5) && (local_res10[0] != '\0')) ||
                (lVar9 = SmCheckProcessOrigin(lVar7), cVar4 != '\0')) && (lVar12 != 0)) {
LAB_140009768:
              lVar9 = **(longlong **)(*(longlong *)(lVar12 + 8) + 0x20);
              goto LAB_140009788;
            }
            if ((lVar9 != 0) || (lVar3 != 0)) {
              if (lVar12 == 0) {
                if (lVar9 == 0) {
                  lVar9 = 0;
                  if (lVar3 != 0) goto LAB_140009785;
                }
                else {
                  lVar9 = *(longlong *)(lVar9 + 0x20);
                }
                goto LAB_140009788;
              }
              goto LAB_140009768;
            }
          }
          else {
LAB_140009785:
            lVar9 = lVar3;
LAB_140009788:
            if (((*(uint *)(lVar9 + 8) & 0xfffffffc) == 0) && (*(uint *)(lVar9 + 8) != 2)) {
              uVar5 = SeLocateProcessImageName(lVar7,&local_70);
              uVar6 = (ulonglong)uVar5;
              SmRegisterUninstallStringWithSessionOrigin(lVar9);
            }
            SmReleaseOriginProcessData();
          }
          if (lVar12 != 0) {
            ExFreePoolWithTag(lVar12,0x41746d73);
          }
          if (lVar3 != 0) {
            ExFreePoolWithTag(lVar3,0x53746d73);
          }
          goto LAB_140009648;
        }
      }
    }
    else if (((local_50 & 1) == 0) && (3 < (ushort)local_50)) {
      while ((uVar10 != 0 &&
             (*(short *)(lStack_48 + -2 + ((ulonglong)uVar10 & 0xfffffffffffffffe)) == 0))) {
        local_50._2_6_ = (undefined6)(local_50 >> 0x10);
        local_50 = CONCAT62(local_50._2_6_,uVar10 - 2);
        uVar10 = uVar10 - 2;
      }
      goto LAB_14000957f;
    }
  }
LAB_140009645:
  uVar6 = 0;
LAB_140009648:
  if (local_70 != 0) {
    ExFreePoolWithTag(local_70,0);
  }
  return uVar6;
}



===== SmpSetEaFromOrigin @ 140009814 =====

int SmpSetEaFromOrigin(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,
                      void *param_5,uint param_6,undefined8 *param_7)

{
  undefined8 *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  void *pvVar8;
  longlong local_38 [2];
  
  uVar6 = 0;
  pvVar7 = (void *)0x0;
  uVar5 = 0;
  pvVar8 = (void *)0x0;
  uVar3 = Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    if (param_3 == 0) {
      if (param_4 == 0) {
        if (param_5 == (void *)0x0) {
          return 0;
        }
      }
      else {
        param_5 = *(void **)(param_4 + 0x20);
        param_6 = *(uint *)(param_4 + 0x28);
      }
    }
    else {
      puVar1 = *(undefined8 **)(*(longlong *)(param_3 + 8) + 0x20);
      param_6 = *(uint *)(puVar1 + 1);
      param_5 = (void *)*puVar1;
    }
    goto LAB_14000991c;
  }
  if (param_3 != 0) {
    puVar1 = *(undefined8 **)(*(longlong *)(param_3 + 8) + 0x20);
    uVar5 = *(uint *)(puVar1 + 1);
    pvVar8 = (void *)*puVar1;
  }
  if (param_4 != 0) {
    pvVar7 = *(void **)(param_4 + 0x20);
    uVar6 = *(uint *)(param_4 + 0x28);
  }
  if ((param_5 != (void *)0x0) &&
     ((*(uint *)((longlong)param_5 + 8) < 2 || (*(uint *)((longlong)param_5 + 8) - 3 < 2))))
  goto LAB_14000991c;
  if ((pvVar8 == (void *)0x0) ||
     ((1 < *(uint *)((longlong)pvVar8 + 8) && (1 < *(uint *)((longlong)pvVar8 + 8) - 3)))) {
    if ((pvVar7 == (void *)0x0) ||
       ((1 < *(uint *)((longlong)pvVar7 + 8) && (1 < *(uint *)((longlong)pvVar7 + 8) - 3)))) {
      if (param_5 != (void *)0x0) goto LAB_14000991c;
      if (param_3 != 0) goto LAB_1400098cb;
      if (param_4 == 0) {
        return 0;
      }
    }
    param_5 = pvVar7;
    param_6 = uVar6;
  }
  else {
LAB_1400098cb:
    param_5 = pvVar8;
    param_6 = uVar5;
  }
LAB_14000991c:
  puVar4 = (undefined4 *)ExAllocatePool2(0x102,param_6 + 0x28,0x45746d73);
  if (puVar4 == (undefined4 *)0x0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    *puVar4 = 0;
    *(undefined2 *)(puVar4 + 1) = 0x1f00;
    *(short *)((longlong)puVar4 + 6) = (short)param_6;
    builtin_strncpy((char *)(puVar4 + 2),"$Kernel.",8);
    builtin_strncpy((char *)(puVar4 + 4),"Smartloc",8);
    builtin_strncpy((char *)(puVar4 + 6),"ker.Orig",8);
    builtin_strncpy((char *)(puVar4 + 8),"inClaim",8);
    memmove(puVar4 + 10,param_5,(ulonglong)param_6);
    local_38[0] = 0;
    iVar2 = FltAllocateCallbackData(param_1,param_2,local_38);
    if (-1 < iVar2) {
      *(undefined1 *)(*(longlong *)(local_38[0] + 0x10) + 4) = 8;
      *(undefined1 *)(*(longlong *)(local_38[0] + 0x10) + 5) = 4;
      *(uint *)(*(longlong *)(local_38[0] + 0x10) + 0x18) = param_6 + 0x28;
      *(undefined4 **)(*(longlong *)(local_38[0] + 0x10) + 0x20) = puVar4;
      *(undefined8 *)(*(longlong *)(local_38[0] + 0x10) + 0x28) = 0;
      FltPerformSynchronousIo(local_38[0]);
      iVar2 = *(int *)(local_38[0] + 0x18);
      FltFreeCallbackData();
    }
    ExFreePoolWithTag(puVar4,0x45746d73);
    if (-1 < iVar2) {
      *param_7 = param_5;
    }
  }
  return iVar2;
}



===== _tlgEnableCallback @ 140009a60 =====

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



===== wil_details_EvaluateFeatureDependencies @ 140009adc =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140009b17;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140009b91:
  while( true ) {
    if (&UNK_140005437 < ppuVar3) {
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
      if (&UNK_140005437 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140009b17:
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
      if (&UNK_140005437 < ppuVar2) goto LAB_140009b91;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140009b91;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140009bcc =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140009c64;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140009c64;
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
LAB_140009c64:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140009cb0 =====

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
              if (&UNK_140005437 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140009d30 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_140009e2d;
  }
LAB_140009e36:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_140009e2d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140009e36;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_140009dfe:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_140009dfe;
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
    if (&UNK_140005437 < ppuVar3) goto LAB_140009e36;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_140009e2d;
}



===== SmCheckOrigin @ 140009e5c =====

int SmCheckOrigin(undefined8 param_1,undefined1 *param_2,longlong *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  uint local_res10 [2];
  
  *param_2 = 0;
  *param_3 = 0;
  uVar4 = PsReferencePrimaryToken();
  local_res10[0] = 0;
  uVar6 = 0x24d;
  do {
    lVar5 = ExAllocatePool2(0x102,uVar6,0x41746d73);
    if (lVar5 == 0) {
      iVar3 = -0x3fffffe9;
LAB_140009f49:
      PsDereferencePrimaryToken(uVar4);
      return iVar3;
    }
    iVar3 = SeQuerySecurityAttributesToken(uVar4,&DAT_140004230,1,lVar5,uVar6,local_res10);
    uVar1 = local_res10[0];
    if (iVar3 != -0x3fffffdd) {
      if (iVar3 < 0) goto LAB_140009f24;
      iVar2 = iVar3;
      if (*(int *)(lVar5 + 4) == 0) {
LAB_140009f2e:
        iVar3 = iVar2;
        ExFreePoolWithTag(lVar5,0x41746d73);
      }
      else {
        *param_2 = 1;
        *param_3 = lVar5;
      }
      goto LAB_140009f49;
    }
    if (local_res10[0] <= uVar6) {
LAB_140009f24:
      iVar2 = 0;
      if (iVar3 != -0x3ffffddb) {
        iVar2 = iVar3;
      }
      goto LAB_140009f2e;
    }
    ExFreePoolWithTag(lVar5,0x41746d73);
    uVar6 = uVar1;
  } while( true );
}



===== SmRegisterUninstallStringWithSessionOrigin @ 140009f78 =====

undefined8 SmRegisterUninstallStringWithSessionOrigin(longlong param_1)

{
  code *pcVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar6 = 0;
  lVar2 = SmGetTrackSessionOriginData();
  if (lVar2 != 0) {
    SmAcquireTrackLockExclusive();
    plVar3 = (longlong *)SmGetTrackSessionOriginDataLocked();
    puVar7 = auStack_28;
    if (plVar3 != (longlong *)0x0) {
      plVar8 = (longlong *)*plVar3;
      if ((*(longlong *)(param_1 + 0x20) != *(longlong *)(plVar8[4] + 0x20)) ||
         (*(longlong *)(param_1 + 0x28) != *(longlong *)(plVar8[4] + 0x28))) {
        do {
          plVar8 = (longlong *)*plVar8;
          puVar7 = auStack_28;
          if (plVar8 == plVar3) goto LAB_14000a030;
        } while ((*(longlong *)(param_1 + 0x20) != *(longlong *)(plVar8[4] + 0x20)) ||
                (*(longlong *)(param_1 + 0x28) != *(longlong *)(plVar8[4] + 0x28)));
      }
      puVar4 = (undefined8 *)SmAllocUninstallStringData();
      puVar7 = auStack_28;
      if (puVar4 == (undefined8 *)0x0) {
        uVar6 = 0xc0000017;
        puVar7 = auStack_28;
      }
      else {
        plVar3 = plVar8 + 6;
        puVar5 = (undefined8 *)plVar8[7];
        if ((longlong *)*puVar5 != plVar3) {
          plVar3 = (longlong *)0x3;
          pcVar1 = (code *)swi(0x29);
          puVar4 = (undefined8 *)(*pcVar1)();
          puVar7 = auStack_20;
        }
        *puVar4 = plVar3;
        puVar4[1] = puVar5;
        *puVar5 = puVar4;
        plVar3[1] = (longlong)puVar4;
      }
    }
LAB_14000a030:
    *(undefined8 *)(puVar7 + -8) = 0x14000a035;
    SmReleaseTrackLock();
  }
  return uVar6;
}



===== entry @ 14000b010 =====

void entry(undefined8 param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000b044 =====

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



===== DriverEntry @ 14000b078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1)

{
  undefined2 uVar1;
  code *pcVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 auStack_248 [8];
  undefined1 auStack_240 [24];
  undefined4 local_228;
  undefined4 *local_220;
  undefined4 local_1e8 [2];
  longlong local_1e0 [3];
  undefined8 *puStack_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  wchar_t *local_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined4 local_188;
  undefined4 local_184;
  undefined8 local_180;
  undefined *local_178;
  undefined4 local_170;
  undefined4 local_16c;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  wchar_t *pwStack_150;
  undefined4 local_148;
  undefined1 local_144 [284];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_248;
  local_1a8 = 0xa600a4;
  local_184 = 0;
  local_16c = 0;
  local_1a0 = 
  L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\Control\\AppID\\Configuration\\SMARTLOCKER";
  local_158 = 0x120010;
  pwStack_150 = L"DISABLED";
  puStack_1c8 = &local_1a8;
  bVar3 = false;
  bVar8 = false;
  local_1e0[0] = 0;
  local_198 = 0;
  uStack_190 = 0;
  lVar6 = 0;
  local_1e8[0] = 0x30;
  local_1e0[1] = 0x30;
  local_1c0 = 0x240;
  local_1e0[2] = 0;
  local_1b8 = 0;
  uStack_1b0 = 0;
  iVar5 = ZwOpenKey(local_1e0,0x20019,local_1e0 + 1);
  puVar7 = auStack_248;
  if (-1 < iVar5) {
    do {
      uVar4 = local_1e8[0];
      if (lVar6 != 0) {
        ExFreePoolWithTag(lVar6,0x52746d73);
      }
      lVar6 = ExAllocatePool2(0x102,uVar4,0x52746d73);
      if (lVar6 == 0) goto LAB_14000b1f4;
      local_220 = local_1e8;
      local_228 = uVar4;
      iVar5 = ZwQueryValueKey(local_1e0[0],&local_158,2,lVar6);
    } while (iVar5 == -0x7ffffffb);
    bVar8 = bVar3;
    if (((-1 < iVar5) && (*(int *)(lVar6 + 4) == 0xb)) && (*(int *)(lVar6 + 8) == 8)) {
      bVar8 = *(longlong *)(lVar6 + 0xc) != 0;
    }
    ExFreePoolWithTag(lVar6);
  }
LAB_14000b1f4:
  if (local_1e0[0] != 0) {
    ZwClose();
  }
  if (bVar8) {
    iVar5 = -0x3fffffff;
  }
  else {
    memset(local_144,0,0x110);
    local_148 = 0x114;
    RtlGetVersion(&local_148);
    local_158 = *(undefined8 *)(PTR_DAT_140006018 + -0x10);
    pwStack_150 = *(wchar_t **)(PTR_DAT_140006018 + -8);
    puVar7 = auStack_248;
    if (DAT_140006030 != 0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(5);
      puVar7 = auStack_240;
    }
    _DAT_140006038 = 0;
    uRam0000000140006040 = 0;
    *(undefined8 *)(puVar7 + -8) = 0x14000b28c;
    iVar5 = EtwRegister(&local_158,_tlgEnableCallback,&DAT_140006010,&DAT_140006030);
    if (iVar5 == 0) {
      uVar1 = *(undefined2 *)PTR_DAT_140006018;
      *(undefined8 *)(puVar7 + -8) = 0x14000b2b1;
      EtwSetInformation(DAT_140006030,2,PTR_DAT_140006018,uVar1);
    }
    *(undefined8 *)(puVar7 + -8) = 0x14000b2bb;
    wil_InitializeFeatureStaging();
    *(undefined8 *)(puVar7 + -8) = 0x14000b2d5;
    EtwRegister(&SrpEventProviderId,0,0,&g_EtwEventHandle);
    *(undefined4 *)(puVar7 + 0x50) = 0;
    *(undefined8 *)(puVar7 + 0x48) = 0;
    *(undefined4 *)(puVar7 + 0x40) = 0;
    *(undefined4 *)(puVar7 + 0x38) = 1;
    *(undefined4 *)(puVar7 + 0x30) = 3;
    *(undefined4 *)(puVar7 + 0x28) = 0;
    *(undefined8 *)(puVar7 + 0x20) = 0;
    local_188 = 0x30;
    local_180 = 0;
    local_170 = 0x240;
    local_178 = &DAT_1400041c0;
    local_168 = 0;
    uStack_160 = 0;
    *(undefined8 *)(puVar7 + -8) = 0x14000b33f;
    iVar5 = ZwCreateFile(&DAT_140006190,0x40000000,&local_188,&local_198);
    if (-1 < iVar5) {
      *(undefined4 *)(puVar7 + 0x48) = 0x30;
      *(undefined1 **)(puVar7 + 0x40) = puVar7 + 0x70;
      *(undefined4 *)(puVar7 + 0x38) = 0;
      *(undefined8 *)(puVar7 + 0x30) = 0;
      *(undefined4 *)(puVar7 + 0x28) = 0x22a014;
      *(undefined8 **)(puVar7 + 0x20) = &local_198;
      *(undefined8 *)(puVar7 + 0x70) = 0;
      *(undefined8 *)(puVar7 + 0x78) = 0;
      puStack_1c8 = (undefined8 *)0x0;
      local_1c0 = 0;
      local_1b8 = 0;
      uStack_1b0 = 0;
      *(undefined8 *)(puVar7 + -8) = 0x14000b3a1;
      iVar5 = ZwDeviceIoControlFile(DAT_140006190,0,0,0);
      if (-1 < iVar5) {
        DAT_140006178 = *(undefined8 *)(puVar7 + 0x70);
        DAT_1400061c8 = *(undefined8 *)(puVar7 + 0x78);
        DAT_1400061b8 = puStack_1c8;
        DAT_140006128 = local_1c0;
        DAT_140006160 = local_1b8;
        DAT_140006130 = uStack_1b0;
        *(undefined8 *)(puVar7 + -8) = 0x14000b40c;
        iVar5 = FltRegisterFilter(param_1,&FilterRegistration,&DAT_140006188);
        if (-1 < iVar5) {
          *(undefined8 *)(puVar7 + -8) = 0x14000b425;
          iVar5 = FltStartFiltering(DAT_140006188);
          if (-1 < iVar5) {
            *(undefined8 *)(puVar7 + -8) = 0x14000b447;
            iVar5 = CmRegisterCallback(SmpRegistryCallback,0,&DAT_140006118);
            if (-1 < iVar5) goto LAB_14000b50a;
          }
          *(undefined8 *)(puVar7 + -8) = 0x14000b464;
          FltUnregisterFilter(DAT_140006188);
        }
      }
    }
    *(undefined8 *)(puVar7 + -8) = 0x14000b477;
    ZwClose(DAT_140006190);
    DAT_140006190 = 0;
    if (g_wil_details_featureChangeNotification != 0) {
      *(undefined8 *)(puVar7 + -8) = 0x14000b496;
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      *(undefined8 *)(puVar7 + -8) = 0x14000b4b5;
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    lVar6 = DAT_140006030;
    DAT_140006030 = 0;
    g_wil_details_isFeatureStagingInitialized = 0;
    _DAT_140006010 = 0;
    *(undefined8 *)(puVar7 + -8) = 0x14000b4e4;
    EtwUnregister(lVar6);
    if (g_EtwEventHandle != 0) {
      *(undefined8 *)(puVar7 + -8) = 0x14000b4fc;
      EtwUnregister();
      g_EtwEventHandle = 0;
    }
  }
LAB_14000b50a:
  *(undefined8 *)(puVar7 + -8) = 0x14000b519;
  return iVar5;
}



===== wil_InitializeFeatureStaging @ 14000b540 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14000b5c7;
    }
LAB_14000b601:
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
LAB_14000b5c7:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000b601;
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
    goto LAB_14000b601;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140005437 < ppuVar3) goto LAB_14000b601;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000b5c7;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000b654 =====

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
            if (&UNK_140005437 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14000b73e;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14000b73e;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14000b73e:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140005437 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


