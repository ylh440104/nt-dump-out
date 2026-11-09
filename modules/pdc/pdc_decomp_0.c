
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (longlong param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = *(undefined8 *)(param_1 + 8);
  *(uint *)(param_6 + 1) = (uint)**(ushort **)(param_1 + 8);
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(*(undefined8 *)(param_1 + 0x20),&local_18,0,0,param_5,param_6);
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



===== ZwPowerInformation @ 1400010cd =====

void ZwPowerInformation(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400010cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ZwPowerInformation();
  return;
}



===== __C_specific_handler @ 1400010df =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline @ 1400010f4 =====

ulonglong Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_PDCParallelAlpcProcess__private_featureState;
  if ((Feature_PDCParallelAlpcProcess__private_featureState & 0x10) == 0) {
    uVar1 = Feature_PDCParallelAlpcProcess__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_PDCParallelAlpcProcess__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_PDCParallelAlpcProcess__private_IsEnabledFallback @ 14000112c =====

void Feature_PDCParallelAlpcProcess__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_PDCParallelAlpcProcess__private_descriptor)
  ;
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140001148 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140012158;
  uVar2 = 0;
  if (DAT_140012158 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140012158;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(PDC_EVENT_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateU0qq_EtwWriteTransfer @ 1400011ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res18;
  local_28 = local_res20;
  local_2c = 0;
  local_30 = 4;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(4,param_2,param_3,3,local_48);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000121c =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4,uint param_5)

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
      uVar3 = uVar5 + param_5;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        param_1[2] = param_3;
        param_1[1] = uVar5;
        uVar3 = param_5;
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
LAB_1400012ff:
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
          param_1[1] = param_5;
          param_1[2] = param_3;
          param_1[3] = param_4;
          return param_1;
        }
        goto LAB_1400012ff;
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
      uVar3 = uVar5 + param_5;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        param_1[2] = param_3;
        param_1[1] = uVar5;
        uVar3 = param_5;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140001524 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3,undefined8 param_4)

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
      goto LAB_1400015f5;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_1400015f5;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_1400015f5;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_1400015f5;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_1400015f5;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_1400015f5;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_1400015f5;
    }
  }
  uVar3 = 0xff;
LAB_1400015f5:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect
                    (param_1,param_2,uVar3,(uint)param_4);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,param_4);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140001650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3,uint param_4)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStackY_a8 [32];
  undefined8 local_78;
  uint local_70 [6];
  uint local_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_70,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20),
                      param_4);
  local_58 = *puVar2;
  uStack_54 = puVar2[1];
  uStack_50 = puVar2[2];
  uStack_4c = puVar2[3];
  local_48 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,param_4,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_78._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_78;
    local_78 = (ulonglong)(uint6)local_78;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_78 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_78);
  }
  return (int)local_48 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140001738 =====

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
LAB_1400017eb:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140001819;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_1400017eb;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140001819:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400019a4 =====

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



===== wil_details_IsEnabledFallback @ 140001a08 =====

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
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2,1),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== wil_details_RecordCachedUsage @ 140001aa4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001c00 =====

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



===== PdcGetRegistryDwordValue @ 140001c84 =====

void PdcGetRegistryDwordValue
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 local_78 [8];
  undefined4 local_70;
  undefined8 local_68;
  undefined4 *local_60;
  undefined4 local_58;
  
  memset(local_78,0,0x70);
  local_70 = 0x124;
  local_58 = 0x4000000;
  local_68 = param_2;
  local_60 = param_4;
  iVar1 = RtlQueryRegistryValuesEx(0,param_1,local_78,0,0);
  if (iVar1 < 0) {
    *param_4 = param_3;
  }
  return;
}



===== Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline @ 140001d18 =====

ulonglong Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_PdcResiliencyV2__private_featureState;
  if ((Feature_PdcResiliencyV2__private_featureState & 0x10) == 0) {
    uVar1 = Feature_PdcResiliencyV2__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_PdcResiliencyV2__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_PdcResiliencyV2__private_IsEnabledFallback @ 140001d50 =====

void Feature_PdcResiliencyV2__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_PdcResiliencyV2__private_descriptor);
  return;
}



===== McTemplateU0pt_EtwWriteTransfer @ 140001d6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_res18;
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res18;
  local_28 = local_res20;
  local_2c = 0;
  local_30 = 8;
  local_1c = 0;
  local_20 = 4;
  local_res18 = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,3,local_48);
  return;
}



===== McTemplateU0pqqNR2qzr4_EtwWriteTransfer @ 140001de0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pqqNR2qzr4_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,int param_8,
               undefined8 param_9)

{
  undefined8 local_res18;
  undefined4 local_res20 [2];
  undefined1 auStackY_c8 [32];
  undefined4 local_98 [4];
  undefined8 local_88 [2];
  undefined8 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_60 = 4;
  local_98[0] = 8;
  local_78 = &local_res18;
  local_1c = 0;
  local_68 = local_res20;
  local_70 = 8;
  local_58 = local_98;
  local_50 = 4;
  local_48 = param_7;
  local_38 = &param_8;
  local_28 = param_9;
  local_20 = param_8 * 2;
  local_40 = 0x80;
  local_30 = 4;
  local_res18 = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(8,&PDC_ACTIVATOR_RUNDOWN,param_3,7,local_88);
  return;
}



===== McTemplateU0pqq_EtwWriteTransfer @ 140001ea4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined8 local_res18;
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 8;
  local_48 = &local_res18;
  local_30 = 4;
  local_38 = local_res20;
  local_28 = &param_5;
  local_20 = 4;
  local_res18 = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateU0pqqqzr3_EtwWriteTransfer @ 140001f20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pqqqzr3_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,int param_6,undefined8 param_7)

{
  undefined8 local_res18;
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_60 = 8;
  local_68 = &local_res18;
  local_50 = 4;
  local_58 = local_res20;
  local_48 = &param_5;
  local_38 = &param_6;
  local_40 = 4;
  local_28 = param_7;
  local_20 = param_6 * 2;
  local_30 = 4;
  local_1c = 0;
  local_res18 = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,6,local_78);
  return;
}



===== McTemplateU0qqq_EtwWriteTransfer @ 140001fcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res18;
  local_38 = local_res20;
  local_28 = &param_5;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateU0qzr0qzr2_EtwWriteTransfer @ 140002044 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qzr0qzr2_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int local_res18 [4];
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [4];
  undefined8 local_68 [2];
  int *local_58;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (int)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = local_res18;
  local_3c = 0;
  local_40 = local_res18[0] * 2;
  local_38 = local_78;
  local_78[0] = 0xe;
  local_28 = L"ResiliencyType";
  local_50 = 4;
  local_30 = 4;
  local_20 = 0x1c;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_INVALID_ARGUMENT_TO_FUNCTION,param_3,5,local_68);
  return;
}



===== PdcV2ActivatorReceive @ 1400020e4 =====

ulonglong PdcV2ActivatorReceive(longlong param_1,undefined8 *param_2,longlong param_3)

{
  int iVar1;
  undefined4 extraout_var;
  ulonglong uVar2;
  undefined4 extraout_var_00;
  
  iVar1 = *(int *)(param_2 + 5);
  if (iVar1 == 10) {
    iVar1 = PdcpV2Activation(param_1,param_2);
    uVar2 = CONCAT44(extraout_var,iVar1);
  }
  else if (iVar1 == 0xb) {
    uVar2 = PdcpV2Renew(param_1,param_2);
  }
  else if (iVar1 == 0xd) {
    iVar1 = PdcpV2Deactivation(param_1,param_2,param_3);
    uVar2 = CONCAT44(extraout_var_00,iVar1);
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== PdcpActivationResiliencyRequestCallback @ 140002120 =====

void PdcpActivationResiliencyRequestCallback(longlong param_1,undefined8 param_2,longlong param_3)

{
  *(undefined4 *)(param_1 + 0x33c) = 2;
  PdcpCompleteResiliencyOperation(param_1,param_2,param_3);
  return;
}



===== Feature_PoAdaptiveStandby__private_IsEnabledDeviceUsageNoInline @ 140002140 =====

ulonglong Feature_PoAdaptiveStandby__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_PoAdaptiveStandby__private_featureState;
  if ((Feature_PoAdaptiveStandby__private_featureState & 0x10) == 0) {
    uVar1 = Feature_PoAdaptiveStandby__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_PoAdaptiveStandby__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_PoAdaptiveStandby__private_IsEnabledFallback @ 140002178 =====

void Feature_PoAdaptiveStandby__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_PoAdaptiveStandby__private_descriptor);
  return;
}



===== McTemplateU0qzr0t_EtwWriteTransfer @ 140002194 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qzr0t_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  int local_res18 [4];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (int)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res18;
  local_40 = 4;
  local_30 = local_res18[0] * 2;
  local_20 = 4;
  local_28 = &param_5;
  local_2c = 0;
  local_38 = param_4;
  McGenEventWrite_EtwWriteTransfer(0,&PDC_CLIENT_POLICY_STATUS_CHANGED,param_3,4,local_58);
  return;
}



===== McTemplateU0qzr0tqUR3_EtwWriteTransfer @ 140002214 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qzr0tqUR3_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined8 param_6,undefined8 param_7)

{
  int local_res18 [4];
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined8 local_78 [2];
  int *local_68;
  undefined8 local_60;
  undefined8 local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (int)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68 = local_res18;
  local_88[0] = 0x7d;
  local_50 = local_res18[0] * 2;
  local_4c = 0;
  local_48 = &param_5;
  local_60 = 4;
  local_38 = local_88;
  local_40 = 4;
  local_28 = param_7;
  local_30 = 4;
  local_20 = 0x7d;
  local_58 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_CLIENT_POLICY_RUNDOWN,param_3,6,local_78);
  return;
}



===== PdcpEaStopPolicyEvent @ 1400022c0 =====

void PdcpEaStopPolicyEvent(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  PdcAcquireLock();
  PdcpClientPolicyDisableEaRule(param_3);
  PdcReleaseLock();
  return;
}



===== StringCbCatW @ 1400022e8 =====

HRESULT __stdcall StringCbCatW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc)

{
  wchar_t wVar1;
  uint uVar2;
  STRSAFE_LPWSTR pwVar3;
  longlong lVar4;
  STRSAFE_LPWSTR pwVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  
  lVar7 = 0xc0;
  pwVar3 = pszDest;
  do {
    if (*pwVar3 == L'\0') break;
    pwVar3 = pwVar3 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar6 = -(ulonglong)(lVar7 != 0) & 0xc0U - lVar7;
  uVar2 = ~-(uint)(lVar7 != 0) & 0x80070057;
  if (lVar7 != 0) {
    pwVar3 = pszDest + uVar6;
    lVar7 = 0xc0 - uVar6;
    if (lVar7 != 0) {
      lVar4 = 0x7ffffffe;
      lVar8 = (longlong)pszSrc - (longlong)pwVar3;
      do {
        if ((lVar4 == 0) || (wVar1 = *(wchar_t *)(lVar8 + (longlong)pwVar3), wVar1 == L'\0')) break;
        *pwVar3 = wVar1;
        lVar4 = lVar4 + -1;
        pwVar3 = pwVar3 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    pwVar5 = pwVar3 + -1;
    if (lVar7 != 0) {
      pwVar5 = pwVar3;
    }
    *pwVar5 = L'\0';
    uVar2 = ~-(uint)(lVar7 != 0) & 0x8007007a;
  }
  return uVar2;
}



===== McTemplateU0qqqzr2_EtwWriteTransfer @ 140002390 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqqzr2_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               int param_5,undefined8 param_6)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 4;
  local_58 = local_res18;
  local_1c = 0;
  local_48 = local_res20;
  local_38 = &param_5;
  local_28 = param_6;
  local_20 = param_5 * 2;
  local_40 = 4;
  local_30 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_CLIENT_VERBOSE_RUNDOWN,param_3,5,local_68);
  return;
}



===== PdcPostprocessClient @ 140002430 =====

ulonglong PdcPostprocessClient(undefined8 *param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  ulonglong local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  iVar1 = *(int *)(param_1 + 2);
  uVar4 = 0;
  if (iVar1 == 0) {
    uVar4 = PdcNotificationPostprocess((longlong)param_1);
    uVar4 = uVar4 & 0xffffffff;
  }
  else if (iVar1 == 1) {
    uVar2 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      if (*(int *)(param_1 + 5) == 6) {
        for (puVar5 = (undefined8 *)param_1[6]; puVar5 != param_1 + 6;
            puVar5 = (undefined8 *)*puVar5) {
          local_20 = puVar5[2];
          local_18 = 0;
          local_28 = 1;
          PdcpResiliencyClientOneTimeTransaction((longlong)param_1,&local_28,(uint)(puVar5[3] == 0))
          ;
        }
      }
      else {
        lVar3 = PdcpResiliencyClientGetRefCount((longlong)param_1,0);
        PdcpResiliencyClientOneTimeTransaction
                  ((longlong)param_1,(ulonglong *)0x0,(uint)(lVar3 == 0));
      }
    }
  }
  else if (iVar1 != 2) {
    if (iVar1 == 3) {
      PdcSuspendResumeClientPostProcess(param_1);
    }
    else if ((((iVar1 != 4) && (iVar1 != 5)) && (iVar1 != 6)) && ((iVar1 != 7 && (iVar1 != 8)))) {
      uVar4 = 0xc000000d;
    }
  }
  return uVar4;
}



===== PdcpDumpControlCallback @ 140002550 =====

void PdcpDumpControlCallback(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  
  if ((*(int *)(param_3 + 0x10) == 0x14f) || (*(int *)(param_3 + 0x10) == 0x15c)) {
    lVar2 = *(longlong *)(param_3 + 0x30);
    KeAddTriageDumpDataBlock(param_2 + 0x30,lVar2,0x28);
    if (*(longlong *)(lVar2 + 8) != 0) {
      IoAddBugcheckTriageThread();
    }
    plVar1 = (longlong *)(lVar2 + 0x10);
    lVar2 = 3;
    do {
      if (*plVar1 != 0) {
        IoAddBugcheckTriageThread();
      }
      plVar1 = plVar1 + 1;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
  }
  return;
}



===== PdcpLockWatchdogLKDCallback @ 1400025e0 =====

void PdcpLockWatchdogLKDCallback(undefined8 param_1,longlong param_2,longlong *param_3)

{
  if (((int)param_3[2] == 0x17c) && (*(char *)(param_2 + -0x18) != '\0')) {
    *(int *)(param_2 + -0x14) = *(int *)(param_2 + -0x14) + 1;
    *param_3 = param_2 + 0x30;
  }
  return;
}



===== GetPdcLockThread @ 140002604 =====

undefined8 GetPdcLockThread(void)

{
  return PdcLockThread;
}



===== PdcGetInterruptTime @ 140002614 =====

void PdcGetInterruptTime(void)

{
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  KeQueryInterruptTimePrecise(local_res8);
  return;
}



===== PdcGetScenarioInstanceId @ 14000263c =====

undefined8 PdcGetScenarioInstanceId(void)

{
  return DAT_140015130;
}



===== PdcInternalError @ 14000264c =====

void PdcInternalError(void)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xa0,0x100,1,0,0);
}



===== Feature_14FBugcheckMinidumpDiagnostics__private_IsEnabledDeviceUsageNoInline @ 140002678 =====

ulonglong Feature_14FBugcheckMinidumpDiagnostics__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_14FBugcheckMinidumpDiagnostics__private_featureState;
  if ((Feature_14FBugcheckMinidumpDiagnostics__private_featureState & 0x10) == 0) {
    uVar1 = Feature_14FBugcheckMinidumpDiagnostics__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_14FBugcheckMinidumpDiagnostics__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_14FBugcheckMinidumpDiagnostics__private_IsEnabledFallback @ 1400026b0 =====

void Feature_14FBugcheckMinidumpDiagnostics__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_14FBugcheckMinidumpDiagnostics__private_descriptor);
  return;
}



===== McTemplateU0_EtwWriteTransfer @ 1400026cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,1,local_28);
  return;
}



===== McTemplateU0q_EtwWriteTransfer @ 140002710 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0q_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 local_res18 [4];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res18;
  local_1c = 0;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== McTemplateU0qqqqqqqq_EtwWriteTransfer @ 14000276c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqqqqqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined4 *local_98;
  undefined8 local_90;
  undefined4 *local_88;
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
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = local_res18;
  local_90 = 4;
  local_88 = local_res20;
  local_80 = 4;
  local_78 = &param_5;
  local_70 = 4;
  local_68 = &param_6;
  local_58 = &param_7;
  local_48 = &param_8;
  local_38 = &param_9;
  local_28 = &param_10;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_ENTER_CS_END,param_3,9,local_a8);
  return;
}



===== McTemplateU0qqqqqqqqx_EtwWriteTransfer @ 140002848 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqqqqqqqx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_e8 [32];
  undefined8 local_b8 [2];
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
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
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8 = local_res18;
  local_a0 = 4;
  local_98 = local_res20;
  local_90 = 4;
  local_88 = &param_5;
  local_80 = 4;
  local_78 = &param_6;
  local_68 = &param_7;
  local_58 = &param_8;
  local_48 = &param_9;
  local_38 = &param_10;
  local_28 = &param_11;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_EXIT_CS_END,param_3,10,local_b8);
  return;
}



===== PdcMaintenanceResumeTimerCallback @ 140002940 =====

void PdcMaintenanceResumeTimerCallback(void)

{
  ExQueueWorkItem(&PdcMaintenanceResumeWorkItem,1);
  return;
}



===== PdcMaintenanceResumeWorkItemCallback @ 140002970 =====

void PdcMaintenanceResumeWorkItemCallback(undefined8 param_1)

{
  PdcAcquireLock();
  if (PdcMaintenanceResumeTimerScheduled == '\0') {
    PdcReleaseLock();
  }
  else {
    PdcMaintenanceResumeTimerScheduled = '\0';
    PdcReleaseLock();
    PdcTaskClientRequest(param_1,'\0');
  }
  return;
}



===== PdcPoNetworkResiliency @ 1400029a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcPoNetworkResiliency(void)

{
  (*DAT_1400150d8)();
  return;
}



===== PdcPoNotifyPhaseEntryExit @ 1400029c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcPoNotifyPhaseEntryExit(void)

{
  (*DAT_1400150b8)();
  return;
}



===== PdcpLogPhaseAccounting @ 1400029e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcpLogPhaseAccounting(undefined8 param_1)

{
  undefined1 auStack_88 [32];
  ulonglong local_68 [10];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  PdcPhasesQueryTotalTimes(local_68);
  PdcDiagTracePhasesAccounting(local_68,param_1);
  PdcPhasesLogPhaseBlockers();
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 140002a34 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== McTemplateU0qqqqqqqtqqq_EtwWriteTransfer @ 140002a40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqqqqqqtqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_148 [32];
  undefined4 local_118 [2];
  undefined4 local_110 [2];
  undefined4 local_108 [2];
  undefined4 local_100 [2];
  undefined4 local_f8 [2];
  undefined4 local_f0 [2];
  undefined4 local_e8 [2];
  undefined4 local_e0 [2];
  undefined8 local_d8 [2];
  undefined4 *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
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
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  local_c0 = 4;
  local_c8 = local_res18;
  local_e0[0] = 0;
  local_b8 = local_res20;
  local_a8 = &param_5;
  local_98 = local_118;
  local_e8[0] = 0;
  local_88 = local_110;
  local_78 = local_108;
  local_68 = local_100;
  local_58 = local_f8;
  local_48 = local_f0;
  local_38 = local_e8;
  local_28 = local_e0;
  local_f0[0] = 0;
  local_f8[0] = 0;
  local_100[0] = 0;
  local_108[0] = 0;
  local_110[0] = 0;
  local_118[0] = 0;
  local_b0 = 4;
  local_a0 = 4;
  local_90 = 4;
  local_80 = 4;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_MONITOR_CTX,param_3,0xc,local_d8);
  return;
}



===== PdcMonitorInitialize @ 140002b78 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcMonitorInitialize(void)

{
  int local_res8 [2];
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  PdcGetRegistryDwordValue
            (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",L"PdcOneWayEntry",0,
             local_res8);
  DAT_140014db4 = 0;
  DAT_140014dc8 = 1;
  DAT_140014db0 = (uint)(local_res8[0] != 0);
  DAT_140014da8 = 0xffffffff;
  PdcMonitor = 0xffffffff;
  DAT_140014dd0 = KeQueryInterruptTimePrecise(local_res10);
  DAT_140014df4 = 0;
  DAT_140014dd8 = 0;
  _DAT_140014df0 = 0x3f;
  memset(&DAT_140014df8,0,0x200);
  PdcInitializeTimer(0x140014cc0,PdcpSessionTimerCallback,0,0,1);
  PdcRwLockInitialize((undefined8 *)&PdcMonitorLock);
  return;
}



===== PdcQueryAllPhasesDisengagedTime @ 140002c4c =====

undefined8 PdcQueryAllPhasesDisengagedTime(void)

{
  undefined8 uVar1;
  
  PdcpAcquireMonitorLock();
  uVar1 = DAT_140014dd0;
  PdcpReleaseMonitorLock();
  return uVar1;
}



===== PdcpIsPowerSettingInitialized @ 140002c74 =====

undefined1 PdcpIsPowerSettingInitialized(void)

{
  return DAT_140014dad;
}



===== AppModelPolicy_Kernel_GetPolicy @ 140002c84 =====

int AppModelPolicy_Kernel_GetPolicy(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  ulonglong local_res18;
  ulonglong local_res20;
  
  local_res20 = 0;
  local_res18 = 0;
  iVar1 = RtlQueryPackageClaims(param_1,0,0,0,0,0,&local_res18,&local_res20);
  if (iVar1 == -0x3ffffddb) {
    local_res20 = 0;
    local_res18 = local_res18 & 0xffffffff00000000;
    iVar1 = 0;
    uVar2 = 0;
  }
  else {
    *param_3 = 0;
    if (iVar1 < 0) {
      return iVar1;
    }
    uVar2 = (uint)local_res18;
  }
  if ((local_res20 & 1) == 0) {
    puVar3 = &DAT_14000ce04;
  }
  else if ((local_res20 & 8) == 0) {
    if ((uVar2 >> 0x10 & 1) == 0) {
      if ((uVar2 >> 0xe & 1) == 0) {
        if ((uVar2 & 4) == 0) {
          if ((uVar2 >> 10 & 1) == 0) {
            if ((uVar2 >> 0xb & 1) == 0) {
              if ((uVar2 & 0x40) == 0) {
                if ((uVar2 & 8) == 0) {
                  puVar3 = &DAT_14000ce24;
                  if ((uVar2 >> 0x12 & 1) == 0) {
                    puVar3 = &DAT_14000cdfc;
                  }
                }
                else {
                  puVar3 = &DAT_14000ce08;
                }
              }
              else {
                puVar3 = &DAT_14000ce0c;
              }
            }
            else {
              puVar3 = &DAT_14000ce14;
            }
          }
          else {
            puVar3 = &DAT_14000ce10;
          }
        }
        else {
          puVar3 = &DAT_14000ce00;
        }
      }
      else {
        puVar3 = &DAT_14000ce20;
      }
    }
    else {
      puVar3 = &DAT_14000ce18;
    }
  }
  else {
    puVar3 = &DAT_14000ce1c;
  }
  *param_3 = *puVar3;
  if ((uVar2 >> 0x14 & 1) != 0) {
    *param_3 = 0x3a0000;
  }
  Feature_PackagedComElevationSupport__private_IsEnabledNoReportingNoInline();
  return iVar1;
}



===== Feature_PackagedComElevationSupport__private_IsEnabledFallback @ 140002db4 =====

void Feature_PackagedComElevationSupport__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_PackagedComElevationSupport__private_descriptor);
  return;
}



===== Feature_PackagedComElevationSupport__private_IsEnabledNoReportingNoInline @ 140002dd0 =====

ulonglong Feature_PackagedComElevationSupport__private_IsEnabledNoReportingNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_PackagedComElevationSupport__private_featureState;
  if ((Feature_PackagedComElevationSupport__private_featureState & 2) == 0) {
    uVar1 = Feature_PackagedComElevationSupport__private_IsEnabledFallback(local_res8,0);
  }
  else {
    uVar1 = (ulonglong)(Feature_PackagedComElevationSupport__private_featureState & 1);
  }
  return uVar1;
}



===== McTemplateU0pqpqq_EtwWriteTransfer @ 140002e08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pqpqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res18;
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
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
  local_68 = &local_res18;
  local_60 = 8;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_38 = &param_6;
  local_28 = &param_7;
  local_40 = 8;
  local_30 = 4;
  local_20 = 4;
  local_res18 = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,6,local_78);
  return;
}



===== McTemplateU0qqqpqqq_EtwWriteTransfer @ 140002eb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqqpqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined8 local_98 [2];
  undefined4 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_80 = 4;
  local_88 = local_res18;
  local_a8[0] = 0;
  local_78 = local_res20;
  local_68 = &param_5;
  local_58 = local_a8;
  local_70 = 4;
  local_48 = &param_7;
  local_60 = 4;
  local_38 = &param_8;
  local_28 = &param_9;
  local_50 = 8;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_SUSPEND_RESUME_STARTED,param_3,8,local_98);
  return;
}



===== McTemplateU0ppqqq_EtwWriteTransfer @ 140002f7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0ppqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = &local_res18;
  local_60 = 8;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res18 = param_3;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_NOTIFICATION_MESSAGE,param_3,6,local_78);
  return;
}



===== McTemplateU0qpqqq_EtwWriteTransfer @ 140003028 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qpqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res18 [2];
  undefined8 local_res20;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = local_res18;
  local_60 = 4;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 4;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_NOTIFICATION_STARTED,param_3,6,local_78);
  return;
}



===== McTemplateU0pqqqqzr4_EtwWriteTransfer @ 1400030d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pqqqqzr4_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,int param_7,undefined8 param_8)

{
  undefined8 local_res18;
  undefined4 local_res20 [2];
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined8 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_70 = 8;
  local_78 = &local_res18;
  local_1c = 0;
  local_68 = local_res20;
  local_58 = &param_5;
  local_48 = &param_6;
  local_60 = 4;
  local_38 = &param_7;
  local_50 = 4;
  local_28 = param_8;
  local_20 = param_7 * 2;
  local_40 = 4;
  local_30 = 4;
  local_res18 = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_TASK_RUNDOWN,param_3,7,local_88);
  return;
}



===== PdcTaskClientRevocationMaskUpdate @ 140003194 =====

void PdcTaskClientRevocationMaskUpdate
               (longlong param_1,undefined8 param_2,undefined8 *param_3,ulonglong param_4)

{
  char cVar1;
  uint uVar2;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  uint *puVar3;
  undefined *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  
  for (puVar6 = PdcTaskClients; (undefined8 **)puVar6 != &PdcTaskClients;
      puVar6 = (undefined8 *)*puVar6) {
    uVar2 = *(uint *)(puVar6 + 6);
    param_3 = (undefined8 *)
              (CONCAT71((int7)((ulonglong)param_3 >> 8),(char)uVar2) & 0xffffffffffffff01);
    if ((*(byte *)((ulonglong)*(uint *)(puVar6 + 5) + param_1) & 1) == 0) {
      if ((char)param_3 != '\0') {
        uVar2 = uVar2 & 0xfffffffe;
        uVar5 = (ulonglong)uVar2;
        *(uint *)(puVar6 + 6) = uVar2;
        if ((uVar2 == 0) && (0 < *(int *)((longlong)puVar6 + 0x2c))) {
          cVar1 = PdcpGetTaskClientRequestGroup((longlong)puVar6);
          puVar4 = (undefined *)CONCAT71((int7)(uVar5 >> 8),1);
          puVar3 = (uint *)(CONCAT71(extraout_var_00,cVar1) & 0xffffffff);
          PdcGroupRequest(puVar3,'\x01');
          if ((DAT_140015c02 & 1) != 0) {
            uVar2 = PdcPhasesGetCurrent();
            param_4 = (ulonglong)uVar2;
            puVar4 = &PDC_TASK_REFERENCE;
            param_3 = puVar6;
            McTemplateU0pqq_EtwWriteTransfer(puVar3,&PDC_TASK_REFERENCE,puVar6,uVar2,1);
          }
          PdcpStatsMarkTaskClientActive((longlong)puVar6,puVar4,param_3,param_4);
        }
      }
    }
    else if ((char)param_3 == '\0') {
      if ((uVar2 == 0) && (0 < *(int *)((longlong)puVar6 + 0x2c))) {
        cVar1 = PdcpGetTaskClientRequestGroup((longlong)puVar6);
        puVar4 = (undefined *)0x0;
        puVar3 = (uint *)(CONCAT71(extraout_var,cVar1) & 0xffffffff);
        PdcGroupRequest(puVar3,'\0');
        if (DAT_140015c01 < '\0') {
          uVar2 = PdcPhasesGetCurrent();
          puVar4 = &PDC_TASK_DEREFERENCE;
          param_4 = (ulonglong)uVar2;
          param_3 = puVar6;
          McTemplateU0pqq_EtwWriteTransfer(puVar3,&PDC_TASK_DEREFERENCE,puVar6,uVar2,0);
        }
        PdcpStatsMarkTaskClientInactive((longlong)puVar6,puVar4,param_3,param_4);
      }
      if (*(int *)(puVar6 + 0x6b) == 0x103) {
        *(undefined4 *)(puVar6 + 0x6b) = 0;
        PdcpTaskClientAcknowledge((longlong)puVar6,0);
      }
      *(uint *)(puVar6 + 6) = *(uint *)(puVar6 + 6) | 1;
    }
  }
  return;
}



===== McTemplateU0ppq_EtwWriteTransfer @ 1400032bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0ppq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res18;
  local_40 = 8;
  local_38 = &local_res20;
  local_30 = 8;
  local_28 = &param_5;
  local_20 = 4;
  local_res18 = param_3;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateU0ppqxqqqqzr7_EtwWriteTransfer @ 14000333c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0ppqxqqqqzr7_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,int param_10,undefined8 param_11)

{
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStackY_e8 [32];
  undefined8 local_b8 [2];
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
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
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a0 = 8;
  local_a8 = &local_res18;
  local_90 = 8;
  local_98 = &local_res20;
  local_80 = 4;
  local_88 = &param_5;
  local_70 = 8;
  local_78 = &param_6;
  local_68 = &param_7;
  local_58 = &param_8;
  local_48 = &param_9;
  local_38 = &param_10;
  local_28 = param_11;
  local_20 = param_10 * 2;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_1c = 0;
  local_res18 = param_3;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_RESILIENCY_CLIENT_CTX,0,10,local_b8);
  return;
}



===== McTemplateU0pqqqtt_EtwWriteTransfer @ 140003430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pqqqtt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res18;
  undefined4 local_res20 [2];
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined8 *local_78;
  undefined8 local_70;
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
  local_78 = &local_res18;
  local_70 = 8;
  local_68 = local_res20;
  local_60 = 4;
  local_58 = &param_5;
  local_50 = 4;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = &param_8;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res18 = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_RESILIENCY_MESSAGE,param_3,7,local_88);
  return;
}



===== McTemplateU0pxqq_EtwWriteTransfer @ 1400034ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pxqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res18;
  local_50 = 8;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 4;
  local_28 = &param_6;
  local_20 = 4;
  local_res18 = param_3;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_RESILIENCY_CLIENT_RUNDOWN,param_3,5,local_68);
  return;
}



===== PdcSystemButtonNotifyHandler @ 140003590 =====

undefined8 PdcSystemButtonNotifyHandler(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4008) &&
     (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
    PdcAcquireRwLockExclusive(0x140032b28);
    if ((undefined8 **)PdcSwitches != &PdcSwitches) {
      puVar1 = PdcSwitches;
      do {
        if (puVar1 == (undefined8 *)*param_2) {
          *(undefined1 *)((longlong)puVar1 + 0x22) = 1;
          IoCancelIrp(puVar1[5]);
          break;
        }
        puVar1 = (undefined8 *)*puVar1;
      } while ((undefined8 **)puVar1 != &PdcSwitches);
    }
    IoUnregisterPlugPlayNotificationEx(param_2[1]);
    PdcReleaseRwLockExclusive(0x140032b28);
    ExFreePoolWithTag(param_2,0x74775350);
  }
  return 0;
}



===== PdcpExternalMonitorUpdateCallback @ 140003640 =====

void PdcpExternalMonitorUpdateCallback
               (undefined1 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  PdcAcquireRwLockExclusive(0x140032b28);
  DAT_140013688 = param_1;
  PdcpReplayLidClose(3,param_2,param_3,param_4);
  PdcReleaseRwLockExclusive(0x140032b28);
  return;
}



===== PdcpTriggerActionByCaps @ 140003680 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpTriggerActionByCaps
               (longlong param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
               uint param_5,char param_6,uint *param_7)

{
  bool bVar1;
  bool bVar2;
  longlong lVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  undefined7 extraout_var;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined7 extraout_var_00;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  longlong lVar13;
  byte *pbVar14;
  uint uVar15;
  uint uVar16;
  ulonglong uVar17;
  undefined1 auStackY_f8 [32];
  longlong local_c8;
  undefined8 *local_c0;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  longlong local_a8;
  undefined8 *local_a0;
  undefined8 *local_98;
  undefined8 local_88 [4];
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar9 = 0;
  uVar11 = 0;
  local_b4 = 0;
  uVar15 = 0;
  local_b8 = 0;
  bVar2 = false;
  local_b0 = 0;
  local_c0 = param_2;
  local_a0 = param_3;
  local_98 = param_4;
  cVar4 = PdcSystemStarted();
  uVar16 = 1;
  if (cVar4 == '\0') goto LAB_1400039db;
  uVar16 = *(uint *)(param_1 + 0x14);
  uVar17 = (ulonglong)uVar16;
  uVar15 = 0;
  if (PdcpSwitchProcessingSuspended != (char)uVar9) {
    uVar15 = 2;
  }
  uVar12 = (ulonglong)uVar15;
  uVar9 = uVar16 & 4;
  uVar10 = (ulonglong)uVar9;
  if (uVar9 != 0) {
    uVar11 = uVar15 | 4;
    if ((param_5 & 0x40000) == 0) {
      uVar11 = uVar15;
    }
    uVar15 = uVar11;
    if ((*(char *)(param_1 + 0x18) == '\x01') && (uVar15 = uVar15 | 8, param_6 != '\0')) {
      bVar2 = false;
      if (DAT_1400135e4 != 0) {
        bVar2 = true;
      }
    }
  }
  if (((int)param_5 < 0) && (uVar9 == 0)) {
    bVar2 = true;
  }
  if ((uVar16 & 3) != 0) {
    PdcpPrintPowerButton(uVar10,uVar12,uVar17,param_4);
    if ((DAT_140015c01 & 2) != 0) {
      McTemplateU0_EtwWriteTransfer(uVar10,&PDC_POWER_BUTTON_HANDLER,uVar17);
    }
    lVar3 = _DAT_fffff78000000008;
    lVar13 = _DAT_fffff78000000008 - _DAT_140015128;
    if (lVar13 < 1000000) {
      if (5 < DAT_140031288) {
        if (((DAT_140031298 & 2) == 0) || (((uint)DAT_1400312a0 & 2) != DAT_1400312a0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_5c = 0;
          local_68 = &local_a8;
          local_4c = 0;
          local_c8._0_4_ = *(undefined4 *)(param_1 + 0x14);
          local_58 = (undefined4 *)&local_c8;
          local_60 = 8;
          local_50 = 4;
          local_a8 = lVar13;
          _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000f17c,uVar17,param_4,4,local_88);
        }
      }
      uVar15 = uVar15 | 0x10;
    }
    else {
      uVar10 = (ulonglong)*(uint *)(param_1 + 0x14);
      cVar4 = PdcpSuppressPowerButton(*(uint *)(param_1 + 0x14));
      if (cVar4 == '\0') {
        _DAT_140015128 = lVar3;
        PdcpPrintPowerButtonConsumed(uVar10,lVar13,uVar17,param_4);
        if (Microsoft_Windows_PDCEnableBits < '\0') {
          McTemplateU0_EtwWriteTransfer(uVar10,&PDC_POWER_BUTTON_CONSUMED,uVar17);
        }
        bVar5 = PdcpGetSwitchRequestReason(param_1);
        iVar6 = PdcMonitorControl(2,(int)CONCAT71(extraout_var,bVar5));
        if (iVar6 == 0xff) {
          if (5 < DAT_140031288) {
            if (((DAT_140031298 & 2) == 0) || ((DAT_1400312a0 & 2) != DAT_1400312a0)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              pbVar14 = &DAT_14000ee43;
              goto LAB_140003924;
            }
          }
        }
        else if (iVar6 == 0x102) {
          uVar15 = uVar15 | 0x200;
          if (5 < DAT_140031288) {
            if (((DAT_140031298 & 2) == 0) || ((DAT_1400312a0 & 2) != DAT_1400312a0)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              pbVar14 = &DAT_14000ee76;
LAB_140003924:
              local_c8._0_4_ = *(undefined4 *)(param_1 + 0x14);
              local_5c = 0;
              local_68 = &local_c8;
              local_60 = 4;
              _tlgWriteTransfer_EtwWriteTransfer(0x140031288,pbVar14,uVar17,param_4,3,local_88);
            }
          }
        }
        else {
          uVar15 = uVar15 | 0x20;
          if (5 < DAT_140031288) {
            if (((DAT_140031298 & 2) == 0) || ((DAT_1400312a0 & 2) != DAT_1400312a0)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (bVar1) {
              pbVar14 = &DAT_14000f14a;
              goto LAB_140003924;
            }
          }
        }
      }
      else {
        uVar15 = uVar15 | 0x80;
      }
    }
    param_2 = local_c0;
  }
  uVar16 = uVar15 | 0x40;
  if (!bVar2) {
    uVar16 = uVar15;
  }
  if (uVar16 == 0) {
    uVar7 = PdcpTriggerSpecificAction(param_1,4,param_2,param_5);
    uVar8 = PdcpTriggerSpecificAction(param_1,1,local_a0,param_5);
    local_b4 = (uint)uVar8;
    uVar8 = PdcpTriggerSpecificAction(param_1,2,local_98,param_5);
    local_b8 = (uint)uVar8;
    uVar15 = (uint)uVar7;
    uVar11 = local_b8;
  }
  else {
    uVar15 = local_b0;
    uVar11 = local_b0;
  }
  if (bVar2) {
    bVar5 = PdcpGetSwitchRequestReason(param_1);
    PoSetUserPresent(CONCAT71(extraout_var_00,bVar5) & 0xffffffff);
    uVar11 = local_b8;
  }
  uVar9 = local_b4;
LAB_1400039db:
  if (param_7 != (uint *)0x0) {
    *param_7 = uVar16;
    param_7[1] = uVar15;
    param_7[2] = uVar9;
    param_7[3] = uVar11;
  }
  return;
}



===== PdcCheckForWork @ 140003a14 =====

void PdcCheckForWork(void)

{
  undefined1 uVar1;
  
  if (((PdcWorkerPending & PdcWorkerStatus) != 0) && (PdcLockThread != SystemReserved1[0xf])) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(&PdcWorkerSpinLock);
    if ((int)PdcWorkerStatus < 0) {
      PdcWorkerStatus = PdcWorkerStatus & 0x7fffffff;
      ExQueueWorkItem(&PdcPolicyWorker,1);
    }
    KeReleaseSpinLock(&PdcWorkerSpinLock,uVar1);
  }
  return;
}



===== PdcCompletePolicyIrp @ 140003aa0 =====

undefined8 PdcCompletePolicyIrp(undefined8 param_1,longlong param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  bool bVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&PdcWorkerSpinLock);
  puVar5 = auStack_28;
  puVar4 = (undefined8 *)(param_2 + 0xa8);
  puVar3 = &PdcPolicyIrpQueue;
  if ((undefined *)*DAT_140013628 != &PdcPolicyIrpQueue) {
    puVar4 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar3 = (undefined *)(*pcVar1)();
    puVar5 = auStack_20;
  }
  bVar6 = PdcDispatchPolicyIrps != '\0';
  *puVar4 = puVar3;
  puVar4[1] = DAT_140013628;
  *DAT_140013628 = puVar4;
  DAT_140013628 = puVar4;
  if (bVar6) {
    PdcWorkerPending = PdcWorkerPending | 1;
    if ((PdcWorkerStatus & 0x80000001) == 0x80000001) {
      PdcWorkerStatus = PdcWorkerStatus & 0x7fffffff;
      *(undefined8 *)(puVar5 + -8) = 0x140003b38;
      ExQueueWorkItem(&PdcPolicyWorker);
    }
  }
  if (*(int *)(param_2 + 0x30) == -0x3ffffee0) {
    *(undefined1 *)(param_2 + 0x44) = 0;
  }
  *(undefined8 *)(puVar5 + -8) = 0x140003b5b;
  KeReleaseSpinLock(&PdcWorkerSpinLock,uVar2);
  return 0xc0000016;
}



===== PdcGetPolicyWorker @ 140003b78 =====

uint PdcGetPolicyWorker(uint param_1)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&PdcWorkerSpinLock);
  uVar1 = PdcWorkerPending;
  PdcWorkerPending = PdcWorkerPending | param_1;
  KeReleaseSpinLock(&PdcWorkerSpinLock,CONCAT31((int3)(PdcWorkerPending >> 8),uVar2));
  return uVar1;
}



===== PdcStartPolicyIrps @ 140003bd0 =====

void PdcStartPolicyIrps(void)

{
  PdcDispatchPolicyIrps = 1;
  PdcGetPolicyWorker(1);
  PdcCheckForWork();
  return;
}



===== PdcpPolicyWorkerThread @ 140003c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpPolicyWorkerThread(uint param_1)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&PdcWorkerSpinLock);
  PdcWorkerStatus = param_1 | PdcWorkerStatus;
  uVar4 = 0;
  while( true ) {
    uVar3 = PdcWorkerStatus & PdcWorkerPending;
    if (uVar3 == 0) break;
    uVar1 = 0;
    if (uVar3 != 0) {
      for (; (uVar3 >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
      }
    }
    uVar5 = 1 << ((byte)uVar1 & 0x1f);
    uVar3 = ~uVar5;
    PdcWorkerPending = PdcWorkerPending & uVar3;
    PdcWorkerStatus = uVar3 & PdcWorkerStatus;
    KeReleaseSpinLock(&PdcWorkerSpinLock,CONCAT31((int3)(PdcWorkerPending >> 8),uVar2));
    uVar3 = (*(code *)(&PdcWorkerTypes)[uVar1])();
    uVar4 = uVar4 | uVar3;
    uVar2 = KeAcquireSpinLockRaiseToDpc(&PdcWorkerSpinLock);
    PdcWorkerStatus = uVar5 | PdcWorkerStatus;
  }
  PdcWorkerPending = PdcWorkerPending | uVar4;
  KeReleaseSpinLock(&PdcWorkerSpinLock,CONCAT31((int3)(PdcWorkerPending >> 8),uVar2));
  return;
}



===== PdcpAcDcSettingCallback @ 140003d00 =====

undefined4 * PdcpAcDcSettingCallback(longlong *param_1,int *param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0xc000000d;
  if ((((*param_1 == 0x4b00e9d55d3e9a59) && (param_1[1] == 0x486551ff34ffbda6)) &&
      ((int)param_3 == 4)) && (param_2 != (int *)0x0)) {
    iVar1 = *param_2;
    PdcAcquireLock();
    DAT_1400135e8 = iVar1 == 0;
    PdcReleaseLock();
    PdcpReplayLidClosePowerSourceUpdate(iVar1 == 0,param_2,param_3,puVar2);
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}



===== McGenControlCallbackV2 @ 140003d60 =====

void McGenControlCallbackV2
               (undefined8 *param_1,uint param_2,undefined1 param_3,undefined8 param_4,
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
        param_1 = *(undefined8 **)(param_7 + 0x30);
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(param_1,0,(longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
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
          param_1 = (undefined8 *)(uVar7 >> 5);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (longlong)param_1 * 4);
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
    PdcEtwCallback(param_1,(undefined **)(ulonglong)param_2);
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 140003e88 =====

void McGenEventRegister_EtwRegister(void)

{
  if (PDC_EVENT_PROVIDER_Context == 0) {
    EtwRegister(&PDC_EVENT_PROVIDER,McGenControlCallbackV2,&PDC_EVENT_PROVIDER_Context,
                &PDC_EVENT_PROVIDER_Context);
  }
  return;
}



===== McTemplateU0qNR0x_EtwWriteTransfer @ 140003ec8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qNR0x_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6)

{
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_30 = 0x80;
  local_48 = local_68;
  local_68[0] = 8;
  local_38 = param_5;
  local_28 = &param_6;
  local_20 = 8;
  local_40 = 4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_PHASE_ACCOUNTING,param_3,4,local_58);
  return;
}



===== McTemplateU0qdt_EtwWriteTransfer @ 140003f4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qdt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res18;
  local_38 = local_res20;
  local_40 = 4;
  local_28 = &param_5;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_GROUP_REQUEST,param_3,4,local_58);
  return;
}



===== McTemplateU0qtt_EtwWriteTransfer @ 140003fcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qtt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res18;
  local_38 = local_res20;
  local_40 = 4;
  local_28 = &param_5;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_GROUP_ENABLE,param_3,4,local_58);
  return;
}



===== McTemplateU0t_EtwWriteTransfer @ 14000404c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0t_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 local_res18 [4];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res18;
  local_1c = 0;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_SIDLE_UPDATE_NOTIFICATION,param_3,2,local_38);
  return;
}



===== McTemplateU0u_EtwWriteTransfer @ 1400040b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0u_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 local_res18 [16];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined1)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res18;
  local_1c = 0;
  local_20 = 1;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_TARGET_PHASE_REACHED,param_3,2,local_38);
  return;
}



===== McTemplateU0uddt_EtwWriteTransfer @ 140004114 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0uddt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined1 local_res18 [8];
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined1)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res18;
  local_50 = 1;
  local_48 = local_res20;
  local_40 = 4;
  local_38 = &param_5;
  local_28 = &param_6;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateU0udtuqqqq_EtwWriteTransfer @ 1400041a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0udtuqqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  undefined1 local_res18 [8];
  undefined4 local_res20 [2];
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined1 *local_98;
  undefined8 local_90;
  undefined4 *local_88;
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
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined1)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = local_res18;
  local_90 = 1;
  local_88 = local_res20;
  local_80 = 4;
  local_78 = &param_5;
  local_70 = 4;
  local_68 = &param_6;
  local_58 = &param_7;
  local_48 = &param_8;
  local_38 = &param_9;
  local_28 = &param_10;
  local_60 = 1;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_PHASE_RUNDOWN,param_3,9,local_a8);
  return;
}



===== McTemplateU0uqxxqxxx_EtwWriteTransfer @ 140004284 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0uqxxqxxx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  undefined1 local_res18 [8];
  undefined4 local_res20 [2];
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined1 *local_98;
  undefined8 local_90;
  undefined4 *local_88;
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
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined1)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = local_res18;
  local_90 = 1;
  local_88 = local_res20;
  local_80 = 4;
  local_78 = &param_5;
  local_70 = 8;
  local_68 = &param_6;
  local_58 = &param_7;
  local_48 = &param_8;
  local_38 = &param_9;
  local_28 = &param_10;
  local_60 = 8;
  local_50 = 4;
  local_40 = 8;
  local_30 = 8;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_PHASE_ACCOUNTING_RUNDOWN,param_3,9,local_a8);
  return;
}



===== McTemplateU0uuqqqq_EtwWriteTransfer @ 140004360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0uuqqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
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
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined1)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = local_res18;
  local_70 = 1;
  local_68 = local_res20;
  local_60 = 1;
  local_58 = &param_5;
  local_50 = 4;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = &param_8;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_PHASE_NOTIFICATION_CALLBACK,param_3,7,local_88);
  return;
}



===== McTemplateU0uuu_EtwWriteTransfer @ 14000441c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0uuu_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
               undefined1 param_5)

{
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined1)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res18;
  local_40 = 1;
  local_38 = local_res20;
  local_30 = 1;
  local_28 = &param_5;
  local_20 = 1;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== PdcDiagTracePhaseNotificationCallback @ 1400044a0 =====

void PdcDiagTracePhaseNotificationCallback
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
               undefined1 param_5,undefined1 param_6)

{
  if (Microsoft_Windows_PDCEnableBits < '\0') {
    McTemplateU0uuqqqq_EtwWriteTransfer
              (param_1,param_2,
               CONCAT44((int)((ulonglong)param_3 >> 0x20),
                        CONCAT31((int3)((ulonglong)param_3 >> 8),(char)param_1)),(char)param_2,
               (char)param_3,param_4,param_5,param_6);
  }
  return;
}



===== PdcDiagTraceSleepStudyBlocker @ 1400044e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcDiagTraceSleepStudyBlocker
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               undefined1 param_5)

{
  char cVar1;
  longlong lVar2;
  undefined8 local_res8;
  undefined1 auStack_d8 [32];
  undefined1 **local_b8;
  undefined1 local_a8 [4];
  int local_a4;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  int *local_78;
  undefined8 local_70;
  longlong local_68;
  int local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  local_a0 = 0;
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (*(short *)(param_4 + lVar2 * 2) != 0);
  local_a4 = (int)lVar2;
  local_60 = local_a4 * 2;
  local_48 = &param_5;
  local_38 = &local_res8;
  local_a8[0] = (undefined1)param_1;
  local_98 = local_a8;
  local_28 = &local_a0;
  local_78 = &local_a4;
  local_90 = 1;
  local_80 = 0x10;
  local_70 = 4;
  local_5c = 0;
  local_50 = 0x10;
  local_40 = 8;
  local_30 = 8;
  local_20 = 8;
  if (PdcDiagSleepStudyHandleRegistered != '\0') {
    local_res8 = param_1;
    local_88 = param_2;
    local_68 = param_4;
    local_58 = param_3;
    cVar1 = EtwEventEnabled(PdcDiagSleepStudyHandle,&SLEEPSTUDY_EVT_SCENARIO_BLOCKER);
    if (cVar1 != '\0') {
      local_b8 = &local_98;
      EtwWrite(PdcDiagSleepStudyHandle,&SLEEPSTUDY_EVT_SCENARIO_BLOCKER,0,8);
    }
  }
  return;
}



===== PdcpLogTaskClientAction @ 14000460c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcpLogTaskClientAction(char *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 auStackY_c8 [32];
  uint local_98 [2];
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_78 [4];
  char *local_58;
  int local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  uint local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar3 = 0;
  local_90 = 0;
  uStack_88 = 0;
  RtlInitUnicodeString(&local_90,L"");
  if (param_2 != 0) {
    uVar3 = *(uint *)(param_2 + 0x28);
    puVar1 = PdcGetClientInfo(uVar3);
    if (puVar1 != (undefined4 *)0x0) {
      RtlInitUnicodeString(&local_90,*(undefined8 *)(puVar1 + 4));
    }
  }
  if (5 < DAT_140031288) {
    if (param_1 == (char *)0x0) {
      param_1 = "";
      local_50 = 1;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_1[lVar2] != '\0');
      local_50 = (int)lVar2 + 1;
    }
    local_4c = 0;
    local_3c = 0;
    local_2c = 0;
    local_20[1] = 0;
    local_48 = local_98;
    local_38 = local_20;
    local_28 = uStack_88;
    local_20[0] = (uint)(ushort)local_90;
    local_40 = 4;
    local_30 = 2;
    local_98[0] = uVar3;
    local_58 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000f2c1,param_3,param_4,6,local_78);
  }
  return;
}



===== Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline @ 14000474c =====

ulonglong Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SpmAsyncEaCallout__private_featureState;
  if ((Feature_SpmAsyncEaCallout__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SpmAsyncEaCallout__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SpmAsyncEaCallout__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SpmAsyncEaCallout__private_IsEnabledFallback @ 140004784 =====

void Feature_SpmAsyncEaCallout__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_SpmAsyncEaCallout__private_descriptor);
  return;
}



===== McTemplateU0pjquqzr4j_EtwWriteTransfer @ 1400047a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pjquqzr4j_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6,int param_7,undefined8 param_8,
               undefined8 param_9)

{
  undefined8 local_res18 [2];
  undefined1 auStackY_d8 [32];
  undefined4 local_a8 [4];
  undefined8 local_98 [2];
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_88 = local_res18;
  local_a8[0] = 0;
  local_68 = local_a8;
  local_70 = 0x10;
  local_58 = &param_6;
  local_80 = 8;
  local_48 = &param_7;
  local_60 = 4;
  local_38 = param_8;
  local_30 = param_7 * 2;
  local_50 = 1;
  local_28 = param_9;
  local_40 = 4;
  local_2c = 0;
  local_20 = 0x10;
  local_res18[0] = param_3;
  local_78 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_SPM_SCENARIO_RUNDOWN,8,8,local_98);
  return;
}



===== McTemplateU0pqjqqzr4_EtwWriteTransfer @ 14000486c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pqjqqzr4_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined1 param_6,int param_7,undefined8 param_8)

{
  undefined8 local_res18;
  undefined4 local_res20 [2];
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined8 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_70 = 8;
  local_78 = &local_res18;
  local_1c = 0;
  local_68 = local_res20;
  local_58 = param_5;
  local_48 = &param_6;
  local_60 = 4;
  local_38 = &param_7;
  local_28 = param_8;
  local_20 = param_7 * 2;
  local_50 = 0x10;
  local_40 = 4;
  local_30 = 4;
  local_res18 = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_PPM_PROFILE_CLIENT_REGISTRATION,param_3,7,local_88);
  return;
}



===== McTemplateU0puu_EtwWriteTransfer @ 14000492c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0puu_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
               undefined1 param_5)

{
  undefined8 local_res18;
  undefined1 local_res20 [8];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res18;
  local_40 = 8;
  local_38 = local_res20;
  local_30 = 1;
  local_28 = &param_5;
  local_20 = 1;
  local_res18 = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_SPM_SCENARIO_STATE_CHANGE,param_3,4,local_58);
  return;
}



===== McTemplateU0pxxxx_EtwWriteTransfer @ 1400049b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0pxxxx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = &local_res18;
  local_60 = 8;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 8;
  local_20 = 8;
  local_res18 = param_3;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDC_SPM_SCENARIO_ACTIVITY_RUNDOWN,param_3,6,local_78);
  return;
}



===== PdcPpmMediaBufferingUpdate @ 140004a70 =====

void PdcPpmMediaBufferingUpdate(char param_1,undefined8 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  
  if (DAT_140012e88 != 0) {
    uVar1 = Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar1 == 0) {
      uVar2 = ~-(uint)(param_1 != '\0') & 3;
      if (uVar2 != DAT_140012e90) {
        PdcpPpmProcessScenarioStateChange(&PdcPpmMediaBufferingScenario,(ulonglong)uVar2);
      }
    }
    else {
      PdcAcquireRwLockExclusive(0x140012e98);
      DAT_140012eb2 = param_1;
      PdcpPpmProcessScenarioStateChangeV2(&PdcPpmMediaBufferingScenario,param_2);
      PdcReleaseRwLockExclusive(0x140012e98);
    }
  }
  return;
}



===== PdcpPpmProcessScenarioStateChangeV2 @ 140004ae4 =====

void PdcpPpmProcessScenarioStateChangeV2(undefined *param_1,undefined8 param_2)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  iVar7 = 1;
  iVar3 = *(int *)(param_1 + 0x30);
  if ((param_1[0x51] == '\0') || (param_1[0x52] == '\0')) {
    iVar6 = 3;
  }
  else {
    iVar6 = 0;
  }
  if (iVar3 != iVar6) {
    uVar5 = 0;
    lVar4 = KeQueryPerformanceCounter();
    if (iVar3 == 0) {
      uVar5 = lVar4 - *(longlong *)(param_1 + 200);
      *(ulonglong *)(param_1 + 0xe8) = *(longlong *)(param_1 + 0xe8) + uVar5;
      *(longlong *)(param_1 + 0xd0) = *(longlong *)(param_1 + 0xd0) + 1;
      if (*(ulonglong *)(param_1 + 0xd8) < uVar5) {
        *(ulonglong *)(param_1 + 0xd8) = uVar5;
      }
      if (uVar5 < *(ulonglong *)(param_1 + 0xe0)) {
        *(ulonglong *)(param_1 + 0xe0) = uVar5;
      }
    }
    *(longlong *)(param_1 + 200) = lVar4;
    *(int *)(param_1 + 0x30) = iVar6;
    if ((DAT_140015c02 & 2) != 0) {
      McTemplateU0puu_EtwWriteTransfer(uVar5,param_2,param_1,(char)iVar3,(char)iVar6);
    }
    if (iVar6 == 0) {
      LOCK();
      piVar1 = (int *)(lVar2 + 0x40);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      iVar3 = iVar3 + 1;
    }
    else {
      LOCK();
      piVar1 = (int *)(lVar2 + 0x40);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 == 1) {
      LOCK();
      iVar3 = PdcPpmEvaulationRequestCount + 1;
      UNLOCK();
      bVar8 = PdcPpmEvaulationRequestCount == 0;
      PdcPpmEvaulationRequestCount = iVar3;
      if (bVar8) {
        if (param_1 == &PdcPpmMediaBufferingScenario) {
          iVar3 = KeQueryPriorityThread(SystemReserved1[0xf]);
          iVar7 = iVar3 + 1;
          if (0x1e < iVar3) {
            iVar7 = iVar3;
          }
          iVar7 = iVar7 + 0x20;
        }
        ExQueueWorkItem(&PdcPpmProfileEvaluationWorkItem,iVar7);
      }
    }
  }
  return;
}



===== McTemplateU0uqqjjqzr5x_EtwWriteTransfer @ 140004c28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0uqqjjqzr5x_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined8 param_6,undefined8 param_7,int param_8,
               undefined8 param_9,undefined1 param_10)

{
  undefined1 local_res18 [8];
  undefined4 local_res20 [2];
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined1 *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_res18[0] = (undefined1)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_90 = 1;
  local_98 = local_res18;
  local_2c = 0;
  local_88 = local_res20;
  local_80 = 4;
  local_78 = &param_5;
  local_68 = param_6;
  local_58 = param_7;
  local_48 = &param_8;
  local_38 = param_9;
  local_30 = param_8 * 2;
  local_70 = 4;
  local_28 = &param_10;
  local_60 = 0x10;
  local_50 = 0x10;
  local_40 = 4;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,9,local_a8);
  return;
}



===== PdcHandleSignalQueue @ 140004d04 =====

void PdcHandleSignalQueue
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  bool bVar3;
  undefined8 *puVar4;
  
  do {
    PdcAcquireRwLockExclusive(0x140012e20);
    puVar4 = PdcSignalEventQueue;
    if ((undefined8 **)PdcSignalEventQueue == &PdcSignalEventQueue) {
      bVar3 = true;
      puVar4 = (undefined8 *)0x0;
    }
    else {
      bVar3 = false;
      if (((undefined8 **)PdcSignalEventQueue[1] != &PdcSignalEventQueue) ||
         (puVar1 = (undefined8 *)*PdcSignalEventQueue,
         (undefined8 *)puVar1[1] != PdcSignalEventQueue)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      PdcSignalEventQueue = puVar1;
      puVar1[1] = &PdcSignalEventQueue;
    }
    PdcReleaseRwLockExclusive(0x140012e20);
    if (puVar4 != (undefined8 *)0x0) {
      PdcPolicyClientDeliverEvent((uint *)(puVar4 + 4),param_2,param_3,param_4);
      if (*(char *)(puVar4 + 3) != '\0') {
        PdcAcquireLock();
        PdcpSignalClientCompleteRemove((longlong *)puVar4[2]);
        PdcReleaseLock();
      }
      PdcFree(puVar4);
    }
  } while (!bVar3);
  return;
}



===== PdcFreeActivationStats @ 140004db4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcFreeActivationStats(longlong *param_1)

{
  if (((param_1[1] != 0) && (param_1[1] != *(longlong *)(*param_1 + 0x48))) &&
     (DAT_140012868 != (code *)0x0)) {
    (*DAT_140012868)();
  }
  param_1[1] = 0;
  return;
}



===== Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline @ 140004df4 =====

ulonglong Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_LocklessPhasesPoCallout__private_featureState;
  if ((Feature_LocklessPhasesPoCallout__private_featureState & 0x10) == 0) {
    uVar1 = Feature_LocklessPhasesPoCallout__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_LocklessPhasesPoCallout__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_LocklessPhasesPoCallout__private_IsEnabledFallback @ 140004e2c =====

void Feature_LocklessPhasesPoCallout__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_LocklessPhasesPoCallout__private_descriptor);
  return;
}



===== PdcPhaseGetNotificationEntryWatchdogTimeout @ 140004e48 =====

undefined4 PdcPhaseGetNotificationEntryWatchdogTimeout(int param_1)

{
  return (&DAT_140031308)[(longlong)param_1 * 0x56];
}



===== PdcPhasesAcknowledgePoCallback @ 140004e64 =====

void PdcPhasesAcknowledgePoCallback(int param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = (longlong)DAT_14003100c * 0x158;
  if (*(int *)(&DAT_1400312dc + lVar2) != param_1) {
    return;
  }
  if (*(int *)(&DAT_1400312d8 + lVar2) == 3) {
    iVar1 = 1;
  }
  else {
    if (*(int *)(&DAT_1400312d8 + lVar2) != 2) goto LAB_140004ea6;
    iVar1 = 0;
  }
  PdcpSetPhasePoCallbackState((longlong)(&PdcPhasesEx + lVar2),iVar1,0);
LAB_140004ea6:
  PdcGetPolicyWorker(0x10);
  PdcCheckForWork();
  return;
}



===== PdcPhasesResetScenarioAccounting @ 140004ec4 =====

void PdcPhasesResetScenarioAccounting(char param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_1400313c0;
  lVar2 = 9;
  do {
    if (param_1 == '\0') {
      *puVar1 = 0;
    }
    else {
      puVar1[-1] = 0;
    }
    puVar1 = puVar1 + 0x2b;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== PdcpResiliencyRequestCompletionCallback @ 140004f00 =====

void PdcpResiliencyRequestCompletionCallback(void)

{
  PdcpPhaseNotificationCallback(0,0,0);
  return;
}



===== PdcGroupsSnapDiagnosticContext @ 140004f1c =====

void PdcGroupsSnapDiagnosticContext(undefined8 *param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  bool bVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  uint uVar9;
  int *piVar10;
  
  *param_1 = 0;
  *param_2 = 0;
  uVar9 = 0;
  piVar10 = &PdcRequestGroups;
  do {
    if (((uVar9 < 6) && (piVar10 != (int *)0x0)) && (*piVar10 == 0)) {
      bVar4 = PdcpIsGroupBlockingPhases(piVar10);
      if (bVar4) {
        *param_2 = *param_2 | 1 << ((byte)uVar9 & 0x1f);
      }
    }
    uVar9 = uVar9 + 1;
    piVar10 = piVar10 + 0x28;
  } while ((int)uVar9 < 6);
  puVar5 = (undefined8 *)PdcAllocate('\x01');
  if (puVar5 != (undefined8 *)0x0) {
    lVar7 = 7;
    puVar2 = puVar5;
    puVar3 = (undefined8 *)&PdcRequestGroups;
    do {
      puVar8 = puVar3;
      puVar6 = puVar2;
      uVar1 = puVar8[1];
      *puVar6 = *puVar8;
      puVar6[1] = uVar1;
      uVar1 = puVar8[3];
      puVar6[2] = puVar8[2];
      puVar6[3] = uVar1;
      uVar1 = puVar8[5];
      puVar6[4] = puVar8[4];
      puVar6[5] = uVar1;
      uVar1 = puVar8[7];
      puVar6[6] = puVar8[6];
      puVar6[7] = uVar1;
      uVar1 = puVar8[9];
      puVar6[8] = puVar8[8];
      puVar6[9] = uVar1;
      uVar1 = puVar8[0xb];
      puVar6[10] = puVar8[10];
      puVar6[0xb] = uVar1;
      uVar1 = puVar8[0xd];
      puVar6[0xc] = puVar8[0xc];
      puVar6[0xd] = uVar1;
      uVar1 = puVar8[0xf];
      puVar6[0xe] = puVar8[0xe];
      puVar6[0xf] = uVar1;
      lVar7 = lVar7 + -1;
      puVar2 = puVar6 + 0x10;
      puVar3 = puVar8 + 0x10;
    } while (lVar7 != 0);
    uVar1 = puVar8[0x11];
    puVar6[0x10] = puVar8[0x10];
    puVar6[0x11] = uVar1;
    uVar1 = puVar8[0x13];
    puVar6[0x12] = puVar8[0x12];
    puVar6[0x13] = uVar1;
    uVar1 = puVar8[0x15];
    puVar6[0x14] = puVar8[0x14];
    puVar6[0x15] = uVar1;
    uVar1 = puVar8[0x17];
    puVar6[0x16] = puVar8[0x16];
    puVar6[0x17] = uVar1;
    *param_1 = puVar5;
  }
  return;
}



===== PdcpGetGroup @ 140005024 =====

undefined4 * PdcpGetGroup(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x0;
  if (param_1 < 6) {
    puVar1 = &PdcRequestGroups + (longlong)(int)param_1 * 0x28;
  }
  return puVar1;
}



===== PdcpSleepstudyHelperDecodeHandle @ 140005048 =====

undefined8 * PdcpSleepstudyHelperDecodeHandle(longlong param_1,int param_2,longlong param_3)

{
  undefined8 *puVar1;
  
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  puVar1 = *(undefined8 **)(param_1 + 0x50);
  while( true ) {
    if (puVar1 == (undefined8 *)(param_1 + 0x50)) {
      return (undefined8 *)0x0;
    }
    if ((*(int *)(puVar1 + 2) == param_2) && (puVar1[4] == param_3)) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1;
}



===== PdcpSleepstudyHelperProcessUserMessage @ 1400050a4 =====

uint PdcpSleepstudyHelperProcessUserMessage(longlong param_1,undefined8 *param_2,undefined8 param_3)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined7 uVar4;
  
  uVar4 = (undefined7)((ulonglong)param_3 >> 8);
  if ((*(int *)(param_2 + 5) != 0xf) || (*(int *)(param_1 + 0x10) != 8)) {
    return 0xc000000d;
  }
  uVar2 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    PdcAcquireRwLockExclusive(param_1 + 0x30);
  }
  iVar3 = *(int *)(param_2 + 7);
  if (iVar3 < 6) {
    if ((iVar3 != 5) && (iVar3 != 0)) {
      iVar3 = iVar3 + -1;
      goto LAB_1400050f3;
    }
  }
  else {
    iVar3 = iVar3 + -6;
LAB_1400050f3:
    if ((((iVar3 != 0) && (iVar3 != 1)) && (iVar3 != 2)) && (iVar3 != 3)) {
      uVar1 = 0xc000000d;
      goto LAB_140005119;
    }
  }
  uVar1 = PdcpSleepstudyHelperProcessMessage(param_1,(int *)(param_2 + 7));
LAB_140005119:
  uVar2 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    PdcReleaseRwLockExclusive(param_1 + 0x30);
  }
  *(uint *)((longlong)param_2 + 0x3c) = uVar1;
  if (-1 < (int)uVar1) {
    PdcSendUserMessage(*(longlong *)(param_1 + 0x20),param_2,CONCAT71(uVar4,1));
  }
  return uVar1;
}



===== PoArmStopWatchCollection @ 140005168 =====

undefined1 PoArmStopWatchCollection(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  
  uVar2 = 0;
  if (param_1[2] == 0) {
    uVar2 = 1;
    uVar1 = PdcGetInterruptTime();
    puVar3 = (undefined8 *)*param_1;
    param_1[2] = uVar1;
    for (; puVar3 != param_1; puVar3 = (undefined8 *)*puVar3) {
      PopInternalUpdateStopWatchState(puVar3 + -1);
    }
    PopInternalUpdateActiveStopWatchesCollectionState((longlong)param_1);
  }
  return uVar2;
}



===== PoInitializeStopWatch @ 1400051c8 =====

void PoInitializeStopWatch(undefined8 *param_1,longlong *param_2)

{
  code *pcVar1;
  longlong lVar2;
  longlong *plVar3;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = param_2;
  plVar3 = param_1 + 1;
  lVar2 = *param_2;
  if (*(longlong **)(lVar2 + 8) != param_2) {
    plVar3 = (longlong *)0x3;
    pcVar1 = (code *)swi(0x29);
    lVar2 = (*pcVar1)();
  }
  *plVar3 = lVar2;
  plVar3[1] = (longlong)param_2;
  *(longlong **)(lVar2 + 8) = plVar3;
  *param_2 = (longlong)plVar3;
  return;
}



===== PoInitializeStopWatchCollection @ 140005204 =====

void PoInitializeStopWatchCollection(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[1] = param_1;
  *param_1 = param_1;
  return;
}



===== PoIsArmedStopWatchCollection @ 140005228 =====

bool PoIsArmedStopWatchCollection(longlong param_1)

{
  return *(longlong *)(param_1 + 0x10) != 0;
}



===== PoPauseStopWatch @ 140005238 =====

void PoPauseStopWatch(longlong *param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  
  LOCK();
  plVar1 = param_1 + 5;
  lVar4 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  if ((int)lVar4 == 1) {
    PopInternalUpdateStopWatchState(param_1);
    lVar4 = *param_1;
    LOCK();
    piVar2 = (int *)(lVar4 + 0x30);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      PopInternalUpdateActiveStopWatchesCollectionState(lVar4);
    }
  }
  return;
}



===== PoQueryStopWatch @ 140005278 =====

undefined8 PoQueryStopWatch(longlong *param_1,ulonglong *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  uVar3 = 0;
  if (*param_1 == 0) {
    uVar3 = 0xc00000b7;
  }
  else if ((param_2 != (ulonglong *)0x0) && (*param_2 = param_1[4], param_1[3] != 0)) {
    lVar1 = PdcGetInterruptTime();
    uVar4 = (*param_2 - param_1[3]) + lVar1;
    uVar2 = 0xffffffffffffffff;
    if (*param_2 <= uVar4) {
      uVar2 = uVar4;
    }
    *param_2 = uVar2;
  }
  return uVar3;
}



===== PoResetStopWatch @ 1400052e8 =====

void PoResetStopWatch(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  LOCK();
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x2c);
  UNLOCK();
  return;
}



===== PoResetStopWatchCollection @ 140005304 =====

void PoResetStopWatchCollection(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  return;
}



===== PoStartStopWatch @ 140005320 =====

void PoStartStopWatch(longlong *param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  
  LOCK();
  plVar1 = param_1 + 5;
  lVar4 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + 1;
  UNLOCK();
  LOCK();
  *(int *)((longlong)param_1 + 0x2c) = *(int *)((longlong)param_1 + 0x2c) + 1;
  UNLOCK();
  if ((int)lVar4 == 0) {
    PopInternalUpdateStopWatchState(param_1);
    lVar4 = *param_1;
    LOCK();
    piVar2 = (int *)(lVar4 + 0x30);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + 1;
    UNLOCK();
    if (iVar3 == 0) {
      PopInternalUpdateActiveStopWatchesCollectionState(lVar4);
    }
  }
  return;
}



===== PoUnarmStopWatchCollection @ 14000536c =====

undefined1 PoUnarmStopWatchCollection(undefined8 *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  
  if (param_1[2] == 0) {
    uVar4 = 0;
  }
  else {
    uVar1 = param_1[3];
    uVar4 = 1;
    lVar2 = PdcGetInterruptTime();
    param_1[3] = param_1[3] + (lVar2 - param_1[2]);
    if ((ulonglong)param_1[3] < uVar1) {
      param_1[3] = 0xffffffffffffffff;
    }
    param_1[2] = 0;
    for (puVar3 = (undefined8 *)*param_1; puVar3 != param_1; puVar3 = (undefined8 *)*puVar3) {
      PopInternalUpdateStopWatchState(puVar3 + -1);
    }
    PopInternalUpdateActiveStopWatchesCollectionState((longlong)param_1);
  }
  return uVar4;
}



===== PopInternalUpdateActiveStopWatchesCollectionState @ 1400053e8 =====

void PopInternalUpdateActiveStopWatchesCollectionState(longlong param_1)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  bool bVar6;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x30);
  iVar2 = *piVar1;
  *piVar1 = *piVar1;
  UNLOCK();
  if ((iVar2 < 1) || (*(longlong *)(param_1 + 0x10) == 0)) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  if (bVar6 != (*(longlong *)(param_1 + 0x20) != 0)) {
    if (bVar6 == false) {
      uVar3 = *(ulonglong *)(param_1 + 0x28);
      lVar5 = PdcGetInterruptTime();
      *(longlong *)(param_1 + 0x28) =
           *(longlong *)(param_1 + 0x28) + (lVar5 - *(longlong *)(param_1 + 0x20));
      if (*(ulonglong *)(param_1 + 0x28) < uVar3) {
        *(undefined8 *)(param_1 + 0x28) = 0xffffffffffffffff;
      }
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    else {
      uVar4 = PdcGetInterruptTime();
      *(undefined8 *)(param_1 + 0x20) = uVar4;
    }
  }
  return;
}



===== PopInternalUpdateStopWatchState @ 14000545c =====

void PopInternalUpdateStopWatchState(longlong *param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong lVar3;
  bool bVar4;
  
  LOCK();
  plVar1 = param_1 + 5;
  lVar3 = *plVar1;
  *(int *)plVar1 = (int)*plVar1;
  UNLOCK();
  if (((int)lVar3 < 1) || (*(longlong *)(*param_1 + 0x10) == 0)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (bVar4 != (param_1[3] != 0)) {
    if (bVar4 == false) {
      uVar2 = param_1[4];
      lVar3 = PdcGetInterruptTime();
      param_1[4] = param_1[4] + (lVar3 - param_1[3]);
      if ((ulonglong)param_1[4] < uVar2) {
        param_1[4] = -1;
      }
      param_1[3] = 0;
    }
    else {
      lVar3 = PdcGetInterruptTime();
      param_1[3] = lVar3;
    }
  }
  return;
}



===== PdcPrint @ 1400054d4 =====

void PdcPrint(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintEx(0x92,param_1,param_2,&local_res18);
  return;
}



===== PdcTimerCallback @ 140005510 =====

void PdcTimerCallback(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = KeQueryUnbiasedInterruptTime();
  *(undefined8 *)(param_2 + 0xb0) = uVar1;
  ExQueueWorkItem(param_2 + 0x88,*(undefined4 *)(param_2 + 0xa8));
  return;
}



===== PdcPortSendMessageSynchronously @ 140005554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PdcPortSendMessageSynchronously(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = ExAcquireRundownProtection(param_1 + 8);
  if (cVar1 == '\0') {
    uVar2 = 0xc0000189;
  }
  else {
    *(undefined4 *)(param_2 + 0x2c) = 6;
    uVar2 = (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x18),param_2,800);
    ExReleaseRundownProtection(param_1 + 8);
  }
  return uVar2;
}



===== McTemplateU0qqqqzr3_EtwWriteTransfer @ 1400055d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqqqzr3_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,int param_6,undefined8 param_7)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_88[0] = 1;
  local_68 = local_res18;
  local_1c = 0;
  local_58 = local_res20;
  local_48 = local_88;
  local_38 = &param_6;
  local_60 = 4;
  local_28 = param_7;
  local_20 = param_6 * 2;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDCV2_ACTIVATION_REGISTER,param_3,6,local_78);
  return;
}



===== McTemplateU0qqzr1qzr3qqqqpqqzr11_EtwWriteTransfer @ 140005688 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqzr1qzr3qqqqpqqzr11_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4,
               undefined8 param_5,int param_6,undefined8 param_7,undefined1 param_8,
               undefined8 param_9,undefined8 param_10,undefined1 param_11,undefined1 param_12,
               undefined8 param_13,int param_14,undefined8 param_15)

{
  undefined4 local_res18 [2];
  int local_res20 [2];
  undefined1 auStackY_148 [32];
  undefined4 local_118 [2];
  undefined4 local_110 [2];
  undefined4 local_108 [4];
  undefined8 local_f8 [2];
  undefined4 *local_e8;
  undefined8 local_e0;
  int *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  int local_c0;
  undefined4 local_bc;
  int *local_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  int local_a0;
  undefined4 local_9c;
  undefined1 *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_res18[0] = (undefined4)param_3;
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  local_108[0] = 1;
  local_110[0] = 0xffffffff;
  local_118[0] = 0xffffffff;
  local_e8 = local_res18;
  local_d8 = local_res20;
  local_c8 = param_5;
  local_c0 = param_4 * 2;
  local_b8 = &param_6;
  local_bc = 0;
  local_a8 = L"V1_Unknown";
  local_a0 = param_6 * 2;
  local_9c = 0;
  local_98 = &param_8;
  local_88 = local_118;
  local_78 = local_110;
  local_68 = &param_11;
  local_58 = &param_12;
  local_48 = local_108;
  local_38 = &param_14;
  local_28 = param_15;
  local_20 = param_14 * 2;
  local_1c = 0;
  local_e0 = 4;
  local_d0 = 4;
  local_b0 = 4;
  local_90 = 4;
  local_80 = 4;
  local_70 = 4;
  local_60 = 4;
  local_50 = 8;
  local_40 = 4;
  local_30 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDCV2_ACTIVATION_ACTIVATE,param_3,0xe,local_f8);
  return;
}



===== McTemplateU0qqzr1qzr3qqqxqpqqqzr13q_EtwWriteTransfer @ 1400057ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqzr1qzr3qqqxqpqqqzr13q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,int param_4,
               undefined8 param_5,int param_6,undefined8 param_7,undefined1 param_8,
               undefined1 param_9,undefined8 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined8 param_14,undefined8 param_15,int param_16,
               undefined8 param_17)

{
  undefined4 local_res18 [2];
  int local_res20 [2];
  undefined1 auStackY_178 [32];
  undefined4 local_148 [2];
  undefined4 local_140 [2];
  undefined4 local_138 [2];
  undefined4 local_130 [2];
  undefined8 local_128 [2];
  undefined4 *local_118;
  undefined8 local_110;
  int *local_108;
  undefined8 local_100;
  undefined8 local_f8;
  int local_f0;
  undefined4 local_ec;
  int *local_e8;
  undefined8 local_e0;
  wchar_t *local_d8;
  int local_d0;
  undefined4 local_cc;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_178;
  local_138[0] = 1;
  local_140[0] = 0xffffffff;
  local_148[0] = 0xffffffff;
  local_118 = local_res18;
  local_130[0] = 0;
  local_108 = local_res20;
  local_f8 = param_5;
  local_f0 = param_4 * 2;
  local_e8 = &param_6;
  local_110 = 4;
  local_d8 = L"V1_Unknown";
  local_d0 = param_6 * 2;
  local_100 = 4;
  local_c8 = &param_8;
  local_b8 = &param_9;
  local_a8 = local_148;
  local_98 = &param_11;
  local_88 = &param_12;
  local_78 = &param_13;
  local_68 = local_140;
  local_58 = local_138;
  local_48 = &param_16;
  local_38 = param_17;
  local_30 = param_16 * 2;
  local_ec = 0;
  local_28 = local_130;
  local_e0 = 4;
  local_cc = 0;
  local_c0 = 4;
  local_b0 = 4;
  local_a0 = 4;
  local_90 = 8;
  local_80 = 4;
  local_70 = 8;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_2c = 0;
  local_20 = 4;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDCV2_ACTIVATION_CALLBACK,0,0x11,local_128);
  return;
}



===== McTemplateU0qqzr1qzr3qqxqpqqzr11q_EtwWriteTransfer @ 1400059a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateU0qqzr1qzr3qqxqpqqzr11q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,int param_4,
               undefined8 param_5,int param_6,undefined8 param_7,undefined1 param_8,
               undefined8 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined8 param_13,int param_14,undefined8 param_15)

{
  undefined4 local_res18 [2];
  int local_res20 [2];
  undefined1 auStackY_158 [32];
  undefined4 local_128 [2];
  undefined4 local_120 [2];
  undefined4 local_118 [4];
  undefined8 local_108 [2];
  undefined4 *local_f8;
  undefined8 local_f0;
  int *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  int local_d0;
  undefined4 local_cc;
  int *local_c8;
  undefined8 local_c0;
  wchar_t *local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_158;
  local_128[0] = 0xffffffff;
  local_f8 = local_res18;
  local_120[0] = 1;
  local_e8 = local_res20;
  local_118[0] = 0;
  local_d8 = param_5;
  local_d0 = param_4 * 2;
  local_c8 = &param_6;
  local_f0 = 4;
  local_b8 = L"V1_Unknown";
  local_b0 = param_6 * 2;
  local_e0 = 4;
  local_a8 = &param_8;
  local_98 = local_128;
  local_88 = &param_10;
  local_78 = &param_11;
  local_68 = &param_12;
  local_58 = local_120;
  local_48 = &param_14;
  local_38 = param_15;
  local_30 = param_14 * 2;
  local_cc = 0;
  local_28 = local_118;
  local_c0 = 4;
  local_ac = 0;
  local_a0 = 4;
  local_90 = 4;
  local_80 = 8;
  local_70 = 4;
  local_60 = 8;
  local_50 = 4;
  local_40 = 4;
  local_2c = 0;
  local_20 = 4;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PDCV2_ACTIVATION_DEACTIVATE,0,0xf,local_108);
  return;
}



===== PdcInitializeETW @ 140005b24 =====

void PdcInitializeETW(void)

{
  int iVar1;
  bool bVar2;
  
  LOCK();
  iVar1 = g_RegistrationCount + 1;
  UNLOCK();
  bVar2 = g_RegistrationCount == 0;
  g_RegistrationCount = iVar1;
  if (bVar2) {
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x140012560);
  }
  return;
}



===== PdcpFormatTaskName @ 140005b54 =====

void PdcpFormatTaskName(uint param_1,undefined4 *param_2)

{
  short sVar1;
  uint uVar2;
  short sVar3;
  
  *param_2 = 0x310056;
  *(undefined2 *)(param_2 + 3) = 0;
  *(undefined2 *)(param_2 + 1) = 0x5f;
  sVar3 = (short)(param_1 / 10);
  uVar2 = (param_1 / 10) / 10;
  sVar1 = (short)uVar2;
  *(short *)((longlong)param_2 + 10) = (short)param_1 + sVar3 * -10 + 0x30;
  *(short *)((longlong)param_2 + 6) = sVar1 + (short)((ulonglong)uVar2 / 10) * -10 + 0x30;
  *(short *)(param_2 + 2) = sVar3 + sVar1 * -10 + 0x30;
  return;
}



===== Pdcv1EventWrite_ACTIVATION_CLIENT_ACTIVATE @ 140005bf4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Pdcv1EventWrite_ACTIVATION_CLIENT_ACTIVATE(longlong param_1,undefined1 param_2)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStackY_b8 [32];
  undefined8 in_stack_ffffffffffffff78;
  undefined8 in_stack_ffffffffffffff88;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffa8;
  short local_38 [8];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar3 = 0xff;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  pwVar2 = L"";
  uVar4 = 0xffffffff;
  if (param_1 != 0) {
    uVar4 = *(uint *)(param_1 + 0x20);
    uVar3 = (undefined1)*(undefined4 *)(param_1 + 200);
    PdcpFormatTaskName(uVar4,(undefined4 *)local_38);
    pwVar2 = (wchar_t *)(param_1 + 0x46);
  }
  if ((DAT_140015c02 & 0x40) != 0) {
    lVar5 = -1;
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (pwVar2[lVar1] != L'\0');
    do {
      lVar5 = lVar5 + 1;
    } while (local_38[lVar5] != 0);
    McTemplateU0qqzr1qzr3qqqqpqqzr11_EtwWriteTransfer
              (pwVar2,local_38,(ulonglong)uVar4,(int)lVar5,local_38,10,in_stack_ffffffffffffff78,
               uVar3,in_stack_ffffffffffffff88,in_stack_ffffffffffffff90,param_2,(char)param_1,
               in_stack_ffffffffffffffa8,(int)lVar1,pwVar2);
  }
  return;
}



===== Pdcv1EventWrite_ACTIVATION_CLIENT_CALLBACK @ 140005cec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pdcv1EventWrite_ACTIVATION_CLIENT_CALLBACK
               (longlong param_1,int param_2,ulonglong param_3,longlong param_4)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong lVar7;
  int iVar8;
  undefined1 auStackY_1e8 [32];
  undefined8 in_stack_fffffffffffffe48;
  undefined8 in_stack_fffffffffffffe60;
  undefined8 in_stack_fffffffffffffe80;
  undefined8 in_stack_fffffffffffffe88;
  uint local_158;
  uint local_154;
  uint local_150;
  int local_14c [5];
  longlong local_138;
  longlong local_130;
  undefined8 local_128 [4];
  uint *local_108;
  undefined8 local_100;
  short *local_f8;
  int local_f0;
  undefined4 local_ec;
  wchar_t *local_e8;
  undefined8 local_e0;
  int *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  int *local_b8;
  undefined8 local_b0;
  int *local_a8;
  undefined8 local_a0;
  longlong *local_98;
  undefined8 local_90;
  longlong *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  short local_48 [8];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_154 = (uint)param_3;
  local_158 = 0xffffffff;
  lVar4 = -1;
  local_58 = L"";
  uVar3 = 0xffffffff;
  uVar6 = 0xffffffff;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  lVar7 = -1;
  local_48[6] = 0;
  if (param_1 != 0) {
    local_158 = *(uint *)(param_1 + 200);
    uVar6 = *(uint *)(param_1 + 0x20);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = _DAT_fffff78000000320 << 8;
    lVar7 = SUB168(auVar1 * (ZEXT416(_DAT_fffff78000000004) << 0x20),8) -
            *(longlong *)(param_1 + 0xd0);
    PdcpFormatTaskName(uVar6,(undefined4 *)local_48);
    uVar3 = (ulonglong)local_158;
    local_58 = (wchar_t *)(param_1 + 0x46);
    param_3 = (ulonglong)local_154;
  }
  iVar8 = 0x65;
  if (param_2 != 0) {
    iVar8 = param_2;
  }
  uVar5 = param_3;
  if ((DAT_140015c02 & 0x40) != 0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_58[lVar2] != L'\0');
    param_4 = -1;
    do {
      param_4 = param_4 + 1;
    } while (local_48[param_4] != 0);
    uVar5 = (ulonglong)uVar6;
    McTemplateU0qqzr1qzr3qqqxqpqqqzr13q_EtwWriteTransfer
              (uVar3,0,uVar6,(int)param_4,local_48,10,in_stack_fffffffffffffe48,(char)iVar8,
               (char)uVar3,in_stack_fffffffffffffe60,(char)lVar7,(char)param_3,(char)param_1,
               in_stack_fffffffffffffe80,in_stack_fffffffffffffe88,(int)lVar2,local_58);
  }
  if (5 < DAT_140012560) {
    local_108 = &local_150;
    lVar2 = -1;
    local_100 = 4;
    do {
      lVar2 = lVar2 + 1;
    } while (local_48[lVar2] != 0);
    local_f0 = (int)lVar2 * 2 + 2;
    local_ec = 0;
    local_f8 = local_48;
    local_e8 = L"V1_Unknown";
    local_e0 = 0x16;
    local_d8 = local_14c;
    local_c8 = &local_158;
    local_b8 = local_14c + 1;
    local_a8 = local_14c + 2;
    local_98 = &local_138;
    local_88 = &local_130;
    local_78 = &local_154;
    local_68 = local_14c + 3;
    local_d0 = 4;
    local_c0 = 4;
    local_14c[1] = 0xffffffff;
    local_b0 = 4;
    local_14c[2] = 0xffffffff;
    local_a0 = 4;
    local_90 = 8;
    local_80 = 8;
    local_70 = 4;
    local_14c[3] = 1;
    local_60 = 4;
    if (local_58 == (wchar_t *)0x0) {
      local_58 = L"";
      local_50 = 2;
    }
    else {
      do {
        lVar4 = lVar4 + 1;
      } while (local_58[lVar4] != L'\0');
      local_50 = (int)lVar4 * 2 + 2;
    }
    local_4c = 0;
    local_150 = uVar6;
    local_14c[0] = iVar8;
    local_138 = lVar7;
    local_130 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x140012560,&DAT_14000f4c7,uVar5,param_4,0xe,local_128);
  }
  return;
}



===== Pdcv1EventWrite_ACTIVATION_CLIENT_DEACTIVATE @ 140005fcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pdcv1EventWrite_ACTIVATION_CLIENT_DEACTIVATE
               (longlong param_1,undefined4 param_2,ulonglong param_3,longlong param_4)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 auStackY_1b8 [32];
  undefined8 in_stack_fffffffffffffe78;
  undefined8 in_stack_fffffffffffffe88;
  undefined8 in_stack_fffffffffffffea8;
  uint local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128 [2];
  ulonglong local_120;
  longlong local_118 [2];
  undefined8 local_108 [4];
  uint *local_e8;
  undefined8 local_e0;
  short *local_d8;
  int local_d0;
  undefined4 local_cc;
  wchar_t *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  ulonglong *local_98;
  undefined8 local_90;
  longlong *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  short local_48 [8];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_58 = L"";
  uVar4 = 0xffffffff;
  uVar6 = 0xffffffff;
  uVar5 = 0xffffffff;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  if (param_1 != 0) {
    uVar6 = *(uint *)(param_1 + 0x20);
    uVar4 = *(undefined4 *)(param_1 + 200);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = _DAT_fffff78000000320 << 8;
    uVar5 = SUB168(auVar1 * (ZEXT416(_DAT_fffff78000000004) << 0x20),8) -
            *(longlong *)(param_1 + 0xd0);
    PdcpFormatTaskName(uVar6,(undefined4 *)local_48);
    local_58 = (wchar_t *)(param_1 + 0x46);
  }
  lVar3 = -1;
  if ((DAT_140015c02 & 0x40) != 0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_58[lVar2] != L'\0');
    param_4 = -1;
    do {
      param_4 = param_4 + 1;
    } while (local_48[param_4] != 0);
    param_3 = (ulonglong)uVar6;
    McTemplateU0qqzr1qzr3qqxqpqqzr11q_EtwWriteTransfer
              (0,local_48,uVar6,(int)param_4,local_48,10,in_stack_fffffffffffffe78,(char)uVar4,
               in_stack_fffffffffffffe88,(char)uVar5,(char)param_2,(char)param_1,
               in_stack_fffffffffffffea8,(int)lVar2,local_58);
  }
  if ((999 < uVar5) && (5 < DAT_140012560)) {
    local_e8 = &local_138;
    lVar2 = -1;
    local_e0 = 4;
    do {
      lVar2 = lVar2 + 1;
    } while (local_48[lVar2] != 0);
    local_cc = 0;
    local_d0 = (int)lVar2 * 2 + 2;
    local_c8 = L"V1_Unknown";
    local_b8 = &local_134;
    local_130 = 0xffffffff;
    local_a8 = &local_130;
    local_98 = &local_120;
    local_88 = local_118;
    local_78 = &local_12c;
    local_68 = local_128;
    local_d8 = local_48;
    local_c0 = 0x16;
    local_b0 = 4;
    local_a0 = 4;
    local_90 = 8;
    local_80 = 8;
    local_70 = 4;
    local_128[0] = 1;
    local_60 = 4;
    if (local_58 == (wchar_t *)0x0) {
      local_58 = L"";
      local_50 = 2;
    }
    else {
      do {
        lVar3 = lVar3 + 1;
      } while (local_58[lVar3] != L'\0');
      local_50 = (int)lVar3 * 2 + 2;
    }
    local_4c = 0;
    local_138 = uVar6;
    local_134 = uVar4;
    local_12c = param_2;
    local_120 = uVar5;
    local_118[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x140012560,&DAT_14000f420,param_3,param_4,0xc,local_108);
  }
  return;
}



===== Pdcv1EventWrite_ACTIVATION_CLIENT_REGISTER @ 14000624c =====

void Pdcv1EventWrite_ACTIVATION_CLIENT_REGISTER(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  wchar_t *pwVar2;
  uint uVar3;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar3 = 0xffffffff;
  pwVar2 = L"";
  if (param_1 != 0) {
    uVar3 = *(uint *)(param_1 + 0x20);
    pwVar2 = (wchar_t *)(param_1 + 0x46);
  }
  if ((DAT_140015c02 & 0x40) != 0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (pwVar2[lVar1] != L'\0');
    McTemplateU0qqqqzr3_EtwWriteTransfer
              (param_1,param_2,(ulonglong)uVar3,(int)param_2,in_stack_ffffffffffffffd8,(int)lVar1,
               pwVar2);
  }
  return;
}



===== SleepstudyHelperBlockerActiveDereference @ 1400062a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SleepstudyHelperBlockerActiveDereference(void)

{
  undefined8 uVar1;
  
  if (DAT_140012828 == (code *)0x0) {
    uVar1 = 0xc00000bb;
  }
  else {
    uVar1 = (*DAT_140012828)();
  }
  return uVar1;
}



===== SleepstudyHelperBlockerActiveReference @ 1400062cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SleepstudyHelperBlockerActiveReference(void)

{
  undefined8 uVar1;
  
  if (DAT_140012830 == (code *)0x0) {
    uVar1 = 0xc00000bb;
  }
  else {
    uVar1 = (*DAT_140012830)();
  }
  return uVar1;
}



===== SleepstudyHelperCreateLibraryEx @ 1400062f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SleepstudyHelperCreateLibraryEx(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = SleepstudyHelperEnsureRoutineBlockLoaded();
  if (-1 < (int)uVar1) {
    if (DAT_140012928 == (code *)0x0) {
      uVar1 = 0xc00000bb;
    }
    else {
      uVar1 = (*DAT_140012928)(param_1,param_2);
    }
  }
  return uVar1;
}



===== SleepstudyHelperDestroyBlocker @ 140006340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SleepstudyHelperDestroyBlocker(void)

{
  undefined8 uVar1;
  
  if (DAT_140012868 == (code *)0x0) {
    uVar1 = 0xc00000bb;
  }
  else {
    uVar1 = (*DAT_140012868)();
  }
  return uVar1;
}



===== InitializeTelemetryAssertsKMByDriverObject @ 140006368 =====

ulonglong InitializeTelemetryAssertsKMByDriverObject(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0;
  lStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitUnicodeString(&local_48,0);
    uVar3 = IoQueryFullDriverPath(param_1,&local_48);
    if (-1 < (int)uVar3) {
      uVar2 = RtlUnicodeStringToAnsiString(&local_38,&local_48,1);
      uVar3 = (ulonglong)uVar2;
      ExFreePoolWithTag(uStack_40,0);
      if (-1 < (int)uVar2) {
        uVar2 = (uint)(ushort)local_38;
        do {
          uVar1 = uVar2;
          uVar2 = uVar1 - 1;
          if (uVar2 == 0) goto LAB_140006449;
        } while (*(char *)((ulonglong)uVar2 + lStack_30) != '\\');
        if (uVar2 != (ushort)local_38) {
          local_28 = 0;
          uStack_20 = 0;
          RtlInitAnsiString(&local_28,(ulonglong)uVar1 + lStack_30);
          local_18 = local_28;
          uStack_10 = uStack_20;
          uVar3 = InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_18);
          uVar3 = uVar3 & 0xffffffff;
        }
LAB_140006449:
        RtlFreeAnsiString(&local_38);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 140006470 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 InitializeTelemetryAssertsKMWorkerInternal(ushort *param_1)

{
  undefined8 uVar1;
  
  KeInitializeSpinLock(&g_AssertSpinLock);
  uVar1 = 0;
  g_ModuleName = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 1,0x74727341);
  if (g_ModuleName == (void *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    memmove(g_ModuleName,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _DAT_140012948 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14001a040);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14001a008);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14001a078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 140006524 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM
               (char *param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,param_1,param_2,param_3,param_4);
  return;
}



===== MicrosoftTelemetryAssertTriggeredNoArgsKM @ 140006558 =====

void MicrosoftTelemetryAssertTriggeredNoArgsKM(void)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker
            (unaff_retaddr,0,(char *)0x0,0xffffffff,0xffffffff,(char *)0x0);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140006588 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000675d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined4 param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,char *param_6)

{
  code *pcVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  char *pcVar12;
  undefined8 *puVar13;
  byte *pbVar14;
  longlong lVar15;
  undefined1 *puVar16;
  char *pcVar17;
  IMAGE_DOS_HEADER *pIVar18;
  int iVar19;
  undefined1 auStack_1b8 [8];
  undefined1 auStack_1b0 [116];
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  char *local_130;
  IMAGE_DOS_HEADER *local_128;
  undefined1 local_118 [32];
  undefined4 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  puVar16 = auStack_1b8;
  local_38 = __security_cookie ^ (ulonglong)auStack_1b8;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_140006ea9;
  local_13c = param_2;
  local_138 = param_4;
  local_130 = param_3;
  local_128 = param_1;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar16 = auStack_1b8;
  for (plVar9 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar9 != &g_MicrosoftTelemetryAssertsTriggeredList; plVar9 = (longlong *)*plVar9
      ) {
    plVar8 = plVar9 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar8 == param_1) goto LAB_1400066e4;
  }
  plVar8 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar15 = _DAT_fffff78000000320;
  puVar16 = auStack_1b8;
  if (plVar8 != (longlong *)0x0) {
    *plVar8 = (longlong)param_1;
    uVar6 = KeQueryTimeIncrement();
    puVar16 = auStack_1b8;
    plVar8[2] = 0;
    *(undefined4 *)(plVar8 + 3) = 0;
    puVar13 = &g_MicrosoftTelemetryAssertsTriggeredList;
    plVar8[1] = (longlong)((ulonglong)uVar6 * lVar15) / 10000 + -0xea61;
    plVar9 = plVar8 + 4;
    plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar11 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar9 = (longlong *)(*pcVar1)();
      puVar16 = auStack_1b0;
    }
    *plVar9 = (longlong)plVar11;
    plVar9[1] = (longlong)puVar13;
    plVar11[1] = (longlong)plVar9;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar9;
LAB_1400066e4:
    *(int *)(plVar8 + 2) = (int)plVar8[2] + 1;
    *(int *)((longlong)plVar8 + 0x14) = *(int *)((longlong)plVar8 + 0x14) + 1;
    lVar15 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar16 + -8) = 0x1400066f4;
    uVar6 = KeQueryTimeIncrement();
    lVar15 = (longlong)((ulonglong)uVar6 * lVar15) / 10000;
    if (60000 < (ulonglong)(lVar15 - plVar8[1])) {
      pIVar18 = &IMAGE_DOS_HEADER_140000000;
      if ((param_1 < &IMAGE_DOS_HEADER_140000000) || ((IMAGE_DOS_HEADER *)0x140038000 < param_1)) {
        iVar19 = 0;
      }
      else {
        iVar19 = (int)param_1 + -0x40000000;
      }
      *(int *)(puVar16 + 0x70) = (int)plVar8[2];
      *(undefined4 *)(puVar16 + 0x74) = *(undefined4 *)((longlong)plVar8 + 0x14);
      plVar8[1] = lVar15;
      *(int *)(puVar16 + 0x6c) = (int)plVar8[3];
      *(undefined8 *)(puVar16 + -8) = 0x1400067aa;
      KeReleaseSpinLock(&g_AssertSpinLock,CONCAT71((int7)((ulonglong)lVar15 >> 8),uVar3));
      pcVar12 = local_130;
      if (local_130 == (char *)0x0) {
        pcVar12 = g_ModuleName;
      }
      lVar15 = -1;
      local_130 = pcVar12;
      if (*(int *)(puVar16 + 0x7c) == 0) {
        if (5 < DAT_14001a040) {
          if (((_DAT_14001a050 & 0x400000000000) == 0) ||
             (bVar2 = true, (DAT_14001a058 & 0x400000000000) != DAT_14001a058)) {
            bVar2 = false;
          }
          if (bVar2) {
            *(undefined4 *)(puVar16 + 100) = 10;
            local_f8 = (undefined4 *)(puVar16 + 100);
            local_e8 = puVar16 + 0x60;
            local_d8 = puVar16 + 0x5c;
            local_c8 = puVar16 + 0x58;
            local_f0 = 4;
            *(int *)(puVar16 + 0x60) = iVar19;
            local_e0 = 4;
            *(dword *)(puVar16 + 0x5c) = 0x9e6dd1ef;
            local_d0 = 4;
            *(dword *)(puVar16 + 0x58) = 0x38000;
            local_c0 = 4;
            local_b8 = g_ModuleName;
            if (g_ModuleName == (char *)0x0) {
              local_b8 = "<unknown>";
            }
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (local_b8[lVar10] != '\0');
            local_b0 = (int)lVar10 + 1;
            *(undefined4 *)(puVar16 + 0x54) = *(undefined4 *)(puVar16 + 0x70);
            local_a8 = puVar16 + 0x54;
            *(undefined4 *)(puVar16 + 0x50) = *(undefined4 *)(puVar16 + 0x74);
            local_98 = puVar16 + 0x50;
            local_ac = 0;
            local_a0 = 4;
            local_90 = 4;
            *(undefined8 *)(puVar16 + -8) = 0x140006aa3;
            bVar4 = KeGetCurrentIrql();
            *(uint *)(puVar16 + 0x68) = (uint)bVar4;
            local_88 = puVar16 + 0x68;
            if (param_6 == (char *)0x0) {
              param_6 = "<unknown>";
            }
            if (param_6 == (char *)0x0) {
              param_6 = "";
              local_70 = 1;
            }
            else {
              lVar10 = -1;
              do {
                lVar10 = lVar10 + 1;
              } while (param_6[lVar10] != '\0');
              local_70 = (int)lVar10 + 1;
            }
            pbVar14 = &DAT_14000f858;
            *(undefined1 **)(puVar16 + 0x28) = local_118;
            *(undefined4 *)(puVar16 + 0x20) = 0xb;
            local_78 = param_6;
            goto LAB_1400069a7;
          }
        }
      }
      else if (5 < DAT_14001a040) {
        if (((_DAT_14001a050 & 0x400000000000) == 0) ||
           (bVar2 = true, (DAT_14001a058 & 0x400000000000) != DAT_14001a058)) {
          bVar2 = false;
        }
        if (bVar2) {
          local_134 = 10;
          local_f8 = &local_134;
          local_e8 = puVar16 + 0x78;
          local_d8 = puVar16 + 0x68;
          local_c8 = puVar16 + 0x50;
          local_f0 = 4;
          *(int *)(puVar16 + 0x78) = iVar19;
          local_e0 = 4;
          *(dword *)(puVar16 + 0x68) = 0x9e6dd1ef;
          local_d0 = 4;
          *(dword *)(puVar16 + 0x50) = 0x38000;
          local_c0 = 4;
          local_b8 = g_ModuleName;
          if (g_ModuleName == (char *)0x0) {
            local_b8 = "<unknown>";
          }
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (local_b8[lVar10] != '\0');
          local_b0 = (int)lVar10 + 1;
          *(undefined4 *)(puVar16 + 0x54) = *(undefined4 *)(puVar16 + 0x70);
          local_a8 = puVar16 + 0x54;
          *(undefined4 *)(puVar16 + 0x58) = *(undefined4 *)(puVar16 + 0x74);
          local_98 = puVar16 + 0x58;
          local_ac = 0;
          local_a0 = 4;
          local_90 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x1400068d8;
          bVar4 = KeGetCurrentIrql();
          *(uint *)(puVar16 + 0x5c) = (uint)bVar4;
          local_88 = puVar16 + 0x5c;
          if (pcVar12 == (char *)0x0) {
            pcVar12 = "";
            local_70 = 1;
          }
          else {
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (pcVar12[lVar10] != '\0');
            local_70 = (int)lVar10 + 1;
          }
          *(undefined4 *)(puVar16 + 0x60) = local_138;
          local_68 = puVar16 + 0x60;
          *(undefined4 *)(puVar16 + 100) = param_5;
          local_58 = puVar16 + 100;
          if (param_6 == (char *)0x0) {
            param_6 = "<unknown>";
          }
          local_60 = 4;
          local_50 = 4;
          if (param_6 == (char *)0x0) {
            param_6 = "";
            local_40 = 1;
          }
          else {
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (param_6[lVar10] != '\0');
            local_40 = (int)lVar10 + 1;
          }
          pbVar14 = &DAT_14000f708;
          *(undefined1 **)(puVar16 + 0x28) = local_118;
          *(undefined4 *)(puVar16 + 0x20) = 0xe;
          local_3c = 0;
          local_78 = pcVar12;
          local_48 = param_6;
LAB_1400069a7:
          local_80 = 4;
          local_6c = 0;
          *(undefined8 *)(puVar16 + -8) = 0x1400069b3;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x14001a040,pbVar14,0,pIVar18,*(undefined4 *)(puVar16 + 0x20),
                     *(undefined8 **)(puVar16 + 0x28));
        }
      }
      if ((DAT_14001a078 == 0) || (*(int *)(puVar16 + 0x6c) != 0)) goto LAB_140006ea9;
      *(undefined8 *)(puVar16 + -8) = 0x140006b3b;
      cVar5 = KeGetCurrentIrql();
      if (cVar5 != '\0') goto LAB_140006ea9;
      *(undefined4 *)(puVar16 + 0x40) = 0;
      *(undefined8 *)(puVar16 + 0x38) = 0;
      *(undefined8 *)(puVar16 + 0x30) = 0;
      *(undefined8 *)(puVar16 + 0x28) = 0x38000;
      *(undefined8 *)(puVar16 + 0x20) = 0x9e6dd1ef;
      *(undefined8 *)(puVar16 + -8) = 0x140006b84;
      pcVar12 = g_ModuleName;
      iVar7 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1,iVar19);
      if (*(int *)(puVar16 + 0x7c) == 0) {
        if (5 < DAT_14001a040) {
          pcVar17 = (char *)0x400000000000;
          if (((_DAT_14001a050 & 0x400000000000) == 0) ||
             (bVar2 = true, (DAT_14001a058 & 0x400000000000) != DAT_14001a058)) {
            bVar2 = false;
          }
          if (bVar2) {
            *(undefined4 *)(puVar16 + 0x6c) = 10;
            *(int *)(puVar16 + 100) = iVar19;
            *(dword *)(puVar16 + 0x60) = 0x9e6dd1ef;
            *(dword *)(puVar16 + 0x5c) = 0x38000;
            local_b8 = g_ModuleName;
            if (g_ModuleName == (char *)0x0) {
              local_b8 = "<unknown>";
            }
            do {
              lVar15 = lVar15 + 1;
            } while (local_b8[lVar15] != '\0');
            local_b0 = (int)lVar15;
            *(undefined4 *)(puVar16 + 0x58) = *(undefined4 *)(puVar16 + 0x70);
            *(undefined4 *)(puVar16 + 0x54) = *(undefined4 *)(puVar16 + 0x74);
            *(undefined1 **)(puVar16 + 0x28) = local_118;
            *(undefined4 *)(puVar16 + 0x20) = 10;
            pbVar14 = &DAT_14000f8c5;
            *(int *)(puVar16 + 0x50) = iVar7;
            goto LAB_140006e40;
          }
        }
      }
      else if (5 < DAT_14001a040) {
        if (((_DAT_14001a050 & 0x400000000000) == 0) ||
           (bVar2 = true, (DAT_14001a058 & 0x400000000000) != DAT_14001a058)) {
          bVar2 = false;
        }
        if (bVar2) {
          *(undefined4 *)(puVar16 + 0x6c) = 10;
          *(int *)(puVar16 + 100) = iVar19;
          *(dword *)(puVar16 + 0x60) = 0x9e6dd1ef;
          *(dword *)(puVar16 + 0x5c) = 0x38000;
          local_b8 = g_ModuleName;
          if (g_ModuleName == (char *)0x0) {
            local_b8 = "<unknown>";
          }
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (local_b8[lVar10] != '\0');
          local_b0 = (int)lVar10;
          *(undefined4 *)(puVar16 + 0x58) = *(undefined4 *)(puVar16 + 0x70);
          *(undefined4 *)(puVar16 + 0x54) = *(undefined4 *)(puVar16 + 0x74);
          *(int *)(puVar16 + 0x50) = iVar7;
          if (local_130 == (char *)0x0) {
            pcVar17 = "";
            local_70 = 1;
          }
          else {
            do {
              lVar15 = lVar15 + 1;
            } while (local_130[lVar15] != '\0');
            local_70 = (int)lVar15 + 1;
            pcVar17 = local_130;
          }
          pbVar14 = &DAT_14000f7b2;
          *(undefined4 *)(puVar16 + 0x68) = local_138;
          local_68 = puVar16 + 0x68;
          *(undefined4 *)(puVar16 + 0x78) = param_5;
          local_58 = puVar16 + 0x78;
          *(undefined1 **)(puVar16 + 0x28) = local_118;
          *(undefined4 *)(puVar16 + 0x20) = 0xd;
          local_6c = 0;
          local_60 = 4;
          local_50 = 4;
          local_78 = pcVar17;
LAB_140006e40:
          local_b0 = local_b0 + 1;
          local_80 = 4;
          local_88 = puVar16 + 0x50;
          local_90 = 4;
          local_98 = puVar16 + 0x54;
          local_a0 = 4;
          local_a8 = puVar16 + 0x58;
          local_ac = 0;
          local_c0 = 4;
          local_c8 = puVar16 + 0x5c;
          local_d0 = 4;
          local_d8 = puVar16 + 0x60;
          local_e0 = 4;
          local_e8 = puVar16 + 100;
          local_f0 = 4;
          local_f8 = (undefined4 *)(puVar16 + 0x6c);
          *(undefined8 *)(puVar16 + -8) = 0x140006e4c;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x14001a040,pbVar14,pcVar17,pcVar12,*(undefined4 *)(puVar16 + 0x20),
                     *(undefined8 **)(puVar16 + 0x28));
        }
      }
      if (iVar7 != 0) goto LAB_140006ea9;
      *(undefined8 *)(puVar16 + -8) = 0x140006e5e;
      uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar9 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar9[-4] == local_128) {
            *(int *)(plVar9 + -1) = (int)plVar9[-1] + 1;
            break;
          }
          plVar9 = (longlong *)*plVar9;
        } while ((longlong **)plVar9 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar16 + -8) = 0x140006ea4;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
LAB_140006ea9:
  *(undefined8 *)(puVar16 + -8) = 0x140006eb8;
  return;
}



===== _guard_check_icall @ 140006ef0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140006f08 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140006f2c =====

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



===== __GSHandlerCheck_SEH @ 140006f94 =====

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



===== __cpu_features_init @ 140007030 =====

/* WARNING: Removing unreachable block (ram,0x00014000709a) */
/* WARNING: Removing unreachable block (ram,0x000140007049) */
/* WARNING: Removing unreachable block (ram,0x00014000703a) */

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



===== __security_check_cookie @ 140007100 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140007140 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007170 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007170. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400071a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140007200 =====

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



===== memset @ 140007500 =====

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



===== __memset_repmovs @ 140007640 =====

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



===== __memset_query @ 1400076c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140007740 =====

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
    if (param_3 < &DAT_00000010) {
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



===== __memset_spec_ermsb_repmovsb @ 140007880 =====

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



===== __memset_spec_plain @ 140007900 =====

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
    if (param_3 < &DAT_00000010) {
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



===== PdcIrpInvalidRequest @ 14001b010 =====

undefined8
PdcIrpInvalidRequest(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  PdcPrint(2,"PDC: function: %s\n","PdcIrpInvalidRequest",param_4);
  if (**(char **)(param_2 + 0xb8) == '\x16') {
    PoStartNextPowerIrp(param_2);
  }
  *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
  IofCompleteRequest(param_2,0);
  return 0xc0000010;
}



===== wil_details_EvaluateFeatureDependencies @ 14001b078 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_LocklessPhasesPoCallout__private_descriptor;
  ppuVar2 = &Feature_LocklessPhasesPoCallout__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014001b0b3;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001b12d:
  while( true ) {
    if (&UNK_1400116cf < ppuVar3) {
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
      if (&UNK_1400116cf < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014001b0b3:
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
      if (&UNK_1400116cf < ppuVar2) goto LAB_14001b12d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001b12d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001b168 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14001b200;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14001b200;
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
LAB_14001b200:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001b250 =====

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
      for (ppuVar2 = &Feature_LocklessPhasesPoCallout__private_descriptor;
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
              if (&UNK_1400116cf < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001b2d0 =====

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
  for (ppuVar3 = &Feature_LocklessPhasesPoCallout__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001b3cd;
  }
LAB_14001b3d6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001b3cd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001b3d6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001b39e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001b39e;
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
    if (&UNK_1400116cf < ppuVar3) goto LAB_14001b3d6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001b3cd;
}



===== PdcOpenRegistryKey @ 14001b3fc =====

void PdcOpenRegistryKey(short *param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  longlong lVar4;
  undefined8 in_stack_00000028;
  undefined8 local_48;
  short *psStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar2 = 0;
  local_48 = 0;
  psStack_40 = (short *)0x0;
  if (param_1 != (short *)0x0) {
    lVar4 = 0x7fff;
    psVar3 = param_1;
    do {
      if (*psVar3 == 0) break;
      psVar3 = psVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar2 = ~-(uint)(lVar4 != 0) & 0xc000000d;
    if (lVar4 != 0) {
      sVar1 = (0x7fff - (short)lVar4) * 2;
      local_48 = (ulonglong)CONCAT22(sVar1 + 2,sVar1);
      psStack_40 = param_1;
    }
  }
  if (-1 < (int)uVar2) {
    local_28 = &local_48;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    local_30 = 0;
    ZwOpenKey(in_stack_00000028,8,&local_38);
  }
  return;
}



===== PdcAcknowledgeActivators @ 14001b4b4 =====

undefined8 PdcAcknowledgeActivators(int param_1,undefined4 param_2,uint param_3,longlong param_4)

{
  longlong lVar1;
  code *pcVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined8 uVar5;
  int iVar6;
  char *pcVar7;
  longlong *plVar8;
  char *pcVar9;
  bool bVar10;
  
  uVar5 = 2;
  PdcPrint(2,"%s:Activators received acknowledgement(Status:%08lx, State::%08lx)\n",
           "PdcAcknowledgeActivators",(ulonglong)param_3);
  if ((Microsoft_Windows_PDCEnableBits & 2) != 0) {
    McTemplateU0qq_EtwWriteTransfer(uVar5,&PDC_ACTIVATOR_ACKNOWLEDGEMENT,(ulonglong)param_3,param_2)
    ;
  }
  plVar8 = PdcActivators;
  do {
    if ((longlong **)plVar8 == &PdcActivators) {
      for (plVar8 = PdcActivators;
          (plVar4 = (longlong *)0x0, (longlong **)plVar8 != &PdcActivators &&
          ((*(char *)((longlong)plVar8 + 0xc4) != '\0' ||
           (plVar4 = plVar8, (longlong *)plVar8[0x16] != plVar8 + 0x16))));
          plVar8 = (longlong *)*plVar8) {
      }
      while( true ) {
        if (plVar4 == (longlong *)0x0) {
          return 0;
        }
        lVar1 = *plVar4;
        if ((*(longlong **)(lVar1 + 8) != plVar4) ||
           (plVar8 = (longlong *)plVar4[1], (longlong *)*plVar8 != plVar4)) break;
        *plVar8 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar8;
        ExFreePoolWithTag(plVar4,0);
        for (plVar8 = PdcActivators;
            (plVar4 = (longlong *)0x0, (longlong **)plVar8 != &PdcActivators &&
            ((*(char *)((longlong)plVar8 + 0xc4) != '\0' ||
             (plVar4 = plVar8, (longlong *)plVar8[0x16] != plVar8 + 0x16))));
            plVar8 = (longlong *)*plVar8) {
        }
      }
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      uVar5 = (*pcVar2)();
      return uVar5;
    }
    for (plVar4 = (longlong *)plVar8[0x16]; plVar4 != plVar8 + 0x16; plVar4 = (longlong *)*plVar4) {
      if (((int)plVar4[99] == param_1) &&
         ((param_1 != 6 || (*(longlong *)(param_4 + 8) == plVar4[0x5c])))) {
        pcVar9 = "PdcpAcknowledgeActivationInstance";
        uVar5 = 2;
        pcVar7 = "%s:Activator:%p received acknowledgement (Status%08lx)\n";
        PdcPrint(2,"%s:Activator:%p received acknowledgement (Status%08lx)\n",
                 "PdcpAcknowledgeActivationInstance",plVar4);
        if ((Microsoft_Windows_PDCEnableBits & 2) != 0) {
          pcVar9 = (char *)plVar4[2];
          pcVar7 = "\t";
          McTemplateU0pt_EtwWriteTransfer
                    (uVar5,&PDC_ACTIVATOR_CLIENT_ACKNOWLEDGEMENT,pcVar9,param_3);
        }
        if (*(int *)((longlong)plVar4 + 0x2f4) == 2) {
          *(undefined4 *)((longlong)plVar4 + (longlong)(int)plVar4[99] * 4 + 0x2f8) = 2;
          pcVar7 = (char *)(ulonglong)*(uint *)(plVar4 + 99);
          uVar5 = PdcpGetResiliencyThreshold((int)plVar4[3]);
          iVar6 = (int)pcVar7;
          if (iVar6 < (int)uVar5) {
            pcVar7 = (char *)0x0;
            *(int *)(plVar4 + 99) = iVar6 + 1;
            PdcpReferenceActivationInstance((longlong)plVar4,0);
          }
          uVar3 = PdcpGetActivationResiliencyStatus((longlong)plVar4);
          bVar10 = (int)uVar3 == 2;
        }
        else {
          if (*(int *)((longlong)plVar4 + 0x2f4) != 0) goto LAB_14001b628;
          *(undefined4 *)((longlong)plVar4 + (longlong)(int)plVar4[99] * 4 + 0x2f8) = 0;
          if (0 < (int)plVar4[99]) {
            pcVar7 = (char *)0x0;
            *(int *)(plVar4 + 99) = (int)plVar4[99] + -1;
            PdcpDereferenceActivationInstance((longlong)plVar4,0);
          }
          uVar3 = PdcpGetActivationResiliencyStatus((longlong)plVar4);
          bVar10 = (int)uVar3 == 0;
        }
        if (bVar10) {
          PdcpCompleteResiliencyOperation((longlong)plVar4,pcVar7,(longlong)pcVar9);
        }
      }
LAB_14001b628:
    }
    while (plVar4 = PdcpGetFirstRemoveReadyActivationInstance((longlong)plVar8),
          plVar4 != (longlong *)0x0) {
      PdcpFreeActivationInstance(plVar4);
    }
    plVar8 = (longlong *)*plVar8;
  } while( true );
}



===== PdcActivatorFree @ 14001b70c =====

undefined4 PdcActivatorFree(longlong *param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  plVar7 = param_1;
  PdcpCancelActivatorWatchdog((longlong)param_1);
  uVar5 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  puVar9 = auStack_38;
  uVar8 = 0;
  if ((int)uVar5 == 0) {
    iVar10 = 0;
    do {
      while (plVar7 = param_1, plVar6 = PdcpGetActivationByType((longlong)param_1,iVar10),
            plVar6 != (longlong *)0x0) {
        *(undefined1 *)(plVar6 + 0x67) = 0;
        uVar5 = PdcpGetActivationResiliencyStatus((longlong)plVar6);
        if ((int)uVar5 == 2) {
          PdcpDereferenceActivationInstance((longlong)plVar6,9);
        }
        if (plVar6[100] != 0) {
          PdcpCancelActivationInstanceTimerAction((longlong)plVar6);
        }
        uVar5 = PdcpGetActivationResiliencyStatus((longlong)plVar6);
        if ((int)uVar5 == 0) {
          PdcpFreeActivationInstance(plVar6);
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < 8);
  }
  else {
    while (plVar6 = (longlong *)param_1[0x16], plVar6 != param_1 + 0x16) {
      *(undefined1 *)(plVar6 + 0x67) = 0;
      if (plVar6[100] != 0) {
        PdcpCancelActivationInstanceTimerAction((longlong)plVar6);
      }
      uVar5 = PdcpGetActivationResiliencyStatus((longlong)plVar6);
      if ((int)uVar5 != 0) {
        PdcpDereferenceActivationInstance((longlong)plVar6,9);
      }
      PdcpGetActivationResiliencyStatus((longlong)plVar6);
      PdcpFreeActivationInstance(plVar6);
      plVar7 = plVar6;
    }
  }
  lVar3 = param_1[5];
  *(undefined1 *)((longlong)param_1 + 0xc4) = 0;
  puVar4 = auStack_38;
  if ((longlong *)param_1[0x16] == param_1 + 0x16) {
    lVar1 = *param_1;
    if ((*(longlong **)(lVar1 + 8) == param_1) &&
       (plVar7 = (longlong *)param_1[1], (longlong *)*plVar7 == param_1)) {
      *plVar7 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar7;
      plVar7 = param_1;
      ExFreePoolWithTag(param_1,0);
      goto LAB_14001b83e;
    }
    plVar7 = (longlong *)0x3;
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)();
    puVar4 = auStack_30;
  }
  puVar9 = puVar4;
  uVar8 = 0x103;
LAB_14001b83e:
  if ((Microsoft_Windows_PDCEnableBits & 2) != 0) {
    *(undefined4 *)(puVar9 + 0x20) = uVar8;
    *(undefined8 *)(puVar9 + -8) = 0x14001b85d;
    McTemplateU0pqq_EtwWriteTransfer
              (plVar7,&PDC_ACTIVATOR_DEREGISTRATION,param_1,(int)lVar3,puVar9[0x20]);
  }
  return uVar8;
}



===== PdcActivatorInitialize @ 14001b884 =====

undefined4 PdcActivatorInitialize(uint *param_1,int param_2,longlong param_3,undefined8 *param_4)

{
  short sVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  undefined8 *_Dst;
  short *psVar5;
  undefined8 *puVar6;
  short *psVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  longlong lVar10;
  undefined *puVar11;
  ulonglong uVar12;
  longlong lVar13;
  longlong lVar14;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [56];
  
  puVar9 = auStack_68;
  uVar8 = 0;
  uVar12 = (ulonglong)param_1 & 0xffffffff;
  *param_4 = 0;
  _Dst = (undefined8 *)0x0;
  puVar11 = (undefined *)0x0;
  lVar13 = 0;
  uVar4 = (uint)param_1;
  if (uVar4 - 1 < 0x7c) {
    param_1 = &PdcClientInfo + uVar12 * 6;
    if (((param_1 != (uint *)0x0) && ((*param_1 & 1) != 0)) && ((param_2 == 2 || (param_2 == 7)))) {
      puVar11 = (&PTR_u_Invalid_client_140031f70)[uVar12 * 3];
      lVar13 = -1;
      do {
        lVar13 = lVar13 + 1;
      } while (*(short *)(puVar11 + lVar13 * 2) != 0);
      lVar10 = 0x40;
      param_1 = (uint *)0x40;
      _Dst = (undefined8 *)ExAllocatePool2(0x40,0x490,0x41636450);
      puVar9 = auStack_68;
      if (_Dst == (undefined8 *)0x0) {
        uVar8 = 0xc0000017;
      }
      else {
        memset(_Dst,0,0x490);
        *(int *)(_Dst + 2) = param_2;
        *(uint *)(_Dst + 5) = uVar4;
        _Dst[0x91] = 1;
        if (param_3 != 0) {
          psVar7 = (short *)((longlong)_Dst + 0x2c);
          lVar14 = param_3 - (longlong)psVar7;
          do {
            if ((lVar10 == -0x7fffffbe) ||
               (sVar1 = *(short *)(lVar14 + (longlong)psVar7), sVar1 == 0)) break;
            *psVar7 = sVar1;
            psVar7 = psVar7 + 1;
            lVar10 = lVar10 + -1;
          } while (lVar10 != 0);
          psVar5 = psVar7 + -1;
          if (lVar10 != 0) {
            psVar5 = psVar7;
          }
          *psVar5 = 0;
        }
        puVar6 = _Dst + 0x1a;
        lVar10 = 8;
        do {
          *puVar6 = 0;
          *(undefined4 *)(puVar6 + 1) = 0xc0000008;
          puVar6 = puVar6 + 2;
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
        uVar2 = *(uint *)(_Dst + 5);
        if ((uVar2 != 0x12) &&
           (((0x7b < uVar2 - 1 || (&PdcClientInfo + (ulonglong)uVar2 * 6 == (uint *)0x0)) ||
            (((&PdcClientInfo)[(ulonglong)uVar2 * 6] & 0x20000) == 0)))) {
          *(uint *)(_Dst + 0x18) = *(uint *)(_Dst + 0x18) | PdcGlobalActivatorsVetoBitset;
        }
        puVar6 = _Dst + 0x16;
        _Dst[0x17] = puVar6;
        *puVar6 = puVar6;
        puVar6 = PdcGetActivatorStats(uVar4);
        puVar9 = auStack_68;
        _Dst[0x90] = puVar6;
        param_1 = (uint *)&PdcActivators;
        *(undefined1 *)((longlong)_Dst + 0xc4) = 1;
        if ((undefined8 *)*DAT_140015bf8 != &PdcActivators) {
          param_1 = (uint *)0x3;
          pcVar3 = (code *)swi(0x29);
          DAT_140015bf8 = (undefined8 *)(*pcVar3)();
          puVar9 = auStack_60;
        }
        _Dst[1] = DAT_140015bf8;
        *_Dst = param_1;
        *DAT_140015bf8 = _Dst;
        DAT_140015bf8 = _Dst;
        **(undefined8 **)(puVar9 + 0x88) = _Dst;
      }
      goto LAB_14001ba57;
    }
  }
  uVar8 = 0xc000000d;
LAB_14001ba57:
  if ((Microsoft_Windows_PDCEnableBits & 1) != 0) {
    *(undefined **)(puVar9 + 0x30) = puVar11;
    *(int *)(puVar9 + 0x28) = (int)lVar13;
    *(undefined4 *)(puVar9 + 0x20) = uVar8;
    *(undefined8 *)(puVar9 + -8) = 0x14001ba80;
    McTemplateU0pqqqzr3_EtwWriteTransfer
              (param_1,&PDC_ACTIVATOR_REGISTRATION,_Dst,uVar4,puVar9[0x20],*(int *)(puVar9 + 0x28),
               *(undefined8 *)(puVar9 + 0x30));
  }
  return uVar8;
}



===== PdcActivatorsRundown @ 14001baa8 =====

void PdcActivatorsRundown(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 *puVar7;
  longlong lVar8;
  int *piVar9;
  undefined **ppuVar10;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 in_stack_ffffffffffffffb0;
  
  puVar7 = PdcActivators;
  if ((undefined8 **)PdcActivators != &PdcActivators) {
    do {
      if (*(char *)((longlong)puVar7 + 0xc4) != '\0') {
        if (*(uint *)(puVar7 + 5) - 1 < 0x7c) {
          ppuVar10 = &PTR_u_Invalid_client_140031f70 + (ulonglong)*(uint *)(puVar7 + 5) * 3;
        }
        else {
          ppuVar10 = (undefined **)&DAT_00000010;
        }
        lVar8 = -1;
        do {
          lVar8 = lVar8 + 1;
        } while (*(short *)(*ppuVar10 + lVar8 * 2) != 0);
        puVar2 = puVar7 + 0x1a;
        lVar6 = 8;
        do {
          *puVar2 = 0;
          *(undefined4 *)(puVar2 + 1) = 0xc0000008;
          puVar2 = puVar2 + 2;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
        for (puVar2 = (undefined8 *)puVar7[0x16]; puVar2 != puVar7 + 0x16;
            puVar2 = (undefined8 *)*puVar2) {
          uVar3 = PdcpGetResiliencyThreshold(*(int *)(puVar2 + 3));
          lVar6 = (longlong)(int)uVar3;
          uVar4 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar4 == 0) {
            param_2 = 0;
            if (-1 < (int)uVar3) {
              piVar9 = (int *)(puVar2 + 0x5f);
              plVar5 = puVar7 + 0x1a;
              do {
                if (param_2 != 6) {
                  iVar1 = *piVar9;
                  if (iVar1 == 2) {
                    *plVar5 = *plVar5 + 1;
                    *(undefined4 *)(plVar5 + 1) = 0;
                  }
                  else if (iVar1 == 1) {
                    *plVar5 = *plVar5 + 1;
                    *(undefined4 *)(plVar5 + 1) = 0x103;
                  }
                  else if (iVar1 == 0) {
                    *(undefined4 *)(plVar5 + 1) = 0xc0000008;
                  }
                }
                param_2 = param_2 + 1;
                piVar9 = piVar9 + 1;
                plVar5 = plVar5 + 2;
              } while (param_2 <= lVar6);
            }
          }
          else {
            uVar4 = PdcpGetActivationResiliencyStatus((longlong)puVar2);
            if (-1 < lVar6) {
              lVar6 = lVar6 + 1;
              plVar5 = puVar7 + 0x1a;
              do {
                iVar1 = (int)uVar4;
                if (iVar1 == 2) {
                  *plVar5 = *plVar5 + 1;
                  *(undefined4 *)(plVar5 + 1) = 0;
                }
                else if (iVar1 == 1) {
                  *plVar5 = *plVar5 + 1;
                  *(undefined4 *)(plVar5 + 1) = 0x103;
                }
                else if (iVar1 == 0) {
                  *(undefined4 *)(plVar5 + 1) = 0xc0000008;
                }
                plVar5 = plVar5 + 2;
                lVar6 = lVar6 + -1;
              } while (lVar6 != 0);
            }
          }
        }
        if ((Microsoft_Windows_PDCEnableBits & 1) != 0) {
          McTemplateU0pqqNR2qzr4_EtwWriteTransfer
                    (puVar7 + 0x1a,param_2,puVar7,*(undefined4 *)(puVar7 + 5),
                     in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,puVar7 + 0x1a,(int)lVar8,
                     *ppuVar10);
        }
      }
      puVar7 = (undefined8 *)*puVar7;
    } while ((undefined8 **)puVar7 != &PdcActivators);
  }
  return;
}



===== PdcpAcquireReleaseResiliencyBias @ 14001bc80 =====

void PdcpAcquireReleaseResiliencyBias
               (longlong param_1,char param_2,undefined8 param_3,longlong param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 0x28);
    if (0x7b < uVar1 - 1) goto LAB_14001bcc0;
    param_1 = (ulonglong)uVar1 * 3;
    if ((&PdcClientInfo + (ulonglong)uVar1 * 6 == (uint *)0x0) ||
       (((&PdcClientInfo)[(ulonglong)uVar1 * 6] & 0x42000) == 0)) goto LAB_14001bcc0;
  }
  uVar2 = 3;
LAB_14001bcc0:
  PdcReleaseLock();
  PdcActivationClientActivityRequest(param_1,uVar2,param_2,param_4);
  PdcAcquireLock();
  return;
}



===== PdcpActivationWatchdog @ 14001bcf0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpActivationWatchdog
               (longlong param_1,undefined *param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 local_res8;
  undefined8 local_358;
  undefined8 uStack_350;
  undefined8 local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined8 local_328 [5];
  undefined4 local_300;
  undefined4 local_2f0;
  
  local_358 = 0;
  uStack_350 = 0;
  local_338 = 0;
  local_348 = 0;
  uStack_340 = 0;
  PdcAcquireLock();
  lVar1 = *(longlong *)(param_1 + 0xb8);
  if ((lVar1 != 0) && (*(undefined8 *)(lVar1 + 0x470) = 0, DAT_14003100c == 8)) {
    *(longlong *)(lVar1 + 0x478) =
         *(longlong *)(lVar1 + 0x478) + (ulonglong)PdcCriticalActivatorTimeout;
    uVar5 = (ulonglong)(uint)(*(int *)(lVar1 + 0x478) * 1000);
    if ((*(longlong **)(lVar1 + 0xb0) == (longlong *)(lVar1 + 0xb0)) ||
       (*(longlong *)(lVar1 + 0xb8) == 0)) {
      uVar3 = 5;
    }
    else {
      uVar3 = (undefined1)*(undefined4 *)(*(longlong *)(lVar1 + 0xb8) + 0x18);
    }
    local_res8._0_2_ = CONCAT11(uVar3,*(undefined1 *)(lVar1 + 0x28));
    uVar2 = CONCAT22(CONCAT11(PdcCriticalActivatorAction,PdcActivationOnAc),(undefined2)local_res8);
    local_res8 = (ulonglong)uVar2;
    if (*(char *)(lVar1 + 0x18) == '\x01') {
      uVar4 = (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x20) + 0x28);
    }
    else {
      uVar4 = 0;
    }
    if ((DAT_140015c02 & 8) != 0) {
      param_2 = &PDC_ACTIVATOR_ACTIVE_TOO_LONG;
      McTemplateU0qqq_EtwWriteTransfer(uVar4,&PDC_ACTIVATOR_ACTIVE_TOO_LONG,uVar5,uVar2,(char)uVar4)
      ;
      param_4 = local_res8;
    }
    PdcpSetActivatorWatchdog(lVar1);
    if (((0x7b < *(uint *)(lVar1 + 0x28) - 1) ||
        (&PdcClientInfo + (ulonglong)*(uint *)(lVar1 + 0x28) * 6 == (uint *)0x0)) ||
       (((&PdcClientInfo)[(ulonglong)*(uint *)(lVar1 + 0x28) * 6] & 0x800) == 0)) {
      if ((_PdcCriticalActivatorAction & 4) != 0) {
        PdcpCancelActivatorWatchdog(lVar1);
        *(int *)(lVar1 + 200) = *(int *)(lVar1 + 200) + 1;
        PdcpWriteV1ActivationRevocationTelemetryEvent(lVar1,param_2,uVar5,param_4);
        PdcpEnforceActivatorClientVeto(lVar1,0,CONCAT71((int7)(uVar5 >> 8),1),param_4);
        memset(local_328,0,800);
        local_2f0 = 0;
        local_300 = 0xe;
        PdcpSendMessageToActivatorClient(lVar1,local_328);
      }
      if ((_PdcCriticalActivatorAction & 1) != 0) {
        PdcTriageCaptureContext(lVar1,&local_358,'\x01');
        DbgkWerCaptureLiveKernelDump
                  (L"PDCActivator",0x15c,*(undefined4 *)(lVar1 + 0x28),3,lVar1,&local_358,0,0,1);
      }
      if ((_PdcCriticalActivatorAction & 2) != 0) {
        PdcTriageCaptureContext(lVar1,&local_358,'\0');
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x14f,*(undefined4 *)(lVar1 + 0x28),3,lVar1,&local_358);
      }
    }
  }
  ExFreePoolWithTag(param_1,0);
  PdcReleaseLock();
  return;
}



===== PdcpCancelActivationInstanceTimerAction @ 14001bf40 =====

void PdcpCancelActivationInstanceTimerAction(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = *(longlong *)(param_1 + 800);
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0xb8) = 0;
    cVar2 = KeCancelTimer(lVar1);
    if (cVar2 != '\0') {
      ExFreePoolWithTag(lVar1,0);
    }
    *(undefined8 *)(param_1 + 800) = 0;
  }
  return;
}



===== PdcpCancelActivatorWatchdog @ 14001bfa0 =====

void PdcpCancelActivatorWatchdog(longlong param_1)

{
  char cVar1;
  
  *(undefined8 *)(param_1 + 0x478) = 0;
  if (*(longlong *)(param_1 + 0x470) != 0) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x470) + 0xb8) = 0;
    cVar1 = KeCancelTimer(*(undefined8 *)(param_1 + 0x470));
    if (cVar1 != '\0') {
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x470),0);
    }
    *(undefined8 *)(param_1 + 0x470) = 0;
  }
  return;
}



===== PdcpCompleteResiliencyOperation @ 14001c008 =====

void PdcpCompleteResiliencyOperation(longlong param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  ulonglong uVar4;
  char *pcVar5;
  undefined4 uVar6;
  longlong lVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  uVar4 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    *(undefined4 *)(param_1 + 0x318) = 8;
  }
  iVar1 = *(int *)(param_1 + 0x31c);
  if (iVar1 == 0) goto LAB_14001c107;
  if (iVar1 == 1) {
    pcVar5 = "PdcpReplyV1ActivationDeactivation";
LAB_14001c0bb:
    *(undefined4 *)(lVar2 + 0x188) = 0;
    lVar7 = lVar2 + 0x150;
    PdcpPrintActivationMessage(pcVar5,lVar7);
    PdcpReplyActivatorClient(lVar2,lVar7,param_3);
  }
  else {
    if (iVar1 == 2) {
      if ((*(byte *)(param_1 + 0x20) & 2) == 0) {
        pcVar5 = "PdcpV2ReplyActivation";
        *(undefined8 *)(lVar2 + 400) = *(undefined8 *)(param_1 + 0x370);
LAB_14001c07b:
        *(undefined4 *)(lVar2 + 0x188) = 0;
        lVar7 = lVar2 + 0x150;
        *(undefined4 *)(lVar2 + 0x18c) = 0;
        PdcpPrintActivationMessage(pcVar5,lVar7);
        PdcpReplyActivatorClient(lVar2,lVar7,param_3);
      }
    }
    else {
      if (iVar1 != 3) {
        if (iVar1 == 4) {
          if ((*(byte *)(param_1 + 0x20) & 2) == 0) {
            pcVar5 = "PdcpV2ReplyDeactivation";
            goto LAB_14001c0bb;
          }
        }
        else {
          if (iVar1 == 5) {
            uVar6 = 0x65;
          }
          else if (iVar1 == 6) {
            uVar6 = 0x12e;
          }
          else {
            if (iVar1 != 7) goto LAB_14001c100;
            uVar6 = 0x12f;
          }
          PdcpV2SendCallbackMessage(param_1,uVar6);
        }
        goto LAB_14001c100;
      }
      if ((*(byte *)(param_1 + 0x20) & 2) == 0) {
        pcVar5 = "PdcpV2ReplyRenew";
        goto LAB_14001c07b;
      }
    }
    PdcpSetActivationInstanceTimerAction(param_1,0);
  }
LAB_14001c100:
  *(undefined4 *)(param_1 + 0x31c) = 0;
LAB_14001c107:
  cVar3 = PdcpIsActivatorHoldingResiliency(lVar2);
  if (cVar3 == '\0') {
    PdcpCancelActivatorWatchdog(lVar2);
  }
  else if (*(longlong *)(lVar2 + 0x470) == 0) {
    PdcpSetActivatorWatchdog(lVar2);
  }
  return;
}



===== PdcpCreateActivationInstance @ 14001c144 =====

longlong *
PdcpCreateActivationInstance
          (longlong param_1,int param_2,longlong param_3,undefined4 param_4,undefined4 param_5,
          short *param_6,short *param_7,longlong *param_8,longlong *param_9)

{
  short sVar1;
  uint uVar2;
  code *pcVar3;
  longlong *_Dst;
  short *psVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  
  _Dst = (longlong *)ExAllocatePool2(0x40,0x378,0x41636450);
  if (_Dst == (longlong *)0x0) {
    return (longlong *)0x0;
  }
  memset(_Dst,0,0x378);
  _Dst[2] = param_1;
  *(undefined4 *)((longlong)_Dst + 0x36c) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(_Dst + 0x6d) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)((longlong)_Dst + 0x2c) = param_5;
  *(int *)(_Dst + 3) = param_2;
  _Dst[4] = param_3;
  *(undefined4 *)(_Dst + 5) = param_4;
  _Dst[0x6e] = *(longlong *)(param_1 + 0x488);
  *(longlong *)(param_1 + 0x488) = *(longlong *)(param_1 + 0x488) + 1;
  if (param_6 == (short *)0x0) {
LAB_14001c223:
    uVar10 = 0;
    if (param_6 != (short *)0x0) goto LAB_14001c22b;
LAB_14001c25f:
    plVar8 = _Dst + 6;
    lVar9 = 0x80;
    lVar11 = (longlong)L"DefaultTask" - (longlong)plVar8;
    do {
      if ((lVar9 == -0x7fffff7e) || (sVar1 = *(short *)(lVar11 + (longlong)plVar8), sVar1 == 0))
      break;
      *(short *)plVar8 = sVar1;
      plVar8 = (longlong *)((longlong)plVar8 + 2);
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
  }
  else {
    lVar9 = 0x80;
    psVar4 = param_6;
    do {
      if (*psVar4 == 0) break;
      psVar4 = psVar4 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    uVar10 = -(ulonglong)(lVar9 != 0) & 0x80U - lVar9;
    if (lVar9 == 0) goto LAB_14001c223;
LAB_14001c22b:
    if (uVar10 == 0) goto LAB_14001c25f;
    plVar8 = _Dst + 6;
    lVar9 = 0x80;
    lVar11 = (longlong)param_6 - (longlong)plVar8;
    do {
      if ((lVar9 == -0x7fffff7e) || (sVar1 = *(short *)(lVar11 + (longlong)plVar8), sVar1 == 0))
      break;
      *(short *)plVar8 = sVar1;
      plVar8 = (longlong *)((longlong)plVar8 + 2);
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
  }
  plVar5 = (longlong *)((longlong)plVar8 + -2);
  if (lVar9 != 0) {
    plVar5 = plVar8;
  }
  *(short *)plVar5 = 0;
  if (param_7 == (short *)0x0) {
LAB_14001c2d9:
    uVar10 = 0;
    if (param_7 != (short *)0x0) goto LAB_14001c2e1;
  }
  else {
    lVar9 = 0x80;
    psVar4 = param_7;
    do {
      if (*psVar4 == 0) break;
      psVar4 = psVar4 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    uVar10 = -(ulonglong)(lVar9 != 0) & 0x80U - lVar9;
    if (lVar9 == 0) goto LAB_14001c2d9;
LAB_14001c2e1:
    if (uVar10 != 0) {
      plVar8 = _Dst + 0x26;
      lVar9 = 0x80;
      lVar11 = (longlong)param_7 - (longlong)plVar8;
      do {
        if ((lVar9 == -0x7fffff7e) || (sVar1 = *(short *)(lVar11 + (longlong)plVar8), sVar1 == 0))
        break;
        *(short *)plVar8 = sVar1;
        plVar8 = (longlong *)((longlong)plVar8 + 2);
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      goto LAB_14001c354;
    }
  }
  plVar8 = _Dst + 0x26;
  lVar9 = 0x80;
  lVar11 = (longlong)L"DefaultSubtask" - (longlong)plVar8;
  do {
    if ((lVar9 == -0x7fffff7e) || (sVar1 = *(short *)(lVar11 + (longlong)plVar8), sVar1 == 0))
    break;
    *(short *)plVar8 = sVar1;
    plVar8 = (longlong *)((longlong)plVar8 + 2);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
LAB_14001c354:
  plVar5 = (longlong *)((longlong)plVar8 + -2);
  if (lVar9 != 0) {
    plVar5 = plVar8;
  }
  *(short *)plVar5 = 0;
  if (param_8 != (longlong *)0x0) {
    lVar9 = param_8[1];
    _Dst[0x46] = *param_8;
    _Dst[0x47] = lVar9;
    lVar9 = param_8[3];
    _Dst[0x48] = param_8[2];
    _Dst[0x49] = lVar9;
    lVar9 = param_8[5];
    _Dst[0x4a] = param_8[4];
    _Dst[0x4b] = lVar9;
    lVar9 = param_8[7];
    _Dst[0x4c] = param_8[6];
    _Dst[0x4d] = lVar9;
    lVar9 = param_8[9];
    _Dst[0x4e] = param_8[8];
    _Dst[0x4f] = lVar9;
    lVar9 = param_8[0xb];
    _Dst[0x50] = param_8[10];
    _Dst[0x51] = lVar9;
    lVar9 = param_8[0xd];
    _Dst[0x52] = param_8[0xc];
    _Dst[0x53] = lVar9;
    lVar9 = param_8[0xf];
    _Dst[0x54] = param_8[0xe];
    _Dst[0x55] = lVar9;
    lVar9 = param_8[0x11];
    _Dst[0x56] = param_8[0x10];
    _Dst[0x57] = lVar9;
    lVar9 = param_8[0x13];
    _Dst[0x58] = param_8[0x12];
    _Dst[0x59] = lVar9;
    _Dst[0x5a] = param_8[0x14];
  }
  if (param_9 != (longlong *)0x0) {
    lVar9 = param_9[1];
    _Dst[0x5b] = *param_9;
    _Dst[0x5c] = lVar9;
    _Dst[0x5d] = param_9[2];
  }
  uVar10 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar10 == 0) {
    _Dst[0x5e] = 1;
    *(undefined4 *)(_Dst + 99) = 8;
    _Dst[0x5f] = 0;
    _Dst[0x60] = 0;
    _Dst[0x61] = 0;
    _Dst[0x62] = 0;
  }
  else {
    _Dst[0x69] = 0;
    plVar8 = _Dst + 0x68;
    _Dst[0x6a] = 0;
    _Dst[0x6b] = 0;
    _Dst[0x6c] = 0;
    _Dst[0x69] = (longlong)plVar8;
    *plVar8 = (longlong)plVar8;
    uVar6 = PdcpGetResiliencyThreshold(param_2);
    *(int *)(plVar8 + 2) = (int)uVar6;
    plVar8[3] = (longlong)PdcpActivationResiliencyRequestCallback;
    plVar8[4] = (longlong)_Dst;
  }
  uVar2 = *(uint *)(param_1 + 0x28);
  _Dst[0x65] = 0;
  _Dst[0x66] = 0;
  if (((_Dst + 6 != (longlong *)0x0) || (_Dst + 0x26 == (longlong *)0x0)) &&
     (puVar7 = PdcGetActivatorStats(uVar2), puVar7 != (undefined8 *)0x0)) {
    PdcpCreateActivationBlockerHeirarchy
              ((longlong)puVar7,(short *)(_Dst + 6),(short *)(_Dst + 0x26),_Dst + 0x65);
  }
  lVar9 = param_1 + 0xb0;
  _Dst[100] = 0;
  *(undefined4 *)((longlong)_Dst + 0x31c) = 0;
  *(undefined1 *)(_Dst + 0x67) = 1;
  plVar8 = *(longlong **)(param_1 + 0xb8);
  if (*plVar8 != lVar9) {
    plVar8 = (longlong *)0x3;
    pcVar3 = (code *)swi(0x29);
    lVar9 = (*pcVar3)();
  }
  *_Dst = lVar9;
  _Dst[1] = (longlong)plVar8;
  *plVar8 = (longlong)_Dst;
  *(longlong **)(lVar9 + 8) = _Dst;
  return _Dst;
}



===== PdcpDereferenceActivationInstance @ 14001c504 =====

void PdcpDereferenceActivationInstance(longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  
  uVar4 = param_2;
  uVar1 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    if ((int)param_2 != 0) {
      *(int *)(param_1 + 0x2f0) = (int)param_2;
    }
    *(undefined4 *)(param_1 + 0x2f4) = 0;
    uVar1 = (ulonglong)*(uint *)(param_1 + 0x318);
    if (*(uint *)(param_1 + 0x318) == 8) {
      uVar2 = PdcpGetResiliencyThreshold(*(int *)(param_1 + 0x18));
      uVar1 = (ulonglong)(int)uVar2;
      if (*(int *)(param_1 + 0x2f8 + uVar1 * 4) == 0) {
        return;
      }
    }
    lVar5 = (longlong)(int)uVar1;
    iVar3 = 2;
    if (-1 < (int)uVar1) {
      lVar6 = lVar5 * 4 + 8;
      do {
        uVar7 = (uint)uVar1;
        if (uVar7 != 6) {
          iVar3 = 3;
          if (uVar7 < 8) {
            PdcDereferenceActivationStats((longlong *)(param_1 + 0x328));
            uVar4 = uVar1 & 0xffffffff;
            uVar1 = PdcResiliencyClientDereference
                              (*(undefined8 *)(param_1 + 0x10),uVar7,
                               (ulonglong *)
                               (-(ulonglong)((*(byte *)(param_1 + 0x2d8U) & 7) != 0) &
                               param_1 + 0x2d8U));
            if (((int)uVar1 == 0) || ((int)uVar1 != 0x103)) {
              iVar3 = 0;
              *(undefined4 *)(lVar6 + 0x2f0 + param_1) = 0;
            }
            else {
              iVar3 = 1;
              *(undefined4 *)(lVar6 + 0x2f0 + param_1) = 1;
            }
          }
          else if ((DAT_140015c03 & 1) != 0) {
            McTemplateU0qzr0qzr2_EtwWriteTransfer
                      (3,uVar4,0x2b,L"PdcpDereferenceActivationInstanceResiliency");
            iVar3 = 3;
            goto LAB_14001c5cc;
          }
          if (iVar3 == 1) {
            *(uint *)(param_1 + 0x318) = uVar7;
            return;
          }
        }
LAB_14001c5cc:
        uVar1 = (ulonglong)(uVar7 - 1);
        lVar6 = lVar6 + -4;
        lVar5 = lVar5 + -1;
      } while (-1 < lVar5);
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x318) = 8;
      }
    }
  }
  else {
    PdcpGetActivationResiliencyStatus(param_1);
    PdcpResiliencyV2RequestCancel((longlong *)(param_1 + 0x340),*(undefined8 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x33c) = 0;
    PdcDereferenceActivationStats((longlong *)(param_1 + 0x328));
  }
  return;
}



===== PdcpFreeActivationInstance @ 14001c664 =====

void PdcpFreeActivationInstance(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    PdcFreeActivationStats(param_1 + 0x65);
    param_1[2] = ~param_1[2];
    ExFreePoolWithTag(param_1,0);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== PdcpGetActivationByType @ 14001c6bc =====

longlong * PdcpGetActivationByType(longlong param_1,int param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  plVar1 = (longlong *)(param_1 + 0xb0);
  plVar3 = (longlong *)0x0;
  plVar4 = (longlong *)*plVar1;
  if (plVar4 == plVar1) {
    plVar3 = (longlong *)0x0;
  }
  else {
    do {
      if (((char)plVar4[0x67] != '\0') && ((int)plVar4[3] == param_2)) {
        uVar2 = PdcpGetActivationResiliencyStatus((longlong)plVar4);
        if ((int)uVar2 == 0) {
          return plVar4;
        }
        plVar3 = plVar4;
      }
      plVar4 = (longlong *)*plVar4;
    } while (plVar4 != plVar1);
    plVar3 = (longlong *)(-(ulonglong)(plVar3 != (longlong *)0x0) & (ulonglong)plVar3);
  }
  return plVar3;
}



===== PdcpGetActivationResiliencyStatus @ 14001c730 =====

ulonglong PdcpGetActivationResiliencyStatus(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  int *piVar4;
  
  uVar1 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    uVar1 = 2;
    uVar2 = PdcpGetResiliencyThreshold(*(int *)(param_1 + 0x18));
    if (-1 < (int)uVar2) {
      uVar3 = 0;
      piVar4 = (int *)(param_1 + 0x2f8);
      do {
        if ((uVar3 != 6) && (uVar3 < 8)) {
          if (*piVar4 == 0) {
            uVar1 = 0;
            break;
          }
          if (*piVar4 == 1) {
            uVar1 = 1;
            break;
          }
        }
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 1;
      } while ((longlong)uVar3 <= (longlong)(int)uVar2);
    }
  }
  else {
    uVar1 = (ulonglong)*(uint *)(param_1 + 0x33c);
  }
  return uVar1 & 0xffffffff;
}



===== PdcpGetActivityTypeFromResiliencyType @ 14001c7a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 PdcpGetActivityTypeFromResiliencyType(uint param_1)

{
  undefined4 uVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_38 = 0x200000005;
  uStack_30 = 0x100000005;
  local_28 = 0x300000000;
  uStack_20 = 0x500000004;
  if (param_1 < 8) {
    uVar1 = *(undefined4 *)((longlong)&local_38 + (longlong)(int)param_1 * 4);
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}



===== PdcpGetEffectiveResiliencyType @ 14001c800 =====

int PdcpGetEffectiveResiliencyType(longlong param_1,int *param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  plVar1 = (longlong *)(param_1 + 0xb0);
  plVar4 = (longlong *)*plVar1;
  iVar5 = 0;
  iVar7 = 8;
  if (plVar4 != plVar1) {
    do {
      if ((char)plVar4[0x67] != '\0') {
        uVar2 = PdcpGetActivationResiliencyStatus((longlong)plVar4);
        if ((int)uVar2 != 0) {
          uVar3 = PdcpGetResiliencyThreshold((int)plVar4[3]);
          if (iVar5 <= (int)uVar3) {
            iVar5 = (int)uVar3;
          }
          iVar6 = iVar6 + 1;
        }
      }
      plVar4 = (longlong *)*plVar4;
    } while (plVar4 != plVar1);
    iVar7 = 8;
    if (iVar6 != 0) {
      iVar7 = iVar5;
    }
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar6;
  }
  return iVar7;
}



===== PdcpGetFirstRemoveReadyActivationInstance @ 14001c88c =====

undefined8 * PdcpGetFirstRemoveReadyActivationInstance(longlong param_1)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0xb0);
  while( true ) {
    if (puVar2 == (undefined8 *)(param_1 + 0xb0)) {
      return (undefined8 *)0x0;
    }
    if ((*(char *)(puVar2 + 0x67) == '\0') &&
       (uVar1 = PdcpGetActivationResiliencyStatus((longlong)puVar2), (int)uVar1 == 0)) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2;
}



===== PdcpGetResiliencyThreshold @ 14001c8e4 =====

undefined8 PdcpGetResiliencyThreshold(int param_1)

{
  if (param_1 == 0) {
    return 4;
  }
  if (param_1 == 1) {
    return 3;
  }
  if (param_1 == 2) {
    return 1;
  }
  if (param_1 == 3) {
    return 5;
  }
  if (param_1 == 4) {
    return 6;
  }
  return 8;
}



===== PdcpIsActivatorHoldingResiliency @ 14001c92c =====

undefined1 PdcpIsActivatorHoldingResiliency(longlong param_1)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0xb0);
  while( true ) {
    if (puVar2 == (undefined8 *)(param_1 + 0xb0)) {
      return 0;
    }
    uVar1 = PdcpGetActivationResiliencyStatus((longlong)puVar2);
    if ((int)uVar1 - 1U < 2) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return 1;
}



===== PdcpPreRevocationWorker @ 14001c980 =====

void PdcpPreRevocationWorker(longlong param_1)

{
  longlong lVar1;
  
  PdcAcquireLock();
  lVar1 = *(longlong *)(param_1 + 0xb8);
  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 800) == param_1)) {
    *(undefined8 *)(lVar1 + 800) = 0;
    PdcpV2SendCallbackMessage(lVar1,100);
    PdcpSetActivationInstanceTimerAction(lVar1,1);
  }
  ExFreePoolWithTag(param_1,0);
  PdcReleaseLock();
  return;
}



===== PdcpPrintActivationMessage @ 14001c9f4 =====

void PdcpPrintActivationMessage(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = 2;
  PdcPrint(2,"%s:Notification message (%p):\n\tStatus/Active:%08lx\n\tActivityType:%08lx\n",param_1,
           param_2);
  if ((Microsoft_Windows_PDCEnableBits & 2) != 0) {
    McTemplateU0pqq_EtwWriteTransfer
              (uVar1,&PDC_ACTIVATOR_MESSAGE,param_2,*(undefined4 *)(param_2 + 0x38),
               (char)*(undefined4 *)(param_2 + 0x3c));
  }
  return;
}



===== PdcpReceiveActivatorClient @ 14001ca54 =====

int PdcpReceiveActivatorClient(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined8 uVar3;
  char cVar4;
  longlong *plVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined8 *puVar10;
  int iVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined8 *puVar14;
  
  if ((Microsoft_Windows_PDCEnableBits & 2) != 0) {
    McTemplateU0pt_EtwWriteTransfer(param_1,&PDC_ACTIVATOR_RECEIVE,param_1,1);
  }
  PdcpPrintActivationMessage("PdcpReceiveActivatorClient",(longlong)param_2);
  uVar2 = *(uint *)((longlong)param_2 + 0x3c);
  plVar5 = (longlong *)0x0;
  cVar4 = *(char *)(param_2 + 7);
  if (((4 < uVar2) || (uVar2 == 4)) ||
     ((uVar2 == 3 &&
      (((0x7b < *(uint *)(param_1 + 0x28) - 1 ||
        (&PdcClientInfo + (ulonglong)*(uint *)(param_1 + 0x28) * 6 == (uint *)0x0)) ||
       (((&PdcClientInfo)[(ulonglong)*(uint *)(param_1 + 0x28) * 6] & 0x2000) == 0)))))) {
    iVar11 = -0x3ffffff3;
    goto LAB_14001cc57;
  }
  puVar10 = (undefined8 *)(param_1 + 0xb0);
  for (puVar12 = (undefined8 *)*puVar10; puVar12 != puVar10; puVar12 = (undefined8 *)*puVar12) {
    uVar6 = PdcpGetActivationResiliencyStatus((longlong)puVar12);
    if ((int)uVar6 == 1) {
      iVar11 = -0x3ffffff3;
      goto LAB_14001cc57;
    }
  }
  if (cVar4 == '\0') {
    plVar5 = PdcpGetActivationByType(param_1,uVar2);
    if (plVar5 != (longlong *)0x0) {
      uVar6 = PdcpGetActivationResiliencyStatus((longlong)plVar5);
      *(undefined1 *)(plVar5 + 0x67) = 0;
      uVar7 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar7 == 0) {
        if ((int)uVar6 == 2) {
LAB_14001cbff:
          PdcpDereferenceActivationInstance((longlong)plVar5,3);
        }
      }
      else if ((int)uVar6 != 0) goto LAB_14001cbff;
      uVar6 = PdcpGetActivationResiliencyStatus((longlong)plVar5);
      Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
      iVar11 = 0x103;
      if ((int)uVar6 == 0) {
        PdcpFreeActivationInstance(plVar5);
        iVar11 = 0;
      }
      cVar4 = PdcpIsActivatorHoldingResiliency(param_1);
      if (cVar4 == '\0') {
        PdcpCancelActivatorWatchdog(param_1);
      }
      if ((undefined8 *)*puVar10 == puVar10) {
        PdcpCancelActivatorClientVeto(param_1,0);
      }
      goto LAB_14001cc57;
    }
  }
  else {
    plVar5 = PdcpCreateActivationInstance
                       (param_1,uVar2,0,0,PdcCriticalActivatorTimeout,(short *)0x0,(short *)0x0,
                        (longlong *)0x0,(longlong *)0x0);
    if (plVar5 == (longlong *)0x0) {
      iVar11 = -0x3fffffe9;
      goto LAB_14001cc57;
    }
    cVar4 = PdcpIsActivationAllowed(param_1,uVar2);
    if (cVar4 != '\0') {
      PdcpReferenceActivationInstance((longlong)plVar5,2);
      uVar6 = PdcpGetActivationResiliencyStatus((longlong)plVar5);
      iVar11 = 0;
      if (((int)uVar6 != 2) && (iVar11 = 0, (int)uVar6 == 1)) {
        iVar11 = 0x103;
      }
      if (*(longlong *)(param_1 + 0x470) == 0) {
        PdcpSetActivatorWatchdog(param_1);
      }
      goto LAB_14001cc57;
    }
    if (*(longlong *)(param_1 + 0x480) != 0) {
      piVar1 = (int *)(*(longlong *)(param_1 + 0x480) + 0x54);
      *piVar1 = *piVar1 + 1;
    }
  }
  iVar11 = 0;
LAB_14001cc57:
  lVar9 = 6;
  puVar10 = (undefined8 *)(param_1 + 0x150);
  lVar13 = 0x80;
  puVar12 = puVar10;
  do {
    puVar14 = param_2;
    puVar8 = puVar12;
    uVar3 = puVar14[1];
    *puVar8 = *puVar14;
    puVar8[1] = uVar3;
    uVar3 = puVar14[3];
    puVar8[2] = puVar14[2];
    puVar8[3] = uVar3;
    uVar3 = puVar14[5];
    puVar8[4] = puVar14[4];
    puVar8[5] = uVar3;
    uVar3 = puVar14[7];
    puVar8[6] = puVar14[6];
    puVar8[7] = uVar3;
    uVar3 = puVar14[9];
    puVar8[8] = puVar14[8];
    puVar8[9] = uVar3;
    uVar3 = puVar14[0xb];
    puVar8[10] = puVar14[10];
    puVar8[0xb] = uVar3;
    uVar3 = puVar14[0xd];
    puVar8[0xc] = puVar14[0xc];
    puVar8[0xd] = uVar3;
    uVar3 = puVar14[0xf];
    puVar8[0xe] = puVar14[0xe];
    puVar8[0xf] = uVar3;
    lVar9 = lVar9 + -1;
    puVar12 = puVar8 + 0x10;
    param_2 = puVar14 + 0x10;
  } while (lVar9 != 0);
  uVar3 = puVar14[0x11];
  puVar8[0x10] = puVar14[0x10];
  puVar8[0x11] = uVar3;
  uVar3 = puVar14[0x13];
  puVar8[0x12] = puVar14[0x12];
  puVar8[0x13] = uVar3;
  if (iVar11 == 0) {
    *(undefined4 *)(param_1 + 0x188) = 0;
    PdcpPrintActivationMessage("PdcpReplyV1ActivationDeactivation",(longlong)puVar10);
    PdcpReplyActivatorClient(param_1,puVar10,lVar13);
  }
  else if (iVar11 == 0x103) {
    *(undefined4 *)((longlong)plVar5 + 0x31c) = 1;
  }
  return iVar11;
}



===== PdcpReferenceActivationInstance @ 14001cd24 =====

void PdcpReferenceActivationInstance(longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  
  uVar4 = param_2;
  PdcpGetActivationResiliencyStatus(param_1);
  uVar1 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    if ((int)param_2 != 0) {
      *(int *)(param_1 + 0x2f0) = (int)param_2;
    }
    uVar5 = *(uint *)(param_1 + 0x318);
    *(undefined4 *)(param_1 + 0x2f4) = 2;
    uVar2 = PdcpGetResiliencyThreshold(*(int *)(param_1 + 0x18));
    iVar3 = 0;
    if (uVar5 == 8) {
      uVar5 = 0;
    }
    lVar6 = (longlong)(int)uVar5;
    if (lVar6 <= (int)uVar2) {
      lVar7 = lVar6 * 4 + 8;
      uVar8 = uVar5;
      do {
        if (uVar5 != 6) {
          iVar3 = 3;
          if (uVar8 < 8) {
            PdcReferenceActivationStats((longlong *)(param_1 + 0x328));
            uVar4 = (ulonglong)uVar5;
            uVar1 = PdcResiliencyClientReference
                              (*(undefined8 *)(param_1 + 0x10),uVar5,
                               (ulonglong *)
                               (-(ulonglong)((*(byte *)(param_1 + 0x2d8U) & 7) != 0) &
                               param_1 + 0x2d8U));
            if ((int)uVar1 == 0) {
              *(undefined4 *)(lVar7 + 0x2f0 + param_1) = 2;
            }
            else if ((int)uVar1 == 0x103) {
              *(undefined4 *)(lVar7 + 0x2f0 + param_1) = 1;
            }
            iVar3 = *(int *)(lVar7 + 0x2f0 + param_1);
          }
          else if ((DAT_140015c03 & 1) != 0) {
            McTemplateU0qzr0qzr2_EtwWriteTransfer
                      (3,uVar4,0x29,L"PdcpReferenceActivationInstanceResiliency");
            iVar3 = 3;
            goto LAB_14001ce0a;
          }
          if (iVar3 == 1) {
            *(uint *)(param_1 + 0x318) = uVar5;
            return;
          }
        }
LAB_14001ce0a:
        uVar5 = uVar5 + 1;
        uVar8 = uVar8 + 1;
        lVar6 = lVar6 + 1;
        lVar7 = lVar7 + 4;
      } while (lVar6 <= (int)uVar2);
      if (iVar3 == 2) {
        *(undefined4 *)(param_1 + 0x318) = 8;
      }
    }
  }
  else {
    uVar5 = PdcpResiliencyV2RequestInitiate
                      ((undefined8 *)(param_1 + 0x340),*(undefined8 *)(param_1 + 0x10));
    PdcReferenceActivationStats((longlong *)(param_1 + 0x328));
    *(uint *)(param_1 + 0x33c) = 2 - (uint)(uVar5 != 0);
  }
  return;
}



===== PdcpReplyActivatorClient @ 14001cea8 =====

void PdcpReplyActivatorClient(longlong param_1,undefined8 param_2,longlong param_3)

{
  if ((Microsoft_Windows_PDCEnableBits & 2) != 0) {
    param_3 = param_1;
    McTemplateU0pt_EtwWriteTransfer(param_1,&PDC_ACTIVATOR_SEND,param_1,0);
  }
  if (*(char *)(param_1 + 0x18) == '\0') {
    PdcSendKernelMessage
              (*(longlong *)(param_1 + 0x20),(undefined8 *)(param_1 + 0x150),
               *(undefined4 *)(param_1 + 0x14));
  }
  else {
    PdcSendUserMessage(*(longlong *)(param_1 + 0x20),(undefined8 *)(param_1 + 0x150),
                       CONCAT71((int7)((ulonglong)param_3 >> 8),1));
  }
  return;
}



===== PdcpRevocationLiveDump @ 14001cf00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcpRevocationLiveDump(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  undefined1 auStack_a8 [32];
  longlong local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_58 = 0;
  bVar2 = false;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  if (*(char *)(lVar1 + 0x18) != '\0') {
    iVar3 = PsLookupProcessByProcessId
                      (*(undefined8 *)(*(longlong *)(lVar1 + 0x20) + 0x28),&local_58);
    if (iVar3 < 0) {
      return;
    }
    iVar3 = PsAcquireProcessExitSynchronization(local_58);
    if (iVar3 < 0) {
      return;
    }
    KeStackAttachProcess(local_58,&local_50);
    bVar2 = true;
  }
  local_68 = 1;
  local_70 = 0;
  local_78 = 0;
  local_88 = param_1;
  local_80 = param_2;
  DbgkWerCaptureLiveKernelDump(L"PDCRevocation",0x17d,*(undefined4 *)(lVar1 + 0x28),lVar1);
  if (bVar2) {
    KeUnstackDetachProcess(&local_50);
    PsReleaseProcessExitSynchronization(local_58);
  }
  return;
}



===== PdcpRevocationWorker @ 14001d030 =====

void PdcpRevocationWorker(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  undefined2 local_res8;
  longlong local_res10;
  longlong local_res18 [2];
  
  bVar6 = 0;
  local_res8 = 0;
  PdcAcquireLock();
  lVar2 = *(longlong *)(param_1 + 0xb8);
  if (((lVar2 != 0) && (*(longlong *)(lVar2 + 800) == param_1)) &&
     (*(undefined8 *)(lVar2 + 800) = 0, *(char *)(lVar2 + 0x338) != '\0')) {
    pbVar5 = (byte *)&local_res8;
    PdcIsClientProcessFrozen(*(longlong *)(lVar2 + 0x10),pbVar5);
    local_res8 = local_res8 & 0xff;
    local_res18[0] = 0;
    local_res10 = 0;
    if (*(char *)(*(longlong *)(lVar2 + 0x10) + 0x18) != '\0') {
      pbVar5 = (byte *)&local_res10;
      iVar4 = PdcpOpenClientProcessHandle
                        (*(undefined8 *)(*(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x20) + 0x28),
                         pbVar5);
      if (-1 < iVar4) {
        pbVar5 = (byte *)0x7;
        iVar4 = NtQueryInformationProcess(local_res10,7,local_res18,8,0);
        if (-1 < iVar4) {
          uVar3 = local_res8._1_1_;
          if (local_res18[0] != 0) {
            uVar3 = 1;
          }
          local_res8 = CONCAT11(uVar3,(byte)local_res8);
        }
      }
      if (local_res10 != 0) {
        NtClose();
      }
    }
    uVar1 = *(uint *)(*(longlong *)(lVar2 + 0x10) + 0x28);
    if (((uVar1 - 1 < 0x7c) && (&PdcClientInfo + (ulonglong)uVar1 * 6 != (uint *)0x0)) &&
       (((&PdcClientInfo)[(ulonglong)uVar1 * 6] & 0x4000) != 0)) {
      if ((byte)local_res8 == 0) {
        pbVar5 = (byte *)&local_res8;
        PdcpRevocationLiveDump(lVar2,pbVar5);
      }
      bVar6 = 1;
    }
    PdcpV2WriteActivationRevocationEvent(lVar2,pbVar5,bVar6,(byte *)&local_res8);
    PdcpEnforceActivationInstanceVeto(lVar2,3);
  }
  ExFreePoolWithTag(param_1,0);
  PdcReleaseLock();
  return;
}



===== PdcpSendMessageToActivatorClient @ 14001d184 =====

void PdcpSendMessageToActivatorClient(longlong param_1,undefined8 *param_2)

{
  if ((Microsoft_Windows_PDCEnableBits & 2) != 0) {
    McTemplateU0pt_EtwWriteTransfer(param_1,&PDC_ACTIVATOR_SEND,param_1,0);
  }
  if (*(char *)(param_1 + 0x18) == '\0') {
    PdcSendKernelMessage(*(longlong *)(param_1 + 0x20),param_2,*(undefined4 *)(param_1 + 0x14));
  }
  else {
    PdcSendUserMessage(*(longlong *)(param_1 + 0x20),param_2,0);
  }
  return;
}



===== PdcpSetActivationInstanceTimerAction @ 14001d1e4 =====

void PdcpSetActivationInstanceTimerAction(longlong param_1,int param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  if (*(longlong *)(param_1 + 800) == 0) {
    uVar2 = 1;
    if (param_2 == 0) {
      pcVar4 = PdcpPreRevocationWorker;
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    else {
      if (param_2 != 1) {
        return;
      }
      pcVar4 = PdcpRevocationWorker;
      uVar2 = 5;
      iVar3 = PdcActivatorClientResponseTimeout;
    }
    if ((iVar3 != 0) && (lVar1 = ExAllocatePool2(0x40,200), lVar1 != 0)) {
      *(int *)(lVar1 + 0xc0) = param_2;
      PdcInitializeTimer(lVar1,pcVar4,0,lVar1,uVar2);
      *(longlong *)(lVar1 + 0xb8) = param_1;
      *(longlong *)(param_1 + 800) = lVar1;
      PdcSetTimer(lVar1,(ulonglong)(uint)(iVar3 * 1000));
    }
  }
  return;
}



===== PdcpSetActivatorWatchdog @ 14001d2c0 =====

void PdcpSetActivatorWatchdog(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  
  if ((*(int *)(param_1 + 0x10) == 2) && (DAT_14003100c == 8)) {
    cVar1 = PdcpIsActivatorHoldingResiliency(param_1);
    if (cVar1 != '\0') {
      if (*(longlong *)(param_1 + 0x470) != 0) {
        PdcpCancelActivatorWatchdog(param_1);
      }
      lVar2 = ExAllocatePool2(0x40);
      if (lVar2 != 0) {
        PdcInitializeTimer(lVar2,PdcpActivationWatchdog,0,lVar2,5);
        *(longlong *)(param_1 + 0x470) = lVar2;
        *(longlong *)(lVar2 + 0xb8) = param_1;
        PdcSetTimer(lVar2,(ulonglong)(uint)(PdcCriticalActivatorTimeout * 1000));
      }
    }
  }
  return;
}



===== PdcpV2Activation @ 14001d36c =====

int PdcpV2Activation(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  char cVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  int iVar11;
  undefined8 *puVar12;
  longlong lVar13;
  int iVar14;
  
  PdcpPrintActivationMessage("PdcpV2Activation",(longlong)param_2);
  uVar2 = *(uint *)(param_2 + 9);
  iVar14 = 0;
  plVar7 = (longlong *)0x0;
  iVar11 = -0x3fffffff;
  if (uVar2 < 5) {
    if (uVar2 == 3) {
      if (((*(uint *)(param_1 + 0x28) - 1 < 0x7c) &&
          (&PdcClientInfo + (ulonglong)*(uint *)(param_1 + 0x28) * 6 != (uint *)0x0)) &&
         (((&PdcClientInfo)[(ulonglong)*(uint *)(param_1 + 0x28) * 6] & 0x2000) != 0)) {
LAB_14001d4e4:
        cVar5 = PdcpIsActivationAllowed(param_1,uVar2);
        if (cVar5 == '\0') {
          iVar11 = 0;
          iVar14 = 300;
          if (*(longlong *)(param_1 + 0x480) != 0) {
            piVar1 = (int *)(*(longlong *)(param_1 + 0x480) + 0x54);
            *piVar1 = *piVar1 + 1;
          }
        }
        else {
          plVar7 = PdcpCreateActivationInstance
                             (param_1,uVar2,param_2[10],*(undefined4 *)(param_2 + 0xb),
                              *(undefined4 *)((longlong)param_2 + 0x5c),(short *)(param_2 + 0xc),
                              (short *)(param_2 + 0x2c),param_2 + 0x4f,
                              (longlong *)
                              (-(ulonglong)((*(byte *)(param_2 + 0x4c) & 7) != 0) &
                              (ulonglong)(param_2 + 0x4c)));
          if (plVar7 == (longlong *)0x0) {
            iVar11 = -0x3fffffe9;
            iVar14 = 1;
          }
          else {
            PdcpReferenceActivationInstance((longlong)plVar7,4);
            uVar8 = PdcpGetActivationResiliencyStatus((longlong)plVar7);
            if ((int)uVar8 == 2) {
              iVar11 = 0;
            }
            else if ((int)uVar8 == 1) {
              iVar11 = 0x103;
            }
          }
        }
        goto LAB_14001d3ea;
      }
      goto LAB_14001d3df;
    }
    if ((uVar2 != 4) ||
       (((*(uint *)(param_1 + 0x28) - 1 < 0x7c &&
         (&PdcClientInfo + (ulonglong)*(uint *)(param_1 + 0x28) * 6 != (uint *)0x0)) &&
        (((&PdcClientInfo)[(ulonglong)*(uint *)(param_1 + 0x28) * 6] & 0x40000) != 0))))
    goto LAB_14001d4e4;
  }
  else {
LAB_14001d3df:
    iVar14 = 1;
  }
  iVar11 = -0x3ffffff3;
LAB_14001d3ea:
  lVar9 = 6;
  puVar10 = (undefined8 *)(param_1 + 0x150);
  lVar13 = 0x80;
  puVar4 = puVar10;
  do {
    puVar12 = param_2;
    puVar6 = puVar4;
    uVar3 = puVar12[1];
    *puVar6 = *puVar12;
    puVar6[1] = uVar3;
    uVar3 = puVar12[3];
    puVar6[2] = puVar12[2];
    puVar6[3] = uVar3;
    uVar3 = puVar12[5];
    puVar6[4] = puVar12[4];
    puVar6[5] = uVar3;
    uVar3 = puVar12[7];
    puVar6[6] = puVar12[6];
    puVar6[7] = uVar3;
    uVar3 = puVar12[9];
    puVar6[8] = puVar12[8];
    puVar6[9] = uVar3;
    uVar3 = puVar12[0xb];
    puVar6[10] = puVar12[10];
    puVar6[0xb] = uVar3;
    uVar3 = puVar12[0xd];
    puVar6[0xc] = puVar12[0xc];
    puVar6[0xd] = uVar3;
    uVar3 = puVar12[0xf];
    puVar6[0xe] = puVar12[0xe];
    puVar6[0xf] = uVar3;
    lVar9 = lVar9 + -1;
    puVar4 = puVar6 + 0x10;
    param_2 = puVar12 + 0x10;
  } while (lVar9 != 0);
  uVar3 = puVar12[0x11];
  puVar6[0x10] = puVar12[0x10];
  puVar6[0x11] = uVar3;
  uVar3 = puVar12[0x13];
  puVar6[0x12] = puVar12[0x12];
  puVar6[0x13] = uVar3;
  if (iVar11 == 0x103) {
    *(undefined4 *)((longlong)plVar7 + 0x31c) = 2;
    if ((*(byte *)(plVar7 + 4) & 2) != 0) {
      *(longlong *)(param_1 + 400) = plVar7[0x6e];
      *(undefined4 *)(param_1 + 0x188) = 0x103;
      *(int *)(param_1 + 0x18c) = iVar14;
      PdcpPrintActivationMessage("PdcpV2ReplyActivation",(longlong)puVar10);
      PdcpReplyActivatorClient(param_1,puVar10,lVar13);
    }
  }
  else {
    if (plVar7 == (longlong *)0x0) {
      lVar9 = 0;
    }
    else {
      lVar9 = plVar7[0x6e];
    }
    *(int *)(param_1 + 0x188) = iVar11;
    *(int *)(param_1 + 0x18c) = iVar14;
    *(longlong *)(param_1 + 400) = lVar9;
    PdcpPrintActivationMessage("PdcpV2ReplyActivation",(longlong)puVar10);
    PdcpReplyActivatorClient(param_1,puVar10,lVar13);
    if ((iVar11 == 0) && (iVar14 != 300)) {
      PdcpSetActivationInstanceTimerAction((longlong)plVar7,0);
    }
  }
  return iVar11;
}



===== PdcpV2Deactivation @ 14001d624 =====

int PdcpV2Deactivation(longlong param_1,undefined8 *param_2,longlong param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  int iVar9;
  undefined8 *puVar10;
  longlong lVar11;
  
  plVar1 = (longlong *)(param_1 + 0xb0);
  plVar8 = (longlong *)*plVar1;
  iVar9 = -0x3fffffff;
  lVar11 = 6;
  if (plVar8 != plVar1) {
    do {
      if (plVar8[0x6e] == param_2[8]) {
        if ((char)plVar8[0x67] != '\0') {
          if (plVar8 == (longlong *)0x0) goto LAB_14001d677;
          uVar6 = PdcpGetActivationResiliencyStatus((longlong)plVar8);
          iVar4 = (int)uVar6;
          if (((*(byte *)(plVar8 + 4) & 2) == 0) && (iVar4 == 1)) goto LAB_14001d677;
          uVar6 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar6 == 0) {
            if ((iVar4 != 2) && ((iVar4 != 1 || (*(int *)((longlong)plVar8 + 0x2f4) != 2))))
            goto LAB_14001d79d;
            PdcpDereferenceActivationInstance((longlong)plVar8,6);
            uVar6 = PdcpGetActivationResiliencyStatus((longlong)plVar8);
            if ((int)uVar6 == 0) goto LAB_14001d79d;
            if ((int)uVar6 == 1) {
              iVar9 = 0x103;
            }
          }
          else {
            if (iVar4 != 0) {
              PdcpDereferenceActivationInstance((longlong)plVar8,6);
              PdcpGetActivationResiliencyStatus((longlong)plVar8);
            }
LAB_14001d79d:
            iVar9 = 0;
          }
          PdcpCancelActivationInstanceTimerAction((longlong)plVar8);
          *(undefined1 *)(plVar8 + 0x67) = 0;
          goto LAB_14001d67c;
        }
        break;
      }
      plVar8 = (longlong *)*plVar8;
    } while (plVar8 != plVar1);
  }
  plVar8 = (longlong *)0x0;
LAB_14001d677:
  iVar9 = -0x3ffffff3;
LAB_14001d67c:
  puVar7 = (undefined8 *)(param_1 + 0x150);
  puVar3 = puVar7;
  do {
    puVar10 = param_2;
    puVar5 = puVar3;
    uVar2 = puVar10[1];
    *puVar5 = *puVar10;
    puVar5[1] = uVar2;
    uVar2 = puVar10[3];
    puVar5[2] = puVar10[2];
    puVar5[3] = uVar2;
    uVar2 = puVar10[5];
    puVar5[4] = puVar10[4];
    puVar5[5] = uVar2;
    uVar2 = puVar10[7];
    puVar5[6] = puVar10[6];
    puVar5[7] = uVar2;
    uVar2 = puVar10[9];
    puVar5[8] = puVar10[8];
    puVar5[9] = uVar2;
    uVar2 = puVar10[0xb];
    puVar5[10] = puVar10[10];
    puVar5[0xb] = uVar2;
    uVar2 = puVar10[0xd];
    puVar5[0xc] = puVar10[0xc];
    puVar5[0xd] = uVar2;
    uVar2 = puVar10[0xf];
    puVar5[0xe] = puVar10[0xe];
    puVar5[0xf] = uVar2;
    lVar11 = lVar11 + -1;
    puVar3 = puVar5 + 0x10;
    param_2 = puVar10 + 0x10;
  } while (lVar11 != 0);
  uVar2 = puVar10[0x11];
  puVar5[0x10] = puVar10[0x10];
  puVar5[0x11] = uVar2;
  uVar2 = puVar10[0x13];
  puVar5[0x12] = puVar10[0x12];
  puVar5[0x13] = uVar2;
  if (iVar9 == 0x103) {
    *(undefined4 *)((longlong)plVar8 + 0x31c) = 4;
    if ((*(byte *)(plVar8 + 4) & 2) == 0) {
      return 0x103;
    }
    *(undefined4 *)(param_1 + 0x188) = 0x103;
  }
  else {
    if (iVar9 == 0) {
      PdcpFreeActivationInstance(plVar8);
    }
    *(int *)(param_1 + 0x188) = iVar9;
  }
  PdcpPrintActivationMessage("PdcpV2ReplyDeactivation",(longlong)puVar7);
  PdcpReplyActivatorClient(param_1,puVar7,param_3);
  return iVar9;
}



===== PdcpV2Renew @ 14001d800 =====

undefined8 PdcpV2Renew(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  char cVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  longlong *plVar11;
  undefined8 *puVar12;
  int iVar13;
  longlong lVar14;
  int iVar15;
  
  PdcpPrintActivationMessage("PdcpV2Renew",(longlong)param_2);
  plVar2 = (longlong *)(param_1 + 0xb0);
  iVar15 = 0;
  plVar11 = (longlong *)*plVar2;
  iVar13 = -0x3fffffff;
  if (plVar11 != plVar2) {
    do {
      if (plVar11[0x6e] == param_2[9]) {
        if ((char)plVar11[0x67] != '\0') {
          if ((plVar11 == (longlong *)0x0) || ((param_2[8] & 2) != 0)) goto LAB_14001d867;
          if (((param_2[8] & 1) != 0) && (*(int *)((longlong)plVar11 + 0x36c) != 0)) {
            iVar15 = 0x12e;
            goto LAB_14001d872;
          }
          if ((*(byte *)(plVar11 + 4) & 2) == 0) {
            uVar8 = PdcpGetActivationResiliencyStatus((longlong)plVar11);
            if ((int)uVar8 == 1) {
              iVar15 = 0xc9;
              goto LAB_14001d872;
            }
          }
          uVar8 = param_2[8] | 2;
          if ((*(byte *)(plVar11 + 4) & 2) == 0) {
            uVar8 = param_2[8];
          }
          plVar11[4] = uVar8;
          *(undefined4 *)((longlong)plVar11 + 0x2c) = *(undefined4 *)(param_2 + 10);
          PdcRefDerefActivationStatsBySubtask
                    ((longlong)plVar11,(wchar_t *)((longlong)param_2 + 0x54));
          uVar8 = PdcpCancelActivationInstanceVeto((longlong)plVar11,3);
          iVar3 = (int)uVar8;
          cVar6 = PdcpIsActivationAllowed(param_1,(int)plVar11[3]);
          if (cVar6 == '\0') {
            iVar13 = 0;
            iVar15 = 300;
            if (*(longlong *)(param_1 + 0x480) != 0) {
              piVar1 = (int *)(*(longlong *)(param_1 + 0x480) + 0x54);
              *piVar1 = *piVar1 + 1;
            }
          }
          else {
            if (iVar3 == 0) {
              PdcpReferenceActivationInstance((longlong)plVar11,5);
              uVar8 = PdcpGetActivationResiliencyStatus((longlong)plVar11);
              iVar3 = (int)uVar8;
            }
            if (iVar3 == 2) {
              iVar13 = 0;
            }
            else {
              iVar13 = -0x3fffffff;
              if (iVar3 == 1) {
                iVar13 = 0x103;
              }
            }
            PdcpCancelActivationInstanceTimerAction((longlong)plVar11);
          }
          goto LAB_14001d872;
        }
        break;
      }
      plVar11 = (longlong *)*plVar11;
    } while (plVar11 != plVar2);
  }
  plVar11 = (longlong *)0x0;
LAB_14001d867:
  iVar15 = 1;
  iVar13 = -0x3ffffff3;
LAB_14001d872:
  lVar9 = 6;
  puVar10 = (undefined8 *)(param_1 + 0x150);
  lVar14 = 0x80;
  puVar5 = puVar10;
  do {
    puVar12 = param_2;
    puVar7 = puVar5;
    uVar4 = puVar12[1];
    *puVar7 = *puVar12;
    puVar7[1] = uVar4;
    uVar4 = puVar12[3];
    puVar7[2] = puVar12[2];
    puVar7[3] = uVar4;
    uVar4 = puVar12[5];
    puVar7[4] = puVar12[4];
    puVar7[5] = uVar4;
    uVar4 = puVar12[7];
    puVar7[6] = puVar12[6];
    puVar7[7] = uVar4;
    uVar4 = puVar12[9];
    puVar7[8] = puVar12[8];
    puVar7[9] = uVar4;
    uVar4 = puVar12[0xb];
    puVar7[10] = puVar12[10];
    puVar7[0xb] = uVar4;
    uVar4 = puVar12[0xd];
    puVar7[0xc] = puVar12[0xc];
    puVar7[0xd] = uVar4;
    uVar4 = puVar12[0xf];
    puVar7[0xe] = puVar12[0xe];
    puVar7[0xf] = uVar4;
    lVar9 = lVar9 + -1;
    puVar5 = puVar7 + 0x10;
    param_2 = puVar12 + 0x10;
  } while (lVar9 != 0);
  uVar4 = puVar12[0x11];
  puVar7[0x10] = puVar12[0x10];
  puVar7[0x11] = uVar4;
  uVar4 = puVar12[0x13];
  puVar7[0x12] = puVar12[0x12];
  puVar7[0x13] = uVar4;
  if (iVar13 == 0x103) {
    *(undefined4 *)((longlong)plVar11 + 0x31c) = 3;
    if ((*(byte *)(plVar11 + 4) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x188) = 0x103;
      *(int *)(param_1 + 0x18c) = iVar15;
      PdcpPrintActivationMessage("PdcpV2ReplyRenew",(longlong)puVar10);
      PdcpReplyActivatorClient(param_1,puVar10,lVar14);
    }
  }
  else {
    *(int *)(param_1 + 0x188) = iVar13;
    *(int *)(param_1 + 0x18c) = iVar15;
    PdcpPrintActivationMessage("PdcpV2ReplyRenew",(longlong)puVar10);
    PdcpReplyActivatorClient(param_1,puVar10,lVar14);
    if ((iVar13 == 0) && (iVar15 != 300)) {
      PdcpSetActivationInstanceTimerAction((longlong)plVar11,0);
    }
  }
  return 0;
}



===== PdcpV2SendCallbackMessage @ 14001da7c =====

void PdcpV2SendCallbackMessage(longlong param_1,undefined4 param_2)

{
  undefined8 local_328 [5];
  undefined4 local_300;
  undefined8 local_2f0;
  undefined4 local_2e8;
  
  memset(local_328,0,800);
  local_2f0 = *(undefined8 *)(param_1 + 0x370);
  local_300 = 0xc;
  local_2e8 = param_2;
  PdcpSendMessageToActivatorClient(*(longlong *)(param_1 + 0x10),local_328);
  return;
}



===== PdcpV2WriteActivationRevocationEvent @ 14001dae0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpV2WriteActivationRevocationEvent
               (longlong param_1,undefined8 param_2,byte param_3,byte *param_4)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStackY_128 [32];
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  undefined8 local_d8 [4];
  undefined4 *local_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  int local_a0;
  undefined4 local_9c;
  wchar_t *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  uint *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  local_e4 = (uint)param_3;
  if (5 < DAT_140031288) {
    if (((_DAT_140031298 & 0x400000000001) == 0) ||
       (bVar1 = true, (DAT_1400312a0 & 0x400000000001) != DAT_1400312a0)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_f8 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x28);
      local_a8 = (wchar_t *)(param_1 + 0x30);
      uVar4 = 2;
      local_b8 = &local_f8;
      local_b0 = 4;
      lVar2 = -1;
      if (local_a8 == (wchar_t *)0x0) {
        local_a8 = L"";
        local_a0 = 2;
      }
      else {
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (local_a8[lVar3] != L'\0');
        local_a0 = (int)lVar3 * 2 + 2;
      }
      local_98 = (wchar_t *)(param_1 + 0x130);
      local_9c = 0;
      if (local_98 == (wchar_t *)0x0) {
        local_98 = L"";
      }
      else {
        do {
          lVar2 = lVar2 + 1;
        } while (local_98[lVar2] != L'\0');
        uVar4 = (ulonglong)((int)lVar2 * 2 + 2);
      }
      local_f4 = *(undefined4 *)(param_1 + 0x18);
      local_88 = &local_f4;
      local_78 = &local_f0;
      local_90 = (undefined4)uVar4;
      local_8c = 0;
      local_80 = 4;
      local_f0 = 7;
      local_70 = 4;
      local_ec = *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20) + 0x28);
      local_68 = &local_ec;
      local_e8 = PdcActivatorClientResponseTimeout;
      local_58 = &local_e8;
      local_48 = &local_e4;
      local_e0 = (uint)*param_4;
      local_38 = &local_e0;
      local_dc = (uint)param_4[1];
      local_28 = &local_dc;
      local_60 = 4;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000e811,uVar4,param_4,0xc,local_d8);
    }
  }
  return;
}



===== PdcpWriteV1ActivationRevocationTelemetryEvent @ 14001dce0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpWriteV1ActivationRevocationTelemetryEvent
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  bool bVar2;
  uint uVar3;
  undefined1 auStackY_d8 [32];
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_98 [4];
  undefined8 local_88 [4];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (*(int *)(param_1 + 0x10) == 2) {
    local_a8 = 0;
    uVar1 = *(undefined4 *)(param_1 + 200);
    uVar3 = PdcpGetEffectiveResiliencyType(param_1,&local_a8);
    local_98[0] = PdcpGetActivityTypeFromResiliencyType(uVar3);
    if (5 < DAT_140031288) {
      if (((_DAT_140031298 & 0x400000000001) == 0) ||
         ((DAT_1400312a0 & 0x400000000001) != DAT_1400312a0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        local_a4 = *(undefined4 *)(param_1 + 0x28);
        local_5c = 0;
        local_4c = 0;
        local_3c = 0;
        local_2c = 0;
        local_1c = 0;
        local_68 = &local_a4;
        local_58 = &local_a0;
        local_9c = PdcCriticalActivatorTimeout;
        local_48 = &local_9c;
        local_38 = local_98;
        local_28 = &local_a8;
        local_60 = 4;
        local_50 = 4;
        local_40 = 4;
        local_30 = 4;
        local_20 = 4;
        local_a0 = uVar1;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x140031288,&DAT_14000e903,(ulonglong)local_98[0],param_4,7,local_88);
      }
    }
  }
  return;
}



===== PdcSetGlobalActivatorsVeto @ 14001de28 =====

void PdcSetGlobalActivatorsVeto(char param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  undefined8 *puVar1;
  
  if (param_1 == '\0') {
    PdcGlobalActivatorsVetoBitset = PdcGlobalActivatorsVetoBitset & 0xfffffffb;
  }
  else {
    PdcGlobalActivatorsVetoBitset = PdcGlobalActivatorsVetoBitset | 4;
  }
  Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  for (puVar1 = PdcActivators; (undefined8 **)puVar1 != &PdcActivators;
      puVar1 = (undefined8 *)*puVar1) {
    if (*(char *)((longlong)puVar1 + 0xc4) != '\0') {
      if (param_1 == '\0') {
        if ((*(uint *)(puVar1 + 0x18) & 4) != 0) {
          PdcpCancelActivatorClientVeto((longlong)puVar1,2);
          PdcpWriteGlobalActivatorVetoTelemetryEvent((longlong)puVar1,0,param_3,param_4);
        }
      }
      else if ((*(uint *)(puVar1 + 0x18) & 4) == 0) {
        PdcpWriteGlobalActivatorVetoTelemetryEvent((longlong)puVar1,1,param_3,param_4);
        param_3 = 0;
        PdcpEnforceActivatorClientVeto((longlong)puVar1,2,0,param_4);
      }
    }
  }
  return;
}



===== PdcpCancelActivationInstanceVeto @ 14001ded4 =====

ulonglong PdcpCancelActivationInstanceVeto(longlong param_1,int param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  lVar6 = (longlong)param_2;
  uVar4 = PdcpGetActivationResiliencyStatus(param_1);
  uVar4 = uVar4 & 0xffffffff;
  uVar5 = 1 << ((byte)param_2 & 0x1f);
  iVar1 = *(int *)(&DAT_14000a18c + lVar6 * 0x18);
  iVar2 = *(int *)(&DAT_14000a190 + lVar6 * 0x18);
  if ((uVar5 & *(uint *)(param_1 + 0x36c)) != 0) {
    uVar5 = ~uVar5 & *(uint *)(param_1 + 0x36c);
    *(uint *)(param_1 + 0x36c) = uVar5;
    if ((uVar5 == 0) &&
       (((*(undefined4 *)(param_1 + 0x368) = 0, *(int *)(lVar3 + 0x10) == 2 || (iVar1 == -1)) ||
        (iVar2 == 0)))) {
      PdcpReferenceActivationInstance(param_1,(ulonglong)*(uint *)(&DAT_14000a194 + lVar6 * 0x18));
      uVar4 = PdcpGetActivationResiliencyStatus(param_1);
      uVar4 = uVar4 & 0xffffffff;
    }
    if (((*(int *)(lVar3 + 0x10) == 7) && (iVar1 != -1)) && (iVar2 != 0)) {
      PdcpV2SendCallbackMessage(param_1,iVar1);
    }
  }
  return uVar4;
}



===== PdcpCancelActivatorClientVeto @ 14001dfa0 =====

void PdcpCancelActivatorClientVeto(longlong param_1,int param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  
  if (*(char *)(param_1 + 0xc4) != '\0') {
    uVar1 = 1 << ((byte)param_2 & 0x1f);
    if (((uVar1 & *(uint *)(param_1 + 0xc0)) != 0) && (*(int *)(param_1 + 0x28) != 0x12)) {
      *(uint *)(param_1 + 0xc0) = ~uVar1 & *(uint *)(param_1 + 0xc0);
      for (puVar2 = *(undefined8 **)(param_1 + 0xb0); puVar2 != (undefined8 *)(param_1 + 0xb0);
          puVar2 = (undefined8 *)*puVar2) {
        if (*(char *)(puVar2 + 0x67) != '\0') {
          PdcpCancelActivationInstanceVeto((longlong)puVar2,param_2);
        }
      }
    }
  }
  return;
}



===== PdcpEnforceActivationInstanceVeto @ 14001e024 =====

ulonglong PdcpEnforceActivationInstanceVeto(longlong param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  
  lVar8 = (longlong)param_2;
  uVar6 = PdcpGetActivationResiliencyStatus(param_1);
  lVar5 = *(longlong *)(param_1 + 0x10);
  uVar7 = uVar6 & 0xffffffff;
  if (*(int *)(lVar5 + 0x28) != 0x12) {
    uVar9 = 1 << ((byte)param_2 & 0x1f);
    *(uint *)(param_1 + 0x36c) = *(uint *)(param_1 + 0x36c) | uVar9;
    uVar2 = *(uint *)(&DAT_14000a188 + lVar8 * 0x18);
    if ((int)uVar6 == 2) {
      if ((*(longlong *)(lVar5 + 0x480) != 0) && (param_2 == 1)) {
        piVar1 = (int *)(*(longlong *)(lVar5 + 0x480) + 0x54);
        *piVar1 = *piVar1 + 1;
      }
      *(uint *)(param_1 + 0x368) = *(uint *)(param_1 + 0x368) | uVar9;
      PdcpDereferenceActivationInstance(param_1,(ulonglong)uVar2);
      uVar7 = PdcpGetActivationResiliencyStatus(param_1);
      uVar7 = uVar7 & 0xffffffff;
    }
    if (((*(int *)(lVar5 + 0x10) != 2) &&
        (iVar3 = *(int *)(&PdcVetoConfig + lVar8 * 0x18), iVar3 != -1)) &&
       (iVar4 = *(int *)(&DAT_14000a184 + lVar8 * 0x18), iVar4 != 0)) {
      PdcpCancelActivationInstanceTimerAction(param_1);
      if ((int)uVar7 == 0) {
        PdcpV2SendCallbackMessage(param_1,iVar3);
      }
      else if ((int)uVar7 == 1) {
        *(int *)(param_1 + 0x31c) = iVar4;
      }
    }
  }
  return uVar7;
}



===== PdcpEnforceActivatorClientVeto @ 14001e110 =====

void PdcpEnforceActivatorClientVeto
               (longlong param_1,int param_2,undefined8 param_3,longlong param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  char cVar3;
  char cVar4;
  undefined7 uVar5;
  
  cVar3 = (char)param_3;
  uVar5 = (undefined7)((ulonglong)param_3 >> 8);
  if (*(char *)(param_1 + 0xc4) == '\0') {
    return;
  }
  uVar1 = *(uint *)(param_1 + 0x28);
  if (uVar1 == 0x12) {
    return;
  }
  if ((((uVar1 - 1 < 0x7c) && (&PdcClientInfo + (ulonglong)uVar1 * 6 != (uint *)0x0)) &&
      (param_2 == 2)) && (((&PdcClientInfo)[(ulonglong)uVar1 * 6] & 0x20000) != 0)) {
    return;
  }
  uVar1 = 1 << ((byte)param_2 & 0x1f);
  *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | uVar1;
  cVar4 = cVar3;
  if ((cVar3 == '\0') ||
     ((PdcpAcquireReleaseResiliencyBias(param_1,'\x01',param_3,param_4),
      *(char *)(param_1 + 0xc4) != '\0' && ((*(uint *)(param_1 + 0xc0) & uVar1) != 0)))) {
    if (param_2 != 2) {
      PdcpCancelActivatorWatchdog(param_1);
    }
    for (puVar2 = *(undefined8 **)(param_1 + 0xb0); puVar2 != (undefined8 *)(param_1 + 0xb0);
        puVar2 = (undefined8 *)*puVar2) {
      if (*(char *)(puVar2 + 0x67) != '\0') {
        PdcpEnforceActivationInstanceVeto((longlong)puVar2,param_2);
      }
    }
    if (cVar3 == '\0') {
      return;
    }
  }
  PdcpAcquireReleaseResiliencyBias(param_1,'\0',CONCAT71(uVar5,cVar4),param_4);
  return;
}



===== PdcpIsActivationAllowed @ 14001e208 =====

undefined1 PdcpIsActivationAllowed(longlong param_1,int param_2)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  
  uVar3 = 1;
  if (*(int *)(param_1 + 0x28) != 0x12) {
    if (*(int *)(param_1 + 0xc0) == 0) {
      if (param_2 == 0) {
        bVar1 = 4;
      }
      else if (param_2 == 1) {
        bVar1 = 8;
      }
      else if (param_2 == 2) {
        bVar1 = 0x10;
      }
      else if (param_2 == 3) {
        bVar1 = 2;
      }
      else {
        bVar1 = 0x20;
      }
      for (puVar2 = AllEaRules; (undefined8 **)puVar2 != &AllEaRules; puVar2 = (undefined8 *)*puVar2
          ) {
        if ((*(int *)(puVar2 + 2) == 2) &&
           ((*(byte *)((longlong)*(int *)(param_1 + 0x28) + 0x28 + (longlong)puVar2) & bVar1) != 0))
        goto LAB_14001e26b;
      }
    }
    else {
LAB_14001e26b:
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== PdcpWriteGlobalActivatorVetoTelemetryEvent @ 14001e27c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpWriteGlobalActivatorVetoTelemetryEvent
               (longlong param_1,byte param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined1 auStackY_b8 [32];
  int local_88;
  undefined4 local_84;
  uint local_80;
  uint local_7c;
  undefined8 local_78 [4];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_88 = 0;
  uVar2 = PdcpGetEffectiveResiliencyType(param_1,&local_88);
  local_7c = PdcpGetActivityTypeFromResiliencyType(uVar2);
  if (5 < DAT_140031288) {
    if (((_DAT_140031298 & 0x400000000001) == 0) ||
       ((DAT_1400312a0 & 0x400000000001) != DAT_1400312a0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_84 = *(undefined4 *)(param_1 + 0x28);
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_58 = &local_84;
      local_48 = &local_80;
      local_38 = &local_7c;
      local_28 = &local_88;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_20 = 4;
      local_80 = (uint)param_2;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140031288,&DAT_14000e99a,(ulonglong)local_7c,param_4,6,local_78);
    }
  }
  return;
}



===== PdcAudioPolicyEvaluationWorker @ 14001e3a0 =====

void PdcAudioPolicyEvaluationWorker
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  
  PdcAcquireLock();
  while ((DAT_140015bc4 & 1) != 0) {
    DAT_140015bc4 = DAT_140015bc4 & 0xfffffffe;
    cVar1 = '\0';
    if ((PdcAudioPolicyContext != '\0') && (cVar1 = '\0', DAT_140015bc1 != '\0')) {
      cVar1 = '\x01';
    }
    if (cVar1 != DAT_140015bc2) {
      PdcReleaseLock();
      PdcActivationClientActivityRequest(param_1,1,cVar1,param_4);
      PdcAcquireLock();
      DAT_140015bc2 = cVar1;
    }
  }
  DAT_140015bc4 = DAT_140015bc4 & 0xfffffffd;
  PdcReleaseLock();
  return;
}



===== PdcAudioPolicyHandleAudioActiveWnf @ 14001e430 =====

int PdcAudioPolicyHandleAudioActiveWnf
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined4 local_res20 [2];
  int local_18 [2];
  undefined8 local_10;
  
  local_10 = 0;
  local_res20[0] = param_4;
  PdcAcquireLock();
  local_18[0] = 8;
  iVar3 = ExQueryWnfStateData(param_1,local_res20,&local_10,local_18);
  if (-1 < iVar3) {
    if (local_18[0] == 8) {
      bVar2 = (byte)((uint)local_10 >> 1) & 1;
      uVar1 = DAT_140015bc4;
      if (bVar2 != PdcAudioPolicyContext) {
        PdcAudioPolicyContext = bVar2;
        uVar1 = DAT_140015bc4 | 1;
        if ((DAT_140015bc4 & 2) == 0) {
          DAT_140015bc4 = DAT_140015bc4 | 3;
          ExQueueWorkItem(&DAT_140015bc8);
          uVar1 = DAT_140015bc4;
        }
      }
      DAT_140015bc4 = uVar1;
      iVar3 = 0;
    }
    else {
      iVar3 = -0x3ffffdfa;
    }
  }
  PdcReleaseLock();
  return iVar3;
}



===== PdcClientPolicyRundown @ 14001e4e4 =====

void PdcClientPolicyRundown(void)

{
  bool bVar1;
  short *psVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 in_stack_ffffffffffffffe0;
  
  puVar4 = AllEaRules;
  if ((undefined8 **)AllEaRules != &AllEaRules) {
    do {
      psVar2 = (short *)((longlong)puVar4 + 0xa6);
      if (psVar2 != (short *)0x0) {
        lVar3 = 0x80;
        do {
          if (*psVar2 == 0) break;
          psVar2 = psVar2 + 1;
          lVar3 = lVar3 + -1;
        } while (lVar3 != 0);
        if ((lVar3 != 0) && ((DAT_140015c03 & 4) != 0)) {
          bVar1 = *(int *)(puVar4 + 2) - 2U < 2;
          McTemplateU0qzr0tqUR3_EtwWriteTransfer
                    ((ulonglong)bVar1,lVar3,-(ulonglong)(lVar3 != 0) & 0x80U - lVar3,
                     (longlong)puVar4 + 0xa6,bVar1,in_stack_ffffffffffffffe0,puVar4 + 5);
        }
      }
      puVar4 = (undefined8 *)*puVar4;
    } while ((undefined8 **)puVar4 != &AllEaRules);
  }
  return;
}



===== PdcpArmEaRules @ 14001e590 =====

void PdcpArmEaRules(void)

{
  short *psVar1;
  uint uVar2;
  short *psVar3;
  char *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 in_stack_ffffffffffffffd0;
  
  PdcAcquireLock();
  puVar6 = AllEaRules;
  if ((undefined8 **)AllEaRules != &AllEaRules) {
    do {
      if (puVar6[4] != 0) {
        psVar1 = (short *)((longlong)puVar6 + 0xa6);
        if (psVar1 != (short *)0x0) {
          lVar5 = 0x80;
          psVar3 = psVar1;
          do {
            if (*psVar3 == 0) break;
            psVar3 = psVar3 + 1;
            lVar5 = lVar5 + -1;
          } while (lVar5 != 0);
          if ((lVar5 != 0) && ((DAT_140015c03 & 4) != 0)) {
            McTemplateU0qzr0tqUR3_EtwWriteTransfer
                      (0x80U - lVar5,lVar5,-(ulonglong)(lVar5 != 0) & 0x80U - lVar5,psVar1,0,
                       in_stack_ffffffffffffffd0,puVar6 + 5);
          }
        }
        uVar2 = 0;
        pcVar4 = (char *)(puVar6 + 5);
        do {
          if (*pcVar4 != '\0') goto LAB_14001e635;
          uVar2 = uVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (uVar2 < 0x7d);
        if (uVar2 != 0x7d) {
LAB_14001e635:
          in_stack_ffffffffffffffd0 = 0;
          EaCreateAggregatedEvent
                    (puVar6[4],0,PdcpEaStartPolicyEvent,PdcpEaStopPolicyEvent,0,0,puVar6,0,
                     puVar6 + 3);
        }
        EaFreeAggregatedEventParameters(puVar6[4]);
        puVar6[4] = 0;
      }
      puVar6 = (undefined8 *)*puVar6;
    } while ((undefined8 **)puVar6 != &AllEaRules);
  }
  PdcReleaseLock();
  return;
}



===== PdcpClientPolicyDisableEaRule @ 14001e6b0 =====

void PdcpClientPolicyDisableEaRule(longlong param_1)

{
  bool bVar1;
  
  if (*(int *)(param_1 + 0x10) == 2) {
    bVar1 = VetoClientWorkItemPending == '\0';
    *(undefined4 *)(param_1 + 0x10) = 3;
    if (bVar1) {
      VetoClientWorkItemPending = '\x01';
      ExQueueWorkItem(&VetoClientWorkItem,1);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}



===== PdcpClientPolicyEnableEaRule @ 14001e6fc =====

void PdcpClientPolicyEnableEaRule(longlong param_1)

{
  bool bVar1;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    bVar1 = VetoClientWorkItemPending == '\0';
    *(undefined4 *)(param_1 + 0x10) = 1;
    if (bVar1) {
      VetoClientWorkItemPending = '\x01';
      ExQueueWorkItem(&VetoClientWorkItem);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 2;
  }
  return;
}



===== PdcpConfigureClientPolicyWorker @ 14001e750 =====

void PdcpConfigureClientPolicyWorker(void)

{
  uint uVar1;
  undefined8 uVar2;
  
  PdcAcquireLock();
  if (UmpoScmWnfSubscription == 0) {
    PdcReleaseLock();
  }
  else {
    ExUnsubscribeWnfStateChange();
    UmpoScmWnfSubscription = 0;
    PdcReleaseLock();
    uVar1 = PdcpEnumerateEaRules();
    if (-1 < (int)uVar1) {
      uVar2 = PdcpEnumerateBuiltinClientPolicies();
      if (-1 < (int)uVar2) {
        PdcpEnumerateClientPolicies();
        PdcpArmEaRules();
      }
    }
  }
  return;
}



===== PdcpEaStartPolicyEvent @ 14001e7b0 =====

void PdcpEaStartPolicyEvent(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  PdcAcquireLock();
  PdcpClientPolicyEnableEaRule(param_3);
  PdcReleaseLock();
  return;
}



===== PdcpEnumerateBuiltinClientPolicies @ 14001e7d8 =====

undefined8 PdcpEnumerateBuiltinClientPolicies(void)

{
  short sVar1;
  code *pcVar2;
  undefined8 *puVar3;
  short *psVar4;
  ulonglong uVar5;
  short *psVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong lVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar9 = 0x40;
  puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x128,0x70636470);
  puVar11 = auStack_28;
  uVar13 = 0;
  if (puVar3 == (undefined8 *)0x0) {
    uVar13 = 0xc000009a;
  }
  else {
    psVar6 = (short *)((longlong)puVar3 + 0xa6);
    *(undefined4 *)(puVar3 + 2) = 0;
    lVar8 = (longlong)L"EA:AusterityExperiment" - (longlong)psVar6;
    do {
      if ((lVar9 == -0x7fffffbe) || (sVar1 = *(short *)(lVar8 + (longlong)psVar6), sVar1 == 0))
      break;
      *psVar6 = sVar1;
      psVar6 = psVar6 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    uVar12 = 0;
    pbVar10 = (byte *)(puVar3 + 5);
    psVar4 = psVar6 + -1;
    if (lVar9 != 0) {
      psVar4 = psVar6;
    }
    *psVar4 = 0;
    do {
      uVar5 = Feature_PoAdaptiveStandby__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        if ((uVar12 - 0x79 & 0xfffffffd) == 0) goto LAB_14001e87c;
LAB_14001e88d:
        if ((uVar12 == 0x44) || (uVar12 == 0x78)) {
          *pbVar10 = *pbVar10 | 0x1e;
        }
        else {
          *pbVar10 = 0x1f;
        }
      }
      else {
        if (((uVar12 - 0x79 & 0xfffffffc) != 0) || (uVar12 == 0x7a)) goto LAB_14001e88d;
LAB_14001e87c:
        *pbVar10 = *pbVar10 | 1;
      }
      uVar12 = uVar12 + 1;
      pbVar10 = pbVar10 + 1;
    } while (uVar12 < 0x7d);
    PdcAcquireLock();
    puVar7 = &AllEaRules;
    if ((undefined8 *)*DAT_140015b58 != &AllEaRules) {
      puVar7 = (undefined8 *)0x3;
      pcVar2 = (code *)swi(0x29);
      DAT_140015b58 = (undefined8 *)(*pcVar2)();
      puVar11 = auStack_20;
    }
    *puVar3 = puVar7;
    puVar3[1] = DAT_140015b58;
    *DAT_140015b58 = puVar3;
    *(undefined8 *)(puVar11 + -8) = 0x14001e8e5;
    DAT_140015b58 = puVar3;
    PdcpAusterityModeClientPolicy = puVar3;
    PdcReleaseLock();
  }
  return uVar13;
}



===== PdcpEnumerateClientPolicies @ 14001e904 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcpEnumerateClientPolicies(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  wchar_t **ppwVar5;
  int iVar6;
  undefined1 auStack_a8 [32];
  longlong *local_88;
  undefined4 *local_80;
  longlong local_78;
  undefined4 local_70 [2];
  int local_68 [2];
  wchar_t *local_60 [4];
  wchar_t local_40 [16];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70[0] = 0;
  piVar4 = local_68;
  local_60[0] = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\PDC\\Activators";
  ppwVar5 = local_60;
  local_68[0] = 7;
  local_60[1] = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\PDC\\TaskClients";
  uVar3 = 0;
  local_68[1] = 4;
  do {
    local_78 = 0;
    local_88 = &local_78;
    iVar1 = PdcOpenRegistryKey(*ppwVar5);
    if (iVar1 < 0) break;
    iVar1 = *piVar4;
    PdcpEnumerateVetoPolicies(iVar1,L"Default");
    iVar6 = 0;
    while( true ) {
      local_80 = local_70;
      local_88 = (longlong *)CONCAT44(local_88._4_4_,0x30);
      local_60[2] = (wchar_t *)0x0;
      local_60[3] = (wchar_t *)0x0;
      local_40[0] = L'\0';
      local_40[1] = L'\0';
      local_40[2] = L'\0';
      local_40[3] = L'\0';
      local_40[4] = L'\0';
      local_40[5] = L'\0';
      local_40[6] = L'\0';
      local_40[7] = L'\0';
      local_40[8] = L'\0';
      local_40[9] = L'\0';
      local_40[10] = L'\0';
      local_40[0xb] = L'\0';
      local_40[0xc] = L'\0';
      local_40[0xd] = L'\0';
      local_40[0xe] = L'\0';
      local_40[0xf] = L'\0';
      iVar2 = ZwEnumerateKey(local_78,iVar6,0,local_60 + 2);
      if (iVar2 == -0x7fffffe6) break;
      if ((-1 < iVar2) && (iVar2 = _wcsnicmp(local_40,L"Default",0xc), iVar2 != 0)) {
        PdcpEnumerateVetoPolicies(iVar1,local_40);
      }
      iVar6 = iVar6 + 1;
    }
    ZwClose();
    uVar3 = uVar3 + 1;
    ppwVar5 = ppwVar5 + 1;
    local_78 = 0;
    piVar4 = piVar4 + 1;
  } while (uVar3 < 2);
  if (local_78 != 0) {
    ZwClose();
  }
  return;
}



===== PdcpEnumerateEaRules @ 14001ea80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PdcpEnumerateEaRules(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  undefined8 *_Dst;
  short *psVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  longlong lVar11;
  bool bVar12;
  undefined1 auStack_108 [8];
  undefined1 auStack_100 [24];
  longlong *local_e8;
  undefined4 *local_e0;
  longlong local_d8;
  undefined4 local_d0 [2];
  longlong local_c8;
  undefined8 local_c0;
  short *psStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 local_98 [16];
  short local_88 [48];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_108;
  local_e8 = &local_c8;
  local_d8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_d0[0] = 0;
  local_c0 = 0;
  psStack_b8 = (short *)0x0;
  local_c8 = 0;
  uVar3 = PdcOpenRegistryKey(
                            L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\PDC\\VetoPolicy\\EA"
                            );
  puVar9 = auStack_108;
  if (-1 < (int)uVar3) {
    iVar10 = 0;
    memset(local_98,0,0x66);
    local_e0 = local_d0;
    local_e8 = (longlong *)CONCAT44(local_e8._4_4_,0x66);
    iVar4 = ZwEnumerateKey(local_c8,0,0,local_98);
    puVar8 = auStack_108;
    while (puVar9 = auStack_108, iVar4 != -0x7fffffe6) {
      if (-1 < iVar4) {
        psVar5 = local_88;
        local_c0 = 0;
        psStack_b8 = (short *)0x0;
        lVar7 = 0x7fff;
        do {
          if (*psVar5 == 0) break;
          psVar5 = psVar5 + 1;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        if (lVar7 != 0) {
          sVar1 = (0x7fff - (short)lVar7) * 2;
          local_c0 = (ulonglong)CONCAT22(sVar1 + 2,sVar1);
          psStack_b8 = local_88;
        }
        if ((((int)-(uint)(lVar7 != 0) < 0) && (iVar4 = RtlGUIDFromString(&local_c0), -1 < iVar4))
           && (iVar4 = EaQueryAggregatedEventParameters(local_c8,&local_b0,&local_d8), -1 < iVar4))
        {
          psVar5 = *(short **)(local_d8 + 0x38);
          if (psVar5 != (short *)0x0) {
            lVar7 = 0x3f;
            do {
              if (*psVar5 == 0) break;
              psVar5 = psVar5 + 1;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            if (lVar7 != 0) {
              _Dst = (undefined8 *)ExAllocatePool2(0x40,0x128,0x70636470);
              if (_Dst != (undefined8 *)0x0) {
                memset(_Dst,0,0x128);
                lVar7 = 0x40;
                _Dst[4] = local_d8;
                psVar5 = (short *)((longlong)_Dst + 0xa6);
                lVar11 = *(longlong *)(local_d8 + 0x38) - (longlong)psVar5;
                do {
                  if ((lVar7 == -0x7fffffbe) ||
                     (sVar1 = *(short *)(lVar11 + (longlong)psVar5), sVar1 == 0)) break;
                  *psVar5 = sVar1;
                  psVar5 = psVar5 + 1;
                  lVar7 = lVar7 + -1;
                } while (lVar7 != 0);
                psVar6 = psVar5 + -1;
                if (lVar7 != 0) {
                  psVar6 = psVar5;
                }
                *psVar6 = 0;
                if (lVar7 == 0) {
                  ExFreePoolWithTag(_Dst);
                  goto LAB_14001ecd4;
                }
                PdcAcquireLock();
                if ((undefined8 **)*DAT_140015b58 == &AllEaRules) {
                  *_Dst = &AllEaRules;
                  _Dst[1] = DAT_140015b58;
                  *DAT_140015b58 = _Dst;
                  DAT_140015b58 = _Dst;
                  PdcReleaseLock();
                  goto LAB_14001ece0;
                }
                pcVar2 = (code *)swi(0x29);
                (*pcVar2)(3);
                puVar8 = auStack_100;
              }
              *(undefined8 *)(puVar8 + -8) = 0x14001ed36;
              EaFreeAggregatedEventParameters(local_d8);
              puVar9 = puVar8;
              break;
            }
          }
LAB_14001ecd4:
          EaFreeAggregatedEventParameters(local_d8);
        }
      }
LAB_14001ece0:
      iVar10 = iVar10 + 1;
      memset(local_98,0,0x66);
      local_e0 = local_d0;
      local_e8 = (longlong *)CONCAT44(local_e8._4_4_,0x66);
      iVar4 = ZwEnumerateKey(local_c8,iVar10,0,local_98);
    }
    *(undefined8 *)(puVar9 + -8) = 0x14001ed40;
    PdcAcquireLock();
    bVar12 = (undefined8 **)AllEaRules == &AllEaRules;
    *(undefined8 *)(puVar9 + -8) = 0x14001ed4f;
    PdcReleaseLock();
    uVar3 = -(uint)bVar12 & 0x80000022;
  }
  if (local_c8 != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x14001ed69;
    ZwClose();
  }
  *(undefined8 *)(puVar9 + -8) = 0x14001ed7c;
  return uVar3;
}



===== PdcpEnumerateVetoPolicies @ 14001eda4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcpEnumerateVetoPolicies(int param_1,STRSAFE_LPCWSTR param_2)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined1 auStack_1e8 [32];
  int local_1c8;
  uint local_1c4;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  wchar_t local_1a8 [192];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1e8;
  PdcAcquireLock();
  puVar5 = AllEaRules;
  do {
    if ((undefined8 **)puVar5 == &AllEaRules) {
      PdcReleaseLock();
      return;
    }
    local_1c4 = 0;
    local_1c8 = 0;
    if (param_2 == L"Default") {
LAB_14001ee4c:
      memset(local_1a8,0,0x180);
      PdcpGetVetoPolicyRegPath(param_1,param_2,local_1a8);
      PdcGetRegistryDwordValue(local_1a8,(longlong)puVar5 + 0xa6,0xffffffff,&local_1c8);
      if (local_1c8 != -1) {
        if (param_1 == 4) {
          bVar3 = 1;
        }
        else if (local_1c8 == 1) {
LAB_14001eebb:
          bVar3 = 0x1e;
        }
        else if (local_1c8 == 2) {
          bVar3 = 0xe;
        }
        else if (local_1c8 == 3) {
          bVar3 = 6;
        }
        else {
          if (local_1c8 != 4) goto LAB_14001eebb;
          bVar3 = 2;
        }
        if (local_1c4 == 0) {
          if (local_1c8 != 0) {
            pbVar2 = (byte *)(puVar5 + 5);
            lVar4 = 0x7d;
            do {
              *pbVar2 = *pbVar2 | bVar3;
              pbVar2 = pbVar2 + 1;
              lVar4 = lVar4 + -1;
            } while (lVar4 != 0);
          }
        }
        else if (local_1c8 == 0) {
          pbVar2 = (byte *)((ulonglong)local_1c4 + 0x28 + (longlong)puVar5);
          *pbVar2 = *pbVar2 & ~bVar3;
        }
        else {
          pbVar2 = (byte *)((ulonglong)local_1c4 + 0x28 + (longlong)puVar5);
          *pbVar2 = *pbVar2 | bVar3;
        }
      }
    }
    else {
      local_1c0 = 0;
      uStack_1b8 = 0;
      iVar1 = RtlInitUnicodeStringEx(&local_1c0);
      if ((-1 < iVar1) && (iVar1 = RtlUnicodeStringToInteger(&local_1c0,10,&local_1c4), -1 < iVar1))
      goto LAB_14001ee4c;
    }
    puVar5 = (undefined8 *)*puVar5;
  } while( true );
}



===== PdcpGetVetoPolicyRegPath @ 14001ef30 =====

void PdcpGetVetoPolicyRegPath(int param_1,STRSAFE_LPCWSTR param_2,STRSAFE_LPWSTR param_3)

{
  wchar_t wVar1;
  STRSAFE_LPWSTR pwVar2;
  STRSAFE_LPCWSTR cbDest;
  STRSAFE_LPWSTR pwVar3;
  longlong lVar4;
  wchar_t *pwVar5;
  
  pwVar5 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\PDC\\TaskClients";
  if (param_1 != 4) {
    pwVar5 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\PDC\\Activators";
  }
  lVar4 = 0xc0;
  pwVar3 = param_3;
  do {
    if ((lVar4 == -0x7fffff3e) ||
       (wVar1 = *(wchar_t *)(((longlong)pwVar5 - (longlong)param_3) + (longlong)pwVar3),
       wVar1 == L'\0')) break;
    *pwVar3 = wVar1;
    pwVar3 = pwVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  pwVar2 = pwVar3 + -1;
  if (lVar4 != 0) {
    pwVar2 = pwVar3;
  }
  *pwVar2 = L'\0';
  cbDest = param_2;
  StringCbCatW(param_3,(size_t)param_2,L"\\");
  StringCbCatW(param_3,(size_t)cbDest,param_2);
  StringCbCatW(param_3,(size_t)cbDest,L"\\");
  StringCbCatW(param_3,(size_t)cbDest,L"VetoPolicy");
  return;
}



===== PdcpVetoClientWorker @ 14001efe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcpVetoClientWorker(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  byte *_Dst;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  byte *pbVar8;
  short *in_R9;
  uint7 uVar9;
  longlong lVar10;
  undefined1 auStack_c8 [32];
  byte local_98 [128];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  PdcAcquireLock();
  if (VetoClientWorkItemActive == '\0') {
    VetoClientWorkItemActive = 1;
    while (VetoClientWorkItemPending != '\0') {
      VetoClientWorkItemPending = '\0';
      _Dst = local_98;
      memset(_Dst,0,0x7d);
      for (puVar7 = AllEaRules; (undefined8 **)puVar7 != &AllEaRules; puVar7 = (undefined8 *)*puVar7
          ) {
        uVar2 = *(uint *)(puVar7 + 2);
        uVar5 = (ulonglong)uVar2;
        uVar9 = (uint7)((ulonglong)in_R9 >> 8);
        in_R9 = (short *)CONCAT71(uVar9,1);
        if (uVar2 == 1) {
          *(undefined4 *)(puVar7 + 2) = 2;
          uVar5 = 2;
LAB_14001f09b:
          _Dst = local_98;
          lVar10 = 0x7d;
          do {
            *_Dst = *_Dst | _Dst[(longlong)puVar7 + (0x28 - (longlong)local_98)];
            _Dst = _Dst + 1;
            lVar10 = lVar10 + -1;
          } while (lVar10 != 0);
          if ((char)in_R9 != '\0') {
LAB_14001f0c6:
            in_R9 = (short *)((longlong)puVar7 + 0xa6);
            if (in_R9 != (short *)0x0) {
              lVar10 = 0x80;
              psVar4 = in_R9;
              do {
                if (*psVar4 == 0) break;
                psVar4 = psVar4 + 1;
                lVar10 = lVar10 + -1;
              } while (lVar10 != 0);
              _Dst = (byte *)(0x80 - lVar10);
              if ((lVar10 != 0) && ((DAT_140015c03 & 4) != 0)) {
                McTemplateU0qzr0t_EtwWriteTransfer
                          (_Dst,uVar5,-(ulonglong)(lVar10 != 0) & (ulonglong)_Dst,in_R9,
                           (int)uVar5 == 2);
              }
            }
          }
        }
        else {
          if (uVar2 == 3) {
            *(undefined4 *)(puVar7 + 2) = 0;
            uVar5 = 0;
            goto LAB_14001f0c6;
          }
          in_R9 = (short *)((ulonglong)uVar9 << 8);
          if (uVar2 == 2) goto LAB_14001f09b;
        }
      }
      PdcReleaseLock();
      PdcActivationClientActivityRequest(_Dst,3,'\x01',(longlong)in_R9);
      PdcAcquireLock();
      for (puVar7 = PdcActivators; (undefined8 **)puVar7 != &PdcActivators;
          puVar7 = (undefined8 *)*puVar7) {
        if ((*(char *)((longlong)puVar7 + 0xc4) != '\0') &&
           (uVar2 = *(uint *)(puVar7 + 5), uVar2 != 0x12)) {
          pbVar1 = (byte *)(puVar7 + 0x16);
          pbVar8 = *(byte **)pbVar1;
          if (pbVar8 != pbVar1) {
            do {
              if (pbVar8[0x338] != 0) {
                iVar3 = *(int *)(pbVar8 + 0x18);
                if (iVar3 == 0) {
                  _Dst = (byte *)0x4;
                }
                else if (iVar3 == 1) {
                  _Dst = &DAT_00000008;
                }
                else if (iVar3 == 2) {
                  _Dst = &DAT_00000010;
                }
                else if (iVar3 == 3) {
                  _Dst = (byte *)0x2;
                }
                else {
                  _Dst = (byte *)0x20;
                }
                if ((local_98[uVar2] & (byte)_Dst) == 0) {
                  if ((*(uint *)(pbVar8 + 0x36c) & 2) != 0) {
                    _Dst = pbVar8;
                    PdcpCancelActivationInstanceVeto((longlong)pbVar8,1);
                  }
                }
                else if ((*(uint *)(pbVar8 + 0x36c) & 2) == 0) {
                  _Dst = pbVar8;
                  PdcpEnforceActivationInstanceVeto((longlong)pbVar8,1);
                }
              }
              pbVar8 = *(byte **)pbVar8;
            } while (pbVar8 != pbVar1);
          }
        }
      }
      PdcReleaseLock();
      puVar7 = (undefined8 *)0x0;
      uVar6 = 3;
      PdcActivationClientActivityRequest(_Dst,3,'\0',(longlong)in_R9);
      PdcAcquireLock();
      PdcTaskClientRevocationMaskUpdate((longlong)local_98,uVar6,puVar7,(ulonglong)in_R9);
    }
    VetoClientWorkItemActive = '\0';
    VetoClientWorkItemPending = '\0';
  }
  PdcReleaseLock();
  return;
}



===== PdcpWnfScmPhaseCallback @ 14001f280 =====

undefined8
PdcpWnfScmPhaseCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_res20 [2];
  int local_18 [6];
  
  local_18[0] = 0;
  local_18[1] = 4;
  local_res20[0] = param_4;
  iVar1 = ExQueryWnfStateData(param_1,local_res20,local_18,local_18 + 1);
  if ((-1 < iVar1) && (local_18[0] == 2)) {
    PdcAcquireLock();
    if (UmpoScmWnfSubscription != 0) {
      ExQueueWorkItem(&ConfigureClientPolicyWorkItem,1);
    }
    PdcReleaseLock();
  }
  return 0;
}



===== PdcpAlpcProcessMessages @ 14001f300 =====

void PdcpAlpcProcessMessages(void)

{
  ulonglong uVar1;
  
  uVar1 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    PdcpAlpcProcessMessagesV1();
  }
  else {
    PdcpAlpcProcessMessagesV2();
  }
  return;
}



===== PdcProcessMessage @ 14001f328 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcProcessMessage(undefined8 *param_1,longlong *param_2)

{
  longlong *plVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  longlong *plVar8;
  ushort uVar9;
  char *pcVar10;
  longlong lVar11;
  undefined1 *puVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined8 *puVar15;
  longlong *plVar16;
  undefined1 auStack_448 [8];
  undefined1 auStack_440 [24];
  undefined1 *local_428;
  longlong *local_420;
  undefined8 *local_418;
  undefined8 local_410;
  undefined1 local_408;
  longlong local_3f8;
  ulonglong local_3f0;
  longlong *local_3e8;
  undefined4 local_3e0;
  undefined4 local_3dc;
  undefined8 local_3d8;
  undefined8 local_3d0;
  undefined4 local_3c8;
  undefined4 local_3c4;
  undefined8 local_3c0;
  undefined8 uStack_3b8;
  char local_3a8 [800];
  undefined1 local_88 [16];
  undefined8 local_78;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_448;
  local_3f8 = 0;
  local_3dc = 0;
  local_3c4 = 0;
  memset(local_3a8,0,800);
  puVar12 = auStack_448;
  uVar9 = *(ushort *)((longlong)param_1 + 4);
  uVar13 = uVar9 & 0xffff00ff;
  puVar14 = (undefined4 *)(ulonglong)uVar13;
  if (uVar13 == 1) {
    pcVar10 = local_3a8;
    lVar11 = *param_2;
    uVar7 = PdcSanitizeClientMessage
                      (param_1,(int)*(short *)((longlong)param_1 + 2),(undefined8 *)pcVar10);
    puVar12 = auStack_448;
    if ((int)uVar7 != 0) {
      pcVar10 = "LPC_REQUEST";
      goto LAB_14001f778;
    }
    if ((&DAT_14000a830)[*(uint *)(*(longlong *)(lVar11 + 0x20) + 0x10)] != '\0') {
      uVar13 = PdcProcessReceivedUserMessage(lVar11,local_3a8,(longlong)pcVar10,(ulonglong)puVar14);
      puVar12 = auStack_448;
      if (-1 < (int)uVar13) goto LAB_14001f7ee;
    }
    iVar6 = ZwAlpcCancelMessage(PdcServerPort,0,param_2);
    puVar12 = auStack_448;
    if (-1 < iVar6) goto LAB_14001f7ee;
    puVar14 = (undefined4 *)(ulonglong)*(uint *)((longlong)param_2 + 0x14);
    pcVar10 = "%s: Unable to cancel ALPC message id=%x\n";
LAB_14001f7dd:
    puVar12 = auStack_448;
  }
  else {
    if (uVar13 != 3) {
      if (uVar13 == 5) {
        puVar4 = (undefined4 *)*param_2;
        puVar14 = puVar4;
        PdcPrint(2,"%s: A client (%p) stopped.\n","PdcProcessMessage",puVar4);
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(&PdcAlpcPushLock,0);
        local_3f8 = *(longlong *)(puVar4 + 6);
        plVar8 = (longlong *)(puVar4 + 2);
        *(undefined8 *)(puVar4 + 6) = 0;
        lVar11 = *plVar8;
        if ((*(longlong **)(lVar11 + 8) == plVar8) &&
           (plVar16 = *(longlong **)(puVar4 + 4), (longlong *)*plVar16 == plVar8)) {
          *plVar16 = lVar11;
          *(longlong **)(lVar11 + 8) = plVar16;
          PdcReleaseAlpcPushLock();
          PdcFreeClient(*(longlong **)(puVar4 + 8));
          ZwClose(local_3f8);
          puVar12 = auStack_448;
          goto LAB_14001f7ee;
        }
      }
      else {
        if ((uVar13 == 6) || (uVar13 != 10)) {
          pcVar10 = "%s: Not expecting message type=0x%x\n";
          goto LAB_14001f7dd;
        }
        local_420 = (longlong *)&local_3e0;
        local_3e8 = (longlong *)0x0;
        puVar15 = (undefined8 *)0x0;
        local_428 = (undefined1 *)CONCAT44(local_428._4_4_,0x400);
        local_3f0 = 0;
        local_3e0 = 0x30;
        param_2 = (longlong *)0x0;
        local_3d8 = 0;
        plVar16 = (longlong *)0x0;
        local_3c8 = 0x200;
        local_3d0 = 0;
        local_3c0 = 0;
        uStack_3b8 = 0;
        uVar13 = ZwAlpcOpenSenderProcess(&local_3f0,PdcServerPort,param_1);
        if (-1 < (int)uVar13) {
          uVar7 = PdcSanitizeClientMessage
                            (param_1,(int)*(short *)((longlong)param_1 + 2),(undefined8 *)local_3a8)
          ;
          uVar13 = (uint)uVar7;
          if (uVar13 == 0) {
            uVar13 = PdcValidateClient((longlong)local_3a8,local_3f0);
            if (uVar13 == 0) {
              uVar13 = PdcAllocateUserClient
                                 ((longlong)local_3a8,local_3f0,(longlong *)&local_3e8,puVar15);
              plVar16 = local_3e8;
              if (-1 < (int)uVar13) {
                param_2 = (longlong *)local_3e8[4];
              }
            }
          }
          else {
            MicrosoftTelemetryAssertTriggeredArgsMsgKM
                      ("LPC_CONNECTION_REQUEST",9,(int)*(short *)((longlong)param_1 + 2),
                       "PdcSanitizeClientMessage failed");
          }
          ZwClose(local_3f0);
        }
        local_3e0 = 0x30;
        local_3d8 = 0;
        local_3c8 = 0x200;
        local_3d0 = 0;
        local_3c0 = 0;
        uStack_3b8 = 0;
        memset(local_88,0,0x48);
        local_78 = 800;
        local_3f8 = 0;
        if (param_2 == (longlong *)0x0) {
          local_420 = (longlong *)(longlong)(int)uVar13;
          plVar8 = &local_3f8;
        }
        else {
          plVar8 = param_2 + 3;
          local_420 = param_2;
        }
        local_408 = param_2 != (longlong *)0x0;
        puVar14 = &local_3e0;
        local_410 = 0;
        local_428 = local_88;
        local_418 = param_1;
        iVar6 = ZwAlpcAcceptConnectPort(plVar8,PdcServerPort,0);
        puVar12 = auStack_448;
        if (iVar6 < 0) {
          local_408 = 0;
          local_410 = 0;
          local_420 = (longlong *)(longlong)iVar6;
          local_428 = local_88;
          local_418 = param_1;
          ZwAlpcAcceptConnectPort(&local_3f8,PdcServerPort,0,&local_3e0);
          puVar12 = auStack_448;
          if (param_2 != (longlong *)0x0) {
            PdcFreeClient(plVar16);
            puVar12 = auStack_448;
          }
          goto LAB_14001f7ee;
        }
        if (param_2 == (longlong *)0x0) goto LAB_14001f7ee;
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(&PdcAlpcPushLock,0);
        plVar1 = param_2 + 1;
        plVar8 = DAT_140015ae8;
        if ((undefined *)*DAT_140015ae8 == &PdcClientPorts) {
          *plVar1 = (longlong)&PdcClientPorts;
          param_2[2] = (longlong)DAT_140015ae8;
          *DAT_140015ae8 = (longlong)plVar1;
          DAT_140015ae8 = plVar1;
          PdcReleaseAlpcPushLock();
          PdcPrint(2,"%s: A client connected, port context=%p\n","PdcProcessMessage",param_2);
          PdcPostprocessClient(plVar16);
          puVar12 = auStack_448;
          goto LAB_14001f7ee;
        }
      }
      uVar9 = (ushort)plVar8;
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar12 = auStack_440;
    }
    lVar11 = *param_2;
    if ((uVar9 >> 0xd & 1) == 0) {
      if ((&DAT_14000a830)[*(uint *)(*(longlong *)(lVar11 + 0x20) + 0x10)] != '\0')
      goto LAB_14001f7ee;
      sVar2 = *(short *)((longlong)param_1 + 2);
      pcVar10 = local_3a8;
      *(undefined8 *)(puVar12 + -8) = 0x14001f73c;
      uVar7 = PdcSanitizeClientMessage(param_1,(int)sVar2,(undefined8 *)pcVar10);
      if ((int)uVar7 == 0) {
        *(undefined8 *)(puVar12 + -8) = 0x14001f755;
        PdcProcessReceivedUserMessage(lVar11,local_3a8,(longlong)pcVar10,(ulonglong)puVar14);
        goto LAB_14001f7ee;
      }
      pcVar10 = "LPC_DATAGRAM";
LAB_14001f778:
      uVar3 = *(undefined4 *)(*(longlong *)(lVar11 + 0x20) + 0x10);
      sVar2 = *(short *)((longlong)param_1 + 2);
      *(undefined8 *)(puVar12 + -8) = 0x14001f790;
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                (pcVar10,uVar3,(int)sVar2,"PdcSanitizeClientMessage failed");
      goto LAB_14001f7ee;
    }
    uVar13 = *(uint *)((longlong)param_2 + 0x14);
    *(undefined8 *)(puVar12 + -8) = 0x14001f6e2;
    PdcPrint(1,"%s: ALPC message id=%x required continuation unexpectedly. Cancelling it.\n",
             "PdcProcessMessage",(ulonglong)uVar13);
    *(undefined8 *)(puVar12 + -8) = 0x14001f6f5;
    iVar6 = ZwAlpcCancelMessage(PdcServerPort,0,param_2);
    if (-1 < iVar6) goto LAB_14001f7ee;
    puVar14 = (undefined4 *)(ulonglong)*(uint *)((longlong)param_2 + 0x14);
    pcVar10 = "%s: Unable to cancel ALPC message id=%x\n";
  }
  *(undefined8 *)(puVar12 + -8) = 0x14001f7ee;
  PdcPrint(1,pcVar10,"PdcProcessMessage",puVar14);
LAB_14001f7ee:
  *(undefined8 *)(puVar12 + -8) = 0x14001f7fd;
  return;
}



===== PdcReleaseAlpcPushLock @ 14001f820 =====

void PdcReleaseAlpcPushLock(void)

{
  ExReleasePushLockEx(&PdcAlpcPushLock,0);
  KeLeaveCriticalRegion();
  return;
}



===== PdcSendUserMessage @ 14001f854 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PdcSendUserMessage(longlong param_1,undefined8 *param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_398 [32];
  undefined8 local_378;
  undefined8 local_370;
  undefined8 local_368;
  undefined8 local_360;
  uint local_358 [4];
  ulonglong local_348 [100];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_398;
  local_358[0] = 0;
  cVar1 = (char)param_3;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&PdcAlpcPushLock,0);
  if (param_1 == 0) {
    uVar4 = 0xc0000037;
  }
  else if (*(longlong *)(param_1 + 0x18) == 0) {
    uVar4 = 0xc0000042;
  }
  else {
    *(undefined4 *)((longlong)param_2 + 0x2c) =
         *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x14);
    uVar3 = PdcFormatMessageToClientVersion(param_2,local_348,param_3,local_358);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 == 0) {
      if (cVar1 == '\0') {
        local_348[4] = 0;
        local_348[1] = 0;
        local_348[0] = (ulonglong)CONCAT22((short)local_358[0],(short)local_358[0] + -0x28);
        local_348[2] = 0;
        local_348[3] = 0;
      }
      local_360 = 0;
      local_368 = 0;
      local_370 = 0;
      local_378 = 0;
      uVar2 = ZwAlpcSendWaitReceivePort(*(undefined8 *)(param_1 + 0x18),0x10000,local_348,0);
      uVar4 = (ulonglong)uVar2;
    }
    else {
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                ("PdcSendUserMessage",*(undefined4 *)((longlong)param_2 + 0x2c),local_358[0],
                 "PdcFormatMessageToClientVersion failed");
    }
  }
  PdcReleaseAlpcPushLock();
  return uVar4;
}



===== PdcpAlpcMessageLockAcquire @ 14001f998 =====

void PdcpAlpcMessageLockAcquire(longlong param_1)

{
  code *pcVar1;
  longlong *plVar2;
  undefined1 *puVar3;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  void *pvStack_10;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  pvStack_10 = (void *)0x0;
  if (*(longlong *)(param_1 + 0x38) == 0) {
    *(void **)(param_1 + 0x38) = SystemReserved1[0xf];
    PdcReleaseAlpcPushLock();
  }
  else {
    pvStack_10 = SystemReserved1[0xf];
    KeInitializeEvent(&local_28,0,0);
    puVar3 = auStack_68;
    plVar2 = *(longlong **)(param_1 + 0x48);
    if (*plVar2 != param_1 + 0x40) {
      pcVar1 = (code *)swi(0x29);
      plVar2 = (longlong *)(*pcVar1)(3);
      puVar3 = auStack_60;
    }
    *(longlong **)(puVar3 + 0x38) = plVar2;
    *(longlong *)(puVar3 + 0x30) = param_1 + 0x40;
    *plVar2 = (longlong)(puVar3 + 0x30);
    *(undefined1 **)(param_1 + 0x48) = puVar3 + 0x30;
    *(undefined8 *)(puVar3 + -8) = 0x14001fa1d;
    PdcReleaseAlpcPushLock();
    *(undefined8 *)(puVar3 + 0x20) = 0;
    *(undefined8 *)(puVar3 + -8) = 0x14001fa37;
    KeWaitForSingleObject(puVar3 + 0x40,0,0,0);
  }
  return;
}



===== PdcpAlpcMessageLockRelease @ 14001fa4c =====

void PdcpAlpcMessageLockRelease(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&PdcAlpcPushLock,0);
  plVar1 = (longlong *)(param_1 + 0x40);
  plVar2 = (longlong *)*plVar1;
  if (plVar2 != plVar1) {
    if (((longlong *)plVar2[1] == plVar1) &&
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) == plVar2)) {
      *plVar1 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar1;
      *(longlong *)(param_1 + 0x38) = plVar2[5];
      KeSetEvent(plVar2 + 2,0,0);
      return;
    }
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  return;
}



===== PdcpAlpcProcessClientConnection @ 14001fad0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PdcpAlpcProcessClientConnection(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  char *pcVar8;
  undefined1 auStack_138 [32];
  undefined1 *local_118;
  undefined8 *local_110;
  undefined8 *local_108;
  undefined8 local_100;
  undefined1 local_f8;
  ulonglong local_e8;
  longlong *local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8 [2];
  undefined1 local_98 [16];
  undefined8 local_88;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_138;
  local_d8 = 0x30;
  puVar1 = (undefined8 *)(param_1 + 0xa0);
  local_a8[0] = 0;
  local_110 = &local_d8;
  local_c0 = 0x200;
  puVar6 = (undefined8 *)(param_1 + 0x3c0);
  local_118 = (undefined1 *)CONCAT44(local_118._4_4_,0x400);
  local_e0 = (longlong *)0x0;
  pcVar8 = (char *)0x0;
  local_e8 = 0;
  local_d0 = 0;
  plVar7 = (longlong *)0x0;
  local_c8 = 0;
  bVar2 = false;
  local_b8 = 0;
  uStack_b0 = 0;
  uVar3 = ZwAlpcOpenSenderProcess(&local_e8,PdcServerPort,puVar1);
  uVar5 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar4 = PdcSanitizeClientMessage(puVar1,(int)*(short *)(param_1 + 0xa2),puVar6);
    uVar5 = uVar4 & 0xffffffff;
    if ((int)uVar4 != 0) {
      pcVar8 = "PdcSanitizeClientMessage failed";
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                ("LPC_CONNECTION_REQUEST",9,(int)*(short *)(param_1 + 0xa2),
                 "PdcSanitizeClientMessage failed");
      if ((int)uVar4 < 0) goto LAB_14001fcac;
    }
    uVar3 = PdcValidateClient((longlong)puVar6,local_e8);
    uVar5 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      if ((8 < *(uint *)(param_1 + 0x3fc)) ||
         ((0x148U >> (*(uint *)(param_1 + 0x3fc) & 0x1f) & 1) == 0)) {
        PdcAcquireLock();
        bVar2 = true;
      }
      uVar3 = PdcAllocateUserClient
                        ((longlong)puVar6,local_e8,(longlong *)&local_e0,(undefined8 *)pcVar8);
      plVar7 = local_e0;
      uVar5 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        puVar6 = (undefined8 *)local_e0[4];
        local_d8 = CONCAT44(local_d8._4_4_,0x30);
        local_d0 = 0;
        local_c0 = CONCAT44(local_c0._4_4_,0x200);
        local_c8 = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        memset(local_98,0,0x48);
        local_118 = local_98;
        local_f8 = 1;
        local_100 = 0;
        local_88 = 800;
        local_110 = puVar6;
        local_108 = puVar1;
        uVar3 = ZwAlpcAcceptConnectPort(puVar6 + 3,PdcServerPort,0,&local_d8);
        uVar5 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          PdcPrint(2,"%s: A client connected, port context=%p\n","PdcpAlpcProcessClientConnection",
                   puVar6);
          PdcPostprocessClient(plVar7);
          uVar5 = 0;
          goto LAB_14001fd33;
        }
      }
    }
  }
LAB_14001fcac:
  local_a8[0] = 0;
  local_d8 = CONCAT44(local_d8._4_4_,0x30);
  local_d0 = 0;
  local_c0 = CONCAT44(local_c0._4_4_,0x200);
  local_c8 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  memset(local_98,0,0x48);
  local_f8 = 0;
  local_100 = 0;
  local_110 = (undefined8 *)(longlong)(int)uVar5;
  local_118 = local_98;
  local_88 = 800;
  local_108 = puVar1;
  ZwAlpcAcceptConnectPort(local_a8,PdcServerPort,0,&local_d8);
  if (plVar7 != (longlong *)0x0) {
    PdcFreeClient(plVar7);
  }
  puVar6 = (undefined8 *)0x0;
LAB_14001fd33:
  *param_2 = (longlong)puVar6;
  if (bVar2) {
    PdcReleaseLock();
  }
  if (local_e8 != 0) {
    ZwClose();
  }
  return uVar5;
}



===== PdcpAlpcProcessMessagesV1 @ 14001fd88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcpAlpcProcessMessagesV1(void)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  longlong *plVar4;
  undefined1 auStack_438 [32];
  undefined8 *local_418;
  undefined8 *local_410;
  undefined1 *local_408;
  undefined8 *local_400;
  undefined8 local_3f8;
  undefined8 local_3f0;
  undefined8 local_3e8 [2];
  undefined1 local_3d8 [160];
  undefined8 local_338 [100];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_438;
  local_3f0 = 0;
  local_3e8[0] = 0;
  bVar1 = false;
  memset(local_3d8,0,0xa0);
  pvVar3 = (void *)GetPdcLockThread();
  if (pvVar3 != SystemReserved1[0xf]) {
    PdcAcquireLock();
    bVar1 = true;
  }
  while( true ) {
    AlpcInitializeMessageAttribute(0x20000000,local_3d8,0xa0,&local_3f0);
    local_400 = local_3e8;
    local_408 = local_3d8;
    local_3f8 = 800;
    local_410 = &local_3f8;
    local_418 = local_338;
    uVar2 = ZwAlpcSendWaitReceivePort(PdcServerPort,0,0,0);
    if (uVar2 != 0) break;
    plVar4 = (longlong *)AlpcGetMessageAttribute(local_3d8,0x20000000);
    PdcProcessMessage(local_338,plVar4);
  }
  if (uVar2 != 0x102) {
    PdcPrint(1,"%s: ZwAlpcSendWaitReceivePort failed: 0x%x\n","PdcpAlpcProcessMessagesV1",
             (ulonglong)uVar2);
  }
  if (bVar1) {
    PdcReleaseLock();
  }
  return;
}



===== PdcpAlpcProcessMessagesV2 @ 14001fedc =====

void PdcpAlpcProcessMessagesV2(void)

{
  undefined8 *puVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  char *pcVar11;
  longlong lVar12;
  ushort uVar13;
  char *pcVar14;
  longlong local_res10 [3];
  undefined8 local_58 [3];
  
  local_res10[2] = 0;
  bVar2 = false;
  local_res10[0] = 0;
  local_res10[1] = 0;
  local_58[0] = 0;
  bVar3 = false;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&PdcAlpcPushLock,0);
  puVar6 = (undefined *)ExAllocateFromPagedLookasideList(&PdcMessageBufferLookasideList);
  if (puVar6 == (undefined *)0x0) {
    if (PdcBackupMessageBufferInUse != '\0') goto LAB_140020306;
    bVar2 = true;
    puVar6 = &PdcBackupMessageBuffer;
    bVar3 = true;
    PdcBackupMessageBufferInUse = '\x01';
  }
  puVar1 = (undefined8 *)(puVar6 + 0xa0);
  AlpcInitializeMessageAttribute(0x20000000,puVar6,0xa0);
  uVar8 = 0;
  local_res10[1] = 800;
  uVar4 = ZwAlpcSendWaitReceivePort(PdcServerPort,0,0,0,puVar1,local_res10 + 1,puVar6,local_58);
  if (uVar4 == 0) {
    do {
      plVar7 = (longlong *)AlpcGetMessageAttribute(puVar6,0x20000000);
      uVar13 = *(ushort *)(puVar6 + 0xa4) & 0xff;
      if ((uVar13 == 1) || (uVar13 == 3)) {
        lVar12 = *plVar7;
        PdcpAlpcMessageLockAcquire(lVar12);
        lVar9 = AlpcGetMessageAttribute(puVar6,0x20000000);
        pcVar11 = puVar6 + 0x3c0;
        uVar13 = *(ushort *)(puVar6 + 0xa4) & 0xff;
        if (uVar13 == 1) {
          pcVar14 = pcVar11;
          uVar10 = PdcSanitizeClientMessage
                             (puVar1,(int)*(short *)(puVar6 + 0xa2),(undefined8 *)pcVar11);
          if ((int)uVar10 == 0) {
            if (((&DAT_14000a830)[*(uint *)(*(longlong *)(lVar12 + 0x20) + 0x10)] == '\0') ||
               (uVar4 = PdcProcessReceivedUserMessage(lVar12,pcVar11,(longlong)pcVar14,uVar8),
               (int)uVar4 < 0)) goto LAB_14002020e;
          }
          else {
            pcVar11 = "LPC_REQUEST";
LAB_1400201d1:
            MicrosoftTelemetryAssertTriggeredArgsMsgKM
                      (pcVar11,*(undefined4 *)(*(longlong *)(lVar12 + 0x20) + 0x10),
                       (int)*(short *)(puVar6 + 0xa2),"PdcSanitizeClientMessage failed");
          }
        }
        else if (uVar13 == 3) {
          if ((*(ushort *)(puVar6 + 0xa4) >> 0xd & 1) == 0) {
            if ((&DAT_14000a830)[*(uint *)(*(longlong *)(lVar12 + 0x20) + 0x10)] == '\0') {
              pcVar14 = pcVar11;
              uVar10 = PdcSanitizeClientMessage
                                 (puVar1,(int)*(short *)(puVar6 + 0xa2),(undefined8 *)pcVar11);
              if ((int)uVar10 != 0) {
                pcVar11 = "LPC_DATAGRAM";
                goto LAB_1400201d1;
              }
              PdcProcessReceivedUserMessage(lVar12,pcVar11,(longlong)pcVar14,uVar8);
            }
          }
          else {
            PdcPrint(1,"%s: ALPC message id=%x required continuation unexpectedly. Cancelling it.\n"
                     ,"PdcpAlpcProcessClientMessage",(ulonglong)*(uint *)(lVar9 + 0x14));
LAB_14002020e:
            iVar5 = ZwAlpcCancelMessage(PdcServerPort,0,lVar9);
            if (iVar5 < 0) {
              PdcPrint(1,"%s: Unable to cancel ALPC message id=%x\n","PdcpAlpcProcessClientMessage",
                       (ulonglong)*(uint *)(lVar9 + 0x14));
            }
          }
        }
LAB_140020249:
        PdcpAlpcMessageLockRelease(lVar12);
        local_res10[0] = 0;
      }
      else {
        if (uVar13 == 5) {
          lVar12 = *plVar7;
          PdcpAlpcMessageLockAcquire(lVar12);
          KeEnterCriticalRegion();
          ExAcquirePushLockExclusiveEx(&PdcAlpcPushLock,0);
          uVar10 = *(undefined8 *)(lVar12 + 0x18);
          *(undefined8 *)(lVar12 + 0x18) = 0;
          PdcReleaseAlpcPushLock();
          uVar4 = *(uint *)(*(longlong *)(lVar12 + 0x20) + 0x10);
          if ((8 < uVar4) || ((0x148U >> (uVar4 & 0x1f) & 1) == 0)) {
            PdcAcquireLock();
          }
          PdcFreeClient(*(longlong **)(lVar12 + 0x20));
          if ((8 < uVar4) || ((0x148U >> (uVar4 & 0x1f) & 1) == 0)) {
            PdcReleaseLock();
          }
          ZwClose(uVar10);
          local_res10[0] = 0;
        }
        else {
          if (uVar13 != 10) {
            PdcPrint(1,"%s: Not expecting message type=0x%x\n","PdcpAlpcProcessMessagesV2",
                     (ulonglong)(*(ushort *)(puVar6 + 0xa4) & 0xffff00ff));
            goto LAB_140020252;
          }
          PdcReleaseAlpcPushLock();
          uVar8 = PdcpAlpcProcessClientConnection((longlong)puVar6,local_res10);
          if (-1 < (int)uVar8) {
            lVar12 = local_res10[0];
            goto LAB_140020249;
          }
        }
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(&PdcAlpcPushLock,0);
      }
LAB_140020252:
      AlpcInitializeMessageAttribute(0x20000000,puVar6,0xa0);
      uVar8 = 0;
      local_res10[1] = 800;
      uVar4 = ZwAlpcSendWaitReceivePort(PdcServerPort,0,0,0,puVar1,local_res10 + 1,puVar6,local_58);
    } while (uVar4 == 0);
    bVar2 = bVar3;
  }
  if (uVar4 != 0x102) {
    PdcPrint(1,"%s: ZwAlpcSendWaitReceivePort failed: 0x%x\n","PdcpAlpcProcessMessagesV2",
             (ulonglong)uVar4);
  }
  if (puVar6 != (undefined *)0x0) {
    if (bVar2) {
      PdcBackupMessageBufferInUse = '\0';
    }
    else {
      ExFreeToPagedLookasideList(&PdcMessageBufferLookasideList,puVar6);
    }
  }
LAB_140020306:
  PdcReleaseAlpcPushLock();
  return;
}



===== PdcAllocateUserClient @ 140020324 =====

uint PdcAllocateUserClient(longlong param_1,ulonglong param_2,longlong *param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 *_Dst;
  ulonglong uVar5;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  uVar4 = *(uint *)(param_1 + 0x38);
  *param_3 = 0;
  if ((0x7b < uVar4 - 1) || (&PdcClientInfo + (ulonglong)uVar4 * 6 == (uint *)0x0)) {
    return 0xc000000d;
  }
  if ((4 < *(int *)(param_1 + 0x2c)) && (((&PdcClientInfo)[(ulonglong)uVar4 * 6] & 0x10000000) != 0)
     ) {
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              ("PdcAllocateUserClient",uVar4,iVar2,"PDC client is deprecated");
    return 0xc000000d;
  }
  _Dst = (undefined4 *)ExAllocatePool2(0x100,0x50,0x43636450);
  if (_Dst == (undefined4 *)0x0) {
    return 0xc000009a;
  }
  memset(_Dst,0,0x50);
  *_Dst = 0x43636450;
  *(undefined8 *)(_Dst + 10) = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(_Dst + 0xc) = *(undefined8 *)(param_1 + 0x40);
  uVar5 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    puVar1 = _Dst + 0x10;
    *(undefined4 **)(_Dst + 0x12) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    *(void **)(_Dst + 0xe) = SystemReserved1[0xf];
  }
  if (iVar2 == 0) {
    uVar4 = PdcNotificationInitialize((undefined8 *)(ulonglong)uVar4,param_3);
  }
  else if (iVar2 == 1) {
    uVar5 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      uVar4 = PdcResiliencyClientInitialize((ulonglong)uVar4,param_3);
    }
    else {
      uVar4 = PdcpResiliencyV2ClientRegister(uVar4,param_3);
    }
  }
  else if (iVar2 == 2) {
LAB_140020501:
    uVar4 = PdcActivatorInitialize((uint *)(ulonglong)uVar4,iVar2,param_1 + 0x48,param_3);
  }
  else if (iVar2 == 3) {
    uVar5 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      PdcReleaseLock();
    }
    uVar4 = PdcSuspendResumeClientInitialize((ulonglong)uVar4,param_2,param_3);
    uVar5 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      PdcAcquireLock();
    }
  }
  else if (iVar2 == 4) {
    uVar4 = PdcTaskClientInitialize((undefined8 *)(ulonglong)uVar4,param_3,param_1 + 0x48,param_4);
  }
  else if (iVar2 == 5) {
    uVar4 = PdcSignalClientInitialize(uVar4,(int *)(param_1 + 200),param_3);
  }
  else if (iVar2 == 6) {
    uVar4 = PdcPpmProfileClientInitialize
                      ((undefined **)(ulonglong)uVar4,(undefined **)(param_1 + 200),param_3);
  }
  else {
    if (iVar2 == 7) goto LAB_140020501;
    if (iVar2 != 8) {
      uVar4 = 0xc000000d;
      goto LAB_140020473;
    }
    uVar5 = PdcpSleepstudyHelperClientInitialize(uVar4,param_1 + 200,param_3);
    uVar4 = (uint)uVar5;
  }
  if (-1 < (int)uVar4) {
    lVar3 = *param_3;
    *(undefined1 *)(lVar3 + 0x18) = 1;
    *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 **)(lVar3 + 0x20) = _Dst;
    *(longlong *)(_Dst + 8) = lVar3;
    PdcPrint(2,"%s: Port (%p) attached to UM client(%p).\n","PdcAllocateUserClient",_Dst);
    return uVar4;
  }
LAB_140020473:
  ExFreePoolWithTag(_Dst,0);
  return uVar4;
}



===== PdcFormatMessageToClientVersion @ 140020580 =====

undefined8
PdcFormatMessageToClientVersion
          (undefined8 *param_1,undefined8 *param_2,undefined8 param_3,uint *param_4)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 local_308 [96];
  
  memset(local_308,0,0x300);
  iVar2 = *(int *)((longlong)param_1 + 0x2c);
  *param_4 = 0;
  lVar5 = 6;
  if ((iVar2 == 1) || (iVar2 - 4U < 2)) {
    if (iVar2 != 5) {
      if (iVar2 != 4) {
        if (iVar2 == 1) {
          *param_4 = 0x300;
          PdcpCastMessageRs1('\0',param_1,local_308);
          memmove(param_2,local_308,(ulonglong)*param_4);
          return 0;
        }
        return 0xc00000bb;
      }
      uVar3 = *(uint *)(param_1 + 5);
      *param_4 = 800;
      if (0xe < uVar3) {
        return 0xc000000d;
      }
      do {
        uVar4 = param_1[1];
        *param_2 = *param_1;
        param_2[1] = uVar4;
        uVar4 = param_1[3];
        param_2[2] = param_1[2];
        param_2[3] = uVar4;
        uVar4 = param_1[5];
        param_2[4] = param_1[4];
        param_2[5] = uVar4;
        uVar4 = param_1[7];
        param_2[6] = param_1[6];
        param_2[7] = uVar4;
        uVar4 = param_1[9];
        param_2[8] = param_1[8];
        param_2[9] = uVar4;
        uVar4 = param_1[0xb];
        param_2[10] = param_1[10];
        param_2[0xb] = uVar4;
        uVar4 = param_1[0xd];
        param_2[0xc] = param_1[0xc];
        param_2[0xd] = uVar4;
        puVar6 = param_2 + 0x10;
        puVar1 = param_1 + 0xe;
        uVar4 = param_1[0xf];
        param_1 = param_1 + 0x10;
        param_2[0xe] = *puVar1;
        param_2[0xf] = uVar4;
        lVar5 = lVar5 + -1;
        param_2 = puVar6;
      } while (lVar5 != 0);
      goto LAB_1400206d4;
    }
  }
  else if (iVar2 != 6) {
    return 0xc000000d;
  }
  *param_4 = 800;
  do {
    uVar4 = param_1[1];
    *param_2 = *param_1;
    param_2[1] = uVar4;
    uVar4 = param_1[3];
    param_2[2] = param_1[2];
    param_2[3] = uVar4;
    uVar4 = param_1[5];
    param_2[4] = param_1[4];
    param_2[5] = uVar4;
    uVar4 = param_1[7];
    param_2[6] = param_1[6];
    param_2[7] = uVar4;
    uVar4 = param_1[9];
    param_2[8] = param_1[8];
    param_2[9] = uVar4;
    uVar4 = param_1[0xb];
    param_2[10] = param_1[10];
    param_2[0xb] = uVar4;
    uVar4 = param_1[0xd];
    param_2[0xc] = param_1[0xc];
    param_2[0xd] = uVar4;
    puVar6 = param_2 + 0x10;
    puVar1 = param_1 + 0xe;
    uVar4 = param_1[0xf];
    param_1 = param_1 + 0x10;
    param_2[0xe] = *puVar1;
    param_2[0xf] = uVar4;
    lVar5 = lVar5 + -1;
    param_2 = puVar6;
  } while (lVar5 != 0);
LAB_1400206d4:
  uVar4 = param_1[1];
  *puVar6 = *param_1;
  puVar6[1] = uVar4;
  uVar4 = param_1[3];
  puVar6[2] = param_1[2];
  puVar6[3] = uVar4;
  return 0;
}



===== PdcFreeClient @ 140020708 =====

void PdcFreeClient(longlong *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  undefined1 *puVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined *puVar6;
  int iVar7;
  char *pcVar8;
  undefined1 *puVar9;
  longlong lVar10;
  char *pcVar11;
  longlong lVar12;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  iVar7 = (int)param_1[2];
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  lVar10 = 0;
  plVar1 = param_1 + 4;
  if ((char)param_1[3] != '\0') {
    lVar10 = *plVar1;
  }
  lVar12 = *plVar1;
  pcVar11 = "PdcFreeClient";
  pcVar8 = "%s: Port (%p) and client(%p) to be destroyed.\n";
  plVar5 = (longlong *)0x2;
  PdcPrint(2,"%s: Port (%p) and client(%p) to be destroyed.\n","PdcFreeClient",lVar12);
  puVar9 = auStackY_48;
  if (iVar7 == 0) {
    PdcNotificationFree(param_1);
    puVar9 = auStackY_48;
    goto LAB_1400208f5;
  }
  if (iVar7 != 1) {
    puVar3 = auStackY_48;
    if (iVar7 != 2) {
      if (iVar7 == 3) {
        puVar6 = &PdcSuspendResumeLock;
        PdcAcquireRwLockExclusive(0x140014ca0);
        lVar12 = *param_1;
        if ((*(longlong **)(lVar12 + 8) == param_1) &&
           (plVar1 = (longlong *)param_1[1], (longlong *)*plVar1 == param_1)) {
          *plVar1 = lVar12;
          *(longlong **)(lVar12 + 8) = plVar1;
          if ((DAT_140014c78 != 0) && (*(char *)((longlong)param_1 + 0x34) != '\0')) {
            PdcpSuspendResumeHandleClientCompletion(puVar6);
          }
          puVar6 = &PdcSuspendResumeLock;
          PdcReleaseRwLockExclusive(0x140014ca0);
          if ((DAT_140015c01 & 4) != 0) {
            McTemplateU0pqpqq_EtwWriteTransfer
                      (puVar6,&PDC_SUSPEND_RESUME_DEREGISTRATION,param_1[5],(int)param_1[6],
                       (char)param_1,0x11,0);
          }
          ExFreePoolWithTag(param_1,0);
          puVar9 = auStackY_48;
          goto LAB_1400208f5;
        }
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar3 = auStackY_40;
      }
      else {
        if (iVar7 == 4) {
          PdcTaskClientFree(param_1,pcVar8,pcVar11,lVar12);
          puVar9 = auStackY_48;
          goto LAB_1400208f5;
        }
        if (iVar7 == 5) {
          PdcSignalClientFree((longlong)param_1);
          puVar9 = auStackY_48;
          goto LAB_1400208f5;
        }
        if (iVar7 == 6) {
          PdcPpmProfileClientFree(param_1);
          puVar9 = auStackY_48;
          goto LAB_1400208f5;
        }
        puVar3 = auStackY_48;
        if (iVar7 != 7) {
          if (iVar7 == 8) {
            PdcpSleepstudyHelperClientFree((longlong)param_1);
            puVar9 = auStackY_48;
          }
          goto LAB_1400208f5;
        }
      }
    }
    puVar9 = puVar3;
    *(undefined8 *)(puVar9 + -8) = 0x140020864;
    PdcActivatorFree(param_1);
    goto LAB_1400208f5;
  }
  uVar4 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    PdcResiliencyClientFree(param_1);
    puVar9 = auStackY_48;
    goto LAB_1400208f5;
  }
  *plVar1 = 0;
  *(undefined4 *)(param_1 + 5) = 0xffffffff;
  *(undefined4 *)((longlong)param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  if ((int)param_1[6] == 3) {
    iVar7 = 0;
LAB_140020896:
    *(undefined4 *)(param_1 + 7) = 0;
    plVar5 = param_1;
    PdcpResiliencyV2ClientSetState((longlong)param_1,iVar7);
  }
  else if ((int)param_1[6] == 1) {
    iVar7 = 2;
    goto LAB_140020896;
  }
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    McTemplateU0pqq_EtwWriteTransfer
              (plVar5,&PDC_RESILIENCY_CLIENT_DEREGISTRATION,param_1,
               *(undefined4 *)((longlong)param_1 + 0x2c),0);
  }
  PdcpResiliencyV2PrintClientMessage(0x14000d3d0,(longlong)param_1);
  PdcGetPolicyWorker(0x40);
  PdcCheckForWork();
  puVar9 = auStackY_48;
LAB_1400208f5:
  if (lVar10 != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x140020906;
    ExFreePoolWithTag(lVar10,0);
  }
  return;
}



===== PdcGetClientInfo @ 140020928 =====

undefined4 * PdcGetClientInfo(uint param_1)

{
  if (param_1 - 1 < 0x7c) {
    return &PdcClientInfo + (ulonglong)param_1 * 6;
  }
  return (undefined4 *)0x0;
}



===== PdcProcessReceivedUserMessage @ 140020950 =====

uint PdcProcessReceivedUserMessage
               (longlong param_1,char *param_2,longlong param_3,ulonglong param_4)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  uVar2 = *(ulonglong *)(param_1 + 0x20);
  uVar4 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar4 != 0) &&
     ((8 < *(uint *)(uVar2 + 0x10) || ((0x148U >> (*(uint *)(uVar2 + 0x10) & 0x1f) & 1) == 0)))) {
    PdcAcquireLock();
  }
  iVar1 = *(int *)(uVar2 + 0x10);
  if (iVar1 == 0) {
    uVar5 = PdcpNotificationClientReceive(uVar2,(longlong)param_2,param_3,param_4);
    uVar3 = (uint)uVar5;
    goto LAB_140020aa4;
  }
  if (iVar1 == 1) {
    uVar4 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      uVar5 = PdcpResiliencyV2ClientHandleMessage(uVar2,(longlong)param_2);
      uVar3 = (uint)uVar5;
      goto LAB_140020aa4;
    }
    if ((*(int *)(uVar2 + 0x10) == 1) && (*(int *)(param_2 + 0x28) == 5)) {
      uVar5 = PdcpResiliencyClientReceive(uVar2,(longlong)param_2);
      uVar3 = (uint)uVar5;
      goto LAB_140020aa4;
    }
  }
  else if (iVar1 == 2) {
    if (*(int *)(param_2 + 0x28) == 4) {
      uVar3 = PdcpReceiveActivatorClient(uVar2,(undefined8 *)param_2);
      goto LAB_140020aa4;
    }
  }
  else if (iVar1 == 3) {
    if (*(int *)(param_2 + 0x28) == 6) {
      PdcAcquireRwLockExclusive(0x140014ca0);
      uVar3 = PdcpSuspendResumeClientReceive(uVar2,(longlong)param_2);
      PdcReleaseRwLockExclusive(0x140014ca0);
      goto LAB_140020aa4;
    }
  }
  else {
    if (iVar1 != 4) {
      if (iVar1 == 5) {
        uVar4 = PdcSignalClientReceive(uVar2,(longlong)param_2);
        uVar3 = (uint)uVar4;
      }
      else if (iVar1 == 6) {
        uVar4 = PdcPpmProfileClientReceive(uVar2,(undefined8 *)param_2,param_3);
        uVar3 = (uint)uVar4;
      }
      else if (iVar1 == 7) {
        uVar4 = PdcV2ActivatorReceive(uVar2,(undefined8 *)param_2,param_3);
        uVar3 = (uint)uVar4;
      }
      else {
        uVar3 = PdcpSleepstudyHelperProcessUserMessage(uVar2,(undefined8 *)param_2,param_3);
      }
      goto LAB_140020aa4;
    }
    if (*(int *)(param_2 + 0x28) == 7) {
      uVar5 = PdcpTaskClientReceive(uVar2,param_2);
      uVar3 = (uint)uVar5;
      goto LAB_140020aa4;
    }
  }
  uVar3 = 0xc000000d;
LAB_140020aa4:
  uVar4 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar4 != 0) &&
     ((8 < *(uint *)(uVar2 + 0x10) || ((0x148U >> (*(uint *)(uVar2 + 0x10) & 0x1f) & 1) == 0)))) {
    PdcReleaseLock();
  }
  return uVar3;
}



===== PdcSanitizeClientMessage @ 140020ae4 =====

undefined8 PdcSanitizeClientMessage(undefined8 *param_1,uint param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  
  memset(param_3,0,800);
  lVar5 = 6;
  if (param_2 < 800) {
    if (param_2 != 0x300) {
      return 0xc000000d;
    }
    iVar3 = 1;
  }
  else {
    iVar3 = *(int *)((longlong)param_1 + 0x2c);
    if ((((iVar3 != 1) && (iVar3 != 4)) && (iVar3 != 5)) && (iVar3 != 6)) {
      return 0xc000000d;
    }
  }
  if (iVar3 == 6) {
    *(undefined4 *)((longlong)param_1 + 0x2c) = 6;
    do {
      uVar2 = param_1[1];
      *param_3 = *param_1;
      param_3[1] = uVar2;
      uVar2 = param_1[3];
      param_3[2] = param_1[2];
      param_3[3] = uVar2;
      uVar2 = param_1[5];
      param_3[4] = param_1[4];
      param_3[5] = uVar2;
      uVar2 = param_1[7];
      param_3[6] = param_1[6];
      param_3[7] = uVar2;
      uVar2 = param_1[9];
      param_3[8] = param_1[8];
      param_3[9] = uVar2;
      uVar2 = param_1[0xb];
      param_3[10] = param_1[10];
      param_3[0xb] = uVar2;
      uVar2 = param_1[0xd];
      param_3[0xc] = param_1[0xc];
      param_3[0xd] = uVar2;
      puVar4 = param_3 + 0x10;
      puVar1 = param_1 + 0xe;
      uVar2 = param_1[0xf];
      param_1 = param_1 + 0x10;
      param_3[0xe] = *puVar1;
      param_3[0xf] = uVar2;
      lVar5 = lVar5 + -1;
      param_3 = puVar4;
    } while (lVar5 != 0);
  }
  else {
    if (iVar3 == 5) {
      PdcpCastMessage19H1(param_3,param_1);
      return 0;
    }
    if (iVar3 != 4) {
      if (iVar3 == 1) {
        PdcpCastMessageRs1('\x01',param_3,param_1);
        return 0;
      }
      return 0xc00000bb;
    }
    if (0xe < *(uint *)(param_1 + 5)) {
      return 0xc000000d;
    }
    do {
      uVar2 = param_1[1];
      *param_3 = *param_1;
      param_3[1] = uVar2;
      uVar2 = param_1[3];
      param_3[2] = param_1[2];
      param_3[3] = uVar2;
      uVar2 = param_1[5];
      param_3[4] = param_1[4];
      param_3[5] = uVar2;
      uVar2 = param_1[7];
      param_3[6] = param_1[6];
      param_3[7] = uVar2;
      uVar2 = param_1[9];
      param_3[8] = param_1[8];
      param_3[9] = uVar2;
      uVar2 = param_1[0xb];
      param_3[10] = param_1[10];
      param_3[0xb] = uVar2;
      uVar2 = param_1[0xd];
      param_3[0xc] = param_1[0xc];
      param_3[0xd] = uVar2;
      puVar4 = param_3 + 0x10;
      puVar1 = param_1 + 0xe;
      uVar2 = param_1[0xf];
      param_1 = param_1 + 0x10;
      param_3[0xe] = *puVar1;
      param_3[0xf] = uVar2;
      lVar5 = lVar5 + -1;
      param_3 = puVar4;
    } while (lVar5 != 0);
  }
  uVar2 = param_1[1];
  *puVar4 = *param_1;
  puVar4[1] = uVar2;
  uVar2 = param_1[3];
  puVar4[2] = param_1[2];
  puVar4[3] = uVar2;
  return 0;
}



===== PdcValidateClient @ 140020c6c =====

uint PdcValidateClient(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (*(int *)(param_1 + 0x28) != 0) {
    return 0xc0000022;
  }
  uVar1 = *(uint *)(param_1 + 0x38);
  uVar2 = *(uint *)(param_1 + 0x3c);
  if (0x7c < uVar1) {
    return 0xc0000022;
  }
  if (PdcClientInclusionList != (uint *)0x0) {
    uVar5 = 0;
    puVar4 = PdcClientInclusionList;
    if (*PdcClientInclusionList == 0) {
      return 0xc0000022;
    }
    while (puVar4[1] != uVar1) {
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 1;
      if (*PdcClientInclusionList <= uVar5) {
        return 0xc0000022;
      }
    }
  }
  if (8 < uVar2) {
    return 0xc0000022;
  }
  uVar5 = 0;
  if (uVar2 == 0) {
    uVar5 = 2;
  }
  else if (uVar2 == 1) {
    uVar5 = 4;
  }
  else {
    if (uVar2 != 2) {
      if (uVar2 == 3) {
        uVar5 = 8;
        goto LAB_140020d42;
      }
      if (uVar2 == 4) {
        uVar5 = 0x10;
        goto LAB_140020d42;
      }
      if (uVar2 == 5) {
        uVar5 = 0x20;
        goto LAB_140020d42;
      }
      if (uVar2 == 6) {
        uVar5 = 0x40;
        goto LAB_140020d42;
      }
      if (uVar2 != 7) {
        if (uVar2 == 8) {
          uVar5 = 0x80000;
        }
        goto LAB_140020d42;
      }
    }
    uVar5 = 1;
  }
LAB_140020d42:
  uVar3 = 0xc0000022;
  if ((uVar5 & (&PdcClientInfo)[(ulonglong)uVar1 * 6]) != 0) {
    if (((uint)(&PdcClientInfo)[(ulonglong)uVar1 * 6] >> 9 & 1) == 0) {
      uVar3 = PdcpVerifyUserClient(uVar1,uVar2,param_2);
    }
    else {
      Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
      if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') || (param_2 != 0)) {
        uVar6 = 0xc0000022;
      }
      uVar3 = uVar6;
    }
  }
  return uVar3;
}



===== PdcpCastActivationV2MessageDataRs3 @ 140020da4 =====

void PdcpCastActivationV2MessageDataRs3(char param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  lVar4 = 4;
  puVar2 = param_2;
  puVar3 = param_3;
  if (param_1 == '\0') {
    do {
      puVar6 = puVar3;
      puVar5 = puVar2;
      uVar1 = puVar5[1];
      *puVar6 = *puVar5;
      puVar6[1] = uVar1;
      uVar1 = puVar5[3];
      puVar6[2] = puVar5[2];
      puVar6[3] = uVar1;
      uVar1 = puVar5[5];
      puVar6[4] = puVar5[4];
      puVar6[5] = uVar1;
      uVar1 = puVar5[7];
      puVar6[6] = puVar5[6];
      puVar6[7] = uVar1;
      uVar1 = puVar5[9];
      puVar6[8] = puVar5[8];
      puVar6[9] = uVar1;
      uVar1 = puVar5[0xb];
      puVar6[10] = puVar5[10];
      puVar6[0xb] = uVar1;
      uVar1 = puVar5[0xd];
      puVar6[0xc] = puVar5[0xc];
      puVar6[0xd] = uVar1;
      uVar1 = puVar5[0xf];
      puVar6[0xe] = puVar5[0xe];
      puVar6[0xf] = uVar1;
      lVar4 = lVar4 + -1;
      puVar2 = puVar5 + 0x10;
      puVar3 = puVar6 + 0x10;
    } while (lVar4 != 0);
    uVar1 = puVar5[0x11];
    puVar6[0x10] = puVar5[0x10];
    puVar6[0x11] = uVar1;
    uVar1 = puVar5[0x13];
    puVar6[0x12] = puVar5[0x12];
    puVar6[0x13] = uVar1;
    puVar6[0x14] = puVar5[0x14];
    uVar1 = param_2[0x49];
    param_3[0x45] = param_2[0x48];
    param_3[0x46] = uVar1;
    uVar1 = param_2[0x4b];
    param_3[0x47] = param_2[0x4a];
    param_3[0x48] = uVar1;
    uVar1 = param_2[0x4d];
    param_3[0x49] = param_2[0x4c];
    param_3[0x4a] = uVar1;
    uVar1 = param_2[0x4f];
    param_3[0x4b] = param_2[0x4e];
    param_3[0x4c] = uVar1;
    uVar1 = param_2[0x51];
    param_3[0x4d] = param_2[0x50];
    param_3[0x4e] = uVar1;
    uVar1 = param_2[0x53];
    param_3[0x4f] = param_2[0x52];
    param_3[0x50] = uVar1;
    uVar1 = param_2[0x55];
    param_3[0x51] = param_2[0x54];
    param_3[0x52] = uVar1;
    uVar1 = param_2[0x57];
    param_3[0x53] = param_2[0x56];
    param_3[0x54] = uVar1;
    uVar1 = param_2[0x59];
    param_3[0x55] = param_2[0x58];
    param_3[0x56] = uVar1;
    uVar1 = param_2[0x5b];
    param_3[0x57] = param_2[0x5a];
    param_3[0x58] = uVar1;
    param_3[0x59] = param_2[0x5c];
    return;
  }
  do {
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar1 = puVar6[1];
    *puVar5 = *puVar6;
    puVar5[1] = uVar1;
    uVar1 = puVar6[3];
    puVar5[2] = puVar6[2];
    puVar5[3] = uVar1;
    uVar1 = puVar6[5];
    puVar5[4] = puVar6[4];
    puVar5[5] = uVar1;
    uVar1 = puVar6[7];
    puVar5[6] = puVar6[6];
    puVar5[7] = uVar1;
    uVar1 = puVar6[9];
    puVar5[8] = puVar6[8];
    puVar5[9] = uVar1;
    uVar1 = puVar6[0xb];
    puVar5[10] = puVar6[10];
    puVar5[0xb] = uVar1;
    uVar1 = puVar6[0xd];
    puVar5[0xc] = puVar6[0xc];
    puVar5[0xd] = uVar1;
    uVar1 = puVar6[0xf];
    puVar5[0xe] = puVar6[0xe];
    puVar5[0xf] = uVar1;
    lVar4 = lVar4 + -1;
    puVar2 = puVar5 + 0x10;
    puVar3 = puVar6 + 0x10;
  } while (lVar4 != 0);
  uVar1 = puVar6[0x11];
  puVar5[0x10] = puVar6[0x10];
  puVar5[0x11] = uVar1;
  uVar1 = puVar6[0x13];
  puVar5[0x12] = puVar6[0x12];
  puVar5[0x13] = uVar1;
  puVar5[0x14] = puVar6[0x14];
  uVar1 = param_3[0x46];
  param_2[0x48] = param_3[0x45];
  param_2[0x49] = uVar1;
  uVar1 = param_3[0x48];
  param_2[0x4a] = param_3[0x47];
  param_2[0x4b] = uVar1;
  uVar1 = param_3[0x4a];
  param_2[0x4c] = param_3[0x49];
  param_2[0x4d] = uVar1;
  uVar1 = param_3[0x4c];
  param_2[0x4e] = param_3[0x4b];
  param_2[0x4f] = uVar1;
  uVar1 = param_3[0x4e];
  param_2[0x50] = param_3[0x4d];
  param_2[0x51] = uVar1;
  uVar1 = param_3[0x50];
  param_2[0x52] = param_3[0x4f];
  param_2[0x53] = uVar1;
  uVar1 = param_3[0x52];
  param_2[0x54] = param_3[0x51];
  param_2[0x55] = uVar1;
  uVar1 = param_3[0x54];
  param_2[0x56] = param_3[0x53];
  param_2[0x57] = uVar1;
  uVar1 = param_3[0x56];
  param_2[0x58] = param_3[0x55];
  param_2[0x59] = uVar1;
  uVar1 = param_3[0x58];
  param_2[0x5a] = param_3[0x57];
  param_2[0x5b] = uVar1;
  param_2[0x5c] = param_3[0x59];
  return;
}



===== PdcpCastMessage19H1 @ 140020f7c =====

void PdcpCastMessage19H1(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  if (*(int *)(param_2 + 5) != 0) {
    lVar4 = 6;
    do {
      puVar3 = param_2;
      puVar2 = param_1;
      uVar1 = puVar3[1];
      *puVar2 = *puVar3;
      puVar2[1] = uVar1;
      uVar1 = puVar3[3];
      puVar2[2] = puVar3[2];
      puVar2[3] = uVar1;
      uVar1 = puVar3[5];
      puVar2[4] = puVar3[4];
      puVar2[5] = uVar1;
      uVar1 = puVar3[7];
      puVar2[6] = puVar3[6];
      puVar2[7] = uVar1;
      uVar1 = puVar3[9];
      puVar2[8] = puVar3[8];
      puVar2[9] = uVar1;
      uVar1 = puVar3[0xb];
      puVar2[10] = puVar3[10];
      puVar2[0xb] = uVar1;
      uVar1 = puVar3[0xd];
      puVar2[0xc] = puVar3[0xc];
      puVar2[0xd] = uVar1;
      uVar1 = puVar3[0xf];
      puVar2[0xe] = puVar3[0xe];
      puVar2[0xf] = uVar1;
      lVar4 = lVar4 + -1;
      param_1 = puVar2 + 0x10;
      param_2 = puVar3 + 0x10;
    } while (lVar4 != 0);
    uVar1 = puVar3[0x11];
    puVar2[0x10] = puVar3[0x10];
    puVar2[0x11] = uVar1;
    uVar1 = puVar3[0x13];
    puVar2[0x12] = puVar3[0x12];
    puVar2[0x13] = uVar1;
    return;
  }
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  uVar1 = param_2[3];
  param_1[2] = param_2[2];
  param_1[3] = uVar1;
  uVar1 = param_2[5];
  param_1[4] = param_2[4];
  param_1[5] = uVar1;
  param_1[6] = param_2[6];
  *(undefined4 *)(param_1 + 7) = *(undefined4 *)(param_2 + 7);
  *(undefined4 *)((longlong)param_1 + 0x3c) = *(undefined4 *)((longlong)param_2 + 0x3c);
  param_1[8] = param_2[8];
  uVar1 = *(undefined8 *)((longlong)param_2 + 0xfc);
  param_1[9] = *(undefined8 *)((longlong)param_2 + 0xf4);
  param_1[10] = uVar1;
  uVar1 = *(undefined8 *)((longlong)param_2 + 0x10c);
  param_1[0xb] = *(undefined8 *)((longlong)param_2 + 0x104);
  param_1[0xc] = uVar1;
  uVar1 = *(undefined8 *)((longlong)param_2 + 0x11c);
  param_1[0xd] = *(undefined8 *)((longlong)param_2 + 0x114);
  param_1[0xe] = uVar1;
  uVar1 = *(undefined8 *)((longlong)param_2 + 300);
  param_1[0xf] = *(undefined8 *)((longlong)param_2 + 0x124);
  param_1[0x10] = uVar1;
  uVar1 = *(undefined8 *)((longlong)param_2 + 0x13c);
  param_1[0x11] = *(undefined8 *)((longlong)param_2 + 0x134);
  param_1[0x12] = uVar1;
  uVar1 = *(undefined8 *)((longlong)param_2 + 0x14c);
  param_1[0x13] = *(undefined8 *)((longlong)param_2 + 0x144);
  param_1[0x14] = uVar1;
  uVar1 = *(undefined8 *)((longlong)param_2 + 0x15c);
  param_1[0x15] = *(undefined8 *)((longlong)param_2 + 0x154);
  param_1[0x16] = uVar1;
  uVar1 = *(undefined8 *)((longlong)param_2 + 0x16c);
  param_1[0x17] = *(undefined8 *)((longlong)param_2 + 0x164);
  param_1[0x18] = uVar1;
  if (*(int *)((longlong)param_2 + 0x2c) == 8) {
    *(undefined4 *)(param_1 + 0x19) = 1;
    *(undefined4 *)((longlong)param_1 + 0xcc) = *(undefined4 *)(param_2 + 9);
    return;
  }
  uVar1 = param_2[10];
  param_1[0x19] = param_2[9];
  param_1[0x1a] = uVar1;
  uVar1 = param_2[0xc];
  param_1[0x1b] = param_2[0xb];
  param_1[0x1c] = uVar1;
  uVar1 = param_2[0xe];
  param_1[0x1d] = param_2[0xd];
  param_1[0x1e] = uVar1;
  uVar1 = param_2[0x10];
  param_1[0x1f] = param_2[0xf];
  param_1[0x20] = uVar1;
  uVar1 = param_2[0x12];
  param_1[0x21] = param_2[0x11];
  param_1[0x22] = uVar1;
  uVar1 = param_2[0x14];
  param_1[0x23] = param_2[0x13];
  param_1[0x24] = uVar1;
  uVar1 = param_2[0x16];
  param_1[0x25] = param_2[0x15];
  param_1[0x26] = uVar1;
  uVar1 = param_2[0x18];
  param_1[0x27] = param_2[0x17];
  param_1[0x28] = uVar1;
  uVar1 = param_2[0x1a];
  param_1[0x29] = param_2[0x19];
  param_1[0x2a] = uVar1;
  uVar1 = param_2[0x1c];
  param_1[0x2b] = param_2[0x1b];
  param_1[0x2c] = uVar1;
  param_1[0x2d] = param_2[0x1d];
  *(undefined4 *)(param_1 + 0x2e) = *(undefined4 *)(param_2 + 0x1e);
  return;
}



===== PdcpCastMessageRs1 @ 140021118 =====

void PdcpCastMessageRs1(char param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *_Dst;
  undefined8 *_Src;
  undefined4 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  size_t _Size;
  
  puVar7 = param_2 + 7;
  puVar3 = param_3 + 6;
  if (param_1 == '\0') {
    iVar1 = *(int *)(param_2 + 5);
    puVar5 = param_2;
    puVar6 = puVar3;
    _Dst = param_3;
    _Src = puVar7;
  }
  else {
    iVar1 = *(int *)(param_3 + 5);
    puVar5 = param_3;
    puVar6 = puVar7;
    _Dst = param_2;
    _Src = puVar3;
  }
  memset(_Dst,0,(ulonglong)(-(uint)(param_1 != '\0') & 0x20) + 0x300);
  if (param_1 != '\0') {
    *(undefined4 *)((longlong)param_2 + 0x2c) = 1;
  }
  uVar2 = puVar5[1];
  *_Dst = *puVar5;
  _Dst[1] = uVar2;
  uVar2 = puVar5[3];
  _Dst[2] = puVar5[2];
  _Dst[3] = uVar2;
  _Dst[4] = puVar5[4];
  *(undefined4 *)(_Dst + 5) = *(undefined4 *)(puVar5 + 5);
  if (iVar1 == 0) {
    _Size = 0x140;
  }
  else {
    _Size = 4;
    if ((iVar1 == 4) || (iVar1 == 6)) {
      _Size = 8;
    }
    else if (iVar1 != 7) {
      if (iVar1 == 8) {
        _Size = 0x98;
      }
      else if (iVar1 != 9) {
        if (iVar1 == 0xb) {
          _Size = 0x1c8;
        }
        else if ((iVar1 == 0xc) || (iVar1 == 0xd)) {
          _Size = 0x10;
        }
        else if (iVar1 != 0xe) {
          if (iVar1 - 2U < 2) {
            if (param_1 == '\0') {
              *(undefined4 *)puVar3 = *(undefined4 *)puVar7;
              *(undefined4 *)puVar3 = *(undefined4 *)puVar7;
              *(undefined4 *)((longlong)param_3 + 0x34) = *(undefined4 *)(param_2 + 8);
              return;
            }
            *(undefined4 *)puVar7 = *(undefined4 *)puVar3;
            *(undefined4 *)puVar7 = *(undefined4 *)puVar3;
            uVar4 = *(undefined4 *)((longlong)param_3 + 0x34);
          }
          else {
            if (iVar1 != 5) {
              if (iVar1 == 10) {
                PdcpCastActivationV2MessageDataRs3(param_1,puVar7,puVar3);
                return;
              }
              return;
            }
            puVar6 = puVar7;
            if (param_1 == '\0') {
              puVar6 = puVar3;
              puVar3 = puVar7;
            }
            *puVar6 = *puVar3;
            uVar4 = *(undefined4 *)(puVar3 + 1);
            puVar7 = puVar6;
          }
          *(undefined4 *)(puVar7 + 1) = uVar4;
          return;
        }
      }
    }
  }
  memmove(puVar6,_Src,_Size);
  return;
}



===== PdcpVerifyUserCallerAccess @ 1400212d0 =====

uint PdcpVerifyUserCallerAccess(undefined8 param_1,undefined8 param_2,uint param_3,longlong param_4)

{
  char cVar1;
  uint uVar2;
  undefined8 *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_48 [2];
  longlong local_40 [5];
  
  local_48[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  local_40[4] = 0;
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  local_40[0] = 0;
  uVar2 = ZwQueryInformationToken(param_2,0x19,0,0,local_48);
  if (uVar2 != 0xc0000023) goto LAB_140021484;
  puVar3 = (undefined8 *)ExAllocatePool2(0x100,local_48[0],0x54636450);
  if (puVar3 == (undefined8 *)0x0) {
    uVar2 = 0xc0000017;
    goto LAB_140021484;
  }
  puVar5 = local_48;
  uVar2 = ZwQueryInformationToken(param_2,0x19,puVar3,local_48[0],puVar5);
  uVar6 = (undefined4)((ulonglong)puVar5 >> 0x20);
  if ((uVar2 & 0xc0000000) != 0xc0000000) {
    cVar1 = RtlValidSid(*puVar3);
    if (cVar1 == '\0') {
      uVar2 = 0xc0000078;
    }
    else {
      puVar4 = (uint *)RtlSubAuthoritySid(*puVar3,0);
      if (*puVar4 < param_3) {
        uVar2 = 0xc0000022;
      }
      else if (param_4 == 0) {
LAB_140021471:
        uVar2 = 0;
      }
      else {
        uVar2 = ObReferenceObjectByHandleWithTag
                          (param_1,0x20000,*(undefined8 *)PsProcessType_exref,0,
                           CONCAT44(uVar6,0x54636450),local_40,0);
        if (-1 < (int)uVar2) {
          SeCaptureSubjectContextEx(0,local_40[0],local_40 + 1);
          cVar1 = SePrivilegeCheck(param_4,local_40 + 1,1);
          SeReleaseSubjectContext(local_40 + 1);
          if (cVar1 != '\0') goto LAB_140021471;
          uVar2 = 0xc0000061;
        }
      }
    }
  }
  ExFreePoolWithTag(puVar3,0);
LAB_140021484:
  if (local_40[0] != 0) {
    ObfDereferenceObjectWithTag(local_40[0],0x54636450);
  }
  return uVar2;
}



===== PdcpVerifyUserClient @ 1400214c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PdcpVerifyUserClient(uint param_1,int param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 auStack_78 [32];
  char local_58;
  longlong local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  local_50 = 0;
  if (*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\x01') {
    return 0xc0000022;
  }
  if (param_2 == 3) {
    return 0;
  }
  uVar1 = ZwOpenProcessTokenEx(param_3,0x20000);
  if (-1 < (int)uVar1) {
    uVar1 = (&PdcClientInfo)[(ulonglong)param_1 * 6];
    if ((uVar1 >> 8 & 1) != 0) {
      local_58 = '\0';
      iVar2 = RtlCheckTokenMembership
                        (local_50,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
      if ((iVar2 < 0) || (local_58 == '\0')) {
        uVar1 = 0xc0000022;
        goto LAB_140021602;
      }
    }
    if ((uVar1 >> 0xc & 1) == 0) {
      puVar3 = (undefined8 *)0x0;
    }
    else {
      uStack_44 = 0;
      puVar3 = &local_40;
      local_30 = 0;
      local_48 = 0x13;
      uStack_38 = 0x13;
      local_40 = 0x100000001;
    }
    uVar1 = PdcpVerifyUserCallerAccess
                      (param_3,local_50,(-(uint)((uVar1 & 0x400) != 0) & 0xfffff000) + 0x2000,
                       (longlong)puVar3);
  }
LAB_140021602:
  if (local_50 != 0) {
    ZwClose();
  }
  return uVar1;
}



===== PdcAcquireLock @ 140021644 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcAcquireLock(void)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  KeEnterCriticalRegion();
  lVar1 = KeQueryUnbiasedInterruptTime();
  ExAcquireResourceExclusiveLite(&PdcLock);
  PdcLockThread = SystemReserved1[0xf];
  _DAT_140031240 = KeQueryUnbiasedInterruptTime();
  DAT_140031158 = DAT_140031158 + 1;
  uVar2 = _DAT_140031240 - lVar1;
  if (uVar2 < DAT_140031160) {
    DAT_140031160 = uVar2;
  }
  if (DAT_140031168 < uVar2) {
    DAT_140031168 = uVar2;
  }
  _DAT_140031170 = _DAT_140031170 + uVar2;
  if (PdcLockStats == 0) {
    uVar2 = 0;
  }
  else {
    uVar4 = 1;
    uVar3 = 1;
    if (1 < DAT_1400310f8) {
      do {
        uVar3 = (uint)uVar4;
        if (uVar2 < *(ulonglong *)(&DAT_140031100 + uVar4 * 8)) break;
        uVar3 = uVar3 + 1;
        uVar4 = (ulonglong)uVar3;
      } while (uVar3 < DAT_1400310f8);
    }
    uVar2 = (ulonglong)(uVar3 - 1);
  }
  (&DAT_140031178)[uVar2] = (&DAT_140031178)[uVar2] + 1;
  if (PdcLockWatchdogTimeoutMs != 0) {
    KeClearEvent(&DAT_140015278);
    PdcSetTimer(0x1400151c0,(ulonglong)PdcLockWatchdogTimeoutMs);
    _DAT_140031250 = KeQueryUnbiasedInterruptTime();
  }
  return;
}



===== PdcConvertQpcDuration @ 140021760 =====

ulonglong PdcConvertQpcDuration(ulonglong param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  
  if ((param_1 != 0) && (PdcQpcFrequency != 1000000)) {
    auVar2._8_8_ = 0;
    auVar2._0_8_ = param_1;
    if (SUB168(ZEXT816(1000000) * auVar2,8) == 0) {
      auVar1._8_8_ = 0;
      auVar1._0_8_ = PdcQpcFrequency;
      param_1 = SUB168((ZEXT816(1000000) * auVar2) / auVar1,0);
    }
    else {
      param_1 = ((param_1 - (param_1 / PdcQpcFrequency) * PdcQpcFrequency) * 1000000) /
                PdcQpcFrequency + (param_1 / PdcQpcFrequency) * 1000000;
    }
  }
  return param_1;
}



===== PdcInitializeLock @ 1400217c4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 PdcInitializeLock(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  PdcGetRegistryDwordValue
            (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
             L"PdcLockStatsTelemetryPeriod",0x15180,&PdcLockStatsTelemetryPeriodSeconds);
  PdcGetRegistryDwordValue
            (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
             L"PdcLockWatchdogTimeout",30000,&PdcLockWatchdogTimeoutMs);
  if (PdcLockWatchdogTimeoutMs != 0) {
    memset(&PdcLockWatchdog,0,0xd0);
    KeInitializeEvent(&DAT_140015278,0);
    PdcInitializeTimer(0x1400151c0,PdcpLockWatchdogWorkerRoutine,0,&PdcLockStats,5);
  }
  uVar2 = ExInitializeResourceLite(&PdcLock);
  PdcAcquireLock();
  _DAT_140031100 = 0;
  lVar6 = 100000;
  PdcLockStats = &PdcLock;
  DAT_1400310f8 = 0xb;
  uVar5 = 1;
  do {
    uVar4 = (int)uVar5 + 1;
    *(longlong *)(&DAT_140031100 + uVar5 * 8) = lVar6;
    lVar6 = lVar6 * 2;
    uVar5 = (ulonglong)uVar4;
  } while (uVar4 < DAT_1400310f8);
  memset(&DAT_140031158,0,0x130);
  DAT_140031160 = 0xffffffffffffffff;
  DAT_1400311d0 = 0xffffffffffffffff;
  if (PdcLockStatsTelemetryPeriodSeconds != 0) {
    PdcInitializeTimer(0x140015320,PdcLockStatsTelemetryWorkerRoutine,0,&PdcLockStats,1);
    PdcSetTimer(0x140015320,(ulonglong)(uint)(PdcLockStatsTelemetryPeriodSeconds * 1000));
  }
  PdcReleaseLock();
  DAT_1400120d4 = 0;
  iVar3 = KeInitializeTriageDumpDataArray(&DAT_1400120d8,0x40);
  if (-1 < iVar3) {
    KeAddTriageDumpDataBlock(&DAT_1400120d8,&PdcLockStats,0x198);
    cVar1 = KeRegisterBugCheckReasonCallback
                      (&DAT_1400120a8,PTR_PdcpLockWatchdogLKDCallback_140012098,7,
                       PTR_s_PDC_LOCK_WATCHDOG_LIVEDUMP_TRIA_1400120a0);
    if (cVar1 != '\0') {
      PdcpLockWatchdogLKDControlContext = 1;
    }
  }
  PdcLockInitialized = (byte)((uint)uVar2 >> 0x1f) ^ 1;
  return uVar2;
}



===== PdcIsClientProcessFrozen @ 1400219cc =====

int PdcIsClientProcessFrozen(longlong param_1,byte *param_2)

{
  int iVar1;
  longlong local_res8;
  undefined1 local_48 [56];
  uint local_10;
  
  memset(local_48,0,0x40);
  local_res8 = 0;
  iVar1 = 0;
  *param_2 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    iVar1 = PdcpOpenClientProcessHandle
                      (*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x28),&local_res8);
    if (-1 < iVar1) {
      iVar1 = NtQueryInformationProcess(local_res8,0,local_48,0x40,0);
      if (-1 < iVar1) {
        *param_2 = (byte)(local_10 >> 4) & 1;
      }
    }
    if (local_res8 != 0) {
      NtClose();
    }
  }
  return iVar1;
}



===== PdcLockRecordBlackboxInformation @ 140021a8c =====

void PdcLockRecordBlackboxInformation(char param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined4 *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar2 = 0;
  puVar1 = (undefined4 *)0x0;
  if (param_1 != '\0') {
    uVar2 = 0x18;
    puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x18,0x4c636450);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 1;
      *puVar1 = 0x18;
      *(undefined8 **)(puVar1 + 2) = &PdcLockThread;
      *(undefined8 **)(puVar1 + 4) = &PdcLockStats;
    }
  }
  local_18 = 0;
  local_c = 0;
  local_10 = 6;
  local_28 = puVar1;
  local_20 = uVar2;
  ZwPowerInformation(0x5e,&local_28,0x20,0,0);
  if (puVar1 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar1,0);
  }
  return;
}



===== PdcLockStatsTelemetryWorkerRoutine @ 140021b50 =====

void PdcLockStatsTelemetryWorkerRoutine
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  PdcAcquireLock();
  PdcLockStatsEmitTelemetry(param_1,param_2,param_3,param_4);
  memset((void *)(param_1 + 0x68),0,0x130);
  *(undefined8 *)(param_1 + 0x70) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0xe0) = 0xffffffffffffffff;
  if (PdcLockStatsTelemetryPeriodSeconds != 0) {
    PdcSetTimer(0x140015320,(ulonglong)(uint)(PdcLockStatsTelemetryPeriodSeconds * 1000));
  }
  PdcReleaseLock();
  return;
}



===== PdcReleaseLock @ 140021bb4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcReleaseLock(void)

{
  char cVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (PdcLockWatchdogTimeoutMs != 0) {
    _DAT_140031258 = KeQueryUnbiasedInterruptTime();
    cVar1 = KeCancelTimer(&PdcLockWatchdog);
    _DAT_140031260 = KeQueryUnbiasedInterruptTime();
    if (cVar1 == '\0') {
      KeWaitForSingleObject(&DAT_140015278,0,0,0,0);
      _DAT_140031268 = KeQueryUnbiasedInterruptTime();
      PdcLockRecordBlackboxInformation('\0');
    }
  }
  if (DAT_140031158 != 0) {
    lVar2 = KeQueryUnbiasedInterruptTime();
    uVar3 = lVar2 - _DAT_140031240;
    if (uVar3 < DAT_1400311d0) {
      DAT_1400311d0 = uVar3;
    }
    if (DAT_1400311d8 < uVar3) {
      DAT_1400311d8 = uVar3;
    }
    _DAT_1400311e0 = _DAT_1400311e0 + uVar3;
    if (PdcLockStats == 0) {
      uVar3 = 0;
    }
    else {
      uVar5 = 1;
      uVar4 = 1;
      if (1 < DAT_1400310f8) {
        do {
          uVar4 = (uint)uVar5;
          if (uVar3 < *(ulonglong *)(&DAT_140031100 + uVar5 * 8)) break;
          uVar4 = uVar4 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < DAT_1400310f8);
      }
      uVar3 = (ulonglong)(uVar4 - 1);
    }
    (&DAT_1400311e8)[uVar3] = (&DAT_1400311e8)[uVar3] + 1;
    _DAT_140031240 = 0;
    _DAT_140031248 = 0;
    _DAT_140031250 = 0;
    _DAT_140031258 = 0;
    _DAT_140031260 = 0;
    _DAT_140031268 = 0;
  }
  PdcLockThread = 0;
  ExReleaseResourceLite(&PdcLock);
  PdcCheckForWork();
  KeLeaveCriticalRegion();
  return;
}



===== PdcpLockWatchdogWorkerRoutine @ 140021d40 =====

void PdcpLockWatchdogWorkerRoutine(longlong param_1)

{
  undefined8 uVar1;
  
  *(undefined8 *)(param_1 + 0x180) = DAT_140015270;
  uVar1 = KeQueryUnbiasedInterruptTime();
  *(undefined8 *)(param_1 + 0x188) = uVar1;
  PdcLockRecordBlackboxInformation('\x01');
  uVar1 = KeQueryUnbiasedInterruptTime();
  *(undefined8 *)(param_1 + 400) = uVar1;
  DbgkWerCaptureLiveKernelDump
            (L"PdcLockWatchdog",0x17c,PdcLockThread,PdcLockWatchdogTimeoutMs,0,0,0,0,0);
  KeSetEvent(&DAT_140015278,0,0);
  return;
}



===== PdcpOpenClientProcessHandle @ 140021dec =====

void PdcpOpenClientProcessHandle(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_40 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0x200;
  local_18 = 0;
  uStack_10 = 0;
  local_48 = param_1;
  ZwOpenProcess(param_2,0x400,&local_38,&local_48);
  return;
}



===== PdcAcknowledgePhaseCallback @ 140021e50 =====

void PdcAcknowledgePhaseCallback(int param_1)

{
  PdcAcquireLock();
  PdcPhasesAcknowledgePoCallback(param_1);
  PdcReleaseLock();
  return;
}



===== PdcAttemptGlobalActivatorsVeto @ 140021e78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcAttemptGlobalActivatorsVeto
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  bool bVar1;
  bool bVar2;
  undefined1 auStackY_c8 [32];
  uint local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_94 = PdcGetResourceMask();
  bVar1 = true;
  bVar2 = ((byte)local_94 & 0x38) == 0x20;
  if (bVar2) {
    PdcSetGlobalActivatorsVeto('\x01',0,param_3,param_4);
  }
  local_98 = (uint)bVar2;
  if (5 < DAT_140031288) {
    if (((_DAT_140031298 & 0x400000000000) == 0) ||
       ((DAT_1400312a0 & 0x400000000000) != DAT_1400312a0)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_90 = DAT_140015130;
      local_58 = &local_90;
      local_48 = &local_98;
      local_38 = &local_94;
      local_28 = local_88;
      local_40 = 4;
      local_30 = 4;
      local_50 = 8;
      local_88[0] = 0x1000000;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000ea06,8,param_4,6,local_78);
    }
  }
  return;
}



===== PdcCaptureSleepStudyStatistics @ 140021fb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
PdcCaptureSleepStudyStatistics
          (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  plVar2 = param_1;
  uVar3 = param_2;
  PdcAcquireLock();
  if ((*param_1 == 0) && (param_1[1] == 0)) {
    PdcCaptureStats(plVar2,uVar3,param_3,param_4);
    PdcpStopStandbyExitPerftrack();
    PdcWriteDSNetworkFeatureEnabledTelemetryEvent(plVar2,DAT_140015130);
    DAT_140015130 = 0;
  }
  else {
    DAT_1400129c8 = 0;
    PdcActivationCsStartTime = _DAT_fffff78000000008;
    PdcActivationOnAc = DAT_1400135e8;
    PdcpAccountingPaused = 1;
    DAT_140015130 = param_2;
    for (puVar1 = PdcActivatorStatsList; (undefined8 **)puVar1 != &PdcActivatorStatsList;
        puVar1 = (undefined8 *)*puVar1) {
      *(undefined4 *)((longlong)puVar1 + 0x54) = 0;
    }
    PdcDSNetworkFeatureEnabled = 0;
  }
  PdcPhasesResetAccounting();
  PdcReleaseLock();
  return 0;
}



===== PdcCaptureStats @ 140022078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcCaptureStats(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined1 auStackY_c8 [32];
  undefined4 local_98;
  int local_94;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  PdcActivationCsStartTime = 0;
  DAT_1400129c8 = 0;
  if ((undefined8 **)PdcActivatorStatsList != &PdcActivatorStatsList) {
    uVar2 = DAT_1400312a0;
    puVar3 = PdcActivatorStatsList;
    do {
      if ((*(int *)((longlong)puVar3 + 0x54) != 0) && (5 < DAT_140031288)) {
        if (((_DAT_140031298 & 0x400000000000) == 0) || ((uVar2 & 0x400000000000) != uVar2)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_4c = 0;
          local_3c = 0;
          local_2c = 0;
          local_1c = 0;
          local_90 = DAT_140015130;
          local_58 = &local_90;
          local_98 = *(undefined4 *)(puVar3 + 2);
          local_48 = &local_98;
          local_38 = &local_94;
          local_28 = local_88;
          local_50 = 8;
          local_40 = 4;
          local_30 = 4;
          local_88[0] = 0x1000000;
          local_20 = 8;
          local_94 = *(int *)((longlong)puVar3 + 0x54);
          _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000f3b7,param_3,param_4,6,local_78);
          uVar2 = DAT_1400312a0;
        }
      }
      puVar3 = (undefined8 *)*puVar3;
    } while ((undefined8 **)puVar3 != &PdcActivatorStatsList);
  }
  PdcpLogPhaseAccounting(DAT_140015130);
  return;
}



===== PdcChargePowerRequest @ 1400221f0 =====

void PdcChargePowerRequest(char param_1)

{
  PdcAcquireLock();
  PdcGroupRequest((uint *)0x5,param_1);
  PdcReleaseLock();
  return;
}



===== PdcInitializePdc @ 14002221c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PdcInitializePdc(int param_1)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  
  local_res10 = 0;
  if (param_1 == 0) {
    wil_InitializeFeatureStaging();
    KeQueryPerformanceCounter(&local_res10);
    PdcQpcFrequency = local_res10;
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x140031288);
    memset(&PdcContext,0,0x48);
    DAT_140015150 = 0x3f;
    PdcGetRegistryDwordValue
              (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
               L"PdcCriticalTransitionTimeout",0,&PdcCriticalNotificationTimeout);
    PdcGetRegistryDwordValue
              (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",L"PdcCsEntryAction"
               ,1,&PdcCsEntryNotificationAction);
    PdcGetRegistryDwordValue
              (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
               L"PdcWcmTransitionTimeout",0,&PdcWcmNotificationTimeout);
    if (PdcWcmNotificationTimeout == 0) {
      if (PdcCriticalNotificationTimeout != 0) {
        PdcWcmNotificationTimeout = PdcCriticalNotificationTimeout;
        goto LAB_1400222f4;
      }
      PdcWcmNotificationTimeout = 0x136;
LAB_1400222fd:
      PdcCriticalNotificationTimeout = 10;
    }
    else {
LAB_1400222f4:
      if (PdcCriticalNotificationTimeout == 0) goto LAB_1400222fd;
    }
    PdcGetRegistryDwordValue
              (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
               L"PdcCriticalActivatorTimeout",0,&PdcCriticalActivatorTimeout);
    if (PdcCriticalActivatorTimeout == 0) {
      PdcCriticalActivatorTimeout = 300;
    }
    PdcGetRegistryDwordValue
              (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
               L"PdcActivatorClientResponseTimeout",0,&PdcActivatorClientResponseTimeout);
    if (PdcActivatorClientResponseTimeout == 0) {
      PdcActivatorClientResponseTimeout = 0x3c;
    }
    PdcGetRegistryDwordValue
              (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
               L"PdcActivatorClientPolicyNotificationDebounce",0,
               &PdcActivatorPolicyNotificationDebounce);
    if (PdcActivatorPolicyNotificationDebounce == 0) {
      PdcActivatorPolicyNotificationDebounce = 3;
    }
    PdcGetRegistryDwordValue
              (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
               L"PdcCriticalActivatorAction",5,(undefined4 *)&PdcCriticalActivatorAction);
    puVar5 = &PdcEnforceSystemIdleTimeoutOnConsoleLock;
    PdcGetRegistryDwordValue
              (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
               L"PdcEnforceSystemIdleTimeoutOnConsoleLock",0,
               (undefined4 *)&PdcEnforceSystemIdleTimeoutOnConsoleLock);
    uVar3 = PdcDiagInitialize();
    uVar1 = (uint)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if ((int)uVar1 < 0) {
      pcVar4 = "PDC: PdcDiagInitialize: %08lx\n";
    }
    else {
      uVar1 = PdcClientInclusionListInitialize();
      if ((int)uVar1 < 0) {
        PdcPrint(1,"PDC: PdcClientInclusionListInitialize: %08lx\n",(ulonglong)uVar1,puVar5);
      }
      PdcClientsInitialize();
      PdcMonitorInitialize();
      PdcInitializePowerSettingCallbacks();
      PdcInitializePolicyWorker();
      PdcInitDriverServices();
      uVar1 = PdcAlpcInitializeChannel();
      uVar3 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        PdcPortInitialize();
        PdcPhasesInitialize(0);
        PdcGroupsInitialize();
        PdcpInitializeInternalRequestGroupsClients();
        _DAT_140015198 = 0;
        _PdcMaintenanceResumeWorkItem = 0;
        _DAT_140015190 = PdcMaintenanceResumeWorkItemCallback;
        PdcMaintenanceResumeTimer = ExAllocateTimer(PdcMaintenanceResumeTimerCallback,0,0x80000000);
        if (PdcMaintenanceResumeTimer == 0) {
          return 0xc000009a;
        }
        PdcpReplayLidCloseInit();
        uVar3 = Feature_14FBugcheckMinidumpDiagnostics__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 != 0) {
          PdcpDumpControlInit();
        }
        goto LAB_140022517;
      }
      pcVar4 = "PDC: PdcAlpcInitializeChannel: %08lx\n";
    }
    PdcPrint(1,pcVar4,(ulonglong)uVar1,puVar5);
  }
  else {
    PdcPhasesInitialize(param_1);
    local_res18[0] = 0x44;
    iVar2 = ZwPowerInformation(0x57,local_res18,8,0,0);
    PdcAcquireRwLockExclusive(0x140014d80);
    DAT_140014dd8 = iVar2 == 0;
    PdcpHandleSystemForegroundGroupStateChange();
    if (PdcpPlatformAoAcCapable == '\0') {
      PdcGroupEnable((uint *)0x3,0);
    }
    PdcReleaseRwLockExclusive(0x140014d80);
LAB_140022517:
    uVar3 = 0;
  }
  return uVar3;
}



===== PdcLowPowerEpoch @ 140022530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcLowPowerEpoch(char param_1)

{
  (*DAT_140015068)(param_1 != '\0');
  return;
}



===== PdcQueryResiliencyStats @ 140022560 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcQueryResiliencyStats(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    PdcAcquireLock();
    param_1[5] = DAT_140013e70;
    *(undefined4 *)(param_1 + 6) = DAT_140013e80;
    param_1[7] = DAT_140013ee0;
    uVar2 = DAT_140013ef0;
  }
  else {
    PdcAcquireLock();
    param_1[5] = DAT_140013938;
    *(undefined4 *)(param_1 + 6) = DAT_140013948;
    param_1[7] = DAT_1400139a8;
    uVar2 = DAT_1400139b8;
  }
  *(undefined4 *)(param_1 + 8) = uVar2;
  PdcReleaseLock();
  uVar1 = DAT_140012de8;
  *param_1 = _PdcResiliencyActivationStats;
  param_1[1] = uVar1;
  uVar1 = _DAT_140012df8;
  param_1[2] = DAT_140012df0;
  param_1[3] = uVar1;
  param_1[4] = DAT_140012e00;
  return;
}



===== PdcRegisterPpmProfiles @ 140022600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcRegisterPpmProfiles(void)

{
  (*DAT_1400150c0)();
  return;
}



===== PdcSnapDiagnosticContext @ 140022620 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcSnapDiagnosticContext(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  void *_Dst;
  longlong lVar6;
  undefined8 *puVar7;
  
  PdcAcquireLock();
  *param_1 = 0;
  puVar4 = (undefined8 *)ExAllocatePool2(0x100,0x48,0x54445050);
  uVar1 = _DAT_140015128;
  if (puVar4 != (undefined8 *)0x0) {
    *puVar4 = _PdcContext;
    puVar4[1] = uVar1;
    uVar1 = _DAT_140015138;
    puVar4[2] = DAT_140015130;
    puVar4[3] = uVar1;
    uVar1 = DAT_140015148;
    puVar4[4] = _DAT_140015140;
    puVar4[5] = uVar1;
    uVar1 = _DAT_140015158;
    puVar4[6] = _DAT_140015150;
    puVar4[7] = uVar1;
    puVar4[8] = DAT_140015160;
    *param_1 = puVar4;
  }
  param_1[1] = 0;
  PdcAcquireRwLockExclusive(0x140014d80);
  puVar4 = (undefined8 *)ExAllocatePool2(0x100,600,0x54445050);
  if (puVar4 != (undefined8 *)0x0) {
    lVar6 = 4;
    puVar2 = (undefined8 *)&PdcMonitor;
    puVar3 = puVar4;
    do {
      puVar7 = puVar3;
      puVar5 = puVar2;
      uVar1 = puVar5[1];
      *puVar7 = *puVar5;
      puVar7[1] = uVar1;
      uVar1 = puVar5[3];
      puVar7[2] = puVar5[2];
      puVar7[3] = uVar1;
      uVar1 = puVar5[5];
      puVar7[4] = puVar5[4];
      puVar7[5] = uVar1;
      uVar1 = puVar5[7];
      puVar7[6] = puVar5[6];
      puVar7[7] = uVar1;
      uVar1 = puVar5[9];
      puVar7[8] = puVar5[8];
      puVar7[9] = uVar1;
      uVar1 = puVar5[0xb];
      puVar7[10] = puVar5[10];
      puVar7[0xb] = uVar1;
      uVar1 = puVar5[0xd];
      puVar7[0xc] = puVar5[0xc];
      puVar7[0xd] = uVar1;
      uVar1 = puVar5[0xf];
      puVar7[0xe] = puVar5[0xe];
      puVar7[0xf] = uVar1;
      lVar6 = lVar6 + -1;
      puVar2 = puVar5 + 0x10;
      puVar3 = puVar7 + 0x10;
    } while (lVar6 != 0);
    uVar1 = puVar5[0x11];
    puVar7[0x10] = puVar5[0x10];
    puVar7[0x11] = uVar1;
    uVar1 = puVar5[0x13];
    puVar7[0x12] = puVar5[0x12];
    puVar7[0x13] = uVar1;
    uVar1 = puVar5[0x15];
    puVar7[0x14] = puVar5[0x14];
    puVar7[0x15] = uVar1;
    uVar1 = puVar5[0x17];
    puVar7[0x16] = puVar5[0x16];
    puVar7[0x17] = uVar1;
    uVar1 = puVar5[0x19];
    puVar7[0x18] = puVar5[0x18];
    puVar7[0x19] = uVar1;
    puVar7[0x1a] = puVar5[0x1a];
    param_1[1] = puVar4;
  }
  PdcReleaseRwLockExclusive(0x140014d80);
  PdcGroupsSnapDiagnosticContext(param_1 + 3,(uint *)(param_1 + 2));
  param_1[4] = 0;
  param_1[5] = 0;
  puVar4 = (undefined8 *)ExAllocatePool2(0x100,0x28,0x54445050);
  uVar1 = _DAT_140031010;
  if (puVar4 != (undefined8 *)0x0) {
    *puVar4 = _PdcPhasesContext;
    puVar4[1] = uVar1;
    uVar1 = _DAT_140031020;
    puVar4[2] = _DAT_140031018;
    puVar4[3] = uVar1;
    puVar4[4] = DAT_140031028;
    param_1[4] = puVar4;
  }
  _Dst = (void *)ExAllocatePool2(0x100,0xc18,0x54445050);
  if (_Dst != (void *)0x0) {
    memmove(_Dst,&PdcPhasesEx,0xc18);
    param_1[5] = _Dst;
  }
  PdcReleaseLock();
  return;
}



===== PdcSuspendResume @ 140022820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcSuspendResume(uint param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar3 = 2;
  local_28 = 0;
  uStack_20 = 0;
  PdcPrint(2,"%s: step %lx\n","PdcSuspendResume",(ulonglong)param_1);
  if ((DAT_140015c01 & 2) != 0) {
    McTemplateU0q_EtwWriteTransfer(uVar3,&PDC_CS_SUSPEND_RESUME,(ulonglong)param_1);
  }
  puVar4 = auStack_48;
  puVar5 = auStack_48;
  PdcAcquireLock();
  iVar2 = PdcContext;
  PdcContext = param_1;
  if (param_1 == 1) {
    uVar3 = 5;
    PdcRecordLogEntry(5);
    if ((iVar2 == 1) || (PdcMaintenanceResumeTimerScheduled == '\0')) {
      PdcReleaseLock();
      puVar5 = auStack_48;
      if (iVar2 != 1) {
        PdcTaskClientRequest(uVar3,iVar2 != 1);
        puVar5 = auStack_48;
      }
      goto LAB_140022939;
    }
    ExCancelTimer(PdcMaintenanceResumeTimer,0);
    PdcMaintenanceResumeTimerScheduled = '\0';
  }
  else if (param_1 == 2) {
    PdcRecordLogEntry(6);
    puVar5 = auStack_48;
  }
  else {
    if (param_1 != 3) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(5);
      puVar4 = auStack_40;
    }
    *(undefined8 *)(puVar4 + -8) = 0x1400228ae;
    PdcRecordLogEntry(7);
    *(undefined8 *)(puVar4 + -8) = 0x1400228cb;
    ExSetTimer(PdcMaintenanceResumeTimer,0xfffffffffa0a1f00,0,puVar4 + 0x20);
    PdcMaintenanceResumeTimerScheduled = '\x01';
    puVar5 = puVar4;
  }
  *(undefined8 *)(puVar5 + -8) = 0x14002291e;
  PdcReleaseLock();
LAB_140022939:
  *(undefined8 *)(puVar5 + -8) = 0x140022945;
  PdcAcquireRwLockExclusive(0x140032b28);
  if ((PdcpSwitchProcessingSuspended != '\0') && (param_1 != 1)) {
    DAT_1400136e2 = 1;
  }
  PdcpSwitchProcessingSuspended = param_1 == 1;
  *(undefined8 *)(puVar5 + -8) = 0x140022970;
  PdcReleaseRwLockExclusive(0x140032b28);
  *(undefined8 *)(puVar5 + -8) = 0x14002298b;
  PdcPrint(2,"%s: step %lx complete\n","PdcSuspendResume",(ulonglong)param_1);
  *(undefined8 *)(puVar5 + -8) = 0x140022998;
  return;
}



===== PdcSystemIdle @ 1400229b0 =====

undefined8 PdcSystemIdle(ulonglong param_1,undefined8 param_2)

{
  ulonglong uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  bool bVar4;
  
  uVar2 = (undefined1)param_2;
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  uVar1 = param_1;
  PdcAcquireLock();
  bVar4 = (char)param_1 == '\0';
  if ((bool)(char)DAT_140015160 != bVar4) {
    uVar1 = 0;
    uVar2 = bVar4;
    PdcGroupRequest((uint *)0x0,bVar4);
    DAT_140015160._0_1_ = bVar4;
  }
  if ((DAT_140015c03 & 1) != 0) {
    McTemplateU0t_EtwWriteTransfer(uVar1,CONCAT71(uVar3,uVar2),param_1 & 0xff);
  }
  PdcReleaseLock();
  return 0;
}



===== PdcWriteDSNetworkFeatureEnabledTelemetryEvent @ 140022a0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcWriteDSNetworkFeatureEnabledTelemetryEvent(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  undefined1 auStackY_b8 [32];
  uint local_88 [2];
  undefined8 local_80;
  undefined8 local_78 [2];
  undefined8 local_68 [4];
  uint *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (5 < DAT_140031288) {
    if (((_DAT_140031298 & 0x400000000000) == 0) ||
       (bVar1 = true, (DAT_1400312a0 & 0x400000000000) != DAT_1400312a0)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_48 = local_88;
      local_38 = &local_80;
      local_88[0] = PdcDSNetworkFeatureEnabled;
      local_28 = local_78;
      local_40 = 4;
      local_30 = 8;
      local_78[0] = 0x1000000;
      local_20 = 8;
      local_80 = param_2;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140031288,&DAT_14000ea71,(ulonglong)PdcDSNetworkFeatureEnabled,0,5,local_68);
    }
  }
  return;
}



===== PdcpApplyResiliencyBias @ 140022af0 =====

void PdcpApplyResiliencyBias
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  PdcActivationClientActivityRequest(param_1,3,(char)param_1,param_4);
  return;
}



===== PdcpPlatformInitializationCompleteCallback @ 140022b10 =====

void PdcpPlatformInitializationCompleteCallback(byte param_1)

{
  void *pvVar1;
  undefined8 uVar2;
  bool bVar3;
  
  pvVar1 = (void *)GetPdcLockThread();
  bVar3 = pvVar1 != SystemReserved1[0xf];
  if (bVar3) {
    PdcAcquireLock();
  }
  uVar2 = 1;
  PdcpPlatformAoAcCapable = param_1;
  PdcInitializePdc(1);
  if (bVar3) {
    PdcReleaseLock();
  }
  if ((DAT_140015c01 & 2) != 0) {
    McTemplateU0qq_EtwWriteTransfer(uVar2,&PDC_INITIALIZATION,(ulonglong)PdcpPlatformAoAcCapable,0);
  }
  return;
}



===== PdcpQueryResumeStats @ 140022b90 =====

void PdcpQueryResumeStats(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  PdcAcquireLock();
  lVar1 = DAT_140015148;
  lVar2 = 0;
  if (DAT_140015160._2_1_ != '\0') {
    PdcAcquireRwLockExclusive(0x140014d80);
    lVar2 = DAT_140014de0;
    PdcReleaseRwLockExclusive(0x140014d80);
    lVar2 = lVar2 - lVar1;
  }
  *param_1 = lVar2;
  PdcReleaseLock();
  return;
}



===== PdcpStopStandbyEntryPerftrack @ 140022bfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PdcpStopStandbyEntryPerftrack(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 auStackY_b8 [32];
  undefined8 local_68;
  int local_60;
  int local_58;
  uint local_50;
  int local_48;
  uint local_40;
  uint local_38;
  int local_30;
  int local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar2 = &DAT_1400313b8;
  lVar6 = 9;
  puVar3 = &local_68;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 0x2b;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  uVar4 = (ulonglong)(local_48 - local_50) / 10000;
  uVar7 = 0x7ffff;
  if (uVar4 < 0x7ffff) {
    uVar7 = uVar4;
  }
  uVar5 = (ulonglong)(local_38 - local_40) / 10000;
  uVar4 = 0x7ffff;
  if (uVar5 < 0x7ffff) {
    uVar4 = uVar5;
  }
  uVar1 = SUB168(ZEXT816(0x346dc5d63886594b) * ZEXT416((uint)(local_28 - local_30)),0);
  if ((PdcpPlatformAoAcCapable != '\0') && ((DAT_140015c01 & 0x10) != 0)) {
    uVar5 = (ulonglong)local_50 / 10000;
    uVar1 = McTemplateU0qqqqqqqq_EtwWriteTransfer
                      ((ulonglong)local_50,uVar5,uVar5,local_40 / 10000,(char)(local_38 / 10000),
                       (char)((uint)(local_58 - local_60) / 10000),
                       (char)((local_50 - local_58) / 10000),(char)uVar7,
                       (char)((local_40 - local_48) / 10000),(char)uVar4);
  }
  DAT_140015160._1_1_ = 0;
  return uVar1;
}



===== PdcpStopStandbyExitPerftrack @ 140022ddc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpStopStandbyExitPerftrack(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  uint6 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  char cVar8;
  undefined8 *puVar9;
  char cVar10;
  undefined1 uVar11;
  int iVar12;
  longlong lVar13;
  ulonglong uVar14;
  uint *puVar15;
  ulonglong uVar16;
  int *piVar17;
  int *piVar18;
  ushort uVar19;
  undefined1 auStackY_238 [32];
  undefined8 local_1d8;
  undefined8 local_1c0;
  ulonglong local_1b8;
  undefined4 local_1b0;
  undefined4 local_1ac;
  uint local_1a8;
  uint local_1a4;
  uint local_1a0;
  uint local_19c;
  undefined1 local_198 [8];
  undefined8 local_190;
  undefined8 local_188;
  uint local_17c;
  undefined4 local_178;
  uint local_174;
  uint local_16c;
  uint local_168;
  uint local_164;
  uint local_160 [2];
  undefined8 local_158 [4];
  undefined8 *local_138;
  undefined8 local_130;
  undefined4 *local_128;
  undefined8 local_120;
  undefined4 *local_118;
  undefined8 local_110;
  uint *local_108;
  undefined8 local_100;
  uint *local_f8;
  undefined8 local_f0;
  uint *local_e8;
  undefined8 local_e0;
  uint *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined8 *local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  ulonglong *local_98;
  undefined8 local_90;
  undefined8 local_88 [3];
  uint local_70;
  uint local_60;
  uint local_58;
  int local_50 [6];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_238;
  if (DAT_140015160._2_1_ != '\0') {
    puVar6 = &DAT_1400313c0;
    puVar9 = local_88;
    lVar13 = 9;
    do {
      uVar3 = *puVar6;
      puVar6 = puVar6 + 0x2b;
      *puVar9 = uVar3;
      puVar9 = puVar9 + 1;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
    iVar12 = 8;
    puVar15 = local_160;
    piVar17 = local_50 + 2;
    piVar18 = local_50;
    do {
      iVar1 = *piVar18;
      iVar2 = *piVar17;
      piVar18 = piVar18 + -2;
      piVar17 = piVar17 + -2;
      *puVar15 = (uint)(iVar1 - iVar2) / 10000;
      puVar15 = puVar15 + -1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    lVar5 = PdcQueryAllPhasesDisengagedTime();
    PdcAcquireRwLockExclusive(0x140014d80);
    lVar13 = DAT_140014de0;
    PdcReleaseRwLockExclusive(0x140014d80);
    local_1b8 = (ulonglong)(uint)((int)DAT_140015148 - _DAT_140015140) / 10000;
    uVar16 = (lVar13 - lVar5 & 0xffffffffU) / 10000;
    uVar19 = (ushort)local_160[0];
    if (0xfffe < local_160[0]) {
      uVar19 = 0xffff;
    }
    local_1d8._0_4_ = (uint)uVar19;
    if (0xfffe < local_164) {
      local_1d8._0_4_ = CONCAT22(0xffff,uVar19);
    }
    local_1d8._0_6_ = CONCAT24((short)local_168,(uint)local_1d8);
    uVar4 = (uint6)local_1d8;
    if (0xfffe < local_168) {
      local_1d8._0_6_ = CONCAT24(0xffff,(uint)local_1d8);
      uVar4 = (uint6)local_1d8;
    }
    local_1d8 = (ulonglong)uVar4;
    if (0xfffe < local_16c) {
      local_1d8 = CONCAT26(0xffff,uVar4);
    }
    uVar14 = (ulonglong)local_174;
    uVar11 = (undefined1)local_174;
    if (0xfffe < local_174) {
      uVar11 = 0xff;
    }
    uVar7 = 0xff;
    if (local_17c < 0xff) {
      uVar7 = (char)local_17c;
    }
    cVar8 = '\0';
    if (PdcpPlatformAoAcCapable != '\0') {
      local_1c0 = uVar16;
      local_190 = PdcGetScenarioInstanceId();
      if ((DAT_140015c01 & 0x20) != 0) {
        uVar16 = (ulonglong)local_58 / 10000;
        McTemplateU0qqqqqqqqx_EtwWriteTransfer
                  ((ulonglong)local_58,uVar16,uVar16,local_60 / 10000,(char)(local_70 / 10000),
                   (char)local_1d8,(char)(local_1d8 >> 0x20),uVar11,uVar7,(char)local_1b8,
                   (char)local_190);
        uVar14 = (ulonglong)local_174;
        cVar8 = '\0';
        uVar16 = local_1c0;
      }
      local_188 = local_190;
      if (5 < DAT_140031288) {
        if (((_DAT_140031298 & 0x400000000000) == 0) ||
           (cVar10 = '\x01', (DAT_1400312a0 & 0x400000000000) != DAT_1400312a0)) {
          cVar10 = cVar8;
        }
        if (cVar10 != '\0') {
          local_138 = &local_188;
          local_1b0 = (undefined4)local_1b8;
          local_128 = &local_1b0;
          local_118 = &local_1ac;
          local_108 = &local_1a8;
          local_f8 = &local_1a4;
          local_e8 = &local_1a0;
          local_d8 = &local_19c;
          local_c8 = local_198;
          local_b8 = &local_190;
          local_a8 = &local_1c0;
          local_98 = &local_1b8;
          local_130 = 8;
          local_120 = 4;
          local_1ac = (undefined4)uVar16;
          local_110 = 4;
          local_1a8 = local_160[0];
          local_100 = 4;
          local_1a4 = local_164;
          local_f0 = 4;
          local_1a0 = local_168;
          local_e0 = 4;
          local_19c = local_16c;
          local_d0 = 4;
          local_c0 = 4;
          local_190 = CONCAT44(local_190._4_4_,(int)uVar14);
          local_b0 = 4;
          local_1c0 = CONCAT44(0x4000,local_178);
          local_a0 = 4;
          local_1b8 = CONCAT44(local_1b8._4_4_,local_17c);
          local_90 = 4;
          _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000eb32,uVar14,uVar16,0xd,local_158)
          ;
        }
      }
    }
    DAT_140015160._2_1_ = '\0';
  }
  return;
}



===== TraceLoggingRegister_EtwRegister_EtwSetInformation @ 140023200 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegister_EtwRegister_EtwSetInformation(longlong param_1)

{
  longlong *plVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar7 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = *(longlong *)(param_1 + 8);
  plVar1 = (longlong *)(param_1 + 0x20);
  local_28 = *(undefined4 *)(lVar3 + -0x10);
  uStack_24 = *(undefined4 *)(lVar3 + -0xc);
  uStack_20 = *(undefined4 *)(lVar3 + -8);
  uStack_1c = *(undefined4 *)(lVar3 + -4);
  if (*plVar1 != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x140023263;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x140023283;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140023297;
  return iVar6;
}



===== _tlgEnableCallback @ 1400232b0 =====

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



===== PdcPortMessageWorkerThread @ 140023330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcPortMessageWorkerThread(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 *_Dst;
  char cVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  undefined1 auStack_368 [8];
  undefined1 auStack_360 [24];
  uint local_348 [4];
  undefined8 local_338 [100];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_368;
  local_348[0] = 0;
  PdcAcquireLock();
  puVar7 = auStack_368;
  do {
    _Dst = PdcPortMessageQueue;
    if ((undefined8 **)PdcPortMessageQueue == &PdcPortMessageQueue) {
LAB_140023445:
      PdcPortWorkerRunning = 0;
      *(undefined8 *)(puVar7 + -8) = 0x140023451;
      PdcReleaseLock();
      *(undefined8 *)(puVar7 + -8) = 0x140023461;
      return;
    }
    if (((undefined8 **)PdcPortMessageQueue[1] != &PdcPortMessageQueue) ||
       (puVar2 = (undefined8 *)*PdcPortMessageQueue, (undefined8 *)puVar2[1] != PdcPortMessageQueue)
       ) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar7 = auStack_360;
      goto LAB_140023445;
    }
    puVar1 = PdcPortMessageQueue + 3;
    PdcPortMessageQueue = puVar2;
    puVar2[1] = &PdcPortMessageQueue;
    lVar3 = _Dst[0x67];
    uVar6 = PdcFormatMessageToClientVersion(puVar1,local_338,param_3,local_348);
    if ((int)uVar6 != 0) {
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                ("PdcPortMessageWorkerThread",*(undefined4 *)((longlong)_Dst + 0x44),local_348[0],
                 "PdcFormatMessageToClientVersion failed");
    }
    param_3 = 0x340;
    memset(_Dst,0,0x340);
    if ((int)uVar6 == 0) {
      cVar5 = ExAcquireRundownProtection(lVar3 + 8);
      if (cVar5 != '\0') {
        PdcReleaseLock();
        (**(code **)(lVar3 + 0x6d8))(*(undefined8 *)(lVar3 + 0x6d0),local_338);
        PdcAcquireLock();
        ExReleaseRundownProtection(lVar3 + 8);
      }
    }
  } while( true );
}



===== PdcPortQueueMessage @ 140023484 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PdcPortQueueMessage(longlong param_1,undefined4 param_2,undefined8 *param_3)

{
  void *_Dst;
  undefined8 uVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  size_t _Size;
  int *piVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  uint uVar12;
  longlong lVar13;
  undefined8 *puVar14;
  undefined1 *puVar15;
  ulonglong uVar16;
  undefined8 *puVar17;
  bool bVar18;
  undefined1 auStack_368 [8];
  undefined1 auStack_360 [24];
  uint local_348 [4];
  undefined8 local_338 [100];
  ulonglong local_18;
  
  puVar15 = auStack_368;
  local_18 = __security_cookie ^ (ulonglong)auStack_368;
  local_348[0] = 0;
  if (*(longlong *)(param_1 + 0x6b8) != 0) {
    uVar7 = PdcFormatMessageToClientVersion(param_3,local_338,param_3,local_348);
    puVar15 = auStack_368;
    uVar16 = uVar7 & 0xffffffff;
    if ((int)uVar7 == 0) {
      _Size = (size_t)local_348[0];
      if (*(uint *)(param_1 + 0x6c0) < local_348[0]) {
        pcVar3 = (code *)swi(0x29);
        _Size = (*pcVar3)(5);
        puVar15 = auStack_360;
      }
      _Dst = *(void **)(param_1 + 0x6b8);
      *(undefined8 *)(puVar15 + -8) = 0x140023523;
      memmove(_Dst,puVar15 + 0x30,_Size);
      uVar1 = *(undefined8 *)(param_1 + 0x6c8);
      *(undefined8 *)(puVar15 + -8) = 0x140023536;
      KeSetEvent(uVar1,0,0);
      *(undefined8 *)(param_1 + 0x6b8) = 0;
      *(undefined4 *)(param_1 + 0x6c0) = 0;
      *(undefined8 *)(param_1 + 0x6c8) = 0;
      uVar16 = 0;
    }
    else {
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                ("PdcPortQueueMessage",*(undefined4 *)((longlong)param_3 + 0x2c),local_348[0],
                 "PdcFormatMessageToClientVersion failed");
      puVar15 = auStack_368;
    }
    goto LAB_140023681;
  }
  uVar16 = 0;
  piVar8 = (int *)(param_1 + 0x48);
  uVar12 = 0;
  do {
    if (*piVar8 == 0) goto LAB_1400235ab;
    uVar12 = uVar12 + 1;
    piVar8 = piVar8 + 0xd0;
  } while (uVar12 < 2);
  if (uVar12 == 2) {
    uVar12 = *(uint *)(param_1 + 0x30);
    puVar14 = (undefined8 *)(ulonglong)uVar12;
    plVar9 = (longlong *)((longlong)puVar14 * 0x340 + 0x38 + param_1);
    lVar13 = *plVar9;
    if ((*(longlong **)(lVar13 + 8) == plVar9) &&
       (plVar2 = (longlong *)plVar9[1], (longlong *)*plVar2 == plVar9)) {
      *plVar2 = lVar13;
      uVar16 = 0x8000001a;
      *(longlong **)(lVar13 + 8) = plVar2;
      goto LAB_1400235ab;
    }
LAB_140023641:
    puVar11 = (undefined8 *)0x3;
    pcVar3 = (code *)swi(0x29);
    puVar10 = (undefined8 *)(*pcVar3)();
    puVar15 = auStack_360;
  }
  else {
LAB_1400235ab:
    *(uint *)(param_1 + 0x30) = uVar12;
    lVar13 = 6;
    puVar10 = (undefined8 *)((ulonglong)uVar12 * 0x340 + 0x38 + param_1);
    *(undefined4 *)(puVar10 + 2) = param_2;
    puVar10[0x67] = param_1;
    puVar14 = puVar10 + 3;
    do {
      puVar17 = param_3;
      puVar11 = puVar14;
      uVar1 = puVar17[1];
      *puVar11 = *puVar17;
      puVar11[1] = uVar1;
      uVar1 = puVar17[3];
      puVar11[2] = puVar17[2];
      puVar11[3] = uVar1;
      uVar1 = puVar17[5];
      puVar11[4] = puVar17[4];
      puVar11[5] = uVar1;
      uVar1 = puVar17[7];
      puVar11[6] = puVar17[6];
      puVar11[7] = uVar1;
      uVar1 = puVar17[9];
      puVar11[8] = puVar17[8];
      puVar11[9] = uVar1;
      uVar1 = puVar17[0xb];
      puVar11[10] = puVar17[10];
      puVar11[0xb] = uVar1;
      uVar1 = puVar17[0xd];
      puVar11[0xc] = puVar17[0xc];
      puVar11[0xd] = uVar1;
      uVar1 = puVar17[0xf];
      puVar11[0xe] = puVar17[0xe];
      puVar11[0xf] = uVar1;
      lVar13 = lVar13 + -1;
      puVar14 = puVar11 + 0x10;
      param_3 = puVar17 + 0x10;
    } while (lVar13 != 0);
    uVar4 = *(undefined4 *)((longlong)puVar17 + 0x84);
    uVar5 = *(undefined4 *)(puVar17 + 0x11);
    uVar6 = *(undefined4 *)((longlong)puVar17 + 0x8c);
    puVar14 = &PdcPortMessageQueue;
    *(undefined4 *)(puVar11 + 0x10) = *(undefined4 *)(puVar17 + 0x10);
    *(undefined4 *)((longlong)puVar11 + 0x84) = uVar4;
    *(undefined4 *)(puVar11 + 0x11) = uVar5;
    *(undefined4 *)((longlong)puVar11 + 0x8c) = uVar6;
    uVar1 = puVar17[0x13];
    puVar11[0x12] = puVar17[0x12];
    puVar11[0x13] = uVar1;
    puVar11 = DAT_140015008;
    if ((undefined8 *)*DAT_140015008 != &PdcPortMessageQueue) goto LAB_140023641;
  }
  bVar18 = PdcPortWorkerRunning == '\0';
  *puVar10 = puVar14;
  puVar10[1] = puVar11;
  *puVar11 = puVar10;
  DAT_140015008 = puVar10;
  if (bVar18) {
    PdcPortWorkerRunning = '\x01';
    *(undefined8 *)(puVar15 + -8) = 0x14002367c;
    ExQueueWorkItem(&PdcPortMessageWorker,5);
  }
LAB_140023681:
  *(undefined8 *)(puVar15 + -8) = 0x140023693;
  return uVar16;
}



===== PdcRegisterKernelClient @ 1400236b0 =====

ulonglong PdcRegisterKernelClient(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 *local_res10;
  undefined8 local_328 [100];
  
  local_res10 = (undefined8 *)0x0;
  memset(local_328,0,800);
  PdcAcquireLock();
  uVar2 = PdcSanitizeClientMessage(param_2,(int)*(short *)((longlong)param_2 + 2),local_328);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == 0) {
    uVar1 = PdcValidateClient((longlong)local_328,0);
    uVar3 = (ulonglong)uVar1;
    if (uVar1 == 0) {
      uVar1 = PdcpAllocateKernelClient((longlong)local_328,param_1,(longlong *)&local_res10);
      uVar3 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        PdcPostprocessClient(local_res10);
      }
    }
  }
  else {
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              ("PdcRegisterKernelClient",*(undefined4 *)(param_1 + 0x14),
               (int)*(short *)((longlong)param_2 + 2),"PdcSanitizeClientMessage failed");
  }
  PdcReleaseLock();
  return uVar3;
}



===== PdcSendKernelMessage @ 140023778 =====

int PdcSendKernelMessage(longlong param_1,undefined8 *param_2,undefined4 param_3)

{
  ulonglong uVar1;
  int iVar2;
  
  *(undefined4 *)((longlong)param_2 + 0x2c) = param_3;
  do {
    PdcSequenceId = PdcSequenceId + 1;
  } while (PdcSequenceId == 0);
  uVar1 = PdcPortQueueMessage(param_1,PdcSequenceId,param_2);
  iVar2 = 0;
  if (-1 < (int)uVar1) {
    iVar2 = (int)uVar1;
  }
  return iVar2;
}



===== PdcpAllocateKernelClient @ 1400237b4 =====

uint PdcpAllocateKernelClient(longlong param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x38);
  *param_3 = 0;
  if (uVar3 - 1 < 0x7c) {
    if (&PdcClientInfo + (ulonglong)uVar3 * 6 != (uint *)0x0) {
      iVar1 = *(int *)(param_1 + 0x3c);
      if ((*(int *)(param_1 + 0x2c) < 5) ||
         (((&PdcClientInfo)[(ulonglong)uVar3 * 6] & 0x10000000) == 0)) {
        if (iVar1 == 0) {
          uVar3 = PdcNotificationInitialize((undefined8 *)(ulonglong)uVar3,param_3);
        }
        else if (iVar1 == 1) {
          uVar4 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar4 == 0) {
            uVar3 = PdcResiliencyClientInitialize((ulonglong)uVar3,param_3);
          }
          else {
            uVar3 = PdcpResiliencyV2ClientRegister(uVar3,param_3);
          }
        }
        else {
          if (iVar1 != 2) {
            if (iVar1 == 3) {
              return 0xc0000002;
            }
            if (iVar1 == 4) {
              uVar3 = PdcTaskClientInitialize
                                ((undefined8 *)(ulonglong)uVar3,param_3,param_1 + 0x48,
                                 (undefined8 *)((ulonglong)uVar3 * 3));
              goto LAB_1400238c4;
            }
            if (iVar1 == 5) {
              uVar3 = PdcSignalClientInitialize(uVar3,(int *)(param_1 + 200),param_3);
              goto LAB_1400238c4;
            }
            if (iVar1 == 6) {
              return 0xc0000002;
            }
            if (iVar1 != 7) {
              if (iVar1 == 8) {
                return 0xc0000002;
              }
              return 0xc000000d;
            }
          }
          uVar3 = PdcActivatorInitialize((uint *)(ulonglong)uVar3,iVar1,param_1 + 0x48,param_3);
        }
LAB_1400238c4:
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        lVar2 = *param_3;
        *(undefined1 *)(lVar2 + 0x18) = 0;
        *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(param_1 + 0x2c);
        *(code **)(param_2 + 0x28) = PdcpProcessSynchKernelMessage;
        *(longlong *)(param_2 + 0x18) = lVar2;
        *(code **)(param_2 + 0x20) = PdcpProcessReceivedKernelMessage;
        *(longlong *)(lVar2 + 0x20) = param_2;
        PdcPrint(2,"%s: Port (%p) attached to KM client(%p).\n","PdcpAllocateKernelClient",param_2);
        return uVar3;
      }
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                ("PdcpAllocateKernelClient",uVar3,iVar1,"PDC client is deprecated");
    }
  }
  return 0xc000000d;
}



===== PdcpProcessReceivedKernelMessage @ 140023930 =====

ulonglong PdcpProcessReceivedKernelMessage
                    (longlong *param_1,undefined8 *param_2,uint param_3,ulonglong param_4)

{
  ulonglong uVar1;
  
  PdcAcquireLock();
  uVar1 = PdcpProcessReceivedKernelMessageUnsafe(param_1,param_2,param_3,param_4);
  PdcReleaseLock();
  return uVar1 & 0xffffffff;
}



===== PdcpProcessReceivedKernelMessageUnsafe @ 14002397c =====

ulonglong PdcpProcessReceivedKernelMessageUnsafe
                    (longlong *param_1,undefined8 *param_2,uint param_3,ulonglong param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  uint uVar10;
  longlong *plVar11;
  undefined8 *puVar12;
  undefined1 auStack_348 [8];
  undefined1 auStack_340 [24];
  undefined8 local_328 [5];
  int local_300;
  
  memset(local_328,0,800);
  puVar12 = local_328;
  uVar6 = PdcSanitizeClientMessage(param_2,param_3,puVar12);
  puVar9 = auStack_348;
  uVar8 = uVar6 & 0xffffffff;
  if ((int)uVar6 == 0) {
    if (local_300 == 1) {
      lVar2 = param_1[4];
      *(undefined8 *)(lVar2 + 0x18) = 0;
      plVar11 = (longlong *)(lVar2 + 0x38);
      *(undefined8 *)(lVar2 + 0x20) = 0;
      uVar6 = 0;
      uVar7 = 1;
      do {
        local_300 = (int)uVar7;
        if ((int)plVar11[2] != 0) {
          lVar3 = *plVar11;
          if ((*(longlong **)(lVar3 + 8) != plVar11) ||
             (plVar4 = (longlong *)plVar11[1], (longlong *)*plVar4 != plVar11)) {
            pcVar5 = (code *)swi(0x29);
            (*pcVar5)(3);
            puVar9 = auStack_340;
            goto LAB_140023a61;
          }
          *plVar4 = lVar3;
          uVar7 = 0;
          *(longlong **)(lVar3 + 8) = plVar4;
          puVar12 = (undefined8 *)0x340;
          memset((void *)(uVar6 * 0x340 + 0x38 + lVar2),0,0x340);
        }
        uVar10 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar10;
        plVar11 = plVar11 + 0x68;
      } while (uVar10 < 2);
      PdcFreeClient(param_1);
    }
    else {
LAB_140023a61:
      iVar1 = (int)param_1[2];
      if (iVar1 == 0) {
        *(undefined8 *)(puVar9 + -8) = 0x140023b1c;
        PdcpNotificationClientReceive((ulonglong)param_1,(longlong)(puVar9 + 0x20),puVar12,param_4);
      }
      else if (iVar1 == 1) {
        *(undefined8 *)(puVar9 + -8) = 0x140023ad7;
        uVar6 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar6 == 0) {
          if (((int)param_1[2] != 1) || (*(int *)(puVar9 + 0x48) != 5)) {
            return 0xc000000d;
          }
          *(undefined8 *)(puVar9 + -8) = 0x140023afc;
          uVar7 = PdcpResiliencyClientReceive((longlong)param_1,(longlong)(puVar9 + 0x20));
          uVar10 = (uint)uVar7;
        }
        else {
          *(undefined8 *)(puVar9 + -8) = 0x140023b0d;
          uVar7 = PdcpResiliencyV2ClientHandleMessage((longlong)param_1,(longlong)(puVar9 + 0x20));
          uVar10 = (uint)uVar7;
        }
        uVar8 = (ulonglong)uVar10;
      }
      else if (iVar1 == 2) {
        if (local_300 == 4) {
          *(undefined8 *)(puVar9 + -8) = 0x140023ad0;
          PdcpReceiveActivatorClient((longlong)param_1,(undefined8 *)(puVar9 + 0x20));
        }
      }
      else if (iVar1 == 4) {
        if (local_300 == 7) {
          *(undefined8 *)(puVar9 + -8) = 0x140023abc;
          PdcpTaskClientReceive((longlong)param_1,puVar9 + 0x20);
        }
      }
      else if (iVar1 == 5) {
        *(undefined8 *)(puVar9 + -8) = 0x140023aa8;
        PdcSignalClientReceive((longlong)param_1,(longlong)(puVar9 + 0x20));
      }
      else if (iVar1 == 7) {
        *(undefined8 *)(puVar9 + -8) = 0x140023a96;
        PdcV2ActivatorReceive((longlong)param_1,(undefined8 *)(puVar9 + 0x20),(longlong)puVar12);
      }
    }
  }
  else {
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              ("PdcpProcessReceivedKernelMessage",(int)param_1[2],param_3,
               "PdcSanitizeClientMessage failed");
  }
  return uVar8;
}



===== PdcpProcessSynchKernelMessage @ 140023b50 =====

ulonglong PdcpProcessSynchKernelMessage
                    (longlong *param_1,undefined8 *param_2,uint param_3,ulonglong param_4)

{
  longlong lVar1;
  code *pcVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [40];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = param_1[4];
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  PdcAcquireLock();
  puVar4 = auStack_58;
  if (*(longlong *)(lVar1 + 0x6b8) != 0) {
    PdcReleaseLock();
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_50;
  }
  *(undefined8 *)(puVar4 + -8) = 0x140023bad;
  KeInitializeEvent(puVar4 + 0x30,1);
  *(undefined8 **)(lVar1 + 0x6b8) = param_2;
  *(undefined1 **)(lVar1 + 0x6c8) = puVar4 + 0x30;
  *(uint *)(lVar1 + 0x6c0) = param_3;
  *(undefined8 *)(puVar4 + -8) = 0x140023bd9;
  uVar3 = PdcpProcessReceivedKernelMessageUnsafe(param_1,param_2,param_3,param_4);
  *(undefined8 *)(puVar4 + -8) = 0x140023be0;
  PdcReleaseLock();
  if (-1 < (int)uVar3) {
    *(undefined8 *)(puVar4 + 0x20) = 0;
    *(undefined8 *)(puVar4 + -8) = 0x140023bfe;
    KeWaitForSingleObject(puVar4 + 0x30,0,0,0);
  }
  return uVar3 & 0xffffffff;
}



===== PdcAreAllPhasesDisengaged @ 140023c30 =====

undefined1 PdcAreAllPhasesDisengaged(void)

{
  undefined1 uVar1;
  
  PdcAcquireRwLockExclusive(0x140014d80);
  uVar1 = DAT_140014dc8;
  PdcReleaseRwLockExclusive(0x140014d80);
  return uVar1;
}



===== PdcDisengagePhases @ 140023c70 =====

undefined4 PdcDisengagePhases(void)

{
  undefined4 uVar1;
  
  PdcAcquireRwLockExclusive(0x140014d80);
  uVar1 = PdcpEngageDisengagePhases('\0',0x3f);
  PdcReleaseRwLockExclusive(0x140014d80);
  return uVar1;
}



===== PdcDisplayStateUpdate @ 140023cb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcDisplayStateUpdate(int param_1)

{
  undefined8 uVar1;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  PdcAcquireRwLockExclusive(0x140014d80);
  uVar1 = KeQueryInterruptTimePrecise(local_res10);
  if (param_1 == 0) {
    _DAT_140014de8 = uVar1;
  }
  else if (param_1 == 1) {
    DAT_140014de0 = uVar1;
  }
  PdcReleaseRwLockExclusive(0x140014d80);
  return;
}



===== PdcEngagePhases @ 140023d10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcEngagePhases(undefined4 param_1)

{
  undefined8 local_res10 [3];
  
  PdcAcquireRwLockExclusive(0x140014d80);
  local_res10[0] = 0;
  DAT_140014db4 = 1;
  _DAT_140014df0 = param_1;
  _DAT_140014db8 = KeQueryInterruptTimePrecise(local_res10);
  PdcGetPolicyWorker(2);
  PdcCheckForWork();
  PdcReleaseRwLockExclusive(0x140014d80);
  return 0;
}



===== PdcGetResourceMask @ 140023d7c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 PdcGetResourceMask(void)

{
  undefined4 uVar1;
  
  PdcAcquireRwLockExclusive(0x140014d80);
  uVar1 = _DAT_140014df0;
  PdcReleaseRwLockExclusive(0x140014d80);
  return uVar1;
}



===== PdcMonitorControl @ 140023db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PdcMonitorControl(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 in_register_0000000c;
  undefined4 local_res18 [2];
  undefined4 local_res20;
  undefined4 local_res24;
  undefined8 local_18 [2];
  
  local_res18[0] = 0xffffffff;
  local_18[0] = 10;
  iVar1 = (*DAT_1400150a0)(CONCAT71((int7)(CONCAT44(in_register_0000000c,param_1) >> 8),1),
                           local_res18,local_18);
  if (-1 < iVar1) {
    local_res20 = param_1;
    local_res24 = param_2;
    iVar1 = (*DAT_1400150a8)(&local_res20,local_res18[0]);
    (*DAT_1400150a0)(0,local_res18,0);
  }
  return iVar1;
}



===== PdcRecordLogEntry @ 140023e3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcRecordLogEntry(undefined4 param_1)

{
  undefined1 auVar1 [16];
  uint uVar2;
  ulonglong uVar3;
  void *pvVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined *puVar8;
  bool bVar9;
  undefined1 auStackY_a8 [32];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70 [2];
  undefined8 local_68 [4];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  bVar9 = DAT_140014d88 != SystemReserved1[0xf];
  if (bVar9) {
    PdcAcquireRwLockExclusive(0x140014d80);
  }
  puVar8 = &DAT_140014df8;
  uVar6 = (ulonglong)DAT_140014df4;
  DAT_140014df4 = DAT_140014df4 + 1 & 0x3f;
  pvVar4 = (void *)GetPdcLockThread();
  uVar3 = _DAT_fffff78000000008;
  uVar7 = 0xffffffff;
  if (pvVar4 == SystemReserved1[0xf]) {
    uVar7 = (ulonglong)DAT_14003100c;
  }
  auVar1._8_8_ = 0;
  auVar1._0_8_ = _DAT_fffff78000000008;
  uVar5 = SUB168(ZEXT816(0x346dc5d63886594b) * auVar1,0);
  puVar8[uVar6 * 8 + 4] = (char)param_1;
  uVar2 = DAT_140031288;
  *(int *)(puVar8 + uVar6 * 8) = (int)(uVar3 / 10000);
  puVar8[uVar6 * 8 + 6] = 0xff;
  puVar8[uVar6 * 8 + 5] = (char)uVar7;
  if (5 < uVar2) {
    local_3c = 0;
    local_48 = &local_78;
    local_74 = 0xffffffff;
    local_2c = 0;
    local_1c = 0;
    local_38 = &local_74;
    local_28 = local_70;
    local_40 = 4;
    local_30 = 4;
    local_20 = 4;
    local_70[0] = (undefined4)uVar7;
    local_78 = param_1;
    uVar5 = _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000ecce,uVar6,uVar7,5,local_68);
  }
  if (bVar9) {
    uVar5 = PdcReleaseRwLockExclusive(0x140014d80);
  }
  return uVar5;
}



===== PdcSessionConnectionEvent @ 140023fa0 =====

void PdcSessionConnectionEvent(uint param_1,byte param_2,char param_3)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  char *pcVar4;
  ulonglong uVar5;
  
  bVar1 = false;
  pcVar4 = "Console";
  if (param_2 == 0) {
    pcVar4 = "Remote";
  }
  uVar3 = 2;
  PdcPrint(2,"%s:%s session %u is %s\n","PdcSessionConnectionEvent",pcVar4);
  if ((DAT_140015c01 & 2) != 0) {
    McTemplateU0qqq_EtwWriteTransfer
              (uVar3,&PDC_SESSION_CONNECT,(ulonglong)param_1,(uint)param_2,param_3);
  }
  PdcAcquireRwLockExclusive(0x140014d80);
  cVar2 = DAT_140014dac;
  if (param_3 == '\0') {
    DAT_140014da4 = DAT_140014da4 - 1;
    uVar5 = (ulonglong)DAT_140014da4;
    if (param_2 != 0) {
      PdcMonitor = 0xffffffff;
    }
  }
  else {
    if (param_2 != 0) {
      DAT_140014dac = '\x01';
      PdcMonitor = param_1;
    }
    bVar1 = param_2 != 0 && cVar2 == '\0';
    DAT_140014da4 = DAT_140014da4 + 1;
    uVar5 = (ulonglong)DAT_140014da4;
  }
  pcVar4 = "%s:Connected Sessions Count %u, Console Session:%d\n";
  uVar3 = 2;
  PdcPrint(2,"%s:Connected Sessions Count %u, Console Session:%d\n","PdcSessionCheck",uVar5);
  if ((DAT_140015c01 & 2) != 0) {
    McTemplateU0qqqqqqqtqqq_EtwWriteTransfer
              (uVar3,pcVar4,(ulonglong)DAT_140014da4,PdcMonitor,(char)DAT_140014da8);
  }
  if ((PdcMonitor == 0xffffffff) || (DAT_140014da4 != 1)) {
    if ((param_3 != '\0') && (DAT_140014da4 == 2)) {
      PdcGetPolicyWorker(4);
      PdcCheckForWork();
    }
  }
  else {
    PdcSetTimer(0x140014cc0,10000);
  }
  PdcReleaseRwLockExclusive(0x140014d80);
  if (bVar1) {
    PdcpDeferSwitchSignalSystemStarted();
  }
  return;
}



===== PdcSystemStarted @ 140024158 =====

undefined1 PdcSystemStarted(void)

{
  return DAT_140014dac;
}



===== PdcpAcquireMonitorLock @ 140024168 =====

void PdcpAcquireMonitorLock(void)

{
  PdcAcquireRwLockExclusive(0x140014d80);
  return;
}



===== PdcpEngageDisengagePhases @ 140024184 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 PdcpEngageDisengagePhases(char param_1,undefined4 param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined8 local_res18 [2];
  
  uVar2 = 0;
  local_res18[0] = 0;
  if ((param_1 == '\0') && (DAT_140014db0 == 2)) {
    uVar2 = 0xc0000001;
    PdcRecordLogEntry(0xf);
  }
  else {
    DAT_140014db4 = param_1;
    _DAT_140014df0 = param_2;
    uVar1 = KeQueryInterruptTimePrecise(local_res18);
    if (param_1 == '\0') {
      _DAT_140014dc0 = uVar1;
    }
    else {
      _DAT_140014db8 = uVar1;
    }
    PdcGetPolicyWorker(2);
    PdcCheckForWork();
    if ((param_1 == '\0') && (uVar2 = 0, DAT_140014dc8 == '\0')) {
      uVar2 = 0x103;
    }
  }
  return uVar2;
}



===== PdcpEngageDisengagePhasesInternal @ 140024220 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpEngageDisengagePhasesInternal
               (undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  bool bVar3;
  undefined8 local_res8;
  
  bVar3 = DAT_140014db4 == '\0';
  local_res8 = 0;
  if ((bool)DAT_140015138 != bVar3) {
    if (DAT_140031020 != '\0') {
      PdcGroupRequest((uint *)0x1,'\0');
      DAT_140031020 = '\0';
    }
    if ((DAT_140014db4 == '\0') && (DAT_14003100c == 5)) {
      param_3 = "PdcCancelSuspendResumeWait";
      PdcPrint(2,"%s\n","PdcCancelSuspendResumeWait",param_4);
      PdcAcquireRwLockExclusive(0x140014ca0);
      if (DAT_140014c78 != 0) {
        param_3 = (char *)0x0;
        KeSetEvent(DAT_140014c78 + 8,0);
      }
      PdcReleaseRwLockExclusive(0x140014ca0);
    }
    PdcGroupRequest((uint *)0x1,bVar3);
    puVar2 = &local_res8;
    DAT_140015138 = bVar3;
    if (DAT_140014db4 == '\0') {
      DAT_140015148 = KeQueryInterruptTimePrecise();
      if (DAT_140015160._1_1_ != '\0') {
        if ((PdcpPlatformAoAcCapable != '\0') && ((DAT_140015c01 & 0x10) != 0)) {
          McTemplateU0_EtwWriteTransfer(puVar2,&PDC_ENTER_CS_ABORT,param_3);
        }
        DAT_140015160._1_1_ = '\0';
      }
      uVar1 = 0;
      PdcPhasesResetScenarioAccounting('\0');
      if ((PdcpPlatformAoAcCapable != '\0') && ((DAT_140015c01 & 0x10) != 0)) {
        McTemplateU0_EtwWriteTransfer(uVar1,&PDC_EXIT_CS_START,param_3);
      }
      DAT_140015160._2_1_ = '\x01';
    }
    else {
      _DAT_140015140 = KeQueryInterruptTimePrecise();
      if (DAT_140015160._2_1_ != '\0') {
        DAT_140015160._2_1_ = '\0';
      }
      uVar1 = CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
      PdcPhasesResetScenarioAccounting('\x01');
      if ((PdcpPlatformAoAcCapable != '\0') && ((DAT_140015c01 & 0x10) != 0)) {
        McTemplateU0_EtwWriteTransfer(uVar1,&PDC_ENTER_CS_START,param_3);
      }
      DAT_140015160._1_1_ = '\x01';
      if (DAT_140014db0 != 0) {
        PdcRecordLogEntry(0xe);
        DAT_140014db0 = 2;
      }
    }
  }
  return;
}



===== PdcpHandleSystemForegroundGroupStateChange @ 1400243d4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpHandleSystemForegroundGroupStateChange(void)

{
  ulonglong uVar1;
  
  uVar1 = 1;
  if (((DAT_140014dc8 == '\0') || (DAT_140014dd8 == '\0')) || ((_DAT_140014df0 & 1) == 0)) {
    uVar1 = 0;
  }
  PdcGroupEnable((uint *)0x0,uVar1);
  return;
}



===== PdcpReleaseMonitorLock @ 140024410 =====

void PdcpReleaseMonitorLock(void)

{
  PdcReleaseRwLockExclusive(0x140014d80);
  return;
}



===== PdcpSessionTimerCallback @ 140024430 =====

void PdcpSessionTimerCallback(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  PdcAcquireLock();
  PdcAcquireRwLockExclusive(0x140014d80);
  iVar3 = DAT_140014da4;
  if (PdcMonitor != -1) {
    iVar3 = DAT_140014da4 + -1;
  }
  if (-1 < iVar3) {
    puVar1 = PdcpGetGroup(2);
    if ((puVar1 != (uint *)0x0) && (*(char *)((longlong)puVar1 + 6) != '\0')) {
      iVar3 = iVar3 - puVar1[2];
      LOCK();
      puVar1[2] = puVar1[2] + iVar3;
      UNLOCK();
      if (*(char *)((longlong)puVar1 + 5) != '\0') {
        if (iVar3 < 1) {
          if (iVar3 < 0) {
            iVar2 = -iVar3;
            if (-iVar3 < 0) {
              iVar2 = iVar3;
            }
            PdcPhaseDereference((ulonglong)*puVar1,iVar2);
          }
        }
        else {
          PdcPhaseReference((ulonglong)*puVar1,iVar3);
        }
      }
      PdcpGroupBlockingConditionsChanged((int *)puVar1);
    }
  }
  PdcReleaseRwLockExclusive(0x140014d80);
  PdcReleaseLock();
  return;
}



===== PdcpUmpoInitializationCompleteCallback @ 1400244d0 =====

void PdcpUmpoInitializationCompleteCallback(void)

{
  bool bVar1;
  
  PdcAcquireRwLockExclusive(0x140014d80);
  bVar1 = DAT_140014dad == '\0';
  if (bVar1) {
    DAT_140014dad = '\x01';
  }
  PdcReleaseRwLockExclusive(0x140014d80);
  if (bVar1) {
    PdcpDeferSwitchSignalSystemStarted();
  }
  return;
}



===== PdcSuspendResumeClientInitialize @ 140024518 =====

int PdcSuspendResumeClientInitialize(ulonglong param_1,ulonglong param_2,longlong *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong local_res18;
  
  lVar4 = 0;
  *param_3 = 0;
  uVar3 = 0xffffffff;
  lVar7 = 0;
  if ((((int)param_1 - 1U < 0x7c) && (&PdcClientInfo + (param_1 & 0xffffffff) * 6 != (uint *)0x0))
     && (((&PdcClientInfo)[(param_1 & 0xffffffff) * 6] & 8) != 0)) {
    local_res18 = 0;
    iVar2 = ObReferenceObjectByHandle
                      (param_2,0x10000000,*(undefined8 *)PsProcessType_exref,0,&local_res18,0);
    lVar7 = local_res18;
    if (-1 < iVar2) {
      uVar6 = 0x38;
      param_2 = 0x100;
      lVar4 = ExAllocatePool2(0x100,0x38,0x53636450);
      if (lVar4 == 0) {
        iVar2 = -0x3fffffe9;
      }
      else {
        *(undefined8 *)(lVar4 + 0x14) = 0;
        *(undefined8 *)(lVar4 + 0x1c) = 0;
        *(undefined4 *)(lVar4 + 0x24) = 0;
        *(undefined8 *)(lVar4 + 0x30) = 0;
        *(undefined4 *)(lVar4 + 0x10) = 3;
        *(longlong *)(lVar4 + 8) = lVar4;
        *(longlong *)lVar4 = lVar4;
        *(longlong *)(lVar4 + 0x28) = lVar7;
        uVar3 = PsGetProcessSessionIdEx(lVar7);
        *(undefined4 *)(lVar4 + 0x30) = uVar3;
        lVar5 = lVar4;
        PdcpInitializeClientOwnershipMask(lVar4,uVar6);
        uVar1 = *(undefined1 *)(lVar4 + 0x35);
        param_2 = CONCAT71((int7)((ulonglong)lVar5 >> 8),uVar1);
        iVar2 = 0;
        *(undefined1 *)(lVar4 + 0x36) = uVar1;
        *(undefined1 *)(lVar4 + 0x37) = uVar1;
        *param_3 = lVar4;
      }
    }
  }
  else {
    iVar2 = -0x3ffffff3;
    param_2 = param_1;
  }
  if ((DAT_140015c01 & 4) != 0) {
    McTemplateU0pqpqq_EtwWriteTransfer
              (param_2,&PDC_SUSPEND_RESUME_REGISTRATION,lVar7,uVar3,(char)lVar4,(char)param_1,
               (char)iVar2);
  }
  if (lVar7 != 0) {
    ObfDereferenceObjectWithTag(lVar7,0x746c6644);
  }
  return iVar2;
}



===== PdcSuspendResumeClientPostProcess @ 14002469c =====

void PdcSuspendResumeClientPostProcess(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  PdcAcquireRwLockExclusive(0x140014ca0);
  puVar3 = auStack_28;
  puVar2 = &PdcSuspendResumeContext;
  if ((undefined8 *)*DAT_140014c68 != &PdcSuspendResumeContext) {
    puVar2 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    DAT_140014c68 = (undefined8 *)(*pcVar1)();
    puVar3 = auStack_20;
  }
  *param_1 = puVar2;
  param_1[1] = DAT_140014c68;
  *DAT_140014c68 = param_1;
  *(undefined8 *)(puVar3 + -8) = 0x1400246e8;
  DAT_140014c68 = param_1;
  PdcReleaseRwLockExclusive(0x140014ca0);
  return;
}



===== PdcSuspendResumeIssueBroadcast @ 140024700 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcSuspendResumeIssueBroadcast(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined4 uVar9;
  longlong local_res8;
  undefined1 uVar10;
  undefined8 in_stack_ffffffffffffff90;
  undefined1 uVar11;
  uint local_48;
  int iStack_44;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar7 = 0;
  if (((param_1 == 0) || (uVar2 = *(uint *)(param_1 + 8), 3 < uVar2)) ||
     (2 < *(uint *)(param_1 + 0xc))) {
    uVar7 = 0xc000000d;
  }
  else {
    local_res8 = 0;
    if (*(uint *)(param_1 + 0xc) == 0) {
      local_res8 = -50000000;
    }
    local_48 = 0;
    iStack_44 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    KeInitializeEvent(&uStack_40,0,0);
    while( true ) {
      PdcAcquireRwLockExclusive(0x140014ca0);
      if (DAT_140014c78 == (uint *)0x0) break;
      PdcReleaseRwLockExclusive(0x140014ca0);
      KeWaitForSingleObject(&DAT_140014c88,0,0,0,0);
    }
    KeClearEvent(&DAT_140014c88);
    DAT_140014c78 = &local_48;
    _DAT_140014c80 = SystemReserved1[0xf];
    uVar5 = DAT_140014c70;
    do {
      DAT_140014c70 = uVar5;
      uVar6 = (ulonglong)DAT_140014c70;
      local_48 = DAT_140014c70;
      uVar5 = DAT_140014c70 + 1;
    } while (DAT_140014c70 == 0);
    if ((DAT_140015c01 & 4) != 0) {
      uVar10 = (undefined1)*(uint *)(param_1 + 0xc);
      uVar11 = (undefined1)DAT_140014c70;
      DAT_140014c70 = uVar5;
      McTemplateU0qqqpqqq_EtwWriteTransfer
                ((ulonglong)*(uint *)(param_1 + 0xc),uVar6,(ulonglong)*(uint *)(param_1 + 8),
                 *(undefined4 *)(param_1 + 0x10),uVar10,in_stack_ffffffffffffff90,uVar11,uVar10,
                 -(char)local_res8);
      uVar5 = DAT_140014c70;
    }
    DAT_140014c70 = uVar5;
    for (puVar8 = PdcSuspendResumeContext; (undefined8 **)puVar8 != &PdcSuspendResumeContext;
        puVar8 = (undefined8 *)*puVar8) {
      *(undefined1 *)((longlong)puVar8 + 0x34) = 0;
      if ((*(int *)(param_1 + 0x10) == -1) || (*(int *)(param_1 + 0x10) == *(int *)(puVar8 + 6))) {
        bVar1 = *(byte *)((longlong)puVar8 + 0x35);
        bVar4 = (byte)(1 << ((byte)uVar2 & 0x1f));
        if ((bVar4 & bVar1) != 0) {
          iVar3 = *(int *)(param_1 + 0xc);
          if (iVar3 == 0) {
            if (*(byte *)((longlong)puVar8 + 0x37) == bVar1) {
              PdcpSuspendResumeClientSend((longlong)puVar8,local_48,4);
              *(undefined1 *)((longlong)puVar8 + 0x34) = 1;
              iStack_44 = iStack_44 + 1;
            }
            *(byte *)((longlong)puVar8 + 0x37) = *(byte *)((longlong)puVar8 + 0x37) & ~bVar4;
            *(byte *)((longlong)puVar8 + 0x36) = *(byte *)((longlong)puVar8 + 0x36) & ~bVar4;
          }
          else if (iVar3 == 1) {
            if (((bVar4 & *(byte *)((longlong)puVar8 + 0x37)) == 0) &&
               (bVar4 = *(byte *)((longlong)puVar8 + 0x37) | bVar4,
               *(byte *)((longlong)puVar8 + 0x37) = bVar4, bVar4 == bVar1)) {
              uVar9 = 0x12;
              goto LAB_14002489d;
            }
          }
          else if (((iVar3 == 2) && ((bVar4 & *(byte *)((longlong)puVar8 + 0x36)) == 0)) &&
                  (bVar4 = *(byte *)((longlong)puVar8 + 0x36) | bVar4,
                  *(byte *)((longlong)puVar8 + 0x36) = bVar4, bVar4 == bVar1)) {
            uVar9 = 7;
LAB_14002489d:
            PdcpSuspendResumeClientSend((longlong)puVar8,local_48,uVar9);
            *(undefined1 *)((longlong)puVar8 + 0x34) = 1;
            iStack_44 = iStack_44 + 1;
          }
        }
      }
    }
    if ((iStack_44 != 0) && (local_res8 != 0)) {
      PdcReleaseRwLockExclusive(0x140014ca0);
      KeWaitForSingleObject(&uStack_40,0,0,0,&local_res8);
      PdcAcquireRwLockExclusive(0x140014ca0);
    }
    DAT_140014c78 = (uint *)0x0;
    _DAT_140014c80 = (void *)0x0;
    KeSetEvent(&DAT_140014c88,0,0);
    if (((2 < *(int *)(param_1 + 8) - 1U) && (PdcpPlatformAoAcCapable != '\0')) &&
       (*(int *)(param_1 + 0x10) != 0)) {
      uVar7 = 0x103;
    }
    PdcReleaseRwLockExclusive(0x140014ca0);
  }
  return uVar7;
}



===== PdcpInitializeClientOwnershipMask @ 140024994 =====

void PdcpInitializeClientOwnershipMask(longlong param_1,undefined8 param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  int local_res8 [2];
  int local_res10 [2];
  
  local_res10[0] = 0;
  *(byte *)(param_1 + 0x35) = *(byte *)(param_1 + 0x35) | 1;
  local_res8[0] = 0;
  cVar2 = RtlIsMultiSessionSku();
  if ((cVar2 == '\0') || ((*(int *)(param_1 + 0x30) + 1U & 0xfffffffe) != 0)) {
    lVar4 = PsReferencePrimaryToken(*(undefined8 *)(param_1 + 0x28));
    iVar3 = AppModelPolicy_Kernel_GetPolicy(lVar4,param_2,local_res8);
    if ((iVar3 < 0) || (local_res8[0] == 0x3a0002)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
      if (local_res8[0] == 0x3a0001) {
        *(byte *)(param_1 + 0x35) = *(byte *)(param_1 + 0x35) | 6;
      }
    }
    if (lVar4 != 0) {
      ObfDereferenceObject(lVar4);
    }
    if (bVar1) {
      return;
    }
  }
  lVar4 = PdcpSuspendResumeGetDamCallback();
  if (lVar4 != 0) {
    ExNotifyCallback(lVar4,*(undefined8 *)(param_1 + 0x28),local_res10);
    if (local_res10[0] == 1) {
      *(byte *)(param_1 + 0x35) = *(byte *)(param_1 + 0x35) | 6;
    }
    else if (local_res10[0] == 3) {
      *(byte *)(param_1 + 0x35) = *(byte *)(param_1 + 0x35) | 8;
    }
  }
  return;
}



===== PdcpPrintResumeSuspendMessage @ 140024a80 =====

void PdcpPrintResumeSuspendMessage(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = 2;
  PdcPrint(2,"\n%s:Suspend resume message (%p):\n\tTransactionId:%08lx\n\tPowerType:%08lx\n",param_1
           ,param_2);
  if ((DAT_140015c01 & 4) != 0) {
    McTemplateU0pqq_EtwWriteTransfer
              (uVar1,&PDC_SUSPEND_RESUME_MESSAGE,param_2,*(undefined4 *)(param_2 + 0x3c),
               (char)*(undefined4 *)(param_2 + 0x38));
  }
  return;
}



===== PdcpSuspendResumeClientReceive @ 140024ae0 =====

uint PdcpSuspendResumeClientReceive(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  char *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  
  uVar1 = *(uint *)(param_2 + 0x3c);
  pcVar3 = "PdcpSuspendResumeClientReceive";
  uVar5 = 0;
  PdcpPrintResumeSuspendMessage("PdcpSuspendResumeClientReceive",param_2);
  if ((DAT_140015c01 & 4) != 0) {
    McTemplateU0pt_EtwWriteTransfer(pcVar3,&PDC_SUSPEND_RESUME_RECEIVED,param_1,uVar1);
  }
  puVar2 = DAT_140014c78;
  if (((DAT_140014c78 == (uint *)0x0) || (*DAT_140014c78 != uVar1)) ||
     (*(char *)(param_1 + 0x34) == '\0')) {
    uVar4 = 1;
    PdcPrint(1,"%s:Incorrect sequence number: %08lx\n","PdcpSuspendResumeClientReceive",
             (ulonglong)uVar1);
    if ((DAT_140015c01 & 8) != 0) {
      if (puVar2 != (uint *)0x0) {
        uVar5 = *puVar2;
      }
      McTemplateU0pqq_EtwWriteTransfer
                (uVar4,&PDC_INVALID_SUSPEND_RESUME_NOTIFICATION,param_1,uVar5,(char)uVar1);
    }
    uVar5 = 0xc000000d;
  }
  else {
    *(undefined1 *)(param_1 + 0x34) = 0;
    PdcpSuspendResumeHandleClientCompletion(pcVar3);
  }
  return uVar5;
}



===== PdcpSuspendResumeClientSend @ 140024ba8 =====

void PdcpSuspendResumeClientSend(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 *_Dst;
  undefined8 local_328 [5];
  undefined4 local_300;
  undefined4 local_2f0;
  undefined4 local_2ec;
  
  _Dst = local_328;
  memset(_Dst,0,800);
  local_300 = 6;
  local_2f0 = param_3;
  local_2ec = param_2;
  if ((DAT_140015c01 & 4) != 0) {
    McTemplateU0pt_EtwWriteTransfer(_Dst,&PDC_SUSPEND_RESUME_RECEIVE,param_1,0);
  }
  PdcpPrintResumeSuspendMessage("PdcpSuspendResumeClientSend",(longlong)local_328);
  if (*(char *)(param_1 + 0x18) != '\0') {
    PdcSendUserMessage(*(longlong *)(param_1 + 0x20),local_328,0);
  }
  return;
}



===== PdcpSuspendResumeGetDamCallback @ 140024c44 =====

longlong PdcpSuspendResumeGetDamCallback(void)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  longlong local_res8;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  lVar2 = PdcDamExemptCheckCallback;
  local_res8 = 0;
  local_1c = 0;
  local_34 = 0;
  if (PdcDamExemptCheckCallback == 0) {
    local_30 = 0;
    local_38 = 0x30;
    local_28 = &PdcDamCallbackName;
    local_20 = 0x250;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ExCreateCallback(&local_res8,&local_38,0,0);
    if (-1 < iVar1) {
      lVar2 = 0;
      LOCK();
      bVar3 = PdcDamExemptCheckCallback == 0;
      if (bVar3) {
        PdcDamExemptCheckCallback = local_res8;
      }
      else {
        lVar2 = PdcDamExemptCheckCallback;
      }
      UNLOCK();
      if (bVar3) {
        lVar2 = local_res8;
      }
      else {
        ObfDereferenceObject(local_res8);
      }
    }
  }
  return lVar2;
}



===== PdcpSuspendResumeHandleClientCompletion @ 140024cf0 =====

void PdcpSuspendResumeHandleClientCompletion(undefined8 param_1)

{
  int *piVar1;
  longlong lVar2;
  
  lVar2 = DAT_140014c78;
  piVar1 = (int *)(DAT_140014c78 + 4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if ((DAT_140015c01 & 4) != 0) {
      McTemplateU0q_EtwWriteTransfer(param_1,&PDC_SUSPEND_RESUME_ALL_CLIENT_RESPONDED,0);
    }
    KeSetEvent(lVar2 + 8,0,0);
  }
  return;
}



===== PdcActivateNotification @ 140024d40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PdcActivateNotification
                    (uint param_1,ulonglong param_2,undefined4 param_3,longlong param_4,uint param_5
                    ,char param_6)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  ulonglong uVar5;
  longlong lVar6;
  byte bVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined8 *puVar11;
  
  lVar6 = (longlong)(int)param_1;
  uVar9 = (ulonglong)param_1;
  uVar3 = 2;
  pcVar4 = 
  "%s: Starting notifications\n\tNotificationType:%lu\n\tDirection:%s\n\tClientContext:%p\n\tPdcSequence:%08lx\n\tValue:%lu\n\tWaitTime:%lu\n"
  ;
  PdcPrint(2,
           "%s: Starting notifications\n\tNotificationType:%lu\n\tDirection:%s\n\tClientContext:%p\n\tPdcSequence:%08lx\n\tValue:%lu\n\tWaitTime:%lu\n"
           ,"minkernel\\po\\pdc\\sys\\notification.c",uVar9);
  if ((Microsoft_Windows_PDCEnableBits & 0x10) != 0) {
    uVar9 = param_2;
    McTemplateU0qpqqq_EtwWriteTransfer
              (uVar3,pcVar4,(ulonglong)param_1,param_2,(char)param_3,param_6 != '\0',(char)param_5);
  }
  if ((param_1 < 6) && (param_4 != 0)) {
    lVar8 = lVar6 * 0x98;
    if ((&DAT_140014020)[lVar8] == '\0') {
      bVar7 = 0;
      if ((param_1 == 1) && (param_6 != '\0')) {
        uVar2 = PdcGetResourceMask();
        bVar7 = ~((byte)uVar2 >> 1) & 1;
      }
      if ((&DAT_140014030)[lVar8] == '\0') {
        *(undefined4 *)(&DAT_140014010 + lVar8) = param_3;
        *(undefined4 *)(&DAT_140014070 + lVar8) = 0;
        *(longlong *)(&DAT_140014018 + lVar8) = param_4;
        (&DAT_140014008)[lVar6 * 0x13] = param_2;
        *(undefined2 *)(&DAT_140014020 + lVar8) = 1;
        uVar10 = (uint)(param_6 != '\0');
        *(uint *)(&DAT_140014068 + lVar8) = uVar10;
        (&DAT_14001406c)[lVar8] = bVar7;
        if (param_5 == 0) {
          *(undefined8 *)(&DAT_140014028 + lVar8) = 0xffffffffffffffff;
          (&DAT_140014022)[lVar8] = 1;
          KeCancelTimer();
        }
        else {
          (&DAT_140014022)[lVar8] = 0;
          *(ulonglong *)(&DAT_140014028 + lVar8) =
               (ulonglong)param_5 * 10000000 + _DAT_fffff78000000008;
          PdcSetTimer((longlong)(&PdcNotificationTimers + lVar6 * 0xb8),(ulonglong)(param_5 * 1000))
          ;
        }
        PdcpNotificationWatchdogArm
                  (param_6,&PdcNotificationControls + lVar6 * 0x26,
                   (longlong)(&PdcNotificationWatchdogTimers + lVar6 * 0xb8));
        puVar1 = &DAT_140014078 + lVar6 * 0x13;
        puVar11 = (undefined8 *)*puVar1;
        if (puVar11 == puVar1) {
          (&DAT_140014021)[lVar8] = 1;
          if (*(longlong *)(&DAT_140014088 + lVar8) != 0) {
            *(undefined4 *)(&DAT_140014090 + lVar8) = 0;
            *(undefined8 *)(&DAT_140014088 + lVar8) = 0;
            KeCancelTimer(&PdcNotificationWatchdogTimers + lVar6 * 0xb8);
          }
          if ((&DAT_140014022)[lVar8] != '\0') {
            (&DAT_140014020)[lVar8] = 0;
            return 0;
          }
        }
        else {
          do {
            PdcpNotificationClientSend((longlong)puVar11,uVar10,bVar7);
            puVar11 = (undefined8 *)*puVar11;
          } while (puVar11 != puVar1);
        }
        uVar5 = 0x103;
      }
      else {
        uVar10 = (&PdcNotificationControls)[lVar6 * 0x26];
        (&DAT_140014031)[lVar8] = 1;
        uVar5 = PdcControlNotification(uVar10);
        uVar5 = uVar5 & 0xffffffff;
        PdcPrint(2,
                 "%s: Normal notifications blocked because not all catchup notifications have been received.\n"
                 ,"minkernel\\po\\pdc\\sys\\notification.c",uVar9);
        *(longlong *)(&DAT_140014050 + lVar8) = param_4;
        (&DAT_140014058)[lVar8] = param_6;
        *(uint *)(&DAT_140014038 + lVar8) = param_1;
        *(ulonglong *)(&DAT_140014040 + lVar8) = param_2;
        *(undefined4 *)(&DAT_140014048 + lVar8) = param_3;
        *(uint *)(&DAT_14001405c + lVar8) = param_5;
        (&DAT_140014060)[lVar8] = bVar7;
      }
    }
    else {
      uVar5 = 0xc0000189;
    }
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== PdcControlNotification @ 140024fc4 =====

undefined8 PdcControlNotification(uint param_1)

{
  undefined8 *puVar1;
  bool bVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 local_328 [5];
  undefined4 local_300;
  uint local_2f0;
  undefined4 local_2e8;
  
  lVar4 = (longlong)(int)param_1;
  uVar3 = 2;
  PdcPrint(2,"%s: Control notification\n\tNotificationType:%lu\n\tFlags:%08lx\n",
           "minkernel\\po\\pdc\\sys\\notification.c",(ulonglong)param_1);
  if ((Microsoft_Windows_PDCEnableBits & 4) != 0) {
    McTemplateU0qq_EtwWriteTransfer(uVar3,&PDC_CONTROL_NOTIFICATION,(ulonglong)param_1,0x80000000);
  }
  if (param_1 < 6) {
    lVar6 = lVar4 * 0x98;
    if (*(int *)(&DAT_140014068 + lVar6) == 1) {
      uVar3 = 0;
      if (((&DAT_140014020)[lVar6] != '\0') || ((&DAT_140014030)[lVar6] != '\0')) {
        if ((&DAT_140014022)[lVar6] == '\0') {
          *(undefined8 *)(&DAT_140014028 + lVar6) = 0xffffffffffffffff;
          (&DAT_140014022)[lVar6] = 1;
          KeCancelTimer();
        }
        if ((&DAT_140014021)[lVar6] == '\0') {
          if (*(longlong *)(&DAT_140014088 + lVar6) != 0) {
            *(undefined4 *)(&DAT_140014090 + lVar6) = 0;
            *(undefined8 *)(&DAT_140014088 + lVar6) = 0;
            KeCancelTimer();
          }
          PdcpNotificationWatchdogArm
                    ('\0',&PdcNotificationControls + lVar4 * 0x26,
                     (longlong)(&PdcNotificationWatchdogTimers + lVar4 * 0xb8));
          puVar1 = &DAT_140014078 + lVar4 * 0x13;
          bVar2 = false;
          puVar5 = (undefined8 *)*puVar1;
          if (puVar5 != puVar1) {
            do {
              if (*(char *)((longlong)puVar5 + 0x2c) == '\0') {
                PdcpSetNotificationClientState((longlong)puVar5,5);
                memset(local_328,0,800);
                local_2f0 = *(uint *)(&DAT_140014068 + lVar6) | 0x80000000;
                local_300 = 3;
                local_2e8 = *(undefined4 *)(puVar5[7] + 0x10);
                PdcpPrintNotificationMessage
                          ("PdcpNotificationClientControl",puVar5,(longlong)local_328);
                if (*(char *)(puVar5 + 3) == '\0') {
                  PdcSendKernelMessage(puVar5[4],local_328,*(undefined4 *)((longlong)puVar5 + 0x14))
                  ;
                }
                else {
                  PdcSendUserMessage(puVar5[4],local_328,0);
                }
                bVar2 = true;
              }
              puVar5 = (undefined8 *)*puVar5;
            } while (puVar5 != puVar1);
            if (bVar2) {
              uVar3 = 0x103;
            }
          }
        }
        else {
          (&DAT_140014020)[lVar6] = 0;
        }
      }
    }
    else {
      uVar3 = 0xc000a003;
    }
  }
  else {
    uVar3 = 0xc00000ef;
  }
  return uVar3;
}



===== PdcNotificationClientsRundown @ 1400251a4 =====

void PdcNotificationClientsRundown(void)

{
  uint uVar1;
  undefined *puVar2;
  longlong lVar3;
  undefined **ppuVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  
  puVar5 = &DAT_140014078;
  lVar6 = 6;
  do {
    for (puVar7 = (undefined8 *)*puVar5; puVar7 != puVar5; puVar7 = (undefined8 *)*puVar7) {
      uVar1 = *(uint *)(puVar7 + 5);
      if (uVar1 - 1 < 0x7c) {
        ppuVar4 = &PTR_u_Invalid_client_140031f70 + (ulonglong)uVar1 * 3;
      }
      else {
        ppuVar4 = (undefined **)&DAT_00000010;
      }
      if ((Microsoft_Windows_PDCEnableBits & 0x10) != 0) {
        puVar2 = *ppuVar4;
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (*(short *)(puVar2 + lVar3 * 2) != 0);
        McTemplateU0pqqqzr3_EtwWriteTransfer
                  (puVar2,&PDC_NOTIFICATION_CLIENT_RUNDOWN,puVar7,uVar1,
                   (char)*(undefined4 *)(puVar5 + -0xf),(int)lVar3,puVar2);
      }
    }
    puVar5 = puVar5 + 0x13;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  return;
}



===== PdcNotificationFree @ 14002524c =====

undefined8 PdcNotificationFree(undefined8 *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  uint *puVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar6 = (uint *)param_1[7];
  puVar5 = (uint *)*param_1;
  if ((*(undefined8 **)(puVar5 + 2) != param_1) ||
     (plVar1 = (longlong *)param_1[1], (undefined8 *)*plVar1 != param_1)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    uVar4 = (*pcVar2)();
    return uVar4;
  }
  *plVar1 = (longlong)puVar5;
  *(longlong **)(puVar5 + 2) = plVar1;
  if (((char)puVar6[8] != '\0') && (*(char *)((longlong)param_1 + 0x2c) == '\0')) {
    puVar5 = puVar6 + 0x1e;
    for (puVar3 = *(uint **)puVar5; puVar3 != puVar5; puVar3 = *(uint **)puVar3) {
      if ((char)puVar3[0xb] == '\0') goto LAB_1400252ec;
    }
    *(undefined1 *)((longlong)puVar6 + 0x21) = 1;
    if (*(longlong *)(puVar6 + 0x22) != 0) {
      puVar6[0x24] = 0;
      puVar6[0x22] = 0;
      puVar6[0x23] = 0;
      puVar5 = (uint *)(&PdcNotificationWatchdogTimers + (longlong)(int)*puVar6 * 0xb8);
      KeCancelTimer();
    }
    if (*(char *)((longlong)puVar6 + 0x22) != '\0') {
      PdcpActivateCallback(puVar6);
      puVar5 = puVar6;
    }
  }
LAB_1400252ec:
  if ((Microsoft_Windows_PDCEnableBits & 4) != 0) {
    McTemplateU0pqq_EtwWriteTransfer
              (puVar5,&PDC_NOTIFICATION_DEREGISTRATION,param_1,*(undefined4 *)(param_1 + 5),0);
  }
  ExFreePoolWithTag(param_1,0);
  return 0;
}



===== PdcNotificationInitialize @ 14002533c =====

undefined4 PdcNotificationInitialize(undefined8 *param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 *_Dst;
  longlong lVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  longlong lVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  undefined *puVar9;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [56];
  
  puVar5 = auStack_58;
  uVar7 = 0;
  uVar8 = (ulonglong)param_1 & 0xffffffff;
  *param_2 = 0;
  _Dst = (undefined8 *)0x0;
  puVar9 = (undefined *)0x0;
  lVar6 = 0;
  iVar2 = (int)param_1;
  if (iVar2 - 1U < 0x7c) {
    if ((&PdcClientInfo + uVar8 * 6 != (uint *)0x0) && (((&PdcClientInfo)[uVar8 * 6] & 2) != 0)) {
      puVar9 = (&PTR_u_Invalid_client_140031f70)[uVar8 * 3];
      lVar6 = -1;
      do {
        lVar6 = lVar6 + 1;
      } while (*(short *)(puVar9 + lVar6 * 2) != 0);
      param_1 = (undefined8 *)0x100;
      _Dst = (undefined8 *)ExAllocatePool2(0x100,0x40,0x4e636450);
      puVar5 = auStack_58;
      if (_Dst == (undefined8 *)0x0) {
        uVar7 = 0xc0000017;
      }
      else {
        lVar3 = (longlong)*(int *)(&DAT_140031f64 + uVar8 * 0x18);
        param_1 = _Dst;
        memset(_Dst,0,0x40);
        puVar5 = auStack_58;
        _Dst[7] = &PdcNotificationControls + lVar3 * 0x26;
        *(int *)(_Dst + 5) = iVar2;
        puVar4 = (undefined8 *)(&DAT_140014080)[lVar3 * 0x13];
        if ((undefined8 *)*puVar4 != &DAT_140014078 + lVar3 * 0x13) {
          param_1 = (undefined8 *)0x3;
          pcVar1 = (code *)swi(0x29);
          puVar4 = (undefined8 *)(*pcVar1)();
          puVar5 = auStack_50;
        }
        *_Dst = &DAT_140014078 + lVar3 * 0x13;
        _Dst[1] = puVar4;
        *puVar4 = _Dst;
        (&DAT_140014080)[lVar3 * 0x13] = _Dst;
        *param_2 = _Dst;
      }
      goto LAB_14002542f;
    }
  }
  uVar7 = 0xc000000d;
LAB_14002542f:
  if ((Microsoft_Windows_PDCEnableBits & 4) != 0) {
    *(undefined **)(puVar5 + 0x30) = puVar9;
    *(int *)(puVar5 + 0x28) = (int)lVar6;
    *(undefined4 *)(puVar5 + 0x20) = uVar7;
    *(undefined8 *)(puVar5 + -8) = 0x140025457;
    McTemplateU0pqqqzr3_EtwWriteTransfer
              (param_1,&PDC_NOTIFICATION_REGISTRATION,_Dst,iVar2,puVar5[0x20],
               *(int *)(puVar5 + 0x28),*(undefined8 *)(puVar5 + 0x30));
  }
  return uVar7;
}



===== PdcNotificationPostprocess @ 140025480 =====

undefined8 PdcNotificationPostprocess(longlong param_1)

{
  longlong lVar1;
  
  if (PdcpPlatformAoAcCapable != '\0') {
    lVar1 = *(longlong *)(param_1 + 0x38);
    if (*(char *)(lVar1 + 0x20) == '\0') {
      if (*(int *)(lVar1 + 0x68) == 0) {
        return 0;
      }
      if (*(char *)(lVar1 + 0x31) != '\0') {
        return 0;
      }
      PdcPrint(2,
               "%s: Notification client %#p registered while notification has non-0 value. Sending catchup notification.\n"
               ,"minkernel\\po\\pdc\\sys\\notification.c",param_1);
      *(undefined1 *)(lVar1 + 0x30) = 1;
    }
    else if (*(char *)(param_1 + 0x18) == '\0') {
      return 0xc000000d;
    }
    *(undefined1 *)(lVar1 + 0x21) = 0;
    PdcpNotificationClientSend(param_1,*(int *)(lVar1 + 0x68),*(undefined1 *)(lVar1 + 0x6c));
  }
  return 0;
}



===== PdcpActivateCallback @ 140025508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpActivateCallback(uint *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *param_1;
  uVar2 = 2;
  PdcPrint(2,"%s: Finishing notifications for:%lu\n","minkernel\\po\\pdc\\sys\\notification.c",
           (ulonglong)uVar1);
  if ((Microsoft_Windows_PDCEnableBits & 4) != 0) {
    McTemplateU0q_EtwWriteTransfer(uVar2,&PDC_NOTIFICATION_CALLBACK,(ulonglong)uVar1);
  }
  *(undefined1 *)(param_1 + 8) = 0;
  (**(code **)(param_1 + 6))(*(undefined8 *)(param_1 + 2),param_1[4],param_1[0x1c]);
  return;
}



===== PdcpNotificationClientReceive @ 140025574 =====

undefined8
PdcpNotificationClientReceive
          (ulonglong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  char *pcVar5;
  undefined8 uVar6;
  int iVar7;
  
  uVar1 = *(uint *)(param_2 + 0x38);
  uVar2 = *(uint *)(param_2 + 0x40);
  puVar3 = *(uint **)(param_1 + 0x38);
  pcVar5 = "PdcpNotificationClientReceive";
  PdcpPrintNotificationMessage("PdcpNotificationClientReceive",param_1,param_2);
  if ((Microsoft_Windows_PDCEnableBits & 0x10) != 0) {
    param_4 = (ulonglong)uVar2;
    McTemplateU0pt_EtwWriteTransfer(pcVar5,&PDC_NOTIFICATION_RECEIVED,param_1,uVar2);
  }
  if ((((char)puVar3[0xc] == '\0') && ((char)puVar3[8] == '\0')) || (uVar2 != puVar3[4])) {
    uVar6 = 1;
    PdcPrint(1,"%s:Invalid notification (sequence number: %08lx)\n","PdcpNotificationClientReceive",
             (ulonglong)puVar3[4]);
    if ((Microsoft_Windows_PDCEnableBits & 0x20) != 0) {
      McTemplateU0pqq_EtwWriteTransfer
                (uVar6,&PDC_INVALID_NOTIFICATION,param_1,puVar3[4],(char)uVar2);
    }
    return 0xc000000d;
  }
  *(undefined1 *)(param_1 + 0x2c) = 1;
  if (uVar1 == 0) {
    if ((*(int *)(param_1 + 0x30) - 3U & 0xfffffffd) == 0) {
      iVar7 = 4;
    }
    else {
      if (*(int *)(param_1 + 0x30) != 2) goto LAB_14002566a;
      iVar7 = 1;
    }
    PdcpSetNotificationClientState(param_1,iVar7);
  }
  else {
    PdcpSetNotificationClientState(param_1,6);
    if ((int)uVar1 < 0) {
      puVar3[0x1c] = uVar1;
    }
  }
LAB_14002566a:
  if ((char)puVar3[0xc] != '\0') {
    PdcPrint(2,"%s: Catchup reply from notification client %#p received.\n",
             "minkernel\\po\\pdc\\sys\\notification.c",param_1);
    *(undefined1 *)(puVar3 + 0xc) = 0;
    param_4 = param_1;
  }
  puVar4 = *(uint **)(puVar3 + 0x1e);
  while( true ) {
    if (puVar4 == puVar3 + 0x1e) {
      *(undefined1 *)((longlong)puVar3 + 0x21) = 1;
      uVar6 = 2;
      PdcPrint(2,"%s: All clients responded\n","minkernel\\po\\pdc\\sys\\notification.c",param_4);
      if ((Microsoft_Windows_PDCEnableBits & 4) != 0) {
        McTemplateU0q_EtwWriteTransfer
                  (uVar6,&PDC_NOTIFICATION_ALL_CLIENT_RESPONDED,(ulonglong)puVar3[0x1c]);
      }
      if (*(longlong *)(puVar3 + 0x22) != 0) {
        puVar3[0x24] = 0;
        puVar3[0x22] = 0;
        puVar3[0x23] = 0;
        KeCancelTimer(&PdcNotificationWatchdogTimers + (longlong)(int)*puVar3 * 0xb8);
      }
      if (((char)puVar3[8] == '\0') || (*(char *)((longlong)puVar3 + 0x22) == '\0')) {
        if (*(char *)((longlong)puVar3 + 0x31) != '\0') {
          PdcPrint(2,
                   "%s: Final catchup reply received; catchup replies no longer blocking normal notification round. Restarting notification round.\n"
                   ,"minkernel\\po\\pdc\\sys\\notification.c",param_4);
          *(undefined1 *)((longlong)puVar3 + 0x31) = 0;
          PdcActivateNotification
                    (puVar3[0xe],*(ulonglong *)(puVar3 + 0x10),puVar3[0x12],
                     *(longlong *)(puVar3 + 0x14),puVar3[0x17],(char)puVar3[0x16]);
        }
      }
      else {
        PdcpActivateCallback(puVar3);
      }
      return 0;
    }
    if ((char)puVar4[0xb] == '\0') break;
    puVar4 = *(uint **)puVar4;
  }
  return 0;
}



===== PdcpNotificationClientSend @ 140025788 =====

int PdcpNotificationClientSend(longlong param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 local_328 [5];
  undefined4 local_300;
  int local_2f0;
  undefined1 local_2ec;
  undefined4 local_2e8;
  
  memset(local_328,0,800);
  local_300 = 2;
  local_2e8 = *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x10);
  local_2f0 = param_2;
  local_2ec = param_3;
  PdcpPrintNotificationMessage("PdcpNotificationClientSend",param_1,(longlong)local_328);
  if (*(char *)(param_1 + 0x18) == '\0') {
    iVar1 = PdcSendKernelMessage
                      (*(longlong *)(param_1 + 0x20),local_328,*(undefined4 *)(param_1 + 0x14));
  }
  else {
    uVar2 = PdcSendUserMessage(*(longlong *)(param_1 + 0x20),local_328,0);
    iVar1 = (int)uVar2;
  }
  *(undefined1 *)(param_1 + 0x2c) = 0;
  iVar3 = 3;
  if (param_2 != 1) {
    iVar3 = (-(uint)(param_2 != 0) & 3) + 2;
  }
  PdcpSetNotificationClientState(param_1,iVar3);
  return iVar1;
}



===== PdcpNotificationQueueWorker @ 140025850 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpNotificationQueueWorker(uint *param_1)

{
  PdcAcquireLock();
  if (*(ulonglong *)(param_1 + 10) <= _DAT_fffff78000000008) {
    param_1[10] = 0xffffffff;
    param_1[0xb] = 0xffffffff;
    *(undefined1 *)((longlong)param_1 + 0x22) = 1;
    if (*(char *)((longlong)param_1 + 0x21) != '\0') {
      PdcpActivateCallback(param_1);
    }
  }
  PdcReleaseLock();
  return;
}



===== PdcpNotificationWatchdog @ 1400258a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpNotificationWatchdog(longlong param_1)

{
  int iVar1;
  uint *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  PdcAcquireLock();
  if ((*(longlong *)(param_1 + 0x88) != 0) &&
     (*(ulonglong *)(param_1 + 0x88) < _DAT_fffff78000000008)) {
    for (puVar3 = *(undefined8 **)(param_1 + 0x78); puVar3 != (undefined8 *)(param_1 + 0x78);
        puVar3 = (undefined8 *)*puVar3) {
      if (*(char *)((longlong)puVar3 + 0x2c) == '\0') {
        iVar1 = *(int *)(puVar3 + 6);
        if (iVar1 == 3) {
          uVar4 = PdcCsEntryNotificationAction;
        }
        else if ((iVar1 == 5) || (iVar1 == 2)) {
          uVar4 = 2;
        }
        else {
          uVar4 = 0;
        }
        if (*(uint *)(puVar3 + 5) - 1 < 0x7c) {
          puVar2 = &PdcClientInfo + (ulonglong)*(uint *)(puVar3 + 5) * 6;
        }
        else {
          puVar2 = (uint *)0x0;
        }
        if (((*puVar2 & 0x10000) == 0) || ((iVar1 != 2 && (iVar1 != 5)))) {
          if ((uVar4 & 1) != 0) {
            PdcTriageCaptureContext((longlong)puVar3,&local_38,'\x01');
            DbgkWerCaptureLiveKernelDump
                      (L"PDCNotification",0x15c,*(undefined4 *)(puVar3 + 5),1,puVar3,&local_38,0,0,1
                      );
          }
          if ((uVar4 & 2) != 0) {
            PdcTriageCaptureContext((longlong)puVar3,&local_38,'\0');
                    /* WARNING: Subroutine does not return */
            KeBugCheckEx(0x14f,*(undefined4 *)(puVar3 + 5),1,puVar3,&local_38);
          }
        }
        else {
          PdcpSkipUnresponsiveNotificationClient((ulonglong)puVar3,DAT_140015138 == '\0');
        }
      }
    }
  }
  PdcReleaseLock();
  return;
}



===== PdcpNotificationWatchdogArm @ 140025a38 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpNotificationWatchdogArm(char param_1,int *param_2,longlong param_3)

{
  int iVar1;
  
  iVar1 = 9;
  if (*param_2 != 6) {
    iVar1 = *(int *)(&DAT_14000d260 + (longlong)*param_2 * 4);
  }
  if (param_1 == '\0') {
    iVar1 = PdcCriticalNotificationTimeout;
  }
  else {
    iVar1 = PdcPhaseGetNotificationEntryWatchdogTimeout(iVar1);
  }
  param_2[0x24] = iVar1;
  if (iVar1 != 0) {
    *(ulonglong *)(param_2 + 0x22) = (ulonglong)(uint)(iVar1 * 10000000) + _DAT_fffff78000000008;
    PdcSetTimer(param_3,(ulonglong)(uint)((iVar1 + 1) * 1000));
  }
  return;
}



===== PdcpPrintNotificationMessage @ 140025ab0 =====

void PdcpPrintNotificationMessage(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  char *pcVar1;
  bool bVar2;
  
  pcVar1 = "%s:Client (%p):\n%s message (%p):\n\tStatus/Value:%08lx\n\tSequenceNumber:%08lx\n";
  PdcPrint(2,"%s:Client (%p):\n%s message (%p):\n\tStatus/Value:%08lx\n\tSequenceNumber:%08lx\n",
           param_1,param_2);
  if ((Microsoft_Windows_PDCEnableBits & 0x10) != 0) {
    bVar2 = *(int *)(param_3 + 0x28) == 3;
    McTemplateU0ppqqq_EtwWriteTransfer
              ((ulonglong)bVar2,pcVar1,param_2,param_3,bVar2,(char)*(undefined4 *)(param_3 + 0x38),
               (char)*(undefined4 *)(param_3 + 0x40));
  }
  return;
}



===== PdcpSetNotificationClientState @ 140025b4c =====

void PdcpSetNotificationClientState(longlong param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 != param_2) {
    if (iVar1 == 0) {
      bVar2 = param_2 - 1U < 3;
      bVar3 = param_2 - 1U == 3;
LAB_140025b6c:
      if (bVar2 || bVar3) goto LAB_140025bca;
    }
    else if (iVar1 == 1) {
      bVar2 = param_2 == 3;
LAB_140025b9e:
      if (bVar2) goto LAB_140025bca;
    }
    else {
      if (iVar1 == 2) {
        if (param_2 == 1) goto LAB_140025bca;
        bVar2 = param_2 == 6;
      }
      else {
        if (iVar1 == 3) {
          bVar2 = param_2 - 4U < 2;
          bVar3 = param_2 - 4U == 2;
          goto LAB_140025b6c;
        }
        if (iVar1 == 4) {
          bVar2 = param_2 == 2;
          goto LAB_140025b9e;
        }
        if (iVar1 == 5) {
          bVar2 = (param_2 - 4U & 0xfffffffd) == 0;
        }
        else {
          if (iVar1 != 6) goto LAB_140025bc5;
          if (param_2 == 1) goto LAB_140025bca;
          bVar2 = param_2 == 4;
        }
      }
      if (bVar2) goto LAB_140025bca;
    }
  }
LAB_140025bc5:
  MicrosoftTelemetryAssertTriggeredNoArgsKM();
LAB_140025bca:
  *(int *)(param_1 + 0x30) = param_2;
  return;
}



===== PdcpSkipUnresponsiveNotificationClient @ 140025be0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcpSkipUnresponsiveNotificationClient(ulonglong param_1,byte param_2)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined1 auStackY_418 [32];
  undefined4 local_3e8;
  int local_3e4;
  undefined4 local_3e0;
  uint local_3dc;
  uint local_3d8;
  int local_3d4 [3];
  undefined1 local_3c8 [40];
  undefined4 local_3a0;
  undefined4 local_390;
  int local_388;
  undefined8 local_a8 [4];
  undefined4 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  int *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_418;
  piVar2 = *(int **)(param_1 + 0x38);
  uVar5 = 9;
  iVar1 = *piVar2;
  if (iVar1 != 6) {
    uVar5 = (ulonglong)*(uint *)(&DAT_14000d260 + (longlong)iVar1 * 4);
  }
  if (5 < DAT_140031288) {
    if (((_DAT_140031298 & 0x400000000008) == 0) ||
       ((DAT_1400312a0 & 0x400000000008) != DAT_1400312a0)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (bVar3) {
      local_7c = 0;
      local_88 = &local_3e8;
      local_6c = 0;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_78 = &local_3e4;
      local_68 = &local_3e0;
      local_58 = &local_3dc;
      local_48 = &local_3d8;
      local_38 = local_3d4;
      local_80 = 4;
      local_70 = 4;
      local_60 = 4;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_3e0 = (undefined4)uVar5;
      local_3dc = (uint)param_2;
      local_3d8 = (uint)*(byte *)(piVar2 + 0x16);
      local_3e8 = *(undefined4 *)(param_1 + 0x28);
      local_3e4 = iVar1;
      local_3d4[0] = piVar2[0x24];
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140031288,&DAT_14000ed0a,(longlong)iVar1,uVar5,8,local_a8);
    }
  }
  uVar4 = 800;
  memset(local_3c8,0,800);
  local_390 = 0;
  local_3a0 = 2;
  local_388 = piVar2[4];
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar4 = PdcpNotificationClientReceive(param_1,(longlong)local_3c8,uVar4,uVar5);
  }
  else {
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== PdcTaskClientFree @ 140025dcc =====

undefined8
PdcTaskClientFree(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  char cVar4;
  undefined7 extraout_var;
  undefined8 uVar5;
  
  if (param_1[0x6c] != 0) {
    SleepstudyHelperDestroyBlocker();
    param_1[0x6c] = 0;
  }
  PdcpLogTaskClientAction("Delete TaskClient",(longlong)param_1,param_3,param_4);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) != param_1) ||
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    uVar5 = (*pcVar3)();
    return uVar5;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  if (DAT_140015c01 < '\0') {
    McTemplateU0pqq_EtwWriteTransfer(lVar1,&PDC_TASK_DEREGISTRATION,param_1,(int)param_1[5],0);
  }
  if (*(int *)((longlong)param_1 + 0x2c) != 0) {
    if ((int)param_1[6] == 0) {
      cVar4 = PdcpGetTaskClientRequestGroup((longlong)param_1);
      PdcGroupRequest((uint *)(CONCAT71(extraout_var,cVar4) & 0xffffffff),'\0');
    }
    *(undefined4 *)((longlong)param_1 + 0x2c) = 0;
  }
  ExFreePoolWithTag(param_1,0);
  return 0;
}



===== PdcTaskClientInitialize @ 140025e80 =====

undefined4
PdcTaskClientInitialize
          (undefined8 *param_1,undefined8 *param_2,undefined8 param_3,undefined8 *param_4)

{
  code *pcVar1;
  undefined8 *_Dst;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined *puVar9;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [56];
  
  puVar6 = auStack_58;
  uVar5 = 0;
  iVar2 = (int)param_1;
  *param_2 = 0;
  _Dst = (undefined8 *)0x0;
  puVar9 = (undefined *)0x0;
  lVar7 = 0;
  if (iVar2 - 1U < 0x7c) {
    if ((&PdcClientInfo + ((ulonglong)param_1 & 0xffffffff) * 6 != (uint *)0x0) &&
       (((&PdcClientInfo)[((ulonglong)param_1 & 0xffffffff) * 6] & 0x10) != 0)) {
      puVar9 = (&PTR_u_Invalid_client_140031f70)[((ulonglong)param_1 & 0xffffffff) * 3];
      lVar7 = -1;
      do {
        lVar7 = lVar7 + 1;
      } while (*(short *)(puVar9 + lVar7 * 2) != 0);
      param_1 = (undefined8 *)0x100;
      _Dst = (undefined8 *)ExAllocatePool2(0x100,0x368,0x74636450);
      puVar6 = auStack_58;
      if (_Dst == (undefined8 *)0x0) {
        uVar5 = 0xc0000017;
      }
      else {
        memset(_Dst,0,0x368);
        puVar6 = auStack_58;
        *(undefined4 *)(_Dst + 2) = 4;
        puVar8 = &AllEaRules;
        *(int *)(_Dst + 5) = iVar2;
        for (puVar4 = AllEaRules; (undefined8 **)puVar4 != &AllEaRules;
            puVar4 = (undefined8 *)*puVar4) {
          if ((*(int *)(puVar4 + 2) == 2) &&
             ((*(byte *)((longlong)iVar2 + 0x28 + (longlong)puVar4) & 1) != 0)) {
            *(uint *)(_Dst + 6) = *(uint *)(_Dst + 6) | 1;
            break;
          }
        }
        puVar3 = &PdcTaskClients;
        if ((undefined8 *)*DAT_140013fe8 != &PdcTaskClients) {
          puVar3 = (undefined8 *)0x3;
          pcVar1 = (code *)swi(0x29);
          DAT_140013fe8 = (undefined8 *)(*pcVar1)();
          puVar6 = auStack_50;
        }
        *_Dst = puVar3;
        _Dst[1] = DAT_140013fe8;
        *DAT_140013fe8 = _Dst;
        DAT_140013fe8 = _Dst;
        *param_2 = _Dst;
        *(undefined8 *)(puVar6 + -8) = 0x140025f95;
        param_1 = _Dst;
        PdcpStatsCreateTaskClient((longlong)_Dst,puVar4,puVar8,param_4);
      }
      goto LAB_140025f9c;
    }
  }
  uVar5 = 0xc000000d;
LAB_140025f9c:
  if (DAT_140015c01 < '\0') {
    *(undefined **)(puVar6 + 0x30) = puVar9;
    *(int *)(puVar6 + 0x28) = (int)lVar7;
    *(undefined4 *)(puVar6 + 0x20) = uVar5;
    *(undefined8 *)(puVar6 + -8) = 0x140025fc5;
    McTemplateU0pqqqzr3_EtwWriteTransfer
              (CONCAT71((int7)((ulonglong)param_1 >> 8),DAT_140015c01),&PDC_TASK_REGISTRATION,_Dst,
               iVar2,puVar6[0x20],*(int *)(puVar6 + 0x28),*(undefined8 *)(puVar6 + 0x30));
  }
  return uVar5;
}



===== PdcpDereferenceTaskClient @ 140025fe8 =====

undefined4
PdcpDereferenceTaskClient(longlong param_1,undefined8 param_2,longlong param_3,ulonglong param_4)

{
  char cVar1;
  int iVar2;
  undefined7 extraout_var;
  uint *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x2c) == 0) {
    uVar4 = 0xc0000095;
  }
  else if (*(int *)(param_1 + 0x358) == 0x103) {
    uVar4 = 0xc000000d;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x2c) + -1;
    *(int *)(param_1 + 0x2c) = iVar2;
    if ((iVar2 == 0) && (*(int *)(param_1 + 0x30) == 0)) {
      cVar1 = PdcpGetTaskClientRequestGroup(param_1);
      puVar3 = (uint *)(CONCAT71(extraout_var,cVar1) & 0xffffffff);
      PdcGroupRequest(puVar3,'\0');
      if (DAT_140015c01 < '\0') {
        param_4 = (ulonglong)DAT_14003100c;
        param_3 = param_1;
        McTemplateU0pqq_EtwWriteTransfer(puVar3,&PDC_TASK_DEREFERENCE,param_1,DAT_14003100c,0);
      }
      if (*(longlong *)(param_1 + 0x360) != 0) {
        SleepstudyHelperBlockerActiveDereference();
      }
      PdcpLogTaskClientAction("TaskClient Inactive",param_1,param_3,param_4);
    }
  }
  PdcpTaskClientAcknowledge(param_1,uVar4);
  return uVar4;
}



===== PdcpGetTaskClientRequestGroup @ 140026098 =====

char PdcpGetTaskClientRequestGroup(longlong param_1)

{
  uint *puVar1;
  
  if (*(uint *)(param_1 + 0x28) - 1 < 0x7c) {
    puVar1 = &PdcClientInfo + (ulonglong)*(uint *)(param_1 + 0x28) * 6;
  }
  else {
    puVar1 = (uint *)0x0;
  }
  return ((*puVar1 & 0x8000) != 0) + '\x03';
}



===== PdcpReferenceTaskClient @ 1400260d0 =====

undefined4
PdcpReferenceTaskClient(longlong param_1,undefined8 param_2,longlong param_3,ulonglong param_4)

{
  char cVar1;
  int iVar2;
  undefined7 extraout_var;
  uint *puVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x2c) == 0x7fffffff) {
    uVar4 = 0xc0000095;
  }
  else {
    uVar4 = 0;
    iVar2 = *(int *)(param_1 + 0x2c) + 1;
    *(int *)(param_1 + 0x2c) = iVar2;
    if ((iVar2 == 1) && (*(int *)(param_1 + 0x30) == 0)) {
      cVar1 = PdcpGetTaskClientRequestGroup(param_1);
      puVar3 = (uint *)(CONCAT71(extraout_var,cVar1) & 0xffffffff);
      PdcGroupRequest(puVar3,'\x01');
      if ((DAT_140015c02 & 1) != 0) {
        param_4 = (ulonglong)DAT_14003100c;
        param_3 = param_1;
        McTemplateU0pqq_EtwWriteTransfer(puVar3,&PDC_TASK_REFERENCE,param_1,DAT_14003100c,1);
      }
      if (*(longlong *)(param_1 + 0x360) != 0) {
        SleepstudyHelperBlockerActiveReference();
      }
      PdcpLogTaskClientAction("TaskClient Active",param_1,param_3,param_4);
      if (4 < (int)DAT_14003100c) {
        *(undefined4 *)(param_1 + 0x358) = 0x103;
        return 0x103;
      }
      *(undefined4 *)(param_1 + 0x358) = 0;
    }
  }
  PdcpTaskClientAcknowledge(param_1,uVar4);
  return uVar4;
}



===== PdcpTaskClientAcknowledge @ 140026194 =====

undefined8 PdcpTaskClientAcknowledge(longlong param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  *(undefined4 *)(param_1 + 0x70) = param_2;
  if (DAT_140015c01 < '\0') {
    McTemplateU0pt_EtwWriteTransfer(param_1,&PDC_TASK_SEND,param_1,0);
  }
  pcVar1 = (char *)(param_1 + 0x38);
  uVar2 = 2;
  pcVar3 = "PdcpTaskClientSend";
  PdcPrint(2,"%s:Task message (%p):\n\tStatus/Active:%08lx\n","PdcpTaskClientSend",pcVar1);
  if (DAT_140015c01 < '\0') {
    pcVar3 = pcVar1;
    McTemplateU0pt_EtwWriteTransfer(uVar2,&PDC_TASK_MESSAGE,pcVar1,*(undefined4 *)(param_1 + 0x70));
  }
  if (*(char *)(param_1 + 0x18) == '\0') {
    PdcSendKernelMessage
              (*(longlong *)(param_1 + 0x20),(undefined8 *)pcVar1,*(undefined4 *)(param_1 + 0x14));
  }
  else {
    PdcSendUserMessage(*(longlong *)(param_1 + 0x20),(undefined8 *)pcVar1,
                       CONCAT71((int7)((ulonglong)pcVar3 >> 8),1));
  }
  return 0;
}



===== PdcpTaskClientReceive @ 140026238 =====

undefined8 PdcpTaskClientReceive(longlong param_1,char *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  char *pcVar6;
  undefined8 uVar7;
  char *pcVar8;
  char *pcVar9;
  
  uVar7 = 0;
  if (DAT_140015c01 < '\0') {
    McTemplateU0pt_EtwWriteTransfer(param_1,&PDC_TASK_RECEIVE,param_1,1);
  }
  pcVar8 = "PdcpTaskClientReceive";
  uVar4 = 2;
  pcVar9 = param_2;
  PdcPrint(2,"%s:Task message (%p):\n\tStatus/Active:%08lx\n","PdcpTaskClientReceive",param_2);
  if (DAT_140015c01 < '\0') {
    pcVar9 = (char *)(ulonglong)*(uint *)(param_2 + 0x38);
    pcVar8 = param_2;
    McTemplateU0pt_EtwWriteTransfer(uVar4,&PDC_TASK_MESSAGE,param_2,*(uint *)(param_2 + 0x38));
  }
  cVar1 = param_2[0x38];
  if (*(int *)(param_1 + 0x358) == 0x103) {
    uVar7 = 0xc000000d;
  }
  else {
    lVar5 = 6;
    puVar2 = (undefined8 *)(param_1 + 0x38);
    do {
      pcVar6 = param_2;
      puVar3 = puVar2;
      uVar4 = *(undefined8 *)(pcVar6 + 8);
      *puVar3 = *(undefined8 *)pcVar6;
      puVar3[1] = uVar4;
      uVar4 = *(undefined8 *)(pcVar6 + 0x18);
      puVar3[2] = *(undefined8 *)(pcVar6 + 0x10);
      puVar3[3] = uVar4;
      uVar4 = *(undefined8 *)(pcVar6 + 0x28);
      puVar3[4] = *(undefined8 *)(pcVar6 + 0x20);
      puVar3[5] = uVar4;
      uVar4 = *(undefined8 *)(pcVar6 + 0x38);
      puVar3[6] = *(undefined8 *)(pcVar6 + 0x30);
      puVar3[7] = uVar4;
      uVar4 = *(undefined8 *)(pcVar6 + 0x48);
      puVar3[8] = *(undefined8 *)(pcVar6 + 0x40);
      puVar3[9] = uVar4;
      uVar4 = *(undefined8 *)(pcVar6 + 0x58);
      puVar3[10] = *(undefined8 *)(pcVar6 + 0x50);
      puVar3[0xb] = uVar4;
      uVar4 = *(undefined8 *)(pcVar6 + 0x68);
      puVar3[0xc] = *(undefined8 *)(pcVar6 + 0x60);
      puVar3[0xd] = uVar4;
      uVar4 = *(undefined8 *)(pcVar6 + 0x78);
      puVar3[0xe] = *(undefined8 *)(pcVar6 + 0x70);
      puVar3[0xf] = uVar4;
      lVar5 = lVar5 + -1;
      puVar2 = puVar3 + 0x10;
      param_2 = pcVar6 + 0x80;
    } while (lVar5 != 0);
    uVar4 = *(undefined8 *)(pcVar6 + 0x88);
    puVar3[0x10] = *(undefined8 *)(pcVar6 + 0x80);
    puVar3[0x11] = uVar4;
    uVar4 = *(undefined8 *)(pcVar6 + 0x98);
    puVar3[0x12] = *(undefined8 *)(pcVar6 + 0x90);
    puVar3[0x13] = uVar4;
    if (cVar1 == '\0') {
      PdcpDereferenceTaskClient(param_1,0,(longlong)pcVar8,(ulonglong)pcVar9);
    }
    else {
      PdcpReferenceTaskClient(param_1,0,(longlong)pcVar8,(ulonglong)pcVar9);
    }
  }
  return uVar7;
}



===== PdcPoCompleteResiliencyCallback @ 140026360 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcPoCompleteResiliencyCallback(int param_1,int param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined4 uVar7;
  uint uVar8;
  
  PdcAcquireLock();
  uVar8 = 0;
  puVar3 = &PdcResiliencyClients;
  do {
    puVar4 = puVar3;
    if (*(int *)(puVar4 + 0x48) == param_1) break;
    uVar8 = uVar8 + 1;
    puVar3 = puVar4 + 0x70;
  } while (uVar8 < 8);
  puVar1 = (undefined8 *)(puVar4 + 0x30);
  if (*(int *)(puVar4 + 0x28) == 6) {
    for (puVar5 = (undefined8 *)*puVar1; puVar5 != puVar1; puVar5 = (undefined8 *)*puVar5) {
      if (puVar5[2] == _DAT_00000008) goto LAB_1400263c2;
    }
    puVar5 = (undefined8 *)0x0;
LAB_1400263c2:
    iVar2 = *(int *)((longlong)puVar5 + 0x2c);
  }
  else {
    iVar2 = *(int *)(puVar4 + 0x44);
  }
  if (iVar2 == param_2) {
    if (*(int *)(puVar4 + 0x28) == 6) {
      for (puVar5 = (undefined8 *)*puVar1; puVar5 != puVar1; puVar5 = (undefined8 *)*puVar5) {
        if (puVar5[2] == _DAT_00000008) goto LAB_1400263f1;
      }
      puVar5 = (undefined8 *)0x0;
LAB_1400263f1:
      uVar7 = *(undefined4 *)((longlong)puVar5 + 0x24);
    }
    else {
      uVar7 = *(undefined4 *)(puVar4 + 0x3c);
    }
    lVar6 = 0;
    PdcpResiliencyClientSetCurrentState((longlong)puVar4,0,uVar7);
    PdcpResiliencyClientSetTransactionId((longlong)puVar4,lVar6,0);
    PdcPhasesAcknowledgeResiliencyClient(*(int *)(puVar4 + 0x28),uVar7);
    PdcAcknowledgeActivators(*(int *)(puVar4 + 0x28),uVar7,0,0);
  }
  PdcReleaseLock();
  return;
}



===== PdcPrintResiliencyClient @ 140026448 =====

void PdcPrintResiliencyClient(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 uVar9;
  char *pcVar10;
  undefined1 uVar11;
  longlong lVar12;
  undefined1 uVar13;
  undefined8 *puVar14;
  undefined1 uVar15;
  
  iVar2 = *(int *)(param_2 + 0x28);
  puVar14 = (undefined8 *)0x0;
  if ((iVar2 == 6) && (param_3 == 0)) {
    for (puVar14 = *(undefined8 **)(param_2 + 0x30); puVar14 != (undefined8 *)(param_2 + 0x30);
        puVar14 = (undefined8 *)*puVar14) {
      uVar3 = *(uint *)((longlong)puVar14 + 0x2c);
      uVar4 = *(undefined4 *)(puVar14 + 3);
      uVar5 = *(undefined4 *)(puVar14 + 4);
      uVar6 = *(undefined4 *)((longlong)puVar14 + 0x24);
      PdcpGetResiliencyTypeAsString(*(int *)(param_2 + 0x28));
      pcVar10 = 
      "%S reference client:\nResiliency client (%p):\n\tClientPort:%p\n\tResiliencyType:%s\n\tCurrentTransactionId:%08lx\n\tLUID:%08llx\n\t ClientReferences:%08lx\n\t CurrentState:%08lx\n\t NextState:%08lx\n"
      ;
      PdcPrint(2,
               "%S reference client:\nResiliency client (%p):\n\tClientPort:%p\n\tResiliencyType:%s\n\tCurrentTransactionId:%08lx\n\tLUID:%08llx\n\t ClientReferences:%08lx\n\t CurrentState:%08lx\n\t NextState:%08lx\n"
               ,param_1,param_2);
      if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
        lVar8 = -1;
        do {
          lVar8 = lVar8 + 1;
        } while (*(short *)(param_1 + lVar8 * 2) != 0);
        McTemplateU0ppqxqqqqzr7_EtwWriteTransfer
                  ((ulonglong)uVar3,pcVar10,param_2,*(undefined8 *)(param_2 + 0x20),6,(char)uVar4,
                   (char)uVar3,(char)uVar5,(char)uVar6,(int)lVar8,param_1);
      }
    }
  }
  else {
    lVar8 = PdcpResiliencyClientGetRefCount(param_2,param_3);
    if (iVar2 == 6) {
      lVar12 = *(longlong *)(param_3 + 8);
      puVar1 = (undefined8 *)(param_2 + 0x30);
      for (puVar7 = (undefined8 *)*puVar1; puVar7 != puVar1; puVar7 = (undefined8 *)*puVar7) {
        if (puVar7[2] == lVar12) goto LAB_1400265a2;
      }
      puVar7 = puVar14;
LAB_1400265a2:
      uVar13 = (undefined1)*(undefined4 *)(puVar7 + 4);
      for (puVar7 = (undefined8 *)*puVar1; puVar7 != puVar1; puVar7 = (undefined8 *)*puVar7) {
        if (puVar7[2] == lVar12) goto LAB_1400265be;
      }
      puVar7 = puVar14;
LAB_1400265be:
      uVar11 = (undefined1)*(undefined4 *)((longlong)puVar7 + 0x24);
      for (puVar7 = (undefined8 *)*puVar1; puVar7 != puVar1; puVar7 = (undefined8 *)*puVar7) {
        if (puVar7[2] == lVar12) goto LAB_1400265d7;
      }
      puVar7 = puVar14;
LAB_1400265d7:
      uVar15 = (undefined1)*(undefined4 *)((longlong)puVar7 + 0x2c);
    }
    else {
      uVar13 = (undefined1)*(undefined4 *)(param_2 + 0x38);
      uVar11 = (undefined1)*(undefined4 *)(param_2 + 0x3c);
      uVar15 = (undefined1)*(undefined4 *)(param_2 + 0x44);
    }
    PdcpGetResiliencyTypeAsString(iVar2);
    pcVar10 = 
    "%S:\nResiliency client (%p):\n\tClientPort:%p\n\tResiliencyType:%s\n\tCurrentTransactionId:%08lx\n\tLUID:%08llx\n\t ClientReferences:%08lx\n\t CurrentState:%08lx\n\t NextState:%08lx\n"
    ;
    uVar9 = 2;
    PdcPrint(2,
             "%S:\nResiliency client (%p):\n\tClientPort:%p\n\tResiliencyType:%s\n\tCurrentTransactionId:%08lx\n\tLUID:%08llx\n\t ClientReferences:%08lx\n\t CurrentState:%08lx\n\t NextState:%08lx\n"
             ,param_1,param_2);
    if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
      lVar12 = -1;
      do {
        lVar12 = lVar12 + 1;
      } while (*(short *)(param_1 + lVar12 * 2) != 0);
      McTemplateU0ppqxqqqqzr7_EtwWriteTransfer
                (uVar9,pcVar10,param_2,*(undefined8 *)(param_2 + 0x20),(char)iVar2,(char)lVar8,
                 uVar15,uVar13,uVar11,(int)lVar12,param_1);
    }
  }
  return;
}



===== PdcResiliencyClientDereference @ 140026698 =====

ulonglong PdcResiliencyClientDereference(undefined8 param_1,uint param_2,ulonglong *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  undefined *puVar6;
  
  uVar4 = 0;
  puVar6 = (undefined *)0x0;
  if (param_2 < 8) {
    puVar6 = &PdcResiliencyClients + (longlong)(int)param_2 * 0x70;
  }
  if ((Microsoft_Windows_PDCEnableBits & 0x40) != 0) {
    McTemplateU0ppq_EtwWriteTransfer(param_1,&PDC_RESILIENCY_DEREFERENCE,param_1,puVar6,0);
  }
  puVar5 = (ulonglong *)0x0;
  if (param_2 == 6) {
    puVar5 = param_3;
  }
  PdcPrintResiliencyClient(0x14000d5e8,(longlong)puVar6,(longlong)puVar5);
  lVar2 = PdcpResiliencyClientGetRefCount((longlong)puVar6,(longlong)puVar5);
  if (lVar2 == 0) {
    uVar4 = 0xc0000095;
  }
  else {
    plVar1 = (longlong *)(puVar6 + 0x30);
    lVar2 = 0;
    if (*(int *)(puVar6 + 0x28) == 6) {
      for (plVar3 = (longlong *)*plVar1; plVar3 != plVar1; plVar3 = (longlong *)*plVar3) {
        if (plVar3[2] == puVar5[1]) {
          if (plVar3 != (longlong *)0x0) {
            plVar3[3] = plVar3[3] + -1;
            lVar2 = plVar3[3];
          }
          break;
        }
      }
    }
    else {
      lVar2 = *plVar1 + -1;
      *plVar1 = lVar2;
    }
    PdcpResiliencyClientIsTransactionPending((longlong)puVar6,(longlong)puVar5);
    if (lVar2 == 0) {
      PdcPrintResiliencyClient(0x14000d5b0,(longlong)puVar6,(longlong)puVar5);
      uVar4 = PdcpResiliencyClientTransaction((longlong)puVar6,1,puVar5);
      uVar4 = uVar4 & 0xffffffff;
    }
  }
  return uVar4;
}



===== PdcResiliencyClientFree @ 1400267a8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcResiliencyClientFree(undefined8 *param_1)

{
  int iVar1;
  bool bVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  if (*(int *)(param_1 + 5) == 6) {
    puVar4 = param_1 + 6;
    for (puVar3 = (undefined8 *)*puVar4; puVar3 != puVar4; puVar3 = (undefined8 *)*puVar3) {
      *(undefined4 *)(puVar3 + 4) = 0;
      *(undefined4 *)((longlong)puVar3 + 0x24) = 0;
      *(undefined4 *)((longlong)puVar3 + 0x2c) = 0;
    }
  }
  else {
    bVar2 = PdcpResiliencyClientIsTransactionPending((longlong)param_1,0);
    if (bVar2) {
      iVar1 = *(int *)(param_1 + 5);
      puVar4 = param_1 + 6;
      if (iVar1 == 6) {
        for (puVar3 = (undefined8 *)*puVar4; puVar3 != puVar4; puVar3 = (undefined8 *)*puVar3) {
          if (puVar3[2] == _DAT_00000008) goto LAB_14002681c;
        }
        puVar3 = (undefined8 *)0x0;
LAB_14002681c:
        cVar5 = *(char *)(puVar3 + 5);
      }
      else {
        cVar5 = *(char *)(param_1 + 8);
      }
      if (cVar5 == '\0') {
        if (iVar1 == 6) {
          for (puVar3 = (undefined8 *)*puVar4; puVar3 != puVar4; puVar3 = (undefined8 *)*puVar3) {
            if (puVar3[2] == _DAT_00000008) goto LAB_14002684b;
          }
          puVar3 = (undefined8 *)0x0;
LAB_14002684b:
          uVar7 = *(undefined4 *)((longlong)puVar3 + 0x24);
        }
        else {
          uVar7 = *(undefined4 *)((longlong)param_1 + 0x3c);
        }
        PdcPhasesAcknowledgeResiliencyClient(iVar1,uVar7);
        PdcAcknowledgeActivators(*(int *)(param_1 + 5),uVar7,0,0);
      }
    }
    uVar8 = 0;
    uVar6 = 0;
    PdcpResiliencyClientSetCurrentState((longlong)param_1,0,0);
    if (*(int *)(param_1 + 5) == 6) {
      for (puVar4 = (undefined8 *)param_1[6]; puVar4 != param_1 + 6; puVar4 = (undefined8 *)*puVar4)
      {
        if (puVar4[2] == _DAT_00000008) goto LAB_1400268a1;
      }
      puVar4 = (undefined8 *)0x0;
LAB_1400268a1:
      *(uint *)((longlong)puVar4 + 0x24) = *(uint *)((longlong)puVar4 + 0x24) & uVar8;
    }
    else {
      *(uint *)((longlong)param_1 + 0x3c) = *(uint *)((longlong)param_1 + 0x3c) & uVar6;
    }
    puVar4 = param_1;
    PdcpResiliencyClientSetTransactionId((longlong)param_1,0,uVar8);
  }
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    McTemplateU0pqq_EtwWriteTransfer
              (puVar4,&PDC_RESILIENCY_CLIENT_DEREGISTRATION,param_1,*(undefined4 *)(param_1 + 5),0);
  }
  PdcPrintResiliencyClient(0x14000d3d0,(longlong)param_1,0);
  return 0;
}



===== PdcResiliencyClientInitialize @ 1400268fc =====

undefined4 PdcResiliencyClientInitialize(ulonglong param_1,undefined8 *param_2)

{
  uint *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  *param_2 = 0;
  uVar3 = 0xc000000d;
  if ((int)param_1 - 1U < 0x7c) {
    puVar1 = (uint *)(&DAT_140031f68 + (param_1 & 0xffffffff) * 0x18);
  }
  else {
    puVar1 = (uint *)&DAT_00000008;
  }
  puVar2 = (undefined *)0x0;
  if (*puVar1 < 8) {
    puVar2 = &PdcResiliencyClients + (longlong)(int)*puVar1 * 0x70;
  }
  if ((*(longlong *)(puVar2 + 0x20) == 0) && (*(int *)(puVar2 + 0x48) == 0)) {
    *(int *)(puVar2 + 0x4c) = (int)param_1;
    uVar3 = 0;
    *param_2 = puVar2;
  }
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    McTemplateU0pqq_EtwWriteTransfer
              (param_1,&PDC_RESILIENCY_CLIENT_REGISTRATION,puVar2,*(undefined4 *)(puVar2 + 0x28),
               (char)uVar3);
  }
  PdcPrintResiliencyClient(0x14000d380,(longlong)puVar2,0);
  return uVar3;
}



===== PdcResiliencyClientReference @ 1400269a8 =====

ulonglong PdcResiliencyClientReference(undefined8 param_1,uint param_2,ulonglong *param_3)

{
  longlong *plVar1;
  ulonglong *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  bool bVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  ulonglong uVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  ulonglong *puVar12;
  undefined *puVar13;
  int iVar14;
  char cVar15;
  undefined8 uStack_40;
  undefined1 auStack_38 [32];
  
  puVar13 = (undefined *)0x0;
  if (param_2 < 8) {
    puVar13 = &PdcResiliencyClients + (longlong)(int)param_2 * 0x70;
  }
  if ((Microsoft_Windows_PDCEnableBits & 0x40) != 0) {
    McTemplateU0ppq_EtwWriteTransfer(param_1,&PDC_RESILIENCY_REFERENCE,param_1,puVar13,1);
  }
  puVar10 = auStack_38;
  puVar11 = auStack_38;
  plVar1 = (longlong *)(puVar13 + 0x30);
  puVar12 = (ulonglong *)0x0;
  if (param_2 == 6) {
    puVar12 = param_3;
  }
  puVar2 = puVar12 + 1;
  if (*(int *)(puVar13 + 0x28) == 6) {
    uVar8 = *puVar2;
    for (plVar7 = (longlong *)*plVar1; puVar10 = auStack_38, plVar7 != plVar1;
        plVar7 = (longlong *)*plVar7) {
      if (plVar7[2] == uVar8) goto LAB_140026a81;
    }
    do {
      *(undefined8 *)(puVar10 + -8) = 0x140026a47;
      puVar6 = (undefined8 *)ExAllocatePool2(0x100,0x30,0x52636450);
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[5] = 0;
      *(undefined4 *)((longlong)puVar6 + 0x24) = 0;
      puVar6[2] = uVar8;
      puVar6[3] = 1;
      *(undefined4 *)(puVar6 + 4) = 1;
      puVar3 = *(undefined8 **)(puVar13 + 0x38);
      if ((longlong *)*puVar3 == plVar1) {
        *puVar6 = plVar1;
        puVar6[1] = puVar3;
        *puVar3 = puVar6;
        *(undefined8 **)(puVar13 + 0x38) = puVar6;
        goto LAB_140026a9f;
      }
      pcVar4 = (code *)swi(0x29);
      plVar7 = (longlong *)(*pcVar4)(3);
      puVar11 = puVar10 + 8;
LAB_140026a81:
      puVar10 = puVar11;
    } while (plVar7 == (longlong *)0x0);
    plVar7[3] = plVar7[3] + 1;
  }
  else {
    *plVar1 = *plVar1 + 1;
  }
LAB_140026a9f:
  *(undefined8 *)(puVar10 + -8) = 0x140026ab1;
  PdcPrintResiliencyClient(0x14000d520,(longlong)puVar13,(longlong)puVar12);
  *(undefined8 *)(puVar10 + -8) = 0x140026abc;
  bVar5 = PdcpResiliencyClientIsTransactionPending((longlong)puVar13,(longlong)puVar12);
  if (bVar5) {
    if (*(int *)(puVar13 + 0x28) == 6) {
      for (plVar7 = (longlong *)*plVar1; plVar7 != plVar1; plVar7 = (longlong *)*plVar7) {
        if (plVar7[2] == *puVar2) goto LAB_140026ae9;
      }
      plVar7 = (longlong *)0x0;
LAB_140026ae9:
      iVar9 = *(int *)((longlong)plVar7 + 0x24);
      iVar14 = *(int *)(puVar13 + 0x28);
      for (plVar7 = (longlong *)*plVar1; plVar7 != plVar1; plVar7 = (longlong *)*plVar7) {
        if (plVar7[2] == *puVar2) goto LAB_140026b08;
      }
      plVar7 = (longlong *)0x0;
LAB_140026b08:
      cVar15 = (char)plVar7[5];
    }
    else {
      iVar9 = *(int *)(puVar13 + 0x3c);
      cVar15 = puVar13[0x40];
      iVar14 = *(int *)(puVar13 + 0x28);
    }
    if (cVar15 == '\0') {
      if (iVar9 == 0) {
        return 0x103;
      }
    }
    else if (iVar9 == 0) {
      return 0;
    }
    if (iVar14 == 6) {
      for (plVar7 = (longlong *)*plVar1; plVar7 != plVar1; plVar7 = (longlong *)*plVar7) {
        if (plVar7[2] == *puVar2) goto LAB_140026b46;
      }
      plVar7 = (longlong *)0x0;
LAB_140026b46:
      *(undefined1 *)(plVar7 + 5) = 0;
    }
    else {
      puVar13[0x40] = 0;
    }
  }
  else {
    if (*(int *)(puVar13 + 0x28) == 6) {
      for (plVar7 = (longlong *)*plVar1; plVar7 != plVar1; plVar7 = (longlong *)*plVar7) {
        if (plVar7[2] == *puVar2) goto LAB_140026b7e;
      }
      plVar7 = (longlong *)0x0;
LAB_140026b7e:
      iVar9 = (int)plVar7[4];
    }
    else {
      iVar9 = *(int *)(puVar13 + 0x38);
    }
    if (iVar9 != 1) {
      return 0;
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x140026b5d;
  uVar8 = PdcpResiliencyClientTransaction((longlong)puVar13,0,puVar12);
  return uVar8 & 0xffffffff;
}



===== PdcpGetResiliencyTypeAsString @ 140026bb4 =====

char * PdcpGetResiliencyTypeAsString(int param_1)

{
  if (param_1 == 0) {
    return "PdcIdleResiliency";
  }
  if (param_1 == 1) {
    return "PdcHostResiliency";
  }
  if (param_1 == 2) {
    return "PdcIoResiliency";
  }
  if (param_1 == 3) {
    return "PdcDamResiliency";
  }
  if (param_1 == 4) {
    return "PdcNqmResiliency";
  }
  if (param_1 == 5) {
    return "PdcWcmResiliency";
  }
  if (param_1 == 6) {
    return "PdcAnyNetworkResiliency";
  }
  if (param_1 == 7) {
    return "PdcDeepIoResiliency";
  }
  if (param_1 == 8) {
    return "PdcInvalidResiliency";
  }
  return "Unrecognized PDC_RESILIENCY_TYPE value";
}



===== PdcpPrintResiliencyMessage @ 140026c40 =====

void PdcpPrintResiliencyMessage
               (undefined8 param_1,longlong param_2,undefined1 param_3,undefined1 param_4)

{
  undefined8 uVar1;
  char *pcVar2;
  
  uVar1 = 2;
  pcVar2 = 
  "%s:Resiliency message (%p):\n\tTransactionId:%08lx\n\tClientState:%08lx\n\tClientStatus:%08lx\n\tSend:%08lx\n\tUserMode:%08lx\n"
  ;
  PdcPrint(2,
           "%s:Resiliency message (%p):\n\tTransactionId:%08lx\n\tClientState:%08lx\n\tClientStatus:%08lx\n\tSend:%08lx\n\tUserMode:%08lx\n"
           ,param_1,param_2);
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    McTemplateU0pqqqtt_EtwWriteTransfer
              (uVar1,pcVar2,param_2,*(undefined4 *)(param_2 + 0x38),
               (char)*(undefined4 *)(param_2 + 0x3c),(char)*(undefined4 *)(param_2 + 0x40),param_3,
               param_4);
  }
  return;
}



===== PdcpResiliencyClientGetRefCount @ 140026cd0 =====

longlong PdcpResiliencyClientGetRefCount(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  
  plVar1 = (longlong *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x28) == 6) {
    lVar2 = 0;
    if (param_2 == 0) {
      for (plVar3 = (longlong *)*plVar1; plVar3 != plVar1; plVar3 = (longlong *)*plVar3) {
        lVar2 = lVar2 + plVar3[3];
      }
    }
    else {
      for (plVar3 = (longlong *)*plVar1; plVar3 != plVar1; plVar3 = (longlong *)*plVar3) {
        if (plVar3[2] == *(longlong *)(param_2 + 8)) {
          return plVar3[3];
        }
      }
    }
  }
  else {
    lVar2 = *plVar1;
  }
  return lVar2;
}



===== PdcpResiliencyClientIsTransactionPending @ 140026d24 =====

bool PdcpResiliencyClientIsTransactionPending(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  
  if (*(int *)(param_1 + 0x28) == 6) {
    puVar4 = (undefined8 *)(param_1 + 0x30);
    if (param_2 == -1) {
      puVar2 = (undefined8 *)*puVar4;
      do {
        if (puVar2 == puVar4) {
          return false;
        }
        puVar1 = (undefined8 *)*puVar4;
        do {
          if (puVar1[2] == puVar2[2]) goto LAB_140026d59;
          puVar1 = (undefined8 *)*puVar1;
        } while (puVar1 != puVar4);
        puVar1 = (undefined8 *)0x0;
LAB_140026d59:
        if (*(int *)((longlong)puVar1 + 0x2c) != 0) {
          return true;
        }
        puVar2 = (undefined8 *)*puVar2;
      } while( true );
    }
    for (puVar2 = (undefined8 *)*puVar4; puVar2 != puVar4; puVar2 = (undefined8 *)*puVar2) {
      if (puVar2[2] == *(longlong *)(param_2 + 8)) goto LAB_140026d88;
    }
    puVar2 = (undefined8 *)0x0;
LAB_140026d88:
    iVar3 = *(int *)((longlong)puVar2 + 0x2c);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x44);
  }
  return iVar3 != 0;
}



===== PdcpResiliencyClientOneTimeTransaction @ 140026da4 =====

int PdcpResiliencyClientOneTimeTransaction(longlong param_1,ulonglong *param_2,int param_3)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  int iVar3;
  
  PdcpGetResiliencyTypeAsString(*(int *)(param_1 + 0x28));
  PdcPrint(2,
           "%s: Resiliency client %#p (%s) registered, should be %s. Explicitly sending transaction now.\n"
           ,"minkernel\\po\\pdc\\sys\\resiliency.c",param_1);
  if (*(int *)(param_1 + 0x28) == 6) {
    for (puVar1 = *(undefined8 **)(param_1 + 0x30); puVar1 != (undefined8 *)(param_1 + 0x30);
        puVar1 = (undefined8 *)*puVar1) {
      if (puVar1[2] == param_2[1]) goto LAB_140026e2a;
    }
    puVar1 = (undefined8 *)0x0;
LAB_140026e2a:
    *(undefined1 *)(puVar1 + 5) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x40) = 1;
  }
  PdcpResiliencyClientSetCurrentState(param_1,(longlong)param_2,(uint)(param_3 == 0));
  uVar2 = PdcpResiliencyClientTransaction(param_1,param_3,param_2);
  iVar3 = 0;
  if ((int)uVar2 != 0x103) {
    iVar3 = (int)uVar2;
  }
  return iVar3;
}



===== PdcpResiliencyClientReceive @ 140026e7c =====

undefined8 PdcpResiliencyClientReceive(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  int iVar8;
  longlong lVar9;
  char cVar10;
  longlong lVar11;
  
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    McTemplateU0pt_EtwWriteTransfer(param_1,&PDC_RESILIENCY_RECEIVE,param_1,0);
  }
  iVar3 = *(int *)(param_2 + 0x38);
  lVar11 = param_2 + 0x48;
  iVar4 = *(int *)(param_2 + 0x3c);
  uVar5 = *(uint *)(param_2 + 0x40);
  if (*(int *)(param_1 + 0x28) != 6) {
    lVar11 = 0;
  }
  PdcPrintResiliencyClient(0x14000d4b0,param_1,lVar11);
  PdcpPrintResiliencyMessage
            ("PdcpResiliencyClientReceive",param_2,0,*(undefined1 *)(param_1 + 0x18));
  plVar1 = (longlong *)(lVar11 + 8);
  puVar2 = (undefined8 *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x28) == 6) {
    for (puVar6 = (undefined8 *)*puVar2; puVar6 != puVar2; puVar6 = (undefined8 *)*puVar6) {
      if (puVar6[2] == *plVar1) goto LAB_140026f21;
    }
    puVar6 = (undefined8 *)0x0;
LAB_140026f21:
    iVar8 = *(int *)((longlong)puVar6 + 0x2c);
  }
  else {
    iVar8 = *(int *)(param_1 + 0x44);
  }
  if (iVar8 == iVar3) {
    lVar9 = lVar11;
    PdcpResiliencyClientSetCurrentState(param_1,lVar11,iVar4);
    PdcpResiliencyClientSetTransactionId(param_1,lVar9,0);
    PdcResiliencyWatchdogTimeout = 0;
    KeCancelTimer(&PdcResiliencyWatchdogTimer);
    PdcPrintResiliencyClient(0x14000d540,param_1,lVar11);
    if (*(int *)(param_1 + 0x28) == 6) {
      for (puVar6 = (undefined8 *)*puVar2; puVar6 != puVar2; puVar6 = (undefined8 *)*puVar6) {
        if (puVar6[2] == *plVar1) goto LAB_140026f95;
      }
      puVar6 = (undefined8 *)0x0;
LAB_140026f95:
      cVar10 = *(char *)(puVar6 + 5);
    }
    else {
      cVar10 = *(char *)(param_1 + 0x40);
    }
    if ((cVar10 == '\0') && (iVar4 == 0)) {
      uVar7 = PdcGetInterruptTime();
      *(longlong *)(param_1 + 0x50) =
           *(longlong *)(param_1 + 0x50) + (uVar7 / 10 - *(longlong *)(param_1 + 0x58));
      *(undefined8 *)(param_1 + 0x58) = 0;
      if (*(int *)(param_1 + 0x4c) == 5) {
        PdcPoNetworkResiliency();
      }
    }
    if ((ResiliencyPhaseActive == '\0') && (cVar10 == '\0')) {
      ResiliencyPhaseActive = 1;
      PdcPhasesAcknowledgeResiliencyClient(*(int *)(param_1 + 0x28),iVar4);
      PdcAcknowledgeActivators(*(int *)(param_1 + 0x28),iVar4,uVar5,lVar11);
      ResiliencyPhaseActive = '\0';
    }
    if (*(int *)(param_1 + 0x28) == 6) {
      for (puVar6 = (undefined8 *)*puVar2; puVar6 != puVar2; puVar6 = (undefined8 *)*puVar6) {
        if (puVar6[2] == *plVar1) goto LAB_14002702f;
      }
      puVar6 = (undefined8 *)0x0;
LAB_14002702f:
      *(undefined1 *)(puVar6 + 5) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x40) = 0;
    }
  }
  return 0;
}



===== PdcpResiliencyClientSend @ 140027060 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpResiliencyClientSend(longlong param_1,ulonglong *param_2)

{
  bool bVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 local_328 [5];
  undefined4 local_300;
  undefined4 local_2f0;
  int local_2ec;
  undefined4 local_2e8;
  ulonglong local_2e0;
  ulonglong uStack_2d8;
  ulonglong local_2d0;
  
  memset(local_328,0,800);
  puVar4 = (undefined8 *)(param_1 + 0x30);
  local_300 = 5;
  if (*(int *)(param_1 + 0x28) == 6) {
    for (puVar3 = (undefined8 *)*puVar4; puVar3 != puVar4; puVar3 = (undefined8 *)*puVar3) {
      if (puVar3[2] == param_2[1]) goto LAB_1400270c5;
    }
    puVar3 = (undefined8 *)0x0;
LAB_1400270c5:
    local_2f0 = *(undefined4 *)((longlong)puVar3 + 0x2c);
  }
  else {
    local_2f0 = *(undefined4 *)(param_1 + 0x44);
  }
  if (*(int *)(param_1 + 0x28) == 6) {
    for (puVar3 = (undefined8 *)*puVar4; puVar3 != puVar4; puVar3 = (undefined8 *)*puVar3) {
      if (puVar3[2] == param_2[1]) goto LAB_1400270f0;
    }
    puVar3 = (undefined8 *)0x0;
LAB_1400270f0:
    local_2ec = *(int *)((longlong)puVar3 + 0x24);
  }
  else {
    local_2ec = *(int *)(param_1 + 0x3c);
  }
  local_2e8 = 0;
  if (param_2 != (ulonglong *)0x0) {
    local_2e0 = *param_2;
    uStack_2d8 = param_2[1];
    local_2d0 = param_2[2];
  }
  if (local_2ec == 1) {
    bVar1 = true;
    uVar2 = PdcGetResourceMask();
    if ((uVar2 & 0x20) == 0) {
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | 1;
    }
  }
  else {
    bVar1 = false;
  }
  if ((*(uint *)(param_1 + 0x68) & 1) == 0) {
    if (bVar1) goto LAB_1400271a7;
  }
  else {
    local_2e0 = local_2e0 | 2;
    if (bVar1) goto LAB_1400271a7;
    *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xfffffffe;
  }
  if ((_DAT_140031010 == 4) &&
     (bVar1 = false, puVar4 = PdcTaskClients, (undefined8 **)PdcTaskClients != &PdcTaskClients)) {
    do {
      if ((*(int *)((longlong)puVar4 + 0x2c) != 0) && (*(int *)(puVar4 + 6) == 0)) {
        if (*(int *)(puVar4 + 5) != 0x44) goto LAB_1400271a7;
        bVar1 = true;
      }
      puVar4 = (undefined8 *)*puVar4;
    } while ((undefined8 **)puVar4 != &PdcTaskClients);
    if (bVar1) {
      local_2e0 = local_2e0 | 4;
    }
  }
LAB_1400271a7:
  PdcPrintResiliencyClient(0x14000d470,param_1,(longlong)param_2);
  PdcpPrintResiliencyMessage
            ("PdcpResiliencyClientSend",(longlong)local_328,1,*(undefined1 *)(param_1 + 0x18));
  if (*(char *)(param_1 + 0x18) == '\0') {
    PdcSendKernelMessage(*(longlong *)(param_1 + 0x20),local_328,*(undefined4 *)(param_1 + 0x14));
  }
  else {
    PdcSendUserMessage(*(longlong *)(param_1 + 0x20),local_328,0);
  }
  return;
}



===== PdcpResiliencyClientSetCurrentState @ 140027214 =====

void PdcpResiliencyClientSetCurrentState(longlong param_1,longlong param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  
  if (*(int *)(param_1 + 0x28) != 6) {
    *(undefined4 *)(param_1 + 0x38) = param_3;
    return;
  }
  for (puVar1 = *(undefined8 **)(param_1 + 0x30); puVar1 != (undefined8 *)(param_1 + 0x30);
      puVar1 = (undefined8 *)*puVar1) {
    if (puVar1[2] == *(longlong *)(param_2 + 8)) goto LAB_140027237;
  }
  puVar1 = (undefined8 *)0x0;
LAB_140027237:
  *(undefined4 *)(puVar1 + 4) = param_3;
  return;
}



===== PdcpResiliencyClientSetNextState @ 14002724c =====

void PdcpResiliencyClientSetNextState(longlong param_1,longlong param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  
  if (*(int *)(param_1 + 0x28) != 6) {
    *(undefined4 *)(param_1 + 0x3c) = param_3;
    return;
  }
  for (puVar1 = *(undefined8 **)(param_1 + 0x30); puVar1 != (undefined8 *)(param_1 + 0x30);
      puVar1 = (undefined8 *)*puVar1) {
    if (puVar1[2] == *(longlong *)(param_2 + 8)) goto LAB_14002726f;
  }
  puVar1 = (undefined8 *)0x0;
LAB_14002726f:
  *(undefined4 *)((longlong)puVar1 + 0x24) = param_3;
  return;
}



===== PdcpResiliencyClientSetTransactionId @ 140027284 =====

void PdcpResiliencyClientSetTransactionId(longlong param_1,longlong param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  
  if (*(int *)(param_1 + 0x28) != 6) {
    *(undefined4 *)(param_1 + 0x44) = param_3;
    return;
  }
  for (puVar1 = *(undefined8 **)(param_1 + 0x30); puVar1 != (undefined8 *)(param_1 + 0x30);
      puVar1 = (undefined8 *)*puVar1) {
    if (puVar1[2] == *(longlong *)(param_2 + 8)) goto LAB_1400272a7;
  }
  puVar1 = (undefined8 *)0x0;
LAB_1400272a7:
  *(undefined4 *)((longlong)puVar1 + 0x2c) = param_3;
  return;
}



===== PdcpResiliencyClientTransaction @ 1400272bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PdcpResiliencyClientTransaction(longlong param_1,int param_2,ulonglong *param_3)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong *puVar8;
  
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    McTemplateU0pt_EtwWriteTransfer(param_1,&PDC_RESILIENCY_SEND,param_1,1);
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    if (param_2 == 1) {
      if (DAT_1400150e8 == (code *)0x0) goto LAB_140027328;
      uVar7 = 0;
    }
    else {
      if ((param_2 != 0) || (DAT_1400150e8 == (code *)0x0)) goto LAB_140027328;
      uVar7 = 1;
    }
    (*DAT_1400150e8)(8,uVar7);
  }
LAB_140027328:
  if (*(longlong *)(param_1 + 0x20) == 0) {
    if (*(int *)(param_1 + 0x48) == 0) {
      uVar3 = 0;
      puVar8 = param_3;
      PdcpResiliencyClientSetTransactionId(param_1,(longlong)param_3,0);
      PdcpResiliencyClientSetCurrentState(param_1,(longlong)puVar8,uVar3);
      if (*(int *)(param_1 + 0x28) == 6) {
        for (puVar5 = *(undefined8 **)(param_1 + 0x30); puVar5 != (undefined8 *)(param_1 + 0x30);
            puVar5 = (undefined8 *)*puVar5) {
          if (puVar5[2] == param_3[1]) goto LAB_1400274eb;
        }
        puVar5 = (undefined8 *)0x0;
LAB_1400274eb:
        *(uint *)((longlong)puVar5 + 0x24) = *(uint *)((longlong)puVar5 + 0x24) & uVar3;
      }
      else {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & uVar3;
      }
      uVar4 = 0;
    }
    else {
      do {
        PdcSequenceId = PdcSequenceId + 1;
      } while (PdcSequenceId == 0);
      PdcpResiliencyClientSetTransactionId(param_1,(longlong)param_3,PdcSequenceId);
      if (*(int *)(param_1 + 0x28) == 6) {
        for (puVar5 = *(undefined8 **)(param_1 + 0x30); puVar5 != (undefined8 *)(param_1 + 0x30);
            puVar5 = (undefined8 *)*puVar5) {
          if (puVar5[2] == param_3[1]) goto LAB_140027473;
        }
        puVar5 = (undefined8 *)0x0;
LAB_140027473:
        *(int *)((longlong)puVar5 + 0x24) = param_2;
      }
      else {
        *(int *)(param_1 + 0x3c) = param_2;
      }
      uVar3 = (*PdcPoCallbacks)(*(undefined4 *)(param_1 + 0x48),param_2 == 1);
      uVar4 = (ulonglong)uVar3;
      if (uVar3 == 0) {
        PdcpResiliencyClientSetCurrentState(param_1,(longlong)param_3,param_2);
        PdcpResiliencyClientSetTransactionId(param_1,(longlong)param_3,0);
      }
    }
  }
  else {
    if (param_2 == 1) {
      uVar4 = PdcGetInterruptTime();
      *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
      *(ulonglong *)(param_1 + 0x58) = uVar4 / 10;
      if (*(int *)(param_1 + 0x4c) == 5) {
        PdcPoNetworkResiliency();
      }
    }
    iVar1 = *(int *)(param_1 + 0x4c);
    if (((iVar1 == 2) || (iVar1 == 5)) || (iVar6 = PdcCriticalNotificationTimeout, iVar1 == 0x6c)) {
      iVar6 = PdcWcmNotificationTimeout;
    }
    PdcResiliencyWatchdogTimeout = (ulonglong)(uint)(iVar6 * 10000000) + _DAT_fffff78000000008;
    PdcSetTimer(0x140013ba0,(ulonglong)(uint)((iVar6 + 1) * 1000));
    do {
      PdcSequenceId = PdcSequenceId + 1;
    } while (PdcSequenceId == 0);
    PdcpResiliencyClientSetTransactionId(param_1,(longlong)param_3,PdcSequenceId);
    if (*(int *)(param_1 + 0x28) == 6) {
      for (puVar5 = *(undefined8 **)(param_1 + 0x30); puVar5 != (undefined8 *)(param_1 + 0x30);
          puVar5 = (undefined8 *)*puVar5) {
        if (puVar5[2] == param_3[1]) goto LAB_1400273f8;
      }
      puVar5 = (undefined8 *)0x0;
LAB_1400273f8:
      *(int *)((longlong)puVar5 + 0x24) = param_2;
    }
    else {
      *(int *)(param_1 + 0x3c) = param_2;
    }
    PdcpResiliencyClientSend(param_1,param_3);
    bVar2 = PdcpResiliencyClientIsTransactionPending(param_1,(longlong)param_3);
    uVar4 = (ulonglong)(-(uint)bVar2 & 0x103);
  }
  return uVar4 & 0xffffffff;
}



===== PdcpResiliencyWatchdog @ 140027520 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpResiliencyWatchdog(void)

{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((PdcResiliencyWatchdogTimeout != 0) && (PdcResiliencyWatchdogTimeout < _DAT_fffff78000000008))
  {
    uVar3 = 0;
    puVar2 = &PdcResiliencyClients;
    do {
      if (*(int *)(puVar2 + 0x28) != 6) {
        bVar1 = PdcpResiliencyClientIsTransactionPending((longlong)puVar2,0);
        if (bVar1) {
          PdcTriageCaptureContext((longlong)puVar2,&local_38,'\0');
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0x14f,*(undefined4 *)(puVar2 + 0x4c),2,puVar2,&local_38);
        }
      }
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 0x70;
    } while (uVar3 < 8);
  }
  return;
}



===== PdcpResiliencyV2ClientDisengage @ 1400275c8 =====

undefined8 PdcpResiliencyV2ClientDisengage(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 != 0) {
    if ((iVar1 != 1) && (iVar1 != 2)) {
      if (iVar1 == 3) {
        return 0x103;
      }
      return 0xc000a003;
    }
    *(undefined4 *)(param_1 + 0x30) = 3;
    if (*(int *)(param_1 + 0x34) == 2) {
      PdcpResiliencyV2StartClientWatchdog(param_1);
    }
    uVar2 = PdcpResiliencyV2ClientSendMessage(param_1,'\0');
    if ((int)uVar2 == 0x103) {
      return uVar2;
    }
    PdcpResiliencyV2ClientSetState(param_1,0);
  }
  return 0;
}



===== PdcpResiliencyV2ClientEngage @ 140027634 =====

undefined8 PdcpResiliencyV2ClientEngage(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 == 0) {
    PdcpResiliencyV2ClientSetState(param_1,1);
    uVar2 = PdcpResiliencyV2ClientSendMessage(param_1,'\x01');
    if ((int)uVar2 == 0x103) {
      return uVar2;
    }
    PdcpResiliencyV2ClientSetState(param_1,2);
LAB_140027689:
    uVar2 = 0;
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) goto LAB_140027689;
      if (iVar1 != 3) {
        return 0xc000a003;
      }
    }
    uVar2 = 0x103;
  }
  return uVar2;
}



===== PdcpResiliencyV2ClientHandleMessage @ 140027698 =====

undefined8 PdcpResiliencyV2ClientHandleMessage(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x10) != 1) || (*(int *)(param_2 + 0x28) != 5)) {
    return 0xc000000d;
  }
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    McTemplateU0pt_EtwWriteTransfer(param_1,&PDC_RESILIENCY_RECEIVE,param_1,0);
  }
  PdcpResiliencyV2PrintClientMessage(0x14000d4b0,param_1);
  PdcpResiliencyV2PrintPdcMessage
            ("PdcpResiliencyV2ClientHandleMessage",param_2,0,*(undefined1 *)(param_1 + 0x18));
  if (*(int *)(param_1 + 0x38) != *(int *)(param_2 + 0x38)) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (*(int *)(param_1 + 0x30) == 1) {
    iVar1 = 2;
  }
  else {
    if (*(int *)(param_1 + 0x30) != 3) goto LAB_140027727;
    iVar1 = 0;
  }
  PdcpResiliencyV2ClientSetState(param_1,iVar1);
LAB_140027727:
  PdcpResiliencyV2PrintClientMessage(0x14000d540,param_1);
  PdcGetPolicyWorker(0x40);
  PdcCheckForWork();
  return 0;
}



===== PdcpResiliencyV2ClientRegister @ 140027760 =====

undefined4 PdcpResiliencyV2ClientRegister(uint param_1,undefined8 *param_2)

{
  int *piVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  uVar3 = 0;
  puVar4 = (undefined *)0x0;
  if (param_1 - 1 < 0x7c) {
    piVar1 = (int *)(&DAT_140031f68 + (ulonglong)param_1 * 0x18);
  }
  else {
    piVar1 = (int *)&DAT_00000008;
  }
  pwVar2 = (wchar_t *)(longlong)*piVar1;
  if (*piVar1 != 8) {
    puVar4 = &DAT_140013728 + (longlong)pwVar2 * 0x70;
    if ((&DAT_14001375c)[(longlong)pwVar2 * 0x1c] == 0) {
      (&DAT_140013750)[(longlong)pwVar2 * 0x1c] = param_1;
      if (PdcpResiliencyV2Context < (int)(&DAT_140013754)[(longlong)pwVar2 * 0x1c]) {
        (&DAT_14001375c)[(longlong)pwVar2 * 0x1c] = 1;
        if ((undefined8 **)DAT_140013aa8 == &DAT_140013aa8) {
          PdcpResiliencyV2RequestInitiate(&DAT_140013aa8,0);
        }
      }
      else {
        (&DAT_14001375c)[(longlong)pwVar2 * 0x1c] = 2;
      }
      pwVar2 = L"Register";
      PdcpResiliencyV2PrintClientMessage(0x14000d380,(longlong)puVar4);
      *param_2 = puVar4;
      goto LAB_140027805;
    }
  }
  uVar3 = 0xc000000d;
LAB_140027805:
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    McTemplateU0pqq_EtwWriteTransfer
              (pwVar2,&PDC_RESILIENCY_CLIENT_REGISTRATION,puVar4,param_1,(char)uVar3);
  }
  return uVar3;
}



===== PdcpResiliencyV2ClientRegistrationRequestCallback @ 140027850 =====

void PdcpResiliencyV2ClientRegistrationRequestCallback(void)

{
  PdcpResiliencyV2RequestCancel(&DAT_140013aa8,0);
  return;
}



===== PdcpResiliencyV2ClientSendMessage @ 140027870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcpResiliencyV2ClientSendMessage(longlong param_1,char param_2)

{
  int iVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined7 in_register_00000011;
  undefined8 local_328 [5];
  undefined4 local_300;
  int local_2f0;
  undefined4 local_2ec;
  ulonglong local_2e0;
  
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    in_register_00000011 = 0x1400099;
    McTemplateU0pt_EtwWriteTransfer(param_1,&PDC_RESILIENCY_SEND,param_1,1);
  }
  if (*(int *)(param_1 + 0x34) == 2) {
    iVar1 = (&PdcpResiliencyV2PoResiliencyMap)[*(int *)(param_1 + 0x2c)];
    do {
      local_2f0 = PdcSequenceId + 1;
      PdcSequenceId = local_2f0;
    } while (local_2f0 == 0);
    *(int *)(param_1 + 0x38) = local_2f0;
    if (iVar1 == 0) {
      memset(local_328,0,800);
      local_300 = 5;
      if (param_2 == '\0') {
        local_2ec = 0;
        uVar2 = (ulonglong)*(uint *)(param_1 + 0x68) * 2;
        *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xfffffffe;
        local_2e0 = (uVar2 ^ local_2e0) & 0xfffffffffffffffd ^ uVar2;
        if (_DAT_140031010 == 4) {
          bVar3 = false;
          puVar5 = PdcTaskClients;
          if ((undefined8 **)PdcTaskClients != &PdcTaskClients) {
            do {
              if ((*(int *)((longlong)puVar5 + 0x2c) != 0) && (*(int *)(puVar5 + 6) == 0)) {
                if (*(int *)(puVar5 + 5) != 0x44) goto LAB_140027996;
                bVar3 = true;
              }
              puVar5 = (undefined8 *)*puVar5;
            } while ((undefined8 **)puVar5 != &PdcTaskClients);
            if (bVar3) {
              local_2e0 = local_2e0 | 4;
            }
          }
        }
      }
      else {
        local_2ec = 1;
        uVar4 = PdcGetResourceMask();
        if ((uVar4 & 0x20) == 0) {
          *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | 1;
          local_2e0 = local_2e0 | 2;
        }
      }
LAB_140027996:
      PdcpResiliencyV2PrintClientMessage(0x14000d470,param_1);
      PdcpResiliencyV2PrintPdcMessage
                ("PdcpResiliencyV2ClientSendMessage",(longlong)local_328,1,
                 *(undefined1 *)(param_1 + 0x18));
      if (*(char *)(param_1 + 0x18) == '\0') {
        PdcSendKernelMessage
                  (*(longlong *)(param_1 + 0x20),local_328,*(undefined4 *)(param_1 + 0x14));
      }
      else {
        PdcSendUserMessage(*(longlong *)(param_1 + 0x20),local_328,0);
      }
      uVar6 = 0x103;
    }
    else {
      uVar6 = (*PdcPoCallbacks)(iVar1,CONCAT71(in_register_00000011,param_2),local_2f0);
      if ((int)uVar6 == 0) {
        *(undefined4 *)(param_1 + 0x38) = 0;
      }
    }
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}



===== PdcpResiliencyV2ClientSetState @ 140027a20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpResiliencyV2ClientSetState(longlong param_1,int param_2)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  
  *(int *)(param_1 + 0x30) = param_2;
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0x34) == 2) {
      KeCancelTimer(&DAT_140013ad0);
      DAT_140013b90 = 0;
      DAT_140013b88 = 0;
      uVar1 = PdcGetInterruptTime();
      *(longlong *)(param_1 + 0x50) =
           *(longlong *)(param_1 + 0x50) + (uVar1 / 10 - *(longlong *)(param_1 + 0x58));
      *(undefined8 *)(param_1 + 0x58) = 0;
      if (*(int *)(param_1 + 0x28) == 5) {
        PdcPoNetworkResiliency();
      }
    }
    else if (*(int *)(param_1 + 0x34) == 1) {
      *(undefined4 *)(param_1 + 0x34) = 2;
    }
    for (puVar2 = *(undefined8 **)(param_1 + 0x40); puVar2 != (undefined8 *)(param_1 + 0x40);
        puVar2 = (undefined8 *)*puVar2) {
      (*(code *)puVar2[3])(puVar2[4]);
    }
    return;
  }
  if (param_2 == 1) {
    if (*(int *)(param_1 + 0x34) != 2) {
      return;
    }
    uVar1 = PdcGetInterruptTime();
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
    *(ulonglong *)(param_1 + 0x58) = uVar1 / 10;
    if (*(int *)(param_1 + 0x28) == 5) {
      PdcPoNetworkResiliency();
    }
  }
  else {
    if (param_2 == 2) {
      if (*(int *)(param_1 + 0x34) == 2) {
        KeCancelTimer(&DAT_140013ad0);
        DAT_140013b88 = 0;
        DAT_140013b90 = 0;
        return;
      }
      return;
    }
    if (param_2 != 3) {
      return;
    }
    if (*(int *)(param_1 + 0x34) != 2) {
      return;
    }
  }
  PdcpResiliencyV2StartClientWatchdog(param_1);
  return;
}



===== PdcpResiliencyV2CompletePoResiliencyCallback @ 140027b70 =====

void PdcpResiliencyV2CompletePoResiliencyCallback(int param_1,int param_2)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  int *piVar4;
  
  PdcAcquireLock();
  uVar2 = 0;
  piVar4 = &PdcpResiliencyV2PoResiliencyMap;
  do {
    if (*piVar4 == param_1) break;
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulonglong)uVar1;
    piVar4 = piVar4 + 1;
  } while (uVar1 < 8);
  if ((&DAT_140013760)[uVar2 * 0x1c] != param_2) goto LAB_140027bdd;
  (&DAT_140013760)[uVar2 * 0x1c] = 0;
  if ((&DAT_140013758)[uVar2 * 0x1c] == 1) {
    iVar3 = 2;
LAB_140027bc9:
    PdcpResiliencyV2ClientSetState((longlong)(&DAT_140013728 + uVar2 * 0x70),iVar3);
  }
  else if ((&DAT_140013758)[uVar2 * 0x1c] == 3) {
    iVar3 = 0;
    goto LAB_140027bc9;
  }
  PdcGetPolicyWorker(0x40);
  PdcCheckForWork();
LAB_140027bdd:
  PdcReleaseLock();
  return;
}



===== PdcpResiliencyV2PrintClientMessage @ 140027bf4 =====

void PdcpResiliencyV2PrintClientMessage(longlong param_1,longlong param_2)

{
  int iVar1;
  char *pcVar2;
  undefined1 uVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  iVar1 = *(int *)(param_2 + 0x30);
  lVar4 = -1;
  if (iVar1 == 0) {
    uVar5 = 0;
  }
  else {
    if (iVar1 == 1) {
      uVar5 = 0;
      uVar3 = 1;
      goto LAB_140027c5a;
    }
    if (iVar1 == 2) {
      uVar3 = 1;
      uVar5 = 1;
      goto LAB_140027c5a;
    }
    if (iVar1 != 3) {
      uVar5 = 0xff;
      uVar3 = 0xff;
      goto LAB_140027c5a;
    }
    uVar5 = 1;
  }
  uVar3 = 0;
LAB_140027c5a:
  pcVar2 = 
  "%S:\nResiliency client (%p):\n\tClientPort:%p\n\tResiliencyType:%s\n\tCurrentTransactionId:%08x\n\tLUID:%08x\n\t ClientReferences:%08x\n\t CurrentState:%08x\n\t NextState:%08x\n"
  ;
  PdcPrint(2,
           "%S:\nResiliency client (%p):\n\tClientPort:%p\n\tResiliencyType:%s\n\tCurrentTransactionId:%08x\n\tLUID:%08x\n\t ClientReferences:%08x\n\t CurrentState:%08x\n\t NextState:%08x\n"
           ,param_1,param_2);
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    do {
      lVar4 = lVar4 + 1;
    } while (*(short *)(param_1 + lVar4 * 2) != 0);
    McTemplateU0ppqxqqqqzr7_EtwWriteTransfer
              ((ulonglong)*(uint *)(param_2 + 0x3c),pcVar2,param_2,*(undefined8 *)(param_2 + 0x20),
               (char)*(undefined4 *)(param_2 + 0x2c),(char)*(uint *)(param_2 + 0x3c),
               (char)*(undefined4 *)(param_2 + 0x38),uVar5,uVar3,(int)lVar4,param_1);
  }
  return;
}



===== PdcpResiliencyV2PrintPdcMessage @ 140027d88 =====

void PdcpResiliencyV2PrintPdcMessage
               (undefined8 param_1,longlong param_2,undefined1 param_3,undefined1 param_4)

{
  undefined8 uVar1;
  char *pcVar2;
  
  uVar1 = 2;
  pcVar2 = 
  "%s:Resiliency message (%p):\n\tTransactionId:%08x\n\tClientState:%08x\n\tClientStatus:%08x\n\tSend:%08x\n\tUserMode:%08x\n"
  ;
  PdcPrint(2,
           "%s:Resiliency message (%p):\n\tTransactionId:%08x\n\tClientState:%08x\n\tClientStatus:%08x\n\tSend:%08x\n\tUserMode:%08x\n"
           ,param_1,param_2);
  if ((Microsoft_Windows_PDCEnableBits & 8) != 0) {
    McTemplateU0pqqqtt_EtwWriteTransfer
              (uVar1,pcVar2,param_2,*(undefined4 *)(param_2 + 0x38),
               (char)*(undefined4 *)(param_2 + 0x3c),(char)*(undefined4 *)(param_2 + 0x40),param_3,
               param_4);
  }
  return;
}



===== PdcpResiliencyV2RequestCancel @ 140027e18 =====

void PdcpResiliencyV2RequestCancel(longlong *param_1,undefined8 param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  undefined *puVar4;
  
  lVar3 = *param_1;
  if ((*(longlong **)(lVar3 + 8) != param_1) ||
     (plVar1 = (longlong *)param_1[1], (longlong *)*plVar1 != param_1)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *plVar1 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar1;
  param_1[1] = (longlong)param_1;
  *param_1 = (longlong)param_1;
  lVar3 = (longlong)(int)param_1[2];
  puVar4 = &DAT_140013728 + lVar3 * 0x70;
  (&DAT_140013764)[lVar3 * 0x1c] = (&DAT_140013764)[lVar3 * 0x1c] + -1;
  if ((Microsoft_Windows_PDCEnableBits & 0x40) != 0) {
    McTemplateU0ppq_EtwWriteTransfer(param_1,&PDC_RESILIENCY_DEREFERENCE,param_2,puVar4,0);
  }
  PdcpResiliencyV2PrintClientMessage(0x14000d5e8,(longlong)puVar4);
  if ((&DAT_140013764)[lVar3 * 0x1c] == 0) {
    PdcpResiliencyV2PrintClientMessage(0x14000d5b0,(longlong)puVar4);
  }
  PdcGetPolicyWorker(0x40);
  PdcCheckForWork();
  return;
}



===== PdcpResiliencyV2RequestInitialize @ 140027ec0 =====

void PdcpResiliencyV2RequestInitialize
               (undefined4 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  *(undefined4 *)(param_4 + 0x14) = 0;
  *(longlong *)(param_4 + 8) = param_4;
  *(longlong *)param_4 = param_4;
  *(undefined4 *)(param_4 + 0x10) = param_1;
  *(undefined8 *)(param_4 + 0x18) = param_2;
  *(undefined8 *)(param_4 + 0x20) = param_3;
  return;
}



===== PdcpResiliencyV2RequestInitiate @ 140027ee0 =====

uint PdcpResiliencyV2RequestInitiate(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined8 *puVar6;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  puVar5 = auStack_38;
  lVar3 = (longlong)*(int *)(param_1 + 2);
  (&DAT_140013764)[lVar3 * 0x1c] = (&DAT_140013764)[lVar3 * 0x1c] + 1;
  puVar4 = &DAT_140013768 + lVar3 * 0xe;
  puVar6 = (undefined8 *)(&DAT_140013770)[lVar3 * 0xe];
  if ((undefined8 *)*puVar6 != puVar4) {
    param_1 = (undefined8 *)0x3;
    pcVar2 = (code *)swi(0x29);
    puVar4 = (undefined8 *)(*pcVar2)();
    puVar5 = auStack_30;
  }
  *param_1 = puVar4;
  param_1[1] = puVar6;
  *puVar6 = param_1;
  puVar4[1] = param_1;
  iVar1 = (&DAT_140013758)[lVar3 * 0x1c];
  if ((Microsoft_Windows_PDCEnableBits & 0x40) != 0) {
    *(undefined4 *)(puVar5 + 0x20) = 1;
    *(undefined8 *)(puVar5 + -8) = 0x140027f51;
    McTemplateU0ppq_EtwWriteTransfer
              (param_1,&PDC_RESILIENCY_REFERENCE,param_2,&DAT_140013728 + lVar3 * 0x70,puVar5[0x20])
    ;
  }
  *(undefined8 *)(puVar5 + -8) = 0x140027f60;
  PdcpResiliencyV2PrintClientMessage(0x14000d520,(longlong)(&DAT_140013728 + lVar3 * 0x70));
  *(undefined8 *)(puVar5 + -8) = 0x140027f6a;
  PdcGetPolicyWorker(0x40);
  *(undefined8 *)(puVar5 + -8) = 0x140027f6f;
  PdcCheckForWork();
  return -(uint)(iVar1 != 0) & 0x103;
}



===== PdcpResiliencyV2StartClientWatchdog @ 140027f84 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpResiliencyV2StartClientWatchdog(longlong param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_140013b88 != 0) {
    KeCancelTimer(&DAT_140013ad0);
    DAT_140013b90 = 0;
    DAT_140013b88 = 0;
  }
  if ((&PdcpResiliencyV2PoResiliencyMap)[*(int *)(param_1 + 0x2c)] == 0) {
    iVar1 = *(int *)(param_1 + 0x28);
    if (((iVar1 == 2) || (iVar1 == 5)) || (iVar2 = PdcCriticalNotificationTimeout, iVar1 == 0x6c)) {
      iVar2 = PdcWcmNotificationTimeout;
    }
    DAT_140013b90 = (ulonglong)(uint)(iVar2 * 10000000) + _DAT_fffff78000000008;
    DAT_140013b88 = _DAT_fffff78000000008;
    PdcSetTimer(0x140013ad0,(ulonglong)(uint)((iVar2 + 1) * 1000));
  }
  return;
}



===== PdcpResiliencyV2WatchdogCallback @ 140028030 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpResiliencyV2WatchdogCallback(void)

{
  int *piVar1;
  uint uVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar2 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((DAT_140013b90 != 0) && (DAT_140013b90 < _DAT_fffff78000000008)) {
    piVar1 = &DAT_140013758;
    do {
      if ((piVar1[-1] != 6) && ((*piVar1 - 1U & 0xfffffffd) == 0)) {
        PdcTriageCaptureContext((longlong)(piVar1 + -0xc),&local_38,'\0');
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x14f,piVar1[-2],2,piVar1 + -0xc,&local_38);
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 0x1c;
    } while (uVar2 < 8);
  }
  return;
}



===== PdcPowerButtonSuppressionCallback @ 1400280e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcPowerButtonSuppressionCallback(int param_1)

{
  bool bVar1;
  undefined1 auStackY_c8 [32];
  undefined1 local_98 [4];
  int local_94;
  int local_90 [2];
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  int *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  PdcAcquireRwLockExclusive(0x1400136b0);
  if (PdcpPowerButtonSuppression != param_1) {
    DAT_1400136a4 = DAT_1400136a4 + 1;
    DAT_1400136a8 = 0;
    PdcpPowerButtonSuppression = param_1;
    if (5 < DAT_140031288) {
      if (((_DAT_140031298 & 0x400000000002) == 0) ||
         (bVar1 = true, (DAT_1400312a0 & 0x400000000002) != DAT_1400312a0)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_58 = &local_94;
        local_48 = local_90;
        local_98[0] = DAT_1400136c8;
        local_38 = local_98;
        local_28 = local_88;
        local_50 = 4;
        local_40 = 4;
        local_30 = 1;
        local_88[0] = 0x1000000;
        local_20 = 8;
        local_94 = param_1;
        local_90[0] = DAT_1400136a4;
        _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000ed9b,0,0x400000000002,6,local_78);
      }
    }
  }
  PdcReleaseRwLockExclusive(0x1400136b0);
  return 0;
}



===== PdcResetSwitchTriggers @ 140028230 =====

void PdcResetSwitchTriggers(void)

{
  undefined8 *puVar1;
  
  PdcAcquireRwLockExclusive(0x140032b28);
  for (puVar1 = PdcSwitches; (undefined8 **)puVar1 != &PdcSwitches; puVar1 = (undefined8 *)*puVar1)
  {
    *(undefined1 *)((longlong)puVar1 + 0x11) = 0;
  }
  PdcReleaseRwLockExclusive(0x140032b28);
  return;
}



===== PdcSoftSwitchHandler @ 140028274 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcSoftSwitchHandler
               (undefined8 param_1,undefined8 param_2,longlong *param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 *puVar2;
  undefined1 auStackY_98 [32];
  uint local_68 [2];
  undefined8 local_60;
  undefined8 local_58 [4];
  uint *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  puVar2 = PdcPolicyClientShimPowerButton;
  if ((*param_3 == 0x4ee97f6236844184) && (param_3[1] == -0x58797b0f550ff077)) {
    param_4 = (undefined4 *)0x0;
    if ((DAT_140014dac == '\0') || (cVar1 = PdcpIsPowerSettingInitialized(), cVar1 == '\0')) {
      cVar1 = '\x01';
      PdcpDeferSwitchSignalTotalCount = PdcpDeferSwitchSignalTotalCount + 1;
      if (PdcpDeferSwitchSignalDevice == param_4) {
        PdcpDeferRequestedSwitch = 1;
        PdcpDeferSwitchSignalDevice = puVar2;
      }
      if (DAT_140031288 < 6) {
        return;
      }
      if (((_DAT_140031298 & 0x400000000002) == 0) ||
         ((DAT_1400312a0 & 0x400000000002) != DAT_1400312a0)) {
        cVar1 = (char)param_4;
      }
      if (cVar1 == '\0') {
        return;
      }
      local_38 = local_68;
      local_30 = 4;
      local_28 = &local_60;
      local_60 = 0x1000000;
      local_20 = 8;
      local_68[0] = PdcpDeferSwitchSignalTotalCount;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140031288,&DAT_14000ee04,(ulonglong)PdcpDeferSwitchSignalTotalCount,param_4,4,
                 local_58);
      return;
    }
    if (PdcpDeferSwitchSignalTotalCount != (int)param_4) {
      return;
    }
  }
  PdcpHandleSwitch((longlong)puVar2,1,0,param_4);
  return;
}



===== PdcSystemButtonHandler @ 1400283c0 =====

void PdcSystemButtonHandler(longlong param_1,longlong param_2,longlong *param_3,undefined4 *param_4)

{
  char *pcVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar8 = (ulonglong)*(uint *)(param_2 + 0x30);
  pcVar1 = (char *)((longlong)param_3 + 0x22);
  if (((int)*(uint *)(param_2 + 0x30) < 0) || (*pcVar1 != '\0')) {
    if (*(char *)((longlong)param_3 + 0x21) == '\0') {
      PdcPrint(1,"PdcSystemButtonHandler: unexpected error %x\n",uVar8,param_4);
    }
    else {
      if ((*(uint *)(*(longlong *)(param_1 + 0x138) + 0x20) & 2) == 0) {
        uVar5 = 0x294140;
        *(undefined1 *)((longlong)param_3 + 0x21) = 0;
        goto LAB_140028478;
      }
      PdcPrint(1,"PdcSystemButtonHandler: unexpected device removal\n",uVar8,param_4);
    }
    *(undefined1 *)(param_3 + 4) = 0;
    uVar5 = 0;
    *pcVar1 = '\x01';
  }
  else {
    if ((char)param_3[4] == '\0') {
      uVar6 = *(uint *)((longlong)param_3 + 0x24) & 7;
      *(undefined4 *)((longlong)param_3 + 0x24) = 0;
      *(uint *)((longlong)param_3 + 0x14) = uVar6;
      *(undefined1 *)(param_3 + 4) = 1;
      if (uVar6 == 0) {
        *pcVar1 = '\x01';
      }
      else {
        PdcpSwitchUpdateCapabilitiesCount(0,uVar6);
      }
    }
    else {
      uVar8 = 0;
      PdcpHandleSwitch((longlong)param_3,(ulonglong)*(uint *)((longlong)param_3 + 0x24),0,param_4);
    }
    uVar5 = 0x294144;
  }
LAB_140028478:
  puVar7 = auStack_28;
  if (*pcVar1 != '\0') {
    PdcPrint(1,"PdcSystemButtonHandler: removing button device\n",uVar8,param_4);
    lVar2 = *param_3;
    if ((*(longlong **)(lVar2 + 8) == param_3) &&
       (plVar3 = (longlong *)param_3[1], (longlong *)*plVar3 == param_3)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      PdcpSwitchUpdateCapabilitiesCount(*(uint *)((longlong)param_3 + 0x14),0);
      IoFreeIrp(param_2);
      ObfDereferenceObject(param_1);
      RtlFreeUnicodeString(param_3 + 6);
      ExFreePoolWithTag(param_3,0);
      return;
    }
    uVar5 = 3;
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)();
    puVar7 = auStack_20;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(undefined4 *)(lVar2 + -0x30) = uVar5;
  *(undefined4 *)(lVar2 + -0x38) = 4;
  *(undefined4 *)(lVar2 + -0x40) = 4;
  *(undefined1 *)(lVar2 + -0x48) = 0xe;
  *(longlong *)(param_2 + 0x18) = (longlong)param_3 + 0x24;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(lVar2 + -8) = 0;
  *(code **)(lVar2 + -0x10) = PdcCompletePolicyIrp;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  *(undefined8 *)(puVar7 + -8) = 0x140028542;
  IofCallDriver(param_1,param_2);
  return;
}



===== PdcUserShutdownCancelled @ 140028570 =====

char PdcUserShutdownCancelled(char param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  PdcAcquireRwLockExclusive(0x140032b28);
  PdcAcquireRwLockExclusive(0x140032b78);
  puVar7 = auStackY_48;
  if (PdcUserShutdownInProgress != '\0') {
    bVar3 = false;
    while (puVar1 = DAT_140032b70, puVar6 = PdcUserShutdownDelayList, puVar7 = auStackY_48,
          (undefined8 **)PdcUserShutdownDelayList != &PdcUserShutdownDelayList) {
      if (param_1 == '\0') {
        if (((undefined8 **)PdcUserShutdownDelayList[1] != &PdcUserShutdownDelayList) ||
           (puVar1 = (undefined8 *)*PdcUserShutdownDelayList,
           (undefined8 *)puVar1[1] != PdcUserShutdownDelayList)) goto LAB_14002868f;
        PdcUserShutdownDelayList = puVar1;
        puVar1[1] = &PdcUserShutdownDelayList;
      }
      else {
        if (((undefined8 **)*DAT_140032b70 != &PdcUserShutdownDelayList) ||
           (puVar6 = (undefined8 *)DAT_140032b70[1], (undefined8 *)*puVar6 != DAT_140032b70)) {
LAB_14002868f:
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(3);
          puVar7 = auStackY_40;
          break;
        }
        DAT_140032b70 = puVar6;
        *puVar6 = &PdcUserShutdownDelayList;
        puVar6 = puVar1;
      }
      if ((!bVar3) && ((undefined8 **)PdcSwitches != &PdcSwitches)) {
        puVar1 = (undefined8 *)puVar6[2];
        puVar5 = PdcSwitches;
        do {
          if (puVar1 == puVar5) {
            if (param_1 != '\0') {
              if ((*(uint *)((longlong)puVar1 + 0x14) & 4) == 0) break;
              bVar3 = true;
            }
            PdcpTriggerActionByCaps
                      ((longlong)puVar1,puVar6 + 3,(undefined8 *)((longlong)puVar6 + 0x24),
                       puVar6 + 6,*(uint *)((longlong)puVar6 + 0x3c),*(char *)(puVar6 + 8),
                       (uint *)0x0);
            break;
          }
          puVar5 = (undefined8 *)*puVar5;
        } while ((undefined8 **)puVar5 != &PdcSwitches);
      }
      ExFreePoolWithTag(puVar6,0x74775350);
    }
  }
  cVar4 = PdcUserShutdownInProgress;
  PdcUserShutdownInProgress = 0;
  *(undefined8 *)(puVar7 + -8) = 0x1400286af;
  PdcReleaseRwLockExclusive(0x140032b78);
  *(undefined8 *)(puVar7 + -8) = 0x1400286bb;
  PdcReleaseRwLockExclusive(0x140032b28);
  return cVar4;
}



===== PdcUserShutdownInitiated @ 1400286e0 =====

bool PdcUserShutdownInitiated(void)

{
  bool bVar1;
  
  PdcAcquireRwLockExclusive(0x140032b78);
  bVar1 = PdcUserShutdownInProgress == '\0';
  if (bVar1) {
    PdcUserShutdownInProgress = '\x01';
    DAT_140032b70 = &PdcUserShutdownDelayList;
    PdcUserShutdownDelayList = &PdcUserShutdownDelayList;
  }
  PdcReleaseRwLockExclusive(0x140032b78);
  return bVar1;
}



===== PdcpDeferSwitchSignalSystemStarted @ 140028734 =====

void PdcpDeferSwitchSignalSystemStarted(void)

{
  char cVar1;
  
  if (DAT_140014dac != '\0') {
    cVar1 = PdcpIsPowerSettingInitialized();
    if (cVar1 != '\0') {
      PdcAcquireRwLockExclusive(0x140032b28);
      if (PdcpDeferSwitchSignalWorkerRunning == '\0') {
        PdcpDeferSwitchSignalWorkerRunning = '\x01';
        ExQueueWorkItem(&PdcpDeferSwitchSignalWorkItem,1);
      }
      PdcReleaseRwLockExclusive(0x140032b28);
    }
  }
  return;
}



===== PdcpDeferSwitchSignalWorkItemCallback @ 1400287a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpDeferSwitchSignalWorkItemCallback(void)

{
  bool bVar1;
  undefined8 uVar2;
  undefined4 *in_R9;
  undefined1 auStackY_d8 [32];
  undefined1 local_a8 [4];
  int local_a4;
  undefined4 local_a0;
  uint local_9c;
  undefined8 local_98 [2];
  undefined8 local_88 [4];
  int *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  PdcAcquireRwLockExclusive(0x140032b28);
  if ((PdcpDeferSwitchSignalTotalCount != 0) && (PdcpDeferSwitchSignalDevice != 0)) {
    uVar2 = 0;
    PdcpHandleSwitch(PdcpDeferSwitchSignalDevice,(ulonglong)PdcpDeferRequestedSwitch,0,in_R9);
    if (5 < DAT_140031288) {
      if (((_DAT_140031298 & 0x400000000002) == 0) ||
         ((DAT_1400312a0 & 0x400000000002) != DAT_1400312a0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_5c = 0;
        local_4c = 0;
        local_3c = 0;
        local_2c = 0;
        local_1c = 0;
        local_a4 = PdcpDeferSwitchSignalTotalCount;
        local_68 = &local_a4;
        local_a8[0] = *(undefined1 *)(PdcpDeferSwitchSignalDevice + 0x10);
        local_58 = local_a8;
        local_a0 = *(undefined4 *)(PdcpDeferSwitchSignalDevice + 0x14);
        local_48 = &local_a0;
        local_9c = PdcpDeferRequestedSwitch;
        local_38 = &local_9c;
        local_28 = local_98;
        local_60 = 4;
        local_40 = 4;
        local_30 = 4;
        local_50 = 1;
        local_98[0] = 0x1000000;
        local_20 = 8;
        _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000f0dc,uVar2,in_R9,7,local_88);
      }
    }
    PdcpDeferSwitchSignalTotalCount = 0;
  }
  PdcpDeferSwitchSignalWorkerRunning = 0;
  PdcReleaseRwLockExclusive(0x140032b28);
  return;
}



===== PdcpGetSwitchRequestReason @ 140028914 =====

byte PdcpGetSwitchRequestReason(longlong param_1)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if ((uVar1 & 4) != 0) {
    return 0xf;
  }
  bVar2 = 1;
  if ((uVar1 & 1) == 0) {
    bVar2 = -((uVar1 & 2) != 0) & 0xe;
  }
  return bVar2;
}



===== PdcpHandleSwitch @ 140028940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpHandleSwitch(longlong param_1,ulonglong param_2,undefined8 param_3,undefined4 *param_4)

{
  code *pcVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  undefined8 *puVar6;
  char cVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  undefined1 *puVar10;
  uint uVar11;
  char cVar12;
  char cVar13;
  int iVar14;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  ulonglong local_38 [2];
  
  uVar9 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  cVar2 = (char)param_3;
  cVar13 = '\0';
  cVar12 = '\0';
  iVar14 = 0;
  uVar8 = param_2;
  if (((*(uint *)(param_1 + 0x14) & 1) != 0) && ((param_2 & 1) != 0)) {
    PdcAcquireRwLockExclusive(0x140014d80);
    if ((DAT_140014db4 != '\0') || (bVar3 = false, DAT_140014dc8 == '\0')) {
      bVar3 = true;
    }
    PdcReleaseRwLockExclusive(0x140014d80);
    iVar4 = PdcButtonWriteWorkerActive;
    if (bVar3) {
      LOCK();
      PdcButtonWriteWorkerActive = 1;
      UNLOCK();
      if (iVar4 == 0) {
        uVar8 = 1;
        ExQueueWorkItem(&PdcButtonWriteWorker);
      }
    }
    else {
      (*DAT_140015088)();
    }
  }
  lVar5 = _DAT_fffff78000000008;
  puVar10 = auStackY_88;
  uVar11 = (uint)param_2;
  if ((*(uint *)(param_1 + 0x14) & 4) == 0) {
LAB_140028b29:
    PdcAcquireRwLockExclusive(0x140032b78);
    if (PdcUserShutdownInProgress != '\0') {
      puVar6 = (undefined8 *)ExAllocatePool2(0x100,0x48,0x74775350);
      if (puVar6 != (undefined8 *)0x0) {
        puVar6[2] = param_1;
        puVar6[3] = CONCAT44((undefined4)DAT_1400135dc,DAT_1400135d8);
        *(undefined4 *)(puVar6 + 4) = DAT_1400135dc._4_4_;
        *(undefined8 *)((longlong)puVar6 + 0x24) = _PdcPowerSettingValues;
        *(undefined4 *)((longlong)puVar6 + 0x2c) = DAT_1400135c4._4_4_;
        puVar6[6] = _DAT_1400135cc;
        *(undefined4 *)(puVar6 + 7) = DAT_1400135d0._4_4_;
        *(uint *)((longlong)puVar6 + 0x3c) = uVar11;
        *(char *)(puVar6 + 8) = cVar12;
        if ((undefined8 *)*DAT_140032b70 != &PdcUserShutdownDelayList) {
          pcVar1 = (code *)swi(0x29);
          (*pcVar1)(3);
          puVar10 = auStackY_80;
          goto LAB_140028bd0;
        }
        *puVar6 = &PdcUserShutdownDelayList;
        cVar13 = '\x01';
        puVar6[1] = DAT_140032b70;
        *DAT_140032b70 = puVar6;
        DAT_140032b70 = puVar6;
      }
    }
    PdcReleaseRwLockExclusive(0x140032b78);
    puVar10 = auStackY_88;
    if (cVar13 == '\0') {
      param_4 = &DAT_1400135cc;
      PdcpTriggerActionByCaps
                (param_1,(undefined8 *)&DAT_1400135d8,(undefined8 *)&PdcPowerSettingValues,
                 (undefined8 *)&DAT_1400135cc,uVar11,cVar12,(uint *)local_38);
      puVar10 = auStackY_88;
    }
  }
  else {
    if (DAT_140013690 == 0) {
      DAT_140013690 = param_1;
    }
    if ((uVar11 >> 0x10 & 1) == 0) {
      if ((uVar11 >> 0x11 & 1) != 0) {
        cVar7 = '\x02';
        if (cVar2 != '\0') goto LAB_140028a37;
        if ((DAT_1400135e8 != '\0') && (DAT_1400135d8 == 0)) {
          DAT_140013684 = 1;
        }
        goto LAB_140028a59;
      }
LAB_140028bd0:
      *(uint *)(puVar10 + 0x50) = *(uint *)(puVar10 + 0x50) | 0x100;
    }
    else {
      cVar7 = '\x01';
LAB_140028a37:
      DAT_140013684 = 0;
LAB_140028a59:
      if ((cVar7 != *(char *)(param_1 + 0x18)) || (cVar2 != '\0')) {
        *(char *)(param_1 + 0x18) = cVar7;
        cVar12 = '\x01';
        if (cVar2 == '\0') {
          (*DAT_140015080)(cVar7 == '\x01');
          DAT_1400136f0 = DAT_1400136f0 + 1;
          if (DAT_1400136f4 < DAT_1400136f0) {
            PdcpLidReliabilityUpdate('\x01',uVar8,param_3,param_4);
          }
          DAT_1400136e1 = '\0';
        }
LAB_140028b16:
        _DAT_1400136e8 = lVar5;
        DAT_1400136e2 = '\0';
        _DAT_1400136f8 = uVar11;
        goto LAB_140028b29;
      }
      if ((_DAT_1400136f8 & 0x40000) != 0) goto LAB_140028b16;
      if (999999 < _DAT_fffff78000000008 - _DAT_1400136e8) {
        if ((PdcpSwitchProcessingSuspended == '\0') && (DAT_1400136e2 == '\0')) {
          iVar14 = (cVar7 != '\x01') + 1;
          PdcpLidReliabilityUpdate('\0',uVar8,param_3,param_4);
          if (DAT_1400136e1 == '\0') {
            DAT_1400136f0 = 0;
          }
          DAT_1400136e1 = '\x01';
        }
        goto LAB_140028b16;
      }
      local_38[0] = local_38[0] | 0x10;
      puVar10 = auStackY_88;
    }
    uVar9 = 1;
  }
  *(undefined4 *)(puVar10 + 0x40) = *(undefined4 *)(puVar10 + 0x90);
  puVar10[0x38] = cVar2;
  *(int *)(puVar10 + 0x30) = iVar14;
  puVar10[0x28] = uVar9;
  puVar10[0x20] = cVar13;
  *(undefined8 *)(puVar10 + -8) = 0x140028c61;
  PdcpLogHandleSwitch(param_1,(undefined4 *)(puVar10 + 0x50),uVar11,
                      CONCAT71((int7)((ulonglong)param_4 >> 8),cVar12),puVar10[0x20],puVar10[0x28],
                      *(undefined4 *)(puVar10 + 0x30),puVar10[0x38],*(undefined4 *)(puVar10 + 0x40))
  ;
  return;
}



===== PdcpLidReliabilityUpdate @ 140028c88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpLidReliabilityUpdate(char param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  undefined1 auStackY_98 [32];
  char local_68 [8];
  undefined8 local_60;
  undefined8 local_58 [4];
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (PdcpDupLidStateContext != param_1) {
    PdcpDupLidStateContext = param_1;
    if (DAT_1400150f0 != (code *)0x0) {
      (*DAT_1400150f0)();
    }
    if (5 < DAT_140031288) {
      if (((_DAT_140031298 & 0x400000000002) == 0) ||
         ((DAT_1400312a0 & 0x400000000002) != DAT_1400312a0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_2c = 0;
        local_38 = local_68;
        local_1c = 0;
        local_28 = &local_60;
        local_30 = 1;
        local_60 = 0x1000000;
        local_20 = 8;
        local_68[0] = param_1;
        _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000f09a,param_3,param_4,4,local_58);
      }
    }
  }
  return;
}



===== PdcpLogHandleSwitch @ 140028d88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpLogHandleSwitch(longlong param_1,undefined4 *param_2,undefined4 param_3,undefined8 param_4,
                        undefined1 param_5,undefined1 param_6,undefined4 param_7,undefined1 param_8,
                        undefined4 param_9)

{
  bool bVar1;
  longlong lVar2;
  undefined1 auStackY_1f8 [32];
  undefined1 local_1c8;
  undefined1 local_1c7;
  undefined1 local_1c6;
  undefined1 local_1c5;
  undefined4 local_1c4;
  undefined4 local_1c0;
  uint local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  int local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined8 local_188 [2];
  undefined8 local_178 [4];
  undefined1 *local_158;
  undefined8 local_150;
  undefined1 *local_148;
  undefined8 local_140;
  undefined1 *local_138;
  undefined8 local_130;
  undefined4 *local_128;
  undefined8 local_120;
  undefined4 *local_118;
  undefined8 local_110;
  uint *local_108;
  undefined8 local_100;
  undefined4 *local_f8;
  undefined8 local_f0;
  undefined4 *local_e8;
  undefined8 local_e0;
  undefined4 *local_d8;
  undefined8 local_d0;
  undefined4 *local_c8;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  lVar2 = _DAT_fffff78000000008;
  local_18 = __security_cookie ^ (ulonglong)auStackY_1f8;
  if (_DAT_fffff78000000008 - _PdcSwitchTelemetryContext < 1000000) {
    if ((*(uint *)(param_1 + 0x14) & 4) != 0) {
      DAT_140032bb4 = DAT_140032bb4 + 1;
    }
    if ((*(uint *)(param_1 + 0x14) & 3) != 0) {
      DAT_140032bb0 = DAT_140032bb0 + 1;
    }
  }
  else {
    if (5 < DAT_140031288) {
      if (((_DAT_140031298 & 0x400000000000) == 0) ||
         (bVar1 = true, (DAT_1400312a0 & 0x400000000000) != DAT_1400312a0)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_1c8 = *(undefined1 *)(param_1 + 0x10);
        local_158 = &local_1c8;
        local_1c7 = param_5;
        local_148 = &local_1c7;
        local_1c6 = param_6;
        local_138 = &local_1c6;
        local_1c4 = *(undefined4 *)(param_1 + 0x14);
        local_128 = &local_1c4;
        local_118 = &local_1c0;
        local_1bc = (uint)param_4 & 0xff;
        local_108 = &local_1bc;
        local_1b8 = DAT_1400135d8;
        local_f8 = &local_1b8;
        local_1b4 = DAT_1400135e4;
        local_e8 = &local_1b4;
        local_1b0 = PdcPowerSettingValues;
        local_d8 = &local_1b0;
        local_1ac = DAT_1400135cc;
        local_c8 = &local_1ac;
        local_1a8 = *param_2;
        local_b8 = &local_1a8;
        local_1a4 = param_2[1];
        local_a8 = &local_1a4;
        local_1a0 = param_2[2];
        local_98 = &local_1a0;
        local_19c = param_2[3];
        local_88 = &local_19c;
        local_198 = param_7;
        local_78 = &local_198;
        local_194 = DAT_140032bb4;
        local_68 = &local_194;
        local_190 = DAT_140032bb0;
        local_150 = 1;
        local_140 = 1;
        local_130 = 1;
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
        local_58 = &local_190;
        local_30 = 1;
        local_18c = param_9;
        local_48 = &local_18c;
        local_1c5 = param_8;
        local_38 = &local_1c5;
        local_28 = local_188;
        local_50 = 4;
        local_40 = 4;
        local_188[0] = 0x1000000;
        local_20 = 8;
        local_1c0 = param_3;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x140031288,&DAT_14000eea7,0x400000000000,param_4,0x16,local_178);
      }
    }
    _PdcSwitchTelemetryContext = lVar2;
    _DAT_140032bb0 = 0;
  }
  return;
}



===== PdcpPrintPowerButton @ 1400290c8 =====

void PdcpPrintPowerButton
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  PdcPrint(2,
           "####################################################################################\n",
           param_3,param_4);
  PdcPrint(2," Power/sleep button pushed\n",param_3,param_4);
  PdcPrint(2,
           "####################################################################################\n",
           param_3,param_4);
  return;
}



===== PdcpPrintPowerButtonConsumed @ 14002910c =====

void PdcpPrintPowerButtonConsumed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  PdcPrint(2,"###################################################################################\n"
           ,param_3,param_4);
  PdcPrint(2," Power/sleep button to be consumed\n",param_3,param_4);
  PdcPrint(2,
           "####################################################################################\n",
           param_3,param_4);
  return;
}



===== PdcpReplayLidClose @ 140029150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpReplayLidClose(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4
                       )

{
  bool bVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined7 uVar5;
  undefined1 auStackY_d8 [32];
  undefined1 local_a8 [4];
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98 [2];
  undefined8 local_88 [4];
  undefined1 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  int *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  uVar4 = (undefined1)param_3;
  uVar5 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar3 = 0;
  uVar2 = 0;
  if (PdcpReplayLidCloseContext == '\0') {
    uVar2 = 1;
  }
  else if (DAT_140013684 == 7) {
    if (DAT_140013688 == '\0') {
      uVar4 = 1;
      uVar3 = *(undefined1 *)(DAT_140013690 + 0x18);
      PdcpHandleSwitch(DAT_140013690,0x20004,CONCAT71(uVar5,1),param_4);
    }
    else {
      uVar2 = 3;
    }
  }
  else {
    uVar2 = 2;
  }
  if (5 < DAT_140031288) {
    if (((_DAT_140031298 & 0x400000000000) == 0) ||
       ((DAT_1400312a0 & 0x400000000000) != DAT_1400312a0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_5c = 0;
      local_68 = local_a8;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_a4 = DAT_140013684;
      local_58 = &local_a4;
      local_48 = &local_a0;
      local_38 = &local_9c;
      local_28 = local_98;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_60 = 1;
      local_98[0] = 0x1000000;
      local_20 = 8;
      local_a8[0] = uVar3;
      local_a0 = param_1;
      local_9c = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140031288,&DAT_14000f1bc,CONCAT71(uVar5,uVar4),param_4,7,local_88);
    }
  }
  return;
}



===== PdcpReplayLidClosePowerSourceUpdate @ 1400292cc =====

void PdcpReplayLidClosePowerSourceUpdate
               (char param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  PdcAcquireRwLockExclusive(0x140032b28);
  if (param_1 == '\0') {
    DAT_140013684 = DAT_140013684 | 2;
    PdcpReplayLidClose(2,param_2,param_3,param_4);
  }
  else {
    DAT_140013684 = DAT_140013684 & 0xfffffffd;
  }
  PdcReleaseRwLockExclusive(0x140032b28);
  return;
}



===== PdcpSuppressPowerButton @ 140029318 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 PdcpSuppressPowerButton(undefined4 param_1)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8;
  int local_a4;
  int local_a0;
  uint local_9c;
  undefined8 local_98 [2];
  undefined8 local_88 [4];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  int *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (PdcpPlatformAoAcCapable == '\0') {
    return 0;
  }
  PdcAcquireRwLockExclusive(0x1400136b0);
  bVar1 = true;
  if (PdcpPowerButtonSuppression == 1) {
    DAT_1400136a8 = DAT_1400136a8 + 1;
    uVar2 = 1;
    DAT_1400136ac = DAT_1400136ac + 1;
  }
  else {
    uVar2 = 0;
    if (PdcpPowerButtonSuppression != 2) goto LAB_14002945e;
  }
  if (5 < DAT_140031288) {
    if (((_DAT_140031298 & 0x400000000002) == 0) ||
       ((DAT_1400312a0 & 0x400000000002) != DAT_1400312a0)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_5c = 0;
      local_68 = &local_a8;
      local_4c = 0;
      local_3c = 0;
      local_2c = 0;
      local_1c = 0;
      local_a4 = DAT_1400136a8;
      local_58 = &local_a4;
      local_a0 = DAT_1400136ac;
      local_48 = &local_a0;
      local_38 = &local_9c;
      local_28 = local_98;
      local_60 = 4;
      local_50 = 4;
      local_40 = 4;
      local_30 = 4;
      local_9c = PdcpPowerButtonSuppression;
      local_98[0] = 0x1000000;
      local_20 = 8;
      local_a8 = param_1;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140031288,&DAT_14000f02c,(ulonglong)PdcpPowerButtonSuppression,0x400000000002,7,
                 local_88);
    }
  }
LAB_14002945e:
  PdcReleaseRwLockExclusive(0x1400136b0);
  return uVar2;
}



===== PdcpSwitchUpdateCapabilitiesCount @ 140029494 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpSwitchUpdateCapabilitiesCount(uint param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  piVar3 = &PdcpSwitchCapabilityCounts;
  uVar4 = 0;
  do {
    uVar5 = 1 << ((byte)uVar4 & 0x1f);
    if ((uVar5 & (param_1 ^ param_2)) != 0) {
      if ((param_2 & uVar5) == 0) {
        iVar1 = *piVar3 + -1;
        *piVar3 = iVar1;
        if (iVar1 == 0) {
          uVar2 = 0;
          goto LAB_1400294e4;
        }
      }
      else {
        iVar1 = *piVar3 + 1;
        *piVar3 = iVar1;
        if (iVar1 == 1) {
          uVar2 = 1;
LAB_1400294e4:
          (*DAT_140015078)(uVar5,uVar2);
        }
      }
    }
    uVar4 = uVar4 + 1;
    piVar3 = piVar3 + 1;
    if (2 < uVar4) {
      return;
    }
  } while( true );
}



===== PdcpTriggerSpecificAction @ 14002951c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PdcpTriggerSpecificAction(longlong param_1,uint param_2,undefined8 *param_3,uint param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  uint local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  local_3c = 0;
  local_50 = 0;
  uStack_48 = 0;
  if ((*(uint *)(param_1 + 0x14) & param_2) == 0) {
    uVar2 = 3;
  }
  else if (((param_4 & param_2) == 0) || ((*(byte *)(param_1 + 0x11) & (byte)param_2) != 0)) {
    uVar2 = 4;
  }
  else {
    local_38 = *param_3;
    local_30 = *(undefined4 *)(param_3 + 1);
    if ((PdcpPlatformAoAcCapable == '\0') || (((int)local_38 != 2 && ((int)local_38 != 8)))) {
      (*DAT_140015090)();
    }
    if (((PdcpPlatformAoAcCapable == '\0') || (DAT_140014dac == '\0')) ||
       (((int)local_38 != 2 && ((int)local_38 != 8)))) {
      local_3c = 0;
      local_58 = 0;
      local_54 = 0x80;
      local_50 = 0;
      uStack_48 = 0;
      local_68 = 1;
      local_40 = param_2;
      (*DAT_140015070)(&local_58,0,&local_38,2);
      uVar2 = 2;
      if ((int)local_38 != 0) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | (byte)param_2;
      }
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x14);
      uVar2 = 1;
      if ((uVar1 & 4) == 0) {
        if ((uVar1 & 1) == 0) {
          uVar1 = -(uint)((uVar1 & 2) != 0) & 0xe;
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 0xf;
      }
      PdcMonitorControl(0,uVar1);
    }
  }
  return uVar2;
}



===== PdcpButtonWriteWorkerThread @ 140029670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpButtonWriteWorkerThread(void)

{
  LOCK();
  PdcButtonWriteWorkerActive = 0;
  UNLOCK();
  (*DAT_140015088)();
  return;
}



===== PdcpDelayedInitializationWorker @ 1400296a0 =====

undefined8 PdcpDelayedInitializationWorker(void)

{
  ulonglong uVar1;
  
  LOCK();
  PdcDelayedInitializationWorkerRun = 1;
  UNLOCK();
  uVar1 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    PdcpAlpcProcessMessagesV1();
  }
  else {
    PdcpAlpcProcessMessagesV2();
  }
  return 0;
}



===== PdcpPhasesWorker @ 1400296e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcpPhasesWorker(undefined *param_1,undefined *param_2,undefined8 param_3)

{
  bool bVar1;
  char cVar2;
  ulonglong uVar3;
  int *piVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  int *piVar8;
  undefined7 uVar9;
  
  uVar9 = (undefined7)((ulonglong)param_3 >> 8);
  PdcAcquireLock();
  uVar3 = Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    DAT_140031028 = SystemReserved1[0xf];
  }
  if (PdcPhasesContext != '\0') {
    uVar6 = 0;
    if (DAT_1400312c4 == 0) {
      piVar4 = &DAT_1400312c4;
      param_1 = &DAT_140031d84;
      do {
        if (0x140031d83 < (longlong)piVar4) break;
        piVar4 = piVar4 + 0x56;
        uVar6 = uVar6 + 1;
      } while (*piVar4 == 0);
    }
    if (Microsoft_Windows_PDCEnableBits < '\0') {
      param_2 = &PDC_TARGET_PHASE_SELECTED;
      McTemplateU0uuu_EtwWriteTransfer
                (param_1,&PDC_TARGET_PHASE_SELECTED,CONCAT71(uVar9,DAT_140031010),(char)uVar6,
                 (undefined1)DAT_14003100c);
    }
    _DAT_140031010 = uVar6;
    while (lVar5 = (longlong)(int)DAT_14003100c, DAT_14003100c != _DAT_140031010) {
      piVar4 = (int *)(&PdcPhasesEx + lVar5 * 0x158);
      bVar1 = (int)_DAT_140031010 <= (int)DAT_14003100c;
      if (bVar1) {
        uVar3 = PdcpDisengagePhase(piVar4);
        uVar6 = (uint)uVar3;
      }
      else {
        uVar6 = PdcpEngagePhase(piVar4);
      }
      if (uVar6 == 0x103) goto LAB_140029849;
      PdcpSetPhaseTargetBlockingState(piVar4,'\0');
      uVar3 = (ulonglong)DAT_14003100c;
      uVar6 = DAT_14003100c - 1;
      DAT_14003100c = DAT_14003100c + 1;
      if (bVar1) {
        DAT_14003100c = uVar6;
      }
      param_2 = (undefined *)(ulonglong)DAT_14003100c;
      PdcpRecordPhaseTransition(uVar3,DAT_14003100c);
    }
    lVar7 = lVar5 * 0x158;
    piVar8 = (int *)(&PdcPhasesEx + lVar7);
    piVar4 = piVar8;
    if ((&DAT_1400312c4)[lVar5 * 0x56] == 0) {
      uVar6 = PdcpEngagePhase(piVar8);
    }
    else {
      uVar3 = PdcpDisengagePhase(piVar8);
      uVar6 = (uint)uVar3;
    }
    if (uVar6 == 0) {
      if (Microsoft_Windows_PDCEnableBits < '\0') {
        McTemplateU0u_EtwWriteTransfer(piVar4,param_2,CONCAT71(uVar9,(undefined1)DAT_14003100c));
      }
      cVar2 = PdcpHasNotificationClients(piVar8);
      if (cVar2 == '\0') {
        cVar2 = (&DAT_1400312e8)[lVar7];
      }
      else {
        cVar2 = *(int *)(&DAT_1400312ec + lVar7) == 4;
      }
      if (cVar2 == '\0') {
        PdcpSetPhaseTargetBlockingState(piVar8,'\x01');
      }
    }
  }
LAB_140029849:
  uVar3 = Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    DAT_140031028 = (void *)0x0;
  }
  PdcReleaseLock();
  return 0;
}



===== PdcpPolicyWorkerMain @ 140029880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
PdcpPolicyWorkerMain(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  longlong lVar4;
  undefined *puVar5;
  
  uVar3 = PdcActivationClientActivityRequest(param_1,1,'\x01',param_4);
  while( true ) {
    puVar5 = &PdcPolicyIrpQueue;
    lVar4 = ExInterlockedRemoveHeadList(&PdcPolicyIrpQueue,&PdcWorkerSpinLock);
    if (lVar4 == 0) break;
    lVar1 = *(longlong *)(lVar4 + 0x10);
    pcVar2 = *(code **)(lVar1 + 0x18);
    PdcAcquireRwLockExclusive(0x140032b28);
    (*pcVar2)(*(undefined8 *)(lVar1 + 8),lVar4 + -0xa8);
    PdcReleaseRwLockExclusive(0x140032b28);
  }
  if (-1 < (int)uVar3) {
    PdcActivationClientActivityRequest(puVar5,1,'\0',param_4);
  }
  return 0;
}



===== PdcpResiliencyWorker @ 140029940 =====

undefined8 PdcpResiliencyWorker(void)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  int iVar3;
  
  PdcAcquireLock();
  puVar1 = &DAT_140013a78;
  iVar3 = 7;
  do {
    if ((undefined8 *)*puVar1 != puVar1) break;
    iVar3 = iVar3 + -1;
    puVar1 = puVar1 + -0xe;
  } while (0x140013768 < (longlong)puVar1);
  do {
    if (PdcpResiliencyV2Context == iVar3) {
LAB_1400299bf:
      if (PdcpResiliencyV2Context == iVar3) {
        if ((undefined8 *)(&DAT_140013768)[(longlong)iVar3 * 0xe] ==
            &DAT_140013768 + (longlong)iVar3 * 0xe) {
          PdcpResiliencyV2ClientEngage((longlong)(&DAT_140013728 + (longlong)iVar3 * 0x70));
        }
        else {
          PdcpResiliencyV2ClientDisengage((longlong)(&DAT_140013728 + (longlong)iVar3 * 0x70));
        }
      }
      PdcReleaseLock();
      return 0;
    }
    if (iVar3 < PdcpResiliencyV2Context) {
      uVar2 = PdcpResiliencyV2ClientEngage
                        ((longlong)(&DAT_140013728 + (longlong)PdcpResiliencyV2Context * 0x70));
      if ((int)uVar2 == 0x103) goto LAB_1400299bf;
      PdcpResiliencyV2Context = PdcpResiliencyV2Context + -1;
    }
    else {
      uVar2 = PdcpResiliencyV2ClientDisengage
                        ((longlong)(&DAT_140013728 + (longlong)PdcpResiliencyV2Context * 0x70));
      if ((int)uVar2 == 0x103) goto LAB_1400299bf;
      PdcpResiliencyV2Context = PdcpResiliencyV2Context + 1;
    }
  } while( true );
}



===== PdcpSessionWorker @ 140029a10 =====

undefined8 PdcpSessionWorker(void)

{
  PdcpSessionTimerCallback();
  return 0;
}



===== PdcpSignalQueueWorker @ 140029a30 =====

undefined8
PdcpSignalQueueWorker(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  PdcHandleSignalQueue(param_1,param_2,param_3,param_4);
  return 0;
}



===== PdcpTransitionWorker @ 140029a50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
PdcpTransitionWorker(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  uint uVar1;
  byte bVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined8 local_res8;
  
  PdcAcquireLock();
  puVar3 = (undefined8 *)&PdcMonitorLock;
  PdcAcquireRwLockExclusive(0x140014d80);
  local_res8 = 0;
  uVar4 = (ulonglong)_DAT_140014df0;
  if (DAT_140015150 != _DAT_140014df0) {
    uVar4 = (ulonglong)(_DAT_140014df0 & 0xffffff01);
    PdcGroupEnable((uint *)0x5,uVar4);
    PdcpHandleSystemForegroundGroupStateChange();
    bVar2 = ~(byte)(_DAT_140014df0 >> 5) & 1;
    uVar1 = DAT_140015bc4;
    if (DAT_140015bc1 != bVar2) {
      DAT_140015bc1 = bVar2;
      uVar1 = DAT_140015bc4 | 1;
      if ((DAT_140015bc4 & 2) == 0) {
        DAT_140015bc4 = DAT_140015bc4 | 3;
        uVar4 = 1;
        ExQueueWorkItem(&DAT_140015bc8);
        uVar1 = DAT_140015bc4;
      }
    }
    DAT_140015bc4 = uVar1;
    uVar1 = _DAT_140014df0;
    uVar5 = _DAT_140014df0 ^ DAT_140015150;
    if ((PdcpAusterityModeClientPolicy != 0) && ((uVar5 & 0x20) != 0)) {
      if ((_DAT_140014df0 & 0x20) == 0) {
        PdcpClientPolicyEnableEaRule(PdcpAusterityModeClientPolicy);
      }
      else {
        PdcpClientPolicyDisableEaRule(PdcpAusterityModeClientPolicy);
      }
    }
    if (((PdcDSNetworkFeatureEnabled != 0) && (PdcpNetworkDSClientPolicy != 0)) &&
       ((uVar5 & 8) != 0)) {
      if ((uVar1 & 8) == 0) {
        PdcpClientPolicyEnableEaRule(PdcpNetworkDSClientPolicy);
      }
      else {
        PdcpClientPolicyDisableEaRule(PdcpNetworkDSClientPolicy);
      }
    }
    puVar3 = &local_res8;
    DAT_140015150 = _DAT_140014df0;
    _DAT_140015158 = KeQueryInterruptTimePrecise();
  }
  PdcpEngageDisengagePhasesInternal(puVar3,uVar4,param_3,param_4);
  PdcReleaseRwLockExclusive(0x140014d80);
  PdcReleaseLock();
  return 0;
}



===== PdcpPowerButtonSettingCallback @ 140029b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
PdcpPowerButtonSettingCallback
          (longlong *param_1,uint *param_2,undefined8 param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  uint *puVar4;
  uint *puVar5;
  undefined8 uVar6;
  
  iVar2 = (int)param_3;
  uVar6 = 0xc000000d;
  bVar3 = false;
  puVar5 = param_2;
  PdcAcquireLock();
  if ((*param_1 == 0x4e3edd9c7648efa3) && (param_1[1] == -0x7f9dc7d606af994b)) {
    puVar4 = &PdcPowerSettingValues;
  }
  else if ((*param_1 == 0x47ecad5096996bc0) && (param_1[1] == -0x1426b278be90c46e)) {
    puVar4 = &DAT_1400135cc;
  }
  else {
    if ((*param_1 != 0x459f6e455ca83367) || (param_1[1] != 0x36c9011d6b477ba2)) {
      if ((((*param_1 == 0x4c0723b199ff10e7) && (param_1[1] == -0x4bbe28f9cda32e57)) && (iVar2 == 4)
          ) && ((param_2 != (uint *)0x0 && (*param_2 < 8)))) {
        DAT_1400135e4 = *param_2;
        (*DAT_140015098)(&DAT_1400135e4,1);
        PdcReleaseLock();
        return 0;
      }
      goto LAB_140029c75;
    }
    puVar4 = (uint *)&DAT_1400135d8;
    if (DAT_140013689 == '\0') {
      DAT_140013689 = '\x01';
    }
    else {
      bVar3 = false;
      if (DAT_1400135d8 == 0) {
        bVar3 = true;
      }
    }
  }
  if (((iVar2 == 4) && (param_2 != (uint *)0x0)) &&
     ((uVar1 = *param_2, uVar1 < 9 && (puVar5 = (uint *)0x14d, (0x14dU >> (uVar1 & 0x1f) & 1) != 0))
     )) {
    puVar4[1] = 0;
    puVar4[2] = 0;
    uVar6 = 0;
    *puVar4 = uVar1;
  }
  else {
    bVar3 = false;
  }
LAB_140029c75:
  PdcReleaseLock();
  if (bVar3) {
    PdcAcquireRwLockExclusive(0x140032b28);
    DAT_140013684 = DAT_140013684 | 4;
    PdcpReplayLidClose(1,puVar5,param_3,param_4);
    PdcReleaseRwLockExclusive(0x140032b28);
  }
  return uVar6;
}



===== PdcpSetButtonAction @ 140029d1c =====

void PdcpSetButtonAction(undefined4 *param_1,undefined4 param_2)

{
  *(undefined8 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}



===== PdcpConnectToPolicyDevice @ 140029d2c =====

void PdcpConnectToPolicyDevice(int param_1,undefined8 param_2,char param_3)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 local_res20;
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [24];
  code *local_98;
  undefined8 *local_90;
  undefined8 *local_88;
  longlong local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res20 = 0;
  local_54 = 0;
  lVar6 = 0;
  local_3c = 0;
  lVar5 = 0;
  puVar7 = (undefined8 *)0x0;
  puVar8 = (undefined8 *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  if (param_3 != '\0') {
    return;
  }
  puVar12 = &local_68;
  local_90 = (undefined8 *)CONCAT44(local_90._4_4_,0x10);
  local_58 = 0x30;
  local_50 = 0;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  local_98 = (code *)CONCAT44(local_98._4_4_,3);
  local_48 = param_2;
  uVar4 = ZwOpenFile(&local_res20,0x100003,&local_58);
  if ((int)uVar4 < 0) {
    PdcPrint(1,"PdcConnectToPolicyDevice: Device open failed %x\n",(ulonglong)uVar4,puVar12);
    return;
  }
  local_98 = (code *)&local_78;
  local_90 = (undefined8 *)0x0;
  uVar13 = 0;
  local_78 = 0;
  uVar4 = ObReferenceObjectByHandle(local_res20,0x100003,0);
  lVar3 = local_78;
  ZwClose(local_res20);
  if ((int)uVar4 < 0) {
    pcVar9 = "PdcConnectToPolicyDevice: ObReferenceObjectByHandle failed %x\n";
    uVar14 = uVar13;
LAB_140029e33:
    puVar10 = auStack_b8;
    PdcPrint(1,pcVar9,(ulonglong)uVar4,uVar14);
  }
  else {
    lVar5 = IoGetRelatedDeviceObject(lVar3);
    ObfReferenceObject(lVar5);
    lVar6 = IoAllocateIrp(*(char *)(lVar5 + 0x4c) + '\x01',0);
    puVar10 = auStack_b8;
    if (lVar6 == 0) goto LAB_140029fe9;
    local_70 = *(longlong *)(lVar6 + 0xb8);
    if (param_1 != 0) {
      PdcInternalError();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar11 = 0x74775350;
    puVar7 = (undefined8 *)ExAllocatePool2(0x40,0x40);
    if (puVar7 == (undefined8 *)0x0) {
      pcVar9 = "PdcConnectToPolicyDevice: ExAllocatePool2 for SwitchDevice failed\n";
    }
    else {
      uVar11 = 0x74775350;
      puVar8 = (undefined8 *)ExAllocatePool2(0x100);
      uVar14 = PdcDriverObject;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = puVar7;
        local_88 = puVar8 + 1;
        *(undefined1 *)((longlong)puVar7 + 0x21) = 1;
        puVar7[5] = lVar6;
        local_98 = PdcSystemButtonNotifyHandler;
        local_90 = puVar8;
        uVar4 = IoRegisterPlugPlayNotification(3,0,lVar3);
        if (-1 < (int)uVar4) {
          PdcAcquireRwLockExclusive(0x140032b28);
          puVar10 = auStack_b8;
          puVar8 = &PdcSwitches;
          if ((undefined8 *)*DAT_140032b60 != &PdcSwitches) {
            puVar8 = (undefined8 *)0x3;
            pcVar2 = (code *)swi(0x29);
            DAT_140032b60 = (undefined8 *)(*pcVar2)();
            puVar10 = auStack_b0;
          }
          *puVar7 = puVar8;
          puVar7[1] = DAT_140032b60;
          *DAT_140032b60 = puVar7;
          *(undefined8 *)(puVar10 + -8) = 0x140029f91;
          DAT_140032b60 = puVar7;
          PdcReleaseRwLockExclusive(0x140032b28);
          *(code **)(local_70 + -0x30) = PdcSystemButtonHandler;
          *(longlong *)(local_70 + -0x40) = lVar5;
          *(undefined8 **)(local_70 + -0x38) = puVar7;
          *(longlong *)(lVar6 + 0xb8) = *(longlong *)(lVar6 + 0xb8) + -0x48;
          lVar1 = *(longlong *)(lVar6 + 0xb8);
          *(char *)(lVar6 + 0x43) = *(char *)(lVar6 + 0x43) + -1;
          *(undefined4 *)(lVar6 + 0x30) = 0xc000009d;
          *(undefined4 *)(lVar1 + -0x30) = 0;
          *(undefined4 *)(lVar1 + -0x38) = 0;
          *(undefined4 *)(lVar1 + -0x40) = 0;
          *(undefined1 *)(lVar1 + -0x48) = 0xf;
          *(undefined8 *)(puVar10 + -8) = 0x140029fdf;
          PdcCompletePolicyIrp(lVar5,lVar6);
          lVar6 = 0;
          lVar5 = 0;
          puVar7 = (undefined8 *)0x0;
          puVar8 = (undefined8 *)0x0;
          goto LAB_140029fe9;
        }
        pcVar9 = 
        "PdcConnectToPolicyDevice: IoRegisterPlugPlayNotification for SystemButton failed with status %x\n"
        ;
        goto LAB_140029e33;
      }
      pcVar9 = "PdcConnectToPolicyDevice: ExAllocatePool2 for NotifyContext failed\n";
    }
    puVar10 = auStack_b8;
    PdcPrint(1,pcVar9,uVar11,uVar13);
  }
LAB_140029fe9:
  if (lVar3 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x140029ff8;
    ObfDereferenceObject(lVar3);
  }
  if (lVar6 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x14002a00c;
    IoFreeIrp(lVar6);
  }
  if (lVar5 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x14002a020;
    ObfDereferenceObject(lVar5);
  }
  if (puVar7 != (undefined8 *)0x0) {
    if (puVar7[7] != 0) {
      *(undefined8 *)(puVar10 + -8) = 0x14002a03c;
      RtlFreeUnicodeString(puVar7 + 6);
    }
    *(undefined8 *)(puVar10 + -8) = 0x14002a050;
    ExFreePoolWithTag(puVar7,0x74775350);
  }
  if (puVar8 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x14002a069;
    ExFreePoolWithTag(puVar8,0x74775350);
  }
  return;
}



===== PdcpNotifyPolicyDevice @ 14002a0a0 =====

undefined8 PdcpNotifyPolicyDevice(longlong param_1,int param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4005;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  PdcpConnectToPolicyDevice(param_2,*(undefined8 *)(param_1 + 0x28),lVar1 == 0);
  return 0;
}



===== PdcDiagTracePhasesAccounting @ 14002a0e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcDiagTracePhasesAccounting(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined1 auStackY_128 [32];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8 [4];
  undefined8 *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_98 [2];
  undefined8 local_90 [15];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar5 = 0;
  piVar3 = local_98 + 1;
  bVar2 = true;
  puVar6 = param_1;
  do {
    *piVar3 = 0;
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    piVar3[-1] = (int)uVar5;
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulonglong)uVar4;
    *(undefined8 *)(piVar3 + 1) = uVar1;
    piVar3 = piVar3 + 4;
  } while (uVar4 < 8);
  if ((DAT_140015c02 & 4) != 0) {
    McTemplateU0qNR0x_EtwWriteTransfer(param_1,param_2,piVar3,uVar5,local_98,(char)param_2);
  }
  if (5 < DAT_140031288) {
    if (((_DAT_140031298 & 0x400000000000) == 0) ||
       ((DAT_1400312a0 & 0x400000000000) != DAT_1400312a0)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_bc = 0;
      local_c8 = &local_f8;
      local_ac = 0;
      local_9c = 0;
      local_a8 = &local_f0;
      local_c0 = 8;
      local_b0 = 0x48;
      local_f0 = 0x1000000;
      local_a0 = 8;
      local_f8 = param_2;
      local_b8 = param_1;
      _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000f219,piVar3,uVar5,5,local_e8);
    }
  }
  return;
}



===== PdcEtwCallback @ 14002a230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcEtwCallback(undefined8 *param_1,undefined **param_2)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  uint *puVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 *puVar6;
  
  if ((int)param_2 == 2) {
    PdcAcquireLock();
    PdcPhasesRundown();
    PdcNotificationClientsRundown();
    uVar1 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
    lVar4 = 8;
    if ((int)uVar1 == 0) {
      puVar2 = &DAT_140013c90;
      do {
        uVar5 = *(uint *)(puVar2 + -1);
        param_1 = (undefined8 *)(ulonglong)uVar5;
        if (uVar5 == 6) {
          for (puVar6 = (undefined8 *)*puVar2; puVar6 != puVar2; puVar6 = (undefined8 *)*puVar6) {
            if ((Microsoft_Windows_PDCEnableBits & 0x40) != 0) {
              McTemplateU0pxqq_EtwWriteTransfer
                        (param_1,param_2,puVar2 + -6,puVar6[3],(char)*(undefined4 *)(puVar6 + 4),6);
            }
          }
        }
        else if ((Microsoft_Windows_PDCEnableBits & 0x40) != 0) {
          McTemplateU0pxqq_EtwWriteTransfer
                    (param_1,param_2,puVar2 + -6,*puVar2,(char)*(undefined4 *)(puVar2 + 1),
                     (char)uVar5);
        }
        puVar2 = puVar2 + 0xe;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    else {
      uVar5 = 0;
      puVar3 = &DAT_140013764;
      do {
        if ((Microsoft_Windows_PDCEnableBits & 0x40) != 0) {
          McTemplateU0pxqq_EtwWriteTransfer
                    (param_1,param_2,puVar3 + -0xf,(ulonglong)*puVar3,(char)puVar3[-3],(char)uVar5);
        }
        uVar5 = uVar5 + 1;
        puVar3 = puVar3 + 0x1c;
      } while (uVar5 < 8);
    }
    PdcActivatorsRundown(param_1,(longlong)param_2);
    for (puVar2 = PdcTaskClients; (undefined8 **)puVar2 != &PdcTaskClients;
        puVar2 = (undefined8 *)*puVar2) {
      uVar5 = *(uint *)(puVar2 + 5);
      if (uVar5 - 1 < 0x7c) {
        param_1 = (undefined8 *)((ulonglong)uVar5 * 3);
        param_2 = &PTR_u_Invalid_client_140031f70 + (ulonglong)uVar5 * 3;
      }
      else {
        param_2 = (undefined **)&DAT_00000010;
      }
      if (DAT_140015c01 < '\0') {
        param_1 = (undefined8 *)*param_2;
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (*(short *)((longlong)param_1 + lVar4 * 2) != 0);
        McTemplateU0pqqqqzr4_EtwWriteTransfer
                  (param_1,param_2,puVar2,uVar5,(char)*(undefined4 *)((longlong)puVar2 + 0x2c),
                   (char)*(undefined4 *)(puVar2 + 0x6b),(int)lVar4,param_1);
      }
    }
    for (puVar2 = PdcSignalClients; (undefined8 **)puVar2 != &PdcSignalClients;
        puVar2 = (undefined8 *)*puVar2) {
      param_2 = (undefined **)CONCAT71((int7)((ulonglong)param_2 >> 8),1);
      param_1 = puVar2;
      (**(code **)(&DAT_140012120 + (longlong)*(int *)(puVar2 + 0x1b) * 0x10))();
    }
    uVar5 = 0;
    uVar1 = 0;
    do {
      if ((DAT_140015c02 & 4) != 0) {
        param_1 = *(undefined8 **)((longlong)&PTR_u_Invalid_client_140031f70 + uVar1);
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (*(short *)((longlong)param_1 + lVar4 * 2) != 0);
        McTemplateU0qqqzr2_EtwWriteTransfer
                  (param_1,param_2,(ulonglong)uVar5,
                   *(undefined4 *)((longlong)&PdcClientInfo + uVar1),(int)lVar4,param_1);
      }
      uVar5 = uVar5 + 1;
      uVar1 = uVar1 + 0x18;
    } while (uVar1 < 3000);
    uVar1 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar1 == 0) {
      PdcPpmLogScenarioList(param_1,param_2);
    }
    PdcClientPolicyRundown();
    PdcReleaseLock();
    uVar1 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar1 != 0) {
      PdcPpmLogScenarioList(param_1,param_2);
    }
  }
  return;
}



===== PdcpStatsCreateTaskClient @ 14002a454 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcpStatsCreateTaskClient
               (longlong param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4)

{
  uint uVar1;
  short *psVar2;
  short sVar3;
  int iVar4;
  short *psVar5;
  undefined8 *puVar6;
  short sVar7;
  uint *puVar8;
  undefined8 *puVar9;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  longlong *local_70;
  longlong local_58;
  undefined8 local_50;
  undefined8 local_48;
  short *psStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  uVar1 = *(uint *)(param_1 + 0x28);
  local_50 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_58 = 0;
  if (uVar1 - 1 < 0x7c) {
    puVar8 = &PdcClientInfo + (ulonglong)uVar1 * 6;
  }
  else {
    puVar8 = (uint *)0x0;
  }
  psVar2 = *(short **)(puVar8 + 4);
  local_48 = 0;
  psStack_40 = (short *)0x0;
  if (psVar2 != (short *)0x0) {
    param_4 = (undefined8 *)0x7fff;
    param_3 = (undefined8 *)0x7fff;
    psVar5 = psVar2;
    do {
      if (*psVar5 == 0) break;
      psVar5 = psVar5 + 1;
      param_3 = (undefined8 *)((longlong)param_3 + -1);
    } while (param_3 != (undefined8 *)0x0);
    if (param_3 != (undefined8 *)0x0) {
      sVar3 = (short)(0x7fff - (longlong)param_3) * 2;
      sVar7 = sVar3 + 2;
      param_4 = (undefined8 *)
                CONCAT62((int6)((ulonglong)(0x7fff - (longlong)param_3) >> 0x10),sVar7);
      local_48 = (ulonglong)CONCAT22(sVar7,sVar3);
      psStack_40 = psVar2;
    }
    if (-1 < (int)-(uint)(param_3 != (undefined8 *)0x0)) goto LAB_14002a5ff;
  }
  puVar9 = (undefined8 *)0x0;
  puVar6 = DAT_140031968;
  if ((*puVar8 & 0x8000) == 0) {
    for (; (undefined8 **)puVar6 != &DAT_140031968; puVar6 = (undefined8 *)*puVar6) {
      if (*(char *)((longlong)puVar6 + 0x1c) == '\x04') {
        puVar9 = puVar6 + 3;
        break;
      }
    }
    local_38._4_4_ = 4;
  }
  else {
    for (; (undefined8 **)puVar6 != &DAT_140031968; puVar6 = (undefined8 *)*puVar6) {
      if (*(char *)((longlong)puVar6 + 0x1c) == '\x05') {
        puVar9 = puVar6 + 3;
        break;
      }
    }
    local_38._4_4_ = 5;
  }
  local_38 = CONCAT44(local_38._4_4_,0xaaddaadd);
  uStack_30 = (ulonglong)uVar1;
  if (DAT_140012858 != (code *)0x0) {
    local_70 = &local_58;
    param_4 = &local_48;
    local_78 = 4;
    param_3 = &local_38;
    iVar4 = (*DAT_140012858)(PdcpTaskClientLibraryHandle,puVar9);
    if (((-1 < iVar4) && (DAT_140012838 != (code *)0x0)) &&
       (iVar4 = (*DAT_140012838)(local_58,&local_50), -1 < iVar4)) {
      local_58 = 0;
      *(undefined8 *)(param_1 + 0x360) = local_50;
      local_50 = 0;
    }
  }
  if ((local_58 != 0) && (DAT_140012870 != (code *)0x0)) {
    (*DAT_140012870)(local_58);
  }
LAB_14002a5ff:
  PdcpLogTaskClientAction("Create TaskClient",param_1,param_3,param_4);
  return;
}



===== PdcpStatsMarkTaskClientActive @ 14002a63c =====

void PdcpStatsMarkTaskClientActive
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(longlong *)(param_1 + 0x360) != 0) {
    SleepstudyHelperBlockerActiveReference();
  }
  PdcpLogTaskClientAction("TaskClient Active",param_1,param_3,param_4);
  return;
}



===== PdcpStatsMarkTaskClientInactive @ 14002a674 =====

void PdcpStatsMarkTaskClientInactive
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(longlong *)(param_1 + 0x360) != 0) {
    SleepstudyHelperBlockerActiveDereference();
  }
  PdcpLogTaskClientAction("TaskClient Inactive",param_1,param_3,param_4);
  return;
}



===== PdcTriageCaptureContext @ 14002a6ac =====

void PdcTriageCaptureContext(longlong param_1,undefined8 *param_2,char param_3)

{
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  if (*(char *)(param_1 + 0x18) == '\0') {
    LOCK();
    UNLOCK();
    param_2[1] = *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x6e0);
  }
  else {
    PdcTriageCaptureUserContext(*(longlong *)(param_1 + 0x20),param_2,param_3);
  }
  return;
}



===== PdcTriageCaptureUserContext @ 14002a6f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcTriageCaptureUserContext(longlong param_1,undefined8 *param_2,char param_3)

{
  ulonglong *puVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStack_98 [32];
  undefined1 local_78;
  undefined8 local_70;
  undefined8 local_68;
  ulonglong *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_70 = 0;
  local_68 = 0;
  bVar2 = false;
  iVar3 = PsLookupProcessByProcessId(*(undefined8 *)(param_1 + 0x28),&local_70);
  if (-1 < iVar3) {
    *param_2 = local_70;
    iVar3 = PsAcquireProcessExitSynchronization();
    if (-1 < iVar3) {
      KeStackAttachProcess(local_70,&local_58);
      bVar2 = true;
      local_78 = 1;
      uVar4 = Feature_14FBugcheckMinidumpDiagnostics__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 != 0) {
        (*DAT_140015100)(local_70,PdcTriageThreadEnumCallback,param_2);
      }
      puVar1 = *(ulonglong **)(param_1 + 0x30);
      if (puVar1 != (ulonglong *)0x0) {
        if (((ulonglong)puVar1 & 3) != 0) {
          local_60 = puVar1;
                    /* WARNING: Subroutine does not return */
          ExRaiseDatatypeMisalignment();
        }
        local_60 = (ulonglong *)*puVar1;
        if ((((int)local_60 == 0x74434450) && ((int)((ulonglong)local_60 >> 0x20) != 0)) &&
           (iVar3 = PsLookupThreadByThreadId((ulonglong)local_60 >> 0x20,&local_68), -1 < iVar3)) {
          param_2[1] = local_68;
        }
      }
    }
  }
  if ((param_3 != '\0') && (bVar2)) {
    KeUnstackDetachProcess(&local_58);
    PsReleaseProcessExitSynchronization(local_70);
  }
  return;
}



===== PdcTriageThreadEnumCallback @ 14002a890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PdcTriageThreadEnumCallback(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  uint uVar5;
  char local_res18 [8];
  char local_res20 [8];
  longlong local_38;
  longlong local_30;
  
  local_30 = 0;
  local_38 = 0;
  local_res18[0] = '\0';
  local_res20[0] = '\0';
  iVar1 = (*DAT_1400150f8)(param_2,local_res18,0,&local_30);
  if ((iVar1 != 0) && (local_res18[0] == '\0')) {
    plVar3 = (longlong *)0x0;
    uVar5 = 0;
    plVar4 = (longlong *)(param_3 + 0x10);
    lVar2 = 0x7fffffffffffffff;
    do {
      if (((*plVar4 == 0) || (iVar1 = (*DAT_1400150f8)(*plVar4,local_res20,0,&local_38), iVar1 == 0)
          ) || (local_res20[0] != '\0')) {
        lVar2 = 0;
        plVar3 = plVar4;
        break;
      }
      if (local_38 < lVar2) {
        lVar2 = local_38;
        plVar3 = plVar4;
      }
      uVar5 = uVar5 + 1;
      plVar4 = plVar4 + 1;
    } while (uVar5 < 3);
    if (lVar2 < local_30) {
      ObfReferenceObject(param_2);
      if (*plVar3 != 0) {
        ObfDereferenceObject();
      }
      *plVar3 = param_2;
    }
  }
  return 0;
}



===== PdcPpmLogScenarioList @ 14002a98c =====

void PdcPpmLogScenarioList(undefined8 param_1,undefined **param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  undefined *puVar8;
  ulonglong in_stack_ffffffffffffffb8;
  
  for (ppuVar7 = (undefined **)PdcPpmProfileList; ppuVar7 != &PdcPpmProfileList;
      ppuVar7 = (undefined **)*ppuVar7) {
    for (ppuVar6 = (undefined **)ppuVar7[9]; ppuVar6 != ppuVar7 + 9;
        ppuVar6 = (undefined **)*ppuVar6) {
      if ((DAT_140015c02 & 2) != 0) {
        puVar8 = ppuVar6[2];
        param_2 = ppuVar7 + 2;
        lVar1 = -1;
        do {
          lVar1 = lVar1 + 1;
        } while (*(short *)(puVar8 + lVar1 * 2) != 0);
        McTemplateU0pjquqzr4j_EtwWriteTransfer
                  (puVar8,param_2,ppuVar6,ppuVar6 + 3,in_stack_ffffffffffffffb8,
                   *(undefined1 *)(ppuVar6 + 6),(int)lVar1,puVar8,param_2);
      }
      puVar8 = ppuVar6[0x1a];
      uVar2 = PdcConvertQpcDuration((ulonglong)ppuVar6[0x1b]);
      uVar3 = PdcConvertQpcDuration((ulonglong)ppuVar6[0x1c]);
      puVar5 = ppuVar6[0x1d];
      uVar4 = PdcConvertQpcDuration((ulonglong)puVar5);
      if ((DAT_140015c02 & 0x20) != 0) {
        McTemplateU0pxxxx_EtwWriteTransfer
                  (puVar5,param_2,ppuVar6,puVar8,(char)uVar2,(char)uVar3,(char)uVar4);
        in_stack_ffffffffffffffb8 = uVar2;
      }
    }
  }
  return;
}



===== PdcPpmProfileClientFree @ 14002aa90 =====

ulonglong PdcPpmProfileClientFree(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  plVar6 = param_1;
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if (*(int *)((longlong)param_1 + 0x3c) == 0) {
    uVar4 = 0;
  }
  else {
    plVar6 = (longlong *)((longlong)param_1 + 0x2c);
    uVar4 = PdcpPpmUpdateProfileEvents(plVar6,'\0');
  }
  uVar5 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    plVar6 = (longlong *)&PdcPpmProfileLock;
    PdcAcquireRwLockExclusive(0x140012f60);
  }
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) != param_1) ||
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    uVar5 = (*pcVar3)();
    return uVar5;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  uVar5 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    plVar6 = (longlong *)&PdcPpmProfileLock;
    PdcReleaseRwLockExclusive(0x140012f60);
  }
  if ((DAT_140015c02 & 2) != 0) {
    McTemplateU0pqq_EtwWriteTransfer
              (plVar6,&PDC_PPM_PROFILE_CLIENT_DEREGISTRATION,param_1,(int)param_1[5],(char)uVar4);
  }
  ExFreePoolWithTag(param_1,0);
  return (ulonglong)uVar4;
}



===== PdcPpmProfileClientInitialize @ 14002ab48 =====

undefined4
PdcPpmProfileClientInitialize(undefined **param_1,undefined **param_2,undefined8 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 *_Dst;
  ulonglong uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  longlong lVar8;
  undefined *puVar9;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [56];
  
  uVar3 = (ulonglong)param_1 & 0xffffffff;
  ppuVar4 = param_1;
  ppuVar5 = param_2;
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  puVar7 = auStack_68;
  uVar6 = 0;
  iVar2 = (int)param_1;
  *param_3 = 0;
  puVar9 = (undefined *)0x0;
  lVar8 = 0;
  _Dst = (undefined8 *)0x0;
  if (iVar2 - 1U < 0x7c) {
    ppuVar5 = (undefined **)(uVar3 * 3);
    if ((&PdcClientInfo + uVar3 * 6 != (uint *)0x0) && (((&PdcClientInfo)[uVar3 * 6] & 0x40) != 0))
    {
      ppuVar5 = &PdcPpmProfileList;
      for (ppuVar4 = (undefined **)PdcPpmProfileList; ppuVar4 != &PdcPpmProfileList;
          ppuVar4 = (undefined **)*ppuVar4) {
        if ((ppuVar4[2] == *param_2) && (ppuVar4[3] == param_2[1])) {
          if (ppuVar4 != (undefined **)0x0) {
            ppuVar5 = (undefined **)0x360;
            ppuVar4 = (undefined **)0x100;
            _Dst = (undefined8 *)ExAllocatePool2(0x100,0x360,0x73636450);
            puVar7 = auStack_68;
            if (_Dst == (undefined8 *)0x0) {
              uVar6 = 0xc0000017;
            }
            else {
              ppuVar5 = (undefined **)0x0;
              memset(_Dst,0,0x360);
              *(undefined4 *)(_Dst + 2) = 6;
              lVar8 = -1;
              *(int *)(_Dst + 5) = iVar2;
              puVar9 = param_2[1];
              *(undefined **)((longlong)_Dst + 0x2c) = *param_2;
              *(undefined **)((longlong)_Dst + 0x34) = puVar9;
              puVar9 = (&PTR_u_Invalid_client_140031f70)[uVar3 * 3];
              do {
                lVar8 = lVar8 + 1;
              } while (*(short *)(puVar9 + lVar8 * 2) != 0);
              uVar3 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
              if ((int)uVar3 != 0) {
                PdcAcquireRwLockExclusive(0x140012f60);
              }
              puVar7 = auStack_68;
              ppuVar4 = &PdcPpmProfileClientList;
              if (*(undefined ***)PTR_PdcPpmProfileClientList_1400310a0 != &PdcPpmProfileClientList)
              {
                ppuVar4 = (undefined **)0x3;
                pcVar1 = (code *)swi(0x29);
                PTR_PdcPpmProfileClientList_1400310a0 = (undefined *)(*pcVar1)();
                puVar7 = auStack_60;
              }
              *_Dst = ppuVar4;
              _Dst[1] = PTR_PdcPpmProfileClientList_1400310a0;
              *(undefined8 **)PTR_PdcPpmProfileClientList_1400310a0 = _Dst;
              *(undefined8 *)(puVar7 + -8) = 0x14002ac91;
              PTR_PdcPpmProfileClientList_1400310a0 = (undefined *)_Dst;
              uVar3 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
              if ((int)uVar3 != 0) {
                ppuVar4 = (undefined **)&PdcPpmProfileLock;
                *(undefined8 *)(puVar7 + -8) = 0x14002aca1;
                PdcReleaseRwLockExclusive(0x140012f60);
              }
              *param_3 = _Dst;
            }
            goto LAB_14002acac;
          }
          break;
        }
      }
      uVar6 = 0xc0000225;
      puVar7 = auStack_68;
      goto LAB_14002acac;
    }
  }
  uVar6 = 0xc000000d;
LAB_14002acac:
  if ((DAT_140015c02 & 2) != 0) {
    *(undefined **)(puVar7 + 0x38) = puVar9;
    *(int *)(puVar7 + 0x30) = (int)lVar8;
    *(undefined4 *)(puVar7 + 0x28) = uVar6;
    *(undefined ***)(puVar7 + 0x20) = param_2;
    *(undefined8 *)(puVar7 + -8) = 0x14002acd2;
    McTemplateU0pqjqqzr4_EtwWriteTransfer
              (ppuVar4,ppuVar5,_Dst,iVar2,*(undefined8 *)(puVar7 + 0x20),puVar7[0x28],
               *(int *)(puVar7 + 0x30),*(undefined8 *)(puVar7 + 0x38));
  }
  return uVar6;
}



===== PdcPpmProfileClientReceive @ 14002acfc =====

ulonglong PdcPpmProfileClientReceive(longlong param_1,undefined8 *param_2,longlong param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  longlong *plVar7;
  undefined *puVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  lVar9 = 6;
  if ((*(int *)(param_1 + 0x10) == 6) && (*(int *)(param_2 + 5) == 9)) {
    iVar1 = *(int *)(param_1 + 0x3c);
    plVar7 = (longlong *)(param_1 + 0x2c);
    iVar4 = 0;
    if (*(char *)(param_2 + 7) == '\0') {
      if (iVar1 == 0) goto LAB_14002ae37;
      if (((iVar1 != 1) || (iVar4 = PdcpPpmUpdateProfileEvents(plVar7,'\0'), -1 < iVar4)) &&
         (*(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1, (DAT_140015c02 & 2) != 0)) {
        uVar11 = 0;
        puVar8 = &PDC_PPM_PROFILE_CLIENT_DEREFERENCE;
        goto LAB_14002adad;
      }
    }
    else {
      if (iVar1 == -1) {
        return 0xc0000095;
      }
      if (((iVar1 != 0) || (iVar4 = PdcpPpmUpdateProfileEvents(plVar7,'\x01'), -1 < iVar4)) &&
         (*(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1, (DAT_140015c02 & 2) != 0)) {
        uVar11 = 1;
        puVar8 = &PDC_PPM_PROFILE_CLIENT_REFERENCE;
LAB_14002adad:
        param_3 = param_1;
        McTemplateU0pt_EtwWriteTransfer(plVar7,puVar8,param_1,uVar11);
      }
    }
    puVar3 = (undefined8 *)(param_1 + 0x40);
    do {
      puVar10 = param_2;
      puVar5 = puVar3;
      uVar2 = puVar10[1];
      *puVar5 = *puVar10;
      puVar5[1] = uVar2;
      uVar2 = puVar10[3];
      puVar5[2] = puVar10[2];
      puVar5[3] = uVar2;
      uVar2 = puVar10[5];
      puVar5[4] = puVar10[4];
      puVar5[5] = uVar2;
      uVar2 = puVar10[7];
      puVar5[6] = puVar10[6];
      puVar5[7] = uVar2;
      uVar2 = puVar10[9];
      puVar5[8] = puVar10[8];
      puVar5[9] = uVar2;
      uVar2 = puVar10[0xb];
      puVar5[10] = puVar10[10];
      puVar5[0xb] = uVar2;
      uVar2 = puVar10[0xd];
      puVar5[0xc] = puVar10[0xc];
      puVar5[0xd] = uVar2;
      uVar2 = puVar10[0xf];
      puVar5[0xe] = puVar10[0xe];
      puVar5[0xf] = uVar2;
      lVar9 = lVar9 + -1;
      puVar3 = puVar5 + 0x10;
      param_2 = puVar10 + 0x10;
    } while (lVar9 != 0);
    uVar2 = puVar10[0x11];
    puVar5[0x10] = puVar10[0x10];
    puVar5[0x11] = uVar2;
    uVar2 = puVar10[0x13];
    puVar5[0x12] = puVar10[0x12];
    puVar5[0x13] = uVar2;
    *(int *)(param_1 + 0x78) = iVar4;
    if (*(char *)(param_1 + 0x18) == '\0') {
      uVar6 = 0xc00000bb;
    }
    else {
      uVar6 = PdcSendUserMessage(*(longlong *)(param_1 + 0x20),(undefined8 *)(param_1 + 0x40),
                                 CONCAT71((int7)((ulonglong)param_3 >> 8),1));
    }
  }
  else {
LAB_14002ae37:
    uVar6 = 0xc000000d;
  }
  return uVar6;
}



===== PdcpPpmOpenRegistryKey @ 14002ae58 =====

void PdcpPpmOpenRegistryKey
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = 0x240;
  local_30 = param_4;
  local_28 = param_1;
  ZwOpenKey(param_5,8,&local_38);
  return;
}



===== PdcpPpmProcessScenarioStateChange @ 14002aeb0 =====

void PdcpPpmProcessScenarioStateChange(undefined *param_1,undefined8 param_2)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  uVar6 = param_2;
  Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
  iVar3 = *(int *)(param_1 + 0x30);
  iVar7 = 1;
  lVar2 = *(longlong *)(param_1 + 0x28);
  iVar8 = (int)param_2;
  if (iVar3 != iVar8) {
    uVar5 = 0;
    lVar4 = KeQueryPerformanceCounter();
    if (iVar3 == 0) {
      uVar5 = lVar4 - *(longlong *)(param_1 + 200);
      *(ulonglong *)(param_1 + 0xe8) = *(longlong *)(param_1 + 0xe8) + uVar5;
      *(longlong *)(param_1 + 0xd0) = *(longlong *)(param_1 + 0xd0) + 1;
      if (*(ulonglong *)(param_1 + 0xd8) < uVar5) {
        *(ulonglong *)(param_1 + 0xd8) = uVar5;
      }
      if (uVar5 < *(ulonglong *)(param_1 + 0xe0)) {
        *(ulonglong *)(param_1 + 0xe0) = uVar5;
      }
    }
    *(longlong *)(param_1 + 200) = lVar4;
    *(int *)(param_1 + 0x30) = iVar8;
    if ((DAT_140015c02 & 2) != 0) {
      McTemplateU0puu_EtwWriteTransfer(uVar5,uVar6,param_1,(char)iVar3,(char)param_2);
    }
    if (iVar8 == 0) {
      LOCK();
      piVar1 = (int *)(lVar2 + 0x40);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      iVar3 = iVar3 + 1;
    }
    else {
      LOCK();
      piVar1 = (int *)(lVar2 + 0x40);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 == 1) {
      LOCK();
      iVar3 = PdcPpmEvaulationRequestCount + 1;
      UNLOCK();
      bVar9 = PdcPpmEvaulationRequestCount == 0;
      PdcPpmEvaulationRequestCount = iVar3;
      if (bVar9) {
        if (param_1 == &PdcPpmMediaBufferingScenario) {
          iVar3 = KeQueryPriorityThread(SystemReserved1[0xf]);
          iVar7 = iVar3 + 1;
          if (0x1e < iVar3) {
            iVar7 = iVar3;
          }
          iVar7 = iVar7 + 0x20;
        }
        ExQueueWorkItem(&PdcPpmProfileEvaluationWorkItem,iVar7);
      }
    }
  }
  return;
}



===== PdcpPpmProfileClientWorker @ 14002aff0 =====

void PdcpPpmProfileClientWorker(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  char cVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
  cVar3 = *(char *)(param_1 + 0x38);
  puVar4 = *(undefined8 **)(param_1 + 0x48);
  do {
    if (puVar4 == (undefined8 *)(param_1 + 0x48)) {
      KeSetEvent(param_1 + 0x58,0,0);
      return;
    }
    if (puVar4 != (undefined8 *)&PdcPpmMediaBufferingScenario) {
      plVar1 = puVar4 + 0xb;
      if (cVar3 == '\0') {
        if (*plVar1 != 0) {
          KeWaitForSingleObject(puVar4 + 0x12,0,0,0,0);
          LOCK();
          lVar2 = *plVar1;
          *plVar1 = 0;
          UNLOCK();
          puVar4[0x11] = lVar2;
          ExQueueWorkItem(puVar4 + 0x15,1);
          LOCK();
          UNLOCK();
          uVar7 = PdcPpmLogCount & 0x3f;
          uVar8 = (ulonglong)uVar7;
          PdcPpmLogCount = PdcPpmLogCount + 1;
          *(undefined4 *)(&DAT_140012f90 + uVar8 * 0x18) = 1;
          *(uint *)(&PdcPpmLogBuffer + uVar8 * 0x18) = uVar7;
          *(undefined8 **)(&DAT_140012f88 + uVar8 * 0x18) = puVar4;
          if (*(int *)(puVar4 + 6) == 0) {
            PdcpPpmProcessScenarioStateChange((undefined *)puVar4,3);
            LOCK();
            UNLOCK();
            uVar8 = (ulonglong)(PdcPpmLogCount & 0x3f);
            PdcPpmLogCount = PdcPpmLogCount + 1;
            *(undefined4 *)(&DAT_140012f90 + uVar8 * 0x18) = 4;
            goto LAB_14002b174;
          }
        }
      }
      else {
        uVar6 = puVar4[0xc];
        uVar5 = EaCreateAggregatedEvent
                          (uVar6,0,PdcpPpmScenarioStart,PdcpPpmScenarioStop,PdcpPpmScenarioCleanup,0
                           ,puVar4,0,plVar1);
        if ((DAT_140015c02 & 0x20) != 0) {
          McTemplateU0pt_EtwWriteTransfer(uVar6,&PDC_SPM_SCENARIO_CREATE,puVar4,uVar5);
        }
        LOCK();
        UNLOCK();
        uVar8 = (ulonglong)(PdcPpmLogCount & 0x3f);
        PdcPpmLogCount = PdcPpmLogCount + 1;
        *(undefined4 *)(&DAT_140012f90 + uVar8 * 0x18) = 0;
LAB_14002b174:
        *(undefined8 **)(&DAT_140012f88 + uVar8 * 0x18) = puVar4;
        *(int *)(&PdcPpmLogBuffer + uVar8 * 0x18) = (int)uVar8;
      }
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== PdcpPpmProfileDisable @ 14002b1c4 =====

void PdcpPpmProfileDisable(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  for (puVar2 = *(undefined8 **)(param_1 + 0x48); puVar2 != (undefined8 *)(param_1 + 0x48);
      puVar2 = (undefined8 *)*puVar2) {
    puVar1 = puVar2 + 7;
    PdcAcquireRwLockExclusive((longlong)puVar1);
    if ((DAT_140015c02 & 0x20) != 0) {
      McTemplateU0pt_EtwWriteTransfer(puVar1,&PDC_SPM_SCENARIO_DELETE,puVar2,0);
    }
    LOCK();
    UNLOCK();
    uVar3 = PdcPpmLogCount & 0x3f;
    uVar4 = (ulonglong)uVar3;
    PdcPpmLogCount = PdcPpmLogCount + 1;
    *(undefined4 *)(&DAT_140012f90 + uVar4 * 0x18) = 1;
    *(uint *)(&PdcPpmLogBuffer + uVar4 * 0x18) = uVar3;
    *(undefined8 **)(&DAT_140012f88 + uVar4 * 0x18) = puVar2;
    *(undefined1 *)((longlong)puVar2 + 0x51) = 0;
    PdcpPpmProcessScenarioStateChangeV2((undefined *)puVar2,uVar4 * 3);
    PdcReleaseRwLockExclusive((longlong)(puVar2 + 7));
  }
  return;
}



===== PdcpPpmProfileEnable @ 14002b26c =====

void PdcpPpmProfileEnable(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  for (puVar2 = *(undefined8 **)(param_1 + 0x48); puVar2 != (undefined8 *)(param_1 + 0x48);
      puVar2 = (undefined8 *)*puVar2) {
    puVar1 = puVar2 + 7;
    PdcAcquireRwLockExclusive((longlong)puVar1);
    if ((puVar2 != (undefined8 *)&PdcPpmMediaBufferingScenario) && (*(char *)(puVar2 + 10) == '\0'))
    {
      puVar1 = puVar2 + 0xd;
      *(undefined1 *)(puVar2 + 10) = 1;
      *puVar1 = 0;
      puVar2[0xf] = PdcpPpmScenarioEaCreateWorker;
      puVar2[0x10] = puVar2;
      ExQueueWorkItem(puVar1,1);
    }
    if ((DAT_140015c02 & 0x20) != 0) {
      McTemplateU0pt_EtwWriteTransfer(puVar1,&PDC_SPM_SCENARIO_CREATE,puVar2,0);
    }
    LOCK();
    UNLOCK();
    uVar3 = PdcPpmLogCount & 0x3f;
    uVar4 = (ulonglong)uVar3;
    PdcPpmLogCount = PdcPpmLogCount + 1;
    *(undefined4 *)(&DAT_140012f90 + uVar4 * 0x18) = 0;
    *(uint *)(&PdcPpmLogBuffer + uVar4 * 0x18) = uVar3;
    *(undefined8 **)(&DAT_140012f88 + uVar4 * 0x18) = puVar2;
    *(undefined1 *)((longlong)puVar2 + 0x51) = 1;
    PdcpPpmProcessScenarioStateChangeV2((undefined *)puVar2,uVar4 * 3);
    PdcReleaseRwLockExclusive((longlong)(puVar2 + 7));
  }
  return;
}



===== PdcpPpmProfileEvaluationWorker @ 14002b360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpPpmProfileEvaluationWorker(void)

{
  int iVar1;
  ulonglong uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  bool bVar5;
  
  uVar2 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    PdcAcquireLock();
  }
  else {
    PdcAcquireRwLockExclusive(0x140012f60);
  }
  do {
    ppuVar3 = (undefined **)0x0;
    for (ppuVar4 = (undefined **)PdcPpmProfileList; ppuVar4 != &PdcPpmProfileList;
        ppuVar4 = (undefined **)*ppuVar4) {
      if (((*(int *)(ppuVar4 + 8) != 0) && (*(char *)(ppuVar4 + 7) != '\0')) &&
         ((ppuVar3 == (undefined **)0x0 || (*(byte *)(ppuVar3 + 5) <= *(byte *)(ppuVar4 + 5))))) {
        ppuVar3 = ppuVar4;
      }
    }
    if (ppuVar3 != PdcPpmCurrentProfile) {
      PdcPpmCurrentProfile = ppuVar3;
      Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
      (*DAT_1400150c8)();
    }
    LOCK();
    iVar1 = PdcPpmEvaulationRequestCount + -1;
    UNLOCK();
    bVar5 = PdcPpmEvaulationRequestCount != 1;
    PdcPpmEvaulationRequestCount = iVar1;
  } while (bVar5);
  uVar2 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    PdcReleaseLock();
  }
  else {
    PdcReleaseRwLockExclusive(0x140012f60);
  }
  return;
}



===== PdcpPpmReadProfileProperties @ 14002b42c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdcpPpmReadProfileProperties(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined1 local_c8 [8];
  undefined4 local_c0;
  wchar_t *local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 local_88;
  wchar_t *local_80;
  undefined8 local_78;
  undefined4 local_70;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  memset(local_c8,0,0xa8);
  local_d8 = 0;
  local_b8 = L"Name";
  local_c0 = 0x124;
  local_88 = 0x124;
  local_80 = L"Pri";
  local_a8 = 0x1000000;
  local_70 = 0x4000000;
  local_b0 = param_3;
  local_78 = param_2;
  RtlQueryRegistryValuesEx(0x40000000,param_1,local_c8,0);
  return;
}



===== PdcpPpmScenarioCleanup @ 14002b500 =====

void PdcpPpmScenarioCleanup(longlong param_1,undefined8 param_2,undefined *param_3)

{
  PdcpPpmScenarioStop(param_1,param_2,param_3);
  return;
}



===== PdcpPpmScenarioDeleteWorker @ 14002b520 =====

void PdcpPpmScenarioDeleteWorker(longlong param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
  uVar2 = *(undefined8 *)(param_1 + 0x88);
  uVar1 = EaDeleteAggregatedEvent(uVar2,0);
  if ((DAT_140015c02 & 0x20) != 0) {
    McTemplateU0pt_EtwWriteTransfer(uVar2,&PDC_SPM_SCENARIO_DELETE,param_1,uVar1);
  }
  KeSetEvent(param_1 + 0x90,0,0);
  return;
}



===== PdcpPpmScenarioEaCreateWorker @ 14002b590 =====

void PdcpPpmScenarioEaCreateWorker(longlong param_1)

{
  EaCreateAggregatedEvent
            (*(undefined8 *)(param_1 + 0x60),0,PdcpPpmScenarioStart,PdcpPpmScenarioStop,
             PdcpPpmScenarioCleanup,0,param_1,0,param_1 + 0x58);
  return;
}



===== PdcpPpmScenarioStart @ 14002b5f0 =====

void PdcpPpmScenarioStart(longlong param_1,undefined8 param_2,undefined *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  
  uVar1 = Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    if (*(longlong *)(param_3 + 0x58) == param_1) {
      LOCK();
      UNLOCK();
      uVar2 = PdcPpmLogCount & 0x3f;
      uVar1 = (ulonglong)uVar2;
      PdcPpmLogCount = PdcPpmLogCount + 1;
      *(uint *)(&PdcPpmLogBuffer + uVar1 * 0x18) = uVar2;
      *(undefined4 *)(&DAT_140012f90 + uVar1 * 0x18) = 2;
      *(undefined **)(&DAT_140012f88 + uVar1 * 0x18) = param_3;
      PdcpPpmProcessScenarioStateChange(param_3,0);
    }
  }
  else {
    PdcAcquireRwLockExclusive((longlong)(param_3 + 0x38));
    param_3[0x52] = 1;
    PdcpPpmProcessScenarioStateChangeV2(param_3,param_2);
    LOCK();
    UNLOCK();
    uVar2 = PdcPpmLogCount & 0x3f;
    uVar1 = (ulonglong)uVar2;
    PdcPpmLogCount = PdcPpmLogCount + 1;
    *(undefined4 *)(&DAT_140012f90 + uVar1 * 0x18) = 2;
    *(uint *)(&PdcPpmLogBuffer + uVar1 * 0x18) = uVar2;
    *(undefined **)(&DAT_140012f88 + uVar1 * 0x18) = param_3;
    PdcReleaseRwLockExclusive((longlong)(param_3 + 0x38));
  }
  return;
}



===== PdcpPpmScenarioStop @ 14002b6b0 =====

void PdcpPpmScenarioStop(longlong param_1,undefined8 param_2,undefined *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  
  uVar1 = Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    if (*(longlong *)(param_3 + 0x58) == param_1) {
      LOCK();
      UNLOCK();
      uVar2 = PdcPpmLogCount & 0x3f;
      uVar1 = (ulonglong)uVar2;
      PdcPpmLogCount = PdcPpmLogCount + 1;
      *(undefined4 *)(&DAT_140012f90 + uVar1 * 0x18) = 3;
      *(uint *)(&PdcPpmLogBuffer + uVar1 * 0x18) = uVar2;
      *(undefined **)(&DAT_140012f88 + uVar1 * 0x18) = param_3;
      PdcpPpmProcessScenarioStateChange(param_3,3);
    }
  }
  else {
    PdcAcquireRwLockExclusive((longlong)(param_3 + 0x38));
    param_3[0x52] = 0;
    PdcpPpmProcessScenarioStateChangeV2(param_3,param_2);
    LOCK();
    UNLOCK();
    uVar2 = PdcPpmLogCount & 0x3f;
    uVar1 = (ulonglong)uVar2;
    PdcPpmLogCount = PdcPpmLogCount + 1;
    *(undefined4 *)(&DAT_140012f90 + uVar1 * 0x18) = 3;
    *(uint *)(&PdcPpmLogBuffer + uVar1 * 0x18) = uVar2;
    *(undefined **)(&DAT_140012f88 + uVar1 * 0x18) = param_3;
    PdcReleaseRwLockExclusive((longlong)(param_3 + 0x38));
  }
  return;
}



===== PdcpPpmUpdateProfileEvents @ 14002b770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PdcpPpmUpdateProfileEvents(longlong *param_1,char param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined **ppuVar5;
  
  uVar4 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 != 0) {
    PdcAcquireRwLockExclusive(0x140012f60);
  }
  uVar3 = 0;
  ppuVar5 = (undefined **)PdcPpmProfileList;
  do {
    if (ppuVar5 == &PdcPpmProfileList) {
LAB_14002b7cc:
      uVar3 = 0xc0000225;
LAB_14002b7d1:
      uVar4 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 != 0) {
        PdcReleaseRwLockExclusive(0x140012f60);
      }
      return uVar3;
    }
    if ((ppuVar5[2] == (undefined *)*param_1) && (ppuVar5[3] == (undefined *)param_1[1])) {
      if (ppuVar5 != (undefined **)0x0) {
        iVar1 = *(int *)((longlong)ppuVar5 + 0x3c);
        if (param_2 == '\0') {
          *(int *)((longlong)ppuVar5 + 0x3c) = iVar1 + -1;
          if ((iVar1 + -1 != 0) || (*(char *)(ppuVar5 + 7) == '\0')) goto LAB_14002b7d1;
          *(undefined1 *)(ppuVar5 + 7) = 0;
        }
        else {
          if (iVar1 == -1) {
            uVar3 = 0xc0000095;
            goto LAB_14002b7d1;
          }
          *(int *)((longlong)ppuVar5 + 0x3c) = iVar1 + 1;
          if ((iVar1 + 1 != 1) || (*(char *)(ppuVar5 + 7) != '\0')) goto LAB_14002b7d1;
          puVar2 = ppuVar5[6];
          *(char *)(ppuVar5 + 7) = param_2;
          Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
          (*DAT_1400150d0)(puVar2,1);
        }
        uVar4 = Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar4 == 0) {
          ExQueueWorkItem(ppuVar5 + 0xe,1);
          uVar3 = KeWaitForSingleObject(ppuVar5 + 0xb,0,0,0,0);
        }
        else if (param_2 == '\0') {
          PdcpPpmProfileDisable((longlong)ppuVar5);
        }
        else {
          PdcpPpmProfileEnable((longlong)ppuVar5);
        }
        if (param_2 == '\0') {
          puVar2 = ppuVar5[6];
          Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
          (*DAT_1400150d0)(puVar2,0);
        }
        goto LAB_14002b7d1;
      }
      goto LAB_14002b7cc;
    }
    ppuVar5 = (undefined **)*ppuVar5;
  } while( true );
}



===== PdcPolicyClientDeliverEvent @ 14002b8dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PdcPolicyClientDeliverEvent
                    (uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined **ppuVar1;
  uint uVar2;
  ulonglong uVar3;
  
  PdcPrint(2,"PDC: Begin PdcPolicyClientDeliverEvent\n",param_3,param_4);
  uVar3 = 0;
  ppuVar1 = &PdcPolicyShims;
  uVar2 = 0;
  while ((*(longlong *)(param_1 + 1) != *(longlong *)*ppuVar1 ||
         (*(longlong *)(param_1 + 3) != *(longlong *)((longlong)*ppuVar1 + 8)))) {
    uVar2 = uVar2 + 1;
    ppuVar1 = ppuVar1 + 3;
    if (3 < uVar2) {
LAB_14002b936:
      PdcPrint(((int)uVar3 >> 0x1f) + 2,
               "PDC: PdcPolicyClientDeliverEvent: %08lx\n  EventType  = %d\n  ClassId    = {%08lx-...}\n  ProviderId = {%08lx-...}\n  InstanceId = %d\n  DiagString = \"%.*S\"\n"
               ,uVar3,(ulonglong)*param_1);
      return uVar3;
    }
  }
  uVar2 = (*(code *)ppuVar1[2])(param_1);
  uVar3 = (ulonglong)uVar2;
  goto LAB_14002b936;
}



===== PdcpPolicyClientShimHandleMonitorOff @ 14002b990 =====

int PdcpPolicyClientShimHandleMonitorOff(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  
  if (*param_1 == 1) {
    plVar4 = (longlong *)(param_1 + 5);
    uVar1 = PdcpPolicySignalReasonRemap((longlong *)(param_1 + 1),plVar4);
    if (DAT_140015c02 < '\0') {
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (*(short *)((longlong)(param_1 + 10) + lVar3 * 2) != 0);
      McTemplateU0uqqjjqzr5x_EtwWriteTransfer
                (lVar3,&PDC_SIGNAL_CLASS_MONITOR_OFF_DETAILS,DAT_140015130,0,(char)uVar1,param_1 + 1
                 ,plVar4,(int)lVar3,param_1 + 10,(char)DAT_140015130);
    }
    iVar2 = PdcMonitorControl(0,uVar1);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



===== PdcpPolicyClientShimHandleNearProximityInCall @ 14002ba30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PdcpPolicyClientShimHandleNearProximityInCall(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  longlong lVar6;
  short asStackY_f423c [499858];
  undefined1 auStackY_118 [32];
  uint local_d8;
  undefined4 local_d4;
  ushort local_d0 [4];
  short *psStack_c8;
  ulonglong local_c0;
  undefined8 uStack_b8;
  short local_a8 [64];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  iVar3 = 0;
  local_d8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d4 = 0;
  if (*param_1 != 0) {
    psVar5 = local_a8;
    memset(psVar5,0,0x80);
    local_d0[0] = 0;
    local_d0[1] = 0x7e;
    local_d0[2] = 0;
    local_d0[3] = 0;
    psStack_c8 = local_a8;
    PdcAcquireLock();
    PdcSignalClientsGetActiveCount
              (psVar5,(int *)&local_d8,(undefined4 *)&local_c0,&local_d4,local_d0);
    uVar1 = local_d8;
    if ((local_d8 != 0) != (PdcpDisplayBlockedInCallActiveCount != 0)) {
      iVar3 = PdcMonitorControl((uint)(local_d8 == 0),0x16);
    }
    uVar2 = local_d4;
    lVar6 = 0x40;
    PdcPrint(2,
             "PDC: PdcpPolicyClientShimHandleDisplayBlockedInCall\n  ActiveCount = %d\n  ProviderId  = {%08lx-...}\n  InstanceId  = %d\n  DiagString  = \"%.*S\"\n"
             ,(ulonglong)uVar1,local_c0 & 0xffffffff);
    psVar5 = &PdcpDisplayBlockedInCallDiagString;
    PdcpDisplayBlockedInCallActiveCount = uVar1;
    PdcpDisplayBlockedInCallInstanceId._0_4_ = uVar2;
    _PdcpDisplayBlockedInCallProviderId = local_c0;
    _DAT_1400310b0 = uStack_b8;
    do {
      if ((lVar6 == -0x7fffffbe) ||
         (*(short *)((longlong)register0x00000020 + -0x140031f88 + (longlong)psVar5) == 0)) break;
      *psVar5 = *(short *)((longlong)register0x00000020 + -0x140031f88 + (longlong)psVar5);
      psVar5 = psVar5 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    psVar4 = psVar5 + -1;
    if (lVar6 != 0) {
      psVar4 = psVar5;
    }
    *psVar4 = 0;
    PdcReleaseLock();
  }
  return iVar3;
}



===== PdcpPolicyClientShimHandlePowerButton @ 14002bbb0 =====

undefined8
PdcpPolicyClientShimHandlePowerButton
          (int *param_1,undefined8 *param_2,undefined8 param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*param_1 != 1) {
    return 0;
  }
  puVar3 = (undefined8 *)&PdcSwitchStateLock;
  PdcAcquireRwLockExclusive(0x140032b28);
  puVar5 = auStack_28;
  uVar4 = 0;
  if (PdcPolicyClientShimPowerButton == (undefined8 *)0x0) {
    PdcPolicyClientShimPowerButton = (undefined8 *)0x0;
    uVar6 = 0x74775350;
    puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x40);
    puVar5 = auStack_28;
    if (puVar2 == (undefined8 *)0x0) {
      PdcPrint(1,"PdcConnectToPolicyDevice: ExAllocatePool2 for SwitchDevicefailed\n",uVar6,param_4)
      ;
      puVar5 = auStack_28;
      uVar4 = 0xc0000017;
      goto LAB_14002bc64;
    }
    *(undefined1 *)(puVar2 + 2) = 1;
    param_2 = &PdcSwitches;
    *(undefined4 *)((longlong)puVar2 + 0x14) = 1;
    puVar3 = DAT_140032b60;
    if ((undefined8 *)*DAT_140032b60 != &PdcSwitches) {
      puVar3 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      puVar2 = (undefined8 *)(*pcVar1)();
      puVar5 = auStack_20;
    }
    *puVar2 = param_2;
    puVar2[1] = puVar3;
    *puVar3 = puVar2;
    PdcPolicyClientShimPowerButton = puVar2;
    DAT_140032b60 = puVar2;
    if (puVar2 == (undefined8 *)0x0) goto LAB_14002bc64;
  }
  *(undefined8 *)(puVar5 + -8) = 0x14002bc64;
  PdcSoftSwitchHandler(puVar3,param_2,(longlong *)(param_1 + 5),param_4);
LAB_14002bc64:
  *(undefined8 *)(puVar5 + -8) = 0x14002bc70;
  PdcReleaseRwLockExclusive(0x140032b28);
  return uVar4;
}



===== PdcpPolicyClientShimHandleWake @ 14002bc90 =====

undefined8 PdcpPolicyClientShimHandleWake(int *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong *plVar3;
  
  if (*param_1 == 1) {
    plVar3 = (longlong *)(param_1 + 5);
    uVar1 = PdcpPolicySignalReasonRemap((longlong *)(param_1 + 1),plVar3);
    if (DAT_140015c02 < '\0') {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (*(short *)((longlong)(param_1 + 10) + lVar2 * 2) != 0);
      McTemplateU0uqqjjqzr5x_EtwWriteTransfer
                (lVar2,&PDC_SIGNAL_CLASS_WAKE_DETAILS,DAT_140015130,1,(char)uVar1,param_1 + 1,plVar3
                 ,(int)lVar2,param_1 + 10,(char)DAT_140015130);
    }
    PoSetUserPresent(uVar1);
  }
  return 0;
}



===== PdcpPolicySignalReasonRemap @ 14002bd34 =====

undefined4 PdcpPolicySignalReasonRemap(longlong *param_1,longlong *param_2)

{
  undefined **ppuVar1;
  uint uVar2;
  
  ppuVar1 = &PdcPolicyMonitorRequestMap;
  uVar2 = 0;
  while ((((*param_1 != *(longlong *)*ppuVar1 ||
           (param_1[1] != *(longlong *)((longlong)*ppuVar1 + 8))) ||
          (*param_2 != *(longlong *)ppuVar1[1])) ||
         (param_2[1] != *(longlong *)((longlong)ppuVar1[1] + 8)))) {
    uVar2 = uVar2 + 1;
    ppuVar1 = ppuVar1 + 3;
    if (7 < uVar2) {
      return 0x1b;
    }
  }
  return *(undefined4 *)(ppuVar1 + 2);
}



===== PdcSignalClientFree @ 14002bd9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PdcSignalClientFree(longlong param_1)

{
  uint *puVar1;
  short sVar2;
  undefined8 uVar3;
  undefined8 *_Dst;
  short *psVar4;
  short *psVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  
  uVar7 = 0;
  if (*(char *)(param_1 + 0x30) == '\0') {
    _Dst = (undefined8 *)ExAllocatePool2(0x100,0x2a0,0x51636450);
    puVar1 = (uint *)(param_1 + 0xd8);
    if (_Dst == (undefined8 *)0x0) {
      uVar7 = 0xc0000017;
    }
    else {
      *(undefined1 *)(param_1 + 0x30) = 1;
      (**(code **)(&DAT_140012120 + (longlong)(int)*puVar1 * 0x10))(param_1);
      memset(_Dst,0,0x2a0);
      _Dst[2] = param_1;
      *(undefined1 *)(_Dst + 3) = 1;
      *(undefined4 *)(_Dst + 4) = 2;
      uVar3 = *(undefined8 *)(param_1 + 0x3c);
      *(undefined8 *)((longlong)_Dst + 0x24) = *(undefined8 *)(param_1 + 0x34);
      *(undefined8 *)((longlong)_Dst + 0x2c) = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0x4c);
      *(undefined8 *)((longlong)_Dst + 0x34) = *(undefined8 *)(param_1 + 0x44);
      *(undefined8 *)((longlong)_Dst + 0x3c) = uVar3;
      *(undefined4 *)((longlong)_Dst + 0x44) = *(undefined4 *)(param_1 + 0x54);
      uVar3 = *(undefined8 *)(param_1 + 0xe0);
      _Dst[0x19] = *(undefined8 *)puVar1;
      _Dst[0x1a] = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0xf0);
      _Dst[0x1b] = *(undefined8 *)(param_1 + 0xe8);
      _Dst[0x1c] = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0x100);
      _Dst[0x1d] = *(undefined8 *)(param_1 + 0xf8);
      _Dst[0x1e] = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0x110);
      _Dst[0x1f] = *(undefined8 *)(param_1 + 0x108);
      _Dst[0x20] = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0x120);
      _Dst[0x21] = *(undefined8 *)(param_1 + 0x118);
      _Dst[0x22] = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0x130);
      _Dst[0x23] = *(undefined8 *)(param_1 + 0x128);
      _Dst[0x24] = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0x140);
      _Dst[0x25] = *(undefined8 *)(param_1 + 0x138);
      _Dst[0x26] = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0x150);
      _Dst[0x27] = *(undefined8 *)(param_1 + 0x148);
      _Dst[0x28] = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0x160);
      _Dst[0x29] = *(undefined8 *)(param_1 + 0x158);
      _Dst[0x2a] = uVar3;
      uVar3 = *(undefined8 *)(param_1 + 0x170);
      _Dst[0x2b] = *(undefined8 *)(param_1 + 0x168);
      _Dst[0x2c] = uVar3;
      psVar5 = (short *)(_Dst + 9);
      lVar6 = 0x40;
      lVar8 = param_1 - (longlong)psVar5;
      do {
        if ((lVar6 == -0x7fffffbe) ||
           (sVar2 = *(short *)(lVar8 + 0x58 + (longlong)psVar5), sVar2 == 0)) break;
        *psVar5 = sVar2;
        psVar5 = psVar5 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      psVar4 = psVar5 + -1;
      if (lVar6 != 0) {
        psVar4 = psVar5;
      }
      *psVar4 = 0;
      PdcpEnqueueSignalEvent(_Dst);
    }
    PdcPrint(((int)uVar7 >> 0x1f) + 2,
             "PDC: PdcSignalClientFree: %08lx\n  SignalType = %d\n  ClassId    = {%08lx-...}\n  ProviderId = {%08lx-...}\n  InstanceId = %d\n"
             ,(ulonglong)uVar7,(ulonglong)*puVar1);
  }
  else {
    uVar7 = 0xc0000189;
  }
  return uVar7;
}



===== PdcSignalClientInitialize @ 14002bf64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PdcSignalClientInitialize(uint param_1,int *param_2,undefined8 *param_3)

{
  longlong *plVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int *piVar10;
  undefined8 *_Dst;
  undefined8 *_Dst_00;
  short *psVar11;
  longlong lVar12;
  undefined **ppuVar13;
  short *psVar14;
  undefined8 *puVar15;
  uint uVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [72];
  
  *param_3 = 0;
  if ((((param_1 - 1 < 0x7c) && (&PdcClientInfo + (ulonglong)param_1 * 6 != (uint *)0x0)) &&
      (((&PdcClientInfo)[(ulonglong)param_1 * 6] & 0x20) != 0)) && (*param_2 == 1)) {
    iVar3 = param_2[1];
    if ((((iVar3 - 1U < 2) &&
         ((plVar1 = (longlong *)(param_2 + 2), *plVar1 != 0 || (*(longlong *)(param_2 + 4) != 0))))
        && ((*(longlong *)(param_2 + 6) != 0 || (*(longlong *)(param_2 + 8) != 0)))) &&
       (piVar10 = param_2 + 0xb, piVar10 != (int *)0x0)) {
      lVar12 = 0x40;
      do {
        if ((short)*piVar10 == 0) break;
        piVar10 = (int *)((longlong)piVar10 + 2);
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      uVar16 = ~-(uint)(lVar12 != 0) & 0xc000000d;
      puVar18 = auStack_78;
      if (lVar12 == 0) goto LAB_14002c264;
      if (plVar1 != (longlong *)0x0) {
        uVar16 = 0;
        ppuVar13 = &PdcPolicyShims;
        do {
          if ((*plVar1 == *(longlong *)*ppuVar13) &&
             (*(longlong *)(param_2 + 4) == *(longlong *)((longlong)*ppuVar13 + 8))) {
            if (*(int *)(ppuVar13 + 1) != 0) {
              if (*(int *)(ppuVar13 + 1) != iVar3) {
                uVar16 = 0xc0000232;
                puVar18 = auStack_78;
                goto LAB_14002c264;
              }
              _Dst = (undefined8 *)ExAllocatePool2(0x100,0x178,0x49636450);
              _Dst_00 = (undefined8 *)ExAllocatePool2(0x100,0x2a0,0x51636450);
              if ((_Dst != (undefined8 *)0x0) && (_Dst_00 != (undefined8 *)0x0)) {
                memset(_Dst,0,0x178);
                *(undefined4 *)(_Dst + 2) = 5;
                *(int *)(_Dst + 0x1b) = param_2[1];
                lVar12 = 0x40;
                uVar9 = *(undefined8 *)(param_2 + 4);
                *(longlong *)((longlong)_Dst + 0x34) = *plVar1;
                *(undefined8 *)((longlong)_Dst + 0x3c) = uVar9;
                uVar9 = *(undefined8 *)(param_2 + 8);
                *(undefined8 *)((longlong)_Dst + 0x44) = *(undefined8 *)(param_2 + 6);
                *(undefined8 *)((longlong)_Dst + 0x4c) = uVar9;
                *(int *)((longlong)_Dst + 0x54) = param_2[10];
                psVar14 = (short *)(_Dst + 0xb);
                goto LAB_14002c136;
              }
              uVar16 = 0xc0000017;
              if (_Dst != (undefined8 *)0x0) {
                ExFreePoolWithTag(_Dst,0);
              }
              puVar18 = auStack_78;
              if (_Dst_00 != (undefined8 *)0x0) {
                ExFreePoolWithTag(_Dst_00,0);
                puVar18 = auStack_78;
              }
              goto LAB_14002c264;
            }
            break;
          }
          uVar16 = uVar16 + 1;
          ppuVar13 = ppuVar13 + 3;
        } while (uVar16 < 4);
        uVar16 = 0xc0000003;
        puVar18 = auStack_78;
        goto LAB_14002c264;
      }
    }
  }
  uVar16 = 0xc000000d;
  puVar18 = auStack_78;
LAB_14002c264:
  uVar4 = param_2[1];
  *(int **)(puVar18 + 0x40) = param_2 + 0xb;
  iVar3 = param_2[10];
  *(undefined4 *)(puVar18 + 0x38) = 0x40;
  *(int *)(puVar18 + 0x30) = iVar3;
  *(int *)(puVar18 + 0x28) = param_2[6];
  *(int *)(puVar18 + 0x20) = param_2[2];
  *(undefined8 *)(puVar18 + -8) = 0x14002c2a5;
  PdcPrint(((int)uVar16 >> 0x1f) + 2,
           "PDC: PdcSignalClientInitialize: %08lx\n  SignalType = %d\n  ClassId    = {%08lx-...}\n  ProviderId = {%08lx-...}\n  InstanceId = %d\n  DiagString = \"%.*S\"\n"
           ,(ulonglong)uVar16,(ulonglong)uVar4);
  return uVar16;
  while( true ) {
    *psVar14 = sVar2;
    psVar14 = psVar14 + 1;
    lVar12 = lVar12 + -1;
    if (lVar12 == 0) break;
LAB_14002c136:
    if ((lVar12 == -0x7fffffbe) ||
       (sVar2 = *(short *)((longlong)param_2 + (0x2c - (longlong)(_Dst + 0xb)) + (longlong)psVar14),
       sVar2 == 0)) break;
  }
  psVar11 = psVar14 + -1;
  if (lVar12 != 0) {
    psVar11 = psVar14;
  }
  *psVar11 = 0;
  memset(_Dst_00,0,0x2a0);
  _Dst_00[2] = _Dst;
  uVar9 = *(undefined8 *)((longlong)_Dst + 0x3c);
  lVar12 = 0x40;
  *(undefined8 *)((longlong)_Dst_00 + 0x24) = *(undefined8 *)((longlong)_Dst + 0x34);
  *(undefined8 *)((longlong)_Dst_00 + 0x2c) = uVar9;
  uVar6 = *(undefined4 *)(_Dst + 9);
  uVar7 = *(undefined4 *)((longlong)_Dst + 0x4c);
  uVar8 = *(undefined4 *)(_Dst + 10);
  *(undefined4 *)((longlong)_Dst_00 + 0x34) = *(undefined4 *)((longlong)_Dst + 0x44);
  *(undefined4 *)(_Dst_00 + 7) = uVar6;
  *(undefined4 *)((longlong)_Dst_00 + 0x3c) = uVar7;
  *(undefined4 *)(_Dst_00 + 8) = uVar8;
  *(undefined4 *)((longlong)_Dst_00 + 0x44) = *(undefined4 *)((longlong)_Dst + 0x54);
  psVar14 = (short *)(_Dst_00 + 9);
  do {
    if ((lVar12 == -0x7fffffbe) ||
       (sVar2 = *(short *)((longlong)_Dst + (0x58 - (longlong)(_Dst_00 + 9)) + (longlong)psVar14),
       sVar2 == 0)) break;
    *psVar14 = sVar2;
    psVar14 = psVar14 + 1;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  psVar11 = psVar14 + -1;
  if (lVar12 != 0) {
    psVar11 = psVar14;
  }
  *psVar11 = 0;
  (**(code **)(&DAT_140012120 + (longlong)iVar3 * 0x10))(_Dst,1);
  puVar17 = auStack_78;
  puVar15 = &PdcSignalClients;
  if ((undefined8 *)*DAT_140012e18 != &PdcSignalClients) {
    puVar15 = (undefined8 *)0x3;
    pcVar5 = (code *)swi(0x29);
    DAT_140012e18 = (undefined8 *)(*pcVar5)();
    puVar17 = auStack_70;
  }
  *_Dst = puVar15;
  _Dst[1] = DAT_140012e18;
  *DAT_140012e18 = _Dst;
  *(undefined8 *)(puVar17 + -8) = 0x14002c224;
  DAT_140012e18 = _Dst;
  PdcpEnqueueSignalEvent(_Dst_00);
  *param_3 = _Dst;
  uVar16 = 0;
  puVar18 = puVar17;
  goto LAB_14002c264;
}



===== PdcSignalClientReceive @ 14002c2c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PdcSignalClientReceive(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  int *piVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined8 *_Dst;
  short *psVar10;
  short *psVar11;
  longlong lVar12;
  char local_res10 [8];
  
  local_res10[0] = '\0';
  if (*(int *)(param_2 + 0x28) == 8) {
    if (*(char *)(param_1 + 0x30) == '\0') {
      puVar1 = (undefined8 *)(param_2 + 0x38);
      _Dst = (undefined8 *)ExAllocatePool2(0x100,0x2a0,0x51636450);
      if (_Dst == (undefined8 *)0x0) {
        uVar9 = 0xc0000017;
      }
      else {
        memset(_Dst,0,0x2a0);
        _Dst[2] = param_1;
        *(undefined4 *)(_Dst + 4) = 1;
        piVar2 = (int *)(param_1 + 0xd8);
        uVar7 = *(undefined8 *)(param_1 + 0x4c);
        *(undefined8 *)((longlong)_Dst + 0x34) = *(undefined8 *)(param_1 + 0x44);
        *(undefined8 *)((longlong)_Dst + 0x3c) = uVar7;
        uVar7 = *(undefined8 *)(param_1 + 0x3c);
        *(undefined8 *)((longlong)_Dst + 0x24) = *(undefined8 *)(param_1 + 0x34);
        *(undefined8 *)((longlong)_Dst + 0x2c) = uVar7;
        *(undefined4 *)((longlong)_Dst + 0x44) = *(undefined4 *)(param_1 + 0x54);
        uVar7 = *(undefined8 *)(param_2 + 0x40);
        _Dst[0x41] = *puVar1;
        _Dst[0x42] = uVar7;
        uVar7 = *(undefined8 *)(param_2 + 0x50);
        _Dst[0x43] = *(undefined8 *)(param_2 + 0x48);
        _Dst[0x44] = uVar7;
        uVar7 = *(undefined8 *)(param_2 + 0x60);
        _Dst[0x45] = *(undefined8 *)(param_2 + 0x58);
        _Dst[0x46] = uVar7;
        uVar7 = *(undefined8 *)(param_2 + 0x70);
        _Dst[0x47] = *(undefined8 *)(param_2 + 0x68);
        _Dst[0x48] = uVar7;
        uVar7 = *(undefined8 *)(param_2 + 0x80);
        _Dst[0x49] = *(undefined8 *)(param_2 + 0x78);
        _Dst[0x4a] = uVar7;
        uVar7 = *(undefined8 *)(param_2 + 0x90);
        _Dst[0x4b] = *(undefined8 *)(param_2 + 0x88);
        _Dst[0x4c] = uVar7;
        uVar7 = *(undefined8 *)(param_2 + 0xa0);
        _Dst[0x4d] = *(undefined8 *)(param_2 + 0x98);
        _Dst[0x4e] = uVar7;
        uVar7 = *(undefined8 *)(param_2 + 0xb0);
        _Dst[0x4f] = *(undefined8 *)(param_2 + 0xa8);
        _Dst[0x50] = uVar7;
        uVar7 = *(undefined8 *)(param_2 + 0xc0);
        _Dst[0x51] = *(undefined8 *)(param_2 + 0xb8);
        _Dst[0x52] = uVar7;
        _Dst[0x53] = *(undefined8 *)(param_2 + 200);
        uVar7 = *(undefined8 *)(param_1 + 0xe0);
        _Dst[0x19] = *(undefined8 *)piVar2;
        _Dst[0x1a] = uVar7;
        uVar7 = *(undefined8 *)(param_1 + 0xf0);
        _Dst[0x1b] = *(undefined8 *)(param_1 + 0xe8);
        _Dst[0x1c] = uVar7;
        uVar7 = *(undefined8 *)(param_1 + 0x100);
        _Dst[0x1d] = *(undefined8 *)(param_1 + 0xf8);
        _Dst[0x1e] = uVar7;
        uVar7 = *(undefined8 *)(param_1 + 0x110);
        _Dst[0x1f] = *(undefined8 *)(param_1 + 0x108);
        _Dst[0x20] = uVar7;
        uVar7 = *(undefined8 *)(param_1 + 0x120);
        _Dst[0x21] = *(undefined8 *)(param_1 + 0x118);
        _Dst[0x22] = uVar7;
        uVar7 = *(undefined8 *)(param_1 + 0x130);
        _Dst[0x23] = *(undefined8 *)(param_1 + 0x128);
        _Dst[0x24] = uVar7;
        uVar7 = *(undefined8 *)(param_1 + 0x140);
        _Dst[0x25] = *(undefined8 *)(param_1 + 0x138);
        _Dst[0x26] = uVar7;
        uVar7 = *(undefined8 *)(param_1 + 0x150);
        _Dst[0x27] = *(undefined8 *)(param_1 + 0x148);
        _Dst[0x28] = uVar7;
        uVar4 = *(undefined4 *)(param_1 + 0x15c);
        uVar5 = *(undefined4 *)(param_1 + 0x160);
        uVar6 = *(undefined4 *)(param_1 + 0x164);
        *(undefined4 *)(_Dst + 0x29) = *(undefined4 *)(param_1 + 0x158);
        *(undefined4 *)((longlong)_Dst + 0x14c) = uVar4;
        *(undefined4 *)(_Dst + 0x2a) = uVar5;
        *(undefined4 *)((longlong)_Dst + 0x154) = uVar6;
        uVar4 = *(undefined4 *)(param_1 + 0x16c);
        uVar5 = *(undefined4 *)(param_1 + 0x170);
        uVar6 = *(undefined4 *)(param_1 + 0x174);
        *(undefined4 *)(_Dst + 0x2b) = *(undefined4 *)(param_1 + 0x168);
        *(undefined4 *)((longlong)_Dst + 0x15c) = uVar4;
        *(undefined4 *)(_Dst + 0x2c) = uVar5;
        *(undefined4 *)((longlong)_Dst + 0x164) = uVar6;
        lVar12 = 0x40;
        psVar11 = (short *)(_Dst + 9);
        do {
          if ((lVar12 == -0x7fffffbe) ||
             (sVar3 = *(short *)((longlong)puVar1 + (4 - (longlong)(_Dst + 9)) + (longlong)psVar11),
             sVar3 == 0)) break;
          *psVar11 = sVar3;
          psVar11 = psVar11 + 1;
          lVar12 = lVar12 + -1;
        } while (lVar12 != 0);
        psVar10 = psVar11 + -1;
        if (lVar12 != 0) {
          psVar10 = psVar11;
        }
        *psVar10 = 0;
        uVar8 = (**(code **)(&PdcSignalTypedefs + (longlong)*piVar2 * 0x10))
                          (param_1,puVar1,local_res10);
        uVar9 = (ulonglong)uVar8;
        if (((int)uVar8 < 0) || (local_res10[0] == '\0')) {
          ExFreePoolWithTag(_Dst,0);
        }
        else {
          uVar7 = *(undefined8 *)(param_1 + 0xe0);
          _Dst[0x2d] = *(undefined8 *)piVar2;
          _Dst[0x2e] = uVar7;
          uVar7 = *(undefined8 *)(param_1 + 0xf0);
          _Dst[0x2f] = *(undefined8 *)(param_1 + 0xe8);
          _Dst[0x30] = uVar7;
          uVar7 = *(undefined8 *)(param_1 + 0x100);
          _Dst[0x31] = *(undefined8 *)(param_1 + 0xf8);
          _Dst[0x32] = uVar7;
          uVar7 = *(undefined8 *)(param_1 + 0x110);
          _Dst[0x33] = *(undefined8 *)(param_1 + 0x108);
          _Dst[0x34] = uVar7;
          uVar7 = *(undefined8 *)(param_1 + 0x120);
          _Dst[0x35] = *(undefined8 *)(param_1 + 0x118);
          _Dst[0x36] = uVar7;
          uVar7 = *(undefined8 *)(param_1 + 0x130);
          _Dst[0x37] = *(undefined8 *)(param_1 + 0x128);
          _Dst[0x38] = uVar7;
          uVar7 = *(undefined8 *)(param_1 + 0x140);
          _Dst[0x39] = *(undefined8 *)(param_1 + 0x138);
          _Dst[0x3a] = uVar7;
          uVar7 = *(undefined8 *)(param_1 + 0x150);
          _Dst[0x3b] = *(undefined8 *)(param_1 + 0x148);
          _Dst[0x3c] = uVar7;
          uVar7 = *(undefined8 *)(param_1 + 0x160);
          _Dst[0x3d] = *(undefined8 *)(param_1 + 0x158);
          _Dst[0x3e] = uVar7;
          uVar7 = *(undefined8 *)(param_1 + 0x170);
          _Dst[0x3f] = *(undefined8 *)(param_1 + 0x168);
          _Dst[0x40] = uVar7;
          PdcpEnqueueSignalEvent(_Dst);
        }
      }
      PdcPrint(((int)uVar9 >> 0x1f) + 2,
               "PDC: PdcSignalClientReceive: %08lx\n  SignalType = %d\n  ClassId    = {%08lx-...}\n  ProviderId = {%08lx-...}\n  InstanceId = %d\n  ChangeType = %d\n  DiagString = \"%.*S\"\n  RawData    = %016llx %016llx\n"
               ,uVar9,(ulonglong)*(uint *)(param_1 + 0xd8));
    }
    else {
      uVar9 = 0xc0000189;
    }
  }
  else {
    uVar9 = 0xc000000d;
  }
  return uVar9;
}



===== PdcSignalClientsGetActiveCount @ 14002c5cc =====

void PdcSignalClientsGetActiveCount
               (undefined8 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
               ushort *param_5)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  short sVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong lVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  
  puVar4 = PdcSignalClients;
  sVar5 = 0;
  *param_2 = 0;
  puVar9 = (undefined8 *)0x0;
  if ((undefined8 **)puVar4 != &PdcSignalClients) {
    do {
      if ((((*(int *)(puVar4 + 0x1b) == 2) && (*(char *)(puVar4 + 6) == '\0')) &&
          (*(longlong *)((longlong)puVar4 + 0x34) == 0x448c693d0ef04360)) &&
         ((*(longlong *)((longlong)puVar4 + 0x3c) == -0x38f8628586084845 &&
          (*(char *)(puVar4 + 0x2c) != '\0')))) {
        *param_2 = *param_2 + 1;
        puVar9 = puVar4;
      }
      puVar4 = (undefined8 *)*puVar4;
    } while ((undefined8 **)puVar4 != &PdcSignalClients);
    if (puVar9 != (undefined8 *)0x0) {
      uVar11 = *(undefined4 *)((longlong)puVar9 + 0x44);
      uVar12 = *(undefined4 *)(puVar9 + 9);
      uVar13 = *(undefined4 *)((longlong)puVar9 + 0x4c);
      uVar14 = *(undefined4 *)(puVar9 + 10);
      uVar3 = *(undefined4 *)((longlong)puVar9 + 0x54);
      pwVar6 = (wchar_t *)(puVar9 + 0xb);
      goto LAB_14002c649;
    }
  }
  uVar11 = 0;
  uVar12 = 0;
  uVar13 = 0;
  uVar14 = 0;
  uVar3 = 0;
  pwVar6 = (wchar_t *)0x0;
LAB_14002c649:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar11;
    param_3[1] = uVar12;
    param_3[2] = uVar13;
    param_3[3] = uVar14;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = uVar3;
  }
  if ((((param_5 != (ushort *)0x0) && (uVar1 = *param_5, (uVar1 & 1) == 0)) &&
      ((uVar2 = param_5[1], (uVar2 & 1) == 0 && ((uVar1 <= uVar2 && (uVar2 != 0xffff)))))) &&
     ((*(longlong *)(param_5 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    uVar1 = param_5[1];
    pwVar7 = L"";
    if (pwVar6 != (wchar_t *)0x0) {
      pwVar7 = pwVar6;
    }
    if ((ulonglong)(uVar1 >> 1) != 0) {
      lVar8 = 0x7fff;
      sVar5 = 0;
      lVar10 = *(longlong *)(param_5 + 4) - (longlong)pwVar7;
      do {
        if ((lVar8 == 0) || (*pwVar7 == L'\0')) break;
        *(wchar_t *)(lVar10 + (longlong)pwVar7) = *pwVar7;
        lVar8 = lVar8 + -1;
        pwVar7 = pwVar7 + 1;
        sVar5 = sVar5 + 1;
      } while (((ulonglong)(uVar1 >> 1) - 0x7fff) + lVar8 != 0);
    }
    *param_5 = sVar5 * 2;
  }
  return;
}



===== PdcpLevelSignalClientRundown @ 14002c710 =====

void PdcpLevelSignalClientRundown(void)

{
  return;
}



===== PdcpEdgeSignalClientUpdate @ 14002c720 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcpEdgeSignalClientUpdate(longlong param_1,int *param_2,undefined1 *param_3)

{
  code *pcVar1;
  
  *param_3 = 0;
  if (*(int *)(param_1 + 0xd8) != 1) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  if (*param_2 == 0) {
    *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + 1;
    *(undefined8 *)(param_1 + 0x168) = _DAT_fffff78000000008;
    *param_3 = 1;
    return 0;
  }
  return 0xc000000d;
}



===== PdcpEnqueueSignalEvent @ 14002c768 =====

void PdcpEnqueueSignalEvent(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  PdcAcquireRwLockExclusive(0x140012e20);
  puVar3 = auStack_28;
  puVar2 = &PdcSignalEventQueue;
  if ((undefined8 *)*DAT_140012e48 != &PdcSignalEventQueue) {
    puVar2 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    DAT_140012e48 = (undefined8 *)(*pcVar1)();
    puVar3 = auStack_20;
  }
  *param_1 = puVar2;
  param_1[1] = DAT_140012e48;
  *DAT_140012e48 = param_1;
  *(undefined8 *)(puVar3 + -8) = 0x14002c7b4;
  DAT_140012e48 = param_1;
  PdcReleaseRwLockExclusive(0x140012e20);
  *(undefined8 *)(puVar3 + -8) = 0x14002c7be;
  PdcGetPolicyWorker(8);
  *(undefined8 *)(puVar3 + -8) = 0x14002c7c3;
  PdcCheckForWork();
  return;
}



===== PdcpLevelSignalClientUpdate @ 14002c7d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcpLevelSignalClientUpdate(longlong param_1,int *param_2,undefined1 *param_3)

{
  code *pcVar1;
  undefined3 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  *param_3 = 0;
  if (*(int *)(param_1 + 0xd8) != 2) {
    pcVar1 = (code *)swi(0x29);
    uVar4 = 0;
    (*pcVar1)(5);
  }
  if (*param_2 != 1) {
    return 0xc000000d;
  }
  uVar2 = (undefined3)((uint)uVar4 >> 8);
  if (CONCAT31(uVar2,(char)param_2[0x22] != (char)uVar4) !=
      CONCAT31(uVar2,*(char *)(param_1 + 0x160) != (char)uVar4)) {
    *param_3 = 1;
    iVar3 = param_2[0x22];
    *(bool *)(param_1 + 0x160) = (char)iVar3 != '\0';
    if ((char)iVar3 == '\0') {
      *(undefined8 *)(param_1 + 0x170) = _DAT_fffff78000000008;
    }
    else {
      *(int *)(param_1 + 0x164) = *(int *)(param_1 + 0x164) + 1;
      *(undefined8 *)(param_1 + 0x168) = _DAT_fffff78000000008;
    }
  }
  return 0;
}



===== PdcpSignalClientCompleteRemove @ 14002c864 =====

undefined8 PdcpSignalClientCompleteRemove(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    ExFreePoolWithTag(param_1,0);
    return 0;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  uVar4 = (*pcVar3)();
  return uVar4;
}



===== PdcLockStatsEmitTelemetry @ 14002c8a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcLockStatsEmitTelemetry
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  undefined1 auStackY_168 [32];
  ushort local_138 [2];
  ushort local_134 [2];
  ushort local_130 [2];
  undefined4 local_12c;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108 [2];
  undefined8 local_f8 [4];
  undefined4 *local_d8;
  undefined8 local_d0;
  ushort *local_c8;
  undefined8 local_c0;
  longlong local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  ushort *local_78;
  undefined8 local_70;
  longlong local_68;
  int local_60;
  undefined4 local_5c;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  longlong local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_168;
  if (5 < DAT_140031288) {
    if (((_DAT_140031298 & 0x400000000004) == 0) ||
       (bVar1 = true, (DAT_1400312a0 & 0x400000000004) != DAT_1400312a0)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_138[0] = *(ushort *)(param_1 + 8);
      local_12c = *(undefined4 *)(param_1 + 8);
      local_d8 = &local_12c;
      local_c8 = local_138;
      local_b8 = param_1 + 0x10;
      local_128 = *(undefined8 *)(param_1 + 0x68);
      local_a8 = &local_128;
      local_120 = *(undefined8 *)(param_1 + 0x70);
      local_98 = &local_120;
      local_118 = *(undefined8 *)(param_1 + 0x78);
      local_88 = &local_118;
      local_78 = local_134;
      local_68 = param_1 + 0x88;
      local_110 = *(undefined8 *)(param_1 + 0xe0);
      local_58 = &local_110;
      local_108[0] = *(undefined8 *)(param_1 + 0xe8);
      local_48 = local_108;
      local_b0 = (uint)local_138[0] << 3;
      local_38 = local_130;
      local_28 = param_1 + 0xf8;
      local_d0 = 4;
      local_c0 = 2;
      local_ac = 0;
      local_a0 = 8;
      local_90 = 8;
      local_80 = 8;
      local_70 = 2;
      local_5c = 0;
      local_50 = 8;
      local_40 = 8;
      local_30 = 2;
      local_1c = 0;
      local_134[0] = local_138[0];
      local_130[0] = local_138[0];
      local_60 = local_b0;
      local_20 = local_b0;
      _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000f307,param_1,param_4,0xe,local_f8);
    }
  }
  return;
}



===== PdcDereferenceActivationStats @ 14002ca68 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcDereferenceActivationStats(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = _DAT_fffff78000000008;
  PdcBSActivationStats = PdcBSActivationStats + -1;
  lVar2 = *param_1;
  if (lVar2 != 0) {
    piVar1 = (int *)(lVar2 + 0x14);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      PdcpEndActivatedPeriod(lVar2,lVar3,'\0');
    }
  }
  PdcpActivationCount = PdcpActivationCount + -1;
  if ((PdcpResiliencyActivationAccountingEnabled != '\0') && (PdcpActivationCount == 0)) {
    PdcpPauseResiliencyActivationAccounting();
  }
  if (param_1[1] != 0) {
    SleepstudyHelperBlockerActiveDereference();
  }
  return;
}



===== PdcGetActivatorStats @ 14002cad8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * PdcGetActivatorStats(uint param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined8 *puVar6;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  puVar6 = (undefined8 *)0x0;
  puVar5 = auStack_48;
  if ((param_1 - 1 < 0x7c) && (puVar5 = auStack_48, (ulonglong)param_1 * 0x18 != -0x140031f60)) {
    for (puVar2 = PdcActivatorStatsList; (undefined8 **)puVar2 != &PdcActivatorStatsList;
        puVar2 = (undefined8 *)*puVar2) {
      if (*(uint *)(puVar2 + 2) == param_1) goto LAB_14002cbac;
    }
    puVar2 = (undefined8 *)ExAllocatePool2(0x100,0x58,0x41636450);
    puVar5 = auStack_48;
    if (puVar2 != (undefined8 *)0x0) {
      *(uint *)(puVar2 + 2) = param_1;
      *(undefined4 *)(puVar2 + 10) = 0x10001;
      local_24 = 0x50444341;
      local_28 = 1;
      local_20 = 6;
      uVar3 = SleepstudyHelperCreateLibraryEx(&local_28,puVar2 + 8);
      puVar5 = auStack_48;
      if ((int)uVar3 < 0) {
        ExFreePoolWithTag(puVar2,0);
        puVar5 = auStack_48;
      }
      else if ((undefined8 **)*DAT_140012998 == &PdcActivatorStatsList) {
        *puVar2 = &PdcActivatorStatsList;
        puVar2[1] = DAT_140012998;
        *DAT_140012998 = puVar2;
        puVar6 = puVar2;
        DAT_140012998 = puVar2;
      }
      else {
        pcVar1 = (code *)swi(0x29);
        puVar2 = (undefined8 *)(*pcVar1)(3);
        puVar4 = auStack_40;
LAB_14002cbac:
        puVar5 = puVar4;
        puVar6 = puVar2;
      }
    }
  }
  *(undefined8 *)(puVar5 + -8) = 0x14002cbe8;
  return puVar6;
}



===== PdcPauseActivationStats @ 14002cc04 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcPauseActivationStats(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  lVar1 = _DAT_fffff78000000008;
  PdcpAccountingPaused = 1;
  for (puVar2 = PdcActivatorStatsList; (undefined8 **)puVar2 != &PdcActivatorStatsList;
      puVar2 = (undefined8 *)*puVar2) {
    if (0 < *(int *)((longlong)puVar2 + 0x14)) {
      PdcpEndActivatedPeriod((longlong)puVar2,lVar1,'\x01');
    }
  }
  return;
}



===== PdcQueryBootSessionStandbyActiveTime @ 14002cc70 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcQueryBootSessionStandbyActiveTime(undefined8 *param_1,longlong *param_2,longlong *param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  
  PdcAcquireLock();
  if (PdcpAccountingPaused == '\0') {
    PdcPauseActivationStats();
    PdcResumeActivationStats();
    if (0 < PdcBSActivationStats) {
      DAT_1400129d0 = DAT_1400129d0 + (_DAT_fffff78000000008 - DAT_1400129c8);
      DAT_1400129c8 = _DAT_fffff78000000008;
    }
  }
  if (DAT_14003100c == 8) {
    DAT_140012dc8 = DAT_140012dc8 + (_DAT_fffff78000000008 - _DAT_140012dc0);
    _DAT_140012dc0 = _DAT_fffff78000000008;
  }
  lVar4 = 7;
  puVar2 = (undefined8 *)&DAT_1400129d8;
  do {
    puVar5 = param_1;
    puVar3 = puVar2;
    uVar1 = puVar3[1];
    *puVar5 = *puVar3;
    puVar5[1] = uVar1;
    uVar1 = puVar3[3];
    puVar5[2] = puVar3[2];
    puVar5[3] = uVar1;
    uVar1 = puVar3[5];
    puVar5[4] = puVar3[4];
    puVar5[5] = uVar1;
    uVar1 = puVar3[7];
    puVar5[6] = puVar3[6];
    puVar5[7] = uVar1;
    uVar1 = puVar3[9];
    puVar5[8] = puVar3[8];
    puVar5[9] = uVar1;
    uVar1 = puVar3[0xb];
    puVar5[10] = puVar3[10];
    puVar5[0xb] = uVar1;
    uVar1 = puVar3[0xd];
    puVar5[0xc] = puVar3[0xc];
    puVar5[0xd] = uVar1;
    uVar1 = puVar3[0xf];
    puVar5[0xe] = puVar3[0xe];
    puVar5[0xf] = uVar1;
    lVar4 = lVar4 + -1;
    puVar2 = puVar3 + 0x10;
    param_1 = puVar5 + 0x10;
  } while (lVar4 != 0);
  uVar1 = puVar3[0x11];
  puVar5[0x10] = puVar3[0x10];
  puVar5[0x11] = uVar1;
  uVar1 = puVar3[0x13];
  puVar5[0x12] = puVar3[0x12];
  puVar5[0x13] = uVar1;
  uVar1 = puVar3[0x15];
  puVar5[0x14] = puVar3[0x14];
  puVar5[0x15] = uVar1;
  uVar1 = puVar3[0x17];
  puVar5[0x16] = puVar3[0x16];
  puVar5[0x17] = uVar1;
  uVar1 = puVar3[0x19];
  puVar5[0x18] = puVar3[0x18];
  puVar5[0x19] = uVar1;
  uVar1 = puVar3[0x1b];
  puVar5[0x1a] = puVar3[0x1a];
  puVar5[0x1b] = uVar1;
  puVar5[0x1c] = puVar3[0x1c];
  *param_2 = DAT_1400129d0;
  *param_3 = DAT_140012dc8;
  PdcReleaseLock();
  return;
}



===== PdcRefDerefActivationStatsBySubtask @ 14002cdc0 =====

void PdcRefDerefActivationStatsBySubtask(longlong param_1,wchar_t *param_2)

{
  longlong *plVar1;
  wchar_t wVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  wchar_t *pwVar6;
  uint uVar7;
  wchar_t *_Str2;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  
  plVar1 = (longlong *)(param_1 + 0x328);
  _Str2 = (wchar_t *)(param_1 + 0x130);
  lVar9 = *plVar1;
  if (*(char *)(param_1 + 0x338) == '\0') {
    return;
  }
  lVar10 = 0x80;
  iVar3 = wcsncmp(param_2,L"",0x80);
  if (iVar3 == 0) {
    return;
  }
  iVar3 = wcsncmp(param_2,_Str2,0x80);
  if (iVar3 == 0) {
    return;
  }
  uVar5 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  uVar8 = 0;
  if ((int)uVar5 != 0) {
    uVar8 = (uint)(*(int *)(param_1 + 0x33c) != 0);
    goto LAB_14002ceae;
  }
  uVar7 = *(uint *)(param_1 + 0x318);
  PdcpGetActivationResiliencyStatus(param_1);
  uVar5 = 8;
  if (*(int *)(param_1 + 0x2f4) == 2) {
    if (uVar7 == 8) {
      uVar5 = PdcpGetResiliencyThreshold(*(int *)(param_1 + 0x18));
      uVar5 = uVar5 & 0xffffffff;
    }
    else {
LAB_14002ce86:
      uVar5 = (ulonglong)uVar7;
    }
  }
  else if (*(int *)(param_1 + 0x2f4) == 0) {
    if (uVar7 == 8) goto LAB_14002ceae;
    goto LAB_14002ce86;
  }
  uVar7 = (uint)uVar5;
  while (-1 < (int)uVar7) {
    uVar4 = uVar8 + 1;
    if ((int)uVar5 == 6) {
      uVar4 = uVar8;
    }
    uVar7 = (int)uVar5 - 1;
    uVar5 = (ulonglong)uVar7;
    uVar8 = uVar4;
  }
LAB_14002ceae:
  if (*(longlong *)(param_1 + 0x330) != 0) {
    if (0 < (int)uVar8) {
      uVar5 = (ulonglong)uVar8;
      do {
        SleepstudyHelperBlockerActiveDereference();
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    PdcFreeActivationStats(plVar1);
  }
  if ((((lVar9 != 0) && (*(longlong *)(lVar9 + 0x40) != 0)) &&
      (PdcpCreateActivationBlockerHeirarchy(lVar9,(short *)(param_1 + 0x30),_Str2,plVar1),
      *(longlong *)(param_1 + 0x330) != 0)) && (0 < (int)uVar8)) {
    uVar5 = (ulonglong)uVar8;
    do {
      SleepstudyHelperBlockerActiveReference();
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  lVar9 = (longlong)param_2 - (longlong)_Str2;
  do {
    if ((lVar10 == -0x7fffff7e) || (wVar2 = *(wchar_t *)(lVar9 + (longlong)_Str2), wVar2 == L'\0'))
    break;
    *_Str2 = wVar2;
    _Str2 = _Str2 + 1;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  pwVar6 = _Str2 + -1;
  if (lVar10 != 0) {
    pwVar6 = _Str2;
  }
  *pwVar6 = L'\0';
  return;
}



===== PdcReferenceActivationStats @ 14002cf64 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcReferenceActivationStats(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 local_res8 [4];
  
  uVar2 = _DAT_fffff78000000008;
  PdcBSActivationStats = PdcBSActivationStats + 1;
  lVar1 = *param_1;
  if ((lVar1 != 0) &&
     (*(int *)(lVar1 + 0x14) = *(int *)(lVar1 + 0x14) + 1, *(int *)(lVar1 + 0x14) == 1)) {
    PdcpBeginActivatedPeriod(lVar1,uVar2,'\0');
  }
  PdcpActivationCount = PdcpActivationCount + 1;
  if (PdcpResiliencyActivationAccountingEnabled != '\0') {
    if (PdcResiliencyActivationStats < PdcpActivationCount) {
      PdcResiliencyActivationStats = PdcpActivationCount;
    }
    if (PdcpActivationCount == 1) {
      local_res8[0] = 0;
      _PdcResiliencyActivationStartTime = KeQueryInterruptTimePrecise(local_res8);
    }
  }
  if (param_1[1] != 0) {
    SleepstudyHelperBlockerActiveReference();
  }
  return;
}



===== PdcResumeActivationStats @ 14002cffc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcResumeActivationStats(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = _DAT_fffff78000000008;
  PdcpAccountingPaused = 0;
  for (puVar2 = PdcActivatorStatsList; (undefined8 **)puVar2 != &PdcActivatorStatsList;
      puVar2 = (undefined8 *)*puVar2) {
    if (0 < *(int *)((longlong)puVar2 + 0x14)) {
      PdcpBeginActivatedPeriod((longlong)puVar2,uVar1,'\x01');
    }
  }
  return;
}



===== PdcpBeginActivatedPeriod @ 14002d064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpBeginActivatedPeriod(longlong param_1,undefined8 param_2,char param_3)

{
  undefined8 uVar1;
  
  if ((PdcpAccountingPaused == '\0') || (param_3 != '\0')) {
    *(undefined8 *)(param_1 + 0x20) = param_2;
    uVar1 = (*DAT_1400150e0)();
    *(undefined8 *)(param_1 + 0x38) = uVar1;
    if ((0 < PdcBSActivationStats) && (DAT_1400129c8 == 0)) {
      DAT_1400129c8 = *(longlong *)(param_1 + 0x20);
      _DAT_140012dd0 = *(undefined8 *)(param_1 + 0x38);
    }
    if (param_3 != '\0') {
      return;
    }
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return;
}



===== PdcpCreateActivationBlockerHeirarchy @ 14002d0dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined **
PdcpCreateActivationBlockerHeirarchy
          (longlong param_1,short *param_2,short *param_3,longlong *param_4)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  short *psVar5;
  undefined **ppuVar6;
  short *psVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  longlong *local_b0;
  longlong local_98;
  longlong local_90;
  undefined8 local_88;
  short *psStack_80;
  longlong local_78;
  longlong lStack_70;
  ulonglong local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar1 = *(uint *)(param_1 + 0x10);
  local_90 = 0;
  if (uVar1 - 1 < 0x7c) {
    ppuVar6 = &PTR_u_Invalid_client_140031f70 + (ulonglong)uVar1 * 3;
  }
  else {
    ppuVar6 = (undefined **)&DAT_00000010;
  }
  local_98 = 0;
  uStack_60 = 0;
  local_68 = (ulonglong)uVar1;
  local_58 = 0x4dbd9a290e3a0f05;
  uStack_50 = 0x40626b86b1861fb7;
  local_78 = 0;
  lStack_70 = 0;
  if (*(longlong *)(param_1 + 0x48) == 0) {
    psVar7 = (short *)*ppuVar6;
    local_88 = 0;
    psStack_80 = (short *)0x0;
    if (psVar7 != (short *)0x0) {
      lVar8 = 0x7fff;
      psVar5 = psVar7;
      do {
        if (*psVar5 == 0) break;
        psVar5 = psVar5 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      ppuVar6 = (undefined **)-lVar8;
      if (lVar8 != 0) {
        sVar2 = (short)(0x7fff - lVar8) * 2;
        sVar3 = sVar2 + 2;
        ppuVar6 = (undefined **)CONCAT62((int6)((ulonglong)(0x7fff - lVar8) >> 0x10),sVar3);
        local_88._0_4_ = CONCAT22(sVar3,sVar2);
        local_88 = (ulonglong)(uint)local_88;
        psStack_80 = psVar7;
      }
      if (-1 < (int)-(uint)(lVar8 != 0)) goto LAB_14002d4c4;
    }
    ppuVar6 = (undefined **)0x0;
    if (DAT_140012858 != (code *)0x0) {
      local_b0 = &local_98;
      local_b8 = 6;
      ppuVar6 = (undefined **)
                (*DAT_140012858)(*(undefined8 *)(param_1 + 0x40),&local_58,&local_68,&local_88);
      if ((-1 < (int)ppuVar6) && (ppuVar6 = (undefined **)0x0, DAT_140012838 != (code *)0x0)) {
        ppuVar6 = (undefined **)(*DAT_140012838)(local_98,&local_90);
        if (-1 < (int)ppuVar6) {
          *(longlong *)(param_1 + 0x48) = local_90;
          goto LAB_14002d245;
        }
      }
    }
  }
  else {
    local_90 = *(longlong *)(param_1 + 0x48);
LAB_14002d245:
    lVar8 = local_90;
    local_98 = 0;
    local_78 = param_1;
    lStack_70 = local_90;
    if (param_2 == (short *)0x0) goto LAB_14002d4c4;
    lVar9 = 0x7fff;
    local_58 = local_68;
    uStack_50 = uStack_60;
    uStack_60._0_6_ = CONCAT24(*(undefined2 *)(param_1 + 0x50),(undefined4)uStack_60);
    local_88 = 0;
    psStack_80 = (short *)0x0;
    psVar7 = param_2;
    do {
      if (*psVar7 == 0) break;
      psVar7 = psVar7 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    ppuVar6 = (undefined **)-lVar9;
    if (lVar9 != 0) {
      sVar2 = (short)(0x7fff - lVar9) * 2;
      sVar3 = sVar2 + 2;
      ppuVar6 = (undefined **)CONCAT62((int6)((ulonglong)(0x7fff - lVar9) >> 0x10),sVar3);
      local_88._0_4_ = CONCAT22(sVar3,sVar2);
      local_88 = (ulonglong)(uint)local_88;
      psStack_80 = param_2;
    }
    if (-1 < (int)-(uint)(lVar9 != 0)) goto LAB_14002d4c4;
    ppuVar6 = (undefined **)0x0;
    if (DAT_140012858 != (code *)0x0) {
      local_b0 = &local_98;
      local_b8 = 6;
      ppuVar6 = (undefined **)
                (*DAT_140012858)(*(undefined8 *)(param_1 + 0x40),&local_58,&local_68,&local_88);
      if ((-1 < (int)ppuVar6) && (ppuVar6 = (undefined **)0x0, DAT_1400128a0 != (code *)0x0)) {
        ppuVar6 = (undefined **)(*DAT_1400128a0)(local_98,lVar8);
        if ((-1 < (int)ppuVar6) && (ppuVar6 = (undefined **)0x0, DAT_140012838 != (code *)0x0)) {
          ppuVar6 = (undefined **)(*DAT_140012838)(local_98,&local_90);
          if (-1 < (int)ppuVar6) {
            local_98 = 0;
            lStack_70 = local_90;
            if (DAT_140012888 != (code *)0x0) {
              (*DAT_140012888)(local_90,&local_68);
            }
            lVar8 = local_90;
            uVar4 = *(ushort *)(param_1 + 0x50);
            ppuVar6 = (undefined **)(ulonglong)uVar4;
            if (uStack_60._4_2_ == uVar4) {
              uVar4 = uVar4 + 1;
              ppuVar6 = (undefined **)(ulonglong)uVar4;
              *(ushort *)(param_1 + 0x50) = uVar4;
              if (uVar4 == 0) {
                *(undefined2 *)(param_1 + 0x50) = 1;
              }
            }
            if (param_3 != (short *)0x0) {
              lVar9 = 0x7fff;
              local_58 = local_68;
              uStack_50 = uStack_60;
              uStack_60 = CONCAT26(*(undefined2 *)(param_1 + 0x52),(undefined6)uStack_60);
              local_88 = 0;
              psStack_80 = (short *)0x0;
              psVar7 = param_3;
              do {
                if (*psVar7 == 0) break;
                psVar7 = psVar7 + 1;
                lVar9 = lVar9 + -1;
              } while (lVar9 != 0);
              ppuVar6 = (undefined **)-lVar9;
              if (lVar9 != 0) {
                sVar2 = (0x7fff - (short)lVar9) * 2;
                local_88._0_4_ = CONCAT22(sVar2 + 2,sVar2);
                local_88 = (ulonglong)(uint)local_88;
                psStack_80 = param_3;
              }
              if ((int)-(uint)(lVar9 != 0) < 0) {
                ppuVar6 = (undefined **)0x0;
                if (DAT_140012858 != (code *)0x0) {
                  local_b0 = &local_98;
                  local_b8 = 6;
                  ppuVar6 = (undefined **)
                            (*DAT_140012858)(*(undefined8 *)(param_1 + 0x40),&local_58,&local_68,
                                             &local_88);
                  if ((-1 < (int)ppuVar6) &&
                     (ppuVar6 = (undefined **)0x0, DAT_1400128a0 != (code *)0x0)) {
                    ppuVar6 = (undefined **)(*DAT_1400128a0)(local_98,lVar8);
                    if ((-1 < (int)ppuVar6) &&
                       (ppuVar6 = (undefined **)0x0, DAT_140012838 != (code *)0x0)) {
                      ppuVar6 = (undefined **)(*DAT_140012838)(local_98,&local_90);
                      if (-1 < (int)ppuVar6) {
                        local_98 = 0;
                        SleepstudyHelperDestroyBlocker();
                        lStack_70 = local_90;
                        if (DAT_140012888 != (code *)0x0) {
                          (*DAT_140012888)(local_90,&local_68);
                        }
                        uVar4 = *(ushort *)(param_1 + 0x52);
                        ppuVar6 = (undefined **)(ulonglong)uVar4;
                        if (uStack_60._6_2_ == uVar4) {
                          uVar4 = uVar4 + 1;
                          ppuVar6 = (undefined **)(ulonglong)uVar4;
                          *(ushort *)(param_1 + 0x52) = uVar4;
                          if (uVar4 == 0) {
                            *(undefined2 *)(param_1 + 0x52) = 1;
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
  if ((local_98 != 0) && (ppuVar6 = (undefined **)0x0, DAT_140012870 != (code *)0x0)) {
    ppuVar6 = (undefined **)(*DAT_140012870)();
  }
LAB_14002d4c4:
  *param_4 = local_78;
  param_4[1] = lStack_70;
  return ppuVar6;
}



===== PdcpEndActivatedPeriod @ 14002d4fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpEndActivatedPeriod(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if ((PdcpAccountingPaused == '\0') || (param_3 != '\0')) {
    uVar3 = param_2 - *(longlong *)(param_1 + 0x20);
    *(longlong *)(param_1 + 0x28) = *(longlong *)(param_1 + 0x28) + uVar3;
    *(undefined8 *)(param_1 + 0x20) = 0;
    if (*(ulonglong *)(param_1 + 0x30) < uVar3) {
      *(ulonglong *)(param_1 + 0x30) = uVar3;
    }
    lVar2 = (*DAT_1400150e0)();
    lVar1 = *(longlong *)(param_1 + 0x38);
    *(longlong *)(param_1 + 0x38) = lVar2;
    *(ulonglong *)(&DAT_1400129d8 + (ulonglong)*(uint *)(param_1 + 0x10) * 8) =
         *(longlong *)(&DAT_1400129d8 + (ulonglong)*(uint *)(param_1 + 0x10) * 8) +
         (uVar3 - (lVar2 - lVar1));
    if ((DAT_1400129c8 != 0) && ((param_3 != '\0' || (PdcBSActivationStats == 0)))) {
      DAT_1400129d0 = DAT_1400129d0 + ((param_2 - DAT_1400129c8) - (lVar2 - _DAT_140012dd0));
      DAT_1400129c8 = 0;
      _DAT_140012dd0 = lVar2;
    }
  }
  return;
}



===== PdcpPauseResiliencyActivationAccounting @ 14002d5cc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcpPauseResiliencyActivationAccounting(void)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  lVar2 = KeQueryInterruptTimePrecise(local_res8);
  auVar1._8_8_ = 0;
  auVar1._0_8_ = lVar2 - _PdcResiliencyActivationStartTime;
  uVar3 = (ulonglong)(lVar2 - _PdcResiliencyActivationStartTime) / 10;
  _DAT_140012df8 = _DAT_140012df8 + uVar3;
  if (DAT_140012de8 < uVar3) {
    DAT_140012de8 = uVar3;
  }
  if (uVar3 < DAT_140012df0) {
    DAT_140012df0 = uVar3;
  }
  DAT_140012e00._0_4_ = (int)DAT_140012e00 + 1;
  _PdcResiliencyActivationStartTime = 0;
  return SUB168(ZEXT816(0xcccccccccccccccd) * auVar1,0);
}



===== PdcPhaseDereference @ 14002d644 =====

void PdcPhaseDereference(ulonglong param_1,int param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  lVar2 = (longlong)(int)param_1;
  LOCK();
  (&DAT_1400312c4)[lVar2 * 0x56] = (&DAT_1400312c4)[lVar2 * 0x56] - param_2;
  UNLOCK();
  uVar3 = 0;
  uVar1 = param_1;
  if (((&DAT_1400312c4)[lVar2 * 0x56] == 0) && ((int)param_1 == DAT_14003100c)) {
    uVar1 = 0x10;
    PdcGetPolicyWorker(0x10);
    PdcCheckForWork();
    uVar3 = 1;
  }
  if (Microsoft_Windows_PDCEnableBits < '\0') {
    McTemplateU0uddt_EtwWriteTransfer
              (uVar1,&PDC_PHASE_DEREFERENCED,param_1 & 0xff,param_2,
               (char)(&DAT_1400312c4)[lVar2 * 0x56],uVar3);
  }
  return;
}



===== PdcPhaseReference @ 14002d6dc =====

void PdcPhaseReference(ulonglong param_1,int param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  lVar3 = (longlong)(int)param_1;
  iVar1 = (&DAT_1400312c4)[lVar3 * 0x56];
  LOCK();
  (&DAT_1400312c4)[lVar3 * 0x56] = (&DAT_1400312c4)[lVar3 * 0x56] + param_2;
  UNLOCK();
  uVar4 = 0;
  uVar2 = param_1;
  if ((iVar1 == 0) && ((int)param_1 <= DAT_14003100c)) {
    uVar2 = 0x10;
    PdcGetPolicyWorker(0x10);
    PdcCheckForWork();
    uVar4 = 1;
  }
  if (Microsoft_Windows_PDCEnableBits < '\0') {
    McTemplateU0uddt_EtwWriteTransfer
              (uVar2,&PDC_PHASE_REFERENCED,param_1 & 0xff,param_2,
               (char)(&DAT_1400312c4)[lVar3 * 0x56],uVar4);
  }
  return;
}



===== PdcPhasesAcknowledgeResiliencyClient @ 14002d770 =====

void PdcPhasesAcknowledgeResiliencyClient(int param_1,undefined4 param_2)

{
  *(undefined4 *)(&DAT_14003104c + (longlong)param_1 * 4) = param_2;
  if (DAT_140031048 != param_1) {
    return;
  }
  if (PdcResiliencyPhaseContext == 3) {
    if (0 < param_1) {
      DAT_140031048 = DAT_140031048 + -1;
      PdcpActivatePendingResiliencyClient();
      return;
    }
    PdcResiliencyPhaseContext = 1;
  }
  else {
    if (PdcResiliencyPhaseContext != 2) {
      return;
    }
    if (param_1 < 7) {
      DAT_140031048 = DAT_140031048 + 1;
      PdcpDeactivatePendingResiliencyClient();
      return;
    }
    PdcResiliencyPhaseContext = 0;
  }
  if (DAT_140031044 == 0x103) {
    DAT_140031044 = 0;
    PdcpPhaseNotificationCallback(0,0,0);
  }
  return;
}



===== PdcPhasesAddBlockerAccountingEntry @ 14002d804 =====

void PdcPhasesAddBlockerAccountingEntry
               (uint param_1,undefined8 param_2,undefined1 param_3,undefined8 *param_4)

{
  code *pcVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 local_18;
  
  if (param_1 < 9) {
    plVar3 = &DAT_1400313c8 + (longlong)(int)param_1 * 0x2b;
    if (*plVar3 != 0) {
      param_4[2] = param_2;
      local_18 = (ulonglong)CONCAT14(param_3,0xaaddaadd);
      param_4[3] = local_18;
      param_4[4] = 0;
      PoInitializeStopWatch
                (param_4 + 5,(longlong *)(&DAT_1400313d0 + (longlong)(int)param_1 * 0x158));
      puVar2 = (undefined8 *)plVar3[9];
      plVar3 = plVar3 + 8;
      if ((longlong *)*puVar2 != plVar3) {
        pcVar1 = (code *)swi(0x29);
        puVar2 = (undefined8 *)(*pcVar1)(3);
      }
      *param_4 = plVar3;
      param_4[1] = puVar2;
      *puVar2 = param_4;
      plVar3[1] = (longlong)param_4;
    }
  }
  return;
}



===== PdcPhasesGetCurrent @ 14002d888 =====

undefined4 PdcPhasesGetCurrent(void)

{
  return DAT_14003100c;
}



===== PdcPhasesInitialize @ 14002d898 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcPhasesInitialize(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  longlong lVar5;
  uint *puVar6;
  
  lVar5 = 9;
  if (param_1 == 0) {
    puVar4 = &DAT_140031308;
    do {
      if (*(longlong *)(puVar4 + -2) != 0) {
        PdcGetRegistryDwordValue
                  (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
                   *(longlong *)(puVar4 + -2),*puVar4,puVar4);
      }
      puVar1 = puVar4 + 0x40;
      *(undefined4 **)(puVar4 + 0x42) = puVar1;
      *(undefined4 **)puVar1 = puVar1;
      PoInitializeStopWatchCollection((undefined8 *)(puVar4 + 0x32));
      puVar4 = puVar4 + 0x56;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    DAT_1400313c8 = &GUID_SLEEPSTUDY_BLOCKER_NOCS_PHASE;
    _DAT_1400317d0 = &GUID_SLEEPSTUDY_BLOCKER_PLM_PHASE;
    _DAT_140031a80 = &GUID_SLEEPSTUDY_BLOCKER_DAM_PHASE;
    _DAT_140031928 = &GUID_SLEEPSTUDY_BLOCKER_MAINTENANCE_PHASE;
    _DAT_140031520 = &GUID_SLEEPSTUDY_BLOCKER_CONNECTION_PHASE;
    PdcPhasesResetAccounting();
    _DAT_14003104c = 0;
    uRam0000000140031054 = 0;
    _DAT_14003105c = 0;
    uRam0000000140031064 = 0;
    uVar3 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 != 0) {
      _DAT_140012974 = 0;
      _DAT_140012980 = 0;
      _DAT_140012968 = &PdcResiliencyV2PhaseContext;
      _PdcResiliencyV2PhaseContext = &PdcResiliencyV2PhaseContext;
      _DAT_140012978 = PdcpResiliencyRequestCompletionCallback;
      _DAT_140012970 = 7;
      PdcpResiliencyV2RequestInitiate((undefined8 *)&PdcResiliencyV2PhaseContext,0);
    }
  }
  else {
    puVar6 = (uint *)&DAT_1400312ec;
    do {
      puVar6[1] = 0;
      cVar2 = PdcpHasNotificationClients((int *)(puVar6 + -0xb));
      *puVar6 = (uint)(cVar2 != '\0');
      puVar6 = puVar6 + 0x56;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    PdcPhasesContext = 1;
  }
  return;
}



===== PdcPhasesLogPhaseBlockers @ 14002d9e8 =====

void PdcPhasesLogPhaseBlockers(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  puVar2 = &DAT_140031408;
  lVar3 = 9;
  do {
    for (puVar4 = (undefined8 *)*puVar2; puVar4 != puVar2; puVar4 = (undefined8 *)*puVar4) {
      PoQueryStopWatch(puVar4 + 5,&local_res8);
      local_28 = puVar4[3];
      uStack_20 = puVar4[4];
      local_18 = *(undefined8 *)puVar2[-8];
      uStack_10 = ((undefined8 *)puVar2[-8])[1];
      uVar1 = PdcGetScenarioInstanceId();
      PdcDiagTraceSleepStudyBlocker(uVar1,&local_18,&local_28,puVar4[2],(char)local_res8);
    }
    puVar2 = puVar2 + 0x2b;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



===== PdcPhasesQueryTotalTimes @ 14002da84 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcPhasesQueryTotalTimes(ulonglong *param_1)

{
  ulonglong uVar1;
  undefined1 auVar2 [16];
  longlong lVar3;
  ulonglong *puVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar6 = (longlong)DAT_14003100c;
  lVar3 = PdcGetInterruptTime();
  lVar5 = lVar3 - _DAT_140031018;
  _DAT_140031018 = lVar3;
  (&DAT_1400313b0)[lVar6 * 0x2b] = (&DAT_1400313b0)[lVar6 * 0x2b] + lVar5;
  puVar4 = &DAT_1400313b0;
  lVar3 = 9;
  do {
    uVar1 = *puVar4;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar1;
    puVar4 = puVar4 + 0x2b;
    *param_1 = uVar1 / 10000;
    param_1 = param_1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return SUB168(ZEXT816(0x346dc5d63886594b) * auVar2,0);
}



===== PdcPhasesResetAccounting @ 14002db04 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcPhasesResetAccounting(void)

{
  bool bVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  
  puVar4 = (undefined8 *)&DAT_1400313d0;
  lVar5 = 9;
  do {
    memset(puVar4 + -0x18,0,0xa8);
    puVar2 = puVar4;
    bVar1 = PoIsArmedStopWatchCollection((longlong)puVar4);
    if (bVar1) {
      PoUnarmStopWatchCollection(puVar2);
    }
    PoResetStopWatchCollection((longlong)puVar4);
    puVar2 = puVar4 + 7;
    for (puVar3 = (undefined8 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined8 *)*puVar3) {
      PoResetStopWatch((longlong)(puVar3 + 5));
    }
    if (bVar1) {
      PoArmStopWatchCollection(puVar4);
    }
    puVar4 = puVar4 + 0x2b;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  _DAT_140031018 = PdcGetInterruptTime();
  return;
}



===== PdcPhasesRundown @ 14002dba8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcPhasesRundown(void)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  
  lVar4 = (longlong)DAT_14003100c;
  lVar1 = PdcGetInterruptTime();
  uVar3 = lVar4 * 0x158;
  puVar7 = &DAT_1400313b0;
  lVar2 = lVar1 - _DAT_140031018;
  puVar5 = &DAT_1400312f8;
  lVar6 = 9;
  _DAT_140031018 = lVar1;
  (&DAT_1400313b0)[lVar4 * 0x2b] = (&DAT_1400313b0)[lVar4 * 0x2b] + lVar2;
  do {
    if (Microsoft_Windows_PDCEnableBits < '\0') {
      puVar7 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar7 >> 8),*(undefined1 *)(puVar5 + -0xe))
      ;
      McTemplateU0udtuqqqq_EtwWriteTransfer
                ((ulonglong)*(byte *)(puVar5 + -4),uVar3,puVar7,puVar5[-0xd],*(byte *)(puVar5 + -4),
                 *(undefined1 *)(puVar5 + -3),(char)puVar5[-2],(char)puVar5[-1],(char)*puVar5,
                 (char)puVar5[4]);
    }
    if (Microsoft_Windows_PDCEnableBits < '\0') {
      puVar7 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar7 >> 8),*(undefined1 *)(puVar5 + -0xe))
      ;
      uVar3 = *(ulonglong *)(puVar5 + 0xc) / 10000;
      McTemplateU0uqxxqxxx_EtwWriteTransfer
                (*(ulonglong *)(puVar5 + 0x12) / 10000,uVar3,puVar7,puVar5[6],(char)uVar3,
                 (char)(*(ulonglong *)(puVar5 + 0x12) / 10000),(char)puVar5[0x1a],
                 (char)(*(ulonglong *)(puVar5 + 0x20) / 10000),
                 (char)(*(ulonglong *)(puVar5 + 0x26) / 10000),
                 (char)(*(ulonglong *)(puVar5 + 0x2e) / 10000));
    }
    puVar5 = puVar5 + 0x56;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  return;
}



===== PdcpActivatePendingResiliencyClient @ 14002dcf4 =====

ulonglong PdcpActivatePendingResiliencyClient(void)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  
  uVar2 = (ulonglong)(int)DAT_140031048;
  uVar4 = 0;
  if (-1 < (int)DAT_140031048) {
    puVar5 = (undefined4 *)(&DAT_14003104c + uVar2 * 4);
    uVar3 = DAT_140031048;
    do {
      uVar1 = (uint)uVar2;
      if (uVar1 != 6) {
        DAT_140031048 = uVar1;
        uVar2 = PdcResiliencyClientDereference(0,uVar1,(ulonglong *)0x0);
        uVar4 = uVar2 & 0xffffffff;
        if ((int)uVar2 == 0x103) {
          DAT_140031044 = 0x103;
          return uVar4;
        }
        if (uVar3 < 8) {
          *puVar5 = 1;
        }
      }
      uVar3 = uVar3 - 1;
      puVar5 = puVar5 + -1;
      uVar2 = (ulonglong)(uVar1 - 1);
    } while (-1 < (int)(uVar1 - 1));
    if ((int)uVar4 != 0) {
      return uVar4;
    }
  }
  PdcResiliencyPhaseContext = 1;
  if (DAT_140031044 == 0x103) {
    DAT_140031044 = 0;
    PdcpPhaseNotificationCallback(0,0,0);
  }
  return uVar4;
}



===== PdcpActivatePhaseNotification @ 14002ddb4 =====

uint PdcpActivatePhaseNotification(int *param_1,char param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  
  iVar2 = *param_1;
  uVar3 = 0;
  if (PdcpPlatformAoAcCapable != '\0') {
    if (iVar2 == 9) {
      return 0;
    }
    uVar1 = *(uint *)(&DAT_14000d278 + (longlong)iVar2 * 4);
    if (uVar1 != 6) {
      do {
        iVar2 = PdcSequenceId + 1;
        PdcSequenceId = iVar2;
      } while (iVar2 == 0);
      param_1[0xd] = iVar2;
      if (param_2 != '\0') {
        uVar3 = param_1[0xe];
      }
      uVar4 = PdcActivateNotification(uVar1,0,iVar2,0x14002e460,uVar3,param_2);
      return (uint)uVar4;
    }
  }
  if (iVar2 == 8) {
    uVar3 = PdcpResiliencyPhaseActivationHandler(param_2);
    return uVar3;
  }
  return 0;
}



===== PdcpDeactivatePendingResiliencyClient @ 14002de38 =====

ulonglong PdcpDeactivatePendingResiliencyClient(void)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  
  uVar2 = (ulonglong)(int)DAT_140031048;
  uVar4 = 0;
  if ((int)DAT_140031048 < 8) {
    puVar5 = (undefined4 *)(&DAT_14003104c + uVar2 * 4);
    uVar3 = DAT_140031048;
    do {
      uVar1 = (uint)uVar2;
      if (uVar1 != 6) {
        DAT_140031048 = uVar1;
        uVar2 = PdcResiliencyClientReference(0,uVar1,(ulonglong *)0x0);
        uVar4 = uVar2 & 0xffffffff;
        if ((int)uVar2 == 0x103) {
          DAT_140031044 = 0x103;
          return uVar4;
        }
        if (uVar3 < 8) {
          *puVar5 = 0;
        }
      }
      uVar2 = (ulonglong)(uVar1 + 1);
      uVar3 = uVar3 + 1;
      puVar5 = puVar5 + 1;
    } while ((int)uVar3 < 8);
    if ((int)uVar4 != 0) {
      return uVar4;
    }
  }
  PdcResiliencyPhaseContext = 0;
  if (DAT_140031044 == 0x103) {
    DAT_140031044 = 0;
    PdcpPhaseNotificationCallback(0,0,0);
  }
  return uVar4;
}



===== PdcpDisengagePhase @ 14002def8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PdcpDisengagePhase(int *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  param_1[0x28] = param_1[0x28] + 1;
  uVar4 = 0;
  cVar2 = PdcpHasNotificationClients(param_1);
  if (cVar2 == '\0') {
LAB_14002df91:
    if ((int)uVar4 == 0x103) {
      return uVar4;
    }
  }
  else {
    iVar1 = param_1[0xb];
    if (iVar1 == 4) {
LAB_14002df71:
      PdcpSetPhaseNotificationsState((undefined1 *)param_1,2,0x103);
      uVar3 = PdcpActivatePhaseNotification(param_1,'\0');
      uVar4 = (ulonglong)uVar3;
      if (uVar3 != 0) goto LAB_14002df91;
    }
    else {
      if (iVar1 == 3) {
        PdcpSetPhaseNotificationsState((undefined1 *)param_1,5,0x103);
        iVar1 = *param_1;
        if (PdcpPlatformAoAcCapable == '\0') {
LAB_14002df68:
          if (iVar1 == 8) goto LAB_14002df71;
        }
        else if (iVar1 != 9) {
          if (*(uint *)(&DAT_14000d278 + (longlong)iVar1 * 4) == 6) goto LAB_14002df68;
          uVar4 = PdcControlNotification(*(uint *)(&DAT_14000d278 + (longlong)iVar1 * 4));
          uVar4 = uVar4 & 0xffffffff;
        }
        if ((int)uVar4 != 0) goto LAB_14002df91;
        goto LAB_14002df71;
      }
      if (iVar1 != 6) {
        if ((iVar1 == 2) || (iVar1 == 5)) {
          return 0x103;
        }
        goto LAB_14002df95;
      }
    }
    PdcpSetPhaseNotificationsState((undefined1 *)param_1,1,0);
  }
LAB_14002df95:
  if ((char)param_1[10] != '\0') {
    uVar5 = PdcGetInterruptTime();
    param_1[0x2c] = 0;
    param_1[0x2d] = 0;
    *(undefined8 *)(param_1 + 0x2a) = uVar5;
    if (*(code **)(param_1 + 8) != (code *)0x0) {
      (**(code **)(param_1 + 8))(0);
    }
    *(undefined1 *)(param_1 + 10) = 0;
    lVar6 = PdcGetInterruptTime();
    *(longlong *)(param_1 + 0x2c) = lVar6;
    *(longlong *)(param_1 + 0x2e) =
         *(longlong *)(param_1 + 0x2e) + (lVar6 - *(longlong *)(param_1 + 0x2a));
  }
  uVar3 = PdcpDisengagePoCallback((longlong)param_1);
  if (uVar3 == 0x103) {
    Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline();
  }
  return (ulonglong)uVar3;
}



===== PdcpDisengagePoCallback @ 14002e034 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PdcpDisengagePoCallback(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x18) != 2) {
    do {
      iVar4 = PdcSequenceId + 1;
      PdcSequenceId = iVar4;
    } while (iVar4 == 0);
    uVar2 = PdcGetInterruptTime();
    *(undefined4 *)(param_1 + 0x18) = 2;
    *(int *)(param_1 + 0x1c) = iVar4;
    *(undefined8 *)(param_1 + 0xe0) = 0;
    *(undefined8 *)(param_1 + 0xd8) = uVar2;
    if ((_DAT_140031010 == 4) && (DAT_14003100c == 6)) {
      PdcpQueryReasonMaintenancePhaseChange();
    }
    uVar3 = Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 != 0) {
      PdcReleaseLock();
    }
    iVar1 = PdcPoNotifyPhaseEntryExit();
    uVar3 = Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      if (iVar1 == 0x103) {
        return 0x103;
      }
      PdcpSetPhasePoCallbackState(param_1,0,0);
      return iVar1;
    }
    PdcAcquireLock();
    if (iVar1 != 0) {
      return iVar1;
    }
    PdcPhasesAcknowledgePoCallback(iVar4);
  }
  return 0x103;
}



===== PdcpEngagePhase @ 14002e11c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PdcpEngagePhase(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  
  piVar1 = param_1 + 10;
  uVar6 = 0;
  cVar2 = PdcpHasNotificationClients(param_1);
  if (cVar2 == '\0') {
    cVar2 = (char)*piVar1;
  }
  else {
    cVar2 = param_1[0xb] == 4;
  }
  if (cVar2 == '\0') {
    param_1[0x14] = param_1[0x14] + 1;
    PdcpSetPhaseTargetBlockingState(param_1,'\0');
    iVar3 = PdcpEngagePoCallback((longlong)param_1);
    if (iVar3 == 0x103) {
      Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline();
      uVar6 = 0x103;
    }
    else {
      if ((char)*piVar1 == '\0') {
        uVar4 = PdcGetInterruptTime();
        param_1[0x18] = 0;
        param_1[0x19] = 0;
        *(undefined8 *)(param_1 + 0x16) = uVar4;
        if (*(code **)(param_1 + 8) != (code *)0x0) {
          (**(code **)(param_1 + 8))(1);
        }
        *(char *)piVar1 = '\x01';
        lVar5 = PdcGetInterruptTime();
        *(longlong *)(param_1 + 0x18) = lVar5;
        *(longlong *)(param_1 + 0x1a) =
             *(longlong *)(param_1 + 0x1a) + (lVar5 - *(longlong *)(param_1 + 0x16));
      }
      uVar6 = 0;
      cVar2 = PdcpHasNotificationClients(param_1);
      if (cVar2 != '\0') {
        iVar3 = param_1[0xb];
        if (iVar3 == 1) {
          PdcpSetPhaseNotificationsState((undefined1 *)param_1,3,0x103);
          uVar6 = PdcpActivatePhaseNotification(param_1,'\x01');
          if (uVar6 == 0) {
            PdcpSetPhaseNotificationsState((undefined1 *)param_1,4,0);
          }
        }
        else if (((iVar3 - 2U & 0xfffffffc) == 0) && (iVar3 != 4)) {
          uVar6 = 0x103;
        }
      }
    }
  }
  return uVar6;
}



===== PdcpEngagePoCallback @ 14002e234 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PdcpEngagePoCallback(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x18) == 1) {
    return 0;
  }
  if (*(int *)(param_1 + 0x18) != 3) {
    do {
      iVar4 = PdcSequenceId + 1;
      PdcSequenceId = iVar4;
    } while (iVar4 == 0);
    uVar2 = PdcGetInterruptTime();
    *(undefined4 *)(param_1 + 0x18) = 3;
    *(int *)(param_1 + 0x1c) = iVar4;
    *(undefined8 *)(param_1 + 0x90) = 0;
    *(undefined8 *)(param_1 + 0x88) = uVar2;
    if ((_DAT_140031010 == 4) && (DAT_14003100c == 3)) {
      PdcpQueryReasonMaintenancePhaseChange();
    }
    uVar3 = Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 != 0) {
      PdcReleaseLock();
    }
    iVar1 = PdcPoNotifyPhaseEntryExit();
    uVar3 = Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      if (iVar1 == 0x103) {
        return 0x103;
      }
      PdcpSetPhasePoCallbackState(param_1,1,0);
      return iVar1;
    }
    PdcAcquireLock();
    if (iVar1 != 0) {
      return iVar1;
    }
    PdcPhasesAcknowledgePoCallback(iVar4);
  }
  return 0x103;
}



===== PdcpHasNotificationClients @ 14002e320 =====

undefined1 PdcpHasNotificationClients(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (PdcpPlatformAoAcCapable != '\0') {
    if (iVar1 == 9) {
      return 0;
    }
    if (*(int *)(&DAT_14000d278 + (longlong)iVar1 * 4) != 6) {
      return 1;
    }
  }
  if (iVar1 == 8) {
    return 1;
  }
  return 0;
}



===== PdcpMaintenancePhaseHandler @ 14002e360 =====

void PdcpMaintenancePhaseHandler(void)

{
  undefined8 *puVar1;
  undefined8 in_R9;
  
  PdcPrint(2,"%s:TaskClients received acknowledgement\n","PdcAcknowledgePendingTaskClients",in_R9);
  for (puVar1 = PdcTaskClients; (undefined8 **)puVar1 != &PdcTaskClients;
      puVar1 = (undefined8 *)*puVar1) {
    if (*(int *)(puVar1 + 0x6b) == 0x103) {
      *(undefined4 *)(puVar1 + 0x6b) = 0;
      PdcpTaskClientAcknowledge((longlong)puVar1,0);
    }
  }
  return;
}



===== PdcpNoCsPhaseHandler @ 14002e3d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpNoCsPhaseHandler(char param_1,undefined8 param_2)

{
  undefined7 uVar1;
  undefined8 local_res10 [3];
  
  uVar1 = (undefined7)((ulonglong)param_2 >> 8);
  local_res10[0] = 0;
  PdcAcquireRwLockExclusive(0x140014d80);
  DAT_140014dc8 = param_1 == '\0';
  if (param_1 == '\0') {
    DAT_140014dd0 = KeQueryInterruptTimePrecise(local_res10);
  }
  else {
    DAT_140014dd0 = 0;
  }
  PdcGroupEnable((uint *)0x5,CONCAT71(uVar1,DAT_140014df0) & 0xffffffffffffff01);
  PdcpHandleSystemForegroundGroupStateChange();
  PdcReleaseRwLockExclusive(0x140014d80);
  if (param_1 == '\0') {
    (*DAT_1400150b0)();
  }
  return;
}



===== PdcpPhaseNotificationCallback @ 14002e460 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PdcpPhaseNotificationCallback(undefined8 param_1,undefined1 param_2,uint param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  int *piVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStackY_a8 [32];
  int local_78;
  uint local_74;
  undefined4 local_70 [2];
  undefined8 local_68 [4];
  int *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar1 = (longlong)DAT_14003100c;
  lVar3 = lVar1 * 0x158;
  piVar4 = (int *)(&PdcPhasesEx + lVar3);
  uVar6 = (ulonglong)(uint)(&DAT_1400312f4)[lVar1 * 0x56];
  uVar5 = (ulonglong)(uint)(&DAT_1400312f0)[lVar1 * 0x56];
  PdcDiagTracePhaseNotificationCallback
            (lVar1,(ulonglong)*(uint *)(&DAT_1400312ec + lVar3),uVar5,
             (char)(&DAT_1400312f4)[lVar1 * 0x56],(char)param_3,param_2);
  if ((int)param_3 < 0) {
    if (5 < DAT_140031288) {
      local_78 = DAT_14003100c;
      local_48 = &local_78;
      local_40 = 4;
      local_38 = &local_74;
      local_70[0] = *(undefined4 *)(&DAT_1400312ec + lVar3);
      local_28 = local_70;
      local_30 = 4;
      local_20 = 4;
      local_74 = param_3;
      _tlgWriteTransfer_EtwWriteTransfer(0x140031288,&DAT_14000f26b,uVar5,uVar6,5,local_68);
    }
    PdcpSetPhaseNotificationsState((undefined1 *)piVar4,6,(ulonglong)param_3);
    if (DAT_140031020 != '\x01') {
      PdcGroupRequest((uint *)0x1,'\x01');
      DAT_140031020 = '\x01';
    }
  }
  else {
    if (*(int *)(&DAT_1400312ec + lVar3) == 5) {
      PdcpSetPhaseNotificationsState((undefined1 *)piVar4,2,0x103);
      param_3 = PdcpActivatePhaseNotification(piVar4,'\0');
      if (param_3 == 0x103) goto LAB_14002e5aa;
    }
    if (*(int *)(&DAT_1400312ec + lVar3) == 3) {
      iVar2 = 4;
    }
    else {
      if (*(int *)(&DAT_1400312ec + lVar3) != 2) goto LAB_14002e5aa;
      iVar2 = 1;
    }
    PdcpSetPhaseNotificationsState((undefined1 *)piVar4,iVar2,(ulonglong)param_3);
  }
LAB_14002e5aa:
  PdcGetPolicyWorker(0x10);
  PdcCheckForWork();
  return 0;
}



===== PdcpQueryReasonMaintenancePhaseChange @ 14002e5e4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint PdcpQueryReasonMaintenancePhaseChange(void)

{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined8 *puVar6;
  uint uVar7;
  
  uVar4 = 0;
  piVar3 = &DAT_1400121a8;
  iVar5 = 0;
  do {
    if (((piVar3[-2] == _DAT_140031010) && (*(char *)((longlong)piVar3 + -3) != '\0')) &&
       (0 < *piVar3)) break;
    iVar5 = iVar5 + 1;
    piVar3 = piVar3 + 0x28;
  } while ((longlong)piVar3 < 0x140012568);
  if (iVar5 == 6) {
    return 0x1000000;
  }
  uVar7 = 0x8010;
  puVar6 = PdcTaskClients;
  if (iVar5 != 4) {
    uVar7 = 0x10;
  }
  while( true ) {
    if ((undefined8 **)puVar6 == &PdcTaskClients) {
      return 0x1000000;
    }
    uVar1 = *(uint *)(puVar6 + 5);
    if (uVar1 - 1 < 0x7c) {
      puVar2 = &PdcClientInfo + (ulonglong)uVar1 * 6;
    }
    else {
      puVar2 = (uint *)0x0;
    }
    if (((uVar7 & *puVar2) == uVar7) && (0 < *(int *)((longlong)puVar6 + 0x2c))) break;
    puVar6 = (undefined8 *)*puVar6;
  }
  if (uVar1 == 0x7d) {
    return 0x1000000;
  }
  puVar2 = &SessionTransitionReasonMap;
  do {
    if (*puVar2 == uVar1) {
      return *(uint *)(&DAT_1400125d4 + (ulonglong)uVar4 * 8) & 0xffffff | 0x1000000;
    }
    uVar4 = uVar4 + 1;
    puVar2 = puVar2 + 2;
  } while (uVar4 < 0xe);
  return 0x1000000;
}



===== PdcpRecordPhaseTransition @ 14002e6d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpRecordPhaseTransition(ulonglong param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined *puVar8;
  ulonglong uVar9;
  
  lVar6 = (longlong)(int)param_2;
  iVar3 = (int)param_1;
  lVar7 = (longlong)iVar3;
  uVar4 = param_1;
  lVar2 = PdcGetInterruptTime();
  uVar9 = lVar7 * 0x158;
  if (iVar3 < (int)param_2) {
    if ((&DAT_1400313b8)[lVar6 * 0x2b] == 0) {
      uVar4 = lVar2 - _DAT_140015140;
      (&DAT_1400313b8)[lVar6 * 0x2b] = uVar4;
    }
  }
  else if (((int)param_2 < iVar3) && ((&DAT_1400313c0)[lVar6 * 0x2b] == 0)) {
    uVar4 = lVar2 - DAT_140015148;
    (&DAT_1400313c0)[lVar6 * 0x2b] = uVar4;
  }
  (&DAT_1400313b0)[lVar7 * 0x2b] = (&DAT_1400313b0)[lVar7 * 0x2b] + (lVar2 - _DAT_140031018);
  uVar1 = (&DAT_1400312f0)[lVar7 * 0x56];
  _DAT_140031018 = lVar2;
  if (Microsoft_Windows_PDCEnableBits < '\0') {
    uVar9 = (ulonglong)uVar1;
    McTemplateU0qq_EtwWriteTransfer(uVar4,&PDC_CS_EXIT_PHASE,param_1 & 0xffffffff,uVar1);
  }
  PdcPrint(2,"############################%s#################################################\n",
           (&ModernStandbyTransitions)[DAT_140015138],uVar9);
  puVar8 = (&PhaseNames)[lVar7];
  uVar4 = (ulonglong)uVar1;
  PdcPrint(2,"Exiting %s phase with status=%08lx\n",puVar8,uVar4);
  uVar5 = 2;
  PdcPrint(2,
           "####################################################################################\n",
           puVar8,uVar4);
  if (Microsoft_Windows_PDCEnableBits < '\0') {
    uVar4 = 0;
    McTemplateU0qq_EtwWriteTransfer(uVar5,&PDC_CS_ENTER_PHASE,(ulonglong)param_2,0);
  }
  PdcPrint(2,"############################%s#################################################\n",
           (&ModernStandbyTransitions)[DAT_140015138],uVar4);
  puVar8 = (&PhaseNames)[lVar6];
  PdcPrint(2," Entering %s phase\n",puVar8,uVar4);
  PdcPrint(2,
           "####################################################################################\n",
           puVar8,uVar4);
  PdcRecordLogEntry(0x16);
  if (DAT_1400150e8 != (code *)0x0) {
    (*DAT_1400150e8)(param_1 & 0xffffffff,0);
    if (DAT_1400150e8 != (code *)0x0) {
      (*DAT_1400150e8)(param_2,1);
    }
  }
  return;
}



===== PdcpResiliencyNotificationPhaseHandler @ 14002e8a0 =====

void PdcpResiliencyNotificationPhaseHandler(char param_1)

{
  undefined4 local_res10;
  undefined4 local_res14;
  
  local_res14 = 0xffffffff;
  local_res10 = 1;
  if (param_1 != '\0') {
    local_res10 = 3;
  }
  ZwUpdateWnfStateData(&WNF_SEB_RESILIENCY_NOTIFICATION_PHASE,&local_res10,8,0,0,0,0);
  return;
}



===== PdcpResiliencyPhaseActivationHandler @ 14002e8f8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint PdcpResiliencyPhaseActivationHandler(char param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined8 local_res10;
  
  if (param_1 == '\0') {
    if (PdcpActivationCount != 0) {
      PdcpPauseResiliencyActivationAccounting();
    }
    PdcpResiliencyActivationAccountingEnabled = 0;
    uVar1 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar1 == 0) {
      PdcResiliencyPhaseContext = 2;
      uVar1 = PdcpDeactivatePendingResiliencyClient();
      uVar5 = (uint)uVar1;
    }
    else {
      uVar5 = PdcpResiliencyV2RequestInitiate((undefined8 *)&PdcResiliencyV2PhaseContext,0);
    }
    PdcPauseActivationStats();
    for (puVar4 = PdcActivators; (undefined8 **)puVar4 != &PdcActivators;
        puVar4 = (undefined8 *)*puVar4) {
      if (*(char *)((longlong)puVar4 + 0xc4) != '\0') {
        PdcpCancelActivatorWatchdog((longlong)puVar4);
      }
    }
  }
  else {
    uVar1 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar1 == 0) {
      PdcResiliencyPhaseContext = 3;
      uVar1 = PdcpActivatePendingResiliencyClient();
      uVar5 = (uint)uVar1;
    }
    else {
      PdcpResiliencyV2RequestCancel((longlong *)&PdcResiliencyV2PhaseContext,0);
      uVar1 = Feature_LocklessPhasesPoCallout__private_IsEnabledDeviceUsageNoInline();
      uVar5 = ~-(uint)((int)uVar1 != 0) & 0x103;
    }
    for (puVar4 = PdcActivators; (undefined8 **)puVar4 != &PdcActivators;
        puVar4 = (undefined8 *)*puVar4) {
      if (*(char *)((longlong)puVar4 + 0xc4) != '\0') {
        PdcpSetActivatorWatchdog((longlong)puVar4);
      }
    }
    DAT_140012df0 = 0xffffffffffffffff;
    _PdcResiliencyActivationStats = 0;
    DAT_140012de8 = 0;
    _DAT_140012df8 = 0;
    DAT_140012e00 = 0;
    PdcpResiliencyActivationAccountingEnabled = 1;
    if (PdcpActivationCount != 0) {
      local_res10 = 0;
      _PdcResiliencyActivationStartTime = KeQueryInterruptTimePrecise(&local_res10);
      _PdcResiliencyActivationStats = CONCAT44(PdcResiliencyActivationStats_4,PdcpActivationCount);
    }
    PdcResumeActivationStats();
    uVar1 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
    lVar2 = 8;
    if ((int)uVar1 == 0) {
      puVar3 = &DAT_140013cc0;
      do {
        *(undefined8 *)(puVar3 + -4) = 0;
        *puVar3 = 0;
        puVar3 = puVar3 + 0x1c;
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
    }
    else {
      puVar3 = &DAT_140013788;
      do {
        *(undefined8 *)(puVar3 + -4) = 0;
        *puVar3 = 0;
        puVar3 = puVar3 + 0x1c;
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
    }
  }
  return uVar5;
}



===== PdcpResiliencyPhaseHandler @ 14002eab0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpResiliencyPhaseHandler(char param_1,char *param_2,undefined8 param_3,longlong param_4)

{
  undefined *puVar1;
  
  if (param_1 == '\0') {
    PdcSetGlobalActivatorsVeto('\0',param_2,param_3,param_4);
  }
  else {
    if (DAT_140015160._1_1_ != '\0') {
      PdcpStopStandbyEntryPerftrack();
    }
    PdcAcquireRwLockExclusive(0x140014d80);
    if (DAT_140014db0 != 0) {
      PdcRecordLogEntry(0x10);
      param_2 = "PDC: One-way entry complete\n";
      PdcPrint(2,"PDC: One-way entry complete\n",param_3,param_4);
      DAT_140014db0 = 1;
    }
    puVar1 = &PdcMonitorLock;
    PdcReleaseRwLockExclusive(0x140014d80);
    PdcAttemptGlobalActivatorsVeto(puVar1,param_2,param_3,param_4);
  }
  if (param_1 == '\0') {
    DAT_140012dc8 = DAT_140012dc8 + (_DAT_fffff78000000008 - _DAT_140012dc0);
  }
  _DAT_140012dc0 = _DAT_fffff78000000008;
  return;
}



===== PdcpSetPhaseNotificationsState @ 14002eb54 =====

void PdcpSetPhaseNotificationsState(undefined1 *param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  uVar3 = (undefined4)param_3;
  lVar2 = PdcGetInterruptTime();
  iVar1 = *(int *)(param_1 + 0x2c);
  *(int *)(param_1 + 0x2c) = param_2;
  *(undefined4 *)(param_1 + 0x30) = uVar3;
  if (param_2 == 3) {
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(longlong *)(param_1 + 0x70) = lVar2;
    goto LAB_14002ec00;
  }
  if (param_2 == 4) {
LAB_14002eb92:
    *(longlong *)(param_1 + 0x78) = lVar2;
    lVar2 = lVar2 - *(longlong *)(param_1 + 0x70);
    *(longlong *)(param_1 + 0x80) = *(longlong *)(param_1 + 0x80) + lVar2;
    goto LAB_14002ec00;
  }
  if (param_2 == 2) {
    if (iVar1 != 4) goto LAB_14002ec00;
LAB_14002ebf1:
    *(undefined8 *)(param_1 + 200) = 0;
    *(longlong *)(param_1 + 0xc0) = lVar2;
  }
  else {
    if (param_2 != 1) {
      if (param_2 != 6) {
        if (param_2 != 5) goto LAB_14002ec00;
        *(longlong *)(param_1 + 0x80) =
             *(longlong *)(param_1 + 0x80) + (lVar2 - *(longlong *)(param_1 + 0x70));
        *(longlong *)(param_1 + 0x78) = lVar2;
        goto LAB_14002ebf1;
      }
      if (iVar1 == 3) goto LAB_14002eb92;
      if (iVar1 != 2) goto LAB_14002ec00;
    }
    *(longlong *)(param_1 + 200) = lVar2;
    lVar2 = lVar2 - *(longlong *)(param_1 + 0xc0);
    *(longlong *)(param_1 + 0xd0) = *(longlong *)(param_1 + 0xd0) + lVar2;
  }
LAB_14002ec00:
  if (Microsoft_Windows_PDCEnableBits < '\0') {
    McTemplateU0uuu_EtwWriteTransfer
              (lVar2,&PDC_PHASE_NOTIFICATIONS_STATE_CHANGED,
               CONCAT44((int)((ulonglong)param_3 >> 0x20),
                        CONCAT31((int3)((ulonglong)param_3 >> 8),*param_1)),(char)iVar1,
               (char)param_2);
  }
  return;
}



===== PdcpSetPhasePoCallbackState @ 14002ec38 =====

void PdcpSetPhasePoCallbackState(longlong param_1,int param_2,undefined4 param_3)

{
  longlong lVar1;
  
  lVar1 = PdcGetInterruptTime();
  *(int *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  if (param_2 == 0) {
    *(longlong *)(param_1 + 0xe0) = lVar1;
    *(longlong *)(param_1 + 0xe8) =
         *(longlong *)(param_1 + 0xe8) + (lVar1 - *(longlong *)(param_1 + 0xd8));
  }
  else if (param_2 == 1) {
    *(longlong *)(param_1 + 0x90) = lVar1;
    *(longlong *)(param_1 + 0x98) =
         *(longlong *)(param_1 + 0x98) + (lVar1 - *(longlong *)(param_1 + 0x88));
  }
  else if (param_2 == 2) {
    *(undefined8 *)(param_1 + 0xe0) = 0;
    *(longlong *)(param_1 + 0xd8) = lVar1;
  }
  else if (param_2 == 3) {
    *(undefined8 *)(param_1 + 0x90) = 0;
    *(longlong *)(param_1 + 0x88) = lVar1;
  }
  return;
}



===== PdcpSetPhaseTargetBlockingState @ 14002ecd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpSetPhaseTargetBlockingState(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  if ((char)param_1[2] != param_2) {
    if (param_2 == '\0') {
      PoUnarmStopWatchCollection((undefined8 *)(param_1 + 0x44));
    }
    else {
      PoArmStopWatchCollection((undefined8 *)(param_1 + 0x44));
    }
    *(char *)(param_1 + 2) = param_2;
    if (*(code **)(param_1 + 4) != (code *)0x0) {
      (**(code **)(param_1 + 4))(param_2);
    }
    iVar1 = *param_1;
    uVar3 = 0;
    do {
      piVar2 = PdcpGetGroup(uVar3);
      if ((piVar2 != (int *)0x0) && (*piVar2 == iVar1)) {
        PdcpGroupBlockingConditionsChanged(piVar2);
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 6);
  }
  return;
}



===== PdcpShellPhaseHandler @ 14002ed50 =====

void PdcpShellPhaseHandler(char param_1)

{
  char local_res10 [8];
  undefined4 local_res18;
  undefined4 local_res1c;
  
  if (PdcpPlatformAoAcCapable != '\0') {
    local_res10[0] = param_1;
    ZwUpdateWnfStateData(&WNF_PO_PDC_SHELL_PHASE_NOTIFICATION,local_res10,1,0,0,0,0);
    local_res1c = 0xffffffff;
    local_res18 = 1;
    if (param_1 != '\0') {
      local_res18 = 3;
    }
    ZwUpdateWnfStateData(&WNF_SEB_SHELL_PHASE,&local_res18,8,0,0,0,0);
  }
  return;
}



===== PdcGroupEnable @ 14002edec =====

void PdcGroupEnable(uint *param_1,ulonglong param_2)

{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  ulonglong uVar7;
  
  uVar7 = (ulonglong)param_1 & 0xffffffff;
  uVar4 = param_2;
  puVar2 = PdcpGetGroup((uint)param_1);
  uVar5 = 0;
  uVar6 = 0;
  if (((puVar2 != (uint *)0x0) && ((char)puVar2[1] == '\0')) &&
     (*(char *)((longlong)puVar2 + 5) != (char)param_2)) {
    cVar3 = (char)uVar4;
    uVar6 = 1;
    uVar1 = puVar2[2];
    uVar4 = (ulonglong)uVar1;
    if (cVar3 == '\0') {
      if (0 < (int)uVar1) {
        PdcPhaseDereference((ulonglong)*puVar2,uVar1);
      }
    }
    else {
      if (0 < (int)uVar1) {
        PdcPhaseReference((ulonglong)*puVar2,uVar1);
      }
      uVar5 = 1;
    }
    *(undefined1 *)((longlong)puVar2 + 5) = uVar5;
    PdcpGroupBlockingConditionsChanged((int *)puVar2);
    param_1 = puVar2;
  }
  if ((DAT_140015c03 & 2) != 0) {
    McTemplateU0qtt_EtwWriteTransfer(param_1,uVar4,uVar7,(uint)param_2 & 0xff,uVar6);
  }
  return;
}



===== PdcGroupRequest @ 14002ee94 =====

void PdcGroupRequest(uint *param_1,char param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  
  iVar5 = (-(uint)(param_2 != '\0') & 2) - 1;
  puVar2 = param_1;
  puVar1 = PdcpGetGroup((uint)param_1);
  uVar4 = 0;
  if ((puVar1 != (uint *)0x0) && (*(char *)((longlong)puVar1 + 6) == '\0')) {
    LOCK();
    puVar1[2] = puVar1[2] + iVar5;
    UNLOCK();
    if (*(char *)((longlong)puVar1 + 5) != '\0') {
      if (param_2 == '\0') {
        iVar3 = -iVar5;
        if (-iVar5 < 0) {
          iVar3 = iVar5;
        }
        PdcPhaseDereference((ulonglong)*puVar1,iVar3);
      }
      else {
        PdcPhaseReference((ulonglong)*puVar1,iVar5);
      }
    }
    PdcpGroupBlockingConditionsChanged((int *)puVar1);
    uVar4 = 1;
    puVar2 = puVar1;
  }
  if ((DAT_140015c03 & 2) != 0) {
    McTemplateU0qdt_EtwWriteTransfer(puVar2,uVar4,(ulonglong)param_1 & 0xffffffff,iVar5,(char)uVar4)
    ;
  }
  return;
}



===== PdcpGroupBlockingConditionsChanged @ 14002ef28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpGroupBlockingConditionsChanged(int *param_1)

{
  longlong lVar1;
  char cVar2;
  
  cVar2 = '\0';
  if ((*(char *)((longlong)param_1 + 5) != '\0') && (0 < param_1[2])) {
    cVar2 = '\0';
    if ((&DAT_1400312c8)[(longlong)*param_1 * 0x158] != '\0') {
      cVar2 = '\x01';
    }
  }
  if ((char)param_1[6] != cVar2) {
    if (*(code **)(param_1 + 4) != (code *)0x0) {
      (**(code **)(param_1 + 4))(cVar2);
    }
    *(char *)(param_1 + 6) = cVar2;
    lVar1 = PdcGetInterruptTime();
    if (cVar2 == '\0') {
      *(longlong *)(param_1 + 10) = lVar1;
      *(longlong *)(param_1 + 0xc) =
           *(longlong *)(param_1 + 0xc) + (lVar1 - *(longlong *)(param_1 + 8));
      PoPauseStopWatch((longlong *)(param_1 + 0x18));
    }
    else {
      param_1[10] = 0;
      param_1[0xb] = 0;
      *(longlong *)(param_1 + 8) = lVar1;
      PoStartStopWatch((longlong *)(param_1 + 0x18));
    }
  }
  return;
}



===== PdcpIsGroupBlockingPhases @ 14002efcc =====

bool PdcpIsGroupBlockingPhases(int *param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(char *)((longlong)param_1 + 5) != '\0') && (0 < param_1[2])) {
    bVar1 = (&DAT_1400312c8)[(longlong)*param_1 * 0x158] != '\0';
  }
  return bVar1;
}



===== PdcpSleepstudyHelperClientFree @ 14002f004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PdcpSleepstudyHelperClientFree(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar6 = auStack_28;
  if (*(int *)(param_1 + 0x10) == 8) {
    plVar1 = (longlong *)(param_1 + 0x50);
    uVar7 = 0;
    while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
      if (((longlong *)plVar2[1] != plVar1) ||
         (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar6 = auStack_20;
        break;
      }
      *plVar1 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar1;
      if ((*(int *)(plVar2 + 2) == 1) && (DAT_140012870 != (code *)0x0)) {
        (*DAT_140012870)(plVar2[3]);
      }
      ExFreePoolWithTag(plVar2);
    }
    if (DAT_140012880 != (code *)0x0) {
      uVar4 = *(undefined8 *)(param_1 + 0x28);
      *(undefined8 *)(puVar6 + -8) = 0x14002f096;
      (*DAT_140012880)(uVar4);
    }
    *(undefined8 *)(puVar6 + -8) = 0x14002f0a2;
    ExFreePoolWithTag(param_1,0);
  }
  else {
    uVar7 = 0xc000000d;
  }
  return uVar7;
}



===== PdcpSleepstudyHelperClientInitialize @ 14002f0c8 =====

ulonglong PdcpSleepstudyHelperClientInitialize(int param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  void *_Dst;
  ulonglong uVar2;
  ulonglong uVar3;
  
  *param_3 = 0;
  if (param_1 == 0x70) {
    _Dst = (void *)ExAllocatePool2(0x100,0x60,0x68737350);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,0x60);
      lVar1 = (longlong)_Dst + 0x50;
      *(undefined4 *)((longlong)_Dst + 0x10) = 8;
      *(longlong *)((longlong)_Dst + 0x58) = lVar1;
      *(longlong *)lVar1 = lVar1;
      *(void **)((longlong)_Dst + 8) = _Dst;
      *(void **)_Dst = _Dst;
      *(undefined8 *)((longlong)_Dst + 0x48) = 1;
      uVar2 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar2 != 0) {
        *(undefined8 *)((longlong)_Dst + 0x38) = 0;
        *(undefined8 *)((longlong)_Dst + 0x40) = 0;
        *(undefined8 *)((longlong)_Dst + 0x30) = 0;
      }
      uVar3 = SleepstudyHelperCreateLibraryEx(param_2,(longlong)_Dst + 0x28);
      uVar2 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        ExFreePoolWithTag(_Dst,0);
      }
      else {
        *param_3 = _Dst;
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== PdcpSleepstudyHelperInitUnicodeString @ 14002f1b0 =====

uint PdcpSleepstudyHelperInitUnicodeString(short *param_1,short *param_2)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  longlong lVar4;
  
  if (param_1 == (short *)0x0) {
    uVar3 = 0xc000000d;
  }
  else {
    lVar4 = 0x100;
    psVar2 = param_1;
    do {
      if (*psVar2 == 0) break;
      psVar2 = psVar2 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
    if (lVar4 != 0) {
      sVar1 = (-(ushort)(lVar4 != 0) & 0x100U - (short)lVar4) * 2;
      *(short **)(param_2 + 4) = param_1;
      *param_2 = sVar1;
      param_2[1] = sVar1;
      return 0;
    }
  }
  return uVar3;
}



===== PdcpSleepstudyHelperProcessMessage @ 14002f22c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PdcpSleepstudyHelperProcessMessage(longlong param_1,int *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  uint uVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  int *piVar8;
  longlong lVar9;
  longlong lVar10;
  longlong local_res18;
  longlong local_res20;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  int local_58;
  longlong *local_50;
  short local_38 [8];
  
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  puVar6 = auStack_78;
  local_res20 = 0;
  uVar3 = 0;
  local_res18 = 0;
  iVar7 = *param_2;
  lVar10 = param_1;
  if (5 < iVar7) goto LAB_14002f527;
  if (iVar7 == 5) {
    lVar9 = *(longlong *)(param_2 + 2);
    plVar4 = PdcpSleepstudyHelperDecodeHandle(param_1,1,lVar9);
    iVar7 = (int)lVar9;
    if (plVar4 == (longlong *)0x0) {
      return 0xc000000d;
    }
    local_res18 = plVar4[3];
    if (DAT_140012870 != (code *)0x0) {
      (*DAT_140012870)();
    }
LAB_14002f4f1:
    lVar9 = *plVar4;
    if ((*(longlong **)(lVar9 + 8) == plVar4) &&
       (plVar1 = (longlong *)plVar4[1], (longlong *)*plVar1 == plVar4)) {
      *plVar1 = lVar9;
      *(longlong **)(lVar9 + 8) = plVar1;
      ExFreePoolWithTag(plVar4,0);
      return uVar3;
    }
  }
  else {
    if (iVar7 == 0) {
      puVar5 = PdcpSleepstudyHelperDecodeHandle(param_1,0,*(longlong *)(param_2 + 2));
      if (puVar5 == (undefined8 *)0x0) {
        return 0xc000000d;
      }
      LOCK();
      piVar8 = (int *)(puVar5 + 5);
      iVar7 = *piVar8;
      *piVar8 = *piVar8 + 1;
      UNLOCK();
      if (iVar7 + 1 < 0x10000) {
        local_res20 = puVar5[3];
        SleepstudyHelperBlockerActiveReference();
        return 0;
      }
      LOCK();
      *(int *)(puVar5 + 5) = *(int *)(puVar5 + 5) + -1;
      UNLOCK();
      return 0xc0000095;
    }
    if (iVar7 == 1) {
      puVar5 = PdcpSleepstudyHelperDecodeHandle(param_1,0,*(longlong *)(param_2 + 2));
      if (puVar5 == (undefined8 *)0x0) {
        return 0xc000000d;
      }
      LOCK();
      piVar8 = (int *)(puVar5 + 5);
      iVar7 = *piVar8;
      *piVar8 = *piVar8 + -1;
      UNLOCK();
      if (iVar7 + -1 < 0) {
        LOCK();
        *(int *)(puVar5 + 5) = *(int *)(puVar5 + 5) + 1;
        UNLOCK();
        return 0xc0000095;
      }
      local_res20 = puVar5[3];
      SleepstudyHelperBlockerActiveDereference();
      return 0;
    }
    if (iVar7 == 2) {
      puVar5 = PdcpSleepstudyHelperDecodeHandle(param_1,1,*(longlong *)(param_2 + 2));
      if (puVar5 == (undefined8 *)0x0) {
        return 0xc000000d;
      }
      local_res18 = puVar5[3];
      if (DAT_140012838 == (code *)0x0) {
        return 0xc00000bb;
      }
      uVar3 = (*DAT_140012838)(local_res18,&local_res20);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      *(undefined4 *)(puVar5 + 2) = 0;
      puVar5[3] = local_res20;
      *(undefined4 *)(puVar5 + 5) = 0;
      *(undefined8 *)(param_2 + 4) = puVar5[4];
      return uVar3;
    }
    if (iVar7 != 3) {
      if (iVar7 != 4) {
        return 0xc000000d;
      }
      lVar9 = *(longlong *)(param_2 + 2);
      plVar4 = PdcpSleepstudyHelperDecodeHandle(param_1,0,lVar9);
      iVar7 = (int)lVar9;
      if (plVar4 == (longlong *)0x0) {
        return 0xc000000d;
      }
      local_res20 = plVar4[3];
      SleepstudyHelperDestroyBlocker();
      goto LAB_14002f4f1;
    }
    uVar3 = PdcpSleepstudyHelperInitUnicodeString((short *)(param_2 + 0xb),local_38);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
    iVar7 = 0x68737350;
    plVar4 = (longlong *)ExAllocatePool2(0x100);
    if (plVar4 == (longlong *)0x0) {
      return 0xc000009a;
    }
    *(undefined8 *)((longlong)plVar4 + 0x14) = 0;
    *(undefined8 *)((longlong)plVar4 + 0x1c) = 0;
    *(undefined8 *)((longlong)plVar4 + 0x24) = 0;
    *(undefined4 *)((longlong)plVar4 + 0x2c) = 0;
    plVar4[1] = (longlong)plVar4;
    *plVar4 = (longlong)plVar4;
    *(undefined4 *)(plVar4 + 2) = 1;
    plVar4[4] = *(longlong *)(param_1 + 0x48);
    *(longlong *)(param_1 + 0x48) = *(longlong *)(param_1 + 0x48) + 1;
    if (DAT_140012858 == (code *)0x0) {
      uVar3 = 0xc00000bb;
      goto LAB_14002f4f1;
    }
    local_50 = &local_res18;
    piVar8 = param_2 + 6;
    local_58 = param_2[10];
    uVar3 = (*DAT_140012858)(*(undefined8 *)(param_1 + 0x28),param_2 + 2,piVar8,local_38);
    iVar7 = (int)piVar8;
    if ((int)uVar3 < 0) goto LAB_14002f4f1;
    lVar10 = param_1 + 0x50;
    plVar4[3] = local_res18;
    plVar1 = *(longlong **)(param_1 + 0x58);
    if (*plVar1 == lVar10) {
      *plVar4 = lVar10;
      plVar4[1] = (longlong)plVar1;
      *plVar1 = (longlong)plVar4;
      *(longlong **)(param_1 + 0x58) = plVar4;
      *(longlong *)(param_2 + 0x8c) = plVar4[4];
      return uVar3;
    }
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  puVar6 = auStack_70;
LAB_14002f527:
  if (iVar7 == 6) {
    lVar9 = *(longlong *)(param_2 + 2);
    *(undefined8 *)(puVar6 + -8) = 0x14002f645;
    puVar5 = PdcpSleepstudyHelperDecodeHandle(lVar10,0,lVar9);
    if (puVar5 != (undefined8 *)0x0) {
      local_res20 = puVar5[3];
      if (DAT_140012888 == (code *)0x0) {
        return 0xc00000bb;
      }
      *(undefined8 *)(puVar6 + -8) = 0x14002f66b;
      uVar3 = (*DAT_140012888)(local_res20,param_2 + 4);
      return uVar3;
    }
  }
  else if (iVar7 == 7) {
    *(undefined8 *)(puVar6 + -8) = 0x14002f5f6;
    uVar3 = PdcpSleepstudyHelperInitUnicodeString((short *)(param_2 + 4),local_38);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    lVar9 = *(longlong *)(param_2 + 2);
    *(undefined8 *)(puVar6 + -8) = 0x14002f60d;
    puVar5 = PdcpSleepstudyHelperDecodeHandle(lVar10,1,lVar9);
    if (puVar5 != (undefined8 *)0x0) {
      local_res18 = puVar5[3];
      if (DAT_140012898 != (code *)0x0) {
        *(undefined8 *)(puVar6 + -8) = 0x14002f633;
        (*DAT_140012898)(local_res18,local_38);
      }
      return 0;
    }
  }
  else if (iVar7 == 8) {
    lVar9 = *(longlong *)(param_2 + 2);
    *(undefined8 *)(puVar6 + -8) = 0x14002f59b;
    puVar5 = PdcpSleepstudyHelperDecodeHandle(lVar10,1,lVar9);
    if (puVar5 != (undefined8 *)0x0) {
      local_res18 = puVar5[3];
      lVar9 = *(longlong *)(param_2 + 4);
      *(undefined8 *)(puVar6 + -8) = 0x14002f5ba;
      puVar5 = PdcpSleepstudyHelperDecodeHandle(lVar10,0,lVar9);
      if (puVar5 != (undefined8 *)0x0) {
        local_res20 = puVar5[3];
        if (DAT_1400128a0 == (code *)0x0) {
          return uVar3;
        }
        *(undefined8 *)(puVar6 + -8) = 0x14002f5e4;
        (*DAT_1400128a0)(local_res18);
        return uVar3;
      }
    }
  }
  else if (iVar7 == 9) {
    lVar9 = *(longlong *)(param_2 + 2);
    *(undefined8 *)(puVar6 + -8) = 0x14002f55c;
    puVar5 = PdcpSleepstudyHelperDecodeHandle(lVar10,1,lVar9);
    if (puVar5 != (undefined8 *)0x0) {
      local_res18 = puVar5[3];
      if (DAT_1400128a8 == (code *)0x0) {
        return uVar3;
      }
      iVar7 = param_2[4];
      *(undefined8 *)(puVar6 + -8) = 0x14002f585;
      (*DAT_1400128a8)(local_res18,(char)iVar7);
      return uVar3;
    }
  }
  return 0xc000000d;
}



===== PdcActivationClientActivityRequest @ 14002f688 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint PdcActivationClientActivityRequest
               (undefined8 param_1,uint param_2,char param_3,longlong param_4)

{
  int iVar1;
  undefined1 auVar2 [16];
  int *piVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 local_328 [40];
  undefined4 local_300;
  uint local_2f0;
  uint local_2ec;
  
  piVar3 = PdcInternalActivatorClient;
  uVar5 = 800;
  memset(local_328,0,800);
  if ((piVar3 == (int *)0x0) || (*piVar3 != 0x41636450)) {
    return 0xc00000ef;
  }
  if ((4 < param_2) || (param_2 == 4)) {
    return 0xc00000f0;
  }
  PdcAcquireRwLockExclusive((longlong)(piVar3 + 2));
  iVar1 = piVar3[(longlong)(int)param_2 + 0xc];
  if (param_3 == '\0') {
    if (iVar1 == 0) {
      uVar4 = 0xc0000001;
      goto LAB_14002f7d7;
    }
    if (iVar1 != 1) goto LAB_14002f71a;
LAB_14002f730:
    local_2f0 = local_2f0 & 0xffffff00;
LAB_14002f735:
    local_300 = 4;
    local_2ec = param_2;
    uVar4 = PdcPortSendMessageSynchronously(*(longlong *)(piVar3 + 10),(longlong)local_328);
    if (((int)uVar4 < 0) || (uVar4 = local_2f0, (int)local_2f0 < 0)) goto LAB_14002f7d7;
  }
  else {
    if (iVar1 == 0) {
      local_2f0 = CONCAT31(local_2f0._1_3_,1);
      if (param_3 == '\0') goto LAB_14002f730;
      goto LAB_14002f735;
    }
LAB_14002f71a:
    uVar4 = 0;
  }
  if (param_3 == '\0') {
    piVar3[(longlong)(int)param_2 + 0xc] = piVar3[(longlong)(int)param_2 + 0xc] + -1;
    piVar3[0x32] = piVar3[0x32] + -1;
    Pdcv1EventWrite_ACTIVATION_CLIENT_DEACTIVATE((longlong)piVar3,uVar4,uVar5,param_4);
    if (piVar3[0x32] != 0) goto LAB_14002f7d7;
    piVar3[0x34] = 0;
    piVar3[0x35] = 0;
  }
  else {
    piVar3[(longlong)(int)param_2 + 0xc] = piVar3[(longlong)(int)param_2 + 0xc] + 1;
    piVar3[0x32] = piVar3[0x32] + 1;
    Pdcv1EventWrite_ACTIVATION_CLIENT_ACTIVATE((longlong)piVar3,(char)uVar4);
    if (piVar3[0x32] != 1) goto LAB_14002f7d7;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = _DAT_fffff78000000320 << 8;
    *(longlong *)(piVar3 + 0x34) = SUB168(auVar2 * (ZEXT416(_DAT_fffff78000000004) << 0x20),8);
  }
  piVar3[0x33] = 0;
LAB_14002f7d7:
  PdcReleaseRwLockExclusive((longlong)(piVar3 + 2));
  return uVar4;
}



===== PdcActivationClientRegister @ 14002f80c =====

int PdcActivationClientRegister(undefined8 param_1,undefined *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  code *local_res10 [3];
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  PdcInternalActivatorClient = (undefined4 *)0x0;
  uVar3 = 0x100;
  local_res10[0] = (code *)param_2;
  puVar2 = (undefined4 *)ExAllocatePool2(0x100,0xd8,0x41636450);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    *(undefined8 *)(puVar2 + 0x34) = 0;
    puVar2[0x32] = 0;
    puVar2[0x33] = 0;
    *puVar2 = 0x41636450;
    puVar2[8] = 0x12;
    local_res10[0] = PdcpActivationClientCallback;
    *(undefined8 *)(puVar2 + 4) = 0;
    *(undefined8 *)(puVar2 + 6) = 0;
    *(undefined8 *)(puVar2 + 2) = 0;
    iVar1 = PdcPortOpenCommon(uVar3,2,puVar2,(longlong *)local_res10,in_stack_ffffffffffffffc8,
                              in_stack_ffffffffffffffd0,0,in_stack_ffffffffffffffe0,
                              (undefined8 *)(puVar2 + 10));
    if (iVar1 == 0) {
      *(undefined1 *)(puVar2 + 0x11) = 1;
      PdcInitializeETW();
      Pdcv1EventWrite_ACTIVATION_CLIENT_REGISTER((longlong)puVar2,0);
      PdcInternalActivatorClient = puVar2;
    }
    else {
      ExFreePoolWithTag(puVar2,0);
    }
  }
  return iVar1;
}



===== PdcpActivationClientCallback @ 14002f900 =====

uint PdcpActivationClientCallback(int *param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = false;
  uVar2 = 0;
  if ((param_1 == (int *)0x0) || (*param_1 != 0x41636450)) {
    uVar2 = 0xc00000ef;
LAB_14002f929:
    param_1 = (int *)0x0;
  }
  else {
    if (*(int *)(param_2 + 0x28) != 0xe) {
      uVar2 = 0xc0000702;
      goto LAB_14002f929;
    }
    PdcAcquireRwLockExclusive((longlong)(param_1 + 2));
    bVar1 = true;
    if ((char)param_1[0x11] != '\0') {
      Pdcv1EventWrite_ACTIVATION_CLIENT_CALLBACK
                ((longlong)param_1,*(int *)(param_2 + 0x38),0,param_4);
      goto LAB_14002f97c;
    }
    uVar2 = 0xc0000189;
  }
  Pdcv1EventWrite_ACTIVATION_CLIENT_CALLBACK((longlong)param_1,-1,(ulonglong)uVar2,param_4);
  if (!bVar1) {
    return uVar2;
  }
LAB_14002f97c:
  PdcReleaseRwLockExclusive((longlong)(param_1 + 2));
  return uVar2;
}



===== PdcAcquireRwLockExclusive @ 14002f9a4 =====

void PdcAcquireRwLockExclusive(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1,0);
  *(void **)(param_1 + 8) = SystemReserved1[0xf];
  return;
}



===== PdcAllocate @ 14002f9e4 =====

void PdcAllocate(char param_1)

{
  ExAllocatePool2((-(uint)(param_1 != '\0') & 0xc0) + 0x40);
  return;
}



===== PdcFree @ 14002fa10 =====

void PdcFree(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PdcInitializeTimer @ 14002fa30 =====

void PdcInitializeTimer(longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                       undefined4 param_5)

{
  *(undefined4 *)(param_1 + 0x80) = param_3;
  *(undefined4 *)(param_1 + 0xa8) = param_5;
  KeInitializeDpc(param_1 + 0x40,PdcTimerCallback,param_1);
  KeInitializeTimer(param_1);
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined8 *)(param_1 + 0x98) = param_2;
  *(undefined8 *)(param_1 + 0xa0) = param_4;
  return;
}



===== PdcReleaseRwLockExclusive @ 14002fab0 =====

void PdcReleaseRwLockExclusive(longlong param_1)

{
  *(undefined8 *)(param_1 + 8) = 0;
  ExReleasePushLockEx(param_1,0);
  KeLeaveCriticalRegion();
  return;
}



===== PdcRwLockInitialize @ 14002fae0 =====

void PdcRwLockInitialize(undefined8 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



===== PdcSetTimer @ 14002faf8 =====

void PdcSetTimer(longlong param_1,ulonglong param_2)

{
  KeSetCoalescableTimer(param_1,(param_2 & 0xffffffff) * -10000,0,1000,param_1 + 0x40);
  return;
}



===== PdcTaskClientRegister @ 14002fb30 =====

int PdcTaskClientRegister(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined8 local_338;
  undefined8 local_330;
  undefined8 local_328;
  undefined4 local_30c;
  undefined4 local_300;
  undefined4 local_2fc;
  
  PdcInternalTaskClient = (undefined8 *)0x0;
  puVar2 = (undefined8 *)ExAllocatePool2(0x100,0x40,0x63636450);
  if (puVar2 == (undefined8 *)0x0) {
    return -0x3fffffe9;
  }
  *puVar2 = 0x63636450;
  puVar2[4] = 0x12;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[1] = 0;
  memset(&local_338,0,800);
  puVar2[5] = 0;
  puVar4 = (undefined4 *)0x0;
  puVar3 = (undefined4 *)ExAllocatePool2(0x100,0x6e8,0x50636450);
  if (puVar3 == (undefined4 *)0x0) {
LAB_14002fbe0:
    iVar1 = -0x3fffffe9;
LAB_14002fbe5:
    if (puVar3 != (undefined4 *)0x0) {
      PdcpPortReleaseResources(puVar3);
    }
    if (puVar4 == (undefined4 *)0x0) goto LAB_14002fc08;
  }
  else {
    *puVar3 = 0x50636450;
    puVar3[5] = 4;
    *(undefined8 **)(puVar3 + 0x1b4) = puVar2;
    puVar3[4] = 0x12;
    ExInitializeRundownProtection(puVar3 + 2);
    *(undefined8 *)(puVar3 + 0x1b6) = 0;
    local_2fc = 4;
    local_30c = 6;
    local_300 = 0x12;
    local_338 = 0x32002f8;
    local_330 = 0;
    local_328 = 0;
    puVar4 = (undefined4 *)ExAllocatePool2(0x100,0xe0,0x50636450);
    if (puVar4 == (undefined4 *)0x0) goto LAB_14002fbe0;
    *puVar4 = 1;
    *(undefined4 **)(puVar4 + 4) = puVar3;
    *(undefined8 **)(puVar4 + 2) = &local_338;
    iVar1 = ZwPowerInformation(0x43,puVar4,0xe0,0,0);
    if (iVar1 < 0) goto LAB_14002fbe5;
    puVar2[5] = puVar3;
    iVar1 = 0;
  }
  ExFreePoolWithTag(puVar4,0);
LAB_14002fc08:
  if (iVar1 == 0) {
    PdcInternalTaskClient = puVar2;
  }
  else {
    ExFreePoolWithTag(puVar2,0);
  }
  return iVar1;
}



===== PdcTaskClientRequest @ 14002fd1c =====

int PdcTaskClientRequest(undefined8 param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 local_328 [40];
  undefined4 local_300;
  undefined1 local_2f0;
  
  piVar1 = PdcInternalTaskClient;
  memset(local_328,0,800);
  if ((piVar1 == (int *)0x0) || (*piVar1 != 0x63636450)) {
    return -0x3fffff11;
  }
  PdcAcquireRwLockExclusive((longlong)(piVar1 + 2));
  if ((param_2 == '\0') && (piVar1[0xc] == 0)) {
    iVar2 = -0x3fffffff;
    goto LAB_14002fdc8;
  }
  iVar2 = 0;
  if (param_2 == '\0') {
    if (piVar1[0xc] == 1) {
LAB_14002fd8e:
      local_300 = 7;
      local_2f0 = param_2 != '\0';
      PdcPortSendMessageSynchronously(*(longlong *)(piVar1 + 10),(longlong)local_328);
      iVar2 = piVar1[0xd];
      if (iVar2 < 0) goto LAB_14002fdc8;
    }
  }
  else if (piVar1[0xc] == 0) goto LAB_14002fd8e;
  if (param_2 == '\0') {
    piVar1[0xc] = piVar1[0xc] + -1;
  }
  else {
    piVar1[0xc] = piVar1[0xc] + 1;
  }
LAB_14002fdc8:
  PdcReleaseRwLockExclusive((longlong)(piVar1 + 2));
  return iVar2;
}



===== PdcPortOpenCommon @ 14002fdf0 =====

int PdcPortOpenCommon(undefined8 param_1,int param_2,undefined8 param_3,longlong *param_4,
                     undefined8 param_5,undefined8 param_6,longlong param_7,undefined8 param_8,
                     undefined8 *param_9)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  short *psVar4;
  undefined4 *puVar5;
  short *psVar6;
  longlong lVar7;
  undefined8 local_348;
  undefined8 local_340;
  undefined8 local_338;
  undefined4 local_31c;
  undefined4 local_310;
  int local_30c;
  short local_300 [364];
  
  memset(&local_348,0,800);
  puVar5 = (undefined4 *)0x0;
  *param_9 = 0;
  puVar3 = (undefined4 *)ExAllocatePool2(0x100,0x6e8,0x50636450);
  if (puVar3 == (undefined4 *)0x0) {
LAB_14002fe65:
    iVar2 = -0x3fffffe9;
  }
  else {
    *(undefined8 *)(puVar3 + 0x1b4) = param_3;
    *puVar3 = 0x50636450;
    puVar3[4] = 0x12;
    puVar3[5] = param_2;
    ExInitializeRundownProtection(puVar3 + 2);
    lVar7 = *param_4;
    *(longlong *)(puVar3 + 0x1b6) = lVar7;
    if ((lVar7 == 0) && (((param_2 - 4U & 0xfffffffa) != 0 || (param_2 == 9)))) {
      iVar2 = -0x3fffff0f;
    }
    else {
      local_31c = 6;
      local_310 = 0x12;
      if (param_7 != 0) {
        lVar7 = 0x40;
        psVar6 = local_300;
        do {
          if ((lVar7 == -0x7fffffbe) ||
             (sVar1 = *(short *)((param_7 - (longlong)local_300) + (longlong)psVar6), sVar1 == 0))
          break;
          *psVar6 = sVar1;
          psVar6 = psVar6 + 1;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        psVar4 = psVar6 + -1;
        if (lVar7 != 0) {
          psVar4 = psVar6;
        }
        *psVar4 = 0;
      }
      local_348 = 0x32002f8;
      local_340 = 0;
      local_338 = 0;
      local_30c = param_2;
      puVar5 = (undefined4 *)ExAllocatePool2(0x100,0xe0,0x50636450);
      if (puVar5 == (undefined4 *)0x0) goto LAB_14002fe65;
      *puVar5 = 1;
      *(undefined4 **)(puVar5 + 4) = puVar3;
      *(undefined8 **)(puVar5 + 2) = &local_348;
      iVar2 = ZwPowerInformation(0x43,puVar5,0xe0,0,0);
      if (-1 < iVar2) {
        *param_9 = puVar3;
        iVar2 = 0;
        goto LAB_14002fe7c;
      }
    }
  }
  if (puVar3 != (undefined4 *)0x0) {
    PdcpPortReleaseResources(puVar3);
  }
  if (puVar5 == (undefined4 *)0x0) {
    return iVar2;
  }
LAB_14002fe7c:
  ExFreePoolWithTag(puVar5,0);
  return iVar2;
}



===== PdcpPortReleaseResources @ 14002ffec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdcpPortReleaseResources(undefined4 *param_1)

{
  undefined1 local_328 [40];
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f0;
  undefined4 local_2ec;
  
  memset(local_328,0,800);
  *param_1 = 0;
  if (*(longlong *)(param_1 + 6) != 0) {
    local_2f0 = param_1[4];
    local_2ec = param_1[5];
    local_300 = 1;
    local_2fc = 6;
    (**(code **)(param_1 + 8))(*(longlong *)(param_1 + 6),local_328,800);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PdctAllocateAndGetInclusionList @ 14003006c =====

int PdctAllocateAndGetInclusionList(undefined8 *param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  uint local_res18 [2];
  
  local_res18[0] = 0;
  iVar1 = PdctGetInclusionList((int *)0x0,local_res18);
  if (iVar1 == -0x7ffffffb) {
    piVar2 = (int *)ExAllocatePool2(0x100,local_res18[0],0x49636450);
    if (piVar2 == (int *)0x0) {
      iVar1 = -0x3fffffe9;
    }
    else {
      iVar1 = PdctGetInclusionList(piVar2,local_res18);
      if (iVar1 < 0) {
        ExFreePoolWithTag(piVar2,0);
      }
      else {
        *param_2 = local_res18[0];
        *param_1 = piVar2;
      }
    }
  }
  return iVar1;
}



===== PdctGetInclusionList @ 140030118 =====

int PdctGetInclusionList(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int local_res10 [2];
  uint local_res18 [2];
  longlong local_res20;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 local_68;
  wchar_t *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar2 = *param_2;
  local_3c = 0;
  local_res20 = 0;
  local_res10[0] = -1;
  local_50 = 0;
  local_70 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power";
  local_58 = 0x30;
  local_60 = L"PdcClientInclusionList";
  local_48 = &local_78;
  local_78 = 0x720070;
  local_68 = 0x2e002c;
  local_40 = 0x40;
  local_38 = 0;
  uStack_30 = 0;
  local_res18[0] = uVar2;
  iVar1 = ZwOpenKey(&local_res20,1,&local_58);
  if (iVar1 < 0) goto LAB_140030218;
  iVar1 = PdctpQueryRegistryValueData(local_res20,&local_68,local_res10,param_1,uVar2,local_res18);
  if ((iVar1 != -0x7ffffffb) && (iVar1 != 0)) goto LAB_140030218;
  if (local_res10[0] != 3) {
    iVar1 = -0x3fffffdc;
    goto LAB_140030218;
  }
  if (((local_res18[0] & 3) == 0) && (uVar2 = 8, 7 < local_res18[0])) {
    if (iVar1 == 0) {
      if (*param_1 != 0) {
        uVar2 = *param_1 * 4 + 4;
      }
      if (local_res18[0] != uVar2) goto LAB_140030213;
    }
    *param_2 = local_res18[0];
  }
  else {
LAB_140030213:
    iVar1 = -0x3ffffdfa;
  }
LAB_140030218:
  if (local_res20 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== PdctpQueryRegistryValueData @ 140030244 =====

int PdctpQueryRegistryValueData
              (undefined8 param_1,undefined8 param_2,undefined4 *param_3,void *param_4,uint param_5,
              uint *param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  
  uVar1 = param_5;
  param_5 = param_5 + 0xc;
  lVar4 = ExAllocatePool2(0x100,param_5,0x49636450);
  if (lVar4 == 0) {
    return -0x3fffffe9;
  }
  iVar3 = ZwQueryValueKey(param_1,param_2,2,lVar4,param_5,&param_5);
  uVar2 = param_5;
  if (iVar3 == -0x7ffffffb) {
    if ((uVar1 < param_5 - 0xc) || (param_4 == (void *)0x0)) {
      *param_6 = param_5 - 0xc;
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(lVar4 + 4);
      }
      goto LAB_140030322;
    }
  }
  else if (iVar3 < 0) goto LAB_140030322;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(lVar4 + 4);
  }
  memmove(param_4,(void *)(lVar4 + 0xc),(ulonglong)*(uint *)(lVar4 + 8));
  *param_6 = uVar2 - 0xc;
LAB_140030322:
  ExFreePoolWithTag(lVar4,0);
  return iVar3;
}



===== SleepstudyHelperEnsureRoutineBlockLoaded @ 140030358 =====

void SleepstudyHelperEnsureRoutineBlockLoaded(void)

{
  RtlRunOnceExecuteOnce(&SleepstudyHelperInitializeRunOnce,SleepstudyHelperInitializeOnce,0,0);
  return;
}



===== SleepstudyHelperInitializeOnce @ 140030390 =====

undefined8 SleepstudyHelperInitializeOnce(void)

{
  int iVar1;
  size_t _Size;
  undefined8 local_res20;
  int *local_18 [2];
  
  _Size = 0x110;
  local_18[0] = (int *)0x0;
  memset(&SleepstudyHelperRoutineBlock,0,0x110);
  local_res20 = 0x3f;
  iVar1 = ZwPowerInformation(0x57,&local_res20,8,local_18,8);
  if (iVar1 != -0x3fffff45) {
    if (iVar1 < 0) {
      return 0;
    }
    if (*local_18[0] == 1) {
      _Size = 0x108;
    }
    memmove(&SleepstudyHelperRoutineBlock,local_18[0],_Size);
  }
  return 1;
}



===== entry @ 140033010 =====

void entry(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 140033044 =====

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



===== DriverEntry @ 140033078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  char *pcVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined8 local_res8;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar9;
  ulonglong in_stack_ffffffffffffffe0;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  wil_InitializeFeatureStaging();
  PdcPrint(2,"PDC: initializing %s\n","DriverEntry",param_4);
  uVar8 = 0x22;
  PdcDriverObject = param_1;
  uVar1 = IoCreateDevice(param_1,4,0,0x22,CONCAT44(uVar9,0x100),
                         in_stack_ffffffffffffffe0 & 0xffffffffffffff00,&PdcDevice);
  if ((int)uVar1 < 0) {
    pcVar6 = "PDC: IoCreateDevice: %08lx\n";
  }
  else {
    PdcPrint(2,"PDC: created device object: %p\n",PdcDevice,uVar8);
    uVar1 = PdcInitializeLock();
    if (-1 < (int)uVar1) {
      PdcAcquireLock();
      InitializeTelemetryAssertsKMByDriverObject(param_1);
      uVar2 = PdcInitializePdc(0);
      uVar1 = (uint)uVar2;
      uVar2 = uVar2 & 0xffffffff;
      if ((int)uVar1 < 0) {
        pcVar6 = "PDC: PdcInitializePdc: %08lx\n";
      }
      else {
        uVar1 = PdcRegisterPdc();
        uVar2 = (ulonglong)uVar1;
        PdcLowPowerEpoch('\0');
        if (DAT_1400150e8 != (code *)0x0) {
          (*DAT_1400150e8)(0,1);
        }
        PdcReleaseLock();
        if ((int)uVar1 < 0) {
          pcVar6 = "PDC: PdcRegisterPdc: %08lx\n";
        }
        else {
          uVar2 = PdcPpmInitialize();
          uVar1 = (uint)uVar2;
          uVar2 = uVar2 & 0xffffffff;
          if ((int)uVar1 < 0) {
            pcVar6 = "PDC: PdcPpmInitialize: %08lx\n";
          }
          else {
            PdcAcquireLock();
            local_res8 = 0;
            _PdcAudioPolicyContext = 0;
            _DAT_140015bd0 = 0;
            _DAT_140015be0 = 0;
            _DAT_140015bc8 = 0;
            _DAT_140015bd8 = PdcAudioPolicyEvaluationWorker;
            uVar8 = 0;
            puVar7 = &WNF_SEB_AUDIO_ACTIVITY;
            puVar4 = &local_res8;
            uVar1 = ExSubscribeWnfStateChange
                              (puVar4,&WNF_SEB_AUDIO_ACTIVITY,1,0,PdcAudioPolicyHandleAudioActiveWnf
                               ,0);
            uVar2 = (ulonglong)uVar1;
            PdcReleaseLock();
            if ((int)uVar1 < 0) {
              pcVar6 = "PDC: PdcAudioPolicyInitialize: %08lx\n";
            }
            else {
              uVar2 = PdcClientPolicyInitialize();
              uVar1 = (uint)uVar2;
              uVar2 = uVar2 & 0xffffffff;
              if ((int)uVar1 < 0) {
                pcVar6 = "PDC: PdcInitalizeClientPolicy: %08lx\n";
              }
              else {
                uVar1 = PdcActivationClientRegister(puVar4,puVar7);
                uVar2 = (ulonglong)uVar1;
                if ((int)uVar1 < 0) {
                  pcVar6 = "PDC: PdcRegisterInternalActivatorClient: %08lx\n";
                }
                else {
                  uVar1 = PdcTaskClientRegister();
                  uVar2 = (ulonglong)uVar1;
                  if (-1 < (int)uVar1) {
                    puVar4 = (undefined8 *)(param_1 + 0x70);
                    for (lVar5 = 0x1b; lVar5 != 0; lVar5 = lVar5 + -1) {
                      *puVar4 = PdcIrpInvalidRequest;
                      puVar4 = puVar4 + 1;
                    }
                    *(undefined8 *)(param_1 + 0x68) = 0;
                    uVar3 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
                    if ((int)uVar3 == 0) {
                      return uVar2;
                    }
                    PdcGetPolicyWorker(0x20);
                    PdcCheckForWork();
                    return uVar2;
                  }
                  pcVar6 = "PDC: PdcRegisterInternalTaskClient: %08lx\n";
                }
              }
            }
          }
        }
      }
      goto LAB_140033276;
    }
    pcVar6 = "PDC: PdcInitializeLock: %08lx\n";
  }
  uVar2 = (ulonglong)uVar1;
LAB_140033276:
  PdcPrint(1,pcVar6,(ulonglong)uVar1,uVar8);
  PdcPrint(1,"PDC: driver startup error: status: %08lx\n",uVar2,uVar8);
  lVar5 = PdcDevice;
  if (PdcDevice != 0) {
    IoDeleteDevice();
  }
  if ((DAT_140015c01 & 2) != 0) {
    McTemplateU0qq_EtwWriteTransfer(lVar5,&PDC_INITIALIZATION,0,(int)uVar2);
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
  return uVar2;
}



===== wil_InitializeFeatureStaging @ 14003335c =====

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
    for (ppuVar3 = &Feature_LocklessPhasesPoCallout__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400333e3;
    }
LAB_14003341d:
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
LAB_1400333e3:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14003341d;
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
    goto LAB_14003341d;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400116cf < ppuVar3) goto LAB_14003341d;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400333e3;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140033470 =====

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
  ppuVar4 = &Feature_LocklessPhasesPoCallout__private_descriptor;
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
            if (&UNK_1400116cf < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14003355a;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14003355a;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14003355a:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400116cf < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}



===== PdcClientPolicyInitialize @ 1400335ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PdcClientPolicyInitialize(void)

{
  int iVar1;
  
  _DAT_140015b38 = 0;
  _ConfigureClientPolicyWorkItem = 0;
  _DAT_140015b98 = 0;
  _VetoClientWorkItem = 0;
  DAT_140015b58 = &AllEaRules;
  AllEaRules = &AllEaRules;
  _DAT_140015b30 = PdcpConfigureClientPolicyWorker;
  _DAT_140015b90 = PdcpVetoClientWorker;
  PdcAcquireLock();
  iVar1 = ExSubscribeWnfStateChange
                    (&UmpoScmWnfSubscription,&WNF_SCM_AUTOSTART_STATE,1,0,PdcpWnfScmPhaseCallback,0)
  ;
  if (iVar1 < 0) {
    UmpoScmWnfSubscription = 0;
  }
  PdcReleaseLock();
  return 0;
}



===== PdcAlpcInitializeChannel @ 140033698 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint PdcAlpcInitializeChannel(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  undefined4 local_110;
  undefined2 local_108;
  undefined8 local_f8;
  longlong local_f0;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined8 uStack_e0;
  undefined8 *local_d8;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined8 *local_c8;
  ulonglong local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_68 [4];
  undefined8 local_58;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_c8 = (undefined8 *)0x0;
  local_c0 = local_c0 & 0xffffffff00000000;
  local_e8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  local_d8 = (undefined8 *)0x0;
  uStack_d0 = 0;
  uStack_cc = 0;
  memset(local_68,0,0x48);
  local_78 = 0;
  PdcServerPort = 0;
  DAT_140015ae8 = &PdcClientPorts;
  _PdcClientPorts = &PdcClientPorts;
  local_a8 = 0;
  uStack_a0 = 0;
  _PdcAlpcPushLock = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_f8 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  uVar5 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    local_108 = 0;
    local_110 = 0x50636450;
    local_118 = 0x6e0;
    ExInitializePagedLookasideList(&PdcMessageBufferLookasideList,0,0,0);
  }
  local_f0 = 0;
  uVar1 = SeConvertStringSidToSid
                    (L"S-1-15-3-1024-1502825166-1963708345-2616377461-2562897074-4192028372-3968301570-1997628692-1435953622"
                     ,&local_f0);
  if ((int)uVar1 < 0) {
    PdcPrint(1,"%s: SeConvertStringSidToSid failed: 0x%x\n","PdcAlpcInitializeChannel",
             (ulonglong)uVar1);
    goto LAB_140033a73;
  }
  iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x208));
  iVar3 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
  iVar4 = RtlLengthSid();
  lVar6 = PdcAllocate('\0');
  if (lVar6 == 0) {
    uVar1 = 0xc000009a;
    goto LAB_140033a73;
  }
  RtlCreateAcl(lVar6,iVar2 + iVar3 + iVar4 + 0x2c,2);
  RtlAddAccessAllowedAce(lVar6,2,0x10000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
  RtlAddAccessAllowedAce(lVar6,2,0x10000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0x208));
  RtlAddAccessAllowedAce(lVar6,2,0x10000000);
  RtlCreateSecurityDescriptor(&local_98,1);
  RtlSetDaclSecurityDescriptor(&local_98,1,lVar6);
  RtlInitUnicodeString(&local_a8);
  memset(local_68,0,0x48);
  local_d8 = &local_a8;
  local_58 = 800;
  local_c8 = &local_98;
  local_68[0] = 0x100000;
  local_e8 = 0x30;
  uStack_e0 = 0;
  uStack_d0 = 0x200;
  local_c0 = 0;
  uVar1 = ZwAlpcCreatePort(&PdcServerPort,&local_e8,local_68);
  if ((int)uVar1 < 0) {
    pcVar8 = "%s: ZwAlpcCreatePort failed: 0x%x\n";
LAB_140033964:
    PdcPrint(1,pcVar8,"PdcAlpcInitializeChannel",(ulonglong)uVar1);
  }
  else {
    local_c8 = &local_98;
    local_e8 = 0x30;
    uVar9 = 0;
    uStack_e0 = 0;
    uStack_d0 = 0x200;
    local_d8 = (undefined8 *)0x0;
    local_c0 = 0;
    uVar1 = ExCreateCallback(&local_f8,&local_e8,1);
    if ((int)uVar1 < 0) {
      pcVar8 = "%s: ExCreateCallback failed: 0x%x\n";
      goto LAB_140033964;
    }
    lVar7 = ExRegisterCallback(local_f8,PdcpAlpcProcessMessages,0);
    if (lVar7 == 0) {
      PdcPrint(1,"%s: ExRegisterCallback failed\n","PdcAlpcInitializeChannel",uVar9);
      uVar1 = 0xc000009a;
    }
    else {
      local_b8 = local_f8;
      uStack_b0 = 0;
      uVar1 = ZwAlpcSetInformation(PdcServerPort,9,&local_b8);
      ObfDereferenceObject(local_f8);
      if ((int)uVar1 < 0) {
        pcVar8 = "%s: ZwAlpcSetInformation failed: 0x%x\n";
        goto LAB_140033964;
      }
      uVar5 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar5 == 0) {
        PdcpAlpcProcessMessages();
      }
      uVar1 = 0;
    }
  }
  PdcFree(lVar6);
LAB_140033a73:
  if (local_f0 != 0) {
    ExFreePoolWithTag(local_f0,0);
  }
  return uVar1;
}



===== PdcClientInclusionListInitialize @ 140033ac0 =====

int PdcClientInclusionListInitialize(void)

{
  int iVar1;
  uint local_res8 [2];
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  PdcClientInclusionList = 0;
  iVar1 = PdctAllocateAndGetInclusionList(local_res10,local_res8);
  if (iVar1 < 0) {
    if (local_res10[0] != 0) {
      PdcFree(local_res10[0]);
    }
  }
  else {
    PdcClientInclusionList = local_res10[0];
  }
  return iVar1;
}



===== PdcClientsInitialize @ 140033b18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcClientsInitialize(void)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  longlong lVar6;
  undefined1 auStackY_58 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  uVar1 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    PdcResiliencyClientsInitialize();
  }
  else {
    PdcpResiliencyV2Initialize();
  }
  uVar5 = 0;
  puVar3 = &DAT_140014078;
  lVar6 = 0;
  puVar4 = &PdcNotificationControls;
  do {
    puVar3[-0xe] = 0;
    *(uint *)(puVar3 + -0xf) = uVar5;
    puVar3[1] = puVar3;
    *puVar3 = puVar3;
    PdcInitializeTimer((longlong)(&PdcNotificationTimers + lVar6),PdcpNotificationQueueWorker,uVar5,
                       puVar4,1);
    PdcInitializeTimer((longlong)(&PdcNotificationWatchdogTimers + lVar6),PdcpNotificationWatchdog,
                       uVar5,puVar4,5);
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 0x26;
    lVar6 = lVar6 + 0xb8;
    puVar3 = puVar3 + 0x13;
  } while (uVar5 < 6);
  DAT_140015bf8 = &PdcActivators;
  PdcActivators = &PdcActivators;
  DAT_140012998 = &PdcActivatorStatsList;
  PdcActivatorStatsList = &PdcActivatorStatsList;
  memset(&PdcBSActivationStats,0,0x418);
  PdcpAccountingPaused = 1;
  PdcRwLockInitialize((undefined8 *)&PdcSuspendResumeLock);
  DAT_140014c68 = &PdcSuspendResumeContext;
  PdcSuspendResumeContext = &PdcSuspendResumeContext;
  DAT_140014c78 = 0;
  _DAT_140014c80 = 0;
  KeInitializeEvent(&DAT_140014c88,0,1);
  local_28 = 1;
  DAT_140013fe8 = &PdcTaskClients;
  PdcTaskClients = &PdcTaskClients;
  local_24 = 0x5044434d;
  local_20 = 1;
  uVar2 = SleepstudyHelperCreateLibraryEx(&local_28,&PdcpTaskClientLibraryHandle);
  if ((int)uVar2 < 0) {
    PdcpTaskClientLibraryHandle = 0;
  }
  DAT_140012e18 = &PdcSignalClients;
  PdcSignalClients = &PdcSignalClients;
  DAT_140012e48 = &PdcSignalEventQueue;
  PdcSignalEventQueue = &PdcSignalEventQueue;
  PdcRwLockInitialize((undefined8 *)&PdcSignalEventQueueLock);
  return;
}



===== PdcpDumpControlInit @ 140033d1c =====

void PdcpDumpControlInit(void)

{
  DAT_140012044 = 0;
  KeInitializeTriageDumpDataArray(&DAT_140012048,0x40);
  KeRegisterBugCheckReasonCallback
            (&DAT_140012018,PTR_PdcpDumpControlCallback_140012008,7,
             PTR_s_PDC_14F_TRIAGE_DUMP_COMPONENT_140012010);
  Pdcp14FControlContext = 1;
  return;
}



===== PdcRegisterPdc @ 140033d7c =====

undefined4 PdcRegisterPdc(void)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined4 local_198;
  undefined4 local_194;
  code *local_190;
  code *local_188;
  code *local_180;
  code *local_178;
  code *local_170;
  code *local_168;
  code *local_160;
  code *local_158;
  code *local_150;
  code *local_148;
  code *local_140;
  code *local_138;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  local_194 = 0;
  memset(&local_b8,0,0xa8);
  local_198 = 0;
  local_190 = PdcResetSwitchTriggers;
  local_188 = PdcUserShutdownInitiated;
  local_180 = PdcUserShutdownCancelled;
  local_178 = PdcStartPolicyIrps;
  local_170 = PdcRegisterKernelClient;
  local_168 = PdcSessionConnectionEvent;
  local_160 = PdcSuspendResume;
  local_158 = PdcSuspendResumeIssueBroadcast;
  local_150 = PdcSystemIdle;
  local_148 = PdcPpmMediaBufferingUpdate;
  local_140 = PdcpApplyResiliencyBias;
  local_138 = PdcQueryBootSessionStandbyActiveTime;
  local_130 = PdcCaptureSleepStudyStatistics;
  local_128 = PdcEngagePhases;
  local_120 = PdcDisengagePhases;
  local_118 = PdcQueryResiliencyStats;
  local_110 = PdcAreAllPhasesDisengaged;
  uVar2 = Feature_PdcResiliencyV2__private_IsEnabledDeviceUsageNoInline();
  local_100 = PdcSnapDiagnosticContext;
  local_f8 = PdcAcknowledgePhaseCallback;
  local_108 = PdcPoCompleteResiliencyCallback;
  if ((int)uVar2 != 0) {
    local_108 = PdcpResiliencyV2CompletePoResiliencyCallback;
  }
  local_f0 = PdcChargePowerRequest;
  local_e8 = PdcDisplayStateUpdate;
  local_e0 = PdcPowerButtonSuppressionCallback;
  local_d8 = PdcpQueryResumeStats;
  local_d0 = PdcpUmpoInitializationCompleteCallback;
  local_c8 = PdcpExternalMonitorUpdateCallback;
  local_c0 = PdcpPlatformInitializationCompleteCallback;
  uVar1 = ZwPowerInformation(0x43,&local_198,0xe0,&local_b8,0xa8);
  PdcPoCallbacks = local_b8;
  DAT_140015068 = uStack_b0;
  DAT_140015070 = local_a8;
  DAT_140015078 = uStack_a0;
  DAT_140015080 = local_98;
  DAT_140015088 = uStack_90;
  DAT_140015090 = local_88;
  DAT_140015098 = uStack_80;
  DAT_1400150a0 = local_78;
  DAT_1400150a8 = uStack_70;
  DAT_1400150b0 = local_68;
  DAT_1400150b8 = uStack_60;
  DAT_1400150c0 = local_58;
  DAT_1400150c8 = uStack_50;
  DAT_1400150d0 = local_48;
  DAT_1400150d8 = uStack_40;
  DAT_1400150e0 = uStack_38;
  DAT_1400150e8 = uStack_30;
  DAT_1400150f0 = uStack_28;
  DAT_1400150f8 = uStack_20;
  DAT_140015100 = uStack_18;
  return uVar1;
}



===== PdcpInitializeInternalRequestGroupsClients @ 140033f98 =====

void PdcpInitializeInternalRequestGroupsClients(void)

{
  PdcGroupRequest((uint *)0x1,'\x01');
  DAT_140015138 = 1;
  PdcGroupRequest((uint *)0x0,'\x01');
  DAT_140015160._0_1_ = 1;
  return;
}



===== PdcPortInitialize @ 140033fcc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcPortInitialize(void)

{
  _DAT_140015038 = 0;
  _PdcPortMessageWorker = 0;
  DAT_140015008 = &PdcPortMessageQueue;
  PdcPortMessageQueue = &PdcPortMessageQueue;
  _DAT_140015030 = PdcPortMessageWorkerThread;
  return;
}



===== PdcResiliencyClientsInitialize @ 140034008 =====

void PdcResiliencyClientsInitialize(void)

{
  undefined8 *_Dst;
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  
  uVar4 = 0;
  puVar2 = &DAT_140013c90;
  do {
    iVar3 = (int)uVar4;
    memset(&PdcResiliencyClients + uVar4 * 0x70,0,0x70);
    _Dst = puVar2 + -6;
    memset(_Dst,0,0x70);
    *(undefined4 *)(puVar2 + -4) = 1;
    *(int *)(puVar2 + -1) = iVar3;
    if (iVar3 == 6) {
      puVar2[1] = puVar2;
      *puVar2 = puVar2;
    }
    else {
      uVar5 = 0;
      *puVar2 = 1;
      lVar1 = 0;
      PdcpResiliencyClientSetCurrentState((longlong)_Dst,0,0);
      PdcpResiliencyClientSetNextState((longlong)_Dst,lVar1,uVar5);
      PdcpResiliencyClientSetTransactionId((longlong)_Dst,lVar1,uVar5);
    }
    uVar4 = (ulonglong)(iVar3 + 1U);
    *(undefined4 *)(puVar2 + 3) = (&PdcpResiliencyV2PoResiliencyMap)[iVar3];
    puVar2 = puVar2 + 0xe;
  } while (iVar3 + 1U < 8);
  PdcInitializeTimer(0x140013ba0,PdcpResiliencyWatchdog,0,0,5);
  return;
}



===== PdcpResiliencyV2Initialize @ 1400340e0 =====

undefined8 PdcpResiliencyV2Initialize(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  
  memset(&DAT_140013724,0,0x474);
  piVar6 = &PdcpResiliencyV2PoResiliencyMap;
  PdcpResiliencyV2Context = 7;
  uVar5 = 0;
  puVar4 = &DAT_140013738;
  do {
    puVar4[6] = 0xffffffff;
    puVar1 = puVar4 + 0xc;
    puVar4[7] = uVar5;
    *puVar4 = 1;
    *(undefined4 **)(puVar4 + 0xe) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    puVar4[10] = 0;
    puVar4[8] = 0;
    iVar2 = *piVar6;
    piVar6 = piVar6 + 1;
    uVar5 = uVar5 + 1;
    puVar4[9] = -(uint)(iVar2 != 0) & 2;
    puVar4 = puVar4 + 0x1c;
  } while (uVar5 < 8);
  uVar3 = 0;
  PdcpResiliencyV2RequestInitialize
            (7,PdcpResiliencyV2ClientRegistrationRequestCallback,0,0x140013aa8);
  PdcInitializeTimer(0x140013ad0,PdcpResiliencyV2WatchdogCallback,uVar3,0,5);
  return 0;
}



===== PdcpReplayLidCloseInit @ 14003419c =====

void PdcpReplayLidCloseInit(void)

{
  int local_res8 [8];
  
  local_res8[0] = 1;
  PdcGetRegistryDwordValue
            (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",L"PdcReplayLidClose",
             1,local_res8);
  PdcpReplayLidCloseContext = local_res8[0] != 0;
  return;
}



===== PdcInitializePolicyWorker @ 1400341dc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcInitializePolicyWorker(void)

{
  KeInitializeSpinLock();
  PdcWorkerStatus = 0xffffffff;
  DAT_140013628 = &PdcPolicyIrpQueue;
  _PdcPolicyIrpQueue = &PdcPolicyIrpQueue;
  _DAT_140013650 = PdcpPolicyWorkerThread;
  _DAT_140013658 = 0x80000000;
  _DAT_140013610 = PdcpButtonWriteWorkerThread;
  _PdcPolicyWorker = 0;
  _DAT_140013618 = 0;
  _PdcButtonWriteWorker = 0;
  return;
}



===== PdcInitializePowerSettingCallbacks @ 14003425c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcInitializePowerSettingCallbacks(void)

{
  int iVar1;
  undefined **ppuVar2;
  ulonglong uVar3;
  
  DAT_1400135dc._4_4_ = 0;
  DAT_1400135e4 = 1;
  _DAT_1400135e8 = 0;
  _PdcPowerSettingValues = 0;
  ram0x0001400135c8 = 0;
  DAT_1400135d0 = 0;
  _DAT_1400135d8 = 0;
  iVar1 = PdcpSetButtonAction(&PdcPowerSettingValues,0);
  PdcpSetButtonAction(&DAT_1400135cc,iVar1 + 2);
  iVar1 = PdcpSetButtonAction(&DAT_1400135d8,0);
  ppuVar2 = &PdcInitialSettingCallbacks;
  uVar3 = (ulonglong)(iVar1 + 5);
  do {
    PoRegisterPowerSettingCallback(0,*ppuVar2,ppuVar2[1],0,0);
    ppuVar2 = ppuVar2 + 2;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  return;
}



===== PdcInitDriverServices @ 1400342fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcInitDriverServices(void)

{
  int iVar1;
  undefined1 auStack_278 [32];
  code *local_258;
  undefined8 local_250;
  undefined8 *local_248;
  int local_238;
  undefined4 local_234;
  undefined8 local_230;
  undefined1 local_228 [528];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_278;
  DAT_140032b60 = &PdcSwitches;
  PdcSwitches = &PdcSwitches;
  PdcRwLockInitialize((undefined8 *)&PdcSwitchStateLock);
  PdcRwLockInitialize((undefined8 *)&PdcShutdownLock);
  local_230 = (ulonglong)local_230._4_4_ << 0x20;
  local_248 = &local_230;
  local_258 = (code *)local_228;
  local_250 = CONCAT44(local_250._4_4_,0x208);
  local_238 = 1;
  local_234 = 5;
  iVar1 = RtlGetPersistedStateLocation
                    (L"Power",0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",0)
  ;
  if (-1 < iVar1) {
    PdcGetRegistryDwordValue(local_228,L"LidReliabilityState",1,&local_238);
  }
  PdcpDupLidStateContext = local_238 != 0;
  PdcGetRegistryDwordValue
            (L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power",
             L"LidReliabilityThreshold",5,&local_234);
  DAT_1400136f4 = local_234;
  _PdcpPowerButtonSuppression = 0;
  _DAT_1400136a8 = 0;
  _DAT_1400136b0 = 0;
  uRam00000001400136b8 = 0;
  _DAT_1400136c0 = 0;
  _DAT_1400136c8 = 0;
  PdcRwLockInitialize((undefined8 *)&DAT_1400136b0);
  _DAT_140013718 = 0;
  _PdcpDeferSwitchSignalWorkItem = 0;
  local_248 = &local_230;
  local_230 = 0;
  local_250 = 0;
  _DAT_140013710 = PdcpDeferSwitchSignalWorkItemCallback;
  local_258 = PdcpNotifyPolicyDevice;
  IoRegisterPlugPlayNotification(2,1,&GUID_DEVICE_SYS_BUTTON,PdcDriverObject);
  return;
}



===== PdcDiagInitialize @ 140034494 =====

undefined8 PdcDiagInitialize(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = McGenEventRegister_EtwRegister();
  if ((iVar1 < 0) ||
     (uVar2 = EtwRegister(&SLEEPSTUDY_ETW_PROVIDER,0,0,&PdcDiagSleepStudyHandle), (int)uVar2 < 0)) {
    return 0;
  }
  PdcDiagSleepStudyHandleRegistered = 1;
  return uVar2;
}



===== PdcPpmInitialize @ 1400344dc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PdcPpmInitialize(void)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  short sVar4;
  wchar_t *pwVar5;
  undefined8 *puVar6;
  ushort uVar7;
  wchar_t *pwVar8;
  longlong local_res8;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = 0;
  local_28 = 0;
  local_res8 = 0;
  local_20 = (wchar_t *)0x0;
  local_10 = 0;
  _DAT_140013590 = PdcpPpmProfileEvaluationWorker;
  _DAT_140013598 = 0;
  _PdcPpmProfileEvaluationWorkItem = 0;
  uVar2 = Feature_PDCParallelAlpcProcess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    PdcRwLockInitialize((undefined8 *)&PdcPpmProfileLock);
  }
  uVar1 = RtlStringFromGUID(&GUID_PROCESSOR_SETTINGS_SUBGROUP,&local_18);
  uVar2 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    uVar7 = (short)local_18 + 0x94;
    uVar2 = (ulonglong)uVar7;
    local_20 = (wchar_t *)PdcAllocate('\x01');
    if (local_20 == (wchar_t *)0x0) {
      uVar2 = 0xc0000017;
    }
    else {
      local_28 = (ulonglong)CONCAT42((int)(local_28 >> 0x20),uVar7) << 0x10;
      memset(local_20,0,uVar2);
      if (((local_28 & 1) == 0) && ((local_28 & 0x10000) == 0)) {
        if ((((ushort)local_28 <= local_28._2_2_) && (local_28._2_2_ != 0xffff)) &&
           ((local_20 != (wchar_t *)0x0 || (((ushort)local_28 == 0 && (local_28._2_2_ == 0)))))) {
          uVar2 = 0x7fff;
          sVar4 = 0;
          pwVar5 = local_20;
          uVar3 = (ulonglong)(local_28._2_2_ >> 1);
          for (pwVar8 = 
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\Profile\\Events\\";
              ((uVar3 != 0 && (uVar2 != 0)) && (*pwVar8 != L'\0')); pwVar8 = pwVar8 + 1) {
            *pwVar5 = *pwVar8;
            pwVar5 = pwVar5 + 1;
            uVar2 = uVar2 - 1;
            sVar4 = sVar4 + 1;
            uVar3 = ((ulonglong)(local_28._2_2_ >> 1) - 0x7fff) + uVar2;
          }
          local_28 = CONCAT62(local_28._2_6_,sVar4 * 2);
        }
      }
      puVar6 = &local_18;
      RtlAppendUnicodeStringToString(&local_28);
      uVar1 = PdcpPpmOpenRegistryKey(&local_28,puVar6,uVar2,0,&local_res8);
      if ((int)uVar1 < 0) {
        uVar2 = 0;
        if (uVar1 != 0xc0000034) {
          uVar2 = (ulonglong)uVar1;
        }
      }
      else {
        uVar3 = PdcpPpmEnumerateProfiles(local_res8);
        uVar2 = uVar3 & 0xffffffff;
        if (-1 < (int)uVar3) {
          uVar1 = PdcpPpmRegisterProfiles();
          uVar2 = (ulonglong)uVar1;
        }
      }
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  if (local_20 != (wchar_t *)0x0) {
    PdcFree(local_20);
  }
  RtlFreeUnicodeString(&local_18);
  return uVar2;
}



===== PdcpPpmEnumerateProfiles @ 1400346c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PdcpPpmEnumerateProfiles(undefined8 param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  int iVar15;
  undefined1 auStackY_228 [8];
  undefined1 auStackY_220 [24];
  uint local_1f8 [2];
  undefined8 local_1f0;
  undefined4 local_1e8;
  undefined8 local_1e0;
  undefined2 *local_1d8;
  undefined8 local_1d0;
  undefined1 *puStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined1 local_1a8 [12];
  uint local_19c;
  undefined1 local_198 [96];
  undefined2 local_138 [128];
  ulonglong local_38;
  
  puVar11 = auStackY_228;
  puVar10 = auStackY_228;
  local_38 = __security_cookie ^ (ulonglong)auStackY_228;
  uVar9 = 0;
  local_1e0 = 0x1000000;
  local_1e8 = 0;
  local_1f8[0] = 0;
  local_1d8 = local_138;
  local_1f0 = 0;
  local_1c0 = 0;
  uStack_1b8 = 0;
  local_1d0 = 0;
  puStack_1c8 = (undefined1 *)0x0;
  iVar3 = 1;
  iVar7 = 0;
  do {
    iVar15 = iVar3;
    uVar14 = 0;
    iVar3 = ZwEnumerateKey(param_1,iVar7,0,local_1a8);
    if (iVar3 == -0x7fffffe6) {
LAB_140034988:
      *(undefined8 *)(puVar11 + -8) = 0x140034999;
      return uVar9;
    }
    if (local_19c < 0x4f) {
      puStack_1c8 = local_198;
      puVar4 = &local_1c0;
      local_1d0._0_4_ = CONCAT22((short)local_19c,(short)local_19c);
      iVar3 = RtlGUIDFromString(&local_1d0);
      if ((-1 < iVar3) &&
         (iVar3 = PdcpPpmOpenRegistryKey(&local_1d0,puVar4,uVar14,param_1,&local_1f0), -1 < iVar3))
      {
        local_1e0 = local_1e0 & 0xffffffffffff0000;
        iVar3 = PdcpPpmReadProfileProperties(local_1f0,local_1f8,&local_1e0);
        if ((-1 < iVar3) && (local_1f8[0] < 0x100)) {
          uVar12 = (uint)(ushort)local_1e0;
          puVar4 = (undefined8 *)PdcAllocate('\0');
          if (puVar4 != (undefined8 *)0x0) {
            memset(puVar4,0,(ulonglong)(uVar12 + 0x92));
            puVar4[4] = puVar4 + 0x12;
            puVar1 = puVar4 + 9;
            puVar4[10] = puVar1;
            *puVar1 = puVar1;
            *(undefined1 *)(puVar4 + 5) = (undefined1)local_1f8[0];
            puVar4[2] = local_1c0;
            puVar4[3] = uStack_1b8;
            uVar5 = Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar5 == 0) {
              KeInitializeEvent(puVar4 + 0xb,1);
              puVar4[0x11] = puVar4;
              puVar4[0x10] = PdcpPpmProfileClientWorker;
              puVar4[0xe] = 0;
            }
            puVar8 = (undefined2 *)puVar4[4];
            uVar5 = (ulonglong)(uVar12 + 2 >> 1);
            if (uVar5 - 1 < 0x7fff) {
              if (((local_1e0 & 1) == 0) && ((local_1e0 & 0x10000) == 0)) {
                if ((((ushort)local_1e0 <= local_1e0._2_2_) && (local_1e0._2_2_ != 0xffff)) &&
                   ((local_1d8 != (undefined2 *)0x0 ||
                    (((ushort)local_1e0 == 0 && (local_1e0._2_2_ == 0)))))) {
                  uVar13 = (ulonglong)((ushort)local_1e0 >> 1);
                  puVar6 = local_1d8;
                  do {
                    if (uVar13 == 0) break;
                    uVar13 = uVar13 - 1;
                    *puVar8 = *puVar6;
                    puVar6 = puVar6 + 1;
                    puVar8 = puVar8 + 1;
                    uVar5 = uVar5 - 1;
                  } while (uVar5 != 0);
                  puVar6 = puVar8 + -1;
                  if (uVar5 != 0) {
                    puVar6 = puVar8;
                  }
                  *puVar6 = 0;
                  goto LAB_1400348ee;
                }
              }
              *puVar8 = 0;
            }
LAB_1400348ee:
            PdcpPpmEnumerateScenarios((longlong)puVar4,local_1f0);
            ZwClose(local_1f0);
            if (*(undefined ***)PTR_PdcPpmProfileList_140031078 == &PdcPpmProfileList) {
              *puVar4 = &PdcPpmProfileList;
              puVar4[1] = PTR_PdcPpmProfileList_140031078;
              *(undefined8 **)PTR_PdcPpmProfileList_140031078 = puVar4;
              PTR_PdcPpmProfileList_140031078 = (undefined *)puVar4;
              goto LAB_140034930;
            }
            pcVar2 = (code *)swi(0x29);
            (*pcVar2)(3);
            puVar10 = auStackY_220;
          }
          *(undefined8 *)(puVar10 + -8) = 0x14003497e;
          ZwClose(*(undefined8 *)(puVar10 + 0x38));
          uVar9 = 0xc0000017;
          puVar11 = puVar10;
          goto LAB_140034988;
        }
        ZwClose(local_1f0);
      }
    }
LAB_140034930:
    iVar3 = iVar15 + 1;
    iVar7 = iVar15;
  } while( true );
}



===== PdcpPpmEnumerateScenarios @ 1400349bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PdcpPpmEnumerateScenarios(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  short sVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  short *psVar6;
  longlong *plVar7;
  ulonglong uVar8;
  short *psVar9;
  ulonglong uVar10;
  uint uVar11;
  int iVar12;
  longlong lVar13;
  longlong lVar14;
  undefined8 uVar15;
  int iVar16;
  undefined1 auStackY_128 [32];
  undefined8 local_e8;
  undefined1 *puStack_e0;
  undefined8 local_d8;
  longlong local_d0;
  longlong lStack_c8;
  undefined1 local_b8 [12];
  uint local_ac;
  undefined1 local_a8 [96];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  lVar1 = param_1 + 0x48;
  local_d8 = 0;
  local_d0 = 0;
  lStack_c8 = 0;
  local_e8 = 0;
  puStack_e0 = (undefined1 *)0x0;
  iVar5 = 1;
  iVar12 = 0;
  do {
    iVar16 = iVar5;
    uVar10 = 0;
    uVar15 = 0;
    iVar5 = ZwEnumerateKey(param_2,iVar12,0,local_b8);
    if (iVar5 == -0x7fffffe6) {
LAB_140034c7f:
      if ((*(longlong *)(param_1 + 0x10) == 0x4869272e4569e601) &&
         (*(longlong *)(param_1 + 0x18) == 0x6f96d7036c1cabbc)) {
        _DAT_140012f40 = 0xffffffffffffffff;
        _DAT_140012e70 = PdcPpmMediaBufferingScenarioName;
        _DAT_140012e78 = 0x4da6378823456e92;
        uRam0000000140012e80 = 0x96cd899d2599c3a2;
        DAT_140012e90 = 3;
        DAT_140012e88 = param_1;
        uVar10 = Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar10 != 0) {
          PdcRwLockInitialize((undefined8 *)&DAT_140012e98);
        }
        plVar7 = *(longlong **)(param_1 + 0x50);
        if (*plVar7 != lVar1) {
LAB_140034d31:
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        _PdcPpmMediaBufferingScenario = lVar1;
        _DAT_140012e68 = plVar7;
        *plVar7 = (longlong)&PdcPpmMediaBufferingScenario;
        *(undefined **)(param_1 + 0x50) = &PdcPpmMediaBufferingScenario;
      }
      return;
    }
    if (local_ac < 0x4f) {
      puStack_e0 = local_a8;
      plVar7 = &local_d0;
      local_e8._0_4_ = CONCAT22((short)local_ac,(short)local_ac);
      iVar5 = RtlGUIDFromString(&local_e8);
      if ((-1 < iVar5) &&
         (iVar5 = PdcpPpmOpenRegistryKey(&local_e8,plVar7,uVar15,param_2,&local_d8), -1 < iVar5)) {
        iVar5 = EaQueryAggregatedEventParameters(param_2,&local_d0);
        psVar9 = psRam0000000000000038;
        if (-1 < iVar5) {
          if (psRam0000000000000038 == (short *)0x0) {
            uVar11 = 0xc000000d;
          }
          else {
            lVar13 = 0x3fffffff;
            psVar6 = psRam0000000000000038;
            do {
              if (*psVar6 == 0) break;
              psVar6 = psVar6 + 1;
              lVar13 = lVar13 + -1;
            } while (lVar13 != 0);
            uVar11 = ~-(uint)(lVar13 != 0) & 0xc000000d;
            if (lVar13 != 0) {
              uVar10 = -(ulonglong)(lVar13 != 0) & (0x3fffffff - lVar13) * 2;
            }
          }
          if ((int)uVar11 < 0) {
            EaFreeAggregatedEventParameters(0);
          }
          else {
            plVar7 = (longlong *)PdcAllocate('\0');
            if (plVar7 == (longlong *)0x0) {
              EaFreeAggregatedEventParameters(0);
              goto LAB_140034c7f;
            }
            memset(plVar7,0,uVar10 + 0xf2);
            plVar7[5] = param_1;
            plVar7[0x1c] = -1;
            plVar7[0xc] = 0;
            plVar7[2] = (longlong)(plVar7 + 0x1e);
            *(undefined4 *)(plVar7 + 6) = 3;
            plVar7[3] = local_d0;
            plVar7[4] = lStack_c8;
            uVar8 = Feature_SpmAsyncEaCallout__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar8 == 0) {
              plVar7[0x18] = (longlong)plVar7;
              plVar7[0x17] = (longlong)PdcpPpmScenarioDeleteWorker;
              plVar7[0x15] = 0;
              KeInitializeEvent(plVar7 + 0x12,1);
            }
            else {
              PdcRwLockInitialize(plVar7 + 7);
            }
            uVar10 = uVar10 + 2 >> 1;
            psVar6 = (short *)plVar7[2];
            if (uVar10 != 0) {
              if (uVar10 < 0x80000000) {
                lVar14 = 0x7ffffffe - uVar10;
                lVar13 = (longlong)psVar9 - (longlong)psVar6;
                do {
                  if ((lVar14 + uVar10 == 0) ||
                     (sVar2 = *(short *)(lVar13 + (longlong)psVar6), sVar2 == 0)) break;
                  *psVar6 = sVar2;
                  psVar6 = psVar6 + 1;
                  uVar10 = uVar10 - 1;
                } while (uVar10 != 0);
                psVar9 = psVar6 + -1;
                if (uVar10 != 0) {
                  psVar9 = psVar6;
                }
                *psVar9 = 0;
              }
              else {
                *psVar6 = 0;
              }
            }
            plVar3 = *(longlong **)(param_1 + 0x50);
            if (*plVar3 != lVar1) goto LAB_140034d31;
            *plVar7 = lVar1;
            plVar7[1] = (longlong)plVar3;
            *plVar3 = (longlong)plVar7;
            *(longlong **)(param_1 + 0x50) = plVar7;
          }
        }
      }
    }
    iVar5 = iVar16 + 1;
    iVar12 = iVar16;
  } while( true );
}



===== PdcpPpmRegisterProfiles @ 140034d40 =====

int PdcpPpmRegisterProfiles(void)

{
  int iVar1;
  undefined **ppuVar2;
  void *_Dst;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  ulonglong uVar6;
  
  uVar4 = 0;
  bVar5 = 0;
  uVar6 = 0;
  ppuVar2 = (undefined **)PdcPpmProfileList;
  if ((undefined **)PdcPpmProfileList != &PdcPpmProfileList) {
    do {
      ppuVar2 = (undefined **)*ppuVar2;
      bVar5 = bVar5 + 1;
    } while (ppuVar2 != &PdcPpmProfileList);
    if (bVar5 != 0) {
      if (0x1f < bVar5) {
        return -0x3fffffff;
      }
      if (SUB168(ZEXT816(0x20) * ZEXT116(bVar5),8) != 0) {
        return -0x3fffff6b;
      }
      _Dst = (void *)PdcAllocate('\x01');
      if (_Dst == (void *)0x0) {
        return -0x3fffffe9;
      }
      memset(_Dst,0,SUB168(ZEXT816(0x20) * ZEXT116(bVar5),0));
      for (ppuVar2 = (undefined **)PdcPpmProfileList; ppuVar2 != &PdcPpmProfileList;
          ppuVar2 = (undefined **)*ppuVar2) {
        lVar3 = uVar6 * 0x20;
        uVar6 = (ulonglong)(byte)((char)uVar6 + 1);
        *(undefined ***)(lVar3 + (longlong)_Dst) = ppuVar2 + 2;
        *(undefined **)(lVar3 + 8 + (longlong)_Dst) = ppuVar2[4];
        *(undefined1 *)(lVar3 + 0x10 + (longlong)_Dst) = *(undefined1 *)(ppuVar2 + 5);
      }
      iVar1 = PdcRegisterPpmProfiles();
      if (-1 < iVar1) {
        for (ppuVar2 = (undefined **)PdcPpmProfileList; ppuVar2 != &PdcPpmProfileList;
            ppuVar2 = (undefined **)*ppuVar2) {
          lVar3 = uVar4 * 0x20;
          uVar4 = (ulonglong)(byte)((char)uVar4 + 1);
          ppuVar2[6] = *(undefined **)(lVar3 + 0x18 + (longlong)_Dst);
        }
      }
      PdcFree(_Dst);
      return iVar1;
    }
  }
  return 0;
}



===== PdcGroupsInitialize @ 140034e80 =====

void PdcGroupsInitialize(void)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = 0;
  puVar2 = &PdcRequestGroups;
  do {
    if (((uVar1 < 6) && (puVar2 != (uint *)0x0)) && (puVar2[0x26] != 0)) {
      PdcPhasesAddBlockerAccountingEntry
                (*puVar2,*(undefined8 *)(puVar2 + 0x24),(char)puVar2[0x26],
                 (undefined8 *)(puVar2 + 0xe));
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 0x28;
  } while ((int)uVar1 < 6);
  return;
}


