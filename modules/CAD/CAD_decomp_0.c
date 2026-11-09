
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
  *param_6 = PTR_DAT_1400090d0;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_1400090d0;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_1400090e8,&local_18,0,0,param_5,param_6);
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



===== __GSHandlerCheck @ 1400010d0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400010f4 =====

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



===== __cpu_features_init @ 140001170 =====

/* WARNING: Removing unreachable block (ram,0x0001400011da) */
/* WARNING: Removing unreachable block (ram,0x000140001189) */
/* WARNING: Removing unreachable block (ram,0x00014000117a) */

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



===== Feature_CADBufferValidation__private_IsEnabledDeviceUsageNoInline @ 140001238 =====

ulonglong Feature_CADBufferValidation__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_CADBufferValidation__private_featureState;
  if ((Feature_CADBufferValidation__private_featureState & 0x10) == 0) {
    uVar1 = Feature_CADBufferValidation__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_CADBufferValidation__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_CADBufferValidation__private_IsEnabledFallback @ 140001270 =====

void Feature_CADBufferValidation__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001288 =====

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
LAB_140001491:
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
LAB_140001363:
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
      if (param_3 == 4) goto LAB_140001491;
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
        goto LAB_140001363;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000157c =====

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
      goto LAB_14000163f;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_14000163f;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_14000163f;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_14000163f;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_14000163f;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_14000163f;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_14000163f;
    }
  }
  uVar2 = 0xff;
LAB_14000163f:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x357ee31,&Feature_UxPerfImp_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140001698 =====

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
                     (local_50,&Feature_CADBufferValidation__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x357ee31,param_3,1,&Feature_CADBufferValidation__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x357ee31);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140001784 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
LAB_140001837:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140001865;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140001837;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140001865:
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
     (_g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*_g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (bVar12 && iVar3 == 0) {
    local_88 = CONCAT44(local_88._4_4_,(uVar11 ^ uVar5) & 0x9c1 ^ uVar5);
  }
  return local_88;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400019f0 =====

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
  if ((Feature_CADBufferValidation__private_featureState & 2) != 0) {
    uVar1 = Feature_CADBufferValidation__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_CADBufferValidation__private_featureState;
      if (bVar3) {
        Feature_CADBufferValidation__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_CADBufferValidation__private_featureState;
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



===== wil_details_IsEnabledFallback @ 140001a44 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_CADBufferValidation__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_CADBufferValidation__private_featureState,(ulonglong)param_1,
                             0x140008bc0);
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



===== BatterySetChargerIdCompletionRoutine @ 140001ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BatterySetChargerIdCompletionRoutine(undefined8 param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== CompareUsbPowerSourceUpdateEx @ 140001b10 =====

bool CompareUsbPowerSourceUpdateEx(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = RtlCompareMemory(param_1,param_2,0x38);
  return lVar1 == 0x38;
}



===== DoesDppFileExist @ 140001b3c =====

int DoesDppFileExist(undefined8 param_1)

{
  int iVar1;
  longlong local_res10 [3];
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
  
  local_34 = 0;
  local_1c = 0;
  local_res10[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_58,param_1);
  local_28 = &local_58;
  local_30 = 0;
  local_38 = 0x30;
  local_20 = 0x200;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenFile(local_res10,0x80000000,&local_38,&local_48,1,0);
  if ((-1 < iVar1) && (local_res10[0] != 0)) {
    ZwClose();
  }
  return iVar1;
}



===== McGenControlCallbackV2 @ 140001c00 =====

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



===== McGenEventRegister_EtwRegister @ 140001d10 =====

void McGenEventRegister_EtwRegister(void)

{
  if (MICROSOFT_WINDOWS_POWER_CAD_Context == 0) {
    EtwRegister(&MICROSOFT_WINDOWS_POWER_CAD,McGenControlCallbackV2,
                &MICROSOFT_WINDOWS_POWER_CAD_Context,&MICROSOFT_WINDOWS_POWER_CAD_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140001d50 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (MICROSOFT_WINDOWS_POWER_CAD_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    MICROSOFT_WINDOWS_POWER_CAD_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140001d84 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140009088;
  uVar2 = 0;
  if (DAT_140009088 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140009088;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(MICROSOFT_WINDOWS_POWER_CAD_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0q_EtwWriteTransfer @ 140001de8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&StopCharging,&MICROSOFT_WINDOWS_POWER_CAD,2,local_38);
  return;
}



===== McTemplateK0qhqqqqxqj_EtwWriteTransfer @ 140001e54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qhqqqqxqj_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined8 param_12)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_e8 [32];
  undefined8 local_b8 [2];
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8 = local_res20;
  local_a0 = 4;
  local_98 = &param_5;
  local_90 = 2;
  local_88 = &param_6;
  local_80 = 4;
  local_78 = &param_7;
  local_70 = 4;
  local_68 = &param_8;
  local_58 = &param_9;
  local_48 = &param_10;
  local_38 = &param_11;
  local_28 = param_12;
  local_60 = 4;
  local_50 = 4;
  local_40 = 8;
  local_30 = 4;
  local_20 = 0x10;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&CadPowerSourceUpdateUsb,&MICROSOFT_WINDOWS_POWER_CAD,10,local_b8);
  return;
}



===== McTemplateK0qq_EtwWriteTransfer @ 140001f48 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qq_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_2c = 0;
  local_28 = &uStack0000000000000028;
  local_30 = 4;
  local_1c = 0;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(4,&ChargingSourceChange,&MICROSOFT_WINDOWS_POWER_CAD,3,local_48);
  return;
}



===== McTemplateK0qqqd_EtwWriteTransfer @ 140001fc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_30 = 4;
  local_28 = &param_7;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&BatteryStatusInfo,&MICROSOFT_WINDOWS_POWER_CAD,5,local_68);
  return;
}



===== McTemplateK0qqqq_EtwWriteTransfer @ 140002064 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_30 = 4;
  local_28 = &param_7;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&NotifyChargerStatusResult,&MICROSOFT_WINDOWS_POWER_CAD,5,local_68);
  return;
}



===== McTemplateK0qqqqj_EtwWriteTransfer @ 140002104 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqqj_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = local_res20;
  local_60 = 4;
  local_58 = &param_5;
  local_50 = 4;
  local_48 = &param_6;
  local_40 = 4;
  local_38 = &param_7;
  local_28 = param_8;
  local_30 = 4;
  local_20 = 0x10;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,&MICROSOFT_WINDOWS_POWER_CAD,6,local_78);
  return;
}



===== McTemplateK0qqqqq_EtwWriteTransfer @ 1400021ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqqq_EtwWriteTransfer(undefined8 param_1)

{
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68 = local_88;
  local_88[0] = 0x40;
  local_58 = &uStack0000000000000028;
  local_60 = 4;
  local_48 = &uStack0000000000000030;
  local_50 = 4;
  local_38 = &uStack0000000000000038;
  local_40 = 4;
  local_28 = &uStack0000000000000040;
  local_30 = 4;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&NotifyGenericChargerStatus,&MICROSOFT_WINDOWS_POWER_CAD,6,local_78);
  return;
}



===== McTemplateK0qqqqqqqqqxpj_EtwWriteTransfer @ 140002260 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqqqqqqqxpj_EtwWriteTransfer(undefined8 param_1)

{
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 auStackY_128 [32];
  undefined4 local_f8 [4];
  undefined8 local_e8 [2];
  undefined4 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d8 = local_f8;
  local_f8[0] = 0x40;
  local_c8 = &uStack0000000000000028;
  local_d0 = 4;
  local_b8 = &uStack0000000000000030;
  local_c0 = 4;
  local_a8 = &uStack0000000000000038;
  local_b0 = 4;
  local_98 = &uStack0000000000000040;
  local_88 = &uStack0000000000000048;
  local_78 = &uStack0000000000000050;
  local_68 = &uStack0000000000000058;
  local_58 = &uStack0000000000000060;
  local_48 = &uStack0000000000000068;
  local_38 = &uStack0000000000000070;
  local_a0 = 4;
  local_90 = 4;
  local_80 = 4;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 8;
  local_30 = 8;
  local_20 = 0x10;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&NotifyUsbChargerStatus,&MICROSOFT_WINDOWS_POWER_CAD,0xd,local_e8);
  return;
}



===== McTemplateK0sqd_EtwWriteTransfer @ 14000239c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sqd_EtwWriteTransfer(void)

{
  longlong lVar1;
  char *in_R9;
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  char *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (in_R9 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_R9[lVar1] != '\0');
    local_40 = (int)lVar1 + 1;
  }
  local_3c = 0;
  local_38 = &uStack0000000000000028;
  if (in_R9 == (char *)0x0) {
    in_R9 = "NULL";
  }
  local_28 = &uStack0000000000000030;
  local_30 = 4;
  local_20 = 4;
  local_48 = in_R9;
  McGenEventWrite_EtwWriteTransfer("NULL",&Error,0,4,local_58);
  return;
}



===== McTemplateK0z_EtwWriteTransfer @ 140002440 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0z_EtwWriteTransfer(void)

{
  longlong lVar1;
  wchar_t *in_R9;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (in_R9 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_R9[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (in_R9 == (wchar_t *)0x0) {
    in_R9 = L"NULL";
  }
  local_28 = in_R9;
  McGenEventWrite_EtwWriteTransfer(L"NULL",&Trace,0,2,local_38);
  return;
}



===== ValidateGenericPowerSource @ 1400024cc =====

void ValidateGenericPowerSource(ulonglong *param_1)

{
  *param_1 = (ulonglong)(uint)*param_1;
  return;
}



===== _WPOutputDebugMessage @ 1400024dc =====

void _WPOutputDebugMessage(uint param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  if (((-1 < (int)param_1) && (param_1 < 6)) &&
     ((param_1 == 0 ||
      ((*(uint *)(L"ChargeLimiting" + (longlong)(int)param_1 * 2 + 0xe) & param_2) != 0)))) {
    local_res20 = param_4;
    vDbgPrintEx(0x65,0,param_3,&local_res20);
  }
  return;
}



===== _tlgDefineProvider_annotation__TlgCadTraceHandleProv @ 14000252c =====

void _tlgDefineProvider_annotation__TlgCadTraceHandleProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 140002538 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140002690 =====

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



===== RtlStringLengthWorkerW @ 140002714 =====

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



===== RtlUnicodeStringInitWorker @ 14000275c =====

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



===== FxStubDriverUnloadCommon @ 1400027c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400091d8 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1400091d8 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_14000281d:
      if (ppvVar1 == (void **)0x0) goto LAB_140002873;
      if (ppvVar2 <= ppvVar1) goto LAB_14000288b;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_14000281d;
LAB_140002873:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14000288b:
  WdfVersionUnbind(&DAT_140009490,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1400028c0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1400028f4 =====

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
    _DAT_140009490 = 0x2080000;
    _DAT_140009498 = &DAT_140009280;
    RtlCopyUnicodeString(&DAT_140009490);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_140009490,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_140009488 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_140009490);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1400091d8 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 140002a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_140009488 != (code *)0x0) && (DAT_140009488 != FxStubDriverUnload)) {
    (*DAT_140009488)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140002ab4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140002ad9) */
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
    if ((void **)0x1400091cf < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1400091d8 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 140002c3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140002c59) */
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
    if ((void **)0x1400091ef < ppvVar2) break;
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



===== _guard_check_icall @ 140002d10 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140002d30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002d70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002da0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002dd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 140002e40 =====

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



===== __memset_repmovs @ 140002f80 =====

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



===== __memset_query @ 140003000 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003080 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400031c0 =====

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



===== __memset_spec_plain @ 140003240 =====

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



===== CadDiagTraceContextInfoRundown @ 14000c008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CadDiagTraceContextInfoRundown
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined1 auStackY_118 [32];
  undefined1 local_e8 [4];
  undefined4 local_e4;
  undefined1 local_e0 [4];
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0 [2];
  undefined8 local_c8;
  undefined4 local_c0;
  uint local_bc;
  undefined8 local_b8 [4];
  undefined4 *local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  if (5 < DAT_1400090c8) {
    local_c0 = *(undefined4 *)(param_1 + 8);
    local_98 = &local_c0;
    local_bc = (uint)*(byte *)(param_1 + 0xc);
    local_88 = &local_bc;
    local_c8 = CONCAT44(local_c8._4_4_,(uint)*(byte *)(param_1 + 0x1d8));
    local_78 = &local_c8;
    local_d8 = *(undefined4 *)(param_1 + 0x1c0);
    local_68 = &local_d8;
    local_d4 = *(undefined4 *)(param_1 + 0x1c4);
    local_58 = &local_d4;
    local_d0[0] = *(undefined4 *)(param_1 + 0x10);
    local_48 = local_d0;
    local_dc = *(undefined4 *)(param_1 + 0x14);
    local_38 = &local_dc;
    local_e4 = *(undefined4 *)(param_1 + 0x18);
    local_28 = &local_e4;
    local_90 = 4;
    local_80 = 4;
    local_70 = 4;
    local_60 = 4;
    local_50 = 4;
    local_40 = 4;
    local_30 = 4;
    local_20 = 4;
    lVar1 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1400073ee,param_3,param_4,10,local_b8);
    if (5 < DAT_1400090c8) {
      local_e8[0] = *(undefined1 *)(param_1 + 0x1c);
      local_98 = (undefined4 *)local_e8;
      local_e4 = *(undefined4 *)(param_1 + 0x20);
      local_88 = &local_e4;
      local_dc = *(undefined4 *)(param_1 + 0x24);
      local_78 = (undefined8 *)&local_dc;
      local_90 = 1;
      local_80 = 4;
      local_70 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(lVar1,&DAT_1400070f9,param_3,param_4,5,local_b8);
      if (5 < DAT_1400090c8) {
        local_e4 = *(undefined4 *)(param_1 + 0x34);
        local_98 = &local_e4;
        local_dc = *(undefined4 *)(param_1 + 0x38);
        local_88 = &local_dc;
        local_c8 = *(undefined8 *)(param_1 + 0x40);
        local_78 = &local_c8;
        local_d0[0] = *(undefined4 *)(param_1 + 0x3c);
        local_68 = local_d0;
        local_d4 = *(undefined4 *)(param_1 + 0x30);
        local_58 = &local_d4;
        local_d8 = *(undefined4 *)(param_1 + 0x48);
        local_48 = &local_d8;
        local_38 = (undefined4 *)(param_1 + 0x4c);
        local_90 = 4;
        local_80 = 4;
        local_70 = 8;
        local_60 = 4;
        local_50 = 4;
        local_40 = 4;
        local_30 = 0x10;
        _tlgWriteTransfer_EtwWriteTransfer(lVar1,&DAT_1400071ba,param_3,param_4,9,local_b8);
        if (5 < DAT_1400090c8) {
          local_e4 = *(undefined4 *)(param_1 + 0x6c);
          local_98 = &local_e4;
          local_dc = *(undefined4 *)(param_1 + 0x70);
          local_88 = &local_dc;
          local_c8 = *(undefined8 *)(param_1 + 0x78);
          local_78 = &local_c8;
          local_d0[0] = *(undefined4 *)(param_1 + 0x74);
          local_68 = local_d0;
          local_d4 = *(undefined4 *)(param_1 + 0x68);
          local_58 = &local_d4;
          local_d8 = *(undefined4 *)(param_1 + 0x80);
          local_48 = &local_d8;
          local_38 = (undefined4 *)(param_1 + 0x84);
          local_90 = 4;
          local_80 = 4;
          local_70 = 8;
          local_60 = 4;
          local_50 = 4;
          local_40 = 4;
          local_30 = 0x10;
          _tlgWriteTransfer_EtwWriteTransfer(lVar1,&DAT_14000736c,param_3,param_4,9,local_b8);
          if (5 < DAT_1400090c8) {
            local_98 = (undefined4 *)(param_1 + 0xb0);
            local_90 = 0x10;
            local_e4 = *(undefined4 *)(param_1 + 0x9c);
            local_88 = &local_e4;
            local_e8[0] = *(undefined1 *)(param_1 + 0xa0);
            local_78 = (undefined8 *)local_e8;
            local_80 = 4;
            local_70 = 1;
            _tlgWriteTransfer_EtwWriteTransfer(lVar1,&DAT_140007091,param_3,param_4,5,local_b8);
            if (5 < DAT_1400090c8) {
              local_e8[0] = *(undefined1 *)(param_1 + 0xe8);
              local_98 = (undefined4 *)local_e8;
              local_88 = (uint *)(param_1 + 0xd8);
              local_e4 = *(undefined4 *)(param_1 + 0xc4);
              local_78 = (undefined8 *)&local_e4;
              local_e0[0] = *(undefined1 *)(param_1 + 200);
              local_68 = (undefined4 *)local_e0;
              local_90 = 1;
              local_80 = 0x10;
              local_70 = 4;
              local_60 = 1;
              _tlgWriteTransfer_EtwWriteTransfer(lVar1,&DAT_140007162,param_3,param_4,6,local_b8);
            }
          }
        }
      }
    }
  }
  return;
}



===== CadDiagTraceLoggingControlCallback @ 14000c470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

void CadDiagTraceLoggingControlCallback
               (undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 *param_7)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  code *pcVar4;
  ulonglong *puVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0 [2];
  ulonglong local_d8;
  undefined4 *puStack_d0;
  undefined8 local_c8 [4];
  ulonglong *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  ulonglong local_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  if (param_2 == 2) {
    local_28 = __security_cookie ^ (ulonglong)auStackY_128;
    local_d8 = 0;
    puStack_d0 = (undefined4 *)0x0;
    if (param_7 != (undefined8 *)0x0) {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,*param_7);
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x9b0);
      (*pcVar4)(WdfDriverGlobals);
      CadDiagTraceContextInfoRundown((longlong)param_7,uVar2,pcVar4,param_4);
      if ((param_7[0x28] != 0) && (*(char *)((longlong)param_7 + 0x1bc) != '\0')) {
        CadLockAcquire(param_7 + 0x25);
        CadLockAcquire(param_7 + 0x29);
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_7[0x28],0);
        puVar5 = &local_d8;
        uVar2 = WdfDriverGlobals;
        (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x18));
        if (5 < DAT_1400090c8) {
          local_a8 = &local_90;
          local_a0 = 2;
          local_98 = puStack_d0;
          local_f8 = *(undefined4 *)(lVar3 + 0x20);
          local_88 = &local_f8;
          local_f4 = *(undefined4 *)(lVar3 + 0x24);
          local_78 = &local_f4;
          local_f0._0_4_ = *(undefined4 *)(lVar3 + 0x28);
          local_68 = (undefined4 *)&local_f0;
          local_90 = local_d8 & 0xffff;
          local_80 = 4;
          local_70 = 4;
          local_60 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140007508,puVar5,param_4,7,local_c8);
          if (5 < DAT_1400090c8) {
            local_f0._0_4_ = *(undefined4 *)(param_7 + 0x2c);
            uVar1 = *(uint *)(param_7 + 0x37);
            local_a8 = &local_f0;
            local_f4 = *(undefined4 *)(param_7 + 0x30);
            local_98 = &local_f4;
            local_f8 = *(undefined4 *)(param_7 + 0x32);
            local_88 = &local_f8;
            local_f0._4_4_ = *(undefined4 *)(param_7 + 0x34);
            local_78 = (undefined4 *)((longlong)&local_f0 + 4);
            local_e8 = *(undefined4 *)((longlong)param_7 + 0x1a4);
            local_68 = &local_e8;
            local_e4 = *(undefined4 *)(param_7 + 0x36);
            local_58 = &local_e4;
            local_e0[0] = *(undefined4 *)((longlong)param_7 + 0x1b4);
            local_48 = local_e0;
            local_a0 = 4;
            local_90 = 4;
            local_80 = 4;
            local_70 = 4;
            local_60 = 4;
            local_50 = 4;
            local_40 = 4;
            if (uVar1 == 0) {
              local_38 = "ValueUnavailable";
            }
            else if (uVar1 == 1) {
              local_38 = "False";
            }
            else if (uVar1 == 2) {
              local_38 = "True";
            }
            else {
              local_38 = "MaxValue";
              if (uVar1 != 3) {
                local_38 = "InvalidValue";
              }
            }
            lVar3 = -1;
            do {
              lVar3 = lVar3 + 1;
            } while (local_38[lVar3] != '\0');
            local_30 = (int)lVar3 + 1;
            local_2c = 0;
            _tlgWriteTransfer_EtwWriteTransfer
                      ((ulonglong)uVar1,&DAT_140007239,puVar5,param_4,10,local_c8);
          }
        }
        CadLockRelease(param_7 + 0x29);
        CadLockRelease(param_7 + 0x25);
      }
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,*param_7);
      (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar2);
    }
  }
  return;
}



