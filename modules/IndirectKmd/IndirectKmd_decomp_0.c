
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



===== __C_specific_handler @ 14000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __cpu_features_init @ 140001030 =====

/* WARNING: Removing unreachable block (ram,0x00014000109a) */
/* WARNING: Removing unreachable block (ram,0x000140001049) */
/* WARNING: Removing unreachable block (ram,0x00014000103a) */

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



===== __GSHandlerCheck @ 1400010ec =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001110 =====

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



===== CALLONEXIT<<lambda_bd554ddd1f9fda9e2fe11075810952ec>_> @ 140001178 =====

undefined8 *
`anonymous_namespace'::CALLONEXIT<<lambda_bd554ddd1f9fda9e2fe11075810952ec>_>
          (undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return param_1;
}



===== TargetModeKnown @ 140001188 =====

ulonglong `anonymous_namespace'::TargetModeKnown(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong in_RAX;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(uint *)(param_2 + 0xe0) != 0) {
    lVar1 = *(longlong *)(param_2 + 0xd8);
    do {
      if ((((((*(int *)(lVar1 + 4 + uVar3 * 0x48) == *(int *)(param_1 + 0xc)) &&
             (in_RAX = (ulonglong)*(uint *)(param_1 + 0x10),
             *(uint *)(lVar1 + 8 + uVar3 * 0x48) == *(uint *)(param_1 + 0x10))) &&
            (in_RAX = (ulonglong)*(uint *)(param_1 + 0x14),
            *(uint *)(lVar1 + 0xc + uVar3 * 0x48) == *(uint *)(param_1 + 0x14))) &&
           ((in_RAX = (ulonglong)*(uint *)(param_1 + 0x18),
            *(uint *)(lVar1 + 0x10 + uVar3 * 0x48) == *(uint *)(param_1 + 0x18) &&
            (in_RAX = (ulonglong)*(uint *)(param_1 + 0x1c),
            *(uint *)(lVar1 + 0x14 + uVar3 * 0x48) == *(uint *)(param_1 + 0x1c))))) &&
          ((in_RAX = (ulonglong)*(uint *)(param_1 + 0x20),
           *(uint *)(lVar1 + 0x18 + uVar3 * 0x48) == *(uint *)(param_1 + 0x20) &&
           ((in_RAX = (ulonglong)*(uint *)(param_1 + 0x24),
            *(uint *)(lVar1 + 0x1c + uVar3 * 0x48) == *(uint *)(param_1 + 0x24) &&
            (in_RAX = (ulonglong)*(uint *)(param_1 + 0x28),
            *(uint *)(lVar1 + 0x20 + uVar3 * 0x48) == *(uint *)(param_1 + 0x28))))))) &&
         ((in_RAX = *(ulonglong *)(param_1 + 0x30),
          *(ulonglong *)(lVar1 + 0x28 + uVar3 * 0x48) == in_RAX &&
          (in_RAX = 0,
          *(uint *)(lVar1 + 0x30 + uVar3 * 0x48) == (*(uint *)(param_1 + 0x38) >> 3 & 0x3f))))) {
        return 1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(param_2 + 0xe0));
  }
  return in_RAX & 0xffffffffffffff00;
}



===== Feature_SupressIddGammaDxglogError__private_IsEnabledDeviceUsageNoInline @ 140001224 =====

ulonglong Feature_SupressIddGammaDxglogError__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SupressIddGammaDxglogError__private_featureState;
  if ((Feature_SupressIddGammaDxglogError__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SupressIddGammaDxglogError__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SupressIddGammaDxglogError__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SupressIddGammaDxglogError__private_IsEnabledFallback @ 14000125c =====

void Feature_SupressIddGammaDxglogError__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_SupressIddGammaDxglogError__private_descriptor);
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140001278 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_1400081e8;
  uVar2 = 0;
  if (DAT_1400081e8 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_1400081e8;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(IddCxEtwProvider_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0x_EtwWriteTransfer @ 1400012dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0x_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = &local_res20;
  local_1c = 0;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&KMD_SET_TIMINGS_STOP,param_3,2,local_38);
  return;
}



===== McTemplateK0xq_EtwWriteTransfer @ 140001340 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res20;
  local_2c = 0;
  local_28 = &param_5;
  local_30 = 8;
  local_1c = 0;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&KMD_SET_TIMINGS_START,param_3,3,local_48);
  return;
}



===== McTemplateK0xqqtqqqqq_EtwWriteTransfer @ 1400013b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xqqtqqqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  undefined8 local_res20;
  undefined1 auStackY_e8 [32];
  undefined8 local_b8 [2];
  undefined8 *local_a8;
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
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8 = &local_res20;
  local_a0 = 8;
  local_98 = &param_5;
  local_90 = 4;
  local_88 = &param_6;
  local_80 = 4;
  local_78 = &param_7;
  local_68 = &param_8;
  local_58 = &param_9;
  local_48 = &param_10;
  local_38 = &param_11;
  local_28 = &param_12;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&KMD_SET_TIMINGS_PATH,param_3,10,local_b8);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400014a4 =====

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
LAB_1400016a7:
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
LAB_14000157f:
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
      if (param_3 == 4) goto LAB_1400016a7;
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
        goto LAB_14000157f;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140001790 =====

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
      goto LAB_140001861;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140001861;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140001861;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140001861;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140001861;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140001861;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140001861;
    }
  }
  uVar3 = 0xff;
LAB_140001861:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400018b8 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400019a8 =====

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
LAB_140001a5b:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140001a89;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140001a5b;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140001a89:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140001c14 =====

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



===== wil_details_IsEnabledFallback @ 140001c78 =====

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



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001d10 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int),&INDIRECT_DEVICE::TerminateOutput>
     ::CallWithVerify<&VerifyAdapter,_1073741811>(INDIRECT_DEVICE *param_1,uint param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::TerminateOutput(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001d40 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int,unsigned_long,unsigned_long,unsigned_long,void_*),&INDIRECT_DEVICE::I2CReceiveDataFromDisplay>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,uint param_2,ulong param_3,ulong param_4,ulong param_5,
               void *param_6)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::I2CReceiveDataFromDisplay
                      (param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001d80 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int,unsigned_long,unsigned_long,void_const_*),&INDIRECT_DEVICE::I2CTransmitDataToDisplay>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,uint param_2,ulong param_3,ulong param_4,void *param_5)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::I2CTransmitDataToDisplay(param_1,param_2,param_3,param_4,param_5);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001dc0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int,unsigned_long,unsigned_long,void_const_*,unsigned_long,unsigned_long,unsigned_long,void_*),&INDIRECT_DEVICE::I2CTransmitAndReceiveDataFromDisplay>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,uint param_2,ulong param_3,ulong param_4,void *param_5,
               ulong param_6,ulong param_7,ulong param_8,void *param_9)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::I2CTransmitAndReceiveDataFromDisplay
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001e30 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int,unsigned_int_*,unsigned_int_*),&INDIRECT_DEVICE::GetMonitorPhysicalSizeOverride>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,uint param_2,uint *param_3,uint *param_4)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::GetMonitorPhysicalSizeOverride(param_1,param_2,param_3,param_4);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001e60 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int,_DXGK_IDD_VIRTUAL_MONITOR_INFO_*),&INDIRECT_DEVICE::GetIdVirtualMonitorInfo>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,uint param_2,_DXGK_IDD_VIRTUAL_MONITOR_INFO *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::GetIdVirtualMonitorInfo(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001e90 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int,_LUID_*),&INDIRECT_DEVICE::GetIdRenderAdapter>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,uint param_2,_LUID *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::GetIdRenderAdapter(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001ec0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int,void_*,_LUID),&INDIRECT_DEVICE::SetSwapChainHandle>
     ::CallWithVerify<&VerifyAdapter,_1073741811>(int *param_1)

{
  long lVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetSwapChainHandle();
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001ef0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int,unsigned___int64_*),&INDIRECT_DEVICE::GetOpmMftContext>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,uint param_2,__uint64 *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::GetOpmMftContext(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001f20 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_int,enum__DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS,void_*_*),&INDIRECT_DEVICE::OPMCreateProtectedOutput>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,uint param_2,_DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS param_3,
               void **param_4)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::OPMCreateProtectedOutput(param_1,param_2,param_3,param_4);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001f50 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(long),&INDIRECT_DEVICE::PostStartDevice>::
     CallWithVerify<&VerifyAdapter,_1073741811>(INDIRECT_DEVICE *param_1,long param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::PostStartDevice(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001f80 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,_DXGK_CHILD_CONTAINER_ID_*),&INDIRECT_DEVICE::GetChildContainerId>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,ulong param_2,_DXGK_CHILD_CONTAINER_ID *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::GetChildContainerId(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001fb0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,_DXGK_DEVICE_DESCRIPTOR_*),&INDIRECT_DEVICE::QueryDeviceDescriptor>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,ulong param_2,_DXGK_DEVICE_DESCRIPTOR *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::QueryDeviceDescriptor(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140001fe0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,_DXGK_MIRACAST_CAPS_*),&INDIRECT_DEVICE::MiracastQueryCaps>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,ulong param_2,_DXGK_MIRACAST_CAPS *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::MiracastQueryCaps(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002010 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,_VIDEO_REQUEST_PACKET_*),&INDIRECT_DEVICE::DispatchIoRequest>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,ulong param_2,_VIDEO_REQUEST_PACKET *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::DispatchIoRequest(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002040 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,void_*,unsigned_long,void_*,unsigned_long_*),&INDIRECT_DEVICE::ReceiveMessageFromUserMode>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,ulong param_2,void *param_3,ulong param_4,void *param_5,
               ulong *param_6)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::ReceiveMessageFromUserMode
                      (param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002080 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,void_const_*),&INDIRECT_DEVICE::SetPreStartPrivateData>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,ulong param_2,void *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetPreStartPrivateData(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400020b0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,enum__DEVICE_POWER_STATE,enum_POWER_ACTION),&INDIRECT_DEVICE::SetPowerState>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,ulong param_2,_DEVICE_POWER_STATE param_3,
               POWER_ACTION param_4)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetPowerState(param_1,param_2,param_3,param_4);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400020e0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_QUERYCONNECTIONCHANGE_*),&INDIRECT_DEVICE::QueryConnectionChange>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_QUERYCONNECTIONCHANGE *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::QueryConnectionChange(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002110 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETTARGETADJUSTEDCOLORIMETRY2_*),&INDIRECT_DEVICE::SetTargetAdjustedColorimetry>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_SETTARGETADJUSTEDCOLORIMETRY2 *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetTargetAdjustedColorimetry(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002140 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETTIMINGSFROMVIDPN_*),&INDIRECT_DEVICE::SetTimingsFromVidPn>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_SETTIMINGSFROMVIDPN *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetTimingsFromVidPn(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002170 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_UPDATEMONITORLINKINFO_*),&INDIRECT_DEVICE::UpdateMonitorLinkInfo>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_UPDATEMONITORLINKINFO *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::UpdateMonitorLinkInfo(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400021a0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGK_CHILD_DESCRIPTOR_*,unsigned_long),&INDIRECT_DEVICE::QueryChildRelations>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGK_CHILD_DESCRIPTOR *param_2,ulong param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::QueryChildRelations(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400021d0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGK_CHILD_STATUS_*,unsigned_char),&INDIRECT_DEVICE::QueryChildStatus>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGK_CHILD_STATUS *param_2,uchar param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::QueryChildStatus(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002200 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGK_IDD_DISPLAY_CAPS_*),&INDIRECT_DEVICE::GetIdDisplayCaps>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGK_IDD_DISPLAY_CAPS *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::GetIdDisplayCaps(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002230 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGK_MIRACAST_DISPLAY_CALLBACKS_*,void_*_*,unsigned_long_*),&INDIRECT_DEVICE::MiracastCreateContext>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGK_MIRACAST_DISPLAY_CALLBACKS *param_2,void **param_3,
               ulong *param_4)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::MiracastCreateContext(param_1,param_2,param_3,param_4);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002260 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGK_START_INFO_*,_DXGKRNL_INTERFACE_*,unsigned_long_*,unsigned_long_*),&INDIRECT_DEVICE::StartDevice>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGK_START_INFO *param_2,_DXGKRNL_INTERFACE *param_3,
               ulong *param_4,ulong *param_5)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::StartDevice(param_1,param_2,param_3,param_4,param_5);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400022a0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_QUERY_INTERFACE_*),&INDIRECT_DEVICE::QueryInterface>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_QUERY_INTERFACE *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::QueryInterface(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400022d0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(void_*),&INDIRECT_DEVICE::OPMDestroyProtectedOutput>
     ::CallWithVerify<&VerifyAdapter,_1073741811>(INDIRECT_DEVICE *param_1,void *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::OPMDestroyProtectedOutput(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002300 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(void_*,unsigned_long,void_*,unsigned_long,void_*,unsigned_long_*),&INDIRECT_DEVICE::MiracastHandleIoControl>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5,
               void *param_6,ulong *param_7)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::MiracastHandleIoControl
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002350 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(void_*,_DXGKMDT_OPM_RANDOM_NUMBER_*),&INDIRECT_DEVICE::OPMGetRandomNumber>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,void *param_2,_DXGKMDT_OPM_RANDOM_NUMBER *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::OPMGetRandomNumber(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002380 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(void_*,_DXGKMDT_OPM_CONFIGURE_PARAMETERS_const_*,unsigned_long,void_const_*),&INDIRECT_DEVICE::OPMConfigureProtectedOutput>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,void *param_2,_DXGKMDT_OPM_CONFIGURE_PARAMETERS *param_3,
               ulong param_4,void *param_5)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::OPMConfigureProtectedOutput(param_1,param_2,param_3,param_4,param_5);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400023c0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(void_*,_DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS_const_*,_DXGKMDT_OPM_REQUESTED_INFORMATION_*),&INDIRECT_DEVICE::OPMGetCOPPCompatibleInformation>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,void *param_2,
               _DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS *param_3,
               _DXGKMDT_OPM_REQUESTED_INFORMATION *param_4)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::OPMGetCOPPCompatibleInformation(param_1,param_2,param_3,param_4);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400023f0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(void_*,_DXGKMDT_OPM_ENCRYPTED_PARAMETERS_const_*),&INDIRECT_DEVICE::OPMSetSigningKeyAndSequenceNumbers>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,void *param_2,_DXGKMDT_OPM_ENCRYPTED_PARAMETERS *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::OPMSetSigningKeyAndSequenceNumbers(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002420 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(void_*,_DXGKMDT_OPM_GET_INFO_PARAMETERS_const_*,_DXGKMDT_OPM_REQUESTED_INFORMATION_*),&INDIRECT_DEVICE::OPMGetInformation>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,void *param_2,_DXGKMDT_OPM_GET_INFO_PARAMETERS *param_3,
               _DXGKMDT_OPM_REQUESTED_INFORMATION *param_4)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::OPMGetInformation(param_1,param_2,param_3,param_4);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002450 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_DISPLAYDETECTCONTROL_const_*),&INDIRECT_DEVICE::DisplayDetectControl>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_DISPLAYDETECTCONTROL *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::DisplayDetectControl(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002480 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_PRESENT_DISPLAYONLY_const_*),&INDIRECT_DEVICE::PresentDisplayOnly>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_PRESENT_DISPLAYONLY *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::PresentDisplayOnly(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400024b0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETPALETTE_const_*),&INDIRECT_DEVICE::SetPalette>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_SETPALETTE *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetPalette(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400024e0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETPOINTERPOSITION_const_*),&INDIRECT_DEVICE::SetPointerPosition>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_SETPOINTERPOSITION *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetPointerPosition(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002510 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETPOINTERSHAPE_const_*),&INDIRECT_DEVICE::SetPointerShape>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_SETPOINTERSHAPE *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetPointerShape(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002540 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETTARGETGAMMA_const_*),&INDIRECT_DEVICE::SetTargetGamma>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_SETTARGETGAMMA *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetTargetGamma(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002570 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(enum__DXGKMDT_CERTIFICATE_TYPE,unsigned_long,void_*),&INDIRECT_DEVICE::OPMGetCertificate>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKMDT_CERTIFICATE_TYPE param_2,ulong param_3,
               void *param_4)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::OPMGetCertificate(param_1,param_2,param_3,param_4);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400025a0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(enum__DXGKMDT_CERTIFICATE_TYPE,unsigned_long_*),&INDIRECT_DEVICE::OPMGetCertificateSize>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKMDT_CERTIFICATE_TYPE param_2,ulong *param_3)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::OPMGetCertificateSize(param_1,param_2,param_3);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400025d0 =====

long CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(void),&INDIRECT_DEVICE::StopDevice>::
     CallWithVerify<&VerifyAdapter,_1073741811>(INDIRECT_DEVICE *param_1)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::StopDevice(param_1);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002600 =====

long CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_ISSUPPORTEDVIDPN_*),&INDIRECT_DEVICE::IsSupportedVidPn>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_ISSUPPORTEDVIDPN *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::IsSupportedVidPn(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002630 =====

long CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_QUERYVIDPNHWCAPABILITY_*),&INDIRECT_DEVICE::QueryVidPnHWCapability>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_QUERYVIDPNHWCAPABILITY *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::QueryVidPnHWCapability(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002660 =====

long CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_ENUMVIDPNCOFUNCMODALITY_const_*),&INDIRECT_DEVICE::EnumVidPnCofuncModality>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_ENUMVIDPNCOFUNCMODALITY *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::EnumVidPnCofuncModality(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002690 =====

long CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_ESCAPE_const_*),&INDIRECT_DEVICE::Escape>
     ::CallWithVerify<&VerifyAdapter,_1073741811>(INDIRECT_DEVICE *param_1,_DXGKARG_ESCAPE *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::Escape(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400026c0 =====

long CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_QUERYADAPTERINFO_const_*),&INDIRECT_DEVICE::QueryAdapterInfo>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_QUERYADAPTERINFO *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::QueryAdapterInfo(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 1400026f0 =====

long CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_RECOMMENDFUNCTIONALVIDPN_const_*),&INDIRECT_DEVICE::RecommendFunctionalVidPn>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_RECOMMENDFUNCTIONALVIDPN *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::RecommendFunctionalVidPn(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002720 =====

long CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_RECOMMENDMONITORMODES_const_*),&INDIRECT_DEVICE::RecommendMonitorModes>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_RECOMMENDMONITORMODES *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::RecommendMonitorModes(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002750 =====

long CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETVIDPNSOURCEVISIBILITY_const_*),&INDIRECT_DEVICE::SetVidPnSourceVisibility>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_SETVIDPNSOURCEVISIBILITY *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::SetVidPnSourceVisibility(param_1,param_2);
  }
  return lVar1;
}



===== CallWithVerify<&VerifyAdapter,-1073741811> @ 140002780 =====

long CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH_const_*),&INDIRECT_DEVICE::UpdateActiveVidPnPresentPath>
     ::CallWithVerify<&VerifyAdapter,_1073741811>
               (INDIRECT_DEVICE *param_1,_DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH *param_2)

{
  long lVar1;
  
  if ((param_1 == (INDIRECT_DEVICE *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = INDIRECT_DEVICE::UpdateActiveVidPnPresentPath(param_1,param_2);
  }
  return lVar1;
}



===== VIDPN_SOURCE_INFO @ 1400027ac =====

/* public: __cdecl VIDPN_SOURCE_INFO::VIDPN_SOURCE_INFO(void) __ptr64 */

VIDPN_SOURCE_INFO * __thiscall VIDPN_SOURCE_INFO::VIDPN_SOURCE_INFO(VIDPN_SOURCE_INFO *this)

{
  *(undefined8 *)(this + 0x68) = 0;
  return this;
}



===== VIDPN_TARGET_INFO @ 1400027bc =====

/* public: __cdecl VIDPN_TARGET_INFO::VIDPN_TARGET_INFO(void) __ptr64 */

VIDPN_TARGET_INFO * __thiscall VIDPN_TARGET_INFO::VIDPN_TARGET_INFO(VIDPN_TARGET_INFO *this)

{
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 200) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  return this;
}



===== ~AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_> @ 1400027e0 =====

/* public: __cdecl AUTO_PTR_DETAILS::AutoPtrImpl<struct VIDPN_SOURCE_INFO,struct
   AUTO_PTR_DETAILS::AutoDeleter<struct VIDPN_SOURCE_INFO [0]> >::~AutoPtrImpl<struct
   VIDPN_SOURCE_INFO,struct AUTO_PTR_DETAILS::AutoDeleter<struct VIDPN_SOURCE_INFO [0]> >(void)
   __ptr64 */

void __thiscall
AUTO_PTR_DETAILS::
AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_>::
~AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_>
          (AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_>
           *this)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  VIDPN_SOURCE_INFO *this_00;
  
  lVar2 = *(longlong *)this;
  if (lVar2 != 0) {
    plVar1 = (longlong *)(lVar2 + -8);
    lVar3 = *plVar1;
    this_00 = (VIDPN_SOURCE_INFO *)(lVar3 * 0xf0 + lVar2);
    for (; lVar3 != 0; lVar3 = lVar3 + -1) {
      this_00 = this_00 + -0xf0;
      VIDPN_SOURCE_INFO::~VIDPN_SOURCE_INFO(this_00);
    }
    if (plVar1 != (longlong *)0x0) {
      ExFreePoolWithTag(plVar1,0);
    }
  }
  *(undefined8 *)this = 0;
  return;
}



===== ~AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_> @ 140002864 =====

/* public: __cdecl AUTO_PTR_DETAILS::AutoPtrImpl<struct VIDPN_TARGET_INFO,struct
   AUTO_PTR_DETAILS::AutoDeleter<struct VIDPN_TARGET_INFO [0]> >::~AutoPtrImpl<struct
   VIDPN_TARGET_INFO,struct AUTO_PTR_DETAILS::AutoDeleter<struct VIDPN_TARGET_INFO [0]> >(void)
   __ptr64 */

void __thiscall
AUTO_PTR_DETAILS::
AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_>::
~AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_>
          (AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_>
           *this)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  VIDPN_TARGET_INFO *this_00;
  
  lVar2 = *(longlong *)this;
  if (lVar2 != 0) {
    plVar1 = (longlong *)(lVar2 + -8);
    lVar3 = *plVar1;
    this_00 = (VIDPN_TARGET_INFO *)(lVar3 * 0x130 + lVar2);
    for (; lVar3 != 0; lVar3 = lVar3 + -1) {
      this_00 = this_00 + -0x130;
      VIDPN_TARGET_INFO::~VIDPN_TARGET_INFO(this_00);
    }
    if (plVar1 != (longlong *)0x0) {
      ExFreePoolWithTag(plVar1,0);
    }
  }
  *(undefined8 *)this = 0;
  return;
}



===== ~VIDPN_SOURCE_INFO @ 1400028e8 =====

/* public: __cdecl VIDPN_SOURCE_INFO::~VIDPN_SOURCE_INFO(void) __ptr64 */

void __thiscall VIDPN_SOURCE_INFO::~VIDPN_SOURCE_INFO(VIDPN_SOURCE_INFO *this)

{
  if (*(longlong *)(this + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x68),0);
  }
  *(undefined8 *)(this + 0x68) = 0;
  return;
}



===== ~VIDPN_TARGET_INFO @ 14000291c =====

/* public: __cdecl VIDPN_TARGET_INFO::~VIDPN_TARGET_INFO(void) __ptr64 */

void __thiscall VIDPN_TARGET_INFO::~VIDPN_TARGET_INFO(VIDPN_TARGET_INFO *this)

{
  if (*(longlong *)(this + 0xd8) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0xd8),0);
  }
  *(undefined8 *)(this + 0xd8) = 0;
  if (*(longlong *)(this + 200) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 200),0);
  }
  *(undefined8 *)(this + 200) = 0;
  if (*(longlong *)(this + 0xb0) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0xb0),0);
  }
  *(undefined8 *)(this + 0xb0) = 0;
  return;
}



===== KmdDodCopyFromUserMode @ 140002998 =====

/* long __cdecl KmdDodCopyFromUserMode(void * __ptr64,unsigned long,void * __ptr64) */

long __cdecl KmdDodCopyFromUserMode(void *param_1,ulong param_2,void *param_3)

{
  memmove(param_1,param_3,(ulonglong)param_2);
  return 0;
}



===== KmdDodCopyToUserMode @ 1400029e0 =====

/* long __cdecl KmdDodCopyToUserMode(void * __ptr64,unsigned long,void * __ptr64) */

long __cdecl KmdDodCopyToUserMode(void *param_1,ulong param_2,void *param_3)

{
  ProbeForWrite(param_3,param_2,1);
  memmove(param_3,param_1,(ulonglong)param_2);
  return 0;
}



===== KmdDodDdiResetDevice @ 140002a40 =====

/* void __cdecl KmdDodDdiResetDevice(void * __ptr64) */

void __cdecl KmdDodDdiResetDevice(void *param_1)

{
  return;
}



===== KmdDodDdiSystemDisplayEnable @ 140002a50 =====

/* long __cdecl KmdDodDdiSystemDisplayEnable(void * __ptr64,unsigned int,struct
   _DXGKARG_SYSTEM_DISPLAY_ENABLE_FLAGS * __ptr64,unsigned int * __ptr64,unsigned int * __ptr64,enum
   _D3DDDIFORMAT * __ptr64) */

long __cdecl
KmdDodDdiSystemDisplayEnable
          (void *param_1,uint param_2,_DXGKARG_SYSTEM_DISPLAY_ENABLE_FLAGS *param_3,uint *param_4,
          uint *param_5,_D3DDDIFORMAT *param_6)

{
  return -0x3fffff45;
}



===== KmdDodDdiSystemDisplayWrite @ 140002a60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl KmdDodDdiSystemDisplayWrite(void * __ptr64,void * __ptr64,unsigned int,unsigned
   int,unsigned int,unsigned int,unsigned int) */

void __cdecl
KmdDodDdiSystemDisplayWrite
          (void *param_1,void *param_2,uint param_3,uint param_4,uint param_5,uint param_6,
          uint param_7)

{
  WdLogSingleEntry1(1,0x54f);
  _WdLogGlobalForLineNumber = 0x54f;
  return;
}



===== KmdDodInterruptRoutine @ 140002a90 =====

/* unsigned char __cdecl KmdDodInterruptRoutine(void * __ptr64,unsigned long) */

uchar __cdecl KmdDodInterruptRoutine(void *param_1,ulong param_2)

{
  return '\0';
}



===== Feature_IdAtomicI2C__private_IsEnabledDeviceUsageNoInline @ 140002a9c =====

ulonglong Feature_IdAtomicI2C__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_IdAtomicI2C__private_featureState;
  if ((Feature_IdAtomicI2C__private_featureState & 0x10) == 0) {
    uVar1 = Feature_IdAtomicI2C__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_IdAtomicI2C__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_IdAtomicI2C__private_IsEnabledFallback @ 140002ad4 =====

void Feature_IdAtomicI2C__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_IdAtomicI2C__private_descriptor);
  return;
}



===== McGenControlCallbackV2 @ 140002af0 =====

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



===== McGenEventRegister_EtwRegister @ 140002c00 =====

void McGenEventRegister_EtwRegister(void)

{
  if (IddCxEtwProvider_Context == 0) {
    EtwRegister(&IddCxEtwProvider,McGenControlCallbackV2,&IddCxEtwProvider_Context,
                &IddCxEtwProvider_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140002c40 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (IddCxEtwProvider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    IddCxEtwProvider_Context = 0;
  }
  return uVar1;
}



===== wil_details_RecordCachedUsage @ 140002c74 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140002dc0 =====

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



===== OnSourcePowerOff @ 140002e44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* private: void __cdecl INDIRECT_DEVICE::OnSourcePowerOff(struct VIDPN_SOURCE_INFO & __ptr64)
   __ptr64 */

void __thiscall INDIRECT_DEVICE::OnSourcePowerOff(INDIRECT_DEVICE *this,VIDPN_SOURCE_INFO *param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x40) != 0) &&
     (*(int *)(param_1 + 0x3c) != 0 || *(int *)(param_1 + 0x38) != 0)) {
    iVar1 = (**(code **)(this + 0x2a8))
                      (*(undefined8 *)(this + 0x280),0,*(undefined8 *)(param_1 + 0x38));
    if (iVar1 < 0) {
      WdLogSingleEntry1(2,(longlong)iVar1);
      _WdLogGlobalForLineNumber = 0x4ad;
    }
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  return;
}



===== OnSourcePowerOn @ 140002ea8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* private: void __cdecl INDIRECT_DEVICE::OnSourcePowerOn(struct VIDPN_SOURCE_INFO & __ptr64)
   __ptr64 */

void __thiscall INDIRECT_DEVICE::OnSourcePowerOn(INDIRECT_DEVICE *this,VIDPN_SOURCE_INFO *param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x40) == 0) &&
     (*(int *)(param_1 + 0x3c) != 0 || *(int *)(param_1 + 0x38) != 0)) {
    iVar1 = (**(code **)(this + 0x2a8))
                      (*(undefined8 *)(this + 0x280),1,*(undefined8 *)(param_1 + 0x38));
    if (iVar1 < 0) {
      WdLogSingleEntry1(2,(longlong)iVar1);
      _WdLogGlobalForLineNumber = 0x49c;
    }
    *(undefined4 *)(param_1 + 0x40) = 1;
  }
  return;
}



===== QueueConnectionChangedEvent @ 140002f14 =====

/* private: long __cdecl INDIRECT_DEVICE::QueueConnectionChangedEvent(unsigned int,struct
   VIDPN_TARGET_INFO & __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::QueueConnectionChangedEvent
          (INDIRECT_DEVICE *this,uint param_1,VIDPN_TARGET_INFO *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  long lVar4;
  longlong *plVar5;
  INDIRECT_DEVICE *pIVar6;
  longlong *plVar7;
  uint uVar8;
  
  plVar5 = (longlong *)ExAllocateFromPagedLookasideList(this + 0x400);
  if (plVar5 == (longlong *)0x0) {
    lVar4 = -0x3fffffe9;
  }
  else {
    lVar2 = *(longlong *)(param_2 + 0x118);
    *(longlong *)(param_2 + 0x118) = lVar2 + 1;
    plVar5[2] = lVar2;
    uVar8 = (*(uint *)(plVar5 + 3) ^ param_1) & 0xffffff ^ *(uint *)(plVar5 + 3);
    *(uint *)(plVar5 + 3) = uVar8;
    *(uint *)(plVar5 + 3) =
         ((-(uint)(*(int *)(param_2 + 0x90) != 0) & 2) + 8) * 0x1000000 | uVar8 & 0xf0ffffff;
    uVar1 = *(undefined4 *)(param_2 + 0x94);
    *(undefined4 *)(plVar5 + 4) = 0;
    *(undefined4 *)((longlong)plVar5 + 0x1c) = uVar1;
    pIVar6 = this + 0x480;
    plVar7 = *(longlong **)(this + 0x488);
    if ((INDIRECT_DEVICE *)*plVar7 != pIVar6) {
      plVar7 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      pIVar6 = (INDIRECT_DEVICE *)(*pcVar3)();
    }
    *plVar5 = (longlong)pIVar6;
    plVar5[1] = (longlong)plVar7;
    *plVar7 = (longlong)plVar5;
    *(longlong **)(pIVar6 + 8) = plVar5;
    lVar4 = 0;
  }
  return lVar4;
}



===== Feature_IdAcceptDisplayIdOnly__private_IsEnabledDeviceUsageNoInline @ 140002fe4 =====

ulonglong Feature_IdAcceptDisplayIdOnly__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_IdAcceptDisplayIdOnly__private_featureState;
  if ((Feature_IdAcceptDisplayIdOnly__private_featureState & 0x10) == 0) {
    uVar1 = Feature_IdAcceptDisplayIdOnly__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_IdAcceptDisplayIdOnly__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_IdAcceptDisplayIdOnly__private_IsEnabledFallback @ 14000301c =====

void Feature_IdAcceptDisplayIdOnly__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_IdAcceptDisplayIdOnly__private_descriptor);
  return;
}



===== HandleRequestQueryMouseCursor @ 140003038 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::HandleRequestQueryMouseCursor(struct
   IDD_USER_QUERY_MOUSE_CURSOR_IN const * __ptr64,struct IDD_USER_QUERY_MOUSE_CURSOR_OUT * __ptr64)
   __ptr64 */

long __thiscall
INDIRECT_DEVICE::HandleRequestQueryMouseCursor
          (INDIRECT_DEVICE *this,IDD_USER_QUERY_MOUSE_CURSOR_IN *param_1,
          IDD_USER_QUERY_MOUSE_CURSOR_OUT *param_2)

