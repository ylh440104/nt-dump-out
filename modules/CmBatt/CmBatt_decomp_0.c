
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



===== memcpy_s @ 140001020 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_14000103d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_14000107f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memmove(_Dst,_Src,_MaxCount);
        goto LAB_14000103d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_14000107f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== __cpu_features_init @ 1400010c0 =====

/* WARNING: Removing unreachable block (ram,0x00014000112a) */
/* WARNING: Removing unreachable block (ram,0x0001400010d9) */
/* WARNING: Removing unreachable block (ram,0x0001400010ca) */

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



===== CmBattSetCoolingPercentage @ 140001188 =====

void CmBattSetCoolingPercentage(longlong param_1,char param_2)

{
  if (*(int *)(param_1 + 0x688) != *(int *)(param_1 + 0x68c)) {
    *(int *)(param_1 + 0x688) = *(int *)(param_1 + 0x68c);
    if (param_2 == '\0') {
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(param_1 + 0x150,0);
    }
    if (*(char *)(param_1 + 0x148) == '\0') {
      CmBattSetThrottle(param_1,*(undefined4 *)(param_1 + 0x688));
    }
    if (param_2 == '\0') {
      ExReleasePushLockSharedEx(param_1 + 0x150,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== CmBattVerifyStaData @ 14000122c =====

undefined8 CmBattVerifyStaData(longlong param_1)

{
  uint *puVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  puVar1 = (uint *)(param_1 + 0x66c);
  cVar2 = *(char *)(param_1 + 0x170);
  while (cVar2 != '\0') {
    *(undefined1 *)(param_1 + 0x170) = 0;
    uVar3 = CmBattGetStaData(param_1,puVar1);
    if ((int)uVar3 < 0) {
      *puVar1 = 0;
    }
    cVar2 = *(char *)(param_1 + 0x170);
  }
  if ((*puVar1 & 0x10) == 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 0x6d0,0);
    *(undefined4 *)(param_1 + 400) = 0;
    ExReleasePushLockExclusiveEx(param_1 + 0x6d0,0);
    KeLeaveCriticalRegion();
    uVar4 = 0xc000000e;
  }
  return uVar4;
}



===== Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline @ 1400012dc =====

ulonglong Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_EE_MPTF_Functionality__private_featureState;
  if ((Feature_EE_MPTF_Functionality__private_featureState & 0x10) == 0) {
    uVar1 = Feature_EE_MPTF_Functionality__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_EE_MPTF_Functionality__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_EE_MPTF_Functionality__private_IsEnabledFallback @ 140001314 =====

void Feature_EE_MPTF_Functionality__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_EE_MPTF_Functionality__private_descriptor);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001330 =====

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
LAB_140001539:
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
LAB_14000140b:
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
      if (param_3 == 4) goto LAB_140001539;
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
        goto LAB_14000140b;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140001624 =====

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
      goto LAB_1400016f5;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_1400016f5;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_1400016f5;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_1400016f5;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_1400016f5;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_1400016f5;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_1400016f5;
    }
  }
  uVar3 = 0xff;
LAB_1400016f5:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000174c =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000183c =====

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
LAB_1400018ef:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_14000191d;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_1400018ef;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_14000191d:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140001aa8 =====

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



===== wil_details_IsEnabledFallback @ 140001b0c =====

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



===== wil_details_RecordCachedUsage @ 140001ba0 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001d00 =====

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



===== CmBattWatchdogDispatch @ 140001d90 =====

void CmBattWatchdogDispatch(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_2 + 0x6c4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 == 0) {
    KeClearEvent(param_2 + 0x6a0);
    IoQueueWorkItem(*(undefined8 *)(param_2 + 0x698),CmBattWatchdogWork,1,param_2);
  }
  return;
}



===== CmBattDevicePowerIrpCompletion @ 140001df0 =====

undefined8 CmBattDevicePowerIrpCompletion(longlong param_1,undefined8 param_2)

{
  IoQueueWorkItem(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x160),
                  CmBattDevicePowerIrpCompletionWorker,1,param_2);
  return 0xc0000016;
}



===== CmBattDevicePowerRequestCompletion @ 140001e30 =====

void CmBattDevicePowerRequestCompletion
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               undefined4 *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined4 *)(param_4 + 0x30) = *param_5;
  IofCompleteRequest(param_4,0);
  IoReleaseRemoveLockEx(lVar1 + 0xc0,param_4,0x20);
  return;
}



===== CmBattEjectCoolingInterface @ 140001e8c =====

undefined8 CmBattEjectCoolingInterface(int *param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  
  if (*param_1 != 1) {
    return 0xc00000bb;
  }
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((*(ushort *)(lVar1 + 0x10) < 0x38) || (*(short *)(lVar1 + 0x12) == 0)) {
    return 0xc000000d;
  }
  puVar2 = *(undefined4 **)(lVar1 + 0x18);
  *(int **)(puVar2 + 2) = param_1;
  *(code **)(puVar2 + 4) = _guard_check_icall;
  *(code **)(puVar2 + 6) = _guard_check_icall;
  puVar2[8] = 0;
  *(undefined8 *)(puVar2 + 10) = 0;
  *puVar2 = 0x10038;
  *(code **)(puVar2 + 0xc) = CmBattCoolingNotification;
  return 0;
}



===== CmBattGetAcpiInterfaces @ 140001efc =====

int CmBattGetAcpiInterfaces(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined2 *)(lVar1 + -0x48) = 0x81b;
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined **)(lVar1 + -0x40) = &GUID_ACPI_INTERFACE_STANDARD2;
    *(undefined4 *)(lVar1 + -0x38) = 0x10058;
    *(undefined8 *)(lVar1 + -0x30) = param_2;
    KeInitializeEvent(&local_28,1,0);
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = CmBattIoCompletion;
    *(undefined8 **)(lVar1 + -8) = &local_28;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    iVar2 = IofCallDriver(param_1,lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = *(int *)(lVar3 + 0x30);
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== CmBattIoCompletion @ 140002010 =====

undefined8 CmBattIoCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== _guard_check_icall @ 140002040 =====

void _guard_check_icall(void)

{
  return;
}



===== CmBattPowerDispatch @ 140002050 =====

int CmBattPowerDispatch(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  if (*(char *)(*(longlong *)(param_2 + 0xb8) + 1) == '\x02') {
    iVar2 = CmBattSetPowerState(param_1,param_2);
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x40);
    if (*(longlong *)(lVar1 + 0x20) == 0) {
      iVar2 = *(int *)(param_2 + 0x30);
      IofCompleteRequest(param_2,0);
      return iVar2;
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x20));
  }
  return iVar2;
}



===== CmBattRemoveDevice @ 1400020c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CmBattRemoveDevice(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  piVar2 = *(int **)(param_1 + 0x40);
  if (*(longlong *)(piVar2 + 0x1a) != 0) {
    IoCancelIrp();
    piVar2[0x1a] = 0;
    piVar2[0x1b] = 0;
  }
  (**(code **)(piVar2 + 0x50))(*(undefined8 *)(piVar2 + 0x3e));
  (**(code **)(piVar2 + 0x42))(*(undefined8 *)(piVar2 + 0x3e));
  CmBattWmiDeRegistration((longlong)piVar2);
  puVar8 = auStack_28;
  if (*piVar2 == 1) {
    KeAcquireGuardedMutex(&DeviceObjectMutex);
    plVar1 = (longlong *)(piVar2 + 0x5e);
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) == plVar1) &&
       (plVar4 = *(longlong **)(piVar2 + 0x60), (longlong *)*plVar4 == plVar1)) {
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      KeReleaseGuardedMutex(&DeviceObjectMutex);
      BatteryClassUnload(*(undefined8 *)(piVar2 + 0x5a));
      if ((char)piVar2[0x1b2] != '\0') {
        CmBattStopWatchdog((longlong)piVar2);
      }
      if ((char)piVar2[0x1a0] == '\0') {
        return;
      }
      RtlFreeUnicodeString(piVar2 + 0x1b6);
      return;
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar8 = auStack_20;
  }
  *(undefined8 *)(puVar8 + -8) = 0x1400021af;
  uVar7 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 != 0) {
    uVar5 = *(undefined8 *)(AcAdapter + 0x168);
    *(undefined8 *)(puVar8 + -8) = 0x1400021c8;
    AdapterClassUnload(uVar5);
  }
  *(undefined8 *)(puVar8 + -8) = 0x1400021db;
  KeAcquireGuardedMutex(&DeviceObjectMutex);
  AcAdapter = 0;
  *(undefined8 *)(puVar8 + -8) = 0x1400021f6;
  KeReleaseGuardedMutex(&DeviceObjectMutex);
  return;
}



===== CmBattSetPowerState @ 140002208 =====

int CmBattSetPowerState(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  code *pcVar5;
  
  piVar1 = *(int **)(param_1 + 0x40);
  iVar4 = IoAcquireRemoveLockEx(piVar1 + 0x30,param_2,"",1,0x20);
  if (iVar4 < 0) {
    *(int *)(param_2 + 0x30) = iVar4;
    IofCompleteRequest(param_2);
    return iVar4;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar2 + 0x10) == 0) {
    pcVar5 = CmBattSystemPowerIrpCompletion;
LAB_14000232c:
    *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 1;
    puVar3 = *(undefined8 **)(param_2 + 0xb8);
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
    lVar2 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar2 + -0x10) = pcVar5;
    *(undefined8 *)(lVar2 + -8) = 0;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    IofCallDriver(*(undefined8 *)(piVar1 + 8),param_2);
    iVar4 = 0x103;
  }
  else {
    if (*(int *)(lVar2 + 0x10) == 1) {
      iVar4 = *(int *)(lVar2 + 0x18);
      if (iVar4 == 1) {
        pcVar5 = CmBattDevicePowerIrpCompletion;
        goto LAB_14000232c;
      }
      if ((*piVar1 == 1) && ((char)piVar1[0x1b2] != '\0')) {
        CmBattStopWatchdog((longlong)piVar1);
      }
      PoSetPowerState(param_1,1,iVar4);
      piVar1[0x57] = iVar4;
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(piVar1 + 0x54,0);
      *(undefined1 *)(piVar1 + 0x52) = 1;
      ExReleasePushLockExclusiveEx(piVar1 + 0x54,0);
      KeLeaveCriticalRegion();
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    }
    else {
      *(longlong *)(param_2 + 0xb8) = lVar2 + 0x48;
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    iVar4 = IofCallDriver(*(undefined8 *)(piVar1 + 8),param_2);
    IoReleaseRemoveLockEx(piVar1 + 0x30,param_2,0x20);
  }
  return iVar4;
}



===== CmBattSystemPowerIrpCompletion @ 1400023f0 =====

int CmBattSystemPowerIrpCompletion(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  *(int *)(lVar1 + 0x158) = iVar2;
  uVar3 = 1;
  if (iVar2 != 1) {
    uVar3 = 4;
  }
  iVar2 = PoRequestPowerIrp(param_1,2,uVar3,CmBattDevicePowerRequestCompletion,param_2,0);
  if (iVar2 < 0) {
    *(int *)(param_2 + 0x30) = iVar2;
    IoReleaseRemoveLockEx(lVar1 + 0xc0,param_2,0x20);
  }
  else {
    iVar2 = -0x3fffffea;
  }
  return iVar2;
}



===== CmBattWaitWakeLoop @ 140002490 =====

void CmBattWaitWakeLoop(longlong param_1)

{
  int *in_stack_00000028;
  
  if ((*in_stack_00000028 < 0) || (*(char *)(*(longlong *)(param_1 + 0x40) + 0xb8) == '\0')) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x68) = 0;
  }
  else {
    PoRequestPowerIrp();
  }
  return;
}



===== Feature_1178837306__private_IsEnabledDeviceUsageNoInline @ 1400024e4 =====

ulonglong Feature_1178837306__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1178837306__private_featureState;
  if ((Feature_1178837306__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1178837306__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1178837306__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1178837306__private_IsEnabledFallback @ 14000251c =====

void Feature_1178837306__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1178837306__private_descriptor);
  return;
}



===== CmBattNotifyHandler @ 140002540 =====

void CmBattNotifyHandler(int *param_1,int param_2)

{
  undefined8 *puVar1;
  
  if ((char)param_1[0x52] != '\0') {
    return;
  }
  if (*param_1 == 0) {
    if (param_2 != 0x80) {
      return;
    }
    KeAcquireGuardedMutex(&DeviceObjectMutex);
    for (puVar1 = BatteryListHead; (undefined8 **)puVar1 != &BatteryListHead;
        puVar1 = (undefined8 *)*puVar1) {
      if ((*(int *)(puVar1 + -0x2f) == 1) && (puVar1[-2] != 0)) {
        BatteryClassStatusNotify();
      }
    }
    KeReleaseGuardedMutex(&DeviceObjectMutex);
    return;
  }
  if (*param_1 != 1) {
    return;
  }
  if ((param_2 == 0) || (param_2 == 1)) {
LAB_1400025ed:
    LOCK();
    param_1[0x5d] = 0;
    UNLOCK();
  }
  else if (param_2 != 0x80) {
    if (param_2 != 0x81) goto LAB_140002614;
    goto LAB_1400025ed;
  }
  param_1[0x19a] = -1;
  *(undefined1 *)(param_1 + 0x5c) = 1;
  BatteryClassStatusNotify(*(undefined8 *)(param_1 + 0x5a));
LAB_140002614:
  CmBattTraceNotify((longlong)param_1,param_2);
  return;
}



===== CmBattNotifyHandlerV1 @ 140002640 =====

void CmBattNotifyHandlerV1(int *param_1,int param_2)

{
  undefined8 *puVar1;
  
  if ((char)param_1[0x52] != '\0') {
    return;
  }
  if (*param_1 == 0) {
    CmBattTraceNotify((longlong)param_1,param_2);
    if (param_2 == 0x80) {
      KeAcquireGuardedMutex(&DeviceObjectMutex);
      for (puVar1 = BatteryListHead; (undefined8 **)puVar1 != &BatteryListHead;
          puVar1 = (undefined8 *)*puVar1) {
        if ((*(int *)(puVar1 + -0x2f) == 1) && (puVar1[-2] != 0)) {
          BatteryClassStatusNotify();
        }
      }
      KeReleaseGuardedMutex(&DeviceObjectMutex);
    }
    else if ((1 < param_2 - 0x81U) && (param_2 != 0)) {
      return;
    }
    AdapterClassStatusNotify(*(undefined8 *)(param_1 + 0x5a));
    return;
  }
  if (*param_1 != 1) {
    return;
  }
  CmBattTraceNotify((longlong)param_1,param_2);
  if ((param_2 != 0) && (param_2 != 1)) {
    if (param_2 == 0x80) goto LAB_140002748;
    if (param_2 != 0x81) {
      if (param_2 != 0x83) {
        return;
      }
      if ((param_1[0x1be] & 0x20U) == 0) {
        return;
      }
      BatteryClassPeakPowerNotify(*(undefined8 *)(param_1 + 0x5a));
      return;
    }
  }
  LOCK();
  param_1[0x5d] = 0;
  UNLOCK();
LAB_140002748:
  param_1[0x19a] = -1;
  *(undefined1 *)(param_1 + 0x5c) = 1;
  BatteryClassStatusNotify(*(undefined8 *)(param_1 + 0x5a));
  return;
}



===== _tlgDefineProvider_annotation__TlgCmBattTraceHandleProv @ 140002788 =====

void _tlgDefineProvider_annotation__TlgCmBattTraceHandleProv(void)

{
  return;
}



===== __GSHandlerCheck @ 140002798 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400027bc =====

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



===== __security_check_cookie @ 140002830 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002870 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400028a0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400028a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400028d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002940 =====

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



===== memset @ 140002c40 =====

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



===== __memset_repmovs @ 140002d80 =====

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



===== __memset_query @ 140002e00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002e80 =====

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



===== __memset_spec_ermsb_repmovsb @ 140002fc0 =====

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



===== __memset_spec_plain @ 140003040 =====

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



===== CmBattCoolingNotification @ 14000a010 =====

void CmBattCoolingNotification(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x68c) = param_2;
  CmBattSetCoolingPercentage(param_1,'\0');
  return;
}



===== CmBattDisablePeakPowerNotify @ 14000a030 =====

int CmBattDisablePeakPowerNotify(longlong param_1)

{
  int iVar1;
  uint uVar2;
  int local_res8 [2];
  
  local_res8[0] = 0;
  if (((*(char *)(param_1 + 0x652) == '\0') || (*(char *)(param_1 + 0x6fc) == '\0')) ||
     (*(char *)(param_1 + 0x6fd) == '\0')) {
    iVar1 = -0x3fffff45;
  }
  else {
    if (*(char *)(param_1 + 0x651) == '\0') {
      return -0x3fffffcc;
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(param_1 + 0x150,0);
    if (*(char *)(param_1 + 0x148) == '\0') {
      iVar1 = CmBattSetBptData(local_res8,*(undefined8 *)(param_1 + 0x20),0,0);
      if (iVar1 < 0) {
        uVar2 = *(uint *)(param_1 + 0x6f8) | 0x10;
      }
      else {
        *(undefined4 *)(param_1 + 0x70c) = 0;
        uVar2 = *(uint *)(param_1 + 0x6f8) & 0xffffffef;
        *(undefined4 *)(param_1 + 0x708) = 0;
      }
      *(uint *)(param_1 + 0x6f8) = uVar2;
    }
    else {
      iVar1 = 0;
    }
    ExReleasePushLockSharedEx(param_1 + 0x150,0);
    KeLeaveCriticalRegion();
  }
  return iVar1;
}



===== CmBattDisableStatusNotify @ 14000a130 =====

int CmBattDisableStatusNotify(longlong param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x650) == '\0') {
    iVar1 = -0x3fffffcc;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(param_1 + 0x150);
    if ((*(char *)(param_1 + 0x148) == '\0') && (*(int *)(param_1 + 0x668) != 0)) {
      ExAcquirePushLockExclusiveEx(param_1 + 0x6d0);
      *(undefined4 *)(param_1 + 0x668) = 0;
      iVar1 = CmBattSetTripPpoint(param_1,0);
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x668) = 0xffffffff;
      }
      CmBattTraceBtp(param_1,'\0');
      ExReleasePushLockExclusiveEx(param_1 + 0x6d0,0);
    }
    else {
      iVar1 = 0;
    }
    ExReleasePushLockSharedEx(param_1 + 0x150,0);
    KeLeaveCriticalRegion();
  }
  return iVar1;
}



===== CmBattGetBatteryStatus @ 14000a220 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CmBattGetBatteryStatus(longlong param_1,char param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  int local_res10 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res10[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_2 == '\0') {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(param_1 + 0x150,0);
  }
  if (*(char *)(param_1 + 0x148) == '\0') {
    iVar6 = 0;
    if (param_3 != '\0') {
      if (_DAT_fffff78000000008 < *(longlong *)(param_1 + 0x678) + 10000000U) goto LAB_14000a27b;
      iVar6 = local_res10[0];
    }
    uVar3 = CmBattGetBstData(param_1,(uint *)&local_28);
    if ((int)uVar3 < 0) {
      uVar5 = 0xc000000e;
      LOCK();
      *(undefined4 *)(param_1 + 0x174) = 0;
      UNLOCK();
      *(undefined8 *)(param_1 + 0x678) = 0;
      goto LAB_14000a61f;
    }
    ExAcquirePushLockExclusiveEx(param_1 + 0x6d0);
    *(undefined8 *)(param_1 + 0x1c0) = local_28;
    *(undefined8 *)(param_1 + 0x1c8) = uStack_20;
    CmBattTraceBst(param_1,'\0');
    ExReleasePushLockExclusiveEx(param_1 + 0x6d0,0);
    uVar1 = *(uint *)(param_1 + 0x614);
    *(undefined8 *)(param_1 + 0x614) = 0;
    *(undefined8 *)(param_1 + 0x61c) = 0;
    uVar4 = *(uint *)(param_1 + 0x1c0);
    uVar2 = 0;
    if ((uVar4 & 4) != 0) {
      uVar2 = 8;
      *(undefined4 *)(param_1 + 0x614) = 8;
    }
    if ((uVar4 & 2) == 0) {
      if (((uVar4 & 1) != 0) && (*(uint *)(param_1 + 0x614) = uVar2 | 2, (uVar1 & 2) == 0)) {
        *(ulonglong *)(param_1 + 0x670) = _DAT_fffff78000000008;
        iVar6 = local_res10[0];
      }
    }
    else {
      *(uint *)(param_1 + 0x614) = uVar2 | 4;
    }
    KeAcquireGuardedMutexUnsafe(&DeviceObjectMutex);
    if (AcAdapter == 0) {
      if ((*(byte *)(param_1 + 0x1c0) & 1) == 0) {
        iVar6 = 1;
      }
    }
    else {
      ExAcquirePushLockSharedEx(AcAdapter + 0x150,0);
      uVar3 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 != 0) {
        iVar6 = *(int *)(AcAdapter + 0x178);
        local_res10[0] = iVar6;
      }
      if (*(char *)(AcAdapter + 0x148) == '\0') {
        uVar3 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 == 0) {
          CmBattGetPsrData(*(undefined8 *)(AcAdapter + 0x18),(undefined4 *)(AcAdapter + 0x178));
        }
        else {
          CmBattGetPsrDataV1(*(undefined8 *)(AcAdapter + 0x18),local_res10);
          iVar6 = local_res10[0];
        }
      }
      uVar3 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 == 0) {
        iVar6 = *(int *)(AcAdapter + 0x178);
      }
      ExReleasePushLockSharedEx(AcAdapter + 0x150,0);
    }
    KeReleaseGuardedMutexUnsafe();
    if (iVar6 == 1) {
      *(uint *)(param_1 + 0x614) = *(uint *)(param_1 + 0x614) | 1;
    }
    *(undefined4 *)(param_1 + 0x61c) = *(undefined4 *)(param_1 + 0x1cc);
    if (*(int *)(param_1 + 0x1d8) == 1) {
      if (*(int *)(param_1 + 0x1e8) - 1U < 0xfffffffe) {
        if (*(int *)(param_1 + 0x1c8) == -1) {
          if (*(int *)(param_1 + 0x618) != -1) {
            *(undefined4 *)(param_1 + 0x618) = 0xffffffff;
          }
        }
        else {
          *(uint *)(param_1 + 0x618) =
               (*(int *)(param_1 + 0x1c8) * *(int *)(param_1 + 0x1e8) + 500U) / 1000;
        }
        if ((*(uint *)(param_1 + 0x1c4) == 0xffffffff) ||
           ((uint)(0xfffffe0b / (ulonglong)*(uint *)(param_1 + 0x1e8)) < *(uint *)(param_1 + 0x1c4))
           ) {
          if (*(int *)(param_1 + 0x620) == -0x80000000) goto LAB_14000a5b5;
LAB_14000a568:
          *(undefined4 *)(param_1 + 0x620) = 0x80000000;
          uVar4 = 0x80000000;
        }
        else {
          uVar3 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
          if (((int)uVar3 == 0) || (0xfffffffd < *(int *)(param_1 + 0x1cc) - 1U)) {
            uVar4 = (uint)((ulonglong)(*(int *)(param_1 + 0x1e8) * *(int *)(param_1 + 0x1c4) + 500)
                           * 0x10624dd3 >> 0x20);
          }
          else {
            uVar4 = (uint)((ulonglong)(*(int *)(param_1 + 0x1cc) * *(int *)(param_1 + 0x1c4) + 500)
                           * 0x10624dd3 >> 0x20);
          }
          uVar4 = uVar4 >> 6;
          *(uint *)(param_1 + 0x620) = uVar4;
        }
      }
      else {
        uVar4 = *(uint *)(param_1 + 0x620);
        if (uVar4 == 0x80000000) goto LAB_14000a5b5;
        if (*(int *)(param_1 + 0x618) != -1) {
          *(undefined4 *)(param_1 + 0x618) = 0xffffffff;
          goto LAB_14000a568;
        }
      }
LAB_14000a525:
      if (uVar4 != 0x80000000) {
        if ((*(uint *)(param_1 + 0x614) & 2) == 0) {
          if (((*(uint *)(param_1 + 0x614) & 4) == 0) && (uVar4 != 0)) {
            *(undefined4 *)(param_1 + 0x620) = 0;
          }
        }
        else {
          *(uint *)(param_1 + 0x620) = -uVar4;
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x618) = *(undefined4 *)(param_1 + 0x1c8);
      uVar4 = *(uint *)(param_1 + 0x1c4);
      *(uint *)(param_1 + 0x620) = uVar4;
      if (*(uint *)(param_1 + 0x1c4) < 0x80000000) goto LAB_14000a525;
      *(undefined4 *)(param_1 + 0x620) = 0x80000000;
    }
LAB_14000a5b5:
    if (*(int *)(param_1 + 0x6c0) != 0) {
      uVar4 = *(uint *)(param_1 + 0x614) & 4;
      if ((uVar1 & 4) == 0) {
        if (uVar4 != 0) {
          *(undefined1 *)(param_1 + 0x6c8) = 1;
          CmBattStartWatchdog(param_1);
        }
      }
      else if (uVar4 == 0) {
        CmBattStopWatchdog(param_1);
        *(undefined1 *)(param_1 + 0x6c8) = 0;
      }
    }
    *(ulonglong *)(param_1 + 0x678) = _DAT_fffff78000000008;
  }
LAB_14000a27b:
  uVar5 = 0;
LAB_14000a61f:
  if (param_2 == '\0') {
    ExReleasePushLockSharedEx(param_1 + 0x150,0);
    KeLeaveCriticalRegion();
  }
  return uVar5;
}



===== CmBattIoctl @ 14000a670 =====

int CmBattIoctl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0xc0,param_2,"",1,0x20);
  if (iVar2 < 0) {
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
  }
  else {
    iVar2 = BatteryClassIoctl(*(undefined8 *)(lVar1 + 0x168),param_2);
    if (iVar2 == -0x3fffff45) {
      if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x294050) {
        *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
        IofCompleteRequest(param_2,0);
      }
      else {
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x20),param_2);
      }
    }
    IoReleaseRemoveLockEx(lVar1 + 0xc0,param_2,0x20);
  }
  return iVar2;
}



===== CmBattOpenClose @ 14000a780 =====

