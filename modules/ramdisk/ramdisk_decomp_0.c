
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



===== Feature_AllowLargerRamdiskSize__private_IsEnabledDeviceUsageNoInline @ 140001020 =====

ulonglong Feature_AllowLargerRamdiskSize__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_AllowLargerRamdiskSize__private_featureState;
  if ((Feature_AllowLargerRamdiskSize__private_featureState & 0x10) == 0) {
    uVar1 = Feature_AllowLargerRamdiskSize__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_AllowLargerRamdiskSize__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_AllowLargerRamdiskSize__private_IsEnabledFallback @ 140001058 =====

void Feature_AllowLargerRamdiskSize__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== RtlStringCbCatW @ 140001070 =====

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



===== RtlStringCbCopyW @ 140001138 =====

uint RtlStringCbCopyW(short *param_1,ulonglong param_2,longlong param_3)

{
  short sVar1;
  short *psVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  
  uVar3 = param_2 >> 1;
  if (0x7ffffffe < uVar3 - 1) {
    if (uVar3 != 0) {
      *param_1 = 0;
    }
    return 0xc000000d;
  }
  lVar4 = 0x7ffffffe - uVar3;
  lVar5 = param_3 - (longlong)param_1;
  do {
    if ((lVar4 + uVar3 == 0) || (sVar1 = *(short *)(lVar5 + (longlong)param_1), sVar1 == 0)) break;
    *param_1 = sVar1;
    param_1 = param_1 + 1;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  psVar2 = param_1 + -1;
  if (uVar3 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  return ~-(uint)(uVar3 != 0) & 0x80000005;
}



===== RtlStringCbPrintfW @ 1400011ac =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001228 =====

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
LAB_140001431:
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
LAB_140001303:
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
      if (param_3 == 4) goto LAB_140001431;
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
        goto LAB_140001303;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000151c =====

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
      goto LAB_1400015df;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_1400015df;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_1400015df;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_1400015df;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_1400015df;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_1400015df;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_1400015df;
    }
  }
  uVar2 = 0xff;
LAB_1400015df:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x387bd24,&Feature_AllowLargerRamdiskSize_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140001638 =====

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
                     (local_50,&Feature_AllowLargerRamdiskSize__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x387bd24,param_3,1,&Feature_AllowLargerRamdiskSize__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x387bd24);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140001724 =====

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
LAB_1400017d7:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140001805;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_1400017d7;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140001805:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140001990 =====

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
  if ((Feature_AllowLargerRamdiskSize__private_featureState & 2) != 0) {
    uVar1 = Feature_AllowLargerRamdiskSize__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_AllowLargerRamdiskSize__private_featureState;
      if (bVar3) {
        Feature_AllowLargerRamdiskSize__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_AllowLargerRamdiskSize__private_featureState;
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



===== wil_details_IsEnabledFallback @ 1400019e4 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_AllowLargerRamdiskSize__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_AllowLargerRamdiskSize__private_featureState,
                             (ulonglong)param_1,0x140005d18);
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



===== RamdiskIoCompletionRoutine @ 140001a80 =====

undefined8 RamdiskIoCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== RamdiskGetRegistryString @ 140001aac =====

int RamdiskGetRegistryString(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  local_res20[0] = 0;
  iVar1 = RtlInitUnicodeStringEx(&local_28);
  if (iVar1 < 0) {
    return iVar1;
  }
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (*(short *)(param_2 + lVar2 * 2) != 0);
  iVar1 = ((int)lVar2 * 2 + 0x1fU & 0xfffffff8) + 4;
  lVar2 = ExAllocatePool2(0x100,iVar1,0x646d6152);
  if (lVar2 == 0) {
LAB_140001b31:
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = ZwQueryValueKey(param_1,&local_28,1,lVar2,iVar1,local_res20);
    if (iVar1 < 0) {
      ExFreePoolWithTag(lVar2,0x646d6152);
      if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
        return iVar1;
      }
      lVar2 = ExAllocatePool2(0x100,local_res20[0],0x646d6152);
      if (lVar2 == 0) goto LAB_140001b31;
      iVar1 = ZwQueryValueKey(param_1,&local_28,1,lVar2,local_res20[0],local_res20);
      if (iVar1 < 0) {
        ExFreePoolWithTag(lVar2,0x646d6152);
        return iVar1;
      }
    }
    if (((*(int *)(lVar2 + 4) == 1) && (*(uint *)(lVar2 + 0xc) != 0)) &&
       (*(short *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2 +
                  (ulonglong)((*(uint *)(lVar2 + 0xc) >> 1) - 1) * 2) == 0)) {
      *param_3 = lVar2;
      return 0;
    }
    ExFreePoolWithTag(lVar2,0x646d6152,0);
    iVar1 = -0x3fffffff;
  }
  return iVar1;
}



===== RamdiskQuerySystemStartOptions @ 140001c64 =====

int RamdiskQuerySystemStartOptions(void)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  wchar_t *_Str;
  longlong local_res8;
  undefined8 local_res10;
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
  
  local_res8 = 0;
  local_res10 = 0;
  local_44 = 0;
  local_2c = 0;
  local_58 = 0;
  uStack_50 = 0;
  RtlInitUnicodeString(&local_58,L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control");
  local_38 = &local_58;
  local_48 = 0x30;
  local_40 = 0;
  local_30 = 0x240;
  local_28 = 0;
  uStack_20 = 0;
  iVar2 = ZwOpenKey(&local_res10,0x20019,&local_48);
  if (-1 < iVar2) {
    iVar2 = RamdiskGetRegistryString(local_res10,0x140005498,&local_res8);
    lVar1 = local_res8;
    if (-1 < iVar2) {
      pwVar5 = (wchar_t *)((ulonglong)*(uint *)(local_res8 + 8) + local_res8);
      uVar4 = 0xffffffffffffffff;
      do {
        uVar4 = uVar4 + 1;
      } while (pwVar5[uVar4] != L'\0');
      if (9 < uVar4) {
        iVar2 = _wcsnicmp(pwVar5,L"ramdisk(",8);
        if (iVar2 == 0) {
          ReportDetectedDevice = 1;
        }
      }
      ExFreePoolWithTag(lVar1,0x646d6152);
    }
    iVar2 = RamdiskGetRegistryString(local_res10,0x1400054d8,&local_res8);
    lVar1 = local_res8;
    if (-1 < iVar2) {
      _Str = (wchar_t *)((ulonglong)*(uint *)(local_res8 + 8) + local_res8);
      _wcsupr(_Str);
      pwVar5 = wcsstr(_Str,L"RDEXPORTASCD");
      if (pwVar5 != (wchar_t *)0x0) {
        ExportBootDiskAsCd = 1;
      }
      pwVar5 = wcsstr(_Str,L"MININT");
      if (pwVar5 != (wchar_t *)0x0) {
        IsWinPEBoot = 1;
      }
      ExFreePoolWithTag(lVar1,0x646d6152);
    }
    ZwClose(local_res10);
  }
  iVar3 = RtlCheckRegistryKey(2,L"MiniNT");
  if (-1 < iVar3) {
    IsWinPEBoot = 1;
  }
  RtlCheckRegistryKey(2,L"Setup");
  return iVar2;
}



===== wil_details_RecordCachedUsage @ 140001e50 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001fb0 =====

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



===== RamdiskReadWrite @ 140002040 =====

int RamdiskReadWrite(longlong param_1,longlong param_2)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  int iVar6;
  
  piVar2 = *(int **)(param_1 + 0x40);
  if (*piVar2 == 1) {
    pcVar3 = *(char **)(param_2 + 0xb8);
    iVar6 = 0;
    uVar1 = *(uint *)(pcVar3 + 8);
    if (uVar1 != 0) {
      uVar4 = *(ulonglong *)(pcVar3 + 0x18);
      if ((((uVar1 | uVar4) & (ulonglong)(piVar2[0x5f] - 1)) == 0) && (uVar4 <= uVar1 + uVar4)) {
        if (*(ulonglong *)(piVar2 + 0x3a) < uVar1 + uVar4) {
          iVar6 = -0x3fffffeb;
        }
        else if ((*pcVar3 == '\x04') && ((piVar2[0x38] & 1U) != 0)) {
          iVar6 = -0x3fffff5e;
        }
        else if ((uint)piVar2[0x36] < 3) {
          uVar5 = SendIrpToThread(param_1,param_2);
          iVar6 = (int)uVar5;
          if (iVar6 == 0x103) {
            return 0x103;
          }
        }
        else {
          uVar5 = RamdiskReadWriteReal(param_2,(longlong)piVar2);
          iVar6 = (int)uVar5;
        }
      }
      else {
        iVar6 = -0x3ffffff3;
      }
    }
  }
  else {
    iVar6 = -0x3ffffff0;
  }
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,1);
  return iVar6;
}



===== RamdiskReadWriteReal @ 140002118 =====

undefined8 RamdiskReadWriteReal(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char *pcVar2;
  void *pvVar3;
  void *_Dst;
  void *_Src;
  void *pvVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong _Size;
  uint local_res8 [2];
  longlong local_res10;
  longlong local_res18;
  
  local_res8[0] = 0;
  lVar1 = *(longlong *)(param_1 + 8);
  uVar5 = 0xc000000d;
  local_res10 = param_2;
  if ((*(byte *)(lVar1 + 10) & 5) == 0) {
    pvVar4 = (void *)MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
  }
  else {
    pvVar4 = *(void **)(lVar1 + 0x18);
  }
  if (pvVar4 == (void *)0x0) {
LAB_140002232:
    uVar5 = 0xc000009a;
  }
  else {
    pcVar2 = *(char **)(param_1 + 0xb8);
    uVar6 = *(uint *)(pcVar2 + 8);
    local_res18 = *(longlong *)(pcVar2 + 0x18);
    *(undefined8 *)(param_1 + 0x38) = 0;
    for (; uVar6 != 0; uVar6 = uVar6 - local_res8[0]) {
      pvVar3 = (void *)RamdiskMapPages(local_res10,local_res18,uVar6,local_res8);
      if (pvVar3 == (void *)0x0) goto LAB_140002232;
      _Size = (ulonglong)local_res8[0];
      uVar5 = 0;
      *(longlong *)(param_1 + 0x38) = *(longlong *)(param_1 + 0x38) + _Size;
      if (*pcVar2 == '\x03') {
        _Dst = pvVar4;
        _Src = pvVar3;
LAB_1400021e7:
        memmove(_Dst,_Src,_Size);
      }
      else {
        if (*pcVar2 == '\x04') {
          _Dst = pvVar3;
          _Src = pvVar4;
          goto LAB_1400021e7;
        }
        uVar5 = 0xc000000d;
        uVar6 = local_res8[0];
      }
      RamdiskUnmapPages(local_res10,(longlong)pvVar3,local_res18,local_res8[0]);
      pvVar4 = (void *)((longlong)pvVar4 + _Size);
      local_res18 = local_res18 + _Size;
    }
  }
  return uVar5;
}



===== RamdiskScsi @ 140002250 =====