{
  long lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  uint *puVar6;
  
  if (*(uint *)(this + 0x31c) <= *(uint *)(param_1 + 4)) {
    return -0x3ffffff3;
  }
  puVar6 = (uint *)((ulonglong)*(uint *)(param_1 + 4) * 0x130 + *(longlong *)(this + 0x2c8));
  if (*puVar6 == 0xffffffff) {
    return -0x3fe1fcd9;
  }
  lVar5 = (ulonglong)*puVar6 * 0xf0 + *(longlong *)(this + 0x2d0);
  lVar2 = WdLogNewEntry5_WdTrace();
  *(ulonglong *)(lVar2 + 0x18) = (ulonglong)*(uint *)(param_1 + 4);
  *(ulonglong *)(lVar2 + 0x20) = (ulonglong)*puVar6;
  *(ulonglong *)(lVar2 + 0x28) = (ulonglong)*(uint *)(param_1 + 0x14);
  *(ulonglong *)(lVar2 + 0x30) = (ulonglong)*(uint *)(lVar5 + 0x5c);
  *(undefined8 *)param_2 = 0;
  *(undefined8 *)(param_2 + 8) = 0;
  _WdLogGlobalForLineNumber = 0x103;
  *(undefined8 *)(param_2 + 0x10) = 0;
  *(undefined8 *)(param_2 + 0x18) = 0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  ExAcquireFastMutex(lVar5 + 0x80);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(lVar5 + 0xb8);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(lVar5 + 0xbc);
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(lVar5 + 0xc0);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(lVar5 + 0xc4);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(lVar5 + 0x60);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(lVar5 + 100);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(lVar5 + 0x5c);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(lVar5 + 0xd8);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(lVar5 + 0xdc);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(lVar5 + 0xec);
  *(undefined4 *)param_2 = *(undefined4 *)(lVar5 + 0xe4);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(lVar5 + 0xe8);
  *(uint *)(param_2 + 0x30) = puVar6[0x48];
  if (*(int *)(param_1 + 0x14) != *(int *)(lVar5 + 0x5c)) {
    uVar3 = *(int *)(lVar5 + 0xc4) * *(int *)(lVar5 + 0xc0);
    uVar4 = uVar3 * 2;
    if ((*(uint *)(lVar5 + 0xb8) & 1) == 0) {
      uVar4 = uVar3;
    }
    if (uVar4 != 0) {
      if (((*(void **)(lVar5 + 0x68) == (void *)0x0) || (*(void **)(param_1 + 8) == (void *)0x0)) ||
         (*(uint *)(param_1 + 0x10) < uVar4)) {
        lVar1 = -0x3fffffdd;
        goto LAB_1400031bd;
      }
      lVar1 = KmdDodCopyToUserMode(*(void **)(lVar5 + 0x68),uVar4,*(void **)(param_1 + 8));
      if (lVar1 < 0) goto LAB_1400031bd;
    }
  }
  lVar1 = 0;
LAB_1400031bd:
  ExReleaseFastMutex(lVar5 + 0x80);
  return lVar1;
}