undefined4 CmBattOpenClose(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  pcVar2 = *(char **)(param_2 + 0xb8);
  uVar3 = 0;
  ExAcquireFastMutex(lVar1 + 0x28);
  if ((*pcVar2 == '\0') && (uVar3 = 0, *(char *)(lVar1 + 0x60) == '\0')) {
    uVar3 = 0xc000000e;
  }
  ExReleaseFastMutex(lVar1 + 0x28);
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== CmBattQueryAdapterStatus @ 14000a820 =====

ulonglong CmBattQueryAdapterStatus(undefined8 param_1,longlong *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  short *psVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 local_48;
  longlong lStack_30;
  longlong local_28;
  
  uVar5 = 0;
  KeAcquireGuardedMutex(&DeviceObjectMutex);
  if (AcAdapter == 0) {
    KeReleaseGuardedMutex();
    uVar5 = 0xc00000a3;
  }
  else {
    KeReleaseGuardedMutex(&DeviceObjectMutex);
    ExAcquirePushLockSharedEx(AcAdapter + 0x150,0);
    lVar6 = AcAdapter;
    if (*(char *)(AcAdapter + 0x148) == '\0') {
      uVar5 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
      psVar4 = (short *)(AcAdapter + 0x178);
      uVar3 = *(undefined8 *)(AcAdapter + 0x20);
      if ((int)uVar5 == 0) {
        uVar5 = CmBattGetPsrData(uVar3,(undefined4 *)psVar4);
        uVar1 = (uint)uVar5;
      }
      else {
        uVar5 = CmBattGetPsrDataV1(uVar3,(undefined4 *)psVar4);
        uVar1 = (uint)uVar5;
      }
      lVar6 = AcAdapter;
      uVar5 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        *(uint *)(AcAdapter + 0x174) = *(uint *)(AcAdapter + 0x174) | 1;
      }
      else {
        *(uint *)(AcAdapter + 0x174) = *(uint *)(AcAdapter + 0x174) & 0xfffffffe;
        if (*(int *)(lVar6 + 0x178) != 0) {
          uVar2 = AcAdapterGetRecStatus(uVar3,psVar4);
          lVar6 = AcAdapter;
          uVar5 = uVar2 & 0xffffffff;
          if ((int)uVar2 < 0) {
            *(undefined8 *)(AcAdapter + 0x490) = 0;
            *(undefined8 *)(lVar6 + 0x498) = 0;
            *(uint *)(lVar6 + 0x174) = *(uint *)(lVar6 + 0x174) | 4;
            *(undefined8 *)(lVar6 + 0x498) = 0xffffffffffffffff;
            *(undefined8 *)(lVar6 + 0x4a0) = 0xffffffffffffffff;
          }
          else {
            *(uint *)(AcAdapter + 0x174) = *(uint *)(AcAdapter + 0x174) & 0xfffffffb;
          }
        }
      }
      if ((*(uint *)(lVar6 + 0x170) & 1) != 0) {
        uVar2 = CmBattGetPifData((undefined4 *)(lVar6 + 0x17c),(undefined4 *)(lVar6 + 0x180),
                                 *(undefined8 *)(lVar6 + 0x20),'\0');
        lVar6 = AcAdapter;
        uVar5 = uVar2 & 0xffffffff;
        if ((int)uVar2 < 0) {
          *(uint *)(AcAdapter + 0x174) = *(uint *)(AcAdapter + 0x174) | 2;
          *(undefined4 *)(lVar6 + 0x17c) = 0xffffffff;
          *(undefined4 *)(lVar6 + 0x180) = 0xffffffff;
        }
        else {
          *(uint *)(AcAdapter + 0x174) = *(uint *)(AcAdapter + 0x174) & 0xfffffffd;
        }
      }
    }
    ExReleasePushLockSharedEx(lVar6 + 0x150,0);
    lVar6 = AcAdapter;
    local_48 = 0;
    if (((*(uint *)(AcAdapter + 0x174) & 5) == 0) && (*(int *)(AcAdapter + 0x178) != 0)) {
      local_48._4_4_ = 0;
      if (*(char *)(AcAdapter + 0x490) != '\0') {
        local_48._4_4_ = 2;
      }
      if (*(char *)(AcAdapter + 0x491) != '\0') {
        local_48._4_4_ = (-(uint)(*(char *)(AcAdapter + 0x490) != '\0') & 2) + 4;
      }
      local_48 = (ulonglong)local_48._4_4_ << 0x20;
      lStack_30 = *(longlong *)(AcAdapter + 0x498);
      local_28 = *(longlong *)(AcAdapter + 0x4a0);
    }
    else {
      lStack_30 = -1;
      local_28 = -1;
    }
    *param_2 = local_48;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = lStack_30;
    param_2[4] = local_28;
    *(undefined1 *)param_2 = 0;
    *(uint *)((longlong)param_2 + 4) =
         (uint)(*(int *)(lVar6 + 0x178) != 0) | *(uint *)((longlong)param_2 + 4) & 0xfffffffe;
    *(undefined4 *)(param_2 + 1) = *(undefined4 *)(lVar6 + 0x17c);
    *(undefined4 *)((longlong)param_2 + 0xc) = *(undefined4 *)(lVar6 + 0x17c);
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(lVar6 + 0x180);
  }
  return uVar5;
}



===== CmBattQueryInformation @ 14000aa90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CmBattQueryInformation
                    (longlong param_1,int param_2,int param_3,int param_4,void *param_5,uint param_6
                    ,uint *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  size_t _Size;
  uint *_Src;
  undefined1 auStack_398 [32];
  undefined8 local_378;
  uint *puStack_370;
  uint local_368 [2];
  undefined8 local_360;
  undefined8 uStack_358;
  uint local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  char local_338 [256];
  uint local_238 [128];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_398;
  local_378 = 0;
  puStack_370 = (uint *)0x0;
  local_360 = 0;
  uStack_358 = 0;
  uVar2 = CmBattVerifyTag(param_1,param_2);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  local_368[0] = 0;
  _Size = 0;
  uVar2 = 0;
  if (param_3 == 0) {
    _Size = 0x24;
    _Src = (uint *)(param_1 + 0x624);
    goto LAB_14000ad99;
  }
  if (param_3 == 1) {
    local_350 = *(uint *)(param_1 + 0x648);
    local_34c = *(undefined4 *)(param_1 + 0x638);
    local_348 = *(undefined4 *)(param_1 + 0x64c);
    local_344 = *(undefined4 *)(param_1 + 0x630);
    _Size = 0x10;
    _Src = &local_350;
    goto LAB_14000ad99;
  }
  if (param_3 == 2) goto LAB_14000ad50;
  if (param_3 == 3) {
    if (*(longlong *)(param_1 + 0x670) + 150000000U < _DAT_fffff78000000008) {
      CmBattGetBatteryStatus(param_1,'\0','\x01');
      if (param_4 == 0) {
        param_4 = *(int *)(param_1 + 0x620);
      }
      local_368[0] = 0xffffffff;
      if (((param_4 < 0) && (param_4 != -0x80000000)) && (*(int *)(param_1 + 0x618) != -1)) {
        local_368[0] = (uint)(*(int *)(param_1 + 0x618) * 0xe10) / (uint)-param_4;
      }
      else {
        if ((*(int *)(param_1 + 0x620) == -0x80000000) &&
           (uVar2 = 0, (*(byte *)(param_1 + 0x1c0) & 1) != 0)) {
          uVar2 = 0xc0000010;
        }
        if (*(int *)(param_1 + 0x618) == -1) {
          uVar2 = 0xc0000010;
        }
      }
    }
    else {
      local_368[0] = 0xffffffff;
    }
    _Size = 4;
    _Src = local_368;
    goto LAB_14000ad99;
  }
  if (param_3 == 4) {
    uVar3 = *(undefined8 *)(param_1 + 0x198);
LAB_14000ac56:
    puStack_370 = local_238;
    local_378._0_4_ = CONCAT22(0x100,(ushort)local_378);
    RtlInitAnsiString(&local_360,uVar3);
    uVar1 = RtlAnsiStringToUnicodeString(&local_378,&local_360,0);
    uVar2 = (ulonglong)uVar1;
  }
  else {
    if (param_3 == 5) {
LAB_14000ad50:
      uVar2 = 0xc0000010;
      _Src = (uint *)0x0;
      goto LAB_14000ad99;
    }
    if (param_3 == 6) {
      uVar3 = *(undefined8 *)(param_1 + 0x1b8);
      goto LAB_14000ac56;
    }
    if (param_3 != 7) {
      if (param_3 == 8) {
        puStack_370 = local_238;
        local_378._0_4_ = CONCAT22(0x100,(ushort)local_378);
        RtlInitAnsiString(&local_360,*(undefined8 *)(param_1 + 0x1a8));
        uVar1 = RtlAnsiStringToUnicodeString(&local_378,&local_360,0);
        _Size = local_378 & 0xffff;
        uVar2 = (ulonglong)uVar1;
        _Src = puStack_370;
        if ((ushort)local_378 + 2 <= (uint)local_378._2_2_) {
          _Size = (size_t)((ushort)local_378 + 2);
        }
        goto LAB_14000ad99;
      }
      goto LAB_14000ad50;
    }
    strcpy_s(local_338,0x100,*(char **)(param_1 + 0x1a8));
    strcat_s(local_338,0x100,*(char **)(param_1 + 0x1b8));
    strcat_s(local_338,0x100,*(char **)(param_1 + 0x198));
    puStack_370 = local_238;
    local_378._0_4_ = CONCAT22(0x100,(ushort)local_378);
    RtlInitAnsiString(&local_360,local_338);
    RtlAnsiStringToUnicodeString(&local_378,&local_360,0);
  }
  _Size = local_378 & 0xffff;
  _Src = puStack_370;
  if ((ushort)local_378 + 2 <= (uint)local_378._2_2_) {
    _Size = (size_t)((ushort)local_378 + 2);
  }
LAB_14000ad99:
  *param_7 = (uint)_Size;
  if (param_6 < (uint)_Size) {
    uVar2 = 0xc0000023;
  }
  else if ((-1 < (int)uVar2) && (_Src != (uint *)0x0)) {
    memmove(param_5,_Src,_Size);
  }
  return uVar2;
}



===== CmBattQueryPeakPower @ 14000ae00 =====

ulonglong CmBattQueryPeakPower(longlong param_1,int param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar3 = CmBattVerifyTag(param_1,param_2);
  uVar4 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    if (((*(char *)(param_1 + 0x652) == '\0') || (*(char *)(param_1 + 0x6fc) == '\0')) ||
       (*(char *)(param_1 + 0x6fd) == '\0')) {
      uVar4 = 0xc00000bb;
    }
    else {
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(param_1 + 0x150,0);
      if (*(char *)(param_1 + 0x148) == '\0') {
        uVar3 = CmBattGetBpsData((undefined1 *)param_3,*(undefined8 *)(param_1 + 0x20));
        uVar4 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) {
          *(uint *)(param_1 + 0x6f8) = *(uint *)(param_1 + 0x6f8) | 2;
        }
        else {
          uVar2 = param_3[1];
          *(undefined8 *)(param_1 + 0x654) = *param_3;
          *(undefined8 *)(param_1 + 0x65c) = uVar2;
          uVar1 = *(undefined4 *)(param_3 + 2);
          *(uint *)(param_1 + 0x6f8) = *(uint *)(param_1 + 0x6f8) & 0xfffffffd;
          *(undefined4 *)(param_1 + 0x664) = uVar1;
        }
      }
      else {
        uVar4 = 0;
      }
      ExReleasePushLockSharedEx(param_1 + 0x150,0);
      KeLeaveCriticalRegion();
    }
  }
  return uVar4;
}



===== CmBattQueryStatus @ 14000af00 =====

void CmBattQueryStatus(longlong param_1,int param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = CmBattVerifyTag(param_1,param_2);
  if (-1 < (int)uVar1) {
    uVar2 = CmBattGetBatteryStatus(param_1,'\0','\0');
    if (-1 < (int)uVar2) {
      uVar2 = *(undefined8 *)(param_1 + 0x61c);
      *param_3 = *(undefined8 *)(param_1 + 0x614);
      param_3[1] = uVar2;
    }
  }
  return;
}



===== CmBattQueryTag @ 14000af50 =====

uint CmBattQueryTag(longlong param_1,int *param_2)

{
  int iVar1;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1 + 0x150,0);
  if (*(char *)(param_1 + 0x148) == '\0') {
    CmBattVerifyStaticInfo(param_1);
  }
  ExReleasePushLockSharedEx(param_1 + 0x150,0);
  KeLeaveCriticalRegion();
  iVar1 = *(int *)(param_1 + 400);
  *param_2 = iVar1;
  return ~-(uint)(iVar1 != 0) & 0xc000000e;
}



===== CmBattSetAdapterStatus @ 14000aff0 =====

ulonglong CmBattSetAdapterStatus(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(AcAdapter + 0x170) & 2) == 0) {
    uVar1 = 0xc00000bb;
  }
  else if (*(byte *)(param_2 + 1) != *(byte *)(AcAdapter + 0x491)) {
    uVar1 = AcAdapterSetRecOverride(*(byte *)(param_2 + 1),param_2,(undefined4 *)0x0);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}



===== CmBattSetPeakPowerNotify @ 14000b040 =====

ulonglong CmBattSetPeakPowerNotify(longlong param_1,int param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  int local_res8 [2];
  
  local_res8[0] = 0;
  uVar2 = CmBattVerifyTag(param_1,param_2);
  uVar4 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    if (((*(char *)(param_1 + 0x652) == '\0') || (*(char *)(param_1 + 0x6fc) == '\0')) ||
       (*(char *)(param_1 + 0x6fd) == '\0')) {
      uVar4 = 0xc00000bb;
    }
    else {
      if (*(char *)(param_1 + 0x651) == '\0') {
        return 0xc0000034;
      }
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(param_1 + 0x150,0);
      if (*(char *)(param_1 + 0x148) == '\0') {
        uVar3 = *(uint *)(param_3 + 4);
        if (*(uint *)(param_1 + 0x700) <= *(uint *)(param_3 + 4)) {
          uVar3 = *(uint *)(param_1 + 0x700);
        }
        uVar1 = CmBattSetBptData(local_res8,*(undefined8 *)(param_1 + 0x20),1,uVar3);
        uVar4 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          uVar1 = *(uint *)(param_1 + 0x6f8) | 4;
        }
        else {
          *(uint *)(param_1 + 0x708) = uVar3;
          *(uint *)(param_1 + 0x6f8) = *(uint *)(param_1 + 0x6f8) & 0xfffffffb;
          uVar3 = *(uint *)(param_3 + 8);
          if (*(uint *)(param_1 + 0x704) <= *(uint *)(param_3 + 8)) {
            uVar3 = *(uint *)(param_1 + 0x704);
          }
          uVar1 = CmBattSetBptData(local_res8,*(undefined8 *)(param_1 + 0x20),2,uVar3);
          uVar4 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            uVar1 = *(uint *)(param_1 + 0x6f8) | 8;
          }
          else {
            uVar1 = *(uint *)(param_1 + 0x6f8) & 0xfffffff7;
            *(uint *)(param_1 + 0x70c) = uVar3;
          }
        }
        *(uint *)(param_1 + 0x6f8) = uVar1;
      }
      else {
        uVar4 = 0;
      }
      ExReleasePushLockSharedEx(param_1 + 0x150,0);
      KeLeaveCriticalRegion();
    }
  }
  return uVar4;
}



===== CmBattSetStatusNotify @ 14000b1b0 =====

ulonglong CmBattSetStatusNotify(int *param_1,int param_2,longlong param_3)

{
  int *piVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint local_18 [4];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  uVar3 = CmBattVerifyTag((longlong)param_1,param_2);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if ((char)param_1[0x194] == '\0') {
    return 0xc0000034;
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_1 + 0x54);
  if ((char)param_1[0x52] == '\0') {
    uVar6 = *(uint *)(param_3 + 8);
    if ((uVar6 == 0xffffffff) && (*(int *)(param_3 + 4) == -1)) {
LAB_14000b234:
      uVar3 = 0xc00000bb;
      goto LAB_14000b381;
    }
    uVar5 = param_1[0x70] & 2;
    if (uVar5 == 0) {
      uVar6 = *(uint *)(param_3 + 4);
    }
    if ((param_1[0x76] & 1U) == 0) {
      if (uVar5 == 0) {
        uVar5 = uVar6;
        if (0 < (int)uVar6) {
          uVar5 = uVar6 - 1;
        }
      }
      else {
        uVar5 = uVar6 + 1;
      }
    }
    else {
      uVar2 = param_1[0x7a];
      if (0xfffffffd < uVar2 - 1) goto LAB_14000b234;
      if (uVar5 == 0) {
        uVar5 = uVar6 * 1000 - 500;
        uVar5 = uVar5 / uVar2 - (uint)(uVar5 % uVar2 == 0);
      }
      else {
        uVar5 = uVar6 * 1000 + 500;
        uVar5 = (uint)(uVar5 % uVar2 != 0) + uVar5 / uVar2;
      }
    }
    if (uVar5 != param_1[0x19a]) {
      piVar1 = param_1 + 0x1b4;
      ExAcquirePushLockExclusiveEx(piVar1,0);
      param_1[0x19a] = uVar5;
      uVar2 = CmBattSetTripPpoint((longlong)param_1,(ulonglong)uVar5);
      uVar3 = (ulonglong)uVar2;
      if ((uVar5 == 0) && (uVar6 != 0)) {
        uVar3 = 0xc00000bb;
      }
      else if (-1 < (int)uVar2) {
        CmBattTraceBtp((longlong)param_1,'\0');
        ExReleasePushLockExclusiveEx(piVar1,0);
        uVar4 = CmBattGetBstData((longlong)param_1,local_18);
        uVar3 = uVar4 & 0xffffffff;
        if (-1 < (int)uVar4) {
          if ((param_1[0x70] & 2U) == 0) {
            if ((uVar5 < local_18[2]) || (uVar6 == 0)) goto LAB_14000b381;
          }
          else if (local_18[2] < uVar5) goto LAB_14000b381;
          uVar4 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar4 == 0) {
            CmBattNotifyHandler(param_1,0x80);
          }
          else {
            CmBattNotifyHandlerV1(param_1,0x80);
          }
        }
        goto LAB_14000b381;
      }
      param_1[0x19a] = -1;
      CmBattTraceBtp((longlong)param_1,'\0');
      ExReleasePushLockExclusiveEx(piVar1,0);
      goto LAB_14000b381;
    }
  }
  uVar3 = 0;
LAB_14000b381:
  ExReleasePushLockSharedEx(param_1 + 0x54,0);
  KeLeaveCriticalRegion();
  return uVar3;
}



===== CmBattUnload @ 14000b3d0 =====

void CmBattUnload(void)

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
  CmBattUnregisterEtw();
  if (DAT_1400071f8 != 0) {
    ExFreePoolWithTag(DAT_1400071f8,0);
  }
  return;
}



===== CmBattVerifyStaticInfo @ 14000b448 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CmBattVerifyStaticInfo(longlong param_1)

{
  int *piVar1;
  int *piVar2;
  undefined8 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  int *piVar11;
  int *piVar12;
  uint uVar13;
  
  piVar1 = (int *)(param_1 + 0x1d0);
  piVar7 = (int *)ExAllocatePool2(0x100,0x444,0x4d746142);
  piVar2 = (int *)(param_1 + 0x174);
  if (piVar7 != (int *)0x0) {
    uVar9 = 0;
    do {
      do {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + 1;
        UNLOCK();
        if (iVar6 != 0) goto LAB_14000b901;
        uVar8 = CmBattVerifyStaData(param_1);
        uVar9 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) goto LAB_14000b901;
        uVar9 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
        if ((((int)uVar9 != 0) && (*(char *)(param_1 + 0x652) != '\0')) &&
           (uVar9 = CmBattGetBpcData((undefined1 *)(param_1 + 0x6fc),(undefined1 *)(param_1 + 0x6fd)
                                     ,(undefined4 *)(param_1 + 0x700),
                                     (undefined4 *)(param_1 + 0x704),*(undefined8 *)(param_1 + 0x20)
                                    ), (int)uVar9 < 0)) {
          *(uint *)(param_1 + 0x6f8) = *(uint *)(param_1 + 0x6f8) | 1;
        }
        uVar8 = CmBattGetBixData(param_1,piVar7);
        uVar9 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) {
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(param_1 + 0x6d0,0);
          *(undefined4 *)(param_1 + 400) = 0;
          ExReleasePushLockExclusiveEx(param_1 + 0x6d0,0);
          KeLeaveCriticalRegion();
          goto LAB_14000b901;
        }
      } while ((*(int *)(param_1 + 400) != 0) &&
              (lVar10 = RtlCompareMemory(piVar7,piVar1,0x444), lVar10 == 0x444));
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(param_1 + 0x6d0,0);
      iVar6 = *(int *)(param_1 + 0x188) + 1;
      *(int *)(param_1 + 0x188) = iVar6;
      if (iVar6 == 0) {
        *(undefined4 *)(param_1 + 0x188) = 1;
        iVar6 = 1;
      }
      *(int *)(param_1 + 400) = iVar6;
      lVar10 = 8;
      *(undefined8 *)(param_1 + 0x670) = _DAT_fffff78000000008;
      piVar4 = piVar7;
      piVar5 = piVar1;
      do {
        piVar12 = piVar5;
        piVar11 = piVar4;
        uVar3 = *(undefined8 *)(piVar11 + 2);
        *(undefined8 *)piVar12 = *(undefined8 *)piVar11;
        *(undefined8 *)(piVar12 + 2) = uVar3;
        uVar3 = *(undefined8 *)(piVar11 + 6);
        *(undefined8 *)(piVar12 + 4) = *(undefined8 *)(piVar11 + 4);
        *(undefined8 *)(piVar12 + 6) = uVar3;
        uVar3 = *(undefined8 *)(piVar11 + 10);
        *(undefined8 *)(piVar12 + 8) = *(undefined8 *)(piVar11 + 8);
        *(undefined8 *)(piVar12 + 10) = uVar3;
        uVar3 = *(undefined8 *)(piVar11 + 0xe);
        *(undefined8 *)(piVar12 + 0xc) = *(undefined8 *)(piVar11 + 0xc);
        *(undefined8 *)(piVar12 + 0xe) = uVar3;
        uVar3 = *(undefined8 *)(piVar11 + 0x12);
        *(undefined8 *)(piVar12 + 0x10) = *(undefined8 *)(piVar11 + 0x10);
        *(undefined8 *)(piVar12 + 0x12) = uVar3;
        uVar3 = *(undefined8 *)(piVar11 + 0x16);
        *(undefined8 *)(piVar12 + 0x14) = *(undefined8 *)(piVar11 + 0x14);
        *(undefined8 *)(piVar12 + 0x16) = uVar3;
        uVar3 = *(undefined8 *)(piVar11 + 0x1a);
        *(undefined8 *)(piVar12 + 0x18) = *(undefined8 *)(piVar11 + 0x18);
        *(undefined8 *)(piVar12 + 0x1a) = uVar3;
        uVar3 = *(undefined8 *)(piVar11 + 0x1e);
        *(undefined8 *)(piVar12 + 0x1c) = *(undefined8 *)(piVar11 + 0x1c);
        *(undefined8 *)(piVar12 + 0x1e) = uVar3;
        lVar10 = lVar10 + -1;
        piVar4 = piVar11 + 0x20;
        piVar5 = piVar12 + 0x20;
      } while (lVar10 != 0);
      uVar3 = *(undefined8 *)(piVar11 + 0x22);
      *(undefined8 *)(piVar12 + 0x20) = *(undefined8 *)(piVar11 + 0x20);
      *(undefined8 *)(piVar12 + 0x22) = uVar3;
      uVar3 = *(undefined8 *)(piVar11 + 0x26);
      *(undefined8 *)(piVar12 + 0x24) = *(undefined8 *)(piVar11 + 0x24);
      *(undefined8 *)(piVar12 + 0x26) = uVar3;
      uVar3 = *(undefined8 *)(piVar11 + 0x2a);
      *(undefined8 *)(piVar12 + 0x28) = *(undefined8 *)(piVar11 + 0x28);
      *(undefined8 *)(piVar12 + 0x2a) = uVar3;
      uVar3 = *(undefined8 *)(piVar11 + 0x2e);
      *(undefined8 *)(piVar12 + 0x2c) = *(undefined8 *)(piVar11 + 0x2c);
      *(undefined8 *)(piVar12 + 0x2e) = uVar3;
      piVar12[0x30] = piVar11[0x30];
      *(undefined8 *)(param_1 + 0x628) = 0;
      *(undefined8 *)(param_1 + 0x630) = 0;
      *(undefined8 *)(param_1 + 0x638) = 0;
      *(undefined8 *)(param_1 + 0x640) = 0;
      *(undefined4 *)(param_1 + 0x624) = 0x80000000;
      if (*(int *)(param_1 + 0x684) == 2) {
        *(undefined4 *)(param_1 + 0x624) = 0x90000000;
      }
      *(undefined1 *)(param_1 + 0x628) = *(undefined1 *)(param_1 + 0x1e4);
      *(undefined1 *)(param_1 + 0x62c) = *(undefined1 *)(param_1 + 0x414);
      *(undefined1 *)(param_1 + 0x62d) = *(undefined1 *)(param_1 + 0x415);
      *(undefined1 *)(param_1 + 0x62e) = *(undefined1 *)(param_1 + 0x416);
      *(undefined1 *)(param_1 + 0x62f) = *(undefined1 *)(param_1 + 0x417);
      if (*(int *)(param_1 + 500) != -1) {
        *(int *)(param_1 + 0x644) = *(int *)(param_1 + 500);
      }
      if ((*(uint *)(param_1 + 0x1d8) & 1) == 0) {
        *(undefined4 *)(param_1 + 0x630) = *(undefined4 *)(param_1 + 0x1dc);
        *(undefined4 *)(param_1 + 0x634) = *(undefined4 *)(param_1 + 0x1e0);
        *(undefined4 *)(param_1 + 0x638) = *(undefined4 *)(param_1 + 0x1f0);
        *(undefined4 *)(param_1 + 0x63c) = *(undefined4 *)(param_1 + 0x1ec);
        *(undefined4 *)(param_1 + 0x648) = *(undefined4 *)(param_1 + 0x20c);
        uVar13 = *(uint *)(param_1 + 0x210);
      }
      else {
        if (*(int *)(param_1 + 0x1e8) == -1) {
          *(undefined4 *)(param_1 + 0x630) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x634) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x638) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x63c) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x648) = 0xffffffff;
        }
        else {
          if (*(int *)(param_1 + 0x1dc) == -1) {
            uVar13 = 0xffffffff;
          }
          else {
            uVar13 = (*(int *)(param_1 + 0x1dc) * *(int *)(param_1 + 0x1e8) + 500U) / 1000;
          }
          *(uint *)(param_1 + 0x630) = uVar13;
          if (*(int *)(param_1 + 0x1e0) == -1) {
            uVar13 = 0xffffffff;
          }
          else {
            uVar13 = (*(int *)(param_1 + 0x1e0) * *(int *)(param_1 + 0x1e8) + 500U) / 1000;
          }
          *(uint *)(param_1 + 0x634) = uVar13;
          if (*(int *)(param_1 + 0x1ec) == -1) {
            uVar13 = 0xffffffff;
          }
          else {
            uVar13 = (*(int *)(param_1 + 0x1ec) * *(int *)(param_1 + 0x1e8) + 500U) / 1000;
          }
          *(uint *)(param_1 + 0x63c) = uVar13;
          if (*(int *)(param_1 + 0x1f0) == -1) {
            uVar13 = 0xffffffff;
          }
          else {
            uVar13 = (*(int *)(param_1 + 0x1f0) * *(int *)(param_1 + 0x1e8) + 500U) / 1000;
          }
          *(uint *)(param_1 + 0x638) = uVar13;
          if (*(int *)(param_1 + 0x20c) == -1) {
            uVar13 = 0xffffffff;
          }
          else {
            uVar13 = (*(int *)(param_1 + 0x20c) * *(int *)(param_1 + 0x1e8) + 500U) / 1000;
          }
          *(uint *)(param_1 + 0x648) = uVar13;
          if (*(int *)(param_1 + 0x210) != -1) {
            uVar13 = (*(int *)(param_1 + 0x210) * *(int *)(param_1 + 0x1e8) + 500U) / 1000;
            goto LAB_14000b7fd;
          }
        }
        uVar13 = 0xffffffff;
      }
LAB_14000b7fd:
      *(uint *)(param_1 + 0x64c) = uVar13;
      *(longlong *)(param_1 + 0x198) = param_1 + 0x214;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while (*(char *)(param_1 + 0x214 + lVar10) != '\0');
      *(int *)(param_1 + 0x194) = (int)lVar10;
      *(longlong *)(param_1 + 0x1a8) = param_1 + 0x314;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while (*(char *)(param_1 + 0x314 + lVar10) != '\0');
      *(int *)(param_1 + 0x1a0) = (int)lVar10;
      *(longlong *)(param_1 + 0x1b8) = param_1 + 0x514;
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while (*(char *)(param_1 + 0x514 + lVar10) != '\0');
      *(int *)(param_1 + 0x1b0) = (int)lVar10;
      if (*piVar1 == 0x5849425f) {
        CmBattTraceBix(param_1,'\0');
      }
      else {
        CmBattTraceBif(param_1,'\0');
      }
      ExReleasePushLockExclusiveEx(param_1 + 0x6d0,0);
      KeLeaveCriticalRegion();
      uVar8 = CmBattGetBatteryStatus(param_1,'\x01','\0');
      uVar9 = uVar8 & 0xffffffff;
      CmBattSetCoolingPercentage(param_1,'\x01');
    } while (-1 < (int)uVar8);
LAB_14000b901:
    ExFreePoolWithTag(piVar7,0x4d746142);
    if (-1 < (int)uVar9) {
      return uVar9;
    }
  }
  LOCK();
  *piVar2 = 0;
  UNLOCK();
  return 0xc000000e;
}



===== CmBattVerifyTag @ 14000b94c =====

ulonglong CmBattVerifyTag(longlong param_1,int param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if ((*(int *)(param_1 + 400) == 0) || (param_2 != *(int *)(param_1 + 400))) {
    uVar2 = 0xc000000e;
  }
  else if ((*(int *)(param_1 + 0x174) != 2) || (*(char *)(param_1 + 0x170) != '\0')) {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(param_1 + 0x150,0);
    if (*(char *)(param_1 + 0x148) == '\0') {
      uVar1 = CmBattVerifyStaData(param_1);
      uVar2 = uVar1 & 0xffffffff;
      if (-1 < (int)uVar1) {
        CmBattVerifyStaticInfo(param_1);
        if ((*(int *)(param_1 + 400) == 0) || (param_2 != *(int *)(param_1 + 400))) {
          uVar2 = 0xc000000e;
        }
      }
    }
    ExReleasePushLockSharedEx(param_1 + 0x150,0);
    KeLeaveCriticalRegion();
  }
  return uVar2;
}