===== CadEventCreate @ 14000c7e8 =====

int CadEventCreate(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res20;
  ulonglong in_stack_ffffffffffffff78;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 *local_28;
  ulonglong local_20;
  
  local_28 = (undefined8 *)0x0;
  local_20 = local_20 & 0xffffffff00000000;
  local_50 = 0;
  local_res20 = 0;
  lVar3 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  iVar1 = RtlCreateSecurityDescriptor(&local_70,1);
  if (-1 < iVar1) {
    iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
    iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
    iVar1 = iVar1 + iVar2 + 0x20;
    lVar3 = ExAllocatePool2(0x100,iVar1,0x2e444143);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = RtlCreateAcl(lVar3,iVar1,2);
      if (-1 < iVar1) {
        iVar1 = RtlAddAccessAllowedAce
                          (lVar3,2,0x1f0003,*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
        if (-1 < iVar1) {
          iVar1 = RtlAddAccessAllowedAce
                            (lVar3,2,0x1f0003,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108))
          ;
          if (-1 < iVar1) {
            iVar1 = RtlSetDaclSecurityDescriptor(&local_70,1,lVar3,0);
            if (-1 < iVar1) {
              local_28 = &local_70;
              local_48 = CONCAT44(local_48._4_4_,0x30);
              uStack_40 = 0;
              uStack_30 = CONCAT44(uStack_30._4_4_,0x290);
              local_20 = 0;
              local_38 = param_1;
              iVar1 = NtCreateEvent(&local_res20,0x1f0003,&local_48,1,
                                    in_stack_ffffffffffffff78 & 0xffffffffffffff00);
              if (-1 < iVar1) {
                local_78 = 0;
                iVar1 = ObReferenceObjectByHandle(local_res20,0x1f0003,0,0,&local_78,0);
                *param_3 = local_78;
                if (-1 < iVar1) {
                  iVar1 = 0;
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_res20 != 0) {
    NtClose();
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return iVar1;
}



===== CadLockAcquire @ 14000ca48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CadLockAcquire(undefined8 *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*param_1,0);
  param_1[1] = SystemReserved1[0xf];
  return;
}



===== CadLockInitialize @ 14000ca8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CadLockInitialize(undefined8 param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,0,param_1);
  return;
}



===== CadLockRelease @ 14000cabc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CadLockRelease(undefined8 *param_1)

{
  param_1[1] = 0;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*param_1);
  return;
}



===== CadRegReadUlong @ 14000caf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CadRegReadUlong(undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  if (param_3 != (undefined4 *)0x0) {
    *param_4 = *param_3;
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                    (WdfDriverGlobals,0,param_1,0x20019,0,local_res18);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res18[0],param_2,param_4);
  }
  if (local_res18[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return iVar1;
}



===== CadTimerCallback @ 14000cbc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CadTimerCallback(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CAD_TIMER_CONTEXT_TYPE_INFO_140009068);
  if ((puVar1 != (undefined8 *)0x0) && ((code *)puVar1[1] != (code *)0x0)) {
    (*(code *)puVar1[1])(*puVar1);
  }
  return;
}



===== CadTimerInitialize @ 14000cc10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CadTimerInitialize(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 local_68;
  code *pcStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined *local_10;
  
  local_2c = 0;
  local_18 = 0;
  local_10 = PTR__WDF_CAD_TIMER_CONTEXT_TYPE_INFO_140009068;
  local_48 = 0;
  uStack_50 = 0;
  pcStack_60 = CadTimerCallback;
  local_40 = 0x38;
  *param_1 = 0;
  local_3c = 0;
  uStack_34 = 0;
  local_24 = 1;
  local_28 = 2;
  local_68 = 0x28;
  local_58 = 0x100000000;
  local_20 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9f0))(WdfDriverGlobals,&local_68,&local_40,param_1);
  if (-1 < iVar1) {
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*param_1,PTR__WDF_CAD_TIMER_CONTEXT_TYPE_INFO_140009068);
    puVar2[1] = param_3;
    *puVar2 = param_4;
  }
  return iVar1;
}



===== CadWnfExtractData @ 14000cd1c =====

ulonglong CadWnfExtractData(undefined8 param_1,undefined4 param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 local_res10 [6];
  
  uVar1 = *param_4;
  local_res10[0] = param_2;
  uVar3 = ExQueryWnfStateData(param_1,local_res10);
  if (-1 < (int)uVar3) {
    uVar2 = *param_4;
    if (uVar2 == 0) {
      uVar3 = 0xc00002b9;
    }
    else if (uVar2 < uVar1) {
      uVar3 = 0xc0000206;
    }
    else {
      uVar3 = uVar3 & 0xffffffff;
      if (uVar1 < uVar2) {
        uVar3 = 0xc0000023;
      }
    }
  }
  return uVar3;
}



===== CadPsCheckPowerSourcePresence @ 14000cd78 =====

int CadPsCheckPowerSourcePresence
              (longlong param_1,uint param_2,byte *param_3,longlong param_4,longlong param_5,
              uint param_6)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  if (((param_2 != 0) && (param_3 != (byte *)0x0)) && (param_1 <= param_4)) {
    uVar2 = 0;
    lVar1 = param_1;
    if (param_2 != 0) {
      do {
        param_1 = (ulonglong)*(uint *)(param_3 + 4) * 10000000 + lVar1;
        if ((*(uint *)(param_3 + 4) != 0) && (param_4 < param_1)) {
          if ((param_4 < lVar1) || (iVar3 != 0)) {
            if (iVar3 == 2) goto LAB_14000cddd;
          }
          else {
            iVar4 = 2;
            iVar3 = 2;
LAB_14000cddd:
            if (*param_3 == 0xff) {
              return 0;
            }
            if (*param_3 < param_6) {
              return 1;
            }
          }
          if (param_5 + param_4 < param_1) {
            return iVar3;
          }
        }
        uVar2 = uVar2 + 1;
        param_3 = param_3 + 8;
        lVar1 = param_1;
      } while (uVar2 < param_2);
    }
    iVar3 = iVar4;
    if (param_1 <= param_5 + param_4) {
      iVar3 = 0;
    }
  }
  return iVar3;
}



===== CadPsEvaluateBatteryUtilizationHint @ 14000ce2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
CadPsEvaluateBatteryUtilizationHint
          (ulonglong param_1,longlong param_2,byte *param_3,longlong param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  byte *pbVar10;
  ulonglong uVar11;
  longlong lVar12;
  char *pcVar13;
  undefined1 auStackY_108 [32];
  longlong local_d8;
  ulonglong local_d0;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8 [4];
  char *local_98;
  undefined8 local_90;
  longlong *local_88;
  ulonglong local_80;
  int *local_78;
  ulonglong local_70;
  uint *local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50 [2];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar6 = *(uint *)(param_2 + 0x70);
  uVar8 = param_1;
  local_d0 = param_1;
  if (5 < DAT_1400090c8) {
    local_98 = "Evaluate Power Predictions Start";
    local_c8 = CONCAT44(local_c8._4_4_,*(undefined4 *)(param_2 + 0x58));
    local_88 = &local_c8;
    local_d8._0_4_ = *(int *)(param_2 + 0x38);
    local_78 = (int *)&local_d8;
    local_90 = 0x21;
    local_80 = 4;
    local_70 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1400079e3,param_3,param_4,5,local_b8);
  }
  lVar12 = -1;
  pcVar13 = "ValueUnavailable";
  if ((*(uint *)(param_2 + 0x58) < 2) || (*(int *)(param_2 + 0x38) != 3)) {
LAB_14000d2a1:
    uVar6 = 2;
  }
  else if (*(longlong *)(param_2 + 0x28) == 0) {
    if (5 < DAT_1400090c8) {
      local_90 = 0x20;
      local_98 = "Retrieve PowerSourcePredictions";
      local_80 = 0x11;
      local_88 = (longlong *)0x1400056d0;
      _tlgWriteTransfer_EtwWriteTransfer(uVar8,&DAT_140007b04,param_3,param_4,4,local_b8);
    }
    uVar6 = 0;
  }
  else {
    param_3 = (byte *)0x0;
    uVar8 = WdfDriverGlobals;
    plVar5 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x610))();
    if (plVar5 == (longlong *)0x0) {
      if (DAT_1400090c8 < 6) goto LAB_14000d324;
      local_90 = 0x20;
      local_98 = "Retrieve PowerSourcePredictions";
      local_80 = 0x18;
      local_88 = (longlong *)0x1400056e8;
      _tlgWriteTransfer_EtwWriteTransfer(uVar8,&DAT_14000778c,param_3,param_4,4,local_b8);
    }
    else {
      lVar7 = *plVar5;
      local_c0 = _DAT_fffff78000000014;
      local_c8 = (ulonglong)*(uint *)(param_2 + 0x68) * 10000000 + _DAT_fffff78000000014;
      param_4 = _DAT_fffff78000000014;
      if (lVar7 == 0) {
        uVar8 = 0;
        if (5 < DAT_1400090c8) {
          pbVar10 = &DAT_140007a37;
          local_88 = (longlong *)0x1400056d0;
          local_80 = 0x11;
          goto LAB_14000d0d7;
        }
      }
      else {
        param_3 = (byte *)(lVar7 + 0x14);
        uVar8 = *(ulonglong *)(lVar7 + 8);
        iVar2 = CadPsCheckPowerSourcePresence
                          (uVar8,*(uint *)(lVar7 + 0x10),param_3,_DAT_fffff78000000014,local_c8,
                           *(uint *)(param_2 + 0x6c));
        if (5 < DAT_1400090c8) {
          if (iVar2 == 0) {
            local_88 = (longlong *)0x1400052a8;
          }
          else if (iVar2 == 1) {
            local_88 = (longlong *)0x1400052bc;
          }
          else if (iVar2 == 2) {
            local_88 = (longlong *)0x1400052c4;
          }
          else {
            local_88 = (longlong *)0x1400052d0;
            if (iVar2 != 3) {
              local_88 = (longlong *)0x1400052e0;
            }
          }
          lVar7 = -1;
          do {
            lVar7 = lVar7 + 1;
          } while (*(char *)((longlong)local_88 + lVar7) != '\0');
          uVar6 = (int)lVar7 + 1;
          uVar8 = (ulonglong)uVar6;
          pbVar10 = &DAT_14000795c;
          local_80 = (ulonglong)uVar6;
LAB_14000d0d7:
          local_90 = 0x24;
          local_98 = "Retrieve AcSourcePresencePrediction";
          _tlgWriteTransfer_EtwWriteTransfer(uVar8,pbVar10,param_3,param_4,4,local_b8);
        }
      }
      puVar1 = (uint *)plVar5[1];
      uVar11 = 0;
      if (*puVar1 != 0) {
        do {
          iVar2 = (int)uVar11;
          lVar7 = *(longlong *)(puVar1 + uVar11 * 4 + 2);
          if (lVar7 == 0) {
            if (5 < DAT_1400090c8) {
              local_90 = 0x23;
              local_98 = "Retrieve BatteryPresencePrediction";
              local_88 = &local_d8;
              local_80 = 4;
              local_78 = (int *)0x1400056d0;
              local_70 = 0x11;
              local_d8._0_4_ = iVar2;
              _tlgWriteTransfer_EtwWriteTransfer(uVar8,&DAT_140007ac0,param_3,param_4,5,local_b8);
            }
LAB_14000d294:
            uVar6 = 0;
            param_1 = local_d0;
            goto LAB_14000d2a6;
          }
          param_3 = (byte *)(lVar7 + 0x24);
          uVar8 = *(ulonglong *)(lVar7 + 0x18);
          param_4 = local_c0;
          iVar3 = CadPsCheckPowerSourcePresence
                            (uVar8,*(uint *)(lVar7 + 0x20),param_3,local_c0,local_c8,
                             *(uint *)(param_2 + 0x6c));
          if (5 < DAT_1400090c8) {
            local_90 = 0x23;
            local_98 = "Retrieve BatteryPresencePrediction";
            local_88 = &local_d8;
            local_80 = 4;
            if (iVar3 == 0) {
              local_78 = (int *)0x1400052a8;
            }
            else if (iVar3 == 1) {
              local_78 = (int *)0x1400052bc;
            }
            else if (iVar3 == 2) {
              local_78 = (int *)0x1400052c4;
            }
            else {
              local_78 = (int *)0x1400052d0;
              if (iVar3 != 3) {
                local_78 = (int *)0x1400052e0;
              }
            }
            lVar9 = -1;
            do {
              lVar9 = lVar9 + 1;
            } while (*(char *)((longlong)local_78 + lVar9) != '\0');
            uVar6 = (int)lVar9 + 1;
            uVar8 = (ulonglong)uVar6;
            local_68 = local_50;
            local_58 = *(undefined8 *)(lVar7 + 0x10);
            local_50[0] = (uint)*(ushort *)(lVar7 + 8);
            local_70 = (ulonglong)uVar6;
            local_60 = 2;
            local_50[1] = 0;
            local_d8._0_4_ = iVar2;
            _tlgWriteTransfer_EtwWriteTransfer(uVar8,&DAT_1400076b5,param_3,param_4,7,local_b8);
          }
          if (iVar3 == 0) goto LAB_14000d294;
          if (iVar3 == 1) {
            param_1 = local_d0;
            goto LAB_14000d2a1;
          }
          uVar11 = (ulonglong)(iVar2 + 1U);
        } while (iVar2 + 1U < *puVar1);
      }
      uVar6 = 1;
      param_1 = local_d0;
    }
  }
LAB_14000d2a6:
  if (5 < DAT_1400090c8) {
    local_90 = 0x1f;
    local_98 = "Evaluate Power Predictions End";
    if (uVar6 != 0) {
      if (uVar6 == 1) {
        pcVar13 = "False";
      }
      else if (uVar6 == 2) {
        pcVar13 = "True";
      }
      else {
        pcVar13 = "MaxValue";
        if (uVar6 != 3) {
          pcVar13 = "InvalidValue";
        }
      }
    }
    do {
      lVar12 = lVar12 + 1;
    } while (*(char *)((longlong)pcVar13 + lVar12) != '\0');
    local_80 = (ulonglong)((int)lVar12 + 1);
    local_88 = (longlong *)pcVar13;
    _tlgWriteTransfer_EtwWriteTransfer(uVar8,&DAT_140007811,param_3,param_4,4,local_b8);
  }
LAB_14000d324:
  if ((*(uint *)(param_2 + 0x70) != uVar6) &&
     (uVar4 = CadHpmiSendBatteryUtilizationUpdate(param_1,uVar6,param_3,param_4), -1 < (int)uVar4))
  {
    *(uint *)(param_2 + 0x70) = uVar6;
  }
  return 0;
}



===== CadPsEvaluateBatteryUtilizationHintWorker @ 14000d370 =====

void CadPsEvaluateBatteryUtilizationHintWorker
               (ulonglong param_1,undefined8 param_2,byte *param_3,longlong param_4)

{
  undefined8 *puVar1;
  
  CadLockAcquire((undefined8 *)(param_1 + 0x128));
  puVar1 = (undefined8 *)(param_1 + 0x148);
  CadLockAcquire(puVar1);
  if (*(char *)(param_1 + 0x1bc) != '\0') {
    CadPsEvaluateBatteryUtilizationHint(param_1,(longlong)puVar1,param_3,param_4);
  }
  CadLockRelease(puVar1);
  CadLockRelease((undefined8 *)(param_1 + 0x128));
  return;
}



===== CadPsInitialize @ 14000d3d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CadPsInitialize(undefined8 param_1,undefined *param_2,undefined8 param_3,undefined *param_4)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  wchar_t *pwVar4;
  code *pcVar5;
  undefined1 auStackY_c8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_78 [4];
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_90 = 0;
  uStack_88 = 0;
  bVar1 = false;
  pcVar5 = (code *)param_2;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,0);
  if (-1 < iVar2) {
    CadLockAcquire((undefined8 *)param_2);
    bVar1 = true;
    puVar3 = param_2;
    CadPsLoadRegistrySettings((longlong)param_2);
    if (*(int *)(param_2 + 0x18) == 0) {
      if (5 < DAT_1400090c8) {
        local_4c = 0;
        local_58 = "Prediction Services Disabled via Registry";
        local_50 = 0x2a;
        _tlgWriteTransfer_EtwWriteTransfer(puVar3,&DAT_14000792e,pcVar5,param_4,3,local_78);
      }
      iVar2 = 0;
    }
    else {
      pwVar4 = L"\\KernelObjects\\CadRequestPowerSourcePredictions";
      RtlInitUnicodeString(&local_90);
      local_98 = 0;
      pcVar5 = (code *)&local_98;
      iVar2 = CadEventCreate(&local_90,pwVar4,(undefined8 *)pcVar5);
      if (-1 < iVar2) {
        *(undefined8 *)(param_2 + 0x10) = local_98;
        *(undefined4 *)(param_2 + 0x70) = 3;
        param_4 = (undefined *)
                  (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040);
        pcVar5 = CadPsEvaluateBatteryUtilizationHintWorker;
        iVar2 = CadTimerInitialize((undefined8 *)(param_2 + 0x60),param_1,
                                   CadPsEvaluateBatteryUtilizationHintWorker,param_4);
        if (-1 < iVar2) {
          pcVar5 = CadPsRequestPowerSourcePredictionsWorker;
          param_4 = param_2;
          iVar2 = CadTimerInitialize((undefined8 *)(param_2 + 0x20),param_1,
                                     CadPsRequestPowerSourcePredictionsWorker,param_2);
          if (-1 < iVar2) {
            param_4 = (undefined *)0x0;
            pcVar5 = (code *)0x1;
            iVar2 = ExSubscribeWnfStateChange(param_2 + 0x30,&WNF_PO_BATTERY_CHARGE_LEVEL);
            if (-1 < iVar2) {
              param_4 = (undefined *)0x0;
              pcVar5 = (code *)0x1;
              iVar2 = ExSubscribeWnfStateChange(param_2 + 0x40,&WNF_PO_BATTERY_DISCHARGING);
              if (-1 < iVar2) {
                param_4 = (undefined *)0x0;
                pcVar5 = (code *)0x1;
                iVar2 = ExSubscribeWnfStateChange(param_2 + 0x50,&WNF_PO_COMPOSITE_BATTERY);
                if (-1 < iVar2) {
                  pcVar5 = (code *)0xfffffffffa0a1f00;
                  param_2[0x74] = 1;
                  (**(code **)(WdfFunctions_01015 + 0x9f8))
                            (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x20));
                }
              }
            }
          }
        }
      }
    }
  }
  if (5 < DAT_1400090c8) {
    local_4c = 0;
    local_3c = 0;
    local_58 = "Prediction Services Initialize";
    local_48 = &local_98;
    local_50 = 0x1f;
    local_98 = CONCAT44(local_98._4_4_,iVar2);
    local_40 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_140007c08,pcVar5,param_4,4,local_78);
  }
  if (bVar1) {
    CadLockRelease((undefined8 *)param_2);
  }
  return iVar2;
}