===== HandleRequestSetupMouseCursor @ 1400031f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl INDIRECT_DEVICE::HandleRequestSetupMouseCursor(struct
   IDD_USER_SETUP_MOUSE_CURSOR const * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::HandleRequestSetupMouseCursor
          (INDIRECT_DEVICE *this,IDD_USER_SETUP_MOUSE_CURSOR *param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong local_res8;
  
  iVar1 = 0;
  if (*(uint *)(param_1 + 4) < *(uint *)(this + 0x31c)) {
    lVar2 = (ulonglong)*(uint *)(param_1 + 4) * 0xf0 + *(longlong *)(this + 0x2d0);
    lVar3 = 0;
    if (*(longlong *)(param_1 + 0x20) != 0) {
      local_res8 = 0;
      iVar1 = ObReferenceObjectByHandle
                        (*(longlong *)(param_1 + 0x20),0x100000,
                         *(undefined8 *)ExEventObjectType_exref,1,&local_res8,0);
      lVar3 = local_res8;
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    ExAcquireFastMutex(lVar2 + 0x80);
    if (*(longlong *)(lVar2 + 0x78) != 0) {
      ObfDereferenceObject();
    }
    *(longlong *)(lVar2 + 0x78) = lVar3;
    *(undefined4 *)(lVar2 + 0x44) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(lVar2 + 0x48) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(lVar2 + 0x4c) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(lVar2 + 0x50) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(lVar2 + 0x54) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(lVar2 + 0x58) = *(undefined4 *)(param_1 + 0x1c);
    if (lVar3 != 0) {
      KeSetEvent(lVar3,0,0);
    }
    if (*(code **)(this + 0x2b0) != (code *)0x0) {
      (**(code **)(this + 0x2b0))(*(undefined8 *)(this + 0x280),*(undefined4 *)(param_1 + 4));
    }
    ExReleaseFastMutex(lVar2 + 0x80);
  }
  else {
    iVar1 = -0x3ffffff3;
  }
  return iVar1;
}



===== SetPointerPosition @ 140003344 =====

/* public: long __cdecl INDIRECT_DEVICE::SetPointerPosition(struct _DXGKARG_SETPOINTERPOSITION const
   * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::SetPointerPosition(INDIRECT_DEVICE *this,_DXGKARG_SETPOINTERPOSITION *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  long lVar13;
  
  lVar13 = 0;
  if ((param_1 == (_DXGKARG_SETPOINTERPOSITION *)0x0) ||
     (*(uint *)(this + 0x31c) <= *(uint *)param_1)) {
    return -0x3ffffff3;
  }
  lVar4 = *(longlong *)(this + 0x2d0);
  lVar12 = (ulonglong)*(uint *)param_1 * 0xf0;
  ExAcquireFastMutex(lVar12 + lVar4 + 0x80);
  uVar3 = *(uint *)(param_1 + 0xc);
  if (*(int *)(lVar12 + 0x44 + lVar4) == 0) {
    if ((uVar3 & 1) != 0) {
      lVar13 = -0x3fffff45;
    }
  }
  else {
    uVar10 = *(uint *)(lVar12 + 0xec + lVar4) & 1;
    uVar11 = uVar3 & 1;
    if (((this[0x32e] == (INDIRECT_DEVICE)0x0) && (this[0x32b] != (INDIRECT_DEVICE)0x0)) &&
       ((uVar3 & 2) == 0)) {
      bVar8 = false;
      if (uVar10 == uVar11) goto LAB_140003459;
    }
    else {
      bVar8 = true;
    }
    uVar9 = *(undefined4 *)(param_1 + 4);
    uVar6 = *(undefined4 *)(param_1 + 8);
    uVar7 = *(undefined4 *)(param_1 + 0xc);
    puVar2 = (undefined4 *)(lVar12 + 0xe0 + lVar4);
    *puVar2 = *(undefined4 *)param_1;
    puVar2[1] = uVar9;
    puVar2[2] = uVar6;
    puVar2[3] = uVar7;
    if ((bVar8) || (uVar9 = 0, uVar10 == uVar11)) {
      uVar9 = 1;
    }
    *(undefined4 *)(lVar12 + 100 + lVar4) = uVar9;
    if (((this[0x32d] != (INDIRECT_DEVICE)0x0) && (this[0x32b] != (INDIRECT_DEVICE)0x0)) &&
       (((*(uint *)(param_1 + 0xc) & 2) == 0 && (uVar10 != uVar11)))) {
      *(undefined4 *)(lVar12 + 0xe4 + lVar4) = 0x1f400;
      *(undefined4 *)(lVar12 + 0xe8 + lVar4) = 0x1f400;
    }
    piVar1 = (int *)(lVar12 + 0x60 + lVar4);
    *piVar1 = *piVar1 + 1;
    lVar5 = *(longlong *)(lVar12 + 0x78 + lVar4);
    if (lVar5 != 0) {
      KeSetEvent(lVar5,0,0);
    }
  }
LAB_140003459:
  ExReleaseFastMutex(lVar12 + lVar4 + 0x80);
  return lVar13;
}



===== SetPointerShape @ 140003498 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::SetPointerShape(struct _DXGKARG_SETPOINTERSHAPE const *
   __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::SetPointerShape(INDIRECT_DEVICE *this,_DXGKARG_SETPOINTERSHAPE *param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  void *_Dst;
  uint uVar8;
  long lVar9;
  longlong lVar10;
  
  lVar9 = 0;
  if ((param_1 == (_DXGKARG_SETPOINTERSHAPE *)0x0) ||
     (*(uint *)(this + 0x31c) <= *(uint *)(param_1 + 0x10))) {
    return -0x3ffffff3;
  }
  lVar10 = (ulonglong)*(uint *)(param_1 + 0x10) * 0xf0 + *(longlong *)(this + 0x2d0);
  ExAcquireFastMutex(lVar10 + 0x80);
  if ((((*(int *)(lVar10 + 0x44) == 0) ||
       ((((uVar3 = *(uint *)param_1, (uVar3 & 2) == 0 || (*(int *)(lVar10 + 0x48) == 0)) &&
         (((uVar3 & 4) == 0 || (*(int *)(lVar10 + 0x4c) == 0)))) &&
        (((uVar3 & 1) == 0 || (*(int *)(lVar10 + 0x50) == 0)))))) ||
      (*(uint *)(lVar10 + 0x54) < *(uint *)(param_1 + 4))) ||
     (*(uint *)(lVar10 + 0x58) < *(uint *)(param_1 + 8))) {
    lVar9 = -0x3fffff45;
    goto LAB_14000364a;
  }
  uVar7 = *(uint *)(param_1 + 8) * *(int *)(param_1 + 0xc);
  plVar1 = (longlong *)(lVar10 + 0x68);
  _Dst = (void *)*plVar1;
  uVar8 = uVar7 * 2;
  if ((uVar3 & 1) == 0) {
    uVar8 = uVar7;
  }
  if (_Dst == (void *)0x0) {
LAB_140003571:
    *plVar1 = 0;
    *(undefined4 *)(lVar10 + 0x70) = 0;
    _Dst = (void *)ExAllocatePool2(0x100,uVar8,0x4b646449);
    if (*plVar1 != 0) {
      ExFreePoolWithTag(*plVar1,0);
    }
    *plVar1 = (longlong)_Dst;
    if (_Dst == (void *)0x0) {
      *(undefined4 *)(lVar10 + 0x70) = 0;
      WdLogSingleEntry1(6,uVar8);
      _WdLogGlobalForLineNumber = 0x9b;
      lVar9 = -0x3fffffe9;
      goto LAB_14000364a;
    }
    *(uint *)(lVar10 + 0x70) = uVar8;
  }
  else if (*(uint *)(lVar10 + 0x70) < uVar8) {
    ExFreePoolWithTag(_Dst,0);
    goto LAB_140003571;
  }
  memmove(_Dst,*(void **)(param_1 + 0x18),(ulonglong)uVar8);
  uVar2 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(lVar10 + 0xb8) = *(undefined8 *)param_1;
  *(undefined8 *)(lVar10 + 0xc0) = uVar2;
  uVar4 = *(undefined4 *)(param_1 + 0x14);
  uVar5 = *(undefined4 *)(param_1 + 0x18);
  uVar6 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(lVar10 + 200) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(lVar10 + 0xcc) = uVar4;
  *(undefined4 *)(lVar10 + 0xd0) = uVar5;
  *(undefined4 *)(lVar10 + 0xd4) = uVar6;
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  *(int *)(lVar10 + 0x5c) = *(int *)(lVar10 + 0x5c) + 1;
  *(undefined8 *)(lVar10 + 0xd8) = uVar2;
  *(undefined8 *)(lVar10 + 0xd0) = *(undefined8 *)(lVar10 + 0x68);
  if (*(longlong *)(lVar10 + 0x78) != 0) {
    KeSetEvent(*(longlong *)(lVar10 + 0x78),0,0);
  }
LAB_14000364a:
  ExReleaseFastMutex(lVar10 + 0x80);
  return lVar9;
}



===== Feature_3030546745__private_IsEnabledDeviceUsageNoInline @ 140003688 =====

ulonglong Feature_3030546745__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3030546745__private_featureState;
  if ((Feature_3030546745__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3030546745__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3030546745__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3030546745__private_IsEnabledFallback @ 1400036c0 =====

void Feature_3030546745__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3030546745__private_descriptor);
  return;
}



===== DlpGetServiceNameInSystemSpace @ 1400036dc =====

undefined8 * DlpGetServiceNameInSystemSpace(void)

{
  wchar_t *_Dst;
  
  _Dst = (wchar_t *)ExAllocatePoolWithTag(0x401,0x78,0x706d6c44);
  if (ExPoolZeroingNativelySupported == '\0') {
    if (_Dst == (wchar_t *)0x0) {
      return (undefined8 *)0x0;
    }
    memset(_Dst,0,0x78);
  }
  else if (_Dst == (wchar_t *)0x0) {
    return (undefined8 *)0x0;
  }
  builtin_wcsncpy(_Dst,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\DXGKrnl",0x3c);
  return (undefined8 *)_Dst;
}



===== DlpLoadDxgkrnl @ 140003790 =====

int DlpLoadDxgkrnl(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 local_res18 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar4 = 10;
  puVar3 = DlpGetServiceNameInSystemSpace();
  if (puVar3 == (undefined8 *)0x0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    RtlInitUnicodeString(&local_48,puVar3);
    iVar1 = ZwLoadDriver(&local_48);
    ExFreePoolWithTag(puVar3,0);
    if (((iVar1 + 0x80000000U & 0x80000000) != 0) || (iVar2 = iVar1, iVar1 == -0x3ffffef2)) {
      RtlInitUnicodeString(&local_38,L"\\Device\\DxgKrnl");
      do {
        iVar2 = IoGetDeviceObjectPointer(&local_38,0xc0000000,param_1,param_2);
        if ((-1 < iVar2) || (iVar1 != -0x3ffffef2)) break;
        local_res18[0] = 0xffffffffffff3cb0;
        KeDelayExecutionThread(0,0,local_res18);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (iVar2 < 0) {
        if (iVar1 != -0x3ffffef2) {
          DlpUnloadDxgkrnl();
        }
      }
      else if (iVar1 == -0x3ffffef2) {
        iVar2 = -0x3ffffef2;
      }
    }
  }
  return iVar2;
}



===== DlpUnloadDxgkrnl @ 1400038d0 =====

void DlpUnloadDxgkrnl(void)

{
  undefined8 *puVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  puVar1 = DlpGetServiceNameInSystemSpace();
  if (puVar1 != (undefined8 *)0x0) {
    RtlInitUnicodeString(&local_18,puVar1);
    ZwUnloadDriver(&local_18);
    ExFreePoolWithTag(puVar1,0);
  }
  return;
}



===== DxgkInitializeDisplayOnlyDriver @ 140003930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DxgkInitializeDisplayOnlyDriver(longlong param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  bool bVar4;
  undefined8 local_res8;
  longlong local_res20;
  
  local_res20 = 0;
  bVar4 = false;
  local_res8 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == (uint *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    uVar1 = *param_3;
    if (((((uVar1 - 0x1052 < 2) || (uVar1 == 0x2005)) ||
         ((uVar1 == 0x300e || ((uVar1 - 0x4002 < 2 || (uVar1 == 0x5023)))))) ||
        ((uVar1 == 0x6003 ||
         ((((((uVar1 - 0x6010 < 2 || (uVar1 == 0x700a)) || (uVar1 == 0x8001)) ||
            ((uVar1 == 0x9006 || (uVar1 == 0xa00b)))) ||
           ((uVar1 == 0xb004 || ((uVar1 == 0xc004 || (uVar1 == 0xd001)))))) || (uVar1 == 0xe003)))))
        ) || (((uVar1 == 0xf003 || (uVar1 == 0x10004)) || (0x11006 < uVar1)))) {
      iVar2 = DlpLoadDxgkrnl(&local_res20,&local_res8);
      if (((iVar2 + 0x80000000U & 0x80000000) != 0) || (iVar2 == -0x3ffffef2)) {
        bVar4 = iVar2 != -0x3ffffef2;
        uVar3 = DlpCallSyncDeviceIoControl(local_res8);
        iVar2 = (int)uVar3;
      }
      if (local_res20 != 0) {
        ObfDereferenceObject();
      }
      if (iVar2 < 0) {
        if (bVar4) {
          DlpUnloadDxgkrnl();
        }
      }
      else {
        MiniportStartDevice = *(undefined8 *)(param_3 + 4);
        *(code **)(param_3 + 4) = DlpStartDevice;
        iVar2 = (*(code *)0x0)(param_1,param_2,param_3);
      }
    }
    else {
      iVar2 = -0x3fffffa7;
    }
  }
  return iVar2;
}



===== __security_check_cookie @ 140003b10 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140003b50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140003b80 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140003b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140003bb0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 140003c00 =====

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



===== __memset_repmovs @ 140003d40 =====

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



===== __memset_query @ 140003dc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003e40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140003f80 =====

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



===== __memset_spec_plain @ 140004000 =====

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



===== memmove @ 140004140 =====

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



===== operator++ @ 14000b008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class TopologyIterator & __ptr64 __cdecl TopologyIterator::operator++(void) __ptr64 */

TopologyIterator * __thiscall TopologyIterator::operator++(TopologyIterator *this)

{
  longlong lVar1;
  long lVar2;
  int iVar3;
  
  if (-1 < *(int *)this) {
    lVar2 = ReleaseModes(this,true,true);
    if (-1 < lVar2) {
      *(undefined8 *)(this + 0x30) = *(undefined8 *)(this + 0x28);
      iVar3 = (**(code **)(*(longlong *)(*(longlong *)(this + 0x48) + 0x18) + 0x30))
                        (*(undefined8 *)(*(longlong *)(this + 0x48) + 8));
      lVar1 = *(longlong *)(this + 0x48);
      *(int *)this = iVar3;
      if (iVar3 < 0) {
        WdLogSingleEntry3(2,(longlong)iVar3,*(undefined8 *)(lVar1 + 8),*(undefined8 *)(this + 0x30))
        ;
        _WdLogGlobalForLineNumber = 0xf9;
      }
      else {
        iVar3 = (**(code **)(*(longlong *)(lVar1 + 0x18) + 0x40))
                          (*(undefined8 *)(lVar1 + 8),*(undefined8 *)(this + 0x30));
        if (iVar3 < 0) {
          WdLogSingleEntry1(1,0xfe);
          _WdLogGlobalForLineNumber = 0xfe;
        }
        *(undefined8 *)(this + 0x30) = 0;
        if (*(int *)this == 0x401e034c) {
          *(undefined4 *)this = 0;
        }
      }
    }
  }
  return this;
}



===== AddSingleSourceMode @ 14000b0d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::AddSingleSourceMode(struct
   _DXGK_VIDPNSOURCEMODESET_INTERFACE const * __ptr64,struct D3DKMDT_HVIDPNSOURCEMODESET__ *
   __ptr64,unsigned int,struct TARGET_MONITOR_MODE const & __ptr64,unsigned int,int) __ptr64 */

long __thiscall
INDIRECT_DEVICE::AddSingleSourceMode
          (INDIRECT_DEVICE *this,_DXGK_VIDPNSOURCEMODESET_INTERFACE *param_1,
          D3DKMDT_HVIDPNSOURCEMODESET__ *param_2,uint param_3,TARGET_MONITOR_MODE *param_4,
          uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  undefined4 in_register_0000008c;
  uint *local_res8;
  
  local_res8 = (uint *)0x0;
  iVar1 = (**(code **)(param_1 + 0x28))
                    (param_2,&local_res8,param_2,CONCAT44(in_register_0000008c,param_3));
  if (iVar1 < 0) {
    WdLogSingleEntry2(2,(longlong)iVar1,param_2);
    _WdLogGlobalForLineNumber = 0x49d;
  }
  else {
    *local_res8 = param_5;
    local_res8[1] = 1;
    local_res8[2] = *(uint *)(param_4 + 0xc);
    local_res8[3] = *(uint *)(param_4 + 0x10);
    *(undefined8 *)(local_res8 + 4) = *(undefined8 *)(local_res8 + 2);
    local_res8[6] = ((-(uint)(param_6 != 0) & 4) + 4) * *(int *)(param_4 + 0xc);
    local_res8[7] = (-(uint)(param_6 != 0) & 0x5c) + 0x15;
    local_res8[8] = 3;
    local_res8[9] = 1;
    iVar1 = (**(code **)(param_1 + 0x30))(param_2,local_res8);
    if (iVar1 < 0) {
      iVar2 = (**(code **)(param_1 + 0x20))(param_2,local_res8);
      if (iVar2 < 0) {
        WdLogSingleEntry1(1,0x4b2);
        _WdLogGlobalForLineNumber = 0x4b2;
      }
      if (iVar1 != -0x3fe1fcec) {
        WdLogSingleEntry3(2,(longlong)iVar1,param_2,local_res8);
        _WdLogGlobalForLineNumber = 0x4b6;
        goto LAB_14000b236;
      }
    }
    iVar1 = 0;
  }
LAB_14000b236:
  return iVar1;
}



===== AddSingleTargetMode @ 14000b254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::AddSingleTargetMode(struct
   _DXGK_VIDPNTARGETMODESET_INTERFACE const * __ptr64,struct D3DKMDT_HVIDPNTARGETMODESET__ *
   __ptr64,struct TARGET_MONITOR_MODE const & __ptr64,unsigned int) __ptr64 */

long __thiscall
INDIRECT_DEVICE::AddSingleTargetMode
          (INDIRECT_DEVICE *this,_DXGK_VIDPNTARGETMODESET_INTERFACE *param_1,
          D3DKMDT_HVIDPNTARGETMODESET__ *param_2,TARGET_MONITOR_MODE *param_3,uint param_4)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  uint *local_res8;
  undefined4 local_res10;
  undefined4 uStackX_14;
  
  local_res8 = (uint *)0x0;
  iVar2 = (**(code **)(param_1 + 0x28))(param_2,&local_res8);
  if (iVar2 < 0) {
    WdLogSingleEntry2(2,(longlong)iVar2,param_2);
    _WdLogGlobalForLineNumber = 0x4cb;
  }
  else {
    *local_res8 = param_4;
    local_res8[2] = 0xff;
    *(undefined8 *)(local_res8 + 3) = *(undefined8 *)(param_3 + 4);
    *(undefined8 *)(local_res8 + 5) = *(undefined8 *)(param_3 + 0xc);
    *(undefined8 *)(local_res8 + 7) = *(undefined8 *)(param_3 + 0x14);
    uVar1 = *(undefined8 *)(param_3 + 0x1c);
    local_res10 = (undefined4)uVar1;
    uStackX_14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    *(undefined8 *)(local_res8 + 9) = uVar1;
    *(undefined8 *)(local_res8 + 0xc) = *(undefined8 *)(param_3 + 0x28);
    local_res8[0xe] = 1;
    local_res8[0xe] = (*(int *)(param_3 + 0x30) << 3 ^ local_res8[0xe]) & 0x1f8 ^ local_res8[0xe];
    local_res8[0x10] = *(uint *)(param_3 + 0x40);
    iVar2 = (**(code **)(param_1 + 0x30))(param_2,local_res8);
    if (-1 < iVar2) {
      return 0;
    }
    if (iVar2 == -0x3fe1fcec) {
      iVar2 = 0;
    }
    else {
      WdLogSingleEntry3(2,(longlong)iVar2,param_2,local_res8);
      _WdLogGlobalForLineNumber = 0x4e4;
    }
    iVar3 = (**(code **)(param_1 + 0x20))(param_2,local_res8);
    if (iVar3 < 0) {
      WdLogSingleEntry1(1,0x4ed);
      _WdLogGlobalForLineNumber = 0x4ed;
    }
  }
  return iVar2;
}



===== ComputeVidPnBandwidth @ 14000b414 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::ComputeVidPnBandwidth(class TopologyHelper &
   __ptr64,unsigned __int64 * __ptr64,unsigned __int64 * __ptr64,unsigned __int64 * __ptr64) __ptr64
    */

long __thiscall
INDIRECT_DEVICE::ComputeVidPnBandwidth
          (INDIRECT_DEVICE *this,TopologyHelper *param_1,__uint64 *param_2,__uint64 *param_3,
          __uint64 *param_4)

{
  uint uVar1;
  long lVar2;
  longlong lVar3;
  longlong lVar4;
  __uint64 *p_Var5;
  int local_58 [10];
  longlong local_30;
  uint *local_20;
  uint *local_18;
  
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  p_Var5 = param_2;
  TopologyIterator::TopologyIterator((TopologyIterator *)local_58,param_1);
  lVar2 = 0;
  do {
    if ((local_58[0] < 0) || (local_30 == 0)) {
      TopologyIterator::~TopologyIterator((TopologyIterator *)local_58);
      return lVar2;
    }
    lVar4 = (ulonglong)(*(int *)(local_30 + 4) - 0x100) * 0x130 + *(longlong *)(this + 0x2c8);
    lVar2 = TopologyIterator::AcquireModes
                      ((TopologyIterator *)local_58,SUB81(param_1,0),SUB81(p_Var5,0));
    if (-1 < lVar2) {
      p_Var5 = (__uint64 *)(lVar4 + 0xe0);
      lVar3 = 0;
      if (local_20 == (uint *)0x0) {
        *param_3 = *param_3 + *(longlong *)(lVar4 + 0xe8);
      }
      else {
        uVar1 = *local_20;
        if (*(uint *)p_Var5 <= uVar1) {
          param_1 = (TopologyHelper *)(ulonglong)uVar1;
          WdLogSingleEntry1(2);
          _WdLogGlobalForLineNumber = 0x518;
          goto LAB_14000b538;
        }
        lVar3 = *(longlong *)(*(longlong *)(lVar4 + 0xd8) + 0x38 + (ulonglong)uVar1 * 0x48);
      }
      if (local_18 == (uint *)0x0) {
        *param_4 = *param_4 + *(longlong *)(lVar4 + 0xe8);
      }
      else {
        uVar1 = *local_18;
        if (*(uint *)p_Var5 <= uVar1) {
          param_1 = (TopologyHelper *)(ulonglong)uVar1;
          WdLogSingleEntry1(2);
          _WdLogGlobalForLineNumber = 0x52b;
          goto LAB_14000b538;
        }
        lVar3 = *(longlong *)(*(longlong *)(lVar4 + 0xd8) + 0x38 + (ulonglong)uVar1 * 0x48);
      }
      *param_2 = *param_2 + lVar3;
    }
LAB_14000b538:
    TopologyIterator::operator++((TopologyIterator *)local_58);
    lVar2 = local_58[0];
  } while( true );
}



===== DisplayDetectControl @ 14000b57c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl INDIRECT_DEVICE::DisplayDetectControl(struct _DXGKARG_DISPLAYDETECTCONTROL
   const * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::DisplayDetectControl(INDIRECT_DEVICE *this,_DXGKARG_DISPLAYDETECTCONTROL *param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  uVar3 = *(uint *)param_1;
  lVar2 = 0;
  uVar1 = uVar3 >> 0x18 & 0xf;
  if (uVar1 == 1) {
    if (this[0x3d0] != (INDIRECT_DEVICE)0x0) {
      lVar2 = QueueConnectionChangedEvent
                        (this,(uVar3 & 0xffffff) + 0x100,
                         (VIDPN_TARGET_INFO *)
                         (((ulonglong)uVar3 & 0xffffff) * 0x130 + *(longlong *)(this + 0x2c8)));
      if (lVar2 < 0) goto LAB_14000b68e;
      goto LAB_14000b67c;
    }
  }
  else if (uVar1 == 2) {
    if (this[0x3d0] != (INDIRECT_DEVICE)0x0) {
      uVar4 = 0;
      if (*(int *)(this + 0x31c) != 0) {
        do {
          lVar2 = QueueConnectionChangedEvent
                            (this,(int)uVar4 + 0x100,
                             (VIDPN_TARGET_INFO *)(uVar4 * 0x130 + *(longlong *)(this + 0x2c8)));
          if (lVar2 < 0) goto LAB_14000b68e;
          uVar3 = (int)uVar4 + 1;
          uVar4 = (ulonglong)uVar3;
        } while (uVar3 < *(uint *)(this + 0x31c));
      }
      goto LAB_14000b67c;
    }
  }
  else {
    if (uVar1 == 3) {
      this[0x3d0] = (INDIRECT_DEVICE)0x1;
      if (*(INDIRECT_DEVICE **)(this + 0x480) == this + 0x480) goto LAB_14000b68e;
LAB_14000b67c:
      lVar2 = (**(code **)(this + 0x188))(*(undefined8 *)(this + 0x40));
      goto LAB_14000b68e;
    }
    if (uVar1 == 4) {
      this[0x3d0] = (INDIRECT_DEVICE)0x0;
      goto LAB_14000b68e;
    }
  }
  lVar2 = -0x3ffffff3;
LAB_14000b68e:
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar2;
}



===== EnumVidPnCofuncModality @ 14000b6bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::EnumVidPnCofuncModality(struct
   _DXGKARG_ENUMVIDPNCOFUNCMODALITY const * __ptr64 const) __ptr64 */

long __thiscall
INDIRECT_DEVICE::EnumVidPnCofuncModality
          (INDIRECT_DEVICE *this,_DXGKARG_ENUMVIDPNCOFUNCMODALITY *param_1)

{
  TARGET_MONITOR_MODE *pTVar1;
  uint uVar2;
  undefined8 uVar3;
  uint *puVar4;
  uint uVar5;
  long lVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  INDIRECT_DEVICE *this_00;
  uint *puVar10;
  uint *puVar11;
  TopologyHelper *pTVar12;
  INDIRECT_DEVICE *pIVar13;
  ulonglong uVar14;
  longlong lVar15;
  __uint64 *p_Var16;
  _DXGK_VIDPNSOURCEMODESET_INTERFACE **pp_Var17;
  int iVar18;
  uint uVar19;
  undefined4 uVar20;
  ulonglong uVar21;
  bool bVar22;
  bool bVar23;
  undefined1 auStackY_2c8 [32];
  uint local_278 [2];
  D3DKMDT_HVIDPNSOURCEMODESET__ *local_270;
  D3DKMDT_HVIDPNTARGETMODESET__ *local_268;
  _DXGK_VIDPNSOURCEMODESET_INTERFACE *local_260;
  _DXGK_VIDPNTARGETMODESET_INTERFACE *local_258;
  uint *local_250;
  uint *local_240;
  longlong local_238;
  undefined8 *local_230;
  ulonglong local_228;
  _DXGKARG_ENUMVIDPNCOFUNCMODALITY *local_220;
  __uint64 local_218;
  __uint64 local_210;
  __uint64 local_208;
  __uint64 local_200;
  __uint64 local_1f8;
  ulonglong local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  longlong local_1d0;
  INDIRECT_DEVICE *local_1c8;
  INDIRECT_DEVICE *local_1c0;
  longlong local_1b8;
  uint local_1a8;
  int iStack_1a4;
  undefined8 uStack_1a0;
  undefined4 local_198;
  int iStack_194;
  undefined4 uStack_190;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2c8;
  if (param_1 == (_DXGKARG_ENUMVIDPNCOFUNCMODALITY *)0x0) {
    return -0x3ffffff3;
  }
  pIVar13 = this + 0x350;
  local_220 = param_1;
  local_1c8 = pIVar13;
  local_1c0 = this;
  ExEnterCriticalRegionAndAcquireResourceShared(pIVar13);
  lVar7 = WdLogNewEntry5_WdTrace();
  *(undefined8 *)(lVar7 + 0x18) = 0xd0;
  local_1e8 = *(undefined8 *)param_1;
  local_1d0 = 0;
  _WdLogGlobalForLineNumber = 0xd0;
  local_1e0 = 0;
  uStack_1d8 = 0;
  uVar5 = TopologyHelper::Init((TopologyHelper *)&local_1e8,(_DXGKRNL_INTERFACE *)(this + 0x38));
  if ((int)uVar5 < 0) {
    WdLogSingleEntry1(2,(longlong)(int)uVar5);
    _WdLogGlobalForLineNumber = 0xd6;
  }
  else {
    local_1f8 = 0;
    local_210 = 0;
    local_200 = 0;
    p_Var16 = &local_1f8;
    uVar5 = ComputeVidPnBandwidth(this,(TopologyHelper *)&local_1e8,p_Var16,&local_210,&local_200);
    uVar14 = (ulonglong)(int)uVar5;
    if ((int)uVar5 < 0) {
      WdLogSingleEntry1(2,uVar14);
      _WdLogGlobalForLineNumber = 0xe1;
    }
    else {
      uVar8 = *(ulonglong *)(this + 800);
      if (local_1f8 <= uVar8) {
        lVar7 = uVar8 - local_1f8;
        pTVar12 = (TopologyHelper *)&local_1e8;
        local_1b8 = lVar7;
        TopologyIterator::TopologyIterator((TopologyIterator *)local_278,pTVar12);
        local_218 = local_210;
        local_208 = local_200;
        do {
          if (((int)local_278[0] < 0) || (local_250 == (uint *)0x0)) {
            bVar22 = false;
          }
          else {
            bVar22 = true;
          }
          uVar5 = (uint)uVar14;
          if (!bVar22) goto LAB_14000bf95;
          lVar15 = (ulonglong)(local_250[1] - 0x100) * 0x130 + *(longlong *)(this + 0x2c8);
          if (*(int *)(lVar15 + 0x90) == 0) {
            TopologyIterator::~TopologyIterator((TopologyIterator *)local_278);
            goto LAB_14000b817;
          }
          lVar6 = TopologyIterator::AcquireModes
                            ((TopologyIterator *)local_278,SUB81(pTVar12,0),SUB81(p_Var16,0));
          if (lVar6 < 0) goto LAB_14000bfe1;
          bVar22 = local_240 == (uint *)0x0;
          bVar23 = local_238 == 0;
          uVar14 = 0;
          if ((bVar22) &&
             (uVar14 = (*(longlong *)(lVar15 + 0xe8) - local_218) + lVar7,
             *(ulonglong *)(this + 800) < uVar14)) {
            WdLogSingleEntry1(1);
            _WdLogGlobalForLineNumber = 0x109;
          }
          local_1f0 = 0;
          if ((bVar23) &&
             (local_1f0 = (*(longlong *)(lVar15 + 0xe8) - local_208) + lVar7,
             *(ulonglong *)(this + 800) < local_1f0)) {
            WdLogSingleEntry1(1);
            _WdLogGlobalForLineNumber = 0x111;
          }
          if (((*(int *)(param_1 + 8) != 1) || (*(uint *)(param_1 + 0xc) != *local_250)) &&
             (local_240 == (uint *)0x0)) {
            lVar6 = TopologyIterator::ReleaseModes((TopologyIterator *)local_278,true,false);
            if (lVar6 < 0) goto LAB_14000bfe1;
            pp_Var17 = &local_260;
            local_278[0] = (**(code **)(local_230[2] + 0x20))(*local_230,*local_250,&local_270);
            if ((int)local_278[0] < 0) {
              pp_Var17 = (_DXGK_VIDPNSOURCEMODESET_INTERFACE **)(ulonglong)*local_250;
              WdLogSingleEntry3(2,(longlong)(int)local_278[0],*local_230);
              _WdLogGlobalForLineNumber = 0xae;
              if (-1 < (int)local_278[0]) goto LAB_14000b9e0;
LAB_14000bb6a:
              uVar5 = local_278[0];
              TopologyIterator::~TopologyIterator((TopologyIterator *)local_278);
              goto LAB_14000bf9f;
            }
LAB_14000b9e0:
            uVar19 = 0;
            uVar8 = 0;
            local_228 = local_228 & 0xffffffff00000000;
            if (*(int *)(lVar15 + 0xe0) != 0) {
              do {
                this_00 = (INDIRECT_DEVICE *)(uVar8 * 9);
                pTVar1 = (TARGET_MONITOR_MODE *)(*(longlong *)(lVar15 + 0xd8) + uVar8 * 0x48);
                uVar5 = uVar19;
                if (pTVar1[1] != (TARGET_MONITOR_MODE)0x0) {
                  if (uVar14 < *(ulonglong *)(pTVar1 + 0x38)) {
                    lVar7 = WdLogNewEntry5_WdTrace();
                    *(ulonglong *)(lVar7 + 0x18) = (ulonglong)*(uint *)(pTVar1 + 0xc);
                    *(ulonglong *)(lVar7 + 0x20) = (ulonglong)*(uint *)(pTVar1 + 0x10);
                    *(ulonglong *)(lVar7 + 0x28) = (ulonglong)*(uint *)(pTVar1 + 0x14);
                    *(ulonglong *)(lVar7 + 0x30) = (ulonglong)*(uint *)(pTVar1 + 0x18);
                    *(ulonglong *)(lVar7 + 0x38) = (ulonglong)*(uint *)(pTVar1 + 0x30);
                    _WdLogGlobalForLineNumber = 0x147;
                    lVar7 = WdLogNewEntry5_WdTrace();
                    *(undefined8 *)(lVar7 + 0x18) = *(undefined8 *)(pTVar1 + 0x38);
                    _WdLogGlobalForLineNumber = 0x148;
                  }
                  else {
                    uVar5 = AddSingleSourceMode(this_00,local_260,local_270,(uint)pp_Var17,pTVar1,
                                                uVar19,0);
                    if ((int)uVar5 < 0) {
                      TopologyIterator::~TopologyIterator((TopologyIterator *)local_278);
                      goto LAB_14000bf9f;
                    }
                    if ((*(int *)(lVar15 + 0x128) != 0) ||
                       (uVar5 = uVar19 + 1, *(int *)(lVar15 + 0x124) != 0)) {
                      uVar5 = AddSingleSourceMode(this_00,local_260,local_270,(uint)pp_Var17,pTVar1,
                                                  uVar19 + 1,1);
                      if ((int)uVar5 < 0) {
                        TopologyIterator::~TopologyIterator((TopologyIterator *)local_278);
                        goto LAB_14000bf9f;
                      }
                      uVar5 = uVar19 + 2;
                    }
                  }
                }
                uVar19 = uVar5;
                uVar5 = (int)local_228 + 1;
                uVar8 = (ulonglong)uVar5;
                local_228 = CONCAT44(local_228._4_4_,uVar5);
              } while (uVar5 < *(uint *)(lVar15 + 0xe0));
              if (uVar19 != 0) {
                local_278[0] = (**(code **)(local_230[2] + 0x28))(*local_230,*local_250,local_270);
                if ((int)local_278[0] < 0) {
                  WdLogSingleEntry4(2,(longlong)(int)local_278[0],*local_230,*local_250);
                  _WdLogGlobalForLineNumber = 0xbe;
                  if ((int)local_278[0] < 0) goto LAB_14000bb6a;
                }
                else {
                  local_270 = (D3DKMDT_HVIDPNSOURCEMODESET__ *)0x0;
                }
                param_1 = local_220;
                goto LAB_14000bb86;
              }
            }
            uVar20 = 0x151;
            WdLogSingleEntry1(2,0x151);
LAB_14000bf8e:
            uVar5 = 0xc0000001;
            _WdLogGlobalForLineNumber = uVar20;
            goto LAB_14000bf95;
          }
LAB_14000bb86:
          if (((*(int *)(param_1 + 8) != 2) || (*(uint *)(param_1 + 0x10) != local_250[1])) &&
             (local_238 == 0)) {
            lVar6 = TopologyIterator::ReleaseModes((TopologyIterator *)local_278,false,true);
            if (-1 < lVar6) {
              local_278[0] = (**(code **)(local_230[2] + 0x48))
                                       (*local_230,local_250[1],&local_268,&local_258);
              if ((int)local_278[0] < 0) {
                WdLogSingleEntry3(2,(longlong)(int)local_278[0],*local_230,local_250[1]);
                _WdLogGlobalForLineNumber = 0xd0;
                if ((int)local_278[0] < 0) goto LAB_14000bb6a;
              }
              uVar14 = local_1f0;
              local_228 = 0;
              if ((local_240 != (uint *)0x0) && (*local_240 < *(uint *)(lVar15 + 0xe0))) {
                local_228 = *(ulonglong *)
                             (*(longlong *)(lVar15 + 0xd8) + 0x38 + (ulonglong)*local_240 * 0x48);
              }
              uVar8 = local_228;
              iVar18 = 0;
              uVar21 = 0;
              puVar11 = local_240;
              if (*(int *)(lVar15 + 0xe0) != 0) {
                do {
                  pTVar1 = (TARGET_MONITOR_MODE *)(*(longlong *)(lVar15 + 0xd8) + uVar21 * 0x48);
                  if ((pTVar1[1] != (TARGET_MONITOR_MODE)0x0) &&
                     ((puVar11 == (uint *)0x0 ||
                      ((puVar11[2] == *(uint *)(pTVar1 + 0xc) &&
                       (puVar11[3] == *(uint *)(pTVar1 + 0x10))))))) {
                    if (uVar8 + uVar14 < *(ulonglong *)(pTVar1 + 0x38)) {
                      lVar7 = WdLogNewEntry5_WdTrace();
                      *(ulonglong *)(lVar7 + 0x18) = (ulonglong)*(uint *)(pTVar1 + 0xc);
                      *(ulonglong *)(lVar7 + 0x20) = (ulonglong)*(uint *)(pTVar1 + 0x10);
                      *(ulonglong *)(lVar7 + 0x28) = (ulonglong)*(uint *)(pTVar1 + 0x14);
                      *(ulonglong *)(lVar7 + 0x30) = (ulonglong)*(uint *)(pTVar1 + 0x18);
                      *(ulonglong *)(lVar7 + 0x38) = (ulonglong)*(uint *)(pTVar1 + 0x30);
                      _WdLogGlobalForLineNumber = 0x18e;
                      lVar7 = WdLogNewEntry5_WdTrace();
                      *(undefined8 *)(lVar7 + 0x18) = *(undefined8 *)(pTVar1 + 0x38);
                      _WdLogGlobalForLineNumber = 399;
                    }
                    else {
                      lVar6 = AddSingleTargetMode((INDIRECT_DEVICE *)(uVar21 * 9),local_258,
                                                  local_268,pTVar1,(uint)uVar21);
                      if (lVar6 < 0) break;
                      iVar18 = iVar18 + 1;
                    }
                    puVar11 = local_240;
                  }
                  uVar5 = (uint)uVar21 + 1;
                  uVar21 = (ulonglong)uVar5;
                } while (uVar5 < *(uint *)(lVar15 + 0xe0));
                pIVar13 = local_1c8;
                if (iVar18 != 0) {
                  local_278[0] = (**(code **)(local_230[2] + 0x50))
                                           (*local_230,local_250[1],local_268);
                  if ((int)local_278[0] < 0) {
                    WdLogSingleEntry4(2,(longlong)(int)local_278[0],*local_230,local_250[1]);
                    _WdLogGlobalForLineNumber = 0xe0;
                    if ((int)local_278[0] < 0) goto LAB_14000bb6a;
                  }
                  else {
                    local_268 = (D3DKMDT_HVIDPNTARGETMODESET__ *)0x0;
                  }
                  param_1 = local_220;
                  goto LAB_14000bdcc;
                }
              }
              uVar20 = 0x198;
              WdLogSingleEntry1(2,0x198);
              goto LAB_14000bf8e;
            }
LAB_14000bfe1:
            uVar5 = local_278[0];
            goto LAB_14000bf95;
          }
LAB_14000bdcc:
          lVar6 = TopologyIterator::ReleaseModes((TopologyIterator *)local_278,true,true);
          if (lVar6 < 0) goto LAB_14000bfe1;
          if (bVar22) {
            local_218 = local_218 - *(longlong *)(lVar15 + 0xe8);
            local_210 = local_218;
          }
          if (bVar23) {
            local_208 = local_208 - *(longlong *)(lVar15 + 0xe8);
            local_200 = local_208;
          }
          lVar7 = 2;
          puVar11 = local_250;
          puVar4 = &local_1a8;
          do {
            puVar10 = puVar4;
            puVar9 = puVar11;
            uVar3 = *(undefined8 *)(puVar9 + 2);
            *(undefined8 *)puVar10 = *(undefined8 *)puVar9;
            *(undefined8 *)(puVar10 + 2) = uVar3;
            uVar3 = *(undefined8 *)(puVar9 + 6);
            *(undefined8 *)(puVar10 + 4) = *(undefined8 *)(puVar9 + 4);
            *(undefined8 *)(puVar10 + 6) = uVar3;
            uVar3 = *(undefined8 *)(puVar9 + 10);
            *(undefined8 *)(puVar10 + 8) = *(undefined8 *)(puVar9 + 8);
            *(undefined8 *)(puVar10 + 10) = uVar3;
            uVar3 = *(undefined8 *)(puVar9 + 0xe);
            *(undefined8 *)(puVar10 + 0xc) = *(undefined8 *)(puVar9 + 0xc);
            *(undefined8 *)(puVar10 + 0xe) = uVar3;
            uVar3 = *(undefined8 *)(puVar9 + 0x12);
            *(undefined8 *)(puVar10 + 0x10) = *(undefined8 *)(puVar9 + 0x10);
            *(undefined8 *)(puVar10 + 0x12) = uVar3;
            uVar3 = *(undefined8 *)(puVar9 + 0x16);
            *(undefined8 *)(puVar10 + 0x14) = *(undefined8 *)(puVar9 + 0x14);
            *(undefined8 *)(puVar10 + 0x16) = uVar3;
            uVar3 = *(undefined8 *)(puVar9 + 0x1a);
            *(undefined8 *)(puVar10 + 0x18) = *(undefined8 *)(puVar9 + 0x18);
            *(undefined8 *)(puVar10 + 0x1a) = uVar3;
            uVar3 = *(undefined8 *)(puVar9 + 0x1e);
            *(undefined8 *)(puVar10 + 0x1c) = *(undefined8 *)(puVar9 + 0x1c);
            *(undefined8 *)(puVar10 + 0x1e) = uVar3;
            lVar7 = lVar7 + -1;
            puVar11 = puVar9 + 0x20;
            puVar4 = puVar10 + 0x20;
          } while (lVar7 != 0);
          uVar3 = *(undefined8 *)(puVar9 + 0x22);
          iVar18 = *(int *)(param_1 + 8);
          p_Var16 = (__uint64 *)0x0;
          *(undefined8 *)(puVar10 + 0x20) = *(undefined8 *)(puVar9 + 0x20);
          *(undefined8 *)(puVar10 + 0x22) = uVar3;
          uVar3 = *(undefined8 *)(puVar9 + 0x26);
          *(undefined8 *)(puVar10 + 0x24) = *(undefined8 *)(puVar9 + 0x24);
          *(undefined8 *)(puVar10 + 0x26) = uVar3;
          uVar3 = *(undefined8 *)(puVar9 + 0x2a);
          *(undefined8 *)(puVar10 + 0x28) = *(undefined8 *)(puVar9 + 0x28);
          *(undefined8 *)(puVar10 + 0x2a) = uVar3;
          uVar3 = *(undefined8 *)(puVar9 + 0x2e);
          *(undefined8 *)(puVar10 + 0x2c) = *(undefined8 *)(puVar9 + 0x2c);
          *(undefined8 *)(puVar10 + 0x2e) = uVar3;
          uVar5 = puVar9[0x31];
          uVar19 = puVar9[0x32];
          uVar2 = puVar9[0x33];
          puVar10[0x30] = puVar9[0x30];
          puVar10[0x31] = uVar5;
          puVar10[0x32] = uVar19;
          puVar10[0x33] = uVar2;
          uVar5 = puVar9[0x35];
          uVar19 = puVar9[0x36];
          uVar2 = puVar9[0x37];
          puVar10[0x34] = puVar9[0x34];
          puVar10[0x35] = uVar5;
          puVar10[0x36] = uVar19;
          puVar10[0x37] = uVar2;
          *(undefined8 *)(puVar10 + 0x38) = *(undefined8 *)(puVar9 + 0x38);
          pTVar12 = (TopologyHelper *)(ulonglong)local_1a8;
          if (((iVar18 == 3) && (*(uint *)(param_1 + 0xc) == local_1a8)) &&
             (*(int *)(param_1 + 0x10) == iStack_1a4)) {
LAB_14000bef0:
            if ((*(uint *)(param_1 + 0xc) != local_1a8) || (*(int *)(param_1 + 0x10) != iStack_1a4))
            goto LAB_14000bf00;
LAB_14000bf12:
            if ((char)p_Var16 != '\0') goto LAB_14000bf17;
          }
          else {
            bVar22 = (int)((ulonglong)uStack_1a0 >> 0x20) == 0xfe;
            if (bVar22) {
              local_198 = 1;
            }
            p_Var16 = (__uint64 *)(ulonglong)bVar22;
            if (iVar18 != 4) goto LAB_14000bef0;
LAB_14000bf00:
            if (iStack_194 != 0xfe) goto LAB_14000bf12;
            uStack_190 = 0x11;
LAB_14000bf17:
            pTVar12 = (TopologyHelper *)&local_1a8;
            uVar5 = (**(code **)(local_1d0 + 0x38))(local_1e0);
            if ((int)uVar5 < 0) goto LAB_14000c005;
          }
          TopologyIterator::operator++((TopologyIterator *)local_278);
          uVar14 = (ulonglong)local_278[0];
          lVar7 = local_1b8;
          this = local_1c0;
        } while( true );
      }
      WdLogSingleEntry2(2,local_1f8,uVar8);
      _WdLogGlobalForLineNumber = 0xe8;
LAB_14000b817:
      uVar5 = 0xc01e0301;
    }
  }
LAB_14000bf9f:
  ExReleaseResourceAndLeaveCriticalRegion(pIVar13);
  return uVar5;
LAB_14000c005:
  WdLogSingleEntry2(2,(longlong)(int)uVar5,local_1e0);
  _WdLogGlobalForLineNumber = 0x1db;
LAB_14000bf95:
  TopologyIterator::~TopologyIterator((TopologyIterator *)local_278);
  goto LAB_14000bf9f;
}



===== IsSupportedVidPn @ 14000c03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::IsSupportedVidPn(struct _DXGKARG_ISSUPPORTEDVIDPN *
   __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::IsSupportedVidPn(INDIRECT_DEVICE *this,_DXGKARG_ISSUPPORTEDVIDPN *param_1)

{
  long lVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 local_res8 [2];
  ulonglong local_res10;
  __uint64 local_res18 [2];
  __uint64 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  longlong local_48;
  
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  if (param_1 == (_DXGKARG_ISSUPPORTEDVIDPN *)0x0) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar3 = WdLogNewEntry5_WdTrace();
    *(undefined8 *)(lVar3 + 0x18) = 0x69;
    local_60 = *(undefined8 *)param_1;
    local_48 = 0;
    _WdLogGlobalForLineNumber = 0x69;
    local_58 = 0;
    uStack_50 = 0;
    lVar1 = TopologyHelper::Init((TopologyHelper *)&local_60,(_DXGKRNL_INTERFACE *)(this + 0x38));
    if (lVar1 < 0) {
      WdLogSingleEntry1(2,(longlong)lVar1);
      _WdLogGlobalForLineNumber = 0x6f;
    }
    else {
      uVar4 = 0;
      uVar2 = 0;
      if (*(int *)(this + 0x31c) != 0) {
        do {
          local_res10 = 0;
          lVar1 = (**(code **)(local_48 + 8))(local_58,uVar4,&local_res10);
          if (lVar1 == -0x3fe1fcc7) {
            local_res10 = 0;
          }
          else {
            if (lVar1 < 0) {
              WdLogSingleEntry1(2,(longlong)lVar1);
              _WdLogGlobalForLineNumber = 0x7f;
              goto LAB_14000c24d;
            }
            if (1 < local_res10) {
              WdLogSingleEntry1(3,0x86);
              _WdLogGlobalForLineNumber = 0x86;
              lVar1 = 0;
              param_1[8] = (_DXGKARG_ISSUPPORTEDVIDPN)0x0;
              goto LAB_14000c24d;
            }
          }
          uVar2 = *(uint *)(this + 0x31c);
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar2);
      }
      uVar4 = 0;
      if (uVar2 != 0) {
        do {
          local_res8[0] = 0;
          lVar1 = (**(code **)(local_48 + 0x18))(local_58,uVar4 + 0x100,local_res8);
          if (lVar1 < 0) {
            WdLogSingleEntry1(2,(longlong)lVar1);
            _WdLogGlobalForLineNumber = 0x92;
            goto LAB_14000c24d;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(this + 0x31c));
      }
      local_res18[0] = 0;
      local_68 = 0;
      local_res18[1] = 0;
      lVar1 = ComputeVidPnBandwidth
                        (this,(TopologyHelper *)&local_60,local_res18,&local_68,local_res18 + 1);
      if (-1 < lVar1) {
        if (*(ulonglong *)(this + 800) < local_res18[0]) {
          param_1[8] = (_DXGKARG_ISSUPPORTEDVIDPN)0x0;
          lVar3 = WdLogNewEntry5_WdTrace();
          *(undefined8 *)(lVar3 + 0x18) = 0xa3;
          _WdLogGlobalForLineNumber = 0xa3;
        }
        else {
          param_1[8] = (_DXGKARG_ISSUPPORTEDVIDPN)0x1;
        }
      }
    }
  }
LAB_14000c24d:
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar1;
}



===== QueryConnectionChange @ 14000c274 =====

/* public: long __cdecl INDIRECT_DEVICE::QueryConnectionChange(struct _DXGKARG_QUERYCONNECTIONCHANGE
   * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::QueryConnectionChange
          (INDIRECT_DEVICE *this,_DXGKARG_QUERYCONNECTIONCHANGE *param_1)

{
  INDIRECT_DEVICE *pIVar1;
  INDIRECT_DEVICE *pIVar2;
  INDIRECT_DEVICE *pIVar3;
  longlong lVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  pIVar1 = this + 0x350;
  ExEnterCriticalRegionAndAcquireResourceShared(pIVar1);
  puVar9 = auStack_28;
  pIVar2 = this + 0x480;
  pIVar3 = *(INDIRECT_DEVICE **)pIVar2;
  if (pIVar3 != pIVar2) {
    if ((*(INDIRECT_DEVICE **)(pIVar3 + 8) == pIVar2) &&
       (lVar4 = *(longlong *)pIVar3, *(INDIRECT_DEVICE **)(lVar4 + 8) == pIVar3)) {
      *(longlong *)pIVar2 = lVar4;
      *(INDIRECT_DEVICE **)(lVar4 + 8) = pIVar2;
      uVar6 = *(undefined4 *)(pIVar3 + 0x14);
      uVar7 = *(undefined4 *)(pIVar3 + 0x18);
      uVar8 = *(undefined4 *)(pIVar3 + 0x1c);
      *(undefined4 *)param_1 = *(undefined4 *)(pIVar3 + 0x10);
      *(undefined4 *)(param_1 + 4) = uVar6;
      *(undefined4 *)(param_1 + 8) = uVar7;
      *(undefined4 *)(param_1 + 0xc) = uVar8;
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(pIVar3 + 0x20);
      ExFreeToPagedLookasideList(this + 0x400);
      ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
      return 0;
    }
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    puVar9 = auStack_20;
  }
  *(undefined8 *)(puVar9 + -8) = 0x14000c30c;
  ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
  return 0xff;
}



===== QueryVidPnHWCapability @ 14000c330 =====

/* public: long __cdecl INDIRECT_DEVICE::QueryVidPnHWCapability(struct
   _DXGKARG_QUERYVIDPNHWCAPABILITY * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::QueryVidPnHWCapability
          (INDIRECT_DEVICE *this,_DXGKARG_QUERYVIDPNHWCAPABILITY *param_1)

{
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x3f;
  return 0;
}



===== RecommendFunctionalVidPn @ 14000c340 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::RecommendFunctionalVidPn(struct
   _DXGKARG_RECOMMENDFUNCTIONALVIDPN const * __ptr64 const) __ptr64 */

long __thiscall
INDIRECT_DEVICE::RecommendFunctionalVidPn
          (INDIRECT_DEVICE *this,_DXGKARG_RECOMMENDFUNCTIONALVIDPN *param_1)

{
  long lVar1;
  
  if (param_1 == (_DXGKARG_RECOMMENDFUNCTIONALVIDPN *)0x0) {
    lVar1 = -0x3ffffff3;
  }
  else {
    WdLogSingleEntry1(1,0xbe);
    lVar1 = -0x3fe1fcdd;
    _WdLogGlobalForLineNumber = 0xbe;
  }
  return lVar1;
}



===== RecommendMonitorModes @ 14000c384 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::RecommendMonitorModes(struct _DXGKARG_RECOMMENDMONITORMODES
   const * __ptr64 const) __ptr64 */

long __thiscall
INDIRECT_DEVICE::RecommendMonitorModes
          (INDIRECT_DEVICE *this,_DXGKARG_RECOMMENDMONITORMODES *param_1)

{
  INDIRECT_DEVICE *pIVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  longlong local_res8;
  undefined4 local_res10;
  undefined4 uStackX_14;
  undefined4 local_res18;
  undefined4 uStackX_1c;
  undefined4 local_res20;
  undefined4 uStackX_24;
  
  pIVar1 = this + 0x350;
  local_res8 = 0;
  ExEnterCriticalRegionAndAcquireResourceShared(pIVar1);
  if (((param_1 == (_DXGKARG_RECOMMENDMONITORMODES *)0x0) || (*(longlong *)(param_1 + 0x10) == 0))
     || ((*(int *)(this + 4) == 0 && (*(int *)param_1 != 0x100)))) {
    ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
    lVar5 = -0x3ffffff3;
  }
  else {
    lVar7 = (ulonglong)(*(int *)param_1 - 0x100) * 0x130 + *(longlong *)(this + 0x2c8);
    uVar8 = 0;
    if (*(int *)(lVar7 + 0xe0) != 0) {
      do {
        lVar2 = *(longlong *)(lVar7 + 0xd8);
        uVar6 = (ulonglong)uVar8;
        if (*(char *)(lVar2 + uVar6 * 0x48) != '\0') {
          iVar4 = (**(code **)(*(longlong *)(param_1 + 0x10) + 0x20))
                            (*(undefined8 *)(param_1 + 8),&local_res8);
          if (iVar4 < 0) {
            ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
            return iVar4;
          }
          if (local_res8 == 0) {
            WdLogSingleEntry1(1,0x277);
            _WdLogGlobalForLineNumber = 0x277;
          }
          *(undefined4 *)(local_res8 + 8) = 0xff;
          uVar3 = *(undefined8 *)(lVar2 + 4 + uVar6 * 0x48);
          local_res10 = (undefined4)uVar3;
          uStackX_14 = (undefined4)((ulonglong)uVar3 >> 0x20);
          *(undefined8 *)(local_res8 + 0xc) = uVar3;
          uVar3 = *(undefined8 *)(lVar2 + 0xc + uVar6 * 0x48);
          local_res18 = (undefined4)uVar3;
          uStackX_1c = (undefined4)((ulonglong)uVar3 >> 0x20);
          *(undefined8 *)(local_res8 + 0x14) = uVar3;
          uVar3 = *(undefined8 *)(lVar2 + 0x14 + uVar6 * 0x48);
          local_res20 = (undefined4)uVar3;
          uStackX_24 = (undefined4)((ulonglong)uVar3 >> 0x20);
          *(undefined8 *)(local_res8 + 0x1c) = uVar3;
          *(undefined8 *)(local_res8 + 0x24) = *(undefined8 *)(lVar2 + 0x1c + uVar6 * 0x48);
          *(undefined8 *)(local_res8 + 0x30) = *(undefined8 *)(lVar2 + 0x28 + uVar6 * 0x48);
          *(undefined4 *)(local_res8 + 0x38) = 1;
          *(undefined4 *)(local_res8 + 0x54) = 5;
          *(undefined4 *)(local_res8 + 0x40) = 2;
          *(undefined4 *)(local_res8 + 0x44) = 8;
          *(undefined4 *)(local_res8 + 0x48) = 8;
          *(undefined4 *)(local_res8 + 0x4c) = 8;
          *(undefined4 *)(local_res8 + 0x50) = 8;
          *(uint *)(local_res8 + 0x58) = 2 - (uint)(*(char *)(lVar2 + 0x34 + uVar6 * 0x48) != '\0');
          iVar4 = (**(code **)(*(longlong *)(param_1 + 0x10) + 0x28))
                            (*(undefined8 *)(param_1 + 8),local_res8);
          if ((iVar4 < 0) &&
             (iVar4 = (**(code **)(*(longlong *)(param_1 + 0x10) + 0x30))
                                (*(undefined8 *)(param_1 + 8),local_res8), iVar4 < 0)) {
            WdLogSingleEntry1(1,0x295);
            _WdLogGlobalForLineNumber = 0x295;
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(lVar7 + 0xe0));
    }
    ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
    lVar5 = 0;
  }
  return lVar5;
}



===== SetTargetAdjustedColorimetry @ 14000c5f8 =====

/* public: long __cdecl INDIRECT_DEVICE::SetTargetAdjustedColorimetry(struct
   _DXGKARG_SETTARGETADJUSTEDCOLORIMETRY2 * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::SetTargetAdjustedColorimetry
          (INDIRECT_DEVICE *this,_DXGKARG_SETTARGETADJUSTEDCOLORIMETRY2 *param_1)

{
  long lVar1;
  
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  if (*(uint *)(this + 0x31c) < *(int *)param_1 - 0x100U) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = 0;
    *(undefined4 *)
     ((ulonglong)(*(int *)param_1 - 0x100U) * 0x130 + 0x120 + *(longlong *)(this + 0x2c8)) =
         *(undefined4 *)(param_1 + 0x38);
  }
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar1;
}



===== SetTargetGamma @ 14000c67c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::SetTargetGamma(struct _DXGKARG_SETTARGETGAMMA const *
   __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::SetTargetGamma(INDIRECT_DEVICE *this,_DXGKARG_SETTARGETGAMMA *param_1)

{
  int iVar1;
  long lVar2;
  undefined4 *_Dst;
  ulonglong uVar3;
  size_t _Size;
  
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  if (param_1 != (_DXGKARG_SETTARGETGAMMA *)0x0) {
    iVar1 = *(int *)(param_1 + 8);
    if ((iVar1 != 1) && (iVar1 != 2)) {
      if (iVar1 == 4) {
        if (this[0x32f] != (INDIRECT_DEVICE)0x0) goto LAB_14000c725;
        WdLogSingleEntry1(1,0x442);
        _WdLogGlobalForLineNumber = 0x442;
      }
      else {
        WdLogSingleEntry1(2,(longlong)iVar1);
        _WdLogGlobalForLineNumber = 0x446;
      }
      lVar2 = -0x3fffff45;
      goto LAB_14000c867;
    }
LAB_14000c725:
    if ((this[0x2f8] == (INDIRECT_DEVICE)0x0) ||
       ((this[0x32f] == (INDIRECT_DEVICE)0x0 && (this[0x328] == (INDIRECT_DEVICE)0x0)))) {
LAB_14000c865:
      lVar2 = 0;
      goto LAB_14000c867;
    }
    _Dst = (undefined4 *)ExAllocatePool2(0x100,0xc040,0x4b646449);
    if (_Dst == (undefined4 *)0x0) {
      WdLogSingleEntry1(2,0x450);
      _WdLogGlobalForLineNumber = 0x450;
      lVar2 = -0x3fffffe9;
      goto LAB_14000c867;
    }
    memset(_Dst,0,0xc040);
    *_Dst = 6;
    _Dst[1] = *(int *)param_1 + -0x100;
    _Dst[2] = *(undefined4 *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 2) {
      _Size = 0x600;
      if (0x5ff < *(ulonglong *)(param_1 + 0x10)) {
LAB_14000c7e7:
        memmove(_Dst + 3,*(void **)(param_1 + 0x18),_Size);
        goto LAB_14000c7f4;
      }
      WdLogSingleEntry1(2);
      _WdLogGlobalForLineNumber = 0x463;
    }
    else {
      if (*(int *)(param_1 + 8) != 4) {
LAB_14000c7f4:
        uVar3 = Feature_SupressIddGammaDxglogError__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 == 0) {
          lVar2 = SendMessageToUserMode
                            (this,0xc040,_Dst,0,(void *)0x0,
                             (_func_void_void_ptr__IO_STATUS_BLOCK_ptr *)0x0,(void *)0x0);
        }
        else {
          lVar2 = SendMessageToUserMode
                            (this,0xc040,_Dst,0,(void *)0x0,
                             (_func_void_void_ptr__IO_STATUS_BLOCK_ptr *)0x0,(void *)0x0);
          if (-1 < lVar2) {
            ExFreePoolWithTag(_Dst,0);
            goto LAB_14000c865;
          }
          WdLogSingleEntry1(2,(longlong)lVar2);
          _WdLogGlobalForLineNumber = 0x47d;
        }
        ExFreePoolWithTag(_Dst,0);
        goto LAB_14000c867;
      }
      _Size = 0xc034;
      if (0xc033 < *(ulonglong *)(param_1 + 0x10)) goto LAB_14000c7e7;
      WdLogSingleEntry1(2);
      _WdLogGlobalForLineNumber = 0x470;
    }
    ExFreePoolWithTag(_Dst,0);
  }
  lVar2 = -0x3ffffff3;
LAB_14000c867:
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar2;
}



===== SetTimingsFromVidPn @ 14000c8fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000cbd0) */
/* WARNING: Removing unreachable block (ram,0x00014000cfe6) */
/* WARNING: Removing unreachable block (ram,0x00014000cc0e) */
/* WARNING: Removing unreachable block (ram,0x00014000cc2e) */
/* WARNING: Removing unreachable block (ram,0x00014000cc37) */
/* WARNING: Removing unreachable block (ram,0x00014000cc57) */
/* WARNING: Removing unreachable block (ram,0x00014000cc8b) */
/* WARNING: Removing unreachable block (ram,0x00014000cca8) */
/* WARNING: Removing unreachable block (ram,0x00014000cfc6) */
/* WARNING: Removing unreachable block (ram,0x00014000ccb2) */
/* WARNING: Removing unreachable block (ram,0x00014000cfa2) */
/* WARNING: Removing unreachable block (ram,0x00014000ccef) */
/* WARNING: Removing unreachable block (ram,0x00014000cd13) */
/* WARNING: Removing unreachable block (ram,0x00014000cd1c) */
/* WARNING: Removing unreachable block (ram,0x00014000cd3e) */
/* WARNING: Removing unreachable block (ram,0x00014000cf4b) */
/* WARNING: Removing unreachable block (ram,0x00014000cf6f) */
/* WARNING: Removing unreachable block (ram,0x00014000cd4e) */
/* WARNING: Removing unreachable block (ram,0x00014000cd95) */
/* WARNING: Removing unreachable block (ram,0x00014000cdb2) */
/* WARNING: Removing unreachable block (ram,0x00014000cf82) */
/* WARNING: Removing unreachable block (ram,0x00014000cdbc) */
/* WARNING: Removing unreachable block (ram,0x00014000cdc9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::SetTimingsFromVidPn(struct _DXGKARG_SETTIMINGSFROMVIDPN *
   __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::SetTimingsFromVidPn(INDIRECT_DEVICE *this,_DXGKARG_SETTIMINGSFROMVIDPN *param_1)

{
  INDIRECT_DEVICE *pIVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  ulonglong uVar8;
  uint uVar9;
  INDIRECT_DEVICE *pIVar10;
  undefined8 uVar11;
  INDIRECT_DEVICE *pIVar12;
  _DXGKARG_SETTIMINGSFROMVIDPN *p_Var13;
  undefined8 uVar14;
  VIDPN_SOURCE_INFO *pVVar15;
  INDIRECT_DEVICE *pIVar16;
  INDIRECT_DEVICE *pIVar17;
  undefined8 in_R8;
  undefined8 uVar18;
  int *piVar19;
  uint uVar20;
  longlong lVar21;
  undefined4 local_res18;
  uint local_res20;
  undefined8 local_c8;
  longlong local_c0;
  uint local_b8;
  INDIRECT_DEVICE *local_98;
  uint local_90;
  INDIRECT_DEVICE *local_70;
  longlong local_68;
  undefined8 local_60 [2];
  INDIRECT_DEVICE *local_50;
  
  pIVar1 = this + 0x350;
  pIVar17 = pIVar1;
  p_Var13 = param_1;
  ExEnterCriticalRegionAndAcquireResourceExclusive();
  if (param_1 == (_DXGKARG_SETTIMINGSFROMVIDPN *)0x0) {
    WdLogSingleEntry1(2,0x2cc);
    _WdLogGlobalForLineNumber = 0x2cc;
    iVar6 = -0x3ffffff3;
  }
  else {
    if ((Microsoft_Windows_IndirectDisplays_ClassExtension_EventsEnableBits & 2) != 0) {
      McTemplateK0xq_EtwWriteTransfer
                (pIVar17,p_Var13,in_R8,this,(char)*(undefined4 *)(param_1 + 0x18));
    }
    `anonymous_namespace'::CALLONEXIT<<lambda_bd554ddd1f9fda9e2fe11075810952ec>_>(&local_c8,this);
    uVar8 = 0;
    uVar9 = 0;
    if (*(int *)(this + 0x31c) != 0) {
      do {
        pVVar15 = (VIDPN_SOURCE_INFO *)(uVar8 * 0xf0 + *(longlong *)(this + 0x2d0));
        *(undefined4 *)(pVVar15 + 4) = 0;
        OnSourcePowerOff(this,pVVar15);
        *(undefined8 *)(pVVar15 + 0x30) = 0;
        *(undefined8 *)(pVVar15 + 0x38) = 0;
        *(undefined8 *)(pVVar15 + 8) = 0;
        *(undefined8 *)(pVVar15 + 0x10) = 0;
        uVar20 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar20;
        *(undefined8 *)(pVVar15 + 0x18) = 0;
        *(undefined8 *)(pVVar15 + 0x20) = 0;
        *(undefined8 *)(pVVar15 + 0x28) = 0;
        uVar9 = *(uint *)(this + 0x31c);
      } while (uVar20 < uVar9);
    }
    uVar20 = 0;
    if (uVar9 != 0) {
      do {
        uVar8 = (ulonglong)uVar20;
        uVar20 = uVar20 + 1;
        *(undefined4 *)(uVar8 * 0x130 + *(longlong *)(this + 0x2c8)) = 0xffffffff;
      } while (uVar20 < *(uint *)(this + 0x31c));
    }
    pIVar10 = *(INDIRECT_DEVICE **)param_1;
    pIVar17 = (INDIRECT_DEVICE *)&local_c0;
    uVar9 = *(uint *)(param_1 + 0x18);
    local_c0 = 0;
    local_98 = pIVar10;
    local_90 = uVar9;
    iVar6 = (**(code **)(this + 200))(pIVar10,1);
    pIVar16 = (INDIRECT_DEVICE *)(longlong)iVar6;
    if (iVar6 < 0) {
      pIVar10 = (INDIRECT_DEVICE *)0x2;
      WdLogSingleEntry1();
      _WdLogGlobalForLineNumber = 0x2f6;
    }
    else {
      local_60[0] = 0;
      pIVar16 = (INDIRECT_DEVICE *)local_60;
      local_68 = 0;
      iVar6 = (**(code **)(local_c0 + 8))();
      pIVar12 = (INDIRECT_DEVICE *)0x0;
      pIVar17 = (INDIRECT_DEVICE *)(longlong)iVar6;
      if (iVar6 < 0) {
        pIVar10 = (INDIRECT_DEVICE *)0x2;
        WdLogSingleEntry1();
        _WdLogGlobalForLineNumber = 0x2ff;
        pIVar16 = pIVar17;
        pIVar17 = pIVar12;
      }
      else {
        local_b8 = 0;
        local_50 = (INDIRECT_DEVICE *)0x0;
        if (this[0x2f8] != (INDIRECT_DEVICE)0x0) {
          pIVar10 = (INDIRECT_DEVICE *)0x100;
          local_b8 = uVar9 * 0x50 + 8;
          pIVar16 = (INDIRECT_DEVICE *)(ulonglong)local_b8;
          local_50 = (INDIRECT_DEVICE *)ExAllocatePool2();
          uVar18 = 0;
          if (local_50 == (INDIRECT_DEVICE *)0x0) {
            uVar11 = 2;
            uVar14 = 0x30d;
            WdLogSingleEntry1();
            _WdLogGlobalForLineNumber = 0x30d;
            if ((Microsoft_Windows_IndirectDisplays_ClassExtension_EventsEnableBits & 2) != 0) {
              McTemplateK0x_EtwWriteTransfer(uVar11,uVar14,uVar18,local_c8);
            }
            iVar6 = -0x3fffffe9;
            goto LAB_14000d0b6;
          }
          *(undefined4 *)local_50 = 0x12;
          *(uint *)(local_50 + 4) = uVar9;
        }
        local_res20 = 0;
        if (uVar9 != 0) {
          lVar21 = 0;
          local_70 = local_50 + 0xc;
          do {
            lVar2 = *(longlong *)(param_1 + 0x20);
            piVar19 = (int *)((ulonglong)(*(int *)(lVar21 + lVar2) - 0x100) * 0x130 +
                             *(longlong *)(this + 0x2c8));
            if ((*(uint *)(lVar21 + 0xc + lVar2) & 4) != 0) {
              iVar6 = (**(code **)(local_68 + 0x18))(local_60[0],*(undefined4 *)(lVar21 + lVar2));
              pIVar17 = (INDIRECT_DEVICE *)(longlong)iVar6;
              if (iVar6 < 0) {
                pIVar16 = (INDIRECT_DEVICE *)(ulonglong)*(uint *)(lVar21 + lVar2);
                pIVar10 = (INDIRECT_DEVICE *)0x2;
                WdLogSingleEntry2();
                _WdLogGlobalForLineNumber = 0x328;
                goto LAB_14000d0a4;
              }
            }
            if (((*(uint *)(lVar21 + 0xc + lVar2) & 3) != 0) || (local_res18 = 0, *piVar19 != -1)) {
              local_res18 = 1;
            }
            *piVar19 = -1;
            iVar6 = (int)pIVar17;
            uVar9 = *(uint *)(lVar21 + 0x20 + lVar2);
            *(uint *)(lVar21 + 0x20 + lVar2) =
                 (uVar9 ^ *(uint *)(lVar21 + lVar2)) & 0xffffff ^ uVar9;
            pIVar10 = *(INDIRECT_DEVICE **)(piVar19 + 0x46);
            *(INDIRECT_DEVICE **)(piVar19 + 0x46) = pIVar10 + 1;
            *(INDIRECT_DEVICE **)(lVar21 + 0x18 + lVar2) = pIVar10;
            *(uint *)(lVar21 + 0x20 + lVar2) =
                 *(uint *)(lVar21 + 0x20 + lVar2) & 0xfeffffff | 0xe000000;
            if ((Microsoft_Windows_IndirectDisplays_ClassExtension_EventsEnableBits & 2) != 0) {
              uVar9 = *(int *)(lVar21 + lVar2) - 0x100;
              pIVar10 = (INDIRECT_DEVICE *)(ulonglong)uVar9;
              McTemplateK0xqqtqqqqq_EtwWriteTransfer
                        (pIVar10,0xffffffff,0,this,(char)uVar9,(char)local_res20,(char)local_res18,
                         (char)*piVar19,(char)piVar19[5],(char)piVar19[6],
                         (char)*(undefined4 *)(lVar21 + 4 + lVar2),
                         (byte)(*(uint *)(lVar21 + 8 + lVar2) >> 2) & 0x3f);
            }
            if (this[0x2f8] != (INDIRECT_DEVICE)0x0) {
              *(int *)(local_70 + -4) = *(int *)(lVar21 + lVar2) + -0x100;
              *(undefined4 *)local_70 = local_res18;
              *(int *)(local_70 + 4) = *piVar19;
              uVar18 = *(undefined8 *)(piVar19 + 6);
              *(undefined8 *)(local_70 + 0xc) = *(undefined8 *)(piVar19 + 4);
              *(undefined8 *)(local_70 + 0x14) = uVar18;
              uVar18 = *(undefined8 *)(piVar19 + 10);
              *(undefined8 *)(local_70 + 0x1c) = *(undefined8 *)(piVar19 + 8);
              *(undefined8 *)(local_70 + 0x24) = uVar18;
              iVar3 = piVar19[0xd];
              iVar4 = piVar19[0xe];
              iVar5 = piVar19[0xf];
              *(int *)(local_70 + 0x2c) = piVar19[0xc];
              *(int *)(local_70 + 0x30) = iVar3;
              *(int *)(local_70 + 0x34) = iVar4;
              *(int *)(local_70 + 0x38) = iVar5;
              *(undefined8 *)(local_70 + 0x3c) = *(undefined8 *)(piVar19 + 0x10);
              *(undefined4 *)(local_70 + 0x44) = *(undefined4 *)(lVar21 + 4 + lVar2);
              *(undefined4 *)(local_70 + 0x48) = *(undefined4 *)(lVar21 + 8 + lVar2);
            }
            pIVar16 = local_70 + 0x50;
            local_res20 = local_res20 + 1;
            lVar21 = lVar21 + 0x38;
            local_70 = pIVar16;
          } while (local_res20 < local_90);
        }
        pIVar12 = local_50;
        pIVar17 = (INDIRECT_DEVICE *)0x0;
        if (this[0x2f8] == (INDIRECT_DEVICE)0x0) {
          if (iVar6 < 0) {
            pIVar16 = pIVar17;
            pIVar12 = pIVar17;
            if (*(int *)(this + 0x31c) != 0) {
              do {
                uVar9 = (int)pIVar12 + 1;
                pIVar16 = (INDIRECT_DEVICE *)(ulonglong)uVar9;
                pIVar10 = (INDIRECT_DEVICE *)((longlong)pIVar12 * 0xf0);
                *(undefined4 *)(pIVar10 + *(longlong *)(this + 0x2d0) + 4) = 0;
                pIVar12 = pIVar16;
              } while (uVar9 < *(uint *)(this + 0x31c));
            }
          }
        }
        else {
          pIVar16 = (INDIRECT_DEVICE *)(ulonglong)local_b8;
          pIVar17 = local_50;
          lVar7 = SendMessageToUserMode
                            (this,local_b8,local_50,0,(void *)0x0,
                             (_func_void_void_ptr__IO_STATUS_BLOCK_ptr *)0x0,(void *)0x0);
          if (lVar7 < 0) {
            pIVar16 = (INDIRECT_DEVICE *)(longlong)lVar7;
            this = (INDIRECT_DEVICE *)0x2;
            WdLogSingleEntry1();
            _WdLogGlobalForLineNumber = 0x3a3;
          }
          pIVar10 = this;
          if (pIVar12 != (INDIRECT_DEVICE *)0x0) {
            pIVar16 = (INDIRECT_DEVICE *)0x0;
            ExFreePoolWithTag();
            pIVar10 = pIVar12;
          }
          iVar6 = 0;
        }
      }
    }
LAB_14000d0a4:
    if ((Microsoft_Windows_IndirectDisplays_ClassExtension_EventsEnableBits & 2) != 0) {
      McTemplateK0x_EtwWriteTransfer(pIVar10,pIVar16,pIVar17,local_c8);
    }
  }
LAB_14000d0b6:
  ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
  return iVar6;
}



===== SetVidPnSourceVisibility @ 14000d0e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::SetVidPnSourceVisibility(struct
   _DXGKARG_SETVIDPNSOURCEVISIBILITY const * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::SetVidPnSourceVisibility
          (INDIRECT_DEVICE *this,_DXGKARG_SETVIDPNSOURCEVISIBILITY *param_1)

{
  INDIRECT_DEVICE *pIVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  undefined1 auStackY_88 [32];
  undefined4 local_48;
  uint local_44;
  uint local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  pIVar1 = this + 0x350;
  lVar3 = 0;
  ExEnterCriticalRegionAndAcquireResourceExclusive(pIVar1);
  if (param_1 != (_DXGKARG_SETVIDPNSOURCEVISIBILITY *)0x0) {
    uVar2 = *(uint *)param_1;
    if (uVar2 < *(uint *)(this + 0x31c)) {
      uVar6 = *(uint *)(this + 0x31c);
      if (uVar2 != 0xfffffffd) {
        uVar6 = uVar2 + 1;
      }
      uVar4 = 0;
      if (uVar2 != 0xfffffffd) {
        uVar4 = uVar2;
      }
      if (uVar4 < uVar6) {
        lVar5 = (ulonglong)uVar4 * 0xf0;
        do {
          *(uint *)(lVar5 + *(longlong *)(this + 0x2d0)) = (uint)(byte)param_1[4];
          if (this[0x2f8] != (INDIRECT_DEVICE)0x0) {
            local_48 = 1;
            local_40 = (uint)(byte)param_1[4];
            local_44 = uVar4;
            lVar3 = SendMessageToUserMode
                              (this,0xc,&local_48,0,(void *)0x0,
                               (_func_void_void_ptr__IO_STATUS_BLOCK_ptr *)0x0,(void *)0x0);
            if (lVar3 < 0) {
              WdLogSingleEntry1(2,(longlong)lVar3);
              _WdLogGlobalForLineNumber = 0x207;
              goto LAB_14000d1d1;
            }
          }
          uVar4 = uVar4 + 1;
          lVar5 = lVar5 + 0xf0;
        } while (uVar4 < uVar6);
        lVar3 = 0;
      }
LAB_14000d1d1:
      ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
      return lVar3;
    }
  }
  ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
  return -0x3ffffff3;
}



===== UpdateActiveVidPnPresentPath @ 14000d248 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::UpdateActiveVidPnPresentPath(struct
   _DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH const * __ptr64 const) __ptr64 */

long __thiscall
INDIRECT_DEVICE::UpdateActiveVidPnPresentPath
          (INDIRECT_DEVICE *this,_DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH *param_1)

{
  long lVar1;
  undefined4 *_Dst;
  ulonglong uVar2;
  
  if (param_1 == (_DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH *)0x0) {
    lVar1 = -0x3ffffff3;
  }
  else if ((*(int *)(param_1 + 0x150) == 1) || (*(int *)(param_1 + 0x150) == 2)) {
    if ((this[0x2f8] == (INDIRECT_DEVICE)0x0) || (this[0x328] == (INDIRECT_DEVICE)0x0)) {
      lVar1 = 0;
    }
    else {
      _Dst = (undefined4 *)ExAllocatePool2(0x100,0xc040,0x4b646449);
      if (_Dst == (undefined4 *)0x0) {
        WdLogSingleEntry1(2,0x22d);
        lVar1 = -0x3fffffe9;
        _WdLogGlobalForLineNumber = 0x22d;
      }
      else {
        memset(_Dst,0,0xc040);
        *_Dst = 6;
        _Dst[1] = *(int *)(param_1 + 4) + -0x100;
        _Dst[2] = *(undefined4 *)(param_1 + 0x150);
        if ((*(int *)(param_1 + 0x150) == 2) && (0x5ff < *(ulonglong *)(param_1 + 0x158))) {
          memmove(_Dst + 3,*(void **)(param_1 + 0x160),0x600);
        }
        uVar2 = Feature_SupressIddGammaDxglogError__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar2 == 0) {
          lVar1 = SendMessageToUserMode
                            (this,0xc040,_Dst,0,(void *)0x0,
                             (_func_void_void_ptr__IO_STATUS_BLOCK_ptr *)0x0,(void *)0x0);
        }
        else {
          lVar1 = SendMessageToUserMode
                            (this,0xc040,_Dst,0,(void *)0x0,
                             (_func_void_void_ptr__IO_STATUS_BLOCK_ptr *)0x0,(void *)0x0);
          if (lVar1 < 0) {
            WdLogSingleEntry1(2,(longlong)lVar1);
            _WdLogGlobalForLineNumber = 0x242;
          }
          else {
            lVar1 = 0;
          }
        }
        ExFreePoolWithTag(_Dst,0);
      }
    }
  }
  else {
    WdLogSingleEntry1(2);
    lVar1 = -0x3fffff45;
    _WdLogGlobalForLineNumber = 0x223;
  }
  return lVar1;
}



===== UpdateMinBandwidth @ 14000d3f8 =====

/* public: void __cdecl VIDPN_TARGET_INFO::UpdateMinBandwidth(void) __ptr64 */

void __thiscall VIDPN_TARGET_INFO::UpdateMinBandwidth(VIDPN_TARGET_INFO *this)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  *(undefined8 *)(this + 0xe8) = 0xffffffffffffffff;
  uVar3 = 0;
  lVar1 = *(longlong *)(this + 0xd8);
  if (lVar1 != 0) {
    for (; (uint)uVar3 < *(uint *)(this + 0xe0); uVar3 = (ulonglong)((uint)uVar3 + 1)) {
      if ((*(char *)(lVar1 + 1 + uVar3 * 0x48) != '\0') &&
         (uVar2 = *(ulonglong *)(lVar1 + 0x38 + uVar3 * 0x48), uVar2 < *(ulonglong *)(this + 0xe8)))
      {
        *(ulonglong *)(this + 0xe8) = uVar2;
      }
    }
  }
  if (*(longlong *)(this + 0xe8) == -1) {
    *(undefined8 *)(this + 0xe8) = 0;
  }
  return;
}



===== UpdateMonitorLinkInfo @ 14000d458 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::UpdateMonitorLinkInfo(struct _DXGKARG_UPDATEMONITORLINKINFO
   * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::UpdateMonitorLinkInfo
          (INDIRECT_DEVICE *this,_DXGKARG_UPDATEMONITORLINKINFO *param_1)

{
  uint uVar1;
  long lVar2;
  longlong lVar3;
  
  uVar1 = *(int *)param_1 - 0x100;
  if (*(uint *)(this + 0x31c) < uVar1) {
    WdLogSingleEntry1(2,*(int *)param_1);
    lVar2 = -0x3ffffff3;
    _WdLogGlobalForLineNumber = 0x2b1;
  }
  else {
    lVar3 = (ulonglong)uVar1 * 0x130 + *(longlong *)(this + 0x2c8);
    *(undefined4 *)(param_1 + 8) = 0;
    uVar1 = (*(uint *)(lVar3 + 0x124) & 1) * 2;
    *(uint *)(param_1 + 8) = uVar1;
    *(uint *)(param_1 + 8) = (*(uint *)(lVar3 + 0x128) & 1) << 2 | uVar1;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(lVar3 + 300);
    lVar2 = 0;
  }
  return lVar2;
}



===== TopologyIterator @ 14000d4e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __cdecl TopologyIterator::TopologyIterator(class TopologyHelper * __ptr64) __ptr64 */

TopologyIterator * __thiscall
TopologyIterator::TopologyIterator(TopologyIterator *this,TopologyHelper *param_1)

{
  int iVar1;
  
  *(undefined4 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(TopologyHelper **)(this + 0x48) = param_1;
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x18) + 0x28))(*(undefined8 *)(param_1 + 8));
  *(int *)this = iVar1;
  if (iVar1 < 0) {
    WdLogSingleEntry2(2,(longlong)iVar1,*(undefined8 *)(param_1 + 8));
    _WdLogGlobalForLineNumber = 0x27;
  }
  if (*(int *)this == 0x401e034c) {
    *(undefined4 *)this = 0;
  }
  return this;
}



===== ~TopologyIterator @ 14000d580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __cdecl TopologyIterator::~TopologyIterator(void) __ptr64 */

void __thiscall TopologyIterator::~TopologyIterator(TopologyIterator *this)

{
  int iVar1;
  
  ReleaseModes(this,true,true);
  if (*(longlong *)(this + 0x28) != 0) {
    iVar1 = (**(code **)(*(longlong *)(*(longlong *)(this + 0x48) + 0x18) + 0x40))
                      (*(undefined8 *)(*(longlong *)(this + 0x48) + 8));
    if (iVar1 < 0) {
      WdLogSingleEntry1(1,0x97);
      _WdLogGlobalForLineNumber = 0x97;
    }
    *(undefined8 *)(this + 0x28) = 0;
  }
  if (*(longlong *)(this + 0x30) != 0) {
    iVar1 = (**(code **)(*(longlong *)(*(longlong *)(this + 0x48) + 0x18) + 0x40))
                      (*(undefined8 *)(*(longlong *)(this + 0x48) + 8));
    if (iVar1 < 0) {
      WdLogSingleEntry1(1,0x9d);
      _WdLogGlobalForLineNumber = 0x9d;
    }
    *(undefined8 *)(this + 0x30) = 0;
  }
  return;
}



===== AcquireModes @ 14000d638 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl TopologyIterator::AcquireModes(bool,bool) __ptr64 */

long __thiscall TopologyIterator::AcquireModes(TopologyIterator *this,bool param_1,bool param_2)

{
  TopologyIterator *pTVar1;
  int iVar2;
  
  pTVar1 = this + 8;
  iVar2 = (**(code **)((*(undefined8 **)(this + 0x48))[2] + 0x10))
                    (**(undefined8 **)(this + 0x48),**(undefined4 **)(this + 0x28),pTVar1,
                     this + 0x18);
  *(int *)this = iVar2;
  if (iVar2 < 0) {
    WdLogSingleEntry3(2,(longlong)iVar2,**(undefined8 **)(this + 0x48),
                      **(undefined4 **)(this + 0x28));
    _WdLogGlobalForLineNumber = 0x4b;
  }
  else {
    iVar2 = (**(code **)(*(longlong *)(this + 0x18) + 0x18))(*(undefined8 *)pTVar1,this + 0x38);
    *(int *)this = iVar2;
    if (iVar2 < 0) {
      WdLogSingleEntry2(2,(longlong)iVar2,*(undefined8 *)pTVar1);
      _WdLogGlobalForLineNumber = 0x53;
    }
    else {
      pTVar1 = this + 0x10;
      iVar2 = (**(code **)((*(undefined8 **)(this + 0x48))[2] + 0x38))
                        (**(undefined8 **)(this + 0x48),
                         *(undefined4 *)(*(longlong *)(this + 0x28) + 4),pTVar1,this + 0x20);
      *(int *)this = iVar2;
      if (iVar2 < 0) {
        WdLogSingleEntry3(2,(longlong)iVar2,**(undefined8 **)(this + 0x48),
                          *(undefined4 *)(*(longlong *)(this + 0x28) + 4));
        _WdLogGlobalForLineNumber = 0x60;
      }
      else {
        iVar2 = (**(code **)(*(longlong *)(this + 0x20) + 0x18))(*(undefined8 *)pTVar1,this + 0x40);
        *(int *)this = iVar2;
        if (-1 < iVar2) {
          return iVar2;
        }
        WdLogSingleEntry2(2,(longlong)iVar2,*(undefined8 *)pTVar1);
        _WdLogGlobalForLineNumber = 0x68;
      }
    }
  }
  return *(long *)this;
}



===== Init @ 14000d798 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl TopologyHelper::Init(struct _DXGKRNL_INTERFACE const & __ptr64) __ptr64 */

long __thiscall TopologyHelper::Init(TopologyHelper *this,_DXGKRNL_INTERFACE *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(param_1 + 0x90))(*(undefined8 *)this,1,this + 0x10);
  if (-1 < iVar1) {
    iVar2 = (**(code **)(*(longlong *)(this + 0x10) + 8))(*(undefined8 *)this,this + 8,this + 0x18);
    iVar1 = 0;
    if (iVar2 < 0) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}



===== ReleaseModes @ 14000d800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl TopologyIterator::ReleaseModes(bool,bool) __ptr64 */

long __thiscall TopologyIterator::ReleaseModes(TopologyIterator *this,bool param_1,bool param_2)

{
  int iVar1;
  
  if ((param_1) && (*(longlong *)(this + 0x38) != 0)) {
    iVar1 = (**(code **)(*(longlong *)(this + 0x18) + 0x20))(*(undefined8 *)(this + 8));
    if (iVar1 < 0) {
      WdLogSingleEntry1(1);
      _WdLogGlobalForLineNumber = 0x76;
    }
    *(undefined8 *)(this + 0x38) = 0;
  }
  if (param_2) {
    if (*(longlong *)(this + 0x40) != 0) {
      iVar1 = (**(code **)(*(longlong *)(this + 0x20) + 0x20))(*(undefined8 *)(this + 0x10));
      if (iVar1 < 0) {
        WdLogSingleEntry1(1,0x7c);
        _WdLogGlobalForLineNumber = 0x7c;
      }
      *(undefined8 *)(this + 0x40) = 0;
    }
    if (*(longlong *)(this + 0x10) != 0) {
      iVar1 = (**(code **)((*(undefined8 **)(this + 0x48))[2] + 0x40))
                        (**(undefined8 **)(this + 0x48));
      if (iVar1 < 0) {
        WdLogSingleEntry1(1,0x82);
        _WdLogGlobalForLineNumber = 0x82;
      }
      *(undefined8 *)(this + 0x10) = 0;
    }
  }
  if ((param_1) && (*(longlong *)(this + 8) != 0)) {
    iVar1 = (**(code **)((*(undefined8 **)(this + 0x48))[2] + 0x18))(**(undefined8 **)(this + 0x48))
    ;
    if (iVar1 < 0) {
      WdLogSingleEntry1(1,0x88);
      _WdLogGlobalForLineNumber = 0x88;
    }
    *(undefined8 *)(this + 8) = 0;
  }
  return *(long *)this;
}



===== <lambda_invoker_cdecl> @ 14000d950 =====

void <lambda_d3f6885b853900ca9f7e79fb41d94694>::<lambda_invoker_cdecl>
               (INDIRECT_DEVICE *param_1,_IO_STATUS_BLOCK *param_2)

{
  INDIRECT_DEVICE::PostStartDeviceCallback(param_1,param_2);
  return;
}



===== INDIRECT_DEVICE @ 14000d968 =====

/* public: __cdecl INDIRECT_DEVICE::INDIRECT_DEVICE(struct _DEVICE_OBJECT * __ptr64,struct
   _LUID,unsigned int,struct _GUID) __ptr64 */

INDIRECT_DEVICE * __thiscall
INDIRECT_DEVICE::INDIRECT_DEVICE
          (INDIRECT_DEVICE *this,undefined8 param_1,undefined8 param_3,undefined4 param_4,
          undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(undefined8 *)(this + 0x10) = param_1;
  *(undefined8 *)this = 0x4b646449;
  *(undefined2 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  memset(this + 0x38,0,0x240);
  memset(this + 0x278,0,0x50);
  *(undefined8 *)(this + 0x2c8) = 0;
  *(undefined8 *)(this + 0x2d0) = 0;
  *(undefined2 *)(this + 0x2d8) = 0;
  *(undefined8 *)(this + 0x2e0) = 0;
  *(undefined8 *)(this + 0x2e8) = 0;
  *(undefined8 *)(this + 0x2f0) = 0;
  this[0x2f8] = (INDIRECT_DEVICE)0x0;
  *(undefined8 *)(this + 0x300) = 0;
  *(undefined8 *)(this + 0x308) = 0;
  *(undefined8 *)(this + 0x310) = 0;
  *(undefined4 *)(this + 0x498) = 3;
  uVar1 = *param_5;
  uVar2 = param_5[1];
  uVar3 = param_5[2];
  uVar4 = param_5[3];
  *(undefined4 *)(this + 0x4a4) = 3;
  *(undefined4 *)(this + 0x49c) = 8;
  *(undefined4 *)(this + 0x4a0) = 8;
  *(undefined4 *)(this + 0x318) = 0x101;
  *(undefined4 *)(this + 0x31c) = 1;
  *(undefined8 *)(this + 800) = 0;
  *(undefined8 *)(this + 0x328) = 0;
  this[0x330] = (INDIRECT_DEVICE)0x0;
  *(undefined8 *)(this + 0x334) = param_3;
  *(undefined4 *)(this + 0x33c) = param_4;
  *(undefined4 *)(this + 0x340) = uVar1;
  *(undefined4 *)(this + 0x344) = uVar2;
  *(undefined4 *)(this + 0x348) = uVar3;
  *(undefined4 *)(this + 0x34c) = uVar4;
  *(undefined4 *)(this + 0x3b8) = 2;
  this[0x3d0] = (INDIRECT_DEVICE)0x0;
  *(undefined8 *)(this + 0x490) = 0;
  ExInitializeResourceLite(this + 0x350);
  *(undefined8 *)(this + 0x3c0) = 0;
  *(undefined8 *)(this + 0x3c8) = 0;
  return this;
}



===== ~INDIRECT_DEVICE @ 14000dac0 =====

/* public: __cdecl INDIRECT_DEVICE::~INDIRECT_DEVICE(void) __ptr64 */

void __thiscall INDIRECT_DEVICE::~INDIRECT_DEVICE(INDIRECT_DEVICE *this)

{
  ExDeleteResourceLite(this + 0x350);
  AUTO_PTR_DETAILS::
  AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_>::
  ~AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_>
            ((AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_>
              *)(this + 0x2d0));
  AUTO_PTR_DETAILS::
  AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_>::
  ~AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_>
            ((AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_>
              *)(this + 0x2c8));
  return;
}



===== DispatchIoRequest @ 14000db04 =====

/* public: long __cdecl INDIRECT_DEVICE::DispatchIoRequest(unsigned long,struct
   _VIDEO_REQUEST_PACKET * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::DispatchIoRequest
          (INDIRECT_DEVICE *this,ulong param_1,_VIDEO_REQUEST_PACKET *param_2)

{
  return (-(uint)(param_2 != (_VIDEO_REQUEST_PACKET *)0x0) & 0xfffffff5) + 0xc000000d;
}



===== Escape @ 14000db1c =====

/* public: long __cdecl INDIRECT_DEVICE::Escape(struct _DXGKARG_ESCAPE const * __ptr64) __ptr64 */

long __thiscall INDIRECT_DEVICE::Escape(INDIRECT_DEVICE *this,_DXGKARG_ESCAPE *param_1)

{
  return 0;
}



===== GetChildContainerId @ 14000db28 =====

/* public: long __cdecl INDIRECT_DEVICE::GetChildContainerId(unsigned long,struct
   _DXGK_CHILD_CONTAINER_ID * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::GetChildContainerId
          (INDIRECT_DEVICE *this,ulong param_1,_DXGK_CHILD_CONTAINER_ID *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  long lVar5;
  
  ExEnterCriticalRegionAndAcquireResourceExclusive(this + 0x350);
  if (param_1 - 0x100 < *(uint *)(this + 0x31c)) {
    lVar5 = 0;
    lVar4 = (ulonglong)(param_1 - 0x100) * 0x130 + *(longlong *)(this + 0x2c8);
    if (*(int *)(lVar4 + 0x98) == 0) {
      uVar1 = *(undefined4 *)(param_2 + 4);
      uVar2 = *(undefined4 *)(param_2 + 8);
      uVar3 = *(undefined4 *)(param_2 + 0xc);
      lVar5 = -0x3fe2ffff;
      *(undefined4 *)(lVar4 + 0x9c) = *(undefined4 *)param_2;
      *(undefined4 *)(lVar4 + 0xa0) = uVar1;
      *(undefined4 *)(lVar4 + 0xa4) = uVar2;
      *(undefined4 *)(lVar4 + 0xa8) = uVar3;
    }
    else {
      uVar1 = *(undefined4 *)(lVar4 + 0xa0);
      uVar2 = *(undefined4 *)(lVar4 + 0xa4);
      uVar3 = *(undefined4 *)(lVar4 + 0xa8);
      *(undefined4 *)param_2 = *(undefined4 *)(lVar4 + 0x9c);
      *(undefined4 *)(param_2 + 4) = uVar1;
      *(undefined4 *)(param_2 + 8) = uVar2;
      *(undefined4 *)(param_2 + 0xc) = uVar3;
    }
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar5;
}



===== KmdDodAllocUnicodeString @ 14000dbd4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl KmdDodAllocUnicodeString(struct _UNICODE_STRING * __ptr64,unsigned long) */

long __cdecl KmdDodAllocUnicodeString(_UNICODE_STRING *param_1,ulong param_2)

{
  short sVar1;
  long lVar2;
  undefined2 *puVar3;
  
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  sVar1 = ((short)param_2 + 1) * 2;
  *(short *)(param_1 + 2) = sVar1;
  puVar3 = (undefined2 *)ExAllocatePool2(0x100,sVar1,0x4b646449);
  *(undefined2 **)(param_1 + 8) = puVar3;
  if (puVar3 == (undefined2 *)0x0) {
    *(undefined4 *)param_1 = 0;
    WdLogSingleEntry1(6,0x5a1);
    lVar2 = -0x3fffffe9;
    _WdLogGlobalForLineNumber = 0x5a1;
  }
  else {
    *puVar3 = 0;
    lVar2 = 0;
  }
  return lVar2;
}



===== KmdDodDdiAddDevice @ 14000dc50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl KmdDodDdiAddDevice(struct _DEVICE_OBJECT * __ptr64,void * __ptr64 * __ptr64) */

long __cdecl KmdDodDdiAddDevice(_DEVICE_OBJECT *param_1,void **param_2)

{
  int iVar1;
  long lVar2;
  INDIRECT_DEVICE *pIVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined1 auStack_98 [32];
  undefined4 *local_78;
  undefined8 *local_70;
  int *local_68;
  int *local_60;
  int local_58;
  int local_54;
  undefined4 local_50 [2];
  undefined8 local_48 [2];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  if ((param_1 == (_DEVICE_OBJECT *)0x0) || (param_2 == (void **)0x0)) {
    return -0x3ffffff3;
  }
  *param_2 = (void *)0x0;
  local_60 = &local_58;
  local_58 = 0;
  local_54 = 0;
  local_48[0] = 0;
  local_50[0] = 0;
  local_68 = &local_54;
  local_70 = local_48;
  local_78 = (undefined4 *)CONCAT44(local_78._4_4_,8);
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = IoGetDevicePropertyData(0,&DEVPKEY_Device_TerminalLuid,0,0);
  if (((iVar1 < 0) || (local_58 != 0x1003)) || (local_54 != 8)) {
LAB_14000dde1:
    pIVar3 = (INDIRECT_DEVICE *)ExAllocatePool2(0x40,0x4c0,0x4b646449);
    if (pIVar3 != (INDIRECT_DEVICE *)0x0) {
      local_78 = &local_38;
      local_38 = (undefined4)local_28;
      uStack_34 = local_28._4_4_;
      uStack_30 = (undefined4)uStack_20;
      uStack_2c = uStack_20._4_4_;
      pvVar4 = (void *)INDIRECT_DEVICE::INDIRECT_DEVICE(pIVar3,param_1,local_48[0],local_50[0]);
      if (pvVar4 != (void *)0x0) {
        *param_2 = pvVar4;
        return 0;
      }
    }
    WdLogSingleEntry1(6,0xc5);
    lVar2 = -0x3fffffe9;
    _WdLogGlobalForLineNumber = 0xc5;
  }
  else {
    local_60 = &local_58;
    local_68 = &local_54;
    local_70 = (undefined8 *)local_50;
    local_78._0_4_ = 4;
    iVar1 = IoGetDevicePropertyData(param_1,&DEVPKEY_Device_SessionId,0,0);
    if (((iVar1 < 0) || (local_58 != 7)) || (local_54 != 4)) {
      uVar5 = 0xac;
      WdLogSingleEntry1(2,0xac);
    }
    else {
      local_60 = &local_58;
      local_68 = &local_54;
      local_70 = &local_28;
      local_78 = (undefined4 *)CONCAT44(local_78._4_4_,0x10);
      iVar1 = IoGetDevicePropertyData(param_1,&DEVPKEY_Device_ActivityId,0,0);
      if (((-1 < iVar1) && (local_58 == 0x1003)) && (local_54 == 0x10)) goto LAB_14000dde1;
      uVar5 = 0xbc;
      WdLogSingleEntry1(2,0xbc);
    }
    lVar2 = -0x3fffffff;
    _WdLogGlobalForLineNumber = uVar5;
  }
  return lVar2;
}



===== KmdDodDdiRemoveDevice @ 14000de90 =====

/* long __cdecl KmdDodDdiRemoveDevice(void * __ptr64) */

long __cdecl KmdDodDdiRemoveDevice(void *param_1)

{
  long lVar1;
  
  if ((param_1 == (void *)0x0) || (*(int *)param_1 != 0x4b646449)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    INDIRECT_DEVICE::~INDIRECT_DEVICE(param_1);
    ExFreePoolWithTag(param_1,0);
    lVar1 = 0;
  }
  return lVar1;
}



===== KmdDodDdiUnload @ 14000dee0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl KmdDodDdiUnload(void) */

void __cdecl KmdDodDdiUnload(void)

{
  if (DAT_1400083d0 != 0) {
    ExFreePoolWithTag(DAT_1400083d0,0);
    _DAT_1400083c8 = 0;
    DAT_1400083d0 = 0;
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
  McGenEventUnregister_EtwUnregister();
  return;
}



===== KmdDodInterfaceReferenceNop @ 14000df60 =====

/* void __cdecl KmdDodInterfaceReferenceNop(void * __ptr64) */

void __cdecl KmdDodInterfaceReferenceNop(void *param_1)

{
  return;
}



===== PostStartDevice @ 14000df6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl INDIRECT_DEVICE::PostStartDevice(long) __ptr64 */

long __thiscall INDIRECT_DEVICE::PostStartDevice(INDIRECT_DEVICE *this,long param_1)

{
  long lVar1;
  undefined1 auStackY_88 [32];
  undefined4 local_48;
  long local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (*(int *)(this + 4) == 2) {
    lVar1 = 0;
  }
  else {
    local_40 = *(undefined8 *)(this + 0x2c);
    local_30 = *(undefined8 *)(this + 0x340);
    uStack_28 = *(undefined8 *)(this + 0x348);
    local_38 = *(undefined8 *)(this + 0x334);
    local_20 = *(undefined4 *)(this + 0x33c);
    local_48 = 4;
    local_44 = param_1;
    lVar1 = SendMessageToUserMode
                      (this,0x2c,&local_48,0x10,this + 0x308,
                       <lambda_d3f6885b853900ca9f7e79fb41d94694>::<lambda_invoker_cdecl>,this);
  }
  return lVar1;
}



===== PostStartDeviceCallback @ 14000e014 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl INDIRECT_DEVICE::PostStartDeviceCallback(struct _IO_STATUS_BLOCK * __ptr64)
   __ptr64 */

void __thiscall
INDIRECT_DEVICE::PostStartDeviceCallback(INDIRECT_DEVICE *this,_IO_STATUS_BLOCK *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 local_res8;
  undefined8 local_res10;
  ulonglong in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffd0 >> 0x20);
  ExEnterCriticalRegionAndAcquireResourceExclusive(this + 0x350);
  if (*(int *)param_1 < 0) {
    WdLogSingleEntry1(2,(longlong)*(int *)param_1);
    _WdLogGlobalForLineNumber = 0x1f0;
  }
  else if (this[9] != (INDIRECT_DEVICE)0x0) {
    iVar2 = PsLookupProcessByProcessId(*(undefined4 *)(this + 0x308),this + 0x300);
    if (iVar2 < 0) {
      WdLogSingleEntry2(2,*(undefined4 *)(this + 0x308),(longlong)iVar2);
      _WdLogGlobalForLineNumber = 0x1f9;
    }
    else {
      local_res8 = 0;
      iVar2 = ObDuplicateObject(*(undefined8 *)(this + 0x300),*(undefined8 *)(this + 0x310),0,
                                &local_res8,in_stack_ffffffffffffffc8 & 0xffffffff00000000,
                                CONCAT44(uVar3,0x200),2,0);
      if (iVar2 < 0) {
        WdLogSingleEntry1(2,(longlong)iVar2);
        _WdLogGlobalForLineNumber = 0x202;
      }
      else {
        local_res10 = 0;
        iVar2 = ObReferenceObjectByHandle
                          (local_res8,3,*(undefined8 *)ExEventObjectType_exref,0,&local_res10,0);
        uVar1 = local_res10;
        if (iVar2 < 0) {
          ObCloseHandle(local_res8);
          WdLogSingleEntry1(2,(longlong)iVar2);
          _WdLogGlobalForLineNumber = 0x20c;
        }
        else {
          this[0x2f8] = (INDIRECT_DEVICE)0x1;
          KeSetEvent(local_res10,0,0);
          ObfDereferenceObject(uVar1);
          ObCloseHandle(local_res8,0);
          iVar2 = IoSetDeviceInterfaceState(this + 0x3c0,1);
          if (iVar2 < 0) {
            WdLogSingleEntry1(1,(longlong)iVar2);
            _WdLogGlobalForLineNumber = 0x21e;
          }
        }
      }
    }
  }
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return;
}



===== PresentDisplayOnly @ 14000e22c =====

/* public: long __cdecl INDIRECT_DEVICE::PresentDisplayOnly(struct _DXGKARG_PRESENT_DISPLAYONLY
   const * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::PresentDisplayOnly(INDIRECT_DEVICE *this,_DXGKARG_PRESENT_DISPLAYONLY *param_1)

{
  if ((((param_1 == (_DXGKARG_PRESENT_DISPLAYONLY *)0x0) ||
       (*(uint *)(this + 0x31c) <= *(uint *)param_1)) || (*(int *)(param_1 + 0x10) != 4)) ||
     (((*(int *)(param_1 + 0x1c) != 0 && (*(longlong *)(param_1 + 0x20) == 0)) ||
      ((*(int *)(param_1 + 0x28) != 0 && (*(longlong *)(param_1 + 0x30) == 0)))))) {
    return -0x3ffffff3;
  }
  return 0;
}



===== QueryAdapterInfo @ 14000e270 =====

/* public: long __cdecl INDIRECT_DEVICE::QueryAdapterInfo(struct _DXGKARG_QUERYADAPTERINFO const *
   __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::QueryAdapterInfo(INDIRECT_DEVICE *this,_DXGKARG_QUERYADAPTERINFO *param_1)

{
  uint *puVar1;
  undefined8 *_Dst;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  long lVar5;
  
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  lVar5 = 0;
  if (param_1 != (_DXGKARG_QUERYADAPTERINFO *)0x0) {
    iVar2 = *(int *)param_1;
    if (iVar2 == 1) {
      if (0x24f < *(uint *)(param_1 + 0x20)) {
        _Dst = *(undefined8 **)(param_1 + 0x18);
        memset(_Dst,0,(ulonglong)*(uint *)(param_1 + 0x20));
        *_Dst = 0xffffffffffffffff;
        *(undefined4 *)(_Dst + 0x2a) = 0x3200;
        *(undefined4 *)(_Dst + 1) = 0;
        _Dst[2] = 0;
        *(undefined4 *)(_Dst + 5) = 0;
        _Dst[8] = 0;
        _Dst[9] = 0;
        iVar2 = (-(uint)(this[0x32b] != (INDIRECT_DEVICE)0x0) & 0x100) + 0x100;
        *(int *)(_Dst + 3) = iVar2;
        *(int *)((longlong)_Dst + 0x1c) = iVar2;
        *(uint *)(_Dst + 4) = *(uint *)(_Dst + 4) | 7;
        *(undefined4 *)((longlong)_Dst + 0x24) = 0;
        uVar3 = (uint)(this[0x328] != (INDIRECT_DEVICE)0x0) | *(uint *)(_Dst + 6) & 0xfffffffe;
        *(uint *)(_Dst + 6) = uVar3;
        if (this[0x32f] != (INDIRECT_DEVICE)0x0) {
          *(uint *)(_Dst + 6) = uVar3 | 0x1c;
        }
        *(undefined4 *)((longlong)_Dst + 0x2c) = 0;
        _Dst[7] = 0;
        *(undefined4 *)((longlong)_Dst + 0x34) = 0;
        goto LAB_14000e430;
      }
    }
    else if (iVar2 == 0x10) {
      if (3 < *(uint *)(param_1 + 0x20)) {
        puVar1 = *(uint **)(param_1 + 0x18);
        memset(puVar1,0,(ulonglong)*(uint *)(param_1 + 0x20));
        uVar3 = *puVar1;
        *puVar1 = uVar3 | 2;
        if ((this[0x32f] != (INDIRECT_DEVICE)0x0) &&
           (*puVar1 = uVar3 | 6, this[0x32b] == (INDIRECT_DEVICE)0x0)) {
          *puVar1 = uVar3 | 0x16;
        }
        goto LAB_14000e430;
      }
    }
    else {
      if (iVar2 != 0x14) {
        lVar5 = -0x3fffff45;
        goto LAB_14000e430;
      }
      if ((0xf < *(uint *)(param_1 + 0x20)) && (3 < *(uint *)(param_1 + 0x10))) {
        puVar1 = *(uint **)(param_1 + 0x18);
        if (**(int **)(param_1 + 8) - 0x100U < *(uint *)(this + 0x31c)) {
          lVar4 = (ulonglong)(**(int **)(param_1 + 8) - 0x100U) * 0x130 +
                  *(longlong *)(this + 0x2c8);
          uVar3 = *(uint *)(lVar4 + 0xd0);
          if (uVar3 == 0) {
            lVar5 = -0x3fe2ffff;
          }
          else if (*puVar1 < uVar3) {
            *puVar1 = uVar3;
            lVar5 = -0x3fffffdd;
          }
          else {
            memmove(*(void **)(puVar1 + 2),*(void **)(lVar4 + 200),(ulonglong)uVar3);
          }
          goto LAB_14000e430;
        }
      }
    }
  }
  lVar5 = -0x3ffffff3;
LAB_14000e430:
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar5;
}



===== QueryChildRelations @ 14000e460 =====

/* public: long __cdecl INDIRECT_DEVICE::QueryChildRelations(struct _DXGK_CHILD_DESCRIPTOR *
   __ptr64,unsigned long) __ptr64 */

long __thiscall
INDIRECT_DEVICE::QueryChildRelations
          (INDIRECT_DEVICE *this,_DXGK_CHILD_DESCRIPTOR *param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  ExEnterCriticalRegionAndAcquireResourceShared();
  if ((param_1 == (_DXGK_CHILD_DESCRIPTOR *)0x0) ||
     ((ulonglong)param_2 < (ulonglong)*(uint *)(this + 0x31c) * 0x1c)) {
    ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
    lVar1 = -0x3ffffff3;
  }
  else {
    uVar3 = 0;
    if (*(uint *)(this + 0x31c) != 0) {
      do {
        iVar2 = (int)uVar3;
        lVar4 = uVar3 * 0x1c;
        *(undefined4 *)(param_1 + lVar4 + 0x14) = 0;
        *(undefined4 *)(param_1 + lVar4) = 1;
        *(int *)(param_1 + lVar4 + 0x18) = iVar2 + 0x100;
        param_1[lVar4 + 0xc] = (_DXGK_CHILD_DESCRIPTOR)0x0;
        *(undefined4 *)(param_1 + lVar4 + 8) = 1;
        if ((*(int *)(this + 4) == 0) && (iVar2 == 0)) {
          *(undefined4 *)(param_1 + lVar4 + 4) = 0xf;
        }
        else {
          *(uint *)(param_1 + lVar4 + 4) = 0x11 - (uint)(*(int *)(this + 4) != 2);
        }
        uVar3 = (ulonglong)(iVar2 + 1U);
        *(undefined4 *)(param_1 + lVar4 + 0x10) = 4;
      } while (iVar2 + 1U < *(uint *)(this + 0x31c));
    }
    ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
    lVar1 = 0;
  }
  return lVar1;
}



===== QueryChildStatus @ 14000e554 =====

/* public: long __cdecl INDIRECT_DEVICE::QueryChildStatus(struct _DXGK_CHILD_STATUS *
   __ptr64,unsigned char) __ptr64 */

long __thiscall
INDIRECT_DEVICE::QueryChildStatus(INDIRECT_DEVICE *this,_DXGK_CHILD_STATUS *param_1,uchar param_2)

{
  uint uVar1;
  long lVar2;
  
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  lVar2 = 0;
  if ((param_1 == (_DXGK_CHILD_STATUS *)0x0) ||
     (uVar1 = *(int *)(param_1 + 4) - 0x100, *(uint *)(this + 0x31c) <= uVar1)) {
    lVar2 = -0x3ffffff3;
  }
  else if (*(int *)param_1 == 3) {
    param_1[8] = *(_DXGK_CHILD_STATUS *)
                  ((ulonglong)uVar1 * 0x130 + 0x90 + *(longlong *)(this + 0x2c8));
    *(undefined4 *)(param_1 + 0xc) =
         *(undefined4 *)((ulonglong)uVar1 * 0x130 + 0x94 + *(longlong *)(this + 0x2c8));
  }
  else if (*(int *)param_1 == 1) {
    param_1[8] = *(_DXGK_CHILD_STATUS *)
                  ((ulonglong)uVar1 * 0x130 + 0x90 + *(longlong *)(this + 0x2c8));
  }
  else {
    lVar2 = -0x3fffff45;
  }
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar2;
}



===== QueryDeviceDescriptor @ 14000e62c =====

/* public: long __cdecl INDIRECT_DEVICE::QueryDeviceDescriptor(unsigned long,struct
   _DXGK_DEVICE_DESCRIPTOR * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::QueryDeviceDescriptor
          (INDIRECT_DEVICE *this,ulong param_1,_DXGK_DEVICE_DESCRIPTOR *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  longlong lVar5;
  
  lVar4 = 0;
  if ((param_2 == (_DXGK_DEVICE_DESCRIPTOR *)0x0) || (*(longlong *)(param_2 + 8) == 0)) {
    lVar4 = -0x3ffffff3;
  }
  else {
    ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
    if (param_1 - 0x100 < *(uint *)(this + 0x31c)) {
      lVar5 = (ulonglong)(param_1 - 0x100) * 0x130 + *(longlong *)(this + 0x2c8);
      if (*(int *)(lVar5 + 0x90) == 0) {
        lVar4 = -0x3fffff45;
      }
      else {
        uVar1 = *(uint *)(lVar5 + 0xb8);
        if (uVar1 == 0) {
          lVar4 = -0x3fe2ffff;
        }
        else {
          uVar2 = *(uint *)param_2;
          if (uVar2 < uVar1) {
            uVar3 = uVar1 - uVar2;
            if (*(uint *)(param_2 + 4) <= uVar1 - uVar2) {
              uVar3 = *(uint *)(param_2 + 4);
            }
            memmove(*(void **)(param_2 + 8),(void *)((ulonglong)uVar2 + *(longlong *)(lVar5 + 0xb0))
                    ,(ulonglong)uVar3);
          }
          else {
            lVar4 = -0x3fe2fff8;
          }
        }
      }
    }
    else {
      lVar4 = -0x3ffffff3;
    }
    ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  }
  return lVar4;
}



===== QueryInterface @ 14000e724 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::QueryInterface(struct _QUERY_INTERFACE * __ptr64) __ptr64
    */

long __thiscall INDIRECT_DEVICE::QueryInterface(INDIRECT_DEVICE *this,_QUERY_INTERFACE *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined8 uVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined8 uVar15;
  undefined *puVar16;
  undefined *puVar17;
  long lVar18;
  ulonglong uVar19;
  
  puVar17 = PTR_KmdDodInterfaceReferenceNop_1400081b8;
  puVar16 = PTR_KmdDodInterfaceReferenceNop_1400081b0;
  uVar15 = uRam00000001400081a8;
  puVar14 = PTR_KmdDodInterfaceReferenceNop_140008148;
  puVar13 = PTR_KmdDodInterfaceReferenceNop_140008140;
  uVar12 = uRam0000000140008138;
  puVar11 = PTR_KmdDodInterfaceReferenceNop_1400080d8;
  puVar10 = PTR_KmdDodInterfaceReferenceNop_1400080d0;
  uVar9 = uRam00000001400080c8;
  puVar7 = PTR_KmdDodInterfaceReferenceNop_1400080a0;
  puVar6 = PTR_KmdDodInterfaceReferenceNop_140008098;
  uVar8 = uRam0000000140008090;
  puVar5 = PTR_KmdDodInterfaceReferenceNop_140008018;
  puVar4 = PTR_KmdDodInterfaceReferenceNop_140008010;
  uVar3 = uRam0000000140008008;
  if ((param_1 == (_QUERY_INTERFACE *)0x0) ||
     (plVar1 = *(longlong **)param_1, plVar1 == (longlong *)0x0)) {
    lVar18 = -0x3ffffff3;
  }
  else {
    if ((((*plVar1 == 0x48cb22afaf03f190) && (plVar1[1] == 0x751a2768eb7bb94)) &&
        (0x3f < *(ushort *)(param_1 + 8))) && (*(short *)(param_1 + 10) == DAT_1400081a2)) {
      puVar2 = *(undefined8 **)(param_1 + 0x10);
      *puVar2 = CONCAT44(uRam00000001400081a4,CONCAT22(DAT_1400081a2,_DAT_1400081a0));
      puVar2[1] = uVar15;
      puVar5 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_1400081c8;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_1400081c0;
      puVar2[2] = puVar16;
      puVar2[3] = puVar17;
      puVar7 = PTR_KmdDodMiraDisplayDestroyContext_1400081d8;
      puVar6 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_1400081d0;
      puVar2[4] = puVar4;
      puVar2[5] = puVar5;
      puVar2[6] = puVar6;
      puVar2[7] = puVar7;
    }
    else if (((*plVar1 == 0x4b3d0fd26ba41a33) && (plVar1[1] == -0x6c895333b83bd844)) &&
            ((0x6f < *(ushort *)(param_1 + 8) && (*(short *)(param_1 + 10) == DAT_140008132)))) {
      puVar2 = *(undefined8 **)(param_1 + 0x10);
      *puVar2 = CONCAT44(uRam0000000140008134,CONCAT22(DAT_140008132,_DAT_140008130));
      puVar2[1] = uVar12;
      puVar5 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008158;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008150;
      puVar2[2] = puVar13;
      puVar2[3] = puVar14;
      puVar7 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008168;
      puVar6 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008160;
      puVar2[4] = puVar4;
      puVar2[5] = puVar5;
      puVar5 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008178;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008170;
      puVar2[6] = puVar6;
      puVar2[7] = puVar7;
      puVar7 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008188;
      puVar6 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008180;
      puVar2[8] = puVar4;
      puVar2[9] = puVar5;
      puVar5 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008198;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008190;
      puVar2[10] = puVar6;
      puVar2[0xb] = puVar7;
      puVar2[0xc] = puVar4;
      puVar2[0xd] = puVar5;
    }
    else if (((*plVar1 == 0x4be46b4ebf4672de) && (plVar1[1] == 0x99ca41ea96825a3)) &&
            ((*(short *)(param_1 + 8) == 0x68 && (*(short *)(param_1 + 10) == DAT_1400080c2)))) {
      puVar2 = *(undefined8 **)(param_1 + 0x10);
      *puVar2 = CONCAT44(uRam00000001400080c4,CONCAT22(DAT_1400080c2,_DAT_1400080c0));
      puVar2[1] = uVar9;
      puVar5 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_1400080e8;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_1400080e0;
      puVar2[2] = puVar10;
      puVar2[3] = puVar11;
      puVar7 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_1400080f8;
      puVar6 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_1400080f0;
      puVar2[4] = puVar4;
      puVar2[5] = puVar5;
      puVar5 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008108;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008100;
      puVar2[6] = puVar6;
      puVar2[7] = puVar7;
      puVar7 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008118;
      puVar6 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008110;
      puVar2[8] = puVar4;
      puVar2[9] = puVar5;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008120;
      puVar2[10] = puVar6;
      puVar2[0xb] = puVar7;
      puVar2[0xc] = puVar4;
    }
    else if ((((*plVar1 == 0x4495dddb2564aa4f) && (plVar1[1] == -0x289cbe572b95684c)) &&
             (*(short *)(param_1 + 8) == 0x30)) && (*(short *)(param_1 + 10) == DAT_14000808a)) {
      puVar2 = *(undefined8 **)(param_1 + 0x10);
      *puVar2 = CONCAT44(uRam000000014000808c,CONCAT22(DAT_14000808a,_DAT_140008088));
      puVar2[1] = uVar8;
      puVar5 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_1400080b0;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_1400080a8;
      puVar2[2] = puVar6;
      puVar2[3] = puVar7;
      puVar2[4] = puVar4;
      puVar2[5] = puVar5;
    }
    else if (((*plVar1 == 0x4f5a31eccec9ab31) && (plVar1[1] == -0x364e897cb8549779)) &&
            ((0x4f < *(ushort *)(param_1 + 8) && (*(short *)(param_1 + 10) == DAT_140008002)))) {
      puVar2 = *(undefined8 **)(param_1 + 0x10);
      *puVar2 = CONCAT44(uRam0000000140008004,CONCAT22(DAT_140008002,_DAT_140008000));
      puVar2[1] = uVar3;
      puVar7 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008028;
      puVar6 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008020;
      puVar2[2] = puVar4;
      puVar2[3] = puVar5;
      puVar5 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008038;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008030;
      puVar2[4] = puVar6;
      puVar2[5] = puVar7;
      puVar7 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008048;
      puVar6 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008040;
      puVar2[6] = puVar4;
      puVar2[7] = puVar5;
      puVar2[8] = puVar6;
      puVar2[9] = puVar7;
    }
    else {
      uVar19 = Feature_IdAtomicI2C__private_IsEnabledDeviceUsageNoInline();
      puVar5 = PTR_KmdDodInterfaceReferenceNop_140008068;
      puVar4 = PTR_KmdDodInterfaceReferenceNop_140008060;
      uVar3 = uRam0000000140008058;
      if ((((int)uVar19 == 0) || (**(longlong **)param_1 != 0x4876067115cca904)) ||
         (((*(longlong **)param_1)[1] != 0x7a887dd802e31394 ||
          ((*(short *)(param_1 + 8) != 0x38 || (*(short *)(param_1 + 10) != DAT_140008052)))))) {
        return -0x3fffff45;
      }
      puVar2 = *(undefined8 **)(param_1 + 0x10);
      *puVar2 = CONCAT44(uRam0000000140008054,CONCAT22(DAT_140008052,_DAT_140008050));
      puVar2[1] = uVar3;
      puVar7 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008078;
      puVar6 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008070;
      puVar2[2] = puVar4;
      puVar2[3] = puVar5;
      puVar4 = PTR_CallWithVerify<&VerifyAdapter,_1073741811>_140008080;
      puVar2[4] = puVar6;
      puVar2[5] = puVar7;
      puVar2[6] = puVar4;
    }
    *(INDIRECT_DEVICE **)(*(longlong *)(param_1 + 0x10) + 8) = this;
    lVar18 = 0;
  }
  return lVar18;
}



===== SetPalette @ 14000ea0c =====

/* public: long __cdecl INDIRECT_DEVICE::SetPalette(struct _DXGKARG_SETPALETTE const * __ptr64)
   __ptr64 */

long __thiscall INDIRECT_DEVICE::SetPalette(INDIRECT_DEVICE *this,_DXGKARG_SETPALETTE *param_1)

{
  return (-(uint)(param_1 != (_DXGKARG_SETPALETTE *)0x0) & 0xae) + 0xc000000d;
}



===== SetPowerState @ 14000ea24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl INDIRECT_DEVICE::SetPowerState(unsigned long,enum _DEVICE_POWER_STATE,enum
   POWER_ACTION) __ptr64 */

long __thiscall
INDIRECT_DEVICE::SetPowerState
          (INDIRECT_DEVICE *this,ulong param_1,_DEVICE_POWER_STATE param_2,POWER_ACTION param_3)

{
  long lVar1;
  undefined1 auStackY_88 [32];
  undefined4 local_48;
  int local_44;
  _DEVICE_POWER_STATE local_40;
  POWER_ACTION local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  if (param_1 != 0xffffffff) {
    if (*(uint *)(this + 0x31c) <= param_1 - 0x100) {
      lVar1 = -0x3ffffff3;
      goto LAB_14000ead4;
    }
    if ((*(int *)(this + 4) == 1) ||
       ((this[0x2d8] != (INDIRECT_DEVICE)0x0 && (this[0x2d9] != (INDIRECT_DEVICE)0x0)))) {
      local_44 = param_1 - 0x200;
      local_48 = 0;
      local_40 = param_2;
      local_3c = param_3;
      lVar1 = SendMessageToUserMode
                        (this,0x10,&local_48,0,(void *)0x0,
                         (_func_void_void_ptr__IO_STATUS_BLOCK_ptr *)0x0,(void *)0x0);
      if (lVar1 < 0) goto LAB_14000ead4;
    }
  }
  lVar1 = 0;
LAB_14000ead4:
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar1;
}



===== SetPreStartPrivateData @ 14000eb0c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::SetPreStartPrivateData(unsigned long,void const * __ptr64)
   __ptr64 */

long __thiscall
INDIRECT_DEVICE::SetPreStartPrivateData(INDIRECT_DEVICE *this,ulong param_1,void *param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  char local_res10 [8];
  undefined1 local_res20 [8];
  int local_28;
  int local_24 [3];
  
  if (param_1 != 600) {
    return 0;
  }
  ExEnterCriticalRegionAndAcquireResourceExclusive();
  if (*(int *)((longlong)param_2 + 0x22c) == 0) {
    if ((*(int *)(this + 0x334) == 0) && (*(int *)(this + 0x338) == 0)) goto LAB_14000ebc5;
    uVar3 = 0xfa;
    WdLogSingleEntry1(2,0xfa);
  }
  else {
    if ((*(int *)(this + 0x334) != 0) || (*(int *)(this + 0x338) != 0)) {
LAB_14000ebc5:
      if (*(int *)((longlong)param_2 + 0x208) == 0) {
        if (*(int *)((longlong)param_2 + 0x20c) == 0) {
          *(undefined4 *)(this + 4) = 1;
        }
        else {
          *(undefined4 *)(this + 4) = 2;
          local_res20[0] = 0;
          local_24[0] = 0;
          local_28 = 0;
          iVar1 = IoGetDevicePropertyData
                            (*(undefined8 *)(this + 0x10),&DEVPKEY_Gpu_IddVirtualMonitorDevice,0,0,1
                             ,local_res20,local_24,&local_28);
          if (((iVar1 < 0) || (local_28 != 0x11)) || (local_24[0] != 1)) {
            uVar3 = 0x116;
            WdLogSingleEntry1(2,0x116);
            goto LAB_14000eb88;
          }
          local_res10[0] = '\0';
          iVar1 = IoGetDevicePropertyData
                            (*(undefined8 *)(this + 0x10),
                             &DEVPKEY_Gpu_IddVirtualMonitorDeviceLowRights,0,0,1,local_res10,
                             local_24,&local_28);
          if (((-1 < iVar1) && (local_28 == 0x11)) && (local_24[0] == 1)) {
            this[8] = (INDIRECT_DEVICE)(local_res10[0] != '\0');
          }
        }
      }
      else {
        *(undefined4 *)(this + 4) = 0;
      }
      if (*(int *)(this + 4) == 2) {
        *(undefined4 *)(this + 0x3b8) = 0;
      }
      else {
        *(uint *)(this + 0x3b8) = (*(int *)((longlong)param_2 + 0x210) != 0) + 1;
      }
      iVar1 = *(int *)((longlong)param_2 + 0x248);
      if (iVar1 - 1U < 0x10) {
        *(int *)(this + 0x31c) = iVar1;
        this[0x318] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x218) != 0);
        this[0x319] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x214) != 0);
        this[0x31a] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x21c) != 0);
        this[0x31b] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x220) != 0);
        this[0x328] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x224) != 0);
        this[0x329] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x228) != 0);
        *(undefined8 *)(this + 800) = *(undefined8 *)((longlong)param_2 + 0x250);
        this[0x32a] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x234) != 0);
        this[0x32b] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x22c) != 0);
        this[0x32c] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x238) != 0);
        this[0x32d] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x23c) != 0);
        this[0x32e] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x230) != 0);
        this[0x32f] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x240) != 0);
        uVar2 = Feature_IdAtomicI2C__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar2 != 0) {
          this[0x330] = (INDIRECT_DEVICE)(*(int *)((longlong)param_2 + 0x244) != 0);
        }
        ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
        return 0;
      }
      WdLogSingleEntry1(2,iVar1);
      _WdLogGlobalForLineNumber = 0x142;
      goto LAB_14000eb8e;
    }
    uVar3 = 0xf5;
    WdLogSingleEntry1(2,0xf5);
  }