===== wil_details_EvaluateFeatureDependencies @ 14000ba28 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000ba63;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000badd:
  while( true ) {
    if (&UNK_14000641f < ppuVar3) {
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
      if (&UNK_14000641f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000ba63:
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
      if (&UNK_14000641f < ppuVar2) goto LAB_14000badd;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000badd;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000bb18 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000bbb0;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000bbb0;
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
LAB_14000bbb0:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000bc00 =====

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
              if (&UNK_14000641f < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000bc80 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000bd7d;
  }
LAB_14000bd86:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000bd7d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000bd86;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000bd4e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000bd4e;
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
    if (&UNK_14000641f < ppuVar3) goto LAB_14000bd86;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000bd7d;
}



===== AcAdapterEvalRec_DSM @ 14000bdac =====

ulonglong AcAdapterEvalRec_DSM(undefined8 param_1,undefined4 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  puVar2 = (undefined4 *)ExAllocatePool2(0x100,0x3c,0x4d746142);
  if (puVar2 == (undefined4 *)0x0) {
    uVar6 = 0xc000009a;
  }
  else {
    lVar3 = ExAllocatePool2(0x100,0x200,0x4d746142);
    if (lVar3 == 0) {
      uVar6 = 0xc000009a;
    }
    else {
      puVar2[1] = 0x4d53445f;
      *puVar2 = 0x43696541;
      puVar2[2] = 0x3c;
      puVar2[3] = 4;
      uVar5 = 0x10;
      puVar2[4] = 0x100002;
      memcpy_s(puVar2 + 5,0x10,&GUID_DSM_AC_ADAPTER,0x10);
      lVar1 = AcAdapter;
      uVar4 = (ulonglong)*(ushort *)((longlong)puVar2 + 0x12);
      if (*(ushort *)((longlong)puVar2 + 0x12) < 4) {
        uVar4 = 4;
      }
      *(undefined8 *)((longlong)puVar2 + uVar4 + 0x14) = 0x40000;
      *(undefined4 *)((longlong)puVar2 + uVar4 + 0x1c) = 0x40000;
      *(undefined4 *)((longlong)puVar2 + uVar4 + 0x20) = param_2;
      *(undefined4 *)((longlong)puVar2 + uVar4 + 0x24) = 4;
      uVar4 = CmBattSendDownStreamIrp(*(undefined8 *)(lVar1 + 0x18),uVar5,puVar2,0x3c,lVar3,0x200);
      uVar6 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        ExFreePoolWithTag(lVar3,0x4d746142);
      }
      else {
        *param_3 = lVar3;
      }
    }
    ExFreePoolWithTag(puVar2,0x4d746142);
  }
  return uVar6;
}



===== AcAdapterGetRecCapabilities @ 14000bf08 =====

ulonglong AcAdapterGetRecCapabilities(undefined8 param_1)

{
  short *psVar1;
  ushort uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  short *psVar9;
  longlong local_res8;
  
  local_res8 = 0;
  uVar5 = 0;
  uVar4 = AcAdapterEvalRec_DSM(param_1,0,&local_res8);
  lVar3 = local_res8;
  uVar6 = uVar4 & 0xffffffff;
  if (((int)uVar4 < 0) || (local_res8 == 0)) {
    uVar7 = 1;
    goto LAB_14000c004;
  }
  uVar5 = 1;
  if (*(int *)(local_res8 + 8) != 1) {
    uVar6 = 0xc014000f;
    uVar7 = 2;
    goto LAB_14000c004;
  }
  psVar1 = (short *)(local_res8 + 0xc);
  if ((psVar1 < (short *)(local_res8 + 0x14U)) &&
     (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
     (short *)(local_res8 + 0x14U) <= psVar9)) {
    uVar2 = *(ushort *)(local_res8 + 0xe);
    uVar8 = (ulonglong)uVar2;
    uVar4 = 4;
    if (3 < uVar2) {
      uVar4 = uVar8;
    }
    if ((short *)(uVar4 + 4 + (longlong)psVar1) <= psVar1) goto LAB_14000bff1;
    if (uVar2 < 4) {
      uVar8 = 4;
    }
    if (psVar9 < (short *)(local_res8 + 0x10 + uVar8)) goto LAB_14000bff1;
    if ((*psVar1 == 2) && (uVar2 != 0)) {
      if ((*(byte *)(local_res8 + 0x10) & 1) == 0) {
        uVar6 = 0xc0000002;
        uVar7 = 4;
      }
      else {
        uVar7 = 0;
        *(uint *)(AcAdapter + 0x488) = (uint)*(byte *)(local_res8 + 0x10);
      }
      goto LAB_14000c004;
    }
    uVar6 = 0xc014000f;
  }
  else {
LAB_14000bff1:
    uVar6 = 0xc0140005;
  }
  uVar7 = 3;
LAB_14000c004:
  CmBattTraceRecCapabilities((int)uVar6,uVar5,uVar7,'\0');
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0x4d746142);
  }
  return uVar6;
}



===== AcAdapterGetRecStatus @ 14000c03c =====

ulonglong AcAdapterGetRecStatus(undefined8 param_1,short *param_2)

{
  ushort uVar1;
  short sVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  short *psVar8;
  short *psVar9;
  short *psVar10;
  longlong local_res8;
  undefined6 uStack_26;
  undefined2 uStack_20;
  undefined6 uStack_1e;
  
  local_res8 = 0;
  if ((*(uint *)(AcAdapter + 0x488) >> 3 & 1) == 0) {
    uVar5 = 0xc0000002;
    uVar6 = 1;
    goto LAB_14000c209;
  }
  uVar6 = 3;
  param_2 = (short *)0x3;
  uVar4 = AcAdapterEvalRec_DSM(param_1,3,&local_res8);
  uVar5 = uVar4 & 0xffffffff;
  if (((int)uVar4 < 0) || (local_res8 == 0)) {
    uVar6 = 2;
    goto LAB_14000c209;
  }
  if (*(int *)(local_res8 + 8) != 2) {
LAB_14000c0a9:
    uVar5 = 0xc014000f;
    goto LAB_14000c209;
  }
  param_2 = (short *)(local_res8 + 0xc);
  uVar6 = 4;
  if ((param_2 < (short *)(local_res8 + 0x14U)) &&
     (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
     (short *)(local_res8 + 0x14U) <= psVar9)) {
    uVar1 = *(ushort *)(local_res8 + 0xe);
    uVar7 = (ulonglong)uVar1;
    uVar4 = 4;
    if (3 < uVar1) {
      uVar4 = uVar7;
    }
    if (param_2 < (short *)(uVar4 + 4 + (longlong)param_2)) {
      if (uVar1 < 4) {
        uVar7 = 4;
      }
      if ((short *)(local_res8 + 0x10 + uVar7) <= psVar9) {
        if (*param_2 != 0) goto LAB_14000c0a9;
        *(bool *)(AcAdapter + 0x490) = *(int *)(local_res8 + 0x10) != 0;
        lVar3 = AcAdapter;
        if (*(ushort *)(local_res8 + 0xe) < 4) {
          uVar4 = 4;
        }
        else {
          uVar4 = (ulonglong)*(ushort *)(local_res8 + 0xe);
        }
        psVar9 = (short *)(local_res8 + 0x10 + uVar4);
        if (((psVar9 < (short *)(local_res8 + 0xcU)) || (param_2 = psVar9 + 4, param_2 <= psVar9))
           || (psVar10 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
              psVar10 < param_2)) {
LAB_14000c1f1:
          uVar5 = 0xc0140005;
        }
        else {
          uVar1 = psVar9[1];
          param_2 = (short *)(ulonglong)uVar1;
          uVar4 = 4;
          if (3 < uVar1) {
            uVar4 = (ulonglong)(uint)uVar1;
          }
          if ((short *)(uVar4 + 4 + (longlong)psVar9) <= psVar9) goto LAB_14000c1f1;
          psVar8 = param_2;
          if (uVar1 < 4) {
            psVar8 = (short *)0x4;
          }
          if (psVar10 < (short *)((longlong)(psVar8 + 2) + (longlong)psVar9)) goto LAB_14000c1f1;
          if ((*psVar9 == 2) && (uVar1 == 0x12)) {
            sVar2 = psVar9[10];
            uVar6 = 0;
            uStack_26 = (undefined6)((ulonglong)*(undefined8 *)(psVar9 + 2) >> 0x10);
            uStack_20 = (undefined2)*(undefined8 *)(psVar9 + 6);
            uStack_1e = (undefined6)((ulonglong)*(undefined8 *)(psVar9 + 6) >> 0x10);
            *(ulonglong *)(AcAdapter + 0x498) = CONCAT26(uStack_20,uStack_26);
            *(ulonglong *)(lVar3 + 0x4a0) = CONCAT26(sVar2,uStack_1e);
            goto LAB_14000c209;
          }
          uVar5 = 0xc014000f;
        }
        uVar6 = 5;
        goto LAB_14000c209;
      }
    }
  }
  uVar5 = 0xc0140005;
LAB_14000c209:
  lVar3 = local_res8;
  CmBattTraceRecStatus((int)uVar5,param_2,uVar6,'\0');
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0x4d746142);
  }
  return uVar5;
}



===== AcAdapterGetRecSupported @ 14000c250 =====

ulonglong AcAdapterGetRecSupported(undefined8 param_1,short *param_2)

{
  short *psVar1;
  ushort uVar2;
  short *psVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  short *psVar8;
  short *psVar9;
  longlong local_res8;
  
  local_res8 = 0;
  uVar6 = 1;
  if ((*(uint *)(AcAdapter + 0x244) >> 1 & 1) == 0) {
    uVar7 = 0xc0000002;
  }
  else {
    param_2 = (short *)0x1;
    uVar5 = AcAdapterEvalRec_DSM(param_1,1,&local_res8);
    psVar3 = AcAdapter;
    uVar7 = uVar5 & 0xffffffff;
    if (((int)uVar5 < 0) || (local_res8 == 0)) {
      uVar6 = 2;
    }
    else if (*(int *)(local_res8 + 8) == 1) {
      psVar1 = (short *)(local_res8 + 0xc);
      uVar6 = 4;
      param_2 = (short *)(local_res8 + 0x14);
      if ((psVar1 < param_2) &&
         (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
         param_2 <= psVar9)) {
        uVar2 = *(ushort *)(local_res8 + 0xe);
        param_2 = (short *)(ulonglong)uVar2;
        psVar8 = (short *)0x4;
        if (3 < uVar2) {
          psVar8 = param_2;
        }
        if (psVar1 < (short *)((longlong)(psVar8 + 2) + (longlong)psVar1)) {
          psVar8 = param_2;
          if (uVar2 < 4) {
            psVar8 = (short *)0x4;
          }
          if ((short *)(local_res8 + 0x10 + (longlong)psVar8) <= psVar9) {
            if (*psVar1 == 0) {
              uVar6 = 0;
              *(uint *)(AcAdapter + 0xb8) =
                   -(uint)(*(int *)(local_res8 + 0x10) != 0) & 2 |
                   *(uint *)(AcAdapter + 0xb8) & 0xfffffffd;
              param_2 = psVar3;
            }
            else {
              uVar7 = 0xc014000f;
            }
            goto LAB_14000c354;
          }
        }
      }
      uVar7 = 0xc0140005;
    }
    else {
      uVar7 = 0xc014000f;
      uVar6 = 3;
    }
  }
LAB_14000c354:
  lVar4 = local_res8;
  CmBattTraceRecSupported((int)uVar7,param_2,uVar6,'\0');
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0x4d746142);
  }
  return uVar7;
}



===== AcAdapterGetWattageRequirements @ 14000c398 =====

ulonglong AcAdapterGetWattageRequirements(undefined8 param_1,short *param_2)

{
  byte bVar1;
  ushort uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  short *psVar8;
  short *psVar9;
  short *psVar10;
  longlong local_res8;
  
  local_res8 = 0;
  if ((*(uint *)(AcAdapter + 0x488) >> 4 & 1) == 0) {
    uVar6 = 0xc0000002;
    uVar7 = 1;
    goto LAB_14000cafb;
  }
  param_2 = (short *)0x4;
  uVar4 = AcAdapterEvalRec_DSM(param_1,4,&local_res8);
  lVar3 = AcAdapter;
  uVar6 = uVar4 & 0xffffffff;
  if (((int)uVar4 < 0) || (local_res8 == 0)) {
    uVar7 = 2;
    goto LAB_14000cafb;
  }
  if ((*(int *)(local_res8 + 8) != 4) && (*(int *)(local_res8 + 8) != 7)) {
    uVar6 = 0xc014000f;
    uVar7 = 3;
    goto LAB_14000cafb;
  }
  psVar10 = (short *)(local_res8 + 0xc);
  param_2 = (short *)(local_res8 + 0x14);
  if ((psVar10 < param_2) &&
     (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
     param_2 <= psVar9)) {
    uVar2 = *(ushort *)(local_res8 + 0xe);
    param_2 = (short *)(ulonglong)uVar2;
    psVar8 = (short *)0x4;
    if (3 < uVar2) {
      psVar8 = param_2;
    }
    if ((short *)((longlong)(psVar8 + 2) + (longlong)psVar10) <= psVar10) goto LAB_14000caeb;
    psVar8 = param_2;
    if (uVar2 < 4) {
      psVar8 = (short *)0x4;
    }
    if (psVar9 < (short *)(local_res8 + 0x10 + (longlong)psVar8)) goto LAB_14000caeb;
    if (*psVar10 == 0) {
      bVar1 = *(byte *)(local_res8 + 0x10);
      if (bVar1 != 1) {
        uVar5 = bVar1 - 2;
        param_2 = (short *)(ulonglong)uVar5;
        if (uVar5 == 0) goto LAB_14000c8ce;
        if (uVar5 != 1) {
          uVar6 = 0xc014000f;
          uVar7 = 0xb;
          goto LAB_14000cafb;
        }
        *(undefined4 *)(AcAdapter + 0x484) = 2;
        *(undefined4 *)(lVar3 + 0x4a8) = 1;
        if (*(ushort *)(local_res8 + 0xe) < 4) {
          uVar4 = 4;
        }
        else {
          uVar4 = (ulonglong)*(ushort *)(local_res8 + 0xe);
        }
        param_2 = (short *)(local_res8 + 0x10 + uVar4);
        if (((param_2 < (short *)(local_res8 + 0xcU)) || (param_2 + 4 <= param_2)) ||
           (psVar10 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
           psVar10 < param_2 + 4)) goto LAB_14000cade;
        uVar2 = param_2[1];
        uVar6 = (ulonglong)uVar2;
        uVar4 = 4;
        if (3 < uVar2) {
          uVar4 = uVar6;
        }
        if ((short *)(uVar4 + 4 + (longlong)param_2) <= param_2) goto LAB_14000cade;
        if (uVar2 < 4) {
          uVar6 = 4;
        }
        if (psVar10 < (short *)(uVar6 + 4 + (longlong)param_2)) goto LAB_14000cade;
        if (*param_2 != 0) goto LAB_14000c970;
        *(undefined4 *)(AcAdapter + 0x4ac) = *(undefined4 *)(param_2 + 2);
        if ((ushort)param_2[1] < 4) {
          uVar4 = 4;
        }
        else {
          uVar4 = (ulonglong)(ushort)param_2[1];
        }
        psVar10 = (short *)(uVar4 + 4 + (longlong)param_2);
        if (((psVar10 < (short *)(local_res8 + 0xcU)) || (psVar10 + 4 <= psVar10)) ||
           (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
           psVar9 < psVar10 + 4)) goto LAB_14000cad1;
        uVar2 = psVar10[1];
        param_2 = (short *)(ulonglong)uVar2;
        psVar8 = (short *)0x4;
        if (3 < uVar2) {
          psVar8 = param_2;
        }
        if ((short *)((longlong)(psVar8 + 2) + (longlong)psVar10) <= psVar10) goto LAB_14000cad1;
        if (uVar2 < 4) {
          param_2 = (short *)0x4;
        }
        if (psVar9 < (short *)((longlong)(param_2 + 2) + (longlong)psVar10)) goto LAB_14000cad1;
        if (*psVar10 == 0) {
          *(undefined4 *)(AcAdapter + 0x4b0) = *(undefined4 *)(psVar10 + 2);
          lVar3 = AcAdapter;
          if ((ushort)psVar10[1] < 4) {
            uVar4 = 4;
          }
          else {
            uVar4 = (ulonglong)(ushort)psVar10[1];
          }
          param_2 = (short *)(uVar4 + 4 + (longlong)psVar10);
          if ((((short *)(local_res8 + 0xcU) <= param_2) && (param_2 < param_2 + 4)) &&
             (psVar10 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
             param_2 + 4 <= psVar10)) {
            uVar2 = param_2[1];
            uVar6 = (ulonglong)uVar2;
            uVar4 = 4;
            if (3 < uVar2) {
              uVar4 = uVar6;
            }
            if ((short *)(uVar4 + 4 + (longlong)param_2) <= param_2) goto LAB_14000cac7;
            if (uVar2 < 4) {
              uVar6 = 4;
            }
            if (psVar10 < (short *)(uVar6 + 4 + (longlong)param_2)) goto LAB_14000cac7;
            if (*param_2 != 0) goto LAB_14000caa8;
            *(undefined4 *)(AcAdapter + 0x4b4) = *(undefined4 *)(param_2 + 2);
            *(undefined4 *)(lVar3 + 0x4b8) = 2;
            if ((ushort)param_2[1] < 4) {
              uVar4 = 4;
            }
            else {
              uVar4 = (ulonglong)(ushort)param_2[1];
            }
            param_2 = (short *)((longlong)param_2 + uVar4 + 4);
            if (((param_2 < (short *)(local_res8 + 0xcU)) || (param_2 + 4 <= param_2)) ||
               (psVar10 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
               psVar10 < param_2 + 4)) {
LAB_14000c8be:
              uVar6 = 0xc0140005;
LAB_14000c8c3:
              uVar7 = 8;
              goto LAB_14000cafb;
            }
            uVar2 = param_2[1];
            uVar6 = (ulonglong)uVar2;
            uVar4 = 4;
            if (3 < uVar2) {
              uVar4 = uVar6;
            }
            if ((short *)(uVar4 + 4 + (longlong)param_2) <= param_2) goto LAB_14000c8be;
            if (uVar2 < 4) {
              uVar6 = 4;
            }
            if (psVar10 < (short *)(uVar6 + 4 + (longlong)param_2)) goto LAB_14000c8be;
            if (*param_2 != 0) {
              uVar6 = 0xc014000f;
              goto LAB_14000c8c3;
            }
            *(undefined4 *)(AcAdapter + 0x4bc) = *(undefined4 *)(param_2 + 2);
            if ((ushort)param_2[1] < 4) {
              uVar4 = 4;
            }
            else {
              uVar4 = (ulonglong)(ushort)param_2[1];
            }
            psVar10 = (short *)(uVar4 + 4 + (longlong)param_2);
            if (((psVar10 < (short *)(local_res8 + 0xcU)) || (psVar10 + 4 <= psVar10)) ||
               (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
               psVar9 < psVar10 + 4)) {
LAB_14000c8ae:
              uVar6 = 0xc0140005;
LAB_14000c8b3:
              uVar7 = 9;
              goto LAB_14000cafb;
            }
            uVar2 = psVar10[1];
            param_2 = (short *)(ulonglong)uVar2;
            psVar8 = (short *)0x4;
            if (3 < uVar2) {
              psVar8 = param_2;
            }
            if ((short *)((longlong)(psVar8 + 2) + (longlong)psVar10) <= psVar10)
            goto LAB_14000c8ae;
            if (uVar2 < 4) {
              param_2 = (short *)0x4;
            }
            if (psVar9 < (short *)((longlong)(param_2 + 2) + (longlong)psVar10)) goto LAB_14000c8ae;
            if (*psVar10 != 0) {
              uVar6 = 0xc014000f;
              goto LAB_14000c8b3;
            }
            *(undefined4 *)(AcAdapter + 0x4c0) = *(undefined4 *)(psVar10 + 2);
            if ((ushort)psVar10[1] < 4) {
              uVar4 = 4;
            }
            else {
              uVar4 = (ulonglong)(ushort)psVar10[1];
            }
            psVar10 = (short *)(uVar4 + 4 + (longlong)psVar10);
            if (((psVar10 < (short *)(local_res8 + 0xcU)) ||
                (param_2 = psVar10 + 4, param_2 <= psVar10)) ||
               (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
               psVar9 < param_2)) {
LAB_14000c89e:
              uVar6 = 0xc0140005;
LAB_14000c8a3:
              uVar7 = 10;
              goto LAB_14000cafb;
            }
            uVar2 = psVar10[1];
            param_2 = (short *)(ulonglong)uVar2;
            psVar8 = (short *)0x4;
            if (3 < uVar2) {
              psVar8 = param_2;
            }
            if ((short *)((longlong)(psVar8 + 2) + (longlong)psVar10) <= psVar10)
            goto LAB_14000c89e;
            psVar8 = param_2;
            if (uVar2 < 4) {
              psVar8 = (short *)0x4;
            }
            if (psVar9 < (short *)((longlong)(psVar8 + 2) + (longlong)psVar10)) goto LAB_14000c89e;
            if (*psVar10 != 0) {
              uVar6 = 0xc014000f;
              goto LAB_14000c8a3;
            }
            *(undefined4 *)(AcAdapter + 0x4c4) = *(undefined4 *)(psVar10 + 2);
LAB_14000cabf:
            uVar6 = 0;
            uVar7 = 0;
            goto LAB_14000cafb;
          }
          goto LAB_14000cac7;
        }
LAB_14000ca15:
        uVar6 = 0xc014000f;
LAB_14000cad6:
        uVar7 = 6;
        goto LAB_14000cafb;
      }
LAB_14000c8ce:
      *(undefined4 *)(AcAdapter + 0x484) = 1;
      *(uint *)(lVar3 + 0x4a8) = (uint)bVar1;
      if (*(ushort *)(local_res8 + 0xe) < 4) {
        uVar4 = 4;
      }
      else {
        uVar4 = (ulonglong)*(ushort *)(local_res8 + 0xe);
      }
      param_2 = (short *)(local_res8 + 0x10 + uVar4);
      if (((param_2 < (short *)(local_res8 + 0xcU)) || (param_2 + 4 <= param_2)) ||
         (psVar10 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
         psVar10 < param_2 + 4)) {
LAB_14000cade:
        uVar6 = 0xc0140005;
      }
      else {
        uVar2 = param_2[1];
        uVar6 = (ulonglong)uVar2;
        uVar4 = 4;
        if (3 < uVar2) {
          uVar4 = uVar6;
        }
        if ((short *)(uVar4 + 4 + (longlong)param_2) <= param_2) goto LAB_14000cade;
        if (uVar2 < 4) {
          uVar6 = 4;
        }
        if (psVar10 < (short *)(uVar6 + 4 + (longlong)param_2)) goto LAB_14000cade;
        if (*param_2 == 0) {
          *(undefined4 *)(AcAdapter + 0x4ac) = *(undefined4 *)(param_2 + 2);
          if ((ushort)param_2[1] < 4) {
            uVar4 = 4;
          }
          else {
            uVar4 = (ulonglong)(ushort)param_2[1];
          }
          psVar10 = (short *)(uVar4 + 4 + (longlong)param_2);
          if ((((short *)(local_res8 + 0xcU) <= psVar10) && (psVar10 < psVar10 + 4)) &&
             (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
             psVar10 + 4 <= psVar9)) {
            uVar2 = psVar10[1];
            param_2 = (short *)(ulonglong)uVar2;
            psVar8 = (short *)0x4;
            if (3 < uVar2) {
              psVar8 = param_2;
            }
            if (psVar10 < (short *)((longlong)(psVar8 + 2) + (longlong)psVar10)) {
              if (uVar2 < 4) {
                param_2 = (short *)0x4;
              }
              if ((short *)((longlong)(param_2 + 2) + (longlong)psVar10) <= psVar9) {
                if (*psVar10 != 0) goto LAB_14000ca15;
                *(undefined4 *)(AcAdapter + 0x4b0) = *(undefined4 *)(psVar10 + 2);
                if ((ushort)psVar10[1] < 4) {
                  uVar4 = 4;
                }
                else {
                  uVar4 = (ulonglong)(ushort)psVar10[1];
                }
                psVar10 = (short *)(uVar4 + 4 + (longlong)psVar10);
                if (((psVar10 < (short *)(local_res8 + 0xcU)) ||
                    (param_2 = psVar10 + 4, param_2 <= psVar10)) ||
                   (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc +
                                      local_res8), psVar9 < param_2)) {
LAB_14000cac7:
                  uVar6 = 0xc0140005;
                }
                else {
                  uVar2 = psVar10[1];
                  param_2 = (short *)(ulonglong)uVar2;
                  psVar8 = (short *)0x4;
                  if (3 < uVar2) {
                    psVar8 = param_2;
                  }
                  if ((short *)((longlong)(psVar8 + 2) + (longlong)psVar10) <= psVar10)
                  goto LAB_14000cac7;
                  psVar8 = param_2;
                  if (uVar2 < 4) {
                    psVar8 = (short *)0x4;
                  }
                  if (psVar9 < (short *)((longlong)(psVar8 + 2) + (longlong)psVar10))
                  goto LAB_14000cac7;
                  if (*psVar10 == 0) {
                    *(undefined4 *)(AcAdapter + 0x4b4) = *(undefined4 *)(psVar10 + 2);
                    goto LAB_14000cabf;
                  }
LAB_14000caa8:
                  uVar6 = 0xc014000f;
                }
                uVar7 = 7;
                goto LAB_14000cafb;
              }
            }
          }
LAB_14000cad1:
          uVar6 = 0xc0140005;
          goto LAB_14000cad6;
        }
LAB_14000c970:
        uVar6 = 0xc014000f;
      }
      uVar7 = 5;
      goto LAB_14000cafb;
    }
    uVar6 = 0xc014000f;
  }
  else {
LAB_14000caeb:
    uVar6 = 0xc0140005;
  }
  uVar7 = 4;
LAB_14000cafb:
  lVar3 = local_res8;
  CmBattTraceAdapterWattageRequirements((int)uVar6,param_2,uVar7,'\0');
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0x4d746142);
  }
  return uVar6;
}



===== AcAdapterSetRecOverride @ 14000cb3c =====

ulonglong AcAdapterSetRecOverride(byte param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined4 *)0x0;
  if ((*(uint *)(AcAdapter + 0x488) >> 2 & 1) == 0) {
    uVar3 = 0xc0000002;
    uVar4 = 1;
  }
  else {
    param_2 = 0x40;
    param_3 = (undefined4 *)0x4d746142;
    puVar1 = (undefined4 *)ExAllocatePool2(0x100,0x40,0x4d746142);
    uVar4 = 2;
    if (puVar1 == (undefined4 *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      puVar1[1] = 0x4d53445f;
      *puVar1 = 0x43696541;
      puVar1[2] = 0x40;
      puVar1[3] = 4;
      param_2 = 0x10;
      puVar1[4] = 0x100002;
      memcpy_s(puVar1 + 5,0x10,&GUID_DSM_AC_ADAPTER,0x10);
      uVar2 = (ulonglong)*(ushort *)((longlong)puVar1 + 0x12);
      if (*(ushort *)((longlong)puVar1 + 0x12) < 4) {
        uVar2 = 4;
      }
      *(undefined8 *)((longlong)puVar1 + uVar2 + 0x14) = 0x40000;
      *(undefined4 *)((longlong)puVar1 + uVar2 + 0x1c) = 0x40000;
      *(undefined4 *)((longlong)puVar1 + uVar2 + 0x20) = 2;
      *(undefined4 *)((longlong)puVar1 + uVar2 + 0x24) = 0x80004;
      *(undefined4 *)((longlong)puVar1 + uVar2 + 0x28) = 0x40000;
      *(uint *)((longlong)puVar1 + uVar2 + 0x2c) = (uint)param_1;
      param_3 = puVar1;
      uVar2 = CmBattSendDownStreamIrp(*(undefined8 *)(AcAdapter + 0x18),param_2,puVar1,0x40,0,0);
      uVar3 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) {
        uVar4 = 3;
      }
      else {
        uVar4 = 0;
        *(byte *)(AcAdapter + 0x491) = param_1;
      }
    }
  }
  CmBattTraceRecOverride
            ((int)uVar3,param_2,(uint)CONCAT71((int7)((ulonglong)param_3 >> 8),param_1),uVar4,'\0');
  if (puVar1 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar1,0x4d746142);
  }
  return uVar3;
}



===== CmBattCancelWatchdog @ 14000ccb0 =====

void CmBattCancelWatchdog(longlong param_1)

{
  ExCancelTimer(*(undefined8 *)(param_1 + 0x690),0);
  *(undefined4 *)(param_1 + 0x6cc) = 3;
  KeFlushQueuedDpcs();
  KeEnterCriticalRegion();
  KeWaitForSingleObject(param_1 + 0x6a0,0,0,0,0);
  KeLeaveCriticalRegion();
  return;
}