ulonglong RamdiskScsi(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  
  if (*(int *)(*(longlong *)(param_1 + 0x40) + 4) < 4) {
    lVar1 = *(longlong *)(param_1 + 0x40) + 0x20;
    uVar3 = IoAcquireRemoveLockEx(lVar1,param_2,"",1,0x20);
    iVar2 = (int)uVar3;
    if (-1 < iVar2) {
      uVar3 = SendIrpToThread(param_1,param_2);
      iVar2 = (int)uVar3;
      if (iVar2 == 0x103) {
        IoReleaseRemoveLockEx(lVar1,param_2,0x20);
        return 0x103;
      }
    }
    uVar3 = uVar3 & 0xffffffff;
    *(int *)(param_2 + 0x30) = iVar2;
  }
  else {
    uVar3 = 0xc00000c0;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000c0;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== RamdiskFlushViews @ 140002318 =====

int RamdiskFlushViews(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  longlong *plVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  longlong *plVar7;
  int iVar8;
  ulonglong local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res10 = 0;
  local_38 = 0;
  uStack_30 = 0;
  bVar5 = false;
  bVar4 = false;
  iVar8 = 0;
  KeEnterCriticalRegion();
  lVar1 = param_1 + 0x60;
  ExAcquireFastMutex(lVar1);
  plVar3 = (longlong *)(param_1 + 0x138);
  plVar7 = (longlong *)*plVar3;
  if (plVar7 != plVar3) {
    do {
      if (plVar7[4] != 0) {
        *(int *)((longlong)plVar7 + 0x34) = *(int *)((longlong)plVar7 + 0x34) + 1;
        ExReleaseFastMutex(lVar1);
        KeLeaveCriticalRegion();
        local_res10 = (ulonglong)*(uint *)(plVar7 + 6);
        iVar6 = ZwFlushVirtualMemory(0xffffffffffffffff,plVar7 + 4,&local_res10,&local_38);
        if (((iVar6 < 0) || (iVar6 = (int)local_38, (int)local_38 < 0)) && (iVar8 == 0)) {
          iVar8 = iVar6;
        }
        KeEnterCriticalRegion();
        ExAcquireFastMutex(lVar1);
        piVar2 = (int *)((longlong)plVar7 + 0x34);
        *piVar2 = *piVar2 + -1;
        bVar4 = bVar5;
        if (*piVar2 == 0) {
          bVar4 = true;
          bVar5 = true;
        }
      }
      plVar7 = (longlong *)*plVar7;
    } while (plVar7 != plVar3);
    if ((bVar4) && (*(int *)(param_1 + 0x178) != 0)) {
      KeReleaseSemaphore(param_1 + 0x158,0,*(int *)(param_1 + 0x178),0);
      *(undefined4 *)(param_1 + 0x178) = 0;
    }
  }
  ExReleaseFastMutex(lVar1);
  KeLeaveCriticalRegion();
  return iVar8;
}



===== RamdiskMapPages @ 14000247c =====

longlong RamdiskMapPages(longlong param_1,longlong param_2,uint param_3,uint *param_4)

{
  uint *puVar1;
  ulonglong uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  uint *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  ulonglong uVar13;
  uint *puVar14;
  ulonglong local_res8;
  ulonglong local_res10;
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [24];
  undefined8 local_78;
  ulonglong *local_70;
  ulonglong *local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_50;
  longlong local_48 [2];
  
  puVar11 = auStack_98;
  uVar5 = *(uint *)(param_1 + 0xd8);
  uVar13 = (ulonglong)*(uint *)(param_1 + 0xf0) + param_2;
  uVar12 = (uint)uVar13;
  lVar9 = param_1;
  puVar14 = param_4;
  if (uVar5 < 3) {
    do {
      KeEnterCriticalRegion();
      ExAcquireFastMutex(param_1 + 0x60);
      for (puVar10 = *(uint **)(param_1 + 0x138);
          (puVar10 != (uint *)(param_1 + 0x138) &&
          (uVar2 = *(ulonglong *)(puVar10 + 10), uVar2 <= uVar13)); puVar10 = *(uint **)puVar10) {
        if (uVar13 < puVar10[0xc] + uVar2) {
          if ((char)puVar10[0xe] == '\0') {
            puVar10[0xd] = puVar10[0xd] + 1;
          }
          puVar1 = puVar10 + 4;
          lVar9 = *(longlong *)puVar1;
          if ((*(uint **)(lVar9 + 8) != puVar1) ||
             (plVar7 = *(longlong **)(puVar10 + 6), (uint *)*plVar7 != puVar1)) goto LAB_14000289b;
          *plVar7 = lVar9;
          *(longlong **)(lVar9 + 8) = plVar7;
          plVar7 = (longlong *)(param_1 + 0x148);
          lVar9 = *plVar7;
          if (*(longlong **)(lVar9 + 8) != plVar7) goto LAB_14000289b;
          *(longlong **)(puVar10 + 6) = plVar7;
          *(longlong *)puVar1 = lVar9;
          *(uint **)(lVar9 + 8) = puVar1;
          *plVar7 = (longlong)puVar1;
          ExReleaseFastMutex(param_1 + 0x60);
          KeLeaveCriticalRegion();
          uVar12 = uVar12 - puVar10[10];
          uVar5 = puVar10[0xc];
          *param_4 = uVar5 - uVar12;
          if (param_3 < uVar5 - uVar12) {
            *param_4 = param_3;
          }
          goto LAB_140002602;
        }
        if (uVar13 < uVar2) break;
      }
      for (puVar14 = *(uint **)(param_1 + 0x150); puVar14 != (uint *)(param_1 + 0x148);
          puVar14 = *(uint **)(puVar14 + 2)) {
        puVar10 = puVar14 + -4;
        if (((char)puVar14[10] == '\0') && (puVar14[9] == 0)) {
          lVar9 = *(longlong *)(puVar14 + 4);
          local_res8 = 0;
          if (lVar9 != 0) {
            uVar6 = PsGetCurrentProcess();
            MmUnmapViewOfSection(uVar6,lVar9);
            puVar14[6] = 0;
            puVar14[7] = 0;
            puVar14[8] = 0;
            puVar14[4] = 0;
            puVar14[5] = 0;
            lVar9 = *(longlong *)puVar14;
            if ((*(uint **)(lVar9 + 8) != puVar14) ||
               (plVar7 = *(longlong **)(puVar14 + 2), (uint *)*plVar7 != puVar14))
            goto LAB_14000289b;
            *plVar7 = lVar9;
            *(longlong **)(lVar9 + 8) = plVar7;
            plVar7 = *(longlong **)(param_1 + 0x150);
            if (*plVar7 != param_1 + 0x148) goto LAB_14000289b;
            *(longlong *)puVar14 = param_1 + 0x148;
            *(longlong **)(puVar14 + 2) = plVar7;
            *plVar7 = (longlong)puVar14;
            *(uint **)(param_1 + 0x150) = puVar14;
            lVar9 = *(longlong *)puVar10;
            if ((*(uint **)(lVar9 + 8) != puVar10) ||
               (plVar7 = *(longlong **)(puVar14 + -2), (uint *)*plVar7 != puVar10))
            goto LAB_14000289b;
            *plVar7 = lVar9;
            *(longlong **)(lVar9 + 8) = plVar7;
            plVar7 = (longlong *)(param_1 + 0x138);
            lVar9 = *plVar7;
            if (*(longlong **)(lVar9 + 8) != plVar7) goto LAB_14000289b;
            *(longlong *)puVar10 = lVar9;
            *(longlong **)(puVar14 + -2) = plVar7;
            *(uint **)(lVar9 + 8) = puVar10;
            *plVar7 = (longlong)puVar10;
          }
          local_res8 = (ulonglong)*(uint *)(param_1 + 0x128);
          local_res10 = ~(ulonglong)(*(uint *)(param_1 + 0x128) - 1) & uVar13;
          if (*(ulonglong *)(param_1 + 0xf8) < local_res10 + local_res8) {
            local_res8 = *(ulonglong *)(param_1 + 0xf8) - local_res10;
          }
          local_48[0] = 0;
          uVar6 = PsGetCurrentProcess();
          local_50 = 4;
          local_58 = 0;
          local_68 = &local_res8;
          local_60 = 2;
          local_70 = &local_res10;
          local_78 = 0;
          iVar4 = MmMapViewOfSection(*(undefined8 *)(param_1 + 0x108),uVar6,local_48,0);
          if (iVar4 < 0) {
            ExReleaseFastMutex(param_1 + 0x60);
            KeLeaveCriticalRegion();
            return 0;
          }
          *(ulonglong *)(puVar14 + 6) = local_res10;
          puVar14[8] = (uint)local_res8;
          *(longlong *)(puVar14 + 4) = local_48[0];
          puVar14[9] = 1;
          lVar9 = *(longlong *)puVar14;
          if ((*(uint **)(lVar9 + 8) != puVar14) ||
             (plVar7 = *(longlong **)(puVar14 + 2), (uint *)*plVar7 != puVar14)) goto LAB_14000289b;
          *plVar7 = lVar9;
          *(longlong **)(lVar9 + 8) = plVar7;
          plVar7 = (longlong *)(param_1 + 0x148);
          lVar9 = *plVar7;
          if (*(longlong **)(lVar9 + 8) != plVar7) goto LAB_14000289b;
          *(longlong *)puVar14 = lVar9;
          *(longlong **)(puVar14 + 2) = plVar7;
          *(uint **)(lVar9 + 8) = puVar14;
          *plVar7 = (longlong)puVar14;
          lVar9 = *(longlong *)puVar10;
          if ((*(uint **)(lVar9 + 8) != puVar10) ||
             (plVar7 = *(longlong **)(puVar14 + -2), (uint *)*plVar7 != puVar10))
          goto LAB_14000289b;
          *plVar7 = lVar9;
          *(longlong **)(lVar9 + 8) = plVar7;
          plVar7 = *(longlong **)(param_1 + 0x140);
          if (plVar7 == (longlong *)(param_1 + 0x138)) goto LAB_140002845;
          goto LAB_140002836;
        }
      }
      *(int *)(param_1 + 0x178) = *(int *)(param_1 + 0x178) + 1;
      ExReleaseFastMutex(param_1 + 0x60);
      KeLeaveCriticalRegion();
      local_78 = 0;
      KeWaitForSingleObject(param_1 + 0x158,0,0);
    } while( true );
  }
  goto LAB_1400028a2;
  while (plVar7 = (longlong *)plVar7[1], plVar7 != (longlong *)(param_1 + 0x138)) {
LAB_140002836:
    if ((ulonglong)plVar7[5] <= *(ulonglong *)(puVar14 + 6)) break;
  }
LAB_140002845:
  lVar9 = *plVar7;
  if (*(longlong **)(lVar9 + 8) == plVar7) {
    *(longlong *)puVar10 = lVar9;
    *(longlong **)(puVar14 + -2) = plVar7;
    *(uint **)(lVar9 + 8) = puVar10;
    *plVar7 = (longlong)puVar10;
    ExReleaseFastMutex(param_1 + 0x60);
    KeLeaveCriticalRegion();
    uVar12 = uVar12 - puVar14[6];
    uVar5 = puVar14[8];
    *param_4 = uVar5 - uVar12;
    if (param_3 < uVar5 - uVar12) {
      *param_4 = param_3;
    }
LAB_140002602:
    return (ulonglong)uVar12 + *(longlong *)(puVar10 + 8);
  }
LAB_14000289b:
  lVar9 = 3;
  pcVar3 = (code *)swi(0x29);
  uVar5 = (*pcVar3)();
  puVar11 = auStack_90;
LAB_1400028a2:
  if (uVar5 == 3) {
    lVar9 = *(longlong *)(param_1 + 0x100);
    *(undefined8 *)(puVar11 + -8) = 0x1400028e1;
    lVar8 = MmMapIoSpaceEx(((uVar13 >> 0xc) + lVar9) * 0x1000,
                           (uVar12 & 0xfff) + param_3 + 0xfff & 0xfffff000,4);
    lVar9 = 0;
    if (lVar8 != 0) {
      lVar9 = (uVar13 & 0xfff) + lVar8;
    }
  }
  else if (uVar5 == 5) {
    lVar9 = (ulonglong)(uVar12 & 0x7fffffff) +
            *(longlong *)(*(longlong *)(lVar9 + 0x198 + (uVar13 >> 0x1f & 0xffffffff) * 8) + 0x18);
    if (((uint)(uVar13 >> 0x1f) < *(int *)(param_1 + 0x118) - 1U) &&
       (uVar5 = 0x80000000 - (uVar12 & 0x7fffffff), uVar5 < param_3)) {
      param_3 = uVar5;
    }
  }
  else {
    lVar9 = *(longlong *)(lVar9 + 0x110) + uVar13;
  }
  *puVar14 = param_3;
  return lVar9;
}



===== RamdiskUnmapPages @ 140002968 =====

void RamdiskUnmapPages(longlong param_1,longlong param_2,longlong param_3,uint param_4)

{
  int *piVar1;
  ulonglong uVar2;
  bool bVar3;
  bool bVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  uVar7 = (ulonglong)*(uint *)(param_1 + 0xf0) + param_3;
  uVar8 = (ulonglong)param_4;
  if (*(uint *)(param_1 + 0xd8) < 3) {
    uVar2 = uVar7 + uVar8;
    bVar4 = false;
    bVar3 = false;
    KeEnterCriticalRegion();
    ExAcquireFastMutex(param_1 + 0x60);
    puVar5 = *(undefined8 **)(param_1 + 0x138);
    if (param_4 != 0) {
      do {
        uVar6 = puVar5[5] + (ulonglong)*(uint *)(puVar5 + 6);
        if (uVar7 < uVar6) {
          if (*(char *)(puVar5 + 7) == '\0') {
            piVar1 = (int *)((longlong)puVar5 + 0x34);
            *piVar1 = *piVar1 + -1;
            bVar3 = bVar4;
            if (*piVar1 == 0) {
              bVar3 = true;
              bVar4 = true;
            }
          }
          if (uVar2 <= uVar6) break;
          uVar8 = (ulonglong)
                  ((int)uVar8 + (((uint)uVar7 - *(uint *)(puVar5 + 6)) - *(int *)(puVar5 + 5)));
        }
        puVar5 = (undefined8 *)*puVar5;
      } while ((int)uVar8 != 0);
      if ((bVar3) && (*(int *)(param_1 + 0x178) != 0)) {
        KeReleaseSemaphore(param_1 + 0x158,0,*(int *)(param_1 + 0x178),0);
        *(undefined4 *)(param_1 + 0x178) = 0;
      }
    }
    ExReleaseFastMutex(param_1 + 0x60);
    KeLeaveCriticalRegion();
  }
  else if (*(uint *)(param_1 + 0xd8) == 3) {
    MmUnmapIoSpace(param_2 - (uVar7 & 0xfff),param_4 + 0xfff + ((uint)uVar7 & 0xfff) & 0xfffff000);
  }
  return;
}



===== SendIrpToThread @ 140002ab0 =====

undefined8 SendIrpToThread(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  lVar2 = IoAllocateWorkItem();
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    *(longlong *)(param_2 + 0x78) = lVar2;
    IoQueueWorkItem(lVar2,RamdiskWorkerThread,1,param_2);
    uVar3 = 0x103;
  }
  return uVar3;
}



===== _guard_check_icall @ 140002b20 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002b38 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140002b5c =====

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



===== __cpu_features_init @ 140002bd0 =====

/* WARNING: Removing unreachable block (ram,0x000140002c3a) */
/* WARNING: Removing unreachable block (ram,0x000140002be9) */
/* WARNING: Removing unreachable block (ram,0x000140002bda) */

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



===== __security_check_cookie @ 140002ca0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002ce0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002d10 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002d40 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002dc0 =====

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



===== memset @ 1400030c0 =====

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



===== __memset_repmovs @ 140003200 =====

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



===== __memset_query @ 140003280 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003300 =====

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



===== __memset_spec_ermsb_repmovsb @ 140003440 =====

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



===== __memset_spec_plain @ 1400034c0 =====

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



===== RamdiskCreateDiskDevice @ 140009008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RamdiskCreateDiskDevice(ulonglong param_1,longlong param_2,char param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  longlong *plVar2;
  short sVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  byte bVar7;
  char cVar8;
  int iVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  int iVar14;
  ulonglong uVar15;
  undefined8 *puVar16;
  undefined4 uVar17;
  int iVar18;
  longlong *plVar19;
  uint uVar20;
  longlong *plVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  ulonglong uVar24;
  uint uVar25;
  uint uVar26;
  undefined4 uVar27;
  undefined1 auStack_1e8 [8];
  undefined1 auStack_1e0 [24];
  longlong *local_1c8;
  ulonglong local_1c0;
  longlong *local_1b8;
  undefined4 local_1b0;
  undefined4 local_1a8;
  undefined8 local_1a0;
  undefined4 local_198;
  undefined4 local_190;
  undefined8 local_188;
  uint local_180;
  longlong local_178;
  longlong local_170;
  longlong *local_168;
  undefined8 local_160;
  short *psStack_158;
  undefined8 local_150;
  short *psStack_148;
  longlong local_140;
  longlong lStack_138;
  ulonglong local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 *local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  ulonglong uStack_100;
  longlong local_f8;
  longlong local_f0;
  ulonglong local_e8;
  undefined8 *local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  ulonglong uStack_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  undefined1 local_6c;
  wchar_t local_68 [16];
  ulonglong local_48;
  
  bVar7 = IsWinPEBoot;
  puVar23 = auStack_1e8;
  local_48 = __security_cookie ^ (ulonglong)auStack_1e8;
  local_108 = 0;
  uStack_100 = uStack_100 & 0xffffffff00000000;
  local_a8 = 0;
  local_70 = 0;
  local_6c = 0;
  iVar9 = 0;
  uVar20 = *(uint *)(param_2 + 0x14);
  uVar27 = 0;
  local_178 = 0;
  local_140 = 0;
  lVar10 = 0;
  local_160 = 0;
  lVar13 = 0;
  local_150 = 0;
  local_168 = (longlong *)0x0;
  local_170 = 0;
  lStack_138 = 0;
  psStack_158 = (short *)0x0;
  psStack_148 = (short *)0x0;
  local_130 = 0;
  local_f0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_118 = (undefined8 *)0x0;
  uStack_110 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_e8 = param_1;
  local_e0 = param_4;
  if (uVar20 < 3) {
    RtlInitUnicodeString(&local_d8,param_2 + 0x38);
    local_118 = &local_d8;
    local_128 = CONCAT44(local_128._4_4_,0x30);
    uStack_120 = 0;
    uStack_110 = CONCAT44(uStack_110._4_4_,0x240);
    local_180 = -(uint)(param_3 != '\0') & 0x101;
    local_188 = 0;
    local_190 = 0;
    local_198 = 0;
    local_1a0 = 0;
    local_1a8 = 0;
    local_1b0 = 1;
    local_1b8 = (longlong *)CONCAT44(local_1b8._4_4_,1);
    local_1c0 = local_1c0 & 0xffffffff00000000;
    local_1c8 = (longlong *)0x0;
    local_108 = 0;
    uStack_100 = 0;
    iVar9 = IoCreateFile(&local_168,(~*(uint *)(param_2 + 0x18) & 1) * 2 | 0x100081,&local_128,
                         &local_c8);
    if ((-1 < iVar9) && (param_3 == '\0')) {
      local_1c8 = (longlong *)CONCAT44(local_1c8._4_4_,5);
      iVar9 = ZwQueryInformationFile(local_168,&local_c8,&local_b8,0x18);
      if (-1 < iVar9) {
        if (uStack_b0 < (ulonglong)*(uint *)(param_2 + 0x28) + *(longlong *)(param_2 + 0x20)) {
LAB_140009ace:
          iVar9 = -0x3ffffff3;
        }
        else {
          local_128 = 0x30;
          uStack_110 = 0x200;
          uStack_120 = 0;
          local_118 = (undefined8 *)0x0;
          local_1b8 = local_168;
          local_1c0 = CONCAT44(local_1c0._4_4_,0x8000000);
          local_1c8 = (longlong *)CONCAT44(local_1c8._4_4_,(~*(uint *)(param_2 + 0x18) & 1) * 2 + 2)
          ;
          local_108 = 0;
          uStack_100 = 0;
          iVar9 = ZwCreateSection(&local_170,0xf001f,&local_128,0);
          if (-1 < iVar9) {
            ZwClose(local_168);
            local_168 = (longlong *)0x0;
            local_1c0 = 0;
            local_1c8 = &local_f8;
            local_f8 = 0;
            iVar9 = ObReferenceObjectByHandle
                              (local_170,0xf001f,*(undefined8 *)MmSectionObjectType_exref,0);
            lVar13 = local_f8;
            if (-1 < iVar9) {
              ZwClose(local_170);
              uVar20 = *(uint *)(param_2 + 0x30);
              local_170 = 0;
              if (uVar20 == 0) {
                *(uint *)(param_2 + 0x30) = DefaultViewCount;
                uVar20 = DefaultViewCount;
              }
              else if (uVar20 < MinimumViewCount) {
                *(uint *)(param_2 + 0x30) = MinimumViewCount;
                uVar20 = MinimumViewCount;
              }
              else if (MaximumViewCount < uVar20) {
                *(uint *)(param_2 + 0x30) = MaximumViewCount;
                uVar20 = MaximumViewCount;
              }
              uVar11 = (ulonglong)uVar20;
              uVar25 = *(uint *)(param_2 + 0x34);
              if (uVar25 == 0) {
                *(uint *)(param_2 + 0x34) = DefaultViewLength;
                uVar25 = DefaultViewLength;
              }
              else if (uVar25 < MinimumViewLength) {
                *(uint *)(param_2 + 0x34) = MinimumViewLength;
                uVar25 = MinimumViewLength;
              }
              else if (MaximumViewLength < uVar25) {
                *(uint *)(param_2 + 0x34) = MaximumViewLength;
                uVar25 = MaximumViewLength;
              }
              uVar24 = (ulonglong)uVar25;
              uVar15 = (ulonglong)uVar20 * (ulonglong)uVar25;
              while (MaximumPerDiskViewLength < uVar15) {
                if (MinimumViewCount < uVar20) {
                  *(uint *)(param_2 + 0x30) = uVar20 >> 1;
                  if (uVar20 >> 1 < MinimumViewCount) {
                    *(uint *)(param_2 + 0x30) = MinimumViewCount;
                  }
                }
                else {
                  if (uVar25 <= MinimumViewLength) {
                    *(undefined4 *)(param_2 + 0x34) = 0x100000;
                    *(undefined4 *)(param_2 + 0x30) = 0x10;
                    uVar11 = 0x10;
                    break;
                  }
                  uVar25 = uVar25 >> 1;
                  uVar24 = (ulonglong)uVar25;
                  *(uint *)(param_2 + 0x34) = uVar25;
                  if (uVar25 < MinimumViewLength) {
                    *(uint *)(param_2 + 0x34) = MinimumViewLength;
                    uVar24 = (ulonglong)MinimumViewLength;
                  }
                }
                uVar20 = *(uint *)(param_2 + 0x30);
                uVar11 = (ulonglong)uVar20;
                uVar25 = (uint)uVar24;
                uVar15 = uVar24 * uVar11;
              }
              lVar10 = ExAllocatePool2(0x100,uVar11 << 6,0x646d6152);
              if (lVar10 != 0) {
                if ((*(uint *)(param_2 + 0x18) & 0x20) != 0) {
                  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 1;
                }
                goto LAB_140009487;
              }
              goto LAB_1400093d8;
            }
          }
        }
      }
    }
  }
  else {
    uVar27 = 0;
    if (uVar20 == 3) {
      local_130 = *(ulonglong *)(param_2 + 0x30);
      if (local_130 == 0) {
        iVar9 = -0x3ffffff3;
        puVar23 = auStack_1e8;
        goto LAB_140009b8f;
      }
      *(uint *)(param_2 + 0x18) =
           ((*(uint *)(param_2 + 0x18) >> 5 | (uint)IsWinPEBoot) & 1 ^
           (*(uint *)(param_2 + 0x18) & 0xfffffffe | 2)) & 0xffffffe7;
      if (bVar7 != 0) {
        uVar27 = 0x20000;
      }
    }
    else {
      if (uVar20 == 4) {
        local_f0 = *(longlong *)(param_2 + 0x30);
        uVar20 = *(uint *)(param_2 + 0x18) & 0xffffffe6 | 6;
      }
      else {
        if (uVar20 != 5) goto LAB_140009ace;
        uVar20 = *(uint *)(param_2 + 0x18) & 0xffffffe2 | 2;
      }
      *(uint *)(param_2 + 0x18) = uVar20;
    }
    if (param_3 != '\0') goto LAB_140009b8f;
LAB_140009487:
    if (*(int *)(param_2 + 0x14) - 4U < 2) {
      RtlStringCbPrintfW(local_68,0x1e,L"%u",(ulonglong)*(uint *)(param_2 + 4));
      cVar8 = RtlCreateUnicodeString(&local_140,local_68);
      if (cVar8 != '\0') goto LAB_1400094eb;
    }
    else {
      iVar9 = RtlStringFromGUID(param_2 + 4,&local_140);
LAB_1400094eb:
      if ((-1 < iVar9) && (lStack_138 != 0)) {
        uVar20 = (ushort)local_140 + 0x20;
        psStack_158 = (short *)ExAllocatePool2(0x40,uVar20,0x646d6152);
        if (psStack_158 != (short *)0x0) {
          local_160 = CONCAT62(CONCAT42(local_160._4_4_,(short)uVar20),(short)uVar20 + -2);
          RtlStringCbCopyW(psStack_158,(ulonglong)uVar20,0x140005158);
          RtlStringCbCatW(psStack_158,(ulonglong)uVar20,lStack_138);
          uVar11 = Feature_AllowLargerRamdiskSize__private_IsEnabledDeviceUsageNoInline();
          uVar20 = *(uint *)(param_2 + 0x14);
          if ((int)uVar11 == 0) {
            uVar11 = 0x3a0;
            if (uVar20 < 3) {
              lVar12 = -1;
              do {
                lVar12 = lVar12 + 1;
              } while (*(short *)(param_2 + 0x38 + lVar12 * 2) != 0);
              uVar11 = (ulonglong)((int)lVar12 * 2 + 0x3a0);
            }
          }
          else {
            uVar11 = 0x1a0;
            if (uVar20 < 3) {
              lVar12 = -1;
              do {
                lVar12 = lVar12 + 1;
              } while (*(short *)(param_2 + 0x38 + lVar12 * 2) != 0);
              uVar11 = (ulonglong)((int)lVar12 * 2 + 0x1a0);
            }
            else if (uVar20 == 5) {
              uVar11 = (ulonglong)
                       ((int)(*(longlong *)(param_2 + 0x20) + 0x7fffffffU >> 0x1f) * 8 + 0x1a0);
            }
          }
          uVar17 = 1;
          if ((*(uint *)(param_2 + 0x18) & 2) != 0) {
            uVar17 = uVar27;
          }
          local_1b8 = &local_178;
          local_1c0 = local_1c0 & 0xffffffffffffff00;
          local_1c8 = (longlong *)CONCAT44(local_1c8._4_4_,uVar17);
          iVar9 = IoCreateDevice(*(undefined8 *)(*(longlong *)(local_e8 + 8) + 8),uVar11,&local_160,
                                 (-(uint)((*(uint *)(param_2 + 0x18) & 0x20) != 0) & 0xfffffffb) + 7
                                );
          if (iVar9 < 0) goto LAB_140009ad3;
          plVar21 = *(longlong **)(local_178 + 0x40);
          if ((*(uint *)(param_2 + 0x18) & 8) == 0) {
            uVar20 = (ushort)local_140 + 0x24;
            local_150 = CONCAT62(CONCAT42(local_150._4_4_,(short)uVar20),(ushort)local_140 + 0x22);
            psStack_148 = (short *)ExAllocatePool2(0x40,uVar20,0x646d6152);
            if (psStack_148 == (short *)0x0) {
              *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 8;
            }
            else {
              RtlStringCbCopyW(psStack_148,(ulonglong)uVar20,0x140005178);
              RtlStringCbCatW(psStack_148,(ulonglong)uVar20,lStack_138);
              iVar9 = IoCreateSymbolicLink(&local_150,&local_160);
              if (iVar9 < 0) {
                *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 8;
                ExFreePoolWithTag(psStack_148,0x646d6152);
                psStack_148 = (short *)0x0;
              }
            }
            sVar3 = *(short *)(param_2 + 0x38);
            if ((ushort)(sVar3 - 0x41U) < 0x1a) {
              *(short *)(plVar21 + 0x24) = sVar3;
              iVar9 = RamdiskMapDosDriveLetter(sVar3,(longlong)&local_160);
              if (iVar9 < 0) {
                *(undefined2 *)(plVar21 + 0x24) = 0;
              }
            }
          }
          if ((*(int *)(param_2 + 0x14) == 3) && ((*(uint *)(param_2 + 0x18) & 0x40) == 0)) {
            *(uint *)(local_178 + 0x30) = *(uint *)(local_178 + 0x30) | 0x100;
          }
          *(uint *)(local_178 + 0x30) = *(uint *)(local_178 + 0x30) | 0x2010;
          *(undefined4 *)(local_178 + 0x98) = 1;
          *local_e0 = plVar21;
          *plVar21 = 1;
          *(undefined4 *)(plVar21 + 0xc) = 1;
          plVar21[0xd] = 0;
          *(undefined4 *)(plVar21 + 0xe) = 0;
          KeInitializeEvent(plVar21 + 0xf,1,0);
          local_1c8 = (longlong *)CONCAT44(local_1c8._4_4_,0x20);
          IoInitializeRemoveLockEx(plVar21 + 4,0x646d6152,1,0);
          plVar21[10] = local_160;
          plVar21[0xb] = (longlong)psStack_158;
          psStack_158 = (short *)0x0;
          plVar21[0x19] = local_150;
          plVar21[0x1a] = (longlong)psStack_148;
          psStack_148 = (short *)0x0;
          uVar27 = *(undefined4 *)(param_2 + 8);
          uVar17 = *(undefined4 *)(param_2 + 0xc);
          uVar6 = *(undefined4 *)(param_2 + 0x10);
          *(undefined4 *)(plVar21 + 0x15) = *(undefined4 *)(param_2 + 4);
          *(undefined4 *)((longlong)plVar21 + 0xac) = uVar27;
          *(undefined4 *)(plVar21 + 0x16) = uVar17;
          *(undefined4 *)((longlong)plVar21 + 0xb4) = uVar6;
          plVar21[0x17] = local_140;
          plVar21[0x18] = lStack_138;
          lStack_138 = 0;
          plVar21[2] = local_178;
          lVar12 = RamdiskBusFdo;
          plVar21[1] = RamdiskBusFdo;
          plVar21[3] = lVar12;
          plVar21[0x20] = local_130;
          plVar21[0x22] = local_f0;
          plVar21[0x21] = lVar13;
          lVar13 = 0;
          if (*(uint *)(param_2 + 0x14) < 3) {
            RtlStringCbCopyW((short *)(plVar21 + 0x33),uVar11,param_2 + 0x38);
          }
          *(undefined4 *)(plVar21 + 0x1b) = *(undefined4 *)(param_2 + 0x14);
          *(undefined4 *)(plVar21 + 0x1c) = *(undefined4 *)(param_2 + 0x18);
          if (lVar10 != 0) {
            *(undefined4 *)((longlong)plVar21 + 0x124) = *(undefined4 *)(param_2 + 0x30);
            *(undefined4 *)(plVar21 + 0x25) = *(undefined4 *)(param_2 + 0x34);
            plVar21[0x26] = lVar10;
            KeInitializeSemaphore(plVar21 + 0x2b,0,0x7fffffff);
            plVar19 = plVar21 + 0x27;
            *(undefined4 *)(plVar21 + 0x2f) = 0;
            plVar2 = plVar21 + 0x29;
            plVar21[0x28] = (longlong)plVar19;
            *plVar19 = (longlong)plVar19;
            uVar20 = 0;
            plVar21[0x2a] = (longlong)plVar2;
            *plVar2 = (longlong)plVar2;
            if (*(int *)((longlong)plVar21 + 0x124) != 0) {
              puVar16 = (undefined8 *)(lVar10 + 0x10);
              do {
                puVar4 = (undefined8 *)plVar21[0x28];
                if ((longlong *)*puVar4 != plVar19) goto LAB_140009a8b;
                puVar1 = puVar16 + -2;
                puVar16[-1] = puVar4;
                *puVar1 = plVar19;
                *puVar4 = puVar1;
                plVar21[0x28] = (longlong)puVar1;
                puVar4 = (undefined8 *)plVar21[0x2a];
                if ((longlong *)*puVar4 != plVar2) goto LAB_140009a8b;
                *puVar16 = plVar2;
                uVar20 = uVar20 + 1;
                puVar16[1] = puVar4;
                *puVar4 = puVar16;
                plVar21[0x2a] = (longlong)puVar16;
                puVar16 = puVar16 + 8;
              } while (uVar20 < *(uint *)((longlong)plVar21 + 0x124));
            }
            lVar10 = 0;
          }
          lVar12 = *(longlong *)(param_2 + 0x20);
          plVar21[0x1d] = lVar12;
          uVar20 = *(uint *)(param_2 + 0x28);
          *(uint *)(plVar21 + 0x1e) = uVar20;
          *(undefined8 *)((longlong)plVar21 + 0x17c) = 0;
          *(undefined4 *)(plVar21 + 0x31) = 0;
          plVar21[0x1f] = lVar12 + (ulonglong)uVar20;
          if (((*(uint *)(param_2 + 0x18) & 0x20) == 0) && (*(int *)(param_2 + 0x14) == 3)) {
            local_130 = local_130 & 0xffffffff00000000;
            lVar12 = RamdiskMapPages((longlong)plVar21,0,0x1000,(uint *)&local_130);
            if (lVar12 == 0) goto LAB_1400093d8;
            lVar13 = RtlCompareMemory(lVar12 + 0xb,&local_a0);
            if (lVar13 == 0x35) {
              uVar20 = 0x10;
              uVar26 = 1 << (*(byte *)(lVar12 + 0x6c) & 0x1f);
              uVar25 = 0x80;
            }
            else {
              uVar20 = (uint)*(ushort *)(lVar12 + 0x1a);
              uVar25 = (uint)*(ushort *)(lVar12 + 0x18);
              uVar26 = (uint)*(ushort *)(lVar12 + 0xb);
            }
            *(uint *)((longlong)plVar21 + 0x17c) = uVar26;
            *(uint *)(plVar21 + 0x30) = uVar25;
            *(uint *)(plVar21 + 0x31) = uVar20;
            RamdiskUnmapPages((longlong)plVar21,lVar12,0,(uint)local_130);
          }
          iVar9 = *(int *)((longlong)plVar21 + 0x17c);
          if (((iVar9 == 0) || (iVar14 = (int)plVar21[0x30], iVar14 == 0)) ||
             (iVar18 = (int)plVar21[0x31], iVar18 == 0)) {
            if ((*(uint *)(param_2 + 0x18) & 0x20) == 0) {
              *(undefined4 *)(plVar21 + 0x30) = 0x80;
              *(undefined4 *)(plVar21 + 0x31) = 0x10;
              iVar18 = 0x10;
              *(undefined4 *)((longlong)plVar21 + 0x17c) = 0x200;
              iVar14 = 0x80;
              iVar9 = 0x200;
            }
            else {
              iVar18 = 0x40;
              *(undefined4 *)(plVar21 + 0x30) = 0x20;
              iVar9 = 0x800;
              *(undefined4 *)(plVar21 + 0x31) = 0x40;
              *(undefined4 *)((longlong)plVar21 + 0x17c) = 0x800;
              iVar14 = 0x20;
            }
          }
          uVar20 = iVar9 * iVar14 * iVar18;
          uVar24 = (ulonglong)uVar20;
          *(uint *)((longlong)plVar21 + 0x18c) = uVar20;
          uVar11 = *(ulonglong *)(param_2 + 0x20);
          uVar15 = uVar11 / uVar24;
          iVar9 = (int)uVar15;
          uVar15 = (uVar15 & 0xffffffff) * uVar24;
          *(int *)((longlong)plVar21 + 0x184) = iVar9;
          if (uVar15 < *(ulonglong *)(param_2 + 0x20)) {
            *(int *)((longlong)plVar21 + 0x184) = iVar9 + 1;
          }
          KeEnterCriticalRegion(uVar15,uVar11 % uVar24);
          uVar11 = local_e8;
          ExAcquireFastMutex(local_e8 + 0x60);
          puVar22 = auStack_1e8;
          lVar13 = uVar11 + 0x98;
          plVar21 = plVar21 + 0x13;
          plVar19 = *(longlong **)(uVar11 + 0xa0);
          if (*plVar19 != lVar13) {
LAB_140009a8b:
            pcVar5 = (code *)swi(0x29);
            lVar13 = (*pcVar5)(3);
            puVar22 = auStack_1e0;
          }
          *plVar21 = lVar13;
          plVar21[1] = (longlong)plVar19;
          *plVar19 = (longlong)plVar21;
          *(longlong **)(lVar13 + 8) = plVar21;
          *(undefined8 *)(puVar22 + -8) = 0x140009aab;
          ExReleaseFastMutex(uVar11 + 0x60);
          *(undefined8 *)(puVar22 + -8) = 0x140009ab7;
          KeLeaveCriticalRegion();
          iVar9 = 0;
          *(uint *)(*(longlong *)(puVar22 + 0x70) + 0x30) =
               *(uint *)(*(longlong *)(puVar22 + 0x70) + 0x30) & 0xffffff7f;
          puVar23 = puVar22;
          goto LAB_140009b8f;
        }
      }
    }
LAB_1400093d8:
    iVar9 = -0x3fffff66;
  }
LAB_140009ad3:
  if (psStack_148 != (short *)0x0) {
    ExFreePoolWithTag(psStack_148,0x646d6152);
    psStack_148 = (short *)0x0;
  }
  if (psStack_158 != (short *)0x0) {
    ExFreePoolWithTag(psStack_158,0x646d6152);
    psStack_158 = (short *)0x0;
  }
  if (lStack_138 != 0) {
    ExFreePoolWithTag(lStack_138,0x646d6152);
    lStack_138 = 0;
  }
  if (lVar10 != 0) {
    ExFreePoolWithTag(lVar10,0x646d6152);
  }
  if (lVar13 != 0) {
    ObfDereferenceObject(lVar13);
  }
  if (local_170 != 0) {
    ZwClose();
    local_170 = 0;
  }
  puVar23 = auStack_1e8;
  if (local_168 != (longlong *)0x0) {
    ZwClose();
    puVar23 = auStack_1e8;
  }
LAB_140009b8f:
  *(undefined8 *)(puVar23 + -8) = 0x140009ba0;
  return iVar9;
}



===== RamdiskCreateRamBackedDisk @ 140009bc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RamdiskCreateRamBackedDisk(ulonglong param_1,int *param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined1 *_Src;
  longlong lVar7;
  ulonglong uVar8;
  int iVar9;
  uint uVar10;
  longlong *plVar11;
  undefined1 auStack_2a8 [32];
  undefined4 local_288;
  undefined4 local_280;
  uint local_278;
  longlong local_270;
  ulonglong local_268;
  undefined8 local_260;
  undefined8 uStack_258;
  undefined8 local_250;
  undefined8 uStack_248;
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2a8;
  local_270 = 0;
  local_260 = 0;
  uStack_258 = 0;
  _Src = (undefined1 *)0x0;
  local_250 = 0;
  uStack_248 = 0;
  local_268 = param_1;
  memset(local_238,0,0x200);
  if ((param_2 == (int *)0x0) || (*param_2 != 0x40)) {
    iVar3 = -0x3ffffff3;
  }
  else {
    uVar8 = 0;
    uVar2 = KeQueryHighestNodeNumber();
    local_278 = uVar2 + 1;
    uVar4 = Feature_AllowLargerRamdiskSize__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      _Src = local_238;
    }
    else {
      _Src = (undefined1 *)
             ExAllocatePool2(0x100,(*(longlong *)(param_2 + 8) + 0x7fffffffU >> 0x1f) << 3);
      if (_Src == (undefined1 *)0x0) {
        iVar3 = -0x3fffff66;
        goto LAB_140009e65;
      }
    }
    uVar10 = uVar2 + 1;
    uVar1 = 0x80000000;
    for (uVar4 = *(ulonglong *)(param_2 + 8); iVar9 = (int)uVar8, uVar4 != 0; uVar4 = uVar4 - uVar5)
    {
      uVar5 = uVar4;
      if (uVar1 <= uVar4) {
        uVar5 = uVar1;
      }
      if (1 < uVar10) {
        KeQueryNodeActiveAffinity(uVar8 % (ulonglong)uVar10,&local_260);
        KeSetSystemGroupAffinityThread(&local_260);
      }
      local_280 = 4;
      local_288 = 1;
      uVar6 = MmAllocatePagesForMdlEx(0);
      *(undefined8 *)(_Src + uVar8 * 8) = uVar6;
      if (1 < local_278) {
        KeRevertToUserGroupAffinityThread(&local_250);
      }
      lVar7 = *(longlong *)(_Src + uVar8 * 8);
      if (lVar7 == 0) {
LAB_140009e10:
        iVar3 = -0x3fffff66;
        goto LAB_140009e15;
      }
      if ((*(byte *)(lVar7 + 10) & 5) == 0) {
        local_280 = 0x40000010;
        local_288 = 0;
        lVar7 = MmMapLockedPagesSpecifyCache();
      }
      else {
        lVar7 = *(longlong *)(lVar7 + 0x18);
      }
      if (lVar7 == 0) {
        MmFreePagesFromMdl(*(undefined8 *)(_Src + uVar8 * 8));
        ExFreePoolWithTag(*(undefined8 *)(_Src + uVar8 * 8),0);
        *(undefined8 *)(_Src + uVar8 * 8) = 0;
        goto LAB_140009e10;
      }
      uVar8 = (ulonglong)(iVar9 + 1);
      uVar10 = local_278;
      uVar1 = uVar5;
    }
    iVar3 = RamdiskCreateDiskDevice(local_268,(longlong)param_2,'\0',&local_270);
    if (iVar3 < 0) {
LAB_140009e15:
      if (iVar9 != 0) {
        plVar11 = (longlong *)(_Src + uVar8 * 8);
        do {
          plVar11 = plVar11 + -1;
          MmUnmapLockedPages(*(undefined8 *)(*plVar11 + 0x18),*plVar11);
          MmFreePagesFromMdl(*plVar11);
          ExFreePoolWithTag(*plVar11,0);
          uVar10 = (int)uVar8 - 1;
          uVar8 = (ulonglong)uVar10;
        } while (uVar10 != 0);
      }
    }
    else {
      memmove((void *)(local_270 + 0x198),_Src,uVar8 << 3);
      *(int *)(local_270 + 0x11c) = (int)uVar1;
      *(int *)(local_270 + 0x118) = iVar9;
    }
  }
LAB_140009e65:
  uVar8 = Feature_AllowLargerRamdiskSize__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar8 != 0) && (_Src != (undefined1 *)0x0)) {
    ExFreePoolWithTag(_Src,0x646d6152);
  }
  return iVar3;
}