LAB_14000eb88:
  _WdLogGlobalForLineNumber = uVar3;
LAB_14000eb8e:
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return -0x3ffffff3;
}



===== StartDevice @ 14000ee5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::StartDevice(struct _DXGK_START_INFO * __ptr64,struct
   _DXGKRNL_INTERFACE * __ptr64,unsigned long * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::StartDevice
          (INDIRECT_DEVICE *this,_DXGK_START_INFO *param_1,_DXGKRNL_INTERFACE *param_2,
          ulong *param_3,ulong *param_4)

{
  longlong *plVar1;
  INDIRECT_DEVICE *pIVar2;
  INDIRECT_DEVICE *pIVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  uint uVar10;
  int iVar11;
  ulonglong uVar12;
  ulonglong *puVar13;
  INDIRECT_DEVICE *pIVar14;
  longlong lVar15;
  undefined4 *puVar16;
  uint uVar17;
  ulonglong uVar18;
  longlong lVar19;
  _DXGKRNL_INTERFACE *p_Var20;
  undefined4 uVar21;
  VIDPN_SOURCE_INFO *pVVar22;
  VIDPN_TARGET_INFO *pVVar23;
  size_t sVar24;
  VIDPN_SOURCE_INFO *pVVar25;
  VIDPN_TARGET_INFO *pVVar26;
  undefined8 local_res10 [2];
  ulong *local_res20;
  ulonglong in_stack_ffffffffffffffa8;
  undefined8 local_48 [2];
  
  if ((((param_1 == (_DXGK_START_INFO *)0x0) || (param_2 == (_DXGKRNL_INTERFACE *)0x0)) ||
      (param_3 == (ulong *)0x0)) || (param_4 == (ulong *)0x0)) {
    iVar11 = -0x3ffffff3;
  }
  else {
    pIVar2 = this + 0x350;
    local_res20 = param_3;
    ExEnterCriticalRegionAndAcquireResourceExclusive(pIVar2);
    *(undefined2 *)(this + 0x27a) = 1;
    *(undefined2 *)(this + 0x278) = 0x50;
    iVar11 = (**(code **)(param_2 + 0x38))(*(undefined8 *)(param_2 + 8),6);
    if (iVar11 < 0) {
      WdLogSingleEntry1(2,(longlong)iVar11);
      _WdLogGlobalForLineNumber = 0x176;
    }
    else {
      uVar18 = CONCAT44(0,*(uint *)(this + 0x31c));
      auVar4._8_8_ = 0;
      auVar4._0_8_ = uVar18;
      uVar12 = SUB168(ZEXT816(0xf0) * auVar4,0);
      if (SUB168(ZEXT816(0xf0) * auVar4,8) != 0) {
        uVar12 = 0xffffffffffffffff;
      }
      sVar24 = uVar12 + 8;
      if (0xfffffffffffffff7 < uVar12) {
        sVar24 = 0xffffffffffffffff;
      }
      puVar13 = (ulonglong *)ExAllocatePool2(0x40,sVar24,0x4b646449);
      if (puVar13 == (ulonglong *)0x0) {
        pVVar22 = (VIDPN_SOURCE_INFO *)0x0;
      }
      else {
        memset(puVar13,0,sVar24);
        *puVar13 = uVar18;
        pVVar22 = (VIDPN_SOURCE_INFO *)(puVar13 + 1);
        pVVar25 = pVVar22;
        for (; uVar18 != 0; uVar18 = uVar18 - 1) {
          VIDPN_SOURCE_INFO::VIDPN_SOURCE_INFO(pVVar25);
          pVVar25 = pVVar25 + 0xf0;
        }
      }
      lVar15 = *(longlong *)(this + 0x2d0);
      if (lVar15 != 0) {
        plVar1 = (longlong *)(lVar15 + -8);
        lVar19 = *plVar1;
        pVVar25 = (VIDPN_SOURCE_INFO *)(lVar19 * 0xf0 + lVar15);
        for (; lVar19 != 0; lVar19 = lVar19 + -1) {
          pVVar25 = pVVar25 + -0xf0;
          VIDPN_SOURCE_INFO::~VIDPN_SOURCE_INFO(pVVar25);
        }
        if (plVar1 != (longlong *)0x0) {
          ExFreePoolWithTag(plVar1,0);
        }
      }
      local_res10[0] = 0;
      *(VIDPN_SOURCE_INFO **)(this + 0x2d0) = pVVar22;
      AUTO_PTR_DETAILS::
      AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_>::
      ~AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_>
                ((AutoPtrImpl<VIDPN_SOURCE_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_SOURCE_INFO_[0]>_>
                  *)local_res10);
      uVar18 = CONCAT44(0,*(uint *)(this + 0x31c));
      auVar5._8_8_ = 0;
      auVar5._0_8_ = uVar18;
      uVar12 = SUB168(ZEXT816(0x130) * auVar5,0);
      if (SUB168(ZEXT816(0x130) * auVar5,8) != 0) {
        uVar12 = 0xffffffffffffffff;
      }
      sVar24 = uVar12 + 8;
      if (0xfffffffffffffff7 < uVar12) {
        sVar24 = 0xffffffffffffffff;
      }
      puVar13 = (ulonglong *)ExAllocatePool2(0x40,sVar24,0x4b646449);
      if (puVar13 == (ulonglong *)0x0) {
        pVVar23 = (VIDPN_TARGET_INFO *)0x0;
      }
      else {
        memset(puVar13,0,sVar24);
        *puVar13 = uVar18;
        pVVar23 = (VIDPN_TARGET_INFO *)(puVar13 + 1);
        pVVar26 = pVVar23;
        for (; uVar18 != 0; uVar18 = uVar18 - 1) {
          VIDPN_TARGET_INFO::VIDPN_TARGET_INFO(pVVar26);
          pVVar26 = pVVar26 + 0x130;
        }
      }
      lVar15 = *(longlong *)(this + 0x2c8);
      if (lVar15 != 0) {
        plVar1 = (longlong *)(lVar15 + -8);
        lVar19 = *plVar1;
        pVVar26 = (VIDPN_TARGET_INFO *)(lVar19 * 0x130 + lVar15);
        for (; lVar19 != 0; lVar19 = lVar19 + -1) {
          pVVar26 = pVVar26 + -0x130;
          VIDPN_TARGET_INFO::~VIDPN_TARGET_INFO(pVVar26);
        }
        if (plVar1 != (longlong *)0x0) {
          ExFreePoolWithTag(plVar1,0);
        }
      }
      *(VIDPN_TARGET_INFO **)(this + 0x2c8) = pVVar23;
      local_48[0] = 0;
      AUTO_PTR_DETAILS::
      AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_>::
      ~AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_>
                ((AutoPtrImpl<VIDPN_TARGET_INFO,AUTO_PTR_DETAILS::AutoDeleter<struct_VIDPN_TARGET_INFO_[0]>_>
                  *)local_48);
      if ((*(longlong *)(this + 0x2d0) == 0) || (*(longlong *)(this + 0x2c8) == 0)) {
        uVar21 = 0x17f;
        WdLogSingleEntry1(2,0x17f);
        iVar11 = -0x3fffffe9;
      }
      else {
        uVar17 = 0;
        uVar10 = 0;
        if (*(int *)(this + 0x31c) != 0) {
          do {
            lVar15 = (ulonglong)uVar17 * 0xf0 + *(longlong *)(this + 0x2d0);
            *(undefined4 *)(lVar15 + 4) = 0;
            *(undefined4 *)(lVar15 + 0x80) = 1;
            *(undefined8 *)(lVar15 + 0x88) = 0;
            *(undefined4 *)(lVar15 + 0x90) = 0;
            KeInitializeEvent(lVar15 + 0x98,1,0);
            uVar10 = *(uint *)(this + 0x31c);
            uVar17 = uVar17 + 1;
          } while (uVar17 < uVar10);
        }
        uVar17 = 0;
        if (uVar10 != 0) {
          do {
            uVar18 = (ulonglong)uVar17;
            uVar17 = uVar17 + 1;
            puVar16 = (undefined4 *)(uVar18 * 0x130 + *(longlong *)(this + 0x2c8));
            *puVar16 = 0xffffffff;
            *(undefined8 *)(puVar16 + 0x4a) = 0;
            *(undefined8 *)(puVar16 + 0x46) = 1;
            *(undefined8 *)(puVar16 + 0x48) = 0x50;
          } while (uVar17 < *(uint *)(this + 0x31c));
        }
        uVar21 = 0;
        ExInitializePagedLookasideList
                  (this + 0x400,0,0,0x200,0x28,0x4b646449,
                   in_stack_ffffffffffffffa8 & 0xffffffffffff0000);
        pIVar3 = this + 0x480;
        lVar15 = 4;
        *(INDIRECT_DEVICE **)(this + 0x488) = pIVar3;
        *(INDIRECT_DEVICE **)pIVar3 = pIVar3;
        uVar9 = *(undefined8 *)(param_1 + 8);
        *(undefined8 *)(this + 0x18) = *(undefined8 *)param_1;
        *(undefined8 *)(this + 0x20) = uVar9;
        *(undefined8 *)(this + 0x28) = *(undefined8 *)(param_1 + 0x10);
        *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x18);
        pIVar3 = this + 0x38;
        do {
          p_Var20 = param_2;
          pIVar14 = pIVar3;
          uVar9 = *(undefined8 *)(p_Var20 + 8);
          *(undefined8 *)pIVar14 = *(undefined8 *)p_Var20;
          *(undefined8 *)(pIVar14 + 8) = uVar9;
          uVar9 = *(undefined8 *)(p_Var20 + 0x18);
          *(undefined8 *)(pIVar14 + 0x10) = *(undefined8 *)(p_Var20 + 0x10);
          *(undefined8 *)(pIVar14 + 0x18) = uVar9;
          uVar9 = *(undefined8 *)(p_Var20 + 0x28);
          *(undefined8 *)(pIVar14 + 0x20) = *(undefined8 *)(p_Var20 + 0x20);
          *(undefined8 *)(pIVar14 + 0x28) = uVar9;
          uVar9 = *(undefined8 *)(p_Var20 + 0x38);
          *(undefined8 *)(pIVar14 + 0x30) = *(undefined8 *)(p_Var20 + 0x30);
          *(undefined8 *)(pIVar14 + 0x38) = uVar9;
          uVar9 = *(undefined8 *)(p_Var20 + 0x48);
          *(undefined8 *)(pIVar14 + 0x40) = *(undefined8 *)(p_Var20 + 0x40);
          *(undefined8 *)(pIVar14 + 0x48) = uVar9;
          uVar9 = *(undefined8 *)(p_Var20 + 0x58);
          *(undefined8 *)(pIVar14 + 0x50) = *(undefined8 *)(p_Var20 + 0x50);
          *(undefined8 *)(pIVar14 + 0x58) = uVar9;
          uVar9 = *(undefined8 *)(p_Var20 + 0x68);
          *(undefined8 *)(pIVar14 + 0x60) = *(undefined8 *)(p_Var20 + 0x60);
          *(undefined8 *)(pIVar14 + 0x68) = uVar9;
          uVar9 = *(undefined8 *)(p_Var20 + 0x78);
          *(undefined8 *)(pIVar14 + 0x70) = *(undefined8 *)(p_Var20 + 0x70);
          *(undefined8 *)(pIVar14 + 0x78) = uVar9;
          lVar15 = lVar15 + -1;
          pIVar3 = pIVar14 + 0x80;
          param_2 = p_Var20 + 0x80;
        } while (lVar15 != 0);
        uVar9 = *(undefined8 *)(p_Var20 + 0x88);
        *(undefined8 *)(pIVar14 + 0x80) = *(undefined8 *)(p_Var20 + 0x80);
        *(undefined8 *)(pIVar14 + 0x88) = uVar9;
        uVar9 = *(undefined8 *)(p_Var20 + 0x98);
        *(undefined8 *)(pIVar14 + 0x90) = *(undefined8 *)(p_Var20 + 0x90);
        *(undefined8 *)(pIVar14 + 0x98) = uVar9;
        uVar6 = *(undefined4 *)(p_Var20 + 0xa4);
        uVar7 = *(undefined4 *)(p_Var20 + 0xa8);
        uVar8 = *(undefined4 *)(p_Var20 + 0xac);
        *(undefined4 *)(pIVar14 + 0xa0) = *(undefined4 *)(p_Var20 + 0xa0);
        *(undefined4 *)(pIVar14 + 0xa4) = uVar6;
        *(undefined4 *)(pIVar14 + 0xa8) = uVar7;
        *(undefined4 *)(pIVar14 + 0xac) = uVar8;
        uVar6 = *(undefined4 *)(p_Var20 + 0xb4);
        uVar7 = *(undefined4 *)(p_Var20 + 0xb8);
        uVar8 = *(undefined4 *)(p_Var20 + 0xbc);
        *(undefined4 *)(pIVar14 + 0xb0) = *(undefined4 *)(p_Var20 + 0xb0);
        *(undefined4 *)(pIVar14 + 0xb4) = uVar6;
        *(undefined4 *)(pIVar14 + 0xb8) = uVar7;
        *(undefined4 *)(pIVar14 + 0xbc) = uVar8;
        *local_res20 = *(ulong *)(this + 0x31c);
        *param_4 = *(ulong *)(this + 0x31c);
        iVar11 = IoRegisterDeviceInterface
                           (*(undefined8 *)(this + 0x10),&GUID_INDIRECT_DISPLAY_DEVICE_ARRIVAL,0,
                            this + 0x3c0);
        if (iVar11 < 0) {
          uVar21 = 0x1b9;
          WdLogSingleEntry1(2,0x1b9);
        }
        else {
          iVar11 = IoSetDeviceInterfacePropertyData
                             (this + 0x3c0,&DEVPKEY_Device_TerminalLuid,0,0,CONCAT44(uVar21,0x1003),
                              8,this + 0x334);
          if (-1 < iVar11) {
            this[9] = (INDIRECT_DEVICE)0x1;
            ExReleaseResourceAndLeaveCriticalRegion(pIVar2);
            return 0;
          }
          uVar21 = 0x1c8;
          WdLogSingleEntry1(2,0x1c8);
        }
      }
      _WdLogGlobalForLineNumber = uVar21;
    }
    ExReleaseResourceAndLeaveCriticalRegion(pIVar2);
  }
  return iVar11;
}