===== CadPsIoctlPowerSourcePredictions @ 14000d680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint CadPsIoctlPowerSourcePredictions
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t ***param_4)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  wchar_t ***pppwVar4;
  wchar_t *****pppppwVar5;
  undefined1 auStackY_118 [32];
  longlong local_d8;
  uint local_d0 [2];
  wchar_t *****local_c8;
  wchar_t *****local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  ulonglong local_88;
  undefined8 local_78 [4];
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c8 = (wchar_t *****)0x0;
  local_c0 = (wchar_t *****)0x0;
  local_88 = local_88 & 0xffffffff00000000;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  pppppwVar5 = (wchar_t *****)param_4;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  pppwVar4 = (wchar_t ***)PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2);
  CadLockAcquire((undefined8 *)(lVar3 + 0x148));
  local_d8 = 0;
  if (param_4 < (wchar_t ***)0x80) {
    uVar1 = 0xc0000206;
  }
  else {
    pppppwVar5 = (wchar_t *****)&local_c8;
    pppwVar4 = param_4;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2);
    if (-1 < (int)uVar1) {
      local_88 = 0;
      local_a8 = 0;
      pppppwVar5 = (wchar_t *****)0x2e444143;
      uStack_a0 = 0x100000001;
      pppwVar4 = (wchar_t ***)0x200;
      uStack_b0 = 0;
      local_b8 = 0x38;
      uStack_90 = 0;
      local_98 = uVar2;
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals,&local_b8);
      if (-1 < (int)uVar1) {
        pppwVar4 = (wchar_t ***)0x0;
        pppppwVar5 = local_c8;
        uVar1 = (**(code **)(WdfFunctions_01015 + 0x628))(WdfDriverGlobals,0);
        if (-1 < (int)uVar1) {
          local_c8 = local_c0;
          uVar1 = CadPsValidatePowerSourcePredictions
                            ((wchar_t *)local_c0,(ulonglong)param_4,pppwVar4,pppppwVar5);
          if (-1 < (int)uVar1) {
            local_d8 = *(longlong *)(lVar3 + 0x170);
            *(undefined8 *)(lVar3 + 0x170) = 0;
            pppwVar4 = (wchar_t ***)((ulonglong)(uint)(*(int *)(lVar3 + 0x1a4) * 1000) * -10000);
            (**(code **)(WdfFunctions_01015 + 0x9f8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x1a8));
          }
        }
      }
    }
  }
  if (5 < DAT_1400090c8) {
    local_4c = 0;
    local_3c = 0;
    local_58 = "Process IOCTL_CAD_POWER_SOURCE_PREDICTIONS";
    local_48 = local_d0;
    local_50 = 0x2b;
    local_40 = 4;
    local_d0[0] = uVar1;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_140007868,pppwVar4,pppppwVar5,4,local_78);
  }
  if (local_d8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  CadLockRelease((undefined8 *)(lVar3 + 0x148));
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar1);
  return uVar1;
}



===== CadPsLoadRegistrySettings @ 14000d928 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CadPsLoadRegistrySettings(longlong param_1)

{
  bool bVar1;
  ulonglong uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined1 auStackY_178 [32];
  uint local_148;
  uint local_144;
  uint local_140;
  undefined4 local_13c;
  undefined4 local_138 [2];
  undefined8 local_130;
  wchar_t *local_128;
  undefined8 local_118 [4];
  uint *local_f8;
  undefined8 local_f0;
  uint *local_e8;
  undefined8 local_e0;
  wchar_t *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  wchar_t local_a8 [64];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_178;
  puVar4 = &local_140;
  puVar3 = &local_148;
  builtin_wcsncpy(local_a8,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\CAD",
                  0x3d);
  local_128 = local_a8;
  local_140 = 0;
  local_130 = 0x7a0078;
  local_148 = 0xe10;
  CadRegReadUlong(&local_130,&CAD_PREDICTION_QUERY_INTERVAL_SEC_VALUE,puVar3,puVar4);
  *(uint *)(param_1 + 0x18) = local_148;
  if ((local_140 == 0) || ((uVar2 = (ulonglong)local_148, 899 < local_140 && (local_140 < 0x15181)))
     ) {
    *(uint *)(param_1 + 0x18) = local_140;
    uVar2 = (ulonglong)local_140;
  }
  if (5 < DAT_1400090c8) {
    local_e8 = (uint *)&local_d0;
    local_144 = local_148;
    local_d8 = L"PredicationQueryInterval";
    local_c8 = &local_148;
    local_b8 = &local_144;
    local_f8 = (uint *)0x1400055d0;
    local_f0 = 0xe;
    local_e0 = 2;
    local_d0 = 0x30;
    local_148 = (uint)uVar2;
    local_c0 = 4;
    local_b0 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140007a6d,puVar3,puVar4,7,local_118);
  }
  puVar4 = &local_140;
  local_148 = 10;
  puVar3 = &local_148;
  CadRegReadUlong(&local_130,&CAD_EVALUATE_HPMI_HINT_DELAY_SEC_VALUE,puVar3,puVar4);
  uVar2 = (ulonglong)local_148;
  *(uint *)(param_1 + 0x5c) = local_148;
  if ((2 < local_140) && (local_140 < 0x3d)) {
    *(uint *)(param_1 + 0x5c) = local_140;
    uVar2 = (ulonglong)local_140;
  }
  if (5 < DAT_1400090c8) {
    local_e8 = (uint *)&local_d0;
    local_d8 = L"EvaluateHpmiHintDelay";
    local_c8 = &local_144;
    local_b8 = &local_148;
    local_f8 = (uint *)0x1400055d0;
    local_f0 = 0xe;
    local_e0 = 2;
    local_d0 = 0x2a;
    local_144 = (uint)uVar2;
    local_c0 = 4;
    local_b0 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_1400075d3,puVar3,puVar4,7,local_118);
  }
  puVar4 = &local_140;
  local_148 = 0x2a30;
  puVar3 = &local_148;
  CadRegReadUlong(&local_130,&CAD_FORWARD_LOOKING_BATTERY_PREDICTION_DURATION_SEC_VALUE,puVar3,
                  puVar4);
  uVar2 = (ulonglong)local_148;
  *(uint *)(param_1 + 0x68) = local_148;
  if ((0xe0f < local_140) && (local_140 < 0xa53d)) {
    *(uint *)(param_1 + 0x68) = local_140;
    uVar2 = (ulonglong)local_140;
  }
  if (5 < DAT_1400090c8) {
    local_e8 = (uint *)&local_d0;
    local_d8 = L"ForwardLookingBatteryPredictionDuration";
    local_c8 = &local_144;
    local_b8 = &local_148;
    local_f8 = (uint *)0x1400055d0;
    local_f0 = 0xe;
    local_e0 = 2;
    local_d0 = 0x4e;
    local_144 = (uint)uVar2;
    local_c0 = 4;
    local_b0 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140007580,puVar3,puVar4,7,local_118);
  }
  puVar4 = &local_140;
  local_148 = 0x50;
  puVar3 = &local_148;
  CadRegReadUlong(&local_130,&CAD_MINIMUM_PREDICTION_CONFIDENCE_REQUIRED_VALUE,puVar3,puVar4);
  uVar2 = (ulonglong)local_148;
  *(uint *)(param_1 + 0x6c) = local_148;
  if ((0x32 < local_140) && (local_140 < 0x65)) {
    *(uint *)(param_1 + 0x6c) = local_140;
    uVar2 = (ulonglong)local_140;
  }
  if (5 < DAT_1400090c8) {
    local_e8 = (uint *)&local_d0;
    local_d8 = L"MinimumPredictionConfidenceRequired";
    local_c8 = &local_144;
    local_b8 = &local_148;
    local_f8 = (uint *)0x1400055d0;
    local_f0 = 0xe;
    local_e0 = 2;
    local_d0 = 0x46;
    local_144 = (uint)uVar2;
    local_c0 = 4;
    local_b0 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140007739,puVar3,puVar4,7,local_118);
    if (5 < DAT_1400090c8) {
      if (((_DAT_1400090d8 & 0x400000000000) == 0) ||
         (bVar1 = true, (DAT_1400090e0 & 0x400000000000) != DAT_1400090e0)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_144 = *(uint *)(param_1 + 0x18);
        local_f8 = &local_144;
        local_148 = *(uint *)(param_1 + 0x5c);
        local_e8 = &local_148;
        local_13c = *(undefined4 *)(param_1 + 0x68);
        local_d8 = (wchar_t *)&local_13c;
        local_138[0] = *(undefined4 *)(param_1 + 0x6c);
        local_c8 = local_138;
        local_f0 = 4;
        local_e0 = 4;
        local_d0 = 4;
        local_c0 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140007b3a,puVar3,puVar4,6,local_118);
      }
    }
  }
  return;
}



===== CadPsRequestPowerSourcePredictionsWorker @ 14000ddd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CadPsRequestPowerSourcePredictionsWorker
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [4];
  char *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  CadLockAcquire(param_1);
  if (*(char *)((longlong)param_1 + 0x74) != '\0') {
    uVar1 = param_1[2];
    uVar2 = 0;
    KeSetEvent(uVar1,0);
    if (5 < DAT_1400090c8) {
      local_1c = 0;
      local_28 = "Request Power Predictions";
      local_20 = 0x1a;
      _tlgWriteTransfer_EtwWriteTransfer(uVar1,&DAT_14000770b,uVar2,param_4,3,local_48);
    }
    if (899 < *(uint *)(param_1 + 3)) {
      (**(code **)(WdfFunctions_01015 + 0x9f8))
                (WdfDriverGlobals,param_1[4],(ulonglong)(*(uint *)(param_1 + 3) * 1000) * -10000);
    }
  }
  CadLockRelease(param_1);
  return;
}



===== CadPsUninitialize @ 14000dea4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CadPsUninitialize(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (*(char *)((longlong)param_1 + 0x74) != '\0') {
    CadLockAcquire(param_1);
    *(undefined1 *)((longlong)param_1 + 0x74) = 0;
    if (param_1[2] != 0) {
      ObfDereferenceObject();
    }
    if (param_1[6] != 0) {
      ExUnsubscribeWnfStateChange();
    }
    if (param_1[8] != 0) {
      ExUnsubscribeWnfStateChange();
    }
    if (param_1[10] != 0) {
      ExUnsubscribeWnfStateChange();
    }
    if (param_1[4] != 0) {
      param_3 = 0;
      (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals);
    }
    if (param_1[0xc] != 0) {
      param_3 = 0;
      (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals);
    }
    CadLockRelease(param_1);
  }
  if (5 < DAT_1400090c8) {
    local_2c = 0;
    local_68[0] = 0;
    local_1c = 0;
    local_38 = "Prediction Services Uninitialize";
    local_28 = local_68;
    local_30 = 0x21;
    local_20 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_14000789f,param_3,param_4,4,local_58);
  }
  return 0;
}



===== CadPsValidateBatteryPredictionCollection @ 14000dff8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint CadPsValidateBatteryPredictionCollection
               (wchar_t *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  wchar_t wVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  uint uVar9;
  wchar_t *pwVar10;
  uint uVar11;
  ulonglong uVar12;
  wchar_t *pwVar13;
  longlong lVar14;
  undefined1 auStackY_e8 [32];
  uint local_b8 [2];
  char *local_b0;
  char *local_a8;
  wchar_t *local_a0;
  undefined8 local_98 [4];
  char *local_78;
  int local_70;
  undefined4 local_6c;
  char **local_68;
  undefined8 local_60;
  wchar_t *local_58;
  ulonglong local_50;
  char **local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8 = (char *)0x0;
  uVar12 = 0;
  uVar11 = 0;
  uVar9 = 0;
  pwVar5 = param_1;
  local_a0 = param_2;
  uVar3 = Feature_CADBufferValidation__private_IsEnabledDeviceUsageNoInline();
  lVar14 = -1;
  if (((int)uVar3 == 0) || (param_1 != (wchar_t *)0x0)) {
    local_b8[0] = 0;
    uVar11 = 0;
    if (*(int *)param_1 != 0) {
      do {
        uVar3 = Feature_CADBufferValidation__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar3 != 0) &&
           (pwVar5 = (wchar_t *)((longlong)param_1 + uVar12 * 8 + 0xf), param_2 < pwVar5)) {
LAB_14000e259:
          uVar9 = 0xc0000474;
LAB_14000e25e:
          uVar11 = (uint)uVar12;
          local_78 = local_a8;
          goto LAB_14000e262;
        }
        local_a8 = "Validate SYSMAIN_BATTERY_PREDICTION";
        pwVar8 = param_1 + uVar12 * 4 + 4;
        uVar3 = Feature_CADBufferValidation__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar3 != 0) && (pwVar8 == (wchar_t *)0x0)) {
          uVar9 = 0xc000003e;
          goto LAB_14000e25e;
        }
        pwVar7 = (wchar_t *)((ulonglong)*(uint *)pwVar8 + (longlong)param_1);
        if (((pwVar7 <= param_1) || (param_2 < (wchar_t *)((longlong)pwVar7 + 0x2fU))) ||
           (pwVar7 == (wchar_t *)0x0)) goto LAB_14000e259;
        *(wchar_t **)pwVar8 = pwVar7;
        local_a8 = "Call SYSMAIN_BATTERY_PREDICTION Validate Subroutine";
        uVar9 = 0;
        pwVar5 = (wchar_t *)((ulonglong)*(uint *)(pwVar7 + 0x10) * 8 + 0x2f + (longlong)pwVar7);
        pcVar6 = "Validate Battery Prediction Buffer";
        if (param_2 < pwVar5) {
LAB_14000e143:
          uVar9 = 0xc0000474;
          pwVar8 = L"Battery PNP path not found";
        }
        else {
          pwVar8 = (wchar_t *)((ulonglong)*(uint *)(pwVar7 + 4) + (longlong)pwVar7);
          local_b0 = "Validate Battery PNP Path";
          pwVar10 = (wchar_t *)((longlong)param_2 + -1);
          pcVar6 = "Validate Battery PNP Path";
          if (pwVar8 <= pwVar7) goto LAB_14000e143;
          uVar3 = Feature_CADBufferValidation__private_IsEnabledDeviceUsageNoInline();
          pwVar5 = (wchar_t *)0x0;
          pwVar13 = pwVar8;
          if ((int)uVar3 != 0) {
            for (; pwVar13 <= pwVar10; pwVar13 = pwVar13 + 1) {
              if (*pwVar13 == L'\0') goto LAB_14000e1c4;
            }
LAB_14000e13f:
            pcVar6 = local_b0;
            goto LAB_14000e143;
          }
          wVar1 = *pwVar8;
          while (wVar1 != L'\0') {
            if (pwVar10 < pwVar13) goto LAB_14000e13f;
            pwVar13 = pwVar13 + 1;
            wVar1 = *pwVar13;
          }
          if (pwVar10 < pwVar13) goto LAB_14000e13f;
LAB_14000e1c4:
          if (pwVar8 == (wchar_t *)0x0) goto LAB_14000e13f;
          pwVar5 = pwVar7 + 4;
          RtlInitUnicodeString(pwVar5,pwVar8);
          pcVar6 = "Validate Battery Prediction";
        }
        uVar11 = local_b8[0];
        if (5 < DAT_1400090c8) {
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (pcVar6[lVar4] != '\0');
          local_70 = (int)lVar4 + 1;
          local_68 = (char **)local_b8;
          local_6c = 0;
          local_60 = 4;
          if (pwVar8 == (wchar_t *)0x0) {
            pwVar8 = L"";
            uVar2 = 2;
          }
          else {
            lVar4 = -1;
            do {
              lVar4 = lVar4 + 1;
            } while (pwVar8[lVar4] != L'\0');
            uVar2 = (int)lVar4 * 2 + 2;
          }
          local_48 = &local_b0;
          local_50 = (ulonglong)uVar2;
          local_b0 = (char *)CONCAT44(local_b0._4_4_,uVar9);
          local_40 = 4;
          local_78 = pcVar6;
          local_58 = pwVar8;
          _tlgWriteTransfer_EtwWriteTransfer(pwVar5,&DAT_1400078d6,param_3,param_4,6,local_98);
        }
        uVar12 = (ulonglong)uVar11;
        if ((int)uVar9 < 0) goto LAB_14000e25e;
        uVar11 = uVar11 + 1;
        uVar12 = (ulonglong)uVar11;
        if (*(uint *)param_1 <= uVar11) break;
        param_2 = local_a0;
        local_b8[0] = uVar11;
      } while( true );
    }
    local_78 = "Validate Battery Collection";
  }
  else {
    uVar9 = 0xc000000d;
    local_78 = (char *)0x0;
  }
LAB_14000e262:
  if (5 < DAT_1400090c8) {
    if (local_78 == (char *)0x0) {
      local_78 = "";
      local_70 = 1;
    }
    else {
      do {
        lVar14 = lVar14 + 1;
      } while (local_78[lVar14] != '\0');
      local_70 = (int)lVar14 + 1;
    }
    local_68 = &local_b0;
    local_58 = (wchar_t *)local_b8;
    local_6c = 0;
    local_b0 = (char *)CONCAT44(local_b0._4_4_,uVar11);
    local_60 = 4;
    local_50 = 4;
    local_b8[0] = uVar9;
    _tlgWriteTransfer_EtwWriteTransfer(pwVar5,&DAT_1400077c2,param_3,param_4,5,local_98);
  }
  return uVar9;
}