===== RamdiskCreateRamDisk @ 140009ebc =====

int RamdiskCreateRamDisk(longlong param_1,longlong param_2,char param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  undefined8 local_res8;
  
  uVar4 = *(ulonglong *)(param_1 + 0x40);
  local_res8 = 0;
  piVar5 = *(int **)(param_2 + 0x18);
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (uVar2 < 0x40) {
    return -0x3ffffff3;
  }
  if (*piVar5 != 0x40) {
    return -0x3ffffff3;
  }
  uVar3 = piVar5[5];
  if (uVar3 == 4) {
    return -0x3ffffff3;
  }
  if (uVar3 == 5) {
    if (param_3 != '\0') {
      return 0;
    }
    iVar6 = RamdiskCreateRamBackedDisk(uVar4,piVar5);
    if (iVar6 < 0) {
      return iVar6;
    }
    goto LAB_140009f1b;
  }
  if ((uVar3 == 3) && (ExportBootDiskAsCd != '\0')) {
    piVar5[6] = piVar5[6] | 0x20;
  }
  if ((piVar5[6] & 0x20U) == 0) {
    if (uVar3 < 3) goto LAB_140009f78;
  }
  else if (uVar3 != 3) {
    if (uVar3 != 2) {
      return -0x3ffffff3;
    }
LAB_140009f78:
    piVar1 = (int *)((longlong)piVar5 + (ulonglong)uVar2);
    for (piVar7 = piVar5 + 0xe; piVar7 < piVar1; piVar7 = (int *)((longlong)piVar7 + 2)) {
      if ((short)*piVar7 == 0) goto LAB_140009f92;
    }
    if (piVar7 == piVar1) {
      return -0x3ffffff3;
    }
  }
LAB_140009f92:
  iVar6 = RamdiskCreateDiskDevice(uVar4,(longlong)piVar5,param_3,&local_res8);
  if (iVar6 < 0) {
    return iVar6;
  }
LAB_140009f1b:
  IoInvalidateDeviceRelations(*(undefined8 *)(uVar4 + 0x10),0);
  *(undefined8 *)(param_2 + 0x38) = 0;
  return iVar6;
}