===== StopDevice @ 14000f39c =====

/* public: long __cdecl INDIRECT_DEVICE::StopDevice(void) __ptr64 */

long __thiscall INDIRECT_DEVICE::StopDevice(INDIRECT_DEVICE *this)

{
  INDIRECT_DEVICE *pIVar1;
  INDIRECT_DEVICE *pIVar2;
  longlong lVar3;
  code *pcVar4;
  INDIRECT_DEVICE *this_00;
  VIDPN_TARGET_INFO *pVVar5;
  undefined1 *puVar6;
  VIDPN_SOURCE_INFO *pVVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  ExEnterCriticalRegionAndAcquireResourceExclusive(this + 0x350);
  if (*(longlong *)(this + 0x3c8) != 0) {
    pIVar1 = this + 0x3c0;
    IoSetDeviceInterfaceState(pIVar1,0);
    RtlFreeUnicodeString(pIVar1);
    *(undefined8 *)pIVar1 = 0;
    *(undefined8 *)(this + 0x3c8) = 0;
  }
  puVar6 = auStack_28;
  pIVar1 = this + 0x480;
  this_00 = this + 0x400;
  do {
    pIVar2 = *(INDIRECT_DEVICE **)pIVar1;
    if (pIVar2 == pIVar1) {
LAB_14000f449:
      *(undefined8 *)(puVar6 + -8) = 0x14000f453;
      ExDeletePagedLookasideList();
      uVar9 = 0;
      uVar8 = 0;
      if (*(int *)(this + 0x31c) != 0) {
        do {
          pVVar7 = (VIDPN_SOURCE_INFO *)(uVar9 * 0xf0 + *(longlong *)(this + 0x2d0));
          *(undefined8 *)(puVar6 + -8) = 0x14000f485;
          OnSourcePowerOff(this,pVVar7);
          *(undefined8 *)(pVVar7 + 0x38) = 0;
          this_00 = (INDIRECT_DEVICE *)(pVVar7 + 0x80);
          *(undefined8 *)(pVVar7 + 0x30) = 0;
          *(undefined8 *)(puVar6 + -8) = 0x14000f4a0;
          ExAcquireFastMutex(this_00);
          if (*(longlong *)(pVVar7 + 0x78) != 0) {
            *(undefined8 *)(puVar6 + -8) = 0x14000f4b5;
            ObfDereferenceObject();
            *(undefined8 *)(pVVar7 + 0x78) = 0;
          }
          lVar3 = *(longlong *)(pVVar7 + 0x68);
          if (lVar3 != 0) {
            *(undefined8 *)(puVar6 + -8) = 0x14000f4d1;
            ExFreePoolWithTag(lVar3,0);
          }
          *(undefined8 *)(pVVar7 + 0x68) = 0;
          *(undefined4 *)(pVVar7 + 0x70) = 0;
          *(undefined8 *)(pVVar7 + 0xb8) = 0;
          *(undefined8 *)(pVVar7 + 0xc0) = 0;
          *(undefined8 *)(pVVar7 + 200) = 0;
          *(undefined8 *)(pVVar7 + 0xd0) = 0;
          *(undefined8 *)(pVVar7 + 0xd8) = 0;
          *(undefined8 *)(pVVar7 + 0xe0) = 0;
          *(undefined8 *)(pVVar7 + 0xe8) = 0;
          *(undefined8 *)(puVar6 + -8) = 0x14000f50a;
          ExReleaseFastMutex();
          uVar8 = *(uint *)(this + 0x31c);
          uVar10 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar10;
        } while (uVar10 < uVar8);
      }
      uVar9 = 0;
      if (uVar8 != 0) {
        do {
          pVVar5 = (VIDPN_TARGET_INFO *)(uVar9 * 0x130 + *(longlong *)(this + 0x2c8));
          *(undefined4 *)pVVar5 = 0xffffffff;
          *(undefined8 *)(puVar6 + -8) = 0x14000f53f;
          CleanupTargetInfoResources(this_00,pVVar5);
          uVar8 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar8;
        } while (uVar8 < *(uint *)(this + 0x31c));
      }
      if (*(longlong *)(this + 0x300) != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x14000f55c;
        ObfDereferenceObject();
        *(undefined8 *)(this + 0x300) = 0;
      }
      this[9] = (INDIRECT_DEVICE)0x0;
      *(undefined8 *)(puVar6 + -8) = 0x14000f577;
      ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
      return 0;
    }
    if ((*(INDIRECT_DEVICE **)(pIVar2 + 8) != pIVar1) ||
       (lVar3 = *(longlong *)pIVar2, *(INDIRECT_DEVICE **)(lVar3 + 8) != pIVar2)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar6 = auStack_20;
      goto LAB_14000f449;
    }
    *(longlong *)pIVar1 = lVar3;
    *(INDIRECT_DEVICE **)(lVar3 + 8) = pIVar1;
    ExFreeToPagedLookasideList(this_00);
  } while( true );
}