===== CadPsValidatePowerSourcePredictions @ 14000e320 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint CadPsValidatePowerSourcePredictions
               (wchar_t *param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined1 auStackY_118 [32];
  undefined2 local_e8 [2];
  undefined2 local_e4 [2];
  uint local_e0;
  undefined4 local_dc;
  uint local_d8 [4];
  undefined8 local_c8 [4];
  char *local_a8;
  int local_a0;
  undefined4 local_9c;
  undefined2 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  wchar_t *local_88;
  uint local_80;
  undefined4 local_7c;
  undefined2 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar7 = 0;
  pwVar5 = (wchar_t *)((longlong)param_1 + (param_2 - 1));
  pcVar6 = "Validate PSYSMAIN_AC_PREDICTION";
  uVar2 = Feature_CADBufferValidation__private_IsEnabledDeviceUsageNoInline();
  if (((((int)uVar2 == 0) || ((wchar_t *)((longlong)param_1 + 0xfU) <= pwVar5)) &&
      (pwVar4 = (wchar_t *)((ulonglong)*(uint *)param_1 + (longlong)param_1), param_1 < pwVar4)) &&
     (((wchar_t *)((longlong)pwVar4 + 7U) <= pwVar5 && (pwVar4 != (wchar_t *)0x0)))) {
    *(wchar_t **)param_1 = pwVar4;
    pcVar6 = "Validate PSYSMAIN_BATTERY_PREDICTION_COLLECTION";
    pwVar4 = (wchar_t *)((ulonglong)*(uint *)(param_1 + 4) + (longlong)param_1);
    if ((param_1 < pwVar4) &&
       (((wchar_t *)((longlong)pwVar4 + 7U) <= pwVar5 && (pwVar4 != (wchar_t *)0x0)))) {
      *(wchar_t **)(param_1 + 4) = pwVar4;
      uVar7 = *(undefined4 *)pwVar4;
      uVar1 = CadPsValidateBatteryPredictionCollection(pwVar4,pwVar5,param_3,param_4);
      pcVar6 = "Validate Power Predictions";
      if ((int)uVar1 < 0) {
        pcVar6 = "Call PSYSMAIN_BATTERY_PREDICTION_COLLECTION Validate Subroutine";
      }
      goto LAB_14000e3dc;
    }
  }
  uVar1 = 0xc0000474;
LAB_14000e3dc:
  local_80 = 0xffff;
  local_e0 = (uint)param_2;
  if (param_2 < 0x10000) {
    local_80 = local_e0 & 0xffff;
  }
  if (5 < DAT_1400090c8) {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (pcVar6[lVar3] != '\0');
    local_9c = 0;
    local_a0 = (int)lVar3 + 1;
    local_8c = 0;
    local_7c = 0;
    local_6c = 0;
    local_5c = 0;
    local_4c = 0;
    local_3c = 0;
    local_98 = local_e8;
    local_e8[0] = (undefined2)local_80;
    local_78 = local_e4;
    local_68 = &local_e0;
    local_58 = &local_dc;
    local_48 = local_d8;
    local_90 = 2;
    local_70 = 2;
    local_60 = 4;
    local_50 = 4;
    local_40 = 4;
    local_e4[0] = local_e8[0];
    local_dc = uVar7;
    local_d8[0] = uVar1;
    local_a8 = pcVar6;
    local_88 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_140007626,param_3,param_4,9,local_c8);
  }
  return uVar1;
}



===== CadPsWnfPoCallback @ 14000e4e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CadPsWnfPoCallback(undefined8 *param_1,longlong *param_2,undefined8 *param_3,uint *param_4
                            ,undefined8 param_5,undefined8 *param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  char *pcVar4;
  ulonglong uVar5;
  uint *puVar6;
  undefined4 uVar7;
  undefined1 auStackY_108 [32];
  uint local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined8 local_88 [4];
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  local_d8 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  puVar3 = param_6;
  puVar6 = param_4;
  CadLockAcquire(param_6);
  lVar2 = *param_2;
  pcVar4 = "Unknown";
  uVar5 = 0xc000000d;
  uVar7 = SUB84(param_4,0);
  if (lVar2 == 0x41c6013da3bc8075) {
    puVar6 = &local_d8;
    local_d8 = 4;
    param_3 = &local_d0;
    pcVar4 = "WNF_PO_BATTERY_CHARGE_LEVEL";
    uVar1 = CadWnfExtractData(param_1,uVar7,param_3,puVar6);
    uVar5 = uVar1 & 0xffffffff;
    puVar3 = param_1;
    if (((int)uVar1 < 0) || (*(int *)(param_6 + 7) == (int)local_d0)) goto LAB_14000e643;
    *(int *)(param_6 + 7) = (int)local_d0;
  }
  else {
    if (lVar2 == 0x41c6013da3bc9875) {
      puVar6 = &local_d8;
      local_d8 = 4;
      param_3 = &local_d0;
      pcVar4 = "WNF_PO_BATTERY_DISCHARGING";
      uVar1 = CadWnfExtractData(param_1,uVar7,param_3,puVar6);
      uVar5 = uVar1 & 0xffffffff;
      puVar3 = param_1;
      if ((-1 < (int)uVar1) && (*(int *)(param_6 + 9) != (int)local_d0)) {
        *(int *)(param_6 + 9) = (int)local_d0;
      }
      goto LAB_14000e643;
    }
    if (lVar2 != 0x41c6013da3bc1075) goto LAB_14000e643;
    puVar6 = &local_d8;
    local_d8 = 0x3c;
    param_3 = &local_d0;
    pcVar4 = "WNF_PO_COMPOSITE_BATTERY";
    uVar1 = CadWnfExtractData(param_1,uVar7,param_3,puVar6);
    uVar5 = uVar1 & 0xffffffff;
    puVar3 = param_1;
    if (((int)uVar1 < 0) || (*(int *)(param_6 + 0xb) == local_a0._4_4_)) goto LAB_14000e643;
    *(int *)(param_6 + 0xb) = local_a0._4_4_;
  }
  param_3 = (undefined8 *)((ulonglong)(uint)(*(int *)((longlong)param_6 + 0x5c) * 1000) * -10000);
  puVar3 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,param_6[0xc]);
LAB_14000e643:
  if (5 < DAT_1400090c8) {
    local_5c = 0;
    local_68 = "Process WNF Notification";
    lVar2 = -1;
    local_60 = 0x19;
    do {
      lVar2 = lVar2 + 1;
    } while (pcVar4[lVar2] != '\0');
    local_4c = 0;
    local_3c = 0;
    local_50 = (int)lVar2 + 1;
    local_48 = &local_d4;
    local_40 = 4;
    local_d4 = (int)uVar5;
    local_58 = pcVar4;
    _tlgWriteTransfer_EtwWriteTransfer(puVar3,&DAT_14000799b,param_3,puVar6,5,local_88);
  }
  CadLockRelease(param_6);
  return uVar5;
}



===== CadHpmiGetContextFromCadContext @ 14000e6ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CadHpmiGetContextFromCadContext(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(longlong *)(param_1 + 0x140) != 0) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x610))
                      (WdfDriverGlobals,*(longlong *)(param_1 + 0x140),0);
  }
  return uVar1;
}



===== CadHpmiInitialize @ 14000e728 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CadHpmiInitialize(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  uint *puVar4;
  undefined1 auStackY_148 [32];
  uint local_108;
  uint local_104;
  int local_100 [2];
  undefined8 local_f8;
  wchar_t *local_f0;
  undefined8 local_e8 [4];
  char *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  uint *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  int *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  builtin_wcsncpy(local_98,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\CAD",
                  0x3d);
  local_f0 = local_98;
  local_f8 = 0x7a0078;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040);
  local_108 = 1;
  puVar4 = (uint *)(lVar1 + 0x128);
  local_100[0] = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,0);
  if (-1 < local_100[0]) {
    param_4 = &local_108;
    local_104 = 1;
    puVar4 = &local_104;
    CadRegReadUlong(&local_f8,&CAD_HPMI_SDB_SETTING_VALUE,puVar4,param_4);
    if (1 < local_108) {
      local_108 = local_104;
    }
    *(undefined8 *)(lVar1 + 0x138) = 0;
    if (local_108 != 0) {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x138))(WdfDriverGlobals,param_1);
      param_4 = (uint *)(**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,uVar2);
      puVar4 = (uint *)&GUID_DEVINTERFACE_HPMI;
      local_100[0] = IoRegisterPlugPlayNotification(2);
    }
  }
  iVar3 = local_100[0];
  if (5 < DAT_1400090c8) {
    local_bc = 0;
    local_ac = 0;
    local_9c = 0;
    local_c8 = "HPMI Initialize";
    local_104 = local_108;
    local_b8 = &local_104;
    local_a8 = local_100;
    local_c0 = 0x10;
    local_b0 = 4;
    local_a0 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_140007d54,puVar4,param_4,5,local_e8);
  }
  return iVar3;
}



===== CadHpmiIoctl @ 14000e978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint CadHpmiIoctl(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t ***param_4,
                 int param_5)

{
  bool bVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined *puVar5;
  wchar_t ***pppwVar6;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined8 local_78 [4];
  char *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  bVar1 = false;
  pppwVar6 = param_4;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar5 = PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar3);
  CadLockAcquire((undefined8 *)(lVar4 + 0x128));
  if (*(longlong *)(lVar4 + 0x140) == 0) {
    uVar2 = 0xc00000c0;
    if (5 < DAT_1400090c8) {
      local_4c = 0;
      local_3c = 0;
      local_58 = "Handle CadHpmiIoctl";
      local_48 = local_88;
      local_50 = 0x14;
      local_88[0] = 0xc00000c0;
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_140007d02,puVar5,pppwVar6,4,local_78);
    }
  }
  else if (param_5 == 0x29cc00) {
    bVar1 = true;
    uVar2 = CadPsIoctlPowerSourcePredictions(param_1,param_2,puVar5,param_4);
  }
  else {
    uVar2 = 0xc00000bb;
  }
  CadLockRelease((undefined8 *)(lVar4 + 0x128));
  if (!bVar1) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
  }
  return uVar2;
}



===== CadHpmiPnpNotification @ 14000eaf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CadHpmiPnpNotification
              (longlong param_1,undefined8 *param_2,undefined8 param_3,undefined *param_4)

{
  longlong *plVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined1 auStackY_1a8 [32];
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 *local_138;
  undefined8 uStack_130;
  ulonglong local_128;
  int local_120 [2];
  undefined8 local_118;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined8 local_88 [4];
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_128 = local_128 & 0xffffffff00000000;
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = (undefined8 *)0x0;
  uStack_130 = 0;
  memset(&local_118,0,0x88);
  puVar6 = param_2;
  puVar7 = (undefined8 *)PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040;
  puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  CadLockAcquire(puVar4 + 0x25);
  puVar5 = *(undefined8 **)(param_1 + 0x14);
  plVar1 = (longlong *)(param_1 + 4);
  iVar3 = 0;
  if ((puVar5 == (undefined8 *)0x4c401d20dedae202) &&
     (puVar5 = *(undefined8 **)(param_1 + 0x1c), puVar5 == (undefined8 *)0x4fd519e39718f3a6)) {
    if ((*plVar1 == 0x11d046f0cb3a4004) && (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
      if (puVar4[0x28] == 0) {
        local_128 = 0;
        local_148 = 0;
        param_4 = (undefined *)0x2e444143;
        uStack_140 = 0x100000001;
        puVar7 = (undefined8 *)0x200;
        uStack_150 = 0;
        local_158 = 0x38;
        uStack_130 = 0;
        puVar5 = WdfDriverGlobals;
        local_138 = param_2;
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals,&local_158);
        if (-1 < iVar3) {
          puVar7 = &local_158;
          param_4 = (undefined *)0x8;
          local_128 = 0;
          local_148 = 0;
          uStack_140 = 0x100000001;
          uStack_130 = 0;
          local_138 = (undefined8 *)0x0;
          uStack_150 = 0;
          local_158 = 0x38;
          iVar3 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_2);
          puRam0000000000000000 = puVar4;
          if (-1 < iVar3) {
            puVar2 = *(undefined4 **)(param_1 + 0x28);
            puVar7 = &local_118;
            local_118._0_4_ = 0x88;
            local_118._4_4_ = 2;
            local_e8 = *puVar2;
            uStack_e4 = puVar2[1];
            uStack_e0 = puVar2[2];
            uStack_dc = puVar2[3];
            local_d8 = 0xc0000000;
            local_c8 = 0x40;
            local_cc = 1;
            iVar3 = (**(code **)(WdfFunctions_01015 + 0x540))
                              (WdfDriverGlobals,puRam0000000000000008);
            if (-1 < iVar3) {
              puVar7 = &local_158;
              local_128 = 0;
              local_148 = 0;
              param_4 = (undefined *)0x18;
              uStack_140 = 0x100000001;
              uStack_130 = 0;
              local_138 = (undefined8 *)0x0;
              uStack_150 = 0;
              local_158 = 0x38;
              iVar3 = (**(code **)(WdfFunctions_01015 + 0x9a0))
                                (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28));
              if (-1 < iVar3) {
                local_148 = 0;
                local_128 = 0;
                uStack_150 = 0;
                local_158 = 0x38;
                uStack_130 = 0;
                param_4 = (undefined *)0x10;
                uStack_140 = 0x100000001;
                local_138 = puRam0000000000000008;
                puVar7 = puRam0000000000000008;
                iVar3 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,&local_158);
                if (-1 < iVar3) {
                  puVar4[0x28] = 0;
                  puVar5 = puVar4;
                  iVar3 = CadHpmiQueryCapabilities((longlong)puVar4);
                  if (iVar3 < 0) {
                    puVar5 = WdfDriverGlobals;
                    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,0);
                    puVar4[0x28] = 0;
                  }
                  else if ((uRam0000000000000024 & 1) != 0) {
                    CadHpmiSendBatteryUtilizationUpdate((longlong)puVar4,0,puVar7,param_4);
                    iVar3 = CadPsInitialize(param_2,(undefined *)(puVar4 + 0x29),puVar7,param_4);
                    puVar5 = param_2;
                  }
                  goto LAB_14000ef25;
                }
              }
            }
          }
          puVar5 = WdfDriverGlobals;
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,0);
        }
      }
      else {
        iVar3 = -0x3fffffc8;
      }
    }
    else if ((*plVar1 == 0x11d046f0cb3a4005) && (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)
            ) {
      if (puVar4[0x28] == 0) {
        iVar3 = -0x3ffffd4a;
      }
      else {
        CadPsUninitialize(puVar4 + 0x29,puVar6,puVar7,param_4);
        puVar5 = (undefined8 *)CadHpmiGetContextFromCadContext((longlong)puVar4);
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0;
        puVar5[4] = 0;
        puVar5[5] = 0;
        puVar5 = WdfDriverGlobals;
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,puVar4[0x28]);
        puVar4[0x28] = 0;
      }
    }
  }
  else {
    iVar3 = -0x3ffffff3;
  }
LAB_14000ef25:
  if (5 < DAT_1400090c8) {
    local_5c = 0;
    local_4c = 0;
    local_3c = 0;
    local_68 = "Handle HPMI PNP Notification";
    local_48 = local_120;
    local_60 = 0x1d;
    local_50 = 0x10;
    local_40 = 4;
    local_120[0] = iVar3;
    local_58 = plVar1;
    _tlgWriteTransfer_EtwWriteTransfer(puVar5,&DAT_140007cce,puVar7,param_4,5,local_88);
  }
  CadLockRelease(puVar4 + 0x25);
  return iVar3;
}



===== CadHpmiQueryCapabilities @ 14000efc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CadHpmiQueryCapabilities(longlong param_1)

{
  undefined8 *puVar1;
  bool bVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  int local_d4;
  ulonglong local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98 [4];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_138;
  local_d0 = 0;
  local_ac = 0;
  local_c4 = 0;
  lVar3 = CadHpmiGetContextFromCadContext(param_1);
  local_ac = 0;
  local_a8 = &local_e8;
  local_9c = 0;
  bVar2 = true;
  uVar7 = 0x29c800;
  local_e8 = 1;
  puVar1 = (undefined8 *)(lVar3 + 0x20);
  local_b0 = 1;
  uVar6 = 0;
  local_a0 = 4;
  *puVar1 = 0;
  *(undefined4 *)(lVar3 + 0x28) = 0;
  local_c4 = 0;
  local_b4 = 0;
  local_c8 = 1;
  local_b8 = 0xc;
  uVar4 = WdfDriverGlobals;
  local_c0 = puVar1;
  local_d4 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 8));
  if ((-1 < local_d4) && (local_d0 < 0xc)) {
    local_d4 = -0x3fffff10;
  }
  iVar5 = local_d4;
  if (5 < DAT_1400090c8) {
    if (((_DAT_1400090d8 & 0x400000000000) == 0) ||
       ((DAT_1400090e0 & 0x400000000000) != DAT_1400090e0)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_6c = 0;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_e4 = local_e8;
      local_78 = &local_e4;
      local_e0 = *(undefined4 *)puVar1;
      local_68 = &local_e0;
      local_dc = *(undefined4 *)(lVar3 + 0x28);
      local_58 = &local_dc;
      local_d8 = *(undefined4 *)(lVar3 + 0x24);
      local_48 = &local_d8;
      local_38 = &local_d4;
      local_70 = 4;
      local_60 = 4;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_140007c3f,uVar6,uVar7,7,local_98);
    }
  }
  return iVar5;
}