===== RamdiskDeviceControl @ 140009fb0 =====

ulonglong RamdiskDeviceControl(longlong param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  ulonglong uVar5;
  void *_Dst;
  undefined2 *puVar6;
  ulonglong *puVar7;
  ushort *puVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  int *piVar11;
  uint uVar12;
  undefined8 uVar13;
  int *piVar14;
  int *piVar15;
  longlong lVar16;
  ulonglong uVar17;
  int *piVar18;
  
  piVar3 = *(int **)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  uVar12 = IoAcquireRemoveLockEx(piVar3 + 8,param_2,"",1,0x20);
  lVar16 = 0;
  uVar17 = (ulonglong)uVar12;
  if ((int)uVar12 < 0) goto LAB_14000a6a0;
  uVar17 = 0xc0000010;
  if (*piVar3 == 0) {
    iVar2 = *(int *)(lVar4 + 0x18);
    if (iVar2 == 0x240000) {
      uVar12 = RamdiskCreateRamDisk(param_1,param_2,'\x01');
      uVar17 = (ulonglong)uVar12;
      if (-1 < (int)uVar12) goto LAB_14000a673;
    }
    else if (iVar2 == 0x240004) {
      if ((*(uint *)(lVar4 + 0x10) < 0x14) ||
         (piVar11 = *(int **)(param_2 + 0x18), *piVar11 != 0x14)) goto LAB_14000a0a6;
      KeEnterCriticalRegion();
      ExAcquireFastMutex(piVar3 + 0x18);
      piVar18 = piVar3 + 0x26;
      piVar14 = *(int **)piVar18;
      if (piVar14 == piVar18) {
LAB_14000a5ca:
        uVar17 = 0xc000000e;
      }
      else {
        do {
          piVar15 = piVar14 + -0x26;
          if ((*(longlong *)(piVar14 + 4) == *(longlong *)(piVar11 + 1)) &&
             (*(longlong *)(piVar14 + 6) == *(longlong *)(piVar11 + 3))) break;
          piVar14 = *(int **)piVar14;
          piVar15 = (int *)0x0;
        } while (piVar14 != piVar18);
        if (piVar15 == (int *)0x0) goto LAB_14000a5ca;
        *(undefined1 *)((longlong)piVar15 + 0x122) = 1;
        uVar17 = 0;
      }
LAB_14000a255:
      ExReleaseFastMutex(piVar3 + 0x18);
      KeLeaveCriticalRegion();
    }
    else if (iVar2 == 0x240008) {
      if ((0x13 < *(uint *)(lVar4 + 0x10)) &&
         (piVar11 = *(int **)(param_2 + 0x18), *piVar11 == 0x14)) {
        KeEnterCriticalRegion();
        ExAcquireFastMutex(piVar3 + 0x18);
        piVar18 = piVar3 + 0x26;
        piVar14 = *(int **)piVar18;
        if (piVar14 != piVar18) {
          do {
            piVar15 = piVar14 + -0x26;
            if ((*(longlong *)(piVar14 + 4) == *(longlong *)(piVar11 + 1)) &&
               (*(longlong *)(piVar14 + 6) == *(longlong *)(piVar11 + 3))) break;
            piVar14 = *(int **)piVar14;
            piVar15 = (int *)0x0;
          } while (piVar14 != piVar18);
          if (piVar15 != (int *)0x0) {
            uVar12 = RamdiskQueryRamdisk(param_2,(longlong)piVar15);
            lVar16 = *(longlong *)(param_2 + 0x38);
            uVar17 = (ulonglong)uVar12;
            goto LAB_14000a255;
          }
        }
        goto LAB_14000a5ca;
      }
LAB_14000a0a6:
      uVar17 = 0xc000000d;
    }
    else if (iVar2 == 0x2d1400) {
LAB_14000a532:
      uVar17 = RamdiskQueryProperty(param_1,param_2);
      return uVar17 & 0xffffffff;
    }
  }
  else if (*piVar3 == 1) {
    uVar12 = *(uint *)(lVar4 + 0x18);
    if (uVar12 < 0x240009) {
      if (uVar12 == 0x240008) {
        KeEnterCriticalRegion();
        ExAcquireFastMutex(piVar3 + 0x18);
        uVar12 = RamdiskQueryRamdisk(param_2,(longlong)piVar3);
        lVar16 = *(longlong *)(param_2 + 0x38);
        uVar17 = (ulonglong)uVar12;
        goto LAB_14000a255;
      }
      if (uVar12 < 0x70c01) {
        if (uVar12 != 0x70c00) {
          if (uVar12 == 0x24000) {
            if (*(uint *)(lVar4 + 8) < 0x324) goto LAB_14000a103;
            _Dst = *(void **)(param_2 + 0x18);
            memset(_Dst,0,0x324);
            uVar17 = 0;
            *(undefined2 *)((longlong)_Dst + 1) = 0x112;
            lVar16 = 0x14;
            *(undefined1 *)((longlong)_Dst + 3) = 1;
            *(undefined2 *)((longlong)_Dst + 5) = 0x114;
            goto LAB_14000a680;
          }
          if (uVar12 != 0x2404c) {
            if (uVar12 == 0x24800) goto LAB_14000a0bc;
            if (uVar12 != 0x70000) {
              if (uVar12 != 0x70014) {
                if (uVar12 == 0x70024) {
                  uVar17 = (ulonglong)(-(uint)((piVar3[0x38] & 1U) != 0) & 0xc00000a2);
                }
                goto LAB_14000a680;
              }
              if (0xf < *(uint *)(lVar4 + 0x10)) {
                uVar12 = (uint)(*(ulonglong **)(param_2 + 0x18))[1];
                if (uVar12 == 0) goto LAB_14000a0bc;
                uVar5 = **(ulonglong **)(param_2 + 0x18);
                uVar17 = uVar12 + uVar5;
                if ((uVar5 <= uVar17) && (((uVar12 | uVar5) & (ulonglong)(piVar3[0x5f] - 1)) == 0))
                {
                  uVar17 = (ulonglong)(-(uint)(*(ulonglong *)(piVar3 + 0x3a) < uVar17) & 0xc0000015)
                  ;
                  goto LAB_14000a680;
                }
              }
              goto LAB_14000a0a6;
            }
          }
        }
LAB_14000a2fa:
        if (0x17 < *(uint *)(lVar4 + 8)) {
          uVar17 = 0;
          puVar7 = *(ulonglong **)(param_2 + 0x18);
          lVar16 = 0x18;
          *(uint *)(puVar7 + 1) = ((piVar3[0x38] & 2U) != 0) + 0xb;
          *puVar7 = (ulonglong)(uint)piVar3[0x61];
          *(int *)((longlong)puVar7 + 0xc) = piVar3[0x62];
          *(int *)(puVar7 + 2) = piVar3[0x60];
          *(int *)((longlong)puVar7 + 0x14) = piVar3[0x5f];
          goto LAB_14000a680;
        }
      }
      else if (uVar12 == 0x74004) {
        if (0x1f < *(uint *)(lVar4 + 8)) {
          if (2 < (uint)piVar3[0x36]) {
            uVar13 = RamdiskGetPartitionInfo(param_2,(longlong)piVar3);
            uVar12 = (uint)uVar13;
            goto LAB_14000a189;
          }
LAB_14000a673:
          uVar13 = SendIrpToThread(param_1,param_2);
          uVar12 = (uint)uVar13;
LAB_14000a67e:
          uVar17 = (ulonglong)uVar12;
          goto LAB_14000a680;
        }
      }
      else if (uVar12 == 0x7400c) {
        if (0x27 < *(uint *)(lVar4 + 8)) {
          if ((uint)piVar3[0x36] < 3) goto LAB_14000a673;
          uVar13 = RamdiskGetDriveLayout(param_2,(longlong)piVar3);
          uVar12 = (uint)uVar13;
LAB_14000a189:
          lVar16 = *(longlong *)(param_2 + 0x38);
          goto LAB_14000a67e;
        }
      }
      else if (uVar12 == 0x7405c) {
        if (7 < *(uint *)(lVar4 + 8)) {
          **(longlong **)(param_2 + 0x18) =
               (ulonglong)(uint)piVar3[0x62] * (ulonglong)(uint)piVar3[0x61] *
               (ulonglong)(uint)piVar3[0x60] * (ulonglong)(uint)piVar3[0x5f];
          goto LAB_14000a1cb;
        }
      }
      else {
        if (uVar12 == 0x74800) goto LAB_14000a0bc;
        if (uVar12 != 0x7c008) goto LAB_14000a680;
        if (*(int *)(lVar4 + 0x10) != 0) {
          if ((uint)piVar3[0x36] < 3) goto LAB_14000a673;
          uVar13 = RamdiskSetPartitionInfo(param_2,(longlong)piVar3);
          uVar12 = (uint)uVar13;
          goto LAB_14000a189;
        }
      }
      goto LAB_14000a0a6;
    }
    if (uVar12 < 0x4d0009) {
      if (uVar12 != 0x4d0008) {
        if (uVar12 != 0x2d0800) {
          if (uVar12 == 0x2d0c00) goto LAB_14000a2fa;
          if (uVar12 == 0x2d1400) goto LAB_14000a532;
          if (uVar12 != 0x2d4800) {
            if (uVar12 == 0x4d0000) {
              uVar12 = *(uint *)(lVar4 + 8);
              if (uVar12 < 2) goto LAB_14000a0a6;
              puVar6 = *(undefined2 **)(param_2 + 0x18);
              *puVar6 = 0x10;
              if (uVar12 < 0x12) goto LAB_14000a2d2;
              uVar13 = *(undefined8 *)(piVar3 + 0x2c);
              uVar17 = 0;
              lVar16 = 0x12;
              *(undefined8 *)(puVar6 + 1) = *(undefined8 *)(piVar3 + 0x2a);
              *(undefined8 *)(puVar6 + 5) = uVar13;
            }
            goto LAB_14000a680;
          }
        }
        goto LAB_14000a0bc;
      }
      uVar12 = *(uint *)(lVar4 + 8);
      if (uVar12 < 2) goto LAB_14000a0a6;
      uVar1 = *(ushort *)(piVar3 + 0x14);
      puVar8 = *(ushort **)(param_2 + 0x18);
      *puVar8 = uVar1;
      if (uVar12 < uVar1 + 2) {
LAB_14000a2d2:
        uVar17 = 0x80000005;
        lVar16 = 2;
      }
      else {
        memmove(puVar8 + 1,*(void **)(piVar3 + 0x16),(ulonglong)uVar1);
        uVar17 = 0;
        lVar16 = (ulonglong)*puVar8 + 2;
      }
    }
    else if (uVar12 == 0x4d0018) {
      if (*(uint *)(lVar4 + 8) < 0x10) goto LAB_14000a0a6;
      puVar10 = *(undefined8 **)(param_2 + 0x18);
      uVar17 = 0;
      uVar13 = *(undefined8 *)(piVar3 + 0x2c);
      lVar16 = 0x10;
      *puVar10 = *(undefined8 *)(piVar3 + 0x2a);
      puVar10[1] = uVar13;
    }
    else if (uVar12 == 0x560000) {
      if (piVar3[0x36] == 1) goto LAB_14000a0a6;
      if (*(uint *)(lVar4 + 8) < 0x20) {
LAB_14000a103:
        uVar17 = 0xc0000023;
      }
      else {
        puVar9 = *(undefined4 **)(param_2 + 0x18);
        uVar17 = 0;
        puVar9[2] = 0xffffffff;
        *(undefined8 *)(puVar9 + 4) = 0;
        lVar16 = 0x20;
        *puVar9 = 1;
        *(undefined8 *)(puVar9 + 6) = *(undefined8 *)(piVar3 + 0x3a);
      }
    }
    else if (uVar12 == 0x560034) {
      if (*(uint *)(lVar4 + 0x10) < 0x10) goto LAB_14000a0a6;
      uVar12 = piVar3[0x38];
      uVar17 = **(ulonglong **)(param_2 + 0x18) & 0x4000000000000000;
      if ((uVar12 & 0x10) == 0) {
        if (uVar17 != 0) {
          uVar12 = uVar12 | 0x10;
          uVar13 = 0;
          goto LAB_14000a485;
        }
      }
      else if (uVar17 == 0) {
        uVar12 = uVar12 & 0xffffffef;
        uVar13 = 1;
LAB_14000a485:
        piVar3[0x38] = uVar12;
        IoSetDeviceInterfaceState(piVar3 + 0x10,uVar13);
      }
LAB_14000a0bc:
      uVar17 = 0;
    }
    else if (uVar12 == 0x560038) {
      if (*(uint *)(lVar4 + 8) < 8) goto LAB_14000a0a6;
      puVar7 = *(ulonglong **)(param_2 + 0x18);
      uVar17 = 0;
      *puVar7 = 0;
      if ((piVar3[0x38] & 1U) != 0) {
        uVar17 = 0x1000000000000000;
        *puVar7 = 0x1000000000000000;
      }
      if ((piVar3[0x38] & 4U) != 0) {
        uVar17 = uVar17 | 0x8000000000000000;
        *puVar7 = uVar17;
      }
      if ((piVar3[0x38] & 0x10U) != 0) {
        *puVar7 = uVar17 | 0x4000000000000000;
      }
LAB_14000a1cb:
      uVar17 = 0;
      lVar16 = 8;
    }
    else if (uVar12 == 0x56c008) goto LAB_14000a0bc;
  }
LAB_14000a680:
  IoReleaseRemoveLockEx(piVar3 + 8,param_2,0x20);
  if ((int)uVar17 == 0x103) {
    return uVar17;
  }
LAB_14000a6a0:
  *(int *)(param_2 + 0x30) = (int)uVar17;
  *(longlong *)(param_2 + 0x38) = lVar16;
  IofCompleteRequest(param_2,0);
  return uVar17;
}