===== wil_details_EvaluateFeatureDependencies @ 14000f5a0 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000f5db;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000f655:
  while( true ) {
    if (&UNK_140007297 < ppuVar3) {
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
      if (&UNK_140007297 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000f5db:
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
      if (&UNK_140007297 < ppuVar2) goto LAB_14000f655;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000f655;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000f690 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000f72c;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000f72c;
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
LAB_14000f72c:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000f790 =====

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
              if (&UNK_140007297 < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 14000f810 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000f830 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000f92d;
  }
LAB_14000f936:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000f92d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000f936;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000f8fe:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000f8fe;
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
    if (&UNK_140007297 < ppuVar3) goto LAB_14000f936;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000f92d;
}



===== <lambda_invoker_cdecl> @ 14000f960 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void <lambda_df7c4c777db98983d9cefc3d6a9d5fd9>::<lambda_invoker_cdecl>
               (longlong param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x18) = *param_2;
  KeSetEvent(param_1,0,0);
  LOCK();
  piVar1 = (int *)(param_1 + 0x1c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 < 0) {
    WdLogSingleEntry1(1,0x26);
    _WdLogGlobalForLineNumber = 0x26;
  }
  else if (iVar2 == 1) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== CleanupTargetInfoResources @ 14000f9cc =====

/* public: void __cdecl INDIRECT_DEVICE::CleanupTargetInfoResources(struct VIDPN_TARGET_INFO *
   __ptr64) __ptr64 */

void __thiscall
INDIRECT_DEVICE::CleanupTargetInfoResources(INDIRECT_DEVICE *this,VIDPN_TARGET_INFO *param_1)

{
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xb0),0);
  }
  *(undefined8 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  if (*(longlong *)(param_1 + 200) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 200),0);
  }
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  if (*(longlong *)(param_1 + 0xd8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xd8),0);
  }
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  if (*(longlong *)(param_1 + 0x110) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_1 + 0x110) = 0;
  }
  if (*(longlong *)(param_1 + 0x108) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x108),0x4b646449);
  }
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  return;
}



===== GetIdDisplayCaps @ 14000fac0 =====

/* public: long __cdecl INDIRECT_DEVICE::GetIdDisplayCaps(struct _DXGK_IDD_DISPLAY_CAPS * __ptr64)
   __ptr64 */

long __thiscall
INDIRECT_DEVICE::GetIdDisplayCaps(INDIRECT_DEVICE *this,_DXGK_IDD_DISPLAY_CAPS *param_1)

{
  *param_1 = (_DXGK_IDD_DISPLAY_CAPS)this[0x318];
  *(INDIRECT_DEVICE *)(param_1 + 1) = this[0x319];
  *(INDIRECT_DEVICE *)(param_1 + 2) = this[0x31a];
  *(INDIRECT_DEVICE *)(param_1 + 3) = this[0x31b];
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(this + 0x3b8);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(this + 0x334);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(this + 0x33c);
  *(INDIRECT_DEVICE *)(param_1 + 0x14) = this[0x32a];
  *(INDIRECT_DEVICE *)(param_1 + 0x15) = this[0x32c];
  return 0;
}



===== GetIdRenderAdapter @ 14000fb1c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::GetIdRenderAdapter(unsigned int,struct _LUID * __ptr64)
   __ptr64 */

long __thiscall
INDIRECT_DEVICE::GetIdRenderAdapter(INDIRECT_DEVICE *this,uint param_1,_LUID *param_2)

{
  long lVar1;
  
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  if (param_1 < *(uint *)(this + 0x31c)) {
    lVar1 = 0;
    *(undefined8 *)param_2 =
         *(undefined8 *)((ulonglong)param_1 * 0xf0 + 0x38 + *(longlong *)(this + 0x2d0));
  }
  else {
    WdLogSingleEntry1(2,param_1);
    _WdLogGlobalForLineNumber = 0x3c4;
    lVar1 = -0x3ffffff3;
  }
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar1;
}



===== GetIdVirtualMonitorInfo @ 14000fbc4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::GetIdVirtualMonitorInfo(unsigned int,struct
   _DXGK_IDD_VIRTUAL_MONITOR_INFO * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::GetIdVirtualMonitorInfo
          (INDIRECT_DEVICE *this,uint param_1,_DXGK_IDD_VIRTUAL_MONITOR_INFO *param_2)

{
  uint uVar1;
  INDIRECT_DEVICE *pIVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  long lVar8;
  
  pIVar2 = this + 0x350;
  ExEnterCriticalRegionAndAcquireResourceShared(pIVar2);
  if (*(int *)(this + 4) == 2) {
    uVar1 = param_1 - 0x100;
    if (uVar1 < *(uint *)(this + 0x31c)) {
      lVar4 = *(longlong *)(this + 0x2c8);
      lVar8 = 0;
      puVar3 = (undefined4 *)((ulonglong)uVar1 * 0x130 + 0xf8 + lVar4);
      uVar5 = puVar3[1];
      uVar6 = puVar3[2];
      uVar7 = puVar3[3];
      *(undefined4 *)param_2 = *puVar3;
      *(undefined4 *)(param_2 + 4) = uVar5;
      *(undefined4 *)(param_2 + 8) = uVar6;
      *(undefined4 *)(param_2 + 0xc) = uVar7;
      *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)((ulonglong)uVar1 * 0x130 + 0x108 + lVar4);
    }
    else {
      WdLogSingleEntry1(2,uVar1);
      _WdLogGlobalForLineNumber = 0x3df;
      lVar8 = -0x3ffffff3;
    }
    ExReleaseResourceAndLeaveCriticalRegion(pIVar2);
  }
  else {
    WdLogSingleEntry1(2,0x3d7);
    _WdLogGlobalForLineNumber = 0x3d7;
    ExReleaseResourceAndLeaveCriticalRegion(pIVar2);
    lVar8 = -0x3ffffff3;
  }
  return lVar8;
}