===== CadHpmiSendBatteryUtilizationUpdate @ 14000f1a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CadHpmiSendBatteryUtilizationUpdate
               (longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 auStackY_e8 [32];
  undefined8 local_98;
  undefined4 local_90;
  uint local_8c [3];
  undefined8 *puStack_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_68 [4];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  char *local_38;
  uint local_30;
  undefined4 local_2c;
  uint *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98 = 0;
  local_78 = 0;
  local_8c[1] = 0;
  local_8c[2] = 0;
  puStack_80 = (undefined8 *)0x0;
  if (param_2 < 3) {
    lVar2 = CadHpmiGetContextFromCadContext(param_1);
    if (lVar2 == 0) {
      local_8c[0] = 0xc00000c0;
    }
    else {
      puStack_80 = &local_98;
      param_4 = 0x29c804;
      local_74 = 0;
      param_3 = 0;
      local_98 = CONCAT44(param_2,1);
      local_8c[1] = 1;
      local_8c[2] = 0;
      local_78 = 8;
      local_8c[0] = (**(code **)(WdfFunctions_01015 + 0x5d0))
                              (WdfDriverGlobals,*(undefined8 *)(lVar2 + 8));
    }
  }
  else {
    local_8c[0] = 0xc000003e;
  }
  uVar3 = local_8c[0];
  if (5 < DAT_1400090c8) {
    if (((_DAT_1400090d8 & 0x400000000000) == 0) ||
       ((DAT_1400090e0 & 0x400000000000) != DAT_1400090e0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_3c = 0;
      local_90 = (undefined4)local_98;
      local_48 = &local_90;
      local_40 = 4;
      if (param_2 == 0) {
        local_38 = "ValueUnavailable";
      }
      else if (param_2 == 1) {
        local_38 = "False";
      }
      else if (param_2 == 2) {
        local_38 = "True";
      }
      else {
        local_38 = "MaxValue";
        if (param_2 != 3) {
          local_38 = "InvalidValue";
        }
      }
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (local_38[lVar2] != '\0');
      local_2c = 0;
      local_30 = (int)lVar2 + 1;
      local_1c = 0;
      local_28 = local_8c;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer
                ((ulonglong)local_30,&DAT_140007d8f,param_3,param_4,5,local_68);
    }
  }
  return uVar3;
}



===== ArbitrateUsbNotification @ 14000f36c =====

undefined1 ArbitrateUsbNotification(longlong param_1,int *param_2)

{
  *(int *)(param_1 + 0x20) = param_2[5];
  if (((*(longlong *)(param_2 + 9) != 0) || (*(longlong *)(param_2 + 0xb) != 0)) &&
     ((Microsoft_Windows_Power_CADEnableBits & 1) != 0)) {
    McTemplateK0z_EtwWriteTransfer();
  }
  if (*param_2 == 5) {
    if ((param_2[2] & 1U) == 0) {
      if ((*(int *)(param_1 + 0x24) != 5) && ((Microsoft_Windows_Power_CADEnableBits & 1) != 0)) {
        McTemplateK0z_EtwWriteTransfer();
      }
      *(undefined4 *)(param_1 + 0x24) = 5;
      return 1;
    }
    if ((*(int *)(param_1 + 0x24) != 2) && ((Microsoft_Windows_Power_CADEnableBits & 1) != 0)) {
      McTemplateK0z_EtwWriteTransfer();
    }
    *(undefined4 *)(param_1 + 0x24) = 2;
    if (*(int *)(param_1 + 0x34) != 0) {
      return 1;
    }
    if (*(longlong *)(param_1 + 0x4c) != 0) {
      return 1;
    }
    if (*(longlong *)(param_1 + 0x54) != 0) {
      return 1;
    }
  }
  else {
    if (*param_2 != 2) {
      return 1;
    }
    if (*(int *)(param_1 + 0x20) != 1) {
      *(undefined4 *)(param_1 + 0x24) = 2;
      return 1;
    }
    if ((*(int *)(param_1 + 0x24) != 5) && (*(int *)(param_1 + 0x24) == 2)) {
      if ((Microsoft_Windows_Power_CADEnableBits & 1) == 0) {
        return 1;
      }
      McTemplateK0z_EtwWriteTransfer();
      return 1;
    }
  }
  if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
    McTemplateK0z_EtwWriteTransfer();
  }
  return 0;
}



===== BatteryQueryInfo @ 14000f4c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BatteryQueryInfo(undefined8 *param_1)

{
  int iVar1;
  undefined1 auStack_c8 [32];
  undefined4 *local_a8;
  undefined4 *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_78;
  undefined4 local_74;
  ulonglong *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  ulonglong local_38 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_c8;
  local_5c = 0;
  local_4c = 0;
  local_90 = 0;
  local_98 = 0;
  local_74 = 0;
  local_64 = 0;
  local_44 = 0;
  local_40 = 0;
  local_18 = 0;
  local_58 = &local_48;
  local_70 = local_38;
  local_48 = *(undefined4 *)(param_1 + 2);
  local_a0 = &local_78;
  local_a8 = &local_60;
  local_38[0] = 0;
  local_38[1] = 0;
  local_60 = 1;
  local_28 = 0;
  uStack_20 = 0;
  local_50 = 0xc;
  local_78 = 1;
  local_68 = 0x24;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,*param_1,0,0x294044);
  if (iVar1 < 0) {
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
      local_a0 = (undefined4 *)CONCAT44(local_a0._4_4_,iVar1);
      local_a8 = (undefined4 *)CONCAT44(local_a8._4_4_,0x8fc);
      McTemplateK0sqd_EtwWriteTransfer();
    }
  }
  else {
    *(undefined2 *)((longlong)param_1 + 0x14) = 0;
    if ((local_38[0] & 8) != 0) {
      *(undefined1 *)((longlong)param_1 + 0x14) = 1;
    }
    if ((local_38[0] & 4) != 0) {
      *(undefined1 *)((longlong)param_1 + 0x15) = 1;
    }
    iVar1 = 0;
    *(undefined4 *)(param_1 + 6) = (undefined4)local_28;
  }
  return iVar1;
}



===== BatteryQueryStatus @ 14000f5fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000f6f2) */

int BatteryQueryStatus(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,*param_1,0,0x29404c);
  if (iVar1 < 0) {
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
      McTemplateK0sqd_EtwWriteTransfer();
    }
  }
  else {
    uVar3 = 0x4000;
    pcVar4 = "Capacity:%u, FullChargedCapacity:%u, Voltage:%u, Rate:%d\r\n";
    uVar2 = 3;
    _WPOutputDebugMessage(3,0x4000,"Capacity:%u, FullChargedCapacity:%u, Voltage:%u, Rate:%d\r\n",0)
    ;
    if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
      McTemplateK0qqqd_EtwWriteTransfer(uVar2,uVar3,pcVar4,0,(char)*(undefined4 *)(param_1 + 6),0,0)
      ;
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== BatteryQueryTag @ 14000f788 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BatteryQueryTag(undefined8 *param_1)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = local_res10;
  local_res8[0] = 0;
  local_1c = 0;
  local_c = 0;
  local_34 = 0;
  local_24 = 0;
  local_res10[0] = 0;
  local_10 = 4;
  local_28 = 4;
  local_30 = local_res8;
  local_20 = 1;
  local_38 = 1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,*param_1,0,0x294040,&local_20,&local_38,0,0);
  if (iVar1 < 0) {
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
      McTemplateK0sqd_EtwWriteTransfer();
    }
  }
  else {
    iVar1 = 0;
    *(undefined4 *)(param_1 + 2) = local_res8[0];
  }
  return iVar1;
}



===== BatterySearch @ 14000f86c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 BatterySearch(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0xf8))
  ;
  uVar5 = 0;
  if (uVar2 != 0) {
    do {
      local_28 = 0;
      uStack_20 = 0;
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x90))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0xf8),uVar5);
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,uVar3,0);
      (**(code **)(WdfFunctions_01015 + 0x9a8))
                (WdfDriverGlobals,*(undefined8 *)(lVar4 + 8),&local_28);
      cVar1 = RtlEqualUnicodeString(param_2,&local_28,0);
      if (cVar1 != '\0') {
        *param_3 = uVar3;
        return 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar2);
  }
  return 0xc0000225;
}



===== BatterySetChargerId @ 14000f988 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BatterySetChargerId(undefined8 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  undefined8 local_res8;
  undefined4 *local_res18;
  undefined8 local_res20;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res8 = 0;
  local_res20 = 0;
  local_res18 = (undefined4 *)0x0;
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,0,*param_1,&local_res8);
  if (-1 < iVar5) {
    local_28 = 0;
    local_48 = 0;
    uStack_40 = 0x100000001;
    uStack_30 = 0;
    local_38 = local_res8;
    uStack_50 = 0;
    local_58 = 0x38;
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,&local_58,0x200,0x2e444143,0x18,&local_res20,&local_res18);
    if (-1 < iVar5) {
      *local_res18 = *(undefined4 *)(param_1 + 2);
      local_res18[1] = 4;
      uVar1 = param_2[1];
      uVar2 = param_2[2];
      uVar3 = param_2[3];
      local_res18[2] = *param_2;
      local_res18[3] = uVar1;
      local_res18[4] = uVar2;
      local_res18[5] = uVar3;
      (**(code **)(WdfFunctions_01015 + 0x820))
                (WdfDriverGlobals,local_res8,BatterySetChargerIdCompletionRoutine,0);
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                        (WdfDriverGlobals,*param_1,local_res8,0x298048,local_res20,0,0,0);
      if (-1 < iVar5) {
        cVar4 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,local_res8,*param_1,0);
        if (cVar4 == '\0') {
          iVar5 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,local_res8);
          return iVar5;
        }
        return iVar5;
      }
    }
  }
  if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
    McTemplateK0sqd_EtwWriteTransfer();
  }
  return iVar5;
}



===== CADBatteryNotificationThread @ 14000fbb0 =====

void CADBatteryNotificationThread(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_res8;
  
  local_res8 = 0xffffffffee1e5d00;
  bVar1 = true;
  puVar3 = param_1;
  do {
    if ((*(int *)(param_1 + 1) == 0) && (*(char *)(param_1 + 0x19) == '\x01')) {
      if (bVar1) {
        if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
          McTemplateK0qqqqj_EtwWriteTransfer
                    (puVar3,&NotifyBatteryDriver,param_3,*(undefined4 *)(param_1 + 0x18),
                     (char)*(undefined4 *)((longlong)param_1 + 0xc4),
                     (char)*(undefined4 *)(param_1 + 0x1a),1,param_1 + 0x1b);
        }
        bVar1 = false;
      }
      NotifyAllBatteryDrivers(param_1,2,1);
    }
    param_3 = 0;
    puVar3 = param_1 + 0x21;
    iVar2 = KeWaitForSingleObject(puVar3,0,0,0,&local_res8);
  } while (iVar2 == 0x102);
  ZwClose(param_1[0x24]);
  return;
}



===== CADDriverUnload @ 14000fca0 =====

void CADDriverUnload(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_1400090e8;
  DAT_1400090e8 = 0;
  DAT_1400090c8 = 0;
  EtwUnregister(uVar1);
  McGenEventUnregister_EtwUnregister();
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



===== CADEvtDeviceAdd @ 14000fd20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CADEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  undefined1 auStack_238 [8];
  undefined1 auStack_230 [24];
  undefined8 *local_218;
  int local_210;
  undefined8 local_1f8;
  undefined8 local_1f0;
  code *pcStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined *local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  wchar_t *local_1a8;
  undefined8 local_1a0;
  code *pcStack_198;
  code *local_190;
  undefined8 uStack_188;
  undefined4 local_180;
  undefined4 local_17c;
  undefined8 local_178;
  undefined4 local_170;
  undefined4 local_16c;
  undefined8 local_168;
  undefined8 local_160;
  undefined4 local_158;
  undefined4 local_154;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined1 local_12b;
  code *local_110;
  code *local_108;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  wchar_t local_78 [40];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_238;
  local_c8 = 0;
  local_c0 = 0;
  local_1f8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_178 = 0;
  local_1c0 = (undefined *)((ulonglong)local_1c0 & 0xffffffff00000000);
  local_1f0 = 0;
  pcStack_1e8 = (code *)0x0;
  local_180 = 0;
  local_1e0 = 0;
  uStack_1d8 = 0;
  local_1d0 = 0;
  uStack_1c8 = 0;
  local_1a0 = 0;
  pcStack_198 = (code *)0x0;
  local_190 = (code *)0x0;
  uStack_188 = 0;
  local_b8 = 0;
  uStack_b4 = 0;
  uStack_b0 = 0;
  uStack_ac = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_1b8 = param_2;
  memset(&local_138,0,0x60);
  builtin_wcsncpy(local_78,L"Charge Arbitration Driver Status",0x21);
  local_1a8 = local_78;
  local_1b0 = 0x420040;
  CadLockAcquire((undefined8 *)&CadInitializationLock);
  puVar6 = auStack_238;
  if (CadDriverContext != (undefined8 *)0x0) {
    iVar3 = -0x3fffffff;
    goto LAB_140010435;
  }
  pcStack_198 = CADEvtFileCreate;
  local_1a0 = CONCAT44(local_1a0._4_4_,0x28);
  local_1e0 = 0;
  local_190 = CADEvtFileClose;
  local_1c0 = PTR__WDF_CADFILEOBJECTCONTEXT_TYPE_INFO_140009018;
  pcStack_1e8 = (code *)0x0;
  uStack_188 = 0;
  local_17c = 4;
  local_180 = 2;
  local_1d0 = 0;
  uStack_1c8 = 0;
  local_1f0 = 0x38;
  uStack_1d8 = 0x100000001;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_1b8,&local_1a0,&local_1f0);
  local_1c0 = PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040;
  local_1f0 = 0x38;
  pcStack_1e8 = CADEvtDeviceContextCleanup;
  local_1e0 = 0;
  local_1d0 = 0;
  uStack_1c8 = 0;
  uStack_1d8 = 0x100000002;
  iVar3 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_1b8,&local_1f0,&local_1f8)
  ;
  puVar6 = auStack_238;
  if (iVar3 < 0) {
    if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) goto LAB_140010435;
    local_218 = (undefined8 *)CONCAT44(local_218._4_4_,0x358);
    puVar6 = auStack_238;
    local_210 = iVar3;
  }
  else {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x268))
                      (WdfDriverGlobals,local_1f8,&GUID_DEVINTERFACE_CHARGING_ARBITRATION,&local_1b0
                      );
    puVar6 = auStack_238;
    if (iVar3 < 0) {
      if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) goto LAB_140010435;
      local_218 = (undefined8 *)CONCAT44(local_218._4_4_,0x365);
      puVar6 = auStack_238;
      local_210 = iVar3;
    }
    else {
      local_110 = CADEvtIoDeviceControl;
      local_218 = &local_178;
      local_138 = 0x60;
      local_108 = CADEvtIoInternalDeviceControl;
      local_130 = 2;
      local_12b = 1;
      local_134 = 1;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_1f8,&local_138,0);
      puVar6 = auStack_238;
      if (iVar3 < 0) {
        if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) goto LAB_140010435;
        local_218 = (undefined8 *)CONCAT44(local_218._4_4_,0x377);
        puVar6 = auStack_238;
        local_210 = iVar3;
      }
      else {
        uStack_90 = 0xffffffffffffffff;
        local_b8 = 0x30;
        uStack_b4 = 2;
        uStack_b0 = 0;
        local_a8 = 0x200000002;
        uStack_a0 = 2;
        local_98 = 0x200000002;
        uStack_ac = 0;
        (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_1f8,&local_b8);
        local_d8 = 0x20000001c;
        uStack_d0 = 0x200000002;
        local_c0 = 2;
        local_c8 = 0x200000001;
        (**(code **)(WdfFunctions_01015 + 0xe8))(WdfDriverGlobals,local_1f8,&local_d8);
        puVar7 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_1f8,PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040);
        CadDriverContext = puVar7;
        *puVar7 = local_1f8;
        *(undefined4 *)(puVar7 + 1) = 0;
        *(undefined1 *)((longlong)puVar7 + 0x1c) = 1;
        *(undefined4 *)(puVar7 + 4) = 2;
        ResetUsbConnectionState(1,(longlong)puVar7);
        *(undefined4 *)((longlong)puVar7 + 0x9c) = 0xffffffff;
        *(undefined4 *)((longlong)puVar7 + 0xc4) = 0xffffffff;
        *(undefined4 *)(puVar7 + 0x18) = 4;
        *(undefined4 *)(puVar7 + 0x13) = 3;
        *(undefined4 *)(puVar7 + 0x1d) = 3;
        local_1c0 = (undefined *)0x0;
        local_1e0 = 0;
        uStack_1c8 = 0;
        local_1d0 = local_1f8;
        pcStack_1e8 = (code *)0x0;
        local_1f0 = 0x38;
        uStack_1d8 = 0x100000001;
        (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_1f0,puVar7 + 0x1f);
        puVar6 = auStack_238;
        local_1c0 = (undefined *)0x0;
        local_1e0 = 0;
        uStack_1c8 = 0;
        local_1d0 = local_1f8;
        pcStack_1e8 = (code *)0x0;
        local_1f0 = 0x38;
        uStack_1d8 = 0x100000001;
        local_88 = *(undefined4 *)(PTR_DAT_1400090d0 + -0x10);
        uStack_84 = *(undefined4 *)(PTR_DAT_1400090d0 + -0xc);
        uStack_80 = *(undefined4 *)(PTR_DAT_1400090d0 + -8);
        uStack_7c = *(undefined4 *)(PTR_DAT_1400090d0 + -4);
        if (DAT_1400090e8 != 0) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(5);
          puVar6 = auStack_230;
        }
        _DAT_1400090f0 = CadDiagTraceLoggingControlCallback;
        *(undefined8 *)(puVar6 + -8) = 0x14001021f;
        _DAT_1400090f8 = puVar7;
        iVar3 = EtwRegister(&local_88,_tlgEnableCallback,&DAT_1400090c8,&DAT_1400090e8);
        if (iVar3 == 0) {
          uVar1 = *(undefined2 *)PTR_DAT_1400090d0;
          *(undefined8 *)(puVar6 + -8) = 0x140010244;
          EtwSetInformation(DAT_1400090e8,2,PTR_DAT_1400090d0,uVar1);
        }
        *(undefined8 *)(puVar6 + -8) = 0x14001025d;
        KeInitializeEvent(puVar7 + 0x21,1,0);
        *(undefined8 *)(puVar6 + -8) = 0x14001026e;
        iVar3 = DoesDppFileExist(L"\\??\\C:\\Dpp\\Microsoft\\UsbNoCurrentDraw.txt");
        if (iVar3 < 0) {
          if (*KdDebuggerEnabled_exref != (code)0x0) {
            *(undefined8 *)(puVar6 + -8) = 0x1400102cc;
            iVar3 = GetKdType();
            *(int *)(puVar7 + 0x1d) = iVar3;
            if (iVar3 != 2) {
              local_16c = 0;
              local_154 = 0;
              *(undefined8 *)(puVar6 + -8) = 0x1400102ed;
              iVar3 = DoesDppFileExist(L"\\??\\C:\\Dpp\\Microsoft\\UsbKdMaxCurrent500mA.txt");
              if (iVar3 < 0) {
                *(undefined4 *)((longlong)puVar7 + 0xc4) = 900;
              }
              else {
                *(undefined4 *)((longlong)puVar7 + 0xc4) = 500;
              }
              if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
                *(undefined8 *)(puVar6 + -8) = 0x14001032c;
                McTemplateK0z_EtwWriteTransfer();
              }
              *(undefined8 **)(puVar6 + 0x30) = puVar7;
              *(code **)(puVar6 + 0x28) = CADBatteryNotificationThread;
              *(undefined8 *)(puVar6 + 0x20) = 0;
              *(undefined1 *)(puVar7 + 0x19) = 1;
              local_170 = 0x30;
              local_168 = 0;
              local_158 = 0;
              local_160 = 0;
              local_150 = 0;
              uStack_148 = 0;
              *(undefined8 *)(puVar6 + -8) = 0x14001037d;
              PsCreateSystemThread(puVar7 + 0x24,0x1fffff,&local_170,0);
            }
          }
        }
        else {
          *(undefined1 *)((longlong)puVar7 + 0x1c) = 0;
          *(undefined4 *)((longlong)puVar7 + 0xc4) = 0;
          *(undefined8 *)(puVar6 + -8) = 0x140010299;
          _WPOutputDebugMessage
                    (3,0x4000,"*** Found Disable USB Charging DPP File: %S\r\n",
                     L"\\??\\C:\\Dpp\\Microsoft\\UsbNoCurrentDraw.txt");
          if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
            *(undefined8 *)(puVar6 + -8) = 0x1400102b2;
            McTemplateK0z_EtwWriteTransfer();
          }
        }
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x138);
        *(undefined8 *)(puVar6 + -8) = 0x1400103a1;
        uVar4 = (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(puVar6 + 0x40));
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x3b0);
        *(undefined8 *)(puVar6 + -8) = 0x1400103c1;
        puVar5 = (uint *)(*pcVar2)(WdfDriverGlobals,uVar4);
        *(undefined8 **)(puVar6 + 0x30) = puVar7 + 0x1e;
        puVar7 = &GUID_DEVICE_BATTERY;
        uVar4 = 1;
        *(undefined8 *)(puVar6 + 0x28) = *(undefined8 *)(puVar6 + 0x40);
        *(code **)(puVar6 + 0x20) = CADEvtPnpNotifyDeviceBattery;
        *(undefined8 *)(puVar6 + -8) = 0x1400103fa;
        iVar3 = IoRegisterPlugPlayNotification(2);
        if (-1 < iVar3) {
          *(undefined8 *)(puVar6 + -8) = 0x140010429;
          iVar3 = CadHpmiInitialize(*(undefined8 *)(puVar6 + 0x40),uVar4,puVar7,puVar5);
          *(undefined8 *)(puVar6 + -8) = 0x140010435;
          CadChargeLimitingInitialize(*(undefined8 *)(puVar6 + 0x40));
          goto LAB_140010435;
        }
        if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) goto LAB_140010435;
        *(int *)(puVar6 + 0x28) = iVar3;
        *(undefined4 *)(puVar6 + 0x20) = 0x3f8;
      }
    }
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000ff44;
  McTemplateK0sqd_EtwWriteTransfer();