===== RamdiskGetDriveLayout @ 14000a6e0 =====

undefined8 RamdiskGetDriveLayout(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 uVar6;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 8) < 0x28) {
    uVar4 = 0xc000000d;
    *(undefined4 *)(param_1 + 0x30) = 0xc000000d;
  }
  else {
    lVar5 = RamdiskMapPages(param_2,0,0x1000,local_res8);
    if (lVar5 != 0) {
      puVar3 = *(undefined4 **)(param_1 + 0x18);
      uVar6 = 1;
      puVar3[1] = 0;
      *puVar3 = 1;
      *(ulonglong *)(puVar3 + 2) = (ulonglong)*(uint *)(param_2 + 0x17c);
      *(ulonglong *)(puVar3 + 4) =
           (ulonglong)*(uint *)(param_2 + 0x188) * (ulonglong)*(uint *)(param_2 + 0x184) *
           (ulonglong)*(uint *)(param_2 + 0x180) * (ulonglong)*(uint *)(param_2 + 0x17c);
      uVar2 = *(undefined4 *)(param_2 + 400);
      puVar3[7] = 0;
      puVar3[6] = uVar2;
      bVar1 = *(byte *)(lVar5 + 0x1c2);
      *(byte *)(puVar3 + 8) = bVar1;
      *(bool *)((longlong)puVar3 + 0x21) = *(int *)(param_2 + 0xd8) == 3;
      if ((bVar1 != 0x2b) &&
         (((0x2d < bVar1 || ((0x3780000058d2U >> ((ulonglong)bVar1 & 0x3f) & 1) == 0)) &&
          (bVar1 != 0xef)))) {
        uVar6 = 0;
      }
      *(undefined1 *)((longlong)puVar3 + 0x22) = uVar6;
      *(undefined1 *)((longlong)puVar3 + 0x23) = 0;
      RamdiskUnmapPages(param_2,lVar5,0,local_res8[0]);
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x28;
      return 0;
    }
    uVar4 = 0xc000009a;
    *(undefined4 *)(param_1 + 0x30) = 0xc000009a;
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  return uVar4;
}



===== RamdiskGetPartitionInfo @ 14000a800 =====

undefined8 RamdiskGetPartitionInfo(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined4 uVar2;
  ulonglong *puVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 8) < 0x20) {
    uVar5 = 0xc000000d;
    *(undefined4 *)(param_1 + 0x30) = 0xc000000d;
  }
  else {
    lVar6 = RamdiskMapPages(param_2,0,0x1000,local_res8);
    if (lVar6 != 0) {
      puVar3 = *(ulonglong **)(param_1 + 0x18);
      *puVar3 = (ulonglong)*(uint *)(param_2 + 0x17c);
      puVar3[1] = (ulonglong)*(uint *)(param_2 + 0x188) * (ulonglong)*(uint *)(param_2 + 0x184) *
                  (ulonglong)*(uint *)(param_2 + 0x180) * (ulonglong)*(uint *)(param_2 + 0x17c);
      uVar2 = *(undefined4 *)(param_2 + 400);
      *(undefined4 *)((longlong)puVar3 + 0x14) = 0;
      *(undefined4 *)(puVar3 + 2) = uVar2;
      bVar1 = *(byte *)(lVar6 + 0x1c2);
      *(byte *)(puVar3 + 3) = bVar1;
      *(bool *)((longlong)puVar3 + 0x19) = *(int *)(param_2 + 0xd8) == 3;
      if ((bVar1 == 0x2b) ||
         (((bVar1 < 0x2e && ((0x3780000058d2U >> ((ulonglong)bVar1 & 0x3f) & 1) != 0)) ||
          (bVar1 == 0xef)))) {
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
      *(undefined1 *)((longlong)puVar3 + 0x1a) = uVar4;
      *(undefined1 *)((longlong)puVar3 + 0x1b) = 0;
      RamdiskUnmapPages(param_2,lVar6,0,local_res8[0]);
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x20;
      return 0;
    }
    uVar5 = 0xc000009a;
    *(undefined4 *)(param_1 + 0x30) = 0xc000009a;
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  return uVar5;
}



===== RamdiskQueryProperty @ 14000a914 =====

ulonglong RamdiskQueryProperty(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *_Dst;
  int *piVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  size_t sVar9;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined8 local_3c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  
  _Dst = *(int **)(param_2 + 0x18);
  piVar5 = *(int **)(param_1 + 0x40);
  uVar8 = 0;
  iVar1 = _Dst[1];
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar6 = (ulonglong)uVar2;
  if (1 < iVar1) {
    uVar8 = 0xc00000ef;
    *(undefined8 *)(param_2 + 0x38) = 0;
    goto LAB_14000ab4c;
  }
  iVar3 = *_Dst;
  iVar4 = *piVar5;
  if (iVar3 == 0) {
    if (iVar4 == 1) {
      if (iVar1 == 1) goto LAB_14000ab4c;
      local_28 = 0;
      local_48 = 0x28;
      local_3c = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      local_40 = (uint)(~(*(byte *)(piVar5 + 0x38) >> 1) & 1) << 0x10;
      uStack_2c = 0;
      local_44 = 0x46;
      memset(_Dst,0,uVar6);
      sVar9 = 0x28;
      if (uVar2 < 0x28) {
        sVar9 = uVar6;
      }
      memmove(_Dst,&local_48,sVar9);
      if (uVar2 < 0x29) {
        *(ulonglong *)(param_2 + 0x38) = uVar6;
        goto LAB_14000ab4c;
      }
      uVar7 = 0x28;
      if (0x3d < uVar2) {
        _Dst[3] = 0x28;
        *(undefined8 *)(_Dst + 10) = 0x666f736f7263694d;
        *(undefined8 *)(_Dst + 0xc) = 0x726f70726f432074;
        _Dst[0xe] = 0x6f697461;
        *(undefined2 *)(_Dst + 0xf) = 0x6e;
        if (uVar2 < 0x46) {
          *(undefined8 *)(param_2 + 0x38) = 0x3e;
        }
        else {
          _Dst[4] = 0x3e;
          *(undefined8 *)((longlong)_Dst + 0x3e) = 0x6b7369446d6152;
          _Dst[5] = 0;
          _Dst[6] = 0;
          _Dst[1] = 0x46;
          *(undefined8 *)(param_2 + 0x38) = 0x46;
        }
        goto LAB_14000ab4c;
      }
      goto LAB_14000aaee;
    }
    uVar8 = 0xc0000010;
  }
  else {
    if (iVar3 == 1) {
      if (iVar4 == 1) {
LAB_14000a9b1:
        IoReleaseRemoveLockEx(piVar5 + 8,param_2,0x20);
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        uVar6 = IofCallDriver(*(undefined8 *)(piVar5 + 6),param_2);
        return uVar6;
      }
      if (iVar1 == 1) goto LAB_14000ab4c;
      uStack_30 = 0xa0000;
      uStack_2c = 0;
      local_40 = -1;
      local_48 = 0x20;
      local_44 = 0x20;
      local_3c = 0x1ffffffff;
      uStack_34 = 0x1000000;
      memset(_Dst,0,uVar6);
      sVar9 = 0x20;
      if (uVar2 < 0x20) {
        sVar9 = uVar6;
      }
      memmove(_Dst,&local_48,sVar9);
      uVar7 = 0x20;
      if (uVar2 < 0x20) {
        uVar7 = uVar6;
      }
LAB_14000aaee:
      *(ulonglong *)(param_2 + 0x38) = uVar7;
      goto LAB_14000ab4c;
    }
    if (iVar3 == 2) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar8 = 0xc00000bb;
      if (iVar4 != 1) {
        uVar8 = 0xc0000010;
      }
      goto LAB_14000ab4c;
    }
    if (iVar4 == 1) goto LAB_14000a9b1;
    uVar8 = 0xc00000ef;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
LAB_14000ab4c:
  IoReleaseRemoveLockEx(piVar5 + 8,param_2,0x20);
  *(uint *)(param_2 + 0x30) = uVar8;
  IofCompleteRequest(param_2,1);
  return (ulonglong)uVar8;
}



===== RamdiskQueryRamdisk @ 14000aba4 =====

undefined4 RamdiskQueryRamdisk(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  
  uVar5 = 0;
  lVar2 = *(longlong *)(param_1 + 0xb8);
  uVar7 = 0x40;
  if (*(uint *)(param_2 + 0xd8) < 3) {
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (*(short *)(param_2 + 0x198 + lVar6 * 2) != 0);
    uVar7 = lVar6 * 2 + 0x40;
  }
  if (*(uint *)(lVar2 + 8) < uVar7) {
    uVar5 = 0xc0000023;
    uVar7 = 0;
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 0x18);
    *puVar3 = 0x40;
    uVar4 = *(undefined8 *)(param_2 + 0xb0);
    *(undefined8 *)(puVar3 + 1) = *(undefined8 *)(param_2 + 0xa8);
    *(undefined8 *)(puVar3 + 3) = uVar4;
    puVar3[5] = *(undefined4 *)(param_2 + 0xd8);
    puVar3[6] = *(undefined4 *)(param_2 + 0xe0);
    *(undefined8 *)(puVar3 + 8) = *(undefined8 *)(param_2 + 0xe8);
    puVar3[10] = *(undefined4 *)(param_2 + 0xf0);
    puVar3[0xc] = *(undefined4 *)(param_2 + 0x124);
    puVar3[0xd] = *(undefined4 *)(param_2 + 0x128);
    iVar1 = *(int *)(param_2 + 0xd8);
    if (iVar1 == 3) {
      *(undefined8 *)(puVar3 + 0xc) = *(undefined8 *)(param_2 + 0x100);
      *(undefined2 *)(puVar3 + 0xe) = *(undefined2 *)(param_2 + 0x120);
    }
    else if (iVar1 == 4) {
      *(undefined8 *)(puVar3 + 0xc) = *(undefined8 *)(param_2 + 0x110);
    }
    else if (iVar1 != 5) {
      RtlStringCbCopyW((short *)(puVar3 + 0xe),(ulonglong)*(uint *)(lVar2 + 8) - 0x38,
                       param_2 + 0x198);
    }
  }
  *(undefined4 *)(param_1 + 0x30) = uVar5;
  *(ulonglong *)(param_1 + 0x38) = uVar7;
  return uVar5;
}



===== RamdiskSetPartitionInfo @ 14000acb4 =====

undefined8 RamdiskSetPartitionInfo(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  if (*(int *)(*(longlong *)(param_1 + 0xb8) + 0x10) == 0) {
    uVar1 = 0xc000000d;
    *(undefined4 *)(param_1 + 0x30) = 0xc000000d;
  }
  else {
    lVar2 = RamdiskMapPages(param_2,0,0x1000,local_res8);
    if (lVar2 == 0) {
      uVar1 = 0xc000009a;
      *(undefined4 *)(param_1 + 0x30) = 0xc000009a;
    }
    else {
      *(undefined1 *)(lVar2 + 0x1c2) = **(undefined1 **)(param_1 + 0x18);
      RamdiskUnmapPages(param_2,lVar2,0,local_res8[0]);
      *(undefined4 *)(param_1 + 0x30) = 0;
      uVar1 = 0;
    }
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  return uVar1;
}



===== GetRamBackedDiskRegistryConfiguration @ 14000ad40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GetRamBackedDiskRegistryConfiguration(void *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 *local_90;
  undefined4 local_88 [2];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined1 local_30 [12];
  uint local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_44 = 0;
  local_78 = 0;
  local_80 = 0;
  local_88[0] = 0;
  local_58 = 0;
  local_60 = 0x30;
  local_70 = 0;
  uStack_68 = 0;
  local_50 = (undefined8 *)&DriverRegistryPath;
  local_40 = 0;
  uStack_38 = 0;
  local_48 = 0x240;
  uVar2 = ZwOpenKey(&local_78,0x20019,&local_60);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  RtlInitUnicodeString(&local_70,L"Parameters");
  local_58 = local_78;
  local_50 = &local_70;
  local_60 = CONCAT44(local_60._4_4_,0x30);
  local_48 = 0x240;
  local_40 = 0;
  uStack_38 = 0;
  uVar1 = ZwOpenKey(&local_80,0x20019,&local_60);
  uVar2 = (ulonglong)uVar1;
  ZwClose(local_78);
  if (-1 < (int)uVar1) {
    memset(param_1,0,0x40);
    *(undefined4 *)((longlong)param_1 + 0x14) = 5;
    *(uint *)((longlong)param_1 + 0x18) = *(uint *)((longlong)param_1 + 0x18) | 2;
    RtlInitUnicodeString(&local_70,L"Enabled");
    local_90 = local_88;
    local_98 = 0x14;
    uVar2 = ZwQueryValueKey(local_80,&local_70,2,local_30);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (local_24 != 0) {
      RtlInitUnicodeString(&local_70,L"DiskSize");
      local_90 = local_88;
      local_98 = 0x14;
      uVar3 = ZwQueryValueKey(local_80,&local_70,2,local_30);
      uVar2 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      *(undefined4 *)((longlong)param_1 + 4) = 0xffffffff;
      *(ulonglong *)((longlong)param_1 + 0x20) = (ulonglong)local_24 << 0x14;
      uVar3 = Feature_AllowLargerRamdiskSize__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar3 != 0) || (*(ulonglong *)((longlong)param_1 + 0x20) < 0x2000000001)) {
        ZwClose(local_80);
        goto LAB_14000af3b;
      }
    }
    uVar2 = 0xc000000d;
  }
LAB_14000af3b:
  return uVar2;
}



===== RamdiskAddDevice @ 14000af70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RamdiskAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *_Dst;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined1 local_a0;
  longlong *local_98;
  longlong local_88 [4];
  int local_68 [16];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  memset(local_68,0,0x40);
  if (RamdiskBusFdo == 0) {
    RtlInitUnicodeString(local_88 + 1,L"\\Device\\Ramdisk");
    local_98 = local_88;
    local_a0 = 0;
    local_a8 = 0x100;
    uVar4 = IoCreateDevice(param_1,0xa8,local_88 + 1);
    if (-1 < (int)uVar4) {
      _Dst = *(undefined4 **)(local_88[0] + 0x40);
      memset(_Dst,0,0xa8);
      *(uint *)(local_88[0] + 0x30) = *(uint *)(local_88[0] + 0x30) | 0x2010;
      *_Dst = 0;
      _Dst[1] = 0;
      *(undefined8 *)(_Dst + 0x1a) = 0;
      _Dst[0x1c] = 0;
      _Dst[0x18] = 1;
      KeInitializeEvent(_Dst + 0x1e,1,0);
      local_a8 = 0x20;
      IoInitializeRemoveLockEx(_Dst + 8,0x646d6152,1,0);
      puVar2 = _Dst + 0x26;
      *(undefined8 *)(_Dst + 4) = param_2;
      *(undefined4 **)(_Dst + 0x28) = puVar2;
      puVar1 = _Dst + 0x10;
      *(undefined4 **)puVar2 = puVar2;
      *(longlong *)(_Dst + 2) = local_88[0];
      uVar3 = IoRegisterDeviceInterface(param_2,&RamdiskBusInterface,0,puVar1);
      uVar4 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        lVar5 = IoAttachDeviceToDeviceStack(local_88[0],param_2);
        *(longlong *)(_Dst + 6) = lVar5;
        if (lVar5 != 0) {
          RamdiskBusFdo = local_88[0];
          uVar4 = GetRamBackedDiskRegistryConfiguration(local_68);
          if (-1 < (int)uVar4) {
            RamdiskCreateRamBackedDisk((ulonglong)_Dst,local_68);
          }
          *(uint *)(local_88[0] + 0x30) = *(uint *)(local_88[0] + 0x30) & 0xffffff7f;
          return 0;
        }
        IoSetDeviceInterfaceState(puVar1,0);
        RtlFreeUnicodeString(puVar1);
        uVar4 = 0xc000000e;
      }
      IoDeleteDevice(local_88[0]);
    }
  }
  else {
    uVar4 = 0xc0000038;
  }
  return uVar4;
}