===== GetMonitorPhysicalSizeOverride @ 14000fcc0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::GetMonitorPhysicalSizeOverride(unsigned int,unsigned int *
   __ptr64,unsigned int * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::GetMonitorPhysicalSizeOverride
          (INDIRECT_DEVICE *this,uint param_1,uint *param_2,uint *param_3)

{
  longlong lVar1;
  long lVar2;
  
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  if (param_1 - 0x100 < *(uint *)(this + 0x31c)) {
    lVar1 = (ulonglong)(param_1 - 0x100) * 0x130 + *(longlong *)(this + 0x2c8);
    lVar2 = 0;
    *param_2 = *(uint *)(lVar1 + 0xbc);
    *param_3 = *(uint *)(lVar1 + 0xc0);
  }
  else {
    WdLogSingleEntry1(2,param_1);
    _WdLogGlobalForLineNumber = 0x3f4;
    lVar2 = -0x3ffffff3;
  }
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar2;
}



===== HandleRequestMonitorConnect @ 14000fd84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::HandleRequestMonitorConnect(struct IDD_USER_MONITOR_CONNECT
   const * __ptr64,struct IDD_USER_VIRTUAL_MONITOR_INFO const * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::HandleRequestMonitorConnect
          (INDIRECT_DEVICE *this,IDD_USER_MONITOR_CONNECT *param_1,
          IDD_USER_VIRTUAL_MONITOR_INFO *param_2)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  void *pvVar6;
  undefined8 uVar7;
  INDIRECT_DEVICE *this_00;
  VIDPN_TARGET_INFO *this_01;
  undefined4 uVar8;
  undefined8 local_res10;
  
  if (param_1 == (IDD_USER_MONITOR_CONNECT *)0x0) {
    WdLogSingleEntry1(1,0x196);
    _WdLogGlobalForLineNumber = 0x196;
  }
  uVar4 = Feature_IdAcceptDisplayIdOnly__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    if (*(uint *)(this + 0x31c) <= *(uint *)(param_1 + 4)) {
LAB_14000fe53:
      WdLogSingleEntry1(2,0x1b0);
      _WdLogGlobalForLineNumber = 0x1b0;
      return -0x3ffffff3;
    }
    lVar5 = *(longlong *)(param_1 + 0x28);
    if (*(uint *)(param_1 + 0x20) == 0) {
      if (lVar5 != 0) goto LAB_14000fe53;
    }
    else if (lVar5 == 0) goto LAB_14000fe53;
    if (0x7f00 < *(uint *)(param_1 + 0x20)) goto LAB_14000fe53;
    if (*(int *)(param_1 + 0x30) == 0) {
      if (*(longlong *)(param_1 + 0x38) != 0) goto LAB_14000fe53;
    }
    else if ((*(longlong *)(param_1 + 0x38) == 0) || (lVar5 == 0)) goto LAB_14000fe53;
  }
  else {
    if (*(uint *)(this + 0x31c) <= *(uint *)(param_1 + 4)) {
LAB_14000fe25:
      WdLogSingleEntry1(2,0x1a2);
      _WdLogGlobalForLineNumber = 0x1a2;
      return -0x3ffffff3;
    }
    if (*(uint *)(param_1 + 0x20) == 0) {
      if (*(longlong *)(param_1 + 0x28) != 0) goto LAB_14000fe25;
    }
    else if (*(longlong *)(param_1 + 0x28) == 0) goto LAB_14000fe25;
    if (0x7f00 < *(uint *)(param_1 + 0x20)) goto LAB_14000fe25;
    if (*(int *)(param_1 + 0x30) == 0) {
      if (*(longlong *)(param_1 + 0x38) != 0) goto LAB_14000fe25;
    }
    else if (*(longlong *)(param_1 + 0x38) == 0) goto LAB_14000fe25;
  }
  if ((*(longlong *)(param_1 + 0x50) == 0) || (199 < *(int *)(param_1 + 0x48) - 1U)) {
    WdLogSingleEntry1(2,*(undefined4 *)(param_1 + 0x48));
    _WdLogGlobalForLineNumber = 0x1b9;
    return -0x3ffffff3;
  }
  if ((param_2 != (IDD_USER_VIRTUAL_MONITOR_INFO *)0x0) &&
     (((*(int *)(param_1 + 0xc) != 0 || (*(int *)(param_1 + 0x30) != 0)) ||
      (*(int *)(param_1 + 0x20) != 0)))) {
    WdLogSingleEntry1(2,0x1c3);
    _WdLogGlobalForLineNumber = 0x1c3;
    return -0x3fffffde;
  }
  this_01 = (VIDPN_TARGET_INFO *)
            ((ulonglong)*(uint *)(param_1 + 4) * 0x130 + *(longlong *)(this + 0x2c8));
  if (*(int *)(this_01 + 0x90) == 0) {
    if (*(uint *)(this_01 + 0xb8) < *(uint *)(param_1 + 0x20)) {
      if (*(longlong *)(this_01 + 0xb0) != 0) {
        ExFreePoolWithTag(*(longlong *)(this_01 + 0xb0),0);
        *(undefined8 *)(this_01 + 0xb0) = 0;
        *(undefined4 *)(this_01 + 0xb8) = 0;
      }
      lVar5 = ExAllocatePool2(0x100,*(uint *)(param_1 + 0x20),0x4b646449);
      if (*(longlong *)(this_01 + 0xb0) != 0) {
        ExFreePoolWithTag(*(longlong *)(this_01 + 0xb0),0);
      }
      *(longlong *)(this_01 + 0xb0) = lVar5;
      if (lVar5 == 0) {
        lVar2 = -0x3fffffe9;
        this_00 = (INDIRECT_DEVICE *)0x6;
        WdLogSingleEntry1(6,*(undefined4 *)(param_1 + 0x20));
        _WdLogGlobalForLineNumber = 0x1dd;
        goto LAB_14000ff58;
      }
    }
    *(ulong *)(this_01 + 0xb8) = *(ulong *)(param_1 + 0x20);
    uVar1 = *(ulong *)(param_1 + 0x20);
    if ((uVar1 == 0) ||
       (lVar2 = KmdDodCopyFromUserMode(*(void **)(this_01 + 0xb0),uVar1,*(void **)(param_1 + 0x28)),
       -1 < lVar2)) {
      if (*(longlong *)(this_01 + 200) != 0) {
        ExFreePoolWithTag(*(longlong *)(this_01 + 200),0);
        *(undefined8 *)(this_01 + 200) = 0;
        *(undefined4 *)(this_01 + 0xd0) = 0;
      }
      if (*(longlong *)(param_1 + 0x38) != 0) {
        pvVar6 = (void *)ExAllocatePool2(0x100,*(undefined4 *)(param_1 + 0x30),0x4b646449);
        if (*(longlong *)(this_01 + 200) != 0) {
          ExFreePoolWithTag(*(longlong *)(this_01 + 200),0);
        }
        *(void **)(this_01 + 200) = pvVar6;
        if (pvVar6 == (void *)0x0) {
          lVar2 = -0x3fffffe9;
          this_00 = (INDIRECT_DEVICE *)0x6;
          WdLogSingleEntry1(6,*(undefined4 *)(param_1 + 0x30));
          _WdLogGlobalForLineNumber = 0x1fb;
          goto LAB_14000ff58;
        }
        *(undefined4 *)(this_01 + 0xd0) = *(undefined4 *)(param_1 + 0x30);
        lVar2 = KmdDodCopyFromUserMode(pvVar6,*(ulong *)(param_1 + 0x30),*(void **)(param_1 + 0x38))
        ;
        if (lVar2 < 0) {
          this_00 = (INDIRECT_DEVICE *)0x2;
          uVar8 = 0x204;
          WdLogSingleEntry1(2,0x204);
          goto LAB_14000ff51;
        }
      }
      if (*(longlong *)(this_01 + 0xd8) != 0) {
        ExFreePoolWithTag(*(longlong *)(this_01 + 0xd8),0);
        *(undefined8 *)(this_01 + 0xd8) = 0;
        *(undefined4 *)(this_01 + 0xe0) = 0;
      }
      uVar7 = SUB168(ZEXT816(0x48) * ZEXT416(*(uint *)(param_1 + 0x48)),0);
      if (SUB168(ZEXT816(0x48) * ZEXT416(*(uint *)(param_1 + 0x48)),8) != 0) {
        uVar7 = 0xffffffffffffffff;
      }
      pvVar6 = (void *)ExAllocatePool2(0x100,uVar7,0x4b646449);
      if (*(longlong *)(this_01 + 0xd8) != 0) {
        ExFreePoolWithTag(*(longlong *)(this_01 + 0xd8),0);
      }
      *(void **)(this_01 + 0xd8) = pvVar6;
      iVar3 = *(int *)(param_1 + 0x48);
      if (pvVar6 == (void *)0x0) {
        lVar2 = -0x3fffffe9;
        this_00 = (INDIRECT_DEVICE *)0x6;
        WdLogSingleEntry1(6,iVar3);
        _WdLogGlobalForLineNumber = 0x213;
        goto LAB_14000ff58;
      }
      *(int *)(this_01 + 0xe0) = iVar3;
      lVar2 = KmdDodCopyFromUserMode(pvVar6,iVar3 * 0x48,*(void **)(param_1 + 0x50));
      if (lVar2 < 0) {
        this_00 = (INDIRECT_DEVICE *)0x2;
        uVar8 = 0x21c;
        WdLogSingleEntry1(2,0x21c);
        goto LAB_14000ff51;
      }
      *(undefined8 *)(this_01 + 0x110) = 0;
      *(undefined8 *)(this_01 + 0xf8) = 0;
      *(undefined8 *)(this_01 + 0x100) = 0;
      *(undefined8 *)(this_01 + 0x108) = 0;
      *(undefined4 *)(this_01 + 0xbc) = *(undefined4 *)(param_1 + 0x40);
      *(undefined4 *)(this_01 + 0xc0) = *(undefined4 *)(param_1 + 0x44);
      if (param_2 == (IDD_USER_VIRTUAL_MONITOR_INFO *)0x0) {
LAB_140010428:
        VIDPN_TARGET_INFO::UpdateMinBandwidth(this_01);
        *(undefined4 *)(this_01 + 0x90) = 1;
        *(undefined4 *)
         ((ulonglong)*(uint *)(param_1 + 4) * 0x130 + 0x94 + *(longlong *)(this + 0x2c8)) =
             *(undefined4 *)(param_1 + 8);
        if ((*(int *)(this + 4) == 0) && (*(int *)(param_1 + 4) == 0)) {
          this[0x2d9] = (INDIRECT_DEVICE)0x1;
        }
        iVar3 = *(int *)(param_1 + 0xc);
        *(int *)(this_01 + 0x98) = iVar3;
        if (iVar3 != 0) {
          uVar7 = *(undefined8 *)(param_1 + 0x18);
          *(undefined8 *)(this_01 + 0x9c) = *(undefined8 *)(param_1 + 0x10);
          *(undefined8 *)(this_01 + 0xa4) = uVar7;
        }
        this_00 = this;
        lVar2 = QueueConnectionChangedEvent(this,*(int *)(param_1 + 4) + 0x100,this_01);
        if (-1 < lVar2) {
          if (this[0x3d0] == (INDIRECT_DEVICE)0x0) {
            return lVar2;
          }
          iVar3 = (**(code **)(this + 0x188))(*(undefined8 *)(this + 0x40));
          if (iVar3 < 0) {
            WdLogSingleEntry1(1,0x28b);
            _WdLogGlobalForLineNumber = 0x28b;
            return lVar2;
          }
          return lVar2;
        }
        goto LAB_14000ff58;
      }
      if (*(longlong *)param_2 != 0) {
        local_res10 = 0;
        lVar2 = ObReferenceObjectByHandle
                          (*(longlong *)param_2,0x1f0003,*(undefined8 *)ExEventObjectType_exref,1,
                           &local_res10,0,0,0);
        *(undefined8 *)(this_01 + 0x110) = local_res10;
        if (lVar2 < 0) {
          this_00 = (INDIRECT_DEVICE *)0x2;
          uVar8 = 0x234;
          WdLogSingleEntry1(2,0x234);
          goto LAB_14000ff51;
        }
      }
      *(undefined4 *)(this_01 + 0xf8) = *(undefined4 *)(param_2 + 8);
      iVar3 = *(int *)(param_2 + 0xc);
      if (iVar3 == 0) {
        uVar8 = 0;
LAB_140010390:
        *(undefined4 *)(this_01 + 0xfc) = uVar8;
        if (this[8] != (INDIRECT_DEVICE)0x0) {
          lVar2 = -0x3fffffde;
          this_00 = (INDIRECT_DEVICE *)0x2;
          uVar8 = 0x259;
          WdLogSingleEntry1(2,0x259);
          goto LAB_14000ff51;
        }
      }
      else {
        if (iVar3 == 1) {
          uVar8 = 1;
          goto LAB_140010390;
        }
        if (iVar3 != 2) {
          lVar2 = -0x3ffffff3;
          this_00 = (INDIRECT_DEVICE *)0x2;
          WdLogSingleEntry1();
          _WdLogGlobalForLineNumber = 0x252;
          goto LAB_14000ff58;
        }
        *(undefined4 *)(this_01 + 0xfc) = 2;
      }
      pvVar6 = (void *)ExAllocatePool2(0x100,0x22,0x4b646449);
      if (pvVar6 == (void *)0x0) {
        lVar2 = -0x3fffffe9;
        this_00 = (INDIRECT_DEVICE *)0x6;
        uVar8 = 0x261;
        WdLogSingleEntry1(6,0x261);
      }
      else {
        lVar2 = KmdDodCopyFromUserMode(pvVar6,0x22,*(void **)(param_2 + 0x10));
        if (-1 < lVar2) {
          *(undefined2 *)((longlong)pvVar6 + 0x20) = 0;
          RtlInitUnicodeString(this_01 + 0x100,pvVar6);
          goto LAB_140010428;
        }
        ExFreePoolWithTag(pvVar6,0x4b646449);
        this_00 = (INDIRECT_DEVICE *)0x2;
        uVar8 = 0x269;
        WdLogSingleEntry1(2,0x269);
      }
    }
    else {
      this_00 = (INDIRECT_DEVICE *)0x2;
      uVar8 = 0x1e9;
      WdLogSingleEntry1(2,0x1e9);
    }
  }
  else {
    lVar2 = -0x3ffffff3;
    uVar8 = 0x1cd;
    this_00 = (INDIRECT_DEVICE *)0x2;
    WdLogSingleEntry1(2,0x1cd);
  }
LAB_14000ff51:
  _WdLogGlobalForLineNumber = uVar8;
LAB_14000ff58:
  CleanupTargetInfoResources(this_00,this_01);
  if ((*(int *)(this + 4) == 0) && (*(int *)(param_1 + 4) == 0)) {
    this[0x2d9] = (INDIRECT_DEVICE)0x0;
  }
  return lVar2;
}



===== HandleRequestMonitorDisconnect @ 140010510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::HandleRequestMonitorDisconnect(struct
   IDD_USER_MONITOR_DISCONNECT const * __ptr64,bool) __ptr64 */

long __thiscall
INDIRECT_DEVICE::HandleRequestMonitorDisconnect
          (INDIRECT_DEVICE *this,IDD_USER_MONITOR_DISCONNECT *param_1,bool param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  VIDPN_TARGET_INFO *pVVar4;
  undefined7 in_register_00000081;
  
  uVar1 = *(uint *)(param_1 + 4);
  if (uVar1 < *(uint *)(this + 0x31c)) {
    pVVar4 = (VIDPN_TARGET_INFO *)((ulonglong)uVar1 * 0x130 + *(longlong *)(this + 0x2c8));
    if (*(int *)(pVVar4 + 0x90) != 0) {
      CleanupTargetInfoResources(this,pVVar4);
      if ((*(int *)(this + 4) == 0) && (*(int *)(param_1 + 4) == 0)) {
        this[0x2d9] = (INDIRECT_DEVICE)0x0;
      }
      lVar2 = QueueConnectionChangedEvent(this,*(int *)(param_1 + 4) + 0x100,pVVar4);
      if ((-1 < lVar2) && (this[0x3d0] != (INDIRECT_DEVICE)0x0)) {
        iVar3 = (**(code **)(this + 0x188))(*(undefined8 *)(this + 0x40));
        if (iVar3 < 0) {
          WdLogSingleEntry1(1,0x2c1);
          _WdLogGlobalForLineNumber = 0x2c1;
        }
      }
    }
    lVar2 = 0;
  }
  else {
    WdLogSingleEntry1(2,uVar1,CONCAT71(in_register_00000081,param_2));
    lVar2 = -0x3ffffff3;
    _WdLogGlobalForLineNumber = 0x2a7;
  }
  return lVar2;
}



===== HandleRequestMonitorUpdate @ 1400105f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::HandleRequestMonitorUpdate(struct IDD_USER_MONITOR_UPDATE
   const * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::HandleRequestMonitorUpdate(INDIRECT_DEVICE *this,IDD_USER_MONITOR_UPDATE *param_1)

{
  VIDPN_TARGET_INFO *pVVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  void *pvVar6;
  VIDPN_TARGET_INFO *this_00;
  
  uVar2 = *(uint *)(param_1 + 4);
  if (uVar2 < *(uint *)(this + 0x31c)) {
    if ((*(longlong *)(param_1 + 0x10) == 0) || (199 < *(int *)(param_1 + 8) - 1U)) {
      WdLogSingleEntry1(2,*(undefined4 *)(param_1 + 8));
      _WdLogGlobalForLineNumber = 0x2d7;
    }
    else {
      this_00 = (VIDPN_TARGET_INFO *)((ulonglong)uVar2 * 0x130 + *(longlong *)(this + 0x2c8));
      if (*(int *)(this_00 + 0x90) != 0) {
        pVVar1 = this_00 + 0xe0;
        if (*(longlong *)(this_00 + 0xd8) != 0) {
          ExFreePoolWithTag(*(longlong *)(this_00 + 0xd8),0);
          *(undefined8 *)(this_00 + 0xd8) = 0;
          *(int *)pVVar1 = 0;
        }
        uVar5 = SUB168(ZEXT816(0x48) * ZEXT416(*(uint *)(param_1 + 8)),0);
        if (SUB168(ZEXT816(0x48) * ZEXT416(*(uint *)(param_1 + 8)),8) != 0) {
          uVar5 = 0xffffffffffffffff;
        }
        pvVar6 = (void *)ExAllocatePool2(0x100,uVar5,0x4b646449);
        if (*(longlong *)(this_00 + 0xd8) != 0) {
          ExFreePoolWithTag(*(longlong *)(this_00 + 0xd8),0);
        }
        *(void **)(this_00 + 0xd8) = pvVar6;
        iVar3 = *(int *)(param_1 + 8);
        if (pvVar6 == (void *)0x0) {
          WdLogSingleEntry1(6,iVar3);
          _WdLogGlobalForLineNumber = 0x2ec;
          return -0x3fffffe9;
        }
        *(int *)pVVar1 = iVar3;
        lVar4 = KmdDodCopyFromUserMode(pvVar6,iVar3 * 0x48,*(void **)(param_1 + 0x10));
        if (lVar4 < 0) {
          if (*(longlong *)(this_00 + 0xd8) != 0) {
            ExFreePoolWithTag(*(longlong *)(this_00 + 0xd8),0);
          }
          *(undefined8 *)(this_00 + 0xd8) = 0;
          *(int *)pVVar1 = 0;
          WdLogSingleEntry1(2,0x2f8);
          _WdLogGlobalForLineNumber = 0x2f8;
        }
        else {
          VIDPN_TARGET_INFO::UpdateMinBandwidth(this_00);
          if (this[0x32b] == (INDIRECT_DEVICE)0x0) {
            lVar4 = (**(code **)(this + 0x2a0))(*(undefined8 *)(this + 0x280));
          }
        }
        return lVar4;
      }
      WdLogSingleEntry1(2,0x2df);
      _WdLogGlobalForLineNumber = 0x2df;
    }
  }
  else {
    WdLogSingleEntry1(2,uVar2);
    _WdLogGlobalForLineNumber = 0x2ce;
  }
  return -0x3ffffff3;
}



===== HandleTriggerWppDiagDump @ 140010818 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::HandleTriggerWppDiagDump(void) __ptr64 */

long __thiscall INDIRECT_DEVICE::HandleTriggerWppDiagDump(INDIRECT_DEVICE *this)

{
  undefined8 uVar1;
  long lVar2;
  undefined4 *_Dst;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar4 = *(int *)(this + 0x31c) * 0x20 + 0x18;
  _Dst = (undefined4 *)ExAllocatePool2(0x40,uVar4,0x4b646449);
  if (_Dst == (undefined4 *)0x0) {
    WdLogSingleEntry1(2,0x31d);
    lVar2 = -0x3fffffe9;
    _WdLogGlobalForLineNumber = 0x31d;
  }
  else {
    memset(_Dst,0,(ulonglong)uVar4);
    *_Dst = 0x11;
    *(undefined8 *)(_Dst + 2) = *(undefined8 *)(this + 800);
    _Dst[1] = *(undefined4 *)(this + 4);
    _Dst[4] = *(undefined4 *)(this + 0x31c);
    uVar6 = 0;
    if (*(int *)(this + 0x31c) != 0) {
      do {
        lVar3 = uVar6 * 0x130;
        *(undefined8 *)(_Dst + uVar6 * 8 + 8) =
             *(undefined8 *)(lVar3 + 0xe8 + *(longlong *)(this + 0x2c8));
        _Dst[uVar6 * 8 + 6] = *(undefined4 *)(lVar3 + *(longlong *)(this + 0x2c8));
        _Dst[uVar6 * 8 + 7] = *(undefined4 *)(*(longlong *)(this + 0x2c8) + 0x90 + lVar3);
        uVar1 = *(undefined8 *)(uVar6 * 0xf0 + 0x30 + *(longlong *)(this + 0x2d0));
        uVar5 = (int)uVar6 + 1;
        _Dst[uVar6 * 8 + 10] = (int)uVar6 + 0x100;
        *(undefined8 *)(_Dst + uVar6 * 8 + 0xc) = uVar1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < *(uint *)(this + 0x31c));
    }
    lVar2 = SendSyncMessageToUserMode(this,uVar4,_Dst,0,(void *)0x0,*(uint *)(this + 0x4a4));
    ExFreePoolWithTag(_Dst,0);
  }
  return lVar2;
}



===== I2CReceiveDataFromDisplay @ 140010988 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::I2CReceiveDataFromDisplay(unsigned int,unsigned
   long,unsigned long,unsigned long,void * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::I2CReceiveDataFromDisplay
          (INDIRECT_DEVICE *this,uint param_1,ulong param_2,ulong param_3,ulong param_4,
          void *param_5)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStackY_58 [32];
  undefined4 local_28;
  int local_24;
  ulong local_20;
  ulong local_1c;
  ulong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  if (this[0x329] == (INDIRECT_DEVICE)0x0) {
    lVar2 = WdLogNewEntry5_WdTrace();
    *(undefined8 *)(lVar2 + 0x18) = 0x433;
    lVar1 = -0x3fffff45;
    _WdLogGlobalForLineNumber = 0x433;
  }
  else {
    local_24 = param_1 - 0x100;
    local_28 = 0x10;
    local_18 = param_4;
    local_20 = param_2;
    local_1c = param_3;
    lVar1 = SendSyncMessageToUserMode(this,0x14,&local_28,param_4,param_5,*(uint *)(this + 0x49c));
    if (lVar1 < 0) {
      WdLogSingleEntry1(2,(longlong)lVar1);
      _WdLogGlobalForLineNumber = 0x443;
    }
  }
  return lVar1;
}



===== I2CTransmitAndReceiveDataFromDisplay @ 140010a5c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::I2CTransmitAndReceiveDataFromDisplay(unsigned int,unsigned
   long,unsigned long,void const * __ptr64,unsigned long,unsigned long,unsigned long,void * __ptr64)
   __ptr64 */

long __thiscall
INDIRECT_DEVICE::I2CTransmitAndReceiveDataFromDisplay
          (INDIRECT_DEVICE *this,uint param_1,ulong param_2,ulong param_3,void *param_4,
          ulong param_5,ulong param_6,ulong param_7,void *param_8)

{
  long lVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  
  uVar2 = Feature_IdAtomicI2C__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    if (this[0x329] != (INDIRECT_DEVICE)0x0) {
      if (this[0x330] == (INDIRECT_DEVICE)0x0) {
        lVar1 = I2CTransmitDataToDisplay(this,param_1,param_2,param_3,param_4);
        if (lVar1 < 0) {
          WdLogSingleEntry1(2,(longlong)lVar1);
          _WdLogGlobalForLineNumber = 0x462;
          return lVar1;
        }
        lVar1 = I2CReceiveDataFromDisplay(this,param_1,param_5,param_6,param_7,param_8);
        if (lVar1 < 0) {
          WdLogSingleEntry1(2,(longlong)lVar1);
          _WdLogGlobalForLineNumber = 0x469;
        }
      }
      else {
        puVar4 = (undefined4 *)ExAllocatePool2(0x100,param_3 + 0x18,0x4b646449);
        if (puVar4 == (undefined4 *)0x0) {
          WdLogSingleEntry1(2,0x475);
          _WdLogGlobalForLineNumber = 0x475;
          return -0x3fffffe9;
        }
        *puVar4 = 0x13;
        puVar4[4] = param_2;
        puVar4[1] = param_1 - 0x100;
        puVar4[2] = param_5;
        puVar4[3] = param_6;
        puVar4[5] = param_3;
        memmove(puVar4 + 6,param_4,(ulonglong)param_3);
        lVar1 = SendSyncMessageToUserMode
                          (this,param_3 + 0x18,puVar4,param_7,param_8,*(uint *)(this + 0x49c));
        if (lVar1 < 0) {
          WdLogSingleEntry1(2,(longlong)lVar1);
          _WdLogGlobalForLineNumber = 0x487;
        }
        ExFreePoolWithTag(puVar4,0);
      }
      return lVar1;
    }
    lVar3 = WdLogNewEntry5_WdTrace();
    *(undefined8 *)(lVar3 + 0x18) = 0x458;
    _WdLogGlobalForLineNumber = 0x458;
  }
  return -0x3fffff45;
}



===== I2CTransmitDataToDisplay @ 140010c68 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::I2CTransmitDataToDisplay(unsigned int,unsigned
   long,unsigned long,void const * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::I2CTransmitDataToDisplay
          (INDIRECT_DEVICE *this,uint param_1,ulong param_2,ulong param_3,void *param_4)

{
  long lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  
  if (this[0x329] == (INDIRECT_DEVICE)0x0) {
    lVar2 = WdLogNewEntry5_WdTrace();
    *(undefined8 *)(lVar2 + 0x18) = 0x408;
    lVar1 = -0x3fffff45;
    _WdLogGlobalForLineNumber = 0x408;
  }
  else {
    puVar3 = (undefined4 *)ExAllocatePool2(0x100,param_3 + 0x10,0x4b646449);
    if (puVar3 == (undefined4 *)0x0) {
      WdLogSingleEntry1(2,0x411);
      lVar1 = -0x3fffffe9;
      _WdLogGlobalForLineNumber = 0x411;
    }
    else {
      *puVar3 = 0xf;
      puVar3[2] = param_2;
      puVar3[1] = param_1 - 0x100;
      puVar3[3] = param_3;
      memmove(puVar3 + 4,param_4,(ulonglong)param_3);
      lVar1 = SendSyncMessageToUserMode
                        (this,param_3 + 0x10,puVar3,0,(void *)0x0,*(uint *)(this + 0x49c));
      if (lVar1 < 0) {
        WdLogSingleEntry1(2,(longlong)lVar1);
        _WdLogGlobalForLineNumber = 0x421;
      }
      ExFreePoolWithTag(puVar3,0);
    }
  }
  return lVar1;
}



===== ReceiveMessageFromUserMode @ 140010da4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::ReceiveMessageFromUserMode(unsigned long,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::ReceiveMessageFromUserMode
          (INDIRECT_DEVICE *this,ulong param_1,void *param_2,ulong param_3,void *param_4,
          ulong *param_5)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  long lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  void *pvVar8;
  IDD_USER_VIRTUAL_MONITOR_INFO *pIVar9;
  ulong local_res18;
  
  lVar4 = 0;
  local_res18 = 0;
  if ((param_2 == (void *)0x0) || (param_5 == (ulong *)0x0)) {
    return -0x3ffffff3;
  }
  if (param_1 < 4) {
    return -0x3fffffdd;
  }
  iVar1 = *(int *)param_2;
  bVar3 = true;
  if (iVar1 < 7) {
    if ((((iVar1 != 6) && (iVar1 != 0)) && (iVar1 != 1)) &&
       (((iVar1 == 2 || (iVar1 == 3)) || ((iVar1 != 4 && (iVar1 != 5)))))) goto LAB_140010e5a;
LAB_140010e3f:
    pvVar8 = param_2;
    ExEnterCriticalRegionAndAcquireResourceExclusive(this + 0x350);
    uVar7 = SUB81(pvVar8,0);
  }
  else {
    if ((iVar1 != 7) && (iVar1 != 8)) {
      if (iVar1 == 100) {
        bVar3 = false;
      }
      else if ((iVar1 == 200) || (iVar1 == 0xc9)) {
        bVar3 = false;
        goto LAB_140010e3f;
      }
    }
LAB_140010e5a:
    pvVar8 = param_2;
    ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
    uVar7 = SUB81(pvVar8,0);
  }
  if ((this[0x2f8] == (INDIRECT_DEVICE)0x0) && (*(int *)(this + 4) != 2)) {
    WdLogSingleEntry1(1,0x9b);
    _WdLogGlobalForLineNumber = 0x9b;
    lVar4 = -0x3fffff45;
    goto LAB_140010ef4;
  }
  if ((bVar3) && (lVar5 = PsGetCurrentProcess(), *(longlong *)(this + 0x300) != lVar5)) {
    uVar6 = PsGetCurrentProcess();
    WdLogSingleEntry2(2,*(undefined8 *)(this + 0x300),uVar6);
    _WdLogGlobalForLineNumber = 0xa2;
    lVar4 = -0x3fffffde;
    goto LAB_140010ef4;
  }
  iVar1 = *(int *)param_2;
  if (iVar1 < 7) {
    if (iVar1 == 6) {
      if (param_1 < 0x10) goto LAB_140010f5e;
      *(undefined8 *)(this + 800) = *(undefined8 *)((longlong)param_2 + 8);
      lVar4 = (**(code **)(this + 0x2a0))(*(undefined8 *)(this + 0x280));
    }
    else if (iVar1 == 0) {
      if (param_1 < 0x58) goto LAB_140010f5e;
      pIVar9 = (IDD_USER_VIRTUAL_MONITOR_INFO *)0x0;
LAB_140011024:
      lVar4 = HandleRequestMonitorConnect(this,param_2,pIVar9);
    }
    else if (iVar1 == 1) {
LAB_140010fff:
      if (param_1 < 0xc) goto LAB_140010f5e;
      lVar4 = HandleRequestMonitorDisconnect(this,param_2,(bool)uVar7);
    }
    else if (iVar1 == 2) {
      if (param_1 < 0x28) goto LAB_140010f5e;
      lVar4 = HandleRequestSetupMouseCursor(this,param_2);
    }
    else if (iVar1 == 3) {
      if ((param_1 < 0x18) || (param_3 < 0x34)) goto LAB_140010f5e;
      lVar4 = HandleRequestQueryMouseCursor(this,param_2,param_4);
      local_res18 = 0x34;
    }
    else {
      if (iVar1 == 4) {
        if (0xf < param_1) {
          uVar2 = *(uint *)((longlong)param_2 + 4);
          if (uVar2 < *(uint *)(this + 0x31c)) {
            *(undefined8 *)((ulonglong)uVar2 * 0x130 + 0xf0 + *(longlong *)(this + 0x2c8)) =
                 *(undefined8 *)((longlong)param_2 + 8);
            goto LAB_140011128;
          }
          WdLogSingleEntry1(2,uVar2);
          _WdLogGlobalForLineNumber = 0x33a;
          goto LAB_140010f96;
        }
      }
      else {
        if (iVar1 != 5) {
LAB_140010f96:
          lVar4 = -0x3ffffff3;
          goto LAB_14001113b;
        }
        if (0x17 < param_1) {
          lVar4 = HandleRequestMonitorUpdate(this,param_2);
          goto LAB_140011128;
        }
      }
LAB_140010f5e:
      lVar4 = -0x3fffffdd;
    }
LAB_140011128:
    *param_5 = local_res18;
    if (-1 < lVar4) goto LAB_140010ef4;
  }
  else {
    if (iVar1 != 7) {
      if (iVar1 == 8) {
        if ((0x17 < param_1) && (3 < param_3)) {
          lVar4 = HandleRequestGetSrmListVersion(this,param_2,param_4);
          local_res18 = 4;
          goto LAB_140011128;
        }
      }
      else if (iVar1 == 9) {
        if (0x13 < param_1) {
          lVar5 = (ulonglong)*(uint *)((longlong)param_2 + 4) * 0x130 + *(longlong *)(this + 0x2c8);
          *(undefined4 *)(lVar5 + 0x124) = *(undefined4 *)((longlong)param_2 + 8);
          *(undefined4 *)(lVar5 + 0x128) = *(undefined4 *)((longlong)param_2 + 0xc);
          *(undefined4 *)(lVar5 + 300) = *(undefined4 *)((longlong)param_2 + 0x10);
          *param_5 = 0;
          goto LAB_140010ef4;
        }
      }
      else {
        if (iVar1 == 100) {
          lVar4 = HandleTriggerWppDiagDump(this);
          goto LAB_140011128;
        }
        if (iVar1 != 200) {
          if (iVar1 != 0xc9) goto LAB_140010f96;
          goto LAB_140010fff;
        }
        if (0x6f < param_1) {
          pIVar9 = (IDD_USER_VIRTUAL_MONITOR_INFO *)((longlong)param_2 + 0x58);
          goto LAB_140011024;
        }
      }
      goto LAB_140010f5e;
    }
    if (0x17 < param_1) {
      lVar4 = HandleRequestSetSrmList(this,param_2);
      goto LAB_140011128;
    }
    lVar4 = -0x3fffffdd;
LAB_14001113b:
    *param_5 = 0;
  }
  WdLogSingleEntry2(2,(longlong)*(int *)param_2,(longlong)lVar4);
  _WdLogGlobalForLineNumber = 0x188;
LAB_140010ef4:
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar4;
}



===== SendMessageToUserMode @ 140011190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::SendMessageToUserMode(unsigned long,void const *
   __ptr64,unsigned long,void * __ptr64,void (__cdecl*)(void * __ptr64,struct _IO_STATUS_BLOCK *
   __ptr64),void * __ptr64)const __ptr64 */

long __thiscall
INDIRECT_DEVICE::SendMessageToUserMode
          (INDIRECT_DEVICE *this,ulong param_1,void *param_2,ulong param_3,void *param_4,
          _func_void_void_ptr__IO_STATUS_BLOCK_ptr *param_5,void *param_6)

{
  long lVar1;
  
  if (*(int *)(this + 4) == 2) {
    WdLogSingleEntry1(1);
    _WdLogGlobalForLineNumber = 0x52;
  }
  if (*(code **)(this + 0x298) == (code *)0x0) {
    lVar1 = -0x3fffff45;
  }
  else {
    lVar1 = (**(code **)(this + 0x298))
                      (*(undefined8 *)(this + 0x280),param_1,param_2,param_3,param_4,param_5,param_6
                      );
  }
  return lVar1;
}



===== SendSyncMessageToUserMode @ 140011238 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::SendSyncMessageToUserMode(unsigned long,void *
   __ptr64,unsigned long,void * __ptr64,unsigned int) __ptr64 */

long __thiscall
INDIRECT_DEVICE::SendSyncMessageToUserMode
          (INDIRECT_DEVICE *this,ulong param_1,void *param_2,ulong param_3,void *param_4,
          uint param_5)

{
  char cVar1;
  int iVar2;
  long lVar3;
  
  cVar1 = ExIsResourceAcquiredExclusiveLite(this + 0x350);
  if ((cVar1 == '\0') && (iVar2 = ExIsResourceAcquiredSharedLite(this + 0x350), iVar2 == 0)) {
    lVar3 = SendSyncMessageToUserModeInternal
                      (param_1,param_2,param_3,param_4,param_5,*(void **)(this + 0x280),
                       *(_func_long_void_ptr_ulong_void_ptr_ulong_void_ptr__func_void_void_ptr__IO_STATUS_BLOCK_ptr_ptr_void_ptr
                         **)(this + 0x298));
    return lVar3;
  }
  WdLogSingleEntry1(1,0x42);
  _WdLogGlobalForLineNumber = 0x42;
  return -0x3ffffe7c;
}



===== SendSyncMessageToUserModeInternal @ 140011304 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* private: static long __cdecl INDIRECT_DEVICE::SendSyncMessageToUserModeInternal(unsigned
   long,void * __ptr64,unsigned long,void * __ptr64,unsigned int,void * __ptr64,long (__cdecl*)(void
   * __ptr64,unsigned long,void * __ptr64,unsigned long,void * __ptr64,void (__cdecl*)(void *
   __ptr64,struct _IO_STATUS_BLOCK * __ptr64),void * __ptr64)) */

long __cdecl
INDIRECT_DEVICE::SendSyncMessageToUserModeInternal
          (ulong param_1,void *param_2,ulong param_3,void *param_4,uint param_5,void *param_6,
          _func_long_void_ptr_ulong_void_ptr_ulong_void_ptr__func_void_void_ptr__IO_STATUS_BLOCK_ptr_ptr_void_ptr
          *param_7)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  void *pvVar4;
  longlong local_18 [2];
  
  pvVar4 = (void *)ExAllocatePool2(0x40,0x20,0x4b646449);
  if (pvVar4 == (void *)0x0) {
    WdLogSingleEntry1(6,0x4fb);
    lVar2 = -0x3fffffe9;
    _WdLogGlobalForLineNumber = 0x4fb;
  }
  else {
    *(undefined4 *)((longlong)pvVar4 + 0x18) = 0;
    *(undefined4 *)((longlong)pvVar4 + 0x1c) = 2;
    KeInitializeEvent(pvVar4,0,0);
    lVar2 = (*param_7)(param_6,param_1,param_2,param_3,param_4,
                       <lambda_df7c4c777db98983d9cefc3d6a9d5fd9>::<lambda_invoker_cdecl>,pvVar4);
    if (lVar2 < 0) {
      LOCK();
      piVar1 = (int *)((longlong)pvVar4 + 0x1c);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 + -1 < 0) {
        WdLogSingleEntry1(1,0x26);
        _WdLogGlobalForLineNumber = 0x26;
      }
      else if (iVar3 == 1) {
        ExFreePoolWithTag(pvVar4,0);
      }
    }
    else if (lVar2 == 0x103) {
      local_18[0] = (ulonglong)param_5 * -10000000;
      iVar3 = KeWaitForSingleObject(pvVar4,0,0,0,local_18);
      if (iVar3 == 0) {
        lVar2 = *(long *)((longlong)pvVar4 + 0x18);
      }
      else {
        WdLogSingleEntry1(2,(longlong)iVar3);
        _WdLogGlobalForLineNumber = 0x51e;
        lVar2 = -0x3ffffdc0;
      }
    }
    LOCK();
    piVar1 = (int *)((longlong)pvVar4 + 0x1c);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 + -1 < 0) {
      WdLogSingleEntry1(1,0x26);
      _WdLogGlobalForLineNumber = 0x26;
    }
    else if (iVar3 == 1) {
      ExFreePoolWithTag(pvVar4,0);
    }
  }
  return lVar2;
}