===== CmBattGetBixData @ 14000cd2c =====

ulonglong CmBattGetBixData(longlong param_1,int *param_2)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  undefined4 local_res18;
  undefined4 local_res1c;
  
  lVar2 = ExAllocatePool2(0x100,0x200,0x4d746142);
  if (lVar2 == 0) {
    return 0xc000009a;
  }
  uVar4 = 0;
  memset(param_2,0,0x444);
  local_res1c = 0x5849425f;
  local_res18 = 0x42696541;
  iVar10 = 0x5849425f;
  uVar3 = CmBattSendDownStreamIrp(*(undefined8 *)(param_1 + 0x20),uVar4,&local_res18,8,lVar2,0x200);
  if (((int)uVar3 < 0) || (*(uint *)(lVar2 + 8) < 0x14)) {
    iVar10 = 0x4649425f;
    local_res1c = 0x4649425f;
    local_res18 = 0x42696541;
    uVar3 = CmBattSendDownStreamIrp
                      (*(undefined8 *)(param_1 + 0x20),uVar4,&local_res18,8,lVar2,0x200);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) goto LAB_14000cf13;
    if (0xc < *(uint *)(lVar2 + 8)) goto LAB_14000ce10;
    goto LAB_14000d9e5;
  }
LAB_14000ce10:
  psVar8 = (short *)(lVar2 + 0xc);
  if ((psVar8 < (short *)(lVar2 + 0x14U)) &&
     (psVar6 = (short *)((ulonglong)(*(int *)(lVar2 + 4) - 0xc) + 0xc + lVar2),
     (short *)(lVar2 + 0x14U) <= psVar6)) {
    uVar1 = *(ushort *)(lVar2 + 0xe);
    uVar5 = (ulonglong)uVar1;
    uVar3 = 4;
    if (3 < uVar1) {
      uVar3 = uVar5;
    }
    if (psVar8 < (short *)(uVar3 + 4 + (longlong)psVar8)) {
      if (uVar1 < 4) {
        uVar5 = 4;
      }
      if ((short *)(uVar5 + 4 + (longlong)psVar8) <= psVar6) {
        iVar9 = -1;
        *param_2 = iVar10;
        if (iVar10 == 0x5849425f) {
          if (*psVar8 != 0) goto LAB_14000d9e5;
          param_2[1] = *(int *)(lVar2 + 0x10);
          if (*(ushort *)(lVar2 + 0xe) < 4) {
            uVar3 = 4;
          }
          else {
            uVar3 = (ulonglong)*(ushort *)(lVar2 + 0xe);
          }
          psVar6 = (short *)(lVar2 + 0x10 + uVar3);
          if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4)) &&
             (psVar7 = (short *)((ulonglong)(*(int *)(lVar2 + 4) - 0xc) + 0xc + lVar2),
             psVar6 + 4 <= psVar7)) {
            uVar1 = psVar6[1];
            uVar5 = (ulonglong)uVar1;
            uVar3 = 4;
            if (3 < uVar1) {
              uVar3 = uVar5;
            }
            if (psVar6 < (short *)(uVar3 + 4 + (longlong)psVar6)) {
              if (uVar1 < 4) {
                uVar5 = 4;
              }
              if ((short *)(uVar5 + 4 + (longlong)psVar6) <= psVar7) goto LAB_14000cf48;
            }
          }
        }
        else {
          param_2[1] = -1;
          psVar6 = psVar8;
LAB_14000cf48:
          if (*psVar6 != 0) goto LAB_14000d9e5;
          param_2[2] = *(int *)(psVar6 + 2);
          uVar3 = (ulonglong)(ushort)psVar6[1];
          if ((ushort)psVar6[1] < 4) {
            uVar3 = 4;
          }
          psVar6 = (short *)(uVar3 + 4 + (longlong)psVar6);
          if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4)) &&
             (psVar7 = (short *)((ulonglong)(*(int *)(lVar2 + 4) - 0xc) + 0xc + lVar2),
             psVar6 + 4 <= psVar7)) {
            uVar1 = psVar6[1];
            uVar5 = (ulonglong)uVar1;
            uVar3 = 4;
            if (3 < uVar1) {
              uVar3 = uVar5;
            }
            if (psVar6 < (short *)(uVar3 + 4 + (longlong)psVar6)) {
              if (uVar1 < 4) {
                uVar5 = 4;
              }
              if ((short *)(uVar5 + 4 + (longlong)psVar6) <= psVar7) {
                if (*psVar6 != 0) goto LAB_14000d9e5;
                param_2[3] = *(int *)(psVar6 + 2);
                if ((ushort)psVar6[1] < 4) {
                  uVar3 = 4;
                }
                else {
                  uVar3 = (ulonglong)(ushort)psVar6[1];
                }
                psVar6 = (short *)(uVar3 + 4 + (longlong)psVar6);
                if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4)) &&
                   (psVar7 = (short *)((ulonglong)(*(int *)(lVar2 + 4) - 0xc) + 0xc + lVar2),
                   psVar6 + 4 <= psVar7)) {
                  uVar1 = psVar6[1];
                  uVar5 = (ulonglong)uVar1;
                  uVar3 = 4;
                  if (3 < uVar1) {
                    uVar3 = uVar5;
                  }
                  if (psVar6 < (short *)(uVar3 + 4 + (longlong)psVar6)) {
                    if (uVar1 < 4) {
                      uVar5 = 4;
                    }
                    if ((short *)(uVar5 + 4 + (longlong)psVar6) <= psVar7) {
                      if (*psVar6 != 0) goto LAB_14000d9e5;
                      param_2[4] = *(int *)(psVar6 + 2);
                      if ((ushort)psVar6[1] < 4) {
                        uVar3 = 4;
                      }
                      else {
                        uVar3 = (ulonglong)(ushort)psVar6[1];
                      }
                      psVar6 = (short *)(uVar3 + 4 + (longlong)psVar6);
                      if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4)) &&
                         (psVar7 = (short *)((ulonglong)(*(int *)(lVar2 + 4) - 0xc) + 0xc + lVar2),
                         psVar6 + 4 <= psVar7)) {
                        uVar1 = psVar6[1];
                        uVar5 = (ulonglong)uVar1;
                        uVar3 = 4;
                        if (3 < uVar1) {
                          uVar3 = uVar5;
                        }
                        if (psVar6 < (short *)(uVar3 + 4 + (longlong)psVar6)) {
                          if (uVar1 < 4) {
                            uVar5 = 4;
                          }
                          if ((short *)(uVar5 + 4 + (longlong)psVar6) <= psVar7) {
                            if (*psVar6 != 0) goto LAB_14000d9e5;
                            param_2[5] = *(int *)(psVar6 + 2);
                            if ((ushort)psVar6[1] < 4) {
                              uVar3 = 4;
                            }
                            else {
                              uVar3 = (ulonglong)(ushort)psVar6[1];
                            }
                            psVar6 = (short *)(uVar3 + 4 + (longlong)psVar6);
                            if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4)) &&
                               (psVar7 = (short *)((ulonglong)(*(int *)(lVar2 + 4) - 0xc) + 0xc +
                                                  lVar2), psVar6 + 4 <= psVar7)) {
                              uVar1 = psVar6[1];
                              uVar5 = (ulonglong)uVar1;
                              uVar3 = 4;
                              if (3 < uVar1) {
                                uVar3 = uVar5;
                              }
                              if (psVar6 < (short *)(uVar3 + 4 + (longlong)psVar6)) {
                                if (uVar1 < 4) {
                                  uVar5 = 4;
                                }
                                if ((short *)(uVar5 + 4 + (longlong)psVar6) <= psVar7) {
                                  if (*psVar6 != 0) goto LAB_14000d9e5;
                                  param_2[6] = *(int *)(psVar6 + 2);
                                  if ((ushort)psVar6[1] < 4) {
                                    uVar3 = 4;
                                  }
                                  else {
                                    uVar3 = (ulonglong)(ushort)psVar6[1];
                                  }
                                  psVar6 = (short *)(uVar3 + 4 + (longlong)psVar6);
                                  if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4)) &&
                                     (psVar7 = (short *)((ulonglong)(*(int *)(lVar2 + 4) - 0xc) +
                                                         0xc + lVar2), psVar6 + 4 <= psVar7)) {
                                    uVar1 = psVar6[1];
                                    uVar5 = (ulonglong)uVar1;
                                    uVar3 = 4;
                                    if (3 < uVar1) {
                                      uVar3 = uVar5;
                                    }
                                    if (psVar6 < (short *)(uVar3 + 4 + (longlong)psVar6)) {
                                      if (uVar1 < 4) {
                                        uVar5 = 4;
                                      }
                                      if ((short *)(uVar5 + 4 + (longlong)psVar6) <= psVar7) {
                                        if (*psVar6 != 0) goto LAB_14000d9e5;
                                        param_2[7] = *(int *)(psVar6 + 2);
                                        if ((ushort)psVar6[1] < 4) {
                                          uVar3 = 4;
                                        }
                                        else {
                                          uVar3 = (ulonglong)(ushort)psVar6[1];
                                        }
                                        psVar6 = (short *)(uVar3 + 4 + (longlong)psVar6);
                                        if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4)) &&
                                           (psVar7 = (short *)((ulonglong)
                                                               (*(int *)(lVar2 + 4) - 0xc) + 0xc +
                                                              lVar2), psVar6 + 4 <= psVar7)) {
                                          uVar1 = psVar6[1];
                                          uVar5 = (ulonglong)uVar1;
                                          uVar3 = 4;
                                          if (3 < uVar1) {
                                            uVar3 = uVar5;
                                          }
                                          if (psVar6 < (short *)(uVar3 + 4 + (longlong)psVar6)) {
                                            if (uVar1 < 4) {
                                              uVar5 = 4;
                                            }
                                            if ((short *)(uVar5 + 4 + (longlong)psVar6) <= psVar7) {
                                              if (*psVar6 != 0) goto LAB_14000d9e5;
                                              param_2[8] = *(int *)(psVar6 + 2);
                                              if (iVar10 == 0x5849425f) {
                                                if ((ushort)psVar6[1] < 4) {
                                                  uVar3 = 4;
                                                }
                                                else {
                                                  uVar3 = (ulonglong)(ushort)psVar6[1];
                                                }
                                                psVar6 = (short *)(uVar3 + 4 + (longlong)psVar6);
                                                if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4)) &&
                                                   (psVar7 = (short *)((ulonglong)
                                                                       (*(int *)(lVar2 + 4) - 0xc) +
                                                                       0xc + lVar2),
                                                   psVar6 + 4 <= psVar7)) {
                                                  uVar1 = psVar6[1];
                                                  uVar5 = (ulonglong)uVar1;
                                                  uVar3 = 4;
                                                  if (3 < uVar1) {
                                                    uVar3 = uVar5;
                                                  }
                                                  if (psVar6 < (short *)(uVar3 + 4 +
                                                                        (longlong)psVar6)) {
                                                    if (uVar1 < 4) {
                                                      uVar5 = 4;
                                                    }
                                                    if ((short *)(uVar5 + 4 + (longlong)psVar6) <=
                                                        psVar7) {
                                                      if (*psVar6 != 0) goto LAB_14000d9e5;
                                                      param_2[9] = *(int *)(psVar6 + 2);
                                                      if ((ushort)psVar6[1] < 4) {
                                                        uVar3 = 4;
                                                      }
                                                      else {
                                                        uVar3 = (ulonglong)(ushort)psVar6[1];
                                                      }
                                                      psVar6 = (short *)(uVar3 + 4 +
                                                                        (longlong)psVar6);
                                                      if (((psVar8 <= psVar6) &&
                                                          (psVar6 < psVar6 + 4)) &&
                                                         (psVar7 = (short *)((ulonglong)
                                                                             (*(int *)(lVar2 + 4) -
                                                                             0xc) + 0xc + lVar2),
                                                         psVar6 + 4 <= psVar7)) {
                                                        uVar1 = psVar6[1];
                                                        uVar5 = (ulonglong)uVar1;
                                                        uVar3 = 4;
                                                        if (3 < uVar1) {
                                                          uVar3 = uVar5;
                                                        }
                                                        if (psVar6 < (short *)(uVar3 + 4 +
                                                                              (longlong)psVar6)) {
                                                          if (uVar1 < 4) {
                                                            uVar5 = 4;
                                                          }
                                                          if ((short *)(uVar5 + 4 + (longlong)psVar6
                                                                       ) <= psVar7) {
                                                            if (*psVar6 != 0) goto LAB_14000d9e5;
                                                            param_2[10] = *(int *)(psVar6 + 2);
                                                            if ((ushort)psVar6[1] < 4) {
                                                              uVar3 = 4;
                                                            }
                                                            else {
                                                              uVar3 = (ulonglong)(ushort)psVar6[1];
                                                            }
                                                            psVar6 = (short *)((longlong)psVar6 +
                                                                              uVar3 + 4);
                                                            if (((psVar8 <= psVar6) &&
                                                                (psVar6 < psVar6 + 4)) &&
                                                               (psVar7 = (short *)((ulonglong)
                                                                                   (*(int *)(lVar2 +
                                                                                            4) - 0xc
                                                                                   ) + 0xc + lVar2),
                                                               psVar6 + 4 <= psVar7)) {
                                                              uVar1 = psVar6[1];
                                                              uVar5 = (ulonglong)uVar1;
                                                              uVar3 = 4;
                                                              if (3 < uVar1) {
                                                                uVar3 = uVar5;
                                                              }
                                                              if (psVar6 < (short *)(uVar3 + 4 +
                                                                                    (longlong)psVar6
                                                                                    )) {
                                                                if (uVar1 < 4) {
                                                                  uVar5 = 4;
                                                                }
                                                                if ((short *)(uVar5 + 4 +
                                                                             (longlong)psVar6) <=
                                                                    psVar7) {
                                                                  if (*psVar6 != 0)
                                                                  goto LAB_14000d9e5;
                                                                  param_2[0xb] = *(int *)(psVar6 + 2
                                                                                         );
                                                                  if ((ushort)psVar6[1] < 4) {
                                                                    uVar3 = 4;
                                                                  }
                                                                  else {
                                                                    uVar3 = (ulonglong)
                                                                            (ushort)psVar6[1];
                                                                  }
                                                                  psVar6 = (short *)((longlong)
                                                                                     psVar6 + uVar3 
                                                  + 4);
                                                  if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4))
                                                     && (psVar7 = (short *)((ulonglong)
                                                                            (*(int *)(lVar2 + 4) -
                                                                            0xc) + 0xc + lVar2),
                                                        psVar6 + 4 <= psVar7)) {
                                                    uVar1 = psVar6[1];
                                                    uVar5 = (ulonglong)uVar1;
                                                    uVar3 = 4;
                                                    if (3 < uVar1) {
                                                      uVar3 = uVar5;
                                                    }
                                                    if (psVar6 < (short *)(uVar3 + 4 +
                                                                          (longlong)psVar6)) {
                                                      if (uVar1 < 4) {
                                                        uVar5 = 4;
                                                      }
                                                      if ((short *)(uVar5 + 4 + (longlong)psVar6) <=
                                                          psVar7) {
                                                        if (*psVar6 != 0) goto LAB_14000d9e5;
                                                        param_2[0xc] = *(int *)(psVar6 + 2);
                                                        if ((ushort)psVar6[1] < 4) {
                                                          uVar3 = 4;
                                                        }
                                                        else {
                                                          uVar3 = (ulonglong)(ushort)psVar6[1];
                                                        }
                                                        psVar6 = (short *)((longlong)psVar6 +
                                                                          uVar3 + 4);
                                                        if (((psVar8 <= psVar6) &&
                                                            (psVar6 < psVar6 + 4)) &&
                                                           (psVar7 = (short *)((ulonglong)
                                                                               (*(int *)(lVar2 + 4)
                                                                               - 0xc) + 0xc + lVar2)
                                                           , psVar6 + 4 <= psVar7)) {
                                                          uVar1 = psVar6[1];
                                                          uVar5 = (ulonglong)uVar1;
                                                          uVar3 = 4;
                                                          if (3 < uVar1) {
                                                            uVar3 = uVar5;
                                                          }
                                                          if (psVar6 < (short *)(uVar3 + 4 +
                                                                                (longlong)psVar6)) {
                                                            if (uVar1 < 4) {
                                                              uVar5 = 4;
                                                            }
                                                            if ((short *)(uVar5 + 4 +
                                                                         (longlong)psVar6) <= psVar7
                                                               ) {
                                                              if (*psVar6 != 0) {
LAB_14000d9e5:
                                                                uVar5 = 0xc014000f;
                                                                goto LAB_14000cf13;
                                                              }
                                                              param_2[0xd] = *(int *)(psVar6 + 2);
                                                              if ((ushort)psVar6[1] < 4) {
                                                                uVar3 = 4;
                                                              }
                                                              else {
                                                                uVar3 = (ulonglong)(ushort)psVar6[1]
                                                                ;
                                                              }
                                                              psVar6 = (short *)((longlong)psVar6 +
                                                                                uVar3 + 4);
                                                              if (((psVar8 <= psVar6) &&
                                                                  (psVar6 < psVar6 + 4)) &&
                                                                 (psVar7 = (short *)((ulonglong)
                                                                                     (*(int *)(lVar2
                                                                                              + 4) -
                                                                                     0xc) + 0xc +
                                                                                    lVar2),
                                                                 psVar6 + 4 <= psVar7)) {
                                                                uVar1 = psVar6[1];
                                                                uVar5 = (ulonglong)uVar1;
                                                                uVar3 = 4;
                                                                if (3 < uVar1) {
                                                                  uVar3 = uVar5;
                                                                }
                                                                if (psVar6 < (short *)(uVar3 + 4 +
                                                                                      (longlong)
                                                                                      psVar6)) {
                                                                  if (uVar1 < 4) {
                                                                    uVar5 = 4;
                                                                  }
                                                                  if ((short *)(uVar5 + 4 +
                                                                               (longlong)psVar6) <=
                                                                      psVar7) {
                                                                    if (*psVar6 == 0) {
                                                                      iVar9 = *(int *)(psVar6 + 2);
                                                                      goto LAB_14000d623;
                                                                    }
                                                                    goto LAB_14000d9e5;
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                              else {
                                                param_2[9] = -1;
                                                param_2[10] = -1;
                                                param_2[0xb] = -1;
                                                param_2[0xc] = -1;
                                                param_2[0xd] = -1;
LAB_14000d623:
                                                param_2[0xe] = iVar9;
                                                uVar3 = (ulonglong)(ushort)psVar6[1];
                                                if ((ushort)psVar6[1] < 4) {
                                                  uVar3 = 4;
                                                }
                                                psVar6 = (short *)(uVar3 + 4 + (longlong)psVar6);
                                                if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4)) &&
                                                   (psVar7 = (short *)((ulonglong)
                                                                       (*(int *)(lVar2 + 4) - 0xc) +
                                                                       0xc + lVar2),
                                                   psVar6 + 4 <= psVar7)) {
                                                  uVar1 = psVar6[1];
                                                  uVar5 = (ulonglong)uVar1;
                                                  uVar3 = 4;
                                                  if (3 < uVar1) {
                                                    uVar3 = uVar5;
                                                  }
                                                  if (psVar6 < (short *)(uVar3 + 4 +
                                                                        (longlong)psVar6)) {
                                                    if (uVar1 < 4) {
                                                      uVar5 = 4;
                                                    }
                                                    if ((short *)(uVar5 + 4 + (longlong)psVar6) <=
                                                        psVar7) {
                                                      if (*psVar6 != 0) goto LAB_14000d9e5;
                                                      param_2[0xf] = *(int *)(psVar6 + 2);
                                                      if ((ushort)psVar6[1] < 4) {
                                                        uVar3 = 4;
                                                      }
                                                      else {
                                                        uVar3 = (ulonglong)(ushort)psVar6[1];
                                                      }
                                                      psVar6 = (short *)(uVar3 + 4 +
                                                                        (longlong)psVar6);
                                                      if (((psVar8 <= psVar6) &&
                                                          (psVar6 < psVar6 + 4)) &&
                                                         (psVar7 = (short *)((ulonglong)
                                                                             (*(int *)(lVar2 + 4) -
                                                                             0xc) + 0xc + lVar2),
                                                         psVar6 + 4 <= psVar7)) {
                                                        uVar1 = psVar6[1];
                                                        uVar5 = (ulonglong)uVar1;
                                                        uVar3 = 4;
                                                        if (3 < uVar1) {
                                                          uVar3 = uVar5;
                                                        }
                                                        if (psVar6 < (short *)(uVar3 + 4 +
                                                                              (longlong)psVar6)) {
                                                          if (uVar1 < 4) {
                                                            uVar5 = 4;
                                                          }
                                                          if ((short *)(uVar5 + 4 + (longlong)psVar6
                                                                       ) <= psVar7) {
                                                            if (*psVar6 != 0) goto LAB_14000d9e5;
                                                            param_2[0x10] = *(int *)(psVar6 + 2);
                                                            if ((ushort)psVar6[1] < 4) {
                                                              uVar3 = 4;
                                                            }
                                                            else {
                                                              uVar3 = (ulonglong)(ushort)psVar6[1];
                                                            }
                                                            psVar6 = (short *)(uVar3 + 4 +
                                                                              (longlong)psVar6);
                                                            if (((psVar8 <= psVar6) &&
                                                                (psVar6 < psVar6 + 4)) &&
                                                               (psVar7 = (short *)((ulonglong)
                                                                                   (*(int *)(lVar2 +
                                                                                            4) - 0xc
                                                                                   ) + 0xc + lVar2),
                                                               psVar6 + 4 <= psVar7)) {
                                                              uVar1 = psVar6[1];
                                                              uVar5 = (ulonglong)uVar1;
                                                              uVar3 = 4;
                                                              if (3 < uVar1) {
                                                                uVar3 = uVar5;
                                                              }
                                                              if (psVar6 < (short *)(uVar3 + 4 +
                                                                                    (longlong)psVar6
                                                                                    )) {
                                                                if (uVar1 < 4) {
                                                                  uVar5 = 4;
                                                                }
                                                                if ((short *)(uVar5 + 4 +
                                                                             (longlong)psVar6) <=
                                                                    psVar7) {
                                                                  memset(param_2 + 0x11,0,0x100);
                                                                  uVar3 = GetStringElement(psVar6,
                                                  param_2 + 0x11);
                                                  uVar5 = uVar3 & 0xffffffff;
                                                  if ((int)uVar3 < 0) goto LAB_14000cf13;
                                                  if ((ushort)psVar6[1] < 4) {
                                                    uVar3 = 4;
                                                  }
                                                  else {
                                                    uVar3 = (ulonglong)(ushort)psVar6[1];
                                                  }
                                                  psVar6 = (short *)((longlong)psVar6 + uVar3 + 4);
                                                  if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4))
                                                     && (psVar7 = (short *)((ulonglong)
                                                                            (*(int *)(lVar2 + 4) -
                                                                            0xc) + 0xc + lVar2),
                                                        psVar6 + 4 <= psVar7)) {
                                                    uVar1 = psVar6[1];
                                                    uVar5 = (ulonglong)uVar1;
                                                    uVar3 = 4;
                                                    if (3 < uVar1) {
                                                      uVar3 = uVar5;
                                                    }
                                                    if (psVar6 < (short *)(uVar3 + 4 +
                                                                          (longlong)psVar6)) {
                                                      if (uVar1 < 4) {
                                                        uVar5 = 4;
                                                      }
                                                      if ((short *)(uVar5 + 4 + (longlong)psVar6) <=
                                                          psVar7) {
                                                        memset(param_2 + 0x51,0,0x100);
                                                        uVar3 = GetStringElement(psVar6,param_2 + 
                                                  0x51);
                                                  uVar5 = uVar3 & 0xffffffff;
                                                  if ((int)uVar3 < 0) goto LAB_14000cf13;
                                                  if ((ushort)psVar6[1] < 4) {
                                                    uVar3 = 4;
                                                  }
                                                  else {
                                                    uVar3 = (ulonglong)(ushort)psVar6[1];
                                                  }
                                                  psVar6 = (short *)((longlong)psVar6 + uVar3 + 4);
                                                  if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4))
                                                     && (psVar7 = (short *)((ulonglong)
                                                                            (*(int *)(lVar2 + 4) -
                                                                            0xc) + 0xc + lVar2),
                                                        psVar6 + 4 <= psVar7)) {
                                                    uVar1 = psVar6[1];
                                                    uVar5 = (ulonglong)uVar1;
                                                    uVar3 = 4;
                                                    if (3 < uVar1) {
                                                      uVar3 = uVar5;
                                                    }
                                                    if (psVar6 < (short *)(uVar3 + 4 +
                                                                          (longlong)psVar6)) {
                                                      if (uVar1 < 4) {
                                                        uVar5 = 4;
                                                      }
                                                      if ((short *)(uVar5 + 4 + (longlong)psVar6) <=
                                                          psVar7) {
                                                        memset(param_2 + 0x91,0,0x100);
                                                        uVar3 = GetStringElement(psVar6,param_2 + 
                                                  0x91);
                                                  uVar5 = uVar3 & 0xffffffff;
                                                  if ((int)uVar3 < 0) goto LAB_14000cf13;
                                                  memset(param_2 + 0xd1,0,0x100);
                                                  if ((ushort)psVar6[1] < 4) {
                                                    uVar3 = 4;
                                                  }
                                                  else {
                                                    uVar3 = (ulonglong)(ushort)psVar6[1];
                                                  }
                                                  psVar6 = (short *)(uVar3 + 4 + (longlong)psVar6);
                                                  if (((psVar8 <= psVar6) && (psVar6 < psVar6 + 4))
                                                     && (psVar8 = (short *)((ulonglong)
                                                                            (*(int *)(lVar2 + 4) -
                                                                            0xc) + 0xc + lVar2),
                                                        psVar6 + 4 <= psVar8)) {
                                                    uVar1 = psVar6[1];
                                                    uVar5 = (ulonglong)uVar1;
                                                    uVar3 = 4;
                                                    if (3 < uVar1) {
                                                      uVar3 = uVar5;
                                                    }
                                                    if (psVar6 < (short *)(uVar3 + 4 +
                                                                          (longlong)psVar6)) {
                                                      if (uVar1 < 4) {
                                                        uVar5 = 4;
                                                      }
                                                      if ((short *)(uVar5 + 4 + (longlong)psVar6) <=
                                                          psVar8) {
                                                        if (*psVar6 == 0) {
                                                          if (*(int *)(psVar6 + 2) != 0)
                                                          goto LAB_14000d9e5;
                                                          *(undefined1 *)(param_2 + 0xd1) = 0;
                                                        }
                                                        else {
                                                          uVar3 = GetStringElement(psVar6,param_2 + 
                                                  0xd1);
                                                  uVar5 = uVar3 & 0xffffffff;
                                                  if ((int)uVar3 < 0) goto LAB_14000cf13;
                                                  }
                                                  uVar5 = 0;
                                                  goto LAB_14000cf13;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar5 = 0xc0140005;
LAB_14000cf13:
  ExFreePoolWithTag(lVar2,0);
  return uVar5;
}



===== CmBattGetBpcData @ 14000da18 =====

ulonglong CmBattGetBpcData(undefined1 *param_1,undefined1 *param_2,undefined4 *param_3,
                          undefined4 *param_4,undefined8 param_5)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  short *psVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  short *psVar9;
  longlong local_res8;
  undefined4 local_res10;
  undefined4 local_res14;
  
  local_res14 = 0x4350425f;
  *param_1 = 0;
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  local_res8 = 0;
  local_res10 = 0x42696541;
  uVar4 = CmBattGetMethodOutput(&local_res8,param_5,&local_res10);
  uVar7 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) goto LAB_14000dcbf;
  if (*(uint *)(local_res8 + 8) < 4) goto LAB_14000da7f;
  uVar4 = local_res8 + 0xc;
  if ((uVar4 < local_res8 + 0x14U) &&
     (uVar7 = (ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8,
     local_res8 + 0x14U <= uVar7)) {
    uVar2 = *(ushort *)(local_res8 + 0xe);
    uVar8 = (ulonglong)uVar2;
    uVar5 = 4;
    if (3 < uVar2) {
      uVar5 = uVar8;
    }
    if (uVar4 < uVar5 + 4 + uVar4) {
      if (uVar2 < 4) {
        uVar8 = 4;
      }
      if (local_res8 + 0x10 + uVar8 <= uVar7) {
        if (uVar2 < 4) {
          uVar7 = 4;
        }
        else {
          uVar7 = (ulonglong)*(ushort *)(local_res8 + 0xe);
        }
        lVar1 = uVar7 + uVar4;
        psVar6 = (short *)(lVar1 + 4);
        if ((((short *)(local_res8 + 0xcU) <= psVar6) && (psVar6 < (short *)(lVar1 + 0xcU))) &&
           (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
           (short *)(lVar1 + 0xcU) <= psVar9)) {
          uVar2 = *(ushort *)(lVar1 + 6);
          uVar7 = (ulonglong)uVar2;
          uVar4 = 4;
          if (3 < uVar2) {
            uVar4 = uVar7;
          }
          if (psVar6 < (short *)(uVar4 + 8 + lVar1)) {
            if (uVar2 < 4) {
              uVar7 = 4;
            }
            if ((short *)(uVar7 + 8 + lVar1) <= psVar9) {
              if (*psVar6 != 0) goto LAB_14000da7f;
              uVar3 = *(uint *)(lVar1 + 8);
              if ((uVar3 & 1) != 0) {
                *param_1 = 1;
              }
              if ((uVar3 & 2) != 0) {
                *param_2 = 1;
              }
              if (*(ushort *)(lVar1 + 6) < 4) {
                uVar4 = 4;
              }
              else {
                uVar4 = (ulonglong)*(ushort *)(lVar1 + 6);
              }
              psVar6 = (short *)(uVar4 + 8 + lVar1);
              if ((((short *)(local_res8 + 0xcU) <= psVar6) && (psVar6 < psVar6 + 4)) &&
                 (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8)
                 , psVar6 + 4 <= psVar9)) {
                uVar2 = psVar6[1];
                uVar7 = (ulonglong)uVar2;
                uVar4 = 4;
                if (3 < uVar2) {
                  uVar4 = uVar7;
                }
                if (psVar6 < (short *)(uVar4 + 4 + (longlong)psVar6)) {
                  if (uVar2 < 4) {
                    uVar7 = 4;
                  }
                  if ((short *)(uVar7 + 4 + (longlong)psVar6) <= psVar9) {
                    if (*psVar6 != 0) {
LAB_14000da7f:
                      uVar7 = 0xc014000f;
                      goto LAB_14000dcbf;
                    }
                    *param_3 = *(undefined4 *)(psVar6 + 2);
                    if ((ushort)psVar6[1] < 4) {
                      uVar4 = 4;
                    }
                    else {
                      uVar4 = (ulonglong)(ushort)psVar6[1];
                    }
                    psVar6 = (short *)(uVar4 + 4 + (longlong)psVar6);
                    if ((((short *)(local_res8 + 0xcU) <= psVar6) && (psVar6 < psVar6 + 4)) &&
                       (psVar9 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc +
                                          local_res8), psVar6 + 4 <= psVar9)) {
                      uVar2 = psVar6[1];
                      uVar7 = (ulonglong)uVar2;
                      uVar4 = 4;
                      if (3 < uVar2) {
                        uVar4 = uVar7;
                      }
                      if (psVar6 < (short *)(uVar4 + 4 + (longlong)psVar6)) {
                        if (uVar2 < 4) {
                          uVar7 = 4;
                        }
                        if ((short *)(uVar7 + 4 + (longlong)psVar6) <= psVar9) {
                          if (*psVar6 == 0) {
                            uVar7 = 0;
                            *param_4 = *(undefined4 *)(psVar6 + 2);
                            goto LAB_14000dcbf;
                          }
                          goto LAB_14000da7f;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar7 = 0xc0140005;
LAB_14000dcbf:
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0x4d746142);
  }
  return uVar7;
}



===== CmBattGetBpsData @ 14000dcf0 =====

ulonglong CmBattGetBpsData(undefined1 *param_1,undefined8 param_2)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  short *psVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  short *psVar8;
  longlong local_res18;
  undefined4 local_res20;
  undefined4 local_res24;
  
  local_res24 = 0x5350425f;
  local_res20 = 0x42696541;
  local_res18 = 0;
  uVar3 = CmBattGetMethodOutput(&local_res18,param_2,&local_res20);
  lVar2 = local_res18;
  uVar5 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    uVar6 = 1;
    goto LAB_14000e069;
  }
  if (*(uint *)(local_res18 + 8) < 5) {
    uVar5 = 0xc014000f;
    uVar6 = 2;
    goto LAB_14000e069;
  }
  psVar4 = (short *)(local_res18 + 0xc);
  if ((psVar4 < (short *)(local_res18 + 0x14U)) &&
     (psVar8 = (short *)((ulonglong)(*(int *)(local_res18 + 4) - 0xc) + 0xc + local_res18),
     (short *)(local_res18 + 0x14U) <= psVar8)) {
    uVar1 = *(ushort *)(local_res18 + 0xe);
    uVar5 = (ulonglong)uVar1;
    uVar7 = 4;
    uVar6 = 4;
    uVar3 = 4;
    if (3 < uVar1) {
      uVar3 = uVar5;
    }
    if ((short *)(uVar3 + 4 + (longlong)psVar4) <= psVar4) goto LAB_14000e05e;
    if (uVar1 < 4) {
      uVar5 = 4;
    }
    if (psVar8 < (short *)(local_res18 + 0x10 + uVar5)) goto LAB_14000e05e;
    if (*psVar4 == 0) {
      *param_1 = (char)*(undefined4 *)(local_res18 + 0x10);
      if (*(ushort *)(local_res18 + 0xe) < 4) {
        uVar3 = 4;
      }
      else {
        uVar3 = (ulonglong)*(ushort *)(local_res18 + 0xe);
      }
      psVar4 = (short *)(local_res18 + 0x10 + uVar3);
      if ((((short *)(local_res18 + 0xcU) <= psVar4) && (psVar4 < psVar4 + 4)) &&
         (psVar8 = (short *)((ulonglong)(*(int *)(local_res18 + 4) - 0xc) + 0xc + local_res18),
         psVar4 + 4 <= psVar8)) {
        uVar1 = psVar4[1];
        uVar5 = (ulonglong)uVar1;
        uVar3 = 4;
        if (3 < uVar1) {
          uVar3 = uVar5;
        }
        if (psVar4 < (short *)(uVar3 + 4 + (longlong)psVar4)) {
          if (uVar1 < 4) {
            uVar5 = 4;
          }
          if ((short *)(uVar5 + 4 + (longlong)psVar4) <= psVar8) {
            if (*psVar4 != 0) {
              uVar5 = 0xc014000f;
              goto LAB_14000e069;
            }
            *(undefined4 *)(param_1 + 4) = *(undefined4 *)(psVar4 + 2);
            if ((ushort)psVar4[1] < 4) {
              uVar3 = 4;
            }
            else {
              uVar3 = (ulonglong)(ushort)psVar4[1];
            }
            psVar4 = (short *)(uVar3 + 4 + (longlong)psVar4);
            if ((((short *)(local_res18 + 0xcU) <= psVar4) && (psVar4 < psVar4 + 4)) &&
               (psVar8 = (short *)((ulonglong)(*(int *)(local_res18 + 4) - 0xc) + 0xc + local_res18)
               , psVar4 + 4 <= psVar8)) {
              uVar1 = psVar4[1];
              uVar5 = (ulonglong)uVar1;
              uVar3 = 4;
              if (3 < uVar1) {
                uVar3 = uVar5;
              }
              if (psVar4 < (short *)(uVar3 + 4 + (longlong)psVar4)) {
                if (uVar1 < 4) {
                  uVar5 = 4;
                }
                if ((short *)(uVar5 + 4 + (longlong)psVar4) <= psVar8) {
                  if (*psVar4 != 0) {
                    uVar5 = 0xc014000f;
                    uVar6 = 5;
                    goto LAB_14000e069;
                  }
                  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(psVar4 + 2);
                  if ((ushort)psVar4[1] < 4) {
                    uVar3 = 4;
                  }
                  else {
                    uVar3 = (ulonglong)(ushort)psVar4[1];
                  }
                  psVar4 = (short *)((longlong)psVar4 + uVar3 + 4);
                  if (((psVar4 < (short *)(local_res18 + 0xcU)) || (psVar4 + 4 <= psVar4)) ||
                     (psVar8 = (short *)((ulonglong)(*(int *)(local_res18 + 4) - 0xc) + 0xc +
                                        local_res18), psVar8 < psVar4 + 4)) {
LAB_14000e047:
                    uVar5 = 0xc0140005;
                  }
                  else {
                    uVar1 = psVar4[1];
                    uVar5 = (ulonglong)uVar1;
                    uVar3 = 4;
                    if (3 < uVar1) {
                      uVar3 = uVar5;
                    }
                    if ((short *)(uVar3 + 4 + (longlong)psVar4) <= psVar4) goto LAB_14000e047;
                    if (uVar1 < 4) {
                      uVar5 = 4;
                    }
                    if (psVar8 < (short *)(uVar5 + 4 + (longlong)psVar4)) goto LAB_14000e047;
                    if (*psVar4 == 0) {
                      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(psVar4 + 2);
                      if ((ushort)psVar4[1] < 4) {
                        uVar3 = 4;
                      }
                      else {
                        uVar3 = (ulonglong)(ushort)psVar4[1];
                      }
                      psVar4 = (short *)(uVar3 + 4 + (longlong)psVar4);
                      if (((psVar4 < (short *)(local_res18 + 0xcU)) || (psVar4 + 4 <= psVar4)) ||
                         (psVar8 = (short *)((ulonglong)(*(int *)(local_res18 + 4) - 0xc) + 0xc +
                                            local_res18), psVar8 < psVar4 + 4)) {
LAB_14000e03a:
                        uVar5 = 0xc0140005;
                      }
                      else {
                        uVar1 = psVar4[1];
                        uVar5 = (ulonglong)uVar1;
                        uVar3 = 4;
                        if (3 < uVar1) {
                          uVar3 = uVar5;
                        }
                        if ((short *)(uVar3 + 4 + (longlong)psVar4) <= psVar4) goto LAB_14000e03a;
                        if (uVar1 < 4) {
                          uVar5 = 4;
                        }
                        if (psVar8 < (short *)(uVar5 + 4 + (longlong)psVar4)) goto LAB_14000e03a;
                        if (*psVar4 == 0) {
                          uVar5 = 0;
                          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(psVar4 + 2);
                          uVar6 = 0;
                          goto LAB_14000e069;
                        }
                        uVar5 = 0xc014000f;
                      }
                      uVar6 = 7;
                      goto LAB_14000e069;
                    }
                    uVar5 = 0xc014000f;
                  }
                  uVar6 = 6;
                  goto LAB_14000e069;
                }
              }
            }
            uVar7 = 5;
          }
        }
      }
      uVar6 = uVar7;
      uVar5 = 0xc0140005;
      goto LAB_14000e069;
    }
    uVar5 = 0xc014000f;
  }
  else {
LAB_14000e05e:
    uVar5 = 0xc0140005;
  }
  uVar6 = 3;
LAB_14000e069:
  CmBattTraceBps((int)uVar5,(longlong)param_1,uVar6,'\0');
  if ((int)uVar5 < 0) {
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0x4d746142);
  }
  return uVar5;
}



===== CmBattGetBstData @ 14000e0b8 =====

ulonglong CmBattGetBstData(longlong param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  undefined4 local_res18;
  undefined4 local_res1c;
  
  uVar8 = 0x200;
  piVar6 = (int *)ExAllocatePool2(0x100,0x200,0x4d746142);
  if (piVar6 == (int *)0x0) {
    return 0xc000009a;
  }
  local_res18 = 0x42696541;
  local_res1c = 0x5453425f;
  uVar7 = CmBattSendDownStreamIrp
                    (*(undefined8 *)(param_1 + 0x20),uVar8,&local_res18,8,(longlong)piVar6,0x200);
  uVar9 = uVar7 & 0xffffffff;
  if (*(char *)(param_1 + 0x6c8) != '\0') {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 0x6b8,0);
    if (*(char *)(param_1 + 0x6c9) != '\0') {
      CmBattCancelWatchdog(param_1);
      CmBattQueueWatchdog(param_1);
    }
    ExReleasePushLockExclusiveEx(param_1 + 0x6b8,0);
    KeLeaveCriticalRegion();
  }
  if ((int)uVar7 < 0) goto LAB_14000e48e;
  if ((*piVar6 != 0x426f6541) || (piVar6[2] != 4)) goto LAB_14000e489;
  piVar11 = piVar6 + 3;
  if ((piVar11 < piVar6 + 5) &&
     (piVar10 = (int *)((ulonglong)(piVar6[1] - 0xc) + 0xc + (longlong)piVar6),
     piVar6 + 5 <= piVar10)) {
    uVar1 = *(ushort *)((longlong)piVar6 + 0xe);
    uVar9 = (ulonglong)uVar1;
    uVar7 = 4;
    if (3 < uVar1) {
      uVar7 = uVar9;
    }
    if (piVar11 < (int *)(uVar7 + 4 + (longlong)piVar11)) {
      if (uVar1 < 4) {
        uVar9 = 4;
      }
      if ((int *)(uVar9 + 4 + (longlong)piVar11) <= piVar10) {
        if ((short)*piVar11 != 0) goto LAB_14000e489;
        if (uVar1 < 4) {
          uVar7 = 4;
        }
        else {
          uVar7 = (ulonglong)*(ushort *)((longlong)piVar6 + 0xe);
        }
        piVar10 = (int *)((longlong)piVar6 + uVar7 + 0x10);
        if (((piVar11 <= piVar10) && (piVar10 < piVar10 + 2)) &&
           (piVar13 = (int *)((ulonglong)(piVar6[1] - 0xc) + 0xc + (longlong)piVar6),
           piVar10 + 2 <= piVar13)) {
          uVar1 = *(ushort *)((longlong)piVar10 + 2);
          uVar9 = (ulonglong)uVar1;
          uVar7 = 4;
          if (3 < uVar1) {
            uVar7 = uVar9;
          }
          if (piVar10 < (int *)(uVar7 + 4 + (longlong)piVar10)) {
            if (uVar1 < 4) {
              uVar9 = 4;
            }
            if ((int *)(uVar9 + 4 + (longlong)piVar10) <= piVar13) {
              if ((short)*piVar10 != 0) goto LAB_14000e489;
              uVar2 = piVar10[1];
              if (uVar1 < 4) {
                uVar7 = 4;
              }
              else {
                uVar7 = (ulonglong)*(ushort *)((longlong)piVar10 + 2);
              }
              piVar10 = (int *)((longlong)piVar10 + uVar7 + 4);
              if (((piVar11 <= piVar10) && (piVar10 < piVar10 + 2)) &&
                 (piVar13 = (int *)((ulonglong)(piVar6[1] - 0xc) + 0xc + (longlong)piVar6),
                 piVar10 + 2 <= piVar13)) {
                uVar1 = *(ushort *)((longlong)piVar10 + 2);
                uVar9 = (ulonglong)uVar1;
                uVar7 = 4;
                if (3 < uVar1) {
                  uVar7 = uVar9;
                }
                if (piVar10 < (int *)(uVar7 + 4 + (longlong)piVar10)) {
                  if (uVar1 < 4) {
                    uVar9 = 4;
                  }
                  if ((int *)(uVar9 + 4 + (longlong)piVar10) <= piVar13) {
                    if ((short)*piVar10 != 0) {
LAB_14000e489:
                      uVar9 = 0xc014000f;
                      goto LAB_14000e48e;
                    }
                    uVar3 = piVar10[1];
                    if (uVar1 < 4) {
                      uVar7 = 4;
                    }
                    else {
                      uVar7 = (ulonglong)*(ushort *)((longlong)piVar10 + 2);
                    }
                    piVar10 = (int *)((longlong)piVar10 + uVar7 + 4);
                    if (((piVar11 <= piVar10) && (piVar10 < piVar10 + 2)) &&
                       (piVar11 = (int *)((ulonglong)(piVar6[1] - 0xc) + 0xc + (longlong)piVar6),
                       piVar10 + 2 <= piVar11)) {
                      uVar1 = *(ushort *)((longlong)piVar10 + 2);
                      uVar9 = (ulonglong)uVar1;
                      uVar7 = 4;
                      if (3 < uVar1) {
                        uVar7 = uVar9;
                      }
                      if (piVar10 < (int *)(uVar7 + 4 + (longlong)piVar10)) {
                        if (uVar1 < 4) {
                          uVar9 = 4;
                        }
                        if ((int *)(uVar9 + 4 + (longlong)piVar10) <= piVar11) {
                          if ((short)*piVar10 == 0) {
                            uVar4 = piVar10[1];
                            uVar9 = 0;
                            uVar12 = (uint)piVar6[4] >> 3 & 1;
                            *param_2 = piVar6[4];
                            param_2[1] = uVar2;
                            param_2[2] = uVar3;
                            param_2[3] = uVar4;
                            if ((*(longlong *)(param_1 + 0x6f0) != 0) &&
                               ((*(uint *)(param_1 + 0x6e8) & 1) != uVar12)) {
                              *(uint *)(param_1 + 0x6e8) = uVar12;
                              LOCK();
                              piVar11 = (int *)(param_1 + 0x6ec);
                              iVar5 = *piVar11;
                              *piVar11 = *piVar11 + 1;
                              UNLOCK();
                              if ((iVar5 == 0) &&
                                 (iVar5 = IoAcquireRemoveLockEx
                                                    (param_1 + 0xc0,*(undefined8 *)(param_1 + 0x6f0)
                                                     ,"",1,0x20), -1 < iVar5)) {
                                IoQueueWorkItem(*(undefined8 *)(param_1 + 0x6f0),
                                                CmBattUpdateDataCompletionWorker,1,0);
                              }
                            }
                            goto LAB_14000e48e;
                          }
                          goto LAB_14000e489;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar9 = 0xc0140005;
LAB_14000e48e:
  ExFreePoolWithTag(piVar6,0);
  return uVar9;
}



===== CmBattGetExtendedSupport @ 14000e4c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CmBattGetExtendedSupport(longlong param_1)

{
  short *psVar1;
  ushort uVar2;
  bool bVar3;
  longlong lVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  short *psVar9;
  undefined1 auStackY_f8 [32];
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  longlong local_b8 [2];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined *local_98;
  uint local_90;
  undefined4 local_8c;
  undefined *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  longlong *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  longlong *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  lVar4 = ExAllocatePool2(0x100,0x200,0x4d746142);
  if (lVar4 != 0) {
    puVar5 = (undefined4 *)ExAllocatePool2(0x100,0x3c,0x4d746142);
    if (puVar5 != (undefined4 *)0x0) {
      uVar7 = 0x10;
      puVar5[1] = 0x4d53445f;
      *puVar5 = 0x43696541;
      puVar5[2] = 0x3c;
      puVar5[3] = 4;
      puVar5[4] = 0x100002;
      memcpy_s(puVar5 + 5,0x10,&GUID_DSM_BATTERY_EXT,0x10);
      uVar6 = (ulonglong)*(ushort *)((longlong)puVar5 + 0x12);
      if (*(ushort *)((longlong)puVar5 + 0x12) < 4) {
        uVar6 = 4;
      }
      *(undefined8 *)((longlong)puVar5 + uVar6 + 0x14) = 0x40000;
      *(undefined8 *)((longlong)puVar5 + uVar6 + 0x1c) = 0x40000;
      *(undefined4 *)((longlong)puVar5 + uVar6 + 0x24) = 4;
      uVar6 = CmBattSendDownStreamIrp(*(undefined8 *)(param_1 + 0x20),uVar7,puVar5,0x3c,lVar4,0x200)
      ;
      if ((-1 < (int)uVar6) && (*(int *)(lVar4 + 8) == 1)) {
        psVar1 = (short *)(lVar4 + 0xc);
        if ((psVar1 < (short *)(lVar4 + 0x14U)) &&
           (psVar9 = (short *)((ulonglong)(*(int *)(lVar4 + 4) - 0xc) + 0xc + lVar4),
           (short *)(lVar4 + 0x14U) <= psVar9)) {
          uVar2 = *(ushort *)(lVar4 + 0xe);
          uVar8 = (ulonglong)uVar2;
          uVar6 = 4;
          if (3 < uVar2) {
            uVar6 = uVar8;
          }
          if (psVar1 < (short *)(uVar6 + 4 + (longlong)psVar1)) {
            if (uVar2 < 4) {
              uVar8 = 4;
            }
            if (((((short *)(uVar8 + 4 + (longlong)psVar1) <= psVar9) && (*psVar1 == 2)) &&
                (uVar2 != 0)) && ((*(byte *)(lVar4 + 0x10) & 1) != 0)) {
              if ((*(byte *)(lVar4 + 0x10) & 2) != 0) {
                *(undefined1 *)(param_1 + 0x680) = 1;
              }
              if ((*(byte *)(lVar4 + 0x10) & 4) != 0) {
                CmBattGetUserServiceable(param_1);
              }
              if ((*(byte *)(lVar4 + 0x10) & 8) != 0) {
                CmBattGetWatchdog(param_1);
              }
            }
          }
        }
      }
      ExFreePoolWithTag(puVar5,0x4d746142);
    }
    ExFreePoolWithTag(lVar4,0x4d746142);
  }
  if (5 < DAT_140007010) {
    if (((_DAT_140007020 & 0x400000000000) == 0) ||
       (bVar3 = true, (DAT_140007028 & 0x400000000000) != DAT_140007028)) {
      bVar3 = false;
    }
    if (bVar3) {
      local_a0 = 0x400000000000;
      local_b8[0] = param_1 + 0x168;
      local_78 = local_b8;
      local_70 = 8;
      local_c8 = *(undefined4 *)(param_1 + 0x6cc);
      local_68 = &local_c8;
      local_c4 = *(undefined4 *)(param_1 + 0x6c0);
      local_58 = &local_c4;
      local_48 = local_b8 + 1;
      local_a4 = 5;
      local_98 = PTR_DAT_140007018;
      local_60 = 4;
      local_50 = 4;
      local_b8[1] = 0x1000000;
      local_40 = 8;
      local_a8 = 0xb000000;
      local_90 = (uint)*(ushort *)PTR_DAT_140007018;
      local_88 = &DAT_14000561c;
      local_8c = 2;
      local_80 = 0x6e;
      local_7c = 1;
      local_c0 = 0xc9;
      EtwWriteTransfer(DAT_140007030,&local_a8,0,0);
    }
  }
  return;
}



===== CmBattGetMethodOutput @ 14000e7fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CmBattGetMethodOutput(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStackY_68 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_68;
  *param_1 = 0;
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar1 = CmBattSendDownStreamIrp(param_2,param_2,param_3,8,(longlong)&local_38,0x14);
  uVar3 = uVar1 & 0xffffffff;
  if ((int)uVar1 == -0x7ffffffb) {
    if (local_38._4_4_ == 0) goto LAB_14000e8b2;
    uVar1 = (ulonglong)local_38._4_4_;
    lVar2 = ExAllocatePool2(0x40,uVar1,0x4d746142);
    *param_1 = lVar2;
    if (lVar2 == 0) {
      uVar3 = 0xc000009a;
      goto LAB_14000e8b2;
    }
    uVar3 = CmBattSendDownStreamIrp(param_2,uVar1,param_3,8,lVar2,local_38._4_4_);
    uVar3 = uVar3 & 0xffffffff;
  }
  if (-1 < (int)uVar3) {
    return uVar3;
  }
LAB_14000e8b2:
  if (*param_1 != 0) {
    ExFreePoolWithTag(*param_1,0x4d746142);
    *param_1 = 0;
  }
  return uVar3;
}



===== CmBattGetPifData @ 14000e8f8 =====

ulonglong CmBattGetPifData(undefined4 *param_1,undefined4 *param_2,undefined8 param_3,char param_4)

{
  ushort uVar1;
  ulonglong uVar2;
  short *psVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  ulonglong uVar9;
  short *psVar10;
  longlong local_res8;
  undefined4 local_res10;
  undefined4 local_res14;
  
  local_res14 = 0x4649505f;
  *param_1 = 0;
  *param_2 = 0;
  local_res8 = 0;
  local_res10 = 0x42696541;
  uVar2 = CmBattGetMethodOutput(&local_res8,param_3,&local_res10);
  lVar6 = local_res8;
  uVar5 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    uVar8 = 1;
    goto LAB_14000edd4;
  }
  if (*(uint *)(local_res8 + 8) < 6) {
    uVar8 = 2;
LAB_14000e962:
    uVar5 = 0xc014000f;
    goto LAB_14000edd4;
  }
  uVar2 = local_res8 + 0xc;
  if ((uVar2 < local_res8 + 0x14U) &&
     (uVar5 = (ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8,
     local_res8 + 0x14U <= uVar5)) {
    uVar1 = *(ushort *)(local_res8 + 0xe);
    uVar9 = (ulonglong)uVar1;
    uVar7 = 4;
    uVar8 = 4;
    uVar4 = 4;
    if (3 < uVar1) {
      uVar4 = uVar9;
    }
    if (uVar4 + 4 + uVar2 <= uVar2) goto LAB_14000edca;
    if (uVar1 < 4) {
      uVar9 = 4;
    }
    if (uVar5 < local_res8 + 0x10 + uVar9) goto LAB_14000edca;
    if (uVar1 < 4) {
      uVar2 = 4;
    }
    else {
      uVar2 = (ulonglong)*(ushort *)(local_res8 + 0xe);
    }
    psVar3 = (short *)(local_res8 + 0x10 + uVar2);
    if (((psVar3 < (short *)(local_res8 + 0xcU)) || (psVar3 + 4 <= psVar3)) ||
       (psVar10 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
       psVar10 < psVar3 + 4)) goto LAB_14000edcf;
    uVar1 = psVar3[1];
    uVar5 = (ulonglong)uVar1;
    uVar2 = 4;
    if (3 < uVar1) {
      uVar2 = uVar5;
    }
    if ((short *)(uVar2 + 4 + (longlong)psVar3) <= psVar3) goto LAB_14000edcf;
    if (uVar1 < 4) {
      uVar5 = 4;
    }
    if (psVar10 < (short *)(uVar5 + 4 + (longlong)psVar3)) goto LAB_14000edcf;
    uVar5 = 0;
    if (*psVar3 != 0) goto LAB_14000e962;
    *param_1 = *(undefined4 *)(psVar3 + 2);
    if ((ushort)psVar3[1] < 4) {
      uVar2 = 4;
    }
    else {
      uVar2 = (ulonglong)(ushort)psVar3[1];
    }
    psVar3 = (short *)(uVar2 + 4 + (longlong)psVar3);
    if (((psVar3 < (short *)(local_res8 + 0xcU)) || (psVar3 + 4 <= psVar3)) ||
       (psVar10 = (short *)((ulonglong)(*(int *)(local_res8 + 4) - 0xc) + 0xc + local_res8),
       psVar10 < psVar3 + 4)) {
LAB_14000edc3:
      uVar7 = 5;
      goto LAB_14000edcf;
    }
    uVar1 = psVar3[1];
    uVar4 = (ulonglong)uVar1;
    uVar2 = 4;
    if (3 < uVar1) {
      uVar2 = uVar4;
    }
    if ((short *)(uVar2 + 4 + (longlong)psVar3) <= psVar3) goto LAB_14000edc3;
    if (uVar1 < 4) {
      uVar4 = 4;
    }
    if (psVar10 < (short *)(uVar4 + 4 + (longlong)psVar3)) goto LAB_14000edc3;
    if (*psVar3 == 0) {
      *param_2 = *(undefined4 *)(psVar3 + 2);
      if (param_4 == '\0') {
        uVar8 = 0;
        goto LAB_14000edd6;
      }
      memset((void *)(AcAdapter + 0x184),0,0x100);
      if ((ushort)psVar3[1] < 4) {
        uVar2 = 4;
      }
      else {
        uVar2 = (ulonglong)(ushort)psVar3[1];
        lVar6 = local_res8;
      }
      psVar3 = (short *)((longlong)psVar3 + uVar2 + 4);
      if ((((short *)(lVar6 + 0xcU) <= psVar3) && (psVar3 < psVar3 + 4)) &&
         (psVar10 = (short *)((ulonglong)(*(int *)(lVar6 + 4) - 0xc) + 0xc + lVar6),
         psVar3 + 4 <= psVar10)) {
        uVar1 = psVar3[1];
        uVar5 = (ulonglong)uVar1;
        uVar2 = 4;
        if (3 < uVar1) {
          uVar2 = uVar5;
        }
        if (psVar3 < (short *)(uVar2 + 4 + (longlong)psVar3)) {
          if (uVar1 < 4) {
            uVar5 = 4;
          }
          if ((short *)(uVar5 + 4 + (longlong)psVar3) <= psVar10) {
            if (*psVar3 == 0) {
              if (*(int *)(psVar3 + 2) != 0) {
                uVar5 = 0xc014000f;
                uVar8 = 6;
                goto LAB_14000edd4;
              }
            }
            else {
              uVar2 = GetStringElement(psVar3,(void *)(AcAdapter + 0x184));
              uVar5 = uVar2 & 0xffffffff;
              if ((int)uVar2 < 0) {
                uVar8 = 6;
                goto LAB_14000edd6;
              }
            }
            memset((void *)(AcAdapter + 0x284),0,0x100);
            if ((ushort)psVar3[1] < 4) {
              uVar2 = 4;
            }
            else {
              uVar2 = (ulonglong)(ushort)psVar3[1];
              lVar6 = local_res8;
            }
            psVar3 = (short *)((longlong)psVar3 + uVar2 + 4);
            if ((((short *)(lVar6 + 0xcU) <= psVar3) && (psVar3 < psVar3 + 4)) &&
               (psVar10 = (short *)((ulonglong)(*(int *)(lVar6 + 4) - 0xc) + 0xc + lVar6),
               psVar3 + 4 <= psVar10)) {
              uVar1 = psVar3[1];
              uVar5 = (ulonglong)uVar1;
              uVar2 = 4;
              if (3 < uVar1) {
                uVar2 = uVar5;
              }
              if (psVar3 < (short *)(uVar2 + 4 + (longlong)psVar3)) {
                if (uVar1 < 4) {
                  uVar5 = 4;
                }
                if ((short *)(uVar5 + 4 + (longlong)psVar3) <= psVar10) {
                  if (*psVar3 == 0) {
                    if (*(int *)(psVar3 + 2) != 0) {
                      uVar5 = 0xc014000f;
                      uVar8 = 7;
                      goto LAB_14000edd4;
                    }
                  }
                  else {
                    uVar2 = GetStringElement(psVar3,(void *)(AcAdapter + 0x284));
                    uVar5 = uVar2 & 0xffffffff;
                    if ((int)uVar2 < 0) {
                      uVar8 = 7;
                      goto LAB_14000edd6;
                    }
                  }
                  uVar5 = 0;
                  memset((void *)(AcAdapter + 900),0,0x100);
                  if ((ushort)psVar3[1] < 4) {
                    uVar2 = 4;
                  }
                  else {
                    uVar2 = (ulonglong)(ushort)psVar3[1];
                    lVar6 = local_res8;
                  }
                  psVar3 = (short *)(uVar2 + 4 + (longlong)psVar3);
                  if ((((short *)(lVar6 + 0xcU) <= psVar3) && (psVar3 < psVar3 + 4)) &&
                     (psVar10 = (short *)((ulonglong)(*(int *)(lVar6 + 4) - 0xc) + 0xc + lVar6),
                     psVar3 + 4 <= psVar10)) {
                    uVar1 = psVar3[1];
                    uVar4 = (ulonglong)uVar1;
                    uVar2 = 4;
                    if (3 < uVar1) {
                      uVar2 = uVar4;
                    }
                    if (psVar3 < (short *)(uVar2 + 4 + (longlong)psVar3)) {
                      if (uVar1 < 4) {
                        uVar4 = 4;
                      }
                      if ((short *)(uVar4 + 4 + (longlong)psVar3) <= psVar10) {
                        if (*psVar3 == 0) {
                          if (*(int *)(psVar3 + 2) != 0) {
                            uVar8 = 8;
                            goto LAB_14000e962;
                          }
                          uVar8 = 0;
                        }
                        else {
                          uVar2 = GetStringElement(psVar3,(void *)(AcAdapter + 900));
                          uVar8 = 0;
                          uVar5 = uVar2 & 0xffffffff;
                          if ((int)uVar2 < 0) {
                            uVar8 = 8;
                          }
                        }
                        goto LAB_14000edd4;
                      }
                    }
                  }
                  uVar7 = 8;
                  goto LAB_14000edcf;
                }
              }
            }
            uVar7 = 7;
            goto LAB_14000edcf;
          }
        }
      }
      uVar7 = 6;
      goto LAB_14000edcf;
    }
    uVar5 = 0xc014000f;
    uVar8 = 5;
  }
  else {
LAB_14000edca:
    uVar7 = 3;
LAB_14000edcf:
    uVar8 = uVar7;
    uVar5 = 0xc0140005;
  }
LAB_14000edd4:
LAB_14000edd6:
  CmBattTracePif((int)uVar5,*param_1,*param_2,uVar8,'\0');
  if ((int)uVar5 < 0) {
    *param_1 = 0xffffffff;
    *param_2 = 0xffffffff;
  }
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0x4d746142);
  }
  return uVar5;
}



===== CmBattGetPsrData @ 14000ee38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CmBattGetPsrData(undefined8 param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_20 = 0;
  *param_2 = 0;
  local_34 = 0x5253505f;
  local_38 = 0x42696541;
  local_30 = 0;
  uStack_28 = 0;
  uVar1 = CmBattSendDownStreamIrp(param_1,param_2,&local_38,8,(longlong)&local_30,0x14);
  if (-1 < (int)uVar1) {
    if (uStack_28._4_2_ == 0) {
      *param_2 = local_20;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc014000f;
    }
  }
  return uVar1;
}



===== CmBattGetPsrDataV1 @ 14000eed4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CmBattGetPsrDataV1(undefined8 param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_20 = 0;
  *param_2 = 0;
  local_34 = 0x5253505f;
  local_38 = 0x42696541;
  local_30 = 0;
  uStack_28 = 0;
  uVar1 = CmBattSendDownStreamIrp(param_1,param_2,&local_38,8,(longlong)&local_30,0x14);
  uVar2 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    if (uStack_28._4_2_ == 0) {
      uVar2 = 0;
      *param_2 = local_20;
    }
    else {
      uVar2 = 0xc014000f;
    }
  }
  CmBattTracePsr((int)uVar2,*param_2,'\0');
  return uVar2;
}



===== CmBattGetStaData @ 14000ef88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CmBattGetStaData(longlong param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  uVar2 = 0;
  local_20 = 0;
  *param_2 = 0;
  local_34 = 0x4154535f;
  local_38 = 0x42696541;
  local_30 = 0;
  uStack_28 = 0;
  uVar1 = CmBattSendDownStreamIrp
                    (*(undefined8 *)(param_1 + 0x20),param_2,&local_38,8,(longlong)&local_30,0x14);
  if ((int)uVar1 < 0) {
    uVar2 = 0xc000000e;
  }
  else if (uStack_28._4_2_ == 0) {
    *param_2 = local_20;
  }
  else {
    uVar2 = 0xc014000f;
  }
  return uVar2;
}



===== CmBattGetUserServiceable @ 14000f02c =====

void CmBattGetUserServiceable(longlong param_1)

{
  short *psVar1;
  ushort uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  short *psVar8;
  
  lVar3 = ExAllocatePool2(0x100,0x200,0x4d746142);
  if (lVar3 != 0) {
    puVar4 = (undefined4 *)ExAllocatePool2(0x100,0x3c,0x4d746142);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[1] = 0x4d53445f;
      uVar6 = 0x10;
      *puVar4 = 0x43696541;
      puVar4[2] = 0x3c;
      puVar4[3] = 4;
      puVar4[4] = 0x100002;
      memcpy_s(puVar4 + 5,0x10,&GUID_DSM_BATTERY_EXT,0x10);
      uVar5 = (ulonglong)*(ushort *)((longlong)puVar4 + 0x12);
      if (*(ushort *)((longlong)puVar4 + 0x12) < 4) {
        uVar5 = 4;
      }
      *(undefined8 *)((longlong)puVar4 + uVar5 + 0x14) = 0x40000;
      *(undefined4 *)((longlong)puVar4 + uVar5 + 0x1c) = 0x40000;
      *(undefined4 *)((longlong)puVar4 + uVar5 + 0x20) = 2;
      *(undefined4 *)((longlong)puVar4 + uVar5 + 0x24) = 4;
      uVar5 = CmBattSendDownStreamIrp(*(undefined8 *)(param_1 + 0x20),uVar6,puVar4,0x3c,lVar3,0x200)
      ;
      if ((-1 < (int)uVar5) && (*(int *)(lVar3 + 8) == 1)) {
        psVar1 = (short *)(lVar3 + 0xc);
        if ((psVar1 < (short *)(lVar3 + 0x14U)) &&
           (psVar8 = (short *)((ulonglong)(*(int *)(lVar3 + 4) - 0xc) + 0xc + lVar3),
           (short *)(lVar3 + 0x14U) <= psVar8)) {
          uVar2 = *(ushort *)(lVar3 + 0xe);
          uVar7 = (ulonglong)uVar2;
          uVar5 = 4;
          if (3 < uVar2) {
            uVar5 = uVar7;
          }
          if (psVar1 < (short *)(uVar5 + 4 + (longlong)psVar1)) {
            if (uVar2 < 4) {
              uVar7 = 4;
            }
            if (((short *)(lVar3 + 0x10 + uVar7) <= psVar8) && (*psVar1 == 0)) {
              *(uint *)(param_1 + 0x684) = 2 - (uint)(*(int *)(lVar3 + 0x10) != 0);
            }
          }
        }
      }
      ExFreePoolWithTag(puVar4,0x4d746142);
    }
    ExFreePoolWithTag(lVar3,0x4d746142);
  }
  return;
}



===== CmBattGetWatchdog @ 14000f1d4 =====

void CmBattGetWatchdog(longlong param_1)

{
  short *psVar1;
  ushort uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  ulonglong uVar9;
  short *psVar10;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0;
  lVar3 = ExAllocatePool2(0x100,0x200,0x4d746142);
  if (lVar3 != 0) {
    puVar4 = (undefined4 *)ExAllocatePool2(0x100,0x3c,0x4d746142);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[1] = 0x4d53445f;
      uVar7 = 0x10;
      *puVar4 = 0x43696541;
      puVar4[2] = 0x3c;
      puVar4[3] = 4;
      puVar4[4] = 0x100002;
      memcpy_s(puVar4 + 5,0x10,&GUID_DSM_BATTERY_EXT,0x10);
      uVar5 = (ulonglong)*(ushort *)((longlong)puVar4 + 0x12);
      if (*(ushort *)((longlong)puVar4 + 0x12) < 4) {
        uVar5 = 4;
      }
      *(undefined8 *)((longlong)puVar4 + uVar5 + 0x14) = 0x40000;
      *(undefined4 *)((longlong)puVar4 + uVar5 + 0x1c) = 0x40000;
      *(undefined4 *)((longlong)puVar4 + uVar5 + 0x20) = 3;
      *(undefined4 *)((longlong)puVar4 + uVar5 + 0x24) = 4;
      uVar5 = CmBattSendDownStreamIrp(*(undefined8 *)(param_1 + 0x20),uVar7,puVar4,0x3c,lVar3,0x200)
      ;
      if ((-1 < (int)uVar5) && (*(int *)(lVar3 + 8) == 1)) {
        psVar1 = (short *)(lVar3 + 0xc);
        if ((psVar1 < (short *)(lVar3 + 0x14U)) &&
           (psVar10 = (short *)((ulonglong)(*(int *)(lVar3 + 4) - 0xc) + 0xc + lVar3),
           (short *)(lVar3 + 0x14U) <= psVar10)) {
          uVar2 = *(ushort *)(lVar3 + 0xe);
          uVar9 = (ulonglong)uVar2;
          uVar5 = 4;
          if (3 < uVar2) {
            uVar5 = uVar9;
          }
          if (psVar1 < (short *)(uVar5 + 4 + (longlong)psVar1)) {
            if (uVar2 < 4) {
              uVar9 = 4;
            }
            if ((((short *)(uVar9 + 4 + (longlong)psVar1) <= psVar10) && (*psVar1 == 0)) &&
               (uVar8 = *(uint *)(lVar3 + 0x10), 0x1d < uVar8)) {
              if (300 < uVar8) {
                uVar8 = 300;
              }
              lVar6 = IoAllocateWorkItem(*(undefined8 *)(param_1 + 0x10));
              *(longlong *)(param_1 + 0x698) = lVar6;
              if (lVar6 != 0) {
                *(undefined8 *)(param_1 + 0x6b8) = 0;
                local_res10[0] = 0xf;
                lVar6 = Ordinal_4(CmBattWatchdogDispatch,param_1,local_res10,2);
                *(longlong *)(param_1 + 0x690) = lVar6;
                if (lVar6 != 0) {
                  KeInitializeEvent(param_1 + 0x6a0);
                  *(uint *)(param_1 + 0x6c0) = uVar8;
                  *(undefined4 *)(param_1 + 0x6cc) = 1;
                  CmBattTraceChargingWatchdog(param_1,'\0');
                }
              }
            }
          }
        }
      }
      ExFreePoolWithTag(puVar4,0x4d746142);
    }
    ExFreePoolWithTag(lVar3,0x4d746142);
  }
  return;
}



===== CmBattQueueWatchdog @ 14000f420 =====

void CmBattQueueWatchdog(longlong param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(*(int *)(param_1 + 0x6c0) * 90000) / 100;
  KeSetEvent(param_1 + 0x6a0,0,0);
  ExSetTimer(*(undefined8 *)(param_1 + 0x690),(ulonglong)uVar1 * -10000,uVar1 * 10000,0);
  *(undefined4 *)(param_1 + 0x6cc) = 2;
  return;
}



===== CmBattSendDownStreamIrp @ 14000f4a0 =====

ulonglong CmBattSendDownStreamIrp
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    longlong param_5,undefined4 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,1,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (0x32c004,param_1,param_3,param_4,param_5,param_6,1,&local_28,&local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      uVar2 = local_38 & 0xffffffff;
    }
    if (((-1 < (int)uVar2) && (param_5 != 0)) &&
       ((uStack_30 < 0x14 || (*(int *)(param_5 + 8) == 0)))) {
      uVar2 = 0xc014000f;
    }
  }
  return uVar2;
}



===== CmBattSetBptData @ 14000f5bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CmBattSetBptData(int *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  undefined1 auStackY_c8 [32];
  undefined8 local_98;
  undefined8 uStack_90;
  int local_88;
  undefined1 local_84 [4];
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88 = 0;
  local_7c = 0x5450425f;
  local_80 = 0x43696541;
  uVar3 = 3;
  local_78 = 0x28;
  local_74 = 3;
  local_70 = 0x40000;
  local_6c = 1;
  local_68 = 0x40000;
  local_98 = 0;
  uStack_90 = 0;
  local_60 = 0x40000;
  local_64 = param_3;
  local_5c = param_4;
  uVar2 = CmBattSendDownStreamIrp(param_2,param_2,&local_80,0x28,(longlong)&local_98,0x14);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    uVar3 = 2;
  }
  else {
    if (local_84 <= local_84 + ((ulonglong)(local_98._4_4_ - 0xc) - 8)) {
      uVar2 = 4;
      if (3 < uStack_90._6_2_) {
        uVar2 = (ulonglong)uStack_90._6_2_;
      }
      if ((undefined1 *)((longlong)&uStack_90 + 4U) < local_84 + (uVar2 - 4)) {
        uVar2 = 4;
        if (3 < uStack_90._6_2_) {
          uVar2 = (ulonglong)uStack_90._6_2_;
        }
        if (local_84 + (uVar2 - 4) <= local_84 + ((ulonglong)(local_98._4_4_ - 0xc) - 8)) {
          if (uStack_90._4_2_ == 0) {
            iVar1 = 0;
            *param_1 = local_88;
            if (local_88 == 0) {
              uVar3 = 0;
            }
            else {
              uVar3 = 4;
              iVar1 = -0x3fffffff;
            }
          }
          else {
            iVar1 = -0x3febfff1;
          }
          goto LAB_14000f6e2;
        }
      }
    }
    iVar1 = -0x3febfffb;
  }
LAB_14000f6e2:
  CmBattTraceBpt(param_3,param_4,iVar1,*param_1,uVar3,'\0');
  return iVar1;
}



===== CmBattSetThrottle @ 14000f728 =====

ulonglong CmBattSetThrottle(longlong param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x100,0x40,0x4d746142);
  if (puVar1 == (undefined4 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    puVar1[1] = 0x4d53445f;
    *puVar1 = 0x43696541;
    puVar1[2] = 0x40;
    puVar1[3] = 4;
    uVar2 = 0x10;
    puVar1[4] = 0x100002;
    memcpy_s(puVar1 + 5,0x10,&GUID_DSM_BATTERY_EXT,0x10);
    uVar3 = (ulonglong)*(ushort *)((longlong)puVar1 + 0x12);
    if (*(ushort *)((longlong)puVar1 + 0x12) < 4) {
      uVar3 = 4;
    }
    *(undefined8 *)((longlong)puVar1 + uVar3 + 0x14) = 0x40000;
    *(undefined4 *)((longlong)puVar1 + uVar3 + 0x1c) = 0x40000;
    *(undefined4 *)((longlong)puVar1 + uVar3 + 0x20) = 1;
    *(undefined4 *)((longlong)puVar1 + uVar3 + 0x24) = 0x80004;
    *(undefined4 *)((longlong)puVar1 + uVar3 + 0x28) = 0x40000;
    *(undefined4 *)((longlong)puVar1 + uVar3 + 0x2c) = param_2;
    uVar3 = CmBattSendDownStreamIrp(*(undefined8 *)(param_1 + 0x20),uVar2,puVar1,0x40,0,0);
    uVar3 = uVar3 & 0xffffffff;
    ExFreePoolWithTag(puVar1,0x4d746142);
  }
  return uVar3;
}



===== CmBattSetTripPpoint @ 14000f840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattSetTripPpoint(longlong param_1,undefined8 param_2)

{
  undefined1 auStackY_58 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_20 = (undefined4)param_2;
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  local_24 = 0x5054425f;
  local_28 = 0x49696541;
  CmBattSendDownStreamIrp(*(undefined8 *)(param_1 + 0x20),param_2,&local_28,0xc,0,0);
  return;
}



===== CmBattStartWatchdog @ 14000f8a0 =====

void CmBattStartWatchdog(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0x6b8,0);
  *(undefined1 *)(param_1 + 0x6c9) = 1;
  CmBattQueueWatchdog(param_1);
  ExReleasePushLockExclusiveEx(param_1 + 0x6b8,0);
  KeLeaveCriticalRegion();
  return;
}



===== CmBattStopWatchdog @ 14000f910 =====

void CmBattStopWatchdog(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0x6b8,0);
  *(undefined1 *)(param_1 + 0x6c9) = 0;
  CmBattCancelWatchdog(param_1);
  ExReleasePushLockExclusiveEx(param_1 + 0x6b8,0);
  KeLeaveCriticalRegion();
  return;
}



===== CmBattUpdateDataCompletionWorker @ 14000f980 =====

void CmBattUpdateDataCompletionWorker(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  undefined8 local_res8;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  local_res8 = 1;
  do {
    do {
      LOCK();
      bVar4 = *(int *)(lVar3 + 0x6ec) == *(int *)(lVar3 + 0x6ec);
      if (bVar4) {
        *(int *)(lVar3 + 0x6ec) = 1;
      }
      UNLOCK();
    } while (!bVar4);
    local_res8 = CONCAT44(*(undefined4 *)(lVar3 + 0x6e8),(undefined4)local_res8);
    BatteryClassUpdateData(*(undefined8 *)(lVar3 + 0x168),&local_res8);
    LOCK();
    piVar1 = (int *)(lVar3 + 0x6ec);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  } while (1 < iVar2);
  IoReleaseRemoveLockEx(lVar3 + 0xc0,*(undefined8 *)(lVar3 + 0x6f0),0x20);
  return;
}



===== CmBattWatchdogWork @ 14000fa20 =====

void CmBattWatchdogWork(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined4 local_res10;
  undefined4 local_res14;
  
  *(undefined4 *)(param_2 + 0x6cc) = 4;
  uVar1 = 0;
  CmBattTraceChargingWatchdog(param_2,'\0');
  local_res10 = 0x42696541;
  local_res14 = 0x5453425f;
  CmBattSendDownStreamIrp(*(undefined8 *)(param_2 + 0x20),uVar1,&local_res10,8,0,0);
  KeSetEvent(param_2 + 0x6a0,0,0);
  LOCK();
  *(undefined4 *)(param_2 + 0x6c4) = 0;
  UNLOCK();
  return;
}



===== GetStringElement @ 14000fa9c =====

undefined8 GetStringElement(short *param_1,void *param_2)

{
  undefined8 uVar1;
  
  if ((ushort)(*param_1 - 1U) < 2) {
    if ((ushort)param_1[1] < 0x100) {
      memmove(param_2,param_1 + 2,(ulonglong)(ushort)param_1[1]);
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc0000023;
    }
  }
  else {
    uVar1 = 0xc014000f;
  }
  return uVar1;
}



===== CmBattAddAcAdapterV1 @ 14000fae8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CmBattAddAcAdapterV1(undefined8 param_1,undefined8 param_2)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int *piVar4;
  longlong lVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  ulonglong uVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  undefined1 auStackY_108 [32];
  longlong local_d8;
  int local_d0 [2];
  undefined8 local_c8;
  int *local_c0;
  undefined8 local_b8;
  longlong local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined8 local_80;
  code *local_78;
  code *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_108;
  local_d8 = 0;
  memset(&local_c8,0,0x70);
  uVar9 = CmBattCreateFdo(param_1,param_2,0x4c8,0,&local_d8);
  lVar5 = local_d8;
  iVar8 = (int)uVar9;
  if (iVar8 < 0) {
    uVar13 = 1;
    goto LAB_14000fbe8;
  }
  piVar1 = *(int **)(local_d8 + 0x40);
  iVar8 = CmBattWmiRegistration((longlong)piVar1);
  uVar12 = iVar8 >> 0x1f & 2;
  iVar8 = (**(code **)(piVar1 + 0x4e))(*(undefined8 *)(piVar1 + 0x3e),CmBattNotifyHandlerV1,piVar1);
  uVar13 = uVar12 | 4;
  if (-1 < iVar8) {
    uVar13 = uVar12;
  }
  KeAcquireGuardedMutex(&DeviceObjectMutex);
  if (AcAdapter == (int *)0x0) {
    AcAdapter = piVar1;
    KeReleaseGuardedMutex(&DeviceObjectMutex);
    piVar11 = AcAdapter + 0x60;
    piVar10 = AcAdapter + 0x5f;
    uVar9 = CmBattGetPifData(piVar10,piVar11,*(undefined8 *)(AcAdapter + 8),'\x01');
    piVar4 = AcAdapter;
    if ((int)uVar9 < 0) {
      AcAdapter[0x5c] = AcAdapter[0x5c] & 0xfffffffe;
      piVar4[0x5f] = -1;
      piVar4[0x60] = -1;
    }
    else {
      AcAdapter[0x5c] = AcAdapter[0x5c] | 1;
    }
    local_58 = (int *)0x0;
    uStack_50 = 0;
    local_38 = 0;
    local_48 = (longlong *)0x0;
    uStack_40 = 0;
    uVar9 = AcAdapterGetRecCapabilities(piVar10);
    if ((int)uVar9 < 0) {
LAB_14000fd64:
      local_c0 = AcAdapter;
      local_90 = 0;
      uStack_8c = 0;
      uStack_88 = 0;
      uStack_84 = 0;
      local_58 = (int *)CONCAT44(local_58._4_4_,0xffffffff);
      piVar11 = AcAdapter;
      piVar11[0x12a] = -1;
      piVar11[299] = -1;
      piVar11[300] = -1;
      piVar11[0x12d] = -1;
      piVar11[0x12e] = -1;
      piVar11[0x12f] = -1;
      piVar11[0x130] = -1;
      piVar11[0x131] = -1;
    }
    else {
      uVar9 = AcAdapterGetRecSupported(piVar10,(short *)piVar11);
      if (-1 < (int)uVar9) {
        uVar7 = local_58._4_1_;
        if ((*(byte *)(AcAdapter + 0x5c) & 2) != 0) {
          uVar7 = 1;
        }
        local_58._0_5_ = CONCAT14(uVar7,(undefined4)local_58);
      }
      uVar9 = AcAdapterGetWattageRequirements(piVar10,(short *)piVar11);
      if ((int)uVar9 < 0) goto LAB_14000fd64;
      uStack_50 = *(undefined8 *)(AcAdapter + 0x12a);
      uVar2 = *(undefined8 *)(AcAdapter + 300);
      uVar3 = *(undefined8 *)(AcAdapter + 0x12e);
      local_38 = *(undefined8 *)(AcAdapter + 0x130);
      local_58 = (int *)CONCAT44(local_58._4_4_,AcAdapter[0x121]);
      local_48._0_4_ = (undefined4)uVar2;
      local_48._4_4_ = (undefined4)((ulonglong)uVar2 >> 0x20);
      uStack_40._0_4_ = (undefined4)uVar3;
      uStack_40._4_4_ = (undefined4)((ulonglong)uVar3 >> 0x20);
      local_c0 = AcAdapter;
      local_90 = (undefined4)local_48;
      uStack_8c = local_48._4_4_;
      uStack_88 = (undefined4)uStack_40;
      uStack_84 = uStack_40._4_4_;
      local_48 = (longlong *)uVar2;
      uStack_40 = uVar3;
    }
    local_78 = CmBattQueryAdapterStatus;
    local_a0 = local_58;
    uStack_98 = uStack_50;
    local_80 = local_38;
    local_c8 = 1;
    local_b0 = lVar5;
    local_a8 = 0;
    local_70 = CmBattSetAdapterStatus;
    local_68 = 0;
    local_60 = 0;
    local_b8 = param_2;
    iVar8 = AdapterClassInitializeDevice(&local_c8,local_c0 + 0x5a);
    if (iVar8 < 0) {
      uVar9 = Feature_1178837306__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 != 0) {
        IoWMIRegistrationControl(*(undefined8 *)(piVar1 + 4),2);
      }
      KeAcquireGuardedMutex(&DeviceObjectMutex);
      IoDetachDevice(*(undefined8 *)(piVar1 + 8));
      CmBattDestroyFdo(*(longlong *)(piVar1 + 4));
      uVar9 = Feature_1178837306__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 != 0) {
        AcAdapter = (int *)0x0;
      }
      KeReleaseGuardedMutex(&DeviceObjectMutex);
      uVar13 = uVar13 | 0x10;
      goto LAB_14000fbe8;
    }
  }
  else {
    KeReleaseGuardedMutex();
    uVar13 = uVar13 | 8;
  }
  CmBattNotifyHandlerV1(piVar1,0x80);
  iVar8 = 0;
LAB_14000fbe8:
  local_d8 = CONCAT44(local_d8._4_4_,uVar13);
  if ((CmBattEtwRegistered != '\0') &&
     (local_d0[0] = iVar8, cVar6 = EtwEventEnabled(CmBattEtwHandle,&BATTERY_EVT_ADAPTER_ADD),
     cVar6 != '\0')) {
    local_58 = local_d0;
    local_48 = &local_d8;
    uStack_50 = 4;
    uStack_40 = 4;
    EtwWrite(CmBattEtwHandle,&BATTERY_EVT_ADAPTER_ADD,0,2);
  }
  return iVar8;
}



===== CmBattAddBattery @ 14000fe68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CmBattAddBattery(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  code *pcVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined1 auStackY_178 [8];
  undefined1 auStackY_170 [24];
  undefined8 local_148;
  undefined4 local_140;
  int local_13c;
  longlong local_138 [5];
  undefined4 local_110;
  undefined4 local_10c;
  undefined8 local_108;
  longlong *local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined2 local_d8;
  undefined2 local_d6;
  longlong local_d0;
  code *local_c8;
  code *local_c0;
  undefined8 local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  longlong local_88;
  byte local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  int local_54;
  int local_50;
  byte local_4c;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_178;
  local_138[0] = 0;
  local_10c = 0;
  local_f4 = 0;
  local_148 = 0;
  local_140 = 0;
  local_138[1] = 0;
  local_138[2] = 0;
  local_13c = 0;
  local_138[3] = 0;
  local_138[4] = 0;
  uVar5 = CmBattCreateFdo(param_1,param_2,0x710,1,local_138);
  puVar10 = auStackY_178;
  if ((int)uVar5 < 0) goto LAB_140010317;
  lVar1 = *(longlong *)(local_138[0] + 0x40);
  *(undefined1 *)(lVar1 + 0x170) = 1;
  *(undefined4 *)(lVar1 + 0x688) = 0xffffffff;
  *(undefined4 *)(lVar1 + 0x68c) = 100;
  *(undefined4 *)(lVar1 + 400) = 0;
  *(undefined4 *)(lVar1 + 0x668) = 0xffffffff;
  *(undefined8 *)(lVar1 + 0x670) = _DAT_fffff78000000008;
  *(undefined8 *)(lVar1 + 0x6d0) = 0;
  iVar3 = CmBattSetTripPpoint(lVar1,0);
  *(bool *)(lVar1 + 0x650) = iVar3 != -0x3fffffcc;
  RtlInitUnicodeString
            (local_138 + 1,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\ACPI\\Parameters");
  local_100 = local_138 + 1;
  local_110 = 0x30;
  local_108 = 0;
  local_f8 = 0x240;
  local_f0 = 0;
  uStack_e8 = 0;
  iVar3 = ZwOpenKey(&local_148,0x20019,&local_110);
  lVar2 = local_138[0];
  if (iVar3 < 0) {
LAB_140010054:
    CmBattGetExtendedSupport(lVar1);
    uVar5 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      uVar5 = CmBattGetBpcData((undefined1 *)(lVar1 + 0x6fc),(undefined1 *)(lVar1 + 0x6fd),
                               (undefined4 *)(lVar1 + 0x700),(undefined4 *)(lVar1 + 0x704),
                               *(undefined8 *)(lVar1 + 0x20));
      if ((int)uVar5 < 0) {
        *(uint *)(lVar1 + 0x6f8) = *(uint *)(lVar1 + 0x6f8) | 1;
      }
      *(bool *)(lVar1 + 0x652) = (int)uVar5 != -0x3fffffcc;
    }
    memset(&local_d8,0,0x78);
    local_d8 = 1;
    uVar5 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    local_d6 = 2;
    if ((int)uVar5 == 0) {
      local_d6 = 1;
    }
    local_c8 = CmBattQueryTag;
    local_c0 = CmBattQueryInformation;
    local_b0 = CmBattQueryStatus;
    local_a8 = CmBattSetStatusNotify;
    local_a0 = CmBattDisableStatusNotify;
    local_b8 = 0;
    local_90 = *(undefined8 *)(lVar1 + 0xe8);
    local_88 = lVar2;
    local_d0 = lVar1;
    local_98 = param_2;
    uVar5 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar5 != 0) && (*(char *)(lVar1 + 0x652) != '\0')) {
      iVar3 = CmBattSetBptData(&local_13c,*(undefined8 *)(lVar1 + 0x20),0,0);
      if (iVar3 == -0x3fffffcc) {
        *(undefined1 *)(lVar1 + 0x651) = 0;
      }
      else {
        *(undefined1 *)(lVar1 + 0x651) = 1;
        local_78 = CmBattQueryPeakPower;
        local_70 = CmBattSetPeakPowerNotify;
        local_68 = CmBattDisablePeakPowerNotify;
      }
    }
    puVar8 = (undefined8 *)(lVar1 + 0x168);
    uVar4 = BatteryClassInitializeDevice(&local_d8,puVar8);
    uVar5 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) goto LAB_140010208;
    uVar5 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      if ((local_80 & 1) == 0) {
        *(undefined1 *)(lVar1 + 0x6fc) = 0;
        uVar4 = *(uint *)(lVar1 + 0x6f8) & 0xffffffdf;
        *(undefined4 *)(lVar1 + 0x704) = 0;
      }
      else {
        uVar4 = *(uint *)(lVar1 + 0x6f8) | 0x20;
      }
      *(uint *)(lVar1 + 0x6f8) = uVar4;
    }
    if (*(char *)(lVar1 + 0x680) != '\0') {
      uVar4 = IoRegisterDeviceInterface(param_2,&GUID_DEVINTERFACE_THERMAL_COOLING,0,lVar1 + 0x6d8);
      uVar5 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) {
        BatteryClassUnload(*puVar8);
        goto LAB_140010208;
      }
    }
    CmBattWmiRegistration(lVar1);
    uVar5 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    pcVar7 = CmBattNotifyHandlerV1;
    if ((int)uVar5 == 0) {
      pcVar7 = CmBattNotifyHandler;
    }
    uVar4 = (**(code **)(lVar1 + 0x138))(*(undefined8 *)(lVar1 + 0xf8),pcVar7,lVar1);
    uVar5 = (ulonglong)uVar4;
    if (-1 < (int)uVar4) {
      KeAcquireGuardedMutex(&DeviceObjectMutex);
      puVar10 = auStackY_178;
      puVar8 = &BatteryListHead;
      puVar9 = (undefined8 *)(lVar1 + 0x178);
      if ((undefined8 *)*DAT_1400071e8 != &BatteryListHead) {
        pcVar7 = (code *)swi(0x29);
        DAT_1400071e8 = (undefined8 *)(*pcVar7)(3);
        puVar10 = auStackY_170;
      }
      *puVar9 = puVar8;
      *(undefined8 **)(lVar1 + 0x180) = DAT_1400071e8;
      *DAT_1400071e8 = puVar9;
      *(undefined8 *)(puVar10 + -8) = 0x140010310;
      DAT_1400071e8 = puVar9;
      KeReleaseGuardedMutex(&DeviceObjectMutex);
      uVar5 = 0;
      goto LAB_140010317;
    }
    IoWMIRegistrationControl(*(undefined8 *)(lVar1 + 0x10),2);
    BatteryClassUnload(*puVar8);
    IoDetachDevice(*(undefined8 *)(lVar1 + 0x20));
    if (*(char *)(lVar1 + 0x680) != '\0') {
      RtlFreeUnicodeString(lVar1 + 0x6d8);
    }
  }
  else {
    RtlInitUnicodeString(local_138 + 3,L"BatteryFeaturesGranted");
    iVar3 = ZwQueryValueKey(local_148,local_138 + 3,2);
    if ((((iVar3 < 0) || (local_54 != 3)) || (local_50 != 4)) || ((local_4c & 1) == 0)) {
LAB_140010043:
      ZwClose(local_148);
      goto LAB_140010054;
    }
    lVar6 = IoAllocateWorkItem(lVar2);
    *(longlong *)(lVar1 + 0x6f0) = lVar6;
    if (lVar6 != 0) goto LAB_140010043;
    ZwClose(local_148);
    uVar5 = 0xc000009a;
LAB_140010208:
    IoDetachDevice(*(undefined8 *)(lVar1 + 0x20));
  }
  puVar10 = auStackY_178;
  CmBattDestroyFdo(*(longlong *)(lVar1 + 0x10));
LAB_140010317:
  *(undefined8 *)(puVar10 + -8) = 0x140010323;
  return uVar5;
}



===== CmBattAddDevice @ 140010350 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong CmBattAddDevice(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 auStackY_98 [32];
  undefined8 local_60;
  longlong local_58 [4];
  int local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  local_60 = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  if (param_2 == 0) {
    return 0x8000001a;
  }
  uVar3 = IoOpenDeviceRegistryKey(param_2,2,0x20000,&local_60);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  RtlInitUnicodeString(local_58 + 1,L"PowerSourceType");
  uVar2 = ZwQueryValueKey(local_60,local_58 + 1,2);
  ZwClose(local_60);
  if ((int)uVar2 < 0) {
    return (ulonglong)uVar2;
  }
  if (local_34 == 0) {
    uVar3 = CmBattAddBattery(param_1,param_2);
    uVar2 = (uint)uVar3;
  }
  else {
    if (local_34 != 1) {
      return 0xc0000001;
    }
    uVar3 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      local_58[0] = 0;
      uVar3 = CmBattCreateFdo(param_1,param_2,0x4c8,0,local_58);
      if ((int)uVar3 < 0) {
        return uVar3 & 0xffffffff;
      }
      piVar1 = *(int **)(local_58[0] + 0x40);
      CmBattWmiRegistration((longlong)piVar1);
      (**(code **)(piVar1 + 0x4e))(*(undefined8 *)(piVar1 + 0x3e),CmBattNotifyHandler,piVar1);
      KeAcquireGuardedMutex(&DeviceObjectMutex);
      if (AcAdapter == (int *)0x0) {
        AcAdapter = piVar1;
      }
      KeReleaseGuardedMutex(&DeviceObjectMutex);
      CmBattNotifyHandler(piVar1,0x80);
      return 0;
    }
    uVar2 = CmBattAddAcAdapterV1(param_1,param_2);
  }
  return (ulonglong)uVar2;
}



===== CmBattCreateFdo @ 140010520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CmBattCreateFdo(undefined8 param_1,undefined8 param_2,uint param_3,undefined4 param_4,
                         undefined8 *param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined1 auStackY_e8 [32];
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined1 local_60 [12];
  int local_54;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98 = 0;
  local_88 = 0;
  uStack_80 = 0;
  uVar5 = IoCreateDevice(0,param_3,0,0x29);
  puVar1 = puRam0000000000000040;
  if (-1 < (int)uVar5) {
    uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f | 0x2004;
    memset(puRam0000000000000040,0,(ulonglong)param_3);
    *puVar1 = param_4;
    *(undefined8 *)(puVar1 + 2) = 0;
    *(undefined8 *)(puVar1 + 4) = 0;
    *(undefined8 *)(puVar1 + 6) = param_2;
    lVar6 = IoAllocateWorkItem(0);
    *(longlong *)(puVar1 + 0x58) = lVar6;
    if (lVar6 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      lVar6 = IoAttachDeviceToDeviceStack(0,param_2);
      *(longlong *)(puVar1 + 8) = lVar6;
      if (lVar6 == 0) {
        uVar2 = 0xc0000001;
      }
      else {
        puVar7 = puVar1 + 0x3c;
        uVar2 = CmBattGetAcpiInterfaces(lVar6,puVar7);
        if (-1 < (int)uVar2) {
          local_68 = 0;
          local_8c = 0x4449555f;
          local_90 = 0x42696541;
          local_78 = 0;
          uStack_70 = 0;
          uVar8 = 0;
          uVar5 = CmBattSendDownStreamIrp
                            (*(undefined8 *)(puVar1 + 8),puVar7,&local_90,8,(longlong)&local_78,0x14
                            );
          uVar2 = (uint)uVar5;
          if (-1 < (int)uVar2) {
            uVar8 = 0;
            if (uStack_70._4_2_ == 0) {
              uVar8 = local_68;
            }
            uVar2 = -(uint)(uStack_70._4_2_ != 0) & 0xc014000f;
          }
          *(undefined8 *)(puVar1 + 0xc) = 0;
          puVar1[10] = 1;
          puVar1[0xe] = 0;
          KeInitializeEvent(puVar1 + 0x10,1,0);
          *(undefined1 *)(puVar1 + 0x18) = 1;
          IoInitializeRemoveLockEx(puVar1 + 0x30,0x4d746142,0,0);
          puVar1[0x56] = 1;
          puVar1[0x57] = 1;
          *(undefined8 *)(puVar1 + 0x3a) = 0;
          uVar3 = 0;
          if (-1 < (int)uVar2) {
            uVar3 = uVar8;
          }
          *(undefined1 *)(puVar1 + 0x52) = 0;
          puVar1[0x38] = uVar3;
          *(undefined8 *)(puVar1 + 0x54) = 0;
          *(undefined1 *)(puVar1 + 0x2e) = 1;
          iVar4 = IoOpenDeviceRegistryKey(param_2,1,0x1f0000,&local_98);
          if (-1 < iVar4) {
            RtlInitUnicodeString(&local_88,L"WaitWakeEnabled");
            iVar4 = ZwQueryValueKey(local_98,&local_88,2,local_60);
            if (-1 < iVar4) {
              *(bool *)(puVar1 + 0x2e) = local_54 != 0;
            }
            ZwClose(local_98);
          }
          *param_5 = 0;
          return 0;
        }
        IoDetachDevice();
      }
    }
    CmBattDestroyFdo(*(longlong *)(puVar1 + 4));
    uVar5 = (ulonglong)uVar2;
  }
  return uVar5;
}



===== CmBattDestroyFdo @ 140010800 =====

void CmBattDestroyFdo(longlong param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x40);
  if (*(longlong *)(piVar1 + 0x58) != 0) {
    IoFreeWorkItem();
  }
  if ((*piVar1 == 1) && (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x6f0) != 0)) {
    IoFreeWorkItem();
  }
  IoDeleteDevice(param_1);
  return;
}



===== CmBattDevicePowerIrpCompletionWorker @ 140010870 =====

void CmBattDevicePowerIrpCompletionWorker(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  piVar3 = *(int **)(param_1 + 0x40);
  PoSetPowerState(param_1,1,*(undefined4 *)(lVar2 + 0x18));
  iVar1 = *(int *)(lVar2 + 0x18);
  *(undefined1 *)(piVar3 + 0x52) = 0;
  piVar3[0x57] = iVar1;
  LOCK();
  UNLOCK();
  if (*piVar3 == 1) {
    LOCK();
    piVar3[0x5d] = 0;
    UNLOCK();
    piVar3[0x19a] = -1;
    piVar3[0x1a2] = -1;
    *(undefined1 *)(piVar3 + 0x5c) = 1;
    BatteryClassStatusNotify(*(undefined8 *)(piVar3 + 0x5a));
    if ((char)piVar3[0x1b2] != '\0') {
      CmBattStartWatchdog((longlong)piVar3);
    }
  }
  else if (*piVar3 == 0) {
    uVar4 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      AdapterClassStatusNotify(*(undefined8 *)(piVar3 + 0x5a));
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  IoReleaseRemoveLockEx(piVar3 + 0x30,param_2,0x20);
  return;
}



===== CmBattPnpDispatch @ 140010970 =====

ulonglong CmBattPnpDispatch(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  undefined8 *puVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  piVar4 = *(int **)(param_1 + 0x40);
  lVar8 = *(longlong *)(param_2 + 0xb8);
  local_38 = 0;
  uStack_30 = 0;
  piVar1 = piVar4 + 0x30;
  local_28 = 0;
  uVar7 = IoAcquireRemoveLockEx(piVar1,param_2,"",1,0x20);
  if ((int)uVar7 < 0) {
    *(uint *)(param_2 + 0x30) = uVar7;
    IofCompleteRequest(param_2,0);
    return (ulonglong)uVar7;
  }
  bVar2 = *(byte *)(lVar8 + 1);
  if (bVar2 < 6) {
    if (bVar2 != 5) {
      if (bVar2 == 0) {
        if ((*piVar4 == 1) && ((char)piVar4[0x1a0] != '\0')) {
          IoSetDeviceInterfaceState(piVar4 + 0x1b6,1);
          *(undefined1 *)((longlong)piVar4 + 0x681) = 1;
        }
      }
      else {
        if (bVar2 == 1) {
          ExAcquireFastMutex(piVar4 + 10);
          if ((char)piVar4[0x18] != '\0') {
LAB_140010b56:
            *(undefined1 *)(piVar4 + 0x18) = 0;
          }
        }
        else {
          if (bVar2 == 2) {
            if ((*piVar4 == 1) && (*(char *)((longlong)piVar4 + 0x681) != '\0')) {
              IoSetDeviceInterfaceState(piVar4 + 0x1b6,0);
              *(undefined1 *)((longlong)piVar4 + 0x681) = 0;
            }
            IoReleaseRemoveLockAndWaitEx(piVar1,param_2,0x20);
            CmBattRemoveDevice(param_1);
            *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
            *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
            uVar7 = IofCallDriver(*(undefined8 *)(piVar4 + 8),param_2);
            IoDetachDevice(*(undefined8 *)(piVar4 + 8));
            CmBattDestroyFdo(*(longlong *)(piVar4 + 2));
            return (ulonglong)uVar7;
          }
          if (bVar2 != 3) {
            if (bVar2 != 4) goto LAB_140010a2b;
            goto LAB_140010a27;
          }
          ExAcquireFastMutex(piVar4 + 10);
          if ((char)piVar4[0x18] == '\0') {
            *(undefined1 *)(piVar4 + 0x18) = 1;
          }
        }
        ExReleaseFastMutex(piVar4 + 10);
      }
    }
LAB_140010a27:
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  else {
    if (bVar2 == 6) goto LAB_140010a27;
    if (bVar2 != 8) {
      if (bVar2 == 9) {
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
        KeInitializeEvent(&local_38,1);
        lVar6 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar6 + -0x10) = CmBattIoCompletion;
        *(undefined8 **)(lVar6 + -8) = &local_38;
        *(undefined1 *)(lVar6 + -0x45) = 0xe0;
        uVar7 = IofCallDriver(*(undefined8 *)(piVar4 + 8),param_2);
        if (uVar7 == 0x103) {
          KeWaitForSingleObject(&local_38,0,0,0,0);
          uVar7 = *(uint *)(param_2 + 0x30);
        }
        uVar10 = (ulonglong)uVar7;
        lVar8 = *(longlong *)(lVar8 + 8);
        iVar3 = *(int *)(lVar8 + 0x2c);
        piVar4[0x1c] = iVar3;
        if (iVar3 == 0) {
          *(undefined1 *)(piVar4 + 0x2e) = 0;
        }
        else if ((*(longlong *)(piVar4 + 0x1a) == 0) && ((char)piVar4[0x2e] != '\0')) {
          PoRequestPowerIrp(*(undefined8 *)(piVar4 + 2),0,iVar3,CmBattWaitWakeLoop,0,piVar4 + 0x1a);
        }
        if ((*(uint *)(lVar8 + 4) & 0x10) != 0) {
          *(uint *)(lVar8 + 4) = *(uint *)(lVar8 + 4) | 0x200;
        }
      }
      else {
        if (bVar2 != 0x14) {
          if (bVar2 == 0x17) {
            if ((*piVar4 == 1) && (*(char *)((longlong)piVar4 + 0x681) != '\0')) {
              IoSetDeviceInterfaceState(piVar4 + 0x1b6,0);
              *(undefined1 *)((longlong)piVar4 + 0x681) = 0;
            }
            ExAcquireFastMutex(piVar4 + 10);
            goto LAB_140010b56;
          }
          goto LAB_140010a2b;
        }
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
        KeInitializeEvent(&local_38,1);
        lVar8 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar8 + -0x10) = CmBattIoCompletion;
        *(undefined8 **)(lVar8 + -8) = &local_38;
        *(undefined1 *)(lVar8 + -0x45) = 0xe0;
        uVar7 = IofCallDriver(*(undefined8 *)(piVar4 + 8),param_2);
        if (uVar7 == 0x103) {
          KeWaitForSingleObject(&local_38,0,0,0,0);
          uVar7 = *(uint *)(param_2 + 0x30);
        }
        uVar10 = (ulonglong)uVar7;
        *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) & 0xffffffffffffffdf;
      }
LAB_140010ca3:
      IofCompleteRequest(param_2,0);
      goto LAB_140010a4b;
    }
    if ((*(undefined **)(lVar8 + 8) == &GUID_THERMAL_COOLING_INTERFACE) ||
       (lVar8 = RtlCompareMemory(*(undefined **)(lVar8 + 8),&GUID_THERMAL_COOLING_INTERFACE,0x10),
       lVar8 == 0x10)) {
      uVar9 = CmBattEjectCoolingInterface(piVar4,param_2);
      uVar10 = uVar9 & 0xffffffff;
      *(int *)(param_2 + 0x30) = (int)uVar9;
      goto LAB_140010ca3;
    }
  }
LAB_140010a2b:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar7 = IofCallDriver(*(undefined8 *)(piVar4 + 8),param_2);
  uVar10 = (ulonglong)uVar7;
LAB_140010a4b:
  IoReleaseRemoveLockEx(piVar1,param_2,0x20);
  return uVar10;
}



===== CmBattQueryWmiDataBlock @ 140010e10 =====

void CmBattQueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,int param_7,undefined1 *param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *in_stack_ffffffffffffffb8;
  
  piVar1 = *(int **)(param_1 + 0x40);
  uVar4 = 0;
  uVar3 = 0xc0000295;
  if ((*piVar1 != 1) ||
     (in_stack_ffffffffffffffb8 = param_6,
     iVar2 = BatteryClassQueryWmiDataBlock
                       (*(undefined8 *)(piVar1 + 0x5a),param_1,param_2,param_3,param_6,param_7,
                        param_8), iVar2 == -0x3ffffd6b)) {
    if ((param_3 == 0) && (piVar1[0x1c] != 0)) {
      uVar4 = 1;
      if (param_7 == 0) {
        uVar3 = 0xc0000023;
      }
      else {
        uVar3 = 0;
        *param_8 = (char)piVar1[0x2e];
        *param_6 = 1;
      }
    }
    WmiCompleteRequest(param_1,param_2,uVar3,uVar4,
                       (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
  }
  return;
}



===== CmBattQueryWmiRegInfo @ 140010f00 =====

undefined8
CmBattQueryWmiRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0x20;
  *param_4 = &GlobalRegistryPath;
  *param_6 = *(undefined8 *)(lVar1 + 0x18);
  return 0;
}



===== CmBattSetWmiDataBlock @ 140010f30 =====

void CmBattSetWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
               undefined8 param_5,char *param_6)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_res8;
  uint local_res18 [2];
  uint *in_stack_ffffffffffffffd8;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar4;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  local_res8 = 0;
  local_res18[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_18 = 0;
  uStack_10 = 0;
  if (param_3 == 0) {
    if (*(char *)(lVar1 + 0xb8) != *param_6) {
      *(char *)(lVar1 + 0xb8) = *param_6;
      iVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar1 + 0x18),1,0x1f0000,&local_res8);
      if (-1 < iVar2) {
        RtlInitUnicodeString(&local_18,L"WaitWakeEnabled");
        local_res18[0] = (uint)*(byte *)(lVar1 + 0xb8);
        in_stack_ffffffffffffffd8 = local_res18;
        ZwSetValueKey(local_res8,&local_18,0,4,in_stack_ffffffffffffffd8,CONCAT44(uVar4,4));
        ZwClose(local_res8);
      }
      if (*(char *)(lVar1 + 0xb8) == '\0') {
        if (*(longlong *)(lVar1 + 0x68) != 0) {
          IoCancelIrp();
        }
      }
      else if (*(int *)(lVar1 + 0x70) == 0) {
        *(undefined1 *)(lVar1 + 0xb8) = 0;
      }
      else if (*(longlong *)(lVar1 + 0x68) == 0) {
        in_stack_ffffffffffffffd8 = (uint *)0x0;
        PoRequestPowerIrp(*(undefined8 *)(lVar1 + 8),0,*(undefined4 *)(lVar1 + 0x70),
                          CmBattWaitWakeLoop,0,(longlong *)(lVar1 + 0x68));
      }
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar3,0,
                     (ulonglong)in_stack_ffffffffffffffd8 & 0xffffffffffffff00);
  return;
}



===== CmBattSetWmiDataItem @ 1400110a0 =====

void CmBattSetWmiDataItem
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,int param_5,
               undefined8 param_6,char *param_7)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_res8;
  uint local_res18 [2];
  uint *in_stack_ffffffffffffffd8;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar4;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  local_res8 = 0;
  local_res18[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_18 = 0;
  uStack_10 = 0;
  if (param_3 == 0) {
    if (param_5 == 0) {
      if (*(char *)(lVar1 + 0xb8) != *param_7) {
        *(char *)(lVar1 + 0xb8) = *param_7;
        iVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar1 + 0x18),1,0x1f0000,&local_res8);
        if (-1 < iVar2) {
          RtlInitUnicodeString(&local_18,L"WaitWakeEnabled");
          local_res18[0] = (uint)*(byte *)(lVar1 + 0xb8);
          in_stack_ffffffffffffffd8 = local_res18;
          ZwSetValueKey(local_res8,&local_18,0,4,in_stack_ffffffffffffffd8,CONCAT44(uVar4,4));
          ZwClose(local_res8);
        }
        if (*(char *)(lVar1 + 0xb8) == '\0') {
          if (*(longlong *)(lVar1 + 0x68) != 0) {
            IoCancelIrp();
          }
        }
        else if (*(int *)(lVar1 + 0x70) == 0) {
          *(undefined1 *)(lVar1 + 0xb8) = 0;
        }
        else if (*(longlong *)(lVar1 + 0x68) == 0) {
          in_stack_ffffffffffffffd8 = (uint *)0x0;
          PoRequestPowerIrp(*(undefined8 *)(lVar1 + 8),0,*(undefined4 *)(lVar1 + 0x70),
                            CmBattWaitWakeLoop,0,(longlong *)(lVar1 + 0x68));
        }
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 0xc00002c6;
    }
  }
  else {
    uVar3 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar3,0,
                     (ulonglong)in_stack_ffffffffffffffd8 & 0xffffffffffffff00);
  return;
}



===== CmBattSystemControl @ 140011230 =====

int CmBattSystemControl(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  int local_res8 [2];
  
  piVar1 = *(int **)(param_1 + 0x40);
  local_res8[0] = 3;
  iVar2 = IoAcquireRemoveLockEx(piVar1 + 0x30,param_2,"",1,0x20);
  if (iVar2 < 0) {
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
  }
  else {
    if (*piVar1 == 1) {
      iVar2 = BatteryClassSystemControl
                        (*(undefined8 *)(piVar1 + 0x5a),piVar1 + 0x1e,param_1,param_2,local_res8);
    }
    else {
      iVar2 = WmiSystemControl(piVar1 + 0x1e,param_1,param_2,local_res8);
    }
    if (local_res8[0] != 0) {
      if (local_res8[0] == 1) {
        IofCompleteRequest(param_2,0);
      }
      else {
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        iVar2 = IofCallDriver(*(undefined8 *)(piVar1 + 8),param_2);
      }
    }
    IoReleaseRemoveLockEx(piVar1 + 0x30,param_2,0x20);
  }
  return iVar2;
}



===== CmBattWmiDeRegistration @ 140011360 =====

void CmBattWmiDeRegistration(longlong param_1)

{
  IoWMIRegistrationControl(*(undefined8 *)(param_1 + 0x10),2);
  return;
}



===== CmBattWmiRegistration @ 140011388 =====

void CmBattWmiRegistration(longlong param_1)

{
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined8 *)(param_1 + 0xb0) = 0;
  *(undefined ***)(param_1 + 0x80) = &CmBattWmiGuidList;
  *(code **)(param_1 + 0x88) = CmBattQueryWmiRegInfo;
  *(code **)(param_1 + 0x90) = CmBattQueryWmiDataBlock;
  *(code **)(param_1 + 0x98) = CmBattSetWmiDataBlock;
  *(code **)(param_1 + 0xa0) = CmBattSetWmiDataItem;
  *(undefined4 *)(param_1 + 0x78) = 1;
  IoWMIRegistrationControl(*(undefined8 *)(param_1 + 0x10));
  return;
}



===== CmBattTraceAdapterWattageRequirements @ 140011408 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceAdapterWattageRequirements
               (undefined4 param_1,undefined8 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  char cVar4;
  undefined *puVar5;
  ulonglong uVar6;
  int iVar7;
  longlong lVar8;
  undefined *puVar9;
  uint uVar10;
  undefined4 local_res8 [2];
  undefined4 local_res18 [4];
  undefined1 auStack_f8 [32];
  undefined4 **local_d8;
  undefined4 *local_c8;
  undefined8 local_c0;
  ulonglong local_28;
  
  lVar8 = AcAdapter;
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  if (*(int *)(AcAdapter + 0x484) == 1) {
    iVar1 = 6;
    puVar5 = &BATTERY_EVT_REC_WATTAGE_SINGLE_ADAPTER_RUNDOWN;
    puVar9 = &BATTERY_EVT_REC_WATTAGE_SINGLE_ADAPTER;
  }
  else {
    if (*(int *)(AcAdapter + 0x484) != 2) {
      return;
    }
    iVar1 = 10;
    puVar5 = &BATTERY_EVT_REC_WATTAGE_DUAL_ADAPTER_RUNDOWN;
    puVar9 = &BATTERY_EVT_REC_WATTAGE_DUAL_ADAPTER;
  }
  if (param_4 != '\0') {
    puVar9 = puVar5;
  }
  if ((CmBattEtwRegistered != '\0') &&
     (local_res8[0] = param_1, local_res18[0] = param_3,
     cVar4 = EtwEventEnabled(CmBattEtwHandle,puVar9), cVar4 != '\0')) {
    local_c0._4_4_ = 0;
    local_c8 = local_res8;
    uVar3 = *(uint *)(lVar8 + 0x484);
    uVar10 = 0;
    local_c0._0_4_ = 4;
    if (uVar3 != 0) {
      lVar8 = lVar8 + 0x4ac;
      do {
        iVar7 = uVar10 * 4;
        uVar10 = uVar10 + 1;
        uVar6 = (ulonglong)(iVar7 + 1);
        *(undefined4 *)((longlong)&local_c0 + (uVar6 * 4 + 1) * 4) = 0;
        (&local_c0)[uVar6 * 2 + -1] = lVar8 + -4;
        *(undefined4 *)(&local_c0 + uVar6 * 2) = 4;
        uVar6 = (ulonglong)(iVar7 + 2);
        *(undefined4 *)((longlong)&local_c0 + (uVar6 * 4 + 1) * 4) = 0;
        (&local_c0)[uVar6 * 2 + -1] = lVar8;
        *(undefined4 *)(&local_c0 + uVar6 * 2) = 4;
        uVar6 = (ulonglong)(iVar7 + 3);
        *(undefined4 *)((longlong)&local_c0 + (uVar6 * 4 + 1) * 4) = 0;
        (&local_c0)[uVar6 * 2 + -1] = lVar8 + 4;
        lVar2 = lVar8 + 8;
        *(undefined4 *)(&local_c0 + uVar6 * 2) = 4;
        lVar8 = lVar8 + 0x10;
        uVar6 = (ulonglong)(iVar7 + 4);
        *(undefined4 *)((longlong)&local_c0 + (uVar6 * 4 + 1) * 4) = 0;
        (&local_c0)[uVar6 * 2 + -1] = lVar2;
        *(undefined4 *)(&local_c0 + uVar6 * 2) = 4;
      } while (uVar10 < uVar3);
    }
    uVar6 = (ulonglong)(iVar1 - 1);
    *(undefined4 *)((longlong)&local_c0 + (uVar6 * 4 + 1) * 4) = 0;
    (&local_c0)[uVar6 * 2 + -1] = local_res18;
    local_d8 = &local_c8;
    *(undefined4 *)(&local_c0 + uVar6 * 2) = 4;
    EtwWrite(CmBattEtwHandle,puVar9,0,iVar1);
  }
  return;
}



===== CmBattTraceBif @ 1400115ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceBif(longlong param_1,char param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined1 auStack_128 [32];
  longlong *local_108;
  longlong local_f8 [3];
  undefined8 local_e0;
  longlong local_d8;
  undefined8 local_d0;
  longlong local_c8;
  undefined8 local_c0;
  longlong local_b8;
  undefined8 local_b0;
  longlong local_a8;
  undefined8 local_a0;
  longlong local_98;
  undefined8 local_90;
  longlong local_88;
  undefined8 local_80;
  longlong local_78;
  undefined8 local_70;
  longlong local_68;
  undefined8 local_60;
  longlong local_58;
  int local_50;
  undefined4 local_4c;
  longlong local_48;
  int local_40;
  undefined4 local_3c;
  longlong local_38;
  int local_30;
  undefined4 local_2c;
  longlong local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_128;
  puVar4 = &BATTERY_EVT_BIF_UPDATED;
  if (param_2 != '\0') {
    puVar4 = &BATTERY_EVT_BIF_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    cVar1 = EtwEventEnabled(CmBattEtwHandle,puVar4);
    if (cVar1 != '\0') {
      local_f8[0] = param_1 + 0x168;
      local_f8[1] = 8;
      local_58 = param_1 + 0x214;
      local_f8[2] = param_1 + 0x1d8;
      local_e0 = 4;
      local_d8 = param_1 + 0x1dc;
      local_c8 = param_1 + 0x1e0;
      local_b8 = param_1 + 0x1e4;
      local_a8 = param_1 + 0x1e8;
      local_98 = param_1 + 0x1ec;
      local_88 = param_1 + 0x1f0;
      local_78 = param_1 + 0x20c;
      local_68 = param_1 + 0x210;
      lVar2 = -1;
      lVar3 = -1;
      local_d0 = 4;
      local_c0 = 4;
      local_b0 = 4;
      local_a0 = 4;
      local_90 = 4;
      local_80 = 4;
      local_70 = 4;
      local_60 = 4;
      do {
        lVar3 = lVar3 + 1;
      } while (*(char *)(local_58 + lVar3) != '\0');
      local_50 = (int)lVar3 + 1;
      local_4c = 0;
      local_48 = param_1 + 0x314;
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (*(char *)(local_48 + lVar3) != '\0');
      local_40 = (int)lVar3 + 1;
      local_3c = 0;
      local_38 = param_1 + 0x414;
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (*(char *)(local_38 + lVar3) != '\0');
      local_30 = (int)lVar3 + 1;
      local_2c = 0;
      local_28 = param_1 + 0x514;
      do {
        lVar2 = lVar2 + 1;
      } while (*(char *)(local_28 + lVar2) != '\0');
      local_20 = (int)lVar2 + 1;
      local_108 = local_f8;
      local_1c = 0;
      EtwWrite(CmBattEtwHandle,puVar4,0,0xe);
    }
  }
  return;
}



===== CmBattTraceBix @ 1400117b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceBix(longlong param_1,char param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined1 auStack_198 [32];
  longlong *local_178;
  longlong local_168 [3];
  undefined8 local_150;
  longlong local_148;
  undefined8 local_140;
  longlong local_138;
  undefined8 local_130;
  longlong local_128;
  undefined8 local_120;
  longlong local_118;
  undefined8 local_110;
  longlong local_108;
  undefined8 local_100;
  longlong local_f8;
  undefined8 local_f0;
  longlong local_e8;
  undefined8 local_e0;
  longlong local_d8;
  undefined8 local_d0;
  longlong local_c8;
  undefined8 local_c0;
  longlong local_b8;
  undefined8 local_b0;
  longlong local_a8;
  undefined8 local_a0;
  longlong local_98;
  undefined8 local_90;
  longlong local_88;
  undefined8 local_80;
  longlong local_78;
  undefined8 local_70;
  longlong local_68;
  undefined8 local_60;
  longlong local_58;
  int local_50;
  undefined4 local_4c;
  longlong local_48;
  int local_40;
  undefined4 local_3c;
  longlong local_38;
  int local_30;
  undefined4 local_2c;
  longlong local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_198;
  puVar4 = &BATTERY_EVT_BIX_UPDATED;
  if (param_2 != '\0') {
    puVar4 = &BATTERY_EVT_BIX_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    cVar1 = EtwEventEnabled(CmBattEtwHandle,puVar4);
    if (cVar1 != '\0') {
      local_168[0] = param_1 + 0x168;
      local_168[1] = 8;
      local_58 = param_1 + 0x214;
      local_168[2] = param_1 + 0x1d4;
      local_150 = 4;
      local_148 = param_1 + 0x1d8;
      local_138 = param_1 + 0x1dc;
      local_128 = param_1 + 0x1e0;
      local_118 = param_1 + 0x1e4;
      local_108 = param_1 + 0x1e8;
      local_f8 = param_1 + 0x1ec;
      local_e8 = param_1 + 0x1f0;
      local_d8 = param_1 + 0x20c;
      local_c8 = param_1 + 0x210;
      local_b8 = param_1 + 500;
      local_a8 = param_1 + 0x1f8;
      local_98 = param_1 + 0x1fc;
      local_88 = param_1 + 0x200;
      local_78 = param_1 + 0x204;
      local_68 = param_1 + 0x208;
      lVar2 = -1;
      lVar3 = -1;
      local_140 = 4;
      local_130 = 4;
      local_120 = 4;
      local_110 = 4;
      local_100 = 4;
      local_f0 = 4;
      local_e0 = 4;
      local_d0 = 4;
      local_c0 = 4;
      local_b0 = 4;
      local_a0 = 4;
      local_90 = 4;
      local_80 = 4;
      local_70 = 4;
      local_60 = 4;
      do {
        lVar3 = lVar3 + 1;
      } while (*(char *)(local_58 + lVar3) != '\0');
      local_50 = (int)lVar3 + 1;
      local_4c = 0;
      local_48 = param_1 + 0x314;
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (*(char *)(local_48 + lVar3) != '\0');
      local_40 = (int)lVar3 + 1;
      local_3c = 0;
      local_38 = param_1 + 0x414;
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (*(char *)(local_38 + lVar3) != '\0');
      local_30 = (int)lVar3 + 1;
      local_2c = 0;
      local_28 = param_1 + 0x514;
      do {
        lVar2 = lVar2 + 1;
      } while (*(char *)(local_28 + lVar2) != '\0');
      local_20 = (int)lVar2 + 1;
      local_178 = local_168;
      local_1c = 0;
      EtwWrite(CmBattEtwHandle,puVar4,0,0x15);
    }
  }
  return;
}



===== CmBattTraceBps @ 140011a4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceBps(undefined4 param_1,longlong param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  undefined *puVar2;
  undefined4 local_res8 [2];
  undefined4 local_res18 [2];
  undefined1 auStack_a8 [32];
  undefined4 **local_88;
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  puVar2 = &BATTERY_EVT_BPS_GET;
  if (param_4 != '\0') {
    puVar2 = &BATTERY_EVT_BPS_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    local_res8[0] = param_1;
    local_res18[0] = param_3;
    cVar1 = EtwEventEnabled(CmBattEtwHandle,puVar2);
    if (cVar1 != '\0') {
      local_6c = 0;
      local_78 = local_res8;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_68 = param_2 + 4;
      local_58 = param_2 + 8;
      local_48 = param_2 + 0xc;
      local_38 = param_2 + 0x10;
      local_28 = local_res18;
      local_88 = &local_78;
      local_70 = 4;
      local_60 = 4;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_20 = 4;
      EtwWrite(CmBattEtwHandle,puVar2,0,6);
    }
  }
  return;
}



===== CmBattTraceBpt @ 140011b68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceBpt(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined1 param_5,char param_6)

{
  char cVar1;
  undefined *puVar2;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStack_a8 [32];
  undefined4 **local_88;
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
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  puVar2 = &BATTERY_EVT_BPT_SET;
  if (param_6 != '\0') {
    puVar2 = &BATTERY_EVT_BPT_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    local_res8[0] = param_1;
    local_res10[0] = param_2;
    local_res18[0] = param_3;
    local_res20[0] = param_4;
    cVar1 = EtwEventEnabled(CmBattEtwHandle,puVar2);
    if (cVar1 != '\0') {
      local_6c = 0;
      local_78 = local_res8;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_68 = local_res10;
      local_70 = 4;
      local_58 = local_res18;
      local_48 = local_res20;
      local_38 = &param_5;
      local_88 = &local_78;
      local_60 = 4;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      EtwWrite(CmBattEtwHandle,puVar2,0,5);
    }
  }
  return;
}



===== CmBattTraceBst @ 140011c64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceBst(longlong param_1,char param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined1 auStack_98 [32];
  longlong *local_78;
  longlong local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = &BATTERY_EVT_BST_UPDATED;
  if (param_2 != '\0') {
    puVar2 = &BATTERY_EVT_BST_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    cVar1 = EtwEventEnabled(CmBattEtwHandle,puVar2);
    if (cVar1 != '\0') {
      local_5c = 0;
      local_58 = param_1 + 0x1c0;
      local_4c = 0;
      local_68 = param_1 + 0x168;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_48 = param_1 + 0x1c4;
      local_38 = param_1 + 0x1c8;
      local_28 = param_1 + 0x1cc;
      local_78 = &local_68;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_20 = 4;
      local_60 = 8;
      EtwWrite(CmBattEtwHandle,puVar2,0,5);
    }
  }
  return;
}



===== CmBattTraceBtp @ 140011d74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceBtp(longlong param_1,char param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined1 auStack_68 [32];
  longlong *local_48;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  puVar2 = &BATTERY_EVT_BTP_SET;
  if (param_2 != '\0') {
    puVar2 = &BATTERY_EVT_BTP_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    cVar1 = EtwEventEnabled(CmBattEtwHandle,puVar2);
    if (cVar1 != '\0') {
      local_2c = 0;
      local_38 = param_1 + 0x168;
      local_1c = 0;
      local_28 = param_1 + 0x668;
      local_30 = 8;
      local_48 = &local_38;
      local_20 = 4;
      EtwWrite(CmBattEtwHandle,puVar2,0,2);
    }
  }
  return;
}



===== CmBattTraceChargingWatchdog @ 140011e44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceChargingWatchdog(longlong param_1,char param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined1 auStack_88 [32];
  longlong *local_68;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = &BATTERY_EVT_CHARGING_WATCHOG_UPDATED;
  if (param_2 != '\0') {
    puVar2 = &BATTERY_EVT_CHARGING_WATCHOG_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    cVar1 = EtwEventEnabled(CmBattEtwHandle,puVar2);
    if (cVar1 != '\0') {
      local_4c = 0;
      local_58 = param_1 + 0x168;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_48 = param_1 + 0x1c0;
      local_38 = param_1 + 0x6cc;
      local_28 = param_1 + 0x6c0;
      local_68 = &local_58;
      local_50 = 8;
      local_40 = 4;
      local_30 = 4;
      local_20 = 4;
      EtwWrite(CmBattEtwHandle,puVar2,0);
    }
  }
  return;
}



===== CmBattTraceControlCallback @ 140011f50 =====

void CmBattTraceControlCallback(undefined8 param_1,int param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  
  if (param_2 == 2) {
    KeAcquireGuardedMutex();
    for (puVar3 = BatteryListHead; (undefined8 **)puVar3 != &BatteryListHead;
        puVar3 = (undefined8 *)*puVar3) {
      puVar1 = puVar3 + -0x2f;
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(puVar3 + 0xab,0);
      if (*(int *)(puVar3 + 3) != 0) {
        if (*(int *)(puVar3 + 0xb) == 0x5849425f) {
          CmBattTraceBix((longlong)puVar1,'\x01');
        }
        else {
          CmBattTraceBif((longlong)puVar1,'\x01');
        }
        CmBattTraceBst((longlong)puVar1,'\x01');
        CmBattTraceChargingWatchdog((longlong)puVar1,'\x01');
        if (*(char *)(puVar3 + 0x9b) != '\0') {
          CmBattTraceBtp((longlong)puVar1,'\x01');
        }
        uVar2 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar2 != 0) {
          CmBattTraceBps(-(uint)((*(uint *)(puVar3 + 0xb0) & 2) != 0) & 0xc0000001,
                         (longlong)puVar3 + 0x4dc,0,'\x01');
          if (*(char *)((longlong)puVar3 + 0x4d9) != '\0') {
            if (*(char *)((longlong)puVar3 + 0x584) != '\0') {
              CmBattTraceBpt(1,*(undefined4 *)(puVar3 + 0xb2),
                             -(uint)((*(uint *)(puVar3 + 0xb0) & 4) != 0) & 0xc0000001,0,0,'\x01');
            }
            if (*(char *)((longlong)puVar3 + 0x585) != '\0') {
              CmBattTraceBpt(2,*(undefined4 *)((longlong)puVar3 + 0x594),
                             -(uint)((*(uint *)(puVar3 + 0xb0) & 8) != 0) & 0xc0000001,0,0,'\x01');
            }
          }
        }
      }
      ExReleasePushLockExclusiveEx();
      KeLeaveCriticalRegion();
    }
    uVar2 = Feature_EE_MPTF_Functionality__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar2 != 0) && (AcAdapter != 0)) {
      CmBattTracePsr(-(uint)((*(uint *)(AcAdapter + 0x174) & 1) != 0) & 0xc0000001,
                     *(undefined4 *)(AcAdapter + 0x178),'\x01');
      uVar2 = (ulonglong)*(uint *)(AcAdapter + 0x17c);
      CmBattTracePif(-(uint)((*(uint *)(AcAdapter + 0x174) & 2) != 0) & 0xc0000001,
                     *(uint *)(AcAdapter + 0x17c),*(undefined4 *)(AcAdapter + 0x180),0,'\x01');
      if ((*(uint *)(AcAdapter + 0x170) & 2) != 0) {
        CmBattTraceRecCapabilities(0,uVar2,0,'\x01');
        CmBattTraceRecSupported(0,uVar2,0,'\x01');
        CmBattTraceRecStatus(0,uVar2,0,'\x01');
        CmBattTraceRecOverride(0,uVar2,0,0,'\x01');
        CmBattTraceAdapterWattageRequirements(0,uVar2,0,'\x01');
      }
    }
    KeReleaseGuardedMutex(&DeviceObjectMutex);
  }
  return;
}



===== CmBattTraceNotify @ 1400121dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceNotify(longlong param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 local_res10 [6];
  undefined1 auStack_68 [32];
  longlong *local_48;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  if (CmBattEtwRegistered != '\0') {
    local_res10[0] = param_2;
    cVar1 = EtwEventEnabled(CmBattEtwHandle,&BATTERY_EVT_ACPI_NOTIFY);
    if (cVar1 != '\0') {
      local_2c = 0;
      local_38 = param_1 + 0x168;
      local_1c = 0;
      local_28 = local_res10;
      local_30 = 8;
      local_48 = &local_38;
      local_20 = 4;
      EtwWrite(CmBattEtwHandle,&BATTERY_EVT_ACPI_NOTIFY,0,2);
    }
  }
  return;
}



===== CmBattTracePif @ 140012298 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmBattTracePif(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              char param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStack_c8 [32];
  undefined4 **local_a8;
  undefined4 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  int local_50;
  undefined4 local_4c;
  longlong local_48;
  int local_40;
  undefined4 local_3c;
  longlong local_38;
  int local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  puVar4 = &BATTERY_EVT_PIF_GET;
  if (param_5 != '\0') {
    puVar4 = &BATTERY_EVT_PIF_RUNDOWN;
  }
  uVar1 = CONCAT71(0x1400053,-param_5);
  if (CmBattEtwRegistered != '\0') {
    local_res8[0] = param_1;
    local_res10[0] = param_2;
    local_res18[0] = param_3;
    local_res20[0] = param_4;
    uVar1 = EtwEventEnabled(CmBattEtwHandle,puVar4);
    if ((char)uVar1 != '\0') {
      local_8c = 0;
      local_98 = local_res8;
      local_7c = 0;
      local_6c = 0;
      local_5c = 0;
      local_88 = local_res10;
      local_78 = local_res18;
      local_68 = local_res20;
      local_90 = 4;
      local_80 = 4;
      local_70 = 4;
      local_60 = 4;
      if (param_5 != '\0') {
        local_58 = AcAdapter + 0x184;
        lVar3 = -1;
        lVar2 = -1;
        do {
          lVar2 = lVar2 + 1;
        } while (*(char *)(local_58 + lVar2) != '\0');
        local_4c = 0;
        local_50 = (int)lVar2 + 1;
        local_48 = AcAdapter + 0x284;
        lVar2 = -1;
        do {
          lVar2 = lVar2 + 1;
        } while (*(char *)(local_48 + lVar2) != '\0');
        local_3c = 0;
        local_40 = (int)lVar2 + 1;
        local_38 = AcAdapter + 900;
        do {
          lVar3 = lVar3 + 1;
        } while (*(char *)(local_38 + lVar3) != '\0');
        local_30 = (int)lVar3 + 1;
        local_2c = 0;
      }
      local_a8 = &local_98;
      uVar1 = EtwWrite(CmBattEtwHandle,puVar4,0,(-(param_5 != '\0') & 3U) + 4);
    }
  }
  return uVar1;
}



===== CmBattTracePsr @ 14001241c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTracePsr(undefined4 param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  undefined *puVar2;
  undefined4 local_res8 [2];
  undefined4 local_res10 [6];
  undefined1 auStack_68 [32];
  undefined4 **local_48;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  puVar2 = &BATTERY_EVT_PSR_GET;
  if (param_3 != '\0') {
    puVar2 = &BATTERY_EVT_PSR_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    local_res8[0] = param_1;
    local_res10[0] = param_2;
    cVar1 = EtwEventEnabled(CmBattEtwHandle,puVar2);
    if (cVar1 != '\0') {
      local_2c = 0;
      local_38 = local_res8;
      local_1c = 0;
      local_28 = local_res10;
      local_30 = 4;
      local_48 = &local_38;
      local_20 = 4;
      EtwWrite(CmBattEtwHandle,puVar2,0,2);
    }
  }
  return;
}



===== CmBattTraceRecCapabilities @ 1400124dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceRecCapabilities
               (undefined4 param_1,undefined8 param_2,undefined4 param_3,char param_4)

{
  longlong lVar1;
  char cVar2;
  undefined *puVar3;
  undefined4 local_res8 [2];
  undefined4 local_res18 [2];
  undefined1 auStack_78 [32];
  undefined4 **local_58;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  lVar1 = AcAdapter;
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  puVar3 = &BATTERY_EVT_REC_CAPABILITIES;
  if (param_4 != '\0') {
    puVar3 = &BATTERY_EVT_REC_CAPABILITIES_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    local_res8[0] = param_1;
    local_res18[0] = param_3;
    cVar2 = EtwEventEnabled(CmBattEtwHandle,puVar3);
    if (cVar2 != '\0') {
      local_3c = 0;
      local_48 = local_res8;
      local_2c = 0;
      local_1c = 0;
      local_38 = lVar1 + 0x488;
      local_40 = 4;
      local_28 = local_res18;
      local_30 = 4;
      local_58 = &local_48;
      local_20 = 4;
      EtwWrite(CmBattEtwHandle,puVar3,0,3);
    }
  }
  return;
}



===== CmBattTraceRecOverride @ 1400125c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmBattTraceRecOverride
          (undefined4 param_1,undefined8 param_2,uint param_3,undefined4 param_4,char param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined *puVar4;
  undefined4 local_res8 [2];
  undefined4 local_res20 [2];
  undefined1 auStack_a8 [32];
  undefined4 **local_88;
  uint local_78 [4];
  undefined4 *local_68;
  undefined4 local_60 [2];
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_28;
  
  lVar1 = AcAdapter;
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  puVar4 = &BATTERY_EVT_REC_OVERRIDE;
  if (param_5 != '\0') {
    puVar4 = &BATTERY_EVT_REC_OVERRIDE_RUNDOWN;
  }
  uVar2 = CONCAT71(0x1400054,-param_5);
  if (CmBattEtwRegistered != '\0') {
    local_res8[0] = param_1;
    local_res20[0] = param_4;
    uVar2 = EtwEventEnabled(CmBattEtwHandle,puVar4);
    if ((char)uVar2 != '\0') {
      local_60[1] = 0;
      local_68 = local_res8;
      local_4c = 0;
      local_58 = lVar1 + 0x491;
      local_78[0] = param_3 & 0xff;
      local_60[0] = 4;
      local_50 = 4;
      if (param_5 == '\0') {
        local_3c = 0;
        local_48 = local_78;
        local_40 = 4;
      }
      uVar3 = (ulonglong)(-(uint)(param_5 != '\0') + 3);
      local_60[uVar3 * 4 + 1] = 0;
      *(undefined4 **)(local_78 + uVar3 * 4 + 4) = local_res20;
      local_88 = &local_68;
      local_60[uVar3 * 4] = 4;
      uVar2 = EtwWrite(CmBattEtwHandle,puVar4,0,-(uint)(param_5 != '\0') + 4);
    }
  }
  return uVar2;
}



===== CmBattTraceRecStatus @ 1400126fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceRecStatus(undefined4 param_1,undefined8 param_2,undefined4 param_3,char param_4)

{
  longlong lVar1;
  char cVar2;
  undefined *puVar3;
  undefined4 local_res8 [2];
  undefined4 local_res18 [2];
  undefined1 auStack_b8 [32];
  undefined4 **local_98;
  uint local_88 [4];
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  lVar1 = AcAdapter;
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  puVar3 = &BATTERY_EVT_REC_STATUS;
  if (param_4 != '\0') {
    puVar3 = &BATTERY_EVT_REC_STATUS_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    local_res8[0] = param_1;
    local_res18[0] = param_3;
    cVar2 = EtwEventEnabled(CmBattEtwHandle,puVar3);
    if (cVar2 != '\0') {
      local_6c = 0;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_88[0] = (uint)*(byte *)(lVar1 + 0x490);
      local_78 = local_res8;
      local_68 = local_88;
      local_58 = lVar1 + 0x498;
      local_48 = lVar1 + 0x4a0;
      local_38 = lVar1 + 0x491;
      local_28 = local_res18;
      local_98 = &local_78;
      local_70 = 4;
      local_60 = 4;
      local_50 = 8;
      local_40 = 8;
      local_30 = 4;
      local_20 = 4;
      EtwWrite(CmBattEtwHandle,puVar3,0,6);
    }
  }
  return;
}



===== CmBattTraceRecSupported @ 140012834 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CmBattTraceRecSupported(undefined4 param_1,undefined8 param_2,undefined4 param_3,char param_4)

{
  longlong lVar1;
  char cVar2;
  undefined *puVar3;
  undefined4 local_res8 [2];
  undefined4 local_res18 [2];
  undefined1 auStack_78 [32];
  undefined4 **local_58;
  uint local_48 [2];
  undefined4 *local_40;
  undefined4 local_38;
  undefined4 local_34;
  uint *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  lVar1 = AcAdapter;
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  puVar3 = &BATTERY_EVT_REC_SUPPORTED;
  if (param_4 != '\0') {
    puVar3 = &BATTERY_EVT_REC_SUPPORTED_RUNDOWN;
  }
  if (CmBattEtwRegistered != '\0') {
    local_res8[0] = param_1;
    local_res18[0] = param_3;
    cVar2 = EtwEventEnabled(CmBattEtwHandle,puVar3);
    if (cVar2 != '\0') {
      local_34 = 0;
      local_24 = 0;
      local_14 = 0;
      local_48[0] = *(uint *)(lVar1 + 0x170) >> 1 & 1;
      local_38 = 4;
      local_40 = local_res8;
      local_30 = local_48;
      local_20 = local_res18;
      local_58 = &local_40;
      local_28 = 4;
      local_18 = 4;
      EtwWrite(CmBattEtwHandle,puVar3,0,3);
    }
  }
  return;
}



===== CmBattUnregisterEtw @ 14001292c =====

void CmBattUnregisterEtw(void)

{
  undefined8 uVar1;
  
  if (CmBattEtwRegistered != '\0') {
    EtwUnregister(CmBattEtwHandle);
    uVar1 = DAT_140007030;
    DAT_140007030 = 0;
    DAT_140007010 = 0;
    CmBattEtwRegistered = '\0';
    EtwUnregister(uVar1);
  }
  return;
}



===== _tlgEnableCallback @ 140012990 =====

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



===== entry @ 140013010 =====

void entry(longlong param_1,short *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140013044 =====

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



===== DriverEntry @ 140013078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,short *param_2)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  wil_InitializeFeatureStaging();
  DAT_1400071e8 = &BatteryListHead;
  BatteryListHead = &BatteryListHead;
  KeInitializeGuardedMutex(&DeviceObjectMutex);
  iVar3 = EtwRegister(&BATTERY_ETW_PROVIDER,CmBattTraceControlCallback,0,&CmBattEtwHandle);
  puVar4 = auStack_48;
  if (-1 < iVar3) {
    CmBattEtwRegistered = 1;
    local_28 = *(undefined4 *)(PTR_DAT_140007018 + -0x10);
    uStack_24 = *(undefined4 *)(PTR_DAT_140007018 + -0xc);
    uStack_20 = *(undefined4 *)(PTR_DAT_140007018 + -8);
    uStack_1c = *(undefined4 *)(PTR_DAT_140007018 + -4);
    puVar4 = auStack_48;
    if (DAT_140007030 != 0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(5);
      puVar4 = auStack_40;
    }
    _DAT_140007038 = 0;
    uRam0000000140007040 = 0;
    *(undefined8 *)(puVar4 + -8) = 0x14001314c;
    iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_140007010,&DAT_140007030);
    if (iVar3 == 0) {
      uVar1 = *(undefined2 *)PTR_DAT_140007018;
      *(undefined8 *)(puVar4 + -8) = 0x140013175;
      EtwSetInformation(DAT_140007030,2,PTR_DAT_140007018,uVar1);
    }
    _DAT_1400071f2 = *param_2 + 2;
    _GlobalRegistryPath = *param_2;
    *(undefined8 *)(puVar4 + -8) = 0x1400131a6;
    DAT_1400071f8 = ExAllocatePool2(0x100,_DAT_1400071f2,0x4d746142);
    if (DAT_1400071f8 != 0) {
      *(undefined8 *)(puVar4 + -8) = 0x140013239;
      RtlCopyUnicodeString(&GlobalRegistryPath,param_2);
      iVar3 = 0;
      *(code **)(param_1 + 0x68) = CmBattUnload;
      *(code **)(param_1 + 0xe0) = CmBattIoctl;
      *(code **)(param_1 + 0x70) = CmBattOpenClose;
      *(code **)(param_1 + 0x80) = CmBattOpenClose;
      *(code **)(param_1 + 0x120) = CmBattPowerDispatch;
      *(code **)(param_1 + 0x148) = CmBattPnpDispatch;
      *(code **)(param_1 + 0x128) = CmBattSystemControl;
      *(code **)(*(longlong *)(param_1 + 0x30) + 8) = CmBattAddDevice;
      goto LAB_140013208;
    }
    iVar3 = -0x3fffff66;
    *(undefined8 *)(puVar4 + -8) = 0x1400131c1;
    CmBattUnregisterEtw();
  }
  if (g_wil_details_featureChangeNotification != 0) {
    *(undefined8 *)(puVar4 + -8) = 0x1400131d4;
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    *(undefined8 *)(puVar4 + -8) = 0x1400131f4;
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
LAB_140013208:
  *(undefined8 *)(puVar4 + -8) = 0x140013217;
  return iVar3;
}



===== wil_InitializeFeatureStaging @ 1400132b0 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_140013337;
    }
LAB_140013371:
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
LAB_140013337:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140013371;
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
    goto LAB_140013371;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000641f < ppuVar3) goto LAB_140013371;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_140013337;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400133c4 =====

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
            if (&UNK_14000641f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1400134ae;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1400134ae;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1400134ae:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000641f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