===== RamdiskDeleteDiskDevice @ 14000b180 =====

undefined8 RamdiskDeleteDiskDevice(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  short sVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  undefined1 *puVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  uVar15 = 0;
  uVar16 = *(ulonglong *)(puVar4[1] + 0x40);
  if (param_2 != 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    if (*(char *)((longlong)puVar4 + 0x122) == '\0') {
      *(uint *)((longlong)puVar4 + 0xdc) = *(uint *)((longlong)puVar4 + 0xdc) & 0xfffffffd;
      goto LAB_14000b1c5;
    }
    if (*(int *)((longlong)puVar4 + 4) < 5) {
      *(undefined4 *)((longlong)puVar4 + 4) = 5;
      IoInvalidateDeviceRelations(*(undefined8 *)(*(longlong *)(puVar4[1] + 0x40) + 0x10),0);
      goto LAB_14000b1c5;
    }
    if (*(int *)((longlong)puVar4 + 4) == 5) goto LAB_14000b1c5;
    KeEnterCriticalRegion();
    ExAcquireFastMutex(uVar16 + 0x60);
  }
  if (6 < *(int *)((longlong)puVar4 + 4)) {
    ExReleaseFastMutex(uVar16 + 0x60);
    KeLeaveCriticalRegion();
LAB_14000b1c5:
    IoReleaseRemoveLockEx(puVar4 + 4,param_2,0x20);
    return 0;
  }
  *(undefined4 *)((longlong)puVar4 + 4) = 7;
  puVar5 = *(undefined8 **)(uVar16 + 0x98);
  do {
    puVar11 = puVar5;
    if (puVar11 == (undefined8 *)(uVar16 + 0x98)) goto LAB_14000b2a3;
    puVar5 = (undefined8 *)*puVar11;
  } while (puVar11 + -0x13 != puVar4);
  if (((undefined8 *)puVar5[1] == puVar11) &&
     (puVar6 = (undefined8 *)puVar11[1], (undefined8 *)*puVar6 == puVar11)) {
    *puVar6 = puVar5;
    puVar5[1] = puVar6;
LAB_14000b2a3:
    ExReleaseFastMutex(uVar16 + 0x60);
    KeLeaveCriticalRegion();
    IoReleaseRemoveLockAndWaitEx(puVar4 + 4,param_2,0x20);
    if (puVar4[9] != 0) {
      if ((*(uint *)(puVar4 + 0x1c) & 0x10) == 0) {
        IoSetDeviceInterfaceState(puVar4 + 8);
      }
      RtlFreeUnicodeString(puVar4 + 8);
    }
    puVar13 = auStack_38;
    uVar16 = 0x646d6152;
    if (puVar4[0x21] == 0) goto LAB_14000b3c4;
    puVar13 = auStack_38;
    if (puVar4[0x26] != 0) {
      plVar2 = puVar4 + 0x27;
      while( true ) {
        puVar13 = auStack_38;
        plVar7 = (longlong *)*plVar2;
        if (plVar7 == plVar2) break;
        if (((longlong *)plVar7[1] != plVar2) ||
           (lVar8 = *plVar7, *(longlong **)(lVar8 + 8) != plVar7)) goto LAB_14000b394;
        *plVar2 = lVar8;
        plVar1 = plVar7 + 2;
        *(longlong **)(lVar8 + 8) = plVar2;
        lVar8 = *plVar1;
        if ((*(longlong **)(lVar8 + 8) != plVar1) ||
           (plVar9 = (longlong *)plVar7[3], (longlong *)*plVar9 != plVar1)) goto LAB_14000b394;
        *plVar9 = lVar8;
        *(longlong **)(lVar8 + 8) = plVar9;
        lVar8 = plVar7[4];
        if (lVar8 != 0) {
          uVar12 = PsGetCurrentProcess();
          MmUnmapViewOfSection(uVar12,lVar8);
        }
      }
      goto LAB_14000b39b;
    }
  }
  else {
LAB_14000b394:
    pcVar10 = (code *)swi(0x29);
    (*pcVar10)(3);
    puVar13 = auStack_30;
LAB_14000b39b:
    uVar12 = puVar4[0x26];
    *(undefined8 *)(puVar13 + -8) = 0x14000b3ac;
    ExFreePoolWithTag(uVar12);
  }
  uVar12 = puVar4[0x21];
  *(undefined8 *)(puVar13 + -8) = 0x14000b3bf;
  ObfDereferenceObject(uVar12);
LAB_14000b3c4:
  sVar3 = *(short *)(puVar4 + 0x24);
  if ((ushort)(sVar3 - 0x41U) < 0x1a) {
    *(undefined8 *)(puVar13 + -8) = 0x14000b3db;
    RamdiskMapDosDriveLetter(sVar3,0);
  }
  if ((*(uint *)(puVar4 + 0x1c) & 8) == 0) {
    *(undefined8 *)(puVar13 + -8) = 0x14000b3f3;
    IoDeleteSymbolicLink(puVar4 + 0x19);
    uVar12 = puVar4[0x1a];
    *(undefined8 *)(puVar13 + -8) = 0x14000b409;
    ExFreePoolWithTag(uVar12,uVar16 & 0xffffffff);
  }
  lVar8 = puVar4[0xb];
  if (lVar8 != 0) {
    *(undefined8 *)(puVar13 + -8) = 0x14000b421;
    ExFreePoolWithTag(lVar8,uVar16 & 0xffffffff);
  }
  lVar8 = puVar4[0x18];
  if (lVar8 != 0) {
    *(undefined8 *)(puVar13 + -8) = 0x14000b43c;
    ExFreePoolWithTag(lVar8,uVar16 & 0xffffffff);
  }
  if (*(int *)(puVar4 + 0x23) != 0) {
    do {
      lVar8 = puVar4[uVar15 + 0x33];
      uVar12 = *(undefined8 *)(lVar8 + 0x18);
      *(undefined8 *)(puVar13 + -8) = 0x14000b461;
      MmUnmapLockedPages(uVar12,lVar8);
      *(undefined8 *)(puVar13 + -8) = 0x14000b470;
      MmFreePagesFromMdl(lVar8);
      *(undefined8 *)(puVar13 + -8) = 0x14000b481;
      ExFreePoolWithTag(lVar8,0);
      uVar14 = (int)uVar15 + 1;
      uVar15 = (ulonglong)uVar14;
    } while (uVar14 < *(uint *)(puVar4 + 0x23));
  }
  *(undefined8 *)(puVar13 + -8) = 0x14000b49a;
  IoDeleteDevice(param_1);
  return 0;
}



===== RamdiskPnp @ 14000b4d0 =====

ulonglong RamdiskPnp(longlong param_1,longlong param_2)

{
  byte bVar1;
  int *piVar2;
  longlong lVar3;
  ushort *puVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined *puVar9;
  ulonglong uVar10;
  bool bVar11;
  int local_res8 [2];
  undefined4 local_res10 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  piVar2 = *(int **)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  if (((4 < piVar2[1]) && (*(char *)(lVar3 + 1) != '\x02')) && (*(char *)(lVar3 + 1) != '\x13')) {
    uVar10 = 0xc000000e;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    goto LAB_14000b6f8;
  }
  uVar10 = IoAcquireRemoveLockEx(piVar2 + 8,param_2,"",1,0x20);
  uVar8 = 0;
  iVar6 = (int)uVar10;
  if (iVar6 < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
LAB_14000b6f5:
    uVar10 = uVar10 & 0xffffffff;
    *(int *)(param_2 + 0x30) = iVar6;
LAB_14000b6f8:
    IofCompleteRequest(param_2,0);
    return uVar10;
  }
  bVar1 = *(byte *)(lVar3 + 1);
  if (bVar1 < 0xb) {
    if (bVar1 == 10) goto LAB_14000b682;
    if (bVar1 != 0) {
      if (bVar1 == 1) {
        piVar2[1] = 3;
        goto LAB_14000b676;
      }
      if (bVar1 == 2) {
        if (*piVar2 == 0) {
          uVar8 = RamdiskRemoveBusDevice(param_1,param_2);
          return (ulonglong)uVar8;
        }
        uVar10 = RamdiskDeleteDiskDevice(param_1,param_2);
        iVar6 = (int)uVar10;
        goto LAB_14000b6f5;
      }
      if (bVar1 == 3) {
        bVar11 = piVar2[1] == 3;
LAB_14000b65f:
        if (!bVar11) goto LAB_14000b667;
        piVar2[1] = 1;
      }
      else if (bVar1 == 4) {
        piVar2[1] = 0;
      }
      else {
        if (bVar1 != 5) {
          if (bVar1 != 6) {
            if (bVar1 != 7) {
              if (bVar1 == 9) {
                if (*piVar2 != 0) {
                  puVar4 = *(ushort **)(*(longlong *)(param_2 + 0xb8) + 8);
                  if ((puVar4[1] == 1) && (0x3f < *puVar4)) {
                    uVar8 = -(uint)(*(int *)(*(longlong *)(param_1 + 0x40) + 0xd8) != 1) & 0x100 |
                            *(uint *)(puVar4 + 2) & 0xffffbef7;
                    *(uint *)(puVar4 + 2) = uVar8;
                    *(uint *)(puVar4 + 2) =
                         ((uint)MarkRamdisksAsRemovable << 4 ^ uVar8) & 0x10 ^ uVar8 | 0x202c0;
                    uVar8 = 0;
                  }
                  else {
                    uVar8 = 0xc0000001;
                  }
                  goto LAB_14000b634;
                }
                goto LAB_14000b98c;
              }
              goto LAB_14000b679;
            }
            uVar10 = RamdiskQueryDeviceRelations(*(int *)(lVar3 + 8),param_1,param_2);
            uVar8 = (uint)uVar10;
            goto LAB_14000b656;
          }
          bVar11 = piVar2[1] == 2;
          goto LAB_14000b65f;
        }
        piVar2[1] = 2;
      }
LAB_14000b676:
      *(undefined4 *)(param_2 + 0x30) = 0;
      goto LAB_14000b679;
    }
    if (*piVar2 == 0) {
      puVar5 = *(undefined8 **)(param_2 + 0xb8);
      puVar5[-9] = *puVar5;
      puVar5[-8] = puVar5[1];
      puVar5[-7] = puVar5[2];
      puVar5[-6] = puVar5[3];
      *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
      *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
      *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
      *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
      puVar5[-3] = puVar5[6];
      *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
      KeInitializeEvent(&local_58,0,0);
      lVar3 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar3 + -0x10) = RamdiskIoCompletionRoutine;
      *(undefined8 **)(lVar3 + -8) = &local_58;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      uVar8 = IofCallDriver(*(undefined8 *)(piVar2 + 6),param_2);
      if (uVar8 == 0x103) {
        KeWaitForSingleObject(&local_58,0,0,0,0);
        uVar8 = *(uint *)(param_2 + 0x30);
      }
      uVar10 = (ulonglong)uVar8;
      if ((int)uVar8 < 0) goto LAB_14000b685;
LAB_14000b889:
      uVar8 = IoSetDeviceInterfaceState(piVar2 + 0x10,1);
      uVar10 = (ulonglong)uVar8;
    }
    else {
      if (*(longlong *)(piVar2 + 0x12) != 0) {
        ExFreePoolWithTag(*(longlong *)(piVar2 + 0x12),0x646d6152);
      }
      puVar9 = &RamdiskDiskInterface;
      if (piVar2[0x36] != 1) {
        puVar9 = &GUID_DEVINTERFACE_VOLUME;
      }
      uVar8 = IoRegisterDeviceInterface(param_1,puVar9,0,piVar2 + 0x10);
      uVar10 = (ulonglong)uVar8;
      if (((piVar2[0x38] & 0x10U) == 0) && (*(longlong *)(piVar2 + 0x12) != 0)) {
        local_res8[0] = 0;
        local_res10[0] = 0;
        uVar8 = IoGetDeviceProperty(param_1,0x12,4,local_res8,local_res10);
        uVar10 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          local_res8[0] = 0;
        }
        if ((local_res8[0] == 0) || (piVar2[0x36] == 3)) goto LAB_14000b889;
      }
    }
    piVar2[1] = 1;
LAB_14000b685:
    *(int *)(param_2 + 0x30) = (int)uVar10;
  }
  else {
    if (bVar1 == 0xb) {
LAB_14000b682:
      uVar10 = (ulonglong)*(uint *)(param_2 + 0x30);
      goto LAB_14000b685;
    }
    if (bVar1 == 0xc) {
      if (*piVar2 == 0) goto LAB_14000b679;
      uVar8 = RamdiskQueryDeviceText(0,param_2);
LAB_14000b656:
      uVar10 = (ulonglong)uVar8;
      goto LAB_14000b699;
    }
    if (bVar1 == 0xd) {
LAB_14000b679:
      if (*piVar2 == 0) {
LAB_14000b98c:
        if (*(longlong *)(piVar2 + 6) != 0) {
          *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
          *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
          uVar8 = IofCallDriver(*(undefined8 *)(piVar2 + 6),param_2);
          goto LAB_14000b656;
        }
      }
      goto LAB_14000b682;
    }
    if (bVar1 == 0x11) {
      iVar6 = *piVar2;
      *(undefined4 *)(param_2 + 0x30) = 0;
      if (iVar6 == 0) goto LAB_14000b679;
      uVar10 = 0;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    else {
      if (bVar1 == 0x13) {
        if (*piVar2 != 0) {
          uVar8 = RamdiskQueryId((longlong)piVar2,param_2);
          goto LAB_14000b656;
        }
        goto LAB_14000b98c;
      }
      if (bVar1 == 0x14) goto LAB_14000b679;
      if (bVar1 == 0x15) {
        puVar7 = (undefined4 *)ExAllocatePool2(0x100,0x18,0x646d6152);
        if (puVar7 != (undefined4 *)0x0) {
          *(undefined8 *)(puVar7 + 4) = 0xf;
          *puVar7 = 0x9d6d66a6;
          puVar7[1] = 0x45630b0c;
          puVar7[2] = 0xe9a07790;
          puVar7[3] = 0xe45a95a7;
          *(undefined4 **)(param_2 + 0x38) = puVar7;
LAB_14000b634:
          *(uint *)(param_2 + 0x30) = uVar8;
          IofCompleteRequest(param_2,0);
          uVar10 = (ulonglong)uVar8;
          goto LAB_14000b699;
        }
        uVar10 = 0xc000009a;
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
        goto LAB_14000b68d;
      }
      if (bVar1 != 0x17) goto LAB_14000b679;
      if (*piVar2 == 0) {
        piVar2[1] = 4;
        goto LAB_14000b676;
      }
LAB_14000b667:
      uVar10 = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
  }
LAB_14000b68d:
  IofCompleteRequest(param_2,0);
LAB_14000b699:
  IoReleaseRemoveLockEx(piVar2 + 8,param_2,0x20);
  return uVar10;
}



===== RamdiskPower @ 14000b9d0 =====

undefined4 RamdiskPower(longlong param_1,longlong param_2)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar2 = *(int **)(param_1 + 0x40);
  if (*piVar2 == 0) {
    PoStartNextPowerIrp(param_2);
    if (piVar2[1] < 5) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar3 = PoCallDriver(*(undefined8 *)(piVar2 + 6),param_2);
      return uVar3;
    }
    uVar3 = 0xc0000056;
  }
  else {
    bVar1 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
    if (((bVar1 != 0) && (bVar1 != 1)) &&
       (((iVar4 = bVar1 - 2, iVar4 == 0 &&
         (iVar4 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10), iVar4 == 0)) || (iVar4 == 1)))) {
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    PoStartNextPowerIrp(param_2);
    uVar3 = *(undefined4 *)(param_2 + 0x30);
  }
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== RamdiskQueryDeviceRelations @ 14000ba8c =====