LAB_140010435:
  *(undefined8 *)(puVar6 + -8) = 0x140010441;
  CadLockRelease((undefined8 *)&CadInitializationLock);
  *(undefined8 *)(puVar6 + -8) = 0x140010452;
  return iVar3;
}



===== CADEvtDeviceContextCleanup @ 140010480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CADEvtDeviceContextCleanup
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040);
  uVar1 = 0;
  puVar4 = PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  CadLockAcquire((undefined8 *)(lVar3 + 0x128));
  CadPsUninitialize((undefined8 *)(lVar3 + 0x148),param_1,puVar4,param_4);
  if (*(longlong *)(lVar3 + 0x138) != 0) {
    uVar1 = IoUnregisterPlugPlayNotificationEx();
    *(undefined8 *)(lVar3 + 0x138) = 0;
  }
  if (5 < DAT_1400090c8) {
    local_2c = 0;
    local_1c = 0;
    local_38 = "HPMI Uninitialize";
    local_28 = local_68;
    local_30 = 0x12;
    local_20 = 4;
    local_68[0] = uVar1;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_140007d2b,puVar4,param_4,4,local_58);
  }
  CadLockRelease((undefined8 *)(lVar3 + 0x128));
  KeSetEvent(lVar2 + 0x108,0,0);
  IoUnregisterPlugPlayNotificationEx(*(undefined8 *)(lVar2 + 0xf0));
  return;
}



===== CADEvtFileClose @ 140010600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CADEvtFileClose(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  pcVar3 = (char *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,
                              PTR__WDF_CADFILEOBJECTCONTEXT_TYPE_INFO_140009018);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  puVar5 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar4,PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040);
  cVar1 = GetStickyDisableChargingWnfState((longlong)puVar5);
  if ((*pcVar3 != '\0') && (cVar1 == '\0')) {
    if ((0 < *(int *)(puVar5 + 1)) &&
       (iVar2 = *(int *)(puVar5 + 1) + -1, *(int *)(puVar5 + 1) = iVar2, iVar2 == 0)) {
      NotifyAllBatteryDrivers(puVar5,0,6);
    }
    *pcVar3 = '\0';
  }
  return;
}



===== CADEvtFileCreate @ 1400106c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CADEvtFileCreate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_3,PTR__WDF_CADFILEOBJECTCONTEXT_TYPE_INFO_140009018);
  *puVar1 = 0;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
  return;
}



===== CADEvtIoDeviceControl @ 140010720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Type propagation algorithm not settling */

void CADEvtIoDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t ***param_4,
               int param_5)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  char *pcVar5;
  undefined8 *puVar6;
  ulonglong *puVar7;
  ulonglong *puVar8;
  undefined1 uVar9;
  undefined *puVar10;
  undefined8 uVar11;
  undefined8 *local_38;
  char *local_30;
  int *local_28;
  undefined8 local_20;
  
  uVar9 = 0;
  local_20 = 0;
  local_30 = (char *)0x0;
  local_28 = (int *)0x0;
  uVar11 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar10 = PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040;
  puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar11);
  if (param_5 == 0x29c480) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,1,&local_30,0);
    if (-1 < iVar3) {
      uVar11 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
      pcVar5 = (char *)(**(code **)(WdfFunctions_01015 + 0x650))
                                 (WdfDriverGlobals,uVar11,
                                  PTR__WDF_CADFILEOBJECTCONTEXT_TYPE_INFO_140009018);
      cVar2 = GetStickyDisableChargingWnfState((longlong)puVar4);
      cVar1 = *local_30;
      if ((*pcVar5 == cVar1) && (cVar2 == '\0')) goto LAB_140010b6c;
      if (cVar2 != '\0') {
        if (cVar1 == '\0') {
          if (*(int *)(puVar4 + 1) == 0) goto LAB_140010b6c;
        }
        else if (*(int *)(puVar4 + 1) != 0) goto LAB_140010b6c;
      }
      *pcVar5 = cVar1;
      uVar11 = UpdateChargingPolicy(puVar4,*local_30);
      iVar3 = (int)uVar11;
      if (-1 < iVar3) goto LAB_140010b6c;
    }
  }
  else if (param_5 == 0x29c488) {
    local_38 = (undefined8 *)0x0;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x44,&local_38,0);
    if (-1 < iVar3) {
      puVar6 = puVar4 + 5;
      if (*(int *)((longlong)puVar4 + 0x3c) != 0) {
        puVar6 = (undefined8 *)0x0;
      }
      if (puVar6 == (undefined8 *)0x0) {
        *local_38 = 0;
        local_38[1] = 0;
      }
      else {
        *(undefined4 *)local_38 = *(undefined4 *)puVar6;
        *(undefined4 *)((longlong)local_38 + 4) = *(undefined4 *)((longlong)puVar6 + 0xc);
        *(undefined4 *)(local_38 + 1) = *(undefined4 *)(puVar6 + 4);
        if (((*(int *)((longlong)puVar6 + 0xc) != 0) ||
            (*(longlong *)((longlong)puVar6 + 0x24) != 0)) ||
           (*(longlong *)((longlong)puVar6 + 0x2c) != 0)) {
          uVar9 = 1;
        }
        *(undefined1 *)((longlong)local_38 + 0xc) = uVar9;
      }
      TranslatePowerSourceInfoUsbToStatus
                ((longlong)puVar4,*(int *)((longlong)puVar4 + 0x24),1,local_38 + 2);
      puVar7 = puVar4 + 0x15;
      puVar6 = local_38;
      ValidateGenericPowerSource(puVar7);
      *(undefined4 *)(puVar6 + 6) = *(undefined4 *)(puVar4 + 0x13);
      *(undefined4 *)((longlong)puVar6 + 0x34) = *(undefined4 *)((longlong)puVar4 + 0x9c);
      puVar8 = puVar4 + 0x1a;
      *(int *)(puVar6 + 7) = (int)*puVar7;
      *(undefined1 *)((longlong)puVar6 + 0x3c) = *(undefined1 *)(puVar4 + 0x14);
      puVar6 = local_38;
      ValidateGenericPowerSource(puVar8);
      uVar11 = 0x44;
      *(undefined4 *)(puVar6 + 4) = *(undefined4 *)(puVar4 + 0x18);
      *(undefined4 *)((longlong)puVar6 + 0x24) = *(undefined4 *)((longlong)puVar4 + 0xc4);
      *(int *)(puVar6 + 5) = (int)*puVar8;
      *(undefined1 *)((longlong)puVar6 + 0x2c) = *(undefined1 *)(puVar4 + 0x19);
      *(undefined4 *)(local_38 + 8) = *(undefined4 *)(puVar4 + 1);
LAB_140010910:
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,uVar11);
      return;
    }
  }
  else if (param_5 == 0x29c4c4) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,1,&local_20,0);
    if (-1 < iVar3) {
      uVar11 = 1;
      *(bool *)local_20 = *(char *)((longlong)puVar4 + 0x1c) != '\x01';
      goto LAB_140010910;
    }
  }
  else {
    if (param_5 != 0x29c4c8) {
      if (param_5 == 0x29cc00) {
        CadHpmiIoctl(param_1,param_2,puVar10,param_4,0x29cc00);
        return;
      }
      iVar3 = -0x3fffff45;
      goto LAB_140010b6c;
    }
    if (param_4 < (wchar_t ***)0xc) {
      iVar3 = -0x3ffffff3;
    }
    else {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0xc,&local_28,0);
      if (-1 < iVar3) {
        if ((*local_28 == 2) || (*local_28 == 5)) {
          iVar3 = PowerSourceUpdateUsb(puVar4,(ulonglong)param_4,param_2);
          goto LAB_140010b6c;
        }
        iVar3 = -0x3ffffff3;
      }
    }
  }
  if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
    McTemplateK0sqd_EtwWriteTransfer();
  }
LAB_140010b6c:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar3);
  return;
}



===== CADEvtIoInternalDeviceControl @ 140010bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CADEvtIoInternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4,
               int param_5)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  int local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar3,PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040);
  if (param_5 == 0x29c4c0) {
    if (param_4 < 0x18) {
      iVar1 = -0x3ffffff3;
      if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) goto LAB_140010d85;
      local_60 = -0x3ffffff3;
      local_68 = CONCAT44(local_68._4_4_,0x5ca);
    }
    else {
      local_58 = (undefined8 *)0x0;
      local_68 = 0;
      uVar3 = 0x28;
      if (param_4 < 0x28) {
        local_50 = 0;
        uStack_48 = 0;
        uStack_40 = 0;
        uVar3 = 0x18;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))();
        if (iVar1 < 0) {
          if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) goto LAB_140010d85;
          local_68 = CONCAT44(local_68._4_4_,0x5d8);
          local_60 = iVar1;
        }
        else {
          local_50 = *local_58;
          uStack_48 = local_58[1];
          uStack_40 = local_58[2];
          local_38 = 0;
          uStack_30 = 0;
          uVar3 = PowerSourceUpdateWireless(puVar2,&local_50,uVar3);
          iVar1 = (int)uVar3;
          if ((-1 < iVar1) || ((Microsoft_Windows_Power_CADEnableBits & 2) == 0))
          goto LAB_140010d85;
          local_68 = CONCAT44(local_68._4_4_,0x5e1);
          local_60 = iVar1;
        }
      }
      else {
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x28,&local_58);
        if (iVar1 < 0) {
          if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) goto LAB_140010d85;
          local_68 = CONCAT44(local_68._4_4_,0x5ec);
          local_60 = iVar1;
        }
        else {
          uVar3 = PowerSourceUpdateWireless(puVar2,local_58,uVar3);
          iVar1 = (int)uVar3;
          if ((-1 < iVar1) || ((Microsoft_Windows_Power_CADEnableBits & 2) == 0))
          goto LAB_140010d85;
          local_68 = CONCAT44(local_68._4_4_,0x5f2);
          local_60 = iVar1;
        }
      }
    }
  }
  else {
    iVar1 = -0x3fffff45;
    if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) goto LAB_140010d85;
    local_60 = -0x3fffff45;
    local_68 = CONCAT44(local_68._4_4_,0x5fa);
  }
  iVar1 = local_60;
  McTemplateK0sqd_EtwWriteTransfer();
LAB_140010d85:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== CADEvtPnpNotifyDeviceBattery @ 140010dd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CADEvtPnpNotifyDeviceBattery(longlong param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  code *pcVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined8 local_res8;
  undefined8 *local_res10;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 local_6c;
  undefined4 local_68;
  
  local_res8 = 0;
  local_res10 = (undefined8 *)0x0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040);
  if ((*(longlong *)(param_1 + 0x14) != 0x11d078a472631e54) ||
     (*(longlong *)(param_1 + 0x1c) != 0x2ab3b700aa00f7bc)) {
joined_r0x000140011519:
    if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) {
      return 0;
    }
    McTemplateK0sqd_EtwWriteTransfer();
    return 0;
  }
  if ((*(longlong *)(param_1 + 4) != 0x11d046f0cb3a4004) ||
     (*(longlong *)(param_1 + 0xc) != 0x3f05139760008fb0)) {
    if (*(longlong *)(param_1 + 4) != 0x11d046f0cb3a4005) {
      return 0;
    }
    if (*(longlong *)(param_1 + 0xc) != 0x3f05139760008fb0) {
      return 0;
    }
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,param_2);
    (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar7);
    uVar7 = BatterySearch(lVar4,*(undefined8 *)(param_1 + 0x28),&local_res8);
    if ((int)uVar7 < 0) {
      if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
        McTemplateK0sqd_EtwWriteTransfer();
      }
      uVar7 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,param_2);
      pcVar5 = *(code **)(WdfFunctions_01015 + 0x9b8);
      goto LAB_140010f87;
    }
    (**(code **)(WdfFunctions_01015 + 0x80))
              (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0xf8),local_res8);
    goto LAB_1400111d6;
  }
  local_c8 = 0;
  local_e8 = 0;
  uStack_f0 = 0;
  uStack_d0 = 0;
  local_f8 = 0x38;
  uStack_e0 = 0x100000001;
  local_d8 = param_2;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,&local_f8,0x200,0x2e444143,0x38,&local_res8,&local_res10);
  if (iVar2 < 0) goto joined_r0x000140011519;
  local_c8 = 0;
  local_e8 = 0;
  uStack_d0 = 0;
  local_d8 = local_res8;
  uStack_f0 = 0;
  local_f8 = 0x38;
  uStack_e0 = 0x100000001;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_2,&local_f8,local_res10);
  if (iVar2 < 0) {
joined_r0x000140011005:
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
LAB_140010f69:
      McTemplateK0sqd_EtwWriteTransfer();
    }
  }
  else {
    memset(&local_b8,0,0x88);
    puVar1 = *(undefined4 **)(param_1 + 0x28);
    local_b8 = 0x88;
    local_b4 = 2;
    local_88 = *puVar1;
    uStack_84 = puVar1[1];
    uStack_80 = puVar1[2];
    uStack_7c = puVar1[3];
    local_78 = 0xc0000000;
    local_68 = 0x40;
    local_6c = 1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,*local_res10,&local_b8);
    if (iVar2 < 0) goto joined_r0x000140011005;
    local_c8 = 0;
    local_e8 = 0;
    uStack_d0 = 0;
    local_d8 = local_res8;
    uStack_f0 = 0;
    local_f8 = 0x38;
    uStack_e0 = 0x100000001;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x9a0))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28),&local_f8,local_res10 + 1);
    if ((((iVar2 < 0) || (iVar2 = BatteryQueryTag(local_res10), iVar2 < 0)) ||
        (iVar2 = BatteryQueryInfo(local_res10), iVar2 < 0)) ||
       (iVar2 = BatteryQueryStatus(local_res10), iVar2 < 0)) {
      if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) goto LAB_140010f75;
      goto LAB_140010f69;
    }
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,param_2);
    (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar7);
    if (*(int *)(lVar4 + 8) == 0) {
      uVar3 = NotifyOneBatteryDriver(lVar4,local_res10,0,6,0);
      *(undefined4 *)(lVar4 + 0x14) = 0;
      *(undefined4 *)(lVar4 + 0x10) = 6;
      *(uint *)(lVar4 + 0x18) = uVar3;
      if (-1 < (int)uVar3) goto LAB_140011218;
      if (((Microsoft_Windows_Power_CADEnableBits & 2) == 0) ||
         (McTemplateK0sqd_EtwWriteTransfer(), (Microsoft_Windows_Power_CADEnableBits & 2) == 0))
      goto LAB_1400111d6;
LAB_1400111ca:
      McTemplateK0sqd_EtwWriteTransfer();
    }
    else {
LAB_140011218:
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x78))
                        (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0xf8),local_res8);
      if (iVar2 < 0) {
        if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) goto LAB_1400111ca;
      }
      else {
        local_e8 = 0;
        local_c8 = 0;
        uStack_f0 = 0;
        local_f8 = 0x38;
        uStack_d0 = 0;
        uStack_e0 = 0x100000001;
        local_d8 = *local_res10;
        uVar3 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                          (WdfDriverGlobals,&local_f8,*local_res10,local_res10 + 3);
        if ((int)uVar3 < 0) {
          if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
            McTemplateK0sqd_EtwWriteTransfer();
          }
          pcVar8 = "Failed to create request for source change notification: 0x%x\r\n";
        }
        else {
          local_c8 = 0;
          local_e8 = 0;
          uStack_d0 = 0;
          local_d8 = local_res8;
          uStack_f0 = 0;
          local_f8 = 0x38;
          uStack_e0 = 0x100000001;
          uVar3 = (**(code **)(WdfFunctions_01015 + 0x608))
                            (WdfDriverGlobals,&local_f8,local_res10 + 5,8,local_res10 + 4);
          if (-1 < (int)uVar3) {
            uVar7 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,param_2);
            (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar7);
            uVar6 = SendChargeSourceChangeNotificationRequestASync(local_res8);
            if (-1 < (int)uVar6) {
              return 0;
            }
            if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
              McTemplateK0sqd_EtwWriteTransfer();
            }
            _WPOutputDebugMessage
                      (3,0x4000,
                       "NON-FATAL: Failed to send first async request for source change notification: 0x%x\r\n"
                       ,0);
            return 0;
          }
          if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
            McTemplateK0sqd_EtwWriteTransfer();
          }
          pcVar8 = "Failed to allocate memory for source change notification: 0x%x\r\n";
        }
        _WPOutputDebugMessage(2,0x4000,pcVar8,(ulonglong)uVar3);
      }
    }
LAB_1400111d6:
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,param_2);
    (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar7);
  }
LAB_140010f75:
  pcVar5 = *(code **)(WdfFunctions_01015 + 0x680);
  uVar7 = local_res8;
LAB_140010f87:
  (*pcVar5)(WdfDriverGlobals,uVar7);
  return 0;
}