===== SetSwapChainHandle @ 1400114d8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::SetSwapChainHandle(unsigned int,void * __ptr64 const,struct
   _LUID) __ptr64 */

long __thiscall
INDIRECT_DEVICE::SetSwapChainHandle
          (INDIRECT_DEVICE *this,uint param_1,longlong param_2,undefined8 param_4)

{
  INDIRECT_DEVICE *pIVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  VIDPN_SOURCE_INFO *pVVar5;
  int iStackX_24;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar6;
  ulonglong in_stack_ffffffffffffffa0;
  ulonglong in_stack_ffffffffffffffa8;
  undefined4 local_48;
  uint local_44;
  undefined8 local_40;
  undefined8 local_38;
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  pIVar1 = this + 0x350;
  ExEnterCriticalRegionAndAcquireResourceExclusive(pIVar1);
  if ((this[0x2f8] == (INDIRECT_DEVICE)0x0) || (lVar3 = *(longlong *)(this + 0x300), lVar3 == 0)) {
    WdLogSingleEntry1(2,0x350);
    _WdLogGlobalForLineNumber = 0x350;
    ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
    return -0x3fffff45;
  }
  if (param_1 < *(uint *)(this + 0x31c)) {
    pVVar5 = (VIDPN_SOURCE_INFO *)((ulonglong)param_1 * 0xf0 + *(longlong *)(this + 0x2d0));
    if (*(int *)(pVVar5 + 4) == 0) {
      lVar3 = WdLogNewEntry5_WdTrace();
      *(ulonglong *)(lVar3 + 0x18) = (ulonglong)param_1;
      iVar2 = -0x3fe1fcbe;
      _WdLogGlobalForLineNumber = 0x360;
    }
    else {
      local_40 = 0;
      local_48 = 3;
      local_44 = param_1;
      local_38 = param_4;
      if (param_2 != 0) {
        uVar4 = PsGetCurrentProcess();
        iVar2 = ObDuplicateObject(uVar4,param_2,lVar3,&local_40,CONCAT44(uVar6,0x80000000),
                                  in_stack_ffffffffffffffa0 & 0xffffffff00000000,
                                  in_stack_ffffffffffffffa8 & 0xffffffff00000000,1);
        if (iVar2 < 0) {
          WdLogSingleEntry2(2,*(undefined8 *)(this + 0x300),(longlong)iVar2);
          _WdLogGlobalForLineNumber = 0x371;
          goto LAB_140011673;
        }
      }
      iVar2 = SendMessageToUserMode
                        (this,0x18,&local_48,0,(void *)0x0,
                         (_func_void_void_ptr__IO_STATUS_BLOCK_ptr *)0x0,(void *)0x0);
      if (-1 < iVar2) {
        if ((*(int *)(pVVar5 + 0x38) != (int)param_4) ||
           (iStackX_24 = (int)((ulonglong)param_4 >> 0x20), *(int *)(pVVar5 + 0x3c) != iStackX_24))
        {
          OnSourcePowerOff(this,pVVar5);
        }
        *(longlong *)(pVVar5 + 0x30) = param_2;
        *(undefined8 *)(pVVar5 + 0x38) = param_4;
        if (param_2 != 0) {
          OnSourcePowerOn(this,pVVar5);
        }
        ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
        return 0;
      }
      WdLogSingleEntry1(2,(longlong)iVar2);
      _WdLogGlobalForLineNumber = 0x37a;
    }
  }
  else {
    WdLogSingleEntry1(2,param_1);
    _WdLogGlobalForLineNumber = 0x356;
    iVar2 = -0x3ffffff3;
  }
LAB_140011673:
  ExReleaseResourceAndLeaveCriticalRegion(pIVar1);
  return iVar2;
}



===== TerminateOutput @ 140011728 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl INDIRECT_DEVICE::TerminateOutput(unsigned int) __ptr64 */

long __thiscall INDIRECT_DEVICE::TerminateOutput(INDIRECT_DEVICE *this,uint param_1)

{
  long lVar1;
  undefined4 local_res8;
  uint local_resc;
  
  ExEnterCriticalRegionAndAcquireResourceExclusive();
  if (*(int *)(this + 4) == 0) {
    lVar1 = -0x3fffff45;
  }
  else {
    local_res8 = 5;
    local_resc = param_1;
    lVar1 = (**(code **)(this + 0x298))(*(undefined8 *)(this + 0x280),8,&local_res8,0,0,0,0);
  }
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar1;
}



===== KmdDodMiraDisplayDestroyContext @ 1400117d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl KmdDodMiraDisplayDestroyContext(void * __ptr64,void * __ptr64) */

void __cdecl KmdDodMiraDisplayDestroyContext(void *param_1,void *param_2)

{
  long lVar1;
  bool in_R8B;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (((param_1 != (void *)0x0) && (param_2 != (void *)0x0)) && (*(int *)param_1 == 0x4b646449)) {
    if (param_2 == (void *)0x900dbeef) {
      if (*(char *)((longlong)param_1 + 0x2d9) != '\0') {
        local_10 = 0;
        local_14 = 0;
        local_18 = 1;
        lVar1 = INDIRECT_DEVICE::HandleRequestMonitorDisconnect
                          (param_1,(IDD_USER_MONITOR_DISCONNECT *)&local_18,in_R8B);
        if ((lVar1 < 0) || (*(char *)((longlong)param_1 + 0x2d9) != '\0')) {
          WdLogSingleEntry1(1);
          _WdLogGlobalForLineNumber = 0x7b;
        }
      }
      *(undefined1 *)((longlong)param_1 + 0x2d8) = 0;
      *(undefined1 *)((longlong)param_1 + 0x2f8) = 0;
    }
    else {
      WdLogSingleEntry1(1,0x99);
      _WdLogGlobalForLineNumber = 0x99;
    }
  }
  return;
}



===== MiracastCreateContext @ 14001188c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::MiracastCreateContext(struct
   _DXGK_MIRACAST_DISPLAY_CALLBACKS * __ptr64,void * __ptr64 * __ptr64,unsigned long * __ptr64)
   __ptr64 */

long __thiscall
INDIRECT_DEVICE::MiracastCreateContext
          (INDIRECT_DEVICE *this,_DXGK_MIRACAST_DISPLAY_CALLBACKS *param_1,void **param_2,
          ulong *param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  if (((param_1 == (_DXGK_MIRACAST_DISPLAY_CALLBACKS *)0x0) || (param_2 == (void **)0x0)) ||
     (param_3 == (ulong *)0x0)) {
    lVar2 = -0x3ffffff3;
  }
  else if (this[0x2d8] == (INDIRECT_DEVICE)0x0) {
    uVar1 = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)(this + 0x2e0) = *(undefined8 *)param_1;
    *(undefined8 *)(this + 0x2e8) = uVar1;
    *(undefined8 *)(this + 0x2f0) = *(undefined8 *)(param_1 + 0x10);
    this[0x2d8] = (INDIRECT_DEVICE)0x1;
    this[0x2f8] = (INDIRECT_DEVICE)0x1;
    *param_2 = (void *)0x900dbeef;
    lVar2 = 0;
    *param_3 = 0x100;
  }
  else {
    WdLogSingleEntry1(1);
    lVar2 = -0x3fffff45;
    _WdLogGlobalForLineNumber = 0x5f;
  }
  return lVar2;
}



===== MiracastHandleIoControl @ 140011918 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::MiracastHandleIoControl(void * __ptr64,unsigned long,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::MiracastHandleIoControl
          (INDIRECT_DEVICE *this,void *param_1,ulong param_2,void *param_3,ulong param_4,
          void *param_5,ulong *param_6)

{
  long lVar1;
  
  if (param_1 == (void *)0x900dbeef) {
    if (this[0x2d8] == (INDIRECT_DEVICE)0x0) {
      WdLogSingleEntry1(1);
      _WdLogGlobalForLineNumber = 0x2f;
    }
    else {
      WdLogSingleEntry1(1);
      _WdLogGlobalForLineNumber = 0x33;
    }
    lVar1 = -0x3fffff45;
  }
  else {
    WdLogSingleEntry1(1);
    lVar1 = -0x3fffff10;
    _WdLogGlobalForLineNumber = 0x29;
  }
  return lVar1;
}



===== MiracastQueryCaps @ 1400119a4 =====

/* public: long __cdecl INDIRECT_DEVICE::MiracastQueryCaps(unsigned long,struct _DXGK_MIRACAST_CAPS
   * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::MiracastQueryCaps(INDIRECT_DEVICE *this,ulong param_1,_DXGK_MIRACAST_CAPS *param_2)

{
  if ((param_2 == (_DXGK_MIRACAST_CAPS *)0x0) || (param_1 < 8)) {
    return -0x3ffffff3;
  }
  *(undefined8 *)param_2 = 0;
  return 0;
}



===== GetOpmMftContext @ 1400119c4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::GetOpmMftContext(unsigned int,unsigned __int64 * __ptr64)
   __ptr64 */

long __thiscall
INDIRECT_DEVICE::GetOpmMftContext(INDIRECT_DEVICE *this,uint param_1,__uint64 *param_2)

{
  long lVar1;
  
  ExEnterCriticalRegionAndAcquireResourceShared(this + 0x350);
  lVar1 = 0;
  if (this[0x2f8] == (INDIRECT_DEVICE)0x0) {
    WdLogSingleEntry1(2,0x1f);
    _WdLogGlobalForLineNumber = 0x1f;
    lVar1 = -0x3fffff45;
  }
  else if (param_1 - 0x100 < *(uint *)(this + 0x31c)) {
    *param_2 = *(__uint64 *)
                ((ulonglong)(param_1 - 0x100) * 0x130 + 0xf0 + *(longlong *)(this + 0x2c8));
  }
  else {
    WdLogSingleEntry1(2,0x25);
    _WdLogGlobalForLineNumber = 0x25;
    lVar1 = -0x3ffffff3;
  }
  ExReleaseResourceAndLeaveCriticalRegion(this + 0x350);
  return lVar1;
}



===== HandleRequestGetSrmListVersion @ 140011aa8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::HandleRequestGetSrmListVersion(struct
   IDD_USER_GET_SRM_LIST_VERSION_IN const * __ptr64,struct IDD_USER_GET_SRM_LIST_VERSION_OUT *
   __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::HandleRequestGetSrmListVersion
          (INDIRECT_DEVICE *this,IDD_USER_GET_SRM_LIST_VERSION_IN *param_1,
          IDD_USER_GET_SRM_LIST_VERSION_OUT *param_2)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStack_78 [32];
  uint local_58 [2];
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  ulonglong local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = *(ulonglong *)(param_1 + 0x10);
  pvVar3 = (void *)0x0;
  local_50 = *(undefined4 *)param_1;
  uStack_4c = *(undefined4 *)(param_1 + 4);
  uStack_48 = *(undefined4 *)(param_1 + 8);
  uStack_44 = *(undefined4 *)(param_1 + 0xc);
  uVar1 = (uint)local_40;
  uVar5 = local_40 & 0xffffffff;
  if (((uint)local_40 == 0) ||
     (pvVar3 = (void *)ExAllocatePool2(0x100,local_40 & 0xffffffff,0x4b646449),
     pvVar3 != (void *)0x0)) {
    local_58[0] = uVar1;
    iVar2 = (**(code **)(this + 0x2c0))(*(undefined8 *)(this + 0x280),local_58,pvVar3);
    uVar4 = Feature_3030546745__private_IsEnabledDeviceUsageNoInline();
    if ((((int)uVar4 == 0) || (uVar1 == 0)) || (local_58[0] <= uVar1)) {
      *(uint *)param_2 = local_58[0];
      if ((-1 < iVar2) && (uVar1 != 0)) {
        iVar2 = KmdDodCopyToUserMode(pvVar3,local_58[0],*(void **)(param_1 + 8));
      }
    }
    else {
      WdLogSingleEntry2(2,local_58[0],uVar5);
      uStack_4c = 0;
      uStack_48 = 0;
      _WdLogGlobalForLineNumber = 0x156;
      local_50 = 0x3c27604;
      RtlLogUnexpectedCodepath(&local_50);
      iVar2 = -0x3ffffdfa;
    }
    if (pvVar3 != (void *)0x0) {
      ExFreePoolWithTag(pvVar3,0);
    }
  }
  else {
    WdLogSingleEntry1(2,0x147);
    iVar2 = -0x3fffffe9;
    _WdLogGlobalForLineNumber = 0x147;
  }
  return iVar2;
}



===== HandleRequestSetSrmList @ 140011c04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::HandleRequestSetSrmList(struct IDD_USER_SET_SRM_LIST const
   * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::HandleRequestSetSrmList(INDIRECT_DEVICE *this,IDD_USER_SET_SRM_LIST *param_1)

{
  long lVar1;
  void *pvVar2;
  
  pvVar2 = (void *)ExAllocatePool2(0x100,*(undefined4 *)(param_1 + 0x10),0x4b646449);
  if (pvVar2 == (void *)0x0) {
    WdLogSingleEntry1(2,0x129);
    lVar1 = -0x3fffffe9;
    _WdLogGlobalForLineNumber = 0x129;
  }
  else {
    lVar1 = KmdDodCopyFromUserMode(pvVar2,*(ulong *)(param_1 + 0x10),*(void **)(param_1 + 8));
    if (-1 < lVar1) {
      lVar1 = (**(code **)(this + 0x2b8))
                        (*(undefined8 *)(this + 0x280),*(undefined4 *)(param_1 + 0x10),pvVar2);
    }
    ExFreePoolWithTag(pvVar2,0);
  }
  return lVar1;
}



===== OPMConfigureProtectedOutput @ 140011cc4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::OPMConfigureProtectedOutput(void * __ptr64,struct
   _DXGKMDT_OPM_CONFIGURE_PARAMETERS const * __ptr64,unsigned long,void const * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::OPMConfigureProtectedOutput
          (INDIRECT_DEVICE *this,void *param_1,_DXGKMDT_OPM_CONFIGURE_PARAMETERS *param_2,
          ulong param_3,void *param_4)

{
  uint uVar1;
  long lVar2;
  undefined4 *puVar3;
  
  uVar1 = param_3 + 0x1018;
  if (uVar1 < 0x1018) {
    WdLogSingleEntry1(2,(ulonglong)param_3);
    lVar2 = -0x3fffff6b;
    _WdLogGlobalForLineNumber = 0xf0;
  }
  else {
    puVar3 = (undefined4 *)ExAllocatePool2(0x100,uVar1,0x4b646449);
    if (puVar3 == (undefined4 *)0x0) {
      WdLogSingleEntry1(2,0xf7);
      lVar2 = -0x3fffffe9;
      _WdLogGlobalForLineNumber = 0xf7;
    }
    else {
      *puVar3 = 0xd;
      *(void **)(puVar3 + 2) = param_1;
      memmove(puVar3 + 4,param_2,0x1000);
      puVar3[0x404] = param_3;
      memmove(puVar3 + 0x405,param_4,(ulonglong)param_3);
      lVar2 = SendSyncMessageToUserMode(this,uVar1,puVar3,0,(void *)0x0,*(uint *)(this + 0x4a0));
      if (lVar2 < 0) {
        WdLogSingleEntry1(2,(longlong)lVar2);
        _WdLogGlobalForLineNumber = 0x104;
      }
      ExFreePoolWithTag(puVar3,0);
    }
  }
  return lVar2;
}



===== OPMCreateProtectedOutput @ 140011e18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::OPMCreateProtectedOutput(unsigned int,enum
   _DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::OPMCreateProtectedOutput
          (INDIRECT_DEVICE *this,uint param_1,_DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS param_2,
          void **param_3)

{
  long lVar1;
  undefined1 auStackY_68 [32];
  void *local_38;
  undefined4 local_30;
  int local_2c;
  _DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_68;
  local_38 = (void *)0x0;
  local_2c = param_1 - 0x100;
  local_30 = 9;
  local_28 = param_2;
  lVar1 = SendSyncMessageToUserMode(this,0xc,&local_30,8,&local_38,*(uint *)(this + 0x4a0));
  if (lVar1 < 0) {
    WdLogSingleEntry1(2,(longlong)lVar1);
    _WdLogGlobalForLineNumber = 0x72;
  }
  else {
    *param_3 = local_38;
  }
  return lVar1;
}



===== OPMDestroyProtectedOutput @ 140011ec0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::OPMDestroyProtectedOutput(void * __ptr64) __ptr64 */

long __thiscall INDIRECT_DEVICE::OPMDestroyProtectedOutput(INDIRECT_DEVICE *this,void *param_1)

{
  long lVar1;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  
  local_14 = 0;
  local_18 = 0xe;
  local_10 = param_1;
  lVar1 = SendSyncMessageToUserMode(this,0x10,&local_18,0,(void *)0x0,*(uint *)(this + 0x4a0));
  if (lVar1 < 0) {
    WdLogSingleEntry1(2,(longlong)lVar1);
    _WdLogGlobalForLineNumber = 0x119;
  }
  return lVar1;
}



===== OPMGetCOPPCompatibleInformation @ 140011f30 =====

/* public: long __cdecl INDIRECT_DEVICE::OPMGetCOPPCompatibleInformation(void * __ptr64,struct
   _DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS const * __ptr64,struct
   _DXGKMDT_OPM_REQUESTED_INFORMATION * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::OPMGetCOPPCompatibleInformation
          (INDIRECT_DEVICE *this,void *param_1,
          _DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS *param_2,
          _DXGKMDT_OPM_REQUESTED_INFORMATION *param_3)

{
  return -0x3ffffffe;
}



===== OPMGetCertificate @ 140011f40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::OPMGetCertificate(enum _DXGKMDT_CERTIFICATE_TYPE,unsigned
   long,void * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::OPMGetCertificate
          (INDIRECT_DEVICE *this,_DXGKMDT_CERTIFICATE_TYPE param_1,ulong param_2,void *param_3)

{
  long lVar1;
  undefined1 auStackY_58 [32];
  undefined4 local_28;
  _DXGKMDT_CERTIFICATE_TYPE local_24;
  ulong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 8;
  local_24 = param_1;
  local_20 = param_2;
  lVar1 = SendSyncMessageToUserMode(this,0xc,&local_28,param_2,param_3,*(uint *)(this + 0x4a0));
  if (lVar1 < 0) {
    WdLogSingleEntry1(2,(longlong)lVar1);
    _WdLogGlobalForLineNumber = 0x57;
  }
  return lVar1;
}



===== OPMGetCertificateSize @ 140011fc8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::OPMGetCertificateSize(enum
   _DXGKMDT_CERTIFICATE_TYPE,unsigned long * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::OPMGetCertificateSize
          (INDIRECT_DEVICE *this,_DXGKMDT_CERTIFICATE_TYPE param_1,ulong *param_2)

{
  long lVar1;
  undefined4 local_res8;
  _DXGKMDT_CERTIFICATE_TYPE local_resc;
  ulong local_res10 [2];
  
  local_res10[0] = 0;
  local_res8 = 7;
  local_resc = param_1;
  lVar1 = SendSyncMessageToUserMode(this,8,&local_res8,4,local_res10,*(uint *)(this + 0x4a0));
  if (lVar1 < 0) {
    WdLogSingleEntry1(2,(longlong)lVar1);
    _WdLogGlobalForLineNumber = 0x42;
  }
  else {
    *param_2 = local_res10[0];
  }
  return lVar1;
}



===== OPMGetInformation @ 140012050 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::OPMGetInformation(void * __ptr64,struct
   _DXGKMDT_OPM_GET_INFO_PARAMETERS const * __ptr64,struct _DXGKMDT_OPM_REQUESTED_INFORMATION *
   __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::OPMGetInformation
          (INDIRECT_DEVICE *this,void *param_1,_DXGKMDT_OPM_GET_INFO_PARAMETERS *param_2,
          _DXGKMDT_OPM_REQUESTED_INFORMATION *param_3)

{
  long lVar1;
  undefined4 *puVar2;
  void *_Src;
  long lVar3;
  
  puVar2 = (undefined4 *)ExAllocatePool2(0x100,0x1020,0x4b646449);
  _Src = (void *)ExAllocatePool2(0x100,0x1000,0x4b646449);
  if ((puVar2 == (undefined4 *)0x0) || (_Src == (void *)0x0)) {
    WdLogSingleEntry1(2,0xc6);
    _WdLogGlobalForLineNumber = 0xc6;
    lVar3 = -0x3fffffe9;
    lVar1 = -0x3fffffe9;
    if (puVar2 == (undefined4 *)0x0) goto LAB_14001216e;
  }
  else {
    *puVar2 = 0xc;
    *(void **)(puVar2 + 2) = param_1;
    memmove(puVar2 + 4,param_2,0x1010);
    lVar1 = SendSyncMessageToUserMode(this,0x1020,puVar2,0x1000,_Src,*(uint *)(this + 0x4a0));
    if (lVar1 < 0) {
      WdLogSingleEntry1(2,(longlong)lVar1);
      _WdLogGlobalForLineNumber = 0xc1;
    }
    else {
      memmove(param_3,_Src,0x1000);
    }
  }
  lVar3 = lVar1;
  ExFreePoolWithTag(puVar2,0);
LAB_14001216e:
  if (_Src != (void *)0x0) {
    ExFreePoolWithTag(_Src,0);
  }
  return lVar3;
}



===== OPMGetRandomNumber @ 1400121a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::OPMGetRandomNumber(void * __ptr64,struct
   _DXGKMDT_OPM_RANDOM_NUMBER * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::OPMGetRandomNumber
          (INDIRECT_DEVICE *this,void *param_1,_DXGKMDT_OPM_RANDOM_NUMBER *param_2)

{
  long lVar1;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined4 local_34;
  void *local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_34 = 0;
  local_38 = 10;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = param_1;
  lVar1 = SendSyncMessageToUserMode(this,0x10,&local_38,0x10,&local_28,*(uint *)(this + 0x4a0));
  if (lVar1 < 0) {
    WdLogSingleEntry1(2,(longlong)lVar1);
    _WdLogGlobalForLineNumber = 0x8b;
  }
  else {
    *(undefined8 *)param_2 = local_28;
    *(undefined8 *)(param_2 + 8) = uStack_20;
  }
  return lVar1;
}



===== OPMSetSigningKeyAndSequenceNumbers @ 140012258 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl INDIRECT_DEVICE::OPMSetSigningKeyAndSequenceNumbers(void * __ptr64,struct
   _DXGKMDT_OPM_ENCRYPTED_PARAMETERS const * __ptr64) __ptr64 */

long __thiscall
INDIRECT_DEVICE::OPMSetSigningKeyAndSequenceNumbers
          (INDIRECT_DEVICE *this,void *param_1,_DXGKMDT_OPM_ENCRYPTED_PARAMETERS *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined1 auStackY_168 [32];
  undefined4 local_138 [2];
  void *local_130;
  undefined8 local_128 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_168;
  memset(local_138,0,0x110);
  lVar7 = 2;
  local_138[0] = 0xb;
  puVar6 = local_128;
  do {
    uVar1 = *(undefined8 *)(param_2 + 8);
    uVar2 = *(undefined8 *)(param_2 + 0x10);
    uVar3 = *(undefined8 *)(param_2 + 0x18);
    *puVar6 = *(undefined8 *)param_2;
    puVar6[1] = uVar1;
    uVar1 = *(undefined8 *)(param_2 + 0x20);
    uVar4 = *(undefined8 *)(param_2 + 0x28);
    puVar6[2] = uVar2;
    puVar6[3] = uVar3;
    uVar2 = *(undefined8 *)(param_2 + 0x30);
    uVar3 = *(undefined8 *)(param_2 + 0x38);
    puVar6[4] = uVar1;
    puVar6[5] = uVar4;
    uVar1 = *(undefined8 *)(param_2 + 0x40);
    uVar4 = *(undefined8 *)(param_2 + 0x48);
    puVar6[6] = uVar2;
    puVar6[7] = uVar3;
    uVar2 = *(undefined8 *)(param_2 + 0x50);
    uVar3 = *(undefined8 *)(param_2 + 0x58);
    puVar6[8] = uVar1;
    puVar6[9] = uVar4;
    uVar1 = *(undefined8 *)(param_2 + 0x60);
    uVar4 = *(undefined8 *)(param_2 + 0x68);
    puVar6[10] = uVar2;
    puVar6[0xb] = uVar3;
    uVar2 = *(undefined8 *)(param_2 + 0x70);
    uVar3 = *(undefined8 *)(param_2 + 0x78);
    param_2 = param_2 + 0x80;
    puVar6[0xc] = uVar1;
    puVar6[0xd] = uVar4;
    puVar6[0xe] = uVar2;
    puVar6[0xf] = uVar3;
    lVar7 = lVar7 + -1;
    puVar6 = puVar6 + 0x10;
  } while (lVar7 != 0);
  local_130 = param_1;
  lVar5 = SendSyncMessageToUserMode(this,0x110,local_138,0,(void *)0x0,*(uint *)(this + 0x4a0));
  if (lVar5 < 0) {
    WdLogSingleEntry1(2,(longlong)lVar5);
    _WdLogGlobalForLineNumber = 0xa0;
  }
  return lVar5;
}



===== DlpCallSyncDeviceIoControl @ 140012364 =====

ulonglong DlpCallSyncDeviceIoControl(undefined8 param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 in_stack_00000030;
  undefined8 *in_stack_00000040;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (0x230043,param_1,0,0,in_stack_00000030,8,1,&local_28,&local_38);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    uVar1 = IofCallDriver(param_1,lVar2);
    if (uVar1 == 0x103) {
      uVar3 = KeWaitForSingleObject(&local_28,0,0,0,0);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar1 = (uint)local_38;
    }
    if (-1 < (int)uVar1) {
      *in_stack_00000040 = uStack_30;
    }
    uVar3 = (ulonglong)uVar1;
  }
  return uVar3;
}



===== DlpStartDevice @ 140012460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DlpStartDevice(void)

{
  (*MiniportStartDevice)();
  return;
}



===== entry @ 140013010 =====

void entry(longlong param_1,ushort *param_2)

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,ushort *param_2)

{
  int iVar1;
  uint local_158 [2];
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
  code *local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_78;
  code *local_70;
  code *local_60;
  code *local_58;
  code *local_48;
  code *local_40;
  code *local_38;
  
  iVar1 = wil_InitializeFeatureStaging();
  if (-1 < iVar1) {
    McGenEventRegister_EtwRegister();
    if ((param_1 == 0) || (param_2 == (ushort *)0x0)) {
      if (g_wil_details_featureChangeNotification != 0) {
        RtlUnregisterFeatureConfigurationChangeNotification();
        g_wil_details_featureChangeNotification = 0;
      }
      if (g_wil_details_featureUsageProvider != 0) {
        RtlUnregisterFeatureUsageProvider();
        g_wil_details_featureUsageProvider = 0;
      }
      iVar1 = -0x3ffffff3;
    }
    else {
      _Globals = param_1;
      iVar1 = KmdDodAllocUnicodeString((_UNICODE_STRING *)&DAT_1400083c8,(uint)*param_2);
      if (iVar1 < 0) {
        if (g_wil_details_featureChangeNotification != 0) {
          RtlUnregisterFeatureConfigurationChangeNotification();
          g_wil_details_featureChangeNotification = 0;
        }
        if (g_wil_details_featureUsageProvider != 0) {
          RtlUnregisterFeatureUsageProvider();
          g_wil_details_featureUsageProvider = 0;
        }
      }
      else {
        RtlCopyUnicodeString(&DAT_1400083c8);
        memset(local_158,0,0x150);
        local_158[0] = 0x11007;
        local_150 = KmdDodDdiAddDevice;
        local_148 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGK_START_INFO_*,_DXGKRNL_INTERFACE_*,unsigned_long_*,unsigned_long_*),&INDIRECT_DEVICE::StartDevice>
                    ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_140 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(void),&INDIRECT_DEVICE::StopDevice>
                    ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_138 = KmdDodDdiRemoveDevice;
        local_130 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,_VIDEO_REQUEST_PACKET_*),&INDIRECT_DEVICE::DispatchIoRequest>
                    ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_118 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGK_CHILD_DESCRIPTOR_*,unsigned_long),&INDIRECT_DEVICE::QueryChildRelations>
                    ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_110 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGK_CHILD_STATUS_*,unsigned_char),&INDIRECT_DEVICE::QueryChildStatus>
                    ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_108 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,_DXGK_DEVICE_DESCRIPTOR_*),&INDIRECT_DEVICE::QueryDeviceDescriptor>
                    ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_38 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,_DXGK_CHILD_CONTAINER_ID_*),&INDIRECT_DEVICE::GetChildContainerId>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_100 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(unsigned_long,enum__DEVICE_POWER_STATE,enum_POWER_ACTION),&INDIRECT_DEVICE::SetPowerState>
                    ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_f0 = KmdDodDdiResetDevice;
        local_e8 = KmdDodDdiUnload;
        local_e0 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_QUERY_INTERFACE_*),&INDIRECT_DEVICE::QueryInterface>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_b0 = CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_ESCAPE_const_*),&INDIRECT_DEVICE::Escape>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_d0 = CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_QUERYADAPTERINFO_const_*),&INDIRECT_DEVICE::QueryAdapterInfo>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_c8 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETPALETTE_const_*),&INDIRECT_DEVICE::SetPalette>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_b8 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETPOINTERSHAPE_const_*),&INDIRECT_DEVICE::SetPointerShape>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_c0 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETPOINTERPOSITION_const_*),&INDIRECT_DEVICE::SetPointerPosition>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_128 = KmdDodInterruptRoutine;
        local_120 = KmdDodDdiResetDevice;
        local_58 = CallNtThunk<void_*,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_PRESENT_DISPLAYONLY_const_*),&INDIRECT_DEVICE::PresentDisplayOnly>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_48 = KmdDodDdiSystemDisplayEnable;
        local_40 = KmdDodDdiSystemDisplayWrite;
        local_a0 = CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_ISSUPPORTEDVIDPN_*),&INDIRECT_DEVICE::IsSupportedVidPn>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_98 = CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_RECOMMENDFUNCTIONALVIDPN_const_*),&INDIRECT_DEVICE::RecommendFunctionalVidPn>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_90 = CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_ENUMVIDPNCOFUNCMODALITY_const_*),&INDIRECT_DEVICE::EnumVidPnCofuncModality>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_88 = CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_SETVIDPNSOURCEVISIBILITY_const_*),&INDIRECT_DEVICE::SetVidPnSourceVisibility>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_78 = CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_UPDATEACTIVEVIDPNPRESENTPATH_const_*),&INDIRECT_DEVICE::UpdateActiveVidPnPresentPath>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_70 = CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_RECOMMENDMONITORMODES_const_*),&INDIRECT_DEVICE::RecommendMonitorModes>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        local_60 = CallNtThunk<void_*_const,long_(__cdecl_INDIRECT_DEVICE::*)(_DXGKARG_QUERYVIDPNHWCAPABILITY_*),&INDIRECT_DEVICE::QueryVidPnHWCapability>
                   ::CallWithVerify<&VerifyAdapter,_1073741811>;
        iVar1 = DxgkInitializeDisplayOnlyDriver(param_1,(longlong)param_2,local_158);
        if (-1 < iVar1) {
          return iVar1;
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
    }
    g_wil_details_isFeatureStagingInitialized = 0;
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 140013370 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400133f7;
    }
LAB_140013431:
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
LAB_1400133f7:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140013431;
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
    goto LAB_140013431;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140007297 < ppuVar3) goto LAB_140013431;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400133f7;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140013484 =====

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
            if (&UNK_140007297 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001356e;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001356e;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001356e:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140007297 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