ulonglong RamdiskQueryDeviceRelations(int param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  ulonglong uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  
  piVar2 = *(int **)(param_2 + 0x40);
  if (*piVar2 == 1) {
    if (param_1 == 4) {
      puVar6 = (undefined4 *)ExAllocatePool2(0x100,0x10,0x646d6152);
      uVar10 = 0;
      if (puVar6 == (undefined4 *)0x0) {
        uVar10 = 0xc000009a;
      }
      else {
        ObfReferenceObject(param_2);
        *puVar6 = 1;
        *(longlong *)(puVar6 + 2) = param_2;
      }
      *(uint *)(param_3 + 0x30) = uVar10;
      *(undefined4 **)(param_3 + 0x38) = puVar6;
    }
    else {
      uVar10 = *(uint *)(param_3 + 0x30);
      *(uint *)(param_3 + 0x30) = uVar10;
    }
    IofCompleteRequest(param_3,0);
    uVar8 = (ulonglong)uVar10;
  }
  else {
    if (param_1 == 0) {
      KeEnterCriticalRegion();
      ExAcquireFastMutex(piVar2 + 0x18);
      puVar3 = *(uint **)(param_3 + 0x38);
      if (puVar3 == (uint *)0x0) {
        uVar10 = 0;
      }
      else {
        uVar10 = *puVar3;
      }
      piVar1 = piVar2 + 0x26;
      iVar9 = 0;
      piVar7 = *(int **)piVar1;
      while (piVar7 != piVar1) {
        piVar11 = piVar7 + -0x25;
        piVar7 = *(int **)piVar7;
        iVar5 = iVar9 + 1;
        if (4 < *piVar11) {
          iVar5 = iVar9;
        }
        iVar9 = iVar5;
      }
      piVar7 = (int *)ExAllocatePool2(0x100,(iVar9 + uVar10) * 8 + 8,0x646d6152);
      if (piVar7 == (int *)0x0) {
        ExReleaseFastMutex(piVar2 + 0x18);
        KeLeaveCriticalRegion();
        *(undefined4 *)(param_3 + 0x30) = 0xc000009a;
        IofCompleteRequest(param_3,0);
        return 0xc000009a;
      }
      if (uVar10 != 0) {
        memmove(piVar7 + 2,puVar3 + 2,(ulonglong)uVar10 << 3);
      }
      *piVar7 = iVar9 + uVar10;
      for (piVar11 = *(int **)piVar1; piVar11 != piVar1; piVar11 = *(int **)piVar11) {
        if (piVar11[-0x25] < 5) {
          ObfReferenceObject(*(undefined8 *)(piVar11 + -0x22));
          uVar8 = (ulonglong)uVar10;
          uVar10 = uVar10 + 1;
          *(undefined8 *)(piVar7 + uVar8 * 2 + 2) = *(undefined8 *)(piVar11 + -0x22);
        }
        else if (piVar11[-0x25] == 5) {
          piVar11[-0x25] = 6;
        }
      }
      ExReleaseFastMutex(piVar2 + 0x18);
      KeLeaveCriticalRegion();
      if (puVar3 != (uint *)0x0) {
        ExFreePoolWithTag(puVar3,0x646d6152);
      }
      *(int **)(param_3 + 0x38) = piVar7;
      *(undefined4 *)(param_3 + 0x30) = 0;
    }
    puVar4 = *(undefined8 **)(param_3 + 0xb8);
    puVar4[-9] = *puVar4;
    puVar4[-8] = puVar4[1];
    puVar4[-7] = puVar4[2];
    puVar4[-6] = puVar4[3];
    *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
    *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
    *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
    *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
    puVar4[-3] = puVar4[6];
    *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
    uVar8 = IofCallDriver(*(undefined8 *)(piVar2 + 6),param_3);
  }
  return uVar8;
}



===== RamdiskQueryDeviceText @ 14000bcfc =====

undefined4 RamdiskQueryDeviceText(undefined8 param_1,longlong param_2)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  
  uVar3 = 0;
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (iVar1 == 0) {
    uVar4 = 0x10;
    psVar2 = (short *)ExAllocatePool2(0x100,0x10,0x646d6152);
    if (psVar2 == (short *)0x0) {
LAB_14000bd81:
      uVar3 = 0xc000009a;
      goto LAB_14000bd9a;
    }
    pwVar5 = L"RamDisk";
  }
  else {
    if (iVar1 != 1) {
      uVar3 = *(undefined4 *)(param_2 + 0x30);
      psVar2 = *(short **)(param_2 + 0x38);
      goto LAB_14000bd9a;
    }
    uVar4 = 0x14;
    psVar2 = (short *)ExAllocatePool2(0x100,0x14,0x646d6152);
    if (psVar2 == (short *)0x0) goto LAB_14000bd81;
    pwVar5 = L"Ramdisk\\0";
  }
  RtlStringCbCopyW(psVar2,uVar4,(longlong)pwVar5);
LAB_14000bd9a:
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  *(short **)(param_2 + 0x38) = psVar2;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== RamdiskQueryId @ 14000bdcc =====

undefined4 RamdiskQueryId(longlong param_1,longlong param_2)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  ulonglong uVar5;
  
  uVar3 = 0;
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (iVar1 == 0) {
    uVar5 = 0x20;
    if (*(int *)(param_1 + 0xd8) != 1) {
      uVar5 = 0x24;
    }
    psVar2 = (short *)ExAllocatePool2(0x100,uVar5,0x646d6152);
    if (psVar2 != (short *)0x0) {
      RtlStringCbCopyW(psVar2,uVar5,0x140005200);
      pwVar4 = L"RamDisk";
      if (*(int *)(param_1 + 0xd8) != 1) {
        pwVar4 = L"RamVolume";
      }
      RtlStringCbCatW(psVar2,uVar5,(longlong)pwVar4);
      goto LAB_14000bfac;
    }
  }
  else if (iVar1 == 1) {
    uVar5 = 0x22;
    if (*(int *)(param_1 + 0xd8) != 1) {
      uVar5 = 0x26;
    }
    psVar2 = (short *)ExAllocatePool2(0x100,uVar5,0x646d6152);
    if (psVar2 != (short *)0x0) {
      RtlStringCbCopyW(psVar2,uVar5,0x140005200);
      pwVar4 = L"RamDisk";
      if (*(int *)(param_1 + 0xd8) != 1) {
        pwVar4 = L"RamVolume";
      }
      RtlStringCbCatW(psVar2,uVar5,(longlong)pwVar4);
      *(undefined2 *)((longlong)psVar2 + (uVar5 - 2)) = 0;
      goto LAB_14000bfac;
    }
  }
  else if (iVar1 == 2) {
    if (*(int *)(param_1 + 0xd8) != 1) {
      psVar2 = (short *)0x0;
      uVar3 = 0xc0000010;
      goto LAB_14000bfac;
    }
    psVar2 = (short *)ExAllocatePool2(0x100,0x12,0x646d6152);
    if (psVar2 != (short *)0x0) {
      RtlStringCbCopyW(psVar2,0x12,0x140005240);
      psVar2[8] = 0;
      goto LAB_14000bfac;
    }
  }
  else {
    if (iVar1 != 3) {
      uVar3 = *(undefined4 *)(param_2 + 0x30);
      psVar2 = *(short **)(param_2 + 0x38);
      goto LAB_14000bfac;
    }
    psVar2 = (short *)ExAllocatePool2(0x100,*(undefined2 *)(param_1 + 0xba),0x646d6152);
    if (psVar2 != (short *)0x0) {
      RtlStringCbCopyW(psVar2,(ulonglong)*(ushort *)(param_1 + 0xba),*(longlong *)(param_1 + 0xc0));
      goto LAB_14000bfac;
    }
  }
  uVar3 = 0xc000009a;
LAB_14000bfac:
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  *(short **)(param_2 + 0x38) = psVar2;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== RamdiskRemoveBusDevice @ 14000bfe8 =====

undefined4 RamdiskRemoveBusDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined4 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  KeEnterCriticalRegion();
  lVar1 = lVar2 + 0x60;
  ExAcquireFastMutex(lVar1);
  while (plVar3 = *(longlong **)(lVar2 + 0x98), plVar3 != (longlong *)(lVar2 + 0x98)) {
    IoAcquireRemoveLockEx(plVar3 + -0xf,0,"",1,0x20);
    RamdiskDeleteDiskDevice(plVar3[-0x11],0);
    KeEnterCriticalRegion();
    ExAcquireFastMutex(lVar1);
  }
  ExReleaseFastMutex(lVar1);
  KeLeaveCriticalRegion();
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  *(undefined4 *)(param_2 + 0x30) = 0;
  uVar4 = IofCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
  *(undefined4 *)(lVar2 + 4) = 5;
  IoReleaseRemoveLockAndWaitEx(lVar2 + 0x20,param_2,0x20);
  if (*(longlong *)(lVar2 + 0x48) != 0) {
    IoSetDeviceInterfaceState(lVar2 + 0x40,0);
    RtlFreeUnicodeString(lVar2 + 0x40);
  }
  if (*(longlong *)(lVar2 + 0x18) != 0) {
    IoDetachDevice();
  }
  RamdiskBusFdo = 0;
  IoDeleteDevice(param_1);
  return uVar4;
}



===== RamdiskCreateClose @ 14000c160 =====

undefined8 RamdiskCreateClose(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 1;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== RamdiskFlushBuffers @ 14000c190 =====

ulonglong RamdiskFlushBuffers(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if ((**(int **)(param_1 + 0x40) == 1) && ((uint)(*(int **)(param_1 + 0x40))[0x36] < 3)) {
    uVar1 = SendIrpToThread(param_1,param_2);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 != 0x103) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(int *)(param_2 + 0x30) = (int)uVar1;
      IofCompleteRequest(param_2,0);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar2 = 0;
  }
  return uVar2;
}



===== RamdiskMapDosDriveLetter @ 14000c208 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RamdiskMapDosDriveLetter(undefined2 param_1,longlong param_2)

{
  uint uVar1;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined2 local_68;
  undefined4 local_66;
  short local_58 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_78 = 0;
  uStack_70 = 0;
  uVar1 = RtlStringCbCopyW(local_58,0x40,0x140005550);
  if (-1 < (int)uVar1) {
    local_66 = 0x3a;
    local_68 = param_1;
    uVar1 = RtlStringCbCatW(local_58,0x40,(longlong)&local_68);
    if (-1 < (int)uVar1) {
      RtlInitUnicodeString(&local_78,local_58);
      if (param_2 == 0) {
        IoDeleteSymbolicLink(&local_78);
      }
      else {
        IoCreateSymbolicLink(&local_78,param_2);
      }
    }
  }
  return;
}



===== RamdiskSystemControl @ 14000c2e0 =====

ulonglong RamdiskSystemControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  int *piVar2;
  ulonglong uVar3;
  
  piVar2 = *(int **)(param_1 + 0x40);
  if (*piVar2 == 0) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(*(undefined8 *)(piVar2 + 6));
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x30);
    IofCompleteRequest(param_2,0);
    uVar3 = (ulonglong)uVar1;
  }
  return uVar3;
}



===== RamdiskUnload @ 14000c340 =====

void RamdiskUnload(void)