===== CADSourceChangeCompletionRoutine @ 140011560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CADSourceChangeCompletionRoutine
               (undefined8 param_1,undefined8 param_2,longlong param_3,char *param_4)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 local_1c;
  undefined4 local_14;
  
  pcVar7 = param_4;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_4,0);
  uVar2 = *(uint *)(param_3 + 8);
  if ((int)uVar2 < 0) {
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
      McTemplateK0sqd_EtwWriteTransfer();
    }
    pcVar7 = 
    "NON-FATAL: Request for source change notification failed with 0x%x - ignoring future requests\r\n"
    ;
    uVar6 = 4;
    goto LAB_140011752;
  }
  uVar2 = *(uint *)(lVar3 + 0x28);
  if (uVar2 == 0xffffffff) {
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
      pcVar7 = "CADSourceChangeCompletionRoutine";
      McTemplateK0sqd_EtwWriteTransfer();
    }
    _WPOutputDebugMessage
              (4,0x4000,
               "NON-FATAL: Request for source change notification not supported - ignoring future requests\r\n"
               ,pcVar7);
    return;
  }
  cVar1 = *(char *)(lVar3 + 0x2c);
  uVar6 = 4;
  if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
    pcVar7 = (char *)(ulonglong)uVar2;
    McTemplateK0qq_EtwWriteTransfer();
  }
  if (uVar2 == 1) {
    pcVar8 = "AC power source ON\r\n";
    if (cVar1 == '\0') {
      pcVar8 = "AC power source OFF\r\n";
    }
  }
  else {
    if (uVar2 == 2) {
      pcVar4 = "USB power source OFF\r\n";
      pcVar8 = "USB power source ON\r\n";
    }
    else {
      if (uVar2 != 3) {
        uVar6 = 3;
        pcVar8 = "NON-FATAL: Source change detected for unknown type\r\n";
        goto LAB_140011697;
      }
      pcVar4 = "Wireless power source OFF\r\n";
      pcVar8 = "Wireless power source ON\r\n";
    }
    if (cVar1 == '\0') {
      pcVar8 = pcVar4;
    }
  }
LAB_140011697:
  _WPOutputDebugMessage(uVar6,0x4000,pcVar8,pcVar7);
  local_1c = 0;
  local_14 = 0;
  local_24 = 0;
  local_20 = 0;
  local_28 = 0x18;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,param_1,&local_28);
  if ((int)uVar2 < 0) {
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
      McTemplateK0sqd_EtwWriteTransfer();
    }
    pcVar7 = "NON-FATAL: Failed to reuse request for source change notification: 0x%x\r\n";
    uVar6 = 2;
  }
  else {
    uVar5 = SendChargeSourceChangeNotificationRequestASync(param_4);
    uVar2 = (uint)uVar5;
    if (-1 < (int)uVar2) {
      return;
    }
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
      McTemplateK0sqd_EtwWriteTransfer();
    }
    pcVar7 = 
    "NON-FATAL: Failed to send subsequent async request for source change notification: 0x%x\r\n";
    uVar6 = 3;
  }
LAB_140011752:
  _WPOutputDebugMessage(uVar6,0x4000,pcVar7,(ulonglong)uVar2);
  return;
}



===== CadChargeLimitingInitialize @ 140011784 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CadChargeLimitingInitialize(undefined8 param_1)

{
  uint *puVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  int *piVar8;
  byte *pbVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined1 auStackY_2d8 [32];
  undefined4 uVar12;
  uint local_298 [3];
  int local_28c;
  short local_288 [8];
  undefined8 local_278 [4];
  uint *local_258;
  undefined4 local_250;
  undefined4 local_24c;
  uint *local_248;
  undefined4 local_240;
  undefined4 local_23c;
  int *local_238;
  undefined4 local_230;
  undefined4 local_22c;
  short local_228 [256];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_2d8;
  memset(local_228,0,0x200);
  local_298[1] = 0;
  local_288[0] = 0;
  local_288[1] = 0;
  local_288[2] = 0;
  local_288[3] = 0;
  local_288[4] = 0;
  local_288[5] = 0;
  local_288[6] = 0;
  local_288[7] = 0;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040);
  bVar2 = true;
  puVar1 = (uint *)(lVar7 + 0x1c0);
  *(undefined1 *)(lVar7 + 0x1d8) = 1;
  piVar8 = (int *)(lVar7 + 0x1c4);
  *puVar1 = 200;
  *piVar8 = 5;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,0,lVar7 + 0x1c8);
  if (((-1 < iVar4) &&
      (iVar4 = RtlGetPersistedStateLocation
                         (L"ChargeLimiting",0,
                          L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\CAD\\ChargeLimiting"
                          ,0), -1 < iVar4)) &&
     (uVar5 = RtlUnicodeStringInitWorker(local_288,local_228), -1 < (int)uVar5)) {
    local_298[0] = 200;
    iVar4 = CadRegReadUlong(local_288,&COMPOSITE_MAX_CHARGE_LIMIT_SUBKEY,local_298,puVar1);
    if (-1 < iVar4) {
      local_298[0] = 5;
      iVar4 = CadRegReadUlong(local_288,&COMPOSITE_HYSTERESIS_SUBKEY,local_298,piVar8);
      if (-1 < iVar4) {
        uVar5 = *puVar1;
        iVar4 = *piVar8;
        if (((9 < (int)(uVar5 - iVar4)) && (uVar5 < 0x65)) && (iVar4 - 2U < 9)) {
          uVar11 = 0;
          uVar10 = 1;
          piVar8 = (int *)&CadWnfPoCompositeBattery;
          uVar6 = ExSubscribeWnfStateChange(&CadWnfPoCompositeBattery,&WNF_PO_COMPOSITE_BATTERY);
          if ((int)uVar6 < 0) {
            if (DAT_1400090c8 < 6) {
              return;
            }
            pbVar9 = &DAT_140007f75;
            uVar12 = 3;
            local_298[0] = uVar6;
          }
          else {
            if (DAT_1400090c8 < 6) {
              return;
            }
            if (((_DAT_1400090d8 & 0x200000000000) == 0) ||
               ((DAT_1400090e0 & 0x200000000000) != DAT_1400090e0)) {
              bVar2 = false;
            }
            if (!bVar2) {
              return;
            }
            bVar3 = ExIsManufacturingModeEnabled();
            local_23c = 0;
            local_248 = local_298 + 2;
            local_22c = 0;
            pbVar9 = &DAT_140007ef6;
            local_298[0] = (uint)bVar3;
            local_240 = 4;
            local_230 = 4;
            piVar8 = &local_28c;
            uVar12 = 5;
            local_298[2] = uVar5;
            local_28c = iVar4;
            local_238 = piVar8;
          }
          local_250 = 4;
          local_258 = local_298;
          local_24c = 0;
          _tlgWriteTransfer_EtwWriteTransfer(piVar8,pbVar9,uVar10,uVar11,uVar12,local_278);
        }
      }
    }
  }
  return;
}



===== CadWnfCompositeBatteryCallback @ 140011a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CadWnfCompositeBatteryCallback
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  char cVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  uint *puVar8;
  undefined8 uVar9;
  undefined1 auStackY_f8 [32];
  uint local_c8;
  uint local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  ulonglong local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_78 [4];
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_c8 = 0x3c;
  local_88 = 0;
  local_80 = 0;
  puVar8 = &local_c8;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  uVar3 = CadWnfExtractData(param_1,param_4,&local_b8,puVar8);
  if ((int)uVar3 < 0) {
    return uVar3 & 0xffffffff;
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_6,PTR__WDF_CAD_CONTEXT_TYPE_INFO_140009040);
  CadLockAcquire(puVar4 + 0x39);
  cVar2 = ExIsManufacturingModeEnabled();
  if (cVar2 == '\0') goto LAB_140011c1c;
  uVar7 = local_a8 & 0xffffffff;
  cVar2 = *(char *)(puVar4 + 0x3b);
  uVar9 = CONCAT71((int7)((ulonglong)puVar8 >> 8),cVar2);
  if ((uint)local_a8 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = ((int)uStack_90 * 100 + ((uint)local_a8 >> 1)) / (uint)local_a8;
  }
  cVar5 = '\x01';
  if (uVar6 < *(uint *)(puVar4 + 0x38)) {
    if ((cVar2 == '\0') && (*(uint *)(puVar4 + 0x38) - *(int *)((longlong)puVar4 + 0x1c4) < uVar6))
    {
      *(undefined1 *)(puVar4 + 0x3b) = 0;
      goto LAB_140011c1c;
    }
  }
  else {
    cVar5 = '\0';
  }
  *(char *)(puVar4 + 0x3b) = cVar5;
  if (cVar2 == cVar5) goto LAB_140011c1c;
  iVar1 = *(int *)(puVar4 + 1);
  if (cVar5 == '\0') {
    *(int *)(puVar4 + 1) = iVar1 + 1;
    if (iVar1 + 1 == 1) {
      uVar6 = 1;
      goto LAB_140011b9a;
    }
  }
  else if ((0 < iVar1) && (*(int *)(puVar4 + 1) = iVar1 + -1, iVar1 + -1 == 0)) {
    uVar6 = 0;
LAB_140011b9a:
    uVar7 = 6;
    NotifyAllBatteryDrivers(puVar4,uVar6,6);
  }
  if (5 < DAT_1400090c8) {
    local_4c = 0;
    local_3c = 0;
    local_2c = 0;
    local_c4 = (uint)*(byte *)(puVar4 + 0x3b);
    local_58 = &local_c4;
    local_c0 = *(undefined4 *)(puVar4 + 0x38);
    local_48 = &local_c0;
    local_bc = *(undefined4 *)((longlong)puVar4 + 0x1c4);
    local_38 = &local_bc;
    local_50 = 4;
    local_40 = 4;
    local_30 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_140007dfb,uVar7,uVar9,5,local_78);
  }
LAB_140011c1c:
  CadLockRelease(puVar4 + 0x39);
  return uVar3 & 0xffffffff;
}



===== EventWriteNotifyBatteryChargerStatus @ 140011c4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EventWriteNotifyBatteryChargerStatus
               (undefined8 param_1,longlong param_2,undefined4 param_3,undefined8 param_4)

{
  bool bVar1;
  ulonglong uVar2;
  undefined1 auStackY_158 [32];
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0 [2];
  ulonglong local_c8;
  ulonglong local_c0 [3];
  undefined8 local_a8 [4];
  ulonglong *local_88;
  undefined8 local_80;
  ulonglong *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  longlong local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  ulonglong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_158;
  uVar2 = (ulonglong)*(uint *)(param_2 + 8);
  if (*(uint *)(param_2 + 8) == 2) {
    if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
      McTemplateK0qqqqqqqqqxpj_EtwWriteTransfer(2);
    }
    if (5 < DAT_1400090c8) {
      if (((_DAT_1400090d8 & 0x400000000000) == 0) ||
         (bVar1 = true, (DAT_1400090e0 & 0x400000000000) != DAT_1400090e0)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_c8 = (ulonglong)*(uint *)(param_2 + 0x18);
        local_88 = &local_c8;
        local_c0[0] = (ulonglong)*(uint *)(param_2 + 0x14);
        local_78 = local_c0;
        local_d8 = *(undefined4 *)(param_2 + 0x1c);
        local_68 = &local_d8;
        local_58 = param_2 + 0x30;
        local_d4 = *(undefined4 *)(param_2 + 8);
        local_48 = &local_d4;
        local_38 = local_d0;
        local_28 = local_c0 + 1;
        local_80 = 8;
        local_70 = 8;
        local_60 = 4;
        local_50 = 0x10;
        local_40 = 4;
        local_30 = 4;
        local_c0[1] = 0x1000000;
        local_20 = 8;
        local_d0[0] = param_3;
        _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140007e70,0x400000000000,param_4,9,local_a8);
      }
    }
  }
  else if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
    McTemplateK0qqqqq_EtwWriteTransfer(uVar2);
  }
  return;
}



===== ForwardLegacyPowerNotifications @ 140011e2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ForwardLegacyPowerNotifications(undefined8 *param_1,undefined8 param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_3;
  ValidateGenericPowerSource((ulonglong *)(param_3 + 4));
  bVar1 = *(byte *)(puVar3 + 2);
  if (bVar1 == 0) {
    if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
      McTemplateK0q_EtwWriteTransfer(0,param_2,puVar3,*puVar3);
    }
  }
  else if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
    McTemplateK0qqqqj_EtwWriteTransfer
              ((ulonglong)bVar1,&StartCharging,puVar3,*puVar3,(char)puVar3[1],(char)puVar3[4],bVar1,
               puVar3 + 6);
  }
  if ((*(char *)((longlong)param_1 + 0x14) == '\0') ||
     ((*(longlong *)(param_3 + 6) == 0 && (*(longlong *)(param_3 + 8) == 0)))) {
    if (*(char *)((longlong)param_1 + 0x15) == '\0') {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,*param_1,0,0x298048);
    }
    else {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,*param_1,0);
    }
  }
  else {
    iVar2 = BatterySetChargerId(param_1,param_3 + 6);
  }
  if ((iVar2 < 0) && ((Microsoft_Windows_Power_CADEnableBits & 2) != 0)) {
    McTemplateK0sqd_EtwWriteTransfer();
  }
  return iVar2;
}



===== ForwardPowerNotification @ 140012020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint ForwardPowerNotification(undefined8 *param_1,undefined8 param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 local_28;
  undefined4 *local_20;
  undefined8 local_18;
  
  local_28 = 1;
  uVar5 = 0x298048;
  *param_3 = *(undefined4 *)(param_1 + 2);
  param_3[1] = 5;
  local_18 = 0x40;
  uVar2 = WdfDriverGlobals;
  local_20 = param_3;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,*param_1,0,0x298048,&local_28,0,0,0);
  uVar4 = (ulonglong)uVar1;
  puVar3 = param_3;
  EventWriteNotifyBatteryChargerStatus(uVar2,(longlong)param_3,uVar1,uVar5);
  if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
    McTemplateK0qqqq_EtwWriteTransfer
              ((ulonglong)(uint)param_3[1],puVar3,uVar4,*param_3,(char)param_3[1],(char)param_3[2],
               (char)uVar1);
  }
  return uVar1;
}



===== GetKdType @ 1400120d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 GetKdType(void)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined8 in_R9;
  undefined2 local_res8 [4];
  longlong local_res10;
  undefined8 local_18;
  longlong local_10;
  
  local_18 = 0x4000000;
  uVar3 = 3;
  local_res10 = 0;
  local_res8[0] = 0;
  local_10 = ExAllocatePool2(0x40,0x400,0x2e444143);
  if (local_10 == 0) {
    _WPOutputDebugMessage(2,0x4000,"ExAllocatePool2 failed\r\n",in_R9);
  }
  else {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                      (WdfDriverGlobals,0,&KdKeyPath,0x20019,0,&local_res10);
    if ((int)uVar1 < 0) {
      pcVar4 = "WdfRegistryOpenKey failed with 0x%x\r\n";
    }
    else {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x770))
                        (WdfDriverGlobals,local_res10,&KdKeyName,local_res8,&local_18);
      if (-1 < (int)uVar1) {
        lVar2 = RtlFindUnicodeSubstring(&local_18,&KdTypeNet,0);
        if (lVar2 == 0) {
          lVar2 = RtlFindUnicodeSubstring(&local_18,&KdTypeUSB,0);
          if (lVar2 == 0) {
            lVar2 = RtlFindUnicodeSubstring(&local_18,&KdTypeCOM,0);
            uVar3 = 3;
            if (lVar2 != 0) {
              uVar3 = 2;
            }
          }
          else {
            uVar3 = 1;
          }
        }
        else {
          uVar3 = 0;
        }
        goto LAB_14001223b;
      }
      pcVar4 = "WdfRegistryQueryUnicodeString failed with 0x%x\r\n";
    }
    _WPOutputDebugMessage(2,0x4000,pcVar4,(ulonglong)uVar1);
  }
LAB_14001223b:
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if (local_10 != 0) {
    ExFreePoolWithTag(local_10,0);
  }
  return uVar3;
}



===== GetStickyDisableChargingWnfState @ 140012290 =====

void GetStickyDisableChargingWnfState(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  ulonglong uVar4;
  byte local_res8 [8];
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  ulonglong local_res20;
  
  local_res18[0] = 0;
  local_res8[0] = 0;
  local_res10[0] = 1;
  local_res20 = 8;
  uVar1 = ZwQuerySystemInformation(0x67,&local_res20,8,0);
  uVar4 = (ulonglong)uVar1;
  uVar2 = 2;
  if (((int)uVar1 < 0) || ((local_res20 & 0x200000000) == 0)) {
    pcVar3 = "Test signing not enabled, return immediately 0x%x\r\n";
  }
  else {
    uVar1 = ZwQueryWnfStateData(&WNF_PO_CAD_STICKY_DISABLE_CHARGING,0,0,local_res18,local_res8,
                                local_res10);
    uVar4 = (ulonglong)uVar1;
    if (((uVar1 + 0x80000000 & 0x80000000) == 0) && (uVar1 != 0xc0000034)) {
      pcVar3 = "ZwQueryWnfStateData for WNF_PO_CAD_STICKY_DISABLE_CHARGING 0x%x\r\n";
    }
    else {
      uVar4 = (ulonglong)local_res8[0];
      pcVar3 = "StickyDisableChargingWnfState = %d\r\n";
      uVar2 = 4;
    }
  }
  _WPOutputDebugMessage(uVar2,0x4000,pcVar3,uVar4);
  *(byte *)(param_1 + 0xc) = local_res8[0];
  return;
}



===== NotifyAllBatteryDrivers @ 140012370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint NotifyAllBatteryDrivers(undefined8 *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar2 = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,*param_1);
  (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar3);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,param_1[0x1f]);
  uVar6 = 0;
  if (uVar1 != 0) {
    do {
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,param_1[0x1f],uVar6);
      puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,uVar3,0);
      uVar2 = NotifyOneBatteryDriver((longlong)param_1,puVar4,param_2,param_3,1);
      if ((int)uVar2 < 0) {
        uVar5 = uVar2;
        break;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar1);
  }
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,*param_1);
  (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar3);
  *(uint *)(param_1 + 3) = uVar5;
  *(int *)(param_1 + 2) = param_3;
  *(uint *)((longlong)param_1 + 0x14) = param_2;
  return uVar2;
}