{
  if (DAT_1400060d8 != 0) {
    ExFreePoolWithTag(DAT_1400060d8,0x646d6152);
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
  return;
}



===== RamdiskWorkerThread @ 14000c3c0 =====

void RamdiskWorkerThread(longlong param_1,ulonglong param_2)

{
  char cVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  undefined8 uVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong lVar13;
  
  pcVar2 = *(char **)(param_2 + 0xb8);
  IoFreeWorkItem(*(undefined8 *)(param_2 + 0x78));
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar11 = param_2;
  iVar8 = IoAcquireRemoveLockEx(lVar3 + 0x20,param_2,"",1,0x20);
  uVar12 = 0;
  if (iVar8 < 0) {
    *(int *)(param_2 + 0x30) = iVar8;
    uVar9 = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    goto LAB_14000c5fb;
  }
  cVar1 = *pcVar2;
  if ((cVar1 == '\x03') || (cVar1 == '\x04')) {
    uVar9 = RamdiskReadWriteReal(param_2,lVar3);
    iVar8 = (int)uVar9;
  }
  else if (cVar1 == '\t') {
    iVar8 = RamdiskFlushViews(lVar3);
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  else if (cVar1 == '\x0e') {
    iVar8 = *(int *)(pcVar2 + 0x18);
    if (iVar8 == 0x74004) {
      uVar9 = RamdiskGetPartitionInfo(param_2,lVar3);
      iVar8 = (int)uVar9;
    }
    else if (iVar8 == 0x7400c) {
      uVar9 = RamdiskGetDriveLayout(param_2,lVar3);
      iVar8 = (int)uVar9;
    }
    else if (iVar8 == 0x7c008) {
      uVar9 = RamdiskSetPartitionInfo(param_2,lVar3);
      iVar8 = (int)uVar9;
    }
    else {
      if (iVar8 != 0x240000) goto LAB_14000c469;
      iVar8 = RamdiskCreateRamDisk(param_1,param_2,'\0');
    }
  }
  else if (cVar1 == '\x0f') {
    lVar4 = *(longlong *)(pcVar2 + 8);
    lVar5 = *(longlong *)(param_2 + 8);
    iVar8 = *(int *)(pcVar2 + 0x18);
    lVar6 = *(longlong *)(lVar4 + 0x18);
    lVar13 = lVar6;
    if (lVar5 == 0) {
LAB_14000c4d0:
      lVar5 = *(longlong *)(lVar3 + 0x10);
      if (iVar8 == 0x1b0013) {
        lVar7 = *(longlong *)(lVar5 + 0x40);
        uVar10 = (uint)*(byte *)(lVar4 + 2);
        if ((uVar10 == 1) || (uVar10 == 5)) {
          if ((*(uint *)(lVar7 + 0xdc) & 2) == 0) {
            *(undefined4 *)(lVar7 + 4) = 1;
            *(uint *)(lVar7 + 0xdc) = *(uint *)(lVar7 + 0xdc) | 2;
            *(longlong *)(lVar4 + 0x18) = lVar5;
            goto LAB_14000c52f;
          }
          iVar8 = -0x7fffffef;
          *(undefined2 *)(lVar4 + 3) = 0x805;
        }
        else {
          uVar10 = uVar10 - 6;
          uVar11 = (ulonglong)uVar10;
          if ((uVar10 != 0) && (uVar10 != 0x10)) goto LAB_14000c546;
          *(uint *)(lVar7 + 0xdc) = *(uint *)(lVar7 + 0xdc) & 0xfffffffd;
LAB_14000c52f:
          iVar8 = 0;
          *(undefined2 *)(lVar4 + 3) = 1;
        }
      }
      else {
LAB_14000c546:
        iVar8 = RamdiskScsiExecuteIo(lVar5,uVar11,lVar4);
      }
      if (*(longlong *)(lVar4 + 0x18) == lVar13) {
        *(longlong *)(lVar4 + 0x18) = lVar6;
      }
      if (-1 < iVar8) {
        uVar12 = (ulonglong)*(uint *)(lVar4 + 0x10);
      }
    }
    else {
      if ((*(byte *)(lVar5 + 10) & 5) == 0) {
        uVar11 = 0;
        lVar13 = MmMapLockedPagesSpecifyCache(lVar5,0,1,0,0,0x40000010);
      }
      else {
        lVar13 = *(longlong *)(lVar5 + 0x18);
      }
      if (lVar13 != 0) {
        lVar13 = (ulonglong)
                 (uint)(((int)lVar6 - *(int *)(*(longlong *)(param_2 + 8) + 0x2c)) -
                       *(int *)(*(longlong *)(param_2 + 8) + 0x20)) + lVar13;
        *(longlong *)(lVar4 + 0x18) = lVar13;
        goto LAB_14000c4d0;
      }
      *(undefined1 *)(lVar4 + 3) = 2;
      iVar8 = -0x3fffff66;
    }
    *(ulonglong *)(param_2 + 0x38) = uVar12;
  }
  else {
LAB_14000c469:
    iVar8 = -0x3ffffff0;
  }
  IoReleaseRemoveLockEx(lVar3 + 0x20,param_2,0x20);
  uVar9 = 1;
  *(int *)(param_2 + 0x30) = iVar8;
LAB_14000c5fb:
  IofCompleteRequest(param_2,uVar9);
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000c630 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000c66b;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000c6e5:
  while( true ) {
    if (&UNK_140005d4f < ppuVar3) {
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
      if (&UNK_140005d4f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000c66b:
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
      if (&UNK_140005d4f < ppuVar2) goto LAB_14000c6e5;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000c6e5;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000c720 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000c7b8;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000c7b8;
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
LAB_14000c7b8:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000c800 =====

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
              if (&UNK_140005d4f < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000c880 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000c97d;
  }
LAB_14000c986:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000c97d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000c986;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000c94e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000c94e;
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
    if (&UNK_140005d4f < ppuVar3) goto LAB_14000c986;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000c97d;
}



===== BuildInquiryData @ 14000c9ac =====

undefined8 BuildInquiryData(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  byte bVar4;
  size_t sVar5;
  ulonglong local_38;
  void *pvStack_30;
  ulonglong local_28;
  void *pvStack_20;
  ulonglong local_18;
  void *pvStack_10;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar2 = *(undefined8 **)(param_2 + 0x18);
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  local_28 = 0;
  pvStack_20 = (void *)0x0;
  local_18 = 0;
  pvStack_10 = (void *)0x0;
  RtlInitString(&local_38,"Microsoft");
  RtlInitString(&local_28,"Ramdisk");
  RtlInitString(&local_18,"1.0");
  if (*(uint *)(param_2 + 0x10) < 0x24) {
    uVar3 = 0xc0000023;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0;
    sVar5 = 8;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *(undefined4 *)(puVar2 + 4) = 0;
    bVar4 = ~(*(char *)(lVar1 + 0xe0) << 6);
    *(undefined1 *)((longlong)puVar2 + 4) = 0x20;
    *(byte *)((longlong)puVar2 + 1) = (bVar4 ^ *(byte *)((longlong)puVar2 + 1)) & 0x7f ^ bVar4;
    *(byte *)((longlong)puVar2 + 2) = *(byte *)((longlong)puVar2 + 2) & 0xfa | 2;
    *(byte *)((longlong)puVar2 + 3) = *(byte *)((longlong)puVar2 + 3) & 0xf2 | 2;
    if ((ushort)local_38 < 8) {
      sVar5 = local_38 & 0xffff;
    }
    memmove(puVar2 + 1,pvStack_30,sVar5);
    sVar5 = 0x10;
    if ((ushort)local_28 < 0x10) {
      sVar5 = local_28 & 0xffff;
    }
    memmove(puVar2 + 2,pvStack_20,sVar5);
    sVar5 = 4;
    if ((ushort)local_18 < 4) {
      sVar5 = local_18 & 0xffff;
    }
    memmove(puVar2 + 4,pvStack_10,sVar5);
    uVar3 = 0;
  }
  return uVar3;
}



===== BuildModeSenseInfo @ 14000caf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BuildModeSenseInfo(undefined8 param_1,longlong param_2)

{
  undefined8 *_Src;
  size_t _Size;
  undefined1 auStack_48 [32];
  undefined4 local_28 [2];
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28[0] = 0;
  local_20 = 0;
  if (*(char *)(param_2 + 10) == '\x06') {
    if (0x3f < *(byte *)(param_2 + 0x4a)) goto LAB_14000cb49;
    _Size = 4;
    if (*(byte *)(param_2 + 0x4c) < 5) {
      return 0;
    }
    _Src = (undefined8 *)local_28;
    local_28[0] = 3;
  }
  else {
    if (*(char *)(param_2 + 10) != '\n') {
LAB_14000cb49:
      *(undefined1 *)(param_2 + 3) = 6;
      return 0xc0000010;
    }
    _Size = 8;
    if (*(ushort *)(param_2 + 0x4f) < 9) {
      return 0;
    }
    _Src = &local_20;
    local_20 = 6;
  }
  if (*(uint *)(param_2 + 0x10) < (uint)_Size) {
    return 0xc0000023;
  }
  memmove(*(void **)(param_2 + 0x18),_Src,_Size);
  return 0;
}



===== Do10ByteCdbCommand @ 14000cba0 =====

ulonglong Do10ByteCdbCommand(longlong param_1,undefined8 param_2,longlong param_3)

{
  undefined1 *puVar1;
  char cVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  void *pvVar6;
  void *_Dst;
  void *_Src;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  void *pvVar10;
  uint local_res8 [2];
  undefined8 local_res10;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  puVar1 = (undefined1 *)(param_3 + 3);
  local_res8[0] = 0;
  uVar9 = 0;
  *puVar1 = 1;
  *(undefined1 *)(param_3 + 4) = 0;
  cVar2 = *(char *)(param_3 + 0x48);
  if (cVar2 == '%') {
    if (*(uint *)(param_3 + 0x10) < 8) {
      return 0xc0000023;
    }
    uVar8 = *(uint *)(lVar3 + 0x17c);
    puVar4 = *(uint **)(param_3 + 0x18);
    uVar5 = (int)(*(ulonglong *)(lVar3 + 0xe8) / (ulonglong)uVar8) - 1;
    puVar4[1] = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
    *puVar4 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 * 0x1000000;
  }
  else if ((cVar2 == '(') || (cVar2 == '*')) {
    local_res10._0_2_ = CONCAT11(*(undefined1 *)(param_3 + 0x4f),*(undefined1 *)(param_3 + 0x50));
    uVar5 = (uint)(ushort)local_res10 * *(int *)(lVar3 + 0x17c);
    uVar8 = *(uint *)(param_3 + 0x10);
    if (uVar5 <= *(uint *)(param_3 + 0x10)) {
      uVar8 = uVar5;
    }
    local_res10._0_2_ = CONCAT11(*(undefined1 *)(param_3 + 0x4c),*(undefined1 *)(param_3 + 0x4d));
    local_res10._4_4_ = (undefined4)((ulonglong)param_2 >> 0x20);
    local_res10._0_4_ =
         CONCAT13(*(undefined1 *)(param_3 + 0x4a),
                  CONCAT12(*(undefined1 *)(param_3 + 0x4b),(ushort)local_res10));
    if ((*(byte *)(param_3 + 0x49) & 1) == 0) {
      uVar9 = (ulonglong)(uint)(*(int *)(lVar3 + 0x17c) * (int)local_res10);
      if ((uVar9 <= uVar8 + uVar9) && (uVar8 + uVar9 <= *(ulonglong *)(lVar3 + 0xe8))) {
        pvVar10 = *(void **)(param_3 + 0x18);
        while( true ) {
          if (uVar8 == 0) {
            return 0;
          }
          pvVar6 = (void *)RamdiskMapPages(lVar3,uVar9,uVar8,local_res8);
          uVar5 = local_res8[0];
          if (pvVar6 == (void *)0x0) break;
          uVar7 = (ulonglong)local_res8[0];
          if (*(char *)(param_3 + 0x48) == '(') {
            if ((longlong)
                (((ulonglong)*(uint *)(param_3 + 0x10) - (longlong)pvVar10) +
                *(longlong *)(param_3 + 0x18)) < (longlong)uVar7) {
              *(undefined1 *)(param_3 + 3) = 6;
              return 0x80000005;
            }
            _Dst = pvVar10;
            _Src = pvVar6;
          }
          else {
            _Dst = pvVar6;
            _Src = pvVar10;
          }
          memmove(_Dst,_Src,(ulonglong)local_res8[0]);
          RamdiskUnmapPages(lVar3,(longlong)pvVar6,uVar9,uVar5);
          uVar9 = uVar9 + uVar7;
          pvVar10 = (void *)((longlong)pvVar10 + uVar7);
          uVar8 = uVar8 - uVar5;
        }
        *puVar1 = 4;
        return 0xc000009a;
      }
      *(undefined1 *)(param_3 + 3) = 6;
    }
    else {
      *puVar1 = 6;
    }
    uVar9 = 0xc0000010;
  }
  else if (cVar2 != '/') {
    if (cVar2 == 'Z') {
      local_res10 = param_2;
      uVar9 = BuildModeSenseInfo(puVar1,param_3);
      uVar9 = uVar9 & 0xffffffff;
    }
    else {
      uVar9 = 0xc0000010;
      *puVar1 = 6;
    }
  }
  return uVar9;
}



===== RamdiskScsiExecuteIo @ 14000cd88 =====

int RamdiskScsiExecuteIo(longlong param_1,undefined8 param_2,longlong param_3)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  
  cVar1 = *(char *)(param_3 + 2);
  if (cVar1 == '\0') {
    cVar1 = *(char *)(param_3 + 10);
    *(undefined1 *)(param_3 + 3) = 1;
    if (cVar1 != '\x06') {
      if (cVar1 == '\n') {
        uVar5 = Do10ByteCdbCommand(param_1,0,param_3);
        return (int)uVar5;
      }
      if (cVar1 == '\f') {
        *(undefined2 *)(param_3 + 3) = 6;
        return -0x3ffffff0;
      }
      *(undefined1 *)(param_3 + 3) = 6;
      return -0x3ffffff0;
    }
    lVar3 = *(longlong *)(param_1 + 0x40);
    *(undefined1 *)(param_3 + 4) = 0;
    cVar1 = *(char *)(param_3 + 0x48);
    if (cVar1 == '\0') {
      return 0;
    }
    if (cVar1 != '\x03') {
      if (cVar1 == '\x04') {
        return 0;
      }
      if (cVar1 == '\x12') {
        if (0x23 < *(uint *)(param_3 + 0x10)) {
          uVar6 = BuildInquiryData(param_1,param_3);
          return (int)uVar6;
        }
      }
      else {
        if (cVar1 == '\x1a') {
          uVar6 = BuildModeSenseInfo(0,param_3);
          return (int)uVar6;
        }
        if (cVar1 == '\x1e') {
          uVar2 = *(uint *)(lVar3 + 0xdc);
          uVar7 = uVar2 | 1;
          if ((*(byte *)(param_3 + 0x4c) & 1) == 0) {
            uVar7 = uVar2 & 0xfffffffe;
          }
          *(uint *)(lVar3 + 0xdc) = uVar7;
          return 0;
        }
      }
    }
    *(undefined1 *)(param_3 + 3) = 6;
  }
  else {
    if (cVar1 != '\x02') {
      if ((cVar1 == '\a') || (cVar1 == '\b')) {
        iVar4 = RamdiskFlushViews(*(longlong *)(param_1 + 0x40));
        *(undefined1 *)(param_3 + 3) = 1;
        return iVar4;
      }
      return -0x3fffff1b;
    }
    *(undefined1 *)(param_3 + 3) = 6;
  }
  return -0x3ffffff0;
}



===== entry @ 14000d010 =====

void entry(longlong param_1,short *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14000d044 =====

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



===== DriverEntry @ 14000d078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,short *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong local_res10;
  
  local_res10 = 0;
  wil_InitializeFeatureStaging();
  QueryParameters((longlong)param_2);
  _DriverRegistryPath = *param_2;
  _DAT_1400060d2 = *param_2 + 2;
  DAT_1400060d8 = ExAllocatePool2(0x100,_DAT_1400060d2,0x646d6152);
  if (DAT_1400060d8 == 0) {
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    uVar3 = 0xc000009a;
  }
  else {
    RtlCopyUnicodeString(&DriverRegistryPath,param_2);
    *(code **)(param_1 + 0x70) = RamdiskCreateClose;
    *(code **)(param_1 + 0x80) = RamdiskCreateClose;
    *(code **)(param_1 + 0x88) = RamdiskReadWrite;
    *(code **)(param_1 + 0x90) = RamdiskReadWrite;
    *(code **)(param_1 + 0xb8) = RamdiskFlushBuffers;
    *(code **)(param_1 + 0xe0) = RamdiskDeviceControl;
    *(code **)(param_1 + 0x148) = RamdiskPnp;
    *(code **)(param_1 + 0x120) = RamdiskPower;
    *(code **)(param_1 + 0x128) = RamdiskSystemControl;
    *(code **)(param_1 + 0xe8) = RamdiskScsi;
    *(code **)(param_1 + 0x68) = RamdiskUnload;
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = RamdiskAddDevice;
    RamdiskQuerySystemStartOptions();
    if (ReportDetectedDevice == '\0') {
      return 0;
    }
    uVar1 = IoReportDetectedDevice(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0,&local_res10);
    uVar3 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar2 = RamdiskAddDevice(param_1,local_res10);
      uVar3 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        *(uint *)(local_res10 + 0x30) = *(uint *)(local_res10 + 0x30) & 0xffffff7f;
        return 0;
      }
    }
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return uVar3;
}



===== QueryParameters @ 14000d29c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QueryParameters(longlong param_1)

{
  undefined1 auStack_2e8 [32];
  undefined8 local_2c8;
  undefined1 local_2b8 [8];
  undefined4 local_2b0;
  wchar_t *local_2a8;
  undefined8 local_2a0;
  undefined4 local_298;
  undefined8 local_290;
  undefined4 local_288;
  undefined4 local_278;
  wchar_t *local_270;
  undefined1 *local_268;
  undefined4 local_260;
  undefined8 local_258;
  undefined4 local_250;
  undefined4 local_240;
  wchar_t *local_238;
  undefined1 *local_230;
  undefined4 local_228;
  undefined8 local_220;
  undefined4 local_218;
  undefined4 local_208;
  wchar_t *local_200;
  undefined4 *local_1f8;
  undefined4 local_1f0;
  undefined8 local_1e8;
  undefined4 local_1e0;
  undefined4 local_1d0;
  wchar_t *local_1c8;
  undefined4 *local_1c0;
  undefined4 local_1b8;
  undefined8 local_1b0;
  undefined4 local_1a8;
  undefined4 local_198;
  wchar_t *local_190;
  undefined4 *local_188;
  undefined4 local_180;
  undefined8 local_178;
  undefined4 local_170;
  undefined4 local_160;
  wchar_t *local_158;
  undefined4 *local_150;
  undefined4 local_148;
  undefined8 local_140;
  undefined4 local_138;
  undefined4 local_128;
  wchar_t *local_120;
  undefined4 *local_118;
  undefined4 local_110;
  undefined8 local_108;
  undefined4 local_100;
  undefined4 local_f0;
  wchar_t *local_e8;
  undefined4 *local_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_b8;
  wchar_t *local_b0;
  undefined4 *local_a8;
  undefined4 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_2e8;
  MinimumViewCount = 2;
  ReportDetectedDevice = 0;
  MarkRamdisksAsRemovable = 0;
  MaximumViewLength = 0x10000000;
  MaximumPerDiskViewLength = 0x10000000;
  DefaultViewCount = 0x10;
  MaximumViewCount = 0x40;
  MinimumViewLength = 0x10000;
  DefaultViewLength = 0x100000;
  memset(local_2b8,0,0x2a0);
  local_2b0 = 1;
  local_2a0 = 0;
  local_298 = 0;
  local_2a8 = L"Parameters";
  local_270 = L"ReportDetectedDevice";
  local_268 = &ReportDetectedDevice;
  local_238 = L"MarkRamdisksAsRemovable";
  local_230 = &MarkRamdisksAsRemovable;
  local_200 = L"MinimumViewCount";
  local_1f8 = &MinimumViewCount;
  local_1c8 = L"DefaultViewCount";
  local_1c0 = &DefaultViewCount;
  local_190 = L"MaximumViewCount";
  local_188 = &MaximumViewCount;
  local_158 = L"MinimumViewLength";
  local_150 = &MinimumViewLength;
  local_120 = L"DefaultViewLength";
  local_118 = &DefaultViewLength;
  local_290 = 0;
  local_288 = 0;
  local_278 = 0x120;
  local_260 = 0x4000000;
  local_258 = 0;
  local_250 = 0;
  local_240 = 0x120;
  local_228 = 0x4000000;
  local_220 = 0;
  local_218 = 0;
  local_208 = 0x120;
  local_1f0 = 0x4000000;
  local_1e8 = 0;
  local_1e0 = 0;
  local_1d0 = 0x120;
  local_1b8 = 0x4000000;
  local_1b0 = 0;
  local_1a8 = 0;
  local_198 = 0x120;
  local_180 = 0x4000000;
  local_178 = 0;
  local_170 = 0;
  local_160 = 0x120;
  local_148 = 0x4000000;
  local_140 = 0;
  local_138 = 0;
  local_128 = 0x120;
  local_110 = 0x4000000;
  local_108 = 0;
  local_100 = 0;
  local_f0 = 0x120;
  local_e8 = L"MaximumViewLength";
  local_d8 = 0x4000000;
  local_e0 = &MaximumViewLength;
  local_b8 = 0x120;
  local_b0 = L"MaximumPerDiskViewLength";
  local_a0 = 0x4000000;
  local_a8 = &MaximumPerDiskViewLength;
  local_d0 = 0;
  local_c8 = 0;
  local_98 = 0;
  local_90 = 0;
  local_2c8 = 0;
  RtlQueryRegistryValuesEx(0x80000000,*(undefined8 *)(param_1 + 8),local_2b8,0);
  if (MinimumViewCount < 2) {
    MinimumViewCount = 2;
  }
  else if (0x100 < MinimumViewCount) {
    MinimumViewCount = 0x100;
  }
  if (DefaultViewCount < MinimumViewCount) {
    DefaultViewCount = MinimumViewCount;
  }
  else if (0x100 < DefaultViewCount) {
    DefaultViewCount = 0x100;
  }
  if (MaximumViewCount < DefaultViewCount) {
    MaximumViewCount = DefaultViewCount;
  }
  else if (0x100 < MaximumViewCount) {
    MaximumViewCount = 0x100;
  }
  if (MinimumViewLength < 0x10000) {
    MinimumViewLength = 0x10000;
  }
  else if (0x40000000 < MinimumViewLength) {
    MinimumViewLength = 0x40000000;
  }
  if (DefaultViewLength < MinimumViewLength) {
    DefaultViewLength = MinimumViewLength;
  }
  else if (0x40000000 < DefaultViewLength) {
    DefaultViewLength = 0x40000000;
  }
  if (MaximumViewLength < DefaultViewLength) {
    MaximumViewLength = DefaultViewLength;
  }
  else if (0x40000000 < MaximumViewLength) {
    MaximumViewLength = 0x40000000;
  }
  if (MaximumPerDiskViewLength < 0x1000000) {
    MaximumPerDiskViewLength = 0x1000000;
  }
  return;
}



===== wil_InitializeFeatureStaging @ 14000d610 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14000d697;
    }
LAB_14000d6d1:
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
LAB_14000d697:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000d6d1;
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
    goto LAB_14000d6d1;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140005d4f < ppuVar3) goto LAB_14000d6d1;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000d697;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000d724 =====

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
            if (&UNK_140005d4f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14000d80e;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14000d80e;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14000d80e:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140005d4f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