===== NotifyOneBatteryDriver @ 1400124dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint NotifyOneBatteryDriver
               (longlong param_1,undefined8 *param_2,uint param_3,int param_4,int param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong lVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  uint local_b0;
  undefined8 local_a8;
  ulonglong uStack_a0;
  longlong local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined4 local_78 [2];
  undefined4 local_70;
  uint local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined8 local_58;
  longlong local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  local_88 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  uVar3 = 0;
  local_98 = 0;
  uStack_90 = 0;
  memset(local_78,0,0x40);
  if (param_4 == 6) {
    if (1 < param_3) {
      if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) {
        return 0xc000000d;
      }
      local_b0 = 0xc000000d;
      local_b8 = 0x9f9;
      goto LAB_140012846;
    }
LAB_140012577:
    if (*(int *)(param_1 + 0x20) == 1) {
      if (*(int *)(param_1 + 0x24) == 5) {
        if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
          McTemplateK0z_EtwWriteTransfer();
        }
        piVar5 = (int *)(param_1 + 0x60);
      }
      else {
        if (*(int *)(param_1 + 0x24) != 2) goto LAB_14001272f;
        if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
          McTemplateK0z_EtwWriteTransfer();
        }
        piVar5 = (int *)(param_1 + 0x28);
      }
      if (piVar5 != (int *)0x0) {
        uVar1 = *(undefined8 *)(piVar5 + 9);
        uVar2 = *(undefined8 *)(piVar5 + 0xb);
        puVar6 = local_78;
        for (lVar4 = 0x40; lVar4 != 0; lVar4 = lVar4 + -1) {
          *(undefined1 *)puVar6 = 0;
          puVar6 = (undefined4 *)((longlong)puVar6 + 1);
        }
        local_68 = 0;
        local_64 = piVar5[3];
        local_5c = piVar5[5];
        local_60 = piVar5[4];
        local_58 = *(undefined8 *)(piVar5 + 6);
        local_50 = (longlong)piVar5[8];
        local_70 = 2;
        if (local_5c == 1) {
          if (*piVar5 == 2) {
            local_68 = 1;
          }
          else if (*piVar5 == 5) {
            local_68 = piVar5[2] & 2;
          }
        }
        local_48 = uVar1;
        uStack_40 = uVar2;
        if (param_3 == 1) {
          local_60 = 0;
          local_64 = 0;
          local_48 = 0;
          uStack_40 = 0;
        }
        uVar3 = ForwardPowerNotification(param_2,piVar5,local_78);
        if (((int)uVar3 < 0) && (param_5 == 1)) {
          if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) {
            return uVar3;
          }
          local_b8 = 0xa4b;
          local_b0 = uVar3;
          goto LAB_140012846;
        }
      }
    }
    else if (*(int *)(param_1 + 0x20) == 0) {
      if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
        McTemplateK0z_EtwWriteTransfer();
      }
      puVar7 = &local_a8;
      for (lVar4 = 0x28; lVar4 != 0; lVar4 = lVar4 + -1) {
        *(undefined1 *)puVar7 = 0;
        puVar7 = (undefined8 *)((longlong)puVar7 + 1);
      }
      if (param_3 == 1) {
        local_a8 = CONCAT44(local_a8._4_4_,2);
      }
      else {
        local_a8 = CONCAT44(*(int *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x28));
        if (((*(int *)(param_1 + 0x34) != 0) || (*(longlong *)(param_1 + 0x4c) != 0)) ||
           (uStack_a0 = uStack_a0 & 0xffffffffffffff00, *(longlong *)(param_1 + 0x54) != 0)) {
          uStack_a0 = CONCAT71(uStack_a0._1_7_,1);
        }
        uStack_90 = *(undefined8 *)(param_1 + 0x4c);
        local_88 = *(undefined8 *)(param_1 + 0x54);
        local_98 = (longlong)*(int *)(param_1 + 0x48);
      }
      uVar3 = ForwardLegacyPowerNotifications(param_2,2,(undefined4 *)&local_a8);
      if (((int)uVar3 < 0) && (param_5 == 1)) {
        if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) {
          return uVar3;
        }
        local_b8 = 0xa7c;
        local_b0 = uVar3;
        goto LAB_140012846;
      }
    }
  }
  else if ((param_4 == 2) || (param_4 == 5)) goto LAB_140012577;
LAB_14001272f:
  if ((param_4 == 3) || (param_4 == 6)) {
    if (param_3 == 2) {
LAB_140012767:
      puVar7 = (undefined8 *)(param_1 + 0x98);
    }
    else {
      if (*(char *)(param_1 + 0xa0) == '\0') goto LAB_1400127a0;
      if (param_3 != 1) goto LAB_140012767;
      puVar7 = &local_a8;
      puVar8 = &local_a8;
      for (lVar4 = 0x28; lVar4 != 0; lVar4 = lVar4 + -1) {
        *(undefined1 *)puVar8 = 0;
        puVar8 = (undefined8 *)((longlong)puVar8 + 1);
      }
      local_a8 = CONCAT44(local_a8._4_4_,3);
    }
    uVar3 = ForwardLegacyPowerNotifications(param_2,3,(undefined4 *)puVar7);
    if (((int)uVar3 < 0) && (param_5 == 1)) {
      if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) {
        return uVar3;
      }
      local_b8 = 0xa9d;
      local_b0 = uVar3;
      goto LAB_140012846;
    }
  }
LAB_1400127a0:
  if (*(char *)(param_1 + 200) == '\0') {
    return uVar3;
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    return uVar3;
  }
  if (*(longlong *)(param_1 + 0x4c) != 0) {
    return uVar3;
  }
  if (*(longlong *)(param_1 + 0x54) != 0) {
    return uVar3;
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    return uVar3;
  }
  if (*(longlong *)(param_1 + 0x84) != 0) {
    return uVar3;
  }
  if (*(longlong *)(param_1 + 0x8c) != 0) {
    return uVar3;
  }
  if (*(char *)(param_1 + 0xa0) != '\0') {
    return uVar3;
  }
  if (param_3 == 1) {
    puVar7 = &local_a8;
    puVar8 = &local_a8;
    for (lVar4 = 0x28; lVar4 != 0; lVar4 = lVar4 + -1) {
      *(undefined1 *)puVar8 = 0;
      puVar8 = (undefined8 *)((longlong)puVar8 + 1);
    }
    local_a8 = CONCAT44(local_a8._4_4_,4);
  }
  else {
    puVar7 = (undefined8 *)(param_1 + 0xc0);
  }
  local_b0 = ForwardLegacyPowerNotifications(param_2,2,(undefined4 *)puVar7);
  if (-1 < (int)local_b0) {
    return local_b0;
  }
  if (param_5 != 1) {
    return local_b0;
  }
  if ((Microsoft_Windows_Power_CADEnableBits & 2) == 0) {
    return local_b0;
  }
  local_b8 = 0xab9;
LAB_140012846:
  uVar3 = local_b0;
  McTemplateK0sqd_EtwWriteTransfer();
  return uVar3;
}



===== PowerSourceUpdateKd @ 140012884 =====

void PowerSourceUpdateKd(longlong param_1)

{
  if ((((((*KdDebuggerEnabled_exref != (code)0x0) && (*(int *)(param_1 + 0xe8) != 2)) &&
        (*(int *)(param_1 + 0x34) == 0)) &&
       ((*(longlong *)(param_1 + 0x4c) == 0 && (*(longlong *)(param_1 + 0x54) == 0)))) &&
      ((*(int *)(param_1 + 0x6c) == 0 &&
       ((*(longlong *)(param_1 + 0x84) == 0 && (*(longlong *)(param_1 + 0x8c) == 0)))))) &&
     ((*(char *)(param_1 + 200) == '\0' && (*(char *)(param_1 + 0xa0) == '\0')))) {
    *(undefined1 *)(param_1 + 200) = 1;
  }
  return;
}



===== PowerSourceUpdateUsb @ 1400128f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PowerSourceUpdateUsb(undefined8 *param_1,ulonglong param_2,undefined8 param_3)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int *local_res10;
  
  local_res10 = (int *)0x0;
  uVar7 = 0x38;
  if (param_2 < 0x38) {
    iVar4 = -0x3ffffff3;
  }
  else {
    uVar6 = WdfDriverGlobals;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_3,0x38,&local_res10,0);
    if (-1 < iVar4) {
      if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
        McTemplateK0qhqqqqxqj_EtwWriteTransfer
                  (uVar6,param_3,uVar7,*local_res10,(char)local_res10[1],(char)local_res10[2],
                   (char)local_res10[3],(char)local_res10[4],(char)local_res10[5],
                   (char)*(undefined8 *)(local_res10 + 6),(char)local_res10[8],local_res10 + 9);
      }
      if ((short)local_res10[1] == 0) {
        if (*local_res10 == 2) {
          lVar5 = 0x28;
LAB_140012a35:
          piVar1 = (int *)(lVar5 + (longlong)param_1);
          if ((*(char *)((longlong)param_1 + 0x1c) == '\0') ||
             (bVar2 = CompareUsbPowerSourceUpdateEx(piVar1,local_res10), bVar2)) {
            if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
              McTemplateK0z_EtwWriteTransfer();
            }
          }
          else {
            uVar6 = *(undefined8 *)(local_res10 + 2);
            *(undefined8 *)piVar1 = *(undefined8 *)local_res10;
            *(undefined8 *)(piVar1 + 2) = uVar6;
            uVar6 = *(undefined8 *)(local_res10 + 6);
            *(undefined8 *)(piVar1 + 4) = *(undefined8 *)(local_res10 + 4);
            *(undefined8 *)(piVar1 + 6) = uVar6;
            uVar6 = *(undefined8 *)(local_res10 + 10);
            *(undefined8 *)(piVar1 + 8) = *(undefined8 *)(local_res10 + 8);
            *(undefined8 *)(piVar1 + 10) = uVar6;
            *(undefined8 *)(piVar1 + 0xc) = *(undefined8 *)(local_res10 + 0xc);
            cVar3 = ArbitrateUsbNotification((longlong)param_1,piVar1);
            if ((cVar3 != '\0') && (*(int *)(param_1 + 1) < 1)) {
              if ((piVar1[3] != 0) ||
                 ((*(longlong *)(piVar1 + 9) != 0 || (*(longlong *)(piVar1 + 0xb) != 0)))) {
                uVar7 = 0;
                KeSetEvent(param_1 + 0x21,0);
                *(undefined1 *)(param_1 + 0x19) = 0;
              }
              PowerSourceUpdateKd((longlong)param_1);
              if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
                if (((piVar1[3] != 0) || (*(longlong *)(piVar1 + 9) != 0)) ||
                   (uVar6 = 0, *(longlong *)(piVar1 + 0xb) != 0)) {
                  uVar6 = 1;
                }
                McTemplateK0qqqqj_EtwWriteTransfer
                          (uVar6,&NotifyBatteryDriver,uVar7,*piVar1,(char)piVar1[3],(char)piVar1[8],
                           (char)uVar6,piVar1 + 9);
              }
              NotifyAllBatteryDrivers(param_1,2,*piVar1);
              if (piVar1[3] != 0) {
                return iVar4;
              }
              if (*(longlong *)(piVar1 + 9) != 0) {
                return iVar4;
              }
              if (*(longlong *)(piVar1 + 0xb) != 0) {
                return iVar4;
              }
              if (*(int *)((longlong)param_1 + 0x24) == *piVar1) {
                ResetUsbConnectionState(*piVar1,(longlong)param_1);
                return iVar4;
              }
              return iVar4;
            }
          }
          return 0;
        }
        if (*local_res10 == 5) {
          lVar5 = 0x60;
          goto LAB_140012a35;
        }
      }
      iVar4 = -0x3ffffff3;
    }
  }
  if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
    McTemplateK0sqd_EtwWriteTransfer();
  }
  return iVar4;
}



===== PowerSourceUpdateWireless @ 140012be0 =====

undefined8 PowerSourceUpdateWireless(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  int *piVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong *puVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  
  puVar4 = param_2 + 2;
  puVar5 = param_2;
  ValidateGenericPowerSource(puVar4);
  if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
    McTemplateK0qqqqj_EtwWriteTransfer
              (puVar4,&UpdateChargingSource,param_3,*(undefined4 *)puVar5,
               (char)*(undefined4 *)((longlong)puVar5 + 4),(char)*puVar4,*(undefined1 *)(puVar5 + 1)
               ,puVar5 + 3);
  }
  if ((*(char *)(param_2 + 1) != '\0') &&
     (((*(int *)((longlong)param_2 + 4) != 0 || (puVar5[3] != 0)) || (puVar5[4] != 0)))) {
    KeSetEvent(param_1 + 0x21,0,0);
  }
  piVar1 = (int *)(param_1 + 0x13);
  uVar6 = 0x28;
  lVar3 = RtlCompareMemory(piVar1,param_2);
  if (lVar3 != 0x28) {
    uVar2 = param_2[1];
    *(undefined8 *)piVar1 = *param_2;
    param_1[0x14] = uVar2;
    uVar2 = param_2[3];
    param_1[0x15] = param_2[2];
    param_1[0x16] = uVar2;
    param_1[0x17] = param_2[4];
    if ((*(int *)(param_1 + 1) < 1) || (*(int *)((longlong)param_1 + 0x9c) == 0)) {
      PowerSourceUpdateKd((longlong)param_1);
      if ((Microsoft_Windows_Power_CADEnableBits & 4) != 0) {
        McTemplateK0qqqqj_EtwWriteTransfer
                  ((ulonglong)*(byte *)(param_1 + 0x14),&NotifyBatteryDriver,uVar6,*piVar1,
                   (char)*(undefined4 *)((longlong)param_1 + 0x9c),
                   (char)*(undefined4 *)(param_1 + 0x15),*(byte *)(param_1 + 0x14),param_1 + 0x16);
      }
      NotifyAllBatteryDrivers(param_1,2,*piVar1);
    }
  }
  return 0;
}



===== ResetUsbConnectionState @ 140012d38 =====

void ResetUsbConnectionState(int param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x20) == 1) {
    if (param_1 != 5) {
      if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
        McTemplateK0z_EtwWriteTransfer();
      }
      *(undefined4 *)(param_2 + 0x28) = 0;
      *(undefined4 *)(param_2 + 0x3c) = 2;
      return;
    }
    if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
      McTemplateK0z_EtwWriteTransfer();
    }
  }
  else {
    if (*(int *)(param_2 + 0x20) == 0) {
      if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
        McTemplateK0z_EtwWriteTransfer();
      }
      *(undefined4 *)(param_2 + 0x28) = 0;
      *(undefined4 *)(param_2 + 0x3c) = 2;
      goto LAB_140012dd7;
    }
    if ((Microsoft_Windows_Power_CADEnableBits & 1) != 0) {
      McTemplateK0z_EtwWriteTransfer();
    }
    *(undefined4 *)(param_2 + 0x28) = 0;
    *(undefined4 *)(param_2 + 0x3c) = 2;
  }
  *(undefined4 *)(param_2 + 0x60) = 0;
  *(undefined4 *)(param_2 + 0x74) = 2;
LAB_140012dd7:
  *(undefined4 *)(param_2 + 0x24) = 1;
  return;
}



===== SendChargeSourceChangeNotificationRequestASync @ 140012dec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SendChargeSourceChangeNotificationRequestASync(undefined8 param_1)

{
  char cVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  char *pcVar5;
  
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_1,0);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                    (WdfDriverGlobals,*puVar3,puVar3[3],0x294050,0,0,puVar3[4],0);
  uVar4 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
      McTemplateK0sqd_EtwWriteTransfer();
    }
    pcVar5 = "NON-FATAL: Failed to format request for source change notification: 0x%x\r\n";
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,puVar3[3],CADSourceChangeCompletionRoutine,param_1);
    *(undefined4 *)(puVar3 + 5) = 0xffffffff;
    cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,puVar3[3],*puVar3,0);
    if (cVar1 != '\0') {
      return uVar4;
    }
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,puVar3[3]);
    uVar4 = (ulonglong)uVar2;
    if ((Microsoft_Windows_Power_CADEnableBits & 2) != 0) {
      McTemplateK0sqd_EtwWriteTransfer();
    }
    pcVar5 = "NON-FATAL: Failed to send request for source change notification: 0x%x\r\n";
  }
  _WPOutputDebugMessage(2,0x4000,pcVar5,uVar4);
  return uVar4;
}



===== TranslatePowerSourceInfoUsbToStatus @ 140012f60 =====

void TranslatePowerSourceInfoUsbToStatus
               (longlong param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  bool bVar3;
  
  uVar2 = 0;
  if (param_3 == 0) {
    bVar3 = *(int *)(param_1 + 0x3c) == 0;
LAB_140012f7d:
    if (!bVar3) goto LAB_140012fd5;
    puVar1 = (undefined4 *)(param_1 + 0x28);
  }
  else {
    if (param_3 != 1) goto LAB_140012fd5;
    if (param_2 == 2) {
      bVar3 = *(int *)(param_1 + 0x3c) == 1;
      goto LAB_140012f7d;
    }
    if ((param_2 != 5) || (*(int *)(param_1 + 0x74) != 1)) goto LAB_140012fd5;
    puVar1 = (undefined4 *)(param_1 + 0x60);
  }
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)param_4 = *puVar1;
    *(undefined4 *)((longlong)param_4 + 4) = puVar1[3];
    *(undefined4 *)(param_4 + 1) = puVar1[8];
    if (((puVar1[3] != 0) || (*(longlong *)(puVar1 + 9) != 0)) || (*(longlong *)(puVar1 + 0xb) != 0)
       ) {
      uVar2 = 1;
    }
    *(undefined1 *)((longlong)param_4 + 0xc) = uVar2;
    return;
  }
LAB_140012fd5:
  *param_4 = 0;
  param_4[1] = 0;
  return;
}



===== UpdateChargingPolicy @ 140012fe4 =====

undefined8 UpdateChargingPolicy(undefined8 *param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == '\0') {
    if (*(int *)(param_1 + 1) < 1) {
      return 0;
    }
    iVar1 = -1;
  }
  else {
    iVar1 = 1;
  }
  iVar1 = iVar1 + *(int *)(param_1 + 1);
  *(int *)(param_1 + 1) = iVar1;
  if (param_2 == '\0') {
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = 0;
  }
  else {
    if (iVar1 != 1) {
      return 0;
    }
    uVar2 = 1;
  }
  NotifyAllBatteryDrivers(param_1,uVar2,6);
  return 0;
}



===== _tlgEnableCallback @ 140013040 =====

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



===== wil_details_EvaluateFeatureDependencies @ 1400130bc =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_CADBufferValidation__private_descriptor;
  ppuVar2 = &Feature_CADBufferValidation__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x0001400130f7;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140013171:
  while( true ) {
    if (&UNK_140008d47 < ppuVar3) {
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
      if (&UNK_140008d47 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x0001400130f7:
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
      if (&UNK_140008d47 < ppuVar2) goto LAB_140013171;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140013171;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400131ac =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140013244;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140013244;
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
LAB_140013244:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140013290 =====

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
      for (ppuVar2 = &Feature_CADBufferValidation__private_descriptor;
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
              if (&UNK_140008d47 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140013310 =====

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
  for (ppuVar3 = &Feature_CADBufferValidation__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001340d;
  }
LAB_140013416:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001340d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140013416;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1400133de:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1400133de;
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
    if (&UNK_140008d47 < ppuVar3) goto LAB_140013416;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001340d;
}



===== __security_init_cookie @ 140014008 =====

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



===== DriverEntry @ 14001403c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  code *local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_24 = 0;
  wil_InitializeFeatureStaging();
  McGenEventRegister_EtwRegister();
  local_24 = 0;
  local_10 = 0;
  local_20 = CADEvtDeviceAdd;
  local_28 = 0x20;
  local_18 = CADDriverUnload;
  local_c = 0x2e444143;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_28,0);
  if ((((iVar1 < 0) || (iVar1 = CadLockInitialize(&CadInitializationLock), iVar1 < 0)) ||
      (iVar1 = IoReportRootDevice(param_1), iVar1 < 0)) &&
     ((Microsoft_Windows_Power_CADEnableBits & 2) != 0)) {
    McTemplateK0sqd_EtwWriteTransfer();
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 140014154 =====

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
    for (ppuVar3 = &Feature_CADBufferValidation__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400141db;
    }
LAB_140014215:
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
LAB_1400141db:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140014215;
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
    goto LAB_140014215;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140008d47 < ppuVar3) goto LAB_140014215;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400141db;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140014268 =====

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
  ppuVar4 = &Feature_CADBufferValidation__private_descriptor;
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
            if (&UNK_140008d47 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140014352;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140014352;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140014352:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140008d47 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


